// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_fetch_bomb.cpp
// Functions: 3
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_fetch_bomb.h"

//------------------------------------------------------------------------------
// Address: 0x102D3460
// Name: public: virtual void FetchBombState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FetchBombState::OnEnter(FetchBombState *this, CCSBot *me)
{
  me->m_isStopping = false;
  me->m_pathLength = 0;
  me->m_pathLadder = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102D3480
// Name: public: virtual void FetchBombState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall FetchBombState::OnUpdate(FetchBombState *this, CCSBot *me)
{
  unsigned int v2; // ecx
  CBaseEntity **v3; // eax
  CBaseEntity *v4; // edi
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( CCSPlayer::HasC4(this: me) )
  {
    CBot<CCSPlayer>::PrintIfWatched(this: me, format: "I picked up the bomb\n");
    CCSBot::Idle(this: me);
  }
  else
  {
    v2 = *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[476];
    if ( v2 != -1
      && (v3 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v2],
          g_pEntityList->m_EntPtrArray[(unsigned __int16)v2].m_SerialNumber == HIWORD(v2))
      && (v4 = *v3, *v3 != nullptr) )
    {
      if ( me->m_pathLength != 0 )
        goto LABEL_11;
      if ( (v4->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: *v3, a2: (int)&savedregs);
      v4 = (CBaseEntity *)((char *)v4 + 460);
      if ( CCSBot::ComputePath(this: me, goal: (const Vector *)v4, route: SAFEST_ROUTE) != 0 )
      {
LABEL_11:
        CCSBot::UpdateLookAround(this: me, a2: COERCE_FLOAT(&savedregs), a3: (int)v4, updateNow: false);
        if ( CCSBot::UpdatePathMovement(this: me, a2: (int)&savedregs, allowSpeedChange: true) != 0 )
          CCSBot::Idle(this: me);
      }
      else
      {
        CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Fetch bomb pathfind failed\n");
        CCSBot::Hunt(this: me);
      }
    }
    else
    {
      CBot<CCSPlayer>::PrintIfWatched(this: me, format: "Someone else picked up the bomb.\n");
      CCSBot::Idle(this: me);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D3570
// Name: __CreateCServerGameTagsIServerGameTags_interface_42
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_42()
{
  return &_g_CServerGameTags_singleton_42;
}
