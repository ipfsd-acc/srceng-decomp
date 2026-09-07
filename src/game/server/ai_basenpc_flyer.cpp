// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_basenpc_flyer.cpp
// Functions: 1
// ============================================================

#include "game\server\ai_basenpc_flyer.h"

//------------------------------------------------------------------------------
// Address: 0x103FB2C0
// Name: CAI_BaseFlyingBot_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_BaseFlyingBot_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_BaseFlyingBot>();
  CAI_BaseFlyingBot_DataDescInit::g_DataMapHolder = result;
  return result;
}
