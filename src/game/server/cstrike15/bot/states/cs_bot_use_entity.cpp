// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_use_entity.cpp
// Functions: 1
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_use_entity.h"

//------------------------------------------------------------------------------
// Address: 0x102D8780
// Name: public: virtual void UseEntityState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall UseEntityState::OnUpdate(UseEntityState *this, CCSBot *me)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  Vector pos; // [esp+18h] [ebp-Ch] BYREF

  if ( (float)(me->m_stateTimestamp - gpGlobals->curtime) > 5.0 )
  {
LABEL_12:
    CCSBot::Idle(this: me);
    return;
  }
  m_Index = this->m_entity.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *, Vector *))m_pEntity->__vftable[42].dtr_IHandleEntity)(a1: m_pEntity, a2: &pos);
  CCSBot::SetLookAt(
    this: me,
    desc: "Use entity",
    &pos,
    pri: PRIORITY_HIGH,
    duration: -1.0,
    clearIfClose: false,
    angleTolerance: 5.0,
    attack: false);
  if ( CBot<CCSPlayer>::IsLookingAtPosition(this: me, &pos, angleTolerance: 20.0) )
  {
    if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)2
      && CBaseEntity::GetTeamNumber(this: me) == 3
      && me->m_task == COLLECT_HOSTAGES )
    {
      ++me->m_hostageEscortCount;
    }
    me->UseEnvironment(this: me);
    goto LABEL_12;
  }
}
