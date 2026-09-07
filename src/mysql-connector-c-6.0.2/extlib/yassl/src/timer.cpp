// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/extlib/yassl/src/timer.cpp
// Functions: 2
// ============================================================

#include "mysql-connector-c-6.0.2\extlib\yassl\src\timer.h"

//------------------------------------------------------------------------------
// Address: 0x0043BBB0
// Name: double yaSSL::timer(void)
// Source: json
//------------------------------------------------------------------------------
double yaSSL::timer()
{
  LARGE_INTEGER PerformanceCount; // [esp+0h] [ebp-8h] BYREF

  if ( !init )
  {
    QueryPerformanceFrequency(lpFrequency: &freq);
    init = true;
  }
  QueryPerformanceCounter(lpPerformanceCount: &PerformanceCount);
  return (double)PerformanceCount.QuadPart / (double)freq.QuadPart;
}

//------------------------------------------------------------------------------
// Address: 0x0043BBF0
// Name: unsigned int yaSSL::lowResTimer(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl yaSSL::lowResTimer()
{
  return (__int64)yaSSL::timer();
}
