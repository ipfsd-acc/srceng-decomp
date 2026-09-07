// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mathlib/almostequal.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10263280
// Name: bool AlmostEqual(float,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AlmostEqual(float a, float b, int maxUlps)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx

  if ( fabs(a) == INFINITY || fabs(b) == INFINITY )
    return a == b;
  if ( (LODWORD(a) & 0x7F800000) == 0x7F800000 && (LODWORD(a) & 0x7FFFFF) != 0
    || (LODWORD(b) & 0x7F800000) == 0x7F800000 && (LODWORD(b) & 0x7FFFFF) != 0 )
  {
    return false;
  }
  if ( (LODWORD(a) ^ LODWORD(b)) < 0 )
    return a == b;
  v3 = LODWORD(a);
  if ( a < 0.0 )
    v3 = 0x80000000 - LODWORD(a);
  v4 = LODWORD(b);
  if ( b < 0.0 )
    v4 = 0x80000000 - LODWORD(b);
  return (int)abs32(v3 - v4) <= maxUlps;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x102632B0
// Name: bool AlmostEqual(float,float,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl AlmostEqual(float a, float b, int maxUlps)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx

  if ( fabs(a) == INFINITY || fabs(b) == INFINITY )
    return a == b;
  if ( (LODWORD(a) & 0x7F800000) == 0x7F800000 && (LODWORD(a) & 0x7FFFFF) != 0
    || (LODWORD(b) & 0x7F800000) == 0x7F800000 && (LODWORD(b) & 0x7FFFFF) != 0 )
  {
    return false;
  }
  if ( (LODWORD(a) ^ LODWORD(b)) < 0 )
    return a == b;
  v3 = LODWORD(a);
  if ( a < 0.0 )
    v3 = 0x80000000 - LODWORD(a);
  v4 = LODWORD(b);
  if ( b < 0.0 )
    v4 = 0x80000000 - LODWORD(b);
  return (int)abs32(v3 - v4) <= maxUlps;
}

} // namespace engine_xlsp
