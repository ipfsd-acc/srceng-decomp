// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-simple.c
// Functions: 40
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041A0E0
// Name: _my_strnxfrmlen_simple
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strnxfrmlen_simple(LIST_ENTRY32 *cs, unsigned int len)
{
  int Blink; // eax

  Blink = cs[9].Blink;
  if ( Blink == 0 )
    Blink = 1;
  return len * Blink;
}

//------------------------------------------------------------------------------
// Address: 0x0041A100
// Name: _my_strnncoll_simple
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_simple(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *s,
        unsigned int slen,
        const LoggingContext_t *t,
        unsigned int tlen,
        char t_is_prefix)
{
  unsigned int v6; // eax
  unsigned int v7; // ebp
  unsigned int v8; // edi
  int Blink; // ecx
  int m_ChannelID_low; // eax
  char v13; // bl

  v6 = tlen;
  v7 = slen;
  v8 = tlen;
  if ( slen <= tlen )
    v8 = slen;
  Blink = cs[5].Blink;
  if ( t_is_prefix != 0 && slen > tlen )
    v7 = tlen;
  if ( v8 != 0 )
  {
    while ( 1 )
    {
      m_ChannelID_low = LOBYTE(s->m_ChannelID);
      v13 = *(_BYTE *)(LOBYTE(t->m_ChannelID) + Blink);
      --v8;
      t = (const LoggingContext_t *)((char *)t + 1);
      s = (const LoggingContext_t *)((char *)s + 1);
      if ( *(_BYTE *)(m_ChannelID_low + Blink) != v13 )
        return *(unsigned __int8 *)(s[-1].m_Color._color[3] + Blink)
             - *(unsigned __int8 *)(t[-1].m_Color._color[3] + Blink);
      if ( v8 == 0 )
      {
        v6 = tlen;
        goto LABEL_10;
      }
    }
  }
  else
  {
LABEL_10:
    if ( v7 <= v6 )
      return -(v7 < v6);
    else
      return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A180
// Name: _my_strnncollsp_simple
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_simple(
        int *cs,
        const LoggingContext_t *a,
        unsigned int a_length,
        const LoggingContext_t *b,
        unsigned int b_length)
{
  unsigned int v5; // edx
  int v6; // esi
  unsigned int v7; // edi
  unsigned int v8; // ebx
  const LoggingContext_t *v9; // eax
  const LoggingContext_t *v11; // ebp
  int m_ChannelID_low; // edx
  char v13; // bl
  int v14; // ebp
  unsigned __int8 *v15; // ecx
  unsigned int length; // [esp+14h] [ebp+4h]

  v5 = b_length;
  v6 = cs[11];
  v7 = a_length;
  if ( a_length >= b_length )
  {
    v8 = b_length;
    length = b_length;
  }
  else
  {
    v8 = a_length;
    length = a_length;
  }
  v9 = a;
  v11 = (const LoggingContext_t *)((char *)a + v8);
  if ( a >= (const LoggingContext_t *)((char *)a + v8) )
  {
LABEL_8:
    if ( a_length == v5 )
      return 0;
    v14 = 1;
    if ( a_length < v5 )
    {
      v7 = v5;
      v9 = b;
      v14 = -1;
    }
    v15 = (unsigned __int8 *)v9 + v7 - v8;
    if ( v9 >= (const LoggingContext_t *)v15 )
    {
      return 0;
    }
    else
    {
      while ( *(_BYTE *)(LOBYTE(v9->m_ChannelID) + v6) == 32 )
      {
        v9 = (const LoggingContext_t *)((char *)v9 + 1);
        if ( v9 >= (const LoggingContext_t *)v15 )
          return 0;
      }
      if ( *(_BYTE *)(LOBYTE(v9->m_ChannelID) + v6) < 0x20u )
        return -v14;
      return v14;
    }
  }
  else
  {
    while ( 1 )
    {
      m_ChannelID_low = LOBYTE(v9->m_ChannelID);
      v13 = *(_BYTE *)(LOBYTE(b->m_ChannelID) + v6);
      b = (const LoggingContext_t *)((char *)b + 1);
      v9 = (const LoggingContext_t *)((char *)v9 + 1);
      if ( *(_BYTE *)(m_ChannelID_low + v6) != v13 )
        return *(unsigned __int8 *)(v9[-1].m_Color._color[3] + v6) - *(unsigned __int8 *)(b[-1].m_Color._color[3] + v6);
      if ( v9 >= v11 )
      {
        v5 = b_length;
        v8 = length;
        goto LABEL_8;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041A230
// Name: _my_caseup_str_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_caseup_str_8bit(int a1, _BYTE *a2)
{
  int v2; // edx
  _BYTE *v3; // eax
  char v4; // cl
  char v5; // cl

  v2 = *(_DWORD *)(a1 + 40);
  v3 = a2;
  v4 = *(_BYTE *)((unsigned __int8)*a2 + v2);
  *a2 = v4;
  if ( v4 != 0 )
  {
    do
    {
      v5 = *(_BYTE *)((unsigned __int8)*++v3 + v2);
      *v3 = v5;
    }
    while ( v5 != 0 );
  }
  return v3 - a2;
}

//------------------------------------------------------------------------------
// Address: 0x0041A270
// Name: _my_casedn_str_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_casedn_str_8bit(int a1, _BYTE *a2)
{
  int v2; // edx
  _BYTE *v3; // eax
  char v4; // cl
  char v5; // cl

  v2 = *(_DWORD *)(a1 + 36);
  v3 = a2;
  v4 = *(_BYTE *)((unsigned __int8)*a2 + v2);
  *a2 = v4;
  if ( v4 != 0 )
  {
    do
    {
      v5 = *(_BYTE *)((unsigned __int8)*++v3 + v2);
      *v3 = v5;
    }
    while ( v5 != 0 );
  }
  return v3 - a2;
}

//------------------------------------------------------------------------------
// Address: 0x0041A2B0
// Name: _my_caseup_8bit
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_caseup_8bit(LIST_ENTRY32 *cs, _iobuf *src, unsigned int srclen)
{
  _iobuf *v3; // ecx
  unsigned int i; // esi

  v3 = src;
  for ( i = cs[5].Flink; v3 != (_iobuf *)((char *)src + srclen); v3 = (_iobuf *)((char *)v3 + 1) )
    LOBYTE(v3->_ptr) = *(_BYTE *)(LOBYTE(v3->_ptr) + i);
  return srclen;
}

//------------------------------------------------------------------------------
// Address: 0x0041A2E0
// Name: _my_casedn_8bit
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_casedn_8bit(LIST_ENTRY32 *cs, _iobuf *src, unsigned int srclen)
{
  _iobuf *v3; // ecx
  unsigned int i; // esi

  v3 = src;
  for ( i = cs[4].Blink; v3 != (_iobuf *)((char *)src + srclen); v3 = (_iobuf *)((char *)v3 + 1) )
    LOBYTE(v3->_ptr) = *(_BYTE *)(LOBYTE(v3->_ptr) + i);
  return srclen;
}

//------------------------------------------------------------------------------
// Address: 0x0041A310
// Name: _my_strcasecmp_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strcasecmp_8bit(LIST_ENTRY32 *a1, char *s, unsigned __int8 *t)
{
  unsigned int Flink; // ecx
  unsigned __int8 *v4; // esi
  char *v5; // edi
  unsigned __int8 v6; // al

  Flink = a1[5].Flink;
  v4 = t;
  v5 = s;
  v6 = *s;
  if ( *(_BYTE *)((unsigned __int8)*s + Flink) != *(_BYTE *)(*t + Flink) )
    return *(unsigned __int8 *)((unsigned __int8)*v5 + Flink) - *(unsigned __int8 *)(*v4 + Flink);
  while ( 1 )
  {
    ++v4;
    ++v5;
    if ( v6 == 0 )
      break;
    v6 = *v5;
    if ( *(_BYTE *)((unsigned __int8)*v5 + Flink) != *(_BYTE *)(*v4 + Flink) )
      return *(unsigned __int8 *)((unsigned __int8)*v5 + Flink) - *(unsigned __int8 *)(*v4 + Flink);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A370
// Name: _my_mb_wc_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_8bit(int a1, _DWORD *a2, _BYTE *a3, unsigned int a4)
{
  int v5; // eax

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v5 = *(unsigned __int16 *)(*(_DWORD *)(a1 + 56) + 2 * (unsigned __int8)*a3);
  *a2 = v5;
  if ( v5 != 0 || *a3 == 0 )
    return 1;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0041A3B0
// Name: _my_wc_mb_8bit
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_8bit(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *str, unsigned __int8 *end, ...)
{
  unsigned __int16 *Blink; // eax
  char v6; // al

  if ( str >= end )
    return -101;
  Blink = (unsigned __int16 *)cs[7].Blink;
  if ( *((_DWORD *)Blink + 1) == 0 )
    return 0;
  while ( *Blink > (unsigned int)wc || Blink[1] < (unsigned int)wc )
  {
    Blink += 4;
    if ( *((_DWORD *)Blink + 1) == 0 )
      return 0;
  }
  v6 = wc[*((_DWORD *)Blink + 1) - *Blink];
  *str = v6;
  return v6 != 0 || wc == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0041A410
// Name: _my_snprintf_8bit
// Source: json
//------------------------------------------------------------------------------
_EXCEPTION_DISPOSITION my_snprintf_8bit(
        LIST_ENTRY32 *a1,
        char *to,
        _EXCEPTION_REGISTRATION_RECORD *n,
        _CONTEXT *fmt,
        ...)
{
  va_list va; // [esp+14h] [ebp+14h] BYREF

  va_start(va, fmt);
  return my_vsnprintf((_EXCEPTION_RECORD *)to, n, fmt, ap: va);
}

//------------------------------------------------------------------------------
// Address: 0x0041A430
// Name: _my_hash_sort_simple
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_hash_sort_simple(
        unsigned __int8 *sort_order,
        const LoggingContext_t *key,
        unsigned int len,
        unsigned int *nr1,
        unsigned int *nr2)
{
  const LoggingContext_t *v5; // edi
  unsigned int result; // eax
  int v7; // ebx
  unsigned __int8 *sort_ordera; // [esp+8h] [ebp+4h]

  v5 = key;
  sort_ordera = *((unsigned __int8 **)sort_order + 11);
  result = skip_trailing_space();
  if ( (unsigned int)key < result )
  {
    do
    {
      v7 = sort_ordera[LOBYTE(v5->m_ChannelID)];
      v5 = (const LoggingContext_t *)((char *)v5 + 1);
      *nr1 ^= (*nr1 << 8) + (*nr2 + (*nr1 & 0x3F)) * v7;
      *nr2 += 3;
    }
    while ( (unsigned int)v5 < result );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041A490
// Name: _my_strntol_8bit
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strntol_8bit(
        LIST_ENTRY32 *cs,
        tagShutdownType nptr,
        char *l,
        unsigned int base,
        unsigned int *a5,
        int *err)
{
  unsigned int v6; // esi
  char *v7; // edi
  char *v8; // ecx
  unsigned int v9; // esi
  char v10; // bl
  unsigned int v11; // edx
  unsigned __int8 v12; // bl
  bool v14; // cc
  int overflow; // [esp+10h] [ebp-Ch]
  tagShutdownType save; // [esp+18h] [ebp-4h]
  int negative; // [esp+28h] [ebp+Ch]

  v6 = nptr;
  v7 = &l[nptr];
  *err = 0;
  v8 = (char *)nptr;
  if ( nptr < (unsigned int)&l[nptr] )
  {
    do
    {
      if ( (*(_BYTE *)(cs[4].Flink + (unsigned __int8)*v8 + 1) & 8) == 0 )
        break;
      ++v8;
    }
    while ( v8 < v7 );
  }
  if ( v8 == v7 )
    goto noconv;
  if ( *v8 == 45 )
  {
    negative = 1;
LABEL_8:
    ++v8;
    goto LABEL_9;
  }
  negative = 0;
  if ( *v8 == 43 )
    goto LABEL_8;
LABEL_9:
  v9 = 0;
  overflow = 0;
  v10 = *v8;
  save = (tagShutdownType)v8;
  v11 = 0xFFFFFFFF / base;
  if ( v8 != v7 )
  {
    do
    {
      if ( (unsigned __int8)(v10 - 48) > 9u )
      {
        if ( (unsigned __int8)(v10 - 65) > 0x19u )
        {
          if ( (unsigned __int8)(v10 - 97) > 0x19u )
            break;
          v12 = v10 - 87;
        }
        else
        {
          v12 = v10 - 55;
        }
      }
      else
      {
        v12 = v10 - 48;
      }
      if ( v12 >= (int)base )
        break;
      if ( v9 > v11 || v9 == v11 && v12 > 0xFFFFFFFF % base )
        overflow = 1;
      else
        v9 = v12 + base * v9;
      v10 = *++v8;
    }
    while ( v8 != v7 );
    if ( v8 != (char *)save )
    {
      if ( a5 != nullptr )
        *a5 = (unsigned int)v8;
      if ( negative != 0 )
        v14 = v9 <= 0x80000000;
      else
        v14 = v9 <= 0x7FFFFFFF;
      if ( v14 && overflow == 0 )
      {
        if ( negative != 0 )
          return -v9;
        return v9;
      }
      else
      {
        *err = 34;
        return (negative != 0) + 0x7FFFFFFF;
      }
    }
  }
  v6 = nptr;
noconv:
  *err = 33;
  if ( a5 != nullptr )
    *a5 = v6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A5F0
// Name: _my_strntoul_8bit
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_strntoul_8bit(LIST_ENTRY32 *cs, const char *nptr, int l, int base, const char **a5, int *err)
{
  const char *v6; // esi
  const char *v7; // edi
  const char *i; // ecx
  unsigned int v9; // esi
  char v10; // bl
  unsigned int v11; // edx
  unsigned __int8 v12; // bl
  int overflow; // [esp+10h] [ebp-Ch]
  tagShutdownType save; // [esp+18h] [ebp-4h]
  int negative; // [esp+28h] [ebp+Ch]

  v6 = nptr;
  v7 = &nptr[l];
  *err = 0;
  for ( i = nptr; i < v7; ++i )
  {
    if ( (*(_BYTE *)(cs[4].Flink + *(unsigned __int8 *)i + 1) & 8) == 0 )
      break;
  }
  if ( i == v7 )
    goto noconv_0;
  if ( *i == 45 )
  {
    negative = 1;
LABEL_8:
    ++i;
    goto LABEL_9;
  }
  negative = 0;
  if ( *i == 43 )
    goto LABEL_8;
LABEL_9:
  v9 = 0;
  overflow = 0;
  v10 = *i;
  save = (tagShutdownType)i;
  v11 = 0xFFFFFFFF / base;
  if ( i != v7 )
  {
    do
    {
      if ( (unsigned __int8)(v10 - 48) > 9u )
      {
        if ( (unsigned __int8)(v10 - 65) > 0x19u )
        {
          if ( (unsigned __int8)(v10 - 97) > 0x19u )
            break;
          v12 = v10 - 87;
        }
        else
        {
          v12 = v10 - 55;
        }
      }
      else
      {
        v12 = v10 - 48;
      }
      if ( v12 >= base )
        break;
      if ( v9 > v11 || v9 == v11 && v12 > 0xFFFFFFFF % base )
        overflow = 1;
      else
        v9 = v12 + base * v9;
      v10 = *++i;
    }
    while ( i != v7 );
    if ( i != (const char *)save )
    {
      if ( a5 != nullptr )
        *a5 = i;
      if ( overflow != 0 )
      {
        *err = 34;
        return -1;
      }
      else
      {
        if ( negative != 0 )
          return -v9;
        return v9;
      }
    }
  }
  v6 = nptr;
noconv_0:
  *err = 33;
  if ( a5 != nullptr )
    *a5 = v6;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A730
// Name: _my_strntoll_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strntoll_8bit(int a1, _BYTE *a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  unsigned int v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ebp
  _BYTE *v9; // esi
  unsigned __int64 v10; // rax
  unsigned int v11; // ebx
  char v12; // al
  unsigned __int8 v13; // al
  bool v15; // cc
  int v16; // [esp+10h] [ebp-1Ch]
  _BYTE *i; // [esp+14h] [ebp-18h]
  _BYTE *v18; // [esp+18h] [ebp-14h]
  unsigned __int64 v19; // [esp+1Ch] [ebp-10h]
  int v20; // [esp+38h] [ebp+Ch]

  v6 = 0;
  *a6 = 0;
  v7 = a2;
  v8 = &a2[a3];
  v9 = a2;
  for ( i = &a2[a3]; v9 < v8; ++v9 )
  {
    if ( (*(_BYTE *)((unsigned __int8)*v9 + *(_DWORD *)(a1 + 32) + 1) & 8) == 0 )
      break;
  }
  if ( v9 == v8 )
    goto LABEL_28;
  if ( *v9 == 45 )
  {
    v20 = 1;
LABEL_8:
    ++v9;
    goto LABEL_9;
  }
  v20 = 0;
  if ( *v9 == 43 )
    goto LABEL_8;
LABEL_9:
  v18 = v9;
  v10 = 0xFFFFFFFFFFFFFFFFuLL / (unsigned int)a4;
  v11 = 0;
  v19 = v10;
  v16 = 0;
  if ( v9 != v8 )
  {
    do
    {
      v12 = *v9;
      if ( (unsigned __int8)(*v9 - 48) > 9u )
      {
        if ( (unsigned __int8)(v12 - 65) > 0x19u )
        {
          if ( (unsigned __int8)(v12 - 97) > 0x19u )
            break;
          v13 = v12 - 87;
        }
        else
        {
          v13 = v12 - 55;
        }
      }
      else
      {
        v13 = *v9 - 48;
      }
      if ( v13 >= a4 )
        break;
      if ( v6 > HIDWORD(v10)
        || v6 >= HIDWORD(v10) && v11 > (unsigned int)v19
        || v11 == (_DWORD)v19 && v6 == HIDWORD(v10) && v13 > (unsigned int)(0xFFFFFFFFFFFFFFFFuLL % (unsigned int)a4) )
      {
        v16 = 1;
      }
      else
      {
        v6 = (v13 + a4 * __PAIR64__(v6, v11)) >> 32;
        HIDWORD(v10) = HIDWORD(v19);
        v11 = v13 + a4 * v11;
      }
      ++v9;
    }
    while ( v9 != i );
    if ( v9 != v18 )
    {
      if ( a5 != nullptr )
        *a5 = v9;
      if ( v20 != 0 )
      {
        if ( v6 > 0x80000000 )
          goto LABEL_42;
        if ( v6 < 0x80000000 )
          goto LABEL_41;
        v15 = v11 == 0;
      }
      else
      {
        if ( v6 > 0x7FFFFFFF )
          goto LABEL_42;
        if ( v6 < 0x7FFFFFFF )
          goto LABEL_41;
        v15 = true;
      }
      if ( !v15 )
        goto LABEL_42;
LABEL_41:
      if ( v16 != 0 )
      {
LABEL_42:
        *a6 = 34;
        if ( v20 != 0 )
          return 0;
        else
          return -1;
      }
      if ( v20 != 0 )
        return -v11;
      return v11;
    }
  }
  v7 = a2;
LABEL_28:
  *a6 = 33;
  if ( a5 != nullptr )
    *a5 = v7;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041A8F0
// Name: _my_strntoull_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strntoull_8bit(int a1, _BYTE *a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  unsigned int v6; // edi
  _BYTE *v7; // eax
  _BYTE *v8; // ebp
  _BYTE *v9; // esi
  unsigned __int64 v10; // rax
  unsigned int v11; // ebx
  char v12; // al
  unsigned __int8 v13; // al
  int v15; // [esp+10h] [ebp-1Ch]
  _BYTE *i; // [esp+14h] [ebp-18h]
  _BYTE *v17; // [esp+18h] [ebp-14h]
  unsigned __int64 v18; // [esp+1Ch] [ebp-10h]
  int v19; // [esp+38h] [ebp+Ch]

  v6 = 0;
  *a6 = 0;
  v7 = a2;
  v8 = &a2[a3];
  v9 = a2;
  for ( i = &a2[a3]; v9 < v8; ++v9 )
  {
    if ( (*(_BYTE *)((unsigned __int8)*v9 + *(_DWORD *)(a1 + 32) + 1) & 8) == 0 )
      break;
  }
  if ( v9 == v8 )
    goto LABEL_28;
  if ( *v9 == 45 )
  {
    v19 = 1;
LABEL_8:
    ++v9;
    goto LABEL_9;
  }
  v19 = 0;
  if ( *v9 == 43 )
    goto LABEL_8;
LABEL_9:
  v17 = v9;
  v10 = 0xFFFFFFFFFFFFFFFFuLL / (unsigned int)a4;
  v11 = 0;
  v18 = v10;
  v15 = 0;
  if ( v9 != v8 )
  {
    do
    {
      v12 = *v9;
      if ( (unsigned __int8)(*v9 - 48) > 9u )
      {
        if ( (unsigned __int8)(v12 - 65) > 0x19u )
        {
          if ( (unsigned __int8)(v12 - 97) > 0x19u )
            break;
          v13 = v12 - 87;
        }
        else
        {
          v13 = v12 - 55;
        }
      }
      else
      {
        v13 = *v9 - 48;
      }
      if ( v13 >= a4 )
        break;
      if ( v6 > HIDWORD(v10)
        || v6 >= HIDWORD(v10) && v11 > (unsigned int)v18
        || v11 == (_DWORD)v18 && v6 == HIDWORD(v10) && v13 > (unsigned int)(0xFFFFFFFFFFFFFFFFuLL % (unsigned int)a4) )
      {
        v15 = 1;
      }
      else
      {
        v6 = (v13 + a4 * __PAIR64__(v6, v11)) >> 32;
        HIDWORD(v10) = HIDWORD(v18);
        v11 = v13 + a4 * v11;
      }
      ++v9;
    }
    while ( v9 != i );
    if ( v9 != v17 )
    {
      if ( a5 != nullptr )
        *a5 = v9;
      if ( v15 != 0 )
      {
        *a6 = 34;
        return -1;
      }
      else
      {
        if ( v19 != 0 )
          return -v11;
        return v11;
      }
    }
  }
  v7 = a2;
LABEL_28:
  *a6 = 33;
  if ( a5 != nullptr )
    *a5 = v7;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AA70
// Name: _my_strntod_8bit
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_strntod_8bit(LIST_ENTRY32 *cs, char *str, const wchar_t *length, unsigned int *a4, int *err)
{
  int v5; // ecx

  v5 = (int)length;
  if ( length == (const wchar_t *)0x7FFFFFFF )
    v5 = 0xFFFF;
  *a4 = (unsigned int)&str[v5];
  my_strtod(a1: (tagShutdownType)str, a2: a4, a3: err);
}

//------------------------------------------------------------------------------
// Address: 0x0041AAA0
// Name: _my_long10_to_str_8bit
// Source: json
//------------------------------------------------------------------------------
_BYTE *__cdecl my_long10_to_str_8bit(int a1, unsigned __int8 *a2, _BYTE *a3, int a4, int a5)
{
  unsigned int v5; // ecx
  unsigned __int8 *v6; // ebp
  _BYTE *v7; // edi
  signed int v8; // edx
  unsigned __int8 *p_src; // esi
  char i; // cl
  int v12; // [esp+Ch] [ebp-4Ch]
  unsigned __int8 src; // [esp+50h] [ebp-8h] BYREF
  _BYTE v14[3]; // [esp+51h] [ebp-7h] BYREF

  v5 = a5;
  v6 = a2;
  v12 = 0;
  v14[0] = 0;
  if ( a4 >= 0 || a5 >= 0 )
  {
    v7 = a3;
  }
  else
  {
    *a2 = 45;
    v5 = -a5;
    v6 = a2 + 1;
    v7 = a3 - 1;
    v12 = 1;
  }
  v8 = v5 / 0xA;
  src = v5 % 0xA + 48;
  p_src = &src;
  for ( i = v5 / 0xA; v8 != 0; i = v8 )
  {
    v8 /= 10;
    *--p_src = i - 10 * v8 + 48;
  }
  if ( (unsigned int)v7 >= v14 - p_src )
    v7 = (_BYTE *)(v14 - p_src);
  memcpy(dst: v6, src: p_src, count: (unsigned int)v7);
  return &v7[v12];
}

//------------------------------------------------------------------------------
// Address: 0x0041AB70
// Name: _my_longlong10_to_str_8bit
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_longlong10_to_str_8bit(
        LIST_ENTRY32 *cs,
        char *dst,
        unsigned int len,
        const char *radix,
        int val,
        char *buffer)
{
  unsigned int v6; // eax
  int v7; // ebx
  char *v8; // edi
  unsigned int v9; // ebp
  unsigned __int8 *p_src; // esi
  unsigned __int64 v11; // rax
  unsigned int v12; // ecx
  unsigned int sign; // [esp+10h] [ebp-50h]
  char *v15; // [esp+14h] [ebp-4Ch]
  unsigned __int8 src; // [esp+57h] [ebp-9h] BYREF
  _BYTE v17[4]; // [esp+58h] [ebp-8h] BYREF

  v6 = (unsigned int)buffer;
  v7 = val;
  v8 = dst;
  v15 = dst;
  sign = 0;
  if ( (int)radix >= 0 || (int)buffer >= 0 )
  {
    v9 = len;
  }
  else
  {
    v7 = -val;
    *dst = 45;
    v8 = dst + 1;
    v6 = (unsigned __int64)-__SPAIR64__((unsigned int)buffer, val) >> 32;
    v15 = dst + 1;
    v9 = len - 1;
    sign = 1;
  }
  p_src = v17;
  v17[0] = 0;
  if ( (v6 | v7) != 0 )
  {
    if ( v6 != 0 || (unsigned int)v7 > 0x7FFFFFFF )
    {
      do
      {
        v11 = __PAIR64__(v6, v7) / 0xA;
        v12 = v11;
        *--p_src = v7 - 10 * v11 + 48;
        v7 = v11;
        v6 = HIDWORD(v11);
      }
      while ( __PAIR64__(HIDWORD(v11), v12) > 0x7FFFFFFF );
      v8 = v15;
    }
    for ( ; v7 != 0; v7 /= 10 )
      *--p_src = v7 % 10 + 48;
    if ( v9 >= v17 - p_src )
      v9 = v17 - p_src;
  }
  else
  {
    p_src = &src;
    src = 48;
    v9 = 1;
  }
  memcpy(dst: (unsigned __int8 *)v8, src: p_src, count: v9);
  return v9 + sign;
}

//------------------------------------------------------------------------------
// Address: 0x0041AC90
// Name: _my_wildcmp_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_wildcmp_8bit(
        int a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        char *a4,
        char *a5,
        int a6,
        int a7,
        int a8)
{
  char *v8; // esi
  int result; // eax
  int v11; // ecx
  char *v12; // edx
  int v13; // ebx
  int v14; // eax
  int v15; // ebx
  char v16; // cl
  bool v17; // zf
  char *v18; // esi
  int v19; // eax
  unsigned __int8 v20; // al
  unsigned __int8 *v21; // ecx
  int v22; // ecx
  char v23; // bl
  char *v24; // esi
  unsigned __int8 *v25; // eax

  v8 = a4;
  result = -1;
  if ( a4 == a5 )
    return a2 != a3;
  while ( 1 )
  {
    v11 = *v8;
    if ( v11 == a8 )
    {
LABEL_12:
      v13 = a7;
    }
    else
    {
      v12 = v8 + 1;
      while ( 1 )
      {
        v13 = a7;
        if ( v11 == a7 )
          break;
        if ( v11 == a6 && v12 != a5 )
        {
          ++v8;
          ++v12;
        }
        if ( a2 == a3 )
          return 1;
        v14 = *(_DWORD *)(a1 + 44);
        v15 = (unsigned __int8)*v8;
        v16 = *(_BYTE *)(*a2++ + v14);
        ++v8;
        ++v12;
        if ( *(_BYTE *)(v15 + v14) != v16 )
          return 1;
        if ( v8 == a5 )
          return a2 != a3;
        v11 = *v8;
        result = 1;
        if ( v11 == a8 )
          goto LABEL_12;
      }
    }
    if ( *v8 == v13 )
    {
      while ( 1 )
      {
        if ( a2 == a3 )
          return result;
        ++v8;
        ++a2;
        v17 = v8 == a5;
        if ( v8 >= a5 )
          break;
        if ( *v8 != v13 )
        {
          v17 = v8 == a5;
          break;
        }
      }
      if ( v17 )
        return a2 != a3;
    }
    if ( *v8 == a8 )
      break;
    if ( v8 == a5 )
      return a2 != a3;
  }
  v18 = v8 + 1;
  if ( v18 == a5 )
    return 0;
  while ( 1 )
  {
    v19 = *v18;
    if ( v19 != a8 )
    {
      if ( v19 != v13 )
        break;
      if ( a2 == a3 )
        return -1;
      ++a2;
    }
    if ( ++v18 == a5 )
      return 0;
  }
  if ( v18 != a5 )
  {
    if ( a2 != a3 )
    {
      v20 = *v18;
      if ( (unsigned __int8)*v18 == a6 )
      {
        v21 = (unsigned __int8 *)(v18 + 1);
        if ( v18 + 1 != a5 )
        {
          ++v18;
          v20 = *v21;
        }
      }
      v22 = a1;
      v23 = *(_BYTE *)(v20 + *(_DWORD *)(a1 + 44));
      v24 = v18 + 1;
      while ( 1 )
      {
        do
        {
          if ( *(_BYTE *)(*a2 + *(_DWORD *)(v22 + 44)) == v23 )
            break;
          ++a2;
        }
        while ( a2 != a3 );
        v25 = a2++;
        if ( v25 == a3 )
          break;
        result = my_wildcmp_8bit(a1: v22, a2, a3, a4: v24, a5, a6, a7, a8);
        if ( result <= 0 )
          return result;
        if ( a2 == a3 || *v24 == a8 )
          break;
        v22 = a1;
      }
    }
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AE20
// Name: _my_like_range_simple
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_simple(
        LIST_ENTRY32 *a1,
        char *min_end,
        unsigned int charlen,
        int escape,
        int w_one,
        int w_many,
        unsigned int res_length,
        char *min_org,
        char *max_str,
        unsigned int *min_length,
        unsigned int *max_length)
{
  char *v11; // ecx
  char *v12; // esi
  char *v13; // edi
  unsigned int v14; // eax
  char *v16; // ebp
  char v17; // bl
  int v18; // edi
  unsigned int v20; // eax
  char *end; // [esp+10h] [ebp-4h]
  unsigned int charlena; // [esp+20h] [ebp+Ch]

  v11 = min_org;
  v12 = min_end;
  v13 = &min_org[res_length];
  v14 = res_length / a1[11].Flink;
  end = &min_end[charlen];
  charlena = v14;
  if ( min_end != end )
  {
    v16 = min_end + 1;
    while ( 1 )
    {
      if ( v11 == v13 || v14 == 0 )
        goto LABEL_13;
      v17 = *v12;
      v18 = *v12;
      if ( v18 == escape && v16 != end )
        break;
      if ( v18 != w_one )
      {
        if ( v18 == w_many )
        {
          if ( (a1[1].Blink & 0x10) != 0 )
            v20 = v11 - min_org;
          else
            v20 = res_length;
          *min_length = v20;
          *max_length = res_length;
          do
          {
            *v11++ = 0;
            *max_str++ = BYTE2(a1[11].Blink);
          }
          while ( v11 != &min_org[res_length] );
          return 0;
        }
        goto LABEL_11;
      }
      *v11 = 0;
      *max_str = BYTE2(a1[11].Blink);
LABEL_12:
      v13 = &min_org[res_length];
      ++v12;
      v14 = charlena - 1;
      ++v11;
      ++max_str;
      ++v16;
      --charlena;
      if ( v12 == end )
        goto LABEL_13;
    }
    v17 = *++v12;
    ++v16;
LABEL_11:
    *max_str = v17;
    *v11 = v17;
    goto LABEL_12;
  }
LABEL_13:
  *max_length = v11 - min_org;
  for ( *min_length = v11 - min_org; v11 != v13; ++max_str )
  {
    *max_str = 32;
    *v11++ = 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041AF30
// Name: _my_scan_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_scan_8bit(int a1, unsigned __int8 *a2, unsigned __int8 *a3, int a4)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *i; // eax

  v4 = a2;
  if ( a4 != 1 )
  {
    if ( a4 == 2 )
    {
      if ( a2 < a3 )
      {
        do
        {
          if ( (*(_BYTE *)(*v4 + *(_DWORD *)(a1 + 32) + 1) & 8) == 0 )
            break;
          ++v4;
        }
        while ( v4 < a3 );
      }
      return v4 - a2;
    }
    return 0;
  }
  if ( *a2 != 46 )
    return 0;
  for ( i = a2 + 1; i != a3; ++i )
  {
    if ( *i != 48 )
      break;
  }
  return i - a2;
}

//------------------------------------------------------------------------------
// Address: 0x0041AF90
// Name: _my_fill_8bit
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_fill_8bit(int a1, unsigned __int8 *dst, unsigned int count, unsigned __int8 value)
{
  memset(dst, value, count);
}

//------------------------------------------------------------------------------
// Address: 0x0041AFB0
// Name: _my_numcells_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_numcells_8bit(int a1, int a2, int a3)
{
  return a3 - a2;
}

//------------------------------------------------------------------------------
// Address: 0x0041AFC0
// Name: _my_charpos_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_charpos_8bit(int a1, int a2, int a3, int a4)
{
  return a4;
}

//------------------------------------------------------------------------------
// Address: 0x0041AFD0
// Name: _my_well_formed_len_8bit
// Source: json
//------------------------------------------------------------------------------
unsigned int my_well_formed_len_8bit(
        LIST_ENTRY32 *cs,
        const char *start,
        tagShutdownType end,
        unsigned int nchars,
        int *error,
        ...)
{
  unsigned int result; // eax

  result = end - (_DWORD)start;
  *error = 0;
  if ( end - (int)start >= nchars )
    return nchars;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041AFF0
// Name: _my_lengthsp_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_lengthsp_8bit(int a1, int a2)
{
  return skip_trailing_space() - a2;
}

//------------------------------------------------------------------------------
// Address: 0x0041B010
// Name: _my_instr_simple
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_instr_simple(
        int a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 *a4,
        unsigned int a5,
        _DWORD *a6,
        unsigned int a7)
{
  unsigned __int8 *v8; // ecx
  int v9; // edi
  unsigned __int8 *v10; // esi
  int v11; // ebx
  unsigned __int8 *v12; // eax
  int v13; // edi
  int v14; // esi
  int v15; // edx
  char v16; // bl
  int v17; // ecx

  if ( a5 > a3 )
    return 0;
  if ( a5 != 0 )
  {
    v8 = a2;
    v9 = (int)&a2[a3 - a5 + 1];
    v10 = a4;
LABEL_7:
    while ( v8 != (unsigned __int8 *)v9 )
    {
      v11 = *v8++;
      if ( *(_BYTE *)(v11 + *(_DWORD *)(a1 + 44)) == *(_BYTE *)(*v10 + *(_DWORD *)(a1 + 44)) )
      {
        v12 = v10 + 1;
        v13 = v8 - (v10 + 1);
        while ( v12 != &a4[a5] )
        {
          v14 = *(_DWORD *)(a1 + 44);
          v15 = v12[v13];
          v16 = *(_BYTE *)(*v12++ + v14);
          if ( *(_BYTE *)(v15 + v14) != v16 )
          {
            v10 = a4;
            v9 = (int)&a2[a3 - a5 + 1];
            goto LABEL_7;
          }
        }
        if ( a7 != 0 )
        {
          v17 = v8 - a2 - 1;
          *a6 = 0;
          a6[1] = v17;
          a6[2] = v17;
          if ( a7 > 1 )
          {
            a6[4] = v17 + a5;
            a6[3] = v17;
            a6[5] = a5;
          }
        }
        return 2;
      }
    }
    return 0;
  }
  if ( a7 != 0 )
  {
    *a6 = 0;
    a6[1] = 0;
    a6[2] = 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041B0F0
// Name: pcmp
// Source: json
//------------------------------------------------------------------------------
int __cdecl pcmp(tagCAC s)
{
  int result; // eax

  result = *(_DWORD *)s.pElems - *(_DWORD *)s.cElems;
  if ( *(_DWORD *)s.pElems == *(_DWORD *)s.cElems )
    return *(unsigned __int16 *)(s.cElems + 4) - *((unsigned __int16 *)s.pElems + 3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041B110
// Name: create_fromuni
// Source: json
//------------------------------------------------------------------------------
char __cdecl create_fromuni(int a1, int (__cdecl *a2)(unsigned int))
{
  int v3; // edx
  unsigned __int16 *v4; // ebp
  unsigned __int16 v5; // cx
  int v6; // eax
  int v7; // ebx
  unsigned __int8 *v8; // edi
  unsigned __int16 v9; // dx
  unsigned __int8 *v10; // edx
  unsigned __int16 v11; // ax
  unsigned __int16 v12; // cx
  int v13; // eax
  unsigned __int8 *v14; // edi
  unsigned __int16 v15; // dx
  unsigned __int8 *v16; // edx
  unsigned __int16 v17; // ax
  unsigned __int16 v18; // cx
  int v19; // eax
  unsigned __int8 *v20; // edi
  unsigned __int16 v21; // dx
  unsigned __int8 *v22; // edx
  unsigned __int16 v23; // ax
  unsigned __int16 v24; // cx
  int v25; // eax
  unsigned __int8 *v26; // edi
  unsigned __int16 v27; // dx
  unsigned __int8 *v28; // edx
  unsigned __int16 v29; // ax
  int v30; // ebx
  unsigned __int8 *v31; // esi
  unsigned int v32; // edi
  unsigned __int8 *v33; // eax
  int i; // ecx
  unsigned __int16 v35; // ax
  unsigned __int16 v36; // dx
  int v37; // eax
  int v38; // eax
  unsigned __int8 *v39; // ecx
  int v40; // edx
  _DWORD *v41; // eax
  int v42; // [esp+4h] [ebp-C04h]
  unsigned __int8 dst[3072]; // [esp+8h] [ebp-C00h] BYREF

  if ( *(_DWORD *)(a1 + 56) == 0 )
    return 1;
  memset(dst, value: 0, count: sizeof(dst));
  v3 = 2;
  v42 = 2;
  v4 = (unsigned __int16 *)(*(_DWORD *)(a1 + 56) + 4);
  do
  {
    v5 = *(v4 - 2);
    if ( v5 != 0 || v3 == 2 )
    {
      v6 = 12 * HIBYTE(v5);
      v7 = *(_DWORD *)&dst[v6];
      v8 = &dst[v6];
      if ( v7 != 0 )
      {
        v9 = *(_WORD *)&dst[12 * HIBYTE(v5) + 4];
        if ( v5 < v9 )
          v9 = *(v4 - 2);
        *(_WORD *)&dst[12 * HIBYTE(v5) + 4] = v9;
        v10 = &dst[v6 + 6];
        v11 = *(_WORD *)&dst[12 * HIBYTE(v5) + 6];
        if ( v5 > v11 )
          v11 = v5;
        *(_WORD *)v10 = v11;
        v3 = v42;
      }
      else
      {
        *(_WORD *)&dst[12 * HIBYTE(v5) + 4] = v5;
        *(_WORD *)&dst[12 * HIBYTE(v5) + 6] = v5;
      }
      *(_DWORD *)v8 = v7 + 1;
    }
    v12 = *(v4 - 1);
    if ( v12 != 0 || v3 == 1 )
    {
      v13 = 12 * HIBYTE(v12);
      v14 = &dst[v13];
      if ( *(_DWORD *)&dst[v13] != 0 )
      {
        v15 = *(_WORD *)&dst[12 * HIBYTE(v12) + 4];
        if ( v12 < v15 )
          v15 = *(v4 - 1);
        *(_WORD *)&dst[12 * HIBYTE(v12) + 4] = v15;
        v16 = &dst[v13 + 6];
        v17 = *(_WORD *)&dst[12 * HIBYTE(v12) + 6];
        if ( v12 > v17 )
          v17 = v12;
        *(_WORD *)v16 = v17;
        v3 = v42;
      }
      else
      {
        *(_WORD *)&dst[12 * HIBYTE(v12) + 4] = v12;
        *(_WORD *)&dst[12 * HIBYTE(v12) + 6] = v12;
      }
      ++*(_DWORD *)v14;
    }
    v18 = *v4;
    if ( *v4 != 0 || v3 == 0 )
    {
      v19 = 12 * (unsigned __int8)HIBYTE(*v4);
      v20 = &dst[v19];
      if ( *(_DWORD *)&dst[v19] != 0 )
      {
        v21 = *(_WORD *)&dst[12 * (unsigned __int8)HIBYTE(*v4) + 4];
        if ( v18 < v21 )
          v21 = *v4;
        *(_WORD *)&dst[12 * (unsigned __int8)HIBYTE(*v4) + 4] = v21;
        v22 = &dst[v19 + 6];
        v23 = *(_WORD *)&dst[v19 + 6];
        if ( v18 > v23 )
          v23 = v18;
        *(_WORD *)v22 = v23;
        v3 = v42;
      }
      else
      {
        *(_WORD *)&dst[12 * (unsigned __int8)HIBYTE(*v4) + 4] = v18;
        *(_WORD *)&dst[v19 + 6] = v18;
      }
      ++*(_DWORD *)v20;
    }
    v24 = v4[1];
    if ( v24 != 0 || v3 == -1 )
    {
      v25 = 12 * HIBYTE(v24);
      v26 = &dst[v25];
      if ( *(_DWORD *)&dst[v25] != 0 )
      {
        v27 = *(_WORD *)&dst[12 * HIBYTE(v24) + 4];
        if ( v24 < v27 )
          v27 = v4[1];
        *(_WORD *)&dst[12 * HIBYTE(v24) + 4] = v27;
        v28 = &dst[v25 + 6];
        v29 = *(_WORD *)&dst[12 * HIBYTE(v24) + 6];
        if ( v24 > v29 )
          v29 = v24;
        *(_WORD *)v28 = v29;
        v3 = v42;
      }
      else
      {
        *(_WORD *)&dst[12 * HIBYTE(v24) + 4] = v24;
        *(_WORD *)&dst[12 * HIBYTE(v24) + 6] = v24;
      }
      ++*(_DWORD *)v26;
    }
    v3 += 4;
    v4 += 4;
    v42 = v3;
  }
  while ( v3 - 2 < 256 );
  qsort(base: dst, num: 0x100u, width: 0xCu, comp: (int (__cdecl *)(const void *, const void *))pcmp);
  v30 = 0;
  v31 = &dst[6];
  do
  {
    if ( *(_DWORD *)(v31 - 6) == 0 )
      break;
    v32 = *(unsigned __int16 *)v31 - *((unsigned __int16 *)v31 - 1) + 1;
    v33 = (unsigned __int8 *)a2(a1: v32);
    *(_DWORD *)(v31 + 2) = v33;
    if ( v33 == nullptr )
      return 1;
    memset(dst: v33, value: 0, count: v32);
    for ( i = 1; i < 256; ++i )
    {
      v35 = *(_WORD *)(*(_DWORD *)(a1 + 56) + 2 * i);
      v36 = *((_WORD *)v31 - 1);
      if ( v35 >= v36 && v35 <= *(_WORD *)v31 && v35 != 0 )
        *(_BYTE *)(v35 - v36 + *(_DWORD *)(v31 + 2)) = i;
    }
    ++v30;
    v31 += 12;
  }
  while ( v30 < 256 );
  v37 = a2(a1: 8 * v30 + 8);
  *(_DWORD *)(a1 + 60) = v37;
  if ( v37 == 0 )
    return 1;
  v38 = 0;
  if ( v30 > 0 )
  {
    v39 = &dst[4];
    do
    {
      v40 = *(_DWORD *)(a1 + 60);
      *(_DWORD *)(v40 + 8 * v38) = *(_DWORD *)v39;
      *(_DWORD *)(v40 + 8 * v38++ + 4) = *((_DWORD *)v39 + 1);
      v39 += 12;
    }
    while ( v38 < v30 );
  }
  v41 = (_DWORD *)(*(_DWORD *)(a1 + 60) + 8 * v38);
  *v41 = 0;
  v41[1] = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B460
// Name: my_cset_init_8bit
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_cset_init_8bit(_BYTE *a1, int (__cdecl *a2)(unsigned int))
{
  a1[80] = 1;
  a1[81] = 1;
  a1[96] = 32;
  return create_fromuni((int)a1, a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041B480
// Name: set_max_sort_char
// Source: json
//------------------------------------------------------------------------------
void __usercall set_max_sort_char(int a1@<edi>)
{
  int v1; // esi
  unsigned __int8 v2; // dl
  unsigned int i; // eax

  v1 = *(_DWORD *)(a1 + 44);
  if ( v1 != 0 )
  {
    v2 = *(_BYTE *)(*(unsigned __int8 *)(a1 + 94) + v1);
    for ( i = 0; i < 0x100; ++i )
    {
      if ( *(_BYTE *)(v1 + i) > v2 )
      {
        v2 = *(_BYTE *)(v1 + i);
        *(_WORD *)(a1 + 94) = i;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B4B0
// Name: my_coll_init_simple
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_coll_init_simple(int a1)
{
  set_max_sort_char(a1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041B4C0
// Name: _my_strtoll10_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strtoll10_8bit(LIST_ENTRY32 *cs, _BYTE *nptr, _DWORD *a3, int *error)
{
  return my_strtoll10(a1: nptr, a2: a3, a3: error);
}

//------------------------------------------------------------------------------
// Address: 0x0041B4E0
// Name: _my_mb_ctype_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_ctype_8bit(LIST_ENTRY32 *a1, int *ctype, const LoggingContext_t *s, const LoggingContext_t *e)
{
  if ( s < e )
  {
    *ctype = *(unsigned __int8 *)(a1[4].Flink + LOBYTE(s->m_ChannelID) + 1);
    return 1;
  }
  else
  {
    *ctype = 0;
    return -101;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041B520
// Name: _my_strntoull10rnd_8bit
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strntoull10rnd_8bit(int a1, _BYTE *a2, int a3, int a4, _DWORD *a5, _DWORD *a6)
{
  _BYTE *v6; // esi
  unsigned int v7; // edi
  BOOL v8; // ebp
  unsigned __int64 v9; // rax
  _BYTE *v10; // ebx
  unsigned __int8 v11; // cl
  _BYTE *v12; // edi
  unsigned int v13; // ebp
  unsigned __int8 v14; // bl
  int v15; // edi
  BOOL v16; // ebx
  int j; // edx
  unsigned __int8 v18; // cl
  const std::__non_rtti_object **v19; // ecx
  const std::__non_rtti_object *v20; // edi
  unsigned __int64 v21; // rcx
  unsigned __int64 v23; // [esp-8h] [ebp-30h]
  _BYTE *v24; // [esp+10h] [ebp-18h]
  unsigned int v25; // [esp+14h] [ebp-14h]
  const std::__non_rtti_object *v26; // [esp+14h] [ebp-14h]
  BOOL v27; // [esp+1Ch] [ebp-Ch]
  _BYTE *v28; // [esp+20h] [ebp-8h]
  unsigned int v29; // [esp+24h] [ebp-4h]
  int i; // [esp+30h] [ebp+8h]
  BOOL v31; // [esp+34h] [ebp+Ch]

  v6 = a2;
  v7 = (unsigned int)&a2[a3];
  v25 = v7;
  i = 0;
  if ( (unsigned int)v6 >= v7 )
    goto LABEL_58;
  while ( *v6 == 32 || *v6 == 9 )
  {
    if ( (unsigned int)++v6 >= v7 )
      goto LABEL_58;
  }
  if ( (unsigned int)v6 >= v7 || ((v8 = *v6 == 45, v27 = v8, *v6 == 45) || *v6 == 43) && (++v6, v6 == (_BYTE *)v7) )
  {
LABEL_58:
    *a5 = v6;
    *a6 = 33;
    LODWORD(v9) = 0;
    return v9;
  }
  HIDWORD(v9) = v6 + 9;
  v10 = v6;
  v28 = v6;
  if ( (unsigned int)(v6 + 9) > v7 )
    HIDWORD(v9) = v7;
  for ( LODWORD(v9) = 0; (unsigned int)v6 < HIDWORD(v9); LODWORD(v9) = v11 + 10 * v9 )
  {
    v11 = *v6 - 48;
    if ( v11 >= 0xAu )
      break;
    ++v6;
  }
  if ( (unsigned int)v6 >= v7 )
  {
    *a5 = v6;
    if ( v8 )
    {
      if ( a4 != 0 )
      {
        *a6 = (_DWORD)v9 != 0 ? 0x22 : 0;
        LODWORD(v9) = 0;
      }
      else
      {
        *a6 = 0;
        LODWORD(v9) = -(int)v9;
      }
      return v9;
    }
LABEL_85:
    *a6 = 0;
    return v9;
  }
  HIDWORD(v9) = v7;
  v12 = nullptr;
  v24 = (_BYTE *)(v6 - v10);
  v13 = 0;
  while ( 1 )
  {
    v14 = *v6 - 48;
    if ( v14 < 0xAu )
      break;
    if ( *v6 != 46 )
      goto LABEL_33;
    if ( v12 != nullptr )
    {
      v15 = 0;
      v31 = false;
      goto LABEL_56;
    }
    v12 = v6 + 1;
LABEL_32:
    if ( (unsigned int)++v6 >= HIDWORD(v9) )
    {
LABEL_33:
      if ( v12 != nullptr )
        v15 = v12 - v6;
      else
        v15 = 0;
      v31 = false;
LABEL_55:
      i = v15;
      goto LABEL_56;
    }
  }
  if ( v13 < 0x19999999 || v13 <= 0x19999999 && (unsigned int)v9 < 0x99999999 )
  {
LABEL_28:
    v13 = (v14 + 10 * __PAIR64__(v13, v9)) >> 32;
    ++v24;
    v9 = __PAIR64__(v25, v14 + 10 * v9);
    goto LABEL_32;
  }
  if ( (_DWORD)v9 == -1717986919 && v13 == 429496729 )
  {
    if ( v14 > 5u )
    {
      LODWORD(v9) = -1;
      v13 = -1;
      v31 = true;
      ++v6;
      goto LABEL_37;
    }
    goto LABEL_28;
  }
  v31 = *v6 >= 53;
LABEL_37:
  if ( v12 != nullptr )
  {
    v15 = v12 - v6;
    for ( i = v15; (unsigned int)v6 < HIDWORD(v9); ++v6 )
    {
      if ( (unsigned __int8)(*v6 - 48) >= 0xAu )
        break;
    }
  }
  else
  {
    v15 = 0;
    if ( (unsigned int)v6 < HIDWORD(v9) )
    {
      while ( (unsigned __int8)(*v6 - 48) < 0xAu )
      {
        ++v6;
        ++v15;
        if ( (unsigned int)v6 >= HIDWORD(v9) )
          goto LABEL_55;
      }
      i = v15;
      if ( (unsigned int)v6 < HIDWORD(v9) && *v6 == 46 && (unsigned int)++v6 < HIDWORD(v9) )
      {
        do
        {
          if ( (unsigned __int8)(*v6 - 48) >= 0xAu )
            break;
          ++v6;
        }
        while ( (unsigned int)v6 < HIDWORD(v9) );
      }
    }
  }
LABEL_56:
  if ( v24 == nullptr )
  {
    v6 = v28;
    goto LABEL_58;
  }
  if ( (unsigned int)v6 >= HIDWORD(v9) || *v6 != 101 && *v6 != 69 || (++v6, (unsigned int)v6 >= HIDWORD(v9)) )
  {
LABEL_72:
    if ( v15 != 0 )
    {
      if ( v15 < 0 )
      {
        if ( -v15 >= 20 )
        {
          *a5 = v6;
          LODWORD(v9) = 0;
          goto LABEL_85;
        }
        v19 = &d10 - 2 * i;
        v20 = v19[1];
        v23 = *(_QWORD *)v19;
        v26 = *v19;
        v21 = __PAIR64__(v13, v9) % *(_QWORD *)v19;
        v29 = (__PAIR64__(v13, v9) / v23) >> 32;
        LODWORD(v9) = __PAIR64__(v13, v9) / v23;
        v13 = v29;
        if ( 2 * v21 < __PAIR64__((unsigned int)v20, (unsigned int)v26) )
          goto LABEL_76;
LABEL_75:
        v13 = (__PAIR64__(v13, v9) + 1) >> 32;
        LODWORD(v9) = v9 + 1;
        goto LABEL_76;
      }
      if ( v15 <= 20 )
      {
        while ( v13 <= 0x19999999 && (v13 < 0x19999999 || (unsigned int)v9 <= 0x99999999) )
        {
          --i;
          v9 = 10 * __PAIR64__(v13, v9);
          v13 = HIDWORD(v9);
          if ( i <= 0 )
            goto LABEL_76;
        }
      }
      else if ( (v13 | (unsigned int)v9) == 0 )
      {
        goto LABEL_76;
      }
    }
    else
    {
      if ( !v31 )
        goto LABEL_76;
      if ( (v13 & (unsigned int)v9) != 0xFFFFFFFF )
        goto LABEL_75;
    }
    *a5 = v6;
    *a6 = 34;
    if ( a4 != 0 )
    {
      LODWORD(v9) = -1;
      return v9;
    }
    if ( v27 )
    {
      LODWORD(v9) = 0;
      return v9;
    }
LABEL_102:
    LODWORD(v9) = -1;
    return v9;
  }
  v16 = *v6 == 45;
  if ( *v6 != 45 && *v6 != 43 || (++v6, v6 != (_BYTE *)HIDWORD(v9)) )
  {
    for ( j = 0; (unsigned int)v6 < v25; j = v18 + 10 * j )
    {
      v18 = *v6 - 48;
      if ( v18 >= 0xAu )
        break;
      ++v6;
    }
    if ( v16 )
      j = -j;
    i += j;
    v15 = i;
    goto LABEL_72;
  }
LABEL_76:
  *a5 = v6;
  if ( a4 != 0 )
  {
    if ( v27 && (v13 | (unsigned int)v9) != 0 )
    {
      *a6 = 34;
      LODWORD(v9) = 0;
      return v9;
    }
    goto LABEL_106;
  }
  if ( !v27 )
  {
    if ( (v13 & 0x80000000) != 0 )
    {
      *a6 = 34;
      goto LABEL_102;
    }
LABEL_106:
    *a6 = 0;
    return v9;
  }
  if ( v13 >= 0x80000000 && (v13 > 0x80000000 || (_DWORD)v9 != 0) )
  {
    *a6 = 34;
    LODWORD(v9) = 0;
  }
  else
  {
    v9 = -__SPAIR64__(v13, v9);
    *a6 = 0;
  }
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x0041B990
// Name: _my_propagate_simple
// Source: json
//------------------------------------------------------------------------------
char __thiscall my_propagate_simple(ConCommandBase *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041B9B0
// Name: _my_strxfrm_desc_and_reverse
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_strxfrm_desc_and_reverse(
        unsigned __int8 *str,
        unsigned __int8 *strend,
        unsigned int flags,
        char level)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v5; // ecx
  unsigned __int8 v6; // dl
  unsigned __int8 *v7; // ecx
  unsigned __int8 v8; // dl

  result = (unsigned __int8 *)flags;
  if ( ((256 << level) & flags) != 0 )
  {
    if ( ((0x10000 << level) & flags) != 0 )
    {
      v5 = str;
      for ( result = strend - 1; v5 <= result; --result )
      {
        v6 = *v5;
        *v5 = ~*result;
        *result = ~v6;
        ++v5;
      }
    }
    else
    {
      for ( result = str; result < strend; ++result )
        *result = ~*result;
    }
  }
  else if ( ((0x10000 << level) & flags) != 0 )
  {
    v7 = str;
    for ( result = strend - 1; v7 < result; --result )
    {
      v8 = *v7;
      *v7 = *result;
      *result = v8;
      ++v7;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BA30
// Name: _my_strxfrm_pad_desc_and_reverse
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strxfrm_pad_desc_and_reverse(
        int a1,
        unsigned __int8 *str,
        unsigned __int8 *strend,
        unsigned int a4,
        int a5,
        unsigned int flags,
        char level)
{
  unsigned __int8 *v7; // esi
  int v8; // ebp

  v7 = strend;
  if ( a5 != 0 && (unsigned int)strend < a4 && (flags & 0x40) != 0 )
  {
    v8 = a4 - (_DWORD)strend;
    if ( a4 - (unsigned int)strend >= a5 * *(_DWORD *)(a1 + 84) )
      v8 = a5 * *(_DWORD *)(a1 + 84);
    (*(void (__cdecl **)(int, unsigned __int8 *, int, _DWORD))(*(_DWORD *)(a1 + 100) + 72))(
      a1,
      a2: strend,
      a3: v8,
      a4: *(unsigned __int8 *)(a1 + 96));
    v7 = &strend[v8];
  }
  my_strxfrm_desc_and_reverse(str, strend: v7, flags, level);
  if ( (flags & 0x80u) != 0 && (unsigned int)v7 < a4 )
  {
    (*(void (__cdecl **)(int, unsigned __int8 *, unsigned int, _DWORD))(*(_DWORD *)(a1 + 100) + 72))(
      a1,
      a2: v7,
      a3: a4 - (_DWORD)v7,
      a4: *(unsigned __int8 *)(a1 + 96));
    v7 = (unsigned __int8 *)a4;
  }
  return v7 - str;
}

//------------------------------------------------------------------------------
// Address: 0x0041BAC0
// Name: _my_strnxfrm_simple
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnxfrm_simple(
        int a1,
        unsigned __int8 *str,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 *a5,
        unsigned int a6,
        unsigned int flags)
{
  unsigned int v7; // ebp
  int v8; // edi
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ecx

  v7 = a3;
  v8 = *(_DWORD *)(a1 + 44);
  v9 = str;
  if ( a3 >= a4 )
    v7 = a4;
  if ( v7 > a6 )
    v7 = a6;
  v10 = a5;
  if ( str == a5 )
  {
    if ( str < &str[v7] )
    {
      do
      {
        *v9 = *(_BYTE *)(*v9 + v8);
        ++v9;
      }
      while ( v9 < &str[v7] );
    }
  }
  else if ( a5 < &a5[v7] )
  {
    do
      *v9++ = *(_BYTE *)(*v10++ + v8);
    while ( v10 < &a5[v7] );
  }
  return my_strxfrm_pad_desc_and_reverse(a1, str, strend: v9, a4: (unsigned int)&str[a3], a5: a4 - v7, flags, level: 0);
}
