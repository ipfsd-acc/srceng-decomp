// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/crypto_wrapper.cpp
// Functions: 121
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\crypto_wrapper.h"

//------------------------------------------------------------------------------
// Address: 0x00416150
// Name: public: virtual unsigned int TaoCrypt::RIPEMD160::getPadSize(void)const
// Source: json
//------------------------------------------------------------------------------
int TaoCrypt::RIPEMD160::getPadSize()
{
  return 56;
}

//------------------------------------------------------------------------------
// Address: 0x00421090
// Name: public: int (*yaSSL::SSL_CTX::getVerifyCallback(void)const)(int,struct yaSSL::X509_STORE_CTX __near *)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall yaSSL::SSL_CTX::getVerifyCallback(_DWORD *this)
{
  return (Quaternion *)*(this + 62);
}

//------------------------------------------------------------------------------
// Address: 0x00424660
// Name: public: virtual int yaSSL::RC4::get_ivSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::RC4::get_ivSize(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00424670
// Name: protected: void TaoCrypt::Mode_BASE::ECB_Process(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Mode_BASE::ECB_Process(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this,
        unsigned __int8 *out,
        const LoggingContext_t *in,
        unsigned int sz)
{
  int i; // edi
  int m_nAllocationCount; // eax

  for ( i = sz / this->m_nAllocationCount; i != 0; in = (const LoggingContext_t *)((char *)in + m_nAllocationCount) )
  {
    --i;
    (*((void (__thiscall **)(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *, const LoggingContext_t *, _DWORD, unsigned __int8 *))this->m_pMemory
     + 2))(
      a1: this,
      a2: in,
      a3: 0,
      a4: out);
    m_nAllocationCount = this->m_nAllocationCount;
    out += m_nAllocationCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004246B0
// Name: protected: void TaoCrypt::Mode_BASE::CBC_Encrypt(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::Mode_BASE::CBC_Encrypt(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this@<ecx>,
        unsigned int a2@<ebp>,
        unsigned __int8 *out,
        unsigned __int8 *in,
        unsigned int sz)
{
  int v6; // edi
  int m_nAllocationCount; // eax
  unsigned int v10; // [esp-8h] [ebp-10h]

  v6 = sz / this->m_nAllocationCount;
  if ( v6 != 0 )
  {
    v10 = a2;
    do
    {
      --v6;
      TaoCrypt::xorbuf(
        this: (TaoCrypt *)this->m_nGrowSize,
        a2: in,
        a3: (const unsigned __int8 *)this->m_nAllocationCount,
        a4: v10);
      (*((void (__thiscall **)(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *, int, _DWORD, int))this->m_pMemory + 2))(
        a1: this,
        a2: this->m_nGrowSize,
        a3: 0,
        a4: this->m_nGrowSize);
      memcpy(dst: out, src: (unsigned __int8 *)this->m_nGrowSize, count: this->m_nAllocationCount);
      m_nAllocationCount = this->m_nAllocationCount;
      out += m_nAllocationCount;
      in += m_nAllocationCount;
    }
    while ( v6 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424720
// Name: protected: void TaoCrypt::Mode_BASE::CBC_Decrypt(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::Mode_BASE::CBC_Decrypt(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this@<ecx>,
        unsigned int a2@<ebp>,
        unsigned __int8 *out,
        unsigned __int8 *in,
        unsigned int sz)
{
  unsigned int m_nAllocationCount; // ebx
  unsigned __int8 *m_nGrowSize; // ebp
  int v9; // eax
  unsigned int v10; // [esp-4h] [ebp-2Ch]
  unsigned int blocks; // [esp+Ch] [ebp-1Ch]
  CDatamapFieldSizeDeducer<8> hold; // [esp+14h] [ebp-14h] BYREF

  blocks = sz / this->m_nAllocationCount;
  if ( blocks != 0 )
  {
    v10 = a2;
    do
    {
      --blocks;
      memcpy(dst: *((unsigned __int8 **)this + 3), src: in, count: this->m_nAllocationCount);
      (*((void (__thiscall **)(CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *, _DWORD, _DWORD, unsigned __int8 *))this->m_pMemory
       + 2))(
        a1: this,
        a2: *((_DWORD *)this + 3),
        a3: 0,
        a4: out);
      TaoCrypt::xorbuf(
        this: (TaoCrypt *)out,
        a2: (unsigned __int8 *)this->m_nGrowSize,
        a3: (const unsigned __int8 *)this->m_nAllocationCount,
        a4: v10);
      m_nAllocationCount = this->m_nAllocationCount;
      m_nGrowSize = (unsigned __int8 *)this->m_nGrowSize;
      memcpy(dst: (unsigned __int8 *)&hold, src: m_nGrowSize, count: m_nAllocationCount);
      memcpy(dst: m_nGrowSize, src: *((unsigned __int8 **)this + 3), count: m_nAllocationCount);
      memcpy(dst: *((unsigned __int8 **)this + 3), src: (unsigned __int8 *)&hold, count: this->m_nAllocationCount);
      v9 = this->m_nAllocationCount;
      in += v9;
      out += v9;
    }
    while ( blocks != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x004247E0
// Name: public: yaSSL::MD5::MD5(class yaSSL::MD5 const __near &)
// Source: json
//------------------------------------------------------------------------------
yaSSL::MD5 *__thiscall yaSSL::MD5::MD5(yaSSL::MD5 *this, const struct yaSSL::MD5 *a2)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v3; // eax
  int v4; // edi
  int v6; // [esp+0h] [ebp-8h]
  int v7; // [esp+4h] [ebp-4h]

  this->m_Memory.m_pMemory = (KeyValues **)&yaSSL::MD5::`vftable';
  v3 = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  v4 = (int)v3;
  if ( v3 != nullptr )
  {
    TaoCrypt::MD5::MD5(this: v3, that: (CUtlString *)a2->m_Memory.m_nAllocationCount, a3: v6, a4: v7);
    this->m_Memory.m_nAllocationCount = v4;
  }
  else
  {
    this->m_Memory.m_nAllocationCount = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424850
// Name: public: yaSSL::SHA::SHA(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SHA::SHA(Vector2D *this)
{
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v2; // eax
  std::exception *v3; // edi
  const std::exception *v4; // [esp+0h] [ebp-8h]

  LODWORD(this->x) = &yaSSL::SHA::`vftable';
  v2 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  v3 = (std::exception *)v2;
  if ( v2 != nullptr )
  {
    TaoCrypt::HASHwithTransform::HASHwithTransform(this: v2, digSz: 5);
    v3->__vftable = (std::exception_vtbl *)&TaoCrypt::SHA::`vftable';
    TaoCrypt::RIPEMD160::Init(this: v3, a2: v4);
    LODWORD(this->y) = v3;
  }
  else
  {
    this->y = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004248A0
// Name: public: yaSSL::SHA::SHA(class yaSSL::SHA const __near &)
// Source: json
//------------------------------------------------------------------------------
yaSSL::SHA *__thiscall yaSSL::SHA::SHA(yaSSL::SHA *this, const struct TaoCrypt::SHA **a2)
{
  TaoCrypt::SHA *v3; // eax
  float *v4; // edi

  *this = (yaSSL::SHA)&yaSSL::SHA::`vftable';
  v3 = (TaoCrypt::SHA *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  v4 = (float *)v3;
  if ( v3 != nullptr )
  {
    TaoCrypt::SHA::SHA(this: v3, a2: a2[1]);
    *(this + 1) = v4;
  }
  else
  {
    *(this + 1) = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424910
// Name: public: virtual unsigned int yaSSL::HMAC_SHA::get_padSize(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::HMAC_SHA::get_padSize()
{
  return 40;
}

//------------------------------------------------------------------------------
// Address: 0x00424920
// Name: public: virtual void yaSSL::MD5::get_digest(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::MD5::get_digest(
        CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *this,
        const CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *out)
{
  (*(void (__thiscall **)(int, const CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *))(*(_DWORD *)this->m_Memory.m_nAllocationCount + 8))(
    a1: this->m_Memory.m_nAllocationCount,
    a2: out);
}

//------------------------------------------------------------------------------
// Address: 0x00424930
// Name: public: yaSSL::RMD::RMD(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::RMD::RMD(CSplitScreenAddedConVar *this)
{
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v2; // eax
  std::exception *v3; // edi
  const std::exception *v5; // [esp+0h] [ebp-8h]

  this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::RMD::`vftable';
  v2 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)operator new(sz: this);
  v3 = (std::exception *)v2;
  if ( v2 != nullptr )
  {
    TaoCrypt::HASHwithTransform::HASHwithTransform(this: v2, digSz: 5);
    v3->__vftable = (std::exception_vtbl *)&TaoCrypt::RIPEMD160::`vftable';
    TaoCrypt::RIPEMD160::Init(this: v3, a2: v5);
    this->m_pNext = (ConCommandBase *)v3;
  }
  else
  {
    this->m_pNext = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424980
// Name: public: virtual unsigned int yaSSL::HMAC_RMD::get_padSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::HMAC_RMD::get_padSize(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this)
{
  return 44;
}

//------------------------------------------------------------------------------
// Address: 0x00424990
// Name: public: virtual void yaSSL::MD5::get_digest(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
Vector2D *__thiscall yaSSL::MD5::get_digest(
        _DWORD **this,
        Vector2D *result,
        const LoggingContext_t *in,
        unsigned int sz)
{
  (*(void (__thiscall **)(_DWORD, const LoggingContext_t *, unsigned int))(**(this + 1) + 4))(
    a1: *(this + 1),
    a2: in,
    a3: sz);
  return (*(Vector2D *(__thiscall **)(_DWORD, Vector2D *))(**(this + 1) + 8))(a1: *(this + 1), a2: result);
}

//------------------------------------------------------------------------------
// Address: 0x004249C0
// Name: public: virtual unsigned int yaSSL::MD5::get_padSize(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::MD5::get_padSize()
{
  return 48;
}

//------------------------------------------------------------------------------
// Address: 0x004249D0
// Name: public: virtual unsigned int yaSSL::HMAC_SHA::get_digestSize(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::HMAC_SHA::get_digestSize(Vector2D *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004249E0
// Name: public: virtual void yaSSL::RC4::set_encryptKey(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void yaSSL::RC4::set_encryptKey()
{
  JUMPOUT(0x44AFF0);
}

//------------------------------------------------------------------------------
// Address: 0x004249F0
// Name: public: virtual void yaSSL::RC4::set_decryptKey(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void yaSSL::RC4::set_decryptKey()
{
  JUMPOUT(0x44AFF0);
}

//------------------------------------------------------------------------------
// Address: 0x00424A10
// Name: public: virtual void yaSSL::RC4::encrypt(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RC4::encrypt(
        TaoCrypt::ARC4 **this,
        unsigned __int8 *cipher,
        const LoggingContext_t *plain,
        unsigned int sz)
{
  TaoCrypt::ARC4::Process(this: *(this + 1), x: cipher, in: plain, a4: sz);
}

//------------------------------------------------------------------------------
// Address: 0x00424A20
// Name: public: virtual void yaSSL::RC4::decrypt(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RC4::decrypt(
        yaSSL::RC4 *this,
        unsigned __int8 *plain,
        const LoggingContext_t *cipher,
        unsigned int sz)
{
  TaoCrypt::ARC4::Process(this: (TaoCrypt::ARC4 *)(*((_DWORD *)this + 1) + 258), x: plain, in: cipher, a4: sz);
}

//------------------------------------------------------------------------------
// Address: 0x00424A30
// Name: public: virtual int yaSSL::AES::get_keySize(void)const
// Source: json
//------------------------------------------------------------------------------
tagDESCKIND __thiscall yaSSL::AES::get_keySize(_DWORD *this)
{
  return *(_DWORD *)(*(this + 1) + 600);
}

//------------------------------------------------------------------------------
// Address: 0x00424A40
// Name: public: int yaSSL::RandomPool::GetError(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall yaSSL::RandomPool::GetError(yaSSL::RandomPool *this)
{
  return (*this)->decVal.Hi32;
}

//------------------------------------------------------------------------------
// Address: 0x00424A50
// Name: public: void yaSSL::RandomPool::Fill(unsigned char __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RandomPool::Fill(yaSSL::RandomPool *this, unsigned __int8 *dst, unsigned int sz)
{
  TaoCrypt::RandomNumberGenerator::GenerateBlock(this: (TaoCrypt::RandomNumberGenerator *)*this, output: dst, a3: sz);
}

//------------------------------------------------------------------------------
// Address: 0x00424A60
// Name: public: virtual unsigned int yaSSL::DSS::get_signatureLength(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DSS::get_signatureLength(
        CThread *this,
        int (__cdecl *a2)(const CCountedStringPoolBase<unsigned int>::hash_item_t *, const CCountedStringPoolBase<unsigned int>::hash_item_t *))
{
  TaoCrypt::DSA_PublicKey::SignatureLength(
    this: *(CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > **)this->m_Lock.m_CriticalSection,
    a2);
}

//------------------------------------------------------------------------------
// Address: 0x00424A70
// Name: public: unsigned int yaSSL::RSA::get_cipherLength(void)const
// Source: json
//------------------------------------------------------------------------------
const CThreadMutex *yaSSL::RSA::get_cipherLength()
{
  return (const CThreadMutex *)TaoCrypt::Integer::ByteCount();
}

//------------------------------------------------------------------------------
// Address: 0x00424A80
// Name: public: virtual unsigned int yaSSL::RSA::get_signatureLength(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const CThreadMutex *yaSSL::RSA::get_signatureLength()
{
  return yaSSL::RSA::get_cipherLength();
}

//------------------------------------------------------------------------------
// Address: 0x00424AB0
// Name: public: void yaSSL::DiffieHellman::makeAgreement(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DiffieHellman::makeAgreement(
        QAngleByValue *this,
        const QAngleByValue *other,
        unsigned int otherSz)
{
  TaoCrypt::DH::Agree(
    this: (TaoCrypt::DH *)LODWORD(this->x),
    a2: *(unsigned __int8 **)(LODWORD(this->x) + 44),
    encodedInteger: *(const unsigned __int8 **)(LODWORD(this->x) + 40),
    a4: (const unsigned __int8 *)other,
    a5: otherSz);
}

//------------------------------------------------------------------------------
// Address: 0x00424AD0
// Name: public: unsigned int yaSSL::DiffieHellman::get_agreedKeyLength(void)const
// Source: json
//------------------------------------------------------------------------------
QAngleByValue *yaSSL::DiffieHellman::get_agreedKeyLength()
{
  return (QAngleByValue *)TaoCrypt::Integer::ByteCount();
}

//------------------------------------------------------------------------------
// Address: 0x00424AE0
// Name: public: unsigned char const __near * yaSSL::DiffieHellman::get_agreedKey(void)const
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__thiscall yaSSL::DiffieHellman::get_agreedKey(yaSSL::DiffieHellman *this)
{
  return *(const unsigned __int8 **)(*(_DWORD *)this + 44);
}

//------------------------------------------------------------------------------
// Address: 0x00424AF0
// Name: public: unsigned char const __near * yaSSL::DiffieHellman::get_publicKey(void)const
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__thiscall yaSSL::DiffieHellman::get_publicKey(yaSSL::DiffieHellman *this)
{
  return *(const unsigned __int8 **)(*(_DWORD *)this + 36);
}

//------------------------------------------------------------------------------
// Address: 0x00424B00
// Name: public: void TaoCrypt::HMAC<class TaoCrypt::RIPEMD160>::Init(void)
// Source: json
//------------------------------------------------------------------------------
FilesystemMountRetval_t __thiscall TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Init(CFileSystemPassThru *this)
{
  FilesystemMountRetval_t result; // eax

  result = (*(int (__thiscall **)(CFileSystemPassThru *))(*((_DWORD *)this + 4) + 12))(a1: this + 1);
  LOBYTE(this->m_pFileSystemPassThru) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424B20
// Name: public: void TaoCrypt::HMAC<class TaoCrypt::MD5>::SetKey(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::HMAC<TaoCrypt::MD5>::SetKey(
        CFileSystemPassThru *this,
        unsigned __int8 *src,
        unsigned int count)
{
  int v4; // edi
  unsigned int result; // eax

  TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Init(this);
  v4 = count;
  if ( count > 0x40 )
  {
    (*(void (__thiscall **)(CFileSystemPassThru *, unsigned __int8 *, unsigned int))(*((_DWORD *)this + 4) + 4))(
      a1: this + 1,
      a2: src,
      a3: count);
    (*(void (__thiscall **)(CFileSystemPassThru *, CFileSystemPassThru_vtbl *))(*((_DWORD *)this + 4) + 8))(
      a1: this + 1,
      a2: this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable);
    v4 = 16;
  }
  else
  {
    memcpy(
      dst: (unsigned __int8 *)this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable,
      src,
      count);
  }
  memset(
    dst: (unsigned __int8 *)this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable + v4,
    value: 0,
    count: 64 - v4);
  for ( result = 0; result < 0x40; result += 4 )
  {
    *((_BYTE *)&this->Read + result) = *((_BYTE *)&this->Connect + result) ^ 0x5C;
    *((_BYTE *)&this->Connect + result) ^= 0x36u;
    *((_BYTE *)&this->Read + result + 1) = *((_BYTE *)&this->Connect + result + 1) ^ 0x5C;
    *((_BYTE *)&this->Connect + result + 1) ^= 0x36u;
    *((_BYTE *)&this->Read + result + 2) = *((_BYTE *)&this->Connect + result + 2) ^ 0x5C;
    *((_BYTE *)&this->Connect + result + 2) ^= 0x36u;
    *((_BYTE *)&this->Read + result + 3) = *((_BYTE *)&this->Connect + result + 3) ^ 0x5C;
    *((_BYTE *)&this->Connect + result + 3) ^= 0x36u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424C00
// Name: public: void TaoCrypt::HMAC<class TaoCrypt::RIPEMD160>::SetKey(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::SetKey(
        CFileSystemPassThru *this,
        unsigned __int8 *key,
        unsigned int length)
{
  int v4; // edi
  unsigned int result; // eax

  TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Init(this);
  v4 = length;
  if ( length > 0x40 )
  {
    (*(void (__thiscall **)(CFileSystemPassThru *, unsigned __int8 *, unsigned int))(*((_DWORD *)this + 4) + 4))(
      a1: this + 1,
      a2: key,
      a3: length);
    (*(void (__thiscall **)(CFileSystemPassThru *, CFileSystemPassThru_vtbl *))(*((_DWORD *)this + 4) + 8))(
      a1: this + 1,
      a2: this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable);
    v4 = 20;
  }
  else
  {
    memcpy(
      dst: (unsigned __int8 *)this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable,
      src: key,
      count: length);
  }
  memset(
    dst: (unsigned __int8 *)this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable + v4,
    value: 0,
    count: 64 - v4);
  for ( result = 0; result < 0x40; result += 4 )
  {
    *((_BYTE *)&this->Read + result) = *((_BYTE *)&this->Connect + result) ^ 0x5C;
    *((_BYTE *)&this->Connect + result) ^= 0x36u;
    *((_BYTE *)&this->Read + result + 1) = *((_BYTE *)&this->Connect + result + 1) ^ 0x5C;
    *((_BYTE *)&this->Connect + result + 1) ^= 0x36u;
    *((_BYTE *)&this->Read + result + 2) = *((_BYTE *)&this->Connect + result + 2) ^ 0x5C;
    *((_BYTE *)&this->Connect + result + 2) ^= 0x36u;
    *((_BYTE *)&this->Read + result + 3) = *((_BYTE *)&this->Connect + result + 3) ^ 0x5C;
    *((_BYTE *)&this->Connect + result + 3) ^= 0x36u;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424CE0
// Name: private: void TaoCrypt::HMAC<class TaoCrypt::RIPEMD160>::KeyInnerHash(void)
// Source: json
//------------------------------------------------------------------------------
FilesystemMountRetval_t __thiscall TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::KeyInnerHash(CFileSystemPassThru *this)
{
  FilesystemMountRetval_t result; // eax

  result = (*(int (__thiscall **)(CFileSystemPassThru *, CFileSystemPassThru_vtbl *, int))(*((_DWORD *)this + 4) + 4))(
             a1: this + 1,
             a2: this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable,
             a3: 64);
  LOBYTE(this->m_pFileSystemPassThru) = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424D10
// Name: public: virtual void TaoCrypt::Mode_BASE::Process(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::Mode_BASE::Process(
        CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *this@<ecx>,
        unsigned int a2@<ebp>,
        unsigned __int8 *out,
        const LoggingContext_t *in,
        unsigned int sz)
{
  int v5; // eax

  v5 = *((_DWORD *)this + 13);
  if ( v5 != 0 )
  {
    if ( v5 == 1 )
    {
      if ( *((_DWORD *)this + 12) != 0 )
        TaoCrypt::Mode_BASE::CBC_Decrypt(this, a2, out, (unsigned __int8 *)in, sz);
      else
        TaoCrypt::Mode_BASE::CBC_Encrypt(this, a2, out, (unsigned __int8 *)in, sz);
    }
  }
  else
  {
    TaoCrypt::Mode_BASE::ECB_Process(this, out, in, sz);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424D50
// Name: public: yaSSL::MD5::MD5(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues **__thiscall yaSSL::MD5::MD5(KeyValues **this)
{
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v2; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v3; // edi

  *this = (KeyValues *)&yaSSL::MD5::`vftable';
  v2 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  v3 = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)v2;
  if ( v2 != nullptr )
  {
    TaoCrypt::HASHwithTransform::HASHwithTransform(this: v2, digSz: 4);
    v3->m_Memory.m_pMemory = (CUtlString *)&TaoCrypt::MD5::`vftable';
    TaoCrypt::MD5::Init(this: v3);
    *(this + 1) = (KeyValues *)v3;
  }
  else
  {
    *(this + 1) = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424DA0
// Name: public: yaSSL::DES::DESImpl::DESImpl(void)
// Source: json
//------------------------------------------------------------------------------
CFileSystemPassThru *__thiscall yaSSL::DES::DESImpl::DESImpl(CFileSystemPassThru *this)
{
  this->m_pBaseFileSystemPassThru = (IBaseFileSystem *)(this + 1);
  this->m_pFileSystemPassThru = this + 2;
  *((_DWORD *)this + 12) = 0;
  this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystemPassThru_vtbl *)&TaoCrypt::DES::`vftable';
  this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)8;
  *((_DWORD *)this + 13) = 1;
  *((_DWORD *)this + 47) = 8;
  *((_DWORD *)this + 48) = (char *)this + 200;
  *((_DWORD *)this + 49) = (char *)this + 216;
  *((_DWORD *)this + 58) = 1;
  *((_DWORD *)this + 59) = 1;
  *((_DWORD *)this + 46) = &TaoCrypt::DES::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424E00
// Name: public: virtual void yaSSL::DES::set_encryptKey(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DES::set_encryptKey(CLoggingSystem *this, const LoggingContext_t *k, unsigned __int8 *iv)
{
  int m_ID; // esi

  m_ID = this->m_RegisteredChannels[0].m_ID;
  TaoCrypt::BasicDES::SetKey(a1: m_ID + 56, a2: k, a3: 8, a4: 0);
  memcpy(dst: *(unsigned __int8 **)(m_ID + 8), src: iv, count: *(_DWORD *)(m_ID + 4));
}

//------------------------------------------------------------------------------
// Address: 0x00424E30
// Name: public: virtual void yaSSL::DES::set_decryptKey(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DES::set_decryptKey(CLoggingSystem *this, const LoggingContext_t *k, unsigned __int8 *iv)
{
  int v3; // esi

  v3 = this->m_RegisteredChannels[0].m_ID + 184;
  TaoCrypt::BasicDES::SetKey(a1: this->m_RegisteredChannels[0].m_ID + 240, a2: k, a3: 8, a4: 1);
  memcpy(dst: *(unsigned __int8 **)(v3 + 8), src: iv, count: *(_DWORD *)(v3 + 4));
}

//------------------------------------------------------------------------------
// Address: 0x00424E70
// Name: public: virtual void yaSSL::DES::decrypt(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DES::decrypt(CLoggingSystem *this, unsigned __int8 *plain, Color cipher)
{
  (*(void (__thiscall **)(int, unsigned __int8 *, Color))(*(_DWORD *)(this->m_RegisteredChannels[0].m_ID + 184) + 4))(
    a1: this->m_RegisteredChannels[0].m_ID + 184,
    a2: plain,
    a3: cipher);
}

//------------------------------------------------------------------------------
// Address: 0x00424E90
// Name: public: yaSSL::DES_EDE::DES_EDEImpl::DES_EDEImpl(void)
// Source: json
//------------------------------------------------------------------------------
yaSSL::DES_EDE::DES_EDEImpl *__thiscall yaSSL::DES_EDE::DES_EDEImpl::DES_EDEImpl(yaSSL::DES_EDE::DES_EDEImpl *this)
{
  *((_DWORD *)this + 2) = (char *)this + 16;
  *((_DWORD *)this + 3) = (char *)this + 32;
  *((_DWORD *)this + 12) = 0;
  *(_DWORD *)this = &TaoCrypt::DES_EDE3::`vftable';
  *((_DWORD *)this + 1) = 8;
  *((_DWORD *)this + 13) = 1;
  *((_DWORD *)this + 111) = 8;
  *((_DWORD *)this + 112) = (char *)this + 456;
  *((_DWORD *)this + 113) = (char *)this + 472;
  *((_DWORD *)this + 122) = 1;
  *((_DWORD *)this + 123) = 1;
  *((_DWORD *)this + 110) = &TaoCrypt::DES_EDE3::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424EF0
// Name: public: virtual void yaSSL::DES_EDE::set_encryptKey(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
const LoggingContext_t *__thiscall yaSSL::DES_EDE::set_encryptKey(
        CInterlockedIntT<unsigned int> **this,
        const LoggingContext_t *result,
        const LoggingContext_t *iv)
{
  CInterlockedIntT<unsigned int> *v3; // esi

  v3 = *(this + 1);
  TaoCrypt::DES_EDE3::SetKey(this: v3, key: (unsigned int)result, sz: 0x18u);
  v3[4].m_value = iv->m_ChannelID;
  v3[5].m_value = iv->m_Flags;
  return iv;
}

//------------------------------------------------------------------------------
// Address: 0x00424F20
// Name: public: virtual void yaSSL::DES_EDE::set_decryptKey(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
const LoggingContext_t *__thiscall yaSSL::DES_EDE::set_decryptKey(
        _DWORD *this,
        const LoggingContext_t *result,
        const LoggingContext_t *iv)
{
  CInterlockedIntT<unsigned int> *v3; // esi

  v3 = (CInterlockedIntT<unsigned int> *)(*(this + 1) + 440);
  TaoCrypt::DES_EDE3::SetKey(this: v3, key: (unsigned int)result, sz: 0x18u);
  v3[4].m_value = iv->m_ChannelID;
  v3[5].m_value = iv->m_Flags;
  return iv;
}

//------------------------------------------------------------------------------
// Address: 0x00424F50
// Name: public: virtual void yaSSL::DES_EDE::decrypt(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DES_EDE::decrypt(
        yaSSL::DES_EDE *this,
        unsigned __int8 *plain,
        const LoggingContext_t *cipher,
        unsigned int sz)
{
  (*(void (__thiscall **)(int, unsigned __int8 *, const LoggingContext_t *, unsigned int))(*(_DWORD *)(*((_DWORD *)this + 1) + 440)
                                                                                         + 4))(
    a1: *((_DWORD *)this + 1) + 440,
    a2: plain,
    a3: cipher,
    a4: sz);
}

//------------------------------------------------------------------------------
// Address: 0x00424F70
// Name: public: yaSSL::RC4::RC4(void)
// Source: json
//------------------------------------------------------------------------------
CLoggingSystem::LoggingChannel_t *__thiscall yaSSL::RC4::RC4(CLoggingSystem::LoggingChannel_t *this)
{
  this->m_ID = (int)&yaSSL::RC4::`vftable';
  this->m_Flags = (LoggingChannelFlags_t)operator new(sz: (const CSplitScreenAddedConVar *)this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424FA0
// Name: public: virtual yaSSL::RC4::~RC4(void)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *__thiscall yaSSL::RC4::~RC4(
        CLoggingSystem::LoggingChannel_t *this)
{
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *result; // eax

  this->m_ID = (int)&yaSSL::RC4::`vftable';
  result = yaSSL::ysDelete<unsigned char>(result: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *)this);
  this->m_ID = (int)&yaSSL::BulkCipher::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00424FC0
// Name: public: yaSSL::AES::AESImpl::AESImpl(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CCountedStringPoolBase<unsigned short>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> > *__userpurge yaSSL::AES::AESImpl::AESImpl@<eax>(
        CUtlVector<CCountedStringPoolBase<unsigned short>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> > *this@<ecx>,
        unsigned int ks,
        const CCountedStringPoolBase<unsigned short>::hash_item_t *a3)
{
  this->m_Memory.m_nGrowSize = (int)&this->m_pElements;
  this->m_Size = (int)this + 32;
  *((_DWORD *)this + 12) = 0;
  *((_DWORD *)this + 13) = 1;
  this->m_Memory.m_pMemory = (CCountedStringPoolBase<unsigned short>::hash_item_t *)&TaoCrypt::AES::`vftable';
  this->m_Memory.m_nAllocationCount = 16;
  *((_DWORD *)this + 76) = 16;
  *((_DWORD *)this + 77) = (char *)this + 316;
  *((_DWORD *)this + 87) = 1;
  *((_DWORD *)this + 88) = 1;
  *((_DWORD *)this + 78) = (char *)this + 332;
  *((_DWORD *)this + 75) = &TaoCrypt::AES::`vftable';
  *((_DWORD *)this + 150) = ks;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425030
// Name: public: yaSSL::AES::AES(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__userpurge yaSSL::AES::AES@<eax>(
        CSplitScreenAddedConVar *a1@<ecx>,
        ITypeComp *this,
        wchar_t *ks,
        unsigned int a4,
        unsigned __int16 a5,
        ITypeInfo **a6,
        tagDESCKIND *a7,
        tagBINDPTR *a8)
{
  CUtlVector<CCountedStringPoolBase<unsigned short>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> > *v9; // eax
  const CCountedStringPoolBase<unsigned short>::hash_item_t *v11; // [esp+0h] [ebp-4h]

  a1->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::AES::`vftable';
  v9 = (CUtlVector<CCountedStringPoolBase<unsigned short>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int> > *)operator new(sz: a1);
  if ( v9 != nullptr )
    a1->m_pNext = (ConCommandBase *)yaSSL::AES::AESImpl::AESImpl(this: v9, ks: (unsigned int)this, a3: v11);
  else
    a1->m_pNext = nullptr;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00425090
// Name: public: virtual void yaSSL::AES::set_encryptKey(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITypeInfo *__thiscall yaSSL::AES::set_encryptKey(
        CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> **this,
        const LoggingContext_t *result,
        const LoggingContext_t *iv)
{
  CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *v3; // esi
  ITypeInfo *m_Color; // eax

  v3 = *(this + 1);
  TaoCrypt::AES::SetKey(this: v3);
  v3[1].m_nAllocationCount = iv->m_ChannelID;
  v3[1].m_nGrowSize = iv->m_Flags;
  v3[2].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)iv->m_Severity;
  m_Color = (ITypeInfo *)iv->m_Color;
  v3[2].m_nAllocationCount = (int)m_Color;
  return m_Color;
}

//------------------------------------------------------------------------------
// Address: 0x004250D0
// Name: public: virtual void yaSSL::AES::set_decryptKey(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
ITypeInfo *__thiscall yaSSL::AES::set_decryptKey(
        _DWORD *this,
        const LoggingContext_t *result,
        const LoggingContext_t *iv)
{
  CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *v3; // esi
  ITypeInfo *m_Color; // eax

  v3 = (CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> *)(*(this + 1) + 300);
  TaoCrypt::AES::SetKey(this: v3);
  v3[1].m_nAllocationCount = iv->m_ChannelID;
  v3[1].m_nGrowSize = iv->m_Flags;
  v3[2].m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)iv->m_Severity;
  m_Color = (ITypeInfo *)iv->m_Color;
  v3[2].m_nAllocationCount = (int)m_Color;
  return m_Color;
}

//------------------------------------------------------------------------------
// Address: 0x00425110
// Name: public: virtual void yaSSL::AES::decrypt(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::AES::decrypt(
        yaSSL::AES *this,
        unsigned __int8 *plain,
        const LoggingContext_t *cipher,
        unsigned int sz)
{
  (*(void (__thiscall **)(int, unsigned __int8 *, const LoggingContext_t *, unsigned int))(*(_DWORD *)(*((_DWORD *)this + 1) + 300)
                                                                                         + 4))(
    a1: *((_DWORD *)this + 1) + 300,
    a2: plain,
    a3: cipher,
    a4: sz);
}

//------------------------------------------------------------------------------
// Address: 0x00425130
// Name: public: yaSSL::RandomPool::RandomPool(void)
// Source: json
//------------------------------------------------------------------------------
yaSSL::RandomPool *__thiscall yaSSL::RandomPool::RandomPool(yaSSL::RandomPool *this)
{
  TaoCrypt::RandomNumberGenerator *v2; // eax
  tagPROPVARIANT *v3; // edi

  v2 = (TaoCrypt::RandomNumberGenerator *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  v3 = (tagPROPVARIANT *)v2;
  if ( v2 != nullptr )
  {
    TaoCrypt::RandomNumberGenerator::RandomNumberGenerator(this: v2);
    *this = v3;
  }
  else
  {
    *this = nullptr;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425170
// Name: public: TaoCrypt::DSA_PrivateKey::~DSA_PrivateKey(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::DSA_PrivateKey::~DSA_PrivateKey(int this)
{
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 72));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 56));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 40));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 24));
  return TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 8));
}

//------------------------------------------------------------------------------
// Address: 0x004251D0
// Name: public: TaoCrypt::RSA_PrivateKey::~RSA_PrivateKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::RSA_PrivateKey::~RSA_PrivateKey(TaoCrypt::RSA_PrivateKey *this)
{
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)this + 10);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 104));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 88));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)this + 6);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 56));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 40));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)this + 2);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 8));
}

//------------------------------------------------------------------------------
// Address: 0x00425260
// Name: public: yaSSL::Integer::Integer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Integer::Integer(IMemAlloc *this)
{
  TaoCrypt::Integer *v2; // eax
  IMemAlloc_vtbl *v3; // edi

  v2 = (TaoCrypt::Integer *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  v3 = (IMemAlloc_vtbl *)v2;
  if ( v2 != nullptr )
  {
    TaoCrypt::Integer::Integer(this: v2);
    this->__vftable = v3;
  }
  else
  {
    this->__vftable = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004252A0
// Name: public: void yaSSL::Integer::assign(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::Integer::assign(IMemAlloc *this, unsigned __int16 num, unsigned __int16 sz)
{
  const char *v4; // eax
  const char *v6; // [esp+0h] [ebp-14h]
  CUtlSymbolTable::CStringPoolIndex v7; // [esp+4h] [ebp-10h] BYREF
  __int64 v8; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Integer(this: &v7, encodedInteger: num, byteCount: sz);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)this->__vftable, t: v4, a3: v6);
  return TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v8);
}

//------------------------------------------------------------------------------
// Address: 0x004252E0
// Name: public: yaSSL::DiffieHellman::DHImpl::DHImpl(struct yaSSL::DiffieHellman::DHImpl const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DiffieHellman::DHImpl::DHImpl(CFunctorCallback0 *this, CFunctorData *that)
{
  const CSplitScreenAddedConVar *v3; // ecx
  const CSplitScreenAddedConVar *v4; // ecx

  TaoCrypt::Integer::Integer((TaoCrypt::Integer *)this, a2: (const struct TaoCrypt::Integer *)that);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 4, a2: (const struct TaoCrypt::Integer *)&that[4]);
  *((CFunctorData *)this + 8) = that[8];
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 0;
  TaoCrypt::Integer::ByteCount();
  *((_DWORD *)this + 9) = operator new[](sz: v3);
  *((_DWORD *)this + 10) = operator new[](sz: v4);
  *((_DWORD *)this + 11) = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
}

//------------------------------------------------------------------------------
// Address: 0x00425360
// Name: public: yaSSL::DiffieHellman::DiffieHellman(unsigned char const __near *,unsigned int,unsigned char const __near *,unsigned int,unsigned char const __near *,unsigned int,class yaSSL::RandomPool const __near &)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::DiffieHellman::DiffieHellman(
        CSplitScreenAddedConVar *this,
        const unsigned __int8 *a2,
        unsigned __int16 a3,
        const unsigned __int8 *encodedInteger,
        unsigned __int16 byteCount,
        unsigned __int8 *src,
        unsigned int count,
        const struct yaSSL::RandomPool *a8)
{
  TaoCrypt::Integer *v9; // eax
  TaoCrypt::Integer *v10; // edi
  int v11; // ebx
  const char *v12; // eax
  const char *v13; // ebx
  CSplitScreenAddedConVar_vtbl *v14; // edi
  const char *v15; // eax
  const char *v17; // [esp+0h] [ebp-2Ch]
  const char *v18; // [esp+0h] [ebp-2Ch]
  CUtlSymbolTable::CStringPoolIndex v19; // [esp+Ch] [ebp-20h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v20; // [esp+14h] [ebp-18h] BYREF
  __int64 v21; // [esp+24h] [ebp-8h] BYREF

  v9 = (TaoCrypt::Integer *)operator new(sz: this);
  v10 = v9;
  if ( v9 != nullptr )
  {
    v11 = *(_DWORD *)a8;
    TaoCrypt::Integer::Integer(this: v9);
    TaoCrypt::Integer::Integer(this: v10 + 4);
    v10[8].m_stackLevel = v11;
    v10[9].m_stackLevel = 0;
    v10[10].m_stackLevel = 0;
    v10[11].m_stackLevel = 0;
  }
  else
  {
    v10 = nullptr;
  }
  this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)v10;
  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&v20.m_iRefs,
    (unsigned __int16)encodedInteger,
    byteCount);
  v13 = v12;
  TaoCrypt::Integer::Integer(this: &v19, encodedInteger: (unsigned __int16)a2, byteCount: a3);
  v14 = this->ConVar::ConCommandBase::__vftable;
  TaoCrypt::Integer::operator=(
    this: (CInternalFileSystemPassThru<IFileSystem> *)this->ConVar::ConCommandBase::__vftable,
    t: v15,
    a3: v17);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&v14->RemoveFlags, t: v13, a3: v18);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v20);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v21);
  this->GetDLLIdentifier = (int (__thiscall *)(struct CSplitScreenAddedConVar *))operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  memcpy(dst: (unsigned __int8 *)this->GetDLLIdentifier, src, count);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425450
// Name: public: yaSSL::DiffieHellman::DiffieHellman(class yaSSL::Integer const __near &,class yaSSL::Integer const __near &,class yaSSL::RandomPool const __near &)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::DiffieHellman::DiffieHellman(
        CSplitScreenAddedConVar *this,
        const char **a2,
        const char **a3,
        const struct yaSSL::RandomPool *a4)
{
  TaoCrypt::Integer *v5; // eax
  TaoCrypt::Integer *v6; // edi
  int v7; // ebx
  const char *v8; // ebx
  CSplitScreenAddedConVar_vtbl *v9; // ebx
  const CSplitScreenAddedConVar *v10; // ecx
  const CSplitScreenAddedConVar *v11; // ecx
  const char *v13; // [esp+0h] [ebp-Ch]
  const char *v14; // [esp+0h] [ebp-Ch]

  v5 = (TaoCrypt::Integer *)operator new(sz: this);
  v6 = v5;
  if ( v5 != nullptr )
  {
    v7 = *(_DWORD *)a4;
    TaoCrypt::Integer::Integer(this: v5);
    TaoCrypt::Integer::Integer(this: v6 + 4);
    v6[8].m_stackLevel = v7;
    v6[9].m_stackLevel = 0;
    v6[10].m_stackLevel = 0;
    v6[11].m_stackLevel = 0;
  }
  else
  {
    v6 = nullptr;
  }
  this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)v6;
  v8 = *a3;
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)v6, t: *a2, a3: v13);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&v6[4], t: v8, a3: v14);
  TaoCrypt::Integer::ByteCount();
  v9 = this->ConVar::ConCommandBase::__vftable;
  v9->GetDLLIdentifier = (int (__thiscall *)(struct CSplitScreenAddedConVar *))operator new[](sz: v10);
  v9->Create = (void (__thiscall *)(struct CSplitScreenAddedConVar *, const char *, const char *, int))operator new[](sz: v11);
  v9->Init = (void (__thiscall *)(struct CSplitScreenAddedConVar *))operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  TaoCrypt::DH::GenerateKeyPair(
    this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)this->ConVar::ConCommandBase::__vftable,
    rng: (int)this->IsRegistered,
    priv: (const unsigned __int16 *)this->Create);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425520
// Name: public: yaSSL::DiffieHellman::DiffieHellman(class yaSSL::DiffieHellman const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DiffieHellman::DiffieHellman(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *this,
        CFunctorData **that)
{
  CFunctorCallback0 *v3; // eax
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *v4; // eax

  v3 = (CFunctorCallback0 *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  if ( v3 != nullptr )
    yaSSL::DiffieHellman::DHImpl::DHImpl(this: v3, that: *that);
  else
    v4 = nullptr;
  this->index = (int)v4;
  TaoCrypt::DH::GenerateKeyPair(this: v4, rng: v4[1].m_Size, priv: v4[2].m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x00425570
// Name: public: void yaSSL::DiffieHellman::set_sizes(int __near &,int __near &,int __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DiffieHellman::set_sizes(const struct TaoCrypt::Integer **this, int *a2, int *a3, int *a4)
{
  TaoCrypt::Integer v5; // [esp+4h] [ebp-20h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v6; // [esp+Ch] [ebp-18h] BYREF
  __int64 v7; // [esp+1Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v6.m_iRefs, a2: *this);
  TaoCrypt::Integer::Integer(this: &v5, a2: *this + 4);
  *a2 = TaoCrypt::Integer::ByteCount();
  *a3 = TaoCrypt::Integer::ByteCount();
  *a4 = TaoCrypt::Integer::ByteCount();
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v6);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7);
}

//------------------------------------------------------------------------------
// Address: 0x004255F0
// Name: public: void yaSSL::DiffieHellman::get_parms(unsigned char __near *,unsigned char __near *,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DiffieHellman::get_parms(
        const struct TaoCrypt::Integer **this,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        unsigned __int8 *dst)
{
  int v5; // eax
  int v6; // eax
  unsigned int v7; // eax
  TaoCrypt::Integer v8; // [esp+4h] [ebp-20h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v9; // [esp+Ch] [ebp-18h] BYREF
  __int64 v10; // [esp+1Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v9.m_iRefs, a2: *this);
  TaoCrypt::Integer::Integer(this: &v8, a2: *this + 4);
  v5 = TaoCrypt::Integer::ByteCount();
  TaoCrypt::Integer::Encode(a1: &v9.m_iRefs, a2, a3: v5, a4: 0);
  v6 = TaoCrypt::Integer::ByteCount();
  TaoCrypt::Integer::Encode(a1: &v8, a2: a3, a3: v6, a4: 0);
  v7 = TaoCrypt::Integer::ByteCount();
  memcpy(dst, src: (unsigned __int8 *)(*this)[9].m_stackLevel, count: v7);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v9);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v10);
}

//------------------------------------------------------------------------------
// Address: 0x00425690
// Name: public: void TaoCrypt::HMAC<class TaoCrypt::RIPEMD160>::Update(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Update(
        CFileSystemPassThru *this,
        const LoggingContext_t *msg,
        unsigned int length,
        int a4)
{
  if ( LOBYTE(this->m_pFileSystemPassThru) == 0 )
    TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::KeyInnerHash(this);
  return (*(bool (__thiscall **)(CFileSystemPassThru *, const LoggingContext_t *, unsigned int, int))(*((_DWORD *)this + 4) + 4))(
           a1: this + 1,
           a2: msg,
           a3: length,
           a4);
}

//------------------------------------------------------------------------------
// Address: 0x004256B0
// Name: public: void TaoCrypt::HMAC<class TaoCrypt::MD5>::Final(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::HMAC<TaoCrypt::MD5>::Final(CFileSystemPassThru *this@<ecx>, char *hash, int a3, int a4)
{
  if ( LOBYTE(this->m_pFileSystemPassThru) == 0 )
    TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::KeyInnerHash(this);
  (*(void (__thiscall **)(CFileSystemPassThru *, IBaseFileSystem *))(*((_DWORD *)this + 4) + 8))(
    a1: this + 1,
    a2: this->m_pBaseFileSystemPassThru);
  (*(void (__thiscall **)(CFileSystemPassThru *, IBaseFileSystem_vtbl *, int))(*((_DWORD *)this + 4) + 4))(
    a1: this + 1,
    a2: this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable,
    a3: 64);
  (*(void (__thiscall **)(CFileSystemPassThru *, IBaseFileSystem *, int))(*((_DWORD *)this + 4) + 4))(
    a1: this + 1,
    a2: this->m_pBaseFileSystemPassThru,
    a3: 16);
  (*(void (__thiscall **)(CFileSystemPassThru *, char *))(*((_DWORD *)this + 4) + 8))(a1: this + 1, a2: hash);
  LOBYTE(this->m_pFileSystemPassThru) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00425710
// Name: public: void TaoCrypt::HMAC<class TaoCrypt::SHA>::Final(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::HMAC<TaoCrypt::SHA>::Final(int this, unsigned __int8 *hash)
{
  int result; // eax

  if ( *(_BYTE *)(this + 12) == 0 )
    TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::KeyInnerHash((CFileSystemPassThru *)this);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)(this + 16) + 8))(a1: this + 16, a2: *(_DWORD *)(this + 8));
  (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)(this + 16) + 4))(
    a1: this + 16,
    a2: *(_DWORD *)(this + 4),
    a3: 64);
  (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)(this + 16) + 4))(
    a1: this + 16,
    a2: *(_DWORD *)(this + 8),
    a3: 20);
  result = (*(int (__thiscall **)(int, unsigned __int8 *))(*(_DWORD *)(this + 16) + 8))(a1: this + 16, a2: hash);
  *(_BYTE *)(this + 12) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004257E0
// Name: public: yaSSL::HMAC_MD5::HMAC_MD5Impl::HMAC_MD5Impl(void)
// Source: json
//------------------------------------------------------------------------------
CFileSystemPassThru *__thiscall yaSSL::HMAC_MD5::HMAC_MD5Impl::HMAC_MD5Impl(CFileSystemPassThru *this)
{
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v2; // edi

  this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)(this + 12);
  v2 = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)(this + 1);
  this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystemPassThru_vtbl *)(this + 8);
  this->m_pBaseFileSystemPassThru = (IBaseFileSystem *)(this + 16);
  TaoCrypt::HASHwithTransform::HASHwithTransform(
    this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)(this + 1),
    digSz: 4);
  v2->m_Memory.m_pMemory = (CUtlString *)&TaoCrypt::MD5::`vftable';
  TaoCrypt::MD5::Init(this: v2);
  TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425830
// Name: public: yaSSL::HMAC_MD5::HMAC_MD5(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::HMAC_MD5::HMAC_MD5(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *secret,
        unsigned int len)
{
  CFileSystemPassThru *v4; // eax
  CFileSystemPassThru *v5; // eax

  this->m_Memory.m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)&yaSSL::HMAC_MD5::`vftable';
  v4 = (CFileSystemPassThru *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  if ( v4 != nullptr )
    v5 = yaSSL::HMAC_MD5::HMAC_MD5Impl::HMAC_MD5Impl(this: v4);
  else
    v5 = nullptr;
  this->m_Memory.m_nAllocationCount = (int)v5;
  TaoCrypt::HMAC<TaoCrypt::MD5>::SetKey(this: v5, src: (unsigned __int8 *)secret, count: len);
}

//------------------------------------------------------------------------------
// Address: 0x00425880
// Name: public: virtual void yaSSL::HMAC_MD5::get_digest(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004258B0
// Name: public: virtual void yaSSL::HMAC_MD5::get_digest(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::HMAC_MD5::get_digest(yaSSL::HMAC_MD5 *this@<ecx>, char *a2, int a3, int a4)
{
  TaoCrypt::HMAC<TaoCrypt::MD5>::Final(this: (CFileSystemPassThru *)this->m_Memory.m_nAllocationCount, hash: a2, a3, a4);
}

//------------------------------------------------------------------------------
// Address: 0x004258C0
// Name: public: virtual void yaSSL::HMAC_MD5::update(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::HMAC_MD5::update(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        const LoggingContext_t *in,
        unsigned int sz,
        int a4)
{
  return TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Update(
           this: (CFileSystemPassThru *)this->m_Memory.m_nAllocationCount,
           msg: in,
           length: sz,
           a4);
}

//------------------------------------------------------------------------------
// Address: 0x004258D0
// Name: public: yaSSL::HMAC_SHA::HMAC_SHAImpl::HMAC_SHAImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::HMAC_SHA::HMAC_SHAImpl::HMAC_SHAImpl(CFileSystemPassThru *this)
{
  std::exception *v2; // edi
  const std::exception *v3; // [esp+0h] [ebp-8h]

  this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)(this + 12);
  v2 = (std::exception *)(this + 1);
  this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystemPassThru_vtbl *)(this + 8);
  this->m_pBaseFileSystemPassThru = (IBaseFileSystem *)(this + 16);
  TaoCrypt::HASHwithTransform::HASHwithTransform(
    this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)(this + 1),
    digSz: 5);
  v2->__vftable = (std::exception_vtbl *)&TaoCrypt::SHA::`vftable';
  TaoCrypt::RIPEMD160::Init(this: v2, a2: v3);
  TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Init(this);
}

//------------------------------------------------------------------------------
// Address: 0x00425920
// Name: public: yaSSL::HMAC_SHA::HMAC_SHA(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *__thiscall yaSSL::HMAC_SHA::HMAC_SHA(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        unsigned __int8 *secret,
        unsigned int len)
{
  CFileSystemPassThru *v4; // eax
  CFileSystemPassThru *v5; // eax

  this->m_Memory.m_pMemory = (CUtlVector<int,CUtlMemory<int,int> > *)&yaSSL::HMAC_SHA::`vftable';
  v4 = (CFileSystemPassThru *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  if ( v4 != nullptr )
    yaSSL::HMAC_SHA::HMAC_SHAImpl::HMAC_SHAImpl(this: v4);
  else
    v5 = nullptr;
  this->m_Memory.m_nAllocationCount = (int)v5;
  TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::SetKey(this: v5, key: secret, length: len);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425970
// Name: public: virtual void yaSSL::HMAC_SHA::get_digest(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<int,CUtlMemory<int,int> > *__thiscall yaSSL::HMAC_SHA::get_digest(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        unsigned __int8 *out)
{
  return (CUtlVector<int,CUtlMemory<int,int> > *)TaoCrypt::HMAC<TaoCrypt::SHA>::Final(
                                                   this: this->m_Memory.m_nAllocationCount,
                                                   hash: out);
}

//------------------------------------------------------------------------------
// Address: 0x00425980
// Name: public: yaSSL::HMAC_RMD::HMAC_RMDImpl::HMAC_RMDImpl(void)
// Source: json
//------------------------------------------------------------------------------
CFileSystemPassThru *__thiscall yaSSL::HMAC_RMD::HMAC_RMDImpl::HMAC_RMDImpl(CFileSystemPassThru *this)
{
  std::exception *v2; // edi
  const std::exception *v4; // [esp+0h] [ebp-8h]

  this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)(this + 12);
  v2 = (std::exception *)(this + 1);
  this->CInternalFileSystemPassThru<IFileSystem>::IFileSystem::IAppSystem::__vftable = (CFileSystemPassThru_vtbl *)(this + 8);
  this->m_pBaseFileSystemPassThru = (IBaseFileSystem *)(this + 16);
  TaoCrypt::HASHwithTransform::HASHwithTransform(
    this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)(this + 1),
    digSz: 5);
  v2->__vftable = (std::exception_vtbl *)&TaoCrypt::RIPEMD160::`vftable';
  TaoCrypt::RIPEMD160::Init(this: v2, a2: v4);
  TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Init(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004259D0
// Name: public: yaSSL::HMAC_RMD::HMAC_RMD(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<int,CUtlMemory<int,int> > *__thiscall yaSSL::HMAC_RMD::HMAC_RMD(
        const CUtlVector<int,CUtlMemory<int,int> > *this,
        CUtlVector<int,CUtlMemory<int,int> > *secret,
        unsigned int len)
{
  CFileSystemPassThru *v4; // eax
  CFileSystemPassThru *v5; // eax

  this->m_Memory.m_pMemory = (int *)&yaSSL::HMAC_RMD::`vftable';
  v4 = (CFileSystemPassThru *)operator new(sz: (const CSplitScreenAddedConVar *)this);
  if ( v4 != nullptr )
    v5 = yaSSL::HMAC_RMD::HMAC_RMDImpl::HMAC_RMDImpl(this: v4);
  else
    v5 = nullptr;
  this->m_Memory.m_nAllocationCount = (int)v5;
  TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::SetKey(this: v5, key: (unsigned __int8 *)secret, length: len);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425A20
// Name: public: virtual void yaSSL::HMAC_RMD::get_digest(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall yaSSL::HMAC_RMD::get_digest(
        CUtlVector<CUtlVector<int,CUtlMemory<int,int> >,CUtlMemory<CUtlVector<int,CUtlMemory<int,int> >,int> > *this,
        const LoggingContext_t *out,
        const LoggingContext_t *in,
        unsigned int sz)
{
  int v5; // [esp-4h] [ebp-8h]

  TaoCrypt::HMAC<TaoCrypt::RIPEMD160>::Update(
    this: (CFileSystemPassThru *)this->m_Memory.m_nAllocationCount,
    msg: out,
    length: (unsigned int)in,
    a4: v5);
  TaoCrypt::HMAC<TaoCrypt::SHA>::Final(this: this->m_Memory.m_nAllocationCount, hash: (unsigned __int8 *)out);
}

//------------------------------------------------------------------------------
// Address: 0x00425A50
// Name: public: yaSSL::DES::DES(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::DES::DES(CSplitScreenAddedConVar *this)
{
  CFileSystemPassThru *v2; // eax

  this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::DES::`vftable';
  v2 = (CFileSystemPassThru *)operator new(sz: this);
  if ( v2 != nullptr )
    this->m_pNext = (ConCommandBase *)yaSSL::DES::DESImpl::DESImpl(this: v2);
  else
    this->m_pNext = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425A90
// Name: public: virtual unsigned int yaSSL::DES::get_blockSize(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::DES::get_blockSize()
{
  return 8;
}

//------------------------------------------------------------------------------
// Address: 0x00425AA0
// Name: public: yaSSL::DES_EDE::DES_EDE(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::DES_EDE::DES_EDE(CSplitScreenAddedConVar *this)
{
  yaSSL::DES_EDE::DES_EDEImpl *v2; // eax

  this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::DES_EDE::`vftable';
  v2 = (yaSSL::DES_EDE::DES_EDEImpl *)operator new(sz: this);
  if ( v2 != nullptr )
    this->m_pNext = (ConCommandBase *)yaSSL::DES_EDE::DES_EDEImpl::DES_EDEImpl(this: v2);
  else
    this->m_pNext = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425AE0
// Name: public: virtual int yaSSL::DES_EDE::get_keySize(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::DES_EDE::get_keySize()
{
  return 24;
}

//------------------------------------------------------------------------------
// Address: 0x00425B00
// Name: public: yaSSL::DSS::DSSImpl::DSSImpl(void)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall yaSSL::DSS::DSSImpl::DSSImpl(TaoCrypt::Integer *this)
{
  TaoCrypt::Integer::Integer(this);
  TaoCrypt::Integer::Integer(this: this + 4);
  TaoCrypt::Integer::Integer(this: this + 8);
  TaoCrypt::Integer::Integer(this: this + 12);
  TaoCrypt::Integer::Integer(this: this + 16);
  TaoCrypt::Integer::Integer(this: this + 20);
  TaoCrypt::Integer::Integer(this: this + 24);
  TaoCrypt::Integer::Integer(this: this + 28);
  TaoCrypt::Integer::Integer(this: this + 32);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00425B50
// Name: public: virtual void yaSSL::DSS::sign(unsigned char __near *,unsigned char const __near *,unsigned int,class yaSSL::RandomPool const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::DSS::sign(
        CThread *this,
        unsigned __int8 *sig,
        const LoggingContext_t *sha_digest,
        unsigned int __formal,
        int random)
{
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> v6; // [esp+0h] [ebp-24h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v7; // [esp+Ch] [ebp-18h] BYREF
  __int64 v8; // [esp+1Ch] [ebp-8h] BYREF

  TaoCrypt::DSA_Signer::DSA_Signer(this: (CFunctor *)&v6);
  TaoCrypt::DSA_Signer::Sign(this: &v6);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v8);
  return TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v7);
}

//------------------------------------------------------------------------------
// Address: 0x00425BB0
// Name: public: virtual bool yaSSL::DSS::verify(unsigned char const __near *,unsigned int,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall yaSSL::DSS::verify(
        yaSSL::DSS *this,
        CFunctor *sha_digest,
        unsigned int a3,
        const unsigned __int8 *a4,
        unsigned int a5)
{
  unsigned __int8 v5; // bl
  CFunctor v7; // [esp+4h] [ebp-24h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v8; // [esp+10h] [ebp-18h] BYREF
  __int64 v9; // [esp+20h] [ebp-8h] BYREF

  TaoCrypt::DSA_Signer::DSA_Signer(this: &v7);
  v5 = (unsigned __int8)TaoCrypt::DSA_Verifier::Verify(this: &v7, sha_digest);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v9);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v8);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x00425C10
// Name: public: yaSSL::RSA::RSAImpl::RSAImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RSA::RSAImpl::RSAImpl(CCountedStringPoolBase<unsigned short> *this)
{
  TaoCrypt::Integer::Integer((TaoCrypt::Integer *)this);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&this->m_HashTable.m_Size);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&this->m_Elements.m_Memory.m_nGrowSize);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&this->m_caseSensitivity);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 16);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 20);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 24);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 28);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 32);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 36);
}

//------------------------------------------------------------------------------
// Address: 0x00425C90
// Name: void yaSSL::ysDelete<struct yaSSL::HMAC_SHA::HMAC_SHAImpl>(struct yaSSL::HMAC_SHA::HMAC_SHAImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::HMAC_SHA::HMAC_SHAImpl>(int a1)
{
  if ( a1 != 0 )
    *(_DWORD *)(a1 + 16) = &TaoCrypt::HASH::`vftable';
  operator delete(ptr: (KeyValues *)*(unsigned __int8 *)yaSSL::ys);
}

//------------------------------------------------------------------------------
// Address: 0x00425CF0
// Name: void yaSSL::ysDelete<struct yaSSL::DES_EDE::DES_EDEImpl>(struct yaSSL::DES_EDE::DES_EDEImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::DES_EDE::DES_EDEImpl>(_DWORD *ptr)
{
  if ( ptr != nullptr )
  {
    ptr[110] = &TaoCrypt::Mode_BASE::`vftable';
    *ptr = &TaoCrypt::Mode_BASE::`vftable';
  }
  operator delete(ptr: (KeyValues *)*(unsigned __int8 *)yaSSL::ys);
}

//------------------------------------------------------------------------------
// Address: 0x00425D50
// Name: void yaSSL::ysDelete<struct yaSSL::RandomPool::RandomImpl>(struct yaSSL::RandomPool::RandomImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::RandomPool::RandomImpl>(tagCABSTRBLOB ptr)
{
  KeyValues *v1; // ecx

  if ( ptr.cElems != 0 )
    TaoCrypt::OS_Seed::~OS_Seed(this: (TaoCrypt::OS_Seed *)ptr.cElems);
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00425D80
// Name: void yaSSL::ysDelete<struct yaSSL::DiffieHellman::DHImpl>(struct yaSSL::DiffieHellman::DHImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::DiffieHellman::DHImpl>(CDatamapFieldSizeDeducer<17>::<unnamed_tag> ptr)
{
  void **v1; // [esp-8h] [ebp-Ch]
  void **v2; // [esp-4h] [ebp-8h]
  void **v3; // [esp+0h] [ebp-4h]

  if ( ptr != 0 )
  {
    yaSSL::ysArrayDelete<unsigned char>(ptr: *(void **)(ptr + 44), a2: v3);
    yaSSL::ysArrayDelete<unsigned char>(ptr: *(void **)(ptr + 40), a2: v2);
    yaSSL::ysArrayDelete<unsigned char>(ptr: *(void **)(ptr + 36), a2: v1);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(ptr + 24));
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(ptr + 8));
  }
  operator delete(ptr: (KeyValues *)*(unsigned __int8 *)yaSSL::ys);
}

//------------------------------------------------------------------------------
// Address: 0x00425DE0
// Name: public: virtual yaSSL::MD5::~MD5(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::MD5::~MD5(yaSSL::MD5 *this)
{
  const CUtlEnvelope<char const *> *m_nAllocationCount; // [esp-4h] [ebp-8h]

  m_nAllocationCount = (const CUtlEnvelope<char const *> *)this->m_Memory.m_nAllocationCount;
  this->m_Memory.m_pMemory = (KeyValues **)&yaSSL::MD5::`vftable';
  yaSSL::ysDelete<yaSSL::SHA::SHAImpl>(result: m_nAllocationCount);
  this->m_Memory.m_pMemory = (KeyValues **)&yaSSL::Digest::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00425E00
// Name: public: virtual yaSSL::SHA::~SHA(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SHA::~SHA(Vector2D *this)
{
  float y; // [esp-4h] [ebp-8h]

  y = this->y;
  LODWORD(this->x) = &yaSSL::SHA::`vftable';
  yaSSL::ysDelete<yaSSL::SHA::SHAImpl>(result: (const CUtlEnvelope<char const *> *)LODWORD(y));
  LODWORD(this->x) = &yaSSL::Digest::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00425E20
// Name: public: virtual yaSSL::RMD::~RMD(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlEnvelope<char const *> *__thiscall yaSSL::RMD::~RMD(const CUtlEnvelope<char const *> **this)
{
  const CUtlEnvelope<char const *> *v2; // eax
  const CUtlEnvelope<char const *> *v3; // [esp-4h] [ebp-8h]

  v3 = *(this + 1);
  *this = (const CUtlEnvelope<char const *> *)&yaSSL::RMD::`vftable';
  v2 = yaSSL::ysDelete<yaSSL::SHA::SHAImpl>(result: v3);
  *this = (const CUtlEnvelope<char const *> *)&yaSSL::Digest::`vftable';
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00425E40
// Name: public: virtual yaSSL::HMAC_MD5::~HMAC_MD5(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::HMAC_MD5::~HMAC_MD5(yaSSL::HMAC_MD5 *this)
{
  int m_nAllocationCount; // [esp-4h] [ebp-8h]

  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  this->m_Memory.m_pMemory = (int *)&yaSSL::HMAC_MD5::`vftable';
  yaSSL::ysDelete<yaSSL::HMAC_SHA::HMAC_SHAImpl>(a1: m_nAllocationCount);
  this->m_Memory.m_pMemory = (int *)&yaSSL::Digest::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00425E60
// Name: public: virtual yaSSL::HMAC_SHA::~HMAC_SHA(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::HMAC_SHA::~HMAC_SHA(int *this)
{
  int v2; // [esp-4h] [ebp-8h]

  v2 = *(this + 1);
  *this = (int)&yaSSL::HMAC_SHA::`vftable';
  yaSSL::ysDelete<yaSSL::HMAC_SHA::HMAC_SHAImpl>(a1: v2);
  *this = (int)&yaSSL::Digest::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00425E80
// Name: public: virtual yaSSL::HMAC_RMD::~HMAC_RMD(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::HMAC_RMD::~HMAC_RMD(yaSSL::HMAC_RMD *this)
{
  unsigned int nNextElement; // [esp-4h] [ebp-8h]

  nNextElement = this->nNextElement;
  this->pString = (char *)&yaSSL::HMAC_RMD::`vftable';
  yaSSL::ysDelete<yaSSL::HMAC_SHA::HMAC_SHAImpl>(a1: nNextElement);
  this->pString = (char *)&yaSSL::Digest::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00425EA0
// Name: public: virtual yaSSL::DES::~DES(void)
// Source: json
//------------------------------------------------------------------------------
ILoggingListener *__thiscall yaSSL::DES::~DES(_DWORD *this)
{
  ILoggingListener *v2; // eax
  int v3; // [esp-4h] [ebp-8h]

  v3 = *(this + 1);
  *this = &yaSSL::DES::`vftable';
  v2 = (ILoggingListener *)yaSSL::ysDelete<yaSSL::DES::DESImpl>(a1: v3);
  *this = &yaSSL::BulkCipher::`vftable';
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00425EC0
// Name: public: virtual yaSSL::DES_EDE::~DES_EDE(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DES_EDE::~DES_EDE(_DWORD *this)
{
  _DWORD *v2; // [esp-4h] [ebp-8h]

  v2 = (_DWORD *)*(this + 1);
  *this = &yaSSL::DES_EDE::`vftable';
  yaSSL::ysDelete<yaSSL::DES_EDE::DES_EDEImpl>(ptr: v2);
  *this = &yaSSL::BulkCipher::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00425EE0
// Name: public: virtual yaSSL::AES::~AES(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::AES::~AES(yaSSL::AES *this)
{
  int v2; // [esp-4h] [ebp-8h]

  v2 = *((_DWORD *)this + 1);
  *(_DWORD *)this = &yaSSL::AES::`vftable';
  yaSSL::ysDelete<yaSSL::AES::AESImpl>(ptr: this, a2: v2);
  *(_DWORD *)this = &yaSSL::BulkCipher::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00425F00
// Name: public: yaSSL::RandomPool::~RandomPool(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00425F10
// Name: public: void yaSSL::DSS::DSSImpl::SetPublic(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DSS::DSSImpl::SetPublic(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this,
        const LoggingContext_t *key,
        IConVar *sz)
{
  CSplitScreenAddedConVar *v3; // eax
  ConVar *m_pConVarState; // esi
  void **v6; // [esp-Ch] [ebp-24h]
  int v7; // [esp+0h] [ebp-18h]
  ConVarRef source; // [esp+4h] [ebp-14h] BYREF
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v3 = (CSplitScreenAddedConVar *)sz;
  source.m_pConVar = sz;
  if ( sz != nullptr )
    v3 = operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc);
  source.m_pConVarState = v3;
  memcpy(dst: (unsigned __int8 *)v3, src: (unsigned __int8 *)key, count: (unsigned int)source.m_pConVar);
  v9 = 0;
  v10 = 0;
  TaoCrypt::DSA_PublicKey::Initialize(this, (int)&source, decoder: v7);
  m_pConVarState = source.m_pConVarState;
  memset(dst: (unsigned __int8 *)source.m_pConVarState, value: 0, count: (unsigned int)source.m_pConVar);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: (void *)m_pConVarState, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00425F90
// Name: public: void yaSSL::DSS::DSSImpl::SetPrivate(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DSS::DSSImpl::SetPrivate(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this,
        const LoggingContext_t *key,
        unsigned __int8 *sz)
{
  unsigned __int8 *v3; // eax
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v5; // eax
  void **v6; // [esp-Ch] [ebp-68h]
  unsigned __int8 *source_4; // [esp+Ch] [ebp-50h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v8; // [esp+1Ch] [ebp-40h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v9; // [esp+34h] [ebp-28h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v10; // [esp+44h] [ebp-18h] BYREF
  __int64 v11; // [esp+54h] [ebp-8h] BYREF

  v3 = sz;
  if ( sz != nullptr )
    v3 = (unsigned __int8 *)operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc);
  source_4 = v3;
  memcpy(dst: v3, src: (unsigned __int8 *)key, count: (unsigned int)sz);
  TaoCrypt::DSA_PrivateKey::Initialize(this: (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)((char *)this + 64));
  TaoCrypt::DSA_PublicKey::DSA_PublicKey(
    this: &v8,
    other: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)((char *)this + 64));
  TaoCrypt::DSA_PublicKey::operator=(this, other: v5);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v11);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v10);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v9);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v8.m_Memory.m_nGrowSize);
  memset(dst: source_4, value: 0, count: (unsigned int)sz);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: source_4, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00426070
// Name: public: yaSSL::DSS::DSS(unsigned char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::DSS::DSS(
        CSplitScreenAddedConVar *this,
        const LoggingContext_t *result,
        IConVar *sz,
        bool publicKey)
{
  TaoCrypt::Integer *v5; // eax
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *v6; // ecx

  this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::DSS::`vftable';
  v5 = (TaoCrypt::Integer *)operator new(sz: this);
  if ( v5 != nullptr )
    v6 = (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)yaSSL::DSS::DSSImpl::DSSImpl(this: v5);
  else
    v6 = nullptr;
  this->m_pNext = (ConCommandBase *)v6;
  if ( publicKey )
    yaSSL::DSS::DSSImpl::SetPublic(this: v6, key: result, sz);
  else
    yaSSL::DSS::DSSImpl::SetPrivate(this: v6, key: result, (unsigned __int8 *)sz);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004260D0
// Name: public: void yaSSL::RSA::RSAImpl::SetPublic(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RSA::RSAImpl::SetPublic(yaSSL::RSA::RSAImpl *this, unsigned __int8 *key, IConVar *sz)
{
  CSplitScreenAddedConVar *v3; // eax
  ConVar *m_pConVarState; // esi
  void **v5; // [esp-Ch] [ebp-24h]
  int v6; // [esp+0h] [ebp-18h]
  ConVarRef source; // [esp+4h] [ebp-14h] BYREF
  int v8; // [esp+10h] [ebp-8h]
  int v9; // [esp+14h] [ebp-4h]

  v3 = (CSplitScreenAddedConVar *)sz;
  source.m_pConVar = sz;
  if ( sz != nullptr )
    v3 = operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc);
  source.m_pConVarState = v3;
  memcpy(dst: (unsigned __int8 *)v3, src: key, count: (unsigned int)source.m_pConVar);
  v8 = 0;
  v9 = 0;
  TaoCrypt::RSA_PublicKey::Initialize((int)&source, a2: v6);
  m_pConVarState = source.m_pConVarState;
  memset(dst: (unsigned __int8 *)source.m_pConVarState, value: 0, count: (unsigned int)source.m_pConVar);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: (void *)m_pConVarState, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00426150
// Name: public: void yaSSL::RSA::RSAImpl::SetPrivate(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RSA::RSAImpl::SetPrivate(TaoCrypt::Integer *this, const LoggingContext_t *key, IConVar *sz)
{
  CSplitScreenAddedConVar *v3; // eax
  ConVar *m_pConVarState; // esi
  void **v6; // [esp-Ch] [ebp-48h]
  ConVarRef source; // [esp+8h] [ebp-34h] BYREF
  int v8; // [esp+14h] [ebp-28h]
  int v9; // [esp+18h] [ebp-24h]
  TaoCrypt::Integer v10; // [esp+1Ch] [ebp-20h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v11; // [esp+24h] [ebp-18h] BYREF
  __int64 v12; // [esp+34h] [ebp-8h] BYREF

  v3 = (CSplitScreenAddedConVar *)sz;
  source.m_pConVar = sz;
  if ( sz != nullptr )
    v3 = operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc);
  source.m_pConVarState = v3;
  memcpy(dst: (unsigned __int8 *)v3, src: (unsigned __int8 *)key, count: (unsigned int)source.m_pConVar);
  v8 = 0;
  v9 = 0;
  TaoCrypt::RSA_PrivateKey::Initialize(this: (CInternalFileSystemPassThru<IFileSystem> *)(this + 8), a2: &source);
  TaoCrypt::Integer::Integer(this: &v10, a2: this + 8);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v11.m_iRefs, a2: this + 12);
  TaoCrypt::RSA_PublicKey::operator=(this, a2: &v10);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v12);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v11);
  m_pConVarState = source.m_pConVarState;
  memset(dst: (unsigned __int8 *)source.m_pConVarState, value: 0, count: (unsigned int)source.m_pConVar);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: (void *)m_pConVarState, a2: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00426220
// Name: public: yaSSL::RSA::RSA(unsigned char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::RSA::RSA(
        CSplitScreenAddedConVar *this,
        unsigned __int8 *key,
        IConVar *sz,
        bool a4)
{
  CCountedStringPoolBase<unsigned short> *v5; // eax
  yaSSL::RSA::RSAImpl *v6; // eax
  yaSSL::RSA::RSAImpl *v7; // ecx

  this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::RSA::`vftable';
  v5 = (CCountedStringPoolBase<unsigned short> *)operator new(sz: this);
  if ( v5 != nullptr )
  {
    yaSSL::RSA::RSAImpl::RSAImpl(this: v5);
    v7 = v6;
  }
  else
  {
    v7 = nullptr;
  }
  this->m_pNext = (ConCommandBase *)v7;
  if ( a4 )
    yaSSL::RSA::RSAImpl::SetPublic(this: v7, key, sz);
  else
    yaSSL::RSA::RSAImpl::SetPrivate(this: (TaoCrypt::Integer *)v7, (const LoggingContext_t *)key, sz);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00426280
// Name: public: yaSSL::DiffieHellman::~DiffieHellman(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DiffieHellman::~DiffieHellman(CDatamapFieldSizeDeducer<17>::<unnamed_tag> *this)
{
  yaSSL::ysDelete<yaSSL::DiffieHellman::DHImpl>(ptr: *this);
}

//------------------------------------------------------------------------------
// Address: 0x00426290
// Name: void yaSSL::ysDelete<struct yaSSL::DSS::DSSImpl>(struct yaSSL::DSS::DSSImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::DSS::DSSImpl>(int a1)
{
  KeyValues *v1; // ecx

  if ( a1 != 0 )
  {
    TaoCrypt::DSA_PrivateKey::~DSA_PrivateKey(this: a1 + 64);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(a1 + 56));
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(a1 + 40));
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(a1 + 24));
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(a1 + 8));
  }
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00426300
// Name: void yaSSL::ysDelete<struct yaSSL::RSA::RSAImpl>(struct yaSSL::RSA::RSAImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ysDelete<yaSSL::RSA::RSAImpl>(void *ptr, int ptra)
{
  if ( ptra != 0 )
  {
    TaoCrypt::RSA_PrivateKey::~RSA_PrivateKey(this: (TaoCrypt::RSA_PrivateKey *)(ptra + 32));
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(ptra + 24));
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(ptra + 8));
  }
  operator delete(ptr: (KeyValues *)*(unsigned __int8 *)yaSSL::ys);
}

//------------------------------------------------------------------------------
// Address: 0x00426410
// Name: public: virtual yaSSL::DSS::~DSS(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DSS::~DSS(CThread *this)
{
  int v2; // [esp-4h] [ebp-8h]

  v2 = *(_DWORD *)this->m_Lock.m_CriticalSection;
  this->__vftable = (CThread_vtbl *)&yaSSL::DSS::`vftable';
  yaSSL::ysDelete<yaSSL::DSS::DSSImpl>(a1: v2);
  this->__vftable = (CThread_vtbl *)&yaSSL::Auth::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00426430
// Name: public: virtual yaSSL::RSA::~RSA(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RSA::~RSA(int *this)
{
  int v2; // [esp-4h] [ebp-8h]

  v2 = *(this + 1);
  *this = (int)&yaSSL::RSA::`vftable';
  yaSSL::ysDelete<yaSSL::RSA::RSAImpl>(ptr: this, ptra: v2);
  *this = (int)&yaSSL::Auth::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00426450
// Name: public: yaSSL::Integer::~Integer(void)
// Source: json
//------------------------------------------------------------------------------
const CFunctorCallback0 *__thiscall yaSSL::Integer::~Integer(IMemAlloc *this)
{
  return yaSSL::ysDelete<yaSSL::Integer::IntegerImpl>(result: (const CFunctorCallback0 *)this->__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x00426460
// Name: public: unsigned int TaoCrypt::RSA_Decryptor<class TaoCrypt::RSA_BlockType2>::Decrypt(unsigned char const __near *,unsigned int,unsigned char __near *,class TaoCrypt::RandomNumberGenerator __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::RSA_Decryptor<TaoCrypt::RSA_BlockType2>::Decrypt(
        IIoStats *this@<ecx>,
        const CInternalFileSystemPassThru<IFileSystem> *a2@<esi>,
        unsigned __int16 cipher,
        unsigned int sz,
        unsigned __int8 *plain,
        int a6)
{
  int v7; // eax
  unsigned __int16 v8; // ax
  IConVar *v9; // eax
  IConVar *m_pConVar; // ebx
  const char *v11; // eax
  ConVar *m_pConVarState; // esi
  int v13; // eax
  void **v14; // [esp-14h] [ebp-48h]
  const char *v15; // [esp-8h] [ebp-3Ch]
  ConVarRef v16; // [esp+8h] [ebp-2Ch] BYREF
  CKeyErrorContext x; // [esp+14h] [ebp-20h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v18; // [esp+1Ch] [ebp-18h] BYREF
  __int64 v19; // [esp+2Ch] [ebp-8h] BYREF

  if ( sz == TaoCrypt::Integer::ByteCount() )
  {
    v7 = TaoCrypt::Integer::BitCount();
    TaoCrypt::Block<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>::Block<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
      this: &v16,
      s: (unsigned int)(v7 + 6) >> 3);
    v8 = TaoCrypt::Integer::ByteCount();
    TaoCrypt::Integer::Integer(
      this: (CUtlSymbolTable::CStringPoolIndex *)&v18.m_iRefs,
      encodedInteger: cipher,
      byteCount: v8);
    TaoCrypt::RSA_PrivateKey::CalculateInverse(
      this: (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)this->__vftable,
      rng: (int)&x);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v19);
    v9 = (IConVar *)TaoCrypt::Integer::ByteCount();
    m_pConVar = v16.m_pConVar;
    if ( v9 > v16.m_pConVar )
    {
      v11 = (const char *)TaoCrypt::Integer::Zero(result: a2);
      TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&x, t: v11, a3: v15);
    }
    m_pConVarState = v16.m_pConVarState;
    TaoCrypt::Integer::Encode(a1: &x, a2: v16.m_pConVarState, a3: m_pConVar, a4: 0);
    v13 = TaoCrypt::Integer::BitCount();
    TaoCrypt::RSA_BlockType2::UnPad(
      this: (TaoCrypt::RSA_BlockType2 *)this + 1,
      pkcsBlock: (const LoggingContext_t *)m_pConVarState,
      pkcsBlockLen: v13 - 1,
      a4: plain);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v18);
    memset(dst: (unsigned __int8 *)m_pConVarState, value: 0, count: (unsigned int)m_pConVar);
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: (void *)m_pConVarState, a2: v14);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00426560
// Name: public: void TaoCrypt::RSA_Encryptor<class TaoCrypt::RSA_BlockType2>::Encrypt(unsigned char const __near *,unsigned int,unsigned char __near *,class TaoCrypt::RandomNumberGenerator __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall TaoCrypt::RSA_Encryptor<TaoCrypt::RSA_BlockType2>::Encrypt(
        int this,
        unsigned __int8 *src,
        unsigned int count,
        int a4,
        struct TaoCrypt::RandomNumberGenerator *a5)
{
  const CSplitScreenAddedConVar *v6; // ecx
  unsigned int v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // edi
  int v10; // eax
  struct TaoCrypt::Integer v11; // eax
  void **v13; // [esp-Ch] [ebp-3Ch]
  int v14; // [esp-8h] [ebp-38h]
  CFunctorData v15; // [esp+10h] [ebp-20h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v16; // [esp+18h] [ebp-18h] BYREF
  __int64 v17; // [esp+28h] [ebp-8h] BYREF

  v7 = (unsigned int)(TaoCrypt::Integer::BitCount() + 6) >> 3;
  if ( v7 != 0 )
    v8 = (unsigned __int8 *)operator new[](sz: v6);
  else
    v8 = nullptr;
  v9 = (unsigned __int8 *)TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: (int)&v16,
                            src: v8,
                            a3: v7,
                            count: v7,
                            a5: 0);
  memset(dst: v9, value: 0, count: v7);
  v10 = TaoCrypt::Integer::BitCount();
  TaoCrypt::RSA_BlockType2::Pad(this: (TaoCrypt::RSA_BlockType2 *)(this + 4), src, count, a4: v9, a5: v10 - 1, a6: a5);
  v14 = TaoCrypt::Integer::ByteCount();
  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&v16.m_iRefs,
    encodedInteger: (unsigned __int16)v9,
    byteCount: v7);
  v11.m_stackLevel = TaoCrypt::RSA_PublicKey::ApplyFunction(this: *(TaoCrypt::RSA_PublicKey **)this, result: &v15).m_stackLevel;
  TaoCrypt::Integer::Encode(a1: v11.m_stackLevel, a2: a4, a3: v14, a4: 0);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v16);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v17);
  memset(dst: v9, value: 0, count: v7);
  return TaoCrypt::tcArrayDelete<unsigned char>(ptr: v9, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x00426650
// Name: public: bool TaoCrypt::RSA_Encryptor<class TaoCrypt::RSA_BlockType2>::SSL_Verify(unsigned char const __near *,unsigned int,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall TaoCrypt::RSA_Encryptor<TaoCrypt::RSA_BlockType2>::SSL_Verify(
        TaoCrypt::RSA_PublicKey **this,
        const LoggingContext_t *result,
        unsigned int sz,
        const LoggingContext_t *sig)
{
  unsigned int v5; // eax
  const CSplitScreenAddedConVar *v6; // ecx
  unsigned int v7; // ebp
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // esi
  unsigned int v12; // eax
  unsigned __int8 *v13; // edi
  unsigned __int8 *v14; // [esp-20h] [ebp-38h]
  void **v15; // [esp-Ch] [ebp-24h]
  void **v16; // [esp-Ch] [ebp-24h]
  int v17; // [esp+14h] [ebp-4h] BYREF

  v5 = (unsigned int)(TaoCrypt::Integer::BitCount() - 1) >> 3;
  if ( v5 <= 0xA )
  {
    v7 = 0;
    v8 = nullptr;
  }
  else
  {
    v7 = v5 - 10;
    v8 = (unsigned __int8 *)operator new[](sz: v6);
  }
  v9 = (unsigned __int8 *)TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: (int)&v17,
                            src: v8,
                            a3: v7,
                            count: v7,
                            a5: 0);
  memset(dst: v9, value: 0, count: v7);
  if ( TaoCrypt::SSL_Decrypt(this: *this, encodedInteger: (const struct TaoCrypt::RSA_PublicKey *)sig, a3: v9, a4: v14) != sz )
    goto LABEL_5;
  v12 = sz;
  v13 = v9;
  if ( sz >= 4 )
  {
    while ( *(_DWORD *)v13 == result->m_ChannelID )
    {
      v12 -= 4;
      result = (const LoggingContext_t *)((char *)result + 4);
      v13 += 4;
      if ( v12 < 4 )
        goto LABEL_9;
    }
    goto LABEL_5;
  }
LABEL_9:
  if ( v12 != 0
    && (LOBYTE(result->m_ChannelID) != *v13
     || v12 > 1 && (BYTE1(result->m_ChannelID) != v13[1] || v12 > 2 && BYTE2(result->m_ChannelID) != v13[2])) )
  {
LABEL_5:
    memset(dst: v9, value: 0, count: v7);
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: v9, a2: v15);
    return 0;
  }
  memset(dst: v9, value: 0, count: v7);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v9, a2: v16);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00426740
// Name: public: void TaoCrypt::RSA_Encryptor<class TaoCrypt::RSA_BlockType1>::Encrypt(unsigned char const __near *,unsigned int,unsigned char __near *,class TaoCrypt::RandomNumberGenerator __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall TaoCrypt::RSA_Encryptor<TaoCrypt::RSA_BlockType1>::Encrypt(
        CUtlFilenameSymbolTable *this,
        const LoggingContext_t *plain,
        unsigned int sz,
        unsigned __int8 *cipher,
        struct TaoCrypt::RandomNumberGenerator *a5)
{
  const CSplitScreenAddedConVar *v6; // ecx
  unsigned int v7; // esi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // edi
  int v10; // eax
  struct TaoCrypt::Integer v11; // eax
  void **v13; // [esp-Ch] [ebp-3Ch]
  int v14; // [esp-8h] [ebp-38h]
  CFunctorData v15; // [esp+10h] [ebp-20h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v16; // [esp+18h] [ebp-18h] BYREF
  __int64 v17; // [esp+28h] [ebp-8h] BYREF

  v7 = (unsigned int)(TaoCrypt::Integer::BitCount() + 6) >> 3;
  if ( v7 != 0 )
    v8 = (unsigned __int8 *)operator new[](sz: v6);
  else
    v8 = nullptr;
  v9 = (unsigned __int8 *)TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: (int)&v16,
                            src: v8,
                            a3: v7,
                            count: v7,
                            a5: 0);
  memset(dst: v9, value: 0, count: v7);
  v10 = TaoCrypt::Integer::BitCount();
  TaoCrypt::RSA_BlockType1::Pad(
    this: (TaoCrypt::RSA_BlockType1 *)&this->m_PathStringPool.m_HashTable,
    input: plain,
    inputLen: sz,
    pkcsBlock: v9,
    pkcsBlockLen: v10 - 1,
    a6: a5);
  v14 = TaoCrypt::Integer::ByteCount();
  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&v16.m_iRefs,
    encodedInteger: (unsigned __int16)v9,
    byteCount: v7);
  v11.m_stackLevel = TaoCrypt::RSA_PublicKey::ApplyFunction(
                       this: (TaoCrypt::RSA_PublicKey *)this->m_PathStringPool.__vftable,
                       result: &v15).m_stackLevel;
  TaoCrypt::Integer::Encode(a1: v11.m_stackLevel, a2: cipher, a3: v14, a4: 0);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v16);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v17);
  memset(dst: v9, value: 0, count: v7);
  return TaoCrypt::tcArrayDelete<unsigned char>(ptr: v9, a2: v13);
}

//------------------------------------------------------------------------------
// Address: 0x00426830
// Name: public: TaoCrypt::Base64Decoder::Base64Decoder(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
ICvar::Iterator *__thiscall TaoCrypt::Base64Decoder::Base64Decoder(ICvar::Iterator *this, struct TaoCrypt::Source *a2)
{
  this->m_pIter = nullptr;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 1) = TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: (int)(this + 2),
                            src: nullptr,
                            a3: 0,
                            count: 0,
                            a5: 0);
  this->m_pIter = nullptr;
  *((_DWORD *)this + 3) = a2;
  TaoCrypt::Base64Decoder::Decode(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004268A0
// Name: public: virtual bool yaSSL::RSA::verify(unsigned char const __near *,unsigned int,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RSA::verify(
        CThreadMutex *this,
        const LoggingContext_t *message,
        unsigned int sz,
        const LoggingContext_t *sig,
        unsigned int __formal)
{
  TaoCrypt::RSA_PublicKey *v5; // [esp+0h] [ebp-8h] BYREF

  v5 = *(TaoCrypt::RSA_PublicKey **)&this->m_CriticalSection[4];
  TaoCrypt::RSA_Encryptor<TaoCrypt::RSA_BlockType2>::SSL_Verify(this: &v5, result: message, sz, sig);
}

//------------------------------------------------------------------------------
// Address: 0x004268D0
// Name: public: void yaSSL::RSA::encrypt(unsigned char __near *,unsigned char const __near *,unsigned int,class yaSSL::RandomPool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RSA::encrypt(
        CThreadMutex *this,
        const CThreadMutex *cipher,
        unsigned __int8 *plain,
        unsigned int sz,
        struct TaoCrypt::RandomNumberGenerator **random)
{
  struct TaoCrypt::RandomNumberGenerator *v5; // [esp-4h] [ebp-Ch]
  int v6; // [esp+0h] [ebp-8h] BYREF

  v5 = *random;
  v6 = *(_DWORD *)&this->m_CriticalSection[4];
  TaoCrypt::RSA_Encryptor<TaoCrypt::RSA_BlockType2>::Encrypt(
    this: (int)&v6,
    src: plain,
    count: sz,
    a4: (int)cipher,
    a5: v5);
}

//------------------------------------------------------------------------------
// Address: 0x00426900
// Name: public: void yaSSL::RSA::decrypt(unsigned char __near *,unsigned char const __near *,unsigned int,class yaSSL::RandomPool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::RSA::decrypt(
        CThreadMutex *this@<ecx>,
        const CInternalFileSystemPassThru<IFileSystem> *a2@<esi>,
        const CThreadMutex *plain,
        unsigned __int16 cipher,
        unsigned int sz,
        int *random)
{
  int v6; // [esp-4h] [ebp-Ch]
  IIoStats v7; // [esp+0h] [ebp-8h] BYREF

  v6 = *random;
  v7.__vftable = (IIoStats_vtbl *)(*(_DWORD *)&this->m_CriticalSection[4] + 32);
  TaoCrypt::RSA_Decryptor<TaoCrypt::RSA_BlockType2>::Decrypt(
    this: &v7,
    a2,
    cipher,
    sz,
    plain: plain->m_CriticalSection,
    a6: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00426940
// Name: class yaSSL::x509 __near * yaSSL::PemToDer(struct _iobuf __near *,enum yaSSL::CertType,struct yaSSL::EncryptedInfo __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<KeyValues *,int> *__cdecl yaSSL::PemToDer(_iobuf *result, int file_4, unsigned __int8 *dst)
{
  int v3; // ebp
  unsigned __int8 *v4; // eax
  unsigned __int8 *v5; // esi
  unsigned int v6; // eax
  unsigned int v7; // ebp
  unsigned __int8 *v8; // eax
  unsigned int v9; // eax
  void *length; // eax
  int (__cdecl *v12)(const CUtlString *, const CUtlString *); // eax
  IConVar *m_pConVar; // edi
  yaSSL::x509 *v14; // eax
  CUtlMemory<KeyValues *,int> *v15; // esi
  unsigned __int8 *v16; // eax
  sockaddr_in *v17; // ecx
  unsigned __int8 *v18; // edi
  ConVar *m_pConVarState; // edi
  void **v20; // [esp-2Ch] [ebp-17Ch]
  void **v21; // [esp-1Ch] [ebp-16Ch]
  int v22; // [esp-Ch] [ebp-15Ch]
  unsigned __int8 *v23; // [esp-8h] [ebp-158h]
  const char *v24; // [esp+0h] [ebp-150h]
  bool foundEnd; // [esp+13h] [ebp-13Dh]
  int end; // [esp+14h] [ebp-13Ch]
  CUtlString v27; // [esp+1Ch] [ebp-134h] BYREF
  ConVarRef der; // [esp+2Ch] [ebp-124h] BYREF
  unsigned int count; // [esp+40h] [ebp-110h] BYREF
  unsigned __int8 *v30; // [esp+44h] [ebp-10Ch]
  CFunctorCallbackBase encHeader; // [esp+50h] [ebp-100h] BYREF
  $_s__RTTIBaseClassArray$_extraBytes_8 line; // [esp+5Ch] [ebp-F4h] BYREF
  $_s__RTTIBaseClassArray$_extraBytes_8 header; // [esp+ACh] [ebp-A4h] BYREF
  $_s__RTTIBaseClassArray$_extraBytes_8 footer; // [esp+FCh] [ebp-54h] BYREF

  if ( file_4 != 0 )
  {
    strncpy(dest: (unsigned __int8 *)&header, source: "-----BEGIN RSA PRIVATE KEY-----", count: 0x50u);
    strncpy(dest: (unsigned __int8 *)&footer, source: "-----END RSA PRIVATE KEY-----", count: 0x50u);
  }
  else
  {
    strncpy(dest: (unsigned __int8 *)&header, source: "-----BEGIN CERTIFICATE-----", count: 0x50u);
    strncpy(dest: (unsigned __int8 *)&footer, source: "-----END CERTIFICATE-----", count: 0x50u);
  }
  v3 = -1;
  end = 0;
  foundEnd = false;
  if ( fgets(string: (char *)&line, count: 80, str: result) != nullptr )
  {
    while ( strncmp(first: (const char *)&header, last: (const char *)&line, count: strlen((const char *)&header)) != 0 )
    {
      if ( fgets(string: (char *)&line, count: 80, str: result) == nullptr )
        goto LABEL_9;
    }
    v3 = ftell(stream: result);
  }
LABEL_9:
  if ( fgets(string: (char *)&line, count: 80, str: result) != nullptr )
  {
    strcpy((char *)&encHeader, "Proc-Type");
    if ( strncmp(first: (const char *)&encHeader, last: (const char *)&line, count: strlen((const char *)&encHeader)) == 0
      && fgets(string: (char *)&line, count: 80, str: result) != nullptr )
    {
      strstr(str1: (unsigned __int8 *)&line, str2: "DES");
      v5 = v4;
      strstr(str1: (unsigned __int8 *)&line, str2: ",");
      v7 = v6;
      if ( v5 == nullptr )
      {
        strstr(str1: (unsigned __int8 *)&line, str2: "AES");
        v5 = v8;
      }
      if ( dst == nullptr )
        return nullptr;
      if ( v5 != nullptr && v7 != 0 && (unsigned int)v5 < v7 )
      {
        memcpy(dst, src: v5, count: v7 - (_DWORD)v5);
        *(_BYTE *)(dst - v5 + v7) = 0;
        qmemcpy(dst + 80, (const void *)(v7 + 1), 0x20u);
        strstr(str1: (unsigned __int8 *)&line, str2: "\r");
        if ( v9 != 0 || (strstr(str1: (unsigned __int8 *)&line, str2: "\n"), v9 != 0) )
        {
          if ( v9 > v7 )
          {
            *((_DWORD *)dst + 28) = v9 - v7 - 1;
            dst[116] = 1;
          }
        }
      }
      fgets(string: (char *)&line, count: 80, str: result);
      v3 = ftell(stream: result);
    }
  }
  if ( fgets(string: (char *)&line, count: 80, str: result) != nullptr )
  {
    while ( strncmp(first: (const char *)&footer, last: (const char *)&line, count: strlen((const char *)&footer)) != 0 )
    {
      end = ftell(stream: result);
      if ( fgets(string: (char *)&line, count: 80, str: result) == nullptr )
        goto LABEL_28;
    }
    foundEnd = true;
  }
LABEL_28:
  if ( v3 == -1 || !foundEnd )
    return nullptr;
  yaSSL::input_buffer::input_buffer(result: (const CUtlString *)(end - v3));
  fseek(stream: result, offset: v3, whence: 0);
  length = (void *)yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v27);
  if ( fread(buffer: length, elementSize: end - v3, count: 1u, stream: result) != 1 )
  {
    yaSSL::input_buffer::~input_buffer(this: &v27, a2: v24);
    return nullptr;
  }
  v12 = (int (__cdecl *)(const CUtlString *, const CUtlString *))yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v27);
  TaoCrypt::Source::Source(this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)&der, b: v12);
  TaoCrypt::Base64Decoder::Base64Decoder(this: (ICvar::Iterator *)&count, a2: &der);
  m_pConVar = der.m_pConVar;
  v14 = (yaSSL::x509 *)operator new(sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  if ( v14 != nullptr )
    v15 = (CUtlMemory<KeyValues *,int> *)yaSSL::x509::x509(this: v14, a2: (unsigned int)m_pConVar);
  else
    v15 = nullptr;
  yaSSL::SSL_CTX::getCert(this: v15, a2: (CUtlMemory<KeyValues *,int> *)der.m_pConVarState);
  memcpy(dst: v16, src: v23, count: (unsigned int)m_pConVar);
  yaSSL::ysDelete<yaSSL::x509>(ptr: v17, a2: nullptr, a3: v22);
  v18 = v30;
  memset(dst: v30, value: 0, count);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v18, a2: v21);
  m_pConVarState = der.m_pConVarState;
  memset(dst: (unsigned __int8 *)der.m_pConVarState, value: 0, count: (unsigned int)der.m_pConVar);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: (void *)m_pConVarState, a2: v20);
  yaSSL::input_buffer::~input_buffer(this: &v27, a2: v24);
  return v15;
}

//------------------------------------------------------------------------------
// Address: 0x00426D10
// Name: public: void TaoCrypt::RSA_Decryptor<class TaoCrypt::RSA_BlockType2>::SSL_Sign(unsigned char const __near *,unsigned int,unsigned char __near *,class TaoCrypt::RandomNumberGenerator __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::RSA_Decryptor<TaoCrypt::RSA_BlockType2>::SSL_Sign(
        IIoStats *this,
        const LoggingContext_t *message,
        unsigned int sz,
        unsigned __int8 *sig,
        struct TaoCrypt::RandomNumberGenerator *a5)
{
  int (__thiscall **p_GetNumberOfFileOpens)(IIoStats *); // esi
  IIoStats_vtbl *v7; // [esp-4h] [ebp-30h]
  const char *v8; // [esp+0h] [ebp-2Ch]
  const char *v9; // [esp+0h] [ebp-2Ch]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > **p_inverse; // [esp+4h] [ebp-28h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *inverse; // [esp+Ch] [ebp-20h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v12; // [esp+14h] [ebp-18h] BYREF
  __int64 v13; // [esp+24h] [ebp-8h] BYREF

  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&inverse);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v12.m_iRefs);
  v7 = this->__vftable;
  p_GetNumberOfFileOpens = &this->GetNumberOfFileOpens;
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&inverse, t: (const char *)v7, a3: v8);
  TaoCrypt::Integer::operator=(
    this: (CInternalFileSystemPassThru<IFileSystem> *)&v12.m_iRefs,
    t: (const char *)p_GetNumberOfFileOpens,
    a3: v9);
  p_inverse = &inverse;
  TaoCrypt::RSA_Encryptor<TaoCrypt::RSA_BlockType1>::Encrypt(
    this: (CUtlFilenameSymbolTable *)&p_inverse,
    plain: message,
    sz,
    cipher: sig,
    a5);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v13);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v12);
}

//------------------------------------------------------------------------------
// Address: 0x00426DA0
// Name: public: virtual void yaSSL::RSA::sign(unsigned char __near *,unsigned char const __near *,unsigned int,class yaSSL::RandomPool const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::RSA::sign(
        CThreadMutex *this,
        const CThreadMutex *sig,
        const LoggingContext_t *message,
        unsigned int sz,
        struct TaoCrypt::RandomNumberGenerator **random)
{
  struct TaoCrypt::RandomNumberGenerator *v5; // [esp-4h] [ebp-Ch]
  IIoStats v6; // [esp+0h] [ebp-8h] BYREF

  v5 = *random;
  v6.__vftable = (IIoStats_vtbl *)(*(_DWORD *)&this->m_CriticalSection[4] + 32);
  TaoCrypt::RSA_Decryptor<TaoCrypt::RSA_BlockType2>::SSL_Sign(
    this: &v6,
    message,
    sz,
    sig: sig->m_CriticalSection,
    a5: v5);
}
