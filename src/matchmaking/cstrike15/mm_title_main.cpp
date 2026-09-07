// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/cstrike15/mm_title_main.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10002880
// Name: enum InitReturnVal_t MM_Title_Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __cdecl MM_Title_Init()
{
  return g_pMatchTitle->Init(this: g_pMatchTitle);
}

//------------------------------------------------------------------------------
// Address: 0x10002890
// Name: void MM_Title_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MM_Title_Shutdown()
{
  if ( g_pMatchTitle != nullptr )
    g_pMatchTitle->Shutdown(this: g_pMatchTitle);
}
