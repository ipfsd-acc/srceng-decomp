// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_criteria.cpp
// Functions: 3
// ============================================================

#include "game\server\ai_criteria.h"

//------------------------------------------------------------------------------
// Address: 0x103FBAE0
// Name: AI_ResponseParams_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_ResponseParams_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ResponseRules::ResponseParams>();
  AI_ResponseParams_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FBAF0
// Name: AI_Response_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_Response_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ResponseRules::CRR_Response>();
  AI_Response_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FBB00
// Name: _dynamic_initializer_for__g_AISystemHook__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AISystemHook__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_AISystemHook, name: "CAI_SystemHook");
  g_AISystemHook.__vftable = (CAI_SystemHook_vtbl *)&CAI_SystemHook::`vftable';
  return atexit(func: dynamic_atexit_destructor_for__g_AISystemHook__);
}
