// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/mf_dirname.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00419D90
// Name: _dirname_length
// Source: json
//------------------------------------------------------------------------------
int __cdecl dirname_length(unsigned __int8 *string)
{
  unsigned __int8 *v1; // eax
  unsigned __int8 v2; // cl
  unsigned __int8 *v3; // edx
  unsigned __int8 *i; // eax

  strrchr(string, chr: 0x3Au);
  if ( v1 == nullptr )
    v1 = string - 1;
  v2 = v1[1];
  v3 = v1;
  for ( i = v1 + 1; v2 != 0; ++i )
  {
    if ( v2 == 92 || v2 == 47 )
      v3 = i;
    v2 = i[1];
  }
  return v3 - string + 1;
}

//------------------------------------------------------------------------------
// Address: 0x00419DD0
// Name: _convert_dirname
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl convert_dirname(unsigned __int8 *dst, unsigned __int8 *src, unsigned __int8 *a3)
{
  unsigned __int8 *v3; // edi
  unsigned __int8 *v4; // esi
  LIST_ENTRY32 *v5; // ebp
  int (__cdecl *v6)(LIST_ENTRY32 *, unsigned __int8 *, unsigned __int8 *); // eax
  unsigned int v7; // eax
  unsigned int v8; // ebx
  char v9; // al

  v3 = dst;
  v4 = src;
  v5 = fs_character_set();
  if ( a3 == nullptr || a3 - src > 510 )
    a3 = src + 510;
  if ( src != a3 )
  {
    while ( 1 )
    {
      if ( *v4 == 0 )
        goto LABEL_14;
      if ( *v4 == 47 )
        break;
      v6 = *(int (__cdecl **)(LIST_ENTRY32 *, unsigned __int8 *, unsigned __int8 *))(v5[12].Blink + 4);
      if ( v6 == nullptr || (v7 = v6(a1: v5, a2: v4, a3: v4 + 3), v8 = v7, v7 == 0) )
      {
        *v3 = *v4;
        goto LABEL_12;
      }
      memmove(dst: v3, src: v4, count: v7);
      v3 += v8;
      v4 = &v4[v8 - 1];
      dst = v3;
LABEL_13:
      if ( ++v4 == a3 )
        goto LABEL_14;
    }
    *v3 = 92;
LABEL_12:
    ++v3;
    goto LABEL_13;
  }
LABEL_14:
  *v3 = 0;
  if ( v3 != dst )
  {
    v9 = *(v3 - 1);
    if ( v9 != 92 && v9 != 58 )
    {
      *v3++ = 92;
      *v3 = 0;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00419E80
// Name: _dirname_part
// Source: json
//------------------------------------------------------------------------------
int __cdecl dirname_part(unsigned __int8 *dst, unsigned __int8 *string, _DWORD *a3)
{
  int v3; // edi

  v3 = dirname_length(string);
  *a3 = convert_dirname(dst, src: string, a3: &string[v3]) - dst;
  return v3;
}
