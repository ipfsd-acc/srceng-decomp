// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/platform_independent.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1000AB10
// Name: _GetCurrentDayOfTheWeek
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetCurrentDayOfTheWeek(int *pDay)
{
  __int64 long_time; // [esp+0h] [ebp-8h] BYREF

  _time64(timeptr: &long_time);
  *pDay = _localtime64(ptime: &long_time)->tm_wday;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB40
// Name: _GetCurrentDayOfTheYear
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetCurrentDayOfTheYear(int *pDay)
{
  __int64 long_time; // [esp+0h] [ebp-8h] BYREF

  _time64(timeptr: &long_time);
  *pDay = _localtime64(ptime: &long_time)->tm_yday;
}
