// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/mulalloc.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00417B00
// Name: _my_multi_malloc
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_multi_malloc(char my_flags, int a2)
{
  int v2; // edi
  unsigned int v3; // ecx
  int *v4; // eax
  unsigned int v5; // edx
  unsigned __int8 *result; // eax
  unsigned __int8 *v7; // esi
  unsigned __int8 **v8; // edx
  int *v9; // ecx
  int v10; // edx

  v2 = a2;
  v3 = 0;
  if ( a2 != 0 )
  {
    v4 = &a2;
    do
    {
      v5 = (v4[1] + 7) & 0xFFFFFFF8;
      v4 += 2;
      v3 += v5;
    }
    while ( *v4 != 0 );
  }
  result = my_malloc(size: v3, my_flags);
  if ( result != nullptr )
  {
    v7 = result;
    v8 = (unsigned __int8 **)v2;
    if ( v2 != 0 )
    {
      v9 = &a2;
      do
      {
        *v8 = v7;
        v10 = v9[1];
        v9 += 2;
        v7 += (v10 + 7) & 0xFFFFFFF8;
        v8 = (unsigned __int8 **)*v9;
      }
      while ( *v9 != 0 );
    }
  }
  return result;
}
