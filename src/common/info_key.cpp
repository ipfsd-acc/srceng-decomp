// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: common/info_key.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: char const __near * Info_ValueForKey(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Info_ValueForKey(const char *s, const char *key)
{
  int v2; // ecx
  const char *v3; // esi
  bool v4; // zf
  char v5; // al
  char *v6; // edx
  char v7; // al
  _BYTE *v8; // esi
  char *v9; // ecx
  char pkey[512]; // [esp+8h] [ebp-200h] BYREF

  v2 = (valueindex + 1) % 4;
  v3 = s;
  v4 = *s == 92;
  valueindex = v2;
  if ( v4 )
    v3 = s + 1;
  while ( 1 )
  {
    v5 = *v3;
    v6 = pkey;
    if ( *v3 != 92 )
      break;
LABEL_6:
    v7 = v3[1];
    v8 = v3 + 1;
    v9 = value[v2];
    *v6 = 0;
    if ( v7 != 92 )
    {
      do
      {
        if ( v7 == 0 )
          break;
        ++v8;
        *v9 = v7;
        v7 = *v8;
        ++v9;
      }
      while ( *v8 != 92 );
    }
    *v9 = 0;
    if ( _V_stricmp(s1: key, s2: pkey) == 0 )
      return value[valueindex];
    if ( *v8 == 0 )
      return (char *)defaultValue;
    v2 = valueindex;
    v3 = v8 + 1;
  }
  while ( v5 != 0 )
  {
    ++v3;
    *v6 = v5;
    v5 = *v3;
    ++v6;
    if ( *v3 == 92 )
      goto LABEL_6;
  }
  return (char *)defaultValue;
}

// ============================================================
// Overlay from xlspmastertest (Missing functions)
// ============================================================
namespace xlspmastertest {

//------------------------------------------------------------------------------
// Address: 0x004010C0
// Name: void Info_RemoveKey(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_RemoveKey(char *s, char *key)
{
  int v2; // eax
  char *v4; // edi
  char v5; // al
  char *v6; // ecx
  char v7; // al
  char *i; // ecx
  char value[512]; // [esp+4h] [ebp-400h] BYREF
  char pkey[512]; // [esp+204h] [ebp-200h] BYREF

  strstr(str1: (unsigned __int8 *)key, str2: "\\");
  if ( v2 == 0 )
  {
    while ( 1 )
    {
      v4 = s;
      if ( *s == 92 )
        ++s;
      v5 = *s;
      v6 = pkey;
      if ( *s != 92 )
        break;
LABEL_7:
      v7 = *++s;
      *v6 = 0;
      for ( i = value; v7 != 92; ++i )
      {
        if ( v7 == 0 )
          break;
        v7 = *++s;
      }
      *i = 0;
      if ( _V_stricmp(s1: key, s2: pkey) == 0 )
      {
        _V_strcpy(dest: v4, src: s);
        return;
      }
      if ( *s == 0 )
        return;
    }
    while ( v5 != 0 )
    {
      ++s;
      *v6 = v5;
      v5 = *s;
      ++v6;
      if ( *s == 92 )
        goto LABEL_7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401160
// Name: bool Info_IsKeyImportant(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Info_IsKeyImportant(const char *key)
{
  return *key == 42 || _V_stricmp(s1: key, s2: "tracker") == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00401190
// Name: char __near * Info_FindLargestKey(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Info_FindLargestKey(char *s)
{
  char *v1; // esi
  signed int v2; // ebx
  char i; // al
  char *v4; // ecx
  unsigned int v5; // kr00_4
  char v6; // al
  char *v7; // ecx
  bool v8; // zf
  unsigned int v9; // kr04_4
  char value[256]; // [esp+Ch] [ebp-200h] BYREF
  char key[256]; // [esp+10Ch] [ebp-100h] BYREF

  v1 = s;
  v2 = 0;
  largest_key[0] = 0;
  if ( *s == 92 )
    v1 = s + 1;
  for ( i = *v1; *v1 != 0; i = *v1 )
  {
    v4 = key;
    if ( i != 0 )
    {
      do
      {
        if ( i == 92 )
          break;
        ++v1;
        *v4 = i;
        i = *v1;
        ++v4;
      }
      while ( *v1 != 0 );
    }
    *v4 = 0;
    v5 = strlen(key);
    if ( *v1 == 0 )
      break;
    v6 = *++v1;
    v7 = value;
    if ( v6 != 0 )
    {
      do
      {
        if ( v6 == 92 )
          break;
        ++v1;
        *v7 = v6;
        v6 = *v1;
        ++v7;
      }
      while ( *v1 != 0 );
    }
    v8 = *v1 == 0;
    *v7 = 0;
    if ( !v8 )
      ++v1;
    v9 = strlen(value);
    if ( (int)(v9 + v5) > v2 && key[0] != 42 && _V_stricmp(s1: key, s2: "tracker") != 0 )
    {
      v2 = v9 + v5;
      V_strncpy(pDest: largest_key, pSrc: key, maxLen: 256);
    }
  }
  return largest_key;
}

//------------------------------------------------------------------------------
// Address: 0x004012A0
// Name: void Info_SetValueForStarKey(char __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_SetValueForStarKey(char *s, char *key, char *value, int maxsize)
{
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  char *v10; // esi
  char *v11; // ecx
  unsigned int v12; // eax
  char news[1024]; // [esp+4h] [ebp-404h] BYREF
  char *largekey; // [esp+404h] [ebp-4h]

  strstr(str1: (unsigned __int8 *)key, str2: "\\");
  if ( v4 == 0 )
  {
    strstr(str1: (unsigned __int8 *)value, str2: "\\");
    if ( v5 == 0 )
    {
      strstr(str1: (unsigned __int8 *)key, str2: "..");
      if ( v6 == 0 )
      {
        strstr(str1: (unsigned __int8 *)value, str2: "..");
        if ( v7 == 0 )
        {
          strstr(str1: (unsigned __int8 *)key, str2: "\"");
          if ( v8 == 0 )
          {
            strstr(str1: (unsigned __int8 *)value, str2: "\"");
            if ( v9 == 0 && strlen(key) <= 0x7F && strlen(value) <= 0x7F )
            {
              Info_RemoveKey(s, key);
              if ( value != nullptr && strlen(value) != 0 )
              {
                V_snprintf(pDest: news, maxLen: 1024, pFormat: "\\%s\\%s", key, value);
                if ( (int)(strlen(s) + strlen(news)) < maxsize )
                  goto LABEL_17;
                if ( Info_IsKeyImportant(key) )
                {
                  while ( 1 )
                  {
                    largekey = Info_FindLargestKey(s);
                    Info_RemoveKey(s, key: largekey);
                    if ( (int)(strlen(s) + strlen(news)) < maxsize )
                      break;
                    if ( *largekey == 0 )
                      return;
                  }
                  if ( *largekey != 0 )
                  {
LABEL_17:
                    v10 = &s[strlen(s)];
                    v11 = news;
                    while ( *v11 != 0 )
                    {
                      v12 = *v11++ & 0x7F;
                      if ( v12 > 0xD )
                        *v10++ = v12;
                    }
                    *v10 = 0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401490
// Name: void Info_SetValueForKey(char __near *,char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Info_SetValueForKey(char *s, char *key, char *value, int maxsize)
{
  if ( *key != 42 )
    Info_SetValueForStarKey(s, key, value, maxsize);
}

} // namespace xlspmastertest
