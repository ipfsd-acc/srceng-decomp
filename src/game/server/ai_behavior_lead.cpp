// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_behavior_lead.cpp
// Functions: 20
// ============================================================

#include "game\server\ai_behavior_lead.h"

//------------------------------------------------------------------------------
// Address: 0x100473C0
// Name: public: virtual struct datamap_t __near * CAI_LeadGoal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_LeadGoal::GetDataDescMap(CAI_LeadGoal *this)
{
  return &CAI_LeadGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100473D0
// Name: private: void CAI_LeadGoal::InputSetFailure(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_LeadGoal::InputSetFailure(CAI_LeadGoal *this, inputdata_t *inputdata)
{
  DevMsg(a1: "SetFailure unimplemented\n");
}

//------------------------------------------------------------------------------
// Address: 0x100473E0
// Name: private: virtual void CAI_LeadGoal::OnEvent(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_LeadGoal::OnEvent(CAI_LeadGoal *this, int event)
{
  COutputEvent *p_m_bRegistered; // eax

  p_m_bRegistered = nullptr;
  switch ( event )
  {
    case 0:
      p_m_bRegistered = (COutputEvent *)&this->m_Network.m_TimerEvent.m_bRegistered;
      goto LABEL_8;
    case 1:
      p_m_bRegistered = (COutputEvent *)&this->m_nLastThinkTick;
      goto LABEL_9;
    case 2:
      p_m_bRegistered = (COutputEvent *)&this->m_aThinkFunctions.m_pElements;
      goto LABEL_9;
    case 3:
      p_m_bRegistered = (COutputEvent *)&this->m_iszResponseContext;
      goto LABEL_9;
    case 4:
      p_m_bRegistered = (COutputEvent *)&this->m_nRenderFX;
      goto LABEL_9;
    default:
      if ( event != 0 )
        return;
LABEL_8:
      LOBYTE(this->m_pfnMoveDone) = 1;
LABEL_9:
      if ( p_m_bRegistered != nullptr )
        COutputEvent::FireOutput(
          this: p_m_bRegistered,
          pActivator: (CAI_LeadGoal *)((char *)this - 904),
          pCaller: (CAI_LeadGoal *)((char *)this - 904),
          fDelay: 0.0);
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047460
// Name: public: virtual char const __near * CAI_LeadGoal::GetConceptModifiers(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_LeadGoal::GetConceptModifiers(CAI_LeadGoal *this, const char *pszConcept)
{
  const char *result; // eax

  result = (const char *)LODWORD(this->m_Network.m_PVSInfo.m_vCenter[2]);
  if ( result == nullptr || *result == 0 || strcmp(pszConcept, "TLK_LEAD_START") != 0 )
  {
    result = *(const char **)this->m_Network.m_PVSInfo.m_pClustersInline;
    if ( result == nullptr || *result == 0 || strcmp(pszConcept, "TLK_LEAD_ATTRACTPLAYER") != 0 )
    {
      result = *(const char **)&this->m_Network.m_PVSInfo.m_pClustersInline[2];
      if ( result == nullptr || *result == 0 || strcmp(pszConcept, "TLK_LEAD_WAITOVER") != 0 )
      {
        result = (const char *)this->m_Network.m_pServerClass;
        if ( result == nullptr || *result == 0 || strcmp(pszConcept, "TLK_LEAD_ARRIVAL") != 0 )
        {
          result = (const char *)this->m_Network.m_TimerEvent.m_pEventMgr;
          if ( result == nullptr || *result == 0 || strcmp(pszConcept, "TLK_LEAD_SUCCESS") != 0 )
          {
            result = (const char *)LODWORD(this->m_Network.m_TimerEvent.m_flNextEventTime);
            if ( result == nullptr || *result == 0 || strcmp(pszConcept, "lead_fail") != 0 )
            {
              result = (const char *)LODWORD(this->m_Network.m_TimerEvent.m_flUpdateInterval);
              if ( result == nullptr || *result == 0 || strcmp(pszConcept, "TLK_LEAD_RETRIEVE") != 0 )
              {
                result = (const char *)this->m_Network.m_TimerEvent.m_pCallback;
                if ( result == nullptr || *result == 0 || strcmp(pszConcept, "TLK_LEAD_COMINGBACK") != 0 )
                {
                  if ( LOBYTE(this->m_pfnMoveDone) == 0 )
                    return nullptr;
                  result = (const char *)this->m_Network.m_hParent.m_Index;
                  if ( result == nullptr || *result == 0 )
                    return nullptr;
                }
              }
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10047690
// Name: private: virtual struct datamap_t __near * CAI_LeadGoal_Weapon::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_LeadGoal_Weapon::GetDataDescMap(CAI_LeadGoal_Weapon *this)
{
  return &CAI_LeadGoal_Weapon::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100476A0
// Name: public: virtual char const __near * CAI_LeadGoal_Weapon::GetConceptModifiers(char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_LeadGoal_Weapon::GetConceptModifiers(CAI_LeadGoal_Weapon *this, const char *pszConcept)
{
  const char *result; // eax

  result = (const char *)this->m_pParent.m_Index;
  if ( result == nullptr || *result == 0 || strcmp(pszConcept, "TLK_LEAD_MISSING_WEAPON") != 0 )
    return CAI_LeadGoal::GetConceptModifiers(this, pszConcept);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10047780
// Name: public: bool CAI_LeadBehavior::Connect(class CAI_LeadBehaviorHandler __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_LeadBehavior::Connect(CAI_LeadBehavior *this, CAI_LeadBehaviorHandler *pSink)
{
  void *v3; // eax
  unsigned int m_Index; // eax

  this->m_pSink = pSink;
  v3 = __RTDynamicCast(
         inptr: pSink,
         VfDelta: 0,
         SrcType: &CAI_LeadBehaviorHandler `RTTI Type Descriptor',
         TargetType: &CBaseEntity `RTTI Type Descriptor',
         isReference: 0);
  if ( v3 != nullptr )
    this->m_hSinkImplementor.m_Index = *(_DWORD *)(*(int (__thiscall **)(void *))(*(_DWORD *)v3 + 8))(a1: v3);
  else
    this->m_hSinkImplementor.m_Index = -1;
  m_Index = this->m_hSinkImplementor.m_Index;
  if ( m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    _DevMsg(
      a1: 2,
      a2: "Note: CAI_LeadBehaviorHandler connected to a sink that isn't an entity. Manual fixup on load will be necessary\n");
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10047820
// Name: public: bool CAI_LeadBehavior::SetGoal(struct AI_LeadArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_LeadBehavior::SetGoal(CAI_LeadBehavior *this, const AI_LeadArgs_t *args)
{
  CBaseEntity *EntityByName; // eax
  float y; // xmm0_4
  float flLeadDistance; // xmm0_4
  float flRetrieveDistance; // xmm0_4
  float flSuccessDistance; // xmm0_4
  const char *pszWaitPoint; // edi
  CBaseEntity *v10; // eax

  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: args->pszGoal,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName == nullptr )
    return 0;
  this->m_args = *args;
  this->m_goal.x = EntityByName->m_vecOrigin.m_Value.x;
  this->m_goal.y = EntityByName->m_vecOrigin.m_Value.y;
  this->m_goal.z = EntityByName->m_vecOrigin.m_Value.z;
  if ( (args->flags & 4) != 0 )
    y = EntityByName->m_angRotation.m_Value.y;
  else
    y = -1.0;
  this->m_goalyaw = y;
  this->m_waitpoint = vec3_origin;
  this->m_waitdistance = args->flWaitDistance;
  flLeadDistance = args->flLeadDistance;
  if ( flLeadDistance == 0.0 )
    flLeadDistance = 64.0;
  this->m_leaddistance = flLeadDistance;
  if ( args->flRetrieveDistance == 0.0 )
    flRetrieveDistance = flLeadDistance + 24.0;
  else
    flRetrieveDistance = args->flRetrieveDistance;
  this->m_retrievedistance = flRetrieveDistance;
  flSuccessDistance = args->flSuccessDistance;
  if ( flSuccessDistance == 0.0 )
    flSuccessDistance = 0.0;
  this->m_successdistance = flSuccessDistance;
  this->m_run = args->bRun;
  this->m_gagleader = args->bGagLeader;
  this->m_hasspokenstart = args->bDontSpeakStart;
  *(_WORD *)&this->m_hasspokenarrival = 0;
  this->m_flSpeakNextNagTime = 0.0;
  this->m_flWeaponSafetyTimeOut = 0.0;
  this->m_flNextLeadIdle = gpGlobals->curtime + 10.0;
  this->m_bInitialAheadTest = true;
  pszWaitPoint = args->pszWaitPoint;
  if ( pszWaitPoint != nullptr && *pszWaitPoint != 0 )
  {
    v10 = CGlobalEntityList::FindEntityByName(
            this: &gEntList,
            pStartEntity: nullptr,
            szName: pszWaitPoint,
            pSearchingEntity: nullptr,
            pActivator: nullptr,
            pCaller: nullptr,
            pFilter: nullptr);
    if ( v10 != nullptr )
    {
      this->m_waitpoint.x = v10->m_vecOrigin.m_Value.x;
      this->m_waitpoint.y = v10->m_vecOrigin.m_Value.y;
      this->m_waitpoint.z = v10->m_vecOrigin.m_Value.z;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100479F0
// Name: public: virtual void CAI_LeadGoal::InputDeactivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_LeadGoal::InputDeactivate(CAI_LeadGoal *this, inputdata_t *inputdata)
{
  CAI_BaseNPC *Actor; // eax
  inputdata_t *v4; // ecx

  CAI_GoalEntity::InputDeactivate(this, inputdata);
  Actor = CAI_GoalEntity::GetActor(this, iActor: 0);
  if ( Actor != nullptr
    && CAI_BaseNPC::GetBehavior<CAI_LeadBehavior>(this: Actor, ppBehavior: (CAI_LeadBehavior **)&inputdata) != 0 )
  {
    v4 = inputdata;
    if ( inputdata != nullptr )
    {
      inputdata[3].pCaller = (CBaseEntity *)LODWORD(vec3_origin.x);
      v4[3].value.iVal = LODWORD(vec3_origin.y);
      v4[3].value.vecVal[1] = vec3_origin.z;
      *(Vector *)&v4[3].value.eVal.m_Index = vec3_origin;
      v4[4].value.vecVal[2] = 0.0;
      v4[2].nOutputID = 0;
      CAI_BehaviorBase::NotifyChangeBehaviorStatus(this: (CAI_BehaviorBase *)v4, fCanFinishSchedule: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047A90
// Name: private: void CAI_LeadGoal::InputSetSuccess(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_LeadGoal::InputSetSuccess(CAI_LeadGoal *this, inputdata_t *inputdata)
{
  CAI_BaseNPC *Actor; // eax
  CAI_LeadBehavior *v3; // esi
  CAI_ClassScheduleIdSpace *v4; // eax
  int v5; // eax
  CAI_LeadBehavior *ppBehavior; // [esp+0h] [ebp-4h] BYREF

  ppBehavior = (CAI_LeadBehavior *)this;
  Actor = CAI_GoalEntity::GetActor(this, iActor: 0);
  if ( Actor != nullptr && CAI_BaseNPC::GetBehavior<CAI_LeadBehavior>(this: Actor, &ppBehavior) != 0 )
  {
    v3 = ppBehavior;
    if ( ppBehavior != nullptr )
    {
      v4 = ppBehavior->GetClassScheduleIdSpace(this: ppBehavior);
      v5 = CAI_LocalIdSpace::LocalToGlobal(this: &v4->m_ConditionIds, localID: 100004);
      CAI_BaseNPC::SetCondition(this: v3->m_pOuter, iCondition: v5);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047AE0
// Name: public: virtual void CAI_LeadGoal::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_LeadGoal::InputActivate(CAI_LeadGoal *this, inputdata_t *inputdata)
{
  CAI_BaseNPC *Actor; // eax
  CAI_LeadBehavior *v4; // edi
  float m_flLeadDistance; // xmm1_4
  unsigned int m_Value; // edx
  bool m_bRun; // al
  float m_flWaitDistance; // xmm0_4
  bool m_bStopScenesWhenPlayerLost; // cl
  int m_iRetrieveWaitForSpeak; // edx
  int m_iComingBackWaitForSpeak; // eax
  bool m_bGagLeader; // cl
  float m_flRetrieveDistance; // xmm0_4
  float m_flSuccessDistance; // xmm0_4
  CAI_LeadBehaviorHandler *v15; // esi
  AI_LeadArgs_t leadArgs; // [esp+8h] [ebp-30h] BYREF

  CAI_GoalEntity::InputActivate(this, inputdata);
  Actor = CAI_GoalEntity::GetActor(this, iActor: 0);
  if ( Actor != nullptr
    && CAI_BaseNPC::GetBehavior<CAI_LeadBehavior>(this: Actor, ppBehavior: (CAI_LeadBehavior **)&inputdata) != 0
    && (v4 = (CAI_LeadBehavior *)inputdata, inputdata != nullptr) )
  {
    m_flLeadDistance = this->m_flLeadDistance;
    if ( (float)(m_flLeadDistance + 24.0) > this->m_flRetrieveDistance )
      this->m_flRetrieveDistance = m_flLeadDistance + 24.0;
    leadArgs.pszGoal = this->m_iszGoal.pszValue;
    if ( leadArgs.pszGoal == nullptr )
      leadArgs.pszGoal = locale;
    leadArgs.pszWaitPoint = this->m_iszWaitPointName.pszValue;
    if ( leadArgs.pszWaitPoint == nullptr )
      leadArgs.pszWaitPoint = locale;
    m_Value = this->m_spawnflags.m_Value;
    m_bRun = this->m_bRun;
    m_flWaitDistance = this->m_flWaitDistance;
    leadArgs.iRetrievePlayer = this->m_iRetrievePlayer;
    m_bStopScenesWhenPlayerLost = this->m_bStopScenesWhenPlayerLost;
    leadArgs.flags = m_Value;
    m_iRetrieveWaitForSpeak = this->m_iRetrieveWaitForSpeak;
    leadArgs.bRun = m_bRun;
    m_iComingBackWaitForSpeak = this->m_iComingBackWaitForSpeak;
    leadArgs.iRetrieveWaitForSpeak = m_iRetrieveWaitForSpeak;
    LOBYTE(m_iRetrieveWaitForSpeak) = this->m_bDontSpeakStart;
    leadArgs.bStopScenesWhenPlayerLost = m_bStopScenesWhenPlayerLost;
    m_bGagLeader = this->m_bGagLeader;
    leadArgs.flWaitDistance = m_flWaitDistance;
    m_flRetrieveDistance = this->m_flRetrieveDistance;
    leadArgs.iComingBackWaitForSpeak = m_iComingBackWaitForSpeak;
    LOBYTE(m_iComingBackWaitForSpeak) = this->m_bLeadDuringCombat;
    leadArgs.bDontSpeakStart = m_iRetrieveWaitForSpeak;
    leadArgs.flRetrieveDistance = m_flRetrieveDistance;
    m_flSuccessDistance = this->m_flSuccessDistance;
    leadArgs.bGagLeader = m_bGagLeader;
    leadArgs.flLeadDistance = m_flLeadDistance;
    leadArgs.flSuccessDistance = m_flSuccessDistance;
    leadArgs.bLeadDuringCombat = m_iComingBackWaitForSpeak;
    v15 = &this->CAI_LeadBehaviorHandler;
    if ( CAI_LeadBehavior::SetGoal(this: v4, args: &leadArgs) != 0 )
    {
      CAI_BaseNPC::SetCondition(this: v4->m_pOuter, iCondition: 25);
      CAI_LeadBehavior::Connect(this: v4, pSink: v15);
      CAI_BehaviorBase::NotifyChangeBehaviorStatus(this: v4, fCanFinishSchedule: false);
    }
    else
    {
      DevMsg(a1: "*** Warning! LeadPlayer() has a NULL Goal Ent\n");
    }
  }
  else
  {
    DevMsg(a1: "Lead goal entity activated for an NPC that doesn't have the lead behavior\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047C50
// Name: public: virtual void CAI_LeadGoal_Weapon::InputActivate(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_LeadGoal_Weapon::InputActivate(CAI_LeadGoal_Weapon *this, inputdata_t *inputdata)
{
  CAI_BaseNPC *Actor; // eax
  inputdata_t *v4; // eax

  CAI_LeadGoal::InputActivate(this, inputdata);
  Actor = CAI_GoalEntity::GetActor(this, iActor: 0);
  if ( Actor != nullptr
    && CAI_BaseNPC::GetBehavior<CAI_LeadBehavior>(this: Actor, ppBehavior: (CAI_LeadBehavior **)&inputdata) != 0 )
  {
    v4 = inputdata;
    if ( inputdata != nullptr )
    {
      LODWORD(inputdata[4].value.vecVal[2]) = this->m_iszWeaponName.pszValue;
      *(float *)&v4[5].pActivator = gpGlobals->curtime + 60.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10047CB0
// Name: public: CAI_LeadGoal::CAI_LeadGoal(void)
// Source: json
//------------------------------------------------------------------------------
CAI_LeadGoal *__thiscall CAI_LeadGoal::CAI_LeadGoal(CAI_LeadGoal *this)
{
  CAI_GoalEntity::CAI_GoalEntity(this);
  this->CAI_LeadBehaviorHandler::__vftable = (CAI_LeadBehaviorHandler_vtbl *)&CAI_LeadBehaviorHandler::`vftable';
  this->m_fArrived = false;
  this->CAI_GoalEntity::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_LeadGoal_vtbl *)&CAI_LeadGoal::`vftable'{for `CBaseEntity'};
  this->CAI_GoalEntity::IEntityListener::__vftable = (IEntityListener_vtbl *)&CAI_LeadGoal::`vftable'{for `IEntityListener'};
  this->CAI_LeadBehaviorHandler::__vftable = (CAI_LeadBehaviorHandler_vtbl *)&CAI_LeadGoal::`vftable';
  this->m_OnArrival.m_Value.iVal = 0;
  this->m_OnArrival.m_Value.eVal.m_Index = -1;
  this->m_OnArrival.m_Value.fieldType = FIELD_VOID;
  this->m_OnArrivalDone.m_Value.iVal = 0;
  this->m_OnArrivalDone.m_Value.eVal.m_Index = -1;
  this->m_OnArrivalDone.m_Value.fieldType = FIELD_VOID;
  this->m_OnSuccess.m_Value.iVal = 0;
  this->m_OnSuccess.m_Value.eVal.m_Index = -1;
  this->m_OnSuccess.m_Value.fieldType = FIELD_VOID;
  this->m_OnFailure.m_Value.iVal = 0;
  this->m_OnFailure.m_Value.eVal.m_Index = -1;
  this->m_OnFailure.m_Value.fieldType = FIELD_VOID;
  this->m_OnDone.m_Value.iVal = 0;
  this->m_OnDone.m_Value.eVal.m_Index = -1;
  this->m_OnDone.m_Value.fieldType = FIELD_VOID;
  this->m_iRetrieveWaitForSpeak = 0;
  this->m_iComingBackWaitForSpeak = 0;
  *(_DWORD *)&this->m_bStopScenesWhenPlayerLost = 0;
  this->m_iRetrievePlayer = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x103FB810
// Name: AI_LeadArgs_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AI_LeadArgs_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AI_LeadArgs_t>();
  AI_LeadArgs_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB820
// Name: CAI_LeadBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_LeadBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_LeadBehavior>();
  CAI_LeadBehavior_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB880
// Name: CAI_LeadGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_LeadGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_LeadGoal>();
  CAI_LeadGoal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB8B0
// Name: CAI_LeadGoal_Weapon_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_LeadGoal_Weapon_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_LeadGoal_Weapon>();
  CAI_LeadGoal_Weapon_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB830
// Name: _dynamic_initializer_for__CAI_LeadBehavior::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_LeadBehavior::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_LeadBehavior::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_LeadBehavior::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CAI_LeadBehavior::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}

//------------------------------------------------------------------------------
// Address: 0x103FB860
// Name: _dynamic_initializer_for__ai_goal_lead__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_goal_lead__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_LeadGoal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_goal_lead,
           a3: "ai_goal_lead");
}

//------------------------------------------------------------------------------
// Address: 0x103FB890
// Name: _dynamic_initializer_for__ai_goal_lead_weapon__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_goal_lead_weapon__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_LeadGoal_Weapon> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_goal_lead_weapon,
           a3: "ai_goal_lead_weapon");
}
