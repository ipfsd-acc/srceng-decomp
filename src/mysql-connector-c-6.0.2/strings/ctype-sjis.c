// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-sjis.c
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041E4D0
// Name: mbcharlen_sjis
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl mbcharlen_sjis(LIST_ENTRY32 *cs, unsigned __int8 c)
{
  if ( (c < 0x81u || c > 0x9Fu) && (unsigned __int8)(c + 32) > 0x1Cu )
    return 1;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x004370B0
// Name: ismbchar_sjis
// Source: json
//------------------------------------------------------------------------------
int __cdecl ismbchar_sjis(int a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 v3; // al
  char v4; // al

  v3 = *a2;
  if ( (*a2 < 0x81u || v3 > 0x9Fu) && (v3 < 0xE0u || v3 > 0xFCu) )
    return 0;
  if ( a3 - (int)a2 <= 1 )
    return 0;
  if ( ((unsigned __int8)(v4 = a2[1]) < 0x40u || (unsigned __int8)v4 > 0x7Eu) && v4 > -4 )
    return 0;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x004370F0
// Name: my_strnncoll_sjis_internal
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_sjis_internal(
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
        if ( *((_BYTE *)&sort_order_sjis + *v10) != *((_BYTE *)&sort_order_sjis + *v7) )
        {
          v12 = *((unsigned __int8 *)&sort_order_sjis + *v7);
          v11 = *((unsigned __int8 *)&sort_order_sjis + *v10);
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
// Address: 0x004371B0
// Name: my_strnncoll_sjis
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_sjis(
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
  result = my_strnncoll_sjis_internal(
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
// Address: 0x004371F0
// Name: my_strnncollsp_sjis
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_sjis(
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
  result = my_strnncoll_sjis_internal(
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
// Address: 0x00437270
// Name: my_like_range_sjis
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_sjis(
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
  char *v11; // esi
  unsigned __int8 *v12; // edi
  char *v13; // ecx
  char *v14; // ebp
  char *v15; // edx
  unsigned __int8 *v16; // ebx
  bool v17; // zf
  signed __int8 v18; // al
  unsigned __int8 v19; // al
  unsigned int v21; // eax
  tagShutdownType end; // [esp+10h] [ebp-4h]
  char *min_enda; // [esp+1Ch] [ebp+8h]
  unsigned int charlena; // [esp+20h] [ebp+Ch]

  v11 = min_org;
  v12 = (unsigned __int8 *)min_end;
  v13 = &min_end[charlen];
  v14 = &min_org[res_length];
  v15 = max_str;
  end = (tagShutdownType)v13;
  min_enda = &min_org[res_length];
  charlena = res_length / a1[11].Flink;
  if ( v12 < (unsigned __int8 *)v13 )
  {
    v16 = v12 + 1;
    while ( 1 )
    {
      if ( v11 >= v14 || charlena == 0 )
        goto LABEL_22;
      v17 = ismbchar_sjis((int)a1, a2: v12, a3: (int)v13) == 0;
      v18 = *v12;
      if ( !v17 )
        break;
      if ( v18 != escape || (unsigned int)v16 >= end )
      {
        if ( v18 == w_one )
        {
          v14 = &min_org[res_length];
          *v11 = 0;
          *v15 = -1;
LABEL_20:
          ++v11;
          ++v15;
          ++v12;
          ++v16;
          goto LABEL_21;
        }
        if ( v18 == w_many )
        {
          if ( (a1[1].Blink & 0x10) != 0 )
            v21 = v11 - min_org;
          else
            v21 = res_length;
          *min_length = v21;
          *max_length = res_length;
          do
          {
            *v11++ = 0;
            *v15++ = -1;
          }
          while ( v11 < min_enda );
          return 0;
        }
        v14 = &min_org[res_length];
LABEL_19:
        *v15 = v18;
        *v11 = v18;
        goto LABEL_20;
      }
      ++v12;
      ++v16;
      if ( ismbchar_sjis((int)a1, a2: v12, a3: end) != 0 )
      {
        v19 = *v12;
        *v15 = *v12;
        *v11++ = v19;
        ++v15;
        ++v12;
        ++v16;
      }
      v14 = &min_org[res_length];
      if ( v11 < min_enda )
      {
        v18 = *v12;
        goto LABEL_19;
      }
LABEL_21:
      --charlena;
      if ( (unsigned int)v12 >= end )
        goto LABEL_22;
      v13 = (char *)end;
    }
    *v15 = v18;
    *v11++ = v18;
    ++v15;
    ++v12;
    ++v16;
    if ( v11 >= v14 )
      goto LABEL_21;
    v18 = *v12;
    goto LABEL_19;
  }
LABEL_22:
  *max_length = v11 - min_org;
  for ( *min_length = v11 - min_org; v11 != v14; ++v15 )
  {
    *v15 = 32;
    *v11++ = 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004373E0
// Name: func_sjis_uni_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_sjis_uni_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 161) <= 0x3E )
    return *(unsigned __int16 *)((char *)&loc_50499D + 2 * a1 + 1);
  if ( (unsigned int)(a1 - 33088) <= 0x37E )
    return (unsigned __int16)word_4F48E0[a1];
  if ( (unsigned int)(a1 - 34975) <= 0x175D )
    return (unsigned __int16)word_4F4122[a1];
  if ( (unsigned int)(a1 - 57408) > 0xA64 )
    return 0;
  return (unsigned __int16)word_4EC0A0[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00437440
// Name: func_uni_sjis_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_uni_sjis_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 92) <= 0x9B )
    return (unsigned __int16)word_509538[a1];
  if ( (unsigned int)(a1 - 913) <= 0xC0 )
    return (unsigned __int16)word_509006[a1];
  if ( (unsigned int)(a1 - 8208) <= 0x302 )
    return (unsigned __int16)word_505890[a1];
  if ( (unsigned int)(a1 - 9472) <= 0x16F )
    return (unsigned __int16)word_5054B8[a1];
  if ( (unsigned int)(a1 - 12288) <= 0xFE )
    return (unsigned __int16)word_504198[a1];
  if ( (unsigned int)(a1 - 19968) <= 0x4681 )
    return (unsigned __int16)word_500798[a1];
  if ( (unsigned int)(a1 - 38263) <= 0xA29 )
    return (unsigned __int16)word_5005B2[a1];
  if ( (unsigned int)(a1 - 65281) > 0xE4 )
    return 0;
  return (unsigned __int16)word_4F46F6[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00437500
// Name: my_wc_mb_sjis
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_sjis(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  int result; // eax

  if ( s >= e )
    return -101;
  LOBYTE(result) = (_BYTE)wc;
  if ( (int)wc < 128 )
  {
    if ( wc == (const char *)92 )
    {
      LOWORD(result) = -32417;
      goto mb;
    }
LABEL_6:
    *s = result;
    return 1;
  }
  result = func_uni_sjis_onechar(a1: (int)wc);
  if ( result == 0 )
    return result;
  if ( (unsigned int)(result - 161) <= 0x3E )
    goto LABEL_6;
mb:
  if ( s + 2 > e )
    return -102;
  s[1] = result;
  *s = BYTE1(result);
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00437570
// Name: my_mb_wc_sjis
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_sjis(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
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
        v6 = func_sjis_uni_onechar(a1: (v5 << 8) + a3[1]);
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
      *a2 = func_sjis_uni_onechar(a1: v5);
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
// Address: 0x004375F0
// Name: my_numcells_sjis
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_numcells_sjis(int a1, unsigned __int8 *a2, unsigned int a3)
{
  unsigned __int8 *v3; // ecx
  int result; // eax
  unsigned __int8 v5; // dl

  v3 = a2;
  result = 0;
  while ( (unsigned int)v3 < a3 )
  {
    v5 = *v3;
    if ( *v3 >= 0xA1u && v5 <= 0xDFu || v5 <= 0x7Fu )
    {
      ++result;
      ++v3;
    }
    else
    {
      result += 2;
      v3 += 2;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437630
// Name: my_well_formed_len_sjis
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_sjis(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, unsigned int pos, int *error, ...)
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
      if ( *v5 < 0x80u )
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
