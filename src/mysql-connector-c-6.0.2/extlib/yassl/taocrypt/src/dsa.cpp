// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/dsa.cpp
// Functions: 17
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\dsa.h"

//------------------------------------------------------------------------------
// Address: 0x0044B200
// Name: public: void TaoCrypt::DSA_PublicKey::Swap(class TaoCrypt::DSA_PublicKey __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DSA_PublicKey::Swap(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this@<ecx>,
        struct TaoCrypt::Integer *other,
        int a3,
        int a4)
{
  TaoCrypt::Integer::Swap((TaoCrypt::Integer *)this, a2: other);
  TaoCrypt::Integer::Swap(this: (TaoCrypt::Integer *)&this->m_pElements, a2: other + 4);
  TaoCrypt::Integer::Swap(this: (TaoCrypt::Integer *)this + 8, a2: other + 8);
  TaoCrypt::Integer::Swap(this: (TaoCrypt::Integer *)this + 12, a2: other + 12);
}

//------------------------------------------------------------------------------
// Address: 0x0044B240
// Name: public: void TaoCrypt::DSA_PublicKey::Initialize(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DSA_PublicKey::Initialize(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this@<ecx>,
        const void *source,
        int decoder)
{
  _DWORD v3[2]; // [esp+0h] [ebp-8h] BYREF

  v3[1] = source;
  v3[0] = &TaoCrypt::DSA_Public_Decoder::`vftable';
  TaoCrypt::DSA_Public_Decoder::Decode(
    this: (TaoCrypt::DSA_Public_Decoder *)v3,
    a2: (CInternalFileSystemPassThru<IFileSystem> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0044B270
// Name: public: class TaoCrypt::Integer const __near & TaoCrypt::DSA_PublicKey::GetPublicPart(void)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::DSA_PublicKey *__thiscall TaoCrypt::DSA_PublicKey::GetPublicPart(TaoCrypt::DSA_PublicKey *this)
{
  return this + 4;
}

//------------------------------------------------------------------------------
// Address: 0x0044B280
// Name: public: void TaoCrypt::DSA_PublicKey::SetModulus(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
CInternalFileSystemPassThru<IFileSystem> *__userpurge TaoCrypt::DSA_PublicKey::SetModulus@<eax>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        char *t,
        const char *a3)
{
  return TaoCrypt::Integer::operator=(this, t, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0044B290
// Name: public: void TaoCrypt::DSA_PublicKey::SetSubGroupOrder(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DSA_PublicKey::SetSubGroupOrder(
        TaoCrypt::DSA_PublicKey *this@<ecx>,
        struct TaoCrypt::Integer *a2,
        const char *a3)
{
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 16), t: (char *)a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0044B2A0
// Name: public: void TaoCrypt::DSA_PublicKey::SetSubGroupGenerator(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DSA_PublicKey::SetSubGroupGenerator(
        TaoCrypt::DSA_PublicKey *this@<ecx>,
        struct TaoCrypt::Integer *a2,
        const char *a3)
{
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 32), t: (char *)a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0044B2B0
// Name: public: void TaoCrypt::DSA_PublicKey::SetPublicPart(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DSA_PublicKey::SetPublicPart(
        TaoCrypt::DSA_PublicKey *this@<ecx>,
        struct TaoCrypt::Integer *a2,
        const char *a3)
{
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)this + 4, t: (char *)a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x0044B2C0
// Name: public: unsigned int TaoCrypt::DSA_PublicKey::SignatureLength(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::DSA_PublicKey::SignatureLength(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this)
{
  int *certManager; // eax

  certManager = (int *)yaSSL::Crypto::get_certManager((CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)this);
  TaoCrypt::Integer::ByteCount(this: certManager);
}

//------------------------------------------------------------------------------
// Address: 0x0044B2D0
// Name: public: void TaoCrypt::DSA_PrivateKey::Initialize(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::DSA_PrivateKey::Initialize(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this,
        const void *source)
{
  _DWORD v2[2]; // [esp+0h] [ebp-8h] BYREF

  v2[1] = source;
  v2[0] = &TaoCrypt::DSA_Private_Decoder::`vftable';
  TaoCrypt::DSA_Private_Decoder::Decode(
    this: (TaoCrypt::DSA_Private_Decoder *)v2,
    a2: (CInternalFileSystemPassThru<IFileSystem> *)this);
}

//------------------------------------------------------------------------------
// Address: 0x0044B300
// Name: public: class TaoCrypt::Integer const __near & TaoCrypt::DSA_PrivateKey::GetPrivatePart(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall TaoCrypt::DSA_PrivateKey::GetPrivatePart(char *this)
{
  return this + 64;
}

//------------------------------------------------------------------------------
// Address: 0x0044B310
// Name: public: void TaoCrypt::DSA_PrivateKey::SetPrivatePart(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__userpurge TaoCrypt::DSA_PrivateKey::SetPrivatePart@<eax>(
        int a1@<ecx>,
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *result,
        const char *a3)
{
  return TaoCrypt::Integer::operator=(
           this: (CInternalFileSystemPassThru<IFileSystem> *)(a1 + 64),
           t: (char *)result,
           a3);
}

//------------------------------------------------------------------------------
// Address: 0x0044B330
// Name: public: TaoCrypt::DSA_PublicKey::DSA_PublicKey(class TaoCrypt::DSA_PublicKey const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::DSA_PublicKey::DSA_PublicKey(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *other)
{
  TaoCrypt::Integer::Integer((TaoCrypt::Integer *)this, a2: (const struct TaoCrypt::Integer *)other);
  TaoCrypt::Integer::Integer(
    this: (TaoCrypt::Integer *)&this->m_pElements,
    a2: (const struct TaoCrypt::Integer *)&other->m_pElements);
  TaoCrypt::Integer::Integer(
    this: (TaoCrypt::Integer *)this + 8,
    a2: (const struct TaoCrypt::Integer *)&other[1].m_Size);
  TaoCrypt::Integer::Integer(
    this: (TaoCrypt::Integer *)this + 12,
    a2: (const struct TaoCrypt::Integer *)&other[2].m_Memory.m_nGrowSize);
}

//------------------------------------------------------------------------------
// Address: 0x0044B370
// Name: public: class TaoCrypt::DSA_PublicKey __near & TaoCrypt::DSA_PublicKey::operator=(class TaoCrypt::DSA_PublicKey const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *__thiscall TaoCrypt::DSA_PublicKey::operator=(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this,
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *other)
{
  int v4; // [esp+0h] [ebp-44h]
  CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > v5; // [esp+4h] [ebp-40h] BYREF
  unsigned __int8 *v6; // [esp+18h] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v7; // [esp+1Ch] [ebp-28h] BYREF
  unsigned __int8 *v8; // [esp+28h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v9; // [esp+2Ch] [ebp-18h] BYREF
  unsigned __int8 *v10; // [esp+38h] [ebp-Ch]
  __int64 v11; // [esp+3Ch] [ebp-8h] BYREF

  TaoCrypt::DSA_PublicKey::DSA_PublicKey(this: &v5, other);
  TaoCrypt::DSA_PublicKey::Swap(this, other: (struct TaoCrypt::Integer *)&v5, a3: v4, a4: (int)v5.m_Memory.m_pMemory);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v11,
    p: v10,
    n: v9.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v9, p: v8, n: v7.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v7, p: v6, n: (unsigned int)v5.m_pElements);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v5.m_Memory.m_nGrowSize,
    p: (unsigned __int8 *)v5.m_Memory.m_nAllocationCount,
    n: (unsigned int)v5.m_Memory.m_pMemory);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044B3F0
// Name: public: TaoCrypt::DSA_PublicKey::DSA_PublicKey(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *__thiscall TaoCrypt::DSA_PublicKey::DSA_PublicKey(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this,
        const CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *source)
{
  int v4; // [esp+0h] [ebp-4h]

  TaoCrypt::Integer::Integer((TaoCrypt::Integer *)this);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&this->m_pElements);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 8);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 12);
  TaoCrypt::DSA_PublicKey::Initialize(this, source, decoder: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044B430
// Name: public: TaoCrypt::DSA_Signer::DSA_Signer(class TaoCrypt::DSA_PrivateKey const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::DSA_Signer::DSA_Signer(CFunctor *this, CFunctor_vtbl *key)
{
  this->__vftable = key;
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&this->m_nUserID);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 5);
}

//------------------------------------------------------------------------------
// Address: 0x0044B450
// Name: public: unsigned int TaoCrypt::DSA_Signer::Sign(unsigned char const __near *,unsigned char __near *,class TaoCrypt::RandomNumberGenerator __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::DSA_Signer::Sign(
        CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *this,
        char *sha_digest,
        unsigned __int8 *sig,
        CUtlSymbolTable::CStringPoolIndex *a4)
{
  struct TaoCrypt::Integer *v5; // eax
  struct TaoCrypt::Integer *v6; // ebp
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v7; // ecx
  KeyValues ***certManager; // edi
  yaSSL::SSL_SESSION *v9; // ecx
  char *v10; // ecx
  struct TaoCrypt::Integer *p_m_nAllocationCount; // esi
  char *v12; // eax
  struct TaoCrypt::Integer v13; // eax
  CInternalFileSystemPassThru<IFileSystem> *v14; // ebx
  unsigned int v15; // eax
  unsigned __int8 *v16; // ebp
  unsigned int v17; // edi
  unsigned int v18; // eax
  const char *v20; // [esp+0h] [ebp-88h]
  const char *v21; // [esp+0h] [ebp-88h]
  const char *v22; // [esp+0h] [ebp-88h]
  int *Secret; // [esp+10h] [ebp-78h]
  TaoCrypt::Integer *PrivatePart; // [esp+14h] [ebp-74h]
  CKeyErrorContext k; // [esp+18h] [ebp-70h] BYREF
  unsigned __int8 *v26; // [esp+1Ch] [ebp-6Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v27; // [esp+20h] [ebp-68h] BYREF
  unsigned __int8 *v28; // [esp+2Ch] [ebp-5Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v29; // [esp+30h] [ebp-58h] BYREF
  unsigned __int8 *v30; // [esp+3Ch] [ebp-4Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v31; // [esp+40h] [ebp-48h] BYREF
  unsigned __int8 *v32; // [esp+4Ch] [ebp-3Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v33; // [esp+50h] [ebp-38h] BYREF
  unsigned __int8 *v34; // [esp+5Ch] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v35; // [esp+60h] [ebp-28h] BYREF
  unsigned __int8 *v36; // [esp+6Ch] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v37; // [esp+70h] [ebp-18h] BYREF
  unsigned __int8 *v38; // [esp+7Ch] [ebp-Ch]
  __int64 v39; // [esp+80h] [ebp-8h] BYREF

  yaSSL::sslHashes::get_MD5(this: (ShortVector *)this->m_pMemory);
  v6 = v5;
  certManager = yaSSL::Crypto::get_certManager(this: v7);
  Secret = (int *)yaSSL::SSL_SESSION::GetSecret(this: v9);
  PrivatePart = (TaoCrypt::Integer *)TaoCrypt::DSA_PrivateKey::GetPrivatePart(this: v10);
  TaoCrypt::Integer::Integer(this: (CUtlSymbolTable::CStringPoolIndex *)&v31.m_iRefs, value: 1);
  TaoCrypt::Integer::Integer(this: (CUtlSymbolTable::CStringPoolIndex *)&v29.m_iRefs, value: 1);
  TaoCrypt::Integer::Minus(
    this: (TaoCrypt::Integer *)certManager,
    a2: (TaoCrypt::Integer *)&v27.m_iRefs,
    a3: (struct TaoCrypt::Integer *)&v31.m_iRefs);
  TaoCrypt::Integer::Integer(
    this: (int)&k,
    result: a4,
    a3: (struct TaoCrypt::Integer *)&v29.m_iRefs,
    a4: (TaoCrypt::Integer *)&v27.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v29, p: v28, n: v27.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v31, p: v30, n: v29.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v33, p: v32, n: v31.m_iRefs);
  p_m_nAllocationCount = (struct TaoCrypt::Integer *)&this->m_nAllocationCount;
  v12 = (char *)TaoCrypt::a_exp_b_mod_c(result: (CFunctorData *)&v33.m_iRefs, exponent: Secret, a3: (int)&k, a4: v6);
  TaoCrypt::Integer::operator=(
    this: (CInternalFileSystemPassThru<IFileSystem> *)&this->m_nAllocationCount,
    t: v12,
    a3: v20);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v35, p: v34, n: v33.m_iRefs);
  v13.m_stackLevel = TaoCrypt::Integer::Modulo(
                       this: (TaoCrypt::Integer *)&this->m_nAllocationCount,
                       quotient: (TaoCrypt::Integer *)&v33.m_iRefs,
                       a3: (CInternalFileSystemPassThru<IFileSystem> *)certManager).m_stackLevel;
  TaoCrypt::Integer::operator=(
    this: (CInternalFileSystemPassThru<IFileSystem> *)&this->m_nAllocationCount,
    t: (char *)v13.m_stackLevel,
    a3: v21);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v35, p: v34, n: v33.m_iRefs);
  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&v37.m_iRefs,
    encodedInteger: sha_digest,
    byteCount: 0x14u,
    a4: 0);
  TaoCrypt::Integer::InverseMod(
    this: &k,
    a2: (TaoCrypt::Integer *)&v35.m_iRefs,
    t: (CInternalFileSystemPassThru<IFileSystem> *)certManager);
  TaoCrypt::Integer::Times(
    this: PrivatePart,
    a2: (TaoCrypt::Integer *)&v33.m_iRefs,
    a3: (struct TaoCrypt::Integer *)&this->m_nAllocationCount);
  TaoCrypt::Integer::Plus(
    this: (TaoCrypt::Integer *)&v37.m_iRefs,
    a2: (TaoCrypt::Integer *)&v27.m_iRefs,
    a3: (struct TaoCrypt::Integer *)&v33.m_iRefs);
  TaoCrypt::Integer::Times(
    this: (TaoCrypt::Integer *)&v35.m_iRefs,
    a2: (TaoCrypt::Integer *)&v29.m_iRefs,
    a3: (struct TaoCrypt::Integer *)&v27.m_iRefs);
  TaoCrypt::Integer::Modulo(
    this: (TaoCrypt::Integer *)&v29.m_iRefs,
    quotient: (TaoCrypt::Integer *)&v31.m_iRefs,
    a3: (CInternalFileSystemPassThru<IFileSystem> *)certManager);
  v14 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 20);
  TaoCrypt::Integer::operator=(this: v14, t: (char *)&v31.m_iRefs, a3: v22);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v33, p: v32, n: v31.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v31, p: v30, n: v29.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v29, p: v28, n: v27.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v35, p: v34, n: v33.m_iRefs);
  v15 = TaoCrypt::Integer::ByteCount(this: &p_m_nAllocationCount->m_stackLevel);
  v16 = sig;
  v17 = v15;
  if ( v15 == 19 )
  {
    *sig = 0;
    v16 = sig + 1;
  }
  TaoCrypt::Integer::Encode(a1: p_m_nAllocationCount, a2: (int)v16, a3: v16, a4: v15, a5: 0);
  v18 = TaoCrypt::Integer::ByteCount(this: (int *)v14);
  if ( v18 == 19 )
    (v16++)[v17] = 0;
  TaoCrypt::Integer::Encode(a1: (struct TaoCrypt::Integer *)v14, a2: (int)v16, a3: &v16[v17], a4: v18, a5: 0);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v37, p: v36, n: v35.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v39,
    p: v38,
    n: v37.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v27, p: v26, n: k.m_stackLevel);
  return 40;
}

//------------------------------------------------------------------------------
// Address: 0x0044B6B0
// Name: public: bool TaoCrypt::DSA_Verifier::Verify(unsigned char const __near *,unsigned char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TaoCrypt::DSA_Verifier::Verify(CFunctor *this, CFunctor *sha_digest, char *sig)
{
  struct TaoCrypt::Integer *v4; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *v5; // ecx
  int *certManager; // esi
  yaSSL::SSL_SESSION *v7; // ecx
  TaoCrypt::DSA_PublicKey *v8; // ecx
  unsigned int v9; // ebp
  unsigned int *p_m_nUserID; // ebx
  CInternalFileSystemPassThru<IFileSystem> *v11; // edi
  struct TaoCrypt::Integer *v13; // edi
  struct TaoCrypt::Integer v14; // eax
  bool v15; // bl
  const char *v16; // [esp+0h] [ebp-D0h]
  char v17; // [esp+13h] [ebp-BDh]
  char v18; // [esp+14h] [ebp-BCh]
  CUtlSymbolTable::CStringPoolIndex v19; // [esp+18h] [ebp-B8h] BYREF
  unsigned __int8 *v20; // [esp+1Ch] [ebp-B4h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v21; // [esp+20h] [ebp-B0h] BYREF
  struct TaoCrypt::Integer *v22; // [esp+2Ch] [ebp-A4h]
  char *e1; // [esp+30h] [ebp-A0h]
  CKeyErrorContext v; // [esp+34h] [ebp-9Ch] BYREF
  unsigned __int8 *v25; // [esp+38h] [ebp-98h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v26; // [esp+3Ch] [ebp-94h] BYREF
  unsigned __int8 *v27; // [esp+48h] [ebp-88h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v28; // [esp+4Ch] [ebp-84h] BYREF
  unsigned __int8 *v29; // [esp+58h] [ebp-78h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v30; // [esp+5Ch] [ebp-74h] BYREF
  unsigned __int8 *v31; // [esp+68h] [ebp-68h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v32; // [esp+6Ch] [ebp-64h] BYREF
  unsigned __int8 *v33; // [esp+78h] [ebp-58h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v34; // [esp+7Ch] [ebp-54h] BYREF
  unsigned __int8 *v35; // [esp+88h] [ebp-48h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v36; // [esp+8Ch] [ebp-44h] BYREF
  void **v37; // [esp+98h] [ebp-38h]
  int *p_m_iRefs; // [esp+9Ch] [ebp-34h]
  TaoCrypt::Integer v39; // [esp+A0h] [ebp-30h] BYREF
  unsigned __int8 *v40; // [esp+A4h] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v41; // [esp+A8h] [ebp-28h] BYREF
  unsigned __int8 *v42; // [esp+B4h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v43; // [esp+B8h] [ebp-18h] BYREF
  unsigned __int8 *v44; // [esp+C4h] [ebp-Ch]
  __int64 v45; // [esp+C8h] [ebp-8h] BYREF

  v18 = 0;
  yaSSL::sslHashes::get_MD5(this: (ShortVector *)this->__vftable);
  v22 = v4;
  certManager = (int *)yaSSL::Crypto::get_certManager(this: v5);
  e1 = yaSSL::SSL_SESSION::GetSecret(this: v7);
  v21.m_iRefs = (int)TaoCrypt::DSA_PublicKey::GetPublicPart(this: v8);
  v9 = TaoCrypt::Integer::ByteCount(this: certManager);
  p_m_nUserID = &this->m_nUserID;
  TaoCrypt::Integer::Decode(this: (int)&this->m_nUserID, a2: sig, a3: v9, a4: 0);
  v11 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 20);
  TaoCrypt::Integer::Decode(this: (int)v11, a2: &sig[v9], a3: v9, a4: 0);
  if ( TaoCrypt::Integer::Compare(
         this: (CInternalFileSystemPassThru<IFileSystem> *)p_m_nUserID,
         t: (CInternalFileSystemPassThru<IFileSystem> *)certManager) >= 0
    || (TaoCrypt::Integer::Integer(this: &v19, value: 1),
        v18 = 1,
        TaoCrypt::Integer::Compare(
          this: (CInternalFileSystemPassThru<IFileSystem> *)p_m_nUserID,
          t: (CInternalFileSystemPassThru<IFileSystem> *)&v19) < 0)
    || TaoCrypt::Integer::Compare(this: v11, t: (CInternalFileSystemPassThru<IFileSystem> *)certManager) >= 0
    || (TaoCrypt::Integer::Integer(this: (CUtlSymbolTable::CStringPoolIndex *)&v30.m_iRefs, value: 1),
        v18 = 3,
        v17 = 0,
        TaoCrypt::Integer::Compare(this: v11, t: (CInternalFileSystemPassThru<IFileSystem> *)&v30.m_iRefs) < 0) )
  {
    v17 = 1;
  }
  if ( (v18 & 2) != 0 )
  {
    v18 &= ~2u;
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v32, p: v31, n: v30.m_iRefs);
  }
  if ( (v18 & 1) != 0 )
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v21, p: v20, n: *(_DWORD *)&v19);
  if ( v17 != 0 )
    return false;
  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&v32.m_iRefs,
    encodedInteger: (char *)sha_digest,
    byteCount: 0x14u,
    a4: 0);
  TaoCrypt::Integer::InverseMod(
    this: (TaoCrypt::Integer *)v11,
    a2: (TaoCrypt::Integer *)&v26.m_iRefs,
    t: (CInternalFileSystemPassThru<IFileSystem> *)certManager);
  TaoCrypt::Integer::Times(
    this: (TaoCrypt::Integer *)&v32.m_iRefs,
    a2: (TaoCrypt::Integer *)&v19,
    a3: (struct TaoCrypt::Integer *)&v26.m_iRefs);
  TaoCrypt::Integer::Modulo(
    this: (TaoCrypt::Integer *)&v19,
    quotient: (TaoCrypt::Integer *)&v28.m_iRefs,
    a3: (CInternalFileSystemPassThru<IFileSystem> *)certManager);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v21, p: v20, n: *(_DWORD *)&v19);
  TaoCrypt::Integer::Times(
    this: (TaoCrypt::Integer *)p_m_nUserID,
    a2: (TaoCrypt::Integer *)&v19,
    a3: (struct TaoCrypt::Integer *)&v26.m_iRefs);
  TaoCrypt::Integer::Modulo(
    this: (TaoCrypt::Integer *)&v19,
    quotient: (TaoCrypt::Integer *)&v34.m_iRefs,
    a3: (CInternalFileSystemPassThru<IFileSystem> *)certManager);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v21, p: v20, n: *(_DWORD *)&v19);
  v13 = v22;
  v37 = &TaoCrypt::AbstractRing::MultiplicativeGroupT::`vftable';
  p_m_iRefs = &v36.m_iRefs;
  v36.m_iRefs = (int)&TaoCrypt::ModularArithmetic::`vftable';
  TaoCrypt::Integer::Integer(this: &v39, a2: v22);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v41.m_iRefs, a2: 0, a3: v13->m_stackLevel);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v43.m_iRefs);
  TaoCrypt::ModularArithmetic::CascadeExponentiate(
    this: (IFileSystem *)&v36.m_iRefs,
    x: &v,
    (struct TaoCrypt::Integer *)e1,
    y: (const char *)&v28.m_iRefs,
    a5: (struct TaoCrypt::Integer *)v21.m_iRefs,
    a6: (int)&v34.m_iRefs);
  v14.m_stackLevel = TaoCrypt::Integer::Modulo(
                       this: &v,
                       quotient: (TaoCrypt::Integer *)&v19,
                       a3: (CInternalFileSystemPassThru<IFileSystem> *)certManager).m_stackLevel;
  TaoCrypt::Integer::operator=(
    this: (CInternalFileSystemPassThru<IFileSystem> *)&v,
    t: (char *)v14.m_stackLevel,
    a3: v16);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v21, p: v20, n: *(_DWORD *)&v19);
  v15 = TaoCrypt::Integer::Compare(
          this: (CInternalFileSystemPassThru<IFileSystem> *)p_m_nUserID,
          t: (CInternalFileSystemPassThru<IFileSystem> *)&v) == 0;
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v26, p: v25, n: v.m_stackLevel);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v45,
    p: v44,
    n: v43.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v43, p: v42, n: v41.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v41, p: v40, n: v39.m_stackLevel);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v36, p: v35, n: v34.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v30, p: v29, n: v28.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v28, p: v27, n: v26.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v34, p: v33, n: v32.m_iRefs);
  return v15;
}
