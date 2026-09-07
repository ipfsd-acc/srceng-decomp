// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/typelib.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00415FC0
// Name: _find_type
// Source: json
//------------------------------------------------------------------------------
int __cdecl find_type(char *x, int a2, char full_name)
{
  int v3; // ebp
  int v4; // edi
  char *v6; // ecx
  char v7; // bl
  char *v8; // eax
  char v9; // cl
  char *v10; // edi
  int v11; // esi
  char v12; // [esp+Bh] [ebp-Dh]
  int find; // [esp+Ch] [ebp-Ch]
  int v14; // [esp+10h] [ebp-8h]
  int findpos; // [esp+14h] [ebp-4h]

  v3 = a2;
  v4 = 0;
  if ( *(_DWORD *)a2 == 0 )
    return 0;
  v6 = **(char ***)(a2 + 8);
  v7 = full_name;
  find = 0;
  if ( v6 == nullptr )
  {
LABEL_25:
    if ( (v7 & 4) == 0 )
      return 0;
    v10 = x;
    if ( *x != 35 )
      return 0;
    if ( *((_BYTE *)&strend(result: (ioinfo *)x)[-1].dbcsBufferUsed + 7) != 35 )
      return 0;
    v11 = atoi(nptr: x + 1) - 1;
    if ( v11 < 0 || (unsigned int)v11 >= *(_DWORD *)v3 )
      return 0;
    goto LABEL_35;
  }
  v12 = *x;
  v14 = *(_DWORD *)(a2 + 8);
  do
  {
    v8 = x;
    if ( v12 != 0 )
    {
      do
      {
        if ( (v7 & 8) != 0 && *v8 == 44 )
          break;
        if ( *((_BYTE *)off_4904B0 + (unsigned __int8)*v8) != *((_BYTE *)off_4904B0 + (unsigned __int8)*v6) )
          break;
        ++v8;
        ++v6;
      }
      while ( *v8 != 0 );
    }
    v9 = *v6;
    if ( v9 != 0 )
    {
      v7 = full_name;
    }
    else
    {
      for ( ; *v8 == 32; ++v8 )
        ;
      if ( *v8 == 0 )
        return v4 + 1;
      v7 = full_name;
      if ( (full_name & 8) != 0 && *v8 == 44 )
        return v4 + 1;
    }
    if ( *v8 == 0 && (v9 == 0 || (v7 & 1) == 0) )
    {
      ++find;
      findpos = v4;
    }
    v6 = *(char **)(v14 + 4);
    ++v4;
    v14 += 4;
  }
  while ( v6 != nullptr );
  if ( find == 0 )
  {
    v3 = a2;
    goto LABEL_25;
  }
  if ( v12 == 0 )
    return 0;
  if ( find != 1 || (v7 & 1) != 0 )
    return -1;
  v11 = findpos;
  v10 = x;
  v3 = a2;
LABEL_35:
  if ( (v7 & 2) == 0 )
    strmov(dst: *(void **)(v3 + 8), dsta: v10, src: *(char **)(*(_DWORD *)(v3 + 8) + 4 * v11));
  return v11 + 1;
}
