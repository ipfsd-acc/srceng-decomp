// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/array.c
// Functions: 5
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00414C60
// Name: _init_dynamic_array2
// Source: json
//------------------------------------------------------------------------------
char __cdecl init_dynamic_array2(
        unsigned __int8 **a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        unsigned int a4,
        unsigned int a5)
{
  unsigned int v5; // eax
  unsigned __int8 *v6; // eax

  v5 = a5;
  if ( a5 == 0 )
  {
    v5 = 0x1FF8 / (unsigned int)a2;
    if ( 0x1FF8 / (unsigned int)a2 <= 0x10 )
      v5 = 16;
    if ( a4 > 8 && v5 > 2 * a4 )
      v5 = 2 * a4;
  }
  a1[3] = (unsigned __int8 *)v5;
  a1[1] = nullptr;
  a1[2] = (unsigned __int8 *)a4;
  a1[4] = a2;
  *a1 = a3;
  if ( a3 != nullptr )
    return 0;
  if ( a4 == 0 )
    return 0;
  v6 = my_malloc(size: a4 * (_DWORD)a2, my_flags: 16);
  *a1 = v6;
  if ( v6 != nullptr )
    return 0;
  a1[2] = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00414CE0
// Name: _init_dynamic_array
// Source: json
//------------------------------------------------------------------------------
char __cdecl init_dynamic_array(
        unsigned __int8 **array,
        unsigned __int8 *element_size,
        unsigned int init_alloc,
        unsigned int alloc_increment)
{
  return init_dynamic_array2(a1: array, a2: element_size, a3: nullptr, a4: init_alloc, a5: alloc_increment);
}

//------------------------------------------------------------------------------
// Address: 0x00414D00
// Name: _alloc_dynamic
// Source: json
//------------------------------------------------------------------------------
int __cdecl alloc_dynamic(int a1)
{
  int v1; // eax
  unsigned __int8 *v2; // edi
  int result; // eax
  int v4; // ecx

  v1 = *(_DWORD *)(a1 + 8);
  if ( *(_DWORD *)(a1 + 4) == v1 )
  {
    if ( *(_DWORD *)a1 == a1 + 20 )
    {
      v2 = my_malloc(size: *(_DWORD *)(a1 + 16) * (v1 + *(_DWORD *)(a1 + 12)), my_flags: 16);
      if ( v2 == nullptr )
        return 0;
      memcpy(dst: v2, src: *(unsigned __int8 **)a1, count: *(_DWORD *)(a1 + 4) * *(_DWORD *)(a1 + 16));
    }
    else
    {
      v2 = (unsigned __int8 *)my_realloc(
                                ptr: *(void **)a1,
                                size: *(_DWORD *)(a1 + 16) * (v1 + *(_DWORD *)(a1 + 12)),
                                my_flags: 80);
      if ( v2 == nullptr )
        return 0;
    }
    *(_DWORD *)(a1 + 8) += *(_DWORD *)(a1 + 12);
    *(_DWORD *)a1 = v2;
  }
  v4 = *(_DWORD *)(a1 + 4);
  result = *(_DWORD *)a1 + v4 * *(_DWORD *)(a1 + 16);
  *(_DWORD *)(a1 + 4) = v4 + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414D90
// Name: _delete_dynamic
// Source: json
//------------------------------------------------------------------------------
void __cdecl delete_dynamic(int a1)
{
  if ( *(_DWORD *)a1 != a1 + 20 )
  {
    if ( *(_DWORD *)a1 == 0 )
      return;
    my_no_flags_free(ptr: *(void **)a1);
    *(_DWORD *)a1 = 0;
    *(_DWORD *)(a1 + 8) = 0;
  }
  *(_DWORD *)(a1 + 4) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00414DD0
// Name: _insert_dynamic
// Source: json
//------------------------------------------------------------------------------
char __cdecl insert_dynamic(_DWORD *array, unsigned __int8 *element)
{
  int v2; // ecx
  unsigned __int8 *v3; // eax

  v2 = array[1];
  if ( v2 == array[2] )
  {
    v3 = (unsigned __int8 *)alloc_dynamic(a1: (int)array);
    if ( v3 == nullptr )
      return 1;
  }
  else
  {
    v3 = (unsigned __int8 *)(*array + v2 * array[4]);
    array[1] = v2 + 1;
  }
  memcpy(dst: v3, src: element, count: array[4]);
  return 0;
}
