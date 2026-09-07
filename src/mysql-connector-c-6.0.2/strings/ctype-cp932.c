// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-cp932.c
// Functions: 9
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041E4F0
// Name: my_strnncoll_cp932_internal
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_cp932_internal(
        LIST_ENTRY32 *a1,
        unsigned __int8 **a2,
        unsigned int a_length,
        unsigned __int8 **a4,
        unsigned int b_length)
{
  unsigned __int8 *v5; // edx
  LIST_ENTRY32 *v6; // ebp
  unsigned __int8 *v7; // esi
  unsigned int v8; // edi
  unsigned int v9; // ebx
  unsigned __int8 *v10; // edx
  int v11; // eax
  int v12; // ecx

  v5 = *a2;
  v6 = a1;
  v7 = *a4;
  v8 = (unsigned int)&(*a2)[a_length];
  v9 = (unsigned int)&(*a4)[b_length];
  if ( (unsigned int)*a2 < v8 )
  {
    while ( (unsigned int)v7 < v9 )
    {
      if ( ismbchar_sjis(a1: (int)v6, a2: v5, a3: v8) != 0 && ismbchar_sjis(a1: (int)v6, a2: v7, a3: v9) != 0 )
      {
        v11 = v10[1] | (*v10 << 8);
        v12 = v7[1] | (*v7 << 8);
        if ( v11 != v12 )
          return v11 - v12;
        v6 = a1;
        v5 = v10 + 2;
        v7 += 2;
      }
      else
      {
        if ( *((_BYTE *)&sort_order_cp932 + *v10) != *((_BYTE *)&sort_order_cp932 + *v7) )
        {
          v12 = *((unsigned __int8 *)&sort_order_cp932 + *v7);
          v11 = *((unsigned __int8 *)&sort_order_cp932 + *v10);
          return v11 - v12;
        }
        v5 = v10 + 1;
        ++v7;
      }
      if ( (unsigned int)v5 >= v8 )
        break;
    }
  }
  *a2 = v5;
  *a4 = v7;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E5B0
// Name: my_strnncoll_cp932
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_cp932(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *a,
        unsigned int a_length,
        const LoggingContext_t *b,
        unsigned int b_length,
        char b_is_prefix)
{
  unsigned int v6; // esi
  unsigned int v7; // edi
  int result; // eax

  v6 = a_length;
  v7 = b_length;
  result = my_strnncoll_cp932_internal(
             a1: cs,
             a2: (unsigned __int8 **)&a,
             a_length,
             a4: (unsigned __int8 **)&b,
             b_length);
  if ( b_is_prefix != 0 && v6 > v7 )
    v6 = v7;
  if ( result == 0 )
    return v6 - v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E5F0
// Name: my_strnncollsp_cp932
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_cp932(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *a,
        unsigned int a_length,
        const LoggingContext_t *b,
        unsigned int b_length)
{
  const LoggingContext_t *v5; // esi
  const LoggingContext_t *v6; // edi
  int result; // eax
  const LoggingContext_t *v8; // ecx
  int v9; // edx
  bool v10; // cf

  v5 = (const LoggingContext_t *)((char *)a + a_length);
  v6 = (const LoggingContext_t *)((char *)b + b_length);
  result = my_strnncoll_cp932_internal(
             a1: cs,
             a2: (unsigned __int8 **)&a,
             a_length,
             a4: (unsigned __int8 **)&b,
             b_length);
  if ( result == 0 )
  {
    v8 = a;
    if ( a != v5 || b != v6 )
    {
      v9 = 1;
      v10 = a < v5;
      if ( a == v5 )
      {
        v5 = v6;
        v8 = b;
        v9 = -1;
        result = 0;
        v10 = b < v6;
      }
      if ( v10 )
      {
        while ( LOBYTE(v8->m_ChannelID) == 32 )
        {
          v8 = (const LoggingContext_t *)((char *)v8 + 1);
          if ( v8 >= v5 )
            return result;
        }
        if ( LOBYTE(v8->m_ChannelID) < 0x20u )
          return -v9;
        return v9;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E670
// Name: my_like_range_cp932
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_cp932(
        LIST_ENTRY32 *a1,
        char *min_end,
        tagShutdownType end,
        int escape,
        int w_one,
        int w_many,
        unsigned int res_length,
        char *min_org,
        char *max_str,
        unsigned int *min_length,
        unsigned int *max_length)
{
  char *v11; // edx
  unsigned __int8 *v12; // esi
  char *v13; // eax
  char *v14; // ebp
  unsigned __int8 *v16; // ebx
  bool v17; // zf
  char v18; // al
  unsigned __int8 v19; // al
  char *min_enda; // [esp+18h] [ebp+8h]
  tagShutdownType enda; // [esp+1Ch] [ebp+Ch]

  v11 = min_org;
  v12 = (unsigned __int8 *)min_end;
  v13 = &min_end[end];
  v14 = &min_org[res_length];
  enda = (tagShutdownType)v13;
  min_enda = &min_org[res_length];
  if ( v12 < (unsigned __int8 *)v13 )
  {
    v16 = v12 + 1;
    while ( 1 )
    {
      if ( v11 >= v14 )
        goto LABEL_21;
      v17 = ismbchar_sjis((int)a1, a2: v12, a3: (int)v13) == 0;
      v18 = *v12;
      if ( !v17 )
        break;
      if ( v18 != escape || (unsigned int)v16 >= enda )
      {
        if ( v18 == w_one )
        {
          v14 = &min_org[res_length];
          *v11 = 0;
          *max_str = -1;
LABEL_19:
          ++v11;
          ++max_str;
          ++v12;
          ++v16;
          goto LABEL_20;
        }
        if ( v18 == w_many )
        {
          *min_length = v11 - min_org;
          *max_length = res_length;
          do
          {
            *v11++ = 0;
            *max_str++ = -1;
          }
          while ( v11 < min_enda );
          return 0;
        }
        v14 = &min_org[res_length];
LABEL_18:
        *max_str = v18;
        *v11 = v18;
        goto LABEL_19;
      }
      ++v12;
      ++v16;
      if ( ismbchar_sjis((int)a1, a2: v12, a3: enda) != 0 )
      {
        v19 = *v12;
        *max_str = *v12;
        *v11++ = v19;
        ++max_str;
        ++v12;
        ++v16;
      }
      v14 = &min_org[res_length];
      if ( v11 < min_enda )
      {
        v18 = *v12;
        goto LABEL_18;
      }
LABEL_20:
      if ( (unsigned int)v12 >= enda )
        goto LABEL_21;
      v13 = (char *)enda;
    }
    *max_str = v18;
    *v11++ = v18;
    ++max_str;
    ++v12;
    ++v16;
    if ( v11 >= v14 )
      goto LABEL_20;
    v18 = *v12;
    goto LABEL_18;
  }
LABEL_21:
  *max_length = v11 - min_org;
  for ( *min_length = v11 - min_org; v11 < v14; ++max_str )
  {
    *max_str = 32;
    *v11++ = 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E7B0
// Name: func_cp932_uni_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_cp932_uni_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 161) <= 0x3E )
    return *(unsigned __int16 *)((char *)&loc_4AD4DD + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 33088) <= 0x37E )
    return (unsigned __int16)word_49D420[a1];
  if ( (unsigned int)(a1 - 34624) <= 0x5C )
    return (unsigned __int16)word_49CF20[a1];
  if ( (unsigned int)(a1 - 34975) <= 0x175D )
    return (unsigned __int16)word_49CD22[a1];
  if ( (unsigned int)(a1 - 57408) <= 0xA64 )
    return (unsigned __int16)word_494CA0[a1];
  if ( (unsigned int)(a1 - 60736) <= 0x1BC )
    return (unsigned __int16)word_494770[a1];
  if ( (unsigned int)(a1 - 61504) <= 0x9BC )
    return (unsigned __int16)word_4944F0[a1];
  if ( (unsigned int)(a1 - 64064) > 0x20B )
    return 0;
  return (unsigned __int16)word_494470[a1];
}

//------------------------------------------------------------------------------
// Address: 0x0041E870
// Name: func_uni_cp932_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_uni_cp932_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 92) <= 0x9B )
    return (unsigned __int16)word_4B3C50[a1];
  if ( (unsigned int)(a1 - 913) <= 0xC0 )
    return (unsigned __int16)word_4B371E[a1];
  if ( (unsigned int)(a1 - 8208) <= 0x463 )
    return (unsigned __int16)word_4AFFA8[a1];
  if ( (unsigned int)(a1 - 9472) <= 0x16F )
    return (unsigned __int16)word_4AFE90[a1];
  if ( (unsigned int)(a1 - 12288) <= 0xFE )
    return (unsigned __int16)word_4AEB70[a1];
  if ( (unsigned int)(a1 - 12848) <= 0x19D )
    return (unsigned __int16)word_4AE910[a1];
  if ( (unsigned int)(a1 - 19968) <= 0x4681 )
    return (unsigned __int16)word_4AB4B0[a1];
  if ( (unsigned int)(a1 - 38263) <= 0xA29 )
    return (unsigned __int16)word_4AB2CA[a1];
  if ( (unsigned int)(a1 - 57344) <= 0x757 )
    return (unsigned __int16)word_4A3210[a1];
  if ( (unsigned int)(a1 - 63776) <= 0x10D )
    return (unsigned __int16)word_4A0E80[a1];
  if ( (unsigned int)(a1 - 65281) > 0xE4 )
    return 0;
  return (unsigned __int16)word_4A04DE[a1];
}

//------------------------------------------------------------------------------
// Address: 0x0041E970
// Name: my_wc_mb_cp932
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_cp932(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  int result; // eax

  if ( s >= e )
    return -101;
  LOBYTE(result) = (_BYTE)wc;
  if ( (int)wc < 128 )
    goto LABEL_4;
  result = func_uni_cp932_onechar(a1: (int)wc);
  if ( result != 0 )
  {
    if ( (unsigned int)(result - 161) <= 0x3E )
    {
LABEL_4:
      *s = result;
      return 1;
    }
    s[1] = result;
    *s = BYTE1(result);
    return 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0041E9C0
// Name: my_mb_wc_cp932
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_cp932(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v5; // ecx
  int v6; // eax

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v5 = *a3;
  if ( v5 >= 0x80 )
  {
    if ( v5 - 161 > 0x3E )
    {
      if ( (unsigned int)(a3 + 2) <= a4 )
      {
        v6 = func_cp932_uni_onechar(a1: (v5 << 8) + a3[1]);
        *a2 = v6;
        return 4 * (v6 != 0) - 2;
      }
      else
      {
        return -102;
      }
    }
    else
    {
      *a2 = func_cp932_uni_onechar(a1: v5);
      return 1;
    }
  }
  else
  {
    *a2 = v5;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041EA40
// Name: my_well_formed_len_cp932
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_cp932(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, unsigned int pos, int *error, ...)
{
  const char *v5; // eax
  unsigned int v6; // edi
  int v7; // esi
  char v8; // cl
  char v9; // dl

  v5 = b;
  v6 = pos;
  *error = 0;
  if ( pos != 0 )
  {
    v7 = e - (_DWORD)b;
    while ( 1 )
    {
      --v6;
      if ( (unsigned int)v5 >= e )
        return v5 - b;
      v8 = *v5;
      if ( *v5 >= 0 )
        goto LABEL_16;
      if ( ((unsigned __int8)v8 < 0x81u || (unsigned __int8)v8 > 0x9Fu)
        && ((unsigned __int8)v8 < 0xE0u || (unsigned __int8)v8 > 0xFCu) )
      {
        break;
      }
      if ( v7 <= 1 )
        break;
      v9 = v5[1];
      if ( ((unsigned __int8)v9 < 0x40u || (unsigned __int8)v9 > 0x7Eu) && v9 > -4 )
        break;
      v5 += 2;
      v7 -= 2;
LABEL_17:
      if ( v6 == 0 )
        return v5 - b;
    }
    if ( (unsigned __int8)v8 < 0xA1u || (unsigned __int8)v8 > 0xDFu )
    {
      *error = 1;
      return v5 - b;
    }
LABEL_16:
    ++v5;
    --v7;
    goto LABEL_17;
  }
  return v5 - b;
}
