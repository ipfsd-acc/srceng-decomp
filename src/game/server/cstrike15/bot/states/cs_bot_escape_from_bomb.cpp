// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/states/cs_bot_escape_from_bomb.cpp
// Functions: 4
// ============================================================

#include "game\server\cstrike15\bot\states\cs_bot_escape_from_bomb.h"

//------------------------------------------------------------------------------
// Address: 0x102D2BE0
// Name: public: virtual void EscapeFromBombState::OnEnter(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EscapeFromBombState::OnEnter(EscapeFromBombState *this, CCSBot *me)
{
  me->StandUp(this: me);
  me->Run(this: me);
  me->m_isStopping = false;
  me->m_pathLength = 0;
  me->m_pathLadder = nullptr;
  CCSBot::EquipKnife(this: me);
}

//------------------------------------------------------------------------------
// Address: 0x102D2C40
// Name: class CNavArea __near * FindMinimumCostArea<class FarAwayFromPositionFunctor>(class CNavArea __near *,class FarAwayFromPositionFunctor __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CNavArea *__usercall FindMinimumCostArea<FarAwayFromPositionFunctor>@<eax>(
        int a1@<ebp>,
        CNavArea *startArea,
        FarAwayFromPositionFunctor *costFunc)
{
  int m_Size; // ecx
  int v4; // edx
  int v5; // eax
  CNavArea *v6; // eax
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  __int128 v10; // xmm1
  int v11; // xmm0_4
  int v12; // esi
  char *v13; // ecx
  int v14; // eax
  float *v15; // edx
  int v16; // edx
  int v18; // eax
  int v19; // ecx
  int v20; // edi
  _BYTE cheapAreaSet_8[252]; // [esp+8h] [ebp-138h] OVERLAPPED BYREF
  int v22; // [esp+10Ch] [ebp-34h]
  int v23; // [esp+110h] [ebp-30h]
  int v24; // [esp+114h] [ebp-2Ch]
  int v25; // [esp+118h] [ebp-28h]
  int v26; // [esp+11Ch] [ebp-24h]
  CNavArea *area; // [esp+120h] [ebp-20h]
  int v28; // [esp+124h] [ebp-1Ch]
  int v29; // [esp+128h] [ebp-18h]
  int v30; // [esp+12Ch] [ebp-14h]
  int v31; // [esp+130h] [ebp-10h]
  int iter; // [esp+134h] [ebp-Ch] BYREF
  void *v33; // [esp+138h] [ebp-8h]
  void *retaddr; // [esp+140h] [ebp+0h]

  iter = a1;
  v33 = retaddr;
  m_Size = TheNavAreas.m_Size;
  v4 = 0;
  v5 = 0;
  v31 = 0;
  v29 = 0;
  if ( TheNavAreas.m_Size > 0 )
  {
    do
    {
      v6 = TheNavAreas.m_Memory.m_pMemory[v5];
      v7 = v6->m_seCorner.x - v6->m_nwCorner.x;
      v24 = (int)v6;
      if ( v7 >= 150.0 && (float)(v6->m_seCorner.y - v6->m_nwCorner.y) >= 150.0 )
      {
        v8 = costFunc->m_pos->y - v6->m_center.y;
        v9 = (float)((float)((float)(costFunc->m_pos->x - v6->m_center.x) * (float)(costFunc->m_pos->x - v6->m_center.x))
                   + (float)((float)(costFunc->m_pos->z - v6->m_center.z) * (float)(costFunc->m_pos->z - v6->m_center.z)))
           + (float)(v8 * v8);
        v10 = 0;
        *(float *)&v10 = fsqrt(v9);
        *(_OWORD *)&cheapAreaSet_8[236] = v10;
        *(float *)&v11 = 1.0 / *(float *)&v10;
        if ( v4 >= 32 )
        {
          v25 = 24 - (_DWORD)cheapAreaSet_8;
          v23 = 32 - (_DWORD)cheapAreaSet_8;
          v28 = 40 - (_DWORD)cheapAreaSet_8;
          v22 = 48 - (_DWORD)cheapAreaSet_8;
          area = (CNavArea *)(56 - (_DWORD)cheapAreaSet_8);
          v12 = 0;
          v13 = nullptr;
          v14 = 1;
          v30 = 16;
          v26 = 64 - (_DWORD)cheapAreaSet_8;
          do
          {
            v15 = (float *)(&iter + 2 * v14 - 77);
            if ( *((float *)&iter + 2 * v14 - 79) > *(float *)((char *)&iter + (_DWORD)v13 - 316) )
            {
              v12 = v14;
              v13 = (char *)(8 * v14);
            }
            if ( *v15 > *(float *)((char *)&iter + (_DWORD)v13 - 316) )
            {
              v13 = (char *)v30;
              v12 = v14 + 1;
            }
            if ( v15[2] > *(float *)((char *)&iter + (_DWORD)v13 - 316) )
            {
              v12 = v14 + 2;
              v13 = (char *)v15 + v25;
            }
            if ( v15[4] > *(float *)((char *)&iter + (_DWORD)v13 - 316) )
            {
              v12 = v14 + 3;
              v13 = (char *)v15 + v23;
            }
            if ( v15[6] > *(float *)((char *)&iter + (_DWORD)v13 - 316) )
            {
              v12 = v14 + 4;
              v13 = (char *)v15 + v28;
            }
            if ( v15[8] > *(float *)((char *)&iter + (_DWORD)v13 - 316) )
            {
              v12 = v14 + 5;
              v13 = (char *)v15 + v22;
            }
            if ( v15[10] > *(float *)((char *)&iter + (_DWORD)v13 - 316) )
            {
              v12 = v14 + 6;
              v13 = (char *)area + (_DWORD)v15;
            }
            if ( v15[12] > *(float *)((char *)&iter + (_DWORD)v13 - 316) )
            {
              v12 = v14 + 7;
              v13 = (char *)v15 + v26;
            }
            v14 += 8;
            v30 += 64;
          }
          while ( v30 < 208 );
          if ( v14 < 32 )
          {
            v16 = 8 * v12;
            do
            {
              if ( *((float *)&iter + 2 * v14 - 79) > *(float *)((char *)&iter + v16 - 316) )
              {
                v12 = v14;
                v16 = 8 * v14;
              }
              ++v14;
            }
            while ( v14 < 32 );
          }
          if ( *((float *)&iter + 2 * v12 - 79) > *(float *)&v11 )
          {
            *(&iter + 2 * v12 - 80) = v24;
            *(&iter + 2 * v12 - 79) = v11;
          }
          v4 = v31;
        }
        else
        {
          *(&iter + 2 * v4 - 80) = (int)v6;
          *(&iter + 2 * v4++ - 79) = v11;
          v31 = v4;
        }
      }
      m_Size = TheNavAreas.m_Size;
      v5 = v29 + 1;
      v29 = v5;
    }
    while ( v5 < TheNavAreas.m_Size );
    if ( v4 != 0 )
      return (CNavArea *)*(&iter
                         + 2 * _RandomInt(this: (IUniformRandomStream *)TheNavAreas.m_Size, a2: 0, a3: v4 - 1)
                         - 80);
  }
  v18 = _RandomInt(this: (IUniformRandomStream *)(m_Size - 1), a2: 0, a3: m_Size - 1);
  v19 = 0;
  if ( TheNavAreas.m_Size <= 0 )
    return (CNavArea *)*(&iter + 2 * _RandomInt(this: (IUniformRandomStream *)v19, a2: 0, a3: -1) - 80);
  while ( 1 )
  {
    v20 = v18--;
    if ( v20 == 0 )
      break;
    if ( ++v19 >= TheNavAreas.m_Size )
      return (CNavArea *)*(&iter + 2 * _RandomInt(this: (IUniformRandomStream *)v19, a2: 0, a3: -1) - 80);
  }
  return TheNavAreas.m_Memory.m_pMemory[v19];
}

//------------------------------------------------------------------------------
// Address: 0x102D2F50
// Name: public: virtual void EscapeFromBombState::OnUpdate(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall EscapeFromBombState::OnUpdate(EscapeFromBombState *this, CCSBot *me)
{
  CCSBot *v2; // esi
  CCSBot *BombPosition; // edi
  CNavArea *(__thiscall *GetLastKnownArea)(CBaseCombatCharacter *); // eax
  CNavArea *v5; // eax
  CNavArea *MinimumCost; // eax
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  v2 = me;
  BombPosition = (CCSBot *)CSGameState::GetBombPosition(this: &me->m_gameState);
  if ( BombPosition != nullptr )
  {
    CCSBot::EquipKnife(this: v2);
    CCSBot::UpdateLookAround(this: v2, a2: COERCE_FLOAT(&savedregs), a3: (int)BombPosition, updateNow: false);
    if ( CCSBot::UpdatePathMovement(this: v2, a2: (int)&savedregs, allowSpeedChange: true) != 0 )
    {
      GetLastKnownArea = v2->GetLastKnownArea;
      me = BombPosition;
      v5 = GetLastKnownArea(this: v2);
      MinimumCost = FindMinimumCostArea<FarAwayFromPositionFunctor>(
                      a1: (int)&savedregs,
                      startArea: v5,
                      costFunc: (FarAwayFromPositionFunctor *)&me);
      CCSBot::ComputePath(this: v2, goal: &MinimumCost->m_center, route: FASTEST_ROUTE);
    }
  }
  else
  {
    CCSBot::Idle(this: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102D2FC0
// Name: __CreateCServerGameTagsIServerGameTags_interface_40
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_40()
{
  return &_g_CServerGameTags_singleton_40;
}
