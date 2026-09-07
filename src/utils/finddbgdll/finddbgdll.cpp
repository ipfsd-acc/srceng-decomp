// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/finddbgdll/finddbgdll.cpp
// Functions: 2
// ============================================================

#include "utils\finddbgdll\finddbgdll.h"

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: public: virtual enum LoggingResponse_t CNonFatalLoggingResponsePolicy::OnLog(struct LoggingContext_t const __near *)
// Source: json
//------------------------------------------------------------------------------
LoggingResponse_t __thiscall CNonFatalLoggingResponsePolicy::OnLog(
        CNonFatalLoggingResponsePolicy *this,
        const LoggingContext_t *pContext)
{
  int v2; // eax
  LoggingResponse_t result; // eax

  result = pContext->m_Severity == LS_ASSERT
        && (v2 = _CommandLine(a1: this),
            (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-noassert") == 0)
        || pContext->m_Severity == LS_ERROR;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401040
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  HANDLE FirstFileA; // esi
  HMODULE LibraryA; // esi
  _WIN32_FIND_DATAA findFileData; // [esp+4h] [ebp-148h] BYREF
  CNonFatalLoggingResponsePolicy nonFatalLoggingResponsePolicy; // [esp+144h] [ebp-8h] BYREF
  void *hFind; // [esp+148h] [ebp-4h]

  printf(format: "Valve Software - finddbgdll.exe (%s)\n", "Dec 28 2010");
  nonFatalLoggingResponsePolicy.__vftable = (CNonFatalLoggingResponsePolicy_vtbl *)&CNonFatalLoggingResponsePolicy::`vftable';
  _LoggingSystem_SetLoggingResponsePolicy(a1: &nonFatalLoggingResponsePolicy);
  FirstFileA = FindFirstFileA(lpFileName: "*.dll", lpFindFileData: &findFileData);
  hFind = FirstFileA;
  if ( FirstFileA != (HANDLE)-1 )
  {
    do
    {
      if ( _V_strstr(s1: findFileData.cFileName, search: "360") == nullptr )
      {
        LibraryA = LoadLibraryA(lpLibFileName: findFileData.cFileName);
        if ( GetProcAddress(hModule: LibraryA, lpProcName: "BuiltDebug") != nullptr )
          _Msg(a1: "Module %s is a debug build\n", findFileData.cFileName);
        FreeLibrary(hLibModule: LibraryA);
        FirstFileA = hFind;
      }
    }
    while ( FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &findFileData) );
  }
  return 0;
}
