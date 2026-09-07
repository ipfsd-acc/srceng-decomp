// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/gametrace_client.cpp
// Functions: 3
// ============================================================

#include "game\client\gametrace_client.h"

//------------------------------------------------------------------------------
// Address: 0x100EA450
// Name: public: int CGameTrace::GetEntityIndex(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CGameTrace::GetEntityIndex(CGameTrace *this)
{
  if ( this->m_pEnt != nullptr )
    return (*(int (__thiscall **)(char *))(*((_DWORD *)this->m_pEnt + 2) + 40))(a1: (char *)this->m_pEnt + 8);
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100EA470
// Name: public: bool CGameTrace::DidHitWorld(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CGameTrace::DidHitWorld(CGameTrace *this)
{
  return this->m_pEnt == (struct CBaseEntity *)CClientEntityList::GetBaseEntity(
                                                 this: (CClientEntityList *)cl_entitylist.m_Index,
                                                 entnum: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100EA490
// Name: public: bool CGameTrace::DidHitNonWorldEntity(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CGameTrace::DidHitNonWorldEntity(CGameTrace *this)
{
  return this->m_pEnt != nullptr
      && (C_BaseEntity *)this->m_pEnt != CClientEntityList::GetBaseEntity(
                                           this: (CClientEntityList *)cl_entitylist.m_Index,
                                           entnum: 0);
}
