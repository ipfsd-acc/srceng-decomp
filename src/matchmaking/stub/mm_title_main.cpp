// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/stub/mm_title_main.cpp
// Functions: 2
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10001B50
// Name: enum InitReturnVal_t MM_Title_Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __cdecl MM_Title_Init()
{
  return g_pMatchTitle->Init(this: g_pMatchTitle);
}

//------------------------------------------------------------------------------
// Address: 0x10001B60
// Name: void MM_Title_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MM_Title_Shutdown()
{
  if ( g_pMatchTitle != nullptr )
    g_pMatchTitle->Shutdown(this: g_pMatchTitle);
}

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10002840
// Name: enum InitReturnVal_t MM_Title_Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __cdecl MM_Title_Init()
{
  return g_pMatchTitle->Init(this: g_pMatchTitle);
}

//------------------------------------------------------------------------------
// Address: 0x10002850
// Name: void MM_Title_Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MM_Title_Shutdown()
{
  if ( g_pMatchTitle != nullptr )
    g_pMatchTitle->Shutdown(this: g_pMatchTitle);
}

} // namespace matchmaking_ds
