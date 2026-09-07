// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/gamestats_reader/gamestats_reader.cpp
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: Usage
// Source: json
//------------------------------------------------------------------------------
void __noreturn Usage()
{
  _iobuf *v0; // eax

  v0 = __iob_func();
  fprintf(
    str: v0 + 2,
    format: "Usage: gamestats_reader <hostname> <database> <username> <password> <table> <directory to parse> ( -verbose )\n");
  printf(format: "Hit a key to continue\n");
  getch();
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00401030
// Name: void StartMYSQLInsert(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl StartMYSQLInsert()
{
  g_bFirstCmd = true;
  sqlCmd[0] = 0;
  V_snprintf(pDest: sqlCmd, maxLen: 16000, pFormat: "INSERT INTO %s SET ", g_argv[5]);
}

//------------------------------------------------------------------------------
// Address: 0x00401060
// Name: void AddField(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddField(const char *field, const char *value)
{
  char buf[132]; // [esp+0h] [ebp-84h] BYREF

  if ( !g_bFirstCmd )
    V_strncat(pDest: sqlCmd, pSrc: ", ", destBufferSize: 0x3E80u, max_chars_to_copy: -1);
  V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "%s=\"%s\"", field, value);
  V_strncat(pDest: sqlCmd, pSrc: &buf[4], destBufferSize: 0x3E80u, max_chars_to_copy: -1);
  g_bFirstCmd = false;
}

//------------------------------------------------------------------------------
// Address: 0x004010D0
// Name: void AddField(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddField(const char *field, int value)
{
  char buf[132]; // [esp+0h] [ebp-84h] BYREF

  if ( !g_bFirstCmd )
    V_strncat(pDest: sqlCmd, pSrc: ", ", destBufferSize: 0x3E80u, max_chars_to_copy: -1);
  V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "%s=%d", field, value);
  V_strncat(pDest: sqlCmd, pSrc: &buf[4], destBufferSize: 0x3E80u, max_chars_to_copy: -1);
  g_bFirstCmd = false;
}

//------------------------------------------------------------------------------
// Address: 0x00401140
// Name: void ParseFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ParseFile(const char *fileName)
{
  void *v1; // eax
  int v2; // eax
  int i; // esi
  __int16 *v4; // edi
  const char *v5; // ebx
  int v6; // esi
  __int16 *v7; // edi
  int v8; // ebp
  int j; // esi
  const char *v10; // edi
  int iNumAttacks; // ebx
  int iNumHits; // edi
  const char *v13; // eax
  __int16 *v14; // [esp+20h] [ebp-470h]
  int *file; // [esp+24h] [ebp-46Ch]
  char buf[128]; // [esp+28h] [ebp-468h] BYREF
  tm t; // [esp+A8h] [ebp-3E8h] BYREF
  char pDest[124]; // [esp+D0h] [ebp-3C0h] BYREF
  dod_gamestats_t stats; // [esp+14Ch] [ebp-344h] BYREF
  char filetimebuf[68]; // [esp+44Ch] [ebp-44h] BYREF

  v1 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: fileName, a3: "rb", a4: 0);
  *(_DWORD *)buf = v1;
  if ( v1 != nullptr )
  {
    g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: &stats.header.szGameName[4], a3: 768, a4: v1);
    if ( stats.header.szMapName[3] != 2 || _V_stricmp(s1: &stats.header.szGameName[4], s2: "dod") != 0 )
    {
      printf(format: "Error parsing file, bad header info: %s\n", fileName);
    }
    else
    {
      StartMYSQLInsert();
      AddField(field: "map", value: &stats.header.szMapName[4]);
      v2 = g_pFullFileSystem->GetFileTime(this: &g_pFullFileSystem->IBaseFileSystem, a2: fileName, a3: nullptr);
      _Plat_ConvertToLocalTime(a1: v2, a2: v2 >> 31, a3: &t.tm_min);
      V_snprintf(
        pDest: &filetimebuf[4],
        maxLen: 64,
        pFormat: "%04d-%02d-%02d %02d:%02d:%02d",
        t.tm_wday + 1900,
        t.tm_year + 1,
        t.tm_mon,
        t.tm_mday,
        t.tm_hour,
        t.tm_min);
      AddField(field: "time", value: &filetimebuf[4]);
      AddField(field: "version", value: (unsigned __int8)stats.header.szMapName[3]);
      AddField(field: "ipaddr_0", value: stats.header.ipAddr[4]);
      AddField(field: "ipaddr_1", value: SLOBYTE(stats.header.port));
      AddField(field: "ipaddr_2", value: SHIBYTE(stats.header.port));
      AddField(field: "ipaddr_3", value: SLOBYTE(stats.header.serverid));
      AddField(field: "port", value: SHIWORD(stats.header.serverid));
      AddField(field: "minutes_map", value: stats.iMinutesPlayedPerClass_Allies[1]);
      AddField(field: "wins_allies", value: LOBYTE(stats.iAxisTickPoints));
      AddField(field: "wins_axis", value: HIBYTE(stats.iAxisTickPoints));
      AddField(field: "tickpoints_allies", value: stats.iMinutesPlayed);
      AddField(field: "tickpoints_axis", value: stats.iMinutesPlayedPerClass_Allies[0]);
      for ( i = 0; i < 6; ++i )
      {
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "minutes_allies_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iMinutesPlayedPerClass_Allies[i + 2]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "kills_allies_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iKillsPerClass_Allies[i + 2]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "defenses_allies_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iDefensesPerClass_Allies[i + 4]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "caps_allies_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iCapsPerClass_Allies[i + 2]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "spawns_allies_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iSpawnsPerClass_Allies[i + 2]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "classlimit_allies_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iClassLimits_Allies[i + 4]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "minutes_axis_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iMinutesPlayedPerClass_Axis[i + 2]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "kills_axis_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iKillsPerClass_Axis[i + 2]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "defenses_axis_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iDefensesPerClass_Axis[i + 4]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "caps_axis_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iCapsPerClass_Axis[i + 2]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "spawns_axis_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iSpawnsPerClass_Axis[i + 2]);
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "classlimit_axis_%s", pszClassNames[i]);
        AddField(field: &buf[4], value: stats.iClassLimits_Axis[i + 4]);
      }
      v4 = &stats.weaponStatsDistance[0].iDistanceBuckets[1];
      v14 = &stats.weaponStatsDistance[0].iDistanceBuckets[1];
      file = iDistanceStatWeapons;
      while ( 1 )
      {
        v5 = s_WeaponAliasInfo[*file];
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "weapon_shots_%s", v5);
        AddField(field: &buf[4], value: *(v4 - 1));
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "weapon_hits_%s", v5);
        AddField(field: &buf[4], value: *v4);
        v6 = 0;
        v7 = v4 + 1;
        do
        {
          V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "weapon_distance_%s_%d", v5, v6);
          v8 = *v7;
          if ( !g_bFirstCmd )
            V_strncat(pDest: sqlCmd, pSrc: ", ", destBufferSize: 0x3E80u, max_chars_to_copy: -1);
          V_snprintf(pDest, maxLen: 128, pFormat: "%s=%d", &buf[4], v8);
          V_strncat(pDest: sqlCmd, pSrc: pDest, destBufferSize: 0x3E80u, max_chars_to_copy: -1);
          ++v6;
          ++v7;
          g_bFirstCmd = false;
        }
        while ( v6 < 10 );
        v14 += 12;
        if ( (int)++file >= (int)iNoDistStatWeapons )
          break;
        v4 = v14;
      }
      for ( j = 0; j < 14; ++j )
      {
        v10 = s_WeaponAliasInfo[iNoDistStatWeapons[j]];
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "weapon_shots_%s", v10);
        iNumAttacks = stats.weaponStats[j + 1].iNumAttacks;
        if ( !g_bFirstCmd )
          V_strncat(pDest: sqlCmd, pSrc: ", ", destBufferSize: 0x3E80u, max_chars_to_copy: -1);
        V_snprintf(pDest, maxLen: 128, pFormat: "%s=%d", &buf[4], iNumAttacks);
        V_strncat(pDest: sqlCmd, pSrc: pDest, destBufferSize: 0x3E80u, max_chars_to_copy: -1);
        g_bFirstCmd = false;
        V_snprintf(pDest: &buf[4], maxLen: 128, pFormat: "weapon_hits_%s", v10);
        iNumHits = stats.weaponStats[j + 1].iNumHits;
        if ( !g_bFirstCmd )
          V_strncat(pDest: sqlCmd, pSrc: ", ", destBufferSize: 0x3E80u, max_chars_to_copy: -1);
        V_snprintf(pDest, maxLen: 128, pFormat: "%s=%d", &buf[4], iNumHits);
        V_strncat(pDest: sqlCmd, pSrc: pDest, destBufferSize: 0x3E80u, max_chars_to_copy: -1);
        g_bFirstCmd = false;
      }
      V_strncat(pDest: sqlCmd, pSrc: "\n", destBufferSize: 0x3E80u, max_chars_to_copy: -1);
      if ( g_bVerbose )
        printf(format: "%s", sqlCmd);
      if ( mysql->Execute(this: mysql, a2: sqlCmd) != 0 )
      {
        v13 = mysql->GetLastError(this: mysql);
        printf(format: "Error: %s\n", v13);
      }
      g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: *(void **)buf);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401880
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // edi
  struct CSysModule *Module; // eax
  struct CSysModule *v5; // ebp
  void *(__cdecl *Factory)(const char *, int *); // eax
  IMySQL *v7; // eax
  const char *v8; // edi
  int v9; // ebx
  const char *i; // esi
  const char *v12; // eax
  int v13; // [esp+Ch] [ebp-424h]
  char fullFileName[520]; // [esp+1Ch] [ebp-414h] BYREF
  char searchString[524]; // [esp+224h] [ebp-20Ch] BYREF

  g_argv = (char **)argv;
  if ( argc < 6 )
    Usage();
  if ( argc == 7 && _V_stricmp(s1: argv[6], s2: "-verbose") == 0 )
    g_bVerbose = true;
  InitDefaultFileSystem();
  Module = Sys_LoadModule(pModuleName: "mysql_wrapper");
  v5 = Module;
  if ( Module != nullptr )
  {
    Factory = Sys_GetFactory(pModule: Module);
    if ( Factory != nullptr )
    {
      v7 = (IMySQL *)Factory(a1: "MySQLWrapper001", a2: nullptr);
      mysql = v7;
      if ( v7 != nullptr )
      {
        if ( v7->InitMySQL(this: v7, a2: argv[2], a3: argv[1], a4: argv[3], a5: argv[4]) )
        {
          v13 = v3;
          v8 = argv[6];
          V_strncpy(pDest: &searchString[4], pSrc: v8, maxLen: 520);
          V_AppendSlash(pStr: &searchString[4], strSize: 520);
          V_strncat(pDest: &searchString[4], pSrc: "*.dat", destBufferSize: 0x208u, max_chars_to_copy: -1);
          v9 = 0;
          *(_DWORD *)fullFileName = 0;
          for ( i = (const char *)((int (__thiscall *)(IFileSystem *, char *, char *, int))g_pFullFileSystem->FindFirst)(
                                    a1: g_pFullFileSystem,
                                    a2: &searchString[4],
                                    a3: fullFileName,
                                    a4: v13);
                i != nullptr;
                i = g_pFullFileSystem->FindNext(this: g_pFullFileSystem, a2: *(_DWORD *)&fullFileName[4]) )
          {
            V_strncpy(pDest: &fullFileName[8], pSrc: v8, maxLen: 520);
            V_AppendSlash(pStr: &fullFileName[8], strSize: 520);
            V_strncat(pDest: &fullFileName[8], pSrc: i, destBufferSize: 0x208u, max_chars_to_copy: -1);
            ParseFile(fileName: &fullFileName[8]);
            printf(format: "processing file: %s\n", &fullFileName[8]);
            ++v9;
          }
          g_pFullFileSystem->FindClose(this: g_pFullFileSystem, a2: *(_DWORD *)&fullFileName[4]);
          printf(format: "Completed: %d files processed from directory \"%s\"\n", v9, v8);
          mysql->Release(this: mysql);
          Sys_UnloadModule(pModule: v5);
          return 0;
        }
        else
        {
          v12 = mysql->GetLastError(this: mysql);
          printf(format: "InitMySQL failed ( %s )\n", v12);
          mysql->Release(this: mysql);
          Sys_UnloadModule(pModule: v5);
          return 0;
        }
      }
      else
      {
        printf(format: "Unable to connect via mysql_wrapper\n");
        Sys_UnloadModule(pModule: v5);
        return 0;
      }
    }
    else
    {
      printf(format: "Unable to get factory from mysql_wrapper.dll, not updating access mysql table!!!");
      Sys_UnloadModule(pModule: v5);
      return 0;
    }
  }
  else
  {
    printf(format: "Unable to load mysql_wrapper.dll, not updating access mysql table!!!");
    return 0;
  }
}
