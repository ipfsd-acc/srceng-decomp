// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/h_export.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x1015C1A0
// Name: DllMain(x,x,x)
// Source: json
//------------------------------------------------------------------------------
BOOL __stdcall DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
  BOOL result; // eax

  result = true;
  if ( fdwReason == 1 )
    win32DLLHandle = hinstDLL;
  return result;
}
