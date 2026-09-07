// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/vio/viosslfactories.c
// Functions: 6
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00417780
// Name: get_dh512
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall get_dh512(const CSplitScreenAddedConVar *this)
{
  CSplitScreenAddedConVar *result; // eax
  _DWORD *v2; // esi
  IMemAlloc *v3; // eax
  bool v4; // zf

  result = yaDH_new(this);
  v2 = &result->ConVar::ConCommandBase::__vftable;
  if ( result != nullptr )
  {
    result->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)yaBN_bin2bn(
                                                                                  num: (unsigned __int16)&dh512_p,
                                                                                  sz: 0x40u,
                                                                                  a3: nullptr);
    v3 = yaBN_bin2bn(num: (unsigned __int16)dh512_g, sz: 1u, a3: nullptr);
    v4 = *v2 == 0;
    v2[1] = v3;
    if ( !v4 && v3 != nullptr )
    {
      return (CSplitScreenAddedConVar *)v2;
    }
    else
    {
      yaDH_free(a1: v2);
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00417800
// Name: vio_set_cert_stuff
// Source: json
//------------------------------------------------------------------------------
int __usercall vio_set_cert_stuff@<eax>(
        char *a1@<eax>,
        yaSSL::SSL_CTX *a2@<ebx>,
        const Quaternion *a3@<ebp>,
        char *a4@<esi>)
{
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v8; // eax
  _iobuf *v9; // eax
  const char *v10; // [esp-8h] [ebp-Ch]
  char *v11; // [esp-4h] [ebp-8h]

  if ( a4 == nullptr )
    return 0;
  if ( (int)yaSSL_CTX_use_certificate_file(a1: (unsigned int)a2, a2: a3, file: a2, a4, format: 11) <= 0 )
  {
    v11 = a4;
    v10 = "SSL error: Unable to get certificate from '%s'\n";
LABEL_4:
    v5 = __iob_func();
    fprintf(str: v5 + 2, format: v10, v11);
    v6 = __iob_func();
    fflush(stream: v6 + 2);
    return 1;
  }
  if ( a1 == nullptr )
    a1 = a4;
  if ( (int)yaSSL_CTX_use_PrivateKey_file(a1: (unsigned int)a2, a2: a3, file: a2, a4: a1, format: 11) <= 0 )
  {
    v11 = a1;
    v10 = "SSL error: Unable to get private key from '%s'\n";
    goto LABEL_4;
  }
  if ( yaSSL_CTX_set_default_verify_paths() != 0 )
    return 0;
  v8 = __iob_func();
  fprintf(str: v8 + 2, format: "SSL error: Private key does not match the certificate public key\n");
  v9 = __iob_func();
  fflush(stream: v9 + 2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x004178B0
// Name: vio_verify_callback
// Source: json
//------------------------------------------------------------------------------
wchar_t *__cdecl vio_verify_callback(wchar_t *ok, ShortVector **ctx)
{
  yaSSL::X509 *current_cert; // eax
  struct X509_NAME *subject_name; // eax
  const char *v4; // ecx
  wchar_t *v5; // edi
  yaSSL::SSL_CTX *v6; // eax
  const char *v7; // ecx
  char *v9; // [esp-8h] [ebp-114h]
  int v10; // [esp-4h] [ebp-110h]
  __int16 v11; // [esp+0h] [ebp-10Ch]
  int (__stdcall *bufa[64])(_EXCEPTION_POINTERS *); // [esp+8h] [ebp-104h] BYREF

  current_cert = (yaSSL::X509 *)yaX509_STORE_CTX_get_current_cert(a1: (int)ctx);
  subject_name = yaX509_get_subject_name(a1: current_cert);
  yaX509_NAME_oneline(name: v4, buffer: (yaSSL::SSL_CTX *)subject_name, buffera: (char *)bufa, sz: 256);
  v5 = ok;
  if ( ok == nullptr )
  {
    yaX509_STORE_CTX_get_error(a1: (int)ctx);
    v5 = (wchar_t *)(verify_depth >= yaX509_STORE_CTX_get_error_depth(a1: (int)ctx));
  }
  if ( *ctx == (ShortVector *)2 )
  {
    yaX509_get_issuer_name(a1: ctx[2], a2: (__int16)bufa, a3: 256, a4: v11);
    yaX509_NAME_oneline(name: v7, buffer: v6, buffera: v9, sz: v10);
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00417980
// Name: check_ssl_init
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004179B0
// Name: new_VioSSLFd
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00417AA0
// Name: _new_VioSSLConnectorFd
// Source: json
//------------------------------------------------------------------------------
yaSSL::SSL_CTX **__cdecl new_VioSSLConnectorFd(int a1, int a2, int a3, int a4)
{
  const CSplitScreenAddedConVar *v4; // ecx
  BOOL v5; // edi
  int v6; // eax
  yaSSL::SSL_CTX **result; // eax
  const char *v8; // ecx
  yaSSL::SSL_CTX **v9; // esi

  v5 = true;
  if ( a3 == 0 )
    v5 = a4 != 0;
  v6 = yaTLSv1_client_method(this: v4);
  result = (yaSSL::SSL_CTX **)new_VioSSLFd(a1, a2, a3, a4, a5: v6);
  v9 = result;
  if ( result != nullptr )
  {
    yaSSL_CTX_set_verify(
      ctx: v8,
      mode: *result,
      a3: v5,
      vc: (int (__cdecl *)(int, struct X509_STORE_CTX *))vio_verify_callback);
    return v9;
  }
  return result;
}
