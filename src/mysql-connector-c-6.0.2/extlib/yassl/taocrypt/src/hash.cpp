// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/hash.cpp
// Functions: 5
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\hash.h"

//------------------------------------------------------------------------------
// Address: 0x00427C60
// Name: void TaoCrypt::ByteReverse<unsigned int>(unsigned int __near *,unsigned int const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl TaoCrypt::ByteReverse<unsigned int>(unsigned int *out, int a2, unsigned int byteCount)
{
  unsigned int v3; // esi
  unsigned int *v4; // ecx
  int v5; // edx
  int result; // eax

  v3 = byteCount >> 2;
  if ( byteCount >> 2 != 0 )
  {
    v4 = out;
    v5 = a2 - (_DWORD)out;
    do
    {
      result = __ROL4__(*(unsigned int *)((char *)v4 + v5), 8) & 0xFF00FF;
      *v4 = result | __ROR4__(*(unsigned int *)((char *)v4 + v5), 8) & 0xFF00FF00;
      ++v4;
      --v3;
    }
    while ( v3 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00427CA0
// Name: public: TaoCrypt::HASHwithTransform::HASHwithTransform(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *__thiscall TaoCrypt::HASHwithTransform::HASHwithTransform(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this,
        unsigned int digSz,
        unsigned int buffSz)
{
  this->m_pMemory = (void (__cdecl **)(IConVar *, const char *, float))&TaoCrypt::HASHwithTransform::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00427CB0
// Name: protected: void TaoCrypt::HASHwithTransform::AddLength(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::HASHwithTransform::AddLength(TaoCrypt::HASHwithTransform *this, unsigned int a2)
{
  unsigned int v2; // eax

  v2 = *((_DWORD *)this + 2);
  *((_DWORD *)this + 2) = v2 + a2;
  if ( v2 + a2 < v2 )
    ++*((_DWORD *)this + 3);
}

//------------------------------------------------------------------------------
// Address: 0x00427CD0
// Name: public: virtual void TaoCrypt::HASHwithTransform::Update(unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::HASHwithTransform::Update(
        TaoCrypt::HASHwithTransform *this,
        unsigned __int8 *src,
        unsigned int a3)
{
  unsigned int v4; // ebp
  unsigned int v5; // ebx
  unsigned int v6; // edi

  v4 = a3;
  v5 = (*(int (__thiscall **)(TaoCrypt::HASHwithTransform *))(*this + 16))(a1: this);
  while ( v4 != 0 )
  {
    v6 = v5 - *((_DWORD *)this + 1);
    if ( v4 < v6 )
      v6 = v4;
    memcpy(dst: (unsigned __int8 *)this + *((_DWORD *)this + 1) + 48, src, count: v6);
    *((_DWORD *)this + 1) += v6;
    src += v6;
    v4 -= v6;
    if ( *((_DWORD *)this + 1) == v5 )
    {
      if ( (*(int (__thiscall **)(TaoCrypt::HASHwithTransform *))(*this + 24))(a1: this) != 0 )
        TaoCrypt::ByteReverse<unsigned int>(out: (unsigned int *)this + 12, a2: (int)(this + 12), byteCount: v5);
      (*(void (__thiscall **)(TaoCrypt::HASHwithTransform *))(*this + 32))(a1: this);
      TaoCrypt::HASHwithTransform::AddLength(this, a2: v5);
      *((_DWORD *)this + 1) = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00427D60
// Name: public: virtual void TaoCrypt::HASHwithTransform::Final(unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::HASHwithTransform::Final(
        CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *this@<ecx>,
        void (__cdecl **hash)(IConVar *, const char *, float),
        int preHiLen)
{
  unsigned int v4; // ebx
  int v5; // ebp
  unsigned int m_nGrowSize; // eax
  int v7; // edx
  CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *v8; // edi
  unsigned int m_nAllocationCount; // eax
  unsigned int *p_preHiLena; // eax
  unsigned int *p_preLoLen; // eax
  int blockSz; // [esp+10h] [ebp-10h]
  int digestSz; // [esp+14h] [ebp-Ch]
  unsigned int preLoLen; // [esp+18h] [ebp-8h] BYREF
  unsigned int preHiLena; // [esp+1Ch] [ebp-4h] BYREF

  blockSz = (*((int (__thiscall **)(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *))this->m_pMemory + 4))(a1: this);
  digestSz = (*((int (__thiscall **)(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *))this->m_pMemory + 5))(a1: this);
  v4 = (*((int (__thiscall **)(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *))this->m_pMemory + 7))(a1: this);
  v5 = (*((int (__thiscall **)(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *))this->m_pMemory + 6))(a1: this);
  TaoCrypt::HASHwithTransform::AddLength((TaoCrypt::HASHwithTransform *)this, a2: this->m_nAllocationCount);
  m_nGrowSize = this->m_nGrowSize;
  v7 = *((_DWORD *)this + 3);
  preLoLen = 8 * m_nGrowSize;
  v8 = this + 4;
  *((_BYTE *)this + this->m_nAllocationCount++ + 48) = 0x80;
  preHiLena = (m_nGrowSize >> 29) + 8 * v7;
  m_nAllocationCount = this->m_nAllocationCount;
  if ( m_nAllocationCount > v4 )
  {
    memset(dst: (unsigned __int8 *)v8 + m_nAllocationCount, value: 0, count: blockSz - m_nAllocationCount);
    this->m_nAllocationCount = blockSz;
    if ( v5 != 0 )
      TaoCrypt::ByteReverse<unsigned int>(out: (unsigned int *)this + 12, a2: (int)(this + 4), byteCount: blockSz);
    (*((void (__thiscall **)(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *))this->m_pMemory + 8))(a1: this);
    this->m_nAllocationCount = 0;
  }
  memset(dst: (unsigned __int8 *)v8 + this->m_nAllocationCount, value: 0, count: v4 - this->m_nAllocationCount);
  if ( v5 != 0 )
  {
    TaoCrypt::ByteReverse<unsigned int>(out: (unsigned int *)this + 12, a2: (int)(this + 4), byteCount: blockSz);
    p_preHiLena = &preHiLena;
  }
  else
  {
    p_preHiLena = &preLoLen;
  }
  *(void (__cdecl ***)(IConVar *, const char *, float))((char *)&v8->m_pMemory + v4) = (void (__cdecl **)(IConVar *, const char *, float))*p_preHiLena;
  p_preLoLen = &preLoLen;
  if ( v5 == 0 )
    p_preLoLen = &preHiLena;
  *(int *)((char *)&v8->m_nAllocationCount + v4) = *p_preLoLen;
  (*((void (__thiscall **)(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *))this->m_pMemory + 8))(a1: this);
  if ( v5 != 0 )
    TaoCrypt::ByteReverse<unsigned int>(out: (unsigned int *)this + 4, a2: (int)this + 16, byteCount: digestSz);
  memcpy(dst: (unsigned __int8 *)hash, src: (unsigned __int8 *)this + 16, count: digestSz);
  (*((void (__thiscall **)(CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> *))this->m_pMemory + 3))(a1: this);
}
