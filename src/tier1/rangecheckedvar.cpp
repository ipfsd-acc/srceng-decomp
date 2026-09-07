// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier1/rangecheckedvar.cpp
// Functions: 2
// ============================================================

#include "tier1\rangecheckedvar.h"

//------------------------------------------------------------------------------
// Address: 0x10369450
// Name: public: CDisableRangeChecks::CDisableRangeChecks(void)
// Source: json
//------------------------------------------------------------------------------
CDisableRangeChecks *__thiscall CDisableRangeChecks::CDisableRangeChecks(CDisableRangeChecks *this)
{
  bool v2; // zf
  CDisableRangeChecks *result; // eax

  v2 = (unsigned __int8)_ThreadInMainThread(a1: this) == 0;
  result = this;
  if ( !v2 )
  {
    ++g_nDisables;
    g_bDoRangeChecks = false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10369470
// Name: public: CDisableRangeChecks::~CDisableRangeChecks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDisableRangeChecks::~CDisableRangeChecks(CDisableRangeChecks *this)
{
  if ( (unsigned __int8)_ThreadInMainThread(a1: this) != 0 && --g_nDisables == 0 )
    g_bDoRangeChecks = true;
}
