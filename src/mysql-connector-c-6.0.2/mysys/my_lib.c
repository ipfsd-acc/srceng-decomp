// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_lib.c
// Functions: 4
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041DB80
// Name: _my_dirend
// Source: json
//------------------------------------------------------------------------------
void __cdecl my_dirend(_DWORD *a1)
{
  if ( a1 != nullptr )
  {
    delete_dynamic(a1: (int)(a1 + 2));
    free_root(a1: a1 + 8, MyFlags: 0);
    my_no_flags_free(ptr: a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041DBB0
// Name: comp_names
// Source: json
//------------------------------------------------------------------------------
int __cdecl comp_names(const char **a1, const char **a2)
{
  return strcmp(*a1, *a2);
}

//------------------------------------------------------------------------------
// Address: 0x0041DBF0
// Name: _my_dir
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl my_dir(char *src, __int16 my_flags)
{
  bool v2; // zf
  char *p_szWild; // eax
  char *v4; // eax
  unsigned __int8 *v5; // esi
  int *v6; // esi
  int *v7; // eax
  unsigned int v9; // ecx
  char attrib; // bl
  unsigned __int8 *v11; // eax
  __int16 v12; // ax
  int v13; // ebx
  int element; // [esp+10h] [ebp-340h] BYREF
  unsigned __int8 *v15; // [esp+14h] [ebp-33Ch]
  unsigned __int8 *v16; // [esp+18h] [ebp-338h]
  int hFile; // [esp+1Ch] [ebp-334h]
  char ap[4]; // [esp+20h] [ebp-330h]
  _finddata64i32_t pfd; // [esp+24h] [ebp-32Ch] BYREF
  char szWild; // [esp+14Ch] [ebp-204h] BYREF
  char v21; // [esp+14Dh] [ebp-203h] BYREF

  v2 = *src == 0;
  *(_DWORD *)ap = src;
  v16 = nullptr;
  p_szWild = &szWild;
  if ( v2 )
  {
    szWild = 46;
    p_szWild = &v21;
  }
  v4 = strnmov(dst: p_szWild, src, n: 0x1FBu);
  if ( *(v4 - 1) == 58 )
    *v4++ = 46;
  if ( *(v4 - 1) != 92 )
    *v4++ = 92;
  *v4 = 42;
  v4[1] = 46;
  v4[2] = 42;
  v4[3] = 0;
  v5 = my_malloc(size: 0x40u, my_flags);
  if ( v5 == nullptr )
    goto LABEL_10;
  if ( init_dynamic_array2(
         a1: (unsigned __int8 **)v5 + 2,
         a2: (unsigned __int8 *)8,
         a3: nullptr,
         a4: 0x400u,
         a5: 0x2000u) != 0 )
  {
    my_no_flags_free(ptr: v5);
    goto LABEL_10;
  }
  init_alloc_root(result: (_stat64 *)(v5 + 32), block_size: 0x8000u, pre_alloc_size: 0x8000u);
  v16 = v5;
  hFile = _findfirst64i32(&szWild, &pfd);
  if ( hFile != -1 )
  {
    while ( 1 )
    {
      attrib = pfd.attrib;
      if ( (pfd.attrib & 6) == 0 )
      {
        element = (int)strdup_root(a1: (int *)v5 + 8, str: (unsigned __int8 *)pfd.name);
        if ( element == 0 )
          goto LABEL_10;
        if ( (my_flags & 0x400) != 0 )
        {
          v11 = alloc_root(mem_root: (int *)v5 + 8, length: (const void *)0x38);
          v15 = v11;
          if ( v11 == nullptr )
            goto LABEL_10;
          memset(dst: v11, value: 0, count: 0x38u);
          *((_DWORD *)v15 + 6) = pfd.size;
          *((_DWORD *)v15 + 7) = 0;
          v12 = 256;
          if ( (attrib & 1) == 0 )
            v12 = 384;
          if ( (attrib & 0x10) != 0 )
            v12 |= 0x4000u;
          *((_WORD *)v15 + 3) = v12;
          *((_DWORD *)v15 + 10) = pfd.time_write;
          *((_DWORD *)v15 + 11) = 0;
        }
        else
        {
          v15 = nullptr;
        }
        if ( insert_dynamic(array: (_DWORD *)v5 + 2, (unsigned __int8 *)&element) != 0 )
          goto LABEL_10;
      }
      v13 = hFile;
      if ( _findnext64i32(hFile, &pfd) != 0 )
      {
        _findclose(hFile: v13);
        goto LABEL_31;
      }
    }
  }
  if ( *_errno() != 22 )
  {
LABEL_10:
    v6 = _errno();
    *(_DWORD *)_my_thread_var() = *v6;
    if ( hFile != -1 )
      _findclose(hFile);
    my_dirend(a1: v16);
    if ( (my_flags & 0x18) != 0 )
    {
      v7 = _errno();
      my_error(a1: 12, a2: 36, *(_DWORD *)ap, *v7);
    }
    return nullptr;
  }
LABEL_31:
  *(_DWORD *)v5 = *((_DWORD *)v5 + 2);
  *((_DWORD *)v5 + 1) = *((_DWORD *)v5 + 3);
  if ( (my_flags & 0x200) == 0 )
    my_qsort(base_ptr: v9);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0041DE80
// Name: _my_stat
// Source: json
//------------------------------------------------------------------------------
_stat64 *__cdecl my_stat(char *name, _stat64 *buf, char my_flags)
{
  _stat64 *v3; // esi
  int *v5; // ebp
  _DWORD *v6; // eax

  v3 = buf;
  if ( buf != nullptr || (v3 = (_stat64 *)my_malloc(size: 0x38u, my_flags)) != nullptr )
  {
    if ( my_win_stat(name, buf: v3) == 0 )
      return v3;
    v5 = _errno();
    *(_DWORD *)_my_thread_var() = *v5;
    if ( buf == nullptr )
      my_no_flags_free(ptr: v3);
  }
  if ( (my_flags & 0x18) != 0 )
  {
    v6 = _my_thread_var();
    my_error(a1: 13, a2: 36, name, *v6);
  }
  return nullptr;
}
