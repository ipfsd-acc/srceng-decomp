// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vice/vice.cpp
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00403630
// Name: Exit
// Source: json
//------------------------------------------------------------------------------
void __usercall __noreturn Exit(const char *msg@<eax>)
{
  _iobuf *v1; // eax

  v1 = __iob_func();
  fprintf(str: v1 + 2, format: msg);
  if ( !g_NoPause )
  {
    printf(format: "Hit a key to continue\n");
    getch();
  }
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00403670
// Name: Usage
// Source: json
//------------------------------------------------------------------------------
void __noreturn Usage()
{
  _iobuf *v0; // eax
  _iobuf *v1; // eax
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v0 = __iob_func();
  fprintf(
    str: v0 + 2,
    format: "Usage: vice [-quiet] [-nopause] [-encrypt key] [-decrypt key] [-newext name] file file2 . . .\n");
  v1 = __iob_func();
  fprintf(str: v1 + 2, format: "-quiet   : don't print anything out, don't pause for input\n");
  v2 = __iob_func();
  fprintf(str: v2 + 2, format: "-nopause : don't pause for input\n");
  v3 = __iob_func();
  fprintf(str: v3 + 2, format: "-encrypt : encrypt files with given key\n");
  v4 = __iob_func();
  fprintf(str: v4 + 2, format: "-decrypt : decypt files with given key\n");
  v5 = __iob_func();
  fprintf(str: v5 + 2, format: "-newext  : new output file extension\n");
  if ( !g_NoPause )
  {
    printf(format: "Hit a key to continue\n");
    getch();
  }
  exit(code: -1);
}

//------------------------------------------------------------------------------
// Address: 0x00403720
// Name: bool Process_File(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Process_File(char *pInputBaseName, int maxlen)
{
  void *v2; // edi
  int v3; // esi
  void *v4; // esp
  unsigned __int8 *v5; // ebx
  signed int v6; // edi
  void *v7; // esp
  unsigned __int8 *v8; // eax
  void *v9; // edi
  _BYTE v11[12]; // [esp+0h] [ebp-24h] BYREF
  IceKey ice; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int8 *temp; // [esp+18h] [ebp-Ch]
  int bytesLeft; // [esp+1Ch] [ebp-8h]
  unsigned __int8 *p2; // [esp+20h] [ebp-4h]

  V_FixSlashes(pname: pInputBaseName, separator: 47);
  if ( !g_Quiet )
    printf(format: "input file: %s\n", pInputBaseName);
  v2 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pInputBaseName, a3: "rb", a4: "vice");
  if ( v2 == nullptr )
    _Error(a1: "Could not open input file");
  v3 = g_pFullFileSystem->Size_2(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
  v4 = alloca(v3);
  v5 = v11;
  g_pFullFileSystem->Read(this: &g_pFullFileSystem->IBaseFileSystem, a2: v11, a3: v3, a4: v2);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v2);
  IceKey::IceKey(this: &ice, n: 0);
  IceKey::set(this: &ice, key: (const unsigned __int8 *)g_ICEKey);
  v6 = IceKey::blockSize(this: &ice);
  v7 = alloca(v3);
  v8 = v11;
  temp = v11;
  p2 = v11;
  for ( bytesLeft = v3; bytesLeft >= v6; v8 = p2 )
  {
    if ( g_Encrypt )
    {
      IceKey::encrypt(this: &ice, ptext: v5, ctext: v8);
    }
    else if ( g_Decrypt )
    {
      IceKey::decrypt(this: &ice, ctext: v5, ptext: v8);
    }
    else
    {
      memcpy(dst: v8, src: v5, count: v6);
    }
    p2 += v6;
    v5 += v6;
    bytesLeft -= v6;
  }
  memcpy(dst: v8, src: v5, count: bytesLeft);
  V_SetExtension(path: pInputBaseName, extension: g_Extension, pathStringLength: maxlen);
  if ( !g_Quiet )
    printf(format: "output file: %s\n", pInputBaseName);
  v9 = g_pFullFileSystem->Open(this: &g_pFullFileSystem->IBaseFileSystem, a2: pInputBaseName, a3: "wb", a4: "vice");
  if ( v9 == nullptr )
    Exit(msg: "Could not open output file");
  g_pFullFileSystem->Write(this: &g_pFullFileSystem->IBaseFileSystem, a2: temp, a3: v3, a4: v9);
  g_pFullFileSystem->Close(this: &g_pFullFileSystem->IBaseFileSystem, a2: v9);
  IceKey::~IceKey(this: &ice);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004038E0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  void (__thiscall ***v3)(_DWORD, int, const char **); // eax
  const char **v4; // edi
  int v5; // esi
  const char *v6; // edx
  const char *v7; // edx
  char *v8; // edi
  int v9; // ebx
  int v10; // eax
  HANDLE FirstFileA; // edi
  char ext[256]; // [esp+Ch] [ebp-448h] BYREF
  char search[260]; // [esp+10Ch] [ebp-348h] BYREF
  _WIN32_FIND_DATAA wfd; // [esp+210h] [ebp-244h] BYREF
  char fname[260]; // [esp+350h] [ebp-104h] BYREF

  v3 = (void (__thiscall ***)(_DWORD, int, const char **))_CommandLine();
  v4 = argv;
  (**v3)(a1: v3, a2: argc, a3: argv);
  if ( argc < 2 )
    Usage();
  v5 = 1;
  strcpy(g_Extension, ".dat");
  while ( 1 )
  {
    if ( _V_stricmp(s1: argv[v5], s2: "-quiet") == 0 )
    {
      ++v5;
      g_Quiet = true;
      g_NoPause = true;
    }
    if ( _V_stricmp(s1: argv[v5], s2: "-nopause") == 0 )
    {
      ++v5;
      g_NoPause = true;
    }
    if ( _V_stricmp(s1: argv[v5], s2: "-encrypt") == 0 )
    {
      v6 = argv[v5 + 1];
      g_Encrypt = true;
      if ( strlen(v6) != 8 )
        goto LABEL_18;
      V_strncpy(pDest: g_ICEKey, pSrc: v6, maxLen: 16);
      v5 += 2;
    }
    if ( _V_stricmp(s1: argv[v5], s2: "-decrypt") == 0 )
    {
      v7 = argv[v5 + 1];
      g_Decrypt = true;
      if ( strlen(v7) != 8 )
LABEL_18:
        Exit(msg: "Error - ICE key must be a 8 char text.\n");
      V_strncpy(pDest: g_ICEKey, pSrc: v7, maxLen: 16);
      v5 += 2;
    }
    if ( _V_stricmp(s1: argv[v5], s2: "-newext") != 0 )
      break;
    if ( strlen(argv[v5 + 1]) > 5 )
      Exit(msg: "Error - extension must be smaller than 4 chars.\n");
    V_strncpy(pDest: g_Extension, pSrc: argv[v5 + 1], maxLen: 16);
    v5 += 2;
    if ( v5 >= argc )
      goto LABEL_21;
  }
  if ( v5 >= argc )
LABEL_21:
    Exit(msg: "Error - missing files in commandline.\n");
  CmdLib_InitFileSystem(pFilename: argv[v5], maxMemoryUsage: 0);
  g_pFullFileSystem->GetCurrentDirectoryA(this: g_pFullFileSystem, a2: gamedir, a3: 1024);
  g_pFullFileSystem->AddSearchPath(this: g_pFullFileSystem, a2: gamedir, a3: "vice", a4: PATH_ADD_TO_TAIL);
  V_FixSlashes(pname: gamedir, separator: 47);
  while ( 1 )
  {
    v8 = (char *)v4[v5];
    v9 = _V_strlen(str: v8) + 1;
    strstr(str1: (unsigned __int8 *)v8, str2: "*.");
    if ( v10 != 0 )
    {
      _splitpath(path: v8, drive: nullptr, dir: nullptr, fname, ext);
      wfd.cAlternateFileName[strlen(fname) + 15] = 0;
      sprintf(string: search, format: "%s\\*%s", gamedir, ext);
      V_FixSlashes(pname: search, separator: 47);
      memset(dst: (unsigned __int8 *)&wfd, value: 0, count: sizeof(wfd));
      FirstFileA = FindFirstFileA(lpFileName: search, lpFindFileData: &wfd);
      if ( FirstFileA != (HANDLE)-1 )
      {
        while ( (V_strncasecmp(s1: fname, s2: wfd.cFileName, n: strlen(fname)) != 0
              || Process_File(pInputBaseName: wfd.cFileName, maxlen: 260) != 0)
             && FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &wfd) )
          ;
      }
      FindClose(hFindFile: FirstFileA);
    }
    else
    {
      Process_File(pInputBaseName: v8, maxlen: v9);
    }
    if ( ++v5 >= argc )
      break;
    v4 = argv;
  }
  if ( !g_NoPause )
  {
    printf(format: "Hit a key to continue\n");
    getch();
  }
  return 0;
}
