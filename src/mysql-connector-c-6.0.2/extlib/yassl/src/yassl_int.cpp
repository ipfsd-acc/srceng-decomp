// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/yassl_int.cpp
// Functions: 136
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\yassl_int.h"

//------------------------------------------------------------------------------
// Address: 0x00420C00
// Name: void yaSSL::c32to24(unsigned int,unsigned char (__near &)[3])
// Source: json
//------------------------------------------------------------------------------
yaSSL *__cdecl yaSSL::c32to24(yaSSL *this, _BYTE *a2)
{
  *a2 = BYTE2(this);
  a2[1] = BYTE1(this);
  a2[2] = (_BYTE)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00420C20
// Name: void yaSSL::c24to32(unsigned char const __near * const,unsigned int __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL::c24to32(const LoggingContext_t *u24, int *u32)
{
  int result; // eax

  *u32 = 0;
  result = BYTE2(u24->m_ChannelID);
  *u32 = result | ((BYTE1(u24->m_ChannelID) | (LOBYTE(u24->m_ChannelID) << 8)) << 8);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00420C50
// Name: unsigned int yaSSL::c24to32(unsigned char const __near * const)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl yaSSL::c24to32(const LoggingContext_t *u24)
{
  unsigned int v1; // ecx
  unsigned int ret; // [esp+0h] [ebp-4h] BYREF

  ret = v1;
  yaSSL::c24to32(u24, u32: (int *)&ret);
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x00420C70
// Name: void yaSSL::ato16(unsigned char const __near *,unsigned short __near &)
// Source: json
//------------------------------------------------------------------------------
_WORD *__thiscall yaSSL::ato16(const IntVector4D *c, unsigned __int16 *ca, _WORD *a3)
{
  *a3 = 0;
  *a3 = _byteswap_ushort(*ca);
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x00420CA0
// Name: void yaSSL::c16toa(unsigned short,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
IntVector4D *__thiscall yaSSL::c16toa(void *u16, int u16a, unsigned __int8 *c)
{
  *c = BYTE1(u16a);
  c[1] = u16a;
  return (IntVector4D *)u16a;
}

//------------------------------------------------------------------------------
// Address: 0x00420CC0
// Name: void yaSSL::c32toa(unsigned int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::c32toa(yaSSL *this, unsigned __int8 *c)
{
  *c = HIBYTE(this);
  c[1] = BYTE2(this);
  c[2] = BYTE1(this);
  c[3] = (unsigned __int8)this;
}

//------------------------------------------------------------------------------
// Address: 0x00420CF0
// Name: public: yaSSL::States::States(void)
// Source: json
//------------------------------------------------------------------------------
yaSSL::States *__thiscall yaSSL::States::States(yaSSL::States *this)
{
  *(_DWORD *)this = 1;
  *((_DWORD *)this + 1) = 1;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 26) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00420D30
// Name: public: enum yaSSL::YasslError yaSSL::States::What(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::States::What(_DWORD *this)
{
  return *(this + 26);
}

//------------------------------------------------------------------------------
// Address: 0x00420D40
// Name: public: enum yaSSL::ClientState __near & yaSSL::States::useClient(void)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall yaSSL::States::useClient(CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *this)
{
  return &this->m_Memory.m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x00420D50
// Name: public: void yaSSL::States::SetError(enum yaSSL::YasslError)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::States::SetError(_DWORD *this, int a2)
{
  *(this + 26) = a2;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x00420D60
// Name: public: class yaSSL::Factory<struct yaSSL::ClientKeyBase,int,struct yaSSL::ClientKeyBase __near * (*)(void)> const __near & yaSSL::sslFactory::getClientKey(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall yaSSL::sslFactory::getClientKey(char *this)
{
  return this + 36;
}

//------------------------------------------------------------------------------
// Address: 0x00420D70
// Name: public: void yaSSL::SSL::SetError(enum yaSSL::YasslError)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::SSL::SetError(_DWORD *this, void (__thiscall *ye)(CBaseEntity *this, inputdata_t *))
{
  return yaSSL::States::SetError(this: this + 571, a2: (int)ye);
}

//------------------------------------------------------------------------------
// Address: 0x00420D80
// Name: public: void yaSSL::SSL::SetQuietShutdown(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::SetQuietShutdown(yaSSL::SSL *this, bool mode)
{
  *((_BYTE *)this + 2525) = mode;
}

//------------------------------------------------------------------------------
// Address: 0x00420E50
// Name: public: void yaSSL::SSL::order_error(void)
// Source: json
//------------------------------------------------------------------------------
st_mysql *__thiscall yaSSL::SSL::order_error(_DWORD *this)
{
  return (st_mysql *)yaSSL::SSL::SetError(this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6C);
}

//------------------------------------------------------------------------------
// Address: 0x00420E60
// Name: public: void yaSSL::SSL::Send(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::Send(yaSSL::SSL *this, const LoggingContext_t *buffer, unsigned int sz)
{
  if ( yaSSL::Socket::send(this: (yaSSL::SSL *)((char *)this + 2488), buf: buffer, sz, a4: 0) != sz )
    yaSSL::SSL::SetError(this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x71);
}

//------------------------------------------------------------------------------
// Address: 0x00420EC0
// Name: public: bool yaSSL::SSL::GetQuietShutdown(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::SSL::GetQuietShutdown(_BYTE *this)
{
  return *(this + 2525);
}

//------------------------------------------------------------------------------
// Address: 0x00420F00
// Name: public: bool yaSSL::SSL::HasData(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::SSL::HasData(_BYTE *this)
{
  return *(this + 2526);
}

//------------------------------------------------------------------------------
// Address: 0x00420F10
// Name: public: yaSSL::SSL_SESSION::SSL_SESSION(class yaSSL::RandomPool __near &)
// Source: json
//------------------------------------------------------------------------------
QAngle *__thiscall yaSSL::SSL_SESSION::SSL_SESSION(QAngle *this, int ran)
{
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = ran;
  *((_DWORD *)this + 24) = 0;
  this->x = 0.0;
  this->y = 0.0;
  this->z = 0.0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
  memset(dst: (unsigned __int8 *)this + 32, value: 0, count: 0x30u);
  *((_WORD *)this + 40) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00420F60
// Name: public: unsigned char const __near * yaSSL::SSL_SESSION::GetSecret(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall yaSSL::SSL_SESSION::GetSecret(yaSSL::SSL_SESSION *this)
{
  return (char *)this + 32;
}

//------------------------------------------------------------------------------
// Address: 0x00420F70
// Name: public: unsigned char const __near * yaSSL::SSL_SESSION::GetSuite(void)const
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__thiscall yaSSL::SSL_SESSION::GetSuite(yaSSL::SSL_SESSION *this)
{
  return (const unsigned __int8 *)this + 80;
}

//------------------------------------------------------------------------------
// Address: 0x00420F80
// Name: public: class yaSSL::X509 __near * yaSSL::SSL_SESSION::GetPeerX509(void)const
// Source: json
//------------------------------------------------------------------------------
float *__thiscall yaSSL::SSL_SESSION::GetPeerX509(QAngle *this)
{
  return *((float **)this + 24);
}

//------------------------------------------------------------------------------
// Address: 0x00420F90
// Name: public: unsigned int yaSSL::SSL_SESSION::GetBornOn(void)const
// Source: json
//------------------------------------------------------------------------------
const float *__thiscall yaSSL::SSL_SESSION::GetBornOn(QAngle *this)
{
  return *((const float **)this + 21);
}

//------------------------------------------------------------------------------
// Address: 0x00420FA0
// Name: public: unsigned int yaSSL::SSL_SESSION::GetTimeOut(void)const
// Source: json
//------------------------------------------------------------------------------
const float *__thiscall yaSSL::SSL_SESSION::GetTimeOut(QAngle *this)
{
  return *((const float **)this + 22);
}

//------------------------------------------------------------------------------
// Address: 0x00420FB0
// Name: public: void yaSSL::SSL_SESSION::SetTimeOut(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_SESSION::SetTimeOut(yaSSL::SSL_SESSION *this, unsigned int a2)
{
  *((_DWORD *)this + 22) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x00420FC0
// Name: unsigned long yaSSL::yassl_int_cpp_local2::GetSelf(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall yaSSL::yassl_int_cpp_local2::GetSelf()
{
  return GetCurrentThreadId();
}

//------------------------------------------------------------------------------
// Address: 0x00420FD0
// Name: public: yaSSL::SSL_METHOD::SSL_METHOD(enum yaSSL::ConnectionEnd,struct yaSSL::ProtocolVersion,bool)
// Source: json
//------------------------------------------------------------------------------
_BYTE *__thiscall yaSSL::SSL_METHOD::SSL_METHOD(_BYTE *this, modsv_t *ce, __int16 pv, bool multiProto)
{
  *(_WORD *)this = pv;
  *(this + 8) = 0;
  *(this + 9) = 0;
  *(this + 10) = 0;
  *((_DWORD *)this + 1) = ce;
  *(this + 11) = multiProto;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00421000
// Name: public: struct yaSSL::ProtocolVersion yaSSL::SSL_METHOD::getVersion(void)const
// Source: json
//------------------------------------------------------------------------------
KeyValues *__userpurge yaSSL::SSL_METHOD::getVersion@<eax>(IKeyValuesDumpContext *this@<ecx>, KeyValues *a2, int a3)
{
  *(_WORD *)a2 = this->__vftable;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x00421010
// Name: public: class yaSSL::x509 const __near * yaSSL::SSL_CTX::getCert(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_CTX::getCert(CUtlMemory<KeyValues *,int> *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00421020
// Name: public: void yaSSL::SSL_METHOD::setVerifyPeer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_METHOD::setVerifyPeer(_BYTE *this)
{
  *(this + 8) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00421030
// Name: public: void yaSSL::SSL_METHOD::setVerifyNone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_METHOD::setVerifyNone(_BYTE *this)
{
  *(this + 9) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00421040
// Name: public: void yaSSL::SSL_METHOD::setFailNoCert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_METHOD::setFailNoCert(_BYTE *this)
{
  *(this + 10) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00421050
// Name: public: bool yaSSL::SSL_METHOD::verifyPeer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::SSL_METHOD::verifyPeer(ConCommandBase *this)
{
  return this->m_bRegistered;
}

//------------------------------------------------------------------------------
// Address: 0x00421060
// Name: public: bool yaSSL::SSL_METHOD::verifyNone(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::SSL_METHOD::verifyNone(yaSSL::SSL_METHOD *this)
{
  return *((_BYTE *)this + 9);
}

//------------------------------------------------------------------------------
// Address: 0x00421070
// Name: public: bool yaSSL::SSL_METHOD::failNoCert(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::SSL_METHOD::failNoCert(yaSSL::SSL_METHOD *this)
{
  return *((_BYTE *)this + 10);
}

//------------------------------------------------------------------------------
// Address: 0x00421080
// Name: public: bool yaSSL::SSL_METHOD::multipleProtocol(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::SSL_METHOD::multipleProtocol(yaSSL::SSL_METHOD *this)
{
  return *((_BYTE *)this + 11);
}

//------------------------------------------------------------------------------
// Address: 0x004210B0
// Name: public: struct yaSSL::Ciphers const __near & yaSSL::SSL_CTX::GetCiphers(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::SSL_CTX::GetCiphers(void *this)
{
  return (int)this + 24;
}

//------------------------------------------------------------------------------
// Address: 0x004210C0
// Name: public: struct yaSSL::DH_Parms const __near & yaSSL::SSL_CTX::GetDH_Parms(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_CTX::GetDH_Parms(QuaternionAligned *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004210D0
// Name: public: int (*yaSSL::SSL_CTX::GetPasswordCb(void)const)(char __near *,int,int,void __near *)
// Source: json
//------------------------------------------------------------------------------
Quaternion *__thiscall yaSSL::SSL_CTX::GetPasswordCb(QuaternionAligned *this)
{
  return *((Quaternion **)this + 43);
}

//------------------------------------------------------------------------------
// Address: 0x004210E0
// Name: public: void __near * yaSSL::SSL_CTX::GetUserData(void)const
// Source: json
//------------------------------------------------------------------------------
const Quaternion *__thiscall yaSSL::SSL_CTX::GetUserData(_DWORD *this)
{
  return (const Quaternion *)*(this + 44);
}

//------------------------------------------------------------------------------
// Address: 0x004210F0
// Name: public: bool yaSSL::SSL_CTX::GetSessionCacheOff(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::SSL_CTX::GetSessionCacheOff(QuaternionAligned *this)
{
  return *((_BYTE *)this + 180);
}

//------------------------------------------------------------------------------
// Address: 0x00421100
// Name: public: bool yaSSL::SSL_CTX::GetSessionCacheFlushOff(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::SSL_CTX::GetSessionCacheFlushOff(QuaternionAligned *this)
{
  return *((_BYTE *)this + 181);
}

//------------------------------------------------------------------------------
// Address: 0x00421110
// Name: public: void yaSSL::SSL_CTX::setVerifyPeer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_CTX::setVerifyPeer(yaSSL::SSL_CTX *this)
{
  yaSSL::SSL_METHOD::setVerifyPeer(this: *this);
}

//------------------------------------------------------------------------------
// Address: 0x00421120
// Name: public: void yaSSL::SSL_CTX::setVerifyNone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_CTX::setVerifyNone(yaSSL::SSL_CTX *this)
{
  yaSSL::SSL_METHOD::setVerifyNone(this: *this);
}

//------------------------------------------------------------------------------
// Address: 0x00421130
// Name: public: void yaSSL::SSL_CTX::setFailNoCert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_CTX::setFailNoCert(yaSSL::SSL_CTX *this)
{
  yaSSL::SSL_METHOD::setFailNoCert(this: *this);
}

//------------------------------------------------------------------------------
// Address: 0x00421140
// Name: public: void yaSSL::SSL_CTX::setVerifyCallback(int (*)(int,struct yaSSL::X509_STORE_CTX __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_CTX::setVerifyCallback(yaSSL::SSL_CTX *this, typedescription_t *vc)
{
  *(this + 62) = vc;
}

//------------------------------------------------------------------------------
// Address: 0x00421150
// Name: public: bool yaSSL::SSL_CTX::SetDH(struct yaSSL::DH const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::SSL_CTX::SetDH(yaSSL::SSL_CTX *this, const char ***a2)
{
  const char *v4; // [esp+0h] [ebp-8h]
  const char *v5; // [esp+0h] [ebp-8h]

  yaSSL::Integer::operator=(this: (IMemAlloc *)this + 40, that: *a2, a3: v4);
  yaSSL::Integer::operator=(this: (IMemAlloc *)this + 41, that: a2[1], a3: v5);
  *((_BYTE *)this + 168) = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00421190
// Name: public: bool yaSSL::SSL_CTX::SetCipherList(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::SSL_CTX::SetCipherList(_BYTE *this, QuaternionAligned *result)
{
  unsigned __int8 *v2; // eax
  int v4; // ebp
  char *v5; // edi
  char *v6; // eax
  unsigned int v7; // esi
  int v8; // ebx
  _BYTE *v9; // eax
  int v10; // ebp
  bool ret; // [esp+3h] [ebp-41h]
  char *haystack; // [esp+4h] [ebp-40h]
  char str2[4]; // [esp+8h] [ebp-3Ch] BYREF
  _BYTE *v14; // [esp+Ch] [ebp-38h]
  char dest[48]; // [esp+10h] [ebp-34h] BYREF

  v2 = (unsigned __int8 *)result;
  v14 = this;
  if ( result == nullptr )
    return false;
  ret = false;
  strcpy(str2, ":");
  v4 = 0;
  while ( 1 )
  {
    v5 = (char *)v2;
    strstr(str1: v2, (unsigned __int8 *)str2);
    haystack = v6;
    if ( v6 != nullptr )
    {
      v7 = v6 - v5;
      if ( (unsigned int)(v6 - v5) > 0x30 )
        v7 = 48;
    }
    else
    {
      v7 = strlen(v5) > 0x30 ? 48 : strlen(v5);
    }
    strncpy((unsigned __int8 *)dest, source: (unsigned __int8 *)v5, count: v7);
    if ( v7 == 48 )
      v7 = 47;
    dest[v7] = 0;
    v8 = 0;
    while ( strncmp(first: dest, last: *((const char **)cipher_names_0 + v8), count: 0x30u) != 0 )
    {
      if ( ++v8 >= 128 )
      {
        v9 = v14;
        goto LABEL_17;
      }
    }
    v9 = v14;
    v14[v4 + 25] = 0;
    v10 = v4 + 1;
    v9[v10 + 25] = v8;
    v4 = v10 + 1;
    if ( !ret )
      ret = true;
LABEL_17:
    if ( haystack == nullptr )
      break;
    v2 = (unsigned __int8 *)(haystack + 1);
  }
  if ( ret )
  {
    v9[24] = 1;
    *((_DWORD *)v9 + 39) = v4;
  }
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x004212D0
// Name: public: yaSSL::Crypto::Crypto(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *const *__thiscall yaSSL::Crypto::Crypto(CUtlMemory<KeyValues *,int> *this)
{
  this->m_pMemory = nullptr;
  this->m_nAllocationCount = 0;
  this->m_nGrowSize = 0;
  yaSSL::RandomPool::RandomPool(this: (yaSSL::RandomPool *)this + 3);
  yaSSL::CertManager::CertManager(this: (ShortVector *)this + 2);
  return (KeyValues *const *)this;
}

//------------------------------------------------------------------------------
// Address: 0x00421300
// Name: public: class yaSSL::CertManager const __near & yaSSL::Crypto::get_certManager(void)const
// Source: json
//------------------------------------------------------------------------------
KeyValues ***__thiscall yaSSL::Crypto::get_certManager(CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *this)
{
  return &this->m_pElements;
}

//------------------------------------------------------------------------------
// Address: 0x00421310
// Name: public: void yaSSL::Crypto::SetDH(class yaSSL::DiffieHellman __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Crypto::SetDH(yaSSL::Crypto *this, struct yaSSL::DiffieHellman *a2)
{
  *((_DWORD *)this + 2) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x00421320
// Name: public: void yaSSL::Crypto::SetDH(struct yaSSL::DH_Parms const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Crypto::SetDH(CUtlMemory<KeyValues *,int> *this, HINSTANCE__ *dh)
{
  CSplitScreenAddedConVar *v3; // eax

  if ( *((_BYTE *)dh + 8) != 0 )
  {
    v3 = operator new(sz: (const CSplitScreenAddedConVar *)this, sza: 4u);
    if ( v3 != nullptr )
      this->m_nGrowSize = (int)yaSSL::DiffieHellman::DiffieHellman(
                                 this: v3,
                                 a2: (const char **)dh,
                                 a3: (const char **)dh + 1,
                                 a4: (const struct yaSSL::RandomPool *)(this + 1));
    else
      this->m_nGrowSize = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00421370
// Name: public: void yaSSL::Crypto::setCipher(struct yaSSL::BulkCipher __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::Crypto::setCipher(
        CUtlString *this@<ecx>,
        const CUtlMemory<KeyValues *,int>::Iterator_t *i,
        int a3)
{
  this->m_Storage.m_Memory.m_nAllocationCount = (int)i;
}

//------------------------------------------------------------------------------
// Address: 0x00421380
// Name: public: struct yaSSL::Hashes __near & yaSSL::sslHashes::use_certVerify(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *__thiscall yaSSL::sslHashes::use_certVerify(
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *this)
{
  return this + 3;
}

//------------------------------------------------------------------------------
// Address: 0x00421390
// Name: public: void yaSSL::Buffers::SetRawInput(class yaSSL::input_buffer __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::Buffers::SetRawInput(_DWORD *this, int ib)
{
  *(this + 6) = ib;
  return ib;
}

//------------------------------------------------------------------------------
// Address: 0x004213A0
// Name: public: class yaSSL::input_buffer __near * yaSSL::Buffers::TakeRawInput(void)
// Source: json
//------------------------------------------------------------------------------
struct yaSSL::input_buffer *__thiscall yaSSL::Buffers::TakeRawInput(yaSSL::Buffers *this)
{
  struct yaSSL::input_buffer *result; // eax

  result = *((struct yaSSL::input_buffer **)this + 6);
  *((_DWORD *)this + 6) = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004213B0
// Name: public: enum yaSSL::ServerState __near & yaSSL::States::useServer(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall yaSSL::States::useServer(char *this)
{
  return this + 12;
}

//------------------------------------------------------------------------------
// Address: 0x004213C0
// Name: public: class yaSSL::MD5 const __near & yaSSL::sslHashes::get_MD5(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::sslHashes::get_MD5(ShortVector *this)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x004213D0
// Name: public: class yaSSL::SSL_CTX const __near * yaSSL::Security::GetContext(void)const
// Source: json
//------------------------------------------------------------------------------
const struct SSL_CTX *__thiscall yaSSL::Security::GetContext(yaSSL::Security *this)
{
  return *((const struct SSL_CTX **)this + 543);
}

//------------------------------------------------------------------------------
// Address: 0x004213E0
// Name: public: struct yaSSL::Parameters __near & yaSSL::Security::use_parms(void)
// Source: json
//------------------------------------------------------------------------------
const st_mysql_methods *__thiscall yaSSL::Security::use_parms(char *this)
{
  return (const st_mysql_methods *)(this + 312);
}

//------------------------------------------------------------------------------
// Address: 0x004213F0
// Name: public: class yaSSL::SSL_SESSION const __near & yaSSL::Security::get_resume(void)const
// Source: json
//------------------------------------------------------------------------------
const struct yaSSL::SSL_SESSION *__thiscall yaSSL::Security::get_resume(yaSSL::Security *this)
{
  return (yaSSL::Security *)((char *)this + 2072);
}

//------------------------------------------------------------------------------
// Address: 0x00421400
// Name: public: bool yaSSL::Security::get_resuming(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::Security::get_resuming(_BYTE *this)
{
  return *(this + 2176);
}

//------------------------------------------------------------------------------
// Address: 0x00421410
// Name: public: void yaSSL::Security::set_resuming(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Security::set_resuming(yaSSL::Security *this, bool a2)
{
  *((_BYTE *)this + 2176) = a2;
}

//------------------------------------------------------------------------------
// Address: 0x00421420
// Name: public: yaSSL::X509_NAME::X509_NAME(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::X509_NAME::X509_NAME(
        CSplitScreenAddedConVar *this,
        unsigned __int8 *n,
        const CSplitScreenAddedConVar *sz)
{
  unsigned __int8 *v4; // eax

  this->ConVar::ConCommandBase::__vftable = nullptr;
  this->m_pNext = &sz->ConCommandBase;
  if ( sz != nullptr )
  {
    v4 = (unsigned __int8 *)operator new[](sz: this, sza: sz);
    this->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)v4;
    memcpy(dst: v4, src: n, count: (unsigned int)sz);
  }
  this->m_pszHelpString = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00421470
// Name: public: class yaSSL::X509_NAME __near * yaSSL::X509::GetSubject(void)
// Source: json
//------------------------------------------------------------------------------
struct X509_NAME *__thiscall yaSSL::X509::GetSubject(yaSSL::X509 *this)
{
  return (yaSSL::X509 *)((char *)this + 20);
}

//------------------------------------------------------------------------------
// Address: 0x00421480
// Name: public: yaSSL::StringHolder::StringHolder(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::StringHolder::StringHolder(IMemAlloc *this@<ecx>, unsigned __int8 *str, const char *sz, int a4)
{
  unsigned __int8 *v5; // eax

  *((_DWORD *)this + 1) = sz;
  v5 = (unsigned __int8 *)operator new[](
                            sz: (const CSplitScreenAddedConVar *)(sz + 1),
                            sza: (const CSplitScreenAddedConVar *)(sz + 1));
  *((_DWORD *)this + 2) = v5;
  memcpy(dst: v5, src: str, count: (unsigned int)sz);
  this->__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004214C0
// Name: int yaSSL::Compress(unsigned char const __near *,int,class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL::Compress()
{
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004214D0
// Name: unsigned char __near * mySTL::GetArrayMemory<unsigned char>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__cdecl mySTL::GetArrayMemory<unsigned char>(CSplitScreenAddedConVar *sz)
{
  return operator new[](sz, sza: sz);
}

//------------------------------------------------------------------------------
// Address: 0x004214F0
// Name: public: class yaSSL::input_buffer __near * mySTL::list<class yaSSL::input_buffer __near *>::front(void)const
// Source: json
//------------------------------------------------------------------------------
bool (__cdecl *__thiscall mySTL::list<yaSSL::input_buffer *>::front(
        CMasterDlg *this))(const sockaddr_in *, const sockaddr_in *)
{
  bool (__cdecl *result)(const sockaddr_in *, const sockaddr_in *); // eax

  result = this->m_XLSPPortMapping.m_Tree.m_LessFunc.m_LessFunc;
  if ( this->m_XLSPPortMapping.m_Tree.m_LessFunc.m_LessFunc != nullptr )
    return *((bool (__cdecl **)(const sockaddr_in *, const sockaddr_in *))result + 2);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00421500
// Name: class mySTL::list<class yaSSL::SSL_SESSION __near *>::iterator mySTL::find_if<class mySTL::list<class yaSSL::SSL_SESSION __near *>::iterator,struct yaSSL::yassl_int_cpp_local2::sess_match>(class mySTL::list<class yaSSL::SSL_SESSION __near *>::iterator,class mySTL::list<class yaSSL::SSL_SESSION __near *>::iterator,struct yaSSL::yassl_int_cpp_local2::sess_match)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl mySTL::find_if<mySTL::list<yaSSL::SSL_SESSION *>::iterator,yaSSL::yassl_int_cpp_local2::sess_match>(
        _DWORD *a1,
        int a2,
        int a3,
        int a4)
{
  int v4; // edi
  unsigned int v5; // esi
  _DWORD *v6; // edx
  int v7; // eax
  int v8; // eax

  v4 = a2;
  if ( a2 == a3 )
  {
    *a1 = a2;
    return a1;
  }
  else
  {
    do
    {
      v5 = 32;
      yaSSL::sslHashes::get_MD5(this: *(ShortVector **)(v4 + 8));
      v8 = v7 - a4;
      while ( *(_DWORD *)((char *)v6 + v8) == *v6 )
      {
        v5 -= 4;
        ++v6;
        if ( v5 < 4 )
        {
          *a1 = v4;
          return a1;
        }
      }
      v4 = *(_DWORD *)(v4 + 4);
    }
    while ( v4 != a3 );
    *a1 = v4;
    return a1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004215A0
// Name: void yaSSL::ysArrayDelete<unsigned char>(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __stdcall yaSSL::ysArrayDelete<unsigned char>(unsigned __int8 *ptr)
{
  operator delete[]((KeyValues *)ptr, ptra: (KeyValues *)ptr);
}

//------------------------------------------------------------------------------
// Address: 0x004215D0
// Name: public: void yaSSL::SSL::set_pending(unsigned char)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00422500
// Name: public: void yaSSL::SSL::set_random(unsigned char const __near *,enum yaSSL::ConnectionEnd)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::set_random(ShortVector *this, const void *a2, int a3)
{
  int v3; // eax

  yaSSL::sslHashes::get_MD5(this: this + 13);
  if ( a3 == 1 )
    qmemcpy((void *)(v3 + 52), a2, 0x20u);
  else
    qmemcpy((void *)(v3 + 84), a2, 0x20u);
}

//------------------------------------------------------------------------------
// Address: 0x00422530
// Name: public: void yaSSL::SSL::set_preMaster(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::set_preMaster(ShortVector *this, unsigned __int8 *pre, unsigned int sz)
{
  CSplitScreenAddedConVar **v3; // eax
  unsigned __int8 **v4; // esi

  yaSSL::sslHashes::get_MD5(this: this + 13);
  v4 = (unsigned __int8 **)v3;
  yaSSL::Connection::AllocPreSecret(this: v3, sz);
  memcpy(dst: *v4, src: pre, count: sz);
}

//------------------------------------------------------------------------------
// Address: 0x00422560
// Name: public: void yaSSL::SSL::UnSetCompression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::UnSetCompression(ShortVector *this)
{
  int v1; // eax

  yaSSL::sslHashes::get_MD5(this: this + 13);
  *(_BYTE *)(v1 + 301) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422570
// Name: public: bool yaSSL::SSL::CompressionOn(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::SSL::CompressionOn(ShortVector *this)
{
  int v1; // eax

  yaSSL::sslHashes::get_MD5(this: this + 13);
  return *(_BYTE *)(v1 + 301);
}

//------------------------------------------------------------------------------
// Address: 0x00422580
// Name: public: void yaSSL::SSL::set_masterSecret(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::set_masterSecret(ShortVector *this, const LoggingContext_t *sec)
{
  int v2; // eax

  yaSSL::sslHashes::get_MD5(this: this + 13);
  qmemcpy((void *)(v2 + 4), sec, 0x30u);
}

//------------------------------------------------------------------------------
// Address: 0x004225A0
// Name: public: void yaSSL::SSL::set_sessionID(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::set_sessionID(ShortVector *this, const LoggingContext_t *sessionID)
{
  int v2; // eax

  yaSSL::sslHashes::get_MD5(this: this + 13);
  qmemcpy((void *)(v2 + 116), sessionID, 0x20u);
  *(_BYTE *)(v2 + 300) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x004225D0
// Name: private: void yaSSL::SSL::setKeys(void)
// Source: json
//------------------------------------------------------------------------------
st_mysql *__thiscall yaSSL::SSL::setKeys(int this)
{
  int v2; // eax
  int v3; // esi
  char *v4; // ecx
  int v5; // eax
  int v6; // eax
  int v8; // eax
  int v9; // eax

  yaSSL::sslHashes::get_MD5(this: (ShortVector *)(this + 104));
  v3 = v2;
  if ( yaSSL::Security::use_parms(this: v4)->read_query_result == (char (__cdecl *)(st_mysql *))1 )
  {
    yaSSL::SSL_CTX::getCert((CUtlMemory<KeyValues *,int> *)this);
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v5 + 8))(a1: v5, a2: v3 + 188, a3: v3 + 252);
    yaSSL::SSL_CTX::getCert((CUtlMemory<KeyValues *,int> *)this);
    return (*(st_mysql *(__thiscall **)(int, int, int))(*(_DWORD *)v6 + 12))(a1: v6, a2: v3 + 220, a3: v3 + 268);
  }
  else
  {
    yaSSL::SSL_CTX::getCert((CUtlMemory<KeyValues *,int> *)this);
    (*(void (__thiscall **)(int, int, int))(*(_DWORD *)v8 + 8))(a1: v8, a2: v3 + 220, a3: v3 + 268);
    yaSSL::SSL_CTX::getCert((CUtlMemory<KeyValues *,int> *)this);
    return (*(st_mysql *(__thiscall **)(int, int, int))(*(_DWORD *)v9 + 12))(a1: v9, a2: v3 + 188, a3: v3 + 252);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422670
// Name: public: unsigned int yaSSL::SSL::get_SEQIncrement(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall yaSSL::SSL::get_SEQIncrement(ShortVector *this, bool a2)
{
  int v2; // eax
  _DWORD *v3; // ecx

  yaSSL::sslHashes::get_MD5(this: this + 13);
  v3 = (_DWORD *)(v2 + 288);
  if ( !a2 )
    v3 = (_DWORD *)(v2 + 284);
  return (*v3)++;
}

//------------------------------------------------------------------------------
// Address: 0x004226A0
// Name: public: unsigned char const __near * yaSSL::SSL::get_macSecret(bool)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::SSL::get_macSecret(CUtlMemory<KeyValues *,int> *this@<ecx>, KeyValues **verify, int a3)
{
  ShortVector *v3; // ecx

  yaSSL::Security::use_parms(this: (char *)this + 104);
  yaSSL::sslHashes::get_MD5(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x004226E0
// Name: public: void yaSSL::SSL::verifyState(struct yaSSL::RecordLayerHeader const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::verifyState(yaSSL::SSL *this, const struct yaSSL::RecordLayerHeader *a2)
{
  _DWORD *v3; // edx
  _DWORD *v4; // eax

  if ( yaSSL::SSL::GetError((char *)this) == 0 )
  {
    if ( *((_BYTE *)a2 + 4) == 3 && *((_BYTE *)a2 + 5) <= 2u )
    {
      yaSSL::sslHashes::get_MD5(this: (ShortVector *)((char *)this + 2284));
      if ( *v4 == 0 || *v3 == 23 && *(_DWORD *)TaoCrypt::AbstractRing::MultiplicativeGroup() != 3 )
        yaSSL::SSL::SetError(this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6A);
    }
    else
    {
      yaSSL::SSL::SetError(this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x75);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422740
// Name: public: void yaSSL::SSL::verifyState(enum yaSSL::ClientState)
// Source: json
//------------------------------------------------------------------------------
st_mysql *__thiscall yaSSL::SSL::verifyState(char *this, st_mysql *a2)
{
  st_mysql *result; // eax
  int v3; // edx
  _DWORD *v4; // edx

  result = (st_mysql *)yaSSL::SSL::GetError(this);
  if ( result == nullptr )
  {
    result = (st_mysql *)*yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)(v3 + 2284));
    if ( result != a2 )
      return yaSSL::SSL::order_error(this: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422770
// Name: public: void yaSSL::SSL::verifyState(enum yaSSL::ServerState)
// Source: json
//------------------------------------------------------------------------------
matrix3x4a_t *__thiscall yaSSL::SSL::verifyState(char *this, matrix3x4a_t *result)
{
  matrix3x4a_t *Error; // eax
  int v3; // edx
  _DWORD *v4; // edx

  Error = (matrix3x4a_t *)yaSSL::SSL::GetError(this);
  if ( Error == nullptr )
  {
    Error = *(matrix3x4a_t **)yaSSL::States::useServer(this: (char *)(v3 + 2284));
    if ( Error != result )
      return (matrix3x4a_t *)yaSSL::SSL::order_error(this: v4);
  }
  return Error;
}

//------------------------------------------------------------------------------
// Address: 0x004227A0
// Name: public: void yaSSL::SSL::verfiyHandShakeComplete(void)
// Source: json
//------------------------------------------------------------------------------
st_mysql *__thiscall yaSSL::SSL::verfiyHandShakeComplete(char *this)
{
  st_mysql *Error; // eax
  _DWORD *v2; // edx

  Error = (st_mysql *)yaSSL::SSL::GetError(this);
  if ( Error == nullptr )
  {
    Error = (st_mysql *)TaoCrypt::AbstractRing::MultiplicativeGroup();
    if ( Error->net.vio != (struct st_vio *)3 )
      return yaSSL::SSL::order_error(this: v2);
  }
  return Error;
}

//------------------------------------------------------------------------------
// Address: 0x004227D0
// Name: private: void yaSSL::SSL::verifyClientState(enum yaSSL::HandShakeType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::SSL::verifyClientState(CUtlMemory<KeyValues *,int> *this@<ecx>, int hsType, int hsType_4)
{
  int v3; // edx
  bool v4; // zf
  int v5; // eax

  if ( yaSSL::SSL::GetError((char *)this) == 0 )
  {
    switch ( hsType )
    {
      case 2:
        v4 = *yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)(v3 + 2284)) == 0;
        break;
      case 11:
        v4 = *yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)(v3 + 2284)) == 1;
        break;
      case 12:
        v4 = *yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)(v3 + 2284)) == 2;
        break;
      case 13:
      case 14:
        v5 = *yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)(v3 + 2284));
        if ( v5 == 2 )
          return;
        v4 = v5 == 3;
        break;
      case 20:
        if ( *yaSSL::States::useClient(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)(v3 + 2284)) != 4 )
          goto LABEL_11;
        v4 = LOBYTE(yaSSL::Security::use_parms(this: (char *)(v3 + 104))->unbuffered_fetch) == 0;
        break;
      default:
        goto LABEL_11;
    }
    if ( !v4 )
LABEL_11:
      yaSSL::SSL::order_error(this: (_DWORD *)v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004228A0
// Name: private: void yaSSL::SSL::verifyServerState(enum yaSSL::HandShakeType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::SSL::verifyServerState(CUtlMemory<KeyValues *,int> *this@<ecx>, int hsType, int hsType_4)
{
  int v3; // edx
  bool v4; // zf

  if ( yaSSL::SSL::GetError((char *)this) == 0 )
  {
    switch ( hsType )
    {
      case 1:
        v4 = *(_DWORD *)yaSSL::States::useServer(this: (char *)(v3 + 2284)) == 0;
        goto LABEL_8;
      case 11:
      case 16:
        v4 = *(_DWORD *)yaSSL::States::useServer(this: (char *)(v3 + 2284)) == 1;
        goto LABEL_8;
      case 15:
        v4 = *(_DWORD *)yaSSL::States::useServer(this: (char *)(v3 + 2284)) == 2;
        goto LABEL_8;
      case 20:
        if ( *(_DWORD *)yaSSL::States::useServer(this: (char *)(v3 + 2284)) != 2 )
          goto LABEL_9;
        v4 = LOBYTE(yaSSL::Security::use_parms(this: (char *)(v3 + 104))->unbuffered_fetch) == 0;
LABEL_8:
        if ( !v4 )
LABEL_9:
          yaSSL::SSL::order_error(this: (_DWORD *)v3);
        break;
      default:
        goto LABEL_9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422950
// Name: public: void yaSSL::SSL::matchSuite(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::matchSuite(yaSSL::SSL *this, const LoggingContext_t *peer, unsigned int length)
{
  unsigned int v3; // esi
  yaSSL::SSL *v4; // edx
  char *v5; // ecx
  unsigned int v6; // ebp
  char v7; // al
  unsigned int v8; // edx
  const st_mysql_methods *v9; // eax
  int v10; // edx

  if ( length == 0 || (length & 1) != 0 )
  {
    yaSSL::SSL::SetError(this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6D);
  }
  else
  {
    v3 = 1;
    v6 = BYTE2(yaSSL::Security::use_parms(this: (char *)this + 104)->free_embedded_thd);
    if ( v6 <= 1 )
    {
LABEL_10:
      yaSSL::SSL::SetError(this: v4, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6E);
    }
    else
    {
      while ( length <= 1 )
      {
LABEL_8:
        v3 += 2;
        if ( v3 >= v6 )
        {
          v4 = this;
          goto LABEL_10;
        }
      }
      v7 = *((_BYTE *)&yaSSL::Security::use_parms(this: v5)->free_embedded_thd + v3 + 3);
      while ( v7 != *((_BYTE *)&peer->m_ChannelID + v8) )
      {
        v8 += 2;
        if ( v8 >= length )
          goto LABEL_8;
      }
      v9 = yaSSL::Security::use_parms(this: v5);
      LOBYTE(v9->free_embedded_thd) = 0;
      BYTE1(v9->free_embedded_thd) = *((_BYTE *)&peer->m_ChannelID + v10);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004229E0
// Name: public: bool yaSSL::SSL::GetMultiProtocol(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::SSL::GetMultiProtocol(int this)
{
  yaSSL::SSL_CTX *Context; // eax
  yaSSL::SSL_METHOD *Method; // eax

  Context = (yaSSL::SSL_CTX *)yaSSL::Security::GetContext(this: (yaSSL::Security *)(this + 104));
  Method = (yaSSL::SSL_METHOD *)yaSSL::SSL_CTX::getMethod(this: Context);
  return yaSSL::SSL_METHOD::multipleProtocol(this: Method);
}

//------------------------------------------------------------------------------
// Address: 0x00422A00
// Name: public: bool yaSSL::SSL::isTLS(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::SSL::isTLS(ShortVector *this)
{
  int v1; // eax

  yaSSL::sslHashes::get_MD5(this: this + 13);
  return *(_BYTE *)(v1 + 298);
}

//------------------------------------------------------------------------------
// Address: 0x00422A10
// Name: public: bool yaSSL::SSL::isTLSv1_1(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall yaSSL::SSL::isTLSv1_1(ShortVector *this)
{
  int v1; // eax

  yaSSL::sslHashes::get_MD5(this: this + 13);
  return *(_BYTE *)(v1 + 299);
}

//------------------------------------------------------------------------------
// Address: 0x00422A20
// Name: public: yaSSL::X509_NAME::~X509_NAME(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::X509_NAME::~X509_NAME(yaSSL::X509_NAME *this)
{
  yaSSL::ysArrayDelete<unsigned char>(ptr: *(unsigned __int8 **)this);
  yaSSL::ysArrayDelete<unsigned char>(ptr: *((unsigned __int8 **)this + 4));
}

//------------------------------------------------------------------------------
// Address: 0x00422A40
// Name: public: struct yaSSL::ASN1_STRING __near * yaSSL::X509::GetBefore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::X509::GetBefore(_LocaleUpdate *this)
{
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)this + 5);
}

//------------------------------------------------------------------------------
// Address: 0x00422A50
// Name: public: struct yaSSL::ASN1_STRING __near * yaSSL::X509::GetAfter(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::X509::GetAfter(_LocaleUpdate *this)
{
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)((char *)this + 52));
}

//------------------------------------------------------------------------------
// Address: 0x00422A70
// Name: public: void mySTL::list<struct yaSSL::ThreadError>::push_back(struct yaSSL::ThreadError)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::list<yaSSL::ThreadError>::push_back(
        ICommandLine *this,
        ICommandLine *t,
        const char *(__thiscall *a3)(ICommandLine *this, const char *, const char **))
{
  ICommandLine_vtbl *Array; // eax
  int v5; // ecx

  Array = (ICommandLine_vtbl *)mySTL::GetArrayMemory<unsigned char>(sz: (CSplitScreenAddedConVar *)0x10);
  if ( Array != nullptr )
  {
    Array->CreateCmdLine = nullptr;
    Array->CreateCmdLine_2 = nullptr;
    Array->GetCmdLine = (const char *(__thiscall *)(ICommandLine *))t;
    Array->CheckParm = a3;
  }
  else
  {
    Array = nullptr;
  }
  v5 = *((_DWORD *)this + 1);
  if ( v5 != 0 )
  {
    *(_DWORD *)(v5 + 4) = Array;
    Array->CreateCmdLine = (void (__thiscall *)(ICommandLine *, int, char **))*(this + 1);
    ++*((_DWORD *)this + 2);
  }
  else
  {
    ++*((_DWORD *)this + 2);
    this->__vftable = Array;
  }
  *((_DWORD *)this + 1) = Array;
}

//------------------------------------------------------------------------------
// Address: 0x00422B20
// Name: struct yaSSL::yassl_int_cpp_local1::SumData mySTL::for_each<class mySTL::list<class yaSSL::input_buffer __near *>::iterator,struct yaSSL::yassl_int_cpp_local1::SumData>(class mySTL::list<class yaSSL::input_buffer __near *>::iterator,class mySTL::list<class yaSSL::input_buffer __near *>::iterator,struct yaSSL::yassl_int_cpp_local1::SumData)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00422BA0
// Name: struct yaSSL::yassl_int_cpp_local1::SumBuffer mySTL::for_each<class mySTL::list<class yaSSL::output_buffer __near *>::iterator,struct yaSSL::yassl_int_cpp_local1::SumBuffer>(class mySTL::list<class yaSSL::output_buffer __near *>::iterator,class mySTL::list<class yaSSL::output_buffer __near *>::iterator,struct yaSSL::yassl_int_cpp_local1::SumBuffer)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__cdecl mySTL::for_each<mySTL::list<yaSSL::output_buffer *>::iterator,yaSSL::yassl_int_cpp_local1::SumBuffer>(
        _DWORD *a1,
        int a2,
        int a3,
        IBaseInterface *const op)
{
  int v4; // eax

  v4 = a2;
  if ( a2 == a3 )
  {
    *a1 = op;
    return a1;
  }
  else
  {
    do
    {
      op = (IBaseInterface *const)((char *)op + (_DWORD)yaSSL::SSL_CTX::getMethod(this: *(yaSSL::SSL_CTX **)(v4 + 8)));
      v4 = *(_DWORD *)(a2 + 4);
      a2 = v4;
    }
    while ( v4 != a3 );
    *a1 = op;
    return a1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422C20
// Name: class mySTL::list<struct yaSSL::ThreadError>::iterator mySTL::find_if<class mySTL::list<struct yaSSL::ThreadError>::iterator,struct yaSSL::yassl_int_cpp_local2::thr_match>(class mySTL::list<struct yaSSL::ThreadError>::iterator,class mySTL::list<struct yaSSL::ThreadError>::iterator,struct yaSSL::yassl_int_cpp_local2::thr_match)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> *__cdecl mySTL::find_if<mySTL::list<yaSSL::ThreadError>::iterator,yaSSL::yassl_int_cpp_local2::thr_match>(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> *result,
        UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *last,
        UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *last_4,
        int last_8)
{
  UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *i; // ecx

  for ( i = last; i != last_4; i = (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)i->m_Right )
  {
    if ( i->m_Parent == last_8 )
      break;
  }
  result->m_pMemory = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422C80
// Name: private: void yaSSL::SSL::storeKeys(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::storeKeys(yaSSL::SSL *this, unsigned __int8 *key_data)
{
  const st_mysql_methods *v2; // ebp
  unsigned int flush_use_result_low; // edi
  ShortVector *v4; // ecx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // esi
  unsigned int use_result_low; // ebp
  unsigned int v8; // edi
  unsigned int v9; // edi
  unsigned int v10; // ebp
  const st_mysql_methods *v11; // [esp+10h] [ebp-8h]

  v2 = yaSSL::Security::use_parms(this: (char *)this + 104);
  flush_use_result_low = LOBYTE(v2->flush_use_result);
  v11 = v2;
  yaSSL::sslHashes::get_MD5(this: v4);
  v6 = v5;
  memcpy(dst: v5 + 148, src: key_data, count: flush_use_result_low);
  memcpy(dst: v6 + 168, src: &key_data[flush_use_result_low], count: flush_use_result_low);
  use_result_low = LOBYTE(v2->use_result);
  flush_use_result_low *= 2;
  memcpy(dst: v6 + 188, src: &key_data[flush_use_result_low], count: use_result_low);
  v8 = use_result_low + flush_use_result_low;
  memcpy(dst: v6 + 220, src: &key_data[v8], count: use_result_low);
  v9 = use_result_low + v8;
  v10 = BYTE1(v11->use_result);
  memcpy(dst: v6 + 252, src: &key_data[v9], count: v10);
  memcpy(dst: v6 + 268, src: &key_data[v10 + v9], count: v10);
  yaSSL::SSL::setKeys((int)this);
}

//------------------------------------------------------------------------------
// Address: 0x00422D40
// Name: public: unsigned int yaSSL::SSL::bufferedData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::bufferedData(CUtlMemory<KeyValues *,int> *this)
{
  const IBaseInterface *v1; // ecx

  yaSSL::sslHashes::get_MD5(this: (ShortVector *)this + 312);
  mySTL::for_each<mySTL::list<yaSSL::input_buffer *>::iterator,yaSSL::yassl_int_cpp_local1::SumData>(first: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00422D70
// Name: public: void yaSSL::SSL::PeekData(class yaSSL::Data __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::SSL::PeekData(int a1@<ecx>, int *a2@<esi>, CUtlCharConversion *elements)
{
  unsigned int v5; // ebp
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  int *v9; // eax
  int v10; // edi
  unsigned int v11; // eax
  __int16 v12; // bx
  const CUtlMemory<KeyValues *,int>::Iterator_t *v13; // eax
  int length; // eax
  __int16 v15; // ax
  bool v16; // zf
  int v18; // [esp-Ch] [ebp-18h]
  int *v19; // [esp-Ch] [ebp-18h]
  int v20; // [esp-Ch] [ebp-18h]
  int v21; // [esp+4h] [ebp-8h]
  const CUtlMemory<KeyValues *,int>::Iterator_t *before; // [esp+8h] [ebp-4h]
  unsigned int elementsa; // [esp+10h] [ebp+4h]

  if ( yaSSL::SSL::GetError(this: (char *)a1) == 0 )
  {
    v5 = ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))elements->__vftable[4].FindConversion)(a1: elements);
    yaSSL::sslHashes::get_MD5(this: (ShortVector *)(a1 + 2496));
    elementsa = *(_DWORD *)(v6 + 8);
    yaSSL::Data::set_length(this: elements, l: nullptr, a3: a2);
    yaSSL::SSL::bufferedData(this: (CUtlMemory<KeyValues *,int> *)a1);
    if ( v5 >= v7 )
    {
      yaSSL::SSL::bufferedData(this: (CUtlMemory<KeyValues *,int> *)a1);
      v5 = v8;
    }
    yaSSL::sslHashes::get_MD5(this: (ShortVector *)(a1 + 2496));
    v10 = *v9;
    if ( elementsa != 0 )
    {
      do
      {
        yaSSL::input_buffer::get_remaining(this: *(CUtlString **)(v10 + 8), a2: v18);
        v12 = v11;
        if ( v5
           - ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))elements->__vftable[4].FindConversion)(a1: elements) < v11 )
          v12 = v5 - ((int (__thiscall *)(CUtlCharConversion *))elements->__vftable[4].FindConversion)(a1: elements);
        yaSSL::SSL_CTX::getCert(this: *(CUtlMemory<KeyValues *,int> **)(v10 + 8));
        before = v13;
        v21 = ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))elements->__vftable[4].FindConversion)(a1: elements);
        length = yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)elements);
        yaSSL::input_buffer::read(this: *(CUtlString **)(v10 + 8), dst: (const char *)(v21 + length));
        v15 = ((int (__thiscall *)(CUtlCharConversion *))elements->__vftable[4].FindConversion)(a1: elements);
        yaSSL::Data::set_length(this: elements, l: (const char *)(unsigned __int16)(v12 + v15), a3: v19);
        yaSSL::Crypto::setCipher(this: *(CUtlString **)(v10 + 8), i: before, a3: v20);
        if ( ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))elements->__vftable[4].FindConversion)(a1: elements) == v5 )
          break;
        v16 = elementsa-- == 1;
        v10 = *(_DWORD *)(v10 + 4);
      }
      while ( !v16 );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422E90
// Name: public: void yaSSL::SSL::verifyState(class yaSSL::HandShakeHeader const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::verifyState(yaSSL::SSL *this, CUtlMemory<KeyValues *,int> *hsHeader)
{
  int v3; // eax
  int v4; // eax
  int v5; // [esp+0h] [ebp-4h]

  if ( yaSSL::SSL::GetError((char *)this) == 0 )
  {
    if ( *(_DWORD *)TaoCrypt::AbstractRing::MultiplicativeGroup() != 0 )
    {
      if ( yaSSL::Security::use_parms(this: (char *)this + 104)->read_query_result == (char (__cdecl *)(st_mysql *))1 )
      {
        yaSSL::SSL_CTX::getCert(this: hsHeader);
        yaSSL::SSL::verifyClientState((CUtlMemory<KeyValues *,int> *)this, hsType: v3, hsType_4: v5);
      }
      else
      {
        yaSSL::SSL_CTX::getCert(this: hsHeader);
        yaSSL::SSL::verifyServerState((CUtlMemory<KeyValues *,int> *)this, hsType: v4, hsType_4: v5);
      }
    }
    else
    {
      yaSSL::SSL::SetError(this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6B);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422EF0
// Name: public: void yaSSL::SSL::addData(class yaSSL::input_buffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::addData(ShortVector *this, sockaddr *a2)
{
  _DWORD *v3; // eax

  yaSSL::sslHashes::get_MD5(this: this + 312);
  mySTL::list<yaSSL::x509 *>::push_back(this: v3, result: a2);
  if ( *((_BYTE *)this + 2526) == 0 )
    *((_BYTE *)this + 2526) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00422F20
// Name: public: void yaSSL::SSL::addBuffer(class yaSSL::output_buffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::addBuffer(yaSSL::SSL *this, sockaddr *result)
{
  char *v2; // eax

  v2 = yaSSL::States::useServer(this: (char *)this + 2496);
  mySTL::list<yaSSL::x509 *>::push_back(this: v2, result);
}

//------------------------------------------------------------------------------
// Address: 0x00422F40
// Name: public: void yaSSL::SSL_CTX::AddCA(class yaSSL::x509 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_CTX::AddCA(yaSSL::SSL_CTX *this, sockaddr *a2)
{
  mySTL::list<yaSSL::x509 *>::push_back(this: this + 3, result: a2);
}

//------------------------------------------------------------------------------
// Address: 0x00422F50
// Name: public: yaSSL::Crypto::~Crypto(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Crypto::~Crypto(yaSSL::Crypto *this)
{
  KeyValues *v2; // ecx

  yaSSL::ysDelete<yaSSL::DiffieHellman>(result: *((CDatamapFieldSizeDeducer<17>::<unnamed_tag> **)this + 2));
  yaSSL::ysDelete<yaSSL::BulkCipher>(
    ptr: *((KeyValues **)this + 1),
    ptra: *((const CUtlMemory<KeyValues *,int>::Iterator_t **)this + 1));
  yaSSL::ysDelete<yaSSL::Digest>(ptr: v2, a2: (int)*this);
  yaSSL::CertManager::~CertManager(this: (ShortVector *)this + 2);
  yaSSL::RandomPool::~RandomPool(this: (yaSSL::RandomPool *)this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x00422F90
// Name: public: yaSSL::X509::X509(char const __near *,unsigned int,char const __near *,unsigned int,char const __near *,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
yaSSL::X509 *__thiscall yaSSL::X509::X509(
        yaSSL::X509 *this,
        char *a2,
        const CSplitScreenAddedConVar *a3,
        char *a4,
        const CSplitScreenAddedConVar *a5,
        char *str,
        char *sz,
        char *a8,
        char *a9)
{
  int v11; // [esp+0h] [ebp-4h]
  int v12; // [esp+0h] [ebp-4h]

  yaSSL::X509_NAME::X509_NAME((CSplitScreenAddedConVar *)this, n: (unsigned __int8 *)a2, sz: a3);
  yaSSL::X509_NAME::X509_NAME(this: (CSplitScreenAddedConVar *)((char *)this + 20), n: (unsigned __int8 *)a4, sz: a5);
  yaSSL::StringHolder::StringHolder(this: (IMemAlloc *)this + 10, (unsigned __int8 *)str, sz, a4: v11);
  yaSSL::StringHolder::StringHolder(this: (IMemAlloc *)this + 13, str: (unsigned __int8 *)a8, sz: a9, a4: v12);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423000
// Name: public: void mySTL::list<class yaSSL::input_buffer __near *>::pop_front(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::list<yaSSL::input_buffer *>::pop_front(ICommandLine *this)
{
  ICommandLine *v1; // esi
  ICommandLine_vtbl *v2; // eax

  v1 = this;
  v2 = this->__vftable;
  if ( this->__vftable != nullptr )
  {
    if ( v2 == *((ICommandLine_vtbl **)this + 1) )
    {
      *((_DWORD *)this + 1) = 0;
    }
    else
    {
      this = (ICommandLine *)v2->CreateCmdLine_2;
      v1->__vftable = (ICommandLine_vtbl *)this;
    }
    this->__vftable = nullptr;
    mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>();
    --v1[2].__vftable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423050
// Name: public: void mySTL::list<class yaSSL::SSL_SESSION __near *>::pop_back(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::list<yaSSL::SSL_SESSION *>::pop_back(ICommandLine *this)
{
  ICommandLine *v1; // esi
  ICommandLine **v2; // eax

  v1 = this;
  v2 = *((ICommandLine ***)this + 1);
  if ( v2 != nullptr )
  {
    if ( v2 == (ICommandLine **)this->__vftable )
    {
      this->__vftable = nullptr;
    }
    else
    {
      this = *v2;
      v1[1].__vftable = (ICommandLine_vtbl *)*v2;
    }
    *((_DWORD *)this + 1) = 0;
    mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>();
    --v1[2].__vftable;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423090
// Name: public: void yaSSL::SSL::deriveKeys(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::deriveKeys(int this)
{
  ShortVector *v1; // esi
  unsigned __int8 *v2; // eax
  int v3; // ebx
  int v4; // eax
  int length; // eax
  unsigned __int8 *v6; // eax
  _BYTE *v7; // [esp-4h] [ebp-124h]
  const char *v8; // [esp+0h] [ebp-120h]
  int v9; // [esp+10h] [ebp-110h]
  int rounds; // [esp+14h] [ebp-10Ch]
  int v11; // [esp+18h] [ebp-108h]
  float *sha; // [esp+20h] [ebp-100h] BYREF
  int v14; // [esp+28h] [ebp-F8h]
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > md5; // [esp+2Ch] [ebp-F4h] BYREF
  Vector2D v16; // [esp+44h] [ebp-DCh] BYREF
  int v17; // [esp+4Ch] [ebp-D4h]
  int v18; // [esp+50h] [ebp-D0h]
  int v19; // [esp+54h] [ebp-CCh]
  LoggingContext_t v20[3]; // [esp+58h] [ebp-C8h] BYREF
  Vector2D v21; // [esp+88h] [ebp-98h]
  int v22; // [esp+90h] [ebp-90h]
  int v23; // [esp+94h] [ebp-8Ch]
  int v24; // [esp+98h] [ebp-88h]
  LoggingContext_t v25; // [esp+A0h] [ebp-80h] BYREF
  _BYTE v26[75]; // [esp+D1h] [ebp-4Fh] BYREF

  v1 = (ShortVector *)(this + 104);
  v2 = (unsigned __int8 *)yaSSL::Security::use_parms(this: (char *)(this + 104));
  rounds = (2 * (v2[12] + v2[13] + v2[20]) + 15) / 16;
  yaSSL::input_buffer::input_buffer(result: (const CUtlString *)(16 * rounds));
  yaSSL::MD5::MD5(this: (KeyValues **)&md5);
  yaSSL::SHA::SHA(this: (Vector2D *)&sha);
  yaSSL::sslHashes::get_MD5(this: v1);
  v3 = 0;
  v11 = v4;
  qmemcpy((void *)v20, (const void *)(v4 + 4), sizeof(v20));
  if ( rounds != 0 )
  {
    v14 = 113 - (_DWORD)v26;
    while ( yaSSL::_anonymous_namespace_::setPrefix(a1: &v25, a2: v3) != 0 )
    {
      qmemcpy((char *)&v25.m_ChannelID + v3 + 1, (const void *)(v11 + 4), 0x30u);
      qmemcpy(&v26[v3], (const void *)(v11 + 84), 0x20u);
      v7 = &v26[v3 + v14];
      qmemcpy(&v26[v3 + 32], (const void *)(v11 + 52), 0x20u);
      yaSSL::MD5::get_digest(this: (_DWORD **)&sha, result: &v16, in: &v25, sz: (unsigned int)v7);
      v22 = v17;
      v21 = v16;
      v23 = v18;
      v24 = v19;
      length = yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&md5.m_Memory.m_nGrowSize);
      yaSSL::MD5::get_digest(this: &md5.m_Memory.m_pMemory, result: (Vector2D *)(v9 + length), in: v20, sz: 0x44u);
      if ( ++v3 >= rounds )
        goto LABEL_5;
    }
    yaSSL::SSL::SetError((_DWORD *)this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x69);
  }
  else
  {
LABEL_5:
    v6 = (unsigned __int8 *)yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&md5.m_Memory.m_nGrowSize);
    yaSSL::SSL::storeKeys((yaSSL::SSL *)this, key_data: v6);
  }
  yaSSL::SHA::~SHA(this: (Vector2D *)&sha);
  yaSSL::MD5::~MD5(this: &md5);
  yaSSL::input_buffer::~input_buffer(this: (CUtlString *)&md5.m_Memory.m_nGrowSize, a2: v8);
}

//------------------------------------------------------------------------------
// Address: 0x00423270
// Name: public: void yaSSL::SSL::deriveTLSKeys(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall yaSSL::SSL::deriveTLSKeys(char *this)
{
  ShortVector *v2; // esi
  unsigned __int8 *v3; // eax
  const CUtlString *v4; // ebx
  int v5; // eax
  int length; // eax
  void *v7; // ecx
  unsigned __int8 *v8; // eax
  const char *v9; // [esp+0h] [ebp-64h]
  CUtlString v10; // [esp+10h] [ebp-54h] BYREF
  _BYTE seed[32]; // [esp+20h] [ebp-44h] OVERLAPPED BYREF
  _BYTE v12[32]; // [esp+40h] [ebp-24h] BYREF

  v2 = (ShortVector *)(this + 104);
  v3 = (unsigned __int8 *)yaSSL::Security::use_parms(this: this + 104);
  v4 = (const CUtlString *)(2 * (v3[12] + v3[13] + v3[20]));
  yaSSL::input_buffer::input_buffer(result: v4);
  yaSSL::sslHashes::get_MD5(this: v2);
  qmemcpy(seed, (const void *)(v5 + 84), sizeof(seed));
  qmemcpy(v12, (const void *)(v5 + 52), sizeof(v12));
  length = yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v10);
  yaSSL::PRF(digest: v7, digLen: length, secret: (int)v4);
  v8 = (unsigned __int8 *)yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v10);
  yaSSL::SSL::storeKeys((yaSSL::SSL *)this, key_data: v8);
  yaSSL::input_buffer::~input_buffer(this: &v10, a2: v9);
}

//------------------------------------------------------------------------------
// Address: 0x00423330
// Name: public: void yaSSL::SSL::fillData(class yaSSL::Data __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::SSL::fillData(int a1@<ecx>, int *a2@<edi>, CUtlCharConversion *dataSz)
{
  int v3; // ebp
  unsigned int v5; // edi
  CMasterDlg *v6; // eax
  CMasterDlg *v7; // ebx
  unsigned int v8; // eax
  unsigned int v9; // eax
  bool (__cdecl *v10)(const sockaddr_in *, const sockaddr_in *); // ebp
  unsigned int v11; // eax
  unsigned int v12; // ebx
  unsigned int v13; // edi
  int length; // eax
  __int16 v15; // ax
  ICommandLine *v16; // eax
  int v18; // [esp-Ch] [ebp-24h]
  int *v19; // [esp-Ch] [ebp-24h]
  unsigned int i; // [esp+4h] [ebp-14h]
  unsigned int elements; // [esp+8h] [ebp-10h]
  CMasterDlg *v23; // [esp+10h] [ebp-8h]
  int v24; // [esp+14h] [ebp-4h]
  unsigned int dataSza; // [esp+1Ch] [ebp+4h]

  v3 = a1;
  if ( yaSSL::SSL::GetError(this: (char *)a1) == 0 )
  {
    v5 = ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))dataSz->__vftable[4].FindConversion)(a1: dataSz);
    dataSza = v5;
    yaSSL::sslHashes::get_MD5(this: (ShortVector *)(v3 + 2496));
    v7 = v6;
    v23 = v6;
    elements = v6->m_XLSPPortMapping.m_Tree.m_Elements.m_nAllocationCount;
    yaSSL::Data::set_length(this: dataSz, l: nullptr, a3: a2);
    yaSSL::SSL::bufferedData(this: (CUtlMemory<KeyValues *,int> *)v3);
    if ( v5 >= v8 )
    {
      yaSSL::SSL::bufferedData(this: (CUtlMemory<KeyValues *,int> *)v3);
      dataSza = v9;
      v5 = v9;
    }
    i = 0;
    if ( elements != 0 )
    {
      while ( 1 )
      {
        v10 = mySTL::list<yaSSL::input_buffer *>::front(this: v7);
        yaSSL::input_buffer::get_remaining(this: (CUtlString *)v10, a2: v18);
        v12 = v11;
        v13 = v5
            - ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))dataSz->__vftable[4].FindConversion)(a1: dataSz) >= v11
            ? v12
            : v5
            - ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))dataSz->__vftable[4].FindConversion)(a1: dataSz);
        v24 = ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))dataSz->__vftable[4].FindConversion)(a1: dataSz);
        length = yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)dataSz);
        yaSSL::input_buffer::read(this: (CUtlString *)v10, dst: (const char *)(v24 + length));
        v15 = ((int (__thiscall *)(CUtlCharConversion *))dataSz->__vftable[4].FindConversion)(a1: dataSz);
        yaSSL::Data::set_length(this: dataSz, l: (const char *)(unsigned __int16)(v13 + v15), a3: v19);
        if ( v13 == v12 )
        {
          yaSSL::sslHashes::get_MD5(this: (ShortVector *)(a1 + 2496));
          mySTL::list<yaSSL::input_buffer *>::pop_front(this: v16);
          yaSSL::ysDelete<yaSSL::input_buffer>(result: (CUtlString *)v10);
        }
        if ( ((unsigned __int16 (__thiscall *)(CUtlCharConversion *))dataSz->__vftable[4].FindConversion)(a1: dataSz) == dataSza )
          break;
        if ( ++i >= elements )
          break;
        v5 = dataSza;
        v7 = v23;
      }
      v3 = a1;
      v7 = v23;
    }
    if ( v7->m_XLSPPortMapping.m_Tree.m_Elements.m_nAllocationCount == 0 )
      *(_BYTE *)(v3 + 2526) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004234A0
// Name: public: void yaSSL::SSL::flushBuffer(void)
// Source: json
//------------------------------------------------------------------------------
st_mysql *__usercall yaSSL::SSL::flushBuffer@<eax>(char *a1@<ecx>, QueuedPacket_t *const *a2@<edi>)
{
  char *v2; // ebp
  st_mysql *Error; // eax
  int *v4; // edi
  IBaseInterface *const v5; // edx
  unsigned int *v6; // eax
  char *v7; // ebp
  int v8; // edx
  int v9; // ebx
  bool (__cdecl *v10)(const sockaddr_in *, const sockaddr_in *); // esi
  const unsigned __int8 *v11; // eax
  KeyValues *v12; // ecx
  const LoggingContext_t *v13; // eax
  const struct SSL_METHOD *Method; // [esp-10h] [ebp-28h]
  const struct SSL_METHOD *v15; // [esp-10h] [ebp-28h]
  int v18; // [esp+8h] [ebp-10h] BYREF
  CUtlMemory<KeyValues *,int> v19; // [esp+Ch] [ebp-Ch] BYREF

  v2 = a1;
  Error = (st_mysql *)yaSSL::SSL::GetError(this: a1);
  if ( Error == nullptr )
  {
    v4 = (int *)yaSSL::States::useServer(this: v2 + 2496);
    v6 = mySTL::for_each<mySTL::list<yaSSL::output_buffer *>::iterator,yaSSL::yassl_int_cpp_local1::SumBuffer>(
           a1: &v18,
           a2: *v4,
           a3: 0,
           op: v5);
    yaSSL::output_buffer::output_buffer(this: (yaSSL::output_buffer *)&v19, a2: *v6);
    if ( v4[2] != 0 )
    {
      v7 = yaSSL::States::useServer(this: v2 + 2496);
      v9 = v8;
      do
      {
        v10 = mySTL::list<yaSSL::input_buffer *>::front(this: (CMasterDlg *)v4);
        Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v10);
        yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)v10);
        yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)&v19, src: v11, a3: (unsigned int)Method);
        mySTL::list<yaSSL::input_buffer *>::pop_front(this: (ICommandLine *)v7);
        yaSSL::ysDelete<yaSSL::x509>(
          ptr: v12,
          ptra: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v10);
        --v9;
      }
      while ( v9 != 0 );
      v2 = a1;
    }
    v15 = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v19);
    yaSSL::SSL_CTX::getCert(this: &v19);
    yaSSL::SSL::Send(this: (yaSSL::SSL *)v2, buffer: v13, sz: (unsigned int)v15);
    return (st_mysql *)yaSSL::x509::~x509(
                         this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v19,
                         a2);
  }
  return Error;
}

//------------------------------------------------------------------------------
// Address: 0x00423570
// Name: private: void yaSSL::SSL_SESSION::CopyX509(class yaSSL::X509 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_SESSION::CopyX509(yaSSL::SSL_SESSION *this, ShortVector *a2)
{
  CUtlMemory<KeyValues *,int> *v2; // eax
  CUtlMemory<KeyValues *,int> *v3; // esi
  yaSSL::X509 *v4; // ecx
  CUtlMemory<KeyValues *,int> *Subject; // edi
  _LocaleUpdate *v6; // ecx
  int v7; // eax
  int v8; // ebx
  _LocaleUpdate *v9; // edx
  int v10; // eax
  int v11; // ebp
  const CSplitScreenAddedConVar *v12; // ecx
  const CSplitScreenAddedConVar *v13; // eax
  yaSSL::SSL_CTX *v14; // ecx
  const CSplitScreenAddedConVar *v15; // eax
  yaSSL::SSL_CTX *v16; // ecx
  char *v17; // eax
  yaSSL::X509 *v18; // edx
  const CSplitScreenAddedConVar *v19; // [esp-2Ch] [ebp-30h]
  char *Method; // [esp-28h] [ebp-2Ch]
  const CSplitScreenAddedConVar *v21; // [esp-24h] [ebp-28h]
  char *v22; // [esp-20h] [ebp-24h]
  char *v23; // [esp-1Ch] [ebp-20h]
  char *v24; // [esp-18h] [ebp-1Ch]
  char *v25; // [esp-14h] [ebp-18h]

  if ( a2 != nullptr )
  {
    yaSSL::sslHashes::get_MD5(this: a2);
    v3 = v2;
    Subject = (CUtlMemory<KeyValues *,int> *)yaSSL::X509::GetSubject(this: v4);
    yaSSL::X509::GetBefore(this: v6);
    v8 = v7;
    yaSSL::X509::GetAfter(this: v9);
    v11 = v10;
    if ( operator new(sz: v12, sza: 0x40u) != nullptr )
    {
      v25 = *(char **)(v11 + 4);
      v24 = *(char **)(v11 + 8);
      v23 = *(char **)(v8 + 4);
      v22 = *(char **)(v8 + 8);
      yaSSL::SSL_CTX::getCert(this: Subject);
      v21 = v13;
      Method = (char *)yaSSL::SSL_CTX::getMethod(this: v14);
      yaSSL::SSL_CTX::getCert(this: v3);
      v19 = v15;
      v17 = (char *)yaSSL::SSL_CTX::getMethod(this: v16);
      *((_DWORD *)this + 24) = yaSSL::X509::X509(
                                 this: v18,
                                 a2: v17,
                                 a3: v19,
                                 a4: Method,
                                 a5: v21,
                                 str: v22,
                                 sz: v23,
                                 a8: v24,
                                 a9: v25);
    }
    else
    {
      *((_DWORD *)this + 24) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423610
// Name: public: yaSSL::SSL_SESSION::SSL_SESSION(class yaSSL::SSL const __near &,class yaSSL::RandomPool __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::SSL_SESSION::SSL_SESSION(QAngle *this@<ecx>, char *ssl, float ran, float ran_4)
{
  ShortVector *v5; // eax
  int v6; // eax
  char *v7; // edx
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v8; // eax
  KeyValues ***certManager; // eax
  ShortVector *peerX509; // eax
  yaSSL *v11; // [esp+0h] [ebp-10h]

  *((_DWORD *)this + 22) = 500;
  *((float *)this + 23) = ran;
  *((_DWORD *)this + 24) = 0;
  v5 = (ShortVector *)yaSSL::SSL::useSecurity(this: ssl);
  yaSSL::sslHashes::get_MD5(this: v5);
  qmemcpy(this, (const void *)(v6 + 116), 0x20u);
  qmemcpy((char *)this + 32, (const void *)(v6 + 4), 0x30u);
  *((_WORD *)this + 40) = yaSSL::Security::use_parms(this: v7)->free_embedded_thd;
  *((_DWORD *)this + 21) = yaSSL::lowResTimer(this: v11);
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)ssl);
  certManager = yaSSL::Crypto::get_certManager(this: v8);
  peerX509 = (ShortVector *)yaSSL::CertManager::get_peerX509(this: (yaSSL::CertManager *)certManager);
  yaSSL::SSL_SESSION::CopyX509((yaSSL::SSL_SESSION *)this, a2: peerX509);
}

//------------------------------------------------------------------------------
// Address: 0x004236A0
// Name: class yaSSL::Sessions __near & yaSSL::GetSessions(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::GetSessions(const CSplitScreenAddedConVar *ecx0)
{
  CSplitScreenAddedConVar *result; // eax
  CSplitScreenAddedConVar *v2; // eax
  CSplitScreenAddedConVar *v3; // esi

  result = *(CSplitScreenAddedConVar **)&sessionsInstance[0].adr.sin_family;
  if ( *(_DWORD *)&sessionsInstance[0].adr.sin_family == 0 )
  {
    v2 = operator new(sz: ecx0, sza: 0x18u);
    v3 = v2;
    if ( v2 != nullptr )
    {
      v2->ConVar::ConCommandBase::__vftable = nullptr;
      v2->m_pNext = nullptr;
      *(_DWORD *)&v2->m_bRegistered = 0;
      yaSSL::RandomPool::RandomPool(this: (yaSSL::RandomPool *)&v2->m_pszName);
      v3->m_nFlags = 0;
      *(_DWORD *)&sessionsInstance[0].adr.sin_family = v3;
      return v3;
    }
    else
    {
      *(_DWORD *)&sessionsInstance[0].adr.sin_family = 0;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423700
// Name: class yaSSL::Errors __near & yaSSL::GetErrors(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::GetErrors(const CSplitScreenAddedConVar *ecx0)
{
  CSplitScreenAddedConVar *result; // eax

  result = *(CSplitScreenAddedConVar **)&errorsInstance.sin_family;
  if ( *(_DWORD *)&errorsInstance.sin_family == 0 )
  {
    result = operator new(sz: ecx0, sza: 0x10u);
    if ( result != nullptr )
    {
      result->ConVar::ConCommandBase::__vftable = nullptr;
      result->m_pNext = nullptr;
      *(_DWORD *)&result->m_bRegistered = 0;
      *(_DWORD *)&errorsInstance.sin_family = result;
    }
    else
    {
      *(_DWORD *)&errorsInstance.sin_family = 0;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423750
// Name: public: yaSSL::SSL_CTX::SSL_CTX(class yaSSL::SSL_METHOD __near *)
// Source: json
//------------------------------------------------------------------------------
IMemAlloc *__thiscall yaSSL::SSL_CTX::SSL_CTX(IMemAlloc *this, IMemAlloc_vtbl *meth)
{
  IMemAlloc *v3; // edi

  this->__vftable = meth;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  v3 = this + 40;
  *((_BYTE *)this + 24) = 0;
  *((_DWORD *)this + 39) = 0;
  yaSSL::Integer::Integer(this: this + 40);
  yaSSL::Integer::Integer(this: v3 + 1);
  LOBYTE(v3[2].__vftable) = 0;
  *((_DWORD *)this + 43) = 0;
  *((_DWORD *)this + 44) = 0;
  *((_BYTE *)this + 180) = 0;
  *((_BYTE *)this + 181) = 0;
  *((_DWORD *)this + 46) = 0;
  *((_DWORD *)this + 47) = 0;
  *((_DWORD *)this + 48) = 0;
  *((_DWORD *)this + 49) = 0;
  *((_DWORD *)this + 50) = 0;
  *((_DWORD *)this + 51) = 0;
  *((_DWORD *)this + 52) = 0;
  *((_DWORD *)this + 53) = 0;
  *((_DWORD *)this + 54) = 0;
  *((_DWORD *)this + 55) = 0;
  *((_DWORD *)this + 56) = 0;
  *((_DWORD *)this + 57) = 0;
  *((_DWORD *)this + 58) = 0;
  *((_DWORD *)this + 59) = 0;
  *((_DWORD *)this + 60) = 0;
  *((_DWORD *)this + 62) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423810
// Name: public: yaSSL::Buffers::Buffers(void)
// Source: json
//------------------------------------------------------------------------------
CThreadFastMutex *__thiscall yaSSL::Buffers::Buffers(CThreadFastMutex *this)
{
  this->m_ownerID = 0;
  this->m_depth = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423830
// Name: public: bool mySTL::list<class yaSSL::SSL_SESSION __near *>::erase(class mySTL::list<class yaSSL::SSL_SESSION __near *>::iterator)
// Source: json
//------------------------------------------------------------------------------
char __thiscall mySTL::list<yaSSL::SSL_SESSION *>::erase(ICommandLine *this, ICommandLine_vtbl *iter)
{
  if ( iter == nullptr )
    return 0;
  if ( iter == this->__vftable )
  {
    mySTL::list<yaSSL::input_buffer *>::pop_front(this);
    return 1;
  }
  else
  {
    if ( iter == *((ICommandLine_vtbl **)this + 1) )
    {
      mySTL::list<yaSSL::SSL_SESSION *>::pop_back(this);
    }
    else
    {
      *((_DWORD *)iter->CreateCmdLine + 1) = iter->CreateCmdLine_2;
      *(_DWORD *)iter->CreateCmdLine_2 = iter->CreateCmdLine;
      mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>();
      --*((_DWORD *)this + 2);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423950
// Name: private: yaSSL::sslFactory::sslFactory(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall yaSSL::sslFactory::sslFactory(_DWORD *this)
{
  *this = 0;
  *(this + 1) = 0;
  *(this + 2) = 0;
  yaSSL::InitMessageFactory(mf: (int)this);
  *(this + 3) = 0;
  *(this + 4) = 0;
  *(this + 5) = 0;
  yaSSL::InitHandShakeFactory(a1: (int)(this + 3));
  *(this + 6) = 0;
  *(this + 7) = 0;
  *(this + 8) = 0;
  yaSSL::InitServerKeyFactory(a1: (int)(this + 6));
  *(this + 9) = 0;
  *(this + 10) = 0;
  *(this + 11) = 0;
  yaSSL::InitClientKeyFactory(a1: (int)(this + 9));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004239A0
// Name: public: void yaSSL::SSL::makeTLSMasterSecret(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall yaSSL::SSL::makeTLSMasterSecret(int this)
{
  int v2; // eax
  ShortVector *v3; // edx
  int v4; // eax
  void *v5; // ecx
  _BYTE seed[32]; // [esp+Ch] [ebp-44h] OVERLAPPED BYREF
  _BYTE v7[32]; // [esp+2Ch] [ebp-24h] BYREF

  yaSSL::sslHashes::get_MD5(this: (ShortVector *)(this + 104));
  qmemcpy(seed, (const void *)(v2 + 52), sizeof(seed));
  qmemcpy(v7, (const void *)(v2 + 84), sizeof(v7));
  yaSSL::sslHashes::get_MD5(this: v3);
  yaSSL::PRF(digest: v5, digLen: v4 + 4, secret: 48);
  yaSSL::SSL::deriveTLSKeys((char *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00423A20
// Name: public: class yaSSL::SSL_SESSION __near & yaSSL::SSL_SESSION::operator=(class yaSSL::SSL_SESSION const __near &)
// Source: json
//------------------------------------------------------------------------------
const QAngle *__thiscall yaSSL::SSL_SESSION::operator=(int this, const QAngle *result)
{
  char *v3; // eax

  qmemcpy((void *)this, result, 0x20u);
  qmemcpy((void *)(this + 32), &result[2].z, 0x32u);
  v3 = *(char **)(this + 96);
  *(float *)(this + 84) = result[7].x;
  *(float *)(this + 88) = result[7].y;
  if ( v3 != nullptr )
  {
    yaSSL::ysDelete<yaSSL::X509>(ptr: v3);
    *(_DWORD *)(this + 96) = 0;
  }
  yaSSL::SSL_SESSION::CopyX509((yaSSL::SSL_SESSION *)this, a2: (ShortVector *)LODWORD(result[8].x));
  return (const QAngle *)this;
}

//------------------------------------------------------------------------------
// Address: 0x00423A90
// Name: public: yaSSL::SSL_SESSION::~SSL_SESSION(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_SESSION::~SSL_SESSION(QAngle *this)
{
  yaSSL::clean(
    p: (HICON__)((char *)this + 32),
    sz: (volatile unsigned __int8 *)0x30,
    ran: *((yaSSL::RandomPool **)this + 23));
  yaSSL::ysDelete<yaSSL::X509>(ptr: *((char **)this + 24));
}

//------------------------------------------------------------------------------
// Address: 0x00423AB0
// Name: class yaSSL::sslFactory __near & yaSSL::GetSSL_Factory(void)
// Source: json
//------------------------------------------------------------------------------
struct yaSSL::sslFactory *__thiscall yaSSL::GetSSL_Factory(const CSplitScreenAddedConVar *ecx0)
{
  struct yaSSL::sslFactory *result; // eax
  CSplitScreenAddedConVar *v2; // eax

  result = *(struct yaSSL::sslFactory **)sslFactoryInstance.SGName;
  if ( *(_DWORD *)sslFactoryInstance.SGName == 0 )
  {
    v2 = operator new(sz: ecx0, sza: 0x30u);
    if ( v2 != nullptr )
    {
      result = (struct yaSSL::sslFactory *)yaSSL::sslFactory::sslFactory(this: v2);
      *(_DWORD *)sslFactoryInstance.SGName = result;
    }
    else
    {
      *(_DWORD *)sslFactoryInstance.SGName = 0;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00423AF0
// Name: public: void yaSSL::Errors::Remove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Errors::Remove(ICommandLine *this)
{
  DWORD Self; // eax
  unsigned int iter; // [esp+4h] [ebp-4h] BYREF

  Self = yaSSL::yassl_int_cpp_local2::GetSelf();
  mySTL::find_if<mySTL::list<yaSSL::ThreadError>::iterator,yaSSL::yassl_int_cpp_local2::thr_match>(
    result: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int> *)&iter,
    last: (UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int> *)this->__vftable,
    last_4: nullptr,
    last_8: Self);
  if ( iter != 0 )
    mySTL::list<yaSSL::SSL_SESSION *>::erase(this, (ICommandLine_vtbl *)iter);
}

//------------------------------------------------------------------------------
// Address: 0x00423B20
// Name: public: void yaSSL::Errors::Add(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::Errors::Add(
        ICommandLine *this@<ecx>,
        const char *(__thiscall *error)(ICommandLine *this, const char *, const char **),
        char **a3)
{
  ICommandLine *Self; // ebx

  Self = (ICommandLine *)yaSSL::yassl_int_cpp_local2::GetSelf();
  yaSSL::Errors::Remove(this);
  mySTL::list<yaSSL::ThreadError>::push_back(this, t: Self, a3: error);
}

//------------------------------------------------------------------------------
// Address: 0x00423B50
// Name: public: yaSSL::SSL_CTX::~SSL_CTX(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL_CTX::~SSL_CTX(yaSSL::SSL_CTX *this)
{
  yaSSL::SSL_CTX *v1; // esi
  KeyValues *v2; // ecx
  Vector *v3; // edi
  bool (__cdecl *op)(const sockaddr_in *, const sockaddr_in *); // [esp+8h] [ebp-4h]

  v1 = this;
  yaSSL::ysDelete<unsigned char>(
    result: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *)this,
    ptr: (KeyValues *)*this);
  yaSSL::ysDelete<yaSSL::x509>(
    ptr: (KeyValues *)v1[1],
    ptra: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v1[1]);
  yaSSL::ysDelete<yaSSL::x509>(ptr: v2, ptra: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v1[2]);
  LOBYTE(op) = 0;
  v3 = (Vector *)(v1 + 3);
  mySTL::for_each<mySTL::list<yaSSL::x509 *>::iterator,yaSSL::del_ptr_zero>(a1: (int)v1[3], a2: 0, op);
  v1 += 40;
  yaSSL::Integer::~Integer(this: (IMemAlloc *)v1 + 1);
  yaSSL::Integer::~Integer(this: (IMemAlloc *)v1);
  mySTL::list<TaoCrypt::Signer *>::~list<TaoCrypt::Signer *>(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00423BB0
// Name: public: yaSSL::Buffers::~Buffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Buffers::~Buffers(yaSSL::Buffers *this)
{
  bool (__cdecl *op)(const sockaddr_in *, const sockaddr_in *); // [esp+8h] [ebp-4h]

  LOBYTE(op) = 0;
  mySTL::for_each<mySTL::list<yaSSL::x509 *>::iterator,yaSSL::del_ptr_zero>(a1: *((_DWORD *)this + 3), a2: 0, op);
  mySTL::for_each<mySTL::list<yaSSL::input_buffer *>::iterator,yaSSL::del_ptr_zero>(a1: *(_DWORD *)this, a2: 0, a3: 0);
  yaSSL::ysDelete<yaSSL::input_buffer>(result: *((CUtlString **)this + 6));
  mySTL::list<TaoCrypt::Signer *>::~list<TaoCrypt::Signer *>(this: (Vector *)this + 1);
  mySTL::list<TaoCrypt::Signer *>::~list<TaoCrypt::Signer *>((Vector *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00423C10
// Name: public: yaSSL::Security::Security(struct yaSSL::ProtocolVersion,class yaSSL::RandomPool __near &,enum yaSSL::ConnectionEnd,struct yaSSL::Ciphers const __near &,class yaSSL::SSL_CTX __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CInterlockedIntT<int> *__thiscall yaSSL::Security::Security(
        CInterlockedIntT<int> *this,
        CKeyValuesDumpContextAsDevMsg *pv,
        modsv_t *ran,
        modsv_t *a4,
        int a5,
        int haveDH,
        bool a7)
{
  yaSSL::Connection::Connection(this, v: (__int16)pv, (int)ran);
  yaSSL::Parameters::Parameters(this: (int)(this + 78), ce: a4, a3: a5, pv, haveDH: a7);
  yaSSL::SSL_SESSION::SSL_SESSION(this: (QAngle *)(this + 518), (int)ran);
  *((_DWORD *)this + 543) = haveDH;
  *((_BYTE *)this + 2176) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00423C70
// Name: public: void yaSSL::SSL::makeMasterSecret(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::SSL::makeMasterSecret(int this)
{
  ShortVector *v1; // esi
  int v2; // eax
  int v3; // esi
  int v4; // ebx
  int v5; // edi
  const LoggingContext_t *v6; // eax
  const LoggingContext_t *v7; // eax
  int v8; // eax
  yaSSL::Connection *v9; // eax
  const LoggingContext_t *v10; // [esp-8h] [ebp-60h]
  const struct SSL_METHOD *Method; // [esp-4h] [ebp-5Ch]
  const struct SSL_METHOD *v12; // [esp-4h] [ebp-5Ch]
  QueuedPacket_t *const *v13; // [esp+0h] [ebp-58h]
  QueuedPacket_t *const *v14; // [esp+0h] [ebp-58h]
  QueuedPacket_t *const *v15; // [esp+0h] [ebp-58h]
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > v17; // [esp+14h] [ebp-44h] BYREF
  float *sha; // [esp+30h] [ebp-28h] BYREF
  Vector2D v19; // [esp+38h] [ebp-20h] BYREF
  Vector2D v20; // [esp+40h] [ebp-18h] BYREF

  v1 = (ShortVector *)this;
  if ( yaSSL::SSL::isTLS((ShortVector *)this) != 0 )
  {
    yaSSL::SSL::makeTLSMasterSecret(this: (int)v1);
LABEL_7:
    yaSSL::sslHashes::get_MD5(this: v1 + 13);
    yaSSL::Connection::CleanPreMaster(this: v9);
  }
  else
  {
    yaSSL::sslHashes::get_MD5(this: v1 + 13);
    v3 = v2;
    yaSSL::output_buffer::output_buffer(this: (yaSSL::output_buffer *)&v17.m_pElements, a2: *(_DWORD *)(v2 + 292) + 20);
    yaSSL::output_buffer::output_buffer(this: (yaSSL::output_buffer *)&v17, a2: *(_DWORD *)(v3 + 292) + 67);
    yaSSL::MD5::MD5(this: (KeyValues **)&sha);
    yaSSL::SHA::SHA(this: &v19);
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)&v17.m_pElements,
      src: *(const unsigned __int8 **)v3,
      a3: *(_DWORD *)(v3 + 292));
    v4 = 0;
    v5 = 0;
    while ( yaSSL::_anonymous_namespace_::setPrefix(a1: &v17.m_Size, a2: v4) != 0 )
    {
      yaSSL::output_buffer::set_current(this: &v17, c: nullptr);
      yaSSL::output_buffer::write(
        this: (yaSSL::output_buffer *)&v17,
        src: (const unsigned __int8 *)&v17.m_Size,
        a3: ++v4);
      yaSSL::output_buffer::write(
        this: (yaSSL::output_buffer *)&v17,
        src: *(const unsigned __int8 **)v3,
        a3: *(_DWORD *)(v3 + 292));
      yaSSL::output_buffer::write(
        this: (yaSSL::output_buffer *)&v17,
        src: (const unsigned __int8 *)(v3 + 52),
        a3: 0x20u);
      yaSSL::output_buffer::write(
        this: (yaSSL::output_buffer *)&v17,
        src: (const unsigned __int8 *)(v3 + 84),
        a3: 0x20u);
      Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v17);
      yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)&v17);
      yaSSL::MD5::get_digest(this: &v19, result: &v20, in: v6, sz: (unsigned int)Method);
      yaSSL::output_buffer::set_current(
        this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v17.m_pElements,
        c: *(QueuedPacket_t *const **)(v3 + 292));
      yaSSL::output_buffer::write(
        this: (yaSSL::output_buffer *)&v17.m_pElements,
        src: (const unsigned __int8 *)&v20,
        a3: 0x14u);
      v12 = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v17.m_pElements);
      yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)&v17.m_pElements);
      v10 = v7;
      yaSSL::sslHashes::get_MD5(this: (ShortVector *)(this + 104));
      yaSSL::MD5::get_digest(this: (_DWORD **)&sha, result: (Vector2D *)(v8 + v5 + 4), in: v10, sz: (unsigned int)v12);
      v5 += 16;
      if ( v5 >= 48 )
      {
        yaSSL::SSL::deriveKeys(this);
        yaSSL::SHA::~SHA(this: &v19);
        yaSSL::MD5::~MD5(this: (yaSSL::MD5 *)&sha);
        yaSSL::x509::~x509(this: &v17, a2: v13);
        yaSSL::x509::~x509(
          this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v17.m_pElements,
          a2: v14);
        v1 = (ShortVector *)this;
        goto LABEL_7;
      }
    }
    yaSSL::SSL::SetError((_DWORD *)this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x69);
    yaSSL::SHA::~SHA(this: &v19);
    yaSSL::MD5::~MD5(this: (yaSSL::MD5 *)&sha);
    yaSSL::x509::~x509(this: &v17, a2: v13);
    yaSSL::x509::~x509(
      this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v17.m_pElements,
      a2: v15);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423EB0
// Name: public: yaSSL::SSL::SSL(class yaSSL::SSL_CTX __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<KeyValues *,int> *__thiscall yaSSL::SSL::SSL(
        CUtlMemory<KeyValues *,int> *this,
        QuaternionAligned *serverSide)
{
  CUtlMemory<KeyValues *,int> *v3; // edi
  HINSTANCE__ *v4; // eax
  HINSTANCE__ *v5; // ebx
  yaSSL::SSL_CTX *v6; // ecx
  IKeyValuesDumpContext *Method; // eax
  yaSSL::SSL_CTX *v8; // ecx
  CUtlMemory<KeyValues *,int> *v9; // eax
  modsv_t *v10; // eax
  char *v11; // eax
  unsigned __int16 *v12; // edx
  char *v13; // eax
  void (__thiscall *Error)(CBaseEntity *, inputdata_t *); // eax
  CUtlMemory<KeyValues *,int> *v15; // ecx
  KeyValues ***certManager; // ebx
  unsigned __int8 **v17; // eax
  char v18; // dl
  CUtlMemory<KeyValues *,int> *v19; // ecx
  yaSSL::SSL_CTX *length; // eax
  int v21; // eax
  ConCommandBase *v22; // eax
  yaSSL::SSL_METHOD *v23; // eax
  yaSSL::SSL_METHOD *v24; // eax
  int (__cdecl *VerifyCallback)(int, struct X509_STORE_CTX *); // eax
  int v26; // edi
  modsv_t *v28; // [esp-10h] [ebp-34h]
  int Ciphers; // [esp-Ch] [ebp-30h]
  char v30; // [esp-4h] [ebp-28h]
  int v31; // [esp+0h] [ebp-24h]
  __int16 v32; // [esp+0h] [ebp-24h]
  __int16 v33; // [esp+4h] [ebp-20h]
  __int16 v34; // [esp+8h] [ebp-1Ch]
  const st_mysql_methods *removeRSA; // [esp+14h] [ebp-10h]
  char removeDH; // [esp+18h] [ebp-Ch]
  CKeyValuesDumpContextAsDevMsg *pv; // [esp+1Ch] [ebp-8h]
  HINSTANCE__ *v38; // [esp+20h] [ebp-4h]

  yaSSL::Crypto::Crypto(this);
  v3 = (CUtlMemory<KeyValues *,int> *)serverSide;
  yaSSL::SSL_CTX::GetDH_Parms(this: serverSide);
  v5 = v4;
  v38 = v4;
  Method = (IKeyValuesDumpContext *)yaSSL::SSL_CTX::getMethod(this: v6);
  yaSSL::SSL_METHOD::getVersion(this: Method, a2: (KeyValues *)&serverSide, a3: v31);
  v30 = *((_BYTE *)v5 + 8);
  Ciphers = yaSSL::SSL_CTX::GetCiphers(this: v3);
  v9 = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: v8);
  yaSSL::SSL_CTX::getCert(this: v9);
  v28 = v10;
  v11 = yaSSL::States::useServer((char *)this);
  yaSSL::Security::Security(
    this: (CInterlockedIntT<int> *)this + 26,
    pv: (CKeyValuesDumpContextAsDevMsg *)*v12,
    ran: (modsv_t *)v11,
    a4: v28,
    a5: Ciphers,
    haveDH: (int)v3,
    a7: v30);
  yaSSL::States::States(this: (yaSSL::States *)((char *)this + 2284));
  yaSSL::MD5::MD5(this: (KeyValues **)this + 598);
  yaSSL::SHA::SHA(this: (Vector2D *)this + 300);
  yaSSL::Finished::Finished(this: (yaSSL::Finished *)((char *)this + 2408));
  yaSSL::Socket::Socket(this: (CKeyValuesDumpContextAsDevMsg *)this + 311);
  yaSSL::Buffers::Buffers(this: (CThreadFastMutex *)this + 312);
  yaSSL::Log::Log(
    this: (ShortVector *)((char *)this + 2524),
    __formal: (const __int16)"yaSSL.log",
    a3: v32,
    a4: v33,
    a5: v34);
  *((_BYTE *)this + 2525) = 0;
  *((_BYTE *)this + 2526) = 0;
  v13 = yaSSL::States::useServer((char *)this);
  Error = (void (__thiscall *)(CBaseEntity *, inputdata_t *))yaSSL::RandomPool::GetError(this: (yaSSL::RandomPool *)v13);
  v15 = this;
  if ( Error != nullptr )
    goto LABEL_23;
  certManager = yaSSL::Crypto::get_certManager((CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)this);
  yaSSL::SSL_CTX::getCert(this: v3);
  yaSSL::CertManager::CopySelfCert(this: (CSplitScreenAddedConVar *)certManager, x: v17);
  removeRSA = yaSSL::Security::use_parms(this: (char *)this + 104);
  LOBYTE(serverSide) = removeRSA->read_query_result == nullptr;
  if ( yaSSL::EncryptedPreMasterSecret::get_length(this: v3) == 0 )
  {
    if ( v18 != 0 )
    {
      yaSSL::SSL::SetError(this, ye: (void (__thiscall *)(CBaseEntity *, inputdata_t *))0x6F);
      return this;
    }
    goto LABEL_8;
  }
  length = (yaSSL::SSL_CTX *)yaSSL::EncryptedPreMasterSecret::get_length(this: v19);
  Error = (void (__thiscall *)(CBaseEntity *, inputdata_t *))yaSSL::CertManager::SetPrivateKey(
                                                               this: (CMasterDlg *)certManager,
                                                               a2: length);
  if ( Error == nullptr )
  {
    if ( (_BYTE)serverSide != 0 )
    {
      yaSSL::sslHashes::get_MD5(this: (ShortVector *)this + 13);
      removeDH = HIBYTE(removeRSA[27].read_prepare_result);
      LOWORD(pv) = *(_WORD *)(v21 + 302);
      if ( yaSSL::CertManager::get_keyType(this: certManager) == 1 )
        yaSSL::Parameters::SetSuites(pv, removeDH, removeRSA: false, removeDSA: true);
      else
        yaSSL::Parameters::SetSuites(pv, removeDH, removeRSA: true, removeDSA: false);
    }
LABEL_8:
    v22 = (ConCommandBase *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v3);
    if ( yaSSL::SSL_METHOD::verifyPeer(this: v22) )
      yaSSL::CertManager::setVerifyPeer(this: (ShortVector *)certManager);
    v23 = (yaSSL::SSL_METHOD *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v3);
    if ( yaSSL::SSL_METHOD::verifyNone(this: v23) )
      yaSSL::CertManager::setVerifyNone(this: (ShortVector *)certManager);
    v24 = (yaSSL::SSL_METHOD *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v3);
    if ( yaSSL::SSL_METHOD::failNoCert(this: v24) )
      yaSSL::CertManager::setFailNoCert(this: (ShortVector *)certManager);
    VerifyCallback = (int (__cdecl *)(int, struct X509_STORE_CTX *))yaSSL::SSL_CTX::getVerifyCallback(this: v3);
    yaSSL::CertManager::setVerifyCallback(this: (yaSSL::CertManager *)certManager, vc: VerifyCallback);
    if ( (_BYTE)serverSide != 0 )
      yaSSL::Crypto::SetDH(this, dh: v38);
    v26 = *(_DWORD *)yaSSL::States::useServer(this: (char *)v3);
    if ( v26 == 0 )
      return this;
    while ( 1 )
    {
      Error = (void (__thiscall *)(CBaseEntity *, inputdata_t *))yaSSL::CertManager::CopyCaCert(
                                                                   this: certManager,
                                                                   x: *(CUtlMemory<KeyValues *,int> **)(v26 + 8)).unused;
      if ( Error != nullptr )
        break;
      v26 = *(_DWORD *)(v26 + 4);
      if ( v26 == 0 )
        return this;
    }
  }
  v15 = this;
LABEL_23:
  yaSSL::SSL::SetError(this: v15, ye: Error);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00424110
// Name: public: class yaSSL::SSL_SESSION __near * yaSSL::Sessions::lookup(unsigned char const __near *,class yaSSL::SSL_SESSION __near *)
// Source: json
//------------------------------------------------------------------------------
struct yaSSL::SSL_SESSION *__userpurge yaSSL::Sessions::lookup@<eax>(
        yaSSL::Sessions *this@<ecx>,
        yaSSL *a2@<ebx>,
        unsigned __int8 *iter,
        struct yaSSL::SSL_SESSION *a4)
{
  unsigned __int8 *v5; // esi
  const float *BornOn; // ebx
  QAngle *v7; // ecx
  const float *TimeOut; // eax
  QAngle *v9; // ecx
  unsigned int v10; // edx

  mySTL::find_if<mySTL::list<yaSSL::SSL_SESSION *>::iterator,yaSSL::yassl_int_cpp_local2::sess_match>(
    a1: &iter,
    a2: *(_DWORD *)this,
    a3: 0,
    a4: (int)iter);
  v5 = iter;
  if ( iter == nullptr )
    return nullptr;
  yaSSL::lowResTimer(this: a2);
  BornOn = yaSSL::SSL_SESSION::GetBornOn(this: *((QAngle **)v5 + 2));
  TimeOut = yaSSL::SSL_SESSION::GetTimeOut(this: v7);
  if ( (int)BornOn + (int)TimeOut < v10 )
  {
    *((_DWORD *)v5 + 2) = 0;
    yaSSL::ysDelete<yaSSL::SSL_SESSION>(result: v9);
    mySTL::list<yaSSL::SSL_SESSION *>::erase((ICommandLine *)this, iter: (ICommandLine_vtbl *)v5);
    return nullptr;
  }
  if ( a4 != nullptr )
    yaSSL::SSL_SESSION::operator=(this: (int)a4, result: v9);
  return *((struct yaSSL::SSL_SESSION **)v5 + 2);
}

//------------------------------------------------------------------------------
// Address: 0x00424190
// Name: public: void yaSSL::Sessions::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Sessions::Flush(ICommandLine *this)
{
  ICommandLine v2; // edi
  unsigned int v3; // eax
  const char *(__thiscall *v4)(ICommandLine *); // edx
  unsigned int v5; // ebp
  ICommandLine_vtbl *v6; // esi
  QAngle *GetCmdLine; // ecx
  QAngle *v8; // ecx
  QAngle *v9; // [esp-8h] [ebp-18h]
  yaSSL *v10; // [esp+0h] [ebp-10h]
  const float *BornOn; // [esp+Ch] [ebp-4h]

  v2.__vftable = this->__vftable;
  v3 = yaSSL::lowResTimer(this: v10);
  v4 = nullptr;
  v5 = v3;
  while ( (const char *(__thiscall *)(ICommandLine *))v2.__vftable != v4 )
  {
    v6 = v2.__vftable;
    GetCmdLine = (QAngle *)v2.GetCmdLine;
    v2.__vftable = (ICommandLine_vtbl *)v2.CreateCmdLine_2;
    BornOn = yaSSL::SSL_SESSION::GetBornOn(this: GetCmdLine);
    if ( (int)BornOn + (int)yaSSL::SSL_SESSION::GetTimeOut(this: v8) < v5 )
    {
      v9 = (QAngle *)v6->GetCmdLine;
      v6->GetCmdLine = v4;
      yaSSL::ysDelete<yaSSL::SSL_SESSION>(result: v9);
      mySTL::list<yaSSL::SSL_SESSION *>::erase(this, iter: v6);
      v4 = nullptr;
    }
  }
  *((_DWORD *)this + 5) = v4;
}

//------------------------------------------------------------------------------
// Address: 0x004241F0
// Name: public: void yaSSL::SSL::set_session(class yaSSL::SSL_SESSION __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::SSL::set_session(
        CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *this@<ecx>,
        __int16 a2@<bp>,
        ShortVector *a3)
{
  yaSSL::Security *v4; // eax
  QuaternionAligned *Context; // eax
  unsigned __int8 *v6; // eax
  const CSplitScreenAddedConVar *v7; // ecx
  CSplitScreenAddedConVar *Sessions; // eax
  KeyValues ***certManager; // eax
  unsigned __int8 *v10; // [esp-10h] [ebp-14h]
  struct yaSSL::SSL_SESSION *resume; // [esp-Ch] [ebp-10h]
  ShortVector *PeerX509; // [esp-Ch] [ebp-10h]

  v4 = (yaSSL::Security *)yaSSL::SSL::useSecurity((char *)this);
  Context = (QuaternionAligned *)yaSSL::Security::GetContext(this: v4);
  if ( yaSSL::SSL_CTX::GetSessionCacheOff(this: Context) == 0 && a3 != nullptr )
  {
    resume = yaSSL::Security::get_resume(this: (yaSSL::Security *)((char *)this + 104));
    yaSSL::sslHashes::get_MD5(this: a3);
    v10 = v6;
    Sessions = yaSSL::GetSessions(ecx0: v7);
    if ( yaSSL::Sessions::lookup(this: (yaSSL::Sessions *)Sessions, a2: (yaSSL *)a3, iter: v10, a4: resume) != nullptr )
    {
      yaSSL::Security::set_resuming(this: (yaSSL::Security *)((char *)this + 104), a2: true);
      PeerX509 = (ShortVector *)yaSSL::SSL_SESSION::GetPeerX509(this: (QAngle *)a3);
      certManager = yaSSL::Crypto::get_certManager(this);
      yaSSL::CertManager::setPeerX509(
        this: (yaSSL::CertManager *)certManager,
        a2: (__int16)a3,
        a3: a2,
        a4: (__int16)this,
        a5: PeerX509);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00424260
// Name: public: void yaSSL::Sessions::add(class yaSSL::SSL const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Sessions::add(ICommandLine *this, IMemAlloc *result)
{
  ShortVector *v3; // ebx
  const CSplitScreenAddedConVar *v4; // ecx
  int v5; // eax
  QAngle *v6; // eax
  sockaddr *v7; // eax
  QuaternionAligned *Context; // eax
  float v9; // [esp+0h] [ebp-Ch]

  v3 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)result);
  yaSSL::sslHashes::get_MD5(this: v3);
  if ( *(_BYTE *)(v5 + 300) != 0 )
  {
    v6 = (QAngle *)operator new(sz: v4, sza: 0x64u);
    if ( v6 != nullptr )
      yaSSL::SSL_SESSION::SSL_SESSION(this: v6, ssl: (char *)result, ran: COERCE_FLOAT(this + 3), ran_4: v9);
    else
      v7 = nullptr;
    mySTL::list<yaSSL::x509 *>::push_back(this, result: v7);
    ++*((_DWORD *)this + 5);
  }
  if ( *((int *)this + 5) > 256 )
  {
    Context = (QuaternionAligned *)yaSSL::Security::GetContext(this: (yaSSL::Security *)v3);
    if ( yaSSL::SSL_CTX::GetSessionCacheFlushOff(this: Context) == 0 )
      yaSSL::Sessions::Flush(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042BF00
// Name: public: class yaSSL::SSL_METHOD const __near * yaSSL::SSL_CTX::getMethod(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::SSL_CTX::getMethod(yaSSL::SSL_CTX *this)
{
  return (int)*this;
}
