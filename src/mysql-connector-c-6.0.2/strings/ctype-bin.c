// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-bin.c
// Functions: 11
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041BB50
// Name: my_coll_init_8bit_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_coll_init_8bit_bin(int a1)
{
  *(_WORD *)(a1 + 94) = 255;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041BC00
// Name: my_strnncollsp_binary
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_binary(LIST_ENTRY32 *cs)
{
  return my_strnncoll_mb_bin((int *)cs);
}

//------------------------------------------------------------------------------
// Address: 0x0041BC10
// Name: _my_lengthsp_binary
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_lengthsp_binary(unsigned __int16 cs, _iobuf *src, unsigned int srclen)
{
  return srclen;
}

//------------------------------------------------------------------------------
// Address: 0x0041BC50
// Name: my_mb_wc_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_bin(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  if ( (unsigned int)a3 >= a4 )
    return -101;
  *a2 = *a3;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041BC70
// Name: my_wc_mb_bin
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_bin(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  if ( s >= e )
    return -101;
  if ( (unsigned int)wc >= 0x100 )
    return 0;
  *s = (unsigned __int8)wc;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041BCA0
// Name: _my_hash_sort_8bit_bin
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_hash_sort_8bit_bin(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *key,
        unsigned int len,
        unsigned int *nr1,
        unsigned int *nr2)
{
  const LoggingContext_t *v5; // esi
  unsigned int result; // eax
  int m_ChannelID_low; // ebp

  v5 = key;
  result = skip_trailing_space();
  if ( (unsigned int)key < result )
  {
    do
    {
      m_ChannelID_low = LOBYTE(v5->m_ChannelID);
      v5 = (const LoggingContext_t *)((char *)v5 + 1);
      *nr1 ^= (*nr1 << 8) + m_ChannelID_low * (*nr2 + (*nr1 & 0x3F));
      *nr2 += 3;
    }
    while ( (unsigned int)v5 < result );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BCF0
// Name: _my_hash_sort_bin
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_hash_sort_bin(
        LIST_ENTRY32 *a1,
        const LoggingContext_t *key,
        unsigned int len,
        unsigned int *nr1,
        unsigned int *nr2)
{
  const LoggingContext_t *i; // ecx
  unsigned int result; // eax
  int m_ChannelID_low; // ebp

  for ( i = key; i < (const LoggingContext_t *)((char *)key + len); *nr2 += 3 )
  {
    result = *nr1;
    m_ChannelID_low = LOBYTE(i->m_ChannelID);
    i = (const LoggingContext_t *)((char *)i + 1);
    *nr1 ^= (*nr1 << 8) + m_ChannelID_low * (*nr2 + (*nr1 & 0x3F));
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041BD40
// Name: _my_wildcmp_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_wildcmp_bin(int a1, char *a2, char *a3, char *a4, char *a5, int a6, int a7, int a8)
{
  char *v8; // esi
  int result; // eax
  int v11; // ecx
  char *v12; // edx
  int v13; // ebp
  char v14; // al
  char v15; // cl
  char *v16; // ecx
  bool v17; // zf
  char *v18; // esi
  int v19; // eax
  unsigned __int8 v20; // dl
  unsigned __int8 *v21; // eax
  char *v22; // esi
  char *v23; // eax
  char v24; // [esp+20h] [ebp+10h]

  v8 = a4;
  result = -1;
  if ( a4 == a5 )
  {
LABEL_24:
    v16 = a3;
    return a2 != v16;
  }
  while ( 1 )
  {
    v11 = *v8;
    if ( v11 == a8 )
    {
      v13 = a7;
    }
    else
    {
      v12 = v8 + 1;
      do
      {
        v13 = a7;
        if ( v11 == a7 )
          break;
        if ( v11 == a6 && v12 != a5 )
        {
          ++v8;
          ++v12;
        }
        if ( a2 != a3 )
        {
          v14 = *v8;
          v15 = *a2++;
          ++v8;
          ++v12;
          if ( v14 == v15 )
            continue;
        }
        return 1;
        if ( v8 == a5 )
          return a2 != a3;
        v11 = *v8;
        result = 1;
      }
      while ( v11 != a8 );
    }
    if ( *v8 == v13 )
    {
      while ( 1 )
      {
        v16 = a3;
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
        return a2 != v16;
    }
    else
    {
      v16 = a3;
    }
    if ( *v8 == a8 )
      break;
    if ( v8 == a5 )
      goto LABEL_24;
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
      if ( a2 == v16 )
        return -1;
      ++a2;
    }
    if ( ++v18 == a5 )
      return 0;
  }
  if ( v18 != a5 )
  {
    if ( a2 != v16 )
    {
      v20 = *v18;
      v24 = *v18;
      if ( (unsigned __int8)*v18 == a6 )
      {
        v21 = (unsigned __int8 *)(v18 + 1);
        if ( v18 + 1 != a5 )
        {
          ++v18;
          v20 = *v21;
          v24 = *v21;
        }
      }
      v22 = v18 + 1;
      while ( 1 )
      {
        do
        {
          if ( *a2 == v20 )
            break;
          ++a2;
        }
        while ( a2 != v16 );
        v23 = a2++;
        if ( v23 == v16 )
          break;
        result = my_wildcmp_bin(a1, a2, a3: v16, a4: v22, a5, a6, a7, a8);
        if ( result <= 0 )
          return result;
        if ( a2 == a3 || *v22 == a8 )
          break;
        v16 = a3;
        v20 = v24;
      }
    }
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041BEC0
// Name: my_strnxfrm_8bit_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnxfrm_8bit_bin(
        int a1,
        unsigned __int8 *dst,
        unsigned int a3,
        unsigned int a4,
        unsigned __int8 *src,
        unsigned int count,
        unsigned int flags)
{
  unsigned int v7; // esi

  v7 = count;
  if ( count > a3 )
    v7 = a3;
  if ( v7 > a4 )
    v7 = a4;
  if ( dst != src )
    memcpy(dst, src, count: v7);
  return my_strxfrm_pad_desc_and_reverse(
           a1,
           str: dst,
           strend: &dst[v7],
           a4: (unsigned int)&dst[a3],
           a5: a4 - v7,
           flags,
           level: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0041BF20
// Name: my_instr_bin
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_instr_bin(int a1, char *a2, unsigned int a3, _BYTE *a4, unsigned int a5, _DWORD *a6, unsigned int a7)
{
  unsigned int v7; // ebx
  int v9; // edi
  char *v10; // esi
  char v11; // al
  char *v12; // eax
  char v13; // bl
  char v14; // dl
  bool v15; // zf
  int v16; // ecx
  int v17; // [esp+1Ch] [ebp+Ch]

  v7 = a5;
  if ( a5 > a3 )
    return 0;
  if ( a5 != 0 )
  {
    v9 = (int)&a2[a3 - a5 + 1];
    v10 = a2;
    v17 = v9;
LABEL_7:
    while ( v10 != (char *)v9 )
    {
      v11 = *v10++;
      if ( v11 == *a4 )
      {
        v12 = a4 + 1;
        while ( v12 != &a4[v7] )
        {
          v13 = *v12;
          v14 = (v12++)[v10 - (a4 + 1)];
          v15 = v14 == v13;
          v7 = a5;
          if ( !v15 )
          {
            v9 = v17;
            goto LABEL_7;
          }
        }
        if ( a7 != 0 )
        {
          v16 = v10 - a2 - 1;
          *a6 = 0;
          a6[1] = v16;
          a6[2] = v16;
          if ( a7 > 1 )
          {
            a6[4] = v16 + v7;
            a6[3] = v16;
            a6[5] = v7;
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
// Address: 0x00433C80
// Name: skip_trailing_space
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall skip_trailing_space@<eax>(unsigned int a1@<eax>, unsigned int a2@<edi>)
{
  unsigned int v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // eax

  v2 = a2 + a1;
  if ( a1 > 0x14 )
  {
    v3 = 4 * ((unsigned __int64)(int)v2 >> 2);
    v4 = 4 * ((unsigned __int64)((int)a2 + 3LL) >> 2);
    if ( v3 > a2 )
    {
      if ( v2 <= v3 )
      {
LABEL_6:
        if ( *(_BYTE *)(v2 - 1) == 32 && v4 < v3 && v2 > v4 )
        {
          do
          {
            if ( *(_DWORD *)(v2 - 4) != 538976288 )
              break;
            v2 -= 4;
          }
          while ( v2 > v4 );
        }
      }
      else
      {
        while ( *(_BYTE *)(v2 - 1) == 32 )
        {
          if ( --v2 <= v3 )
            goto LABEL_6;
        }
      }
    }
  }
  for ( ; v2 > a2; --v2 )
  {
    if ( *(_BYTE *)(v2 - 1) != 32 )
      break;
  }
  return v2;
}
