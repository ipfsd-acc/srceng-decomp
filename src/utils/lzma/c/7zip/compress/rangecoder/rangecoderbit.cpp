// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/lzma/c/7zip/compress/rangecoder/rangecoderbit.cpp
// Functions: 1
// ============================================================

#include "utils\lzma\c\7zip\compress\rangecoder\rangecoderbit.h"

//------------------------------------------------------------------------------
// Address: 0x1001E180
// Name: public: static void NCompress::NRangeCoder::CPriceTables::Init(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl NCompress::NRangeCoder::CPriceTables::Init()
{
  int v0; // esi
  int v1; // edi
  unsigned int v2; // edx
  unsigned int v3; // eax
  char v4; // cl
  int v5; // esi
  unsigned int v6; // edi
  int v7; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v0 = 8;
  v1 = 0;
  i = 8;
  v7 = 0;
  do
  {
    v2 = 1 << (v1 + 1);
    v3 = 1 << v1;
    if ( 1 << v1 < v2 )
    {
      v4 = 8 - v0;
      v5 = v0 << 6;
      do
      {
        v6 = (v2 - v3++) << 6 >> v4;
        dword_13F64CEC[v3] = v5 + v6;
      }
      while ( v3 < v2 );
      v0 = i;
      v1 = v7;
    }
    ++v1;
    i = --v0;
    v7 = v1;
  }
  while ( v1 <= 8 );
}

// ============================================================
// Overlay from hlfaceposer (Missing functions)
// ============================================================
namespace hlfaceposer {

//------------------------------------------------------------------------------
// Address: 0x004BCCF0
// Name: public: static void NCompress::NRangeCoder::CPriceTables::Init(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl NCompress::NRangeCoder::CPriceTables::Init()
{
  int v0; // esi
  int v1; // edi
  unsigned int v2; // edx
  unsigned int v3; // eax
  char v4; // cl
  int v5; // esi
  unsigned int v6; // edi
  int v7; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v0 = 8;
  v1 = 0;
  i = 8;
  v7 = 0;
  do
  {
    v2 = 1 << (v1 + 1);
    v3 = 1 << v1;
    if ( 1 << v1 < v2 )
    {
      v4 = 8 - v0;
      v5 = v0 << 6;
      do
      {
        v6 = (v2 - v3++) << 6 >> v4;
        dword_72709C[v3] = v5 + v6;
      }
      while ( v3 < v2 );
      v0 = i;
      v1 = v7;
    }
    ++v1;
    i = --v0;
    v7 = v1;
  }
  while ( v1 <= 8 );
}

} // namespace hlfaceposer

// ============================================================
// Overlay from makegamedata (Missing functions)
// ============================================================
namespace makegamedata {

//------------------------------------------------------------------------------
// Address: 0x00526860
// Name: public: static void NCompress::NRangeCoder::CPriceTables::Init(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl NCompress::NRangeCoder::CPriceTables::Init()
{
  int v0; // esi
  int v1; // edi
  unsigned int v2; // edx
  unsigned int v3; // eax
  char v4; // cl
  int v5; // esi
  unsigned int v6; // edi
  int v7; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v0 = 8;
  v1 = 0;
  i = 8;
  v7 = 0;
  do
  {
    v2 = 1 << (v1 + 1);
    v3 = 1 << v1;
    if ( 1 << v1 < v2 )
    {
      v4 = 8 - v0;
      v5 = v0 << 6;
      do
      {
        v6 = (v2 - v3++) << 6 >> v4;
        dword_691AB4[v3] = v5 + v6;
      }
      while ( v3 < v2 );
      v0 = i;
      v1 = v7;
    }
    ++v1;
    i = --v0;
    v7 = v1;
  }
  while ( v1 <= 8 );
}

} // namespace makegamedata

// ============================================================
// Overlay from shadercompile_dll (Missing functions)
// ============================================================
namespace shadercompile_dll {

//------------------------------------------------------------------------------
// Address: 0x10017D80
// Name: public: static void NCompress::NRangeCoder::CPriceTables::Init(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl NCompress::NRangeCoder::CPriceTables::Init()
{
  int v0; // esi
  int v1; // edi
  unsigned int v2; // edx
  unsigned int v3; // eax
  char v4; // cl
  int v5; // esi
  unsigned int v6; // edi
  int v7; // [esp+8h] [ebp-8h]
  int i; // [esp+Ch] [ebp-4h]

  v0 = 8;
  v1 = 0;
  i = 8;
  v7 = 0;
  do
  {
    v2 = 1 << (v1 + 1);
    v3 = 1 << v1;
    if ( 1 << v1 < v2 )
    {
      v4 = 8 - v0;
      v5 = v0 << 6;
      do
      {
        v6 = (v2 - v3++) << 6 >> v4;
        dword_1016D70C[v3] = v5 + v6;
      }
      while ( v3 < v2 );
      v0 = i;
      v1 = v7;
    }
    ++v1;
    i = --v0;
    v7 = v1;
  }
  while ( v1 <= 8 );
}

} // namespace shadercompile_dll
