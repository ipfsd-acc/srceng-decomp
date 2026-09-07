// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_behavior_standoff.cpp
// Functions: 23
// ============================================================

#include "game\server\ai_behavior_standoff.h"

//------------------------------------------------------------------------------
// Address: 0x10048990
// Name: private: virtual struct datamap_t __near * CAI_BattleLine::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_BattleLine::GetDataDescMap(CAI_BattleLine *this)
{
  return &CAI_BattleLine::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100489A0
// Name: private: virtual struct datamap_t __near * CAI_StandoffGoal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_StandoffGoal::GetDataDescMap(CAI_StandoffGoal *this)
{
  return &CAI_StandoffGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10048A60
// Name: private: void CAI_BattleLine::NotifyChangeTacticalConstraints(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BattleLine::NotifyChangeTacticalConstraints(CAI_BattleLine *this)
{
  int i; // ebx
  CAI_BaseNPC *v2; // esi
  const char *pszValue; // edi
  CAI_Squad *m_pSquad; // eax
  const char *v5; // eax
  CAI_StandoffBehavior *v6; // eax
  CAI_StandoffBehavior *pBehavior; // [esp+4h] [ebp-8h] BYREF
  CAI_BattleLine *v8; // [esp+8h] [ebp-4h]

  v8 = this;
  for ( i = 0; i < vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager); ++i )
  {
    v2 = CAI_Manager::AccessAIs(this: &g_AI_Manager)[i];
    pszValue = v8->m_iszActor.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    if ( v2->m_iName.m_Value.pszValue != pszValue
      && CBaseEntity::NameMatchesComplex(this: v2, pszNameOrWildcard: pszValue) == 0
      && v2->m_iClassname.pszValue != pszValue
      && CBaseEntity::ClassMatchesComplex(this: v2, pszClassOrWildcard: pszValue) == 0 )
    {
      m_pSquad = v2->m_pSquad;
      if ( m_pSquad == nullptr )
        continue;
      v5 = m_pSquad->m_Name.pszValue;
      if ( v5 == nullptr )
        v5 = locale;
      if ( _V_stricmp(s1: v5, s2: pszValue) != 0 )
        continue;
    }
    if ( CAI_BaseNPC::GetBehavior<CAI_StandoffBehavior>(this: v2, ppBehavior: &pBehavior) != 0 )
    {
      v6 = pBehavior;
      if ( pBehavior->m_params.hintChangeReaction > AIHCR_DEFAULT_AI )
      {
        pBehavior->m_TimeForceCoverHint.m_interval = 8.0;
        v6->m_TimeForceCoverHint.m_next = gpGlobals->curtime + 8.0;
      }
      if ( v6->m_params.hintChangeReaction == AIHCR_MOVE_IMMEDIATE )
        v6->m_fTakeCover = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048B60
// Name: public: void CAI_StandoffBehavior::SetParameters(struct AI_StandoffParams_t const __near &,class CAI_GoalEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_StandoffBehavior::SetParameters(
        CAI_StandoffBehavior *this,
        const AI_StandoffParams_t *params,
        CAI_GoalEntity *pGoalEntity)
{
  CAI_BaseNPC *m_pOuter; // eax

  this->m_params = *params;
  if ( pGoalEntity != nullptr )
    this->m_hStandoffGoal.m_Index = pGoalEntity->GetRefEHandle(this: pGoalEntity)->m_Index;
  else
    this->m_hStandoffGoal.m_Index = -1;
  this->m_vecStandoffGoalPosition.x = 3.4028235e38;
  this->m_vecStandoffGoalPosition.y = 3.4028235e38;
  this->m_vecStandoffGoalPosition.z = 3.4028235e38;
  m_pOuter = this->m_pOuter;
  if ( m_pOuter != nullptr && m_pOuter != (CAI_BaseNPC *)-2944 )
  {
    CAI_ShotRegulator::SetBurstShotCountRange(
      this: &m_pOuter->m_ShotRegulator,
      minShotsPerBurst: this->m_params.minShots,
      maxShotsPerBurst: this->m_params.maxShots);
    CAI_ShotRegulator::SetRestInterval(
      this: &this->m_pOuter->m_ShotRegulator,
      flMinRestInterval: this->m_params.minTimeShots,
      flMaxRestInterval: this->m_params.maxTimeShots);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048C20
// Name: public: void CAI_StandoffGoal::SetBehaviorParams(class CAI_StandoffBehavior __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_StandoffGoal::SetBehaviorParams(CAI_StandoffGoal *this, CAI_StandoffBehavior *pBehavior)
{
  CAI_StandoffGoal::Aggressiveness_t m_aggressiveness; // eax
  CAI_StandoffGoal::Aggressiveness_t v3; // eax
  __int64 v4; // xmm0_8
  AI_StandoffParams_t *v5; // eax
  __int64 v6; // xmm0_8
  float flAbandonTimeLimit; // edx
  bool v8; // zf
  bool m_fPlayerIsBattleline; // dl
  bool m_fStayAtCover; // al
  CAI_BaseNPC *m_pOuter; // ecx
  AI_StandoffParams_t params; // [esp+0h] [ebp-24h] BYREF

  m_aggressiveness = this->m_aggressiveness;
  if ( m_aggressiveness == AGGR_CUSTOM )
  {
    flAbandonTimeLimit = this->m_customParams.flAbandonTimeLimit;
    *(_QWORD *)&params.hintChangeReaction = *(_QWORD *)&this->m_customParams.hintChangeReaction;
    *(_QWORD *)&params.minTimeShots = *(_QWORD *)&this->m_customParams.minTimeShots;
    *(_QWORD *)&params.minShots = *(_QWORD *)&this->m_customParams.minShots;
    v6 = *(_QWORD *)&this->m_customParams.oddsCover;
    params.flAbandonTimeLimit = flAbandonTimeLimit;
  }
  else
  {
    v3 = m_aggressiveness;
    v4 = *(_QWORD *)&g_StandoffParamsByAgression[v3].hintChangeReaction;
    v5 = &g_StandoffParamsByAgression[v3];
    *(_QWORD *)&params.hintChangeReaction = v4;
    *(_QWORD *)&params.minTimeShots = *(_QWORD *)&v5->minTimeShots;
    *(_QWORD *)&params.minShots = *(_QWORD *)&v5->minShots;
    v6 = *(_QWORD *)&v5->oddsCover;
    params.flAbandonTimeLimit = v5->flAbandonTimeLimit;
  }
  v8 = !this->m_bAbandonIfEnemyHides;
  m_fPlayerIsBattleline = this->m_fPlayerIsBattleline;
  params.hintChangeReaction = this->m_HintChangeReaction;
  m_fStayAtCover = this->m_fStayAtCover;
  *(_QWORD *)&params.oddsCover = v6;
  params.fPlayerIsBattleline = m_fPlayerIsBattleline;
  params.fStayAtCover = m_fStayAtCover;
  if ( v8 )
    params.flAbandonTimeLimit = 0.0;
  CAI_StandoffBehavior::SetParameters(this: pBehavior, &params, pGoalEntity: this);
  if ( pBehavior->m_params.hintChangeReaction > AIHCR_DEFAULT_AI )
  {
    pBehavior->m_TimeForceCoverHint.m_interval = 8.0;
    pBehavior->m_TimeForceCoverHint.m_next = gpGlobals->curtime + 8.0;
  }
  if ( pBehavior->m_params.hintChangeReaction == AIHCR_MOVE_IMMEDIATE )
    pBehavior->m_fTakeCover = true;
  m_pOuter = pBehavior->m_pOuter;
  if ( m_pOuter->m_pPrimaryBehavior == pBehavior )
    CAI_BaseNPC::ClearSchedule(this: m_pOuter, szReason: "Standoff behavior parms changed");
}

//------------------------------------------------------------------------------
// Address: 0x10048DC0
// Name: public: virtual void CAI_BattleLine::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BattleLine::InputDeactivate(CAI_BattleLine *this, inputdata_t *inputdata)
{
  if ( this->m_fActive )
  {
    this->m_fActive = false;
    CAI_BattleLine::NotifyChangeTacticalConstraints(this);
    CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10048DF0
// Name: public: virtual void CAI_BattleLine::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BattleLine::UpdateOnRemove(CAI_BattleLine *this)
{
  if ( this->m_fActive )
  {
    this->m_fActive = false;
    CAI_BattleLine::NotifyChangeTacticalConstraints(this);
  }
  CBaseEntity::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x10048E10
// Name: public: void CAI_BattleLine::MovementThink(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BattleLine::MovementThink(CAI_BattleLine *this@<ecx>, int a2@<ebp>)
{
  float m_flMarkTolerance; // xmm3_4
  float v4; // xmm0_4
  double z; // st7
  _DWORD v6[3]; // [esp+28h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+34h] [ebp+0h]

  v6[0] = a2;
  v6[1] = retaddr;
  if ( this != nullptr )
  {
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2: (int)v6);
    m_flMarkTolerance = this->m_SelfMoveMonitor.m_flMarkTolerance;
    if ( m_flMarkTolerance != -1.0 )
    {
      v4 = this->m_SelfMoveMonitor.m_vMark.x - this->m_vecAbsOrigin.x;
      if ( fsqrt(
             (float)((float)((float)(this->m_SelfMoveMonitor.m_vMark.y - this->m_vecAbsOrigin.y)
                           * (float)(this->m_SelfMoveMonitor.m_vMark.y - this->m_vecAbsOrigin.y))
                   + (float)((float)(this->m_SelfMoveMonitor.m_vMark.z - this->m_vecAbsOrigin.z)
                           * (float)(this->m_SelfMoveMonitor.m_vMark.z - this->m_vecAbsOrigin.z)))
           + (float)(v4 * v4)) > m_flMarkTolerance )
      {
        CAI_BattleLine::NotifyChangeTacticalConstraints(this);
        if ( (this->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this, a2: (int)v6);
        this->m_SelfMoveMonitor.m_vMark.x = this->m_vecAbsOrigin.x;
        this->m_SelfMoveMonitor.m_vMark.y = this->m_vecAbsOrigin.y;
        z = this->m_vecAbsOrigin.z;
        this->m_SelfMoveMonitor.m_flMarkTolerance = 60.0;
        this->m_SelfMoveMonitor.m_vMark.z = z;
      }
    }
  }
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.30000001, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10048F40
// Name: public: void CAI_StandoffGoal::InputSetAggressiveness(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_StandoffGoal::InputSetAggressiveness(CAI_StandoffGoal *this, CAI_StandoffBehavior *inputdata)
{
  const char *v3; // eax
  CAI_StandoffGoal::Aggressiveness_t m_aggressiveness; // eax
  unsigned int m_flags; // eax
  int i; // edi
  unsigned int m_Index; // eax
  CAI_BaseNPC *m_pEntity; // ecx

  if ( inputdata->m_ScheduleChannels.m_Size == 5 )
    v3 = (const char *)inputdata->CAI_MappedActivityBehavior_Temporary::CAI_Behavior<CAI_BaseNPC,100000>::CAI_ComponentWithOuter<CAI_BaseNPC,CAI_BehaviorBase>::CAI_BehaviorBase::IAI_BehaviorBridge::__vftable;
  else
    v3 = nullptr;
  this->m_aggressiveness = (CAI_StandoffGoal::Aggressiveness_t)v3;
  if ( (unsigned int)v3 >= 6 )
  {
    DevMsg(a1: "Invalid aggressiveness value %d\n", v3);
    m_aggressiveness = this->m_aggressiveness;
    if ( m_aggressiveness >= AGGR_VERY_LOW )
    {
      if ( m_aggressiveness > AGGR_VERY_HIGH )
        this->m_aggressiveness = AGGR_VERY_HIGH;
    }
    else
    {
      this->m_aggressiveness = AGGR_VERY_LOW;
    }
  }
  m_flags = this->m_flags;
  if ( (m_flags & 1) != 0 && (m_flags & 2) != 0 )
  {
    CAI_GoalEntity::PruneActors(this);
  }
  else
  {
    this->ResolveNames(this);
    this->m_flags |= 2u;
  }
  for ( i = 0; i < this->m_actors.m_Size; ++i )
  {
    m_Index = this->m_actors.m_Memory.m_pMemory[i].m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( CAI_BaseNPC::GetBehavior<CAI_StandoffBehavior>(this: m_pEntity, ppBehavior: &inputdata) != 0 )
      CAI_StandoffGoal::SetBehaviorParams(this, pBehavior: inputdata);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049050
// Name: public: virtual void CAI_BattleLine::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAI_BattleLine::Spawn(CAI_BattleLine *this@<ecx>, int a2@<ebp>)
{
  double z; // st7

  if ( this->m_fActive )
  {
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_BattleLine::MovementThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.30000001, szContext: nullptr);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    this->m_SelfMoveMonitor.m_vMark.x = this->m_vecAbsOrigin.x;
    this->m_SelfMoveMonitor.m_vMark.y = this->m_vecAbsOrigin.y;
    z = this->m_vecAbsOrigin.z;
    this->m_SelfMoveMonitor.m_flMarkTolerance = 60.0;
    this->m_SelfMoveMonitor.m_vMark.z = z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100490E0
// Name: public: virtual void CAI_BattleLine::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CAI_BattleLine::InputActivate(CAI_BattleLine *this@<ecx>, int a2@<ebp>, inputdata_t *inputdata)
{
  double z; // st7

  if ( !this->m_fActive )
  {
    this->m_fActive = true;
    CAI_BattleLine::NotifyChangeTacticalConstraints(this);
    CBaseEntity::ThinkSet(
      this,
      func: (void (__thiscall *)(CBaseEntity *))CAI_BattleLine::MovementThink,
      thinkTime: 0.0,
      szContext: nullptr);
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.30000001, szContext: nullptr);
    if ( (this->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this, a2);
    this->m_SelfMoveMonitor.m_vMark.x = this->m_vecAbsOrigin.x;
    this->m_SelfMoveMonitor.m_vMark.y = this->m_vecAbsOrigin.y;
    z = this->m_vecAbsOrigin.z;
    this->m_SelfMoveMonitor.m_flMarkTolerance = 60.0;
    this->m_SelfMoveMonitor.m_vMark.z = z;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049190
// Name: public: CAI_StandoffGoal::CAI_StandoffGoal(void)
// Source: json
//------------------------------------------------------------------------------
CAI_StandoffGoal *__thiscall CAI_StandoffGoal::CAI_StandoffGoal(CAI_StandoffGoal *this)
{
  CAI_GoalEntity::CAI_GoalEntity(this);
  this->CAI_GoalEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_StandoffGoal_vtbl *)&CAI_StandoffGoal::`vftable'{for `CBaseEntity'};
  this->CAI_GoalEntity::IEntityListener::__vftable = (IEntityListener_vtbl *)&CAI_StandoffGoal::`vftable'{for `IEntityListener'};
  this->m_aggressiveness = AGGR_MEDIUM;
  this->m_HintChangeReaction = AIHCR_DEFAULT_AI;
  this->m_bAbandonIfEnemyHides = false;
  *(_WORD *)&this->m_fPlayerIsBattleline = 1;
  this->m_customParams = AI_DEFAULT_STANDOFF_PARAMS;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10049220
// Name: public: virtual void CAI_StandoffGoal::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_StandoffGoal::InputActivate(CAI_StandoffGoal *this, inputdata_t *inputdata)
{
  CAI_StandoffGoal::Aggressiveness_t m_aggressiveness; // eax

  if ( this->m_aggressiveness >= (unsigned int)(AGGR_VERY_HIGH|AGGR_MEDIUM) )
  {
    DevMsg(a1: "Invalid aggressiveness value %d\n", this->m_aggressiveness);
    m_aggressiveness = this->m_aggressiveness;
    if ( m_aggressiveness < AGGR_VERY_LOW )
    {
      this->m_aggressiveness = AGGR_VERY_LOW;
      CAI_GoalEntity::InputActivate(this, inputdata);
      return;
    }
    if ( m_aggressiveness > AGGR_VERY_HIGH )
      this->m_aggressiveness = AGGR_VERY_HIGH;
  }
  CAI_GoalEntity::InputActivate(this, inputdata);
}

//------------------------------------------------------------------------------
// Address: 0x10049290
// Name: public: virtual void CAI_StandoffGoal::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_StandoffGoal::InputDeactivate(CAI_StandoffGoal *this, inputdata_t *inputdata)
{
  CAI_StandoffGoal::Aggressiveness_t m_aggressiveness; // eax

  if ( this->m_aggressiveness >= (unsigned int)(AGGR_VERY_HIGH|AGGR_MEDIUM) )
  {
    DevMsg(a1: "Invalid aggressiveness value %d\n", this->m_aggressiveness);
    m_aggressiveness = this->m_aggressiveness;
    if ( m_aggressiveness < AGGR_VERY_LOW )
    {
      this->m_aggressiveness = AGGR_VERY_LOW;
      CAI_GoalEntity::InputDeactivate(this, inputdata);
      return;
    }
    if ( m_aggressiveness > AGGR_VERY_HIGH )
      this->m_aggressiveness = AGGR_VERY_HIGH;
  }
  CAI_GoalEntity::InputDeactivate(this, inputdata);
}

//------------------------------------------------------------------------------
// Address: 0x10049300
// Name: public: virtual void CAI_StandoffGoal::EnableGoal(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_StandoffGoal::EnableGoal(CAI_StandoffGoal *this, CAI_StandoffBehavior *pAI)
{
  CAI_StandoffBehavior *v3; // esi

  if ( CAI_BaseNPC::GetBehavior<CAI_StandoffBehavior>(this: (CAI_BaseNPC *)pAI, ppBehavior: &pAI) != 0 )
  {
    v3 = pAI;
    if ( !pAI->m_fActive )
    {
      pAI->m_pOuter->SpeakSentence(this: pAI->m_pOuter, a2: 1000);
      v3->m_fActive = true;
      CAI_BehaviorBase::NotifyChangeBehaviorStatus(this: v3, fCanFinishSchedule: false);
    }
    CAI_StandoffGoal::SetBehaviorParams(this, pBehavior: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10049350
// Name: public: virtual void CAI_StandoffGoal::DisableGoal(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_StandoffGoal::DisableGoal(CAI_StandoffGoal *this, CAI_StandoffBehavior *pAI)
{
  CAI_StandoffBehavior *v3; // esi

  if ( CAI_BaseNPC::GetBehavior<CAI_StandoffBehavior>(this: (CAI_BaseNPC *)pAI, ppBehavior: &pAI) != 0 )
  {
    v3 = pAI;
    if ( pAI->m_fActive )
    {
      pAI->m_pOuter->SpeakSentence(this: pAI->m_pOuter, a2: 1001);
      v3->m_fActive = false;
      CAI_BehaviorBase::NotifyChangeBehaviorStatus(this: v3, fCanFinishSchedule: false);
    }
    CAI_StandoffGoal::SetBehaviorParams(this, pBehavior: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FB980
// Name: CAI_BattleLine_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_BattleLine_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_BattleLine>();
  CAI_BattleLine_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB990
// Name: AI_StandoffParams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_StandoffParams_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AI_StandoffParams_t>();
  AI_StandoffParams_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB9A0
// Name: CAI_StandoffBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_StandoffBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_StandoffBehavior>();
  CAI_StandoffBehavior_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FBA00
// Name: CAI_StandoffGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_StandoffGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_StandoffGoal>();
  CAI_StandoffGoal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10048D40
// Name: class CAI_BattleLine __near * _CreateEntityTemplate<class CAI_BattleLine>(class CAI_BattleLine __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_BattleLine *__cdecl _CreateEntityTemplate<CAI_BattleLine>(CAI_BattleLine *newEnt, const char *className)
{
  CBaseEntity *v2; // eax
  _DWORD *v3; // esi
  void (__thiscall *v4)(_DWORD *, const char *); // edx

  v2 = (CBaseEntity *)CBaseEntity::operator new(stAllocateBlock: 0x36Cu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseEntity::CBaseEntity(this: v2, bServerOnly: false);
    *v3 = &CAI_BattleLine::`vftable';
    v4 = *(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112);
    v3[215] = 0;
    v3[216] = 0;
    v3[217] = 0;
    v3[218] = -1082130432;
    v4(a1: v3, a2: className);
    return (CAI_BattleLine *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FB9B0
// Name: _dynamic_initializer_for__CAI_StandoffBehavior::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_StandoffBehavior::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_StandoffBehavior::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_StandoffBehavior::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CAI_StandoffBehavior::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x103FB9E0
// Name: _dynamic_initializer_for__ai_goal_standoff__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_goal_standoff__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_StandoffGoal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_goal_standoff,
           a3: "ai_goal_standoff");
}
