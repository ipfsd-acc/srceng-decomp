// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/events.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10031B90
// Name: void SignalUpdate(int)
// Source: json
//------------------------------------------------------------------------------
// Decompile returned None

//------------------------------------------------------------------------------
// Address: 0x10031BC0
// Name: int GetUpdateCounter(int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetUpdateCounter(int ev)
{
  return g_EventTimeCounters[ev];
}
