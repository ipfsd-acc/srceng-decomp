// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: materialsystem/colorspace.cpp
// Functions: 2
// ============================================================

#include "materialsystem\colorspace.h"

//------------------------------------------------------------------------------
// Address: 0x10049440
// Name: void ColorSpace::SetGamma(float,float,float,bool,bool)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x100496B0
// Name: unsigned short ColorSpace::LinearFloatToCorrectedShort(float)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ColorSpace::LinearFloatToCorrectedShort(float in)
{
  double v1; // xmm0_8
  float v2; // xmm0_4
  int result; // eax

  v1 = in * 4096.0;
  if ( v1 >= 65535.0 )
    v1 = 65535.0;
  v2 = v1;
  result = (int)v2;
  if ( v2 <= 0.0 )
    return (int)0.0;
  return result;
}
