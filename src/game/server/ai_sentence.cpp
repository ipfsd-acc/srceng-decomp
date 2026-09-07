// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_sentence.cpp
// Functions: 2
// ============================================================

#include "game\server\ai_sentence.h"

//------------------------------------------------------------------------------
// Address: 0x103FED20
// Name: CAI_SentenceBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_SentenceBase_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_SentenceBase>();
  CAI_SentenceBase_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FED30
// Name: _dynamic_initializer_for__ai_debug_speech__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_speech__()
{
  ConVar::ConVar(this: &ai_debug_speech, pName: "ai_debug_speech", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_speech__);
}
