// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/str2int.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00420960
// Name: _str2int
// Source: json
//------------------------------------------------------------------------------
char *__cdecl str2int(char *src, int radix, int lower, int upper, int *val)
{
  int v5; // eax
  int v6; // ecx
  char *v7; // ebp
  int v8; // esi
  char *i; // esi
  int j; // edi
  char v11; // cl
  int v12; // ecx
  int v14; // edi
  int v15; // ebx
  int k; // esi
  int v17; // ecx
  int v18; // eax
  int v19; // ecx
  int sign; // [esp+0h] [ebp-84h]
  _DWORD v21[32]; // [esp+4h] [ebp-80h]

  *val = 0;
  v5 = lower;
  if ( lower > 0 )
    v5 = -lower;
  v6 = upper;
  if ( upper > 0 )
    v6 = -upper;
  if ( v6 < v5 )
    v5 = v6;
  v7 = src;
  if ( (*((_BYTE *)off_4904A8 + (unsigned __int8)*src + 1) & 8) != 0 )
  {
    do
      v8 = (unsigned __int8)*++v7;
    while ( (*((_BYTE *)off_4904A8 + v8 + 1) & 8) != 0 );
  }
  sign = -1;
  if ( *v7 != 43 )
  {
    if ( *v7 != 45 )
      goto LABEL_13;
    sign = 1;
  }
  ++v7;
LABEL_13:
  for ( i = v7; *v7 == 48; ++v7 )
    ;
  for ( j = 0; ; ++j )
  {
    v11 = *v7;
    if ( *v7 < 48 || v11 > 57 )
    {
      if ( v11 < 65 || v11 > 90 )
        v12 = v11 < 97 || v11 > 122 ? 127 : v11 - 87;
      else
        v12 = v11 - 55;
    }
    else
    {
      v12 = v11 - 48;
    }
    v21[j] = v12;
    if ( v12 >= radix || j >= 20 )
      break;
    ++v7;
  }
  if ( i == v7 )
  {
    *_errno() = 33;
    return nullptr;
  }
  v14 = j - 1;
  v15 = 0;
  for ( k = -1; v14 >= 1; v15 += v19 )
  {
    v17 = v21[v14];
    if ( -v17 < v5 )
      goto LABEL_40;
    v18 = v17 + v5;
    v19 = k * v17;
    k *= radix;
    v5 = v18 / radix;
    --v14;
  }
  if ( v14 == 0 )
  {
    if ( -v21[0] < v5 )
      goto LABEL_40;
    v15 += k * v21[0];
  }
  if ( sign >= 0 )
  {
    if ( v15 >= lower )
      goto LABEL_42;
LABEL_40:
    *_errno() = 34;
    return nullptr;
  }
  if ( v15 == 0x80000000 )
    goto LABEL_40;
  v15 = -v15;
  if ( v15 > upper )
    goto LABEL_40;
LABEL_42:
  *val = v15;
  *_errno() = 0;
  return v7;
}
