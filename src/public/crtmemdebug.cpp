// Original: public/crtmemdebug.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "public\crtmemdebug.h"

// Stub: InitCRTMemDebug
void InitCRTMemDebug() {}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x103190F0
// Name: _dynamic_initializer_for__debug_map_crc__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_map_crc__()
{
  ConVar::ConVar(
    this: &debug_map_crc,
    pName: "debug_map_crc",
    pDefaultValue: "0",
    flags: 2,
    pHelpString: "Prints CRC for each map lump loaded");
  return atexit(func: dynamic_atexit_destructor_for__debug_map_crc__);
}

//------------------------------------------------------------------------------
// Address: 0x1031D570
// Name: _dynamic_initializer_for__debug_paint_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__debug_paint_alpha__()
{
  ConVar::ConVar(this: &debug_paint_alpha, pName: "debug_paint_alpha", pDefaultValue: "0", flags: 2);
  return atexit(func: dynamic_atexit_destructor_for__debug_paint_alpha__);
}

//------------------------------------------------------------------------------
// Address: 0x10324D10
// Name: _dynamic_atexit_destructor_for__debug_map_crc__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_map_crc__()
{
  ConVar::~ConVar(this: &debug_map_crc);
}

//------------------------------------------------------------------------------
// Address: 0x103267F0
// Name: _dynamic_atexit_destructor_for__debug_paint_alpha__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__debug_paint_alpha__()
{
  ConVar::~ConVar(this: &debug_paint_alpha);
}

//------------------------------------------------------------------------------
// Address: 0x1031D5A0
// Name: _dynamic_initializer_for__g_PaintManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_PaintManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_PaintManager__);
}

//------------------------------------------------------------------------------
// Address: 0x10326800
// Name: _dynamic_atexit_destructor_for__g_PaintManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_PaintManager__()
{
  g_PaintManager.__vftable = (CPaintmapDataManager_vtbl *)&CPaintmapDataManager::`vftable';
}

} // namespace engine_xlsp
