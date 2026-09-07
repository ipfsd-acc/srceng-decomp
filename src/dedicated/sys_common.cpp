// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/sys_common.cpp
// Functions: 9
// ============================================================

#include "dedicated\sys_common.h"

//------------------------------------------------------------------------------
// Address: 0x10003230
// Name: bool InitInstance(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl InitInstance()
{
  int v0; // eax

  v0 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(a1: v0, a2: "-usegh", a3: 0) != 0 )
    hDLLThirdParty = sys->LoadLibrary(this: sys, a2: "ghostinj.dll");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003270
// Name: void ProcessConsoleInput(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ProcessConsoleInput()
{
  const char *v0; // eax
  char szBuf[256]; // [esp+0h] [ebp-100h] BYREF

  if ( engine != nullptr )
  {
    while ( 1 )
    {
      v0 = sys->ConsoleInput(this: sys);
      if ( v0 == nullptr )
        break;
      V_snprintf(pDest: szBuf, maxLen: 256, pFormat: "%s\n", v0);
      engine->AddConsoleText(this: engine, a2: szBuf);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100032D0
// Name: void PerformCommandLineSubstitutions(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PerformCommandLineSubstitutions(int nIndex)
{
  int v1; // esi
  int v2; // eax
  int v3; // eax
  const char *v4; // eax
  char *v5; // ecx
  int v6; // eax
  int v7; // eax
  double v8; // st7
  int v9; // eax
  int v10; // eax
  char newBuf[2048]; // [esp+14h] [ebp-808h] BYREF
  int i; // [esp+814h] [ebp-8h]
  bool bWasExpression; // [esp+81Bh] [ebp-1h]

  v1 = 0;
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int))(*(_DWORD *)v2 + 36))(a1: v2) > 0 )
  {
    do
    {
      v3 = _CommandLine();
      v4 = (const char *)(*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 44))(a1: v3, a2: v1);
      V_strncpy(pDest: newBuf, pSrc: v4, maxLen: 2048);
      bWasExpression = false;
      v5 = _V_strstr(s1: newBuf, search: "##");
      if ( v5 != nullptr )
      {
        v6 = nIndex % 10;
        for ( i = nIndex % 10; ; LOBYTE(v6) = i )
        {
          v5[1] = v6 + 48;
          *v5 = nIndex / 10 + 48;
          if ( v5 != newBuf )
          {
            strchr(string: "+-/*", chr: *(v5 - 1));
            if ( v7 != 0 )
              bWasExpression = true;
          }
          v5 = _V_strstr(s1: newBuf, search: "##");
          if ( v5 == nullptr )
            break;
        }
        if ( bWasExpression )
        {
          v8 = EvaluateExpression(pExpr: newBuf, flValueToReturnIfFailure: -1.0);
          sprintf(string: newBuf, format: "%d", (int)v8);
        }
        printf(format: "setparm %d %s\n", v1, newBuf);
        v9 = _CommandLine();
        (*(void (__thiscall **)(int, int, char *))(*(_DWORD *)v9 + 48))(a1: v9, a2: v1, a3: newBuf);
      }
      ++v1;
      v10 = _CommandLine();
    }
    while ( v1 < (*(int (__thiscall **)(int))(*(_DWORD *)v10 + 36))(a1: v10) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003420
// Name: public: virtual void CDedicatedExports::RunServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedExports::RunServer(CDedicatedExports *this)
{
  PerformCommandLineSubstitutions(nIndex: 0);
  RunServer(bSupressStdIOBecauseWeAreAForkedChild: false);
}

//------------------------------------------------------------------------------
// Address: 0x10003440
// Name: public: virtual bool CDedicatedExports::IsGuiDedicatedServer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDedicatedExports::IsGuiDedicatedServer(CDedicatedExports *this)
{
  return g_bVGui;
}

//------------------------------------------------------------------------------
// Address: 0x10003460
// Name: char const __near * UTIL_GetExecutableDir(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl UTIL_GetExecutableDir()
{
  HMODULE ModuleHandleA; // eax
  char *result; // eax
  _BYTE *v2; // eax
  _BYTE *v3; // esi
  _BYTE *v4; // eax
  unsigned int v5; // kr00_4

  exedir[0] = 0;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  result = (char *)GetModuleFileNameA(hModule: ModuleHandleA, lpFilename: exedir, nSize: 0x100u);
  if ( result != nullptr )
  {
    strrchr(string: (unsigned __int8 *)exedir, chr: 0x5Cu);
    v3 = v2;
    strrchr(string: (unsigned __int8 *)exedir, chr: 0x2Fu);
    if ( v4 > v3 )
      v3 = v4;
    if ( v3 != nullptr )
      *v3 = 0;
    v5 = strlen(exedir);
    if ( byte_100F579C[v5] != 92 || byte_100F579D[v5] != 98 || byte_100F579E[v5] != 105 || byte_100F579F[v5] != 110 )
    {
      V_strncat(pDest: exedir, pSrc: "\\bin", destBufferSize: 0x104u, max_chars_to_copy: -1);
      V_FixSlashes(pname: exedir, separator: 92);
    }
    return exedir;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003510
// Name: char const __near * UTIL_GetBaseDir(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl UTIL_GetBaseDir()
{
  int v0; // eax
  char *result; // eax
  char *ExecutableDir; // eax
  char *v3; // edx
  char v4; // cl
  int v5; // eax
  char v6; // cl

  v0 = _CommandLine();
  result = (char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v0 + 12))(
                     a1: v0,
                     a2: "-basedir",
                     a3: 0);
  if ( result == nullptr )
  {
    basedir[0] = 0;
    ExecutableDir = UTIL_GetExecutableDir();
    if ( ExecutableDir != nullptr )
    {
      v3 = (char *)(basedir - ExecutableDir);
      do
      {
        v4 = *ExecutableDir;
        ExecutableDir[(_DWORD)v3] = *ExecutableDir;
        ++ExecutableDir;
      }
      while ( v4 != 0 );
      v5 = &basedir[strlen(basedir) + 1] - (char *)&unk_100F58A9;
      if ( byte_100F58A5[v5] == 98 && byte_100F58A6[v5] == 105 && byte_100F58A7[v5] == 110 )
        byte_100F58A4[v5] = v6;
    }
    return basedir;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100035A0
// Name: public: virtual void CDedicatedExports::Sys_Printf(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDedicatedExports::Sys_Printf(CDedicatedExports *this, char *text)
{
  if ( sys != nullptr )
    sys->Printf(this: sys, a2: "%s", text);
}

//------------------------------------------------------------------------------
// Address: 0x10003450
// Name: __CreateCDedicatedExportsIDedicatedExports_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDedicatedExports *__cdecl _CreateCDedicatedExportsIDedicatedExports_interface()
{
  return &_g_CDedicatedExports_singleton;
}
