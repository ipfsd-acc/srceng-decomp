// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/xbox/makegamedata/makegamedata.cpp
// Functions: 45
// ============================================================

#include "utils\xbox\makegamedata\makegamedata.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  return AppMain(argc, (char **)argv, pAppSystemGroup: &_s_SteamApplicationObject);
}

//------------------------------------------------------------------------------
// Address: 0x00401020
// Name: bool IsWildcardMatch(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsWildcardMatch(const char *wildcardString, const char *stringToCheck, bool bCaseSensitive)
{
  const char *v3; // edi
  const char *v4; // esi
  char v5; // bl
  char i; // al
  char strChar; // [esp+7h] [ebp-1h]

  v3 = wildcardString;
  if ( _V_stricmp(s1: wildcardString, s2: "*.*") == 0 || _V_stricmp(s1: wildcardString, s2: "*") == 0 )
    return true;
  v4 = stringToCheck;
  for ( strChar = *stringToCheck; *v4 != 0; strChar = *v4 )
  {
    v5 = *v3;
    if ( *v3 == 0 )
      break;
    ++v4;
    ++v3;
    if ( !bCaseSensitive )
    {
      v5 = tolower(c: v5);
      strChar = tolower(c: strChar);
    }
    if ( v5 == 42 )
    {
      if ( *--v4 != 0 )
      {
        while ( !IsWildcardMatch(wildcardString: v3, stringToCheck: v4++, bCaseSensitive) )
        {
          if ( *v4 == 0 )
            goto LABEL_14;
        }
        return true;
      }
    }
    else if ( v5 != 63 && v5 != strChar )
    {
      return false;
    }
LABEL_14:
    ;
  }
  for ( i = *v3; i != 0; i = *++v3 )
  {
    if ( i != 42 )
      break;
  }
  return *v4 == 0 && *v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401100
// Name: void GetGamePath(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetGamePath()
{
  int v0; // eax
  char v1; // cl
  char *v2; // eax
  char szFullPath[260]; // [esp+0h] [ebp-104h] BYREF

  GetCurrentDirectoryA(nBufferLength: 0x104u, lpBuffer: g_szGamePath);
  if ( _fullpath(UserBuf: szFullPath, path: g_szGamePath, maxlen: 0x104u) != nullptr )
  {
    v0 = 0;
    do
    {
      v1 = szFullPath[v0];
      g_szGamePath[v0++] = v1;
    }
    while ( v1 != 0 );
  }
  V_AppendSlash(pStr: g_szGamePath, strSize: 260);
  v2 = V_stristr(pStr: g_szGamePath, pSearch: "game\\");
  if ( v2 == nullptr )
  {
    _Warning(a1: "ERROR: Failed to determine game directory from current path. Expecting 'game' in current path.");
    exit(code: 1);
  }
  v2[4] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004011A0
// Name: bool GetModPath(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GetModPath()
{
  int v0; // eax
  char v1; // cl
  int v2; // eax
  char v3; // cl
  char fullPath[260]; // [esp+8h] [ebp-33Ch] BYREF
  char szLastDirectory[260]; // [esp+10Ch] [ebp-238h] BYREF
  char szDirectory[260]; // [esp+210h] [ebp-134h] BYREF
  _stat64i32 statBuf; // [esp+314h] [ebp-30h] BYREF

  szLastDirectory[0] = 0;
  GetCurrentDirectoryA(nBufferLength: 0x104u, lpBuffer: szDirectory);
  V_ComposeFileName(path: szDirectory, filename: "gameinfo.txt", dest: g_szModPath, destSize: 260);
  if ( _stat64i32(name: g_szModPath, buf: &statBuf) == -1 )
  {
    while ( 1 )
    {
      V_ComposeFileName(path: szDirectory, filename: "..", dest: g_szModPath, destSize: 260);
      if ( _fullpath(UserBuf: fullPath, path: g_szModPath, maxlen: 0x104u) != nullptr )
      {
        v0 = 0;
        do
        {
          v1 = fullPath[v0];
          szDirectory[v0++] = v1;
        }
        while ( v1 != 0 );
      }
      if ( _V_stricmp(s1: szDirectory, s2: szLastDirectory) == 0 )
        break;
      v2 = 0;
      do
      {
        v3 = szDirectory[v2];
        szLastDirectory[v2++] = v3;
      }
      while ( v3 != 0 );
      V_ComposeFileName(path: szDirectory, filename: "gameinfo.txt", dest: g_szModPath, destSize: 260);
      if ( _stat64i32(name: g_szModPath, buf: &statBuf) != -1 )
        goto LABEL_9;
    }
    GetCurrentDirectoryA(nBufferLength: 0x104u, lpBuffer: g_szModPath);
    return 0;
  }
  else
  {
LABEL_9:
    V_strncpy(pDest: g_szModPath, pSrc: szDirectory, maxLen: 260);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004012F0
// Name: bool DoesFileExist(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl DoesFileExist(const char *pFilename)
{
  int v1; // eax

  v1 = _open(path: pFilename, oflag: 0x8000, pmode: 0);
  if ( v1 == -1 )
    return 0;
  _close(fh: v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401320
// Name: int CompareFileTime(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CompareFileTime(char *pFilenameA, char *pFilenameB)
{
  unsigned int v2; // esi
  unsigned int v3; // eax
  bool v4; // cf

  v2 = FileTime(path: pFilenameA);
  v3 = FileTime(path: pFilenameB);
  if ( v2 == -1 )
    v2 = 0;
  if ( v3 == -1 )
    return v2 != 0;
  v4 = v3 < v2;
  if ( v3 <= v2 )
    return v4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00401360
// Name: char __near * MakeTemporaryFilename(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl MakeTemporaryFilename(char *pPath, int pathSize)
{
  char *v2; // eax
  char *v3; // esi

  v2 = _tempnam(dir: g_szModPath, pfx: "mgd_");
  v3 = v2;
  if ( *v2 == 92 )
    v3 = v2 + 1;
  if ( v3[strlen(v3) - 1] == 46 )
    v3[strlen(v3) - 1] = 0;
  V_snprintf(pDest: pPath, maxLen: pathSize, pFormat: "%s.tmp", v3);
  free(pMem: v3);
  return pPath;
}

//------------------------------------------------------------------------------
// Address: 0x004013D0
// Name: void DoPostProcessingFunctions(bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DoPostProcessingFunctions(bool bWriteToZip)
{
  if ( !g_bDvdDevMode )
  {
    if ( !g_bTexturesOnly )
    {
      if ( !g_bAudioOnly )
      {
        if ( g_bMakeScenes || g_bMakeScenesPC )
          CreateSceneImageFile(
            pchModPath: g_szModPath,
            bWriteToZip,
            bLittleEndian: g_bMakeScenesPC,
            bQuiet: g_bQuiet,
            eWriteModeForConversions: g_WriteModeForConversions);
        ProcessDXSupportConfig(bWriteToZip);
      }
      if ( !g_bNoAudio )
      {
        if ( g_bMakeAudioCachePC )
          CreateAudioCacheFile(pchModPath: g_szModPath, bQuiet: g_bQuiet);
        if ( g_bUpdateAudioCachePC )
          UpdateAudioCacheFile(pchModPath: g_szModPath, bQuiet: g_bQuiet);
      }
    }
    if ( g_bMakeZip )
      WriteCompiledKVPool(bWriteToZip);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401490
// Name: bool CreateTargetFile(char const __near *,char const __near *,enum fileType_e,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CreateTargetFile(char *pSourceName, const char *pTargetName, fileType_e fileType, bool bWriteToZip)
{
  char *v4; // esi
  bool result; // al
  char fullSourcePath[260]; // [esp+4h] [ebp-104h] BYREF

  v4 = pSourceName;
  if ( _fullpath(UserBuf: fullSourcePath, path: pSourceName, maxlen: 0x104u) != nullptr )
    v4 = fullSourcePath;
  result = false;
  switch ( fileType )
  {
    case FILETYPE_WAV:
      result = CreateTargetFile_WAV(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_VTF:
      result = CreateTargetFile_VTF(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_MDL:
    case FILETYPE_ANI:
    case FILETYPE_VTX:
    case FILETYPE_VVD:
    case FILETYPE_PHY:
    case FILETYPE_PHZ:
      result = CreateTargetFile_Model(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_BSP:
      result = CreateTargetFile_BSP(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_AIN:
      result = CreateTargetFile_AIN(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_CCDAT:
      result = CreateTargetFile_CCDAT(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_MP3:
      result = CreateTargetFile_MP3(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_RESLST:
      result = CreateTargetFile_RESLST(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_PCF:
      result = CreateTargetFile_PCF(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_NAV:
      result = CreateTargetFile_NAV(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_RAW:
      result = CreateTargetFile_RAW(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_LMP:
      result = CreateTargetFile_LMP(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_LOCALIZED_TXT:
      result = CreateTargetFile_LocalizedTXT(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_VMT:
      result = CreateTargetFile_VMT(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    case FILETYPE_KV_TXT:
      result = CreateTargetFile_CompiledKV_TXT(pSourceName: v4, pTargetName, bWriteToZip);
      break;
    default:
      return result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401680
// Name: bool IsLocalizedFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLocalizedFile(const char *pFileName)
{
  int v1; // esi
  const char *v2; // eax

  v1 = 0;
  while ( 1 )
  {
    v2 = V_stristr(pStr: pFileName, pSearch: g_Languages[v1].pSuffix);
    if ( v2 != nullptr && v2[strlen(g_Languages[v1].pSuffix)] == 46 )
      break;
    if ( (unsigned int)++v1 >= 20 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004016E0
// Name: bool IsLocalizedPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLocalizedPath(const char *pFileName)
{
  int v1; // edi
  const char *v2; // eax
  char v3; // al

  v1 = 0;
  while ( 1 )
  {
    v2 = V_stristr(pStr: pFileName, pSearch: g_Languages[v1].pSuffix);
    if ( v2 != nullptr )
    {
      v3 = v2[strlen(g_Languages[v1].pSuffix)];
      if ( v3 != 0 && (v3 == 92 || v3 == 47) )
        break;
    }
    if ( (unsigned int)++v1 >= 20 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401750
// Name: bool IsLocalizedFileEnabled(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsLocalizedFileEnabled(const char *pFileName, const char *pLanguageSuffix)
{
  unsigned int v3; // edi
  int v4; // eax
  const char *v5; // eax

  if ( pLanguageSuffix != nullptr )
    return V_stristr(pStr: pFileName, pSearch: pLanguageSuffix) != nullptr;
  v3 = 0;
  while ( g_bSonyPS3 )
  {
    if ( (dword_634024[v3 / 4] & 1) != 0 )
      goto LABEL_10;
LABEL_12:
    v3 += 8;
    if ( v3 >= 0xA0 )
      return false;
  }
  v4 = dword_634024[v3 / 4];
  if ( (v4 & 6) == 0 || g_bIsCert && (v4 & 4) != 0 )
    goto LABEL_12;
LABEL_10:
  v5 = V_stristr(pStr: pFileName, pSearch: g_Languages[v3 / 8].pSuffix);
  if ( v5 == nullptr || v5[strlen(g_Languages[v3 / 8].pSuffix)] != 46 )
    goto LABEL_12;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x004017F0
// Name: bool IsLocalizationFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl IsLocalizationFile(const char *pFilename)
{
  int v1; // eax
  int v2; // esi
  unsigned int v4; // edi
  int v5; // ebx
  int *v6; // eax
  wchar_t *v7; // esi
  unsigned __int8 filedata[256]; // [esp+4h] [ebp-284h] BYREF
  wchar_t unicodeToken[128]; // [esp+104h] [ebp-184h] BYREF
  char ansiToken[131]; // [esp+204h] [ebp-84h] BYREF
  bool bQuoted; // [esp+287h] [ebp-1h] BYREF

  v1 = _open(path: pFilename, oflag: 0x8000, pmode: 0);
  v2 = v1;
  if ( v1 == -1 )
    return 0;
  _lseek(fh: v1, pos: 0, mthd: 2);
  v4 = _tell(filedes: v2);
  _lseek(fh: v2, pos: 0, mthd: 0);
  if ( v4 >= 0xFE )
    v4 = 254;
  v5 = _read(fh: v2, buf: filedata, cnt: v4);
  _close(fh: v2);
  if ( v5 != v4 )
  {
    v6 = _errno();
    _Warning(a1: "IsLocalizationFile(): read failure %d, errno=%d\n", v5, *v6);
    return 0;
  }
  *(_WORD *)&filedata[2 * ((int)v4 / 2)] = 0;
  if ( *(_WORD *)filedata != 0xFEFF )
    return 0;
  v7 = ReadUnicodeToken(start: (wchar_t *)&filedata[2], token: unicodeToken, tokenBufferSize: 128, quoted: &bQuoted);
  if ( unicodeToken[0] == 0 )
    return 0;
  while ( 1 )
  {
    _V_UnicodeToUTF8(a1: unicodeToken, a2: ansiToken, a3: 128);
    if ( V_strncasecmp(s1: ansiToken, s2: "//", n: 2) != 0 )
      break;
    v7 = ReadToEndOfLine(start: v7);
LABEL_12:
    v7 = ReadUnicodeToken(start: v7, token: unicodeToken, tokenBufferSize: 128, quoted: &bQuoted);
    if ( unicodeToken[0] == 0 )
      return 0;
  }
  if ( _V_stricmp(s1: ansiToken, s2: "lang") != 0 )
    goto LABEL_12;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00401970
// Name: bool IncludeInZip(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IncludeInZip(const char *pSourceName)
{
  int v2; // esi
  const char *v3; // edi
  bool bDatHasPlatformExtension; // [esp+7h] [ebp-1h]

  if ( g_bIsPlatformZip
    && V_stristr(pStr: pSourceName, pSearch: "materials\\") == nullptr
    && V_stristr(pStr: pSourceName, pSearch: "resource\\") == nullptr
    && V_stristr(pStr: pSourceName, pSearch: "scripts\\") == nullptr
    && V_stristr(pStr: pSourceName, pSearch: "shaders\\") == nullptr
    && V_stristr(pStr: pSourceName, pSearch: "vgui\\") == nullptr )
  {
    return false;
  }
  if ( g_bSonyPS3 )
  {
    if ( V_stristr(pStr: pSourceName, pSearch: ".360.") != nullptr )
      return false;
    if ( g_bSonyPS3 )
    {
LABEL_12:
      v2 = 0;
      while ( 1 )
      {
        v3 = s_AllowedExtensionsInZip[v2];
        if ( V_stristr(pStr: pSourceName, pSearch: v3) != nullptr )
          break;
        if ( (unsigned int)++v2 >= 52 )
          return false;
      }
      if ( _V_stricmp(s1: v3, s2: ".lst") == 0 )
        return V_stristr(pStr: pSourceName, pSearch: "_exclude") != nullptr;
      if ( _V_stricmp(s1: v3, s2: ".360.dat") == 0
        || (bDatHasPlatformExtension = false, _V_stricmp(s1: v3, s2: ".ps3.dat") == 0) )
      {
        bDatHasPlatformExtension = true;
      }
      return _V_stricmp(s1: v3, s2: ".txt") != 0 && !bDatHasPlatformExtension
          || (IsLocalizedFile(pFileName: pSourceName) == 0
           || IsLocalizedFileEnabled(pFileName: pSourceName, pLanguageSuffix: nullptr))
          && (_V_stricmp(s1: v3, s2: ".txt") != 0
           || V_stristr(pStr: pSourceName, pSearch: "closecaption_") == nullptr
           && V_stristr(pStr: pSourceName, pSearch: "subtitles_") == nullptr);
    }
  }
  if ( V_stristr(pStr: pSourceName, pSearch: ".ps3.") == nullptr )
    goto LABEL_12;
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: void Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn Usage()
{
  _Msg(a1: "usage: MakeGameData [filemask] [options]\n");
  _Msg(a1: "options:\n");
  _Msg(a1: "[-v]                    Version\n");
  _Msg(a1: "[-q]                    Quiet (critical spew only)\n");
  _Msg(a1: "[-h] [-help] [-?]       Help\n");
  _Msg(a1: "[-t targetPath]         Alternate output path, will generate output at target\n");
  _Msg(a1: "[-r] [-recurse]         Recurse into source directory\n");
  _Msg(a1: "[-f] [-force]           Force update, otherwise checks timestamps\n");
  _Msg(a1: "[-test]                 Skip writing to disk\n");
  _Msg(a1: "[-z <zipname>]          Generate zip file AND create or update stale conversions\n");
  _Msg(a1: "[-preloadinfo]          Spew contents of preload section in zip\n");
  _Msg(a1: "[-kvinfo]               Spew contents of kvpool in zip\n");
  _Msg(a1: "[-xmaquality <quality>] XMA Encoding quality override, [0-100]\n");
  _Msg(a1: "[-scenes]               Make Xbox 360 scene image cache.\n");
  _Msg(a1: "[-pcscenes]             Make PC scene image cache.\n");
  _Msg(a1: "[-usemaplist]           For BSP related conversions, restricts to maplist.txt.\n");
  _Msg(a1: "[-files <script>]       Restricts processing to files specified in script.\n");
  _Msg(a1: "[-zipformat]            Compatible zip format (Allows WinZip viewing)\n");
  _Msg(a1: "[-audiocache]           Make PC audio _master.cache file.\n");
  _Msg(a1: "[-updateaudiocache]     Update PC audio _master.cache file w/ new or changed .wav files.\n");
  _Msg(a1: "[-language <name>]      Build _master_name.cache language specific cache file.\n");
  _Msg(a1: "[-ps3]                  Build for Sony PS3\n");
  _Msg(a1: "[-sonyps3]              Build for Sony PS3\n");
  _Msg(a1: "[-cert]                 CERT build, uses environment VPC_AUTO_ARGS or VPC_CONSOLE_ARGS\n");
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401BE0
// Name: public: virtual void CMGDLoggingListener::Log(struct LoggingContext_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMGDLoggingListener::Log(
        CMGDLoggingListener *this,
        const LoggingContext_t *pContext,
        const char *pMessage)
{
  if ( !this->m_bQuietPrintf || pContext->m_Severity != LS_MESSAGE )
    printf(format: "%s", pMessage);
  if ( (unsigned __int8)_Plat_IsInDebugSession() != 0 )
    _Plat_DebugString(a1: pMessage);
}

//------------------------------------------------------------------------------
// Address: 0x00401C20
// Name: public: virtual bool MakeGameDataApp::Create(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall MakeGameDataApp::Create(MakeGameDataApp *this)
{
  AppSystemInfo_t appSystems[2]; // [esp+4h] [ebp-10h] BYREF

  _LoggingSystem_PushLoggingState(a1: 0, a2: 1);
  _LoggingSystem_RegisterLoggingListener(a1: &s_MGDLoggingListener);
  appSystems[1].m_pModuleName = pDefaultValue;
  appSystems[1].m_pInterfaceName = pDefaultValue;
  appSystems[0].m_pModuleName = "mdllib.dll";
  appSystems[0].m_pInterfaceName = "VMDLLIB001";
  CAppSystemGroup::AddSystem(this, pAppSystem: g_pDataModel, pInterfaceName: "VDataModelVersion001");
  CAppSystemGroup::AddSystem(this, pAppSystem: g_pDmSerializers, pInterfaceName: "VDmSerializers001");
  if ( Sys_LoadInterface(
         pModuleName: "vphysics.dll",
         pInterfaceVersionName: "VPhysicsCollision007",
         pOutModule: &g_pPhysicsModule,
         pOutInterface: (void **)&g_pPhysicsCollision) )
  {
    return CAppSystemGroup::AddSystems(this, pSystemList: appSystems);
  }
  _Warning(a1: "Failed to load vphysics interface\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00401CD0
// Name: public: virtual void MakeGameDataApp::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MakeGameDataApp::Destroy(MakeGameDataApp *this)
{
  _LoggingSystem_PopLoggingState(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00401CE0
// Name: public: virtual bool MakeGameDataApp::PreInit(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall MakeGameDataApp::PreInit(MakeGameDataApp *this)
{
  void *(__cdecl *factory)(const char *, int *); // [esp+0h] [ebp-4h] BYREF

  factory = CAppSystemGroup::GetFactory();
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  if ( g_pFullFileSystem != nullptr && g_pDataModel != nullptr && g_pPhysicsCollision != nullptr && mdllib != nullptr )
    return 1;
  _Warning(a1: "MakeGameData is missing a required interface!\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401D50
// Name: public: virtual void MakeGameDataApp::PostShutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall MakeGameDataApp::PostShutdown(MakeGameDataApp *this)
{
  if ( g_pPhysicsModule != nullptr )
  {
    Sys_UnloadModule(pModule: g_pPhysicsModule);
    g_pPhysicsModule = nullptr;
    g_pPhysicsCollision = nullptr;
  }
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x00401D80
// Name: protected: virtual void CFmtStrN<256>::InitQuietTruncation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFmtStrN<256>::InitQuietTruncation(CFmtStrN<256> *this)
{
  this->m_bQuietTruncation = true;
}

//------------------------------------------------------------------------------
// Address: 0x00401DC0
// Name: bool ReadFileToBuffer(char const __near *,class CUtlBuffer __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ReadFileToBuffer(const char *pSourceName, CUtlBuffer *buffer, bool bText, bool bNoOpenFailureWarning)
{
  int v4; // eax
  int v5; // esi
  int *v6; // eax
  const char *v7; // eax
  int v9; // edi
  int *v10; // eax
  int status; // [esp+8h] [ebp-8h]
  bool bSuccess; // [esp+Fh] [ebp-1h]

  bSuccess = true;
  v4 = _open(path: pSourceName, oflag: 0x8000, pmode: 0);
  v5 = v4;
  if ( v4 == -1 )
  {
    if ( !bNoOpenFailureWarning )
    {
      v6 = _errno();
      v7 = strerror(errnum: *v6);
      _Warning(a1: "ReadFileToBuffer(): Error opening %s: %s\n", pSourceName, v7);
    }
    return false;
  }
  else
  {
    _lseek(fh: v4, pos: 0, mthd: 2);
    v9 = _tell(filedes: v5);
    _lseek(fh: v5, pos: 0, mthd: 0);
    CUtlBuffer::EnsureCapacity(this: buffer, num: v9);
    CUtlBuffer::SeekPut(this: buffer, type: SEEK_CURRENT, offset: v9);
    status = _read(fh: v5, buf: buffer->m_Memory.m_pMemory, cnt: v9);
    if ( status != v9 )
    {
      v10 = _errno();
      _Warning(a1: "ReadFileToBuffer(): read failure %d, errno=%d\n", status, *v10);
      bSuccess = false;
    }
    if ( bText )
      CUtlBuffer::SetBufferType(this: buffer, bIsText: true, bContainsCRLF: true);
    else
      CUtlBuffer::SetBufferType(this: buffer, bIsText: false, bContainsCRLF: false);
    _close(fh: v5);
    return bSuccess;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EB0
// Name: bool WriteBufferToFile(char const __near *,class CUtlBuffer __near &,bool,enum DiskWriteMode_t)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl WriteBufferToFile(
        const char *pTargetName,
        CUtlBuffer *buffer,
        bool bWriteToZip,
        DiskWriteMode_t writeMode)
{
  const char *v5; // edi
  _BYTE *v6; // eax
  _BYTE *v7; // esi
  _BYTE *v8; // eax
  int v9; // eax
  int v10; // edi
  int *v11; // eax
  const char *v12; // eax
  int v13; // esi
  int *v14; // eax
  bool v15; // al
  char dirPath[262]; // [esp+0h] [ebp-108h] BYREF
  bool bZipSuccess; // [esp+106h] [ebp-2h]
  bool bSuccess; // [esp+107h] [ebp-1h]

  if ( g_bTest )
    return true;
  v5 = pTargetName;
  bSuccess = true;
  bZipSuccess = true;
  strcpy(dirPath, pTargetName);
  strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v7 = v6;
  if ( v6 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v7 + 1, chr: 0x5Cu);
      v7 = v8;
      if ( v8 == nullptr )
        break;
      *v8 = 0;
      mkdir(path: dirPath);
      *v7 = 92;
    }
  }
  if ( writeMode != WRITE_TO_DISK_ALWAYS )
  {
    if ( writeMode != WRITE_TO_DISK_UPDATE )
      goto LABEL_15;
    v9 = _open(path: pTargetName, oflag: 0x8000, pmode: 0);
    if ( v9 == -1 )
      goto LABEL_15;
    _close(fh: v9);
  }
  v10 = _open(path: pTargetName, oflag: 33538, pmode: 438);
  if ( v10 == -1 )
  {
    v11 = _errno();
    v12 = strerror(errnum: *v11);
    _Warning(a1: "WriteBufferToFile(): Error opening %s: %s\n", pTargetName, v12);
    return false;
  }
  v13 = _write(fh: v10, buf: buffer->m_Memory.m_pMemory, cnt: buffer->m_nMaxPut);
  if ( v13 != buffer->m_nMaxPut )
  {
    v14 = _errno();
    _Warning(a1: "WriteBufferToFile(): write failure %d, errno=%d\n", v13, *v14);
    bSuccess = false;
  }
  _close(fh: v10);
  v5 = pTargetName;
LABEL_15:
  if ( !g_bMakeZip
    || g_bTest
    || !bWriteToZip
    || CXZipTool::AddBuffer(this: &g_MasterXZip, pFilename: v5, fileBuffer: buffer, bDoPreload: true) )
  {
    v15 = bZipSuccess;
  }
  else
  {
    _Warning(a1: "WriteBufferToFile(): Error adding file %s\n", v5);
    v15 = false;
  }
  return bSuccess && v15;
}

//------------------------------------------------------------------------------
// Address: 0x00402050
// Name: bool CompressCallback(class CUtlBuffer __near &,class CUtlBuffer __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CompressCallback(signed int inputBuffer, CUtlBuffer *outputBuffer)
{
  int v2; // eax
  unsigned __int8 *v4; // esi
  CUtlBuffer *v5; // edi

  v2 = *(_DWORD *)(inputBuffer + 16);
  if ( v2 == 0 )
    return 0;
  v4 = LZMA_Compress(
         pInput: (unsigned __int8 *)(*(_DWORD *)(inputBuffer + 12) + *(_DWORD *)inputBuffer),
         inputSize: v2 - *(_DWORD *)(inputBuffer + 12),
         pOutputSize: (unsigned int *)&inputBuffer,
         dictionarySize: 0x12u);
  if ( v4 == nullptr )
    return 0;
  v5 = outputBuffer;
  CUtlBuffer::EnsureCapacity(this: outputBuffer, num: inputBuffer);
  CUtlBuffer::Put(this: v5, pMem: v4, size: inputBuffer);
  free(pMem: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004020B0
// Name: enum fileType_e ResolveFileType(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ResolveFileType(const char *pSourceName, char *pTargetName, int targetNameSize)
{
  unsigned int v3; // esi
  bool v5; // al
  const char *v6; // eax
  char szFullSourcePath[260]; // [esp+8h] [ebp-310h] BYREF
  char targetExtension[260]; // [esp+10Ch] [ebp-20Ch] BYREF
  char sourceExtension[262]; // [esp+210h] [ebp-108h] BYREF
  CUtlSymbol v10; // [esp+316h] [ebp-2h] BYREF

  _fullpath(UserBuf: szFullSourcePath, path: pSourceName, maxlen: 0x104u);
  V_ExtractFileExtension(path: pSourceName, dest: sourceExtension, destSize: 260);
  v3 = 0;
  if ( g_ExcludeFileTable.m_Lookup.m_NumElements != 0 )
  {
    V_strncpy(pDest: targetExtension, pSrc: szFullSourcePath, maxLen: 260);
    _V_strlower(start: targetExtension);
    V_RemoveDotSlashes(pFilename: targetExtension, separator: 92);
    if ( CUtlSymbolTable::Find(this: &g_ExcludeFileTable, result: &v10, pString: targetExtension)->m_Id != 0xFFFF )
      return 1;
  }
  if ( _V_stricmp(s1: sourceExtension, s2: "wav") != 0 )
  {
    if ( _V_stricmp(s1: sourceExtension, s2: "vtf") != 0 )
    {
      if ( _V_stricmp(s1: sourceExtension, s2: "mdl") != 0 )
      {
        if ( _V_stricmp(s1: sourceExtension, s2: "ani") != 0 )
        {
          if ( _V_stricmp(s1: sourceExtension, s2: "vvd") != 0 )
          {
            if ( _V_stricmp(s1: sourceExtension, s2: "phy") != 0 )
            {
              if ( _V_stricmp(s1: sourceExtension, s2: "bsp") != 0 )
              {
                if ( _V_stricmp(s1: sourceExtension, s2: "ain") != 0 )
                {
                  if ( _V_stricmp(s1: sourceExtension, s2: "lmp") != 0 )
                  {
                    if ( _V_stricmp(s1: sourceExtension, s2: "dat") != 0 )
                    {
                      if ( _V_stricmp(s1: sourceExtension, s2: "vtx") != 0 )
                      {
                        if ( _V_stricmp(s1: sourceExtension, s2: "mp3") == 0 )
                        {
                          V_StripExtension(in: pSourceName, out: pTargetName, outSize: targetNameSize);
                          if ( g_bSonyPS3 )
                            V_strncat(
                              pDest: pTargetName,
                              pSrc: ".ps3.wav",
                              destBufferSize: targetNameSize,
                              max_chars_to_copy: -1);
                          else
                            V_strncat(
                              pDest: pTargetName,
                              pSrc: ".360.wav",
                              destBufferSize: targetNameSize,
                              max_chars_to_copy: -1);
                          return 13;
                        }
                        if ( _V_stricmp(s1: sourceExtension, s2: "lst") != 0 )
                        {
                          if ( _V_stricmp(s1: sourceExtension, s2: "pcf") != 0 )
                          {
                            if ( _V_stricmp(s1: sourceExtension, s2: "nav") != 0 )
                            {
                              if ( _V_stricmp(s1: sourceExtension, s2: "raw") != 0 )
                              {
                                if ( _V_stricmp(s1: sourceExtension, s2: "txt") != 0 )
                                {
                                  if ( _V_stricmp(s1: sourceExtension, s2: "vmt") == 0 && g_bMakeZip )
                                  {
                                    V_strncpy(pDest: pTargetName, pSrc: pSourceName, maxLen: targetNameSize);
                                    return 22;
                                  }
                                }
                                else if ( g_bMakeZip
                                       && IsLocalizedFile(pFileName: pSourceName) != 0
                                       && IsLocalizedFileEnabled(pFileName: pSourceName, pLanguageSuffix: nullptr)
                                       && V_stristr(pStr: pSourceName, pSearch: "closecaption_") == nullptr
                                       && V_stristr(pStr: pSourceName, pSearch: "subtitles_") == nullptr
                                       && IsLocalizationFile(pFilename: szFullSourcePath) != 0 )
                                {
                                  V_strncpy(pDest: pTargetName, pSrc: pSourceName, maxLen: targetNameSize);
                                  return 21;
                                }
                              }
                              else
                              {
                                v3 = V_stristr(pStr: pSourceName, pSearch: ".pwl") != nullptr ? 1 : 18;
                              }
                            }
                            else
                            {
                              v3 = 17;
                            }
                          }
                          else
                          {
                            v3 = 15;
                          }
                        }
                        else if ( V_stristr(pStr: szFullSourcePath, pSearch: "reslists_xbox\\") != nullptr )
                        {
                          v3 = 14;
                        }
                      }
                      else
                      {
                        v3 = V_stristr(pStr: pSourceName, pSearch: ".dx90") != nullptr ? 6 : 1;
                      }
                    }
                    else if ( V_stristr(pStr: pSourceName, pSearch: "closecaption_") != nullptr
                           || V_stristr(pStr: pSourceName, pSearch: "subtitles_") != nullptr )
                    {
                      v3 = 12;
                    }
                    else
                    {
                      v3 = 1;
                    }
                  }
                  else if ( V_stristr(pStr: szFullSourcePath, pSearch: "maps\\") != nullptr )
                  {
                    v3 = 20;
                  }
                }
                else
                {
                  v3 = 11;
                }
              }
              else
              {
                v3 = 10;
              }
            }
            else
            {
              v3 = 8;
            }
          }
          else
          {
            v3 = 7;
          }
        }
        else
        {
          v3 = 5;
        }
      }
      else
      {
        v3 = 4;
      }
    }
    else
    {
      v3 = V_stristr(pStr: pSourceName, pSearch: ".pwl") != nullptr ? 1 : 3;
    }
  }
  else
  {
    v3 = 2;
  }
  v5 = V_stristr(pStr: pSourceName, pSearch: ".360.") != nullptr
    || V_stristr(pStr: pSourceName, pSearch: ".ps3.") != nullptr;
  if ( v3 < 2 || v5 )
  {
    V_strncpy(pDest: pTargetName, pSrc: pSourceName, maxLen: targetNameSize);
    return v3;
  }
  else
  {
    v6 = "ps3";
    if ( !g_bSonyPS3 )
      v6 = "360";
    V_snprintf(pDest: targetExtension, maxLen: 260, pFormat: ".%s.%s", v6, sourceExtension);
    V_StripExtension(in: pSourceName, out: pTargetName, outSize: targetNameSize);
    V_strncat(pDest: pTargetName, pSrc: targetExtension, destBufferSize: targetNameSize, max_chars_to_copy: -1);
    return v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004025F0
// Name: public: CFmtStrN<256>::CFmtStrN<256>(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
CFmtStrN<256> *CFmtStrN<256>::CFmtStrN<256>(CFmtStrN<256> *this, const char *pszFormat, ...)
{
  CFmtStrN<256> *v2; // esi
  char *m_szBuf; // edi
  bool v4; // zf
  char *v6; // [esp-14h] [ebp-1Ch]
  const char *v7; // [esp-Ch] [ebp-14h]
  va_list params; // [esp+18h] [ebp+10h] BYREF

  va_start(params, pszFormat);
  v2 = this;
  v7 = pszFormat;
  m_szBuf = this->m_szBuf;
  v6 = this->m_szBuf;
  this->__vftable = (CFmtStrN<256>_vtbl *)&CFmtStrN<256>::`vftable';
  v2->m_bQuietTruncation = true;
  HIBYTE(this) = 0;
  V_vsnprintfRet(pDest: v6, maxLen: 255, pFormat: v7, params, pbTruncated: (bool *)&this + 3);
  v4 = HIBYTE(this) == 0;
  v2->m_szBuf[255] = 0;
  if ( !v4 && !v2->m_bQuietTruncation && `CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted < 5 )
    ++`CFmtStrN<256>::CFmtStrN<256>'::`4'::scAsserted;
  v2->m_nLength = _V_strlen(str: m_szBuf);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00402810
// Name: public: CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::~CUtlMemory<unsigned char,int>(CUtlBuffer *this)
{
  if ( this->m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402840
// Name: void BuildExcludeFileList(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildExcludeFileList()
{
  const char *v0; // eax
  CFmtStrN<256> *v1; // eax
  char *v2; // eax
  char *v3; // eax
  unsigned int v4; // kr00_4
  unsigned int v5; // esi
  CFmtStrN<256> v6; // [esp+0h] [ebp-44Ch] BYREF
  char excludeScript[260]; // [esp+10Ch] [ebp-340h] BYREF
  char pDest[260]; // [esp+210h] [ebp-23Ch] BYREF
  char szToken[260]; // [esp+314h] [ebp-138h] BYREF
  CUtlBuffer buffer; // [esp+418h] [ebp-34h] BYREF
  CUtlSymbol result; // [esp+448h] [ebp-4h] BYREF
  CUtlSymbol v12; // [esp+44Ah] [ebp-2h] BYREF

  v0 = "ps3";
  if ( !g_bSonyPS3 )
    v0 = "xbox";
  v1 = CFmtStrN<256>::CFmtStrN<256>(this: &v6, pszFormat: "scripts/exclude_%s.xsc", v0);
  FindScriptFile(pFilename: v1->m_szBuf, pOutBuff: excludeScript, nOutBuffSize: 260, bCanFallback: false);
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName: excludeScript, &buffer, bText: true, bNoOpenFailureWarning: true) )
  {
    while ( buffer.m_Error == 0 )
    {
      CUtlBuffer::EatWhiteSpace(this: &buffer);
      CUtlBuffer::EatCPPComment(this: &buffer);
      CUtlBuffer::GetLine(this: &buffer, pLine: szToken, nMaxChars: 260);
      v2 = V_stristr(pStr: szToken, pSearch: "\r");
      if ( v2 != nullptr )
        *v2 = 0;
      v3 = V_stristr(pStr: szToken, pSearch: "\n");
      if ( v3 != nullptr )
        *v3 = 0;
      v4 = strlen(szToken);
      if ( v4 != 0 )
      {
        if ( szToken[0] == 34 )
        {
          memcpy(dst: (unsigned __int8 *)szToken, src: (unsigned __int8 *)&szToken[1], count: v4);
          v5 = v4 - 1;
          if ( (int)(v4 - 1) >= 1 && pDest[v5 + 259] == 34 )
            pDest[v5 + 259] = 0;
        }
        V_ComposeFileName(path: g_szGamePath, filename: szToken, dest: &v6.m_szBuf[3], destSize: 260);
        V_strncpy(pDest, pSrc: &v6.m_szBuf[3], maxLen: 260);
        _V_strlower(start: pDest);
        V_RemoveDotSlashes(pFilename: pDest, separator: 92);
        if ( CUtlSymbolTable::Find(this: &g_ExcludeFileTable, &result, pString: pDest)->m_Id == 0xFFFF )
          CUtlSymbolTable::AddString(this: &g_ExcludeFileTable, result: &v12, pString: pDest);
      }
    }
  }
  else if ( IsLocalizedPath(pFileName: excludeScript) == 0 )
  {
    _Warning(a1: "Missing exclude script file '%s'\n", excludeScript);
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00402A50
// Name: bool IsMapNameInList(char const __near *,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl IsMapNameInList(const char *pMapName, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *mapList)
{
  int v2; // esi
  int v3; // ebx
  char szBaseName[260]; // [esp+Ch] [ebp-114h] BYREF
  CUtlString src; // [esp+110h] [ebp-10h] BYREF

  V_FileBase(in: pMapName, out: szBaseName, maxlen: 260);
  _V_strlower(start: szBaseName);
  CUtlString::CUtlString(this: &src, pString: szBaseName);
  v2 = 0;
  if ( mapList->m_Size <= 0 )
  {
LABEL_5:
    v2 = -1;
  }
  else
  {
    v3 = 0;
    while ( !CUtlString::operator==(this: &mapList->m_Memory.m_pMemory[v3], &src) )
    {
      ++v2;
      ++v3;
      if ( v2 >= mapList->m_Size )
        goto LABEL_5;
    }
  }
  src.m_Storage.m_nActualLength = 0;
  if ( src.m_Storage.m_Memory.m_nGrowSize >= 0 && src.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: src.m_Storage.m_Memory.m_pMemory);
  return v2 != -1;
}

//------------------------------------------------------------------------------
// Address: 0x00402F50
// Name: bool SetupFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SetupFileSystem()
{
  int v1; // edi
  const char *i; // eax
  char v3; // dl
  int v4; // ecx
  int m_Size; // eax
  int v6; // esi
  CUtlString *m_pMemory; // ecx
  int v8; // eax
  CUtlString *v9; // esi
  int v10; // eax
  int v11; // esi
  CUtlString *v12; // ecx
  int v13; // eax
  CUtlString *v14; // esi
  int j; // esi
  const char *v16; // eax
  char string[8320]; // [esp+Ch] [ebp-26BCh] BYREF
  CFSSearchPathsInit initInfo; // [esp+208Ch] [ebp-63Ch] BYREF
  char out[260]; // [esp+2298h] [ebp-430h] BYREF
  char pDest[260]; // [esp+239Ch] [ebp-32Ch] BYREF
  CFSSteamSetupInfo fsInfo; // [esp+24A0h] [ebp-228h] BYREF
  CFSMountContentInfo mountContentInfo; // [esp+26ACh] [ebp-1Ch] BYREF
  CUtlString v23; // [esp+26B8h] [ebp-10h] BYREF

  GetGamePath();
  g_bModPathIsValid = GetModPath();
  if ( g_bModPathIsValid )
  {
    CFSSteamSetupInfo::CFSSteamSetupInfo(this: &fsInfo);
    fsInfo.m_pDirectoryName = g_szModPath;
    *(_DWORD *)&fsInfo.m_bOnlyUseDirectoryName = 65793;
    if ( FileSystem_SetupSteamEnvironment(&fsInfo) != FS_OK )
      return 0;
    CFSMountContentInfo::CFSMountContentInfo(this: &mountContentInfo);
    mountContentInfo.m_pFileSystem = g_pFullFileSystem;
    mountContentInfo.m_bToolsMode = true;
    mountContentInfo.m_pDirectoryName = fsInfo.m_GameInfoPath;
    if ( FileSystem_MountContent(&mountContentInfo) != FS_OK )
      return 0;
    CFSSearchPathsInit::CFSSearchPathsInit(this: &initInfo);
    initInfo.m_pDirectoryName = fsInfo.m_GameInfoPath;
    initInfo.m_pFileSystem = mountContentInfo.m_pFileSystem;
    if ( FileSystem_LoadSearchPaths(&initInfo) != FS_OK )
      return 0;
    V_strncpy(pDest, pSrc: fsInfo.m_GameInfoPath, maxLen: 260);
    V_StripTrailingSlash(ppath: pDest);
    V_strncat(pDest, pSrc: "/../platform", destBufferSize: 0x104u, max_chars_to_copy: 260);
    mountContentInfo.m_pFileSystem->AddSearchPath(
      this: mountContentInfo.m_pFileSystem,
      a2: pDest,
      a3: "PLATFORM",
      a4: PATH_ADD_TO_TAIL);
    v1 = 0;
    mountContentInfo.m_pFileSystem->GetSearchPath(
      this: mountContentInfo.m_pFileSystem,
      a2: "GAME",
      a3: false,
      a4: string,
      a5: 8320);
    for ( i = strtok(string, control: ";"); i != nullptr; i = strtok(string: nullptr, control: ";") )
    {
      v4 = strlen(i);
      if ( v4 >= 1 && i[v4 - 1] == 92 )
        i[v4 - 1] = v3;
      V_FileBase(in: i, out, maxlen: 260);
      CUtlString::CUtlString(this: &v23, pString: out);
      m_Size = g_GameNames.m_Size;
      v6 = g_GameNames.m_Size;
      if ( g_GameNames.m_Size + 1 > g_GameNames.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<ResourceCopy_t,int>::Grow(
          this: (CUtlMemory<ResourceCopy_t,int> *)&g_GameNames,
          num: g_GameNames.m_Size - g_GameNames.m_Memory.m_nAllocationCount + 1);
        m_Size = g_GameNames.m_Size;
      }
      m_pMemory = g_GameNames.m_Memory.m_pMemory;
      g_GameNames.m_Size = m_Size + 1;
      v8 = m_Size - v6;
      g_GameNames.m_pElements = g_GameNames.m_Memory.m_pMemory;
      if ( v8 > 0 )
      {
        _V_memmove(
          dest: &g_GameNames.m_Memory.m_pMemory[v6 + 1],
          src: &g_GameNames.m_Memory.m_pMemory[v6],
          count: 16 * v8);
        m_pMemory = g_GameNames.m_Memory.m_pMemory;
      }
      v9 = &m_pMemory[v6];
      if ( v9 != nullptr )
        CUtlString::CUtlString(this: v9, string: &v23);
      v23.m_Storage.m_nActualLength = 0;
      if ( v23.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( v23.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23.m_Storage.m_Memory.m_pMemory);
          v23.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        v23.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
  }
  else
  {
    v1 = 0;
  }
  CUtlString::CUtlString(this: &v23, pString: "platform");
  v10 = g_GameNames.m_Size;
  v11 = g_GameNames.m_Size;
  if ( g_GameNames.m_Size + 1 > g_GameNames.m_Memory.m_nAllocationCount )
  {
    CUtlMemory<ResourceCopy_t,int>::Grow(
      this: (CUtlMemory<ResourceCopy_t,int> *)&g_GameNames,
      num: g_GameNames.m_Size - g_GameNames.m_Memory.m_nAllocationCount + 1);
    v10 = g_GameNames.m_Size;
  }
  v12 = g_GameNames.m_Memory.m_pMemory;
  g_GameNames.m_Size = v10 + 1;
  v13 = v10 - v11;
  g_GameNames.m_pElements = g_GameNames.m_Memory.m_pMemory;
  if ( v13 > 0 )
  {
    _V_memmove(
      dest: &g_GameNames.m_Memory.m_pMemory[v11 + 1],
      src: &g_GameNames.m_Memory.m_pMemory[v11],
      count: 16 * v13);
    v12 = g_GameNames.m_Memory.m_pMemory;
  }
  v14 = &v12[v11];
  if ( v14 != nullptr )
    CUtlString::CUtlString(this: v14, string: &v23);
  v23.m_Storage.m_nActualLength = 0;
  if ( v23.m_Storage.m_Memory.m_nGrowSize >= 0 && v23.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23.m_Storage.m_Memory.m_pMemory);
  _Msg(a1: "Game Names:\n");
  for ( j = 0; j < g_GameNames.m_Size; ++v1 )
  {
    v16 = CUtlString::operator char const *(this: &g_GameNames.m_Memory.m_pMemory[v1]);
    _Msg(a1: "Game: %s\n", v16);
    ++j;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403290
// Name: void BuildValidMapList(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BuildValidMapList(CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *mapList)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *m_pMemory; // ecx
  int v4; // eax
  CUtlString *v5; // ecx
  char szFilename[260]; // [esp+0h] [ebp-44Ch] BYREF
  char szMapName[260]; // [esp+104h] [ebp-348h] BYREF
  char szToken[260]; // [esp+208h] [ebp-244h] BYREF
  characterset_t breakSet; // [esp+30Ch] [ebp-140h] BYREF
  CUtlBuffer buffer; // [esp+40Ch] [ebp-40h] BYREF
  CUtlString string; // [esp+43Ch] [ebp-10h] BYREF

  V_ComposeFileName(path: g_szModPath, filename: "maplist.txt", dest: szFilename, destSize: 260);
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  if ( ReadFileToBuffer(pSourceName: szFilename, &buffer, bText: true, bNoOpenFailureWarning: true) )
  {
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: pDefaultValue);
    while ( CUtlBuffer::ParseToken(
              this: &buffer,
              pBreaks: &breakSet,
              pTokenBuf: szToken,
              nMaxLen: 260,
              bParseComments: true) > 0 )
    {
      V_FileBase(in: szToken, out: szMapName, maxlen: 260);
      _V_strlower(start: szMapName);
      CUtlString::CUtlString(this: &string, pString: szMapName);
      m_Size = mapList->m_Size;
      m_nAllocationCount = mapList->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<ResourceCopy_t,int>::Grow(
          this: (CUtlMemory<ResourceCopy_t,int> *)mapList,
          num: m_Size - m_nAllocationCount + 1);
      ++mapList->m_Size;
      m_pMemory = mapList->m_Memory.m_pMemory;
      v4 = mapList->m_Size - m_Size - 1;
      mapList->m_pElements = mapList->m_Memory.m_pMemory;
      if ( v4 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v4);
      v5 = &mapList->m_Memory.m_pMemory[m_Size];
      if ( v5 != nullptr )
        CUtlString::CUtlString(this: v5, &string);
      string.m_Storage.m_nActualLength = 0;
      if ( string.m_Storage.m_Memory.m_nGrowSize >= 0 )
      {
        if ( string.m_Storage.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: string.m_Storage.m_Memory.m_pMemory);
          string.m_Storage.m_Memory.m_pMemory = nullptr;
        }
        string.m_Storage.m_Memory.m_nAllocationCount = 0;
      }
    }
  }
  if ( buffer.m_Memory.m_nGrowSize >= 0 && buffer.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004035B0
// Name: public: void CUtlDict<int,unsigned short>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlDict<int,unsigned short>::RemoveAll(CUtlDict<int,unsigned short> *this)
{
  unsigned __int16 i; // si

  for ( i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_Elements.m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_Elements.m_Tree,
              i) )
  {
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)this->m_Elements.m_Tree.m_Elements.m_pMemory[i].m_Data.key);
  }
  CUtlRBTree<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short,CUtlMap<char const *,int,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x00403680
// Name: void ExcludeFiles(char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ExcludeFiles(int pExcludeScript, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  const char *v2; // esi
  int *m_pMemory; // edi
  signed int m_Size; // ebx
  int v5; // esi
  const char *v6; // esi
  signed int v7; // esi
  int *v8; // esi
  int v9; // ecx
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v10; // edx
  int v11; // edi
  fileList_t *v12; // esi
  bool v13; // sf
  int v14; // eax
  characterset_t breakSet; // [esp+Ch] [ebp-298h] BYREF
  char szToken[260]; // [esp+10Ch] [ebp-198h] BYREF
  CUtlSymbolTable symbolTable; // [esp+210h] [ebp-94h] BYREF
  CUtlBuffer buffer; // [esp+248h] [ebp-5Ch] BYREF
  CUtlSortVector<int,CFileLess> indicesToRemove; // [esp+278h] [ebp-2Ch] BYREF
  int i; // [esp+294h] [ebp-10h]
  void *context; // [esp+298h] [ebp-Ch] BYREF
  int iIndex; // [esp+29Ch] [ebp-8h]
  unsigned int v23; // [esp+2A0h] [ebp-4h] BYREF

  v2 = (const char *)pExcludeScript;
  m_pMemory = nullptr;
  if ( pExcludeScript != 0 && *(_BYTE *)pExcludeScript != 0 )
  {
    CUtlSymbolTable::CUtlSymbolTable(this: &symbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
    CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: pDefaultValue);
    CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
    if ( ReadFileToBuffer(pSourceName: v2, &buffer, bText: true, bNoOpenFailureWarning: true)
      && CUtlBuffer::ParseToken(
           this: &buffer,
           pBreaks: &breakSet,
           pTokenBuf: szToken,
           nMaxLen: 260,
           bParseComments: true) > 0 )
    {
      do
      {
        V_RemoveDotSlashes(pFilename: szToken, separator: 92);
        if ( CUtlSymbolTable::Find(this: &symbolTable, result: (CUtlSymbol *)&pExcludeScript + 1, pString: szToken)->m_Id == 0xFFFF )
          CUtlSymbolTable::AddString(this: &symbolTable, result: (CUtlSymbol *)&v23 + 1, pString: szToken);
      }
      while ( CUtlBuffer::ParseToken(
                this: &buffer,
                pBreaks: &breakSet,
                pTokenBuf: szToken,
                nMaxLen: 260,
                bParseComments: true) > 0 );
    }
    m_Size = 0;
    v5 = 0;
    memset(&indicesToRemove, 0, 25);
    i = 0;
    if ( symbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        iIndex = (int)CUtlSymbolTable::String(this: &symbolTable, id: (CUtlSymbol)v5);
        pExcludeScript = 0;
        if ( fileList->m_Size > 0 )
        {
          v23 = 0;
          do
          {
            v6 = CUtlString::Get(this: &fileList->m_Memory.m_pMemory[v23 / 0x18].fileName);
            if ( V_strnicmp(s1: v6, s2: asc_58D3CC, n: 2) == 0 )
              v6 += 2;
            if ( IsWildcardMatch(wildcardString: (const char *)iIndex, stringToCheck: v6, bCaseSensitive: false) )
            {
              indicesToRemove.m_bNeedsSort = true;
              v7 = m_Size;
              if ( m_Size + 1 > indicesToRemove.m_Memory.m_nAllocationCount )
              {
                CUtlMemory<IDmFormatUpdater *,int>::Grow(
                  this: (CUtlMemory<S3RGBA,int> *)&indicesToRemove,
                  num: m_Size - indicesToRemove.m_Memory.m_nAllocationCount + 1);
                m_Size = indicesToRemove.m_Size;
                m_pMemory = indicesToRemove.m_Memory.m_pMemory;
              }
              indicesToRemove.m_Size = ++m_Size;
              indicesToRemove.m_pElements = m_pMemory;
              if ( m_Size - v7 - 1 > 0 )
                _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - 1));
              v8 = &m_pMemory[v7];
              if ( v8 != nullptr )
                *v8 = pExcludeScript;
            }
            v23 += 24;
            ++pExcludeScript;
          }
          while ( pExcludeScript < fileList->m_Size );
          v5 = i;
        }
        i = ++v5;
      }
      while ( v5 < symbolTable.m_Lookup.m_NumElements );
      if ( indicesToRemove.m_bNeedsSort && m_Size > 1 )
      {
        context = indicesToRemove.m_pLessContext;
        iIndex = (int)&pExcludeScript + 3;
        qsort_s(
          base: m_pMemory,
          num: m_Size,
          width: 4u,
          comp: (int (__cdecl *)(void *, const void *, const void *))CUtlSortVector<int,CFileLess>::CompareHelper,
          &context);
      }
    }
    pExcludeScript = 0;
    if ( m_Size > 0 )
    {
      do
      {
        v9 = m_pMemory[pExcludeScript];
        v10 = fileList;
        v11 = v9;
        v12 = &fileList->m_Memory.m_pMemory[v9];
        v13 = v12->fileName.m_Storage.m_Memory.m_nGrowSize < 0;
        iIndex = v9;
        v12->fileName.m_Storage.m_nActualLength = 0;
        if ( !v13 )
        {
          if ( v12->fileName.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v12->fileName.m_Storage.m_Memory.m_pMemory);
            v10 = fileList;
            v9 = iIndex;
            v12->fileName.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v12->fileName.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
        if ( v10->m_Size - v9 - 1 > 0 )
        {
          _V_memmove(
            dest: &v10->m_Memory.m_pMemory[v11],
            src: &v10->m_Memory.m_pMemory[v11 + 1],
            count: 24 * (v10->m_Size - v9 - 1));
          v10 = fileList;
        }
        v14 = pExcludeScript;
        --v10->m_Size;
        m_pMemory = indicesToRemove.m_Memory.m_pMemory;
        pExcludeScript = v14 + 1;
      }
      while ( v14 + 1 < m_Size );
    }
    if ( indicesToRemove.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    if ( buffer.m_Memory.m_nGrowSize >= 0 )
    {
      if ( buffer.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
        buffer.m_Memory.m_pMemory = nullptr;
      }
      buffer.m_Memory.m_nAllocationCount = 0;
    }
    CUtlSymbolTable::~CUtlSymbolTable(this: &symbolTable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004039B0
// Name: bool GenerateTargetFiles(class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl GenerateTargetFiles(CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  const char *v1; // edi
  int v2; // eax
  char v3; // cl
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v4; // esi
  int *m_pMemory; // ebx
  int j; // eax
  int v7; // esi
  int v8; // ecx
  int v9; // edi
  const char *v10; // esi
  int v11; // eax
  char v12; // cl
  unsigned int v13; // eax
  char *v14; // edi
  char v15; // cl
  int v16; // eax
  char v17; // cl
  unsigned int v18; // eax
  char *v19; // edi
  char v20; // cl
  int v21; // esi
  int v22; // edx
  bool v23; // al
  bool v24; // al
  int v25; // edx
  int v26; // eax
  int v27; // ecx
  int v29; // eax
  const char *v30; // ebx
  int v31; // eax
  char v32; // cl
  unsigned int v33; // eax
  char *v34; // edi
  char v35; // cl
  int v36; // eax
  char v37; // cl
  unsigned int v38; // eax
  char *v39; // edi
  char v40; // cl
  fileType_e v41; // esi
  int v42; // eax
  int v43; // eax
  int v44; // esi
  errorList_t *v45; // ecx
  int v46; // eax
  unsigned int v47; // esi
  int v48; // eax
  int v49; // esi
  int *v50; // eax
  const char *v51; // eax
  bool v52; // bl
  int v53; // edi
  int v54; // ebx
  int *v55; // eax
  int v56; // eax
  int v57; // esi
  errorList_t *v58; // ecx
  int v59; // eax
  unsigned int v60; // esi
  char *v61; // esi
  CFmtStrN<256> *v62; // eax
  _iobuf *v63; // esi
  _iobuf *v64; // edi
  int v65; // ebx
  int v66; // esi
  const char *v67; // eax
  const char *v68; // eax
  int m_Size; // [esp-4h] [ebp-514h]
  CFmtStrN<256> v70; // [esp+Ch] [ebp-504h] BYREF
  char sourcePath[260]; // [esp+118h] [ebp-3F8h] BYREF
  char sourceFile[260]; // [esp+21Ch] [ebp-2F4h] BYREF
  _stat64i32 targetStatBuf; // [esp+320h] [ebp-1F0h] BYREF
  _stat64i32 sourceStatBuf; // [esp+350h] [ebp-1C0h] BYREF
  char targetFile[260]; // [esp+380h] [ebp-190h] BYREF
  CUtlBuffer targetBuffer; // [esp+484h] [ebp-8Ch] BYREF
  CUtlBuffer workLogBuffer; // [esp+4B4h] [ebp-5Ch] BYREF
  CUtlVector<int,CUtlMemory<int,int> > updateList; // [esp+4E4h] [ebp-2Ch] BYREF
  int v79; // [esp+4F8h] [ebp-18h]
  int numFilesToUpdate; // [esp+4FCh] [ebp-14h]
  char v81; // [esp+503h] [ebp-Dh]
  int numWorkItems; // [esp+504h] [ebp-Ch]
  const char *ptr; // [esp+508h] [ebp-8h]
  int i; // [esp+50Ch] [ebp-4h]

  v1 = nullptr;
  v2 = 0;
  do
  {
    v3 = g_szSourcePath[v2];
    sourcePath[v2++] = v3;
  }
  while ( v3 != 0 );
  V_StripFilename(path: sourcePath);
  if ( sourcePath[0] == 0 )
    strcpy(sourcePath, ".");
  V_AppendSlash(pStr: sourcePath, strSize: 260);
  v4 = fileList;
  m_Size = fileList->m_Size;
  memset(&updateList, 0, sizeof(updateList));
  CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&updateList,
    elem: 0,
    num: m_Size);
  m_pMemory = updateList.m_Memory.m_pMemory;
  for ( j = 0; j < fileList->m_Size; ++j )
    m_pMemory[j] = 3;
  i = 0;
  if ( fileList->m_Size > 0 )
  {
    numWorkItems = 0;
    while ( 1 )
    {
      v7 = numWorkItems;
      if ( CUtlString::Length(this: (CUtlString *)((char *)&fileList->m_Memory.m_pMemory->fileName + numWorkItems)) == 0 )
      {
        v8 = i;
        m_pMemory[i] = 0;
        v9 = v8;
        goto LABEL_73;
      }
      v10 = CUtlString::operator char const *(this: (CUtlString *)((char *)&fileList->m_Memory.m_pMemory->fileName + v7));
      ptr = v10;
      if ( V_strncasecmp(s1: v10, s2: asc_58D3CC, n: 2) == 0 )
        break;
      if ( V_strncasecmp(s1: v10, s2: sourcePath, n: strlen(sourcePath)) == 0 )
      {
        v10 += strlen(sourcePath);
        goto LABEL_15;
      }
LABEL_16:
      v11 = 0;
      do
      {
        v12 = sourcePath[v11];
        sourceFile[v11++] = v12;
      }
      while ( v12 != 0 );
      v13 = strlen(v10) + 1;
      v14 = &sourcePath[259];
      do
        v15 = *++v14;
      while ( v15 != 0 );
      qmemcpy(v14, v10, v13);
      v16 = 0;
      do
      {
        v17 = g_targetPath[v16];
        targetFile[v16++] = v17;
      }
      while ( v17 != 0 );
      v18 = strlen(ptr) + 1;
      v19 = (char *)&sourceStatBuf.st_ctime + 7;
      do
        v20 = *++v19;
      while ( v20 != 0 );
      qmemcpy(v19, ptr, v18);
      v21 = ResolveFileType(pSourceName: sourceFile, pTargetName: targetFile, targetNameSize: 260);
      if ( v21 == 1 )
      {
        v22 = i;
        m_pMemory[i] = 0;
        v9 = v22;
      }
      else
      {
        if ( IncludeInZip(pSourceName: targetFile)
          || g_bDvdDevMode && V_stristr(pStr: targetFile, pSearch: ".swf") != nullptr )
        {
          v9 = i;
        }
        else
        {
          v9 = i;
          m_pMemory[i] &= ~2u;
        }
        if ( g_bMakeZip )
        {
          if ( g_bTexturesOnly || g_bNoTextures )
          {
            v23 = V_stristr(pStr: targetFile, pSearch: ".vmt") != nullptr
               || V_stristr(pStr: targetFile, pSearch: ".vtf") != nullptr;
            if ( g_bTexturesOnly && !v23 || g_bNoTextures && v23 )
              goto LABEL_72;
          }
          if ( g_bMakeZip && (g_bAudioOnly || g_bNoAudio) )
          {
            v24 = V_stristr(pStr: targetFile, pSearch: ".wav") != nullptr;
            if ( g_bAudioOnly && !v24 )
              goto LABEL_72;
            if ( g_bNoAudio && v24 )
              goto LABEL_72;
          }
        }
        if ( v21 != 0 )
        {
          if ( V_stristr(pStr: sourceFile, pSearch: ".360.") == nullptr
            && V_stristr(pStr: sourceFile, pSearch: ".ps3.") == nullptr
            && (v21 != 10 && v21 != 11 && v21 != 14 && v21 != 17
             || g_ValidMapList.m_Size == 0
             || IsMapNameInList(pMapName: sourceFile, mapList: &g_ValidMapList))
            && _stat64i32(name: sourceFile, buf: &sourceStatBuf) == 0 )
          {
            if ( v21 != 4
              && v21 != 5
              && v21 != 6
              && v21 != 7
              && v21 != 8
              && v21 != 9
              && _V_stricmp(s1: sourceFile, s2: targetFile) != 0
              && _stat64i32(name: targetFile, buf: &targetStatBuf) == 0
              && !g_bForce
              && _difftime64(b: sourceStatBuf.st_mtime, a: targetStatBuf.st_mtime) <= 0.0 )
            {
              m_pMemory[v9] &= ~1u;
              if ( g_bDvdDevMode )
                m_pMemory[v9] |= 4u;
            }
            goto LABEL_73;
          }
LABEL_72:
          m_pMemory[v9] = 0;
          goto LABEL_73;
        }
        m_pMemory[v9] &= ~1u;
      }
LABEL_73:
      numWorkItems += 24;
      i = v9 + 1;
      if ( v9 + 1 >= fileList->m_Size )
      {
        v4 = fileList;
        v1 = nullptr;
        goto LABEL_75;
      }
    }
    v10 += 2;
LABEL_15:
    ptr = v10;
    goto LABEL_16;
  }
LABEL_75:
  v25 = 0;
  v26 = 0;
  numWorkItems = 0;
  numFilesToUpdate = 0;
  ptr = nullptr;
  if ( v4->m_Size > 0 )
  {
    do
    {
      if ( g_bDvdDevMode && m_pMemory[v26] != 0 )
        m_pMemory[v26] |= 4u;
      v27 = m_pMemory[v26];
      if ( (v27 & 1) != 0 )
        ++v25;
      if ( g_bMakeZip && (v27 & 2) != 0 )
        ++v1;
      else
        m_pMemory[v26] &= ~2u;
      if ( m_pMemory[v26] != 0 )
        ++numWorkItems;
      ++v26;
    }
    while ( v26 < v4->m_Size );
    ptr = v1;
    numFilesToUpdate = v25;
  }
  _Msg(a1: "\n");
  _Msg(a1: "Creating or Updating %d files.\n", numFilesToUpdate);
  if ( g_bMakeZip )
    _Msg(a1: "Zipping %d files.\n", ptr);
  if ( ptr != nullptr && !g_bTest )
  {
    _Msg(a1: "Creating Zip: %s\n", g_zipPath);
    if ( !CXZipTool::Begin(this: &g_MasterXZip, pZipFileName: g_zipPath, alignment: 0x800u) )
    {
      _Warning(a1: "ERROR: Failed to open \"%s\" for writing.\n", g_zipPath);
      if ( updateList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      return 0;
    }
    SetupCriticalPreloadScript();
    GetAlternateFileFixupScript();
  }
  CUtlBuffer::CUtlBuffer(this: &workLogBuffer, growSize: 0, initSize: 0, nFlags: 1);
  v29 = 0;
  i = 0;
  if ( v4->m_Size > 0 )
  {
    v79 = 1;
    numFilesToUpdate = 0;
    while ( m_pMemory[v29] == 0 )
    {
LABEL_149:
      numFilesToUpdate += 24;
      i = ++v29;
      if ( v29 >= v4->m_Size )
        goto LABEL_150;
    }
    v30 = CUtlString::operator char const *(this: (CUtlString *)((char *)&v4->m_Memory.m_pMemory->fileName
                                                               + numFilesToUpdate));
    if ( V_strncasecmp(s1: v30, s2: asc_58D3CC, n: 2) != 0 )
    {
      if ( V_strncasecmp(s1: v30, s2: sourcePath, n: strlen(sourcePath)) == 0 )
        v30 += strlen(sourcePath);
    }
    else
    {
      v30 += 2;
    }
    v31 = 0;
    do
    {
      v32 = sourcePath[v31];
      sourceFile[v31++] = v32;
    }
    while ( v32 != 0 );
    v33 = strlen(v30) + 1;
    v34 = &sourcePath[259];
    do
      v35 = *++v34;
    while ( v35 != 0 );
    qmemcpy(v34, v30, v33);
    v36 = 0;
    do
    {
      v37 = g_targetPath[v36];
      targetFile[v36++] = v37;
    }
    while ( v37 != 0 );
    v38 = strlen(v30) + 1;
    v39 = (char *)&sourceStatBuf.st_ctime + 7;
    do
      v40 = *++v39;
    while ( v40 != 0 );
    qmemcpy(v39, v30, v38);
    v41 = ResolveFileType(pSourceName: sourceFile, pTargetName: targetFile, targetNameSize: 260);
    _Msg(a1: "%d/%d:%s -> %s\n", v79, numWorkItems, sourceFile, targetFile);
    v42 = updateList.m_Memory.m_pMemory[i];
    if ( (v42 & 1) != 0 )
    {
      if ( !CreateTargetFile(
              pSourceName: sourceFile,
              pTargetName: targetFile,
              fileType: v41,
              bWriteToZip: (updateList.m_Memory.m_pMemory[i] & 2) != 0) )
      {
        v43 = g_errorList.m_Size;
        v44 = g_errorList.m_Size;
        if ( g_errorList.m_Size + 1 > g_errorList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
            this: (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)&g_errorList,
            num: g_errorList.m_Size - g_errorList.m_Memory.m_nAllocationCount + 1);
          v43 = g_errorList.m_Size;
        }
        v45 = g_errorList.m_Memory.m_pMemory;
        g_errorList.m_Size = v43 + 1;
        v46 = v43 - v44;
        g_errorList.m_pElements = g_errorList.m_Memory.m_pMemory;
        if ( v46 > 0 )
        {
          _V_memmove(
            dest: &g_errorList.m_Memory.m_pMemory[v44 + 1],
            src: &g_errorList.m_Memory.m_pMemory[v44],
            count: 20 * v46);
          v45 = g_errorList.m_Memory.m_pMemory;
        }
        v47 = v44;
        if ( &v45[v47] != nullptr )
        {
          CUtlString::CUtlString(this: &v45[v47].fileName);
          v45 = g_errorList.m_Memory.m_pMemory;
        }
        v45[v47].result = MODELPROCESS_UNDEFINED_ERROR;
        CUtlString::Set(this: &g_errorList.m_Memory.m_pMemory[v47].fileName, pValue: sourceFile);
LABEL_148:
        ++v79;
        m_pMemory = updateList.m_Memory.m_pMemory;
        v29 = i;
        v4 = fileList;
        goto LABEL_149;
      }
LABEL_144:
      if ( (updateList.m_Memory.m_pMemory[i] & 4) != 0 )
      {
        v61 = targetFile;
        if ( V_strnicmp(s1: targetFile, s2: asc_58D3CC, n: 2) == 0 )
          v61 = &targetFile[2];
        v62 = CFmtStrN<256>::CFmtStrN<256>(this: &v70, pszFormat: "\"%s\"\n", v61);
        CUtlBuffer::PutString(this: &workLogBuffer, pString: v62->m_szBuf);
      }
      goto LABEL_148;
    }
    if ( (v42 & 2) == 0 )
      goto LABEL_144;
    CUtlBuffer::CUtlBuffer(this: &targetBuffer, growSize: 0, initSize: 0, nFlags: 0);
    v81 = 1;
    v48 = _open(path: targetFile, oflag: 0x8000, pmode: 0);
    v49 = v48;
    if ( v48 == -1 )
    {
      v50 = _errno();
      v51 = strerror(errnum: *v50);
      _Warning(a1: "ReadFileToBuffer(): Error opening %s: %s\n", targetFile, v51);
      v52 = false;
    }
    else
    {
      _lseek(fh: v48, pos: 0, mthd: 2);
      v53 = _tell(filedes: v49);
      _lseek(fh: v49, pos: 0, mthd: 0);
      CUtlBuffer::EnsureCapacity(this: &targetBuffer, num: v53);
      CUtlBuffer::SeekPut(this: &targetBuffer, type: SEEK_CURRENT, offset: v53);
      v54 = _read(fh: v49, buf: targetBuffer.m_Memory.m_pMemory, cnt: v53);
      if ( v54 == v53 )
      {
        v52 = v81;
      }
      else
      {
        v55 = _errno();
        _Warning(a1: "ReadFileToBuffer(): read failure %d, errno=%d\n", v54, *v55);
        v52 = false;
      }
      CUtlBuffer::SetBufferType(this: &targetBuffer, bIsText: false, bContainsCRLF: false);
      _close(fh: v49);
      if ( v52 )
      {
        if ( !g_bTest )
          v52 = CXZipTool::AddBuffer(
                  this: &g_MasterXZip,
                  pFilename: targetFile,
                  fileBuffer: &targetBuffer,
                  bDoPreload: true);
        if ( v52 )
        {
LABEL_140:
          if ( targetBuffer.m_Memory.m_nGrowSize >= 0 && targetBuffer.m_Memory.m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: targetBuffer.m_Memory.m_pMemory);
          if ( !v52 )
            goto LABEL_148;
          goto LABEL_144;
        }
      }
    }
    v56 = g_errorList.m_Size;
    v57 = g_errorList.m_Size;
    if ( g_errorList.m_Size + 1 > g_errorList.m_Memory.m_nAllocationCount )
    {
      CUtlMemory<CUtlVector<CAttributeNode *,CUtlMemory<CAttributeNode *,int>>,int>::Grow(
        this: (CUtlMemory<UtlRBTreeNode_t<CDmElement *,int>,int> *)&g_errorList,
        num: g_errorList.m_Size - g_errorList.m_Memory.m_nAllocationCount + 1);
      v56 = g_errorList.m_Size;
    }
    v58 = g_errorList.m_Memory.m_pMemory;
    g_errorList.m_Size = v56 + 1;
    v59 = v56 - v57;
    g_errorList.m_pElements = g_errorList.m_Memory.m_pMemory;
    if ( v59 > 0 )
    {
      _V_memmove(
        dest: &g_errorList.m_Memory.m_pMemory[v57 + 1],
        src: &g_errorList.m_Memory.m_pMemory[v57],
        count: 20 * v59);
      v58 = g_errorList.m_Memory.m_pMemory;
    }
    v60 = v57;
    if ( &v58[v60] != nullptr )
    {
      CUtlString::CUtlString(this: &v58[v60].fileName);
      v58 = g_errorList.m_Memory.m_pMemory;
    }
    v58[v60].result = MODELPROCESS_READFILE_ERROR;
    CUtlString::Set(this: &g_errorList.m_Memory.m_pMemory[v60].fileName, pValue: targetFile);
    goto LABEL_140;
  }
LABEL_150:
  if ( workLogBuffer.m_Put != 0 && g_szLogName[0] != 0 )
  {
    v63 = fopen(file: g_szLogName, mode: "wt");
    if ( v63 != nullptr )
    {
      fwrite(buffer: workLogBuffer.m_Memory.m_pMemory, size: 1u, count: workLogBuffer.m_Put, stream: v63);
      fclose(stream: v63);
    }
  }
  DoPostProcessingFunctions(bWriteToZip: !g_bTest);
  if ( ptr != nullptr && !g_bTest )
    CXZipTool::End(this: &g_MasterXZip);
  v64 = nullptr;
  if ( g_errorList.m_Size != 0 && g_szLogName[0] != 0 )
    v64 = fopen(file: "makegamedata.err", mode: "wt");
  _Msg(a1: "\n");
  v65 = 0;
  if ( g_errorList.m_Size > 0 )
  {
    v66 = 0;
    do
    {
      v67 = CUtlString::operator char const *(this: &g_errorList.m_Memory.m_pMemory[v66].fileName);
      _Warning(a1: "%s: Could not process %s\n", s_pErrorStrings[g_errorList.m_Memory.m_pMemory[v66].result], v67);
      if ( v64 != nullptr )
      {
        v68 = CUtlString::operator char const *(this: &g_errorList.m_Memory.m_pMemory[v66].fileName);
        fprintf(str: v64, format: (const char *)&stru_58D3D0, v68);
      }
      ++v65;
      ++v66;
    }
    while ( v65 < g_errorList.m_Size );
  }
  if ( v64 != nullptr )
    fclose(stream: v64);
  if ( workLogBuffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( workLogBuffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workLogBuffer.m_Memory.m_pMemory);
      workLogBuffer.m_Memory.m_pMemory = nullptr;
    }
    workLogBuffer.m_Memory.m_nAllocationCount = 0;
  }
  if ( updateList.m_Memory.m_nGrowSize >= 0 && updateList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: updateList.m_Memory.m_pMemory);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00404560
// Name: int GetFileList(char const __near *,char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetFileList(
        const char *pDirPath,
        const char *pPattern,
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *fileList)
{
  unsigned int v4; // kr00_4
  int v5; // eax
  char v6; // cl
  char *v7; // edi
  char v8; // al
  unsigned int v9; // eax
  char *v10; // edi
  char v11; // cl
  int v12; // esi
  int v14; // eax
  char v15; // cl
  unsigned int v16; // eax
  char *v17; // edi
  char v18; // cl
  char *v19; // edi
  char *v20; // esi
  char v21; // cl
  int m_Size; // eax
  int v23; // esi
  char v24; // [esp+Bh] [ebp-435h] BYREF
  char fileName[260]; // [esp+Ch] [ebp-434h] BYREF
  char fullPath[260]; // [esp+110h] [ebp-330h] BYREF
  _finddata64i32_t findData; // [esp+214h] [ebp-22Ch] BYREF
  char sourcePath[260]; // [esp+33Ch] [ebp-104h] BYREF
  int h; // [esp+448h] [ebp+8h]
  char bFindDirs_3; // [esp+453h] [ebp+13h]

  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: fileList);
  if ( fileList->m_Memory.m_nGrowSize >= 0 )
  {
    if ( fileList->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList->m_Memory.m_pMemory);
      fileList->m_Memory.m_pMemory = nullptr;
    }
    fileList->m_Memory.m_nAllocationCount = 0;
  }
  fileList->m_pElements = fileList->m_Memory.m_pMemory;
  strcpy(sourcePath, pDirPath);
  v4 = strlen(sourcePath);
  if ( v4 != 0 )
  {
    if ( findData.name[v4 + 259] != 92 )
    {
      sourcePath[v4] = 92;
      sourcePath[v4 + 1] = 0;
    }
  }
  else
  {
    strcpy(sourcePath, ".\\");
  }
  v5 = 0;
  do
  {
    v6 = sourcePath[v5];
    fullPath[v5++] = v6;
  }
  while ( v6 != 0 );
  if ( *pPattern != 92 || pPattern[1] != 0 )
  {
    bFindDirs_3 = 0;
    v9 = strlen(pPattern) + 1;
    v10 = &fileName[259];
    do
      v11 = *++v10;
    while ( v11 != 0 );
    qmemcpy(v10, pPattern, v9);
  }
  else
  {
    bFindDirs_3 = 1;
    v7 = &fileName[259];
    do
      v8 = *++v7;
    while ( v8 != 0 );
    strcpy(v7, "*");
  }
  v12 = _findfirst64i32(szWild: fullPath, pfd: &findData);
  h = v12;
  if ( v12 == -1 )
    return 0;
  do
  {
    if ( bFindDirs_3 != 0 )
    {
      if ( (findData.attrib & 0x10) == 0 )
        continue;
    }
    else if ( (findData.attrib & 0x10) != 0 )
    {
      continue;
    }
    if ( _V_stricmp(s1: findData.name, s2: ".") != 0 && _V_stricmp(s1: findData.name, s2: "..") != 0 )
    {
      v14 = 0;
      do
      {
        v15 = sourcePath[v14];
        fileName[v14++] = v15;
      }
      while ( v15 != 0 );
      v16 = strlen(findData.name) + 1;
      v17 = &v24;
      do
        v18 = *++v17;
      while ( v18 != 0 );
      qmemcpy(v17, findData.name, 4 * (v16 >> 2));
      v20 = &findData.name[4 * (v16 >> 2)];
      v19 = &v17[4 * (v16 >> 2)];
      v21 = v16;
      m_Size = fileList->m_Size;
      qmemcpy(v19, v20, v21 & 3);
      v23 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertBefore(
              this: (CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *)fileList,
              elem: m_Size);
      CUtlString::Set(this: &fileList->m_Memory.m_pMemory[v23].m_Name, pValue: fileName);
      *(_QWORD *)&fileList->m_Memory.m_pMemory[v23].m_flPercentage = findData.time_write;
      v12 = h;
    }
  }
  while ( _findnext64i32(hFile: v12, pfd: &findData) == 0 );
  _findclose(hFile: v12);
  return fileList->m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00404820
// Name: void RecurseFileTree_r(char const __near *,int,class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RecurseFileTree_r(
        const char *pDirPath,
        int depth,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *dirList)
{
  fileList_t *i; // ebx
  int v4; // eax
  int v5; // eax
  fileList_t *m_pMemory; // edi
  const char *v7; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlString *v10; // ecx
  int v11; // eax
  int v12; // edi
  CUtlString *v13; // ecx
  int v14; // [esp-8h] [ebp-2Ch]
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-18h] BYREF
  int v16; // [esp+20h] [ebp-4h]

  i = nullptr;
  memset(&fileList, 0, sizeof(fileList));
  v4 = GetFileList(
         pDirPath,
         pPattern: "\\",
         (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  if ( v4 != 0 )
  {
    if ( v4 > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      v16 = depth + 1;
      for ( i = (fileList_t *)v4; i != nullptr; i = (fileList_t *)((char *)i - 1) )
      {
        v14 = v16;
        v7 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        RecurseFileTree_r(pDirPath: v7, depth: v14, dirList);
        ++m_pMemory;
      }
    }
    m_Size = dirList->m_Size;
    m_nAllocationCount = dirList->m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ResourceCopy_t,int>::Grow(
        this: (CUtlMemory<ResourceCopy_t,int> *)dirList,
        num: m_Size - m_nAllocationCount + 1);
    ++dirList->m_Size;
    v10 = dirList->m_Memory.m_pMemory;
    v11 = dirList->m_Size - m_Size - 1;
    dirList->m_pElements = dirList->m_Memory.m_pMemory;
    if ( v11 > (int)i )
      _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 16 * v11);
    v12 = m_Size;
    v13 = &dirList->m_Memory.m_pMemory[v12];
    if ( v13 != nullptr )
      CUtlString::CUtlString(this: v13);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v12], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    if ( fileList.m_Memory.m_nGrowSize >= (int)i && fileList.m_Memory.m_pMemory != i )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
  else
  {
    v5 = CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: dirList, elem: dirList->m_Size);
    CUtlString::Set(this: &dirList->m_Memory.m_pMemory[v5], pValue: pDirPath);
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404940
// Name: int FindFiles(char const __near *,bool,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindFiles(
        const char *pFileMask,
        bool bRecurse,
        CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  char *v3; // edi
  char v4; // al
  unsigned int v5; // eax
  char *v6; // edi
  char v7; // cl
  int v8; // esi
  int v9; // eax
  fileList_t *v10; // edi
  int v11; // ebx
  fileList_t *v12; // esi
  int v13; // edx
  bool v14; // zf
  int m_nGrowSize; // esi
  fileList_t *m_pMemory; // eax
  const char *v17; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v18; // esi
  int m_Size; // edi
  int inserted; // eax
  fileList_t *v21; // edi
  int v22; // ebx
  CUtlString *p_fileName; // esi
  int timeWrite_high; // eax
  CUtlString *v25; // eax
  int v26; // esi
  unsigned int v28; // [esp-8h] [ebp-348h]
  char extension[260]; // [esp+8h] [ebp-338h] BYREF
  char dirPath[260]; // [esp+10Ch] [ebp-234h] BYREF
  char pattern[260]; // [esp+210h] [ebp-130h] BYREF
  int i; // [esp+314h] [ebp-2Ch]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > dirList; // [esp+318h] [ebp-28h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > tempList; // [esp+32Ch] [ebp-14h] BYREF
  const char *pFileMaska; // [esp+348h] [ebp+8h]
  int bRecursea; // [esp+34Ch] [ebp+Ch]
  int bRecurseb; // [esp+34Ch] [ebp+Ch]

  strcpy(dirPath, pFileMask);
  V_StripFilename(path: dirPath);
  V_FileBase(in: pFileMask, out: pattern, maxlen: 260);
  V_ExtractFileExtension(path: pFileMask, dest: extension, destSize: 260);
  if ( extension[0] != 0 )
  {
    v3 = &dirPath[259];
    do
      v4 = *++v3;
    while ( v4 != 0 );
    strcpy(v3, ".");
    v5 = strlen(extension) + 1;
    v6 = &dirPath[259];
    do
      v7 = *++v6;
    while ( v7 != 0 );
    qmemcpy(v6, extension, v5);
  }
  memset(&tempList, 0, sizeof(tempList));
  if ( bRecurse )
  {
    memset(&dirList, 0, sizeof(dirList));
    RecurseFileTree_r(pDirPath: dirPath, depth: 0, &dirList);
    i = 0;
    if ( dirList.m_Size > 0 )
    {
      bRecurseb = 0;
      do
      {
        CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
        m_nGrowSize = tempList.m_Memory.m_nGrowSize;
        m_pMemory = tempList.m_Memory.m_pMemory;
        if ( tempList.m_Memory.m_nGrowSize >= 0 )
        {
          if ( tempList.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
            m_pMemory = nullptr;
            tempList.m_Memory.m_pMemory = nullptr;
          }
          tempList.m_Memory.m_nAllocationCount = 0;
        }
        if ( tempList.m_Memory.m_nAllocationCount < dirList.m_Size && m_nGrowSize >= 0 )
        {
          tempList.m_Memory.m_nAllocationCount = dirList.m_Size;
          v28 = 24 * dirList.m_Size;
          if ( m_pMemory != nullptr )
            m_pMemory = (fileList_t *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: v28);
          else
            m_pMemory = (fileList_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v28);
          tempList.m_Memory.m_pMemory = m_pMemory;
        }
        tempList.m_pElements = m_pMemory;
        v17 = CUtlString::operator char const *(this: &dirList.m_Memory.m_pMemory[bRecurseb]);
        GetFileList(
          pDirPath: v17,
          pPattern: pattern,
          fileList: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
        v18 = fileList;
        m_Size = tempList.m_Size;
        inserted = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
                     this: fileList,
                     elem: fileList->m_Size,
                     num: tempList.m_Size);
        if ( m_Size > 0 )
        {
          v21 = tempList.m_Memory.m_pMemory;
          v22 = inserted;
          pFileMaska = (const char *)tempList.m_Size;
          while ( 1 )
          {
            p_fileName = &v18->m_Memory.m_pMemory[v22].fileName;
            CUtlString::operator=(this: p_fileName, src: &v21->fileName);
            p_fileName[1].m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)v21->timeWrite;
            timeWrite_high = HIDWORD(v21->timeWrite);
            ++v21;
            ++v22;
            v14 = pFileMaska-- == (const char *)1;
            p_fileName[1].m_Storage.m_Memory.m_nAllocationCount = timeWrite_high;
            if ( v14 )
              break;
            v18 = fileList;
          }
        }
        ++bRecurseb;
        ++i;
      }
      while ( i < dirList.m_Size );
    }
    CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&dirList);
    v25 = dirList.m_Memory.m_pMemory;
    if ( dirList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( dirList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: dirList.m_Memory.m_pMemory);
        v25 = nullptr;
        dirList.m_Memory.m_pMemory = nullptr;
      }
      dirList.m_Memory.m_nAllocationCount = 0;
    }
    dirList.m_pElements = v25;
    if ( dirList.m_Memory.m_nGrowSize >= 0 && v25 != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v25);
  }
  else
  {
    GetFileList(
      pDirPath: dirPath,
      pPattern: pattern,
      fileList: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
    v8 = tempList.m_Size;
    v9 = CUtlVector<fileList_t,CUtlMemory<fileList_t,int>>::InsertMultipleBefore(
           this: fileList,
           elem: fileList->m_Size,
           num: tempList.m_Size);
    if ( v8 > 0 )
    {
      v10 = tempList.m_Memory.m_pMemory;
      v11 = v9;
      bRecursea = v8;
      do
      {
        v12 = &fileList->m_Memory.m_pMemory[v11];
        CUtlString::operator=(this: &v12->fileName, src: &v10->fileName);
        LODWORD(v12->timeWrite) = v10->timeWrite;
        v13 = HIDWORD(v10->timeWrite);
        ++v10;
        ++v11;
        v14 = bRecursea-- == 1;
        HIDWORD(v12->timeWrite) = v13;
      }
      while ( !v14 );
    }
  }
  v26 = fileList->m_Size;
  CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&tempList);
  if ( tempList.m_Memory.m_nGrowSize >= 0 && tempList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tempList.m_Memory.m_pMemory);
  return v26;
}

//------------------------------------------------------------------------------
// Address: 0x00404C10
// Name: int FindFilesFromScript(char const __near *,class CUtlVector<struct fileList_t,class CUtlMemory<struct fileList_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl FindFilesFromScript(const char *pFileScript, CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *fileList)
{
  bool v2; // al
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > *v3; // edi
  int v4; // esi
  const char *v5; // eax
  int m_Size; // edi
  bool v8; // [esp-8h] [ebp-280h]
  characterset_t breakSet; // [esp+8h] [ebp-270h] BYREF
  char szToken[260]; // [esp+108h] [ebp-170h] BYREF
  CUtlSymbolTable symbolTable; // [esp+20Ch] [ebp-6Ch] BYREF
  CUtlBuffer buffer; // [esp+244h] [ebp-34h] BYREF
  CUtlSymbol v13; // [esp+276h] [ebp-2h] BYREF

  CUtlSymbolTable::CUtlSymbolTable(this: &symbolTable, growSize: 0, initSize: 32, caseInsensitive: true);
  CharacterSetBuild(pSetBuffer: &breakSet, pszSetString: pDefaultValue);
  CUtlBuffer::CUtlBuffer(this: &buffer, growSize: 0, initSize: 0, nFlags: 0);
  v2 = ReadFileToBuffer(pSourceName: pFileScript, &buffer, bText: true, bNoOpenFailureWarning: true);
  v3 = fileList;
  if ( v2 )
  {
    while ( CUtlBuffer::ParseToken(
              this: &buffer,
              pBreaks: &breakSet,
              pTokenBuf: szToken,
              nMaxLen: 260,
              bParseComments: true) > 0 )
    {
      V_FixSlashes(pname: szToken, separator: 92);
      if ( CUtlSymbolTable::Find(this: &symbolTable, result: (CUtlSymbol *)&fileList + 1, pString: szToken)->m_Id == 0xFFFF )
        CUtlSymbolTable::AddString(this: &symbolTable, result: &v13, pString: szToken);
    }
    v4 = 0;
    if ( symbolTable.m_Lookup.m_NumElements != 0 )
    {
      do
      {
        v8 = !g_bDvdDevMode;
        v5 = CUtlSymbolTable::String(this: &symbolTable, id: (CUtlSymbol)v4);
        FindFiles(pFileMask: v5, bRecurse: v8, fileList: v3);
        ++v4;
      }
      while ( v4 < symbolTable.m_Lookup.m_NumElements );
    }
  }
  m_Size = v3->m_Size;
  if ( buffer.m_Memory.m_nGrowSize >= 0 )
  {
    if ( buffer.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buffer.m_Memory.m_pMemory);
      buffer.m_Memory.m_pMemory = nullptr;
    }
    buffer.m_Memory.m_nAllocationCount = 0;
  }
  CUtlSymbolTable::~CUtlSymbolTable(this: &symbolTable);
  return m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00404D70
// Name: void DeleteTemporaryFiles(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeleteTemporaryFiles(const char *pFileMask)
{
  char *v1; // eax
  char *v2; // edx
  char v3; // cl
  unsigned int v4; // eax
  char *v5; // edi
  char v6; // cl
  int m_Size; // edi
  fileList_t *m_pMemory; // esi
  const char *v9; // eax
  char v10; // [esp+3h] [ebp-119h] BYREF
  char tempPath[260]; // [esp+4h] [ebp-118h] BYREF
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+108h] [ebp-14h] BYREF

  v1 = getenv(option: "temp");
  if ( v1 != nullptr || (v1 = getenv(option: "tmp")) != nullptr )
  {
    v2 = (char *)(tempPath - v1);
    do
    {
      v3 = *v1;
      v1[(_DWORD)v2] = *v1;
      ++v1;
    }
    while ( v3 != 0 );
    V_AppendSlash(pStr: tempPath, strSize: 260);
    v4 = strlen(pFileMask) + 1;
    v5 = &v10;
    do
      v6 = *++v5;
    while ( v6 != 0 );
    qmemcpy(v5, pFileMask, v4);
    memset(&fileList, 0, sizeof(fileList));
    FindFiles(pFileMask: tempPath, bRecurse: false, &fileList);
    m_Size = fileList.m_Size;
    if ( fileList.m_Size > 0 )
    {
      m_pMemory = fileList.m_Memory.m_pMemory;
      do
      {
        v9 = CUtlString::operator char const *(this: &m_pMemory->fileName);
        _unlink(path: v9);
        ++m_pMemory;
        --m_Size;
      }
      while ( m_Size != 0 );
    }
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::RemoveAll(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    if ( fileList.m_Memory.m_nGrowSize >= 0 && fileList.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: fileList.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404E80
// Name: public: virtual int MakeGameDataApp::Main(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall MakeGameDataApp::Main(MakeGameDataApp *this)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  char *v9; // edx
  char v10; // cl
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // eax
  int v35; // eax
  int v36; // eax
  const char *v37; // eax
  const char *v38; // eax
  int v39; // eax
  int v40; // esi
  int v41; // eax
  int v42; // eax
  char *v43; // edx
  char v44; // cl
  int v45; // eax
  int v46; // esi
  int v47; // eax
  int v48; // eax
  char *v49; // edx
  char v50; // cl
  int v51; // eax
  int v52; // esi
  int v53; // eax
  int v54; // eax
  char *v55; // edx
  char v56; // cl
  int v57; // eax
  int v58; // esi
  int v59; // eax
  int v60; // eax
  char v61; // cl
  int v62; // eax
  int v63; // esi
  int v64; // eax
  int v65; // eax
  char *v66; // edx
  char v67; // cl
  int v68; // eax
  char *v70; // eax
  CUtlVector<fileList_t,CUtlMemory<fileList_t,int> > fileList; // [esp+Ch] [ebp-1Ch] BYREF
  BOOL bRecurse; // [esp+23h] [ebp-5h]
  bool bHasFileMask; // [esp+27h] [ebp-1h]

  memset(&fileList, 0, sizeof(fileList));
  _Msg(a1: "\nMAKEGAMEDATA - Valve Game Data Compiler (Build: %s %s)\n", "Jul 15 2011", "03:47:37");
  _Msg(a1: "(C) Valve Corporation, All rights reserved.\n\n");
  v1 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-v") != 0 )
    goto lExit;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-version") != 0 )
    goto lExit;
  v3 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v3 + 36))(a1: v3) < 2
    || (v4 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "?") != 0)
    || (v5 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-h") != 0)
    || (v6 = _CommandLine(), (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-help") != 0) )
  {
    Usage();
  }
  bHasFileMask = false;
  v7 = _CommandLine();
  v8 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v7 + 44))(a1: v7, a2: 1);
  if ( *(_BYTE *)v8 == 45 )
  {
    strcpy(g_szSourcePath, "*.*");
  }
  else
  {
    v9 = &g_szSourcePath[-v8];
    do
    {
      v10 = *(_BYTE *)v8;
      v9[v8] = *(_BYTE *)v8;
      ++v8;
    }
    while ( v10 != 0 );
    bHasFileMask = true;
  }
  v11 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-recurse") != 0
    || (v12 = _CommandLine(),
        v13 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v12 + 40))(a1: v12, a2: "-r"),
        LOBYTE(bRecurse) = 0,
        v13 != 0) )
  {
    LOBYTE(bRecurse) = 1;
  }
  v14 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v14 + 40))(a1: v14, a2: "-force") != 0
    || (v15 = _CommandLine(),
        v16 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v15 + 40))(a1: v15, a2: "-f"),
        g_bForce = false,
        v16 != 0) )
  {
    g_bForce = true;
  }
  v17 = _CommandLine();
  g_bTest = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v17 + 40))(a1: v17, a2: "-test") != 0;
  v18 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v18 + 40))(a1: v18, a2: "-quiet") != 0
    || (v19 = _CommandLine(),
        v20 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v19 + 40))(a1: v19, a2: "-q"),
        g_bQuiet = false,
        v20 != 0) )
  {
    g_bQuiet = true;
  }
  v21 = _CommandLine();
  g_bMakeScenes = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v21 + 40))(a1: v21, a2: "-scenes") != 0;
  v22 = _CommandLine();
  g_bMakeScenesPC = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v22 + 40))(a1: v22, a2: "-pcscenes") != 0;
  v23 = _CommandLine();
  g_bUseMapList = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v23 + 40))(a1: v23, a2: "-usemaplist") != 0;
  v24 = _CommandLine();
  g_bCompatibleZipFormat = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v24 + 40))(a1: v24, a2: "-zipformat") != 0;
  v25 = _CommandLine();
  g_bTexturesOnly = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v25 + 40))(a1: v25, a2: "-texturesonly") != 0;
  v26 = _CommandLine();
  g_bNoTextures = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v26 + 40))(a1: v26, a2: "-notextures") != 0;
  v27 = _CommandLine();
  g_bAudioOnly = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v27 + 40))(a1: v27, a2: "-audioonly") != 0;
  v28 = _CommandLine();
  g_bNoAudio = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v28 + 40))(a1: v28, a2: "-noaudio") != 0;
  v29 = _CommandLine();
  g_bMakeAudioCachePC = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v29 + 40))(a1: v29, a2: "-audiocache") != 0;
  v30 = _CommandLine();
  g_bUpdateAudioCachePC = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v30 + 40))(
                            a1: v30,
                            a2: "-updateaudiocache") != 0;
  v31 = _CommandLine();
  g_bDvdDevMode = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v31 + 40))(a1: v31, a2: "-dvddev") != 0;
  v32 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v32 + 40))(a1: v32, a2: "-ps3") != 0
    || (v33 = _CommandLine(),
        v34 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v33 + 40))(a1: v33, a2: "-sonyps3"),
        g_bSonyPS3 = false,
        v34 != 0) )
  {
    g_bSonyPS3 = true;
  }
  v35 = _CommandLine();
  v36 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v35 + 40))(a1: v35, a2: "-cert");
  g_bIsCert = v36 != 0;
  if ( v36 == 0 )
  {
    v37 = getenv(option: "VPC_AUTO_ARGS");
    if ( v37 != nullptr )
      g_bIsCert |= V_stristr(pStr: v37, pSearch: "cert") != nullptr;
    v38 = getenv(option: "VPC_CONSOLE_ARGS");
    if ( v38 != nullptr )
      g_bIsCert |= V_stristr(pStr: v38, pSearch: "cert") != nullptr;
  }
  if ( g_bTexturesOnly )
  {
    if ( g_bAudioOnly )
    {
      _Warning(a1: "ERROR: Cannot specify both -texturesonly and -audioonly at the same time!");
      exit(code: 1);
    }
    g_bNoAudio = true;
  }
  else if ( g_bAudioOnly )
  {
    g_bNoTextures = true;
  }
  s_MGDLoggingListener.m_bQuietPrintf = g_bQuiet;
  v39 = _CommandLine();
  v40 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v39 + 40))(a1: v39, a2: "-files");
  if ( v40 != 0 )
  {
    v41 = _CommandLine();
    v42 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v41 + 44))(a1: v41, a2: v40 + 1);
    v43 = &g_szFileScript[-v42];
    do
    {
      v44 = *(_BYTE *)v42;
      v43[v42] = *(_BYTE *)v42;
      ++v42;
    }
    while ( v44 != 0 );
  }
  v45 = _CommandLine();
  v46 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v45 + 40))(a1: v45, a2: "-excludefiles");
  if ( v46 != 0 )
  {
    v47 = _CommandLine();
    v48 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v47 + 44))(a1: v47, a2: v46 + 1);
    v49 = &g_szExcludeFileScript[-v48];
    do
    {
      v50 = *(_BYTE *)v48;
      v49[v48] = *(_BYTE *)v48;
      ++v48;
    }
    while ( v50 != 0 );
  }
  v51 = _CommandLine();
  v52 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v51 + 40))(a1: v51, a2: "-log");
  if ( v52 != 0 )
  {
    v53 = _CommandLine();
    v54 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v53 + 44))(a1: v53, a2: v52 + 1);
    v55 = &g_szLogName[-v54];
    do
    {
      v56 = *(_BYTE *)v54;
      v55[v54] = *(_BYTE *)v54;
      ++v54;
    }
    while ( v56 != 0 );
  }
  g_WriteModeForConversions = WRITE_TO_DISK_ALWAYS;
  v57 = _CommandLine();
  v58 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v57 + 40))(a1: v57, a2: "-z");
  if ( v58 != 0 )
  {
    if ( !bHasFileMask )
      strcpy(g_szSourcePath, "*.*");
    g_bMakeZip = true;
    LOBYTE(bRecurse) = 1;
    if ( !g_bMakeScenes )
      g_bMakeScenes = g_szFileScript[0] == 0;
  }
  else if ( !g_bMakeZip )
  {
LABEL_51:
    v60 = 0;
    do
    {
      v61 = g_szSourcePath[v60];
      g_targetPath[v60++] = v61;
    }
    while ( v61 != 0 );
    V_StripFilename(path: g_targetPath);
    if ( g_targetPath[0] == 0 )
      strcpy(g_targetPath, ".");
    v62 = _CommandLine();
    v63 = (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v62 + 40))(a1: v62, a2: "-t");
    if ( v63 != 0 )
    {
      v64 = _CommandLine();
      v65 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v64 + 44))(a1: v64, a2: v63 + 1);
      v66 = &g_targetPath[-v65];
      do
      {
        v67 = *(_BYTE *)v65;
        v66[v65] = *(_BYTE *)v65;
        ++v65;
      }
      while ( v67 != 0 );
    }
    V_AppendSlash(pStr: g_targetPath, strSize: 260);
    v68 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v68 + 40))(a1: v68, a2: "-preloadinfo") != 0 )
    {
      CXZipTool::SpewPreloadInfo(this: &g_MasterXZip, pZipName: g_szSourcePath);
      goto lExit;
    }
    if ( SetupFileSystem() == 0 )
    {
      _Warning(a1: "ERROR: Failed to setup file system.\n");
      exit(code: 1);
    }
    g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
    g_pDataModel->OnlyCreateUntypedElements(this: g_pDataModel, a2: true);
    g_pDataModel->SetDefaultElementFactory(this: g_pDataModel, a2: nullptr);
    if ( !g_bMakeZip
      || (v70 = V_stristr(pStr: g_szModPath, pSearch: "\\platform"), g_bIsPlatformZip = true, v70 == nullptr) )
    {
      g_bIsPlatformZip = false;
    }
    g_bIsUpdateZip = g_bMakeZip
                  && (V_stristr(pStr: g_szModPath, pSearch: "\\update") != nullptr
                   || V_stristr(pStr: g_szModPath, pSearch: "\\xlsppatch") != nullptr);
    DeleteTemporaryFiles(pFileMask: "mgd_*.tmp");
    if ( g_bMakeZip || g_bUseMapList )
      BuildValidMapList(mapList: &g_ValidMapList);
    if ( !g_bSonyPS3 )
      BuildPWLTextureList();
    BuildAllow1024TextureList();
    if ( g_szFileScript[0] != 0 )
    {
      FindFilesFromScript(pFileScript: g_szFileScript, &fileList);
      goto LABEL_81;
    }
    if ( bHasFileMask || g_bMakeZip )
    {
      FindFiles(pFileMask: g_szSourcePath, bRecurse, &fileList);
LABEL_81:
      if ( g_bMakeZip )
        BuildExcludeFileList();
    }
    ExcludeFiles(pExcludeScript: (int)g_szExcludeFileScript, &fileList);
    if ( (g_bTexturesOnly || g_bAudioOnly || PreprocessModelFiles(&fileList)) && GenerateTargetFiles(&fileList) == 0 )
      exit(code: 1);
lExit:
    CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>::~CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int>>(this: (CUtlVector<CEventRelativeTag,CUtlMemory<CEventRelativeTag,int> > *)&fileList);
    return 0;
  }
  v59 = _CommandLine();
  strcat(g_zipPath, (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v59 + 44))(a1: v59, a2: v58 + 1));
  goto LABEL_51;
}

//------------------------------------------------------------------------------
// Address: 0x00419840
// Name: public: CUtlString::~CUtlString(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlString::~CUtlString(CUtlString *this)
{
  bool v2; // sf

  v2 = this->m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Storage.m_Memory.m_pMemory);
      this->m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B870
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x0041B890
// Name: __recalloc_crt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl _recalloc_crt(void *ptr, unsigned int count, unsigned int size)
{
  unsigned __int8 *v3; // edi

  v3 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: ptr, a3: size * count);
  memset(dst: v3, value: 0, count: size * count);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0041B8D0
// Name: __msize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _msize(void *pMem)
{
  return _g_pMemAlloc->GetSize(this: _g_pMemAlloc, a2: pMem);
}

//------------------------------------------------------------------------------
// Address: 0x0041B8F0
// Name: __heap_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _heap_init()
{
  return _g_pMemAlloc != nullptr;
}
