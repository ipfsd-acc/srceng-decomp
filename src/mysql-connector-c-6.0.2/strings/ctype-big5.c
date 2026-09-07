// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-big5.c
// Functions: 13
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0043AC30
// Name: big5strokexfrm
// Source: json
//------------------------------------------------------------------------------
int __usercall big5strokexfrm@<eax>(unsigned __int16 a1@<ax>)
{
  int v1; // ecx
  int v3; // edx

  v1 = 42048;
  if ( a1 != 0xA440 && a1 != 0xA441 )
  {
    if ( a1 >= 0xA442u && a1 <= 0xA453u || (unsigned __int16)(a1 + 14016) <= 4u )
      return 42050;
    if ( a1 >= 0xA454u && a1 <= 0xA47Eu || (unsigned __int16)(a1 + 14011) <= 7u )
      return 42068;
    if ( a1 >= 0xA4A1u && a1 <= 0xA4FDu || (unsigned __int16)(a1 + 14003) <= 0x15u )
      return 42145;
    if ( a1 >= 0xA4FEu && a1 <= 0xA5DFu || (unsigned __int16)(a1 + 13981) <= 0x47u )
      return 42238;
    if ( a1 >= 0xA5E0u && a1 <= 0xA6E9u || (unsigned __int16)(a1 + 13909) <= 0xAEu )
      return 42464;
    if ( a1 >= 0xA6EAu && a1 <= 0xA8C2u || (unsigned __int16)(a1 + 13734) <= 0x156u )
      return 42730;
    if ( a1 == 0xA260 || a1 >= 0xA8C3u && a1 <= 0xAB44u || a1 >= 0xCBB1u && a1 <= 0xCDDCu )
      return 43203;
    if ( a1 == 0xA259 || a1 == 0xF9DA || a1 >= 0xAB45u && a1 <= 0xADBBu || a1 >= 0xCDDDu && a1 <= 0xD0C7u )
      return 43845;
    if ( a1 == 0xA25A || a1 >= 0xADBCu && a1 <= 0xB0ADu || a1 >= 0xD0C8u && a1 <= 0xD44Au )
      return 44476;
    if ( a1 == 0xA25B || a1 == 0xA25C || a1 >= 0xB0AEu && a1 <= 0xB3C2u || a1 >= 0xD44Bu && a1 <= 0xD850u )
      return 45230;
    if ( a1 == 0xF9DB || a1 >= 0xB3C3u && a1 <= 0xB6C2u || a1 >= 0xD851u && a1 <= 0xDCB0u )
      return 46019;
    if ( a1 == 0xA25D
      || a1 == 0xA25F
      || a1 == 0xC6A1
      || a1 == 0xF9D6
      || a1 == 0xF9D8
      || a1 >= 0xB6C3u && a1 <= 0xB9ABu
      || a1 >= 0xDCB1u && a1 <= 0xE0EFu )
    {
      return 46787;
    }
    if ( a1 == 0xF9DC || a1 >= 0xB9ACu && a1 <= 0xBBF4u || a1 >= 0xE0F0u && a1 <= 0xE4E5u )
      return 47532;
    if ( a1 == 0xA261 || a1 >= 0xBBF5u && a1 <= 0xBEA6u || a1 >= 0xE4E6u && a1 <= 0xE8F3u )
      return 48117;
    if ( a1 == 0xA25E
      || a1 == 0xF9D7
      || a1 == 0xF9D9
      || a1 >= 0xBEA7u && a1 <= 0xC074u
      || a1 >= 0xE8F4u && a1 <= 0xECB8u )
    {
      return 48807;
    }
    if ( a1 >= 0xC075u && a1 <= 0xC24Eu || (unsigned __int16)(a1 + 4935) <= 0x2FDu )
      return 49269;
    if ( a1 >= 0xC24Fu && a1 <= 0xC35Eu || (unsigned __int16)(a1 + 4169) <= 0x233u )
      return 49743;
    if ( a1 >= 0xC35Fu && a1 <= 0xC454u || (unsigned __int16)(a1 + 3605) <= 0x211u )
      return 50015;
    if ( a1 >= 0xC455u && a1 <= 0xC4D6u || (unsigned __int16)(a1 + 3075) <= 0x1C2u )
      return 50261;
    if ( a1 >= 0xC4D7u && a1 <= 0xC56Au || (unsigned __int16)(a1 + 2624) <= 0x115u )
      return 50391;
    if ( a1 >= 0xC56Bu && a1 <= 0xC5C7u || (unsigned __int16)(a1 + 2346) <= 0xF9u )
      return 50539;
    if ( a1 >= 0xC5C8u && a1 <= 0xC5F0u || (unsigned __int16)(a1 + 2096) <= 0xD4u )
      return 50632;
    if ( a1 >= 0xC5F1u && a1 <= 0xC654u || (unsigned __int16)(a1 + 1883) <= 0x48u )
      return 50673;
    if ( a1 >= 0xC655u && a1 <= 0xC664u || (unsigned __int16)(a1 + 1810) <= 0x7Cu )
      return 50773;
    if ( a1 >= 0xC665u && a1 <= 0xC66Bu || (unsigned __int16)(a1 + 1685) <= 0x36u )
      return 50789;
    if ( a1 >= 0xC66Cu && a1 <= 0xC675u || (unsigned __int16)(a1 + 1630) <= 0x17u )
      return 50796;
    if ( a1 >= 0xC676u && a1 <= 0xC678u || (unsigned __int16)(a1 + 1606) <= 0xBu )
      return 50806;
    if ( a1 >= 0xC679u && a1 <= 0xC67Cu || (unsigned __int16)(a1 + 1593) <= 4u )
      return 50809;
    if ( a1 == 0xC67D || a1 >= 0xF9CCu && a1 <= 0xF9CFu )
      return 50813;
    v1 = 63952;
    if ( a1 != 0xF9D0 )
    {
      v3 = 50814;
      if ( a1 == 0xC67E )
        return v3;
      if ( a1 == 0xF9D1 )
        return v3;
      v3 = 63942;
      if ( a1 == 0xF9C6 )
        return v3;
      if ( a1 == 0xF9D2 )
        return v3;
      v3 = 63955;
      if ( a1 == 0xF9D3 )
        return v3;
      v1 = 63956;
      if ( a1 != 0xF9D4 )
      {
        v3 = 63957;
        if ( a1 != 0xF9D5 )
          return 41280;
        return v3;
      }
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x0043B2A0
// Name: my_strnncoll_big5_internal
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_big5_internal(unsigned __int8 **a1, unsigned __int8 **a2, unsigned int length)
{
  unsigned int v3; // ebp
  unsigned __int8 *v4; // esi
  unsigned __int8 *v5; // edi
  unsigned __int8 v6; // bl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // dl
  unsigned __int8 v9; // al
  int v10; // edx
  int v11; // eax

  v3 = length;
  v4 = *a2;
  v5 = *a1;
  if ( length == 0 )
  {
LABEL_20:
    *a1 = v5;
    *a2 = v4;
    return 0;
  }
  while ( --v3 != 0 )
  {
    v6 = *v5;
    if ( *v5 < 0xA1u || v6 > 0xF9u )
      break;
    v7 = v5[1];
    if ( (v7 < 0x40u || v7 > 0x7Eu) && (v7 < 0xA1u || v7 == 0xFF) )
      break;
    v8 = *v4;
    if ( *v4 < 0xA1u || v8 > 0xF9u )
      break;
    v9 = v4[1];
    if ( (v9 < 0x40u || v9 > 0x7Eu) && (v9 < 0xA1u || v9 == 0xFF) )
      break;
    if ( v6 != v8 || v7 != v9 )
      return (v5[1] | (*v5 << 8)) - (v4[1] | (*v4 << 8));
    v5 += 2;
    v4 += 2;
    --v3;
LABEL_19:
    if ( v3 == 0 )
      goto LABEL_20;
  }
  v10 = *v4;
  v11 = *v5;
  ++v4;
  ++v5;
  if ( *((_BYTE *)&sort_order_big5 + v11) == *((_BYTE *)&sort_order_big5 + v10) )
    goto LABEL_19;
  return *((unsigned __int8 *)&sort_order_big5 + *(v5 - 1)) - *((unsigned __int8 *)&sort_order_big5 + *(v4 - 1));
}

//------------------------------------------------------------------------------
// Address: 0x0043B380
// Name: my_strnncoll_big5
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncoll_big5(
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
  result = my_strnncoll_big5_internal(a1: (unsigned __int8 **)&a, a2: (unsigned __int8 **)&b, length: v8);
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
// Address: 0x0043B3C0
// Name: my_strnncollsp_big5
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnncollsp_big5(
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
  result = my_strnncoll_big5_internal(a1: (unsigned __int8 **)&a, a2: (unsigned __int8 **)&b, length: v7);
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
// Address: 0x0043B430
// Name: my_strnxfrm_big5
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_strnxfrm_big5(
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
        v11 = big5strokexfrm(a1: _byteswap_ushort(*v8));
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
// Address: 0x0043B500
// Name: my_like_range_big5
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_like_range_big5(
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
        || (v18 = *v12, (unsigned __int8)*v12 < 0xA1u)
        || (unsigned __int8)v18 > 0xF9u
        || ((v19 = *v17, (unsigned __int8)*v17 < 0x40u) || (unsigned __int8)v19 > 0x7Eu)
        && ((unsigned __int8)v19 < 0xA1u || v19 == -1) )
      {
        v21 = *v12;
        v22 = *v12;
        if ( v22 == escape && v17 != (char *)end )
        {
          v23 = *++v12;
          ++v17;
          if ( (unsigned __int8)v23 >= 0xA1u && (unsigned __int8)v23 <= 0xF9u )
          {
            if ( (v24 = *v17, (unsigned __int8)*v17 >= 0x40u) && (unsigned __int8)v24 <= 0x7Eu
              || (unsigned __int8)v24 >= 0xA1u && v24 != -1 )
            {
              *max_str = v23;
              *v11++ = v23;
              ++max_str;
              ++v12;
              ++v17;
            }
          }
          if ( v11 >= min_enda )
            goto LABEL_29;
          v21 = *v12;
          goto LABEL_27;
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
LABEL_27:
          *max_str = v21;
          *v11 = v21;
          goto LABEL_28;
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
LABEL_28:
      ++v11;
      ++max_str;
LABEL_29:
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
// Address: 0x0043B680
// Name: ismbchar_big5
// Source: json
//------------------------------------------------------------------------------
int __cdecl ismbchar_big5(int a1, _BYTE *a2, int a3)
{
  unsigned __int8 v3; // al

  if ( *a2 < 0xA1u || *a2 > 0xF9u || a3 - (int)a2 <= 1 )
    return 0;
  if ( ((v3 = a2[1]) < 0x40u || v3 > 0x7Eu) && (v3 < 0xA1u || v3 == 0xFF) )
    return 0;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x0043B6C0
// Name: mbcharlen_big5
// Source: json
//------------------------------------------------------------------------------
int __cdecl mbcharlen_big5(LIST_ENTRY32 *cs, char c)
{
  return 2 - ((unsigned __int8)(c + 95) > 0x58u);
}

//------------------------------------------------------------------------------
// Address: 0x0043B6E0
// Name: func_big5_uni_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_big5_uni_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 41280) <= 0x26BC )
    return (unsigned __int16)word_57A5A8[a1];
  if ( (unsigned int)(a1 - 51520) > 0x309C )
    return 0;
  return (unsigned __int16)word_57A328[a1];
}

//------------------------------------------------------------------------------
// Address: 0x0043B720
// Name: func_uni_big5_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_uni_big5_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 162) <= 0x55 )
    return (unsigned __int16)word_5995A4[a1];
  if ( (unsigned int)(a1 - 711) <= 0x18A )
    return (unsigned __int16)word_59920A[a1];
  if ( (unsigned int)(a1 - 8211) <= 0x2AC )
    return (unsigned __int16)word_595A8A[a1];
  if ( (unsigned int)(a1 - 9312) <= 0x1E2 )
    return (unsigned __int16)word_595750[a1];
  if ( (unsigned int)(a1 - 12288) <= 0x129 )
    return (unsigned __int16)word_5943D8[a1];
  if ( a1 == 12963 )
    return (unsigned __int16)tab_uni_big55;
  if ( (unsigned int)(a1 - 13198) <= 0x47 )
    return (unsigned __int16)word_593F14[a1];
  if ( (unsigned int)(a1 - 19968) <= 0x4683 )
    return (unsigned __int16)word_590AC0[a1];
  if ( (unsigned int)(a1 - 38263) <= 0xA2D )
    return (unsigned __int16)word_5908DA[a1];
  if ( (unsigned int)(a1 - 64012) <= 1 )
    return (unsigned __int16)word_57B214[a1];
  if ( (unsigned int)(a1 - 65072) > 0x1CD )
    return 0;
  return (unsigned __int16)word_584BF0[a1];
}

//------------------------------------------------------------------------------
// Address: 0x0043B820
// Name: my_wc_mb_big5
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_big5(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  int result; // eax

  if ( s >= e )
    return -101;
  if ( (int)wc >= 128 )
  {
    result = func_uni_big5_onechar(a1: (int)wc);
    if ( result != 0 )
    {
      if ( s + 2 > e )
        return -101;
      s[1] = result;
      *s = BYTE1(result);
      return 2;
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
// Address: 0x0043B870
// Name: my_mb_wc_big5
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_big5(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
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
      v6 = func_big5_uni_onechar(a1: (v5 << 8) + a3[1]);
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
// Address: 0x0043B8D0
// Name: my_well_formed_len_big5
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_big5(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, unsigned int pos, int *error, ...)
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
          || (unsigned __int8)v7 < 0xA1u
          || (unsigned __int8)v7 > 0xF9u
          || ((unsigned __int8)(v8 = v6[1]) < 0x40u || (unsigned __int8)v8 > 0x7Eu)
          && ((unsigned __int8)v8 < 0xA1u || v8 == -1) )
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
