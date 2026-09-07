// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-euc_kr.c
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00438070
// Name: ismbchar_euc_kr
// Source: json
//------------------------------------------------------------------------------
int __cdecl ismbchar_euc_kr(int a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 v3; // al
  unsigned __int8 v4; // al

  v3 = *a2;
  if ( *a2 < 0x80u || v3 < 0xA1u || v3 == 0xFF || a3 - (int)a2 <= 1 )
    return 0;
  if ( ((v4 = a2[1]) < 0x41u || v4 > 0x5Au) && (v4 < 0x61u || v4 > 0x7Au) && (v4 < 0x81u || v4 == 0xFF) )
    return 0;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x004380C0
// Name: mbcharlen_euc_kr
// Source: json
//------------------------------------------------------------------------------
int __cdecl mbcharlen_euc_kr(LIST_ENTRY32 *cs, char c)
{
  return 2 - ((unsigned __int8)(c + 95) > 0x5Du);
}

//------------------------------------------------------------------------------
// Address: 0x004380E0
// Name: func_ksc5601_uni_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_ksc5601_uni_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 33089) <= 0x47BD )
    return (unsigned __int16)word_5417B6[a1];
  if ( (unsigned int)(a1 - 51873) > 0x335D )
    return 0;
  return (unsigned __int16)word_541476[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00438120
// Name: func_uni_ksc5601_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_uni_ksc5601_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 161) <= 0xC6 )
    return (unsigned __int16)word_560F36[a1];
  if ( (unsigned int)(a1 - 711) <= 0x18A )
    return (unsigned __int16)word_560C7A[a1];
  if ( (unsigned int)(a1 - 8213) <= 0x2FD )
    return (unsigned __int16)word_55D4F6[a1];
  if ( (unsigned int)(a1 - 9312) <= 0x20D )
    return (unsigned __int16)word_55D260[a1];
  if ( (unsigned int)(a1 - 12288) <= 0x27F )
    return (unsigned __int16)word_55BF40[a1];
  if ( (unsigned int)(a1 - 13184) <= 0x5D )
    return (unsigned __int16)word_55BD40[a1];
  if ( (unsigned int)(a1 - 19968) <= 0x467F )
    return (unsigned __int16)word_558900[a1];
  if ( (unsigned int)(a1 - 38263) <= 0xA25 )
    return (unsigned __int16)word_558712[a1];
  if ( (unsigned int)(a1 - 44032) <= 0x2BA3 )
    return (unsigned __int16)word_556E50[a1];
  if ( (unsigned int)(a1 - 63744) <= 0x10B )
    return (unsigned __int16)word_552B98[a1];
  if ( (unsigned int)(a1 - 65281) > 0xE5 )
    return 0;
  return (unsigned __int16)word_5521AE[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00438220
// Name: my_wc_mb_euc_kr
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_euc_kr(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  int result; // eax

  if ( s >= e )
    return -101;
  if ( (unsigned int)wc >= 0x80 )
  {
    result = func_uni_ksc5601_onechar(a1: (int)wc);
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
// Address: 0x00438280
// Name: my_mb_wc_euc_kr
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_euc_kr(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
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
      v6 = func_ksc5601_uni_onechar(a1: (v5 << 8) + a3[1]);
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
// Address: 0x004382E0
// Name: my_well_formed_len_euckr
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_euckr(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, unsigned int pos, int *error, ...)
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
          || v7 == -1
          || ((unsigned __int8)(v8 = v6[1]) < 0x41u || (unsigned __int8)v8 > 0x5Au)
          && ((unsigned __int8)v8 < 0x61u || (unsigned __int8)v8 > 0x7Au)
          && ((unsigned __int8)v8 < 0x81u || v8 == -1) )
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
