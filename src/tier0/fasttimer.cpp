// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tier0/fasttimer.cpp
// Functions: 1
// ============================================================

#include "tier0\fasttimer.h"

//------------------------------------------------------------------------------
// Address: 0x10004CE0
// Name: public: static void CClockSpeedInit::Init(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CClockSpeedInit::Init()
{
  const CPUInformation *CPUInformation; // eax
  int m_Speed_high; // eax
  double v2; // st7
  ICpuTopology savedregs; // [esp+8h] [ebp+0h] BYREF

  CPUInformation = GetCPUInformation(a1: &savedregs);
  LODWORD(g_ClockSpeed) = CPUInformation->m_Speed;
  m_Speed_high = HIDWORD(CPUInformation->m_Speed);
  g_dwClockSpeed = g_ClockSpeed;
  dword_1003A814 = m_Speed_high;
  v2 = 1.0 / (double)__PAIR64__(m_Speed_high, g_ClockSpeed);
  g_ClockSpeedMicrosecondsMultiplier = 1000000.0 * v2;
  g_ClockSpeedMillisecondsMultiplier = 1000.0 * v2;
  g_ClockSpeedSecondsMultiplier = v2;
}
