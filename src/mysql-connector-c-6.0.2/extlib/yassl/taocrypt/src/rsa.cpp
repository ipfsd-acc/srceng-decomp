// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/rsa.cpp
// Functions: 11
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\rsa.h"

//------------------------------------------------------------------------------
// Address: 0x00425770
// Name: public: class TaoCrypt::RSA_PublicKey __near & TaoCrypt::RSA_PublicKey::operator=(class TaoCrypt::RSA_PublicKey const __near &)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::RSA_PublicKey::operator=(TaoCrypt::Integer *this, struct TaoCrypt::Integer *a2)
{
  struct TaoCrypt::Integer v4; // [esp+8h] [ebp-20h] BYREF
  unsigned __int8 *v5; // [esp+Ch] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v6; // [esp+10h] [ebp-18h] BYREF
  unsigned __int8 *v7; // [esp+1Ch] [ebp-Ch]
  __int64 v8; // [esp+20h] [ebp-8h] BYREF

  TaoCrypt::Integer::Integer(this: &v4, a2);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v6.m_iRefs, a2: a2 + 4);
  TaoCrypt::Integer::Swap(this, a2: &v4);
  TaoCrypt::Integer::Swap(this: this + 4, a2: (struct TaoCrypt::Integer *)&v6.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v8,
    p: v7,
    n: v6.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v6, p: v5, n: v4.m_stackLevel);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044BCC0
// Name: public: void TaoCrypt::RSA_PublicKey::Initialize(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
tagTLIBATTR *__userpurge TaoCrypt::RSA_PublicKey::Initialize@<eax>(tagTLIBATTR *a1@<ecx>, const void *source, int a3)
{
  return TaoCrypt::RSA_Public_Decoder::Decode(result: a1);
}

//------------------------------------------------------------------------------
// Address: 0x0044BCF0
// Name: public: void TaoCrypt::RSA_PrivateKey::Initialize(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::RSA_PrivateKey::Initialize(
        CInternalFileSystemPassThru<IFileSystem> *this,
        struct TaoCrypt::Source *a2)
{
  _DWORD v2[2]; // [esp+0h] [ebp-8h] BYREF

  v2[1] = a2;
  v2[0] = &TaoCrypt::RSA_Private_Decoder::`vftable';
  TaoCrypt::RSA_Private_Decoder::Decode(this: (TaoCrypt::RSA_Private_Decoder *)v2, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x0044BD20
// Name: public: void TaoCrypt::RSA_BlockType2::Pad(unsigned char const __near *,unsigned int,unsigned char __near *,unsigned int,class TaoCrypt::RandomNumberGenerator __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::RSA_BlockType2::Pad(
        TaoCrypt::RSA_BlockType2 *this,
        unsigned __int8 *src,
        unsigned int count,
        unsigned __int8 *a4,
        unsigned int a5,
        struct TaoCrypt::RandomNumberGenerator *a6)
{
  unsigned __int8 *v6; // esi
  unsigned int v7; // edi
  unsigned int i; // eax
  unsigned __int8 *v9; // [esp-Ch] [ebp-1Ch]

  v6 = a4;
  if ( (a5 & 7) != 0 )
  {
    *a4 = 0;
    v6 = a4 + 1;
  }
  v7 = (a5 >> 3) - count - 1;
  *v6 = 2;
  TaoCrypt::RandomNumberGenerator::GenerateBlock(this: (TaoCrypt::RandomNumberGenerator *)a6, output: v6 + 1, a3: v7);
  for ( i = 1; i < v7; ++i )
  {
    if ( v6[i] == 0 )
      v6[i] = 1;
  }
  v9 = &v6[(a5 >> 3) - count];
  *(v9 - 1) = 0;
  memcpy(dst: v9, src, count);
}

//------------------------------------------------------------------------------
// Address: 0x0044BD90
// Name: public: void TaoCrypt::RSA_BlockType1::Pad(unsigned char const __near *,unsigned int,unsigned char __near *,unsigned int,class TaoCrypt::RandomNumberGenerator __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::RSA_BlockType1::Pad(
        TaoCrypt::RSA_BlockType1 *this,
        const LoggingContext_t *input,
        unsigned int inputLen,
        unsigned __int8 *pkcsBlock,
        unsigned int pkcsBlockLen,
        struct TaoCrypt::RandomNumberGenerator *a6)
{
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // [esp-18h] [ebp-24h]

  v6 = pkcsBlock;
  if ( (pkcsBlockLen & 7) != 0 )
  {
    *pkcsBlock = 0;
    v6 = pkcsBlock + 1;
  }
  *v6 = 1;
  memset(dst: v6 + 1, value: 0xFFu, count: (pkcsBlockLen >> 3) - inputLen - 2);
  v7 = &v6[(pkcsBlockLen >> 3) - inputLen];
  *(v7 - 1) = 0;
  memcpy(dst: v7, src: (unsigned __int8 *)input, count: inputLen);
}

//------------------------------------------------------------------------------
// Address: 0x0044BDF0
// Name: public: class TaoCrypt::Integer TaoCrypt::RSA_PublicKey::ApplyFunction(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer __thiscall TaoCrypt::RSA_PublicKey::ApplyFunction(
        TaoCrypt::RSA_PublicKey *this,
        CFunctorData *result,
        int *a3)
{
  struct TaoCrypt::Integer *v4; // [esp+0h] [ebp-8h]

  TaoCrypt::a_exp_b_mod_c(result, exponent: a3, a3: (int)(this + 4), a4: v4);
  return (struct TaoCrypt::Integer)result;
}

//------------------------------------------------------------------------------
// Address: 0x0044BE10
// Name: public: TaoCrypt::RSA_PublicKey::RSA_PublicKey(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::RSA_PublicKey *__thiscall TaoCrypt::RSA_PublicKey::RSA_PublicKey(
        TaoCrypt::RSA_PublicKey *this,
        struct TaoCrypt::Source *source)
{
  int v4; // [esp+0h] [ebp-4h]

  TaoCrypt::Integer::Integer((TaoCrypt::Integer *)this);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 4);
  TaoCrypt::RSA_PublicKey::Initialize(a1: (tagTLIBATTR *)this, source, a3: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0044BE40
// Name: public: class TaoCrypt::Integer TaoCrypt::RSA_PrivateKey::CalculateInverse(class TaoCrypt::RandomNumberGenerator __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::RSA_PrivateKey::CalculateInverse(
        CUtlVector<CCountedStringPoolBase<unsigned int>::hash_item_t,CUtlMemory<CCountedStringPoolBase<unsigned int>::hash_item_t,int> > *this,
        TaoCrypt::Integer *rng,
        CUtlSymbolTable::CStringPoolIndex *a3,
        char *b)
{
  const CSplitScreenAddedConVar *v5; // ecx
  struct TaoCrypt::Integer *v6; // eax
  const CSplitScreenAddedConVar *v7; // ecx
  struct TaoCrypt::Integer *v8; // eax
  char *v9; // eax
  int *v10; // edi
  int v11; // eax
  char *v12; // eax
  char *v14; // [esp+4h] [ebp-74h]
  const char *v15; // [esp+4h] [ebp-74h]
  const char *v16; // [esp+4h] [ebp-74h]
  int v17; // [esp+8h] [ebp-70h]
  CKeyErrorContext re; // [esp+Ch] [ebp-6Ch] BYREF
  unsigned __int8 *v19; // [esp+10h] [ebp-68h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v20; // [esp+14h] [ebp-64h] BYREF
  unsigned __int8 *v21; // [esp+20h] [ebp-58h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v22; // [esp+24h] [ebp-54h] BYREF
  unsigned __int8 *v23; // [esp+30h] [ebp-48h]
  int v24; // [esp+34h] [ebp-44h] BYREF
  CUtlVector<int,CUtlMemory<int,int> > v25; // [esp+3Ch] [ebp-3Ch] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v26; // [esp+50h] [ebp-28h] BYREF
  unsigned __int8 *v27; // [esp+5Ch] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v28; // [esp+60h] [ebp-18h] BYREF
  unsigned __int8 *v29; // [esp+6Ch] [ebp-Ch]
  __int64 v30; // [esp+70h] [ebp-8h] BYREF

  v25.m_Memory.m_nAllocationCount = (int)&TaoCrypt::AbstractRing::MultiplicativeGroupT::`vftable';
  v25.m_Memory.m_nGrowSize = (int)&v25;
  v25.m_Memory.m_pMemory = (int *)&TaoCrypt::ModularArithmetic::`vftable';
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v25.m_Size, a2: (const struct TaoCrypt::Integer *)this);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v26.m_iRefs, a2: 0, a3: (unsigned int)this->m_Memory.m_pMemory);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v28.m_iRefs);
  v6 = (struct TaoCrypt::Integer *)TaoCrypt::Integer::One(this: v5);
  TaoCrypt::Integer::Minus((TaoCrypt::Integer *)this, a2: (TaoCrypt::Integer *)&v22.m_iRefs, a3: v6);
  v8 = (struct TaoCrypt::Integer *)TaoCrypt::Integer::One(this: v7);
  TaoCrypt::Integer::Integer(this: (int)&v20.m_iRefs, result: a3, a3: v8, a4: (TaoCrypt::Integer *)&v22.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v24,
    p: v23,
    n: v22.m_iRefs);
  TaoCrypt::AbstractRing::Exponentiate(this: &v25, base: &re, exponent: &v20.m_iRefs, a4: (int)&this->m_pElements);
  v9 = (char *)TaoCrypt::ModularArithmetic::Multiply(
                 this: (IFileSystem *)&v25,
                 a: &re,
                 (struct TaoCrypt::Integer *)b,
                 a4: v14,
                 a5: v17,
                 a6: (PathTypeFilter_t)re.m_stackLevel,
                 a7: (unsigned int *)v19);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)&re, t: v9, a3: v15);
  TaoCrypt::ModularRoot(
    a: (FileWarningLevel_t)((char *)this + 64),
    a2: rng,
    a3: &re,
    a4: (int)this + 96,
    a5: (int)(this + 4),
    a6: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 64),
    a7: (CInternalFileSystemPassThru<IFileSystem> *)this + 4,
    a8: (TaoCrypt::Integer *)this + 28);
  v10 = v25.m_Memory.m_pMemory + 15;
  v11 = (*((int (__thiscall **)(CUtlVector<int,CUtlMemory<int,int> > *, int *))v25.m_Memory.m_pMemory + 16))(
          a1: &v25,
          a2: &v20.m_iRefs);
  v12 = (char *)((int (__thiscall *)(CUtlVector<int,CUtlMemory<int,int> > *, TaoCrypt::Integer *, int))*v10)(
                  a1: &v25,
                  a2: rng,
                  a3: v11);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)rng, t: v12, a3: v16);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v20, p: v19, n: re.m_stackLevel);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v22, p: v21, n: v20.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v30,
    p: v29,
    n: v28.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v28, p: v27, n: v26.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v26, p: (unsigned __int8 *)v25.m_pElements, n: v25.m_Size);
  return rng;
}

//------------------------------------------------------------------------------
// Address: 0x0044BFC0
// Name: public: unsigned int TaoCrypt::RSA_BlockType2::UnPad(unsigned char const __near *,unsigned int,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::RSA_BlockType2::UnPad(
        TaoCrypt::RSA_BlockType2 *this,
        const LoggingContext_t *pkcsBlock,
        unsigned int pkcsBlockLen,
        unsigned __int8 *output)
{
  unsigned int v4; // ecx
  bool v5; // al
  unsigned int v6; // ebp
  const LoggingContext_t *v7; // edi
  bool v8; // dl
  unsigned int v9; // eax
  char v10; // bl
  unsigned int v11; // ecx
  unsigned int v12; // esi

  v4 = pkcsBlockLen >> 3;
  v5 = false;
  if ( pkcsBlockLen >> 3 <= 0xA )
    v6 = 0;
  else
    v6 = v4 - 10;
  v7 = pkcsBlock;
  if ( (pkcsBlockLen & 7) != 0 )
  {
    v5 = LOBYTE(pkcsBlock->m_ChannelID) != 0;
    v7 = (const LoggingContext_t *)((char *)&pkcsBlock->m_ChannelID + 1);
  }
  v8 = LOBYTE(v7->m_ChannelID) != 2 || v5;
  v9 = 1;
  do
  {
    if ( v9 >= v4 )
      break;
    v10 = *((_BYTE *)&v7->m_ChannelID + v9++);
  }
  while ( v10 != 0 );
  v11 = v4 - v9;
  v12 = v11;
  if ( v11 > v6 || v8 )
    return 0;
  memcpy(dst: output, src: (unsigned __int8 *)v7 + v9, count: v11);
  return v12;
}

//------------------------------------------------------------------------------
// Address: 0x0044C040
// Name: public: unsigned int TaoCrypt::RSA_BlockType1::UnPad(unsigned char const __near *,unsigned int,unsigned char __near *)const
// Source: json
//------------------------------------------------------------------------------
CUtlFilenameSymbolTable::FileNameHandleInternal_t *__stdcall TaoCrypt::RSA_BlockType1::UnPad(
        const LoggingContext_t *result,
        unsigned int pkcsBlockLen,
        unsigned __int8 *output)
{
  unsigned int v3; // ecx
  bool v4; // al
  unsigned int v5; // ebp
  CUtlFilenameSymbolTable::FileNameHandleInternal_t *v6; // edi
  bool v7; // dl
  unsigned int v8; // eax
  char v9; // bl
  unsigned int v10; // ecx
  unsigned int v11; // esi

  v3 = pkcsBlockLen >> 3;
  v4 = false;
  if ( pkcsBlockLen >> 3 <= 0xA )
    v5 = 0;
  else
    v5 = v3 - 10;
  v6 = (CUtlFilenameSymbolTable::FileNameHandleInternal_t *)result;
  if ( (pkcsBlockLen & 7) != 0 )
  {
    v4 = LOBYTE(result->m_ChannelID) != 0;
    v6 = (CUtlFilenameSymbolTable::FileNameHandleInternal_t *)((char *)&result->m_ChannelID + 1);
  }
  v7 = LOBYTE(v6->value) != 1 || v4;
  v8 = 1;
  do
  {
    if ( v8 >= v3 )
      break;
    v9 = *((_BYTE *)&v6->value + v8++);
  }
  while ( v9 != 0 );
  v10 = v3 - v8;
  v11 = v10;
  if ( v10 > v5 || v7 )
    return nullptr;
  memcpy(dst: output, src: (unsigned __int8 *)v6 + v8, count: v10);
  return (CUtlFilenameSymbolTable::FileNameHandleInternal_t *)v11;
}

//------------------------------------------------------------------------------
// Address: 0x0044C0C0
// Name: unsigned int TaoCrypt::SSL_Decrypt(class TaoCrypt::RSA_PublicKey const __near &,unsigned char const __near *,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
CUtlFilenameSymbolTable::FileNameHandleInternal_t *__usercall TaoCrypt::SSL_Decrypt@<eax>(
        int a1@<ebp>,
        TaoCrypt::RSA_PublicKey *this,
        const struct TaoCrypt::RSA_PublicKey *encodedInteger,
        unsigned __int8 *a4)
{
  const CSplitScreenAddedConVar *v4; // ecx
  const CSplitScreenAddedConVar *v5; // esi
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // edi
  unsigned int v8; // eax
  int *v9; // eax
  const CSplitScreenAddedConVar *v10; // ecx
  char *v11; // eax
  unsigned int v12; // eax
  CUtlFilenameSymbolTable::FileNameHandleInternal_t *v13; // ebx
  const char *v15; // [esp+0h] [ebp-2Ch]
  CInternalFileSystemPassThru<IFileSystem> v16; // [esp+Ch] [ebp-20h] BYREF
  CUtlSymbolTable::CStringPoolIndex v17; // [esp+1Ch] [ebp-10h] BYREF
  unsigned __int8 *v18; // [esp+20h] [ebp-Ch]
  __int64 v19; // [esp+24h] [ebp-8h] BYREF

  v5 = (const CSplitScreenAddedConVar *)((TaoCrypt::Integer::BitCount((int *)this) + 6) >> 3);
  if ( v5 != nullptr )
    v6 = (unsigned __int8 *)operator new[](sz: v4, sza: v5);
  else
    v6 = nullptr;
  v7 = (unsigned __int8 *)TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: (int)&v16.m_pBaseFileSystemPassThru,
                            src: v6,
                            a3: (unsigned int)v5,
                            count: (unsigned int)v5,
                            a5: 0);
  memset(dst: v7, value: 0, count: (unsigned int)v5);
  v8 = TaoCrypt::Integer::ByteCount((int *)this);
  TaoCrypt::Integer::Integer(this: &v17, (char *)encodedInteger, byteCount: v8, a4: 0);
  TaoCrypt::RSA_PublicKey::ApplyFunction(this, result: (CFunctorData *)&v16, a3: v9);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v19,
    p: v18,
    n: *(_DWORD *)&v17);
  if ( TaoCrypt::Integer::ByteCount(this: (int *)&v16) > (unsigned int)v5 )
  {
    v11 = (char *)TaoCrypt::Integer::Zero(this: v10);
    TaoCrypt::Integer::operator=(this: &v16, t: v11, a3: v15);
  }
  TaoCrypt::Integer::Encode(a1: (struct TaoCrypt::Integer *)&v16, a2: a1, a3: v7, a4: (unsigned int)v5, a5: 0);
  v12 = TaoCrypt::Integer::BitCount((int *)this);
  v13 = TaoCrypt::RSA_BlockType1::UnPad(result: (const LoggingContext_t *)v7, pkcsBlockLen: v12 - 1, output: a4);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v16.m_pBaseFileSystemPassThru,
    p: (unsigned __int8 *)v16.IFileSystem::IBaseFileSystem::__vftable,
    n: (unsigned int)v16.IFileSystem::IAppSystem::__vftable);
  memset(dst: v7, value: 0, count: (unsigned int)v5);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v7);
  return v13;
}
