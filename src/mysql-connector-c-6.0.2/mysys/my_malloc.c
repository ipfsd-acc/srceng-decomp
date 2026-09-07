// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_malloc.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040F330
// Name: _my_malloc
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_malloc(unsigned int size, char my_flags)
{
  unsigned int v2; // esi
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // ebx
  int *v5; // edi

  v2 = size;
  if ( size == 0 )
    v2 = 1;
  v3 = (unsigned __int8 *)operator new(nSize: v2);
  v4 = v3;
  if ( v3 != nullptr )
  {
    if ( (my_flags & 0x20) != 0 )
      memset(dst: v3, value: 0, count: v2);
  }
  else
  {
    v5 = _errno();
    *(_DWORD *)_my_thread_var() = *v5;
    if ( (my_flags & 8) != 0 )
      error_handler_hook[0] = fatal_error_handler_hook;
    if ( (my_flags & 0x18) != 0 )
      my_error(a1: 5, a2: 100, ap: v2);
    if ( (my_flags & 8) != 0 )
      exit(code: 1);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0040F3B0
// Name: _my_no_flags_free
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_no_flags_free(void *ptr)
{
  if ( ptr != nullptr )
    free(pMem: ptr);
}

//------------------------------------------------------------------------------
// Address: 0x0040F3D0
// Name: _my_memdup
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_memdup(unsigned __int8 *src, unsigned int count, char my_flags)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v4; // esi

  result = my_malloc(size: count, my_flags);
  v4 = result;
  if ( result != nullptr )
  {
    memcpy(dst: result, src, count);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0040F400
// Name: _my_strdup
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_strdup(char *from, char my_flags)
{
  unsigned int v2; // kr00_4
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // esi

  v2 = strlen(from);
  v3 = my_malloc(size: v2 + 1, my_flags);
  v4 = v3;
  if ( v3 != nullptr )
    memcpy(dst: v3, src: (unsigned __int8 *)from, count: v2 + 1);
  return v4;
}
