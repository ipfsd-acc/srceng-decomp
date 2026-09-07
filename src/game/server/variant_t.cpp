// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/variant_t.cpp
// Functions: 1
// ============================================================

#include "game\server\variant_t.h"

//------------------------------------------------------------------------------
// Address: 0x10252880
// Name: public: void variant_t::SetEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall variant_t::SetEntity(variant_t *this, CBaseEntity *val)
{
  if ( val != nullptr )
    this->eVal.m_Index = val->GetRefEHandle(this: val)->m_Index;
  else
    this->eVal.m_Index = -1;
  this->fieldType = FIELD_EHANDLE;
}
