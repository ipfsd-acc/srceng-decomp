// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_read.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0040FCD0
// Name: _my_read
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl my_read(int fd, char *lpBuffer, unsigned int NumberOfBytesRead, __int16 a4)
{
  unsigned int v4; // edi
  int v5; // esi
  int *v6; // ebp
  __int16 v7; // ax
  char v8; // al
  char v10; // al

  v4 = NumberOfBytesRead;
  *_errno() = 0;
  v5 = my_win_read(a1: fd, lpBuffer, NumberOfBytesRead);
  if ( v5 == NumberOfBytesRead )
  {
LABEL_20:
    v7 = a4;
LABEL_21:
    if ( (v7 & 6) != 0 )
      return 0;
    if ( (v7 & 0x200) != 0 )
      return NumberOfBytesRead;
    return v5;
  }
  while ( 1 )
  {
    v6 = _errno();
    *(_DWORD *)_my_thread_var() = *v6;
    if ( *_errno() == 0 || (v7 = a4, v5 != -1) && (a4 & 6) != 0 )
    {
      *(_DWORD *)_my_thread_var() = 176;
      v7 = a4;
    }
    if ( v5 == 0 || v5 == -1 )
    {
      if ( *_errno() == 4 )
        goto LABEL_19;
      v7 = a4;
    }
    if ( (v7 & 0x1A) != 0 )
      break;
LABEL_14:
    if ( v5 == -1 || (v7 & 6) != 0 && (v7 & 0x200) == 0 )
      return -1;
    if ( (v7 & 0x200) == 0 )
      goto LABEL_21;
    lpBuffer += v5;
    v4 -= v5;
LABEL_19:
    *_errno() = 0;
    v5 = my_win_read(a1: fd, lpBuffer, NumberOfBytesRead: v4);
    if ( v5 == v4 )
      goto LABEL_20;
  }
  if ( v5 != -1 )
  {
    if ( (v7 & 6) != 0 )
    {
      _my_thread_var();
      v8 = my_filename(fd);
      my_error(a1: 9, a2: 36, ap: v8);
      v7 = a4;
    }
    goto LABEL_14;
  }
  _my_thread_var();
  v10 = my_filename(fd);
  my_error(a1: 2, a2: 36, ap: v10);
  return -1;
}
