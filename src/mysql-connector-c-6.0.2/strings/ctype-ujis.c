// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/ctype-ujis.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00435470
// Name: ismbchar_ujis
// Source: json
//------------------------------------------------------------------------------
int __cdecl ismbchar_ujis(int a1, unsigned __int8 *a2, int a3)
{
  unsigned __int8 v3; // bl
  unsigned __int8 v4; // cl
  unsigned __int8 v5; // cl
  unsigned __int8 v7; // cl
  unsigned __int8 v8; // al

  v3 = *a2;
  if ( *a2 < 0x80u )
    return 0;
  if ( v3 >= 0xA1u && v3 != 0xFF && a3 - (int)a2 > 1 )
  {
    v4 = a2[1];
    if ( v4 >= 0xA1u && v4 != 0xFF )
      return 2;
  }
  if ( v3 == 0x8E && a3 - (int)a2 > 1 )
  {
    v5 = a2[1];
    if ( v5 >= 0xA1u && v5 <= 0xDFu )
      return 2;
  }
  if ( v3 != 0x8F )
    return 0;
  if ( a3 - (int)a2 <= 2 )
    return 0;
  v7 = a2[1];
  if ( v7 < 0xA1u )
    return 0;
  if ( v7 == 0xFF )
    return 0;
  v8 = a2[2];
  if ( v8 < 0xA1u || v8 == 0xFF )
    return 0;
  else
    return 3;
}

//------------------------------------------------------------------------------
// Address: 0x00435500
// Name: mbcharlen_ujis
// Source: json
//------------------------------------------------------------------------------
int __cdecl mbcharlen_ujis(LIST_ENTRY32 *cs, unsigned __int8 c)
{
  if ( (c < 0xA1u || c == 255) && c != 142 )
    return 2 * (c == 143) + 1;
  else
    return 2;
}

//------------------------------------------------------------------------------
// Address: 0x00436990
// Name: my_well_formed_len_ujis
// Source: json
//------------------------------------------------------------------------------
int my_well_formed_len_ujis(LIST_ENTRY32 *cs, const char *beg, tagShutdownType end, unsigned int pos, int *error, ...)
{
  unsigned int v5; // edi
  const char *v6; // ecx
  unsigned int v7; // edx
  const char *v8; // eax
  bool v9; // cc

  v5 = pos;
  v6 = beg;
  *error = 0;
  if ( pos != 0 )
  {
    while ( (unsigned int)v6 < end )
    {
      v7 = *(unsigned __int8 *)v6;
      if ( v7 > 0x7F )
      {
        v8 = v6++;
        if ( (unsigned int)v6 >= end )
          goto LABEL_16;
        if ( v7 == 142 )
        {
          if ( *v6 < 0xA0u )
            goto LABEL_16;
          v9 = *v6 <= 0xDFu;
        }
        else
        {
          if ( v7 == 143 && (v7 = *(unsigned __int8 *)v6, ++v6, (unsigned int)v6 >= end)
            || v7 - 161 > 0x5D
            || *v6 < 0xA1u )
          {
LABEL_16:
            *error = 1;
            return v8 - beg;
          }
          v9 = *v6 != 0xFF;
        }
        if ( !v9 )
          goto LABEL_16;
      }
      --v5;
      ++v6;
      if ( v5 == 0 )
        return v6 - beg;
    }
  }
  return v6 - beg;
}
