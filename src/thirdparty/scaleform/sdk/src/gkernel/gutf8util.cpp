// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gutf8util.cpp
// Functions: 8
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gutf8util.h"

//------------------------------------------------------------------------------
// Address: 0x100AA4E0
// Name: public: static int GUTF8Util::GetEncodeCharSize(unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GUTF8Util::GetEncodeCharSize(RGB888_t *__return_ptr retstr)
{
  if ( (unsigned int)retstr <= 0x7F )
    return 1;
  if ( (unsigned int)retstr <= 0x7FF )
    return 2;
  if ( (unsigned int)retstr <= 0xFFFF )
    return 3;
  if ( (unsigned int)retstr <= 0x1FFFFF )
    return 4;
  if ( (unsigned int)retstr > 0x3FFFFFF )
    return (unsigned int)retstr > 0x7FFFFFFF ? 0 : 6;
  return 5;
}

//------------------------------------------------------------------------------
// Address: 0x100AA550
// Name: public: static unsigned long GUTF8Util::DecodeNextChar(char const __near * __near *)
// Source: json
//------------------------------------------------------------------------------
static unsigned int __stdcall GUTF8Util::DecodeNextChar(CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer)
{
  unsigned int result; // eax
  char *v2; // edx
  char v3; // si
  char v4; // al
  int v5; // esi
  unsigned int v6; // esi
  char v7; // si
  char v8; // al
  int v9; // esi
  char *v10; // edx
  int v11; // esi
  char v12; // al
  unsigned int v13; // esi
  char v14; // si
  char v15; // al
  int v16; // esi
  char *v17; // edx
  char v18; // bl
  int v19; // esi
  char *v20; // eax
  int v21; // esi
  char v22; // dl
  unsigned int v23; // esi
  char v24; // si
  char v25; // al
  int v26; // esi
  char *v27; // edx
  char v28; // bl
  int v29; // esi
  char *v30; // eax
  int v31; // esi
  char v32; // dl
  char *v33; // eax
  int v34; // esi
  char v35; // dl
  unsigned int v36; // esi
  char v37; // si
  char v38; // al
  int v39; // esi
  char *v40; // edx
  char v41; // bl
  int v42; // esi
  char *v43; // eax
  int v44; // esi
  char v45; // dl
  char *v46; // eax
  int v47; // esi
  char v48; // dl
  char *v49; // eax
  int v50; // esi
  char v51; // dl

  LOBYTE(result) = **(_BYTE **)putf8Buffer.m_LessFunc;
  if ( (_BYTE)result == 0 )
    return 0;
  v2 = (char *)(*(_DWORD *)putf8Buffer.m_LessFunc + 1);
  *(_DWORD *)putf8Buffer.m_LessFunc = v2;
  if ( (result & 0x80u) == 0 )
    return (char)result;
  if ( (result & 0xE0) == 0xC0 )
  {
    v3 = result;
    v4 = *v2;
    v5 = (v3 & 0x1F) << 6;
    if ( *v2 != 0 )
    {
      if ( (v4 & 0xC0) == 0x80 )
      {
        v6 = v4 & 0x3F | v5;
        *(_DWORD *)putf8Buffer.m_LessFunc = v2 + 1;
        if ( v6 >= 0x80 )
          return v6;
      }
      return 65533;
    }
    return 0;
  }
  if ( (result & 0xF0) != 0xE0 )
  {
    if ( (result & 0xF8) == 0xF0 )
    {
      v14 = result;
      v15 = *v2;
      v16 = (v14 & 7) << 18;
      if ( *v2 == 0 )
        return 0;
      if ( (v15 & 0xC0) == 0x80 )
      {
        v17 = v2 + 1;
        *(_DWORD *)putf8Buffer.m_LessFunc = v17;
        v18 = *v17;
        v19 = ((v15 & 0x3F) << 12) | v16;
        if ( *v17 == 0 )
          return 0;
        if ( (v18 & 0xC0) == 0x80 )
        {
          v20 = v17 + 1;
          v21 = ((v18 & 0x3F) << 6) | v19;
          *(_DWORD *)putf8Buffer.m_LessFunc = v17 + 1;
          v22 = *v20;
          if ( *v20 == 0 )
            return 0;
          if ( (v22 & 0xC0) == 0x80 )
          {
            *(_DWORD *)putf8Buffer.m_LessFunc = v20 + 1;
            v23 = v22 & 0x3F | v21;
            if ( v23 >= 0x10000 )
              return v23;
          }
        }
      }
    }
    else if ( (result & 0xFC) == 0xF8 )
    {
      v24 = result;
      v25 = *v2;
      v26 = (v24 & 3) << 24;
      if ( *v2 == 0 )
        return 0;
      if ( (v25 & 0xC0) == 0x80 )
      {
        v27 = v2 + 1;
        *(_DWORD *)putf8Buffer.m_LessFunc = v27;
        v28 = *v27;
        v29 = ((v25 & 0x3F) << 18) | v26;
        if ( *v27 == 0 )
          return 0;
        if ( (v28 & 0xC0) == 0x80 )
        {
          v30 = v27 + 1;
          v31 = ((v28 & 0x3F) << 12) | v29;
          *(_DWORD *)putf8Buffer.m_LessFunc = v27 + 1;
          v32 = *v30;
          if ( *v30 == 0 )
            return 0;
          if ( (v32 & 0xC0) == 0x80 )
          {
            v33 = v30 + 1;
            v34 = ((v32 & 0x3F) << 6) | v31;
            *(_DWORD *)putf8Buffer.m_LessFunc = v33;
            v35 = *v33;
            if ( *v33 == 0 )
              return 0;
            if ( (v35 & 0xC0) == 0x80 )
            {
              *(_DWORD *)putf8Buffer.m_LessFunc = v33 + 1;
              v36 = v35 & 0x3F | v34;
              if ( v36 >= 0x200000 )
                return v36;
            }
          }
        }
      }
    }
    else if ( (result & 0xFE) == 0xFC )
    {
      v37 = result;
      v38 = *v2;
      v39 = (v37 & 1) << 30;
      if ( *v2 == 0 )
        return 0;
      if ( (v38 & 0xC0) == 0x80 )
      {
        v40 = v2 + 1;
        *(_DWORD *)putf8Buffer.m_LessFunc = v40;
        v41 = *v40;
        v42 = ((v38 & 0x3F) << 24) | v39;
        if ( *v40 == 0 )
          return 0;
        if ( (v41 & 0xC0) == 0x80 )
        {
          v43 = v40 + 1;
          v44 = ((v41 & 0x3F) << 18) | v42;
          *(_DWORD *)putf8Buffer.m_LessFunc = v40 + 1;
          v45 = *v43;
          if ( *v43 == 0 )
            return 0;
          if ( (v45 & 0xC0) == 0x80 )
          {
            v46 = v43 + 1;
            v47 = ((v45 & 0x3F) << 12) | v44;
            *(_DWORD *)putf8Buffer.m_LessFunc = v46;
            v48 = *v46;
            if ( *v46 == 0 )
              return 0;
            if ( (v48 & 0xC0) == 0x80 )
            {
              v49 = v46 + 1;
              v50 = ((v48 & 0x3F) << 6) | v47;
              *(_DWORD *)putf8Buffer.m_LessFunc = v49;
              v51 = *v49;
              if ( *v49 != 0 )
              {
                if ( (v51 & 0xC0) != 0x80 )
                  return 65533;
                *(_DWORD *)putf8Buffer.m_LessFunc = v49 + 1;
                v13 = v51 & 0x3F | v50;
                if ( v13 < 0x4000000 )
                  return 65533;
                return v13;
              }
              return 0;
            }
          }
        }
      }
    }
    return 65533;
  }
  v7 = result;
  v8 = *v2;
  v9 = (v7 & 0xF) << 12;
  if ( *v2 == 0 )
    return 0;
  if ( (v8 & 0xC0) != 0x80 )
    return 65533;
  v10 = v2 + 1;
  v11 = ((v8 & 0x3F) << 6) | v9;
  *(_DWORD *)putf8Buffer.m_LessFunc = v10;
  v12 = *v10;
  if ( *v10 == 0 )
    return 0;
  if ( (v12 & 0xC0) != 0x80 )
    return 65533;
  *(_DWORD *)putf8Buffer.m_LessFunc = v10 + 1;
  v13 = v12 & 0x3F | v11;
  if ( v13 < 0x800 || v13 - 55296 <= 0x7FF || v13 == 65534 || v13 == 0xFFFF )
    return 65533;
  return v13;
}

//------------------------------------------------------------------------------
// Address: 0x100AA880
// Name: public: static void GUTF8Util::EncodeChar(char __near *,int __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
static void __stdcall GUTF8Util::EncodeChar(char *a1, int *a2, unsigned int a3)
{
  int *v3; // ecx
  char *v4; // esi

  if ( a3 <= 0x7F )
  {
    a1[(*a2)++] = a3;
    return;
  }
  if ( a3 <= 0x7FF )
  {
    a1[(*a2)++] = (a3 >> 6) | 0xC0;
    a1[(*a2)++] = a3 & 0x3F | 0x80;
    return;
  }
  if ( a3 > 0xFFFF )
  {
    if ( a3 > 0x1FFFFF )
    {
      if ( a3 > 0x3FFFFFF )
      {
        if ( a3 > 0x7FFFFFFF )
          return;
        v3 = a2;
        v4 = a1;
        a1[(*a2)++] = (a3 >> 30) | 0xFC;
        a1[*a2] = HIBYTE(a3) & 0x3F | 0x80;
      }
      else
      {
        v3 = a2;
        v4 = a1;
        a1[*a2] = HIBYTE(a3) | 0xF8;
      }
      v4[++*v3] = (a3 >> 18) & 0x3F | 0x80;
    }
    else
    {
      v3 = a2;
      v4 = a1;
      a1[*a2] = (a3 >> 18) | 0xF0;
    }
    v4[++*v3] = (a3 >> 12) & 0x3F | 0x80;
  }
  else
  {
    v3 = a2;
    v4 = a1;
    a1[*a2] = (a3 >> 12) | 0xE0;
  }
  v4[++*v3] = (a3 >> 6) & 0x3F | 0x80;
  v4[++*v3] = a3 & 0x3F | 0x80;
  ++*v3;
}

//------------------------------------------------------------------------------
// Address: 0x100AA9A0
// Name: public: static int GUTF8Util::GetEncodeStringSize(wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
RGB888_t *__stdcall GUTF8Util::GetEncodeStringSize(RGB888_t *__return_ptr retstr, int a2)
{
  __int64 v2; // rax
  unsigned int v3; // ecx
  int v4; // ecx
  unsigned __int16 i; // cx
  int v6; // ecx

  v2 = 0;
  if ( a2 == -1 )
  {
    for ( i = *(_WORD *)&retstr->r; i != 0; i = *((_WORD *)&retstr->r + HIDWORD(v2)) )
    {
      if ( i > 0x7Fu )
      {
        if ( i > 0x7FFu )
          v6 = 3;
        else
          v6 = 2;
      }
      else
      {
        v6 = 1;
      }
      ++HIDWORD(v2);
      LODWORD(v2) = v6 + v2;
    }
  }
  else if ( a2 > 0 )
  {
    do
    {
      v3 = *((unsigned __int16 *)&retstr->r + HIDWORD(v2));
      if ( (_WORD)v3 == 0 )
        break;
      if ( v3 > 0x7F )
        v4 = v3 > 0x7FF ? 3 : 2;
      else
        v4 = 1;
      ++HIDWORD(v2);
      LODWORD(v2) = v4 + v2;
    }
    while ( SHIDWORD(v2) < a2 );
  }
  return (RGB888_t *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x100AAAB0
// Name: public: static void GUTF8Util::EncodeString(char __near *,wchar_t const __near *,int)
// Source: json
//------------------------------------------------------------------------------
static void __stdcall GUTF8Util::EncodeString(char *a1, wchar_t *a2, int a3)
{
  int v3; // eax
  int v4; // edi
  unsigned int v5; // ecx
  int v6; // esi
  wchar_t v7; // ax
  int v8; // [esp+Ch] [ebp-4h] BYREF

  v3 = 0;
  v8 = 0;
  if ( a3 == -1 )
  {
    v6 = 0;
    if ( *a2 != 0 )
    {
      v7 = *a2;
      do
      {
        GUTF8Util::EncodeChar(a1, a2: &v8, a3: v7);
        v7 = a2[++v6];
      }
      while ( v7 != 0 );
      a1[v8] = 0;
    }
    else
    {
      *a1 = 0;
    }
  }
  else
  {
    v4 = 0;
    if ( a3 <= 0 )
    {
      *a1 = 0;
    }
    else
    {
      do
      {
        v5 = a2[v4];
        if ( (_WORD)v5 == 0 )
          break;
        if ( v5 > 0x7F )
        {
          if ( v5 > 0x7FF )
          {
            a1[v3] = (v5 >> 12) | 0xE0;
            a1[v3 + 1] = (v5 >> 6) & 0x3F | 0x80;
            a1[v3 + 2] = v5 & 0x3F | 0x80;
            v3 += 3;
          }
          else
          {
            a1[v3] = (v5 >> 6) | 0xC0;
            a1[v3 + 1] = v5 & 0x3F | 0x80;
            v3 += 2;
          }
        }
        else
        {
          a1[v3++] = v5;
        }
        ++v4;
      }
      while ( v4 < a3 );
      a1[v3] = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100AACC0
// Name: public: static unsigned int GUTF8Util::DecodeString(wchar_t __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
static int __stdcall GUTF8Util::DecodeString(
        wchar_t *pbegin,
        CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer,
        int length)
{
  int v3; // esi
  wchar_t *v4; // edi
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // eax
  unsigned int v6; // ecx
  char v7; // dl
  int v8; // ecx
  bool v9; // cf
  char v10; // dl
  int v11; // ecx
  int v12; // ecx
  char v13; // dl
  char v14; // dl
  int v15; // ecx
  int v16; // ecx
  char v17; // dl
  int v18; // ecx
  char v19; // dl
  char v20; // dl
  int v21; // ecx
  int v22; // ecx
  char v23; // dl
  int v24; // ecx
  char v25; // dl
  int v26; // ecx
  char v27; // dl
  char v28; // dl
  int v29; // ecx
  int v30; // ecx
  char v31; // dl
  int v32; // ecx
  char v33; // dl
  int v34; // ecx
  char v35; // dl
  int v36; // ecx
  char v37; // dl
  unsigned int Char; // eax

  v3 = length;
  v4 = pbegin;
  if ( length == -1 )
  {
    m_LessFunc = putf8Buffer.m_LessFunc;
    while ( 1 )
    {
      LOBYTE(v6) = *(_BYTE *)m_LessFunc;
      if ( *(_BYTE *)m_LessFunc == 0 )
        goto LABEL_60;
      m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
      if ( (v6 & 0x80u) == 0 )
      {
        v6 = (char)v6;
        goto LABEL_51;
      }
      if ( (v6 & 0xE0) == 0xC0 )
        break;
      if ( (v6 & 0xF0) != 0xE0 )
      {
        if ( (v6 & 0xF8) == 0xF0 )
        {
          v14 = *(_BYTE *)m_LessFunc;
          v15 = (v6 & 7) << 18;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v14 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v16 = ((v14 & 0x3F) << 12) | v15;
          v17 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v17 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v18 = ((v17 & 0x3F) << 6) | v16;
          v19 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v19 & 0xC0) != 0x80 )
            goto LABEL_53;
          v6 = v19 & 0x3F | v18;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v9 = v6 < 0x10000;
        }
        else if ( (v6 & 0xFC) == 0xF8 )
        {
          v20 = *(_BYTE *)m_LessFunc;
          v21 = (v6 & 3) << 24;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v20 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v22 = ((v20 & 0x3F) << 18) | v21;
          v23 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v23 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v24 = ((v23 & 0x3F) << 12) | v22;
          v25 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v25 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v26 = ((v25 & 0x3F) << 6) | v24;
          v27 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v27 & 0xC0) != 0x80 )
            goto LABEL_53;
          v6 = v27 & 0x3F | v26;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v9 = v6 < 0x200000;
        }
        else
        {
          if ( (v6 & 0xFE) != 0xFC )
            goto LABEL_53;
          v28 = *(_BYTE *)m_LessFunc;
          v29 = (v6 & 1) << 30;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v28 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v30 = ((v28 & 0x3F) << 24) | v29;
          v31 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v31 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v32 = ((v31 & 0x3F) << 18) | v30;
          v33 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v33 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v34 = ((v33 & 0x3F) << 12) | v32;
          v35 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v35 & 0xC0) != 0x80 )
            goto LABEL_53;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v36 = ((v35 & 0x3F) << 6) | v34;
          v37 = *(_BYTE *)m_LessFunc;
          if ( *(_BYTE *)m_LessFunc == 0 )
            goto LABEL_60;
          if ( (v37 & 0xC0) != 0x80 )
            goto LABEL_53;
          v6 = v37 & 0x3F | v36;
          m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
          v9 = v6 < 0x4000000;
        }
        goto LABEL_50;
      }
      v10 = *(_BYTE *)m_LessFunc;
      v11 = (v6 & 0xF) << 12;
      if ( *(_BYTE *)m_LessFunc == 0 )
        goto LABEL_60;
      if ( (v10 & 0xC0) != 0x80 )
        goto LABEL_53;
      m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
      v12 = ((v10 & 0x3F) << 6) | v11;
      v13 = *(_BYTE *)m_LessFunc;
      if ( *(_BYTE *)m_LessFunc == 0 )
        goto LABEL_60;
      if ( (v13 & 0xC0) != 0x80 )
        goto LABEL_53;
      v6 = v13 & 0x3F | v12;
      m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
      if ( v6 < 0x800 || v6 - 55296 <= 0x7FF || v6 == 65534 )
        goto LABEL_53;
      if ( v6 == 0xFFFF )
      {
        *v4++ = -3;
      }
      else
      {
LABEL_51:
        if ( v6 == 0 )
          goto LABEL_60;
        if ( v6 >= 0xFFFF )
LABEL_53:
          LOWORD(v6) = -3;
        *v4++ = v6;
      }
    }
    v7 = *(_BYTE *)m_LessFunc;
    v8 = (v6 & 0x1F) << 6;
    if ( *(_BYTE *)m_LessFunc == 0 )
      goto LABEL_60;
    if ( (v7 & 0xC0) != 0x80 )
      goto LABEL_53;
    v6 = v7 & 0x3F | v8;
    m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
    v9 = v6 < 0x80;
LABEL_50:
    if ( v9 )
      goto LABEL_53;
    goto LABEL_51;
  }
  if ( length > 0 )
  {
    do
    {
      Char = GUTF8Util::DecodeNextChar((CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer);
      --v3;
      if ( Char == 0 )
        break;
      if ( Char >= 0xFFFF )
        LOWORD(Char) = -3;
      *v4++ = Char;
    }
    while ( v3 > 0 );
  }
LABEL_60:
  *v4 = 0;
  return v4 - pbegin;
}

//------------------------------------------------------------------------------
// Address: 0x100AB020
// Name: public: static int GUTF8Util::GetLength(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
static const char *__stdcall GUTF8Util::GetLength(
        bool (__cdecl *length)(const char *const *, const char *const *),
        int buflen)
{
  bool (__cdecl *v2)(const char *const *, const char *const *); // eax
  int v3; // esi
  int v4; // ecx
  char v5; // dl
  unsigned int v6; // esi
  int v7; // edi
  char v8; // dl
  unsigned int v9; // edi
  char v10; // si
  char v11; // dl
  int v12; // esi
  int v13; // esi
  char v14; // dl
  char v15; // si
  char v16; // dl
  int v17; // esi
  int v18; // esi
  char v19; // dl
  int v20; // esi
  char v21; // dl
  bool v22; // cf
  char v23; // si
  char v24; // dl
  int v25; // esi
  int v26; // esi
  char v27; // dl
  int v28; // esi
  char v29; // dl
  int v30; // esi
  char v31; // dl
  char v32; // si
  char v33; // dl
  int v34; // esi
  int v35; // esi
  char v36; // dl
  int v37; // esi
  char v38; // dl
  int v39; // esi
  char v40; // dl
  int v41; // esi
  char v42; // dl
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+Ch] [ebp-4h] BYREF
  const char *lengtha; // [esp+18h] [ebp+8h]

  v2 = length;
  v3 = 0;
  putf8Buffer.m_LessFunc = length;
  lengtha = nullptr;
  if ( buflen == -1 )
  {
    if ( GUTF8Util::DecodeNextChar((CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer) != 0 )
    {
      do
        ++v3;
      while ( GUTF8Util::DecodeNextChar((CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer) != 0 );
      return (const char *)v3;
    }
  }
  else if ( buflen > 0 )
  {
    v4 = 0;
    while ( 1 )
    {
      v5 = *(_BYTE *)v2;
      if ( *(_BYTE *)v2 == 0 )
        return lengtha;
      v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
      ++v4;
      if ( v5 >= 0 )
      {
        v6 = v5;
        goto LABEL_53;
      }
      if ( (v5 & 0xE0) == 0xC0 )
      {
        v7 = (v5 & 0x1F) << 6;
        v8 = *(_BYTE *)v2;
        if ( *(_BYTE *)v2 == 0 )
          return lengtha;
        if ( (v8 & 0xC0) == 0x80 )
        {
          v9 = v8 & 0x3F | v7;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          ++v4;
          if ( v9 >= 0x80 )
          {
            v6 = v9;
LABEL_53:
            if ( v6 == 0 )
              return lengtha;
          }
        }
      }
      else if ( (v5 & 0xF0) == 0xE0 )
      {
        v10 = v5;
        v11 = *(_BYTE *)v2;
        v12 = (v10 & 0xF) << 12;
        if ( *(_BYTE *)v2 == 0 )
          return lengtha;
        if ( (v11 & 0xC0) == 0x80 )
        {
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v13 = ((v11 & 0x3F) << 6) | v12;
          v14 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v14 & 0xC0) == 0x80 )
          {
            v6 = v14 & 0x3F | v13;
            v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
            ++v4;
            if ( v6 >= 0x800 && v6 - 55296 > 0x7FF && v6 != 65534 && v6 != 0xFFFF )
              goto LABEL_53;
          }
        }
      }
      else
      {
        if ( (v5 & 0xF8) == 0xF0 )
        {
          v15 = v5;
          v16 = *(_BYTE *)v2;
          v17 = (v15 & 7) << 18;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v16 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v18 = ((v16 & 0x3F) << 12) | v17;
          v19 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v19 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v20 = ((v19 & 0x3F) << 6) | v18;
          v21 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v21 & 0xC0) != 0x80 )
            goto LABEL_54;
          v6 = v21 & 0x3F | v20;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          ++v4;
          v22 = v6 < 0x10000;
        }
        else if ( (v5 & 0xFC) == 0xF8 )
        {
          v23 = v5;
          v24 = *(_BYTE *)v2;
          v25 = (v23 & 3) << 24;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v24 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v26 = ((v24 & 0x3F) << 18) | v25;
          v27 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v27 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v28 = ((v27 & 0x3F) << 12) | v26;
          v29 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v29 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v30 = ((v29 & 0x3F) << 6) | v28;
          v31 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v31 & 0xC0) != 0x80 )
            goto LABEL_54;
          v6 = v31 & 0x3F | v30;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          ++v4;
          v22 = v6 < 0x200000;
        }
        else
        {
          if ( (v5 & 0xFE) != 0xFC )
            goto LABEL_54;
          v32 = v5;
          v33 = *(_BYTE *)v2;
          v34 = (v32 & 1) << 30;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v33 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v35 = ((v33 & 0x3F) << 24) | v34;
          v36 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v36 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v37 = ((v36 & 0x3F) << 18) | v35;
          v38 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v38 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v39 = ((v38 & 0x3F) << 12) | v37;
          v40 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v40 & 0xC0) != 0x80 )
            goto LABEL_54;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          v41 = ((v40 & 0x3F) << 6) | v39;
          v42 = *(_BYTE *)v2;
          ++v4;
          if ( *(_BYTE *)v2 == 0 )
            return lengtha;
          if ( (v42 & 0xC0) != 0x80 )
            goto LABEL_54;
          v6 = v42 & 0x3F | v41;
          v2 = (bool (__cdecl *)(const char *const *, const char *const *))((char *)v2 + 1);
          ++v4;
          v22 = v6 < 0x4000000;
        }
        if ( !v22 )
          goto LABEL_53;
      }
LABEL_54:
      ++lengtha;
      if ( v4 >= buflen )
        return lengtha;
    }
  }
  return lengtha;
}

//------------------------------------------------------------------------------
// Address: 0x100AB390
// Name: public: static int GUTF8Util::GetByteIndex(int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __stdcall GUTF8Util::GetByteIndex(
        int index,
        bool (__cdecl *a2)(const char *const *, const char *const *),
        int length)
{
  bool (__cdecl *m_LessFunc)(const char *const *, const char *const *); // eax
  int v4; // edi
  int v5; // esi
  unsigned int v6; // ecx
  char v7; // dl
  int v8; // ecx
  char v9; // dl
  int v10; // ecx
  int v11; // ecx
  char v12; // dl
  char v13; // dl
  int v14; // ecx
  int v15; // ecx
  char v16; // dl
  int v17; // ecx
  char v18; // dl
  char v19; // dl
  int v20; // ecx
  int v21; // ecx
  char v22; // dl
  int v23; // ecx
  char v24; // dl
  int v25; // ecx
  char v26; // dl
  char v27; // dl
  int v28; // ecx
  int v29; // ecx
  char v30; // dl
  int v31; // ecx
  char v32; // dl
  int v33; // ecx
  char v34; // dl
  int v35; // ecx
  char v36; // dl
  int v38; // esi
  CUtlMap<char const *,int,unsigned short>::CKeyLess putf8Buffer; // [esp+8h] [ebp-4h] BYREF

  m_LessFunc = a2;
  putf8Buffer.m_LessFunc = a2;
  if ( length == -1 )
  {
    v38 = index;
    if ( index > 0 )
    {
      do
        --v38;
      while ( GUTF8Util::DecodeNextChar((CUtlMap<char const *,int,unsigned short>::CKeyLess)&putf8Buffer) != 0
           && v38 > 0 );
      m_LessFunc = putf8Buffer.m_LessFunc;
    }
    return (char *)m_LessFunc - (char *)a2;
  }
  else
  {
    if ( length > 0 )
    {
      v4 = index;
      v5 = 0;
      do
      {
        if ( v4 <= 0 )
          return (char *)m_LessFunc - (char *)a2;
        LOBYTE(v6) = *(_BYTE *)m_LessFunc;
        if ( *(_BYTE *)m_LessFunc == 0 )
        {
          v6 = 0;
          goto LABEL_72;
        }
        m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
        ++v5;
        if ( (v6 & 0x80u) == 0 )
        {
          v6 = (char)v6;
          goto LABEL_72;
        }
        if ( (v6 & 0xE0) == 0xC0 )
        {
          v7 = *(_BYTE *)m_LessFunc;
          v8 = (v6 & 0x1F) << 6;
          if ( *(_BYTE *)m_LessFunc == 0 )
          {
            v6 = 0;
            goto LABEL_72;
          }
          if ( (v7 & 0xC0) == 0x80 )
          {
            v6 = v7 & 0x3F | v8;
            m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
            ++v5;
            if ( v6 >= 0x80 )
              goto LABEL_72;
          }
        }
        else if ( (v6 & 0xF0) == 0xE0 )
        {
          v9 = *(_BYTE *)m_LessFunc;
          v10 = (v6 & 0xF) << 12;
          if ( *(_BYTE *)m_LessFunc == 0 )
          {
            v6 = 0;
            goto LABEL_72;
          }
          if ( (v9 & 0xC0) == 0x80 )
          {
            m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
            v11 = ((v9 & 0x3F) << 6) | v10;
            v12 = *(_BYTE *)m_LessFunc;
            ++v5;
            if ( *(_BYTE *)m_LessFunc == 0 )
            {
              v6 = 0;
              goto LABEL_72;
            }
            if ( (v12 & 0xC0) == 0x80 )
            {
              v6 = v12 & 0x3F | v11;
              m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
              ++v5;
              if ( v6 >= 0x800 && v6 - 55296 > 0x7FF && v6 != 65534 && v6 != 0xFFFF )
                goto LABEL_72;
            }
          }
        }
        else if ( (v6 & 0xF8) == 0xF0 )
        {
          v13 = *(_BYTE *)m_LessFunc;
          v14 = (v6 & 7) << 18;
          if ( *(_BYTE *)m_LessFunc == 0 )
          {
            v6 = 0;
            goto LABEL_72;
          }
          if ( (v13 & 0xC0) == 0x80 )
          {
            m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
            v15 = ((v13 & 0x3F) << 12) | v14;
            v16 = *(_BYTE *)m_LessFunc;
            ++v5;
            if ( *(_BYTE *)m_LessFunc == 0 )
            {
              v6 = 0;
              goto LABEL_72;
            }
            if ( (v16 & 0xC0) == 0x80 )
            {
              m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
              v17 = ((v16 & 0x3F) << 6) | v15;
              v18 = *(_BYTE *)m_LessFunc;
              ++v5;
              if ( *(_BYTE *)m_LessFunc == 0 )
              {
                v6 = 0;
                goto LABEL_72;
              }
              if ( (v18 & 0xC0) == 0x80 )
              {
                v6 = v18 & 0x3F | v17;
                m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
                ++v5;
                if ( v6 >= 0x10000 )
                  goto LABEL_72;
              }
            }
          }
        }
        else if ( (v6 & 0xFC) == 0xF8 )
        {
          v19 = *(_BYTE *)m_LessFunc;
          v20 = (v6 & 3) << 24;
          if ( *(_BYTE *)m_LessFunc == 0 )
          {
            v6 = 0;
            goto LABEL_72;
          }
          if ( (v19 & 0xC0) == 0x80 )
          {
            m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
            v21 = ((v19 & 0x3F) << 18) | v20;
            v22 = *(_BYTE *)m_LessFunc;
            ++v5;
            if ( *(_BYTE *)m_LessFunc == 0 )
            {
              v6 = 0;
              goto LABEL_72;
            }
            if ( (v22 & 0xC0) == 0x80 )
            {
              m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
              v23 = ((v22 & 0x3F) << 12) | v21;
              v24 = *(_BYTE *)m_LessFunc;
              ++v5;
              if ( *(_BYTE *)m_LessFunc == 0 )
              {
                v6 = 0;
                goto LABEL_72;
              }
              if ( (v24 & 0xC0) == 0x80 )
              {
                m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
                v25 = ((v24 & 0x3F) << 6) | v23;
                v26 = *(_BYTE *)m_LessFunc;
                ++v5;
                if ( *(_BYTE *)m_LessFunc == 0 )
                {
                  v6 = 0;
                  goto LABEL_72;
                }
                if ( (v26 & 0xC0) == 0x80 )
                {
                  v6 = v26 & 0x3F | v25;
                  m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
                  ++v5;
                  if ( v6 >= 0x200000 )
                    goto LABEL_72;
                }
              }
            }
          }
        }
        else if ( (v6 & 0xFE) == 0xFC )
        {
          v27 = *(_BYTE *)m_LessFunc;
          v28 = (v6 & 1) << 30;
          if ( *(_BYTE *)m_LessFunc == 0 )
          {
            v6 = 0;
            goto LABEL_72;
          }
          if ( (v27 & 0xC0) == 0x80 )
          {
            m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
            v29 = ((v27 & 0x3F) << 24) | v28;
            v30 = *(_BYTE *)m_LessFunc;
            ++v5;
            if ( *(_BYTE *)m_LessFunc == 0 )
            {
              v6 = 0;
              goto LABEL_72;
            }
            if ( (v30 & 0xC0) == 0x80 )
            {
              m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
              v31 = ((v30 & 0x3F) << 18) | v29;
              v32 = *(_BYTE *)m_LessFunc;
              ++v5;
              if ( *(_BYTE *)m_LessFunc == 0 )
              {
                v6 = 0;
                goto LABEL_72;
              }
              if ( (v32 & 0xC0) == 0x80 )
              {
                m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
                v33 = ((v32 & 0x3F) << 12) | v31;
                v34 = *(_BYTE *)m_LessFunc;
                ++v5;
                if ( *(_BYTE *)m_LessFunc == 0 )
                {
                  v6 = 0;
                  goto LABEL_72;
                }
                if ( (v34 & 0xC0) == 0x80 )
                {
                  m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
                  v35 = ((v34 & 0x3F) << 6) | v33;
                  v36 = *(_BYTE *)m_LessFunc;
                  ++v5;
                  if ( *(_BYTE *)m_LessFunc == 0 )
                  {
                    v6 = 0;
                    goto LABEL_72;
                  }
                  if ( (v36 & 0xC0) == 0x80 )
                  {
                    v6 = v36 & 0x3F | v35;
                    m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))((char *)m_LessFunc + 1);
                    ++v5;
                    if ( v6 >= 0x4000000 )
                      goto LABEL_72;
                  }
                }
              }
            }
          }
        }
        v6 = 65533;
LABEL_72:
        --v4;
      }
      while ( v6 != 0 && v5 < length );
    }
    return (char *)m_LessFunc - (char *)a2;
  }
}
