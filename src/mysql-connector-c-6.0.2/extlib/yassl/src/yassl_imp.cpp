// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/yassl_imp.cpp
// Functions: 161
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\yassl_imp.h"

//------------------------------------------------------------------------------
// Address: 0x004169E0
// Name: void yaSSL::ysDelete<unsigned char>(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ysDelete<unsigned char>(
        CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *result,
        KeyValues *ptr)
{
  operator delete(ptr);
}

//------------------------------------------------------------------------------
// Address: 0x004210A0
// Name: public: virtual int yaSSL::EncryptedPreMasterSecret::get_length(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::EncryptedPreMasterSecret::get_length(CUtlMemory<KeyValues *,int> *this)
{
  return this->m_nGrowSize;
}

//------------------------------------------------------------------------------
// Address: 0x00427EB0
// Name: public: virtual void yaSSL::ServerKeyBase::build(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ServerKeyBase::build(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00427EE0
// Name: public: yaSSL::ProtocolVersion::ProtocolVersion(unsigned char,unsigned char)
// Source: json
//------------------------------------------------------------------------------
yaSSL::ProtocolVersion *__thiscall yaSSL::ProtocolVersion::ProtocolVersion(
        yaSSL::ProtocolVersion *this,
        unsigned __int8 maj,
        unsigned __int8 min)
{
  *(_BYTE *)this = maj;
  *((_BYTE *)this + 1) = min;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00427F00
// Name: public: void yaSSL::EncryptedPreMasterSecret::alloc(int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::EncryptedPreMasterSecret::alloc(_DWORD *this, int sz)
{
  CSplitScreenAddedConVar *result; // eax

  *(this + 2) = sz;
  result = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  *(this + 1) = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427F30
// Name: public: yaSSL::ClientDiffieHellmanPublic::ClientDiffieHellmanPublic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ClientDiffieHellmanPublic::ClientDiffieHellmanPublic(Quaternion *this)
{
  LODWORD(this->x) = &yaSSL::ClientDiffieHellmanPublic::`vftable';
  this->z = 0.0;
  this->w = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x00427F50
// Name: public: void yaSSL::ClientDiffieHellmanPublic::alloc(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ClientDiffieHellmanPublic::alloc(
        Quaternion *this,
        const CSplitScreenAddedConVar *sz,
        bool offset)
{
  LODWORD(this->z) = (char *)sz + (offset ? 2 : 0);
  LODWORD(this->w) = operator new[](sz);
}

//------------------------------------------------------------------------------
// Address: 0x00427F80
// Name: public: virtual int yaSSL::DH_Server::get_length(void)const
// Source: json
//------------------------------------------------------------------------------
CThreadFastMutex *__thiscall yaSSL::DH_Server::get_length(_DWORD *this)
{
  return (CThreadFastMutex *)*(this + 8);
}

//------------------------------------------------------------------------------
// Address: 0x00427F90
// Name: public: virtual unsigned char __near * yaSSL::DH_Server::get_serverKey(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 *__thiscall yaSSL::DH_Server::get_serverKey(yaSSL::DH_Server *this)
{
  return *((unsigned __int8 **)this + 9);
}

//------------------------------------------------------------------------------
// Address: 0x00427FA0
// Name: public: void yaSSL::Parameters::SetCipherNames(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Parameters::SetCipherNames(yaSSL::Parameters *this)
{
  int v1; // edx
  unsigned __int8 *v2; // esi
  yaSSL::Parameters *v3; // edi
  int v4; // ebp
  yaSSL::Parameters *v5; // [esp+0h] [ebp-8h]
  int pos; // [esp+4h] [ebp-4h]

  v1 = 0;
  v5 = this;
  if ( *((unsigned __int8 *)this + 46) >> 1 != 0 )
  {
    v2 = (unsigned __int8 *)this + 223;
    v3 = this + 12;
    v4 = *((unsigned __int8 *)this + 46) >> 1;
    pos = v4;
    do
    {
      strncpy(
        dest: v2,
        source: *((unsigned __int8 **)cipher_names_2 + *(unsigned __int8 *)v3),
        count: strlen(*((const char **)cipher_names_2 + *(unsigned __int8 *)v3)) + 1);
      v2 += 48;
      v3 = (yaSSL::Parameters *)((char *)v3 + 2);
      --v4;
    }
    while ( v4 != 0 );
    this = v5;
    v1 = pos;
  }
  *((_BYTE *)this + 48 * v1 + 223) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00428020
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,struct yaSSL::RecordLayerHeader __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL::operator>>(int a1, CThread hdr)
{
  unsigned __int8 m_pMemory; // [esp+Dh] [ebp+5h]

  hdr.dtr_CThread = (void (__thiscall *)(CThread *))LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
  LOBYTE(hdr.Start) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  BYTE1(hdr.Start) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
  m_pMemory = (unsigned __int8)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  yaSSL::ato16(c: (const IntVector4D *)m_pMemory);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00428120
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,struct yaSSL::Message __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall yaSSL::operator>>(void *input, int a2, void *(__thiscall ***a3)(_DWORD, int))
{
  return (**a3)(a1: a3, a2);
}

//------------------------------------------------------------------------------
// Address: 0x00428130
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,class yaSSL::HandShakeHeader __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL::operator>>(int a1, int a2)
{
  *(_DWORD *)(a2 + 4) = LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
  *(_BYTE *)(a2 + 8) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  *(_BYTE *)(a2 + 9) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  *(_BYTE *)(a2 + 10) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x004281C0
// Name: public: virtual enum yaSSL::ContentType yaSSL::HandShakeHeader::get_type(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::HandShakeHeader::get_type()
{
  return 22;
}

//------------------------------------------------------------------------------
// Address: 0x004281D0
// Name: public: virtual unsigned short yaSSL::HandShakeHeader::get_length(void)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004281E0
// Name: public: void yaSSL::HandShakeHeader::set_length(unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00428200
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::HandShakeHeader::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
struct yaSSL::input_buffer *__thiscall yaSSL::HandShakeHeader::set(
        yaSSL::HandShakeHeader *this,
        struct yaSSL::input_buffer *a2)
{
  return (struct yaSSL::input_buffer *)yaSSL::operator>>(a1: (int)a2, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x00428220
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::HandShakeHeader::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
struct yaSSL::output_buffer *__thiscall yaSSL::HandShakeHeader::get(
        yaSSL::HandShakeHeader *this,
        struct yaSSL::output_buffer *a2)
{
  return (struct yaSSL::output_buffer *)yaSSL::operator<<();
}

//------------------------------------------------------------------------------
// Address: 0x00428240
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,class yaSSL::ChangeCipherSpec __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL::operator>>(int a1, string_criteria_t *a2)
{
  a2->length = LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00428280
// Name: public: yaSSL::ChangeCipherSpec::ChangeCipherSpec(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ChangeCipherSpec::ChangeCipherSpec(CUtlVector<char *,CUtlMemory<char *,int> > *this)
{
  this->m_Memory.m_pMemory = (char **)&yaSSL::ChangeCipherSpec::`vftable';
  this->m_Memory.m_nAllocationCount = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428290
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::ChangeCipherSpec::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::ChangeCipherSpec::set(
        CUtlVector<char *,CUtlMemory<char *,int> > *this@<ecx>,
        int (__cdecl *in)(char *const *, char *const *),
        int a3,
        int a4)
{
  yaSSL::operator>>(a1: (int)in, a2: (string_criteria_t *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004282B0
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::ChangeCipherSpec::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
struct yaSSL::output_buffer *__thiscall yaSSL::ChangeCipherSpec::get(
        yaSSL::ChangeCipherSpec *this,
        struct yaSSL::output_buffer *output)
{
  return (struct yaSSL::output_buffer *)yaSSL::operator<<((const char *)output);
}

//------------------------------------------------------------------------------
// Address: 0x004282D0
// Name: public: virtual void yaSSL::ChangeCipherSpec::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ChangeCipherSpec::Process(const unsigned __int8 *this, int __formal, KeyValues *ssl)
{
  CThreadSyncObject *Hashes; // eax
  void (__thiscall *v4)(IConsoleDisplayFunc *, char *, unsigned int); // [esp-4h] [ebp-8h]
  const st_mysql_methods *v5; // [esp+0h] [ebp-4h]
  const st_mysql_methods *v6; // [esp+0h] [ebp-4h]

  yaSSL::SSL::useSecurity(this: (char *)ssl);
  LOBYTE(yaSSL::Security::use_parms(result: v5)->unbuffered_fetch) = 0;
  yaSSL::SSL::useSecurity(this: (char *)ssl);
  if ( (unsigned __int8)yaSSL::Security::get_resuming() != 0 )
  {
    yaSSL::SSL::useSecurity(this: (char *)ssl);
    if ( yaSSL::Security::use_parms(result: v6)->read_query_result != (char (__cdecl *)(st_mysql *))1 )
      return;
    v4 = server;
  }
  else
  {
    yaSSL::SSL::useSecurity(this: (char *)ssl);
    if ( yaSSL::Security::use_parms(result: v6)->read_query_result != nullptr )
      return;
    v4 = client;
  }
  Hashes = yaSSL::SSL::getHashes(this: (CThreadSyncObject *)ssl);
  yaSSL::Crypto::get_certManager(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)Hashes, a2: (int)v4);
  yaSSL::buildFinished(result: (hostent *)ssl);
}

//------------------------------------------------------------------------------
// Address: 0x00428350
// Name: public: yaSSL::Alert::Alert(enum yaSSL::AlertLevel,enum yaSSL::AlertDescription)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall yaSSL::Alert::Alert(_DWORD *this, int a2, int a3)
{
  *this = &yaSSL::Alert::`vftable';
  *(this + 1) = a2;
  *(this + 2) = a3;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428370
// Name: public: virtual enum yaSSL::ContentType yaSSL::Alert::get_type(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::Alert::get_type()
{
  return 21;
}

//------------------------------------------------------------------------------
// Address: 0x00428380
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,class yaSSL::Alert __near &)
// Source: json
//------------------------------------------------------------------------------
int __cdecl yaSSL::operator>>(int a1, int a2)
{
  *(_DWORD *)(a2 + 4) = LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
  *(_DWORD *)(a2 + 8) = LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00428400
// Name: public: virtual void yaSSL::Alert::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge yaSSL::Alert::Process@<al>(
        _DWORD *a1@<ecx>,
        CUtlMemory<KeyValues *,int> *a2@<ebx>,
        CUtlMemory<KeyValues *,int> *a3,
        char *a4)
{
  _DWORD *v4; // edi
  const st_mysql_methods *v5; // eax
  int v6; // ebx
  yaSSL::SSL_CTX *v7; // eax
  const struct SSL_METHOD *Method; // eax
  int v9; // edi
  CUtlMemory<KeyValues *,int> *v10; // eax
  int v11; // eax
  int v12; // eax
  int i; // ebx
  char *v14; // ecx
  char *v15; // edi
  ShortVector *v16; // eax
  _DWORD *v17; // eax
  int v20; // [esp-4h] [ebp-48h]
  __int16 v21; // [esp-4h] [ebp-48h]
  const st_mysql_methods *v22; // [esp-4h] [ebp-48h]
  int v23; // [esp-4h] [ebp-48h]
  const st_mysql_methods *v24; // [esp-4h] [ebp-48h]
  CUtlMemory<KeyValues *,int> *v25; // [esp-4h] [ebp-48h]
  const st_mysql_methods *v26; // [esp+0h] [ebp-44h]
  CThreadSyncObject *v27; // [esp+0h] [ebp-44h]
  __int16 v28; // [esp+0h] [ebp-44h]
  __int16 v29; // [esp+4h] [ebp-40h]
  __int16 v30; // [esp+4h] [ebp-40h]
  unsigned int v31; // [esp+8h] [ebp-3Ch]
  __int16 v32; // [esp+8h] [ebp-3Ch]
  int ivExtra; // [esp+Ch] [ebp-38h]
  unsigned int digestSz; // [esp+14h] [ebp-30h]
  char v36; // [esp+18h] [ebp-2Ch] BYREF
  char dst[20]; // [esp+2Ch] [ebp-18h] BYREF

  v4 = a1;
  yaSSL::SSL::useSecurity(this: a4);
  v5 = yaSSL::Security::use_parms(result: v26);
  if ( LOBYTE(v5->unbuffered_fetch) == 0 )
  {
    v6 = (*(unsigned __int16 (__thiscall **)(_DWORD *))(*v4 + 16))(a1: v4);
    ivExtra = yaSSL::EncryptedPreMasterSecret::get_length(this: a3) - v6;
    yaSSL::SSL_CTX::getCert(this: a3, a2);
    if ( (unsigned __int8)yaSSL::SSL::isTLS(a1: v20, a2: v27, a3: v29, a4: v31) != 0 )
      yaSSL::TLS_hmac();
    else
      yaSSL::hmac();
    yaSSL::sslHashes::get_MD5(this: (ShortVector *)a4, a2: v21, a3: v28, a4: v30, a5: v32);
    Method = yaSSL::SSL_CTX::getMethod(this: v7);
    v9 = (*(int (__thiscall **)(const struct SSL_METHOD *))(*(_DWORD *)Method + 12))(a1: Method);
    digestSz = v9;
    yaSSL::input_buffer::read(this: (CUtlString *)a3, dst);
    yaSSL::SSL::useSecurity(this: a4);
    if ( yaSSL::Security::use_parms(result: v22)->read_rows == (st_mysql_data *(__cdecl *)(st_mysql *, st_mysql_field *, unsigned int))1 )
    {
      ivExtra = 0;
      if ( (unsigned __int8)yaSSL::SSL::isTLSv1_1(a1: v23, a2: v27, a3: v29, a4: v31) != 0 )
      {
        yaSSL::sslHashes::get_MD5(this: (ShortVector *)a4, a2: (__int16)v24, a3: (__int16)v27, a4: v29, a5: v31);
        yaSSL::SSL_CTX::getCert(this: v10, a2: v25);
        ivExtra = (*(int (__thiscall **)(int))(*(_DWORD *)v11 + 16))(a1: v11);
      }
      yaSSL::SSL::useSecurity(this: a4);
      v12 = HIWORD(yaSSL::Security::use_parms(result: v24)->unbuffered_fetch) - ivExtra - v9 - v6;
      if ( v12 > 0 )
      {
        for ( i = v12; i != 0; --i )
          yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
      }
    }
    v5 = (const st_mysql_methods *)v9;
    v14 = &v36;
    v15 = dst;
    if ( digestSz >= 4 )
    {
      while ( *(_DWORD *)v15 == *(_DWORD *)v14 )
      {
        v5 = (const st_mysql_methods *)((char *)v5 - 4);
        v14 += 4;
        v15 += 4;
        if ( (unsigned int)v5 < 4 )
          goto LABEL_14;
      }
      goto LABEL_20;
    }
LABEL_14:
    if ( v5 != nullptr )
    {
      if ( *v14 != *v15
        || (unsigned int)v5 > 1
        && (v14[1] != v15[1] || (unsigned int)v5 > 2 && (LOBYTE(v5) = v14[2], (_BYTE)v5 != v15[2])) )
      {
LABEL_20:
        LOBYTE(v5) = yaSSL::SSL::SetError(a1: a4, a2: 112);
        return (char)v5;
      }
    }
    v4 = a1;
  }
  if ( v4[1] == 2 )
  {
    v16 = (ShortVector *)yaSSL::SSL::useStates(this: a4);
    yaSSL::sslHashes::get_MD5(this: v16, a2: (__int16)v27, a3: v29, a4: v31, a5: ivExtra);
    *v17 = 0;
    yaSSL::SSL::useStates(this: a4);
    *(_DWORD *)TaoCrypt::AbstractRing::MultiplicativeGroup() = 0;
    LOBYTE(v5) = yaSSL::SSL::SetError(a1: a4, a2: v4[2]);
  }
  return (char)v5;
}

//------------------------------------------------------------------------------
// Address: 0x004285D0
// Name: public: yaSSL::Data::Data(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlCharConversion *__thiscall yaSSL::Data::Data(_WORD *this)
{
  *(_DWORD *)this = &yaSSL::Data::`vftable';
  *(this + 2) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return (const CUtlCharConversion *)this;
}

//------------------------------------------------------------------------------
// Address: 0x004285F0
// Name: public: yaSSL::Data::Data(unsigned short,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
yaSSL::Data *__thiscall yaSSL::Data::Data(yaSSL::Data *this, unsigned __int16 a2, unsigned __int8 *a3)
{
  this->m_nLength = (int)&yaSSL::Data::`vftable';
  LOWORD(this->m_pReplacementString) = a2;
  *((_DWORD *)this + 2) = a3;
  *((_DWORD *)this + 3) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428620
// Name: public: void yaSSL::Data::SetData(unsigned short,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall yaSSL::Data::SetData(int this, unsigned __int16 len, const LoggingContext_t *buffer)
{
  *(_WORD *)(this + 4) = len;
  *(_DWORD *)(this + 12) = buffer;
  return len;
}

//------------------------------------------------------------------------------
// Address: 0x00428640
// Name: public: virtual enum yaSSL::ContentType yaSSL::Data::get_type(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::Data::get_type(CUtlCharConversion *this)
{
  return 23;
}

//------------------------------------------------------------------------------
// Address: 0x00428650
// Name: public: virtual unsigned short yaSSL::Data::get_length(void)const
// Source: json
//------------------------------------------------------------------------------
__int16 __thiscall yaSSL::Data::get_length(CUtlCharConversion *this)
{
  return *(_WORD *)&this->m_nEscapeChar;
}

//------------------------------------------------------------------------------
// Address: 0x00428660
// Name: public: void yaSSL::Data::set_length(unsigned short)
// Source: json
//------------------------------------------------------------------------------
__int16 __userpurge yaSSL::Data::set_length@<ax>(CUtlCharConversion *this@<ecx>, const char *l, int *a3)
{
  *(_WORD *)&this->m_nEscapeChar = (_WORD)l;
  return (__int16)l;
}

//------------------------------------------------------------------------------
// Address: 0x00428690
// Name: public: virtual void yaSSL::Data::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __stdcall yaSSL::Data::Process(CUtlMemory<KeyValues *,int> *result, char *a2)
{
  ShortVector *v2; // ebp
  int unbuffered_fetch_high; // esi
  int v4; // ebx
  CUtlMemory<KeyValues *,int> *v5; // eax
  int v6; // eax
  int length; // ebp
  int v8; // eax
  int v9; // edx
  yaSSL::SSL_CTX *v10; // eax
  const struct SSL_METHOD *Method; // eax
  int v12; // eax
  const CUtlString *v13; // esi
  const CSplitScreenAddedConVar *v14; // ecx
  const CSplitScreenAddedConVar *v15; // ecx
  struct yaSSL::input_buffer *v16; // eax
  const char *v17; // eax
  unsigned int v18; // ebx
  int i; // ebx
  unsigned int v20; // eax
  char *v21; // ecx
  char *v22; // esi
  const st_mysql_methods *v23; // [esp+0h] [ebp-5Ch]
  const st_mysql_methods *v24; // [esp+0h] [ebp-5Ch]
  int v25; // [esp+0h] [ebp-5Ch]
  CUtlMemory<KeyValues *,int> *v26; // [esp+0h] [ebp-5Ch]
  CUtlMemory<KeyValues *,int> *v27; // [esp+0h] [ebp-5Ch]
  CUtlMemory<KeyValues *,int> *v28; // [esp+0h] [ebp-5Ch]
  int v29; // [esp+0h] [ebp-5Ch]
  const char *v30; // [esp+0h] [ebp-5Ch]
  int v31; // [esp+0h] [ebp-5Ch]
  CThreadSyncObject *v32; // [esp+4h] [ebp-58h]
  CThreadSyncObject *v33; // [esp+4h] [ebp-58h]
  CThreadSyncObject *v34; // [esp+4h] [ebp-58h]
  __int16 v35; // [esp+8h] [ebp-54h]
  bool v36; // [esp+8h] [ebp-54h]
  bool v37; // [esp+8h] [ebp-54h]
  unsigned int v38; // [esp+Ch] [ebp-50h]
  unsigned int v39; // [esp+Ch] [ebp-50h]
  unsigned int v40; // [esp+Ch] [ebp-50h]
  CUtlString *v41; // [esp+10h] [ebp-4Ch]
  CUtlString *v42; // [esp+10h] [ebp-4Ch]
  int digestSz; // [esp+14h] [ebp-48h]
  int padByte; // [esp+18h] [ebp-44h]
  int pad; // [esp+1Ch] [ebp-40h]
  CUtlString v46; // [esp+20h] [ebp-3Ch] BYREF
  char v47; // [esp+30h] [ebp-2Ch] BYREF
  char dst[20]; // [esp+44h] [ebp-18h] BYREF

  v2 = (ShortVector *)a2;
  yaSSL::SSL::useSecurity(this: a2);
  unbuffered_fetch_high = HIWORD(yaSSL::Security::use_parms(result: v23)->unbuffered_fetch);
  v4 = 0;
  pad = 0;
  padByte = 0;
  yaSSL::SSL::useSecurity(this: a2);
  if ( yaSSL::Security::use_parms(result: v24)->read_rows == (st_mysql_data *(__cdecl *)(st_mysql *, st_mysql_field *, unsigned int))1 )
  {
    if ( (unsigned __int8)yaSSL::SSL::isTLSv1_1(a1: v25, a2: v32, a3: v35, a4: v38) != 0 )
    {
      yaSSL::sslHashes::get_MD5(this: (ShortVector *)a2, a2: (__int16)v26, a3: (__int16)v32, a4: v35, a5: v38);
      yaSSL::SSL_CTX::getCert(this: v5, a2: v27);
      v4 = (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 16))(a1: v6);
    }
    length = yaSSL::EncryptedPreMasterSecret::get_length(this: result);
    yaSSL::SSL_CTX::getCert(this: result, a2: v26);
    v9 = *(unsigned __int8 *)(unbuffered_fetch_high - v4 + v8 + length - 1);
    v2 = (ShortVector *)a2;
    pad = v9;
    padByte = 1;
  }
  yaSSL::sslHashes::get_MD5(this: v2, a2: v25, a3: (__int16)v32, a4: v35, a5: v38);
  Method = yaSSL::SSL_CTX::getMethod(this: v10);
  v12 = (*(int (__thiscall **)(const struct SSL_METHOD *))(*(_DWORD *)Method + 12))(a1: Method);
  v13 = (const CUtlString *)(unbuffered_fetch_high - v12 - v4 - padByte - pad);
  digestSz = v12;
  yaSSL::EncryptedPreMasterSecret::get_length(this: result);
  yaSSL::SSL_CTX::getCert(this: result, a2: v28);
  if ( v13 != nullptr )
  {
    if ( (unsigned __int8)yaSSL::SSL::CompressionOn(a1: v29, a2: v33, a3: v36, a4: v39) != 0 )
    {
      CUtlString::CUtlString(this: &v46);
      if ( yaSSL::Compress() == -1 )
      {
        yaSSL::SSL::SetError(a1: v2, a2: 119);
        yaSSL::input_buffer::~input_buffer(this: &v46, a2: v30);
        return;
      }
      v41 = (CUtlString *)operator new(sz: v15);
      if ( v41 != nullptr )
      {
        yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v46);
        yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v46);
        yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v46);
        v16 = (struct yaSSL::input_buffer *)yaSSL::input_buffer::input_buffer(this: v41);
      }
      else
      {
        v16 = nullptr;
      }
      yaSSL::SSL::addData(this: (yaSSL::SSL *)v2, a2: v16);
      yaSSL::input_buffer::~input_buffer(this: &v46, a2: v30);
    }
    else
    {
      if ( operator new(sz: v14) != nullptr )
      {
        v42 = (CUtlString *)yaSSL::input_buffer::input_buffer(result: v13);
        yaSSL::SSL::addData(this: (yaSSL::SSL *)v2, a2: (struct yaSSL::input_buffer *)v42);
      }
      else
      {
        v42 = nullptr;
        yaSSL::SSL::addData(this: (yaSSL::SSL *)v2, a2: nullptr);
      }
      v17 = (const char *)yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)v42);
      yaSSL::input_buffer::read(this: (CUtlString *)result, dst: v17);
      yaSSL::input_buffer::add_size(this: v42, i: (const char *)v13, a3: (int)v30);
    }
    if ( (unsigned __int8)yaSSL::SSL::isTLS(a1: v31, a2: v34, a3: v37, a4: v40) != 0 )
      yaSSL::TLS_hmac();
    else
      yaSSL::hmac();
  }
  v18 = digestSz;
  yaSSL::input_buffer::read(this: (CUtlString *)result, dst);
  if ( pad > 0 )
  {
    for ( i = pad; i != 0; --i )
      yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
    v18 = digestSz;
  }
  if ( padByte != 0 )
    yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
  if ( v13 != nullptr )
  {
    v20 = v18;
    v21 = &v47;
    v22 = dst;
    if ( v18 >= 4 )
    {
      while ( *(_DWORD *)v22 == *(_DWORD *)v21 )
      {
        v20 -= 4;
        v21 += 4;
        v22 += 4;
        if ( v20 < 4 )
          goto LABEL_30;
      }
      goto LABEL_36;
    }
LABEL_30:
    if ( v20 != 0 && (*v21 != *v22 || v20 > 1 && (v21[1] != v22[1] || v20 > 2 && v21[2] != v22[2])) )
LABEL_36:
      yaSSL::SSL::SetError(a1: v2, a2: 112);
  }
  else
  {
    yaSSL::SSL::get_SEQIncrement(this: (yaSSL::SSL *)v2, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004289B0
// Name: public: unsigned char const __near * yaSSL::Certificate::get_buffer(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Certificate::get_buffer(CUtlMemory<KeyValues *,int> **this, CUtlMemory<KeyValues *,int> *a2)
{
  yaSSL::SSL_CTX::getCert(this: *(this + 2), a2);
}

//------------------------------------------------------------------------------
// Address: 0x00428A30
// Name: public: virtual void yaSSL::Certificate::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Certificate::Process(_RTL_CRITICAL_SECTION *this, CUtlString *cert_sz, ShortVector *tmp)
{
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v3; // eax
  yaSSL::CertManager *v4; // eax
  yaSSL::CertManager *v5; // ebx
  yaSSL::x509 *v6; // eax
  struct yaSSL::x509 *v7; // edi
  CUtlMemory<KeyValues *,int> *Method; // eax
  const char *v9; // eax
  int v10; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v11; // eax
  __int16 v12; // [esp+0h] [ebp-10h]
  int v13; // [esp+0h] [ebp-10h]
  const st_mysql_methods *v14; // [esp+0h] [ebp-10h]
  int v15; // [esp+0h] [ebp-10h]
  __int16 v16; // [esp+4h] [ebp-Ch]
  KeyValues *const *v17; // [esp+4h] [ebp-Ch]
  __int16 v18; // [esp+8h] [ebp-8h]
  __int16 list_sz; // [esp+Ch] [ebp-4h]
  unsigned int list_sza; // [esp+Ch] [ebp-4h]

  yaSSL::sslHashes::get_MD5(this: tmp, a2: v12, a3: v16, a4: v18, a5: list_sz);
  LOBYTE(v4) = yaSSL::Crypto::get_certManager(this: v3, a2: v13);
  v5 = v4;
  yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
  yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
  yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
  yaSSL::c24to32();
  for ( ; list_sza != 0; list_sza += -3 - (_DWORD)cert_sz )
  {
    yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
    yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
    yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
    yaSSL::c24to32();
    v6 = (yaSSL::x509 *)operator new(sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
    if ( v6 != nullptr )
      v7 = (struct yaSSL::x509 *)yaSSL::x509::x509(this: v6, a2: (unsigned int)cert_sz);
    else
      v7 = nullptr;
    yaSSL::CertManager::AddPeerCert(this: v5, a2: v7);
    Method = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)v7);
    yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)v7, a2: Method);
    yaSSL::input_buffer::read(this: cert_sz, dst: v9);
  }
  v10 = yaSSL::CertManager::Validate(this: v5);
  if ( v10 != 0 )
  {
    yaSSL::SSL::SetError(a1: tmp, a2: v10);
  }
  else
  {
    yaSSL::SSL::useSecurity(this: (char *)tmp);
    if ( yaSSL::Security::use_parms(result: v14)->read_query_result == (char (__cdecl *)(st_mysql *))1 )
    {
      v11 = (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)yaSSL::SSL::useStates(this: (char *)tmp);
      *(_DWORD *)yaSSL::States::useClient(this: v11, a2: v15, a3: v17) = 2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00428B90
// Name: public: yaSSL::Certificate::Certificate(void)
// Source: json
//------------------------------------------------------------------------------
_DWORD *__thiscall yaSSL::Certificate::Certificate(_DWORD *this)
{
  *this = &yaSSL::Certificate::`vftable';
  *(this + 2) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428BA0
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::HelloRequest::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::HelloRequest::set(CUtlVectorAutoPurge<char *> *this, int out)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00428BB0
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::Certificate::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00428BD0
// Name: public: virtual enum yaSSL::HandShakeType yaSSL::Certificate::get_type(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::Certificate::get_type()
{
  return 11;
}

//------------------------------------------------------------------------------
// Address: 0x00428BE0
// Name: public: yaSSL::ServerDHParams::ServerDHParams(void)
// Source: json
//------------------------------------------------------------------------------
yaSSL::ServerDHParams *__thiscall yaSSL::ServerDHParams::ServerDHParams(yaSSL::ServerDHParams *this)
{
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428C00
// Name: public: unsigned char __near * yaSSL::ServerDHParams::alloc_p(int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::ServerDHParams::alloc_p(_DWORD *this, matrix3x4_t *result)
{
  CSplitScreenAddedConVar *v3; // eax

  *this = result;
  v3 = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  *(this + 3) = v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00428C30
// Name: public: unsigned char __near * yaSSL::ServerDHParams::alloc_g(int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::ServerDHParams::alloc_g(_DWORD *this, matrix3x4_t *result)
{
  CSplitScreenAddedConVar *v3; // eax

  *(this + 1) = result;
  v3 = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  *(this + 4) = v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00428C60
// Name: public: unsigned char __near * yaSSL::ServerDHParams::alloc_pub(int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::ServerDHParams::alloc_pub(_DWORD *this, matrix3x4_t *result)
{
  CSplitScreenAddedConVar *v3; // eax

  *(this + 2) = result;
  v3 = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  *(this + 5) = v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00428C90
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,class yaSSL::ServerHello __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__stdcall yaSSL::operator>>(CUtlString *input, HWND__ *hello)
{
  char m_pMemory; // al

  *((_BYTE *)hello + 8) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  *((_BYTE *)hello + 9) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  yaSSL::input_buffer::read(this: input, dst: (const char *)hello + 10);
  m_pMemory = (char)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  *((_BYTE *)hello + 42) = m_pMemory;
  if ( m_pMemory != 0 )
    yaSSL::input_buffer::read(this: input, dst: (const char *)hello + 43);
  *((_BYTE *)hello + 75) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  *((_BYTE *)hello + 76) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  *((_DWORD *)hello + 20) = LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
  return input;
}

//------------------------------------------------------------------------------
// Address: 0x00428DD0
// Name: public: yaSSL::ServerHello::ServerHello(void)
// Source: json
//------------------------------------------------------------------------------
yaSSL::ServerHello *__thiscall yaSSL::ServerHello::ServerHello(yaSSL::ServerHello *this)
{
  *(_DWORD *)this = &yaSSL::ServerHello::`vftable';
  yaSSL::ProtocolVersion::ProtocolVersion(this: (yaSSL::ProtocolVersion *)this + 2, maj: 3u, min: 0);
  *(_DWORD *)((char *)this + 10) = 0;
  *(_DWORD *)((char *)this + 14) = 0;
  *(_DWORD *)((char *)this + 18) = 0;
  *(_DWORD *)((char *)this + 22) = 0;
  *(_DWORD *)((char *)this + 26) = 0;
  *(_DWORD *)((char *)this + 30) = 0;
  *(_DWORD *)((char *)this + 34) = 0;
  *(_DWORD *)((char *)this + 38) = 0;
  *(_DWORD *)((char *)this + 43) = 0;
  *(_DWORD *)((char *)this + 47) = 0;
  *(_DWORD *)((char *)this + 51) = 0;
  *(_DWORD *)((char *)this + 55) = 0;
  *(_DWORD *)((char *)this + 59) = 0;
  *(_DWORD *)((char *)this + 63) = 0;
  *(_DWORD *)((char *)this + 67) = 0;
  *(_DWORD *)((char *)this + 71) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00428E20
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::ServerHello::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall yaSSL::ServerHello::set(HWND__ *hello, CUtlString *input)
{
  return yaSSL::operator>>(input, hello);
}

//------------------------------------------------------------------------------
// Address: 0x00428E40
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::ServerHello::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
const tagMSG *__thiscall yaSSL::ServerHello::get(yaSSL::ServerHello *this, tagMSG *result)
{
  return yaSSL::operator<<(result);
}

//------------------------------------------------------------------------------
// Address: 0x00428E60
// Name: public: virtual void yaSSL::ServerHelloDone::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00428E80
// Name: public: yaSSL::ServerHelloDone::ServerHelloDone(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00428E90
// Name: public: virtual enum yaSSL::HandShakeType yaSSL::ServerHelloDone::get_type(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::ServerHelloDone::get_type()
{
  return 14;
}

//------------------------------------------------------------------------------
// Address: 0x00428EA0
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,class yaSSL::ClientHello __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<KeyValues *,int> *__cdecl yaSSL::operator>>(
        CUtlMemory<KeyValues *,int> *len,
        CUtlMemory<KeyValues *,int> *a2)
{
  int v2; // eax
  int v3; // ebp
  char m_pMemory; // al
  __int16 v5; // ax
  int v6; // eax
  char v7; // al
  int v8; // eax
  unsigned int v9; // ebx
  unsigned int v10; // eax
  unsigned int v11; // esi
  int v12; // eax
  CUtlMemory<KeyValues *,int> *v14; // [esp+0h] [ebp-14h]
  CUtlMemory<KeyValues *,int> *v15; // [esp+0h] [ebp-14h]
  int v16; // [esp+0h] [ebp-14h]
  CUtlMemory<KeyValues *,int> *v17; // [esp+0h] [ebp-14h]
  CUtlMemory<KeyValues *,int> *v18; // [esp+0h] [ebp-14h]
  int v19; // [esp+0h] [ebp-14h]
  _BYTE v20[4]; // [esp+10h] [ebp-4h] BYREF

  yaSSL::SSL_CTX::getCert(this: len, a2: v14);
  v3 = v2;
  LOBYTE(a2->m_nGrowSize) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  BYTE1(a2->m_nGrowSize) = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  yaSSL::input_buffer::read(this: (CUtlString *)len, dst: (const char *)&a2->m_nGrowSize + 2);
  m_pMemory = (char)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  BYTE2(a2[3].m_nAllocationCount) = m_pMemory;
  if ( m_pMemory != 0 )
    yaSSL::input_buffer::read(this: (CUtlString *)len, dst: (const char *)&a2[3].m_nAllocationCount + 3);
  v20[0] = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  v20[1] = yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  yaSSL::ato16(c: (const IntVector4D *)v20);
  v5 = (__int16)len;
  if ( (unsigned __int16)len >= 0x80u )
    v5 = 128;
  LOWORD(a2[6].m_nAllocationCount) = v5;
  yaSSL::input_buffer::read(this: (CUtlString *)len, dst: (const char *)&a2[6].m_nAllocationCount + 2);
  if ( (unsigned __int16)len > LOWORD(a2[6].m_nAllocationCount) )
  {
    yaSSL::SSL_CTX::getCert(this: len, a2: v15);
    yaSSL::Crypto::setCipher(
      this: (CUtlString *)len,
      i: (const char *)((unsigned __int16)len - LOWORD(a2[6].m_nAllocationCount) + v6),
      a3: v16);
  }
  v7 = (char)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  BYTE2(a2[17].m_pMemory) = v7;
  a2[17].m_nAllocationCount = 0;
  while ( BYTE2(a2[17].m_pMemory) != 0 )
  {
    --BYTE2(a2[17].m_pMemory);
    if ( LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory) == 0xDD )
      a2[17].m_nAllocationCount = 221;
  }
  --BYTE2(a2[17].m_pMemory);
  yaSSL::SSL_CTX::getCert(this: len, a2: v15);
  v9 = v8 - v3;
  yaSSL::SSL_CTX::getCert(this: a2, a2: v17);
  v11 = v10;
  if ( v9 < v10 )
  {
    yaSSL::SSL_CTX::getCert(this: len, a2: v18);
    yaSSL::Crypto::setCipher(this: (CUtlString *)len, i: (const char *)(v11 - v9 + v12), a3: v19);
  }
  return len;
}

//------------------------------------------------------------------------------
// Address: 0x00429100
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::ClientHello::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<KeyValues *,int> *__thiscall yaSSL::ClientHello::set(
        yaSSL::ClientHello *this,
        CUtlMemory<KeyValues *,int> *a2)
{
  return yaSSL::operator>>(len: a2, a2: (CUtlMemory<KeyValues *,int> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00429120
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::ClientHello::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
struct yaSSL::output_buffer *__thiscall yaSSL::ClientHello::get(yaSSL::ClientHello *this, QueuedPacket_t **a2)
{
  return (struct yaSSL::output_buffer *)yaSSL::operator<<(a1: a2, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00429150
// Name: public: unsigned char const __near * yaSSL::ClientHello::get_random(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall yaSSL::ClientHello::get_random(yaSSL::ClientHello *this)
{
  return (char *)this + 10;
}

//------------------------------------------------------------------------------
// Address: 0x00429160
// Name: public: yaSSL::ClientHello::ClientHello(void)
// Source: json
//------------------------------------------------------------------------------
yaSSL::ClientHello *__thiscall yaSSL::ClientHello::ClientHello(yaSSL::ClientHello *this)
{
  *this = (yaSSL::ClientHello)&yaSSL::ClientHello::`vftable';
  yaSSL::ProtocolVersion::ProtocolVersion(this: (yaSSL::ProtocolVersion *)this + 2, maj: 3u, min: 0);
  *(yaSSL::ClientHello *)((char *)this + 10) = nullptr;
  *(yaSSL::ClientHello *)((char *)this + 14) = nullptr;
  *(yaSSL::ClientHello *)((char *)this + 18) = nullptr;
  *(yaSSL::ClientHello *)((char *)this + 22) = nullptr;
  *(yaSSL::ClientHello *)((char *)this + 26) = nullptr;
  *(yaSSL::ClientHello *)((char *)this + 30) = nullptr;
  *(yaSSL::ClientHello *)((char *)this + 34) = nullptr;
  *(yaSSL::ClientHello *)((char *)this + 38) = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004291A0
// Name: public: yaSSL::ClientHello::ClientHello(struct yaSSL::ProtocolVersion,bool)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall yaSSL::ClientHello::ClientHello(char *this, __int16 pv, bool useCompression)
{
  *((_WORD *)this + 4) = pv;
  *(_DWORD *)this = &yaSSL::ClientHello::`vftable';
  *((_DWORD *)this + 52) = useCompression ? 0xDD : 0;
  *(_DWORD *)(this + 10) = 0;
  *(_DWORD *)(this + 14) = 0;
  *(_DWORD *)(this + 18) = 0;
  *(_DWORD *)(this + 22) = 0;
  *(_DWORD *)(this + 26) = 0;
  *(_DWORD *)(this + 30) = 0;
  *(_DWORD *)(this + 34) = 0;
  *(_DWORD *)(this + 38) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004291F0
// Name: public: yaSSL::ServerKeyExchange::ServerKeyExchange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ServerKeyExchange::ServerKeyExchange(CUtlMemory<QueuedPacket_t *,int> *this)
{
  this->m_pMemory = (QueuedPacket_t **)&yaSSL::ServerKeyExchange::`vftable';
  this->m_nGrowSize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00429200
// Name: public: virtual enum yaSSL::HandShakeType yaSSL::ServerKeyExchange::get_type(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::ServerKeyExchange::get_type(CUtlMemory<QueuedPacket_t *,int> *this)
{
  return 12;
}

//------------------------------------------------------------------------------
// Address: 0x00429210
// Name: public: virtual void yaSSL::CertificateRequest::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00429250
// Name: public: virtual enum yaSSL::HandShakeType yaSSL::CertificateRequest::get_type(void)const
// Source: json
//------------------------------------------------------------------------------
int yaSSL::CertificateRequest::get_type()
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x00429260
// Name: public: yaSSL::CertificateVerify::CertificateVerify(void)
// Source: json
//------------------------------------------------------------------------------
yaSSL::CertificateVerify *__thiscall yaSSL::CertificateVerify::CertificateVerify(yaSSL::CertificateVerify *this)
{
  *this = (yaSSL::CertificateVerify)&yaSSL::CertificateVerify::`vftable';
  *((_DWORD *)this + 11) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429270
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,class yaSSL::CertificateVerify __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl yaSSL::operator>>(CUtlString *a1, CUtlString *a2)
{
  CUtlString *v2; // esi
  CUtlString *v3; // edi
  const CSplitScreenAddedConVar *v4; // ecx
  const char *v5; // eax
  int v7; // [esp+0h] [ebp-Ch]
  int v8; // [esp+8h] [ebp-4h] BYREF

  v2 = a1;
  yaSSL::input_buffer::read(this: a1, dst: (const char *)&a1);
  v8 = 0;
  yaSSL::ato16(c: (const IntVector4D *)&v8);
  v3 = a2;
  yaSSL::Crypto::setCipher(this: a2, i: (const char *)(unsigned __int16)v8, a3: v7);
  v5 = (const char *)operator new[](sz: v4);
  v3[2].m_Storage.m_nActualLength = (int)v5;
  yaSSL::input_buffer::read(this: v2, dst: v5);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x00429300
// Name: public: virtual void yaSSL::CertificateVerify::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertificateVerify::Process(
        yaSSL::CertificateVerify *this,
        struct yaSSL::input_buffer *a2,
        CThreadSyncObject *a3)
{
  CThreadSyncObject *Hashes; // eax
  int v5; // ebp
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v6; // eax
  yaSSL::CertManager *v7; // eax
  yaSSL::CertManager *v8; // esi
  unsigned __int8 *peerKey; // eax
  unsigned int v10; // eax
  char v11; // al
  const unsigned __int8 *v12; // eax
  const LoggingContext_t *v13; // eax
  unsigned int v14; // eax
  IConVar *peerKeyLength; // [esp-8h] [ebp-4Ch]
  IConVar *v16; // [esp-8h] [ebp-4Ch]
  int v17; // [esp+0h] [ebp-44h]
  __int16 v18; // [esp+0h] [ebp-44h]
  int v19; // [esp+0h] [ebp-44h]
  CUtlMemory<KeyValues *,int> *v20; // [esp+0h] [ebp-44h]
  unsigned int v21; // [esp+0h] [ebp-44h]
  CUtlMemory<KeyValues *,int> *v22; // [esp+0h] [ebp-44h]
  KeyValues *const *v23; // [esp+4h] [ebp-40h]
  __int16 v24; // [esp+4h] [ebp-40h]
  __int16 v25; // [esp+8h] [ebp-3Ch]
  __int16 v26; // [esp+Ch] [ebp-38h]
  CThread *dss; // [esp+10h] [ebp-34h] BYREF
  unsigned __int8 v28[40]; // [esp+18h] [ebp-2Ch] BYREF

  Hashes = yaSSL::SSL::getHashes(this: a3);
  v5 = yaSSL::sslHashes::use_certVerify(
         this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)Hashes,
         a2: v17,
         a3: v23);
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)a3, a2: v18, a3: v24, a4: v25, a5: v26);
  LOBYTE(v7) = yaSSL::Crypto::get_certManager(this: v6, a2: v19);
  v8 = v7;
  if ( yaSSL::CertManager::get_peerKeyType(a1: v7) == 1 )
  {
    peerKeyLength = (IConVar *)yaSSL::CertManager::get_peerKeyLength();
    peerKey = (unsigned __int8 *)yaSSL::CertManager::get_peerKey(this: v8);
    yaSSL::RSA::RSA(this: (CSplitScreenAddedConVar *)&dss, key: peerKey, sz: peerKeyLength, a4: true);
    yaSSL::SSL_CTX::getCert((CUtlMemory<KeyValues *,int> *)this, a2: v20);
    yaSSL::RSA::verify(
      this: (CThreadMutex *)&dss,
      message: (const LoggingContext_t *)v5,
      sz: 0x24u,
      sig: *((const LoggingContext_t **)this + 11),
      __formal: v10);
    if ( v11 == 0 )
      yaSSL::SSL::SetError(a1: a3, a2: 112);
    yaSSL::RSA::~RSA(this: (int *)&dss);
  }
  else
  {
    yaSSL::SSL_CTX::getCert((CUtlMemory<KeyValues *,int> *)this, a2: v20);
    TaoCrypt::DecodeDSA_Signature(this: (TaoCrypt *)v28, a2: *((unsigned __int8 **)this + 11), a3: v12, a4: v21);
    v16 = (IConVar *)yaSSL::CertManager::get_peerKeyLength();
    v13 = (const LoggingContext_t *)yaSSL::CertManager::get_peerKey(this: v8);
    yaSSL::DSS::DSS(this: (CSplitScreenAddedConVar *)&dss, result: v13, sz: v16, publicKey: true);
    yaSSL::SSL_CTX::getCert((CUtlMemory<KeyValues *,int> *)this, a2: v22);
    if ( yaSSL::DSS::verify(this: &dss, sha_digest: (CFunctor *)(v5 + 16), a3: 0x14u, a4: v28, a5: v14) == 0 )
      yaSSL::SSL::SetError(a1: a3, a2: 112);
    yaSSL::DSS::~DSS(this: (CThread *)&dss);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429420
// Name: public: virtual enum yaSSL::HandShakeType yaSSL::CertificateVerify::get_type(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int yaSSL::CertificateVerify::get_type()
{
  return 15;
}

//------------------------------------------------------------------------------
// Address: 0x00429430
// Name: public: yaSSL::ClientKeyExchange::ClientKeyExchange(void)
// Source: json
//------------------------------------------------------------------------------
__int16 *__thiscall yaSSL::ClientKeyExchange::ClientKeyExchange(yaSSL::ClientKeyExchange *this)
{
  *(_DWORD *)this = &yaSSL::ClientKeyExchange::`vftable';
  *(_DWORD *)&(*this)[4] = 0;
  return *this;
}

//------------------------------------------------------------------------------
// Address: 0x00429440
// Name: public: void yaSSL::ClientKeyExchange::build(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ClientKeyExchange::build(yaSSL::ClientKeyExchange *this, struct SSL *a2)
{
  const char *v3; // eax
  int v4; // [esp+0h] [ebp-4h]

  (*(void (__thiscall **)(_DWORD, struct SSL *))(**(_DWORD **)&(*this)[4] + 4))(a1: *(_DWORD *)&(*this)[4], a2);
  v3 = (const char *)(*(int (__thiscall **)(_DWORD))(**(_DWORD **)&(*this)[4] + 12))(a1: *(_DWORD *)&(*this)[4]);
  yaSSL::Crypto::setCipher((CUtlString *)this, i: v3, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x00429470
// Name: public: unsigned char const __near * yaSSL::ServerKeyExchange::getKey(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::ServerKeyExchange::getKey(yaSSL::ServerKeyExchange *this)
{
  return (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 2) + 16))(a1: *((_DWORD *)this + 2));
}

//------------------------------------------------------------------------------
// Address: 0x00429480
// Name: public: int yaSSL::ClientKeyExchange::getKeyLength(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ClientKeyExchange::getKeyLength(
        CUtlVectorAutoPurge<char *> *this,
        const CUtlVectorAutoPurge<char *> *a2)
{
  (*(void (__thiscall **)(int, const CUtlVectorAutoPurge<char *> *))(*(_DWORD *)this->m_Memory.m_nGrowSize + 12))(
    a1: this->m_Memory.m_nGrowSize,
    a2);
}

//------------------------------------------------------------------------------
// Address: 0x00429490
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,class yaSSL::Finished __near &)
// Source: json
//------------------------------------------------------------------------------
ICommandCompletionCallback *__cdecl yaSSL::operator>>(ICommandCompletionCallback *result)
{
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004294F0
// Name: public: virtual void yaSSL::Finished::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Finished::Process(yaSSL::Finished *this, CUtlString *a2, CThreadSyncObject *a3)
{
  CThreadSyncObject *Hashes; // eax
  int v5; // eax
  int v6; // esi
  const char *v7; // ebp
  int v8; // ecx
  unsigned int i; // eax
  yaSSL::SSL_CTX *v10; // eax
  const struct SSL_METHOD *Method; // eax
  unsigned int v12; // ebp
  CUtlMemory<KeyValues *,int> *v13; // eax
  int v14; // eax
  int v15; // eax
  int j; // esi
  char *v17; // eax
  char *v18; // ecx
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v19; // eax
  int v20; // [esp+0h] [ebp-40h]
  int v21; // [esp+0h] [ebp-40h]
  int v22; // [esp+0h] [ebp-40h]
  __int16 v23; // [esp+0h] [ebp-40h]
  const st_mysql_methods *v24; // [esp+0h] [ebp-40h]
  const st_mysql_methods *v25; // [esp+0h] [ebp-40h]
  CUtlMemory<KeyValues *,int> *v26; // [esp+0h] [ebp-40h]
  const st_mysql_methods *v27; // [esp+0h] [ebp-40h]
  int v28; // [esp+0h] [ebp-40h]
  CThreadSyncObject *v29; // [esp+4h] [ebp-3Ch]
  CThreadSyncObject *v30; // [esp+4h] [ebp-3Ch]
  __int16 v31; // [esp+4h] [ebp-3Ch]
  CThreadSyncObject *v32; // [esp+4h] [ebp-3Ch]
  bool v33; // [esp+8h] [ebp-38h]
  bool v34; // [esp+8h] [ebp-38h]
  __int16 v35; // [esp+8h] [ebp-38h]
  bool v36; // [esp+8h] [ebp-38h]
  __int16 v37; // [esp+8h] [ebp-38h]
  unsigned int v38; // [esp+Ch] [ebp-34h]
  unsigned int v39; // [esp+Ch] [ebp-34h]
  __int16 v40; // [esp+Ch] [ebp-34h]
  unsigned int v41; // [esp+Ch] [ebp-34h]
  __int16 v42; // [esp+Ch] [ebp-34h]
  int v43; // [esp+10h] [ebp-30h]
  int v44; // [esp+10h] [ebp-30h]
  char v45; // [esp+14h] [ebp-2Ch] BYREF
  char dst[20]; // [esp+28h] [ebp-18h] BYREF

  Hashes = yaSSL::SSL::getHashes(this: a3);
  LOBYTE(v5) = yaSSL::Crypto::get_certManager(
                 this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)Hashes,
                 a2: v20);
  v43 = v5;
  v6 = (unsigned __int8)yaSSL::SSL::isTLS(a1: v21, a2: v29, a3: v33, a4: v38) != 0 ? 12 : 36;
  v7 = (char *)this + 8;
  yaSSL::input_buffer::read(this: a2, dst: v7);
  v8 = v43 + 8;
  for ( i = v6; i >= 4; i -= 4 )
  {
    if ( *(_DWORD *)v7 != *(_DWORD *)v8 )
      goto LABEL_10;
    v8 += 4;
    v7 += 4;
  }
  if ( i != 0 && (*(_BYTE *)v8 != *v7 || i > 1 && (*(_BYTE *)(v8 + 1) != v7[1] || i > 2 && *(_BYTE *)(v8 + 2) != v7[2])) )
    goto LABEL_10;
  if ( (unsigned __int8)yaSSL::SSL::isTLS(a1: v22, a2: v30, a3: v34, a4: v39) != 0 )
  {
    yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)a2);
    yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)a2, a2: (CUtlMemory<KeyValues *,int> *)(v6 + 4));
    yaSSL::TLS_hmac();
  }
  else
  {
    yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)a2);
    yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)a2, a2: (CUtlMemory<KeyValues *,int> *)(v6 + 4));
    yaSSL::hmac();
  }
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)a3, a2: v23, a3: v31, a4: v35, a5: v40);
  Method = yaSSL::SSL_CTX::getMethod(this: v10);
  v12 = (*(int (__thiscall **)(const struct SSL_METHOD *))(*(_DWORD *)Method + 12))(a1: Method);
  yaSSL::input_buffer::read(this: a2, dst);
  v44 = 0;
  yaSSL::SSL::useSecurity(this: (char *)a3);
  if ( yaSSL::Security::use_parms(result: v24)->read_rows == (st_mysql_data *(__cdecl *)(st_mysql *, st_mysql_field *, unsigned int))1
    && (unsigned __int8)yaSSL::SSL::isTLSv1_1(a1: (int)v25, a2: v32, a3: v36, a4: v41) != 0 )
  {
    yaSSL::sslHashes::get_MD5(this: (ShortVector *)a3, a2: (__int16)v25, a3: (__int16)v32, a4: v37, a5: v42);
    yaSSL::SSL_CTX::getCert(this: v13, a2: v26);
    v44 = (*(int (__thiscall **)(int))(*(_DWORD *)v14 + 16))(a1: v14);
  }
  yaSSL::SSL::useSecurity(this: (char *)a3);
  v15 = HIWORD(yaSSL::Security::use_parms(result: v25)->unbuffered_fetch) - v44 - v12 - v6 - 4;
  if ( v15 > 0 )
  {
    for ( j = v15; j != 0; --j )
      yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF);
  }
  v17 = &v45;
  v18 = dst;
  if ( v12 >= 4 )
  {
    while ( *(_DWORD *)v18 == *(_DWORD *)v17 )
    {
      v12 -= 4;
      v17 += 4;
      v18 += 4;
      if ( v12 < 4 )
        goto LABEL_23;
    }
    goto LABEL_10;
  }
LABEL_23:
  if ( v12 != 0 && (*v17 != *v18 || v12 > 1 && (v17[1] != v18[1] || v12 > 2 && v17[2] != v18[2])) )
  {
LABEL_10:
    yaSSL::SSL::SetError(a1: a3, a2: 112);
    return;
  }
  yaSSL::SSL::useStates(this: (char *)a3);
  *(_DWORD *)TaoCrypt::AbstractRing::MultiplicativeGroup() = 3;
  yaSSL::SSL::useSecurity(this: (char *)a3);
  if ( yaSSL::Security::use_parms(result: v27)->read_query_result == (char (__cdecl *)(st_mysql *))1 )
  {
    v19 = (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)yaSSL::SSL::useStates(this: (char *)a3);
    *(_DWORD *)yaSSL::States::useClient(this: v19, a2: v28, a3: (KeyValues *const *)v32) = 5;
  }
  else
  {
    yaSSL::SSL::useStates(this: (char *)a3);
    **(_DWORD **)&yaSSL::States::useServer().x = 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429780
// Name: public: yaSSL::Finished::Finished(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00429790
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::Finished::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
ICommandCompletionCallback *__thiscall yaSSL::Finished::set(Vector2D *this, ICommandCompletionCallback *in)
{
  return yaSSL::operator>>(result: in);
}

//------------------------------------------------------------------------------
// Address: 0x004297B0
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::Finished::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *__thiscall yaSSL::Finished::get(
        Vector2D *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *out)
{
  return yaSSL::operator<<(result: out);
}

//------------------------------------------------------------------------------
// Address: 0x004297D0
// Name: void yaSSL::clean(unsigned char volatile __near *,unsigned int,class yaSSL::RandomPool __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::clean(HICON__ p, volatile unsigned __int8 *sz, yaSSL::RandomPool *ran)
{
  unsigned int v3; // eax
  unsigned int v4; // eax

  v3 = 0;
  if ( sz != nullptr )
  {
    do
    {
      *(_BYTE *)(v3 + p.unused) = 0;
      ++v3;
    }
    while ( v3 < (unsigned int)sz );
  }
  yaSSL::RandomPool::Fill(this: ran, dst: (unsigned __int8 *)p.unused, (unsigned int)sz);
  v4 = 0;
  if ( sz != nullptr )
  {
    do
    {
      *(_BYTE *)(v4 + p.unused) = 0;
      ++v4;
    }
    while ( v4 < (unsigned int)sz );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429810
// Name: public: yaSSL::Connection::Connection(struct yaSSL::ProtocolVersion,class yaSSL::RandomPool __near &)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall yaSSL::Connection::Connection(void *this, __int16 v, int ran)
{
  bool v4; // cl
  bool v5; // cl

  *(_DWORD *)this = 0;
  *((_DWORD *)this + 71) = 0;
  *((_DWORD *)this + 72) = 0;
  *((_DWORD *)this + 73) = 0;
  *((_BYTE *)this + 296) = 0;
  *((_BYTE *)this + 297) = 0;
  v4 = (unsigned __int8)v >= 3u && HIBYTE(v) != 0;
  *((_BYTE *)this + 298) = v4;
  v5 = (unsigned __int8)v >= 3u && HIBYTE(v) >= 2u;
  *((_BYTE *)this + 299) = v5;
  *((_BYTE *)this + 301) = 0;
  *((_WORD *)this + 151) = v;
  yaSSL::ProtocolVersion::ProtocolVersion(this: (yaSSL::ProtocolVersion *)this + 76, maj: 3u, min: 0);
  *((_DWORD *)this + 77) = ran;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 36) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004298D0
// Name: public: void yaSSL::Connection::AllocPreSecret(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::Connection::AllocPreSecret(CSplitScreenAddedConVar **this, unsigned int sz)
{
  CSplitScreenAddedConVar *result; // eax

  *(this + 73) = (CSplitScreenAddedConVar *)sz;
  result = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
  *this = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429900
// Name: public: void yaSSL::Connection::TurnOffTLS(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Connection::TurnOffTLS(yaSSL::Connection *this)
{
  *((_BYTE *)this + 298) = 0;
  *((_BYTE *)this + 303) = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00429910
// Name: public: void yaSSL::Connection::TurnOffTLS1_1(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Connection::TurnOffTLS1_1(yaSSL::Connection *this)
{
  *((_BYTE *)this + 299) = 0;
  *((_BYTE *)this + 303) = 1;
}

//------------------------------------------------------------------------------
// Address: 0x00429920
// Name: public: void yaSSL::Connection::CleanMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Connection::CleanMaster(yaSSL::Connection *this)
{
  if ( *((_BYTE *)this + 297) == 0 )
  {
    yaSSL::clean(p: (HICON__)(this + 4), sz: (volatile unsigned __int8 *)0x30, ran: *((yaSSL::RandomPool **)this + 77));
    *((_BYTE *)this + 297) = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429950
// Name: struct yaSSL::Message __near * yaSSL::CreateCipherSpec(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateCipherSpec(const CSplitScreenAddedConVar *ecx0)
{
  CUtlVector<char *,CUtlMemory<char *,int> > *v1; // eax

  v1 = (CUtlVector<char *,CUtlMemory<char *,int> > *)operator new(sz: ecx0);
  if ( v1 != nullptr )
    yaSSL::ChangeCipherSpec::ChangeCipherSpec(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429970
// Name: struct yaSSL::Message __near * yaSSL::CreateHandShake(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::CreateHandShake(const CSplitScreenAddedConVar *ecx0)
{
  CSplitScreenAddedConVar *result; // eax

  result = operator new(sz: ecx0);
  if ( result == nullptr )
    return nullptr;
  result->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::HandShakeHeader::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429990
// Name: struct yaSSL::Message __near * yaSSL::CreateData(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlCharConversion *__thiscall yaSSL::CreateData(const CSplitScreenAddedConVar *ecx0)
{
  CSplitScreenAddedConVar *v1; // eax

  v1 = operator new(sz: ecx0);
  if ( v1 != nullptr )
    return yaSSL::Data::Data(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004299B0
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateClientHello(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateClientHello(const CSplitScreenAddedConVar *this)
{
  yaSSL::ClientHello *v1; // eax

  v1 = (yaSSL::ClientHello *)operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::ClientHello::ClientHello(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x004299E0
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateServerHello(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateServerHello(const CSplitScreenAddedConVar *this)
{
  yaSSL::ServerHello *v1; // eax

  v1 = (yaSSL::ServerHello *)operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::ServerHello::ServerHello(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429A00
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateCertificate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateCertificate(const CSplitScreenAddedConVar *this)
{
  CSplitScreenAddedConVar *v1; // eax

  v1 = operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::Certificate::Certificate(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429A20
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateServerKeyExchange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateServerKeyExchange(const CSplitScreenAddedConVar *this)
{
  CUtlMemory<QueuedPacket_t *,int> *v1; // eax

  v1 = (CUtlMemory<QueuedPacket_t *,int> *)operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::ServerKeyExchange::ServerKeyExchange(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429A40
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateServerHelloDone(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateServerHelloDone(const CSplitScreenAddedConVar *this)
{
  yaSSL::ServerHelloDone *v1; // eax

  v1 = (yaSSL::ServerHelloDone *)operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::ServerHelloDone::ServerHelloDone(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429A60
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateCertificateVerify(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateCertificateVerify(const CSplitScreenAddedConVar *this)
{
  yaSSL::CertificateVerify *v1; // eax

  v1 = (yaSSL::CertificateVerify *)operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::CertificateVerify::CertificateVerify(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429A80
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateClientKeyExchange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateClientKeyExchange(const CSplitScreenAddedConVar *this)
{
  __int16 *v1; // eax

  v1 = (__int16 *)operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::ClientKeyExchange::ClientKeyExchange(this: (yaSSL::ClientKeyExchange *)v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429AA0
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateFinished(const CSplitScreenAddedConVar *this)
{
  yaSSL::Finished *v1; // eax

  v1 = (yaSSL::Finished *)operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::Finished::Finished(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429AC0
// Name: struct yaSSL::ClientKeyBase __near * yaSSL::CreateDHClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateDHClient(const CSplitScreenAddedConVar *ecx0)
{
  Quaternion *v1; // eax

  v1 = (Quaternion *)operator new(sz: ecx0);
  if ( v1 != nullptr )
    yaSSL::ClientDiffieHellmanPublic::ClientDiffieHellmanPublic(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x00429BC0
// Name: public: virtual void yaSSL::EncryptedPreMasterSecret::build(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::EncryptedPreMasterSecret::build(
        CUtlMemory<QueuedPacket_t *,int> *this,
        CUtlMemory<QueuedPacket_t *,int> *ssl)
{
  ShortVector v3; // rax
  ShortVector *v4; // eax
  int v5; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v6; // eax
  yaSSL::CertManager *v7; // eax
  yaSSL::CertManager *v8; // ebx
  unsigned __int8 *peerKey; // eax
  const CThreadMutex *cipherLength; // eax
  const CThreadMutex *m_nAllocationCount; // ebp
  float v12; // ecx
  ShortVector v13; // rax
  unsigned __int8 *v14; // [esp-8h] [ebp-58h]
  IConVar *peerKeyLength; // [esp-8h] [ebp-58h]
  unsigned int v16; // [esp-4h] [ebp-54h]
  __int16 v17; // [esp+0h] [ebp-50h]
  __int16 v18; // [esp+0h] [ebp-50h]
  __int16 v19; // [esp+0h] [ebp-50h]
  int v20; // [esp+0h] [ebp-50h]
  int v21; // [esp+0h] [ebp-50h]
  __int16 v22; // [esp+0h] [ebp-50h]
  __int16 v23; // [esp+4h] [ebp-4Ch]
  __int16 v24; // [esp+4h] [ebp-4Ch]
  __int16 v25; // [esp+4h] [ebp-4Ch]
  CThreadSyncObject *v26; // [esp+4h] [ebp-4Ch]
  __int16 v27; // [esp+4h] [ebp-4Ch]
  __int16 v28; // [esp+8h] [ebp-48h]
  __int16 v29; // [esp+8h] [ebp-48h]
  bool v30; // [esp+8h] [ebp-48h]
  __int16 v31; // [esp+8h] [ebp-48h]
  __int16 v32; // [esp+Ch] [ebp-44h]
  __int16 v33; // [esp+Ch] [ebp-44h]
  unsigned int v34; // [esp+Ch] [ebp-44h]
  __int16 v35; // [esp+Ch] [ebp-44h]
  __int16 pv; // [esp+10h] [ebp-40h]
  CDatamapFieldSizeDeducer<21>::<unnamed_tag> rsa; // [esp+14h] [ebp-3Ch] BYREF
  unsigned __int8 dst[48]; // [esp+1Ch] [ebp-34h] BYREF

  memset(dst, value: 0, count: sizeof(dst));
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)ssl, a2: (__int16)dst, a3: 48, a4: v17, a5: v23);
  v3 = yaSSL::States::useServer();
  yaSSL::RandomPool::Fill(this: *(yaSSL::RandomPool **)&v3.x, dst: v14, sz: v16);
  v4 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)ssl);
  yaSSL::sslHashes::get_MD5(this: v4, a2: v18, a3: v24, a4: v28, a5: v32);
  pv = *(_WORD *)(v5 + 304);
  *(_WORD *)dst = pv;
  yaSSL::SSL::set_preMaster(this: (yaSSL::SSL *)ssl, a2: dst, a3: 0x30u);
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)ssl, a2: v19, a3: v25, a4: v29, a5: v33);
  LOBYTE(v7) = yaSSL::Crypto::get_certManager(this: v6, a2: v20);
  v8 = v7;
  peerKeyLength = (IConVar *)yaSSL::CertManager::get_peerKeyLength();
  peerKey = (unsigned __int8 *)yaSSL::CertManager::get_peerKey(this: v8);
  yaSSL::RSA::RSA(this: (CSplitScreenAddedConVar *)&rsa, key: peerKey, sz: peerKeyLength, a4: true);
  LOBYTE(v8) = yaSSL::SSL::isTLS(a1: v21, a2: v26, a3: v30, a4: v34);
  cipherLength = yaSSL::RSA::get_cipherLength();
  yaSSL::EncryptedPreMasterSecret::alloc(
    this,
    sz: (int)&cipherLength->m_CriticalSection[(unsigned __int8)v8 != 0 ? 2 : 0]);
  m_nAllocationCount = (const CThreadMutex *)this->m_nAllocationCount;
  if ( (_BYTE)v8 != 0 )
  {
    yaSSL::RSA::get_cipherLength();
    yaSSL::c16toa(u16: v12);
    *(_WORD *)this->m_nAllocationCount = pv;
    m_nAllocationCount = (const CThreadMutex *)((char *)m_nAllocationCount + 2);
  }
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)ssl, a2: v22, a3: v27, a4: v31, a5: v35);
  v13 = yaSSL::States::useServer();
  yaSSL::RSA::encrypt(
    this: (CThreadMutex *)&rsa,
    cipher: m_nAllocationCount,
    plain: dst,
    sz: 0x30u,
    random: *(struct TaoCrypt::RandomNumberGenerator ***)&v13.x);
  yaSSL::RSA::~RSA(this: (int *)&rsa);
}

//------------------------------------------------------------------------------
// Address: 0x00429D00
// Name: public: virtual void yaSSL::ClientDiffieHellmanPublic::build(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::ClientDiffieHellmanPublic::build(Quaternion *this@<ecx>, QAngleByValue a2)
{
  float x; // ebp
  CUtlMemory<KeyValues *,int> *v4; // eax
  CFunctorData **length; // ebx
  QAngleByValue *agreedKeyLength; // esi
  const QAngleByValue *publicKey; // eax
  float v8; // ecx
  unsigned __int8 *v9; // eax
  const unsigned __int8 *agreedKey; // eax
  unsigned int v11; // [esp-4h] [ebp-14h]
  __int16 v12; // [esp+0h] [ebp-10h]
  __int16 v13; // [esp+4h] [ebp-Ch]
  __int16 v14; // [esp+8h] [ebp-8h]
  __int16 v15; // [esp+Ch] [ebp-4h]

  x = a2.x;
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)LODWORD(a2.x), a2: v12, a3: v13, a4: v14, a5: v15);
  length = (CFunctorData **)yaSSL::EncryptedPreMasterSecret::get_length(this: v4);
  yaSSL::DiffieHellman::DiffieHellman(
    this: (CUtlMemory<UtlRBTreeNode_t<CUtlMap<sockaddr_in,xlspTitleServer_t,int>::Node_t,int>,int>::Iterator_t *)&a2,
    that: length);
  agreedKeyLength = yaSSL::DiffieHellman::get_agreedKeyLength();
  yaSSL::ClientDiffieHellmanPublic::alloc(this, sz: (const CSplitScreenAddedConVar *)agreedKeyLength, offset: true);
  publicKey = (const QAngleByValue *)yaSSL::DiffieHellman::get_publicKey(this: (yaSSL::DiffieHellman *)length);
  yaSSL::DiffieHellman::makeAgreement(this: &a2, other: publicKey, otherSz: (unsigned int)agreedKeyLength);
  yaSSL::c16toa(u16: v8);
  v9 = (unsigned __int8 *)yaSSL::DiffieHellman::get_publicKey(this: (yaSSL::DiffieHellman *)&a2);
  memcpy(dst: (unsigned __int8 *)(LODWORD(this->w) + 2), src: v9, count: (unsigned int)agreedKeyLength);
  if ( *yaSSL::DiffieHellman::get_agreedKey(this: (yaSSL::DiffieHellman *)&a2) != 0 )
  {
    v11 = (unsigned int)agreedKeyLength;
    agreedKey = yaSSL::DiffieHellman::get_agreedKey(this: (yaSSL::DiffieHellman *)&a2);
  }
  else
  {
    v11 = (unsigned int)&agreedKeyLength[-1].z + 3;
    agreedKey = yaSSL::DiffieHellman::get_agreedKey(this: (yaSSL::DiffieHellman *)&a2) + 1;
  }
  yaSSL::SSL::set_preMaster(this: (yaSSL::SSL *)LODWORD(x), a2: agreedKey, a3: v11);
  yaSSL::DiffieHellman::~DiffieHellman(this: (CDatamapFieldSizeDeducer<17>::<unnamed_tag> *)&a2);
}

//------------------------------------------------------------------------------
// Address: 0x00429DB0
// Name: public: virtual void yaSSL::EncryptedPreMasterSecret::read(class yaSSL::SSL __near &,class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::EncryptedPreMasterSecret::read(
        CUtlMemory<QueuedPacket_t *,int> *this,
        ShortVector *ssl,
        CUtlString *a3)
{
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v4; // eax
  yaSSL::CertManager *v5; // eax
  yaSSL::CertManager *v6; // ebx
  unsigned __int8 *privateKey; // eax
  const IntVector4D *v8; // ecx
  ShortVector v9; // rax
  ShortVector *v10; // eax
  int v11; // eax
  IConVar *privateKeyLength; // [esp-8h] [ebp-5Ch]
  __int16 v13; // [esp+0h] [ebp-54h]
  int v14; // [esp+0h] [ebp-54h]
  int v15; // [esp+0h] [ebp-54h]
  __int16 v16; // [esp+0h] [ebp-54h]
  __int16 v17; // [esp+0h] [ebp-54h]
  st_mysql *v18; // [esp+0h] [ebp-54h]
  __int16 v19; // [esp+4h] [ebp-50h]
  CThreadSyncObject *v20; // [esp+4h] [ebp-50h]
  __int16 v21; // [esp+4h] [ebp-50h]
  __int16 v22; // [esp+4h] [ebp-50h]
  __int16 v23; // [esp+8h] [ebp-4Ch]
  bool v24; // [esp+8h] [ebp-4Ch]
  __int16 v25; // [esp+8h] [ebp-4Ch]
  __int16 v26; // [esp+8h] [ebp-4Ch]
  __int16 v27; // [esp+Ch] [ebp-48h]
  unsigned int v28; // [esp+Ch] [ebp-48h]
  __int16 v29; // [esp+Ch] [ebp-48h]
  __int16 v30; // [esp+Ch] [ebp-48h]
  CKeyValuesDumpContextAsDevMsg *pv; // [esp+10h] [ebp-44h] BYREF
  int cipherLen; // [esp+14h] [ebp-40h]
  CDatamapFieldSizeDeducer<21>::<unnamed_tag> rsa; // [esp+18h] [ebp-3Ch] BYREF
  CThreadMutex plain; // [esp+20h] [ebp-34h] BYREF

  yaSSL::sslHashes::get_MD5(this: ssl, a2: v13, a3: v19, a4: v23, a5: v27);
  LOBYTE(v5) = yaSSL::Crypto::get_certManager(this: v4, a2: v14);
  v6 = v5;
  privateKeyLength = (IConVar *)yaSSL::CertManager::get_privateKeyLength();
  privateKey = (unsigned __int8 *)yaSSL::CertManager::get_privateKey(this: v6);
  yaSSL::RSA::RSA(this: (CSplitScreenAddedConVar *)&rsa, key: privateKey, sz: privateKeyLength, a4: false);
  cipherLen = (unsigned __int16)yaSSL::RSA::get_cipherLength();
  if ( (unsigned __int8)yaSSL::SSL::isTLS(a1: v15, a2: v20, a3: v24, a4: v28) != 0 )
  {
    yaSSL::input_buffer::read(this: a3, dst: (const char *)&pv);
    yaSSL::ato16(c: v8);
  }
  yaSSL::EncryptedPreMasterSecret::alloc(this, sz: (unsigned __int16)cipherLen);
  yaSSL::input_buffer::read(this: a3, dst: (const char *)this->m_nAllocationCount);
  yaSSL::sslHashes::get_MD5(this: ssl, a2: v16, a3: v21, a4: v25, a5: v29);
  v9 = yaSSL::States::useServer();
  yaSSL::RSA::decrypt(
    this: (CThreadMutex *)&rsa,
    a2: (const CInternalFileSystemPassThru<IFileSystem> *)ssl,
    &plain,
    cipher: this->m_nAllocationCount,
    sz: this->m_nGrowSize,
    random: *(int **)&v9.x);
  v10 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)ssl);
  yaSSL::sslHashes::get_MD5(this: v10, a2: v17, a3: v22, a4: v26, a5: v30);
  LOWORD(pv) = *(_WORD *)(v11 + 304);
  if ( (_WORD)pv != *(_WORD *)plain.m_CriticalSection )
    yaSSL::SSL::SetError(a1: ssl, a2: 120);
  yaSSL::SSL::set_preMaster(this: (yaSSL::SSL *)ssl, a2: plain.m_CriticalSection, a3: 0x30u);
  yaSSL::SSL::makeMasterSecret(result: v18);
  yaSSL::RSA::~RSA(this: (int *)&rsa);
}

//------------------------------------------------------------------------------
// Address: 0x00429EE0
// Name: public: yaSSL::EncryptedPreMasterSecret::EncryptedPreMasterSecret(void)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<QueuedPacket_t *,int> *__thiscall yaSSL::EncryptedPreMasterSecret::EncryptedPreMasterSecret(
        CUtlMemory<QueuedPacket_t *,int> *this)
{
  this->m_pMemory = (QueuedPacket_t **)&yaSSL::EncryptedPreMasterSecret::`vftable';
  this->m_nAllocationCount = 0;
  this->m_nGrowSize = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00429F00
// Name: public: virtual yaSSL::EncryptedPreMasterSecret::~EncryptedPreMasterSecret(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::EncryptedPreMasterSecret::~EncryptedPreMasterSecret(yaSSL::EncryptedPreMasterSecret *this)
{
  void *v2; // [esp-4h] [ebp-8h]
  void **v3; // [esp+0h] [ebp-4h]

  v2 = *(void **)&this->m_CriticalSection[4];
  *(_DWORD *)this->m_CriticalSection = &yaSSL::EncryptedPreMasterSecret::`vftable';
  yaSSL::ysArrayDelete<unsigned char>(ptr: v2, a2: v3);
  *(_DWORD *)this->m_CriticalSection = &yaSSL::ClientKeyBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x00429F20
// Name: public: virtual void yaSSL::ClientDiffieHellmanPublic::read(class yaSSL::SSL __near &,class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
st_mysql *__thiscall yaSSL::ClientDiffieHellmanPublic::read(Quaternion *this, ShortVector *ssl, CUtlString *a3)
{
  yaSSL::SSL *v3; // ebp
  CUtlMemory<KeyValues *,int> *v5; // eax
  int length; // eax
  CUtlString *v7; // ebx
  QAngleByValue *v8; // esi
  const IntVector4D *v9; // ecx
  const unsigned __int8 *agreedKey; // eax
  QAngleByValue *agreedKeyLength; // [esp-4h] [ebp-18h]
  __int16 v13; // [esp+0h] [ebp-14h]
  st_mysql *v14; // [esp+0h] [ebp-14h]
  __int16 v15; // [esp+4h] [ebp-10h]
  __int16 v16; // [esp+8h] [ebp-Ch]
  __int16 v17; // [esp+Ch] [ebp-8h]
  char m_pMemory; // [esp+10h] [ebp-4h]
  char v19; // [esp+11h] [ebp-3h]

  v3 = (yaSSL::SSL *)ssl;
  yaSSL::sslHashes::get_MD5(this: ssl, a2: v13, a3: v15, a4: v16, a5: v17);
  length = yaSSL::EncryptedPreMasterSecret::get_length(this: v5);
  v7 = a3;
  v8 = (QAngleByValue *)length;
  m_pMemory = (char)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  v19 = (char)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  LOBYTE(v9) = v19;
  yaSSL::ato16(c: v9);
  yaSSL::ClientDiffieHellmanPublic::alloc(
    this,
    sz: (const CSplitScreenAddedConVar *)(unsigned __int16)ssl,
    offset: false);
  yaSSL::input_buffer::read(this: v7, dst: (const char *)LODWORD(this->w));
  yaSSL::DiffieHellman::makeAgreement(
    this: v8,
    other: (const QAngleByValue *)LODWORD(this->w),
    otherSz: (unsigned __int16)ssl);
  if ( *yaSSL::DiffieHellman::get_agreedKey(this: (yaSSL::DiffieHellman *)v8) != 0 )
  {
    agreedKeyLength = yaSSL::DiffieHellman::get_agreedKeyLength();
    agreedKey = yaSSL::DiffieHellman::get_agreedKey(this: (yaSSL::DiffieHellman *)v8);
  }
  else
  {
    agreedKeyLength = (QAngleByValue *)((char *)yaSSL::DiffieHellman::get_agreedKeyLength() - 1);
    agreedKey = yaSSL::DiffieHellman::get_agreedKey(this: (yaSSL::DiffieHellman *)v8) + 1;
  }
  yaSSL::SSL::set_preMaster(this: v3, a2: agreedKey, a3: (unsigned int)agreedKeyLength);
  return yaSSL::SSL::makeMasterSecret(result: v14);
}

//------------------------------------------------------------------------------
// Address: 0x00429FF0
// Name: public: virtual yaSSL::ClientDiffieHellmanPublic::~ClientDiffieHellmanPublic(void)
// Source: json
//------------------------------------------------------------------------------
HRESULT __thiscall yaSSL::ClientDiffieHellmanPublic::~ClientDiffieHellmanPublic(Quaternion *this)
{
  HRESULT result; // eax
  float w; // [esp-4h] [ebp-8h]
  void **v4; // [esp+0h] [ebp-4h]

  w = this->w;
  LODWORD(this->x) = &yaSSL::ClientDiffieHellmanPublic::`vftable';
  result = yaSSL::ysArrayDelete<unsigned char>(ptr: (void *)LODWORD(w), a2: v4);
  LODWORD(this->x) = &yaSSL::ClientKeyBase::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042A010
// Name: public: virtual void yaSSL::DH_Server::read(class yaSSL::SSL __near &,class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DH_Server::read(yaSSL::DH_Server *this, struct SSL *a2, CUtlString *a3)
{
  CUtlMemory<KeyValues *,int> *v4; // ebx
  __int16 v5; // di
  CSplitScreenAddedConVar *v6; // eax
  const IntVector4D *m_pMemory_low; // ecx
  __int16 v8; // di
  CSplitScreenAddedConVar *v9; // eax
  unsigned __int16 v10; // di
  CSplitScreenAddedConVar *v11; // eax
  int v12; // eax
  const char *length; // eax
  const char *v14; // eax
  ShortVector *v15; // esi
  ShortVector *v16; // eax
  int v17; // eax
  int v18; // edi
  int v19; // eax
  int v20; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v21; // eax
  yaSSL::CertManager *v22; // eax
  yaSSL::CertManager *v23; // edi
  unsigned __int8 *peerKey; // eax
  char v25; // al
  const CSplitScreenAddedConVar *v26; // ecx
  const LoggingContext_t *v27; // eax
  CSplitScreenAddedConVar *v28; // edi
  ConCommandBase *v29; // ecx
  CUtlMemory<KeyValues *,int> *Flags; // eax
  CUtlMemory<KeyValues *,int> *v31; // ecx
  unsigned __int16 v32; // ax
  ConCommandBase *v33; // ecx
  yaSSL::SSL_CTX *v34; // ecx
  ConCommandBase *v35; // ecx
  const unsigned __int8 *p; // eax
  __int16 v37; // ax
  yaSSL::Crypto *v38; // eax
  unsigned __int16 v39; // [esp-28h] [ebp-C0h]
  const unsigned __int8 *g; // [esp-24h] [ebp-BCh]
  unsigned __int16 v41; // [esp-20h] [ebp-B8h]
  unsigned __int8 *v42; // [esp-1Ch] [ebp-B4h]
  IConVar *peerKeyLength; // [esp-18h] [ebp-B0h]
  IConVar *v44; // [esp-18h] [ebp-B0h]
  unsigned int v45; // [esp-18h] [ebp-B0h]
  const struct yaSSL::RandomPool *v46; // [esp-14h] [ebp-ACh]
  struct yaSSL::DiffieHellman *v47; // [esp-14h] [ebp-ACh]
  const struct SSL_METHOD *v48; // [esp-10h] [ebp-A8h]
  __int16 v49; // [esp-10h] [ebp-A8h]
  int v50; // [esp-10h] [ebp-A8h]
  const st_mysql_methods *v51; // [esp-10h] [ebp-A8h]
  unsigned int v52; // [esp-10h] [ebp-A8h]
  const char *v53; // [esp-10h] [ebp-A8h]
  __int16 v54; // [esp-Ch] [ebp-A4h]
  __int16 v55; // [esp-Ch] [ebp-A4h]
  __int16 v56; // [esp-8h] [ebp-A0h]
  __int16 v57; // [esp-8h] [ebp-A0h]
  const struct SSL_METHOD *Method; // [esp-4h] [ebp-9Ch]
  __int16 v59; // [esp-4h] [ebp-9Ch]
  __int16 v60; // [esp-4h] [ebp-9Ch]
  unsigned __int16 v61; // [esp+0h] [ebp-98h]
  unsigned __int16 v62; // [esp+0h] [ebp-98h]
  CThread v63; // [esp+4h] [ebp-94h] BYREF

  *(_DWORD *)&v63.m_Lock.m_lockCount = this;
  *(_DWORD *)&v63.m_Lock.m_CriticalSection[20] = a2;
  v63.m_Lock.m_CriticalSection[12] = (unsigned __int8)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  v63.m_Lock.m_CriticalSection[13] = (unsigned __int8)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  yaSSL::ato16(c: (const IntVector4D *)&v63.m_Lock.m_CriticalSection[12]);
  v4 = (CUtlMemory<KeyValues *,int> *)((char *)this + 4);
  v5 = *(_WORD *)&v63.m_Lock.m_CriticalSection[16] + 6;
  v6 = yaSSL::ServerDHParams::alloc_p(
         this: v4,
         result: (matrix3x4_t *)*(unsigned __int16 *)&v63.m_Lock.m_CriticalSection[16]);
  yaSSL::input_buffer::read(this: a3, dst: (const char *)v6);
  v63.m_Lock.m_CriticalSection[12] = (unsigned __int8)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  m_pMemory_low = (const IntVector4D *)LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
  v63.m_Lock.m_CriticalSection[13] = (unsigned __int8)m_pMemory_low;
  yaSSL::ato16(c: m_pMemory_low);
  v8 = *(_WORD *)&v63.m_Lock.m_CriticalSection[16] + v5;
  v9 = yaSSL::ServerDHParams::alloc_g(
         this: v4,
         result: (matrix3x4_t *)*(unsigned __int16 *)&v63.m_Lock.m_CriticalSection[16]);
  yaSSL::input_buffer::read(this: a3, dst: (const char *)v9);
  v63.m_Lock.m_CriticalSection[12] = (unsigned __int8)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  v63.m_Lock.m_CriticalSection[13] = (unsigned __int8)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  yaSSL::ato16(c: (const IntVector4D *)&v63.m_Lock.m_CriticalSection[12]);
  v10 = *(_WORD *)&v63.m_Lock.m_CriticalSection[16] + v8;
  v11 = yaSSL::ServerDHParams::alloc_pub(
          this: v4,
          result: (matrix3x4_t *)*(unsigned __int16 *)&v63.m_Lock.m_CriticalSection[16]);
  yaSSL::input_buffer::read(this: a3, dst: (const char *)v11);
  yaSSL::input_buffer::input_buffer(result: (const CUtlString *)v10);
  yaSSL::SSL_CTX::getCert(
    this: (CUtlMemory<KeyValues *,int> *)a3,
    a2: *(CUtlMemory<KeyValues *,int> **)v63.m_Lock.m_CriticalSection);
  yaSSL::Crypto::setCipher(this: a3, i: (const char *)(v12 - v10), a3: *(int *)v63.m_Lock.m_CriticalSection);
  length = (const char *)yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v63.m_result);
  yaSSL::input_buffer::read(this: a3, dst: length);
  yaSSL::input_buffer::add_size(
    this: (CUtlString *)&v63.m_result,
    i: (const char *)v10,
    a3: *(int *)v63.m_Lock.m_CriticalSection);
  v63.m_Lock.m_CriticalSection[12] = (unsigned __int8)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  v63.m_Lock.m_CriticalSection[13] = (unsigned __int8)yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory;
  yaSSL::ato16(c: (const IntVector4D *)&v63.m_Lock.m_CriticalSection[16]);
  v14 = (const char *)operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int16 *)&v63.m_Lock.m_CriticalSection[16]);
  *(_DWORD *)(*(_DWORD *)&v63.m_Lock.m_lockCount + 28) = v14;
  yaSSL::input_buffer::read(this: a3, dst: v14);
  yaSSL::MD5::MD5(this: (KeyValues **)&v63.m_hThread);
  yaSSL::SHA::SHA(this: (Vector2D *)&v63.m_ExitEvent);
  v15 = *(ShortVector **)&v63.m_Lock.m_CriticalSection[20];
  v16 = (ShortVector *)yaSSL::SSL::useSecurity(this: *(char **)&v63.m_Lock.m_CriticalSection[20]);
  yaSSL::sslHashes::get_MD5(
    this: v16,
    a2: *(__int16 *)v63.m_Lock.m_CriticalSection,
    a3: *(__int16 *)&v63.m_Lock.m_CriticalSection[4],
    a4: *(__int16 *)&v63.m_Lock.m_CriticalSection[8],
    a5: *(__int16 *)&v63.m_Lock.m_CriticalSection[12]);
  v18 = v17;
  *(_DWORD *)&v63.m_Lock.m_CriticalSection[20] = v17 + 52;
  TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
    this: (CLoggingSystem *)&v63.m_hThread,
    cipher: v17 + 52,
    plain: (Color)32);
  v18 += 84;
  TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
    this: (CLoggingSystem *)&v63.m_ExitEvent.m_bCreatedHandle,
    cipher: v18,
    plain: (Color)32);
  Method = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v63.m_hThread);
  v19 = yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v63.m_hThread);
  TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
    this: (CLoggingSystem *)&v63.m_ExitEvent,
    cipher: v19,
    plain: (Color)Method);
  yaSSL::MD5::get_digest(
    this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v63.m_Lock.m_lockCount,
    out: (const CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)v63.m_szName);
  TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
    this: (CLoggingSystem *)&v63.m_Lock.m_CriticalSection[20],
    cipher: *(int *)&v63.m_Lock.m_CriticalSection[8],
    plain: (Color)32);
  TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
    this: (CLoggingSystem *)&v63.m_Lock.m_CriticalSection[16],
    cipher: v18,
    plain: (Color)32);
  v48 = yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v63.m_Lock.m_lockCount);
  v20 = yaSSL::EncryptedPreMasterSecret::get_length(this: (CUtlMemory<KeyValues *,int> *)&v63.m_Lock.m_lockCount);
  TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
    this: (CLoggingSystem *)&v63.m_Lock.m_CriticalSection[12],
    cipher: v20,
    plain: (Color)v48);
  yaSSL::MD5::get_digest(
    this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v63.m_Lock.m_CriticalSection[8],
    out: (const CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v63.m_szName[4]);
  yaSSL::sslHashes::get_MD5(this: v15, a2: v49, a3: v54, a4: v56, a5: v59);
  LOBYTE(v22) = yaSSL::Crypto::get_certManager(this: v21, a2: v50);
  v23 = v22;
  yaSSL::SSL::useSecurity(this: (char *)v15);
  if ( yaSSL::Security::use_parms(result: v51)->stmt_execute == (int (__cdecl *)(st_mysql_stmt *))1 )
  {
    peerKeyLength = (IConVar *)yaSSL::CertManager::get_peerKeyLength();
    peerKey = (unsigned __int8 *)yaSSL::CertManager::get_peerKey(this: v23);
    yaSSL::RSA::RSA(this: (CSplitScreenAddedConVar *)&v63, key: peerKey, sz: peerKeyLength, a4: true);
    yaSSL::RSA::verify(
      this: (CThreadMutex *)&v63,
      message: (const LoggingContext_t *)&v63.m_hThread,
      sz: 0x24u,
      sig: *(const LoggingContext_t **)(*(_DWORD *)&v63.m_Lock.m_CriticalSection[4] + 28),
      __formal: v61);
    if ( v25 == 0 )
      yaSSL::SSL::SetError(a1: v15, a2: 112);
    yaSSL::RSA::~RSA(this: (int *)&v63);
  }
  else
  {
    v62 = TaoCrypt::DecodeDSA_Signature(
            this: (TaoCrypt *)&v63.m_szName[24],
            a2: *(unsigned __int8 **)(*(_DWORD *)&v63.m_Lock.m_CriticalSection[4] + 28),
            a3: (const unsigned __int8 *)v61,
            a4: v52);
    v44 = (IConVar *)yaSSL::CertManager::get_peerKeyLength();
    v27 = (const LoggingContext_t *)yaSSL::CertManager::get_peerKey(this: v23);
    yaSSL::DSS::DSS(this: (CSplitScreenAddedConVar *)&v63, result: v27, sz: v44, publicKey: true);
    if ( yaSSL::DSS::verify(
           this: (yaSSL::DSS *)&v63,
           sha_digest: (CFunctor *)&v63.m_szName[4],
           a3: 0x14u,
           a4: (const unsigned __int8 *)&v63.m_szName[24],
           a5: v62) == 0 )
      yaSSL::SSL::SetError(a1: v15, a2: 112);
    yaSSL::DSS::~DSS(this: &v63);
  }
  v28 = operator new(sz: v26);
  if ( v28 != nullptr )
  {
    yaSSL::sslHashes::get_MD5(this: v15, a2: v52, a3: v55, a4: v57, a5: v60);
    v46 = *(const struct yaSSL::RandomPool **)&yaSSL::States::useServer().x;
    v45 = yaSSL::EncryptedPreMasterSecret::get_length(this: v4);
    Flags = (CUtlMemory<KeyValues *,int> *)ConCommandBase::GetFlags(this: v29);
    yaSSL::SSL_CTX::getCert(this: v31, a2: Flags);
    v41 = v32;
    g = (const unsigned __int8 *)yaSSL::ServerDHParams::get_g(this: v33);
    v39 = (unsigned __int16)yaSSL::SSL_CTX::getMethod(this: v34);
    p = (const unsigned __int8 *)yaSSL::ServerDHParams::get_p(this: v35);
    v37 = (unsigned __int16)yaSSL::DiffieHellman::DiffieHellman(
                              this: v28,
                              a2: p,
                              a3: v39,
                              encodedInteger: g,
                              byteCount: v41,
                              src: v42,
                              count: v45,
                              a8: v46);
  }
  else
  {
    v37 = 0;
  }
  yaSSL::sslHashes::get_MD5(this: v15, a2: v37, a3: v52, a4: v55, a5: v57);
  yaSSL::Crypto::SetDH(this: v38, a2: v47);
  yaSSL::SHA::~SHA(this: (Vector2D *)&v63.m_Lock.m_CriticalSection[8]);
  yaSSL::MD5::~MD5(this: (yaSSL::MD5 *)&v63.m_Lock.m_CriticalSection[16]);
  yaSSL::input_buffer::~input_buffer(this: (CUtlString *)&v63.m_Lock.m_currentOwnerID, a2: v53);
}

//------------------------------------------------------------------------------
// Address: 0x0042A410
// Name: public: void yaSSL::Parameters::SetSuites(struct yaSSL::ProtocolVersion,bool,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __stdcall yaSSL::Parameters::SetSuites(
        CKeyValuesDumpContextAsDevMsg *pv,
        bool removeDH,
        bool removeRSA,
        bool removeDSA)
{
  int v4; // edx
  int v5; // ecx
  int v6; // edx
  int v7; // edx
  int v8; // edx
  int v9; // edx
  int v10; // edx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx
  int v15; // edx
  int v16; // edx

  if ( (unsigned __int8)yaSSL::`anonymous namespace'::isTLS(a1: pv) != 0 )
  {
    if ( !removeDH )
    {
      if ( !removeRSA )
      {
        *(_BYTE *)(v5 + 47) = 0;
        *(_BYTE *)(v5 + 48) = 57;
        v4 = 2;
      }
      if ( !removeDSA )
      {
        *(_BYTE *)(v4 + v5 + 47) = 0;
        v6 = v4 + 1;
        *(_BYTE *)(v6 + v5 + 47) = 56;
        v4 = v6 + 1;
      }
    }
    if ( !removeRSA )
    {
      *(_BYTE *)(v4 + v5 + 47) = 0;
      v7 = v4 + 1;
      *(_BYTE *)(v7 + v5 + 47) = 53;
      v4 = v7 + 1;
    }
    if ( !removeDH )
    {
      if ( !removeRSA )
      {
        *(_BYTE *)(v4 + v5 + 47) = 0;
        v8 = v4 + 1;
        *(_BYTE *)(v8 + v5 + 47) = 51;
        v4 = v8 + 1;
      }
      if ( !removeDSA )
      {
        *(_BYTE *)(v4 + v5 + 47) = 0;
        v9 = v4 + 1;
        *(_BYTE *)(v9 + v5 + 47) = 50;
        v4 = v9 + 1;
      }
    }
    if ( !removeRSA )
    {
      *(_BYTE *)(v4 + v5 + 47) = 0;
      *(_BYTE *)(v4 + v5 + 48) = 47;
      v10 = v4 + 1;
      *(_BYTE *)(v10 + v5 + 48) = 0;
      *(_BYTE *)(++v10 + v5 + 48) = 126;
      v10 += 2;
      *(_BYTE *)(v10 + v5 + 47) = 0;
      *(_BYTE *)(++v10 + v5 + 47) = 125;
      *(_BYTE *)(++v10 + v5 + 47) = 0;
      *(_BYTE *)(++v10 + v5 + 47) = 124;
      v4 = v10 + 1;
    }
    if ( !removeDH )
    {
      if ( !removeRSA )
      {
        *(_BYTE *)(v4 + v5 + 47) = 0;
        *(_BYTE *)(v4 + v5 + 48) = 121;
        v11 = v4 + 2;
        *(_BYTE *)(v11 + v5 + 47) = 0;
        *(_BYTE *)(++v11 + v5 + 47) = 120;
        *(_BYTE *)(++v11 + v5 + 47) = 0;
        *(_BYTE *)(++v11 + v5 + 47) = 119;
        v4 = v11 + 1;
      }
      if ( !removeDSA )
      {
        *(_BYTE *)(v4 + v5 + 47) = 0;
        *(_BYTE *)(v4 + v5 + 48) = 116;
        v12 = v4 + 2;
        *(_BYTE *)(v12 + v5 + 47) = 0;
        *(_BYTE *)(++v12 + v5 + 47) = 115;
        *(_BYTE *)(++v12 + v5 + 47) = 0;
        *(_BYTE *)(++v12 + v5 + 47) = 114;
        v4 = v12 + 1;
      }
    }
  }
  if ( !removeRSA )
  {
    *(_BYTE *)(v4 + v5 + 47) = 0;
    *(_BYTE *)(v4 + v5 + 48) = 5;
    v13 = v4 + 1;
    *(_BYTE *)(v13 + v5 + 48) = 0;
    *(_BYTE *)(++v13 + v5 + 48) = 4;
    v13 += 2;
    *(_BYTE *)(v13 + v5 + 47) = 0;
    *(_BYTE *)(++v13 + v5 + 47) = 10;
    *(_BYTE *)(++v13 + v5 + 47) = 0;
    *(_BYTE *)(++v13 + v5 + 47) = 9;
    v4 = v13 + 1;
  }
  if ( !removeDH )
  {
    if ( !removeRSA )
    {
      *(_BYTE *)(v4 + v5 + 47) = 0;
      v14 = v4 + 1;
      *(_BYTE *)(v14 + v5 + 47) = 22;
      v4 = v14 + 1;
    }
    if ( !removeDSA )
    {
      *(_BYTE *)(v4 + v5 + 47) = 0;
      v15 = v4 + 1;
      *(_BYTE *)(v15 + v5 + 47) = 19;
      v4 = v15 + 1;
    }
    if ( !removeRSA )
    {
      *(_BYTE *)(v4 + v5 + 47) = 0;
      v16 = v4 + 1;
      *(_BYTE *)(v16 + v5 + 47) = 21;
      v4 = v16 + 1;
    }
    if ( !removeDSA )
    {
      *(_BYTE *)(v4 + v5 + 47) = 0;
      *(_BYTE *)(++v4 + v5 + 47) = 18;
      LOBYTE(v4) = v4 + 1;
    }
  }
  *(_BYTE *)(v5 + 46) = v4;
  yaSSL::Parameters::SetCipherNames(this: (yaSSL::Parameters *)v5);
}

//------------------------------------------------------------------------------
// Address: 0x0042A5B0
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::Alert::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
tagSAFEARRAY *__thiscall yaSSL::Alert::set(void *this, int a2)
{
  return (tagSAFEARRAY *)yaSSL::operator>>(a1: a2, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A5D0
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::Alert::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
tagVARIANT *__thiscall yaSSL::Alert::get(void *this, tagVARIANT *result)
{
  return (tagVARIANT *)yaSSL::operator<<(output: (HWND__ *)result, a: (unsigned int)this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A5F0
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::Data::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::Data::get(CUtlCharConversion *this, yaSSL::output_buffer *a2)
{
  return yaSSL::operator<<(a1: a2, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x0042A610
// Name: public: yaSSL::Certificate::Certificate(class yaSSL::x509 const __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall yaSSL::Certificate::Certificate(CUtlString *this, yaSSL::SSL_CTX *cert)
{
  const struct SSL_METHOD *Method; // eax
  int v5; // [esp+0h] [ebp-4h]

  this->m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)&yaSSL::Certificate::`vftable';
  this->m_Storage.m_Memory.m_nGrowSize = (int)cert;
  Method = yaSSL::SSL_CTX::getMethod(this: cert);
  yaSSL::Crypto::setCipher(this, i: (const char *)Method + 6, a3: v5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042A640
// Name: public: yaSSL::ServerDHParams::~ServerDHParams(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ServerDHParams::~ServerDHParams(yaSSL::ServerDHParams *this)
{
  void **v2; // [esp-8h] [ebp-Ch]
  void **v3; // [esp-4h] [ebp-8h]
  void **v4; // [esp+0h] [ebp-4h]

  yaSSL::ysArrayDelete<unsigned char>(ptr: *((void **)this + 5), a2: v4);
  yaSSL::ysArrayDelete<unsigned char>(ptr: *((void **)this + 4), a2: v3);
  yaSSL::ysArrayDelete<unsigned char>(ptr: *((void **)this + 3), a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0042A670
// Name: public: virtual void yaSSL::ServerHello::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0042A860
// Name: public: virtual void yaSSL::ClientHello::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::ClientHello::Process(
        yaSSL::ClientHello *this@<ecx>,
        const st_mysql_methods *a2@<ebp>,
        struct yaSSL::input_buffer *a3,
        struct SSL *a4)
{
  __int16 v5; // bx
  ShortVector *v6; // eax
  int v7; // eax
  ShortVector *v8; // eax
  yaSSL::Connection *v9; // eax
  ShortVector *v10; // eax
  int v11; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v12; // eax
  int v13; // eax
  ShortVector *v14; // eax
  yaSSL::Connection *v15; // eax
  yaSSL::Security *v16; // eax
  QuaternionAligned *Context; // eax
  yaSSL::Sessions *Sessions; // eax
  ShortVector *v19; // eax
  yaSSL::SSL_SESSION *v20; // ebp
  CThreadSyncObject *v21; // eax
  const st_mysql_methods *v22; // eax
  yaSSL::Security *v23; // eax
  const unsigned __int8 *Suite; // eax
  const st_mysql_methods *v25; // eax
  const unsigned __int8 *Secret; // eax
  ShortVector v27; // rax
  CKeyValuesDumpContextAsDevMsg *v28; // [esp-10h] [ebp-50h]
  const unsigned __int8 *v29; // [esp-Ch] [ebp-4Ch]
  unsigned __int8 *v30; // [esp-Ch] [ebp-4Ch]
  unsigned int v31; // [esp-8h] [ebp-48h]
  __int16 v33; // [esp-4h] [ebp-44h]
  int v34; // [esp-4h] [ebp-44h]
  st_mysql *v35; // [esp-4h] [ebp-44h]
  __int16 v36; // [esp+0h] [ebp-40h]
  int v37; // [esp+0h] [ebp-40h]
  int v38; // [esp+0h] [ebp-40h]
  int v39; // [esp+0h] [ebp-40h]
  __int16 v40; // [esp+0h] [ebp-40h]
  const st_mysql_methods *v41; // [esp+0h] [ebp-40h]
  __int16 v42; // [esp+0h] [ebp-40h]
  int v43; // [esp+0h] [ebp-40h]
  __int16 v44; // [esp+0h] [ebp-40h]
  int v45; // [esp+0h] [ebp-40h]
  int v46; // [esp+0h] [ebp-40h]
  CThreadSyncObject *v47; // [esp+0h] [ebp-40h]
  __int16 v48; // [esp+4h] [ebp-3Ch]
  CThreadSyncObject *v49; // [esp+4h] [ebp-3Ch]
  CThreadSyncObject *v50; // [esp+4h] [ebp-3Ch]
  CThreadSyncObject *v51; // [esp+4h] [ebp-3Ch]
  __int16 v52; // [esp+4h] [ebp-3Ch]
  __int16 v53; // [esp+4h] [ebp-3Ch]
  __int16 v54; // [esp+4h] [ebp-3Ch]
  CThreadSyncObject *v55; // [esp+4h] [ebp-3Ch]
  CThreadSyncObject *v56; // [esp+4h] [ebp-3Ch]
  __int16 v57; // [esp+8h] [ebp-38h]
  bool v58; // [esp+8h] [ebp-38h]
  bool v59; // [esp+8h] [ebp-38h]
  __int16 v60; // [esp+8h] [ebp-38h]
  __int16 v61; // [esp+8h] [ebp-38h]
  __int16 v62; // [esp+8h] [ebp-38h]
  unsigned int v63; // [esp+8h] [ebp-38h]
  bool v64; // [esp+8h] [ebp-38h]
  bool v65; // [esp+8h] [ebp-38h]
  __int16 removeDSA; // [esp+Ch] [ebp-34h]
  unsigned int removeDSAa; // [esp+Ch] [ebp-34h]
  unsigned int removeDSAb; // [esp+Ch] [ebp-34h]
  unsigned int removeDSAc; // [esp+Ch] [ebp-34h]
  __int16 removeDSAh; // [esp+Ch] [ebp-34h]
  __int16 removeDSAi; // [esp+Ch] [ebp-34h]
  bool removeDSAd; // [esp+Ch] [ebp-34h]
  __int16 removeDSAe; // [esp+Ch] [ebp-34h]
  unsigned int removeDSAf; // [esp+Ch] [ebp-34h]
  unsigned int removeDSAg; // [esp+Ch] [ebp-34h]
  bool removeRSA; // [esp+10h] [ebp-30h]
  char removeDH; // [esp+14h] [ebp-2Ch]
  const st_mysql_methods *pv; // [esp+18h] [ebp-28h]
  <CrtImplementationDetails>::NativeDll serverRandom; // [esp+1Ch] [ebp-24h] BYREF

  v5 = *((_WORD *)this + 4);
  v6 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)a4);
  yaSSL::sslHashes::get_MD5(this: v6, a2: v36, a3: v48, a4: v57, a5: removeDSA);
  *(_WORD *)(v7 + 304) = v5;
  if ( *((_BYTE *)this + 8) != 3 )
  {
LABEL_2:
    yaSSL::SSL::SetError(a1: a4, a2: 117);
    return;
  }
  if ( (unsigned __int8)yaSSL::SSL::GetMultiProtocol(a1: v37, a2: v49, a3: v58, a4: removeDSAa) != 0 )
  {
    if ( (unsigned __int8)yaSSL::SSL::isTLS(a1: v38, a2: v50, a3: v59, a4: removeDSAb) == 0 || *((_BYTE *)this + 9) != 0 )
    {
      if ( (unsigned __int8)yaSSL::SSL::isTLSv1_1(a1: v39, a2: v51, a3: v60, a4: removeDSAc) != 0
        && *((_BYTE *)this + 9) == 1 )
      {
        v14 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)a4);
        yaSSL::sslHashes::get_MD5(this: v14, a2: v44, a3: v54, a4: v63, a5: removeDSAe);
        yaSSL::Connection::TurnOffTLS1_1(this: v15);
      }
    }
    else
    {
      v8 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)a4);
      yaSSL::sslHashes::get_MD5(this: v8, a2: v39, a3: (__int16)v51, a4: v60, a5: removeDSAc);
      yaSSL::Connection::TurnOffTLS(this: v9);
      v10 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)a4);
      yaSSL::sslHashes::get_MD5(this: v10, a2: v40, a3: v52, a4: v61, a5: removeDSAh);
      LOWORD(pv) = *(_WORD *)(v11 + 302);
      yaSSL::SSL::useSecurity(this: (char *)a4);
      removeDH = HIBYTE(yaSSL::Security::use_parms(result: v41)[27].read_prepare_result);
      removeRSA = false;
      LOBYTE(removeDSAi) = 0;
      yaSSL::sslHashes::get_MD5(this: (ShortVector *)a4, a2: v42, a3: v53, a4: v62, a5: removeDSAi);
      LOBYTE(v13) = yaSSL::Crypto::get_certManager(this: v12, a2: v43);
      if ( yaSSL::CertManager::get_keyType(a1: v13) == 1 )
        removeDSAd = true;
      else
        removeRSA = true;
      yaSSL::SSL::useSecurity(this: (char *)a4);
      yaSSL::Security::use_parms(result: pv);
      yaSSL::Parameters::SetSuites(pv: v28, removeDH, removeRSA, removeDSA: removeDSAd);
    }
  }
  else if ( (unsigned __int8)yaSSL::SSL::isTLSv1_1(a1: v38, a2: v50, a3: v59, a4: removeDSAb) != 0
         && *((_BYTE *)this + 9) < 2u
         || (unsigned __int8)yaSSL::SSL::isTLS(a1: v45, a2: v55, a3: v64, a4: removeDSAf) != 0
         && *((_BYTE *)this + 9) == 0
         || (unsigned __int8)yaSSL::SSL::isTLS(a1: v46, a2: v56, a3: v65, a4: removeDSAg) == 0
         && *((_BYTE *)this + 9) != 0 )
  {
    goto LABEL_2;
  }
  yaSSL::SSL::set_random(a1: a4, a2: (char *)this + 10, a3: 1);
  if ( *((_BYTE *)this + 42) != 0 )
  {
    v16 = (yaSSL::Security *)yaSSL::SSL::useSecurity(this: (char *)a4);
    Context = (QuaternionAligned *)yaSSL::Security::GetContext(this: v16);
    if ( (unsigned __int8)yaSSL::SSL_CTX::GetSessionCacheOff(this: Context) == 0 )
    {
      Sessions = (yaSSL::Sessions *)yaSSL::GetSessions(this: (yaSSL *)((char *)this + 43));
      v19 = (ShortVector *)yaSSL::Sessions::lookup(this: Sessions, iter: v29, a3: nullptr);
      v20 = (yaSSL::SSL_SESSION *)v19;
      if ( v19 != nullptr )
      {
        yaSSL::SSL::set_session(this: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)a4, a2: v19);
        v23 = (yaSSL::Security *)yaSSL::SSL::useSecurity(this: (char *)a4);
        yaSSL::Security::set_resuming(this: v23, a2: true);
        Suite = yaSSL::SSL_SESSION::GetSuite(this: v20);
        yaSSL::SSL::matchSuite(this: a4, a2: Suite, a3: 2u);
        yaSSL::SSL::useSecurity(this: (char *)a4);
        v25 = yaSSL::Security::use_parms(result: a2);
        yaSSL::SSL::set_pending(this: (CUtlString *)a4, suite: BYTE1(v25->free_embedded_thd));
        Secret = yaSSL::SSL_SESSION::GetSecret(this: v20);
        yaSSL::SSL::set_masterSecret(this: a4, a2: Secret);
        yaSSL::sslHashes::get_MD5(this: (ShortVector *)a4, a2: (__int16)&serverRandom, a3: 32, a4: v33, a5: v44);
        v27 = yaSSL::States::useServer();
        yaSSL::RandomPool::Fill(this: *(yaSSL::RandomPool **)&v27.x, dst: v30, sz: v31);
        yaSSL::SSL::set_random(a1: a4, a2: &serverRandom, a3: 0);
        if ( (unsigned __int8)yaSSL::SSL::isTLS(a1: v34, a2: v47, a3: v54, a4: v63) != 0 )
          yaSSL::SSL::deriveTLSKeys(result: v35);
        else
          yaSSL::SSL::deriveKeys(result: v35);
        yaSSL::SSL::useStates(this: (char *)a4);
        **(_DWORD **)&yaSSL::States::useServer().x = 2;
        return;
      }
    }
    v21 = yaSSL::SSL::useLog(this: (char *)a4);
    yaSSL::ServerKeyBase::build(this: (CEmptyConVar *)v21, nValue: (int)&stru_47C598);
  }
  yaSSL::SSL::matchSuite(this: a4, a2: (const unsigned __int8 *)this + 78, a3: *((unsigned __int16 *)this + 38));
  if ( yaSSL::SSL::GetError(this: (char *)a4) == 0 )
  {
    yaSSL::SSL::useSecurity(this: (char *)a4);
    v22 = yaSSL::Security::use_parms(result: a2);
    yaSSL::SSL::set_pending(this: (CUtlString *)a4, suite: BYTE1(v22->free_embedded_thd));
    if ( *(this + 52) == (yaSSL::ClientHello)221 )
      yaSSL::Compress();
    yaSSL::SSL::useStates(this: (char *)a4);
    **(_DWORD **)&yaSSL::States::useServer().x = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AB80
// Name: public: virtual yaSSL::ServerKeyExchange::~ServerKeyExchange(void)
// Source: json
//------------------------------------------------------------------------------
CDefaultAccessor *__thiscall yaSSL::ServerKeyExchange::~ServerKeyExchange(CDefaultAccessor *this)
{
  CDefaultAccessor *v2; // eax

  this->__vftable = (CDefaultAccessor_vtbl *)&yaSSL::ServerKeyExchange::`vftable';
  v2 = yaSSL::ysDelete<yaSSL::ClientKeyBase>(ptr: this);
  this->__vftable = (CDefaultAccessor_vtbl *)&yaSSL::HandShakeBase::`vftable';
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0042ABA0
// Name: public: virtual yaSSL::CertificateVerify::~CertificateVerify(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertificateVerify::~CertificateVerify(yaSSL::CertificateVerify *this)
{
  void *v2; // [esp-4h] [ebp-8h]
  void **v3; // [esp+0h] [ebp-4h]

  v2 = *((void **)this + 11);
  *this = (yaSSL::CertificateVerify)&yaSSL::CertificateVerify::`vftable';
  yaSSL::ysArrayDelete<unsigned char>(ptr: v2, a2: v3);
  *this = (yaSSL::CertificateVerify)&yaSSL::HandShakeBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0042ABC0
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::CertificateVerify::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall yaSSL::CertificateVerify::set(yaSSL::CertificateVerify *this, CUtlString *a2)
{
  return yaSSL::operator>>(a1: a2, a2: (CUtlString *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0042ABE0
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::CertificateVerify::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
const CDefaultAccessor *__thiscall yaSSL::CertificateVerify::get(
        yaSSL::CertificateVerify *this,
        CDefaultAccessor *result)
{
  return yaSSL::operator<<(result);
}

//------------------------------------------------------------------------------
// Address: 0x0042AC30
// Name: public: virtual yaSSL::ClientKeyExchange::~ClientKeyExchange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ClientKeyExchange::~ClientKeyExchange(CUtlVectorAutoPurge<char *> *this)
{
  this->m_Memory.m_pMemory = (char **)&yaSSL::ClientKeyExchange::`vftable';
  yaSSL::ysDelete<yaSSL::ClientKeyBase>(ptr: (const CDefaultAccessor *)this);
  this->m_Memory.m_pMemory = (char **)&yaSSL::HandShakeBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0042AC50
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::ClientKeyExchange::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
IConCommandBaseAccessor *__thiscall yaSSL::ClientKeyExchange::get(
        CUtlMemory<QueuedPacket_t *,int> *this,
        IConCommandBaseAccessor *out)
{
  return yaSSL::operator<<(result: out);
}

//------------------------------------------------------------------------------
// Address: 0x0042AC70
// Name: public: void yaSSL::Connection::CleanPreMaster(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Connection::CleanPreMaster(yaSSL::Connection *this)
{
  void **v2; // [esp-Ch] [ebp-10h]

  if ( *(_DWORD *)this != 0 )
  {
    yaSSL::clean(
      p: *(_DWORD *)this,
      sz: *((volatile unsigned __int8 **)this + 73),
      ran: *((yaSSL::RandomPool **)this + 77));
    yaSSL::ysArrayDelete<unsigned char>(ptr: *(void **)this, a2: v2);
    *(_DWORD *)this = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042ACA0
// Name: struct yaSSL::Message __near * yaSSL::CreateAlert(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::CreateAlert(const CSplitScreenAddedConVar *ecx0)
{
  CSplitScreenAddedConVar *result; // eax

  result = operator new(sz: ecx0);
  if ( result == nullptr )
    return nullptr;
  result->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::Alert::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042ACC0
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateHelloRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateHelloRequest(const CSplitScreenAddedConVar *this)
{
  CSplitScreenAddedConVar *v1; // eax

  v1 = operator new(sz: this);
  if ( v1 != nullptr )
    v1->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::HelloRequest::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0042ACE0
// Name: struct yaSSL::ServerKeyBase __near * yaSSL::CreateRSAServerKEA(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::CreateRSAServerKEA(const CSplitScreenAddedConVar *ecx0)
{
  CSplitScreenAddedConVar *result; // eax

  result = operator new(sz: ecx0);
  if ( result == nullptr )
    return nullptr;
  result->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::RSA_Server::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AD10
// Name: struct yaSSL::ServerKeyBase __near * yaSSL::CreateFortezzaServerKEA(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::CreateFortezzaServerKEA(const CSplitScreenAddedConVar *ecx0)
{
  CSplitScreenAddedConVar *result; // eax

  result = operator new(sz: ecx0);
  if ( result == nullptr )
    return nullptr;
  result->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::Fortezza_Server::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AD40
// Name: struct yaSSL::ClientKeyBase __near * yaSSL::CreateRSAClient(void)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<QueuedPacket_t *,int> *__thiscall yaSSL::CreateRSAClient(const CSplitScreenAddedConVar *ecx0)
{
  CUtlMemory<QueuedPacket_t *,int> *v1; // eax

  v1 = (CUtlMemory<QueuedPacket_t *,int> *)operator new(sz: ecx0);
  if ( v1 != nullptr )
    return yaSSL::EncryptedPreMasterSecret::EncryptedPreMasterSecret(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042AD60
// Name: struct yaSSL::ClientKeyBase __near * yaSSL::CreateFortezzaClient(void)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__thiscall yaSSL::CreateFortezzaClient(const CSplitScreenAddedConVar *ecx0)
{
  CSplitScreenAddedConVar *result; // eax

  result = operator new(sz: ecx0);
  if ( result == nullptr )
    return nullptr;
  result->ConVar::ConCommandBase::__vftable = (CSplitScreenAddedConVar_vtbl *)&yaSSL::FortezzaKeys::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042ADA0
// Name: public: void yaSSL::ClientKeyExchange::createKey(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ClientKeyExchange::createKey(yaSSL::ClientKeyExchange *this, struct SSL *a2)
{
  const struct yaSSL::sslFactory *Factory; // eax
  int *ClientKey; // esi
  const st_mysql_methods *v5; // eax
  int v6; // ecx
  int v7; // edx
  char (__cdecl *read_prepare_result)(st_mysql *, st_mysql_stmt *); // eax
  int v9; // eax
  yaSSL *v10; // [esp+0h] [ebp-Ch]
  const st_mysql_methods *v11; // [esp+0h] [ebp-Ch]

  Factory = yaSSL::SSL::getFactory(this: a2, a2: v10);
  ClientKey = (int *)yaSSL::sslFactory::getClientKey(a1: Factory);
  yaSSL::SSL::useSecurity(this: (char *)a2);
  v5 = yaSSL::Security::use_parms(result: v11);
  v6 = *ClientKey;
  v7 = ClientKey[1];
  read_prepare_result = v5->read_prepare_result;
  if ( *ClientKey == v7 )
  {
    v9 = 0;
  }
  else
  {
    do
    {
      if ( *(char (__cdecl **)(st_mysql *, st_mysql_stmt *))v6 == read_prepare_result )
        break;
      v6 += 8;
    }
    while ( v6 != v7 );
    if ( v6 == v7 )
      v9 = 0;
    else
      v9 = (*(int (**)(void))(v6 + 4))();
  }
  *(_DWORD *)&(*this)[4] = v9;
  if ( v9 == 0 )
    yaSSL::SSL::SetError(a1: a2, a2: 103);
}

//------------------------------------------------------------------------------
// Address: 0x0042AE10
// Name: public: void yaSSL::ServerKeyExchange::createKey(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::ServerKeyExchange::createKey(yaSSL::ServerKeyExchange *this, struct SSL *a2)
{
  int *Ciphers; // esi
  const st_mysql_methods *v4; // eax
  int v5; // ecx
  int v6; // edx
  char (__cdecl *read_prepare_result)(st_mysql *, st_mysql_stmt *); // eax
  int result; // eax
  yaSSL *v9; // [esp+0h] [ebp-Ch]
  const st_mysql_methods *v10; // [esp+0h] [ebp-Ch]

  yaSSL::SSL::getFactory(this: a2, a2: v9);
  Ciphers = (int *)yaSSL::SSL_CTX::GetCiphers();
  yaSSL::SSL::useSecurity(this: (char *)a2);
  v4 = yaSSL::Security::use_parms(result: v10);
  v5 = *Ciphers;
  v6 = Ciphers[1];
  read_prepare_result = v4->read_prepare_result;
  if ( *Ciphers == v6 )
  {
    result = 0;
  }
  else
  {
    do
    {
      if ( *(char (__cdecl **)(st_mysql *, st_mysql_stmt *))v5 == read_prepare_result )
        break;
      v5 += 8;
    }
    while ( v5 != v6 );
    if ( v5 == v6 )
      result = 0;
    else
      result = (*(int (**)(void))(v5 + 4))();
  }
  *((_DWORD *)this + 2) = result;
  if ( result == 0 )
    return yaSSL::SSL::SetError(a1: a2, a2: 103);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AEA0
// Name: public: yaSSL::DH_Server::DH_Server(void)
// Source: json
//------------------------------------------------------------------------------
const CAutoLockT<CThreadFastMutex> *__thiscall yaSSL::DH_Server::DH_Server(char *this)
{
  _DWORD *v1; // edx

  *(_DWORD *)this = &yaSSL::DH_Server::`vftable';
  yaSSL::ServerDHParams::ServerDHParams(this: (yaSSL::ServerDHParams *)(this + 4));
  v1[7] = 0;
  v1[8] = 0;
  v1[9] = 0;
  return (const CAutoLockT<CThreadFastMutex> *)v1;
}

//------------------------------------------------------------------------------
// Address: 0x0042AEC0
// Name: public: virtual yaSSL::DH_Server::~DH_Server(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DH_Server::~DH_Server(CAutoLockT<CThreadFastMutex> *this)
{
  void *v2; // [esp-4h] [ebp-8h]
  void **v3; // [esp-4h] [ebp-8h]
  void **v4; // [esp+0h] [ebp-4h]

  v2 = *((void **)this + 9);
  this->m_lock = (CThreadFastMutex *)&yaSSL::DH_Server::`vftable';
  yaSSL::ysArrayDelete<unsigned char>(ptr: v2, a2: v4);
  yaSSL::ysArrayDelete<unsigned char>(ptr: *((void **)this + 7), a2: v3);
  yaSSL::ServerDHParams::~ServerDHParams(this: (yaSSL::ServerDHParams *)(this + 1));
  this->m_lock = (CThreadFastMutex *)&yaSSL::ServerKeyBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0042AEF0
// Name: public: yaSSL::Parameters::Parameters(enum yaSSL::ConnectionEnd,struct yaSSL::Ciphers const __near &,struct yaSSL::ProtocolVersion,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall yaSSL::Parameters::Parameters(
        int this,
        modsv_t *ce,
        int a3,
        CKeyValuesDumpContextAsDevMsg *pv,
        bool haveDH)
{
  bool v7; // al

  *(_DWORD *)this = ce;
  *(_BYTE *)(this + 40) = 1;
  strncpy(dest: (unsigned __int8 *)(this + 175), source: "NONE", count: 5u);
  *(_BYTE *)(this + 1759) = !haveDH;
  if ( *(_BYTE *)a3 != 0 )
  {
    *(_BYTE *)(this + 46) = *(_BYTE *)(a3 + 132);
    memcpy(dst: (unsigned __int8 *)(this + 47), src: (unsigned __int8 *)(a3 + 1), count: *(_DWORD *)(a3 + 132));
    yaSSL::Parameters::SetCipherNames((yaSSL::Parameters *)this);
    return this;
  }
  else
  {
    v7 = ce == nullptr && !haveDH;
    yaSSL::Parameters::SetSuites(pv, removeDH: v7, removeRSA: false, removeDSA: false);
    return this;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AF80
// Name: public: virtual void yaSSL::ServerKeyExchange::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::ServerKeyExchange::Process(
        yaSSL::ServerKeyExchange *this,
        struct yaSSL::input_buffer *a2,
        struct SSL *a3)
{
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v4; // eax
  int v5; // [esp+0h] [ebp-8h]
  KeyValues *const *v6; // [esp+4h] [ebp-4h]

  yaSSL::ServerKeyExchange::createKey(this, a2: a3);
  if ( yaSSL::SSL::GetError(this: (char *)a3) == 0 )
  {
    (*(void (__thiscall **)(_DWORD, struct SSL *, struct yaSSL::input_buffer *))(**((_DWORD **)this + 2) + 8))(
      a1: *((_DWORD *)this + 2),
      a2: a3,
      a3: a2);
    v4 = (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)yaSSL::SSL::useStates(this: (char *)a3);
    *(_DWORD *)yaSSL::States::useClient(this: v4, a2: v5, a3: v6) = 3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AFE0
// Name: class yaSSL::input_buffer __near & yaSSL::operator>>(class yaSSL::input_buffer __near &,class yaSSL::CertificateRequest __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__cdecl yaSSL::operator>>(CUtlString *a1, int a2)
{
  CUtlString *v2; // edi
  int m_pMemory_low; // eax
  int v4; // ebp
  int v5; // esi
  _DWORD *v6; // ebx
  const IntVector4D *v7; // ecx
  const IntVector4D *v8; // ecx
  sockaddr *v9; // esi
  int v11; // [esp+Ch] [ebp-4h]

  v2 = a1;
  m_pMemory_low = LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
  v4 = a2;
  v5 = 0;
  *(_DWORD *)(a2 + 36) = m_pMemory_low;
  if ( m_pMemory_low != 0 )
  {
    v6 = (_DWORD *)(v4 + 8);
    do
    {
      *v6 = LOBYTE(yaSSL::input_buffer::operator[](result: (CUtlString *)0xFEEDBEEF)->m_Storage.m_Memory.m_pMemory);
      ++v5;
      ++v6;
    }
    while ( v5 < *(_DWORD *)(v4 + 36) );
  }
  yaSSL::input_buffer::read(this: v2, dst: (const char *)&a1);
  yaSSL::ato16(c: v7);
  for ( ; (_WORD)v11 != 0; v11 += 65534 - a2 )
  {
    yaSSL::input_buffer::read(this: v2, dst: (const char *)&a1);
    yaSSL::ato16(c: v8);
    v9 = (sockaddr *)operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
    mySTL::list<yaSSL::x509 *>::push_back(result: v9);
    v9->sa_family = (unsigned __int16)a1;
    yaSSL::input_buffer::read(this: v2, dst: v9->sa_data);
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0042B1A0
// Name: public: virtual void yaSSL::ClientKeyExchange::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0042B220
// Name: public: yaSSL::ClientKeyExchange::ClientKeyExchange(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
__int16 *__thiscall yaSSL::ClientKeyExchange::ClientKeyExchange(yaSSL::ClientKeyExchange *this, struct SSL *a2)
{
  *(_DWORD *)this = &yaSSL::ClientKeyExchange::`vftable';
  yaSSL::ClientKeyExchange::createKey(this, a2);
  return *this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B250
// Name: public: yaSSL::Connection::~Connection(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::Connection::~Connection(yaSSL::Connection *this)
{
  void **v2; // [esp+0h] [ebp-4h]

  yaSSL::Connection::CleanMaster(this);
  yaSSL::Connection::CleanPreMaster(this);
  yaSSL::ysArrayDelete<unsigned char>(ptr: *(void **)this, a2: v2);
}

//------------------------------------------------------------------------------
// Address: 0x0042B270
// Name: struct yaSSL::ServerKeyBase __near * yaSSL::CreateDHServerKEA(void)
// Source: json
//------------------------------------------------------------------------------
const CAutoLockT<CThreadFastMutex> *__thiscall yaSSL::CreateDHServerKEA(const CSplitScreenAddedConVar *ecx0)
{
  char *v1; // eax

  v1 = (char *)operator new(sz: ecx0);
  if ( v1 != nullptr )
    return yaSSL::DH_Server::DH_Server(this: v1);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042B290
// Name: public: virtual void yaSSL::DH_Server::build(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::DH_Server::build(int this, ShortVector *result)
{
  CUtlMemory<KeyValues *,int> *v3; // eax
  const struct TaoCrypt::Integer **length; // ebp
  unsigned __int8 *v5; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v6; // eax
  yaSSL::CertManager *v7; // eax
  yaSSL::CertManager *v8; // ebp
  const CSplitScreenAddedConVar *v9; // ecx
  const char *v10; // ecx
  unsigned __int8 *privateKey; // eax
  const char *v12; // ecx
  CSplitScreenAddedConVar *v13; // ebp
  const LoggingContext_t *v14; // eax
  const char *v15; // ecx
  CSplitScreenAddedConVar *v16; // ebp
  int v17; // ecx
  const char *v18; // ecx
  unsigned int v19; // ebp
  const unsigned __int8 *p; // eax
  float v21; // ecx
  const unsigned __int8 *g; // eax
  const unsigned __int8 *Flags; // eax
  ShortVector *v24; // eax
  int v25; // eax
  int v26; // edi
  CUtlMemory<KeyValues *,int> *Method; // eax
  int v28; // eax
  CUtlMemory<KeyValues *,int> *v29; // eax
  int v30; // eax
  const char *m_nAllocationCount; // edi
  ShortVector v32; // rax
  ShortVector v33; // rax
  CUtlMemory<KeyValues *,int> *v34; // eax
  unsigned __int8 *v35; // eax
  const char *v36; // ecx
  Color v37; // [esp+0h] [ebp-B8h]
  const st_mysql_methods *v38; // [esp+0h] [ebp-B8h]
  __int16 v39; // [esp+0h] [ebp-B8h]
  int v40; // [esp+0h] [ebp-B8h]
  int v41; // [esp+0h] [ebp-B8h]
  __int16 v42; // [esp+4h] [ebp-B4h]
  int v43; // [esp+4h] [ebp-B4h]
  int v44; // [esp+4h] [ebp-B4h]
  __int16 v45; // [esp+8h] [ebp-B0h]
  int v46; // [esp+8h] [ebp-B0h]
  int v47; // [esp+8h] [ebp-B0h]
  Color v48; // [esp+Ch] [ebp-ACh]
  __int16 v49; // [esp+Ch] [ebp-ACh]
  int v50; // [esp+Ch] [ebp-ACh]
  int v51; // [esp+Ch] [ebp-ACh]
  unsigned __int8 *v52; // [esp+10h] [ebp-A8h]
  IConVar *privateKeyLength; // [esp+10h] [ebp-A8h]
  IConVar *v54; // [esp+10h] [ebp-A8h]
  int v55; // [esp+10h] [ebp-A8h]
  unsigned __int8 *v56; // [esp+14h] [ebp-A4h]
  unsigned int v57; // [esp+14h] [ebp-A4h]
  unsigned int v58; // [esp+14h] [ebp-A4h]
  unsigned int v59; // [esp+14h] [ebp-A4h]
  unsigned int v60; // [esp+14h] [ebp-A4h]
  QueuedPacket_t *v61; // [esp+14h] [ebp-A4h]
  QueuedPacket_t *v62; // [esp+14h] [ebp-A4h]
  unsigned int v63; // [esp+14h] [ebp-A4h]
  __int16 v64; // [esp+18h] [ebp-A0h]
  __int16 v65; // [esp+18h] [ebp-A0h]
  char *v66; // [esp+18h] [ebp-A0h]
  const st_mysql_methods *v67; // [esp+18h] [ebp-A0h]
  char *v68; // [esp+18h] [ebp-A0h]
  QueuedPacket_t *const *v69; // [esp+18h] [ebp-A0h]
  char *v70; // [esp+18h] [ebp-A0h]
  __int16 v71; // [esp+1Ch] [ebp-9Ch]
  __int16 v72; // [esp+1Ch] [ebp-9Ch]
  const char *v73; // [esp+1Ch] [ebp-9Ch]
  const char *v74; // [esp+1Ch] [ebp-9Ch]
  CUtlMemory<KeyValues *,int> cipher; // [esp+20h] [ebp-98h] BYREF
  CUtlMemory<KeyValues *,int> v76; // [esp+2Ch] [ebp-8Ch] BYREF
  int sigSz; // [esp+40h] [ebp-78h] BYREF
  int gSz; // [esp+44h] [ebp-74h] BYREF
  int pubSz; // [esp+48h] [ebp-70h] BYREF
  int pSz; // [esp+4Ch] [ebp-6Ch] BYREF
  float *sha; // [esp+50h] [ebp-68h] BYREF
  CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > out; // [esp+54h] [ebp-64h] BYREF
  _BYTE v83[46]; // [esp+84h] [ebp-34h]

  yaSSL::sslHashes::get_MD5(
    this: result,
    a2: v64,
    a3: v71,
    a4: (__int16)cipher.m_pMemory,
    a5: cipher.m_nAllocationCount);
  length = (const struct TaoCrypt::Integer **)yaSSL::EncryptedPreMasterSecret::get_length(this: v3);
  yaSSL::DiffieHellman::set_sizes(this: length, a2: &pSz, a3: &gSz, a4: &pubSz);
  v56 = (unsigned __int8 *)yaSSL::ServerDHParams::alloc_pub(this: (_DWORD *)(this + 4), result: (matrix3x4_t *)pubSz);
  v52 = (unsigned __int8 *)yaSSL::ServerDHParams::alloc_g(this: (_DWORD *)(this + 4), result: (matrix3x4_t *)gSz);
  v5 = (unsigned __int8 *)yaSSL::ServerDHParams::alloc_p(this: (_DWORD *)(this + 4), result: (matrix3x4_t *)pSz);
  yaSSL::DiffieHellman::get_parms(this: length, a2: v5, a3: v52, dst: v56);
  sigSz = 0;
  v76.m_nAllocationCount = 0;
  yaSSL::sslHashes::get_MD5(
    this: result,
    a2: v65,
    a3: v72,
    a4: (__int16)cipher.m_pMemory,
    a5: cipher.m_nAllocationCount);
  LOBYTE(v7) = yaSSL::Crypto::get_certManager(this: v6, a2: (int)v66);
  v8 = v7;
  yaSSL::SSL::useSecurity(this: (char *)result);
  if ( yaSSL::Security::use_parms(result: v67)->stmt_execute == (int (__cdecl *)(st_mysql_stmt *))1 )
  {
    if ( yaSSL::CertManager::get_keyType(a1: v8) != 1 )
    {
LABEL_3:
      yaSSL::SSL::SetError(a1: result, a2: 116);
      yaSSL::ysDelete<yaSSL::Auth>(
        ptr: v10,
        a2: nullptr,
        a3: (int)v68,
        a4: v73,
        a5: (void (__cdecl *)(IConVar *, const char *, float))cipher.m_pMemory);
      return;
    }
    v76.m_pMemory = (KeyValues **)operator new(sz: v9);
    if ( v76.m_pMemory != nullptr )
    {
      privateKeyLength = (IConVar *)yaSSL::CertManager::get_privateKeyLength();
      privateKey = (unsigned __int8 *)yaSSL::CertManager::get_privateKey(this: v8);
      v13 = yaSSL::RSA::RSA(
              this: (CSplitScreenAddedConVar *)v76.m_pMemory,
              key: privateKey,
              sz: privateKeyLength,
              a4: false);
      if ( v13 != nullptr )
      {
        yaSSL::ysDelete<yaSSL::Auth>(
          ptr: v12,
          a2: nullptr,
          a3: (int)v68,
          a4: v73,
          a5: (void (__cdecl *)(IConVar *, const char *, float))cipher.m_pMemory);
        v76.m_nAllocationCount = (int)v13;
      }
    }
  }
  else
  {
    if ( yaSSL::CertManager::get_keyType(a1: v8) != 2 )
      goto LABEL_3;
    v76.m_pMemory = (KeyValues **)operator new(sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
    if ( v76.m_pMemory != nullptr )
    {
      v54 = (IConVar *)yaSSL::CertManager::get_privateKeyLength();
      v14 = (const LoggingContext_t *)yaSSL::CertManager::get_privateKey(this: v8);
      v16 = yaSSL::DSS::DSS(this: (CSplitScreenAddedConVar *)v76.m_pMemory, result: v14, sz: v54, publicKey: false);
      if ( v16 != nullptr )
      {
        yaSSL::ysDelete<yaSSL::Auth>(
          ptr: v15,
          a2: nullptr,
          a3: (int)v68,
          a4: v73,
          a5: (void (__cdecl *)(IConVar *, const char *, float))cipher.m_pMemory);
        v76.m_nAllocationCount = (int)v16;
      }
    }
    sigSz = 6;
  }
  v17 = (*(int (__thiscall **)(int))(*(_DWORD *)v76.m_nAllocationCount + 8))(a1: v76.m_nAllocationCount) + sigSz;
  sigSz = v17;
  if ( (_WORD)v17 != 0 )
  {
    v19 = (__int16)v17;
    v57 = gSz + pSz + (__int16)v17 + pubSz + 8;
    *(_DWORD *)(this + 32) = v57;
    yaSSL::output_buffer::output_buffer(this: (yaSSL::output_buffer *)&v76.m_nGrowSize, a2: v57);
    yaSSL::c16toa(u16: COERCE_FLOAT((CUtlMemory<KeyValues *,int> *)&cipher.m_nGrowSize));
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)&v76.m_nGrowSize,
      src: (const unsigned __int8 *)&cipher.m_nGrowSize,
      a3: 2u);
    v58 = pSz;
    p = (const unsigned __int8 *)yaSSL::ServerDHParams::get_p(this: (ConCommandBase *)(this + 4));
    yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)&v76.m_nGrowSize, src: p, a3: v58);
    yaSSL::c16toa(u16: v21);
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)&v76.m_nGrowSize,
      src: (const unsigned __int8 *)&cipher.m_nGrowSize,
      a3: 2u);
    v59 = gSz;
    g = (const unsigned __int8 *)yaSSL::ServerDHParams::get_g(this: (ConCommandBase *)(this + 4));
    yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)&v76.m_nGrowSize, src: g, a3: v59);
    yaSSL::c16toa(u16: *(float *)&pubSz);
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)&v76.m_nGrowSize,
      src: (const unsigned __int8 *)&cipher.m_nGrowSize,
      a3: 2u);
    v60 = pubSz;
    Flags = (const unsigned __int8 *)ConCommandBase::GetFlags(this: (ConCommandBase *)(this + 4));
    yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)&v76.m_nGrowSize, src: Flags, a3: v60);
    yaSSL::MD5::MD5(this: (KeyValues **)&sha);
    yaSSL::SHA::SHA(this: (Vector2D *)&out.m_Memory.m_nAllocationCount);
    *(_DWORD *)(this + 28) = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
    v24 = (ShortVector *)yaSSL::SSL::useSecurity(this: (char *)result);
    yaSSL::sslHashes::get_MD5(
      this: v24,
      a2: (__int16)v68,
      a3: (__int16)v73,
      a4: (__int16)cipher.m_pMemory,
      a5: cipher.m_nAllocationCount);
    v26 = v25;
    v76.m_pMemory = (KeyValues **)(v25 + 52);
    TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
      this: (CLoggingSystem *)&sha,
      cipher: v25 + 52,
      plain: (Color)32);
    v26 += 84;
    TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(this: (CLoggingSystem *)&pSz, cipher: v26, plain: (Color)32);
    Method = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v76);
    yaSSL::SSL_CTX::getCert(this: &v76, a2: Method);
    TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(this: (CLoggingSystem *)&pubSz, cipher: v28, plain: v48);
    yaSSL::MD5::get_digest(this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&gSz, &out);
    TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
      this: (CLoggingSystem *)&pSz,
      cipher: (int)cipher.m_pMemory,
      plain: (Color)32);
    TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(this: (CLoggingSystem *)&pubSz, cipher: v26, plain: (Color)32);
    v29 = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&cipher);
    yaSSL::SSL_CTX::getCert(this: &cipher, a2: v29);
    TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(this: (CLoggingSystem *)&gSz, cipher: v30, plain: v37);
    yaSSL::MD5::get_digest(
      this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&sigSz,
      out: (const CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&out.m_Memory.m_nAllocationCount);
    yaSSL::SSL::useSecurity(this: (char *)result);
    m_nAllocationCount = (const char *)v69;
    if ( yaSSL::Security::use_parms(result: v38)->stmt_execute == (int (__cdecl *)(st_mysql_stmt *))1 )
    {
      v61 = *v69;
      yaSSL::sslHashes::get_MD5(this: result, a2: v39, a3: v42, a4: v45, a5: v49);
      v32 = yaSSL::States::useServer();
      (*(void (__thiscall **)(QueuedPacket_t *const *, _DWORD, int *, int, _DWORD, int, int, int, int, int, QueuedPacket_t *))&v61->m_From.sin_family)(
        a1: v69,
        a2: *(_DWORD *)(this + 28),
        a3: &pubSz,
        a4: 36,
        a5: *(_DWORD *)&v32.x,
        a6: v40,
        a7: v43,
        a8: v46,
        a9: v50,
        a10: v55,
        a11: v61);
    }
    else
    {
      v62 = *v69;
      yaSSL::sslHashes::get_MD5(this: result, a2: v39, a3: v42, a4: v45, a5: v49);
      v33 = yaSSL::States::useServer();
      (*(void (__thiscall **)(QueuedPacket_t *const *, _DWORD, int *, int, _DWORD, int, int, int, int, int, QueuedPacket_t *))&v62->m_From.sin_family)(
        a1: v69,
        a2: *(_DWORD *)(this + 28),
        a3: &out.m_Memory.m_nAllocationCount,
        a4: 20,
        a5: *(_DWORD *)&v33.x,
        a6: v41,
        a7: v44,
        a8: v47,
        a9: v51,
        a10: v55,
        a11: v62);
      TaoCrypt::EncodeDSA_Signature(signature: *(_DWORD *)(this + 28));
      qmemcpy(*(void **)(this + 28), v83, 46);
      m_nAllocationCount = (const char *)v76.m_nAllocationCount;
    }
    yaSSL::c16toa(u16: *(float *)&sigSz);
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)&v76.m_nGrowSize,
      src: (const unsigned __int8 *)&cipher.m_nGrowSize,
      a3: 2u);
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)&v76.m_nGrowSize,
      src: *(const unsigned __int8 **)(this + 28),
      a3: v19);
    *(_DWORD *)(this + 36) = operator new[](sz: (const CSplitScreenAddedConVar *)*(unsigned __int8 *)yaSSL::ys);
    v34 = (CUtlMemory<KeyValues *,int> *)yaSSL::SSL_CTX::getMethod(this: (yaSSL::SSL_CTX *)&v76.m_nGrowSize);
    yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)&v76.m_nGrowSize, a2: v34);
    memcpy(dst: *(unsigned __int8 **)(this + 36), src: v35, count: v63);
    yaSSL::SHA::~SHA(this: (Vector2D *)&out.m_Memory.m_nAllocationCount);
    yaSSL::MD5::~MD5(this: (yaSSL::MD5 *)&sha);
    yaSSL::x509::~x509(
      this: (CUtlVector<QueuedPacket_t *,CUtlMemory<QueuedPacket_t *,int> > *)&v76.m_nGrowSize,
      a2: v69);
    yaSSL::ysDelete<yaSSL::Auth>(
      ptr: v36,
      a2: m_nAllocationCount,
      a3: (int)v70,
      a4: v74,
      a5: (void (__cdecl *)(IConVar *, const char *, float))cipher.m_pMemory);
  }
  else
  {
    yaSSL::SSL::SetError(a1: result, a2: 116);
    yaSSL::ysDelete<yaSSL::Auth>(
      ptr: v18,
      a2: (const char *)v76.m_nAllocationCount,
      a3: (int)v68,
      a4: v73,
      a5: (void (__cdecl *)(IConVar *, const char *, float))cipher.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042B710
// Name: public: virtual void yaSSL::HandShakeHeader::Process(class yaSSL::input_buffer __near &,class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __userpurge yaSSL::HandShakeHeader::Process@<eax>(
        tagEXCEPINFO *this@<ecx>,
        const unsigned __int8 *a2@<ebx>,
        CUtlString *a3,
        yaSSL::SSL *a4)
{
  HRESULT result; // eax
  ShortVector v6; // rax
  int v7; // ecx
  int v8; // eax
  wchar_t *i; // edx
  CUtlString *v10; // esi
  const struct yaSSL::input_buffer *v11; // ebx
  unsigned int v12; // eax
  int v13; // [esp-8h] [ebp-10h]
  unsigned int v14; // [esp-8h] [ebp-10h]
  int v15; // [esp-8h] [ebp-10h]
  yaSSL *v16; // [esp+0h] [ebp-8h]

  yaSSL::SSL::verifyState(this: a4, a2: (const struct yaSSL::HandShakeHeader *)this);
  result = yaSSL::SSL::GetError(this: (char *)a4);
  if ( result == 0 )
  {
    yaSSL::SSL::getFactory(this: a4, a2: v16);
    v6 = yaSSL::States::useServer();
    v7 = **(_DWORD **)&v6.x;
    v8 = *(_DWORD *)(*(_DWORD *)&v6.x + 4);
    for ( i = this->bstrSource; v7 != v8; v7 += 8 )
    {
      if ( *(wchar_t **)v7 == i )
        break;
    }
    if ( v7 != v8 && (v10 = (CUtlString *)(*(int (__fastcall **)(int, wchar_t *))(v7 + 4))(a1: v7, a2: i)) != nullptr )
    {
      v11 = (const struct yaSSL::input_buffer *)yaSSL::c24to32(
                                                  u24: (const LoggingContext_t *)&this->bstrDescription,
                                                  a2);
      yaSSL::input_buffer::get_remaining(this: a3, a2: v13);
      if ( (unsigned int)v11 <= v12 )
      {
        yaSSL::hashHandShake(this: a4, a2: (struct SSL *)a3, a3: v11, a4: v14);
        yaSSL::Crypto::setCipher(this: v10, i: (const char *)v11, a3: v15);
        yaSSL::operator<<(a1: a3, msg: (tagVARDESC *)v10);
        (*((void (__thiscall **)(CUtlString *, CUtlString *, yaSSL::SSL *))v10->m_Storage.m_Memory.m_pMemory + 3))(
          a1: v10,
          a2: a3,
          a3: a4);
      }
      else
      {
        yaSSL::SSL::SetError(a1: a4, a2: 109);
      }
      return yaSSL::ysDelete<yaSSL::HandShakeBase>(a1: v10);
    }
    else
    {
      yaSSL::SSL::SetError(a1: a4, a2: 103);
      return yaSSL::ysDelete<yaSSL::HandShakeBase>(a1: 0);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B800
// Name: public: yaSSL::CertificateRequest::CertificateRequest(void)
// Source: json
//------------------------------------------------------------------------------
yaSSL::CertificateRequest *__thiscall yaSSL::CertificateRequest::CertificateRequest(yaSSL::CertificateRequest *this)
{
  *this = (yaSSL::CertificateRequest)&yaSSL::CertificateRequest::`vftable';
  *(this + 9) = nullptr;
  *(this + 10) = nullptr;
  *(this + 11) = nullptr;
  *(this + 12) = nullptr;
  *(this + 2) = nullptr;
  *(this + 3) = nullptr;
  *(this + 4) = nullptr;
  *(this + 5) = nullptr;
  *(this + 6) = nullptr;
  *(this + 7) = nullptr;
  *(this + 8) = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042B830
// Name: public: virtual class yaSSL::input_buffer __near & yaSSL::CertificateRequest::set(class yaSSL::input_buffer __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlString *__thiscall yaSSL::CertificateRequest::set(yaSSL::CertificateRequest *this, CUtlString *a2)
{
  return yaSSL::operator>>(a1: a2, a2: (int)this);
}

//------------------------------------------------------------------------------
// Address: 0x0042B850
// Name: public: virtual class yaSSL::output_buffer __near & yaSSL::CertificateRequest::get(class yaSSL::output_buffer __near &)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0042B870
// Name: public: void yaSSL::CertificateVerify::Build(class yaSSL::SSL __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertificateVerify::Build(unsigned int *this, CEmptyConVar *result)
{
  unsigned int v3; // ebx
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v4; // eax
  yaSSL::CertManager *v5; // eax
  yaSSL::CertManager *v6; // esi
  unsigned __int8 *privateKey; // eax
  unsigned __int16 v8; // si
  float v9; // ecx
  ShortVector v10; // rax
  const LoggingContext_t *v11; // eax
  const CSplitScreenAddedConVar *v12; // ecx
  CSplitScreenAddedConVar *v13; // esi
  ShortVector v14; // rax
  IConVar *privateKeyLength; // [esp-8h] [ebp-5Ch]
  IConVar *v16; // [esp-8h] [ebp-5Ch]
  __int16 v17; // [esp+0h] [ebp-54h]
  int v18; // [esp+0h] [ebp-54h]
  void **v19; // [esp+0h] [ebp-54h]
  int v20; // [esp+0h] [ebp-54h]
  void **v21; // [esp+0h] [ebp-54h]
  __int16 v22; // [esp+4h] [ebp-50h]
  __int16 v23; // [esp+4h] [ebp-50h]
  __int16 v24; // [esp+8h] [ebp-4Ch]
  __int16 v25; // [esp+8h] [ebp-4Ch]
  __int16 v26; // [esp+Ch] [ebp-48h]
  __int16 v27; // [esp+Ch] [ebp-48h]
  float u16; // [esp+10h] [ebp-44h] BYREF
  int sz; // [esp+14h] [ebp-40h]
  CThread *dss; // [esp+18h] [ebp-3Ch] BYREF
  _BYTE v31[46]; // [esp+20h] [ebp-34h]

  yaSSL::build_certHashes(result);
  v3 = 0;
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)result, a2: v17, a3: v22, a4: v24, a5: v26);
  LOBYTE(v5) = yaSSL::Crypto::get_certManager(this: v4, a2: v18);
  v6 = v5;
  if ( yaSSL::CertManager::get_keyType(a1: v5) == 1 )
  {
    privateKeyLength = (IConVar *)yaSSL::CertManager::get_privateKeyLength();
    privateKey = (unsigned __int8 *)yaSSL::CertManager::get_privateKey(this: v6);
    yaSSL::RSA::RSA(this: (CSplitScreenAddedConVar *)&dss, key: privateKey, sz: privateKeyLength, a4: false);
    v8 = (unsigned __int16)yaSSL::RSA::get_cipherLength() + 2;
    sz = (int)operator new[](sz: (const CSplitScreenAddedConVar *)v8);
    if ( sz != 0 )
    {
      yaSSL::ysArrayDelete<unsigned char>(ptr: nullptr, a2: v19);
      v3 = sz;
    }
    yaSSL::c16toa(u16: v9);
    *(_WORD *)v3 = LOWORD(u16);
    yaSSL::sslHashes::get_MD5(this: (ShortVector *)result, a2: (__int16)v19, a3: v23, a4: v25, a5: v27);
    v10 = yaSSL::States::useServer();
    yaSSL::RSA::sign(
      this: (CThreadMutex *)&dss,
      sig: (const CThreadMutex *)(v3 + 2),
      message: (const LoggingContext_t *)(this + 2),
      sz: 0x24u,
      random: *(struct TaoCrypt::RandomNumberGenerator ***)&v10.x);
    yaSSL::RSA::~RSA(this: (int *)&dss);
  }
  else
  {
    v16 = (IConVar *)yaSSL::CertManager::get_privateKeyLength();
    v11 = (const LoggingContext_t *)yaSSL::CertManager::get_privateKey(this: v6);
    yaSSL::DSS::DSS(this: (CSplitScreenAddedConVar *)&dss, result: v11, sz: v16, publicKey: false);
    sz = 48;
    v13 = operator new[](sz: v12);
    if ( v13 != nullptr )
    {
      yaSSL::ysArrayDelete<unsigned char>(ptr: nullptr, a2: v19);
      v3 = (unsigned int)v13;
    }
    yaSSL::c16toa(u16: COERCE_FLOAT(&u16));
    *(_WORD *)v3 = LOWORD(u16);
    yaSSL::sslHashes::get_MD5(this: (ShortVector *)result, a2: (__int16)v19, a3: v23, a4: v25, a5: v27);
    v14 = yaSSL::States::useServer();
    yaSSL::DSS::sign(
      this: (CThread *)&dss,
      sig: (unsigned __int8 *)(v3 + 2),
      sha_digest: (const LoggingContext_t *)(this + 6),
      __formal: 0x14u,
      random: *(int *)&v14.x);
    TaoCrypt::EncodeDSA_Signature(signature: v3 + 2);
    qmemcpy((void *)(v3 + 2), v31, 46);
    yaSSL::DSS::~DSS(this: (CThread *)&dss);
    v8 = sz;
  }
  yaSSL::Crypto::setCipher((CUtlString *)this, i: (const char *)v8, a3: v20);
  *(this + 11) = v3;
  yaSSL::ysArrayDelete<unsigned char>(ptr: nullptr, a2: v21);
}

//------------------------------------------------------------------------------
// Address: 0x0042BA30
// Name: class yaSSL::HandShakeBase __near * yaSSL::CreateCertificateRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CreateCertificateRequest(const CSplitScreenAddedConVar *this)
{
  yaSSL::CertificateRequest *v1; // eax

  v1 = (yaSSL::CertificateRequest *)operator new(sz: this);
  if ( v1 != nullptr )
    yaSSL::CertificateRequest::CertificateRequest(this: v1);
}

//------------------------------------------------------------------------------
// Address: 0x0042BB10
// Name: public: virtual yaSSL::CertificateRequest::~CertificateRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall yaSSL::CertificateRequest::~CertificateRequest(yaSSL::CertificateRequest *this)
{
  int v2; // ecx
  int v3; // [esp+0h] [ebp-Ch]
  bool (__cdecl *op)(const sockaddr_in *, const sockaddr_in *); // [esp+8h] [ebp-4h]

  v2 = (int)*(this + 10);
  LOBYTE(op) = 0;
  *this = (yaSSL::CertificateRequest)&yaSSL::CertificateRequest::`vftable';
  mySTL::for_each<mySTL::list<unsigned char *>::iterator,yaSSL::del_ptr_zero>(a1: v2, a2: 0, op);
  mySTL::list<TaoCrypt::Signer *>::~list<TaoCrypt::Signer *>(this: (Vector *)(this + 10), a2: v3);
  *this = (yaSSL::CertificateRequest)&yaSSL::HandShakeBase::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0042BB60
// Name: void yaSSL::InitMessageFactory(class yaSSL::Factory<struct yaSSL::Message,int,struct yaSSL::Message __near * (*)(void)> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl yaSSL::InitMessageFactory(int mf)
{
  const CUtlMemory<CUtlString,int>::Iterator_t *v1; // ecx
  int v2; // eax
  int v4; // [esp-10h] [ebp-1Ch]

  if ( (unsigned int)((*(_DWORD *)(mf + 8) - *(_DWORD *)mf) >> 3) < 4 )
  {
    v4 = mySTL::GetArrayMemory<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)>>(items: v1);
    mySTL::uninit_copy<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *,mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *>(
      first: *(const CUtlString **)(mf + 4),
      last: *(_DWORD *)mf);
    *(_DWORD *)mf = v4;
    *(_DWORD *)(mf + 4) = v2;
    *(_DWORD *)(mf + 8) = v4 + 32;
    mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>();
  }
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  return mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
}

//------------------------------------------------------------------------------
// Address: 0x0042BC20
// Name: void yaSSL::InitHandShakeFactory(class yaSSL::Factory<class yaSSL::HandShakeBase,int,class yaSSL::HandShakeBase __near * (*)(void)> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl yaSSL::InitHandShakeFactory(int a1)
{
  const CUtlMemory<CUtlString,int>::Iterator_t *v1; // ecx
  int v2; // eax
  int v4; // [esp-10h] [ebp-1Ch]

  if ( (unsigned int)((*(_DWORD *)(a1 + 8) - *(_DWORD *)a1) >> 3) < 0xA )
  {
    v4 = mySTL::GetArrayMemory<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)>>(items: v1);
    mySTL::uninit_copy<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *,mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *>(
      first: *(const CUtlString **)(a1 + 4),
      last: *(_DWORD *)a1);
    *(_DWORD *)a1 = v4;
    *(_DWORD *)(a1 + 4) = v2;
    *(_DWORD *)(a1 + 8) = v4 + 80;
    mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>();
  }
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  return mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
}

//------------------------------------------------------------------------------
// Address: 0x0042BD90
// Name: void yaSSL::InitServerKeyFactory(class yaSSL::Factory<struct yaSSL::ServerKeyBase,int,struct yaSSL::ServerKeyBase __near * (*)(void)> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl yaSSL::InitServerKeyFactory(int a1)
{
  const CUtlMemory<CUtlString,int>::Iterator_t *v1; // ecx
  int v2; // eax
  int v4; // [esp-10h] [ebp-1Ch]

  if ( (unsigned int)((*(_DWORD *)(a1 + 8) - *(_DWORD *)a1) >> 3) < 3 )
  {
    v4 = mySTL::GetArrayMemory<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)>>(items: v1);
    mySTL::uninit_copy<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *,mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *>(
      first: *(const CUtlString **)(a1 + 4),
      last: *(_DWORD *)a1);
    *(_DWORD *)a1 = v4;
    *(_DWORD *)(a1 + 4) = v2;
    *(_DWORD *)(a1 + 8) = v4 + 24;
    mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>();
  }
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  return mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
}

//------------------------------------------------------------------------------
// Address: 0x0042BE30
// Name: void yaSSL::InitClientKeyFactory(class yaSSL::Factory<struct yaSSL::ClientKeyBase,int,struct yaSSL::ClientKeyBase __near * (*)(void)> __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl yaSSL::InitClientKeyFactory(int a1)
{
  const CUtlMemory<CUtlString,int>::Iterator_t *v1; // ecx
  int v2; // eax
  int v4; // [esp-10h] [ebp-1Ch]

  if ( (unsigned int)((*(_DWORD *)(a1 + 8) - *(_DWORD *)a1) >> 3) < 3 )
  {
    v4 = mySTL::GetArrayMemory<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)>>(items: v1);
    mySTL::uninit_copy<mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *,mySTL::pair<int,yaSSL::Message * (__cdecl *)(void)> *>(
      first: *(const CUtlString **)(a1 + 4),
      last: *(_DWORD *)a1);
    *(_DWORD *)a1 = v4;
    *(_DWORD *)(a1 + 4) = v2;
    *(_DWORD *)(a1 + 8) = v4 + 24;
    mySTL::FreeArrayMemory<mySTL::pair<int,yaSSL::ClientKeyBase * (__cdecl *)(void)>>();
  }
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
  return mySTL::vector<mySTL::pair<int,yaSSL::HandShakeBase * (__cdecl *)(void)>>::push_back();
}

//------------------------------------------------------------------------------
// Address: 0x00433730
// Name: public: virtual unsigned short yaSSL::Alert::get_length(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl yaSSL::Alert::get_length()
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x0045A0D0
// Name: public: unsigned char const __near * yaSSL::ServerDHParams::get_p(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall yaSSL::ServerDHParams::get_p(ConCommandBase *this)
{
  return this->m_pszName;
}

//------------------------------------------------------------------------------
// Address: 0x0045A130
// Name: public: unsigned char const __near * yaSSL::ServerDHParams::get_g(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall yaSSL::ServerDHParams::get_g(ConCommandBase *this)
{
  return this->m_pszHelpString;
}

//------------------------------------------------------------------------------
// Address: 0x004280A0
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,struct yaSSL::RecordLayerHeader const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
QueuedPacket_t **__cdecl yaSSL::operator<<(QueuedPacket_t **a1, _BYTE *a2)
{
  _BYTE *v2; // eax
  float v3; // ecx

  *(_BYTE *)yaSSL::output_buffer::operator[](this: a1, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *a2;
  *(_BYTE *)yaSSL::output_buffer::operator[](this: a1, i: (QueuedPacket_t *const *)0xFEEDBEEF) = a2[4];
  v2 = (_BYTE *)yaSSL::output_buffer::operator[](this: a1, i: (QueuedPacket_t *const *)0xFEEDBEEF);
  LODWORD(v3) = (unsigned __int8)a2[5];
  *v2 = LOBYTE(v3);
  yaSSL::c16toa(u16: v3);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: a1, i: (QueuedPacket_t *const *)0xFEEDBEEF) = (_BYTE)a1;
  *(_BYTE *)yaSSL::output_buffer::operator[](this: a1, i: (QueuedPacket_t *const *)0xFEEDBEEF) = BYTE1(a1);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00428190
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::HandShakeHeader const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
QueuedPacket_t **__cdecl yaSSL::operator<<(QueuedPacket_t **a1, int hdr)
{
  *(_BYTE *)yaSSL::output_buffer::operator[](this: a1, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(hdr + 4);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)a1, src: (const unsigned __int8 *)(hdr + 8), a3: 3u);
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00428260
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::ChangeCipherSpec const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__stdcall yaSSL::operator<<(const char *output, int a2)
{
  *(_BYTE *)yaSSL::output_buffer::operator[](
              this: (QueuedPacket_t *const *)output,
              i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(a2 + 4);
  return output;
}

//------------------------------------------------------------------------------
// Address: 0x004283C0
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::Alert const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HWND__ *__stdcall yaSSL::operator<<(HWND__ *output, wchar_t **a)
{
  *(_BYTE *)yaSSL::output_buffer::operator[](
              this: (QueuedPacket_t *const *)output,
              i: (QueuedPacket_t *const *)0xFEEDBEEF) = *((_BYTE *)a + 4);
  *(_BYTE *)yaSSL::output_buffer::operator[](
              this: (QueuedPacket_t *const *)output,
              i: (QueuedPacket_t *const *)0xFEEDBEEF) = *((_BYTE *)a + 8);
  return output;
}

//------------------------------------------------------------------------------
// Address: 0x00428670
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::Data const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
yaSSL::output_buffer *__cdecl yaSSL::operator<<(yaSSL::output_buffer *a1, int a2)
{
  yaSSL::output_buffer::write(this: a1, src: *(const unsigned __int8 **)(a2 + 12), a3: *(unsigned __int16 *)(a2 + 4));
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x00428970
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,struct yaSSL::Message const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl yaSSL::operator<<(int a1, tagVARDESC *msg)
{
  return (*(int (__thiscall **)(tagVARDESC *, int))(msg->memid + 4))(a1: msg, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x00428990
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::HandShakeBase const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl yaSSL::operator<<(int a1, _GUID hs)
{
  return (*(int (__thiscall **)(unsigned int, int))(*(_DWORD *)hs.Data1 + 8))(a1: hs.Data1, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x004289C0
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::Certificate const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
HINSTANCE__ *__stdcall yaSSL::operator<<(HINSTANCE__ *output, char *cert)
{
  int v2; // eax
  yaSSL *v3; // esi
  const unsigned __int8 *v4; // eax
  unsigned int v6; // [esp-4h] [ebp-14h]
  CUtlMemory<KeyValues *,int> *v7; // [esp+0h] [ebp-10h]
  unsigned __int8 (*v8)[3]; // [esp+0h] [ebp-10h]
  unsigned __int8 (*v9)[3]; // [esp+0h] [ebp-10h]
  unsigned __int8 src[4]; // [esp+Ch] [ebp-4h] BYREF

  yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)cert, a2: v7);
  v3 = (yaSSL *)(v2 - 6);
  yaSSL::c32to24(this: (yaSSL *)(v2 - 6 + 3), a2: (unsigned int)src, a3: v8);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)output, src, a3: 3u);
  yaSSL::c32to24(this: v3, a2: (unsigned int)src, a3: v9);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)output, src, a3: 3u);
  yaSSL::Certificate::get_buffer(this: (CUtlMemory<KeyValues *,int> **)cert, a2: (CUtlMemory<KeyValues *,int> *)v3);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)output, src: v4, a3: v6);
  return output;
}

//------------------------------------------------------------------------------
// Address: 0x00428D30
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::ServerHello const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
QueuedPacket_t **__cdecl yaSSL::operator<<(QueuedPacket_t **result, int a2)
{
  *(_BYTE *)yaSSL::output_buffer::operator[](this: result, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(a2 + 8);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: result, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(a2 + 9);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)result, src: (const unsigned __int8 *)(a2 + 10), a3: 0x20u);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: result, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(a2 + 42);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)result, src: (const unsigned __int8 *)(a2 + 43), a3: 0x20u);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: result, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(a2 + 75);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: result, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(a2 + 76);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: result, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(a2 + 80);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00429020
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::ClientHello const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
QueuedPacket_t **__cdecl yaSSL::operator<<(QueuedPacket_t **a1, int a2)
{
  QueuedPacket_t **v2; // esi
  _BYTE *v3; // eax
  int v4; // edi
  _BYTE *v5; // eax
  _BYTE *v6; // eax

  v2 = a1;
  v3 = (_BYTE *)yaSSL::output_buffer::operator[](this: a1, i: (QueuedPacket_t *const *)0xFEEDBEEF);
  v4 = a2;
  *v3 = *(_BYTE *)(a2 + 8);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: v2, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(v4 + 9);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)v2, src: (const unsigned __int8 *)(v4 + 10), a3: 0x20u);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: v2, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(v4 + 42);
  if ( *(_BYTE *)(v4 + 42) != 0 )
    yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)v2, src: (const unsigned __int8 *)(v4 + 43), a3: 0x20u);
  yaSSL::c16toa(u16: COERCE_FLOAT(*(_WORD *)(v4 + 76)));
  v5 = (_BYTE *)yaSSL::output_buffer::operator[](this: v2, i: (QueuedPacket_t *const *)0xFEEDBEEF);
  *v5 = (_BYTE)a1;
  v6 = (_BYTE *)yaSSL::output_buffer::operator[](this: v2, i: (QueuedPacket_t *const *)0xFEEDBEEF);
  *v6 = BYTE1(a1);
  yaSSL::output_buffer::write(
    this: (yaSSL::output_buffer *)v2,
    src: (const unsigned __int8 *)(v4 + 78),
    a3: *(unsigned __int16 *)(v4 + 76));
  *(_BYTE *)yaSSL::output_buffer::operator[](this: v2, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(v4 + 206);
  *(_BYTE *)yaSSL::output_buffer::operator[](this: v2, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(v4 + 208);
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x004292E0
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::CertificateVerify const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const CDefaultAccessor *__cdecl yaSSL::operator<<(CDefaultAccessor *result, CUtlMemory<KeyValues *,int> *a2)
{
  int v2; // ecx
  unsigned int v3; // eax
  CUtlMemory<KeyValues *,int> *v5; // [esp+0h] [ebp-4h]

  yaSSL::SSL_CTX::getCert(this: a2, a2: v5);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)result, src: *(const unsigned __int8 **)(v2 + 44), a3: v3);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004294A0
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::Finished const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *__cdecl yaSSL::operator<<(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *result,
        CUtlMemory<KeyValues *,int> *a2)
{
  int v2; // eax
  CUtlMemory<KeyValues *,int> *v4; // [esp+0h] [ebp-4h]

  yaSSL::SSL_CTX::getCert(this: a2, a2: v4);
  if ( v2 == 36 )
  {
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)result,
      src: (const unsigned __int8 *)&a2->m_nGrowSize,
      a3: 0x10u);
    yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)result, src: (const unsigned __int8 *)&a2[2], a3: 0x14u);
  }
  else
  {
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)result,
      src: (const unsigned __int8 *)&a2->m_nGrowSize,
      a3: 0xCu);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042AC00
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::ClientKeyExchange const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
CUtlVectorAutoPurge<char *> *__usercall yaSSL::operator<<@<eax>(
        const CUtlVectorAutoPurge<char *> *a1@<esi>,
        CUtlVectorAutoPurge<char *> *result)
{
  unsigned int v2; // eax
  const unsigned __int8 *Key; // eax
  unsigned int v5; // [esp-8h] [ebp-8h]

  yaSSL::ClientKeyExchange::getKeyLength(this: result, a2: a1);
  v5 = v2;
  Key = (const unsigned __int8 *)yaSSL::ServerKeyExchange::getKey(this: (yaSSL::ServerKeyExchange *)result);
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)result, src: Key, a3: v5);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042B0D0
// Name: class yaSSL::output_buffer __near & yaSSL::operator<<(class yaSSL::output_buffer __near &,class yaSSL::CertificateRequest const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
QueuedPacket_t **__cdecl yaSSL::operator<<(IntVector4D c)
{
  QueuedPacket_t **x; // ebx
  int y; // esi
  int v3; // edi
  _BYTE *v4; // ebp
  int i; // esi

  x = (QueuedPacket_t **)c.x;
  y = c.y;
  v3 = 0;
  *(_BYTE *)yaSSL::output_buffer::operator[](this: (QueuedPacket_t *const *)c.x, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *(_BYTE *)(y + 36);
  if ( *(int *)(y + 36) > 0 )
  {
    v4 = (_BYTE *)(y + 8);
    do
    {
      ++v3;
      *(_BYTE *)yaSSL::output_buffer::operator[](this: x, i: (QueuedPacket_t *const *)0xFEEDBEEF) = *v4;
      v4 += 4;
    }
    while ( v3 < *(_DWORD *)(y + 36) );
  }
  yaSSL::SSL_CTX::getCert(this: (CUtlMemory<KeyValues *,int> *)y, a2: (CUtlMemory<KeyValues *,int> *)&c.y);
  yaSSL::c16toa(u16: COERCE_FLOAT((unsigned __int16)(-3 - *(_WORD *)(y + 36))));
  yaSSL::output_buffer::write(this: (yaSSL::output_buffer *)x, src: (const unsigned __int8 *)&c.y, a3: 2u);
  for ( i = *(_DWORD *)(y + 40); i != 0; i = *(_DWORD *)(i + 4) )
  {
    yaSSL::ato16(&c);
    yaSSL::output_buffer::write(
      this: (yaSSL::output_buffer *)x,
      src: *(const unsigned __int8 **)(i + 8),
      a3: LOWORD(c.x) + 2);
  }
  return x;
}
