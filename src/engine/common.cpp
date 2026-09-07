// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/common.cpp
// Functions: 26
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10157DC0
// Name: void COM_ExplainDisconnection(bool,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void COM_ExplainDisconnection(bool bPrint, const char *fmt, ...)
{
  char *v2; // esi
  const char *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IMatchEventsSubscription *v6; // eax
  char szString[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+410h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: szString, maxLen: 1024, pFormat: fmt, params);
  V_strncpy(pDest: gszDisconnectReason, pSrc: szString, maxLen: 256);
  gfExtendedError = true;
  if ( bPrint )
    ConMsg(a1: "%s\n", gszDisconnectReason);
  v2 = szString;
  v3 = StringAfterPrefix(str: szString, prefix: "Disconnect: ");
  if ( v3 != nullptr )
    v2 = (char *)v3;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OnEngineDisconnectReason", firstKey: "reason", firstValue: v2);
  else
    v5 = nullptr;
  v6 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v6->BroadcastEvent(this: v6, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10157E80
// Name: char const __near * COM_Parse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COM_Parse(const char *data)
{
  characterset_t *v1; // edi
  const char *result; // eax
  int v3; // esi
  unsigned __int8 i; // cl
  char v5; // cl
  int v6; // edx

  v1 = &g_BreakSetIncludingColons;
  if ( com_ignorecolons )
    v1 = &g_BreakSet;
  result = data;
  v3 = 0;
  com_token[0] = 0;
  if ( data == nullptr )
    return nullptr;
  i = *data;
  while ( 1 )
  {
    if ( i <= 0x20u )
    {
      while ( i != 0 )
      {
        i = *++result;
        if ( i > 0x20u )
          goto LABEL_9;
      }
      return nullptr;
    }
LABEL_9:
    if ( i != 47 )
      break;
    if ( result[1] != 47 )
      goto LABEL_21;
    for ( i = *result; i != 0; i = *++result )
    {
      if ( i == 10 )
        break;
    }
  }
  if ( i != 34 )
  {
LABEL_21:
    if ( v1->set[i] != 0 )
    {
      com_token[0] = i;
      byte_1065C6E1 = 0;
      ++result;
    }
    else
    {
      v6 = com_token - result;
      do
      {
        result[v6] = i;
        i = *++result;
        ++v3;
      }
      while ( v1->set[i] == 0 && i > 0x20u );
      com_token[v3] = 0;
    }
    return result;
  }
  v5 = result[1];
  for ( result += 2; v5 != 34; ++result )
  {
    if ( v5 == 0 )
      break;
    com_token[v3] = v5;
    v5 = *result;
    ++v3;
  }
  com_token[v3] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10157F70
// Name: char const __near * COM_ParseLine(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COM_ParseLine(const char *data)
{
  const char *result; // eax
  int v2; // ebx
  char v3; // dl
  char v4; // cl
  char v5; // cl
  int v6; // esi
  int v7; // esi
  const char *v8; // edi
  char v9; // dl
  char v10; // cl
  char v11; // cl
  int v12; // esi
  int v13; // esi
  const char *v14; // edi
  char v15; // dl
  char v16; // cl
  const char *v17; // esi
  char v18; // cl
  int v19; // edi
  int v20; // edi

  result = data;
  v2 = 0;
  while ( result != nullptr && *result != 0 )
  {
    v3 = *result;
    v4 = *result++ & 0xC0;
    com_character = v3;
    if ( v4 == -64 )
    {
      v5 = 32;
      v6 = 2;
      do
      {
        if ( ((unsigned __int8)v3 & (unsigned __int8)v5) == 0 )
          break;
        ++v6;
        v5 >>= 1;
      }
      while ( v5 != 0 );
      if ( v6 <= 4 )
      {
        v7 = v6 - 1;
        v8 = result;
        if ( v7 != 0 )
        {
          while ( (*result & 0xC0) == 0x80 )
          {
            ++result;
            if ( --v7 == 0 )
              goto LABEL_12;
          }
          result = v8;
        }
        else
        {
LABEL_12:
          v3 = 63;
          com_character = 63;
        }
      }
    }
    if ( result != nullptr && (v3 >= 32 || v3 == 9) )
    {
      com_token[v2++] = v3;
      if ( v2 != 1023 )
        continue;
    }
    goto LABEL_20;
  }
  result = nullptr;
LABEL_20:
  com_token[v2] = 0;
  if ( v2 != 1023 )
    goto LABEL_38;
  while ( result != nullptr && *result != 0 )
  {
    v9 = *result;
    v10 = *result++ & 0xC0;
    com_character = v9;
    if ( v10 == -64 )
    {
      v11 = 32;
      v12 = 2;
      do
      {
        if ( ((unsigned __int8)v9 & (unsigned __int8)v11) == 0 )
          break;
        ++v12;
        v11 >>= 1;
      }
      while ( v11 != 0 );
      if ( v12 <= 4 )
      {
        v13 = v12 - 1;
        v14 = result;
        if ( v13 != 0 )
        {
          while ( (*result & 0xC0) == 0x80 )
          {
            ++result;
            if ( --v13 == 0 )
              goto LABEL_31;
          }
          result = v14;
        }
        else
        {
LABEL_31:
          v9 = 63;
          com_character = 63;
        }
      }
    }
    if ( result == nullptr )
      return nullptr;
    if ( v9 < 32 && v9 != 9 )
      goto LABEL_38;
  }
  result = nullptr;
LABEL_38:
  while ( result != nullptr && *result != 0 )
  {
    v15 = *result;
    v16 = *result & 0xC0;
    com_character = *result;
    v17 = result + 1;
    if ( v16 == -64 )
    {
      v18 = 32;
      v19 = 2;
      do
      {
        if ( ((unsigned __int8)v15 & (unsigned __int8)v18) == 0 )
          break;
        ++v19;
        v18 >>= 1;
      }
      while ( v18 != 0 );
      if ( v19 <= 4 )
      {
        v20 = v19 - 1;
        if ( v20 != 0 )
        {
          while ( (*v17 & 0xC0) == 0x80 )
          {
            ++v17;
            if ( --v20 == 0 )
              goto LABEL_48;
          }
          v17 = result + 1;
        }
        else
        {
LABEL_48:
          v15 = 63;
          com_character = 63;
        }
      }
    }
    if ( v17 == nullptr )
      break;
    if ( v15 >= 32 )
      return result;
    result = v17;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101580D0
// Name: int COM_TokenWaiting(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl COM_TokenWaiting(const char *buffer)
{
  const char *i; // esi
  char v2; // al

  for ( i = buffer; *i != 0; ++i )
  {
    v2 = *i;
    if ( *i == 10 )
      break;
    if ( v2 < 9 || v2 > 13 && v2 != 32 || isalnum(c: v2) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10158120
// Name: char __near * va(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *va(char *format, ...)
{
  va_list params; // [esp+Ch] [ebp+Ch] BYREF

  va_start(params, format);
  curstring = (curstring + 1) % 8;
  V_vsnprintf(pDest: string_2[curstring], maxLen: 512, pFormat: format, params);
  return string_2[curstring];
}

//------------------------------------------------------------------------------
// Address: 0x10158170
// Name: bool COM_CheckGameDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl COM_CheckGameDirectory(const char *gamedir)
{
  char szGD[260]; // [esp+4h] [ebp-104h] BYREF

  if ( gamedir != nullptr && *gamedir != 0 )
  {
    V_FileBase(in: com_gamedir, out: szGD, maxlen: 260);
    if ( _V_stricmp(s1: szGD, s2: gamedir) != 0 )
    {
      ConMsg(a1: "COM_CheckGameDirectory: game directories don't match (%s / %s)\n", szGD, gamedir);
      return 0;
    }
  }
  else
  {
    ConMsg(a1: "Server didn't specify a gamedir, assuming no change\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101581F0
// Name: int COM_OpenFile(char const __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl COM_OpenFile(const char *filename, void **file)
{
  void *v2; // eax

  v2 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "rb", a4: 0);
  *file = v2;
  if ( v2 != nullptr )
    return g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10158240
// Name: void COM_CreatePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_CreatePath(const char *path)
{
  char *i; // esi
  char v2; // bl
  char temppath[512]; // [esp+4h] [ebp-200h] BYREF

  V_strncpy(pDest: temppath, pSrc: path, maxLen: 512);
  for ( i = &temppath[1]; *i != 0; ++i )
  {
    v2 = *i;
    if ( *i == 47 || v2 == 92 )
    {
      *i = 0;
      Sys_mkdir(path: temppath);
      *i = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101582A0
// Name: bool COM_CopyFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall COM_CopyFile@<al>(int a1@<edi>, int a2@<esi>, const char *netpath, char *cachepath)
{
  void *v4; // ebx
  int v6; // eax
  IBaseFileSystem_vtbl *v7; // edx
  void *v8; // esi
  IBaseFileSystem *v9; // ecx
  int v10; // edi
  int v11; // esi
  _BYTE v12[4096]; // [esp+4h] [ebp-1004h] BYREF
  void *v13; // [esp+1004h] [ebp-4h]

  v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: netpath, a3: "rb", a4: 0);
  if ( v4 == nullptr )
    return 0;
  COM_CreatePath(path: cachepath);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, char *, const char *, const char *, int))g_pFileSystem->Open)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: cachepath,
         a3: "wb",
         a4: "MOD",
         a5: a2);
  v7 = g_pFileSystem->IBaseFileSystem::__vftable;
  v8 = (void *)v6;
  v9 = &g_pFileSystem->IBaseFileSystem;
  v13 = (void *)v6;
  if ( v6 != 0 )
  {
    v10 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))v7->Size_2)(a1: v9, a2: v4, a3: a1);
    if ( v10 > 0 )
    {
      do
      {
        v11 = v10;
        if ( (unsigned int)v10 >= 0x1000 )
          v11 = 4096;
        g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v12, a3: v11, a4: v4);
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v12, a3: v11, a4: v13);
        v10 -= v11;
      }
      while ( v10 > 0 );
      v8 = v13;
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v8);
    return 1;
  }
  else
  {
    v7->Close(this: v9, a2: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101583B0
// Name: int COM_FileSize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl COM_FileSize(const char *filename)
{
  return g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x101583D0
// Name: void COM_CopyFileChunk(void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_CopyFileChunk(void *dst, void *src, int nSize)
{
  int v3; // esi
  unsigned int v4; // esi
  char copybuf[1024]; // [esp+Ch] [ebp-400h] BYREF
  int copysize; // [esp+41Ch] [ebp+10h]

  v3 = nSize;
  if ( nSize > 1024 )
  {
    v4 = ((unsigned int)(nSize - 1025) >> 10) + 1;
    copysize = nSize - (v4 << 10);
    do
    {
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: 1024, a4: src);
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: 1024, a4: dst);
      --v4;
    }
    while ( v4 != 0 );
    v3 = copysize;
  }
  g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: v3, a4: src);
  g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: v3, a4: dst);
  g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: src);
  g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: dst);
}

//------------------------------------------------------------------------------
// Address: 0x101584B0
// Name: char __near * COM_StringCopy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_StringCopy(const char *in)
{
  int v1; // esi
  char *v2; // edi

  v1 = _V_strlen(str: in) + 1;
  v2 = (char *)MemAlloc_Alloc(nSize: v1);
  V_strncpy(pDest: v2, pSrc: in, maxLen: v1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x101584F0
// Name: char const __near * COM_GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_GetModDirectory()
{
  int v0; // edi
  int *v1; // ebx
  int v2; // esi
  int v3; // eax
  const char *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  if ( _V_strlen(str: modDir) != 0 )
    return modDir;
  v0 = _CommandLine();
  v1 = (int *)_CommandLine();
  v2 = *v1;
  v3 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v0 + 32))(
         a1: v0,
         a2: "-defaultgamedir",
         a3: "hl2");
  v4 = (const char *)(*(int (__thiscall **)(int *, const char *, int))(v2 + 32))(a1: v1, a2: "-game", a3: v3);
  V_strncpy(pDest: modDir, pSrc: v4, maxLen: 260);
  strchr(string: (unsigned __int8 *)modDir, chr: 0x2Fu);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)modDir, chr: 0x5Cu), v6 != 0) )
  {
    V_StripLastDir(dirName: modDir, maxlen: 260);
    v7 = _V_strlen(str: modDir);
    V_strncpy(pDest: modDir, pSrc: &v4[v7], maxLen: 260 - v7);
  }
  return modDir;
}

//------------------------------------------------------------------------------
// Address: 0x101585B0
// Name: char const __near * COM_DXLevelToString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COM_DXLevelToString(int dxlevel)
{
  bool v1; // bl
  const char *v2; // eax
  const char *result; // eax

  v1 = false;
  v2 = g_pMaterialSystemHardwareConfig->GetShaderDLLName(this: g_pMaterialSystemHardwareConfig);
  if ( v2 != nullptr )
    v1 = V_stristr(pStr: v2, pSearch: "nvfx") != nullptr;
  switch ( dxlevel )
  {
    case '<':
      result = "gamemode - 6.0";
      break;
    case 'F':
      result = "gamemode - 7.0";
      break;
    case 'P':
      result = "gamemode - 8.0";
      break;
    case 'Q':
      result = "gamemode - 8.1";
      break;
    case 'R':
      if ( v1 )
        result = "gamemode - 8.1 with some 9.0 (half-precision)";
      else
        result = "gamemode - 8.1 with some 9.0 (full-precision)";
      break;
    case 'Z':
      if ( v1 )
        result = "gamemode - 9.0 (half-precision)";
      else
        result = "gamemode - 9.0 (full-precision)";
      break;
    case '\\':
      result = "9.0 Shader Model 2.0b";
      break;
    case '_':
      result = "9.0 Shader Model 3.0";
      break;
    case 'b':
      result = "XBox 360";
      break;
    case 'd':
      result = "10.0 Shader Model 4.0";
      break;
    default:
      result = "gamemode";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101586C0
// Name: char const __near * COM_FormatSeconds(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_FormatSeconds(int seconds)
{
  int v1; // esi
  int v2; // ecx

  v1 = seconds;
  v2 = seconds / 60;
  if ( seconds / 60 <= 0 || (v1 = seconds % 60, v2 / 60 <= 0) )
  {
    V_snprintf(pDest: string_3, maxLen: 64, pFormat: "%02i:%02i", v2, v1);
    return string_3;
  }
  else
  {
    V_snprintf(pDest: string_3, maxLen: 64, pFormat: "%2i:%02i:%02i", v2 / 60, v2 % 60, v1);
    return string_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158750
// Name: void COM_LogString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_LogString(const char *pchFile, const char *pchString)
{
  const char *v2; // eax
  void *v3; // eax
  void *v4; // esi

  if ( g_pFileSystem != nullptr )
  {
    v2 = pchFile;
    if ( pchFile == nullptr )
      v2 = "hllog.txt";
    v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: "a+t", a4: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v3, a3: "%s", pchString);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101587C0
// Name: int COM_CompareFileTime(char const __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl COM_CompareFileTime(const char *filename1, const char *filename2, int *iCompare)
{
  int result; // eax
  int v4; // edi
  int v5; // eax

  result = 0;
  if ( iCompare != nullptr )
    *iCompare = 0;
  if ( filename1 != nullptr && filename2 != nullptr )
  {
    v4 = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: filename1, a3: nullptr);
    v5 = g_pFileSystem->GetFileTime(this: &g_pFileSystem->IBaseFileSystem, a2: filename2, a3: nullptr);
    if ( iCompare != nullptr )
      *iCompare = Sys_CompareFileTime(ft1: v4, ft2: v5);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158830
// Name: void COM_GetGameDir(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_GetGameDir(char *szGameDir, int maxlen)
{
  if ( szGameDir != nullptr )
    V_strncpy(pDest: szGameDir, pSrc: com_gamedir, maxLen: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x10158850
// Name: char const __near * COM_ParseFile(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COM_ParseFile(const char *data, char *token, int maxtoken)
{
  const char *v3; // esi

  v3 = COM_Parse(data);
  V_strncpy(pDest: token, pSrc: com_token, maxLen: maxtoken);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10158880
// Name: void COM_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_Init()
{
  CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
  CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
}

//------------------------------------------------------------------------------
// Address: 0x101588B0
// Name: bool COM_IsValidPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl COM_IsValidPath(const char *pszFilename)
{
  return pszFilename != nullptr
      && _V_strlen(str: pszFilename) > 0
      && _V_strstr(s1: pszFilename, search: "\\\\") == nullptr
      && _V_strstr(s1: pszFilename, search: ":") == nullptr
      && _V_strstr(s1: pszFilename, search: "..") == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10158910
// Name: unsigned char __near * COM_LoadFile(char const __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall COM_LoadFile@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const char *path,
        int usehunk,
        int *pLength)
{
  const char *v6; // esi
  void *v7; // edi
  int v8; // ebx
  unsigned __int8 *result; // eax
  unsigned __int8 *v10; // eax
  unsigned __int8 *v11; // esi
  char base[128]; // [esp+0h] [ebp-80h] BYREF

  if ( pLength != nullptr )
    *pLength = 0;
  v6 = path;
  v7 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, _DWORD, int, int))g_pFileSystem->Open)(
                 a1: &g_pFileSystem->IBaseFileSystem,
                 a2: path,
                 a3: "rb",
                 a4: 0,
                 a5: a2,
                 a6: a3);
  if ( v7 == nullptr )
    return nullptr;
  v8 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: v7,
         a3: a1);
  V_FileBase(in: path, out: base, maxlen: 128);
  switch ( usehunk )
  {
    case 1:
      v10 = (unsigned __int8 *)Hunk_AllocName(size: v8 + 1, name: base, bClear: true);
      goto LABEL_7;
    case 2:
    case 3:
      goto $LN37_5;
    case 4:
      if ( v8 + 1 <= loadsize )
      {
        v11 = loadbuf;
      }
      else
      {
        v10 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v8 + 1);
LABEL_7:
        v11 = v10;
      }
      if ( v11 != nullptr )
      {
        g_pFileSystem->ReadEx(this: g_pFileSystem, a2: v11, a3: v8 + 1, a4: v8, a5: v7);
        g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
        v11[v8] = 0;
        if ( pLength != nullptr )
          *pLength = v8;
        result = v11;
      }
      else
      {
        v6 = path;
$LN37_5:
        Sys_Error(error: "COM_LoadFile: not enough space for %s", v6);
        ((void (__thiscall *)(IBaseFileSystem *, void *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pFileSystem->Close)(
          a1: &g_pFileSystem->IBaseFileSystem,
          a2: v7,
          a3: *(_DWORD *)base,
          a4: *(_DWORD *)&base[4],
          a5: *(_DWORD *)&base[8],
          a6: *(_DWORD *)&base[12],
          a7: *(_DWORD *)&base[16],
          a8: *(_DWORD *)&base[20],
          a9: *(_DWORD *)&base[24],
          a10: *(_DWORD *)&base[28],
          a11: *(_DWORD *)&base[32],
          a12: *(_DWORD *)&base[36],
          a13: *(_DWORD *)&base[40],
          a14: *(_DWORD *)&base[44],
          a15: *(_DWORD *)&base[48],
          a16: *(_DWORD *)&base[52],
          a17: *(_DWORD *)&base[56],
          a18: *(_DWORD *)&base[60],
          a19: *(_DWORD *)&base[64],
          a20: *(_DWORD *)&base[68],
          a21: *(_DWORD *)&base[72],
          a22: *(_DWORD *)&base[76],
          a23: *(_DWORD *)&base[80],
          a24: *(_DWORD *)&base[84],
          a25: *(_DWORD *)&base[88],
          a26: *(_DWORD *)&base[92],
          a27: *(_DWORD *)&base[96],
          a28: *(_DWORD *)&base[100],
          a29: *(_DWORD *)&base[104],
          a30: *(_DWORD *)&base[108],
          a31: *(_DWORD *)&base[112]);
        result = nullptr;
      }
      break;
    case 5:
      v10 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v8 + 1);
      goto LABEL_7;
    default:
      Sys_Error(error: "COM_LoadFile: bad usehunk");
      goto $LN37_5;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158A60
// Name: unsigned char __near * COM_LoadStackFile(char const __near *,void __near *,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall COM_LoadStackFile@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const char *path,
        unsigned __int8 *buffer,
        int bufsize,
        int *filesize)
{
  void *v7; // esi
  int v8; // edi
  unsigned __int8 *v9; // ebx
  char out[128]; // [esp+0h] [ebp-80h] BYREF

  loadbuf = buffer;
  loadsize = bufsize;
  if ( filesize != nullptr )
    *filesize = 0;
  v7 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, _DWORD, int, int))g_pFileSystem->Open)(
                 a1: &g_pFileSystem->IBaseFileSystem,
                 a2: path,
                 a3: "rb",
                 a4: 0,
                 a5: a3,
                 a6: a1);
  if ( v7 == nullptr )
    return nullptr;
  v8 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: v7,
         a3: a2);
  V_FileBase(in: path, out, maxlen: 128);
  if ( v8 + 1 <= loadsize )
    v9 = loadbuf;
  else
    v9 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v8 + 1);
  if ( v9 != nullptr )
  {
    g_pFileSystem->ReadEx(this: g_pFileSystem, a2: v9, a3: v8 + 1, a4: v8, a5: v7);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
    v9[v8] = 0;
    if ( filesize != nullptr )
      *filesize = v8;
    return v9;
  }
  else
  {
    Sys_Error(error: "COM_LoadFile: not enough space for %s", path);
    ((void (__thiscall *)(IBaseFileSystem *, void *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pFileSystem->Close)(
      a1: &g_pFileSystem->IBaseFileSystem,
      a2: v7,
      a3: *(_DWORD *)out,
      a4: *(_DWORD *)&out[4],
      a5: *(_DWORD *)&out[8],
      a6: *(_DWORD *)&out[12],
      a7: *(_DWORD *)&out[16],
      a8: *(_DWORD *)&out[20],
      a9: *(_DWORD *)&out[24],
      a10: *(_DWORD *)&out[28],
      a11: *(_DWORD *)&out[32],
      a12: *(_DWORD *)&out[36],
      a13: *(_DWORD *)&out[40],
      a14: *(_DWORD *)&out[44],
      a15: *(_DWORD *)&out[48],
      a16: *(_DWORD *)&out[52],
      a17: *(_DWORD *)&out[56],
      a18: *(_DWORD *)&out[60],
      a19: *(_DWORD *)&out[64],
      a20: *(_DWORD *)&out[68],
      a21: *(_DWORD *)&out[72],
      a22: *(_DWORD *)&out[76],
      a23: *(_DWORD *)&out[80],
      a24: *(_DWORD *)&out[84],
      a25: *(_DWORD *)&out[88],
      a26: *(_DWORD *)&out[92],
      a27: *(_DWORD *)&out[96],
      a28: *(_DWORD *)&out[100],
      a29: *(_DWORD *)&out[104],
      a30: *(_DWORD *)&out[108],
      a31: *(_DWORD *)&out[112]);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158B70
// Name: void COM_SetupLogDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_SetupLogDir(const char *mapname)
{
  int v1; // eax
  int i; // esi
  char sLogDir[260]; // [esp+4h] [ebp-30Ch] BYREF
  char gameDir[260]; // [esp+108h] [ebp-208h] BYREF
  char sRelativeLogDir[260]; // [esp+20Ch] [ebp-104h] BYREF

  V_strncpy(pDest: gameDir, pSrc: com_gamedir, maxLen: 260);
  g_pFileSystem->RemoveSearchPath(this: g_pFileSystem, a2: nullptr, a3: "LOGDIR");
  if ( mapname != nullptr
    && (v1 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-uselogdir") != 0) )
  {
    for ( i = 0; i < 10000; ++i )
    {
      V_snprintf(pDest: sRelativeLogDir, maxLen: 260, pFormat: "logs/%s/%04i", mapname, i);
      if ( !g_pFileSystem->IsDirectory(this: g_pFileSystem, a2: sRelativeLogDir, a3: "GAME") )
        break;
    }
    if ( i == 10000 )
      V_snprintf(pDest: sRelativeLogDir, maxLen: 260, pFormat: "logs/%s/%04i", mapname, 0);
    g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: sRelativeLogDir, a3: "GAME");
    if ( !pathsetup )
    {
      pathsetup = true;
      V_snprintf(pDest: sLogDir, maxLen: 260, pFormat: "%s/%s", gameDir, sRelativeLogDir);
      g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: sLogDir, a3: "LOGDIR", a4: PATH_ADD_TO_TAIL);
    }
  }
  else
  {
    g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: gameDir, a3: "LOGDIR", a4: PATH_ADD_TO_TAIL);
  }
  g_pFileSystem->MarkPathIDByRequestOnly(this: g_pFileSystem, a2: "LOGDIR", a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10158CE0
// Name: void COM_InitFilesystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_InitFilesystem(KeyValues *pFullModPath)
{
  int v1; // eax
  int m_Size; // ebx
  int v3; // eax
  const char *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // eax
  char *String; // eax
  IEngineVGuiInternal *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  IBaseFileSystem *v12; // eax
  CSteam3Client *v13; // eax
  const char *v14; // eax
  ELanguage v15; // eax
  KeyValues *Key; // eax
  KeyValues *v17; // eax
  char **m_pMemory; // edi
  KeyValues *FirstValue; // esi
  const char *Name; // ebx
  char *v21; // edi
  char *v22; // ebx
  const char *LanguageShortName; // eax
  int i; // esi
  CFSSearchPathsInit initInfo; // [esp+8h] [ebp-2E8h] BYREF
  char pDest[64]; // [esp+214h] [ebp-DCh] BYREF
  char language[128]; // [esp+254h] [ebp-9Ch] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > vSearchPaths; // [esp+2D4h] [ebp-1Ch] BYREF
  char *szFullSearchPath; // [esp+2E8h] [ebp-8h] BYREF
  ELanguage eAudioLanguage; // [esp+2ECh] [ebp-4h]
  KeyValues *modinfo; // [esp+2F8h] [ebp+8h]

  CFSSearchPathsInit::CFSSearchPathsInit(this: &initInfo);
  V_strncpy(pDest: language, pSrc: "english", maxLen: 128);
  v1 = _CommandLine();
  m_Size = 0;
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v1 + 12))(a1: v1, a2: "-language", a3: 0) != 0 )
  {
    v3 = _CommandLine();
    v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 32))(a1: v3);
    V_strncpy(pDest: language, pSrc: v4, maxLen: (int)"-language");
  }
  else
  {
    memset(dst: (unsigned __int8 *)language, value: 0, count: sizeof(language));
    g_pVGuiSystem->GetRegistryString(
      this: g_pVGuiSystem,
      a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
      a3: language,
      a4: 127);
  }
  if ( _V_strlen(str: language) > 0 && _V_stricmp(s1: language, s2: "english") != 0 )
    initInfo.m_pLanguage = language;
  initInfo.m_pFileSystem = g_pFileSystem;
  initInfo.m_pDirectoryName = (const char *)pFullModPath;
  if ( pFullModPath == nullptr )
    initInfo.m_pDirectoryName = host_parms.game;
  FileSystem_LoadSearchPaths(&initInfo);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ModInfo");
  else
    v6 = nullptr;
  if ( g_pFileSystem != nullptr )
    v7 = &g_pFileSystem->IBaseFileSystem;
  else
    v7 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v6,
         filesystem: v7,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v6, keyName: "type", defaultValue: "singleplayer_only");
    if ( _V_stricmp(s1: String, s2: "singleplayer_only") != 0 )
    {
      DevMsg(a1: "Enabling whitelist file tracking in filesystem...\n");
      g_pFileSystem->EnableWhitelistFileTracking(this: g_pFileSystem, a2: true);
    }
    else
    {
      DevMsg(a1: "Disabling whitelist file tracking in filesystem...\n");
      g_pFileSystem->EnableWhitelistFileTracking(this: g_pFileSystem, a2: false);
    }
  }
  KeyValues::deleteThis(this: v6);
  V_MakeAbsolutePath(pOut: com_gamedir, outLen: 260, pPath: initInfo.m_ModPath, pStartingDir: nullptr);
  V_strncpy(pDest: com_basedir, pSrc: host_parms.basedir, maxLen: 260);
  _V_strlower(start: com_basedir);
  V_FixSlashes(pname: com_basedir, separator: 92);
  v9 = EngineVGui();
  v9->SetVGUIDirectories(this: v9);
  COM_SetupLogDir(mapname: nullptr);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
  {
    v11 = KeyValues::KeyValues(this: v10, setName: "ModInfo");
    modinfo = v11;
  }
  else
  {
    modinfo = nullptr;
    v11 = nullptr;
  }
  if ( g_pFileSystem != nullptr )
    v12 = &g_pFileSystem->IBaseFileSystem;
  else
    v12 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v11,
         filesystem: v12,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    V_strncpy(pDest, pSrc: "english", maxLen: 64);
    if ( Steam3Client()->m_pSteamApps != nullptr )
    {
      v13 = Steam3Client();
      v14 = v13->m_pSteamApps->GetCurrentGameLanguage(this: v13->m_pSteamApps);
      V_strncpy(pDest, pSrc: v14, maxLen: 64);
    }
    v15 = PchLanguageToELanguage(pchShortName: pDest);
    eAudioLanguage = v15;
    if ( v15 != k_Lang_English
      && v15 != k_Lang_None
      && PchLanguageToELanguage(pchShortName: initInfo.m_pLanguage) != v15 )
    {
      Key = KeyValues::FindKey(this: v11, keyName: "FileSystem", bCreate: false);
      v17 = KeyValues::FindKey(this: Key, keyName: "SearchPaths", bCreate: false);
      m_pMemory = nullptr;
      memset(&vSearchPaths, 0, sizeof(vSearchPaths));
      FirstValue = KeyValues::GetFirstValue(this: v17);
      if ( FirstValue != nullptr )
      {
        do
        {
          Name = KeyValues::GetName(this: FirstValue);
          v21 = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue);
          if ( _V_stricmp(s1: Name, s2: "game") == 0 && _V_strstr(s1: v21, search: "|gameinfo_path|") == nullptr )
          {
            v22 = (char *)MemAlloc_Alloc(nSize: 0x104u);
            szFullSearchPath = v22;
            LanguageShortName = GetLanguageShortName(eLang: eAudioLanguage);
            V_snprintf(pDest: v22, maxLen: 260, pFormat: "%s%c%s_%s%c", com_basedir, 92, v21, LanguageShortName, 92);
            CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
              this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vSearchPaths,
              src: (vgui::TreeNode **)&szFullSearchPath);
          }
          FirstValue = KeyValues::GetNextValue(this: FirstValue);
        }
        while ( FirstValue != nullptr );
        m_Size = vSearchPaths.m_Size;
        m_pMemory = vSearchPaths.m_Memory.m_pMemory;
      }
      for ( i = 0; i < m_Size; ++i )
      {
        g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: m_pMemory[i], a3: "game", a4: PATH_ADD_TO_HEAD);
        free(pMem: m_pMemory[i]);
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vSearchPaths);
      v11 = modinfo;
    }
    KeyValues::deleteThis(this: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101590E0
// Name: __CreateCCvarQueryICvarQuery_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCvarQuery *__cdecl _CreateCCvarQueryICvarQuery_interface()
{
  return &s_CvarQuery;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10157F20
// Name: void COM_ExplainDisconnection(bool,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void COM_ExplainDisconnection(bool bPrint, const char *fmt, ...)
{
  char *v2; // esi
  const char *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IMatchEventsSubscription *v6; // eax
  char szString[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list params; // [esp+410h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: szString, maxLen: 1024, pFormat: fmt, params);
  V_strncpy(pDest: gszDisconnectReason, pSrc: szString, maxLen: 256);
  gfExtendedError = true;
  if ( bPrint )
    ConMsg(a1: "%s\n", gszDisconnectReason);
  v2 = szString;
  v3 = StringAfterPrefix(str: szString, prefix: "Disconnect: ");
  if ( v3 != nullptr )
    v2 = (char *)v3;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "OnEngineDisconnectReason", firstKey: "reason", firstValue: v2);
  else
    v5 = nullptr;
  v6 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v6->BroadcastEvent(this: v6, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10157FE0
// Name: char const __near * COM_Parse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COM_Parse(const char *data)
{
  characterset_t *v1; // edi
  const char *result; // eax
  int v3; // esi
  unsigned __int8 i; // cl
  char v5; // cl
  int v6; // edx

  v1 = &g_BreakSetIncludingColons;
  if ( com_ignorecolons )
    v1 = &g_BreakSet;
  result = data;
  v3 = 0;
  com_token[0] = 0;
  if ( data == nullptr )
    return nullptr;
  i = *data;
  while ( 1 )
  {
    if ( i <= 0x20u )
    {
      while ( i != 0 )
      {
        i = *++result;
        if ( i > 0x20u )
          goto LABEL_9;
      }
      return nullptr;
    }
LABEL_9:
    if ( i != 47 )
      break;
    if ( result[1] != 47 )
      goto LABEL_21;
    for ( i = *result; i != 0; i = *++result )
    {
      if ( i == 10 )
        break;
    }
  }
  if ( i != 34 )
  {
LABEL_21:
    if ( v1->set[i] != 0 )
    {
      com_token[0] = i;
      byte_1065C6E1 = 0;
      ++result;
    }
    else
    {
      v6 = com_token - result;
      do
      {
        result[v6] = i;
        i = *++result;
        ++v3;
      }
      while ( v1->set[i] == 0 && i > 0x20u );
      com_token[v3] = 0;
    }
    return result;
  }
  v5 = result[1];
  for ( result += 2; v5 != 34; ++result )
  {
    if ( v5 == 0 )
      break;
    com_token[v3] = v5;
    v5 = *result;
    ++v3;
  }
  com_token[v3] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158230
// Name: int COM_TokenWaiting(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl COM_TokenWaiting(const char *buffer)
{
  const char *i; // esi
  char v2; // al

  for ( i = buffer; *i != 0; ++i )
  {
    v2 = *i;
    if ( *i == 10 )
      break;
    if ( v2 < 9 || v2 > 13 && v2 != 32 || isalnum(c: v2) != 0 )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10158280
// Name: char __near * va(char __near *,...)
// Source: json
//------------------------------------------------------------------------------
char *va(char *format, ...)
{
  va_list params; // [esp+Ch] [ebp+Ch] BYREF

  va_start(params, format);
  curstring = (curstring + 1) % 8;
  V_vsnprintf(pDest: string_2[curstring], maxLen: 512, pFormat: format, params);
  return string_2[curstring];
}

//------------------------------------------------------------------------------
// Address: 0x101582D0
// Name: bool COM_CheckGameDirectory(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl COM_CheckGameDirectory(const char *gamedir)
{
  char szGD[260]; // [esp+4h] [ebp-104h] BYREF

  if ( gamedir != nullptr && *gamedir != 0 )
  {
    V_FileBase(in: com_gamedir, out: szGD, maxlen: 260);
    if ( _V_stricmp(s1: szGD, s2: gamedir) != 0 )
    {
      ConMsg(a1: "COM_CheckGameDirectory: game directories don't match (%s / %s)\n", szGD, gamedir);
      return 0;
    }
  }
  else
  {
    ConMsg(a1: "Server didn't specify a gamedir, assuming no change\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10158350
// Name: int COM_OpenFile(char const __near *,void __near * __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl COM_OpenFile(const char *filename, void **file)
{
  void *v2; // eax

  v2 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: "rb", a4: 0);
  *file = v2;
  if ( v2 != nullptr )
    return g_pFileSystem->Size_2(this: &g_pFileSystem->IBaseFileSystem, a2: v2);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x101583A0
// Name: void COM_CreatePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_CreatePath(const char *path)
{
  char *i; // esi
  char v2; // bl
  char temppath[512]; // [esp+4h] [ebp-200h] BYREF

  V_strncpy(pDest: temppath, pSrc: path, maxLen: 512);
  for ( i = &temppath[1]; *i != 0; ++i )
  {
    v2 = *i;
    if ( *i == 47 || v2 == 92 )
    {
      *i = 0;
      Sys_mkdir(path: temppath);
      *i = v2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158400
// Name: bool COM_CopyFile(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __usercall COM_CopyFile@<al>(int a1@<edi>, int a2@<esi>, const char *netpath, char *cachepath)
{
  void *v4; // ebx
  int v6; // eax
  IBaseFileSystem_vtbl *v7; // edx
  void *v8; // esi
  IBaseFileSystem *v9; // ecx
  int v10; // edi
  int v11; // esi
  _BYTE v12[4096]; // [esp+4h] [ebp-1004h] BYREF
  void *v13; // [esp+1004h] [ebp-4h]

  v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: netpath, a3: "rb", a4: 0);
  if ( v4 == nullptr )
    return 0;
  COM_CreatePath(path: cachepath);
  v6 = ((int (__thiscall *)(IBaseFileSystem *, char *, const char *, const char *, int))g_pFileSystem->Open)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: cachepath,
         a3: "wb",
         a4: "MOD",
         a5: a2);
  v7 = g_pFileSystem->IBaseFileSystem::__vftable;
  v8 = (void *)v6;
  v9 = &g_pFileSystem->IBaseFileSystem;
  v13 = (void *)v6;
  if ( v6 != 0 )
  {
    v10 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))v7->Size_2)(a1: v9, a2: v4, a3: a1);
    if ( v10 > 0 )
    {
      do
      {
        v11 = v10;
        if ( (unsigned int)v10 >= 0x1000 )
          v11 = 4096;
        g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: v12, a3: v11, a4: v4);
        g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: v12, a3: v11, a4: v13);
        v10 -= v11;
      }
      while ( v10 > 0 );
      v8 = v13;
    }
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v8);
    return 1;
  }
  else
  {
    v7->Close(this: v9, a2: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158510
// Name: int COM_FileSize(char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl COM_FileSize(const char *filename)
{
  return g_pFileSystem->Size(this: &g_pFileSystem->IBaseFileSystem, a2: filename, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10158530
// Name: void COM_CopyFileChunk(void __near *,void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_CopyFileChunk(void *dst, void *src, int nSize)
{
  int v3; // esi
  unsigned int v4; // esi
  char copybuf[1024]; // [esp+Ch] [ebp-400h] BYREF
  int copysize; // [esp+41Ch] [ebp+10h]

  v3 = nSize;
  if ( nSize > 1024 )
  {
    v4 = ((unsigned int)(nSize - 1025) >> 10) + 1;
    copysize = nSize - (v4 << 10);
    do
    {
      g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: 1024, a4: src);
      g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: 1024, a4: dst);
      --v4;
    }
    while ( v4 != 0 );
    v3 = copysize;
  }
  g_pFileSystem->Read(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: v3, a4: src);
  g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: copybuf, a3: v3, a4: dst);
  g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: src);
  g_pFileSystem->Flush(this: &g_pFileSystem->IBaseFileSystem, a2: dst);
}

//------------------------------------------------------------------------------
// Address: 0x10158610
// Name: char __near * COM_StringCopy(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_StringCopy(const char *in)
{
  int v1; // esi
  char *v2; // edi

  v1 = _V_strlen(str: in) + 1;
  v2 = (char *)MemAlloc_Alloc(nSize: v1);
  V_strncpy(pDest: v2, pSrc: in, maxLen: v1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10158640
// Name: char const __near * COM_GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_GetModDirectory()
{
  int v0; // edi
  int *v1; // ebx
  int v2; // esi
  int v3; // eax
  const char *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  if ( _V_strlen(str: modDir) != 0 )
    return modDir;
  v0 = _CommandLine();
  v1 = (int *)_CommandLine();
  v2 = *v1;
  v3 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v0 + 32))(
         a1: v0,
         a2: "-defaultgamedir",
         a3: "hl2");
  v4 = (const char *)(*(int (__thiscall **)(int *, const char *, int))(v2 + 32))(a1: v1, a2: "-game", a3: v3);
  V_strncpy(pDest: modDir, pSrc: v4, maxLen: 260);
  strchr(string: (unsigned __int8 *)modDir, chr: 0x2Fu);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)modDir, chr: 0x5Cu), v6 != 0) )
  {
    V_StripLastDir(dirName: modDir, maxlen: 260);
    v7 = _V_strlen(str: modDir);
    V_strncpy(pDest: modDir, pSrc: &v4[v7], maxLen: 260 - v7);
  }
  return modDir;
}

//------------------------------------------------------------------------------
// Address: 0x10158700
// Name: char const __near * COM_DXLevelToString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COM_DXLevelToString(int dxlevel)
{
  bool v1; // bl
  const char *v2; // eax
  const char *result; // eax

  v1 = false;
  v2 = g_pMaterialSystemHardwareConfig->GetShaderDLLName(this: g_pMaterialSystemHardwareConfig);
  if ( v2 != nullptr )
    v1 = V_stristr(pStr: v2, pSearch: "nvfx") != nullptr;
  switch ( dxlevel )
  {
    case '<':
      result = "gamemode - 6.0";
      break;
    case 'F':
      result = "gamemode - 7.0";
      break;
    case 'P':
      result = "gamemode - 8.0";
      break;
    case 'Q':
      result = "gamemode - 8.1";
      break;
    case 'R':
      if ( v1 )
        result = "gamemode - 8.1 with some 9.0 (half-precision)";
      else
        result = "gamemode - 8.1 with some 9.0 (full-precision)";
      break;
    case 'Z':
      if ( v1 )
        result = "gamemode - 9.0 (half-precision)";
      else
        result = "gamemode - 9.0 (full-precision)";
      break;
    case '\\':
      result = "9.0 Shader Model 2.0b";
      break;
    case '_':
      result = "9.0 Shader Model 3.0";
      break;
    case 'b':
      result = "XBox 360";
      break;
    case 'd':
      result = "10.0 Shader Model 4.0";
      break;
    default:
      result = "gamemode";
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10158810
// Name: char const __near * COM_FormatSeconds(int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_FormatSeconds(int seconds)
{
  int v1; // esi
  int v2; // ecx

  v1 = seconds;
  v2 = seconds / 60;
  if ( seconds / 60 <= 0 || (v1 = seconds % 60, v2 / 60 <= 0) )
  {
    V_snprintf(pDest: string_3, maxLen: 64, pFormat: "%02i:%02i", v2, v1);
    return string_3;
  }
  else
  {
    V_snprintf(pDest: string_3, maxLen: 64, pFormat: "%2i:%02i:%02i", v2 / 60, v2 % 60, v1);
    return string_3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101588A0
// Name: void COM_LogString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_LogString(const char *pchFile, const char *pchString)
{
  const char *v2; // eax
  void *v3; // eax
  void *v4; // esi

  if ( g_pFileSystem != nullptr )
  {
    v2 = pchFile;
    if ( pchFile == nullptr )
      v2 = "hllog.txt";
    v3 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: v2, a3: "a+t", a4: 0);
    v4 = v3;
    if ( v3 != nullptr )
    {
      g_pFileSystem->FPrintf(this: g_pFileSystem, a2: v3, a3: "%s", pchString);
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158980
// Name: void COM_GetGameDir(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_GetGameDir(char *szGameDir, int maxlen)
{
  if ( szGameDir != nullptr )
    V_strncpy(pDest: szGameDir, pSrc: com_gamedir, maxLen: maxlen);
}

//------------------------------------------------------------------------------
// Address: 0x101589A0
// Name: char const __near * COM_ParseFile(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl COM_ParseFile(const char *data, char *token, int maxtoken)
{
  const char *v3; // esi

  v3 = COM_Parse(data);
  V_strncpy(pDest: token, pSrc: com_token, maxLen: maxtoken);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x101589D0
// Name: void COM_Init(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_Init()
{
  CharacterSetBuild(pSetBuffer: &g_BreakSet, pszSetString: "{}()'");
  CharacterSetBuild(pSetBuffer: &g_BreakSetIncludingColons, pszSetString: "{}()':");
}

//------------------------------------------------------------------------------
// Address: 0x10158A00
// Name: bool COM_IsValidPath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl COM_IsValidPath(const char *pszFilename)
{
  return pszFilename != nullptr
      && _V_strlen(str: pszFilename) > 0
      && _V_strstr(s1: pszFilename, search: "\\\\") == nullptr
      && _V_strstr(s1: pszFilename, search: ":") == nullptr
      && _V_strstr(s1: pszFilename, search: "..") == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10158BB0
// Name: unsigned char __near * COM_LoadStackFile(char const __near *,void __near *,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__usercall COM_LoadStackFile@<eax>(
        int a1@<ebx>,
        int a2@<edi>,
        int a3@<esi>,
        const char *path,
        unsigned __int8 *buffer,
        int bufsize,
        int *filesize)
{
  void *v7; // esi
  int v8; // edi
  unsigned __int8 *v9; // ebx
  char out[128]; // [esp+0h] [ebp-80h] BYREF

  loadbuf = buffer;
  loadsize = bufsize;
  if ( filesize != nullptr )
    *filesize = 0;
  v7 = (void *)((int (__thiscall *)(IBaseFileSystem *, const char *, const char *, _DWORD, int, int))g_pFileSystem->Open)(
                 a1: &g_pFileSystem->IBaseFileSystem,
                 a2: path,
                 a3: "rb",
                 a4: 0,
                 a5: a3,
                 a6: a1);
  if ( v7 == nullptr )
    return nullptr;
  v8 = ((int (__thiscall *)(IBaseFileSystem *, void *, int))g_pFileSystem->Size_2)(
         a1: &g_pFileSystem->IBaseFileSystem,
         a2: v7,
         a3: a2);
  V_FileBase(in: path, out, maxlen: 128);
  if ( v8 + 1 <= loadsize )
    v9 = loadbuf;
  else
    v9 = (unsigned __int8 *)MemAlloc_Alloc(nSize: v8 + 1);
  if ( v9 != nullptr )
  {
    g_pFileSystem->ReadEx(this: g_pFileSystem, a2: v9, a3: v8 + 1, a4: v8, a5: v7);
    g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v7);
    v9[v8] = 0;
    if ( filesize != nullptr )
      *filesize = v8;
    return v9;
  }
  else
  {
    Sys_Error(error: "COM_LoadFile: not enough space for %s", path);
    ((void (__thiscall *)(IBaseFileSystem *, void *, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))g_pFileSystem->Close)(
      a1: &g_pFileSystem->IBaseFileSystem,
      a2: v7,
      a3: *(_DWORD *)out,
      a4: *(_DWORD *)&out[4],
      a5: *(_DWORD *)&out[8],
      a6: *(_DWORD *)&out[12],
      a7: *(_DWORD *)&out[16],
      a8: *(_DWORD *)&out[20],
      a9: *(_DWORD *)&out[24],
      a10: *(_DWORD *)&out[28],
      a11: *(_DWORD *)&out[32],
      a12: *(_DWORD *)&out[36],
      a13: *(_DWORD *)&out[40],
      a14: *(_DWORD *)&out[44],
      a15: *(_DWORD *)&out[48],
      a16: *(_DWORD *)&out[52],
      a17: *(_DWORD *)&out[56],
      a18: *(_DWORD *)&out[60],
      a19: *(_DWORD *)&out[64],
      a20: *(_DWORD *)&out[68],
      a21: *(_DWORD *)&out[72],
      a22: *(_DWORD *)&out[76],
      a23: *(_DWORD *)&out[80],
      a24: *(_DWORD *)&out[84],
      a25: *(_DWORD *)&out[88],
      a26: *(_DWORD *)&out[92],
      a27: *(_DWORD *)&out[96],
      a28: *(_DWORD *)&out[100],
      a29: *(_DWORD *)&out[104],
      a30: *(_DWORD *)&out[108],
      a31: *(_DWORD *)&out[112]);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10158CC0
// Name: void COM_SetupLogDir(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_SetupLogDir(const char *mapname)
{
  int v1; // eax
  int i; // esi
  char sLogDir[260]; // [esp+4h] [ebp-30Ch] BYREF
  char gameDir[260]; // [esp+108h] [ebp-208h] BYREF
  char sRelativeLogDir[260]; // [esp+20Ch] [ebp-104h] BYREF

  V_strncpy(pDest: gameDir, pSrc: com_gamedir, maxLen: 260);
  g_pFileSystem->RemoveSearchPath(this: g_pFileSystem, a2: nullptr, a3: "LOGDIR");
  if ( mapname != nullptr
    && (v1 = _CommandLine(),
        (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-uselogdir") != 0) )
  {
    for ( i = 0; i < 10000; ++i )
    {
      V_snprintf(pDest: sRelativeLogDir, maxLen: 260, pFormat: "logs/%s/%04i", mapname, i);
      if ( !g_pFileSystem->IsDirectory(this: g_pFileSystem, a2: sRelativeLogDir, a3: "GAME") )
        break;
    }
    if ( i == 10000 )
      V_snprintf(pDest: sRelativeLogDir, maxLen: 260, pFormat: "logs/%s/%04i", mapname, 0);
    g_pFileSystem->CreateDirHierarchy(this: g_pFileSystem, a2: sRelativeLogDir, a3: "GAME");
    if ( !pathsetup )
    {
      pathsetup = true;
      V_snprintf(pDest: sLogDir, maxLen: 260, pFormat: "%s/%s", gameDir, sRelativeLogDir);
      g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: sLogDir, a3: "LOGDIR", a4: PATH_ADD_TO_TAIL);
    }
  }
  else
  {
    g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: gameDir, a3: "LOGDIR", a4: PATH_ADD_TO_TAIL);
  }
  g_pFileSystem->MarkPathIDByRequestOnly(this: g_pFileSystem, a2: "LOGDIR", a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10158E90
// Name: void COM_InitFilesystem(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl COM_InitFilesystem(KeyValues *pFullModPath)
{
  int v1; // eax
  int m_Size; // ebx
  int v3; // eax
  const char *v4; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  IBaseFileSystem *v7; // eax
  const char *String; // eax
  IEngineVGuiInternal *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  IBaseFileSystem *v12; // eax
  CSteam3Client *v13; // eax
  const char *v14; // eax
  ELanguage v15; // eax
  KeyValues *Key; // eax
  KeyValues *v17; // eax
  char **m_pMemory; // edi
  KeyValues *FirstValue; // esi
  const char *Name; // ebx
  const char *v21; // edi
  char *v22; // ebx
  const char *LanguageShortName; // eax
  int i; // esi
  CFSSearchPathsInit initInfo; // [esp+8h] [ebp-2E8h] BYREF
  char pDest[64]; // [esp+214h] [ebp-DCh] BYREF
  char language[128]; // [esp+254h] [ebp-9Ch] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > vSearchPaths; // [esp+2D4h] [ebp-1Ch] BYREF
  char *szFullSearchPath; // [esp+2E8h] [ebp-8h] BYREF
  ELanguage eAudioLanguage; // [esp+2ECh] [ebp-4h]
  KeyValues *modinfo; // [esp+2F8h] [ebp+8h]

  CFSSearchPathsInit::CFSSearchPathsInit(this: &initInfo);
  V_strncpy(pDest: language, pSrc: "english", maxLen: 128);
  v1 = _CommandLine();
  m_Size = 0;
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v1 + 12))(a1: v1, a2: "-language", a3: 0) != 0 )
  {
    v3 = _CommandLine();
    v4 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v3 + 32))(a1: v3);
    V_strncpy(pDest: language, pSrc: v4, maxLen: (int)"-language");
  }
  else
  {
    memset(dst: (unsigned __int8 *)language, value: 0, count: sizeof(language));
    g_pVGuiSystem->GetRegistryString(
      this: g_pVGuiSystem,
      a2: "HKEY_CURRENT_USER\\Software\\Valve\\Steam\\Language",
      a3: language,
      a4: 127);
  }
  if ( _V_strlen(str: language) > 0 && _V_stricmp(s1: language, s2: "english") != 0 )
    initInfo.m_pLanguage = language;
  initInfo.m_pFileSystem = g_pFileSystem;
  initInfo.m_pDirectoryName = (const char *)pFullModPath;
  if ( pFullModPath == nullptr )
    initInfo.m_pDirectoryName = host_parms.game;
  FileSystem_LoadSearchPaths(&initInfo);
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "ModInfo");
  else
    v6 = nullptr;
  if ( g_pFileSystem != nullptr )
    v7 = &g_pFileSystem->IBaseFileSystem;
  else
    v7 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v6,
         filesystem: v7,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    String = KeyValues::GetString(this: v6, keyName: "type", defaultValue: "singleplayer_only");
    if ( _V_stricmp(s1: String, s2: "singleplayer_only") != 0 )
    {
      DevMsg(a1: "Enabling whitelist file tracking in filesystem...\n");
      g_pFileSystem->EnableWhitelistFileTracking(this: g_pFileSystem, a2: true);
    }
    else
    {
      DevMsg(a1: "Disabling whitelist file tracking in filesystem...\n");
      g_pFileSystem->EnableWhitelistFileTracking(this: g_pFileSystem, a2: false);
    }
  }
  KeyValues::deleteThis(this: v6);
  V_MakeAbsolutePath(pOut: com_gamedir, outLen: 260, pPath: initInfo.m_ModPath, pStartingDir: nullptr);
  V_strncpy(pDest: com_basedir, pSrc: host_parms.basedir, maxLen: 260);
  _V_strlower(start: com_basedir);
  V_FixSlashes(pname: com_basedir, separator: 92);
  v9 = EngineVGui();
  v9->SetVGUIDirectories(this: v9);
  COM_SetupLogDir(mapname: nullptr);
  v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v10 != nullptr )
  {
    v11 = KeyValues::KeyValues(this: v10, setName: "ModInfo");
    modinfo = v11;
  }
  else
  {
    modinfo = nullptr;
    v11 = nullptr;
  }
  if ( g_pFileSystem != nullptr )
    v12 = &g_pFileSystem->IBaseFileSystem;
  else
    v12 = nullptr;
  if ( KeyValues::LoadFromFile(
         this: v11,
         filesystem: v12,
         resourceName: "gameinfo.txt",
         pathID: nullptr,
         pfnEvaluateSymbolProc: nullptr) )
  {
    V_strncpy(pDest, pSrc: "english", maxLen: 64);
    if ( Steam3Client()->m_pSteamApps != nullptr )
    {
      v13 = Steam3Client();
      v14 = v13->m_pSteamApps->GetCurrentGameLanguage(this: v13->m_pSteamApps);
      V_strncpy(pDest, pSrc: v14, maxLen: 64);
    }
    v15 = PchLanguageToELanguage(pchShortName: pDest);
    eAudioLanguage = v15;
    if ( v15 != k_Lang_English
      && v15 != k_Lang_None
      && PchLanguageToELanguage(pchShortName: initInfo.m_pLanguage) != v15 )
    {
      Key = KeyValues::FindKey(this: v11, keyName: "FileSystem", bCreate: false);
      v17 = KeyValues::FindKey(this: Key, keyName: "SearchPaths", bCreate: false);
      m_pMemory = nullptr;
      memset(&vSearchPaths, 0, sizeof(vSearchPaths));
      FirstValue = KeyValues::GetFirstValue(this: v17);
      if ( FirstValue != nullptr )
      {
        do
        {
          Name = KeyValues::GetName(this: FirstValue);
          v21 = KeyValues::GetString(this: FirstValue, keyName: nullptr, defaultValue: defaultValue);
          if ( _V_stricmp(s1: Name, s2: "game") == 0 && _V_strstr(s1: v21, search: "|gameinfo_path|") == nullptr )
          {
            v22 = (char *)MemAlloc_Alloc(nSize: 0x104u);
            szFullSearchPath = v22;
            LanguageShortName = GetLanguageShortName(eLang: eAudioLanguage);
            V_snprintf(pDest: v22, maxLen: 260, pFormat: "%s%c%s_%s%c", com_basedir, 92, v21, LanguageShortName, 92);
            CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int>>::AddToHead(
              this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&vSearchPaths,
              src: (vgui::TreeNode **)&szFullSearchPath);
          }
          FirstValue = KeyValues::GetNextValue(this: FirstValue);
        }
        while ( FirstValue != nullptr );
        m_Size = vSearchPaths.m_Size;
        m_pMemory = vSearchPaths.m_Memory.m_pMemory;
      }
      for ( i = 0; i < m_Size; ++i )
      {
        g_pFileSystem->AddSearchPath(this: g_pFileSystem, a2: m_pMemory[i], a3: "game", a4: PATH_ADD_TO_HEAD);
        free(pMem: m_pMemory[i]);
      }
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&vSearchPaths);
      v11 = modinfo;
    }
    KeyValues::deleteThis(this: v11);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10159290
// Name: __CreateCCvarQueryICvarQuery_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CCvarQuery *__cdecl _CreateCCvarQueryICvarQuery_interface()
{
  return &s_CvarQuery;
}

} // namespace engine_xlsp
