// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/info_view_parameters.cpp
// Functions: 2
// ============================================================

#include "game\server\cstrike15\info_view_parameters.h"

//------------------------------------------------------------------------------
// Address: 0x102A3A80
// Name: public: virtual struct datamap_t __near * CInfoViewParameters::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CInfoViewParameters::GetDataDescMap(CInfoViewParameters *this)
{
  return &CInfoViewParameters::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10410200
// Name: CInfoViewParameters_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CInfoViewParameters_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CInfoViewParameters>();
  CInfoViewParameters_DataDescInit::g_DataMapHolder = result;
  return result;
}
