// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/random.cpp
// Functions: 5
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\random.h"

//------------------------------------------------------------------------------
// Address: 0x0044AEE0
// Name: public: void TaoCrypt::RandomNumberGenerator::GenerateBlock(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge TaoCrypt::RandomNumberGenerator::GenerateBlock(
        TaoCrypt::RandomNumberGenerator *this@<ecx>,
        __int128 a2@<xmm0>,
        unsigned __int8 *output,
        unsigned int sz)
{
  memset(a1: a2, dst: (int)output, value: 0, count: sz);
  TaoCrypt::ARC4::Process(
    this: (TaoCrypt::ARC4 *)((char *)this + 8),
    x: output,
    in: (const LoggingContext_t *)output,
    a4: sz);
}

//------------------------------------------------------------------------------
// Address: 0x0044AF10
// Name: public: TaoCrypt::OS_Seed::OS_Seed(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlSymbolTable *__thiscall TaoCrypt::OS_Seed::OS_Seed(CUtlSymbolTable *this)
{
  bool v2; // zf
  const CUtlSymbolTable *v3; // eax

  this->m_Lookup.m_Elements.m_pMemory = nullptr;
  v2 = !CryptAcquireContextA(
          phProv: (HCRYPTPROV *)this,
          szContainer: nullptr,
          szProvider: nullptr,
          dwProvType: 1u,
          dwFlags: 0xF0000000);
  v3 = this;
  if ( v2 )
    this->m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)1001;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x0044AF40
// Name: public: TaoCrypt::OS_Seed::~OS_Seed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TaoCrypt::OS_Seed::~OS_Seed(TaoCrypt::OS_Seed *this)
{
  CryptReleaseContext(hProv: (HCRYPTPROV)*this, dwFlags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x0044AF50
// Name: public: void TaoCrypt::OS_Seed::GenerateSeed(unsigned char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall TaoCrypt::OS_Seed::GenerateSeed(CUtlSymbolTable *this, BYTE *output, DWORD sz)
{
  const char *result; // eax

  result = (const char *)CryptGenRandom(hProv: *(_DWORD *)&this->m_Lookup.m_LessFunc, dwLen: sz, pbBuffer: output);
  if ( result == nullptr )
    this->m_Lookup.m_Elements.m_pMemory = (UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short> *)1002;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0044AF80
// Name: public: TaoCrypt::RandomNumberGenerator::RandomNumberGenerator(void)
// Source: json
//------------------------------------------------------------------------------
TaoCrypt::RandomNumberGenerator *__usercall TaoCrypt::RandomNumberGenerator::RandomNumberGenerator@<eax>(TaoCrypt::RandomNumberGenerator *this@<ecx>, __int128 a2@<xmm0>)
{
  CUtlSymbol output; // [esp+4h] [ebp-124h] BYREF
  unsigned __int8 v5[256]; // [esp+24h] [ebp-104h] BYREF

  TaoCrypt::OS_Seed::OS_Seed((CUtlSymbolTable *)this);
  TaoCrypt::OS_Seed::GenerateSeed((CUtlSymbolTable *)this, (BYTE *)&output, sz: 0x20u);
  TaoCrypt::ARC4::SetKey(this: (TaoCrypt::ARC4 *)((char *)this + 8), a2: (const unsigned __int8 *)&output, a3: 0x20u);
  TaoCrypt::RandomNumberGenerator::GenerateBlock(this, a2, output: v5, sz: 0x100u);
  return this;
}
