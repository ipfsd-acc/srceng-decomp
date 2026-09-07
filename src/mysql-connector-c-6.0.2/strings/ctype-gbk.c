// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-gbk.c
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004376D0
// Name: gbksortorder
// Source: json
//------------------------------------------------------------------------------
int __fastcall gbksortorder(__int16 a1)
{
  int v1; // eax

  if ( (unsigned __int8)a1 <= 0x7Fu )
    v1 = (unsigned __int8)a1 - 64;
  else
    v1 = (unsigned __int8)a1 - 65;
  return (unsigned __int16)gbk_order[190 * HIBYTE(a1) - 24510 + v1] + 33024;
}

//------------------------------------------------------------------------------
// Address: 0x00437710
// Name: _my_strnncoll_gbk_internal
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_gbk_internal(unsigned __int8 **a1, unsigned __int8 **a2, unsigned int length)
{
  unsigned int v3; // ebp
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // edi
  unsigned __int8 v6; // dl
  char v7; // cl
  unsigned __int8 v8; // bl
  char v9; // al
  int v10; // edx
  int v11; // ecx
  int v12; // edx
  char v13; // al
  int v15; // esi
  __int16 v16; // dx

  v3 = length;
  v4 = *a2;
  v5 = *a1;
  if ( length == 0 )
  {
LABEL_17:
    *a1 = v5;
    *a2 = v4;
    return 0;
  }
  while ( --v3 != 0 )
  {
    v6 = *v5;
    if ( *v5 < 0x81u || v6 == 0xFF )
      break;
    v7 = v5[1];
    if ( ((unsigned __int8)v7 < 0x40u || (unsigned __int8)v7 > 0x7Eu) && v7 >= -1 )
      break;
    v8 = *v4;
    if ( *v4 < 0x81u || v8 == 0xFF )
      break;
    v9 = v4[1];
    if ( ((unsigned __int8)v9 < 0x40u || (unsigned __int8)v9 > 0x7Eu) && v9 >= -1 )
      break;
    v10 = (unsigned __int8)v7 | (v6 << 8);
    v11 = (unsigned __int8)v9 | (v8 << 8);
    if ( v10 != v11 )
    {
      v15 = (unsigned __int16)gbksortorder(a1: v11);
      return (unsigned __int16)gbksortorder(a1: v16) - v15;
    }
    v5 += 2;
    v4 += 2;
    --v3;
LABEL_16:
    if ( v3 == 0 )
      goto LABEL_17;
  }
  v12 = *v5;
  v13 = *((_BYTE *)&sort_order_gbk + *v4++);
  ++v5;
  if ( *((_BYTE *)&sort_order_gbk + v12) == v13 )
    goto LABEL_16;
  return *((unsigned __int8 *)&sort_order_gbk + *(v5 - 1)) - *((unsigned __int8 *)&sort_order_gbk + *(v4 - 1));
}

//------------------------------------------------------------------------------
// Address: 0x00437810
// Name: _my_strnncoll_gbk
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_gbk(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *a,
        unsigned int a_length,
        const LoggingContext_t *b,
        unsigned int b_length,
        char b_is_prefix)
{
  unsigned int v6; // ebx
  unsigned int v7; // edi
  unsigned int v8; // esi
  int result; // eax
  unsigned int v10; // eax

  v6 = b_length;
  v7 = a_length;
  v8 = a_length;
  if ( a_length >= b_length )
    v8 = b_length;
  result = my_strnncoll_gbk_internal(a1: (unsigned __int8 **)&a, a2: (unsigned __int8 **)&b, length: v8);
  if ( result == 0 )
  {
    v10 = v8;
    if ( b_is_prefix == 0 )
      v10 = v7;
    return v10 - v6;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437850
// Name: my_strnncollsp_gbk
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_gbk(
        LIST_ENTRY32 *cs,
        const LoggingContext_t *a,
        unsigned int a_length,
        const LoggingContext_t *b,
        unsigned int b_length)
{
  unsigned int v5; // esi
  unsigned int v6; // edi
  unsigned int v7; // ebp
  int result; // eax
  int v9; // ebx
  const LoggingContext_t *v10; // ecx
  const LoggingContext_t *v11; // edx

  v5 = a_length;
  v6 = b_length;
  v7 = a_length;
  if ( a_length >= b_length )
    v7 = b_length;
  result = my_strnncoll_gbk_internal(a1: (unsigned __int8 **)&a, a2: (unsigned __int8 **)&b, length: v7);
  if ( result == 0 && v5 != v6 )
  {
    v9 = 1;
    if ( v5 >= v6 )
    {
      v10 = a;
    }
    else
    {
      v10 = b;
      v5 = v6;
      v9 = -1;
    }
    v11 = (const LoggingContext_t *)((char *)v10 + v5 - v7);
    if ( v10 < v11 )
    {
      while ( LOBYTE(v10->m_ChannelID) == 32 )
      {
        v10 = (const LoggingContext_t *)((char *)v10 + 1);
        if ( v10 >= v11 )
          return result;
      }
      if ( LOBYTE(v10->m_ChannelID) < 0x20u )
        return -v9;
      return v9;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004378C0
// Name: my_strnxfrm_gbk
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnxfrm_gbk(
        int a1,
        unsigned __int8 *strend,
        int a3,
        int a4,
        unsigned __int16 *a5,
        int a6,
        unsigned int flags)
{
  unsigned __int8 *v7; // esi
  unsigned __int16 *v8; // edi
  unsigned __int8 *v9; // ebx
  unsigned int v10; // eax
  __int16 v11; // ax
  unsigned __int8 v12; // al
  int v14; // [esp+20h] [ebp+Ch]

  v7 = strend;
  v8 = a5;
  v9 = &strend[a3];
  v10 = (unsigned int)a5 + a6;
  v14 = *(_DWORD *)(a1 + 44);
  if ( strend < v9 )
  {
    while ( (unsigned int)v8 < v10 && a4 != 0 )
    {
      if ( (*(int (__cdecl **)(int, unsigned __int16 *, unsigned int))(*(_DWORD *)(a1 + 100) + 4))(a1, a2: v8, a3: v10) != 0 )
      {
        v11 = gbksortorder(a1: _byteswap_ushort(*v8));
        *v7++ = HIBYTE(v11);
        if ( v7 < v9 )
          *v7++ = v11;
        ++v8;
      }
      else
      {
        v12 = v14 != 0 ? *(_BYTE *)(*(unsigned __int8 *)v8 + v14) : *(_BYTE *)v8;
        v8 = (unsigned __int16 *)((char *)v8 + 1);
        *v7++ = v12;
      }
      --a4;
      if ( v7 >= v9 )
        break;
      v10 = (unsigned int)a5 + a6;
    }
  }
  return my_strxfrm_pad_desc_and_reverse(a1, str: strend, strend: v7, a4: (unsigned int)v9, a5: a4, flags, level: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00437990
// Name: my_like_range_gbk
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_gbk(
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
  char *v14; // ebx
  unsigned int v15; // eax
  char *v17; // ebp
  char v18; // al
  char v19; // bl
  char v20; // bl
  char v21; // al
  int v22; // edi
  char v23; // al
  char v24; // bl
  unsigned int v26; // eax
  tagShutdownType end; // [esp+10h] [ebp-4h]
  char *min_enda; // [esp+1Ch] [ebp+8h]
  unsigned int charlena; // [esp+20h] [ebp+Ch]

  v11 = min_org;
  v12 = min_end;
  v13 = &min_end[charlen];
  v14 = &min_org[res_length];
  v15 = res_length / a1[11].Flink;
  end = (tagShutdownType)v13;
  min_enda = &min_org[res_length];
  charlena = v15;
  if ( v12 != v13 )
  {
    v17 = v12 + 1;
    do
    {
      if ( v11 == v14 || v15 == 0 )
        break;
      if ( v17 == v13
        || (v18 = *v12, (unsigned __int8)*v12 < 0x81u)
        || v18 == -1
        || ((v19 = *v17, (unsigned __int8)*v17 < 0x40u) || (unsigned __int8)v19 > 0x7Eu) && v19 >= -1 )
      {
        v21 = *v12;
        v22 = *v12;
        if ( v22 == escape && v17 != (char *)end )
        {
          v23 = *++v12;
          ++v17;
          if ( (unsigned __int8)v23 >= 0x81u && v23 != -1 )
          {
            if ( (v24 = *v17, (unsigned __int8)*v17 >= 0x40u) && (unsigned __int8)v24 <= 0x7Eu || v24 < -1 )
            {
              *max_str = v23;
              *v11++ = v23;
              ++max_str;
            }
          }
          if ( v11 >= min_enda )
            goto LABEL_27;
          v21 = *v12;
          goto LABEL_25;
        }
        if ( v22 != w_one )
        {
          if ( v22 == w_many )
          {
            if ( (a1[1].Blink & 0x10) != 0 )
              v26 = v11 - min_org;
            else
              v26 = res_length;
            *min_length = v26;
            *max_length = res_length;
            do
            {
              *v11++ = 0;
              *max_str++ = -1;
            }
            while ( v11 != min_enda );
            return 0;
          }
LABEL_25:
          *max_str = v21;
          *v11 = v21;
          goto LABEL_26;
        }
        *v11 = 0;
        *max_str = -1;
      }
      else
      {
        *max_str = v18;
        *v11 = v18;
        v20 = *++v12;
        ++max_str;
        ++v11;
        *max_str = v20;
        ++v17;
        *v11 = v20;
      }
LABEL_26:
      ++v11;
      ++max_str;
LABEL_27:
      v13 = (char *)end;
      v14 = &min_org[res_length];
      ++v12;
      v15 = charlena - 1;
      ++v17;
      --charlena;
    }
    while ( v12 != (char *)end );
  }
  *max_length = v11 - min_org;
  for ( *min_length = v11 - min_org; v11 != v14; ++max_str )
  {
    *max_str = 32;
    *v11++ = 32;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00437B10
// Name: ismbchar_gbk
// Source: json
//------------------------------------------------------------------------------
int __cdecl ismbchar_gbk(int a1, _BYTE *a2, int a3)
{
  char v3; // al

  if ( *a2 < 0x81u || *a2 == 0xFF || a3 - (int)a2 <= 1 )
    return 0;
  if ( ((unsigned __int8)(v3 = a2[1]) < 0x40u || (unsigned __int8)v3 > 0x7Eu) && v3 >= -1 )
    return 0;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00437B50
// Name: mbcharlen_gbk
// Source: json
//------------------------------------------------------------------------------
int __cdecl mbcharlen_gbk(LIST_ENTRY32 *cs, char c)
{
  return 2 - ((unsigned __int8)(c + 127) > 0x7Du);
}

//------------------------------------------------------------------------------
// Address: 0x00437B70
// Name: func_gbk_uni_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_gbk_uni_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 33088) > 0x7D0F )
    return 0;
  else
    return (unsigned __int16)word_5104D0[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00437B90
// Name: func_uni_gbk_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_uni_gbk_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 164) <= 0x3AD )
    return (unsigned __int16)word_530028[a1];
  if ( (unsigned int)(a1 - 8208) <= 0x302 )
    return (unsigned __int16)word_52C8B0[a1];
  if ( (unsigned int)(a1 - 9312) <= 0x1E2 )
    return (unsigned __int16)word_52C618[a1];
  if ( (unsigned int)(a1 - 12288) <= 0x129 )
    return (unsigned __int16)word_52B2A0[a1];
  if ( (unsigned int)(a1 - 12832) <= 0x83 )
    return (unsigned __int16)word_52B0B8[a1];
  if ( (unsigned int)(a1 - 13198) <= 0x47 )
    return (unsigned __int16)word_52AEE4[a1];
  if ( (unsigned int)(a1 - 19968) <= 0x51A5 )
    return (unsigned __int16)word_527A90[a1];
  if ( (unsigned int)(a1 - 63788) <= 0xFD )
    return (unsigned __int16)word_51C788[a1];
  if ( (unsigned int)(a1 - 65072) > 0x1B5 )
    return 0;
  return (unsigned __int16)word_51BF80[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00437C60
// Name: my_wc_mb_gbk
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_gbk(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  int result; // eax

  if ( s >= e )
    return -101;
  if ( (unsigned int)wc >= 0x80 )
  {
    result = func_uni_gbk_onechar(a1: (int)wc);
    if ( result != 0 )
    {
      if ( s + 2 <= e )
      {
        s[1] = result;
        *s = BYTE1(result);
        return 2;
      }
      else
      {
        return -102;
      }
    }
  }
  else
  {
    *s = (unsigned __int8)wc;
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00437CC0
// Name: my_mb_wc_gbk
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_gbk(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
{
  unsigned int v5; // ecx
  int v6; // eax

  if ( (unsigned int)a3 >= a4 )
    return -101;
  v5 = *a3;
  if ( v5 >= 0x80 )
  {
    if ( (unsigned int)(a3 + 2) <= a4 )
    {
      v6 = func_gbk_uni_onechar(a1: (v5 << 8) + a3[1]);
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
    *a2 = v5;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00437D20
// Name: my_well_formed_len_gbk
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_gbk(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, unsigned int pos, int *error, ...)
{
  unsigned int v5; // edx
  const char *v6; // eax
  char v7; // cl
  char v8; // cl

  v5 = pos;
  v6 = b;
  *error = 0;
  if ( pos != 0 )
  {
    while ( 1 )
    {
      --v5;
      if ( (unsigned int)v6 >= e )
        break;
      v7 = *v6;
      if ( *v6 >= 0x80u )
      {
        if ( (unsigned int)v6 >= e - 1
          || (unsigned __int8)v7 < 0x81u
          || v7 == -1
          || ((unsigned __int8)(v8 = v6[1]) < 0x40u || (unsigned __int8)v8 > 0x7Eu) && v8 >= -1 )
        {
          *error = 1;
          return v6 - b;
        }
        v6 += 2;
      }
      else
      {
        ++v6;
      }
      if ( v5 == 0 )
        return v6 - b;
    }
  }
  return v6 - b;
}
