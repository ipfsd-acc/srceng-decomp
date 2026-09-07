// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/loadcmdline.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00417510
// Name: AddArguments
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddArguments(int *argc, char ***argv, const char *str)
{
  int v3; // esi
  int v4; // eax
  char *v5; // edi
  char **v6; // ebx
  int i; // esi
  int v8; // eax
  char *v9; // eax
  const char *j; // edi
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  char *v14; // eax
  char *argList; // [esp+Ch] [ebp-8h]
  int argCt; // [esp+10h] [ebp-4h]

  v3 = *argc;
  argCt = *argc;
  v4 = _V_strlen(str);
  v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
  argList = v5;
  _V_strcpy(dest: v5, src: str);
  if ( strtok(string: v5, control: " ") != nullptr )
  {
    do
      ++v3;
    while ( strtok(string: nullptr, control: " ") != nullptr );
    argCt = v3;
  }
  if ( v3 > *argc )
  {
    sFoundConfigArgs = true;
    v6 = (char **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v3 >> 30 != 0 ? -1 : 4 * v3);
    for ( i = 0; i < *argc - 1; ++i )
    {
      v8 = _V_strlen(str: (*argv)[i]);
      v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
      v6[i] = v9;
      _V_strcpy(dest: v9, src: (*argv)[i]);
    }
    _V_strcpy(dest: v5, src: str);
    for ( j = strtok(string: v5, control: " "); i < argCt - 1; ++i )
    {
      v11 = _V_strlen(str: j);
      v12 = (char *)MemAlloc_Alloc(nSize: v11 + 1);
      v6[i] = v12;
      _V_strcpy(dest: v12, src: j);
      j = strtok(string: nullptr, control: " ");
    }
    v13 = _V_strlen(str: (*argv)[*argc - 1]);
    v14 = (char *)MemAlloc_Alloc(nSize: v13 + 1);
    v6[i] = v14;
    _V_strcpy(dest: v14, src: (*argv)[*argc - 1]);
    *argc = argCt;
    *argv = v6;
    v5 = argList;
  }
  free(pMem: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00417680
// Name: void LoadCmdLineFromFile(int __near &,char __near * __near * __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadCmdLineFromFile(int *argc, char ***argv, const char *keyname, const char *appname)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *Key; // eax
  const char *String; // edi
  char filename[512]; // [esp+0h] [ebp-200h] BYREF

  sFoundConfigArgs = false;
  if ( g_pFileSystem != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "CommandLine");
    else
      v5 = nullptr;
    filename[0] = 0;
    _V_strcpy(dest: filename, src: gamedir);
    V_StripTrailingSlash(ppath: filename);
    V_strncat(pDest: filename, pSrc: "\\cfg\\commandline.cfg", destBufferSize: 0x200u, max_chars_to_copy: -1);
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: g_pFileSystem,
           resourceName: filename,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      Key = KeyValues::FindKey(this: v5, keyName: keyname, bCreate: false);
      if ( Key != nullptr )
      {
        String = KeyValues::GetString(this: Key, keyName: appname, defaultValue: &defaultValue);
        _Msg(a1: "Command Line found: %s\n", String);
        AddArguments(argc, argv, str: String);
      }
    }
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417770
// Name: void DeleteCmdLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeleteCmdLine(int argc, char **argv)
{
  int i; // esi

  if ( sFoundConfigArgs )
  {
    for ( i = 0; i < argc; ++i )
      free(pMem: argv[i]);
    free(pMem: argv);
  }
}

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00404BD0
// Name: void DeleteCmdLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeleteCmdLine(int argc, char **argv)
{
  int i; // esi

  if ( sFoundConfigArgs )
  {
    for ( i = 0; i < argc; ++i )
      free(pMem: argv[i]);
    free(pMem: argv);
  }
}

} // namespace vbsp2

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00423470
// Name: AddArguments
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddArguments(int *argc, char ***argv, const char *str)
{
  int v3; // esi
  int v4; // eax
  char *v5; // edi
  char **v6; // ebx
  int i; // esi
  int v8; // eax
  char *v9; // eax
  const char *j; // edi
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  char *v14; // eax
  char *argList; // [esp+Ch] [ebp-8h]
  int argCt; // [esp+10h] [ebp-4h]

  v3 = *argc;
  argCt = *argc;
  v4 = _V_strlen(str);
  v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
  argList = v5;
  _V_strcpy(dest: v5, src: str);
  if ( strtok(string: v5, control: " ") != nullptr )
  {
    do
      ++v3;
    while ( strtok(string: nullptr, control: " ") != nullptr );
    argCt = v3;
  }
  if ( v3 > *argc )
  {
    sFoundConfigArgs = true;
    v6 = (char **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v3 >> 30 != 0 ? -1 : 4 * v3);
    for ( i = 0; i < *argc - 1; ++i )
    {
      v8 = _V_strlen(str: (*argv)[i]);
      v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
      v6[i] = v9;
      _V_strcpy(dest: v9, src: (*argv)[i]);
    }
    _V_strcpy(dest: v5, src: str);
    for ( j = strtok(string: v5, control: " "); i < argCt - 1; ++i )
    {
      v11 = _V_strlen(str: j);
      v12 = (char *)MemAlloc_Alloc(nSize: v11 + 1);
      v6[i] = v12;
      _V_strcpy(dest: v12, src: j);
      j = strtok(string: nullptr, control: " ");
    }
    v13 = _V_strlen(str: (*argv)[*argc - 1]);
    v14 = (char *)MemAlloc_Alloc(nSize: v13 + 1);
    v6[i] = v14;
    _V_strcpy(dest: v14, src: (*argv)[*argc - 1]);
    *argc = argCt;
    *argv = v6;
    v5 = argList;
  }
  free(pMem: v5);
}

//------------------------------------------------------------------------------
// Address: 0x004235E0
// Name: void LoadCmdLineFromFile(int __near &,char __near * __near * __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadCmdLineFromFile(int *argc, char ***argv, char *keyname, char *appname)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *Key; // eax
  char *String; // edi
  char filename[512]; // [esp+0h] [ebp-200h] BYREF

  sFoundConfigArgs = false;
  if ( g_pFileSystem != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "CommandLine");
    else
      v5 = nullptr;
    filename[0] = 0;
    _V_strcpy(dest: filename, src: gamedir);
    V_StripTrailingSlash(ppath: filename);
    V_strncat(pDest: filename, pSrc: "\\cfg\\commandline.cfg", destBufferSize: 0x200u, max_chars_to_copy: -1);
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: g_pFileSystem,
           resourceName: filename,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      Key = KeyValues::FindKey(this: v5, keyName: keyname, bCreate: false);
      if ( Key != nullptr )
      {
        String = KeyValues::GetString(this: Key, keyName: appname, defaultValue: var);
        _Msg(a1: "Command Line found: %s\n", String);
        AddArguments(argc, argv, str: String);
      }
    }
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004236D0
// Name: void DeleteCmdLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeleteCmdLine(int argc, char **argv)
{
  int i; // esi

  if ( sFoundConfigArgs )
  {
    for ( i = 0; i < argc; ++i )
      free(pMem: argv[i]);
    free(pMem: argv);
  }
}

} // namespace vmap

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10010BC0
// Name: AddArguments
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddArguments(int *argc, char ***argv, const char *str)
{
  int v3; // esi
  int v4; // eax
  char *v5; // edi
  char **v6; // ebx
  int i; // esi
  int v8; // eax
  char *v9; // eax
  const char *j; // edi
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  char *v14; // eax
  char *argList; // [esp+Ch] [ebp-8h]
  int argCt; // [esp+10h] [ebp-4h]

  v3 = *argc;
  argCt = *argc;
  v4 = _V_strlen(str);
  v5 = (char *)MemAlloc_Alloc(nSize: v4 + 1);
  argList = v5;
  _V_strcpy(dest: v5, src: str);
  if ( strtok(string: v5, control: " ") != nullptr )
  {
    do
      ++v3;
    while ( strtok(string: nullptr, control: " ") != nullptr );
    argCt = v3;
  }
  if ( v3 > *argc )
  {
    sFoundConfigArgs = true;
    v6 = (char **)MemAlloc_Alloc(nSize: (unsigned __int64)(unsigned int)v3 >> 30 != 0 ? -1 : 4 * v3);
    for ( i = 0; i < *argc - 1; ++i )
    {
      v8 = _V_strlen(str: (*argv)[i]);
      v9 = (char *)MemAlloc_Alloc(nSize: v8 + 1);
      v6[i] = v9;
      _V_strcpy(dest: v9, src: (*argv)[i]);
    }
    _V_strcpy(dest: v5, src: str);
    for ( j = strtok(string: v5, control: " "); i < argCt - 1; ++i )
    {
      v11 = _V_strlen(str: j);
      v12 = (char *)MemAlloc_Alloc(nSize: v11 + 1);
      v6[i] = v12;
      _V_strcpy(dest: v12, src: j);
      j = strtok(string: nullptr, control: " ");
    }
    v13 = _V_strlen(str: (*argv)[*argc - 1]);
    v14 = (char *)MemAlloc_Alloc(nSize: v13 + 1);
    v6[i] = v14;
    _V_strcpy(dest: v14, src: (*argv)[*argc - 1]);
    *argc = argCt;
    *argv = v6;
    v5 = argList;
  }
  free(pMem: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10010D30
// Name: void LoadCmdLineFromFile(int __near &,char __near * __near * __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadCmdLineFromFile(int *argc, char ***argv, const char *keyname, const char *appname)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *Key; // eax
  const char *String; // edi
  char filename[512]; // [esp+0h] [ebp-200h] BYREF

  sFoundConfigArgs = false;
  if ( g_pFileSystem != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "CommandLine");
    else
      v5 = nullptr;
    filename[0] = 0;
    _V_strcpy(dest: filename, src: gamedir);
    V_StripTrailingSlash(ppath: filename);
    V_strncat(pDest: filename, pSrc: "\\cfg\\commandline.cfg", destBufferSize: 0x200u, max_chars_to_copy: -1);
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: g_pFileSystem,
           resourceName: filename,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      Key = KeyValues::FindKey(this: v5, keyName: keyname, bCreate: false);
      if ( Key != nullptr )
      {
        String = KeyValues::GetString(this: Key, keyName: appname, defaultValue: defaultValue);
        _Msg(a1: "Command Line found: %s\n", String);
        AddArguments(argc, argv, str: String);
      }
    }
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010E20
// Name: void DeleteCmdLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeleteCmdLine(int argc, char **argv)
{
  int i; // esi

  if ( sFoundConfigArgs )
  {
    for ( i = 0; i < argc; ++i )
      free(pMem: argv[i]);
    free(pMem: argv);
  }
}

} // namespace vrad_dll

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1000CFE0
// Name: AddArguments
// Source: json
//------------------------------------------------------------------------------
void __cdecl AddArguments(int *argc, char ***argv, const char *str)
{
  int v3; // esi
  int v4; // eax
  char *v5; // edi
  char **v6; // ebx
  int i; // esi
  int v8; // eax
  char *v9; // eax
  const char *j; // edi
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  char *v14; // eax
  char *argList; // [esp+Ch] [ebp-8h]
  int argCt; // [esp+10h] [ebp-4h]

  v3 = *argc;
  argCt = *argc;
  v4 = _V_strlen(str);
  v5 = (char *)operator new(size: v4 + 1);
  argList = v5;
  _V_strcpy(dest: v5, src: str);
  if ( strtok(string: v5, control: " ") != nullptr )
  {
    do
      ++v3;
    while ( strtok(string: nullptr, control: " ") != nullptr );
    argCt = v3;
  }
  if ( v3 > *argc )
  {
    sFoundConfigArgs = true;
    v6 = (char **)operator new(size: 4 * v3);
    for ( i = 0; i < *argc - 1; ++i )
    {
      v8 = _V_strlen(str: (*argv)[i]);
      v9 = (char *)operator new(size: v8 + 1);
      v6[i] = v9;
      _V_strcpy(dest: v9, src: (*argv)[i]);
    }
    _V_strcpy(dest: v5, src: str);
    for ( j = strtok(string: v5, control: " "); i < argCt - 1; ++i )
    {
      v11 = _V_strlen(str: j);
      v12 = (char *)operator new(size: v11 + 1);
      v6[i] = v12;
      _V_strcpy(dest: v12, src: j);
      j = strtok(string: nullptr, control: " ");
    }
    v13 = _V_strlen(str: (*argv)[*argc - 1]);
    v14 = (char *)operator new(size: v13 + 1);
    v6[i] = v14;
    _V_strcpy(dest: v14, src: (*argv)[*argc - 1]);
    *argc = argCt;
    *argv = v6;
    v5 = argList;
  }
  operator delete(p: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1000D150
// Name: void LoadCmdLineFromFile(int __near &,char __near * __near * __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl LoadCmdLineFromFile(int *argc, char ***argv, const char *keyname, const char *appname)
{
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *Key; // eax
  const char *String; // edi
  char filename[512]; // [esp+0h] [ebp-200h] BYREF

  sFoundConfigArgs = false;
  if ( g_pFileSystem != nullptr )
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
      v5 = KeyValues::KeyValues(this: v4, setName: "CommandLine");
    else
      v5 = nullptr;
    filename[0] = 0;
    _V_strcpy(dest: filename, src: gamedir);
    V_StripTrailingSlash(ppath: filename);
    V_strncat(pDest: filename, pSrc: "\\cfg\\commandline.cfg", destBufferSize: 0x200u, max_chars_to_copy: -1);
    if ( KeyValues::LoadFromFile(
           this: v5,
           filesystem: g_pFileSystem,
           resourceName: filename,
           pathID: nullptr,
           pfnEvaluateSymbolProc: nullptr) )
    {
      Key = KeyValues::FindKey(this: v5, keyName: keyname, bCreate: false);
      if ( Key != nullptr )
      {
        String = KeyValues::GetString(this: Key, keyName: appname, defaultValue: defaultValue);
        _Msg(a1: "Command Line found: %s\n", String);
        AddArguments(argc, argv, str: String);
      }
    }
    KeyValues::deleteThis(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D240
// Name: void DeleteCmdLine(int,char __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DeleteCmdLine(int argc, char **argv)
{
  int i; // esi

  if ( sFoundConfigArgs )
  {
    for ( i = 0; i < argc; ++i )
      operator delete(p: argv[i]);
    operator delete(p: argv);
  }
}

} // namespace vvis_dll
