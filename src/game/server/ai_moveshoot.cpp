// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_moveshoot.cpp
// Functions: 14
// ============================================================

#include "game\server\ai_moveshoot.h"

//------------------------------------------------------------------------------
// Address: 0x100610B0
// Name: public: void CAI_MoveAndShootOverlay::NoShootWhileMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_MoveAndShootOverlay::NoShootWhileMove(CAI_MoveAndShootOverlay *this)
{
  this->m_bNoShootWhileMove = true;
}

//------------------------------------------------------------------------------
// Address: 0x100610C0
// Name: public: CAI_MoveAndShootOverlay::CAI_MoveAndShootOverlay(void)
// Source: json
//------------------------------------------------------------------------------
CAI_MoveAndShootOverlay *__thiscall CAI_MoveAndShootOverlay::CAI_MoveAndShootOverlay(CAI_MoveAndShootOverlay *this)
{
  this->m_initialDelay = 0.0;
  this->m_pOuter = nullptr;
  this->__vftable = (CAI_MoveAndShootOverlay_vtbl *)&CAI_MoveAndShootOverlay::`vftable';
  this->m_flSuspendUntilTime = -1.0;
  *(_WORD *)&this->m_bMovingAndShooting = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100610F0
// Name: private: bool CAI_MoveAndShootOverlay::HasAvailableRangeAttack(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_MoveAndShootOverlay::HasAvailableRangeAttack(CAI_MoveAndShootOverlay *this)
{
  return CBaseCombatCharacter::GetActiveWeapon(this: this->m_pOuter) != nullptr
      || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x20000) != 0
      || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x40000) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10061140
// Name: public: void CAI_MoveAndShootOverlay::StartShootWhileMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_MoveAndShootOverlay::StartShootWhileMove(CAI_MoveAndShootOverlay *this)
{
  CAI_BaseNPC *m_pOuter; // ecx
  CAI_BaseNPC *v3; // edi
  Activity v4; // eax
  CAI_BaseNPC *v5; // edi
  Activity v6; // eax

  m_pOuter = this->m_pOuter;
  if ( m_pOuter->m_NPCState != NPC_STATE_SCRIPT
    && (CBaseCombatCharacter::GetActiveWeapon(this: m_pOuter) != nullptr
     || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x20000) != 0
     || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x40000) != 0)
    && (v3 = this->m_pOuter,
        v4 = CAI_BaseNPC::TranslateActivity(this: v3, idealActivity: ACT_WALK_AIM, pIdealWeaponActivity: nullptr),
        CAI_BaseNPC::HaveSequenceForActivity(this: v3, activity: v4))
    && (v5 = this->m_pOuter,
        v6 = CAI_BaseNPC::TranslateActivity(this: v5, idealActivity: ACT_RUN_AIM, pIdealWeaponActivity: nullptr),
        CAI_BaseNPC::HaveSequenceForActivity(this: v5, activity: v6)) )
  {
    CAI_ShotRegulator::FireNoEarlierThan(
      this: &this->m_pOuter->m_ShotRegulator,
      flTime: gpGlobals->curtime + this->m_initialDelay);
    this->m_bNoShootWhileMove = false;
  }
  else
  {
    this->m_bNoShootWhileMove = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100611F0
// Name: private: void CAI_MoveAndShootOverlay::UpdateMoveShootActivity(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_MoveAndShootOverlay::UpdateMoveShootActivity(CAI_MoveAndShootOverlay *this, bool bMoveAimAtEnemy)
{
  Activity MovementActivity; // eax
  Activity v4; // esi

  MovementActivity = CAI_Navigator::GetMovementActivity(this: this->m_pOuter->m_pNavigator);
  if ( bMoveAimAtEnemy )
  {
    if ( MovementActivity == ACT_WALK )
    {
      v4 = ACT_WALK_AIM;
    }
    else
    {
      if ( MovementActivity != ACT_RUN )
        return;
      v4 = ACT_RUN_AIM;
    }
  }
  else if ( MovementActivity == ACT_WALK_AIM )
  {
    v4 = ACT_WALK;
  }
  else
  {
    if ( MovementActivity != ACT_RUN_AIM )
      return;
    v4 = ACT_RUN;
  }
  CAI_ShotRegulator::FireNoEarlierThan(this: &this->m_pOuter->m_ShotRegulator, flTime: gpGlobals->curtime + 0.30000001);
  CAI_Navigator::SetMovementActivity(this: this->m_pOuter->m_pNavigator, activity: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10061280
// Name: public: void CAI_MoveAndShootOverlay::EndShootWhileMove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_MoveAndShootOverlay::EndShootWhileMove(CAI_MoveAndShootOverlay *this)
{
  CAI_BaseNPC *m_pOuter; // ecx

  if ( this->m_bMovingAndShooting )
  {
    if ( !CAI_ShotRegulator::IsInRestInterval(this: &this->m_pOuter->m_ShotRegulator) )
      CAI_ShotRegulator::Reset(this: &this->m_pOuter->m_ShotRegulator, bStartShooting: false);
    m_pOuter = this->m_pOuter;
    this->m_bMovingAndShooting = false;
    m_pOuter->OnEndMoveAndShoot(this: m_pOuter);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100612C0
// Name: private: bool CAI_MoveAndShootOverlay::CanAimAtEnemy(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_MoveAndShootOverlay::CanAimAtEnemy(CAI_MoveAndShootOverlay *this)
{
  CAI_BaseNPC *m_pOuter; // ebx
  int v3; // eax
  char v4; // bl
  CAI_BaseNPC_vtbl *v6; // [esp+8h] [ebp-8h]
  bool v7; // [esp+Fh] [ebp-1h]

  m_pOuter = this->m_pOuter;
  v7 = false;
  if ( !m_pOuter->m_bConditionsGathered )
  {
    v6 = m_pOuter->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
    v3 = (int)m_pOuter->GetEnemy_2(this: m_pOuter);
    v6->GatherEnemyConditions(this: m_pOuter, a2: (CBaseEntity *)v3);
  }
  if ( CAI_BaseNPC::HasCondition(this: m_pOuter, iCondition: 21) )
  {
    v4 = 1;
  }
  else
  {
    if ( !CAI_BaseNPC::HasCondition(this: m_pOuter, iCondition: 30)
      && !CAI_BaseNPC::HasCondition(this: m_pOuter, iCondition: 39)
      && !CAI_BaseNPC::HasCondition(this: m_pOuter, iCondition: 27)
      && !CAI_BaseNPC::HasCondition(this: m_pOuter, iCondition: 13) )
    {
      v7 = true;
    }
    v4 = v7;
  }
  if ( CBaseCombatCharacter::GetActiveWeapon(this: this->m_pOuter) != nullptr
    || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x20000) != 0
    || (this->m_pOuter->CapabilitiesGet(this: this->m_pOuter) & 0x40000) != 0 )
  {
    return v4;
  }
  else
  {
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061390
// Name: public: void CAI_MoveAndShootOverlay::RunShootWhileMove(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_MoveAndShootOverlay::RunShootWhileMove(
        CAI_MoveAndShootOverlay *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>)
{
  CAI_BaseNPC *m_pOuter; // esi
  int v5; // eax
  CBaseEntity *v6; // eax
  CAI_BaseNPC_vtbl *v7; // edi
  CBaseEntity *v8; // eax
  const Vector *AbsOrigin; // eax
  int v10; // eax
  Activity v11; // eax
  Activity v12; // eax
  Activity v13; // eax
  Activity v14; // eax
  Activity v15; // edi
  CAI_BaseNPC_vtbl *v16; // edi
  int v17; // eax
  Vector vecEnemyLKP; // [esp+18h] [ebp-10h] BYREF
  int bMoveAimAtEnemy; // [esp+24h] [ebp-4h]

  if ( !this->m_bNoShootWhileMove && this->m_flSuspendUntilTime <= gpGlobals->curtime )
  {
    m_pOuter = this->m_pOuter;
    this->m_flSuspendUntilTime = -1.0;
    if ( m_pOuter->GetEnemy_2(this: m_pOuter) == nullptr
      || (v5 = (int)m_pOuter->GetEnemy_2(this: m_pOuter),
          (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 272))(a1: v5) == 0) )
    {
      v6 = m_pOuter->BestEnemy(this: m_pOuter);
      if ( v6 != nullptr )
      {
        CAI_BaseNPC::SetEnemy(this: m_pOuter, pEnemy: v6, bSetCondNewEnemy: true);
        CAI_BaseNPC::SetState(this: m_pOuter, State: NPC_STATE_COMBAT);
      }
      else
      {
        m_pOuter->ClearAttackConditions(this: m_pOuter);
      }
    }
    if ( CAI_Navigator::IsGoalActive(this: m_pOuter->m_pNavigator) )
    {
      if ( this->m_pOuter->GetEnemy_2(this: this->m_pOuter) != nullptr )
      {
        LOBYTE(bMoveAimAtEnemy) = CAI_MoveAndShootOverlay::CanAimAtEnemy(this);
        CAI_MoveAndShootOverlay::UpdateMoveShootActivity(this, bMoveAimAtEnemy);
        if ( (_BYTE)bMoveAimAtEnemy != 0 )
        {
          v11 = CAI_BaseNPC::TranslateActivity(
                  this: m_pOuter,
                  idealActivity: ACT_GESTURE_RELOAD,
                  pIdealWeaponActivity: nullptr);
          if ( (v11 == ACT_INVALID || !CBaseAnimatingOverlay::IsPlayingGesture(this: m_pOuter, activity: v11))
            && CAI_MoveAndShootOverlay::HasAvailableRangeAttack(this) )
          {
            if ( CAI_BaseNPC::HasCondition(this: m_pOuter, iCondition: 21, bUseIgnoreConditions: false) )
            {
              if ( CAI_ShotRegulator::IsInRestInterval(this: &m_pOuter->m_ShotRegulator) )
              {
                CAI_MoveAndShootOverlay::EndShootWhileMove(this);
              }
              else if ( CAI_ShotRegulator::ShouldShoot(this: &m_pOuter->m_ShotRegulator)
                     && (this->m_bMovingAndShooting || m_pOuter->OnBeginMoveAndShoot(this: m_pOuter)) )
              {
                this->m_bMovingAndShooting = true;
                ((void (__thiscall *)(CAI_BaseNPC *, int, int))m_pOuter->OnRangeAttack1)(a1: m_pOuter, a2, a3);
                v12 = CAI_BaseNPC::TranslateActivity(
                        this: m_pOuter,
                        idealActivity: ACT_GESTURE_RANGE_ATTACK1,
                        pIdealWeaponActivity: nullptr);
                CBaseAnimatingOverlay::RestartGesture(this: m_pOuter, activity: v12, addifmissing: true, autokill: true);
                v13 = ((int (__thiscall *)(CAI_BaseNPC *))m_pOuter->Weapon_TranslateActivity)(a1: m_pOuter);
                CBaseCombatCharacter::Weapon_SetActivity(this: m_pOuter, newActivity: v13, duration: COERCE_FLOAT(16));
              }
            }
            else if ( CAI_BaseNPC::HasCondition(this: m_pOuter, iCondition: 4, bUseIgnoreConditions: false)
                   && CAI_Navigator::GetPathTimeToGoal(this: m_pOuter->m_pNavigator) > 1.0 )
            {
              v14 = CAI_BaseNPC::TranslateActivity(
                      this: m_pOuter,
                      idealActivity: ACT_GESTURE_RELOAD,
                      pIdealWeaponActivity: nullptr);
              v15 = v14;
              if ( v14 != ACT_INVALID && CAI_BaseNPC::HaveSequenceForActivity(this: this->m_pOuter, activity: v14) )
                CBaseAnimatingOverlay::AddGesture(this: m_pOuter, activity: v15, autokill: true);
            }
          }
          vecEnemyLKP = *m_pOuter->GetEnemyLKP(this: m_pOuter);
          v16 = m_pOuter->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
          v17 = ((int (__thiscall *)(CAI_BaseNPC *, Vector *, int, int, _DWORD))m_pOuter->GetEnemy_2)(
                  a1: m_pOuter,
                  a2: &vecEnemyLKP,
                  a3: 1065353216,
                  a4: 1061997773,
                  a5: 0);
          ((void (__thiscall *)(CAI_BaseNPC *, int))v16->AddFacingTarget)(a1: m_pOuter, a2: v17);
        }
        else
        {
          CAI_MoveAndShootOverlay::EndShootWhileMove(this);
        }
      }
      else if ( m_pOuter->GetAlternateMoveShootTarget(this: m_pOuter) != nullptr )
      {
        v7 = m_pOuter->CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        v8 = (CBaseEntity *)((int (__thiscall *)(CAI_BaseNPC *, int, int, _DWORD))m_pOuter->GetAlternateMoveShootTarget)(
                              a1: m_pOuter,
                              a2: 1065353216,
                              a3: 1045220557,
                              a4: 0);
        AbsOrigin = CBaseEntity::GetAbsOrigin(this: v8);
        v10 = ((int (__thiscall *)(CAI_BaseNPC *, const Vector *))m_pOuter->GetAlternateMoveShootTarget)(
                a1: m_pOuter,
                a2: AbsOrigin);
        ((void (__thiscall *)(CAI_BaseNPC *, int))v7->AddFacingTarget)(a1: m_pOuter, a2: v10);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FC920
// Name: CAI_MoveAndShootOverlay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_MoveAndShootOverlay_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_MoveAndShootOverlay>(__formal: nullptr);
  CAI_MoveAndShootOverlay_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10405F30
// Name: _dynamic_initializer_for__move_keyframed__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__move_keyframed__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CBaseMoveBehavior> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &move_keyframed,
           a3: "move_keyframed");
}

//------------------------------------------------------------------------------
// Address: 0x10409630
// Name: _dynamic_initializer_for__move_rope__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__move_rope__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRopeKeyframe> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &move_rope,
           a3: "move_rope");
}

//------------------------------------------------------------------------------
// Address: 0x10061670
// Name: struct datamap_t __near * DataMapInit<class CAI_MoveAndShootOverlay>(class CAI_MoveAndShootOverlay __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_MoveAndShootOverlay>()
{
  if ( (_S2_24 & 1) == 0 )
  {
    _S2_24 |= 1u;
    nameHolder_53.m_pszBase = "CAI_MoveAndShootOverlay";
    nameHolder_53.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_53.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_53.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_53.m_Names.m_Size = 0;
    nameHolder_53.m_Names.m_pElements = nullptr;
    nameHolder_53.m_nLenBase = 23;
    atexit(func: DataMapInit_CAI_MoveAndShootOverlay__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_MoveAndShootOverlay::m_DataMap.baseMap = nullptr;
  CAI_MoveAndShootOverlay::m_DataMap.dataNumFields = 4;
  CAI_MoveAndShootOverlay::m_DataMap.dataDesc = &dataDesc_51[1];
  return &CAI_MoveAndShootOverlay::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FC930
// Name: _dynamic_initializer_for__ai_vehicle_avoidance__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_vehicle_avoidance__()
{
  ConVar::ConVar(this: &ai_vehicle_avoidance, pName: "ai_vehicle_avoidance", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__ai_vehicle_avoidance__);
}

//------------------------------------------------------------------------------
// Address: 0x103FC960
// Name: _dynamic_initializer_for__ai_debug_nav__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_debug_nav__()
{
  ConVar::ConVar(this: &ai_debug_nav, pName: "ai_debug_nav", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_debug_nav__);
}
