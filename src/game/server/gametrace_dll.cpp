// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/gametrace_dll.cpp
// Functions: 3
// ============================================================

#include "game\server\gametrace_dll.h"

//------------------------------------------------------------------------------
// Address: 0x10152900
// Name: public: bool CGameTrace::DidHitWorld(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameTrace::DidHitWorld(CGameTrace *this)
{
  return this->m_pEnt == GetWorldEntity();
}

//------------------------------------------------------------------------------
// Address: 0x10152920
// Name: public: bool CGameTrace::DidHitNonWorldEntity(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameTrace::DidHitNonWorldEntity(CGameTrace *this)
{
  return this->m_pEnt != nullptr && this->m_pEnt != GetWorldEntity();
}

//------------------------------------------------------------------------------
// Address: 0x10152940
// Name: public: int CGameTrace::GetEntityIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameTrace::GetEntityIndex(CGameTrace *this)
{
  CBaseEntity *m_pEnt; // eax
  int result; // eax

  m_pEnt = this->m_pEnt;
  if ( m_pEnt == nullptr )
    return -1;
  result = (int)m_pEnt->m_Network.m_pPev;
  if ( result != 0 )
    return (signed int)(result - (unsigned int)gpGlobals->pEdicts) >> 4;
  return result;
}
