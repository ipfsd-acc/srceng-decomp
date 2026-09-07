// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_alloc.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00410DC0
// Name: _init_alloc_root
// Source: json
//------------------------------------------------------------------------------
_stat64 *__cdecl init_alloc_root(_stat64 *result, unsigned int block_size, unsigned int pre_alloc_size)
{
  _stat64 *v3; // eax

  v3 = (_stat64 *)(block_size - 28);
  *(_DWORD *)&result->st_nlink = 0;
  *(_DWORD *)&result->st_ino = 0;
  result->st_dev = 0;
  *(_DWORD *)&result->st_gid = 32;
  result->st_rdev = block_size - 28;
  HIDWORD(result->st_size) = 0;
  *(&result->st_rdev + 1) = 4;
  LODWORD(result->st_size) = 0;
  if ( pre_alloc_size != 0 )
  {
    v3 = (_stat64 *)my_malloc(size: pre_alloc_size + 16, my_flags: 0);
    *(_DWORD *)&result->st_nlink = v3;
    result->st_dev = (unsigned int)v3;
    if ( v3 != nullptr )
    {
      *(_DWORD *)&v3->st_nlink = pre_alloc_size + 16;
      *(_DWORD *)(result->st_dev + 4) = pre_alloc_size;
      *(_DWORD *)result->st_dev = 0;
    }
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00410E20
// Name: _alloc_root
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__stdcall alloc_root(int *mem_root, const void *length)
{
  int *v2; // eax
  unsigned int v3; // edi
  int *v4; // ebp
  unsigned int v5; // ecx
  int v6; // edx
  unsigned __int8 *v7; // eax
  unsigned int v8; // ebx
  void (*v9)(void); // esi
  int v11; // ecx
  int v12; // ecx
  int v13; // edx
  unsigned int v14; // ecx
  unsigned __int8 *v15; // edx

  v2 = (int *)*mem_root;
  v3 = ((unsigned int)length + 7) & 0xFFFFFFF8;
  v4 = mem_root;
  if ( *mem_root == 0 )
    goto LABEL_9;
  if ( v2[1] < v3 )
  {
    v5 = mem_root[6];
    mem_root[6] = v5 + 1;
    if ( v5 >= 0xA && (unsigned int)v2[1] < 0x1000 )
    {
      v6 = mem_root[1];
      *mem_root = *v2;
      *v2 = v6;
      mem_root[1] = (int)v2;
      mem_root[6] = 0;
    }
  }
  v7 = (unsigned __int8 *)*mem_root;
  if ( *mem_root != 0 )
  {
    while ( *((_DWORD *)v7 + 1) < v3 )
    {
      v4 = (int *)v7;
      v7 = *(unsigned __int8 **)v7;
      if ( v7 == nullptr )
        goto LABEL_9;
    }
  }
  else
  {
LABEL_9:
    v8 = v3 + 16;
    if ( v3 + 16 <= mem_root[4] * ((unsigned int)mem_root[5] >> 2) )
      v8 = mem_root[4] * ((unsigned int)mem_root[5] >> 2);
    v7 = my_malloc(size: v8, my_flags: 16);
    if ( v7 == nullptr )
    {
      v9 = (void (*)(void))mem_root[7];
      if ( v9 != nullptr )
        v9();
      return nullptr;
    }
    ++mem_root[5];
    v11 = *v4;
    *((_DWORD *)v7 + 2) = v8;
    *(_DWORD *)v7 = v11;
    *((_DWORD *)v7 + 1) = v8 - 16;
    *v4 = (int)v7;
  }
  v12 = *((_DWORD *)v7 + 1);
  v13 = *((_DWORD *)v7 + 2) - v12;
  v14 = v12 - v3;
  v15 = &v7[v13];
  *((_DWORD *)v7 + 1) = v14;
  if ( v14 < mem_root[3] )
  {
    *v4 = *(_DWORD *)v7;
    *(_DWORD *)v7 = mem_root[1];
    mem_root[1] = (int)v7;
    mem_root[6] = 0;
  }
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x00410F00
// Name: mark_blocks_free
// Source: json
//------------------------------------------------------------------------------
_DWORD *__fastcall mark_blocks_free(int a1, _DWORD *a2)
{
  _DWORD *v2; // eax
  _DWORD *i; // ecx
  _DWORD *result; // eax

  v2 = (_DWORD *)*a2;
  for ( i = a2; v2 != nullptr; v2 = (_DWORD *)*v2 )
  {
    v2[1] = v2[2] - 16;
    i = v2;
  }
  result = (_DWORD *)a2[1];
  for ( *i = result; result != nullptr; result = (_DWORD *)*result )
    result[1] = result[2] - 16;
  a2[6] = 0;
  a2[1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410F50
// Name: _free_root
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl free_root(_DWORD *a1, char MyFlags)
{
  int v2; // ecx
  _DWORD *result; // eax
  _DWORD *v4; // edi
  void *v5; // eax
  _DWORD *v6; // edi
  void *v7; // eax

  if ( (MyFlags & 2) != 0 )
    return mark_blocks_free(a1: v2, a2: a1);
  if ( (MyFlags & 1) == 0 )
    a1[2] = 0;
  v4 = (_DWORD *)a1[1];
  while ( v4 != nullptr )
  {
    v5 = v4;
    v4 = (_DWORD *)*v4;
    if ( v5 != (void *)a1[2] )
      my_no_flags_free(ptr: v5);
  }
  v6 = (_DWORD *)*a1;
  while ( v6 != nullptr )
  {
    v7 = v6;
    v6 = (_DWORD *)*v6;
    if ( v7 != (void *)a1[2] )
      my_no_flags_free(ptr: v7);
  }
  result = (_DWORD *)a1[2];
  *a1 = 0;
  a1[1] = 0;
  if ( result != nullptr )
  {
    *a1 = result;
    result[1] = result[2] - 16;
    *(_DWORD *)*a1 = 0;
  }
  a1[5] = 4;
  a1[6] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00410FF0
// Name: _strmake_root
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl strmake_root(int *mem_root, unsigned __int8 *str, unsigned int len)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v4; // esi

  result = alloc_root(mem_root, length: (const void *)(len + 1));
  v4 = result;
  if ( result != nullptr )
  {
    memcpy(dst: result, src: str, count: len);
    v4[len] = 0;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00411030
// Name: _strdup_root
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl strdup_root(int *a1, unsigned __int8 *str)
{
  return strmake_root(mem_root: a1, str, len: strlen((const char *)str));
}
