// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/ivp_utility/ivu_os_dep.cxx
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1007B640
// Name: float ivp_rand(void)
// Source: json
//------------------------------------------------------------------------------
double __cdecl ivp_rand()
{
  IVP_RAND_SEED *= 75;
  return (double)(unsigned __int16)IVP_RAND_SEED * 0.000015258789;
}

//------------------------------------------------------------------------------
// Address: 0x1007B670
// Name: void ivp_srand(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ivp_srand(int seed)
{
  int v1; // eax

  v1 = seed;
  if ( seed == 0 )
    v1 = 1;
  IVP_RAND_SEED = v1;
}
