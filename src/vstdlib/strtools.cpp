// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vstdlib/strtools.cpp
// Functions: 1007
// ============================================================

#include "vstdlib\strtools.h"

//------------------------------------------------------------------------------
// Address: 0x3F60B5A0
// Name: Q_NormalizeUTF8
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_NormalizeUTF8(const char *a1, char *a2, int a3)
{
  return CStringNormalization::Normalize(a1: false, a2: a1, a3: a2, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F60C350
// Name: Q_strcat
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_strcat(const char *a1, char *Source, int a3)
{
  if ( a1 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( Source == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  return Q_strncpy(Destination: (char *)&a1[strlen(a1)], Source, Count: a3 - strlen(a1));
}

//------------------------------------------------------------------------------
// Address: 0x3F60C5A0
// Name: Q_strnicmp
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_strnicmp(int a1, int a2, int a3)
{
  if ( a3 < 0 )
    AssertMsgImplementation(a1: "Assertion Failed: n >= 0", 0, ".\\strtools.cpp", 349, &unk_3F665789, 0);
  if ( a1 == 0 )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( a2 == 0 )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( a3 > 0 )
    JUMPOUT(0x3F60C613);
  JUMPOUT(0x3F60C648);
}

//------------------------------------------------------------------------------
// Address: 0x3F60C880
// Name: Q_atof
// Source: json
//------------------------------------------------------------------------------
double __cdecl Q_atof(char *a1)
{
  char *v1; // esi
  int v2; // ecx
  double v3; // st7
  char v4; // al
  char *v5; // esi
  double v6; // st2
  double v7; // st2
  double v8; // rt0
  int v9; // eax
  double v10; // rt1
  double v11; // st2
  double v12; // st7
  double v13; // rt2
  double v14; // st2
  double v15; // st2
  double v16; // rtt
  double v17; // st2
  int v19; // edx
  int i; // ecx
  int v21; // eax
  unsigned int v22; // eax
  int v23; // ecx
  int v24; // [esp+Ch] [ebp-4h]

  v1 = a1;
  if ( a1 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( *a1 == 45 )
  {
    v2 = -1;
    v1 = a1 + 1;
  }
  else
  {
    v2 = 1;
  }
  v3 = 0.0;
  v24 = v2;
  if ( *v1 == 48 )
  {
    v4 = v1[1];
    if ( v4 == 120 || v4 == 88 )
    {
      v5 = v1 + 2;
      v6 = 65.0;
      while ( 1 )
      {
        v9 = *v5++;
        if ( (unsigned int)(v9 - 48) > 9 )
        {
          if ( (unsigned int)(v9 - 97) > 5 )
          {
            if ( (unsigned int)(v9 - 65) > 5 )
              return (float)(v3 * (double)v2);
            v16 = v6;
            v17 = v3;
            v12 = v16;
            v15 = v17 * 16.0 + (double)v9 - v16;
          }
          else
          {
            v13 = v6;
            v14 = v3;
            v12 = v13;
            v15 = v14 * 16.0 + (double)v9 - 97.0;
          }
          v7 = v15 + 10.0;
        }
        else
        {
          v10 = v6;
          v11 = v3;
          v12 = v10;
          v7 = v11 * 16.0 + (double)v9 - 48.0;
        }
        v8 = v7;
        v6 = v12;
        v3 = v8;
      }
    }
  }
  if ( *v1 == 39 )
    return (double)(v2 * v1[1]);
  v19 = -1;
  for ( i = 0; ; ++i )
  {
    while ( 1 )
    {
      v21 = *v1++;
      if ( v21 != 46 )
        break;
      v19 = i;
    }
    if ( (unsigned int)(v21 - 48) > 9 )
      break;
    v3 = v3 * 10.0 + (double)v21 - 48.0;
  }
  if ( v19 == -1 )
  {
    return (float)(v3 * (double)v24);
  }
  else
  {
    if ( i - v19 >= 8 )
    {
      v22 = ((unsigned int)(i - v19 - 8) >> 3) + 1;
      i -= 8 * v22;
      do
      {
        --v22;
        v3 = v3 / 10.0 / 10.0 / 10.0 / 10.0 / 10.0 / 10.0 / 10.0 / 10.0;
      }
      while ( v22 != 0 );
    }
    if ( i > v19 )
    {
      v23 = i - v19;
      do
      {
        --v23;
        v3 = v3 / 10.0;
      }
      while ( v23 != 0 );
    }
    return (float)(v3 * (double)v24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F60CA70
// Name: char const __near * Q_stristr(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Q_stristr(const char *a1, const char *a2)
{
  if ( a1 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( a2 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( a1 != nullptr && a2 != nullptr )
  {
    if ( *a1 != 0 )
      JUMPOUT(0x3F60CAD3);
    JUMPOUT(0x3F60CB44);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F60CB60
// Name: Q_stristr
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_stristr(const char *a1, int a2)
{
  KeyValues *v2; // ecx

  if ( a1 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( a2 != 0 )
    JUMPOUT(0x3F60CBAB);
  KeyValues::RecursiveLoadFromBuffer(
    this: v2,
    a2: nullptr,
    a3: a1,
    a4: (void (__cdecl *)(const char *))AssertMsgImplementation);
}

//------------------------------------------------------------------------------
// Address: 0x3F60CBC0
// Name: Q_strnistr
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl Q_strnistr(_BYTE *a1, char *a2, int a3)
{
  _BYTE *v3; // ebp
  char *v4; // esi
  int v5; // ebx
  char v6; // bl
  _BYTE *v7; // esi
  int v8; // edi
  int v9; // ebp
  int v11; // [esp+Ch] [ebp-4h]

  v3 = a1;
  if ( a1 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  v4 = a2;
  if ( a2 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( a1 == nullptr || a2 == nullptr )
    return nullptr;
  if ( *a1 != 0 )
  {
    while ( a3 > 0 )
    {
      v5 = tolower_0(C: *v4);
      if ( tolower_0(C: (char)*v3) == v5 )
      {
        v6 = v4[1];
        v7 = v4 + 1;
        v8 = a3 - 1;
        if ( v6 == 0 )
          return v3;
        v9 = v3 - v7 + 1;
        while ( v8 > 0 && v7[v9] != 0 )
        {
          v11 = tolower_0(C: (char)v7[v9]);
          if ( v11 != tolower_0(C: v6) )
          {
            if ( *v7 == 0 )
              return a1;
            v4 = a2;
            v3 = a1;
            goto LABEL_20;
          }
          v6 = *++v7;
          --v8;
          if ( v6 == 0 )
            return a1;
        }
        return nullptr;
      }
LABEL_20:
      --a3;
      a1 = ++v3;
      if ( *v3 == 0 )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F60CCF0
// Name: Q_strnchr
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl Q_strnchr(_BYTE *a1, char a2, int a3)
{
  _BYTE *result; // eax

  for ( result = a1; result < &a1[a3]; ++result )
  {
    if ( *result == 0 )
      break;
    if ( *result == a2 )
      return result;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F60CD20
// Name: Q_strnlen
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_strnlen(unsigned int a1, int a2)
{
  _BYTE *v2; // eax

  if ( a1 == 0 )
    return -1;
  if ( a2 < 0 )
    return -1;
  v2 = (_BYTE *)a1;
  if ( a1 >= a1 + a2 )
    return -1;
  while ( *v2 != 0 )
  {
    if ( (unsigned int)++v2 >= a1 + a2 )
      return -1;
  }
  return (int)&v2[-a1];
}

//------------------------------------------------------------------------------
// Address: 0x3F60CD50
// Name: Q_strncpy
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Q_strncpy(char *Destination, char *Source, int Count)
{
  bool v3; // zf
  char *result; // eax

  v3 = Count == 0;
  if ( Count < 0 )
  {
    AssertMsgImplementation(a1: "Assertion Failed: maxLen >= 0", 0, ".\\strtools.cpp", 747, &unk_3F66578C, 0);
    v3 = Count == 0;
  }
  if ( !v3 && Destination == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      109,
      &unk_3F665782,
      0);
  if ( Source == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  result = strncpy_0(Destination, Source, Count);
  if ( Count != 0 )
    Destination[Count - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60CDE0
// Name: Q_wcsncpy
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl Q_wcsncpy(wchar_t *Destination, wchar_t *Source, unsigned int a3)
{
  bool v3; // zf
  wchar_t *result; // eax

  v3 = a3 == 0;
  if ( (a3 & 0x80000000) != 0 )
  {
    AssertMsgImplementation(a1: "Assertion Failed: maxLenInBytes >= 0", 0, ".\\strtools.cpp", 760, &unk_3F66578D, 0);
    v3 = a3 == 0;
  }
  if ( !v3 && Destination == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      109,
      &unk_3F665782,
      0);
  if ( Source == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      102,
      &unk_3F665781,
      0);
  result = wcsncpy_0(Destination, Source, Count: a3 >> 1);
  if ( a3 >> 1 != 0 )
    Destination[(a3 >> 1) - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60CE70
// Name: Q_snprintf
// Source: json
//------------------------------------------------------------------------------
int Q_snprintf(char *Buffer, int a2, char *Format, ...)
{
  bool v3; // zf
  int result; // eax
  va_list va; // [esp+1Ch] [ebp+10h] BYREF

  va_start(va, Format);
  v3 = a2 == 0;
  if ( a2 < 0 )
  {
    AssertMsgImplementation(a1: "Assertion Failed: bufferLen >= 0", 0, ".\\strtools.cpp", 775, &unk_3F66578E, 0);
    v3 = a2 == 0;
  }
  if ( !v3 && Buffer == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      109,
      &unk_3F665782,
      0);
  if ( Format == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  result = _vsnprintf_0(Buffer, BufferCount: a2 - 1, Format, ArgList: va);
  if ( result < 0 )
    result = a2 - 1;
  Buffer[result] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60CFB0
// Name: Q_vsnprintfRet
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_vsnprintfRet(char *Buffer, int a2, char *Format, va_list ArgList, bool *a5)
{
  bool v5; // zf
  int result; // eax

  v5 = a2 == 0;
  if ( a2 <= 0 )
  {
    AssertMsgImplementation(a1: "Assertion Failed: bufferLen > 0", 0, ".\\strtools.cpp", 817, &unk_3F665790, 0);
    v5 = a2 == 0;
  }
  if ( !v5 && Buffer == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      109,
      &unk_3F665782,
      0);
  if ( Format == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  result = _vsnprintf_0(Buffer, BufferCount: a2 - 1, Format, ArgList);
  if ( a5 != nullptr )
    *a5 = result < 0;
  if ( result < 0 )
    result = a2 - 1;
  Buffer[result] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60D2D0
// Name: Q_pretifymem
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_pretifymem(
        CUtlMap<int,int,int> *a1@<ebx>,
        int a2,
        int a3,
        float a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        float a23,
        int a24,
        float a25)
{
  double v25; // st7
  double v26; // st7
  CUtlBuffer *v27; // eax
  float v28; // [esp+54h] [ebp+Ch]
  float v29; // [esp+54h] [ebp+Ch]

  if ( LOBYTE(a4) != 0 )
    v25 = 1024.0;
  else
    v25 = 1000.0;
  v28 = v25;
  v26 = v28;
  v27 = (CUtlBuffer *)(((_BYTE)dword_3F665F18 + 1) & 7);
  v29 = v28 * v28;
  dword_3F665F18 = (int)v27;
  KeyValues::ReadNameSymbols(
    buffer: v27,
    pNameSymbols: a1,
    a3: v26,
    a4: a2,
    a5: a3,
    a6: SLOBYTE(v29),
    a7: a5,
    a8: a6,
    a9: a7,
    a10: a8,
    a11: a9,
    a12: a10,
    a13: a11,
    a14: a12,
    a15: a13,
    a16: a14,
    a17: a15,
    a18: a16,
    a19: a17,
    a20: a18,
    a21: a19,
    a22: a20,
    a23: a21,
    a24: a22,
    a25: a23,
    a26: a24,
    a27: a25);
}

//------------------------------------------------------------------------------
// Address: 0x3F60D480
// Name: Q_pretifynum
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Q_pretifynum(__int64 ArgList)
{
  int v1; // edi
  char *v2; // edi
  int v3; // ebx
  _BYTE *v4; // esi
  int i; // eax
  int v6; // esi
  char *v7; // ecx
  char *v8; // edx
  char j; // al
  _BYTE v11[32]; // [esp+Ch] [ebp-20h] BYREF

  v1 = dword_3F665E10;
  dword_3F665E10 = ((_BYTE)dword_3F665E10 + 1) & 7;
  v2 = (char *)&unk_3F665D10 + 32 * v1;
  v3 = 0;
  v4 = v11;
  for ( i = Q_snprintf(Buffer: v2, a2: 32, Format: "%lld", ArgList) - 1; i >= 0; --i )
  {
    *v4++ = v2[i];
    if ( i != 0 && v2[i - 1] != 45 && ++v3 == 3 )
    {
      v3 = 0;
      *v4++ = 44;
    }
  }
  *v4 = 0;
  v6 = v4 - v11;
  v7 = &v2[v6 - 1];
  v8 = v11;
  v2[v6] = 0;
  for ( j = v11[0]; *v8 != 0; --v7 )
  {
    ++v8;
    *v7 = j;
    j = *v8;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F60D530
// Name: Q_UTF8ToUnicode
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_UTF8ToUnicode(LPCCH lpMultiByteStr, LPWSTR lpWideCharStr, unsigned int a3)
{
  int result; // eax

  if ( lpMultiByteStr == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( lpWideCharStr == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      109,
      &unk_3F665782,
      0);
  *lpWideCharStr = 0;
  result = MultiByteToWideChar(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpMultiByteStr,
             cbMultiByte: -1,
             lpWideCharStr,
             cchWideChar: a3 >> 1);
  lpWideCharStr[(a3 >> 1) - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60D5B0
// Name: Q_UnicodeToUTF8
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_UnicodeToUTF8(LPCWCH lpWideCharStr, LPSTR lpMultiByteStr, int cbMultiByte)
{
  int result; // eax

  if ( lpMultiByteStr == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( lpWideCharStr == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      102,
      &unk_3F665781,
      0);
  *lpMultiByteStr = 0;
  result = WideCharToMultiByte(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpWideCharStr,
             cchWideChar: -1,
             lpMultiByteStr,
             cbMultiByte,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: nullptr);
  lpMultiByteStr[cbMultiByte - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60DE60
// Name: Q_FileBase
// Source: json
//------------------------------------------------------------------------------
void __userpurge Q_FileBase(
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *> > *a1@<ecx>,
        KeyValues *const *a2,
        _BYTE *a3,
        int a4)
{
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *> > *v4; // ecx

  if ( a4 >= 1 )
  {
    CUtlVector<KeyValues *,CUtlMemory<KeyValues *>>::AddToTail(
      this: a1,
      a2: (void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation,
      src: a2,
      a4: a3);
  }
  else
  {
    AssertMsgImplementation(a1: "Assertion Failed: maxlen >= 1", 0, ".\\strtools.cpp", 1678, &unk_3F665798, 0);
    CUtlVector<KeyValues *,CUtlMemory<KeyValues *>>::AddToTail(
      this: v4,
      a2: (void (__cdecl *)(const char *, _DWORD, const char *, int, void *, _DWORD))AssertMsgImplementation,
      src: a2,
      a4: a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F60DFE0
// Name: Q_StripExtension
// Source: json
//------------------------------------------------------------------------------
char *__cdecl Q_StripExtension(char *Source, char *Destination, size_t Count)
{
  unsigned int v3; // edi
  CUtlRBTree<CUtlMap<int,int,int>::Node_t,int,CUtlMap<int,int,int>::CKeyLess> *v4; // ecx
  int v5; // edi
  char *result; // eax

  v3 = ((int (__cdecl *)(char *, int))loc_3F62AE90)(a1: Source, a2: 46);
  if ( v3 != 0
    && ((int (__cdecl *)(char *, int))loc_3F62AE90)(a1: Source, a2: 92) < v3
    && ((int (__cdecl *)(char *, int))loc_3F62AE90)(a1: Source, a2: 47) < v3
    && v3 + 1 > (unsigned int)Source )
  {
    v5 = v3 - (_DWORD)Source;
    if ( v5 < (int)(Count - 1) )
      return (char *)CUtlRBTree<CUtlMap<int,int,int>::Node_t,int,CUtlMap<int,int,int>::CKeyLess>::Find(
                       this: v4,
                       a2: v5,
                       search: (const CUtlRBTree<CUtlMap<int,int,int>::Node_t,int,CUtlMap<int,int,int>::CKeyLess> *)Source,
                       searcha: (CUtlMap<int,int,int>::Node_t *)Destination);
    else
      return (char *)CUtlRBTree<CUtlMap<int,int,int>::Node_t,int,CUtlMap<int,int,int>::CKeyLess>::Find(
                       this: v4,
                       a2: Count - 1,
                       search: (const CUtlRBTree<CUtlMap<int,int,int>::Node_t,int,CUtlMap<int,int,int>::CKeyLess> *)Source,
                       searcha: (CUtlMap<int,int,int>::Node_t *)Destination);
  }
  else
  {
    result = Destination;
    if ( Destination != Source )
      return Q_strncpy(Destination, Source, Count);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60E060
// Name: Q_DefaultExtension
// Source: json
//------------------------------------------------------------------------------
char __cdecl Q_DefaultExtension(const char *a1, _BYTE *a2, int a3)
{
  const char *v3; // ecx
  char result; // al

  if ( a1 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: path", 0, ".\\strtools.cpp", 1798, &unk_3F66579C, 0);
  if ( a3 < 1 )
    AssertMsgImplementation(a1: "Assertion Failed: pathStringLength >= 1", 0, ".\\strtools.cpp", 1799, &unk_3F66579D, 0);
  if ( a2 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: extension", 0, ".\\strtools.cpp", 1800, &unk_3F66579E, 0);
  if ( *a2 != 46 )
    AssertMsgImplementation(a1: "Assertion Failed: extension[0] == '.'", 0, ".\\strtools.cpp", 1801, &unk_3F66579F, 0);
  v3 = &a1[strlen(a1) - 1];
  for ( result = *v3; result != 92; result = *--v3 )
  {
    if ( result == 47 || v3 <= a1 )
      break;
    if ( result == 46 )
      return result;
  }
  return ((int (__cdecl *)(const char *, _BYTE *, int, int))Q_strncat)(a1, a2, a3, a4: -1);
}

//------------------------------------------------------------------------------
// Address: 0x3F60E140
// Name: Q_SetExtension
// Source: json
//------------------------------------------------------------------------------
char __cdecl Q_SetExtension(char *Source, _BYTE *a2, size_t Count)
{
  Q_StripExtension(Source, Destination: Source, Count);
  return Q_DefaultExtension(a1: Source, a2, a3: Count);
}

//------------------------------------------------------------------------------
// Address: 0x3F60E170
// Name: Q_StripFilename
// Source: json
//------------------------------------------------------------------------------
signed int __cdecl Q_StripFilename(const char *a1)
{
  signed int result; // eax
  char v2; // cl

  result = strlen(a1) - 1;
  if ( result > 0 )
  {
    do
    {
      v2 = a1[result];
      if ( v2 == 92 )
        break;
      if ( v2 == 47 )
        break;
      --result;
    }
    while ( result > 0 );
    a1[result] = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60E1B0
// Name: Q_FixSlashes
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl Q_FixSlashes(_BYTE *a1, char a2)
{
  _BYTE *result; // eax

  for ( result = a1; *result != 0; ++result )
  {
    if ( *result == 47 || *result == 92 )
      *result = a2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60E240
// Name: Q_StripLastDir
// Source: json
//------------------------------------------------------------------------------
char __cdecl Q_StripLastDir(char *Buffer, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // esi
  char v5; // al
  bool v6; // zf
  char v7; // al

  if ( *Buffer == 0 )
    return 0;
  Q_strnicmp(a1: (int)Buffer, a2: (int)"./", a3: 0x7FFFFFFF);
  if ( v2 == 0 )
    return 0;
  Q_strnicmp(a1: (int)Buffer, a2: (int)".\\", a3: 0x7FFFFFFF);
  if ( v3 == 0 )
    return 0;
  v4 = strlen(Buffer);
  if ( v4 >= a2 )
    AssertMsgImplementation(a1: "Assertion Failed: len < maxlen", 0, ".\\strtools.cpp", 1926, &unk_3F6657A0, 0);
  v5 = Buffer[v4 - 1];
  if ( v5 == 92 || v5 == 47 )
    --v4;
  v6 = v4 == 0;
  if ( v4 <= 0 )
  {
LABEL_14:
    if ( v6 )
      Q_snprintf(Buffer, a2, Format: ".%c", 92);
    return 1;
  }
  else
  {
    while ( 1 )
    {
      v7 = Buffer[v4 - 1];
      if ( v7 == 92 || v7 == 47 )
        break;
      if ( --v4 <= 0 )
      {
        v6 = v4 == 0;
        goto LABEL_14;
      }
    }
    Buffer[v4] = 0;
    Q_FixSlashes(a1: Buffer, a2: 92);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F60E3A0
// Name: Q_UnqualifiedFileName
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl Q_UnqualifiedFileName(const char *a1)
{
  unsigned int result; // eax
  char v2; // cl

  for ( result = (unsigned int)&a1[strlen(a1) - 1]; result > (unsigned int)a1; --result )
  {
    v2 = *(_BYTE *)(result - 1);
    if ( v2 == 92 )
      break;
    if ( v2 == 47 )
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60E3E0
// Name: Q_ComposeFileName
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F60E530
// Name: Q_GetFileExtension
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl Q_GetFileExtension(const char *a1)
{
  const char *result; // eax

  result = &a1[strlen(a1) - 1];
  if ( result == a1 )
    return nullptr;
  while ( *(result - 1) != 46 )
  {
    if ( --result == a1 )
      return nullptr;
  }
  if ( result == a1 || *result == 92 || *result == 47 )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60E580
// Name: Q_RemoveDotSlashes
// Source: json
//------------------------------------------------------------------------------
char __cdecl Q_RemoveDotSlashes(const char *a1)
{
  char *i; // eax
  const char *v2; // eax
  char *v3; // ecx
  int v4; // eax
  char v5; // cl
  bool v6; // zf
  char *v7; // eax
  const char *v8; // eax
  char v9; // cl
  char *j; // ecx

  for ( i = (char *)a1; *i != 0; ++i )
  {
    if ( *i == 47 || *i == 92 )
      *i = 92;
  }
  v2 = a1;
  v3 = (char *)a1;
  while ( *v2 != 0 )
  {
    if ( *v2 == 46 && v2[1] == 92 && (v2 == a1 || *(v2 - 1) != 46) )
      v2 += 2;
    else
      *v3++ = *v2++;
  }
  *v3 = 0;
  v4 = strlen(a1);
  if ( v4 > 2 && a1[v4 - 1] == 46 )
  {
    v6 = a1[v4 - 2] == 92;
    v7 = (char *)&a1[v4 - 2];
    if ( v6 )
      *v7 = v5;
  }
  v8 = a1;
  if ( *a1 == 0 )
    return 1;
  while ( 1 )
  {
    if ( *v8 == 46 && v8[1] == 46 && (v8 == a1 || *(v8 - 1) == 92) )
    {
      v9 = v8[2];
      if ( v9 == 0 || v9 == 92 )
        break;
    }
    ++v8;
LABEL_31:
    if ( *v8 == 0 )
      return 1;
  }
  for ( j = (char *)(v8 - 2); j >= a1; --j )
  {
    if ( *j == 92 )
    {
      memcpy_0(a1: j, Src: v8 + 2, Size: strlen(v8 + 2) + 1);
      v8 = a1;
      goto LABEL_31;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F60ECE0
// Name: Q_IsAbsolutePath
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl Q_IsAbsolutePath(_BYTE *a1)
{
  return sub_3F62B2A0(a1, a2: 58) != 0 || *a1 == 47 || *a1 == 92;
}

//------------------------------------------------------------------------------
// Address: 0x3F60EDB0
// Name: Q_StrSubstInPlace
// Source: json
//------------------------------------------------------------------------------
char __cdecl Q_StrSubstInPlace(char *Destination, size_t Count, char *SubStr, int a4, char a5)
{
  void *v5; // esp
  char v7[12]; // [esp+0h] [ebp-Ch] BYREF

  v5 = alloca(Count);
  if ( (unsigned __int8)Q_StrSubst(Str: Destination, SubStr, a3: a4, Destination: v7, a5: Count, a6: a5) == 0 )
    return 0;
  Q_strncpy(Destination, Source: v7, Count);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F60EE00
// Name: Q_StrSubst
// Source: json
//------------------------------------------------------------------------------
bool __cdecl Q_StrSubst(char *Str, char *SubStr, const char *a3, char *Destination, int a5, char a6)
{
  const char *v6; // ebp
  char *v7; // edi
  char *v9; // esi
  int v10; // edi
  char *v11; // eax
  int v12; // ebp
  int v13; // ecx
  char *v14; // eax
  int v15; // edx
  int v16; // ebp
  char *v17; // esi
  char *v18; // ecx
  const char *v19; // eax
  char *v20; // edi
  signed int v22; // ebp
  int v23; // [esp+10h] [ebp-Ch]
  unsigned int v24; // [esp+14h] [ebp-8h]
  unsigned int v25; // [esp+18h] [ebp-4h]
  char *Stra; // [esp+20h] [ebp+4h]

  v6 = SubStr;
  v25 = strlen(SubStr);
  v24 = strlen(a3);
  v7 = Destination;
  v9 = Destination;
  *Destination = 0;
  while ( 1 )
  {
    v10 = a5 + v7 - v9;
    Stra = Str;
    v11 = a6 != 0 ? strstr_0(Str, SubStr: v6) : (char *)Q_stristr(a1: Str, a2: v6);
    if ( v11 == nullptr )
      break;
    v23 = v11 - Str;
    v12 = v11 - Str;
    if ( v10 == 0 )
      return false;
    v13 = 0;
    if ( *Str != 0 )
    {
      v14 = Str;
      v15 = v9 - Str;
      while ( v12 > 0 )
      {
        if ( v13 == v10 - 1 )
        {
          v9[v13] = 0;
          return false;
        }
        v14[v15] = *v14;
        Str = Stra;
        ++v14;
        ++v13;
        --v12;
        if ( *v14 == 0 )
          break;
      }
    }
    v9[v13] = 0;
    if ( v23 > v10 - 1 )
      return false;
    v16 = v24;
    v17 = &v9[strlen(v9)];
    v18 = (char *)(a5 + Destination - v17);
    if ( v18 == nullptr )
      return false;
    v19 = a3;
    v20 = nullptr;
    if ( *a3 != 0 )
    {
      while ( 1 )
      {
        if ( v16 <= 0 )
        {
LABEL_18:
          Str = Stra;
          goto LABEL_19;
        }
        if ( v20 == v18 - 1 )
          break;
        v19[v17 - a3] = *v19;
        ++v19;
        ++v20;
        --v16;
        if ( *v19 == 0 )
          goto LABEL_18;
      }
      v17[(_DWORD)v20] = 0;
      return false;
    }
LABEL_19:
    v6 = SubStr;
    v17[(_DWORD)v20] = 0;
    v7 = Destination;
    Str += v25 + v23;
    v9 = &v17[v24];
  }
  v22 = strlen(Str);
  Q_strncpy(Destination: v9, Source: Str, Count: v10);
  return v22 <= v10 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F60F040
// Name: Q_SplitString2
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_SplitString2(char *Source, int a2, int a3, _DWORD *a4)
{
  _DWORD *v4; // esi
  bool v5; // sf
  int v6; // eax
  char *i; // ebx
  int v8; // esi
  int v9; // edi
  const char *v10; // ebp
  const char *v11; // eax
  unsigned int v12; // esi
  unsigned int v13; // eax
  int v14; // edi
  unsigned __int8 (__thiscall *v15)(_DWORD); // eax
  HANDLE ProcessHeap; // eax
  char *v17; // esi
  int v18; // eax
  char *v19; // eax
  int v20; // esi
  unsigned int v21; // eax
  _MEMORY_BASIC_INFORMATION Buffer; // [esp+Ch] [ebp-1Ch] BYREF

  v4 = a4;
  v5 = (int)a4[3] < 0;
  a4[4] = 0;
  if ( !v5 )
  {
    v6 = v4[1];
    if ( v6 != 0 )
    {
      (*(void (__thiscall **)(_DWORD, int, _DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v6, a3: 0);
      v4[1] = 0;
    }
    v4[2] = 0;
  }
  for ( i = Source; ; i = (char *)&v10[v12] )
  {
    v8 = 0;
    v9 = -1;
    v10 = nullptr;
    if ( a3 <= 0 )
      break;
    do
    {
      v11 = Q_stristr(a1: i, a2: *(const char **)(a2 + 4 * v8));
      if ( v11 != nullptr && (v10 == nullptr || v11 < v10) )
      {
        v9 = v8;
        v10 = v11;
      }
      ++v8;
    }
    while ( v8 < a3 );
    if ( v10 == nullptr )
      break;
    v12 = strlen(*(const char **)(a2 + 4 * v9));
    if ( v10 > i )
    {
      Source = (char *)sub_3F60EF80(Source: i);
      v13 = a4[1];
      if ( (unsigned int)&Source >= v13 && (unsigned int)&Source < v13 + 4 * a4[4] )
        AssertMsgImplementation(
          a1: "Assertion Failed: (&src < Base()) || (&src >= (Base() + Count()) )",
          0,
          "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
          623,
          &unk_3F66576C,
          0);
      ((void (__stdcall *)(char **))loc_3F607BC0)(a1: &Source);
    }
  }
  if ( *i != 0 )
  {
    v14 = strlen(i) + 1;
    if ( (dword_3F665D0C & 1) != 0 )
    {
      v18 = dword_3F665D08;
    }
    else
    {
      v15 = *(unsigned __int8 (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 96);
      dword_3F665D0C |= 1u;
      if ( v15(a1: g_pMemAllocSteam) != 0 )
      {
        ProcessHeap = GetProcessHeap();
        v17 = (char *)HeapAlloc(hHeap: ProcessHeap, dwFlags: 0, dwBytes: 0x104u);
        VirtualQuery(lpAddress: &unk_3F665878, lpBuffer: &Buffer, dwLength: 0x1Cu);
        GetModuleFileNameA(hModule: (HMODULE)Buffer.AllocationBase, lpFilename: v17, nSize: 0x104u);
        v18 = (int)v17;
        dword_3F665D08 = (int)v17;
      }
      else
      {
        v18 = 0;
        dword_3F665D08 = 0;
      }
    }
    if ( v18 != 0 )
      v19 = (char *)(*(int (__thiscall **)(_DWORD, int, int, _DWORD, int, _DWORD))(*g_pMemAllocSteam + 4))(
                      a1: g_pMemAllocSteam,
                      a2: v14,
                      a3: v18,
                      a4: 0,
                      a5: 1,
                      a6: 0);
    else
      v19 = (char *)(*(int (__thiscall **)(_DWORD, int))(*g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: v14);
    v20 = (int)v19;
    Q_strncpy(Destination: v19, Source: i, Count: v14);
    a3 = v20;
    v21 = a4[1];
    if ( (unsigned int)&a3 >= v21 && (unsigned int)&a3 < v21 + 4 * a4[4] )
      AssertMsgImplementation(
        a1: "Assertion Failed: (&src < Base()) || (&src >= (Base() + Count()) )",
        0,
        "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
        623,
        &unk_3F66576C,
        0);
    ((void (__stdcall *)(int *))loc_3F607BC0)(a1: &a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F60F250
// Name: Q_SplitString
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_SplitString(char *Source, int a2, _DWORD *a3)
{
  Q_SplitString2(Source, (int)&a2, a3: 1, a4: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F60F3C0
// Name: Q_StrSlice
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_StrSlice(const char *a1, int a2, int a3, char *a4, int a5)
{
  signed int v5; // eax
  int v6; // ecx
  int v7; // esi
  int v8; // eax
  size_t v9; // esi
  const char *v10; // ebx

  if ( a5 != 0 )
  {
    v5 = strlen(a1);
    v6 = a2;
    v7 = v5;
    if ( a2 >= 0 )
    {
      if ( a2 >= v5 )
      {
        *a4 = 0;
        return;
      }
    }
    else
    {
      v6 = v5 - -a2 % v5;
    }
    v8 = a3;
    if ( a3 >= 0 )
    {
      if ( a3 > v7 )
        v8 = a3 % v7;
    }
    else
    {
      v8 = v7 - -a3 % v7;
    }
    if ( v8 > v6 )
    {
      v9 = v8 - v6;
      v10 = &a1[v6];
      if ( v8 - v6 > a5 - 1 )
      {
        memcpy_1(a1: a4, Src: v10, Size: a5 - 1);
        a4[a5 - 1] = 0;
      }
      else
      {
        memcpy_1(a1: a4, Src: v10, Size: v9);
        a4[v9] = 0;
      }
    }
    else
    {
      *a4 = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F60F480
// Name: Q_StrLeft
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_StrLeft(const char *a1, int a2, char *a3, int a4)
{
  if ( a2 != 0 )
  {
    Q_StrSlice(a1, a2: 0, a3: a2, a4: a3, a5: a4);
  }
  else if ( a4 != 0 )
  {
    *a3 = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F60F4C0
// Name: Q_StrRight
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_StrRight(char *Source, int a2, char *Destination, size_t Count)
{
  if ( a2 < (int)strlen(Source) )
    Q_StrSlice(a1: Source, a2: -a2, a3: strlen(Source), a4: Destination, a5: Count);
  else
    Q_strncpy(Destination, Source, Count);
}

//------------------------------------------------------------------------------
// Address: 0x3F60F530
// Name: Q_StrTrim
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl Q_StrTrim(char *a1)
{
  char *v1; // esi
  char *i; // edi
  char v3; // al
  char *j; // ebx

  v1 = a1;
  for ( i = a1; *v1 != 0; ++v1 )
  {
    if ( isspace_0(C: *v1) == 0 )
      break;
  }
  v3 = *v1;
  for ( j = nullptr; *v1 != 0; ++i )
  {
    *i = v3;
    ++v1;
    if ( isspace_0(C: v3) != 0 )
    {
      if ( j == nullptr )
        j = i;
    }
    else
    {
      j = nullptr;
    }
    v3 = *v1;
  }
  *i = 0;
  if ( j != nullptr )
  {
    i = j;
    *j = 0;
  }
  return (_BYTE *)(i - a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F60F6C0
// Name: Q_strtowcs
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_strtowcs(LPCCH lpMultiByteStr, int cbMultiByte, LPWSTR lpWideCharStr, int cchWideChar)
{
  int result; // eax

  result = MultiByteToWideChar(CodePage: 0xFDE9u, dwFlags: 0, lpMultiByteStr, cbMultiByte, lpWideCharStr, cchWideChar);
  if ( result == 0 )
    *lpWideCharStr = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60F6F0
// Name: Q_wcstostr
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_wcstostr(LPCWCH lpWideCharStr, int cchWideChar, LPSTR lpMultiByteStr, int cbMultiByte)
{
  int result; // eax

  result = WideCharToMultiByte(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpWideCharStr,
             cchWideChar,
             lpMultiByteStr,
             cbMultiByte,
             lpDefaultChar: nullptr,
             lpUsedDefaultChar: nullptr);
  if ( result == 0 )
    *lpMultiByteStr = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60F7D0
// Name: Q_FormatAndAppend
// Source: json
//------------------------------------------------------------------------------
int __cdecl Q_FormatAndAppend(int a1, int a2)
{
  return Q_FormatAndAppendV(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F611BC0
// Name: public: void CUtlMemory<char __near *>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall CUtlMemory<char *>::Purge(CUtlMemory<char> *this@<ecx>, _DWORD *a2@<ebx>, _DWORD *a3@<esi>)
{
  CUtlVector<char,CUtlMemory<char> > *v3; // ecx
  void *v4; // [esp-Ch] [ebp-Ch]
  int v5; // [esp-8h] [ebp-8h]
  size_t v6; // [esp-4h] [ebp-4h]

  memset(a1: v4, Val: v5, Size: v6);
  v3 = (CUtlVector<char,CUtlMemory<char> > *)a3[5];
  a3[20] = a3[4];
  a3[21] = v3;
  CUtlVector<char,CUtlMemory<char>>::IsValidIndex(this: v3);
  *a2 = *a3;
  a2[1] = a3[1];
  a2[2] = a3[2];
  JUMPOUT(0x3F611BED);
}

//------------------------------------------------------------------------------
// Address: 0x3F615940
// Name: _Q_strcat
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_strcat(char a1@<bl>, int a2@<ebp>, int a3@<edi>)
{
  _DWORD *v3; // eax
  int v4; // ecx
  int i; // eax

  v3 = (_DWORD *)(*(int (__thiscall **)(_DWORD, int))(*g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: 16);
  *(_DWORD *)a2 = v3;
  *v3 = a3;
  *(_DWORD *)(*(_DWORD *)a2 + 4) = 0;
  v4 = dword_3F664280;
  *(_DWORD *)(*(_DWORD *)a2 + 8) = 0;
  *(_BYTE *)(*(_DWORD *)a2 + 12) = a1;
  for ( i = dword_3F66428C; *(_BYTE *)(i + v4) == 32; ++i )
    ;
  JUMPOUT(0x3F6159A6);
}

//------------------------------------------------------------------------------
// Address: 0x3F6159B0
// Name: _Q_wcscat
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_wcscat(int _EAX@<eax>, int a2@<edx>)
{
  *(_WORD *)(a2 + 102) = __ES__;
  __asm { aas }
  JUMPOUT(0x3F61588D);
}

//------------------------------------------------------------------------------
// Address: 0x3F615A20
// Name: _Q_strncmp
// Source: json
//------------------------------------------------------------------------------
char __usercall Q_strncmp@<al>(const char *a1@<ebx>, const char *s1)
{
  char v3; // bl
  char v4; // al
  int v5; // edx
  int v6; // ecx
  const char *v7; // [esp-8h] [ebp-Ch]
  int v8; // [esp-4h] [ebp-8h]
  int v9; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)s1 == 0 )
    return 0;
  v3 = Q_strncmp(s1: *(const char **)s1, s2: a1, count: v9);
  v4 = Q_strncmp(s1: (const char *)(*(_DWORD *)s1 + 4), s2: v7, count: v8);
  v5 = *(_DWORD *)s1;
  v6 = *(_DWORD *)(*(_DWORD *)s1 + 8);
  if ( v6 != 0 )
  {
    if ( v6 == 1 )
    {
      *(_BYTE *)(v5 + 12) = v4 == 0;
      *(_DWORD *)(*(_DWORD *)s1 + 8) = 2;
      return *(_BYTE *)(*(_DWORD *)s1 + 12);
    }
  }
  else
  {
    if ( *(_BYTE *)(v5 + 12) == 38 )
    {
      if ( v3 == 0 || v4 == 0 )
        JUMPOUT(0x3F615A9F);
    }
    else if ( v3 == 0 )
    {
      JUMPOUT(0x3F615A9B);
    }
    *(_BYTE *)(v5 + 12) = 1;
  }
  *(_DWORD *)(*(_DWORD *)s1 + 8) = 2;
  return *(_BYTE *)(*(_DWORD *)s1 + 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F615AA0
// Name: char __near * Q_strnlwr(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall Q_strnlwr@<al>(int a1@<edx>, int a2@<esi>)
{
  *(_DWORD *)(a1 + 9) = 2;
  return *(_BYTE *)(*(_DWORD *)a2 + 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F615B10
// Name: _Q_strncasecmp
// Source: json
//------------------------------------------------------------------------------
char __usercall Q_strncasecmp@<al>(int *_EAX@<eax>, int *a2@<ebx>)
{
  char v3; // [esp+1h] [ebp-1h]

  __asm { aas }
  if ( _EAX != a2 )
  {
    sub_3F615460(a1: _EAX);
    sub_3F615460(a1: (int *)(*(_DWORD *)s1 + 4));
    v3 = 0;
    (*(void (__thiscall **)(_DWORD, _DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: *(_DWORD *)s1);
    *(_DWORD *)s1 = a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F615BB0
// Name: _Q_strcasecmp
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F615BF0
// Name: _Q_strnicmp
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_strnicmp(const char *s1)
{
  CUtlBuffer *v1; // ecx
  _WORD *v2; // eax
  _WORD *v3; // edx
  int v4; // esi
  LPSTR v5; // eax

  if ( s1[8] != 0 )
  {
    v2 = *((_WORD **)s1 + 1);
    if ( v2 != nullptr && *(_DWORD *)s1 == 0 )
    {
      v3 = v2 + 1;
      do
        LOWORD(v1) = *v2++;
      while ( (_WORD)v1 != 0 );
      v4 = 4 * (v2 - v3) + 1;
      sub_3F609C70(this: v1);
      if ( Q_UnicodeToUTF8(lpWideCharStr: *((LPCWCH *)s1 + 1), lpMultiByteStr: v5, cbMultiByte: v4) != 0 )
        JUMPOUT(0x3F615C4A);
      JUMPOUT(0x3F615C8D);
    }
  }
  JUMPOUT(0x3F615CA1);
}

//------------------------------------------------------------------------------
// Address: 0x3F615C50
// Name: _Q_atoi
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge Q_atoi@<eax>(
        const char *a1@<eax>,
        int a2@<edx>,
        CUtlBuffer *a3@<ecx>,
        char **a4@<ebp>,
        char *a5@<edi>,
        const char *str)
{
  int v6; // esi
  char *v7; // eax
  char *v8; // ebx
  int result; // eax

  v6 = (int)&a1[strlen(a1) + 1 - a2 + 1];
  sub_3F609C70(this: a3);
  v8 = v7;
  Q_strncpy(Destination: v7, Source: a5, Count: v6);
  result = (*(int (__thiscall **)(_DWORD, char *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a5, a3: 1);
  *a4 = v8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F615FA0
// Name: _Q_stristr
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
char *__userpurge Q_stristr@<eax>(
        char *pStr,
        const char *pSearch,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}

//------------------------------------------------------------------------------
// Address: 0x3F615FD0
// Name: _Q_strnistr
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const char *__usercall Q_strnistr@<eax>(_DWORD *a1@<eax>, _DWORD *a2@<edx>, int a3@<ebx>, int a4@<edi>)
{
  const char *result; // eax
  const CHAR *v5; // [esp+4h] [ebp-10h]
  wchar_t *v6; // [esp+8h] [ebp-Ch]
  LPCWSTR lpPathName; // [esp+Ch] [ebp-8h]

  ++*a1;
  *(_BYTE *)(a3 - 2091904832) += (_BYTE)a1;
  *a2 = __ROL4__(*a2, 81);
  result = (const char *)Q_UTF8ToUnicode(lpMultiByteStr: v5, lpWideCharStr: v6, a3: (unsigned int)lpPathName);
  if ( result == nullptr )
    result = (const char *)AssertMsgImplementation(
                             a1: "Assertion Failed: cchResult",
                             0,
                             "..\\tier1\\fileio.cpp",
                             195,
                             &unk_3F6657DD,
                             0);
  *(_WORD *)(*(_DWORD *)(a4 + 4) + 65548) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6160D0
// Name: _Q_strnchr
// Source: json
//------------------------------------------------------------------------------
const char *__usercall Q_strnchr@<eax>(
        const char *result@<eax>,
        int a2@<edx>,
        int a3@<ebx>,
        int _EDI@<edi>,
        int a5@<esi>)
{
  bool v5; // cf

  v5 = __CFADD__(a2, *(_DWORD *)(result - 117));
  *(_DWORD *)(result - 117) += a2;
  BYTE1(a3) = -v5;
  __asm { rcr     byte ptr [edi-50h], 1 }
  *(_DWORD *)(a5 - 125) += a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F616130
// Name: _Q_strncpy
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_strncpy(
        void (__cdecl *a1)(int)@<eax>,
        int a2@<ecx>,
        int a3@<ebx>,
        const char *a4@<edi>,
        int a5@<esi>,
        char *pDest,
        const char *pSrc,
        int maxLen)
{
  CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *v8; // ecx
  CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *v9; // esi

  *(_DWORD *)(a3 + 407014161) |= a2;
  a1(a1: a5);
  if ( *a4 != 0 )
    v9 = CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>::CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>(
           this: v8,
           a2: a4);
  else
    v9 = nullptr;
  Q_StripFilename(a1: (const char *)v9);
  sub_3F617840();
  ((void (*)(void))loc_3F615F80)();
  CreateFileW(
    lpFileName: (LPCWSTR)pDest,
    dwDesiredAccess: 0x40000000u,
    dwShareMode: 0,
    lpSecurityAttributes: nullptr,
    dwCreationDisposition: 4u,
    dwFlagsAndAttributes: 0x80u,
    hTemplateFile: nullptr);
  Q_wcsncpy((wchar_t *)pDest, (const wchar_t *)pSrc, maxLenInBytes: maxLen);
}

//------------------------------------------------------------------------------
// Address: 0x3F616190
// Name: _Q_wcsncpy
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F6161F0
// Name: _Q_snprintf
// Source: json
//------------------------------------------------------------------------------
char __usercall Q_snprintf@<al>(
        void (*a1)(void)@<eax>,
        int a2@<edi>,
        int a3@<esi>,
        char *pDest,
        int maxLen,
        const char *pFormat,
        ...)
{
  a1();
  if ( a2 != 0 )
    (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2, a3: 1);
  if ( a3 != 0 )
    (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a3, a3: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F616260
// Name: _Q_vsnprintf
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_vsnprintf(
        CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *a1@<ecx>,
        const char *a2@<edi>,
        char *pDest,
        int maxLen,
        const char *pFormat,
        char *params,
        int a7,
        const wchar_t *lpFileName)
{
  CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *v8; // esi

  if ( *a2 != 0 )
    v8 = CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>::CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>(
           this: a1,
           a2);
  else
    v8 = nullptr;
  Q_StripFilename(a1: (const char *)v8);
  sub_3F617840();
  ((void (*)(void))loc_3F615F80)();
  if ( CreateFileW(
         lpFileName,
         dwDesiredAccess: 0x40000000u,
         dwShareMode: 0,
         lpSecurityAttributes: nullptr,
         dwCreationDisposition: 2u,
         dwFlagsAndAttributes: 0x80u,
         hTemplateFile: nullptr) == (HANDLE)-1 )
    JUMPOUT(0x3F6162C6);
  JUMPOUT(0x3F616306);
}

//------------------------------------------------------------------------------
// Address: 0x3F6162D0
// Name: _Q_vsnprintfRet
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall Q_vsnprintfRet@<al>(int a1@<ebx>)
{
  void *retaddr; // [esp+0h] [ebp+0h]

  (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a1, a3: 1);
  if ( retaddr != nullptr )
    (*(void (__thiscall **)(_DWORD, void *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: retaddr, a3: 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F616350
// Name: _Q_strncat
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall Q_strncat@<al>(int _EAX@<eax>, _DWORD *a2@<ecx>, int a3@<ebx>)
{
  void *retaddr; // [esp+0h] [ebp+0h]

  __asm { aas }
  (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*a2 + 24))(a1: *a2, a2: a3 + 1, a3: 1);
  if ( retaddr != nullptr )
    (*(void (__thiscall **)(_DWORD, void *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: retaddr, a3: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6165A0
// Name: PretifyWorker
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall PretifyWorker(char *pchOutput@<edx>, char a2@<cf>, void (*a3)(void)@<eax>, char a4@<ch>)
{
  void *retaddr; // [esp+4h] [ebp+0h]

  pchOutput[1] -= a2 + a4;
  a3();
  if ( retaddr != nullptr )
    (*(void (__thiscall **)(_DWORD, void *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: retaddr, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6166C0
// Name: _Q_pretifynum
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall Q_pretifynum@<al>(int _EAX@<eax>, int a2@<edx>, _DWORD *a3@<ecx>, int a4@<ebx>)
{
  bool v4; // cf

  *(_BYTE *)(a4 - 2062539708) = __ROR1__(*(_BYTE *)(a4 - 2062539708), 1);
  v4 = __CFSHL__(*(_BYTE *)(2 * a2 - 117), 13);
  *(_BYTE *)(2 * a2 - 117) = 0;
  *(_BYTE *)(a4 + 101) += _EAX + v4;
  __asm { aas }
  (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*a3 + 24))(a1: *a3, a2: _EAX, a3: 1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F6168F0
// Name: _Q_UnicodeToUTF8
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall Q_UnicodeToUTF8@<al>(char a1@<cf>, int a2@<eax>, int a3@<edx>, int a4@<ebp>)
{
  *(_DWORD *)(a3 + 1) += a4 + a1;
  (*(void (__cdecl **)(int))(a3 + 24))(a1: a2);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F616940
// Name: _Q_NormalizeUTF8Old
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_NormalizeUTF8Old(char a1@<cf>, int _EAX@<eax>, _DWORD *a3@<ecx>, int a4@<ebx>)
{
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h]

  *(_BYTE *)(a4 + 101) += _EAX + a1;
  __asm { aas }
  (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*a3 + 24))(a1: *a3, a2: _EAX, a3: 1);
  if ( retaddr != nullptr )
    JUMPOUT(0x3F6169CD);
  JUMPOUT(0x3F6169D5);
}

//------------------------------------------------------------------------------
// Address: 0x3F6169D0
// Name: _Q_NormalizeUTF8
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __fastcall Q_NormalizeUTF8(int a1, int a2)
{
  (*(void (**)(void))(a2 + 24))();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F6169F0
// Name: _Q_StripPrecedingAndTrailingWhitespace
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __cdecl Q_StripPrecedingAndTrailingWhitespace(char *pch, char *pcha, const wchar_t *a3)
{
  const wchar_t *v3; // esi
  DWORD FileAttributesW; // eax
  DWORD v5; // ebx
  void *retaddr; // [esp+0h] [ebp+0h]

  ((void (*)(void))loc_3F615F80)();
  v3 = a3;
  FileAttributesW = GetFileAttributesW(lpFileName: a3);
  v5 = FileAttributesW;
  if ( FileAttributesW == -1 )
  {
    if ( a3 != nullptr )
      (*(void (__thiscall **)(_DWORD, const wchar_t *, int))(*g_pMemAllocSteam + 24))(
        a1: g_pMemAllocSteam,
        a2: a3,
        a3: 1);
    if ( retaddr != nullptr )
      (*(void (__thiscall **)(_DWORD, void *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: retaddr, a3: 1);
    return 0;
  }
  else
  {
    if ( (FileAttributesW & 3) != 0 )
    {
      ((void (*)(void))loc_3F615F80)();
      v3 = a3;
      SetFileAttributesW(lpFileName: a3, dwFileAttributes: v5 & 0xFFFFFFFC);
    }
    if ( v3 != nullptr )
      (*(void (__thiscall **)(_DWORD, const wchar_t *, int))(*g_pMemAllocSteam + 24))(
        a1: g_pMemAllocSteam,
        a2: v3,
        a3: 1);
    if ( retaddr != nullptr )
      (*(void (__thiscall **)(_DWORD, void *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: retaddr, a3: 1);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F616B30
// Name: Q_nibble
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_nibble(int a1@<ebp>, const char *a2, int a3, unsigned __int8 *a4, int a5)
{
  if ( a1 == 0 )
    JUMPOUT(0x3F616BE8);
  Q_hextobinary(in: a2, numchars: a3, out: a4, maxoutputbytes: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F616B60
// Name: _Q_hextobinary
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_hextobinary(
        char a1@<bl>,
        char *a2@<ebp>,
        const wchar_t *a3@<edi>,
        const char *in,
        int numchars,
        unsigned __int8 *out,
        char *maxoutputbytes,
        int a8)
{
  char *v8; // [esp-270h] [ebp-270h]
  _DWORD v9[2]; // [esp-26Ch] [ebp-26Ch] BYREF
  char *v10; // [esp-264h] [ebp-264h]
  SYSTEMTIME v11[5]; // [esp-260h] [ebp-260h] BYREF
  wchar_t v12[6]; // [esp-208h] [ebp-208h] BYREF
  wchar_t v13[254]; // [esp-1FCh] [ebp-1FCh] BYREF

  *a2 = 0;
  if ( GetDateFormatW(
         Locale: 0x400u,
         dwFlags: 2u,
         lpDate: (const SYSTEMTIME *)&v11[0].wSecond,
         lpFormat: a3,
         lpDateStr: v13,
         cchDate: 260) != 0 )
  {
    *(_DWORD *)&v11[0].wYear = a3;
    *(_DWORD *)&v11[0].wDayOfWeek = v13;
    LOBYTE(v11[0].wHour) = 1;
    Q_strnicmp(s1: (const char *)v11);
    Q_strncpy(Destination: a2, Source: v10, Count: a8);
    if ( LOBYTE(v11[0].wDayOfWeek) != 0 )
      (*(void (__thiscall **)(_DWORD, char *))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v10);
    else
      (*(void (__thiscall **)(_DWORD, _DWORD))(*g_pMemAllocSteam + 24))(
        a1: g_pMemAllocSteam,
        a2: *(_DWORD *)&v11[0].wYear);
    if ( maxoutputbytes == (char *)a3 )
      JUMPOUT(0x3F616C9B);
    *maxoutputbytes = 0;
    if ( GetTimeFormatW(
           Locale: 0x400u,
           dwFlags: a1 != 0 ? 0 : 2,
           lpTime: v11,
           lpFormat: a3,
           lpTimeStr: v12,
           cchTime: 260) != 0 )
    {
      v9[0] = a3;
      v9[1] = v12;
      LOBYTE(v10) = 1;
      Q_strnicmp(s1: (const char *)v9);
      Q_strncpy(Destination: maxoutputbytes, Source: v8, Count: (int)maxoutputbytes);
      JUMPOUT(0x3F616C5F);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F616C60
// Name: _Q_binarytohex
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_binarytohex(char a1@<cf>, char a2@<sf>, char a3@<of>, _BYTE *a4@<eax>)
{
  bool v4; // zf

  if ( a2 != a3 )
    JUMPOUT(0x3F616C89);
  v4 = *a4 == (unsigned __int8)(a1 + (_BYTE)a4);
  *a4 -= a1 + (_BYTE)a4;
  if ( v4 )
    (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
  else
    (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
}

//------------------------------------------------------------------------------
// Address: 0x3F616D10
// Name: _Q_FileBase
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_FileBase(char a1@<cf>, int a2@<esi>)
{
  *(_BYTE *)(a2 - 779943784) += a1 + 2;
}

//------------------------------------------------------------------------------
// Address: 0x3F616E30
// Name: _Q_StripTrailingSlash
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_StripTrailingSlash(char a1@<cf>, _DWORD *a2@<eax>, int a3@<ecx>, int a4@<edi>)
{
  _BYTE v4[4]; // [esp-Ch] [ebp-Ch] BYREF
  int v5; // [esp-8h] [ebp-8h]

  *(_DWORD *)((char *)&g_pMemAllocSteam + a3) += &v4[a1];
  (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*a2 + 24))(a1: *a2, a2: a4, a3: 1);
  if ( v5 != 0 )
    (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v5, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F616E90
// Name: _Q_StripExtension
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_StripExtension(
        int a1@<edx>,
        char a2@<ch>,
        int a3@<ebx>,
        const wchar_t *a4@<edi>,
        char *in,
        char *out,
        unsigned int outSize)
{
  HANDLE FileW; // eax
  void *v8; // esi
  BOOL FileTime; // edi
  char *v10; // edi
  int v11; // ebx
  DWORD v12; // [esp-14h] [ebp-14h]
  DWORD v13; // [esp-10h] [ebp-10h]
  void *v14; // [esp-Ch] [ebp-Ch]
  int v16; // [esp-8h] [ebp-8h]

  *(_BYTE *)(a1 + 3) += a2;
  FileW = CreateFileW(
            lpFileName: a4,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 1u,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: v12,
            dwFlagsAndAttributes: v13,
            hTemplateFile: v14);
  v8 = FileW;
  if ( FileW == (HANDLE)-1 )
  {
    if ( a4 != nullptr )
      (*(void (__thiscall **)(_DWORD, const wchar_t *, int))(*g_pMemAllocSteam + 24))(
        a1: g_pMemAllocSteam,
        a2: a4,
        a3: 1);
    if ( v16 != 0 )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
  }
  else
  {
    FileTime = GetFileTime(
                 hFile: FileW,
                 lpCreationTime: nullptr,
                 lpLastAccessTime: nullptr,
                 lpLastWriteTime: (LPFILETIME)&out);
    CloseHandle(hObject: v8);
    if ( FileTime )
    {
      v10 = out + 717324288;
      v11 = (__PAIR64__((unsigned int)&out[(unsigned __int64)outSize << 32] >> 32, (unsigned int)out)
           - 116444736000000000LL) >> 32;
      ((void (__cdecl *)(int))sub_3F615F30)(a1: a3);
      ((void (__cdecl *)(char *, int, int, _DWORD))&GS_ContextRecord.ExtendedRegisters[172])(
        a1: v10,
        a2: v11,
        a3: 10000000,
        a4: 0);
    }
    else
    {
      sub_3F615F30();
      Q_DefaultExtension(path: in, extension: out, pathStringLength: outSize);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F616F10
// Name: _Q_DefaultExtension
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl Q_DefaultExtension()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F617040
// Name: _Q_SetExtension
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_SetExtension(int a1@<eax>, int a2@<ebp>, char *path, const char *extension)
{
  *(_BYTE *)(a1 + 2 * a2 - 123) = 0;
  if ( extension != nullptr )
    JUMPOUT(0x3F617067);
  JUMPOUT(0x3F617073);
}

//------------------------------------------------------------------------------
// Address: 0x3F617070
// Name: _Q_StripFilename
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_StripFilename(_DWORD *a1@<ecx>, int a2@<ebp>, int a3@<edi>)
{
  void *retaddr; // [esp+0h] [ebp+0h]

  *(_BYTE *)(a2 - 1961724673) = __ROL1__(*(_BYTE *)(a2 - 1961724673), 1);
  (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*a1 + 24))(a1: *a1, a2: a3, a3: 1);
  if ( retaddr != nullptr )
    (*(void (__thiscall **)(_DWORD, void *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: retaddr, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6170B0
// Name: _Q_FixSlashes
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_FixSlashes(_DWORD *a1@<ecx>, int a2@<edi>, int a3@<esi>)
{
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h]

  (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*a1 + 24))(a1: *a1, a2: a3, a3: 1);
  if ( retaddr != nullptr )
    JUMPOUT(0x3F6170D9);
  if ( a2 != 0 )
    JUMPOUT(0x3F6170DF);
  JUMPOUT(0x3F6170F1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6170E0
// Name: _Q_StripLastDir
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __usercall Q_StripLastDir@<al>(_DWORD *a1@<ecx>, int a2@<edi>)
{
  void *retaddr; // [esp+14h] [ebp+0h]

  (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*a1 + 24))(a1: *a1, a2, a3: 1);
  if ( retaddr != nullptr )
    (*(void (__thiscall **)(_DWORD, void *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: retaddr, a3: 1);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x3F6171B0
// Name: _Q_UnqualifiedFileName
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_UnqualifiedFileName(char a1@<cf>, int a2@<eax>, char a3@<ch>)
{
  LOBYTE(a2) = a1 + a2 + 106;
  *(_BYTE *)(a2 - 128) += a3;
  JUMPOUT(0x3F6171B5);
}

//------------------------------------------------------------------------------
// Address: 0x3F6171F0
// Name: _Q_ComposeFileName
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_ComposeFileName(_DWORD *a1@<edx>, int a2@<edi>)
{
  int v2; // [esp-8h] [ebp-8h]

  (*(void (__thiscall **)(_DWORD, int, int, _DWORD))(*(_DWORD *)*a1 + 24))(
    a1: *a1,
    a2,
    a3: 1,
    a4: *(_DWORD *)(2 * (_DWORD)a1 - 117));
  if ( v2 != 0 )
    (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
}

//------------------------------------------------------------------------------
// Address: 0x3F6172E0
// Name: _Q_ExtractFilePath
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_ExtractFilePath(int a1@<eax>, char a2@<dl>, int a3@<ecx>, _BYTE *a4@<edi>)
{
  *(_BYTE *)(a3 - 24) ^= a2;
  if ( a1 >= 0 )
  {
    *a4 &= a3;
    JUMPOUT(0x3F6172EE);
  }
  JUMPOUT(0x3F61730E);
}

//------------------------------------------------------------------------------
// Address: 0x3F617370
// Name: _Q_ExtractFileExtension
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_ExtractFileExtension(
        _MEMORY_BASIC_INFORMATION *a1@<eax>,
        char *a2@<esi>,
        const char *path,
        char *dest,
        int destSize,
        int a6,
        int a7,
        int a8,
        HMODULE a9)
{
  SIZE_T v9; // [esp-4h] [ebp-4h]

  LOBYTE(a1) = (unsigned __int8)a1 & 0x1C;
  VirtualQuery(lpAddress: &unk_3F665878, lpBuffer: a1, dwLength: v9);
  GetModuleFileNameA(hModule: a9, lpFilename: a2, nSize: 0x104u);
  dword_3F665D08 = (int)a2;
  JUMPOUT(0x3F6173A7);
}

//------------------------------------------------------------------------------
// Address: 0x3F6173A0
// Name: _Q_GetFileExtension
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_GetFileExtension(int a1@<edi>)
{
  if ( dword_3F665D08 != 0 )
    (*(void (__thiscall **)(_DWORD, int, int, _DWORD, int))(*g_pMemAllocSteam + 4))(
      a1: g_pMemAllocSteam,
      a2: a1,
      a3: dword_3F665D08,
      a4: 0,
      a5: 1);
  else
    (*(void (__thiscall **)(_DWORD, int, _DWORD))(*g_pMemAllocSteam + 8))(
      a1: g_pMemAllocSteam,
      a2: a1,
      a3: (unsigned __int16)__ES__);
  JUMPOUT(0x3F6173E9);
}

//------------------------------------------------------------------------------
// Address: 0x3F6173F0
// Name: _Q_RemoveDotSlashes
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall Q_RemoveDotSlashes@<al>(int a1@<ebp>)
{
  bool v1; // bl
  char v2; // bl
  int v4; // [esp-448h] [ebp-448h]
  const wchar_t *v5; // [esp-43Ch] [ebp-43Ch]
  intptr_t v6[264]; // [esp-420h] [ebp-420h] BYREF

  if ( (*(_DWORD *)v6[6] & 0x10) != 0 )
  {
    ((void (__cdecl *)(int))loc_3F6172D0)(a1);
  }
  else if ( (unsigned __int8)sub_3F616F60() == 0 )
  {
    ((void (__cdecl *)(int))loc_3F615EB0)(a1);
    ((void (*)(void))loc_3F615F80)();
    v1 = GetFileAttributesW(lpFileName: v5) != -1;
    if ( v5 != nullptr )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
    if ( v4 != 0 )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
    if ( v1 )
    {
      sub_3F6169E0();
      sub_3F616F60();
    }
  }
  (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a1, a3: 1);
  if ( sub_3F618210(a1: (int)v6) != 0 )
    JUMPOUT(0x3F617300);
  v2 = sub_3F617230();
  if ( (v6[3] & v6[2]) != -1 )
    _findclose(FindHandle: v6[2]);
  if ( v6[4] != 0 )
    (*(void (__thiscall **)(_DWORD, intptr_t, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v6[4], a3: 1);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F617510
// Name: _Q_ReplaceBadFilenameCharacters
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_ReplaceBadFilenameCharacters(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        const char *pchFileName,
        char cReplacementCharacter,
        char *pchOut)
{
  unsigned __int8 (__thiscall *v7)(_DWORD, int, int, int, int); // eax
  HANDLE ProcessHeap; // eax
  intptr_t v9[5]; // [esp-420h] [ebp-420h] BYREF
  char v10; // [esp-40Ch] [ebp-40Ch] BYREF

  ((void (*)(void))loc_3F617E90)();
  if ( (unsigned __int8)sub_3F617840() != 0 )
  {
    if ( sub_3F618210(a1: (int)v9) != 0 )
    {
      strlen(pchOut);
      strlen(&v10);
      if ( (dword_3F665D0C & 1) == 0 )
      {
        v7 = *(unsigned __int8 (__thiscall **)(_DWORD, int, int, int, int))(*g_pMemAllocSteam + 96);
        dword_3F665D0C |= 1u;
        if ( v7(a1: g_pMemAllocSteam, a2: a3, a3: a4, a4: a2, a5: a1) != 0 )
        {
          ProcessHeap = GetProcessHeap();
          HeapAlloc(hHeap: ProcessHeap, dwFlags: 0, dwBytes: 0x104u);
          JUMPOUT(0x3F6175F2);
        }
        JUMPOUT(0x3F617613);
      }
      JUMPOUT(0x3F61761D);
    }
    JUMPOUT(0x3F6177BC);
  }
  if ( (v9[3] & v9[2]) != -1 )
    _findclose(FindHandle: v9[2]);
  if ( v9[4] != 0 )
    (*(void (__thiscall **)(_DWORD, intptr_t, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v9[4], a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F617600
// Name: _Q_AppendSlash
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_AppendSlash(_DWORD *a1@<eax>, char a2@<dl>, int a3@<edi>, int a4@<esi>)
{
  HMODULE v4; // [esp-Ch] [ebp-Ch]
  char *v5; // [esp-8h] [ebp-8h]
  DWORD v6; // [esp-4h] [ebp-4h]

  *a1 += a1;
  *(_BYTE *)(a4 + 82) += a2;
  GetModuleFileNameA(hModule: v4, lpFilename: v5, nSize: v6);
  dword_3F665D08 = a4;
  if ( a4 != 0 )
    (*(void (__thiscall **)(_DWORD, int, int, _DWORD, int))(*g_pMemAllocSteam + 4))(
      a1: g_pMemAllocSteam,
      a2: a3,
      a3: a4,
      a4: 0,
      a5: 1);
  else
    (*(void (__thiscall **)(_DWORD, int))(*g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: a3);
  JUMPOUT(0x3F617656);
}

//------------------------------------------------------------------------------
// Address: 0x3F617660
// Name: _Q_MakeAbsolutePath
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_MakeAbsolutePath(
        int _EAX@<eax>,
        int (__cdecl *a2)(HANDLE, _DWORD, int)@<ebp>,
        int a3@<edi>,
        char *pOut,
        HMODULE outLen,
        const char *pPath,
        const char *pStartingDir,
        int Buffer,
        int Buffer_4,
        int Buffer_8,
        int Buffer_12,
        int Buffer_16,
        int Buffer_20,
        int Buffer_24,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        _DWORD *a21,
        char a22,
        int a23,
        int a24,
        int a25,
        char a26)
{
  const char *v27; // ebx
  int v28; // edi
  unsigned __int8 (__thiscall *v29)(_DWORD); // eax
  HANDLE ProcessHeap; // eax
  char *v31; // esi
  char *v32; // eax
  const char *v33; // esi
  bool v34; // zf
  char *v35; // [esp-10h] [ebp-10h]

  __asm { aas }
  v27 = _EAX;
  Q_snprintf(Buffer: _EAX, a2: a3, Format: v35);
  v28 = strlen(&a26) + strlen((const char *)STACK[0x478]) + 2;
  if ( (dword_3F665D0C & 1) != 0 )
  {
    v31 = (char *)dword_3F665D08;
  }
  else
  {
    v29 = *(unsigned __int8 (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 96);
    dword_3F665D0C |= 1u;
    if ( v29(a1: g_pMemAllocSteam) != 0 )
    {
      ProcessHeap = GetProcessHeap();
      v31 = (char *)a2(a1: ProcessHeap, a2: 0, a3: 260);
      VirtualQuery(lpAddress: &unk_3F665878, lpBuffer: (PMEMORY_BASIC_INFORMATION)&pOut, dwLength: 0x1Cu);
      GetModuleFileNameA(hModule: outLen, lpFilename: v31, nSize: 0x104u);
      dword_3F665D08 = (int)v31;
    }
    else
    {
      v31 = nullptr;
      dword_3F665D08 = 0;
    }
  }
  if ( v31 != nullptr )
    v32 = (char *)(*(int (__thiscall **)(_DWORD, int, char *, _DWORD, int))(*g_pMemAllocSteam + 4))(
                    a1: g_pMemAllocSteam,
                    a2: v28,
                    a3: v31,
                    a4: 0,
                    a5: 1);
  else
    v32 = (char *)(*(int (__thiscall **)(_DWORD, int))(*g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: v28);
  v33 = v32;
  Q_snprintf(Buffer: v32, a2: v28, Format: "%s%c%s", (const char *)STACK[0x468], 92, &a22);
  if ( (*a21 & 0x10) != 0 )
    v34 = (unsigned __int8)((int (__cdecl *)(const char *, const char *))loc_3F617500)(a1: v27, a2: v33) == 0;
  else
    v34 = !CopyFileA(lpExistingFileName: v27, lpNewFileName: v33, bFailIfExists: false);
  if ( !v34 )
  {
    (*(void (__thiscall **)(_DWORD, const char *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v27, a3: 1);
    (*(void (__thiscall **)(_DWORD, const char *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v33, a3: 1);
    JUMPOUT(0x3F6177AF);
  }
  JUMPOUT(0x3F6177FB);
}

//------------------------------------------------------------------------------
// Address: 0x3F6177B0
// Name: _Q_IsAbsolutePath
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_IsAbsolutePath(_BYTE *a1@<eax>)
{
  LOBYTE(a1) = *a1 | (unsigned __int8)a1;
  *(_BYTE *)(9 * (_DWORD)a1 - 37452529) += (_BYTE)a1;
  JUMPOUT(0x3F6177BA);
}

//------------------------------------------------------------------------------
// Address: 0x3F6177E0
// Name: CopyToMaxChars
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall CopyToMaxChars@<al>(char *pOut@<esi>, int outSize@<ebx>, const char *pIn@<edx>, int nCharsToCopy@<eax>)
{
  __asm { aas }
  (*(void (__thiscall **)(_DWORD, int, int))(**(_DWORD **)pIn + 24))(a1: *(_DWORD *)pIn, a2: _EAX, a3: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F617830
// Name: _Q_StrSubstInPlace
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __cdecl Q_StrSubstInPlace()
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x3F617880
// Name: _Q_StrSubst
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall Q_StrSubst@<al>(int a1@<ebx>)
{
  (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a1, a3: 1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F617A00
// Name: char __near * AllocString(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall AllocString@<eax>(const char *pStr@<ebx>, unsigned int *a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
  bool v5; // zf
  char *result; // eax
  char *v7; // [esp-910h] [ebp-910h] BYREF
  unsigned int v8; // [esp-90Ch] [ebp-90Ch] BYREF
  unsigned int v9; // [esp-908h] [ebp-908h] BYREF
  char v10[2304]; // [esp-900h] [ebp-900h] BYREF

  ++*((_DWORD *)pStr + 321078065);
  v10[a4] = 0;
  v5 = !GetDiskFreeSpaceA(
          lpRootPathName: v10,
          lpSectorsPerCluster: &v9,
          lpBytesPerSector: (LPDWORD)&v7,
          lpNumberOfFreeClusters: &v8,
          lpTotalNumberOfClusters: a2);
  result = v7;
  if ( v5 )
    return (char *)a3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F617AC0
// Name: _Q_SplitString2
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_SplitString2(int a1@<eax>, char a2@<ch>)
{
  *(_BYTE *)(a1 - 128) += a2;
  JUMPOUT(0x3F617AC3);
}

//------------------------------------------------------------------------------
// Address: 0x3F617CA0
// Name: _Q_SplitString
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_SplitString(int a1@<eax>)
{
  LOBYTE(a1) = a1 & 8;
  if ( a1 != 0 )
    (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a1, a3: 1);
  JUMPOUT(0x3F617CBB);
}

//------------------------------------------------------------------------------
// Address: 0x3F617CC0
// Name: _Q_StrSlice
// Source: json
//------------------------------------------------------------------------------
void __cdecl Q_StrSlice()
{
  unsigned int VolumeSerialNumber; // [esp+0h] [ebp-21Ch] BYREF
  unsigned int FileSystemFlags; // [esp+4h] [ebp-218h] BYREF
  unsigned int MaximumComponentLength; // [esp+8h] [ebp-214h] BYREF
  char FileSystemNameBuffer[264]; // [esp+Ch] [ebp-210h] BYREF
  char VolumeNameBuffer[264]; // [esp+114h] [ebp-108h] BYREF

  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  if ( GetVolumeInformationA(
         lpRootPathName: nullptr,
         lpVolumeNameBuffer: VolumeNameBuffer,
         nVolumeNameSize: 0x105u,
         lpVolumeSerialNumber: &VolumeSerialNumber,
         lpMaximumComponentLength: &MaximumComponentLength,
         lpFileSystemFlags: &FileSystemFlags,
         lpFileSystemNameBuffer: FileSystemNameBuffer,
         nFileSystemNameSize: 0x105u) )
  {
    Q_stristr(a1: FileSystemNameBuffer, a2: (int)"FAT");
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F617D80
// Name: _Q_StrLeft
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall Q_StrLeft(char *a1@<ecx>, int a2@<ebx>)
{
  char *v2; // [esp-2021Ch] [ebp-2021Ch]
  _BYTE v3[131068]; // [esp-1FFFCh] [ebp-1FFFCh] BYREF

  v3[131067] = a2;
  if ( sub_3F62853C(FileName: a1, Mode: v2) != a2 )
    JUMPOUT(0x3F617E2E);
  if ( sub_3F62B2A0(a1: v3, a2: 58) == 0 )
    JUMPOUT(0x3F617DB4);
}

//------------------------------------------------------------------------------
// Address: 0x3F617EA0
// Name: _Q_strtowcs
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_strtowcs(char a1@<zf>, int _EAX@<eax>)
{
  if ( !a1 )
    JUMPOUT(0x3F617EA6);
  __asm { aas }
  JUMPOUT(0x3F617ECB);
}

//------------------------------------------------------------------------------
// Address: 0x3F617ED0
// Name: _Q_wcstostr
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F617F00
// Name: _Q_FormatAndAppend
// Source: json
//------------------------------------------------------------------------------
void __usercall Q_FormatAndAppend(
        int a1@<eax>,
        int a2@<ebp>,
        int a3@<esi>,
        char *pDest,
        int maxLen,
        char *pFormat,
        ...)
{
  char *v6; // eax
  const char *v7; // edi
  unsigned int v8; // eax

  if ( a1 != 0 )
    v6 = (char *)(*(int (__thiscall **)(_DWORD, int, int, _DWORD, int, _DWORD))(*g_pMemAllocSteam + 4))(
                   a1: g_pMemAllocSteam,
                   a2: a3,
                   a3: a1,
                   a4: 0,
                   a5: 1,
                   a6: 0);
  else
    v6 = (char *)(*(int (__thiscall **)(_DWORD, int))(*g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: a3);
  v7 = v6;
  if ( a2 != 0 )
  {
    Q_strncpy(Destination: v6, Source: pFormat, Count: strlen(pFormat) + 1);
    v8 = strlen(v7);
    if ( v7[v8 - 1] != 92 )
      v7[v8] = 92;
    strlen("*");
    JUMPOUT(0x3F617F8D);
  }
  JUMPOUT(0x3F617FAE);
}

//------------------------------------------------------------------------------
// Address: 0x3F617F90
// Name: _Q_BasicHtmlEntityEncode
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge Q_BasicHtmlEntityEncode(_BYTE *a1@<ecx>, char *pDest, int nDestSize, const char *pIn, int nInSize)
{
  int iInput; // [esp+100h] [ebp-8h]

  *a1 = __ROL1__(*a1, 80);
  Q_strncpy(Destination: a1 + 1, Source: "*", Count: iInput);
  JUMPOUT(0x3F618030);
}

//------------------------------------------------------------------------------
// Address: 0x3F618080
// Name: void AssertValidWritePtr<void>(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall AssertValidWritePtr<void>(void *ptr@<ecx>, void (__thiscall *count)(void *, int)@<eax>)
{
  count(a1: ptr, a2: 540);
  JUMPOUT(0x3F618099);
}

//------------------------------------------------------------------------------
// Address: 0x3F6180A0
// Name: void AssertValidReadPtr<unsigned short const>(unsigned short const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall AssertValidReadPtr<unsigned short const>(wchar_t *ptr@<eax>, int a2@<ebp>)
{
  int v2; // [esp-8h] [ebp-8h]
  size_t v3; // [esp-4h] [ebp-4h]

  *(_DWORD *)(a2 + 16) = ptr;
  memset(a1: ptr, Val: v2, Size: v3);
  JUMPOUT(0x3F6180B0);
}

//------------------------------------------------------------------------------
// Address: 0x3F618530
// Name: public: void CUtlMemory<char __near *>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CUtlMemory<char *>::Grow(
        CUtlMemory<char *> *this@<esi>,
        int num@<eax>,
        LARGE_INTEGER liDistanceToMove,
        int a4)
{
  const char *v5; // eax
  DWORD v6; // eax

  if ( *(_BYTE *)(num + 16) != 0 && liDistanceToMove.QuadPart % (unsigned __int64)*(unsigned int *)(num + 20) != 0 )
  {
    v5 = (const char *)((int (*)(const char *, ...))loc_3F6027D0)(
                         a1: "Assertion Failed: %s",
                         "Seeking to a position which is not sector aligned will break unbuffered io");
    AssertMsgImplementation(a1: v5, 0, "..\\tier1\\fileio.cpp", 1812, &unk_3F6657E3, 0);
  }
  else
  {
    if ( a4 == 1 )
    {
      v6 = 1;
    }
    else if ( a4 == 2 )
    {
      v6 = 2;
    }
    else
    {
      v6 = 0;
    }
    SetFilePointerEx(hFile: *(HANDLE *)num, liDistanceToMove, lpNewFilePointer: nullptr, dwMoveMethod: v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F6185F0
// Name: char __near * strstr(char __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void strstr()
{
  JUMPOUT(0x3F6185FD);
}

//------------------------------------------------------------------------------
// Address: 0x3F618600
// Name: float FloatMakePositive(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl FloatMakePositive()
{
  JUMPOUT(0x3F618613);
}

//------------------------------------------------------------------------------
// Address: 0x3F618620
// Name: float BitsToFloat(unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __cdecl BitsToFloat()
{
  JUMPOUT(0x3F618627);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ADD4
// Name: __AssertValidReadPtr
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61D090
// Name: _strstr
// Source: json
//------------------------------------------------------------------------------
void __userpurge strstr(int a1@<eax>, unsigned __int8 *str1, unsigned __int8 *str2)
{
  _DWORD *v3; // eax

  v3 = (_DWORD *)((int (__stdcall *)(int, int))loc_3F61C380)(a1, a2: 1);
  if ( v3 != nullptr )
  {
    v3[2] = v3[2] & 0xC0FFFFFF | 0x6000000;
    *v3 = str1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F629720
// Name: _strstr_0
// Source: json
//------------------------------------------------------------------------------
char *__cdecl strstr_0(const char *Str, const char *SubStr)
{
  char v2; // dl
  const char *v3; // edi
  char v4; // dh
  const char *v5; // ecx
  char *v6; // esi
  char v7; // al
  char v9; // ah
  char v10; // al
  char v11; // al

  v2 = *SubStr;
  v3 = Str;
  if ( *SubStr == 0 )
    return (char *)Str;
  v4 = SubStr[1];
  if ( v4 == 0 )
    JUMPOUT(0x3F62B2A6);
findnext:
  v5 = SubStr;
  v6 = (char *)(v3 + 1);
  if ( *v3 == v2 )
    goto first_char_found_0;
  if ( *v3 != 0 )
  {
    while ( 2 )
    {
      v7 = *v6++;
      while ( v7 == v2 )
      {
first_char_found_0:
        v7 = *v6++;
        if ( v7 == v4 )
        {
          v3 = v6 - 1;
          while ( 1 )
          {
            v9 = v5[2];
            if ( v9 == 0 )
              break;
            v10 = *v6;
            v6 += 2;
            if ( v10 != v9 )
              goto findnext;
            v11 = v5[3];
            if ( v11 == 0 )
              break;
            v5 += 2;
            if ( v11 != *(v6 - 1) )
              goto findnext;
          }
          return (char *)(v3 - 1);
        }
      }
      if ( v7 != 0 )
        continue;
      break;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F60B5E0
// Name: sub_3F60B5E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__usercall sub_3F60B5E0@<eax>(int a1@<eax>)
{
  return &dword_3F6643D8[2 * a1 + 1].m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x3F60B5F0
// Name: sub_3F60B5F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F60B5F0()
{
  return dword_3F6643CC;
}

//------------------------------------------------------------------------------
// Address: 0x3F60CA30
// Name: Q_strtoi64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void Q_strtoi64()
{
  JUMPOUT(0x3F62A5B1);
}

//------------------------------------------------------------------------------
// Address: 0x3F60CA40
// Name: Q_strtoui64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void Q_strtoui64()
{
  JUMPOUT(0x3F62A5F5);
}

//------------------------------------------------------------------------------
// Address: 0x3F60CA50
// Name: Q_wcstoi64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl Q_wcstoi64(int a1, int a2, int a3)
{
  return Q_wcstoi64_0(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F60CA60
// Name: Q_wcstoui64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl Q_wcstoui64(int a1, int a2, int a3)
{
  return Q_wcstoui64_0(a1, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F60D6C0
// Name: Q_UnicodeToUCS2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl Q_UnicodeToUCS2(wchar_t *Source, signed int Count, wchar_t *Destination, int a4)
{
  size_t v4; // esi

  v4 = Count;
  if ( Count >= a4 / 2 )
    v4 = a4 / 2;
  wcsncpy_0(Destination, Source, Count: v4);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x3F60D770
// Name: Q_UTF8ToUCS2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Q_UTF8ToUCS2(LPCCH lpMultiByteStr, int a2, LPWSTR lpWideCharStr, unsigned int a4)
{
  int result; // eax

  if ( lpMultiByteStr == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  if ( lpWideCharStr == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      102,
      &unk_3F665781,
      0);
  *lpWideCharStr = 0;
  result = MultiByteToWideChar(
             CodePage: 0xFDE9u,
             dwFlags: 0,
             lpMultiByteStr,
             cbMultiByte: -1,
             lpWideCharStr,
             cchWideChar: a4 >> 1);
  lpWideCharStr[(a4 >> 1) - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F60E1E0
// Name: Q_CopyAndFixSlashes
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __usercall Q_CopyAndFixSlashes@<al>(
        const CUtlMap<int,int,int>::Node_t *a1@<eax>,
        CUtlMap<int,int,int>::CKeyLess *a2,
        CUtlMap<int,int,int>::CKeyLess *a3,
        unsigned int a4)
{
  if ( LOBYTE(a2->m_LessFunc) != 0 )
  {
    LOBYTE(a1) = a2->m_LessFunc;
    return CUtlMap<int,int,int>::CKeyLess::operator!(this: a3, a2: a1, a3: a2, a4, a5: 0);
  }
  else
  {
    LOBYTE(a3->m_LessFunc) = 0;
    return (char)a3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F60E320
// Name: V_FixDoubleSlashes
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl V_FixDoubleSlashes(const char *a1)
{
  if ( (int)(strlen(a1) - 1) > 1 )
    JUMPOUT(0x3F60E350);
  JUMPOUT(0x3F60E38D);
}

//------------------------------------------------------------------------------
// Address: 0x3F60ED10
// Name: V_FixupPathName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl V_FixupPathName(char *Destination, size_t Count, char *Source)
{
  char *i; // eax

  Q_strncpy(Destination, Source, Count);
  for ( i = Destination; *i != 0; ++i )
  {
    if ( *i == 47 || *i == 92 )
      *i = 92;
  }
  Q_RemoveDotSlashes(a1: Destination);
  V_FixDoubleSlashes(a1: Destination);
  return ___lc_handle_func();
}

//------------------------------------------------------------------------------
// Address: 0x3F60ED60
// Name: sub_3F60ED60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_3F60ED60@<al>(int a1@<eax>, char *a2@<edx>, int a3@<esi>, int a4)
{
  char v6; // al
  int v7; // ecx

  if ( a4 == 0 )
    return 0;
  v6 = *a2;
  v7 = 0;
  if ( *a2 != 0 )
  {
    while ( a1 > 0 )
    {
      if ( v7 == a4 - 1 )
      {
        *(_BYTE *)(v7 + a3) = 0;
        return 0;
      }
      ++a2;
      *(_BYTE *)(v7 + a3) = v6;
      v6 = *a2;
      ++v7;
      --a1;
      if ( *a2 == 0 )
        break;
    }
  }
  *(_BYTE *)(v7 + a3) = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F60EF80
// Name: sub_3F60EF80
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall sub_3F60EF80@<eax>(signed int a1@<eax>, char *Source)
{
  unsigned int v3; // eax
  int v4; // edi
  char *v5; // eax
  char *v6; // esi

  if ( a1 == -1 )
  {
    v3 = strlen(Source);
  }
  else if ( (int)strlen(Source) >= a1 )
  {
    v3 = a1;
  }
  else
  {
    v3 = strlen(Source);
  }
  v4 = v3 + 1;
  if ( (dword_3F665D0C & 1) != 0 )
  {
    v5 = (char *)dword_3F665D08;
  }
  else
  {
    dword_3F665D0C |= 1u;
    v5 = sub_3F6097C0();
    dword_3F665D08 = (int)v5;
  }
  if ( v5 != nullptr )
    v6 = (char *)(*(int (__thiscall **)(_DWORD, int, char *, _DWORD, int, _DWORD))(*g_pMemAllocSteam + 4))(
                   a1: g_pMemAllocSteam,
                   a2: v4,
                   a3: v5,
                   a4: 0,
                   a5: 1,
                   a6: 0);
  else
    v6 = (char *)(*(int (__thiscall **)(_DWORD, int))(*g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: v4);
  Q_strncpy(Destination: v6, Source, Count: v4);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F60F270
// Name: Q_SplitNumbers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Q_SplitNumbers(char *Source, char a2, _DWORD *a3)
{
  _DWORD *v3; // ebp
  char *v4; // esi
  bool v5; // zf
  int v6; // eax
  int v7; // edi
  size_t v8; // ebp
  unsigned int v9; // eax
  char Destination[32]; // [esp+Ch] [ebp-20h] BYREF

  v3 = a3;
  v4 = Source;
  v5 = Source == nullptr;
  a3[4] = 0;
  if ( v5 )
    return 0;
  do
  {
    if ( *v4 == 0 )
      break;
    v6 = sub_3F62B2A0(a1: v4, a2);
    v7 = v6;
    if ( v6 != 0 )
    {
      v8 = v6 - (_DWORD)v4;
      if ( (unsigned int)(v6 - (_DWORD)v4) >= 0x1F )
        v8 = 31;
      memcpy_1(a1: Destination, Src: v4, Size: v8);
      Destination[v8] = 0;
      v3 = a3;
      v4 = (char *)(v7 + 1);
    }
    else
    {
      strncpy_0(Destination, Source: v4, Count: 0x20u);
      Destination[31] = 0;
      v4 = nullptr;
    }
    if ( Destination[0] != 0 )
    {
      ((void (__cdecl *)(char *))Q_StripPrecedingAndTrailingWhitespace)(a1: Destination);
      Source = (char *)((int (__cdecl *)(char *))Q_atoi)(a1: Destination);
      v9 = v3[1];
      if ( (unsigned int)&Source >= v9 && (unsigned int)&Source < v9 + 4 * v3[4] )
        AssertMsgImplementation(
          a1: "Assertion Failed: (&src < Base()) || (&src >= (Base() + Count()) )",
          0,
          "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
          623,
          &unk_3F66573D,
          0);
      sub_3F605810(a1: v3, a2: v3[4], a3: &Source);
    }
  }
  while ( v4 != nullptr );
  return v3[4];
}

//------------------------------------------------------------------------------
// Address: 0x3F60F380
// Name: V_GetCurrentDirectory
// Source: linker_block_proximity
//------------------------------------------------------------------------------
bool __cdecl V_GetCurrentDirectory(int a1, int a2)
{
  return ((int (__cdecl *)(int, int))loc_3F62B1FB)(a1, a2) == a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F60F3A0
// Name: V_SetCurrentDirectory
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl V_SetCurrentDirectory(int a1)
{
  return ((int (__cdecl *)(int))loc_3F62B35E)(a1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F60F5A0
// Name: Q_strcmp_prefix
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Q_strcmp_prefix(_BYTE *a1, _BYTE *a2)
{
  _BYTE *v2; // ecx
  _BYTE *v3; // eax

  if ( a1 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: pStr1", 0, ".\\strtools.cpp", 2804, &unk_3F6657AA, 0);
  if ( a2 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: pStr2", 0, ".\\strtools.cpp", 2805, &unk_3F6657AB, 0);
  v2 = a2;
  v3 = a1;
  if ( *a1 != 0 )
  {
    while ( *v2 != 0 )
    {
      if ( *v3 != *v2 )
        return (char)*v3 - (char)*v2;
      ++v3;
      ++v2;
      if ( *v3 == 0 )
        return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F60F630
// Name: Q_stricmp_prefix
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Q_stricmp_prefix(char *a1, int a2)
{
  char *v2; // esi
  int v3; // ebx
  int v4; // edi
  int v5; // edi

  v2 = a1;
  if ( a1 == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: pStr1", 0, ".\\strtools.cpp", 2827, &unk_3F6657AC, 0);
  if ( a2 == 0 )
    AssertMsgImplementation(a1: "Assertion Failed: pStr2", 0, ".\\strtools.cpp", 2828, &unk_3F6657AD, 0);
  if ( *a1 != 0 )
  {
    v3 = a2 - (_DWORD)a1;
    while ( v2[v3] != 0 )
    {
      v4 = tolower_0(C: *v2);
      v5 = v4 - tolower_0(C: v2[v3]);
      if ( v5 != 0 )
        return v5;
      if ( *++v2 == 0 )
        return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F60F720
// Name: Q_FormatAndAppendV
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlRBTree<CUtlMap<int,int,int>::Node_t,int,CUtlMap<int,int,int>::CKeyLess>::Node_t *__cdecl Q_FormatAndAppendV(
        _BYTE *a1,
        int a2,
        int a3,
        int a4)
{
  CUtlMemory<CUtlRBTree<CUtlMap<int,int,int>::Node_t,int,CUtlMap<int,int,int>::CKeyLess>::Node_t> *v4; // ecx
  bool v5; // zf

  v5 = a2 == 0;
  if ( a2 < 0 )
  {
    AssertMsgImplementation(a1: "Assertion Failed: maxLen >= 0", 0, ".\\strtools.cpp", 2884, &unk_3F6657AE, 0);
    v5 = a2 == 0;
  }
  if ( !v5 && a1 == nullptr )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      109,
      &unk_3F665782,
      0);
  if ( *a1 == 0 )
    JUMPOUT(0x3F60F787);
  return CUtlMemory<CUtlRBTree<CUtlMap<int,int,int>::Node_t,int,CUtlMap<int,int,int>::CKeyLess>::Node_t>::Base(
           this: v4,
           a2: 1 - a2 < 0,
           a3: __OFSUB__(1, a2),
           a4: 1,
           a5: a2,
           a6: a1 + 1,
           a7: (int)a1,
           a8: a2,
           a9: a3,
           a10: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F615D40
// Name: sub_3F615D40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > **__usercall sub_3F615D40@<eax>(
        const char **a1@<eax>,
        CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > **a2@<esi>)
{
  const char *v2; // edi
  CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *v3; // ecx

  *a2 = nullptr;
  v2 = *a1;
  if ( *a1 != nullptr || (v2 = (const char *)&unk_3F656D69, &unk_3F656D69 != nullptr) )
  {
    (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: 0, a3: 0);
    if ( *v2 != 0 )
    {
      *a2 = CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>::CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>(
              this: v3,
              a2: v2);
      return a2;
    }
    *a2 = nullptr;
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F615DB0
// Name: sub_3F615DB0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > **__usercall sub_3F615DB0@<eax>(
        const char **a1@<eax>,
        CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > **a2@<esi>)
{
  const char *v2; // edi
  CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *v3; // ecx

  v2 = *a1;
  if ( *a1 == nullptr )
    v2 = (const char *)&unk_3F656D69;
  if ( *a2 != (CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *)v2 )
  {
    (*(void (__thiscall **)(_DWORD, CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *> > *, _DWORD))(*g_pMemAllocSteam + 24))(
      a1: g_pMemAllocSteam,
      a2: *a2,
      a3: 0);
    if ( v2 != nullptr && *v2 != 0 )
    {
      *a2 = CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>::CUtlVector<CCoroutineMgr *,CUtlMemory<CCoroutineMgr *>>(
              this: v3,
              a2: v2);
      return a2;
    }
    *a2 = nullptr;
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F615EA0
// Name: sub_3F615EA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F615EA0@<eax>(int a1@<eax>)
{
  return *(_DWORD *)(a1 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F615ED0
// Name: ?Q_stristr@@YAPBDPBD0@Z_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__userpurge Q_stristr@<eax>(int _EAX@<eax>, int a2@<esi>, const char *pStr, const char *pSearch)
{
  int v5; // eax

  __asm { aas }
  if ( _EAX != 0 )
    v5 = (*(int (__thiscall **)(_DWORD, int, int, _DWORD, int, _DWORD))(*g_pMemAllocSteam + 4))(
           a1: g_pMemAllocSteam,
           a2: 131068,
           a3: _EAX,
           a4: 0,
           a5: 1,
           a6: 0);
  else
    v5 = (*(int (__thiscall **)(_DWORD, int))(*g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: 131068);
  *(_DWORD *)a2 = v5;
  *(_DWORD *)(a2 + 4) = 0;
  ((void (__cdecl *)(int, int, const char *, _DWORD))Q_MakeAbsolutePath)(a1: v5, a2: 131068, a3: pStr, a4: 0);
  V_FixDoubleSlashes(a1: *(const char **)a2);
  return (const char *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F615F30
// Name: sub_3F615F30
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F615F30@<eax>(int *a1@<esi>)
{
  int v1; // eax
  int result; // eax

  v1 = a1[1];
  if ( v1 != 0 )
  {
    (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v1, a3: 1);
    a1[1] = 0;
  }
  result = *a1;
  if ( *a1 != 0 )
  {
    result = (*(int (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: result, a3: 1);
    *a1 = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6169E0
// Name: sub_3F6169E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_3F6169E0@<al>(int a1@<eax>, char *a2, char *a3, const wchar_t *a4)
{
  ((void (__cdecl *)(int))loc_3F615EB0)(a1);
  return Q_StripPrecedingAndTrailingWhitespace(pch: a2, pcha: a3, a3: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F616F60
// Name: sub_3F616F60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_3F616F60@<al>(int a1@<eax>)
{
  int v2; // [esp+Ch] [ebp-8h]
  const wchar_t *lpFileName; // [esp+10h] [ebp-4h]

  ((void (__stdcall *)(int))loc_3F615EB0)(a1);
  ((void (*)(void))loc_3F615F80)();
  if ( DeleteFileW(lpFileName) )
  {
    if ( lpFileName != nullptr )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
    if ( v2 != 0 )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
    return 1;
  }
  else
  {
    if ( lpFileName != nullptr )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
    if ( v2 != 0 )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F617230
// Name: sub_3F617230
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_3F617230@<al>(int a1@<eax>)
{
  char *v3; // [esp+4h] [ebp-10h]
  char *v4; // [esp+8h] [ebp-Ch]
  const wchar_t *v5; // [esp+Ch] [ebp-8h]
  int v6; // [esp+Ch] [ebp-8h]
  const wchar_t *lpPathName; // [esp+10h] [ebp-4h]

  sub_3F6169E0(a1, a2: v3, a3: v4, a4: v5);
  ((void (__stdcall *)(int))loc_3F615EB0)(a1);
  ((void (*)(void))loc_3F615F80)();
  if ( RemoveDirectoryW(lpPathName) )
  {
    if ( lpPathName != nullptr )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
    if ( v6 != 0 )
      (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v6, a3: 1);
    return 1;
  }
  else
  {
    if ( lpPathName != nullptr )
      (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
    if ( v6 != 0 )
      (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v6, a3: 1);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F617840
// Name: sub_3F617840
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall sub_3F617840@<al>(int a1@<eax>)
{
  const char *v1; // ebx
  char *v3; // ebp
  bool v4; // [esp+21h] [ebp-11h]
  int v5; // [esp+22h] [ebp-10h]
  const wchar_t *lpFileName; // [esp+26h] [ebp-Ch]
  char *v7; // [esp+2Ah] [ebp-8h] BYREF
  int v8; // [esp+2Eh] [ebp-4h]

  ((void (__stdcall *)(int))loc_3F615EB0)(a1);
  v1 = v7;
  if ( (unsigned __int8)((int (*)(void))loc_3F617120)() != 0 )
  {
    if ( v8 != 0 )
      (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v8, a3: 1);
    if ( v7 != nullptr )
      return Q_StrSubst(a1: (int)v7);
  }
  else
  {
    v3 = &v7[strlen(v7) - 1];
    if ( v3 > v7 )
    {
      while ( 1 )
      {
        if ( *v3 == 92 )
        {
          *v3 = 0;
          ((void (__stdcall *)(const char *))loc_3F615EB0)(a1: v1);
          ((void (*)(void))loc_3F615F80)();
          v4 = GetFileAttributesW(lpFileName) != -1;
          if ( lpFileName != nullptr )
          {
            (*(void (__thiscall **)(_DWORD, const wchar_t *, int))(*g_pMemAllocSteam + 24))(
              a1: g_pMemAllocSteam,
              a2: lpFileName,
              a3: 1);
            lpFileName = nullptr;
          }
          if ( v5 != 0 )
          {
            (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v5, a3: 1);
            v5 = 0;
          }
          *v3 = 92;
          if ( v4 )
            break;
        }
        if ( --v3 <= v1 )
          goto LABEL_16;
      }
      ++v3;
    }
LABEL_16:
    while ( *v3 != 0 )
    {
      if ( *v3 == 92 )
      {
        *v3 = 0;
        ((void (*)(void))loc_3F616080)();
        *v3 = 92;
      }
      ++v3;
    }
    if ( (unsigned __int8)((int (*)(void))loc_3F616080)() == 0 )
    {
      sub_3F615F30(a1: (int *)&v7);
      return 0;
    }
    sub_3F615F30(a1: (int *)&v7);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F618090
// Name: ??$AssertValidReadPtr@$$CBX@@YAXPBXH@Z
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void ___AssertValidReadPtr___CBX__YAXPBXH_Z()
{
  JUMPOUT(0x3F618095);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ADDA
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F61AE5C
// Name: public: _LocaleUpdate::~_LocaleUpdate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _LocaleUpdate::~_LocaleUpdate(_LocaleUpdate *this@<ecx>, char a2@<al>)
{
  LOBYTE(this->localeinfo.locinfo) |= a2;
  JUMPOUT(0x3F61AE5F);
}

//------------------------------------------------------------------------------
// Address: 0x3F61AE6A
// Name: public: struct localeinfo_struct __near * _LocaleUpdate::GetLocaleT(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _LocaleUpdate::GetLocaleT(_LocaleUpdate *this@<ecx>, _LocaleUpdate **a2@<esi>)
{
  *a2 = this;
}

//------------------------------------------------------------------------------
// Address: 0x3F61AE6D
// Name: ___ascii_stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __ascii_stricmp@<eax>(_DWORD *a1@<esi>, const char *dst, const char *src, localeinfo_struct *a4)
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  (*(void (__thiscall **)(int *, const char *, void *))(dword_3F6642E0 + 12))(
    a1: &dword_3F6642E0,
    a2: dst,
    a3: &unk_3F6642AC);
  return _stricmp_l(dst, src, plocinfo: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F61AEA2
// Name: __stricmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge _stricmp_l@<eax>(
        int a1@<ecx>,
        int a2@<esi>,
        const char *dst,
        const char *src,
        localeinfo_struct *plocinfo)
{
  *(_DWORD *)(a2 + 8) ^= a1;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F61AF75
// Name: __stricmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _stricmp(char a1@<cl>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 580970736) += a1;
  JUMPOUT(0x3F61AF7E);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B0E9
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl atexit()
{
  JUMPOUT(0x3F61B0EB);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B0FB
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__userpurge _fsopen@<eax>(
        int a1@<edi>,
        _DWORD *a2@<esi>,
        const char *file,
        _iobuf *mode,
        const char *shflag,
        int shflaga,
        int a7)
{
  int v7; // eax
  int *v8; // edi
  unsigned int v9; // ecx
  int v10; // eax
  _DWORD *v11; // edi
  unsigned int v12; // ecx

  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  *a2 = 0;
  a2[1] = 0;
  a2[2] = 0;
  a2[3] = 0;
  a2[2] ^= ((*(int (__thiscall **)(int *, const char *, void *, int))(dword_3F6642E0 + 12))(
              a1: &dword_3F6642E0,
              a2: file,
              a3: &unk_3F6642AC,
              a4: a1)
          ^ a2[2])
         & 0xFFFFFF;
  v7 = ((int (__thiscall *)(_DWORD *, const char *))loc_3F61C380)(a1: a2, a2: shflag);
  v8 = (int *)v7;
  if ( v7 != 0 )
  {
    sub_3F61B1C0(a1: v7);
    v9 = v8[2] & 0xC0FFFFFF | 0x2000000;
    *v8 = shflaga;
    v8[2] = v9;
  }
  v10 = ((int (__thiscall *)(_DWORD *, int))loc_3F61C380)(a1: a2, a2: a7);
  v11 = (_DWORD *)v10;
  if ( v10 != 0 )
  {
    sub_3F61B1C0(a1: v10);
    v12 = v11[2] & 0xC0FFFFFF | 0x2000000;
    *v11 = a7;
    v11[2] = v12;
  }
  return (_iobuf *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B1BF
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fopen()
{
  __debugbreak();
  JUMPOUT(0x3F61B1C0);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B1C0
// Name: sub_3F61B1C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge sub_3F61B1C0@<eax>(int a1, const char *a2, const char *a3)
{
  if ( (*(_DWORD *)(a1 + 8) & 0x3F000000) != 0 )
    JUMPOUT(0x3F61B21B);
  return fopen_s(pfile: (_iobuf **)a1, file: a2, mode: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B1D2
// Name: _fopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge fopen_s@<eax>(int *a1@<ebx>, _iobuf **pfile, const char *file, const char *mode)
{
  int v4; // esi
  int v5; // edi
  int result; // eax

  v4 = *a1;
  if ( *a1 != 0 )
  {
    do
    {
      v5 = *(_DWORD *)(v4 + 12);
      *(_DWORD *)(v4 + 12) = 0;
      sub_3F61B2A0(a1: v4);
      result = (*(int (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v4, a3: 1);
      v4 = v5;
    }
    while ( v5 != 0 );
  }
  *a1 = 0;
  a1[1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B222
// Name: _getc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge getc@<eax>(char a1@<cf>, int _EAX@<eax>, _DWORD *a3@<ecx>, int a4@<ebx>, _iobuf *stream)
{
  int result; // eax

  *(_BYTE *)(a4 + 101) += _EAX + a1;
  __asm { aas }
  result = (*(int (__thiscall **)(_DWORD, _DWORD))(*(_DWORD *)*a3 + 24))(a1: *a3, a2: *(_DWORD *)(a4 + 4));
  *(_DWORD *)(a4 + 4) = 0;
  *(_DWORD *)a4 = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B2A0
// Name: sub_3F61B2A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall sub_3F61B2A0(_DWORD *this)
{
  int result; // eax
  _DWORD *v3; // esi
  _DWORD *v4; // edi
  const char *v5; // [esp+0h] [ebp-Ch]
  const char *v6; // [esp+4h] [ebp-8h]

  result = sub_3F61B1C0(a1: (int)this, a2: v5, a3: v6);
  v3 = (_DWORD *)*(this + 3);
  if ( v3 != nullptr )
  {
    do
    {
      if ( v3 == this )
        break;
      v4 = (_DWORD *)v3[3];
      v3[3] = 0;
      sub_3F61B2A0(a1: v3);
      result = (*(int (__thiscall **)(_DWORD, _DWORD *, int))(*g_pMemAllocSteam + 24))(
                 a1: g_pMemAllocSteam,
                 a2: v3,
                 a3: 1);
      v3 = v4;
    }
    while ( v4 != nullptr );
  }
  *(this + 3) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B348
// Name: nullsub_35
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_35()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B359
// Name: __getc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _getc_nolock(char a1@<zf>, char a2@<sf>, char a3@<of>, char a4@<cl>, int a5@<ebx>)
{
  if ( !(a2 ^ a3 | a1) )
  {
    *(_BYTE *)(a5 - 972282812) += a4;
    JUMPOUT(0x3F61B361);
  }
  JUMPOUT(0x3F61B379);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B373
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fclose_nolock(int a1@<esi>)
{
  int v1; // eax
  char v2; // al

  sub_3F623810();
  if ( *(_BYTE *)(a1 + 30) == 0 )
  {
    if ( (*(_BYTE *)(a1 + 31) & 1) != 0 && *(_BYTE *)(a1 + 30) == 0 )
    {
      v1 = *(_DWORD *)(a1 + 16);
      if ( *(_DWORD *)(a1 + 24) >= v1 + 2 )
      {
        if ( v1 >= 0 && *(_DWORD *)(a1 + 8) >= v1 + 2
          || (v2 = (*(int (__thiscall **)(int, int))(a1 + 32))(a1: a1 + *(_DWORD *)(a1 + 36), a2: 2)) != 0 )
        {
          v2 = 1;
        }
        else
        {
          *(_BYTE *)(a1 + 30) |= 2u;
        }
      }
      else
      {
        *(_BYTE *)(a1 + 30) = 2;
        v2 = 0;
      }
      *(_BYTE *)(a1 + 30) &= ~2u;
      if ( v2 != 0 )
        JUMPOUT(0x3F61B3E3);
    }
    JUMPOUT(0x3F61B429);
  }
  JUMPOUT(0x3F61B422);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B3E5
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_BYTE *__usercall fclose@<eax>(int a1@<eax>, int a2@<ecx>, char a3@<bl>, int a4@<edi>, int a5@<esi>, _iobuf *stream)
{
  bool v6; // zf
  char i; // al
  _BYTE *result; // eax

  LOBYTE(a1) = a1 + 3;
  v6 = *(_DWORD *)(2 * a4 + 0x38) << 24 == 0;
  *(_DWORD *)(2 * a4 + 0x38) <<= 24;
  if ( v6 && *(_BYTE *)(a1 + 1) == a3 )
  {
    *(_DWORD *)(a5 + 16) = a2 + 2;
    for ( i = sub_3F625700(); *(_BYTE *)(a5 + 30) == 0; i = sub_3F625700() )
    {
      if ( i == 10 )
        break;
    }
    sub_3F623810();
    if ( *(_BYTE *)(a5 + 30) == 0 )
      JUMPOUT(0x3F61B390);
    return nullptr;
  }
  else
  {
    result = (_BYTE *)((int (*)(void))loc_3F624220)();
    if ( result != nullptr )
    {
      if ( *result == 34 )
      {
        LOBYTE(stream->_ptr) = 1;
        JUMPOUT(0x3F61B45F);
      }
      JUMPOUT(0x3F61B46C);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B461
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall printf@<eax>(int *a1@<eax>, char a2@<bl>, int a3@<edi>, const char *format, ...)
{
  int result; // eax

  result = *a1;
  *(_BYTE *)(a3 - 117) += a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B510
// Name: __printf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61B526
// Name: __printf_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61B53C
// Name: _printf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61B550
// Name: __printf_p_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _printf_p_l()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B566
// Name: __printf_p
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _printf_p()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B57A
// Name: __set_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl _set_printf_count_output()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B59F
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61B5B5
// Name: __isalpha_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge _isalpha_l@<eax>(int a1@<esi>, int c, localeinfo_struct *plocinfo)
{
  int result; // eax

  result = ((int (__thiscall *)(int))loc_3F61B580)(a1);
  if ( *(_DWORD *)(a1 + 12) != 0 )
    JUMPOUT(0x3F61B5B2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B609
// Name: _isalpha
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall isalpha(char a1@<al>, _BYTE *a2@<ecx>)
{
  *a2 -= a1;
  JUMPOUT(0x3F61B60B);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B634
// Name: __isupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _isupper_l(int (__thiscall *a1)(int)@<eax>, int a2@<esi>)
{
  int v2; // ebx

  v2 = a1(a1: a2);
  if ( (*(int (__thiscall **)(_DWORD, int, const char *, int, _DWORD, _DWORD))(*g_pMemAllocSteam + 4))(
         a1: g_pMemAllocSteam,
         a2: v2 + 1,
         a3: "..\\tier1\\KeyValues.cpp",
         a4: 439,
         a5: 0,
         a6: 0) == 0 )
    AssertMsgImplementation(a1: "Assertion Failed: buffer", 0, "..\\tier1\\KeyValues.cpp", 441, &unk_3F6657F8, 0);
  JUMPOUT(0x3F61B682);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B683
// Name: _isupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall isupper(void (__thiscall **a1)(int)@<eax>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5@<esi>)
{
  (*a1)(a1: a5);
  *(_BYTE *)(a4 + a2) = 0;
  (*(void (__thiscall **)(int, int))(*(_DWORD *)a5 + 12))(a1: a5, a2: a3);
  JUMPOUT(0x3F61B6A2);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B6AC
// Name: __islower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _islower_l@<eax>(int _EAX@<eax>, unsigned int a2@<esi>, int c)
{
  __asm { aas }
  STACK[0x124] = a2;
  STACK[0x128] = a2;
  STACK[0x130] = a2;
  LOBYTE(STACK[0x134]) = 1;
  STACK[0x128] = (*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)*_EAX + 8))(a1: *_EAX, a2: 0x10000);
  STACK[0x11C] = STACK[0x13C];
  return islower(c);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B6FB
// Name: _islower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall islower(int a1@<edi>, unsigned int a2@<esi>)
{
  int v2; // [esp-10h] [ebp-10h]
  int v3; // [esp-Ch] [ebp-Ch]
  int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  STACK[0x114] = a2;
  ((void (__stdcall *)(int, int, int, int))loc_3F61DDB0)(a1: v2, a2: v3, a3: v4, a4: v5);
  (*(void (__thiscall **)(_DWORD, int, unsigned int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a1, a3: a2);
  JUMPOUT(0x3F61B723);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B724
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge _isdigit_l@<al>(
        _DWORD *a1@<eax>,
        void (*a2)(void)@<edx>,
        char a3@<cl>,
        int a4@<ebx>,
        int a5@<esi>,
        int c,
        localeinfo_struct *plocinfo,
        localeinfo_struct *plocinfoa)
{
  void *retaddr; // [esp+10h] [ebp+0h]

  *a1 += a1;
  *(_BYTE *)(a4 + 1347819602) += a3;
  a2();
  (*(void (__thiscall **)(_DWORD, void *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: retaddr, a3: a5);
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B773
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61B79C
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge _isxdigit_l@<al>(
        int _EAX@<eax>,
        int a2@<ebp>,
        int c,
        localeinfo_struct *plocinfo,
        localeinfo_struct *plocinfoa,
        int a6)
{
  *(_BYTE *)(a2 + 873856831) *= 2;
  __asm { aas }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B7F0
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __stdcall isxdigit(int c, int a2, int a3, int a4)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B800
// Name: sub_3F61B800
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F61B800(int a1@<eax>, int a2, int a3)
{
  if ( a1 > 0 )
    JUMPOUT(0x3F61B818);
  JUMPOUT(0x3F61B843);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B81B
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge _isspace_l@<eax>(
        char a1@<cf>,
        int (__thiscall *a2)(int, const char *)@<edx>,
        char a3@<cl>,
        int a4@<ebx>,
        int a5@<edi>,
        int a6@<esi>,
        int c,
        localeinfo_struct *plocinfo)
{
  int result; // eax

  *(_BYTE *)(a4 + 72387334) += a3 + a1;
  result = a2(a1: a6, a2: "\t");
  if ( a4 != 0 )
    result = ((int (__cdecl *)(const char *))loc_3F624900)(a1: "\t");
  if ( c != a5 )
    JUMPOUT(0x3F61B81A);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B86A
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge isspace(
        int c,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B893
// Name: __ispunct_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ispunct_l@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        _BYTE *a3@<ecx>,
        int a4@<ebp>,
        int a5@<edi>,
        int a6@<esi>,
        int c)
{
  int v7; // eax
  int v8; // eax

  v7 = a1 + 1;
  if ( v7 != 0 && (_BYTE)v7 == 92 )
    *a3++ = 92;
  if ( *(_BYTE *)(a4 + 24) != 0 )
  {
    v8 = *(char *)(a2 + a6);
    if ( (unsigned int)(v8 - 65) <= 0x19 )
      LOBYTE(v8) = v8 + 32;
  }
  else
  {
    LOBYTE(v8) = *(_BYTE *)(a2 + a6);
  }
  *a3 = v8;
  if ( a2 + 1 <= a5 )
    JUMPOUT(0x3F61B883);
  strlen(*(const char **)(a4 - 4));
  return ispunct(c);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B8E2
// Name: _ispunct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall ispunct(char a1@<zf>, int a2@<ecx>, int a3@<ebx>, int a4@<ebp>, int a5@<edi>)
{
  if ( !a1 )
    (*(void (__thiscall **)(int))(*(_DWORD *)a2 + 4))(a1: a2);
  if ( *(_DWORD *)(a4 + 20) != 0 && a5 > 0 )
    ((void (__cdecl *)(int))loc_3F624900)(a1: a3);
  JUMPOUT(0x3F61B90A);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B90B
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __userpurge _isalnum_l@<al>(
        char a1@<cf>,
        char a2@<al>,
        int a3@<edx>,
        int a4@<ecx>,
        int a5@<esi>,
        int c,
        localeinfo_struct *plocinfo)
{
  char result; // al

  result = a1 + a2;
  __debugbreak();
  __debugbreak();
  __debugbreak();
  if ( a4 != 0 )
    result = (*(int (__thiscall **)(int, int, localeinfo_struct *, int))(*(_DWORD *)a4 + 4))(
               a1: a4,
               a2: a5,
               a3: plocinfo,
               a4: a3);
  if ( c != 0 && (int)plocinfo > 0 )
    return ((int (__stdcall *)(int))loc_3F624900)(a1: a5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61B95F
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall isalnum(int a1@<eax>, int c, ...)
{
  int v2; // [esp-4h] [ebp-4h]
  va_list va; // [esp+8h] [ebp+8h] BYREF

  va_start(va, c);
  *(_BYTE *)(a1 + 1166738804) += a1;
  *(_DWORD *)a1 += a1;
  if ( Q_UnicodeToUTF8(lpWideCharStr: (LPCWCH)a1, lpMultiByteStr: va, cbMultiByte: v2) != 0 )
    JUMPOUT(0x3F61B985);
  JUMPOUT(0x3F61BAE0);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B98A
// Name: __isprint_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _isprint_l(_DWORD *a1@<eax>, int a2@<edx>, int a3@<ebx>)
{
  unsigned int v3; // edi

  *a1 += a1;
  v3 = STACK[0x10028];
  sub_3F61B800(a1: STACK[0x10030] + 1, a2: STACK[0x10028], a3: a2);
  if ( a3 != 0 )
    (*(void (__thiscall **)(int, const char *, int, unsigned int))(*(_DWORD *)a3 + 4))(a1: a3, a2: "\"", a3: 1, a4: v3);
  if ( STACK[0x10018] != 0 )
    ((void (__cdecl *)(const char *))loc_3F624900)(a1: "\"");
  JUMPOUT(0x3F61B9DD);
}

//------------------------------------------------------------------------------
// Address: 0x3F61B9DE
// Name: _isprint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall isprint(__int16 a1@<ax>)
{
  MEMORY[0xFFFFFF] |= HIBYTE(a1);
  if ( MEMORY[0xFFFFFF] != 0 )
    (*(void (__thiscall **)(int *, __int16))(dword_3F6642E0 + 8))(a1: &dword_3F6642E0, a2: a1);
  JUMPOUT(0x3F61BA08);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BA09
// Name: __isgraph_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __userpurge _isgraph_l@<edx:eax>(
        int a1@<eax>,
        int *a2@<ebx>,
        int c,
        localeinfo_struct *plocinfo,
        localeinfo_struct *plocinfoa,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  return *a2 * (__int64)a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F61BA78
// Name: nullsub_36
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int nullsub_36()
{
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}

//------------------------------------------------------------------------------
// Address: 0x3F61BA88
// Name: __iscntrl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _iscntrl_l(char a1@<cl>, int a2@<ebx>)
{
  *(_BYTE *)(a2 - 1905203003) += a1;
  JUMPOUT(0x3F61BA8E);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BAD7
// Name: _iscntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __stdcall iscntrl(int c, int a2, int a3, int a4, int a5, int a6)
{
  return ((int (*)(void))loc_3F624900)();
}

//------------------------------------------------------------------------------
// Address: 0x3F61BB00
// Name: ___isascii
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __isascii(_DWORD *a1@<eax>, char a2@<dl>, int a3@<ebp>, _BYTE *a4@<esi>)
{
  LOBYTE(a1) = (unsigned __int8)a1 & 0x50;
  *a1 += a1;
  *(_BYTE *)(a3 - 117) += a2;
  LOBYTE(a1) = *a4 & 0x4C;
  *a1 += a1;
  JUMPOUT(0x3F61BB0C);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BB0D
// Name: ___toascii
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __toascii()
{
  JUMPOUT(0x3F61BB0F);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BB15
// Name: __iscsymf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61BB34
// Name: ___iscsymf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __iscsymf@<eax>(
        int _EAX@<eax>,
        void (__thiscall *a2)(int)@<edx>,
        int a3@<ebx>,
        int a4@<ebp>,
        int c,
        localeinfo_struct *a6)
{
  __asm { aas }
  a2(a1: a4);
  if ( a3 == 0 )
    JUMPOUT(0x3F61BB55);
  ((void (__cdecl *)(const char *))loc_3F624900)(a1: "\"");
  return _iscsym_l(c, plocinfo: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BB4E
// Name: __iscsym_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _iscsym_l(int c, localeinfo_struct *plocinfo, int a3, int a4)
{
  if ( (*(_DWORD *)(a4 + 8) & 0xFFFFFF) == 0 )
    JUMPOUT(0x3F61BB7B);
  JUMPOUT(0x3F61BB6A);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BB6D
// Name: ___iscsym
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __iscsym(int _EAX@<eax>, int a2@<edx>)
{
  __asm { aas }
  (*(void (__thiscall **)(int *, int))(a2 + 9))(a1: &dword_3F6642E0, a2: _EAX);
  JUMPOUT(0x3F61BB86);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BB89
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall atol@<eax>(char a1@<cf>, int a2@<ecx>, int a3@<ebx>, const char *nptr, localeinfo_struct *a5)
{
  *(_BYTE *)(a3 + 1284198896) -= a1 + a2;
  ((void (__cdecl *)(int))loc_3F61B850)(a1: a2);
  return _atol_l(nptr, plocinfo: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BB9A
// Name: __atol_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _atol_l(int a1@<ebp>)
{
  if ( a1 != 0 )
    JUMPOUT(0x3F61BBAE);
  JUMPOUT(0x3F61BBB0);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BBAF
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall atoi(int a1@<ebp>)
{
  *(_BYTE *)(a1 + 1746433243) = __ROL1__(*(_BYTE *)(a1 + 1746433243), 1);
  JUMPOUT(0x3F61BBB5);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BBB9
// Name: __atoi64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _atoi64()
{
  ((void (*)(void))loc_3F624900)();
  JUMPOUT(0x3F61BBCC);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BBDF
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _atof_l(
        void (__thiscall *a1)(int, const char *, int)@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        _tiddata *ptd@<edi>,
        const char *nptr,
        localeinfo_struct *plocinfo,
        localeinfo_struct *plocinfoa,
        _tiddata *a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        _tiddata *a14,
        int a15,
        const char *a16,
        int a17)
{
  const char *v17; // ecx
  int v18; // edx
  const char *v19; // eax
  int v20; // kr00_4
  const char *v21; // [esp-110h] [ebp-14Ch]
  _DWORD v22[2]; // [esp-104h] [ebp-140h] BYREF
  const char *v23; // [esp-FCh] [ebp-138h]
  const char *v24; // [esp-F8h] [ebp-134h]
  const char *v25; // [esp-F4h] [ebp-130h]
  int v26; // [esp-E4h] [ebp-120h]
  const char *v27; // [esp-E0h] [ebp-11Ch]
  const char *v28; // [esp-D8h] [ebp-114h]
  _flt fltstruct; // [esp+14h] [ebp-28h]
  _LocaleUpdate _loc_update; // [esp+2Ch] [ebp-10h]

  LOBYTE(a1) = (_BYTE)a1 + 87;
  a1(a1: a3, a2: "{\n", a3: 2);
  if ( a2 != 0 )
  {
    v25 = "{\n";
    ((void (*)(void))loc_3F624900)();
    ptd = a14;
  }
  if ( (*(_BYTE *)(v26 + 11) & 0x3F) == 0 )
  {
    v17 = *(const char **)v26;
    v27 = *(const char **)v26;
    if ( v27 != nullptr )
    {
      do
      {
        v18 = *((_DWORD *)v17 + 2);
        switch ( HIBYTE(v18) & 0x3F )
        {
          case 0:
            ((void (__cdecl *)(int, _tiddata *, int, const char *, int))loc_3F61BAF0)(
              a1: a3,
              a2: ptd,
              a3: a2,
              a4: a16 + 1,
              a5: a17);
            break;
          case 1:
            if ( v18 < 0 )
              v17 = *(const char **)v17;
            v28 = v17;
            if ( v17 != nullptr )
            {
              sub_3F61B800(a1: (int)(a16 + 1), a2: (int)ptd, a3: a2);
              JUMPOUT(0x3F61BC8A);
            }
            return;
          case 2:
            sub_3F61B800(a1: (int)(a16 + 1), a2: (int)ptd, a3: a2);
            if ( a3 != 0 )
              JUMPOUT(0x3F61BDBD);
            JUMPOUT(0x3F61BDCC);
          case 3:
            sub_3F61B800(a1: (int)(a16 + 1), a2: (int)ptd, a3: a2);
            if ( a3 != 0 )
            {
              v22[1] = ptd;
              v22[0] = 1;
              JUMPOUT(0x3F61C061);
            }
            if ( a2 != 0 )
            {
              v22[1] = "\"";
              JUMPOUT(0x3F61C073);
            }
            JUMPOUT(0x3F61C086);
          case 5:
            if ( v18 >= 0 )
              v19 = v17;
            else
              v19 = *(const char **)v17;
            if ( v19 != nullptr )
            {
              v24 = a16;
              v23 = (const char *)a2;
              v22[1] = ptd;
              v22[0] = a3;
              ((void (__stdcall *)(int, const char *))loc_3F61B940)(a1: v26, a2: v17);
            }
            break;
          case 6:
            JUMPOUT(0x3F61C193);
          case 7:
            sub_3F61B800(a1: (int)(a16 + 1), a2: (int)ptd, a3: a2);
            if ( a3 != 0 )
              (*(void (__thiscall **)(int, const char *, int, _tiddata *))(*(_DWORD *)a3 + 4))(
                a1: a3,
                a2: "\"",
                a3: 1,
                a4: ptd);
            if ( a2 != 0 )
            {
              ((void (__cdecl *)(const char *))loc_3F624900)(a1: "\"");
              ptd = a8;
            }
            if ( (*((_DWORD *)v24 + 2) & 0xFFFFFF) != 0 )
              (*(void (__thiscall **)(int *, int))(dword_3F6642E0 + 8))(
                a1: &dword_3F6642E0,
                a2: *((_DWORD *)v24 + 2) & 0xFFFFFF);
            v21 = v25;
            ((void (__cdecl *)(const char *, int, _tiddata *, int))loc_3F61B850)(a1: v23, a2: a3, a3: ptd, a4: a2);
            if ( a3 != 0 )
              JUMPOUT(0x3F61BF7C);
            if ( a2 != 0 )
            {
              ((void (__cdecl *)(const char *))loc_3F624900)(a1: "\"\t\t\"");
              ptd = _loc_update.ptd;
            }
            Q_snprintf(Buffer: (char *)v22, a2: 32, Format: "%lld", *(_QWORD *)v21);
            v20 = strlen((const char *)v22);
            if ( a2 != 0 && v20 > 0 )
              JUMPOUT(0x3F61BFF8);
            if ( a2 != 0 )
            {
              ((void (__cdecl *)(const char *))loc_3F624900)(a1: "\"\n");
              ptd = (_tiddata *)fltstruct.nbytes;
            }
            break;
          case 9:
            v24 = "KeyValues::RecursiveSaveToFile: TODO, missing code for saving binary data to file.\n";
            v23 = "Assertion Failed: %s";
            JUMPOUT(0x3F61C1B1);
          default:
            break;
        }
        v25 = *((const char **)v25 + 3);
        v17 = v25;
      }
      while ( v25 != nullptr );
    }
  }
  sub_3F61B800(a1: a11, a2: (int)ptd, a3: a2);
  if ( a3 != 0 )
    JUMPOUT(0x3F61C200);
  if ( a2 != 0 )
    ((void (__cdecl *)(const char *))loc_3F624900)(a1: "}\n");
}

//------------------------------------------------------------------------------
// Address: 0x3F61BC96
// Name: ___strgtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __strgtold12(
        int _EAX@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        _LDBL12 *pld12,
        _LDBL12 *p_end_ptr,
        const char **str,
        const char *mult12,
        int scale)
{
  *(_DWORD *)&byte_3F654324[_EAX - 1063600848] += a3;
  __asm { aas }
  _EAX(a1: a3, a2: 101);
  if ( a2 != 0 )
    ((void (__stdcall *)(const char *))loc_3F624900)(a1: "\"");
  if ( (*(_DWORD *)(scale + 8) & 0xFFFFFF) == 0 )
    JUMPOUT(0x3F61BCE2);
  JUMPOUT(0x3F61BCD1);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BCD6
// Name: ___STRINGTOLD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __STRINGTOLD(
        int _EAX@<eax>,
        int a2@<edx>,
        int a3@<ebx>,
        int a4@<ebp>,
        int a5@<edi>,
        _LDOUBLE *pld,
        _LDOUBLE *p_end_ptr,
        const char **str,
        const char *mult12,
        int mult12a,
        int a11)
{
  __asm { aas }
  (*(void (__thiscall **)(int *, int))(a2 + 8))(a1: &dword_3F6642E0, a2: _EAX);
  ((void (__stdcall *)(const char *, int, int, int, int))loc_3F61B850)(a1: mult12, a2: a4, a3: a5, a4: a3, a5: a11);
  if ( a4 != 0 )
    (*(void (__thiscall **)(int, const char *, int, int))(*(_DWORD *)a4 + 4))(a1: a4, a2: "\"\t\t\"", a3: 4, a4: a5);
  JUMPOUT(0x3F61BD0E);
}

//------------------------------------------------------------------------------
// Address: 0x3F61BDBE
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61C258
// Name: __longjmpex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _longjmpex(unsigned int a1)
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  return _validdrive(drive: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C25D
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _validdrive@<eax>(int result@<eax>, int a2@<ecx>)
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  if ( a2 != 0 )
  {
    if ( (*(_BYTE *)(result + 11) & 0x3F) != 0 )
      return 0;
    result = *(_DWORD *)result;
    if ( result == 0 )
    {
      return 0;
    }
    else
    {
      while ( (*(_DWORD *)(result + 8) & 0xFFFFFF) != a2 )
      {
        result = *(_DWORD *)(result + 12);
        if ( result == 0 )
          return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61C294
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__userpurge _getdcwd_nolock@<eax>(char a1@<al>, int a2@<ebx>, int a3@<esi>, int drive, char *pnbuf, char *maxlen)
{
  char *result; // eax
  char *v7; // edi
  char *v8; // eax

  if ( (a1 & 8) == 0 )
    return (char *)a2;
  v7 = nullptr;
  if ( (*(_BYTE *)(a2 + 11) & 0x3F) != 0 || (result = *(char **)a2, *(_DWORD *)a2 == 0) )
  {
LABEL_7:
    if ( (_BYTE)pnbuf != 0 )
    {
      if ( (dword_3F665D0C & 1) != 0 )
      {
        v8 = (char *)dword_3F665D08;
      }
      else
      {
        dword_3F665D0C |= 1u;
        v8 = sub_3F6097C0();
        dword_3F665D08 = (int)v8;
      }
      if ( v8 != nullptr )
        result = (char *)(*(int (__thiscall **)(_DWORD, int, char *, _DWORD, int))(*g_pMemAllocSteam + 4))(
                           a1: g_pMemAllocSteam,
                           a2: 16,
                           a3: v8,
                           a4: 0,
                           a5: 1);
      else
        result = (char *)(*(int (__thiscall **)(_DWORD, int))(*g_pMemAllocSteam + 8))(a1: g_pMemAllocSteam, a2: 16);
      if ( result != nullptr )
      {
        *(_DWORD *)result = 0;
        *((_DWORD *)result + 1) = 0;
        *((_DWORD *)result + 2) = 0;
        *((_DWORD *)result + 3) = 0;
        *((_DWORD *)result + 2) ^= (a3 ^ *((_DWORD *)result + 2)) & 0xFFFFFF;
      }
      else
      {
        result = nullptr;
      }
      if ( v7 != nullptr )
        *((_DWORD *)v7 + 3) = result;
      else
        *(_DWORD *)a2 = result;
    }
    else
    {
      return nullptr;
    }
  }
  else
  {
    while ( 1 )
    {
      v7 = result;
      if ( (*((_DWORD *)result + 2) & 0xFFFFFF) == a3 )
        break;
      result = *((char **)result + 3);
      if ( result == nullptr )
        goto LABEL_7;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61C3C9
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall _getcwd@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        _BYTE *a3@<ebx>,
        int a4@<ebp>,
        int a5@<esi>,
        char *pnbuf,
        char *maxlen,
        int maxlena)
{
  int v8; // ecx
  bool v9; // cf
  int v10; // eax

  v8 = *(_DWORD *)(a5 + 8 * a1);
  LOBYTE(a1) = a1 ^ 0x10;
  v9 = __CFADD__((_BYTE)v8, *(_BYTE *)(a4 - 1961876412));
  *(_BYTE *)(a4 - 1961876412) += v8;
  v10 = (*(int (__thiscall **)(int *, char *, int))(a2 + 4))(
          a1: &dword_3F6642E0,
          a2: (char *)&dword_3F6642E0 + v9 + a1,
          a3: a4);
  if ( (a3[11] & 0x3F) != 0 || *(_DWORD *)a3 == 0 )
    JUMPOUT(0x3F61C416);
  if ( (*(_DWORD *)(*(_DWORD *)a3 + 8) & 0xFFFFFF) == v10 )
    JUMPOUT(0x3F61C456);
  return _getdcwd(drive: (int)pnbuf, pnbuf: maxlen, maxlen: maxlena);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C412
// Name: __getdcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _getdcwd(CUtlBuffer *a1@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi

  if ( a4 == 0 )
  {
    if ( LOBYTE(STACK[0x138]) != 0 )
    {
      sub_3F609C70(this: a1);
      if ( v4 != nullptr )
      {
        *v4 = 0;
        v4[1] = 0;
        v4[2] = 0;
        v4[3] = 0;
        v4[2] ^= (a3 ^ v4[2]) & 0xFFFFFF;
        v5 = v4;
      }
      else
      {
        v5 = nullptr;
      }
      if ( a2 != 0 )
      {
        *(_DWORD *)(a2 + 12) = v5;
        JUMPOUT(0x3F61C45C);
      }
      JUMPOUT(0x3F61C47E);
    }
    JUMPOUT(0x3F61C49C);
  }
  JUMPOUT(0x3F61C400);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C45C
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge _strtod_l(
        char a1@<zf>,
        int a2@<eax>,
        int a3@<esi>,
        const char *nptr,
        char **endptr,
        localeinfo_struct *plocinfo)
{
  if ( !a1 )
    ((void (__thiscall *)(int, int, char **))loc_3F61C380)(a1: a3, a2: a2 + 1, a3: endptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C577
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall strtod(int _EAX@<eax>)
{
  __asm { aas }
  if ( _EAX == 0 )
    JUMPOUT(0x3F61C586);
  JUMPOUT(0x3F61C598);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C58A
// Name: xtoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall xtoa(unsigned int radix, int is_neg)
{
  _DWORD *v5; // esi

  __asm { aas }
  v5 = (_DWORD *)(*(int (__thiscall **)(_DWORD, int))(*(_DWORD *)*_EAX + 8))(a1: *_EAX, a2: 16);
  if ( v5 != nullptr )
  {
    *v5 = 0;
    v5[1] = 0;
    v5[2] = 0;
    v5[3] = 0;
    JUMPOUT(0x3F61C5C7);
  }
  JUMPOUT(0x3F61C5ED);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C5CA
// Name: __itoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _itoa(__int16 _AX@<ax>, int a2@<edx>, int a3@<ecx>, int a4@<esi>)
{
  __asm { aas }
  *(_DWORD *)(a4 + 8) ^= ((*(int (__thiscall **)(int *, int, void *))(a2 + 13))(
                            a1: &dword_3F6642E0,
                            a2: a3,
                            a3: &unk_3F6642AC)
                        ^ *(_DWORD *)(a4 + 8))
                       & 0xFFFFFF;
  JUMPOUT(0x3F61C5F0);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C5F2
// Name: __ltoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__userpurge _ltoa@<eax>(char *result@<eax>, int a2@<edx>, int a3@<edi>, unsigned int val, char *buf, char *radix)
{
  *((_DWORD *)result + 2) ^= (*((_DWORD *)result + 2) ^ (a2 << 30)) & 0x40000000;
  if ( *(_DWORD *)a3 != 0 )
  {
    if ( *(_DWORD *)(*(_DWORD *)a3 + 12) == 0 )
      JUMPOUT(0x3F61C61D);
    return _ultoa(val, buf, (int)radix);
  }
  else
  {
    *(_DWORD *)a3 = result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61C617
// Name: __ultoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__userpurge _ultoa@<eax>(char *result@<eax>, int a2@<ecx>, unsigned int val, char *buf, int radix)
{
  if ( *(_DWORD *)(a2 + 12) != 0 )
    JUMPOUT(0x3F61C614);
  *(_DWORD *)(a2 + 12) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61C62F
// Name: x64toa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall x64toa(int *a1, int a2)
{
  int v3; // eax

  __debugbreak();
  v3 = *a1;
  if ( *a1 != 0 )
  {
    for ( ; *(_DWORD *)(v3 + 12) != 0; v3 = *(_DWORD *)(v3 + 12) )
      ;
    *(_DWORD *)(v3 + 12) = a2;
  }
  else
  {
    *a1 = a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F61C69C
// Name: __i64toa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _i64toa(int a1@<eax>, int a2@<edx>, int a3@<ecx>, _BYTE *a4@<ebx>, int a5@<ebp>, int a6@<edi>)
{
  int v6; // eax

  *(_BYTE *)(a5 + a2 - 112) = 0;
  *(_BYTE *)(a3 - 30) |= a1;
  *a4 += BYTE1(a4);
  *(_DWORD *)(a6 + a2 - 117) *= 2;
  *(_BYTE *)(a5 - 20) = 0;
  v6 = ((int (__stdcall *)(int))loc_3F61D400)(a1);
  if ( *(_DWORD *)a4 == 0 )
  {
    *(_DWORD *)a4 = v6;
    JUMPOUT(0x3F61C6FC);
  }
  JUMPOUT(0x3F61C6E6);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C6CD
// Name: __ui64toa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61C6E8
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61C750
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sscanf(_DWORD *a1@<ebx>, int a2@<esi>, const char *string, const char *format, ...)
{
  if ( (*(_BYTE *)(a2 + 11) & 0x3F) != 0 )
  {
    if ( *a1 == a2 )
    {
      *a1 = *(_DWORD *)(a2 + 12);
      JUMPOUT(0x3F61C7C7);
    }
    JUMPOUT(0x3F61C7A4);
  }
  JUMPOUT(0x3F61C7E9);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C76F
// Name: __sscanf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61C790
// Name: _sscanf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sscanf_s(int *a1@<ebx>, int a2@<edi>, int a3@<esi>, const char *string, const char *format, ...)
{
  int v5; // eax

  if ( a3 == 0 )
  {
    v5 = ((int (__stdcall *)(int))loc_3F61D400)(a1: a2);
    if ( *a1 == 0 )
    {
      *a1 = v5;
      JUMPOUT(0x3F61C80C);
    }
    JUMPOUT(0x3F61C7F3);
  }
  JUMPOUT(0x3F61C780);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C7AF
// Name: __sscanf_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _sscanf_s_l@<eax>(
        int a1@<eax>,
        int a2@<ecx>,
        int a3@<ebx>,
        int a4@<esi>,
        const char *string,
        const char *format,
        localeinfo_struct *plocinfo,
        ...)
{
  bool v7; // zf

  v7 = (_BYTE)a2 + *(_BYTE *)(a3 - 834991032) == 0;
  *(_BYTE *)(a3 - 834991032) += a2;
  if ( v7 )
  {
    *(_DWORD *)(a1 + 12) = *(_DWORD *)(a4 + 12);
  }
  else if ( *(_DWORD *)(a2 + 12) != 0 )
  {
    JUMPOUT(0x3F61C7B0);
  }
  *(_DWORD *)(a4 + 12) = 0;
  return _wtol(nptr: (const wchar_t *)string);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C7D0
// Name: __wtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _wtol(_DWORD *this)
{
  sub_3F61B2A0(this);
  JUMPOUT(0x3F61C7DF);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C7E1
// Name: __wtol_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _wtol_l(char a1@<cf>, int a2@<edx>, char a3@<ch>)
{
  int v3; // [esp+0h] [ebp-4h]

  *(_BYTE *)(a2 + 1) -= a1 + a3;
  ((void (__stdcall *)(int))a2)(a1: v3);
  JUMPOUT(0x3F61C794);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C7F6
// Name: __wtoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _wtoi@<eax>(
        int a1@<eax>,
        int a2@<edx>,
        _BYTE *a3@<edi>,
        _BYTE *a4@<esi>,
        const wchar_t *nptr,
        localeinfo_struct *a6)
{
  *(_BYTE *)(a1 + a2 - 115) += BYTE1(a2);
  *a3 = *a4;
  return _wtoi_l(nptr, plocinfo: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C7FB
// Name: __wtoi_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _wtoi_l()
{
  JUMPOUT(0x3F61C7FD);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C800
// Name: __wtoi64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __usercall _wtoi64@<edx:eax>(int a1@<eax>, int a2@<ecx>, const wchar_t *nptr, localeinfo_struct *a4)
{
  do
    a2 = *(_DWORD *)(a2 + 12);
  while ( *(_DWORD *)(a2 + 12) != 0 );
  *(_DWORD *)(a2 + 12) = a1;
  return _wtoi64_l(nptr, plocinfo: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F61C811
// Name: __wtoi64_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _wtoi64_l(char a1@<zf>, int a2@<eax>)
{
  if ( !a1 )
  {
    do
    {
      if ( (*(_BYTE *)(a2 + 11) & 0x3F) == 0 )
        break;
      a2 = *(_DWORD *)(a2 + 12);
    }
    while ( a2 != 0 );
  }
  if ( a2 == 0 )
    JUMPOUT(0x3F61C82A);
  JUMPOUT(0x3F61C740);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D116
// Name: __MarkAllocaS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _MarkAllocaS(int a1@<eax>, int a2@<ecx>)
{
  *(_BYTE *)(a2 - 31) |= a1;
  *(_BYTE *)(a2 + 201) = 6;
  *(_DWORD *)(a1 + 8) = a2;
  JUMPOUT(0x3F61D126);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D128
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _freea(_DWORD *a1@<eax>, int a2@<ecx>)
{
  LOBYTE(a1) = (unsigned __int8)a1 & 4;
  *a1 = a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F61D143
// Name: _strupr_s_l_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strupr_s_l_stat(
        char *string@<edi>,
        const char *a2@<ebx>,
        const char *a3@<esi>,
        void *sizeInBytes,
        localeinfo_struct *plocinfo)
{
  CUtlBuffer *v5; // ecx
  void *v6; // eax
  unsigned int v7; // eax

  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  if ( string != nullptr )
  {
    sub_3F61B1C0(a1: (int)string, a2: a3, a3: a2);
    sub_3F609C70(this: v5);
    *((_DWORD *)string + 1) = v6;
    memcpy_1(a1: v6, Src: sizeInBytes, Size: (size_t)plocinfo);
    *((_BYTE *)&plocinfo->locinfo + *((_DWORD *)string + 1)) = 0;
    v7 = *((_DWORD *)string + 2) & 0xC0FFFFFF | 0x9000000;
    *(_DWORD *)string = plocinfo;
    *((_DWORD *)string + 2) = v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F61D2BF
// Name: __strupr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall _strupr_s_l@<al>(int a1@<eax>, int a2@<ecx>, _DWORD *a3@<esi>)
{
  LOBYTE(a1) = a1 & 4;
  *a3 = a1;
  a3[2] = a2 & 0xC0FFFFFF | 0x2000000;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F61D2F2
// Name: __strupr_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _strupr_s(int a1@<eax>, _DWORD *a2@<esi>)
{
  LOBYTE(a1) = a1 & 8;
  *a2 = a1;
  JUMPOUT(0x3F61D303);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D305
// Name: __strupr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61D31C
// Name: __strupr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall _strupr@<eax>(int a1@<esi>)
{
  int v1; // eax
  char *result; // eax

  v1 = *(_DWORD *)(a1 + 8);
  __asm { fstp    dword ptr [esi] }
  *(float *)a1 = _ET1;
  result = (char *)(v1 & 0xC0FFFFFF | 0x3000000);
  *(_DWORD *)(a1 + 8) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61D37E
// Name: int _strlwr_s_l_stat(char __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _strlwr_s_l_stat()
{
  _BYTE retaddr[8]; // [esp+28h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}

//------------------------------------------------------------------------------
// Address: 0x3F61D4FF
// Name: __strlwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strlwr_s_l()
{
  JUMPOUT(0x3F61D500);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D531
// Name: __strlwr_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge _strlwr_s@<eax>(int a1@<edi>, char *string, unsigned int sizeInBytes)
{
  return MK_FP(*(_WORD *)(a1 + 95), *(_DWORD *)(a1 + 91))();
}

//------------------------------------------------------------------------------
// Address: 0x3F61D544
// Name: __strlwr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__userpurge _strlwr_l@<eax>(int a1@<ebx>, char *string, localeinfo_struct *plocinfo)
{
  return (char *)((int (__stdcall *)(int))loc_3F61D3C0)(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D55B
// Name: __strlwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strlwr()
{
  JUMPOUT(0x3F61D55C);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D5BD
// Name: __tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _tolower(int this)
{
  --*(_DWORD *)(this + 260768835);
  JUMPOUT(0x3F61D5C3);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D5C5
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge _tolower_l@<eax>(
        void *a1@<eax>,
        const void *a2@<edx>,
        _DWORD *a3@<ebx>,
        _DWORD *a4@<edi>,
        int c,
        localeinfo_struct *plocinfo)
{
  size_t _loc_update_8; // [esp+8h] [ebp-10h]

  LOBYTE(a1) = (_BYTE)a1 + 81;
  memcpy_1(a1, Src: a2, Size: _loc_update_8);
  *(_BYTE *)(*a4 + a3[1] + 1) = 0;
  *a3 = *a4;
  return ((int (__stdcall *)(_DWORD *))loc_3F61D3C0)(a1: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D680
// Name: sub_3F61D680
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F61D680@<eax>(_DWORD *a1@<esi>)
{
  int result; // eax

  if ( a1 != nullptr )
  {
    sub_3F61B2A0(this: a1);
    return (*(int (__thiscall **)(_DWORD, _DWORD *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: a1, a3: 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61D6A0
// Name: sub_3F61D6A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall sub_3F61D6A0(int a1, int a2)
{
  if ( *(int *)(a2 + 16) > 0 )
    JUMPOUT(0x3F61D6C4);
  JUMPOUT(0x3F61D736);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D6DC
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall tolower(
        int _EAX@<eax>,
        char a2@<ch>,
        void (__cdecl *a3)(const char *, _DWORD)@<ebx>,
        int a4@<edi>,
        int a5@<esi>)
{
  bool v5; // cf

  v5 = __CFADD__(a2, byte_3F654324[_EAX - 1063600876]);
  byte_3F654324[_EAX - 1063600876] += a2;
  if ( v5 )
  {
    __asm { aas }
    a3(a1: "Assertion Failed: IsValidIndex(i)", a2: 0);
    if ( *(_DWORD *)(*(_DWORD *)(a5 + 4) + 4 * a4) == 0 )
      JUMPOUT(0x3F61D703);
    JUMPOUT(0x3F61D713);
  }
  JUMPOUT(0x3F61D746);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D710
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge strncpy(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        unsigned __int8 *dest,
        unsigned __int8 *source,
        unsigned __int8 *count)
{
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // ecx
  bool v8; // zf
  int v9; // edi

  v6 = dest;
  v7 = dest + 12;
  if ( *((_DWORD *)dest + 3) != 0 )
  {
    do
    {
      v6 = *(unsigned __int8 **)v7;
      v8 = *(_DWORD *)(*(_DWORD *)v7 + 12) == 0;
      v7 = (unsigned __int8 *)(*(_DWORD *)v7 + 12);
    }
    while ( !v8 );
  }
  v9 = a2 + 1;
  *((_DWORD *)v6 + 3) = a3;
  if ( v9 < a1 )
  {
    if ( !sub_3F614FF0(a1: v9, a2: (int)source) )
      JUMPOUT(0x3F61D6D8);
    JUMPOUT(0x3F61D6EE);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F61D834
// Name: _wcsncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void wcsncpy()
{
  unsigned int v1; // [esp-8h] [ebp-8h]

  __writeeflags(v1);
  __asm { rcr     dword ptr [edi-76h], 0C1h }
}

//------------------------------------------------------------------------------
// Address: 0x3F61D880
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  int v3; // esi
  char *result; // eax
  int v5; // [esp-Ch] [ebp-Ch]

  Q_strnicmp(a1: v3, a2: (int)"POSIX", a3: v5);
  if ( result != nullptr )
  {
    Q_strnicmp(a1: v3, a2: (int)"LINUX", a3: 0x7FFFFFFF);
    if ( result != nullptr )
      Q_strnicmp(a1: v3, a2: (int)"X360", a3: 0x7FFFFFFF);
  }
  LOBYTE(result) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61D9B5
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _isleadbyte_l(_DWORD *a1@<eax>, int a2@<ebx>)
{
  bool v2; // zf
  int v3; // eax
  int _loc_update_12; // [esp+Ch] [ebp-4h]

  *a1 += a1;
  v2 = BYTE1(a2) + *(_BYTE *)a1 == 0;
  *(_BYTE *)a1 += BYTE1(a2);
  if ( v2 )
  {
    v3 = *(_DWORD *)(_loc_update_12 + 16);
    if ( *(_DWORD *)(_loc_update_12 + 24) < v3 + 3 )
    {
      *(_BYTE *)(_loc_update_12 + 30) = 2;
      JUMPOUT(0x3F61D9F1);
    }
    if ( (v3 < a2 || *(_DWORD *)(_loc_update_12 + 8) < v3 + 3)
      && (*(unsigned __int8 (__thiscall **)(int, int, _DWORD))(_loc_update_12 + 32))(
           a1: _loc_update_12 + *(_DWORD *)(_loc_update_12 + 36),
           a2: 3,
           a3: (unsigned __int16)__DS__) == 0 )
    {
      JUMPOUT(0x3F61D9E9);
    }
    JUMPOUT(0x3F61D9EF);
  }
  JUMPOUT(0x3F61DA30);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D9EB
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl isleadbyte()
{
  JUMPOUT(0x3F61D9F8);
}

//------------------------------------------------------------------------------
// Address: 0x3F61D9F9
// Name: __iswalpha_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _iswalpha_l@<eax>(int a1@<ebp>, unsigned __int16 c)
{
  int v2; // eax

  v2 = *(_DWORD *)(a1 + 16) + *(_DWORD *)(a1 + 4);
  if ( v2 == 0 )
    JUMPOUT(0x3F61DA30);
  ((void (__cdecl *)(int, void *, int))Q_strncmp)(a1: v2, a2: &unk_3F65B758, a3: 3);
  return iswalpha(c);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DA0F
// Name: _iswalpha
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall iswalpha@<eax>(int a1@<eax>, int a2@<ebp>, unsigned __int16 c, localeinfo_struct *a4)
{
  if ( a1 != 0 )
    JUMPOUT(0x3F61DA30);
  *(_DWORD *)(a2 + 16) += 3;
  return _iswupper_l(c, plocinfo: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DA20
// Name: __iswupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _iswupper_l(char a1@<zf>, char a2@<sf>, char a3@<of>, char a4@<bl>, int a5@<ebp>)
{
  if ( a2 ^ a3 | a1 )
    *(_BYTE *)(a5 + 30) &= a4;
  else
    *(_BYTE *)(a5 + 30) |= 2u;
  JUMPOUT(0x3F61DA30);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DA33
// Name: _iswupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61DA41
// Name: __iswlower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _iswlower_l()
{
  JUMPOUT(0x3F61DA50);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DA54
// Name: _iswlower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl iswlower()
{
  JUMPOUT(0x3F61DA58);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DA62
// Name: __iswdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _iswdigit_l(char a1@<al>, int a2@<ebp>, int _EDI@<edi>)
{
  __asm { fmul    dword ptr [edi] }
  *(_BYTE *)(a2 + 1820594139) += a1;
  JUMPOUT(0x3F61DA70);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DA75
// Name: _iswdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl iswdigit()
{
  JUMPOUT(0x3F61DA78);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DA83
// Name: __iswxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _iswxdigit_l(int _EAX@<eax>, int a2@<ebx>)
{
  int v3; // eax
  int v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  __asm { aas }
  Q_strnicmp(a1: a2, a2: v4, a3: v5);
  if ( v3 == 0 )
    JUMPOUT(0x3F61DA98);
  JUMPOUT(0x3F61DAE7);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DA99
// Name: _iswxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall iswxdigit@<eax>(char a1@<cl>, int a2@<ebp>, unsigned __int16 c, localeinfo_struct *a4)
{
  *(_BYTE *)(a2 + 1376986196) |= a1;
  return _iswspace_l(c, plocinfo: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DAAA
// Name: __iswspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl _iswspace_l(unsigned __int16 c, localeinfo_struct *plocinfo, int a3, int a4)
{
  ((void (__cdecl *)(char *))loc_3F61B350)(a1: (char *)&a4 + 2);
  JUMPOUT(0x3F61DABC);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DABD
// Name: _iswspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall iswspace@<eax>(char a1@<cf>, int a2@<eax>, unsigned __int16 c, localeinfo_struct *a4)
{
  *(_BYTE *)(a2 + 326369336) -= a1 + a2;
  return _iswpunct_l(c, plocinfo: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DACB
// Name: __iswpunct_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge _iswpunct_l(int a1@<eax>, unsigned __int16 c, localeinfo_struct *plocinfo, int a4, int a5)
{
  int v5; // [esp-4h] [ebp-4h]

  ((void (__stdcall *)(int, int))loc_3F61D740)(a1, a2: v5);
  JUMPOUT(0x3F61DCD3);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DADE
// Name: _iswpunct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl iswpunct()
{
  __asm { into }
  JUMPOUT(0x3F61DAE0);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DB13
// Name: __iswprint_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _iswprint_l@<eax>(int a1@<eax>, int a2@<ecx>, unsigned __int16 c)
{
  if ( ((unsigned int)&g_pMemAllocSteam | a1) == 0 )
  {
    (*(void (__cdecl **)(int))(**(_DWORD **)a2 + 8))(a1: 16);
    JUMPOUT(0x3F61DB35);
  }
  return iswprint(c);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DB29
// Name: _iswprint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall iswprint(int a1@<eax>, int a2@<edx>)
{
  (*(void (__stdcall **)(int, int, _DWORD, int))(a2 + 4))(a1: 16, a2: a1, a3: 0, a4: 1);
  JUMPOUT(0x3F61DB39);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DB3A
// Name: __iswgraph_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _iswgraph_l(int a1@<eax>, _DWORD *a2@<esi>)
{
  int v2; // eax

  v2 = a1 ^ 0x689C033;
  a2[1] = v2;
  a2[2] = v2;
  a2[3] = v2;
  JUMPOUT(0x3F61DB4E);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DB50
// Name: _iswgraph
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall iswgraph@<eax>(
        void (__fastcall *_EAX)(int *, int, int)@<eax>,
        int a2@<edx>,
        int a3@<ebx>,
        _BYTE *a4@<esi>,
        unsigned __int16 c,
        localeinfo_struct *a6)
{
  LOBYTE(_EAX) = *a4;
  __asm { aas }
  _EAX(a1: &dword_3F6642E0, a2: a2 + 1, a3);
  return _iswcntrl_l(c, plocinfo: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DB61
// Name: __iswcntrl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _iswcntrl_l(int a1@<eax>, int a2@<ecx>, int a3@<esi>)
{
  *(_DWORD *)(a3 + 8) ^= (a1 ^ a2) & 0xFFFFFF;
  JUMPOUT(0x3F61DB72);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DB74
// Name: _iswcntrl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall iswcntrl@<eax>(char a1@<cl>, int a2@<ebx>, unsigned __int16 c)
{
  *(_BYTE *)(a2 - 1265956798) += a1;
  return iswascii(c);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DB82
// Name: _iswascii
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall iswascii(char a1@<al>, int a2@<ecx>)
{
  LOBYTE(a2) = a1 + a2;
  MEMORY[0x5E429CA7](a1: a2);
  JUMPOUT(0x3F61DB91);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DBB4
// Name: ___iswcsym
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __iswcsym(char a1@<zf>, int (__fastcall *_EAX)(int)@<eax>, int a3@<ecx>, int a4@<edi>)
{
  int v4; // ecx

  v4 = a3 - 1;
  if ( a1 != 0 || v4 == 0 )
  {
    __asm { aas }
    *(_DWORD *)(a4 + 8) ^= (_EAX(a1: v4) ^ *(_DWORD *)(a4 + 8)) & 0xFFFFFF;
    JUMPOUT(0x3F61DBD2);
  }
  JUMPOUT(0x3F61DBF8);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DBD5
// Name: __iswcsymf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _iswcsymf_l(char a1@<cf>, int a2@<edx>, int a3@<ecx>)
{
  MEMORY[0x3E6300FB](a1: a3, a2: *(_DWORD *)(a2 - 63) + a1 + a2);
  JUMPOUT(0x3F61DBDD);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DBFB
// Name: ___iswcsymf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __iswcsymf(int a1, int a2)
{
  ((void (__cdecl *)(int))loc_3F615AC0)(a1: a2);
  JUMPOUT(0x3F61DC1C);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DC4D
// Name: __set_osplatform
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _set_osplatform(int a1@<ecx>, int a2@<edi>)
{
  ((void (__thiscall *)(int, int))loc_3F61DEC0)(a1: a2, a2: a1);
  JUMPOUT(0x3F61DC56);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DC57
// Name: __set_osver
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_osver()
{
  JUMPOUT(0x3F61DC60);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DC61
// Name: __set_winver
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl _set_winver()
{
  JUMPOUT(0x3F61DC7A);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DC6B
// Name: __set_winmajor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _set_winmajor(char a1@<zf>, __int16 _AX@<ax>, int a3@<ecx>)
{
  int v3; // ecx

  v3 = a3 - 1;
  if ( a1 != 0 || v3 == 0 )
  {
    __asm { aas }
    JUMPOUT(0x3F61DC73);
  }
  JUMPOUT(0x3F61DCAF);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DC75
// Name: __set_winminor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61DC7F
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge _CRT_INIT@<al>(
        int _EAX@<eax>,
        int a2@<ebp>,
        _DWORD *a3@<edi>,
        void *hDllHandle,
        void *dwReason,
        unsigned int lpreserved,
        unsigned int winmajor,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12)
{
  char v13; // al
  int v14; // ebp
  int v15; // esi
  int i; // ebx
  int v17; // edi
  char *v19; // [esp-1ECh] [ebp-238h]
  char v20; // [esp-1E8h] [ebp-234h]
  const char *v21; // [esp-1E4h] [ebp-230h]
  const char *v22; // [esp-1E0h] [ebp-22Ch]
  int v23; // [esp-1D8h] [ebp-224h]
  char v24; // [esp-1D3h] [ebp-21Fh]
  int v25; // [esp-1D0h] [ebp-21Ch]
  _DWORD v26[115]; // [esp-1CCh] [ebp-218h] BYREF

  __asm { aas }
  v13 = sub_3F61F4C0(Format: v19, ArgList: v20);
  sub_3F61F2B0(ArgList: v13 + 9);
  if ( v24 == 0 )
  {
    if ( v25 != 0 )
      *(_DWORD *)(v25 + 12) = 0;
    sub_3F61B1C0(a1: (int)a3, a2: v21, a3: v22);
    a3[2] &= 0xC0FFFFFF;
    *a3 = 0;
    a3[1] = 0;
  }
  if ( *(_BYTE *)(a2 + 30) == 0 )
    JUMPOUT(0x3F61DA30);
  sub_3F61D6A0(a1: a12, a2: (int)v26);
  v14 = v26[4];
  v15 = v26[1];
  for ( i = v26[4] - 1; i > 0; --i )
  {
    if ( i >= v14 )
      AssertMsgImplementation(
        a1: "Assertion Failed: IsValidIndex(i)",
        0,
        "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
        292,
        &unk_3F66580D,
        0);
    v17 = *(_DWORD *)(v15 + 4 * i);
    if ( v17 != 0 )
    {
      sub_3F61B2A0(this: *(_DWORD **)(v15 + 4 * i));
      (*(void (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v17, a3: 1);
    }
  }
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v26[70], a3: 0);
  (*(void (__thiscall **)(_DWORD, _DWORD, _DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v26[69], a3: 0);
  if ( v23 >= 0 && v15 != 0 )
    (*(void (__thiscall **)(_DWORD, int, _DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v15, a3: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F61DF4E
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __userpurge _DllMainCRTStartup@<eax>(
        int a1@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        void *hDllHandle,
        unsigned int dwReason,
        void *lpreserved)
{
  --*(_DWORD *)(a2 + 67715);
  *(_BYTE *)a2 += BYTE1(a2);
  *(_DWORD *)(a1 + 2131764300) = __ROR4__(*(_DWORD *)(a1 + 2131764300), 2);
  *(_DWORD *)(a2 + 264) = a1;
  return CPtoLCID(codepage: *(_DWORD *)(a3 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F61DF6F
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CPtoLCID(
        int codepage@<eax>,
        int a2@<ebx>,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        char a13)
{
  if ( ((int (__cdecl *)(char *, bool, int, char *))loc_3F61B350)(
         a1: (char *)&a6 + 2,
         a2: (codepage & 0x40000000) != 0,
         a3: a2,
         a4: &a13) != 0 )
    JUMPOUT(0x3F61DFA4);
  JUMPOUT(0x3F61E441);
}

//------------------------------------------------------------------------------
// Address: 0x3F61DFF3
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall setSBUpLow(
        threadmbcinfostruct *ptmbci@<esi>,
        int _EAX@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        _DWORD *a5@<edi>,
        int a6,
        int a7,
        int a8,
        int a9,
        _DWORD *a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        char a16)
{
  int v17; // eax
  _BYTE *v18; // ebp
  int v19; // eax
  _DWORD *v20; // esi
  int refcount; // eax

  __asm { aas }
  AssertMsgImplementation(a1: "Assertion Failed: stackLevel >= 0 && stackLevel < m_errorIndex", 0);
  *(_DWORD *)(a3 + 4 * a11) = a4;
  v17 = ((int (__cdecl *)(char *, bool, int, char *))loc_3F61B350)(
          a1: (char *)&a9 + 2,
          a2: (ptmbci->ismbcodepage & 0x40000000) != 0,
          a3,
          a4: &a16);
  v18 = (_BYTE *)v17;
  if ( a16 != 0 )
  {
    if ( v17 == 0 )
      goto LABEL_26;
    HIBYTE(a9) = 0;
    ((void (__cdecl *)(char *))loc_3F615AC0)(a1: (char *)&a9 + 3);
    v18 = (_BYTE *)((int (__cdecl *)(char *, bool, int, char *))loc_3F61B350)(
                     a1: (char *)&a9 + 2,
                     a2: (ptmbci->ismbcodepage & 0x40000000) != 0,
                     a3,
                     a4: &a16);
  }
  if ( v18 != nullptr )
  {
    if ( *v18 == 61 && BYTE2(a9) == 0 )
    {
      v19 = ((int (__cdecl *)(char *, bool, int, char *))loc_3F61B350)(
              a1: (char *)&a9 + 2,
              a2: (ptmbci->ismbcodepage & 0x40000000) != 0,
              a3,
              a4: &a16);
      if ( a16 != 0 )
      {
        if ( v19 != 0 )
        {
          HIBYTE(a9) = 0;
          ((void (__cdecl *)(char *))loc_3F615AC0)(a1: (char *)&a9 + 3);
          ((void (__cdecl *)(char *, bool, int, char *))loc_3F61B350)(
            a1: (char *)&a9 + 2,
            a2: (ptmbci->ismbcodepage & 0x40000000) != 0,
            a3,
            a4: &a16);
        }
        if ( HIBYTE(a9) != 0 )
        {
          if ( (a5[2] & 0xFFFFFF) != 0 )
          {
            if ( (ptmbci->ismbcodepage & 0x3F000000) != 0 )
              goto LABEL_25;
            refcount = ptmbci->refcount;
            if ( ptmbci->refcount == 0 )
              goto LABEL_25;
            while ( (*(_DWORD *)(refcount + 8) & 0xFFFFFF) != (a5[2] & 0xFFFFFF) )
            {
              refcount = *(_DWORD *)(refcount + 12);
              if ( refcount == 0 )
                goto LABEL_25;
            }
            v20 = (_DWORD *)refcount;
          }
          else
          {
            v20 = a10;
          }
          if ( v20 != nullptr && v20 != a5 )
          {
            ((void (*)(void))loc_3F61C840)();
            sub_3F61B2A0(this: v20);
            JUMPOUT(0x3F61E17B);
          }
        }
      }
    }
LABEL_25:
    JUMPOUT(0x3F61E183);
  }
LABEL_26:
  JUMPOUT(0x3F61E44F);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E17D
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61E221
// Name: getSystemCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall getSystemCP@<eax>(
        int a1@<ecx>,
        const char *a2@<ebp>,
        int *a3@<edi>,
        int a4,
        threadmbcinfostruct *a5,
        int a6,
        int a7,
        int a8,
        int a9,
        char *EndPtr)
{
  char v11; // al
  int v12; // esi
  char v13; // cl
  int v14; // eax

  a3[2] = a1;
  v11 = *a2;
  v12 = 0;
  v13 = 1;
  if ( *a2 != 0 )
  {
    do
    {
      if ( v13 != 0 && (v11 < 48 || v11 > 57) && (v11 < 43 || v11 > 46) && v11 != 32 )
        v13 = 0;
      v11 = a2[++v12];
    }
    while ( v11 != 0 );
    if ( v12 != 0 && v13 != 0 )
    {
      v14 = strtol_0(String: a2, &EndPtr, Radix: 10);
      if ( EndPtr == &a2[v12] )
      {
        if ( *a2 == 48 )
          JUMPOUT(0x3F61E2A6);
        if ( v14 != 0x7FFFFFFF && v14 != 0x80000000 )
        {
          *a3 = v14;
          return _setmbcp_nolock(codepage: a4, ptmbci: a5);
        }
      }
      JUMPOUT(0x3F61E2A0);
    }
  }
  JUMPOUT(0x3F61E2D8);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E29B
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _setmbcp_nolock@<eax>(
        int a1@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int codepage,
        threadmbcinfostruct *ptmbci,
        threadmbcinfostruct *ptmbcia,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        char a15)
{
  int v15; // ebp
  int v16; // esi
  _DWORD *v17; // esi
  _DWORD *v18; // eax
  bool v19; // cc
  threadmbcinfostruct *v20; // esi
  int refcount; // eax
  int v22; // ecx
  _BYTE *v23; // eax
  const char *v24; // ecx
  int cpinfo_8; // [esp+10h] [ebp-10h]
  _UNKNOWN *retaddr; // [esp+20h] [ebp+0h] BYREF

  *(_DWORD *)(a4 + 8) = a1;
  if ( (*(_BYTE *)(a4 + 11) & 0x3F) == 1 )
    ((void (__cdecl *)(int))loc_3F61D1A0)(a1: a3);
  v15 = a14;
  v16 = *(_DWORD *)(a14 + 16);
  ((void (__cdecl *)(char *, bool, int, char *))loc_3F61B350)(
    a1: (char *)&a8 + 2,
    a2: (*(_DWORD *)(a9 + 8) & 0x40000000) != 0,
    a3: a2,
    a4: &a15);
  if ( a15 != 0 )
  {
    HIBYTE(a8) = 0;
    ((void (__cdecl *)(char *))loc_3F615AC0)(a1: (char *)&a8 + 3);
    if ( HIBYTE(a8) == 0 )
      goto LABEL_19;
    if ( (*(_DWORD *)(a4 + 8) & 0xFFFFFF) != 0 )
    {
      if ( (*(_BYTE *)(a9 + 11) & 0x3F) != 0 )
        goto LABEL_18;
      v18 = *(_DWORD **)a9;
      if ( *(_DWORD *)a9 == 0 )
        goto LABEL_18;
      while ( (v18[2] & 0xFFFFFF) != (*(_DWORD *)(a4 + 8) & 0xFFFFFF) )
      {
        v18 = (_DWORD *)v18[3];
        if ( v18 == nullptr )
          goto LABEL_18;
      }
      v17 = v18;
    }
    else
    {
      v17 = (_DWORD *)a9;
    }
    if ( v17 != nullptr )
    {
      ((void (*)(void))loc_3F61C840)();
      sub_3F61B2A0(this: v17);
      (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam, a2: v17, a3: 1);
    }
  }
  else
  {
    v19 = v16 <= *(_DWORD *)(v15 + 24);
    *(_DWORD *)(v15 + 16) = v16;
    if ( v19 )
      *(_BYTE *)(v15 + 30) &= ~2u;
    else
      *(_BYTE *)(v15 + 30) |= 2u;
  }
LABEL_18:
  if ( HIBYTE(ptmbci) != 0 )
  {
    v20 = ptmbcia;
    goto LABEL_28;
  }
LABEL_19:
  v20 = ptmbcia;
  refcount = ptmbcia->refcount;
  if ( ptmbcia->refcount == a4 )
  {
    ptmbcia->refcount = *(_DWORD *)(a4 + 12);
  }
  else if ( *(_DWORD *)(refcount + 12) != 0 )
  {
    while ( 1 )
    {
      v22 = *(_DWORD *)(refcount + 12);
      if ( v22 == a4 )
        break;
      refcount = *(_DWORD *)(refcount + 12);
      if ( *(_DWORD *)(v22 + 12) == 0 )
        goto LABEL_26;
    }
    *(_DWORD *)(refcount + 12) = *(_DWORD *)(a4 + 12);
  }
LABEL_26:
  *(_DWORD *)(a4 + 12) = 0;
  sub_3F61B2A0(this: (_DWORD *)a4);
  cpinfo_8 = a4;
  (*(void (__thiscall **)(_DWORD))(*g_pMemAllocSteam + 24))(a1: g_pMemAllocSteam);
LABEL_28:
  HIBYTE(retaddr) = 1;
  v23 = (_BYTE *)((int (__cdecl *)(char *, bool, int, int *))loc_3F61B350)(
                   a1: (char *)&retaddr + 2,
                   a2: (v20->ismbcodepage & 0x40000000) != 0,
                   a3: a2,
                   a4: &a11);
  if ( v23 == nullptr )
  {
    v24 = "RecursiveLoadFromBuffer:  got EOF instead of keyname";
LABEL_31:
    sub_3F61F2B0(ArgList: (char)v24);
    goto LABEL_32;
  }
  if ( *v23 == 0 )
  {
    v24 = "RecursiveLoadFromBuffer:  got empty keyname";
    goto LABEL_31;
  }
  if ( *v23 != 125 || BYTE2(retaddr) != 0 )
  {
    ((void (__stdcall *)(_BYTE *, int))loc_3F61C560)(a1: v23, a2: cpinfo_8);
    if ( (int)ptmbcia < 0 || (int)ptmbcia >= *(_DWORD *)(a2 + 260) )
      JUMPOUT(0x3F61DFF0);
    JUMPOUT(0x3F61E005);
  }
LABEL_32:
  --*(_DWORD *)(a2 + 260);
  return _getmbcp();
}

//------------------------------------------------------------------------------
// Address: 0x3F61E474
// Name: __getmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _getmbcp(bool a1@<sf>, int a2@<ebx>, int a3@<esi>)
{
  if ( a1 )
    AssertMsgImplementation(
      a1: "Assertion Failed: m_errorIndex>=0",
      0,
      "..\\tier1\\KeyValues.cpp",
      2842,
      &unk_3F665806,
      0);
  a1 = a3 + *(_DWORD *)(a2 + 260) < 0;
  *(_DWORD *)(a2 + 260) += a3;
  if ( a1 )
    JUMPOUT(0x3F61E4AD);
  JUMPOUT(0x3F61E4C2);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E4B0
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __stdcall _setmbcp(int codepage, int codepagea, int a3, int a4)
{
  __asm { aas }
  return AssertMsgImplementation(a1: "Assertion Failed: m_errorIndex>=0", 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E64A
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __initmbctable(__int16 *a1@<eax>)
{
  __int16 v1; // cx

  do
    v1 = *a1++;
  while ( v1 != 0 );
  JUMPOUT(0x3F61E664);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E668
// Name: __invoke_watson_if_error
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invoke_watson_if_error(char a1@<al>, _BYTE *a2@<ebx>, int a3@<ebp>)
{
  *a2 += a1;
  ++*(_DWORD *)(a3 - 1618079745);
  JUMPOUT(0x3F61E670);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E68A
// Name: ____setlc_active_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ___setlc_active_func()
{
  JUMPOUT(0x3F61E691);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E696
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __freetlocinfo()
{
  JUMPOUT(0x3F61E69C);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E7D6
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge __addlocaleref(
        _DWORD *a1@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        threadlocaleinfostruct *ptloci,
        int a5,
        int a6)
{
  if ( (ptloci->lc_handle[4] & 0x1000000) == 0 && BYTE2(ptloci->lc_handle[4]) == 0 )
  {
    sub_3F61B2A0(this: a1);
    *a1 = 0;
    a1[1] = 0;
    a1[2] = 0;
    a1[3] = 0;
    if ( ptloci->lc_handle[3] != ptloci->lc_handle[1] )
    {
      if ( a5 <= 100 )
        JUMPOUT(0x3F61E944);
      if ( byte_3F665FA4 != 0
        || (unsigned __int8)((int (__cdecl *)(int, int))IsInAssert)(a1: a2, a2: a3) != 0
        || (unsigned __int8)((int (*)(void))BGetMiniDumpLock)() == 0 )
      {
        JUMPOUT(0x3F61E935);
      }
      if ( (unsigned __int8)((int (*)(void))BWritingMiniDump)() != 0 )
        JUMPOUT(0x3F61E92F);
      __removelocaleref(ptloci);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F61E85C
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __removelocaleref()
{
  const char *v0; // eax
  int v1; // esi
  int v2; // eax

  SetInAssert(a1: 1);
  SpewInfo(a1: 2, a2: "..\\tier1\\KeyValues.cpp", a3: 2407);
  v0 = (const char *)((int (*)(const char *, ...))loc_3F6027D0)(
                       a1: "Assertion Failed: %s",
                       "KeyValues::ReadAsBinary() stack depth > 100");
  v1 = SpewMessage(a1: "%s", v0);
  byte_3F665FA4 = 1;
  CallAssertFailedNotifyFunc();
  if ( v1 == 0 && (unsigned __int8)ShouldUseNewAssertDialog() != 0 )
  {
    v2 = ((int (*)(const char *, ...))loc_3F6027D0)(
           a1: "Assertion Failed: %s",
           "KeyValues::ReadAsBinary() stack depth > 100");
    if ( (unsigned __int8)DoNewAssertDialog(a1: "..\\tier1\\KeyValues.cpp", a2: 2407, a3: v2) != 0 )
      __debugbreak();
  }
  JUMPOUT(0x3F61E8E3);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E8E8
// Name: _copytlocinfo_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61E90C
// Name: _updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __userpurge updatetlocinfoEx_nolock@<al>(
        threadlocaleinfostruct **pptlocid@<eax>,
        threadlocaleinfostruct *ptlocis@<edi>,
        char a3@<ch>,
        int a4,
        int a5,
        int a6)
{
  *((_BYTE *)pptlocid + 103) += a3;
  *pptlocid = (threadlocaleinfostruct *)((unsigned int)pptlocid | (unsigned int)*pptlocid);
  byte_3F654324[(_DWORD)pptlocid - 1063600820] += a3;
  BYTE1(pptlocid) = 101;
  __asm { aas }
  ((void (__cdecl *)(int))WriteMiniDump)(a1: _EAX);
  byte_3F665804 = 1;
  ((void (__cdecl *)(_DWORD))ptlocis)(a1: 0);
  ((void (*)(void))MiniDumpUnlock)();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F61E94A
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __updatetlocinfo(char a1@<cl>, int a2@<ebp>, _BYTE *a3@<edi>)
{
  _BYTE *v3; // eax

  *a3 += a1;
  if ( a3 != (_BYTE *)8 )
  {
    *(_DWORD *)(a2 + 8) ^= (*(_DWORD *)(a2 + 8) ^ ((_DWORD)a3 << 24)) & 0x3F000000;
    if ( LOBYTE(STACK[0x138]) != 0 )
    {
      *(_DWORD *)(a2 + 8) ^= (((int (*)(void))loc_3F6259A0)() ^ *(_DWORD *)(a2 + 8)) & 0xFFFFFF;
      JUMPOUT(0x3F61E9C8);
    }
    v3 = (_BYTE *)sub_3F623CF0();
    if ( v3 != nullptr && (*v3 != 0 || (int)(STACK[0x134] + 1) < 100) )
    {
      (*(void (__thiscall **)(int *, _BYTE *, void *))(dword_3F6642E0 + 12))(
        a1: &dword_3F6642E0,
        a2: v3,
        a3: &unk_3F6642AC);
      JUMPOUT(0x3F61E9BF);
    }
  }
  JUMPOUT(0x3F61E935);
}

//------------------------------------------------------------------------------
// Address: 0x3F61E9C0
// Name: __configthreadlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _configthreadlocale(char a1@<zf>, int a2@<ecx>)
{
  int v2; // ecx

  v2 = a2 - 1;
  if ( a1 != 0 && v2 != 0 )
    JUMPOUT(0x3F61E9C1);
  JUMPOUT(0x3F61E9C2);
}

//------------------------------------------------------------------------------
// Address: 0x3F61EA26
// Name: sync_legacy_variables_lk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sync_legacy_variables_lk(int a1@<ebp>)
{
  int v1; // edi
  int v2; // eax

  v1 = ((int (*)(void))loc_3F623950)();
  if ( v1 <= 0 )
  {
    *(_BYTE *)a1 = 0;
  }
  else
  {
    v2 = a1;
    if ( (unsigned int)v1 > 8 )
    {
      v2 = (*(int (__thiscall **)(_DWORD, int, const char *, int, _DWORD, _DWORD))(*g_pMemAllocSteam + 4))(
             a1: g_pMemAllocSteam,
             a2: v1,
             a3: "..\\tier1\\KeyValues.cpp",
             a4: 2467,
             a5: 0,
             a6: 0);
      *(_DWORD *)(a1 + 8) |= 0x80000000;
      *(_DWORD *)a1 = v2;
    }
    sub_3F623750(a1: v2);
  }
  JUMPOUT(0x3F61EB67);
}

//------------------------------------------------------------------------------
// Address: 0x3F61EA79
// Name: __free_locale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _free_locale(int a1@<eax>, char a2@<bh>, int a3@<ebp>, _DWORD *a4@<edi>)
{
  int v4; // ebp
  bool v5; // sf
  bool v6; // of
  int v7; // edi
  int v8; // eax

  v4 = *a4 & a3;
  v6 = __OFADD__(a2, MEMORY[0xFFFF]);
  v5 = (char)(a2 + MEMORY[0xFFFF]) < 0;
  MEMORY[0xFFFF] += a2;
  if ( v5 != v6 )
  {
    if ( a1 <= 0 )
    {
      *(_WORD *)v4 = 0;
      goto LABEL_8;
    }
  }
  else
  {
    a1 = 0xFFFF;
  }
  v7 = 2 * a1;
  if ( (unsigned int)(2 * a1) >= 0x10000 )
    JUMPOUT(0x3F61E935);
  v8 = (*(int (__thiscall **)(_DWORD, int, const char *, int, _DWORD, _DWORD))(*g_pMemAllocSteam + 4))(
         a1: g_pMemAllocSteam,
         a2: v7,
         a3: "..\\tier1\\KeyValues.cpp",
         a4: 2490,
         a5: 0,
         a6: 0);
  *(_DWORD *)(v4 + 8) |= 0x80000000;
  *(_DWORD *)v4 = v8;
  sub_3F623750(a1: v8);
  *(_WORD *)(v7 + *(_DWORD *)v4 - 2) = 0;
LABEL_8:
  JUMPOUT(0x3F61EB67);
}

//------------------------------------------------------------------------------
// Address: 0x3F61EB0F
// Name: ___free_locale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61EB14
// Name: __get_current_locale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61EB9C
// Name: ___get_current_locale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61EBA1
// Name: __strcats
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _strcats(
        _DWORD *a1@<eax>,
        int a2@<ecx>,
        int a3@<ebp>,
        char *outstr,
        unsigned int sizeInBytes,
        int n,
        ...)
{
  _DWORD *retaddr; // [esp+0h] [ebp+0h]

  ++*(_DWORD *)(a3 + 857633984);
  *a1 = a2;
  a1[1] = a2;
  a1[2] = a2;
  a1[3] = a2;
  a1[2] &= 0xFF000000;
  retaddr[3] = a1;
  JUMPOUT(0x3F61E953);
}

//------------------------------------------------------------------------------
// Address: 0x3F61EBDF
// Name: ___lc_strtolc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __lc_strtolc(_DWORD *a1@<eax>)
{
  *a1 += a1;
  JUMPOUT(0x3F61EBE8);
}

//------------------------------------------------------------------------------
// Address: 0x3F61ED08
// Name: ___lc_lctostr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61ED73
// Name: _setlocale_get_all
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61EEE4
// Name: __expandlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _expandlocale()
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  JUMPOUT(0x3F61EEF0);
}

//------------------------------------------------------------------------------
// Address: 0x3F61EEF0
// Name: sub_3F61EEF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall sub_3F61EEF0(int *nGrowSize, CUtlMemory<unsigned char> *nInitAllocationCount)
{
  int m_nGrowSize; // ecx
  int v5; // ebx
  int v6; // eax
  int v7; // edx
  const char *v8; // ecx
  int v9; // ecx
  int v10; // edi
  int m_pMemory; // esi
  char v12; // bl

  if ( nInitAllocationCount == nullptr )
    return 0;
  m_nGrowSize = nInitAllocationCount->m_nGrowSize;
  v5 = *(nGrowSize + 2);
  v6 = HIBYTE(m_nGrowSize) & 0x3F;
  v7 = HIBYTE(v5) & 0x3F;
  if ( v7 != v6 )
    return 0;
  switch ( v7 )
  {
    case 0:
      v10 = *nGrowSize;
      if ( v6 != 0 )
        m_pMemory = 0;
      else
        m_pMemory = (int)nInitAllocationCount->m_pMemory;
      v12 = 0;
      break;
    case 1:
      if ( m_nGrowSize >= 0 )
        v8 = (const char *)nInitAllocationCount;
      else
        v8 = (const char *)nInitAllocationCount->m_pMemory;
      if ( v5 >= 0 )
        return sub_3F6062B0(a1: (const char *)nGrowSize, a2: v8) == 0;
      else
        return sub_3F6062B0(a1: (const char *)*nGrowSize, a2: v8) == 0;
    case 2:
    case 4:
      return (unsigned __int8 *)*nGrowSize == nInitAllocationCount->m_pMemory;
    case 3:
      return *(float *)&nInitAllocationCount->m_pMemory == *(float *)nGrowSize;
    case 5:
      if ( m_nGrowSize >= 0 )
        v9 = (int)nInitAllocationCount;
      else
        v9 = (int)nInitAllocationCount->m_pMemory;
      if ( v5 >= 0 )
        return CUtlMemory<unsigned char>::CUtlMemory<unsigned char>(
                 this: nInitAllocationCount,
                 (int)nGrowSize,
                 nInitAllocationCount: v9) == nullptr;
      else
        return CUtlMemory<unsigned char>::CUtlMemory<unsigned char>(
                 this: nInitAllocationCount,
                 nGrowSize: *nGrowSize,
                 nInitAllocationCount: v9) == nullptr;
    case 7:
      return (unsigned __int8 *)*nGrowSize == nInitAllocationCount->m_pMemory
          && *(nGrowSize + 1) == nInitAllocationCount->m_nAllocationCount;
    default:
      AssertMsgImplementation(a1: "Assertion Failed: false", 0, "..\\tier1\\KeyValues.cpp", 2737, &unk_3F665805, 0);
      return 1;
  }
  while ( v10 != 0 )
  {
    if ( m_pMemory == 0 || (unsigned __int8)sub_3F61EEF0(nGrowSize: v10, nInitAllocationCount: m_pMemory) == 0 )
      return v12;
    v10 = *(_DWORD *)(v10 + 12);
    m_pMemory = *(_DWORD *)(m_pMemory + 12);
  }
  if ( m_pMemory == 0 )
    return 1;
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x3F61F0B8
// Name: _setlocale_set_cat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__userpurge setlocale_set_cat@<eax>(char *result@<eax>, char *category)
{
  if ( (char)result >= 0 )
  {
    result = category;
    if ( category != nullptr )
      return (char *)(*(int (__thiscall **)(_DWORD, char *, _DWORD))(*g_pMemAllocSteam + 24))(
                       a1: g_pMemAllocSteam,
                       a2: category,
                       a3: 0);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61F0E0
// Name: sub_3F61F0E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall sub_3F61F0E0(int this, CValidator *a2, int a3, int a4, char a5)
{
  _DWORD *i; // esi

  if ( *(int *)(this + 8) < 0 )
    CValidator::ClaimMemory(this: a2, a2: *(void **)this);
  if ( a5 != 0 )
  {
    for ( i = *(_DWORD **)(this + 12); i != nullptr; i = (_DWORD *)i[3] )
    {
      CValidator::ClaimMemory(this: a2, a2: i);
      sub_3F61F0E0(a1: a2, a2: "KeyValues", a3: 0, a4: 0);
    }
  }
  if ( (*(_BYTE *)(this + 11) & 0x3F) == 0 && *(_DWORD *)this != 0 )
  {
    CValidator::ClaimMemory(this: a2, a2: *(void **)this);
    sub_3F61F0E0(a1: a2, a2: "KeyValues", a3: 0, a4: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F61F1E0
// Name: sub_3F61F1E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F61F1E0@<eax>(int result@<eax>, int a2@<ecx>)
{
  *(_DWORD *)(result + 256) = a2;
  *(_DWORD *)(result + 264) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61F2B0
// Name: sub_3F61F2B0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__usercall sub_3F61F2B0@<eax>(const char *ArgList@<ecx>, int a2@<eax>, int a3)
{
  int i; // edi
  char *v5; // eax
  char *v6; // eax
  threadlocaleinfostruct *v7; // edx
  const char *v8; // ecx
  int v10; // [esp-8h] [ebp-210h]
  int v11; // [esp-8h] [ebp-210h]
  int v12; // [esp+4h] [ebp-204h] BYREF
  char Buffer[512]; // [esp+8h] [ebp-200h] BYREF

  Q_snprintf(Buffer, a2: 512, Format: "KeyValues Error: %s in file %s\n", ArgList, *(const char **)(a2 + 256));
  for ( i = 0; i < *(_DWORD *)(a2 + 264); ++i )
  {
    if ( *(_DWORD *)(a2 + 4 * i) != 0 )
    {
      if ( i >= *(_DWORD *)(a2 + 260) )
      {
        Q_strcat(a1: Buffer, Source: "(*", a3: 512);
        v11 = *(_DWORD *)(a2 + 4 * i);
        v6 = (char *)(*(int (__thiscall **)(int *))(dword_3F6642E0 + 8))(a1: &dword_3F6642E0);
        Q_strcat(a1: (const char *)&v12, Source: v6, a3: v11);
        Q_strcat(a1: (const char *)&v12, Source: "*), ", a3: 512);
      }
      else
      {
        v10 = *(_DWORD *)(a2 + 4 * i);
        v5 = (char *)(*(int (__thiscall **)(int *))(dword_3F6642E0 + 8))(a1: &dword_3F6642E0);
        Q_strcat(a1: (const char *)&v12, Source: v5, a3: v10);
        Q_strcat(a1: (const char *)&v12, Source: ", ", a3: 512);
      }
    }
  }
  Q_strcat(a1: (const char *)&v12, Source: "\n", a3: 512);
  return setlocale_nolock(ploci: v7, _category: a3, _locale: v8);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F3AE
// Name: _setlocale_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall setlocale_nolock@<eax>(char a1@<zf>, int a2@<esi>)
{
  char v5[472]; // [esp-1D8h] [ebp-1F8h] BYREF

  if ( !a1 )
    Warning(a1: "%s", v5);
  return (char *)((int (__cdecl *)(int, char *))loc_3F61AA50)(a1: a2 + 272, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F3E0
// Name: sub_3F61F3E0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__usercall sub_3F61F3E0@<eax>(int a1@<edi>, int a2@<esi>)
{
  char *v2; // eax
  _DWORD *v3; // eax
  int v4; // edx
  _DWORD *v5; // esi
  int (__thiscall *v6)(int *, void *); // eax
  _DWORD v8[2]; // [esp+10h] [ebp-4Ch] BYREF
  int v9; // [esp+18h] [ebp-44h]

  if ( (dword_3F665D0C & 1) != 0 )
  {
    v2 = (char *)dword_3F665D08;
  }
  else
  {
    dword_3F665D0C |= 1u;
    v2 = sub_3F6097C0();
    dword_3F665D08 = (int)v2;
  }
  v9 = a2;
  if ( v2 != nullptr )
  {
    v4 = *g_pMemAllocSteam;
    v8[1] = 0;
    v3 = (_DWORD *)(*(int (__thiscall **)(_DWORD, int, char *, _DWORD, int))(v4 + 4))(
                     a1: g_pMemAllocSteam,
                     a2: 16,
                     a3: v2,
                     a4: 0,
                     a5: 1);
  }
  else
  {
    v3 = (_DWORD *)(*(int (__thiscall **)(_DWORD, int, int))(*g_pMemAllocSteam + 8))(
                     a1: g_pMemAllocSteam,
                     a2: 16,
                     a3: v9);
  }
  v5 = v3;
  if ( v3 != nullptr )
  {
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    v6 = *(int (__thiscall **)(int *, void *))(dword_3F6642E0 + 12);
    v8[0] = &unk_3F6642AC;
    v5[2] ^= (v6(a1: &dword_3F6642E0, a2: &unk_3F656D69) ^ v5[2]) & 0xFFFFFF;
  }
  else
  {
    v5 = nullptr;
  }
  if ( a1 != 0 )
  {
    ((void (__thiscall *)(int, _DWORD *, int))loc_3F623570)(a1, a2: v8, a3: 8);
    ((void (__thiscall *)(_DWORD *, _DWORD *, _DWORD))loc_3F61E7D0)(a1: v5, a2: v8, a3: 0);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F61F4C0
// Name: sub_3F61F4C0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
localeinfo_struct *__usercall sub_3F61F4C0@<eax>(int a1@<esi>, char *Format, ...)
{
  int v2; // eax
  bool v3; // cl
  const char *ArgList; // [esp+14h] [ebp+8h] BYREF
  va_list ArgLista; // [esp+14h] [ebp+8h]
  va_list va1; // [esp+18h] [ebp+Ch] BYREF

  va_start(va1, Format);
  va_start(ArgLista, Format);
  ArgList = va_arg(va1, const char *);
  *(_DWORD *)a1 = &CFmtStrN<256>::`vftable';
  *(_BYTE *)(a1 + 8) = 1;
  if ( a1 == -9 )
    AssertMsgImplementation(
      a1: "Assertion Failed: count == 0 || ptr != NULL",
      0,
      ".\\strtools.cpp",
      109,
      &unk_3F665782,
      0);
  if ( Format == nullptr )
    AssertMsgImplementation(a1: "Assertion Failed: ptr", 0, ".\\strtools.cpp", 88, &unk_3F66577F, 0);
  v2 = _vsnprintf_0(Buffer: (char *const)(a1 + 9), BufferCount: 0xFEu, Format, ArgList: ArgLista);
  v3 = v2 < 0;
  if ( v2 < 0 )
    v2 = 254;
  *(_BYTE *)(v2 + a1 + 9) = 0;
  *(_BYTE *)(a1 + 264) = 0;
  if ( v3 && *(_BYTE *)(a1 + 8) == 0 && dword_3F665808 < 5 )
  {
    AssertMsgImplementation(
      a1: "Assertion Failed: !bTruncated",
      0,
      "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/fmtstr.h",
      63,
      &unk_3F66580C,
      0);
    ++dword_3F665808;
  }
  return _create_locale(_category: (int)Format, _locale: ArgList);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F57C
// Name: __create_locale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
localeinfo_struct *__usercall _create_locale@<eax>(const char *a1@<eax>, int a2@<edx>, int a3@<esi>)
{
  *(_DWORD *)(a3 + 4) = &a1[strlen(a1) + 1 - a2];
  return (localeinfo_struct *)a3;
}

//------------------------------------------------------------------------------
// Address: 0x3F61F66F
// Name: ___create_locale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __create_locale()
{
  __debugbreak();
  JUMPOUT(0x3F61F673);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F674
// Name: _setlocale
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setlocale(size_t a1@<eax>, int a2@<ecx>, int a3@<edi>, int a4@<esi>)
{
  *(_DWORD *)(a4 + 20) += a3;
  qsort_0(Base: *(void **)(a2 + 4), NumOfElements: a1, SizeOfElements: 4u, CompareFunction: CompareFunction);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F7E4
// Name: _use_encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__usercall use_encode_pointer@<eax>(int _EAX@<eax>, char a2@<ch>, int a3@<ebx>, int a4@<esi>, void *a5)
{
  bool v5; // cf
  bool v6; // zf

  v5 = __CFADD__(a2, byte_3F654324[_EAX - 1063600876]);
  v6 = a2 + byte_3F654324[_EAX - 1063600876] == 0;
  byte_3F654324[_EAX - 1063600876] += a2;
  if ( v5 )
  {
    __asm { aas }
    AssertMsgImplementation(a1: "Assertion Failed: IsValidIndex(elem) || ( m_Size == 0 ) || ( num == 0 )", 0);
    if ( *(_DWORD *)(a4 + 16) - a3 - 1 <= 0 )
      JUMPOUT(0x3F61F891);
    if ( !sub_3F614FF0(a1: a3, a2: a4) )
      AssertMsgImplementation(
        a1: "Assertion Failed: IsValidIndex(i)",
        0,
        "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
        306,
        &unk_3F665811,
        0);
    v6 = !sub_3F614FF0(a1: a3 + 1, a2: a4);
  }
  if ( !v6 )
    JUMPOUT(0x3F61F871);
  return _encode_pointer(ptr: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F850
// Name: __encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *__userpurge _encode_pointer@<eax>(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>, char *ptr)
{
  AssertMsgImplementation(
    a1: "Assertion Failed: IsValidIndex(i)",
    0,
    "d:\\buildslave\\steam_rel_client_win32\\build\\src\\public\\tier1/utlvector.h",
    306,
    &unk_3F665811,
    0);
  return memcpy_0(a1: (void *)(*(_DWORD *)(a4 + 4) + 4 * a2), Src: &ptr[4 * a1], Size: 4 * a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F8BE
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _encoded_null(char a1@<al>, _BYTE *a2@<ecx>)
{
  *a2 += a1;
  JUMPOUT(0x3F61F8C0);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F910
// Name: sub_3F61F910
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F61F910@<eax>(int result@<eax>)
{
  *(_WORD *)(result + 40) = 0;
  *(_DWORD *)(result + 32) = 0;
  *(_DWORD *)(result + 28) = 0;
  *(_DWORD *)(result + 12) = result + 12;
  *(_DWORD *)(result + 16) = result + 12;
  *(_DWORD *)(result + 44) = 0;
  *(_DWORD *)(result + 36) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61F930
// Name: sub_3F61F930
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_3F61F930(void (__stdcall *a1)(void *))
{
  return __crtTlsAlloc(lpCallBack: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F935
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  JUMPOUT(0x3F61F93D);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F93E
// Name: __fls_getvalue(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61F953
// Name: ___get_flsindex
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __get_flsindex(int a1, int a2)
{
  (*(void (**)(void))(a2 + 24))();
  JUMPOUT(0x3F61F958);
}

//------------------------------------------------------------------------------
// Address: 0x3F61F959
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void *(__stdcall *__userpurge __set_flsgetvalue@<eax>(
        int _EAX@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4))(unsigned int)
{
  void *(__stdcall *result)(unsigned int); // eax

  *(_WORD *)(a2 + 40) = a3;
  *(_DWORD *)(a2 + 32) = a3;
  *(_DWORD *)(a2 + 28) = a3;
  *(_DWORD *)(a2 + 44) = a3;
  *(_DWORD *)(a2 + 36) = a3;
  __asm { aas }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61F98B
// Name: __fls_setvalue(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __fastcall __fls_setvalue(int a1, int a2)
{
  *(_BYTE *)(a2 + 104) &= a2;
  *(char *)(a2 - 788578459) >>= 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F61F9A4
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F61F9E1
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _initptd(int _EAX@<eax>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 369049445) += BYTE1(a2);
  LOBYTE(_EAX) = _EAX ^ 0x42;
  __asm { aas }
}

//------------------------------------------------------------------------------
// Address: 0x3F61FAA0
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _getptd_noexit(int a1@<eax>, char a2@<ch>)
{
  LOBYTE(a1) = a1 + 106;
  *(_BYTE *)(a1 - 36) += a2;
  JUMPOUT(0x3F61FAA5);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FB17
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _getptd(char a1@<al>, unsigned __int16 a2@<dx>, int a3@<ebp>)
{
  unsigned __int8 v3; // al
  char v4; // cc

  v3 = (a1 | 0x8B) + 115;
  v4 = (*(_DWORD *)(a3 - 286343470) + 1 < 0) ^ __OFADD__(1, *(_DWORD *)(a3 - 286343470))
     | (*(_DWORD *)(a3 - 286343470) == -1);
  ++*(_DWORD *)(a3 - 286343470);
  __outbyte(a2, v3);
  __outbyte(a2, v3);
  if ( !v4 )
    JUMPOUT(0x3F61FB2D);
  JUMPOUT(0x3F61FB39);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FB2F
// Name: _freefls(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _freefls(_DWORD *a1@<ecx>, int a2@<ebx>, int a3@<edi>, int a4@<esi>)
{
  bool v4; // zf

  v4 = (_DWORD *)((char *)a1 + a1[35815196]) == nullptr;
  a1[35815196] += a1;
  if ( !v4 )
    JUMPOUT(0x3F61FB27);
  *(a1 - 1) = a4;
  *a1 = 0;
  *(_DWORD *)(a3 + 44) += a2;
  ++*(_WORD *)(a3 + 40);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FB50
// Name: sub_3F61FB50
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F61FB50()
{
  return sub_3F61FB60();
}

//------------------------------------------------------------------------------
// Address: 0x3F61FB60
// Name: sub_3F61FB60
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall sub_3F61FB60@<eax>(unsigned int a1@<eax>, unsigned int *a2@<ecx>)
{
  unsigned int v3; // esi
  const char *v4; // eax
  int v6; // eax

  if ( a1 > *a2 )
    return 0;
  v3 = a2[7];
  if ( v3 == 0 )
  {
    if ( a2[2] == 0 )
      return 0;
    ((void (*)(void))loc_3F61F9F0)();
    v3 = a2[7];
    if ( v3 == 0 )
    {
      if ( a2[2] != 3 )
      {
        v4 = (const char *)((int (*)(const char *, ...))loc_3F6027D0)(
                             a1: "Assertion Failed: %s",
                             "CMemoryPool::Alloc: ran out of memory");
        AssertMsgImplementation(a1: v4, 0, "..\\tier1\\mempool.cpp", 290, &unk_3F665816, 0);
      }
      return 0;
    }
  }
  ++a2[8];
  v6 = a2[9];
  if ( v6 <= (int)a2[8] )
    v6 = a2[8];
  a2[9] = v6;
  if ( *(_DWORD *)(v3 - 4) != -286331154 )
    AssertMsgImplementation(
      a1: "Assertion Failed: k_nMemPoolMagic_Free == *(( (int *) returnBlock) - 1)",
      0,
      "..\\tier1\\mempool.cpp",
      302,
      &unk_3F665817,
      0);
  *(_DWORD *)(v3 - 4) = -1431655766;
  a2[7] = *(_DWORD *)a2[7];
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F61FC50
// Name: __freeptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _freeptd(unsigned __int8 a1@<al>, unsigned __int16 a2@<dx>, int a3@<edi>, _DWORD *a4@<esi>)
{
  int v4; // eax

  __outbyte(a2, a1);
  __outbyte(a2, a1);
  __outbyte(a2, a1);
  __outbyte(a2, a1);
  v4 = *(_DWORD *)(a3 + 28);
  --*(_DWORD *)(a3 + 32);
  *a4 = v4;
  *(_DWORD *)(a3 + 28) = a4;
}

//------------------------------------------------------------------------------
// Address: 0x3F61FCB9
// Name: ___threadid
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall __threadid(int a1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F61FCBF
// Name: ___threadhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __threadhandle@<eax>(int a1@<eax>)
{
  __debugbreak();
  *(_DWORD *)(a1 + 4) = 0;
  return _mtinit();
}

//------------------------------------------------------------------------------
// Address: 0x3F61FCC5
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mtinit@<eax>(int result@<eax>, int a2@<ecx>)
{
  *(_WORD *)result = a2;
  *(_DWORD *)(result + 8) = a2;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F61FE49
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg()
{
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  __debugbreak();
  JUMPOUT(0x3F61FE50);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FE53
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(int a1@<edi>, int a2@<esi>)
{
  *(_DWORD *)(a2 + 8) = 3;
  *(_DWORD *)(a2 + 4) = ntohl(netlong: *(_DWORD *)(a1 + 4));
  *(_WORD *)a2 = ntohs(netshort: *(_WORD *)(a1 + 2));
}

//------------------------------------------------------------------------------
// Address: 0x3F61FF4F
// Name: __set_invalid_parameter_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _set_invalid_parameter_handler(
        char *a1@<edx>,
        void (__cdecl *pNew)(const wchar_t *, const wchar_t *, const wchar_t *, unsigned int, unsigned int),
        int a3,
        int a4,
        int a5,
        int a6,
        ...)
{
  _BYTE *v6; // eax
  const char *v7; // [esp-4h] [ebp-8h]
  size_t v8; // [esp+0h] [ebp-4h]
  va_list va; // [esp+1Ch] [ebp+18h] BYREF

  va_start(va, a6);
  strncpy_0(Destination: a1, Source: v7, Count: v8);
  v6 = (_BYTE *)sub_3F62B2A0(a1: (int *)va, a2: 58);
  if ( v6 != nullptr )
    *v6 = 0;
  JUMPOUT(0x3F61FF70);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FF71
// Name: __get_invalid_parameter_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _get_invalid_parameter_handler(const char *this)
{
  gethostbyname(name: this);
  JUMPOUT(0x3F61FF7D);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FF7E
// Name: void _invoke_watson(unsigned short const __near *,unsigned short const __near *,unsigned short const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invoke_watson()
{
  JUMPOUT(0x3F61FF83);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FF87
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _invalid_parameter(int a1@<edi>, int a2@<esi>)
{
  u_long v2; // [esp-8h] [ebp-8h]

  *(_DWORD *)(a1 + 4) = ntohl(netlong: v2);
  if ( a2 != 0 )
    *(_WORD *)a1 = sub_3F628FBF(String: (char *)(a2 + 1));
  JUMPOUT(0x3F61FFAA);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FFAB
// Name: __invalid_parameter_noinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo()
{
  const unsigned __int16 *v0; // [esp+18h] [ebp+4h]
  const unsigned __int16 *v1; // [esp+1Ch] [ebp+8h]
  const unsigned __int16 *v2; // [esp+20h] [ebp+Ch]
  unsigned int v3; // [esp+24h] [ebp+10h]
  unsigned int v4; // [esp+28h] [ebp+14h]

  __debugbreak();
  __debugbreak();
  __debugbreak();
  _invalid_parameter(pszExpression: v0, pszFunction: v1, pszFile: v2, nLine: v3, pReserved: v4);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FFBB
// Name: void _invalid_parameter(unsigned short const __near *,unsigned short const __near *,unsigned short const __near *,unsigned int,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(int a1@<esi>, const unsigned __int16 *pszExpression)
{
  *(_DWORD *)(a1 + 4) = 0;
  _get_errno_from_oserr(oserrno: (unsigned int)pszExpression);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FFC4
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _get_errno_from_oserr(int a1@<esi>, __int16 oserrno, u_long a3)
{
  SOCKET v3; // [esp-Ch] [ebp-Ch]
  struct sockaddr *v4; // [esp-8h] [ebp-8h]
  int *v5; // [esp-4h] [ebp-4h]
  int retaddr; // [esp+0h] [ebp+0h]

  *(_WORD *)a1 = 0;
  *(_DWORD *)(a1 + 8) = 3;
  retaddr = 16;
  if ( getsockname(s: v3, name: v4, namelen: v5) == 0 )
  {
    if ( oserrno == 2 )
    {
      *(_DWORD *)(a1 + 8) = 3;
      ntohl(netlong: a3);
      JUMPOUT(0x3F61FFFC);
    }
    JUMPOUT(0x3F620011);
  }
  JUMPOUT(0x3F620024);
}

//------------------------------------------------------------------------------
// Address: 0x3F61FFFF
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
u_short __usercall _errno@<ax>(int a1@<eax>, u_short a2@<cx>, int a3@<esi>)
{
  u_short result; // ax

  *(_DWORD *)(a3 + 4) = a1;
  result = ntohs(netshort: a2);
  *(_WORD *)a3 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F620012
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __doserrno()
{
  JUMPOUT(0x3F620015);
}

//------------------------------------------------------------------------------
// Address: 0x3F620025
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F620043
// Name: __set_errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_errno()
{
  JUMPOUT(0x3F62005B);
}

//------------------------------------------------------------------------------
// Address: 0x3F62005E
// Name: __get_errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F620088
// Name: __set_doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F6200A3
// Name: __get_doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _get_doserrno(
        int a1@<eax>,
        int a2@<edx>,
        int a3@<ecx>,
        _DWORD *a4@<edi>,
        int a5@<esi>,
        unsigned int *pValue,
        int a7,
        int a8,
        unsigned __int8 a9,
        int a10,
        int a11)
{
  LOBYTE(a1) = a1 & 0x24;
  *a4 = a9 + ((a1 + ((a2 + (a3 << 8)) << 8)) << 8);
  if ( a11 != a5 )
    JUMPOUT(0x3F6200CC);
  JUMPOUT(0x3F6200E2);
}

//------------------------------------------------------------------------------
// Address: 0x3F6200CD
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _amsg_exit()
{
  JUMPOUT(0x3F6200D1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6200F1
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __crtCorExitProcess(unsigned __int16 a1@<dx>, int a2@<ebx>, char *a3@<esi>)
{
  __inbyte(a1);
  *(_BYTE *)(a2 - 117) |= a1;
  if ( a3 != nullptr && a2 != 0 )
  {
    if ( *a3 >= 48 )
      JUMPOUT(0x3F620116);
    JUMPOUT(0x3F620175);
  }
  JUMPOUT(0x3F6201D6);
}

//------------------------------------------------------------------------------
// Address: 0x3F620117
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __crtExitProcess(int a1@<esi>)
{
  if ( sub_3F62B2A0(a1, a2: 46) != 0 )
    JUMPOUT(0x3F620129);
  JUMPOUT(0x3F620175);
}

//------------------------------------------------------------------------------
// Address: 0x3F62012C
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F620135
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62013E
// Name: _initterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F620176
// Name: __get_osplatform
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _get_osplatform(int a1@<ebx>, int a2@<ebp>)
{
  *(_BYTE *)(a2 + 2 * a1 + 60) ^= BYTE1(a1);
  if ( sub_3F62B2A0(a1, a2: 46) != 0 )
    JUMPOUT(0x3F6201AA);
  JUMPOUT(0x3F6201D6);
}

//------------------------------------------------------------------------------
// Address: 0x3F6201AD
// Name: __get_osver
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __userpurge _get_osver@<eax>(int a1@<ecx>, int a2@<ebp>, unsigned int *pValue, char a4, int a5, int a6)
{
  bool v6; // cc
  int v7; // ecx
  int result; // eax
  int v9; // [esp-Ch] [ebp-Ch]

  v6 = *(_BYTE *)(a1 - 1993333636) < (unsigned __int8)a1;
  *(_BYTE *)(a1 - 1993333636) -= a1;
  if ( !v6 )
  {
    MEMORY[0xCA620281]();
    v9 = v7;
    LOBYTE(v7) = a4;
    return ((int (__thiscall *)(int, int, int, int))loc_3F61FD10)(a1: v7, a2, a3: a6, a4: v9);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6201E9
// Name: __get_winver
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_winver@<eax>(
        char a1@<zf>,
        unsigned __int8 *a2@<eax>,
        int a3@<edx>,
        size_t a4@<edi>,
        char *a5@<esi>,
        unsigned int *pValue)
{
  if ( !a1 && (unsigned int)++a3 <= 0x20 )
    JUMPOUT(0x3F6201E7);
  if ( *a2 == 0 )
    JUMPOUT(0x3F620228);
  _snprintf(Buffer: a5, BufferCount: a4, Format: "%i.%i.%i.%i/%i", a2[3], a2[2], a2[1], *a2, 32 - a3);
  return _get_winmajor(pValue);
}

//------------------------------------------------------------------------------
// Address: 0x3F620225
// Name: __get_winmajor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _get_winmajor@<eax>(int a1@<esi>)
{
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F620261
// Name: __get_winminor
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F6297B0
// Name: _strcspn_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl strcspn_0(const char *Str, const char *Control)
{
  unsigned int v2; // eax
  size_t v5; // ecx
  signed __int32 v7[9]; // [esp+0h] [ebp-24h] BYREF

  v2 = 0;
  memset(v7, 0, 32);
  while ( 1 )
  {
    LOBYTE(v2) = *Control;
    if ( *Control == 0 )
      break;
    ++Control;
    _bittestandset(v7, v2);
  }
  v5 = -1;
  do
  {
    ++v5;
    LOBYTE(v2) = *Str;
    if ( *Str == 0 )
      break;
    ++Str;
  }
  while ( !_bittest(v7, v2) );
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F629800
// Name: _strpbrk_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strpbrk_0(const char *Str, const char *Control)
{
  char *result; // eax
  signed __int32 v5[9]; // [esp+0h] [ebp-24h] BYREF

  result = nullptr;
  memset(v5, 0, 32);
  while ( 1 )
  {
    LOBYTE(result) = *Control;
    if ( *Control == 0 )
      break;
    ++Control;
    _bittestandset(v5, (unsigned int)result);
  }
  while ( 1 )
  {
    LOBYTE(result) = *Str;
    if ( *Str == 0 )
      break;
    ++Str;
    if ( _bittest(v5, (unsigned int)result) )
      return (char *)(Str - 1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F629852
// Name: __freea_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea_0(void *Memory)
{
  if ( Memory == nullptr || *((_DWORD *)Memory - 2) != 56797 )
    JUMPOUT(0x3F62986C);
  __init_ctype(ploci: (threadlocaleinfostruct *)Memory);
}

//------------------------------------------------------------------------------
// Address: 0x3F629865
// Name: ___init_ctype
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __init_ctype@<eax>(int a1@<eax>)
{
  return ((int (__cdecl *)(int))loc_3F609ED0)(a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F629BFA
// Name: ____mb_cur_max_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F629C23
// Name: ____mb_cur_max_l_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall ___mb_cur_max_l_func(char a1@<cf>, int a2@<eax>, int a3@<ebx>)
{
  *(_DWORD *)(2 * a2 + 0x55C3C900) -= a1 + a3;
  JUMPOUT(0x3F629C35);
}

//------------------------------------------------------------------------------
// Address: 0x3F629C39
// Name: ____lc_codepage_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall ___lc_codepage_func@<eax>(int a1@<ebp>)
{
  int result; // eax

  if ( (*(_DWORD *)(a1 - 11472827))-- != 1 )
    JUMPOUT(0x3F629C4D);
  result = ((int (__cdecl *)(_DWORD))loc_3F629AA8)(a1: *(_DWORD *)(a1 + 8));
  if ( *(_BYTE *)(a1 - 4) != 0 )
    *(_DWORD *)(*(_DWORD *)(a1 - 8) + 112) &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F629C5F
// Name: ____lc_collate_cp_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall ___lc_collate_cp_func(int a1@<eax>, int a2@<ebx>)
{
  LOBYTE(a1) = a1 & 0xC;
  ((void (__usercall *)(char@<cf>, int@<eax>, int@<ebx>))((char *)&___mb_cur_max_l_func + 6))(a1: 0, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F629C85
// Name: ____lc_handle_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl ___lc_handle_func(threadlocaleinfostruct *ploci)
{
  if ( dword_3F6637BC == 0 )
  {
    if ( ploci == nullptr )
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      JUMPOUT(0x3F629CAD);
    }
    JUMPOUT(0x3F629CB4);
  }
  JUMPOUT(0x3F629CD2);
}

//------------------------------------------------------------------------------
// Address: 0x3F629CAE
// Name: __Getdays_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall _Getdays_l@<al>(char a1@<cf>, int a2@<eax>, char a3@<cl>, int _EBX@<ebx>, int a5@<esi>)
{
  _BYTE *v5; // edx
  char result; // al

  v5 = *(_BYTE **)(_EBX + a5);
  __asm { rcr     byte ptr [ebx-3Dh], 38h }
  *(_BYTE *)(_EBX - 1976863536) -= a1 + a3;
  result = *(_BYTE *)(a2 + 175915513) | a2;
  if ( a3 <= 90 )
    *v5 = a3 + 32;
  if ( v5[1] != (_BYTE)_EBX )
    JUMPOUT(0x3F629CBA);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F629DAC
// Name: __Getdays
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _Getdays(int a1@<edx>, char a2@<ch>)
{
  *(_BYTE *)(a1 + 34) += a2;
  JUMPOUT(0x3F629D06);
}

//------------------------------------------------------------------------------
// Address: 0x3F629DB5
// Name: __Getmonths_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _Getmonths_l(
        char a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        wchar_t *a4@<ecx>,
        wchar_t *a5@<ebx>,
        int a6@<ebp>,
        DWORD a7@<edi>,
        int *a8@<esi>)
{
  unsigned int v8; // eax
  void *v9; // esp
  int *v10; // eax
  int retaddr; // [esp+10h] [ebp+0h] BYREF

  __asm { into }
  if ( !(a2 ^ a3 | a1) && 0xFFFFFFE0 / (unsigned int)a4 >= 2 )
  {
    v8 = 2 * (_DWORD)a4 + 8;
    if ( v8 > 0x400 )
    {
      v10 = (int *)((int (__cdecl *)(int))loc_3F609A30)(a1: 2 * (_DWORD)a4 + 8);
      if ( v10 != a8 )
      {
        *v10 = 56797;
        goto LABEL_8;
      }
    }
    else
    {
      v9 = alloca(v8);
      v10 = &retaddr;
      if ( &retaddr != a8 )
      {
        retaddr = 52428;
LABEL_8:
        v10 += 2;
      }
    }
    a4 = *(wchar_t **)(a6 - 12);
    *(_DWORD *)(a6 - 8) = v10;
    goto LABEL_11;
  }
  *(_DWORD *)(a6 - 8) = a8;
LABEL_11:
  if ( *(int **)(a6 - 8) == a8 )
  {
    *_errno_0() = 12;
    JUMPOUT(0x3F629D94);
  }
  if ( __crtLCMapStringW(
         a1: *(_DWORD *)(a6 + 12),
         Locale: *(_DWORD *)(**(_DWORD **)(a6 + 12) + 20),
         dwMapFlags: a7,
         lpSrcStr: a5,
         cchSrc: (wchar_t *)0xFFFFFFFF,
         lpDestStr: *(LPWSTR *)(a6 - 8),
         cchDest: a4,
         CodePage: *(_DWORD *)(**(_DWORD **)(a6 + 12) + 4)) != 0 )
    wcscpy_s(Destination: a5, SizeInWords: *(_DWORD *)(a6 + 8), Source: *(const wchar_t **)(a6 - 8));
  else
    *_errno_0() = 42;
  _freea_0(Memory: *(void **)(a6 - 8));
  __security_check_cookie`...'(StackCookie: a6 ^ *(_DWORD *)(a6 - 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F629EBC
// Name: __Gettnames_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
localeinfo_struct *__cdecl _Gettnames_l(localeinfo_struct *plocinfo)
{
  ((void (*)(void))loc_3F629E6E)();
  return plocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x3F629ECB
// Name: __wcsupr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t *__cdecl _wcsupr(wchar_t *String)
{
  wchar_t *result; // eax
  wchar_t *i; // ecx
  wchar_t v3; // dx

  if ( dword_3F6637BC != 0 )
  {
    ((void (__cdecl *)(wchar_t *, int, _DWORD))loc_3F629E6E)(a1: String, a2: -1, a3: 0);
    return String;
  }
  else
  {
    result = String;
    if ( String != nullptr )
    {
      for ( i = String; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 0x61u && v3 <= 0x7Au )
          *i = v3 - 32;
      }
    }
    else
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F629F34
// Name: int _wcslwr_s_l_stat(wchar_t __near *,unsigned int,struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __usercall _wcslwr_s_l_stat@<eax>(wchar_t *a1@<ebx>, wchar_t *SizeInWords, unsigned int a3)
{
  int *v3; // eax
  int v4; // edi
  LCID v6; // ecx
  wchar_t *i; // eax
  wchar_t v8; // cx
  int v9; // eax
  wchar_t *v10; // ecx
  unsigned int v11; // eax
  void *v12; // esp
  _DWORD *v13; // eax
  errno_t v14; // esi
  int v15; // [esp-4h] [ebp-18h]
  _DWORD v16[2]; // [esp+0h] [ebp-14h] BYREF
  wchar_t *cchDest; // [esp+8h] [ebp-Ch]
  void *Memory; // [esp+Ch] [ebp-8h]

  if ( a1 == nullptr )
    goto LABEL_2;
  if ( wcsnlen(Source: a1, MaxCount: (size_t)SizeInWords) >= (unsigned int)SizeInWords )
  {
    *a1 = 0;
LABEL_2:
    v3 = _errno_0();
    v15 = 22;
LABEL_3:
    v4 = v15;
    *v3 = v15;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return v4;
  }
  v6 = *(_DWORD *)(*(_DWORD *)a3 + 20);
  if ( v6 != 0 )
  {
    v9 = __crtLCMapStringW(
           a1: a3,
           Locale: v6,
           dwMapFlags: 0x100u,
           lpSrcStr: a1,
           cchSrc: (wchar_t *)0xFFFFFFFF,
           lpDestStr: nullptr,
           cchDest: nullptr,
           CodePage: *(_DWORD *)(*(_DWORD *)a3 + 4));
    v10 = (wchar_t *)v9;
    cchDest = (wchar_t *)v9;
    if ( v9 == 0 )
    {
      *_errno_0() = 42;
      return *_errno_0();
    }
    if ( (unsigned int)SizeInWords < v9 )
    {
      *a1 = 0;
      v3 = _errno_0();
      v15 = 34;
      goto LABEL_3;
    }
    if ( v9 <= 0 || 0xFFFFFFE0 / v9 < 2 )
    {
      Memory = nullptr;
      goto LABEL_28;
    }
    v11 = 2 * v9 + 8;
    if ( v11 > 0x400 )
    {
      v13 = (_DWORD *)((int (__cdecl *)(int))loc_3F609A30)(a1: 2 * (_DWORD)v10 + 8);
      if ( v13 != nullptr )
      {
        *v13 = 56797;
        goto LABEL_25;
      }
    }
    else
    {
      v12 = alloca(v11);
      v13 = v16;
      if ( v16 != nullptr )
      {
        v16[0] = 52428;
LABEL_25:
        v13 += 2;
      }
    }
    v10 = cchDest;
    Memory = v13;
LABEL_28:
    if ( Memory != nullptr )
    {
      if ( __crtLCMapStringW(
             a1: a3,
             Locale: *(_DWORD *)(*(_DWORD *)a3 + 20),
             dwMapFlags: 0x100u,
             lpSrcStr: a1,
             cchSrc: (wchar_t *)0xFFFFFFFF,
             lpDestStr: (LPWSTR)Memory,
             cchDest: v10,
             CodePage: *(_DWORD *)(*(_DWORD *)a3 + 4)) != 0 )
      {
        v14 = wcscpy_s(Destination: a1, (rsize_t)SizeInWords, Source: (const wchar_t *)Memory);
      }
      else
      {
        *_errno_0() = 42;
        v14 = 42;
      }
      _freea_0(Memory);
      return v14;
    }
    *_errno_0() = 12;
    return *_errno_0();
  }
  for ( i = a1; *i != 0; ++i )
  {
    v8 = *i;
    if ( *i >= 0x41u && v8 <= 0x5Au )
      *i = v8 + 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F62A0BB
// Name: __wcslwr_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _wcslwr_s_l(wchar_t *String, size_t SizeInWords, _locale_t Locale)
{
  errno_t result; // eax
  _LocaleUpdate v4; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v4, a2: Locale);
  result = _wcslwr_s_l_stat(a1: String, (wchar_t *)SizeInWords, a3: (unsigned int)&v4);
  if ( v4.updated )
    v4.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62A118
// Name: __wcslwr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t *__cdecl _wcslwr(wchar_t *String)
{
  wchar_t *result; // eax
  wchar_t *i; // ecx
  wchar_t v3; // dx

  if ( dword_3F6637BC != 0 )
  {
    _wcslwr_s_l(String, SizeInWords: 0xFFFFFFFF, Locale: nullptr);
    return String;
  }
  else
  {
    result = String;
    if ( String != nullptr )
    {
      for ( i = String; *i != 0; ++i )
      {
        v3 = *i;
        if ( *i >= 0x41u && v3 <= 0x5Au )
          *i = v3 + 32;
      }
    }
    else
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62A181
// Name: __tolower_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _tolower_0(int C)
{
  return C + 32;
}

//------------------------------------------------------------------------------
// Address: 0x3F62A21A
// Name: _store_str
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall store_str(char *in@<edx>, unsigned int *count@<eax>)
{
  *((_BYTE *)count - 24) += (_BYTE)in;
  JUMPOUT(0x3F62A21F);
}

//------------------------------------------------------------------------------
// Address: 0x3F62A23A
// Name: _store_number
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void store_number()
{
  __asm { aas }
  JUMPOUT(0x3F62A23C);
}

//------------------------------------------------------------------------------
// Address: 0x3F62A2A0
// Name: _tolower_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl tolower_0(int C)
{
  int result; // eax

  if ( dword_3F6637BC != 0 )
    return _tolower_l_0(C, Locale: nullptr);
  result = C;
  if ( (unsigned int)(C - 65) <= 0x19 )
    return C + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62A2E9
// Name: _expandtime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void expandtime()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F62A6CF
// Name: _store_winword
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
__int64 __usercall store_winword@<edx:eax>(int a1@<ebx>, _DWORD *a2@<ebp>, unsigned __int16 *a3@<edi>)
{
  unsigned __int16 v3; // si
  unsigned __int16 *v4; // edi
  int v5; // eax
  unsigned __int16 *v6; // edi
  unsigned int v7; // ebx
  int v8; // eax
  unsigned int v9; // ecx
  int v10; // eax
  unsigned __int16 *v11; // edi
  int v12; // eax
  int *v13; // eax
  bool v14; // zf
  unsigned __int16 **v15; // eax
  int v16; // ecx
  _DWORD *v18; // eax
  unsigned __int64 SystemTime_8; // [esp+8h] [ebp-18h]
  __int64 SystemTime_8a; // [esp+8h] [ebp-18h]

  v3 = *a3;
  v4 = a3 + 1;
  v5 = a2[5];
  if ( v5 >= 0 && v5 != 1 && v5 <= 36 )
  {
    if ( v5 == 0 )
    {
      if ( _wchartodigit_0(a1: v3) != 0 )
      {
        a2[5] = 10;
LABEL_16:
        SystemTime_8 = (int)a2[5];
        *((_QWORD *)a2 - 4) = SystemTime_8;
        *((_QWORD *)a2 - 3) = 0xFFFFFFFFFFFFFFFFuLL % SystemTime_8;
        *((_QWORD *)a2 - 2) = 0xFFFFFFFFFFFFFFFFuLL / SystemTime_8;
        while ( 1 )
        {
          v7 = _wchartodigit_0(a1: v3);
          if ( v7 == -1 )
          {
            if ( (v3 < 0x41u || v3 > 0x5Au) && (unsigned __int16)(v3 - 97) > 0x19u )
            {
LABEL_30:
              v10 = a2[6];
              v11 = v4 - 1;
              if ( (v10 & 8) != 0 )
              {
                if ( (v10 & 4) != 0
                  || (v10 & 1) == 0
                  && ((v12 = a2[6] & 2) != 0 && *((_QWORD *)a2 - 1) > 0x8000000000000000uLL
                   || v12 == 0 && (int)*(a2 - 1) < 0) )
                {
                  v13 = _errno_0();
                  v14 = (a2[6] & 1) == 0;
                  *v13 = 34;
                  if ( v14 )
                  {
                    if ( (a2[6] & 2) != 0 )
                    {
                      *(a2 - 2) = 0;
                      *(a2 - 1) = 0x80000000;
                    }
                    else
                    {
                      *(a2 - 2) = -1;
                      *(a2 - 1) = 0x7FFFFFFF;
                    }
                  }
                  else
                  {
                    *(a2 - 2) = -1;
                    *(a2 - 1) = -1;
                  }
                }
              }
              else
              {
                if ( a2[4] != 0 )
                  v11 = (unsigned __int16 *)a2[3];
                *(a2 - 2) = 0;
                *(a2 - 1) = 0;
              }
              v15 = (unsigned __int16 **)a2[4];
              if ( v15 != nullptr )
                *v15 = v11;
              if ( (a2[6] & 2) != 0 )
              {
                v16 = -*((_QWORD *)a2 - 1) >> 32;
                *(a2 - 2) = -*(a2 - 2);
                *(a2 - 1) = v16;
              }
              if ( *((_BYTE *)a2 - 36) != 0 )
                *(_DWORD *)(*(a2 - 10) + 112) &= ~2u;
              return *((_QWORD *)a2 - 1);
            }
            v8 = v3;
            if ( (unsigned __int16)(v3 - 97) <= 0x19u )
              v8 = v3 - 32;
            v7 = v8 - 55;
          }
          if ( v7 >= a2[5] )
            goto LABEL_30;
          v9 = *(a2 - 1);
          a2[6] |= 8u;
          if ( __PAIR64__(v9, *(a2 - 2)) < *((_QWORD *)a2 - 2)
            || *(a2 - 2) == *(a2 - 4) && v9 == *(a2 - 3) && (unsigned __int64)v7 <= *((_QWORD *)a2 - 3) )
          {
            HIDWORD(SystemTime_8a) = v9;
            LODWORD(SystemTime_8a) = *(a2 - 2);
            *((_QWORD *)a2 - 1) = v7 + *((_QWORD *)a2 - 4) * SystemTime_8a;
          }
          else
          {
            a2[6] |= 4u;
            if ( a2[4] == 0 )
              goto LABEL_30;
          }
          v3 = *v4++;
        }
      }
      if ( *v4 != 120 && *v4 != 88 )
      {
        a2[5] = 8;
        goto LABEL_16;
      }
      a2[5] = 16;
    }
    if ( a2[5] == 16 && _wchartodigit_0(a1: v3) == 0 && (*v4 == 120 || *v4 == 88) )
    {
      v6 = v4 + 1;
      v3 = *v6;
      v4 = v6 + 1;
    }
    goto LABEL_16;
  }
  v18 = (_DWORD *)a2[4];
  if ( v18 != nullptr )
    *v18 = a1;
  if ( *((_BYTE *)a2 - 36) != 0 )
    *(_DWORD *)(*(a2 - 10) + 112) &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F62A8EA
// Name: Q_wcstoi64_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Q_wcstoi64_0(int a1, int a2, int a3)
{
  if ( dword_3F6637BC != 0 )
    return ((int (__cdecl *)(_DWORD, int, int, int, _DWORD))loc_3F62A63A)(a1: 0, a2: a1, a3: a2, a4: a3, a5: 0);
  else
    return ((int (__cdecl *)(CUtlCharConversion::ConversionInfo_t *, int, int, int, _DWORD))loc_3F62A63A)(
             a1: &s_NoEscConversion.m_pReplacements[81],
             a2: a1,
             a3: a2,
             a4: a3,
             a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62A913
// Name: sub_3F62A913
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F62A913(int a1, int a2, int a3, int a4)
{
  return ((int (__cdecl *)(int, int, int, int, _DWORD))loc_3F62A63A)(a1: a4, a2: a1, a3: a2, a4: a3, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62A92E
// Name: Q_wcstoui64_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl Q_wcstoui64_0(int a1, int a2, int a3)
{
  if ( dword_3F6637BC != 0 )
    return ((int (__cdecl *)(_DWORD, int, int, int, int))loc_3F62A63A)(a1: 0, a2: a1, a3: a2, a4: a3, a5: 1);
  else
    return ((int (__cdecl *)(CUtlCharConversion::ConversionInfo_t *, int, int, int, int))loc_3F62A63A)(
             a1: &s_NoEscConversion.m_pReplacements[81],
             a2: a1,
             a3: a2,
             a4: a3,
             a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F62A980
// Name: _strncpy_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncpy_0(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  size_t v4; // ebx
  const char *v5; // esi
  char *v6; // edi
  size_t v7; // ecx
  char v8; // al
  size_t v10; // ecx
  int v11; // eax
  int v12; // edx

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Count;
  v5 = Source;
  v6 = Destination;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v7 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance_1;
copy_tail_loop_0:
    while ( 1 )
    {
      v8 = *v5++;
      *v6++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return Destination;
    }
    while ( --v4 != 0 )
finish_loop_0:
      *v6++ = v8;
    return Destination;
  }
  do
  {
    v8 = *v5++;
    *v6++ = v8;
    if ( --v3 == 0 )
      return Destination;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)v6 & 3) != 0 )
      {
        *v6++ = 0;
        if ( --v3 == 0 )
          return Destination;
      }
      v4 = v3;
      v10 = v3 >> 2;
      if ( v10 == 0 )
        goto finish_loop_0;
      goto fill_dwords_with_EOS_0;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start_1:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop_0;
    return Destination;
  }
  while ( 1 )
  {
main_loop_entrance_1:
    v11 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v12 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v11 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        break;
      if ( BYTE1(v12) == 0 )
      {
        *(_DWORD *)v6 = (unsigned __int8)v12;
        goto fill_with_EOS_dwords_0;
      }
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_DWORD *)v6 = (unsigned __int16)v12;
        goto fill_with_EOS_dwords_0;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v6 = v12;
        goto fill_with_EOS_dwords_0;
      }
    }
    *(_DWORD *)v6 = v12;
    v6 += 4;
    if ( --v7 == 0 )
      goto tail_loop_start_1;
  }
  *(_DWORD *)v6 = 0;
fill_with_EOS_dwords_0:
  v6 += 4;
  v8 = 0;
  v10 = v7 - 1;
  if ( v10 != 0 )
  {
fill_dwords_with_EOS_0:
    v8 = 0;
    do
    {
      *(_DWORD *)v6 = 0;
      v6 += 4;
      --v10;
    }
    while ( v10 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop_0;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x3F62AAA4
// Name: _wcsncpy_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t *__cdecl wcsncpy_0(wchar_t *Destination, const wchar_t *Source, size_t Count)
{
  size_t v3; // ecx
  wchar_t *v4; // edi
  wchar_t v6; // ax
  size_t v7; // ecx
  char v8; // cf
  size_t v9; // ecx
  wchar_t *v10; // edi
  int i; // ecx

  v3 = Count;
  v4 = Destination;
  if ( Count != 0 )
  {
    do
    {
      v6 = *Source;
      *v4++ = *Source++;
      if ( v6 == 0 )
        break;
      --v3;
    }
    while ( v3 != 0 );
    if ( v3 != 0 )
    {
      v7 = v3 - 1;
      if ( v7 != 0 )
      {
        v8 = v7 & 1;
        v9 = v7 >> 1;
        memset(v4, 0, 4 * v9);
        v10 = &v4[2 * v9];
        for ( i = v8; i != 0; --i )
          *v10++ = 0;
      }
    }
  }
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x3F62AAF0
// Name: _strncat_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat_0(char *Destination, const char *Source, size_t Count)
{
  char *i; // edi
  char v4; // al

  if ( Count != 0 )
  {
    for ( i = Destination; ((unsigned __int8)i & 3) != 0; ++i )
    {
      v4 = *i;
      if ( v4 == 0 )
        JUMPOUT(0x3F62AB4D);
    }
    JUMPOUT(0x3F62AB2A);
  }
  JUMPOUT(0x3F62ABB4);
}

//------------------------------------------------------------------------------
// Address: 0x3F62AB2C
// Name: __Strftime_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall _Strftime_l@<eax>(int a1@<eax>, unsigned int a2@<ecx>, int a3@<edi>, char *string, char *maxsize)
{
  _BYTE *v5; // edi
  unsigned int v6; // esi
  char v7; // bl
  unsigned int v8; // ecx
  int v9; // edx
  char v10; // dl
  int v12; // eax

  LOBYTE(a1) = a1 - 87;
  *(_BYTE *)a2 += a1;
  *(_DWORD *)(a2 + 1200351348) += a1;
  if ( (_BYTE)a1 != 0 )
  {
    if ( BYTE1(a1) != 0 )
    {
      if ( (a1 & 0xFF0000) != 0 )
      {
        if ( (a1 & 0xFF000000) != 0 )
          JUMPOUT(0x3F62AB2A);
        v5 = (_BYTE *)(a3 - 1);
      }
      else
      {
        v5 = (_BYTE *)(a3 - 2);
      }
    }
    else
    {
      v5 = (_BYTE *)(a3 - 3);
    }
  }
  else
  {
    v5 = (_BYTE *)(a3 - 4);
  }
  v6 = (unsigned int)maxsize;
  if ( ((unsigned __int8)maxsize & 3) == 0 )
  {
    v7 = a2;
    v8 = a2 >> 2;
    if ( v8 != 0 )
      goto main_loop_entrance_2;
    goto tail_loop_start_2;
  }
  do
  {
    LOBYTE(v9) = *(_BYTE *)v6++;
    if ( (_BYTE)v9 == 0 )
    {
LABEL_21:
      *v5 = v9;
      return string;
    }
    *v5++ = v9;
    if ( --a2 == 0 )
      goto empty_counter_0;
  }
  while ( (v6 & 3) != 0 );
  v7 = a2;
  v8 = a2 >> 2;
  if ( v8 == 0 )
  {
tail_loop_start_2:
    a2 = v7 & 3;
    if ( (v7 & 3) != 0 )
    {
      while ( 1 )
      {
        v10 = *(_BYTE *)v6++;
        *v5++ = v10;
        if ( v10 == 0 )
          break;
        if ( --a2 == 0 )
          goto empty_counter_0;
      }
    }
    else
    {
empty_counter_0:
      *v5 = a2;
    }
    return string;
  }
  while ( 1 )
  {
main_loop_entrance_2:
    v12 = (*(_DWORD *)v6 + 2130640639) ^ ~*(_DWORD *)v6;
    v9 = *(_DWORD *)v6;
    v6 += 4;
    if ( (v12 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v9 == 0 )
        goto LABEL_21;
      if ( BYTE1(v9) == 0 )
        break;
      if ( (v9 & 0xFF0000) == 0 )
      {
        *(_WORD *)v5 = v9;
        v5[2] = 0;
        return string;
      }
      if ( (v9 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v5 = v9;
        return string;
      }
    }
    *(_DWORD *)v5 = v9;
    v5 += 4;
    if ( --v8 == 0 )
      goto tail_loop_start_2;
  }
  *(_WORD *)v5 = (unsigned __int8)v9;
  return string;
}

//------------------------------------------------------------------------------
// Address: 0x3F62ACDB
// Name: __strftime_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strftime_l()
{
  JUMPOUT(0x3F62ACDD);
}

//------------------------------------------------------------------------------
// Address: 0x3F62AD16
// Name: __Strftime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _Strftime(int a1@<ecx>, char a2@<bl>)
{
  *(_BYTE *)(a1 + 89) += a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F62AD34
// Name: _localeconv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl localeconv()
{
  __asm { icebp }
  JUMPOUT(0x3F62AD36);
}

//------------------------------------------------------------------------------
// Address: 0x3F62AD5A
// Name: _strcat_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl strcat_s()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F62AE16
// Name: _strncpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall strncpy_s@<al>(char a1@<al>, int a2@<esi>)
{
  bool v2; // sf
  char result; // al
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v2 = (((unsigned int)&retaddr | *(_DWORD *)(a2 - 125)) & 0x80000000) != 0;
  *(_DWORD *)(a2 - 125) |= (unsigned int)&retaddr;
  if ( v2 )
    return 1;
  result = a1 + 95;
  if ( result == 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62AED0
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall memcpy(bool a1@<zf>, wchar_t *a2@<ebx>, int a3@<ebp>, wchar_t *a4@<edi>, int a5@<esi>)
{
  int v5; // esi
  int v6; // eax
  signed int FullPathNameW; // eax
  wchar_t *v8; // eax
  signed int v9; // eax
  DWORD LastError; // eax

  if ( a1 )
  {
    a2 = nullptr;
    a1 = a5 == 0;
    a4 = *(wchar_t **)(a3 + 12);
  }
  if ( !a1 )
    JUMPOUT(0x3F62B08F);
  v5 = _getdrive_0();
  if ( a4 == a2 )
  {
    *(_DWORD *)(a3 - 16) = a2;
  }
  else
  {
    v6 = *(_DWORD *)(a3 + 16);
    if ( v6 <= (int)a2 )
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: a2, a2, a3: a2, a4: a2, a5: a2);
      goto LABEL_26;
    }
    *(_DWORD *)(a3 - 16) = v6;
    *a4 = (unsigned __int16)a2;
  }
  if ( (wchar_t *)v5 == a2 )
  {
    *(_WORD *)(a3 - 12) = 46;
    JUMPOUT(0x3F62AF5C);
  }
  *(_WORD *)(a3 - 12) = v5 + 64;
  *(_WORD *)(a3 - 10) = 58;
  *(_WORD *)(a3 - 8) = 46;
  *(_WORD *)(a3 - 6) = (_WORD)a2;
  FullPathNameW = GetFullPathNameW(
                    lpFileName: (LPCWSTR)(a3 - 12),
                    nBufferLength: *(_DWORD *)(a3 - 16),
                    lpBuffer: a4,
                    lpFilePart: (LPWSTR *)(a3 - 20));
  if ( (wchar_t *)FullPathNameW == a2 )
    goto LABEL_25;
  if ( a4 != a2 )
  {
    if ( FullPathNameW >= *(_DWORD *)(a3 - 16) )
    {
      *_errno_0() = 34;
      *a4 = (unsigned __int16)a2;
    }
    goto LABEL_26;
  }
  if ( FullPathNameW > *(_DWORD *)(a3 + 16) )
    *(_DWORD *)(a3 + 16) = FullPathNameW;
  v8 = (wchar_t *)((int (__cdecl *)(_DWORD, int))loc_3F609A90)(a1: *(_DWORD *)(a3 + 16), a2: 2);
  if ( v8 == a2 )
  {
    *_errno_0() = 12;
    *__doserrno_0() = 8;
    goto LABEL_26;
  }
  v9 = GetFullPathNameW(
         lpFileName: (LPCWSTR)(a3 - 12),
         nBufferLength: *(_DWORD *)(a3 + 16),
         lpBuffer: v8,
         lpFilePart: (LPWSTR *)(a3 - 20));
  if ( (wchar_t *)v9 == a2 || v9 >= *(_DWORD *)(a3 + 16) )
  {
LABEL_25:
    LastError = GetLastError();
    _dosmaperr_0(a1: LastError);
  }
LABEL_26:
  __security_check_cookie`...'(StackCookie: a3 ^ *(_DWORD *)(a3 - 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F62B235
// Name: TranslateName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl TranslateName()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F62B295
// Name: GetLcidFromDefault
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl GetLcidFromDefault(int a1, char a2)
{
  sub_3F62B2A0(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B2A0
// Name: sub_3F62B2A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F62B2A0@<eax>(char *a1@<ecx>, setloc_struct *a2@<edi>, int a3, char a4)
{
  return ProcessCodePage(lpCodePageStr: a1, _psetloc_data: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B2A9
// Name: ProcessCodePage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall ProcessCodePage@<eax>(int a1@<eax>, int a2@<ebx>, char *a3)
{
  int v5; // eax
  char *v6; // edx
  char v7; // cl
  int v8; // ebx
  int v9; // ecx
  int v10; // esi
  int v11; // eax
  unsigned int v12; // eax

  v5 = a1 << 8;
  v6 = a3;
  if ( ((unsigned __int8)a3 & 3) != 0 )
  {
    while ( 1 )
    {
      v7 = *v6++;
      if ( v7 == (_BYTE)a2 )
        JUMPOUT(0x3F62B290);
      if ( v7 == 0 )
        break;
      if ( ((unsigned __int8)v6 & 3) == 0 )
        goto LABEL_5;
    }
  }
  else
  {
LABEL_5:
    v8 = v5 | a2 | ((v5 | a2) << 16);
    do
    {
      v9 = v8 ^ *(_DWORD *)v6;
      v10 = *(_DWORD *)v6 + 2130640639;
      v11 = v10 ^ ~*(_DWORD *)v6;
      v6 += 4;
      if ( (((v9 + 2130640639) ^ ~v9) & 0x81010100) != 0 )
        JUMPOUT(0x3F62B31F);
      v12 = v11 & 0x81010100;
    }
    while ( v12 == 0 || (v12 & 0x1010100) == 0 && v10 < 0 );
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F62B320
// Name: TestDefaultCountry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall TestDefaultCountry@<eax>(unsigned int a1@<eax>, char *a2@<edx>, char a3@<bl>)
{
  unsigned int v3; // eax

  if ( (_BYTE)a1 != 0 )
  {
    if ( BYTE1(a1) == a3 )
      JUMPOUT(0x3F62B350);
    if ( BYTE1(a1) != 0 )
    {
      v3 = HIWORD(a1);
      if ( (_BYTE)v3 == a3 )
        JUMPOUT(0x3F62B349);
      if ( (_BYTE)v3 != 0 )
      {
        if ( BYTE1(v3) == a3 )
          JUMPOUT(0x3F62B342);
        return LcidFromHexString(lpHexString: a2);
      }
    }
  }
  JUMPOUT(0x3F62B314);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B33E
// Name: LcidFromHexString
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall LcidFromHexString(char a1@<zf>)
{
  if ( !a1 )
    JUMPOUT(0x3F62B2D8);
  JUMPOUT(0x3F62B314);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B370
// Name: GetPrimaryLen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62B38B
// Name: CountryEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge CountryEnumProc(int a1@<ecx>, unsigned int a2@<ebx>, char *lpLcidString)
{
  *(_WORD *)(a1 + 662011997) = __CS__;
  *__doserrno_0() = a2;
  *_errno_0() = 22;
  _invalid_parameter_0(a1: a2, a2, a3: a2, a4: a2, a5: a2);
  JUMPOUT(0x3F62B46A);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B421
// Name: TestDefaultLanguage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall TestDefaultLanguage(int a1@<ebx>, int a2@<ebp>, const char *a3@<esi>)
{
  DWORD LastError; // eax
  unsigned int rgcInfo_104; // [esp+68h] [ebp-14h]

  *(_BYTE *)(a2 - 119) = _mbctoupper(Ch: rgcInfo_104);
  *(_BYTE *)(a2 - 118) = 58;
  *(_BYTE *)(a2 - 117) = 0;
  if ( SetEnvironmentVariableA(lpName: (LPCSTR)(a2 - 120), lpValue: a3) )
  {
    *(_DWORD *)(a2 - 124) = a1;
  }
  else
  {
    LastError = GetLastError();
    _dosmaperr_0(a1: LastError);
  }
  if ( *(_DWORD *)(a2 - 128) != a1 )
    ((void (__cdecl *)(const char *))loc_3F609ED0)(a1: a3);
  __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 + 148));
}

//------------------------------------------------------------------------------
// Address: 0x3F62B493
// Name: LangCountryEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall LangCountryEnumProc@<eax>(char a1@<zf>, char *result@<eax>, int a3@<edx>, char *a4@<ecx>)
{
  int v4; // esi
  char v5; // dl

  v4 = a3;
  if ( !a1 && a3 != 0 )
  {
    do
    {
      v5 = *result;
      *result = *a4;
      --v4;
      *a4 = v5;
      ++result;
      ++a4;
    }
    while ( v4 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62B663
// Name: LanguageEnumProc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge LanguageEnumProc(
        unsigned int a1@<ebx>,
        setloc_struct *a2@<edi>,
        unsigned int a3@<esi>,
        char *lpLcidString,
        char *lpLcidStringa,
        int a6,
        int (__cdecl *a7)(int, unsigned int, setloc_struct *),
        int a8)
{
  unsigned int v8; // eax
  setloc_struct *v9; // esi
  int v10; // eax
  int v11; // [esp-78h] [ebp-F4h]
  _DWORD v12[29]; // [esp-74h] [ebp-F0h]
  char rgcInfo[120]; // [esp+0h] [ebp-7Ch]

  while ( 1 )
  {
    v8 = ((unsigned int)a2 - a1) / a3 + 1;
    if ( v8 > 8 )
      break;
    ((void (__cdecl *)(unsigned int, setloc_struct *, unsigned int, int (__cdecl *)(int, unsigned int, setloc_struct *), int))loc_3F62B4C0)(
      a1,
      a2,
      a3,
      a4: a7,
      a5: a8);
    v10 = --v11;
    if ( v11 < 0 )
      return;
    a2 = *(setloc_struct **)&rgcInfo[4 * v10 + 4];
    a1 = v12[v10];
  }
  v9 = (setloc_struct *)(a1 + a3 * (v8 >> 1));
  if ( a7(a1: a8, a2: a1, a3: v9) > 0 )
    ((void (__fastcall *)(setloc_struct *, int))loc_3F62B490)(a1: v9, a2: a6);
  if ( a7(a1: a8, a2: a1, a3: a2) > 0 )
    ((void (__fastcall *)(setloc_struct *, int))loc_3F62B490)(a1: a2, a2: a6);
  if ( a7(a1: a8, a2: (unsigned int)v9, a3: a2) > 0 )
    ((void (__fastcall *)(setloc_struct *, int))loc_3F62B490)(a1: a2, a2: a6);
  if ( (unsigned int)v9 <= a1 || a6 + a1 >= (unsigned int)v9 )
    JUMPOUT(0x3F62B740);
  GetLcidFromCountry(_psetloc_data: v9);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B722
// Name: GetLcidFromCountry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall GetLcidFromCountry(
        setloc_struct *_psetloc_data@<esi>,
        unsigned int a2@<ebx>,
        int a3,
        int a4,
        int a5,
        int a6,
        unsigned int a7)
{
  if ( ((int (*)(void))STACK[0x120])() <= 0 )
    JUMPOUT(0x3F62B714);
  if ( (unsigned int)_psetloc_data > a2 || STACK[0x11C] + a2 > a7 )
    JUMPOUT(0x3F62B760);
  GetLcidFromLangCountry(_psetloc_data);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B74E
// Name: GetLcidFromLangCountry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall GetLcidFromLangCountry(
        setloc_struct *_psetloc_data@<esi>,
        unsigned int a2@<ebx>,
        int a3@<ebp>,
        unsigned int a4@<edi>)
{
  unsigned int v4; // ecx
  _BYTE *v5; // eax
  int v6; // ebp
  char v7; // [esp+23h] [ebp+1Bh]

  if ( ((int (*)(void))STACK[0x128])() > 0 )
  {
    do
      a4 -= STACK[0x124];
    while ( a4 > (unsigned int)_psetloc_data
         && ((int (__cdecl *)(int, unsigned int, setloc_struct *))STACK[0x128])(a1: a3, a2: a4, a3: _psetloc_data) > 0 );
    if ( a2 <= a4 )
    {
      v4 = STACK[0x124];
      v5 = (_BYTE *)a4;
      if ( a2 != a4 )
      {
        v6 = a2 - a4;
        do
        {
          v7 = v5[v6];
          v5[v6] = *v5;
          --v4;
          *v5++ = v7;
        }
        while ( v4 != 0 );
        JUMPOUT(0x3F62B7AF);
      }
      JUMPOUT(0x3F62B7B6);
    }
    JUMPOUT(0x3F62B7C5);
  }
  JUMPOUT(0x3F62B740);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B7B3
// Name: GetLcidFromLanguage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall GetLcidFromLanguage(_DWORD *a1@<eax>, _BYTE *a2@<ebx>)
{
  *a1 += a1;
  *a2 += BYTE1(a2);
  --*(_DWORD *)(a2 - 11802125);
  JUMPOUT(0x3F62B7C3);
}

//------------------------------------------------------------------------------
// Address: 0x3F62B8C3
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf(char *const Buffer, const char *const Format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  FILE File; // [esp+4h] [ebp-20h] BYREF
  va_list va; // [esp+34h] [ebp+10h] BYREF

  va_start(va, Format);
  if ( Format != nullptr && Buffer != nullptr )
  {
    File._base = Buffer;
    File._ptr = Buffer;
    File._cnt = 0x7FFFFFFF;
    File._flag = 66;
    v3 = _output_l_0(a1: &File, a2: Format, a3: 0, a4: va);
    v4 = --File._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf_0(Ch: 0, &File);
    else
      *File._ptr = 0;
    return v5;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62B9D2
// Name: cmpResult
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62B9E4
// Name: cmpBYTE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62B9FC
// Name: cmpWORD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall cmpWORD@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(_DWORD))loc_3F6349C4)(a1: *(_DWORD *)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F62BA3C
// Name: cmpDWORD
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cmpDWORD@<eax>(int a1@<eax>, int a2@<ebx>, int a3, int a4)
{
  *(_BYTE *)(a2 - 1916597052) += a1;
  LOBYTE(a1) = a1 & 0xC;
  return ((int (__cdecl *)(int, int, int))loc_3F6346A6)(a1: a3, a2: a4, a3: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F62BAB4
// Name: unaligned_memcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall unaligned_memcmp(unsigned __int8 *bLHS@<ecx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  int v6; // edi
  bool v7; // zf
  unsigned int v8; // ebx
  int v9; // eax
  rsize_t v10; // edi
  unsigned int v11; // edx
  int v12; // eax
  unsigned int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  _BYTE *v17; // ecx
  int v18; // eax
  int v19; // [esp+0h] [ebp-8h]
  int v20; // [esp+0h] [ebp-8h]
  size_t v21; // [esp+4h] [ebp-4h]
  unsigned int v22; // [esp+4h] [ebp-4h]

  memset(a1: bLHS, Val: v19, Size: v21);
  if ( a4 == a3 || *(_DWORD *)(a2 + 20) > 0xFFFFFFFF / *(_DWORD *)(a2 + 16) )
    JUMPOUT(0x3F62BA7C);
  v6 = *(_DWORD *)(a2 + 20) * *(_DWORD *)(a2 + 16);
  v7 = (*(_WORD *)(a4 + 12) & 0x10C) == 0;
  *(_DWORD *)(a2 - 16) = v6;
  v8 = v6;
  if ( v7 )
    *(_DWORD *)(a2 - 12) = 4096;
  else
    *(_DWORD *)(a2 - 12) = *(_DWORD *)(a4 + 24);
  if ( v6 == 0 )
LABEL_42:
    JUMPOUT(0x3F62BA96);
  while ( 1 )
  {
    if ( (*(_WORD *)(a4 + 12) & 0x10C) != 0 && (v9 = *(_DWORD *)(a4 + 4)) != 0 )
    {
      if ( v9 < 0 )
        goto LABEL_37;
      v10 = v8;
      if ( v8 >= v9 )
        v10 = *(_DWORD *)(a4 + 4);
      if ( v10 > *(_DWORD *)(a2 - 4) )
      {
        if ( *(_DWORD *)(a2 + 12) != -1 )
          memset(a1: *(void **)(a2 + 8), Val: 0, Size: *(_DWORD *)(a2 + 12));
        goto LABEL_33;
      }
      memcpy_s(
        Destination: *(void *const *)(a2 - 8),
        DestinationSize: *(_DWORD *)(a2 - 4),
        Source: *(const void *const *)a4,
        SourceSize: v10);
      *(_DWORD *)(a4 + 4) -= v10;
      *(_DWORD *)a4 += v10;
      *(_DWORD *)(a2 - 8) += v10;
      v8 -= v10;
      *(_DWORD *)(a2 - 4) -= v10;
    }
    else if ( v8 < *(_DWORD *)(a2 - 12) )
    {
      v16 = _filbuf_0(File: (FILE *)a4);
      if ( v16 == -1 )
        goto LABEL_42;
      if ( *(_DWORD *)(a2 - 4) == 0 )
      {
LABEL_34:
        if ( *(_DWORD *)(a2 + 12) != -1 )
          memset(a1: *(void **)(a2 + 8), Val: 0, Size: *(_DWORD *)(a2 + 12));
LABEL_33:
        *_errno_0() = 34;
        JUMPOUT(0x3F62BA8C);
      }
      v17 = *(_BYTE **)(a2 - 8);
      *(_DWORD *)(a2 - 8) = v17 + 1;
      *v17 = v16;
      v18 = *(_DWORD *)(a4 + 24);
      --v8;
      --*(_DWORD *)(a2 - 4);
      *(_DWORD *)(a2 - 12) = v18;
    }
    else
    {
      if ( *(_DWORD *)(a2 - 12) != 0 )
      {
        if ( v8 <= 0x7FFFFFFF )
        {
          v11 = v8 % *(_DWORD *)(a2 - 12);
          v12 = v8;
        }
        else
        {
          v11 = 0x7FFFFFFFu % *(_DWORD *)(a2 - 12);
          v12 = 0x7FFFFFFF;
        }
        v13 = v12 - v11;
      }
      else
      {
        v13 = 0x7FFFFFFF;
        if ( v8 <= 0x7FFFFFFF )
          v13 = v8;
      }
      if ( v13 > *(_DWORD *)(a2 - 4) )
        goto LABEL_34;
      v22 = v13;
      v20 = *(_DWORD *)(a2 - 8);
      v14 = _fileno_0(Stream: (FILE *)a4);
      v15 = ((int (__cdecl *)(int, int, unsigned int))loc_3F634FAD)(a1: v14, a2: v20, a3: v22);
      if ( v15 == 0 )
      {
        *(_DWORD *)(a4 + 12) |= 0x10u;
        goto LABEL_42;
      }
      if ( v15 == -1 )
      {
LABEL_37:
        *(_DWORD *)(a4 + 12) |= 0x20u;
        goto LABEL_42;
      }
      *(_DWORD *)(a2 - 8) += v15;
      v8 -= v15;
      *(_DWORD *)(a2 - 4) -= v15;
    }
    if ( v8 == 0 )
      goto LABEL_42;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62BC78
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl fread_s(void *Buffer, size_t BufferSize, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  size_t v6; // [esp+10h] [ebp-1Ch]

  if ( ElementSize == 0 || ElementCount == 0 )
    return 0;
  if ( Stream == nullptr )
  {
    if ( BufferSize != -1 )
      memset(a1: Buffer, Val: 0, Size: BufferSize);
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 0;
  }
  _lock_file_0(Stream);
  v6 = ((int (__cdecl *)(void *, size_t, size_t, size_t, FILE *))loc_3F62BA57)(
         a1: Buffer,
         a2: BufferSize,
         a3: ElementSize,
         a4: ElementCount,
         a5: Stream);
  _unlock_file_0(Stream);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x3F62BD0E
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl fread(void *Buffer, size_t ElementSize, size_t ElementCount, FILE *Stream)
{
  return fread_s(Buffer, BufferSize: 0xFFFFFFFF, ElementSize, ElementCount, Stream);
}

//------------------------------------------------------------------------------
// Address: 0x3F62BD29
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(FILE *Stream)
{
  int NumberOfDimensions; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v7; // edx
  int cnt; // edx
  int v9; // esi
  int *v10; // ebx
  char *v11; // eax
  char *v12; // ecx
  bool v13; // zf
  int bufsiz; // eax
  int v15; // ecx
  char *v16; // [esp+8h] [ebp-Ch]
  int v17; // [esp+Ch] [ebp-8h]
  int v18; // [esp+10h] [ebp-4h]
  unsigned int Streama; // [esp+1Ch] [ebp+8h]

  if ( Stream == nullptr )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  v18 = _fileno_0(Stream);
  if ( Stream->_cnt < 0 )
    Stream->_cnt = 0;
  NumberOfDimensions = UnDecorator::getNumberOfDimensions();
  v17 = NumberOfDimensions;
  if ( NumberOfDimensions < 0 )
    return -1;
  flag = Stream->_flag;
  if ( (flag & 0x108) == 0 )
    return NumberOfDimensions - Stream->_cnt;
  ptr = Stream->_ptr;
  base = Stream->_base;
  v16 = (char *)(Stream->_ptr - base);
  if ( (flag & 3) != 0 )
  {
    if ( *(char *)(dword_3F665FE0[v18 >> 5] + 56 * (v18 & 0x1F) + 4) < 0 )
    {
      v7 = Stream->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v7 == 10 )
            ++v16;
          ++v7;
        }
        while ( v7 < ptr );
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno_0() = 22;
    return -1;
  }
  if ( v17 == 0 )
    return (int)v16;
  if ( (Stream->_flag & 1) == 0 )
    return (int)&v16[v17];
  cnt = Stream->_cnt;
  if ( cnt != 0 )
  {
    v9 = 56 * (v18 & 0x1F);
    v10 = &dword_3F665FE0[v18 >> 5];
    Streama = cnt + ptr - base;
    if ( *(char *)(*v10 + v9 + 4) >= 0 )
    {
LABEL_39:
      v17 -= Streama;
      return (int)&v16[v17];
    }
    if ( UnDecorator::getNumberOfDimensions() == v17 )
    {
      v11 = Stream->_base;
      v12 = &v11[Streama];
      while ( v11 < v12 )
      {
        if ( *v11 == 10 )
          ++Streama;
        ++v11;
      }
      v13 = (Stream->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v13 )
        ++Streama;
      goto LABEL_39;
    }
    if ( UnDecorator::getNumberOfDimensions() >= 0 )
    {
      bufsiz = 512;
      if ( Streama > 0x200 || ((v15 = Stream->_flag) & 8) == 0 || (v15 & 0x400) != 0 )
        bufsiz = Stream->_bufsiz;
      Streama = bufsiz;
      v13 = (*(_BYTE *)(*v10 + v9 + 4) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  v16 = nullptr;
  return (int)&v16[v17];
}

//------------------------------------------------------------------------------
// Address: 0x3F62BEC1
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(FILE *Stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  if ( Stream != nullptr )
  {
    _lock_file_0(Stream);
    v2 = _ftell_nolock(Stream);
    _unlock_file_0(Stream);
    return v2;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62BFB6
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(FILE *Stream, int Offset, int Origin)
{
  int v4; // [esp+10h] [ebp-1Ch]

  if ( Stream != nullptr && (unsigned int)Origin <= 2 )
  {
    _lock_file_0(Stream);
    v4 = _fseek_nolock(Stream, Offset, Origin);
    _unlock_file_0(Stream);
    return v4;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62C074
// Name: __invoke_watson_if_error_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invoke_watson_if_error_0(
        int a1,
        wchar_t *Expression,
        wchar_t *FunctionName,
        wchar_t *FileName,
        unsigned int LineNo,
        uintptr_t Reserved)
{
  if ( a1 != 0 )
    _invoke_watson_0(Expression, FunctionName, FileName, LineNo, Reserved);
}

//------------------------------------------------------------------------------
// Address: 0x3F62C300
// Name: sub_3F62C300
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62C300()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F62C303
// Name: ___timet_from_ft
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __timet_from_ft(FILETIME *lpFileTime)
{
  struct _SYSTEMTIME SystemTime; // [esp+0h] [ebp-18h] BYREF
  _FILETIME LocalFileTime; // [esp+10h] [ebp-8h] BYREF

  if ( (lpFileTime->dwLowDateTime != 0 || lpFileTime->dwHighDateTime != 0)
    && FileTimeToLocalFileTime(lpFileTime, lpLocalFileTime: &LocalFileTime)
    && FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
  {
    return __loctotime32_t(
             a1: SystemTime.wYear,
             a2: SystemTime.wMonth,
             a3: SystemTime.wDay,
             a4: SystemTime.wHour,
             a5: SystemTime.wMinute,
             a6: SystemTime.wSecond,
             a7: -1);
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62C367
// Name: __findfirst32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
intptr_t __cdecl _findfirst32(const char *FileName, struct _finddata32_t *FindData)
{
  HANDLE FirstFileA; // ebx
  DWORD LastError; // eax
  struct _WIN32_FIND_DATAA FindFileData; // [esp+8h] [ebp-144h] BYREF

  if ( FindData == nullptr || FileName == nullptr )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  FirstFileA = FindFirstFileA(lpFileName: FileName, lpFindFileData: &FindFileData);
  if ( FirstFileA == (HANDLE)-1 )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_12;
      if ( LastError == 8 )
      {
        *_errno_0() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_12:
        *_errno_0() = 2;
        return -1;
      }
    }
    *_errno_0() = 22;
    return -1;
  }
  FindData->attrib = FindFileData.dwFileAttributes != 128 ? FindFileData.dwFileAttributes : 0;
  FindData->time_create = __timet_from_ft(lpFileTime: &FindFileData.ftCreationTime);
  FindData->time_access = __timet_from_ft(lpFileTime: &FindFileData.ftLastAccessTime);
  FindData->time_write = __timet_from_ft(lpFileTime: &FindFileData.ftLastWriteTime);
  FindData->size = FindFileData.nFileSizeLow;
  if ( strcpy_s_0(Destination: FindData->name, SizeInBytes: 0x104u, Source: FindFileData.cFileName) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  return (intptr_t)FirstFileA;
}

//------------------------------------------------------------------------------
// Address: 0x3F62C730
// Name: sub_3F62C730
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62C730()
{
  return sub_3F62C733();
}

//------------------------------------------------------------------------------
// Address: 0x3F62C733
// Name: sub_3F62C733
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F62C733()
{
  FILE *v0; // [esp+0h] [ebp-4h]

  _unlock_file_0(Stream: v0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62C7A3
// Name: sub_3F62C7A3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62C7A3(int a1, int a2, ...)
{
  va_list va; // [esp+10h] [ebp+Ch] BYREF

  va_start(va, a2);
  return ((int (__cdecl *)(void *, int, _DWORD, char *))vscan_fn)(a1: &_input_l_0, a2, a3: 0, a4: va);
}

//------------------------------------------------------------------------------
// Address: 0x3F62CD92
// Name: _strtol_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strtol_0(const char *String, char **EndPtr, int Radix)
{
  if ( dword_3F6637BC != 0 )
    return strtoxl(a1: nullptr, a2: String, a3: (const char **)EndPtr, a4: Radix, a5: 0);
  else
    return strtoxl(
             a1: (struct localeinfo_struct *)&s_NoEscConversion.m_pReplacements[81],
             a2: String,
             a3: (const char **)EndPtr,
             a4: Radix,
             a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62CDBB
// Name: sub_3F62CDBB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_3F62CDBB(const char *a1, const char **a2, int a3, struct localeinfo_struct *a4)
{
  return strtoxl(a1: a4, a2: a1, a3: a2, a4: a3, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62CF38
// Name: sub_3F62CF38
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62CF44
// Name: _memcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall memcmp@<eax>(int a1@<ebp>)
{
  int result; // eax

  result = ((int (__cdecl *)(char *, _DWORD, _DWORD))_vswprintf_helper)(
             a1: byte_3F637019,
             a2: *(_DWORD *)(a1 + 8),
             a3: *(_DWORD *)(a1 + 12));
  if ( result < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62CF60
// Name: __vswprintf_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vswprintf_s_l(
        wchar_t *const Buffer,
        const size_t BufferCount,
        const wchar_t *const Format,
        const _locale_t Locale,
        va_list ArgList)
{
  int result; // eax

  if ( Format == nullptr )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  if ( Buffer == nullptr || BufferCount == 0 )
  {
    *_errno_0() = 22;
LABEL_10:
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  result = ((int (__cdecl *)(void *, wchar_t *const, const size_t, const wchar_t *const, const _locale_t, va_list))_vswprintf_helper)(
             a1: &loc_3F637929,
             a2: Buffer,
             a3: BufferCount,
             a4: Format,
             a5: Locale,
             a6: ArgList);
  if ( result < 0 )
    *Buffer = 0;
  if ( result == -2 )
  {
    *_errno_0() = 34;
    goto LABEL_10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D002
// Name: __vsnwprintf_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnwprintf_s_l(
        wchar_t *const Buffer,
        const size_t BufferCount,
        const size_t MaxCount,
        const wchar_t *const Format,
        const _locale_t Locale,
        va_list ArgList)
{
  int result; // eax
  int *v7; // eax
  int v8; // edi
  int v9; // [esp+4h] [ebp-4h]

  if ( Format == nullptr )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  if ( MaxCount != 0 )
  {
    if ( Buffer == nullptr )
    {
LABEL_9:
      *_errno_0() = 22;
LABEL_21:
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      return -1;
    }
  }
  else if ( Buffer == nullptr )
  {
    if ( BufferCount == 0 )
      return 0;
    goto LABEL_9;
  }
  if ( BufferCount == 0 )
    goto LABEL_9;
  v7 = _errno_0();
  if ( BufferCount > MaxCount )
  {
    v8 = *v7;
    result = ((int (__cdecl *)(void *, wchar_t *const, size_t, const wchar_t *const, const _locale_t, va_list))_vswprintf_helper)(
               a1: &loc_3F637929,
               a2: Buffer,
               a3: MaxCount + 1,
               a4: Format,
               a5: Locale,
               a6: ArgList);
    if ( result == -2 )
    {
      if ( *_errno_0() == 34 )
        *_errno_0() = v8;
      return -1;
    }
    goto LABEL_18;
  }
  v9 = *v7;
  result = ((int (__cdecl *)(void *, wchar_t *const, const size_t, const wchar_t *const, const _locale_t, va_list))_vswprintf_helper)(
             a1: &loc_3F637929,
             a2: Buffer,
             a3: BufferCount,
             a4: Format,
             a5: Locale,
             a6: ArgList);
  Buffer[BufferCount - 1] = 0;
  if ( result != -2 )
  {
LABEL_18:
    if ( result >= 0 )
      return result;
    goto LABEL_19;
  }
  if ( MaxCount == -1 )
  {
    if ( *_errno_0() == 34 )
      *_errno_0() = v9;
    return -1;
  }
LABEL_19:
  *Buffer = 0;
  if ( result == -2 )
  {
    *_errno_0() = 34;
    goto LABEL_21;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D109
// Name: __vsnwprintf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnwprintf_s(
        wchar_t *const Buffer,
        const size_t BufferCount,
        const size_t MaxCount,
        const wchar_t *const Format,
        va_list ArgList)
{
  return _vsnwprintf_s_l(Buffer, BufferCount, MaxCount, Format, Locale: nullptr, ArgList);
}

//------------------------------------------------------------------------------
// Address: 0x3F62D176
// Name: __snprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snprintf(char *const Buffer, const size_t BufferCount, const char *const Format, ...)
{
  int result; // eax
  int v4; // edi
  FILE File; // [esp+4h] [ebp-20h] BYREF
  va_list va; // [esp+38h] [ebp+14h] BYREF

  va_start(va, Format);
  if ( Format != nullptr )
  {
    if ( BufferCount == 0 || Buffer != nullptr )
    {
      File._cnt = 0x7FFFFFFF;
      if ( BufferCount <= 0x7FFFFFFF )
        File._cnt = BufferCount;
      File._flag = 66;
      File._base = Buffer;
      File._ptr = Buffer;
      result = _output_l_0(a1: &File, a2: Format, a3: 0, a4: va);
      v4 = result;
      if ( Buffer != nullptr )
      {
        if ( --File._cnt < 0 )
          _flsbuf_0(Ch: 0, &File);
        else
          *File._ptr = 0;
        return v4;
      }
    }
    else
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      return -1;
    }
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D223
// Name: __snprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _snprintf_l(char *const Buffer, const size_t BufferCount, const char *const Format, const _locale_t Locale, ...)
{
  va_list ArgList; // [esp+18h] [ebp+18h] BYREF

  va_start(ArgList, Locale);
  return _vsnprintf_l(Buffer, BufferCount, Format, Locale, ArgList);
}

//------------------------------------------------------------------------------
// Address: 0x3F62D240
// Name: __strtod_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l_0(const char *String, char **EndPtr, _locale_t Locale)
{
  const char *v3; // esi
  int v5; // eax
  size_t v6; // eax
  double *v7; // eax
  double *v8; // ecx
  int v9; // eax
  double v10; // st7
  char v11[24]; // [esp+Ch] [ebp-30h] BYREF
  _LocaleUpdate v12; // [esp+24h] [ebp-18h] BYREF
  double v13; // [esp+34h] [ebp-8h]

  v3 = String;
  _LocaleUpdate::_LocaleUpdate(this: &v12, a2: Locale);
  if ( EndPtr != nullptr )
    *EndPtr = (char *)String;
  if ( String == nullptr )
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    if ( v12.updated )
      v12.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = v12.localeinfo.locinfo->mb_cur_max <= 1
       ? v12.localeinfo.locinfo->pctype[*(unsigned __int8 *)v3] & 8
       : _isctype_l_0(C: *(unsigned __int8 *)v3, Type: 8, Locale: &v12.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  v6 = strlen_0(Str: v3);
  v7 = (double *)_fltin2_0(a1: v11, a2: v3, a3: v6, a4: 0, a5: 0, a6: &v12);
  v8 = v7;
  if ( EndPtr != nullptr )
    *EndPtr = (char *)&v3[*((_DWORD *)v7 + 1)];
  v9 = *(_DWORD *)v7;
  if ( (*(_DWORD *)v8 & 0x240) != 0 )
  {
    v13 = 0.0;
    if ( EndPtr != nullptr )
      *EndPtr = (char *)String;
    goto LABEL_24;
  }
  if ( (v9 & 0x81) != 0 )
  {
    v10 = *(double *)&s_NoEscConversion.m_pReplacements[178];
    if ( *v3 == 45 )
      v10 = -*(double *)&s_NoEscConversion.m_pReplacements[178];
  }
  else if ( (v9 & 0x100) == 0 || (v10 = 0.0, 0.0 != v8[2]) )
  {
    v13 = v8[2];
    goto LABEL_24;
  }
  v13 = v10;
  *_errno_0() = 34;
LABEL_24:
  if ( v12.updated )
    v12.ptd->_ownlocale &= ~2u;
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D36E
// Name: sub_3F62D36E
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F62D36E(int a1)
{
  dword_3F66374C = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D378
// Name: sub_3F62D378
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F62D378(int a1)
{
  dword_3F663750 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D382
// Name: sub_3F62D382
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F62D382(int a1)
{
  dword_3F663754 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D38C
// Name: sub_3F62D38C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F62D38C(int a1)
{
  dword_3F663758 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D396
// Name: sub_3F62D396
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F62D396(int a1)
{
  dword_3F66375C = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D579
// Name: ___DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall __DllMainCRTStartup(void *a1, DWORD a2, HINSTANCE hinstDLL)
{
  BOOL v5; // eax
  int v7; // [esp+10h] [ebp-1Ch]
  BOOL v8; // [esp+10h] [ebp-1Ch]

  v7 = 1;
  if ( a2 == 0 && dword_3F663724 == 0 )
    return 0;
  if ( a2 == 1 || a2 == 2 )
  {
    if ( &loc_3F609760 != nullptr )
      v7 = ((int (__stdcall *)(HINSTANCE))loc_3F609760)(a1: hinstDLL);
    if ( v7 == 0 || ((int (__cdecl *)(HINSTANCE, DWORD, void *))_CRT_INIT)(a1: hinstDLL, a2, a3: a1) == 0 )
      return 0;
  }
  v5 = DllMain(hinstDLL, fdwReason: a2, lpvReserved: a1);
  v8 = v5;
  if ( a2 == 1 && !v5 )
  {
    DllMain(hinstDLL, fdwReason: 0, lpvReserved: a1);
    ((void (__cdecl *)(HINSTANCE, _DWORD, void *))_CRT_INIT)(a1: hinstDLL, a2: 0, a3: a1);
    if ( &loc_3F609760 != nullptr )
      ((void (__stdcall *)(HINSTANCE))loc_3F609760)(a1: hinstDLL);
  }
  if ( a2 == 0 || a2 == 3 )
  {
    if ( ((int (__cdecl *)(HINSTANCE, DWORD, void *))_CRT_INIT)(a1: hinstDLL, a2, a3: a1) == 0 )
      v8 = false;
    if ( v8 && &loc_3F609760 != nullptr )
      return ((int (__stdcall *)(HINSTANCE))loc_3F609760)(a1: hinstDLL);
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D66F
// Name: DllEntryPoint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall DllEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    ((void (*)(void))loc_3F63997E)();
  return __DllMainCRTStartup(a1: lpReserved, a2: fdwReason, hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x3F62D690
// Name: __use_encode_pointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _use_encode_pointer()
{
  unsigned int v0; // ebx
  HMODULE ModuleHandleA; // eax
  char *v3; // esi
  const char *v4; // edi
  int v5; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h] BYREF

  v0 = 0;
  v5 = 1;
  v6 = 0;
  sub_3F62DE4D(a1: &v6);
  if ( v6 > 5 )
    return 1;
  ModuleHandleA = GetModuleHandleA(lpModuleName: nullptr);
  v3 = (char *)ModuleHandleA + *((_DWORD *)ModuleHandleA + 15);
  v4 = &v3[*((unsigned __int16 *)v3 + 10) + 24];
  if ( *((_WORD *)v3 + 3) != 0 )
  {
    while ( strcmp_0(Str1: ".mixcrt", Str2: v4) != 0 )
    {
      ++v0;
      v4 += 40;
      if ( v0 >= *((unsigned __int16 *)v3 + 3) )
        return v5;
    }
    return 0;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D76A
// Name: sub_3F62D76A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62D76A()
{
  return ((int (__cdecl *)(_DWORD))_encode_pointer_0)(a1: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62D773
// Name: __decode_pointer_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID __cdecl _decode_pointer_0(void *a1)
{
  int (__stdcall *Value)(int); // eax
  int v2; // eax
  PVOID (__stdcall *DecodePointer)(PVOID); // eax
  HMODULE ModuleHandleA; // esi
  int v6; // [esp-4h] [ebp-8h]

  if ( TlsGetValue(dwTlsIndex: dwTlsIndex) != nullptr
    && dword_3F661020 != -1
    && (v6 = dword_3F661020,
        Value = (int (__stdcall *)(int))TlsGetValue(dwTlsIndex: dwTlsIndex),
        (v2 = Value(a1: v6)) != 0) )
  {
    DecodePointer = *(PVOID (__stdcall **)(PVOID))(v2 + 508);
  }
  else
  {
    ModuleHandleA = GetModuleHandleA(lpModuleName: "KERNEL32.DLL");
    if ( ModuleHandleA == nullptr || _use_encode_pointer() == 0 )
      return a1;
    DecodePointer = (PVOID (__stdcall *)(PVOID))GetProcAddress(hModule: ModuleHandleA, lpProcName: "DecodePointer");
  }
  if ( DecodePointer != nullptr )
    return DecodePointer(Ptr: a1);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D7E7
// Name: nullsub_37
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall nullsub_37(int a1)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D7FF
// Name: sub_3F62D7FF
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62D7FF()
{
  return dword_3F661020;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D805
// Name: ___set_flsgetvalue_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__set_flsgetvalue_0()
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: dwTlsIndex);
  if ( Value == nullptr )
  {
    Value = _decode_pointer_0(a1: (void *)dword_3F66373C);
    TlsSetValue(dwTlsIndex: dwTlsIndex, lpTlsValue: Value);
  }
  return Value;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D837
// Name: ___fls_setvalue@8_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall __fls_setvalue(int a1, int a2)
{
  int (__stdcall *v2)(int, int); // eax

  v2 = (int (__stdcall *)(int, int))_decode_pointer_0(a1: (void *)dword_3F663740);
  return v2(a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F62D850
// Name: __mtterm_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _mtterm_0()
{
  void (__stdcall *v0)(int); // eax
  int v2; // [esp-4h] [ebp-4h]

  if ( dword_3F661020 != -1 )
  {
    v2 = dword_3F661020;
    v0 = (void (__stdcall *)(int))_decode_pointer_0(a1: (void *)dword_3F663744);
    v0(a1: v2);
    dword_3F661020 = -1;
  }
  if ( dwTlsIndex != -1 )
  {
    TlsFree(dwTlsIndex: dwTlsIndex);
    dwTlsIndex = -1;
  }
  return _mtdeletelocks_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F62D943
// Name: sub_3F62D943
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62D943()
{
  return _unlock_0(a1: 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F62D94C
// Name: __getptd_noexit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD *_getptd_noexit_0()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  int (__stdcall *v2)(int); // eax
  DWORD *v3; // esi
  int v4; // eax
  int (__stdcall *v5)(int, int); // eax
  DWORD CurrentThreadId; // eax
  int v8; // [esp-8h] [ebp-10h]
  int v9; // [esp-4h] [ebp-Ch]
  int v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = dword_3F661020;
  v1 = LastError;
  v2 = (int (__stdcall *)(int))__set_flsgetvalue_0();
  v3 = (DWORD *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 1, a2: 532);
    v3 = (DWORD *)v4;
    if ( v4 != 0 )
    {
      v10 = v4;
      v8 = dword_3F661020;
      v5 = (int (__stdcall *)(int, int))_decode_pointer_0(a1: (void *)dword_3F663740);
      if ( v5(a1: v8, a2: v10) != 0 )
      {
        ((void (__cdecl *)(DWORD *, _DWORD))_initptd_0)(a1: v3, a2: 0);
        CurrentThreadId = GetCurrentThreadId();
        v3[1] = -1;
        *v3 = CurrentThreadId;
      }
      else
      {
        ((void (__cdecl *)(DWORD *))loc_3F609ED0)(a1: v3);
        v3 = nullptr;
      }
    }
  }
  SetLastError(dwErrCode: v1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F62D9C3
// Name: __getptd_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DWORD *_getptd_0()
{
  DWORD *v0; // esi

  v0 = _getptd_noexit_0();
  if ( v0 == nullptr )
    _amsg_exit_0(a1: 16);
  return v0;
}

//------------------------------------------------------------------------------
// Address: 0x3F62DAE4
// Name: sub_3F62DAE4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62DAE4()
{
  return sub_3F62DAE7();
}

//------------------------------------------------------------------------------
// Address: 0x3F62DAE7
// Name: sub_3F62DAE7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62DAE7()
{
  return _unlock_0(a1: 13);
}

//------------------------------------------------------------------------------
// Address: 0x3F62DAF0
// Name: sub_3F62DAF0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62DAF0()
{
  return sub_3F62DAF3();
}

//------------------------------------------------------------------------------
// Address: 0x3F62DAF3
// Name: sub_3F62DAF3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62DAF3()
{
  return _unlock_0(a1: 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F62DB65
// Name: GetCurrentThreadId
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall GetCurrentThreadId()
{
  return __imp_GetCurrentThreadId();
}

//------------------------------------------------------------------------------
// Address: 0x3F62DB6B
// Name: GetCurrentThread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
HANDLE __stdcall GetCurrentThread()
{
  return __imp_GetCurrentThread();
}

//------------------------------------------------------------------------------
// Address: 0x3F62DCF5
// Name: __amsg_exit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _amsg_exit_0(int a1)
{
  int (__cdecl *v1)(int); // eax

  _FF_MSGBANNER_0();
  _NMSG_WRITE_0(a1);
  v1 = (int (__cdecl *)(int))_decode_pointer_0(a1: off_3F661028);
  return v1(a1: 255);
}

//------------------------------------------------------------------------------
// Address: 0x3F62DD19
// Name: ___crtCorExitProcess_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HMODULE __cdecl __crtCorExitProcess_0(int a1)
{
  HMODULE result; // eax

  result = GetModuleHandleA(lpModuleName: "mscoree.dll");
  if ( result != nullptr )
  {
    result = (HMODULE)GetProcAddress(hModule: result, lpProcName: "CorExitProcess");
    if ( result != nullptr )
      return (HMODULE)((int (__stdcall *)(int))result)(a1);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62DD3F
// Name: ___crtExitProcess_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess_0(UINT uExitCode)
{
  __crtCorExitProcess_0(a1: uExitCode);
  ExitProcess(uExitCode);
}

//------------------------------------------------------------------------------
// Address: 0x3F62DD54
// Name: sub_3F62DD54
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62DD54()
{
  return _lock_0(a1: 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F62DD5D
// Name: sub_3F62DD5D
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62DD5D()
{
  return _unlock_0(a1: 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F62DD66
// Name: __initterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initterm(_PVFV *First, _PVFV *Last)
{
  void (**v2)(void); // eax
  void (**i)(void); // esi

  for ( i = v2; i < First; ++i )
  {
    if ( *i != nullptr )
      (*i)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62DD7E
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(_PIFV *First, _PIFV *Last)
{
  int result; // eax

  result = 0;
  while ( First < Last && result == 0 )
  {
    if ( *First != nullptr )
      result = (*First)();
    ++First;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62DE4D
// Name: sub_3F62DE4D
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F62DE4D(_DWORD *a1)
{
  if ( a1 != nullptr && dword_3F66374C != 0 )
  {
    *a1 = dword_3F663758;
    return 0;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62DEB0
// Name: nullsub_38
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_38()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F62DFC5
// Name: _doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(UINT uExitCode, int a2, int a3)
{
  void **v3; // esi
  void *v4; // edi
  void (*v5)(void); // eax
  _PVFV *v6; // [esp+0h] [ebp-30h]
  void **v7; // [esp+14h] [ebp-1Ch]

  _lock_0(a1: 8);
  if ( dword_3F66378C != 1 )
  {
    dword_3F663788 = 1;
    byte_3F663784 = a3;
    if ( a2 == 0 )
    {
      v7 = (void **)_decode_pointer_0(a1: (void *)dword_3F667110);
      v3 = (void **)_decode_pointer_0(a1: (void *)dword_3F66710C);
      if ( v7 != nullptr )
      {
        while ( --v3 >= v7 )
        {
          if ( *v3 != nullptr )
          {
            v4 = *v3;
            if ( v4 != (void *)sub_3F62D76A() )
            {
              v5 = (void (*)(void))_decode_pointer_0(a1: v4);
              v5();
            }
          }
        }
      }
      _initterm(First: (_PVFV *)&First, Last: v6);
    }
    _initterm(First: (_PVFV *)&dword_3F654390, Last: v6);
  }
  if ( a3 != 0 )
    _unlock_0(a1: 8);
  if ( a3 == 0 )
  {
    dword_3F66378C = 1;
    _unlock_0(a1: 8);
    __crtExitProcess_0(uExitCode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62E0B8
// Name: __exit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit_0(int Code)
{
  doexit(uExitCode: Code, a2: 1, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E0C9
// Name: __cexit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit_0()
{
  doexit(uExitCode: 0, a2: 0, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E0D8
// Name: __c_exit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _c_exit_0()
{
  doexit(uExitCode: 0, a2: 1, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E0E7
// Name: __init_pointers_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn _init_pointers_0()
{
  int v0; // esi

  v0 = sub_3F62D76A();
  sub_3F63A2F0(a1: v0);
  sub_3F63A211(a1: v0);
  ((void (__cdecl *)(int))loc_3F62E8C7)(a1: v0);
  sub_3F6330BC(a1: v0);
  sub_3F63A103(a1: v0);
  ((void (__cdecl __noreturn *)(int))loc_3F639C0F)(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E179
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x3F62E356
// Name: sub_3F62E356
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_UNKNOWN **sub_3F62E356()
{
  return &off_3F661030;
}

//------------------------------------------------------------------------------
// Address: 0x3F62E40D
// Name: ___endstdio_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __endstdio_0()
{
  sub_3F62F3D6();
  if ( byte_3F663784 != 0 )
    ((void (*)(void))loc_3F63A363)();
  return ((int (__cdecl *)(int))loc_3F609ED0)(a1: dword_3F6660E0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E42D
// Name: __lock_file_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file_0(FILE *Stream)
{
  if ( Stream < (FILE *)&off_3F661030 || Stream > &stru_3F661290 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&Stream[1]);
  }
  else
  {
    _lock_0(a1: (((char *)Stream - (char *)&off_3F661030) >> 5) + 16);
    Stream->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62E469
// Name: __lock_file2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2_0(int a1, int a2)
{
  if ( a1 >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(a2 + 32));
  }
  else
  {
    _lock_0(a1: a1 + 16);
    *(_DWORD *)(a2 + 12) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62E497
// Name: __unlock_file_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file_0(FILE *Stream)
{
  if ( Stream < (FILE *)&off_3F661030 || Stream > &stru_3F661290 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&Stream[1]);
  }
  else
  {
    Stream->_flag &= ~0x8000u;
    _unlock_0(a1: (((char *)Stream - (char *)&off_3F661030) >> 5) + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62E4CD
// Name: __unlock_file2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2_0(int a1, int a2)
{
  if ( a1 >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(a2 + 32));
  }
  else
  {
    *(_DWORD *)(a2 + 12) &= ~0x8000u;
    _unlock_0(a1: a1 + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62E4F7
// Name: __openfile_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _openfile_0(unsigned __int8 *a1, char *a2)
{
  char v3; // al
  unsigned int v5; // [esp+24h] [ebp+Ch]

  while ( *a2 == 32 )
    ++a2;
  v3 = *a2;
  if ( *a2 == 97 )
  {
    v5 = 265;
  }
  else if ( v3 == 114 )
  {
    v5 = 0;
  }
  else
  {
    if ( v3 != 119 )
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: 0, a2: 0, a3: 0, a4: 0, a5: 0);
      JUMPOUT(0x3F62E793);
    }
    v5 = 769;
  }
  if ( a2[1] != 0 )
    JUMPOUT(0x3F62E57E);
  return _FindPESection(pImageBase: a1, rva: v5);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E5C4
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strncmp(_DWORD *a1@<eax>, int a2@<ebx>)
{
  *(_BYTE *)(a2 - 955249587) += (_BYTE)a1;
  *a1 += a1;
  JUMPOUT(0x3F62E5CE);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E690
// Name: _strpbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall strpbrk(
        int a1@<eax>,
        char a2@<dh>,
        int a3@<ecx>,
        int a4@<ebx>,
        char *a5@<esi>,
        unsigned __int8 *string,
        unsigned __int8 *control,
        unsigned __int8 *controla,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17)
{
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  char v22; // al
  _DWORD *retaddr; // [esp+0h] [ebp+0h]

  LOBYTE(a4) = BYTE1(a3) + a4;
  *((_BYTE *)&a17 + a1 + 3) += a2;
  while ( 1 )
  {
    v22 = *++a5;
    if ( *a5 == (_BYTE)a4 || a3 == a4 )
      break;
    if ( v22 > 83 )
      JUMPOUT(0x3F62E634);
    if ( v22 == 83 )
      JUMPOUT(0x3F62E622);
    v17 = v22 - 32;
    if ( v17 != 0 )
    {
      v18 = v17 - 11;
      if ( v18 != 0 )
      {
        v19 = v18 - 1;
        if ( v19 != 0 )
        {
          v20 = v19 - 24;
          if ( v20 != 0 )
          {
            v21 = v20 - 10;
            if ( v21 != 0 )
            {
              if ( v21 == 4 )
                JUMPOUT(0x3F62E5BF);
              JUMPOUT(0x3F62E736);
            }
            JUMPOUT(0x3F62E5D5);
          }
          JUMPOUT(0x3F62E5DD);
        }
        JUMPOUT(0x3F62E5F0);
      }
      JUMPOUT(0x3F62E5FC);
    }
  }
  if ( *(retaddr - 4) == a4 )
  {
    _FindPESection(pImageBase: string, rva: (unsigned int)control);
  }
  else
  {
    while ( *a5 == 32 )
      ++a5;
    sub_3F63B0C1(pwc: (wchar_t *)"ccs=", s: a5, n: 4u);
    _crt_debugger_hook(_Reserved: (int)string);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F62E6D0
// Name: __crt_debugger_hook
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _crt_debugger_hook(char a1@<zf>)
{
  if ( a1 )
    JUMPOUT(0x3F62E6D5);
  JUMPOUT(0x3F62E736);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E700
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_IMAGE_SECTION_HEADER *__usercall _ValidateImageBase@<eax>(
        char a1@<zf>,
        int a2@<ebp>,
        int a3@<esi>,
        unsigned __int8 *pImageBase,
        unsigned int a5)
{
  if ( !a1 )
  {
    if ( sub_3F63AF45(a1: a3, a2: "UNICODE") == 0 )
    {
      *(_DWORD *)(a2 + 12) |= 0x10000u;
      JUMPOUT(0x3F62E72A);
    }
    JUMPOUT(0x3F62E736);
  }
  *(_DWORD *)(a2 + 12) |= 0x20000u;
  return _FindPESection(pImageBase, rva: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E730
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _FindPESection(char a1@<zf>, char a2@<bl>, _DWORD *a3@<ebp>, _BYTE *a4@<esi>)
{
  if ( !a1 )
  {
    if ( *a4 == a2 )
    {
      if ( ((int (__cdecl *)(_DWORD *, _DWORD, _DWORD, _DWORD, int))loc_3F63AD0D)(
             a1: a3 - 4,
             a2: a3[2],
             a3: a3[3],
             a4: a3[4],
             a5: 384) == 0 )
      {
        ++dword_3F663790;
        JUMPOUT(0x3F62E77E);
      }
    }
    else
    {
      *_errno_0() = 22;
      _invalid_parameter_0(a1: a2, a2, a3: a2, a4: a2, a5: a2);
    }
    JUMPOUT(0x3F62E792);
  }
  JUMPOUT(0x3F62E72D);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E780
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char __usercall _IsNonwritableInCurrentImage@<al>(_DWORD *_EAX@<eax>, int a2@<ecx>, int _EBX@<ebx>)
{
  LOBYTE(_EAX) = (unsigned __int8)_EAX | 0x8B;
  __asm { lock mov [eax+4], ebx }
  *_EAX = _EBX;
  _EAX[2] = _EBX;
  _EAX[7] = _EBX;
  _EAX[4] = a2;
  return (char)_EAX;
}

//------------------------------------------------------------------------------
// Address: 0x3F62E83B
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn terminate(int a1@<ebx>, int a2@<esi>)
{
  if ( *(_DWORD *)(a2 + dword_3F6660E0) != a1 )
  {
    if ( ((int (__stdcall *)(int))__crtInitCritSecAndSpinCount_0)(a1: *(_DWORD *)(a2 + dword_3F6660E0) + 32) == 0 )
    {
      ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a2 + dword_3F6660E0));
      *(_DWORD *)(a2 + dword_3F6660E0) = a1;
      JUMPOUT(0x3F62E873);
    }
    JUMPOUT(0x3F62E875);
  }
  JUMPOUT(0x3F62E88D);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E874
// Name: void unexpected(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn unexpected(char a1@<cf>, int a2@<eax>, char a3@<dl>, char a4@<cl>, int a5@<ebx>)
{
  *(_BYTE *)(a5 - 1065155068) -= a1 + a4;
  *(_BYTE *)(a2 - 1) &= a3;
  _inconsistency();
}

//------------------------------------------------------------------------------
// Address: 0x3F62E887
// Name: void _inconsistency(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62E8BE
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_eh_hooks()
{
  _unlock_0(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E8CF
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _initp_misc_winsig()
{
  __asm { aas }
}

//------------------------------------------------------------------------------
// Address: 0x3F62E8E8
// Name: ctrlevent_capture
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge ctrlevent_capture(
        _BYTE *a1@<eax>,
        char a2@<dl>,
        int a3@<ecx>,
        int a4@<ebp>,
        _BYTE *a5@<edi>,
        _BYTE *a6@<esi>,
        unsigned int CtrlType)
{
  bool v7; // sf
  char v8; // cc
  unsigned int v9; // kr00_4
  int v10; // esi

  *a5 = *a6;
  LOBYTE(a1) = *a1 + (_BYTE)a1;
  *(a6 - 118) += a2;
  *(_BYTE *)(2 * (_DWORD)a1 - 1786183680) = *(_BYTE *)(2 * (_DWORD)a1 - 1786183680);
  v7 = (char)(a3 + *(_BYTE *)(a3 + 1971944541)) < 0;
  v8 = v7 ^ __OFADD__((_BYTE)a3, *(_BYTE *)(a3 + 1971944541));
  *(_BYTE *)(a3 + 1971944541) += a3;
  if ( !v7 )
  {
    if ( v8 )
    {
      *(_WORD *)(a4 + 160) = __SS__;
      *(_WORD *)(a4 + 148) = __CS__;
      *(_WORD *)(a4 + 112) = __DS__;
      *(_WORD *)(a4 + 108) = __ES__;
      *(_WORD *)(a4 + 104) = __FS__;
      *(_WORD *)(a4 + 100) = __GS__;
      v9 = __readeflags();
      *(_DWORD *)(a4 + 152) = v9;
      v10 = *(_DWORD *)(a4 + 684);
      *(_DWORD *)(a4 + 156) = a4 + 684;
      *(_DWORD *)(a4 - 40) = 65537;
      *(_DWORD *)(a4 + 144) = v10;
      *(_DWORD *)(a4 + 140) = *(_DWORD *)(a4 + 680);
      memset(a1: (void *)(a4 - 128), Val: 0, Size: 0x50u);
      *(_DWORD *)(a4 - 48) = a4 - 128;
      *(_DWORD *)(a4 - 128) = -1073741811;
      *(_DWORD *)(a4 - 116) = v10;
      *(_DWORD *)(a4 - 44) = a4 - 40;
      IsDebuggerPresent();
      JUMPOUT(0x3F62E983);
    }
    JUMPOUT(0x3F62E97C);
  }
  JUMPOUT(0x3F62E88F);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E983
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
_XCPT_ACTION *__usercall siglookup@<eax>(int a1@<eax>, int a2@<ebp>)
{
  HANDLE CurrentProcess; // eax
  int (__stdcall *v6)(_EXCEPTION_POINTERS *); // [esp-4h] [ebp-4h]

  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: v6);
  if ( UnhandledExceptionFilter(ExceptionInfo: (struct _EXCEPTION_POINTERS *)(a2 - 48)) == 0 && a1 == 0 )
    ((void (__cdecl *)(int))sub_3F63B0D8)(a1: 2);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC000000D);
  return (_XCPT_ACTION *)__get_sigabrt();
}

//------------------------------------------------------------------------------
// Address: 0x3F62E9B7
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __get_sigabrt()
{
  JUMPOUT(0x3F62E9C0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62E9C4
// Name: ___fpecode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__usercall __fpecode@<eax>(int *result@<eax>, int a2@<ecx>)
{
  *(_BYTE *)(a2 + 174277) += (_BYTE)result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62E9CD
// Name: ___pxcptinfoptrs
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62EA05
// Name: __invalid_parameter_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _invalid_parameter_0()
{
  int (*v0)(void); // eax
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  v0 = (int (*)(void))_decode_pointer_0(a1: (void *)dword_3F663794);
  if ( v0 == nullptr )
  {
    sub_3F63B0D8(a1: 2);
    savedregs = (int)&savedregs;
    JUMPOUT(0x3F62E8E6);
  }
  return v0();
}

//------------------------------------------------------------------------------
// Address: 0x3F62EA29
// Name: __invalid_parameter_noinfo_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo_0()
{
  _invalid_parameter_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F62EA42
// Name: __get_errno_from_oserr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr_0(int a1)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( a1 == dword_3F6612B8[2 * i] )
      return dword_3F6612BC[2 * i];
  }
  if ( (unsigned int)(a1 - 19) > 0x11 )
    return (unsigned int)(a1 - 188) > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x3F62EA7D
// Name: __errno_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno_0()
{
  DWORD *v0; // eax

  v0 = _getptd_noexit_0();
  if ( v0 != nullptr )
    return (int *)(v0 + 2);
  else
    return (int *)&unk_3F661420;
}

//------------------------------------------------------------------------------
// Address: 0x3F62EA90
// Name: ___doserrno_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno_0()
{
  DWORD *v0; // eax

  v0 = _getptd_noexit_0();
  if ( v0 != nullptr )
    return v0 + 3;
  else
    return (unsigned int *)&unk_3F661424;
}

//------------------------------------------------------------------------------
// Address: 0x3F62EAA3
// Name: __dosmaperr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _dosmaperr_0(unsigned int a1)
{
  int errno_from_oserr_0; // esi
  int *result; // eax

  *__doserrno_0() = a1;
  errno_from_oserr_0 = _get_errno_from_oserr_0(a1);
  result = _errno_0();
  *result = errno_from_oserr_0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62EC13
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall raise@<eax>(int a1@<eax>, int signum, int signuma, int a4, _DWORD *a5)
{
  LOBYTE(a1) = a1 & 8;
  *a5 = a1;
  return 3;
}

//------------------------------------------------------------------------------
// Address: 0x3F62EC22
// Name: __seh_longjmp_unwind4@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _seh_longjmp_unwind4(_DWORD *a1)
{
  return ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))_local_unwind4_0)(a1: a1[10], a2: a1[6], a3: a1[7]);
}

//------------------------------------------------------------------------------
// Address: 0x3F62EC88
// Name: _EH4_LocalUnwind::6_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind::6_0(int a1, int a2, int a3, int a4)
{
  return ((int (__cdecl *)(int, int, int))_local_unwind4_0)(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F62EDC3
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(unsigned int *enull)
{
  __asm { frstor  byte ptr [ebp+3Fh] }
  rand_s(_RandomValue: enull);
}

//------------------------------------------------------------------------------
// Address: 0x3F62EDCD
// Name: _rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall rand_s@<eax>(int a1@<ebp>, int *a2@<edi>)
{
  unsigned int v2; // eax
  unsigned int i; // ecx
  int *v4; // eax
  int v5; // edi
  int j; // esi
  unsigned int v7; // eax
  int *v8; // ecx
  unsigned int k; // edx

  *(_DWORD *)(a1 - 4) = a2;
  GetStartupInfoA(lpStartupInfo: (LPSTARTUPINFOA)(a1 - 100));
  *(_DWORD *)(a1 - 4) = -2;
  v2 = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 32, a2: 56);
  if ( (int *)v2 != a2 )
  {
    dword_3F665FE0[0] = v2;
    uNumber = 32;
    for ( i = v2 + 1792; v2 < i; i = dword_3F665FE0[0] + 1792 )
    {
      *(_BYTE *)(v2 + 4) = 0;
      *(_DWORD *)v2 = -1;
      *(_BYTE *)(v2 + 5) = 10;
      *(_DWORD *)(v2 + 8) = a2;
      *(_BYTE *)(v2 + 36) = 0;
      *(_BYTE *)(v2 + 37) = 10;
      *(_BYTE *)(v2 + 38) = 10;
      v2 += 56;
    }
    if ( *(_WORD *)(a1 - 50) != (_WORD)a2 )
    {
      v4 = *(int **)(a1 - 48);
      if ( v4 != a2 )
      {
        v5 = *v4;
        *(_DWORD *)(a1 - 28) = (char *)v4 + *v4 + 4;
        if ( v5 >= 2048 )
          v5 = 2048;
        for ( j = 1; ; ++j )
        {
          if ( (int)uNumber >= v5 )
            goto LABEL_18;
          v7 = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 32, a2: 56);
          if ( v7 == 0 )
            break;
          v8 = &dword_3F665FE0[j];
          *v8 = v7;
          uNumber += 32;
          for ( k = v7 + 1792; v7 < k; k = *v8 + 1792 )
          {
            *(_BYTE *)(v7 + 4) = 0;
            *(_DWORD *)v7 = -1;
            *(_BYTE *)(v7 + 5) = 10;
            *(_DWORD *)(v7 + 8) = 0;
            *(_BYTE *)(v7 + 36) &= 0x80u;
            *(_BYTE *)(v7 + 37) = 10;
            *(_BYTE *)(v7 + 38) = 10;
            v7 += 56;
          }
        }
        v5 = uNumber;
LABEL_18:
        *(_DWORD *)(a1 - 32) = 0;
        if ( v5 > 0 )
          JUMPOUT(0x3F62EED0);
      }
    }
    JUMPOUT(0x3F62EF3D);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62EED1
// Name: __initp_misc_initcrit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _initp_misc_initcrit(int a1@<ebx>)
{
  unsigned __int8 v1; // al

  v1 = __inbyte(0x8Bu);
  *(_BYTE *)(a1 + 1450508281) |= v1;
  JUMPOUT(0x3F62EEDA);
}

//------------------------------------------------------------------------------
// Address: 0x3F62EEDB
// Name: __crtInitCritSecNoSpinCount
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _crtInitCritSecNoSpinCount(_RTL_CRITICAL_SECTION *lpCriticalSection, unsigned int dwSpinCount)
{
  JUMPOUT(0x3F62EEDC);
}

//------------------------------------------------------------------------------
// Address: 0x3F62EFB0
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _initp_heap_handler(int a1@<esi>, int (__cdecl *enull)(unsigned int))
{
  ((void (__cdecl *)(int))__crtInitCritSecAndSpinCount_0)(a1: a1 + 12);
  _set_new_handler(pnh: enull);
}

//------------------------------------------------------------------------------
// Address: 0x3F62EFBA
// Name: int (*_set_new_handler(int (*)(unsigned int)))(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _set_new_handler@<eax>(int a1@<eax>, int a2@<ebx>, int a3@<esi>)
{
  if ( a1 == 0 )
    return -1;
  ++*(_DWORD *)(a3 + 8);
  if ( a2 + 1 < 3 )
    JUMPOUT(0x3F62EF3F);
  SetHandleCount(uNumber: uNumber);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F62EFFF
// Name: __ioterm_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioterm_0(unsigned int a1)
{
  return _callnewh(size: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F001
// Name: __callnewh
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _callnewh()
{
  if ( dword_3F665FE0[0] != 0 )
    JUMPOUT(0x3F62F02E);
  JUMPOUT(0x3F62F03D);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F023
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _fcloseall@<eax>(int _EAX@<eax>, int a2@<edi>, _DWORD *a3@<esi>)
{
  int result; // eax

  __asm { aas }
  if ( a2 + 56 < (unsigned int)(*a3 + 1792) )
    JUMPOUT(0x3F62F014);
  result = ((int (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *a3);
  *a3 = 0;
  if ( (int)(a3 + 1) < (int)&dword_3F6660E0 )
    JUMPOUT(0x3F62F006);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F04B
// Name: __fileno_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fileno_0(FILE *Stream)
{
  if ( Stream != nullptr )
    return Stream->_file;
  *_errno_0() = 22;
  _invalid_parameter_0();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F078
// Name: __close_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock_0(int *a1, const char *a2, int a3, int a4, int a5, int a6)
{
  int v6; // edi
  int *v7; // eax

  if ( ((int (__cdecl *)(int *))loc_3F63B222)(a1) == -1
    || (a1 == (int *)1 && (*(_BYTE *)(dword_3F665FE0[0] + 116) & 1) != 0
     || a1 == (int *)2 && (*(_BYTE *)(dword_3F665FE0[0] + 60) & 1) != 0)
    && (v6 = ((int (__cdecl *)(int))loc_3F63B222)(a1: 2), ((int (__cdecl *)(int))loc_3F63B222)(a1: 1) == v6) )
  {
    JUMPOUT(0x3F62F0D7);
  }
  v7 = (int *)((int (__cdecl *)(int *))loc_3F63B222)(a1);
  return tsopen_nolock(punlock_flag: a1, pfh: v7, path: a2, oflag: a3, shflag: a4, pmode: a5, bSecure: a6);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F0C2
// Name: _tsopen_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall tsopen_nolock@<eax>(int *pfh@<eax>, int a2@<esi>)
{
  DWORD LastError; // edi

  if ( CloseHandle(hObject: pfh) )
    LastError = 0;
  else
    LastError = GetLastError();
  ((void (__cdecl *)(int))loc_3F63B1A1)(a1: a2);
  *(_BYTE *)(dword_3F665FE0[a2 >> 5] + 56 * (a2 & 0x1F) + 4) = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr_0(a1: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F10C
// Name: __close_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_0(int FileHandle)
{
  int *v2; // ebx
  int v3; // esi
  const char *v4; // [esp+0h] [ebp-30h]
  int v5; // [esp+4h] [ebp-2Ch]
  int v6; // [esp+8h] [ebp-28h]
  int v7; // [esp+Ch] [ebp-24h]
  int v8; // [esp+10h] [ebp-20h]
  int v9; // [esp+14h] [ebp-1Ch]
  int v10; // [esp+14h] [ebp-1Ch]
  int ms_exc; // [esp+18h] [ebp-18h]
  int ms_exc_4; // [esp+1Ch] [ebp-14h]
  int ms_exc_8; // [esp+20h] [ebp-10h]
  int ms_exc_12; // [esp+24h] [ebp-Ch]
  int ms_exc_16; // [esp+28h] [ebp-8h]

  if ( FileHandle == -2 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    return -1;
  }
  if ( FileHandle < 0
    || FileHandle >= uNumber
    || (v2 = &dword_3F665FE0[FileHandle >> 5], v3 = 56 * (FileHandle & 0x1F), (*(_BYTE *)(*v2 + v3 + 4) & 1) == 0) )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    _invalid_parameter_0();
    return -1;
  }
  ((void (__cdecl *)(int))loc_3F63B293)(a1: FileHandle);
  if ( (*(_BYTE *)(*v2 + v3 + 4) & 1) != 0 )
  {
    v9 = _close_nolock_0(a1: (int *)FileHandle, a2: v4, a3: v5, a4: v6, a5: v7, a6: v8);
  }
  else
  {
    *_errno_0() = 9;
    v9 = -1;
  }
  ((void (__stdcall *)(int, int, const char *, int, int, int, int, int, int, int, int, int, int))_LN9_16)(
    a1: FileHandle,
    a2: 1063449030,
    a3: v4,
    a4: v5,
    a5: v6,
    a6: v7,
    a7: v8,
    a8: v9,
    a9: ms_exc,
    a10: ms_exc_4,
    a11: ms_exc_8,
    a12: ms_exc_12,
    a13: ms_exc_16);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F1D9
// Name: __freebuf_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _freebuf_0(_DWORD *a1)
{
  int result; // eax

  result = a1[3];
  if ( (result & 0x83) != 0 && (result & 8) != 0 )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[2]);
    a1[3] &= 0xFFFFFBF7;
    *a1 = 0;
    a1[2] = 0;
    a1[1] = 0;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F205
// Name: __flush_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush_0(FILE *Stream)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = Stream->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = Stream->_base;
    v4 = (char *)(Stream->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(Stream->_ptr - base);
      v9 = Stream->_base;
      v5 = _fileno_0(Stream);
      if ( (char *)((int (__cdecl *)(int, char *, char *))loc_3F63BBCF)(a1: v5, a2: v9, a3: v10) == v4 )
      {
        v6 = Stream->_flag;
        if ( (v6 & 0x80u) != 0 )
          Stream->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        Stream->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = Stream->_base;
  Stream->_cnt = 0;
  Stream->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F267
// Name: __fflush_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock_0(FILE *Stream)
{
  int v2; // eax

  if ( Stream == nullptr )
    return flsall(a1: 0);
  if ( _flush_0(Stream) != 0 )
    return -1;
  if ( (Stream->_flag & 0x4000) == 0 )
    return 0;
  v2 = _fileno_0(Stream);
  return -(((int (__cdecl *)(int))loc_3F63BCAB)(a1: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F2A9
// Name: _flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int a1)
{
  int i; // esi
  int *v2; // eax
  int v3; // eax
  int v4; // ecx
  int result; // eax
  int v6; // [esp+10h] [ebp-24h]
  int v7; // [esp+18h] [ebp-1Ch]

  v7 = 0;
  v6 = 0;
  _lock_0(a1: 1);
  for ( i = 0; i < dword_3F667100; ++i )
  {
    v2 = (int *)(dword_3F6660E0 + 4 * i);
    if ( *v2 != 0 )
    {
      v3 = *v2;
      if ( (*(_BYTE *)(v3 + 12) & 0x83) != 0 )
      {
        _lock_file2_0(a1: i, a2: v3);
        v4 = *(_DWORD *)(*(_DWORD *)(dword_3F6660E0 + 4 * i) + 12);
        if ( (v4 & 0x83) != 0 )
        {
          if ( a1 == 1 )
          {
            if ( _fflush_nolock_0(Stream: *(FILE **)(dword_3F6660E0 + 4 * i)) != -1 )
              ++v7;
          }
          else if ( a1 == 0 && (v4 & 2) != 0 && _fflush_nolock_0(Stream: *(FILE **)(dword_3F6660E0 + 4 * i)) == -1 )
          {
            v6 = -1;
          }
        }
        _unlock_file2_0(a1: i, a2: *(_DWORD *)(dword_3F6660E0 + 4 * i));
      }
    }
  }
  _unlock_0(a1: 1);
  result = v7;
  if ( a1 != 1 )
    return v6;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F383
// Name: _fflush_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush_0(FILE *Stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  if ( Stream == nullptr )
    return flsall(a1: 0);
  _lock_file_0(Stream);
  v2 = _fflush_nolock_0(Stream);
  _unlock_file_0(Stream);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F3D6
// Name: sub_3F62F3D6
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F62F3D6()
{
  return flsall(a1: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F3DF
// Name: __stbuf_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stbuf_0(FILE *Stream)
{
  int v1; // eax
  int v2; // eax
  char **v3; // edi
  int v4; // eax
  char *v5; // edi

  v1 = _fileno_0(Stream);
  if ( _isatty_0(FileHandle: v1) == 0 )
    return 0;
  if ( Stream == (FILE *)(sub_3F62E356() + 8) )
  {
    v2 = 0;
  }
  else
  {
    if ( Stream != (FILE *)(sub_3F62E356() + 16) )
      return 0;
    v2 = 1;
  }
  ++dword_3F663790;
  if ( (Stream->_flag & 0x10C) != 0 )
    return 0;
  v3 = (char **)((char *)&unk_3F663798 + 4 * v2);
  if ( *v3 != nullptr || (v4 = ((int (__cdecl *)(int))loc_3F609A30)(a1: 4096), *v3 = (char *)v4, v4 != 0) )
  {
    v5 = *v3;
    Stream->_base = v5;
    Stream->_ptr = v5;
    Stream->_bufsiz = 4096;
    Stream->_cnt = 4096;
  }
  else
  {
    Stream->_base = (char *)&Stream->_charbuf;
    Stream->_ptr = (char *)&Stream->_charbuf;
    Stream->_bufsiz = 2;
    Stream->_cnt = 2;
  }
  Stream->_flag |= 0x1102u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F475
// Name: __ftbuf_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftbuf_0(int a1, FILE *Stream)
{
  int result; // eax

  if ( a1 != 0 && (Stream->_flag & 0x1000) != 0 )
  {
    result = _flush_0(Stream);
    Stream->_flag &= 0xFFFFEEFF;
    Stream->_bufsiz = 0;
    Stream->_ptr = nullptr;
    Stream->_base = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62F4A4
// Name: _get_int_arg_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl get_int_arg_0(_DWORD *a1)
{
  *a1 += 4;
  return *(_DWORD *)(*a1 - 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F4B1
// Name: _get_int64_arg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl get_int64_arg(_DWORD *a1)
{
  *a1 += 8;
  return *(_QWORD *)(*a1 - 8);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F4C1
// Name: _get_short_arg_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int16 __cdecl get_short_arg_0(_DWORD *a1)
{
  *a1 += 4;
  return *(_WORD *)(*a1 - 4);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F4CF
// Name: __output_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62F81B
// Name: __open
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _open(int a1@<ecx>, char *a2@<ebx>, int a3@<ebp>, const char *path, const char *oflag, ...)
{
  int v5; // edx
  char v6; // al

  MK_FP(*(_WORD *)(a1 - 123 + 4), *(_DWORD *)(a1 - 123))();
  *(_BYTE *)(v5 + 1952048965) = __ROR1__(*(_BYTE *)(v5 + 1952048965), 25);
  ((void (__thiscall *)(_DWORD))write_char)(a1: *(_DWORD *)(a3 - 48));
  v6 = *a2;
  *(_DWORD *)(a3 - 72) = a2 + 1;
  if ( v6 != 0 )
  {
    ((void (__thiscall *)(_DWORD))write_char)(a1: *(_DWORD *)(a3 - 48));
    JUMPOUT(0x3F62FDEB);
  }
  JUMPOUT(0x3F62FE04);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F8D1
// Name: __sopen_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _sopen_helper(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  int v3; // ecx
  int v4; // edi
  bool v5; // zf
  int v6; // edi
  _WORD *v7; // eax
  int v8; // eax
  _BYTE *i; // eax
  int v10; // eax
  int v11; // ebx
  int v12; // edi
  int v13; // eax

  *(_DWORD *)(a1 - 24) |= 0x800u;
  v3 = *(_DWORD *)(a1 - 32);
  if ( v3 == -1 )
    v3 = 0x7FFFFFFF;
  v4 = a2 + 4;
  v5 = (*(_WORD *)(a1 - 24) & 0x810) == 0;
  *(_DWORD *)(a1 - 44) = v4;
  v6 = *(_DWORD *)(v4 - 4);
  *(_DWORD *)(a1 - 36) = v6;
  if ( v5 )
  {
    if ( v6 == a3 )
      *(_DWORD *)(a1 - 36) = Str;
    for ( i = *(_BYTE **)(a1 - 36); v3 != a3; ++i )
    {
      --v3;
      if ( *i == 0 )
        break;
    }
    v8 = (int)&i[-*(_DWORD *)(a1 - 36)];
  }
  else
  {
    if ( v6 == a3 )
      *(_DWORD *)(a1 - 36) = off_3F661464;
    v7 = *(_WORD **)(a1 - 36);
    *(_DWORD *)(a1 - 68) = 1;
    while ( v3 != a3 )
    {
      --v3;
      if ( *v7 == (_WORD)a3 )
        break;
      ++v7;
    }
    v8 = ((int)v7 - *(_DWORD *)(a1 - 36)) >> 1;
  }
  *(_DWORD *)(a1 - 40) = v8;
  if ( *(_DWORD *)(a1 - 80) != 0 )
    JUMPOUT(0x3F62FDD8);
  v10 = *(_DWORD *)(a1 - 24);
  if ( (v10 & 0x40) != 0 )
  {
    if ( (v10 & 0x100) != 0 )
    {
      *(_BYTE *)(a1 - 56) = 45;
    }
    else if ( (v10 & 1) != 0 )
    {
      *(_BYTE *)(a1 - 56) = 43;
    }
    else
    {
      if ( (v10 & 2) == 0 )
        goto LABEL_27;
      *(_BYTE *)(a1 - 56) = 32;
    }
    *(_DWORD *)(a1 - 60) = 1;
  }
LABEL_27:
  v11 = *(_DWORD *)(a1 - 64) - *(_DWORD *)(a1 - 40) - *(_DWORD *)(a1 - 60);
  if ( (*(_BYTE *)(a1 - 24) & 0xC) == 0 )
    write_multi_char_0(a1: 32, a2: v11, a3: *(_DWORD *)(a1 - 48));
  v12 = *(_DWORD *)(a1 - 48);
  ((void (__cdecl *)(_DWORD))write_string)(a1: *(_DWORD *)(a1 - 60));
  if ( (*(_BYTE *)(a1 - 24) & 8) != 0 && (*(_BYTE *)(a1 - 24) & 4) == 0 )
    write_multi_char_0(a1: 48, a2: v11, a3: v12);
  v13 = *(_DWORD *)(a1 - 40);
  if ( *(_DWORD *)(a1 - 68) != 0 && v13 > 0 )
  {
    *(_DWORD *)(a1 - 104) = v13;
    --*(_DWORD *)(a1 - 104);
    JUMPOUT(0x3F62FD7F);
  }
  JUMPOUT(0x3F62FDB0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F99D
// Name: __sopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _sopen(
        char a1@<zf>,
        int a2@<eax>,
        int a3@<ebp>,
        int a4@<esi>,
        const char *path,
        const char *oflag,
        int shflag,
        ...)
{
  int v7; // eax
  int v8; // ebx
  int v9; // edi
  int v10; // eax

  if ( a1 )
  {
    *(_DWORD *)(a3 - 68) = a4;
  }
  else
  {
    a2 /= 2;
    *(_DWORD *)(a3 - 68) = 1;
  }
  *(_DWORD *)(a3 - 40) = a2;
  if ( *(_DWORD *)(a3 - 80) != 0 )
    JUMPOUT(0x3F62FDD8);
  v7 = *(_DWORD *)(a3 - 24);
  if ( (v7 & 0x40) != 0 )
  {
    if ( (v7 & 0x100) != 0 )
    {
      *(_BYTE *)(a3 - 56) = 45;
    }
    else if ( (v7 & 1) != 0 )
    {
      *(_BYTE *)(a3 - 56) = 43;
    }
    else
    {
      if ( (v7 & 2) == 0 )
        goto LABEL_13;
      *(_BYTE *)(a3 - 56) = 32;
    }
    *(_DWORD *)(a3 - 60) = 1;
  }
LABEL_13:
  v8 = *(_DWORD *)(a3 - 64) - *(_DWORD *)(a3 - 40) - *(_DWORD *)(a3 - 60);
  if ( (*(_BYTE *)(a3 - 24) & 0xC) == 0 )
    write_multi_char_0(a1: 32, a2: v8, a3: *(_DWORD *)(a3 - 48));
  v9 = *(_DWORD *)(a3 - 48);
  ((void (__cdecl *)(_DWORD))write_string)(a1: *(_DWORD *)(a3 - 60));
  if ( (*(_BYTE *)(a3 - 24) & 8) != 0 && (*(_BYTE *)(a3 - 24) & 4) == 0 )
    write_multi_char_0(a1: 48, a2: v8, a3: v9);
  v10 = *(_DWORD *)(a3 - 40);
  if ( *(_DWORD *)(a3 - 68) != 0 && v10 > 0 )
  {
    *(_DWORD *)(a3 - 104) = v10;
    --*(_DWORD *)(a3 - 104);
    JUMPOUT(0x3F62FD7F);
  }
  JUMPOUT(0x3F62FDB0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F9CD
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _sopen_s(int a1, _DWORD *a2)
{
  ++*a2;
  JUMPOUT(0x3F62F9CF);
}

//------------------------------------------------------------------------------
// Address: 0x3F62F9EB
// Name: __mbsicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _mbsicmp_l@<eax>(
        bool a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        int a4@<eax>,
        int a5@<ebp>,
        _WORD **a6@<edi>,
        unsigned int a7@<esi>,
        const unsigned __int8 *s1,
        const unsigned __int8 *s2)
{
  _WORD *v9; // esi
  int v10; // ecx
  __int64 v11; // rax
  _WORD **v12; // edi

  if ( a2 ^ a3 | a1 )
    JUMPOUT(0x3F62F892);
  switch ( a4 )
  {
    case 'i':
      *(_DWORD *)(a5 - 24) |= 0x40u;
      *(_DWORD *)(a5 - 40) = 10;
      break;
    case 'n':
      v9 = *a6;
      *(_DWORD *)(a5 - 44) = a6 + 1;
      if ( _get_printf_count_output_0() != 0 )
      {
        if ( (*(_BYTE *)(a5 - 24) & 0x20) != 0 )
          *v9 = *(_WORD *)(a5 - 52);
        else
          *(_DWORD *)v9 = *(_DWORD *)(a5 - 52);
        *(_DWORD *)(a5 - 80) = 1;
        JUMPOUT(0x3F62FDD8);
      }
      JUMPOUT(0x3F62FE04);
    case 'o':
      a1 = *(_BYTE *)(a5 - 24) >= 0;
      *(_DWORD *)(a5 - 40) = 8;
      if ( !a1 )
        *(_DWORD *)(a5 - 24) |= 0x200u;
      break;
    default:
      JUMPOUT(0x3F62FCD3);
  }
  v10 = *(_DWORD *)(a5 - 24);
  if ( (v10 & 0x8000u) != 0 || (v10 & 0x1000) != 0 )
  {
    v11 = *(_QWORD *)a6;
    v12 = a6 + 2;
  }
  else
  {
    v12 = a6 + 1;
    if ( (v10 & 0x20) != 0 )
    {
      *(_DWORD *)(a5 - 44) = v12;
      if ( (v10 & 0x40) != 0 )
        LODWORD(v11) = *((__int16 *)v12 - 2);
      else
        LODWORD(v11) = *((unsigned __int16 *)v12 - 2);
      v11 = (int)v11;
      goto LABEL_25;
    }
    LODWORD(v11) = *(v12 - 1);
    if ( (v10 & 0x40) != 0 )
      v11 = (int)v11;
    else
      HIDWORD(v11) = 0;
  }
  *(_DWORD *)(a5 - 44) = v12;
LABEL_25:
  if ( (v10 & 0x40) != 0 && v11 < __SPAIR64__(a7, a7) )
    *(_DWORD *)(a5 - 24) |= 0x100u;
  return _mbsicmp(s1, s2);
}

//------------------------------------------------------------------------------
// Address: 0x3F62FC05
// Name: __mbsicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsicmp(bool a1@<zf>, unsigned int a2@<eax>, unsigned int a3@<edx>, int a4@<ebp>)
{
  unsigned int v5; // edi
  _BYTE *i; // esi
  int v7; // eax
  unsigned __int64 v8; // rcx
  int v9; // ecx
  int v10; // eax
  _BYTE *v11; // esi
  int v12; // eax
  int v13; // ebx
  int v14; // edi
  int v15; // eax
  unsigned __int64 v16; // [esp-10h] [ebp-10h]
  unsigned __int64 v17; // [esp-8h] [ebp-8h]

  v5 = a2;
  if ( a1 )
    a3 = 0;
  if ( *(int *)(a4 - 32) < 0 )
  {
    *(_DWORD *)(a4 - 32) = 1;
    JUMPOUT(0x3F62FC1A);
  }
  *(_DWORD *)(a4 - 24) &= ~8u;
  if ( *(int *)(a4 - 32) > 512 )
    *(_DWORD *)(a4 - 32) = 512;
  if ( (a3 | a2) == 0 )
    *(_DWORD *)(a4 - 60) = 0;
  for ( i = (_BYTE *)(a4 + 491); ; --i )
  {
    v7 = *(_DWORD *)(a4 - 32);
    *(_DWORD *)(a4 - 32) = v7 - 1;
    if ( v7 <= 0 && (a3 | v5) == 0 )
      break;
    v17 = *(int *)(a4 - 40);
    v16 = __PAIR64__(a3, v5);
    v8 = __PAIR64__(a3, v5) % v17;
    v9 = v8 + 48;
    *(_DWORD *)(a4 - 104) = HIDWORD(v8);
    a3 = (v16 / v17) >> 32;
    v5 = v16 / v17;
    if ( v9 > 57 )
      v9 += *(_DWORD *)(a4 - 76);
    *i = v9;
  }
  v10 = a4 + 491 - (_DWORD)i;
  v11 = i + 1;
  a1 = (*(_WORD *)(a4 - 24) & 0x200) == 0;
  *(_DWORD *)(a4 - 40) = v10;
  *(_DWORD *)(a4 - 36) = v11;
  if ( !a1 && (v10 == 0 || *v11 != 48) )
  {
    *(_BYTE *)--*(_DWORD *)(a4 - 36) = 48;
    *(_DWORD *)(a4 - 40) = v10 + 1;
  }
  if ( *(_DWORD *)(a4 - 80) != 0 )
    JUMPOUT(0x3F62FDD8);
  v12 = *(_DWORD *)(a4 - 24);
  if ( (v12 & 0x40) != 0 )
  {
    if ( (v12 & 0x100) != 0 )
    {
      *(_BYTE *)(a4 - 56) = 45;
    }
    else if ( (v12 & 1) != 0 )
    {
      *(_BYTE *)(a4 - 56) = 43;
    }
    else
    {
      if ( (v12 & 2) == 0 )
        goto LABEL_29;
      *(_BYTE *)(a4 - 56) = 32;
    }
    *(_DWORD *)(a4 - 60) = 1;
  }
LABEL_29:
  v13 = *(_DWORD *)(a4 - 64) - *(_DWORD *)(a4 - 40) - *(_DWORD *)(a4 - 60);
  if ( (*(_BYTE *)(a4 - 24) & 0xC) == 0 )
    write_multi_char_0(a1: 32, a2: v13, a3: *(_DWORD *)(a4 - 48));
  v14 = *(_DWORD *)(a4 - 48);
  ((void (__cdecl *)(_DWORD))write_string)(a1: *(_DWORD *)(a4 - 60));
  if ( (*(_BYTE *)(a4 - 24) & 8) != 0 && (*(_BYTE *)(a4 - 24) & 4) == 0 )
    write_multi_char_0(a1: 48, a2: v13, a3: v14);
  v15 = *(_DWORD *)(a4 - 40);
  if ( *(_DWORD *)(a4 - 68) != 0 && v15 > 0 )
  {
    *(_DWORD *)(a4 - 104) = v15;
    --*(_DWORD *)(a4 - 104);
    JUMPOUT(0x3F62FD7F);
  }
  JUMPOUT(0x3F62FDB0);
}

//------------------------------------------------------------------------------
// Address: 0x3F62FD81
// Name: __mbsnbcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _mbsnbcmp(_DWORD *a1@<eax>, int a2@<ebp>)
{
  *a1 = *a1;
  if ( a1 == nullptr && *(_DWORD *)(a2 - 112) != 0 )
    JUMPOUT(0x3F62FD96);
  JUMPOUT(0x3F62FDAA);
}

//------------------------------------------------------------------------------
// Address: 0x3F62FD98
// Name: __global_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __usercall _global_unwind2@<edx:eax>(__int64 result@<edx:eax>, char a2@<ch>)
{
  LOBYTE(result) = __inbyte(WORD2(result));
  *(_DWORD *)result += result;
  LOBYTE(result) = a2 + result;
  return (int)result;
}

//------------------------------------------------------------------------------
// Address: 0x3F62FDB8
// Name: __unwind_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _unwind_handler(char a1@<zf>, char a2@<sf>, char a3@<of>)
{
  if ( !(a2 ^ a3 | a1) )
    JUMPOUT(0x3F62FDBA);
  JUMPOUT(0x3F62FD7C);
}

//------------------------------------------------------------------------------
// Address: 0x3F62FDFD
// Name: __local_unwind2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _local_unwind2(char a1@<al>, int a2@<ecx>, int a3@<ebx>, int a4@<ebp>, int a5@<edi>)
{
  char *v5; // ebx
  bool v6; // sf
  int v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  char v13; // al

  v5 = (char *)(a3 + 1);
  v6 = *(int *)(a4 - 52) < 0;
  *(_DWORD *)(a4 - 72) = v5;
  if ( !v6 )
  {
    if ( (unsigned __int8)(a1 - 32) > 0x58u )
      v7 = 0;
    else
      v7 = aUnicode[a1 + 4] & 0xF;
    v8 = byte_3F6544F8[8 * v7 + a2] >> 4;
    *(_DWORD *)(a4 - 116) = v8;
    switch ( v8 )
    {
      case 0:
        goto LABEL_52;
      case 1:
        *(_DWORD *)(a4 - 32) = -1;
        *(_DWORD *)(a4 - 120) = 0;
        *(_DWORD *)(a4 - 80) = 0;
        *(_DWORD *)(a4 - 64) = 0;
        *(_DWORD *)(a4 - 60) = 0;
        *(_DWORD *)(a4 - 24) = 0;
        *(_DWORD *)(a4 - 68) = 0;
        goto LABEL_54;
      case 2:
        switch ( a1 )
        {
          case ' ':
            *(_DWORD *)(a4 - 24) |= 2u;
            break;
          case '#':
            *(_DWORD *)(a4 - 24) |= 0x80u;
            break;
          case '+':
            *(_DWORD *)(a4 - 24) |= 1u;
            break;
          case '-':
            *(_DWORD *)(a4 - 24) |= 4u;
            break;
          case '0':
            *(_DWORD *)(a4 - 24) |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_54;
      case 3:
        if ( a1 == 42 )
        {
          v9 = a5 + 4;
          *(_DWORD *)(a4 - 44) = v9;
          v10 = *(_DWORD *)(v9 - 4);
          *(_DWORD *)(a4 - 64) = v10;
          if ( v10 < 0 )
          {
            *(_DWORD *)(a4 - 24) |= 4u;
            *(_DWORD *)(a4 - 64) = -*(_DWORD *)(a4 - 64);
          }
        }
        else
        {
          *(_DWORD *)(a4 - 64) = 10 * *(_DWORD *)(a4 - 64) + a1 - 48;
        }
        goto LABEL_54;
      case 4:
        *(_DWORD *)(a4 - 32) = 0;
        goto LABEL_54;
      case 5:
        if ( a1 == 42 )
        {
          v11 = a5 + 4;
          *(_DWORD *)(a4 - 44) = v11;
          v12 = *(_DWORD *)(v11 - 4);
          *(_DWORD *)(a4 - 32) = v12;
          if ( v12 < 0 )
            *(_DWORD *)(a4 - 32) = -1;
        }
        else
        {
          *(_DWORD *)(a4 - 32) = 10 * *(_DWORD *)(a4 - 32) + a1 - 48;
        }
        goto LABEL_54;
      case 6:
        switch ( a1 )
        {
          case 'I':
            v13 = *v5;
            if ( *v5 == 54 && v5[1] == 52 )
            {
              *(_DWORD *)(a4 - 24) |= 0x8000u;
              *(_DWORD *)(a4 - 72) = v5 + 2;
            }
            else if ( v13 == 51 && v5[1] == 50 )
            {
              *(_DWORD *)(a4 - 24) &= ~0x8000u;
              *(_DWORD *)(a4 - 72) = v5 + 2;
            }
            else if ( v13 != 100 && v13 != 105 && v13 != 111 && v13 != 117 && v13 != 120 && v13 != 88 )
            {
              *(_DWORD *)(a4 - 116) = 0;
LABEL_52:
              JUMPOUT(0x3F62F815);
            }
            break;
          case 'h':
            *(_DWORD *)(a4 - 24) |= 0x20u;
            break;
          case 'l':
            if ( *v5 == 108 )
            {
              *(_DWORD *)(a4 - 24) |= 0x1000u;
              *(_DWORD *)(a4 - 72) = v5 + 1;
            }
            else
            {
              *(_DWORD *)(a4 - 24) |= 0x10u;
            }
            break;
          case 'w':
            *(_DWORD *)(a4 - 24) |= 0x800u;
            break;
          default:
            break;
        }
LABEL_54:
        JUMPOUT(0x3F62FDEB);
      case 7:
        JUMPOUT(0x3F62F853);
      default:
        goto LABEL_54;
    }
  }
  if ( *(_BYTE *)(a4 - 88) != 0 )
    JUMPOUT(0x3F62FE24);
  __security_check_cookie`...'(StackCookie: a4 ^ *(_DWORD *)(a4 + 500));
}

//------------------------------------------------------------------------------
// Address: 0x3F62FE81
// Name: __abnormal_termination
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination()
{
  char v0; // zf
  char v1; // sf
  char v2; // of
  int *v3; // eax
  int *v4; // edi
  FILE *v5; // esi

  if ( v1 == v2 )
  {
LABEL_4:
    *v3 = 22;
    _invalid_parameter_0();
    JUMPOUT(0x3F62FEA5);
  }
  LOBYTE(v3) = !v0;
  if ( v3 == v4 )
  {
    v3 = _errno_0();
    goto LABEL_4;
  }
  _lock_file_0(Stream: v5);
  return _NLG_Notify();
}

//------------------------------------------------------------------------------
// Address: 0x3F62FEAD
// Name: __NLG_Notify
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F62FECC
// Name: __NLG_Call
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _NLG_Call(_DWORD *a1@<edi>, _DWORD *a2@<esi>)
{
  *a1 = *a2;
  JUMPOUT(0x3F62FECE);
}

//------------------------------------------------------------------------------
// Address: 0x3F62FECF
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _read_nolock(int a1@<ebx>)
{
  ++*(_DWORD *)(a1 + 1170676932);
  JUMPOUT(0x3F62FED6);
}

//------------------------------------------------------------------------------
// Address: 0x3F630490
// Name: __read
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _read@<eax>(unsigned __int16 a1@<dx>, int a2@<ebp>)
{
  int v2; // eax
  int result; // eax

  __inbyte(a1);
  _LocaleUpdate::_LocaleUpdate(this: (_LocaleUpdate *)(a2 - 16), a2: nullptr);
  v2 = *(_DWORD *)(a2 - 12);
  if ( *(_DWORD *)(v2 + 8) != 0 )
  {
    result = *(_DWORD *)(v2 + 4);
    if ( *(_BYTE *)(a2 - 4) != 0 )
      *(_DWORD *)(*(_DWORD *)(a2 - 8) + 112) &= ~2u;
  }
  else
  {
    if ( *(_BYTE *)(a2 - 4) != 0 )
      *(_DWORD *)(*(_DWORD *)(a2 - 8) + 112) &= ~2u;
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63058D
// Name: __getbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _getbuf(int a1@<eax>, int a2@<ebx>, int a3@<ebp>)
{
  int i; // eax

  dword_3F6637B0 = a1;
  dword_3F6637B4 = *(_DWORD *)(a2 + 8);
  dword_3F6637B8 = *(_DWORD *)(a2 + 12);
  for ( i = 0; ; ++i )
  {
    *(_DWORD *)(a3 - 28) = i;
    if ( i >= 5 )
      break;
    word_3F6637A4[i] = *(_WORD *)(a2 + 2 * i + 16);
  }
  *(_DWORD *)(a3 - 28) = 0;
  JUMPOUT(0x3F6305CC);
}

//------------------------------------------------------------------------------
// Address: 0x3F6305D1
// Name: __set_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _set_osfhnd()
{
  __asm { aas }
  JUMPOUT(0x3F6305BE);
}

//------------------------------------------------------------------------------
// Address: 0x3F630664
// Name: ___initmbctable_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __initmbctable_0()
{
  if ( dword_3F667114 == 0 )
  {
    ((void (__cdecl *)(int))loc_3F6304CA)(a1: -3);
    dword_3F667114 = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F630682
// Name: sub_3F630682
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F630682()
{
  return dword_3F665FBC;
}

//------------------------------------------------------------------------------
// Address: 0x3F630688
// Name: sub_3F630688
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *sub_3F630688()
{
  return &unk_3F665FC0;
}

//------------------------------------------------------------------------------
// Address: 0x3F630740
// Name: ___lock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __lock_fhandle(char a1@<ch>, int a2@<ebx>)
{
  --*(_DWORD *)(a2 + 53382);
  *(_BYTE *)a2 += a1;
  JUMPOUT(0x3F63074A);
}

//------------------------------------------------------------------------------
// Address: 0x3F6307E0
// Name: __unlock_fhandle
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _unlock_fhandle(
        int _EAX@<eax>,
        char a2@<dh>,
        int _EBX@<ebx>,
        void (__stdcall *a4)(_DWORD)@<edi>,
        int a5@<esi>)
{
  *(_BYTE *)(_EAX - 2063597568) = a2;
  *(_BYTE *)(_EBX + _EAX + 80) = 0;
  __asm { xlat }
  if ( *(_DWORD *)(a5 + 184) != 0 )
    a4(a1: *(_DWORD *)(a5 + 184));
  JUMPOUT(0x3F630801);
}

//------------------------------------------------------------------------------
// Address: 0x3F630802
// Name: __alloc_osfhnd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _alloc_osfhnd@<eax>(char _AL@<al>, int _EBX@<ebx>, int (__cdecl *a3)(int)@<edi>, _DWORD *a4@<esi>)
{
  int *v5; // ebx
  int i; // ebp

  __asm { xlat }
  if ( a4[48] != 0 )
    a3(a1: a4[48]);
  v5 = a4 + 20;
  for ( i = 6; i != 0; --i )
  {
    if ( (CUtlCharConversion::ConversionInfo_t *)*(v5 - 2) != &s_NoEscConversion.m_pReplacements[52] && *v5 != 0 )
      a3(a1: *v5);
    if ( *(v5 - 1) != 0 && v5[1] != 0 )
      a3(a1: v5[1]);
    v5 += 4;
  }
  return a3(a1: a4[53] + 180);
}

//------------------------------------------------------------------------------
// Address: 0x3F6308E0
// Name: __copytlocinfo_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_DWORD *__usercall _copytlocinfo_nolock@<eax>(_DWORD *result@<eax>, _DWORD *a2@<ecx>)
{
  if ( a2 != nullptr && result != nullptr && result != a2 )
  {
    qmemcpy(result, a2, 0xD8u);
    *result = 0;
    return (_DWORD *)((int (__cdecl *)(_DWORD *))loc_3F6307CE)(a1: result);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F630904
// Name: __updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlNoEscConversion *__usercall _updatetlocinfoEx_nolock@<eax>(
        CUtlNoEscConversion **a1@<eax>,
        CUtlNoEscConversion *a2@<edi>)
{
  CUtlNoEscConversion *v2; // esi

  if ( a2 == nullptr || a1 == nullptr )
    return nullptr;
  v2 = *a1;
  if ( *a1 != a2 )
  {
    *a1 = a2;
    ((void (__cdecl *)(CUtlNoEscConversion *))loc_3F6307CE)(a1: a2);
    if ( v2 != nullptr )
    {
      ((void (__cdecl *)(CUtlNoEscConversion *))__removelocaleref_0)(a1: v2);
      if ( v2->__vftable == nullptr && v2 != (CUtlNoEscConversion *)&s_NoEscConversion.m_pReplacements[53] )
        ((void (__cdecl *)(CUtlNoEscConversion *))__freetlocinfo_0)(a1: v2);
    }
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F6309B8
// Name: __configthreadlocale_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _configthreadlocale_0(int Flag)
{
  DWORD *v1; // eax
  DWORD v2; // ecx
  int v3; // edi
  unsigned int v5; // ecx

  v1 = _getptd_0();
  v2 = v1[28];
  v3 = ((v2 & 2) == 0) + 1;
  if ( Flag == -1 )
  {
    s_NoEscConversion.m_pReplacements[51].m_pReplacementString = (char *)-1;
  }
  else if ( Flag != 0 )
  {
    if ( Flag == 1 )
    {
      v5 = v2 | 2;
    }
    else
    {
      if ( Flag != 2 )
      {
        *_errno_0() = 22;
        _invalid_parameter_0();
        return -1;
      }
      v5 = v2 & 0xFFFFFFFD;
    }
    v1[28] = v5;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F630A1E
// Name: _sync_legacy_variables_lk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *sync_legacy_variables_lk()
{
  char *result; // eax

  dword_3F6637D8 = *(_DWORD *)(s_NoEscConversion.m_pReplacements[80].m_nLength + 4);
  dword_3F6637DC = *(_DWORD *)(s_NoEscConversion.m_pReplacements[80].m_nLength + 8);
  s_NoEscConversion.m_pReplacements[80].m_pReplacementString = *(char **)(s_NoEscConversion.m_pReplacements[80].m_nLength
                                                                        + 168);
  s_NoEscConversion.m_pReplacements[225].m_nLength = *(_DWORD *)(s_NoEscConversion.m_pReplacements[80].m_nLength + 212);
  s_NoEscConversion.m_pReplacements[232].m_nLength = *(_DWORD *)(s_NoEscConversion.m_pReplacements[80].m_nLength + 188);
  s_NoEscConversion.m_pReplacements[201].m_nLength = *(_DWORD *)(s_NoEscConversion.m_pReplacements[80].m_nLength + 200);
  result = *(char **)(s_NoEscConversion.m_pReplacements[80].m_nLength + 172);
  s_NoEscConversion.m_pReplacements[232].m_pReplacementString = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F630AB6
// Name: __write_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _write_nolock@<eax>(
        char a1@<sf>,
        char a2@<of>,
        int a3@<ebp>,
        CUtlNoEscConversion_vtbl *a4@<edi>,
        CUtlNoEscConversion **a5@<esi>)
{
  CUtlNoEscConversion *v5; // eax

  if ( a1 == a2 )
    JUMPOUT(0x3F630AB5);
  ((void (__cdecl *)(CUtlNoEscConversion *))__removelocaleref_0)(a1: *a5);
  v5 = *a5;
  if ( *a5 != (CUtlNoEscConversion *)a4
    && v5->__vftable == a4
    && v5 != (CUtlNoEscConversion *)&s_NoEscConversion.m_pReplacements[53] )
  {
    ((void (__cdecl *)(CUtlNoEscConversion *))__freetlocinfo_0)(a1: *a5);
  }
  *(_DWORD *)(a3 - 4) = -2;
  sub_3F630AFE();
  *a5 = (CUtlNoEscConversion *)-1163005939;
  a5[1] = (CUtlNoEscConversion *)-1163005939;
  return ((int (__cdecl *)(CUtlNoEscConversion **))loc_3F609ED0)(a1: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F630AFB
// Name: sub_3F630AFB
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F630AFB()
{
  return sub_3F630AFE();
}

//------------------------------------------------------------------------------
// Address: 0x3F630AFE
// Name: sub_3F630AFE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F630AFE()
{
  return _unlock_0(a1: 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F630B0C
// Name: __get_current_locale_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_locale_t __cdecl _get_current_locale_0()
{
  DWORD *v0; // edi
  localeinfo_struct *v1; // esi
  int v3; // [esp+0h] [ebp-2Ch]

  v0 = _getptd_0();
  v1 = (localeinfo_struct *)((int (__cdecl *)(int, int))loc_3F609A90)(a1: 8, a2: 1);
  if ( v1 != nullptr )
  {
    ((void (__stdcall *)(int))__updatetlocinfo_0)(a1: v3);
    ((void (*)(void))loc_3F630197)();
    v1->locinfo = (threadlocaleinfostruct *)v0[27];
    v1->mbcinfo = (threadmbcinfostruct *)v0[26];
    _lock_0(a1: 12);
    ((void (__cdecl *)(threadlocaleinfostruct *))loc_3F6307CE)(a1: v1->locinfo);
    _unlock_0(a1: 12);
    InterlockedIncrement(lpAddend: &v1->mbcinfo->refcount);
    return v1;
  }
  else
  {
    *_errno_0() = 12;
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F630B99
// Name: __strcats_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _strcats_0(int a1, int a2, int a3)
{
  int v3; // edi
  int *v4; // esi

  v3 = a3;
  if ( a3 > 0 )
  {
    v4 = &a3;
    do
    {
      if ( ((int (__cdecl *)(int, int, _DWORD))loc_3F63FDA2)(a1, a2, a3: *++v4) != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      --v3;
    }
    while ( v3 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F630BD7
// Name: ___lc_strtolc_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __lc_strtolc_0(char *a1, char *Str)
{
  char *v2; // esi
  size_t v4; // eax
  bool i; // zf
  char *v6; // edi
  char v7; // bl
  int v8; // eax
  char *v9; // eax
  int v10; // [esp-Ch] [ebp-18h]
  char *v12; // [esp-8h] [ebp-14h]
  size_t v13; // [esp-4h] [ebp-10h]
  char *Stra; // [esp+18h] [ebp+Ch]

  memset(a1, Val: 0, Size: 0x90u);
  v2 = Str;
  if ( *Str == 0 )
    return 0;
  if ( *Str == 46 && Str[1] != 0 )
  {
    if ( ((int (__cdecl *)(char *, int, char *, int))loc_3F63FE13)(a1: a1 + 128, a2: 16, a3: Str + 1, a4: 15) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    a1[143] = 0;
    return 0;
  }
  Stra = nullptr;
  v4 = strcspn_0(Str, Control: "_.,");
  for ( i = v4 == 0; !i; i = v4 == 0 )
  {
    v6 = &v2[v4];
    v7 = v2[v4];
    if ( Stra != nullptr )
    {
      if ( Stra == (char *)1 )
      {
        if ( v4 >= 0x40 || v7 == 95 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 64;
        v9 = a1 + 64;
      }
      else
      {
        if ( Stra != (char *)2 || v4 >= 0x10 || v7 != 0 && v7 != 44 )
          return -1;
        v13 = v4;
        v12 = v2;
        v10 = 16;
        v9 = a1 + 128;
      }
      v8 = ((int (__cdecl *)(char *, int, char *, size_t))loc_3F63FE13)(a1: v9, a2: v10, a3: v12, a4: v13);
    }
    else
    {
      if ( v4 >= 0x40 || v7 == 46 )
        return -1;
      v8 = ((int (__cdecl *)(char *, int, char *, size_t))loc_3F63FE13)(a1, a2: 64, a3: v2, a4: v4);
    }
    if ( v8 != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    if ( v7 == 44 || v7 == 0 )
      return 0;
    ++Stra;
    v2 = v6 + 1;
    v4 = strcspn_0(Str: v6 + 1, Control: "_.,");
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F630D00
// Name: ___lc_lctostr_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __lc_lctostr_0(char *Destination, rsize_t SizeInBytes, char *Source)
{
  if ( strcpy_s_0(Destination, SizeInBytes, Source) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  if ( Source[64] != 0 )
    _strcats_0(a1: (int)Destination, a2: SizeInBytes, a3: 2);
  if ( Source[128] != 0 )
    _strcats_0(a1: (int)Destination, a2: SizeInBytes, a3: 2);
}

//------------------------------------------------------------------------------
// Address: 0x3F630D6B
// Name: __setlocale_get_all
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _setlocale_get_all@<eax>(int a1@<esi>)
{
  int result; // eax
  int v2; // edi
  int v3; // ebp
  const char **v4; // ebx
  char **v5; // [esp+4h] [ebp-10h]
  int v6; // [esp+8h] [ebp-Ch]
  int v7; // [esp+Ch] [ebp-8h]
  int v8; // [esp+10h] [ebp-4h]

  v7 = 1;
  result = ((int (__cdecl *)(int))loc_3F609A30)(a1: 853);
  v8 = result;
  if ( result != 0 )
  {
    v2 = result + 4;
    *(_BYTE *)(result + 4) = 0;
    *(_DWORD *)result = 1;
    v3 = a1 + 16;
    v6 = 1;
    v4 = (const char **)(a1 + 88);
    _strcats_0(a1: result + 4, a2: 849, a3: 3);
    v5 = &off_3F6545A4;
    do
    {
      if ( ((int (__cdecl *)(int, int, const char *))loc_3F63FDA2)(a1: v2, a2: 849, a3: ";") != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      if ( strcmp_0(Str1: *v4, Str2: *(const char **)(v3 + 88)) != 0 )
        v7 = 0;
      ++v6;
      v5 += 3;
      v3 = 16 * v6 + a1;
      v4 = (const char **)(v3 + 72);
      _strcats_0(a1: v2, a2: 849, a3: 3);
    }
    while ( (int)v5 < (int)&off_3F6545D4 );
    if ( v7 != 0 )
    {
      ((void (__cdecl *)(int))loc_3F609ED0)(a1: v8);
      if ( *(_DWORD *)(a1 + 80) != 0 && InterlockedDecrement(lpAddend: *(volatile LONG **)(a1 + 80)) == 0 )
        ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a1 + 80));
      if ( *(_DWORD *)(a1 + 84) != 0 && InterlockedDecrement(lpAddend: *(volatile LONG **)(a1 + 84)) == 0 )
        ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a1 + 84));
      result = *(_DWORD *)(a1 + 104);
      *(_DWORD *)(a1 + 80) = 0;
      *(_DWORD *)(a1 + 72) = 0;
    }
    else
    {
      if ( *(_DWORD *)(a1 + 80) != 0 && InterlockedDecrement(lpAddend: *(volatile LONG **)(a1 + 80)) == 0 )
        ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a1 + 80));
      if ( *(_DWORD *)(a1 + 84) != 0 && InterlockedDecrement(lpAddend: *(volatile LONG **)(a1 + 84)) == 0 )
        ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a1 + 84));
      *(_DWORD *)(a1 + 80) = v8;
      *(_DWORD *)(a1 + 72) = v2;
      result = v2;
    }
    *(_DWORD *)(a1 + 76) = 0;
    *(_DWORD *)(a1 + 84) = 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63107C
// Name: __write
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _write(char a1@<zf>, int a2@<ebp>, const wchar_t *a3@<esi>)
{
  char *r; // [esp+4h] [ebp-1Ch]
  rsize_t v4; // [esp+8h] [ebp-18h]
  const char *v5; // [esp+Ch] [ebp-14h]

  if ( !a1 )
    JUMPOUT(0x3F631044);
  if ( strcpy_s_0(Destination: r, SizeInBytes: v4, Source: v5) != 0 )
    _invoke_watson_0(Expression: a3, FunctionName: a3, FileName: a3, LineNo: (unsigned int)a3, Reserved: (uintptr_t)a3);
  __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 + 92));
}

//------------------------------------------------------------------------------
// Address: 0x3F6310B0
// Name: __setlocale_set_cat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _setlocale_set_cat(int a1@<ecx>, int a2@<esi>, int a3)
{
  _BYTE v4[24]; // [esp+1Ch] [ebp-13Ch] BYREF
  _BYTE v5[8]; // [esp+34h] [ebp-124h] BYREF
  int v6; // [esp+3Ch] [ebp-11Ch]
  size_t v7; // [esp+40h] [ebp-118h]
  char Str[132]; // [esp+144h] [ebp-14h] BYREF

  _getptd_0();
  if ( ((int (__cdecl *)(int, char *, int, _BYTE *, _BYTE *, int))_expandlocale_0)(
         a1,
         a2: Str,
         a3: 131,
         a4: v4,
         a5: v5,
         a6: a3) != 0 )
  {
    if ( strcmp_0(Str1: Str, Str2: *(const char **)(16 * a3 + a2 + 72)) == 0 )
      JUMPOUT(0x3F631392);
    v7 = strlen_0(Str) + 5;
    v6 = ((int (__cdecl *)(size_t))loc_3F609A30)(a1: v7);
    if ( v6 != 0 )
      JUMPOUT(0x3F63114D);
  }
  JUMPOUT(0x3F631395);
}

//------------------------------------------------------------------------------
// Address: 0x3F631158
// Name: __commit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _commit@<eax>(
        _DWORD *a1@<eax>,
        int a2@<ecx>,
        int a3@<ebx>,
        int *a4@<edi>,
        _DWORD *a5@<esi>,
        int filedes)
{
  int v6; // ecx
  _DWORD *v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // edx
  int v12; // [esp+1Ch] [ebp-4h]

  *a5 = __ROL4__(*a5, 107);
  *(_DWORD *)(v12 - 288) = a1;
  *(_DWORD *)(v12 - 308) = *a1;
  *(_DWORD *)(v12 - 296) = (char *)a5 + a2;
  memcpy_1(a1: (void *)(v12 - 336), Src: (char *)a5 + a2, Size: 6u);
  v6 = *(_DWORD *)(v12 - 280);
  *(_DWORD *)(v12 - 320) = a5[1];
  if ( strcpy_s_0(
         Destination: (char *)(*(_DWORD *)(v12 - 284) + 4),
         SizeInBytes: v6 - 4,
         Source: (const char *)(v12 - 20)) != 0 )
    _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
  v7 = *(_DWORD **)(v12 - 288);
  *(_DWORD *)(a3 + 72) = *(_DWORD *)(v12 - 284) + 4;
  *v7 = *(unsigned __int16 *)(v12 - 316);
  memcpy_1(a1: *(void **)(v12 - 296), Src: (const void *)(v12 - 316), Size: 6u);
  if ( *(_DWORD *)(v12 + 124) != 2 )
    JUMPOUT(0x3F6312EF);
  v8 = *(_DWORD *)(v12 - 292);
  *(_DWORD *)(v12 - 280) = 0;
  a5[1] = v8;
  v9 = a4[8];
  *(_DWORD *)(v12 - 296) = a4[9];
  if ( a5[1] == *a4 )
    JUMPOUT(0x3F631256);
  v10 = *a4;
  ++*(_DWORD *)(v12 - 280);
  *a4 = v9;
  *(_DWORD *)(v12 - 328) = v10;
  return _isatty(fh: filedes);
}

//------------------------------------------------------------------------------
// Address: 0x3F631239
// Name: __isatty
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F631297
// Name: __wctomb_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _wctomb_s_l(_DWORD *a1@<ebx>, int a2@<ebp>, _DWORD *a3@<edi>, _DWORD *a4@<esi>)
{
  unsigned int i; // eax
  volatile LONG **v5; // edi
  _DWORD *v6; // eax
  int v7; // ecx
  int _loc_update; // [esp+68h] [ebp-10h]

  if ( ((int (__cdecl *)(_DWORD, int))loc_3F63DC9D)(a1: 0, a2: 1) != 0 )
  {
    for ( i = 0; i < 0x7F; ++i )
      *(_WORD *)(a2 + 2 * i - 276) &= 0x1FFu;
    a3[1] = ((int (__cdecl *)(int, int, int))loc_3F641F44)(
              a1: a2 - 276,
              a2: s_NoEscConversion.m_pReplacements[51].m_nLength,
              a3: 254) == 0;
  }
  else
  {
    a3[1] = 0;
  }
  *a3 = a4[1];
  a4[42] = a3[1];
  if ( *(_DWORD *)(a2 + 124) == 1 )
    a4[2] = *(_DWORD *)(a2 - 292);
  if ( (*(&off_3F6545A0 + 3 * *(_DWORD *)(a2 + 124)))() != 0 )
  {
    _loc_update = *(_DWORD *)(a2 - 284);
    a1[18] = *(_DWORD *)(a2 - 304);
    ((void (__cdecl *)(int))loc_3F609ED0)(a1: _loc_update);
    **(_DWORD **)(a2 - 288) = *(_DWORD *)(a2 - 308);
    a4[1] = *(_DWORD *)(a2 - 320);
  }
  else
  {
    if ( *(CUtlNoEscConversion **)(a2 - 304) != (CUtlNoEscConversion *)&s_NoEscConversion.m_pReplacements[52] )
    {
      v5 = (volatile LONG **)&a4[4 * *(_DWORD *)(a2 + 124) + 20];
      if ( InterlockedDecrement(lpAddend: *v5) == 0 )
      {
        ((void (__cdecl *)(volatile LONG *))loc_3F609ED0)(a1: *v5);
        ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[21]);
        a1[19] = 0;
      }
    }
    v6 = *(_DWORD **)(a2 - 284);
    v7 = 4 * (*(_DWORD *)(a2 + 124) + 5);
    *v6 = 1;
    a4[v7] = v6;
  }
  __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 + 112));
}

//------------------------------------------------------------------------------
// Address: 0x3F6313F6
// Name: _wctomb_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void wctomb_s()
{
  __asm { arpl    [ecx], ax }
  JUMPOUT(0x3F6313F8);
}

//------------------------------------------------------------------------------
// Address: 0x3F631411
// Name: __wctomb_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _wctomb_l(char a1@<zf>, const char *a2@<ecx>, int a3@<ebp>)
{
  char *v4; // eax
  char *v5; // ebx
  int v6; // eax

  if ( a1 )
  {
    v4 = strpbrk_0(Str: a2, Control: "=;");
    v5 = v4;
    if ( v4 != nullptr )
    {
      v6 = v4 - a2;
      *(_DWORD *)(a3 - 28) = v6;
      if ( v6 != 0 && *v5 != 59 )
      {
        *(_DWORD *)(a3 - 32) = 1;
        ((void (__cdecl *)(const char *, const char *, int))loc_3F6435C4)(a1: "LC_COLLATE", a2, a3: v6);
        JUMPOUT(0x3F63145E);
      }
    }
    JUMPOUT(0x3F6314FD);
  }
  JUMPOUT(0x3F631501);
}

//------------------------------------------------------------------------------
// Address: 0x3F631460
// Name: _wctomb
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall wctomb(int a1@<ebx>, int a2@<ebp>, int a3@<esi>)
{
  char v3; // di
  _iobuf *v4; // ecx
  const char *retval; // [esp+0h] [ebp-4h]

  *(_BYTE *)(a2 + 13) = 0;
  if ( *(_DWORD *)(a2 - 28) != strlen_0(Str: retval) )
  {
    ++*(_DWORD *)(a2 - 32);
    if ( a3 + 12 <= (int)&off_3F6545D4 )
      JUMPOUT(0x3F631452);
  }
  v3 = strcspn_0(Str: (const char *)(a1 + 1), Control: ";");
  write_char_0(ch: v3, f: v4, pnumwritten: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F631490
// Name: write_char_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall write_char_0(const wchar_t *pnumwritten@<esi>, _BYTE *a2@<ebx>, int a3@<ebp>, int *a4@<edi>)
{
  if ( a4 != (int *)pnumwritten || *a2 == 59 )
  {
    if ( *(int *)(a3 - 32) <= 5 )
    {
      if ( ((int (__cdecl *)(int, int, _BYTE *, int *))loc_3F63FE13)(a1: a3 - 20, a2: 131, a3: a2, a4) != 0 )
        _invoke_watson_0(
          Expression: pnumwritten,
          FunctionName: pnumwritten,
          FileName: pnumwritten,
          LineNo: (unsigned int)pnumwritten,
          Reserved: (uintptr_t)pnumwritten);
      JUMPOUT(0x3F6314C5);
    }
    JUMPOUT(0x3F6314E0);
  }
  JUMPOUT(0x3F6314FD);
}

//------------------------------------------------------------------------------
// Address: 0x3F6314C3
// Name: write_multi_char_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall write_multi_char_0(
        char a1@<zf>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        _iobuf *ch,
        const char *num,
        localeinfo_struct *f,
        char *fa)
{
  int v9; // esi
  int v10; // eax
  int v11; // [esp-4h] [ebp-4h]

  if ( !a1 )
    JUMPOUT(0x3F6314A8);
  v9 = *(_DWORD *)(a3 - 36);
  *(_BYTE *)(a3 + a4 - 20) = 0;
  _setlocale_set_cat(a1: a3 - 20, a2: v9, a3: v11);
  if ( v10 != 0 )
    ++*(_DWORD *)(a3 - 24);
  if ( *(_BYTE *)(a2 + a4) == 0 )
    JUMPOUT(0x3F6314F1);
  _output_s_l(stream: ch, format: num, plocinfo: f, argptr: fa);
}

//------------------------------------------------------------------------------
// Address: 0x3F6314E7
// Name: __output_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _output_s_l(int a1@<ebp>, int a2@<edi>)
{
  if ( *(_BYTE *)(a2 + 1) != 0 )
    JUMPOUT(0x3F631419);
  if ( *(_DWORD *)(a1 - 24) != 0 )
    _setlocale_get_all(a1: *(_DWORD *)(a1 - 36));
  __security_check_cookie`...'(StackCookie: a1 ^ *(_DWORD *)(a1 + 112));
}

//------------------------------------------------------------------------------
// Address: 0x3F631574
// Name: __create_locale_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_locale_t __cdecl _create_locale_0(int Category, const char *Locale)
{
  localeinfo_struct *v2; // esi
  int v4; // eax
  int v5; // eax

  if ( (unsigned int)Category > 5 || Locale == nullptr )
    return nullptr;
  v2 = (localeinfo_struct *)((int (__cdecl *)(int, int))loc_3F609A90)(a1: 8, a2: 1);
  if ( v2 == nullptr )
  {
LABEL_4:
    *_errno_0() = 12;
    return nullptr;
  }
  v4 = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 216, a2: 1);
  v2->locinfo = (threadlocaleinfostruct *)v4;
  if ( v4 == 0 )
  {
    ((void (__cdecl *)(localeinfo_struct *))loc_3F609ED0)(a1: v2);
    goto LABEL_4;
  }
  v5 = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 544, a2: 1);
  v2->mbcinfo = (threadmbcinfostruct *)v5;
  if ( v5 == 0 )
  {
    ((void (__cdecl *)(threadlocaleinfostruct *))loc_3F609ED0)(a1: v2->locinfo);
    ((void (__cdecl *)(localeinfo_struct *))loc_3F609ED0)(a1: v2);
    goto LABEL_4;
  }
  _copytlocinfo_nolock(result: &v2->locinfo->refcount, a2: &s_NoEscConversion.m_pReplacements[53].m_nLength);
  if ( ((int (__cdecl *)(int))loc_3F6313A6)(a1: Category) != 0 )
  {
    if ( ((int (__cdecl *)(unsigned int, threadmbcinfostruct *))loc_3F6302B5)(
           a1: v2->locinfo->lc_codepage,
           a2: v2->mbcinfo) == 0 )
    {
      v2->mbcinfo->refcount = 1;
      v2->mbcinfo->refcount = 1;
      return v2;
    }
    ((void (__cdecl *)(threadmbcinfostruct *))loc_3F609ED0)(a1: v2->mbcinfo);
    ((void (__cdecl *)(threadlocaleinfostruct *))__removelocaleref_0)(a1: v2->locinfo);
    ((void (__cdecl *)(threadlocaleinfostruct *))__freetlocinfo_0)(a1: v2->locinfo);
    ((void (__cdecl *)(localeinfo_struct *))loc_3F609ED0)(a1: v2);
  }
  else
  {
    ((void (__cdecl *)(threadlocaleinfostruct *))__removelocaleref_0)(a1: v2->locinfo);
    ((void (__cdecl *)(threadlocaleinfostruct *))__freetlocinfo_0)(a1: v2->locinfo);
    ((void (__cdecl *)(localeinfo_struct *))loc_3F609ED0)(a1: v2);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x3F63179A
// Name: sub_3F63179A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F63179A()
{
  return _unlock_0(a1: 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F6317A3
// Name: sub_3F6317A3
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F6317A3()
{
  return _unlock_0(a1: 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F6317D4
// Name: sub_3F6317D4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F6317D4()
{
  return sub_3F6317D7();
}

//------------------------------------------------------------------------------
// Address: 0x3F6317D7
// Name: sub_3F6317D7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F6317D7(int a1@<esi>)
{
  *(_DWORD *)(a1 + 112) &= ~0x10u;
}

//------------------------------------------------------------------------------
// Address: 0x3F6317DC
// Name: __isctype_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_l_0(int C, int Type, _locale_t Locale)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate v7; // [esp+4h] [ebp-18h] BYREF
  char v8; // [esp+14h] [ebp-8h] BYREF
  char v9; // [esp+15h] [ebp-7h]
  char v10; // [esp+16h] [ebp-6h]
  unsigned __int16 v11; // [esp+18h] [ebp-4h] BYREF
  int Ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &v7, a2: Locale);
  v3 = C;
  if ( (unsigned int)(C + 1) <= 0x100 )
  {
    v4 = v7.localeinfo.locinfo->pctype[C];
    goto LABEL_11;
  }
  Ca = C >> 8;
  if ( ((int (__cdecl *)(_DWORD, _LocaleUpdate *))loc_3F62AC25)(a1: HIBYTE(v3), a2: &v7) != 0 )
  {
    v8 = Ca;
    v9 = v3;
    v10 = 0;
    v5 = 2;
  }
  else
  {
    v8 = v3;
    v9 = 0;
    v5 = 1;
  }
  if ( ((int (__cdecl *)(_LocaleUpdate *, int, char *, int, unsigned __int16 *, unsigned int, unsigned int, int))loc_3F63DC9D)(
         a1: &v7,
         a2: 1,
         a3: &v8,
         a4: v5,
         a5: &v11,
         a6: v7.localeinfo.locinfo->lc_codepage,
         a7: v7.localeinfo.locinfo->lc_handle[2],
         a8: 1) != 0 )
  {
    v4 = v11;
LABEL_11:
    result = Type & v4;
    if ( v7.updated )
      v7.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( v7.updated )
    v7.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F631892
// Name: __isctype_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_0(int C, int Type)
{
  if ( dword_3F6637BC != 0 )
    return _isctype_l_0(C, Type, Locale: nullptr);
  else
    return (unsigned __int16)Type & *(_WORD *)(s_NoEscConversion.m_pReplacements[78].m_nLength + 2 * C);
}

//------------------------------------------------------------------------------
// Address: 0x3F6318C1
// Name: __fltin2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _fltin2_0(int *a1, int a2, int a3, int a4, int a5, int a6)
{
  int v6; // ebx
  int v7; // eax
  int v9; // [esp+Ch] [ebp-24h] BYREF
  int v10; // [esp+10h] [ebp-20h]
  int v11; // [esp+14h] [ebp-1Ch] BYREF
  int v12; // [esp+18h] [ebp-18h]
  int v13; // [esp+1Ch] [ebp-14h]
  _BYTE v14[12]; // [esp+20h] [ebp-10h] BYREF

  v10 = a2;
  v6 = 0;
  v13 = ((int (__cdecl *)(_BYTE *, int *, int, _DWORD, _DWORD, _DWORD, _DWORD, int))__strgtold12_l_0)(
          a1: v14,
          a2: &v9,
          a3: a2,
          a4: 0,
          a5: 0,
          a6: 0,
          a7: 0,
          a8: a6);
  if ( (v13 & 4) != 0 )
  {
    v6 = 512;
    v11 = 0;
    v12 = 0;
  }
  else
  {
    v7 = ((int (__cdecl *)(_BYTE *, int *))loc_3F643E20)(a1: v14, a2: &v11);
    if ( (v13 & 2) != 0 || v7 == 1 )
      v6 = 128;
    if ( (v13 & 1) != 0 || v7 == 2 )
      v6 |= 0x100u;
  }
  a1[1] = v9 - v10;
  a1[4] = v11;
  a1[5] = v12;
  *a1 = v6;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F631970
// Name: _strlen_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl strlen_0(const char *Str)
{
  const char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = Str;
  if ( ((unsigned __int8)Str & 3) == 0 )
    goto main_loop_4;
  do
  {
    v2 = *v1++;
    if ( v2 == 0 )
      return v1 - 1 - Str;
  }
  while ( ((unsigned __int8)v1 & 3) != 0 );
  while ( 1 )
  {
    do
    {
main_loop_4:
      v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
      v1 += 4;
    }
    while ( (v3 & 0x81010100) == 0 );
    v4 = *((_DWORD *)v1 - 1);
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) == 0 )
      return v1 - 3 - Str;
    if ( (v4 & 0xFF0000) == 0 )
      return v1 - 2 - Str;
    if ( (v4 & 0xFF000000) == 0 )
      return v1 - 1 - Str;
  }
  return v1 - 4 - Str;
}

//------------------------------------------------------------------------------
// Address: 0x3F6319FB
// Name: nullsub_39
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_39()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F631A5C
// Name: sub_3F631A5C
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F631A5C(int a1)
{
  int result; // eax

  result = dword_3F6637E0;
  dword_3F6637E0 = a1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F631D7A
// Name: ___multtenpow12_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F631E97
// Name: __validate_param_reuseA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _validate_param_reuseA(int a1@<eax>, _DWORD *a2@<ecx>, int a3@<ebx>, int a4@<ebp>, int a5@<edi>)
{
  int v5; // esi
  _WORD *v6; // ebx
  int v7; // edi
  int v8; // edx
  unsigned int v9; // edi
  unsigned int v10; // edx
  unsigned int v11; // esi
  bool v12; // zf
  unsigned int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // esi
  int v16; // edi
  int v17; // edx
  bool v18; // cc
  int v19; // ebx
  unsigned int v20; // edx
  unsigned int v21; // edi
  unsigned int v22; // esi
  int v23; // edi
  int v24; // edx
  int v25; // [esp-4h] [ebp-4h]

  *a2 |= a5;
  v5 = v25;
  LOBYTE(a1) = a1 - 82;
  if ( (_BYTE)a1 != 0 )
  {
    *(_DWORD *)(a4 - 56) = a3;
    v6 = (_WORD *)(a4 - 12);
    *(_DWORD *)(a4 - 36) = 5;
    while ( 1 )
    {
      v7 = *(_DWORD *)(a4 - 36);
      v8 = 2 * *(_DWORD *)(a4 - 56);
      *(_DWORD *)(a4 - 44) = v7;
      if ( v7 > 0 )
      {
        *(_DWORD *)(a4 - 64) = v5 + 8;
        *(_DWORD *)(a4 - 60) = a1 + v8;
        do
        {
          v9 = *((_DWORD *)v6 - 1);
          v10 = **(unsigned __int16 **)(a4 - 64) * **(unsigned __int16 **)(a4 - 60);
          *(_DWORD *)(a4 - 68) = 0;
          v11 = v9 + v10;
          if ( v9 + v10 < v9 || v11 < v10 )
            *(_DWORD *)(a4 - 68) = 1;
          v12 = *(_DWORD *)(a4 - 68) == 0;
          *((_DWORD *)v6 - 1) = v11;
          if ( !v12 )
            ++*v6;
          *(_DWORD *)(a4 - 60) += 2;
          *(_DWORD *)(a4 - 64) -= 2;
          --*(_DWORD *)(a4 - 44);
        }
        while ( *(int *)(a4 - 44) > 0 );
        v5 = *(_DWORD *)(a4 - 52);
      }
      ++v6;
      ++*(_DWORD *)(a4 - 56);
      if ( (int)--*(_DWORD *)(a4 - 36) <= 0 )
      {
        *(_DWORD *)(a4 - 32) += 49154;
        if ( *(__int16 *)(a4 - 32) <= 0 )
          goto LABEL_28;
        do
        {
          if ( *(int *)(a4 - 8) < 0 )
            break;
          v13 = *(_DWORD *)(a4 - 12);
          v14 = *(_DWORD *)(a4 - 16);
          *(_DWORD *)(a4 - 32) += 0xFFFF;
          *(_DWORD *)(a4 - 16) *= 2;
          v15 = v13;
          v16 = (v14 >> 31) | (2 * v13);
          v17 = (v15 >> 31) | (2 * *(_DWORD *)(a4 - 8));
          v18 = *(_WORD *)(a4 - 32) <= 0;
          *(_DWORD *)(a4 - 12) = v16;
          *(_DWORD *)(a4 - 8) = v17;
        }
        while ( !v18 );
        if ( *(__int16 *)(a4 - 32) <= 0 )
        {
LABEL_28:
          *(_DWORD *)(a4 - 32) += 0xFFFF;
          if ( *(__int16 *)(a4 - 32) < 0 )
          {
            v19 = (unsigned __int16)-*(_WORD *)(a4 - 32);
            *(_DWORD *)(a4 - 32) += v19;
            do
            {
              if ( (*(_BYTE *)(a4 - 16) & 1) != 0 )
                ++*(_DWORD *)(a4 - 48);
              v20 = *(_DWORD *)(a4 - 8);
              v21 = *(_DWORD *)(a4 - 12);
              v22 = v21;
              *(_DWORD *)(a4 - 8) = v20 >> 1;
              v23 = (v20 << 31) | (v21 >> 1);
              v24 = (v22 << 31) | (*(_DWORD *)(a4 - 16) >> 1);
              --v19;
              *(_DWORD *)(a4 - 12) = v23;
              *(_DWORD *)(a4 - 16) = v24;
            }
            while ( v19 != 0 );
            if ( *(_DWORD *)(a4 - 48) != 0 )
              *(_WORD *)(a4 - 16) |= 1u;
          }
        }
        JUMPOUT(0x3F631FBE);
      }
    }
  }
  JUMPOUT(0x3F631E5A);
}

//------------------------------------------------------------------------------
// Address: 0x3F631FC0
// Name: __output_p_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _output_p_l(char a1@<sf>, char a2@<of>, int a3@<eax>, int _EDX@<edx>, __int16 a5@<cx>, int a6@<ebp>)
{
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // esi
  bool v10; // cf
  __int16 v11; // di
  __int16 v12; // dx
  __int16 v13; // cx
  unsigned __int16 v14; // dx
  unsigned __int16 v15; // di
  int v16; // ebx
  __int16 v17; // cx
  int v19; // edx

  if ( a1 == a2 )
    JUMPOUT(0x3F631FB2);
  *(_BYTE *)(a3 + 1435177335) += a3;
  __asm { lock and edx, 1FFFFh }
  if ( _EDX == 98304 )
  {
    if ( *(_DWORD *)(a6 - 14) == -1 )
    {
      *(_DWORD *)(a6 - 14) = 0;
      if ( *(_DWORD *)(a6 - 10) == -1 )
      {
        *(_DWORD *)(a6 - 10) = 0;
        if ( *(_WORD *)(a6 - 6) == 0xFFFF )
        {
          ++*(_DWORD *)(a6 - 32);
          *(_WORD *)(a6 - 6) = 0x8000;
        }
        else
        {
          ++*(_WORD *)(a6 - 6);
        }
      }
      else
      {
        ++*(_DWORD *)(a6 - 10);
      }
    }
    else
    {
      ++*(_DWORD *)(a6 - 14);
    }
  }
  v19 = *(_DWORD *)(a6 - 32);
  if ( (unsigned __int16)v19 < 0x7FFFu )
  {
    *(_WORD *)a3 = *(_WORD *)(a6 - 14);
    *(_DWORD *)(a3 + 2) = *(_DWORD *)(a6 - 12);
    *(_DWORD *)(a3 + 6) = *(_DWORD *)(a6 - 8);
    *(_WORD *)(a3 + 10) = a5 | v19;
  }
  else
  {
    *(_DWORD *)(a3 + 4) = 0;
    *(_DWORD *)a3 = 0;
    *(_DWORD *)(a3 + 8) = a5 != 0 ? -32768 : 2147450880;
  }
  while ( *(_DWORD *)(a6 + 12) != 0 )
  {
    v6 = *(_DWORD *)(a6 + 12);
    *(_DWORD *)(a6 - 40) += 84;
    *(int *)(a6 + 12) >>= 3;
    v7 = v6 & 7;
    if ( v7 != 0 )
    {
      v8 = *(_DWORD *)(a6 - 40) + 12 * v7;
      v9 = v8;
      v10 = *(_WORD *)v8 < 0x8000u;
      *(_DWORD *)(a6 - 52) = v8;
      if ( !v10 )
      {
        *(_DWORD *)(a6 - 28) = *(_DWORD *)v8;
        *(_DWORD *)(a6 - 28 + 4) = *(_DWORD *)(v8 + 4);
        *(_DWORD *)(a6 - 28 + 8) = *(_DWORD *)(v8 + 8);
        --*(_DWORD *)(a6 - 26);
        *(_DWORD *)(a6 - 52) = a6 - 28;
        v9 = a6 - 28;
      }
      v11 = *(_WORD *)(v9 + 10);
      v12 = *(_WORD *)(a3 + 10);
      *(_DWORD *)(a6 - 48) = 0;
      *(_DWORD *)(a6 - 16) = 0;
      *(_DWORD *)(a6 - 12) = 0;
      *(_DWORD *)(a6 - 8) = 0;
      v13 = v12 ^ v11;
      v14 = v12 & 0x7FFF;
      v15 = v11 & 0x7FFF;
      v16 = (unsigned __int16)(v15 + v14);
      v17 = v13 & 0x8000;
      *(_DWORD *)(a6 - 32) = v16;
      if ( v14 >= 0x7FFFu || v15 >= 0x7FFFu || (unsigned __int16)v16 > 0xBFFDu )
      {
        *(_DWORD *)(a3 + 8) = v17 != 0 ? -32768 : 2147450880;
        goto LABEL_15;
      }
      if ( (unsigned __int16)v16 > 0x3FBFu )
      {
        if ( v14 != 0
          || (++*(_DWORD *)(a6 - 32), (*(_DWORD *)(a3 + 8) & 0x7FFFFFFF) != 0)
          || *(_DWORD *)(a3 + 4) != 0
          || *(_DWORD *)a3 != 0 )
        {
          if ( v15 == 0 )
          {
            ++*(_DWORD *)(a6 - 32);
            JUMPOUT(0x3F631E96);
          }
          JUMPOUT(0x3F631EA1);
        }
        *(_WORD *)(a3 + 10) = 0;
      }
      else
      {
        *(_DWORD *)(a3 + 8) = 0;
LABEL_15:
        *(_DWORD *)(a3 + 4) = 0;
        *(_DWORD *)a3 = 0;
      }
    }
  }
  __security_check_cookie`...'(StackCookie: a6 ^ *(_DWORD *)(a6 - 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F63226B
// Name: $LN259
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __fastcall _LN259(int a1, int a2)
{
  return *(_BYTE *)(a2 + 58) - 118;
}

//------------------------------------------------------------------------------
// Address: 0x3F632743
// Name: sub_3F632743
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F632743(int a1, int a2, int a3, int a4, int a5)
{
  int v5; // edi
  unsigned __int16 v7[6]; // [esp+8h] [ebp-10h] BYREF

  v5 = ((int (__cdecl *)(unsigned __int16 *, int, int, int, _DWORD, _DWORD, _DWORD, int))__strgtold12_l_0)(
         a1: v7,
         a2,
         a3,
         a4,
         a5: 0,
         a6: 0,
         a7: 0,
         a8: a5);
  if ( _ld12told_0(a1: v7, a2: a1) == 1 )
    return v5 | 2;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F632A61
// Name: ___unDNameHelper_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __unDNameHelper_0(int a1, int a2, int a3, int a4)
{
  if ( (_WORD)a4 == 0 )
    a4 = 10240;
  return ((int (__cdecl *)(int, int, int, void *, void *, int))((char *)&DOUBLE_N2_0 + 6))(
           a1,
           a2,
           a3,
           a4: &loc_3F609A30,
           a5: &loc_3F609ED0,
           a6: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F632BD0
// Name: _strcmp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcmp_0(const char *Str1, const char *Str2)
{
  const char *v2; // edx
  const char *v3; // ecx
  unsigned int v4; // eax
  bool v5; // cf
  unsigned int v6; // eax
  __int16 v8; // ax

  v2 = Str1;
  v3 = Str2;
  if ( ((unsigned __int8)Str1 & 3) == 0 )
  {
dodwords:
    while ( 1 )
    {
      v4 = *(_DWORD *)v2;
      v5 = (unsigned __int8)*(_DWORD *)v2 < (unsigned int)*v3;
      if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
        break;
      if ( (_BYTE)v4 == 0 )
        return 0;
      v5 = BYTE1(v4) < (unsigned int)v3[1];
      if ( BYTE1(v4) != v3[1] )
        break;
      if ( BYTE1(v4) == 0 )
        return 0;
      v6 = HIWORD(v4);
      v5 = (unsigned __int8)v6 < (unsigned int)v3[2];
      if ( (_BYTE)v6 != v3[2] )
        break;
      if ( (_BYTE)v6 == 0 )
        return 0;
      v5 = BYTE1(v6) < (unsigned int)v3[3];
      if ( BYTE1(v6) != v3[3] )
        break;
      v3 += 4;
      v2 += 4;
      if ( BYTE1(v6) == 0 )
        return 0;
    }
    return -2 * v5 + 1;
  }
  if ( ((unsigned __int8)Str1 & 1) != 0 )
  {
    v2 = Str1 + 1;
    v5 = *Str1 < (unsigned int)*Str2;
    if ( *Str1 != *Str2 )
      return -2 * v5 + 1;
    v3 = Str2 + 1;
    if ( *Str1 == 0 )
      return 0;
    if ( ((unsigned __int8)v2 & 2) == 0 )
      goto dodwords;
  }
  v8 = *(_WORD *)v2;
  v2 += 2;
  v5 = (unsigned __int8)v8 < (unsigned int)*v3;
  if ( (_BYTE)v8 != *v3 )
    return -2 * v5 + 1;
  if ( (_BYTE)v8 == 0 )
    return 0;
  v5 = HIBYTE(v8) < (unsigned int)v3[1];
  if ( HIBYTE(v8) == v3[1] )
  {
    if ( HIBYTE(v8) != 0 )
    {
      v3 += 2;
      goto dodwords;
    }
    return 0;
  }
  return -2 * v5 + 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F632C58
// Name: _abort_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort_0()
{
  int v0; // esi
  int v1; // eax
  int v2; // edx
  int v3; // ecx
  unsigned int v4; // kr00_4
  int v5; // [esp-4h] [ebp-88h]
  _DWORD v6[20]; // [esp+4h] [ebp-80h] BYREF
  struct _EXCEPTION_POINTERS ExceptionInfo; // [esp+54h] [ebp-30h] BYREF
  int v8; // [esp+5Ch] [ebp-28h] BYREF
  __int16 v9; // [esp+E8h] [ebp+64h]
  __int16 v10; // [esp+ECh] [ebp+68h]
  __int16 v11; // [esp+F0h] [ebp+6Ch]
  __int16 v12; // [esp+F4h] [ebp+70h]
  int v13; // [esp+FCh] [ebp+78h]
  int v14; // [esp+104h] [ebp+80h]
  int v15; // [esp+108h] [ebp+84h]
  int v16; // [esp+10Ch] [ebp+88h]
  int v17; // [esp+110h] [ebp+8Ch]
  void *v18; // [esp+114h] [ebp+90h]
  __int16 v19; // [esp+118h] [ebp+94h]
  unsigned int v20; // [esp+11Ch] [ebp+98h]
  void **v21; // [esp+120h] [ebp+9Ch]
  __int16 v22; // [esp+124h] [ebp+A0h]
  int savedregs; // [esp+32Ch] [ebp+2A8h]
  void *retaddr; // [esp+330h] [ebp+2ACh] BYREF

  if ( (s_NoEscConversion.m_pReplacements[84].m_nLength & 1) != 0 )
    _NMSG_WRITE_0(a1: 10);
  v1 = ((int (*)(void))loc_3F639CF7)();
  if ( v1 != 0 )
  {
    v1 = ((int (__cdecl *)(int))loc_3F639F53)(a1: 22);
    v3 = v5;
  }
  if ( (s_NoEscConversion.m_pReplacements[84].m_nLength & 2) != 0 )
  {
    v16 = v1;
    v15 = v3;
    v14 = v2;
    v13 = v0;
    v22 = __SS__;
    v19 = __CS__;
    v12 = __DS__;
    v11 = __ES__;
    v10 = __FS__;
    v9 = __GS__;
    v4 = __readeflags();
    v20 = v4;
    v21 = &retaddr;
    v8 = 65537;
    v18 = retaddr;
    v17 = savedregs;
    memset(a1: v6, Val: 0, Size: sizeof(v6));
    ExceptionInfo.ExceptionRecord = (_EXCEPTION_RECORD *)v6;
    v6[0] = 1073741845;
    v6[3] = retaddr;
    ExceptionInfo.ContextRecord = (_CONTEXT *)&v8;
    SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
    UnhandledExceptionFilter(&ExceptionInfo);
  }
  _exit_0(Code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x3F632D4B
// Name: __set_abort_behavior_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior_0(unsigned int Flags, unsigned int Mask)
{
  unsigned int result; // eax

  result = s_NoEscConversion.m_pReplacements[84].m_nLength;
  s_NoEscConversion.m_pReplacements[84].m_nLength = Mask & Flags
                                                  | s_NoEscConversion.m_pReplacements[84].m_nLength & ~Mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F632D69
// Name: __NMSG_WRITE_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE_0(int a1)
{
  unsigned int i; // edi
  size_t v2; // eax
  HANDLE StdHandle; // eax
  void *v4; // ebp
  char **p_m_pReplacementString; // esi
  DWORD v6; // eax
  unsigned int NumberOfBytesWritten; // [esp+Ch] [ebp-4h] BYREF

  for ( i = 0; i < 0x17; ++i )
  {
    if ( a1 == s_NoEscConversion.m_pReplacements[i + 85].m_nLength )
      break;
  }
  if ( i < 0x17 )
  {
    if ( _set_error_mode_0(Mode: 3) == 1 || _set_error_mode_0(Mode: 3) == 0 && dword_3F663734 == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v4 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        p_m_pReplacementString = &s_NoEscConversion.m_pReplacements[i + 85].m_pReplacementString;
        v6 = strlen_0(Str: *p_m_pReplacementString);
        WriteFile(
          hFile: v4,
          lpBuffer: *p_m_pReplacementString,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &NumberOfBytesWritten,
          lpOverlapped: nullptr);
      }
    }
    else if ( a1 != 252 )
    {
      if ( strcpy_s_0(Destination: Destination, SizeInBytes: 0x314u, Source: "Runtime Error!\n\nProgram: ") != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      byte_3F66390D = 0;
      if ( GetModuleFileNameA(hModule: nullptr, lpFilename: Filename, nSize: 0x104u) == 0
        && strcpy_s_0(Destination: Filename, SizeInBytes: 0x2FBu, Source: "<program name unknown>") != 0 )
      {
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      }
      if ( strlen_0(Str: Filename) + 1 > 0x3C )
      {
        v2 = strlen_0(Str: Filename);
        if ( ((int (__cdecl *)(char *, int, const char *, int))loc_3F63FE13)(
               a1: &Filename[v2 - 59],
               a2: &unk_3F663B04 - (_UNKNOWN *)&Filename[v2 - 59],
               a3: "...",
               a4: 3) != 0 )
          _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      }
      if ( ((int (__cdecl *)(char *, int, const char *))loc_3F63FDA2)(a1: Destination, a2: 788, a3: "\n\n") != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      if ( ((int (__cdecl *)(char *, int, char *))loc_3F63FDA2)(
             a1: Destination,
             a2: 788,
             a3: s_NoEscConversion.m_pReplacements[i + 85].m_pReplacementString) != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      sub_3F64AC5E(a1: (int)Destination, a2: (int)"Microsoft Visual C++ Runtime Library", a3: 73744);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F632F29
// Name: __FF_MSGBANNER_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _FF_MSGBANNER_0()
{
  if ( _set_error_mode_0(Mode: 3) != 1 && (_set_error_mode_0(Mode: 3) != 0 || dword_3F663734 != 1) )
    JUMPOUT(0x3F632F61);
  return _allmul();
}

//------------------------------------------------------------------------------
// Address: 0x3F632F50
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _allmul()
{
  int v0; // [esp-4h] [ebp-4h]

  _NMSG_WRITE_0(a1: v0);
  _NMSG_WRITE_0(a1: 255);
}

//------------------------------------------------------------------------------
// Address: 0x3F632F84
// Name: __ZeroTail
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ZeroTail(int _EAX@<eax>, int a2@<edx>, int _ECX@<ecx>, int a4@<edi>)
{
  *(_DWORD *)(a4 - 119) += a2;
  __asm
  {
    fmul    dword ptr [ecx-7AF02F8Bh]
    fild    word ptr [eax]
  }
  JUMPOUT(0x3F632F90);
}

//------------------------------------------------------------------------------
// Address: 0x3F632FC9
// Name: __IncMan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _IncMan(char a1@<zf>)
{
  if ( !a1 )
    JUMPOUT(0x3F632FA5);
  JUMPOUT(0x3F632FCA);
}

//------------------------------------------------------------------------------
// Address: 0x3F633033
// Name: __RoundMan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _RoundMan(int a1@<ecx>, int a2@<ebp>)
{
  __security_check_cookie`...'(StackCookie: a2 ^ a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6330BC
// Name: sub_3F6330BC
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F6330BC(int a1)
{
  dword_3F663B0C = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6330C8
// Name: __global_unwind2_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _global_unwind2_0(int a1)
{
  return ((int (__stdcall *)(int, void *, _DWORD, _DWORD))&GS_ExceptionRecord.NumberParameters)(
           a1,
           a2: &gu_return_0,
           a3: 0,
           a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F6330E8
// Name: __unwind_handler_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unwind_handler_0(unsigned int *a1, unsigned int *a2, int a3, int a4, int a5)
{
  int v5; // eax

  if ( (a1[1] & 6) == 0 )
    JUMPOUT(0x3F63312C);
  __security_check_cookie`...'(StackCookie: a5 ^ *(_DWORD *)(a5 - 4));
  ((void (__cdecl *)(_DWORD, _DWORD))_local_unwind2_0)(a1: *(_DWORD *)(v5 + 36), a2: *(_DWORD *)(v5 + 40));
  _CopyMan(dest: a1, src: a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F633121
// Name: __CopyMan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _CopyMan(int a1@<eax>, unsigned int *dest, unsigned int *src, int a4, _DWORD *a5)
{
  *a5 = a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F63313C
// Name: __FillZeroMan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F633148
// Name: __IsZeroMan
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _IsZeroMan()
{
  __asm { aas }
  JUMPOUT(0x3F633163);
}

//------------------------------------------------------------------------------
// Address: 0x3F63319F
// Name: _lu_done_1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void lu_done_1()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F6331B1
// Name: __abnormal_termination_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _abnormal_termination_0()
{
  int result; // eax
  struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // ecx

  result = 0;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  if ( (void (__cdecl *)(unsigned int *, unsigned int *, int, int, int))ExceptionList->Handler == _unwind_handler_0 )
    return ExceptionList[1].Next == *((_EXCEPTION_REGISTRATION_RECORD **)ExceptionList[1].Handler + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6331D4
// Name: __NLG_Notify1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _NLG_Notify1()
{
  JUMPOUT(0x3F6331E8);
}

//------------------------------------------------------------------------------
// Address: 0x3F6331DD
// Name: __NLG_Notify_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _NLG_Notify_0(char *a1@<eax>, char *a2@<ebp>, int a3)
{
  s_NoEscConversion.m_pReplacements[109].m_nLength = a3;
  s_NoEscConversion.m_pReplacements[108].m_pReplacementString = a1;
  s_NoEscConversion.m_pReplacements[109].m_pReplacementString = a2;
  JUMPOUT(0x3F6331F9);
}

//------------------------------------------------------------------------------
// Address: 0x3F6331FC
// Name: __NLG_Call_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _NLG_Call_0@<eax>(int (*a1)(void)@<eax>)
{
  return a1();
}

//------------------------------------------------------------------------------
// Address: 0x3F6331FF
// Name: __rt_probe_read4@4_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _rt_probe_read4(int a1)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F63324A
// Name: _fastcopy_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl fastcopy_I(__m128i *a1, const __m128i *a2, unsigned int a3)
{
  unsigned int v5; // ecx
  __m128i si128; // xmm1
  __m128i v7; // xmm2
  __m128i v8; // xmm3
  __m128i v9; // xmm5
  __m128i v10; // xmm6
  __m128i v11; // xmm7

  v5 = a3 >> 7;
  do
  {
    si128 = _mm_load_si128(a2 + 1);
    v7 = _mm_load_si128(a2 + 2);
    v8 = _mm_load_si128(a2 + 3);
    *a1 = _mm_load_si128(a2);
    a1[1] = si128;
    a1[2] = v7;
    a1[3] = v8;
    v9 = _mm_load_si128(a2 + 5);
    v10 = _mm_load_si128(a2 + 6);
    v11 = _mm_load_si128(a2 + 7);
    a1[4] = _mm_load_si128(a2 + 4);
    a1[5] = v9;
    a1[6] = v10;
    a1[7] = v11;
    a2 += 8;
    a1 += 8;
    --v5;
  }
  while ( v5 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x3F6332D1
// Name: __VEC_memcpy_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__m128i *__cdecl _VEC_memcpy_0(__m128i *a1, const __m128i *a2, unsigned int a3)
{
  int v3; // ecx
  __m128i *result; // eax
  int v5; // ecx
  unsigned int v6; // [esp+4h] [ebp-18h]

  v3 = (int)a2 % 16;
  result = a1;
  if ( (((int)a1 % 16) | ((int)a2 % 16)) != 0 )
  {
    if ( v3 == (int)a1 % 16 )
    {
      qmemcpy(a1, a2, 16 - v3);
      _VEC_memcpy_0(a1: &a1->m128i_i8[16 - v3], a2: &a2->m128i_i8[16 - v3], a3: a3 - (16 - v3));
    }
    else
    {
      qmemcpy(a1, a2, a3);
    }
    return a1;
  }
  else
  {
    v5 = a3 & 0x7F;
    v6 = v5;
    if ( a3 != v5 )
    {
      fastcopy_I(a1, a2, a3: a3 - v5);
      result = a1;
      v5 = v6;
    }
    if ( v5 != 0 )
    {
      qmemcpy(&result->m128i_i8[a3 - v5], &a2->m128i_i8[a3 - v5], v6);
      return a1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6333B4
// Name: __sse2_mathfcns_init_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _sse2_mathfcns_init_0()
{
  dword_3F665FB4 = 0;
  dword_3F665FB4 = ((int (*)(void))_get_sse2_info_0)();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F6333C8
// Name: __set_SSE2_enable_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _set_SSE2_enable_0(int Flag)
{
  int result; // eax

  result = Flag != 0 ? dword_3F665FB8 : 0;
  dword_3F665FB4 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6333DC
// Name: _strcpy_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl strcpy_s_0(char *Destination, rsize_t SizeInBytes, const char *Source)
{
  rsize_t v3; // edi
  errno_t v4; // esi
  const char *v6; // esi
  char *v7; // edx
  char v8; // al

  if ( Destination == nullptr )
    goto LABEL_3;
  v3 = SizeInBytes;
  if ( SizeInBytes == 0 )
    goto LABEL_3;
  v6 = Source;
  if ( Source == nullptr )
  {
    *Destination = 0;
LABEL_3:
    v4 = 22;
    *_errno_0() = 22;
LABEL_4:
    _invalid_parameter_0();
    return v4;
  }
  v7 = Destination;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  if ( v3 == 0 )
  {
    *Destination = 0;
    *_errno_0() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F6337E3
// Name: ___crtLCMapStringA_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __crtLCMapStringA_0(
        struct localeinfo_struct *a1,
        struct localeinfo_struct *a2,
        unsigned int a3,
        unsigned int a4,
        const char *a5,
        int a6,
        char *a7,
        int a8,
        int a9)
{
  int result; // eax
  _LocaleUpdate v10; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v10, a2: a1);
  result = __crtLCMapStringA_stat(
             a1: a2,
             a2: a3,
             a3: a4,
             a4: a5,
             a5: a6,
             a6: a7,
             a7: a8,
             a8: a9,
             a9: v10.localeinfo.locinfo);
  if ( v10.updated )
    v10.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F633826
// Name: _strnlen_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl strnlen_0(const char *String, size_t MaxCount)
{
  size_t result; // eax

  for ( result = 0; result < MaxCount; ++String )
  {
    if ( *String == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F633850
// Name: ___alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __alloca_probe_16(char a1)
{
  JUMPOUT(0x3F64B520);
}

//------------------------------------------------------------------------------
// Address: 0x3F633866
// Name: ___alloca_probe_8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __alloca_probe_8(char a1)
{
  JUMPOUT(0x3F64B520);
}

//------------------------------------------------------------------------------
// Address: 0x3F63387C
// Name: _wcscpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl wcscpy_s(wchar_t *Destination, rsize_t SizeInWords, const wchar_t *Source)
{
  rsize_t v3; // ebx
  errno_t v4; // esi
  const wchar_t *v6; // esi
  wchar_t *v7; // edx
  wchar_t v8; // ax

  if ( Destination == nullptr )
    goto LABEL_3;
  v3 = SizeInWords;
  if ( SizeInWords == 0 )
    goto LABEL_3;
  v6 = Source;
  if ( Source == nullptr )
  {
    *Destination = 0;
LABEL_3:
    v4 = 22;
    *_errno_0() = 22;
LABEL_4:
    _invalid_parameter_0();
    return v4;
  }
  v7 = Destination;
  do
  {
    v8 = *v6;
    *v7++ = *v6++;
    if ( v8 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  if ( v3 == 0 )
  {
    *Destination = 0;
    *_errno_0() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F6338E8
// Name: int wcsncnt(wchar_t const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall wcsncnt@<eax>(_WORD *a1@<eax>, const wchar_t *a2)
{
  int v2; // ecx

  v2 = (int)a2;
  while ( v2 != 0 )
  {
    --v2;
    if ( *a1 == 0 )
      return (int)a2 - v2 - 1;
    ++a1;
  }
  v2 = -1;
  return (int)a2 - v2 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F633904
// Name: int __crtLCMapStringW_stat(struct localeinfo_struct __near *,unsigned long,unsigned long,wchar_t const __near *,int,wchar_t __near *,int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t *__cdecl __crtLCMapStringW_stat(
        LCID Locale,
        DWORD dwMapFlags,
        LPCWSTR lpSrcStr,
        const wchar_t *cchSrc,
        LPWSTR lpDestStr,
        wchar_t *cchDest,
        int CodePage)
{
  int v7; // ecx
  CHAR *v8; // ebx
  int v9; // edi
  int v10; // ecx
  LPCWSTR v11; // eax
  int v13; // eax
  int v14; // eax
  int v15; // edi
  int v16; // eax
  void *v17; // esp
  char *v18; // eax
  int v19; // eax
  wchar_t *v20; // esi
  int v21; // eax
  void *v22; // esp
  CHAR *v23; // eax
  int v24; // eax
  _DWORD v25[3]; // [esp+0h] [ebp-1Ch] BYREF
  int v26; // [esp+Ch] [ebp-10h]
  wchar_t *v27; // [esp+10h] [ebp-Ch]
  LPSTR lpMultiByteStr; // [esp+14h] [ebp-8h]

  v8 = nullptr;
  v9 = v7;
  if ( dword_3F663B14 == 0 )
  {
    if ( LCMapStringW(Locale: 0, dwMapFlags: 0x100u, lpSrcStr: &SrcStr, cchSrc: 1, lpDestStr: nullptr, cchDest: 0) != 0 )
    {
      dword_3F663B14 = 1;
    }
    else if ( GetLastError() == 120 )
    {
      dword_3F663B14 = 2;
    }
  }
  if ( (int)cchSrc > 0 )
  {
    v10 = (int)cchSrc;
    v11 = lpSrcStr;
    while ( 1 )
    {
      --v10;
      if ( *v11 == 0 )
        break;
      ++v11;
      if ( v10 == 0 )
      {
        v10 = -1;
        break;
      }
    }
    cchSrc = (const wchar_t *)((char *)cchSrc - 1 - v10);
  }
  if ( dword_3F663B14 == 1 )
    return (wchar_t *)LCMapStringW(Locale, dwMapFlags, lpSrcStr, (int)cchSrc, lpDestStr, (int)cchDest);
  if ( dword_3F663B14 != 2 && dword_3F663B14 != 0 )
    return nullptr;
  v27 = nullptr;
  if ( Locale == 0 )
    Locale = *(_DWORD *)(*(_DWORD *)v9 + 20);
  if ( CodePage == 0 )
    CodePage = *(_DWORD *)(*(_DWORD *)v9 + 4);
  v13 = ((int (__cdecl *)(LCID))__ansicp_0)(a1: Locale);
  if ( CodePage != v13 && v13 != -1 )
    CodePage = v13;
  v14 = WideCharToMultiByte(
          CodePage,
          dwFlags: 0,
          lpWideCharStr: lpSrcStr,
          cchWideChar: (int)cchSrc,
          lpMultiByteStr: nullptr,
          cbMultiByte: 0,
          lpDefaultChar: nullptr,
          lpUsedDefaultChar: nullptr);
  v15 = v14;
  v26 = v14;
  if ( v14 == 0 )
    return nullptr;
  if ( v14 > 0 && 0xFFFFFFE0 / v14 != 0 )
  {
    v16 = v14 + 8;
    if ( (unsigned int)(v15 + 8) > 0x400 )
    {
      v18 = (char *)((int (__cdecl *)(int))loc_3F609A30)(a1: v15 + 8);
      if ( v18 != nullptr )
      {
        *(_DWORD *)v18 = 56797;
        goto LABEL_32;
      }
    }
    else
    {
      v17 = alloca(v16);
      v18 = (char *)v25;
      if ( v25 != nullptr )
      {
        v25[0] = 52428;
LABEL_32:
        v18 += 8;
      }
    }
    lpMultiByteStr = v18;
    goto LABEL_35;
  }
  lpMultiByteStr = nullptr;
LABEL_35:
  if ( lpMultiByteStr == nullptr )
    return nullptr;
  if ( WideCharToMultiByte(
         CodePage,
         dwFlags: 0,
         lpWideCharStr: lpSrcStr,
         cchWideChar: (int)cchSrc,
         lpMultiByteStr,
         cbMultiByte: v15,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: nullptr) != 0 )
  {
    v19 = LCMapStringA(Locale, dwMapFlags, lpSrcStr: lpMultiByteStr, cchSrc: v15, lpDestStr: nullptr, cchDest: 0);
    v20 = (wchar_t *)v19;
    if ( v19 != 0 )
    {
      if ( v19 <= 0 || 0xFFFFFFE0 / v19 == 0 )
      {
LABEL_47:
        if ( v8 != nullptr )
        {
          if ( LCMapStringA(Locale, dwMapFlags, lpSrcStr: lpMultiByteStr, cchSrc: v26, lpDestStr: v8, cchDest: (int)v20) != 0 )
          {
            if ( (dwMapFlags & 0x400) != 0 )
            {
              v27 = v20;
              if ( cchDest != nullptr )
              {
                if ( (int)cchDest <= (int)v20 )
                  v20 = (wchar_t *)((char *)cchDest - 1);
                if ( ((int (__cdecl *)(LPWSTR, wchar_t *, CHAR *, wchar_t *))loc_3F63FE13)(
                       a1: lpDestStr,
                       a2: cchDest,
                       a3: v8,
                       a4: v20) != 0 )
                  _invoke_watson_0(
                    Expression: nullptr,
                    FunctionName: nullptr,
                    FileName: nullptr,
                    LineNo: 0,
                    Reserved: 0);
              }
            }
            else
            {
              if ( cchDest != nullptr )
                v24 = MultiByteToWideChar(
                        CodePage,
                        dwFlags: 1u,
                        lpMultiByteStr: v8,
                        cbMultiByte: (int)v20,
                        lpWideCharStr: lpDestStr,
                        cchWideChar: (int)cchDest);
              else
                v24 = MultiByteToWideChar(
                        CodePage,
                        dwFlags: 1u,
                        lpMultiByteStr: v8,
                        cbMultiByte: (int)v20,
                        lpWideCharStr: nullptr,
                        cchWideChar: 0);
              v27 = (wchar_t *)v24;
            }
          }
          _freea_0(Memory: v8);
        }
        goto LABEL_60;
      }
      v21 = v19 + 8;
      if ( (unsigned int)(v20 + 4) > 0x400 )
      {
        v23 = (CHAR *)((int (__cdecl *)(wchar_t *, _DWORD))loc_3F609A30)(a1: v20 + 4, a2: v25[0]);
        if ( v23 != nullptr )
        {
          *(_DWORD *)v23 = 56797;
          goto LABEL_45;
        }
      }
      else
      {
        v22 = alloca(v21);
        v23 = (CHAR *)v25;
        if ( v25 != nullptr )
        {
          v25[0] = 52428;
LABEL_45:
          v23 += 8;
        }
      }
      v8 = v23;
      goto LABEL_47;
    }
  }
LABEL_60:
  _freea_0(Memory: lpMultiByteStr);
  return v27;
}

//------------------------------------------------------------------------------
// Address: 0x3F633B65
// Name: ___crtLCMapStringW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
wchar_t *__cdecl __crtLCMapStringW(
        struct localeinfo_struct *a1,
        LCID Locale,
        DWORD dwMapFlags,
        LPCWSTR lpSrcStr,
        wchar_t *cchSrc,
        LPWSTR lpDestStr,
        wchar_t *cchDest,
        UINT CodePage)
{
  wchar_t *result; // eax
  _LocaleUpdate v9; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v9, a2: a1);
  result = __crtLCMapStringW_stat(Locale, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, CodePage);
  if ( v9.updated )
    v9.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F633BA5
// Name: _wcsnlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
size_t __cdecl wcsnlen(const wchar_t *Source, size_t MaxCount)
{
  size_t result; // eax

  for ( result = 0; result < MaxCount; ++Source )
  {
    if ( *Source == 0 )
      break;
    ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F633C64
// Name: __ld12tof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
INTRNCVT_STATUS __usercall _ld12tof@<eax>(int _ECX@<ecx>, unsigned __int16 *a2@<edi>, unsigned __int16 a3@<si>)
{
  unsigned int v3; // eax
  int v4; // eax
  unsigned __int16 *v5; // edi
  int *v6; // eax
  bool v7; // zf

  __asm { rcr     byte ptr [ecx+74h], 9 }
  MEMORY[0x85000016] = 10;
  MEMORY[0x84FFFFFA] = 5;
  while ( 1 )
  {
    v3 = _wchartodigit_0(a1: a3);
    if ( v3 == -1 )
    {
      if ( (a3 < 0x41u || a3 > 0x5Au) && (unsigned __int16)(a3 - 97) > 0x19u )
        break;
      v4 = a3;
      if ( (unsigned __int16)(a3 - 97) <= 0x19u )
        v4 = a3 - 32;
      v3 = v4 - 55;
    }
    if ( v3 >= MEMORY[0x85000016] )
      break;
    MEMORY[0x8500001A] |= 8u;
    if ( MEMORY[0x84FFFFFE] < 0x19999999u || MEMORY[0x84FFFFFE] == 429496729 && v3 <= MEMORY[0x84FFFFFA] )
    {
      MEMORY[0x84FFFFFE] = v3 + MEMORY[0x85000016] * MEMORY[0x84FFFFFE];
    }
    else
    {
      MEMORY[0x8500001A] |= 4u;
      if ( MEMORY[0x85000012] == 0 )
        break;
    }
    a3 = *a2++;
  }
  v5 = a2 - 1;
  if ( (MEMORY[0x8500001A] & 8) != 0 )
  {
    if ( (MEMORY[0x8500001A] & 4) != 0
      || (MEMORY[0x8500001A] & 1) == 0
      && ((MEMORY[0x8500001A] & 2) != 0 && MEMORY[0x84FFFFFE] > 0x80000000
       || (MEMORY[0x8500001A] & 2) == 0 && MEMORY[0x84FFFFFE] > 0x7FFFFFFFu) )
    {
      v6 = _errno_0();
      v7 = (MEMORY[0x8500001A] & 1) == 0;
      *v6 = 34;
      if ( v7 )
        MEMORY[0x84FFFFFE] = ((MEMORY[0x8500001A] & 2) != 0) + 0x7FFFFFFF;
      else
        MEMORY[0x84FFFFFE] = -1;
    }
  }
  else
  {
    if ( MEMORY[0x85000012] != 0 )
      v5 = (unsigned __int16 *)MEMORY[0x8500000E];
    MEMORY[0x84FFFFFE] = 0;
  }
  if ( MEMORY[0x85000012] != 0 )
    *MEMORY[0x85000012] = v5;
  if ( (MEMORY[0x8500001A] & 2) != 0 )
    MEMORY[0x84FFFFFE] = -MEMORY[0x84FFFFFE];
  if ( MEMORY[0x84FFFFF6] != 0 )
    *(_DWORD *)(MEMORY[0x84FFFFF2] + 112) &= ~2u;
  return MEMORY[0x84FFFFFE];
}

//------------------------------------------------------------------------------
// Address: 0x3F633DB8
// Name: _wcstol_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcstol_0(const wchar_t *String, wchar_t **EndPtr, int Radix)
{
  if ( dword_3F6637BC != 0 )
    return wcstoxl(a1: nullptr, a2: String, a3: (const wchar_t **)EndPtr, a4: Radix, a5: 0);
  else
    return wcstoxl(
             a1: (struct localeinfo_struct *)&s_NoEscConversion.m_pReplacements[81],
             a2: String,
             a3: (const wchar_t **)EndPtr,
             a4: Radix,
             a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F633DE1
// Name: sub_3F633DE1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl sub_3F633DE1(const wchar_t *a1, const wchar_t **a2, int a3, struct localeinfo_struct *a4)
{
  return wcstoxl(a1: a4, a2: a1, a3: a2, a4: a3, a5: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F633DFC
// Name: _wcstoul_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl wcstoul_0(const wchar_t *String, wchar_t **EndPtr, int Radix)
{
  if ( dword_3F6637BC != 0 )
    return wcstoxl(a1: nullptr, a2: String, a3: (const wchar_t **)EndPtr, a4: Radix, a5: 1);
  else
    return wcstoxl(
             a1: (struct localeinfo_struct *)&s_NoEscConversion.m_pReplacements[81],
             a2: String,
             a3: (const wchar_t **)EndPtr,
             a4: Radix,
             a5: 1);
}

//------------------------------------------------------------------------------
// Address: 0x3F633E50
// Name: __allmul_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul_0(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F633E90
// Name: __aulldvrm_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm_0(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F633F25
// Name: __wchartodigit_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wchartodigit_0(unsigned __int16 a1)
{
  int v2; // ecx
  bool v3; // cf

  if ( a1 < 0x30u )
    return -1;
  if ( a1 < 0x3Au )
    return a1 - 48;
  v2 = 65296;
  if ( a1 >= 0xFF10u )
  {
    v3 = a1 < 0xFF1Au;
LABEL_39:
    if ( v3 )
      return a1 - v2;
    return -1;
  }
  v2 = 1632;
  if ( a1 >= 0x660u )
  {
    if ( a1 < 0x66Au )
      return a1 - v2;
    v2 = 1776;
    if ( a1 >= 0x6F0u )
    {
      if ( a1 < 0x6FAu )
        return a1 - v2;
      v2 = 2406;
      if ( a1 >= 0x966u )
      {
        if ( a1 < 0x970u )
          return a1 - v2;
        v2 = 2534;
        if ( a1 >= 0x9E6u )
        {
          if ( a1 < 0x9F0u )
            return a1 - v2;
          v2 = 2662;
          if ( a1 >= 0xA66u )
          {
            if ( a1 < 0xA70u )
              return a1 - v2;
            v2 = 2790;
            if ( a1 >= 0xAE6u )
            {
              if ( a1 < 0xAF0u )
                return a1 - v2;
              v2 = 2918;
              if ( a1 >= 0xB66u )
              {
                if ( a1 < 0xB70u )
                  return a1 - v2;
                v2 = 3174;
                if ( a1 >= 0xC66u )
                {
                  if ( a1 < 0xC70u )
                    return a1 - v2;
                  v2 = 3302;
                  if ( a1 >= 0xCE6u )
                  {
                    if ( a1 < 0xCF0u )
                      return a1 - v2;
                    v2 = 3430;
                    if ( a1 >= 0xD66u )
                    {
                      if ( a1 < 0xD70u )
                        return a1 - v2;
                      v2 = 3664;
                      if ( a1 >= 0xE50u )
                      {
                        if ( a1 < 0xE5Au )
                          return a1 - v2;
                        v2 = 3792;
                        if ( a1 >= 0xED0u )
                        {
                          if ( a1 < 0xEDAu )
                            return a1 - v2;
                          v2 = 3872;
                          if ( a1 >= 0xF20u )
                          {
                            if ( a1 < 0xF2Au )
                              return a1 - v2;
                            v2 = 4160;
                            if ( a1 >= 0x1040u )
                            {
                              if ( a1 < 0x104Au )
                                return a1 - v2;
                              v2 = 6112;
                              if ( a1 >= 0x17E0u )
                              {
                                if ( a1 < 0x17EAu )
                                  return a1 - v2;
                                v2 = 6160;
                                if ( a1 >= 0x1810u )
                                {
                                  v3 = a1 < 0x181Au;
                                  goto LABEL_39;
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
            }
          }
        }
      }
    }
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6340A7
// Name: __iswctype_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _iswctype_l_0(wint_t C, wctype_t Type, _locale_t Locale)
{
  _LocaleUpdate v4; // [esp+0h] [ebp-14h] BYREF
  int v5; // [esp+10h] [ebp-4h] BYREF

  if ( C == 0xFFFF )
  {
    v5 = 0;
  }
  else if ( C >= 0x100u )
  {
    _LocaleUpdate::_LocaleUpdate(this: &v4, a2: Locale);
    if ( __crtGetStringTypeW_0(
           a1: &v4.localeinfo,
           a2: 1u,
           a3: &C,
           a4: 1,
           a5: (unsigned __int16 *)&v5,
           a6: v4.localeinfo.locinfo->lc_codepage,
           a7: v4.localeinfo.locinfo->lc_handle[2]) == 0 )
      v5 = 0;
    if ( v4.updated )
      v4.ptd->_ownlocale &= ~2u;
  }
  else
  {
    v5 = (unsigned __int16)(Type & *(_WORD *)&s_NoEscConversion.m_pReplacements[201].m_pReplacementString[2 * C]);
  }
  return Type & (unsigned __int16)v5;
}

//------------------------------------------------------------------------------
// Address: 0x3F634129
// Name: _iswctype_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl iswctype_0(wint_t C, wctype_t Type)
{
  unsigned __int16 v3; // [esp+0h] [ebp-4h] BYREF

  if ( C == 0xFFFF )
    return 0;
  if ( C < 0x100u )
    return Type & *(_WORD *)&s_NoEscConversion.m_pReplacements[201].m_pReplacementString[2 * C];
  if ( dword_3F6637BC == 0 )
    __crtGetStringTypeW_0(
      a1: (struct localeinfo_struct *)&s_NoEscConversion.m_pReplacements[81],
      a2: 1u,
      a3: &C,
      a4: 1,
      a5: &v3,
      a6: (int)s_NoEscConversion.m_pReplacements[53].m_pReplacementString,
      a7: (int)s_NoEscConversion.m_pReplacements[55].m_pReplacementString);
  return _iswctype_l_0(C, Type, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F634197
// Name: j__iswctype_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl j__iswctype_0(wint_t C, wctype_t Type)
{
  return iswctype_0(C, Type);
}

//------------------------------------------------------------------------------
// Address: 0x3F6341A6
// Name: __ld12told
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ld12told()
{
  JUMPOUT(0x3F6341A8);
}

//------------------------------------------------------------------------------
// Address: 0x3F634268
// Name: char __near * strrchr(char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void strrchr()
{
  __asm { aas }
  JUMPOUT(0x3F634269);
}

//------------------------------------------------------------------------------
// Address: 0x3F63426D
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _forcdecpt_l(int a1@<ebx>, int a2@<ebp>)
{
  DWORD LastError; // eax

  ++*(_DWORD *)(a1 + 2080442493);
  if ( *(int *)(a2 + 8) <= 31 )
  {
    _lock_0(a1: 7);
    *(_DWORD *)(a2 - 4) = 0;
    *(_BYTE *)(a2 - 28) = *(_DWORD *)(a2 + 8) + 64;
    *(_BYTE *)(a2 - 27) = 58;
    *(_BYTE *)(a2 - 26) = 0;
    if ( !SetCurrentDirectoryA(lpPathName: (LPCSTR)(a2 - 28)) )
    {
      LastError = GetLastError();
      _dosmaperr_0(a1: LastError);
      JUMPOUT(0x3F6342E0);
    }
    *(_DWORD *)(a2 - 32) = 0;
    *(_DWORD *)(a2 - 4) = -2;
    sub_3F6342FA(a1: (unsigned __int16)__ES__);
  }
  else
  {
    *__doserrno_0() = 15;
    *_errno_0() = 13;
    _invalid_parameter_0();
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F6342FA
// Name: sub_3F6342FA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F6342FA()
{
  return _unlock_0(a1: 7);
}

//------------------------------------------------------------------------------
// Address: 0x3F634303
// Name: __mtinitlocks_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _mtinitlocks_0()
{
  int v0; // esi
  char *v1; // edi
  CUtlCharConversion::ConversionInfo_t *v2; // eax

  v0 = 0;
  v1 = (char *)&unk_3F663B18;
  while ( 1 )
  {
    if ( s_NoEscConversion.m_pReplacements[v0 + 110].m_pReplacementString == (char *)1 )
    {
      v2 = &s_NoEscConversion.m_pReplacements[v0 + 110];
      v2->m_nLength = (int)v1;
      v1 += 24;
      if ( ((int (__cdecl *)(int, int))__crtInitCritSecAndSpinCount_0)(a1: v2->m_nLength, a2: 4000) == 0 )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  s_NoEscConversion.m_pReplacements[v0 + 110].m_nLength = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F63434C
// Name: __mtdeletelocks_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtdeletelocks_0(long double *a1)
{
  return _positive(arg: a1);
}

//------------------------------------------------------------------------------
// Address: 0x3F63435E
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _positive(char a1@<zf>, void (__stdcall *a2)(int)@<ebx>, int a3@<edi>, _DWORD *a4@<esi>)
{
  if ( !a1 && a4[1] != 1 )
  {
    a2(a1: a3);
    ((void (__cdecl *)(int))loc_3F609ED0)(a1: a3);
    *a4 = 0;
  }
  JUMPOUT(0x3F634376);
}

//------------------------------------------------------------------------------
// Address: 0x3F6343A1
// Name: __unlock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_0(int a1, char *a2, char *a3)
{
  LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)s_NoEscConversion.m_pReplacements[a1 + 110].m_nLength);
  _fassign(flag: a1, argument: a2, number: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F6343B4
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl _fassign()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F6343CB
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(int a1@<ecx>, int a2@<ebp>, char *a3)
{
  MK_FP(*(_WORD *)(a1 - 61 + 4), *(_DWORD *)(a1 - 61))();
  *(_DWORD *)(a2 - 28) = 1;
  _forcdecpt(buffer: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F6343E8
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _forcdecpt(char a1@<zf>, char *buffer)
{
  if ( a1 )
  {
    _FF_MSGBANNER_0();
    _NMSG_WRITE_0(a1: 30);
    _cropzeros(buf: buffer);
  }
  JUMPOUT(0x3F634402);
}

//------------------------------------------------------------------------------
// Address: 0x3F6343F6
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _cropzeros()
{
  __crtExitProcess_0(uExitCode: 0xFFu);
}

//------------------------------------------------------------------------------
// Address: 0x3F634404
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(char *buf@<eax>, char a2@<cl>, int a3@<ebx>, int a4@<ebp>, int a5@<edi>, int *a6@<esi>)
{
  int v8; // edi

  *(_BYTE *)(a4 + 459339060) |= a2;
  __asm { aas }
  if ( *a6 != a3 )
    return a5;
  v8 = ((int (__cdecl *)(int))loc_3F609A30)(a1: 24);
  if ( v8 == a3 )
  {
    *_errno_0() = 12;
    return 0;
  }
  else
  {
    _lock_0(a1: 10);
    *(_DWORD *)(a4 - 4) = a3;
    if ( *a6 == a3 )
    {
      if ( ((int (__cdecl *)(int, int))__crtInitCritSecAndSpinCount_0)(a1: v8, a2: 4000) != 0 )
      {
        *a6 = v8;
      }
      else
      {
        ((void (__cdecl *)(int))loc_3F609ED0)(a1: v8);
        *_errno_0() = 12;
        *(_DWORD *)(a4 - 28) = a3;
      }
    }
    else
    {
      ((void (__cdecl *)(int))loc_3F609ED0)(a1: v8);
    }
    *(_DWORD *)(a4 - 4) = -2;
    sub_3F634488();
    return *(_DWORD *)(a4 - 28);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F634488
// Name: sub_3F634488
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F634491
// Name: __lock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_0(int a1)
{
  LPCRITICAL_SECTION *v1; // esi

  v1 = (LPCRITICAL_SECTION *)&s_NoEscConversion.m_pReplacements[a1 + 110];
  if ( *v1 == nullptr && ((int (__cdecl *)(int))loc_3F6343CE)(a1) == 0 )
    _amsg_exit_0(a1: 17);
  EnterCriticalSection(lpCriticalSection: *v1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6344C2
// Name: __mbctoupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _mbctoupper_l(unsigned int Ch, _locale_t Locale)
{
  unsigned int result; // eax
  _LocaleUpdate v3; // [esp+4h] [ebp-18h] BYREF
  _BYTE v4[4]; // [esp+14h] [ebp-8h] BYREF
  _BYTE v5[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &v3, a2: Locale);
  if ( Ch <= 0xFF )
  {
    if ( (v3.localeinfo.mbcinfo->mbctype[Ch + 1] & 0x20) != 0 )
      result = v3.localeinfo.mbcinfo->mbcasemap[Ch];
    else
      result = Ch;
LABEL_11:
    if ( v3.updated )
      v3.ptd->_ownlocale &= ~2u;
    return result;
  }
  v5[0] = BYTE1(Ch);
  v5[1] = Ch;
  if ( (v3.localeinfo.mbcinfo->mbctype[BYTE1(Ch) + 1] & 4) != 0
    && __crtLCMapStringA_0(
         a1: &v3.localeinfo,
         a2: (struct localeinfo_struct *)v3.localeinfo.mbcinfo->mblcid,
         a3: 0x200u,
         a4: (unsigned int)v5,
         a5: (const char *)2,
         a6: (int)v4,
         a7: (char *)2,
         a8: v3.localeinfo.mbcinfo->mbcodepage,
         a9: 1) != 0 )
  {
    result = v4[1] + (v4[0] << 8);
    goto LABEL_11;
  }
  if ( v3.updated )
    v3.ptd->_ownlocale &= ~2u;
  return Ch;
}

//------------------------------------------------------------------------------
// Address: 0x3F634566
// Name: __mbctoupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _mbctoupper(unsigned int Ch)
{
  char *v2; // [esp+8h] [ebp+8h]
  unsigned int v3; // [esp+Ch] [ebp+Ch]
  int v4; // [esp+10h] [ebp+10h]
  int v5; // [esp+14h] [ebp+14h]
  localeinfo_struct *v6; // [esp+18h] [ebp+18h]

  _mbctoupper_l(Ch, Locale: nullptr);
  return _cftoe_l(pvalue: (long double *)Ch, buf: v2, sizeInBytes: v3, ndec: v4, caps: v5, plocinfo: v6);
}

//------------------------------------------------------------------------------
// Address: 0x3F634571
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl _cftoe_l()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F63465D
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _cftoa_l@<eax>(char a1@<zf>, _BYTE *a2@<edx>, char a3@<ch>, int _EDI@<edi>)
{
  if ( a1 )
  {
    __asm { bound   edi, [edi] }
    return ((int (*)(void))loc_3F634607)();
  }
  else
  {
    *a2 |= a3;
    return ((int (__cdecl *)(_DWORD))loc_3F634607)(a1: _output_l_0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F6349CE
// Name: __cftoa
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _cftoa@<eax>(char a1@<zf>, int result@<eax>, int a3@<ebp>)
{
  if ( a1 )
    result = ((int (__cdecl *)(void *, _DWORD, _DWORD))loc_3F6346C0)(
               a1: &_output_p_l_0,
               a2: *(_DWORD *)(a3 + 8),
               a3: *(_DWORD *)(a3 + 12));
  if ( result < 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6349EC
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl cftof2_l(signed int sizeInBytes, int ndec, unsigned int g_fmt)
{
  unsigned int v5; // eax
  char v6; // cl
  int v7; // eax

  if ( sizeInBytes == -2 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    JUMPOUT(0x3F634FAA);
  }
  if ( sizeInBytes < 0 || sizeInBytes >= uNumber )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    _invalid_parameter_0();
    JUMPOUT(0x3F634FA9);
  }
  v5 = 56 * (sizeInBytes & 0x1F) + dword_3F665FE0[sizeInBytes >> 5];
  v6 = *(_BYTE *)(v5 + 4);
  if ( (v6 & 1) == 0 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    JUMPOUT(0x3F634AF4);
  }
  if ( g_fmt <= 0x7FFFFFFF )
  {
    if ( g_fmt == 0 || (v6 & 2) != 0 )
      JUMPOUT(0x3F634FA6);
    if ( ndec != 0 )
    {
      v7 = ((char)(2 * *(_BYTE *)(v5 + 36)) >> 1) - 1;
      if ( v7 == 0 )
        JUMPOUT(0x3F634AE0);
      if ( v7 != 1 || (g_fmt & 1) == 0 )
        JUMPOUT(0x3F634B5B);
    }
  }
  JUMPOUT(0x3F634AE2);
}

//------------------------------------------------------------------------------
// Address: 0x3F634AE1
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cftof_l()
{
  JUMPOUT(0x3F634AEA);
}

//------------------------------------------------------------------------------
// Address: 0x3F634B9A
// Name: __cftof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cftof@<eax>(
        _BYTE *a1@<eax>,
        char a2@<cl>,
        int a3@<ebp>,
        int *a4@<edi>,
        int a5@<esi>,
        long double *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int a10,
        localeinfo_struct *a11)
{
  int v11; // ecx
  bool v12; // zf

  *a1 = a2;
  v11 = *a4;
  --*(_DWORD *)(a3 + 16);
  v12 = *(_BYTE *)(a3 - 2) == 1;
  *(_DWORD *)(a3 - 16) = 2;
  *(_BYTE *)(a5 + v11 + 37) = 10;
  if ( !v12 )
    JUMPOUT(0x3F634BD9);
  return _cftog_l(pvalue, buf, sizeInBytes, ndec, caps: a10, plocinfo: a11);
}

//------------------------------------------------------------------------------
// Address: 0x3F634BB5
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _cftog_l(_BYTE *a1@<eax>, _OVERLAPPED *a2@<ebx>, int a3@<ebp>, int *a4@<edi>, int a5@<esi>)
{
  char v5; // cl
  int v6; // ecx
  _OVERLAPPED *v7; // ecx
  int v8; // eax
  char *v9; // eax
  _BYTE *v10; // ebx
  _BYTE *v11; // eax
  char *v12; // ecx
  char v13; // al

  v5 = *(_BYTE *)(a5 + *a4 + 38);
  if ( v5 != 10 && *(_OVERLAPPED **)(a3 + 16) != a2 )
  {
    *a1 = v5;
    v6 = *a4;
    ++a1;
    --*(_DWORD *)(a3 + 16);
    *(_DWORD *)(a3 - 16) = 3;
    *(_BYTE *)(a5 + v6 + 38) = 10;
  }
  if ( ReadFile(
         hFile: *(HANDLE *)(a5 + *a4),
         lpBuffer: a1,
         nNumberOfBytesToRead: *(_DWORD *)(a3 + 16),
         lpNumberOfBytesRead: (LPDWORD)(a3 - 24),
         lpOverlapped: a2) )
  {
    v7 = *(_OVERLAPPED **)(a3 - 24);
    if ( (int)v7 >= (int)a2 && (unsigned int)v7 <= *(_DWORD *)(a3 + 16) )
    {
      v8 = *a4;
      *(_DWORD *)(a3 - 16) += v7;
      v9 = (char *)(a5 + v8 + 4);
      if ( *v9 < 0 )
      {
        if ( *(_BYTE *)(a3 - 2) != 2 )
        {
          if ( v7 == a2 || **(_BYTE **)(a3 - 12) != 10 )
            *v9 &= ~4u;
          else
            *v9 |= 4u;
          v10 = *(_BYTE **)(a3 - 12);
          v11 = &v10[*(_DWORD *)(a3 - 16)];
          *(_DWORD *)(a3 + 16) = v10;
          *(_DWORD *)(a3 - 16) = v11;
          if ( v10 < v11 )
          {
            v12 = *(char **)(a3 + 16);
            v13 = *v12;
            if ( *v12 != 26 )
            {
              if ( v13 != 13 )
              {
                *v10 = v13;
                *(_DWORD *)(a3 + 16) = v12 + 1;
                JUMPOUT(0x3F634CFC);
              }
              if ( (unsigned int)v12 < *(_DWORD *)(a3 - 16) - 1 )
              {
                if ( v12[1] == 10 )
                {
                  *(_DWORD *)(a3 + 16) = v12 + 2;
                  *v10 = 10;
                  JUMPOUT(0x3F634CFB);
                }
                *(_DWORD *)(a3 + 16) = v12 + 1;
                JUMPOUT(0x3F634CF8);
              }
              ++*(_DWORD *)(a3 + 16);
              if ( !ReadFile(
                      hFile: *(HANDLE *)(a5 + *a4),
                      lpBuffer: (LPVOID)(a3 - 1),
                      nNumberOfBytesToRead: 1u,
                      lpNumberOfBytesRead: (LPDWORD)(a3 - 24),
                      lpOverlapped: nullptr) )
                JUMPOUT(0x3F634CA9);
              JUMPOUT(0x3F634CB3);
            }
            JUMPOUT(0x3F634D0A);
          }
          JUMPOUT(0x3F634D1F);
        }
        JUMPOUT(0x3F634E3B);
      }
      JUMPOUT(0x3F634E01);
    }
  }
  JUMPOUT(0x3F634F71);
}

//------------------------------------------------------------------------------
// Address: 0x3F634CAD
// Name: __cftog
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _cftog@<eax>(
        int _EAX@<eax>,
        _BYTE *a2@<ebx>,
        int a3@<ebp>,
        _DWORD *a4@<edi>,
        int a5@<esi>,
        long double *pvalue,
        long double *buf,
        char *sizeInBytes,
        unsigned int ndec,
        int caps,
        int capsa,
        localeinfo_struct *a12)
{
  __asm { aas }
  if ( _EAX != 0 || *(_DWORD *)(a3 - 24) == 0 )
    JUMPOUT(0x3F634CF8);
  if ( (*(_BYTE *)(a5 + *a4 + 4) & 0x48) == 0 )
    JUMPOUT(0x3F634CD6);
  if ( *(_BYTE *)(a3 - 1) == 10 )
    JUMPOUT(0x3F634C81);
  *a2 = 13;
  return _cfltcvt_l(
           arg: pvalue,
           buffer: (char *)buf,
           (unsigned int)sizeInBytes,
           format: ndec,
           precision: caps,
           caps: capsa,
           plocinfo: a12);
}

//------------------------------------------------------------------------------
// Address: 0x3F634D72
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _setdefaultprecision(int a1@<eax>, int a2@<ecx>, _DWORD *a3@<edi>, int a4@<esi>)
{
  if ( a2 == 0 )
  {
    *_errno_0() = 42;
    JUMPOUT(0x3F634DFD);
  }
  if ( a2 + 1 != a1 )
  {
    if ( (*(_BYTE *)(a4 + *a3 + 4) & 0x48) != 0 )
      JUMPOUT(0x3F634D9A);
    JUMPOUT(0x3F634DBA);
  }
  JUMPOUT(0x3F634DCC);
}

//------------------------------------------------------------------------------
// Address: 0x3F634D9B
// Name: __ms_p5_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ms_p5_test_fdiv(int a1@<eax>, char a2@<dl>, int a3@<ebx>, _DWORD *a4@<edi>, int a5@<esi>)
{
  _BYTE *v5; // ebx

  *(_BYTE *)(a5 + *a4 + 37) = a2;
  v5 = (_BYTE *)(a3 + 1);
  if ( a1 == -327813497 )
    *(_BYTE *)(a5 + *a4 + 38) = *v5;
  JUMPOUT(0x3F634DD5);
}

//------------------------------------------------------------------------------
// Address: 0x3F634DD7
// Name: __ms_p5_mp_test_fdiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _ms_p5_mp_test_fdiv(int a1@<ebp>)
{
  int v1; // eax
  DWORD LastError; // eax
  int v3; // [esp-Ch] [ebp-Ch]
  wchar_t *v4; // [esp-8h] [ebp-8h]
  int v5; // [esp-4h] [ebp-4h]

  v1 = MultiByteToWideChar(
         CodePage: 0xFDE9u,
         dwFlags: 0,
         lpMultiByteStr: *(LPCCH *)(a1 - 12),
         cbMultiByte: v3,
         lpWideCharStr: v4,
         cchWideChar: v5);
  *(_DWORD *)(a1 - 16) = v1;
  if ( v1 == 0 )
  {
    LastError = GetLastError();
    _dosmaperr_0(a1: LastError);
    JUMPOUT(0x3F634DFD);
  }
  JUMPOUT(0x3F634E24);
}

//------------------------------------------------------------------------------
// Address: 0x3F634E00
// Name: ___add_12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __add_12(int a1@<eax>, int a2@<ebx>)
{
  --*(_DWORD *)(a2 + 1161557061);
  LOBYTE(a1) = a1 | 0x74;
  ((void (__cdecl *)(int))loc_3F609ED0)(a1);
  JUMPOUT(0x3F634FA8);
}

//------------------------------------------------------------------------------
// Address: 0x3F634E6D
// Name: ___mtold12
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __mtold12(_WORD *a1@<eax>, int a2@<ecx>, _WORD *a3@<ebx>, int a4@<ebp>, _DWORD *a5@<edi>, int a6@<esi>)
{
  _BYTE *v6; // esi

  if ( a2 == 26 )
  {
    v6 = (_BYTE *)(a6 + *a5 + 4);
    if ( (*v6 & 0x40) != 0 )
      *a3++ = *a1;
    else
      *v6 |= 2u;
    goto LABEL_25;
  }
  if ( (_WORD)a2 != 13 )
  {
    *a3++ = a2;
    *(_DWORD *)(a4 + 16) = a1 + 1;
    goto LABEL_20;
  }
  if ( (unsigned int)a1 >= *(_DWORD *)(a4 - 16) - 2 )
  {
    *(_DWORD *)(a4 + 16) += 2;
    if ( (ReadFile(
            hFile: *(HANDLE *)(a6 + *a5),
            lpBuffer: (LPVOID)(a4 - 8),
            nNumberOfBytesToRead: 2u,
            lpNumberOfBytesRead: (LPDWORD)(a4 - 24),
            lpOverlapped: nullptr)
       || GetLastError() == 0)
      && *(_DWORD *)(a4 - 24) != 0 )
    {
      if ( (*(_BYTE *)(a6 + *a5 + 4) & 0x48) != 0 )
      {
        if ( *(_WORD *)(a4 - 8) != 10 )
        {
          *a3 = 13;
          *(_BYTE *)(a6 + *a5 + 5) = *(_BYTE *)(a4 - 8);
          *(_BYTE *)(a6 + *a5 + 37) = *(_BYTE *)(a4 - 7);
          *(_BYTE *)(a6 + *a5 + 38) = 10;
          goto LABEL_19;
        }
LABEL_7:
        *a3 = 10;
LABEL_19:
        ++a3;
LABEL_20:
        if ( *(_DWORD *)(a4 + 16) < *(_DWORD *)(a4 - 16) )
          JUMPOUT(0x3F634E66);
LABEL_25:
        *(_DWORD *)(a4 - 16) = (char *)a3 - *(_DWORD *)(a4 - 12);
        JUMPOUT(0x3F634E01);
      }
      if ( a3 == *(_WORD **)(a4 - 12) && *(_WORD *)(a4 - 8) == 10 )
        goto LABEL_7;
      _lseeki64_nolock_0(a1: *(_DWORD *)(a4 + 8), a2: -2, a3: -1, dwMoveMethod: 1u);
      if ( *(_WORD *)(a4 - 8) == 10 )
        goto LABEL_20;
    }
  }
  else
  {
    if ( a1[1] == 10 )
    {
      *(_DWORD *)(a4 + 16) = a1 + 2;
      goto LABEL_7;
    }
    *(_DWORD *)(a4 + 16) = a1 + 1;
  }
  *a3 = 13;
  goto LABEL_19;
}

//------------------------------------------------------------------------------
// Address: 0x3F6350A0
// Name: sub_3F6350A0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F6350A0@<eax>(int a1@<ebp>)
{
  return ((int (__cdecl *)(_DWORD))_LN9_16)(a1: *(_DWORD *)(a1 + 8));
}

//------------------------------------------------------------------------------
// Address: 0x3F6350AA
// Name: _memcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
static errno_t __cdecl memcpy_s(
        void *const Destination,
        const rsize_t DestinationSize,
        const void *const Source,
        const rsize_t SourceSize)
{
  if ( SourceSize == 0 )
    JUMPOUT(0x3F635121);
  return _lseeki64(fh: (int)Destination, pos: *(__int64 *)&DestinationSize, mthd: SourceSize);
}

//------------------------------------------------------------------------------
// Address: 0x3F6350BC
// Name: __lseeki64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _lseeki64@<eax>(int a1@<ebp>, int a2@<edi>, size_t a3@<esi>)
{
  int v3; // esi

  if ( *(_DWORD *)(a1 + 8) != a2 )
  {
    if ( *(_DWORD *)(a1 + 16) != a2 && *(_DWORD *)(a1 + 12) >= a3 )
    {
      memcpy_1(a1: *(void **)(a1 + 8), Src: *(const void **)(a1 + 16), Size: a3);
      JUMPOUT(0x3F6350B8);
    }
    memset(a1: *(void **)(a1 + 8), Val: a2, Size: *(_DWORD *)(a1 + 12));
    if ( *(_DWORD *)(a1 + 16) != a2 )
    {
      if ( *(_DWORD *)(a1 + 12) < a3 )
      {
        *_errno_0() = 34;
        v3 = 34;
        goto LABEL_3;
      }
      return 22;
    }
  }
  v3 = 22;
  *_errno_0() = 22;
LABEL_3:
  _invalid_parameter_0();
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F635130
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl memset(void *a1, int Val, size_t Size)
{
  size_t v3; // edx
  int v4; // eax
  _BYTE *v6; // edi
  int v7; // ecx
  size_t v8; // ecx
  unsigned int v9; // ecx

  v3 = Size;
  if ( Size == 0 )
    return a1;
  LOBYTE(v4) = Val;
  if ( (_BYTE)Val == 0 && Size >= 0x100 && dword_3F665FB8 != 0 )
    return (void *)_VEC_memzero_0((int)a1, a2: Val, a3: Size);
  v6 = a1;
  if ( Size < 4 )
    goto LABEL_17;
  v7 = -(int)a1 & 3;
  if ( v7 != 0 )
  {
    v3 = Size - v7;
    do
    {
      *v6++ = Val;
      --v7;
    }
    while ( v7 != 0 );
  }
  v4 = 16843009 * (unsigned __int8)Val;
  v8 = v3;
  v3 &= 3u;
  v9 = v8 >> 2;
  if ( v9 == 0 || (memset32(v6, v4, v9), v6 += 4 * v9, v3 != 0) )
  {
LABEL_17:
    do
    {
      *v6++ = v4;
      --v3;
    }
    while ( v3 != 0 );
  }
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6351D5
// Name: public: HeapManager::Block::Block(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall HeapManager::Block::Block(HeapManager::Block *this@<ecx>, char a2@<cf>, int a3@<eax>, char a4@<dl>)
{
  *(_BYTE *)(a3 - 1) -= a2 + a4;
  JUMPOUT(0x3F6351D8);
}

//------------------------------------------------------------------------------
// Address: 0x3F6351DB
// Name: public: void HeapManager::Constructor(void __near * (*)(unsigned int),void (*)(void __near *))
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge HeapManager::Constructor(
        HeapManager *this@<ecx>,
        int _EAX@<eax>,
        int a3@<esi>,
        void *(__cdecl *pAlloc)(unsigned int),
        void (__cdecl *pFree)(void *))
{
  DWORD LastError; // eax
  _BYTE *v7; // eax

  __asm { aas }
  if ( _EAX == -1 )
    LastError = GetLastError();
  else
    LastError = 0;
  if ( LastError != 0 )
  {
    _dosmaperr_0(a1: LastError);
    JUMPOUT(0x3F6351F8);
  }
  v7 = (_BYTE *)(dword_3F665FE0[a3 >> 5] + 56 * (a3 & 0x1F) + 4);
  *v7 &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x3F63521C
// Name: private: static int UnDecorator::getNumberOfDimensions(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl UnDecorator::getNumberOfDimensions(int a1)
{
  if ( a1 == -2 )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
LABEL_8:
    JUMPOUT(0x3F6352E8);
  }
  if ( a1 < 0 || a1 >= uNumber )
  {
    *__doserrno_0() = 0;
    *_errno_0() = 9;
    _invalid_parameter_0();
    goto LABEL_8;
  }
  return UnDecorator::getTypeEncoding();
}

//------------------------------------------------------------------------------
// Address: 0x3F63527F
// Name: private: static int UnDecorator::getTypeEncoding(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall UnDecorator::getTypeEncoding@<eax>(char a1@<al>, int a2@<ecx>, _DWORD *a3@<ebp>, unsigned int a4@<edi>)
{
  int *v4; // ebx
  int v5; // esi

  v4 = &dword_3F665FE0[a2];
  v5 = 56 * (a1 & 0x1F);
  if ( (*(_BYTE *)(*v4 + v5 + 4) & 1) == 0 )
    JUMPOUT(0x3F635259);
  ((void (__cdecl *)(char))loc_3F63B293)(a1);
  *(a3 - 1) = a4;
  if ( (*(_BYTE *)(*v4 + v5 + 4) & 1) != 0 )
  {
    *(a3 - 7) = ((int (__cdecl *)(_DWORD, _DWORD, _DWORD))_lseek_nolock_0)(a1: a3[2], a2: a3[3], a3: a3[4]);
  }
  else
  {
    *_errno_0() = 9;
    *__doserrno_0() = a4;
    *(a3 - 7) = -1;
  }
  *(a3 - 1) = -2;
  ((void (*)(void))loc_3F6352EE)();
  return *(a3 - 7);
}

//------------------------------------------------------------------------------
// Address: 0x3F635368
// Name: ___loctotime32_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __loctotime32_t(int a1, int a2, int a3, unsigned int a4, unsigned int a5, unsigned int a6, int a7)
{
  int v7; // esi
  int v8; // ebx
  char *v9; // eax
  int v10; // ecx
  int v11; // edi
  int v13; // [esp+30h] [ebp-Ch] BYREF
  int v14; // [esp+34h] [ebp-8h] BYREF
  int v15; // [esp+38h] [ebp-4h] BYREF
  int v16; // [esp+44h] [ebp+8h]

  v7 = a1 - 1900;
  v14 = 0;
  v13 = 0;
  v15 = 0;
  if ( a1 - 1900 < 70
    || v7 > 138
    || (v8 = a2, (unsigned int)(a2 - 1) > 0xB)
    || a4 > 0x17
    || a5 > 0x3B
    || a6 > 0x3B
    || a3 < 1
    || (v9 = &output[4 * a2 + 636], v10 = *((_DWORD *)v9 - 1), *(_DWORD *)v9 - v10 < a3)
    && ((v7 % 4 != 0 || v7 % 100 == 0) && a1 % 400 != 0 || (v8 = a2, a2 != 2) || a3 > 29) )
  {
    *_errno_0() = 22;
    return -1;
  }
  else
  {
    v16 = a3 + v10;
    if ( (v7 % 4 == 0 && v7 % 100 != 0 || (v7 + 1900) % 400 == 0) && v8 > 2 )
      ++v16;
    __tzset_0();
    if ( sub_3F64C1B2(a1: &v14) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    if ( sub_3F64C1E6(a1: &v13) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    if ( sub_3F64C21A(a1: &v15) != 0 )
      _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
    v11 = v15
        + 60 * (a5 + 60 * (a4 + 24 * ((v7 + 299) / 400 - (v7 - 1) / 100 + v16 + (v7 - 1) / 4 + 365 * v7)))
        + a6
        + 2085978496;
    if ( a7 == 1 || a7 == -1 && v14 != 0 && _isindst_0() != 0 )
      v11 += v13;
    return v11;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F63556C
// Name: ___check_float_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __check_float_string@<eax>(void **a1@<edi>, size_t *a2@<esi>, int a3, void *Src, _DWORD *a5)
{
  size_t v5; // eax
  int v6; // eax
  int v8; // eax

  v5 = *a2;
  if ( a3 == *a2 )
  {
    if ( *a1 == Src )
    {
      v6 = ((int (__cdecl *)(size_t, int))loc_3F609A90)(a1: v5, a2: 2);
      *a1 = (void *)v6;
      if ( v6 == 0 )
        return 0;
      *a5 = 1;
      memcpy_1(a1: *a1, Src, Size: *a2);
    }
    else
    {
      v8 = ((int (__cdecl *)(void *, size_t, int))loc_3F609930)(a1: *a1, a2: v5, a3: 2);
      if ( v8 == 0 )
        return 0;
      *a1 = (void *)v8;
    }
    *a2 *= 2;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6355C0
// Name: __INTRN_LOCALE_CONV_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _INTRN_LOCALE_CONV_0(int a1)
{
  return *(_DWORD *)(*(_DWORD *)a1 + 188);
}

//------------------------------------------------------------------------------
// Address: 0x3F6355CD
// Name: __inc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _inc(int a1, FILE *a2)
{
  if ( --a2->_cnt < 0 )
    return _filbuf_0(File: a2);
  return *(unsigned __int8 *)a2->_ptr++;
}

//------------------------------------------------------------------------------
// Address: 0x3F6356F3
// Name: public: static int UnDecorator::doUnderScore(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::doUnderScore(_DWORD *a1@<eax>, int a2@<ebx>)
{
  --*(_DWORD *)(a2 - 1241524099);
  __readeflags();
  *a1 += a1;
  JUMPOUT(0x3F6356FC);
}

//------------------------------------------------------------------------------
// Address: 0x3F6356FE
// Name: public: static int UnDecorator::doMSKeywords(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63570B
// Name: public: static int UnDecorator::doPtr64(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::doPtr64(int a1@<eax>, int a2@<edi>, FILE *a3@<esi>)
{
  __int16 v3; // [esp-Ch] [ebp-Ch]

  if ( (*MK_FP(v3, *MK_FP(v3, a2) + 56 * a1 + 36) & 0x7F) == 0 )
  {
    if ( _fileno_0(Stream: a3) != -1 )
      JUMPOUT(0x3F6356B7);
    JUMPOUT(0x3F6356EE);
  }
  *MK_FP(v3, _errno_0()) = 22;
  JUMPOUT(0x3F635648);
}

//------------------------------------------------------------------------------
// Address: 0x3F635719
// Name: public: static int UnDecorator::doFunctionReturns(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::doFunctionReturns(char a1@<sf>, char a2@<of>, _DWORD *a3@<eax>, int a4@<ebx>)
{
  if ( a1 != a2 )
  {
    isspace_0(C: (unsigned __int8)a3);
    UnDecorator::doAllocationModel();
  }
  else
  {
    UnDecorator::doUnderScore(a1: a3, a2: a4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F635727
// Name: public: static int UnDecorator::doAllocationModel(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::doAllocationModel(char a1@<zf>, int a2@<ebp>)
{
  int v2; // [esp-4h] [ebp-4h]

  if ( !a1 )
  {
    v2 = *(_DWORD *)(a2 - 20);
    --*(_DWORD *)(a2 + 4);
    _whiteout(a1: v2);
    JUMPOUT(0x3F635737);
  }
  JUMPOUT(0x3F63575C);
}

//------------------------------------------------------------------------------
// Address: 0x3F635743
// Name: public: static int UnDecorator::doThisTypes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall UnDecorator::doThisTypes@<eax>(int a1@<edi>)
{
  isspace_0(C: *(unsigned __int8 *)(a1 + 1));
  return UnDecorator::doAccessSpecifiers();
}

//------------------------------------------------------------------------------
// Address: 0x3F635755
// Name: public: static int UnDecorator::doAccessSpecifiers(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::doAccessSpecifiers(char a1@<zf>)
{
  if ( !a1 )
    JUMPOUT(0x3F635748);
  JUMPOUT(0x3F6361A1);
}

//------------------------------------------------------------------------------
// Address: 0x3F635771
// Name: public: static int UnDecorator::doMemberTypes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn UnDecorator::doMemberTypes()
{
  __asm { aam     89h }
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F63577F
// Name: public: static int UnDecorator::doNameOnly(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::doNameOnly(char a1@<al>, int a2@<ebp>)
{
  *(_BYTE *)(a2 + 3) = a1;
  *(_BYTE *)(a2 - 22) = a1;
  *(_BYTE *)(a2 - 5) = a1;
  JUMPOUT(0x3F635788);
}

//------------------------------------------------------------------------------
// Address: 0x3F63578A
// Name: public: static int UnDecorator::doTypeOnly(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall UnDecorator::doTypeOnly(void *_ECX)
{
  __asm { repne add [ecx-9CC47BBh], ecx }
  return UnDecorator::haveTemplateParameters();
}

//------------------------------------------------------------------------------
// Address: 0x3F635795
// Name: public: static int UnDecorator::haveTemplateParameters(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall UnDecorator::haveTemplateParameters@<eax>(unsigned __int8 a1@<bl>)
{
  isdigit_0(C: a1);
  return UnDecorator::doEcsu();
}

//------------------------------------------------------------------------------
// Address: 0x3F6357A0
// Name: public: static int UnDecorator::doEcsu(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::doEcsu(char a1@<zf>, int a2@<ebp>)
{
  if ( !a1 )
  {
    ++*(_DWORD *)(a2 - 44);
    JUMPOUT(0x3F6357AC);
  }
  JUMPOUT(0x3F6357B8);
}

//------------------------------------------------------------------------------
// Address: 0x3F6357AE
// Name: public: static int UnDecorator::doNoIdentCharCheck(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::doNoIdentCharCheck(char a1@<cf>, int a2@<eax>, char a3@<dl>, int a4@<ebp>)
{
  LOBYTE(a2) = a2 - (a1 + a3);
  *(_DWORD *)(a4 - 12) = a2;
  JUMPOUT(0x3F635858);
}

//------------------------------------------------------------------------------
// Address: 0x3F6357B9
// Name: public: static int UnDecorator::doEllipsis(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::doEllipsis(int a1@<esi>)
{
  _enable();
  if ( a1 <= 1 )
  {
    if ( a1 != 1 )
      JUMPOUT(0x3F6357C6);
    JUMPOUT(0x3F635858);
  }
  JUMPOUT(0x3F63582E);
}

//------------------------------------------------------------------------------
// Address: 0x3F6357C7
// Name: public: static char const __near * UnDecorator::UScore(enum Tokens)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl UnDecorator::UScore()
{
  int v0; // [esp-14h] [ebp-14h]
  int v1; // [esp-Ch] [ebp-Ch]

  if ( v0 != 70 )
  {
    if ( v0 == 73 )
      JUMPOUT(0x3F6357E0);
    if ( v0 != 76 )
      JUMPOUT(0x3F63583D);
    ++*(_BYTE *)(v1 - 14);
  }
  JUMPOUT(0x3F635858);
}

//------------------------------------------------------------------------------
// Address: 0x3F6357E0
// Name: public: void __near * HeapManager::getMemory(unsigned int,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge HeapManager::getMemory(
        HeapManager *this@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        unsigned int sz,
        int noBuffer)
{
  char v6; // cl

  v6 = *(_BYTE *)(a3 + 1);
  if ( v6 == 54 && *(_BYTE *)(a3 + 2) == 52 )
  {
    ++*(_DWORD *)(a2 - 72);
    *(_DWORD *)(a2 - 52) = a4;
    *(_DWORD *)(a2 - 48) = a4;
  }
  else if ( (v6 != 51 || *(_BYTE *)(a3 + 2) != 50) && v6 != 100 && v6 != 105 && v6 != 111 && v6 != 120 && v6 != 88 )
  {
    ++*(_BYTE *)(a2 + 3);
  }
  if ( *(_BYTE *)(a2 + 3) != 0 )
    JUMPOUT(0x3F635862);
  JUMPOUT(0x3F635791);
}

//------------------------------------------------------------------------------
// Address: 0x3F635864
// Name: public: DName::DName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::DName(DName *this)
{
  __asm { rep add [this+0E75D87Dh], cl }
  JUMPOUT(0x3F635870);
}

//------------------------------------------------------------------------------
// Address: 0x3F635871
// Name: public: DName::DName(class DNameNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::DName(DName *this@<ecx>, int a2@<eax>, int a3@<ebp>, int a4@<esi>, DNameNode *pd)
{
  int v5; // ebp

  v5 = a3 + 1;
  *(_DWORD *)(v5 - 88) = a2 + 4;
  *(_DWORD *)(v5 - 56) = a4;
  JUMPOUT(0x3F635880);
}

//------------------------------------------------------------------------------
// Address: 0x3F635883
// Name: public: DName::DName(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::DName(DName *this@<ecx>, char a2@<dh>, int a3@<ebp>, char *a4@<edi>, const DName *rd)
{
  char v5; // al
  int v6; // ebx
  int v7; // eax
  FILE *v8; // edx

  *(_BYTE *)(a3 + 18) += a2;
  v5 = *a4;
  if ( *a4 == 83 || (*(_BYTE *)(a3 - 5) = -1, v5 == 67) )
    *(_BYTE *)(a3 - 5) = 1;
  v6 = (unsigned __int8)*a4 | 0x20;
  *(_DWORD *)(a3 - 32) = v6;
  if ( v6 == 110
    || (v6 == 99 || v6 == 123
      ? (v8 = *(FILE **)(a3 - 20), ++*(_DWORD *)(a3 + 4), v7 = _inc(a1: (int)this, a2: v8))
      : (v7 = _whiteout(a1: *(_DWORD *)(a3 - 20))),
        *(_DWORD *)(a3 - 4) = v7,
        v7 != -1) )
  {
    if ( *(_DWORD *)(a3 - 44) == 0 || *(_DWORD *)(a3 - 12) != 0 )
    {
      if ( v6 <= 111 )
      {
        if ( v6 != 111 )
        {
          if ( v6 == 99 )
            JUMPOUT(0x3F635BEA);
          if ( v6 != 100 )
          {
            if ( v6 > 100 )
            {
              if ( v6 > 103 )
              {
                if ( v6 != 105 )
                  JUMPOUT(0x3F63591F);
                JUMPOUT(0x3F63593A);
              }
              JUMPOUT(0x3F635952);
            }
            JUMPOUT(0x3F635D22);
          }
        }
        JUMPOUT(0x3F635F23);
      }
      JUMPOUT(0x3F635CF8);
    }
    JUMPOUT(0x3F6361AD);
  }
  JUMPOUT(0x3F6361D5);
}

//------------------------------------------------------------------------------
// Address: 0x3F63591F
// Name: public: enum DNameStatus DName::status(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::status(DName *this@<ecx>, int a2@<ebx>)
{
  if ( a2 == 110 )
    JUMPOUT(0x3F635928);
  JUMPOUT(0x3F635D22);
}

//------------------------------------------------------------------------------
// Address: 0x3F635929
// Name: public: void DName::clearStatus(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::clearStatus(DName *this@<ecx>, char a2@<sf>, char a3@<of>)
{
  if ( a2 != a3 )
    JUMPOUT(0x3F63592B);
  JUMPOUT(0x3F63591E);
}

//------------------------------------------------------------------------------
// Address: 0x3F63592E
// Name: public: class DName __near & DName::setPtrRef(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::setPtrRef(DName *this)
{
  JUMPOUT(0x3F635933);
}

//------------------------------------------------------------------------------
// Address: 0x3F635935
// Name: public: int DName::isPtrRef(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall DName::isPtrRef(DName *this, int a2)
{
  JUMPOUT(0x3F63613D);
}

//------------------------------------------------------------------------------
// Address: 0x3F63593F
// Name: public: void DName::setIsArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::setIsArray(DName *this@<ecx>, int a2@<ebx>)
{
  if ( a2 == 45 )
    JUMPOUT(0x3F635949);
  JUMPOUT(0x3F635E0B);
}

//------------------------------------------------------------------------------
// Address: 0x3F635951
// Name: public: int DName::isNoTE(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::isNoTE(DName *this@<ecx>, char a2@<dh>, _BYTE *a3@<ebx>)
{
  *a3 += a2;
  JUMPOUT(0x3F635959);
}

//------------------------------------------------------------------------------
// Address: 0x3F63595B
// Name: public: void DName::setIsNoTE(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::setIsNoTE(DName *this)
{
  __asm { fadd    st(6), st }
  JUMPOUT(0x3F63595E);
}

//------------------------------------------------------------------------------
// Address: 0x3F635963
// Name: public: int DName::isPinPtr(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::isPinPtr(DName *this@<ecx>, int a2@<ebp>)
{
  if ( *(_DWORD *)(a2 - 4) == 43 )
  {
    --*(_DWORD *)(a2 - 12);
    JUMPOUT(0x3F63596C);
  }
  JUMPOUT(0x3F63597E);
}

//------------------------------------------------------------------------------
// Address: 0x3F63596D
// Name: public: void DName::setIsPinPtr(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::setIsPinPtr(DName *this@<ecx>, FILE *a2@<edx>, int a3@<ebp>)
{
  __inbyte((unsigned __int16)a2);
  ++*(_DWORD *)(a3 + 4);
  _inc(a1: (int)this, a2);
  JUMPOUT(0x3F635977);
}

//------------------------------------------------------------------------------
// Address: 0x3F63597F
// Name: public: void DName::setIsComArray(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall __noreturn DName::setIsComArray(DName *this)
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F635987
// Name: public: int DName::isVCallThunk(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::isVCallThunk(DName *this)
{
  JUMPOUT(0x3F6359D1);
}

//------------------------------------------------------------------------------
// Address: 0x3F635991
// Name: public: void DName::setIsVCallThunk(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::setIsVCallThunk(DName *this@<ecx>, int a2@<eax>)
{
  *(_BYTE *)(a2 + 2 * (_DWORD)this - 118) *= 32;
  JUMPOUT(0x3F635997);
}

//------------------------------------------------------------------------------
// Address: 0x3F635999
// Name: public: class DName __near & DName::operator=(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator=(DName *this@<ecx>, int a2@<ebx>, int a3@<ebp>, const DName *rd)
{
  int v4; // ebp
  int v5; // ecx
  FILE *v6; // edx
  int v7; // eax
  char v8; // al
  bool v9; // zf
  int v10; // eax
  FILE *v11; // edx
  int v12; // [esp-4h] [ebp-4h]

  __asm { fdiv    st(7), st }
  v4 = a3 + 1;
  __inbyte(0x88u);
  if ( __check_float_string(
         a1: (void **)(v4 - 36),
         a2: (size_t *)(v4 - 76),
         a3: a2 + 1,
         Src: (void *)(v4 + 8),
         a5: (_DWORD *)(v4 - 68)) != 0 )
  {
    v6 = *(FILE **)(v4 - 20);
    ++*(_DWORD *)(v4 + 4);
    v7 = _inc(a1: v5, a2: v6);
    *(_DWORD *)(v4 - 4) = v7;
    if ( isdigit_0(C: (unsigned __int8)v7) == 0 )
    {
      v8 = ***(_BYTE ***)(*(_DWORD *)(v4 - 108) + 188);
      v9 = v8 == *(_BYTE *)(v4 - 4);
      *(_BYTE *)(v4 - 24) = v8;
      if ( v9 )
      {
        v10 = *(_DWORD *)(v4 - 12);
        *(_DWORD *)(v4 - 12) = v10 - 1;
        if ( v10 != 0 )
        {
          v11 = *(FILE **)(v4 - 20);
          ++*(_DWORD *)(v4 + 4);
          *(_DWORD *)(v4 - 4) = _inc(a1: v12, a2: v11);
          JUMPOUT(0x3F635A14);
        }
      }
      JUMPOUT(0x3F635A92);
    }
    JUMPOUT(0x3F63598A);
  }
  JUMPOUT(0x3F6361D5);
}

//------------------------------------------------------------------------------
// Address: 0x3F635A14
// Name: public: int Replicator::isFull(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall Replicator::isFull(Replicator *this@<ecx>, int a2@<ebx>, int a3@<ebp>)
{
  *((_BYTE *)&this->index + a2) = *(_BYTE *)(a3 - 24);
  JUMPOUT(0x3F635A1D);
}

//------------------------------------------------------------------------------
// Address: 0x3F635A1D
// Name: public: class DName const __near & Replicator::operator[](int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge Replicator::operator[](Replicator *this@<ecx>, _DWORD *a2@<eax>, int a3@<ebx>, int a4@<ebp>, int x)
{
  if ( __check_float_string(a1: (void **)(a4 - 36), a2: (size_t *)(a4 - 76), a3: a3 + 1, Src: (void *)(a4 + 8), a5: a2) != 0 )
    JUMPOUT(0x3F635A87);
  JUMPOUT(0x3F6361D5);
}

//------------------------------------------------------------------------------
// Address: 0x3F635A42
// Name: protected: DNameNode::DNameNode(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall __noreturn DNameNode::DNameNode(DNameNode *this)
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F635A4F
// Name: public: class DNameNode __near * DNameNode::nextNode(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DNameNode::nextNode(DNameNode *this@<ecx>, int a2@<ebp>)
{
  ++*(_DWORD *)(a2 - 28);
  JUMPOUT(0x3F635A53);
}

//------------------------------------------------------------------------------
// Address: 0x3F635A53
// Name: public: class DNameNode __near & DNameNode::operator+=(class DNameNode __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
charNode *__userpurge DNameNode::operator+=@<eax>(
        DNameNode *this@<ecx>,
        int a2@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        DNameNode *pNode)
{
  charNode *v5; // ecx

  *(_BYTE *)(a3 + a2) = (_BYTE)this;
  if ( __check_float_string(
         a1: (void **)(a4 - 36),
         a2: (size_t *)(a4 - 76),
         a3: a3 + 1,
         Src: (void *)(a4 + 8),
         a5: (_DWORD *)(a4 - 68)) == 0 )
    JUMPOUT(0x3F6361D5);
  ++*(_DWORD *)(a4 + 4);
  return charNode::charNode(this: v5, ch: (char)pNode);
}

//------------------------------------------------------------------------------
// Address: 0x3F635A7C
// Name: public: charNode::charNode(char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge charNode::charNode(charNode *this@<ecx>, FILE *a2@<edx>, int a3@<ebp>, char ch)
{
  int v4; // eax

  v4 = _inc(a1: (int)this, a2);
  *(_DWORD *)(a3 - 4) = v4;
  if ( isdigit_0(C: (unsigned __int8)v4) == 0 )
    JUMPOUT(0x3F635A92);
  JUMPOUT(0x3F635A40);
}

//------------------------------------------------------------------------------
// Address: 0x3F635A92
// Name: public: virtual int charNode::length(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __thiscall charNode::length(charNode *this)
{
  return charNode::getLastChar(this);
}

//------------------------------------------------------------------------------
// Address: 0x3F635A96
// Name: public: virtual char charNode::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall charNode::getLastChar(charNode *this@<ecx>, char a2@<zf>)
{
  if ( !a2 )
    JUMPOUT(0x3F635A9C);
  JUMPOUT(0x3F635B92);
}

//------------------------------------------------------------------------------
// Address: 0x3F635AB5
// Name: public: pDNameNode::pDNameNode(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall pDNameNode::pDNameNode(pDNameNode *this, DName *pName)
{
  JUMPOUT(0x3F635AB7);
}

//------------------------------------------------------------------------------
// Address: 0x3F635AE4
// Name: public: DNameStatusNode::DNameStatusNode(enum DNameStatus)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F635B09
// Name: public: virtual int DNameStatusNode::length(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DNameStatusNode::length(DNameStatusNode *this@<ecx>, int a2@<ebx>)
{
  ++*(_DWORD *)(a2 - 1065022268);
  JUMPOUT(0x3F635B0F);
}

//------------------------------------------------------------------------------
// Address: 0x3F635B1A
// Name: und_strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall und_strlen(int a1@<ebp>)
{
  int v2; // eax

  v2 = *(_DWORD *)(a1 - 12);
  *(_DWORD *)(a1 - 12) = v2 - 1;
  if ( v2 == 0 )
    JUMPOUT(0x3F635B27);
  JUMPOUT(0x3F635B2C);
}

//------------------------------------------------------------------------------
// Address: 0x3F635B28
// Name: und_strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __noreturn und_strncpy()
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F635B48
// Name: und_strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall und_strncmp(char a1@<zf>, int a2@<ebx>, int a3@<ebp>)
{
  int v5; // eax
  char v6; // cl

  if ( !a1 )
  {
    v5 = *(_DWORD *)(a3 - 36);
    v6 = *(_BYTE *)(a3 - 4);
    ++*(_DWORD *)(a3 - 28);
    *(_BYTE *)(a2 + v5) = v6;
    __check_float_string(
      a1: (void **)(a3 - 36),
      a2: (size_t *)(a3 - 76),
      a3: a2 + 1,
      Src: (void *)(a3 + 8),
      a5: (_DWORD *)(a3 - 68));
    JUMPOUT(0x3F635B6B);
  }
  JUMPOUT(0x3F635B92);
}

//------------------------------------------------------------------------------
// Address: 0x3F635B6D
// Name: private: static class DName UnDecorator::getDataIndirectType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::getDataIndirectType(_BYTE *a1@<edi>)
{
  *a1 = __ROR1__(*a1, 132);
  JUMPOUT(0x3F635B74);
}

//------------------------------------------------------------------------------
// Address: 0x3F635BA0
// Name: private: static class DName UnDecorator::getThisType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F635BD4
// Name: void __near * operator new(unsigned int,class HeapManager __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator new()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_decode_pointer_0(a1: s_NoEscConversion.m_pReplacements[199].m_pReplacementString);
  v0();
  JUMPOUT(0x3F635BE5);
}

//------------------------------------------------------------------------------
// Address: 0x3F635BE7
// Name: public: DName::DName(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::DName(DName *this@<ecx>, int a2@<eax>, int a3@<ebp>, DName *pd)
{
  int v4; // eax
  FILE *v5; // edx
  DName *v6; // [esp-4h] [ebp-4h]

  if ( a2 == 914030592 )
  {
    ++*(_DWORD *)(a3 - 12);
    *(_DWORD *)(a3 - 44) = 1;
  }
  if ( *(char *)(a3 - 5) > 0 )
    *(_BYTE *)(a3 - 22) = 1;
  --*(_DWORD *)(a3 + 4);
  if ( *(_DWORD *)(a3 - 4) != -1 )
  {
    _ungetc_nolock_0(Character: *(_DWORD *)(a3 - 4), Stream: *(FILE **)(a3 - 20));
    this = v6;
  }
  if ( *(_DWORD *)(a3 - 44) == 0 || (v4 = *(_DWORD *)(a3 - 12), *(_DWORD *)(a3 - 12) = v4 - 1, v4 != 0) )
  {
    v5 = *(FILE **)(a3 - 20);
    ++*(_DWORD *)(a3 + 4);
    _inc(a1: (int)this, a2: v5);
    JUMPOUT(0x3F635C3C);
  }
  JUMPOUT(0x3F635EE7);
}

//------------------------------------------------------------------------------
// Address: 0x3F635C3D
// Name: public: DName::DName(enum DNameStatus)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::DName(DName *this@<ecx>, int a2@<eax>, int a3@<ebx>, int a4@<ebp>, DNameStatus st)
{
  int v5; // ebp

  v5 = a4 + 1;
  if ( v5 != 0 )
  {
    if ( a3 == 99 )
      goto LABEL_9;
    if ( a3 == 115 )
    {
      if ( a2 >= 9 && a2 <= 13 )
        goto LABEL_16;
      if ( a2 != 32 )
      {
LABEL_9:
        if ( *(_BYTE *)(v5 - 13) == 0 )
          JUMPOUT(0x3F635C9D);
        JUMPOUT(0x3F635ECE);
      }
    }
    if ( a3 == 123 && ((1 << (a2 & 7)) & (*(char *)(v5 - 24) ^ *(char *)(v5 + (a2 >> 3) + 360))) != 0 )
      goto LABEL_9;
  }
LABEL_16:
  JUMPOUT(0x3F635ED4);
}

//------------------------------------------------------------------------------
// Address: 0x3F635C9E
// Name: public: int DName::isValid(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::isValid(DName *this@<ecx>, char a2@<sf>, char a3@<of>, _BYTE *a4@<edi>)
{
  if ( a2 != a3 )
  {
    *a4 += (_BYTE)this;
    JUMPOUT(0x3F635CA5);
  }
  JUMPOUT(0x3F635C8A);
}

//------------------------------------------------------------------------------
// Address: 0x3F635CB5
// Name: public: int DName::isEmpty(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall DName::isEmpty@<eax>(DName *this@<ecx>, char a2@<zf>, int a3@<ebp>)
{
  DName *v3; // ecx
  FILE *v4; // edx
  int v6; // [esp-4h] [ebp-4h]

  v3 = (DName *)v6;
  if ( !a2 )
  {
    v4 = *(FILE **)(a3 - 20);
    ++*(_DWORD *)(a3 + 4);
    *(_BYTE *)(a3 - 79) = _inc(a1: v6, a2: v4);
  }
  return DName::isUDC(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x3F635CCA
// Name: public: int DName::isUDC(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F635CDE
// Name: public: void DName::setIsUDC(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F635CEC
// Name: public: int DName::isUDTThunk(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::isUDTThunk(DName *this@<ecx>, __int16 a2@<ax>, _WORD *a3@<esi>)
{
  *a3 = a2;
  JUMPOUT(0x3F635EC6);
}

//------------------------------------------------------------------------------
// Address: 0x3F635D00
// Name: public: int DName::length(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::length(DName *this@<ecx>, _BYTE *a2@<eax>, unsigned __int16 a3@<dx>, int a4@<ebx>)
{
  *(_BYTE *)(a4 - 2079390744) += *a2 + (_BYTE)a2;
  __inbyte(a3);
  JUMPOUT(0x3F635D09);
}

//------------------------------------------------------------------------------
// Address: 0x3F635D25
// Name: public: char DName::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DName::getLastChar(DName *this@<ecx>, int a2@<eax>, int a3@<ebp>)
{
  if ( a2 == *(_DWORD *)(a3 - 4) )
  {
    --*(_BYTE *)(a3 - 21);
    if ( *(_BYTE *)(a3 - 13) == 0 )
      *(_DWORD *)(a3 - 88) = *(_DWORD *)(a3 - 112);
    JUMPOUT(0x3F63613D);
  }
  JUMPOUT(0x3F6361AD);
}

//------------------------------------------------------------------------------
// Address: 0x3F635D5D
// Name: public: char __near * DName::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall DName::getString(DName *this, char *buf, char *max)
{
  MEMORY[0xCC83C861](a1: this);
  JUMPOUT(0x3F635D65);
}

//------------------------------------------------------------------------------
// Address: 0x3F635DEE
// Name: public: class DName __near & DName::operator|=(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator|=(
        DName *this@<ecx>,
        char a2@<cf>,
        char a3@<al>,
        int a4@<ebx>,
        int a5@<ebp>,
        int a6@<esi>,
        const DName *rd)
{
  *(_BYTE *)(a4 + 109764701) -= a2 + (_BYTE)this;
  if ( a3 == 93 )
  {
    *(_DWORD *)(a5 - 40) = a6;
    JUMPOUT(0x3F635C02);
  }
  JUMPOUT(0x3F635D88);
}

//------------------------------------------------------------------------------
// Address: 0x3F635E23
// Name: public: class DName __near & DName::operator=(enum DNameStatus)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator=(
        DName *this@<ecx>,
        int a2@<eax>,
        FILE *a3@<edx>,
        int a4@<ebp>,
        _BYTE *a5@<edi>,
        DNameStatus st)
{
  int v6; // ebp
  int v7; // eax
  int v8; // ecx
  bool v9; // zf
  FILE *v10; // edx

  v6 = a4 + 1;
  LOBYTE(a2) = a2 - 24;
  MEMORY[0x8BFFFFF7] = a2;
  __asm { fmul    dword ptr [this-47C03A3h] }
  *a5 ^= (unsigned __int8)this;
  __inbyte((unsigned __int16)a3);
  ++*(_DWORD *)(v6 + 4);
  v7 = _inc(a1: (int)this, a2: a3);
  *(_DWORD *)(v6 - 4) = v7;
  if ( (_BYTE)v7 != 120 && (_BYTE)v7 != 88 )
  {
    v9 = *(_DWORD *)(v6 - 32) == 120;
    *(_DWORD *)(v6 - 28) = 1;
    if ( !v9 )
    {
      if ( *(_DWORD *)(v6 - 44) != 0 )
      {
        v9 = (*(_DWORD *)(v6 - 12))-- == 1;
        if ( v9 )
          ++*(_BYTE *)(v6 + 3);
      }
      *(_DWORD *)(v6 - 32) = 111;
      JUMPOUT(0x3F635F55);
    }
    --*(_DWORD *)(v6 + 4);
    if ( v7 != -1 )
      _ungetc_nolock_0(Character: v7, Stream: *(FILE **)(v6 - 20));
    JUMPOUT(0x3F635F52);
  }
  v10 = *(FILE **)(v6 - 20);
  ++*(_DWORD *)(v6 + 4);
  _inc(a1: v8, a2: v10);
  JUMPOUT(0x3F635EA3);
}

//------------------------------------------------------------------------------
// Address: 0x3F635EA4
// Name: public: Replicator::Replicator(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall Replicator::Replicator(Replicator *this@<ecx>, int a2@<ebp>)
{
  __asm { fmul    dword ptr [this+0D74FC5Dh] }
  *(_DWORD *)(a2 - 12) -= 2;
  if ( *(int *)(a2 - 12) < 1 )
    ++*(_BYTE *)(a2 + 3);
  *(_DWORD *)(a2 - 32) = 120;
  JUMPOUT(0x3F635EBE);
}

//------------------------------------------------------------------------------
// Address: 0x3F635EC2
// Name: public: class Replicator __near & Replicator::operator+=(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge Replicator::operator+=(Replicator *this@<ecx>, int a2@<eax>, const DName *rd)
{
  *(_BYTE *)(a2 + 1971930630) += (_BYTE)this;
  JUMPOUT(0x3F635ECC);
}

//------------------------------------------------------------------------------
// Address: 0x3F635F09
// Name: public: class DNameNode __near * DNameNode::clone(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall DNameNode::clone(DNameNode *this@<ecx>, char a2@<zf>, int a3@<ebp>)
{
  _BYTE *v3; // eax

  v3 = *(_BYTE **)(a3 - 56);
  if ( a2 )
    *v3 = 0;
  else
    *(_WORD *)v3 = 0;
  JUMPOUT(0x3F63613D);
}

//------------------------------------------------------------------------------
// Address: 0x3F635F50
// Name: public: pcharNode::pcharNode(char const __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
pcharNode *__userpurge pcharNode::pcharNode@<eax>(
        pcharNode *this@<ecx>,
        int a2@<eax>,
        int a3@<ebp>,
        char *str,
        int len)
{
  pcharNode *v6; // ecx
  DNameStatusNode *v8; // ecx

  *(_DWORD *)(a3 - 4) = a2;
  if ( *(_DWORD *)(a3 - 72) == 0 )
    JUMPOUT(0x3F63605A);
  if ( *(_BYTE *)(a3 + 3) == 0 )
  {
    if ( *(_DWORD *)(a3 - 32) == 120 || *(_DWORD *)(a3 - 32) == 112 )
    {
      isxdigit_0(C: (unsigned __int8)a2);
      return (pcharNode *)pcharNode::getString(this: v6, buf: str, len);
    }
    if ( isdigit_0(C: (unsigned __int8)a2) != 0 )
    {
      if ( *(_DWORD *)(a3 - 32) != 111 )
        JUMPOUT(0x3F635FB7);
      if ( a2 < 56 )
      {
        *(_DWORD *)(a3 - 48) = *(_QWORD *)(a3 - 52) >> 29;
        JUMPOUT(0x3F635FF3);
      }
    }
    --*(_DWORD *)(a3 + 4);
    if ( a2 != -1 )
    {
      _ungetc_nolock_0(Character: a2, Stream: *(FILE **)(a3 - 20));
      return (pcharNode *)DNameStatusNode::getString(this: v8, buf: str, len);
    }
  }
  JUMPOUT(0x3F636035);
}

//------------------------------------------------------------------------------
// Address: 0x3F635FC7
// Name: public: virtual char __near * pcharNode::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__userpurge pcharNode::getString@<eax>(
        pcharNode *this@<ecx>,
        int a2@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        int a5@<edi>,
        char *buf,
        int len)
{
  DNameStatusNode *v7; // ecx

  if ( a2 != 0 )
  {
    *(_DWORD *)(a4 - 48) = *(_QWORD *)(a4 - 52) >> 28;
    a3 = (char)a3;
    if ( isdigit_0(C: a5) == 0 )
      a3 = ((char)a3 & 0xFFFFFFDF) - 7;
    *(_DWORD *)(a4 - 4) = a3;
    ++*(_DWORD *)(a4 - 28);
    JUMPOUT(0x3F635FF6);
  }
  --*(_DWORD *)(a4 + 4);
  if ( a3 == -1 )
    JUMPOUT(0x3F636035);
  _ungetc_nolock_0(Character: a3, Stream: *(FILE **)(a4 - 20));
  return DNameStatusNode::getString(this: v7, buf, len);
}

//------------------------------------------------------------------------------
// Address: 0x3F635FF8
// Name: public: virtual int pDNameNode::length(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall pDNameNode::length(pDNameNode *this@<ecx>, char a2@<zf>, int a3@<ebx>)
{
  __asm { rcr     byte ptr [this+5511F003h], 1 }
  *(_BYTE *)(a3 - 1996434307) = __ROL1__(*(_BYTE *)(a3 - 1996434307), 1);
  if ( a2 )
    JUMPOUT(0x3F636006);
  JUMPOUT(0x3F635FD2);
}

//------------------------------------------------------------------------------
// Address: 0x3F636007
// Name: public: virtual char pDNameNode::getLastChar(void)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall pDNameNode::getLastChar(pDNameNode *this@<ecx>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 1174400085) -= (_BYTE)this;
  JUMPOUT(0x3F636016);
}

//------------------------------------------------------------------------------
// Address: 0x3F636033
// Name: public: virtual char __near * DNameStatusNode::getString(char __near *,int)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge DNameStatusNode::getString(DNameStatusNode *this@<ecx>, int a2@<ebp>, char *buf, int len)
{
  int v4; // ecx

  if ( *(_BYTE *)(a2 - 23) != 0 )
  {
    v4 = -*(_QWORD *)(a2 - 52) >> 32;
    *(_DWORD *)(a2 - 52) = -*(_DWORD *)(a2 - 52);
    *(_DWORD *)(a2 - 48) = v4;
  }
  JUMPOUT(0x3F6360FD);
}

//------------------------------------------------------------------------------
// Address: 0x3F636066
// Name: public: UnDecorator::UnDecorator(char __near *,char const __near *,int,char __near * (*)(long),unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge UnDecorator::UnDecorator(
        UnDecorator *this@<ecx>,
        int a2@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        char *output,
        char *dName,
        DName *maxLen,
        char *(__cdecl *pGetParameter)(int),
        char *(__cdecl *disable)(int))
{
  bool v9; // zf
  FILE *v10; // edx
  int v11; // [esp-4h] [ebp-4h]

  *(_BYTE *)(a3 + 1954078845) += a2;
  *(_DWORD *)(a3 + 1953554557) -= a2;
  if ( isdigit_0(C: a2) == 0 || *(_DWORD *)(a4 - 32) == 111 && a3 >= 56 )
  {
    --*(_DWORD *)(a4 + 4);
    if ( a3 != -1 )
      _ungetc_nolock_0(Character: a3, Stream: *(FILE **)(a4 - 20));
  }
  else
  {
    ++*(_DWORD *)(a4 - 28);
    if ( *(_DWORD *)(a4 - 44) == 0 || (v9 = *(_DWORD *)(a4 - 12) == 1, --*(_DWORD *)(a4 - 12), !v9) )
    {
      v10 = *(FILE **)(a4 - 20);
      ++*(_DWORD *)(a4 + 4);
      _inc(a1: v11, a2: v10);
      JUMPOUT(0x3F6360DB);
    }
  }
  if ( *(_DWORD *)(a4 - 32) == 70 )
    *(_DWORD *)(a4 - 28) = 0;
  JUMPOUT(0x3F636107);
}

//------------------------------------------------------------------------------
// Address: 0x3F636108
// Name: private: static class DName UnDecorator::getStorageConvention(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getStorageConvention(char a1@<sf>, char a2@<of>, char a3@<cl>, _BYTE *a4@<edi>)
{
  if ( a1 != a2 )
  {
    *a4 += a3;
    JUMPOUT(0x3F63610E);
  }
  JUMPOUT(0x3F6360EE);
}

//------------------------------------------------------------------------------
// Address: 0x3F636117
// Name: public: class DName __near & DName::operator+=(enum DNameStatus)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+=(DName *this@<ecx>, int a2@<ebp>, int a3@<edi>, DNameStatus st)
{
  _DWORD *v4; // esi
  int v5; // edi

  ++*(_DWORD *)(a2 - 60);
  v4 = *(_DWORD **)(a2 - 56);
  if ( *(_DWORD *)(a2 - 72) != 0 )
  {
    *v4 = *(_DWORD *)(a2 - 52);
    v4[1] = *(_DWORD *)(a2 - 48);
  }
  else if ( *(_BYTE *)(a2 - 14) != 0 )
  {
    *v4 = a3;
  }
  else
  {
    *(_WORD *)v4 = a3;
  }
  v5 = *(_DWORD *)(a2 - 40);
  ++*(_BYTE *)(a2 - 21);
  *(_DWORD *)(a2 - 40) = v5 + 1;
  JUMPOUT(0x3F63618F);
}

//------------------------------------------------------------------------------
// Address: 0x3F636190
// Name: public: class DName __near & DName::operator=(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __userpurge DName::operator=(DName *this@<ecx>, char a2@<cf>, int a3@<eax>, int a4@<ebp>, DName *pd)
{
  *(_BYTE *)(a3 + 1064641855) += a3 + a2;
  if ( *(_BYTE *)(*(_DWORD *)(a4 - 40) + 1) == 110 && **(_BYTE **)(a4 - 40) != 0 )
    JUMPOUT(0x3F63571B);
  if ( *(_DWORD *)(a4 - 68) == 1 )
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a4 - 36));
  if ( *(_DWORD *)(a4 - 4) == -1 )
  {
    if ( *(_DWORD *)(a4 - 60) == 0 && *(_BYTE *)(a4 - 21) == 0 )
      JUMPOUT(0x3F6361F6);
    JUMPOUT(0x3F6361F9);
  }
  if ( *(_BYTE *)(a4 - 96) != 0 )
    *(_DWORD *)(*(_DWORD *)(a4 - 100) + 112) &= ~2u;
  __security_check_cookie`...'(StackCookie: a4 ^ *(_DWORD *)(a4 + 392));
}

//------------------------------------------------------------------------------
// Address: 0x3F636255
// Name: __whiteout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _whiteout@<eax>(int a1@<ecx>, _DWORD *a2@<esi>, FILE *a3)
{
  int v3; // ebx
  int v4; // eax
  int v6; // [esp-4h] [ebp-8h]

  do
  {
    ++*a2;
    v3 = _inc(a1, a2: a3);
    if ( v3 == -1 )
      break;
    v4 = isspace_0(C: (unsigned __int8)v3);
    a1 = v6;
  }
  while ( v4 != 0 );
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x3F63629E
// Name: public: DName::DName(char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__userpurge DName::DName@<eax>(
        DName *this@<ecx>,
        _DWORD *a2@<eax>,
        char a3@<dh>,
        _BYTE *a4@<ebx>,
        int _EDI@<edi>,
        int a6@<esi>,
        const char *c)
{
  BYTE1(this) = -100;
  *a2 += a2;
  *a4 += a3;
  __asm { fist    dword ptr [edi-75h] }
  MEMORY[0x150] = a2;
  MEMORY[0x194] = a6;
  MEMORY[0x184] = _EDI;
  MEMORY[0x18C] = 432;
  MEMORY[0x15C] = 350;
  return DName::DName(this, s: c);
}

//------------------------------------------------------------------------------
// Address: 0x3F6362C4
// Name: public: DName::DName(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::DName(DName *this@<ecx>, char a2@<zf>, int a3@<ebx>, int a4@<ebp>, const char *s)
{
  *(_DWORD *)(a4 - 60) = a3;
  *(_DWORD *)(a4 - 92) = a3;
  *(_DWORD *)(a4 + 4) = a3;
  *(_DWORD *)(a4 - 96) = a3;
  if ( a2 )
  {
    *_errno_0() = 22;
    _invalid_parameter_0();
    JUMPOUT(0x3F636F8D);
  }
  JUMPOUT(0x3F6362F4);
}

//------------------------------------------------------------------------------
// Address: 0x3F6362F5
// Name: public: DName::DName(char const __near * __near &,char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::DName(
        DName *this@<ecx>,
        unsigned __int8 a2@<al>,
        int a3@<ebx>,
        int a4@<ebp>,
        unsigned __int8 *a5@<edi>,
        int a6@<esi>,
        const char **name,
        char terminator)
{
  FILE *v8; // esi
  int *v9; // edi
  _BYTE *v10; // eax
  int *v11; // edi
  char *v12; // eax
  unsigned __int8 v13; // al
  bool v14; // zf

  __asm { fdivr   st(6), st }
  v8 = (FILE *)(a6 + 1);
  if ( (a2 | 0x40) == 0 )
  {
    if ( _fileno_0(Stream: v8) == -1 || _fileno_0(Stream: v8) == -2 )
    {
      v10 = &unk_3F661428;
    }
    else
    {
      v9 = &dword_3F665FE0[_fileno_0(Stream: v8) >> 5];
      v10 = (_BYTE *)(*v9 + 56 * (_fileno_0(Stream: v8) & 0x1F));
    }
    if ( (v10[36] & 0x7F) != 0
      || (_fileno_0(Stream: v8) == -1 || _fileno_0(Stream: v8) == -2
        ? (v12 = (char *)&unk_3F661428)
        : (v11 = &dword_3F665FE0[_fileno_0(Stream: v8) >> 5], v12 = (char *)(*v11 + 56 * (_fileno_0(Stream: v8) & 0x1F))),
          v12[36] < 0) )
    {
      JUMPOUT(0x3F6362D2);
    }
    a5 = *(unsigned __int8 **)(a4 - 28);
  }
  _LocaleUpdate::_LocaleUpdate(this: (_LocaleUpdate *)(a4 - 112), a2: *(struct localeinfo_struct **)(a4 + 420));
  v13 = *a5;
  v14 = *a5 == 0;
  *(_BYTE *)(a4 - 14) = a3;
  *(_DWORD *)(a4 + 12) = a3;
  *(_DWORD *)(a4 - 52) = a3;
  if ( !v14 )
  {
    if ( isspace_0(C: v13) != 0 )
      JUMPOUT(0x3F6363C3);
    if ( **(_BYTE **)(a4 - 28) == 37 )
    {
      *(_DWORD *)(a4 - 40) = 0;
      *(_BYTE *)(a4 - 61) = 0;
      *(_DWORD *)(a4 - 24) = 0;
      *(_DWORD *)(a4 - 48) = 0;
      *(_DWORD *)(a4 - 4) = 0;
      *(_DWORD *)(a4 - 56) = 0;
      *(_BYTE *)(a4 - 15) = 0;
      *(_BYTE *)(a4 - 16) = 0;
      *(_BYTE *)(a4 + 2) = 0;
      *(_BYTE *)(a4 + 11) = 0;
      *(_BYTE *)(a4 - 13) = 0;
      JUMPOUT(0x3F63642E);
    }
    JUMPOUT(0x3F636E3A);
  }
  JUMPOUT(0x3F636F7D);
}

//------------------------------------------------------------------------------
// Address: 0x3F6364C4
// Name: public: class DName DName::operator+(enum DNameStatus)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+(DName *this@<ecx>, int a2@<ebp>, DName *result, DNameStatus st)
{
  if ( (_BYTE)this != 88 )
    ++*(_BYTE *)(a2 + 11);
  JUMPOUT(0x3F636500);
}

//------------------------------------------------------------------------------
// Address: 0x3F6364F2
// Name: public: class DName __near & DName::operator+=(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+=(DName *this@<ecx>, _BYTE *a2@<ebp>, char *a3@<esi>, const DName *rd)
{
  bool v4; // zf
  int *v5; // eax
  int v6; // ebx
  char v7; // al
  int v8; // edi

  ++*(a2 - 5);
  ++a2[3];
  if ( a2[11] != 0 )
  {
    v4 = a2[2] == 0;
    *((_DWORD *)a2 - 7) = a3;
    if ( v4 )
    {
      v5 = *((int **)a2 - 20);
      v6 = *v5;
      *((_DWORD *)a2 - 22) = v5;
      *((_DWORD *)a2 - 20) = v5 + 1;
    }
    else
    {
      v6 = 0;
    }
    v4 = a2[3] == 0;
    *((_DWORD *)a2 - 11) = v6;
    a2[11] = 0;
    if ( v4 )
    {
      v7 = *a3;
      if ( *a3 == 83 || (a2[3] = -1, v7 == 67) )
        a2[3] = 1;
    }
    v8 = (unsigned __int8)*a3 | 0x20;
    *((_DWORD *)a2 - 21) = v8;
    if ( v8 != 110 )
      JUMPOUT(0x3F636552);
    JUMPOUT(0x3F63658A);
  }
  JUMPOUT(0x3F636439);
}

//------------------------------------------------------------------------------
// Address: 0x3F636554
// Name: public: class DName __near & DName::operator+=(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+=(DName *this@<ecx>, int _EDX@<edx>, int _EBX@<ebx>, __int16 _SI@<si>, DName *pd)
{
  __asm { arpl    [ebx+edx-7Dh], si }
  JUMPOUT(0x3F636558);
}

//------------------------------------------------------------------------------
// Address: 0x3F6365DF
// Name: public: class DName __near & DName::operator=(char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F6365FB
// Name: public: class DName __near & DName::operator=(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__userpurge DName::operator=@<eax>(DName *this@<ecx>, int a2@<edi>, const char *str)
{
  return (*(DName *(__thiscall **)(DName *, const char *))(a2 + 126))(a1: this, a2: str);
}

//------------------------------------------------------------------------------
// Address: 0x3F6366CB
// Name: private: static class DName UnDecorator::getVCallThunkType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getVCallThunkType(char a1@<al>, int a2@<edx>, char a3@<cl>, int a4@<ebx>, int a5@<ebp>)
{
  bool v5; // zf
  int v6; // eax
  FILE *v7; // edx
  int v8; // eax
  int v9; // ecx

  v5 = a3 + *(_BYTE *)(a2 + 71645696) == 0;
  *(_BYTE *)(a2 + 71645696) += a3;
  *(_BYTE *)(a5 - 15) = a1;
  if ( v5 )
  {
    v6 = *(_DWORD *)(a5 - 4);
    *(_DWORD *)(a5 - 4) = v6 - 1;
    if ( v6 != 0 )
    {
      v7 = *(FILE **)(a5 - 12);
      ++*(_DWORD *)(a5 + 12);
      v8 = _inc(a1: a3, a2: v7);
      v9 = *(_DWORD *)(a5 - 20);
      *(_DWORD *)(a5 + 4) = v8;
      *(_BYTE *)(a4 + v9) = *(_BYTE *)(a5 - 15);
      JUMPOUT(0x3F636702);
    }
  }
  JUMPOUT(0x3F636777);
}

//------------------------------------------------------------------------------
// Address: 0x3F636702
// Name: public: class DName DName::operator+(class DName const __near &)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+(
        DName *this@<ecx>,
        _DWORD *a2@<eax>,
        int a3@<ebx>,
        int a4@<ebp>,
        DName *result,
        const DName *rd)
{
  if ( __check_float_string(a1: (void **)(a4 - 20), a2: (size_t *)(a4 - 68), a3: a3 + 1, Src: (void *)(a4 + 16), a5: a2) != 0 )
    JUMPOUT(0x3F63676C);
  JUMPOUT(0x3F636F2A);
}

//------------------------------------------------------------------------------
// Address: 0x3F636753
// Name: public: class DName DName::operator+(class DName __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+(DName *this@<ecx>, int a2@<eax>, int a3@<ebp>, DName *result, DName *pd)
{
  FILE *v5; // edx
  int v6; // eax

  if ( a2 != 0 )
  {
    v5 = *(FILE **)(a3 - 12);
    ++*(_DWORD *)(a3 + 12);
    v6 = _inc(a1: (int)this, a2: v5);
    *(_DWORD *)(a3 + 4) = v6;
    if ( isdigit_0(C: (unsigned __int8)v6) == 0 )
    {
      if ( *(_DWORD *)(a3 - 24) != 0 )
        JUMPOUT(0x3F636781);
      JUMPOUT(0x3F636877);
    }
    JUMPOUT(0x3F636725);
  }
  JUMPOUT(0x3F636F2A);
}

//------------------------------------------------------------------------------
// Address: 0x3F636781
// Name: public: class DName __near & DName::operator+=(char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+=(DName *this@<ecx>, int a2@<ebx>, void **a3@<ebp>, char ch)
{
  int v4; // eax
  int v5; // ebx
  int v6; // ecx
  FILE *v7; // edx
  int v8; // eax

  if ( a3[1] == (void *)101 || a3[1] == (void *)69 )
  {
    v4 = (int)*(a3 - 1);
    *(a3 - 1) = (void *)(v4 - 1);
    if ( v4 != 0 )
    {
      *((_BYTE *)*(a3 - 5) + a2) = 101;
      v5 = a2 + 1;
      if ( __check_float_string(a1: a3 - 5, a2: (size_t *)a3 - 17, a3: v5, Src: a3 + 4, a5: a3 - 15) != 0 )
      {
        v7 = (FILE *)*(a3 - 3);
        a3[3] = (char *)a3[3] + 1;
        v8 = _inc(a1: v6, a2: v7);
        a3[1] = (void *)v8;
        if ( v8 == 45 )
        {
          *((_BYTE *)*(a3 - 5) + v5) = 45;
          JUMPOUT(0x3F6367EA);
        }
        JUMPOUT(0x3F6367FC);
      }
      JUMPOUT(0x3F636F2A);
    }
  }
  JUMPOUT(0x3F636877);
}

//------------------------------------------------------------------------------
// Address: 0x3F6367EB
// Name: public: class DName __near & DName::operator+=(char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+=(DName *this@<ecx>, char a2@<sf>, char a3@<of>, const char *str)
{
  if ( a2 != a3 )
    JUMPOUT(0x3F6367ED);
  JUMPOUT(0x3F6367DA);
}

//------------------------------------------------------------------------------
// Address: 0x3F636857
// Name: private: static class DName UnDecorator::getArgumentList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl UnDecorator::getArgumentList()
{
  __asm { iret }
  JUMPOUT(0x3F636858);
}

//------------------------------------------------------------------------------
// Address: 0x3F636986
// Name: class DName operator+(char,class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall operator+(_BYTE *_EAX@<eax>, int a2@<ebx>)
{
  __asm { daa }
  *(_BYTE *)(a2 + 251709565) += *_EAX + (_BYTE)_EAX;
  JUMPOUT(0x3F636992);
}

//------------------------------------------------------------------------------
// Address: 0x3F6369CA
// Name: class DName operator+(char const __near *,class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl operator+()
{
  JUMPOUT(0x3F6369CE);
}

//------------------------------------------------------------------------------
// Address: 0x3F6369EC
// Name: public: class DName DName::operator+(char)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+(DName *this@<ecx>, _DWORD *a2@<eax>, int a3@<ebx>, DName *result, char ch)
{
  bool v5; // zf
  char *v6; // eax
  char *v7; // eax
  char *v8; // eax

  *a2 += a2;
  v5 = (_BYTE)this + *(_BYTE *)(a3 + 1894286279) == 0;
  *(_BYTE *)(a3 + 1894286279) += (_BYTE)this;
  if ( !v5 )
  {
    v6 = (char *)a2 - 3;
    if ( v6 != nullptr )
    {
      v7 = v6 - 2;
      if ( v7 != nullptr )
      {
        v8 = v7 - 3;
        if ( v8 != nullptr )
        {
          if ( v8 != (char *)3 )
            JUMPOUT(0x3F636A19);
          JUMPOUT(0x3F636A3D);
        }
        JUMPOUT(0x3F636622);
      }
      JUMPOUT(0x3F636C07);
    }
    JUMPOUT(0x3F6368DD);
  }
  JUMPOUT(0x3F636C03);
}

//------------------------------------------------------------------------------
// Address: 0x3F636A1A
// Name: public: class DName DName::operator+(char const __near *)const
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge DName::operator+(DName *this@<ecx>, int a2@<eax>, int a3@<ebp>, DName *result, const char *str)
{
  if ( a2 == *(_DWORD *)(a3 + 4) )
  {
    --*(_BYTE *)(a3 - 14);
    if ( *(_BYTE *)(a3 + 2) == 0 )
      *(_DWORD *)(a3 - 80) = *(_DWORD *)(a3 - 88);
    JUMPOUT(0x3F636E2E);
  }
  JUMPOUT(0x3F636ED0);
}

//------------------------------------------------------------------------------
// Address: 0x3F636A48
// Name: private: static class DName UnDecorator::getDimension(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getDimension(int a1@<ebp>, unsigned __int8 *a2@<esi>)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v3; // cl
  unsigned __int8 v4; // al
  unsigned int v5; // edi
  int v6; // edx
  unsigned __int8 v7; // al

  if ( *a2 == 94 )
  {
    ++a2;
    *(_BYTE *)(a1 - 15) = -1;
  }
  memset(a1: (void *)(a1 + 368), Val: 0, Size: 0x20u);
  if ( *a2 == 93 )
  {
    v2 = 93;
    ++a2;
    *(_BYTE *)(a1 + 379) = 32;
  }
  else
  {
    v2 = *(_BYTE *)(a1 - 61);
  }
  while ( 1 )
  {
    v7 = *a2;
    if ( *a2 == 93 )
      break;
    ++a2;
    if ( v7 == 45 && v2 != 0 && (v3 = *a2, *a2 != 93) )
    {
      ++a2;
      if ( v2 >= v3 )
      {
        v4 = v2;
        v2 = v3;
      }
      else
      {
        v4 = v3;
      }
      if ( v2 <= v4 )
      {
        v5 = v2;
        v6 = (unsigned __int8)(v4 - v2 + 1);
        do
        {
          *(_BYTE *)(a1 + (v5 >> 3) + 368) |= 1 << (v5 & 7);
          ++v5;
          --v6;
        }
        while ( v6 != 0 );
      }
      v2 = 0;
    }
    else
    {
      v2 = v7;
      *(_BYTE *)(a1 + (v7 >> 3) + 368) |= 1 << (v7 & 7);
    }
  }
  *(_DWORD *)(a1 - 28) = a2;
  JUMPOUT(0x3F6368E7);
}

//------------------------------------------------------------------------------
// Address: 0x3F636B89
// Name: private: static class DName UnDecorator::getEnumType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getEnumType(char a1@<cl>, int a2@<ebx>, int a3@<ebp>)
{
  bool v3; // zf

  v3 = a1 + *(_BYTE *)(a2 + 73239000) == 0;
  *(_BYTE *)(a2 + 73239000) += a1;
  if ( !v3 )
  {
    *(_DWORD *)(a3 - 4) -= 2;
    if ( *(int *)(a3 - 4) < 1 )
      ++*(_BYTE *)(a3 + 11);
  }
  if ( *(_DWORD *)(a3 - 72) != 0 )
  {
    if ( *(_BYTE *)(a3 + 11) == 0 )
      JUMPOUT(0x3F636CA3);
    JUMPOUT(0x3F636D1B);
  }
  JUMPOUT(0x3F636D3D);
}

//------------------------------------------------------------------------------
// Address: 0x3F636C5D
// Name: private: static class DName UnDecorator::getArgumentTypes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl UnDecorator::getArgumentTypes()
{
  JUMPOUT(0x3F636C5E);
}

//------------------------------------------------------------------------------
// Address: 0x3F636D21
// Name: private: static class DName UnDecorator::getThrowTypes(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getThrowTypes(char a1@<cf>, _DWORD *a2@<eax>, int a3@<ecx>, int _EBX@<ebx>, int a5@<ebp>)
{
  *a2 = 1166737408;
  __asm { fmul    qword ptr [ebx-27081FB3h] }
  *(_DWORD *)(a5 - 36) = a2;
  *(_DWORD *)(a5 - 32) = -(a1 + a3);
  JUMPOUT(0x3F636DEC);
}

//------------------------------------------------------------------------------
// Address: 0x3F636D9F
// Name: private: static class DName UnDecorator::getExtendedDataIndirectType(char __near &,bool __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::getExtendedDataIndirectType(int a1@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  int v4; // eax
  bool v5; // zf
  FILE *v6; // edx
  _DWORD *v7; // ebx
  int v8; // eax
  int v9; // esi
  _BYTE *v10; // esi

  *(_DWORD *)(a3 + 4) = a2;
  v4 = *(_DWORD *)(a3 - 40);
  ++*(_DWORD *)(a3 - 24);
  v5 = *(_DWORD *)(a3 - 48) == 0;
  *(_DWORD *)(a3 - 40) = v4 + a2 - 48;
  if ( v5 || (v5 = *(_DWORD *)(a3 - 4) == 1, --*(_DWORD *)(a3 - 4), !v5) )
  {
    v6 = *(FILE **)(a3 - 12);
    ++*(_DWORD *)(a3 + 12);
    *(_DWORD *)(a3 + 4) = _inc(a1, a2: v6);
    JUMPOUT(0x3F636D47);
  }
  if ( *(_BYTE *)(a3 - 16) != 0 )
    *(_DWORD *)(a3 - 40) = -*(_DWORD *)(a3 - 40);
  if ( a4 == 70 )
    *(_DWORD *)(a3 - 24) = 0;
  if ( *(_DWORD *)(a3 - 24) != 0 )
  {
    if ( *(_BYTE *)(a3 + 2) == 0 )
    {
      ++*(_DWORD *)(a3 - 52);
      v7 = *(_DWORD **)(a3 - 44);
      v8 = *(_DWORD *)(a3 - 40);
      if ( *(_DWORD *)(a3 - 72) != 0 )
      {
        *v7 = *(_DWORD *)(a3 - 36);
        v7[1] = *(_DWORD *)(a3 - 32);
      }
      else if ( *(_BYTE *)(a3 - 5) != 0 )
      {
        *v7 = v8;
      }
      else
      {
        *(_WORD *)v7 = v8;
      }
    }
    v9 = *(_DWORD *)(a3 - 28);
    ++*(_BYTE *)(a3 - 14);
    v10 = (_BYTE *)(v9 + 1);
    *(_DWORD *)(a3 - 28) = v10;
    if ( *(_DWORD *)(a3 + 4) == -1 )
    {
      if ( *v10 != 37 || *(_BYTE *)(*(_DWORD *)(a3 - 28) + 1) != 110 )
        goto $error_return$25538;
      v10 = *(_BYTE **)(a3 - 28);
    }
    if ( *v10 != 0 )
      JUMPOUT(0x3F6363B2);
  }
$error_return$25538:
  JUMPOUT(0x3F636F2A);
}

//------------------------------------------------------------------------------
// Address: 0x3F636EC4
// Name: private: static class DName UnDecorator::getArrayType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl UnDecorator::getArrayType()
{
  JUMPOUT(0x3F636EC6);
}

//------------------------------------------------------------------------------
// Address: 0x3F637023
// Name: private: static class DName UnDecorator::getLexicalFrame(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__usercall UnDecorator::getLexicalFrame@<eax>(
        char a1@<cf>,
        char a2@<zf>,
        int a3@<eax>,
        int a4@<ebp>,
        int a5@<esi>,
        DName *result)
{
  if ( !a2 )
    JUMPOUT(0x3F637025);
  BYTE1(a3) += *(_BYTE *)(a5 + 63) + a1;
  *(_DWORD *)(a4 + 1008) = a4 ^ a3;
  return UnDecorator::getDisplacement(result);
}

//------------------------------------------------------------------------------
// Address: 0x3F637054
// Name: private: static class DName UnDecorator::getDisplacement(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__usercall UnDecorator::getDisplacement@<eax>(
        int a1@<eax>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        DName *result)
{
  *(_DWORD *)(a3 - 60) = a1;
  *(_DWORD *)(a3 - 40) = a2;
  *(_DWORD *)(a3 - 84) = a4;
  *(_DWORD *)(a3 - 20) = a4;
  *(_DWORD *)(a3 - 56) = a4;
  *(_DWORD *)(a3 - 24) = a4;
  return UnDecorator::getGuardNumber(result);
}

//------------------------------------------------------------------------------
// Address: 0x3F637066
// Name: private: static class DName UnDecorator::getGuardNumber(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F637078
// Name: private: static class DName UnDecorator::getVfTableType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::getVfTableType(int a1@<ebp>, int a2@<edi>)
{
  *(_DWORD *)(*(int (**)(void))(a2 + 87))() = 22;
  _invalid_parameter_0();
  if ( *(_BYTE *)(a1 - 88) != 0 )
    *(_DWORD *)(*(_DWORD *)(a1 - 92) + 112) &= ~2u;
  JUMPOUT(0x3F6378F1);
}

//------------------------------------------------------------------------------
// Address: 0x3F6371C8
// Name: private: static class DName UnDecorator::getStringEncoding(char __near *,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getStringEncoding(int a1@<ebx>, int a2@<ebp>)
{
  int v2; // ebx

  *(_DWORD *)(a2 - 40) = a1;
  v2 = *(_DWORD *)(a1 - 4);
  *(_DWORD *)(a2 - 24) = v2;
  if ( v2 < 0 )
    *(_DWORD *)(a2 - 24) = -1;
  JUMPOUT(0x3F6378AF);
}

//------------------------------------------------------------------------------
// Address: 0x3F637268
// Name: private: static class DName UnDecorator::getSignedDimension(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getSignedDimension(unsigned int a1@<eax>, int a2@<ebp>, int a3@<esi>)
{
  int v3; // eax

  *(_BYTE *)(a3 + 61) += BYTE1(a1);
  v3 = *(_DWORD *)a1 ^ a1;
  if ( v3 != 0 || *(_WORD *)(a3 + 2) != 50 )
  {
    if ( (_WORD)v3 != 100 && (_WORD)v3 != 105 && (_WORD)v3 != 111 && (_WORD)v3 != 117 && (_WORD)v3 != 120 )
      JUMPOUT(0x3F6372BA);
  }
  else
  {
    *(_DWORD *)(a2 - 20) &= ~0x8000u;
    *(_DWORD *)(a2 - 76) = a3 + 4;
  }
  JUMPOUT(0x3F6378AF);
}

//------------------------------------------------------------------------------
// Address: 0x3F637573
// Name: private: static class DName UnDecorator::getPtrRefDataType(class DName const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getPtrRefDataType(_BYTE *a1@<eax>, char a2@<dl>, int *a3@<ebx>, int a4@<ebp>)
{
  char v4; // cc
  int v5; // ebp
  _BYTE *v6; // esi
  int v7; // eax
  _DWORD *v8; // ebx
  void (__cdecl *v9)(int, _BYTE *, int, int, int, int, int); // eax
  int v10; // ebx
  void (__cdecl *v11)(_BYTE *, int); // eax
  void (__cdecl *v12)(_BYTE *, int); // eax
  int v13; // [esp-Ch] [ebp-14h]
  int v14; // [esp-8h] [ebp-10h]
  int v15; // [esp-4h] [ebp-Ch]
  int bdt; // [esp+0h] [ebp-8h]

  v4 = (a4 + 1 < 0) ^ __OFADD__(1, a4);
  v5 = a4 + 1;
  LOBYTE(a1) = __inbyte(0x89u);
  if ( v4 )
  {
    v6 = a1;
    v7 = *a3;
    v8 = a3 + 2;
    *(_DWORD *)(v5 - 120) = v7;
    *(_DWORD *)(v5 - 116) = *(v8 - 1);
    bdt = *(_DWORD *)(v5 - 108);
    v15 = *(_DWORD *)(v5 - 24);
    *(_DWORD *)(v5 - 40) = v8;
    v14 = a2;
    v13 = *(_DWORD *)(v5 - 32);
    v9 = (void (__cdecl *)(int, _BYTE *, int, int, int, int, int))_decode_pointer_0(a1: (void *)s_NoEscConversion.m_pReplacements[199].m_nLength);
    v9(a1: v5 - 120, a2: v6, a3: v13, a4: v14, a5: v15, a6: bdt, a7: v5 - 100);
    v10 = *(_DWORD *)(v5 - 20) & 0x80;
    if ( v10 != 0 && *(_DWORD *)(v5 - 24) == 0 )
    {
      v11 = (void (__cdecl *)(_BYTE *, int))_decode_pointer_0(a1: s_NoEscConversion.m_pReplacements[200].m_pReplacementString);
      v11(a1: v6, a2: v5 - 100);
    }
    if ( *(_WORD *)(v5 - 36) == 103 && v10 == 0 )
    {
      v12 = (void (__cdecl *)(_BYTE *, int))_decode_pointer_0(a1: (void *)s_NoEscConversion.m_pReplacements[200].m_nLength);
      v12(a1: v6, a2: v5 - 100);
    }
    if ( *v6 == 45 )
    {
      *(_DWORD *)(v5 - 20) |= 0x100u;
      *(_DWORD *)(v5 - 28) = v6 + 1;
    }
    JUMPOUT(0x3F637488);
  }
  JUMPOUT(0x3F637558);
}

//------------------------------------------------------------------------------
// Address: 0x3F637660
// Name: private: static class DName UnDecorator::getTemplateArgumentList(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getTemplateArgumentList(char a1@<ah>, int a2@<esi>)
{
  *(_BYTE *)(a2 - 119) += a1;
  JUMPOUT(0x3F63766B);
}

//------------------------------------------------------------------------------
// Address: 0x3F637818
// Name: private: static class DName UnDecorator::getOperatorName(bool,bool __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::getOperatorName(_BYTE *a1@<eax>, char a2@<dh>, int a3@<ebx>, int a4@<ebp>, int a5@<esi>)
{
  const char *v5; // edi
  int v6; // eax
  int v7; // eax

  *(_BYTE *)(a3 + 2105740484) += *a1 | (unsigned __int8)a1;
  __debugbreak();
  *(_BYTE *)(a4 + 78) += a2;
  if ( a5 <= 0 )
  {
    ((void (__cdecl *)(int))loc_3F636FCA)(a1: a5);
  }
  else
  {
    v5 = *(const char **)(a4 - 28);
    *(_DWORD *)(a4 - 36) = a5;
    while ( 1 )
    {
      --*(_DWORD *)(a4 - 36);
      v6 = _mbtowc_l_0(
             DstCh: (wchar_t *)(a4 - 112),
             SrcCh: v5,
             SrcSizeInBytes: *(_DWORD *)(*(_DWORD *)(a4 - 100) + 172),
             Locale: (_locale_t)(a4 - 100));
      *(_DWORD *)(a4 - 124) = v6;
      if ( v6 <= 0 )
        break;
      ((void (__cdecl *)(_DWORD))loc_3F636FA5)(a1: *(_DWORD *)(a4 - 112));
      v5 += *(_DWORD *)(a4 - 124);
      if ( *(int *)(a4 - 36) <= 0 )
        goto LABEL_8;
    }
    *(_DWORD *)(a4 - 44) = -1;
  }
LABEL_8:
  if ( *(int *)(a4 - 44) >= 0 && (*(_BYTE *)(a4 - 20) & 4) != 0 )
    write_multi_char(a1: 32, a2: a3, a3: *(_DWORD *)(a4 - 60));
  if ( *(_DWORD *)(a4 - 80) != 0 )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a4 - 80));
    *(_DWORD *)(a4 - 80) = 0;
  }
  v7 = **(unsigned __int16 **)(a4 - 76);
  *(_DWORD *)(a4 - 36) = v7;
  if ( (_WORD)v7 != 0 )
    JUMPOUT(0x3F6370C4);
  if ( *(_BYTE *)(a4 - 88) != 0 )
    *(_DWORD *)(*(_DWORD *)(a4 - 92) + 112) &= ~2u;
  __security_check_cookie`...'(StackCookie: a4 ^ *(_DWORD *)(a4 + 1008));
}

//------------------------------------------------------------------------------
// Address: 0x3F637D87
// Name: private: static class DName UnDecorator::getTemplateName(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getTemplateName(char a1@<zf>, int a2@<ebp>)
{
  if ( !a1 )
  {
    *(_DWORD *)(a2 - 52) = 1;
    JUMPOUT(0x3F6380B4);
  }
  *(_DWORD *)(a2 - 52) = 0;
  JUMPOUT(0x3F6380B6);
}

//------------------------------------------------------------------------------
// Address: 0x3F637EDA
// Name: private: static class DName UnDecorator::getZName(bool)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getZName(int a1@<ecx>, int a2@<ebx>)
{
  int v2; // ecx

  MK_FP(*(_WORD *)(a1 - 1 + 4), *(_DWORD *)(a1 - 1))();
  *(_BYTE *)(a2 - 997987235) = __ROR1__(*(_BYTE *)(a2 - 997987235), 1);
  if ( v2 != 0 )
    JUMPOUT(0x3F637EE7);
  JUMPOUT(0x3F637E67);
}

//------------------------------------------------------------------------------
// Address: 0x3F6380C4
// Name: private: static class DName UnDecorator::getScopedName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getScopedName(__int16 a1@<ax>, unsigned __int16 a2@<dx>, int a3@<ebp>)
{
  int v3; // ebp
  int v4; // esi
  int v5; // ebx
  int v6; // edi
  const char *v7; // edi
  int v8; // eax

  v3 = a3 + 1;
  LOBYTE(a1) = __inbyte(a2);
  if ( (a1 & 0x40) != 0 )
  {
    if ( (a1 & 0x100) != 0 )
    {
      *(_WORD *)(v3 - 60) = 45;
    }
    else if ( (a1 & 1) != 0 )
    {
      *(_WORD *)(v3 - 60) = 43;
    }
    else
    {
      if ( (a1 & 2) == 0 )
        goto LABEL_9;
      *(_WORD *)(v3 - 60) = 32;
    }
    *(_DWORD *)(v3 - 48) = 1;
  }
LABEL_9:
  v4 = *(_DWORD *)(v3 - 32);
  v5 = *(_DWORD *)(v3 - 56) - v4 - *(_DWORD *)(v3 - 48);
  if ( (*(_BYTE *)(v3 - 20) & 0xC) == 0 )
    write_multi_char(a1: 32, a2: v5, a3: *(_DWORD *)(v3 - 72));
  v6 = *(_DWORD *)(v3 - 72);
  ((void (__cdecl *)(_DWORD))loc_3F636FCA)(a1: *(_DWORD *)(v3 - 48));
  if ( (*(_BYTE *)(v3 - 20) & 8) != 0 && (*(_BYTE *)(v3 - 20) & 4) == 0 )
    write_multi_char(a1: 48, a2: v5, a3: v6);
  if ( *(_DWORD *)(v3 - 52) != 0 || v4 <= 0 )
  {
    ((void (__cdecl *)(int))loc_3F636FCA)(a1: v4);
  }
  else
  {
    v7 = *(const char **)(v3 - 28);
    *(_DWORD *)(v3 - 40) = v4;
    while ( 1 )
    {
      --*(_DWORD *)(v3 - 40);
      v8 = _mbtowc_l_0(
             DstCh: (wchar_t *)(v3 - 112),
             SrcCh: v7,
             SrcSizeInBytes: *(_DWORD *)(*(_DWORD *)(v3 - 88) + 172),
             Locale: (_locale_t)(v3 - 88));
      *(_DWORD *)(v3 - 124) = v8;
      if ( v8 <= 0 )
        break;
      ((void (__cdecl *)(_DWORD))loc_3F636FA5)(a1: *(_DWORD *)(v3 - 112));
      v7 += *(_DWORD *)(v3 - 124);
      if ( *(int *)(v3 - 40) <= 0 )
        goto LABEL_22;
    }
    *(_DWORD *)(v3 - 44) = -1;
  }
LABEL_22:
  JUMPOUT(0x3F6381A5);
}

//------------------------------------------------------------------------------
// Address: 0x3F6381A8
// Name: private: static class DName UnDecorator::getECSUName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__usercall UnDecorator::getECSUName@<eax>(int a1@<edx>, char a2@<bh>, int a3@<edi>, DName *result)
{
  unsigned __int8 v4; // al

  *(_BYTE *)(a3 + a1 - 10) += a2;
  v4 = __inbyte(a1);
  if ( a3 + __CFADD__(v4, 116) + a3 != 0 )
    JUMPOUT(0x3F63816C);
  return UnDecorator::getECSUDataType(result);
}

//------------------------------------------------------------------------------
// Address: 0x3F6381B7
// Name: private: static class DName UnDecorator::getECSUDataType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
DName *__usercall UnDecorator::getECSUDataType@<eax>(int a1@<ebp>)
{
  int v1; // eax

  ((void (__cdecl *)(int))write_multi_char)(a1: 32);
  if ( *(_DWORD *)(a1 - 100) != 0 )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a1 - 100));
    *(_DWORD *)(a1 - 100) = 0;
  }
  v1 = **(unsigned __int16 **)(a1 - 108);
  *(_DWORD *)(a1 - 40) = v1;
  if ( (_WORD)v1 != 0 )
    JUMPOUT(0x3F6379EA);
  if ( *(_DWORD *)(a1 - 64) != 0 && *(_DWORD *)(a1 - 64) != 7 )
    JUMPOUT(0x3F637988);
  if ( *(_BYTE *)(a1 - 76) != 0 )
    *(_DWORD *)(*(_DWORD *)(a1 - 80) + 112) &= ~2u;
  return *(DName **)(a1 - 44);
}

//------------------------------------------------------------------------------
// Address: 0x3F6382B7
// Name: private: static class DName UnDecorator::getSymbolName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__usercall UnDecorator::getSymbolName@<eax>(
        char a1@<zf>,
        __int16 a2@<ax>,
        __int16 a3@<dx>,
        __int16 a4@<di>,
        __int16 a5@<si>,
        DName *result)
{
  if ( !a1 && a2 != 120 && a2 != 88 && a3 != a5 && a3 != a4 && a3 != 111 && a3 != 117 && a3 != 120 && a3 != 88 )
    JUMPOUT(0x3F638359);
  if ( a2 == a5 || a2 == a4 || a2 == 111 )
    JUMPOUT(0x3F63830F);
  return UnDecorator::getBasedType(result);
}

//------------------------------------------------------------------------------
// Address: 0x3F6382FD
// Name: private: static class DName UnDecorator::getBasedType(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
DName *__usercall UnDecorator::getBasedType@<eax>(
        char a1@<zf>,
        __int16 a2@<ax>,
        __int16 a3@<dx>,
        _DWORD *a4@<ebp>,
        __int16 a5@<di>,
        __int16 a6@<si>)
{
  int v6; // ecx
  int v7; // eax

  v6 = a1 || a2 == 120 || a2 == 88;
  v7 = a3 == a6 || a3 == a5 || a3 == 111 || a3 == 117 || a3 == 120 || a3 == 88;
  return (DName *)(v6 == v7
                && ((a4[5] ^ *(_DWORD *)(a4[2] + 12)) & 0x10000) == 0
                && ((*((_BYTE *)a4 + 20) ^ *(_BYTE *)(a4[2] + 12)) & 0x20) == 0
                && *(_DWORD *)a4[2] == a4[3]);
}

//------------------------------------------------------------------------------
// Address: 0x3F63838F
// Name: private: static class DName UnDecorator::composeDeclaration(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge UnDecorator::composeDeclaration(
        DName *result,
        const DName *symbol,
        const DName *symbola,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18,
        int a19,
        int a20,
        int a21,
        int a22,
        int a23,
        int a24,
        int a25,
        int a26,
        int a27,
        int a28,
        int a29,
        int a30,
        int a31,
        int a32,
        int a33,
        int a34,
        int a35,
        int a36,
        int a37,
        int a38,
        int a39,
        int a40,
        int a41,
        int a42,
        int a43,
        int a44,
        int a45,
        int a46,
        int a47,
        int a48,
        int a49,
        int a50,
        int a51,
        int a52,
        int a53,
        int a54,
        int a55,
        int a56,
        int a57,
        int a58,
        int a59,
        int a60,
        int a61,
        int a62,
        int a63,
        int a64)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F638399
// Name: _write_multi_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall write_multi_char@<eax>(int result@<eax>, int a2, int a3)
{
  _DWORD *v3; // esi

  v3 = (_DWORD *)result;
  do
  {
    if ( a3 <= 0 )
      break;
    --a3;
    result = ((int (__cdecl *)(int))loc_3F636FA5)(a1: a2);
  }
  while ( *v3 != -1 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F6383BE
// Name: __woutput_p_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
DName *__cdecl _woutput_p_l_0(DName *a1, wchar_t *a2, struct localeinfo_struct *a3, int a4)
{
  bool v4; // zf
  int v5; // edx
  wchar_t *v6; // esi
  int v7; // eax
  int v8; // ebx
  int v9; // eax
  int v10; // eax
  int v11; // eax
  wchar_t *v12; // ecx
  int v13; // eax
  int v14; // eax
  _DWORD *v15; // ecx
  int v16; // eax
  int v17; // eax
  int v18; // eax
  wchar_t v19; // ax
  _DWORD *v20; // ecx
  int v21; // eax
  _DWORD *v22; // ecx
  int v23; // eax
  __int16 v25; // bx
  _WORD *v26; // esi
  const char *v27; // edi
  int v28; // esi
  int v29; // eax
  int v30; // eax
  void (__cdecl *v31)(__int64 *, const char *, int, int, int, int, _LocaleUpdate *); // eax
  int v32; // esi
  void (__cdecl *v33)(const char *, _LocaleUpdate *); // eax
  void (__cdecl *v34)(const char *, _LocaleUpdate *); // eax
  int v35; // [esp-18h] [ebp-670h]
  int v36; // [esp-14h] [ebp-66Ch]
  int v37; // [esp-10h] [ebp-668h]
  int v38; // [esp-Ch] [ebp-664h]
  _DWORD v39[403]; // [esp+Ch] [ebp-64Ch] BYREF
  __int64 v40; // [esp+658h] [ebp+0h] BYREF
  int v41; // [esp+660h] [ebp+8h]
  int v42; // [esp+66Ch] [ebp+14h]
  int v43; // [esp+670h] [ebp+18h]
  int v44; // [esp+674h] [ebp+1Ch]
  int v45; // [esp+678h] [ebp+20h]
  char SrcCh[4]; // [esp+67Ch] [ebp+24h] BYREF
  DName *v47; // [esp+680h] [ebp+28h]
  __int16 v48; // [esp+684h] [ebp+2Ch]
  __int16 v49; // [esp+686h] [ebp+2Eh]
  int v50; // [esp+688h] [ebp+30h]
  int v51; // [esp+68Ch] [ebp+34h]
  wchar_t *EndPtr; // [esp+690h] [ebp+38h] BYREF
  int v53; // [esp+694h] [ebp+3Ch]
  int v54; // [esp+698h] [ebp+40h]
  int v55; // [esp+69Ch] [ebp+44h]
  wchar_t *v56; // [esp+6A0h] [ebp+48h]
  int v57; // [esp+6A4h] [ebp+4Ch]
  int v58; // [esp+6A8h] [ebp+50h]
  int v59; // [esp+6ACh] [ebp+54h]
  _LocaleUpdate Locale; // [esp+6B0h] [ebp+58h] BYREF
  unsigned int v61; // [esp+6C0h] [ebp+68h]
  int v62; // [esp+6C4h] [ebp+6Ch]
  wchar_t *v63; // [esp+6C8h] [ebp+70h]
  int v64; // [esp+6CCh] [ebp+74h]
  int v65; // [esp+6D0h] [ebp+78h]
  int v66; // [esp+6D4h] [ebp+7Ch]
  int v67; // [esp+6D8h] [ebp+80h]
  wchar_t DstCh[512]; // [esp+6DCh] [ebp+84h] BYREF

  v47 = a1;
  v66 = a4;
  v44 = 0;
  v67 = 0;
  v53 = 0;
  v45 = 0;
  v51 = 0;
  _LocaleUpdate::_LocaleUpdate(this: &Locale, a2: a3);
  v64 = -1;
  EndPtr = nullptr;
  if ( a1 == nullptr || a2 == nullptr )
  {
    *_errno_0() = 22;
    _invalid_parameter_0();
    v4 = !Locale.updated;
    goto LABEL_3;
  }
  v57 = 0;
  v39[402] = a2;
  v62 = 0;
  v5 = *a2;
  v54 = -1;
  v61 = -1;
  v64 = -1;
  v58 = 0;
  v50 = 0;
  v43 = 0;
  v55 = 0;
  v65 = 0;
  v56 = a2;
  v59 = v5;
  if ( (_WORD)v5 == 0 )
    JUMPOUT(0x3F63929B);
  v6 = a2 + 1;
  v56 = a2 + 1;
  if ( (unsigned __int16)(v5 - 32) > 0x58u )
    v7 = 0;
  else
    v7 = byte_3F654C78[(unsigned __int16)v5] & 0xF;
  v50 = (unsigned __int8)byte_3F654C98[9 * v7 + v50] >> 4;
  v8 = v50;
  if ( v50 == 1 )
  {
    if ( *v6 != 37 )
    {
      if ( wcstol_0(String: v6, &EndPtr, Radix: 10) > 0 && *EndPtr == 36 )
      {
        if ( v62 == 0 )
          memset(a1: v39, Val: 0, Size: 0x640u);
        v64 = 1;
        v9 = wcstol_0(String: v6, &EndPtr, Radix: 10) - 1;
        v61 = v9;
        v56 = EndPtr + 1;
        if ( v62 == 0 )
        {
          if ( v9 < 0 || *EndPtr != 36 || v9 >= 100 )
          {
LABEL_172:
            *_errno_0() = 22;
            _invalid_parameter_0();
            v4 = !Locale.updated;
LABEL_3:
            if ( !v4 )
              Locale.ptd->_ownlocale &= ~2u;
            JUMPOUT(0x3F6392E4);
          }
          if ( v9 > v54 )
            v54 = v9;
        }
        v6 = EndPtr + 1;
        v5 = v59;
      }
      else
      {
        v64 = 0;
        v5 = v59;
      }
    }
  }
  else if ( v50 == 8 )
  {
    goto LABEL_267;
  }
  switch ( v8 )
  {
    case 0:
      if ( v62 == 0 && v64 == 1 || v62 == 1 && v64 == -1 )
        goto LABEL_234;
      goto $NORMAL_STATE$25963;
    case 1:
      v65 = -1;
      v41 = 0;
      v45 = 0;
      v55 = 0;
      v53 = 0;
      v67 = 0;
      v51 = 0;
      goto LABEL_234;
    case 2:
      switch ( (unsigned __int16)v5 )
      {
        case ' ':
          v67 |= 2u;
          break;
        case '#':
          v67 |= 0x80u;
          break;
        case '+':
          v67 |= 1u;
          break;
        case '-':
          v67 |= 4u;
          break;
        case '0':
          v67 |= 8u;
          break;
        default:
          break;
      }
      goto LABEL_234;
    case 3:
      if ( (_WORD)v5 != 42 )
      {
        v55 = 10 * v55 + (unsigned __int16)v5 - 48;
        goto LABEL_234;
      }
      if ( v64 == 0 )
      {
        v66 += 4;
        v10 = *(_DWORD *)(v66 - 4);
        goto LABEL_57;
      }
      v11 = wcstol_0(String: v6, &EndPtr, Radix: 10);
      v12 = EndPtr;
      v13 = v11 - 1;
      v56 = EndPtr + 1;
      if ( v62 != 0 )
      {
        v10 = *(_DWORD *)v39[4 * v13 + 1];
LABEL_57:
        v55 = v10;
        if ( v10 < 0 )
        {
          v67 |= 4u;
          v55 = -v55;
        }
        goto LABEL_234;
      }
      goto LABEL_49;
    case 4:
      v65 = 0;
      goto LABEL_234;
    case 5:
      if ( (_WORD)v5 != 42 )
      {
        v65 = 10 * v65 + (unsigned __int16)v5 - 48;
        goto LABEL_234;
      }
      if ( v64 == 0 )
      {
        v66 += 4;
        v17 = *(_DWORD *)(v66 - 4);
        goto LABEL_66;
      }
      v18 = wcstol_0(String: v6, &EndPtr, Radix: 10);
      v12 = EndPtr;
      v13 = v18 - 1;
      v56 = EndPtr + 1;
      if ( v62 != 0 )
      {
        v17 = *(_DWORD *)v39[4 * v13 + 1];
LABEL_66:
        v65 = v17;
        if ( v17 < 0 )
          v65 = -1;
LABEL_234:
        JUMPOUT(0x3F639222);
      }
LABEL_49:
      if ( v13 < 0 || *v12 != 36 || (int)v61 >= 100 )
        goto LABEL_172;
      if ( v13 > v54 )
        v54 = v13;
      v14 = 4 * v13;
      v15 = &v39[v14];
      if ( v39[v14] != 0 )
      {
        v16 = ((int (__cdecl *)(_DWORD *, int, int, int))loc_3F638245)(a1: v15, a2: 1, a3: 42, a4: v67);
        goto LABEL_171;
      }
      *v15 = 1;
      LOWORD(v39[v14 + 2]) = 42;
      goto LABEL_69;
    case 6:
      switch ( (unsigned __int16)v5 )
      {
        case 'I':
          v19 = *v6;
          if ( *v6 == 54 && v6[1] == 52 )
          {
            v67 |= 0x8000u;
            v56 = v6 + 2;
          }
          else if ( v19 == 51 && v6[1] == 50 )
          {
            v67 &= ~0x8000u;
            v56 = v6 + 2;
          }
          else
          {
            if ( v19 != 100 && v19 != 105 && v19 != 111 && v19 != 117 && v19 != 120 && v19 != 88 )
            {
              v50 = 0;
$NORMAL_STATE$25963:
              v51 = 1;
              ((void (__cdecl *)(int))loc_3F636FA5)(a1: v5);
              JUMPOUT(0x3F639221);
            }
            v67 |= 0x10000u;
          }
          break;
        case 'h':
          v67 |= 0x20u;
          break;
        case 'l':
          if ( *v6 == 108 )
          {
            v67 |= 0x1000u;
            v56 = v6 + 1;
          }
          else
          {
            v67 |= 0x10u;
          }
          break;
        case 'w':
          v67 |= 0x800u;
          break;
        default:
          break;
      }
      goto LABEL_234;
    case 7:
      if ( (unsigned __int16)v5 > 0x64u )
      {
        if ( (unsigned __int16)v5 > 0x70u )
        {
          if ( (unsigned __int16)v5 == 115 )
            goto LABEL_113;
          if ( (unsigned __int16)v5 != 117 )
          {
            if ( (unsigned __int16)v5 != 120 )
              goto LABEL_247;
            v44 = 39;
            goto $COMMON_HEX$26237;
          }
LABEL_165:
          v59 = 10;
LABEL_166:
          v25 = v67;
          goto $COMMON_INT$26230;
        }
        if ( (unsigned __int16)v5 == 112 )
        {
          v65 = 8;
LABEL_197:
          v44 = 7;
$COMMON_HEX$26237:
          v59 = 16;
          if ( (v67 & 0x80u) != 0 )
          {
            v48 = 48;
            v49 = v44 + 81;
            v53 = 2;
          }
          goto LABEL_166;
        }
        if ( (unsigned __int16)v5 < 0x65u )
          goto LABEL_247;
        if ( (unsigned __int16)v5 <= 0x67u )
          goto LABEL_104;
        if ( (unsigned __int16)v5 != 105 )
        {
          if ( (unsigned __int16)v5 == 110 )
          {
            if ( v64 != 0 )
            {
              if ( v61 > 0x63 )
                goto LABEL_267;
              if ( v62 == 0 )
              {
LABEL_156:
                if ( v39[4 * v61] == 0 )
                  JUMPOUT(0x3F6390A1);
LABEL_252:
                JUMPOUT(0x3F638EF0);
              }
              v26 = *(_WORD **)v39[4 * v61 + 1];
            }
            else
            {
              v66 += 4;
              v26 = *(_WORD **)(v66 - 4);
            }
            if ( _get_printf_count_output_0() == 0 )
              goto LABEL_267;
            if ( (v67 & 0x20) != 0 )
              *v26 = v57;
            else
              *(_DWORD *)v26 = v57;
            v45 = 1;
            goto LABEL_247;
          }
          if ( (unsigned __int16)v5 != 111 )
            goto LABEL_247;
          v25 = v67;
          v59 = 8;
          if ( (v67 & 0x80u) != 0 )
          {
            v25 = v67 | 0x200;
            v67 |= 0x200u;
          }
$COMMON_INT$26230:
          if ( v25 < 0 )
          {
            if ( v64 == 0 )
            {
LABEL_169:
              v66 += 8;
              goto LABEL_254;
            }
            if ( v61 > 0x63 )
              goto LABEL_267;
            if ( v62 == 0 )
            {
              if ( v39[4 * v61] != 0 )
                goto LABEL_252;
              v39[4 * v61] = 3;
              goto LABEL_257;
            }
            goto LABEL_254;
          }
          if ( (v25 & 0x1000) != 0 )
          {
            if ( v64 == 0 )
              goto LABEL_169;
            if ( v61 > 0x63 )
              goto LABEL_267;
            if ( v62 == 0 )
            {
              if ( v39[4 * v61] != 0 )
                goto LABEL_252;
              v39[4 * v61] = 4;
LABEL_257:
              JUMPOUT(0x3F638F8B);
            }
LABEL_254:
            JUMPOUT(0x3F638F44);
          }
          if ( (v25 & 0x20) == 0 )
          {
            if ( (v25 & 0x40) == 0 )
              JUMPOUT(0x3F638F15);
            if ( v64 != 0 )
            {
              if ( v61 <= 0x63 )
                JUMPOUT(0x3F638ECF);
              goto LABEL_267;
            }
            v66 += 4;
            goto LABEL_259;
          }
          if ( (v25 & 0x40) != 0 )
          {
            if ( v64 == 0 )
            {
              v66 += 4;
              goto LABEL_259;
            }
            if ( v61 > 0x63 )
              goto LABEL_267;
            if ( v62 != 0 )
              goto LABEL_259;
          }
          else
          {
            if ( v64 == 0 )
            {
              v66 += 4;
              goto LABEL_259;
            }
            if ( v61 > 0x63 )
              goto LABEL_267;
            if ( v62 != 0 )
LABEL_259:
              JUMPOUT(0x3F638F12);
          }
          JUMPOUT(0x3F638ED5);
        }
LABEL_164:
        v67 |= 0x40u;
        goto LABEL_165;
      }
      if ( (unsigned __int16)v5 == 100 )
        goto LABEL_164;
      if ( (unsigned __int16)v5 <= 0x53u )
      {
        if ( (unsigned __int16)v5 != 83 )
        {
          if ( (unsigned __int16)v5 == 65 )
          {
LABEL_103:
            v5 += 32;
            v41 = 1;
            v59 = v5;
            goto LABEL_104;
          }
          if ( (unsigned __int16)v5 != 67 )
          {
            if ( (unsigned __int16)v5 == 69 || (unsigned __int16)v5 == 71 )
              goto LABEL_103;
LABEL_247:
            JUMPOUT(0x3F6390E7);
          }
          if ( (v67 & 0x830) == 0 )
            v67 |= 0x20u;
LABEL_119:
          v51 = 1;
          if ( v64 != 0 )
          {
            if ( v61 > 0x63 )
              goto LABEL_267;
            if ( v62 == 0 )
            {
              v22 = &v39[4 * v61];
              if ( *v22 == 0 )
              {
                *v22 = 1;
                JUMPOUT(0x3F6390A3);
              }
              JUMPOUT(0x3F638EED);
            }
            v21 = *(unsigned __int16 *)v39[4 * v61 + 1];
          }
          else
          {
            v66 += 4;
            v21 = *(unsigned __int16 *)(v66 - 4);
          }
          v42 = v21;
          if ( (v67 & 0x20) != 0 )
          {
            SrcCh[0] = v21;
            SrcCh[1] = 0;
            if ( _mbtowc_l_0(
                   DstCh,
                   SrcCh,
                   SrcSizeInBytes: Locale.localeinfo.locinfo->mb_cur_max,
                   Locale: &Locale.localeinfo) < 0 )
              v45 = 1;
          }
          else
          {
            DstCh[0] = v21;
          }
          v63 = DstCh;
          v58 = 1;
          goto LABEL_247;
        }
        if ( (v67 & 0x830) == 0 )
          v67 |= 0x20u;
LABEL_113:
        if ( v64 == 0 )
        {
          v66 += 4;
          JUMPOUT(0x3F639059);
        }
        JUMPOUT(0x3F63903B);
      }
      if ( (unsigned __int16)v5 == 88 )
        goto LABEL_197;
      if ( (unsigned __int16)v5 != 90 )
      {
        if ( (unsigned __int16)v5 != 97 )
        {
          if ( (unsigned __int16)v5 != 99 )
            goto LABEL_247;
          goto LABEL_119;
        }
LABEL_104:
        v67 |= 0x40u;
        if ( v64 == 1 && v62 == 0 )
        {
          if ( v61 <= 0x63 )
          {
            v14 = 4 * v61;
            v20 = &v39[4 * v61];
            if ( *v20 != 0 )
            {
              v16 = ((int (__cdecl *)(_DWORD *, int, int, int))loc_3F638245)(a1: v20, a2: 7, a3: v5, a4: v67);
LABEL_171:
              if ( v16 != 0 )
                goto LABEL_234;
              goto LABEL_172;
            }
            *v20 = 7;
            LOWORD(v39[v14 + 2]) = v5;
LABEL_69:
            v39[v14 + 3] = v67;
            goto LABEL_234;
          }
LABEL_267:
          JUMPOUT(0x3F6392AE);
        }
        v27 = (const char *)DstCh;
        v63 = DstCh;
        v58 = 512;
        if ( v65 >= 0 )
        {
          if ( v65 != 0 )
          {
            if ( v65 > 512 )
              v65 = 512;
            if ( v65 > 163 )
            {
              v28 = v65 + 349;
              v29 = ((int (__cdecl *)(int))loc_3F609A30)(a1: v65 + 349);
              LOBYTE(v5) = v59;
              v43 = v29;
              if ( v29 != 0 )
              {
                v63 = (wchar_t *)v29;
                v58 = v28;
                v27 = (const char *)v29;
              }
              else
              {
                v65 = 163;
              }
            }
          }
          else
          {
            v65 = (_WORD)v5 == 103;
          }
        }
        else
        {
          v65 = 6;
        }
        if ( v64 != 0 )
        {
          if ( v61 > 0x63 )
            JUMPOUT(0x3F6392C5);
          v30 = v39[4 * v61 + 1] + 8;
        }
        else
        {
          v30 = v66 + 8;
          v66 += 8;
        }
        v40 = *(_QWORD *)(v30 - 8);
        v38 = v41;
        v37 = v65;
        v36 = (char)v5;
        v35 = v58;
        v31 = (void (__cdecl *)(__int64 *, const char *, int, int, int, int, _LocaleUpdate *))_decode_pointer_0(a1: (void *)s_NoEscConversion.m_pReplacements[199].m_nLength);
        v31(a1: &v40, a2: v27, a3: v35, a4: v36, a5: v37, a6: v38, a7: &Locale);
        v32 = v67 & 0x80;
        if ( (v67 & 0x80) != 0 && v65 == 0 )
        {
          v33 = (void (__cdecl *)(const char *, _LocaleUpdate *))_decode_pointer_0(a1: s_NoEscConversion.m_pReplacements[200].m_pReplacementString);
          v33(a1: v27, a2: &Locale);
        }
        if ( (_WORD)v59 == 103 && v32 == 0 )
        {
          v34 = (void (__cdecl *)(const char *, _LocaleUpdate *))_decode_pointer_0(a1: (void *)s_NoEscConversion.m_pReplacements[200].m_nLength);
          v34(a1: v27, a2: &Locale);
        }
        if ( *v27 == 45 )
        {
          v67 |= 0x100u;
          v63 = (wchar_t *)++v27;
        }
        strlen_0(Str: v27);
LABEL_249:
        JUMPOUT(0x3F6390E4);
      }
      if ( v64 != 0 )
      {
        if ( v61 > 0x63 )
          goto LABEL_267;
        if ( v62 != 0 )
        {
          v23 = *(_DWORD *)v39[4 * v61 + 1];
          goto LABEL_137;
        }
        goto LABEL_156;
      }
      v66 += 4;
      v23 = *(_DWORD *)(v66 - 4);
LABEL_137:
      if ( v23 == 0 || *(_DWORD *)(v23 + 4) == 0 )
      {
        v63 = (wchar_t *)Str;
        strlen_0(Str: Str);
        goto LABEL_249;
      }
      v63 = *(wchar_t **)(v23 + 4);
      if ( (v67 & 0x800) == 0 )
      {
        v51 = 0;
        goto LABEL_249;
      }
      v51 = 1;
      return UnDecorator::getScope(result: a1);
    default:
      goto LABEL_234;
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F638ED1
// Name: private: static class DName UnDecorator::getDecoratedName(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getDecoratedName(__int16 _DX@<dx>, int a2@<ebx>, int a3@<ebp>)
{
  int v4; // eax
  _DWORD *v5; // ecx

  __asm { insb }
  *(_BYTE *)(a3 + 49) += HIBYTE(_DX);
  v4 = 16 * *(_DWORD *)(a3 + 104);
  v5 = (_DWORD *)(a3 + v4 - 1612);
  if ( *v5 != 0 )
  {
    if ( ((int (__cdecl *)(int, int, __int16, int))loc_3F638245)(a1: a3 + v4 - 1612, a2: 1, a3: _DX, a4: a2) == 0 )
      JUMPOUT(0x3F638C04);
  }
  else
  {
    *v5 = 1;
    *(_WORD *)(a3 + v4 - 1604) = _DX;
    *(_DWORD *)(a3 + v4 - 1600) = a2;
  }
  JUMPOUT(0x3F6390E7);
}

//------------------------------------------------------------------------------
// Address: 0x3F6390E2
// Name: private: static class DName UnDecorator::getScope(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::getScope(int a1@<eax>, int a2@<ebp>)
{
  int v2; // eax
  int v3; // esi
  int v4; // ebx
  const char *v5; // edi
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // eax
  _DWORD *v10; // esi

  *(_DWORD *)(a2 + 80) = a1 >> 1;
  if ( *(_DWORD *)(a2 + 116) == 1 && *(_DWORD *)(a2 + 108) == 0 )
    goto LABEL_30;
  if ( *(_DWORD *)(a2 + 32) == 0 )
  {
    v2 = *(_DWORD *)(a2 + 128);
    if ( (v2 & 0x40) != 0 )
    {
      if ( (v2 & 0x100) != 0 )
      {
        *(_WORD *)(a2 + 44) = 45;
LABEL_11:
        *(_DWORD *)(a2 + 60) = 1;
        goto LABEL_12;
      }
      if ( (v2 & 1) != 0 )
      {
        *(_WORD *)(a2 + 44) = 43;
        goto LABEL_11;
      }
      if ( (v2 & 2) != 0 )
      {
        *(_WORD *)(a2 + 44) = 32;
        goto LABEL_11;
      }
    }
LABEL_12:
    v3 = *(_DWORD *)(a2 + 80);
    v4 = *(_DWORD *)(a2 + 68) - v3 - *(_DWORD *)(a2 + 60);
    if ( (*(_BYTE *)(a2 + 128) & 0xC) == 0 )
      write_multi_char(result: a2 + 76, a2: 32, a3: v4);
    ((void (__cdecl *)(_DWORD))loc_3F636FCA)(a1: *(_DWORD *)(a2 + 60));
    if ( (*(_BYTE *)(a2 + 128) & 8) != 0 && (*(_BYTE *)(a2 + 128) & 4) == 0 )
      write_multi_char(result: a2 + 76, a2: 48, a3: v4);
    if ( *(_DWORD *)(a2 + 52) != 0 || v3 <= 0 )
    {
      ((void (__cdecl *)(int))loc_3F636FCA)(a1: v3);
    }
    else
    {
      v5 = *(const char **)(a2 + 112);
      *(_DWORD *)(a2 + 84) = v3;
      while ( 1 )
      {
        --*(_DWORD *)(a2 + 84);
        v6 = _mbtowc_l_0(
               DstCh: (wchar_t *)(a2 + 20),
               SrcCh: v5,
               SrcSizeInBytes: *(_DWORD *)(*(_DWORD *)(a2 + 88) + 172),
               Locale: (_locale_t)(a2 + 88));
        *(_DWORD *)(a2 - 8) = v6;
        if ( v6 <= 0 )
          break;
        ((void (__cdecl *)(_DWORD))loc_3F636FA5)(a1: *(_DWORD *)(a2 + 20));
        v5 += *(_DWORD *)(a2 - 8);
        if ( *(int *)(a2 + 84) <= 0 )
          goto LABEL_25;
      }
      *(_DWORD *)(a2 + 76) = -1;
    }
LABEL_25:
    if ( *(int *)(a2 + 76) >= 0 && (*(_BYTE *)(a2 + 128) & 4) != 0 )
      write_multi_char(result: a2 + 76, a2: 32, a3: v4);
  }
  if ( *(_DWORD *)(a2 + 24) != 0 )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a2 + 24));
    *(_DWORD *)(a2 + 24) = 0;
  }
LABEL_30:
  v7 = **(unsigned __int16 **)(a2 + 72);
  *(_DWORD *)(a2 + 84) = v7;
  if ( (_WORD)v7 != 0 )
    JUMPOUT(0x3F638498);
  if ( *(_DWORD *)(a2 + 48) != 0 && *(_DWORD *)(a2 + 48) != 7 )
  {
LABEL_50:
    *_errno_0() = 22;
    JUMPOUT(0x3F638C14);
  }
  if ( *(_DWORD *)(a2 + 116) == 1 && *(_DWORD *)(a2 + 108) == 0 )
  {
    v8 = 0;
    if ( *(int *)(a2 + 64) >= 0 )
    {
      v9 = *(_DWORD *)(a2 + 124);
      v10 = (_DWORD *)(a2 - 1608);
      while ( 1 )
      {
        if ( *(v10 - 1) == 1 || *(v10 - 1) == 2 )
          goto LABEL_45;
        if ( *(v10 - 1) != 3 && *(v10 - 1) != 4 )
          break;
        *v10 = v9;
        v9 += 8;
LABEL_46:
        *(_DWORD *)(a2 + 124) = v9;
LABEL_47:
        ++v8;
        v10 += 4;
        if ( v8 > *(_DWORD *)(a2 + 64) )
          goto LABEL_48;
      }
      if ( *(v10 - 1) != 5 )
      {
        if ( *(v10 - 1) != 7 )
          goto LABEL_50;
        *v10 = v9;
        get_int64_arg(a1: (_DWORD *)(a2 + 124));
        v9 = *(_DWORD *)(a2 + 124);
        goto LABEL_47;
      }
LABEL_45:
      *v10 = v9;
      v9 += 4;
      goto LABEL_46;
    }
  }
LABEL_48:
  if ( (int)++*(_DWORD *)(a2 + 108) < 2 )
    JUMPOUT(0x3F63845A);
  if ( *(_BYTE *)(a2 + 100) != 0 )
    *(_DWORD *)(*(_DWORD *)(a2 + 96) + 112) &= ~2u;
  __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 + 1156));
}

//------------------------------------------------------------------------------
// Address: 0x3F63936D
// Name: private: static class DName UnDecorator::getFunctionIndirectType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall UnDecorator::getFunctionIndirectType@<eax>(
        char a1@<zf>,
        __int16 _AX@<ax>,
        __int16 _DX@<dx>,
        char *a4@<ebx>,
        char **a5@<edi>)
{
  char *i; // esi
  size_t v8; // eax
  rsize_t v9; // ebp
  char *v10; // eax

  __asm
  {
    insb
    aaa
    aas
  }
  if ( a1 )
    JUMPOUT(0x3F63933E);
  for ( i = dword_3F663728; ; i += v9 )
  {
    if ( *i == (_BYTE)a4 )
    {
      ((void (__cdecl *)(char *))loc_3F609ED0)(a1: dword_3F663728);
      dword_3F663728 = a4;
      *a5 = a4;
      dword_3F667108 = 1;
      return 0;
    }
    v8 = strlen_0(Str: i);
    v9 = v8 + 1;
    if ( *i != 61 )
      break;
LABEL_8:
    ;
  }
  v10 = (char *)((int (__cdecl *)(size_t, int))loc_3F609A90)(a1: v8 + 1, a2: 1);
  *a5 = v10;
  if ( v10 != a4 )
  {
    if ( strcpy_s_0(Destination: v10, SizeInBytes: v9, Source: i) != 0 )
      _invoke_watson_0(
        Expression: (const wchar_t *)a4,
        FunctionName: (const wchar_t *)a4,
        FileName: (const wchar_t *)a4,
        LineNo: (unsigned int)a4,
        Reserved: (uintptr_t)a4);
    ++a5;
    goto LABEL_8;
  }
  ((void (__cdecl *)(int))loc_3F609ED0)(a1: dword_3F66376C);
  dword_3F66376C = (int)a4;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F6396AE
// Name: private: static class DName UnDecorator::getDataIndirectType(class DName const __near &,char,class DName const __near &,int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
DName *__usercall UnDecorator::getDataIndirectType@<eax>(WCHAR *a1@<eax>, char *a2@<ebx>, int a3@<ebp>)
{
  WCHAR *v3; // esi
  int v5; // eax
  int v6; // ebp
  char *v7; // eax
  char *ditType_4; // [esp+1Ch] [ebp-8h]
  int v9; // [esp+20h] [ebp-4h]

  v3 = a1;
  if ( a1 == (WCHAR *)a2 )
    return nullptr;
  for ( ; *a1 != (_WORD)a2; a1 = (WCHAR *)((char *)a1 + a3) )
  {
    do
      a1 = (WCHAR *)((char *)a1 + a3);
    while ( *a1 != (_WORD)a2 );
  }
  v9 = a1 - v3 + 1;
  v5 = WideCharToMultiByte(
         CodePage: (UINT)a2,
         dwFlags: (DWORD)a2,
         lpWideCharStr: v3,
         cchWideChar: v9,
         lpMultiByteStr: a2,
         cbMultiByte: (int)a2,
         lpDefaultChar: a2,
         lpUsedDefaultChar: (LPBOOL)a2);
  v6 = v5;
  if ( (char *)v5 != a2 )
  {
    v7 = (char *)((int (__cdecl *)(int))loc_3F609A30)(a1: v5);
    ditType_4 = v7;
    if ( v7 != a2 )
    {
      if ( WideCharToMultiByte(
             CodePage: (UINT)a2,
             dwFlags: (DWORD)a2,
             lpWideCharStr: v3,
             cchWideChar: v9,
             lpMultiByteStr: v7,
             cbMultiByte: v6,
             lpDefaultChar: a2,
             lpUsedDefaultChar: (LPBOOL)a2) == 0 )
      {
        ((void (__cdecl *)(char *))loc_3F609ED0)(a1: ditType_4);
        ditType_4 = a2;
      }
      a2 = ditType_4;
    }
  }
  FreeEnvironmentStringsW(penv: v3);
  return (DName *)a2;
}

//------------------------------------------------------------------------------
// Address: 0x3F639B92
// Name: public: UnDecorator::operator char __near *(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn UnDecorator::operator char *(
        UnDecorator *this@<ecx>,
        void (__thiscall *a2)(UnDecorator *, _DWORD)@<eax>,
        int a3@<ebp>)
{
  *(_DWORD *)(a3 - 4) = 0;
  a2(a1: this, a2: (unsigned __int16)__SS__);
  *(_DWORD *)(a3 - 4) = -2;
  abort_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F639CDE
// Name: private: static class DName UnDecorator::getPtrRefType(class DName const __near &,class DName const __near &,char)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl UnDecorator::getPtrRefType()
{
  JUMPOUT(0x3F639CE0);
}

//------------------------------------------------------------------------------
// Address: 0x3F639DF4
// Name: private: static class DName UnDecorator::getPointerType(class DName const __near &,class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getPointerType(
        char a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        unsigned int a4@<eax>,
        int a5@<ebx>,
        unsigned int a6@<edi>)
{
  if ( !(a2 ^ a3 | a1) )
  {
    if ( a4 < a6 && *(_DWORD *)(a4 + 4) == a5 )
      JUMPOUT(0x3F639DE4);
    JUMPOUT(0x3F639F07);
  }
  JUMPOUT(0x3F639E52);
}

//------------------------------------------------------------------------------
// Address: 0x3F639E0F
// Name: private: static class DName UnDecorator::getPointerTypeArray(class DName const __near &,class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::getPointerTypeArray(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  *(_DWORD *)(a2 - 4) = 0;
  if ( (a1 == a3 || a1 == 21) && dword_3F663D88 == 0 )
    JUMPOUT(0x3F639E28);
  if ( a1 == a3 )
    JUMPOUT(0x3F639ED3);
  if ( a1 - a3 != 4 )
  {
    switch ( a1 - a3 )
    {
      case 13:
        *(_DWORD *)(a2 - 28) = _decode_pointer_0(a1: (void *)dword_3F663D84);
        if ( a4 == a3 )
          goto LABEL_23;
        dword_3F663D84 = ((int (__cdecl *)(int))_encode_pointer_0)(a1: a4);
        break;
      case 19:
        *(_DWORD *)(a2 - 28) = _decode_pointer_0(a1: (void *)dword_3F663D7C);
        if ( a4 == a3 )
          goto LABEL_23;
        dword_3F663D7C = ((int (__cdecl *)(int))_encode_pointer_0)(a1: a4);
        break;
      case 20:
        goto LABEL_10;
      default:
        goto LABEL_23;
    }
LABEL_19:
    JUMPOUT(0x3F639EF1);
  }
LABEL_10:
  *(_DWORD *)(a2 - 28) = _decode_pointer_0(a1: (void *)dword_3F663D80);
  if ( a4 != a3 )
  {
    dword_3F663D80 = ((int (__cdecl *)(int))_encode_pointer_0)(a1: a4);
    goto LABEL_19;
  }
LABEL_23:
  JUMPOUT(0x3F639EF2);
}

//------------------------------------------------------------------------------
// Address: 0x3F639E2A
// Name: private: static class DName UnDecorator::getReferenceType(class DName const __near &,class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall UnDecorator::getReferenceType(int a1@<ebx>, int a2@<ebp>, int _EDI@<edi>, int a4@<esi>)
{
  int (__stdcall *v4)(unsigned int); // kr00_4
  BOOL v5; // [esp+90h] [ebp-4h]

  v4 = (int (__stdcall *)(unsigned int))__getcallerseflags();
  __asm { arpl    [edi], di }
  if ( !SetConsoleCtrlHandler(HandlerRoutine: v4, Add: v5) )
  {
    __doserrno_0();
    JUMPOUT(0x3F639E47);
  }
  dword_3F663D88 = 1;
  if ( a1 == _EDI )
    JUMPOUT(0x3F639ED3);
  if ( a1 - _EDI != 4 )
  {
    switch ( a1 - _EDI )
    {
      case 13:
        *(_DWORD *)(a2 - 28) = _decode_pointer_0(a1: (void *)dword_3F663D84);
        if ( a4 == _EDI )
          goto LABEL_23;
        dword_3F663D84 = ((int (__cdecl *)(int))_encode_pointer_0)(a1: a4);
        break;
      case 19:
        *(_DWORD *)(a2 - 28) = _decode_pointer_0(a1: (void *)dword_3F663D7C);
        if ( a4 == _EDI )
          goto LABEL_23;
        dword_3F663D7C = ((int (__cdecl *)(int))_encode_pointer_0)(a1: a4);
        break;
      case 20:
        goto LABEL_10;
      default:
        goto LABEL_23;
    }
LABEL_19:
    JUMPOUT(0x3F639EF1);
  }
LABEL_10:
  *(_DWORD *)(a2 - 28) = _decode_pointer_0(a1: (void *)dword_3F663D80);
  if ( a4 != _EDI )
  {
    dword_3F663D80 = ((int (__cdecl *)(int))_encode_pointer_0)(a1: a4);
    goto LABEL_19;
  }
LABEL_23:
  JUMPOUT(0x3F639EF2);
}

//------------------------------------------------------------------------------
// Address: 0x3F639EE8
// Name: ___unDNameEx
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __unDNameEx(char a1@<cf>, _BYTE *a2@<eax>, char a3@<bh>)
{
  *a2 += a3 + a1;
  JUMPOUT(0x3F639EEA);
}

//------------------------------------------------------------------------------
// Address: 0x3F639F8B
// Name: private: static class DName UnDecorator::getBasicDataType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall UnDecorator::getBasicDataType@<eax>(int a1@<eax>, int a2@<ebp>)
{
  *(_DWORD *)(a2 - 40) = a1;
  if ( a1 != 0 )
    ((void (__cdecl __noreturn *)(_DWORD))loc_3F639CC3)(a1: *(_DWORD *)(a1 + 92));
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F63A0C1
// Name: sub_3F63A0C1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F63A0C1()
{
  return sub_3F63A0C7();
}

//------------------------------------------------------------------------------
// Address: 0x3F63A0C7
// Name: sub_3F63A0C7
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63A103
// Name: sub_3F63A103
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LONG __cdecl sub_3F63A103(LONG a1)
{
  Target = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F63A10D
// Name: _rand_s_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl rand_s_0(_DWORD *a1)
{
  BOOLEAN (__stdcall *v1)(PVOID, ULONG); // eax
  BOOLEAN (__stdcall *v3)(PVOID, ULONG); // edi
  HMODULE LibraryA; // eax
  HMODULE v6; // ebx
  BOOLEAN (__stdcall *SystemFunction036)(PVOID, ULONG); // eax
  int *v8; // ebx
  DWORD LastError; // eax
  DWORD v10; // eax
  LONG v11; // esi
  int v12; // [esp+10h] [ebp+4h]

  v1 = (BOOLEAN (__stdcall *)(PVOID, ULONG))_decode_pointer_0(a1: (void *)Target);
  v3 = v1;
  if ( a1 == nullptr )
    goto LABEL_2;
  *a1 = 0;
  if ( v1 == nullptr )
  {
    LibraryA = LoadLibraryA(lpLibFileName: "ADVAPI32.DLL");
    v6 = LibraryA;
    if ( LibraryA == nullptr )
    {
LABEL_2:
      *_errno_0() = 22;
      _invalid_parameter_0();
      return 22;
    }
    SystemFunction036 = (BOOLEAN (__stdcall *)(PVOID, ULONG))GetProcAddress(
                                                               hModule: LibraryA,
                                                               lpProcName: "SystemFunction036");
    v3 = SystemFunction036;
    if ( SystemFunction036 == nullptr )
    {
      v8 = _errno_0();
      LastError = GetLastError();
      *v8 = _get_errno_from_oserr_0(a1: LastError);
      _invalid_parameter_0();
      v10 = GetLastError();
      return _get_errno_from_oserr_0(a1: v10);
    }
    v11 = ((int (__cdecl *)(BOOLEAN (__stdcall *)(PVOID, ULONG)))_encode_pointer_0)(a1: SystemFunction036);
    v12 = sub_3F62D76A();
    if ( InterlockedExchange(Target: &Target, Value: v11) != v12 )
      FreeLibrary(hLibModule: v6);
  }
  if ( ((int (__stdcall *)(_DWORD *, int))v3)(a1, a2: 4) != 0 )
    return 0;
  *_errno_0() = 12;
  return *_errno_0();
}

//------------------------------------------------------------------------------
// Address: 0x3F63A211
// Name: sub_3F63A211
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F63A211(int a1)
{
  dword_3F663D90 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F63A21B
// Name: __crtInitCritSecNoSpinCount(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall __crtInitCritSecNoSpinCount(LPCRITICAL_SECTION lpCriticalSection, int a2)
{
  InitializeCriticalSection(lpCriticalSection);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x3F63A2F0
// Name: sub_3F63A2F0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F63A2F0(int a1)
{
  dword_3F663D94 = a1;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x3F63A312
// Name: private: static class DName UnDecorator::getPrimaryDataType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63A450
// Name: private: static class DName UnDecorator::getDataType(class DName __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl UnDecorator::getDataType()
{
  JUMPOUT(0x3F63A451);
}

//------------------------------------------------------------------------------
// Address: 0x3F63A501
// Name: private: static class DName UnDecorator::getExternalDataType(class DName const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall UnDecorator::getExternalDataType(
        int a1@<eax>,
        void *a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        int *a5@<esi>)
{
  unsigned int v5; // eax
  int v6; // eax
  int v7; // eax
  HANDLE FileA; // eax
  HANDLE v9; // eax
  _BYTE *v10; // eax
  DWORD v11; // eax
  DWORD FileType; // eax
  _BYTE *v13; // eax
  DWORD LastError; // esi
  DWORD v15; // [esp-8h] [ebp-8h]

  if ( a1 != 64 )
LABEL_46:
    JUMPOUT(0x3F63A4A7);
  *(_DWORD *)(a3 - 16) = *(_DWORD *)(a3 - 8) == a4;
  v5 = *(_DWORD *)(a3 + 16) & 0x700;
  if ( v5 > 0x400 )
  {
    if ( v5 != 1280 )
    {
      if ( v5 == 1536 )
      {
LABEL_25:
        *(_DWORD *)(a3 - 20) = 5;
        goto LABEL_15;
      }
      if ( v5 != 1792 )
        goto LABEL_46;
    }
    *(_DWORD *)(a3 - 20) = 1;
  }
  else if ( v5 == 1024 || (void *)v5 == a2 )
  {
    *(_DWORD *)(a3 - 20) = 3;
  }
  else
  {
    if ( v5 != 256 )
    {
      if ( v5 != 512 )
      {
        if ( v5 == 768 )
          JUMPOUT(0x3F63A567);
        goto LABEL_46;
      }
      goto LABEL_25;
    }
    *(_DWORD *)(a3 - 20) = 4;
  }
LABEL_15:
  v6 = *(_DWORD *)(a3 + 16);
  *(_DWORD *)(a3 - 12) = 128;
  if ( (v6 & 0x100) != 0 && (*(_BYTE *)(a3 + 24) & ~(_BYTE)dword_3F663748 & 0x80u) == 0 )
    *(_DWORD *)(a3 - 12) = 1;
  if ( (v6 & 0x40) != 0 )
  {
    *(_DWORD *)(a3 - 12) |= 0x4000000u;
    *(_DWORD *)(a3 - 8) |= 0x10000u;
    if ( *(_DWORD *)(a3 - 40) == 2 )
      *(_DWORD *)(a3 - 16) |= 4u;
  }
  if ( (v6 & 0x1000) != 0 )
    *(_DWORD *)(a3 - 12) |= 0x100u;
  if ( (v6 & 0x20) != 0 )
  {
    *(_DWORD *)(a3 - 12) |= 0x8000000u;
  }
  else if ( (v6 & 0x10) != 0 )
  {
    *(_DWORD *)(a3 - 12) |= 0x10000000u;
  }
  v7 = ((int (*)(void))loc_3F63B355)();
  *a5 = v7;
  if ( v7 == -1 )
  {
    *__doserrno_0() = (unsigned int)a2;
    *a5 = -1;
    *_errno_0() = 24;
  }
  else
  {
    v15 = *(_DWORD *)(a3 - 12);
    **(_DWORD **)(a3 + 8) = 1;
    FileA = CreateFileA(
              lpFileName: *(LPCSTR *)(a3 + 12),
              dwDesiredAccess: *(_DWORD *)(a3 - 8),
              dwShareMode: *(_DWORD *)(a3 - 16),
              lpSecurityAttributes: (LPSECURITY_ATTRIBUTES)(a3 - 52),
              dwCreationDisposition: *(_DWORD *)(a3 - 20),
              dwFlagsAndAttributes: v15,
              hTemplateFile: a2);
    *(_DWORD *)(a3 - 28) = FileA;
    if ( FileA != (HANDLE)-1
      || (*(_DWORD *)(a3 - 8) & 0xC0000000) == 0xC0000000
      && (*(_BYTE *)(a3 + 16) & 1) != 0
      && (*(_DWORD *)(a3 - 8) &= ~0x80000000,
          v9 = CreateFileA(
                 lpFileName: *(LPCSTR *)(a3 + 12),
                 dwDesiredAccess: *(_DWORD *)(a3 - 8),
                 dwShareMode: *(_DWORD *)(a3 - 16),
                 lpSecurityAttributes: (LPSECURITY_ATTRIBUTES)(a3 - 52),
                 dwCreationDisposition: *(_DWORD *)(a3 - 20),
                 dwFlagsAndAttributes: *(_DWORD *)(a3 - 12),
                 hTemplateFile: a2),
          *(_DWORD *)(a3 - 28) = v9,
          v9 != (HANDLE)-1) )
    {
      FileType = GetFileType(hFile: *(HANDLE *)(a3 - 28));
      if ( (void *)FileType != a2 )
      {
        if ( FileType == 2 )
          JUMPOUT(0x3F63A71F);
        JUMPOUT(0x3F63A725);
      }
      v13 = (_BYTE *)(dword_3F665FE0[*a5 >> 5] + 56 * (*a5 & 0x1F) + 4);
      *v13 &= ~1u;
      LastError = GetLastError();
      _dosmaperr_0(a1: LastError);
      CloseHandle(hObject: *(HANDLE *)(a3 - 28));
      if ( (void *)LastError == a2 )
        *_errno_0() = 13;
    }
    else
    {
      v10 = (_BYTE *)(dword_3F665FE0[*a5 >> 5] + 56 * (*a5 & 0x1F) + 4);
      *v10 &= ~1u;
      v11 = GetLastError();
      _dosmaperr_0(a1: v11);
    }
  }
  _errno_0();
  JUMPOUT(0x3F63AB56);
}

//------------------------------------------------------------------------------
// Address: 0x3F63A722
// Name: __set_error_mode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _set_error_mode(int a1@<ebp>, _DWORD *a2@<esi>)
{
  ((void (__cdecl *)(_DWORD, _DWORD))loc_3F63B124)(a1: *a2, a2: *(_DWORD *)(a1 - 28));
  *(_BYTE *)(dword_3F665FE0[(int)*a2 >> 5] + 56 * (*a2 & 0x1F) + 4) = *(_BYTE *)(a1 - 1) | 1;
  JUMPOUT(0x3F63A765);
}

//------------------------------------------------------------------------------
// Address: 0x3F63A768
// Name: ___set_app_type
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __set_app_type(char a1@<zf>, int _EAX@<eax>, int a3@<edx>, int a4@<ecx>)
{
  int v4; // ecx

  v4 = a4 - 1;
  if ( a1 != 0 || v4 == 0 )
  {
    __asm { aas }
    *(_BYTE *)(a3 + _EAX + 36) &= 0x80u;
    JUMPOUT(0x3F63A773);
  }
  JUMPOUT(0x3F63A7C9);
}

//------------------------------------------------------------------------------
// Address: 0x3F63A778
// Name: __crtGetLocaleInfoW_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63A8B3
// Name: ___crtGetLocaleInfoW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __crtGetLocaleInfoW(unsigned int a1@<eax>, unsigned __int16 a2@<dx>, unsigned int a3@<ebx>)
{
  LOBYTE(a1) = __inbyte(a2);
  if ( a1 > a3 )
  {
    if ( a1 <= 2 )
      goto LABEL_8;
    if ( a1 <= 4 )
      JUMPOUT(0x3F63A9C6);
    if ( a1 == 5 )
LABEL_8:
      JUMPOUT(0x3F63AAD5);
  }
  JUMPOUT(0x3F63A8ED);
}

//------------------------------------------------------------------------------
// Address: 0x3F63A8EE
// Name: __crtGetLocaleInfoA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _crtGetLocaleInfoA_stat(int a1@<eax>, void *a2@<ebx>, int a3@<ebp>, _DWORD *a4@<esi>)
{
  int v4; // ebp
  _BYTE *v5; // eax
  bool v6; // zf
  _BYTE *v7; // eax
  int v8; // edi
  DWORD LastError; // eax
  _BYTE *v10; // eax

  v4 = a3 - 1;
  ++*(_BYTE *)(a1 + 137396193);
  v5 = (_BYTE *)(dword_3F665FE0[(int)*a4 >> 5] + 56 * (*a4 & 0x1F) + 36);
  v6 = *(_BYTE *)(v4 - 3) == (unsigned __int8)a2;
  *v5 = *v5 & 0x7F | ((unsigned __int8)BYTE2(*(_DWORD *)(v4 + 16)) << 7);
  if ( v6 && (*(_BYTE *)(v4 + 16) & 8) != 0 )
  {
    v7 = (_BYTE *)(dword_3F665FE0[(int)*a4 >> 5] + 56 * (*a4 & 0x1F) + 4);
    *v7 |= 0x20u;
  }
  v8 = *(_DWORD *)(v4 - 8);
  if ( (v8 & 0xC0000000) == 0xC0000000 && (*(_BYTE *)(v4 + 16) & 1) != 0 )
  {
    CloseHandle(hObject: *(HANDLE *)(v4 - 28));
    if ( CreateFileA(
           lpFileName: *(LPCSTR *)(v4 + 12),
           dwDesiredAccess: v8 & 0x7FFFFFFF,
           dwShareMode: *(_DWORD *)(v4 - 16),
           lpSecurityAttributes: (LPSECURITY_ATTRIBUTES)(v4 - 52),
           dwCreationDisposition: 3u,
           dwFlagsAndAttributes: *(_DWORD *)(v4 - 12),
           hTemplateFile: a2) == (HANDLE)-1 )
    {
      LastError = GetLastError();
      _dosmaperr_0(a1: LastError);
      v10 = (_BYTE *)(dword_3F665FE0[(int)*a4 >> 5] + 56 * (*a4 & 0x1F) + 4);
      *v10 &= ~1u;
      ((void (__cdecl *)(_DWORD))loc_3F63B1A1)(a1: *a4);
      JUMPOUT(0x3F63A6BC);
    }
    JUMPOUT(0x3F63AB3D);
  }
  JUMPOUT(0x3F63AB54);
}

//------------------------------------------------------------------------------
// Address: 0x3F63AA66
// Name: has_osfxsr_set
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall has_osfxsr_set(int a1@<eax>, int a2@<edx>)
{
  if ( (a2 & a1) == 0xFFFFFFFF )
    JUMPOUT(0x3F63A7B6);
  JUMPOUT(0x3F63A8D3);
}

//------------------------------------------------------------------------------
// Address: 0x3F63AAB6
// Name: __get_sse2_info
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _get_sse2_info(_DWORD *a1@<edi>)
{
  --*a1;
  JUMPOUT(0x3F63AABC);
}

//------------------------------------------------------------------------------
// Address: 0x3F63AB16
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __sse2_available_init()
{
  JUMPOUT(0x3F63AB22);
}

//------------------------------------------------------------------------------
// Address: 0x3F63AB23
// Name: _rt_probe_read4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge _rt_probe_read4(char a1@<al>, _BYTE *a2@<edi>, unsigned int *ptr)
{
  __asm { fucomip st, st(1) }
  *a2 = a1;
  JUMPOUT(0x3F63AB27);
}

//------------------------------------------------------------------------------
// Address: 0x3F63AB6E
// Name: __toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _toupper(char a1@<zf>)
{
  if ( a1 )
    JUMPOUT(0x3F63AB75);
  JUMPOUT(0x3F63AB50);
}

//------------------------------------------------------------------------------
// Address: 0x3F63AB76
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _toupper_l@<eax>(_DWORD *a1@<eax>, char *a2@<ebx>, int a3@<esi>)
{
  bool v4; // zf

  v4 = *a2 >> 6 == 0;
  *a2 >>= 6;
  if ( !v4 )
  {
    *(a1 - 1) = a3;
    *(a1 - 9) = ((int (__cdecl *)(_DWORD *, _DWORD, _DWORD, int, _DWORD))loc_3F63A402)(
                  a1: a1 - 8,
                  a2: a1[2],
                  a3: a1[3],
                  a4: 64,
                  a5: a1[4]);
    *(a1 - 1) = -2;
    JUMPOUT(0x3F63ABD7);
  }
  *_errno_0() = 22;
  _invalid_parameter_0();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x3F63AC8E
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63ACB5
// Name: __ungetc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ungetc_nolock@<eax>(char a1@<zf>, _DWORD *a2@<edi>)
{
  if ( !a1 )
    JUMPOUT(0x3F63AC97);
  return ((int (__cdecl *)(_DWORD))_LN9_16)(a1: *a2);
}

//------------------------------------------------------------------------------
// Address: 0x3F63ADD3
// Name: _ungetc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl ungetc()
{
  JUMPOUT(0x3F63AF41);
}

//------------------------------------------------------------------------------
// Address: 0x3F63AE45
// Name: __mbtowc_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _mbtowc_l@<eax>(
        unsigned __int8 *a1@<ebx>,
        int a2@<ebp>,
        unsigned int a3@<edi>,
        unsigned __int16 a4@<si>)
{
  int v4; // eax
  unsigned __int16 v5; // cx
  _BYTE *v6; // ebx
  unsigned __int16 v7; // cx
  int v8; // eax
  unsigned __int16 v9; // ax
  unsigned __int16 v10; // dx
  int v11; // ecx
  int result; // eax

  BYTE1(a1) = -16;
  v4 = *(_DWORD *)(a2 - 16);
  v5 = *a1;
  v6 = a1 + 1;
  if ( (*(_BYTE *)((unsigned __int8)v5 + v4 + 29) & 4) == 0 )
  {
    v10 = v5;
    v11 = v5 + v4;
    if ( (*(_BYTE *)(v11 + 29) & 0x10) != 0 )
      v7 = *(unsigned __int8 *)(v11 + 285);
    else
      v7 = v10;
LABEL_12:
    if ( v7 == a4 )
    {
      if ( a4 != 0 )
        JUMPOUT(0x3F63ADDE);
      if ( *(_BYTE *)(a2 - 8) != 0 )
        *(_DWORD *)(*(_DWORD *)(a2 - 12) + 112) &= ~2u;
      return 0;
    }
    else
    {
      result = v7 < a4 ? 1 : -1;
      if ( *(_BYTE *)(a2 - 8) != 0 )
        *(_DWORD *)(*(_DWORD *)(a2 - 12) + 112) &= ~2u;
    }
    return result;
  }
  if ( *v6 == 0 )
  {
    v7 = 0;
    goto LABEL_12;
  }
  v8 = __crtLCMapStringA_0(
         a1: (struct localeinfo_struct *)(a2 - 20),
         a2: *(struct localeinfo_struct **)(v4 + 12),
         a3,
         a4: (unsigned int)(v6 - 1),
         a5: (const char *)2,
         a6: a2 - 4,
         a7: (char *)2,
         a8: *(_DWORD *)(v4 + 4),
         a9: 1);
  if ( v8 == 1 )
  {
    v9 = *(unsigned __int8 *)(a2 - 4);
LABEL_8:
    v7 = v9;
    goto LABEL_12;
  }
  if ( v8 == 2 )
  {
    v9 = *(unsigned __int8 *)(a2 - 3) + (*(unsigned __int8 *)(a2 - 4) << 8);
    goto LABEL_8;
  }
  *_errno_0() = 22;
  if ( *(_BYTE *)(a2 - 8) != 0 )
    *(_DWORD *)(*(_DWORD *)(a2 - 12) + 112) &= ~2u;
  return 0x7FFFFFFF;
}

//------------------------------------------------------------------------------
// Address: 0x3F63AF45
// Name: sub_3F63AF45
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F63AF45(int a1, int a2)
{
  return ((int (__cdecl *)(int, int, _DWORD))loc_3F63AD2B)(a1, a2, a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x3F63AF58
// Name: _mbtowc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63B0C1
// Name: sub_3F63B0C1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl sub_3F63B0C1(wchar_t *pwc, char *s, unsigned int n)
{
  return mbtowc(pwc, s, n);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B0D8
// Name: sub_3F63B0D8
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void sub_3F63B0D8()
{
  dword_3F665FB0 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F63B0F1
// Name: __fputwc_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fputwc_nolock@<eax>(int a1@<eax>, _DWORD *_ECX@<ecx>)
{
  int result; // eax

  __asm { rcr     byte ptr [ecx-75h], 4Ch }
  LOBYTE(a1) = a1 & 4;
  _ECX[2] = a1;
  if ( (_BYTE)a1 != 0 )
  {
    _ECX[3] |= 8u;
    _ECX[6] = 4096;
  }
  else
  {
    _ECX[3] |= 4u;
    _ECX[2] = _ECX + 5;
    _ECX[6] = 2;
  }
  result = _ECX[2];
  _ECX[1] = 0;
  *_ECX = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63B2CF
// Name: _fputwc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall fputwc@<eax>(int a1@<ebx>, int a2@<ebp>, int a3@<edi>, int a4@<esi>)
{
  if ( *(_DWORD *)(a4 + 8) == a1 )
  {
    if ( ((int (__cdecl *)(int, int))__crtInitCritSecAndSpinCount_0)(a1: a4 + 12, a2: 4000) == 0 )
      *(_DWORD *)(a2 - 28) = a1;
    ++*(_DWORD *)(a4 + 8);
  }
  *(_DWORD *)(a2 - 4) = -2;
  sub_3F63B32A();
  if ( *(_DWORD *)(a2 - 28) != a1 )
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(dword_3F665FE0[a3 >> 5] + 56 * (a3 & 0x1F) + 12));
  return *(_DWORD *)(a2 - 28);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B32A
// Name: sub_3F63B32A
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63B347
// Name: _putwc
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void putwc()
{
  __asm { aas }
  JUMPOUT(0x3F63B349);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B34C
// Name: ___ansicp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __cdecl __ansicp()
{
  _RTL_CRITICAL_SECTION *v0; // [esp-4h] [ebp-4h]

  LeaveCriticalSection(lpCriticalSection: v0);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B428
// Name: sub_3F63B428
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63B4F4
// Name: __open_osfhandle_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __noreturn _open_osfhandle_0(intptr_t OSFileHandle, int Flags)
{
  DWORD LastError; // eax

  if ( GetFileType(hFile: (HANDLE)OSFileHandle) == 0 )
  {
    LastError = GetLastError();
    _dosmaperr_0(a1: LastError);
    JUMPOUT(0x3F63B53E);
  }
  JUMPOUT(0x3F63B547);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B545
// Name: ___report_gsfailure
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __report_gsfailure()
{
  int v0; // eax
  char v1; // bl
  int v2; // ebp
  unsigned int v3; // edi
  char v4; // bl
  int v5; // eax
  int v6; // esi
  int *v7; // ecx
  int v8; // eax

  v4 = v1 + 1;
  if ( v0 == 2 )
  {
    v4 |= 0x40u;
  }
  else if ( v0 == 3 )
  {
    v4 |= 8u;
  }
  v5 = ((int (*)(void))loc_3F63B355)();
  v6 = v5;
  *(_DWORD *)(v2 + 12) = v5;
  if ( v5 == -1 )
  {
    *_errno_0() = 24;
    *__doserrno_0() = v3;
  }
  else
  {
    *(_DWORD *)(v2 - 4) = v3;
    ((void (__cdecl *)(int, _DWORD))loc_3F63B124)(a1: v5, a2: *(_DWORD *)(v2 + 8));
    v7 = &dword_3F665FE0[v6 >> 5];
    v8 = 56 * (v6 & 0x1F);
    *(_BYTE *)(*v7 + v8 + 4) = v4 | 1;
    *(_BYTE *)(*v7 + v8 + 36) &= 0x80u;
    *(_BYTE *)(*v7 + v8 + 36) &= ~0x80u;
    *(_DWORD *)(v2 - 28) = 1;
    *(_DWORD *)(v2 - 4) = -2;
    sub_3F63B5E1();
  }
  JUMPOUT(0x3F63B541);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B5E1
// Name: sub_3F63B5E1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall sub_3F63B5E1@<eax>(int a1@<ebp>, int a2@<edi>, int a3@<esi>)
{
  _BYTE *v3; // eax

  if ( *(_DWORD *)(a1 - 28) == a2 )
  {
    v3 = (_BYTE *)(dword_3F665FE0[a3 >> 5] + 56 * (a3 & 0x1F) + 4);
    *v3 &= ~1u;
  }
  return ((int (__cdecl *)(int))_LN9_16)(a1: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B609
// Name: __write_nolock_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _write_nolock_0(int a1, int a2, int a3)
{
  if ( a3 != 0 )
  {
    if ( a2 == 0 )
    {
      *__doserrno_0() = 0;
      JUMPOUT(0x3F63B650);
    }
    JUMPOUT(0x3F63B670);
  }
  JUMPOUT(0x3F63BBB9);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B67B
// Name: __crtGetStringTypeW_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _crtGetStringTypeW_stat@<eax>(
        int a1@<ebx>,
        int a2@<ebp>,
        int a3@<esi>,
        localeinfo_struct *plocinfo,
        localeinfo_struct *dwInfoType,
        const wchar_t *lpSrcStr,
        const wchar_t *cchSrc,
        unsigned __int16 *lpCharType,
        unsigned __int16 *code_page,
        int lcid)
{
  int v10; // ebx
  int *v11; // edi
  int v12; // eax
  char v13; // cl
  BOOL v14; // esi
  UINT ConsoleCP; // eax
  bool v16; // zf
  char *v17; // esi
  char v18; // al
  DWORD v19; // eax
  signed int v20; // esi
  signed int v21; // eax
  int v22; // eax
  int v23; // ecx
  UINT v25; // [esp-14h] [ebp-24h]
  unsigned __int8 *buffer; // [esp+8h] [ebp-8h]
  __int16 v27; // [esp+Ch] [ebp-4h]

  v10 = 56 * a1;
  v11 = &dword_3F665FE0[a3 >> 5];
  v12 = v10 + *MK_FP(v27, v11);
  v13 = (char)(2 * *MK_FP(v27, v12 + 36)) >> 1;
  *(_DWORD *)(a2 - 112) = v11;
  *(_BYTE *)(a2 - 85) = v13;
  if ( (v13 == 2 || v13 == 1) && (*(_BYTE *)(a2 + 1320) & 1) != 0 )
  {
    *MK_FP(v27, __doserrno_0()) = 0;
    *MK_FP(v27, _errno_0()) = 22;
    _invalid_parameter_0();
    JUMPOUT(0x3F63BBAF);
  }
  if ( (*MK_FP(v27, v12 + 4) & 0x20) != 0 )
    _lseeki64_nolock_0(a1: a3, a2: 0, a3: 0, dwMoveMethod: 2u);
  if ( _isatty_0(FileHandle: a3) == 0
    || (char)*MK_FP(v27, v10 + *MK_FP(v27, v11) + 4) >= 0
    || (v14 = *MK_FP(v27, *MK_FP(v27, _getptd_0() + 27) + 20) == 0,
        !GetConsoleMode(hConsoleHandle: (HANDLE)*MK_FP(v27, v10 + *MK_FP(v27, v11)), lpMode: (LPDWORD)(a2 - 124)))
    || v14 && *(_BYTE *)(a2 - 85) == 0 )
  {
    JUMPOUT(0x3F63B8F4);
  }
  ConsoleCP = GetConsoleCP();
  *(_DWORD *)(a2 - 80) = 0;
  v16 = *(_DWORD *)(a2 + 1320) == 0;
  v17 = *(char **)(a2 - 100);
  *(_DWORD *)(a2 - 124) = ConsoleCP;
  *(_DWORD *)(a2 - 116) = v17;
  if ( v16 )
    JUMPOUT(0x3F63BB61);
  *(_DWORD *)(a2 - 92) = 0;
  v18 = *(_BYTE *)(a2 - 85);
  if ( v18 == 0 )
  {
    buffer = (unsigned __int8 *)(char)*MK_FP(v27, v17);
    *(_DWORD *)(a2 - 120) = *MK_FP(v27, v17) == 10;
    if ( ((int (__cdecl *)(unsigned __int8 *))loc_3F62AC5B)(a1: buffer) != 0 )
    {
      if ( (unsigned int)(*(_DWORD *)(a2 + 1320) + *(_DWORD *)(a2 - 100) - (_DWORD)v17) <= 1
        || sub_3F64C5AB(DstCh: (wchar_t *)(a2 - 84), SrcCh: v17, SrcSizeInBytes: 2u) == -1 )
      {
        goto L_1_0;
      }
      ++v17;
      ++*(_DWORD *)(a2 - 92);
    }
    else if ( sub_3F64C5AB(DstCh: (wchar_t *)(a2 - 84), SrcCh: v17, SrcSizeInBytes: 1u) == -1 )
    {
      goto L_1_0;
    }
    v25 = *(_DWORD *)(a2 - 124);
    ++*(_DWORD *)(a2 - 92);
    *(_DWORD *)(a2 - 116) = v17 + 1;
    v19 = WideCharToMultiByte(
            CodePage: v25,
            dwFlags: 0,
            lpWideCharStr: (LPCWCH)(a2 - 84),
            cchWideChar: 1,
            lpMultiByteStr: (LPSTR)(a2 + 1292),
            cbMultiByte: 5,
            lpDefaultChar: nullptr,
            lpUsedDefaultChar: nullptr);
    v20 = v19;
    if ( v19 == 0 )
      goto L_1_0;
    if ( WriteFile(
           hFile: (HANDLE)*MK_FP(v27, v10 + *MK_FP(v27, v11)),
           lpBuffer: (LPCVOID)(a2 + 1292),
           nNumberOfBytesToWrite: v19,
           lpNumberOfBytesWritten: (LPDWORD)(a2 - 80),
           lpOverlapped: nullptr) )
    {
      v21 = *(_DWORD *)(a2 - 80);
      *(_DWORD *)(a2 - 96) += v21;
      if ( v21 < v20 )
        goto L_1_0;
      if ( *(_DWORD *)(a2 - 120) == 0 )
LABEL_45:
        JUMPOUT(0x3F63B8E0);
      v22 = *MK_FP(v27, v11);
      *(_BYTE *)(a2 + 1292) = 13;
      if ( WriteFile(
             hFile: (HANDLE)*MK_FP(v27, v10 + v22),
             lpBuffer: (LPCVOID)(a2 + 1292),
             nNumberOfBytesToWrite: 1u,
             lpNumberOfBytesWritten: (LPDWORD)(a2 - 80),
             lpOverlapped: nullptr) )
      {
        if ( *(int *)(a2 - 80) >= 1 )
        {
          ++*(_DWORD *)(a2 - 104);
          ++*(_DWORD *)(a2 - 96);
          goto LABEL_45;
        }
L_1_0:
        JUMPOUT(0x3F63BB57);
      }
    }
    JUMPOUT(0x3F63BB4E);
  }
  if ( v18 != 1 && v18 != 2 )
    return __crtGetStringTypeW(
             plocinfo,
             (unsigned int)dwInfoType,
             lpSrcStr,
             (int)cchSrc,
             lpCharType,
             (int)code_page,
             lcid);
  v23 = (unsigned __int16)*MK_FP(v27, v17);
  *(_DWORD *)(a2 - 92) += 2;
  *(_DWORD *)(a2 - 84) = v23;
  *(_DWORD *)(a2 - 116) = v17 + 2;
  *(_DWORD *)(a2 - 120) = (_WORD)v23 == 10;
  return __crtGetStringTypeW(
           plocinfo,
           (unsigned int)dwInfoType,
           lpSrcStr,
           (int)cchSrc,
           lpCharType,
           (int)code_page,
           lcid);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B89F
// Name: ___crtGetStringTypeW
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall __crtGetStringTypeW@<eax>(
        char a1@<al>,
        int a2@<ebp>,
        localeinfo_struct *plocinfo,
        localeinfo_struct *dwInfoType,
        const wchar_t *lpSrcStr,
        const wchar_t *cchSrc)
{
  if ( a1 == 1 || a1 == 2 )
  {
    if ( _putwch_nolock_0(Character: *(_DWORD *)(a2 - 84)) != *(_WORD *)(a2 - 84) )
      goto LABEL_12;
    ++*(_DWORD *)(a2 - 96);
    if ( *(_DWORD *)(a2 - 120) != 0 )
    {
      *(_DWORD *)(a2 - 84) = 13;
      if ( _putwch_nolock_0(Character: 0xDu) != *(_WORD *)(a2 - 84) )
LABEL_12:
        JUMPOUT(0x3F63BB4E);
      ++*(_DWORD *)(a2 - 96);
      return x_ismbbtype_l(plocinfo, tst: (unsigned int)dwInfoType, cmask: (int)lpSrcStr, kmask: (int)cchSrc);
    }
  }
  JUMPOUT(0x3F63B8E0);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B8DD
// Name: x_ismbbtype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall x_ismbbtype_l(int a1@<ebp>)
{
  ++*(_DWORD *)(a1 - 104);
  if ( *(_DWORD *)(a1 - 92) >= *(_DWORD *)(a1 + 1320) )
    JUMPOUT(0x3F63BB57);
  JUMPOUT(0x3F63B768);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B92E
// Name: __ismbbkalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ismbbkalnum_l(int a1@<eax>)
{
  BYTE1(a1) = 59;
  ++*(_DWORD *)(a1 - 80);
  JUMPOUT(0x3F63B941);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B943
// Name: __ismbbkalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ismbbkalnum@<eax>(_BYTE *a1@<eax>, char a2@<dl>, int a3@<ebp>, unsigned int tst, localeinfo_struct *a5)
{
  ++*(_DWORD *)(a3 - 104);
  *a1 = 13;
  ++*(_DWORD *)(a3 - 92);
  a1[1] = a2;
  ++*(_DWORD *)(a3 - 92);
  return _ismbbkprint_l(tst, plocinfo: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B956
// Name: __ismbbkprint_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ismbbkprint_l@<eax>(int a1@<ebp>, unsigned int tst)
{
  if ( *(_DWORD *)(a1 - 92) < 0x400u )
    JUMPOUT(0x3F63B930);
  return _ismbbkprint(tst);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B96B
// Name: __ismbbkprint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _ismbbkprint@<eax>(
        int a1@<ebx>,
        int a2@<ebp>,
        _DWORD *a3@<edi>,
        unsigned int tst,
        localeinfo_struct *a5)
{
  DWORD v6; // [esp-4h] [ebp-Ch]
  unsigned int *v7; // [esp+0h] [ebp-8h]
  _OVERLAPPED *v8; // [esp+4h] [ebp-4h]

  WriteFile(
    hFile: *(HANDLE *)(a1 + *a3),
    lpBuffer: (LPCVOID)(a2 - 76),
    nNumberOfBytesToWrite: v6,
    lpNumberOfBytesWritten: v7,
    lpOverlapped: v8);
  return _ismbbkpunct_l(tst, plocinfo: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B97E
// Name: __ismbbkpunct_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ismbbkpunct_l(char a1@<zf>, int a2@<ebp>, int a3@<esi>)
{
  int v3; // eax

  if ( !a1 )
  {
    v3 = *(_DWORD *)(a2 - 108);
    *(_DWORD *)(a2 - 96) += v3;
    if ( v3 >= a3 )
      JUMPOUT(0x3F63B992);
    JUMPOUT(0x3F63BB57);
  }
  JUMPOUT(0x3F63BB4E);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B993
// Name: __ismbbkpunct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ismbbkpunct(unsigned int a1@<eax>, int a2@<ebp>)
{
  LOBYTE(a1) = 43;
  __readeflags();
  if ( a1 >= *(_DWORD *)(a2 + 1322) )
    JUMPOUT(0x3F63BB57);
  JUMPOUT(0x3F63B923);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B9A6
// Name: __ismbbalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ismbbalnum_l(char a1@<sf>, char a2@<of>, int a3@<eax>)
{
  _DWORD *v3; // eax

  if ( a1 != a2 )
  {
    v3 = (_DWORD *)(a3 + 1166606336);
    LOBYTE(v3) = 15;
    *v3 += v3;
    JUMPOUT(0x3F63B9BD);
  }
  JUMPOUT(0x3F63B953);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B9BE
// Name: __ismbbalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ismbbalnum@<eax>(int a1@<ebp>, unsigned int tst, localeinfo_struct *a3)
{
  if ( (unsigned int)(*(_DWORD *)(a1 - 80) - *(_DWORD *)(a1 - 100)) >= *(_DWORD *)(a1 + 1320) )
    return _ismbbgraph_l(tst, plocinfo: a3);
  else
    return _ismbbalpha_l(tst, plocinfo: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B9D4
// Name: __ismbbalpha_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ismbbalpha_l@<eax>(_WORD *a1@<eax>, _WORD *a2@<edx>, int a3@<ebp>, unsigned int tst)
{
  *(_DWORD *)(a3 - 80) += 2;
  if ( *a2 != 10 )
    JUMPOUT(0x3F63B9F0);
  *(_DWORD *)(a3 - 104) += 2;
  *a1 = 13;
  return _ismbbalpha(tst);
}

//------------------------------------------------------------------------------
// Address: 0x3F63B9EC
// Name: __ismbbalpha
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ismbbalpha@<eax>(int a1@<eax>, __int16 a2@<dx>, int a3@<esi>, unsigned int tst, localeinfo_struct *a5)
{
  *(_WORD *)(a1 + 2) = a2;
  if ( (unsigned int)(a3 + 4) < 0x3FF )
    JUMPOUT(0x3F63B9C9);
  return _ismbbgraph_l(tst, plocinfo: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BA02
// Name: __ismbbgraph_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63BA1A
// Name: __ismbbgraph
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ismbbgraph(char a1@<cf>, int a2@<eax>, int a3@<ebp>)
{
  if ( (BOOL (__stdcall **)(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED))((char *)&WriteFile + a1 + a2) != nullptr )
  {
    *(_DWORD *)(a3 - 96) += *(_DWORD *)(a3 - 108);
    JUMPOUT(0x3F63BA2F);
  }
  JUMPOUT(0x3F63BB4E);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BA30
// Name: __ismbbprint_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ismbbprint_l@<eax>(
        unsigned int a1@<eax>,
        _WORD *a2@<edx>,
        char a3@<cl>,
        int a4@<ebx>,
        int a5@<ebp>,
        unsigned int tst,
        localeinfo_struct *plocinfo)
{
  *a2 = __FS__;
  *(_DWORD *)a1 += a1;
  *(_BYTE *)(a4 + 1160491077) += a3;
  __readeflags();
  if ( a1 >= *(_DWORD *)(a5 + 1320) )
    JUMPOUT(0x3F63BA47);
  return _ismbbalnum(a1: a5, tst, a3: plocinfo);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BA48
// Name: __ismbbprint
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ismbbprint()
{
  JUMPOUT(0x3F63BA4A);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BA73
// Name: __ismbbpunct
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ismbbpunct(char a1@<dh>, int a2@<ebx>, int a3@<ebp>, int a4@<esi>)
{
  *(_BYTE *)(a2 + 44) += a1;
  *(_DWORD *)(a3 - 92) += a4;
  JUMPOUT(0x3F63BA85);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BA86
// Name: __ismbblead_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ismbblead_l(_WORD *a1@<eax>, __int16 a2@<dx>, char a3@<cl>, int a4@<ebp>, int a5@<esi>)
{
  BYTE1(a1) |= *(_BYTE *)(a5 - 57);
  MEMORY[0x1C60300] += a3;
  if ( MEMORY[0x1C60300] == 0 )
  {
    *(_DWORD *)(a4 - 80) += a5;
    *a1 = a2;
    JUMPOUT(0x3F63BA99);
  }
  JUMPOUT(0x3F63BA41);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BA9B
// Name: __ismbblead
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63BAC3
// Name: __ismbbtrail
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _ismbbtrail(int a1@<esi>)
{
  DWORD v1; // [esp-18h] [ebp-1Ch]
  const WCHAR *v2; // [esp-14h] [ebp-18h]
  int v3; // [esp-10h] [ebp-14h]
  char *v4; // [esp-Ch] [ebp-10h]
  int v5; // [esp-8h] [ebp-Ch]
  const CHAR *v6; // [esp-4h] [ebp-8h]
  int *v7; // [esp+0h] [ebp-4h]

  if ( WideCharToMultiByte(
         CodePage: 0xFDE9u,
         dwFlags: v1,
         lpWideCharStr: v2,
         cchWideChar: v3,
         lpMultiByteStr: v4,
         cbMultiByte: v5,
         lpDefaultChar: v6,
         lpUsedDefaultChar: v7) != a1 )
    JUMPOUT(0x3F63BAD5);
  JUMPOUT(0x3F63BB4E);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BAD6
// Name: __ismbbkana_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ismbbkana_l(char a1@<cl>, int a2@<ebp>)
{
  *(_BYTE *)(a2 - 1957653435) += a1;
  JUMPOUT(0x3F63BADC);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BB37
// Name: fastzero_I
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall fastzero_I(int a1@<eax>, int a2@<ebp>)
{
  int v2; // eax

  if ( (BOOL (__stdcall **)(HANDLE, LPCVOID, DWORD, LPDWORD, LPOVERLAPPED))((char *)&WriteFile + a1) != nullptr )
  {
    v2 = *(_DWORD *)(a2 - 108);
    *(_DWORD *)(a2 - 84) = 0;
    *(_DWORD *)(a2 - 96) = v2;
  }
  else
  {
    *(_DWORD *)(a2 - 84) = GetLastError();
  }
  if ( *(_DWORD *)(a2 - 96) == 0 )
  {
    if ( *(_DWORD *)(a2 - 84) != 0 )
    {
      if ( *(_DWORD *)(a2 - 84) == 5 )
      {
        *_errno_0() = 9;
        JUMPOUT(0x3F63BBA8);
      }
      _dosmaperr_0(a1: *(_DWORD *)(a2 - 84));
      JUMPOUT(0x3F63BBAF);
    }
    JUMPOUT(0x3F63BB8A);
  }
  JUMPOUT(0x3F63BBB4);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BB8E
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _VEC_memzero(int a1@<eax>, int a2@<ebp>, unsigned int a3@<esi>)
{
  if ( a1 == -1 || **(_BYTE **)(a2 - 100) != 26 )
  {
    *_errno_0() = 28;
    *__doserrno_0() = a3;
  }
  __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 + 1300));
}

//------------------------------------------------------------------------------
// Address: 0x3F63BC1D
// Name: __get_daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _get_daylight(char a1@<dl>, int a2@<edi>)
{
  *(_BYTE *)(a2 + 87) += a1;
  _invalid_parameter_0();
  JUMPOUT(0x3F63BBF6);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BC85
// Name: __get_timezone
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _get_timezone(_DWORD *this)
{
  --*(this - 116170546);
  JUMPOUT(0x3F63BC8F);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BCB9
// Name: __get_tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _get_tzname(char a1@<al>, int a2@<ebx>)
{
  *(_BYTE *)(a2 + 326500088) |= a1;
  *_errno_0() = 9;
  JUMPOUT(0x3F63BD7C);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BD5B
// Name: ___daylight
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __daylight()
{
  __inbyte(0x89u);
  JUMPOUT(0x3F63BD65);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BD6D
// Name: ___tzname
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __tzname(int a1@<ebp>)
{
  *(_DWORD *)(a1 - 4) = -2;
  JUMPOUT(0x3F63BD74);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BD82
// Name: sub_3F63BD82
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall sub_3F63BD82(int a1@<ebp>)
{
  ((void (__cdecl *)(_DWORD))_LN9_16)(a1: *(_DWORD *)(a1 + 8));
  JUMPOUT(0x3F63BD8B);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BDA0
// Name: sub_3F63BDA0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sub_3F63BDA0()
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F63BDEA
// Name: __wctomb_s_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl _wctomb_s_l_0(int *SizeConverted, char *MbCh, size_t SizeInBytes, wchar_t WCh, _locale_t Locale)
{
  char *v5; // esi
  size_t v6; // edi
  errno_t result; // eax
  errno_t v8; // esi
  int v9; // eax
  _LocaleUpdate v10; // [esp+Ch] [ebp-10h] BYREF

  v5 = MbCh;
  v6 = SizeInBytes;
  if ( MbCh == nullptr && SizeInBytes != 0 )
  {
    if ( SizeConverted != nullptr )
      *SizeConverted = 0;
    return 0;
  }
  if ( SizeConverted != nullptr )
    *SizeConverted = -1;
  if ( v6 > 0x7FFFFFFF )
  {
    v8 = 22;
    *_errno_0() = 22;
    _invalid_parameter_0();
    return v8;
  }
  _LocaleUpdate::_LocaleUpdate(this: &v10, a2: Locale);
  if ( v10.localeinfo.locinfo->lc_handle[2] == 0 )
  {
    if ( WCh > 0xFFu )
    {
      if ( v5 != nullptr && v6 != 0 )
        memset(a1: v5, Val: 0, Size: v6);
      goto LABEL_16;
    }
    if ( v5 != nullptr )
    {
      if ( v6 == 0 )
      {
LABEL_21:
        v8 = 34;
        *_errno_0() = 34;
        _invalid_parameter_0();
        if ( v10.updated )
          v10.ptd->_ownlocale &= ~2u;
        return v8;
      }
      *v5 = WCh;
    }
    if ( SizeConverted != nullptr )
      *SizeConverted = 1;
LABEL_26:
    if ( v10.updated )
      v10.ptd->_ownlocale &= ~2u;
    return 0;
  }
  MbCh = nullptr;
  v9 = WideCharToMultiByte(
         CodePage: v10.localeinfo.locinfo->lc_codepage,
         dwFlags: 0,
         lpWideCharStr: &WCh,
         cchWideChar: 1,
         lpMultiByteStr: v5,
         cbMultiByte: v6,
         lpDefaultChar: nullptr,
         lpUsedDefaultChar: (LPBOOL)&MbCh);
  if ( v9 != 0 )
  {
    if ( MbCh == nullptr )
    {
      if ( SizeConverted != nullptr )
        *SizeConverted = v9;
      goto LABEL_26;
    }
  }
  else if ( GetLastError() == 122 )
  {
    if ( v5 != nullptr && v6 != 0 )
      memset(a1: v5, Val: 0, Size: v6);
    goto LABEL_21;
  }
LABEL_16:
  *_errno_0() = 42;
  result = *_errno_0();
  if ( v10.updated )
    v10.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63BF49
// Name: sub_3F63BF49
// Source: linker_block_proximity
//------------------------------------------------------------------------------
errno_t __cdecl sub_3F63BF49(int *SizeConverted, char *MbCh, size_t SizeInBytes, wchar_t WCh)
{
  return _wctomb_s_l_0(SizeConverted, MbCh, SizeInBytes, WCh, Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x3F63BF64
// Name: __wctomb_l_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _wctomb_l_0(char *MbCh, wchar_t WCh, _locale_t Locale)
{
  int result; // eax
  _LocaleUpdate v4; // [esp+0h] [ebp-14h] BYREF
  int SizeConverted; // [esp+10h] [ebp-4h] BYREF

  SizeConverted = -1;
  _LocaleUpdate::_LocaleUpdate(this: &v4, a2: Locale);
  if ( _wctomb_s_l_0(&SizeConverted, MbCh, SizeInBytes: v4.localeinfo.locinfo->mb_cur_max, WCh, Locale: &v4.localeinfo) != 0 )
    result = -1;
  else
    result = SizeConverted;
  if ( v4.updated )
    v4.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63BFB3
// Name: _wctomb_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wctomb_0(char *MbCh, wchar_t WCh)
{
  size_t v2; // eax
  int SizeConverted; // [esp+0h] [ebp-4h] BYREF

  SizeConverted = -1;
  v2 = ((int (*)(void))loc_3F63EC45)();
  if ( _wctomb_s_l_0(&SizeConverted, MbCh, SizeInBytes: v2, WCh, Locale: nullptr) != 0 )
    return -1;
  else
    return SizeConverted;
}

//------------------------------------------------------------------------------
// Address: 0x3F63C016
// Name: _write_multi_char_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall write_multi_char_0@<eax>(int result@<eax>, char a2, int a3, int a4)
{
  _DWORD *v4; // esi

  v4 = (_DWORD *)result;
  do
  {
    if ( a3 <= 0 )
      break;
    --a3;
    result = ((int (__thiscall *)(int))write_char)(a1: a4);
  }
  while ( *v4 != -1 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63C2D5
// Name: _isindst_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall isindst_nolock(int this)
{
  *(_BYTE *)(this - 806764475) = __ROR1__(*(_BYTE *)(this - 806764475), 1);
  JUMPOUT(0x3F63C2DC);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C483
// Name: ___tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __tzset(_BYTE *a1@<eax>, unsigned __int8 a2@<cl>, int a3@<ebp>)
{
  bool v3; // zf

  v3 = a2 == *a1;
  *a1 ^= a2;
  if ( v3 )
    *(_DWORD *)(a3 - 24) |= 0x800u;
  JUMPOUT(0x3F63C4FC);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C4D2
// Name: __tzset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _tzset()
{
  __asm { fadd    st(7), st }
  JUMPOUT(0x3F63C868);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C50A
// Name: __isindst
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _isindst(int a1@<ebp>, int a2@<edi>)
{
  if ( sub_3F63BF49(
         SizeConverted: (int *)(a1 - 40),
         MbCh: (char *)(a1 - 20),
         SizeInBytes: 0x200u,
         WCh: *(_WORD *)(a2 - 4)) != 0 )
    *(_DWORD *)(a1 - 104) = 1;
  *(_DWORD *)(a1 - 36) = a1 - 20;
  JUMPOUT(0x3F63C895);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C54B
// Name: __strnicmp_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _strnicmp_l(int a1@<eax>, int a2@<ebp>, int a3@<edi>)
{
  int v3; // ecx
  bool v4; // zf
  const char *v5; // eax

  *(_DWORD *)(a2 - 44) = a3 + 4;
  if ( a1 != 0 && (v3 = *(_DWORD *)(a1 + 4)) != 0 )
  {
    v4 = (*(_WORD *)(a2 - 24) & 0x800) == 0;
    *(_DWORD *)(a2 - 36) = v3;
    *(_DWORD *)(a2 - 68) = !v4;
  }
  else
  {
    v5 = Str;
    *(_DWORD *)(a2 - 36) = Str;
    strlen_0(Str: v5);
  }
  JUMPOUT(0x3F63C892);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C63B
// Name: __strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _strnicmp@<eax>(
        char a1@<zf>,
        char *a2@<ecx>,
        int a3@<ebp>,
        int a4@<edi>,
        int a5@<esi>,
        const char *dst,
        const char *src,
        const char *count)
{
  int v8; // edi

  if ( a1 )
    *(_DWORD *)(a3 - 32) = 1;
  v8 = a5 + a4;
  *(_DWORD *)(a3 - 128) = *(_DWORD *)(v8 - 8);
  *(_DWORD *)(a3 - 124) = *(_DWORD *)(v8 - 4);
  return xtoa_s(val: a3 - 92, buf: a2, sizeInTChars: (unsigned int)dst, radix: (unsigned int)src, is_neg: (int)count);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C697
// Name: xtoa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall xtoa_s(unsigned int val@<eax>, char a2@<dl>, _BYTE *a3@<ebx>, int a4@<ebp>, int a5@<edi>)
{
  void (__cdecl *v6)(int, _BYTE *, int, int, int, int, unsigned int); // eax
  int v7; // edi
  void (__cdecl *v8)(_BYTE *, int); // eax
  void (__cdecl *v9)(_BYTE *, int); // eax
  int v10; // [esp-10h] [ebp-14h]
  int v11; // [esp-Ch] [ebp-10h]
  int v12; // [esp-8h] [ebp-Ch]
  int v13; // [esp-4h] [ebp-8h]

  v13 = *(_DWORD *)(a4 - 116);
  v12 = *(_DWORD *)(a4 - 32);
  *(_DWORD *)(a4 - 44) = a5;
  v11 = a2;
  v10 = *(_DWORD *)(a4 - 108);
  v6 = (void (__cdecl *)(int, _BYTE *, int, int, int, int, unsigned int))_decode_pointer_0(a1: (void *)s_NoEscConversion.m_pReplacements[199].m_nLength);
  v6(a1: a4 - 128, a2: a3, a3: v10, a4: v11, a5: v12, a6: v13, a7: val);
  v7 = *(_DWORD *)(a4 - 24) & 0x80;
  if ( v7 != 0 && *(_DWORD *)(a4 - 32) == 0 )
  {
    v8 = (void (__cdecl *)(_BYTE *, int))_decode_pointer_0(a1: s_NoEscConversion.m_pReplacements[200].m_pReplacementString);
    v8(a1: a3, a2: a4 - 92);
  }
  if ( *(_BYTE *)(a4 - 25) == 103 && v7 == 0 )
  {
    v9 = (void (__cdecl *)(_BYTE *, int))_decode_pointer_0(a1: (void *)s_NoEscConversion.m_pReplacements[200].m_nLength);
    v9(a1: a3, a2: a4 - 92);
  }
  if ( *a3 == 45 )
  {
    *(_DWORD *)(a4 - 24) |= 0x100u;
    *(_DWORD *)(a4 - 36) = a3 + 1;
  }
  JUMPOUT(0x3F63C58D);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C772
// Name: __itoa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _itoa_s()
{
  JUMPOUT(0x3F63C774);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C79A
// Name: __ltoa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ltoa_s(int a1@<edx>, char a2@<cl>, int a3@<ebp>, int a4@<edi>)
{
  *(_DWORD *)(a3 - 44) = a4;
  if ( (a2 & 0x40) != 0 && a1 < 0 )
    JUMPOUT(0x3F63C7B9);
  JUMPOUT(0x3F63C7C0);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C7BF
// Name: __ultoa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ultoa_s(char a1@<ah>, int a2@<ebp>, int a3@<esi>)
{
  *(_BYTE *)(a3 - 9) += a1;
  MEMORY[0x19EF57C8]();
  if ( *(int *)(a2 - 31) < 0 )
    JUMPOUT(0x3F63C7D4);
  JUMPOUT(0x3F63C7DD);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C7D7
// Name: x64toa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __userpurge x64toa_s(
        _DWORD *a1@<eax>,
        unsigned __int64 val,
        unsigned int sizeInTChars,
        unsigned int radix,
        unsigned int is_neg)
{
  *a1 += a1;
  JUMPOUT(0x3F63C7D9);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C8CD
// Name: __i64toa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _i64toa_s(_BYTE *_EBX@<ebx>)
{
  *_EBX = 0;
  __asm { fsubr   dword ptr [ebx] }
  JUMPOUT(0x3F63C8D3);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C900
// Name: __ui64toa_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _ui64toa_s(char a1@<zf>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>)
{
  if ( !a1 && (*(_BYTE *)(a3 - 24) & 4) == 0 )
    write_multi_char_0(result: a3 - 52, a2: 48, a3: a2, a4);
  JUMPOUT(0x3F63C91C);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C91D
// Name: __fptrap
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _fptrap@<eax>(int a1@<esi>, int a2, __int64 a3)
{
  *(char *)(a1 + 77) >>= 7;
  return _chsize_nolock(filedes: a2, size: a3);
}

//------------------------------------------------------------------------------
// Address: 0x3F63C926
// Name: __chsize_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _chsize_nolock(char a1@<zf>, int a2@<eax>, int a3@<ebx>, int a4@<ebp>, int a5@<edi>, wchar_t *a6@<esi>)
{
  wchar_t v6; // ax
  char v7; // al

  if ( !a1 )
    JUMPOUT(0x3F63C904);
  *(_DWORD *)(a4 - 108) = a2;
  while ( 1 )
  {
    v6 = *a6;
    --*(_DWORD *)(a4 - 108);
    ++a6;
    if ( sub_3F63BF49(SizeConverted: (int *)(a4 - 120), MbCh: (char *)(a4 + 492), SizeInBytes: 6u, WCh: v6) != 0
      || *(_DWORD *)(a4 - 120) == 0 )
    {
      break;
    }
    ((void (__thiscall *)(int, _DWORD))write_string)(a1: a4 + 492, a2: *(_DWORD *)(a4 - 120));
    if ( *(_DWORD *)(a4 - 108) == 0 )
      goto LABEL_8;
  }
  *(_DWORD *)(a4 - 52) = -1;
LABEL_8:
  if ( *(int *)(a4 - 52) >= 0 && (*(_BYTE *)(a4 - 24) & 4) != 0 )
    write_multi_char_0(result: a4 - 52, a2: 32, a3, a4: a5);
  if ( *(_DWORD *)(a4 - 96) != 0 )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a4 - 96));
    *(_DWORD *)(a4 - 96) = 0;
  }
  v7 = **(_BYTE **)(a4 - 76);
  *(_BYTE *)(a4 - 25) = v7;
  if ( v7 != 0 )
    JUMPOUT(0x3F63C1E3);
  if ( *(_DWORD *)(a4 - 72) != 0 && *(_DWORD *)(a4 - 72) != 7 )
    JUMPOUT(0x3F63C0E4);
  if ( *(_BYTE *)(a4 - 80) != 0 )
    *(_DWORD *)(*(_DWORD *)(a4 - 84) + 112) &= ~2u;
  __security_check_cookie`...'(StackCookie: a4 ^ *(_DWORD *)(a4 + 500));
}

//------------------------------------------------------------------------------
// Address: 0x3F63CADA
// Name: __chsize_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
BOOL __usercall _chsize_s@<eax>(char a1@<zf>, char a2@<dl>, int a3@<ecx>, int a4@<ebp>, _DWORD *a5@<edi>)
{
  int v5; // eax

  v5 = a1 || a2 == 105 || a2 == 111 || a2 == 117 || a2 == 120 || a2 == 88;
  return a3 == v5
      && ((*(_DWORD *)(a4 + 20) ^ a5[3]) & 0x10000) == 0
      && ((*(_BYTE *)(a4 + 20) ^ *((_BYTE *)a5 + 12)) & 0x20) == 0
      && *a5 == *(_DWORD *)(a4 + 12);
}

//------------------------------------------------------------------------------
// Address: 0x3F63CBC7
// Name: __chsize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _chsize(int a1@<ebx>)
{
  *(_DWORD *)(*(int (**)(void))(a1 + 83))() = 22;
  _invalid_parameter_0();
  JUMPOUT(0x3F63CBDE);
}

//------------------------------------------------------------------------------
// Address: 0x3F63CBDF
// Name: __lseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _lseek_nolock(int a1@<ebp>)
{
  *(_DWORD *)(*(_DWORD *)(a1 + 92) + 112) &= ~2u;
  JUMPOUT(0x3F63DAAD);
}

//------------------------------------------------------------------------------
// Address: 0x3F63CC51
// Name: __lseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lseek()
{
  JUMPOUT(0x3F63CC52);
}

//------------------------------------------------------------------------------
// Address: 0x3F63CD2D
// Name: __setmode_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _setmode_nolock()
{
  JUMPOUT(0x3F63CD2E);
}

//------------------------------------------------------------------------------
// Address: 0x3F63CE2F
// Name: __get_fmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _get_fmode(int a1@<ebp>)
{
  int v1; // eax

  MEMORY[0xC2994237]();
  v1 = MEMORY[0x87894241]() - 1;
  if ( v1 != 0 )
  {
    if ( v1 == 3 )
      *(_DWORD *)(a1 + 128) |= 8u;
  }
  else
  {
    *(_DWORD *)(a1 + 128) |= 4u;
  }
  JUMPOUT(0x3F63DA1C);
}

//------------------------------------------------------------------------------
// Address: 0x3F63CF5A
// Name: __putwch_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _putwch_nolock(int a1@<ebx>, int a2@<ebp>, int a3@<edi>)
{
  int v3; // eax
  _DWORD *v4; // ecx
  _DWORD *v5; // ebp
  int v6; // eax
  _BYTE *v7; // ecx
  int v8; // eax
  bool v9; // zf
  int v10; // eax
  const char *mbc; // [esp+4h] [ebp-Ch]
  char **mbc_4; // [esp+8h] [ebp-8h]
  int v13; // [esp+Ch] [ebp-4h]

  v5 = (_DWORD *)(a2 + 1);
  v6 = strtol_0(String: mbc, EndPtr: mbc_4, Radix: v13);
  v7 = (_BYTE *)v5[13];
  v8 = v6 - 1;
  v9 = v5[26] == a3;
  v5[20] = v7 + 1;
  if ( v9 )
  {
    if ( v8 < a3 || *v7 != 36 || (int)v5[30] >= 100 )
      JUMPOUT(0x3F63D438);
    if ( v8 > v5[15] )
      v5[15] = v8;
    v3 = 4 * v8;
    v4 = &v5[v3 - 400];
    if ( *v4 != a3 )
      JUMPOUT(0x3F63D427);
    *v4 = a1;
    LOBYTE(v5[v3 - 398]) = 42;
    v5[v3 - 397] = v5[32];
  }
  else
  {
    v10 = *(_DWORD *)v5[4 * v8 - 399];
    v5[28] = v10;
    if ( v10 < a3 )
      v5[28] = -1;
  }
  JUMPOUT(0x3F63DA1C);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D0FD
// Name: __atodbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _atodbl_l(char a1@<ch>, _BYTE *a2@<ebx>)
{
  *a2 |= a1;
  JUMPOUT(0x3F63D0FF);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D1B6
// Name: __atoldbl_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _atoldbl_l()
{
  JUMPOUT(0x3F63D1B8);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D329
// Name: __set_output_format
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _set_output_format(char a1@<al>, int a2@<ebx>)
{
  *(_BYTE *)(a2 - 1911592968) += a1;
  __asm { fdiv    st(5), st }
  JUMPOUT(0x3F63D331);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D360
// Name: __get_output_format
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _get_output_format(_BYTE *a1@<eax>)
{
  *a1 = *a1;
  JUMPOUT(0x3F63D363);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D423
// Name: ___dtold
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __dtold(
        char a1@<zf>,
        char a2@<sf>,
        char a3@<of>,
        _BYTE *a4@<eax>,
        int a5@<ecx>,
        int a6@<ebx>,
        int a7@<ebp>,
        int a8@<edi>)
{
  bool v8; // zf
  char v9; // cc
  _DWORD *v10; // ebp
  int v11; // esi
  int v12; // eax

  if ( a1 )
  {
    if ( ((int (__cdecl *)(int, int))_validate_param_reuseA_0)(a1: a5, a2: 8) != 0 )
      JUMPOUT(0x3F63DA1C);
    goto LABEL_3;
  }
  if ( a2 != a3 )
  {
    *(_DWORD *)(a7 + 124) = a5 + 8;
    JUMPOUT(0x3F63D77E);
  }
  *a4 = __ROR1__(*a4, 137);
  v8 = a7 == -1;
  v9 = (a7 + 1 < 0) ^ __OFADD__(1, a7);
  v10 = (_DWORD *)(a7 + 1);
  if ( v9 )
  {
    if ( !v8 )
    {
LABEL_6:
      if ( v10[27] == a8 )
        JUMPOUT(0x3F63D487);
      if ( v10[30] <= 0x63u )
        JUMPOUT(0x3F63D4DD);
LABEL_3:
      *_errno_0() = 22;
      _invalid_parameter_0();
      JUMPOUT(0x3F63CBDE);
    }
  }
  else
  {
    if ( v10[28] > (int)a4 )
      v10[28] = a4;
    a6 = 163;
    if ( (int)v10[28] <= 163 )
      goto LABEL_6;
    v11 = v10[28] + 349;
    v12 = ((int (__cdecl *)(int))loc_3F609A30)(a1: v11);
    v10[5] = v12;
    if ( v12 != a8 )
    {
      v10[29] = v12;
      v10[17] = v11;
      goto LABEL_6;
    }
  }
  v10[28] = a6;
  goto LABEL_6;
}

//------------------------------------------------------------------------------
// Address: 0x3F63D4DE
// Name: __fltout2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fltout2(_BYTE *a1@<eax>, char a2@<dl>, int a3@<ecx>, int a4@<ebp>, int a5@<edi>)
{
  void (__cdecl *v5)(int, int, int, int, int, int, int); // eax
  int v6; // esi
  void (__cdecl *v7)(int, int); // eax
  void (__cdecl *v8)(int, int); // eax
  int autofos_20; // [esp+14h] [ebp-18h]
  int autofos_24; // [esp+18h] [ebp-14h]
  int ld; // [esp+1Ch] [ebp-10h]
  int ld_4; // [esp+20h] [ebp-Ch]
  int ld_8; // [esp+24h] [ebp-8h]
  int ld_8a; // [esp+24h] [ebp-8h]
  int ld_8b; // [esp+24h] [ebp-8h]

  *a1 = __ROR1__(*a1, 139);
  *(_DWORD *)(a4 + 4) = a3;
  *(_DWORD *)(a4 + 8) = *(_DWORD *)(a1 - 5);
  ld_8 = *(_DWORD *)(a4 + 16);
  ld_4 = *(_DWORD *)(a4 + 112);
  ld = a2;
  autofos_24 = *(_DWORD *)(a4 + 68);
  autofos_20 = *(_DWORD *)(a4 + 116);
  v5 = (void (__cdecl *)(int, int, int, int, int, int, int))_decode_pointer_0(a1: (void *)s_NoEscConversion.m_pReplacements[199].m_nLength);
  v5(a1: a4 + 4, a2: autofos_20, a3: autofos_24, a4: ld, a5: ld_4, a6: ld_8, a7: a4 + 84);
  v6 = *(_DWORD *)(a4 + 128) & 0x80;
  if ( v6 != 0 && *(_DWORD *)(a4 + 112) == a5 )
  {
    ld_8a = *(_DWORD *)(a4 + 116);
    v7 = (void (__cdecl *)(int, int))_decode_pointer_0(a1: s_NoEscConversion.m_pReplacements[200].m_pReplacementString);
    v7(a1: ld_8a, a2: a4 + 84);
  }
  if ( *(_BYTE *)(a4 + 100) == 103 && v6 == a5 )
  {
    ld_8b = *(_DWORD *)(a4 + 116);
    v8 = (void (__cdecl *)(int, int))_decode_pointer_0(a1: (void *)s_NoEscConversion.m_pReplacements[200].m_nLength);
    v8(a1: ld_8b, a2: a4 + 84);
  }
  if ( **(_BYTE **)(a4 + 116) == 45 )
  {
    *(_DWORD *)(a4 + 128) |= 0x100u;
    JUMPOUT(0x3F63D572);
  }
  JUMPOUT(0x3F63D307);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D650
// Name: __aullshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _aullshr()
{
  JUMPOUT(0x3F63D652);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D66F
// Name: __controlfp_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _controlfp_s@<eax>(
        int a1@<eax>,
        char a2@<ch>,
        _DWORD *a3@<ebp>,
        int a4@<edi>,
        unsigned int *_CurrentState,
        unsigned int *newctrl)
{
  *(_BYTE *)(a1 - 1468959712) += a2;
  if ( a1 != -1 )
  {
    if ( a3[27] == a4 )
    {
      a3[31] += 4;
      goto LABEL_12;
    }
    if ( a3[30] <= 0x63u )
    {
      if ( a3[26] != a4 )
LABEL_12:
        JUMPOUT(0x3F63D718);
LABEL_18:
      JUMPOUT(0x3F63D741);
    }
LABEL_17:
    JUMPOUT(0x3F63D438);
  }
  if ( a3[27] == a4 )
  {
    a3[31] += 4;
    goto LABEL_12;
  }
  if ( a3[30] > 0x63u )
    goto LABEL_17;
  if ( a3[26] == a4 )
    goto LABEL_18;
  return _flswbuf(ch: (int)_CurrentState, str: (_iobuf *)newctrl);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D6D9
// Name: __flswbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__usercall _flswbuf@<eax>(int a1@<eax>, _DWORD *a2@<ebp>, int a3@<edi>, const char *ch)
{
  __int64 v4; // rax
  unsigned int v5; // ebx
  unsigned int v6; // edi
  _BYTE *i; // esi
  int v8; // eax
  unsigned __int64 v9; // rcx
  int v10; // ecx
  int v11; // eax
  _BYTE *v12; // esi
  bool v13; // zf
  unsigned __int64 v15; // [esp-Ch] [ebp-10h]
  unsigned __int64 v16; // [esp-4h] [ebp-8h]

  v4 = **(unsigned __int16 **)((char *)a2 + a1 - 1596);
  if ( (a2[32] & 0x40) != 0 && (int)v4 >> 31 <= a3 && (SHIDWORD(v4) < a3 || (unsigned int)v4 < a3) )
  {
    v4 = -(__int64)(int)v4;
    a2[32] |= 0x100u;
  }
  v5 = HIDWORD(v4);
  v6 = v4;
  if ( (a2[32] & 0x9000) == 0 )
    v5 = 0;
  if ( (int)a2[28] >= 0 )
  {
    a2[32] &= ~8u;
    if ( (int)a2[28] > 512 )
      a2[28] = 512;
  }
  else
  {
    a2[28] = 1;
  }
  if ( (v5 | (unsigned int)v4) == 0 )
    a2[14] = 0;
  for ( i = (char *)a2 + 643; ; --i )
  {
    v8 = a2[28];
    a2[28] = v8 - 1;
    if ( v8 <= 0 && (v5 | v6) == 0 )
      break;
    v16 = (int)a2[17];
    v15 = __PAIR64__(v5, v6);
    v9 = __PAIR64__(v5, v6) % v16;
    v10 = v9 + 48;
    a2[10] = HIDWORD(v9);
    v5 = (v15 / v16) >> 32;
    v6 = v15 / v16;
    if ( v10 > 57 )
      v10 += a2[7];
    *i = v10;
  }
  v11 = (char *)a2 + 643 - i;
  v12 = i + 1;
  v13 = (a2[32] & 0x200) == 0;
  a2[10] = v11;
  a2[29] = v12;
  if ( v13 || v11 != 0 && *v12 == 48 )
    JUMPOUT(0x3F63D8EA);
  --a2[29];
  return _getenv_helper_nolock(option: ch);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D849
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _getenv_helper_nolock(int a1@<ebp>)
{
  **(_BYTE **)(a1 + 116) = 48;
  JUMPOUT(0x3F63D8E7);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D8CA
// Name: _getenv_s_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall getenv_s_helper@<eax>(
        char a1@<zf>,
        int a2@<ecx>,
        int a3@<ebp>,
        int a4@<edi>,
        char *buffer,
        char *sizeInTChars)
{
  _BYTE *i; // eax
  int v8; // eax
  char **v9; // ebx

  if ( a1 )
    *(_DWORD *)(a3 + 116) = Str;
  for ( i = *(_BYTE **)(a3 + 116); a2 != a4; ++i )
  {
    --a2;
    if ( *i == 0 )
      break;
  }
  *(_DWORD *)(a3 + 40) = &i[-*(_DWORD *)(a3 + 116)];
  if ( *(_DWORD *)(a3 + 108) == 1 && *(_DWORD *)(a3 + 104) == 0 )
    JUMPOUT(0x3F63DA1C);
  if ( *(_DWORD *)(a3 + 24) != 0 )
    JUMPOUT(0x3F63DA09);
  v8 = *(_DWORD *)(a3 + 128);
  if ( (v8 & 0x40) != 0 )
  {
    if ( (v8 & 0x100) != 0 )
    {
      *(_BYTE *)(a3 + 72) = 45;
    }
    else if ( (v8 & 1) != 0 )
    {
      *(_BYTE *)(a3 + 72) = 43;
    }
    else
    {
      if ( (v8 & 2) == 0 )
        goto LABEL_18;
      *(_BYTE *)(a3 + 72) = 32;
    }
    *(_DWORD *)(a3 + 56) = 1;
  }
LABEL_18:
  v9 = (char **)(*(_DWORD *)(a3 + 64) - *(_DWORD *)(a3 + 40) - *(_DWORD *)(a3 + 56));
  if ( (v8 & 0xC) == 0 )
    write_multi_char_0(result: a3 + 76, a2: 32, a3: (int)v9, a4: *(_DWORD *)(a3 + 32));
  return dupenv_s_helper(pBuffer: v9, pBufferSizeInTChars: (unsigned int *)buffer, varname: sizeInTChars);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D95D
// Name: _dupenv_s_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall dupenv_s_helper(char **pBuffer@<ebx>, int a2@<ebp>, int a3@<edi>)
{
  int v3; // eax
  wchar_t *v4; // esi
  wchar_t v5; // ax

  ((void (*)(void))write_string)();
  if ( (*(_BYTE *)(a2 + 128) & 8) != 0 && (*(_BYTE *)(a2 + 128) & 4) == 0 )
    write_multi_char_0(result: a2 + 76, a2: 48, a3: (int)pBuffer, a4: a3);
  v3 = *(_DWORD *)(a2 + 40);
  if ( *(_DWORD *)(a2 + 48) != 0 && v3 > 0 )
  {
    v4 = *(wchar_t **)(a2 + 116);
    *(_DWORD *)(a2 + 68) = v3;
    while ( 1 )
    {
      v5 = *v4;
      --*(_DWORD *)(a2 + 68);
      ++v4;
      if ( sub_3F63BF49(SizeConverted: (int *)(a2 + 12), MbCh: (char *)(a2 + 644), SizeInBytes: 6u, WCh: v5) != 0
        || *(_DWORD *)(a2 + 12) == 0 )
      {
        break;
      }
      ((void (__thiscall *)(int, _DWORD))write_string)(a1: a2 + 644, a2: *(_DWORD *)(a2 + 12));
      if ( *(_DWORD *)(a2 + 68) == 0 )
        goto LABEL_13;
    }
    *(_DWORD *)(a2 + 76) = -1;
  }
  else
  {
    ((void (__cdecl *)(_DWORD))write_string)(a1: *(_DWORD *)(a2 + 40));
  }
LABEL_13:
  if ( *(int *)(a2 + 76) >= 0 && (*(_BYTE *)(a2 + 128) & 4) != 0 )
    JUMPOUT(0x3F63D9FE);
  JUMPOUT(0x3F63DA09);
}

//------------------------------------------------------------------------------
// Address: 0x3F63D9FF
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall getenv@<eax>(int a1@<eax>, int a2@<ebp>, char *option, char *optiona, unsigned int a5, const char *a6)
{
  int v6; // ebp
  char v7; // al
  int v8; // edx
  _DWORD *v9; // eax
  char v11; // [esp+14h] [ebp-Ch]
  int v12; // [esp+18h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp-4h]

  v6 = a2 + 1;
  write_multi_char_0(result: a1, a2: v11, a3: v12, a4: v13);
  if ( *(_DWORD *)(v6 + 20) != 0 )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(v6 + 20));
    *(_DWORD *)(v6 + 20) = 0;
  }
  v7 = **(_BYTE **)(v6 + 80);
  *(_BYTE *)(v6 + 100) = v7;
  if ( v7 != 0 )
    JUMPOUT(0x3F63CCDE);
  if ( *(_DWORD *)(v6 + 44) == 0 || *(_DWORD *)(v6 + 44) == 7 )
  {
    if ( *(_DWORD *)(v6 + 108) != 1 || *(_DWORD *)(v6 + 104) != 0 || *(int *)(v6 + 60) < 0 )
      JUMPOUT(0x3F63DA8D);
    v8 = *(_DWORD *)(v6 + 124);
    v9 = (_DWORD *)(v6 - 1596);
    switch ( *(_DWORD *)(v6 - 1600) )
    {
      case 1:
      case 2:
      case 3:
        goto LABEL_17;
      case 4:
      case 5:
        goto LABEL_16;
      case 6:
LABEL_17:
        *v9 = v8;
        return (char *)getenv_s(pReturnValue: (unsigned int *)option, buffer: optiona, sizeInTChars: a5, varname: a6);
      case 8:
LABEL_16:
        *v9 = v8;
        return (char *)getenv_s(pReturnValue: (unsigned int *)option, buffer: optiona, sizeInTChars: a5, varname: a6);
      default:
        break;
    }
  }
  JUMPOUT(0x3F63D438);
}

//------------------------------------------------------------------------------
// Address: 0x3F63DA82
// Name: _getenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall getenv_s(int a1@<edx>, int a2@<ebp>, int a3@<esi>)
{
  bool v3; // cc

  v3 = a3 <= *(_DWORD *)(a2 + 60);
  *(_DWORD *)(a2 + 124) = a1;
  if ( v3 )
    JUMPOUT(0x3F63DA58);
  if ( (int)++*(_DWORD *)(a2 + 104) < 2 )
    JUMPOUT(0x3F63CC9B);
  if ( *(_BYTE *)(a2 + 96) != 0 )
    *(_DWORD *)(*(_DWORD *)(a2 + 92) + 112) &= ~2u;
  __security_check_cookie`...'(StackCookie: a2 ^ *(_DWORD *)(a2 + 652));
}

//------------------------------------------------------------------------------
// Address: 0x3F63DB5A
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _dupenv_s(
        char a1@<cf>,
        int a2@<ecx>,
        wchar_t *a3@<ebx>,
        int a4@<ebp>,
        int a5@<edi>,
        char **pBuffer,
        unsigned __int8 *pBufferSizeInTChars,
        const char *varname)
{
  int v8; // eax
  int v9; // edi
  unsigned int v10; // eax
  void *v11; // esp
  int *v12; // eax
  int v13; // eax
  int v14; // [esp+0h] [ebp-4h]
  int retaddr; // [esp+4h] [ebp+0h] BYREF

  *(_BYTE *)(a2 + 141949021) -= a1 + a2;
  *(_DWORD *)(a4 + 24) = *(_DWORD *)(*(_DWORD *)a5 + 4);
  v8 = MultiByteToWideChar(
         CodePage: *(_DWORD *)(a4 + 24),
         dwFlags: 8 * (*(_DWORD *)(a4 + 32) != (_DWORD)a3) + 1,
         lpMultiByteStr: *(LPCCH *)(a4 + 12),
         cbMultiByte: *(_DWORD *)(a4 + 16),
         lpWideCharStr: a3,
         cchWideChar: v14);
  v9 = v8;
  if ( (wchar_t *)v8 == a3 )
    goto LABEL_15;
  if ( v8 > (int)a3 && (unsigned int)v8 <= 0x7FFFFFF0 )
  {
    v10 = 2 * v8 + 8;
    if ( v10 > 0x400 )
    {
      v12 = (int *)((int (__cdecl *)(int))loc_3F609A30)(a1: 2 * v9 + 8);
      if ( v12 != (int *)a3 )
      {
        *v12 = 56797;
        goto LABEL_9;
      }
    }
    else
    {
      v11 = alloca(v10);
      v12 = &retaddr;
      if ( &retaddr != (int *)a3 )
      {
        retaddr = 52428;
LABEL_9:
        v12 += 2;
      }
    }
    a3 = (wchar_t *)v12;
  }
  if ( a3 != nullptr )
  {
    memset(a1: a3, Val: 0, Size: 2 * v9);
    v13 = MultiByteToWideChar(
            CodePage: *(_DWORD *)(a4 + 24),
            dwFlags: 1u,
            lpMultiByteStr: *(LPCCH *)(a4 + 12),
            cbMultiByte: *(_DWORD *)(a4 + 16),
            lpWideCharStr: a3,
            cchWideChar: v9);
    if ( v13 != 0 )
      *(_DWORD *)(a4 - 8) = GetStringTypeW(
                              dwInfoType: *(_DWORD *)(a4 + 8),
                              lpSrcStr: a3,
                              cchSrc: v13,
                              lpCharType: *(LPWORD *)(a4 + 20));
    _freea_0(Memory: a3);
    JUMPOUT(0x3F63DC8B);
  }
LABEL_15:
  __ascii_strnicmp(first: (unsigned __int8 *)pBuffer, last: pBufferSizeInTChars, count: (unsigned int)varname);
}

//------------------------------------------------------------------------------
// Address: 0x3F63DC40
// Name: ___ascii_strnicmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __ascii_strnicmp(int a1@<ebp>)
{
  __security_check_cookie`...'(StackCookie: a1 ^ *(_DWORD *)(a1 - 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F63DCA1
// Name: ___initconin
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63DCC0
// Name: ___initconout
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall __initconout@<eax>(int a1@<ebp>)
{
  int result; // eax

  result = ((int (__cdecl *)(_DWORD, _DWORD))loc_3F63DAE5)(a1: *(_DWORD *)(a1 + 12), a2: *(_DWORD *)(a1 + 16));
  if ( *(_BYTE *)(a1 - 4) != 0 )
    *(_DWORD *)(*(_DWORD *)(a1 - 8) + 112) &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63DCDF
// Name: ___termcon
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __termcon()
{
  __asm
  {
    aas
    retn
  }
}

//------------------------------------------------------------------------------
// Address: 0x3F63DD0C
// Name: _wcslen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl wcslen(_LDOUBLE wcs, int a2, unsigned int a3, _FloatOutStruct *a4)
{
  return _I10_OUTPUT(ld: wcs, ndigits: a2, output_flags: a3, fos: a4);
}

//------------------------------------------------------------------------------
// Address: 0x3F63DD22
// Name: _$I10_OUTPUT
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _I10_OUTPUT@<eax>(char a1@<zf>, int a2@<eax>, int a3@<ecx>, int a4@<ebp>, int a5@<esi>)
{
  int result; // eax
  int v6; // edi
  int v7; // edi
  int v8; // edi
  int v9; // edi
  int v10; // edi
  int v11; // edi
  int v12; // edi
  int v13; // edi
  int v14; // edi
  int v15; // edi
  int v16; // edi
  int v17; // edi
  int v18; // edi
  int v19; // edi
  int v20; // edi
  int v21; // edi
  int v22; // edi
  int v23; // edi
  int v24; // edi
  int v25; // edi
  int v26; // edi
  int v27; // edi
  int v28; // edi
  int v29; // edi
  int v30; // edi
  int v31; // edi
  int v32; // edi
  int v33; // edi
  int v34; // edi
  int v35; // edi
  int v36; // edi
  int v37; // edi
  int v38; // edi
  int v39; // edi
  int v40; // edi
  int v41; // edi
  int v42; // edi
  int v43; // edi
  int v44; // edi
  int v45; // edi
  int v46; // edi
  int v47; // edi
  int v48; // edi
  int v49; // ebx

  if ( a1 )
    return -1;
  *(_DWORD *)(a4 - 12) = 0;
  *(_DWORD *)(a4 - 16) = a2;
  v6 = ((int (__cdecl *)(int, int, int, int, int))__getlocaleinfo_0)(a1: a4 - 16, a2: 1, a3, a4: 49, a5: a5 + 4);
  v7 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
         a1: a4 - 16,
         a2: 1,
         a3: *(_DWORD *)(a4 - 4),
         a4: 50,
         a5: a5 + 8)
     | v6;
  v8 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
         a1: a4 - 16,
         a2: 1,
         a3: *(_DWORD *)(a4 - 4),
         a4: 51,
         a5: a5 + 12)
     | v7;
  v9 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
         a1: a4 - 16,
         a2: 1,
         a3: *(_DWORD *)(a4 - 4),
         a4: 52,
         a5: a5 + 16)
     | v8;
  v10 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 53,
          a5: a5 + 20)
      | v9;
  v11 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 54,
          a5: a5 + 24)
      | v10;
  v12 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 55,
          a5)
      | v11;
  v13 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 42,
          a5: a5 + 32)
      | v12;
  v14 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 43,
          a5: a5 + 36)
      | v13;
  v15 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 44,
          a5: a5 + 40)
      | v14;
  v16 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 45,
          a5: a5 + 44)
      | v15;
  v17 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 46,
          a5: a5 + 48)
      | v16;
  v18 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 47,
          a5: a5 + 52)
      | v17;
  v19 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 48,
          a5: a5 + 28)
      | v18;
  v20 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 68,
          a5: a5 + 56)
      | v19;
  v21 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 69,
          a5: a5 + 60)
      | v20;
  v22 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 70,
          a5: a5 + 64)
      | v21;
  v23 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 71,
          a5: a5 + 68)
      | v22;
  v24 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 72,
          a5: a5 + 72)
      | v23;
  v25 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 73,
          a5: a5 + 76)
      | v24;
  v26 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 74,
          a5: a5 + 80)
      | v25;
  v27 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 75,
          a5: a5 + 84)
      | v26;
  v28 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 76,
          a5: a5 + 88)
      | v27;
  v29 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 77,
          a5: a5 + 92)
      | v28;
  v30 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 78,
          a5: a5 + 96)
      | v29;
  v31 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 79,
          a5: a5 + 100)
      | v30;
  v32 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 56,
          a5: a5 + 104)
      | v31;
  v33 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 57,
          a5: a5 + 108)
      | v32;
  v34 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 58,
          a5: a5 + 112)
      | v33;
  v35 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 59,
          a5: a5 + 116)
      | v34;
  v36 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 60,
          a5: a5 + 120)
      | v35;
  v37 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 61,
          a5: a5 + 124)
      | v36;
  v38 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 62,
          a5: a5 + 128)
      | v37;
  v39 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 63,
          a5: a5 + 132)
      | v38;
  v40 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 64,
          a5: a5 + 136)
      | v39;
  v41 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 65,
          a5: a5 + 140)
      | v40;
  v42 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 66,
          a5: a5 + 144)
      | v41;
  v43 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 67,
          a5: a5 + 148)
      | v42;
  v44 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 40,
          a5: a5 + 152)
      | v43;
  v45 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 4),
          a4: 41,
          a5: a5 + 156)
      | v44;
  v46 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 8),
          a4: 31,
          a5: a5 + 160)
      | v45;
  v47 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 8),
          a4: 32,
          a5: a5 + 164)
      | v46;
  v48 = ((int (__cdecl *)(int, int, _DWORD, int, int))__getlocaleinfo_0)(
          a1: a4 - 16,
          a2: 1,
          a3: *(_DWORD *)(a4 - 8),
          a4: 4099,
          a5: a5 + 168)
      | v47;
  v49 = *(_DWORD *)(a4 - 8);
  result = ((int (__cdecl *)(int, _DWORD, int, int, int))__getlocaleinfo_0)(
             a1: a4 - 16,
             a2: 0,
             a3: v49,
             a4: 4105,
             a5: a5 + 176)
         | v48;
  *(_DWORD *)(a5 + 172) = v49;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63E125
// Name: __free_lc_time
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _free_lc_time(_DWORD *a1)
{
  int result; // eax

  if ( a1 != nullptr )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[1]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[2]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[3]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[4]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[5]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[6]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *a1);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[8]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[9]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[10]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[11]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[12]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[13]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[7]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[14]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[15]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[16]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[17]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[18]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[19]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[20]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[21]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[22]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[23]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[24]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[25]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[26]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[27]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[28]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[29]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[30]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[31]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[32]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[33]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[34]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[35]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[36]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[37]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[38]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[39]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[40]);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[41]);
    return ((int (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[42]);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63E2B5
// Name: ___init_time_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63E35B
// Name: ___free_lconv_num_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __free_lconv_num_0(_DWORD *a1)
{
  char *result; // eax
  int v2; // esi

  if ( a1 != nullptr )
  {
    if ( *a1 != s_NoEscConversion.m_pReplacements[226].m_nLength )
      ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *a1);
    result = (char *)a1[1];
    if ( result != s_NoEscConversion.m_pReplacements[226].m_pReplacementString )
      result = (char *)((int (__cdecl *)(_DWORD))loc_3F609ED0)(a1: a1[1]);
    v2 = a1[2];
    if ( v2 != s_NoEscConversion.m_pReplacements[227].m_nLength )
      return (char *)((int (__cdecl *)(int))loc_3F609ED0)(a1: v2);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63E39B
// Name: ___init_numeric_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __init_numeric_0(int a1)
{
  bool v2; // zf
  CUtlCharConversion::ConversionInfo_t *v3; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // esi
  int v8; // edi
  int v9; // eax
  int v10; // eax
  char *v11; // eax
  char v12; // cl
  char *v13; // esi
  _DWORD v14[2]; // [esp+Ch] [ebp-18h] BYREF
  char **v15; // [esp+14h] [ebp-10h]
  int v16; // [esp+18h] [ebp-Ch]
  _DWORD *v17; // [esp+1Ch] [ebp-8h]
  _DWORD *v18; // [esp+20h] [ebp-4h]
  CUtlCharConversion::ConversionInfo_t *v19; // [esp+2Ch] [ebp+8h]

  v2 = *(_DWORD *)(a1 + 28) == 0;
  v14[0] = a1;
  v14[1] = 0;
  if ( !v2 || *(_DWORD *)(a1 + 24) != 0 )
  {
    v3 = (CUtlCharConversion::ConversionInfo_t *)((int (__cdecl *)(int, int))loc_3F609A90)(a1: 1, a2: 48);
    v19 = v3;
    if ( v3 == nullptr )
      return 1;
    qmemcpy(v3, *(const void **)(a1 + 188), 0x30u);
    v5 = (_DWORD *)((int (__cdecl *)(int))loc_3F609A30)(a1: 4);
    v17 = v5;
    if ( v5 == nullptr )
    {
      ((void (__cdecl *)(CUtlCharConversion::ConversionInfo_t *))loc_3F609ED0)(a1: v19);
      return 1;
    }
    *v5 = 0;
    if ( *(_DWORD *)(a1 + 28) == 0 )
    {
      *v19 = s_NoEscConversion.m_pReplacements[226];
      v18 = nullptr;
      v19[1].m_nLength = s_NoEscConversion.m_pReplacements[227].m_nLength;
LABEL_26:
      *v17 = 1;
      if ( v18 != nullptr )
        *v18 = 1;
      goto LABEL_28;
    }
    v6 = (_DWORD *)((int (__cdecl *)(int))loc_3F609A30)(a1: 4);
    v18 = v6;
    if ( v6 == nullptr )
    {
      v7 = 1;
LABEL_11:
      ((void (__cdecl *)(CUtlCharConversion::ConversionInfo_t *))loc_3F609ED0)(a1: v19);
      ((void (__cdecl *)(_DWORD *))loc_3F609ED0)(a1: v17);
      return v7;
    }
    *v6 = 0;
    v8 = *(unsigned __int16 *)(a1 + 62);
    v16 = ((int (__cdecl *)(_DWORD *, int, int, int, CUtlCharConversion::ConversionInfo_t *))__getlocaleinfo_0)(
            a1: v14,
            a2: 1,
            a3: v8,
            a4: 14,
            a5: v19);
    v9 = ((int (__cdecl *)(_DWORD *, int, int, int, char **))__getlocaleinfo_0)(
           a1: v14,
           a2: 1,
           a3: v8,
           a4: 15,
           a5: &v19->m_pReplacementString);
    v16 |= v9;
    v15 = (char **)&v19[1];
    v10 = ((int (__cdecl *)(_DWORD *, int, int, int, CUtlCharConversion::ConversionInfo_t *))__getlocaleinfo_0)(
            a1: v14,
            a2: 1,
            a3: v8,
            a4: 16,
            a5: &v19[1]);
    if ( (v16 | v10) != 0 )
    {
      __free_lconv_num_0(a1: v19);
      v7 = -1;
      goto LABEL_11;
    }
    v11 = *v15;
    while ( 1 )
    {
      if ( *v11 == 0 )
        goto LABEL_26;
      v12 = *v11;
      if ( *v11 >= 48 && v12 <= 57 )
        break;
      if ( v12 == 59 )
      {
        v13 = v11;
        do
        {
          *v13 = v13[1];
          ++v13;
        }
        while ( *v13 != 0 );
      }
      else
      {
LABEL_18:
        ++v11;
      }
    }
    *v11 = v12 - 48;
    goto LABEL_18;
  }
  v18 = nullptr;
  v17 = nullptr;
  v19 = &s_NoEscConversion.m_pReplacements[226];
LABEL_28:
  if ( *(_DWORD *)(a1 + 180) != 0 )
    InterlockedDecrement(lpAddend: *(volatile LONG **)(a1 + 180));
  if ( *(_DWORD *)(a1 + 176) != 0 && InterlockedDecrement(lpAddend: *(volatile LONG **)(a1 + 176)) == 0 )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a1 + 176));
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a1 + 188));
  }
  *(_DWORD *)(a1 + 180) = v18;
  *(_DWORD *)(a1 + 176) = v17;
  *(_DWORD *)(a1 + 188) = v19;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F63E5E8
// Name: __set_controlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _set_controlfp(int this)
{
  MK_FP(*(_WORD *)(this + 98), *(_DWORD *)(this + 94))();
}

//------------------------------------------------------------------------------
// Address: 0x3F63E6EB
// Name: _hw_cw
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall hw_cw(unsigned int abstr@<ebx>, int a2@<ebp>, int a3@<esi>)
{
  ((void (__cdecl *)(int, int))__getlocaleinfo_0)(a1: a2 - 16, a2: 1);
  ((void (__cdecl *)(int, int, int, int, unsigned int))__getlocaleinfo_0)(
    a1: a2 - 16,
    a2: 1,
    a3,
    a4: 81,
    a5: abstr + 36);
  ((void (__cdecl *)(int, _DWORD, int, int, unsigned int))__getlocaleinfo_0)(
    a1: a2 - 16,
    a2: 0,
    a3,
    a4: 26,
    a5: abstr + 40);
  ((void (__cdecl *)(int, _DWORD, int, int, unsigned int))__getlocaleinfo_0)(
    a1: a2 - 16,
    a2: 0,
    a3,
    a4: 25,
    a5: abstr + 41);
  ((void (__cdecl *)(int, _DWORD, int, int, unsigned int))__getlocaleinfo_0)(
    a1: a2 - 16,
    a2: 0,
    a3,
    a4: 84,
    a5: abstr + 42);
  ((void (__cdecl *)(int, _DWORD, int, int, unsigned int))__getlocaleinfo_0)(
    a1: a2 - 16,
    a2: 0,
    a3,
    a4: 85,
    a5: abstr + 43);
  ((void (__cdecl *)(int, _DWORD, int, int, unsigned int))__getlocaleinfo_0)(
    a1: a2 - 16,
    a2: 0,
    a3,
    a4: 86,
    a5: abstr + 44);
  JUMPOUT(0x3F63E778);
}

//------------------------------------------------------------------------------
// Address: 0x3F63E779
// Name: __abstract_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _abstract_cw_sse2(unsigned int cw@<ecx>, int a2@<ebx>, int a3@<ebp>, int a4@<edi>, int a5@<esi>)
{
  int v5; // ebx
  int v6; // edi
  int v7; // edi
  char *v8; // eax
  char v9; // cl
  char *v10; // esi

  v5 = a2 + 1;
  v6 = ((int (__thiscall *)(unsigned int, int, _DWORD))__getlocaleinfo_0)(a1: cw, a2: a3 - 16, a3: 0) | a4;
  v7 = ((int (__cdecl *)(int, _DWORD, int, int, int))__getlocaleinfo_0)(a1: a3 - 16, a2: 0, a3: a5, a4: 82, a5: v5 + 46)
     | v6;
  if ( (v7
      | ((int (__cdecl *)(int, _DWORD, int, int, int))__getlocaleinfo_0)(
          a1: a3 - 16,
          a2: 0,
          a3: a5,
          a4: 83,
          a5: v5 + 47)) != 0 )
  {
    ((void (__cdecl *)(int))__free_lconv_mon_0)(a1: v5);
    ((void (__cdecl *)(int))loc_3F609ED0)(a1: v5);
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a3 - 8));
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a3 - 4));
    JUMPOUT(0x3F63E62E);
  }
  v8 = *(char **)(v5 + 28);
  while ( 1 )
  {
    if ( *v8 == 0 )
      JUMPOUT(0x3F63E81E);
    v9 = *v8;
    if ( *v8 >= 48 && v9 <= 57 )
      break;
    if ( v9 == 59 )
    {
      v10 = v8;
      do
      {
        *v10 = v10[1];
        ++v10;
      }
      while ( *v10 != 0 );
    }
    else
    {
LABEL_7:
      ++v8;
    }
  }
  *v8 = v9 - 48;
  goto LABEL_7;
}

//------------------------------------------------------------------------------
// Address: 0x3F63E816
// Name: __hw_cw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __usercall _hw_cw_sse2@<eax>(
        unsigned int abstr@<edx>,
        __int16 _AX@<ax>,
        int a3@<ecx>,
        _DWORD *a4@<ebx>,
        int a5@<ebp>,
        _BYTE *a6@<edi>,
        const void *a7@<esi>)
{
  int v8; // esi
  _DWORD *v9; // ecx
  bool v10; // zf

  *a6 += (_BYTE)a4;
  __asm { aas }
  qmemcpy(a4, a7, 4 * a3);
  v8 = *(_DWORD *)(a5 + 8);
  *a4 = **(_DWORD **)(v8 + 188);
  a4[1] = *(_DWORD *)(*(_DWORD *)(v8 + 188) + 4);
  v9 = *(_DWORD **)(a5 - 8);
  a4[2] = *(_DWORD *)(*(_DWORD *)(v8 + 188) + 8);
  v10 = *(_DWORD *)(a5 - 4) == 0;
  *v9 = 1;
  if ( !v10 )
    **(_DWORD **)(a5 - 4) = 1;
  if ( *(_DWORD *)(v8 + 184) != 0 )
    InterlockedDecrement(lpAddend: *(volatile LONG **)(v8 + 184));
  if ( *(_DWORD *)(v8 + 176) != 0 && InterlockedDecrement(lpAddend: *(volatile LONG **)(v8 + 176)) == 0 )
  {
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(v8 + 188));
    ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(v8 + 176));
  }
  *(_DWORD *)(v8 + 184) = *(_DWORD *)(a5 - 4);
  *(_DWORD *)(v8 + 176) = *(_DWORD *)(a5 - 8);
  *(_DWORD *)(v8 + 188) = a4;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F63E8B6
// Name: __abstract_sw_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _abstract_sw_sse2(int a1@<ebp>)
{
  int v1; // esi
  bool v2; // zf
  int v3; // eax
  int i; // eax

  *(_DWORD *)(a1 - 4) = a1 ^ __security_cookie;
  v1 = *(_DWORD *)(a1 + 8);
  v2 = *(_DWORD *)(v1 + 20) == 0;
  *(_DWORD *)(a1 - 44) = 0;
  *(_DWORD *)(a1 - 36) = 0;
  *(_DWORD *)(a1 - 28) = 0;
  *(_DWORD *)(a1 - 40) = 0;
  *(_DWORD *)(a1 - 32) = 0;
  *(_DWORD *)(a1 - 72) = v1;
  *(_DWORD *)(a1 - 68) = 0;
  if ( v2 )
    JUMPOUT(0x3F63EBF1);
  if ( *(_DWORD *)(v1 + 4) == 0 )
    JUMPOUT(0x3F63E8F2);
  *(_DWORD *)(a1 - 44) = ((int (__cdecl *)(int))loc_3F609A30)(a1: 4);
  *(_DWORD *)(a1 - 36) = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 384, a2: 2);
  *(_DWORD *)(a1 - 28) = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 384, a2: 1);
  *(_DWORD *)(a1 - 40) = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 384, a2: 1);
  v3 = ((int (__cdecl *)(int, int))loc_3F609A90)(a1: 257, a2: 1);
  v2 = *(_DWORD *)(a1 - 44) == 0;
  *(_DWORD *)(a1 - 32) = v3;
  if ( v2 || *(_DWORD *)(a1 - 36) == 0 || v3 == 0 || *(_DWORD *)(a1 - 28) == 0 || *(_DWORD *)(a1 - 40) == 0 )
    JUMPOUT(0x3F63EBC9);
  **(_DWORD **)(a1 - 44) = 0;
  for ( i = 0; i < 256; ++i )
    *(_BYTE *)(i + *(_DWORD *)(a1 - 32)) = i;
  _fpreset();
}

//------------------------------------------------------------------------------
// Address: 0x3F63E8F4
// Name: __fpreset_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _fpreset_sse2(char a1@<cf>, _BYTE *a2@<eax>, char a3@<dl>)
{
  *a2 += (_BYTE)a2 + a1;
  *(a2 - 115) += a3;
  JUMPOUT(0x3F63E900);
}

//------------------------------------------------------------------------------
// Address: 0x3F63E990
// Name: __fpreset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fpreset()
{
  char v0; // bl
  int v1; // ebp
  int v2; // esi
  unsigned int v3; // eax

  if ( GetCPInfo(CodePage: *(_DWORD *)(v2 + 4), lpCPInfo: (LPCPINFO)(v1 - 24)) && *(_DWORD *)(v1 - 24) <= 5u )
  {
    v3 = *(unsigned __int16 *)(v1 - 24);
    *(_DWORD *)(v1 - 48) = v3;
    if ( v3 > 1 && *(_BYTE *)(v1 - 18) != v0 )
      JUMPOUT(0x3F63E9C5);
    JUMPOUT(0x3F63E9E8);
  }
  JUMPOUT(0x3F63EBC9);
}

//------------------------------------------------------------------------------
// Address: 0x3F63E9C6
// Name: __statusfp_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _statusfp_sse2()
{
  _BYTE retaddr[8]; // [esp+0h] [ebp+0h]

  return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)();
}

//------------------------------------------------------------------------------
// Address: 0x3F63EA01
// Name: __clearfp_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _clearfp_sse2(struct localeinfo_struct *a1@<ebx>, int a2@<ebp>, int a3@<esi>)
{
  if ( ((int (__cdecl *)(struct localeinfo_struct *, int))loc_3F63DC9D)(a1, a2: 1) != 0
    && __crtLCMapStringA_0(
         a1,
         a2: *(struct localeinfo_struct **)(a3 + 20),
         a3: 0x100u,
         a4: *(_DWORD *)(a2 - 32) + 1,
         a5: (const char *)0xFF,
         a6: *(_DWORD *)(a2 - 28) + 129,
         a7: (char *)0xFF,
         a8: *(_DWORD *)(a3 + 4),
         a9: (int)a1) != 0 )
  {
    JUMPOUT(0x3F63EA4B);
  }
  JUMPOUT(0x3F63EBC9);
}

//------------------------------------------------------------------------------
// Address: 0x3F63EA4C
// Name: __control87_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall _control87_sse2(
        unsigned int newctrl@<eax>,
        char a2@<cf>,
        bool a3@<zf>,
        struct localeinfo_struct *a4@<ebx>,
        int a5@<ebp>,
        char *a6@<edi>,
        int a7@<esi>)
{
  bool v7; // cc
  _WORD *v8; // eax
  _BYTE *v9; // edi
  int v10; // edx
  unsigned __int8 *v11; // ecx
  unsigned __int8 v12; // dl
  int v13; // ecx
  _WORD *i; // edx
  _DWORD *v15; // eax
  unsigned int oldCw; // [esp+0h] [ebp-8h]
  int v17; // [esp+4h] [ebp-4h]

  if ( !(a2 | a3) )
  {
    if ( __crtLCMapStringA_0(
           a1: a4,
           a2: *(struct localeinfo_struct **)(a7 + 20),
           a3: 0x200u,
           a4: *(_DWORD *)(a5 - 32) + 1,
           a5: a6,
           a6: newctrl + 129,
           a7: a6,
           a8: oldCw,
           a9: v17) != 0 )
    {
      v7 = *(_DWORD *)(a5 - 48) <= 1;
      v8 = *(_WORD **)(a5 - 36);
      v9 = *(_BYTE **)(a5 - 28);
      v10 = *(_DWORD *)(a5 - 40);
      v8[127] = (_WORD)a4;
      *(_DWORD *)(a5 - 56) = v8 + 127;
      v9[127] = (_BYTE)a4;
      *(_BYTE *)(v10 + 127) = (_BYTE)a4;
      v9[128] = (_BYTE)a4;
      *(_DWORD *)(a5 - 64) = v9 + 128;
      *(_DWORD *)(a5 - 52) = v10 + 128;
      *(_BYTE *)(v10 + 128) = (_BYTE)a4;
      if ( !v7 && *(_BYTE *)(a5 - 18) != (_BYTE)a4 )
      {
        v11 = (unsigned __int8 *)(a5 - 17);
        *(_DWORD *)(a5 - 28) = a5 - 17;
        do
        {
          v12 = *v11;
          if ( *v11 == (_BYTE)a4 )
            break;
          v13 = *(v11 - 1);
          if ( v13 <= (unsigned int)v12 )
          {
            for ( i = &v8[v13 + 128]; ; i = *(_WORD **)(a5 - 36) )
            {
              *i = 0x8000;
              ++v13;
              *(_DWORD *)(a5 - 36) = i + 1;
              if ( v13 > **(unsigned __int8 **)(a5 - 28) )
                break;
            }
          }
          v11 = (unsigned __int8 *)(*(_DWORD *)(a5 - 28) + 2);
          a3 = *(_BYTE *)(*(_DWORD *)(a5 - 28) + 1) == (unsigned __int8)a4;
          *(_DWORD *)(a5 - 28) = v11;
        }
        while ( !a3 );
      }
      memcpy_1(a1: v8, Src: v8 + 256, Size: 0xFEu);
      memcpy_1(a1: v9, Src: v9 + 256, Size: 0x7Fu);
      memcpy_1(a1: *(void **)(a5 - 40), Src: (const void *)(*(_DWORD *)(a5 - 40) + 256), Size: 0x7Fu);
      if ( *(struct localeinfo_struct **)(a7 + 192) != a4
        && InterlockedDecrement(lpAddend: *(volatile LONG **)(a7 + 192)) == 0 )
      {
        ((void (__cdecl *)(int))loc_3F609ED0)(a1: *(_DWORD *)(a7 + 196) - 254);
        ((void (__cdecl *)(int))loc_3F609ED0)(a1: *(_DWORD *)(a7 + 204) - 128);
        ((void (__cdecl *)(int))loc_3F609ED0)(a1: *(_DWORD *)(a7 + 208) - 128);
        ((void (__cdecl *)(_DWORD))loc_3F609ED0)(a1: *(_DWORD *)(a7 + 192));
      }
      v15 = *(_DWORD **)(a5 - 44);
      *v15 = 1;
      *(_DWORD *)(a7 + 192) = v15;
      *(_DWORD *)(a7 + 200) = *(_DWORD *)(a5 - 60);
      *(_DWORD *)(a7 + 196) = *(_DWORD *)(a5 - 56);
      *(_DWORD *)(a7 + 204) = *(_DWORD *)(a5 - 64);
      *(_DWORD *)(a7 + 208) = *(_DWORD *)(a5 - 52);
      *(_DWORD *)(a7 + 172) = *(_DWORD *)(a5 - 48);
      JUMPOUT(0x3F63EBBF);
    }
    JUMPOUT(0x3F63EBC9);
  }
  JUMPOUT(0x3F63EA52);
}

//------------------------------------------------------------------------------
// Address: 0x3F63EBC0
// Name: __statusfp2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall _statusfp2(char *this)
{
  MK_FP(*(_WORD *)(this - 113), *(_DWORD *)(this - 117))();
}

//------------------------------------------------------------------------------
// Address: 0x3F63EC18
// Name: __clearfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _clearfp()
{
  __debugbreak();
  JUMPOUT(0x3F63EC19);
}

//------------------------------------------------------------------------------
// Address: 0x3F63ECEF
// Name: ___control87_2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
char *__usercall __control87_2@<eax>(int a1@<ebx>, unsigned int newctrl, struct localeinfo_struct *mask)
{
  int v3; // ebx
  int v4; // edi
  int v5; // esi
  size_t v6; // eax
  size_t v7; // eax
  char *v8; // esi
  unsigned int v9; // eax
  char *v10; // esi
  char *v11; // esi
  unsigned int v12; // eax
  char *v13; // esi
  const char *v15; // [esp-10h] [ebp-34h]
  int v16; // [esp+Ch] [ebp-18h] BYREF
  int newCw; // [esp+14h] [ebp-10h]
  int oldCw; // [esp+18h] [ebp-Ch]
  char *v19; // [esp+1Ch] [ebp-8h]
  unsigned int i; // [esp+20h] [ebp-4h]

  ++*(_DWORD *)(a1 + 1438846144);
  v3 = 0;
  _LocaleUpdate::_LocaleUpdate(this: (_LocaleUpdate *)&v16, a2: mask);
  v4 = *(_DWORD *)(v16 + 212);
  i = 0;
  do
  {
    v5 = 4 * i;
    v6 = strlen_0(Str: *(const char **)(4 * i + v4 + 28));
    v15 = *(const char **)(v5 + v4);
    v19 = (char *)v6;
    v7 = strlen_0(Str: v15);
    ++i;
    v3 += (int)&v19[v7 + 2];
  }
  while ( i < 7 );
  v8 = (char *)((int (__cdecl *)(int))loc_3F609A30)(a1: v3 + 1);
  v19 = v8;
  if ( v8 != nullptr )
  {
    for ( i = 0; i < 7; ++i )
    {
      v9 = i;
      *v8 = 58;
      v10 = v8 + 1;
      if ( strcpy_s_0(Destination: v10, SizeInBytes: v19 - v10 + v3 + 1, Source: *(const char **)(v4 + 4 * v9)) != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      v11 = &v10[strlen_0(Str: v10)];
      v12 = i;
      *v11 = 58;
      v13 = v11 + 1;
      if ( strcpy_s_0(Destination: v13, SizeInBytes: v19 - v13 + v3 + 1, Source: *(const char **)(v4 + 4 * v12 + 28)) != 0 )
        _invoke_watson_0(Expression: nullptr, FunctionName: nullptr, FileName: nullptr, LineNo: 0, Reserved: 0);
      v8 = &v13[strlen_0(Str: v13)];
    }
    *v8 = 0;
  }
  if ( (_BYTE)oldCw != 0 )
    *(_DWORD *)(newCw + 112) &= ~2u;
  return v19;
}

//------------------------------------------------------------------------------
// Address: 0x3F63F2FC
// Name: __controlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
unsigned int __cdecl _controlfp(unsigned int newctrl, unsigned int mask)
{
  return _controlfp_0(NewValue: newctrl, Mask: mask);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F32D
// Name: __controlfp_0
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __cdecl _controlfp_0(unsigned int NewValue, unsigned int Mask)
{
  unsigned int result; // eax

  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F63F331
// Name: int _expandtime(struct localeinfo_struct __near *,char,struct tm const __near *,char __near * __near *,unsigned int __near *,struct __lc_time_data __near *,unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _expandtime@<eax>(
        char a1@<al>,
        int *a2@<edx>,
        _DWORD *a3@<ecx>,
        struct localeinfo_struct *a4,
        const unsigned __int8 *a5,
        const struct tm *a6,
        char **a7)
{
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  bool v15; // cc
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // esi
  int v30; // eax
  const unsigned __int8 *v32; // [esp-8h] [ebp-18h]
  const struct tm *v33; // [esp-4h] [ebp-14h]
  char **v34; // [esp-4h] [ebp-14h]

  if ( a1 <= 89 )
  {
    if ( a1 != 89 )
    {
      if ( a1 <= 73 )
      {
        if ( a1 == 73 )
        {
          if ( (unsigned int)a2[2] < 0x18 )
            goto LABEL_53;
          goto LABEL_89;
        }
        v9 = a1 - 4;
        if ( v9 != 0 )
        {
          v10 = v9 - 9;
          if ( v10 != 0 )
          {
            v11 = v10 - 24;
            if ( v11 == 0 )
            {
              *(_BYTE *)(*a3)++ = 37;
              --*(_DWORD *)a5;
              goto LABEL_75;
            }
            v12 = v11 - 28;
            if ( v12 != 0 )
            {
              v13 = v12 - 1;
              if ( v13 != 0 )
              {
                if ( v13 == 6 )
                {
                  v14 = a2[2];
                  if ( v14 >= 0 )
                  {
                    v15 = v14 <= 23;
LABEL_13:
                    if ( v15 )
                    {
LABEL_53:
                      v34 = a7;
                      goto LABEL_54;
                    }
                  }
LABEL_89:
                  JUMPOUT(0x3F63F607);
                }
LABEL_88:
                JUMPOUT(0x3F63F61F);
              }
              if ( (unsigned int)a2[4] >= 0xC )
                goto LABEL_89;
            }
            else if ( (unsigned int)a2[6] > 6 )
            {
              goto LABEL_89;
            }
LABEL_73:
            JUMPOUT(0x3F63F707);
          }
        }
LABEL_75:
        JUMPOUT(0x3F63F70F);
      }
      v16 = a1 - 77;
      if ( v16 != 0 )
      {
        v17 = v16 - 6;
        if ( v17 != 0 )
        {
          v18 = v17 - 2;
          if ( v18 != 0 )
          {
            v19 = v18 - 2;
            if ( v19 != 0 )
            {
              if ( v19 != 1 )
                goto LABEL_88;
              v33 = a6;
              v32 = a5;
LABEL_60:
              if ( ((int (__cdecl *)(struct localeinfo_struct *, int, int *, _DWORD *, const unsigned __int8 *, const struct tm *))loc_3F63F717)(
                     a1: a4,
                     a2: 2,
                     a3: a2,
                     a4: a3,
                     a5: v32,
                     a6: v33) == 0 )
                goto LABEL_88;
              goto LABEL_75;
            }
            v20 = a2[6];
            if ( v20 > 6 )
              goto LABEL_89;
          }
          else if ( (unsigned int)a2[6] > 6 )
          {
            goto LABEL_89;
          }
          v21 = a2[7];
          if ( v21 <= 0x16D )
            goto LABEL_53;
          goto LABEL_89;
        }
        v22 = *a2;
      }
      else
      {
        v22 = a2[1];
      }
      if ( v22 < 0 )
        goto LABEL_89;
      v15 = v22 <= 59;
      goto LABEL_13;
    }
    v23 = a2[5];
    if ( v23 < -1900 || v23 > 8099 )
    {
LABEL_39:
      _errno_0();
      JUMPOUT(0x3F63F60C);
    }
    v34 = a7;
    goto LABEL_54;
  }
  if ( a1 > 109 )
    JUMPOUT(0x3F63F647);
  if ( a1 == 109 )
    JUMPOUT(0x3F63F631);
  v24 = a1 - 90;
  if ( v24 == 0 )
    JUMPOUT(0x3F63F65E);
  v25 = v24 - 7;
  if ( v25 != 0 )
  {
    v26 = v25 - 1;
    if ( v26 == 0 )
    {
      if ( (unsigned int)a2[4] >= 0xC )
        goto LABEL_89;
      goto LABEL_73;
    }
    v27 = v26 - 1;
    if ( v27 == 0 )
    {
      if ( a7 != nullptr )
        v30 = ((int (__cdecl *)(struct localeinfo_struct *, int, int *, _DWORD *, const unsigned __int8 *, const struct tm *))loc_3F63F717)(
                a1: a4,
                a2: 1,
                a3: a2,
                a4: a3,
                a5,
                a6);
      else
        v30 = ((int (__cdecl *)(struct localeinfo_struct *, _DWORD, int *, _DWORD *, const unsigned __int8 *, const struct tm *))loc_3F63F717)(
                a1: a4,
                a2: 0,
                a3: a2,
                a4: a3,
                a5,
                a6);
      if ( v30 == 0 || *(_DWORD *)a5 == 0 )
        goto LABEL_88;
      v33 = a6;
      *(_BYTE *)(*a3)++ = 32;
      --*(_DWORD *)a5;
      v32 = a5;
      goto LABEL_60;
    }
    v28 = v27 - 1;
    if ( v28 == 0 )
    {
      v29 = a2[3];
      if ( v29 >= 1 && v29 <= 31 )
        goto LABEL_53;
      goto LABEL_39;
    }
    if ( v28 != 6 )
      goto LABEL_88;
    if ( (unsigned int)a2[7] > 0x16D )
      goto LABEL_89;
    v34 = a7;
LABEL_54:
    ((void (__cdecl *)(char **))_store_num)(a1: v34);
    goto LABEL_75;
  }
  if ( a2[6] < 0 )
    goto LABEL_89;
  return _mbsnbicoll_l(s1: (const unsigned __int8 *)a4, s2: a5, n: (unsigned int)a6, plocinfo: (localeinfo_struct *)a7);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F605
// Name: __mbsnbicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _mbsnbicoll_l(char a1@<zf>, char a2@<sf>, char a3@<of>)
{
  if ( !(a2 ^ a3 | a1) )
  {
    *_errno_0() = 22;
    _invalid_parameter_0();
    JUMPOUT(0x3F63F712);
  }
  JUMPOUT(0x3F63F707);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F6F1
// Name: __mbsnbicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbsnbicoll()
{
  JUMPOUT(0x3F63F707);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F708
// Name: ___wtomb_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __wtomb_environ()
{
  _enable();
  JUMPOUT(0x3F63F70D);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F79D
// Name: __statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _statfp(_WORD *a1@<eax>, int a2@<ebp>)
{
  *(_WORD *)(a2 - 20) = *a1;
  JUMPOUT(0x3F63F7A6);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F7A8
// Name: __clrfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _clrfp@<eax>(char a1@<zf>, int a2@<ecx>, int a3@<ebp>, unsigned int a4, unsigned int a5)
{
  int v5; // ecx

  v5 = a2 - 1;
  if ( a1 == 0 && v5 != 0 )
    JUMPOUT(0x3F63F7FA);
  *(_DWORD *)(a3 - 12) = v5;
  return _ctrlfp(newctrl: a4, _mask: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F7B4
// Name: __ctrlfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _ctrlfp(__int16 a1@<dx>, int (*a2)(void)@<ecx>, int a3@<ebx>, int a4@<ebp>)
{
  int v4; // eax
  int v5; // eax
  void *v6; // esp

  *(_WORD *)(a4 - 22) = a1;
  *(_WORD *)(a4 - 18) = a3;
  v4 = a2();
  *(_DWORD *)(a4 - 16) = v4;
  if ( v4 != a3 )
  {
    v5 = v4 + 8;
    if ( v5 <= 1024 )
    {
      v6 = alloca(v5);
      JUMPOUT(0x3F63F7DA);
    }
    JUMPOUT(0x3F63F7E6);
  }
  JUMPOUT(0x3F63F85B);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F7DB
// Name: __set_statfp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _set_statfp()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F63F831
// Name: ___get_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __get_fpsr_sse2(int a1@<eax>, int a2@<ecx>, int a3@<ebx>, int a4@<ebp>, unsigned int a5)
{
  *(_DWORD *)(a3 - 12324795) += a2;
  if ( a1 - 1 > 0 )
    JUMPOUT(0x3F63F822);
  _freea_0(Memory: *(void **)(a4 - 8));
  __set_fpsr_sse2(newMXCSR: a5);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F84D
// Name: ___set_fpsr_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __usercall __set_fpsr_sse2(int a1@<ebp>)
{
  __security_check_cookie`...'(StackCookie: a1 ^ *(_DWORD *)(a1 - 4));
}

//------------------------------------------------------------------------------
// Address: 0x3F63F8BF
// Name: ___fclrf_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
unsigned int __usercall __fclrf_sse2@<eax>(char a1@<zf>, _DWORD *a2@<ebx>, int a3@<edi>)
{
  if ( a1 || *a2 <= 1u )
    JUMPOUT(0x3F63F8DF);
  if ( *(_BYTE *)(a3 + 1) == 0 )
    JUMPOUT(0x3F63FB6D);
  return __statfp_sse2();
}

//------------------------------------------------------------------------------
// Address: 0x3F63F8D7
// Name: ___statfp_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall __statfp_sse2@<eax>(
        _BYTE *a1@<eax>,
        char a2@<dl>,
        _BYTE *a3@<ecx>,
        _DWORD *a4@<ebx>,
        _DWORD *a5@<esi>)
{
  *a3 = a2;
  ++*a5;
  --*a4;
  *(_BYTE *)(*a5)++ = *a1;
  --*a4;
  return __clrfp_sse2();
}

//------------------------------------------------------------------------------
// Address: 0x3F63F8EA
// Name: ___clrfp_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __clrfp_sse2(_BYTE *a1@<edi>)
{
  if ( *a1 == 0 )
    JUMPOUT(0x3F63F846);
  JUMPOUT(0x3F63F867);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F902
// Name: ___ctrlfp_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __ctrlfp_sse2(char a1@<zf>, int a2@<eax>)
{
  if ( !a1 && a2 != 1 )
    JUMPOUT(0x3F63F8B3);
  JUMPOUT(0x3F63FB4A);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F936
// Name: ___set_statfp_sse2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl __set_statfp_sse2()
{
  JUMPOUT(0x3F63FB4A);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F94C
// Name: strncnt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void strncnt()
{
  JUMPOUT(0x3F63F965);
}

//------------------------------------------------------------------------------
// Address: 0x3F63F966
// Name: __crtCompareStringA_stat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _crtCompareStringA_stat(
        char a1@<sf>,
        char a2@<of>,
        const unsigned __int8 *a3@<ebx>,
        int a4@<ebp>,
        _DWORD *a5@<esi>)
{
  if ( a1 == a2 )
    JUMPOUT(0x3F63F95C);
  if ( _expandtime(
         a1: 112,
         a2: *(int **)(a4 + 16),
         a3: a5,
         a4: *(struct localeinfo_struct **)(a4 + 8),
         a5: a3,
         a6: *(const struct tm **)(a4 + 28),
         a7: *(char ***)(a4 - 8)) == 0 )
    JUMPOUT(0x3F63F849);
  __clrfp_sse2(a1: *(_BYTE **)(a4 - 12));
}

//------------------------------------------------------------------------------
// Address: 0x3F63FCEF
// Name: ___crtCompareStringA
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall __crtCompareStringA@<eax>(unsigned int a1@<ebx>, int a2@<ebp>)
{
  bool v2; // zf

  *(_DWORD *)(a2 - 8) = 1;
  v2 = *(_DWORD *)(a2 - 8) == a1;
  **(_BYTE **)(a2 - 16) = a1;
  if ( v2 && *(_DWORD *)(a2 - 4) <= a1 )
  {
    *_errno_0() = 34;
  }
  else
  {
    *_errno_0() = 22;
    _invalid_parameter_0();
  }
  if ( *(_BYTE *)(a2 - 20) != (_BYTE)a1 )
    *(_DWORD *)(*(_DWORD *)(a2 - 24) + 112) &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x3F63FD2F
// Name: __strnicoll_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _strnicoll_l@<eax>(char a1@<zf>, int a2@<ebp>)
{
  if ( a1 )
    return ((int (__cdecl *)(_DWORD, _DWORD))_Strftime_l_0)(a1: *(_DWORD *)(a2 + 8), a2: *(_DWORD *)(a2 + 12));
  else
    return ((int (__cdecl *)())_Strftime_l_0)();
}

//------------------------------------------------------------------------------
// Address: 0x3F63FE27
// Name: __strnicoll
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F63FE4E
// Name: findenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void findenv()
{
  JUMPOUT(0x3F63FE50);
}

//------------------------------------------------------------------------------
// Address: 0x3F63FE9B
// Name: copy_environ
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall copy_environ(char **oldenviron@<edi>, _BYTE *a2@<eax>, char **a3@<ebx>, int a4@<ebp>, _BYTE *a5@<esi>)
{
  *a2 = (_BYTE)a3;
  if ( oldenviron == a3 )
  {
    if ( *(_DWORD *)(a4 + 20) == -1 )
    {
      a5[*(_DWORD *)(a4 + 12) - 1] = (_BYTE)a3;
      JUMPOUT(0x3F63FE2E);
    }
    *a5 = (_BYTE)a3;
    *_errno_0() = 34;
    JUMPOUT(0x3F63FE48);
  }
  JUMPOUT(0x3F63FE2C);
}

//------------------------------------------------------------------------------
// Address: 0x3F63FED0
// Name: _memcpy_1
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl memcpy_1(void *a1, const void *Src, size_t Size)
{
  if ( a1 > Src && a1 < (char *)Src + Size )
    JUMPOUT(0x3F640094);
  if ( Size < 0x100 )
    JUMPOUT(0x3F63FF17);
  return (void *)__crtsetenv(poption: (char **)a1, primary: (const int)Src);
}

//------------------------------------------------------------------------------
// Address: 0x3F63FEF8
// Name: ___crtsetenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
__m128i *__usercall __crtsetenv@<eax>(
        char a1@<dl>,
        unsigned int a2@<ecx>,
        int ebp0@<ebp>,
        _BYTE *a4@<edi>,
        _BYTE *a5@<esi>,
        __m128i *poption,
        const __m128i *primary,
        unsigned int a3)
{
  __m128i *result; // eax
  unsigned int v9; // ecx
  int v10; // edx
  bool v11; // cf
  unsigned int v12; // ecx

  if ( dword_3F665FB8 != 0 && ((unsigned __int8)a4 & 0xF) == ((unsigned __int8)a5 & 0xF) )
    return _VEC_memcpy_0(a1: poption, a2: primary, a3);
  if ( ((unsigned __int8)a4 & 3) != 0 )
  {
    v11 = a2 < 4;
    v12 = a2 - 4;
    if ( !v11 )
      __asm { jmp     dword ptr ds:(CopyUnwindUp_1+4)[eax*4] }
    __asm { jmp     dword ptr ds:TrailUp0_2[ecx*4]; jumptable 3F63FF2C case 0 }
  }
  v9 = a2 >> 2;
  v10 = a1 & 3;
  switch ( v9 )
  {
    case 0u:
      goto UnwindUp0_2;
    case 1u:
      goto UnwindUp1_2;
    case 2u:
      goto UnwindUp2_1;
    case 3u:
      goto UnwindUp3_1;
    case 4u:
      goto UnwindUp4_2;
    case 5u:
      goto UnwindUp5_1;
    case 6u:
      goto UnwindUp6_1;
    case 7u:
      *(_DWORD *)&a4[4 * v9 - 28] = *(_DWORD *)&a5[4 * v9 - 28];
UnwindUp6_1:
      *(_DWORD *)&a4[4 * v9 - 24] = *(_DWORD *)&a5[4 * v9 - 24];
UnwindUp5_1:
      *(_DWORD *)&a4[4 * v9 - 20] = *(_DWORD *)&a5[4 * v9 - 20];
UnwindUp4_2:
      *(_DWORD *)&a4[4 * v9 - 16] = *(_DWORD *)&a5[4 * v9 - 16];
UnwindUp3_1:
      *(_DWORD *)&a4[4 * v9 - 12] = *(_DWORD *)&a5[4 * v9 - 12];
UnwindUp2_1:
      *(_DWORD *)&a4[4 * v9 - 8] = *(_DWORD *)&a5[4 * v9 - 8];
UnwindUp1_2:
      *(_DWORD *)&a4[4 * v9 - 4] = *(_DWORD *)&a5[4 * v9 - 4];
      a5 += 4 * v9;
      a4 += 4 * v9;
UnwindUp0_2:
      switch ( v10 )
      {
        case 0:
          goto TrailUp0_2;
        case 1:
          goto TrailUp1_2;
        case 2:
          goto TrailUp2_2;
        case 3:
          goto TrailUp3_2;
      }
    default:
      qmemcpy(a4, a5, 4 * v9);
      a5 += 4 * v9;
      a4 += 4 * v9;
      switch ( v10 )
      {
        case 0:
TrailUp0_2:
          result = *(__m128i **)(ebp0 + 8);
          break;
        case 1:
TrailUp1_2:
          *a4 = *a5;
          result = *(__m128i **)(ebp0 + 8);
          break;
        case 2:
TrailUp2_2:
          *a4 = *a5;
          a4[1] = a5[1];
          result = *(__m128i **)(ebp0 + 8);
          break;
        case 3:
TrailUp3_2:
          *a4 = *a5;
          a4[1] = a5[1];
          a4[2] = a5[2];
          result = *(__m128i **)(ebp0 + 8);
          break;
      }
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F640144
// Name: __strdup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _strdup(int a1@<eax>)
{
  *(_DWORD *)(a1 + 1183449927) = __ROR4__(*(_DWORD *)(a1 + 1183449927), 1);
  JUMPOUT(0x40AB8959);
}

//------------------------------------------------------------------------------
// Address: 0x3F640194
// Name: __mbschr_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
const unsigned __int8 *__usercall _mbschr_l@<eax>(int a1@<edx>, int a2@<ecx>, int a3@<ebp>, int a4@<edi>, int a5@<esi>)
{
  _BYTE *v5; // esi
  _BYTE *v6; // edi
  const unsigned __int8 *result; // eax

  *(_DWORD *)(a4 + 4 * a2 + 28) = *(_DWORD *)(a5 + 4 * a2 + 28);
  *(_DWORD *)(a4 + 4 * a2 + 24) = *(_DWORD *)(a5 + 4 * a2 + 24);
  *(_DWORD *)(a4 + 4 * a2 + 20) = *(_DWORD *)(a5 + 4 * a2 + 20);
  *(_DWORD *)(a4 + 4 * a2 + 16) = *(_DWORD *)(a5 + 4 * a2 + 16);
  *(_DWORD *)(a4 + 4 * a2 + 12) = *(_DWORD *)(a5 + 4 * a2 + 12);
  *(_DWORD *)(a4 + 4 * a2 + 8) = *(_DWORD *)(a5 + 4 * a2 + 8);
  *(_DWORD *)(a4 + 4 * a2 + 4) = *(_DWORD *)(a5 + 4 * a2 + 4);
  v5 = (_BYTE *)(4 * a2 + a5);
  v6 = (_BYTE *)(4 * a2 + a4);
  switch ( a1 )
  {
    case 0:
      result = *(const unsigned __int8 **)(a3 + 8);
      break;
    case 1:
      v6[3] = v5[3];
      result = *(const unsigned __int8 **)(a3 + 8);
      break;
    case 2:
      v6[3] = v5[3];
      v6[2] = v5[2];
      result = *(const unsigned __int8 **)(a3 + 8);
      break;
    case 3:
      v6[3] = v5[3];
      v6[2] = v5[2];
      v6[1] = v5[1];
      result = *(const unsigned __int8 **)(a3 + 8);
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F64024E
// Name: __mbschr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x3F640274
// Name: GetCommandLineA()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPSTR __stdcall GetCommandLineA()
{
  JUMPOUT(0x3F64027A);
}

//------------------------------------------------------------------------------
// Address: 0x3F64027A
// Name: HeapFree(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall HeapFree(HANDLE hHeap, DWORD dwFlags, LPVOID lpMem)
{
  int v3; // ebp
  int v4; // esi

  *(_DWORD *)(v3 + 12) = v4;
  JUMPOUT(0x3F640282);
}

//------------------------------------------------------------------------------
// Address: 0x3F640280
// Name: GetCPInfo(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
BOOL __stdcall GetCPInfo(UINT CodePage, LPCPINFO lpCPInfo)
{
  _DWORD *v2; // ebx
  int v3; // edi

  *v2 += v3;
  JUMPOUT(0x3F640286);
}

//------------------------------------------------------------------------------
// Address: 0x3F6402A4
// Name: TlsGetValue(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
LPVOID __stdcall TlsGetValue(DWORD dwTlsIndex)
{
  return ProcessCodePage(dwTlsIndex);
}

//------------------------------------------------------------------------------
// Address: 0x3F6402A9
// Name: _ProcessCodePage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void ProcessCodePage()
{
  JUMPOUT(0x3F6402AA);
}

//------------------------------------------------------------------------------
// Address: 0x3F6402B0
// Name: TlsSetValue(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall TlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue)
{
  LOBYTE(_AX) = 18;
  __asm { aas }
  JUMPOUT(0x3F6402B6);
}

//------------------------------------------------------------------------------
// Address: 0x3F6402B6
// Name: TlsFree(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall TlsFree(DWORD dwTlsIndex)
{
  int v1; // eax
  int v2; // ebp

  *(_DWORD *)(v2 - 4) = v1;
  JUMPOUT(0x3F6402BC);
}

//------------------------------------------------------------------------------
// Address: 0x3F6402E0
// Name: ExitProcess(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn ExitProcess(UINT uExitCode)
{
  int v1; // ebp

  ++*(_DWORD *)(v1 + 1968789952);
  EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)uExitCode);
}

//------------------------------------------------------------------------------
// Address: 0x3F6402E6
// Name: EnterCriticalSection(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall __noreturn EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  __halt();
}

//------------------------------------------------------------------------------
// Address: 0x3F6402EC
// Name: LeaveCriticalSection(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection)
{
  JUMPOUT(0x3F6402FC);
}

//------------------------------------------------------------------------------
// Address: 0x3F6402F2
// Name: RtlUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall RtlUnwind(PVOID TargetFrame, PVOID TargetIp, PEXCEPTION_RECORD ExceptionRecord, PVOID ReturnValue)
{
  char v4; // cl
  int v5; // ebp

  *(_BYTE *)(v5 + 1750135877) |= v4;
  JUMPOUT(0x3F6402F8);
}

//------------------------------------------------------------------------------
// Address: 0x3F640320
// Name: _TestDefaultCountry
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void TestDefaultCountry()
{
  JUMPOUT(0x3F640322);
}

//------------------------------------------------------------------------------
// Address: 0x3F640328
// Name: SetCurrentDirectoryA(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall SetCurrentDirectoryA(LPCSTR lpPathName)
{
  JUMPOUT(0x3F64032E);
}

//------------------------------------------------------------------------------
// Address: 0x3F640334
// Name: LCMapStringA(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall LCMapStringA(LCID Locale, DWORD dwMapFlags, LPCSTR lpSrcStr, int cchSrc, LPSTR lpDestStr, int cchDest)
{
  JUMPOUT(0x3F64036B);
}

//------------------------------------------------------------------------------
// Address: 0x3F64033A
// Name: LCMapStringW(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall LCMapStringW(LCID Locale, DWORD dwMapFlags, LPCWSTR lpSrcStr, int cchSrc, LPWSTR lpDestStr, int cchDest)
{
  int result; // eax

  return result;
}

//------------------------------------------------------------------------------
// Address: 0x3F640346
// Name: GetEnvironmentStrings()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
LPCH __stdcall GetEnvironmentStrings()
{
  unsigned __int8 v1; // [esp-20h] [ebp-20h]

  if ( v1 <= 5u )
    JUMPOUT(0x3F64034C);
  JUMPOUT(0x3F640351);
}

//------------------------------------------------------------------------------
// Address: 0x3F64034C
// Name: FreeEnvironmentStringsW(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall FreeEnvironmentStringsW(LPWCH penv)
{
  JUMPOUT(0x3F64035C);
}

//------------------------------------------------------------------------------
// Address: 0x3F640358
// Name: QueryPerformanceCounter(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall QueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount)
{
  JUMPOUT(0x3F64035E);
}

//------------------------------------------------------------------------------
// Address: 0x3F64036A
// Name: GetSystemTimeAsFileTime(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __stdcall GetSystemTimeAsFileTime(LPFILETIME lpSystemTimeAsFileTime)
{
  char v1; // zf

  if ( !v1 )
    JUMPOUT(0x3F640345);
}

//------------------------------------------------------------------------------
// Address: 0x3F640370
// Name: GetStringTypeA(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall GetStringTypeA(LCID Locale, DWORD dwInfoType, LPCSTR lpSrcStr, int cchSrc, LPWORD lpCharType)
{
  JUMPOUT(0x3F640372);
}

//------------------------------------------------------------------------------
// Address: 0x3F64037C
// Name: GetTimeFormatA(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __stdcall GetTimeFormatA(
        LCID Locale,
        DWORD dwFlags,
        const SYSTEMTIME *lpTime,
        LPCSTR lpFormat,
        LPSTR lpTimeStr,
        int cchTime)
{
  char v6; // zf
  char v7; // sf
  char v8; // of

  if ( v7 ^ v8 | v6 )
    JUMPOUT(0x3F640387);
  return GetDateFormatA(Locale, dwFlags, lpDate: lpTime, lpFormat, lpDateStr: lpTimeStr, cchDate: cchTime);
}

//------------------------------------------------------------------------------
// Address: 0x3F640382
// Name: GetDateFormatA(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall GetDateFormatA(
        LCID Locale,
        DWORD dwFlags,
        const SYSTEMTIME *lpDate,
        LPCSTR lpFormat,
        LPSTR lpDateStr,
        int cchDate)
{
  unsigned __int8 v6; // cl

  if ( v6 <= 0x19u )
    JUMPOUT(0x3F640388);
  JUMPOUT(0x3F64038A);
}

//------------------------------------------------------------------------------
// Address: 0x3F640388
// Name: GetUserDefaultLCID()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
LCID __stdcall GetUserDefaultLCID()
{
  JUMPOUT(0x3F640375);
}

//------------------------------------------------------------------------------
// Address: 0x3F64038A
// Name: nullsub_32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void nullsub_32()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x3F64039A
// Name: IsValidLocale(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall IsValidLocale(LCID Locale, DWORD dwFlags)
{
  JUMPOUT(0x3F6403A0);
}

//------------------------------------------------------------------------------
// Address: 0x3F6403DC
// Name: GetLocaleInfoW(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __stdcall GetLocaleInfoW(LCID Locale, LCTYPE LCType, LPWSTR lpLCData, int cchData)
{
  int v4; // ebp

  __security_check_cookie`...'(StackCookie: v4 ^ *(_DWORD *)(v4 - 4));
  JUMPOUT(0x3F64041E);
}

//------------------------------------------------------------------------------
// Address: 0x3F6403FA
// Name: WriteConsoleW(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall WriteConsoleW(
        HANDLE hConsoleOutput,
        const void *lpBuffer,
        DWORD nNumberOfCharsToWrite,
        LPDWORD lpNumberOfCharsWritten,
        LPVOID lpReserved)
{
  char v5; // zf
  int v6; // esi

  if ( !v5 )
  {
    *(_DWORD *)(v6 + 8) |= 4u;
    JUMPOUT(0x3F640400);
  }
  JUMPOUT(0x3F640406);
}

//------------------------------------------------------------------------------
// Address: 0x3F640400
// Name: CompareStringA(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CompareStringA(
        LCID Locale,
        DWORD dwCmpFlags,
        PCNZCH lpString1,
        int cchCount1,
        PCNZCH lpString2,
        int cchCount2)
{
  int v6; // edi
  int v7; // esi

  *(_DWORD *)(v7 + 28) = v6;
  *(_DWORD *)(v7 + 24) = v6;
  return CompareStringW(Locale, dwCmpFlags, (PCNZWCH)lpString1, cchCount1, (PCNZWCH)lpString2, cchCount2);
}

//------------------------------------------------------------------------------
// Address: 0x3F640406
// Name: CompareStringW(x,x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall CompareStringW(
        LCID Locale,
        DWORD dwCmpFlags,
        PCNZWCH lpString1,
        int cchCount1,
        PCNZWCH lpString2,
        int cchCount2)
{
  JUMPOUT(0x3F64040C);
}

//------------------------------------------------------------------------------
// Address: 0x3F640420
// Name: __CIsqrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _CIsqrt(unsigned __int16 a1@<dx>, const char **a2@<ecx>, int a3@<ebp>, LCID a4@<edi>, DWORD a5@<esi>)
{
  const char *v7; // esi
  const char *v9; // [esp-7Ch] [ebp-7Ch]
  int v10; // [esp-78h] [ebp-78h]
  unsigned __int16 *v11; // [esp-74h] [ebp-74h]

  *(_BYTE *)(a3 - 117) += a1;
  __inbyte(a1);
  *(_DWORD *)(a3 - 4) = a3 ^ __security_cookie;
  if ( GetLocaleInfoA(
         Locale: *(_DWORD *)(a3 + 8) & 0x3FF | 0x400,
         LCType: 1u,
         lpLCData: (LPSTR)(a3 - 124),
         cchData: 120) != 0
    && *(_DWORD *)(a3 + 8) != ((int (*)(void))LcidFromHexString)()
    && *(_DWORD *)(a3 + 12) != 0 )
  {
    v7 = *a2;
    GetStringTypeA(Locale: a4, dwInfoType: a5, lpSrcStr: v9, cchSrc: v10, lpCharType: v11);
    strlen_0(Str: v7);
  }
  __security_check_cookie`...'(StackCookie: a3 ^ *(_DWORD *)(a3 - 4));
}
