// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/list.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004143E0
// Name: _list_add
// Source: json
//------------------------------------------------------------------------------
char *__cdecl list_add(int element, int element_4)
{
  char *result; // eax

  result = (char *)element_4;
  if ( element != 0 )
  {
    if ( *(_DWORD *)element != 0 )
      *(_DWORD *)(*(_DWORD *)element + 4) = element_4;
    *(_DWORD *)element_4 = *(_DWORD *)element;
    *(_DWORD *)element = element_4;
    *(_DWORD *)(element_4 + 4) = element;
  }
  else
  {
    *(_DWORD *)element_4 = 0;
    *(_DWORD *)(element_4 + 4) = 0;
  }
  return result;
}
