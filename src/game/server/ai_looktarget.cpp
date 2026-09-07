// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_looktarget.cpp
// Functions: 1
// ============================================================

#include "game\server\ai_looktarget.h"

//------------------------------------------------------------------------------
// Address: 0x103FC7E0
// Name: CAI_LookTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_LookTarget_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_LookTarget>();
  CAI_LookTarget_DataDescInit::g_DataMapHolder = result;
  return result;
}
