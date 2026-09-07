// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-mb.c
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041BB60
// Name: _my_strnncoll_mb_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_mb_bin(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s,
        unsigned int slen,
        const LoggingContext_t *t,
        unsigned int tlen,
        char t_is_prefix)
{
  unsigned int v6; // edi
  unsigned int v9; // esi
  int v10; // eax
  int result; // eax
  unsigned int v12; // eax

  v6 = tlen;
  if ( slen < tlen )
    v6 = slen;
  v9 = v6;
  if ( v6 < 4 )
  {
LABEL_6:
    if ( v9 == 0 )
      goto LABEL_15;
  }
  else
  {
    while ( s->m_ChannelID == t->m_ChannelID )
    {
      v9 -= 4;
      t = (const LoggingContext_t *)((char *)t + 4);
      s = (const LoggingContext_t *)((char *)s + 4);
      if ( v9 < 4 )
        goto LABEL_6;
    }
  }
  v10 = LOBYTE(s->m_ChannelID) - LOBYTE(t->m_ChannelID);
  if ( v10 != 0 )
    goto LABEL_14;
  if ( v9 <= 1 )
    goto LABEL_15;
  v10 = BYTE1(s->m_ChannelID) - BYTE1(t->m_ChannelID);
  if ( v10 != 0 )
    goto LABEL_14;
  if ( v9 <= 2 )
    goto LABEL_15;
  v10 = BYTE2(s->m_ChannelID) - BYTE2(t->m_ChannelID);
  if ( v10 != 0 )
  {
LABEL_14:
    result = (v10 >> 31) | 1;
    goto LABEL_16;
  }
  if ( v9 > 3 )
  {
    v10 = HIBYTE(s->m_ChannelID) - HIBYTE(t->m_ChannelID);
    goto LABEL_14;
  }
LABEL_15:
  result = 0;
LABEL_16:
  if ( result == 0 )
  {
    v12 = v6;
    if ( t_is_prefix == 0 )
      v12 = slen;
    return v12 - tlen;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BC20
// Name: _my_strcasecmp_mb_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strcasecmp_mb_bin(LIST_ENTRY32 *a1, const char *s, const char *t)
{
  return strcmp(s, t);
}

//------------------------------------------------------------------------------
// Address: 0x00433D00
// Name: _my_caseup_str_mb
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl my_caseup_str_mb(_DWORD *a1, _BYTE *a2)
{
  _BYTE *v2; // esi
  int v3; // ebx
  int v4; // eax

  v2 = a2;
  v3 = a1[10];
  while ( *v2 != 0 )
  {
    v4 = (*(int (__cdecl **)(_DWORD *, _BYTE *, _BYTE *))(a1[25] + 4))(a1, a2: v2, a3: &v2[a1[22]]);
    if ( v4 != 0 )
    {
      v2 += v4;
    }
    else
    {
      *v2 = *(_BYTE *)((unsigned __int8)*v2 + v3);
      ++v2;
    }
  }
  return (_BYTE *)(v2 - a2);
}

//------------------------------------------------------------------------------
// Address: 0x00433D50
// Name: _my_casedn_str_mb
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl my_casedn_str_mb(_DWORD *a1, _BYTE *a2)
{
  _BYTE *v2; // esi
  int v3; // ebx
  int v4; // eax

  v2 = a2;
  v3 = a1[9];
  while ( *v2 != 0 )
  {
    v4 = (*(int (__cdecl **)(_DWORD *, _BYTE *, _BYTE *))(a1[25] + 4))(a1, a2: v2, a3: &v2[a1[22]]);
    if ( v4 != 0 )
    {
      v2 += v4;
    }
    else
    {
      *v2 = *(_BYTE *)((unsigned __int8)*v2 + v3);
      ++v2;
    }
  }
  return (_BYTE *)(v2 - a2);
}

//------------------------------------------------------------------------------
// Address: 0x00433DA0
// Name: _my_caseup_mb
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_caseup_mb(LIST_ENTRY32 *cs, _iobuf *src, unsigned int srclen)
{
  unsigned int result; // eax
  unsigned int Flink; // ebp
  _iobuf *v5; // esi
  _iobuf *v6; // edi
  int v7; // eax

  result = srclen;
  Flink = cs[5].Flink;
  v5 = src;
  v6 = (_iobuf *)((char *)src + srclen);
  if ( src < (_iobuf *)((char *)src + srclen) )
  {
    do
    {
      v7 = (*(int (__cdecl **)(LIST_ENTRY32 *, _iobuf *, _iobuf *))(cs[12].Blink + 4))(a1: cs, a2: v5, a3: v6);
      if ( v7 != 0 )
      {
        v5 = (_iobuf *)((char *)v5 + v7);
      }
      else
      {
        LOBYTE(v5->_ptr) = *(_BYTE *)(LOBYTE(v5->_ptr) + Flink);
        v5 = (_iobuf *)((char *)v5 + 1);
      }
    }
    while ( v5 < v6 );
    return srclen;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433DF0
// Name: _my_casedn_mb
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_casedn_mb(LIST_ENTRY32 *cs, _iobuf *src, unsigned int srclen)
{
  unsigned int result; // eax
  unsigned int Blink; // ebp
  _iobuf *v5; // esi
  _iobuf *v6; // edi
  int v7; // eax

  result = srclen;
  Blink = cs[4].Blink;
  v5 = src;
  v6 = (_iobuf *)((char *)src + srclen);
  if ( src < (_iobuf *)((char *)src + srclen) )
  {
    do
    {
      v7 = (*(int (__cdecl **)(LIST_ENTRY32 *, _iobuf *, _iobuf *))(cs[12].Blink + 4))(a1: cs, a2: v5, a3: v6);
      if ( v7 != 0 )
      {
        v5 = (_iobuf *)((char *)v5 + v7);
      }
      else
      {
        LOBYTE(v5->_ptr) = *(_BYTE *)(LOBYTE(v5->_ptr) + Blink);
        v5 = (_iobuf *)((char *)v5 + 1);
      }
    }
    while ( v5 < v6 );
    return srclen;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433E40
// Name: _my_strcasecmp_mb
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl my_strcasecmp_mb(LIST_ENTRY32 *a1, unsigned __int8 *s, char *t)
{
  unsigned int Flink; // ebx
  unsigned __int8 *v4; // esi
  int v6; // eax
  unsigned __int8 v7; // cl
  char v8; // dl
  int v9; // eax
  char v10; // dl

  Flink = a1[5].Flink;
  v4 = s;
  if ( *s != 0 )
  {
    while ( *t != 0 )
    {
      v6 = (*(int (__cdecl **)(LIST_ENTRY32 *, unsigned __int8 *, unsigned __int8 *))(a1[12].Blink + 4))(
             a1,
             a2: v4,
             a3: &v4[a1[11].Flink]);
      if ( v6 != 0 )
      {
        while ( 1 )
        {
          v7 = *v4;
          v8 = *t;
          --v6;
          ++t;
          ++v4;
          if ( v7 != v8 )
            return true;
          if ( v6 == 0 )
            goto LABEL_9;
        }
      }
      if ( (unsigned int)(*(int (__cdecl **)(LIST_ENTRY32 *, _DWORD))(a1[12].Blink + 8))(a1, a2: *t) > 1 )
        return true;
      v9 = *v4;
      v10 = *(_BYTE *)((unsigned __int8)*t++ + Flink);
      ++v4;
      if ( *(_BYTE *)(v9 + Flink) != v10 )
        return true;
LABEL_9:
      if ( *v4 == 0 )
        return *t != (char)*v4;
    }
  }
  return *t != (char)*v4;
}

//------------------------------------------------------------------------------
// Address: 0x00433ED0
// Name: _my_wildcmp_mb
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_wildcmp_mb(int a1, unsigned __int8 *a2, unsigned int a3, char *a4, char *a5, int a6, int a7, int a8)
{
  char *v8; // ebp
  unsigned int v10; // edi
  int i; // eax
  unsigned int v12; // edi
  unsigned int v13; // ecx
  char *v14; // edx
  int v15; // eax
  int v16; // ecx
  char v17; // dl
  int v18; // eax
  bool v19; // zf
  int result; // eax
  char *v21; // ecx
  char *v22; // ebp
  int v23; // eax
  int v24; // eax
  unsigned __int8 *v25; // eax
  int v26; // eax
  char *v27; // ebp
  unsigned int v28; // eax
  char *v29; // ecx
  unsigned __int8 *v30; // edi
  int v31; // [esp+10h] [ebp-8h]
  unsigned int v32; // [esp+10h] [ebp-8h]
  char *v33; // [esp+14h] [ebp-4h]
  unsigned __int8 *v34; // [esp+28h] [ebp+10h]
  unsigned __int8 v35; // [esp+28h] [ebp+10h]
  char v36; // [esp+28h] [ebp+10h]

  v8 = a4;
  v10 = a3;
  v31 = -1;
  while ( v8 != a5 )
  {
    for ( i = *v8; i != a8; v31 = 1 )
    {
      if ( i == a7 )
        break;
      if ( i == a6 && v8 + 1 != a5 )
        ++v8;
      v12 = (*(int (__cdecl **)(int, char *, char *))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v8, a3: a5);
      if ( v12 != 0 )
      {
        v34 = &a2[v12];
        if ( (unsigned int)&a2[v12] > a3 )
          return 1;
        v13 = v12;
        v14 = v8;
        if ( v12 >= 4 )
        {
          while ( *(_DWORD *)a2 == *(_DWORD *)v14 )
          {
            v13 -= 4;
            v14 += 4;
            a2 += 4;
            if ( v13 < 4 )
              goto LABEL_12;
          }
          return 1;
        }
LABEL_12:
        if ( v13 != 0 && (*v14 != *a2 || v13 > 1 && (v14[1] != a2[1] || v13 > 2 && v14[2] != a2[2])) )
          return 1;
        a2 = v34;
        v8 += v12;
      }
      else
      {
        if ( a2 == (unsigned __int8 *)a3 )
          return 1;
        v15 = *(_DWORD *)(a1 + 44);
        v16 = (unsigned __int8)*v8;
        v17 = *(_BYTE *)(*a2++ + v15);
        ++v8;
        if ( *(_BYTE *)(v16 + v15) != v17 )
          return 1;
      }
      if ( v8 == a5 )
        return a2 != (unsigned __int8 *)a3;
      i = *v8;
      v10 = a3;
    }
    if ( *v8 == a7 )
    {
      while ( 1 )
      {
        if ( a2 == (unsigned __int8 *)v10 )
          return v31;
        v18 = (*(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2, a3: v10) != 0
            ? (*(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2, a3: v10)
            : 1;
        ++v8;
        a2 += v18;
        v19 = v8 == a5;
        if ( v8 >= a5 )
          break;
        if ( *v8 != a7 )
        {
          v19 = v8 == a5;
          break;
        }
      }
      if ( v19 )
        break;
    }
    if ( *v8 == a8 )
    {
      v21 = a5;
      v22 = v8 + 1;
      if ( v22 == a5 )
        return 0;
      while ( 1 )
      {
        v23 = *v22;
        if ( v23 != a8 )
        {
          if ( v23 != a7 )
          {
            if ( v22 == v21 )
              return 0;
            if ( a2 == (unsigned __int8 *)v10 )
              return -1;
            v35 = *v22;
            if ( (unsigned __int8)*v22 == a6 )
            {
              v25 = (unsigned __int8 *)(v22 + 1);
              if ( v22 + 1 != v21 )
              {
                ++v22;
                v35 = *v25;
              }
            }
            v33 = v22;
            v32 = (*(int (__cdecl **)(int, char *, char *))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v22, a3: a5);
            if ( (*(int (__cdecl **)(int, char *, char *))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v22, a3: a5) != 0 )
              v26 = (*(int (__cdecl **)(int, char *, char *))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v22, a3: a5);
            else
              v26 = 1;
            v27 = &v22[v26];
            v36 = *(_BYTE *)(v35 + *(_DWORD *)(a1 + 44));
            while ( 1 )
            {
              if ( (unsigned int)a2 >= v10 )
                return -1;
              if ( v32 != 0 )
              {
                if ( (unsigned int)&a2[v32] > v10 )
                  goto LABEL_75;
                v28 = v32;
                v29 = v33;
                v30 = a2;
                if ( v32 >= 4 )
                {
                  while ( *(_DWORD *)v30 == *(_DWORD *)v29 )
                  {
                    v28 -= 4;
                    v29 += 4;
                    v30 += 4;
                    if ( v28 < 4 )
                      goto LABEL_66;
                  }
LABEL_75:
                  v10 = a3;
                  if ( (*(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(
                         a1,
                         a2,
                         a3) != 0 )
                    a2 += (*(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(
                            a1,
                            a2,
                            a3);
                  else
                    ++a2;
                  continue;
                }
LABEL_66:
                if ( v28 != 0 && (*v29 != *v30 || v28 > 1 && (v29[1] != v30[1] || v28 > 2 && v29[2] != v30[2])) )
                  goto LABEL_75;
                a2 += v32;
                v10 = a3;
              }
              else
              {
                if ( (*(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(
                       a1,
                       a2,
                       a3: v10) != 0
                  || *(_BYTE *)(*a2 + *(_DWORD *)(a1 + 44)) != v36 )
                {
                  goto LABEL_75;
                }
                ++a2;
              }
              result = my_wildcmp_mb(a1, a2, a3: v10, a4: v27, a5, a6, a7, a8);
              if ( result <= 0 )
                return result;
              if ( a2 == (unsigned __int8 *)v10 )
                return -1;
              if ( *v27 == a8 )
                return -1;
            }
          }
          if ( a2 == (unsigned __int8 *)v10 )
            return -1;
          if ( (*(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2, a3: v10) != 0 )
            v24 = (*(int (__cdecl **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(
                    a1,
                    a2,
                    a3: v10);
          else
            v24 = 1;
          v21 = a5;
          a2 += v24;
        }
        if ( ++v22 == v21 )
          return 0;
      }
    }
  }
  return a2 != (unsigned __int8 *)v10;
}

//------------------------------------------------------------------------------
// Address: 0x004342A0
// Name: _my_numchars_mb
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_numchars_mb(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // esi
  int i; // ebp
  int v5; // eax

  v3 = a2;
  for ( i = 0; v3 < a3; ++i )
  {
    v5 = (*(int (__cdecl **)(int, unsigned int, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v3, a3);
    if ( v5 == 0 )
      v5 = 1;
    v3 += v5;
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x004342E0
// Name: _my_charpos_mb
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_charpos_mb(int a1, unsigned int a2, unsigned int a3, int a4)
{
  int v4; // ebp
  unsigned int v5; // esi
  int v6; // eax

  v4 = a4;
  v5 = a2;
  if ( a4 == 0 )
    return v5 - a2;
  while ( v5 < a3 )
  {
    v6 = (*(int (__cdecl **)(int, unsigned int, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v5, a3);
    if ( v6 == 0 )
      v6 = 1;
    v5 += v6;
    if ( --v4 == 0 )
      return v5 - a2;
  }
  if ( v4 != 0 )
    return a3 - a2 + 2;
  else
    return v5 - a2;
}

//------------------------------------------------------------------------------
// Address: 0x00434340
// Name: _my_well_formed_len_mb
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_mb(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, ...)
{
  unsigned int v3; // ebp
  const char *v4; // esi
  int v5; // eax
  unsigned int wc; // [esp+18h] [ebp+10h] BYREF
  va_list wca; // [esp+18h] [ebp+10h]
  int *error; // [esp+1Ch] [ebp+14h]
  va_list va1; // [esp+20h] [ebp+18h] BYREF

  va_start(va1, e);
  va_start(wca, e);
  wc = va_arg(va1, _DWORD);
  error = va_arg(va1, int *);
  v3 = wc;
  v4 = b;
  *error = 0;
  if ( v3 != 0 )
  {
    while ( 1 )
    {
      v5 = (*(int (__cdecl **)(LIST_ENTRY32 *, unsigned int *, const char *, tagShutdownType))(cs[12].Blink + 32))(
             a1: cs,
             a2: (unsigned int *)wca,
             a3: v4,
             a4: e);
      if ( v5 <= 0 )
        break;
      v4 += v5;
      if ( --v3 == 0 )
        return v4 - b;
    }
    *error = (unsigned int)v4 < e;
  }
  return v4 - b;
}

//------------------------------------------------------------------------------
// Address: 0x004343B0
// Name: _my_instr_mb
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_instr_mb(int a1, unsigned int a2, unsigned int a3, int a4, unsigned int a5, _DWORD *a6, unsigned int a7)
{
  unsigned int v8; // esi
  unsigned int v9; // ebx
  int v10; // eax
  unsigned int v11; // esi
  int v12; // [esp+10h] [ebp-4h]

  v12 = 0;
  if ( a5 > a3 )
    return 0;
  if ( a5 == 0 )
  {
    if ( a7 != 0 )
    {
      *a6 = 0;
      a6[1] = 0;
      a6[2] = 0;
    }
    return 1;
  }
  v8 = a2;
  v9 = a2 - a5 + a3 + 1;
  if ( a2 >= v9 )
    return 0;
  while ( (*(int (__cdecl **)(int, unsigned int, unsigned int, int, unsigned int, _DWORD))(*(_DWORD *)(a1 + 104) + 4))(
            a1,
            a2: v8,
            a3: a5,
            a4,
            a5,
            a6: 0) != 0 )
  {
    v10 = (*(int (__cdecl **)(int, unsigned int, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v8, a3: v9);
    if ( v10 == 0 )
      v10 = 1;
    ++v12;
    v8 += v10;
    if ( v8 >= v9 )
      return 0;
  }
  if ( a7 != 0 )
  {
    v11 = v8 - a2;
    *a6 = 0;
    a6[1] = v11;
    a6[2] = v12;
    if ( a7 > 1 )
    {
      a6[3] = v11;
      a6[4] = a5 + v11;
      a6[5] = 0;
    }
  }
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00434490
// Name: _my_strnncollsp_mb_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_mb_bin(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *a,
        unsigned int length,
        const LoggingContext_t *b,
        unsigned int b_length)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  const LoggingContext_t *v7; // eax
  const LoggingContext_t *v9; // ebp
  char m_ChannelID; // dl
  char v11; // bl
  int v12; // edx
  const LoggingContext_t *v13; // ecx

  v5 = length;
  if ( length >= b_length )
  {
    v6 = b_length;
    length = b_length;
  }
  else
  {
    v6 = length;
  }
  v7 = a;
  v9 = (const LoggingContext_t *)((char *)a + v6);
  if ( a >= (const LoggingContext_t *)((char *)a + v6) )
  {
LABEL_8:
    if ( v5 == b_length )
      return 0;
    v12 = 1;
    if ( v5 < b_length )
    {
      v5 = b_length;
      v7 = b;
      v12 = -1;
    }
    v13 = (const LoggingContext_t *)((char *)v7 + v5 - v6);
    if ( v7 >= v13 )
    {
      return 0;
    }
    else
    {
      while ( LOBYTE(v7->m_ChannelID) == 32 )
      {
        v7 = (const LoggingContext_t *)((char *)v7 + 1);
        if ( v7 >= v13 )
          return 0;
      }
      if ( LOBYTE(v7->m_ChannelID) < 0x20u )
        return -v12;
      return v12;
    }
  }
  else
  {
    while ( 1 )
    {
      m_ChannelID = v7->m_ChannelID;
      v11 = b->m_ChannelID;
      b = (const LoggingContext_t *)((char *)b + 1);
      v7 = (const LoggingContext_t *)((char *)v7 + 1);
      if ( m_ChannelID != v11 )
        return v7[-1].m_Color._color[3] - b[-1].m_Color._color[3];
      if ( v7 >= v9 )
      {
        v6 = length;
        goto LABEL_8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434520
// Name: _my_strnxfrm_mb
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnxfrm_mb(
        int a1,
        unsigned __int8 *dst,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 *src,
        unsigned int a6,
        unsigned int flags)
{
  int v8; // ebx
  int v9; // edx
  unsigned __int8 *v10; // esi
  unsigned __int8 *v11; // edi
  unsigned __int8 *v12; // ebp
  unsigned __int8 v13; // dl
  int v14; // eax
  unsigned int v15; // ebx
  unsigned __int8 v16; // al
  unsigned __int8 *str; // [esp+10h] [ebp-4h]
  unsigned __int8 *dsta; // [esp+1Ch] [ebp+8h]
  int v20; // [esp+20h] [ebp+Ch]

  v8 = a1;
  v9 = *(_DWORD *)(a1 + 44);
  v10 = src;
  v11 = dst;
  dsta = &dst[a3];
  str = v11;
  v12 = &src[a6];
  v20 = v9;
  if ( a3 < a6 || a4 < a6 )
  {
    if ( src < v12 )
    {
      do
      {
        if ( a4 == 0 || v11 >= dsta )
          break;
        if ( *v10 >= 0x80u
          && (v14 = (*(int (__cdecl **)(int, unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)(v8 + 100) + 4))(
                      a1: v8,
                      a2: v10,
                      a3: v12)) != 0 )
        {
          v15 = &v11[v14] > dsta ? dsta - v11 : v14;
          memcpy(dst: v11, src: v10, count: v15);
          v11 += v15;
          v10 += v15;
          v8 = a1;
        }
        else
        {
          v16 = v20 != 0 ? *(_BYTE *)(*v10 + v20) : *v10;
          ++v10;
          *v11++ = v16;
        }
        --a4;
      }
      while ( v10 < v12 );
    }
  }
  else if ( v9 != 0 )
  {
    if ( src < v12 )
    {
      while ( 1 )
      {
        if ( *v10 >= 0x80u )
        {
          switch ( (*(int (__cdecl **)(int, unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)(a1 + 100) + 4))(
                     a1,
                     a2: v10,
                     a3: v12) )
          {
            case 0:
              goto LABEL_13;
            case 2:
              goto LABEL_12;
            case 3:
              goto LABEL_11;
            case 4:
              *v11++ = *v10++;
LABEL_11:
              *v11++ = *v10++;
LABEL_12:
              *v11++ = *v10++;
LABEL_13:
              v13 = *v10;
              goto LABEL_14;
            default:
              goto LABEL_15;
          }
        }
        v13 = *(_BYTE *)(*v10 + v9);
LABEL_14:
        *v11++ = v13;
        ++v10;
LABEL_15:
        --a4;
        if ( v10 >= v12 )
          break;
        v9 = v20;
      }
    }
  }
  else if ( src < v12 )
  {
    do
    {
      if ( *v10 >= 0x80u )
      {
        switch ( (*(int (__cdecl **)(int, unsigned __int8 *, unsigned __int8 *))(*(_DWORD *)(a1 + 100) + 4))(
                   a1,
                   a2: v10,
                   a3: v12) )
        {
          case 0:
            goto LABEL_24;
          case 2:
            goto LABEL_23;
          case 3:
            goto LABEL_22;
          case 4:
            *v11++ = *v10++;
LABEL_22:
            *v11++ = *v10++;
LABEL_23:
            *v11++ = *v10++;
LABEL_24:
            *v11 = *v10;
            goto LABEL_25;
          default:
            goto LABEL_26;
        }
      }
      *v11 = *v10;
LABEL_25:
      ++v11;
      ++v10;
LABEL_26:
      --a4;
    }
    while ( v10 < v12 );
  }
  return my_strxfrm_pad_desc_and_reverse(a1: v8, str, strend: v11, a4: (unsigned int)dsta, a5: a4, flags, level: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004346E0
// Name: pad_max_char
// Source: json
//------------------------------------------------------------------------------
void __fastcall pad_max_char(unsigned __int8 *dst, unsigned int a2, int a3)
{
  unsigned __int8 *v3; // esi
  unsigned int v5; // ebp
  unsigned __int8 src[10]; // [esp+8h] [ebp-10h] BYREF
  _BYTE v7[2]; // [esp+12h] [ebp-6h] BYREF

  v3 = dst;
  if ( *(char *)(a3 + 12) < 0 )
  {
    v5 = (*(char (__cdecl **)(int, _DWORD, unsigned __int8 *, _BYTE *))(*(_DWORD *)(a3 + 100) + 36))(
           a1: a3,
           a2: *(unsigned __int16 *)(a3 + 94),
           a3: src,
           a4: v7);
    do
    {
      if ( (unsigned int)&v3[v5] >= a2 )
      {
        *v3++ = 32;
      }
      else
      {
        memcpy(dst: v3, src, count: v5);
        v3 += v5;
      }
    }
    while ( (unsigned int)v3 < a2 );
  }
  else
  {
    memset(dst, value: 0xFFu, count: a2 - (_DWORD)dst);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00434780
// Name: _my_like_range_mb
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_mb(
        LIST_ENTRY32 *a1,
        unsigned int maxcharlen,
        char *min_end,
        int escape,
        int w_one,
        int w_many,
        unsigned int res_length,
        tagShutdownType contraction_flags,
        char *max_str,
        unsigned int *min_length,
        unsigned int *max_length)
{
  unsigned __int8 *v11; // ebx
  char *v12; // esi
  char *v13; // edi
  char *v14; // ebp
  unsigned int Flink; // eax
  int v16; // eax
  unsigned int v17; // eax
  unsigned __int8 v18; // cl
  signed __int8 v19; // al
  char v20; // cl
  char v21; // al
  unsigned int v23; // eax
  tagShutdownType end; // [esp+10h] [ebp-Ch]
  unsigned int maxcharlena; // [esp+24h] [ebp+8h]
  char *min_enda; // [esp+28h] [ebp+Ch]
  tagShutdownType contraction_flagsa; // [esp+3Ch] [ebp+20h]

  v11 = (unsigned __int8 *)max_str;
  v12 = (char *)contraction_flags;
  v13 = (char *)maxcharlen;
  v14 = &min_end[maxcharlen];
  min_enda = (char *)(res_length + contraction_flags);
  end = (tagShutdownType)v14;
  maxcharlena = res_length / a1[11].Flink;
  Flink = a1[6].Flink;
  if ( Flink != 0 )
    contraction_flagsa = Flink + 4096;
  else
    contraction_flagsa = IdleShutdown;
  if ( v13 != v14 )
  {
    while ( v12 != min_enda && maxcharlena != 0 )
    {
      v16 = *v13;
      if ( v16 != escape || v13 + 1 == v14 )
      {
        if ( v16 == w_one || v16 == w_many )
        {
fill_max_and_min_0:
          if ( (a1[1].Blink & 0x10) != 0 )
            v23 = (unsigned int)&v12[-contraction_flags];
          else
            v23 = res_length;
          *min_length = v23;
          *max_length = res_length;
          do
            *v12++ = a1[11].Blink;
          while ( v12 != min_enda );
          *max_length = res_length;
          pad_max_char(dst: v11, a2: (unsigned int)&max_str[res_length], a3: (int)a1);
          return 0;
        }
      }
      else
      {
        ++v13;
      }
      v17 = (*(int (__cdecl **)(LIST_ENTRY32 *, char *, char *))(a1[12].Blink + 4))(a1, a2: v13, a3: v14);
      if ( v17 <= 1 )
      {
        if ( contraction_flagsa != IdleShutdown && v13 + 1 < v14 )
        {
          v19 = *v13;
          if ( *(_BYTE *)(contraction_flagsa + (unsigned __int8)*v13) != 0 )
          {
            v20 = v13[1];
            if ( v20 == w_one || v20 == w_many )
              goto fill_max_and_min_0;
            if ( *(_BYTE *)((unsigned __int8)v20 + contraction_flagsa) != 0
              && *(_WORD *)(a1[6].Flink + 2 * (v20 + ((v19 - 65) << 6))) != 0 )
            {
              if ( maxcharlena == 1 || v12 + 1 >= min_enda )
                goto fill_max_and_min_0;
              ++v13;
              *v11 = v19;
              *v12 = v19;
              ++v11;
              --maxcharlena;
              ++v12;
            }
          }
          v14 = (char *)end;
        }
        v21 = *v13;
        *v11 = *v13;
        *v12++ = v21;
        ++v11;
        ++v13;
      }
      else
      {
        if ( &v13[v17] > v14 || &v12[v17] > min_enda )
          break;
        do
        {
          v18 = *v13;
          *v11 = *v13;
          --v17;
          *v12++ = v18;
          ++v11;
          ++v13;
        }
        while ( v17 != 0 );
      }
      --maxcharlena;
      if ( v13 == v14 )
        break;
    }
  }
  *max_length = (unsigned int)&v12[-contraction_flags];
  for ( *min_length = (unsigned int)&v12[-contraction_flags]; v12 != min_enda; ++v11 )
  {
    *v11 = 32;
    *v12++ = 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00434980
// Name: _my_wildcmp_mb_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_wildcmp_mb_bin(int a1, char *a2, unsigned int a3, char *a4, char *a5, int a6, int a7, int a8)
{
  char *v8; // ebp
  unsigned int v10; // edi
  int v11; // ebx
  int i; // eax
  int v13; // eax
  unsigned int v14; // edi
  char *v15; // eax
  unsigned int v16; // ecx
  char *v17; // edx
  char v18; // dl
  char v19; // al
  int v20; // eax
  bool v21; // zf
  int result; // eax
  char *v23; // ecx
  char *v24; // ebp
  int v25; // eax
  int v26; // eax
  unsigned __int8 *v27; // eax
  int v28; // eax
  char *v29; // ebp
  unsigned int v30; // eax
  char *v31; // ecx
  char *v32; // edi
  int v33; // [esp+10h] [ebp-8h]
  unsigned int v34; // [esp+10h] [ebp-8h]
  char *v35; // [esp+14h] [ebp-4h]
  unsigned __int8 v36; // [esp+28h] [ebp+10h]

  v8 = a4;
  v10 = a3;
  v33 = -1;
  if ( a4 != a5 )
  {
    v11 = a1;
    do
    {
      for ( i = *v8; i != a8; v33 = 1 )
      {
        if ( i == a7 )
          break;
        if ( i == a6 && v8 + 1 != a5 )
          ++v8;
        v13 = (*(int (__cdecl **)(int, char *, char *))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2: v8, a3: a5);
        v14 = v13;
        if ( v13 != 0 )
        {
          v15 = &a2[v13];
          if ( (unsigned int)&a2[v14] > a3 )
            return 1;
          v16 = v14;
          v17 = v8;
          if ( v14 >= 4 )
          {
            do
            {
              if ( *(_DWORD *)a2 != *(_DWORD *)v17 )
                return 1;
              v16 -= 4;
              v17 += 4;
              a2 += 4;
            }
            while ( v16 >= 4 );
            v11 = a1;
          }
          if ( v16 != 0 )
          {
            if ( *v17 != *a2 || v16 > 1 && (v17[1] != a2[1] || v16 > 2 && v17[2] != a2[2]) )
              return 1;
            v11 = a1;
          }
          a2 = v15;
          v8 += v14;
        }
        else
        {
          if ( a2 == (char *)a3 )
            return 1;
          v18 = *v8;
          v19 = *a2++;
          ++v8;
          if ( v18 != v19 )
            return 1;
        }
        if ( v8 == a5 )
          return a2 != (char *)a3;
        i = *v8;
        v10 = a3;
      }
      if ( *v8 == a7 )
      {
        while ( 1 )
        {
          if ( a2 == (char *)v10 )
            return v33;
          v20 = (*(int (__cdecl **)(int, char *, unsigned int))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2, a3: v10) != 0
              ? (*(int (__cdecl **)(int, char *, unsigned int))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2, a3: v10)
              : 1;
          ++v8;
          a2 += v20;
          v21 = v8 == a5;
          if ( v8 >= a5 )
            break;
          if ( *v8 != a7 )
          {
            v21 = v8 == a5;
            break;
          }
        }
        if ( v21 )
          break;
      }
      if ( *v8 == a8 )
      {
        v23 = a5;
        v24 = v8 + 1;
        if ( v24 == a5 )
          return 0;
        while ( 1 )
        {
          v25 = *v24;
          if ( v25 != a8 )
          {
            if ( v25 != a7 )
            {
              if ( v24 == v23 )
                return 0;
              if ( a2 == (char *)v10 )
                return -1;
              v36 = *v24;
              if ( (unsigned __int8)*v24 == a6 )
              {
                v27 = (unsigned __int8 *)(v24 + 1);
                if ( v24 + 1 != v23 )
                {
                  ++v24;
                  v36 = *v27;
                }
              }
              v35 = v24;
              v34 = (*(int (__cdecl **)(int, char *, char *))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2: v24, a3: a5);
              if ( (*(int (__cdecl **)(int, char *, char *))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2: v24, a3: a5) != 0 )
                v28 = (*(int (__cdecl **)(int, char *, char *))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2: v24, a3: a5);
              else
                v28 = 1;
              v29 = &v24[v28];
              while ( 1 )
              {
                if ( (unsigned int)a2 >= v10 )
                  return -1;
                if ( v34 != 0 )
                {
                  if ( (unsigned int)&a2[v34] > v10 )
                    goto LABEL_78;
                  v30 = v34;
                  v31 = v35;
                  v32 = a2;
                  if ( v34 >= 4 )
                  {
                    while ( *(_DWORD *)v32 == *(_DWORD *)v31 )
                    {
                      v30 -= 4;
                      v31 += 4;
                      v32 += 4;
                      if ( v30 < 4 )
                        goto LABEL_69;
                    }
LABEL_78:
                    v10 = a3;
                    if ( (*(int (__cdecl **)(int, char *, unsigned int))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2, a3) != 0 )
                      a2 += (*(int (__cdecl **)(int, char *, unsigned int))(*(_DWORD *)(v11 + 100) + 4))(
                              a1: v11,
                              a2,
                              a3);
                    else
                      ++a2;
                    continue;
                  }
LABEL_69:
                  if ( v30 != 0 && (*v31 != *v32 || v30 > 1 && (v31[1] != v32[1] || v30 > 2 && v31[2] != v32[2])) )
                    goto LABEL_78;
                  a2 += v34;
                  v10 = a3;
                }
                else
                {
                  if ( (*(int (__cdecl **)(int, char *, unsigned int))(*(_DWORD *)(v11 + 100) + 4))(
                         a1: v11,
                         a2,
                         a3: v10) != 0
                    || *a2 != v36 )
                  {
                    goto LABEL_78;
                  }
                  ++a2;
                }
                result = my_wildcmp_mb_bin(a1: v11, a2, a3: v10, a4: v29, a5, a6, a7, a8);
                if ( result <= 0 )
                  return result;
                if ( a2 == (char *)v10 )
                  return -1;
                if ( *v29 == a8 )
                  return -1;
              }
            }
            if ( a2 == (char *)v10 )
              return -1;
            if ( (*(int (__cdecl **)(int, char *, unsigned int))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2, a3: v10) != 0 )
              v26 = (*(int (__cdecl **)(int, char *, unsigned int))(*(_DWORD *)(v11 + 100) + 4))(a1: v11, a2, a3: v10);
            else
              v26 = 1;
            v23 = a5;
            a2 += v26;
          }
          if ( ++v24 == v23 )
            return 0;
        }
      }
    }
    while ( v8 != a5 );
  }
  return a2 != (char *)v10;
}

//------------------------------------------------------------------------------
// Address: 0x00434D40
// Name: _my_numcells_mb
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_numcells_mb(int a1, unsigned int a2, unsigned int a3)
{
  unsigned int v3; // ebx
  unsigned int v4; // esi
  int v5; // ebp
  int v6; // eax
  int v7; // edx
  int v8; // eax

  v3 = a3;
  v4 = a2;
  v5 = 0;
  while ( v4 < v3 )
  {
    v6 = (*(int (__cdecl **)(int, unsigned int *, unsigned int, unsigned int))(*(_DWORD *)(a1 + 100) + 32))(
           a1,
           &a2,
           a3: v4,
           a4: v3);
    if ( v6 <= 0 || a2 > 0xFFFF )
    {
      ++v4;
    }
    else
    {
      v4 += v6;
      v7 = dword_4D0E4C[2 * BYTE1(a2)];
      if ( v7 != 0 )
        v8 = *(char *)((unsigned __int8)a2 + v7);
      else
        v8 = *((_DWORD *)utr11_data + 2 * BYTE1(a2));
      v5 += v8 + 1;
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00434DC0
// Name: _my_mb_ctype_mb
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_ctype_mb(unsigned int wc, int *ctype, const LoggingContext_t *s, const LoggingContext_t *e)
{
  int result; // eax
  unsigned int v5; // ecx
  int v6; // esi
  int v7; // ecx

  result = (*(int (__cdecl **)(unsigned int, unsigned int *, const LoggingContext_t *, const LoggingContext_t *))(*(_DWORD *)(wc + 100) + 32))(
             a1: wc,
             a2: &wc,
             a3: s,
             a4: e);
  if ( result <= 0 || wc > 0xFFFF )
  {
    *ctype = 0;
  }
  else
  {
    v5 = 8 * (wc >> 8);
    v6 = *(int *)((char *)&off_4C422C + v5);
    if ( v6 != 0 )
      v7 = *(unsigned __int8 *)((unsigned __int8)wc + v6);
    else
      v7 = (unsigned __int8)my_uni_ctype[v5];
    *ctype = v7;
  }
  return result;
}
