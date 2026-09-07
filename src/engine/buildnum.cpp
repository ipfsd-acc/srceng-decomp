// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/buildnum.cpp
// Functions: 2
// ============================================================

#include "engine\buildnum.h"

//------------------------------------------------------------------------------
// Address: 0x101495C0
// Name: private: void CBuildNumber::ComputeBuildNumber(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuildNumber::ComputeBuildNumber(CBuildNumber *this)
{
  int v1; // esi
  int v2; // edi
  int v3; // edx
  int v4; // ebx
  int v5; // eax
  int v6; // ecx

  v1 = 0;
  v2 = 0;
  do
  {
    if ( V_strncasecmp(s1: date, s2: mon[v2], n: 3) == 0 )
      break;
    v3 = mond[v2++];
    v1 += v3;
  }
  while ( v2 < 11 );
  v4 = v1 + atoi(nptr: date + 4) - 1;
  v5 = atoi(nptr: date + 7);
  v6 = v4 - (int)((double)(v5 - 1901) * -365.25);
  this->m_nBuildNumber = v6;
  if ( (v5 - 1900) % 4 == 0 && v2 > 1 )
    this->m_nBuildNumber = v6 + 1;
  this->m_nBuildNumber -= 35739;
}

//------------------------------------------------------------------------------
// Address: 0x10149670
// Name: int build_number(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl build_number()
{
  return g_BuildNumber.m_nBuildNumber;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10149720
// Name: private: void CBuildNumber::ComputeBuildNumber(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBuildNumber::ComputeBuildNumber(CBuildNumber *this)
{
  int v1; // esi
  int v2; // edi
  int v3; // edx
  int v4; // ebx
  int v5; // eax
  int v6; // ecx

  v1 = 0;
  v2 = 0;
  do
  {
    if ( V_strncasecmp(s1: date, s2: mon[v2], n: 3) == 0 )
      break;
    v3 = mond[v2++];
    v1 += v3;
  }
  while ( v2 < 11 );
  v4 = v1 + atoi(nptr: date + 4) - 1;
  v5 = atoi(nptr: date + 7);
  v6 = v4 - (int)((double)(v5 - 1901) * -365.25);
  this->m_nBuildNumber = v6;
  if ( (v5 - 1900) % 4 == 0 && v2 > 1 )
    this->m_nBuildNumber = v6 + 1;
  this->m_nBuildNumber -= 35739;
}

//------------------------------------------------------------------------------
// Address: 0x101497D0
// Name: int build_number(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl build_number()
{
  return g_BuildNumber.m_nBuildNumber;
}

} // namespace engine_xlsp
