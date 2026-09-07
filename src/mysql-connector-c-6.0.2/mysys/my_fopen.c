// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_fopen.c
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00424360
// Name: _my_fclose
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_fclose(_iobuf *a1, char a2)
{
  unsigned int v2; // esi
  int v3; // edi
  int *v4; // ebx
  const char *v5; // eax
  int v6; // esi
  int v8; // [esp-4h] [ebp-Ch]

  EnterCriticalSection(lpCriticalSection: &THR_LOCK_open);
  v2 = my_fileno(file: a1);
  v3 = my_win_fclose(file: a1);
  if ( v3 >= 0 )
  {
    --my_stream_opened;
  }
  else
  {
    v4 = _errno();
    *(_DWORD *)_my_thread_var() = *v4;
    if ( (a2 & 0x18) != 0 )
    {
      v8 = *_errno();
      v5 = my_filename(fd: v2);
      my_error(a1: 4, a2: 36, v5, v8);
    }
  }
  if ( v2 < my_file_limit )
  {
    v6 = 16 * v2;
    if ( *(_DWORD *)((char *)my_file_info + v6 + 12) != 0 )
    {
      *(_DWORD *)((char *)my_file_info + v6 + 12) = 0;
      my_no_flags_free(ptr: *(void **)((char *)my_file_info + v6));
    }
  }
  LeaveCriticalSection(lpCriticalSection: &THR_LOCK_open);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00424410
// Name: make_ftype
// Source: json
//------------------------------------------------------------------------------
_BYTE *__usercall make_ftype@<eax>(_BYTE *a1@<eax>, __int16 a2@<cx>)
{
  _BYTE *result; // eax

  if ( (a2 & 1) != 0 )
  {
    *a1 = (a2 & 8) != 0 ? 97 : 119;
  }
  else if ( (a2 & 2) != 0 )
  {
    if ( (a2 & 0x300) != 0 )
    {
      *a1++ = 119;
      *a1 = 43;
    }
    else
    {
      if ( (a2 & 8) != 0 )
        *a1 = 97;
      else
        *a1 = 114;
      *++a1 = 43;
    }
  }
  else
  {
    *a1 = 114;
  }
  result = a1 + 1;
  if ( a2 < 0 )
    *result++ = 98;
  *result = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424470
// Name: _my_fopen
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl my_fopen(char *filename, int a2, char a3)
{
  _iobuf *v3; // eax
  _iobuf *v4; // ebp
  unsigned int v5; // esi
  int v7; // esi
  int *v8; // esi
  _DWORD *v9; // eax
  char type[8]; // [esp+10h] [ebp-Ch] BYREF

  make_ftype(a1: type, a2);
  v3 = my_win_fopen(filename, type);
  v4 = v3;
  if ( v3 != nullptr )
  {
    v5 = my_fileno(file: v3);
    if ( v5 >= my_file_limit )
    {
      InterlockedIncrement(lpAddend: &my_stream_opened);
      return v4;
    }
    EnterCriticalSection(lpCriticalSection: &THR_LOCK_open);
    v7 = 16 * v5;
    *(_DWORD *)((char *)my_file_info + v7) = my_strdup(from: filename, my_flags: a3);
    if ( *(_DWORD *)((char *)my_file_info + v7) != 0 )
    {
      ++my_stream_opened;
      ++my_file_total_opened;
      *(_DWORD *)((char *)my_file_info + v7 + 12) = 3;
      LeaveCriticalSection(lpCriticalSection: &THR_LOCK_open);
      return v4;
    }
    LeaveCriticalSection(lpCriticalSection: &THR_LOCK_open);
    my_fclose(a1: v4, a2: a3);
    *(_DWORD *)_my_thread_var() = 12;
  }
  else
  {
    v8 = _errno();
    *(_DWORD *)_my_thread_var() = *v8;
  }
  if ( (a3 & 0x19) != 0 )
  {
    v9 = _my_thread_var();
    my_error(a1: a2 != 0 ? 1 : 29, a2: 36, filename, *v9);
  }
  return nullptr;
}
