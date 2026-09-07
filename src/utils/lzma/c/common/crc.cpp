// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lzma/c/common/crc.cpp
// Functions: 1
// ============================================================

#include "utils\lzma\c\common\crc.h"

//------------------------------------------------------------------------------
// Address: 0x1001E1F0
// Name: public: static void CCRC::InitTable(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCRC::InitTable()
{
  unsigned int i; // ecx
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax

  for ( i = 0; i < 0x100; ++i )
  {
    v1 = i >> 1;
    if ( (i & 1) != 0 )
      v1 ^= 0xEDB88320;
    if ( (v1 & 1) != 0 )
      v2 = (v1 >> 1) ^ 0xEDB88320;
    else
      v2 = v1 >> 1;
    if ( (v2 & 1) != 0 )
      v3 = (v2 >> 1) ^ 0xEDB88320;
    else
      v3 = v2 >> 1;
    if ( (v3 & 1) != 0 )
      v4 = (v3 >> 1) ^ 0xEDB88320;
    else
      v4 = v3 >> 1;
    if ( (v4 & 1) != 0 )
      v5 = (v4 >> 1) ^ 0xEDB88320;
    else
      v5 = v4 >> 1;
    if ( (v5 & 1) != 0 )
      v6 = (v5 >> 1) ^ 0xEDB88320;
    else
      v6 = v5 >> 1;
    if ( (v6 & 1) != 0 )
      v7 = (v6 >> 1) ^ 0xEDB88320;
    else
      v7 = v6 >> 1;
    if ( (v7 & 1) != 0 )
      v8 = (v7 >> 1) ^ 0xEDB88320;
    else
      v8 = v7 >> 1;
    CCRC::Table[i] = v8;
  }
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004BCD60
// Name: public: static void CCRC::InitTable(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCRC::InitTable()
{
  unsigned int i; // ecx
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax

  for ( i = 0; i < 0x100; ++i )
  {
    v1 = i >> 1;
    if ( (i & 1) != 0 )
      v1 ^= 0xEDB88320;
    if ( (v1 & 1) != 0 )
      v2 = (v1 >> 1) ^ 0xEDB88320;
    else
      v2 = v1 >> 1;
    if ( (v2 & 1) != 0 )
      v3 = (v2 >> 1) ^ 0xEDB88320;
    else
      v3 = v2 >> 1;
    if ( (v3 & 1) != 0 )
      v4 = (v3 >> 1) ^ 0xEDB88320;
    else
      v4 = v3 >> 1;
    if ( (v4 & 1) != 0 )
      v5 = (v4 >> 1) ^ 0xEDB88320;
    else
      v5 = v4 >> 1;
    if ( (v5 & 1) != 0 )
      v6 = (v5 >> 1) ^ 0xEDB88320;
    else
      v6 = v5 >> 1;
    if ( (v6 & 1) != 0 )
      v7 = (v6 >> 1) ^ 0xEDB88320;
    else
      v7 = v6 >> 1;
    if ( (v7 & 1) != 0 )
      v8 = (v7 >> 1) ^ 0xEDB88320;
    else
      v8 = v7 >> 1;
    CCRC::Table[i] = v8;
  }
}

} // namespace hlfaceposer

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x005268D0
// Name: public: static void CCRC::InitTable(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCRC::InitTable()
{
  unsigned int i; // ecx
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax

  for ( i = 0; i < 0x100; ++i )
  {
    v1 = i >> 1;
    if ( (i & 1) != 0 )
      v1 ^= 0xEDB88320;
    if ( (v1 & 1) != 0 )
      v2 = (v1 >> 1) ^ 0xEDB88320;
    else
      v2 = v1 >> 1;
    if ( (v2 & 1) != 0 )
      v3 = (v2 >> 1) ^ 0xEDB88320;
    else
      v3 = v2 >> 1;
    if ( (v3 & 1) != 0 )
      v4 = (v3 >> 1) ^ 0xEDB88320;
    else
      v4 = v3 >> 1;
    if ( (v4 & 1) != 0 )
      v5 = (v4 >> 1) ^ 0xEDB88320;
    else
      v5 = v4 >> 1;
    if ( (v5 & 1) != 0 )
      v6 = (v5 >> 1) ^ 0xEDB88320;
    else
      v6 = v5 >> 1;
    if ( (v6 & 1) != 0 )
      v7 = (v6 >> 1) ^ 0xEDB88320;
    else
      v7 = v6 >> 1;
    if ( (v7 & 1) != 0 )
      v8 = (v7 >> 1) ^ 0xEDB88320;
    else
      v8 = v7 >> 1;
    CCRC::Table[i] = v8;
  }
}

} // namespace makegamedata

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10017DF0
// Name: public: static void CCRC::InitTable(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CCRC::InitTable()
{
  unsigned int i; // ecx
  unsigned int v1; // eax
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // eax
  unsigned int v5; // eax
  unsigned int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax

  for ( i = 0; i < 0x100; ++i )
  {
    v1 = i >> 1;
    if ( (i & 1) != 0 )
      v1 ^= 0xEDB88320;
    if ( (v1 & 1) != 0 )
      v2 = (v1 >> 1) ^ 0xEDB88320;
    else
      v2 = v1 >> 1;
    if ( (v2 & 1) != 0 )
      v3 = (v2 >> 1) ^ 0xEDB88320;
    else
      v3 = v2 >> 1;
    if ( (v3 & 1) != 0 )
      v4 = (v3 >> 1) ^ 0xEDB88320;
    else
      v4 = v3 >> 1;
    if ( (v4 & 1) != 0 )
      v5 = (v4 >> 1) ^ 0xEDB88320;
    else
      v5 = v4 >> 1;
    if ( (v5 & 1) != 0 )
      v6 = (v5 >> 1) ^ 0xEDB88320;
    else
      v6 = v5 >> 1;
    if ( (v6 & 1) != 0 )
      v7 = (v6 >> 1) ^ 0xEDB88320;
    else
      v7 = v6 >> 1;
    if ( (v7 & 1) != 0 )
      v8 = (v7 >> 1) ^ 0xEDB88320;
    else
      v8 = v7 >> 1;
    CCRC::Table[i] = v8;
  }
}

} // namespace shadercompile_dll
