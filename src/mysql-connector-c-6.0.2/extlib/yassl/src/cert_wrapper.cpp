// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/cert_wrapper.cpp
// Functions: 50
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\cert_wrapper.h"

//------------------------------------------------------------------------------
// Address: 0x00416A00
// Name: void yaSSL::ysDelete<struct yaSSL::BulkCipher>(struct yaSSL::BulkCipher __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ysDelete<yaSSL::BulkCipher>(KeyValues *ptr, const CUtlMemory<KeyValues *,int>::Iterator_t *ptra)
{
  if ( ptra != nullptr )
    (*(void (__thiscall **)(const CUtlMemory<KeyValues *,int>::Iterator_t *, _DWORD))(*(_DWORD *)ptra + 28))(
      a1: ptra,
      a2: 0);
  operator delete(ptr);
}

//------------------------------------------------------------------------------
// Address: 0x00416A70
// Name: void yaSSL::ysDelete<class yaSSL::SSL_CTX>(class yaSSL::SSL_CTX __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::SSL_CTX>(CUtlStringList ptr)
{
  KeyValues *v1; // ecx

  if ( ptr.m_Memory.m_pMemory != nullptr )
    yaSSL::SSL_CTX::~SSL_CTX(this: (yaSSL::SSL_CTX *)ptr.m_Memory.m_pMemory);
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00416BD0
// Name: void yaSSL::ysDelete<struct yaSSL::BIGNUM>(struct yaSSL::BIGNUM __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::BIGNUM>(IMemAlloc *a1)
{
  KeyValues *v1; // ecx

  if ( a1 != nullptr )
    yaSSL::Integer::~Integer(this: a1);
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00416CA0
// Name: void yaSSL::ysDelete<class yaSSL::SSL>(class yaSSL::SSL __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall yaSSL::ysDelete<yaSSL::SSL>(KeyValues *this)
{
  st_mysql *v1; // [esp-4h] [ebp-8h]
  int retaddr; // [esp+4h] [ebp+0h]

  if ( retaddr != 0 )
    yaSSL::SSL::~SSL(this: retaddr, result: v1);
  operator delete(ptr: this);
}

//------------------------------------------------------------------------------
// Address: 0x00421570
// Name: void yaSSL::ysDelete<struct yaSSL::Digest>(struct yaSSL::Digest __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ysDelete<yaSSL::Digest>(KeyValues *ptr, int a2)
{
  if ( a2 != 0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a2 + 20))(a1: a2, a2: 0);
  operator delete(ptr);
}

//------------------------------------------------------------------------------
// Address: 0x00422AD0
// Name: public: void mySTL::list<class yaSSL::x509 __near *>::push_back(class yaSSL::x509 __near *)
// Source: json
//------------------------------------------------------------------------------
sockaddr *__thiscall mySTL::list<yaSSL::x509 *>::push_back(_DWORD *this, sockaddr *result)
{
  sockaddr *Array; // eax
  int v4; // ecx

  Array = (sockaddr *)mySTL::GetArrayMemory<unsigned char>(sz: (CSplitScreenAddedConVar *)0xC);
  if ( Array != nullptr )
  {
    *(_DWORD *)&Array->sa_family = 0;
    *(_DWORD *)&Array->sa_data[2] = 0;
    *(_DWORD *)&Array->sa_data[6] = result;
  }
  else
  {
    Array = nullptr;
  }
  v4 = *(this + 1);
  if ( v4 != 0 )
  {
    *(_DWORD *)(v4 + 4) = Array;
    *(_DWORD *)&Array->sa_family = *(this + 1);
    ++*(this + 2);
  }
  else
  {
    ++*(this + 2);
    *this = Array;
  }
  *(this + 1) = Array;
  return Array;
}

//------------------------------------------------------------------------------
// Address: 0x00422B70
// Name: void yaSSL::ysDelete<class yaSSL::input_buffer>(class yaSSL::input_buffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::input_buffer>(CUtlString *result)
{
  KeyValues *v1; // ecx
  const char *v2; // [esp+0h] [ebp-4h]

  if ( result != nullptr )
    yaSSL::input_buffer::~input_buffer(this: result, a2: v2);
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00422BF0
// Name: void yaSSL::ysDelete<class yaSSL::x509>(class yaSSL::x509 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ysDelete<yaSSL::x509>(
        KeyValues *ptr,
        CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *ptra)
{
  QueuedPacket_t *const *v2; // [esp+0h] [ebp-4h]

  if ( ptra != nullptr )
    yaSSL::x509::~x509(this: ptra, a2: v2);
  operator delete(ptr);
}

//------------------------------------------------------------------------------
// Address: 0x00422C50
// Name: void yaSSL::ysDelete<class yaSSL::DiffieHellman>(class yaSSL::DiffieHellman __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::DiffieHellman>(CDatamapFieldSizeDeducer<17>::<unnamed_tag> *result)
{
  KeyValues *v1; // ecx

  if ( result != nullptr )
    yaSSL::DiffieHellman::~DiffieHellman(this: result);
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00422FE0
// Name: public: mySTL::list<class TaoCrypt::Signer __near *>::~list<class TaoCrypt::Signer __near *>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall mySTL::list<TaoCrypt::Signer *>::~list<TaoCrypt::Signer *>(Vector *this)
{
  float x; // eax
  float v2; // esi

  x = this->x;
  if ( LODWORD(this->x) != 0 )
  {
    do
    {
      v2 = *(float *)(LODWORD(x) + 4);
      mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>();
      x = v2;
    }
    while ( v2 != 0.0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00423890
// Name: void yaSSL::ysDelete<class yaSSL::X509>(class yaSSL::X509 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::X509>(char *ptr)
{
  KeyValues *v1; // ecx
  const char *v2; // [esp+0h] [ebp-4h]
  const char *v3; // [esp+0h] [ebp-4h]

  if ( ptr != nullptr )
  {
    yaSSL::input_buffer::~input_buffer(this: (CUtlString *)(ptr + 52), a2: v2);
    yaSSL::input_buffer::~input_buffer(this: (CUtlString *)(ptr + 40), a2: v3);
    yaSSL::X509_NAME::~X509_NAME(this: (yaSSL::X509_NAME *)(ptr + 20));
    yaSSL::X509_NAME::~X509_NAME(this: (yaSSL::X509_NAME *)ptr);
  }
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004238D0
// Name: struct yaSSL::del_ptr_zero mySTL::for_each<class mySTL::list<class yaSSL::x509 __near *>::iterator,struct yaSSL::del_ptr_zero>(class mySTL::list<class yaSSL::x509 __near *>::iterator,class mySTL::list<class yaSSL::x509 __near *>::iterator,struct yaSSL::del_ptr_zero)
// Source: json
//------------------------------------------------------------------------------
char __cdecl mySTL::for_each<mySTL::list<yaSSL::x509 *>::iterator,yaSSL::del_ptr_zero>(
        int a1,
        int a2,
        bool (__cdecl *op)(const sockaddr_in *, const sockaddr_in *))
{
  int i; // eax
  KeyValues *v4; // ecx

  for ( i = a1; i != a2; a1 = i )
  {
    v4 = *(KeyValues **)(i + 8);
    *(_DWORD *)(i + 8) = 0;
    yaSSL::ysDelete<yaSSL::x509>(ptr: v4, ptra: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v4);
    i = *(_DWORD *)(a1 + 4);
  }
  return (char)op;
}

//------------------------------------------------------------------------------
// Address: 0x00423910
// Name: struct yaSSL::del_ptr_zero mySTL::for_each<class mySTL::list<class yaSSL::input_buffer __near *>::iterator,struct yaSSL::del_ptr_zero>(class mySTL::list<class yaSSL::input_buffer __near *>::iterator,class mySTL::list<class yaSSL::input_buffer __near *>::iterator,struct yaSSL::del_ptr_zero)
// Source: json
//------------------------------------------------------------------------------
char __cdecl mySTL::for_each<mySTL::list<yaSSL::input_buffer *>::iterator,yaSSL::del_ptr_zero>(int a1, int a2, char a3)
{
  int i; // eax
  CUtlString *v5; // [esp-4h] [ebp-4h]

  for ( i = a1; i != a2; a1 = i )
  {
    v5 = *(CUtlString **)(i + 8);
    *(_DWORD *)(i + 8) = 0;
    yaSSL::ysDelete<yaSSL::input_buffer>(result: v5);
    i = *(_DWORD *)(a1 + 4);
  }
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x00423E80
// Name: void yaSSL::ysDelete<class yaSSL::SSL_SESSION>(class yaSSL::SSL_SESSION __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::SSL_SESSION>(QAngle *result)
{
  KeyValues *v1; // ecx
  int v2; // [esp+0h] [ebp-4h]

  if ( result != nullptr )
    yaSSL::SSL_SESSION::~SSL_SESSION(this: result, a2: v2);
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429AE0
// Name: void yaSSL::ysDelete<struct yaSSL::ClientKeyBase>(struct yaSSL::ClientKeyBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ysDelete<yaSSL::ClientKeyBase>(
        KeyValues *ptr,
        CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> *ptra)
{
  if ( ptra != nullptr )
    ((void (__thiscall *)(CUtlMemory<UtlRBTreeNode_t<sv_t *,int>,int> *, _DWORD))ptra->m_pMemory->m_Left)(
      a1: ptra,
      a2: 0);
  operator delete(ptr);
}

//------------------------------------------------------------------------------
// Address: 0x00429B10
// Name: void yaSSL::ysDelete<struct yaSSL::Auth>(struct yaSSL::Auth __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ysDelete<yaSSL::Auth>(KeyValues *ptr, const char *a2)
{
  if ( a2 != nullptr )
    (*(void (__thiscall **)(const char *, _DWORD))(*(_DWORD *)a2 + 12))(a1: a2, a2: 0);
  operator delete(ptr);
}

//------------------------------------------------------------------------------
// Address: 0x00429B40
// Name: void yaSSL::ysDelete<class yaSSL::HandShakeBase>(class yaSSL::HandShakeBase __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::HandShakeBase>(int a1)
{
  KeyValues *v1; // ecx

  if ( a1 != 0 )
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a1 + 16))(a1, a2: 0);
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0042BAD0
// Name: struct yaSSL::del_ptr_zero mySTL::for_each<class mySTL::list<unsigned char __near *>::iterator,struct yaSSL::del_ptr_zero>(class mySTL::list<unsigned char __near *>::iterator,class mySTL::list<unsigned char __near *>::iterator,struct yaSSL::del_ptr_zero)
// Source: json
//------------------------------------------------------------------------------
char __cdecl mySTL::for_each<mySTL::list<unsigned char *>::iterator,yaSSL::del_ptr_zero>(
        int a1,
        int a2,
        bool (__cdecl *op)(const sockaddr_in *, const sockaddr_in *))
{
  int i; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *v4; // ecx

  for ( i = a1; i != a2; a1 = i )
  {
    v4 = *(CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t **)(i + 8);
    *(_DWORD *)(i + 8) = 0;
    yaSSL::ysDelete<unsigned char>(result: v4, ptr: (KeyValues *)v4);
    i = *(_DWORD *)(a1 + 4);
  }
  return (char)op;
}

//------------------------------------------------------------------------------
// Address: 0x0042E790
// Name: public: yaSSL::x509::x509(unsigned int)
// Source: json
//------------------------------------------------------------------------------
yaSSL::x509 *__thiscall yaSSL::x509::x509(yaSSL::x509 *this, unsigned int a2)
{
  *(_DWORD *)this = a2;
  *((_DWORD *)this + 1) = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042E7C0
// Name: public: yaSSL::x509::x509(class yaSSL::x509 const __near &)
// Source: json
//------------------------------------------------------------------------------
yaSSL::x509 *__thiscall yaSSL::x509::x509(yaSSL::x509 *this, unsigned __int8 **a2)
{
  unsigned __int8 *v3; // eax
  unsigned int v4; // edx

  *(_DWORD *)this = *a2;
  v3 = (unsigned __int8 *)operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  v4 = *(_DWORD *)this;
  *((_DWORD *)this + 1) = v3;
  memcpy(dst: v3, src: a2[1], count: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042E800
// Name: public: bool yaSSL::CertManager::verifyPeer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::CertManager::verifyPeer(yaSSL::CertManager *this)
{
  return *((_BYTE *)this + 80);
}

//------------------------------------------------------------------------------
// Address: 0x0042E810
// Name: public: bool yaSSL::CertManager::sendVerify(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall yaSSL::CertManager::sendVerify(yaSSL::CertManager *this)
{
  return *((_BYTE *)this + 83);
}

//------------------------------------------------------------------------------
// Address: 0x0042E820
// Name: public: void yaSSL::CertManager::setVerifyPeer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertManager::setVerifyPeer(ShortVector *this)
{
  *((_BYTE *)this + 80) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E830
// Name: public: void yaSSL::CertManager::setVerifyNone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertManager::setVerifyNone(ShortVector *this)
{
  *((_BYTE *)this + 81) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E840
// Name: public: void yaSSL::CertManager::setFailNoCert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertManager::setFailNoCert(ShortVector *this)
{
  *((_BYTE *)this + 82) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E850
// Name: public: void yaSSL::CertManager::setSendVerify(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertManager::setSendVerify(ShortVector *this)
{
  *((_BYTE *)this + 83) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042E860
// Name: public: void yaSSL::CertManager::setVerifyCallback(int (*)(int,struct yaSSL::X509_STORE_CTX __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertManager::setVerifyCallback(
        yaSSL::CertManager *this,
        int (__cdecl *vc)(int, struct X509_STORE_CTX *))
{
  *((_DWORD *)this + 21) = vc;
}

//------------------------------------------------------------------------------
// Address: 0x0042E870
// Name: public: unsigned char const __near * yaSSL::CertManager::get_peerKey(void)const
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__thiscall yaSSL::CertManager::get_peerKey(yaSSL::CertManager *this)
{
  return (const unsigned __int8 *)yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)((char *)this + 40));
}

//------------------------------------------------------------------------------
// Address: 0x0042E880
// Name: public: class yaSSL::X509 __near * yaSSL::CertManager::get_peerX509(void)const
// Source: json
//------------------------------------------------------------------------------
struct X509 *__thiscall yaSSL::CertManager::get_peerX509(yaSSL::CertManager *this)
{
  return *((struct X509 **)this + 14);
}

//------------------------------------------------------------------------------
// Address: 0x0042E890
// Name: public: enum yaSSL::SignatureAlgorithm yaSSL::CertManager::get_peerKeyType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::CertManager::get_peerKeyType(_DWORD *this)
{
  return *(this + 16);
}

//------------------------------------------------------------------------------
// Address: 0x0042E8A0
// Name: public: enum yaSSL::SignatureAlgorithm yaSSL::CertManager::get_keyType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::CertManager::get_keyType(_DWORD *this)
{
  return *(this + 15);
}

//------------------------------------------------------------------------------
// Address: 0x0042E8B0
// Name: public: unsigned int yaSSL::CertManager::get_peerKeyLength(void)const
// Source: json
//------------------------------------------------------------------------------
const struct SSL_METHOD *__thiscall yaSSL::CertManager::get_peerKeyLength(yaSSL::SSL_CTX *this)
{
  return yaSSL::SSL_CTX::getMethod(this: this + 10);
}

//------------------------------------------------------------------------------
// Address: 0x0042E8C0
// Name: public: unsigned char const __near * yaSSL::CertManager::get_privateKey(void)const
// Source: json
//------------------------------------------------------------------------------
const unsigned __int8 *__thiscall yaSSL::CertManager::get_privateKey(CUtlMemory<KeyValues *,int> *this)
{
  return (const unsigned __int8 *)yaSSL::EncryptedPreMasterSecret::get_length(this: this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x0042E8D0
// Name: public: unsigned int yaSSL::CertManager::get_privateKeyLength(void)const
// Source: json
//------------------------------------------------------------------------------
const struct SSL_METHOD *__thiscall yaSSL::CertManager::get_privateKeyLength(yaSSL::SSL_CTX *this)
{
  return yaSSL::SSL_CTX::getMethod(this: this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x0042E8E0
// Name: public: void yaSSL::CertManager::setPeerX509(class yaSSL::X509 __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::CertManager::setPeerX509(
        yaSSL::CertManager *this@<ecx>,
        __int16 a2@<bx>,
        __int16 a3@<bp>,
        __int16 a4@<di>,
        ShortVector *a5)
{
  CUtlMemory<KeyValues *,int> *v5; // eax
  CUtlMemory<KeyValues *,int> *v6; // edi
  CUtlMemory<KeyValues *,int> *Subject; // ebx
  localeinfo_struct *v8; // ebp
  const CSplitScreenAddedConVar *v9; // ecx
  yaSSL::X509 *v10; // esi
  unsigned int v11; // eax
  CUtlMemory<KeyValues *,int> *Method; // eax
  unsigned int v13; // eax
  const char *v14; // eax
  unsigned int v15; // [esp-28h] [ebp-30h]
  const char *v16; // [esp-24h] [ebp-2Ch]
  unsigned int v17; // [esp-20h] [ebp-28h]
  const char *v18; // [esp-1Ch] [ebp-24h]
  int mbcinfo; // [esp-18h] [ebp-20h]
  const char *v20; // [esp-14h] [ebp-1Ch]
  int v21; // [esp-10h] [ebp-18h]
  __int16 v22; // [esp+0h] [ebp-8h]
  ShortVector *v24; // [esp+Ch] [ebp+4h]

  if ( a5 != nullptr )
  {
    yaSSL::sslHashes::get_MD5(this: a5, a2: a4, a3, a4: a2, a5: v22);
    v6 = v5;
    Subject = (CUtlMemory<KeyValues *,int> *)yaSSL::X509::GetSubject(this: (yaSSL::X509 *)a5);
    v8 = yaSSL::X509::GetBefore(this: (_LocaleUpdate *)a5);
    v24 = (ShortVector *)yaSSL::X509::GetAfter(this: (_LocaleUpdate *)a5);
    v10 = (yaSSL::X509 *)operator new(sz: v9);
    if ( v10 != nullptr )
    {
      v21 = *(_DWORD *)&v24->z;
      v20 = *(const char **)&v24[1].x;
      mbcinfo = (int)v8->mbcinfo;
      yaSSL::SSL_CTX::getCert(this: Subject, a2: (CUtlMemory<KeyValues *,int> *)v8[1].locinfo);
      v17 = v11;
      Method = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)Subject);
      yaSSL::SSL_CTX::getCert(this: v6, a2: Method);
      v15 = v13;
      v14 = (const char *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v6);
      *((_DWORD *)this + 14) = yaSSL::X509::X509(
                                 this: v10,
                                 a2: v14,
                                 a3: v15,
                                 a4: v16,
                                 a5: v17,
                                 a6: v18,
                                 a7: mbcinfo,
                                 a8: v20,
                                 a9: v21);
    }
    else
    {
      *((_DWORD *)this + 14) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042E990
// Name: public: class yaSSL::x509 const __near * yaSSL::CertManager::get_cert(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
bool __thiscall yaSSL::CertManager::get_cert(Vector *this, const char *a2, sockaddr *a3)
{
  return mySTL::list<yaSSL::input_buffer *>::front((CMasterDlg *)this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0042E9A0
// Name: void yaSSL::ysDelete<class TaoCrypt::Signer>(class TaoCrypt::Signer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<TaoCrypt::Signer>(TaoCrypt::Signer *a1)
{
  KeyValues *v1; // ecx

  if ( a1 != nullptr )
    TaoCrypt::Signer::~Signer(this: a1);
  operator delete(ptr: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0042E9D0
// Name: public: void yaSSL::CertManager::AddPeerCert(class yaSSL::x509 __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertManager::AddPeerCert(yaSSL::CertManager *this, sockaddr *a2)
{
  mySTL::list<yaSSL::x509 *>::push_back(this: (_DWORD *)this + 7, result: a2);
}

//------------------------------------------------------------------------------
// Address: 0x0042E9E0
// Name: public: void yaSSL::CertManager::CopySelfCert(class yaSSL::x509 const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertManager::CopySelfCert(CSplitScreenAddedConVar *this, unsigned __int8 **x)
{
  yaSSL::x509 *v3; // eax
  sockaddr *v4; // eax

  if ( x != nullptr )
  {
    v3 = (yaSSL::x509 *)operator new(sz: this);
    if ( v3 != nullptr )
    {
      v4 = (sockaddr *)yaSSL::x509::x509(this: v3, a2: x);
      mySTL::list<yaSSL::x509 *>::push_back(this, result: v4);
    }
    else
    {
      mySTL::list<yaSSL::x509 *>::push_back(this, result: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042EA30
// Name: public: yaSSL::CertManager::CertManager(void)
// Source: json
//------------------------------------------------------------------------------
ShortVector *__thiscall yaSSL::CertManager::CertManager(ShortVector *this)
{
  *(_DWORD *)&this->x = 0;
  *(_DWORD *)&this->z = 0;
  *((_DWORD *)this + 2) = 0;
  CUtlString::CUtlString(this: (CUtlString *)((char *)this + 12));
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  *((_DWORD *)this + 9) = 0;
  CUtlString::CUtlString(this: (CUtlString *)(this + 5));
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_WORD *)this + 40) = 0;
  *((_WORD *)this + 41) = 0;
  *((_DWORD *)this + 21) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042EA80
// Name: public: int yaSSL::CertManager::CopyCaCert(class yaSSL::x509 const __near *)
// Source: json
//------------------------------------------------------------------------------
HWND__ __thiscall yaSSL::CertManager::CopyCaCert(_DWORD *this, CUtlMemory<KeyValues *,int> *x)
{
  unsigned __int8 *v3; // eax
  unsigned __int8 *v4; // edi
  yaSSL::SSL_CTX *v5; // ecx
  IConVar *Method; // eax
  CSplitScreenAddedConVar *v7; // ecx
  struct Error v8; // ecx
  TaoCrypt::Signer *v9; // eax
  sockaddr *v10; // eax
  unsigned __int8 *m_pConVarState; // esi
  CUtlMemory<KeyValues *,int> *v13; // [esp+0h] [ebp-498h]
  const CNonFatalLoggingResponsePolicy *v14; // [esp+0h] [ebp-498h]
  ConVarRef source; // [esp+8h] [ebp-490h] BYREF
  int v16; // [esp+14h] [ebp-484h]
  int v17; // [esp+18h] [ebp-480h]
  CNonFatalLoggingResponsePolicy v18; // [esp+20h] [ebp-478h] BYREF
  const LoggingContext_t *k; // [esp+28h] [ebp-470h]
  unsigned int kSz; // [esp+2Ch] [ebp-46Ch]
  unsigned __int8 v21[556]; // [esp+44h] [ebp-454h] BYREF
  tagShutdownType n[137]; // [esp+270h] [ebp-228h] BYREF

  yaSSL::SSL_CTX::getCert(this: x, a2: v13);
  v4 = v3;
  Method = (IConVar *)yaSSL::SSL_CTX::getMethod(this: v5);
  source.m_pConVar = Method;
  if ( Method != nullptr )
  {
    v7 = operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc);
    Method = source.m_pConVar;
  }
  else
  {
    v7 = nullptr;
  }
  source.m_pConVarState = v7;
  memcpy(dst: (unsigned __int8 *)v7, src: v4, count: (unsigned int)Method);
  v16 = 0;
  v17 = 0;
  TaoCrypt::CertDecoder::CertDecoder(this: &v18, s: (const LoggingContext_t *)&source);
  if ( TaoCrypt::BER_Decoder::GetError(this: (TaoCrypt::BER_Decoder *)&v18).lpVtbl->QueryInterface == nullptr )
  {
    v9 = (TaoCrypt::Signer *)operator new(sz: (const CSplitScreenAddedConVar *)v8.lpVtbl);
    if ( v9 != nullptr )
      v10 = (sockaddr *)TaoCrypt::Signer::Signer(this: v9, k, kSz, (tagShutdownType)n, a5: v21);
    else
      v10 = nullptr;
    mySTL::list<yaSSL::x509 *>::push_back(this: this + 17, result: v10);
  }
  TaoCrypt::CertDecoder::~CertDecoder(result: v14);
  m_pConVarState = (unsigned __int8 *)source.m_pConVarState;
  memset(dst: (unsigned __int8 *)source.m_pConVarState, value: 0, count: (unsigned int)source.m_pConVar);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: m_pConVarState);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042EBA0
// Name: public: int yaSSL::CertManager::Validate(void)
// Source: json
//------------------------------------------------------------------------------
struct ErrorVtbl *__thiscall yaSSL::CertManager::Validate(yaSSL::CertManager *this)
{
  yaSSL::CertManager *v1; // ebx
  unsigned int v2; // ebp
  int **v3; // edi
  _DWORD *v4; // ebx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // esi
  yaSSL::SSL_CTX *v7; // ecx
  CUtlString *Method; // eax
  CUtlString *m_pMemory; // ecx
  struct Error v10; // ecx
  struct Error v11; // esi
  TaoCrypt::Signer *v12; // eax
  sockaddr *v13; // eax
  unsigned __int8 *m_nAllocationCount; // esi
  CUtlMemory<KeyValues *,int> *v15; // eax
  CUtlMemory<KeyValues *,int> *v16; // ecx
  int (__cdecl *v17)(const CUtlString *, const CUtlString *); // eax
  unsigned __int8 *v18; // edi
  char *v20; // edi
  unsigned int v21; // kr00_4
  unsigned int v22; // kr04_4
  unsigned int v23; // kr08_4
  unsigned int v24; // kr0C_4
  yaSSL::X509 *v25; // eax
  int v26; // eax
  unsigned __int8 *v27; // esi
  CUtlString *v28; // [esp-4h] [ebp-4A8h]
  CUtlMemory<KeyValues *,int> *v29; // [esp+0h] [ebp-4A4h]
  const CNonFatalLoggingResponsePolicy *v30; // [esp+0h] [ebp-4A4h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > s; // [esp+14h] [ebp-490h] BYREF
  CNonFatalLoggingResponsePolicy v33; // [esp+2Ch] [ebp-478h] BYREF
  unsigned __int8 *src; // [esp+34h] [ebp-470h]
  char *v35; // [esp+38h] [ebp-46Ch]
  int v36; // [esp+4Ch] [ebp-458h]
  unsigned __int8 v37[44]; // [esp+50h] [ebp-454h] BYREF
  char v38[512]; // [esp+7Ch] [ebp-428h] BYREF
  char n[512]; // [esp+27Ch] [ebp-228h] BYREF
  char v40[16]; // [esp+47Ch] [ebp-28h] BYREF
  char v41[20]; // [esp+48Ch] [ebp-18h] BYREF

  v1 = this;
  v2 = *((_DWORD *)this + 9);
  v3 = *((int ***)this + 8);
  if ( v2 > 1 )
  {
    v4 = (_DWORD *)((char *)this + 68);
    while ( 1 )
    {
      yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)v3[2], a2: v29);
      v6 = v5;
      Method = (CUtlString *)yaSSL::SSL_CTX::getMethod(this: v7);
      m_pMemory = Method;
      s.m_Memory.m_pMemory = Method;
      if ( Method != nullptr )
      {
        Method = (CUtlString *)operator new[](sz: (const CSplitScreenAddedConVar *)Method);
        m_pMemory = s.m_Memory.m_pMemory;
      }
      s.m_Memory.m_nAllocationCount = (int)Method;
      memcpy(dst: (unsigned __int8 *)Method, src: v6, count: (unsigned int)m_pMemory);
      s.m_Size = 0;
      s.m_pElements = nullptr;
      TaoCrypt::CertDecoder::CertDecoder(this: &v33, (const LoggingContext_t *)&s);
      v11.lpVtbl = (struct ErrorVtbl *)TaoCrypt::BER_Decoder::GetError(this: (TaoCrypt::BER_Decoder *)&v33).lpVtbl->QueryInterface;
      if ( v11.lpVtbl != nullptr )
        goto LABEL_13;
      v12 = (TaoCrypt::Signer *)operator new(sz: (const CSplitScreenAddedConVar *)v10.lpVtbl);
      if ( v12 != nullptr )
        v13 = (sockaddr *)TaoCrypt::Signer::Signer(
                            this: v12,
                            k: (const LoggingContext_t *)src,
                            kSz: (unsigned int)v35,
                            (tagShutdownType)n,
                            a5: v37);
      else
        v13 = nullptr;
      mySTL::list<yaSSL::x509 *>::push_back(this: v4, result: v13);
      v3 = (int **)*v3;
      --v2;
      TaoCrypt::CertDecoder::~CertDecoder(result: (const CNonFatalLoggingResponsePolicy *)v29);
      m_nAllocationCount = (unsigned __int8 *)s.m_Memory.m_nAllocationCount;
      memset(dst: (unsigned __int8 *)s.m_Memory.m_nAllocationCount, value: 0, count: (unsigned int)s.m_Memory.m_pMemory);
      TaoCrypt::tcArrayDelete<unsigned char>(ptr: m_nAllocationCount);
      if ( v2 <= 1 )
      {
        v1 = this;
        break;
      }
    }
  }
  if ( v2 != 0 )
  {
    v15 = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v3[2]);
    yaSSL::SSL_CTX::getCert(this: v16, a2: v15);
    TaoCrypt::Source::Source(this: &s, b: v17, sz: v28);
    TaoCrypt::CertDecoder::CertDecoder(this: &v33, (const LoggingContext_t *)&s);
    v11.lpVtbl = (struct ErrorVtbl *)TaoCrypt::BER_Decoder::GetError(this: (TaoCrypt::BER_Decoder *)&v33).lpVtbl->QueryInterface;
    if ( v11.lpVtbl != nullptr )
    {
LABEL_13:
      TaoCrypt::CertDecoder::~CertDecoder(result: (const CNonFatalLoggingResponsePolicy *)v29);
      v18 = (unsigned __int8 *)s.m_Memory.m_nAllocationCount;
      memset(dst: (unsigned __int8 *)s.m_Memory.m_nAllocationCount, value: 0, count: (unsigned int)s.m_Memory.m_pMemory);
      TaoCrypt::tcArrayDelete<unsigned char>(ptr: v18);
      return v11.lpVtbl;
    }
    v20 = v35;
    yaSSL::input_buffer::allocate(this: (CUtlString *)((char *)v1 + 40), s: v35, a3: (int)v29);
    yaSSL::input_buffer::assign(this: (yaSSL::input_buffer *)((char *)v1 + 40), src, a3: (unsigned int)v20);
    *((_DWORD *)v1 + 16) = (v36 != 645) + 1;
    v21 = strlen(v38);
    v22 = strlen(n);
    v23 = strlen(v40);
    v24 = strlen(v41);
    v25 = (yaSSL::X509 *)operator new(sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
    if ( v25 != nullptr )
      v26 = yaSSL::X509::X509(
              this: v25,
              a2: v38,
              a3: v21 + 1,
              a4: n,
              a5: v22 + 1,
              a6: v40,
              a7: v23 + 1,
              a8: v41,
              a9: v24 + 1);
    else
      v26 = 0;
    *((_DWORD *)v1 + 14) = v26;
    TaoCrypt::CertDecoder::~CertDecoder(result: v30);
    v27 = (unsigned __int8 *)s.m_Memory.m_nAllocationCount;
    memset(dst: (unsigned __int8 *)s.m_Memory.m_nAllocationCount, value: 0, count: (unsigned int)s.m_Memory.m_pMemory);
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: v27);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042EE70
// Name: public: int yaSSL::CertManager::SetPrivateKey(class yaSSL::x509 const __near &)
// Source: json
//------------------------------------------------------------------------------
struct ErrorVtbl *__thiscall yaSSL::CertManager::SetPrivateKey(CMasterDlg *this, yaSSL::SSL_CTX *a2)
{
  const char *Method; // eax
  CUtlMemory<KeyValues *,int> *v4; // eax
  CUtlMemory<KeyValues *,int> *v5; // ecx
  const unsigned __int8 *v6; // eax
  CUtlMemory<KeyValues *,int> *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // esi
  yaSSL::SSL_CTX *v10; // ecx
  CSplitScreenAddedConVar *v11; // eax
  unsigned int m_ChannelID; // ecx
  struct Error v13; // esi
  unsigned __int8 *m_Flags; // edi
  unsigned __int8 *v16; // esi
  unsigned int v17; // [esp-4h] [ebp-4A0h]
  int v18; // [esp+0h] [ebp-49Ch]
  const char *v19; // [esp+0h] [ebp-49Ch]
  CUtlMemory<KeyValues *,int> *v20; // [esp+0h] [ebp-49Ch]
  const CNonFatalLoggingResponsePolicy *v21; // [esp+0h] [ebp-49Ch]
  const CNonFatalLoggingResponsePolicy *v22; // [esp+0h] [ebp-49Ch]
  sockaddr *v23; // [esp+4h] [ebp-498h]
  LoggingContext_t s; // [esp+Ch] [ebp-490h] BYREF
  int v25; // [esp+1Ch] [ebp-480h]
  CNonFatalLoggingResponsePolicy v26; // [esp+24h] [ebp-478h] BYREF
  int v27; // [esp+44h] [ebp-458h]

  Method = (const char *)yaSSL::SSL_CTX::getMethod(this: a2);
  yaSSL::input_buffer::allocate(
    this: (CUtlString *)&this->m_XLSPPortMapping.m_Tree.m_Elements.m_nGrowSize,
    s: Method,
    a3: v18);
  v4 = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: a2);
  yaSSL::SSL_CTX::getCert(this: v5, a2: v4);
  yaSSL::input_buffer::assign(
    this: (yaSSL::input_buffer *)&this->m_XLSPPortMapping.m_Tree.m_Elements.m_nGrowSize,
    src: v6,
    a3: v17);
  LOBYTE(v7) = mySTL::list<yaSSL::input_buffer *>::front(this, a2: v19, a3: v23);
  if ( v7 != nullptr )
  {
    yaSSL::SSL_CTX::getCert(this: v7, a2: v20);
    v9 = v8;
    v11 = (CSplitScreenAddedConVar *)yaSSL::SSL_CTX::getMethod(this: v10);
    m_ChannelID = (unsigned int)v11;
    s.m_ChannelID = (int)v11;
    if ( v11 != nullptr )
    {
      v11 = operator new[](sz: v11);
      m_ChannelID = s.m_ChannelID;
    }
    s.m_Flags = (LoggingChannelFlags_t)v11;
    memcpy(dst: (unsigned __int8 *)v11, src: v9, count: m_ChannelID);
    s.m_Color = 0;
    v25 = 0;
    TaoCrypt::CertDecoder::CertDecoder(this: &v26, &s);
    TaoCrypt::CertDecoder::DecodeToKey(result: v21);
    v13.lpVtbl = (struct ErrorVtbl *)TaoCrypt::BER_Decoder::GetError(this: (TaoCrypt::BER_Decoder *)&v26).lpVtbl->QueryInterface;
    if ( v13.lpVtbl != nullptr )
    {
      TaoCrypt::CertDecoder::~CertDecoder(result: v22);
      m_Flags = (unsigned __int8 *)s.m_Flags;
      memset(dst: (unsigned __int8 *)s.m_Flags, value: 0, count: s.m_ChannelID);
      TaoCrypt::tcArrayDelete<unsigned char>(ptr: m_Flags);
      return v13.lpVtbl;
    }
    this->m_fdset.fd_array[5] = (v27 != 645) + 1;
    TaoCrypt::CertDecoder::~CertDecoder(result: v22);
    v16 = (unsigned __int8 *)s.m_Flags;
    memset(dst: (unsigned __int8 *)s.m_Flags, value: 0, count: s.m_ChannelID);
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: v16);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042EFC0
// Name: struct yaSSL::del_ptr_zero mySTL::for_each<class mySTL::list<class TaoCrypt::Signer __near *>::iterator,struct yaSSL::del_ptr_zero>(class mySTL::list<class TaoCrypt::Signer __near *>::iterator,class mySTL::list<class TaoCrypt::Signer __near *>::iterator,struct yaSSL::del_ptr_zero)
// Source: json
//------------------------------------------------------------------------------
char __cdecl mySTL::for_each<mySTL::list<TaoCrypt::Signer *>::iterator,yaSSL::del_ptr_zero>(int a1, int a2, char a3)
{
  int i; // eax
  TaoCrypt::Signer *v5; // [esp-4h] [ebp-4h]

  for ( i = a1; i != a2; a1 = i )
  {
    v5 = *(TaoCrypt::Signer **)(i + 8);
    *(_DWORD *)(i + 8) = 0;
    yaSSL::ysDelete<TaoCrypt::Signer>(a1: v5);
    i = *(_DWORD *)(a1 + 4);
  }
  return a3;
}

//------------------------------------------------------------------------------
// Address: 0x0042F000
// Name: public: yaSSL::CertManager::~CertManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertManager::~CertManager(ShortVector *this)
{
  const char *v2; // [esp+0h] [ebp-10h]
  const char *v3; // [esp+0h] [ebp-10h]
  bool (__cdecl *op)(const sockaddr_in *, const sockaddr_in *); // [esp+Ch] [ebp-4h]

  yaSSL::ysDelete<yaSSL::X509>(ptr: *((char **)this + 14));
  mySTL::for_each<mySTL::list<TaoCrypt::Signer *>::iterator,yaSSL::del_ptr_zero>(
    a1: *((_DWORD *)this + 17),
    a2: 0,
    a3: 0);
  LOBYTE(op) = 0;
  mySTL::for_each<mySTL::list<yaSSL::x509 *>::iterator,yaSSL::del_ptr_zero>(a1: *((_DWORD *)this + 7), a2: 0, op);
  LOBYTE(op) = 0;
  mySTL::for_each<mySTL::list<yaSSL::x509 *>::iterator,yaSSL::del_ptr_zero>(a1: *(_DWORD *)&this->x, a2: 0, op);
  mySTL::list<TaoCrypt::Signer *>::~list<TaoCrypt::Signer *>(this: (Vector *)((char *)this + 68));
  yaSSL::input_buffer::~input_buffer(this: (CUtlString *)(this + 5), a2: v2);
  mySTL::list<TaoCrypt::Signer *>::~list<TaoCrypt::Signer *>(this: (Vector *)((char *)this + 28));
  yaSSL::input_buffer::~input_buffer(this: (CUtlString *)((char *)this + 12), a2: v3);
  mySTL::list<TaoCrypt::Signer *>::~list<TaoCrypt::Signer *>((Vector *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0043BB50
// Name: public: yaSSL::x509::~x509(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00429B70
// Name: struct mySTL::pair<int,struct yaSSL::Message __near * (*)(void)> __near * mySTL::uninit_copy<struct mySTL::pair<int,struct yaSSL::Message __near * (*)(void)> __near *,struct mySTL::pair<int,struct yaSSL::Message __near * (*)(void)> __near *>(struct mySTL::pair<int,struct yaSSL::Message __near * (*)(void)> __near *,struct mySTL::pair<int,struct yaSSL::Message __near * (*)(void)> __near *,struct mySTL::pair<int,struct yaSSL::Message __near * (*)(void)> __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall mySTL::uninit_copy<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *,mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *>(
        const CUtlString *first,
        CThreadManualEvent *last,
        CThreadManualEvent *lasta,
        CThreadManualEvent *place)
{
  CThreadManualEvent *i; // ecx

  for ( i = last; i != lasta; ++place )
  {
    if ( place != nullptr )
    {
      place->m_hSyncObject = i->m_hSyncObject;
      *(_DWORD *)&place->m_bCreatedHandle = *(_DWORD *)&i->m_bCreatedHandle;
    }
    ++i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429BA0
// Name: struct mySTL::pair<int,struct yaSSL::Message __near * (*)(void)> __near * mySTL::GetArrayMemory<struct mySTL::pair<int,struct yaSSL::Message __near * (*)(void)>>(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall mySTL::GetArrayMemory<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)>>(
        const CUtlMemory<CUtlString,int>::Iterator_t *items,
        const CSplitScreenAddedConVar *itemsa)
{
  return operator new[](sz: itemsa);
}

//------------------------------------------------------------------------------
// Address: 0x0042F090
// Name: void operator delete(void __near *,struct yaSSL::new_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall operator delete(KeyValues *ptr, void *ptra)
{
  if ( ptra != nullptr )
    free(pMem: ptra);
}

//------------------------------------------------------------------------------
// Address: 0x0042F0A0
// Name: void operator delete[](void __near *,struct TaoCrypt::new_t)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall operator delete[](KeyValues *ptr, KeyValues *ptra)
{
  operator delete(ptr: ptra, ptra);
}
