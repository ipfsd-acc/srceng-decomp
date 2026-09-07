// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_realloc.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004183C0
// Name: _my_realloc
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_realloc(void *ptr, unsigned int size, __int16 my_flags)
{
  void *v4; // edi
  int *v5; // esi

  if ( ptr == nullptr && (my_flags & 0x40) != 0 )
    return my_malloc(size, my_flags);
  v4 = _realloc_crt(ptr, size);
  if ( v4 == nullptr )
  {
    if ( (my_flags & 0x80u) != 0 )
      my_no_flags_free(ptr);
    if ( (my_flags & 0x100) != 0 )
      return (unsigned __int8 *)ptr;
    v5 = _errno();
    *(_DWORD *)_my_thread_var() = *v5;
    if ( (my_flags & 0x18) != 0 )
      my_error(a1: 5, a2: 36, size);
  }
  return (unsigned __int8 *)v4;
}
