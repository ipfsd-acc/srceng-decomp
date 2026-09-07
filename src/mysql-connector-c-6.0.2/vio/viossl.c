// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/vio/viossl.c
// Functions: 8
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x004175A0
// Name: _vio_ssl_read
// Source: json
//------------------------------------------------------------------------------
void __cdecl vio_ssl_read($BC236CFBD570C18489EB46681F52D83D *result, unsigned __int8 *buf, unsigned int size)
{
  int (__cdecl *v3)(void (__cdecl *const *)(IConVar *, const char *, float), void (__cdecl *const *)(IConVar *, const char *, float)); // ecx

  yaSSL_read(ssl: v3, buffer: result[23].wrefcount, a3: buf, sz: size);
}

//------------------------------------------------------------------------------
// Address: 0x004175C0
// Name: _vio_ssl_write
// Source: json
//------------------------------------------------------------------------------
void __thiscall vio_ssl_write(void *this)
{
  yaSSL_write(ssl: (Color)this);
}

//------------------------------------------------------------------------------
// Address: 0x004175E0
// Name: _vio_ssl_close
// Source: json
//------------------------------------------------------------------------------
int __cdecl vio_ssl_close(int a1)
{
  SplitScreenSlottedConVarRef *v1; // esi
  const char *v2; // ecx

  v1 = *(SplitScreenSlottedConVarRef **)(a1 + 380);
  if ( v1 != nullptr )
  {
    yaSSL_set_quiet_shutdown(result: v1, a2: 1);
    yaSSL_shutdown(ssl: v2, ssla: (yaSSL *)v1);
  }
  return vio_close(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00417620
// Name: _vio_ssl_delete
// Source: json
//------------------------------------------------------------------------------
void __cdecl vio_ssl_delete(int a1)
{
  if ( a1 != 0 )
  {
    if ( *(_DWORD *)(a1 + 276) == 4 )
      vio_ssl_close(a1);
    if ( *(_DWORD *)(a1 + 380) != 0 )
    {
      yaSSL_free();
      *(_DWORD *)(a1 + 380) = 0;
    }
    vio_delete(a1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417670
// Name: ssl_do
// Source: json
//------------------------------------------------------------------------------
int __usercall ssl_do@<eax>(
        u_long vio@<edi>,
        HWND__ *(__stdcall *ptr)(),
        localeinfo_struct *timeout,
        int (__cdecl *a4)(CThreadSyncObject *))
{
  const char *v4; // ecx
  CThreadSyncObject *v5; // esi
  int v7; // ecx
  yaSSL::SSL_SESSION *session; // eax
  bool v9; // cl
  void *v10; // ecx
  unsigned int v11; // eax
  char unused; // [esp+7h] [ebp-5h] BYREF
  int was_blocking; // [esp+8h] [ebp-4h] BYREF

  vio_blocking(argp: vio, a2: 1, a3: (int)&was_blocking);
  v5 = (CThreadSyncObject *)yaSSL_new(serverSide: *(struct SSL_CTX **)ptr);
  if ( v5 != nullptr )
  {
    yaSSL_clear(ssl: v4);
    session = (yaSSL::SSL_SESSION *)yaSSL_get_session(ssl: v7, a2: (int)v5);
    yaSSL_SESSION_set_timeout(sess: v9, sessa: session, t: (unsigned int)timeout);
    yaSSL_set_fd(a1: v5, c: *(QueuedPacket_t ***)vio);
    if ( a4(a1: v5) >= 1 )
    {
      yaSSL_get_fd(ssl: v10, a2: v5);
      vio_reset((threadmbcinfostruct *)vio, sd: 4u, a3: v11, hPipe: nullptr, flags: 0);
      *(_DWORD *)(vio + 380) = v5;
      return 0;
    }
    else
    {
      report_errors();
      yaSSL_free();
      vio_blocking(argp: vio, a2: was_blocking, a3: (int)&unused);
      return 1;
    }
  }
  else
  {
    report_errors();
    vio_blocking(argp: vio, a2: was_blocking, a3: (int)&unused);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417740
// Name: _sslconnect
// Source: json
//------------------------------------------------------------------------------
int __cdecl sslconnect(HWND__ *(__stdcall *ptr)(), u_long vio, localeinfo_struct *timeout)
{
  return ssl_do(vio, ptr, timeout, a4: (int (__cdecl *)(CThreadSyncObject *))yaSSL_connect);
}

//------------------------------------------------------------------------------
// Address: 0x00417760
// Name: _vio_ssl_blocking
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl vio_ssl_blocking(int a1, char a2, _BYTE *a3)
{
  *a3 = 1;
  return a2 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004177D0
// Name: report_errors
// Source: json
//------------------------------------------------------------------------------
int report_errors()
{
  int result; // eax
  tagShutdownType data; // [esp+4h] [ebp-Ch] BYREF

  do
    result = yaSSL::RC4::get_ivSize(this: (ConVar *)&data);
  while ( result != 0 );
  return result;
}
