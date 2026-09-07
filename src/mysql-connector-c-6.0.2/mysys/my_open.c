// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_open.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040F880
// Name: _my_close
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_close(unsigned int fd, char a2)
{
  int v2; // edi
  int *v3; // ebx
  char v4; // al
  int v5; // esi

  EnterCriticalSection(lpCriticalSection: &THR_LOCK_open);
  v2 = my_win_close(fd);
  if ( v2 != 0 )
  {
    v3 = _errno();
    *(_DWORD *)_my_thread_var() = *v3;
    if ( (a2 & 0x18) != 0 )
    {
      _errno();
      v4 = my_filename(fd);
      my_error(a1: 4, a2: 36, ap: v4);
    }
  }
  if ( fd < my_file_limit )
  {
    v5 = 16 * fd;
    if ( *((_DWORD *)my_file_info + 4 * fd + 3) != 0 )
    {
      my_no_flags_free(ptr: *(void **)((char *)my_file_info + v5));
      *(_DWORD *)((char *)my_file_info + v5 + 12) = 0;
    }
  }
  --my_file_opened;
  LeaveCriticalSection(lpCriticalSection: &THR_LOCK_open);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0040F920
// Name: _my_register_filename
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_register_filename(unsigned int fd, char *ap, int a3, int a4, char a5)
{
  int *v6; // esi
  int v7; // esi

  if ( (int)fd < 2048 )
  {
    v6 = _errno();
    *(_DWORD *)_my_thread_var() = *v6;
  }
  else if ( fd < my_file_limit )
  {
    EnterCriticalSection(lpCriticalSection: &THR_LOCK_open);
    *((_DWORD *)my_file_info + 4 * fd) = my_strdup(from: ap, my_flags: a5);
    if ( *((_DWORD *)my_file_info + 4 * fd) != 0 )
    {
      ++my_file_opened;
      ++my_file_total_opened;
      *((_DWORD *)my_file_info + 4 * fd + 3) = a3;
      LeaveCriticalSection(lpCriticalSection: &THR_LOCK_open);
      return fd;
    }
    LeaveCriticalSection(lpCriticalSection: &THR_LOCK_open);
    *(_DWORD *)_my_thread_var() = 12;
    my_close(fd, a2: a5);
  }
  else
  {
    *(_DWORD *)_my_thread_var() = 24;
    my_close(fd, a2: a5);
  }
  if ( (a5 & 0x19) != 0 )
  {
    v7 = 23;
    if ( *(_DWORD *)_my_thread_var() != 24 )
      v7 = a4;
    _my_thread_var();
    my_error(a1: v7, a2: 36, (char)ap);
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0040FA20
// Name: _my_open
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_open(char *lpFileName, int a2, char a3)
{
  unsigned int v3; // eax

  v3 = my_win_open(lpFileName, a2);
  return my_register_filename(fd: v3, ap: lpFileName, a3: 1, a4: 29, a5: a3);
}
