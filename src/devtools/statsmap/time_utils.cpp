// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: devtools/statsmap/time_utils.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00403DD0
// Name: bool System_GetCurrentTimeAndDate(int __near *,int __near *,int __near *,int __near *,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl System_GetCurrentTimeAndDate(
        int *year,
        int *month,
        int *dayOfWeek,
        int *day,
        int *hour,
        int *minute,
        int *second)
{
  tm curtime; // [esp+0h] [ebp-24h] BYREF

  _Plat_GetLocalTime(a1: &curtime);
  if ( year != nullptr )
    *year = curtime.tm_year;
  if ( month != nullptr )
    *month = curtime.tm_mon;
  if ( dayOfWeek != nullptr )
    *dayOfWeek = curtime.tm_wday;
  if ( day != nullptr )
    *day = curtime.tm_mday;
  if ( hour != nullptr )
    *hour = curtime.tm_hour;
  if ( minute != nullptr )
    *minute = curtime.tm_min;
  if ( second != nullptr )
    *second = curtime.tm_sec;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403E40
// Name: void SubtractDays(int,int __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SubtractDays(int iDaysToSubtract, int *year, int *month, int *day)
{
  int *v4; // edx
  int v5; // esi

  v4 = day;
  *day -= iDaysToSubtract;
  if ( *day <= 0 )
  {
    do
    {
      if ( --*month <= 0 )
      {
        --*year;
        *month += 12;
      }
      v5 = *((_DWORD *)&g_StatsConfig.m_Products.m_pElements + *month);
      if ( *month == 2 && *year % 4 == 0 || (v4 = day, *year % 100 == 0) )
        ++v5;
      *v4 += v5;
    }
    while ( *v4 <= 0 );
  }
}
