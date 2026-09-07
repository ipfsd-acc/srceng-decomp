// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/ssl.cpp
// Functions: 50
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\ssl.h"

//------------------------------------------------------------------------------
// Address: 0x00416160
// Name: _yaTLSv1_client_method
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaTLSv1_client_method(const CSplitScreenAddedConVar *this)
{
  CSplitScreenAddedConVar *v1; // esi
  unsigned __int16 *v2; // eax
  char v4; // [esp+6h] [ebp-2h] BYREF

  v1 = operator new(sz: this);
  if ( v1 == nullptr )
    return 0;
  v2 = (unsigned __int16 *)yaSSL::ProtocolVersion::ProtocolVersion(this: (yaSSL::ProtocolVersion *)&v4, maj: 3u, a3: 1u);
  return yaSSL::SSL_METHOD::SSL_METHOD(a1: v1, a2: 1, a3: *v2, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x004161A0
// Name: _yaSSL_CTX_new
// Source: json
//------------------------------------------------------------------------------
SplitScreenSlottedConVarRef *__thiscall yaSSL_CTX_new(const CSplitScreenAddedConVar *this)
{
  if ( operator new(sz: this) != nullptr )
    return (SplitScreenSlottedConVarRef *)yaSSL::SSL_CTX::SSL_CTX();
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004161D0
// Name: _yaSSL_new
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL_new(struct SSL_CTX *serverSide)
{
  const CSplitScreenAddedConVar *v1; // ecx
  CUtlMemory<KeyValues *,int> *v2; // eax

  v2 = (CUtlMemory<KeyValues *,int> *)operator new(sz: v1);
  if ( v2 != nullptr )
    return yaSSL::SSL::SSL(this: v2, serverSide);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00416200
// Name: _yaSSL_set_fd
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL_set_fd(CThreadSyncObject *a1, QueuedPacket_t **c)
{
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *v2; // eax

  yaSSL::SSL::useSocket(this: a1);
  yaSSL::output_buffer::set_current(this: v2, c);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00416220
// Name: _yaSSL_get_fd
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL_get_fd(void *ssl, CThreadSyncObject *a2)
{
  yaSSL::SSL_CTX *v2; // eax

  yaSSL::SSL::useSocket(this: a2);
  yaSSL::SSL_CTX::getMethod(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x00416230
// Name: _yaSSL_connect
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00416480
// Name: _yaSSL_write
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall yaSSL_write(Color ssl)
{
  yaSSL::sendData(ssl);
}

//------------------------------------------------------------------------------
// Address: 0x00416490
// Name: _yaSSL_clear
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004164B0
// Name: _yaSSL_shutdown
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL_shutdown(const char *ssl, yaSSL *ssla)
{
  yaSSL::SSL_CTX *v2; // eax
  CThreadSyncObject *Method; // eax
  CUtlVector<char *,CUtlMemory<char *,int> > *v4; // eax
  ICommandLine *Errors; // eax
  int v6; // [esp-8h] [ebp-18h]
  int v7; // [esp+0h] [ebp-10h]
  struct yaSSL::Alert *v8; // [esp+0h] [ebp-10h]
  const char *v9; // [esp+0h] [ebp-10h]
  CThreadSyncObject *v10[3]; // [esp+4h] [ebp-Ch] BYREF

  if ( (unsigned __int8)yaSSL::SSL::GetQuietShutdown(a1: v7, a2: v10[0], a3: (bool)v10[1], a4: (unsigned int)v10[2]) == 0 )
  {
    yaSSL::Alert::Alert(a1: v10, a2: 1, a3: 0);
    yaSSL::sendAlert(this: ssla, a2: (struct SSL *)v10, a3: v8);
  }
  yaSSL::SSL::useSocket(this: (CThreadSyncObject *)ssla);
  Method = (CThreadSyncObject *)yaSSL::SSL_CTX::getMethod(this: v2);
  v4 = (CUtlVector<char *,CUtlMemory<char *,int> > *)yaSSL::SSL::useLog(result: Method);
  yaSSL::Log::ShowTCP(this: v4, __formal: v6);
  Errors = (ICommandLine *)yaSSL::GetErrors(this: (yaSSL *)v8);
  yaSSL::Errors::Remove(this: Errors, find: v9);
}

//------------------------------------------------------------------------------
// Address: 0x00416520
// Name: _yaSSL_set_quiet_shutdown
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL_set_quiet_shutdown(SplitScreenSlottedConVarRef *result, int a2)
{
  yaSSL::SSL::SetQuietShutdown(this: (yaSSL::SSL *)result, a2: a2 != 0);
}

//------------------------------------------------------------------------------
// Address: 0x00416540
// Name: _yaSSL_get_session
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00416590
// Name: _yaSSL_SESSION_set_timeout
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL_SESSION_set_timeout(bool sess, yaSSL::SSL_SESSION *sessa, unsigned int t)
{
  if ( sessa != nullptr )
    yaSSL::SSL_SESSION::SetTimeOut(this: sessa, a2: t);
}

//------------------------------------------------------------------------------
// Address: 0x004165B0
// Name: _yaSSL_CTX_set_cipher_list
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl yaSSL_CTX_set_cipher_list(tagShutdownType list, QuaternionAligned *result)
{
  return (unsigned __int8)yaSSL::SSL_CTX::SetCipherList(result) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x004165D0
// Name: _yaSSL_get_peer_certificate
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004165F0
// Name: _yaX509_STORE_CTX_get_current_cert
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaX509_STORE_CTX_get_current_cert(int a1)
{
  return *(_DWORD *)(a1 + 8);
}

//------------------------------------------------------------------------------
// Address: 0x00416600
// Name: _yaX509_STORE_CTX_get_error_depth
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaX509_STORE_CTX_get_error_depth(int a1)
{
  return *(_DWORD *)(a1 + 4);
}

//------------------------------------------------------------------------------
// Address: 0x00416610
// Name: _yaX509_NAME_oneline
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall yaX509_NAME_oneline(const char *name, yaSSL::SSL_CTX *buffer, char *buffera, int sz)
{
  unsigned __int8 *result; // eax
  unsigned int v5; // eax
  int v6; // edi
  unsigned int v7; // ebx
  unsigned __int8 *v8; // esi
  unsigned __int8 *Method; // eax

  if ( yaSSL::SSL_CTX::getMethod(this: buffer) == nullptr )
    return (unsigned __int8 *)buffera;
  v5 = strlen((const char *)yaSSL::SSL_CTX::getMethod(this: buffer));
  v6 = sz;
  v7 = v5 + 1;
  if ( (int)(v5 + 1) < sz )
    v6 = v5 + 1;
  v8 = (unsigned __int8 *)buffera;
  if ( buffera == nullptr )
  {
    result = (unsigned __int8 *)operator new(nSize: v5 + 1);
    v8 = result;
    if ( result == nullptr )
      return result;
    v6 = v7;
  }
  if ( v6 != 0 )
  {
    Method = (unsigned __int8 *)yaSSL::SSL_CTX::getMethod(this: buffer);
    memcpy(dst: v8, src: Method, count: v6 - 1);
    v8[v6 - 1] = 0;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00416690
// Name: _yaX509_get_issuer_name
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaX509_get_issuer_name(ShortVector *a1, __int16 a2, __int16 a3, __int16 a4)
{
  yaSSL::sslHashes::get_MD5(this: a1, a2: (__int16)a1, a3: a2, a4: a3, a5: a4);
}

//------------------------------------------------------------------------------
// Address: 0x004166A0
// Name: _yaX509_get_subject_name
// Source: json
//------------------------------------------------------------------------------
struct X509_NAME *__cdecl yaX509_get_subject_name(yaSSL::X509 *a1)
{
  return yaSSL::X509::GetSubject(this: a1);
}

//------------------------------------------------------------------------------
// Address: 0x004166B0
// Name: _yaSSL_CTX_set_tmp_dh
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl yaSSL_CTX_set_tmp_dh(CUtlStringList ctx)
{
  return yaSSL::SSL_CTX::SetDH(
           this: (yaSSL::SSL_CTX *)ctx.m_Memory.m_pMemory,
           a2: (const struct DH *)ctx.m_Memory.m_nAllocationCount);
}

//------------------------------------------------------------------------------
// Address: 0x004166D0
// Name: _yaSSL_CTX_set_verify
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL_CTX_set_verify(
        const char *ctx,
        yaSSL::SSL_CTX *mode,
        int a3,
        int (__cdecl *vc)(int, struct X509_STORE_CTX *))
{
  if ( (a3 & 1) != 0 )
    yaSSL::SSL_CTX::setVerifyPeer(this: mode);
  if ( a3 == 0 )
    yaSSL::SSL_CTX::setVerifyNone(this: mode);
  if ( (a3 & 2) != 0 )
    yaSSL::SSL_CTX::setFailNoCert(this: mode);
  yaSSL::SSL_CTX::setVerifyCallback(this: mode, a2: vc);
}

//------------------------------------------------------------------------------
// Address: 0x00416710
// Name: _yaSSL_CTX_set_default_verify_paths
// Source: json
//------------------------------------------------------------------------------
int yaSSL_CTX_set_default_verify_paths()
{
  return -3;
}

//------------------------------------------------------------------------------
// Address: 0x00416720
// Name: _yaDH_new
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaDH_new(const CSplitScreenAddedConVar *this)
{
  CSplitScreenAddedConVar *v1; // eax

  v1 = operator new(sz: this);
  if ( v1 != nullptr )
  {
    v1->m_pNext = nullptr;
    v1->ConVar::ConCommandBase::__vftable = nullptr;
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00416750
// Name: _yaEVP_BytesToKey
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaEVP_BytesToKey(char *a1, char *first, int a3, int a4, Color plain, int a6, int a7, int a8)
{
  CUtlVectorAutoPurge<char *> *DigestSize; // ebx
  int v9; // esi
  int v10; // edi
  int v11; // esi
  unsigned int m_Size; // esi
  int v13; // edi
  unsigned int v14; // esi
  char *v15; // edx
  int v16; // edi
  CUtlVectorAutoPurge<char *> *v18; // [esp+0h] [ebp-58h]
  int v19; // [esp+0h] [ebp-58h]
  int v20; // [esp+4h] [ebp-54h]
  int v21; // [esp+8h] [ebp-50h]
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > v22; // [esp+Ch] [ebp-4Ch] BYREF
  int v23; // [esp+20h] [ebp-38h]
  int m_nGrowSize; // [esp+24h] [ebp-34h]
  int m_nAllocationCount; // [esp+28h] [ebp-30h]
  int v26; // [esp+2Ch] [ebp-2Ch]
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > out; // [esp+30h] [ebp-28h] BYREF

  out.m_Memory.m_nGrowSize = a3;
  v26 = a4;
  out.m_Memory.m_nAllocationCount = a7;
  out.m_Size = a8;
  if ( strncmp(first, last: "MD5", count: 3u) != 0 )
    return 0;
  if ( strncmp(first: a1, last: "DES-CBC", count: 7u) != 0 )
  {
    if ( strncmp(first: a1, last: "DES-EDE3-CBC", count: 0xCu) == 0 )
    {
      v22.m_Memory.m_nAllocationCount = 24;
      v22.m_Memory.m_nGrowSize = 8;
      goto LABEL_13;
    }
    if ( strncmp(first: a1, last: "AES-128-CBC", count: 0xBu) == 0 )
    {
      v22.m_Memory.m_nAllocationCount = 16;
      v22.m_Memory.m_nGrowSize = 16;
      goto LABEL_13;
    }
    if ( strncmp(first: a1, last: "AES-192-CBC", count: 0xBu) == 0 )
    {
      v22.m_Memory.m_nAllocationCount = 24;
LABEL_12:
      v22.m_Memory.m_nGrowSize = 16;
      goto LABEL_13;
    }
    if ( strncmp(first: a1, last: "AES-256-CBC", count: 0xBu) == 0 )
    {
      v22.m_Memory.m_nAllocationCount = 32;
      goto LABEL_12;
    }
    return 0;
  }
  v22.m_Memory.m_nAllocationCount = 8;
  v22.m_Memory.m_nGrowSize = 8;
LABEL_13:
  yaSSL::MD5::MD5(this: (KeyValues **)&v22.m_pElements);
  DigestSize = TaoCrypt::MD2::getDigestSize(result: v18);
  m_nAllocationCount = v22.m_Memory.m_nAllocationCount;
  v9 = 0;
  m_nGrowSize = v22.m_Memory.m_nGrowSize;
  v22.m_Size = 0;
  out.m_Memory.m_pMemory = (QueuedPacket_t **)(v22.m_Memory.m_nGrowSize + v22.m_Memory.m_nAllocationCount);
  if ( v22.m_Memory.m_nGrowSize + v22.m_Memory.m_nAllocationCount > 0 )
  {
    do
    {
      v10 = (int)DigestSize;
      if ( v9 != 0 )
        TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
          this: (CLoggingSystem *)&v22.m_pElements,
          cipher: (int)&out.m_pElements,
          plain: (Color)DigestSize);
      TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
        this: (CLoggingSystem *)&v22.m_Size,
        cipher: m_nAllocationCount,
        plain);
      if ( out.m_Memory.m_pMemory != nullptr )
        TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
          this: (CLoggingSystem *)&v22.m_Memory.m_nGrowSize,
          cipher: (int)out.m_Memory.m_pMemory,
          plain: (Color)8);
      yaSSL::MD5::get_digest(
        this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v22.m_Memory.m_nAllocationCount,
        out: (const CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&out.m_Memory.m_nAllocationCount);
      if ( a6 > 1 )
      {
        v11 = a6 - 1;
        do
        {
          TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
            this: (CLoggingSystem *)&v22.m_Memory.m_nAllocationCount,
            cipher: (int)&out.m_Memory.m_nAllocationCount,
            plain: (Color)DigestSize);
          yaSSL::MD5::get_digest(this: &v22, &out);
          --v11;
        }
        while ( v11 != 0 );
      }
      m_Size = v22.m_Size;
      if ( v22.m_Size != 0 )
      {
        if ( v22.m_Size >= (int)DigestSize )
          m_Size = (unsigned int)DigestSize;
        v13 = v22.m_Size;
        memcpy(dst: (unsigned __int8 *)(v19 + m_nGrowSize - v22.m_Size), src: (unsigned __int8 *)&out, count: m_Size);
        v21 += m_Size;
        v22.m_Size = v13 - m_Size;
        v10 = (int)DigestSize - m_Size;
      }
      v14 = v22.m_Memory.m_nGrowSize;
      if ( v22.m_Memory.m_nGrowSize != 0 && v10 != 0 )
      {
        if ( v22.m_Memory.m_nGrowSize >= v10 )
          v14 = v10;
        v15 = (char *)DigestSize - v10;
        v16 = v22.m_Memory.m_nGrowSize;
        memcpy(
          dst: (unsigned __int8 *)(v20 + v26 - v22.m_Memory.m_nGrowSize),
          src: (unsigned __int8 *)&out + (_DWORD)v15,
          count: v14);
        v21 += v14;
        v22.m_Memory.m_nGrowSize = v16 - v14;
      }
      v9 = v21;
    }
    while ( v21 < v23 );
  }
  yaSSL::MD5::~MD5(this: (yaSSL::MD5 *)&v22);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x004169C0
// Name: void TaoCrypt::tcArrayDelete<unsigned char>(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall TaoCrypt::tcArrayDelete<unsigned char>(unsigned __int8 *ptr)
{
  operator delete[]((KeyValues *)ptr);
}

//------------------------------------------------------------------------------
// Address: 0x00416A30
// Name: _yaSSL_read
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL_read(
        int (__cdecl *ssl)(void (__cdecl *const *)(IConVar *, const char *, float), void (__cdecl *const *)(IConVar *, const char *, float)),
        void *buffer,
        unsigned __int8 *a3,
        int sz)
{
  unsigned __int16 v4; // ax
  float v5; // ecx
  CUtlCharConversion::ConversionInfo_t data; // [esp+0h] [ebp-10h] BYREF

  v4 = sz;
  if ( sz >= 0x4000 )
    v4 = 0x4000;
  yaSSL::Data::Data(this: &data, a2: v4, a3);
  yaSSL::receiveData(ssl: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00416B40
// Name: public: yaSSL::SSL::~SSL(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::~SSL(int this, st_mysql *result)
{
  int v3; // [esp+0h] [ebp-8h]

  vio_ignore_timeout();
  yaSSL::Buffers::~Buffers(this: (yaSSL::Buffers *)(this + 2496));
  vio_ignore_timeout();
  *(_DWORD *)(this + 2408) = &yaSSL::HandShakeBase::`vftable';
  yaSSL::SHA::~SHA(this: (Vector2D *)(this + 2400));
  yaSSL::MD5::~MD5(this: (yaSSL::MD5 *)(this + 2392));
  yaSSL::SSL_SESSION::~SSL_SESSION(this: (QAngle *)(this + 2176), a2: v3);
  yaSSL::Connection::~Connection(this: (yaSSL::Connection *)(this + 104));
  JUMPOUT(0x422F50);
}

//------------------------------------------------------------------------------
// Address: 0x00416BA0
// Name: _yaSSL_CTX_free
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __cdecl yaSSL_CTX_free(CUtlStringList ptr)
{
  return yaSSL::ysDelete<yaSSL::SSL_CTX>(ptr);
}

//------------------------------------------------------------------------------
// Address: 0x00416BB0
// Name: public: void mySTL::auto_ptr<struct yaSSL::BulkCipher>::reset(struct yaSSL::BulkCipher __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge mySTL::auto_ptr<yaSSL::BulkCipher>::reset(IAppSystem *this@<ecx>, IAppSystem_vtbl *p, const char *a3)
{
  if ( this->__vftable != p )
  {
    yaSSL::ysDelete<yaSSL::BulkCipher>(ptr: (KeyValues *)this, a2: (int)this->__vftable);
    this->__vftable = p;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416C00
// Name: public: TaoCrypt::Source::Source(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Source::Source(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        int (__cdecl *b)(const CUtlString *, const CUtlString *),
        CUtlString *sz)
{
  unsigned __int8 *v3; // eax
  CUtlString *m_pMemory; // [esp-4h] [ebp-8h]

  v3 = (unsigned __int8 *)sz;
  this->m_Memory.m_pMemory = sz;
  if ( sz != nullptr )
    v3 = (unsigned __int8 *)operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Memory.m_nAllocationCount = (int)v3;
  memcpy(dst: v3, src: (unsigned __int8 *)b, count: (unsigned int)m_pMemory);
  this->m_Size = 0;
  this->m_pElements = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00416C50
// Name: public: TaoCrypt::Source::~Source(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Source::~Source(ICvar *this)
{
  unsigned __int8 *v1; // esi

  v1 = *((unsigned __int8 **)this + 1);
  memset(dst: v1, value: 0, count: (unsigned int)this->__vftable);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00416C70
// Name: _yaDH_free
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *__cdecl yaDH_free(
        _DWORD *a1)
{
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *v1; // ecx

  yaSSL::ysDelete<yaSSL::BIGNUM>(a1: a1[1]);
  yaSSL::ysDelete<yaSSL::BIGNUM>(a1: *a1);
  return yaSSL::ysDelete<unsigned char>(result: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00416CD0
// Name: _yaSSL_free
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int yaSSL_free()
{
  return yaSSL::ysDelete<yaSSL::SSL>();
}

//------------------------------------------------------------------------------
// Address: 0x00416D30
// Name: public: TaoCrypt::HexDecoder::HexDecoder(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
ICvar *__thiscall TaoCrypt::HexDecoder::HexDecoder(ICvar *this, ICvarQuery *result)
{
  ICvarQuery *v4; // [esp+0h] [ebp-4h]

  this->__vftable = nullptr;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 1) = TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: (int)(this + 2),
                            src: nullptr,
                            a3: 0,
                            count: 0,
                            a5: 0);
  this->__vftable = nullptr;
  *((_DWORD *)this + 3) = result;
  TaoCrypt::HexDecoder::Decode(this, a2: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00416D80
// Name: int yaSSL::read_file(class yaSSL::SSL_CTX __near *,char const __near *,int,enum yaSSL::CertType)
// Source: json
//------------------------------------------------------------------------------
int __usercall yaSSL::read_file@<eax>(
        unsigned int a1@<ebx>,
        const Quaternion *a2@<ebp>,
        yaSSL::SSL_CTX *result,
        char *a4,
        int format,
        int a6)
{
  _iobuf *v7; // ebp
  CUtlMemory<KeyValues *,int> *i; // eax
  CUtlMemory<KeyValues *,int> *v9; // esi
  const CSplitScreenAddedConVar *v10; // ecx
  yaSSL::x509 *v11; // eax
  CUtlMemory<KeyValues *,int> *v12; // eax
  void *v13; // eax
  CUtlMemory<KeyValues *,int> *v14; // eax
  Quaternion *PasswordCb; // edi
  const Quaternion *UserData; // eax
  Color v17; // esi
  unsigned int m_pConVar; // eax
  const CSplitScreenAddedConVar *v19; // ecx
  CSplitScreenAddedConVar *v20; // eax
  IAppSystem_vtbl *v21; // eax
  CSplitScreenAddedConVar *v22; // eax
  const CSplitScreenAddedConVar *v23; // ecx
  CSplitScreenAddedConVar *v24; // eax
  const CSplitScreenAddedConVar *v25; // ecx
  CSplitScreenAddedConVar *v26; // eax
  CSplitScreenAddedConVar *v27; // eax
  IAppSystem_vtbl *v28; // esi
  const CSplitScreenAddedConVar *v29; // ecx
  yaSSL::x509 *v30; // edi
  const struct SSL_METHOD *Method; // eax
  CUtlMemory<KeyValues *,int> *v32; // edi
  bool (__thiscall *Connect)(IAppSystem *, void *(__cdecl *)(const char *, int *)); // ebx
  CUtlMemory<KeyValues *,int> *v34; // eax
  CUtlMemory<KeyValues *,int> *v35; // eax
  int v36; // eax
  sockaddr_in *v37; // ecx
  sockaddr_in *v38; // ecx
  KeyValues *v39; // ecx
  KeyValues *v40; // ecx
  unsigned int v41; // [esp-8h] [ebp-144h]
  int v42; // [esp+0h] [ebp-13Ch]
  wchar_t *v44; // [esp+4h] [ebp-138h]
  int v45; // [esp+4h] [ebp-138h]
  int v46; // [esp+4h] [ebp-138h]
  unsigned int v47; // [esp+8h] [ebp-134h]
  unsigned __int16 v48; // [esp+Ch] [ebp-130h]
  ITypeInfo **v49; // [esp+10h] [ebp-12Ch]
  tagDESCKIND *v50; // [esp+14h] [ebp-128h]
  IAppSystem v51; // [esp+18h] [ebp-124h] BYREF
  ConVarRef source; // [esp+1Ch] [ebp-120h] BYREF
  ICvar v53; // [esp+30h] [ebp-10Ch] BYREF
  <CrtImplementationDetails>::NativeDll info; // [esp+40h] [ebp-FCh] BYREF
  unsigned __int8 dst[32]; // [esp+90h] [ebp-ACh] BYREF
  CUtlString *v56; // [esp+B0h] [ebp-8Ch]
  char v57; // [esp+B4h] [ebp-88h]
  CDatamapFieldSizeDeducer<8> iv; // [esp+B8h] [ebp-84h] BYREF
  <CrtImplementationDetails>::NativeDll key; // [esp+C8h] [ebp-74h] BYREF
  $_s__RTTIBaseClassArray$_extraBytes_8 password; // [esp+E8h] [ebp-54h] BYREF

  if ( format != 10 && format != 11 )
    return -5;
  v47 = a1;
  if ( a4 == nullptr || *a4 == 0 )
    return -4;
  v7 = fopen(file: a4, mode: "rb");
  if ( v7 == nullptr )
    return -4;
  if ( a6 == 2 )
  {
    for ( i = yaSSL::PemToDer(result: v7, file_4: 0, dst: nullptr);
          i != nullptr;
          i = yaSSL::PemToDer(result: v7, file_4: 0, dst: nullptr) )
    {
      yaSSL::SSL_CTX::AddCA(this: result, a2: (struct yaSSL::x509 *)i);
    }
    if ( feof(stream: v7) == 0 )
      goto LABEL_11;
    goto LABEL_21;
  }
  if ( a6 != 0 )
    v50 = (tagDESCKIND *)(result + 2);
  else
    v50 = (tagDESCKIND *)(result + 1);
  if ( format == 10 )
  {
    fseek(stream: v7, offset: 0, whence: 2);
    v9 = (CUtlMemory<KeyValues *,int> *)ftell(stream: v7);
    rewind(str: v7);
    v11 = (yaSSL::x509 *)operator new(sz: v10);
    if ( v11 != nullptr )
      v12 = (CUtlMemory<KeyValues *,int> *)yaSSL::x509::x509(this: v11, a2: (unsigned int)v9);
    else
      v12 = nullptr;
    *v50 = (tagDESCKIND)v12;
    yaSSL::SSL_CTX::getCert(this: v12, a2: v9);
    if ( fread(buffer: v13, elementSize: v41, count: 1u, stream: v7) == 1 )
      goto LABEL_21;
    goto LABEL_11;
  }
  v56 = nullptr;
  v57 = 0;
  v14 = yaSSL::PemToDer(result: v7, file_4: a6, dst: (unsigned __int8 *)&info);
  *v50 = (tagDESCKIND)v14;
  if ( v14 == nullptr )
    goto LABEL_11;
  if ( v57 == 0 )
  {
LABEL_21:
    fclose(stream: v7);
    return 1;
  }
  PasswordCb = yaSSL::SSL_CTX::GetPasswordCb(this: (QuaternionAligned *)result);
  if ( PasswordCb == nullptr )
  {
LABEL_11:
    fclose(stream: v7);
    return -4;
  }
  UserData = yaSSL::SSL_CTX::GetUserData(result: a2);
  v17 = (Color)((int (__cdecl *)($_s__RTTIBaseClassArray$_extraBytes_8 *, int, _DWORD, const Quaternion *))PasswordCb)(
                 a1: &password,
                 a2: 80,
                 a3: 0,
                 a4: UserData);
  TaoCrypt::Source::Source(
    this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&source,
    b: (int (__cdecl *)(const CUtlString *, const CUtlString *))dst,
    sz: v56);
  TaoCrypt::HexDecoder::HexDecoder(this: &v53, result: (ICvarQuery *)&source);
  m_pConVar = (unsigned int)source.m_pConVar;
  if ( source.m_pConVar > (IConVar *)0x20 )
    m_pConVar = 32;
  memcpy(dst, src: (unsigned __int8 *)source.m_pConVarState, count: m_pConVar);
  yaEVP_BytesToKey(
    a1: (char *)&info,
    first: "MD5",
    a3: (int)dst,
    a4: (int)&password,
    plain: v17,
    a6: 1,
    a7: (int)&key,
    a8: (int)&iv);
  v51.__vftable = nullptr;
  if ( strncmp(first: (const char *)&info, last: "DES-CBC", count: 7u) != 0 )
  {
    if ( strncmp(first: (const char *)&info, last: "DES-EDE3-CBC", count: 0xDu) == 0 )
    {
      v22 = operator new(sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
      if ( v22 != nullptr )
      {
        v21 = (IAppSystem_vtbl *)yaSSL::DES_EDE::DES_EDE(this: v22);
        goto LABEL_43;
      }
    }
    else if ( strncmp(first: (const char *)&info, last: "AES-128-CBC", count: 0xDu) == 0 )
    {
      v24 = operator new(sz: v23);
      if ( v24 != nullptr )
      {
        v21 = (IAppSystem_vtbl *)yaSSL::AES::AES(
                                   a1: v24,
                                   this: (ITypeComp *)0x10,
                                   ks: v44,
                                   a4: a1,
                                   a5: v48,
                                   a6: v49,
                                   a7: v50,
                                   a8: (tagBINDPTR *)v51.__vftable);
        goto LABEL_43;
      }
    }
    else if ( strncmp(first: (const char *)&info, last: "AES-192-CBC", count: 0xDu) == 0 )
    {
      v26 = operator new(sz: v25);
      if ( v26 != nullptr )
      {
        v21 = (IAppSystem_vtbl *)yaSSL::AES::AES(
                                   a1: v26,
                                   this: (ITypeComp *)0x18,
                                   ks: v44,
                                   a4: a1,
                                   a5: v48,
                                   a6: v49,
                                   a7: v50,
                                   a8: (tagBINDPTR *)v51.__vftable);
        goto LABEL_43;
      }
    }
    else
    {
      if ( strncmp(first: (const char *)&info, last: "AES-256-CBC", count: 0xDu) != 0 )
      {
        fclose(stream: v7);
        yaSSL::ysDelete<yaSSL::BulkCipher>(ptr: v40, a2: 0);
        TaoCrypt::Source::~Source(this: &v53);
        TaoCrypt::Source::~Source(this: (ICvar *)&source);
        return -4;
      }
      v27 = operator new(sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
      if ( v27 != nullptr )
      {
        v21 = (IAppSystem_vtbl *)yaSSL::AES::AES(
                                   a1: v27,
                                   this: (ITypeComp *)0x20,
                                   ks: v44,
                                   a4: a1,
                                   a5: v48,
                                   a6: v49,
                                   a7: v50,
                                   a8: (tagBINDPTR *)v51.__vftable);
        goto LABEL_43;
      }
    }
LABEL_42:
    v21 = nullptr;
    goto LABEL_43;
  }
  v20 = operator new(sz: v19);
  if ( v20 == nullptr )
    goto LABEL_42;
  v21 = (IAppSystem_vtbl *)yaSSL::DES::DES(this: v20);
LABEL_43:
  mySTL::auto_ptr<yaSSL::BulkCipher>::reset(this: &v51, p: v21, a3: (const char *)v44);
  v28 = v51.__vftable;
  (*((void (__thiscall **)(IAppSystem_vtbl *, <CrtImplementationDetails>::NativeDll *, unsigned __int8 *, int, unsigned int))v51.Connect
   + 3))(
    a1: v51.__vftable,
    a2: &key,
    a3: dst,
    a4: v45,
    a5: v47);
  v30 = (yaSSL::x509 *)operator new(sz: v29);
  if ( v30 != nullptr )
  {
    Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)source.m_pConVar->__vftable);
    v32 = (CUtlMemory<KeyValues *,int> *)yaSSL::x509::x509(this: v30, a2: (unsigned int)Method);
  }
  else
  {
    v32 = nullptr;
  }
  Connect = v28->Connect;
  v34 = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)source.m_pConVar->__vftable);
  yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)source.m_pConVar->__vftable, a2: v34);
  yaSSL::SSL_CTX::getCert(this: v32, a2: v35);
  (*((void (__thiscall **)(IAppSystem_vtbl *, int))Connect + 1))(a1: v28, a2: v36);
  yaSSL::ysDelete<yaSSL::x509>(ptr: v37, a2: *(unsigned __int8 **)v50, a3: v46);
  *v50 = (tagDESCKIND)v32;
  yaSSL::ysDelete<yaSSL::x509>(ptr: v38, a2: nullptr, a3: v42);
  yaSSL::ysDelete<yaSSL::BulkCipher>(ptr: v39, a2: (int)v28);
  TaoCrypt::Source::~Source(this: &v53);
  TaoCrypt::Source::~Source(this: (ICvar *)&source);
  fclose(stream: v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00417200
// Name: _yaSSL_CTX_use_certificate_file
// Source: json
//------------------------------------------------------------------------------
const char *__usercall yaSSL_CTX_use_certificate_file@<eax>(
        unsigned int a1@<ebx>,
        const Quaternion *a2@<ebp>,
        yaSSL::SSL_CTX *file,
        char *a4,
        int format)
{
  return (const char *)yaSSL::read_file(a1, a2, result: file, a4, format, a6: 0);
}

//------------------------------------------------------------------------------
// Address: 0x00417220
// Name: _yaSSL_CTX_use_PrivateKey_file
// Source: json
//------------------------------------------------------------------------------
const char *__usercall yaSSL_CTX_use_PrivateKey_file@<eax>(
        unsigned int a1@<ebx>,
        const Quaternion *a2@<ebp>,
        yaSSL::SSL_CTX *file,
        char *a4,
        int format)
{
  return (const char *)yaSSL::read_file(a1, a2, result: file, a4, format, a6: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00417240
// Name: _yaSSL_CTX_load_verify_locations
// Source: json
//------------------------------------------------------------------------------
int __usercall yaSSL_CTX_load_verify_locations@<eax>(
        const Quaternion *a1@<ebp>,
        yaSSL::SSL_CTX *file,
        char *a3,
        unsigned __int8 *path)
{
  int v4; // esi
  Quaternion *FirstFileA; // ebp
  struct _WIN32_FIND_DATAA FindFileData; // [esp+10h] [ebp-24Ch] BYREF
  unsigned __int8 dest[264]; // [esp+150h] [ebp-10Ch] BYREF

  v4 = 1;
  if ( (a3 == nullptr
     || (v4 = yaSSL::read_file(a1: (unsigned int)path, a2: a1, result: file, a4: a3, format: 11, a6: 2)) == 1)
    && path != nullptr )
  {
    strncpy(dest, source: path, count: 0x101u);
    strncat(Destination: (char *)dest, Source: "\\*", Count: 3u);
    FirstFileA = (Quaternion *)FindFirstFileA(lpFileName: (LPCSTR)dest, lpFindFileData: &FindFileData);
    if ( FirstFileA == (Quaternion *)-1 )
      return -6;
    do
    {
      if ( FindFileData.dwFileAttributes != 16 )
      {
        strncpy(dest, source: path, count: 0x82u);
        strncat(Destination: (char *)dest, Source: "\\", Count: 2u);
        strncat(Destination: (char *)dest, Source: FindFileData.cFileName, Count: 0x80u);
        v4 = yaSSL::read_file(a1: (unsigned int)path, a2: FirstFileA, result: file, a4: (char *)dest, format: 11, a6: 2);
      }
    }
    while ( v4 == 1 && FindNextFileA(hFindFile: FirstFileA, lpFindFileData: &FindFileData) );
    FindClose(hFindFile: FirstFileA);
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00417380
// Name: _yaBN_bin2bn
// Source: json
//------------------------------------------------------------------------------
IMemAlloc *__cdecl yaBN_bin2bn(unsigned __int16 num, unsigned __int16 sz, IMemAlloc *a3)
{
  const CSplitScreenAddedConVar *v3; // ecx
  IMemAlloc *v4; // esi
  char v5; // bl
  IMemAlloc *v6; // edi
  IMemAlloc *v7; // eax
  IMemAlloc *v8; // esi

  v4 = a3;
  v5 = 0;
  v6 = nullptr;
  if ( a3 == nullptr )
  {
    v5 = 1;
    v7 = (IMemAlloc *)operator new(sz: v3);
    v8 = v7;
    if ( v7 != nullptr )
    {
      yaSSL::Integer::Integer(this: v7);
      yaSSL::ysDelete<yaSSL::BIGNUM>(a1: 0);
      v6 = v8;
    }
    v4 = v6;
  }
  yaSSL::Integer::assign(this: v4, num, sz);
  if ( v5 != 0 )
  {
    yaSSL::ysDelete<yaSSL::BIGNUM>(a1: 0);
    return v6;
  }
  else
  {
    yaSSL::ysDelete<yaSSL::BIGNUM>(a1: v6);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00417E40
// Name: _yaX509_STORE_CTX_get_error
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaX509_STORE_CTX_get_error(int a1)
{
  return *(_DWORD *)a1;
}

//------------------------------------------------------------------------------
// Address: 0x00420D90
// Name: public: class yaSSL::Buffers __near & yaSSL::SSL::useBuffers(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall yaSSL::SSL::useBuffers(CThreadSyncObject *this)
{
  return this + 312;
}

//------------------------------------------------------------------------------
// Address: 0x00420E90
// Name: public: class yaSSL::Security __near & yaSSL::SSL::useSecurity(void)
// Source: json
//------------------------------------------------------------------------------
const CThreadSyncObject *__thiscall yaSSL::SSL::useSecurity(char *this)
{
  return (const CThreadSyncObject *)(this + 104);
}

//------------------------------------------------------------------------------
// Address: 0x00420EA0
// Name: public: class yaSSL::sslHashes const __near & yaSSL::SSL::getHashes(void)const
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall yaSSL::SSL::getHashes(CThreadSyncObject *this)
{
  return this + 299;
}

//------------------------------------------------------------------------------
// Address: 0x00420EB0
// Name: public: enum yaSSL::YasslError yaSSL::SSL::GetError(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::SSL::GetError(char *this)
{
  return yaSSL::States::What(a1: this + 2284);
}

//------------------------------------------------------------------------------
// Address: 0x00420ED0
// Name: public: class yaSSL::States __near & yaSSL::SSL::useStates(void)
// Source: json
//------------------------------------------------------------------------------
const CThreadSyncObject *__thiscall yaSSL::SSL::useStates(char *this)
{
  return (const CThreadSyncObject *)(this + 2284);
}

//------------------------------------------------------------------------------
// Address: 0x00420EE0
// Name: public: class yaSSL::Socket __near & yaSSL::SSL::useSocket(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::useSocket(CThreadSyncObject *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00420EF0
// Name: public: class yaSSL::Log __near & yaSSL::SSL::useLog(void)
// Source: json
//------------------------------------------------------------------------------
CThreadSyncObject *__thiscall yaSSL::SSL::useLog(char *this)
{
  return (CThreadSyncObject *)(this + 2524);
}

//------------------------------------------------------------------------------
// Address: 0x00423E70
// Name: public: class yaSSL::sslFactory const __near & yaSSL::SSL::getFactory(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const struct yaSSL::sslFactory *__thiscall yaSSL::SSL::getFactory(yaSSL::SSL *this, yaSSL *a2)
{
  return yaSSL::GetSSL_Factory(this: a2);
}

//------------------------------------------------------------------------------
// Address: 0x00424650
// Name: public: virtual unsigned int TaoCrypt::MD5::getBlockSize(void)const
// Source: json
//------------------------------------------------------------------------------
int TaoCrypt::MD5::getBlockSize()
{
  return 64;
}

//------------------------------------------------------------------------------
// Address: 0x00420DA0
// Name: yaSSL::_anonymous_namespace_::setPrefix
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __usercall yaSSL::_anonymous_namespace_::setPrefix@<al>(_BYTE *a1@<eax>, int a2@<ecx>)
{
  char result; // al

  switch ( a2 )
  {
    case 0:
      *a1 = 65;
      result = 1;
      break;
    case 1:
      *(_WORD *)a1 = 16962;
      result = 1;
      break;
    case 2:
      *(_WORD *)a1 = *(_WORD *)aCc;
      a1[2] = 67;
      result = 1;
      break;
    case 3:
      *(_DWORD *)a1 = 1145324612;
      result = 1;
      break;
    case 4:
      *(_DWORD *)a1 = *(_DWORD *)aEeee;
      a1[4] = 69;
      result = 1;
      break;
    case 5:
      *(_DWORD *)a1 = *(_DWORD *)aFfff;
      *((_WORD *)a1 + 2) = 17990;
      result = 1;
      break;
    case 6:
      *(_DWORD *)a1 = *(_DWORD *)aGggg;
      *((_WORD *)a1 + 2) = 18247;
      a1[6] = 71;
      result = 1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
