// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/cs_gamestats_shared.cpp
// Functions: 1
// ============================================================

#include "game\shared\cstrike15\cs_gamestats_shared.h"

//------------------------------------------------------------------------------
// Address: 0x101C6AC0
// Name: public: void StatsCollection_t::Aggregate(struct StatsCollection_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall StatsCollection_t::Aggregate(StatsCollection_t *this, const StatsCollection_t *other)
{
  int v2; // edx
  int *v3; // eax

  v2 = 0;
  v3 = &this->m_iValue[1];
  do
  {
    *(v3 - 1) += other->m_iValue[v2];
    *v3 += *(int *)((char *)v3 + (char *)other - (char *)this);
    v2 += 2;
    v3 += 2;
  }
  while ( v2 < 262 );
}
