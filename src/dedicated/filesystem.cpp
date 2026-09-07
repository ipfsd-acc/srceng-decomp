// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: dedicated/filesystem.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10001000
// Name: class CBaseFileSystem __near * BaseFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
CBaseFileSystem *__cdecl BaseFileSystem()
{
  return s_pBaseFileSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10001010
// Name: void __near * FileSystemFactory(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
IBaseFileSystem *__cdecl FileSystemFactory(const char *pName, int *pReturnCode)
{
  int v2; // eax

  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-steam") != 0 )
  {
    s_pBaseFileSystem = BaseFileSystem_Steam();
    if ( _V_stricmp(s1: pName, s2: "VFileSystem017") == 0 )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 0;
      return (IBaseFileSystem *)g_pFileSystemSteam;
    }
    if ( _V_stricmp(s1: pName, s2: "VBaseFileSystem011") == 0 )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 0;
      return g_pBaseFileSystemSteam;
    }
    goto LABEL_18;
  }
  s_pBaseFileSystem = BaseFileSystem_Stdio();
  if ( _V_stricmp(s1: pName, s2: "VFileSystem017") != 0 )
  {
    if ( _V_stricmp(s1: pName, s2: "VBaseFileSystem011") != 0 )
    {
LABEL_18:
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
    if ( pReturnCode != nullptr )
      *pReturnCode = 0;
    return g_pBaseFileSystem;
  }
  else
  {
    if ( pReturnCode != nullptr )
      *pReturnCode = 0;
    return (IBaseFileSystem *)g_pFileSystem;
  }
}
