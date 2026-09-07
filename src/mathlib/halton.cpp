// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/halton.cpp
// Functions: 2
// ============================================================

#include "mathlib\halton.h"

//------------------------------------------------------------------------------
// Address: 0x0042DBD0
// Name: public: HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(int)
// Source: json
//------------------------------------------------------------------------------
HaltonSequenceGenerator_t *__thiscall HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(
        HaltonSequenceGenerator_t *this,
        int b)
{
  this->base = b;
  this->fbase = (float)b;
  this->seed = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042DC00
// Name: public: float HaltonSequenceGenerator_t::GetElement(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall HaltonSequenceGenerator_t::GetElement(HaltonSequenceGenerator_t *this, int elem)
{
  float fbase; // xmm3_4
  int seed; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4
  int base; // ecx
  int v7; // et2
  float ret; // [esp+0h] [ebp-4h]

  fbase = this->fbase;
  seed = this->seed;
  v4 = 0.0;
  ret = 0.0;
  v5 = 1.0 / fbase;
  if ( this->seed != 0 )
  {
    base = this->base;
    do
    {
      v7 = seed % base;
      seed /= base;
      v4 = v4 + (float)((float)v7 * v5);
      ret = v4;
      v5 = v5 * (float)(1.0 / fbase);
    }
    while ( seed != 0 );
  }
  return ret;
}

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x10204FD0
// Name: public: HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(int)
// Source: json
//------------------------------------------------------------------------------
HaltonSequenceGenerator_t *__thiscall HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(
        HaltonSequenceGenerator_t *this,
        int b)
{
  this->base = b;
  this->fbase = (float)b;
  this->seed = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10205000
// Name: public: float HaltonSequenceGenerator_t::GetElement(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall HaltonSequenceGenerator_t::GetElement(HaltonSequenceGenerator_t *this, int elem)
{
  float fbase; // xmm3_4
  int seed; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4
  int base; // ecx
  int v7; // et2
  float ret; // [esp+0h] [ebp-4h]

  fbase = this->fbase;
  seed = this->seed;
  v4 = 0.0;
  ret = 0.0;
  v5 = 1.0 / fbase;
  if ( this->seed != 0 )
  {
    base = this->base;
    do
    {
      v7 = seed % base;
      seed /= base;
      v4 = v4 + (float)((float)v7 * v5);
      ret = v4;
      v5 = v5 * (float)(1.0 / fbase);
    }
    while ( seed != 0 );
  }
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x10205070
// Name: int InsideOut(int,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl InsideOut(int nTotal, int nCounter)
{
  int result; // eax
  int v3; // edx
  int i; // ecx

  result = 0;
  v3 = 1;
  for ( i = nTotal; v3 < nTotal; i >>= 1 )
  {
    if ( 2 * nCounter < i )
    {
      ++i;
    }
    else
    {
      result += v3;
      nCounter -= (i + 1) >> 1;
    }
    v3 *= 2;
  }
  return result;
}

} // namespace hammer_dll

// ============================================================
// Overlay from vrad_dll (Missing functions)
// ============================================================
namespace vrad_dll {

//------------------------------------------------------------------------------
// Address: 0x10078030
// Name: public: HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(int)
// Source: json
//------------------------------------------------------------------------------
HaltonSequenceGenerator_t *__thiscall HaltonSequenceGenerator_t::HaltonSequenceGenerator_t(
        HaltonSequenceGenerator_t *this,
        int b)
{
  this->base = b;
  this->fbase = (float)b;
  this->seed = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10078060
// Name: public: float HaltonSequenceGenerator_t::GetElement(int)
// Source: json
//------------------------------------------------------------------------------
double __thiscall HaltonSequenceGenerator_t::GetElement(HaltonSequenceGenerator_t *this, int elem)
{
  float fbase; // xmm3_4
  int seed; // eax
  float v4; // xmm1_4
  float v5; // xmm0_4
  int base; // ecx
  int v7; // et2
  float ret; // [esp+0h] [ebp-4h]

  fbase = this->fbase;
  seed = this->seed;
  v4 = 0.0;
  ret = 0.0;
  v5 = 1.0 / fbase;
  if ( this->seed != 0 )
  {
    base = this->base;
    do
    {
      v7 = seed % base;
      seed /= base;
      v4 = v4 + (float)((float)v7 * v5);
      ret = v4;
      v5 = v5 * (float)(1.0 / fbase);
    }
    while ( seed != 0 );
  }
  return ret;
}

} // namespace vrad_dll
