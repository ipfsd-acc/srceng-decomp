// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/handshake.cpp
// Functions: 19
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\handshake.h"

//------------------------------------------------------------------------------
// Address: 0x0042C060
// Name: void yaSSL::buildClientHello(class yaSSL::SSL __near &,class yaSSL::ClientHello __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::buildClientHello(yaSSL *this, CUtlString *a2)
{
  __int16 m_nGrowSize; // si
  ShortVector *v3; // eax
  int v4; // eax
  char *v5; // eax
  char *v6; // eax
  CThreadSyncObject *v7; // eax
  yaSSL::Security *v8; // eax
  ShortVector *resume; // eax
  const void *v10; // eax
  char *v11; // eax
  unsigned __int16 v12; // ax
  char *v13; // eax
  const st_mysql_methods *v14; // eax
  unsigned int v15; // [esp-4h] [ebp-10h]
  const CUtlMemory<KeyValues *,int>::Iterator_t *v16; // [esp-4h] [ebp-10h]
  int v17; // [esp+0h] [ebp-Ch]

  m_nGrowSize = a2->m_Storage.m_Memory.m_nGrowSize;
  v3 = (ShortVector *)yaSSL::SSL::useSecurity((char *)this);
  yaSSL::sslHashes::get_MD5(this: v3);
  *(_WORD *)(v4 + 304) = m_nGrowSize;
  yaSSL::sslHashes::get_MD5((ShortVector *)this);
  v6 = yaSSL::States::useServer(this: v5);
  yaSSL::RandomPool::Fill(
    this: (yaSSL::RandomPool *)v6,
    dst: (unsigned __int8 *)&a2->m_Storage.m_Memory.m_nGrowSize + 2,
    sz: 0x20u);
  v7 = (CThreadSyncObject *)yaSSL::SSL::useSecurity((char *)this);
  if ( yaSSL::Security::get_resuming(this: v7) != 0 )
  {
    BYTE2(a2[2].m_Storage.m_Memory.m_nGrowSize) = 32;
    v8 = (yaSSL::Security *)yaSSL::SSL::useSecurity((char *)this);
    resume = (ShortVector *)yaSSL::Security::get_resume(this: v8);
    yaSSL::sslHashes::get_MD5(this: resume);
    qmemcpy((char *)&a2[2].m_Storage.m_Memory.m_nGrowSize + 3, v10, 0x20u);
  }
  else
  {
    BYTE2(a2[2].m_Storage.m_Memory.m_nGrowSize) = 0;
  }
  v11 = (char *)yaSSL::SSL::useSecurity((char *)this);
  v12 = BYTE2(yaSSL::Security::use_parms(this: v11)->free_embedded_thd);
  v15 = v12;
  LOWORD(a2[4].m_Storage.m_nActualLength) = v12;
  v13 = (char *)yaSSL::SSL::useSecurity((char *)this);
  v14 = yaSSL::Security::use_parms(this: v13);
  memcpy(
    dst: (unsigned __int8 *)&a2[4].m_Storage.m_nActualLength + 2,
    src: (unsigned __int8 *)&v14->free_embedded_thd + 3,
    count: v15);
  v16 = (const CUtlMemory<KeyValues *,int>::Iterator_t *)(BYTE2(a2[2].m_Storage.m_Memory.m_nGrowSize)
                                                        + LOWORD(a2[4].m_Storage.m_nActualLength)
                                                        + 39);
  BYTE2(a2[12].m_Storage.m_nActualLength) = 1;
  yaSSL::Crypto::setCipher(this: a2, i: v16, a3: v17);
}

//------------------------------------------------------------------------------
// Address: 0x0042C140
// Name: void yaSSL::hashHandShake(class yaSSL::SSL __near &,class yaSSL::input_buffer const __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL::hashHandShake(
        CThreadSyncObject *this,
        CUtlMemory<KeyValues *,int> *a2,
        const struct yaSSL::input_buffer *sz)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  CThreadSyncObject *Hashes; // eax
  int v7; // eax
  CThreadSyncObject *v8; // eax
  int *v9; // eax

  v3 = yaSSL::EncryptedPreMasterSecret::get_length(this: a2) - 4;
  yaSSL::SSL_CTX::getCert(this: a2);
  v5 = v3 + v4;
  Hashes = yaSSL::SSL::getHashes(this);
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)Hashes);
  (*(void (__thiscall **)(int, int, char *))(*(_DWORD *)v7 + 8))(a1: v7, a2: v5, a3: (char *)sz + 4);
  v8 = yaSSL::SSL::getHashes(this);
  v9 = yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)v8);
  return (*(int (__thiscall **)(int *, int, char *))(*v9 + 8))(a1: v9, a2: v5, a3: (char *)sz + 4);
}

//------------------------------------------------------------------------------
// Address: 0x0042C940
// Name: void yaSSL::hmac(class yaSSL::SSL __near &,unsigned char __near *,unsigned char const __near *,unsigned int,enum yaSSL::ContentType,bool)
// Source: json
//------------------------------------------------------------------------------
int __stdcall yaSSL::hmac(
        ShortVector *a1,
        unsigned __int8 *digest,
        const LoggingContext_t *buffer,
        unsigned int sz,
        bool verify,
        KeyValues **a6)
{
  yaSSL::SSL_CTX *v6; // eax
  int Method; // esi
  unsigned int v8; // edi
  unsigned int v9; // ebp
  const LoggingContext_t *v10; // eax
  void *v11; // ecx
  yaSSL *SEQIncrement; // eax
  int v13; // ecx
  unsigned int v14; // ebx
  int v16; // [esp+0h] [ebp-E8h]
  unsigned __int8 v17[4]; // [esp+10h] [ebp-D8h] BYREF
  const LoggingContext_t *mac_secret; // [esp+14h] [ebp-D4h]
  unsigned __int8 *v19; // [esp+18h] [ebp-D0h]
  const LoggingContext_t *v20; // [esp+1Ch] [ebp-CCh]
  IStorage **seq; // [esp+20h] [ebp-C8h]
  unsigned __int8 c[4]; // [esp+24h] [ebp-C4h] BYREF
  unsigned __int8 src[20]; // [esp+28h] [ebp-C0h] BYREF
  unsigned __int8 dst[4]; // [esp+3Ch] [ebp-ACh] BYREF
  _DWORD v25[19]; // [esp+40h] [ebp-A8h]
  unsigned __int8 v26[88]; // [esp+8Ch] [ebp-5Ch] BYREF

  v20 = buffer;
  v19 = digest;
  yaSSL::sslHashes::get_MD5(this: a1);
  Method = yaSSL::SSL_CTX::getMethod(this: v6);
  v8 = (*(int (__thiscall **)(int))(*(_DWORD *)Method + 12))(a1: Method);
  v9 = (*(int (__thiscall **)(int))(*(_DWORD *)Method + 16))(a1: Method);
  yaSSL::SSL::get_macSecret(this: (CUtlMemory<KeyValues *,int> *)a1, verify: a6, a3: v16);
  mac_secret = v10;
  seq = nullptr;
  *(_DWORD *)c = 0;
  yaSSL::c16toa(u16: v11, u16a: sz, c: v17);
  SEQIncrement = (yaSSL *)yaSSL::SSL::get_SEQIncrement(this: a1, a2: (bool)a6);
  yaSSL::c32toa(this: SEQIncrement, c);
  memcpy(dst, src: (unsigned __int8 *)mac_secret, count: v8);
  memcpy(dst: &dst[v8], src: PAD1, count: v9);
  v13 = *(_DWORD *)c;
  v14 = v8 + v9;
  *(_DWORD *)&dst[v14] = seq;
  *(_WORD *)((char *)&v25[1] + v14 + 1) = *(_WORD *)v17;
  *(_DWORD *)((char *)v25 + v14) = v13;
  *((_BYTE *)&v25[1] + v14) = verify;
  (*(void (__thiscall **)(int, unsigned __int8 *, unsigned int))(*(_DWORD *)Method + 8))(
    a1: Method,
    a2: dst,
    a3: v8 + v9 + 11);
  (**(void (__thiscall ***)(int, unsigned __int8 *, const LoggingContext_t *, unsigned int))Method)(
    a1: Method,
    a2: src,
    a3: v20,
    a4: sz);
  memcpy(dst: v26, src: (unsigned __int8 *)mac_secret, count: v8);
  memcpy(dst: &v26[v8], src: (unsigned __int8 *)PAD2, count: v9);
  memcpy(dst: &v26[v8 + v9], src, count: v8);
  return (**(int (__thiscall ***)(int, unsigned __int8 *, unsigned __int8 *, int))Method)(
           a1: Method,
           a2: v19,
           a3: v26,
           a4: v9 + 2 * v8);
}

//------------------------------------------------------------------------------
// Address: 0x0042CAE0
// Name: void yaSSL::build_certHashes(class yaSSL::SSL __near &,struct yaSSL::Hashes __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::build_certHashes(CThreadSyncObject *result, struct SSL *a2)
{
  CThreadSyncObject *Hashes; // eax
  const struct yaSSL::MD5 *v3; // eax
  CThreadSyncObject *v4; // eax
  int *v5; // eax
  CThreadSyncObject *v6; // eax
  int v7; // eax
  CThreadSyncObject *v8; // eax
  int *v9; // eax
  CThreadSyncObject *v10; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v11; // eax
  CThreadSyncObject *v12; // eax
  int *v13; // eax
  unsigned __int8 *v14; // [esp-8h] [ebp-20h]
  unsigned __int8 *v15; // [esp+0h] [ebp-18h]
  yaSSL::SHA sha[2]; // [esp+8h] [ebp-10h] BYREF
  __int16 v17[4]; // [esp+10h] [ebp-8h] BYREF

  Hashes = yaSSL::SSL::getHashes(this: result);
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)Hashes);
  yaSSL::MD5::MD5(this: (yaSSL::MD5 *)v17, a2: v3);
  v4 = yaSSL::SSL::getHashes(this: result);
  v5 = yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)v4);
  yaSSL::SHA::SHA(this: sha, a2: (const struct TaoCrypt::SHA **)v5);
  if ( yaSSL::SSL::isTLS(this: (ShortVector *)result) != 0 )
  {
    v6 = yaSSL::SSL::getHashes(this: result);
    yaSSL::sslHashes::get_MD5(this: (ShortVector *)v6);
    (*(void (__thiscall **)(int, struct SSL *))(*(_DWORD *)v7 + 4))(a1: v7, a2);
    v8 = yaSSL::SSL::getHashes(this: result);
    v9 = yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)v8);
    (*(void (__thiscall **)(int *, int))(*v9 + 4))(a1: v9, a2: (int)a2 + 16);
  }
  else
  {
    yaSSL::`anonymous namespace'::buildMD5_CertVerify(this: (yaSSL::_anonymous_namespace_ *)result, a2, a3: v15);
    yaSSL::`anonymous namespace'::buildSHA_CertVerify(
      this: (yaSSL::_anonymous_namespace_ *)result,
      a2: (struct SSL *)((char *)a2 + 16),
      a3: v14);
  }
  v10 = yaSSL::SSL::getHashes(this: result);
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)v10);
  yaSSL::MD5::operator=(this: v11, that: (int (__cdecl *)(KeyValues *const *, KeyValues *const *))v17);
  v12 = yaSSL::SSL::getHashes(this: result);
  v13 = yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)v12);
  yaSSL::SHA::operator=(this: (Vector2D *)v13, a2: (int)sha);
  yaSSL::SHA::~SHA(this: (Vector2D *)sha);
  yaSSL::MD5::~MD5(this: (yaSSL::MD5 *)v17);
}

//------------------------------------------------------------------------------
// Address: 0x0042CBD0
// Name: void yaSSL::sendClientHello(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::sendClientHello(yaSSL *this)
{
  ShortVector *v1; // eax
  int v2; // eax
  ShortVector *v3; // eax
  int v4; // eax
  char *random; // eax
  const LoggingContext_t *v6; // eax
  char v7; // [esp-4h] [ebp-100h]
  unsigned int Method; // [esp-4h] [ebp-100h]
  QueuedPacket_t *const *v9; // [esp+0h] [ebp-FCh]
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > v10; // [esp+4h] [ebp-F8h] BYREF
  void **v11; // [esp+18h] [ebp-E4h] BYREF
  yaSSL::ClientHello v12[53]; // [esp+24h] [ebp-D8h] BYREF

  yaSSL::SSL::verifyState((char *)this, a2: nullptr);
  if ( yaSSL::SSL::GetError((char *)this) == 0 )
  {
    v1 = (ShortVector *)yaSSL::SSL::useSecurity((char *)this);
    yaSSL::sslHashes::get_MD5(this: v1);
    v7 = *(_BYTE *)(v2 + 301);
    v3 = (ShortVector *)yaSSL::SSL::useSecurity((char *)this);
    yaSSL::sslHashes::get_MD5(this: v3);
    yaSSL::ClientHello::ClientHello(this: (char *)v12, pv: *(_WORD *)(v4 + 302), useCompression: v7);
    yaSSL::ProtocolVersion::ProtocolVersion(this: (yaSSL::ProtocolVersion *)&v10.m_pElements, maj: 3u, min: 0);
    v11 = &yaSSL::HandShakeHeader::`vftable';
    yaSSL::output_buffer::output_buffer(this: &v10);
    yaSSL::buildClientHello(this, a2: (CUtlString *)v12);
    random = yaSSL::ClientHello::get_random(this: v12);
    yaSSL::SSL::set_random((ShortVector *)this, a2: random, a3: 1);
    yaSSL::`anonymous namespace'::buildHeaders(
      this,
      a2: (struct SSL *)&v11,
      a3: (struct yaSSL::HandShakeHeader *)&v10.m_Size,
      a4: (struct yaSSL::RecordLayerHeader *)v12);
    yaSSL::`anonymous namespace'::buildOutput(result: (std::bad_exception *)&v10);
    yaSSL::`anonymous namespace'::hashHandShake(result: (const CUtlMemory<unsigned int,int> *)this);
    Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v10);
    yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)&v10);
    yaSSL::SSL::Send(this, buffer: v6, sz: Method);
    yaSSL::x509::~x509(this: &v10, a2: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042CCF0
// Name: void yaSSL::ProcessOldClientHello(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __cdecl yaSSL::ProcessOldClientHello(CUtlString *result, CThreadSyncObject *a2)
{
  unsigned int v2; // eax
  char m_pMemory; // bl
  unsigned int v4; // ebx
  unsigned int v5; // eax
  int length; // edi
  int v7; // eax
  int v8; // edi
  CThreadSyncObject *Hashes; // eax
  int v10; // eax
  CThreadSyncObject *v11; // eax
  int *v12; // eax
  const IntVector4D *v13; // ecx
  unsigned __int16 v14; // bx
  int v15; // edi
  unsigned __int16 dst; // [esp+10h] [ebp-E8h] BYREF
  unsigned __int16 randomLen; // [esp+14h] [ebp-E4h] BYREF
  unsigned __int16 sessionLen; // [esp+18h] [ebp-E0h] BYREF
  int i; // [esp+1Ch] [ebp-DCh] OVERLAPPED
  yaSSL::ClientHello v20; // [esp+20h] [ebp-D8h] BYREF
  char v21; // [esp+28h] [ebp-D0h]
  char v22; // [esp+29h] [ebp-CFh]
  unsigned __int8 v23[32]; // [esp+2Ah] [ebp-CEh] BYREF
  unsigned __int8 v24; // [esp+4Ah] [ebp-AEh] BYREF
  char v25[33]; // [esp+4Bh] [ebp-ADh] BYREF
  IntVector4D c; // [esp+6Ch] [ebp-8Ch] BYREF

  yaSSL::input_buffer::get_remaining(this: result);
  if ( v2 >= 2 )
  {
    m_pMemory = (char)yaSSL::input_buffer::operator[](this: result, result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
    v4 = (unsigned __int16)LOBYTE(yaSSL::input_buffer::operator[](this: result, result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory)
       | ((m_pMemory & 0x7F) << 8);
    yaSSL::input_buffer::get_remaining(this: result);
    if ( v4 <= v5 )
    {
      length = yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)result);
      yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)result);
      v8 = v7 + length;
      Hashes = yaSSL::SSL::getHashes(this: a2);
      yaSSL::sslHashes::get_MD5(this: (ShortVector *)Hashes);
      (*(void (__thiscall **)(int, int, unsigned int))(*(_DWORD *)v10 + 8))(a1: v10, a2: v8, a3: v4);
      v11 = yaSSL::SSL::getHashes(this: a2);
      v12 = yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)v11);
      (*(void (__thiscall **)(int *, int, unsigned int))(*v12 + 8))(a1: v12, a2: v8, a3: v4);
      yaSSL::input_buffer::operator[](this: result, result: (CUtlString *)0xFEEDBEEF);
      yaSSL::ClientHello::ClientHello(this: &v20);
      v21 = (char)yaSSL::input_buffer::operator[](this: result, result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
      v22 = (char)yaSSL::input_buffer::operator[](this: result, result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
      yaSSL::input_buffer::read(this: result, (char *)&dst, length: 2u);
      yaSSL::ato16(&c, ca: &dst, a3: &c);
      yaSSL::input_buffer::read(this: result, (char *)&dst, length: 2u);
      yaSSL::ato16(c: (const IntVector4D *)&sessionLen, ca: &dst, a3: &sessionLen);
      v24 = sessionLen;
      yaSSL::input_buffer::read(this: result, (char *)&dst, length: 2u);
      yaSSL::ato16(c: v13, ca: &dst, a3: &randomLen);
      if ( LOWORD(c.x) > 0x80u || sessionLen > 0x20u || (v14 = randomLen, randomLen > 0x20u) )
      {
        yaSSL::SSL::SetError(this: a2, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6D);
      }
      else
      {
        v15 = 0;
        i = 0;
        if ( LOWORD(c.x) != 0 )
        {
          do
          {
            if ( LOBYTE(yaSSL::input_buffer::operator[](this: result, result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory) != 0 )
            {
              yaSSL::input_buffer::read(this: result, (char *)&dst, length: 2u);
            }
            else
            {
              yaSSL::input_buffer::read(this: result, dst: (char *)&c.x + v15 + 2, length: 2u);
              v15 += 2;
            }
            i += 3;
          }
          while ( (unsigned __int16)i < LOWORD(c.x) );
          v14 = randomLen;
        }
        LOWORD(c.x) = v15;
        if ( v24 != 0 )
        {
          yaSSL::input_buffer::read(this: result, dst: v25, length: v24);
          v14 = randomLen;
        }
        if ( v14 < 0x20u )
          memset(dst: v23, value: 0, count: 32 - v14);
        yaSSL::input_buffer::read(this: result, dst: &v25[-v14 - 1], length: v14);
        yaSSL::ClientHello::Process(
          this: &v20,
          (const st_mysql_methods *)a2,
          a3: (struct yaSSL::input_buffer *)result,
          a4: (struct SSL *)a2);
      }
    }
    else
    {
      yaSSL::SSL::SetError(this: a2, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6D);
    }
  }
  else
  {
    yaSSL::SSL::SetError(this: a2, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6D);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D140
// Name: void yaSSL::TLS_hmac(class yaSSL::SSL __near &,unsigned char __near *,unsigned char const __near *,unsigned int,enum yaSSL::ContentType,bool)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __stdcall yaSSL::TLS_hmac(
        CUtlMemory<KeyValues *,int> *a1,
        unsigned __int8 *digest,
        const LoggingContext_t *buffer,
        unsigned int sz,
        bool verify,
        KeyValues **a6)
{
  int v6; // esi
  yaSSL *SEQIncrement; // eax
  char *v8; // eax
  void (__cdecl *fetch_lengths)(unsigned int *, char **, unsigned int); // eax
  const CSplitScreenAddedConVar *v10; // ecx
  unsigned __int8 *v11; // eax
  void *v12; // eax
  KeyValues *v13; // ecx
  CUtlVector<int,CUtlMemory<int,int> > *v14; // eax
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v15; // eax
  int v16; // ebp
  ShortVector *v17; // eax
  int v18; // eax
  ShortVector *v19; // eax
  int v20; // eax
  KeyValues *v21; // ecx
  unsigned int v22; // [esp-4h] [ebp-38h]
  unsigned int v23; // [esp-4h] [ebp-38h]
  unsigned int v24; // [esp-4h] [ebp-38h]
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v25; // [esp+10h] [ebp-24h]
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v26; // [esp+10h] [ebp-24h]
  CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *v27; // [esp+10h] [ebp-24h]
  int v28; // [esp+14h] [ebp-20h] BYREF
  const LoggingContext_t *v29; // [esp+18h] [ebp-1Ch]
  unsigned __int8 *v30; // [esp+1Ch] [ebp-18h]
  _BYTE inner[8]; // [esp+20h] [ebp-14h] OVERLAPPED BYREF
  IStorage **seq; // [esp+28h] [ebp-Ch] BYREF
  unsigned __int8 c[4]; // [esp+2Ch] [ebp-8h] BYREF

  v30 = digest;
  v29 = buffer;
  v6 = 0;
  seq = nullptr;
  *(_DWORD *)c = 0;
  yaSSL::c16toa(u16: (void *)buffer, u16a: sz, c: (unsigned __int8 *)&v28);
  SEQIncrement = (yaSSL *)yaSSL::SSL::get_SEQIncrement(this: (ShortVector *)a1, a2: (bool)a6);
  yaSSL::c32toa(this: SEQIncrement, c);
  v8 = (char *)yaSSL::SSL::useSecurity(this: (char *)a1);
  fetch_lengths = yaSSL::Security::use_parms(this: v8)->fetch_lengths;
  if ( fetch_lengths == (void (__cdecl *)(unsigned int *, char **, unsigned int))2 )
  {
    v25 = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)operator new(sz: v10, sza: 8u);
    if ( v25 == nullptr )
      goto LABEL_11;
    yaSSL::SSL::get_macSecret(this: a1, verify: a6, a3: 20);
    v12 = yaSSL::HMAC_SHA::HMAC_SHA(this: v25, secret: v11, len: v22);
  }
  else if ( fetch_lengths == (void (__cdecl *)(unsigned int *, char **, unsigned int))3 )
  {
    v26 = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)operator new(sz: v10, sza: 8u);
    if ( v26 == nullptr )
      goto LABEL_11;
    yaSSL::SSL::get_macSecret(this: a1, verify: a6, a3: 20);
    v12 = (void *)yaSSL::HMAC_RMD::HMAC_RMD(
                    this: (const CUtlVector<int,CUtlMemory<int,int> > *)v26,
                    secret: v14,
                    len: v23);
  }
  else
  {
    v27 = (CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *)operator new(sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys, sza: 8u);
    if ( v27 == nullptr )
      goto LABEL_11;
    yaSSL::SSL::get_macSecret(this: a1, verify: a6, a3: 16);
    yaSSL::HMAC_MD5::HMAC_MD5(this: v27, secret: v15, len: v24);
  }
  v16 = (int)v12;
  if ( v12 != nullptr )
  {
    yaSSL::ysDelete<yaSSL::Digest>(ptr: v13, a2: 0);
    v6 = v16;
  }
LABEL_11:
  (*(void (__thiscall **)(int, IStorage ***, int))(*(_DWORD *)v6 + 8))(a1: v6, a2: &seq, a3: 8);
  inner[0] = verify;
  v17 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)a1);
  yaSSL::sslHashes::get_MD5(this: v17);
  inner[1] = *(_BYTE *)(v18 + 302);
  v19 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)a1);
  yaSSL::sslHashes::get_MD5(this: v19);
  inner[2] = *(_BYTE *)(v20 + 303);
  *(_WORD *)&inner[3] = v28;
  (*(void (__thiscall **)(int, _BYTE *, int))(*(_DWORD *)v6 + 8))(a1: v6, a2: inner, a3: 5);
  (**(void (__thiscall ***)(int, unsigned __int8 *, const LoggingContext_t *, unsigned int))v6)(
    a1: v6,
    a2: v30,
    a3: v29,
    a4: sz);
  yaSSL::ysDelete<yaSSL::Digest>(ptr: v21, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0042D300
// Name: void yaSSL::PRF(unsigned char __near *,unsigned int,unsigned char const __near *,unsigned int,unsigned char const __near *,unsigned int,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::PRF(
        void *digest,
        unsigned __int8 *digLen,
        CSplitScreenAddedConVar *secret,
        unsigned __int8 *secreta,
        unsigned int secLen,
        unsigned __int8 *label,
        unsigned int labLen,
        unsigned __int8 *seed,
        unsigned int seedLen)
{
  const CSplitScreenAddedConVar *v9; // esi
  struct yaSSL::output_buffer *v10; // [esp+0h] [ebp-4Ch]
  QueuedPacket_t *const *v11; // [esp+0h] [ebp-4Ch]
  QueuedPacket_t *const *v12; // [esp+0h] [ebp-4Ch]
  QueuedPacket_t *const *v13; // [esp+0h] [ebp-4Ch]
  QueuedPacket_t *const *v14; // [esp+0h] [ebp-4Ch]
  QueuedPacket_t *const *v15; // [esp+0h] [ebp-4Ch]
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > v16; // [esp+10h] [ebp-3Ch] BYREF
  QueuedPacket_t *v17[3]; // [esp+28h] [ebp-24h] BYREF
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > v18; // [esp+34h] [ebp-18h] BYREF

  v9 = (const CSplitScreenAddedConVar *)((secLen + 1) >> 1);
  yaSSL::output_buffer::output_buffer(this: (const CSplitScreenAddedConVar *)&v18.m_Size, a2: v9);
  yaSSL::output_buffer::output_buffer(this: (const CSplitScreenAddedConVar *)&v18, a2: v9);
  yaSSL::output_buffer::output_buffer(
    this: (const CSplitScreenAddedConVar *)&v16,
    a2: (const CSplitScreenAddedConVar *)(labLen + seedLen));
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)&v18.m_Size, src: secreta, count: (unsigned int)v9);
  yaSSL::output_buffer::write(
    this: (yaSSL::output_buffer *)&v18,
    src: (unsigned __int8 *)v9 + (_DWORD)secreta - (secLen & 1),
    count: (unsigned int)v9);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)&v16, src: label, count: labLen);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)&v16, src: seed, count: seedLen);
  yaSSL::output_buffer::output_buffer(this: (const CSplitScreenAddedConVar *)v17, a2: secret);
  yaSSL::output_buffer::output_buffer(this: (const CSplitScreenAddedConVar *)&v16.m_Size, a2: secret);
  yaSSL::`anonymous namespace'::p_hash(a1: v17, a2: &v18.m_Size, a3: &v16, a4: 1);
  yaSSL::`anonymous namespace'::p_hash(a1: &v16.m_Size, a2: &v18, a3: &v16, a4: 2);
  yaSSL::output_buffer::set_current(
    this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v17,
    c: nullptr);
  yaSSL::output_buffer::set_current(
    this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v16.m_Size,
    c: nullptr);
  yaSSL::`anonymous namespace'::get_xor(
    this: (yaSSL::_anonymous_namespace_ *)digLen,
    digLen: (unsigned __int8 *)secret,
    a3: v17,
    a4: (QueuedPacket_t **)&v16.m_Size,
    a5: v10);
  yaSSL::x509::~x509(this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v16.m_Size, a2: v11);
  yaSSL::x509::~x509(this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v17, a2: v12);
  yaSSL::x509::~x509(this: &v16, a2: v13);
  yaSSL::x509::~x509(this: &v18, a2: v14);
  yaSSL::x509::~x509(this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v18.m_Size, a2: v15);
}

//------------------------------------------------------------------------------
// Address: 0x0042D430
// Name: int yaSSL::DoProcessReply(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0042D780
// Name: void yaSSL::processReply(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::processReply(CThreadSyncObject *this)
{
  const std::bad_exception *v1; // ecx
  int v2; // eax
  yaSSL::Socket *v3; // eax
  const std::bad_exception *v4; // ecx
  int v5; // eax

  if ( yaSSL::SSL::GetError((char *)this) == 0 )
  {
    yaSSL::DoProcessReply(ssl: v1);
    if ( v2 != 0 )
    {
      yaSSL::SSL::useSocket(this);
      if ( yaSSL::Socket::IsNonBlocking(this: v3) )
      {
        yaSSL::SSL::SetError(this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x50);
      }
      else if ( yaSSL::SSL::GetError((char *)this) == 0 )
      {
        do
          yaSSL::DoProcessReply(ssl: v4);
        while ( v5 != 0 && yaSSL::SSL::GetError((char *)this) == 0 );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042D7F0
// Name: int yaSSL::receiveData(class yaSSL::SSL __near &,class yaSSL::Data __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::receiveData(
        void *ssl,
        CThreadSyncObject *a2,
        int (__cdecl *data)(st_mysql_stmt *, unsigned __int8 **),
        bool peek)
{
  CThreadSyncObject *v4; // eax
  yaSSL::Socket *v5; // eax
  int v6; // [esp-Ch] [ebp-10h]

  if ( yaSSL::SSL::GetError(this: (char *)a2) == 80 )
    yaSSL::SSL::SetError(this: a2, ye: nullptr);
  yaSSL::SSL::verfiyHandShakeComplete(this: (char *)a2);
  if ( yaSSL::SSL::GetError(this: (char *)a2) == 0 )
  {
    if ( yaSSL::SSL::HasData(this: a2) == 0 )
      yaSSL::processReply(this: a2);
    if ( peek )
      yaSSL::SSL::PeekData(a1: (int)a2, (int *)a2, elements: (CUtlCharConversion *)data);
    else
      yaSSL::SSL::fillData(a1: (int)a2, a2: (int *)data, dataSz: (CUtlCharConversion *)data);
    v6 = (*(unsigned __int16 (__thiscall **)(int (__cdecl *)(st_mysql_stmt *, unsigned __int8 **)))(*(_DWORD *)data + 16))(a1: data);
    v4 = yaSSL::SSL::useLog(this: (char *)a2);
    yaSSL::Log::ShowTCP(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)v4, __formal: v6, a3: 0);
    if ( yaSSL::SSL::GetError(this: (char *)a2) == 0 )
    {
      if ( (*(unsigned __int16 (__thiscall **)(int (__cdecl *)(st_mysql_stmt *, unsigned __int8 **)))(*(_DWORD *)data + 16))(a1: data) != 0
        || (yaSSL::SSL::useSocket(this: a2), !yaSSL::Socket::WouldBlock(this: v5)) )
      {
        (*(void (__thiscall **)(int (__cdecl *)(st_mysql_stmt *, unsigned __int8 **)))(*(_DWORD *)data + 16))(a1: data);
      }
      else
      {
        yaSSL::SSL::SetError(this: a2, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x50);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042DF90
// Name: void yaSSL::buildFinished(class yaSSL::SSL __near &,class yaSSL::Finished __near &,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::buildFinished(CThreadSyncObject *result)
{
  CThreadSyncObject *Hashes; // eax
  const struct yaSSL::MD5 *v2; // eax
  CThreadSyncObject *v3; // eax
  int *v4; // eax
  CThreadSyncObject *v5; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v6; // eax
  CThreadSyncObject *v7; // eax
  int *v8; // eax
  yaSSL::SHA sha[2]; // [esp+4h] [ebp-10h] BYREF
  __int16 v10[4]; // [esp+Ch] [ebp-8h] BYREF

  Hashes = yaSSL::SSL::getHashes(this: result);
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)Hashes);
  yaSSL::MD5::MD5(this: (yaSSL::MD5 *)v10, a2: v2);
  v3 = yaSSL::SSL::getHashes(this: result);
  v4 = yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)v3);
  yaSSL::SHA::SHA(this: sha, a2: (const struct TaoCrypt::SHA **)v4);
  if ( yaSSL::SSL::isTLS(this: (ShortVector *)result) != 0 )
  {
    yaSSL::`anonymous namespace'::buildFinishedTLS((hostent *)result);
  }
  else
  {
    yaSSL::`anonymous namespace'::buildMD5((hostent *)result);
    yaSSL::`anonymous namespace'::buildSHA((hostent *)result);
  }
  v5 = yaSSL::SSL::getHashes(this: result);
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)v5);
  yaSSL::MD5::operator=(this: v6, that: (int (__cdecl *)(KeyValues *const *, KeyValues *const *))v10);
  v7 = yaSSL::SSL::getHashes(this: result);
  v8 = yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)v7);
  yaSSL::SHA::operator=(this: (Vector2D *)v8, a2: (int)sha);
  yaSSL::SHA::~SHA(this: (Vector2D *)sha);
  yaSSL::MD5::~MD5(this: (yaSSL::MD5 *)v10);
}

//------------------------------------------------------------------------------
// Address: 0x0042E060
// Name: void yaSSL::sendClientKeyExchange(class yaSSL::SSL __near &,enum yaSSL::BufferOutput)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::sendClientKeyExchange(void (__cdecl *ssl)(IConVar *, const char *, float), char *result, int a3)
{
  const CSplitScreenAddedConVar *v3; // ecx
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v4; // eax
  std::bad_exception *v5; // eax
  std::bad_exception *v6; // esi
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v7; // ebx
  KeyValues *v8; // ecx
  const LoggingContext_t *v9; // eax
  unsigned int Method; // [esp-Ch] [ebp-34h]
  __int16 ck[4]; // [esp+4h] [ebp-24h] BYREF
  _BYTE v12[4]; // [esp+10h] [ebp-18h] BYREF
  yaSSL::ProtocolVersion v13; // [esp+14h] [ebp-14h] BYREF
  tagELEMDESC *hsHeader; // [esp+18h] [ebp-10h] BYREF

  yaSSL::SSL::verifyState(this: result, a2: (st_mysql *)4);
  if ( yaSSL::SSL::GetError(this: result) == 0 )
  {
    yaSSL::ClientKeyExchange::ClientKeyExchange(this: (yaSSL::ClientKeyExchange *)ck, a2: (struct SSL *)result);
    yaSSL::ClientKeyExchange::build(this: (yaSSL::ClientKeyExchange *)ck, a2: (struct SSL *)result);
    yaSSL::SSL::makeMasterSecret(this: (int)result);
    yaSSL::ProtocolVersion::ProtocolVersion(this: &v13, maj: 3u, min: 0);
    hsHeader = (tagELEMDESC *)&yaSSL::HandShakeHeader::`vftable';
    v4 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)operator new(sz: v3, sza: 0xCu);
    if ( v4 != nullptr )
    {
      yaSSL::output_buffer::output_buffer(this: v4);
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    v7 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v6;
    yaSSL::`anonymous namespace'::buildHeaders(
      this: (yaSSL::_anonymous_namespace_ *)result,
      a2: (struct SSL *)&hsHeader,
      a3: (struct yaSSL::HandShakeHeader *)v12,
      a4: (struct yaSSL::RecordLayerHeader *)ck);
    yaSSL::`anonymous namespace'::buildOutput(result: v6);
    yaSSL::`anonymous namespace'::hashHandShake((const CUtlMemory<unsigned int,int> *)result);
    if ( a3 != 0 )
    {
      Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v6);
      yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)v6);
      yaSSL::SSL::Send(this: (yaSSL::SSL *)result, buffer: v9, sz: Method);
    }
    else
    {
      v7 = nullptr;
      yaSSL::SSL::addBuffer(this: (yaSSL::SSL *)result, result: (sockaddr *)v6);
    }
    yaSSL::ysDelete<yaSSL::x509>(ptr: v8, ptra: v7);
    hsHeader = (tagELEMDESC *)&yaSSL::Message::`vftable';
    yaSSL::ClientKeyExchange::~ClientKeyExchange(this: (CUtlVectorAutoPurge<char *> *)ck);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E170
// Name: void yaSSL::sendChangeCipher(class yaSSL::SSL __near &,enum yaSSL::BufferOutput)
// Source: json
//------------------------------------------------------------------------------
void __usercall yaSSL::sendChangeCipher(const struct Message *a1@<esi>, char *a2, int a3)
{
  char *v4; // eax
  CThreadSyncObject *v5; // eax
  const CSplitScreenAddedConVar *v6; // ecx
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v7; // eax
  yaSSL::SSL_CTX *v8; // eax
  yaSSL::SSL_CTX *v9; // esi
  KeyValues *v10; // ecx
  const LoggingContext_t *v11; // eax
  KeyValues *v12; // ecx
  unsigned int Method; // [esp-Ch] [ebp-20h]
  __int128 v14; // [esp+4h] [ebp-10h] BYREF

  v4 = (char *)yaSSL::SSL::useSecurity(this: a2);
  if ( yaSSL::Security::use_parms(this: v4)->read_query_result == nullptr )
  {
    v5 = (CThreadSyncObject *)yaSSL::SSL::useSecurity(this: a2);
    if ( yaSSL::Security::get_resuming(this: v5) != 0 )
      yaSSL::SSL::verifyState(this: a2, result: (matrix3x4a_t *)2);
    else
      yaSSL::SSL::verifyState(this: a2, result: (matrix3x4a_t *)3);
  }
  if ( yaSSL::SSL::GetError(this: a2) == 0 )
  {
    yaSSL::ChangeCipherSpec::ChangeCipherSpec(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)&v14);
    yaSSL::ProtocolVersion::ProtocolVersion(this: (yaSSL::ProtocolVersion *)&v14 + 3, maj: 3u, min: 0);
    yaSSL::`anonymous namespace'::buildHeader(
      this: (yaSSL::_anonymous_namespace_ *)a2,
      a2: (struct SSL *)((char *)&v14 + 8),
      a3: (struct yaSSL::RecordLayerHeader *)&v14,
      a4: a1);
    v7 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)operator new(sz: v6, sza: 0xCu);
    if ( v7 != nullptr )
    {
      yaSSL::output_buffer::output_buffer(this: v7);
      v9 = v8;
    }
    else
    {
      v9 = nullptr;
    }
    yaSSL::`anonymous namespace'::buildOutput(buffer: (const CUtlMemory<unsigned int,int>::Iterator_t *)((char *)&v14 + 8));
    if ( a3 != 0 )
    {
      Method = yaSSL::SSL_CTX::getMethod(this: v9);
      yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)v9);
      yaSSL::SSL::Send(this: (yaSSL::SSL *)a2, buffer: v11, sz: Method);
      yaSSL::ysDelete<yaSSL::x509>(ptr: v12, ptra: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v9);
    }
    else
    {
      yaSSL::SSL::addBuffer(this: (yaSSL::SSL *)a2, result: (sockaddr *)v9);
      yaSSL::ysDelete<yaSSL::x509>(ptr: v10, ptra: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E270
// Name: void yaSSL::sendFinished(class yaSSL::SSL __near &,enum yaSSL::ConnectionEnd,enum yaSSL::BufferOutput)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::sendFinished(char *result, modsv_t *side, int a3)
{
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v3; // eax
  CUtlMemory<KeyValues *,int> *v4; // eax
  CUtlMemory<KeyValues *,int> *v5; // edi
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v6; // ebx
  CThreadSyncObject *v7; // eax
  yaSSL::Security *v8; // eax
  QuaternionAligned *Context; // eax
  const CSplitScreenAddedConVar *v10; // ecx
  ICommandLine *Sessions; // eax
  CThreadSyncObject *Hashes; // eax
  ShortVector *v13; // eax
  yaSSL::Connection *v14; // eax
  KeyValues *v15; // ecx
  const LoggingContext_t *v16; // eax
  unsigned int Method; // [esp-10h] [ebp-44h]
  _BYTE ssl[44]; // [esp+4h] [ebp-30h] BYREF

  if ( yaSSL::SSL::GetError(this: result) != 0 )
    return;
  yaSSL::Finished::Finished(this: (yaSSL::Finished *)ssl);
  yaSSL::buildFinished((CThreadSyncObject *)result);
  v3 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)operator new(
                                                                           sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys,
                                                                           sza: 0xCu);
  if ( v3 != nullptr )
  {
    yaSSL::output_buffer::output_buffer(this: v3);
    v5 = v4;
  }
  else
  {
    v5 = nullptr;
  }
  v6 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v5;
  yaSSL::`anonymous namespace'::cipherFinished((std::_Exception_ptr *)result, ssl, fin: v5);
  v7 = (CThreadSyncObject *)yaSSL::SSL::useSecurity(this: result);
  if ( yaSSL::Security::get_resuming(this: v7) == 0 )
  {
    v8 = (yaSSL::Security *)yaSSL::SSL::useSecurity(this: result);
    Context = (QuaternionAligned *)yaSSL::Security::GetContext(this: v8);
    if ( yaSSL::SSL_CTX::GetSessionCacheOff(this: Context) == 0 )
    {
      Sessions = (ICommandLine *)yaSSL::GetSessions(ecx0: v10);
      yaSSL::Sessions::add(this: Sessions, (IMemAlloc *)result);
    }
    if ( side != (modsv_t *)1 )
      goto LABEL_12;
    goto LABEL_11;
  }
  if ( side == nullptr )
  {
LABEL_11:
    Hashes = yaSSL::SSL::getHashes(this: (CThreadSyncObject *)result);
    yaSSL::Crypto::get_certManager(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)Hashes);
    yaSSL::buildFinished((CThreadSyncObject *)result);
  }
LABEL_12:
  v13 = (ShortVector *)yaSSL::SSL::useSecurity(this: result);
  yaSSL::sslHashes::get_MD5(this: v13);
  yaSSL::Connection::CleanMaster(this: v14);
  if ( a3 != 0 )
  {
    Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v5);
    yaSSL::SSL_CTX::getCert(this: v5);
    yaSSL::SSL::Send(this: (yaSSL::SSL *)result, buffer: v16, sz: Method);
  }
  else
  {
    v6 = nullptr;
    yaSSL::SSL::addBuffer(this: (yaSSL::SSL *)result, result: (sockaddr *)v5);
  }
  yaSSL::ysDelete<yaSSL::x509>(ptr: v15, ptra: v6);
}

//------------------------------------------------------------------------------
// Address: 0x0042E3C0
// Name: int yaSSL::sendData(class yaSSL::SSL __near &,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __usercall yaSSL::sendData(const struct Message *a1@<edi>, yaSSL::SSL *a2, int sz, int a4)
{
  int v5; // esi
  int v6; // edi
  const LoggingContext_t *v7; // eax
  int Error; // eax
  CThreadSyncObject *v9; // eax
  unsigned __int16 v10; // [esp-14h] [ebp-44h]
  const LoggingContext_t *length; // [esp-10h] [ebp-40h]
  unsigned int Method; // [esp-10h] [ebp-40h]
  const struct Message *v13; // [esp-Ch] [ebp-3Ch]
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > v14; // [esp+4h] [ebp-2Ch] BYREF
  CUtlString v15; // [esp+20h] [ebp-10h] BYREF

  if ( yaSSL::SSL::GetError(this: (char *)a2) == 80 )
    yaSSL::SSL::SetError(this: a2, ye: nullptr);
  yaSSL::SSL::verfiyHandShakeComplete(this: (char *)a2);
  if ( yaSSL::SSL::GetError(this: (char *)a2) != 0 )
    return;
  v5 = 0;
  v13 = a1;
  while ( 1 )
  {
    v6 = a4 - v5;
    if ( a4 - v5 >= 0x4000 )
      v6 = 0x4000;
    yaSSL::output_buffer::output_buffer(this: &v14);
    CUtlString::CUtlString(this: &v15);
    yaSSL::Data::Data(this: &v14.m_Size);
    if ( yaSSL::SSL::CompressionOn(this: (ShortVector *)a2) != 0 )
      break;
    yaSSL::Data::SetData(this: (int)&v14.m_Size, len: v6, buffer: (const LoggingContext_t *)(v5 + sz));
LABEL_11:
    yaSSL::`anonymous namespace'::buildMessage(
      this: a2,
      a2: (struct SSL *)&v14,
      a3: (struct yaSSL::output_buffer *)&v14.m_Size,
      a4: v13);
    Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v14);
    yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)&v14);
    yaSSL::SSL::Send(this: a2, buffer: v7, sz: Method);
    Error = yaSSL::SSL::GetError(this: (char *)a2);
    v14.m_Size = (int)&yaSSL::Message::`vftable';
    if ( Error != 0 )
      goto LABEL_15;
    v5 += v6;
    yaSSL::input_buffer::~input_buffer(this: &v15);
    yaSSL::x509::~x509(this: &v14, a2: (QueuedPacket_t *const *)v13);
    if ( v5 == a4 )
    {
      v9 = yaSSL::SSL::useLog(this: (char *)a2);
      yaSSL::Log::ShowTCP(this: (CUtlVector<char *,CUtlMemory<char *,int> > *)v9, __formal: v5, a3: 1);
      return;
    }
  }
  if ( yaSSL::Compress() != -1 )
  {
    length = (const LoggingContext_t *)yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v15);
    v10 = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v15);
    yaSSL::Data::SetData(this: (int)&v14.m_Size, len: v10, buffer: length);
    goto LABEL_11;
  }
  yaSSL::SSL::SetError(this: a2, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x76);
  v14.m_Size = (int)&yaSSL::Message::`vftable';
LABEL_15:
  yaSSL::input_buffer::~input_buffer(this: &v15);
  yaSSL::x509::~x509(this: &v14, a2: (QueuedPacket_t *const *)v13);
}

//------------------------------------------------------------------------------
// Address: 0x0042E530
// Name: int yaSSL::sendAlert(class yaSSL::SSL __near &,class yaSSL::Alert const __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL::sendAlert(yaSSL *this, struct SSL *a2)
{
  const LoggingContext_t *v2; // eax
  int v3; // esi
  unsigned int Method; // [esp-4h] [ebp-18h]
  const struct yaSSL::Alert *v6; // [esp+0h] [ebp-14h]
  QueuedPacket_t *const *v7; // [esp+0h] [ebp-14h]
  CUtlMemory<KeyValues *,int> v8; // [esp+8h] [ebp-Ch] BYREF

  yaSSL::output_buffer::output_buffer(this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v8);
  yaSSL::`anonymous namespace'::buildAlert(this, a2: (struct SSL *)&v8, a3: a2, a4: v6);
  Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v8);
  yaSSL::SSL_CTX::getCert(this: &v8);
  yaSSL::SSL::Send(this, buffer: v2, sz: Method);
  v3 = (*(unsigned __int16 (__thiscall **)(struct SSL *))(*(_DWORD *)a2 + 16))(a1: a2);
  yaSSL::x509::~x509(this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v8, a2: v7);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0042E590
// Name: void yaSSL::sendCertificate(class yaSSL::SSL __near &,enum yaSSL::BufferOutput)
// Source: json
//------------------------------------------------------------------------------
void __usercall yaSSL::sendCertificate(sockaddr *a1@<ebx>, const char *a2@<esi>, ShortVector *a3, int a4)
{
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v5; // eax
  KeyValues ***certManager; // eax
  yaSSL::SSL_CTX *v7; // eax
  const CSplitScreenAddedConVar *v8; // ecx
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v9; // eax
  std::bad_exception *v10; // eax
  std::bad_exception *v11; // esi
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v12; // ebx
  KeyValues *v13; // ecx
  const LoggingContext_t *v14; // eax
  unsigned int Method; // [esp-Ch] [ebp-34h]
  _BYTE v16[4]; // [esp+4h] [ebp-24h] BYREF
  yaSSL::ProtocolVersion v17; // [esp+8h] [ebp-20h] BYREF
  _BYTE v18[12]; // [esp+Ch] [ebp-1Ch] BYREF
  tagELEMDESC *hsHeader; // [esp+18h] [ebp-10h] BYREF

  if ( yaSSL::SSL::GetError(this: (char *)a3) == 0 )
  {
    yaSSL::sslHashes::get_MD5(this: a3);
    certManager = yaSSL::Crypto::get_certManager(this: v5);
    LOBYTE(v7) = yaSSL::CertManager::get_cert(this: (Vector *)certManager, a2, a3: a1);
    yaSSL::Certificate::Certificate(this: (CUtlString *)v18, cert: v7);
    yaSSL::ProtocolVersion::ProtocolVersion(this: &v17, maj: 3u, min: 0);
    hsHeader = (tagELEMDESC *)&yaSSL::HandShakeHeader::`vftable';
    v9 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)operator new(sz: v8, sza: 0xCu);
    if ( v9 != nullptr )
    {
      yaSSL::output_buffer::output_buffer(this: v9);
      v11 = v10;
    }
    else
    {
      v11 = nullptr;
    }
    v12 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v11;
    yaSSL::`anonymous namespace'::buildHeaders(
      this: (yaSSL::_anonymous_namespace_ *)a3,
      a2: (struct SSL *)&hsHeader,
      a3: (struct yaSSL::HandShakeHeader *)v16,
      a4: (struct yaSSL::RecordLayerHeader *)v18);
    yaSSL::`anonymous namespace'::buildOutput(result: v11);
    yaSSL::`anonymous namespace'::hashHandShake(result: (const CUtlMemory<unsigned int,int> *)a3);
    if ( a4 != 0 )
    {
      Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v11);
      yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)v11);
      yaSSL::SSL::Send(this: (yaSSL::SSL *)a3, buffer: v14, sz: Method);
    }
    else
    {
      v12 = nullptr;
      yaSSL::SSL::addBuffer(this: (yaSSL::SSL *)a3, result: (sockaddr *)v11);
    }
    yaSSL::ysDelete<yaSSL::x509>(ptr: v13, ptra: v12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E690
// Name: void yaSSL::sendCertificateVerify(class yaSSL::SSL __near &,enum yaSSL::BufferOutput)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::sendCertificateVerify(
        void (__cdecl *ssl)(IConVar *, const char *, float),
        CEmptyConVar *result,
        int a3)
{
  const CSplitScreenAddedConVar *v3; // ecx
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v4; // eax
  std::bad_exception *v5; // eax
  std::bad_exception *v6; // esi
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v7; // ebx
  KeyValues *v8; // ecx
  const LoggingContext_t *v9; // eax
  unsigned int Method; // [esp-Ch] [ebp-58h]
  _BYTE v11[4]; // [esp+4h] [ebp-48h] BYREF
  yaSSL::ProtocolVersion v12; // [esp+8h] [ebp-44h] BYREF
  tagELEMDESC *hsHeader; // [esp+Ch] [ebp-40h] BYREF
  yaSSL::CertificateVerify verify[12]; // [esp+18h] [ebp-34h] BYREF

  if ( yaSSL::SSL::GetError(this: (char *)result) == 0 )
  {
    yaSSL::CertificateVerify::CertificateVerify(this: verify);
    yaSSL::CertificateVerify::Build(this: (unsigned int *)verify, result);
    yaSSL::ProtocolVersion::ProtocolVersion(this: &v12, maj: 3u, min: 0);
    hsHeader = (tagELEMDESC *)&yaSSL::HandShakeHeader::`vftable';
    v4 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)operator new(sz: v3, sza: 0xCu);
    if ( v4 != nullptr )
    {
      yaSSL::output_buffer::output_buffer(this: v4);
      v6 = v5;
    }
    else
    {
      v6 = nullptr;
    }
    v7 = (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v6;
    yaSSL::`anonymous namespace'::buildHeaders(
      this: (yaSSL::_anonymous_namespace_ *)result,
      a2: (struct SSL *)&hsHeader,
      a3: (struct yaSSL::HandShakeHeader *)v11,
      a4: (struct yaSSL::RecordLayerHeader *)verify);
    yaSSL::`anonymous namespace'::buildOutput(result: v6);
    yaSSL::`anonymous namespace'::hashHandShake((const CUtlMemory<unsigned int,int> *)result);
    if ( a3 != 0 )
    {
      Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v6);
      yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)v6);
      yaSSL::SSL::Send(this: (yaSSL::SSL *)result, buffer: v9, sz: Method);
    }
    else
    {
      v7 = nullptr;
      yaSSL::SSL::addBuffer(this: (yaSSL::SSL *)result, result: (sockaddr *)v6);
    }
    yaSSL::ysDelete<yaSSL::x509>(ptr: v8, ptra: v7);
    hsHeader = (tagELEMDESC *)&yaSSL::Message::`vftable';
    yaSSL::CertificateVerify::~CertificateVerify(this: verify);
  }
}
