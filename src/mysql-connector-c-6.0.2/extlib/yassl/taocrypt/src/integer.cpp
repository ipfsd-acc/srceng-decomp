// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/integer.cpp
// Functions: 163
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\integer.h"

//------------------------------------------------------------------------------
// Address: 0x00416AA0
// Name: unsigned char __near * TaoCrypt::StdReallocate<unsigned char,class TaoCrypt::AllocatorWithCleanup<unsigned char>>(class TaoCrypt::AllocatorWithCleanup<unsigned char> __near &,unsigned char __near *,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
CSplitScreenAddedConVar *__cdecl TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
        int a1,
        unsigned __int8 *src,
        unsigned int a3,
        unsigned int count,
        char a5)
{
  const CSplitScreenAddedConVar *v5; // ecx
  unsigned int v6; // esi
  unsigned __int8 *v8; // edi

  v6 = count;
  if ( a3 == count )
    return (CSplitScreenAddedConVar *)src;
  if ( a5 != 0 )
  {
    if ( count != 0 )
    {
      v8 = (unsigned __int8 *)operator new[](sz: v5);
      if ( a3 < count )
        v6 = a3;
    }
    else
    {
      v8 = nullptr;
    }
    memcpy(dst: v8, src, count: v6);
    memset(dst: src, value: 0, count: a3);
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: src);
    return (CSplitScreenAddedConVar *)v8;
  }
  else
  {
    memset(dst: src, value: 0, count: a3);
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: src);
    if ( count != 0 )
      return operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc);
    else
      return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00416CE0
// Name: public: TaoCrypt::Block<unsigned char,class TaoCrypt::AllocatorWithCleanup<unsigned char>>::Block<unsigned char,class TaoCrypt::AllocatorWithCleanup<unsigned char>>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Block<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>::Block<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
        ConVarRef *this,
        IConVar *s)
{
  CSplitScreenAddedConVar *v2; // eax
  IConVar *m_pConVar; // edi
  CSplitScreenAddedConVar *v5; // eax
  IConVar *v6; // [esp-Ch] [ebp-14h]

  v2 = (CSplitScreenAddedConVar *)s;
  this->m_pConVar = s;
  if ( s != nullptr )
    v2 = operator new[](sz: (const CSplitScreenAddedConVar *)TaoCrypt::tc);
  m_pConVar = this->m_pConVar;
  v6 = this->m_pConVar;
  this->m_pConVarState = v2;
  v5 = TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
         a1: (int)(this + 1),
         src: (unsigned __int8 *)v2,
         a3: (unsigned int)v6,
         count: (unsigned int)m_pConVar,
         a5: 0);
  this->m_pConVarState = v5;
  this->m_pConVar = m_pConVar;
  memset(dst: (unsigned __int8 *)v5, value: 0, count: (unsigned int)m_pConVar);
}

//------------------------------------------------------------------------------
// Address: 0x0041B9A0
// Name: public: virtual bool TaoCrypt::ModularArithmetic::IsMontgomeryRepresentation(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TaoCrypt::ModularArithmetic::IsMontgomeryRepresentation(ConVar *this)
{
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00424A90
// Name: public: class yaSSL::Integer __near & yaSSL::Integer::operator=(class yaSSL::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge yaSSL::Integer::operator=(IMemAlloc *this@<ecx>, const char **that, const char *a3)
{
  const char *v3; // [esp+0h] [ebp-4h]

  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)this->__vftable, t: *that, a3: v3);
}

//------------------------------------------------------------------------------
// Address: 0x00426350
// Name: void yaSSL::ysDelete<struct yaSSL::Integer::IntegerImpl>(struct yaSSL::Integer::IntegerImpl __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl yaSSL::ysDelete<yaSSL::Integer::IntegerImpl>(CFunctorCallback0 *result)
{
  KeyValues *v1; // ecx

  if ( result != nullptr )
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&result->m_iRefs);
  operator delete(ptr: v1, ptra: result);
}

//------------------------------------------------------------------------------
// Address: 0x0043BC20
// Name: void TaoCrypt::CopyWords(unsigned int __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TaoCrypt::CopyWords(TaoCrypt *this, unsigned int *a2, const unsigned int *n)
{
  const unsigned int *v3; // edx
  TaoCrypt *v4; // eax

  v3 = n;
  if ( n != nullptr )
  {
    v4 = this;
    do
    {
      *(_DWORD *)v4 = *(_DWORD *)((char *)v4 + (char *)a2 - (char *)this);
      v4 = (TaoCrypt *)((char *)v4 + 4);
      v3 = (const unsigned int *)((char *)v3 - 1);
    }
    while ( v3 != nullptr );
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BC50
// Name: unsigned int TaoCrypt::ShiftWordsLeftByBits(unsigned int __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ShiftWordsLeftByBits(void *r, unsigned int *ra, unsigned int n, unsigned int shiftBits)
{
  char v4; // cl
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // ebp
  unsigned int v8; // edx

  v4 = shiftBits;
  v5 = 0;
  if ( shiftBits != 0 )
  {
    v6 = 0;
    if ( n != 0 )
    {
      while ( 1 )
      {
        v7 = ra[v6] << v4;
        v8 = ra[v6++] >> (32 - shiftBits);
        ra[v6 - 1] = v5 | v7;
        v5 = v8;
        if ( v6 >= n )
          break;
        v4 = shiftBits;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BCA0
// Name: unsigned int TaoCrypt::ShiftWordsRightByBits(unsigned int __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ShiftWordsRightByBits(void *r, unsigned int *ra, unsigned int n, unsigned int shiftBits)
{
  char v4; // cl
  unsigned int v5; // eax
  int v6; // esi
  unsigned int v7; // ebp
  unsigned int v8; // edx

  v4 = shiftBits;
  v5 = 0;
  if ( shiftBits != 0 )
  {
    v6 = n - 1;
    if ( (int)(n - 1) >= 0 )
    {
      while ( 1 )
      {
        v7 = ra[v6] >> v4;
        v8 = ra[v6--] << (32 - shiftBits);
        ra[v6 + 1] = v5 | v7;
        v5 = v8;
        if ( v6 < 0 )
          break;
        v4 = shiftBits;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BCF0
// Name: void TaoCrypt::ShiftWordsRightByWords(unsigned int __near *,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TaoCrypt::ShiftWordsRightByWords(TaoCrypt *this, unsigned int *a2, unsigned int a3)
{
  unsigned int v3; // ecx
  unsigned int v4; // edx
  TaoCrypt *v5; // eax
  _DWORD *v6; // esi

  v3 = a3;
  if ( a3 >= (unsigned int)a2 )
    v3 = (unsigned int)a2;
  if ( v3 != 0 )
  {
    if ( v3 < (unsigned int)a2 )
    {
      v4 = v3;
      v5 = this;
      v6 = (_DWORD *)((char *)this + 4 * v3);
      do
      {
        *(_DWORD *)v5 = *v6;
        ++v4;
        v5 = (TaoCrypt *)((char *)v5 + 4);
        ++v6;
      }
      while ( v4 < (unsigned int)a2 );
    }
    memset((char *)this + 4 * ((_DWORD)a2 - v3), 0, 4 * v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BD40
// Name: public: virtual bool TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::AbstractRing::MultiplicativeGroupT::Equal(
        CLoggingSystem *this@<ecx>,
        unsigned __int8 *cipher,
        const LoggingContext_t *plain)
{
  (*(void (__thiscall **)(int, unsigned __int8 *))(*(_DWORD *)this->m_RegisteredChannels[0].m_ID + 4))(
    a1: this->m_RegisteredChannels[0].m_ID,
    a2: cipher);
}

//------------------------------------------------------------------------------
// Address: 0x0043BD50
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::AbstractRing::MultiplicativeGroupT::Identity(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::Identity(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        const int *a2)
{
  return (*(bool (__thiscall **)(int, const int *))(*(_DWORD *)this->m_Memory.m_nAllocationCount + 56))(
           a1: this->m_Memory.m_nAllocationCount,
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x0043BD60
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::AbstractRing::MultiplicativeGroupT::Add(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::Add(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        const int *a)
{
  return (*(bool (__thiscall **)(int, const int *))(*(_DWORD *)this->m_Memory.m_nAllocationCount + 60))(
           a1: this->m_Memory.m_nAllocationCount,
           a2: a);
}

//------------------------------------------------------------------------------
// Address: 0x0043BD70
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::AbstractRing::MultiplicativeGroupT::Inverse(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
const struct TaoCrypt::Integer *__thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::Inverse(
        TaoCrypt::AbstractRing::MultiplicativeGroupT *this,
        const struct TaoCrypt::Integer *a2)
{
  return (*(const struct TaoCrypt::Integer *(__thiscall **)(_DWORD, const struct TaoCrypt::Integer *))(**((_DWORD **)this + 1) + 64))(
           a1: *((_DWORD *)this + 1),
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x0043BD80
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::AbstractRing::MultiplicativeGroupT::Subtract(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::Subtract(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        const int *a)
{
  return (*(bool (__thiscall **)(int, const int *))(*(_DWORD *)this->m_Memory.m_nAllocationCount + 72))(
           a1: this->m_Memory.m_nAllocationCount,
           a2: a);
}

//------------------------------------------------------------------------------
// Address: 0x0043BD90
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::AbstractRing::MultiplicativeGroupT::Double(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
const struct TaoCrypt::Integer *__thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::Double(
        TaoCrypt::AbstractRing::MultiplicativeGroupT *this,
        const struct TaoCrypt::Integer *a2)
{
  return (*(const struct TaoCrypt::Integer *(__thiscall **)(_DWORD, const struct TaoCrypt::Integer *))(**((_DWORD **)this + 1) + 68))(
           a1: *((_DWORD *)this + 1),
           a2);
}

//------------------------------------------------------------------------------
// Address: 0x0043BDA0
// Name: public: virtual void TaoCrypt::AbstractRing::MultiplicativeGroupT::SimultaneousMultiply(class TaoCrypt::Integer __near *,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::SimultaneousMultiply(
        TaoCrypt::AbstractRing::MultiplicativeGroupT *this,
        struct TaoCrypt::Integer *a2,
        const struct TaoCrypt::Integer *a3,
        const struct TaoCrypt::Integer *a4,
        unsigned int a5)
{
  (*(void (__thiscall **)(_DWORD, struct TaoCrypt::Integer *, const struct TaoCrypt::Integer *, const struct TaoCrypt::Integer *, unsigned int))(**((_DWORD **)this + 1) + 84))(
    a1: *((_DWORD *)this + 1),
    a2,
    a3,
    a4,
    a5);
}

//------------------------------------------------------------------------------
// Address: 0x0043BDB0
// Name: public: virtual void TaoCrypt::MontgomeryRepresentation::SimultaneousExponentiate(class TaoCrypt::Integer __near *,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall TaoCrypt::MontgomeryRepresentation::SimultaneousExponentiate(
        IFileSystem *this,
        CUtlVector<int,CUtlMemory<int,int> > *results,
        void **base,
        const struct TaoCrypt::Integer *exponents,
        unsigned int exponentsCount)
{
  TaoCrypt::AbstractRing::SimultaneousExponentiate(
    (TaoCrypt::AbstractRing *)this,
    result: results,
    a3: (const struct TaoCrypt::Integer *)base,
    a4: exponents,
    a5: exponentsCount);
}

//------------------------------------------------------------------------------
// Address: 0x0043BDC0
// Name: TaoCrypt::RoundupSize
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043BE10
// Name: TaoCrypt::Compare
// Source: json
//------------------------------------------------------------------------------
int __usercall TaoCrypt::Compare@<eax>(
        int a1@<eax>,
        int a2@<ecx>,
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *result)
{
  int v3; // esi
  int v4; // eax
  char *v5; // edi
  unsigned int v6; // ecx
  unsigned int v7; // edx

  v3 = a1;
  if ( a1 == 0 )
    return 0;
  v4 = a2 + 4 * a1;
  v5 = (char *)result - a2;
  while ( 1 )
  {
    v6 = *(_DWORD *)&v5[v4 - 4];
    v7 = *(_DWORD *)(v4 - 4);
    v4 -= 4;
    --v3;
    if ( v6 > v7 )
      return 1;
    if ( v6 < v7 )
      break;
    if ( v3 == 0 )
      return 0;
  }
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0043BE50
// Name: TaoCrypt::Increment
// Source: json
//------------------------------------------------------------------------------
void __usercall TaoCrypt::Increment(unsigned int *A@<ecx>, int a2@<edx>, unsigned int a3@<esi>)
{
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int i; // eax

  v3 = *A;
  v4 = *A + a2;
  *A = v4;
  if ( v4 < v3 )
  {
    for ( i = 1; i < a3; ++i )
    {
      if ( A[i]++ != -1 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BE80
// Name: TaoCrypt::Decrement
// Source: json
//------------------------------------------------------------------------------
void __usercall TaoCrypt::Decrement(unsigned int *A@<edx>, unsigned int a2@<esi>, unsigned int B)
{
  unsigned int v3; // ecx
  unsigned int v4; // eax
  unsigned int i; // eax
  unsigned int v6; // ecx

  v3 = *A;
  v4 = *A - B;
  *A = v4;
  if ( v4 > v3 )
  {
    for ( i = 1; i < a2; ++i )
    {
      v6 = A[i];
      A[i] = v6 - 1;
      if ( v6 != 0 )
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043BEC0
// Name: TaoCrypt::TwosComplement
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall TaoCrypt::TwosComplement@<eax>(unsigned int a1@<eax>, unsigned int *a2@<edx>)
{
  int v3; // edx
  unsigned int result; // eax

  TaoCrypt::Decrement(A: a2, a2: a1, B: 1u);
  for ( result = 0; result < a1; ++result )
    *(_DWORD *)(v3 + 4 * result) = ~*(_DWORD *)(v3 + 4 * result);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BEF0
// Name: TaoCrypt::AtomicInverseModPower2
// Source: json
//------------------------------------------------------------------------------
int __fastcall TaoCrypt::AtomicInverseModPower2(int a1, int a2)
{
  int result; // eax
  unsigned int i; // ecx

  result = a2 & 7;
  for ( i = 3; i < 0x20; i *= 2 )
    result *= 2 - a2 * result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BF20
// Name: public: static unsigned int TaoCrypt::Portable::Add(unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static unsigned int __cdecl TaoCrypt::Portable::Add(unsigned int *C, char *a2, char *a3, unsigned int N)
{
  unsigned int result; // eax
  unsigned int *v5; // edi
  int v6; // eax
  const unsigned int *v7; // ecx
  unsigned int v8; // ebx
  unsigned __int64 v9; // kr10_8
  unsigned int v10; // [esp+10h] [ebp-4h]

  result = 0;
  v10 = 0;
  if ( N != 0 )
  {
    v5 = C;
    v6 = a2 - (char *)C;
    v7 = (const unsigned int *)(a3 + 4);
    v8 = ((N - 1) >> 1) + 1;
    while ( 1 )
    {
      v9 = v10 + *(v7 - 1) + (unsigned __int64)*(unsigned int *)((char *)v5 + v6);
      *v5 = v9;
      result = (HIDWORD(v9) + (unsigned __int64)*(const unsigned int *)((char *)v7 + a2 - a3) + *v7) >> 32;
      *(const unsigned int *)((char *)v7 + (char *)C - a3) = HIDWORD(v9)
                                                           + *(const unsigned int *)((char *)v7 + a2 - a3)
                                                           + *v7;
      v7 += 2;
      v5 += 2;
      --v8;
      v10 = result;
      if ( v8 == 0 )
        break;
      v6 = a2 - (char *)C;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043BFB0
// Name: public: static unsigned int TaoCrypt::Portable::Subtract(unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl TaoCrypt::Portable::Subtract(unsigned int *C, char *a2, char *a3, unsigned int N)
{
  int v4; // eax
  unsigned int *v5; // edi
  int v6; // eax
  const unsigned int *v7; // edx
  unsigned int v8; // ebx
  unsigned __int64 v9; // kr00_8
  int v11; // [esp+10h] [ebp-4h]

  v4 = 0;
  v11 = 0;
  if ( N != 0 )
  {
    v5 = C;
    v6 = a2 - (char *)C;
    v7 = (const unsigned int *)(a3 + 4);
    v8 = ((N - 1) >> 1) + 1;
    while ( 1 )
    {
      v9 = *(unsigned int *)((char *)v5 + v6) - (unsigned __int64)*(v7 - 1);
      *v5 = v9 + v11;
      v4 = (*(const unsigned int *)((char *)v7 + a2 - a3)
          - (unsigned __int64)((unsigned int)((unsigned int)v9 < -v11) - HIDWORD(v9))
          - *v7) >> 32;
      *(const unsigned int *)((char *)v7 + (char *)C - a3) = *(const unsigned int *)((char *)v7 + a2 - a3)
                                                           - (((unsigned int)v9 < -v11)
                                                            - HIDWORD(v9))
                                                           - *v7;
      v7 += 2;
      v5 += 2;
      --v8;
      v11 = v4;
      if ( v8 == 0 )
        break;
      v6 = a2 - (char *)C;
    }
  }
  return -v4;
}

//------------------------------------------------------------------------------
// Address: 0x0043C050
// Name: public: static void TaoCrypt::Portable::Multiply2(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlSymbolTable::CStringPoolIndex *__thiscall TaoCrypt::Portable::Multiply2(
        unsigned __int16 C,
        unsigned int *Ca,
        unsigned int *a3,
        unsigned int *a4)
{
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // edi
  unsigned int v8; // ebx
  unsigned int v9; // eax
  BOOL v10; // ebx
  bool v11; // cf
  int v12; // esi
  unsigned __int64 v14; // kr08_8
  unsigned __int64 v15; // [esp+10h] [ebp-28h]
  unsigned __int64 v16; // [esp+18h] [ebp-20h]
  unsigned int v17; // [esp+24h] [ebp-14h]
  unsigned int v18; // [esp+28h] [ebp-10h]
  unsigned int v19; // [esp+2Ch] [ebp-Ch]
  unsigned int v20; // [esp+30h] [ebp-8h]
  unsigned int v21; // [esp+34h] [ebp-4h]

  v4 = a3[1];
  v5 = *a3;
  v18 = v4 - *a3;
  v19 = v5 - v4;
  v6 = a4[1];
  v7 = *a4;
  v8 = *a4 - v6;
  v9 = v6 - *a4;
  v20 = v8;
  v10 = v4 < v5;
  v11 = v7 < a4[1];
  v21 = v9;
  v12 = *(&v18 + (v10 && v11)) * *(&v20 + (v10 && v11));
  v17 = (*(&v18 + (v10 && v11)) * (unsigned __int64)*(&v20 + (v10 && v11))) >> 32;
  v21 = 0;
  v19 = 0;
  v15 = v5 * (unsigned __int64)v7;
  *Ca = v15;
  v16 = a3[1] * (unsigned __int64)a4[1];
  v14 = HIDWORD(v15) + (unsigned int)v15 + a3[1] * a4[1] + (unsigned __int64)(unsigned int)v12;
  Ca[1] = v14;
  *((_QWORD *)Ca + 1) = v16 + HIDWORD(v15) + v17 + HIDWORD(v14) - (unsigned __int64)*(&v18 + v10 + !v11) + HIDWORD(v16);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0043C130
// Name: public: static void TaoCrypt::Portable::Multiply2Bottom(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlSymbolTable::CStringPoolIndex *__thiscall TaoCrypt::Portable::Multiply2Bottom(
        unsigned __int16 C,
        unsigned int *Ca,
        unsigned int *a3,
        unsigned int *a4)
{
  unsigned int v4; // kr00_4
  __int64 v5; // kr08_8
  const CUtlSymbolTable::CStringPoolIndex *result; // eax

  v4 = *a4;
  v5 = *a3;
  *Ca = *a4 * *a3;
  result = (const CUtlSymbolTable::CStringPoolIndex *)((__PAIR64__(a4[1], v4) * v5) >> 32);
  Ca[1] = (unsigned int)result + *a4 * a3[1];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C160
// Name: public: static unsigned int TaoCrypt::Portable::Multiply2Add(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
static int __cdecl TaoCrypt::Portable::Multiply2Add(unsigned int *C, unsigned int *a2, unsigned int *bi)
{
  unsigned int v3; // edx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  unsigned int v6; // esi
  unsigned int v7; // edi
  BOOL v8; // ebp
  bool v9; // cf
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr00_8
  unsigned __int64 v12; // kr10_8
  unsigned __int64 v13; // kr20_8
  unsigned __int64 v14; // kr28_8
  unsigned __int64 v16; // [esp+10h] [ebp-30h]
  unsigned __int64 v17; // [esp+18h] [ebp-28h]
  unsigned int v18; // [esp+30h] [ebp-10h]
  unsigned int v19; // [esp+34h] [ebp-Ch]
  unsigned int v20; // [esp+38h] [ebp-8h]
  unsigned int v21; // [esp+3Ch] [ebp-4h]

  v3 = a2[1];
  v4 = *a2;
  v18 = v3 - *a2;
  v19 = v4 - v3;
  v5 = bi[1];
  v6 = *bi;
  v7 = *bi - v5;
  v8 = v3 < v4;
  v9 = *bi < v5;
  v21 = v5 - *bi;
  v20 = v7;
  v17 = *(&v18 + (v8 && v9)) * (unsigned __int64)*(&v20 + (v8 && v9));
  v21 = 0;
  v19 = 0;
  v10 = v4 * (unsigned __int64)v6;
  v11 = v10 + *C;
  *C = v11;
  v16 = a2[1] * (unsigned __int64)bi[1];
  v12 = (unsigned int)v16 + (unsigned int)v17 + (unsigned int)v10 + HIDWORD(v11) + (unsigned __int64)C[1];
  C[1] = v12;
  v13 = (unsigned int)v16
      + HIDWORD(v16)
      + HIDWORD(v12)
      + HIDWORD(v17)
      + HIDWORD(v10)
      - (unsigned __int64)*(&v18 + v8 + !v9)
      + C[2];
  C[2] = v13;
  v14 = HIDWORD(v13) + (unsigned __int64)C[3];
  C[3] = HIDWORD(v16) + v14;
  return __CFADD__(HIDWORD(v16), (_DWORD)v14) + HIDWORD(v14);
}

//------------------------------------------------------------------------------
// Address: 0x0043C270
// Name: TaoCrypt::HasSSE2
// Source: json
//------------------------------------------------------------------------------
char TaoCrypt::HasSSE2()
{
  TaoCrypt *v3; // [esp+0h] [ebp-38h]
  unsigned int *v4; // [esp+0h] [ebp-38h]
  unsigned int v5[4]; // [esp+10h] [ebp-28h] BYREF
  CPPEH_RECORD ms_exc; // [esp+20h] [ebp-18h]

  if ( !TaoCrypt::IsPentium(this: v3) )
    return 0;
  TaoCrypt::CpuId(this: (TaoCrypt *)1, a2: (unsigned int)v5, a3: v4);
  if ( (v5[3] & 0x4000000) == 0 )
    return 0;
  __asm { xorpd   xmm0, xmm0 }
  ms_exc.registration.TryLevel = -2;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0043C310
// Name: TaoCrypt::IsP4
// Source: json
//------------------------------------------------------------------------------
bool TaoCrypt::IsP4()
{
  bool result; // al
  unsigned int v1[4]; // [esp+0h] [ebp-10h] BYREF

  result = TaoCrypt::IsPentium(this: (TaoCrypt *)v1[0]);
  if ( result )
  {
    TaoCrypt::CpuId(this: (TaoCrypt *)1, a2: (unsigned int)v1, a3: (unsigned int *)v1[0]);
    return (v1[0] & 0xF00) == 3840;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C350
// Name: public: static unsigned int TaoCrypt::PentiumOptimized::Add(unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::PentiumOptimized::Add(void *C, int a2, unsigned int *Ca, int a4, int a5)
{
  unsigned int *v5; // edx
  int v6; // ecx
  int v7; // ebx
  bool v8; // cf
  int i; // eax
  unsigned int v10; // esi
  unsigned int v11; // ebp
  int v12; // edi
  unsigned int v13; // esi
  BOOL v14; // ett
  int v15; // edi
  unsigned int v16; // ebp
  BOOL v17; // ett

  v5 = Ca;
  v6 = a2 - (_DWORD)Ca;
  v7 = a4 + 4 * a5;
  v8 = -(char)a5 & 1;
  for ( i = -a5 >> 1; i != 0; *(unsigned int *)((char *)v5 + v6 - 4) = v15 + v16 )
  {
    v10 = *v5;
    v11 = v5[1];
    v12 = *(_DWORD *)(v7 + 8 * i);
    v5 += 2;
    v14 = v8;
    v8 = __CFADD__(v8, v10);
    v13 = v14 + v10;
    v8 |= __CFADD__(v12, v13);
    v13 += v12;
    v15 = *(_DWORD *)(v7 + 8 * i + 4);
    v17 = v8;
    v8 = __CFADD__(v8, v11);
    v16 = v17 + v11;
    v8 |= __CFADD__(v15, v16);
    ++i;
    *(unsigned int *)((char *)v5 + v6 - 8) = v13;
  }
  return v8 + i;
}

//------------------------------------------------------------------------------
// Address: 0x0043C3A0
// Name: public: static unsigned int TaoCrypt::PentiumOptimized::Subtract(unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::PentiumOptimized::Subtract(void *C, int a2, unsigned int *Ca, int a4, int a5)
{
  unsigned int *v5; // edx
  int v6; // ecx
  int v7; // ebx
  char v8; // cf
  int i; // eax
  unsigned int v10; // esi
  unsigned int v11; // ebp
  unsigned int v12; // esi
  unsigned int v13; // ett
  unsigned int v14; // ett

  v5 = Ca;
  v6 = a2 - (_DWORD)Ca;
  v7 = a4 + 4 * a5;
  v8 = -(char)a5 & 1;
  for ( i = -a5 >> 1; i != 0; *(unsigned int *)((char *)v5 + v6 - 4) = v11 - v14 )
  {
    v10 = *v5;
    v11 = v5[1];
    v5 += 2;
    v13 = v8 + *(_DWORD *)(v7 + 8 * i);
    v8 = v10 < v13;
    v12 = v10 - v13;
    v14 = v8 + *(_DWORD *)(v7 + 8 * i + 4);
    v8 = v11 < v14;
    ++i;
    *(unsigned int *)((char *)v5 + v6 - 8) = v12;
  }
  return v8 + i;
}

//------------------------------------------------------------------------------
// Address: 0x0043C3F0
// Name: public: static unsigned int TaoCrypt::P4Optimized::Add(unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::P4Optimized::Add(void *C, _DWORD *A, unsigned int *Ca, int *a4, int a5)
{
  unsigned int *v6; // edx
  int *v7; // ebx
  int result; // eax
  int v9; // esi
  unsigned int v10; // edi
  int v11; // ebp
  unsigned int v12; // edi
  bool v13; // cf
  unsigned int v14; // edi
  int v15; // ebp
  int v16; // edi
  int v17; // edi

  v6 = Ca;
  v7 = a4;
  result = 0;
  v9 = -a5;
  if ( a5 != 0 )
  {
    v10 = *Ca;
    v11 = *a4;
    while ( 1 )
    {
      v13 = __CFADD__(v11, v10);
      *A = v11 + v10;
      v14 = v6[1];
      if ( v13 )
        result = 1;
      v15 = v7[1];
      v7 += 2;
      v13 = __CFADD__(result, v14);
      v16 = result + v14;
      if ( !v13 )
        result = 0;
      v13 = __CFADD__(v15, v16);
      v17 = v15 + v16;
      if ( v13 )
        result = 1;
      A[1] = v17;
      v9 += 2;
      if ( v9 == 0 )
        break;
      v12 = v6[2];
      A += 2;
      v6 += 2;
      v11 = *v7;
      v13 = __CFADD__(result, v12);
      v10 = result + v12;
      if ( !v13 )
        result = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C460
// Name: public: static unsigned int TaoCrypt::P4Optimized::Subtract(unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::P4Optimized::Subtract(void *C, _DWORD *A, unsigned int *Ca, unsigned int *a4, int a5)
{
  unsigned int *v6; // edx
  unsigned int *v7; // ebx
  unsigned int result; // eax
  int v9; // esi
  unsigned int v10; // edi
  unsigned int v11; // ebp
  unsigned int v12; // edi
  bool v13; // cf
  unsigned int v14; // edi
  unsigned int v15; // ebp
  unsigned int v16; // edi
  unsigned int v17; // edi

  v6 = Ca;
  v7 = a4;
  result = 0;
  v9 = -a5;
  if ( a5 != 0 )
  {
    v10 = *Ca;
    v11 = *a4;
    while ( 1 )
    {
      v13 = v10 < v11;
      *A = v10 - v11;
      v14 = v6[1];
      if ( v13 )
        result = 1;
      v15 = v7[1];
      v7 += 2;
      v13 = v14 < result;
      v16 = v14 - result;
      if ( !v13 )
        result = 0;
      v13 = v16 < v15;
      v17 = v16 - v15;
      if ( v13 )
        result = 1;
      A[1] = v17;
      v9 += 2;
      if ( v9 == 0 )
        break;
      v12 = v6[2];
      v6 += 2;
      A += 2;
      v11 = *v7;
      v13 = v12 < result;
      v10 = v12 - result;
      if ( !v13 )
        result = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043C4D0
// Name: public: static void TaoCrypt::PentiumOptimized::Multiply4(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl TaoCrypt::PentiumOptimized::Multiply4(
        unsigned int *a1,
        const unsigned int *a2,
        const unsigned int *a3)
{
  unsigned int v3; // edx
  unsigned int v4; // ebp
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // kr00_8
  unsigned int v7; // ebx
  unsigned __int64 v8; // rax
  unsigned int v9; // edi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr10_8
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // kr18_8
  unsigned __int64 v15; // rax
  unsigned int v16; // edi
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // kr28_8
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // kr30_8
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // kr38_8
  unsigned __int64 v24; // rax
  unsigned int v25; // edi
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // kr48_8
  unsigned int v28; // ebx
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // kr50_8
  unsigned __int64 v31; // rax
  unsigned int v32; // edi
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // kr60_8
  unsigned int v35; // ebx
  unsigned __int64 v36; // rax

  v3 = (*a2 * (unsigned __int64)*a3) >> 32;
  *a1 = *a2 * *a3;
  v4 = v3;
  v5 = a2[1] * (unsigned __int64)*a3;
  v6 = v5 + v4;
  v7 = __CFADD__(v5, v4);
  v8 = *a2 * (unsigned __int64)a3[1];
  v9 = (v8 + v6) >> 32;
  LOBYTE(v7) = BYTE1(v7) + __CFADD__(v8, v6) + v7;
  a1[1] = v8 + v6;
  v10 = a2[2] * (unsigned __int64)*a3;
  v11 = v10 + __PAIR64__(v7, v9);
  v12 = __CFADD__(v10, __PAIR64__(v7, v9));
  v13 = a2[1] * (unsigned __int64)a3[1];
  v14 = v13 + v11;
  LOBYTE(v12) = BYTE1(v12) + __CFADD__(v13, v11) + v12;
  v15 = *a2 * (unsigned __int64)a3[2];
  v16 = (v15 + v14) >> 32;
  LOBYTE(v12) = BYTE1(v12) + __CFADD__(v15, v14) + v12;
  a1[2] = v15 + v14;
  v17 = a2[3] * (unsigned __int64)*a3;
  v18 = v17 + __PAIR64__(v12, v16);
  v19 = __CFADD__(v17, __PAIR64__(v12, v16));
  v20 = a2[2] * (unsigned __int64)a3[1];
  v21 = v20 + v18;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v20, v18) + v19;
  v22 = a2[1] * (unsigned __int64)a3[2];
  v23 = v22 + v21;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v22, v21) + v19;
  v24 = *a2 * (unsigned __int64)a3[3];
  v25 = (v24 + v23) >> 32;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v24, v23) + v19;
  a1[3] = v24 + v23;
  v26 = a2[3] * (unsigned __int64)a3[1];
  v27 = v26 + __PAIR64__(v19, v25);
  v28 = __CFADD__(v26, __PAIR64__(v19, v25));
  v29 = a2[2] * (unsigned __int64)a3[2];
  v30 = v29 + v27;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v29, v27) + v28;
  v31 = a2[1] * (unsigned __int64)a3[3];
  v32 = (v31 + v30) >> 32;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v31, v30) + v28;
  a1[4] = v31 + v30;
  v33 = a2[3] * (unsigned __int64)a3[2];
  v34 = v33 + __PAIR64__(v28, v32);
  v35 = __CFADD__(v33, __PAIR64__(v28, v32));
  v36 = a2[2] * (unsigned __int64)a3[3];
  LOBYTE(v35) = BYTE1(v35) + __CFADD__(v36, v34) + v35;
  a1[5] = v36 + v34;
  *((_QWORD *)a1 + 3) = a2[3] * (unsigned __int64)a3[3] + __PAIR64__(v35, (v36 + v34) >> 32);
}

//------------------------------------------------------------------------------
// Address: 0x0043C600
// Name: public: static void TaoCrypt::PentiumOptimized::Multiply8(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl TaoCrypt::PentiumOptimized::Multiply8(
        unsigned int *a1,
        const unsigned int *a2,
        const unsigned int *a3)
{
  unsigned int v3; // edx
  unsigned int v4; // ebp
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // kr00_8
  unsigned int v7; // ebx
  unsigned __int64 v8; // rax
  unsigned int v9; // edi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr10_8
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // kr18_8
  unsigned __int64 v15; // rax
  unsigned int v16; // edi
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // kr28_8
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // kr30_8
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // kr38_8
  unsigned __int64 v24; // rax
  unsigned int v25; // edi
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // kr48_8
  unsigned int v28; // ebx
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // kr50_8
  unsigned __int64 v31; // rax
  unsigned __int64 v32; // kr58_8
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // kr60_8
  unsigned __int64 v35; // rax
  unsigned int v36; // edi
  unsigned __int64 v37; // rax
  unsigned __int64 v38; // kr70_8
  unsigned int v39; // ebx
  unsigned __int64 v40; // rax
  unsigned __int64 v41; // kr78_8
  unsigned __int64 v42; // rax
  unsigned __int64 v43; // kr80_8
  unsigned __int64 v44; // rax
  unsigned __int64 v45; // kr88_8
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // kr90_8
  unsigned __int64 v48; // rax
  unsigned int v49; // edi
  unsigned __int64 v50; // rax
  unsigned __int64 v51; // krA0_8
  unsigned int v52; // ebx
  unsigned __int64 v53; // rax
  unsigned __int64 v54; // krA8_8
  unsigned __int64 v55; // rax
  unsigned __int64 v56; // krB0_8
  unsigned __int64 v57; // rax
  unsigned __int64 v58; // krB8_8
  unsigned __int64 v59; // rax
  unsigned __int64 v60; // krC0_8
  unsigned __int64 v61; // rax
  unsigned __int64 v62; // krC8_8
  unsigned __int64 v63; // rax
  unsigned int v64; // edi
  unsigned __int64 v65; // rax
  unsigned __int64 v66; // krD8_8
  unsigned int v67; // ebx
  unsigned __int64 v68; // rax
  unsigned __int64 v69; // krE0_8
  unsigned __int64 v70; // rax
  unsigned __int64 v71; // krE8_8
  unsigned __int64 v72; // rax
  unsigned __int64 v73; // krF0_8
  unsigned __int64 v74; // rax
  unsigned __int64 v75; // krF8_8
  unsigned __int64 v76; // rax
  unsigned __int64 v77; // kr100_8
  unsigned __int64 v78; // rax
  unsigned __int64 v79; // kr108_8
  unsigned __int64 v80; // rax
  unsigned int v81; // edi
  unsigned __int64 v82; // rax
  unsigned __int64 v83; // kr118_8
  unsigned int v84; // ebx
  unsigned __int64 v85; // rax
  unsigned __int64 v86; // kr120_8
  unsigned __int64 v87; // rax
  unsigned __int64 v88; // kr128_8
  unsigned __int64 v89; // rax
  unsigned __int64 v90; // kr130_8
  unsigned __int64 v91; // rax
  unsigned __int64 v92; // kr138_8
  unsigned __int64 v93; // rax
  unsigned __int64 v94; // kr140_8
  unsigned __int64 v95; // rax
  unsigned int v96; // edi
  unsigned __int64 v97; // rax
  unsigned __int64 v98; // kr150_8
  unsigned int v99; // ebx
  unsigned __int64 v100; // rax
  unsigned __int64 v101; // kr158_8
  unsigned __int64 v102; // rax
  unsigned __int64 v103; // kr160_8
  unsigned __int64 v104; // rax
  unsigned __int64 v105; // kr168_8
  unsigned __int64 v106; // rax
  unsigned __int64 v107; // kr170_8
  unsigned __int64 v108; // rax
  unsigned int v109; // edi
  unsigned __int64 v110; // rax
  unsigned __int64 v111; // kr180_8
  unsigned int v112; // ebx
  unsigned __int64 v113; // rax
  unsigned __int64 v114; // kr188_8
  unsigned __int64 v115; // rax
  unsigned __int64 v116; // kr190_8
  unsigned __int64 v117; // rax
  unsigned __int64 v118; // kr198_8
  unsigned __int64 v119; // rax
  unsigned int v120; // edi
  unsigned __int64 v121; // rax
  unsigned __int64 v122; // kr1A8_8
  unsigned int v123; // ebx
  unsigned __int64 v124; // rax
  unsigned __int64 v125; // kr1B0_8
  unsigned __int64 v126; // rax
  unsigned __int64 v127; // kr1B8_8
  unsigned __int64 v128; // rax
  unsigned int v129; // edi
  unsigned __int64 v130; // rax
  unsigned __int64 v131; // kr1C8_8
  unsigned int v132; // ebx
  unsigned __int64 v133; // rax
  unsigned __int64 v134; // kr1D0_8
  unsigned __int64 v135; // rax
  unsigned int v136; // edi
  unsigned __int64 v137; // rax
  unsigned __int64 v138; // kr1E0_8
  unsigned int v139; // ebx
  unsigned __int64 v140; // rax

  v3 = (*a2 * (unsigned __int64)*a3) >> 32;
  *a1 = *a2 * *a3;
  v4 = v3;
  v5 = a2[1] * (unsigned __int64)*a3;
  v6 = v5 + v4;
  v7 = __CFADD__(v5, v4);
  v8 = *a2 * (unsigned __int64)a3[1];
  v9 = (v8 + v6) >> 32;
  LOBYTE(v7) = BYTE1(v7) + __CFADD__(v8, v6) + v7;
  a1[1] = v8 + v6;
  v10 = a2[2] * (unsigned __int64)*a3;
  v11 = v10 + __PAIR64__(v7, v9);
  v12 = __CFADD__(v10, __PAIR64__(v7, v9));
  v13 = a2[1] * (unsigned __int64)a3[1];
  v14 = v13 + v11;
  LOBYTE(v12) = BYTE1(v12) + __CFADD__(v13, v11) + v12;
  v15 = *a2 * (unsigned __int64)a3[2];
  v16 = (v15 + v14) >> 32;
  LOBYTE(v12) = BYTE1(v12) + __CFADD__(v15, v14) + v12;
  a1[2] = v15 + v14;
  v17 = a2[3] * (unsigned __int64)*a3;
  v18 = v17 + __PAIR64__(v12, v16);
  v19 = __CFADD__(v17, __PAIR64__(v12, v16));
  v20 = a2[2] * (unsigned __int64)a3[1];
  v21 = v20 + v18;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v20, v18) + v19;
  v22 = a2[1] * (unsigned __int64)a3[2];
  v23 = v22 + v21;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v22, v21) + v19;
  v24 = *a2 * (unsigned __int64)a3[3];
  v25 = (v24 + v23) >> 32;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v24, v23) + v19;
  a1[3] = v24 + v23;
  v26 = a2[4] * (unsigned __int64)*a3;
  v27 = v26 + __PAIR64__(v19, v25);
  v28 = __CFADD__(v26, __PAIR64__(v19, v25));
  v29 = a2[3] * (unsigned __int64)a3[1];
  v30 = v29 + v27;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v29, v27) + v28;
  v31 = a2[2] * (unsigned __int64)a3[2];
  v32 = v31 + v30;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v31, v30) + v28;
  v33 = a2[1] * (unsigned __int64)a3[3];
  v34 = v33 + v32;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v33, v32) + v28;
  v35 = *a2 * (unsigned __int64)a3[4];
  v36 = (v35 + v34) >> 32;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v35, v34) + v28;
  a1[4] = v35 + v34;
  v37 = a2[5] * (unsigned __int64)*a3;
  v38 = v37 + __PAIR64__(v28, v36);
  v39 = __CFADD__(v37, __PAIR64__(v28, v36));
  v40 = a2[4] * (unsigned __int64)a3[1];
  v41 = v40 + v38;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v40, v38) + v39;
  v42 = a2[3] * (unsigned __int64)a3[2];
  v43 = v42 + v41;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v42, v41) + v39;
  v44 = a2[2] * (unsigned __int64)a3[3];
  v45 = v44 + v43;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v44, v43) + v39;
  v46 = a2[1] * (unsigned __int64)a3[4];
  v47 = v46 + v45;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v46, v45) + v39;
  v48 = *a2 * (unsigned __int64)a3[5];
  v49 = (v48 + v47) >> 32;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v48, v47) + v39;
  a1[5] = v48 + v47;
  v50 = a2[6] * (unsigned __int64)*a3;
  v51 = v50 + __PAIR64__(v39, v49);
  v52 = __CFADD__(v50, __PAIR64__(v39, v49));
  v53 = a2[5] * (unsigned __int64)a3[1];
  v54 = v53 + v51;
  LOBYTE(v52) = BYTE1(v52) + __CFADD__(v53, v51) + v52;
  v55 = a2[4] * (unsigned __int64)a3[2];
  v56 = v55 + v54;
  LOBYTE(v52) = BYTE1(v52) + __CFADD__(v55, v54) + v52;
  v57 = a2[3] * (unsigned __int64)a3[3];
  v58 = v57 + v56;
  LOBYTE(v52) = BYTE1(v52) + __CFADD__(v57, v56) + v52;
  v59 = a2[2] * (unsigned __int64)a3[4];
  v60 = v59 + v58;
  LOBYTE(v52) = BYTE1(v52) + __CFADD__(v59, v58) + v52;
  v61 = a2[1] * (unsigned __int64)a3[5];
  v62 = v61 + v60;
  LOBYTE(v52) = BYTE1(v52) + __CFADD__(v61, v60) + v52;
  v63 = *a2 * (unsigned __int64)a3[6];
  v64 = (v63 + v62) >> 32;
  LOBYTE(v52) = BYTE1(v52) + __CFADD__(v63, v62) + v52;
  a1[6] = v63 + v62;
  v65 = a2[7] * (unsigned __int64)*a3;
  v66 = v65 + __PAIR64__(v52, v64);
  v67 = __CFADD__(v65, __PAIR64__(v52, v64));
  v68 = a2[6] * (unsigned __int64)a3[1];
  v69 = v68 + v66;
  LOBYTE(v67) = BYTE1(v67) + __CFADD__(v68, v66) + v67;
  v70 = a2[5] * (unsigned __int64)a3[2];
  v71 = v70 + v69;
  LOBYTE(v67) = BYTE1(v67) + __CFADD__(v70, v69) + v67;
  v72 = a2[4] * (unsigned __int64)a3[3];
  v73 = v72 + v71;
  LOBYTE(v67) = BYTE1(v67) + __CFADD__(v72, v71) + v67;
  v74 = a2[3] * (unsigned __int64)a3[4];
  v75 = v74 + v73;
  LOBYTE(v67) = BYTE1(v67) + __CFADD__(v74, v73) + v67;
  v76 = a2[2] * (unsigned __int64)a3[5];
  v77 = v76 + v75;
  LOBYTE(v67) = BYTE1(v67) + __CFADD__(v76, v75) + v67;
  v78 = a2[1] * (unsigned __int64)a3[6];
  v79 = v78 + v77;
  LOBYTE(v67) = BYTE1(v67) + __CFADD__(v78, v77) + v67;
  v80 = *a2 * (unsigned __int64)a3[7];
  v81 = (v80 + v79) >> 32;
  LOBYTE(v67) = BYTE1(v67) + __CFADD__(v80, v79) + v67;
  a1[7] = v80 + v79;
  v82 = a2[7] * (unsigned __int64)a3[1];
  v83 = v82 + __PAIR64__(v67, v81);
  v84 = __CFADD__(v82, __PAIR64__(v67, v81));
  v85 = a2[6] * (unsigned __int64)a3[2];
  v86 = v85 + v83;
  LOBYTE(v84) = BYTE1(v84) + __CFADD__(v85, v83) + v84;
  v87 = a2[5] * (unsigned __int64)a3[3];
  v88 = v87 + v86;
  LOBYTE(v84) = BYTE1(v84) + __CFADD__(v87, v86) + v84;
  v89 = a2[4] * (unsigned __int64)a3[4];
  v90 = v89 + v88;
  LOBYTE(v84) = BYTE1(v84) + __CFADD__(v89, v88) + v84;
  v91 = a2[3] * (unsigned __int64)a3[5];
  v92 = v91 + v90;
  LOBYTE(v84) = BYTE1(v84) + __CFADD__(v91, v90) + v84;
  v93 = a2[2] * (unsigned __int64)a3[6];
  v94 = v93 + v92;
  LOBYTE(v84) = BYTE1(v84) + __CFADD__(v93, v92) + v84;
  v95 = a2[1] * (unsigned __int64)a3[7];
  v96 = (v95 + v94) >> 32;
  LOBYTE(v84) = BYTE1(v84) + __CFADD__(v95, v94) + v84;
  a1[8] = v95 + v94;
  v97 = a2[7] * (unsigned __int64)a3[2];
  v98 = v97 + __PAIR64__(v84, v96);
  v99 = __CFADD__(v97, __PAIR64__(v84, v96));
  v100 = a2[6] * (unsigned __int64)a3[3];
  v101 = v100 + v98;
  LOBYTE(v99) = BYTE1(v99) + __CFADD__(v100, v98) + v99;
  v102 = a2[5] * (unsigned __int64)a3[4];
  v103 = v102 + v101;
  LOBYTE(v99) = BYTE1(v99) + __CFADD__(v102, v101) + v99;
  v104 = a2[4] * (unsigned __int64)a3[5];
  v105 = v104 + v103;
  LOBYTE(v99) = BYTE1(v99) + __CFADD__(v104, v103) + v99;
  v106 = a2[3] * (unsigned __int64)a3[6];
  v107 = v106 + v105;
  LOBYTE(v99) = BYTE1(v99) + __CFADD__(v106, v105) + v99;
  v108 = a2[2] * (unsigned __int64)a3[7];
  v109 = (v108 + v107) >> 32;
  LOBYTE(v99) = BYTE1(v99) + __CFADD__(v108, v107) + v99;
  a1[9] = v108 + v107;
  v110 = a2[7] * (unsigned __int64)a3[3];
  v111 = v110 + __PAIR64__(v99, v109);
  v112 = __CFADD__(v110, __PAIR64__(v99, v109));
  v113 = a2[6] * (unsigned __int64)a3[4];
  v114 = v113 + v111;
  LOBYTE(v112) = BYTE1(v112) + __CFADD__(v113, v111) + v112;
  v115 = a2[5] * (unsigned __int64)a3[5];
  v116 = v115 + v114;
  LOBYTE(v112) = BYTE1(v112) + __CFADD__(v115, v114) + v112;
  v117 = a2[4] * (unsigned __int64)a3[6];
  v118 = v117 + v116;
  LOBYTE(v112) = BYTE1(v112) + __CFADD__(v117, v116) + v112;
  v119 = a2[3] * (unsigned __int64)a3[7];
  v120 = (v119 + v118) >> 32;
  LOBYTE(v112) = BYTE1(v112) + __CFADD__(v119, v118) + v112;
  a1[10] = v119 + v118;
  v121 = a2[7] * (unsigned __int64)a3[4];
  v122 = v121 + __PAIR64__(v112, v120);
  v123 = __CFADD__(v121, __PAIR64__(v112, v120));
  v124 = a2[6] * (unsigned __int64)a3[5];
  v125 = v124 + v122;
  LOBYTE(v123) = BYTE1(v123) + __CFADD__(v124, v122) + v123;
  v126 = a2[5] * (unsigned __int64)a3[6];
  v127 = v126 + v125;
  LOBYTE(v123) = BYTE1(v123) + __CFADD__(v126, v125) + v123;
  v128 = a2[4] * (unsigned __int64)a3[7];
  v129 = (v128 + v127) >> 32;
  LOBYTE(v123) = BYTE1(v123) + __CFADD__(v128, v127) + v123;
  a1[11] = v128 + v127;
  v130 = a2[7] * (unsigned __int64)a3[5];
  v131 = v130 + __PAIR64__(v123, v129);
  v132 = __CFADD__(v130, __PAIR64__(v123, v129));
  v133 = a2[6] * (unsigned __int64)a3[6];
  v134 = v133 + v131;
  LOBYTE(v132) = BYTE1(v132) + __CFADD__(v133, v131) + v132;
  v135 = a2[5] * (unsigned __int64)a3[7];
  v136 = (v135 + v134) >> 32;
  LOBYTE(v132) = BYTE1(v132) + __CFADD__(v135, v134) + v132;
  a1[12] = v135 + v134;
  v137 = a2[7] * (unsigned __int64)a3[6];
  v138 = v137 + __PAIR64__(v132, v136);
  v139 = __CFADD__(v137, __PAIR64__(v132, v136));
  v140 = a2[6] * (unsigned __int64)a3[7];
  LOBYTE(v139) = BYTE1(v139) + __CFADD__(v140, v138) + v139;
  a1[13] = v140 + v138;
  *((_QWORD *)a1 + 7) = a2[7] * (unsigned __int64)a3[7] + __PAIR64__(v139, (v140 + v138) >> 32);
}

//------------------------------------------------------------------------------
// Address: 0x0043C9E0
// Name: public: static void TaoCrypt::PentiumOptimized::Multiply8Bottom(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl TaoCrypt::PentiumOptimized::Multiply8Bottom(
        unsigned int *a1,
        const unsigned int *a2,
        const unsigned int *a3)
{
  unsigned int v3; // edx
  unsigned int v4; // ebp
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // kr00_8
  unsigned int v7; // ebx
  unsigned __int64 v8; // rax
  unsigned int v9; // edi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr10_8
  unsigned int v12; // ebx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // kr18_8
  unsigned __int64 v15; // rax
  unsigned int v16; // edi
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // kr28_8
  unsigned int v19; // ebx
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // kr30_8
  unsigned __int64 v22; // rax
  unsigned __int64 v23; // kr38_8
  unsigned __int64 v24; // rax
  unsigned int v25; // edi
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // kr48_8
  unsigned int v28; // ebx
  unsigned __int64 v29; // rax
  unsigned __int64 v30; // kr50_8
  unsigned __int64 v31; // rax
  unsigned __int64 v32; // kr58_8
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // kr60_8
  unsigned __int64 v35; // rax
  unsigned int v36; // edi
  unsigned __int64 v37; // rax
  unsigned __int64 v38; // kr70_8
  unsigned int v39; // ebx
  unsigned __int64 v40; // rax
  unsigned __int64 v41; // kr78_8
  unsigned __int64 v42; // rax
  unsigned __int64 v43; // kr80_8
  unsigned __int64 v44; // rax
  unsigned __int64 v45; // kr88_8
  unsigned __int64 v46; // rax
  unsigned __int64 v47; // kr90_8
  unsigned __int64 v48; // rax
  unsigned __int64 v49; // krD0_8

  v3 = (*a2 * (unsigned __int64)*a3) >> 32;
  *a1 = *a2 * *a3;
  v4 = v3;
  v5 = a2[1] * (unsigned __int64)*a3;
  v6 = v5 + v4;
  v7 = __CFADD__(v5, v4);
  v8 = *a2 * (unsigned __int64)a3[1];
  v9 = (v8 + v6) >> 32;
  LOBYTE(v7) = BYTE1(v7) + __CFADD__(v8, v6) + v7;
  a1[1] = v8 + v6;
  v10 = a2[2] * (unsigned __int64)*a3;
  v11 = v10 + __PAIR64__(v7, v9);
  v12 = __CFADD__(v10, __PAIR64__(v7, v9));
  v13 = a2[1] * (unsigned __int64)a3[1];
  v14 = v13 + v11;
  LOBYTE(v12) = BYTE1(v12) + __CFADD__(v13, v11) + v12;
  v15 = *a2 * (unsigned __int64)a3[2];
  v16 = (v15 + v14) >> 32;
  LOBYTE(v12) = BYTE1(v12) + __CFADD__(v15, v14) + v12;
  a1[2] = v15 + v14;
  v17 = a2[3] * (unsigned __int64)*a3;
  v18 = v17 + __PAIR64__(v12, v16);
  v19 = __CFADD__(v17, __PAIR64__(v12, v16));
  v20 = a2[2] * (unsigned __int64)a3[1];
  v21 = v20 + v18;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v20, v18) + v19;
  v22 = a2[1] * (unsigned __int64)a3[2];
  v23 = v22 + v21;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v22, v21) + v19;
  v24 = *a2 * (unsigned __int64)a3[3];
  v25 = (v24 + v23) >> 32;
  LOBYTE(v19) = BYTE1(v19) + __CFADD__(v24, v23) + v19;
  a1[3] = v24 + v23;
  v26 = a2[4] * (unsigned __int64)*a3;
  v27 = v26 + __PAIR64__(v19, v25);
  v28 = __CFADD__(v26, __PAIR64__(v19, v25));
  v29 = a2[3] * (unsigned __int64)a3[1];
  v30 = v29 + v27;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v29, v27) + v28;
  v31 = a2[2] * (unsigned __int64)a3[2];
  v32 = v31 + v30;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v31, v30) + v28;
  v33 = a2[1] * (unsigned __int64)a3[3];
  v34 = v33 + v32;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v33, v32) + v28;
  v35 = *a2 * (unsigned __int64)a3[4];
  v36 = (v35 + v34) >> 32;
  LOBYTE(v28) = BYTE1(v28) + __CFADD__(v35, v34) + v28;
  a1[4] = v35 + v34;
  v37 = a2[5] * (unsigned __int64)*a3;
  v38 = v37 + __PAIR64__(v28, v36);
  v39 = __CFADD__(v37, __PAIR64__(v28, v36));
  v40 = a2[4] * (unsigned __int64)a3[1];
  v41 = v40 + v38;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v40, v38) + v39;
  v42 = a2[3] * (unsigned __int64)a3[2];
  v43 = v42 + v41;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v42, v41) + v39;
  v44 = a2[2] * (unsigned __int64)a3[3];
  v45 = v44 + v43;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v44, v43) + v39;
  v46 = a2[1] * (unsigned __int64)a3[4];
  v47 = v46 + v45;
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v46, v45) + v39;
  v48 = *a2 * (unsigned __int64)a3[5];
  LOBYTE(v39) = BYTE1(v39) + __CFADD__(v48, v47) + v39;
  a1[5] = v48 + v47;
  v49 = *a2 * (unsigned __int64)a3[6]
      + a2[1] * (unsigned __int64)a3[5]
      + a2[2] * (unsigned __int64)a3[4]
      + a2[3] * (unsigned __int64)a3[3]
      + a2[4] * (unsigned __int64)a3[2]
      + a2[5] * (unsigned __int64)a3[1]
      + a2[6] * (unsigned __int64)*a3
      + __PAIR64__(v39, (v48 + v47) >> 32);
  a1[6] = v49;
  a1[7] = *a2 * a3[7]
        + a2[1] * a3[6]
        + a2[2] * a3[5]
        + a2[3] * a3[4]
        + a2[4] * a3[3]
        + a2[5] * a3[2]
        + a2[6] * a3[1]
        + a2[7] * *a3
        + HIDWORD(v49);
}

//------------------------------------------------------------------------------
// Address: 0x0043CBF0
// Name: TaoCrypt::P4_Mul
// Source: json
//------------------------------------------------------------------------------
void __stdcall TaoCrypt::P4_Mul(const CUtlSymbolTable::CStringPoolIndex *C)
{
  __asm
  {
    movdqa  xmm3, xmmword ptr [A]
    movdqa  xmm4, xmmword ptr [B]
  }
  _EAX = C;
  __asm
  {
    pxor    xmm0, xmm0
    pshufd  xmm5, xmm4, 0C9h
    pshufd  xmm1, xmm3, 0D8h
    pmuludq xmm1, xmm5
  }
  _XMM5 = _XMM1;
  __asm
  {
    punpckldq xmm1, xmm0
    punpckhdq xmm5, xmm0
    paddq   xmm5, xmm1
    movdqa  xmmword ptr [eax+10h], xmm5
  }
  _XMM1 = _XMM3;
  __asm { psrlq   xmm1, 20h ; ' ' }
  _XMM5 = _XMM4;
  __asm
  {
    psrlq   xmm5, 20h ; ' '
    pmuludq xmm1, xmm5
    movdqa  xmmword ptr [eax+60h], xmm1
    punpckldq xmm1, xmm0
    pshufd  xmm7, xmm4, 0C6h
  }
  _XMM5 = _XMM3;
  __asm { pmuludq xmm5, xmm7 }
  _XMM6 = _XMM5;
  __asm
  {
    punpckhdq xmm5, xmm0
    punpckldq xmm6, xmm0
    paddq   xmm1, xmm6
    paddq   xmm1, xmm5
    movdqa  xmmword ptr [eax+20h], xmm1
    pshufd  xmm6, xmm3, 0B1h
  }
  _XMM1 = _XMM6;
  __asm
  {
    pmuludq xmm1, xmm7
    pshufd  xmm7, xmm4, 93h
  }
  _XMM5 = _XMM3;
  __asm { pmuludq xmm5, xmm7 }
  _XMM7 = _XMM5;
  __asm
  {
    punpckldq xmm5, xmm0
    punpckhdq xmm7, xmm0
    paddq   xmm7, xmm5
  }
  _XMM5 = _XMM1;
  __asm
  {
    punpckldq xmm1, xmm0
    punpckhdq xmm5, xmm0
    paddq   xmm5, xmm1
    pshufd  xmm1, xmm4, 93h
    pmuludq xmm6, xmm1
  }
  _XMM2 = _XMM3;
  __asm
  {
    pmuludq xmm2, xmm4
    movdqa  xmmword ptr [eax], xmm2
    punpckhdq xmm2, xmm0
  }
  _XMM1 = _XMM6;
  __asm
  {
    punpckhdq xmm1, xmm0
    paddq   xmm2, xmm1
    punpckldq xmm6, xmm0
    paddq   xmm2, xmm6
    movdqa  xmmword ptr [eax+40h], xmm2
    pshufd  xmm2, xmm4, 63h ; 'c'
    pshufd  xmm1, xmm3, 72h ; 'r'
    pmuludq xmm1, xmm2
  }
  _XMM2 = _XMM1;
  __asm
  {
    punpckhdq xmm2, xmm0
    punpckldq xmm1, xmm0
    paddq   xmm7, xmm5
    paddq   xmm2, xmm1
    movdqa  xmmword ptr [eax+30h], xmm7
    movdqa  xmmword ptr [eax+50h], xmm2
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043CD10
// Name: public: static void TaoCrypt::P4Optimized::Multiply4(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl TaoCrypt::P4Optimized::Multiply4(unsigned int *a1)
{
  unsigned int v36; // edx
  CUtlSymbolTable::CStringPoolIndex C; // [esp+10h] [ebp-80h] BYREF
  int v51; // [esp+7Ch] [ebp-14h]

  TaoCrypt::P4_Mul(&C);
  __asm
  {
    movq    mm1, [esp+90h+var_70]
    movd    mm0, [esp+90h+var_7C]
    paddq   mm0, mm1
  }
  __asm
  {
    movq    mm1, mm0
    movd    edx, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+90h+var_68]
    movq    mm2, [esp+90h+var_60]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    movd    eax, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+90h+var_58]
    movq    mm2, [esp+90h+var_50]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  *a1 = (unsigned int)C;
  __asm
  {
    movd    ecx, mm1
    movq    mm1, [esp+90h+var_48]
    movq    mm2, [esp+90h+var_40]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  a1[1] = _EDX;
  __asm
  {
    movd    edx, mm1
    movq    mm1, [esp+90h+var_38]
    movq    mm2, [esp+90h+var_30]
    paddq   mm1, mm2
    movd    mm2, [esp+90h+var_18]
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  a1[2] = _EAX;
  __asm
  {
    movd    eax, mm1
    movq    mm1, [esp+90h+var_28]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
  }
  a1[4] = _EDX;
  __asm
  {
    psrlq   mm0, 20h ; ' '
    movd    edx, mm0
  }
  v36 = v51 + _EDX;
  a1[3] = _ECX;
  __asm { movd    ecx, mm1 }
  a1[5] = _EAX;
  a1[6] = _ECX;
  a1[7] = v36;
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x0043CE10
// Name: public: static void TaoCrypt::P4Optimized::Multiply8(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl TaoCrypt::P4Optimized::Multiply8(unsigned int *a1)
{
  unsigned int v136; // edx
  CUtlSymbolTable::CStringPoolIndex C; // [esp+10h] [ebp-1D0h] BYREF
  CUtlSymbolTable::CStringPoolIndex v152; // [esp+80h] [ebp-160h] BYREF
  CUtlSymbolTable::CStringPoolIndex v166; // [esp+F0h] [ebp-F0h] BYREF
  CUtlSymbolTable::CStringPoolIndex v180; // [esp+160h] [ebp-80h] BYREF
  int v193; // [esp+1CCh] [ebp-14h]

  TaoCrypt::P4_Mul(&C);
  TaoCrypt::P4_Mul(C: &v152);
  TaoCrypt::P4_Mul(C: &v166);
  TaoCrypt::P4_Mul(C: &v180);
  __asm
  {
    movq    mm1, [esp+1E0h+var_1C0]
    movd    mm0, [esp+1E0h+var_1CC]
    paddq   mm0, mm1
  }
  __asm
  {
    movq    mm1, mm0
    movd    eax, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+1E0h+var_1B8]
    movq    mm2, [esp+1E0h+var_1B0]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    movd    ecx, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+1E0h+var_1A8]
    movq    mm2, [esp+1E0h+var_1A0]
    paddq   mm1, mm2
    movd    mm2, dword ptr [esp+1E0h+var_F0.m_iPool]
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  *a1 = (unsigned int)C;
  __asm
  {
    movd    edx, mm1
    movd    mm1, dword ptr [esp+1E0h+var_160.m_iPool]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_198]
    movq    mm2, [esp+1E0h+var_190]
    paddq   mm1, mm2
    movd    mm2, [esp+1E0h+var_EC]
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  a1[1] = _EAX;
  __asm
  {
    movd    eax, mm1
    movq    mm1, [esp+1E0h+var_188]
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_180]
    paddq   mm0, mm1
    movd    mm1, [esp+1E0h+var_15C]
    paddq   mm1, mm2
    movq    mm2, [esp+1E0h+var_150]
    movq    mm3, [esp+1E0h+var_E0]
    paddq   mm2, mm3
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  a1[2] = _ECX;
  __asm
  {
    movd    ecx, mm1
    movq    mm1, [esp+1E0h+var_178]
    paddq   mm0, mm1
    movd    mm1, [esp+1E0h+var_168]
  }
  a1[3] = _EDX;
  a1[4] = _EAX;
  a1[5] = _ECX;
  __asm
  {
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_148]
    movq    mm2, [esp+1E0h+var_D8]
    paddq   mm1, mm2
    movq    mm2, [esp+1E0h+var_140]
    movq    mm3, [esp+1E0h+var_D0]
    paddq   mm2, mm3
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    movd    edx, mm1
    movd    mm1, [esp+1E0h+var_164]
    psrlq   mm0, 20h ; ' '
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_138]
    movq    mm2, [esp+1E0h+var_C8]
    paddq   mm1, mm2
    movq    mm2, [esp+1E0h+var_130]
    movq    mm3, [esp+1E0h+var_C0]
    paddq   mm2, mm3
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    movd    eax, mm1
    movd    mm1, dword ptr [esp+1E0h+var_80.m_iPool]
    psrlq   mm0, 20h ; ' '
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_128]
    movq    mm2, [esp+1E0h+var_B8]
    paddq   mm1, mm2
    movq    mm2, [esp+1E0h+var_120]
    movq    mm3, [esp+1E0h+var_B0]
    paddq   mm2, mm3
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    movd    ecx, mm1
    movd    mm1, [esp+1E0h+var_7C]
    psrlq   mm0, 20h ; ' '
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_70]
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_118]
    movq    mm2, [esp+1E0h+var_A8]
    paddq   mm1, mm2
    movq    mm2, [esp+1E0h+var_110]
    movq    mm3, [esp+1E0h+var_A0]
    paddq   mm2, mm3
    movd    mm3, [esp+1E0h+var_88]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  a1[6] = _EDX;
  __asm
  {
    movd    edx, mm1
    movq    mm1, [esp+1E0h+var_68]
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_60]
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_108]
    movq    mm2, [esp+1E0h+var_98]
    paddq   mm1, mm2
    movd    mm2, [esp+1E0h+var_F8]
    paddq   mm2, mm3
    paddq   mm1, mm2
    movd    mm2, [esp+1E0h+var_84]
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  a1[7] = _EAX;
  __asm
  {
    movd    eax, mm1
    movq    mm1, [esp+1E0h+var_58]
    paddq   mm0, mm1
    movq    mm1, [esp+1E0h+var_50]
    paddq   mm0, mm1
    movd    mm1, [esp+1E0h+var_F4]
    paddq   mm1, mm2
    paddq   mm0, mm1
  }
  a1[8] = _ECX;
  a1[9] = _EDX;
  a1[10] = _EAX;
  __asm
  {
    movq    mm1, mm0
    movd    ecx, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+1E0h+var_48]
    movq    mm2, [esp+1E0h+var_40]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    movd    edx, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+1E0h+var_38]
    movq    mm2, [esp+1E0h+var_30]
    paddq   mm1, mm2
    movd    mm2, [esp+1E0h+var_18]
    paddq   mm0, mm1
    movq    mm1, mm0
    movd    eax, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+1E0h+var_28]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
  }
  a1[12] = _EDX;
  __asm
  {
    psrlq   mm0, 20h ; ' '
    movd    edx, mm0
  }
  v136 = v193 + _EDX;
  a1[11] = _ECX;
  __asm { movd    ecx, mm1 }
  a1[13] = _EAX;
  a1[14] = _ECX;
  a1[15] = v136;
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x0043D180
// Name: public: static void TaoCrypt::P4Optimized::Multiply8Bottom(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl TaoCrypt::P4Optimized::Multiply8Bottom(unsigned int *a1)
{
  int v57; // eax
  CUtlSymbolTable::CStringPoolIndex C; // [esp+10h] [ebp-160h] BYREF
  int v71; // [esp+7Ch] [ebp-F4h]
  CUtlSymbolTable::CStringPoolIndex v72; // [esp+80h] [ebp-F0h] BYREF
  int v77; // [esp+A8h] [ebp-C8h]
  int v78; // [esp+B0h] [ebp-C0h]
  CUtlSymbolTable::CStringPoolIndex v79; // [esp+F0h] [ebp-80h] BYREF
  int v84; // [esp+118h] [ebp-58h]
  int v85; // [esp+120h] [ebp-50h]

  TaoCrypt::P4_Mul(&C);
  TaoCrypt::P4_Mul(C: &v72);
  TaoCrypt::P4_Mul(C: &v79);
  __asm
  {
    movq    mm1, [esp+170h+var_150]
    movd    mm0, [esp+170h+var_15C]
    paddq   mm0, mm1
  }
  __asm
  {
    movq    mm1, mm0
    movd    eax, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+170h+var_148]
    movq    mm2, [esp+170h+var_140]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    movd    ecx, mm1
    psrlq   mm0, 20h ; ' '
    movq    mm1, [esp+170h+var_138]
    movq    mm2, [esp+170h+var_130]
    paddq   mm1, mm2
    movd    mm2, dword ptr [esp+170h+var_80.m_iPool]
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  *a1 = (unsigned int)C;
  __asm
  {
    movd    edx, mm1
    movd    mm1, dword ptr [esp+170h+var_F0.m_iPool]
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, [esp+170h+var_128]
    movq    mm2, [esp+170h+var_120]
    paddq   mm1, mm2
    movd    mm2, [esp+170h+var_7C]
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  a1[1] = _EAX;
  __asm
  {
    movd    eax, mm1
    movq    mm1, [esp+170h+var_118]
    paddq   mm0, mm1
    movq    mm1, [esp+170h+var_110]
    paddq   mm0, mm1
    movd    mm1, [esp+170h+var_EC]
    paddq   mm1, mm2
    movq    mm2, [esp+170h+var_E0]
    movq    mm3, [esp+170h+var_70]
    paddq   mm2, mm3
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
  }
  a1[2] = _ECX;
  __asm
  {
    movd    ecx, mm1
    movq    mm1, [esp+170h+var_108]
    paddq   mm0, mm1
    movd    mm1, [esp+170h+var_F8]
    paddq   mm0, mm1
    movq    mm1, [esp+170h+var_D8]
    movq    mm2, [esp+170h+var_68]
    paddq   mm1, mm2
    movq    mm2, [esp+170h+var_D0]
    movq    mm3, [esp+170h+var_60]
  }
  a1[3] = _EDX;
  a1[4] = _EAX;
  a1[5] = _ECX;
  __asm
  {
    paddq   mm2, mm3
    paddq   mm1, mm2
    paddq   mm0, mm1
    movq    mm1, mm0
    psrlq   mm0, 20h ; ' '
    movd    eax, mm0
  }
  __asm { movd    edx, mm1 }
  v57 = v78 + v77 + _EAX;
  a1[6] = _EDX;
  a1[7] = v85 + v84 + v71 + v57;
  _m_empty();
}

//------------------------------------------------------------------------------
// Address: 0x0043D330
// Name: void TaoCrypt::RecursiveMultiply(unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043D5C0
// Name: void TaoCrypt::RecursiveMultiplyTop(unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043D8A0
// Name: TaoCrypt::EvenWordCount
// Source: json
//------------------------------------------------------------------------------
int __usercall TaoCrypt::EvenWordCount@<eax>(int X@<ecx>, int N@<eax>)
{
  _DWORD *v2; // ecx

  if ( N != 0 )
  {
    v2 = (_DWORD *)(X + 4 * N - 4);
    do
    {
      if ( *(v2 - 1) != 0 )
        break;
      if ( *v2 != 0 )
        break;
      N -= 2;
      v2 -= 2;
    }
    while ( N != 0 );
  }
  return N;
}

//------------------------------------------------------------------------------
// Address: 0x0043D8C0
// Name: void TaoCrypt::DivideByPower2Mod(unsigned int __near *,unsigned int const __near *,unsigned int,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043D970
// Name: void TaoCrypt::MultiplyByPower2Mod(unsigned int __near *,unsigned int const __near *,unsigned int,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::MultiplyByPower2Mod(
        const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *R,
        unsigned int *Ra,
        int a3,
        unsigned int k,
        int a5,
        unsigned int N)
{
  unsigned int *v6; // eax
  unsigned int i; // edx
  unsigned int v8; // ebx
  unsigned int v9; // edx
  unsigned int v10; // ecx
  unsigned int v11; // eax
  unsigned int v12; // eax

  if ( N != 0 )
  {
    v6 = Ra;
    for ( i = N; i != 0; --i )
    {
      *v6 = *(unsigned int *)((char *)v6 + a3 - (_DWORD)Ra);
      ++v6;
    }
  }
  v8 = k;
  while ( v8 != 0 )
  {
    --v8;
    v9 = 0;
    v10 = 0;
    if ( N != 0 )
    {
      do
      {
        v11 = Ra[v10];
        Ra[v10] = v9 | (2 * v11);
        v12 = v11 >> 31;
        ++v10;
        v9 = v12;
      }
      while ( v10 < N );
      if ( v12 != 0 )
        goto LABEL_9;
    }
    if ( TaoCrypt::Compare(
           a1: N,
           a2: a5,
           result: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)Ra) >= 0 )
LABEL_9:
      s_pSub(a1: Ra, a2: Ra, a3: a5, a4: N);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043DA00
// Name: unsigned int TaoCrypt::DivideThreeWordsByTwo<unsigned int,class TaoCrypt::DWord>(unsigned int __near *,unsigned int,unsigned int,class TaoCrypt::DWord __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::DivideThreeWordsByTwo<unsigned int,TaoCrypt::DWord>(
        const unsigned int *A,
        unsigned int *Aa,
        unsigned __int64 B0)
{
  unsigned int v3; // ebx
  int v4; // edi
  int v5; // eax
  unsigned int v6; // ecx
  bool v7; // cf
  unsigned int v8; // eax
  int v9; // ecx
  unsigned __int64 v11; // [esp+10h] [ebp-8h]

  if ( HIDWORD(B0) == -1 )
    v3 = Aa[2];
  else
    v3 = *(_QWORD *)(Aa + 1) / (unsigned __int64)(unsigned int)(HIDWORD(B0) + 1);
  v11 = (unsigned int)B0 * (unsigned __int64)v3;
  v4 = (*Aa - (unsigned __int64)(unsigned int)v11) >> 32;
  *Aa -= v11;
  v5 = Aa[1] - HIDWORD(B0) * v3 + v4 - HIDWORD(v11);
  Aa[2] += (Aa[1] - HIDWORD(B0) * (unsigned __int64)v3 - (unsigned int)-v4 - HIDWORD(v11)) >> 32;
  while ( 1 )
  {
    v6 = Aa[2];
    Aa[1] = v5;
    if ( v6 == 0 && __PAIR64__(v5, *Aa) < B0 )
      break;
    v7 = *Aa < (unsigned int)B0;
    v8 = Aa[1];
    *Aa -= B0;
    v9 = (v8 - (unsigned __int64)v7 - HIDWORD(B0)) >> 32;
    v5 = v8 - v7 - HIDWORD(B0);
    Aa[2] += v9;
    ++v3;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0043DAD0
// Name: TaoCrypt::LinearMultiply
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall TaoCrypt::LinearMultiply@<eax>(_DWORD *a1@<eax>, int a2, unsigned int a3, int a4)
{
  int v4; // ebp
  unsigned int v5; // edi
  _DWORD *v6; // esi
  int v7; // ebx
  unsigned __int64 v8; // rax

  v4 = a4;
  v5 = 0;
  v6 = a1;
  if ( a4 != 0 )
  {
    v7 = a2 - (_DWORD)a1;
    do
    {
      v8 = v5 + *(unsigned int *)((char *)v6 + v7) * (unsigned __int64)a3;
      *v6++ = v8;
      --v4;
      v5 = HIDWORD(v8);
    }
    while ( v4 != 0 );
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x0043DB20
// Name: public: static void TaoCrypt::Portable::Multiply4(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlSymbolTable::CStringPoolIndex *__thiscall TaoCrypt::Portable::Multiply4(
        unsigned __int16 R,
        unsigned int *Ra,
        unsigned int *c,
        unsigned int *d)
{
  unsigned int v6; // ebx
  unsigned __int64 v8; // kr10_8
  unsigned __int64 v9; // kr18_8
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr28_8
  unsigned __int64 v12; // rax
  int v13; // kr04_4
  unsigned __int64 v14; // kr30_8
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // kr48_8
  unsigned __int64 v17; // kr50_8
  unsigned __int64 v18; // rax
  unsigned __int64 v19; // kr60_8
  unsigned __int64 v20; // kr68_8
  unsigned __int64 v21; // kr70_8
  unsigned int v22; // ebp
  unsigned __int64 v23; // rax
  int v25; // [esp+10h] [ebp-Ch]
  unsigned int *Rb; // [esp+20h] [ebp+4h]
  unsigned int *Rc; // [esp+20h] [ebp+4h]
  unsigned int *Rd; // [esp+20h] [ebp+4h]
  unsigned __int64 ca; // [esp+24h] [ebp+8h]

  v6 = (*d * (unsigned __int64)*c) >> 32;
  *Ra = *d * *c;
  ca = v6 + d[1] * (unsigned __int64)*c;
  v8 = HIDWORD(ca) + (((unsigned int)ca + *d * (unsigned __int64)c[1]) >> 32);
  Ra[1] = ca + *d * c[1];
  LODWORD(ca) = v8 + c[2] * *d;
  v9 = (((unsigned int)v8 + c[2] * (unsigned __int64)*d) >> 32) + HIDWORD(v8);
  Rb = (unsigned int *)(((unsigned int)v9 + (((unsigned int)ca + d[1] * (unsigned __int64)c[1]) >> 32)) >> 32);
  v10 = (unsigned int)ca + d[1] * c[1] + *c * (unsigned __int64)d[2];
  v11 = (unsigned int)(v9 + (((unsigned int)ca + d[1] * (unsigned __int64)c[1]) >> 32)) + (unsigned __int64)HIDWORD(v10);
  Ra[2] = v10;
  v12 = (unsigned int)v11 + *c * (unsigned __int64)d[3];
  LODWORD(ca) = v11 + *c * d[3];
  v13 = (int)Rb + HIDWORD(v11) + HIDWORD(v9);
  v14 = HIDWORD(v12) + (unsigned __int64)(unsigned int)v13;
  v25 = ((unsigned int)(HIDWORD(v12) + v13) + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32)) >> 32;
  Rc = (unsigned int *)(((unsigned int)(HIDWORD(v12) + v13 + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32))
                       + (((unsigned int)ca + d[2] * c[1] + d[1] * (unsigned __int64)c[2]) >> 32)) >> 32);
  HIDWORD(ca) = HIDWORD(v12)
              + v13
              + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32)
              + (((unsigned int)ca + d[2] * c[1] + d[1] * (unsigned __int64)c[2]) >> 32);
  v15 = (_DWORD)ca + d[2] * c[1] + d[1] * c[2] + *d * (unsigned __int64)c[3];
  v16 = HIDWORD(ca) + (unsigned __int64)HIDWORD(v15);
  Ra[3] = v15;
  LODWORD(ca) = v16 + d[1] * c[3];
  v17 = (((unsigned int)v16 + d[1] * (unsigned __int64)c[3]) >> 32)
      + (unsigned int)Rc
      + HIDWORD(v16)
      + v25
      + HIDWORD(v14);
  Rd = (unsigned int *)(((unsigned int)v17 + (((unsigned int)ca + c[2] * (unsigned __int64)d[2]) >> 32)) >> 32);
  v18 = (unsigned int)ca + c[2] * d[2] + d[3] * (unsigned __int64)c[1];
  v19 = (unsigned int)(v17 + (((unsigned int)ca + c[2] * (unsigned __int64)d[2]) >> 32))
      + (unsigned __int64)HIDWORD(v18);
  Ra[4] = v18;
  LODWORD(ca) = v19 + c[2] * d[3];
  v20 = (((unsigned int)v19 + c[2] * (unsigned __int64)d[3]) >> 32) + (unsigned int)Rd + HIDWORD(v19) + HIDWORD(v17);
  v21 = (unsigned int)v20 + (((unsigned int)ca + d[2] * (unsigned __int64)c[3]) >> 32);
  v22 = v20 + (((unsigned int)ca + d[2] * (unsigned __int64)c[3]) >> 32);
  Ra[5] = ca + d[2] * c[3];
  v23 = d[3] * (unsigned __int64)c[3];
  Ra[6] = v22 + v23;
  Ra[7] = HIDWORD(v20) + ((__PAIR64__(HIDWORD(v21), v22) + v23) >> 32);
  return (const CUtlSymbolTable::CStringPoolIndex *)HIDWORD(v21);
}

//------------------------------------------------------------------------------
// Address: 0x0043DD60
// Name: public: static void TaoCrypt::Portable::Square2(unsigned int __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Portable::Square2(unsigned __int16 R, unsigned int *A, unsigned int *a3)
{
  unsigned __int64 v3; // rax
  __int64 v4; // rcx
  unsigned __int64 v5; // rax
  __int64 v6; // rcx
  unsigned __int64 v7; // kr00_8

  v3 = *a3 * (unsigned __int64)*a3;
  *A = v3;
  v4 = HIDWORD(v3);
  v5 = *a3 * (unsigned __int64)a3[1];
  v6 = v5 + v4;
  v7 = v5 + (unsigned int)v6;
  A[1] = v7;
  *((_QWORD *)A + 1) = HIDWORD(v6) + (unsigned __int64)HIDWORD(v7) + a3[1] * (unsigned __int64)a3[1];
}

//------------------------------------------------------------------------------
// Address: 0x0043DDD0
// Name: public: static void TaoCrypt::Portable::Multiply8(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlSymbolTable::CStringPoolIndex *__thiscall TaoCrypt::Portable::Multiply8(
        unsigned __int16 R,
        unsigned int *Ra,
        unsigned int *c,
        unsigned int *d)
{
  unsigned int v6; // ebx
  unsigned __int64 v8; // kr40_8
  unsigned __int64 v9; // kr48_8
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr58_8
  unsigned __int64 v12; // rax
  int v13; // kr04_4
  unsigned __int64 v14; // kr60_8
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // kr78_8
  unsigned __int64 v17; // rax
  int v18; // kr0C_4
  unsigned __int64 v19; // kr80_8
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // krA0_8
  int v22; // ebx
  char *v23; // krB8_4
  unsigned __int64 v24; // krC8_8
  unsigned __int64 v25; // krD0_8
  int v26; // ebx
  unsigned int v27; // krD8_4
  unsigned __int64 v28; // kr100_8
  unsigned __int64 v29; // kr108_8
  unsigned __int64 v30; // kr110_8
  unsigned int v31; // kr138_4
  unsigned __int64 v32; // rax
  unsigned __int64 v33; // kr148_8
  unsigned __int64 v34; // kr150_8
  unsigned __int64 v35; // rax
  unsigned __int64 v36; // kr180_8
  int v37; // ebx
  char *v38; // kr190_4
  unsigned __int64 v39; // kr1A8_8
  unsigned __int64 v40; // kr1B0_8
  unsigned __int64 v41; // kr1B8_8
  unsigned __int64 v42; // rax
  unsigned __int64 v43; // kr1D8_8
  unsigned __int64 v44; // rax
  int v45; // kr2C_4
  unsigned __int64 v46; // kr1E0_8
  unsigned __int64 v47; // rax
  unsigned __int64 v48; // kr1F8_8
  unsigned __int64 v49; // kr200_8
  unsigned __int64 v50; // rax
  unsigned __int64 v51; // kr210_8
  unsigned __int64 v52; // rax
  int v53; // kr34_4
  unsigned __int64 v54; // kr218_8
  unsigned __int64 v55; // kr220_8
  unsigned int v56; // ebp
  unsigned __int64 v57; // rax
  int v59; // [esp+10h] [ebp-1Ch]
  int v60; // [esp+10h] [ebp-1Ch]
  int v61; // [esp+10h] [ebp-1Ch]
  int v62; // [esp+10h] [ebp-1Ch]
  int v63; // [esp+10h] [ebp-1Ch]
  int v64; // [esp+14h] [ebp-18h]
  unsigned int v65; // [esp+14h] [ebp-18h]
  int v66; // [esp+14h] [ebp-18h]
  int v67; // [esp+14h] [ebp-18h]
  int v68; // [esp+14h] [ebp-18h]
  int v69; // [esp+18h] [ebp-14h]
  int v70; // [esp+18h] [ebp-14h]
  int v71; // [esp+18h] [ebp-14h]
  int v72; // [esp+18h] [ebp-14h]
  int v73; // [esp+18h] [ebp-14h]
  int v74; // [esp+1Ch] [ebp-10h]
  int v75; // [esp+1Ch] [ebp-10h]
  int v76; // [esp+1Ch] [ebp-10h]
  unsigned int v77; // [esp+1Ch] [ebp-10h]
  int v78; // [esp+1Ch] [ebp-10h]
  int v79; // [esp+20h] [ebp-Ch]
  int v80; // [esp+20h] [ebp-Ch]
  unsigned int v81; // [esp+20h] [ebp-Ch]
  int v82; // [esp+20h] [ebp-Ch]
  int v83; // [esp+20h] [ebp-Ch]
  unsigned int *Rb; // [esp+30h] [ebp+4h]
  unsigned int *Rc; // [esp+30h] [ebp+4h]
  unsigned int *Rd; // [esp+30h] [ebp+4h]
  unsigned int *Re; // [esp+30h] [ebp+4h]
  unsigned int *Rf; // [esp+30h] [ebp+4h]
  unsigned int *Rg; // [esp+30h] [ebp+4h]
  unsigned int *Rh; // [esp+30h] [ebp+4h]
  unsigned int *Ri; // [esp+30h] [ebp+4h]
  unsigned __int64 ca; // [esp+34h] [ebp+8h]

  v6 = (*d * (unsigned __int64)*c) >> 32;
  *Ra = *d * *c;
  ca = v6 + d[1] * (unsigned __int64)*c;
  v8 = HIDWORD(ca) + (((unsigned int)ca + *d * (unsigned __int64)c[1]) >> 32);
  Ra[1] = ca + *d * c[1];
  LODWORD(ca) = v8 + c[2] * *d;
  v9 = (((unsigned int)v8 + c[2] * (unsigned __int64)*d) >> 32) + HIDWORD(v8);
  Rb = (unsigned int *)(((unsigned int)v9 + (((unsigned int)ca + d[1] * (unsigned __int64)c[1]) >> 32)) >> 32);
  v10 = (unsigned int)ca + d[1] * c[1] + *c * (unsigned __int64)d[2];
  v11 = (unsigned int)(v9 + (((unsigned int)ca + d[1] * (unsigned __int64)c[1]) >> 32)) + (unsigned __int64)HIDWORD(v10);
  Ra[2] = v10;
  v12 = (unsigned int)v11 + *c * (unsigned __int64)d[3];
  LODWORD(ca) = v11 + *c * d[3];
  v13 = (int)Rb + HIDWORD(v11) + HIDWORD(v9);
  v14 = HIDWORD(v12) + (unsigned __int64)(unsigned int)v13;
  v59 = ((unsigned int)(HIDWORD(v12) + v13) + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32)) >> 32;
  Rc = (unsigned int *)(((unsigned int)(HIDWORD(v12) + v13 + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32))
                       + (((unsigned int)ca + d[2] * c[1] + d[1] * (unsigned __int64)c[2]) >> 32)) >> 32);
  HIDWORD(ca) = HIDWORD(v12)
              + v13
              + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32)
              + (((unsigned int)ca + d[2] * c[1] + d[1] * (unsigned __int64)c[2]) >> 32);
  v15 = (_DWORD)ca + d[2] * c[1] + d[1] * c[2] + *d * (unsigned __int64)c[3];
  v16 = HIDWORD(ca) + (unsigned __int64)HIDWORD(v15);
  Ra[3] = v15;
  v17 = (unsigned int)v16 + *c * (unsigned __int64)d[4];
  LODWORD(ca) = v16 + *c * d[4];
  v18 = (int)Rc + HIDWORD(v16) + v59 + HIDWORD(v14);
  v19 = HIDWORD(v17) + (unsigned __int64)(unsigned int)v18;
  v64 = ((unsigned int)(HIDWORD(v17) + v18) + (((unsigned int)ca + d[3] * (unsigned __int64)c[1]) >> 32)) >> 32;
  v60 = ((unsigned int)(HIDWORD(v17) + v18 + (((unsigned int)ca + d[3] * (unsigned __int64)c[1]) >> 32))
       + (((unsigned int)ca + d[3] * c[1] + c[2] * (unsigned __int64)d[2]) >> 32)) >> 32;
  Rd = (unsigned int *)(((unsigned int)(HIDWORD(v17)
                                      + v18
                                      + (((unsigned int)ca + d[3] * (unsigned __int64)c[1]) >> 32)
                                      + (((unsigned int)ca + d[3] * c[1] + c[2] * (unsigned __int64)d[2]) >> 32))
                       + (((_DWORD)ca + d[3] * c[1] + c[2] * d[2] + d[1] * (unsigned __int64)c[3]) >> 32)) >> 32);
  HIDWORD(ca) = HIDWORD(v17)
              + v18
              + (((unsigned int)ca + d[3] * (unsigned __int64)c[1]) >> 32)
              + (((unsigned int)ca + d[3] * c[1] + c[2] * (unsigned __int64)d[2]) >> 32)
              + (((_DWORD)ca + d[3] * c[1] + c[2] * d[2] + d[1] * (unsigned __int64)c[3]) >> 32);
  v20 = (_DWORD)ca + d[3] * c[1] + c[2] * d[2] + d[1] * c[3] + c[4] * (unsigned __int64)*d;
  v21 = HIDWORD(ca) + (unsigned __int64)HIDWORD(v20);
  Ra[4] = v20;
  LODWORD(ca) = v21 + d[5] * *c;
  v22 = ((((unsigned int)v21 + d[5] * (unsigned __int64)*c) >> 32)
       + (unsigned int)Rd
       + HIDWORD(v21)
       + v60
       + v64
       + HIDWORD(v19)) >> 32;
  v69 = ((unsigned int)((unsigned int)Rd
                      + HIDWORD(v21)
                      + v60
                      + v64
                      + HIDWORD(v19)
                      + (((unsigned int)v21 + d[5] * (unsigned __int64)*c) >> 32))
       + (((unsigned int)ca + c[1] * (unsigned __int64)d[4]) >> 32)) >> 32;
  v23 = (char *)Rd
      + HIDWORD(v21)
      + v60
      + v64
      + HIDWORD(v19)
      + (((unsigned int)v21 + d[5] * (unsigned __int64)*c) >> 32)
      + (((unsigned int)ca + c[1] * (unsigned __int64)d[4]) >> 32)
      + (((unsigned int)ca + c[1] * d[4] + c[2] * (unsigned __int64)d[3]) >> 32);
  v61 = ((unsigned int)((unsigned int)Rd
                      + HIDWORD(v21)
                      + v60
                      + v64
                      + HIDWORD(v19)
                      + (((unsigned int)v21 + d[5] * (unsigned __int64)*c) >> 32)
                      + (((unsigned int)ca + c[1] * (unsigned __int64)d[4]) >> 32))
       + (((unsigned int)ca + c[1] * d[4] + c[2] * (unsigned __int64)d[3]) >> 32)) >> 32;
  v65 = (unsigned int)&v23[((_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * (unsigned __int64)c[3]) >> 32] >> 32;
  v24 = (unsigned __int64)&v23[(((_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * (unsigned __int64)c[3]) >> 32)
                             + (((_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * c[3] + d[1] * (unsigned __int64)c[4]) >> 32)];
  v25 = (_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * c[3] + d[1] * c[4] + c[5] * (unsigned __int64)*d;
  Ra[5] = v25;
  LODWORD(ca) = v24 + HIDWORD(v25) + d[6] * *c;
  v27 = (((unsigned int)(v24 + HIDWORD(v25)) + d[6] * (unsigned __int64)*c) >> 32)
      + v22
      + v69
      + v61
      + v65
      + HIDWORD(v24)
      + (((unsigned int)v24 + (unsigned __int64)HIDWORD(v25)) >> 32);
  v26 = ((((unsigned int)(v24 + HIDWORD(v25)) + d[6] * (unsigned __int64)*c) >> 32)
       + (unsigned int)(v22
                      + v69
                      + v61
                      + v65
                      + HIDWORD(v24)
                      + (((unsigned int)v24 + (unsigned __int64)HIDWORD(v25)) >> 32))) >> 32;
  v74 = (v27 + (((unsigned int)ca + d[5] * (unsigned __int64)c[1]) >> 32)) >> 32;
  v62 = ((unsigned int)(v27 + (((unsigned int)ca + d[5] * (unsigned __int64)c[1]) >> 32))
       + (((unsigned int)ca + d[5] * c[1] + c[2] * (unsigned __int64)d[4]) >> 32)) >> 32;
  v66 = ((unsigned int)(v27
                      + (((unsigned int)ca + d[5] * (unsigned __int64)c[1]) >> 32)
                      + (((unsigned int)ca + d[5] * c[1] + c[2] * (unsigned __int64)d[4]) >> 32))
       + (((_DWORD)ca + d[5] * c[1] + c[2] * d[4] + d[3] * (unsigned __int64)c[3]) >> 32)) >> 32;
  v70 = ((unsigned int)(v27
                      + (((unsigned int)ca + d[5] * (unsigned __int64)c[1]) >> 32)
                      + (((unsigned int)ca + d[5] * c[1] + c[2] * (unsigned __int64)d[4]) >> 32)
                      + (((_DWORD)ca + d[5] * c[1] + c[2] * d[4] + d[3] * (unsigned __int64)c[3]) >> 32))
       + (((_DWORD)ca + d[5] * c[1] + c[2] * d[4] + d[3] * c[3] + c[4] * (unsigned __int64)d[2]) >> 32)) >> 32;
  v28 = (unsigned int)(v27
                     + (((unsigned int)ca + d[5] * (unsigned __int64)c[1]) >> 32)
                     + (((unsigned int)ca + d[5] * c[1] + c[2] * (unsigned __int64)d[4]) >> 32)
                     + (((_DWORD)ca + d[5] * c[1] + c[2] * d[4] + d[3] * (unsigned __int64)c[3]) >> 32)
                     + (((_DWORD)ca + d[5] * c[1] + c[2] * d[4] + d[3] * c[3] + c[4] * (unsigned __int64)d[2]) >> 32))
      + (((_DWORD)ca + d[5] * c[1] + c[2] * d[4] + d[3] * c[3] + c[4] * d[2] + d[1] * (unsigned __int64)c[5]) >> 32);
  v29 = (_DWORD)ca + d[5] * c[1] + c[2] * d[4] + d[3] * c[3] + c[4] * d[2] + d[1] * c[5] + *d * (unsigned __int64)c[6];
  Ra[6] = v29;
  LODWORD(ca) = v28 + HIDWORD(v29) + *c * d[7];
  v30 = (((unsigned int)(v28 + HIDWORD(v29)) + *c * (unsigned __int64)d[7]) >> 32)
      + (unsigned int)(v26
                     + v74
                     + v62
                     + v66
                     + v70
                     + HIDWORD(v28)
                     + (((unsigned int)v28 + (unsigned __int64)HIDWORD(v29)) >> 32));
  v79 = ((unsigned int)v30 + (((unsigned int)ca + d[6] * (unsigned __int64)c[1]) >> 32)) >> 32;
  v63 = ((unsigned int)(v30 + (((unsigned int)ca + d[6] * (unsigned __int64)c[1]) >> 32))
       + (((unsigned int)ca + d[6] * c[1] + d[5] * (unsigned __int64)c[2]) >> 32)) >> 32;
  v67 = ((unsigned int)(v30
                      + (((unsigned int)ca + d[6] * (unsigned __int64)c[1]) >> 32)
                      + (((unsigned int)ca + d[6] * c[1] + d[5] * (unsigned __int64)c[2]) >> 32))
       + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * (unsigned __int64)c[3]) >> 32)) >> 32;
  v71 = ((unsigned int)(v30
                      + (((unsigned int)ca + d[6] * (unsigned __int64)c[1]) >> 32)
                      + (((unsigned int)ca + d[6] * c[1] + d[5] * (unsigned __int64)c[2]) >> 32)
                      + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * (unsigned __int64)c[3]) >> 32))
       + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * c[3] + c[4] * (unsigned __int64)d[3]) >> 32)) >> 32;
  v31 = v30
      + (((unsigned int)ca + d[6] * (unsigned __int64)c[1]) >> 32)
      + (((unsigned int)ca + d[6] * c[1] + d[5] * (unsigned __int64)c[2]) >> 32)
      + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * (unsigned __int64)c[3]) >> 32)
      + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * c[3] + c[4] * (unsigned __int64)d[3]) >> 32)
      + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * c[3] + c[4] * d[3] + c[5] * (unsigned __int64)d[2]) >> 32);
  v75 = ((unsigned int)(v30
                      + (((unsigned int)ca + d[6] * (unsigned __int64)c[1]) >> 32)
                      + (((unsigned int)ca + d[6] * c[1] + d[5] * (unsigned __int64)c[2]) >> 32)
                      + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * (unsigned __int64)c[3]) >> 32)
                      + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * c[3] + c[4] * (unsigned __int64)d[3]) >> 32))
       + (((_DWORD)ca + d[6] * c[1] + d[5] * c[2] + d[4] * c[3] + c[4] * d[3] + c[5] * (unsigned __int64)d[2]) >> 32)) >> 32;
  Re = (unsigned int *)((v31
                       + (((_DWORD)ca
                         + d[6] * c[1]
                         + d[5] * c[2]
                         + d[4] * c[3]
                         + c[4] * d[3]
                         + c[5] * d[2]
                         + d[1] * (unsigned __int64)c[6]) >> 32)) >> 32);
  v32 = (_DWORD)ca
      + d[6] * c[1]
      + d[5] * c[2]
      + d[4] * c[3]
      + c[4] * d[3]
      + c[5] * d[2]
      + d[1] * c[6]
      + *d * (unsigned __int64)c[7];
  v33 = (unsigned int)(v31
                     + (((_DWORD)ca
                       + d[6] * c[1]
                       + d[5] * c[2]
                       + d[4] * c[3]
                       + c[4] * d[3]
                       + c[5] * d[2]
                       + d[1] * (unsigned __int64)c[6]) >> 32))
      + (unsigned __int64)HIDWORD(v32);
  Ra[7] = v32;
  LODWORD(ca) = v33 + c[1] * d[7];
  v34 = (((unsigned int)v33 + c[1] * (unsigned __int64)d[7]) >> 32)
      + (unsigned int)Re
      + HIDWORD(v33)
      + v75
      + v71
      + v67
      + v63
      + v79
      + HIDWORD(v30);
  v68 = ((unsigned int)v34 + (((unsigned int)ca + d[6] * (unsigned __int64)c[2]) >> 32)) >> 32;
  v72 = ((unsigned int)(v34 + (((unsigned int)ca + d[6] * (unsigned __int64)c[2]) >> 32))
       + (((unsigned int)ca + d[6] * c[2] + d[5] * (unsigned __int64)c[3]) >> 32)) >> 32;
  v76 = ((unsigned int)(v34
                      + (((unsigned int)ca + d[6] * (unsigned __int64)c[2]) >> 32)
                      + (((unsigned int)ca + d[6] * c[2] + d[5] * (unsigned __int64)c[3]) >> 32))
       + (((_DWORD)ca + d[6] * c[2] + d[5] * c[3] + c[4] * (unsigned __int64)d[4]) >> 32)) >> 32;
  v80 = ((unsigned int)(v34
                      + (((unsigned int)ca + d[6] * (unsigned __int64)c[2]) >> 32)
                      + (((unsigned int)ca + d[6] * c[2] + d[5] * (unsigned __int64)c[3]) >> 32)
                      + (((_DWORD)ca + d[6] * c[2] + d[5] * c[3] + c[4] * (unsigned __int64)d[4]) >> 32))
       + (((_DWORD)ca + d[6] * c[2] + d[5] * c[3] + c[4] * d[4] + c[5] * (unsigned __int64)d[3]) >> 32)) >> 32;
  Rf = (unsigned int *)(((unsigned int)(v34
                                      + (((unsigned int)ca + d[6] * (unsigned __int64)c[2]) >> 32)
                                      + (((unsigned int)ca + d[6] * c[2] + d[5] * (unsigned __int64)c[3]) >> 32)
                                      + (((_DWORD)ca + d[6] * c[2] + d[5] * c[3] + c[4] * (unsigned __int64)d[4]) >> 32)
                                      + (((_DWORD)ca
                                        + d[6] * c[2]
                                        + d[5] * c[3]
                                        + c[4] * d[4]
                                        + c[5] * (unsigned __int64)d[3]) >> 32))
                       + (((_DWORD)ca
                         + d[6] * c[2]
                         + d[5] * c[3]
                         + c[4] * d[4]
                         + c[5] * d[3]
                         + d[2] * (unsigned __int64)c[6]) >> 32)) >> 32);
  v35 = (_DWORD)ca + d[6] * c[2] + d[5] * c[3] + c[4] * d[4] + c[5] * d[3] + d[2] * c[6] + d[1] * (unsigned __int64)c[7];
  v36 = (unsigned int)(v34
                     + (((unsigned int)ca + d[6] * (unsigned __int64)c[2]) >> 32)
                     + (((unsigned int)ca + d[6] * c[2] + d[5] * (unsigned __int64)c[3]) >> 32)
                     + (((_DWORD)ca + d[6] * c[2] + d[5] * c[3] + c[4] * (unsigned __int64)d[4]) >> 32)
                     + (((_DWORD)ca + d[6] * c[2] + d[5] * c[3] + c[4] * d[4] + c[5] * (unsigned __int64)d[3]) >> 32)
                     + (((_DWORD)ca
                       + d[6] * c[2]
                       + d[5] * c[3]
                       + c[4] * d[4]
                       + c[5] * d[3]
                       + d[2] * (unsigned __int64)c[6]) >> 32))
      + (unsigned __int64)HIDWORD(v35);
  Ra[8] = v35;
  LODWORD(ca) = v36 + c[2] * d[7];
  v37 = ((((unsigned int)v36 + c[2] * (unsigned __int64)d[7]) >> 32)
       + (unsigned int)Rf
       + HIDWORD(v36)
       + v80
       + v76
       + v72
       + v68
       + HIDWORD(v34)) >> 32;
  v38 = (char *)Rf
      + HIDWORD(v36)
      + v80
      + v76
      + v72
      + v68
      + HIDWORD(v34)
      + (((unsigned int)v36 + c[2] * (unsigned __int64)d[7]) >> 32)
      + (((unsigned int)ca + d[6] * (unsigned __int64)c[3]) >> 32);
  v73 = ((unsigned int)((unsigned int)Rf
                      + HIDWORD(v36)
                      + v80
                      + v76
                      + v72
                      + v68
                      + HIDWORD(v34)
                      + (((unsigned int)v36 + c[2] * (unsigned __int64)d[7]) >> 32))
       + (((unsigned int)ca + d[6] * (unsigned __int64)c[3]) >> 32)) >> 32;
  v77 = (unsigned int)&v38[((unsigned int)ca + d[6] * c[3] + d[5] * (unsigned __int64)c[4]) >> 32] >> 32;
  v81 = (unsigned int)&v38[(((unsigned int)ca + d[6] * c[3] + d[5] * (unsigned __int64)c[4]) >> 32)
                         + (((_DWORD)ca + d[6] * c[3] + d[5] * c[4] + c[5] * (unsigned __int64)d[4]) >> 32)] >> 32;
  v39 = (unsigned __int64)&v38[(((unsigned int)ca + d[6] * c[3] + d[5] * (unsigned __int64)c[4]) >> 32)
                             + (((_DWORD)ca + d[6] * c[3] + d[5] * c[4] + c[5] * (unsigned __int64)d[4]) >> 32)
                             + (((_DWORD)ca + d[6] * c[3] + d[5] * c[4] + c[5] * d[4] + d[3] * (unsigned __int64)c[6]) >> 32)];
  v40 = (_DWORD)ca + d[6] * c[3] + d[5] * c[4] + c[5] * d[4] + d[3] * c[6] + d[2] * (unsigned __int64)c[7];
  Ra[9] = v40;
  LODWORD(ca) = v39 + HIDWORD(v40) + d[7] * c[3];
  v41 = (((unsigned int)(v39 + HIDWORD(v40)) + d[7] * (unsigned __int64)c[3]) >> 32)
      + (unsigned int)(v37
                     + v73
                     + v77
                     + v81
                     + HIDWORD(v39)
                     + (((unsigned int)v39 + (unsigned __int64)HIDWORD(v40)) >> 32));
  v78 = ((unsigned int)v41 + (((unsigned int)ca + d[6] * (unsigned __int64)c[4]) >> 32)) >> 32;
  v82 = ((unsigned int)(v41 + (((unsigned int)ca + d[6] * (unsigned __int64)c[4]) >> 32))
       + (((unsigned int)ca + d[6] * c[4] + d[5] * (unsigned __int64)c[5]) >> 32)) >> 32;
  Rg = (unsigned int *)(((unsigned int)(v41
                                      + (((unsigned int)ca + d[6] * (unsigned __int64)c[4]) >> 32)
                                      + (((unsigned int)ca + d[6] * c[4] + d[5] * (unsigned __int64)c[5]) >> 32))
                       + (((_DWORD)ca + d[6] * c[4] + d[5] * c[5] + d[4] * (unsigned __int64)c[6]) >> 32)) >> 32);
  v42 = (_DWORD)ca + d[6] * c[4] + d[5] * c[5] + d[4] * c[6] + d[3] * (unsigned __int64)c[7];
  v43 = (unsigned int)(v41
                     + (((unsigned int)ca + d[6] * (unsigned __int64)c[4]) >> 32)
                     + (((unsigned int)ca + d[6] * c[4] + d[5] * (unsigned __int64)c[5]) >> 32)
                     + (((_DWORD)ca + d[6] * c[4] + d[5] * c[5] + d[4] * (unsigned __int64)c[6]) >> 32))
      + (unsigned __int64)HIDWORD(v42);
  Ra[10] = v42;
  v44 = (unsigned int)v43 + c[4] * (unsigned __int64)d[7];
  LODWORD(ca) = v43 + c[4] * d[7];
  v45 = (int)Rg + HIDWORD(v43) + v82 + v78 + HIDWORD(v41);
  v46 = HIDWORD(v44) + (unsigned __int64)(unsigned int)v45;
  v83 = ((unsigned int)(HIDWORD(v44) + v45) + (((unsigned int)ca + d[6] * (unsigned __int64)c[5]) >> 32)) >> 32;
  Rh = (unsigned int *)(((unsigned int)(HIDWORD(v44) + v45 + (((unsigned int)ca + d[6] * (unsigned __int64)c[5]) >> 32))
                       + (((unsigned int)ca + d[6] * c[5] + d[5] * (unsigned __int64)c[6]) >> 32)) >> 32);
  HIDWORD(ca) = HIDWORD(v44)
              + v45
              + (((unsigned int)ca + d[6] * (unsigned __int64)c[5]) >> 32)
              + (((unsigned int)ca + d[6] * c[5] + d[5] * (unsigned __int64)c[6]) >> 32);
  v47 = (_DWORD)ca + d[6] * c[5] + d[5] * c[6] + c[7] * (unsigned __int64)d[4];
  v48 = HIDWORD(ca) + (unsigned __int64)HIDWORD(v47);
  Ra[11] = v47;
  LODWORD(ca) = v48 + c[5] * d[7];
  v49 = (((unsigned int)v48 + c[5] * (unsigned __int64)d[7]) >> 32)
      + (unsigned int)Rh
      + HIDWORD(v48)
      + v83
      + HIDWORD(v46);
  Ri = (unsigned int *)(((unsigned int)v49 + (((unsigned int)ca + d[6] * (unsigned __int64)c[6]) >> 32)) >> 32);
  v50 = (unsigned int)ca + d[6] * c[6] + d[5] * (unsigned __int64)c[7];
  v51 = (unsigned int)(v49 + (((unsigned int)ca + d[6] * (unsigned __int64)c[6]) >> 32))
      + (unsigned __int64)HIDWORD(v50);
  Ra[12] = v50;
  v52 = (unsigned int)v51 + d[7] * (unsigned __int64)c[6];
  LODWORD(ca) = v51 + d[7] * c[6];
  v53 = (int)Ri + HIDWORD(v51) + HIDWORD(v49);
  v54 = HIDWORD(v52) + (unsigned __int64)(unsigned int)v53;
  v55 = (unsigned int)(HIDWORD(v52) + v53) + (((unsigned int)ca + d[6] * (unsigned __int64)c[7]) >> 32);
  v56 = HIDWORD(v52) + v53 + (((unsigned int)ca + d[6] * (unsigned __int64)c[7]) >> 32);
  Ra[13] = ca + d[6] * c[7];
  v57 = c[7] * (unsigned __int64)d[7];
  Ra[14] = v56 + v57;
  Ra[15] = HIDWORD(v54) + ((__PAIR64__(HIDWORD(v55), v56) + v57) >> 32);
  return (const CUtlSymbolTable::CStringPoolIndex *)HIDWORD(v55);
}

//------------------------------------------------------------------------------
// Address: 0x0043E6F0
// Name: public: static void TaoCrypt::Portable::Multiply4Bottom(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlSymbolTable::CStringPoolIndex *__thiscall TaoCrypt::Portable::Multiply4Bottom(
        unsigned __int16 R,
        unsigned int *Ra,
        unsigned int *d,
        unsigned int *c)
{
  unsigned int v5; // ebx
  unsigned int v6; // kr00_4
  __int64 v7; // kr08_8
  unsigned int v8; // eax
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // kr10_8
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  const CUtlSymbolTable::CStringPoolIndex *result; // eax
  unsigned int da; // [esp+20h] [ebp+8h]
  unsigned int db; // [esp+20h] [ebp+8h]

  v6 = *c;
  v7 = *d;
  v5 = ((unsigned __int64)*c * v7) >> 32;
  *Ra = *c * *d;
  v8 = d[1];
  da = (v5 + c[1] * (unsigned __int64)*d) >> 32;
  v9 = ((__PAIR64__(c[1], v6) * v7) >> 32) + *c * (unsigned __int64)v8;
  Ra[1] = v9;
  v10 = da + (unsigned __int64)HIDWORD(v9);
  v11 = (unsigned int)v10 + d[2] * (unsigned __int64)*c;
  db = HIDWORD(v11) + HIDWORD(v10);
  v12 = (unsigned int)v11 + c[1] * (unsigned __int64)d[1];
  HIDWORD(v12) += db + (((unsigned int)v12 + *d * (unsigned __int64)c[2]) >> 32);
  Ra[2] = v12 + *d * c[2];
  result = (const CUtlSymbolTable::CStringPoolIndex *)(*c * d[3] + *d * c[3]);
  Ra[3] = (unsigned int)result + HIDWORD(v12) + c[2] * d[1] + c[1] * d[2];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043E7D0
// Name: public: static void TaoCrypt::Portable::Multiply8Bottom(unsigned int __near *,unsigned int const __near *,unsigned int const __near *)
// Source: json
//------------------------------------------------------------------------------
const CUtlSymbolTable::CStringPoolIndex *__thiscall TaoCrypt::Portable::Multiply8Bottom(
        unsigned __int16 R,
        unsigned int *Ra,
        unsigned int *c,
        unsigned int *d)
{
  unsigned int v6; // ebx
  unsigned __int64 v8; // kr18_8
  unsigned __int64 v9; // kr20_8
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // kr30_8
  unsigned __int64 v12; // rax
  int v13; // kr04_4
  unsigned __int64 v14; // kr38_8
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // kr50_8
  unsigned __int64 v17; // rax
  int v18; // kr0C_4
  unsigned __int64 v19; // kr58_8
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // kr78_8
  unsigned __int64 v22; // kr80_8
  unsigned int v23; // krA0_4
  unsigned __int64 v24; // krA8_8
  unsigned __int64 v25; // rax
  char *v26; // ebx
  unsigned __int64 v27; // rax
  char *v28; // ebx
  unsigned __int64 v29; // rax
  char *v30; // ebx
  unsigned __int64 v31; // rax
  char *v32; // ebx
  unsigned __int64 v33; // rax
  const CUtlSymbolTable::CStringPoolIndex *result; // eax
  int v35; // [esp+10h] [ebp-14h]
  int v36; // [esp+10h] [ebp-14h]
  int v37; // [esp+10h] [ebp-14h]
  int v38; // [esp+14h] [ebp-10h]
  int v39; // [esp+14h] [ebp-10h]
  int v40; // [esp+18h] [ebp-Ch]
  unsigned int *Rb; // [esp+28h] [ebp+4h]
  unsigned int *Rc; // [esp+28h] [ebp+4h]
  unsigned int *Rd; // [esp+28h] [ebp+4h]
  unsigned int *Re; // [esp+28h] [ebp+4h]
  unsigned __int64 ca; // [esp+2Ch] [ebp+8h]

  v6 = (*d * (unsigned __int64)*c) >> 32;
  *Ra = *d * *c;
  ca = v6 + d[1] * (unsigned __int64)*c;
  v8 = HIDWORD(ca) + (((unsigned int)ca + *d * (unsigned __int64)c[1]) >> 32);
  Ra[1] = ca + *d * c[1];
  LODWORD(ca) = v8 + c[2] * *d;
  v9 = (((unsigned int)v8 + c[2] * (unsigned __int64)*d) >> 32) + HIDWORD(v8);
  Rb = (unsigned int *)(((unsigned int)v9 + (((unsigned int)ca + d[1] * (unsigned __int64)c[1]) >> 32)) >> 32);
  v10 = (unsigned int)ca + d[1] * c[1] + *c * (unsigned __int64)d[2];
  v11 = (unsigned int)(v9 + (((unsigned int)ca + d[1] * (unsigned __int64)c[1]) >> 32)) + (unsigned __int64)HIDWORD(v10);
  Ra[2] = v10;
  v12 = (unsigned int)v11 + *c * (unsigned __int64)d[3];
  LODWORD(ca) = v11 + *c * d[3];
  v13 = (int)Rb + HIDWORD(v11) + HIDWORD(v9);
  v14 = HIDWORD(v12) + (unsigned __int64)(unsigned int)v13;
  v35 = ((unsigned int)(HIDWORD(v12) + v13) + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32)) >> 32;
  Rc = (unsigned int *)(((unsigned int)(HIDWORD(v12) + v13 + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32))
                       + (((unsigned int)ca + d[2] * c[1] + d[1] * (unsigned __int64)c[2]) >> 32)) >> 32);
  HIDWORD(ca) = HIDWORD(v12)
              + v13
              + (((unsigned int)ca + d[2] * (unsigned __int64)c[1]) >> 32)
              + (((unsigned int)ca + d[2] * c[1] + d[1] * (unsigned __int64)c[2]) >> 32);
  v15 = (_DWORD)ca + d[2] * c[1] + d[1] * c[2] + *d * (unsigned __int64)c[3];
  v16 = HIDWORD(ca) + (unsigned __int64)HIDWORD(v15);
  Ra[3] = v15;
  v17 = (unsigned int)v16 + *c * (unsigned __int64)d[4];
  LODWORD(ca) = v16 + *c * d[4];
  v18 = (int)Rc + HIDWORD(v16) + v35 + HIDWORD(v14);
  v19 = HIDWORD(v17) + (unsigned __int64)(unsigned int)v18;
  v38 = ((unsigned int)(HIDWORD(v17) + v18) + (((unsigned int)ca + d[3] * (unsigned __int64)c[1]) >> 32)) >> 32;
  v36 = ((unsigned int)(HIDWORD(v17) + v18 + (((unsigned int)ca + d[3] * (unsigned __int64)c[1]) >> 32))
       + (((unsigned int)ca + d[3] * c[1] + c[2] * (unsigned __int64)d[2]) >> 32)) >> 32;
  Rd = (unsigned int *)(((unsigned int)(HIDWORD(v17)
                                      + v18
                                      + (((unsigned int)ca + d[3] * (unsigned __int64)c[1]) >> 32)
                                      + (((unsigned int)ca + d[3] * c[1] + c[2] * (unsigned __int64)d[2]) >> 32))
                       + (((_DWORD)ca + d[3] * c[1] + c[2] * d[2] + d[1] * (unsigned __int64)c[3]) >> 32)) >> 32);
  HIDWORD(ca) = HIDWORD(v17)
              + v18
              + (((unsigned int)ca + d[3] * (unsigned __int64)c[1]) >> 32)
              + (((unsigned int)ca + d[3] * c[1] + c[2] * (unsigned __int64)d[2]) >> 32)
              + (((_DWORD)ca + d[3] * c[1] + c[2] * d[2] + d[1] * (unsigned __int64)c[3]) >> 32);
  v20 = (_DWORD)ca + d[3] * c[1] + c[2] * d[2] + d[1] * c[3] + c[4] * (unsigned __int64)*d;
  v21 = HIDWORD(ca) + (unsigned __int64)HIDWORD(v20);
  Ra[4] = v20;
  LODWORD(ca) = v21 + d[5] * *c;
  v22 = (((unsigned int)v21 + d[5] * (unsigned __int64)*c) >> 32)
      + (unsigned int)Rd
      + HIDWORD(v21)
      + v36
      + v38
      + HIDWORD(v19);
  v40 = ((unsigned int)v22 + (((unsigned int)ca + c[1] * (unsigned __int64)d[4]) >> 32)) >> 32;
  v37 = ((unsigned int)(v22 + (((unsigned int)ca + c[1] * (unsigned __int64)d[4]) >> 32))
       + (((unsigned int)ca + c[1] * d[4] + c[2] * (unsigned __int64)d[3]) >> 32)) >> 32;
  v39 = ((unsigned int)(v22
                      + (((unsigned int)ca + c[1] * (unsigned __int64)d[4]) >> 32)
                      + (((unsigned int)ca + c[1] * d[4] + c[2] * (unsigned __int64)d[3]) >> 32))
       + (((_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * (unsigned __int64)c[3]) >> 32)) >> 32;
  v23 = v22
      + (((unsigned int)ca + c[1] * (unsigned __int64)d[4]) >> 32)
      + (((unsigned int)ca + c[1] * d[4] + c[2] * (unsigned __int64)d[3]) >> 32)
      + (((_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * (unsigned __int64)c[3]) >> 32)
      + (((_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * c[3] + d[1] * (unsigned __int64)c[4]) >> 32);
  Re = (unsigned int *)(((unsigned int)(v22
                                      + (((unsigned int)ca + c[1] * (unsigned __int64)d[4]) >> 32)
                                      + (((unsigned int)ca + c[1] * d[4] + c[2] * (unsigned __int64)d[3]) >> 32)
                                      + (((_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * (unsigned __int64)c[3]) >> 32))
                       + (((_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * c[3] + d[1] * (unsigned __int64)c[4]) >> 32)) >> 32);
  v24 = (_DWORD)ca + c[1] * d[4] + c[2] * d[3] + d[2] * c[3] + d[1] * c[4] + c[5] * (unsigned __int64)*d;
  Ra[5] = v24;
  v25 = v23 + HIDWORD(v24) + d[6] * (unsigned __int64)*c;
  LODWORD(ca) = v25 + d[5] * c[1];
  v26 = (char *)Re
      + ((v23 + (unsigned __int64)HIDWORD(v24)) >> 32)
      + v39
      + v37
      + v40
      + HIDWORD(v22)
      + HIDWORD(v25)
      + (((unsigned int)v25 + d[5] * (unsigned __int64)c[1]) >> 32);
  v27 = (unsigned int)ca + c[2] * (unsigned __int64)d[4];
  LODWORD(ca) = ca + c[2] * d[4];
  v28 = &v26[HIDWORD(v27)];
  v29 = (unsigned int)ca + d[3] * (unsigned __int64)c[3];
  LODWORD(ca) = ca + d[3] * c[3];
  v30 = &v28[HIDWORD(v29)];
  v31 = (unsigned int)ca + c[4] * (unsigned __int64)d[2];
  LODWORD(ca) = ca + c[4] * d[2];
  v32 = &v30[HIDWORD(v31)];
  v33 = (unsigned int)ca + d[1] * (unsigned __int64)c[5];
  LODWORD(ca) = ca + d[1] * c[5];
  HIDWORD(v33) += &v32[((unsigned int)ca + *d * (unsigned __int64)c[6]) >> 32];
  Ra[6] = ca + *d * c[6];
  result = (const CUtlSymbolTable::CStringPoolIndex *)(c[5] * d[2]
                                                     + c[4] * d[3]
                                                     + d[6] * c[1]
                                                     + d[1] * c[6]
                                                     + *d * c[7]
                                                     + *c * d[7]);
  Ra[7] = (unsigned int)result + HIDWORD(v33) + d[4] * c[3] + d[5] * c[2];
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043EBE0
// Name: TaoCrypt::SetPentiumFunctionPointers
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043ECB0
// Name: void TaoCrypt::RecursiveSquare(unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043ED80
// Name: void TaoCrypt::RecursiveMultiplyBottom(unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043EE50
// Name: void TaoCrypt::AsymmetricMultiply(unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x0043F050
// Name: unsigned int TaoCrypt::AlmostInverse(unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TaoCrypt::AlmostInverse(
        TaoCrypt *this,
        unsigned int *bcLen,
        char *a3,
        const unsigned int *NA,
        unsigned int a5,
        unsigned int N)
{
  unsigned int *v7; // esi
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *v8; // ebp
  const unsigned int *v9; // eax
  _DWORD *v10; // ecx
  unsigned int v11; // ebx
  unsigned int v12; // ecx
  const unsigned int *v13; // edx
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *v14; // eax
  const unsigned int *v15; // edx
  unsigned int *v16; // eax
  unsigned int v17; // eax
  int v18; // ecx
  unsigned int v19; // edx
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *v20; // eax
  CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *p_m_Elements; // esi
  unsigned int v22; // edx
  unsigned int v23; // eax
  unsigned int *v24; // edx
  unsigned int i; // esi
  _DWORD *v26; // eax
  unsigned int *v27; // edi
  void *v28; // ecx
  unsigned int v29; // eax
  unsigned int *v30; // esi
  unsigned int *v31; // eax
  const unsigned int *v33; // edx
  TaoCrypt *v34; // eax
  int v35; // [esp-10h] [ebp-38h]
  int v36; // [esp-Ch] [ebp-34h]
  int v37; // [esp-8h] [ebp-30h]
  int v38; // [esp-4h] [ebp-2Ch]
  int v39; // [esp+0h] [ebp-28h]
  int v40; // [esp+4h] [ebp-24h]
  int v41; // [esp+8h] [ebp-20h]
  int v42; // [esp+Ch] [ebp-1Ch]
  unsigned int *c; // [esp+10h] [ebp-18h]
  unsigned int *b; // [esp+14h] [ebp-14h]
  unsigned int k; // [esp+18h] [ebp-10h]
  unsigned int *g; // [esp+1Ch] [ebp-Ch]
  unsigned int v47; // [esp+20h] [ebp-8h]
  char s; // [esp+24h] [ebp-4h]
  unsigned int bcLena; // [esp+30h] [ebp+8h]
  unsigned int *NAa; // [esp+38h] [ebp+10h]

  v7 = &bcLen[3 * N];
  c = &bcLen[N];
  b = bcLen;
  v8 = (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&bcLen[2 * N];
  g = v7;
  bcLena = 2;
  v9 = (const unsigned int *)N;
  if ( N != 0 )
  {
    v10 = (_DWORD *)(a5 + 4 * N - 4);
    do
    {
      if ( *(v10 - 1) != 0 )
        break;
      if ( *v10 != 0 )
        break;
      v9 = (const unsigned int *)((char *)v9 - 2);
      v10 -= 2;
    }
    while ( v9 != nullptr );
  }
  v11 = (unsigned int)v9;
  v12 = 3 * N;
  k = 0;
  s = 0;
  if ( 3 * N != 0 )
  {
    memset(bcLen, 0, 12 * N);
    v12 = 0;
  }
  *bcLen = 1;
  v13 = NA;
  if ( NA != nullptr )
  {
    v14 = v8;
    v12 = a3 - (char *)v8;
    do
    {
      *(_DWORD *)&v14->m_LessFunc = *(_DWORD *)(&v14->m_LessFunc + v12);
      v14 = (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)((char *)v14 + 4);
      v13 = (const unsigned int *)((char *)v13 - 1);
    }
    while ( v13 != nullptr );
  }
  v15 = (const unsigned int *)N;
  if ( N != 0 )
  {
    v16 = v7;
    v12 = a5 - (_DWORD)v7;
    do
    {
      *v16 = *(unsigned int *)((char *)v16 + v12);
      ++v16;
      v15 = (const unsigned int *)((char *)v15 - 1);
    }
    while ( v15 != nullptr );
  }
  while ( 1 )
  {
    v17 = *(_DWORD *)&v8->m_LessFunc;
    if ( *(_DWORD *)&v8->m_LessFunc == 0 )
      break;
LABEL_34:
    for ( i = 0; (v17 & 1) == 0; ++i )
      v17 >>= 1;
    k += i;
    if ( v17 == 1 && v8->m_Elements.m_pMemory == nullptr )
    {
      v12 = v11;
      if ( v11 != 0 )
      {
        v26 = (_DWORD *)((char *)v8 + 4 * v11 - 4);
        do
        {
          if ( *(v26 - 1) != 0 )
            break;
          if ( *v26 != 0 )
            break;
          v12 -= 2;
          v26 -= 2;
        }
        while ( v12 != 0 );
      }
      if ( v12 == 2 )
      {
        if ( (s & 1) != 0 )
        {
          s_pSub(a1: this, a2: a5, a3: b, a4: N);
        }
        else
        {
          v33 = (const unsigned int *)N;
          if ( N != 0 )
          {
            v34 = this;
            do
            {
              *(_DWORD *)v34 = *(_DWORD *)((char *)v34 + (char *)b - (char *)this);
              v34 = (TaoCrypt *)((char *)v34 + 4);
              v33 = (const unsigned int *)((char *)v33 - 1);
            }
            while ( v33 != nullptr );
            return k;
          }
        }
        return k;
      }
    }
    TaoCrypt::ShiftWordsRightByBits(r: (void *)v12, ra: (unsigned int *)v8, n: v11, shiftBits: i);
    v27 = c;
    TaoCrypt::ShiftWordsLeftByBits(r: v28, ra: c, n: bcLena, shiftBits: i);
    if ( v29 != 0 )
    {
      c[bcLena] = v29;
      bcLena += 2;
    }
    v30 = g;
    if ( *((_DWORD *)v8 + v11 - 2) == 0 && g[v11 - 2] == 0 && *((_DWORD *)v8 + v11 - 1) == 0 && g[v11 - 1] == 0 )
      v11 -= 2;
    if ( TaoCrypt::Compare(a1: v11, a2: (int)g, result: v8) == -1 )
    {
      ++s;
      g = (unsigned int *)v8;
      v31 = b;
      v8 = (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)v30;
      v30 = g;
      b = c;
      c = v31;
    }
    else
    {
      v27 = b;
    }
    s_pSub(a1: v8, a2: v8, a3: v30, a4: v11);
    if ( s_pAdd(
           a1: v27,
           a2: v27,
           a3: c,
           a4: bcLena,
           a5: v35,
           a6: v36,
           a7: v37,
           a8: v38,
           a9: v39,
           a10: v40,
           a11: v41,
           a12: v42,
           a13: c,
           a14: b) != 0 )
    {
      b[bcLena] = 1;
      bcLena += 2;
    }
  }
  v47 = bcLena - 1;
  NAa = &c[bcLena - 1];
  while ( TaoCrypt::EvenWordCount(X: (int)v8, N: v11) != 0 )
  {
    v18 = 1;
    if ( v11 > 1 )
    {
      v19 = 1;
      v20 = v8;
      p_m_Elements = &v8->m_Elements;
      do
      {
        *(_DWORD *)&v20->m_LessFunc = p_m_Elements->m_pMemory;
        ++v19;
        v20 = (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)((char *)v20 + 4);
        p_m_Elements = (CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> *)((char *)p_m_Elements + 4);
      }
      while ( v19 < v11 );
LABEL_22:
      if ( v18 != 0 )
        memset((char *)v8 + 4 * (v11 - v18), 0, 4 * v18);
      goto LABEL_24;
    }
    v18 = v11;
    if ( v11 != 0 )
      goto LABEL_22;
LABEL_24:
    v22 = bcLena;
    v23 = v47;
    if ( *NAa != 0 )
    {
      NAa += 2;
      v22 = bcLena + 2;
      v23 = v47 + 2;
      bcLena += 2;
      v47 += 2;
    }
    v12 = 1;
    if ( v22 > 1 || (v12 = v22, v22 != 0) )
    {
      if ( v23 >= v12 )
      {
        v24 = &c[v23 - v12];
        do
          c[v23--] = *v24--;
        while ( v23 >= v12 );
      }
      if ( v12 != 0 )
      {
        memset(c, 0, 4 * v12);
        v12 = 0;
      }
    }
    v17 = *(_DWORD *)&v8->m_LessFunc;
    k += 32;
    if ( *(_DWORD *)&v8->m_LessFunc != 0 )
      goto LABEL_34;
  }
  if ( N != 0 )
    memset(this, 0, 4 * N);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043F360
// Name: public: bool TaoCrypt::Integer::GetBit(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TaoCrypt::Integer::GetBit(TaoCrypt::Integer *this, unsigned int a2)
{
  int v2; // eax

  if ( a2 >> 5 < this->m_stackLevel )
    return (*(_DWORD *)(*((_DWORD *)this + 1) + 4 * (a2 >> 5)) >> (a2 & 0x1F)) & 1;
  else
    LOBYTE(v2) = 0;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x0043F390
// Name: public: unsigned char TaoCrypt::Integer::GetByte(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::Integer::GetByte(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        void *n,
        int a3,
        FileSystemSeek_t a4)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x0043F3C0
// Name: public: unsigned int TaoCrypt::Integer::WordCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::Integer::WordCount(int *this)
{
  int result; // eax
  _DWORD *v2; // ecx

  result = *this;
  if ( *this != 0 )
  {
    v2 = (_DWORD *)(*(this + 1) + 4 * result - 4);
    do
    {
      if ( *v2 != 0 )
        break;
      --result;
      --v2;
    }
    while ( result != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043F3E0
// Name: TaoCrypt::CorrectQuotientEstimate
// Source: json
//------------------------------------------------------------------------------
void __usercall TaoCrypt::CorrectQuotientEstimate(
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *R@<edi>,
        unsigned int *a2@<esi>,
        unsigned int *T,
        int a4,
        unsigned int N)
{
  unsigned int *v5; // ebx
  int v7; // ecx
  _DWORD *v8; // ebx
  bool v9; // zf
  unsigned int v10; // [esp+8h] [ebp-4h]
  unsigned int Na; // [esp+18h] [ebp+Ch]
  unsigned int *Nb; // [esp+18h] [ebp+Ch]

  v5 = T;
  if ( a2[1] != 0 )
  {
    T[N + 1] = 0;
    T[N] = 0;
    if ( N != 0 )
    {
      v7 = a4 - (_DWORD)T;
      Na = ((N - 1) >> 2) + 1;
      while ( 1 )
      {
        TaoCrypt::Portable::Multiply2(C: (_WORD)v5 + v7, Ca: v5, a3: a2, a4: (unsigned int *)((char *)v5 + v7));
        v5 += 4;
        if ( --Na == 0 )
          break;
        v7 = a4 - (_DWORD)T;
      }
      v5 = T;
    }
    if ( N > 2 )
    {
      Nb = (unsigned int *)(a4 + 8);
      v8 = v5 + 7;
      v10 = ((N - 3) >> 2) + 1;
      do
      {
        if ( TaoCrypt::Portable::Multiply2Add(C: v8 - 5, a2, bi: Nb) != 0 )
        {
          v9 = (*(v8 - 1))++ == -1;
          *v8 += v9;
        }
        Nb += 4;
        v8 += 4;
        --v10;
      }
      while ( v10 != 0 );
      v5 = T;
    }
  }
  else
  {
    T[N] = TaoCrypt::LinearMultiply(a1: T, a2: a4, a3: *a2, a4: N);
    T[N + 1] = 0;
  }
  s_pSub(a1: R, a2: R, a3: v5, a4: N + 2);
  while ( *((_DWORD *)&R->m_LessFunc + N) != 0 || TaoCrypt::Compare(a1: N, a2: a4, result: R) >= 0 )
  {
    *((_DWORD *)&R->m_LessFunc + N) -= s_pSub(a1: R, a2: R, a3: a4, a4: N);
    v9 = (*a2)++ == -1;
    a2[1] += v9;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F510
// Name: public: unsigned int TaoCrypt::Integer::Modulo(unsigned int)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::Integer::Modulo(TaoCrypt::Integer *this, unsigned int divisor)
{
  TaoCrypt::Integer *v2; // edi
  unsigned __int64 v3; // rax
  int v4; // eax
  int v5; // esi
  unsigned __int64 v6; // kr00_8
  int v7; // eax
  unsigned int v8; // ebp
  int v9; // edi
  unsigned int v10; // ecx

  v2 = this;
  if ( ((divisor - 1) & divisor) != 0 )
  {
    v4 = TaoCrypt::Integer::WordCount(this: &this->m_stackLevel);
    v5 = v4;
    if ( divisor > 5 )
    {
      LODWORD(v3) = 0;
      if ( v5 != 0 )
      {
        v9 = v2[1].m_stackLevel + 4 * v5;
        do
        {
          v10 = *(_DWORD *)(v9 - 4);
          v9 -= 4;
          --v5;
          v3 = __PAIR64__(v3, v10) % divisor;
        }
        while ( v5 != 0 );
        v2 = this;
      }
    }
    else
    {
      v6 = 0;
      if ( v4 != 0 )
      {
        v7 = v2[1].m_stackLevel + 4 * v4;
        do
        {
          v8 = *(_DWORD *)(v7 - 4);
          v7 -= 4;
          --v5;
          v6 += v8;
        }
        while ( v5 != 0 );
      }
      v3 = v6 % divisor;
    }
  }
  else
  {
    LODWORD(v3) = (divisor - 1) & **((_DWORD **)this + 1);
  }
  if ( v2[3].m_stackLevel == 1 && (_DWORD)v3 != 0 )
    LODWORD(v3) = divisor - v3;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0043F5B0
// Name: public: bool TaoCrypt::Integer::IsUnit(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall TaoCrypt::Integer::IsUnit(CInternalFileSystemPassThru<IFileSystem> *this)
{
  return TaoCrypt::Integer::WordCount((int *)this) == 1
      && this->Read == (int (__thiscall *)(IBaseFileSystem *, void *, int, void *))1;
}

//------------------------------------------------------------------------------
// Address: 0x0043F5D0
// Name: void TaoCrypt::MontgomeryReduce(unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int const __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TaoCrypt::MontgomeryReduce(
        TaoCrypt *this,
        unsigned int *T,
        unsigned int *a3,
        CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *a4,
        const unsigned int *a5,
        unsigned int N)
{
  const CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *v6; // ecx
  int v9; // ebx
  unsigned int result; // eax
  unsigned int *v11; // ecx
  int v12; // [esp-3Ch] [ebp-4Ch]
  int v13; // [esp-38h] [ebp-48h]
  int v14; // [esp-34h] [ebp-44h]
  int v15; // [esp-30h] [ebp-40h]
  int v16; // [esp-2Ch] [ebp-3Ch]
  int v17; // [esp-28h] [ebp-38h]
  int v18; // [esp-24h] [ebp-34h]
  int v19; // [esp-20h] [ebp-30h]
  int v20; // [esp-1Ch] [ebp-2Ch]
  int v21; // [esp-18h] [ebp-28h]

  TaoCrypt::RecursiveMultiplyBottom(R: v6);
  TaoCrypt::RecursiveMultiplyTop(
    this: (TaoCrypt *)T,
    T: &T[N],
    a3,
    result: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this,
    a5: a4,
    carry: (const unsigned int *)N,
    a7: (unsigned int)this);
  v9 = s_pSub(a1: T, a2: &a3[N], a3: T, a4: N);
  s_pAdd(
    a1: &T[N],
    a2: T,
    a3: a4,
    a4: N,
    a5: v12,
    a6: v13,
    a7: v14,
    a8: v15,
    a9: v16,
    a10: v17,
    a11: v18,
    a12: v19,
    a13: v20,
    a14: v21);
  result = 0;
  if ( N != 0 )
  {
    v11 = &T[v9 != 0 ? N : 0];
    do
      *((_DWORD *)this + result++) = *v11++;
    while ( result < N );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0043F650
// Name: void TaoCrypt::RecursiveInverseModPower2(unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const CUtlSymbolTable::CStringPoolIndex *__usercall TaoCrypt::RecursiveInverseModPower2@<eax>(
        int a1@<ecx>,
        unsigned int a2@<ebp>,
        unsigned int *R,
        unsigned int *T,
        int *a5,
        unsigned int N)
{
  unsigned __int16 v6; // cx
  unsigned __int16 v7; // cx
  unsigned int v9; // esi
  const CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *v10; // ecx
  int v11; // [esp-1Ch] [ebp-28h]
  int v12; // [esp-18h] [ebp-24h]
  int v13; // [esp-14h] [ebp-20h]
  int v14; // [esp-10h] [ebp-1Ch]
  int v15; // [esp-Ch] [ebp-18h]

  if ( N == 2 )
  {
    *T = TaoCrypt::AtomicInverseModPower2(a1, a2: *a5);
    T[1] = 0;
    TaoCrypt::Portable::Multiply2Bottom(C: v6, Ca: T + 2, a3: T, a4: (unsigned int *)a5);
    TaoCrypt::TwosComplement(a1: 2u, a2: T + 2);
    TaoCrypt::Increment(A: T + 2, a2: 2, a3: 2u);
    return TaoCrypt::Portable::Multiply2Bottom(C: v7, Ca: R, a3: T, a4: T + 2);
  }
  else
  {
    v9 = N >> 1;
    TaoCrypt::RecursiveInverseModPower2();
    *T = 1;
    if ( N >> 1 != 1 )
      memset(T + 1, 0, 4 * ((N >> 1) - 1));
    TaoCrypt::RecursiveMultiplyTop(
      this: (TaoCrypt *)&R[v9],
      T: &T[v9],
      a3: T,
      result: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)R,
      (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)a5,
      carry: (const unsigned int *)v9,
      a7: a2);
    TaoCrypt::RecursiveMultiplyBottom(R: (const CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&a5[v9]);
    s_pAdd(
      a1: T,
      a2: &R[v9],
      a3: T,
      a4: v9,
      a5: T,
      a6: &T[v9],
      a7: R,
      a8: &a5[v9],
      a9: v9,
      a10: v11,
      a11: v12,
      a12: v13,
      a13: v14,
      a14: v15);
    TaoCrypt::TwosComplement(a1: v9, a2: T);
    return (const CUtlSymbolTable::CStringPoolIndex *)TaoCrypt::RecursiveMultiplyBottom(R: v10);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F740
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::MontgomeryRepresentation::Multiply(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__thiscall TaoCrypt::MontgomeryRepresentation::Multiply(
        IFileSystem *this,
        unsigned int **a,
        FSAsyncFile_t__ **b)
{
  TaoCrypt *v4; // ebx
  unsigned int v5; // ebp
  int v6; // ecx
  unsigned int v8; // [esp+0h] [ebp-18h]
  TaoCrypt *R; // [esp+14h] [ebp-4h]

  v4 = *((TaoCrypt **)this + 20);
  v5 = *((_DWORD *)this + 3);
  R = *((TaoCrypt **)this + 8);
  TaoCrypt::AsymmetricMultiply(
    this: v4,
    a2: (unsigned int *)v4 + 2 * v5,
    a3: a[1],
    a4: *a,
    a5: (unsigned int)b[1],
    a6: (const unsigned int *)*b,
    a7: v8);
  v6 = 2 * v5 - (_DWORD)*b - (_DWORD)*a;
  if ( v6 != 0 )
    memset((char *)v4 + 4 * ((int)*b + (_DWORD)*a), 0, 4 * v6);
  TaoCrypt::MontgomeryReduce(
    this: R,
    T: (unsigned int *)v4 + 2 * v5,
    a3: (unsigned int *)v4,
    a4: *((CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **)this
    + 4),
    a5: *((const unsigned int **)this + 16),
    N: v5);
  return (IFileSystem *)((char *)this + 28);
}

//------------------------------------------------------------------------------
// Address: 0x0043F7D0
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::MontgomeryRepresentation::Square(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__thiscall TaoCrypt::MontgomeryRepresentation::Square(IFileSystem *this, FSAsyncFile_t__ *a)
{
  unsigned int *v3; // ebx
  unsigned int v4; // ebp
  TaoCrypt *R; // [esp+14h] [ebp-4h]

  v3 = *((unsigned int **)this + 20);
  v4 = *((_DWORD *)this + 3);
  R = *((TaoCrypt **)this + 8);
  TaoCrypt::RecursiveSquare();
  if ( 2 * (v4 - *(_DWORD *)a) != 0 )
    memset(&v3[2 * *(_DWORD *)a], 0, 8 * (v4 - *(_DWORD *)a));
  TaoCrypt::MontgomeryReduce(
    this: R,
    T: &v3[2 * v4],
    a3: v3,
    a4: *((CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **)this
    + 4),
    a5: *((const unsigned int **)this + 16),
    N: v4);
  return (IFileSystem *)((char *)this + 28);
}

//------------------------------------------------------------------------------
// Address: 0x0043F840
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::MontgomeryRepresentation::MultiplicativeInverse(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__thiscall TaoCrypt::MontgomeryRepresentation::MultiplicativeInverse(
        IFileSystem *this,
        FSAsyncFile_t__ *a)
{
  unsigned int *v3; // ebp
  unsigned int v4; // ebx
  FSAsyncFile_t__ *v5; // eax
  int v6; // edi
  _DWORD *v7; // eax
  int v8; // ecx
  int v9; // eax
  unsigned int v10; // eax
  const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v11; // ecx
  TaoCrypt *R; // [esp+10h] [ebp-4h]

  v3 = *((unsigned int **)this + 20);
  v4 = *((_DWORD *)this + 3);
  R = *((TaoCrypt **)this + 8);
  v5 = a;
  v6 = *(_DWORD *)a;
  if ( *(_DWORD *)a != 0 )
  {
    v7 = *((_DWORD **)this + 20);
    v8 = *((_DWORD *)a + 1) - (_DWORD)v3;
    do
    {
      *v7 = *(_DWORD *)((char *)v7 + v8);
      ++v7;
      --v6;
    }
    while ( v6 != 0 );
    v5 = a;
  }
  v9 = *(_DWORD *)v5;
  if ( 2 * v4 != v9 )
    memset(&v3[v9], 0, 4 * (2 * v4 - v9));
  TaoCrypt::MontgomeryReduce(
    this: R,
    T: &v3[2 * v4],
    a3: v3,
    a4: *((CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **)this
    + 4),
    a5: *((const unsigned int **)this + 16),
    N: v4);
  v10 = TaoCrypt::AlmostInverse(
          this: R,
          bcLen: v3,
          a3: (char *)R,
          NA: (const unsigned int *)v4,
          a5: *((_DWORD *)this + 4),
          N: v4);
  v11 = (const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)(32 * v4);
  if ( v10 <= 32 * v4 )
    TaoCrypt::MultiplyByPower2Mod(
      R: (const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)((char *)v11 - v10),
      Ra: (unsigned int *)R,
      a3: (int)R,
      k: (unsigned int)v11 - v10,
      a5: *((_DWORD *)this + 4),
      N: v4);
  else
    TaoCrypt::DivideByPower2Mod(R: v11);
  return (IFileSystem *)((char *)this + 28);
}

//------------------------------------------------------------------------------
// Address: 0x0043F900
// Name: public: unsigned int __near * TaoCrypt::AlignedAllocator<unsigned int>::allocate(unsigned int,void const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::AlignedAllocator<unsigned int>::allocate(
        CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *this,
        unsigned int n,
        int __formal)
{
  if ( n != 0 )
  {
    if ( n < 4 )
      operator new[](sz: (const CSplitScreenAddedConVar *)(4 * n));
    else
      _aligned_malloc(size: 4 * n, alignment: 0x10u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043F950
// Name: public: void TaoCrypt::AlignedAllocator<unsigned int>::deallocate(void __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
        CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *this,
        unsigned __int8 *p,
        unsigned int n)
{
  memset(dst: p, value: 0, count: 4 * n);
  if ( n < 4 )
    TaoCrypt::tcArrayDelete<unsigned char>(ptr: p);
  else
    _aligned_free(memblock: p);
}

//------------------------------------------------------------------------------
// Address: 0x0043F990
// Name: unsigned int __near * TaoCrypt::StdReallocate<unsigned int,class TaoCrypt::AlignedAllocator<unsigned int>>(class TaoCrypt::AlignedAllocator<unsigned int> __near &,unsigned int __near *,unsigned int,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
        void *a,
        CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *p,
        unsigned __int8 *oldSize,
        void *newSize,
        unsigned int newSizea,
        bool preserve)
{
  unsigned int v6; // esi
  unsigned int v7; // edi
  unsigned __int8 *v8; // eax

  v6 = newSizea;
  v7 = (unsigned int)newSize;
  if ( newSize != (void *)newSizea )
  {
    if ( preserve )
    {
      TaoCrypt::AlignedAllocator<unsigned int>::allocate(
        this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&newSize,
        n: newSizea,
        __formal: 0);
      if ( v7 < v6 )
        v6 = v7;
      memcpy(dst: v8, src: oldSize, count: 4 * v6);
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: p, p: oldSize, n: v7);
    }
    else
    {
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: p, p: oldSize, n: (unsigned int)newSize);
      TaoCrypt::AlignedAllocator<unsigned int>::allocate(this: p, n: v6, __formal: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FA10
// Name: public: bool TaoCrypt::Integer::operator!(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall TaoCrypt::Integer::operator!(CInternalFileSystemPassThru<IFileSystem> *this)
{
  return *((_DWORD *)this + 3) != 1 && this->Read == nullptr && TaoCrypt::Integer::WordCount((int *)this) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043FA30
// Name: void TaoCrypt::PositiveSubtract(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TaoCrypt::PositiveSubtract(
        TaoCrypt *this,
        struct TaoCrypt::Integer *a2,
        const struct TaoCrypt::Integer *a3)
{
  int v3; // eax
  unsigned int v4; // edi
  int v5; // eax
  int v6; // ecx
  int v7; // ebx
  int m_stackLevel; // ebp
  CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *v9; // esi
  _DWORD *v10; // ecx
  unsigned int v11; // esi
  int v12; // edx
  unsigned int v13; // edi
  int v14; // eax
  _DWORD *v15; // ecx
  unsigned int v16; // ebx
  unsigned int v17; // ebp
  unsigned int i; // edi
  unsigned int v19; // [esp+10h] [ebp-4h]
  unsigned int v20; // [esp+10h] [ebp-4h]

  v3 = TaoCrypt::Integer::WordCount(this: &a2->m_stackLevel);
  v4 = (v3 & 1) + v3;
  v5 = TaoCrypt::Integer::WordCount(this: &a3->m_stackLevel);
  v6 = v5 & 1;
  v7 = v6 + v5;
  if ( v4 == v6 + v5 )
  {
    m_stackLevel = a3[1].m_stackLevel;
    v9 = (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)a2[1].m_stackLevel;
    if ( TaoCrypt::Compare(a1: v4, a2: m_stackLevel, result: v9) < 0 )
    {
      s_pSub(a1: *((_DWORD *)this + 1), a2: m_stackLevel, a3: v9, a4: v4);
      *((_DWORD *)this + 3) = 1;
    }
    else
    {
      s_pSub(a1: *((_DWORD *)this + 1), a2: v9, a3: m_stackLevel, a4: v4);
      *((_DWORD *)this + 3) = 0;
    }
  }
  else if ( v4 <= v6 + v5 )
  {
    v20 = s_pSub(a1: *((_DWORD *)this + 1), a2: a3[1].m_stackLevel, a3: a2[1].m_stackLevel, a4: v4);
    v14 = 4 * v4;
    v15 = (_DWORD *)(4 * v4 + *((_DWORD *)this + 1));
    v16 = v7 - v4;
    if ( v16 != 0 )
    {
      v17 = 4 * v4 + a3[1].m_stackLevel - (_DWORD)v15;
      for ( i = v16; i != 0; --i )
      {
        *v15 = *(_DWORD *)((char *)v15 + v17);
        ++v15;
      }
    }
    TaoCrypt::Decrement(A: (unsigned int *)(v14 + *((_DWORD *)this + 1)), a2: v16, B: v20);
    *((_DWORD *)this + 3) = 1;
  }
  else
  {
    v19 = s_pSub(a1: *((_DWORD *)this + 1), a2: a2[1].m_stackLevel, a3: a3[1].m_stackLevel, a4: v7);
    v10 = (_DWORD *)(4 * v7 + *((_DWORD *)this + 1));
    v11 = v4 - v7;
    if ( v4 != v7 )
    {
      v12 = 4 * v7 + a2[1].m_stackLevel - (_DWORD)v10;
      v13 = v4 - v7;
      do
      {
        *v10 = *(_DWORD *)((char *)v10 + v12);
        ++v10;
        --v13;
      }
      while ( v13 != 0 );
    }
    TaoCrypt::Decrement(A: (unsigned int *)(4 * v7 + *((_DWORD *)this + 1)), a2: v11, B: v19);
    *((_DWORD *)this + 3) = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FB90
// Name: private: int TaoCrypt::Integer::PositiveCompare(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::Integer::PositiveCompare(
        CInternalFileSystemPassThru<IFileSystem> *this,
        CInternalFileSystemPassThru<IFileSystem> *t)
{
  unsigned int v3; // esi
  unsigned int v4; // eax

  v3 = TaoCrypt::Integer::WordCount((int *)this);
  v4 = TaoCrypt::Integer::WordCount(this: (int *)t);
  if ( v4 == v3 )
    return (CInternalFileSystemPassThru<IFileSystem> *)TaoCrypt::Compare(
                                                         a1: v3,
                                                         a2: (int)t->IFileSystem::IBaseFileSystem::__vftable,
                                                         result: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)this->IFileSystem::IBaseFileSystem::__vftable);
  else
    return (CInternalFileSystemPassThru<IFileSystem> *)(v4 < v3 ? 1 : -1);
}

//------------------------------------------------------------------------------
// Address: 0x0043FBD0
// Name: public: unsigned int TaoCrypt::Integer::BitCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::Integer::BitCount(int *this)
{
  int v2; // esi
  unsigned int v4; // [esp+0h] [ebp-8h]

  v2 = TaoCrypt::Integer::WordCount(this);
  if ( v2 != 0 )
    return 32 * (v2 - 1) + TaoCrypt::BitPrecision(this: *(TaoCrypt **)(*(this + 1) + 4 * v2 - 4), a2: v4);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043FC10
// Name: public: unsigned int TaoCrypt::Integer::ByteCount(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::Integer::ByteCount(int *this)
{
  int v2; // esi
  unsigned int v4; // [esp+0h] [ebp-8h]

  v2 = TaoCrypt::Integer::WordCount(this);
  if ( v2 != 0 )
    return TaoCrypt::BytePrecision(this: *(TaoCrypt **)(*(this + 1) + 4 * v2 - 4), a2: v4) + 4 * v2 - 4;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0043FC40
// Name: public: void TaoCrypt::Integer::Swap(class TaoCrypt::Integer __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Integer::Swap(TaoCrypt::Integer *this, struct TaoCrypt::Integer *a2)
{
  int m_stackLevel; // edx
  int v3; // edx
  int v4; // edx

  m_stackLevel = this->m_stackLevel;
  this->m_stackLevel = a2->m_stackLevel;
  a2->m_stackLevel = m_stackLevel;
  v3 = *((_DWORD *)this + 1);
  *(this + 1) = a2[1];
  a2[1].m_stackLevel = v3;
  v4 = *((_DWORD *)this + 3);
  *(this + 3) = a2[3];
  a2[3].m_stackLevel = v4;
}

//------------------------------------------------------------------------------
// Address: 0x0043FC70
// Name: void TaoCrypt::Divide(unsigned int __near *,unsigned int __near *,unsigned int __near *,unsigned int const __near *,unsigned int,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Divide(
        unsigned int *R,
        unsigned int *Q,
        unsigned int *T,
        unsigned int *shiftBits,
        int a5,
        const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *TB,
        int a7,
        unsigned int NB)
{
  const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v10; // esi
  unsigned int *v11; // edi
  unsigned int v12; // ecx
  unsigned int v13; // edx
  unsigned int *v14; // edi
  unsigned int v15; // eax
  unsigned int *v16; // ecx
  int v17; // edi
  unsigned int v18; // edi
  bool v19; // zf
  unsigned int v20; // edi
  char *v21; // ecx
  unsigned int *v22; // esi
  unsigned int v23; // eax
  unsigned int *v24; // ecx
  unsigned int v25; // eax
  unsigned int v26; // ecx
  const unsigned int *v27; // ecx
  unsigned int v28; // eax
  unsigned int *v29; // ebp
  char v30; // cl
  unsigned int v31; // esi
  int v32; // ebx
  unsigned int v33; // ebp
  unsigned int v34; // eax
  unsigned int v35; // [esp+0h] [ebp-4Ch]
  CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *r; // [esp+10h] [ebp-3Ch]
  unsigned int shiftWords; // [esp+14h] [ebp-38h]
  unsigned int *TP; // [esp+18h] [ebp-34h]
  unsigned int v39; // [esp+1Ch] [ebp-30h]
  int v40; // [esp+20h] [ebp-2Ch]
  unsigned int v41; // [esp+28h] [ebp-24h]
  unsigned int v42; // [esp+30h] [ebp-1Ch]
  unsigned int v43; // [esp+38h] [ebp-14h]
  unsigned int v44; // [esp+3Ch] [ebp-10h] BYREF
  unsigned int A[3]; // [esp+40h] [ebp-Ch] BYREF
  void *shiftBitsa; // [esp+58h] [ebp+Ch]
  const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *TBa; // [esp+60h] [ebp+14h]
  unsigned int *v48; // [esp+64h] [ebp+18h]
  unsigned int NBa; // [esp+68h] [ebp+1Ch]

  v10 = TB;
  r = (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)((char *)&TB->m_Memory.m_pMemory + 2);
  v11 = &shiftBits[(_DWORD)&TB->m_Memory.m_pMemory + 2];
  TP = &shiftBits[(_DWORD)TB + NB + 2];
  v12 = 0;
  v13 = *(_DWORD *)(a7 + 4 * NB - 4) == 0;
  v11[NB - 1] = 0;
  TBa = (const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)v11;
  *v11 = 0;
  shiftWords = v13;
  if ( NB != v13 )
  {
    v14 = &v11[v13];
    do
      *v14++ = *(_DWORD *)(a7 + 4 * v12++);
    while ( v12 < NB - v13 );
    v11 = (unsigned int *)TBa;
  }
  shiftBitsa = (void *)(32 - TaoCrypt::BitPrecision(this: (TaoCrypt *)v11[NB - 1], a2: v35));
  TaoCrypt::ShiftWordsLeftByBits(r: shiftBitsa, ra: v11, n: NB, shiftBits: (unsigned int)shiftBitsa);
  v15 = 0;
  shiftBits[(_DWORD)v10 + 1] = 0;
  shiftBits[(_DWORD)v10] = 0;
  *shiftBits = 0;
  if ( v10 != nullptr )
  {
    v16 = &shiftBits[shiftWords];
    do
      *v16++ = *(_DWORD *)(a5 + 4 * v15++);
    while ( v15 < (unsigned int)v10 );
  }
  TaoCrypt::ShiftWordsLeftByBits(r, ra: shiftBits, n: (unsigned int)r, shiftBits: (unsigned int)shiftBitsa);
  if ( *(_QWORD *)&shiftBits[(_DWORD)v10] > 1u )
  {
    v10 = r;
  }
  else
  {
    v17 = (int)v10 - NB;
    T[v17] = 0;
    T[v17 + 1] = 0;
    while ( shiftBits[(_DWORD)v10] != 0
         || TaoCrypt::Compare(
              a1: NB,
              a2: (int)TBa,
              result: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&shiftBits[v17]) >= 0 )
    {
      shiftBits[(_DWORD)v10] -= s_pSub(a1: &shiftBits[v17], a2: &shiftBits[v17], a3: TBa, a4: NB);
      ++T[v17];
    }
    v11 = (unsigned int *)TBa;
  }
  v18 = v11[NB - 2];
  v19 = v18 == -1;
  v20 = v18 + 1;
  v39 = v20;
  v21 = (char *)&v10[-1].m_pElements + 2;
  v40 = *((_DWORD *)TBa + NB - 1) + v19;
  if ( (unsigned int)&v10[-1].m_pElements + 2 >= NB )
  {
    v22 = &T[(_DWORD)&v21[-NB]];
    v23 = (unsigned int)&v21[-NB] >> 1;
    v24 = &shiftBits[(_DWORD)v21 + 1];
    v48 = v24;
    NBa = v23 + 1;
    while ( 1 )
    {
      v25 = *(v24 - 1);
      v42 = *v24;
      v41 = *(v24 - 2);
      if ( (v40 | v20) != 0 )
      {
        v44 = *(v24 - 3);
        A[1] = v25;
        A[0] = v41;
        A[2] = v42;
        v43 = TaoCrypt::DivideThreeWordsByTwo<unsigned int,TaoCrypt::DWord>(A, Aa: A, B0: __PAIR64__(v40, v20));
        v25 = TaoCrypt::DivideThreeWordsByTwo<unsigned int,TaoCrypt::DWord>(A: v27, Aa: &v44, B0: __PAIR64__(v40, v20));
        v26 = v43;
      }
      else
      {
        v26 = *v24;
      }
      v22[1] = v26;
      *v22 = v25;
      TaoCrypt::CorrectQuotientEstimate(
        R: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)((char *)v22 + (char *)shiftBits - (char *)T),
        a2: v22,
        T: TP,
        a4: (int)TBa,
        N: NB);
      v48 -= 2;
      v22 -= 2;
      if ( --NBa == 0 )
        break;
      v20 = v39;
      v24 = v48;
    }
  }
  v28 = 0;
  if ( NB != 0 )
  {
    v29 = &shiftBits[shiftWords];
    do
      Q[v28++] = *v29++;
    while ( v28 < NB );
  }
  v30 = (char)shiftBitsa;
  v31 = 0;
  if ( shiftBitsa != nullptr )
  {
    v32 = NB - 1;
    if ( v32 >= 0 )
    {
      while ( 1 )
      {
        v33 = Q[v32] >> v30;
        v34 = Q[v32--] << (32 - (_BYTE)shiftBitsa);
        Q[v32 + 1] = v31 | v33;
        v31 = v34;
        if ( v32 < 0 )
          break;
        v30 = (char)shiftBitsa;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FF10
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::Inverse(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ModularArithmetic::Inverse(IFileSystem *this, CInternalFileSystemPassThru<IFileSystem> *a)
{
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // ecx

  if ( !TaoCrypt::Integer::operator!(this: a) )
  {
    v3 = *((_DWORD *)this + 3);
    v4 = *((_DWORD **)this + 8);
    if ( v3 != 0 )
    {
      v5 = *((_DWORD *)this + 4) - (_DWORD)v4;
      do
      {
        *v4 = *(_DWORD *)((char *)v4 + v5);
        ++v4;
        --v3;
      }
      while ( v3 != 0 );
    }
    if ( s_pSub(
           a1: *((_DWORD *)this + 8),
           a2: *((_DWORD *)this + 8),
           a3: a->IFileSystem::IBaseFileSystem::__vftable,
           a4: a->IFileSystem::IAppSystem::__vftable) != 0 )
      TaoCrypt::Decrement(
        A: (unsigned int *)(*((_DWORD *)this + 8) + 4 * (int)a->IFileSystem::IAppSystem::__vftable),
        a2: 1u,
        B: *((_DWORD *)this + 3) - (unsigned int)a->IFileSystem::IAppSystem::__vftable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x0043FF90
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::AbstractRing::MultiplicativeGroupT::ScalarMultiply(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
const int *__thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::ScalarMultiply(
        const int *this,
        const int *a,
        int a3,
        int a4)
{
  (*(void (__thiscall **)(_DWORD, const int *, int, int))(**((_DWORD **)this + 1) + 76))(a1: *(this + 1), a2: a, a3, a4);
  return a;
}

//------------------------------------------------------------------------------
// Address: 0x0043FFB0
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::AbstractRing::MultiplicativeGroupT::CascadeScalarMultiply(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
const struct TaoCrypt::Integer *__thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::CascadeScalarMultiply(
        TaoCrypt::AbstractRing::MultiplicativeGroupT *this,
        const struct TaoCrypt::Integer *a2,
        const struct TaoCrypt::Integer *a3,
        const struct TaoCrypt::Integer *a4,
        const struct TaoCrypt::Integer *a5,
        int a6)
{
  (*(void (__thiscall **)(_DWORD, const struct TaoCrypt::Integer *, const struct TaoCrypt::Integer *, const struct TaoCrypt::Integer *, const struct TaoCrypt::Integer *, int))(**((_DWORD **)this + 1) + 80))(
    a1: *((_DWORD *)this + 1),
    a2,
    a3,
    a4,
    a5,
    a6);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x0043FFE0
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::MontgomeryRepresentation::CascadeExponentiate(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
FSAsyncControl_t__ *__thiscall TaoCrypt::MontgomeryRepresentation::CascadeExponentiate(
        IFileSystem *this,
        FSAsyncControl_t__ *x,
        bool e1,
        int a4,
        int a5,
        int a6)
{
  TaoCrypt::AbstractRing::CascadeExponentiate((CUtlVector<int,CUtlMemory<int,int> > *)this, (int)x);
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x00440010
// Name: public: void TaoCrypt::Integer::Negate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Integer::Negate(TaoCrypt::Integer *this)
{
  if ( !TaoCrypt::Integer::operator!((CInternalFileSystemPassThru<IFileSystem> *)this) )
    *((_DWORD *)this + 3) = 1 - *((_DWORD *)this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x00440030
// Name: public: int TaoCrypt::Integer::Compare(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::Integer::Compare(
        CInternalFileSystemPassThru<IFileSystem> *this,
        CInternalFileSystemPassThru<IFileSystem> *t)
{
  int result; // eax

  result = 1;
  if ( *((_DWORD *)this + 3) == 1 )
  {
    if ( t[1].IFileSystem::IAppSystem::__vftable == (CInternalFileSystemPassThru<IFileSystem>_vtbl *)1 )
      return -(int)TaoCrypt::Integer::PositiveCompare(this, t);
    else
      return -1;
  }
  else if ( t[1].IFileSystem::IAppSystem::__vftable != (CInternalFileSystemPassThru<IFileSystem>_vtbl *)1 )
  {
    return (int)TaoCrypt::Integer::PositiveCompare(this, t);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00440070
// Name: public: virtual TaoCrypt::MontgomeryRepresentation::~MontgomeryRepresentation(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::MontgomeryRepresentation::~MontgomeryRepresentation(IFileSystem *this)
{
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)this + 7,
    p: *((unsigned __int8 **)this + 20),
    n: *((_DWORD *)this + 19));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 68),
    p: *((unsigned __int8 **)this + 16),
    n: *((_DWORD *)this + 15));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 52),
    p: *((unsigned __int8 **)this + 12),
    n: *((_DWORD *)this + 11));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)this + 3,
    p: *((unsigned __int8 **)this + 8),
    n: *((_DWORD *)this + 7));
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 20),
    p: *((unsigned __int8 **)this + 4),
    n: *((_DWORD *)this + 3));
}

//------------------------------------------------------------------------------
// Address: 0x004400D0
// Name: public: void TaoCrypt::Block<unsigned int,class TaoCrypt::AlignedAllocator<unsigned int>>::CleanGrow(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Block<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>::CleanGrow(
        char *this,
        unsigned int newSize)
{
  unsigned __int8 *v3; // ecx
  unsigned __int8 *v4; // ecx
  int v5; // eax
  unsigned int v6; // [esp-18h] [ebp-20h]

  v3 = *(unsigned __int8 **)this;
  if ( newSize > (unsigned int)v3 )
  {
    TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      a: v3,
      p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 8),
      oldSize: *((unsigned __int8 **)this + 1),
      newSize: v3,
      newSizea: newSize,
      preserve: true);
    v4 = *(unsigned __int8 **)this;
    v6 = 4 * (newSize - *(_DWORD *)this);
    *((_DWORD *)this + 1) = v5;
    memset(dst: (unsigned __int8 *)(v5 + 4 * (_DWORD)v4), value: 0, count: v6);
    *(_DWORD *)this = newSize;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00440120
// Name: public: void TaoCrypt::Integer::SetBit(unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall TaoCrypt::Integer::SetBit(TaoCrypt::Integer *this, unsigned int n, bool value)
{
  unsigned int v4; // edi
  int m_stackLevel; // ecx
  int v6; // eax
  unsigned int result; // eax
  unsigned int v8; // [esp-20h] [ebp-24h]

  if ( value )
  {
    v4 = TaoCrypt::RoundupSize();
    if ( v4 > this->m_stackLevel )
    {
      TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
        a: *((void **)this + 1),
        p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2),
        oldSize: *((unsigned __int8 **)this + 1),
        newSize: (void *)this->m_stackLevel,
        newSizea: v4,
        preserve: true);
      m_stackLevel = this->m_stackLevel;
      v8 = 4 * (v4 - this->m_stackLevel);
      *((_DWORD *)this + 1) = v6;
      memset(dst: (unsigned __int8 *)(v6 + 4 * m_stackLevel), value: 0, count: v8);
      this->m_stackLevel = v4;
    }
    result = *((_DWORD *)this + 1) + 4 * (n >> 5);
    *(_DWORD *)result |= 1 << (n & 0x1F);
  }
  else
  {
    result = n >> 5;
    if ( n >> 5 < this->m_stackLevel )
    {
      result = *((_DWORD *)this + 1) + 4 * result;
      *(_DWORD *)result &= ~(1 << (n & 0x1F));
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004401C0
// Name: public: class TaoCrypt::Integer __near & TaoCrypt::Integer::operator=(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__userpurge TaoCrypt::Integer::operator=@<eax>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        char *t,
        const char *a3)
{
  CInternalFileSystemPassThru<IFileSystem>_vtbl *v4; // edi
  IBaseFileSystem_vtbl *v5; // eax
  int v6; // ecx

  if ( this != (CInternalFileSystemPassThru<IFileSystem> *)t )
  {
    TaoCrypt::Integer::WordCount(this: (int *)t);
    v4 = (CInternalFileSystemPassThru<IFileSystem>_vtbl *)TaoCrypt::RoundupSize();
    TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      a: this->IFileSystem::IBaseFileSystem::__vftable,
      p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&this->m_pBaseFileSystemPassThru,
      oldSize: (unsigned __int8 *)this->IFileSystem::IBaseFileSystem::__vftable,
      newSize: this->IFileSystem::IAppSystem::__vftable,
      newSizea: (unsigned int)v4,
      preserve: false);
    this->IFileSystem::IBaseFileSystem::__vftable = v5;
    this->IFileSystem::IAppSystem::__vftable = v4;
    if ( v4 != nullptr )
    {
      v6 = *((_DWORD *)t + 1) - (_DWORD)v5;
      do
      {
        v5->Read = *(int (__thiscall **)(IBaseFileSystem *, void *, int, void *))((char *)&v5->Read + v6);
        v5 = (IBaseFileSystem_vtbl *)((char *)v5 + 4);
        v4 = (CInternalFileSystemPassThru<IFileSystem>_vtbl *)((char *)v4 - 1);
      }
      while ( v4 != nullptr );
    }
    *((_DWORD *)this + 3) = *((_DWORD *)t + 3);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440220
// Name: public: class TaoCrypt::Integer __near & TaoCrypt::Integer::operator<<=(unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TaoCrypt::Integer::operator<<=(int this, unsigned int a2)
{
  int v3; // ecx
  unsigned int v4; // ebp
  unsigned int v5; // eax
  unsigned int v6; // ebx
  unsigned int v7; // edi
  int v8; // ecx
  int v9; // eax
  _DWORD *v10; // edi
  unsigned int v11; // ecx
  unsigned int v12; // eax
  _DWORD *v13; // edx
  unsigned int v15; // [esp-18h] [ebp-2Ch]
  unsigned int v16; // [esp+0h] [ebp-14h]
  int v17; // [esp+10h] [ebp-4h]

  v3 = TaoCrypt::Integer::WordCount((int *)this);
  v4 = a2 & 0x1F;
  v5 = v3 + ((a2 + 31) >> 5);
  v6 = a2 >> 5;
  v17 = v3;
  if ( v5 > 8 )
  {
    if ( v5 > 0x10 )
    {
      if ( v5 > 0x20 )
      {
        if ( v5 > 0x40 )
          v7 = 1 << TaoCrypt::BitPrecision(this: (TaoCrypt *)(v5 - 1), a2: v16);
        else
          v7 = 64;
      }
      else
      {
        v7 = 32;
      }
    }
    else
    {
      v7 = 16;
    }
  }
  else
  {
    v7 = *((_DWORD *)RoundupSizeTable + v5);
  }
  if ( v7 > *(_DWORD *)this )
  {
    TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      a: *(void **)this,
      p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 8),
      oldSize: *(unsigned __int8 **)(this + 4),
      newSize: *(void **)this,
      newSizea: v7,
      preserve: true);
    v8 = *(_DWORD *)this;
    v15 = 4 * (v7 - *(_DWORD *)this);
    *(_DWORD *)(this + 4) = v9;
    memset(dst: (unsigned __int8 *)(v9 + 4 * v8), value: 0, count: v15);
    *(_DWORD *)this = v7;
  }
  v10 = *(_DWORD **)(this + 4);
  v11 = a2 >> 5;
  if ( v6 >= v6 + v17 )
    v11 = v6 + v17;
  if ( v11 != 0 )
  {
    v12 = v6 + v17 - 1;
    if ( v12 >= v11 )
    {
      v13 = &v10[v12 - v11];
      do
        v10[v12--] = *v13--;
      while ( v12 >= v11 );
    }
    memset(v10, 0, 4 * v11);
  }
  TaoCrypt::ShiftWordsLeftByBits(
    r: (void *)(*(_DWORD *)(this + 4) + 4 * v6),
    ra: (unsigned int *)(*(_DWORD *)(this + 4) + 4 * v6),
    n: v17 + ((v4 + 31) >> 5),
    shiftBits: v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440330
// Name: void TaoCrypt::PositiveAdd(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00440470
// Name: public: virtual class TaoCrypt::Integer __near & TaoCrypt::AbstractRing::MultiplicativeGroupT::Accumulate(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::Accumulate(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        CInternalFileSystemPassThru<IFileSystem> *a,
        int b)
{
  char *v3; // eax
  const char *v4; // [esp+0h] [ebp-4h]

  v3 = (char *)(*(int (__thiscall **)(int, CInternalFileSystemPassThru<IFileSystem> *, int))(*(_DWORD *)this->m_Memory.m_nAllocationCount
                                                                                           + 60))(
                 a1: this->m_Memory.m_nAllocationCount,
                 a2: a,
                 a3: b);
  TaoCrypt::Integer::operator=(this: a, t: v3, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004404A0
// Name: public: virtual class TaoCrypt::Integer __near & TaoCrypt::AbstractRing::MultiplicativeGroupT::Reduce(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::AbstractRing::MultiplicativeGroupT::Reduce(
        CUtlVector<int,CUtlMemory<int,int> > *this,
        CInternalFileSystemPassThru<IFileSystem> *a,
        int b)
{
  char *v3; // eax
  const char *v4; // [esp+0h] [ebp-4h]

  v3 = (char *)(*(int (__thiscall **)(int, CInternalFileSystemPassThru<IFileSystem> *, int))(*(_DWORD *)this->m_Memory.m_nAllocationCount
                                                                                           + 72))(
                 a1: this->m_Memory.m_nAllocationCount,
                 a2: a,
                 a3: b);
  TaoCrypt::Integer::operator=(this: a, t: v3, a3: v4);
}

//------------------------------------------------------------------------------
// Address: 0x004404D0
// Name: public: void TaoCrypt::Integer::Decode(class TaoCrypt::Source __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::Integer::Decode(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        struct TaoCrypt::Source *a2@<ebp>,
        TaoCrypt *source,
        int a4,
        void *a5)
{
  int v5; // eax
  int v6; // edx
  unsigned int Length; // eax
  int v9; // edx
  int v10; // ebp
  int v11; // eax
  unsigned int v12; // ebx
  IBaseFileSystem_vtbl *v13; // eax
  unsigned int v14; // eax
  int i; // ebx
  int v16; // ecx
  _DWORD *v17; // edx
  int v18; // ebp

  v5 = *((_DWORD *)source + 3);
  v6 = *((_DWORD *)source + 1);
  *((_DWORD *)source + 3) = v5 + 1;
  if ( *(_BYTE *)(v5 + v6) == 2 )
  {
    Length = TaoCrypt::GetLength(this: source, a2);
    v9 = *((_DWORD *)source + 1);
    v10 = Length;
    v11 = *((_DWORD *)source + 3);
    *((_DWORD *)source + 3) = v11 + 1;
    if ( *(_BYTE *)(v11 + v9) != 0 )
      *((_DWORD *)source + 3) = v11;
    else
      --v10;
    v12 = TaoCrypt::RoundupSize();
    if ( (CInternalFileSystemPassThru<IFileSystem>_vtbl *)v12 > this->IFileSystem::IAppSystem::__vftable )
    {
      TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
        a: this->IFileSystem::IBaseFileSystem::__vftable,
        p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&this->m_pBaseFileSystemPassThru,
        oldSize: (unsigned __int8 *)this->IFileSystem::IBaseFileSystem::__vftable,
        newSize: this->IFileSystem::IAppSystem::__vftable,
        newSizea: v12,
        preserve: false);
      this->IFileSystem::IBaseFileSystem::__vftable = v13;
      this->IFileSystem::IAppSystem::__vftable = (CInternalFileSystemPassThru<IFileSystem>_vtbl *)v12;
      memset(dst: (unsigned __int8 *)v13, value: 0, count: 4 * v12);
    }
    if ( v10 > 0 )
    {
      v14 = v10 - 1;
      for ( i = v10; i != 0; --i )
      {
        v16 = *((_DWORD *)source + 3);
        *((_DWORD *)source + 3) = v16 + 1;
        v17 = &this->Read + (v14 >> 2);
        v18 = *(unsigned __int8 *)(v16 + *((_DWORD *)source + 1)) << (8 * (v14-- & 3));
        *v17 |= v18;
      }
    }
  }
  else
  {
    *((_DWORD *)source + 4) = 1010;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004405A0
// Name: public: void TaoCrypt::Integer::Decode(unsigned char const __near *,unsigned int,enum TaoCrypt::Integer::Signedness)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Integer::Decode(int this, char *a2, unsigned int a3, int a4)
{
  int v5; // ecx
  char v6; // al
  int v7; // ebp
  unsigned int v8; // ebx
  int v9; // edx
  bool v10; // zf
  unsigned int v11; // eax
  unsigned int v12; // edi
  unsigned __int8 *v13; // eax
  int v14; // ebp
  unsigned int v15; // eax
  char *v16; // ebp
  _DWORD *v17; // edi
  int v18; // edx
  unsigned int j; // eax
  _DWORD *v20; // edx
  int v21; // edi
  unsigned int v22; // [esp+0h] [ebp-10h]
  unsigned int i; // [esp+14h] [ebp+4h]

  v5 = 1;
  v6 = *a2;
  v7 = 1;
  if ( a4 != 1 || v6 >= 0 )
    v5 = 0;
  v8 = a3;
  for ( *(_DWORD *)(this + 12) = v5; v8 != 0; ++v7 )
  {
    v9 = 0;
    if ( v5 != 0 )
      v10 = v6 == -1;
    else
      v10 = v6 == 0;
    LOBYTE(v9) = v10;
    if ( v9 == 0 )
      break;
    v6 = a2[v7];
    --v8;
  }
  v11 = (v8 + 3) >> 2;
  if ( v11 > 8 )
  {
    if ( v11 > 0x10 )
    {
      if ( v11 > 0x20 )
      {
        if ( v11 > 0x40 )
          v12 = 1 << TaoCrypt::BitPrecision(this: (TaoCrypt *)(v11 - 1), a2: v22);
        else
          v12 = 64;
      }
      else
      {
        v12 = 32;
      }
    }
    else
    {
      v12 = 16;
    }
  }
  else
  {
    v12 = *((_DWORD *)RoundupSizeTable + v11);
  }
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: *(void **)(this + 4),
    p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 8),
    oldSize: *(unsigned __int8 **)(this + 4),
    newSize: *(void **)this,
    newSizea: v12,
    preserve: false);
  *(_DWORD *)(this + 4) = v13;
  *(_DWORD *)this = v12;
  memset(dst: v13, value: 0, count: 4 * v12);
  v14 = v7 - 1;
  if ( v8 != 0 )
  {
    v15 = v8 - 1;
    v16 = &a2[v14];
    for ( i = v8; i != 0; --i )
    {
      v17 = (_DWORD *)(*(_DWORD *)(this + 4) + 4 * (v15 >> 2));
      v18 = (unsigned __int8)*v16++ << (8 * (v15-- & 3));
      *v17 |= v18;
    }
  }
  if ( *(_DWORD *)(this + 12) == 1 )
  {
    for ( j = v8; j < 4 * *(_DWORD *)this; *v20 |= v21 )
    {
      v20 = (_DWORD *)(*(_DWORD *)(this + 4) + 4 * (j >> 2));
      v21 = 255 << (8 * (j++ & 3));
    }
    TaoCrypt::TwosComplement(a1: *(_DWORD *)this, a2: *(unsigned int **)(this + 4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x004406F0
// Name: public: void TaoCrypt::Integer::Randomize(class TaoCrypt::RandomNumberGenerator __near &,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Integer::Randomize(
        CInternalFileSystemPassThru<IFileSystem> *this,
        TaoCrypt::RandomNumberGenerator *rng,
        const char *nbits)
{
  unsigned int v3; // esi
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // edi
  const IVirtualMemorySection *v7; // ecx
  int v8; // [esp+18h] [ebp-4h] BYREF

  v3 = ((unsigned int)nbits >> 3) + 1;
  if ( (unsigned int)nbits >> 3 == -1 )
    v5 = nullptr;
  else
    v5 = (unsigned __int8 *)operator new[](sz: (const CSplitScreenAddedConVar *)this);
  v6 = (unsigned __int8 *)TaoCrypt::StdReallocate<unsigned char,TaoCrypt::AllocatorWithCleanup<unsigned char>>(
                            a1: (int)&v8,
                            src: v5,
                            a3: v3,
                            count: v3,
                            a5: 0);
  memset(dst: v6, value: 0, count: v3);
  TaoCrypt::RandomNumberGenerator::GenerateBlock(this: rng, output: v6, a3: v3);
  if ( (unsigned int)nbits >> 3 != -1 )
    *v6 = (unsigned __int8)TaoCrypt::Crop(value: v7);
  TaoCrypt::Integer::Decode((int)this, a2: (char *)v6, a3: v3, a4: 0);
  memset(dst: v6, value: 0, count: v3);
  TaoCrypt::tcArrayDelete<unsigned char>(ptr: v6);
}

//------------------------------------------------------------------------------
// Address: 0x00440790
// Name: public: class TaoCrypt::Integer __near & TaoCrypt::Integer::operator+=(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__userpurge TaoCrypt::Integer::operator+=@<eax>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        const struct TaoCrypt::Integer *t,
        const char *a3)
{
  CInternalFileSystemPassThru<IFileSystem>_vtbl *m_stackLevel; // edi
  CInternalFileSystemPassThru<IFileSystem>_vtbl *v5; // ecx
  IBaseFileSystem_vtbl *v6; // eax
  unsigned int v8; // [esp-18h] [ebp-28h]
  CInternalFileSystemPassThru<IFileSystem> *v9; // [esp-Ch] [ebp-1Ch]
  CInternalFileSystemPassThru<IFileSystem> *v10; // [esp-8h] [ebp-18h]
  CInternalFileSystemPassThru<IFileSystem> *v11; // [esp-4h] [ebp-14h]
  const struct TaoCrypt::Integer *v12; // [esp+0h] [ebp-10h]

  m_stackLevel = (CInternalFileSystemPassThru<IFileSystem>_vtbl *)t->m_stackLevel;
  if ( (CInternalFileSystemPassThru<IFileSystem>_vtbl *)t->m_stackLevel > this->IFileSystem::IAppSystem::__vftable )
  {
    TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      a: this->IFileSystem::IBaseFileSystem::__vftable,
      p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&this->m_pBaseFileSystemPassThru,
      oldSize: (unsigned __int8 *)this->IFileSystem::IBaseFileSystem::__vftable,
      newSize: this->IFileSystem::IAppSystem::__vftable,
      newSizea: (unsigned int)m_stackLevel,
      preserve: true);
    v5 = this->IFileSystem::IAppSystem::__vftable;
    v8 = 4 * ((char *)m_stackLevel - (char *)this->IFileSystem::IAppSystem::__vftable);
    this->IFileSystem::IBaseFileSystem::__vftable = v6;
    memset(dst: (unsigned __int8 *)&v6->Read + 4 * (_DWORD)v5, value: 0, count: v8);
    this->IFileSystem::IAppSystem::__vftable = m_stackLevel;
  }
  if ( *((_DWORD *)this + 3) != 1 )
  {
    v11 = (CInternalFileSystemPassThru<IFileSystem> *)t;
    v10 = this;
    v9 = this;
    if ( t[3].m_stackLevel != 1 )
    {
      TaoCrypt::PositiveAdd((TaoCrypt *)this, a2: (struct TaoCrypt::Integer *)this, a3: t, a4: v12);
      return this;
    }
    goto LABEL_8;
  }
  if ( t[3].m_stackLevel != 1 )
  {
    v11 = this;
    v10 = (CInternalFileSystemPassThru<IFileSystem> *)t;
    v9 = this;
LABEL_8:
    TaoCrypt::PositiveSubtract(
      this: (TaoCrypt *)v9,
      a2: (struct TaoCrypt::Integer *)v10,
      a3: (const struct TaoCrypt::Integer *)v11);
    return this;
  }
  TaoCrypt::PositiveAdd((TaoCrypt *)this, a2: (struct TaoCrypt::Integer *)this, a3: t, a4: v12);
  *((_DWORD *)this + 3) = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440830
// Name: public: class TaoCrypt::Integer __near & TaoCrypt::Integer::operator-=(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__userpurge TaoCrypt::Integer::operator-=@<eax>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        const struct TaoCrypt::Integer *t,
        const char *a3)
{
  CInternalFileSystemPassThru<IFileSystem>_vtbl *m_stackLevel; // edi
  CInternalFileSystemPassThru<IFileSystem>_vtbl *v5; // ecx
  IBaseFileSystem_vtbl *v6; // eax
  unsigned int v8; // [esp-18h] [ebp-28h]
  CInternalFileSystemPassThru<IFileSystem> *v9; // [esp-Ch] [ebp-1Ch]
  CInternalFileSystemPassThru<IFileSystem> *v10; // [esp-8h] [ebp-18h]
  CInternalFileSystemPassThru<IFileSystem> *v11; // [esp-4h] [ebp-14h]
  const struct TaoCrypt::Integer *v12; // [esp+0h] [ebp-10h]

  m_stackLevel = (CInternalFileSystemPassThru<IFileSystem>_vtbl *)t->m_stackLevel;
  if ( (CInternalFileSystemPassThru<IFileSystem>_vtbl *)t->m_stackLevel > this->IFileSystem::IAppSystem::__vftable )
  {
    TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      a: this->IFileSystem::IBaseFileSystem::__vftable,
      p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&this->m_pBaseFileSystemPassThru,
      oldSize: (unsigned __int8 *)this->IFileSystem::IBaseFileSystem::__vftable,
      newSize: this->IFileSystem::IAppSystem::__vftable,
      newSizea: (unsigned int)m_stackLevel,
      preserve: true);
    v5 = this->IFileSystem::IAppSystem::__vftable;
    v8 = 4 * ((char *)m_stackLevel - (char *)this->IFileSystem::IAppSystem::__vftable);
    this->IFileSystem::IBaseFileSystem::__vftable = v6;
    memset(dst: (unsigned __int8 *)&v6->Read + 4 * (_DWORD)v5, value: 0, count: v8);
    this->IFileSystem::IAppSystem::__vftable = m_stackLevel;
  }
  if ( *((_DWORD *)this + 3) == 1 )
  {
    if ( t[3].m_stackLevel != 1 )
    {
      TaoCrypt::PositiveAdd((TaoCrypt *)this, a2: (struct TaoCrypt::Integer *)this, a3: t, a4: v12);
      *((_DWORD *)this + 3) = 1;
      return this;
    }
    v11 = this;
    v10 = (CInternalFileSystemPassThru<IFileSystem> *)t;
    v9 = this;
  }
  else
  {
    v11 = (CInternalFileSystemPassThru<IFileSystem> *)t;
    v10 = this;
    v9 = this;
    if ( t[3].m_stackLevel == 1 )
    {
      TaoCrypt::PositiveAdd((TaoCrypt *)this, a2: (struct TaoCrypt::Integer *)this, a3: t, a4: v12);
      return this;
    }
  }
  TaoCrypt::PositiveSubtract(
    this: (TaoCrypt *)v9,
    a2: (struct TaoCrypt::Integer *)v10,
    a3: (const struct TaoCrypt::Integer *)v11);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004408D0
// Name: public: virtual class TaoCrypt::Integer __near & TaoCrypt::ModularArithmetic::Accumulate(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00440960
// Name: public: virtual class TaoCrypt::Integer __near & TaoCrypt::ModularArithmetic::Reduce(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004409D0
// Name: public: TaoCrypt::Block<unsigned int,class TaoCrypt::AlignedAllocator<unsigned int>>::Block<unsigned int,class TaoCrypt::AlignedAllocator<unsigned int>>(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CRefCountServiceBase<1,CRefMT> *__thiscall TaoCrypt::Block<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>::Block<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
        CRefCountServiceBase<1,CRefMT> *this,
        CRefCountServiceBase<1,CRefMT>_vtbl *s)
{
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *v3; // ebx
  CRefCountServiceBase<1,CRefMT>_vtbl *v4; // edi
  CRefCountServiceBase<1,CRefMT>_vtbl *v5; // ecx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // eax
  CRefCountServiceBase<1,CRefMT>_vtbl *v9; // [esp-Ch] [ebp-18h]

  v3 = (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 1);
  this->__vftable = s;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 1),
    n: (unsigned int)s,
    __formal: 0);
  v4 = this->__vftable;
  v5 = this->__vftable;
  v9 = this->__vftable;
  this->m_iRefs = (int)v6;
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: v5,
    p: v3,
    oldSize: v6,
    newSize: v9,
    newSizea: (unsigned int)v4,
    preserve: false);
  this->m_iRefs = (int)v7;
  this->__vftable = v4;
  memset(dst: v7, value: 0, count: 4 * (_DWORD)v4);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440A20
// Name: void TaoCrypt::PositiveMultiply(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TaoCrypt::PositiveMultiply(
        TaoCrypt *this,
        struct TaoCrypt::Integer *a2,
        const struct TaoCrypt::Integer *a3)
{
  unsigned int v3; // eax
  unsigned int v4; // ebx
  unsigned int v5; // eax
  int v6; // ebp
  unsigned int v7; // edi
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  void *v10; // ecx
  unsigned __int8 *v11; // eax
  unsigned int *v12; // ebx
  unsigned int v13; // [esp-20h] [ebp-40h]
  unsigned int v14; // [esp+0h] [ebp-20h]
  int v15; // [esp+10h] [ebp-10h]
  int p; // [esp+1Ch] [ebp-4h] BYREF

  v3 = TaoCrypt::Integer::WordCount(this: &a2->m_stackLevel);
  v4 = 16;
  if ( v3 > 8 )
  {
    if ( v3 > 0x10 )
    {
      if ( v3 > 0x20 )
      {
        if ( v3 > 0x40 )
          v15 = 1 << TaoCrypt::BitPrecision(this: (TaoCrypt *)(v3 - 1), a2: v14);
        else
          v15 = 64;
      }
      else
      {
        v15 = 32;
      }
    }
    else
    {
      v15 = 16;
    }
  }
  else
  {
    v15 = *((_DWORD *)RoundupSizeTable + v3);
  }
  v5 = TaoCrypt::Integer::WordCount(this: &a3->m_stackLevel);
  if ( v5 > 8 )
  {
    if ( v5 > 0x10 )
    {
      if ( v5 > 0x20 )
      {
        if ( v5 > 0x40 )
          v6 = 1 << TaoCrypt::BitPrecision(this: (TaoCrypt *)(v5 - 1), a2: v14);
        else
          v6 = 64;
      }
      else
      {
        v6 = 32;
      }
    }
    else
    {
      v6 = 16;
    }
  }
  else
  {
    v6 = *((_DWORD *)RoundupSizeTable + v5);
  }
  v7 = v15 + v6;
  if ( (unsigned int)(v15 + v6) > 8 )
  {
    if ( v7 > 0x10 )
    {
      if ( v7 > 0x20 )
      {
        if ( v7 > 0x40 )
          v4 = 1 << TaoCrypt::BitPrecision(this: (TaoCrypt *)(v7 - 1), a2: v14);
        else
          v4 = 64;
      }
      else
      {
        v4 = 32;
      }
    }
  }
  else
  {
    v4 = *((_DWORD *)RoundupSizeTable + v7);
  }
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: *((void **)this + 1),
    p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)((char *)this + 8),
    oldSize: *((unsigned __int8 **)this + 1),
    newSize: *(void **)this,
    newSizea: v4,
    preserve: false);
  *((_DWORD *)this + 1) = v8;
  *(_DWORD *)this = v4;
  memset(dst: v8, value: 0, count: 4 * v4);
  *((_DWORD *)this + 3) = 0;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&p,
    n: v7,
    __formal: 0);
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: v10,
    (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&p,
    oldSize: v9,
    newSize: (void *)v7,
    newSizea: v7,
    preserve: false);
  v12 = (unsigned int *)v11;
  memset(dst: v11, value: 0, count: 4 * v7);
  TaoCrypt::AsymmetricMultiply(
    this: *((TaoCrypt **)this + 1),
    a2: v12,
    a3: (unsigned int *)a2[1].m_stackLevel,
    a4: (const unsigned int *)v15,
    a5: a3[1].m_stackLevel,
    a6: (const unsigned int *)v6,
    a7: v13);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&p,
    p: (unsigned __int8 *)v12,
    n: v7);
}

//------------------------------------------------------------------------------
// Address: 0x00440BB0
// Name: void TaoCrypt::Multiply(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TaoCrypt::Multiply(
        TaoCrypt::Integer *this,
        struct TaoCrypt::Integer *a2,
        const struct TaoCrypt::Integer *a3)
{
  TaoCrypt::PositiveMultiply((TaoCrypt *)this, a2, a3);
  if ( (a2[3].m_stackLevel != 1) != (a3[3].m_stackLevel != 1) )
    TaoCrypt::Integer::Negate(this);
}

//------------------------------------------------------------------------------
// Address: 0x00440BF0
// Name: public: TaoCrypt::Integer::Integer(void)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::Integer::Integer(TaoCrypt::Integer *this)
{
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *v2; // ebx
  int m_stackLevel; // edi
  void *v4; // ecx
  unsigned __int8 *v5; // eax
  unsigned __int8 *v6; // eax
  int v7; // edx
  void *v9; // [esp-Ch] [ebp-18h]

  v2 = (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2);
  this->m_stackLevel = 2;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2),
    n: 2u,
    __formal: 0);
  m_stackLevel = this->m_stackLevel;
  v4 = (void *)this->m_stackLevel;
  v9 = (void *)this->m_stackLevel;
  *((_DWORD *)this + 1) = v5;
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: v4,
    p: v2,
    oldSize: v5,
    newSize: v9,
    newSizea: m_stackLevel,
    preserve: false);
  *((_DWORD *)this + 1) = v6;
  this->m_stackLevel = m_stackLevel;
  memset(dst: v6, value: 0, count: 4 * m_stackLevel);
  v7 = *((_DWORD *)this + 1);
  *((_DWORD *)this + 3) = 0;
  *(_DWORD *)(v7 + 4) = 0;
  **((_DWORD **)this + 1) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440C60
// Name: public: TaoCrypt::Integer::Integer(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::Integer::Integer(TaoCrypt::Integer *this, const struct TaoCrypt::Integer *a2)
{
  unsigned int v3; // eax
  int v4; // edx
  int m_stackLevel; // edi
  void *v6; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  int v9; // ecx
  _DWORD *v10; // eax
  int v11; // edx
  void *v13; // [esp-10h] [ebp-1Ch]
  unsigned int v14; // [esp+0h] [ebp-Ch]

  v3 = TaoCrypt::Integer::WordCount(this: &a2->m_stackLevel);
  if ( v3 > 8 )
  {
    if ( v3 > 0x10 )
    {
      if ( v3 > 0x20 )
      {
        if ( v3 > 0x40 )
          v4 = 1 << TaoCrypt::BitPrecision(this: (TaoCrypt *)(v3 - 1), a2: v14);
        else
          v4 = 64;
      }
      else
      {
        v4 = 32;
      }
    }
    else
    {
      v4 = 16;
    }
  }
  else
  {
    v4 = *((_DWORD *)RoundupSizeTable + v3);
  }
  this->m_stackLevel = v4;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2),
    n: v4,
    __formal: 0);
  m_stackLevel = this->m_stackLevel;
  v6 = (void *)this->m_stackLevel;
  v13 = (void *)this->m_stackLevel;
  *((_DWORD *)this + 1) = v7;
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: v6,
    p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2),
    oldSize: v7,
    newSize: v13,
    newSizea: m_stackLevel,
    preserve: false);
  *((_DWORD *)this + 1) = v8;
  this->m_stackLevel = m_stackLevel;
  memset(dst: v8, value: 0, count: 4 * m_stackLevel);
  v9 = this->m_stackLevel;
  v10 = *((_DWORD **)this + 1);
  *(this + 3) = a2[3];
  if ( v9 != 0 )
  {
    v11 = a2[1].m_stackLevel - (_DWORD)v10;
    do
    {
      *v10 = *(_DWORD *)((char *)v10 + v11);
      ++v10;
      --v9;
    }
    while ( v9 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440D20
// Name: public: TaoCrypt::Integer::Integer(long)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTable::CStringPoolIndex *__thiscall TaoCrypt::Integer::Integer(
        CUtlSymbolTable::CStringPoolIndex *this,
        int value)
{
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *v3; // ebx
  CUtlSymbolTable::CStringPoolIndex v4; // edi
  void *v5; // ecx
  unsigned __int8 *v6; // eax
  unsigned __int8 *v7; // eax
  int v8; // eax
  void *v10; // [esp-Ch] [ebp-18h]

  v3 = (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2);
  *this = (CUtlSymbolTable::CStringPoolIndex)2;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2),
    n: 2u,
    __formal: 0);
  v4 = *this;
  v5 = (void *)*this;
  v10 = (void *)*this;
  *((_DWORD *)this + 1) = v6;
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: v5,
    p: v3,
    oldSize: v6,
    newSize: v10,
    newSizea: *(_DWORD *)&v4,
    preserve: false);
  *((_DWORD *)this + 1) = v7;
  *this = v4;
  memset(dst: v7, value: 0, count: 4 * *(_DWORD *)&v4);
  v8 = value;
  if ( value < 0 )
  {
    *((_DWORD *)this + 3) = 1;
    v8 = -value;
  }
  else
  {
    *((_DWORD *)this + 3) = 0;
  }
  **((_DWORD **)this + 1) = v8;
  *(_DWORD *)(*((_DWORD *)this + 1) + 4) = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440DA0
// Name: private: TaoCrypt::Integer::Integer(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::Integer::Integer(TaoCrypt::Integer *this, unsigned int a2, unsigned int a3)
{
  int v4; // edx
  int m_stackLevel; // edi
  void *v6; // ecx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  _DWORD *v9; // edx
  void *v11; // [esp-10h] [ebp-18h]
  unsigned int v12; // [esp+0h] [ebp-8h]

  if ( a3 > 8 )
  {
    if ( a3 > 0x10 )
    {
      if ( a3 > 0x20 )
      {
        if ( a3 > 0x40 )
          v4 = 1 << TaoCrypt::BitPrecision(this: (TaoCrypt *)(a3 - 1), a2: v12);
        else
          v4 = 64;
      }
      else
      {
        v4 = 32;
      }
    }
    else
    {
      v4 = 16;
    }
  }
  else
  {
    v4 = *((_DWORD *)RoundupSizeTable + a3);
  }
  this->m_stackLevel = v4;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2),
    n: v4,
    __formal: 0);
  m_stackLevel = this->m_stackLevel;
  v6 = (void *)this->m_stackLevel;
  v11 = (void *)this->m_stackLevel;
  *((_DWORD *)this + 1) = v7;
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: v6,
    p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2),
    oldSize: v7,
    newSize: v11,
    newSizea: m_stackLevel,
    preserve: false);
  *((_DWORD *)this + 1) = v8;
  this->m_stackLevel = m_stackLevel;
  memset(dst: v8, value: 0, count: 4 * m_stackLevel);
  v9 = *((_DWORD **)this + 1);
  *((_DWORD *)this + 3) = 0;
  *v9 = a2;
  if ( this->m_stackLevel != 1 )
    memset((void *)(*((_DWORD *)this + 1) + 4), 0, 4 * (this->m_stackLevel - 1));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00440E60
// Name: public: TaoCrypt::Integer::Integer(unsigned char const __near *,unsigned int,enum TaoCrypt::Integer::Signedness)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Integer::Integer(
        CUtlSymbolTable::CStringPoolIndex *this,
        char *encodedInteger,
        unsigned int byteCount,
        int a4)
{
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *v5; // ebx
  CUtlSymbolTable::CStringPoolIndex v6; // edi
  void *v7; // ecx
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  void *v10; // [esp-Ch] [ebp-18h]

  v5 = (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2);
  *this = 0;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 2),
    n: 0,
    __formal: 0);
  v6 = *this;
  v7 = (void *)*this;
  v10 = (void *)*this;
  *((_DWORD *)this + 1) = v8;
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: v7,
    p: v5,
    oldSize: v8,
    newSize: v10,
    newSizea: *(_DWORD *)&v6,
    preserve: false);
  *((_DWORD *)this + 1) = v9;
  *this = v6;
  memset(dst: v9, value: 0, count: 4 * *(_DWORD *)&v6);
  TaoCrypt::Integer::Decode((int)this, a2: encodedInteger, a3: byteCount, a4);
}

//------------------------------------------------------------------------------
// Address: 0x00440ED0
// Name: public: static class TaoCrypt::Integer const __near & TaoCrypt::Integer::Zero(void)
// Source: json
//------------------------------------------------------------------------------
const CFunctorData *__thiscall TaoCrypt::Integer::Zero(const CSplitScreenAddedConVar *this)
{
  const CFunctorData *v1; // eax
  TaoCrypt::Integer *v2; // eax

  v1 = zero;
  if ( zero == nullptr )
  {
    v2 = (TaoCrypt::Integer *)operator new(sz: this);
    if ( v2 != nullptr )
    {
      v1 = (const CFunctorData *)TaoCrypt::Integer::Integer(this: v2);
      zero = v1;
    }
    else
    {
      zero = nullptr;
      return nullptr;
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00440F10
// Name: public: static class TaoCrypt::Integer const __near & TaoCrypt::Integer::One(void)
// Source: json
//------------------------------------------------------------------------------
const CFunctorData *__thiscall TaoCrypt::Integer::One(const CSplitScreenAddedConVar *this)
{
  const CFunctorData *v1; // eax
  TaoCrypt::Integer *v2; // eax

  v1 = one;
  if ( one == nullptr )
  {
    v2 = (TaoCrypt::Integer *)operator new(sz: this);
    if ( v2 != nullptr )
    {
      v1 = (const CFunctorData *)TaoCrypt::Integer::Integer(this: v2, a2: 1u, a3: 2u);
      one = v1;
    }
    else
    {
      one = nullptr;
      return nullptr;
    }
  }
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x00440F50
// Name: public: static class TaoCrypt::Integer TaoCrypt::Integer::Power2(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Integer::Power2(
        const CInternalFileSystemPassThru<IFileSystem> *e,
        TaoCrypt::Integer *a2,
        unsigned int ea)
{
  TaoCrypt::Integer::Integer(this: a2, a2: 0, a3: (ea + 32) >> 5);
  TaoCrypt::Integer::SetBit(this: a2, n: ea, value: true);
}

//------------------------------------------------------------------------------
// Address: 0x00440F80
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::operator-(void)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__userpurge TaoCrypt::Integer::operator-@<eax>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        TaoCrypt::Integer *a2,
        const char *a3,
        CUtlBuffer *a4)
{
  TaoCrypt::Integer::Integer(this: a2, a2: (const struct TaoCrypt::Integer *)this);
  TaoCrypt::Integer::Negate(this: a2);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x00440FA0
// Name: public: class TaoCrypt::Integer __near & TaoCrypt::Integer::operator--(void)
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::Integer::operator--(
        CInternalFileSystemPassThru<IFileSystem> *this)
{
  CInternalFileSystemPassThru<IFileSystem>_vtbl *v2; // esi
  int v3; // eax
  const CSplitScreenAddedConVar *v5; // ecx
  int v6; // eax
  CInternalFileSystemPassThru<IFileSystem> *v7; // eax
  char *v8; // eax
  const char *v9; // [esp+0h] [ebp-18h]
  const char *v10; // [esp+0h] [ebp-18h]
  CUtlBuffer *v11; // [esp+4h] [ebp-14h]
  CInternalFileSystemPassThru<IFileSystem> v12; // [esp+8h] [ebp-10h] BYREF

  v2 = this->IFileSystem::IAppSystem::__vftable;
  if ( *((_DWORD *)this + 3) == 1 )
  {
    TaoCrypt::Increment(A: (unsigned int *)this->IFileSystem::IBaseFileSystem::__vftable, a2: 1, a3: (unsigned int)v2);
    if ( v3 != 0 )
    {
      TaoCrypt::Block<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>::CleanGrow(
        (char *)this,
        newSize: 2 * (int)this->IFileSystem::IAppSystem::__vftable);
      *((_DWORD *)&this->Read + ((unsigned int)this->IFileSystem::IAppSystem::__vftable >> 1)) = 1;
      return this;
    }
  }
  else
  {
    TaoCrypt::Decrement(A: (unsigned int *)this->IFileSystem::IBaseFileSystem::__vftable, a2: (unsigned int)v2, B: 1u);
    if ( v6 != 0 )
    {
      v7 = (CInternalFileSystemPassThru<IFileSystem> *)TaoCrypt::Integer::One(this: v5);
      v8 = (char *)TaoCrypt::Integer::operator-(this: v7, a2: (TaoCrypt::Integer *)&v12, a3: v9, a4: v11);
      TaoCrypt::Integer::operator=(this, t: v8, a3: v10);
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
        this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v12.m_pBaseFileSystemPassThru,
        p: (unsigned __int8 *)v12.IFileSystem::IBaseFileSystem::__vftable,
        n: (unsigned int)v12.IFileSystem::IAppSystem::__vftable);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00441030
// Name: public: class TaoCrypt::Integer __near & TaoCrypt::Integer::operator>>=(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::Integer::operator>>=(
        CInternalFileSystemPassThru<IFileSystem> *this,
        unsigned int a2)
{
  unsigned int *v3; // esi
  const CSplitScreenAddedConVar *v4; // ecx
  char *v5; // eax
  const char *v7; // [esp+0h] [ebp-10h]

  v3 = (unsigned int *)TaoCrypt::Integer::WordCount((int *)this);
  TaoCrypt::ShiftWordsRightByWords(this: (TaoCrypt *)this->IFileSystem::IBaseFileSystem::__vftable, a2: v3, a3: a2 >> 5);
  if ( (unsigned int)v3 > a2 >> 5 )
    TaoCrypt::ShiftWordsRightByBits(
      r: this->IFileSystem::IBaseFileSystem::__vftable,
      ra: (unsigned int *)this->IFileSystem::IBaseFileSystem::__vftable,
      n: (unsigned int)v3 - (a2 >> 5),
      shiftBits: a2 & 0x1F);
  if ( *((_DWORD *)this + 3) == 1 && TaoCrypt::Integer::WordCount((int *)this) == 0 )
  {
    v5 = (char *)TaoCrypt::Integer::Zero(this: v4);
    TaoCrypt::Integer::operator=(this, t: v5, a3: v7);
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004410A0
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::Plus(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer __thiscall TaoCrypt::Integer::Plus(
        TaoCrypt::Integer *this,
        TaoCrypt::Integer *a2,
        struct TaoCrypt::Integer *a3)
{
  struct TaoCrypt::Integer *v3; // ebx
  struct TaoCrypt::Integer *m_stackLevel; // ecx
  unsigned int *v6; // eax
  TaoCrypt *v8; // [esp-Ch] [ebp-20h]
  struct TaoCrypt::Integer *v9; // [esp-8h] [ebp-1Ch]
  TaoCrypt::Integer *v10; // [esp-4h] [ebp-18h]
  const struct TaoCrypt::Integer *v11; // [esp+0h] [ebp-14h]
  unsigned int v12; // [esp+10h] [ebp-4h] BYREF

  v3 = a3;
  m_stackLevel = (struct TaoCrypt::Integer *)this->m_stackLevel;
  v12 = a3->m_stackLevel;
  a3 = m_stackLevel;
  v6 = (unsigned int *)&a3;
  if ( (unsigned int)m_stackLevel <= v12 )
    v6 = &v12;
  TaoCrypt::Integer::Integer(this: a2, a2: 0, a3: *v6);
  if ( *((_DWORD *)this + 3) != 1 )
  {
    v10 = v3;
    v9 = this;
    v8 = (TaoCrypt *)a2;
    if ( v3[3].m_stackLevel != 1 )
    {
      TaoCrypt::PositiveAdd(this: (TaoCrypt *)a2, a2: this, a3: v3, a4: v11);
      return (struct TaoCrypt::Integer)a2;
    }
    goto LABEL_8;
  }
  if ( v3[3].m_stackLevel != 1 )
  {
    v10 = this;
    v9 = v3;
    v8 = (TaoCrypt *)a2;
LABEL_8:
    TaoCrypt::PositiveSubtract(this: v8, a2: v9, a3: v10);
    return (struct TaoCrypt::Integer)a2;
  }
  TaoCrypt::PositiveAdd(this: (TaoCrypt *)a2, a2: this, a3: v3, a4: v11);
  a2[3].m_stackLevel = 1;
  return (struct TaoCrypt::Integer)a2;
}

//------------------------------------------------------------------------------
// Address: 0x00441130
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::Minus(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer __thiscall TaoCrypt::Integer::Minus(
        TaoCrypt::Integer *this,
        TaoCrypt::Integer *a2,
        struct TaoCrypt::Integer *a3)
{
  struct TaoCrypt::Integer *v3; // ebx
  struct TaoCrypt::Integer *m_stackLevel; // ecx
  unsigned int *v6; // eax
  TaoCrypt *v8; // [esp-Ch] [ebp-20h]
  struct TaoCrypt::Integer *v9; // [esp-8h] [ebp-1Ch]
  TaoCrypt::Integer *v10; // [esp-4h] [ebp-18h]
  const struct TaoCrypt::Integer *v11; // [esp+0h] [ebp-14h]
  unsigned int v12; // [esp+10h] [ebp-4h] BYREF

  v3 = a3;
  m_stackLevel = (struct TaoCrypt::Integer *)this->m_stackLevel;
  v12 = a3->m_stackLevel;
  a3 = m_stackLevel;
  v6 = (unsigned int *)&a3;
  if ( (unsigned int)m_stackLevel <= v12 )
    v6 = &v12;
  TaoCrypt::Integer::Integer(this: a2, a2: 0, a3: *v6);
  if ( *((_DWORD *)this + 3) == 1 )
  {
    if ( v3[3].m_stackLevel != 1 )
    {
      TaoCrypt::PositiveAdd(this: (TaoCrypt *)a2, a2: this, a3: v3, a4: v11);
      a2[3].m_stackLevel = 1;
      return (struct TaoCrypt::Integer)a2;
    }
    v10 = this;
    v9 = v3;
    v8 = (TaoCrypt *)a2;
  }
  else
  {
    v10 = v3;
    v9 = this;
    v8 = (TaoCrypt *)a2;
    if ( v3[3].m_stackLevel == 1 )
    {
      TaoCrypt::PositiveAdd(this: (TaoCrypt *)a2, a2: this, a3: v3, a4: v11);
      return (struct TaoCrypt::Integer)a2;
    }
  }
  TaoCrypt::PositiveSubtract(this: v8, a2: v9, a3: v10);
  return (struct TaoCrypt::Integer)a2;
}

//------------------------------------------------------------------------------
// Address: 0x004411C0
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::Times(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer __thiscall TaoCrypt::Integer::Times(
        TaoCrypt::Integer *this,
        TaoCrypt::Integer *a2,
        struct TaoCrypt::Integer *a3)
{
  TaoCrypt::Integer::Integer(this: a2);
  TaoCrypt::Multiply(this: a2, a2: this, a3);
  return (struct TaoCrypt::Integer)a2;
}

//------------------------------------------------------------------------------
// Address: 0x004411F0
// Name: void TaoCrypt::PositiveDivide(class TaoCrypt::Integer __near &,class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::PositiveDivide(
        void *remainder,
        int quotient,
        CInternalFileSystemPassThru<IFileSystem> *a3,
        int *a4,
        int *t)
{
  int v5; // ebp
  int v6; // ebx
  const CSplitScreenAddedConVar *v7; // ecx
  char *v8; // eax
  unsigned int v9; // ebx
  const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *v10; // ebp
  unsigned int v11; // edi
  unsigned __int8 *v12; // eax
  unsigned __int8 *v13; // eax
  unsigned __int8 *v14; // ebx
  unsigned int v15; // [esp-4h] [ebp-24h]
  const char *v16; // [esp+0h] [ebp-20h]
  const char *v17; // [esp+0h] [ebp-20h]
  unsigned int v18; // [esp+10h] [ebp-10h]
  CFunctorData T; // [esp+14h] [ebp-Ch] BYREF
  unsigned __int8 *v20; // [esp+18h] [ebp-8h]
  char v21; // [esp+1Ch] [ebp-4h] BYREF

  v5 = TaoCrypt::Integer::WordCount(this: a4);
  v6 = TaoCrypt::Integer::WordCount(this: t);
  if ( TaoCrypt::Integer::PositiveCompare(
         this: (CInternalFileSystemPassThru<IFileSystem> *)a4,
         (CInternalFileSystemPassThru<IFileSystem> *)t) == (CInternalFileSystemPassThru<IFileSystem> *)-1 )
  {
    TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)quotient, t: (char *)a4, a3: v16);
    *(_DWORD *)(quotient + 12) = 0;
    v8 = (char *)TaoCrypt::Integer::Zero(this: v7);
    TaoCrypt::Integer::operator=(this: a3, t: v8, a3: v17);
  }
  else
  {
    v9 = (v6 & 1) + v6;
    v10 = (const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)((v5 & 1) + v5);
    v11 = TaoCrypt::RoundupSize();
    TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      a: *(void **)(quotient + 4),
      p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(quotient + 8),
      oldSize: *(unsigned __int8 **)(quotient + 4),
      newSize: *(void **)quotient,
      newSizea: v11,
      preserve: false);
    *(_DWORD *)(quotient + 4) = v12;
    *(_DWORD *)quotient = v11;
    memset(dst: v12, value: 0, count: 4 * v11);
    *(_DWORD *)(quotient + 12) = 0;
    v18 = TaoCrypt::RoundupSize();
    TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      a: a3->IFileSystem::IAppSystem::__vftable,
      p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&a3->m_pBaseFileSystemPassThru,
      oldSize: (unsigned __int8 *)a3->IFileSystem::IBaseFileSystem::__vftable,
      newSize: a3->IFileSystem::IAppSystem::__vftable,
      newSizea: v18,
      preserve: false);
    a3->IFileSystem::IAppSystem::__vftable = (CInternalFileSystemPassThru<IFileSystem>_vtbl *)v18;
    a3->IFileSystem::IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)v13;
    memset(dst: v13, value: 0, count: 4 * v18);
    a3[1].IFileSystem::IAppSystem::__vftable = nullptr;
    TaoCrypt::Block<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>::Block<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      this: (CRefCountServiceBase<1,CRefMT> *)&T,
      s: (CRefCountServiceBase<1,CRefMT>_vtbl *)((char *)&v10->m_Memory.m_nAllocationCount + 2 * v9));
    v15 = v9;
    v14 = v20;
    TaoCrypt::Divide(
      R: (unsigned int *)a3->IFileSystem::IBaseFileSystem::__vftable,
      Q: *(unsigned int **)(quotient + 4),
      T: (unsigned int *)a3->IFileSystem::IBaseFileSystem::__vftable,
      shiftBits: (unsigned int *)v20,
      a5: a4[1],
      TB: v10,
      a7: t[1],
      NB: v15);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v21,
      p: v14,
      n: (unsigned int)T.__vftable);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00441330
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::AbsoluteValue(void)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__userpurge TaoCrypt::Integer::AbsoluteValue@<eax>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        TaoCrypt::Integer *a2,
        const char *a3,
        CUtlBuffer *a4)
{
  TaoCrypt::Integer::Integer(this: a2, a2: (const struct TaoCrypt::Integer *)this);
  a2[3].m_stackLevel = 0;
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x00441350
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::MultiplicativeInverse(void)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__userpurge TaoCrypt::Integer::MultiplicativeInverse@<eax>(
        CInternalFileSystemPassThru<IFileSystem> *this@<ecx>,
        TaoCrypt::Integer *a2,
        const char *a3,
        CUtlBuffer *a4)
{
  const CSplitScreenAddedConVar *v5; // ecx
  const CFunctorData *v7; // eax

  if ( TaoCrypt::Integer::IsUnit(this) )
  {
    TaoCrypt::Integer::Integer(this: a2, a2: (const struct TaoCrypt::Integer *)this);
  }
  else
  {
    v7 = TaoCrypt::Integer::Zero(this: v5);
    TaoCrypt::Integer::Integer(this: a2, a2: (const struct TaoCrypt::Integer *)v7);
  }
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x00441390
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::MontgomeryRepresentation::ConvertOut(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::MontgomeryRepresentation::ConvertOut(
        IFileSystem *this,
        TaoCrypt::Integer *a2,
        int *a3)
{
  unsigned int *v4; // edx
  unsigned int v5; // ebx
  int *v6; // eax
  int v7; // edi
  _DWORD *v8; // eax
  int v9; // ecx
  int v10; // eax
  TaoCrypt *R; // [esp+Ch] [ebp-4h]

  v4 = *((unsigned int **)this + 20);
  v5 = *((_DWORD *)this + 3);
  R = *((TaoCrypt **)this + 8);
  v6 = a3;
  v7 = *a3;
  if ( *a3 != 0 )
  {
    v8 = *((_DWORD **)this + 20);
    v9 = a3[1] - (_DWORD)v4;
    do
    {
      *v8 = *(_DWORD *)((char *)v8 + v9);
      ++v8;
      --v7;
    }
    while ( v7 != 0 );
    v6 = a3;
  }
  v10 = *v6;
  if ( 2 * v5 != v10 )
    memset(&v4[v10], 0, 4 * (2 * v5 - v10));
  TaoCrypt::MontgomeryReduce(
    this: R,
    T: &v4[2 * v5],
    a3: v4,
    a4: *((CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > **)this
    + 4),
    a5: *((const unsigned int **)this + 16),
    N: v5);
  TaoCrypt::Integer::Integer(this: a2, a2: (const struct TaoCrypt::Integer *)this + 7);
  return a2;
}

//------------------------------------------------------------------------------
// Address: 0x00441410
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::Double(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ModularArithmetic::Double(IFileSystem *this, const char *a)
{
  ((void (__thiscall *)(IFileSystem *, const char *, const char *))this->Init)(a1: this, a2: a, a3: a);
}

//------------------------------------------------------------------------------
// Address: 0x00441420
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::Divide(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
const char *__userpurge TaoCrypt::ModularArithmetic::Divide@<eax>(
        IFileSystem *this@<ecx>,
        const char *a,
        const char *b,
        char *a4,
        int a5,
        PathTypeFilter_t a6,
        unsigned int *a7)
{
  IFileSystem_vtbl *v8; // edi
  int v9; // eax

  v8 = this->IAppSystem::__vftable;
  v9 = ((int (__thiscall *)(IFileSystem *, const char *))this->GetSearchPath)(a1: this, a2: b);
  return ((const char *(__thiscall *)(IFileSystem *, const char *, int))v8->RelativePathToFullPath)(
           a1: this,
           a2: a,
           a3: v9);
}

//------------------------------------------------------------------------------
// Address: 0x00441490
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::ModularArithmetic::ConvertOut(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ModularArithmetic::ConvertOut(
        IFileSystem *this,
        TaoCrypt::Integer *a2,
        struct TaoCrypt::Integer *a3)
{
  TaoCrypt::Integer::Integer(this: a2, a2: a3);
}

//------------------------------------------------------------------------------
// Address: 0x004414B0
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Identity(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const CFunctorData *__thiscall TaoCrypt::EuclideanDomainOf::Identity(IFileSystem *this)
{
  return TaoCrypt::Integer::Zero((const CSplitScreenAddedConVar *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004414C0
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::MultiplicativeIdentity(void)const
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
const CFunctorData *__thiscall TaoCrypt::ModularArithmetic::MultiplicativeIdentity(IFileSystem *this)
{
  return TaoCrypt::Integer::One((const CSplitScreenAddedConVar *)this);
}

//------------------------------------------------------------------------------
// Address: 0x004414D0
// Name: public: unsigned int TaoCrypt::Integer::Encode(unsigned char __near *,unsigned int,enum TaoCrypt::Integer::Signedness)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __userpurge TaoCrypt::Integer::Encode@<eax>(
        struct TaoCrypt::Integer *a1@<ecx>,
        int a2@<ebp>,
        _BYTE *a3,
        unsigned int a4,
        unsigned int a5)
{
  unsigned int v6; // eax
  unsigned int v7; // edi
  bool v8; // cc
  unsigned int *v9; // eax
  TaoCrypt::Integer *v10; // eax
  unsigned int i; // esi
  char v12; // al
  unsigned int v14; // ebp
  unsigned int v15; // edi
  _BYTE *v16; // ebx
  char v17; // al
  int v18; // [esp-4h] [ebp-30h]
  FileSystemSeek_t v19; // [esp+0h] [ebp-2Ch]
  FileSystemSeek_t v20; // [esp+4h] [ebp-28h]
  CInternalFileSystemPassThru<IFileSystem> v21; // [esp+Ch] [ebp-20h] BYREF
  CInternalFileSystemPassThru<IFileSystem> e; // [esp+1Ch] [ebp-10h] BYREF

  if ( a5 != 0 && a1[3].m_stackLevel == 1 )
  {
    v6 = TaoCrypt::Integer::ByteCount(this: &a1->m_stackLevel);
    v7 = a4;
    a5 = v6;
    v8 = v6 <= a4;
    v9 = &a5;
    if ( v8 )
      v9 = &a4;
    TaoCrypt::Integer::Power2(&e, a2: (TaoCrypt::Integer *)&e, ea: 8 * *v9);
    TaoCrypt::Integer::Plus(this: v10, a2: (TaoCrypt::Integer *)&v21, a3: a1);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&e.m_pBaseFileSystemPassThru,
      p: (unsigned __int8 *)e.IFileSystem::IBaseFileSystem::__vftable,
      n: (unsigned int)e.IFileSystem::IAppSystem::__vftable);
    for ( i = 0; i < v7; ++i )
    {
      TaoCrypt::Integer::GetByte(this: &v21, n: (void *)(v7 - i - 1), a3: v19, a4: v20);
      a3[i] = v12;
    }
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v21.m_pBaseFileSystemPassThru,
      p: (unsigned __int8 *)v21.IFileSystem::IBaseFileSystem::__vftable,
      n: (unsigned int)v21.IFileSystem::IAppSystem::__vftable);
    return v7;
  }
  else
  {
    v18 = a2;
    v14 = a4;
    v15 = a4;
    if ( a4 != 0 )
    {
      v16 = a3;
      do
      {
        TaoCrypt::Integer::GetByte(
          this: (CInternalFileSystemPassThru<IFileSystem> *)a1,
          n: (void *)(v15 - 1),
          a3: v18,
          a4: v19);
        *v16++ = v17;
        --v15;
      }
      while ( v15 != 0 );
    }
    return v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004415B0
// Name: public: void TaoCrypt::Integer::Randomize(class TaoCrypt::RandomNumberGenerator __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Integer::Randomize(
        TaoCrypt::Integer *this,
        struct TaoCrypt::RandomNumberGenerator *rng,
        struct TaoCrypt::Integer *a3,
        TaoCrypt::Integer *a4)
{
  const char *v5; // edi
  const char *v6; // [esp+0h] [ebp-20h]
  CInternalFileSystemPassThru<IFileSystem> t; // [esp+10h] [ebp-10h] BYREF

  TaoCrypt::Integer::Minus(this: a4, a2: (TaoCrypt::Integer *)&t, a3);
  v5 = (const char *)TaoCrypt::Integer::BitCount(this: (int *)&t);
  do
    TaoCrypt::Integer::Randomize(
      (CInternalFileSystemPassThru<IFileSystem> *)this,
      (TaoCrypt::RandomNumberGenerator *)rng,
      nbits: v5);
  while ( TaoCrypt::Integer::Compare((CInternalFileSystemPassThru<IFileSystem> *)this, &t) > 0 );
  TaoCrypt::Integer::operator+=((CInternalFileSystemPassThru<IFileSystem> *)this, t: a3, a3: v6);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&t.m_pBaseFileSystemPassThru,
    p: (unsigned __int8 *)t.IFileSystem::IBaseFileSystem::__vftable,
    n: (unsigned int)t.IFileSystem::IAppSystem::__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x00441620
// Name: public: static void TaoCrypt::Integer::Divide(class TaoCrypt::Integer __near &,class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl TaoCrypt::Integer::Divide(
        struct TaoCrypt::Integer *quotient,
        CInternalFileSystemPassThru<IFileSystem> *a2,
        const struct TaoCrypt::Integer *a3,
        CInternalFileSystemPassThru<IFileSystem> *a4)
{
  void *v4; // ecx
  TaoCrypt::Integer *v5; // eax
  const char *v6; // [esp+0h] [ebp-30h]
  const char *v7; // [esp+0h] [ebp-30h]
  CUtlBuffer *v8; // [esp+4h] [ebp-2Ch]
  char t[4]; // [esp+10h] [ebp-20h] BYREF
  unsigned __int8 *v10; // [esp+14h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v11; // [esp+18h] [ebp-18h] BYREF
  unsigned __int8 *v12; // [esp+24h] [ebp-Ch]
  __int64 v13; // [esp+28h] [ebp-8h] BYREF

  TaoCrypt::PositiveDivide(remainder: v4, (int)quotient, a3: a2, a4: &a3->m_stackLevel, t: (int *)a4);
  if ( a3[3].m_stackLevel == 1 )
  {
    TaoCrypt::Integer::Negate(this: (TaoCrypt::Integer *)a2);
    if ( !TaoCrypt::Integer::operator!(this: (CInternalFileSystemPassThru<IFileSystem> *)quotient) )
    {
      TaoCrypt::Integer::operator--(this: a2);
      v5 = TaoCrypt::Integer::AbsoluteValue(this: a4, a2: (TaoCrypt::Integer *)&v11.m_iRefs, a3: v6, a4: v8);
      TaoCrypt::Integer::Minus(this: v5, a2: (TaoCrypt::Integer *)t, a3: quotient);
      TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)quotient, t, a3: v7);
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v11, p: v10, n: *(unsigned int *)t);
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
        this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v13,
        p: v12,
        n: v11.m_iRefs);
    }
  }
  if ( a4[1].IFileSystem::IAppSystem::__vftable == (CInternalFileSystemPassThru<IFileSystem>_vtbl *)1 )
    TaoCrypt::Integer::Negate(this: (TaoCrypt::Integer *)a2);
}

//------------------------------------------------------------------------------
// Address: 0x004416D0
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::DividedBy(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer __thiscall TaoCrypt::Integer::DividedBy(
        TaoCrypt::Integer *this,
        TaoCrypt::Integer *a2,
        CInternalFileSystemPassThru<IFileSystem> *a3)
{
  TaoCrypt::Integer quotient; // [esp+8h] [ebp-10h] BYREF
  unsigned __int8 *v6; // [esp+Ch] [ebp-Ch]
  __int64 v7; // [esp+10h] [ebp-8h] BYREF

  TaoCrypt::Integer::Integer(this: &quotient);
  TaoCrypt::Integer::Integer(this: a2);
  TaoCrypt::Integer::Divide(&quotient, (CInternalFileSystemPassThru<IFileSystem> *)a2, a3: this, a4: a3);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7,
    p: v6,
    n: quotient.m_stackLevel);
  return (struct TaoCrypt::Integer)a2;
}

//------------------------------------------------------------------------------
// Address: 0x00441720
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::Modulo(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer __thiscall TaoCrypt::Integer::Modulo(
        TaoCrypt::Integer *this,
        TaoCrypt::Integer *quotient,
        CInternalFileSystemPassThru<IFileSystem> *a3)
{
  CInternalFileSystemPassThru<IFileSystem> v5; // [esp+8h] [ebp-10h] BYREF

  TaoCrypt::Integer::Integer(this: quotient);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v5);
  TaoCrypt::Integer::Divide(quotient, a2: &v5, a3: this, a4: a3);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v5.m_pBaseFileSystemPassThru,
    p: (unsigned __int8 *)v5.IFileSystem::IBaseFileSystem::__vftable,
    n: (unsigned int)v5.IFileSystem::IAppSystem::__vftable);
  return (struct TaoCrypt::Integer)quotient;
}

//------------------------------------------------------------------------------
// Address: 0x00441770
// Name: class TaoCrypt::Integer TaoCrypt::a_exp_b_mod_c(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
CFunctorData *__cdecl TaoCrypt::a_exp_b_mod_c(
        CFunctorData *result,
        int *exponent,
        int a3,
        struct TaoCrypt::Integer *a4)
{
  CUtlVector<int,CUtlMemory<int,int> > v5; // [esp+4h] [ebp-3Ch] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v6; // [esp+18h] [ebp-28h] BYREF
  unsigned __int8 *v7; // [esp+24h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v8; // [esp+28h] [ebp-18h] BYREF
  unsigned __int8 *v9; // [esp+34h] [ebp-Ch]
  __int64 v10; // [esp+38h] [ebp-8h] BYREF

  v5.m_Memory.m_nAllocationCount = (int)&TaoCrypt::AbstractRing::MultiplicativeGroupT::`vftable';
  v5.m_Memory.m_nGrowSize = (int)&v5;
  v5.m_Memory.m_pMemory = (int *)&TaoCrypt::ModularArithmetic::`vftable';
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v5.m_Size, a2: a4);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v6.m_iRefs, a2: 0, a3: a4->m_stackLevel);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v8.m_iRefs);
  TaoCrypt::AbstractRing::Exponentiate(this: &v5, base: (int)result, exponent);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v10,
    p: v9,
    n: v8.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v8, p: v7, n: v6.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v6, p: (unsigned __int8 *)v5.m_pElements, n: v5.m_Size);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00441810
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::Add(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x004418D0
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::Subtract(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00441980
// Name: public: TaoCrypt::MontgomeryRepresentation::MontgomeryRepresentation(class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__userpurge TaoCrypt::MontgomeryRepresentation::MontgomeryRepresentation@<eax>(
        IFileSystem *this@<ecx>,
        const FileAsyncRequest_t *m,
        int a3,
        FSAsyncControl_t__ **a4)
{
  unsigned int *v5; // edi
  unsigned int v6; // ebx
  unsigned __int8 *v7; // eax
  unsigned __int8 *v8; // eax
  unsigned int v10; // [esp-8h] [ebp-18h]
  unsigned int v11; // [esp-4h] [ebp-14h]

  this->IBaseFileSystem::__vftable = (IBaseFileSystem_vtbl *)&TaoCrypt::AbstractRing::MultiplicativeGroupT::`vftable';
  v5 = (unsigned int *)this + 3;
  *((_DWORD *)this + 2) = this;
  this->IAppSystem::__vftable = (IFileSystem_vtbl *)&TaoCrypt::ModularArithmetic::`vftable';
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 3, a2: (const struct TaoCrypt::Integer *)m);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 7, a2: 0, a3: (unsigned int)m->pszFilename);
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 11);
  v11 = *v5;
  this->IAppSystem::__vftable = (IFileSystem_vtbl *)&TaoCrypt::MontgomeryRepresentation::`vftable';
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)this + 15, a2: 0, a3: v11);
  v10 = 5 * *v5;
  *((_DWORD *)this + 19) = v10;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)this + 7,
    n: v10,
    __formal: 0);
  v6 = *((_DWORD *)this + 19);
  *((_DWORD *)this + 20) = v7;
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: (void *)v6,
    p: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)this + 7,
    oldSize: v7,
    newSize: (void *)v6,
    newSizea: v6,
    preserve: false);
  *((_DWORD *)this + 20) = v8;
  *((_DWORD *)this + 19) = v6;
  memset(dst: v8, value: 0, count: 4 * v6);
  TaoCrypt::RecursiveInverseModPower2(
    a1: *((_DWORD *)this + 4),
    a2: (unsigned int)this + 84,
    R: *((unsigned int **)this + 16),
    T: *((unsigned int **)this + 20),
    a5: *((int **)this + 4),
    N: *v5);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00441A40
// Name: public: virtual bool TaoCrypt::EuclideanDomainOf::IsUnit(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::EuclideanDomainOf::IsUnit(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        CUtlVector<char,CUtlMemory<char,int> > *a)
{
  TaoCrypt::Integer::IsUnit(this: (CInternalFileSystemPassThru<IFileSystem> *)a);
}

//------------------------------------------------------------------------------
// Address: 0x00441A50
// Name: public: virtual bool TaoCrypt::EuclideanDomainOf::Equal(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall TaoCrypt::EuclideanDomainOf::Equal(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        CInternalFileSystemPassThru<IFileSystem> *a,
        CInternalFileSystemPassThru<IFileSystem> *b)
{
  return TaoCrypt::Integer::Compare(this: a, t: b) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00441AA0
// Name: public: virtual class TaoCrypt::Integer __near & TaoCrypt::EuclideanDomainOf::Accumulate(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00441AC0
// Name: public: virtual class TaoCrypt::Integer __near & TaoCrypt::EuclideanDomainOf::Reduce(class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x00441AE0
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Add(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::EuclideanDomainOf::Add(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        TaoCrypt::Integer *a,
        struct TaoCrypt::Integer *a3)
{
  const char *v4; // [esp+0h] [ebp-14h]
  char t[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  __int64 v7; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Plus(this: a, a2: (TaoCrypt::Integer *)t, a3);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28), t, a3: v4);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7,
    p: v6,
    n: *(unsigned int *)t);
}

//------------------------------------------------------------------------------
// Address: 0x00441B30
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Inverse(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::EuclideanDomainOf::Inverse(
        TaoCrypt::EuclideanDomainOf *this,
        CInternalFileSystemPassThru<IFileSystem> *a2)
{
  char *v3; // eax
  CInternalFileSystemPassThru<IFileSystem> *v4; // esi
  const char *v6; // [esp+0h] [ebp-14h]
  const char *v7; // [esp+0h] [ebp-14h]
  char v8[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v9; // [esp+8h] [ebp-Ch]
  __int64 v10; // [esp+Ch] [ebp-8h] BYREF

  v3 = (char *)TaoCrypt::Integer::operator-(this: a2, a2: (TaoCrypt::Integer *)v8, a3: v6, a4: *(CUtlBuffer **)v8);
  v4 = TaoCrypt::Integer::operator=(
         this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28),
         t: v3,
         a3: v7);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v10,
    p: v9,
    n: *(unsigned int *)v8);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00441B70
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Subtract(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::EuclideanDomainOf::Subtract(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        TaoCrypt::Integer *a,
        struct TaoCrypt::Integer *a3)
{
  const char *v4; // [esp+0h] [ebp-14h]
  char t[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  __int64 v7; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Minus(this: a, a2: (TaoCrypt::Integer *)t, a3);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28), t, a3: v4);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7,
    p: v6,
    n: *(unsigned int *)t);
}

//------------------------------------------------------------------------------
// Address: 0x00441BC0
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Double(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::EuclideanDomainOf::Double(
        TaoCrypt::EuclideanDomainOf *this,
        struct TaoCrypt::Integer *a2)
{
  CInternalFileSystemPassThru<IFileSystem> *v3; // esi
  const char *v5; // [esp+0h] [ebp-14h]
  char t[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v7; // [esp+8h] [ebp-Ch]
  __int64 v8; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Plus(this: a2, a2: (TaoCrypt::Integer *)t, a3: a2);
  v3 = TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28), t, a3: v5);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v8,
    p: v7,
    n: *(unsigned int *)t);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00441C00
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Multiply(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::EuclideanDomainOf::Multiply(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        TaoCrypt::Integer *a,
        struct TaoCrypt::Integer *a3)
{
  const char *v4; // [esp+0h] [ebp-14h]
  char t[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  __int64 v7; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Times(this: a, a2: (TaoCrypt::Integer *)t, a3);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28), t, a3: v4);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7,
    p: v6,
    n: *(unsigned int *)t);
}

//------------------------------------------------------------------------------
// Address: 0x00441C50
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Square(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::EuclideanDomainOf::Square(
        TaoCrypt::EuclideanDomainOf *this,
        struct TaoCrypt::Integer *a2)
{
  CInternalFileSystemPassThru<IFileSystem> *v3; // esi
  const char *v5; // [esp+0h] [ebp-14h]
  char t[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v7; // [esp+8h] [ebp-Ch]
  __int64 v8; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Times(this: a2, a2: (TaoCrypt::Integer *)t, a3: a2);
  v3 = TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28), t, a3: v5);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v8,
    p: v7,
    n: *(unsigned int *)t);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00441C90
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::MultiplicativeInverse(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::EuclideanDomainOf::MultiplicativeInverse(
        TaoCrypt::EuclideanDomainOf *this,
        CInternalFileSystemPassThru<IFileSystem> *a2)
{
  char *v3; // eax
  CInternalFileSystemPassThru<IFileSystem> *v4; // esi
  const char *v6; // [esp+0h] [ebp-14h]
  const char *v7; // [esp+0h] [ebp-14h]
  char v8[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v9; // [esp+8h] [ebp-Ch]
  __int64 v10; // [esp+Ch] [ebp-8h] BYREF

  v3 = (char *)TaoCrypt::Integer::MultiplicativeInverse(
                 this: a2,
                 a2: (TaoCrypt::Integer *)v8,
                 a3: v6,
                 a4: *(CUtlBuffer **)v8);
  v4 = TaoCrypt::Integer::operator=(
         this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28),
         t: v3,
         a3: v7);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v10,
    p: v9,
    n: *(unsigned int *)v8);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00441CD0
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Divide(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::EuclideanDomainOf::Divide(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        TaoCrypt::Integer *a,
        CInternalFileSystemPassThru<IFileSystem> *a3)
{
  const char *v4; // [esp+0h] [ebp-14h]
  char t[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  __int64 v7; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::DividedBy(this: a, a2: (TaoCrypt::Integer *)t, a3);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28), t, a3: v4);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7,
    p: v6,
    n: *(unsigned int *)t);
}

//------------------------------------------------------------------------------
// Address: 0x00441D20
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::EuclideanDomainOf::Mod(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::EuclideanDomainOf::Mod(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        TaoCrypt::Integer *a,
        CInternalFileSystemPassThru<IFileSystem> *a3)
{
  const char *v4; // [esp+0h] [ebp-14h]
  char t[4]; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  __int64 v7; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Modulo(this: a, quotient: (TaoCrypt::Integer *)t, a3);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 28), t, a3: v4);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7,
    p: v6,
    n: *(unsigned int *)t);
}

//------------------------------------------------------------------------------
// Address: 0x00441D70
// Name: public: virtual void TaoCrypt::EuclideanDomainOf::DivisionAlgorithm(class TaoCrypt::Integer __near &,class TaoCrypt::Integer __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::EuclideanDomainOf::DivisionAlgorithm(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        CUtlVector<char,CUtlMemory<char,int> > *r,
        CInternalFileSystemPassThru<IFileSystem> *a3,
        struct TaoCrypt::Integer *a4,
        CInternalFileSystemPassThru<IFileSystem> *a5)
{
  TaoCrypt::Integer::Divide(quotient: (struct TaoCrypt::Integer *)r, a2: a3, a3: a4, a4: a5);
}

//------------------------------------------------------------------------------
// Address: 0x00441D90
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::ModularArithmetic::ConvertIn(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ModularArithmetic::ConvertIn(
        IFileSystem *this,
        TaoCrypt::Integer *quotient,
        TaoCrypt::Integer *a3)
{
  TaoCrypt::Integer::Modulo(this: a3, quotient, a3: (CInternalFileSystemPassThru<IFileSystem> *)this + 1);
}

//------------------------------------------------------------------------------
// Address: 0x00441DB0
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::Multiply(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__userpurge TaoCrypt::ModularArithmetic::Multiply@<eax>(
        IFileSystem *this@<ecx>,
        TaoCrypt::Integer *a,
        struct TaoCrypt::Integer *b,
        char *a4,
        int a5,
        PathTypeFilter_t a6,
        unsigned int *a7)
{
  CInternalFileSystemPassThru<IFileSystem> *v8; // esi
  const char *v10; // [esp+0h] [ebp-24h]
  char t[4]; // [esp+4h] [ebp-20h] BYREF
  unsigned __int8 *v12; // [esp+8h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v13; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int8 *v14; // [esp+18h] [ebp-Ch]
  __int64 v15; // [esp+1Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Times(this: a, a2: (TaoCrypt::Integer *)&v13.m_iRefs, a3: b);
  TaoCrypt::Integer::Modulo(
    this: (TaoCrypt::Integer *)&v13.m_iRefs,
    quotient: (TaoCrypt::Integer *)t,
    a3: (CInternalFileSystemPassThru<IFileSystem> *)this + 1);
  v8 = TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 44), t, a3: v10);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v13, p: v12, n: *(unsigned int *)t);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v15,
    p: v14,
    n: v13.m_iRefs);
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00441E20
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::Square(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ModularArithmetic::Square(IFileSystem *this, TaoCrypt::Integer *a)
{
  const char *v3; // [esp+0h] [ebp-24h]
  char t[4]; // [esp+4h] [ebp-20h] BYREF
  unsigned __int8 *v5; // [esp+8h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v6; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int8 *v7; // [esp+18h] [ebp-Ch]
  __int64 v8; // [esp+1Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Times(this: a, a2: (TaoCrypt::Integer *)&v6.m_iRefs, a3: a);
  TaoCrypt::Integer::Modulo(
    this: (TaoCrypt::Integer *)&v6.m_iRefs,
    quotient: (TaoCrypt::Integer *)t,
    a3: (CInternalFileSystemPassThru<IFileSystem> *)this + 1);
  TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 44), t, a3: v3);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v6, p: v5, n: *(unsigned int *)t);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v8,
    p: v7,
    n: v6.m_iRefs);
}

//------------------------------------------------------------------------------
// Address: 0x00441E90
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::MontgomeryRepresentation::ConvertIn(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::MontgomeryRepresentation::ConvertIn(
        IFileSystem *this,
        TaoCrypt::Integer *quotient,
        struct TaoCrypt::Integer *a3)
{
  CInternalFileSystemPassThru<IFileSystem> *v3; // esi
  TaoCrypt::Integer *v4; // eax
  const struct TaoCrypt::Integer *v5; // eax
  unsigned int v7; // [esp-4h] [ebp-28h]
  TaoCrypt::Integer v8; // [esp+4h] [ebp-20h] BYREF
  unsigned __int8 *v9; // [esp+8h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v10; // [esp+Ch] [ebp-18h] BYREF
  unsigned __int8 *v11; // [esp+18h] [ebp-Ch]
  __int64 v12; // [esp+1Ch] [ebp-8h] BYREF

  v3 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 12);
  v7 = 32 * *((_DWORD *)this + 3);
  v4 = TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v10.m_iRefs, a2: a3);
  v5 = (const struct TaoCrypt::Integer *)TaoCrypt::Integer::operator<<=(this: (int)v4, a2: v7);
  TaoCrypt::Integer::Integer(this: &v8, a2: v5);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v12,
    p: v11,
    n: v10.m_iRefs);
  TaoCrypt::Integer::Modulo(this: &v8, quotient, a3: v3);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v10, p: v9, n: v8.m_stackLevel);
  return quotient;
}

//------------------------------------------------------------------------------
// Address: 0x00441F00
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::MontgomeryRepresentation::MultiplicativeIdentity(void)const
// Source: json
//------------------------------------------------------------------------------
CInternalFileSystemPassThru<IFileSystem> *__thiscall TaoCrypt::MontgomeryRepresentation::MultiplicativeIdentity(
        IFileSystem *this)
{
  CInternalFileSystemPassThru<IFileSystem> *v2; // edi
  TaoCrypt::Integer *v3; // eax
  CInternalFileSystemPassThru<IFileSystem> *v4; // esi
  const char *v6; // [esp+0h] [ebp-28h]
  char t[4]; // [esp+8h] [ebp-20h] BYREF
  unsigned __int8 *v8; // [esp+Ch] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v9; // [esp+10h] [ebp-18h] BYREF
  unsigned __int8 *v10; // [esp+1Ch] [ebp-Ch]
  __int64 v11; // [esp+20h] [ebp-8h] BYREF

  v2 = (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 12);
  TaoCrypt::Integer::Power2(
    e: (const CInternalFileSystemPassThru<IFileSystem> *)this,
    a2: (TaoCrypt::Integer *)&v9.m_iRefs,
    ea: 32 * *((_DWORD *)this + 3));
  TaoCrypt::Integer::Modulo(this: v3, quotient: (TaoCrypt::Integer *)t, a3: v2);
  v4 = TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 44), t, a3: v6);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v9, p: v8, n: *(unsigned int *)t);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v11,
    p: v10,
    n: v9.m_iRefs);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00441F70
// Name: public: TaoCrypt::Integer::Integer(class TaoCrypt::RandomNumberGenerator __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
CUtlSymbolTable::CStringPoolIndex *__thiscall TaoCrypt::Integer::Integer(
        int this,
        CUtlSymbolTable::CStringPoolIndex *result,
        struct TaoCrypt::Integer *a3,
        TaoCrypt::Integer *a4)
{
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *v5; // ebx
  unsigned int v6; // edi
  void *v7; // ecx
  unsigned __int8 *v8; // eax
  unsigned __int8 *v9; // eax
  void *v11; // [esp-Ch] [ebp-18h]

  v5 = (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 8);
  *(_DWORD *)this = 0;
  TaoCrypt::AlignedAllocator<unsigned int>::allocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)(this + 8),
    n: 0,
    __formal: 0);
  v6 = *(_DWORD *)this;
  v7 = *(void **)this;
  v11 = *(void **)this;
  *(_DWORD *)(this + 4) = v8;
  TaoCrypt::StdReallocate<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
    a: v7,
    p: v5,
    oldSize: v8,
    newSize: v11,
    newSizea: v6,
    preserve: false);
  *(_DWORD *)(this + 4) = v9;
  *(_DWORD *)this = v6;
  memset(dst: v9, value: 0, count: 4 * v6);
  TaoCrypt::Integer::Randomize((TaoCrypt::Integer *)this, rng: (struct TaoCrypt::RandomNumberGenerator *)result, a3, a4);
  return (CUtlSymbolTable::CStringPoolIndex *)this;
}

//------------------------------------------------------------------------------
// Address: 0x00441FE0
// Name: public: static class TaoCrypt::Integer TaoCrypt::Integer::Gcd(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::Integer::Gcd(void *a, TaoCrypt::Integer *a2, int a3, int a4)
{
  const struct TaoCrypt::Integer *v4; // eax
  _DWORD v5[3]; // [esp+4h] [ebp-2Ch] BYREF
  TaoCrypt::Integer v6; // [esp+10h] [ebp-20h] BYREF
  unsigned __int8 *v7; // [esp+14h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v8; // [esp+18h] [ebp-18h] BYREF
  unsigned __int8 *v9; // [esp+24h] [ebp-Ch]
  __int64 v10; // [esp+28h] [ebp-8h] BYREF

  v5[1] = &TaoCrypt::AbstractRing::MultiplicativeGroupT::`vftable';
  v5[2] = v5;
  TaoCrypt::Integer::Integer(this: &v6);
  v5[0] = &TaoCrypt::EuclideanDomainOf::`vftable';
  TaoCrypt::Integer::Integer(this: (TaoCrypt::Integer *)&v8.m_iRefs);
  v4 = (const struct TaoCrypt::Integer *)(*(int (__thiscall **)(_DWORD *, int, int))(v5[0] + 100))(
                                           a1: v5,
                                           a2: a3,
                                           a3: a4);
  TaoCrypt::Integer::Integer(this: a2, a2: v4);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v10,
    p: v9,
    n: v8.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v8, p: v7, n: v6.m_stackLevel);
}

//------------------------------------------------------------------------------
// Address: 0x00442060
// Name: public: class TaoCrypt::Integer TaoCrypt::Integer::InverseMod(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
struct TaoCrypt::Integer __thiscall TaoCrypt::Integer::InverseMod(
        TaoCrypt::Integer *this,
        TaoCrypt::Integer *a2,
        CInternalFileSystemPassThru<IFileSystem> *t)
{
  char v4; // bl
  const CSplitScreenAddedConVar *v5; // ecx
  CInternalFileSystemPassThru<IFileSystem> *v6; // eax
  const CSplitScreenAddedConVar *v7; // ecx
  const CFunctorData *v8; // eax
  const CSplitScreenAddedConVar *v10; // ecx
  const struct TaoCrypt::Integer *v11; // eax
  const CFunctorData *v12; // eax
  const unsigned int *m_stackLevel; // edx
  unsigned __int8 *v14; // ebx
  unsigned __int8 *v15; // edi
  char *v16; // [esp-10h] [ebp-80h]
  CInternalFileSystemPassThru<IFileSystem> v17; // [esp+10h] [ebp-60h] BYREF
  TaoCrypt::Integer v18; // [esp+20h] [ebp-50h] BYREF
  unsigned __int8 *v19; // [esp+24h] [ebp-4Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v20; // [esp+28h] [ebp-48h] BYREF
  unsigned __int8 *v21; // [esp+34h] [ebp-3Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v22; // [esp+38h] [ebp-38h] BYREF
  unsigned __int8 *v23; // [esp+44h] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v24; // [esp+48h] [ebp-28h] BYREF
  unsigned __int8 *v25; // [esp+54h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v26; // [esp+58h] [ebp-18h] BYREF
  unsigned __int8 *v27; // [esp+64h] [ebp-Ch]
  __int64 v28; // [esp+68h] [ebp-8h] BYREF

  v4 = 0;
  if ( *((_DWORD *)this + 3) == 1
    || TaoCrypt::Integer::Compare((CInternalFileSystemPassThru<IFileSystem> *)this, t) >= 0 )
  {
    TaoCrypt::Integer::Modulo(this, quotient: (TaoCrypt::Integer *)&v26.m_iRefs, a3: t);
    TaoCrypt::Integer::InverseMod(this: (TaoCrypt::Integer *)&v26.m_iRefs, a2);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v28,
      p: v27,
      n: v26.m_iRefs);
    return (struct TaoCrypt::Integer)a2;
  }
  else if ( TaoCrypt::Integer::GetBit(this: (TaoCrypt::Integer *)t, a2: 0) )
  {
    TaoCrypt::Block<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>::Block<unsigned int,TaoCrypt::AlignedAllocator<unsigned int>>(
      this: (CRefCountServiceBase<1,CRefMT> *)&v17,
      s: (CRefCountServiceBase<1,CRefMT>_vtbl *)(4 * (int)t->IFileSystem::IAppSystem::__vftable));
    TaoCrypt::Integer::Integer(
      this: (TaoCrypt::Integer *)&v26.m_iRefs,
      a2: 0,
      a3: (unsigned int)t->IFileSystem::IAppSystem::__vftable);
    m_stackLevel = (const unsigned int *)this->m_stackLevel;
    v14 = (unsigned __int8 *)v17.IFileSystem::IBaseFileSystem::__vftable;
    v16 = *((char **)this + 1);
    v15 = v27;
    TaoCrypt::AlmostInverse(
      this: (TaoCrypt *)v27,
      bcLen: (unsigned int *)v17.IFileSystem::IBaseFileSystem::__vftable,
      a3: v16,
      NA: m_stackLevel,
      a5: (unsigned int)t->IFileSystem::IBaseFileSystem::__vftable,
      N: (unsigned int)t->IFileSystem::IAppSystem::__vftable);
    TaoCrypt::DivideByPower2Mod(R: (const CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)t->IFileSystem::IAppSystem::__vftable);
    TaoCrypt::Integer::Integer(this: a2, a2: (const struct TaoCrypt::Integer *)&v26.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v28,
      p: v15,
      n: v26.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v17.m_pBaseFileSystemPassThru,
      p: v14,
      n: (unsigned int)v17.IFileSystem::IAppSystem::__vftable);
    return (struct TaoCrypt::Integer)a2;
  }
  else if ( TaoCrypt::Integer::operator!(this: t) || !TaoCrypt::Integer::GetBit(this, a2: 0) )
  {
    v12 = TaoCrypt::Integer::Zero(this: v5);
    TaoCrypt::Integer::Integer(this: a2, a2: (const struct TaoCrypt::Integer *)v12);
    return (struct TaoCrypt::Integer)a2;
  }
  else
  {
    v6 = (CInternalFileSystemPassThru<IFileSystem> *)TaoCrypt::Integer::One(this: v5);
    if ( TaoCrypt::Integer::Compare((CInternalFileSystemPassThru<IFileSystem> *)this, t: v6) != 0 )
    {
      TaoCrypt::Integer::InverseMod(this: (TaoCrypt::Integer *)t, a2: (TaoCrypt::Integer *)&v17);
      if ( TaoCrypt::Integer::operator!(this: &v17) )
      {
        v11 = (const struct TaoCrypt::Integer *)TaoCrypt::Integer::Zero(this: v10);
      }
      else
      {
        TaoCrypt::Integer::Integer(this: (CUtlSymbolTable::CStringPoolIndex *)&v26.m_iRefs, value: 1);
        v4 = 31;
        TaoCrypt::Integer::Minus(this, a2: (TaoCrypt::Integer *)&v24.m_iRefs, a3: (struct TaoCrypt::Integer *)&v17);
        TaoCrypt::Integer::Times(
          this: (TaoCrypt::Integer *)t,
          a2: (TaoCrypt::Integer *)&v22.m_iRefs,
          a3: (struct TaoCrypt::Integer *)&v24.m_iRefs);
        TaoCrypt::Integer::Plus(
          this: (TaoCrypt::Integer *)&v22.m_iRefs,
          a2: (TaoCrypt::Integer *)&v20.m_iRefs,
          a3: (struct TaoCrypt::Integer *)&v26.m_iRefs);
        TaoCrypt::Integer::DividedBy(
          this: (TaoCrypt::Integer *)&v20.m_iRefs,
          a2: &v18,
          a3: (CInternalFileSystemPassThru<IFileSystem> *)this);
        v11 = &v18;
      }
      TaoCrypt::Integer::Integer(this: a2, a2: v11);
      if ( (v4 & 0x10) != 0 )
      {
        v4 &= ~0x10u;
        TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v20, p: v19, n: v18.m_stackLevel);
      }
      if ( (v4 & 8) != 0 )
      {
        v4 &= ~8u;
        TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v22, p: v21, n: v20.m_iRefs);
      }
      if ( (v4 & 4) != 0 )
      {
        v4 &= ~4u;
        TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v24, p: v23, n: v22.m_iRefs);
      }
      if ( (v4 & 2) != 0 )
      {
        v4 &= ~2u;
        TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v26, p: v25, n: v24.m_iRefs);
      }
      if ( (v4 & 1) != 0 )
        TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
          this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v28,
          p: v27,
          n: v26.m_iRefs);
      TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
        this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v17.m_pBaseFileSystemPassThru,
        p: (unsigned __int8 *)v17.IFileSystem::IBaseFileSystem::__vftable,
        n: (unsigned int)v17.IFileSystem::IAppSystem::__vftable);
      return (struct TaoCrypt::Integer)a2;
    }
    else
    {
      v8 = TaoCrypt::Integer::One(this: v7);
      TaoCrypt::Integer::Integer(this: a2, a2: (const struct TaoCrypt::Integer *)v8);
      return (struct TaoCrypt::Integer)a2;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004422F0
// Name: public: virtual class TaoCrypt::Integer TaoCrypt::ModularArithmetic::CascadeExponentiate(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__thiscall TaoCrypt::ModularArithmetic::CascadeExponentiate(
        IFileSystem *this,
        TaoCrypt::Integer *x,
        struct TaoCrypt::Integer *e1,
        const char *y,
        struct TaoCrypt::Integer *a5,
        int a6)
{
  const FileAsyncRequest_t *v7; // esi
  int v9; // [esp+0h] [ebp-90h]
  FSAsyncControl_t__ **v10; // [esp+4h] [ebp-8Ch]
  int v11[2]; // [esp+8h] [ebp-88h] BYREF
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v12; // [esp+10h] [ebp-80h] BYREF
  unsigned __int8 *v13; // [esp+1Ch] [ebp-74h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v14; // [esp+20h] [ebp-70h] BYREF
  unsigned __int8 *v15; // [esp+2Ch] [ebp-64h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v16; // [esp+30h] [ebp-60h] BYREF

  v7 = (const FileAsyncRequest_t *)((char *)this + 12);
  if ( TaoCrypt::Integer::GetBit(this: (TaoCrypt::Integer *)this + 3, a2: 0) )
  {
    TaoCrypt::MontgomeryRepresentation::MontgomeryRepresentation(
      this: (IFileSystem *)&v16.m_iRefs,
      m: v7,
      a3: v9,
      a4: v10);
    TaoCrypt::MontgomeryRepresentation::ConvertIn(
      this: (IFileSystem *)&v16.m_iRefs,
      quotient: (TaoCrypt::Integer *)&v14.m_iRefs,
      a3: a5);
    TaoCrypt::MontgomeryRepresentation::ConvertIn(
      this: (IFileSystem *)&v16.m_iRefs,
      quotient: (TaoCrypt::Integer *)&v12.m_iRefs,
      a3: e1);
    TaoCrypt::AbstractRing::CascadeExponentiate(this: (CUtlVector<int,CUtlMemory<int,int> > *)&v16.m_iRefs, x: (int)v11);
    TaoCrypt::MontgomeryRepresentation::ConvertOut(this: (IFileSystem *)&v16.m_iRefs, a2: x, a3: v11);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v12, p: (unsigned __int8 *)v11[1], n: v11[0]);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v14, p: v13, n: v12.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v16, p: v15, n: v14.m_iRefs);
    TaoCrypt::MontgomeryRepresentation::~MontgomeryRepresentation(this: (IFileSystem *)&v16.m_iRefs);
  }
  else
  {
    TaoCrypt::AbstractRing::CascadeExponentiate((CUtlVector<int,CUtlMemory<int,int> > *)this, (int)x);
  }
  return x;
}

//------------------------------------------------------------------------------
// Address: 0x00442410
// Name: public: virtual void TaoCrypt::ModularArithmetic::SimultaneousExponentiate(class TaoCrypt::Integer __near *,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ModularArithmetic::SimultaneousExponentiate(
        IFileSystem *this,
        CUtlVector<int,CUtlMemory<int,int> > *results,
        struct TaoCrypt::Integer *base,
        const struct TaoCrypt::Integer *exponents,
        unsigned int exponentsCount)
{
  const FileAsyncRequest_t *v6; // esi
  TaoCrypt::Integer *v7; // eax
  unsigned int v8; // edi
  int *v9; // esi
  char *v10; // eax
  int v11; // [esp+0h] [ebp-70h]
  const char *v12; // [esp+0h] [ebp-70h]
  FSAsyncControl_t__ **v13; // [esp+4h] [ebp-6Ch]
  TaoCrypt::Integer v14; // [esp+8h] [ebp-68h] BYREF
  unsigned __int8 *v15; // [esp+Ch] [ebp-64h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v16; // [esp+10h] [ebp-60h] BYREF
  unsigned int v17; // [esp+24h] [ebp-4Ch]
  unsigned __int8 *v18; // [esp+28h] [ebp-48h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v19; // [esp+2Ch] [ebp-44h] BYREF
  unsigned __int8 *v20; // [esp+38h] [ebp-38h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v21; // [esp+3Ch] [ebp-34h] BYREF
  unsigned __int8 *v22; // [esp+48h] [ebp-28h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v23; // [esp+4Ch] [ebp-24h] BYREF
  unsigned __int8 *v24; // [esp+58h] [ebp-18h]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v25; // [esp+5Ch] [ebp-14h] BYREF
  unsigned __int8 *v26; // [esp+68h] [ebp-8h]
  char v27; // [esp+6Ch] [ebp-4h] BYREF

  v6 = (const FileAsyncRequest_t *)((char *)this + 12);
  if ( TaoCrypt::Integer::GetBit(this: (TaoCrypt::Integer *)this + 3, a2: 0) )
  {
    TaoCrypt::MontgomeryRepresentation::MontgomeryRepresentation(
      this: (IFileSystem *)&v16.m_iRefs,
      m: v6,
      a3: v11,
      a4: v13);
    v7 = TaoCrypt::MontgomeryRepresentation::ConvertIn(this: (IFileSystem *)&v16.m_iRefs, quotient: &v14, a3: base);
    v8 = exponentsCount;
    v9 = (int *)results;
    TaoCrypt::AbstractRing::SimultaneousExponentiate(
      this: (TaoCrypt::AbstractRing *)&v16.m_iRefs,
      result: results,
      a3: v7,
      a4: exponents,
      a5: exponentsCount);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v16, p: v15, n: v14.m_stackLevel);
    if ( exponentsCount != 0 )
    {
      do
      {
        v10 = (char *)TaoCrypt::MontgomeryRepresentation::ConvertOut(
                        this: (IFileSystem *)&v16.m_iRefs,
                        a2: &v14,
                        a3: v9);
        TaoCrypt::Integer::operator=(this: (CInternalFileSystemPassThru<IFileSystem> *)v9, t: v10, a3: v12);
        TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v16, p: v15, n: v14.m_stackLevel);
        v9 += 4;
        --v8;
      }
      while ( v8 != 0 );
    }
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
      this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v27,
      p: v26,
      n: v25.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v25, p: v24, n: v23.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v23, p: v22, n: v21.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v21, p: v20, n: v19.m_iRefs);
    TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v19, p: v18, n: v17);
  }
  else
  {
    TaoCrypt::AbstractRing::SimultaneousExponentiate(
      (TaoCrypt::AbstractRing *)this,
      result: results,
      a3: base,
      a4: exponents,
      a5: exponentsCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00442540
// Name: class TaoCrypt::Integer TaoCrypt::CRT(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::Integer *__cdecl TaoCrypt::CRT(
        TaoCrypt::Integer *this,
        struct TaoCrypt::Integer *a2,
        TaoCrypt::Integer *a3,
        TaoCrypt::Integer *a4,
        CInternalFileSystemPassThru<IFileSystem> *a5,
        TaoCrypt::Integer *a6)
{
  TaoCrypt::Integer v7; // [esp+4h] [ebp-40h] BYREF
  unsigned __int8 *v8; // [esp+8h] [ebp-3Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v9; // [esp+Ch] [ebp-38h] BYREF
  unsigned __int8 *v10; // [esp+18h] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v11; // [esp+1Ch] [ebp-28h] BYREF
  unsigned __int8 *v12; // [esp+28h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v13; // [esp+2Ch] [ebp-18h] BYREF
  unsigned __int8 *v14; // [esp+38h] [ebp-Ch]
  __int64 v15; // [esp+3Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Minus(this: a4, a2: (TaoCrypt::Integer *)&v13.m_iRefs, a3: a2);
  TaoCrypt::Integer::Times(
    this: a6,
    a2: (TaoCrypt::Integer *)&v11.m_iRefs,
    a3: (struct TaoCrypt::Integer *)&v13.m_iRefs);
  TaoCrypt::Integer::Modulo(this: (TaoCrypt::Integer *)&v11.m_iRefs, quotient: (TaoCrypt::Integer *)&v9.m_iRefs, a3: a5);
  TaoCrypt::Integer::Times(this: a3, a2: &v7, a3: (struct TaoCrypt::Integer *)&v9.m_iRefs);
  TaoCrypt::Integer::Plus(this: &v7, a2: this, a3: a2);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v9, p: v8, n: v7.m_stackLevel);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v11, p: v10, n: v9.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v13, p: v12, n: v11.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v15,
    p: v14,
    n: v13.m_iRefs);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00442600
// Name: public: virtual bool TaoCrypt::ModularArithmetic::IsUnit(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::ModularArithmetic::IsUnit(IFileSystem *this@<ecx>, const char *a, const char *a3)
{
  CInternalFileSystemPassThru<IFileSystem> *v3; // eax
  int v4[2]; // [esp+4h] [ebp-10h] BYREF
  __int64 v5; // [esp+Ch] [ebp-8h] BYREF

  TaoCrypt::Integer::Gcd(a: v4, a2: (TaoCrypt::Integer *)v4, a3: (int)a, a4: (int)this + 12);
  TaoCrypt::Integer::IsUnit(this: v3);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v5,
    p: (unsigned __int8 *)v4[1],
    n: v4[0]);
}

//------------------------------------------------------------------------------
// Address: 0x00442640
// Name: public: virtual class TaoCrypt::Integer const __near & TaoCrypt::ModularArithmetic::MultiplicativeInverse(class TaoCrypt::Integer const __near &)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ModularArithmetic::MultiplicativeInverse(IFileSystem *this, TaoCrypt::Integer *a)
{
  struct TaoCrypt::Integer v3; // eax
  const char *v4; // [esp+0h] [ebp-14h]
  TaoCrypt::Integer v5; // [esp+4h] [ebp-10h] BYREF
  unsigned __int8 *v6; // [esp+8h] [ebp-Ch]
  __int64 v7; // [esp+Ch] [ebp-8h] BYREF

  v3.m_stackLevel = TaoCrypt::Integer::InverseMod(
                      this: a,
                      a2: &v5,
                      t: (CInternalFileSystemPassThru<IFileSystem> *)this + 1).m_stackLevel;
  TaoCrypt::Integer::operator=(
    this: (CInternalFileSystemPassThru<IFileSystem> *)((char *)this + 44),
    t: (char *)v3.m_stackLevel,
    a3: v4);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v7,
    p: v6,
    n: v5.m_stackLevel);
}

//------------------------------------------------------------------------------
// Address: 0x00442680
// Name: class TaoCrypt::Integer TaoCrypt::ModularRoot(class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &,class TaoCrypt::Integer const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::ModularRoot(
        FileWarningLevel_t a,
        TaoCrypt::Integer *a2,
        TaoCrypt::Integer *a3,
        int a4,
        int a5,
        CInternalFileSystemPassThru<IFileSystem> *a6,
        CInternalFileSystemPassThru<IFileSystem> *a7,
        TaoCrypt::Integer *a8)
{
  TaoCrypt::Integer quotient; // [esp+Ch] [ebp-30h] BYREF
  unsigned __int8 *v9; // [esp+10h] [ebp-2Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v10; // [esp+14h] [ebp-28h] BYREF
  unsigned __int8 *v11; // [esp+20h] [ebp-1Ch]
  CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > v12; // [esp+24h] [ebp-18h] BYREF
  unsigned __int8 *v13; // [esp+30h] [ebp-Ch]
  __int64 v14; // [esp+34h] [ebp-8h] BYREF

  TaoCrypt::Integer::Modulo(this: a3, &quotient, a3: a6);
  TaoCrypt::a_exp_b_mod_c(
    result: (CFunctorData *)&v12.m_iRefs,
    exponent: &quotient.m_stackLevel,
    a3: a4,
    a4: (struct TaoCrypt::Integer *)a6);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v10, p: v9, n: quotient.m_stackLevel);
  TaoCrypt::Integer::Modulo(this: a3, &quotient, a3: a7);
  TaoCrypt::a_exp_b_mod_c(
    result: (CFunctorData *)&v10.m_iRefs,
    exponent: &quotient.m_stackLevel,
    a3: a5,
    a4: (struct TaoCrypt::Integer *)a7);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v10, p: v9, n: quotient.m_stackLevel);
  TaoCrypt::CRT(
    this: a2,
    a2: (struct TaoCrypt::Integer *)&v12.m_iRefs,
    a3: (TaoCrypt::Integer *)a6,
    a4: (TaoCrypt::Integer *)&v10.m_iRefs,
    a5: a7,
    a6: a8);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(this: &v12, p: v11, n: v10.m_iRefs);
  TaoCrypt::AlignedAllocator<unsigned int>::deallocate(
    this: (CRefCounted1<CFunctorCallback,CRefCountServiceBase<1,CRefMT> > *)&v14,
    p: v13,
    n: v12.m_iRefs);
}
