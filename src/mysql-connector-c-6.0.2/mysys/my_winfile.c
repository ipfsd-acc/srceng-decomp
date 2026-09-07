// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/my_winfile.c
// Functions: 12
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00418E00
// Name: _my_open_osfhandle
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_open_osfhandle(int a1, int a2)
{
  int v2; // esi
  unsigned int v3; // ecx
  _DWORD *v4; // eax
  _DWORD *v5; // eax

  v2 = -1;
  EnterCriticalSection(lpCriticalSection: &THR_LOCK_open);
  v3 = 2048;
  if ( my_file_limit > 0x800 )
  {
    v4 = (_DWORD *)((char *)my_file_info + 32772);
    while ( *v4 != 0 )
    {
      ++v3;
      v4 += 4;
      if ( v3 >= my_file_limit )
        goto LABEL_7;
    }
    v5 = (_DWORD *)((char *)my_file_info + 16 * v3);
    v5[1] = a1;
    v5[3] = 1;
    v5[2] = a2;
    v2 = v3;
  }
LABEL_7:
  LeaveCriticalSection(lpCriticalSection: &THR_LOCK_open);
  if ( v2 == -1 )
    *_errno() = 24;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00418E80
// Name: invalidate_fd
// Source: json
//------------------------------------------------------------------------------
int __usercall invalidate_fd@<eax>(void *fd@<eax>)
{
  int result; // eax

  result = 16 * (_DWORD)fd;
  *(_DWORD *)((char *)my_file_info + result + 4) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418EA0
// Name: _my_get_osfhandle
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_get_osfhandle(int a1)
{
  return *((_DWORD *)my_file_info + 4 * a1 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x00418EC0
// Name: _my_win_sopen
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00419160
// Name: _my_win_open
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_win_open(LPCSTR lpFileName, int a2)
{
  return my_win_sopen(lpFileName, a2: a2 | 0x8000, a3: 64, a4: 384);
}

//------------------------------------------------------------------------------
// Address: 0x00419180
// Name: _my_win_close
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_win_close(void *fd)
{
  void *osfhandle; // eax
  ExprNode *v3; // ecx

  osfhandle = (void *)my_get_osfhandle(a1: (int)fd);
  if ( CloseHandle(hObject: osfhandle) )
  {
    invalidate_fd(fd);
    return 0;
  }
  else
  {
    GetLastError();
    my_osmaperr(oserrno: v3);
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004191C0
// Name: _my_win_read
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00419220
// Name: my_get_stdfile_descriptor
// Source: json
//------------------------------------------------------------------------------
int __usercall my_get_stdfile_descriptor@<eax>(_iobuf *a1@<esi>)
{
  DWORD v1; // eax
  HANDLE StdHandle; // eax

  if ( a1 == __iob_func() )
  {
    v1 = -10;
  }
  else if ( a1 == &__iob_func()[1] )
  {
    v1 = -11;
  }
  else
  {
    if ( a1 != &__iob_func()[2] )
      return -1;
    v1 = -12;
  }
  StdHandle = GetStdHandle(nStdHandle: v1);
  if ( StdHandle != (HANDLE)-1 )
    return my_open_osfhandle(a1: (int)StdHandle, a2: 0);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00419270
// Name: _my_win_fileno
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_win_fileno(_iobuf *file)
{
  int v1; // eax
  int osfhandle; // edi
  int result; // eax
  _DWORD *i; // ecx

  v1 = fileno(stream: file);
  osfhandle = _get_osfhandle(fh: v1);
  result = 2048;
  if ( my_file_limit <= 0x800 )
    return my_get_stdfile_descriptor(a1: file);
  for ( i = (_DWORD *)((char *)my_file_info + 32772); *i != osfhandle; i += 4 )
  {
    if ( ++result >= my_file_limit )
      return my_get_stdfile_descriptor(a1: file);
  }
  if ( result == -1 )
    return my_get_stdfile_descriptor(a1: file);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004192D0
// Name: _my_win_fopen
// Source: json
//------------------------------------------------------------------------------
_iobuf *__cdecl my_win_fopen(const char *filename, char *type)
{
  ExprNode **v2; // ecx
  int v3; // ebx
  int v4; // eax
  _iobuf *v6; // esi
  int v7; // eax
  int v8; // eax
  int osfhandle; // eax

  v3 = 0;
  check_if_legal_filename(path: v2);
  if ( v4 != 0 )
  {
    *_errno() = 13;
    return nullptr;
  }
  v6 = fopen(file: filename, mode: type);
  if ( v6 == nullptr )
    return nullptr;
  strchr(string: (unsigned __int8 *)type, chr: 0x61u);
  if ( v7 != 0 )
    v3 = 8;
  v8 = fileno(stream: v6);
  osfhandle = _get_osfhandle(fh: v8);
  if ( my_open_osfhandle(a1: osfhandle, a2: v3) < 0 )
  {
    fclose(stream: v6);
    return nullptr;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x00419350
// Name: _my_win_fclose
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_win_fclose(_iobuf *file)
{
  void *v1; // esi

  v1 = (void *)my_fileno(file);
  if ( (int)v1 < 0 || fclose(stream: file) < 0 )
    return -1;
  invalidate_fd(fd: v1);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00419390
// Name: _my_win_stat
// Source: json
//------------------------------------------------------------------------------
int __cdecl my_win_stat(char *name, _stat64 *buf)
{
  int v2; // ecx
  _BYTE FileInformation[28]; // [esp+8h] [ebp-24h] BYREF
  int v5; // [esp+24h] [ebp-8h]
  int v6; // [esp+28h] [ebp-4h]

  if ( _stat64(name, buf) != 0 )
    return -1;
  if ( GetFileAttributesExA(lpFileName: name, fInfoLevelId: GetFileExInfoStandard, lpFileInformation: FileInformation) )
  {
    v2 = v5;
    LODWORD(buf->st_size) = v6;
    HIDWORD(buf->st_size) = v2;
  }
  return 0;
}
