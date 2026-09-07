// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/gametrace_engine.cpp
// Functions: 1
// ============================================================

#include "engine\gametrace_engine.h"

//------------------------------------------------------------------------------
// Address: 0x1017CF00
// Name: public: struct edict_t __near * CGameTrace::GetEdict(void)const
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CGameTrace::GetEdict(CGameTrace *this)
{
  return serverGameEnts->BaseEntityToEdict(this: serverGameEnts, a2: this->m_pEnt);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1017D2C0
// Name: public: struct edict_t __near * CGameTrace::GetEdict(void)const
// Source: json
//------------------------------------------------------------------------------
edict_t *__thiscall CGameTrace::GetEdict(CGameTrace *this)
{
  return serverGameEnts->BaseEntityToEdict(this: serverGameEnts, a2: this->m_pEnt);
}

} // namespace engine_xlsp
