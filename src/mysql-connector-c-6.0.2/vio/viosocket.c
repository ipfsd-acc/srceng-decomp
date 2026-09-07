// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/vio/viosocket.c
// Functions: 20
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00417B80
// Name: _vio_read
// Source: json
//------------------------------------------------------------------------------
$BC236CFBD570C18489EB46681F52D83D *__cdecl vio_read(
        $BC236CFBD570C18489EB46681F52D83D *result,
        unsigned __int8 *buf,
        unsigned int size)
{
  return ($BC236CFBD570C18489EB46681F52D83D *)recv(s: (SOCKET)result->locale, (char *)buf, len: size, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00417BA0
// Name: _vio_read_buff
// Source: json
//------------------------------------------------------------------------------
$BC236CFBD570C18489EB46681F52D83D *__cdecl vio_read_buff(
        $BC236CFBD570C18489EB46681F52D83D *result,
        unsigned __int8 *buf,
        unsigned int size)
{
  int *wrefcount; // ecx
  char *locale; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  $BC236CFBD570C18489EB46681F52D83D *v7; // eax
  $BC236CFBD570C18489EB46681F52D83D *v8; // edi
  int *refcount; // eax

  wrefcount = result[19].wrefcount;
  locale = result[20].locale;
  if ( wrefcount >= (int *)locale )
  {
    if ( size >= 0x800 )
    {
      return vio_read(result, buf, size);
    }
    else
    {
      v7 = vio_read(result, buf: (unsigned __int8 *)result[19].refcount, size: 0x4000u);
      v8 = v7;
      if ( v7 != nullptr && v7 != ($BC236CFBD570C18489EB46681F52D83D *)-1 )
      {
        if ( (unsigned int)v7 > size )
        {
          refcount = result[19].refcount;
          result[19].wrefcount = (int *)((char *)refcount + size);
          result[20].locale = (char *)refcount + (_DWORD)v8;
          v8 = ($BC236CFBD570C18489EB46681F52D83D *)size;
        }
        memcpy(dst: buf, src: (unsigned __int8 *)result[19].refcount, count: (unsigned int)v8);
        return v8;
      }
    }
  }
  else
  {
    v5 = size;
    v6 = locale - (char *)wrefcount;
    if ( v6 < size )
      v5 = v6;
    memcpy(dst: buf, src: (unsigned __int8 *)wrefcount, count: v5);
    result[19].wrefcount = (int *)((char *)result[19].wrefcount + v5);
    return ($BC236CFBD570C18489EB46681F52D83D *)v5;
  }
  return v7;
}

//------------------------------------------------------------------------------
// Address: 0x00417C60
// Name: _vio_write
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_write(SOCKET *a1, const char *buf, unsigned int size)
{
  return send(s: *a1, buf, len: size, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00417C80
// Name: _vio_blocking
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_blocking(u_long argp, char a2, bool *a3)
{
  SOCKET *v3; // ecx
  SOCKET v4; // edx
  int result; // eax
  SOCKET v6; // edx
  unsigned int v7; // esi

  v3 = (SOCKET *)argp;
  *a3 = (*(_BYTE *)(argp + 12) & 1) == 0;
  v4 = v3[69];
  result = 0;
  if ( v4 == 3 || v4 == 5 )
    return ((v3[3] & 1) == 0) != a2;
  v6 = v3[3];
  if ( a2 != 0 )
  {
    argp = 0;
    v7 = v6 & 0xFFFFFFFE;
  }
  else
  {
    argp = 1;
    v7 = v6 | 1;
  }
  v3[3] = v7;
  if ( v6 != v7 )
    return ioctlsocket(s: *v3, cmd: -2147195266, &argp);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417D00
// Name: _vio_is_blocking
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vio_is_blocking(const char *vio)
{
  return (vio[12] & 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00417D10
// Name: _vio_fastsend
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_fastsend(SOCKET *a1)
{
  int v1; // ecx
  int result; // eax
  SOCKET v3; // [esp-14h] [ebp-18h]
  int nodelay; // [esp+0h] [ebp-4h] BYREF

  nodelay = v1;
  v3 = *a1;
  nodelay = 1;
  result = setsockopt(s: v3, level: 6, optname: 1, optval: (const char *)&nodelay, optlen: 4);
  if ( result != 0 )
    return -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417D40
// Name: _vio_keepalive
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_keepalive(const wchar_t *vio, char set_keep_alive)
{
  unsigned int v2; // ecx
  int result; // eax
  bool v4; // zf
  unsigned int opt; // [esp+0h] [ebp-4h] BYREF

  opt = v2;
  result = 0;
  v4 = *((_DWORD *)vio + 69) == 3;
  opt = 0;
  if ( !v4 )
  {
    opt = set_keep_alive != 0;
    return setsockopt(s: *(_DWORD *)vio, level: 0xFFFF, optname: 8, optval: (const char *)&opt, optlen: 4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417D80
// Name: _vio_should_retry
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl vio_should_retry()
{
  int Error; // eax

  Error = WSAGetLastError();
  return Error == 10036 || Error == 10004 || Error == 10035;
}

//------------------------------------------------------------------------------
// Address: 0x00417DB0
// Name: _vio_was_interrupted
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl vio_was_interrupted()
{
  int Error; // eax

  Error = WSAGetLastError();
  return Error == 10036 || Error == 10004 || Error == 10035 || Error == 10060;
}

//------------------------------------------------------------------------------
// Address: 0x00417DE0
// Name: _vio_close
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_close(int a1)
{
  int v1; // eax
  int v2; // edi

  v1 = *(_DWORD *)(a1 + 276);
  v2 = 0;
  if ( v1 == 3 )
  {
    v2 = CloseHandle(hObject: *(HANDLE *)(a1 + 4));
  }
  else if ( v1 != 0 )
  {
    if ( shutdown(s: *(_DWORD *)a1, how: 2) != 0 )
      v2 = -1;
    if ( closesocket(s: *(_DWORD *)a1) != 0 )
      v2 = -1;
  }
  *(_DWORD *)(a1 + 276) = 0;
  *(_DWORD *)a1 = -1;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00417E50
// Name: _vio_peer_addr
// Source: json
//------------------------------------------------------------------------------
char __cdecl vio_peer_addr(int a1, char *a2, _WORD *a3, int a4)
{
  void *v4; // ecx
  int v6; // eax
  int v7; // esi
  _EH4_SCOPETABLE *v8; // eax
  int v9; // esi
  unsigned int v10; // eax
  char *v11; // ecx
  char *v12; // edx
  SOCKET v13; // [esp-4h] [ebp-44h]
  int namelen; // [esp+18h] [ebp-28h] BYREF
  char nptr[32]; // [esp+1Ch] [ebp-24h] BYREF

  if ( *(_BYTE *)(a1 + 8) != 0 )
  {
    strmov(dst: v4, dsta: a2, src: "127.0.0.1");
    *a3 = 0;
    return 0;
  }
  else
  {
    v13 = *(_DWORD *)a1;
    namelen = 128;
    if ( getpeername(s: v13, name: (struct sockaddr *)(a1 + 144), &namelen) != 0 )
      return 1;
    v6 = namelen;
    *(_DWORD *)(a1 + 272) = namelen;
    v7 = v6;
    v8 = (_EH4_SCOPETABLE *)`WspiapiGetNameInfo'::`2'::pfGetNameInfo;
    if ( `WspiapiGetNameInfo'::`2'::pfGetNameInfo == 0 )
    {
      v8 = WspiapiLoad(result: (_EH4_SCOPETABLE *)1);
      `WspiapiGetNameInfo'::`2'::pfGetNameInfo = (int)v8;
    }
    v9 = ((int (__stdcall *)(int, int, char *, int, char *, int, int))v8)(
           a1: a1 + 144,
           a2: v7,
           a3: a2,
           a4,
           a5: nptr,
           a6: 32,
           a7: 10);
    WSASetLastError(iError: v9);
    if ( v9 != 0 )
    {
      return 1;
    }
    else
    {
      *a3 = strtol(nptr, endptr: nullptr, ibase: 10);
      v10 = 17;
      v11 = "::ffff:127.0.0.1";
      v12 = a2;
      while ( *(_DWORD *)v12 == *(_DWORD *)v11 )
      {
        v10 -= 4;
        v11 += 4;
        v12 += 4;
        if ( v10 < 4 )
        {
          LOBYTE(v11) = *v11;
          if ( (_BYTE)v11 == *v12 )
            strmov(dst: v11, dsta: a2, src: "127.0.0.1");
          return 0;
        }
      }
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417F70
// Name: _vio_poll_read
// Source: json
//------------------------------------------------------------------------------
bool __cdecl vio_poll_read(unsigned int *a1, unsigned int timeout)
{
  unsigned int v2; // esi
  int v3; // eax
  struct timeval v5; // [esp+4h] [ebp-210h] BYREF
  fd_set readfds; // [esp+Ch] [ebp-208h] BYREF
  fd_set exceptfds; // [esp+110h] [ebp-104h] BYREF

  v2 = *a1;
  v5.tv_sec = timeout;
  v5.tv_usec = 0;
  readfds.fd_array[0] = v2;
  readfds.fd_count = 1;
  exceptfds.fd_array[0] = v2;
  exceptfds.fd_count = 1;
  v3 = select(nfds: v2, &readfds, writefds: nullptr, &exceptfds, timeout: &v5) <= 0;
  if ( v3 != 0 )
    return v3 >= 0;
  return __WSAFDIsSet(fd: v2, a2: &readfds) == 0 && __WSAFDIsSet(fd: v2, a2: &exceptfds) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00418040
// Name: _vio_timeout
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_timeout(SOCKET *a1, unsigned int which, int wait_timeout)
{
  wait_timeout *= 1000;
  return setsockopt(s: *a1, level: 0xFFFF, optname: 4102 - (which != 0), optval: (const char *)&wait_timeout, optlen: 4);
}

//------------------------------------------------------------------------------
// Address: 0x00418080
// Name: _vio_read_pipe
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004180B0
// Name: _vio_write_pipe
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004180E0
// Name: _vio_close_pipe
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl vio_close_pipe(int a1)
{
  BOOL result; // eax

  result = CloseHandle(hObject: *(HANDLE *)(a1 + 4));
  *(_DWORD *)(a1 + 276) = 0;
  *(_DWORD *)a1 = -1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00418110
// Name: _vio_read_shared_memory
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_read_shared_memory($BC236CFBD570C18489EB46681F52D83D *result, unsigned __int8 *buf, int *size)
{
  int *v3; // ebx
  int *refcount; // ecx
  char *wlocale; // eax
  unsigned int wrefcount; // edi
  int *v8; // eax
  void (__cdecl *events)(int, char *, char *, localeinfo_struct *); // [esp+10h] [ebp-8h] BYREF
  int *v11; // [esp+14h] [ebp-4h]

  v3 = size;
  refcount = result[25].refcount;
  events = (void (__cdecl *)(int, char *, char *, localeinfo_struct *))result[24].refcount;
  v11 = refcount;
  while ( 1 )
  {
    if ( result[25].wrefcount == nullptr )
    {
      if ( WaitForMultipleObjects(
             nCount: 2u,
             lpHandles: (const HANDLE *)&events,
             bWaitAll: false,
             dwMilliseconds: 1000 * *((_DWORD *)result[26].wlocale + 15)) != 0 )
        return -1;
      wlocale = (char *)result[24].wlocale;
      result[26].locale = wlocale;
      result[25].wrefcount = *(int **)wlocale;
      result[26].locale = wlocale + 4;
    }
    wrefcount = (unsigned int)size;
    if ( result[25].wrefcount < size )
      wrefcount = (unsigned int)result[25].wrefcount;
    if ( wrefcount > (unsigned int)v3 )
      wrefcount = (unsigned int)v3;
    memcpy(dst: buf, src: (unsigned __int8 *)result[26].locale, count: wrefcount);
    result[25].wrefcount = (int *)((char *)result[25].wrefcount - wrefcount);
    v8 = result[25].wrefcount;
    result[26].locale += wrefcount;
    buf += wrefcount;
    v3 = (int *)((char *)v3 - wrefcount);
    if ( v8 == nullptr && !SetEvent(hEvent: result[25].wlocale) )
      break;
    if ( v3 == nullptr )
      return (int)size;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00418200
// Name: _vio_write_shared_memory
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_write_shared_memory(int a1, unsigned __int8 *buf, unsigned int size)
{
  int result; // eax
  int v5; // edx
  unsigned int v6; // ebx
  unsigned int v7; // esi
  void (__cdecl *events)(int, char *, char *, localeinfo_struct *); // [esp+10h] [ebp-8h] BYREF
  int v9; // [esp+14h] [ebp-4h]

  result = size;
  v5 = *(_DWORD *)(a1 + 408);
  v6 = size;
  events = *(void (__cdecl **)(int, char *, char *, localeinfo_struct *))(a1 + 396);
  v9 = v5;
  if ( size != 0 )
  {
    while ( WaitForMultipleObjects(
              nCount: 2u,
              lpHandles: (const HANDLE *)&events,
              bWaitAll: false,
              dwMilliseconds: 1000 * *(_DWORD *)(*(_DWORD *)(a1 + 420) + 56)) == 0 )
    {
      v7 = 16000;
      if ( v6 <= 0x3E80 )
        v7 = v6;
      **(_DWORD **)(a1 + 388) = v7;
      memcpy(dst: (unsigned __int8 *)(*(_DWORD *)(a1 + 388) + 4), src: buf, count: v7);
      v6 -= v7;
      buf += v7;
      if ( !SetEvent(hEvent: *(HANDLE *)(a1 + 400)) )
        break;
      if ( v6 == 0 )
        return size;
    }
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004182B0
// Name: _vio_close_shared_memory
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_close_shared_memory(int a1)
{
  int v1; // edi
  LPCVOID v3; // [esp-4h] [ebp-Ch]

  v1 = 0;
  if ( *(_DWORD *)(a1 + 276) != 0 )
  {
    SetEvent(hEvent: *(HANDLE *)(a1 + 408));
    v3.cElems = *(_DWORD *)(a1 + 388);
    v1 = !UnmapViewOfFile(lpBaseAddress: v3);
    if ( !CloseHandle(hObject: *(HANDLE *)(a1 + 392)) )
      ++v1;
    if ( !CloseHandle(hObject: *(HANDLE *)(a1 + 396)) )
      ++v1;
    if ( !CloseHandle(hObject: *(HANDLE *)(a1 + 400)) )
      ++v1;
    if ( !CloseHandle(hObject: *(HANDLE *)(a1 + 404)) )
      ++v1;
    if ( !CloseHandle(hObject: *(HANDLE *)(a1 + 384)) )
      ++v1;
    if ( !CloseHandle(hObject: *(HANDLE *)(a1 + 408)) )
      ++v1;
  }
  *(_DWORD *)(a1 + 276) = 0;
  *(_DWORD *)a1 = -1;
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x004303D0
// Name: _vio_ignore_timeout
// Source: json
//------------------------------------------------------------------------------
void vio_ignore_timeout()
{
  ;
}
