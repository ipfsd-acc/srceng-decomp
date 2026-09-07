// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/taocrypt/src/misc.cpp
// Functions: 8
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\taocrypt\src\misc.h"

//------------------------------------------------------------------------------
// Address: 0x0042F0C0
// Name: void TaoCrypt::xorbuf(unsigned char __near *,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TaoCrypt::xorbuf(TaoCrypt *this, unsigned __int8 *a2, const unsigned __int8 *a3)
{
  TaoCrypt *v3; // eax
  unsigned int j; // edx
  const unsigned __int8 *i; // esi

  v3 = this;
  if ( (((unsigned __int8)a3 | (unsigned __int8)((unsigned __int8)a2 | (unsigned __int8)this)) & 3) != 0 )
  {
    if ( a3 != nullptr )
    {
      for ( i = a3; i != nullptr; --i )
      {
        *(_BYTE *)v3 ^= *((_BYTE *)v3 + a2 - (unsigned __int8 *)this);
        v3 = (TaoCrypt *)((char *)v3 + 1);
      }
    }
  }
  else
  {
    for ( j = (unsigned int)a3 >> 2; j != 0; --j )
    {
      *(_DWORD *)v3 ^= *(_DWORD *)((char *)v3 + a2 - (unsigned __int8 *)this);
      v3 = (TaoCrypt *)((char *)v3 + 4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042F110
// Name: unsigned int TaoCrypt::BytePrecision(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TaoCrypt::BytePrecision(TaoCrypt *this)
{
  unsigned int result; // eax
  char v2; // cl

  result = 4;
  v2 = 24;
  do
  {
    if ( (unsigned int)this >> v2 != 0 )
      break;
    --result;
    v2 -= 8;
  }
  while ( result != 0 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F140
// Name: unsigned int TaoCrypt::BitPrecision(unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl TaoCrypt::BitPrecision(TaoCrypt *this)
{
  unsigned int result; // eax
  unsigned int v2; // edx

  if ( this == nullptr )
    return 0;
  v2 = 0;
  result = 32;
  do
  {
    if ( (unsigned int)this >> ((result + v2) >> 1) != 0 )
      v2 = (result + v2) >> 1;
    else
      result = (result + v2) >> 1;
  }
  while ( result - v2 > 1 );
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042F180
// Name: unsigned int TaoCrypt::Crop(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
IVirtualMemorySection *__thiscall TaoCrypt::Crop(
        const IVirtualMemorySection *value,
        unsigned int valuea,
        unsigned int size)
{
  if ( size >= 0x20 )
    return (IVirtualMemorySection *)valuea;
  else
    return (IVirtualMemorySection *)(valuea & ((1 << size) - 1));
}

//------------------------------------------------------------------------------
// Address: 0x0042F1A0
// Name: bool TaoCrypt::HaveCpuId(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl TaoCrypt::HaveCpuId()
{
  _EAX = 0;
  __asm { cpuid }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0042F220
// Name: void TaoCrypt::CpuId(unsigned int,unsigned int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TaoCrypt::CpuId(TaoCrypt *this, _DWORD *a2)
{
  _EAX = this;
  __asm { cpuid }
  *a2 = _EAX;
  a2[1] = _EBX;
  a2[2] = _ECX;
  a2[3] = _EDX;
}

//------------------------------------------------------------------------------
// Address: 0x0042F240
// Name: bool TaoCrypt::IsPentium(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl TaoCrypt::IsPentium()
{
  int v1; // eax
  unsigned int v2; // eax
  int i; // ecx
  unsigned int v4[2]; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+8h] [ebp-8h]
  int v6; // [esp+Ch] [ebp-4h]

  if ( TaoCrypt::HaveCpuId() != 0 )
  {
    TaoCrypt::CpuId(this: nullptr, a2: v4);
    v1 = v5;
    v5 = v6;
    v6 = v1;
    v2 = 12;
    for ( i = 0; v4[i + 1] == *(_DWORD *)((char *)&loc_47C677 + i * 4 + 1); ++i )
    {
      v2 -= 4;
      if ( v2 < 4 )
      {
        TaoCrypt::CpuId(this: (TaoCrypt *)1, a2: v4);
        return (BYTE1(v4[0]) & 0xFu) >= 5;
      }
    }
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x0042F2C0
// Name: TaoCrypt::IsMmx
// Source: json
//------------------------------------------------------------------------------
bool TaoCrypt::IsMmx()
{
  bool result; // al
  unsigned int v1[4]; // [esp+0h] [ebp-10h] BYREF

  result = TaoCrypt::IsPentium();
  if ( result )
  {
    TaoCrypt::CpuId(this: (TaoCrypt *)1, a2: v1);
    return (v1[3] & 0x800000) != 0;
  }
  return result;
}
