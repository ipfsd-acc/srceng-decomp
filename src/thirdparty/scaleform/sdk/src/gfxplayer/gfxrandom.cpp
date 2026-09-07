// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gfxplayer/gfxrandom.cpp
// Functions: 9
// ============================================================

#include "thirdparty\scaleform\sdk\src\gfxplayer\gfxrandom.h"

//------------------------------------------------------------------------------
// Address: 0x10107E90
// Name: public: void GFxRandom::Generator::SeedRandom(unsigned long)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall GFxRandom::Generator::SeedRandom(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this,
        unsigned int seed)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  int v5; // eax
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  int v9; // eax
  unsigned int v10; // eax
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  unsigned int result; // eax

  v2 = (32 * (((seed ^ (seed << 13)) >> 17) ^ seed ^ (seed << 13)))
     ^ ((seed ^ (seed << 13)) >> 17)
     ^ seed
     ^ (seed << 13);
  this->m_Memory.m_pMemory = (CUtlString *)v2;
  v3 = (32 * ((((v2 << 13) ^ v2) >> 17) ^ (v2 << 13) ^ v2)) ^ (((v2 << 13) ^ v2) >> 17) ^ (v2 << 13) ^ v2;
  this->m_Memory.m_nAllocationCount = v3;
  v4 = (((v3 << 13) ^ v3) >> 17) ^ (v3 << 13) ^ v3;
  v5 = (32 * v4) ^ v4;
  this->m_Memory.m_nGrowSize = v5;
  v6 = (((v5 << 13) ^ (unsigned int)v5) >> 17) ^ (v5 << 13) ^ v5;
  v7 = (32 * v6) ^ v6;
  this->m_Size = v7;
  v8 = (((v7 << 13) ^ (unsigned int)v7) >> 17) ^ (v7 << 13) ^ v7;
  v9 = (32 * v8) ^ v8;
  this->m_pElements = (CUtlString *)v9;
  v10 = (((v9 << 13) ^ (unsigned int)v9) >> 17) ^ (v9 << 13) ^ v9;
  v11 = (32 * v10) ^ v10;
  *((_DWORD *)this + 5) = v11;
  v12 = (((v11 << 13) ^ (unsigned int)v11) >> 17) ^ (v11 << 13) ^ v11;
  v13 = (32 * v12) ^ v12;
  *((_DWORD *)this + 6) = v13;
  result = (((v13 << 13) ^ (unsigned int)v13) >> 17) ^ (v13 << 13) ^ v13;
  *((_DWORD *)this + 7) = result ^ (32 * result);
  *((_DWORD *)this + 8) = 362436;
  *((_DWORD *)this + 9) = 7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10107F70
// Name: public: unsigned long GFxRandom::Generator::NextRandom(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GFxRandom::Generator::NextRandom(CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  int v1; // esi
  __int64 v2; // rax
  int v3; // edi

  v1 = ((unsigned __int8)*((_DWORD *)this + 9) + 1) & 7;
  *((_DWORD *)this + 9) = v1;
  v2 = *((unsigned int *)this + 8) + 716514398LL * *((unsigned int *)&this->m_Memory.m_pMemory + v1);
  v3 = HIDWORD(v2) + v2;
  *((_DWORD *)this + 8) = HIDWORD(v2);
  if ( (unsigned int)(HIDWORD(v2) + v2) < HIDWORD(v2) )
  {
    ++v3;
    *((_DWORD *)this + 8) = HIDWORD(v2) + 1;
  }
  *((_DWORD *)&this->m_Memory.m_pMemory + v1) = -2 - v3;
  return -2 - v3;
}

//------------------------------------------------------------------------------
// Address: 0x10107FB0
// Name: public: static unsigned long GFxRandom::NextRandom(void)
// Source: json
//------------------------------------------------------------------------------
const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *GFxRandom::NextRandom()
{
  int v0; // ecx
  __int64 v1; // rax
  int v2; // esi

  v0 = ((_BYTE)dword_10330258 + 1) & 7;
  dword_10330258 = v0;
  v1 = (unsigned int)dword_10330254 + 716514398LL * *((unsigned int *)&Generator_1.m_Memory.m_pMemory + v0);
  v2 = HIDWORD(v1) + v1;
  dword_10330254 = HIDWORD(v1);
  if ( (unsigned int)(HIDWORD(v1) + v1) < HIDWORD(v1) )
  {
    ++v2;
    dword_10330254 = HIDWORD(v1) + 1;
  }
  *((_DWORD *)&Generator_1.m_Memory.m_pMemory + v0) = -2 - v2;
  return (const CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)(-2 - v2);
}

//------------------------------------------------------------------------------
// Address: 0x10108000
// Name: public: GFxRandom::Generator::Generator(void)
// Source: json
//------------------------------------------------------------------------------
CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *__thiscall GFxRandom::Generator::Generator(
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *this)
{
  unsigned int v2; // eax

  *((_DWORD *)this + 8) = 362436;
  *((_DWORD *)this + 9) = 7;
  GTimer::GetTicks(this);
  GFxRandom::Generator::SeedRandom(this, seed: v2);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1028BCC0
// Name: _dynamic_initializer_for__Generator_1__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
unsigned int __thiscall dynamic_initializer_for__Generator_1__(void *this)
{
  unsigned int v1; // eax

  GTimer::GetTicks(this);
  return GFxRandom::Generator::SeedRandom(this: &Generator_1, seed: v1);
}

//------------------------------------------------------------------------------
// Address: 0x1028BCE0
// Name: _dynamic_initializer_for__GFxPoint_DefaultParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxPoint_DefaultParams__()
{
  return atexit(func: dynamic_atexit_destructor_for__GFxPoint_DefaultParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BCF0
// Name: _dynamic_initializer_for__GFxPoint_NanParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxPoint_NanParams__()
{
  dbl_10359848 = GASNumberUtil::NaN();
  GFxPoint_NanParams = 3;
  dbl_10359858 = GASNumberUtil::NaN();
  byte_10359854 = 3;
  return atexit(func: dynamic_atexit_destructor_for__GFxPoint_NanParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BD20
// Name: _dynamic_initializer_for__GFxRectangle_DefaultParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxRectangle_DefaultParams__()
{
  return atexit(func: dynamic_atexit_destructor_for__GFxRectangle_DefaultParams__);
}

//------------------------------------------------------------------------------
// Address: 0x1028BD30
// Name: _dynamic_initializer_for__GFxRectangle_NaNParams__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__GFxRectangle_NaNParams__()
{
  *(double *)&GFxRectangle_NaNParams.GListNode<GMemoryHeap> = GASNumberUtil::NaN();
  LOBYTE(GFxRectangle_NaNParams.__vftable) = 3;
  *(double *)&GFxRectangle_NaNParams.OwnerThreadId = GASNumberUtil::NaN();
  LOBYTE(GFxRectangle_NaNParams.RefCount) = 3;
  *(double *)&GFxRectangle_NaNParams.Info.Desc.Granularity = GASNumberUtil::NaN();
  LOBYTE(GFxRectangle_NaNParams.Info.Desc.MinAlign) = 3;
  *(double *)&GFxRectangle_NaNParams.Info.Desc.HeapId = GASNumberUtil::NaN();
  LOBYTE(GFxRectangle_NaNParams.Info.Desc.Limit) = 3;
  return atexit(func: dynamic_atexit_destructor_for__GFxRectangle_NaNParams__);
}
