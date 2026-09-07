// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-gb2312.c
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00437DA0
// Name: ismbchar_gb2312
// Source: json
//------------------------------------------------------------------------------
int __cdecl ismbchar_gb2312(int a1, _BYTE *a2, int a3)
{
  unsigned __int8 v3; // al

  if ( *a2 < 0xA1u )
    return 0;
  if ( *a2 > 0xF7u )
    return 0;
  if ( a3 - (int)a2 <= 1 )
    return 0;
  v3 = a2[1];
  if ( v3 < 0xA1u || v3 == 0xFF )
    return 0;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00437DD0
// Name: mbcharlen_gb2312
// Source: json
//------------------------------------------------------------------------------
int __cdecl mbcharlen_gb2312(LIST_ENTRY32 *cs, char c)
{
  return 2 - ((unsigned __int8)(c + 95) > 0x56u);
}

//------------------------------------------------------------------------------
// Address: 0x00437DF0
// Name: func_gb2312_uni_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_gb2312_uni_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 8481) <= 0x537 )
    return (unsigned __int16)word_53828E[a1];
  if ( (unsigned int)(a1 - 10017) <= 0x24E )
    return (unsigned __int16)word_5380FE[a1];
  if ( (unsigned int)(a1 - 12321) > 0x475D )
    return 0;
  return (unsigned __int16)word_53739E[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00437E40
// Name: func_uni_gb2312_onechar
// Source: json
//------------------------------------------------------------------------------
int __usercall func_uni_gb2312_onechar@<eax>(int a1@<eax>)
{
  if ( (unsigned int)(a1 - 164) <= 0x138 )
    return (unsigned __int16)word_546158[a1];
  if ( (unsigned int)(a1 - 711) <= 0x18A )
    return (unsigned __int16)word_545F8A[a1];
  if ( (unsigned int)(a1 - 8213) <= 0x2FD )
    return (unsigned __int16)word_542806[a1];
  if ( (unsigned int)(a1 - 9312) <= 0x1E2 )
    return (unsigned __int16)word_542570[a1];
  if ( (unsigned int)(a1 - 12288) <= 0x129 )
    return (unsigned __int16)word_5411F8[a1];
  if ( (unsigned int)(a1 - 12832) <= 9 )
    return (unsigned __int16)word_54100C[a1];
  if ( (unsigned int)(a1 - 19968) <= 0x4D54 )
    return (unsigned __int16)word_53D860[a1];
  if ( (unsigned int)(a1 - 40060) <= 0x66 )
    return (unsigned __int16)word_53D618[a1];
  if ( (unsigned int)(a1 - 40479) <= 0x181 )
    return (unsigned __int16)word_53D3A2[a1];
  if ( (unsigned int)(a1 - 65281) > 0xE4 )
    return 0;
  return (unsigned __int16)word_5314E6[a1];
}

//------------------------------------------------------------------------------
// Address: 0x00437F30
// Name: my_wc_mb_gb2312
// Source: json
//------------------------------------------------------------------------------
int my_wc_mb_gb2312(LIST_ENTRY32 *cs, const char *wc, unsigned __int8 *s, unsigned __int8 *e, ...)
{
  int result; // eax
  __int16 v5; // ax

  if ( s >= e )
    return -101;
  if ( (unsigned int)wc >= 0x80 )
  {
    result = func_uni_gb2312_onechar(a1: (int)wc);
    if ( result != 0 )
    {
      if ( s + 2 <= e )
      {
        v5 = result | 0x8080;
        s[1] = v5;
        *s = HIBYTE(v5);
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
// Address: 0x00437F90
// Name: my_mb_wc_gb2312
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_mb_wc_gb2312(int a1, _DWORD *a2, unsigned __int8 *a3, unsigned int a4)
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
      v6 = func_gb2312_uni_onechar(a1: (((_WORD)v5 << 8) + a3[1]) & 0x7F7F);
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
// Address: 0x00438000
// Name: my_well_formed_len_gb2312
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_gb2312(LIST_ENTRY32 *cs, const char *b, tagShutdownType e, unsigned int pos, int *error, ...)
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
          || (unsigned __int8)v7 > 0xF7u
          || (unsigned __int8)(v8 = v6[1]) < 0xA1u
          || v8 == -1 )
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
