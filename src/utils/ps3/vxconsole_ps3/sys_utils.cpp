// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/vxconsole_ps3/sys_utils.cpp
// Functions: 26
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00412840
// Name: void Sys_SetRegistryPrefix(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_SetRegistryPrefix(const char *pPrefix)
{
  _snprintf_s(string: g_szRegistryPrefix, sizeInBytes: 0x100u, count: 0xFFFFFFFF, format: pPrefix);
}

//------------------------------------------------------------------------------
// Address: 0x00412860
// Name: Sys_SplitRegistryKey
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_SplitRegistryKey(const char *key, char *key0, char *key0Len)
{
  unsigned int v4; // edi
  int v5; // eax
  unsigned int v6; // esi

  if ( key == nullptr )
    return 0;
  v4 = strlen(key);
  if ( v4 == 0 )
    return 0;
  v5 = v4 - 1;
  v6 = -1;
  if ( (int)(v4 - 1) < 0 )
    return 0;
  do
  {
    if ( key[v5] == 92 )
      break;
    v6 = v5--;
  }
  while ( v5 >= 0 );
  if ( v6 == -1 )
    return 0;
  _snprintf_s(string: key0, sizeInBytes: v6, count: 0xFFFFFFFF, format: key);
  _snprintf_s(string: key0Len, sizeInBytes: v4 - v6 + 1, count: 0xFFFFFFFF, format: &key[v6]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004128E0
// Name: int Sys_SetRegistryString(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_SetRegistryString(const char *keyName, const char *value)
{
  char *v2; // edi
  int v3; // esi
  char key1[256]; // [esp+8h] [ebp-304h] BYREF
  char key0[256]; // [esp+108h] [ebp-204h] BYREF
  char keyBuff[256]; // [esp+208h] [ebp-104h] BYREF
  HKEY__ *hKey; // [esp+308h] [ebp-4h] BYREF

  strcpy_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: g_szRegistryPrefix);
  strcat_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: keyName);
  v2 = keyBuff;
  v3 = -2147483647;
  if ( strncmp(first: keyBuff, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v3 = -2147483646;
    v2 = &keyBuff[19];
  }
  else if ( strncmp(first: keyBuff, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v2 = &keyBuff[18];
  }
  if ( Sys_SplitRegistryKey(key: v2, key0, key0Len: key1) == 0
    || RegCreateKeyExA(
         hKey: (HKEY)v3,
         lpSubKey: key0,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: value != nullptr ? 131078 : 983103,
         lpSecurityAttributes: nullptr,
         phkResult: &hKey,
         lpdwDisposition: nullptr) != 0 )
  {
    return 0;
  }
  if ( RegSetValueExA(
         hKey,
         lpValueName: key1,
         Reserved: 0,
         dwType: 1u,
         lpData: (const BYTE *)value,
         cbData: strlen(value) + 1) != 0 )
  {
    RegCloseKey(hKey);
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412A10
// Name: int Sys_GetRegistryString(char const __near *,char __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_GetRegistryString(const char *keyName, char *value, const char *defValue, unsigned int valueLen)
{
  char *v4; // esi
  int v5; // edi
  char key1[256]; // [esp+Ch] [ebp-308h] BYREF
  char key0[256]; // [esp+10Ch] [ebp-208h] BYREF
  char keyBuff[256]; // [esp+20Ch] [ebp-108h] BYREF
  unsigned int len; // [esp+30Ch] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+310h] [ebp-4h] BYREF

  strcpy_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: g_szRegistryPrefix);
  strcat_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: keyName);
  v4 = keyBuff;
  if ( defValue != nullptr )
    _snprintf_s(string: value, sizeInBytes: valueLen, count: 0xFFFFFFFF, format: defValue);
  v5 = -2147483647;
  if ( strncmp(first: keyBuff, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v5 = -2147483646;
    v4 = &keyBuff[19];
  }
  else if ( strncmp(first: keyBuff, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v4 = &keyBuff[18];
  }
  if ( Sys_SplitRegistryKey(key: v4, key0, key0Len: key1) == 0
    || RegOpenKeyExA(hKey: (HKEY)v5, lpSubKey: key0, ulOptions: 0, samDesired: 0x20019u, phkResult: &hKey) != 0 )
  {
    return 0;
  }
  len = valueLen;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: key1,
         lpReserved: nullptr,
         lpType: nullptr,
         lpData: (LPBYTE)value,
         lpcbData: &len) != 0 )
  {
    RegCloseKey(hKey);
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412B40
// Name: int Sys_SetRegistryInteger(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_SetRegistryInteger(const char *keyName, int value)
{
  char *v2; // edi
  int v3; // esi
  char key1[256]; // [esp+8h] [ebp-304h] BYREF
  char key0[256]; // [esp+108h] [ebp-204h] BYREF
  char keyBuff[256]; // [esp+208h] [ebp-104h] BYREF
  HKEY__ *hKey; // [esp+308h] [ebp-4h] BYREF

  strcpy_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: g_szRegistryPrefix);
  strcat_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: keyName);
  v2 = keyBuff;
  v3 = -2147483647;
  if ( strncmp(first: keyBuff, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v3 = -2147483646;
    v2 = &keyBuff[19];
  }
  else if ( strncmp(first: keyBuff, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v2 = &keyBuff[18];
  }
  if ( Sys_SplitRegistryKey(key: v2, key0, key0Len: key1) == 0
    || RegCreateKeyExA(
         hKey: (HKEY)v3,
         lpSubKey: key0,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0x20006u,
         lpSecurityAttributes: nullptr,
         phkResult: &hKey,
         lpdwDisposition: nullptr) != 0 )
  {
    return 0;
  }
  if ( RegSetValueExA(hKey, lpValueName: key1, Reserved: 0, dwType: 4u, lpData: (const BYTE *)&value, cbData: 4u) != 0 )
  {
    RegCloseKey(hKey);
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412C50
// Name: int Sys_GetRegistryInteger(char const __near *,int,int __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_GetRegistryInteger(const char *keyName, int defValue, int *value)
{
  char *v3; // edi
  int v4; // esi
  char key1[256]; // [esp+Ch] [ebp-308h] BYREF
  char key0[256]; // [esp+10Ch] [ebp-208h] BYREF
  char keyBuff[256]; // [esp+20Ch] [ebp-108h] BYREF
  unsigned int len; // [esp+30Ch] [ebp-8h] BYREF
  HKEY__ *hKey; // [esp+310h] [ebp-4h] BYREF

  strcpy_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: g_szRegistryPrefix);
  strcat_s(_Dst: keyBuff, _SizeInBytes: 0x100u, _Src: keyName);
  v3 = keyBuff;
  *value = defValue;
  v4 = -2147483647;
  if ( strncmp(first: keyBuff, last: "HKEY_LOCAL_MACHINE", count: 0x12u) == 0 )
  {
    v4 = -2147483646;
    v3 = &keyBuff[19];
  }
  else if ( strncmp(first: keyBuff, last: "HKEY_CURRENT_USER", count: 0x11u) == 0 )
  {
    v3 = &keyBuff[18];
  }
  if ( Sys_SplitRegistryKey(key: v3, key0, key0Len: key1) == 0
    || RegOpenKeyExA(hKey: (HKEY)v4, lpSubKey: key0, ulOptions: 0, samDesired: 0x20019u, phkResult: &hKey) != 0 )
  {
    return 0;
  }
  len = 4;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: key1,
         lpReserved: nullptr,
         lpType: nullptr,
         lpData: (LPBYTE)value,
         lpcbData: &len) != 0 )
  {
    RegCloseKey(hKey);
    return 0;
  }
  RegCloseKey(hKey);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00412D70
// Name: void Sys_MessageBox(char const __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_MessageBox(const char *title, const char *format, ...)
{
  char msg[2048]; // [esp+0h] [ebp-800h] BYREF
  va_list ap; // [esp+810h] [ebp+10h] BYREF

  va_start(ap, format);
  vsprintf_s(string: msg, sizeInBytes: 0x800u, format, ap);
  MessageBoxA(hWnd: nullptr, lpText: msg, lpCaption: title, uType: 0x42000u);
}

//------------------------------------------------------------------------------
// Address: 0x00412DC0
// Name: void Sys_Free(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_Free(void *ptr)
{
  if ( ptr != nullptr )
    free(pMem: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x00412DE0
// Name: void Sys_Error(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void Sys_Error(const char *format, ...)
{
  char msg[1024]; // [esp+0h] [ebp-400h] BYREF
  va_list ap; // [esp+40Ch] [ebp+Ch] BYREF

  va_start(ap, format);
  vsprintf_s(string: msg, sizeInBytes: 0x400u, format, ap);
  MessageBoxA(hWnd: nullptr, lpText: msg, lpCaption: "FATAL ERROR", uType: 0x10u);
}

//------------------------------------------------------------------------------
// Address: 0x00412E20
// Name: bool Sys_SaveFile(char const __near *,void __near *,long,bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl Sys_SaveFile(const char *filename, void *buffer, unsigned int count, int bText)
{
  int *v4; // eax
  int v6; // esi
  int *v7; // eax
  char szError[260]; // [esp+4h] [ebp-104h] BYREF

  _sopen_s(
    pfh: &bText,
    path: filename,
    oflag: ((unsigned __int8)bText != 0 ? 0x4000 : 0x8000) | 0x302,
    shflag: 64,
    pmode: 384);
  if ( bText == -1 )
  {
    v4 = _errno();
    strerror_s(buffer: szError, sizeInTChars: 0x104u, errnum: *v4);
    Sys_Error(format: "Sys_SaveFile(): Error opening %s: %s", filename, szError);
    return 0;
  }
  else
  {
    v6 = _write(fh: bText, buf: buffer, cnt: count);
    if ( v6 == count )
    {
      _close(fh: bText);
      return 1;
    }
    else
    {
      v7 = _errno();
      Sys_Error(format: "Sys_SaveFile(): write failure %d, errno=%d", v6, *v7);
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412EE0
// Name: void Sys_NormalizePath(char __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_NormalizePath(char *path, bool forceToLower)
{
  signed int v2; // edi
  signed int i; // ecx
  char v4; // al

  v2 = strlen(path);
  for ( i = 0; i < v2; ++i )
  {
    v4 = path[i];
    if ( v4 == 47 )
    {
      path[i] = 92;
    }
    else if ( forceToLower && v4 >= 65 && v4 <= 90 )
    {
      path[i] = v4 + 32;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412F30
// Name: void Sys_AddFileSeperator(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_AddFileSeperator(char *path, unsigned int pathLen)
{
  if ( *path != 0 )
  {
    if ( path[strlen(path) - 1] != 92 )
      strcat_s(_Dst: path, _SizeInBytes: pathLen, _Src: "\\");
  }
  else
  {
    strcpy_s(_Dst: path, _SizeInBytes: pathLen, _Src: ".\\");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412F80
// Name: void Sys_StripFilename(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_StripFilename(const char *inpath, char *outpath, unsigned int outPathLen)
{
  unsigned int v3; // kr00_4
  int v4; // eax
  bool v5; // zf
  char v6; // cl

  strcpy_s(_Dst: outpath, _SizeInBytes: outPathLen, _Src: inpath);
  v3 = strlen(outpath);
  v4 = v3 - 1;
  v5 = v3 == 1;
  if ( (int)(v3 - 1) > 0 )
  {
    do
    {
      v6 = outpath[v4];
      if ( v6 == 92 )
        break;
      if ( v6 == 47 )
        break;
      if ( v6 == 58 )
        break;
      --v4;
    }
    while ( v4 > 0 );
    v5 = v4 == 0;
  }
  if ( v5 )
    *outpath = 0;
  else
    outpath[v4 + 1] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00412FE0
// Name: void Sys_StripExtension(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_StripExtension(const char *inpath, char *outpath, unsigned int outPathLen)
{
  unsigned int v3; // kr00_4
  int v4; // eax
  bool v5; // zf

  strcpy_s(_Dst: outpath, _SizeInBytes: outPathLen, _Src: inpath);
  v3 = strlen(outpath);
  v4 = v3 - 1;
  v5 = v3 == 1;
  if ( (int)(v3 - 1) > 0 )
  {
    do
    {
      if ( outpath[v4] == 46 )
        break;
      --v4;
    }
    while ( v4 > 0 );
    v5 = v4 == 0;
  }
  if ( !v5 && outpath[v4] == 46 )
    outpath[v4] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00413030
// Name: void Sys_StripPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_StripPath(const char *inpath, char *outpath, unsigned int outPathLen)
{
  const char *i; // eax
  char v4; // cl

  for ( i = &inpath[strlen(inpath)]; i != inpath; --i )
  {
    v4 = *(i - 1);
    if ( v4 == 92 )
      break;
    if ( v4 == 47 )
      break;
    if ( v4 == 58 )
      break;
  }
  strcpy_s(_Dst: outpath, _SizeInBytes: outPathLen, _Src: i);
}

//------------------------------------------------------------------------------
// Address: 0x00413080
// Name: void Sys_AddExtension(char const __near *,char __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_AddExtension(const char *extension, char *outpath, unsigned int outPathLen, bool bForce)
{
  char *i; // eax
  char v5; // cl

  if ( !bForce && *outpath != 0 )
  {
    for ( i = &outpath[strlen(outpath) - 1]; i != outpath; --i )
    {
      v5 = *i;
      if ( *i == 92 || v5 == 47 )
        break;
      if ( v5 == 46 )
        return;
    }
  }
  strcat_s(_Dst: outpath, _SizeInBytes: outPathLen, _Src: extension);
}

//------------------------------------------------------------------------------
// Address: 0x004130E0
// Name: int Sys_Exists(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_Exists(const char *filename)
{
  int result; // eax
  _iobuf *test; // [esp+0h] [ebp-4h] BYREF

  fopen_s(pfile: &test, file: filename, mode: "rb");
  result = (int)test;
  if ( test != nullptr )
  {
    fclose(stream: test);
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00413120
// Name: char __near * Sys_GetToken(char __near * __near *,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_GetToken(char **dataptr, int allowLineBreaks, int *numlines)
{
  char *v3; // eax
  int v4; // edi
  int v5; // esi
  char *v7; // ecx
  int i; // eax
  char v9; // al
  char v10; // dl
  char j; // cl
  char v12; // cl
  char v13; // al
  char *k; // ecx

  if ( numlines != nullptr )
    *numlines = 0;
  v3 = *dataptr;
  v4 = 0;
  v5 = 0;
  token_0[0] = 0;
  if ( v3 == nullptr )
  {
    *dataptr = nullptr;
    return token_0;
  }
  while ( 1 )
  {
LABEL_5:
    v7 = v3;
    for ( i = *v3; i <= 32; i = *++v7 )
    {
      if ( i == 10 )
      {
        if ( numlines != nullptr )
          ++*numlines;
        v5 = 1;
      }
      else if ( i == 0 )
      {
        *dataptr = nullptr;
        return token_0;
      }
    }
    if ( v5 != 0 && allowLineBreaks == 0 )
      goto LABEL_46;
    v9 = *v7;
    if ( *v7 != 47 )
      break;
    v10 = v7[1];
    if ( v10 == 47 )
    {
      v3 = v7 + 2;
      for ( j = v7[2]; j != 0; j = *++v3 )
      {
        if ( j == 10 )
          break;
      }
    }
    else
    {
      if ( v10 != 42 )
      {
LABEL_37:
        token_0[v4++] = v9;
        while ( 1 )
        {
          v9 = *++v7;
          if ( v9 == 10 )
            break;
          if ( v9 <= 32 )
            goto LABEL_43;
LABEL_36:
          if ( v4 < 1024 )
            goto LABEL_37;
        }
        if ( numlines != nullptr )
          ++*numlines;
LABEL_43:
        if ( v4 >= 1024 )
          v4 = 0;
        token_0[v4] = 0;
LABEL_46:
        *dataptr = v7;
        return token_0;
      }
      v3 = v7 + 2;
      v12 = v7[2];
      if ( v12 != 0 )
      {
        while ( v12 != 42 || v3[1] != 47 )
        {
          v12 = *++v3;
          if ( v12 == 0 )
            goto LABEL_5;
        }
        if ( *v3 != 0 )
          v3 += 2;
      }
    }
  }
  if ( v9 != 34 )
    goto LABEL_36;
  v13 = v7[1];
  for ( k = v7 + 2; v13 != 34; v13 = *k++ )
  {
    if ( v13 == 0 )
      break;
    if ( v4 < 1024 )
      token_0[v4++] = v13;
  }
  token_0[v4] = 0;
  *dataptr = k;
  return token_0;
}

//------------------------------------------------------------------------------
// Address: 0x00413290
// Name: unsigned long Sys_GetSystemTime(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Sys_GetSystemTime()
{
  _LARGE_INTEGER qwTime; // [esp+0h] [ebp-14h] BYREF
  _LARGE_INTEGER qwTicksPerSec; // [esp+8h] [ebp-Ch] BYREF
  float msecsPerTick; // [esp+10h] [ebp-4h]

  QueryPerformanceFrequency(lpFrequency: &qwTicksPerSec);
  msecsPerTick = 1000.0 / (double)qwTicksPerSec.QuadPart;
  QueryPerformanceCounter(lpPerformanceCount: &qwTime);
  return (__int64)((double)qwTime.QuadPart * msecsPerTick);
}

//------------------------------------------------------------------------------
// Address: 0x004132E0
// Name: unsigned long Sys_ColorScale(unsigned long,float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Sys_ColorScale(unsigned int color, float scale)
{
  int v2; // ecx
  int v3; // edx
  int v4; // eax

  v2 = (int)(float)((float)(unsigned __int8)color * scale);
  v3 = (int)(float)((float)BYTE1(color) * scale);
  v4 = (int)(float)((float)BYTE2(color) * scale);
  if ( v2 > 255 )
    LOBYTE(v2) = -1;
  if ( v3 > 255 )
    LOBYTE(v3) = -1;
  if ( v4 > 255 )
    LOBYTE(v4) = -1;
  return (unsigned __int8)v2 | (((unsigned __int8)v3 | ((unsigned __int8)v4 << 8)) << 8);
}

//------------------------------------------------------------------------------
// Address: 0x00413370
// Name: bool Sys_IsWildcardMatch(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Sys_IsWildcardMatch(const char *wildcardString, const char *stringToCheck, bool caseSensitive)
{
  const char *v3; // edi
  const char *v4; // esi
  char v5; // bl
  char i; // al
  char strChar; // [esp+7h] [ebp-1h]

  v3 = wildcardString;
  if ( _stricmp(dst: wildcardString, src: "*.*") == 0 || _stricmp(dst: wildcardString, src: "*") == 0 )
    return true;
  v4 = stringToCheck;
  for ( strChar = *stringToCheck; *v4 != 0; strChar = *v4 )
  {
    v5 = *v3;
    if ( *v3 == 0 )
      break;
    ++v4;
    ++v3;
    if ( !caseSensitive )
    {
      v5 = toupper(c: v5);
      strChar = toupper(c: strChar);
    }
    if ( v5 == 42 )
    {
      if ( *--v4 != 0 )
      {
        while ( !Sys_IsWildcardMatch(wildcardString: v3, stringToCheck: v4++, caseSensitive) )
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
// Address: 0x00413450
// Name: char __near * Sys_NumberToCommaString(__int64,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_NumberToCommaString(__int64 number, char *buffer, unsigned int bufferSize)
{
  int v3; // ecx
  char *v4; // edi
  char *v5; // eax
  int v6; // esi
  signed int v7; // eax
  char *i; // ecx
  char temp2[256]; // [esp+0h] [ebp-200h] BYREF
  char temp[256]; // [esp+100h] [ebp-100h] BYREF

  sprintf_s(string: temp, sizeInBytes: 0x100u, format: "%I64d", number);
  v3 = strlen(temp);
  v4 = &temp2[v3 + 255];
  v5 = temp2;
  if ( v3 > 0 )
  {
LABEL_2:
    v6 = 0;
    while ( v3 > 0 )
    {
      *v5 = *v4;
      ++v6;
      ++v5;
      --v4;
      --v3;
      if ( v6 >= 3 )
      {
        if ( v3 <= 0 )
          break;
        *v5++ = 44;
        goto LABEL_2;
      }
    }
  }
  *v5 = 0;
  v7 = strlen(temp2) - 1;
  for ( i = temp; v7 >= 0; --v7 )
    *i++ = temp2[v7];
  *i = 0;
  _snprintf_s(string: buffer, sizeInBytes: bufferSize, count: 0xFFFFFFFF, format: temp);
  return buffer;
}

//------------------------------------------------------------------------------
// Address: 0x00413520
// Name: void Sys_CreatePath(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Sys_CreatePath(const char *pInPath)
{
  _BYTE *v1; // eax
  _BYTE *v2; // esi
  _BYTE *v3; // eax
  char dirPath[260]; // [esp+4h] [ebp-104h] BYREF

  strcpy_s(_Dst: dirPath, _SizeInBytes: 0x104u, _Src: pInPath);
  if ( dirPath[0] == 92 && dirPath[1] == 92 )
    strchr(string: (unsigned __int8 *)&dirPath[1], chr: 0x5Cu);
  else
    strchr(string: (unsigned __int8 *)dirPath, chr: 0x5Cu);
  v2 = v1;
  if ( v1 != nullptr )
  {
    while ( 1 )
    {
      strchr(string: v2 + 1, chr: 0x5Cu);
      v2 = v3;
      if ( v3 == nullptr )
        break;
      *v3 = 0;
      CreateDirectoryA(lpPathName: dirPath, lpSecurityAttributes: nullptr);
      *v2 = 92;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004135B0
// Name: void __near * Sys_Alloc(int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl Sys_Alloc(int size)
{
  unsigned int v1; // esi
  void *v2; // edi

  if ( size == 0 )
    Sys_Error(format: "Sys_Alloc(): zero size");
  v1 = (size + 3) & 0xFFFFFFFC;
  v2 = operator new(nSize: v1);
  if ( v2 == nullptr )
    Sys_Error(format: "Sys_Alloc(): %d bytes not available", v1);
  _V_memset(dest: v2, fill: 0, count: v1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00413600
// Name: int Sys_LoadFile(char const __near *,void __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Sys_LoadFile(const char *filename, void **bufferptr, bool bText)
{
  int v3; // eax
  int *v4; // eax
  int v5; // edi
  int v6; // ebx
  unsigned int v7; // esi
  unsigned int v9; // ebx
  void *v10; // edi
  int v11; // ebx
  char szError[260]; // [esp+4h] [ebp-10Ch] BYREF
  _iobuf *pfile; // [esp+108h] [ebp-8h] BYREF
  int handle; // [esp+10Ch] [ebp-4h] BYREF

  *bufferptr = nullptr;
  fopen_s(&pfile, file: filename, mode: "rb");
  if ( pfile == nullptr )
    return -1;
  fclose(stream: pfile);
  _sopen_s(pfh: &handle, path: filename, oflag: bText ? 0x4000 : 0x8000, shflag: 32, pmode: 256);
  v3 = handle;
  if ( handle == -1 )
  {
    v4 = _errno();
    strerror_s(buffer: szError, sizeInTChars: 0x104u, errnum: *v4);
    Sys_Error(format: "Sys_LoadFile(): Error opening %s: %s", filename, szError);
    v3 = handle;
  }
  v5 = v3;
  if ( v3 == -1 )
  {
    v7 = -1;
  }
  else
  {
    v6 = _lseek(fh: v3, pos: 0, mthd: 1);
    v7 = _lseek(fh: v5, pos: 0, mthd: 2);
    _lseek(fh: v5, pos: v6, mthd: 0);
  }
  if ( v7 == -1 )
    Sys_Error(format: "Sys_Alloc(): zero size");
  v9 = (v7 + 4) & 0xFFFFFFFC;
  v10 = operator new(nSize: v9);
  if ( v10 == nullptr )
    Sys_Error(format: "Sys_Alloc(): %d bytes not available", v9);
  _V_memset(dest: v10, fill: 0, count: v9);
  v11 = _read(fh: handle, buf: v10, cnt: v7);
  _close(fh: handle);
  if ( bText )
  {
    *((_BYTE *)v10 + v11) = 0;
    *bufferptr = v10;
    return v11;
  }
  else
  {
    if ( v7 != v11 )
      Sys_Error(format: "Sys_LoadFile(): read failure");
    *((_BYTE *)v10 + v7) = 0;
    *bufferptr = v10;
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00413770
// Name: char __near * Sys_CopyString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Sys_CopyString(char *str)
{
  unsigned int v1; // eax
  unsigned int v2; // ebx
  void *v3; // esi

  v1 = strlen(str);
  v2 = v1 + 1;
  if ( v1 == -1 )
    Sys_Error(format: "Sys_Alloc(): zero size");
  v3 = operator new(nSize: (v2 + 3) & 0xFFFFFFFC);
  if ( v3 == nullptr )
    Sys_Error(format: "Sys_Alloc(): %d bytes not available", (v2 + 3) & 0xFFFFFFFC);
  _V_memset(dest: v3, fill: 0, count: (v2 + 3) & 0xFFFFFFFC);
  memcpy(dst: (unsigned __int8 *)v3, src: (unsigned __int8 *)str, count: v2);
  return (char *)v3;
}
