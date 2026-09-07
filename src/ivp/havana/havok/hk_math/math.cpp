// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: ivp/havana/havok/hk_math/math.cpp
// Functions: 1
// ============================================================

#include "ivp\havana\havok\hk_math\math.h"

//------------------------------------------------------------------------------
// Address: 0x100440B0
// Name: public: static void hk_Math::srand01(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl hk_Math::srand01(unsigned int seedVal)
{
  hk_Math::hk_random_seed = seedVal;
}
