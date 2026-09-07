// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/strings/str_alloc.c
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00450EB0
// Name: my_str_malloc_default
// Source: json
//------------------------------------------------------------------------------
void *__cdecl my_str_malloc_default(unsigned int nSize)
{
  void *result; // eax

  result = operator new(nSize);
  if ( result == nullptr )
    exit(code: 1);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00450ED0
// Name: my_str_free_default
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __cdecl my_str_free_default(void *ptr)
{
  free(pMem: ptr);
}
