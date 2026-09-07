// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/dh.cpp
// Functions: 4
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\dh.h"

//------------------------------------------------------------------------------
// Address: 0x0044BA70
// Name: private: void TaoCrypt::DH::GeneratePrivate(class TaoCrypt::RandomNumberGenerator __near &,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DH::GeneratePrivate(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this@<ecx>,
        int a2@<ebp>,
        CUtlSymbolTable::CStringPoolIndex *rng,
        unsigned __int8 *priv)
{
  TaoCrypt::_anonymous_namespace_ *v5; // eax
  unsigned int v6; // eax
  const CInternalFileSystemPassThru<IFileSystem> *v7; // ecx
  CInternalFileSystemPassThru<IFileSystem> *v8; // eax
  CInternalFileSystemPassThru<IFileSystem> *v9; // edi
  const CSplitScreenAddedConVar *v10; // ecx
  struct TaoCrypt::Integer *v11; // eax
  unsigned int v12; // eax
  unsigned int v13; // [esp+0h] [ebp-48h]
  CInternalFileSystemPassThru<IFileSystem> v14; // [esp+8h] [ebp-40h] BYREF
  CUtlSymbolTable::CStringPoolIndex v15; // [esp+18h] [ebp-30h] BYREF
  unsigned __int8 *v16; // [esp+1Ch] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v17; // [esp+20h] [ebp-28h] BYREF
  unsigned __int8 *v18; // [esp+2Ch] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v19; // [esp+30h] [ebp-18h] BYREF
  unsigned __int8 *v20; // [esp+3Ch] [ebp-Ch]
  __int64 v21; // [esp+40h] [ebp-8h] BYREF

  TaoCrypt::Integer::Integer(this: &v15, value: 1);
  TaoCrypt::Integer::Minus(
    (TaoCrypt::Integer *)this,
    a2: (TaoCrypt::Integer *)&v14,
    a3: (struct TaoCrypt::Integer *)&v15);
  v5 = (TaoCrypt::_anonymous_namespace_ *)TaoCrypt::Integer::BitCount((int *)this);
  v6 = TaoCrypt::`anonymous namespace'::DiscreteLogWorkFactor(this: v5, a2: v13);
  TaoCrypt::Integer::Power2(e: v7, a2: (TaoCrypt::Integer *)&v19.m_iRefs, ea: 2 * v6);
  v9 = v8;
  if ( TaoCrypt::Integer::Compare(this: &v14, t: v8) < 0 )
    v9 = &v14;
  v11 = (struct TaoCrypt::Integer *)TaoCrypt::Integer::One(this: v10);
  TaoCrypt::Integer::Integer(this: (int)&v17.m_iRefs, result: rng, a3: v11, a4: (TaoCrypt::Integer *)v9);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v14.m_pBaseFileSystemPassThru,
    p: (unsigned __int8 *)v14.IFileSystem::IBaseFileSystem::__vftable,
    n: (unsigned int)v14.IFileSystem::IAppSystem::__vftable);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v21,
    p: v20,
    n: v19.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v17, p: v16, n: *(_DWORD *)&v15);
  v12 = TaoCrypt::Integer::ByteCount((int *)this);
  TaoCrypt::Integer::Encode(a1: (struct TaoCrypt::Integer *)&v17.m_iRefs, a2, a3: priv, a4: v12, a5: 0);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v19, p: v18, n: v17.m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x0044BB50
// Name: private: void TaoCrypt::DH::GeneratePublic(unsigned char const __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DH::GeneratePublic(
        TaoCrypt::DH *this@<ecx>,
        int a2@<ebp>,
        char *encodedInteger,
        unsigned __int8 *a4)
{
  unsigned int v5; // edi
  CFunctorData result; // [esp+8h] [ebp-20h] BYREF
  unsigned __int8 *v7; // [esp+Ch] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v8; // [esp+10h] [ebp-18h] BYREF
  unsigned __int8 *v9; // [esp+1Ch] [ebp-Ch]
  __int64 v10; // [esp+20h] [ebp-8h] BYREF

  v5 = TaoCrypt::Integer::ByteCount((int *)this);
  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&v8.m_iRefs,
    encodedInteger,
    byteCount: v5,
    a4: 0);
  TaoCrypt::a_exp_b_mod_c(
    &result,
    exponent: (int *)this + 4,
    a3: (int)&v8.m_iRefs,
    a4: (struct TaoCrypt::Integer *)this);
  TaoCrypt::Integer::Encode(a1: (struct TaoCrypt::Integer *)&result, a2, a3: a4, a4: v5, a5: 0);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v8, p: v7, n: (unsigned int)result.__vftable);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v10,
    p: v9,
    n: v8.m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x0044BBD0
// Name: public: void TaoCrypt::DH::Agree(unsigned char __near *,unsigned char const __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DH::Agree(
        TaoCrypt::DH *this@<ecx>,
        int a2@<ebp>,
        unsigned __int8 *a3,
        char *encodedInteger,
        char *a5,
        unsigned int a6)
{
  unsigned int v7; // esi
  TaoCrypt::Integer v8; // [esp+8h] [ebp-30h] BYREF
  unsigned __int8 *v9; // [esp+Ch] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v10; // [esp+10h] [ebp-28h] BYREF
  unsigned __int8 *v11; // [esp+1Ch] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v12; // [esp+20h] [ebp-18h] BYREF
  unsigned __int8 *v13; // [esp+2Ch] [ebp-Ch]
  __int64 v14; // [esp+30h] [ebp-8h] BYREF

  v7 = TaoCrypt::Integer::ByteCount((int *)this);
  TaoCrypt::Integer::Integer(
    this: (CUtlSymbolTable::CStringPoolIndex *)&v12.m_iRefs,
    encodedInteger,
    byteCount: v7,
    a4: 0);
  TaoCrypt::Integer::Integer(this: &v8);
  if ( a6 != 0 )
    TaoCrypt::Integer::Decode(this: (int)&v8, a2: a5, a3: a6, a4: 0);
  else
    TaoCrypt::Integer::Decode(this: (int)&v8, a2: a5, a3: v7, a4: 0);
  TaoCrypt::a_exp_b_mod_c(
    result: (CFunctorData *)&v10.m_iRefs,
    exponent: &v8.m_stackLevel,
    a3: (int)&v12.m_iRefs,
    a4: (struct TaoCrypt::Integer *)this);
  TaoCrypt::Integer::Encode(a1: (struct TaoCrypt::Integer *)&v10.m_iRefs, a2, a3, a4: v7, a5: 0);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v12, p: v11, n: v10.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v10, p: v9, n: v8.m_stackLevel);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v14,
    p: v13,
    n: v12.m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x0044BC90
// Name: public: void TaoCrypt::DH::GenerateKeyPair(class TaoCrypt::RandomNumberGenerator __near &,unsigned char __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::DH::GenerateKeyPair(
        CUtlVector<unsigned short,CUtlMemory<unsigned short,int> > *this@<ecx>,
        int a2@<ebp>,
        CUtlSymbolTable::CStringPoolIndex *rng,
        unsigned __int8 *priv,
        unsigned __int8 *pub)
{
  TaoCrypt::DH::GeneratePrivate(this, a2, rng, priv);
  TaoCrypt::DH::GeneratePublic((TaoCrypt::DH *)this, a2, encodedInteger: (char *)priv, a4: pub);
}
