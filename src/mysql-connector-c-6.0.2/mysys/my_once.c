// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_once.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00419FA0
// Name: _my_once_alloc
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_once_alloc(unsigned int Size, char MyFlags)
{
  int (__stdcall *v2)(void *, _WIN32_FIND_DATAA *); // eax
  unsigned int v3; // esi
  unsigned int v4; // edx
  int (__stdcall *v5)(void *, _WIN32_FIND_DATAA *); // ebx
  unsigned int v6; // ecx
  unsigned int v7; // edi
  int *v8; // esi
  int v10; // ecx
  unsigned __int8 *v11; // edi

  v2 = *(int (__stdcall **)(void *, _WIN32_FIND_DATAA *))my_once_root_block;
  v3 = (Size + 7) & 0xFFFFFFF8;
  v4 = 0;
  v5 = my_once_root_block;
  if ( *(_DWORD *)my_once_root_block != 0 )
  {
    while ( 1 )
    {
      v6 = *((_DWORD *)v2 + 1);
      if ( v6 >= v3 )
        break;
      if ( v6 > v4 )
        v4 = *((_DWORD *)v2 + 1);
      v5 = v2;
      v2 = *(int (__stdcall **)(void *, _WIN32_FIND_DATAA *))v2;
      if ( v2 == nullptr )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v7 = v3 + 16;
    if ( 4 * v4 < my_once_extra && v7 < my_once_extra )
      v7 = my_once_extra;
    v2 = (int (__stdcall *)(void *, _WIN32_FIND_DATAA *))operator new(nSize: v7);
    if ( v2 == nullptr )
    {
      v8 = _errno();
      *(_DWORD *)_my_thread_var() = *v8;
      if ( (MyFlags & 0x18) != 0 )
        my_error(a1: 5, a2: 36, v7);
      return nullptr;
    }
    *((_DWORD *)v2 + 2) = v7;
    *(_DWORD *)v2 = 0;
    *((_DWORD *)v2 + 1) = v7 - 16;
    *(_DWORD *)v5 = v2;
  }
  v10 = *((_DWORD *)v2 + 1);
  v11 = (unsigned __int8 *)v2 + *((_DWORD *)v2 + 2) - v10;
  *((_DWORD *)v2 + 1) = v10 - v3;
  if ( (MyFlags & 0x20) != 0 )
    memset(dst: v11, value: 0, count: v3);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x0041A060
// Name: _my_once_strdup
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_once_strdup(char *src, char myflags)
{
  unsigned int v2; // kr00_4
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // esi

  v2 = strlen(src);
  v3 = my_once_alloc(Size: v2 + 1, MyFlags: myflags);
  v4 = v3;
  if ( v3 != nullptr )
    memcpy(dst: v3, (unsigned __int8 *)src, count: v2 + 1);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x0041A0B0
// Name: _my_once_memdup
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_once_memdup(unsigned __int8 *src, unsigned int count, char MyFlags)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v4; // esi

  result = my_once_alloc(Size: count, MyFlags);
  v4 = result;
  if ( result != nullptr )
  {
    memcpy(dst: result, src, count);
    return v4;
  }
  return result;
}
