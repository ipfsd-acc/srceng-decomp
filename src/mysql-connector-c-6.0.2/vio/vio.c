// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/vio/vio.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00414850
// Name: _vio_delete
// Source: json
//------------------------------------------------------------------------------
void __cdecl vio_delete(int a1)
{
  if ( a1 != 0 )
  {
    if ( *(_DWORD *)(a1 + 276) != 0 )
      (*(void (__cdecl **)(int))(a1 + 372))(a1);
    my_no_flags_free(ptr: *(void **)(a1 + 312));
    my_no_flags_free(ptr: (void *)a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00414890
// Name: vio_init
// Source: json
//------------------------------------------------------------------------------
void __usercall vio_init(threadmbcinfostruct *vio@<esi>, char a2@<al>, int a3@<edi>, unsigned int sd, void *hPipe)
{
  unsigned __int8 *v6; // eax
  $BC236CFBD570C18489EB46681F52D83D *(*v7)($BC236CFBD570C18489EB46681F52D83D *); // eax

  memset(dst: (unsigned __int8 *)vio, value: 0, count: 0x1A8u);
  *(_DWORD *)&vio->mbctype[248] = a3;
  vio->refcount = sd;
  vio->mbcodepage = (int)hPipe;
  LOBYTE(vio->ismbcodepage) = a2 & 1;
  if ( (a2 & 2) != 0 )
  {
    v6 = my_malloc(size: 0x4000u, my_flags: 16);
    *(_DWORD *)&vio->mbcasemap[27] = v6;
    if ( v6 == nullptr )
      a2 &= ~2u;
  }
  *(_DWORD *)&vio->mbcasemap[43] = yaSSL::Socket::get_lastError;
  if ( a3 == 3 )
  {
    *(_DWORD *)&vio->mbcasemap[39] = vio_delete;
    *(_DWORD *)&vio->mbcasemap[47] = vio_read_pipe;
    *(_DWORD *)&vio->mbcasemap[51] = vio_write_pipe;
    *(_DWORD *)&vio->mbcasemap[87] = vio_close_pipe;
    *(_DWORD *)&vio->mbcasemap[91] = vio_ignore_timeout;
LABEL_13:
    *(_DWORD *)&vio->mbcasemap[55] = vio_blocking;
    goto LABEL_14;
  }
  if ( a3 == 5 )
  {
    *(_DWORD *)&vio->mbcasemap[39] = vio_delete;
    *(_DWORD *)&vio->mbcasemap[47] = vio_read_shared_memory;
    *(_DWORD *)&vio->mbcasemap[51] = vio_write_shared_memory;
    *(_DWORD *)&vio->mbcasemap[87] = vio_close_shared_memory;
    *(_DWORD *)&vio->mbcasemap[91] = vio_ignore_timeout;
    goto LABEL_13;
  }
  if ( a3 != 4 )
  {
    *(_DWORD *)&vio->mbcasemap[39] = vio_delete;
    v7 = vio_read_buff;
    if ( (a2 & 2) == 0 )
      v7 = vio_read;
    *(_DWORD *)&vio->mbcasemap[47] = v7;
    *(_DWORD *)&vio->mbcasemap[51] = vio_write;
    *(_DWORD *)&vio->mbcasemap[87] = vio_close;
    *(_DWORD *)&vio->mbcasemap[91] = vio_timeout;
    goto LABEL_13;
  }
  *(_DWORD *)&vio->mbcasemap[39] = vio_ssl_delete;
  *(_DWORD *)&vio->mbcasemap[47] = vio_ssl_read;
  *(_DWORD *)&vio->mbcasemap[51] = vio_ssl_write;
  *(_DWORD *)&vio->mbcasemap[87] = vio_ssl_close;
  *(_DWORD *)&vio->mbcasemap[55] = vio_ssl_blocking;
  *(_DWORD *)&vio->mbcasemap[91] = vio_timeout;
LABEL_14:
  *(_DWORD *)&vio->mbcasemap[59] = vio_is_blocking;
  *(_DWORD *)&vio->mbcasemap[71] = vio_peer_addr;
  *(_DWORD *)&vio->mbcasemap[83] = vio_was_interrupted;
  *(_DWORD *)&vio->mbcasemap[79] = vio_should_retry;
  *(_DWORD *)&vio->mbcasemap[63] = vio_keepalive;
  *(_DWORD *)&vio->mbcasemap[67] = vio_fastsend;
}

//------------------------------------------------------------------------------
// Address: 0x00414A30
// Name: _vio_reset
// Source: json
//------------------------------------------------------------------------------
void __cdecl vio_reset(threadmbcinfostruct *vio, unsigned int sd, unsigned int a3, void *hPipe, char flags)
{
  my_no_flags_free(ptr: *(void **)&vio->mbcasemap[27]);
  vio_init(vio, a2: flags, a3: sd, sd: a3, hPipe);
}

//------------------------------------------------------------------------------
// Address: 0x00414A60
// Name: _vio_new
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__stdcall vio_new(volatile int *sd, unsigned int flags, char a3)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v4; // esi
  const char *v5; // eax
  unsigned int arg; // [esp+4h] [ebp-4h] BYREF

  result = my_malloc(size: 0x1A8u, my_flags: 16);
  v4 = result;
  if ( result != nullptr )
  {
    vio_init(vio: (threadmbcinfostruct *)result, a2: a3, a3: flags, (unsigned int)sd, hPipe: nullptr);
    v5 = "socket (%d)";
    if ( *((_DWORD *)v4 + 69) != 2 )
      v5 = "TCP/IP (%d)";
    sprintf(string: (char *)v4 + 280, format: v5, *(_DWORD *)v4);
    arg = 0;
    ioctlsocket(s: (SOCKET)sd, cmd: -2147195266, argp: &arg);
    *((_DWORD *)v4 + 3) &= ~1u;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414AE0
// Name: _vio_new_win32pipe
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl vio_new_win32pipe(void *hPipe)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v2; // esi

  result = my_malloc(size: 0x1A8u, my_flags: 16);
  v2 = result;
  if ( result != nullptr )
  {
    vio_init(vio: (threadmbcinfostruct *)result, a2: 1, a3: 3, sd: 0, hPipe);
    strmov(dst: v2 + 280, dsta: (char *)v2 + 280, src: "named pipe");
    return v2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00414B30
// Name: _vio_new_win32shared_memory
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__cdecl vio_new_win32shared_memory(int a1, int a2, int a3, int a4, int a5, int a6, int a7, void *dst)
{
  unsigned __int8 *result; // eax
  unsigned __int8 *v9; // esi

  result = my_malloc(size: 0x1A8u, my_flags: 16);
  v9 = result;
  if ( result != nullptr )
  {
    vio_init(vio: (threadmbcinfostruct *)result, a2: 1, a3: 5, sd: 0, hPipe: nullptr);
    *((_DWORD *)v9 + 96) = a2;
    *((_DWORD *)v9 + 98) = a4;
    *((_DWORD *)v9 + 99) = a5;
    *((_DWORD *)v9 + 97) = a3;
    *((_DWORD *)v9 + 104) = a3;
    *((_DWORD *)v9 + 100) = a6;
    *((_DWORD *)v9 + 101) = a7;
    *((_DWORD *)v9 + 102) = dst;
    *((_DWORD *)v9 + 103) = 0;
    *((_DWORD *)v9 + 105) = a1;
    strmov(dst, dsta: (char *)v9 + 280, src: "shared memory");
    return v9;
  }
  return result;
}
