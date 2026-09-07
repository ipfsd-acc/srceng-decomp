// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/classcheck/classcheck.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004054C0
// Name: void printusage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn printusage()
{
  _Msg(
    a1: "usage:  classcheck -q -h -m -t -v [vcproj file] <root source directory> <game:  hl2 | tf2>\n"
    "\t-q = quiet\n"
    "\t-h = print class hierarchy\n"
    "\t-m = don't print member functions/variables of class\n"
    "\t-t = don't print type description errors\n"
    "\t-p = don't print prediction description errors\n"
    "\t-c = create missing save descriptions\n"
    "\t-x = create missing prediction descriptions\n"
    "\t-i = specify specific input file to parse\n"
    "\t-b = similar to -i, allows specifying files outside client\\server directories\n"
    "\t-j = check for Crazy Jay Stelly's mismatched Hungarian notation errors\n"
    "\t-v = get file list from a .vcproj file\n"
    "\t-l = log to file log.txt\n"
    "\n"
    "Ex: classcheck -v c:\\main\\src\\game\\server\\server_episodic.vcproj\n");
  exit(code: 1);
}

//------------------------------------------------------------------------------
// Address: 0x004054E0
// Name: void ProcessDirectory(char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessDirectory(
        const char *game,
        const char *sourcetreebase,
        const char *subdir,
        const char *baseentityclass)
{
  char rootdirectory[256]; // [esp+8h] [ebp-100h] BYREF

  sprintf(string: rootdirectory, format: "%s\\%s", sourcetreebase, subdir);
  if ( COM_DirectoryExists(dir: rootdirectory) )
    processor->Process_2(this: processor, a2: baseentityclass, a3: game, a4: sourcetreebase, a5: subdir);
  else
    vprint(depth: 0, fmt: "Couldn't find directory %s, check path %s\n", rootdirectory, sourcetreebase);
}

//------------------------------------------------------------------------------
// Address: 0x00405560
// Name: void ProcessFile(char const __near *,char const __near *,char const __near *,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessFile(
        const char *game,
        const char *sourcetreebase,
        const char *subdir,
        const char *baseentityclass,
        const char *pFileName)
{
  char rootdirectory[256]; // [esp+8h] [ebp-100h] BYREF

  sprintf(string: rootdirectory, format: "%s\\%s", sourcetreebase, subdir);
  if ( COM_DirectoryExists(dir: rootdirectory) )
    processor->Process(this: processor, a2: baseentityclass, a3: game, a4: sourcetreebase, a5: subdir, a6: pFileName);
  else
    vprint(depth: 0, fmt: "Couldn't find directory %s, check path %s\n", rootdirectory, sourcetreebase);
}

//------------------------------------------------------------------------------
// Address: 0x004055E0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int v3; // esi
  const char *v4; // eax
  char *v5; // eax
  char *v6; // edx
  char v7; // cl
  char *v9; // ebx
  char sourcetreebase[256]; // [esp+Ch] [ebp-10Ch] BYREF
  char *pVCProjFile; // [esp+10Ch] [ebp-Ch]
  char *pSpecificFile; // [esp+110h] [ebp-8h]
  bool bOutsideGamedir; // [esp+117h] [ebp-1h]

  InstallSpewFunction();
  vprint(depth: 0, fmt: "Valve Software - classcheck.exe (%s)\n", "Dec 28 2010");
  vprint(depth: 0, fmt: "--- Game Code Static Analysis ---\n");
  pSpecificFile = nullptr;
  pVCProjFile = nullptr;
  v3 = 1;
  for ( bOutsideGamedir = false; v3 < argc; ++v3 )
  {
    v4 = argv[v3];
    if ( *v4 == 45 )
    {
      switch ( v4[1] )
      {
        case 'b':
          if ( v3 < argc - 1 )
          {
            pSpecificFile = (char *)argv[v3 + 1];
            bOutsideGamedir = true;
            ++v3;
          }
          continue;
        case 'c':
          processor->SetPrintCreateMissingTDs(this: processor, a2: true);
          continue;
        case 'h':
          processor->SetPrintHierarchy(this: processor, a2: true);
          continue;
        case 'i':
          if ( v3 < argc - 1 )
            pSpecificFile = (char *)argv[++v3];
          continue;
        case 'j':
          goto $LN11_0;
        case 'l':
          processor->SetLogFile(this: processor, a2: true);
          continue;
        case 'm':
          processor->SetPrintMembers(this: processor, a2: false);
          continue;
        case 'p':
          processor->SetPrintPredTDs(this: processor, a2: false);
          continue;
        case 'q':
          processor->SetQuiet(this: processor, a2: true);
          continue;
        case 't':
          processor->SetPrintTDs(this: processor, a2: false);
          continue;
        case 'v':
          if ( v3 < argc - 1 )
            pVCProjFile = (char *)argv[++v3];
$LN11_0:
          processor->SetCheckHungarian(this: processor, a2: true);
          continue;
        case 'x':
          processor->SetPrintCreateMissingPredTDs(this: processor, a2: true);
          continue;
        default:
          goto LABEL_28;
      }
    }
  }
  if ( argc < 3 || v3 != argc )
LABEL_28:
    printusage();
  if ( processor->GetLogFile(this: processor) )
  {
    _unlink(path: "log.txt");
    vprint(depth: 0, fmt: "    Outputting to log.txt\n");
  }
  vprint(depth: 0, fmt: "    Looking for obvious screwups and boneheaded mistakes...\n");
  v5 = (char *)argv[v3 - 2];
  v6 = (char *)(sourcetreebase - v5);
  do
  {
    v7 = *v5;
    v5[(_DWORD)v6] = *v5;
    ++v5;
  }
  while ( v7 != 0 );
  V_StripTrailingSlash(ppath: sourcetreebase);
  if ( pVCProjFile != nullptr )
  {
    processor->ProcessVCProj(this: processor, a2: pVCProjFile);
    return 0;
  }
  else
  {
    v9 = pSpecificFile;
    if ( pSpecificFile != nullptr )
    {
      if ( bOutsideGamedir )
      {
        ProcessFile(
          game: argv[v3 - 1],
          sourcetreebase,
          subdir: definetype,
          baseentityclass: definetype,
          pFileName: pSpecificFile);
      }
      else
      {
        ProcessFile(
          game: argv[v3 - 1],
          sourcetreebase,
          subdir: "server",
          baseentityclass: "CBaseEntity",
          pFileName: pSpecificFile);
        ProcessFile(
          game: argv[v3 - 1],
          sourcetreebase,
          subdir: "client",
          baseentityclass: "C_BaseEntity",
          pFileName: v9);
      }
      return 0;
    }
    else
    {
      ProcessDirectory(game: argv[v3 - 1], sourcetreebase, subdir: "server", baseentityclass: "CBaseEntity");
      ProcessDirectory(game: argv[v3 - 1], sourcetreebase, subdir: "client", baseentityclass: "C_BaseEntity");
      return 0;
    }
  }
}
