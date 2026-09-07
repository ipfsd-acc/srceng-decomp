// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/asn.cpp
// Functions: 51
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\asn.h"

//------------------------------------------------------------------------------
// Address: 0x0044C410
// Name: unsigned int TaoCrypt::SetLength(unsigned int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::SetLength(
        const CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Iterator_t *length,
        unsigned int lengtha,
        unsigned __int8 *output)
{
  int v4; // esi
  unsigned int v5; // eax
  int v6; // edi
  unsigned int v7; // edx

  if ( lengtha >= 0x80 )
  {
    *output = TaoCrypt::BytePrecision(this: (TaoCrypt *)lengtha) | 0x80;
    v4 = 1;
    v5 = TaoCrypt::BytePrecision(this: (TaoCrypt *)lengtha);
    if ( v5 != 0 )
    {
      v6 = 8 * v5 - 8;
      do
      {
        v7 = lengtha >> v6;
        --v5;
        ++v4;
        v6 -= 8;
        output[v4 - 1] = v7;
      }
      while ( v5 != 0 );
    }
    return v4;
  }
  else
  {
    *output = lengtha;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C470
// Name: public: void TaoCrypt::PublicKey::SetSize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__userpurge TaoCrypt::PublicKey::SetSize@<eax>(
        CSplitScreenAddedConVar **a1@<ecx>,
        IRecordInfo *this,
        unsigned int s,
        void *a4,
        const wchar_t *a5,
        tagVARIANT *a6)
{
  CSplitScreenAddedConVar *result; // eax

  a1[1] = (CSplitScreenAddedConVar *)this;
  result = operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc, sza: (const CSplitScreenAddedConVar *)this);
  *a1 = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C4A0
// Name: public: void TaoCrypt::PublicKey::SetKey(unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::PublicKey::SetKey(TaoCrypt::PublicKey *this, unsigned __int8 *src)
{
  memcpy(dst: *(unsigned __int8 **)this, src, count: *((_DWORD *)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x0044C4C0
// Name: public: struct TaoCrypt::Error TaoCrypt::BER_Decoder::GetError(void)
// Source: json
//------------------------------------------------------------------------------
struct Error __thiscall TaoCrypt::BER_Decoder::GetError(TaoCrypt::BER_Decoder *this, _DWORD *a2)
{
  *a2 = *(_DWORD *)(*((_DWORD *)this + 1) + 16);
  return (struct Error)a2;
}

//------------------------------------------------------------------------------
// Address: 0x0044C4D0
// Name: public: class TaoCrypt::Integer __near & TaoCrypt::BER_Decoder::GetInteger(class TaoCrypt::Integer __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0044C500
// Name: private: unsigned int TaoCrypt::Signature_Encoder::SetDigest(unsigned char const __near *,unsigned int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::Signature_Encoder::SetDigest(
        TaoCrypt::Signature_Encoder *this,
        const LoggingContext_t *d,
        unsigned int dSz,
        unsigned __int8 *output)
{
  *output = 4;
  output[1] = dSz;
  memcpy(dst: output + 2, src: (unsigned __int8 *)d, count: dSz);
  return dSz + 2;
}

//------------------------------------------------------------------------------
// Address: 0x0044C530
// Name: unsigned int TaoCrypt::SetSequence(unsigned int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::SetSequence(
        const CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Iterator_t *len,
        unsigned int lena,
        unsigned __int8 *output)
{
  *output = 48;
  return TaoCrypt::SetLength(length: len, lengtha: lena, output: output + 1) + 1;
}

//------------------------------------------------------------------------------
// Address: 0x0044C550
// Name: unsigned int TaoCrypt::EncodeDSA_Signature(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TaoCrypt::EncodeDSA_Signature(
        struct TaoCrypt::Integer *this,
        struct TaoCrypt::Integer *a2,
        struct TaoCrypt::Integer *output)
{
  unsigned int v3; // edi
  unsigned int v4; // ebp
  const CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Iterator_t *v5; // ecx
  unsigned int v6; // esi
  unsigned int v7; // ebx
  int seqSz; // [esp+14h] [ebp-28h]
  CCountedStringPoolBase<unsigned int>::<unnamed_tag> seqArray[2]; // [esp+20h] [ebp-1Ch] BYREF
  unsigned __int8 src; // [esp+28h] [ebp-14h] BYREF
  unsigned __int8 v12[7]; // [esp+29h] [ebp-13h] BYREF
  unsigned __int8 v13; // [esp+30h] [ebp-Ch] BYREF
  unsigned __int8 v14[7]; // [esp+31h] [ebp-Bh] BYREF

  v3 = TaoCrypt::Integer::ByteCount(this: &this->m_stackLevel);
  v4 = TaoCrypt::Integer::ByteCount(this: &a2->m_stackLevel);
  src = 2;
  v13 = 2;
  v6 = TaoCrypt::SetLength(
         length: (const CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Iterator_t *)v12,
         lengtha: v3,
         output: v12)
     + 1;
  v7 = TaoCrypt::SetLength(length: v5, lengtha: v4, output: v14) + 1;
  seqSz = TaoCrypt::SetSequence(
            len: (const CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Iterator_t *)(v3 + v4 + v7 + v6),
            lena: v3 + v4 + v7 + v6,
            output: (unsigned __int8 *)seqArray);
  memcpy(dst: (unsigned __int8 *)output, src: (unsigned __int8 *)seqArray, count: seqSz);
  memcpy(dst: (unsigned __int8 *)output + seqSz, &src, count: v6);
  seqArray[0] = (CCountedStringPoolBase<unsigned int>::<unnamed_tag>)((char *)output + seqSz + v6);
  TaoCrypt::Integer::Encode(a1: this, a2: v4, a3: (_BYTE *)seqArray[0], a4: v3, a5: 0);
  memcpy(dst: (unsigned __int8 *)(v3 + seqArray[0]), src: &v13, count: v7);
  TaoCrypt::Integer::Encode(a1: a2, a2: v4, a3: (_BYTE *)output + seqSz + v7 + v6 + v3, a4: v4, a5: 0);
  return v3 + v4 + v6 + v7 + seqSz;
}

//------------------------------------------------------------------------------
// Address: 0x0044C660
// Name: void TaoCrypt::tcDelete<class TaoCrypt::HASH>(class TaoCrypt::HASH __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::tcDelete<TaoCrypt::HASH>(KeyValues *ptr, void (__thiscall ***a2)(void *, _DWORD))
{
  if ( a2 != nullptr )
    (**a2)(a1: a2, a2: 0);
  operator delete(ptr, ptra: a2);
}

//------------------------------------------------------------------------------
// Address: 0x0044C690
// Name: unsigned int TaoCrypt::GetLength(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TaoCrypt::GetLength(TaoCrypt *this)
{
  int v1; // ebp
  int v2; // edi
  int v3; // ecx
  unsigned __int8 v4; // dl
  unsigned int result; // eax
  int i; // edx
  int v7; // edi

  v1 = *((_DWORD *)this + 1);
  v2 = *((_DWORD *)this + 3);
  v3 = v2 + 1;
  *((_DWORD *)this + 3) = v2 + 1;
  v4 = *(_BYTE *)(v2 + v1);
  result = 0;
  if ( v4 < 0x80u )
    return v4;
  for ( i = v4 & 0x7F; i != 0; result = *(unsigned __int8 *)(v7 + v1) | (result << 8) )
  {
    v7 = v3++;
    *((_DWORD *)this + 3) = v3;
    --i;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044C6E0
// Name: public: TaoCrypt::PublicKey::PublicKey(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0044C710
// Name: public: TaoCrypt::Signer::Signer(unsigned char const __near *,unsigned int,char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Signer *__thiscall TaoCrypt::Signer::Signer(TaoCrypt::Signer *this, IRecordInfo *k, unsigned int *kSz, char *n, const LoggingContext_t *h)
{
  unsigned int v6; // edi

  TaoCrypt::PublicKey::PublicKey(this: k, k: kSz);
  v6 = strlen(n);
  memcpy(dst: (unsigned __int8 *)this + 8, src: (unsigned __int8 *)n, count: v6);
  *((_BYTE *)this + v6 + 8) = 0;
  *((_DWORD *)this + 130) = h->m_ChannelID;
  *((_DWORD *)this + 131) = h->m_Flags;
  *((_DWORD *)this + 132) = h->m_Severity;
  *((_DWORD *)this + 133) = h->m_Color;
  *((_DWORD *)this + 134) = h[1].m_ChannelID;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044C790
// Name: public: TaoCrypt::Signer::~Signer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Signer::~Signer(TaoCrypt::Signer *this)
{
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: *(unsigned __int8 **)this);
}

//------------------------------------------------------------------------------
// Address: 0x0044C7A0
// Name: public: unsigned int TaoCrypt::BER_Decoder::GetSequence(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::BER_Decoder::GetSequence(TaoCrypt::BER_Decoder *this)
{
  _DWORD *v1; // eax
  int v2; // edx

  v1 = *((_DWORD **)this + 1);
  if ( v1[4] != 0 )
    return 0;
  v2 = v1[3];
  v1[3] = v2 + 1;
  if ( *(_BYTE *)(v2 + v1[1]) != 48 )
  {
    *(_DWORD *)(*((_DWORD *)this + 1) + 16) = 1020;
    return 0;
  }
  return TaoCrypt::GetLength(this: *((TaoCrypt **)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x0044C7E0
// Name: public: unsigned int TaoCrypt::BER_Decoder::GetSet(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::BER_Decoder::GetSet(TaoCrypt::BER_Decoder *this)
{
  _DWORD *v1; // eax
  int v2; // edx

  v1 = *((_DWORD **)this + 1);
  if ( v1[4] != 0 )
    return 0;
  v2 = v1[3];
  v1[3] = v2 + 1;
  if ( *(_BYTE *)(v2 + v1[1]) != 49 )
  {
    *(_DWORD *)(*((_DWORD *)this + 1) + 16) = 1021;
    return 0;
  }
  return TaoCrypt::GetLength(this: *((TaoCrypt **)this + 1));
}

//------------------------------------------------------------------------------
// Address: 0x0044C820
// Name: public: unsigned int TaoCrypt::BER_Decoder::GetVersion(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::BER_Decoder::GetVersion(TaoCrypt::BER_Decoder *this)
{
  _DWORD *v1; // eax
  int v3; // edx
  int v4; // eax
  int v5; // edx
  _DWORD *v6; // ecx
  int v7; // eax

  v1 = *((_DWORD **)this + 1);
  if ( v1[4] != 0 )
    return 0;
  v3 = v1[3];
  v1[3] = v3 + 1;
  if ( *(_BYTE *)(v3 + v1[1]) == 2 )
  {
    v4 = *((_DWORD *)this + 1);
    v5 = *(_DWORD *)(v4 + 12);
    *(_DWORD *)(v4 + 12) = v5 + 1;
    v6 = *((_DWORD **)this + 1);
    if ( *(_BYTE *)(v5 + *(_DWORD *)(v4 + 4)) == 1 )
    {
      v7 = v6[3];
      v6[3] = v7 + 1;
      return *(unsigned __int8 *)(v6[1] + v7);
    }
    else
    {
      v6[4] = 1022;
      return 0;
    }
  }
  else
  {
    *(_DWORD *)(*((_DWORD *)this + 1) + 16) = 1010;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044C890
// Name: public: unsigned int TaoCrypt::BER_Decoder::GetExplicitVersion(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::BER_Decoder::GetExplicitVersion(TaoCrypt::BER_Decoder *this)
{
  _DWORD *v1; // eax
  int v2; // edx

  v1 = *((_DWORD **)this + 1);
  if ( v1[4] == 0 )
  {
    v2 = v1[3];
    v1[3] = v2 + 1;
    if ( *(_BYTE *)(v2 + v1[1]) == 0xA0 )
    {
      ++*(_DWORD *)(*((_DWORD *)this + 1) + 12);
      return TaoCrypt::BER_Decoder::GetVersion(this);
    }
    --*(_DWORD *)(*((_DWORD *)this + 1) + 12);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044C8D0
// Name: public: void TaoCrypt::RSA_Private_Decoder::Decode(class TaoCrypt::RSA_PrivateKey __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::RSA_Private_Decoder::Decode(
        TaoCrypt::RSA_Private_Decoder *this@<ecx>,
        const char *a2@<edi>,
        CInternalFileSystemPassThru<IFileSystem> *a3)
{
  struct TaoCrypt::Integer *v4; // eax
  char *Integer; // eax
  struct TaoCrypt::Integer *v6; // eax
  char *v7; // eax
  struct TaoCrypt::Integer *v8; // eax
  char *v9; // eax
  struct TaoCrypt::Integer *v10; // eax
  char *v11; // eax
  struct TaoCrypt::Integer *v12; // eax
  char *v13; // eax
  struct TaoCrypt::Integer *v14; // eax
  char *v15; // eax
  struct TaoCrypt::Integer *v16; // eax
  char *v17; // eax
  struct TaoCrypt::Integer *v18; // eax
  char *v19; // eax
  const char *v20; // [esp-4h] [ebp-18h]
  const char *v21; // [esp-4h] [ebp-18h]
  const char *v22; // [esp-4h] [ebp-18h]
  const char *v23; // [esp-4h] [ebp-18h]
  const char *v24; // [esp-4h] [ebp-18h]
  const char *v25; // [esp-4h] [ebp-18h]
  const char *v26; // [esp-4h] [ebp-18h]
  TaoCrypt::Integer v27; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v28; // [esp+8h] [ebp-Ch]
  __int64 v29; // [esp+Ch] [ebp-8h] BYREF

  (*(void (__thiscall **)(TaoCrypt::RSA_Private_Decoder *))(*(_DWORD *)this + 4))(a1: this);
  if ( *(_DWORD *)(*((_DWORD *)this + 1) + 16) == 0 )
  {
    v4 = TaoCrypt::Integer::Integer(this: &v27);
    Integer = (char *)TaoCrypt::BER_Decoder::GetInteger(this, a2: v4);
    TaoCrypt::Integer::operator=(this: a3, t: Integer, a3: a2);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v29,
      p: v28,
      n: v27.m_stackLevel);
    v6 = TaoCrypt::Integer::Integer(this: &v27);
    v7 = (char *)TaoCrypt::BER_Decoder::GetInteger(this, a2: v6);
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)a3 + 16), t: v7, a3: v20);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v29,
      p: v28,
      n: v27.m_stackLevel);
    v8 = TaoCrypt::Integer::Integer(this: &v27);
    v9 = (char *)TaoCrypt::BER_Decoder::GetInteger(this, a2: v8);
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)a3 + 32), t: v9, a3: v21);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v29,
      p: v28,
      n: v27.m_stackLevel);
    v10 = TaoCrypt::Integer::Integer(this: &v27);
    v11 = (char *)TaoCrypt::BER_Decoder::GetInteger(this, a2: v10);
    TaoCrypt::Integer::operator=(this: a3 + 4, t: v11, a3: v22);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v29,
      p: v28,
      n: v27.m_stackLevel);
    v12 = TaoCrypt::Integer::Integer(this: &v27);
    v13 = (char *)TaoCrypt::BER_Decoder::GetInteger(this, a2: v12);
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)a3 + 64), t: v13, a3: v23);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v29,
      p: v28,
      n: v27.m_stackLevel);
    v14 = TaoCrypt::Integer::Integer(this: &v27);
    v15 = (char *)TaoCrypt::BER_Decoder::GetInteger(this, a2: v14);
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)a3 + 80), t: v15, a3: v24);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v29,
      p: v28,
      n: v27.m_stackLevel);
    v16 = TaoCrypt::Integer::Integer(this: &v27);
    v17 = (char *)TaoCrypt::BER_Decoder::GetInteger(this, a2: v16);
    TaoCrypt::Integer::operator=(this: a3 + 8, t: v17, a3: v25);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v29,
      p: v28,
      n: v27.m_stackLevel);
    v18 = TaoCrypt::Integer::Integer(this: &v27);
    v19 = (char *)TaoCrypt::BER_Decoder::GetInteger(this, a2: v18);
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)a3 + 112), t: v19, a3: v26);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v29,
      p: v28,
      n: v27.m_stackLevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CA60
// Name: private: virtual void TaoCrypt::RSA_Private_Decoder::ReadHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::RSA_Private_Decoder::ReadHeader(TaoCrypt::BER_Decoder *this, ITypeLib *result)
{
  TaoCrypt::BER_Decoder::GetSequence(this);
  JUMPOUT(0x44C820);
}

//------------------------------------------------------------------------------
// Address: 0x0044CA70
// Name: public: void TaoCrypt::DSA_Private_Decoder::Decode(class TaoCrypt::DSA_PrivateKey __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DSA_Private_Decoder::Decode(
        TaoCrypt::DSA_Private_Decoder *this@<ecx>,
        const char *a2@<edi>,
        CInternalFileSystemPassThru<IFileSystem> *a3)
{
  struct TaoCrypt::Integer *v4; // eax
  char *Integer; // eax
  struct TaoCrypt::Integer *v6; // eax
  struct TaoCrypt::Integer *v7; // eax
  struct TaoCrypt::Integer *v8; // eax
  struct TaoCrypt::Integer *v9; // eax
  struct TaoCrypt::Integer *v10; // eax
  struct TaoCrypt::Integer *v11; // eax
  struct TaoCrypt::Integer *v12; // eax
  CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *v13; // eax
  const char *v14; // [esp-4h] [ebp-18h]
  const char *v15; // [esp-4h] [ebp-18h]
  const char *v16; // [esp-4h] [ebp-18h]
  const char *v17; // [esp-4h] [ebp-18h]
  TaoCrypt::Integer v18; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v19; // [esp+8h] [ebp-Ch]
  __int64 v20; // [esp+Ch] [ebp-8h] BYREF

  (*(void (__thiscall **)(unsigned int *))((*this)[0] + 4))(a1: (unsigned int *)this);
  if ( *(_DWORD *)((*this)[1] + 16) == 0 )
  {
    v4 = TaoCrypt::Integer::Integer(this: &v18);
    Integer = (char *)TaoCrypt::BER_Decoder::GetInteger((TaoCrypt::BER_Decoder *)this, a2: v4);
    TaoCrypt::DSA_PublicKey::SetModulus(this: a3, t: Integer, a3: a2);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v20,
      p: v19,
      n: v18.m_stackLevel);
    v6 = TaoCrypt::Integer::Integer(this: &v18);
    v7 = TaoCrypt::BER_Decoder::GetInteger((TaoCrypt::BER_Decoder *)this, a2: v6);
    TaoCrypt::DSA_PublicKey::SetSubGroupOrder(this: (TaoCrypt::DSA_PublicKey *)a3, a2: v7, a3: v14);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v20,
      p: v19,
      n: v18.m_stackLevel);
    v8 = TaoCrypt::Integer::Integer(this: &v18);
    v9 = TaoCrypt::BER_Decoder::GetInteger((TaoCrypt::BER_Decoder *)this, a2: v8);
    TaoCrypt::DSA_PublicKey::SetSubGroupGenerator(this: (TaoCrypt::DSA_PublicKey *)a3, a2: v9, a3: v15);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v20,
      p: v19,
      n: v18.m_stackLevel);
    v10 = TaoCrypt::Integer::Integer(this: &v18);
    v11 = TaoCrypt::BER_Decoder::GetInteger((TaoCrypt::BER_Decoder *)this, a2: v10);
    TaoCrypt::DSA_PublicKey::SetPublicPart(this: (TaoCrypt::DSA_PublicKey *)a3, a2: v11, a3: v16);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v20,
      p: v19,
      n: v18.m_stackLevel);
    v12 = TaoCrypt::Integer::Integer(this: &v18);
    v13 = (CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *)TaoCrypt::BER_Decoder::GetInteger(
                                                                          (TaoCrypt::BER_Decoder *)this,
                                                                          a2: v12);
    TaoCrypt::DSA_PrivateKey::SetPrivatePart(a1: (int)a3, result: v13, a3: v17);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v20,
      p: v19,
      n: v18.m_stackLevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CB80
// Name: public: void TaoCrypt::RSA_Public_Decoder::Decode(class TaoCrypt::RSA_PublicKey __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::RSA_Public_Decoder::Decode(
        TaoCrypt::BER_Decoder *a1@<ecx>,
        const char *a2@<edi>,
        tagTLIBATTR *result)
{
  struct TaoCrypt::Integer *v4; // eax
  char *Integer; // eax
  struct TaoCrypt::Integer *v6; // eax
  char *v7; // eax
  const char *v8; // [esp-4h] [ebp-18h]
  TaoCrypt::Integer v9; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v10; // [esp+8h] [ebp-Ch]
  __int64 v11; // [esp+Ch] [ebp-8h] BYREF

  (*(void (__thiscall **)(TaoCrypt::BER_Decoder *))(*(_DWORD *)a1 + 4))(a1);
  if ( *(_DWORD *)(*((_DWORD *)a1 + 1) + 16) == 0 )
  {
    v4 = TaoCrypt::Integer::Integer(this: &v9);
    Integer = (char *)TaoCrypt::BER_Decoder::GetInteger(this: a1, a2: v4);
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)result, t: Integer, a3: a2);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v11,
      p: v10,
      n: v9.m_stackLevel);
    v6 = TaoCrypt::Integer::Integer(this: &v9);
    v7 = (char *)TaoCrypt::BER_Decoder::GetInteger(this: a1, a2: v6);
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&result->lcid, t: v7, a3: v8);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v11,
      p: v10,
      n: v9.m_stackLevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CC00
// Name: public: void TaoCrypt::DSA_Public_Decoder::Decode(class TaoCrypt::DSA_PublicKey __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DSA_Public_Decoder::Decode(
        TaoCrypt::DSA_Public_Decoder *this@<ecx>,
        const char *a2@<edi>,
        CInternalFileSystemPassThru<IFileSystem> *a3)
{
  struct TaoCrypt::Integer *v4; // eax
  char *Integer; // eax
  struct TaoCrypt::Integer *v6; // eax
  struct TaoCrypt::Integer *v7; // eax
  struct TaoCrypt::Integer *v8; // eax
  struct TaoCrypt::Integer *v9; // eax
  struct TaoCrypt::Integer *v10; // eax
  struct TaoCrypt::Integer *v11; // eax
  const char *v12; // [esp-4h] [ebp-18h]
  const char *v13; // [esp-4h] [ebp-18h]
  const char *v14; // [esp-4h] [ebp-18h]
  TaoCrypt::Integer v15; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v16; // [esp+8h] [ebp-Ch]
  __int64 v17; // [esp+Ch] [ebp-8h] BYREF

  (*(void (__thiscall **)(TaoCrypt::DSA_Public_Decoder *))(*(_DWORD *)this + 4))(a1: this);
  if ( *(_DWORD *)(*((_DWORD *)this + 1) + 16) == 0 )
  {
    v4 = TaoCrypt::Integer::Integer(this: &v15);
    Integer = (char *)TaoCrypt::BER_Decoder::GetInteger((TaoCrypt::BER_Decoder *)this, a2: v4);
    TaoCrypt::DSA_PublicKey::SetModulus(this: a3, t: Integer, a3: a2);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v17,
      p: v16,
      n: v15.m_stackLevel);
    v6 = TaoCrypt::Integer::Integer(this: &v15);
    v7 = TaoCrypt::BER_Decoder::GetInteger((TaoCrypt::BER_Decoder *)this, a2: v6);
    TaoCrypt::DSA_PublicKey::SetSubGroupOrder(this: (TaoCrypt::DSA_PublicKey *)a3, a2: v7, a3: v12);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v17,
      p: v16,
      n: v15.m_stackLevel);
    v8 = TaoCrypt::Integer::Integer(this: &v15);
    v9 = TaoCrypt::BER_Decoder::GetInteger((TaoCrypt::BER_Decoder *)this, a2: v8);
    TaoCrypt::DSA_PublicKey::SetSubGroupGenerator(this: (TaoCrypt::DSA_PublicKey *)a3, a2: v9, a3: v13);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v17,
      p: v16,
      n: v15.m_stackLevel);
    v10 = TaoCrypt::Integer::Integer(this: &v15);
    v11 = TaoCrypt::BER_Decoder::GetInteger((TaoCrypt::BER_Decoder *)this, a2: v10);
    TaoCrypt::DSA_PublicKey::SetPublicPart(this: (TaoCrypt::DSA_PublicKey *)a3, a2: v11, a3: v14);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v17,
      p: v16,
      n: v15.m_stackLevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CCE0
// Name: private: virtual void TaoCrypt::RSA_Public_Decoder::ReadHeader(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
tagTLIBATTR *__thiscall TaoCrypt::RSA_Public_Decoder::ReadHeader(TaoCrypt::BER_Decoder *this)
{
  return (tagTLIBATTR *)TaoCrypt::BER_Decoder::GetSequence(this);
}

//------------------------------------------------------------------------------
// Address: 0x0044CCF0
// Name: public: virtual TaoCrypt::CertDecoder::~CertDecoder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::CertDecoder::~CertDecoder(void *this)
{
  unsigned __int8 *v2; // [esp-4h] [ebp-8h]

  v2 = *((unsigned __int8 **)this + 19);
  *(_DWORD *)this = &TaoCrypt::CertDecoder::`vftable';
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v2);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: *((unsigned __int8 **)this + 2));
  *(_DWORD *)this = &TaoCrypt::BER_Decoder::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x0044CD20
// Name: private: virtual void TaoCrypt::CertDecoder::ReadHeader(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::CertDecoder::ReadHeader(TaoCrypt::BER_Decoder *this)
{
  unsigned int Sequence; // eax
  int v3; // ecx
  struct TaoCrypt::Integer *v4; // eax
  TaoCrypt::Integer v5; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  __int64 v7; // [esp+Ch] [ebp-8h] BYREF

  if ( *(_DWORD *)(*((_DWORD *)this + 1) + 16) == 0 )
  {
    TaoCrypt::BER_Decoder::GetSequence(this);
    *((_DWORD *)this + 4) = *(_DWORD *)(*((_DWORD *)this + 1) + 12);
    Sequence = TaoCrypt::BER_Decoder::GetSequence(this);
    v3 = *((_DWORD *)this + 1);
    *((_DWORD *)this + 5) = Sequence;
    *((_DWORD *)this + 5) = Sequence + *(_DWORD *)(v3 + 12);
    TaoCrypt::BER_Decoder::GetExplicitVersion(this);
    v4 = TaoCrypt::Integer::Integer(this: &v5);
    TaoCrypt::BER_Decoder::GetInteger(this, a2: v4);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7,
      p: v6,
      n: v5.m_stackLevel);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CD90
// Name: private: void TaoCrypt::CertDecoder::StoreKey(void)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0044CE00
// Name: private: unsigned int TaoCrypt::CertDecoder::GetAlgoId(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::CertDecoder::GetAlgoId(TaoCrypt **this)
{
  int v2; // eax
  int v3; // ecx
  unsigned int Length; // eax
  int v6; // edi
  int v7; // ecx
  int v8; // edx
  int v9; // eax
  int v10; // ecx
  int v11; // eax
  int v12; // ecx

  if ( *((_DWORD *)*(this + 1) + 4) != 0 )
    return 0;
  TaoCrypt::BER_Decoder::GetSequence((TaoCrypt::BER_Decoder *)this);
  v2 = (int)*(this + 1);
  v3 = *(_DWORD *)(v2 + 12);
  *(_DWORD *)(v2 + 12) = v3 + 1;
  if ( *(_BYTE *)(v3 + *(_DWORD *)(v2 + 4)) != 6 )
  {
    *((_DWORD *)*(this + 1) + 4) = 1026;
    return 0;
  }
  Length = TaoCrypt::GetLength(this: *(this + 1));
  v6 = 0;
  if ( Length != 0 )
  {
    do
    {
      v7 = (int)*(this + 1);
      v8 = *(_DWORD *)(v7 + 12);
      *(_DWORD *)(v7 + 12) = v8 + 1;
      --Length;
      v6 += *(unsigned __int8 *)(*(_DWORD *)(v7 + 4) + v8);
    }
    while ( Length != 0 );
    if ( v6 == 517 || v6 == 515 )
      return v6;
  }
  v9 = (int)*(this + 1);
  v10 = *(_DWORD *)(v9 + 12);
  *(_DWORD *)(v9 + 12) = v10 + 1;
  if ( *(_BYTE *)(v10 + *(_DWORD *)(v9 + 4)) != 5 )
  {
    *((_DWORD *)*(this + 1) + 4) = 1027;
    return 0;
  }
  v11 = (int)*(this + 1);
  v12 = *(_DWORD *)(v11 + 12);
  *(_DWORD *)(v11 + 12) = v12 + 1;
  if ( *(_BYTE *)(v12 + *(_DWORD *)(v11 + 4)) == 0 )
    return v6;
  *((_DWORD *)*(this + 1) + 4) = 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044CED0
// Name: private: unsigned int TaoCrypt::CertDecoder::GetSignature(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::CertDecoder::GetSignature(int this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  int v5; // eax
  const CSplitScreenAddedConVar *v6; // ecx
  unsigned __int8 *v7; // eax
  int v8; // ecx
  unsigned int v9; // [esp-Ch] [ebp-10h]

  v2 = *(_DWORD **)(this + 4);
  if ( v2[4] != 0 )
    return 0;
  v3 = v2[3];
  v2[3] = v3 + 1;
  if ( *(_BYTE *)(v3 + v2[1]) != 3 )
  {
    *(_DWORD *)(*(_DWORD *)(this + 4) + 16) = 1024;
    return 0;
  }
  *(_DWORD *)(this + 24) = TaoCrypt::GetLength(this: *(TaoCrypt **)(this + 4));
  v5 = *(_DWORD *)(this + 4);
  v6 = *(const CSplitScreenAddedConVar **)(v5 + 12);
  *(_DWORD *)(v5 + 12) = (char *)&v6->ConVar::ConCommandBase::__vftable + 1;
  if ( *((_BYTE *)&v6->ConVar::ConCommandBase::__vftable + *(_DWORD *)(v5 + 4)) != 0 )
  {
    *(_DWORD *)(*(_DWORD *)(this + 4) + 16) = 1028;
    return 0;
  }
  else
  {
    v7 = (unsigned __int8 *)operator new[](sz: v6, sza: (const CSplitScreenAddedConVar *)--*(_DWORD *)(this + 24));
    v8 = *(_DWORD *)(this + 4);
    v9 = *(_DWORD *)(this + 24);
    *(_DWORD *)(this + 76) = v7;
    memcpy(dst: v7, src: (unsigned __int8 *)(*(_DWORD *)(v8 + 4) + *(_DWORD *)(v8 + 12)), count: v9);
    *(_DWORD *)(*(_DWORD *)(this + 4) + 12) += *(_DWORD *)(this + 24);
    return *(_DWORD *)(this + 24);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044CF70
// Name: private: void TaoCrypt::CertDecoder::GetName(enum TaoCrypt::CertDecoder::NameType)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::CertDecoder::GetName(int a1@<ecx>, int a2@<esi>, int a3)
{
  unsigned int Sequence; // eax
  unsigned int v5; // ecx
  unsigned int v6; // eax
  int v7; // ebp
  int v8; // esi
  int v9; // eax
  int v10; // ecx
  unsigned int v11; // eax
  int v12; // eax
  int v13; // ecx
  char v14; // bl
  unsigned int v15; // eax
  int v16; // esi
  unsigned int v17; // ebx
  int v18; // esi
  bool email; // [esp+7h] [ebp-7Dh]
  unsigned int strLen; // [esp+8h] [ebp-7Ch]
  __int16 v22; // [esp+Ch] [ebp-78h]
  unsigned int length; // [esp+10h] [ebp-74h]
  std::exception sha; // [esp+14h] [ebp-70h] BYREF

  if ( *(_DWORD *)(*(_DWORD *)(a1 + 4) + 16) == 0 )
  {
    TaoCrypt::HASHwithTransform::HASHwithTransform(
      this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&sha,
      digSz: 5u,
      buffSz: 0x40u);
    sha.__vftable = (std::exception_vtbl *)&TaoCrypt::SHA::`vftable';
    TaoCrypt::RIPEMD160::Init(this: &sha);
    Sequence = TaoCrypt::BER_Decoder::GetSequence(this: (TaoCrypt::BER_Decoder *)a1);
    v5 = *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12);
    v6 = v5 + Sequence;
    length = v6;
    v7 = a1 + 80;
    if ( a3 != 0 )
      v7 = a1 + 592;
    v8 = 0;
    if ( v5 < v6 )
    {
      while ( 1 )
      {
        TaoCrypt::BER_Decoder::GetSet(this: (TaoCrypt::BER_Decoder *)a1);
        TaoCrypt::BER_Decoder::GetSequence(this: (TaoCrypt::BER_Decoder *)a1);
        v9 = *(_DWORD *)(a1 + 4);
        v10 = *(_DWORD *)(v9 + 12);
        *(_DWORD *)(v9 + 12) = v10 + 1;
        if ( *(_BYTE *)(v10 + *(_DWORD *)(v9 + 4)) != 6 )
        {
          *(_DWORD *)(*(_DWORD *)(a1 + 4) + 16) = 1026;
          return;
        }
        v11 = TaoCrypt::GetLength(this: *(TaoCrypt **)(a1 + 4));
        v22 = *(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 12) + *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4));
        if ( v22 != 1109 )
        {
          email = false;
          if ( (unsigned __int8)*(_WORD *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 12) + *(_DWORD *)(*(_DWORD *)(a1 + 4) + 4)) == 42 )
            email = HIBYTE(v22) == 0x86;
          *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12) += v11 + 1;
          v17 = TaoCrypt::GetLength(this: *(TaoCrypt **)(a1 + 4));
          if ( email )
          {
            qmemcpy((void *)(v8 + v7), "/emailAddress=", 14);
            v18 = v8 + 14;
            memcpy(
              dst: (unsigned __int8 *)(v18 + v7),
              src: (unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) + *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12)),
              count: v17);
            v8 = v17 + v18;
          }
          *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12) += v17;
          goto LABEL_29;
        }
        *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12) += 2;
        v12 = *(_DWORD *)(a1 + 4);
        v13 = *(_DWORD *)(v12 + 12);
        *(_DWORD *)(v12 + 12) = v13 + 1;
        v14 = *(_BYTE *)(v13 + *(_DWORD *)(v12 + 4));
        ++*(_DWORD *)(*(_DWORD *)(a1 + 4) + 12);
        v15 = TaoCrypt::GetLength(this: *(TaoCrypt **)(a1 + 4));
        strLen = v15;
        if ( v14 == 3 )
        {
          *(_DWORD *)(v8 + v7) = 1028539183;
          goto LABEL_21;
        }
        if ( v14 == 4 )
        {
          *(_DWORD *)(v8 + v7) = 1028543279;
          goto LABEL_21;
        }
        if ( v14 == 6 )
          break;
        switch ( v14 )
        {
          case 7:
            *(_WORD *)(v8 + v7) = *(_WORD *)asc_480A98;
            *(_BYTE *)(v8 + v7 + 2) = 61;
            v16 = v8 + 3;
            goto LABEL_22;
          case 8:
            *(_DWORD *)(v8 + v7) = 1028936495;
            goto LABEL_21;
          case 10:
            *(_WORD *)(v8 + v7) = *(_WORD *)aO;
            *(_BYTE *)(v8 + v7 + 2) = 61;
            v16 = v8 + 3;
            goto LABEL_22;
          case 11:
            *(_DWORD *)(v8 + v7) = 1029001007;
LABEL_21:
            v16 = v8 + 4;
LABEL_22:
            memcpy(
              dst: (unsigned __int8 *)(v16 + v7),
              src: (unsigned __int8 *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) + *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12)),
              count: v15);
            v15 = strLen;
            v8 = strLen + v16;
            break;
          default:
            break;
        }
        TaoCrypt::SHA::Update(
          this: (TaoCrypt::HASHwithTransform *)&sha,
          result: (std::exception *)(*(_DWORD *)(*(_DWORD *)(a1 + 4) + 4) + *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12)),
          len: v15);
        *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12) += strLen;
LABEL_29:
        if ( *(_DWORD *)(*(_DWORD *)(a1 + 4) + 12) >= length )
          goto LABEL_30;
      }
      *(_WORD *)(v8 + v7) = *(_WORD *)aC_1;
      *(_BYTE *)(v8 + v7 + 2) = 61;
      v16 = v8 + 3;
      goto LABEL_22;
    }
LABEL_30:
    *(_BYTE *)(v8 + v7) = 0;
    if ( a3 != 0 )
      TaoCrypt::HASHwithTransform::Final(
        this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&sha,
        hash: (void (__cdecl **)(IConVar *, const char *, float))(a1 + 36),
        preHiLen: a2);
    else
      TaoCrypt::HASHwithTransform::Final(
        this: (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)&sha,
        hash: (void (__cdecl **)(IConVar *, const char *, float))(a1 + 56),
        preHiLen: a2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D220
// Name: private: void TaoCrypt::CertDecoder::GetDate(enum TaoCrypt::CertDecoder::DateType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::CertDecoder::GetDate(int this, int a2)
{
  _DWORD *v3; // eax
  int v4; // ecx
  char v5; // cl
  unsigned int Length; // ebp
  int v7; // edi
  CDatamapFieldSizeDeducer<8> date; // [esp+8h] [ebp-14h] BYREF

  v3 = *(_DWORD **)(this + 4);
  if ( v3[4] == 0 )
  {
    v4 = v3[3];
    v3[3] = v4 + 1;
    v5 = *(_BYTE *)(v4 + v3[1]);
    if ( v5 != 23 && v5 != 24 )
    {
      *(_DWORD *)(*(_DWORD *)(this + 4) + 16) = 1030;
      return;
    }
    Length = TaoCrypt::GetLength(this: *(TaoCrypt **)(this + 4));
    if ( Length - 13 > 3 )
    {
      *(_DWORD *)(*(_DWORD *)(this + 4) + 16) = 1031;
      return;
    }
    v7 = *(_DWORD *)(this + 4);
    memcpy(
      dst: (unsigned __int8 *)&date,
      src: (unsigned __int8 *)(*(_DWORD *)(v7 + 4) + *(_DWORD *)(v7 + 12)),
      count: Length);
    *(_DWORD *)(v7 + 12) += Length;
    if ( !TaoCrypt::`anonymous namespace'::ValidateDate((const char *)&date, format: (const char *)&date)
      && *(_BYTE *)(this + 1136) != 0 )
    {
      if ( a2 == 0 )
      {
        *(_DWORD *)(*(_DWORD *)(this + 4) + 16) = 1036;
LABEL_12:
        memcpy(dst: (unsigned __int8 *)(this + 1104), src: (unsigned __int8 *)&date, count: Length);
        *(_BYTE *)(this + Length + 1104) = 0;
        return;
      }
      *(_DWORD *)(*(_DWORD *)(this + 4) + 16) = 1037;
    }
    if ( a2 != 0 )
    {
      memcpy(dst: (unsigned __int8 *)(this + 1120), src: (unsigned __int8 *)&date, count: Length);
      *(_BYTE *)(this + Length + 1120) = 0;
      return;
    }
    goto LABEL_12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D370
// Name: private: void TaoCrypt::CertDecoder::GetValidity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::CertDecoder::GetValidity(TaoCrypt::BER_Decoder *this)
{
  if ( *(_DWORD *)(*((_DWORD *)this + 1) + 16) == 0 )
  {
    TaoCrypt::BER_Decoder::GetSequence(this);
    TaoCrypt::CertDecoder::GetDate((int)this, a2: 0);
    TaoCrypt::CertDecoder::GetDate((int)this, a2: 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D3A0
// Name: public: unsigned int TaoCrypt::DER_Encoder::SetAlgoID(enum TaoCrypt::HashType,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
CDbgFmtMsg *__thiscall TaoCrypt::DER_Encoder::SetAlgoID(_DWORD *this, CDbgFmtMsg *result, unsigned __int8 *dst)
{
  unsigned int v4; // ebx
  unsigned int v5; // edi
  const CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Iterator_t *v6; // ecx
  int v7; // eax
  int v8; // esi
  unsigned __int8 *algoName; // [esp+8h] [ebp-18h]
  unsigned __int8 src[8]; // [esp+Ch] [ebp-14h] BYREF
  CCountedStringPoolBase<unsigned int>::<unnamed_tag> ID_Length[2]; // [esp+14h] [ebp-Ch] BYREF

  if ( result == (CDbgFmtMsg *)88 )
  {
    v4 = 7;
    algoName = (unsigned __int8 *)shaAlgoID;
  }
  else if ( result == (CDbgFmtMsg *)646 )
  {
    v4 = 10;
    algoName = (unsigned __int8 *)&loc_480AA4 + 4;
  }
  else
  {
    if ( result != (CDbgFmtMsg *)649 )
    {
      *(this + 1) = 1034;
      return nullptr;
    }
    v4 = 10;
    algoName = (unsigned __int8 *)&md5AlgoID;
  }
  v5 = TaoCrypt::SetLength(
         length: (const CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Iterator_t *)(v4 - 2),
         lengtha: v4 - 2,
         output: (unsigned __int8 *)ID_Length);
  v7 = TaoCrypt::SetSequence(len: v6, lena: v5 + v4 + 1, output: src);
  src[v7] = 6;
  v8 = v7 + 1;
  memcpy(dst, src, count: v7 + 1);
  memcpy(dst: &dst[v8], src: (unsigned __int8 *)ID_Length, count: v5);
  memcpy(dst: &dst[v8 + v5], src: algoName, count: v4);
  return (CDbgFmtMsg *)(v4 + v8 + v5);
}

//------------------------------------------------------------------------------
// Address: 0x0044D480
// Name: unsigned int TaoCrypt::EncodeDSA_Signature(unsigned char const __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TaoCrypt::EncodeDSA_Signature(char *signature, unsigned __int8 *output)
{
  CKeyErrorContext s; // [esp+4h] [ebp-20h] BYREF
  unsigned __int8 *v3; // [esp+8h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v4; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int8 *v5; // [esp+18h] [ebp-Ch]
  __int64 v6; // [esp+1Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&v4.m_iRefs,
    encodedInteger: signature,
    byteCount: 0x14u,
    a4: 0);
  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&s,
    encodedInteger: signature + 20,
    byteCount: 0x14u,
    a4: 0);
  TaoCrypt::EncodeDSA_Signature(
    this: (struct TaoCrypt::Integer *)&v4.m_iRefs,
    a2: &s,
    (struct TaoCrypt::Integer *)output);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v4, p: v3, n: s.m_stackLevel);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v6,
    p: v5,
    n: v4.m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x0044D500
// Name: public: void TaoCrypt::PublicKey::AddToEnd(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::PublicKey::AddToEnd(TaoCrypt::PublicKey *this, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v4; // edi
  unsigned __int8 *v5; // [esp-24h] [ebp-30h]

  v4 = (unsigned __int8 *)operator new[](
                            sz: (const CSplitScreenAddedConVar *)(count + *((_DWORD *)this + 1)),
                            sza: (const CSplitScreenAddedConVar *)(count + *((_DWORD *)this + 1)));
  memcpy(dst: v4, src: *(unsigned __int8 **)this, count: *((_DWORD *)this + 1));
  memcpy(dst: &v4[*((_DWORD *)this + 1)], src, count);
  v5 = *(unsigned __int8 **)this;
  *(_DWORD *)this = 0;
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v5);
  *((_DWORD *)this + 1) += count;
  *(_DWORD *)this = v4;
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x0044D560
// Name: private: void TaoCrypt::CertDecoder::AddDSA(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::CertDecoder::AddDSA(TaoCrypt **this)
{
  _DWORD *v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // edi
  unsigned int Length; // eax

  v2 = *(this + 1);
  if ( v2[4] == 0 )
  {
    v3 = v2[3];
    v2[3] = v3 + 1;
    if ( *(_BYTE *)(v3 + v2[1]) == 3 )
    {
      ++*((_DWORD *)*(this + 1) + 3);
      v4 = (int)*(this + 1);
      v5 = *(_DWORD *)(v4 + 12);
      *(_DWORD *)(v4 + 12) = v5 + 1;
      if ( *(_BYTE *)(v5 + *(_DWORD *)(v4 + 4)) != 0 )
      {
        do
        {
          v6 = (int)*(this + 1);
          v7 = *(_DWORD *)(v6 + 12);
          *(_DWORD *)(v6 + 12) = v7 + 1;
        }
        while ( *(_BYTE *)(v7 + *(_DWORD *)(v6 + 4)) != 0 );
      }
      v8 = (int)*(this + 1);
      v9 = *(_DWORD *)(v8 + 12);
      *(_DWORD *)(v8 + 12) = v9 + 1;
      if ( *(_BYTE *)(v9 + *(_DWORD *)(v8 + 4)) == 2 )
      {
        Length = TaoCrypt::GetLength(this: *(this + 1));
        TaoCrypt::PublicKey::AddToEnd(
          this: (TaoCrypt::PublicKey *)(this + 2),
          src: (unsigned __int8 *)(v9 + *((_DWORD *)*(this + 1) + 1)),
          count: Length + *((_DWORD *)*(this + 1) + 3) - v9);
      }
      else
      {
        *((_DWORD *)*(this + 1) + 4) = 1010;
      }
    }
    else
    {
      *((_DWORD *)*(this + 1) + 4) = 1024;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D620
// Name: unsigned int TaoCrypt::DecodeDSA_Signature(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __usercall TaoCrypt::DecodeDSA_Signature@<eax>(
        const CSplitScreenAddedConVar *a1@<ecx>,
        __int128 a2@<xmm0>,
        TaoCrypt *this,
        unsigned __int8 *encoded,
        IConVar *sz)
{
  CSplitScreenAddedConVar *m_pConVarState; // esi
  bool v6; // zf
  unsigned int Length; // eax
  unsigned int v9; // esi
  int v10; // edi
  unsigned __int8 *v11; // ebx
  unsigned __int8 *v12; // ebp
  unsigned int v13; // eax
  unsigned __int8 *v14; // edi
  ConVarRef source; // [esp+8h] [ebp-14h] BYREF
  int v16; // [esp+14h] [ebp-8h]
  int v17; // [esp+18h] [ebp-4h]

  source.m_pConVar = sz;
  if ( sz != nullptr )
    m_pConVarState = operator new[](sz: a1, sza: (const CSplitScreenAddedConVar *)sz);
  else
    m_pConVarState = nullptr;
  source.m_pConVarState = m_pConVarState;
  memcpy(dst: (unsigned __int8 *)m_pConVarState, src: encoded, count: (unsigned int)sz);
  v6 = LOBYTE(m_pConVarState->ConVar::ConCommandBase::__vftable) == 48;
  v17 = 0;
  v16 = 1;
  if ( !v6 )
  {
    memset(a1: a2, dst: (int)m_pConVarState, value: 0, count: (unsigned int)sz);
LABEL_6:
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: (unsigned __int8 *)m_pConVarState);
    return 0;
  }
  TaoCrypt::GetLength(this: (TaoCrypt *)&source);
  m_pConVarState = (CSplitScreenAddedConVar *)source.m_pConVarState;
  v6 = *((_BYTE *)&source.m_pConVarState->__vftable + v16++) == 2;
  if ( !v6 )
  {
    memset(a1: a2, dst: (int)source.m_pConVarState, value: 0, count: (unsigned int)source.m_pConVar);
    goto LABEL_6;
  }
  Length = TaoCrypt::GetLength(this: (TaoCrypt *)&source);
  v9 = Length;
  if ( Length == 20 )
  {
    v10 = v16;
    goto LABEL_16;
  }
  if ( Length == 21 )
  {
    v10 = v16 + 1;
    v9 = 20;
LABEL_16:
    v11 = (unsigned __int8 *)this;
    goto LABEL_17;
  }
  if ( Length != 19 )
    goto LABEL_25;
  v10 = v16;
  *(_BYTE *)this = 0;
  v11 = (unsigned __int8 *)this + 1;
LABEL_17:
  v12 = (unsigned __int8 *)source.m_pConVarState;
  memcpy(dst: v11, src: (unsigned __int8 *)source.m_pConVarState + v10, count: v9);
  v6 = v12[v9 + v10] == 2;
  v16 = v9 + v10 + 1;
  if ( !v6 )
  {
    memset(a1: a2, dst: (int)v12, value: 0, count: (unsigned int)source.m_pConVar);
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: v12);
    return 0;
  }
  v13 = TaoCrypt::GetLength(this: (TaoCrypt *)&source);
  switch ( v13 )
  {
    case 0x14u:
      goto LABEL_22;
    case 0x15u:
      ++v16;
      v13 = 20;
LABEL_22:
      v14 = (unsigned __int8 *)source.m_pConVarState;
      memcpy(dst: &v11[v9], src: (unsigned __int8 *)source.m_pConVarState + v16, count: v13);
      memset(a1: a2, dst: (int)v14, value: 0, count: (unsigned int)source.m_pConVar);
      TaoCrypt::tcArrayDelete<unsigned char>(ptr: v14);
      return 40;
    case 0x13u:
      (v11++)[v9] = 0;
      goto LABEL_22;
    default:
      break;
  }
LABEL_25:
  v17 = 1035;
  TaoCrypt::Source::~Source(this: (ICvar *)&source);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044D7D0
// Name: private: void TaoCrypt::CertDecoder::GetKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::CertDecoder::GetKey(TaoCrypt::BER_Decoder *this)
{
  int AlgoId; // eax
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // eax
  int v8; // ecx
  const CNonFatalLoggingResponsePolicy *v9; // [esp+0h] [ebp-4h]

  if ( *(_DWORD *)(*((_DWORD *)this + 1) + 16) == 0 )
  {
    TaoCrypt::BER_Decoder::GetSequence(this);
    AlgoId = TaoCrypt::CertDecoder::GetAlgoId((TaoCrypt **)this);
    *((_DWORD *)this + 8) = AlgoId;
    if ( AlgoId == 645 )
    {
      v3 = *((_DWORD *)this + 1);
      v4 = *(_DWORD *)(v3 + 12);
      *(_DWORD *)(v3 + 12) = v4 + 1;
      if ( *(_BYTE *)(v4 + *(_DWORD *)(v3 + 4)) != 3 )
      {
        *(_DWORD *)(*((_DWORD *)this + 1) + 16) = 1024;
        return;
      }
      ++*(_DWORD *)(*((_DWORD *)this + 1) + 12);
      v5 = *((_DWORD *)this + 1);
      v6 = *(_DWORD *)(v5 + 12);
      *(_DWORD *)(v5 + 12) = v6 + 1;
      if ( *(_BYTE *)(v6 + *(_DWORD *)(v5 + 4)) != 0 )
      {
        do
        {
          v7 = *((_DWORD *)this + 1);
          v8 = *(_DWORD *)(v7 + 12);
          *(_DWORD *)(v7 + 12) = v8 + 1;
        }
        while ( *(_BYTE *)(v8 + *(_DWORD *)(v7 + 4)) != 0 );
      }
    }
    else if ( AlgoId != 515 )
    {
      *(_DWORD *)(*((_DWORD *)this + 1) + 16) = 1025;
      return;
    }
    TaoCrypt::CertDecoder::StoreKey(result: v9);
    if ( *((_DWORD *)this + 8) == 515 )
      TaoCrypt::CertDecoder::AddDSA((TaoCrypt **)this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0044D880
// Name: public: TaoCrypt::Signature_Encoder::Signature_Encoder(unsigned char const __near *,unsigned int,enum TaoCrypt::HashType,class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge TaoCrypt::Signature_Encoder::Signature_Encoder@<eax>(
        int a1@<ecx>,
        __int128 a2@<xmm0>,
        const LoggingContext_t *dig,
        unsigned int digSz,
        CDbgFmtMsg *source,
        int a6)
{
  unsigned int v7; // ebp
  const CUtlMemory<CCountedStringPoolBase<unsigned short>::hash_item_t,int>::Iterator_t *v8; // ecx
  unsigned int v9; // eax
  unsigned int v10; // edi
  CSplitScreenAddedConVar *v11; // eax
  int v13; // [esp-20h] [ebp-70h]
  unsigned int v14; // [esp-18h] [ebp-68h]
  unsigned int seqSz; // [esp+10h] [ebp-40h]
  unsigned int algoSz; // [esp+14h] [ebp-3Ch]
  CCountedStringPoolBase<unsigned int>::<unnamed_tag> seqArray[2]; // [esp+18h] [ebp-38h] BYREF
  CDatamapFieldSizeDeducer<8> algoArray; // [esp+20h] [ebp-30h] BYREF
  unsigned __int8 src[28]; // [esp+30h] [ebp-20h] BYREF

  *(_DWORD *)(a1 + 4) = 0;
  *(_DWORD *)a1 = &TaoCrypt::Signature_Encoder::`vftable';
  v7 = TaoCrypt::Signature_Encoder::SetDigest(this: (TaoCrypt::Signature_Encoder *)a1, d: dig, dSz: digSz, output: src);
  algoSz = (unsigned int)TaoCrypt::DER_Encoder::SetAlgoID(
                           this: (_DWORD *)a1,
                           result: source,
                           dst: (unsigned __int8 *)&algoArray);
  v9 = TaoCrypt::SetSequence(len: v8, lena: algoSz + v7, output: (unsigned __int8 *)seqArray);
  v10 = v7 + v9 + algoSz;
  seqSz = v9;
  if ( v10 > *(_DWORD *)a6 )
  {
    v11 = TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
            a1: a6 + 8,
            src: *(unsigned __int8 **)(a6 + 4),
            a3: *(_DWORD *)a6,
            count: v10,
            a5: 1);
    v14 = v10 - *(_DWORD *)a6;
    v13 = (int)v11 + *(_DWORD *)a6;
    *(_DWORD *)(a6 + 4) = v11;
    memset(a1: a2, dst: v13, value: 0, count: v14);
    v9 = seqSz;
    *(_DWORD *)a6 = v10;
  }
  memcpy(
    dst: (unsigned __int8 *)(*(_DWORD *)(a6 + 4) + *(_DWORD *)(a6 + 12)),
    src: (unsigned __int8 *)seqArray,
    count: v9);
  *(_DWORD *)(a6 + 12) += seqSz;
  memcpy(
    dst: (unsigned __int8 *)(*(_DWORD *)(a6 + 12) + *(_DWORD *)(a6 + 4)),
    src: (unsigned __int8 *)&algoArray,
    count: algoSz);
  *(_DWORD *)(a6 + 12) += algoSz;
  memcpy(dst: (unsigned __int8 *)(*(_DWORD *)(a6 + 12) + *(_DWORD *)(a6 + 4)), src, count: v7);
  *(_DWORD *)(a6 + 12) += v7;
  return a1;
}

//------------------------------------------------------------------------------
// Address: 0x0044D990
// Name: public: void TaoCrypt::CertDecoder::DecodeToKey(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::CertDecoder::DecodeToKey(TaoCrypt **this)
{
  (*((void (__thiscall **)(TaoCrypt **))*this + 1))(a1: this);
  *(this + 7) = (TaoCrypt *)TaoCrypt::CertDecoder::GetAlgoId(this);
  TaoCrypt::CertDecoder::GetName(a1: (int)this, a2: (int)this, a3: 0);
  TaoCrypt::CertDecoder::GetValidity((TaoCrypt::BER_Decoder *)this);
  TaoCrypt::CertDecoder::GetName(a1: (int)this, a2: (int)this, a3: 1);
  TaoCrypt::CertDecoder::GetKey((TaoCrypt::BER_Decoder *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0044D9D0
// Name: private: bool TaoCrypt::CertDecoder::ConfirmSignature(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
char __userpurge TaoCrypt::CertDecoder::ConfirmSignature@<al>(
        TaoCrypt::CertDecoder *this@<ecx>,
        __int128 a2@<xmm0>,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *pub)
{
  int v4; // eax
  void (__thiscall ***v5)(void *, _DWORD); // esi
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v6; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *v7; // ebx
  KeyValues *v8; // ecx
  int v9; // ebx
  CSplitScreenAddedConVar *v10; // eax
  KeyValues *v11; // ecx
  const CUtlMemory<unsigned short,int> *v12; // ebx
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v14; // eax
  std::exception *v15; // ebx
  KeyValues *v16; // ecx
  int (__thiscall *v17)(void (__thiscall ***)(void *, _DWORD)); // eax
  unsigned int v18; // eax
  __int128 v19; // xmm0
  const LoggingContext_t *v20; // ecx
  IConVar *m_pConVar; // ebp
  unsigned __int8 *m_pConVarState; // edi
  char v23; // bl
  __int128 v24; // xmm0
  KeyValues *v25; // ecx
  KeyValues *v26; // ecx
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *source; // [esp+10h] [ebp-C0h] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *pubKey; // [esp+18h] [ebp-B8h] BYREF
  unsigned __int8 *v29; // [esp+1Ch] [ebp-B4h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v30; // [esp+20h] [ebp-B0h] BYREF
  unsigned __int8 *v31; // [esp+2Ch] [ebp-A4h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v32; // [esp+30h] [ebp-A0h] BYREF
  ConVarRef build; // [esp+3Ch] [ebp-94h] BYREF
  int v34[3]; // [esp+44h] [ebp-8Ch] BYREF
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v35; // [esp+50h] [ebp-80h] BYREF
  unsigned __int8 *v36; // [esp+64h] [ebp-6Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v37; // [esp+68h] [ebp-68h] BYREF
  unsigned __int8 *v38; // [esp+74h] [ebp-5Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v39; // [esp+78h] [ebp-58h] BYREF
  unsigned __int8 *v40; // [esp+84h] [ebp-4Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v41; // [esp+88h] [ebp-48h] BYREF
  char v42[40]; // [esp+A4h] [ebp-2Ch] BYREF

  source = pub;
  v4 = *((_DWORD *)this + 7);
  v5 = nullptr;
  switch ( v4 )
  {
    case 648:
      v6 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)operator new(
                                                                              sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc,
                                                                              sza: 0x70u);
      v7 = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)v6;
      if ( v6 != nullptr )
      {
        TaoCrypt::HASHwithTransform::HASHwithTransform(this: v6, digSz: 4u, buffSz: 0x40u);
        v7->m_Memory.m_pMemory = (CUtlString *)&TaoCrypt::MD5::`vftable';
        TaoCrypt::MD5::Init(this: v7);
        TaoCrypt::tcDelete<TaoCrypt::HASH>(ptr: v8, a2: nullptr);
        v5 = (void (__thiscall ***)(void *, _DWORD))v7;
      }
      v9 = 649;
      break;
    case 646:
      v10 = operator new(sz: (const CSplitScreenAddedConVar *)this, sza: 0x2Cu);
      if ( v10 != nullptr )
      {
        v12 = TaoCrypt::MD2::MD2(this: (int)v10);
        if ( v12 != nullptr )
        {
          TaoCrypt::tcDelete<TaoCrypt::HASH>(ptr: v11, a2: nullptr);
          v5 = (void (__thiscall ***)(void *, _DWORD))v12;
        }
      }
      v9 = 646;
      break;
    case 649:
    case 517:
      v14 = (CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *)operator new(
                                                                               sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc,
                                                                               sza: 0x70u);
      v15 = (std::exception *)v14;
      if ( v14 != nullptr )
      {
        TaoCrypt::HASHwithTransform::HASHwithTransform(this: v14, digSz: 5u, buffSz: 0x40u);
        v15->__vftable = (std::exception_vtbl *)&TaoCrypt::SHA::`vftable';
        TaoCrypt::RIPEMD160::Init(this: v15);
        TaoCrypt::tcDelete<TaoCrypt::HASH>(ptr: v16, a2: nullptr);
        v5 = (void (__thiscall ***)(void *, _DWORD))v15;
      }
      v9 = 88;
      break;
    default:
      *(_DWORD *)(*((_DWORD *)this + 1) + 16) = 1033;
      TaoCrypt::tcDelete<TaoCrypt::HASH>(ptr: (KeyValues *)this, a2: nullptr);
      return 0;
  }
  ((void (__thiscall *)(void (__thiscall ***)(void *, _DWORD), int, int))(*v5)[1])(
    a1: v5,
    a2: *((_DWORD *)this + 4) + *(_DWORD *)(*((_DWORD *)this + 1) + 4),
    a3: *((_DWORD *)this + 5) - *((_DWORD *)this + 4));
  ((void (__thiscall **)(void *, int *))*v5)[2](a1: v5, a2: &v41.m_iRefs);
  if ( *((_DWORD *)this + 8) == 645 )
  {
    build.m_pConVarState = TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                             a1: (int)v34,
                             src: nullptr,
                             a3: 0,
                             count: 0,
                             a5: 0);
    build.m_pConVar = nullptr;
    memset(a1: a2, dst: (int)build.m_pConVarState, value: 0, count: 0);
    v17 = (int (__thiscall *)(void (__thiscall ***)(void *, _DWORD)))(*v5)[5];
    v34[1] = 0;
    v34[2] = 0;
    v18 = v17(a1: v5);
    TaoCrypt::Signature_Encoder::Signature_Encoder(
      a1: (int)v42,
      a2: v19,
      dig: (const LoggingContext_t *)&v41.m_iRefs,
      digSz: v18,
      source: (CDbgFmtMsg *)v9,
      a6: (int)&build);
    TaoCrypt::RSA_PublicKey::RSA_PublicKey(this: &pubKey, (struct TaoCrypt::Source *)source);
    v20 = *((const LoggingContext_t **)this + 19);
    m_pConVar = build.m_pConVar;
    m_pConVarState = (unsigned __int8 *)build.m_pConVarState;
    source = (CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *)&pubKey;
    v23 = TaoCrypt::RSA_Encryptor<TaoCrypt::RSA_BlockType2>::SSL_Verify(
            this: (TaoCrypt::RSA_PublicKey **)&source,
            result: (const LoggingContext_t *)build.m_pConVarState,
            sz: (unsigned int)build.m_pConVar,
            sig: v20);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v32, p: v31, n: v30.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v30, p: v29, n: (unsigned int)pubKey);
    memset(a1: v24, dst: (int)m_pConVarState, value: 0, count: (unsigned int)m_pConVar);
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: m_pConVarState);
    TaoCrypt::tcDelete<TaoCrypt::HASH>(ptr: v25, a2: v5);
  }
  else
  {
    TaoCrypt::DecodeDSA_Signature(
      a1: *((const CSplitScreenAddedConVar **)this + 19),
      a2,
      this: (TaoCrypt *)v42,
      encoded: *((unsigned __int8 **)this + 19),
      sz: *((IConVar **)this + 6));
    TaoCrypt::DSA_PublicKey::DSA_PublicKey(this: &v35, source);
    TaoCrypt::DSA_Signer::DSA_Signer(this: (CFunctor *)&pubKey, key: (CFunctor_vtbl *)&v35);
    v23 = TaoCrypt::DSA_Verifier::Verify(this: (CFunctor *)&pubKey, sha_digest: (CFunctor *)&v41.m_iRefs, sig: v42);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v32.CRefCountServiceBase<1,CRefMT>,
      p: (unsigned __int8 *)v32.CFunctorCallback::IRefCounted::__vftable,
      n: (unsigned int)v31);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v30.CRefCountServiceBase<1,CRefMT>,
      p: (unsigned __int8 *)v30.CFunctorCallback::IRefCounted::__vftable,
      n: (unsigned int)v29);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v41, p: v40, n: v39.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v39, p: v38, n: v37.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v37, p: v36, n: (unsigned int)v35.m_pElements);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v35.m_Memory.m_nGrowSize,
      p: (unsigned __int8 *)v35.m_Memory.m_nAllocationCount,
      n: (unsigned int)v35.m_Memory.m_pMemory);
    TaoCrypt::tcDelete<TaoCrypt::HASH>(ptr: v26, a2: v5);
  }
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x0044DCE0
// Name: private: bool TaoCrypt::CertDecoder::ValidateSignature(class mySTL::list<class TaoCrypt::Signer __near *> __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge TaoCrypt::CertDecoder::ValidateSignature@<al>(
        TaoCrypt::CertDecoder *this@<ecx>,
        __int128 a2@<xmm0>,
        int *a3)
{
  int v3; // esi
  char *v5; // edi
  char *v6; // eax
  unsigned int v7; // ecx
  int v8; // edx
  int v10; // esi
  CCountedStringPoolBase<unsigned int>::hash_item_t *m_pMemory; // ecx
  unsigned __int8 *v12; // edi
  unsigned __int8 *v13; // eax
  char v14; // bl
  unsigned __int8 *m_nAllocationCount; // esi
  __int128 v16; // xmm0
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > count; // [esp+10h] [ebp-14h] BYREF

  v3 = *a3;
  if ( *a3 != 0 )
  {
    v5 = (char *)this + 56;
    while ( 2 )
    {
      v6 = (char *)(*(_DWORD *)(v3 + 8) + 520);
      v7 = 20;
      v8 = v5 - v6;
      while ( 1 )
      {
        if ( v7 < 4 )
        {
          v10 = *(_DWORD *)(v3 + 8);
          m_pMemory = *(CCountedStringPoolBase<unsigned int>::hash_item_t **)(v10 + 4);
          v12 = *(unsigned __int8 **)v10;
          count.m_Memory.m_pMemory = m_pMemory;
          if ( m_pMemory != nullptr )
          {
            v13 = (unsigned __int8 *)operator new[](
                                       sz: (const CSplitScreenAddedConVar *)m_pMemory,
                                       sza: (const CSplitScreenAddedConVar *)m_pMemory);
            m_pMemory = count.m_Memory.m_pMemory;
          }
          else
          {
            v13 = nullptr;
          }
          count.m_Memory.m_nAllocationCount = (int)v13;
          memcpy(dst: v13, src: v12, count: (unsigned int)m_pMemory);
          count.m_Size = 0;
          count.m_pElements = nullptr;
          v14 = TaoCrypt::CertDecoder::ConfirmSignature(this, a2, pub: &count);
          m_nAllocationCount = (unsigned __int8 *)count.m_Memory.m_nAllocationCount;
          memset(
            a1: v16,
            dst: count.m_Memory.m_nAllocationCount,
            value: 0,
            count: (unsigned int)count.m_Memory.m_pMemory);
          TaoCrypt::tcArrayDelete<unsigned char>(ptr: m_nAllocationCount);
          return v14;
        }
        if ( *(_DWORD *)&v6[v8] != *(_DWORD *)v6 )
          break;
        v7 -= 4;
        v6 += 4;
      }
      v3 = *(_DWORD *)(v3 + 4);
      if ( v3 != 0 )
        continue;
      break;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0044DDB0
// Name: private: void TaoCrypt::CertDecoder::Decode(class mySTL::list<class TaoCrypt::Signer __near *> __near *,enum TaoCrypt::CertDecoder::CertType)
// Source: json
//------------------------------------------------------------------------------
char __userpurge TaoCrypt::CertDecoder::Decode@<al>(int a1@<ecx>, __int128 a2@<xmm0>, int *signers, int ct)
{
  int v5; // eax
  int v6; // ecx
  int AlgoId; // edi

  v5 = *(_DWORD *)(*(_DWORD *)(a1 + 4) + 16);
  if ( v5 == 0 )
  {
    TaoCrypt::CertDecoder::DecodeToKey(this: (TaoCrypt **)a1);
    v5 = *(_DWORD *)(a1 + 4);
    if ( *(_DWORD *)(v5 + 16) == 0 )
    {
      v6 = *(_DWORD *)(a1 + 20);
      if ( *(_DWORD *)(v5 + 12) != v6 )
        *(_DWORD *)(v5 + 12) = v6;
      AlgoId = TaoCrypt::CertDecoder::GetAlgoId(this: (TaoCrypt **)a1);
      TaoCrypt::CertDecoder::GetSignature(this: a1);
      v5 = *(_DWORD *)(a1 + 4);
      if ( *(_DWORD *)(v5 + 16) == 0 )
      {
        if ( AlgoId == *(_DWORD *)(a1 + 28) )
        {
          if ( ct != 0 && *(_BYTE *)(a1 + 1136) != 0 )
          {
            LOBYTE(v5) = TaoCrypt::CertDecoder::ValidateSignature(this: (TaoCrypt::CertDecoder *)a1, a2, a3: signers);
            if ( (_BYTE)v5 == 0 )
              *(_DWORD *)(*(_DWORD *)(a1 + 4) + 16) = 1039;
          }
        }
        else
        {
          *(_DWORD *)(v5 + 16) = 1023;
        }
      }
    }
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0044DE30
// Name: public: TaoCrypt::CertDecoder::CertDecoder(class TaoCrypt::Source __near &,bool,class mySTL::list<class TaoCrypt::Signer __near *> __near *,bool,enum TaoCrypt::CertDecoder::CertType)
// Source: json
//------------------------------------------------------------------------------
CNonFatalLoggingResponsePolicy *__userpurge TaoCrypt::CertDecoder::CertDecoder@<eax>(
        CNonFatalLoggingResponsePolicy *this@<ecx>,
        __int128 a2@<xmm0>,
        const LoggingContext_t *s,
        bool decode,
        int *signers,
        bool noVerify,
        int ct)
{
  *((_DWORD *)this + 1) = s;
  this->__vftable = (CNonFatalLoggingResponsePolicy_vtbl *)&TaoCrypt::CertDecoder::`vftable';
  TaoCrypt::PublicKey::PublicKey(this: nullptr, k: nullptr);
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_BYTE *)this + 1136) = !noVerify;
  *((_BYTE *)this + 80) = 0;
  *((_BYTE *)this + 592) = 0;
  if ( decode )
    TaoCrypt::CertDecoder::Decode(a1: (int)this, a2, signers, ct);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00475FC0
// Name: TaoCrypt::_dynamic_initializer_for__isMMX__
// Source: json
//------------------------------------------------------------------------------
bool TaoCrypt::_dynamic_initializer_for__isMMX__()
{
  bool result; // al

  result = TaoCrypt::IsMmx();
  TaoCrypt::isMMX = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475FD0
// Name: TaoCrypt::_dynamic_initializer_for__s_RunAtStartupSetPentiumFunctionPointers__
// Source: json
//------------------------------------------------------------------------------
int TaoCrypt::_dynamic_initializer_for__s_RunAtStartupSetPentiumFunctionPointers__()
{
  int result; // eax

  result = TaoCrypt::SetPentiumFunctionPointers();
  s_RunAtStartupSetPentiumFunctionPointers = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00475FE0
// Name: _dynamic_initializer_for__g_ExpressionEvaluator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExpressionEvaluator__()
{
  CExpressionEvaluator::CExpressionEvaluator(this: &g_ExpressionEvaluator);
  return atexit(func: dynamic_atexit_destructor_for__g_ExpressionEvaluator__);
}

//------------------------------------------------------------------------------
// Address: 0x00476000
// Name: _dynamic_initializer_for__g_KVMutex__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_KVMutex__()
{
  g_KVMutex.m_ownerID = 0;
  g_KVMutex.m_depth = 0;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00476010
// Name: _dynamic_initializer_for__s_StringCharConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char **__usercall dynamic_initializer_for__s_StringCharConversion__@<eax>(__int128 a1@<xmm0>)
{
  char **result; // eax
  int v2; // edx
  char v3; // cl

  CUtlCharConversion::CUtlCharConversion(
    this: &s_StringCharConversion,
    nEscapeChar: 92,
    pDelimiter: "\"",
    nCount: 11,
    pArray: s_pConversionArrays_StringCharConversion);
  s_StringCharConversion.__vftable = (CUtlCStringConversion_vtbl *)&CUtlCStringConversion::`vftable';
  memset(a1, dst: (int)s_StringCharConversion.m_pConversion, value: 0, count: 0xFFu);
  result = &s_pConversionArrays_StringCharConversion[0].m_pReplacementString;
  do
  {
    v2 = **result;
    v3 = *((_BYTE *)result - 4);
    result += 2;
    s_StringCharConversion.m_pConversion[v2] = v3;
  }
  while ( (int)result < (int)&s_pConversionArrays_NoEscConversion[0].m_pReplacementString );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00476070
// Name: _dynamic_initializer_for__s_NoEscConversion__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CUtlCharConversion *dynamic_initializer_for__s_NoEscConversion__()
{
  CUtlCharConversion *result; // eax

  result = CUtlCharConversion::CUtlCharConversion(
             this: &s_NoEscConversion,
             nEscapeChar: 127,
             pDelimiter: "\"",
             nCount: 1,
             pArray: s_pConversionArrays_NoEscConversion);
  s_NoEscConversion.__vftable = (CUtlNoEscConversion_vtbl *)&CUtlNoEscConversion::`vftable';
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004760A0
// Name: _dynamic_initializer_for__s_EmptyConVar__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_EmptyConVar__()
{
  CEmptyConVar::CEmptyConVar(this: &s_EmptyConVar);
  return atexit(func: dynamic_atexit_destructor_for__s_EmptyConVar__);
}

//------------------------------------------------------------------------------
// Address: 0x004760C0
// Name: _dynamic_atexit_destructor_for__QueuedPacket_t::s_Allocator__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__QueuedPacket_t::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &QueuedPacket_t::s_Allocator);
}
