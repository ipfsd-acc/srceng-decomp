// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_compress.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00418440
// Name: _my_compress_alloc
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_compress_alloc(int a1, _DWORD *a2, unsigned int *a3)
{
  _DWORD *v3; // ebx
  unsigned int *v4; // edi
  unsigned __int8 *v5; // esi
  int v6; // eax
  _DWORD *v7; // ecx
  _DWORD *v8; // eax
  unsigned int v10; // [esp-8h] [ebp-14h]
  _DWORD *v11; // [esp-4h] [ebp-10h]

  v3 = a2;
  v4 = a3;
  v10 = 120 * *a2 / 0x64u + 12;
  *a3 = v10;
  v5 = my_malloc(size: v10, my_flags: 16);
  if ( v5 == nullptr )
    return nullptr;
  v11 = (_DWORD *)*v3;
  a2 = (_DWORD *)*v4;
  v6 = compress(a1: v5, &a2, a3: a1, a4: v11);
  v7 = a2;
  *v4 = (unsigned int)a2;
  if ( v6 != 0 )
  {
LABEL_5:
    my_no_flags_free(ptr: v5);
    return nullptr;
  }
  v8 = (_DWORD *)*v3;
  if ( (unsigned int)v7 >= *v3 )
  {
    *v4 = 0;
    goto LABEL_5;
  }
  *v3 = v7;
  *v4 = (unsigned int)v8;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x004184D0
// Name: _my_uncompress
// Source: json
//------------------------------------------------------------------------------
char __cdecl my_uncompress(unsigned __int8 *dst, unsigned int a2, unsigned int *count)
{
  unsigned int **v3; // edi
  unsigned __int8 *v4; // esi
  int v5; // eax
  unsigned int v6; // ecx

  v3 = (unsigned int **)count;
  if ( *count != 0 )
  {
    v4 = my_malloc(size: *count, my_flags: 16);
    if ( v4 == nullptr )
      return 1;
    count = *v3;
    v5 = uncompress(a1: v4, a2: &count, a3: dst, a4: a2);
    v6 = (unsigned int)count;
    *v3 = count;
    if ( v5 != 0 )
    {
      my_no_flags_free(ptr: v4);
      return 1;
    }
    memcpy(dst, src: v4, count: v6);
    my_no_flags_free(ptr: v4);
    return 0;
  }
  else
  {
    *count = a2;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00418550
// Name: _my_compress
// Source: json
//------------------------------------------------------------------------------
bool __cdecl my_compress(unsigned __int8 *dst, unsigned int *a2, unsigned int *a3)
{
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // esi

  if ( *a2 >= 0x32 )
  {
    v4 = my_compress_alloc(a1: (int)dst, a2, a3);
    v5 = v4;
    if ( v4 != nullptr )
    {
      memcpy(dst, src: v4, count: *a2);
      my_no_flags_free(ptr: v5);
      return false;
    }
    else
    {
      return *a3 == 0;
    }
  }
  else
  {
    *a3 = 0;
    return false;
  }
}
