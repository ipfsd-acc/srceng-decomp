// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: thirdparty/scaleform/sdk/src/gkernel/gtimer.cpp
// Functions: 4
// ============================================================

#include "thirdparty\scaleform\sdk\src\gkernel\gtimer.h"

//------------------------------------------------------------------------------
// Address: 0x1008BC60
// Name: public: static unsigned __int64 GTimer::GetTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTimer::GetTicks(void *this)
{
  timeGetTime();
}

//------------------------------------------------------------------------------
// Address: 0x1008BC70
// Name: public: static unsigned __int64 GTimer::GetRawTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTimer::GetRawTicks(void *li)
{
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  QueryPerformanceCounter(lpPerformanceCount: &PerformanceCount);
}

//------------------------------------------------------------------------------
// Address: 0x1008BC90
// Name: public: static unsigned __int64 GTimer::GetRawFrequency(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTimer::GetRawFrequency(void *freq)
{
  LARGE_INTEGER Frequency; // [esp+0h] [ebp-8h] BYREF

  if ( perfFreq == 0 )
  {
    QueryPerformanceFrequency(lpFrequency: &Frequency);
    perfFreq = Frequency.QuadPart;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BCD0
// Name: public: static unsigned __int64 GTimer::GetProfileTicks(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GTimer::GetProfileTicks(void *this)
{
  LARGE_INTEGER Frequency; // [esp+14h] [ebp-10h] BYREF
  LARGE_INTEGER PerformanceCount; // [esp+1Ch] [ebp-8h] BYREF

  QueryPerformanceCounter(lpPerformanceCount: &PerformanceCount);
  if ( perfFreq == 0 )
  {
    QueryPerformanceFrequency(lpFrequency: &Frequency);
    perfFreq = Frequency.QuadPart;
  }
}
