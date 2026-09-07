// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/genericactor.cpp
// Functions: 131
// ============================================================

#include "game\server\genericactor.h"

//------------------------------------------------------------------------------
// Address: 0x100142E0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::GatherConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::GatherConditions(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  int i; // edi
  CAI_BehaviorBase *v3; // ecx

  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v3 = this->m_Behaviors.m_Memory.m_pMemory[i];
    if ( v3 != this->m_pPrimaryBehavior )
      v3->GatherConditionsNotActive(this: v3);
  }
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->GatherConditions(this: this->m_pPrimaryBehavior);
  else
    CAI_BaseNPC::GatherConditions(this);
}

//------------------------------------------------------------------------------
// Address: 0x100184A0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BuildScheduleTestBits(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BuildScheduleTestBits(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  int i; // edi
  CAI_BehaviorBase *v3; // ecx

  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v3 = this->m_Behaviors.m_Memory.m_pMemory[i];
    if ( v3 != this->m_pPrimaryBehavior )
      v3->BuildScheduleTestBitsNotActive(this: v3);
  }
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->BuildScheduleTestBits(this: this->m_pPrimaryBehavior);
  CAI_BaseNPC::OnSetSchedule((vgui::Panel *)this);
}

//------------------------------------------------------------------------------
// Address: 0x1002D6D0
// Name: public: virtual float CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_GetMaxTacticalLateralMovement(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_GetMaxTacticalLateralMovement(CAI_BaseNPC *this)
{
  return -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10079D50
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::PrescheduleThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::PrescheduleThink(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->PrescheduleThink(this: this->m_pPrimaryBehavior);
  else
    CAI_BaseNPC::PrescheduleThink(this);
}

//------------------------------------------------------------------------------
// Address: 0x10079D70
// Name: public: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::OnTakeDamage_Alive(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAI_BehaviorHost<CAI_BaseNPC>::OnTakeDamage_Alive@<eax>(
        CAI_BehaviorHost<CAI_BaseNPC> *this@<ecx>,
        int a2@<ebx>,
        const CTakeDamageInfo *a1)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->OnTakeDamage_Alive(this: this->m_pPrimaryBehavior, a2: a1);
  else
    return CAI_BaseNPC::OnTakeDamage_Alive(this, a2, info: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10079D90
// Name: public: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::SelectSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BehaviorHost<CAI_BaseNPC>::SelectSchedule(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // esi
  int v2; // edi
  int v3; // eax

  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  this->m_bCalledBehaviorSelectSchedule = true;
  if ( m_pPrimaryBehavior == nullptr )
    return CAI_BaseNPC::SelectSchedule(this);
  v2 = m_pPrimaryBehavior->SelectSchedule(this: m_pPrimaryBehavior);
  if ( !m_pPrimaryBehavior->IsBehaviorSchedule(this: m_pPrimaryBehavior, a2: v2) )
    return v2;
  v3 = (int)m_pPrimaryBehavior->GetClassScheduleIdSpace(this: m_pPrimaryBehavior);
  return CAI_LocalIdSpace::LocalToGlobal(this: (CAI_LocalIdSpace *)(v3 + 4), localID: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10079DF0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnStartSchedule(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnStartSchedule(CAI_BehaviorHost<CAI_BaseNPC> *this, int scheduleType)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // esi
  int v3; // eax
  int v4; // eax

  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  if ( m_pPrimaryBehavior != nullptr )
  {
    if ( scheduleType >= 1000000000 || scheduleType == -1 )
    {
      v3 = (int)m_pPrimaryBehavior->GetClassScheduleIdSpace(this: m_pPrimaryBehavior);
      v4 = CAI_LocalIdSpace::GlobalToLocal(this: (CAI_LocalIdSpace *)(v3 + 4), globalID: scheduleType);
      m_pPrimaryBehavior->OnStartSchedule(this: m_pPrimaryBehavior, a2: v4);
    }
    else
    {
      m_pPrimaryBehavior->OnStartSchedule(this: m_pPrimaryBehavior, a2: scheduleType);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10079E50
// Name: public: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::TranslateSchedule(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BehaviorHost<CAI_BaseNPC>::TranslateSchedule(CAI_BehaviorHost<CAI_BaseNPC> *this, int scheduleType)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // esi
  int v3; // eax
  int v4; // eax

  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  if ( m_pPrimaryBehavior == nullptr )
    return CAI_BaseNPC::TranslateSchedule(this, scheduleType);
  if ( scheduleType < 1000000000 && scheduleType != -1 )
    return m_pPrimaryBehavior->TranslateSchedule(this: m_pPrimaryBehavior, a2: scheduleType);
  v3 = (int)m_pPrimaryBehavior->GetClassScheduleIdSpace(this: m_pPrimaryBehavior);
  v4 = CAI_LocalIdSpace::GlobalToLocal(this: (CAI_LocalIdSpace *)(v3 + 4), globalID: scheduleType);
  return m_pPrimaryBehavior->TranslateSchedule(this: m_pPrimaryBehavior, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10079EC0
// Name: protected: virtual void CAI_ExpresserHost<class CAI_BaseHumanoid>::ModifyOrAppendCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserHost<CAI_BaseHumanoid>::ModifyOrAppendCriteria(
        CAI_ExpresserHost<CAI_BaseHumanoid> *this,
        ResponseRules::CriteriaSet *criteriaSet)
{
  CAI_BaseNPC *v3; // eax

  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->ModifyOrAppendCriteria(this: this->m_pPrimaryBehavior, a2: criteriaSet);
  else
    CAI_BaseNPC::ModifyOrAppendCriteria(this, set: criteriaSet);
  if ( this->MyNPCPointer(this) != nullptr )
  {
    v3 = this->MyNPCPointer(this);
    CAI_ExpresserHost_NPC_DoModifyOrAppendCriteria(pSpeaker: v3, set: criteriaSet);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1007A750
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::Event_Killed(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const CTakeDamageInfo *info)
{
  int i; // esi
  CAI_BehaviorBase *v4; // ecx

  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v4 = this->m_Behaviors.m_Memory.m_pMemory[i];
    v4->Event_Killed(this: v4, a2: info);
  }
  CAI_BaseNPC::Event_Killed(this, a2: (int)info, a3: (int)this, info);
}

//------------------------------------------------------------------------------
// Address: 0x1007A7A0
// Name: public: bool CAI_ExpresserHost<class CAI_BaseHumanoid>::SpeakDispatchResponse(class CAI_Concept,class ResponseRules::CRR_Response __near *,class ResponseRules::CriteriaSet __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_ExpresserHost<CAI_BaseHumanoid>::SpeakDispatchResponse(
        CAI_ExpresserHost<CAI_BaseHumanoid> *this,
        CAI_Concept concept,
        ResponseRules::CRR_Response *response,
        ResponseRules::CriteriaSet *criteria)
{
  CAI_Expresser *v5; // eax
  ResponseRules::CRR_Response *v6; // edi
  int v8; // [esp-Ch] [ebp-14h]

  v5 = this->GetExpresser(this);
  v6 = response;
  if ( !v5->SpeakDispatchResponse(this: v5, a2: &concept, a3: response, a4: criteria, a5: nullptr) )
    return 0;
  LOWORD(v8) = concept.m_iConcept.m_Id;
  ((void (__thiscall *)(CAI_ExpresserHost<CAI_BaseHumanoid> *, int, unsigned int, ResponseRules::CRR_Response *))this->PostSpeakDispatchResponse)(
    a1: this,
    a2: v8,
    a3: concept.m_hSpeaker.m_Index,
    a4: v6);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100CF8A0
// Name: public: enum LocalFlexController_t CFlextalkActor::LookupFlex(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CFlextalkActor::LookupFlex(CFlexCycler *this, const char *szTarget)
{
  LocalFlexController_t v3; // esi
  const char *FlexControllerName; // eax

  v3 = DUMMY_NULL_FLEX_CONTROLLER;
  if ( CBaseAnimating::GetNumFlexControllers(this) <= 0 )
    return -1;
  while ( 1 )
  {
    FlexControllerName = CBaseAnimating::GetFlexControllerName(this, iFlexController: v3);
    if ( _V_stricmp(s1: szTarget, s2: FlexControllerName) == 0 )
      break;
    if ( ++v3 >= CBaseAnimating::GetNumFlexControllers(this) )
      return -1;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x100D7850
// Name: public: virtual void CAI_ExpresserHost<class CBasePlayer>::NoteSpeaking(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserHost<CBasePlayer>::NoteSpeaking(
        CAI_ExpresserHost<CBasePlayer> *this,
        float duration,
        float delay)
{
  CAI_Expresser *v3; // eax

  v3 = this->GetExpresser(this);
  CAI_Expresser::NoteSpeaking(this: v3, duration, delay);
}

//------------------------------------------------------------------------------
// Address: 0x100D7880
// Name: public: virtual bool CAI_ExpresserHost<class CBasePlayer>::Speak(class CAI_Concept,char const __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ExpresserHost<CBasePlayer>::Speak(
        CAI_ExpresserHost<CBasePlayer> *this,
        CAI_Concept concept,
        const char *modifiers,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  CAI_Expresser *v6; // eax
  const char *v8; // [esp-10h] [ebp-10h]
  char *v9; // [esp-Ch] [ebp-Ch]
  unsigned int v10; // [esp-8h] [ebp-8h]
  IRecipientFilter *v11; // [esp-4h] [ebp-4h]

  v11 = filter;
  v10 = bufsize;
  v9 = pszOutResponseChosen;
  v8 = modifiers;
  v6 = this->GetExpresser(this);
  return CAI_Expresser::Speak(this: v6, &concept, modifiers: v8, pszOutResponseChosen: v9, bufsize: v10, filter: v11);
}

//------------------------------------------------------------------------------
// Address: 0x100D7BB0
// Name: protected: virtual void CAI_ExpresserHost<class CBasePlayer>::DispatchResponse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserHost<CBasePlayer>::DispatchResponse(
        CAI_ExpresserHost<CBasePlayer> *this,
        const char *conceptName)
{
  int v3; // [esp-18h] [ebp-20h] BYREF
  int v4; // [esp-10h] [ebp-18h]
  int v5; // [esp-Ch] [ebp-14h]
  int v6; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]

  v7 = 0;
  v6 = 0;
  v5 = 0;
  v4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: (ResponseRules::CRR_Concept *)&v3, fromString: conceptName);
  ((void (__thiscall *)(CAI_ExpresserHost<CBasePlayer> *, int, int, int, int, int, int))this->Speak)(
    a1: this,
    a2: v3,
    a3: -1,
    a4: v4,
    a5: v5,
    a6: v6,
    a7: v7);
}

//------------------------------------------------------------------------------
// Address: 0x100D7DC0
// Name: public: virtual bool CAI_ExpresserHost<class CBasePlayer>::Speak(class CAI_Concept,class ResponseRules::CriteriaSet __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ExpresserHost<CBasePlayer>::Speak(
        CAI_ExpresserHost<CBasePlayer> *this,
        CAI_Concept concept,
        ResponseRules::CriteriaSet *pCriteria,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  CAI_Expresser *v7; // edi
  const CBaseHandle *v8; // eax
  ResponseRules::CriteriaSet *v9; // esi

  v7 = this->GetExpresser(this);
  v8 = this->GetRefEHandle(this);
  v9 = pCriteria;
  concept.m_hSpeaker = (CHandle<CBaseEntity>)v8->m_Index;
  CAI_Expresser::GatherCriteria(this: v7, outputSet: pCriteria, &concept, modifiers: nullptr);
  return CAI_Expresser::Speak(this: v7, &concept, criteria: v9, pszOutResponseChosen, bufsize, filter);
}

//------------------------------------------------------------------------------
// Address: 0x1012A830
// Name: public: virtual void CAI_ExpresserHost<class CFlexExpresserShim>::NoteSpeaking(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserHost<CFlexExpresserShim>::NoteSpeaking(
        CAI_ExpresserHost<CFlexExpresserShim> *this,
        float duration,
        float delay)
{
  CAI_Expresser::NoteSpeaking(this: this->m_pExpresser, duration, delay);
}

//------------------------------------------------------------------------------
// Address: 0x1012A860
// Name: public: virtual bool CAI_ExpresserHost<class CFlexExpresserShim>::Speak(class CAI_Concept,char const __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ExpresserHost<CFlexExpresserShim>::Speak(
        CAI_ExpresserHost<CFlexExpresserShim> *this,
        CAI_Concept concept,
        const char *modifiers,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  return CAI_Expresser::Speak(this: this->m_pExpresser, &concept, modifiers, pszOutResponseChosen, bufsize, filter);
}

//------------------------------------------------------------------------------
// Address: 0x1012A890
// Name: protected: virtual void CAI_ExpresserHost<class CFlexExpresserShim>::ModifyOrAppendCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserHost<CFlexExpresserShim>::ModifyOrAppendCriteria(
        CAI_ExpresserHost<CFlexExpresserShim> *this,
        ResponseRules::CriteriaSet *criteriaSet)
{
  CAI_BaseNPC *v3; // eax

  CBaseAnimating::ModifyOrAppendCriteria(this, set: criteriaSet);
  if ( this->MyNPCPointer(this) != nullptr )
  {
    v3 = this->MyNPCPointer(this);
    CAI_ExpresserHost_NPC_DoModifyOrAppendCriteria(pSpeaker: v3, set: criteriaSet);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012A970
// Name: protected: virtual void CAI_ExpresserHost<class CFlexExpresserShim>::DispatchResponse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserHost<CFlexExpresserShim>::DispatchResponse(
        CAI_ExpresserHost<CFlexExpresserShim> *this,
        const char *conceptName)
{
  int v3; // [esp-18h] [ebp-20h] BYREF
  int v4; // [esp-10h] [ebp-18h]
  int v5; // [esp-Ch] [ebp-14h]
  int v6; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]

  v7 = 0;
  v6 = 0;
  v5 = 0;
  v4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: (ResponseRules::CRR_Concept *)&v3, fromString: conceptName);
  ((void (__thiscall *)(CAI_ExpresserHost<CFlexExpresserShim> *, int, int, int, int, int, int))this->Speak)(
    a1: this,
    a2: v3,
    a3: -1,
    a4: v4,
    a5: v5,
    a6: v6,
    a7: v7);
}

//------------------------------------------------------------------------------
// Address: 0x1012AC30
// Name: public: virtual bool CAI_ExpresserHost<class CFlexExpresserShim>::Speak(class CAI_Concept,class ResponseRules::CriteriaSet __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ExpresserHost<CFlexExpresserShim>::Speak(
        CAI_ExpresserHost<CFlexExpresserShim> *this,
        CAI_Concept concept,
        ResponseRules::CriteriaSet *pCriteria,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  CAI_Expresser *m_pExpresser; // esi
  unsigned int *v7; // eax
  ResponseRules::CriteriaSet *v8; // edi

  m_pExpresser = this->m_pExpresser;
  v7 = (unsigned int *)((int (*)(void))this->GetRefEHandle)();
  v8 = pCriteria;
  concept.m_hSpeaker.m_Index = *v7;
  CAI_Expresser::GatherCriteria(this: m_pExpresser, outputSet: pCriteria, &concept, modifiers: nullptr);
  return CAI_Expresser::Speak(this: m_pExpresser, &concept, criteria: v8, pszOutResponseChosen, bufsize, filter);
}

//------------------------------------------------------------------------------
// Address: 0x10153240
// Name: public: virtual struct datamap_t __near * CGenericActor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CGenericActor::GetDataDescMap(CGenericActor *this)
{
  return &CGenericActor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10153250
// Name: public: virtual struct datamap_t __near * CFlextalkActor::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CFlextalkActor::GetDataDescMap(CFlextalkActor *this)
{
  return &CFlextalkActor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10153260
// Name: public: virtual void CGenericActor::HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CGenericActor::HandleAnimEvent(CGenericActor *this, animevent_t *pEvent)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->HandleAnimEvent(this: this->m_pPrimaryBehavior, a2: pEvent);
  else
    CAI_BaseNPC::HandleAnimEvent(this, a2: (CAI_BaseNPC *)&savedregs, pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x10153290
// Name: public: virtual void CGenericActor::Precache(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGenericActor::Precache(CGenericActor *this)
{
  const char *v1; // eax
  CGenericActor *v2; // [esp+0h] [ebp-4h] BYREF

  v2 = this;
  v1 = *(const char **)((int (__thiscall *)(CGenericActor *, CGenericActor **))this->GetModelName)(a1: this, a2: &v2);
  if ( v1 == nullptr )
    v1 = locale;
  CBaseEntity::PrecacheModel(name: v1, bPreload: true);
}

//------------------------------------------------------------------------------
// Address: 0x101532C0
// Name: public: void CFlextalkActor::SetFlexTarget(enum LocalFlexController_t,float)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CFlextalkActor::SetFlexTarget(
        CFlextalkActor *this@<ecx>,
        int a2@<edi>,
        LocalFlexController_t flexnum,
        float value)
{
  LocalFlexController_t v6; // edi
  const char *FlexControllerType; // eax
  double v8; // st7
  float v9; // xmm0_4
  const char *FlexControllerName; // eax
  const char *v11; // eax
  float v12; // [esp+0h] [ebp-18h]
  float v13; // [esp+4h] [ebp-14h]
  const char *pszType; // [esp+14h] [ebp-4h]
  float *flexnuma; // [esp+20h] [ebp+8h]
  float value2a; // [esp+24h] [ebp+Ch]
  float value2; // [esp+24h] [ebp+Ch]

  this->m_flextarget[flexnum] = value;
  pszType = CBaseAnimating::GetFlexControllerType(this, iFlexController: flexnum);
  v6 = DUMMY_NULL_FLEX_CONTROLLER;
  if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
  {
    flexnuma = this->m_flextarget;
    do
    {
      if ( v6 != flexnum )
      {
        FlexControllerType = CBaseAnimating::GetFlexControllerType(this, iFlexController: v6);
        if ( _V_stricmp(s1: pszType, s2: FlexControllerType) == 0 )
          *flexnuma = 0.0;
      }
      ++flexnuma;
      ++v6;
    }
    while ( v6 < CBaseAnimating::GetNumFlexControllers(this) );
  }
  v13 = value + 0.2;
  v12 = value - 0.2;
  v8 = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD, int))random->RandomFloat)(
         a1: random,
         a2: LODWORD(v12),
         a3: LODWORD(v13),
         a4: a2);
  if ( v8 < 0.0 )
  {
    v9 = 0.0;
LABEL_9:
    value2 = v9;
    goto LABEL_10;
  }
  v9 = v8;
  value2a = v8;
  if ( value2a <= 1.0 )
    goto LABEL_9;
  value2 = 1.0;
LABEL_10:
  FlexControllerName = CBaseAnimating::GetFlexControllerName(this, iFlexController: flexnum);
  if ( strncmp(first: "right_", last: FlexControllerName, count: 6u) == 0 )
  {
    this->m_flextarget[flexnum + 1] = value2;
  }
  else
  {
    v11 = CBaseAnimating::GetFlexControllerName(this, iFlexController: flexnum);
    if ( strncmp(first: "left_", last: v11, count: 5u) == 0 )
      *((float *)&this->m_flexnum + flexnum) = value2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153420
// Name: public: bool CAI_BehaviorBase::BridgeSelectFailSchedule(int,int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BehaviorBase::BridgeSelectFailSchedule(
        CAI_BehaviorBase *this,
        int failedSchedule,
        int failedTask,
        int taskFailCode,
        int *pResult)
{
  int (__thiscall *SelectFailSchedule)(CAI_BehaviorBase *, int, int, int); // edx
  int v7; // eax
  int v8; // edi
  CAI_ClassScheduleIdSpace *v9; // eax

  SelectFailSchedule = this->SelectFailSchedule;
  this->m_fOverrode = true;
  v7 = SelectFailSchedule(this, a2: failedSchedule, a3: failedTask, a4: taskFailCode);
  v8 = v7;
  if ( !this->m_fOverrode )
    return 0;
  if ( v7 == 0 )
  {
    _Warning(a1: "An AI behavior is in control but has no recommended schedule\n");
    return 0;
  }
  if ( this->IsBehaviorSchedule(this, a2: v7) )
  {
    v9 = this->GetClassScheduleIdSpace(this);
    *pResult = CAI_LocalIdSpace::LocalToGlobal(this: &v9->m_ScheduleIds, localID: v8);
  }
  else
  {
    *pResult = v8;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101534B0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_PrescheduleThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_PrescheduleThink(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  CAI_BaseNPC::PrescheduleThink(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x101534C0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_OnScheduleChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_OnScheduleChange(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  CAI_BaseNPC::OnScheduleChange(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x101534D0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsCrouching(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsCrouching(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::IsCrouching(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x101534E0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsValidEnemy(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsValidEnemy(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        CBaseEntity *a1)
{
  return CAI_BaseNPC::IsValidEnemy(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288), pEnemy: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101534F0
// Name: public: virtual class CBaseEntity __near * CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_BestEnemy(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_BestEnemy@<eax>(
        CAI_BehaviorHost<CAI_BaseNPC> *this@<ecx>,
        CBaseEntity *a2@<ebx>)
{
  return CAI_BaseNPC::BestEnemy(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288), a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153500
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsCoverPosition(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsCoverPosition(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        const Vector *a2)
{
  return CAI_BaseNPC::IsCoverPosition(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
           vecThreat: a1,
           vecPosition: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153510
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsValidCover(class Vector const __near &,class CAI_Hint const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsValidCover(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        const CAI_Hint *a2)
{
  return CAI_BaseNPC::IsValidCover(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
           vecCoverLocation: a1,
           pHint: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153520
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsValidShootPosition(class Vector const __near &,class CAI_Node __near *,class CAI_Hint const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsValidShootPosition(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        CAI_Node *a2,
        const CAI_Hint *a3)
{
  return CAI_BaseNPC::IsValidShootPosition(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
           vecShootLocation: a1,
           pNode: a2,
           pHint: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10153530
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_WeaponLOSCondition(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_WeaponLOSCondition(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        const Vector *a2,
        BOOL a3)
{
  return CAI_BaseNPC::WeaponLOSCondition(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
           ownerPos: a1,
           targetPos: a2,
           bSetConditions: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10153540
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_OnFriendDamaged(class CBaseCombatCharacter __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_OnFriendDamaged(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        CBaseCombatCharacter *a1,
        CBaseEntity *a2)
{
  CAI_BaseNPC::OnFriendDamaged(
    this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
    pSquadmate: a1,
    pAttacker: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153550
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsInterruptable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsInterruptable(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::IsInterruptable(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x10153560
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsNavigationUrgent(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsNavigationUrgent(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::IsNavigationUrgent(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x10153570
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_ShouldPlayerAvoid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_ShouldPlayerAvoid(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::ShouldPlayerAvoid(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x10153580
// Name: public: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_OnTakeDamage_Alive(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_OnTakeDamage_Alive@<eax>(
        CAI_BehaviorHost<CAI_BaseNPC> *this@<ecx>,
        int a2@<ebx>,
        const CTakeDamageInfo *a1)
{
  return CAI_BaseNPC::OnTakeDamage_Alive(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288), a2, info: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153590
// Name: public: virtual float CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_GetReasonableFacingDist(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_GetReasonableFacingDist(
        CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::GetReasonableFacingDist(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x101535A0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_CanFlinch(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_CanFlinch(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::CanFlinch(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x101535B0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsCrouchedActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsCrouchedActivity(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        Activity a1)
{
  return CAI_BaseNPC::IsCrouchedActivity(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288), activity: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101535C0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_QueryHearSound(class CSound __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_QueryHearSound(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        CSound *a1)
{
  return CAI_BaseNPC::QueryHearSound(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288), pSound: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101535D0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_CanRunAScriptedNPCInteraction(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_CanRunAScriptedNPCInteraction(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        bool a1)
{
  return CAI_BaseNPC::CanRunAScriptedNPCInteraction(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
           bForced: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101535E0
// Name: public: virtual enum Activity CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_GetFlinchActivity(bool,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_GetFlinchActivity(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        bool a1,
        bool a2)
{
  return CAI_BaseNPC::GetFlinchActivity(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
           bHeavyDamage: a1,
           bGesture: a2);
}

//------------------------------------------------------------------------------
// Address: 0x101535F0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_OnCalcBaseMove(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_OnCalcBaseMove(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        AILocalMoveGoal_t *a1,
        float a2,
        AIMoveResult_t *a3)
{
  return CAI_BaseNPC::OnCalcBaseMove(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 4),
           pMoveGoal: a1,
           distClear: a2,
           pResult: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10153620
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_ModifyOrAppendCriteria(class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_ModifyOrAppendCriteria(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        ResponseRules::CriteriaSet *a1)
{
  CAI_BaseNPC::ModifyOrAppendCriteria(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288), set: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153630
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_Teleport(class Vector const __near *,class QAngle const __near *,class Vector const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_Teleport(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        const QAngle *a2,
        const Vector *a3,
        bool a4)
{
  CAI_BaseNPC::Teleport(
    this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
    newPosition: a1,
    newAngles: a2,
    newVelocity: a3,
    bUseSlowHighAccuracyContacts: a4);
}

//------------------------------------------------------------------------------
// Address: 0x10153640
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_HandleAnimEvent(struct animevent_t __near *)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_HandleAnimEvent(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        animevent_t *a1)
{
  int savedregs; // [esp+0h] [ebp+0h] BYREF

  CAI_BaseNPC::HandleAnimEvent(
    this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
    a2: (CAI_BaseNPC *)&savedregs,
    pEvent: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153650
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_FValidateHintType(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_FValidateHintType(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        CAI_Hint *a1)
{
  return CEventLog::PrintGameEvent(
           this: (vgui::Panel *)((char *)this - 2288),
           msglist: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153660
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_ShouldAlwaysThink(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_ShouldAlwaysThink(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::ShouldAlwaysThink(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x10153670
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsCurTaskContinuousMove(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsCurTaskContinuousMove(
        CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::IsCurTaskContinuousMove(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x10153680
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_AimGun(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_AimGun(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  CAI_BaseNPC::AimGun(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x10153690
// Name: public: virtual enum Activity CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_NPC_TranslateActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_NPC_TranslateActivity(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        Activity a1)
{
  return CAI_BaseNPC::NPC_TranslateActivity(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
           eNewActivity: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101536A0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnScheduleChange(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnScheduleChange(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->OnScheduleChange_2(this: this->m_pPrimaryBehavior);
  else
    CAI_BaseNPC::OnScheduleChange(this);
}

//------------------------------------------------------------------------------
// Address: 0x101536C0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsCrouching(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsCrouching(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsCrouching(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::IsCrouching(this);
}

//------------------------------------------------------------------------------
// Address: 0x101536E0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsValidEnemy(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsValidEnemy(CAI_BehaviorHost<CAI_BaseNPC> *this, CBaseEntity *a1)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsValidEnemy(this: this->m_pPrimaryBehavior, a2: a1);
  else
    return CAI_BaseNPC::IsValidEnemy(this, pEnemy: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153700
// Name: public: virtual class CBaseEntity __near * CAI_BehaviorHost<class CAI_BaseNPC>::BestEnemy(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__usercall CAI_BehaviorHost<CAI_BaseNPC>::BestEnemy@<eax>(
        CAI_BehaviorHost<CAI_BaseNPC> *this@<ecx>,
        CBaseEntity *a2@<ebx>)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->BestEnemy(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::BestEnemy(this, a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153720
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsCoverPosition(class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsCoverPosition(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        const Vector *a2)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsCoverPosition(this: this->m_pPrimaryBehavior, a2: a1, a3: a2);
  else
    return CAI_BaseNPC::IsCoverPosition(this, vecThreat: a1, vecPosition: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153740
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsValidCover(class Vector const __near &,class CAI_Hint const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsValidCover(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        const CAI_Hint *a2)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsValidCover(this: this->m_pPrimaryBehavior, a2: a1, a3: a2);
  else
    return CAI_BaseNPC::IsValidCover(this, vecCoverLocation: a1, pHint: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153760
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsValidShootPosition(class Vector const __near &,class CAI_Node __near *,class CAI_Hint const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsValidShootPosition(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        CAI_Node *a2,
        const CAI_Hint *a3)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsValidShootPosition(this: this->m_pPrimaryBehavior, a2: a1, a3: a2, a4: a3);
  else
    return CAI_BaseNPC::IsValidShootPosition(this, vecShootLocation: a1, pNode: a2, pHint: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10153780
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::WeaponLOSCondition(class Vector const __near &,class Vector const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::WeaponLOSCondition(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *a1,
        const Vector *a2,
        BOOL a3)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->WeaponLOSCondition(this: this->m_pPrimaryBehavior, a2: a1, a3: a2, a4: a3);
  else
    return CAI_BaseNPC::WeaponLOSCondition(this, ownerPos: a1, targetPos: a2, bSetConditions: a3);
}

//------------------------------------------------------------------------------
// Address: 0x101537A0
// Name: public: virtual float CAI_BehaviorHost<class CAI_BaseNPC>::GetMaxTacticalLateralMovement(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BehaviorHost<CAI_BaseNPC>::GetMaxTacticalLateralMovement(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->GetMaxTacticalLateralMovement(this: this->m_pPrimaryBehavior);
  else
    return -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x101537C0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::ShouldIgnoreSound(class CSound __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::ShouldIgnoreSound(CAI_BehaviorHost<CAI_BaseNPC> *this, CSound *a1)
{
  return this->m_pPrimaryBehavior != nullptr
      && this->m_pPrimaryBehavior->ShouldIgnoreSound(this: this->m_pPrimaryBehavior, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101537E0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnSeeEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnSeeEntity(CAI_BehaviorHost<CAI_BaseNPC> *this, CBaseEntity *a1)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->OnSeeEntity(this: this->m_pPrimaryBehavior, a2: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153800
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnFriendDamaged(class CBaseCombatCharacter __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnFriendDamaged(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        CBaseCombatCharacter *a1,
        CBaseEntity *a2)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->OnFriendDamaged(this: this->m_pPrimaryBehavior, a2: a1, a3: a2);
  else
    CAI_BaseNPC::OnFriendDamaged(this, pSquadmate: a1, pAttacker: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153820
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsInterruptable(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsInterruptable(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsInterruptable(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::IsInterruptable(this);
}

//------------------------------------------------------------------------------
// Address: 0x10153840
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsNavigationUrgent(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsNavigationUrgent(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsNavigationUrgent(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::IsNavigationUrgent(this);
}

//------------------------------------------------------------------------------
// Address: 0x10153860
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::ShouldPlayerAvoid(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::ShouldPlayerAvoid(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->ShouldPlayerAvoid(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::ShouldPlayerAvoid(this);
}

//------------------------------------------------------------------------------
// Address: 0x10153880
// Name: public: virtual float CAI_BehaviorHost<class CAI_BaseNPC>::GetReasonableFacingDist(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BehaviorHost<CAI_BaseNPC>::GetReasonableFacingDist(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->GetReasonableFacingDist(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::GetReasonableFacingDist(this);
}

//------------------------------------------------------------------------------
// Address: 0x101538A0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::CanFlinch(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::CanFlinch(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->CanFlinch(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::CanFlinch(this);
}

//------------------------------------------------------------------------------
// Address: 0x101538C0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsCrouchedActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsCrouchedActivity(CAI_BehaviorHost<CAI_BaseNPC> *this, Activity a1)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsCrouchedActivity(this: this->m_pPrimaryBehavior, a2: a1);
  else
    return CAI_BaseNPC::IsCrouchedActivity(this, activity: a1);
}

//------------------------------------------------------------------------------
// Address: 0x101538E0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::QueryHearSound(class CSound __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::QueryHearSound(CAI_BehaviorHost<CAI_BaseNPC> *this, CSound *a1)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->QueryHearSound(this: this->m_pPrimaryBehavior, a2: a1);
  else
    return CAI_BaseNPC::QueryHearSound(this, pSound: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153900
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::CanRunAScriptedNPCInteraction(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_BehaviorHost<CAI_BaseNPC>::CanRunAScriptedNPCInteraction(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        BOOL a1)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->CanRunAScriptedNPCInteraction(this: this->m_pPrimaryBehavior, a2: a1);
  else
    return CAI_BaseNPC::CanRunAScriptedNPCInteraction(this, bForced: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153920
// Name: public: virtual enum Activity CAI_BehaviorHost<class CAI_BaseNPC>::GetFlinchActivity(bool,bool)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BehaviorHost<CAI_BaseNPC>::GetFlinchActivity(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        BOOL a1,
        BOOL a2)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->GetFlinchActivity(this: this->m_pPrimaryBehavior, a2: a1, a3: a2);
  else
    return CAI_BaseNPC::GetFlinchActivity(this, bHeavyDamage: a1, bGesture: a2);
}

//------------------------------------------------------------------------------
// Address: 0x10153940
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::OnCalcBaseMove(struct AILocalMoveGoal_t __near *,float,enum AIMoveResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnCalcBaseMove(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        AILocalMoveGoal_t *a1,
        float a2,
        AIMoveResult_t *a3)
{
  if ( this->m_Network.m_TimerEvent.m_pCallback != nullptr )
    return ((bool (__stdcall *)(AILocalMoveGoal_t *, _DWORD, AIMoveResult_t *))this->m_Network.m_TimerEvent.m_pCallback->__vftable[29].FireEvent)(
             a1,
             a2: LODWORD(a2),
             a3);
  else
    return CAI_BaseNPC::OnCalcBaseMove(this, pMoveGoal: a1, distClear: a2, pResult: a3);
}

//------------------------------------------------------------------------------
// Address: 0x10153980
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::FValidateHintType(class CAI_Hint __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::FValidateHintType(CAI_BehaviorHost<CAI_BaseNPC> *this, CAI_Hint *a1)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->FValidateHintType(this: this->m_pPrimaryBehavior, a2: a1);
  else
    return CEventLog::PrintGameEvent(
             (vgui::Panel *)this,
             msglist: (CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > *)a1);
}

//------------------------------------------------------------------------------
// Address: 0x101539B0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::ShouldAlwaysThink(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::ShouldAlwaysThink(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->ShouldAlwaysThink(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::ShouldAlwaysThink(this);
}

//------------------------------------------------------------------------------
// Address: 0x101539D0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsCurTaskContinuousMove(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsCurTaskContinuousMove(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->IsCurTaskContinuousMove(this: this->m_pPrimaryBehavior);
  else
    return CAI_BaseNPC::IsCurTaskContinuousMove(this);
}

//------------------------------------------------------------------------------
// Address: 0x101539F0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::AimGun(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::AimGun(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->AimGun(this: this->m_pPrimaryBehavior);
  else
    CAI_BaseNPC::AimGun(this);
}

//------------------------------------------------------------------------------
// Address: 0x10153A10
// Name: public: virtual enum Activity CAI_BehaviorHost<class CAI_BaseNPC>::NPC_TranslateActivity(enum Activity)
// Source: json
//------------------------------------------------------------------------------
Activity __thiscall CAI_BehaviorHost<CAI_BaseNPC>::NPC_TranslateActivity(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        Activity a1)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->NPC_TranslateActivity(this: this->m_pPrimaryBehavior, a2: a1);
  else
    return CAI_BaseNPC::NPC_TranslateActivity(this, eNewActivity: a1);
}

//------------------------------------------------------------------------------
// Address: 0x10153A40
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnMovementFailed(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnMovementFailed(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->OnMovementFailed(this: this->m_pPrimaryBehavior);
}

//------------------------------------------------------------------------------
// Address: 0x10153A60
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnMovementComplete(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnMovementComplete(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( this->m_pPrimaryBehavior != nullptr )
    this->m_pPrimaryBehavior->OnMovementComplete(this: this->m_pPrimaryBehavior);
}

//------------------------------------------------------------------------------
// Address: 0x10153A80
// Name: public: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::Save(class ISave __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BehaviorHost<CAI_BaseNPC>::Save(CAI_BehaviorHost<CAI_BaseNPC> *this, ISave *save)
{
  int result; // eax
  int v4; // edi
  CAI_BehaviorBase **v5; // eax
  int v6; // [esp-8h] [ebp-14h]

  result = CAI_BaseNPC::Save(this, save);
  v4 = result;
  if ( result != 0 )
  {
    v6 = this->NumBehaviors(this);
    v5 = this->AccessBehaviors(this);
    CAI_BehaviorBase::SaveBehaviors(
      save,
      pCurrentBehavior: this->m_pPrimaryBehavior,
      ppBehavior: v5,
      nBehaviors: v6,
      bTestIfNPCSave: true);
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153AD0
// Name: public: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::Restore(class IRestore __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BehaviorHost<CAI_BaseNPC>::Restore(CAI_BehaviorHost<CAI_BaseNPC> *this, IRestore *restore)
{
  int result; // eax
  int v4; // edi
  CAI_BehaviorBase **v5; // eax
  int v6; // ebx
  int v7; // [esp-8h] [ebp-14h]

  result = CAI_BaseNPC::Restore(this, restore);
  v4 = result;
  if ( result != 0 )
  {
    v7 = this->NumBehaviors(this);
    v5 = this->AccessBehaviors(this);
    v6 = CAI_BehaviorBase::RestoreBehaviors(restore, ppBehavior: v5, nBehaviors: v7, bTestIfNPCSave: true);
    if ( v6 == -1 )
      this->m_pPrimaryBehavior = nullptr;
    else
      this->m_pPrimaryBehavior = this->AccessBehaviors(this)[v6];
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153B50
// Name: public: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::SelectFailSchedule(int,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BehaviorHost<CAI_BaseNPC>::SelectFailSchedule(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        int failedSchedule,
        int failedTask,
        int taskFailCode)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // ecx
  int v7; // [esp+Ch] [ebp-4h] BYREF

  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  this->m_bCalledBehaviorSelectSchedule = true;
  v7 = 0;
  if ( m_pPrimaryBehavior != nullptr
    && CAI_BehaviorBase::BridgeSelectFailSchedule(
         this: m_pPrimaryBehavior,
         failedSchedule,
         failedTask,
         taskFailCode,
         pResult: &v7) != 0 )
  {
    return v7;
  }
  else
  {
    return CAI_BaseNPC::SelectFailSchedule(this, failedSchedule, failedTask, taskFailCode);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10153BB0
// Name: public: virtual class CAI_Schedule __near * CAI_BehaviorHost<class CAI_BaseNPC>::GetSchedule(int)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_BehaviorHost<CAI_BaseNPC>::GetSchedule(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        int localScheduleID)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // ecx
  CAI_Schedule *result; // eax

  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  if ( m_pPrimaryBehavior == nullptr )
    return CAI_BaseNPC::GetSchedule(this, schedule: localScheduleID);
  result = m_pPrimaryBehavior->GetSchedule(this: m_pPrimaryBehavior, a2: localScheduleID);
  if ( result == nullptr )
    return CAI_BaseNPC::GetSchedule(this, schedule: localScheduleID);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153BF0
// Name: public: virtual char const __near * CAI_BehaviorHost<class CAI_BaseNPC>::TaskName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CAI_BehaviorHost<CAI_BaseNPC>::TaskName(CAI_BehaviorHost<CAI_BaseNPC> *this, int taskID)
{
  CAI_BehaviorBase *m_pPrimaryBehavior; // ecx
  int v4; // eax
  int v5; // eax
  const char *result; // eax

  m_pPrimaryBehavior = this->m_pPrimaryBehavior;
  if ( m_pPrimaryBehavior == nullptr )
    return CAI_BaseNPC::TaskName(this, taskID);
  if ( taskID >= 1000000000 )
    return CAI_BaseNPC::TaskName(this, taskID);
  v4 = (int)m_pPrimaryBehavior->GetClassScheduleIdSpace(this: m_pPrimaryBehavior);
  v5 = CAI_LocalIdSpace::LocalToGlobal(this: (CAI_LocalIdSpace *)(v4 + 28), localID: taskID);
  result = CAI_GlobalNamespace::IdToSymbol(this: &CAI_BaseNPC::gm_SchedulingSymbols.m_TaskNamespace, symbolID: v5);
  if ( result == nullptr )
    return CAI_BaseNPC::TaskName(this, taskID);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153C50
// Name: protected: virtual class CAI_Schedule __near * CAI_BehaviorHost<class CAI_BaseNPC>::GetNewSchedule(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_BehaviorHost<CAI_BaseNPC>::GetNewSchedule(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  CAI_Schedule *result; // eax
  CAI_Schedule *v3; // edi

  this->m_bCalledBehaviorSelectSchedule = false;
  result = CAI_BaseNPC::GetNewSchedule(this);
  v3 = result;
  if ( !this->m_bCalledBehaviorSelectSchedule && this->m_pPrimaryBehavior != nullptr )
  {
    CAI_BaseNPC::DeferSchedulingToBehavior(this, pNewBehavior: nullptr);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153C90
// Name: protected: virtual class CAI_Schedule __near * CAI_BehaviorHost<class CAI_BaseNPC>::GetFailSchedule(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Schedule *__thiscall CAI_BehaviorHost<CAI_BaseNPC>::GetFailSchedule(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  CAI_Schedule *result; // eax
  CAI_Schedule *v3; // edi

  this->m_bCalledBehaviorSelectSchedule = false;
  result = CAI_BaseNPC::GetFailSchedule(this);
  v3 = result;
  if ( !this->m_bCalledBehaviorSelectSchedule && this->m_pPrimaryBehavior != nullptr )
  {
    CAI_BaseNPC::DeferSchedulingToBehavior(this, pNewBehavior: nullptr);
    return v3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153CD0
// Name: private: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_GatherConditions(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_GatherConditions(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  if ( !g_bBehaviorHost_PreventBaseClassGatherConditions )
    CAI_BaseNPC::GatherConditions(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x10153CF0
// Name: private: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_SelectSchedule(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_SelectSchedule(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return CAI_BaseNPC::SelectSchedule(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288));
}

//------------------------------------------------------------------------------
// Address: 0x10153D00
// Name: private: virtual int CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_TranslateSchedule(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_TranslateSchedule(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        int scheduleType)
{
  return CAI_BaseNPC::TranslateSchedule(this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288), scheduleType);
}

//------------------------------------------------------------------------------
// Address: 0x10153D10
// Name: private: virtual float CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_GetJumpGravity(void)const
// Source: json
//------------------------------------------------------------------------------
float __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_GetJumpGravity(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  return (*(float (__thiscall **)(char *))(*((_DWORD *)this - 572) + 1984))(a1: (char *)this - 2288);
}

//------------------------------------------------------------------------------
// Address: 0x10153D30
// Name: private: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_IsJumpLegal(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float,float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_IsJumpLegal(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *startPos,
        const Vector *apex,
        const Vector *endPos,
        float maxUp,
        float maxDown,
        float maxDist)
{
  return CAI_BaseNPC::IsJumpLegal(
           this: (CAI_BehaviorHost<CAI_BaseNPC> *)((char *)this - 2288),
           startPos,
           apex,
           endPos,
           maxUp,
           maxDown,
           maxDist);
}

//------------------------------------------------------------------------------
// Address: 0x10153D80
// Name: private: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_MovementCost(int,class Vector const __near &,class Vector const __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_MovementCost(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        int *moveType,
        const Vector *vecStart,
        const Vector *vecEnd,
        float *pCost)
{
  return vgui::Frame::GetDefaultScreenPosition(
           this: (vgui::Frame *)((char *)this - 2288),
           x: moveType,
           y: (int *)vecStart,
           wide: (int *)vecEnd,
           tall: (int *)pCost);
}

//------------------------------------------------------------------------------
// Address: 0x10153DA0
// Name: public: virtual class CAI_Navigator __near * CAI_BlendingHost<class CAI_BehaviorHost<class CAI_BaseNPC>>::CreateNavigator(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Navigator *__thiscall CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC>>::CreateNavigator(
        CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> > *this)
{
  CAI_Navigator *result; // eax

  result = CAI_BaseNPC::CreateNavigator(this);
  result->m_bValidateActivitySpeed = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153DB0
// Name: public: virtual float CAI_BlendingHost<class CAI_BehaviorHost<class CAI_BaseNPC>>::MaxYawSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC>>::MaxYawSpeed(
        CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> > *this)
{
  double result; // st7

  result = ((double (__thiscall *)(CAI_Motor *, Activity))this->m_pMotor->OverrideMaxYawSpeed)(
             a1: this->m_pMotor,
             a2: this->m_Activity);
  if ( result == -1.0 )
    return CAI_BaseNPC::MaxYawSpeed(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153DF0
// Name: public: virtual float CAI_BlendingHost<class CAI_BehaviorHost<class CAI_BaseNPC>>::GetTimeToNavGoal(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC>>::GetTimeToNavGoal(
        CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> > *this)
{
  double result; // st7

  result = CAI_BlendedMotor::GetMoveScriptTotalTime(this: (CAI_BlendedMotor *)this->m_pMotor);
  if ( result == -1.0 )
    return CAI_BaseNPC::GetTimeToNavGoal(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10153E20
// Name: public: virtual void CFlextalkActor::ProcessSceneEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CFlextalkActor::ProcessSceneEvents(CFlextalkActor *this)
{
  char *v2; // edi
  char *m_pszString; // eax
  char v4; // cl
  const char *v5; // eax
  int v6; // ebx
  int i; // edi
  int j; // edi
  LocalFlexController_t v9; // eax
  int v10; // ecx
  char *k; // eax
  float v12; // ebx
  char v13; // al
  int v14; // edi
  float *m_flextarget; // ebx
  LocalFlexController_t m; // edi
  const char *v17; // eax
  LocalFlexController_t v18; // eax
  bool v19; // zf
  float (__thiscall *RandomFloat)(IUniformRandomStream *, float, float); // eax
  IUniformRandomStream_vtbl *v21; // edi
  int NumFlexControllers; // eax
  LocalFlexController_t v23; // ecx
  const char *FlexControllerType; // eax
  unsigned __int8 *FlexControllerName; // eax
  int v26; // eax
  const char *v27; // eax
  LocalFlexController_t v28; // edi
  float *v29; // ebx
  double FlexWeight; // st7
  float v31; // xmm0_4
  float (__thiscall *v32)(IUniformRandomStream *, float, float); // eax
  double v33; // st7
  int v34; // xmm1_4
  int m_nValue; // eax
  int m_sentence; // eax
  const char *pszValue; // ecx
  int v38; // eax
  int v39; // edi
  const Vector *v40; // ebx
  Vector *(__thiscall *GetSoundEmissionOrigin)(CBaseEntity *, Vector *); // edx
  const Vector *v42; // eax
  edict_t *m_pPev; // esi
  CFlextalkActor_vtbl *v44; // edi
  CBasePlayer *v45; // eax
  float m_fValue; // [esp+3Ch] [ebp-148h]
  const char *value; // [esp+40h] [ebp-144h]
  float valuea; // [esp+40h] [ebp-144h]
  char pDest[128]; // [esp+50h] [ebp-134h] BYREF
  char szExpression[128]; // [esp+D0h] [ebp-B4h] BYREF
  CPASAttenuationFilter filter; // [esp+150h] [ebp-34h] BYREF
  float v52; // [esp+170h] [ebp-14h]
  float attenuation; // [esp+174h] [ebp-10h] BYREF
  double v54; // [esp+178h] [ebp-Ch]
  int weight; // [esp+180h] [ebp-4h]
  int savedregs; // [esp+184h] [ebp+0h] BYREF

  if ( this->m_SceneEvents.m_Size != 0 )
  {
    CBaseFlex::ProcessSceneEvents(this);
    return;
  }
  if ( CBaseAnimating::GetNumFlexControllers(this) <= 2 )
    return;
  if ( (flex_expression.m_nFlags & 0x1000) != 0 )
  {
    v2 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = flex_expression.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      goto LABEL_40;
    v4 = *m_pszString;
    v2 = flex_expression.m_pParent->m_Value.m_pszString;
    if ( *m_pszString == 43 )
    {
      v5 = m_pszString + 1;
      if ( *v5 != 0 )
      {
        v6 = atoi(nptr: v5);
        for ( i = 0; i < CBaseAnimating::GetNumFlexControllers(this); ++i )
          this->m_flextarget[this->m_flexnum] = 0.0;
        for ( j = 0; j < 35; ++j )
        {
          if ( predef_flexcontroller_names[j] == nullptr )
            break;
          v9 = CFlextalkActor::LookupFlex((CFlexCycler *)this, szTarget: predef_flexcontroller_names[j]);
          v10 = j + 30 * v6;
          this->m_flexnum = v9;
          this->m_flextarget[v9] = predef_flexcontroller_values[v10];
        }
        goto LABEL_46;
      }
    }
    if ( v4 == 0 )
    {
LABEL_40:
      if ( gpGlobals->curtime > this->m_flextime )
      {
        *(float *)&weight = COERCE_FLOAT(CBaseAnimating::GetNumFlexControllers(this));
        RandomFloat = random->RandomFloat;
        v54 = 1.0 / (double)weight * 30.0;
        this->m_flextime = ((double (__thiscall *)(IUniformRandomStream *, int, int))RandomFloat)(
                             a1: random,
                             a2: 1050253722,
                             a3: 1056964608)
                         * v54
                         + gpGlobals->curtime;
        v21 = random->__vftable;
        NumFlexControllers = CBaseAnimating::GetNumFlexControllers(this);
        v23 = v21->RandomInt(this: random, a2: 0, a3: NumFlexControllers - 1);
        this->m_flexnum = v23;
        if ( this->m_flextarget[v23] == 1.0 )
        {
          this->m_flextarget[v23] = 0.0;
        }
        else
        {
          FlexControllerType = CBaseAnimating::GetFlexControllerType(this, iFlexController: v23);
          if ( _V_stricmp(s1: FlexControllerType, s2: "phoneme") != 0 )
          {
            FlexControllerName = (unsigned __int8 *)CBaseAnimating::GetFlexControllerName(
                                                      this,
                                                      iFlexController: this->m_flexnum);
            strstr(str1: FlexControllerName, str2: "upper_raiser");
            if ( v26 == 0 )
            {
              value = CBaseAnimating::GetFlexControllerName(this, iFlexController: this->m_flexnum);
              v27 = CBaseAnimating::GetFlexControllerType(this, iFlexController: this->m_flexnum);
              _Msg(a1: "%s:%s\n", v27, value);
              valuea = ((double (__thiscall *)(IUniformRandomStream *, int, int))random->RandomFloat)(
                         a1: random,
                         a2: 1056964608,
                         a3: 1065353216);
              CFlextalkActor::SetFlexTarget(this, a2: (int)v21, flexnum: this->m_flexnum, value: valuea);
            }
          }
        }
      }
      goto LABEL_46;
    }
  }
  if ( strcmp(v2, "+") == 0 )
    goto LABEL_40;
  V_strncpy(pDest: szExpression, pSrc: v2, maxLen: 128);
  for ( k = szExpression; *k != 0; ++k )
  {
    if ( *k == 43 )
      *k = 32;
  }
  v12 = COERCE_FLOAT(szExpression);
  *(float *)&weight = COERCE_FLOAT(szExpression);
  if ( szExpression[0] != 0 )
  {
    do
    {
      v13 = *(_BYTE *)LODWORD(v12);
      if ( *(_BYTE *)LODWORD(v12) != 32 )
      {
        if ( v13 == 45 )
        {
          v14 = 0;
          if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
          {
            m_flextarget = this->m_flextarget;
            do
            {
              *m_flextarget = 0.0;
              ++v14;
              ++m_flextarget;
            }
            while ( v14 < CBaseAnimating::GetNumFlexControllers(this) );
LABEL_37:
            v12 = *(float *)&weight;
          }
        }
        else
        {
          if ( v13 == 63 )
          {
            for ( m = DUMMY_NULL_FLEX_CONTROLLER; m < CBaseAnimating::GetNumFlexControllers(this); ++m )
            {
              v17 = CBaseAnimating::GetFlexControllerName(this, iFlexController: m);
              _Msg(a1: "\"%s\" ", v17);
            }
            _Msg(a1: "\n");
            ConVar::SetValue(this: (ConVar *)&flex_expression.IConVar, value: locale);
            goto LABEL_37;
          }
          if ( sscanf(string: (const char *)LODWORD(v12), format: "%31s", &filter) == 1 )
          {
            v18 = CFlextalkActor::LookupFlex((CFlexCycler *)this, szTarget: (const char *)&filter);
            this->m_flexnum = v18;
            if ( v18 != DUMMY_INVALID_FLEX_CONTROLLER && this->m_flextarget[v18] != 1.0 )
              this->m_flextarget[v18] = 1.0;
            weight = LODWORD(v12) + strlen((const char *)&filter) - 1;
            goto LABEL_37;
          }
        }
      }
      ++LODWORD(v12);
      v19 = *(_BYTE *)LODWORD(v12) == 0;
      *(float *)&weight = v12;
    }
    while ( !v19 );
  }
LABEL_46:
  v28 = DUMMY_NULL_FLEX_CONTROLLER;
  if ( CBaseAnimating::GetNumFlexControllers(this) > 0 )
  {
    v29 = this->m_flextarget;
    do
    {
      FlexWeight = CBaseFlex::GetFlexWeight(this, index: v28);
      *(float *)&weight = FlexWeight;
      v31 = *(float *)&weight;
      v52 = *v29;
      if ( *(float *)&weight != v52 )
      {
        v32 = random->RandomFloat;
        *((float *)&v54 + 1) = v52 - FlexWeight;
        v33 = ((double (__thiscall *)(IUniformRandomStream *, int, int))v32)(a1: random, a2: 0x40000000, a3: 1082130432);
        *(float *)&weight = *((float *)&v54 + 1) / v33 + *(float *)&weight;
        v31 = *(float *)&weight;
      }
      *(float *)&v34 = 0.0;
      if ( v31 < 0.0 || (*(float *)&v34 = 1.0, v31 > 1.0) )
        v31 = *(float *)&v34;
      CBaseFlex::SetFlexWeight(this, index: v28++, value: v31);
      ++v29;
    }
    while ( v28 < CBaseAnimating::GetNumFlexControllers(this) );
  }
  if ( flex_talk.m_pParent != nullptr )
  {
    m_nValue = flex_talk.m_pParent->m_Value.m_nValue;
    switch ( m_nValue )
    {
      case -1:
        m_sentence = this->m_sentence;
        this->m_istalking = 1;
        this->m_sentence = m_sentence + 1;
        pszValue = this->m_iszSentence.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        V_snprintf(pDest, maxLen: 256, pFormat: "%s%d", pszValue, m_sentence);
        v38 = engine->SentenceIndexFromName(this: engine, a2: pDest);
        v39 = v38;
        if ( v38 < 0 )
        {
          this->m_sentence = 0;
        }
        else
        {
          _Msg(a1: "%d : %s\n", v38, pDest);
          v40 = (const Vector *)((int (__thiscall *)(CFlextalkActor *))this->GetSoundEmissionOrigin)(a1: this);
          CRecipientFilter::CRecipientFilter(this: &filter);
          filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASFilter::`vftable';
          CRecipientFilter::AddRecipientsByPAS(this: &filter, origin: v40);
          GetSoundEmissionOrigin = this->GetSoundEmissionOrigin;
          filter.__vftable = (CPASAttenuationFilter_vtbl *)&CPASAttenuationFilter::`vftable';
          v42 = (const Vector *)((int (__thiscall *)(CFlextalkActor *, float *, int))GetSoundEmissionOrigin)(
                                  a1: this,
                                  a2: &attenuation,
                                  a3: 1061997773);
          CPASAttenuationFilter::Filter(
            this: &filter,
            a2: (int)&savedregs,
            origin: v42,
            attenuation: COERCE_FLOAT(&attenuation));
          m_pPev = this->m_Network.m_pPev;
          if ( m_pPev != nullptr )
            m_pPev -= (int)gpGlobals->pEdicts;
          CBaseEntity::EmitSentenceByIndex(
            &filter,
            iEntIndex: (int)m_pPev,
            iChannel: 2,
            iSentenceIndex: v39,
            flVolume: 1.0,
            iSoundlevel: SNDLVL_80dB,
            iFlags: 0,
            iPitch: 100,
            pOrigin: nullptr,
            pDirection: nullptr,
            bUpdatePositions: true,
            soundtime: 0.0);
          CRecipientFilter::~CRecipientFilter(this: &filter);
        }
        break;
      case -2:
        this->m_flNextEyeLookTime = gpGlobals->curtime + 1000.0;
        return;
      case -3:
        this->m_flNextEyeLookTime = gpGlobals->curtime;
        break;
      case -4:
        v44 = this->CGenericActor::CAI_BaseActor::CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
        m_fValue = flex_looktime.m_pParent->m_Value.m_fValue;
        v45 = UTIL_PlayerByIndex(playerIndex: 1);
        ((void (__thiscall *)(CFlextalkActor *, CBasePlayer *, int, float, _DWORD))v44->AddLookTarget)(
          a1: this,
          a2: v45,
          a3: 1056964608,
          a4: COERCE_FLOAT(LODWORD(m_fValue)),
          a5: 0);
        break;
      case -5:
        ((void (__thiscall *)(CFlextalkActor *, int, int, int))this->PickLookTarget)(
          a1: this,
          a2: 1,
          a3: 1069547520,
          a4: 1075838976);
        break;
      default:
        return;
    }
    ConVar::SetValue(this: (ConVar *)&flex_talk.IConVar, value: "0");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101544E0
// Name: public: virtual float CAI_BehaviorHost<class CAI_BaseNPC>::BehaviorBridge_GetDefaultNavGoalTolerance(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BehaviorHost<CAI_BaseNPC>::BehaviorBridge_GetDefaultNavGoalTolerance(
        CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  double v1; // st7

  v1 = NAI_Hull::Width(id: *((_DWORD *)this - 154));
  return v1 + v1;
}

//------------------------------------------------------------------------------
// Address: 0x10154500
// Name: public: virtual float CAI_BehaviorHost<class CAI_BaseNPC>::GetDefaultNavGoalTolerance(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BehaviorHost<CAI_BaseNPC>::GetDefaultNavGoalTolerance(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  double v2; // st7

  if ( this->m_pPrimaryBehavior != nullptr )
    return this->m_pPrimaryBehavior->GetDefaultNavGoalTolerance(this: this->m_pPrimaryBehavior);
  v2 = NAI_Hull::Width(id: this->m_eHull);
  return v2 + v2;
}

//------------------------------------------------------------------------------
// Address: 0x10154530
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::CleanupOnDeath(class CBaseEntity __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::CleanupOnDeath(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        CBaseEntity *pCulprit,
        BOOL bFireDeathOutput)
{
  int i; // edi
  CAI_BehaviorBase *v5; // ecx

  CAI_BaseNPC::DeferSchedulingToBehavior(this, pNewBehavior: nullptr);
  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v5 = this->m_Behaviors.m_Memory.m_pMemory[i];
    v5->CleanupOnDeath(this: v5, a2: pCulprit, a3: bFireDeathOutput);
  }
  CAI_BaseNPC::CleanupOnDeath(this, pCulprit, bFireDeathOutput);
}

//------------------------------------------------------------------------------
// Address: 0x10154590
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::UpdateOnRemove(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  int i; // esi
  CAI_BehaviorBase *v3; // ecx

  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v3 = this->m_Behaviors.m_Memory.m_pMemory[i];
    v3->UpdateOnRemove(this: v3);
  }
  CAI_BaseNPC::UpdateOnRemove(this);
}

//------------------------------------------------------------------------------
// Address: 0x101545D0
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnChangeHintGroup(struct string_t,struct string_t)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnChangeHintGroup(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        string_t oldGroup,
        string_t newGroup)
{
  int i; // esi
  CAI_BehaviorBase *v5; // ecx

  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v5 = this->m_Behaviors.m_Memory.m_pMemory[i];
    ((void (__thiscall *)(CAI_BehaviorBase *, const char *, const char *))v5->OnChangeHintGroup)(
      a1: v5,
      a2: oldGroup.pszValue,
      a3: newGroup.pszValue);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154610
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnChangeActiveWeapon(class CBaseCombatWeapon __near *,class CBaseCombatWeapon __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnChangeActiveWeapon(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        CBaseCombatWeapon *pOldWeapon,
        CBaseCombatWeapon *pNewWeapon)
{
  int i; // esi
  CAI_BehaviorBase *v5; // ecx

  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v5 = this->m_Behaviors.m_Memory.m_pMemory[i];
    v5->OnChangeActiveWeapon(this: v5, a2: pOldWeapon, a3: pNewWeapon);
  }
  CAI_BaseNPC::OnChangeActiveWeapon(this, pOldWeapon, pNewWeapon);
}

//------------------------------------------------------------------------------
// Address: 0x10154660
// Name: public: virtual void CAI_BehaviorHost<class CAI_BaseNPC>::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BehaviorHost<CAI_BaseNPC>::OnRestore(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  int i; // esi
  CAI_BehaviorBase *v3; // ecx

  for ( i = 0; i < this->m_Behaviors.m_Size; ++i )
  {
    v3 = this->m_Behaviors.m_Memory.m_pMemory[i];
    v3->OnRestore(this: v3);
  }
  CAI_BaseNPC::OnRestore(this);
}

//------------------------------------------------------------------------------
// Address: 0x101546A0
// Name: public: virtual float CAI_BehaviorHost<class CAI_BaseNPC>::GetJumpGravity(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_BehaviorHost<CAI_BaseNPC>::GetJumpGravity(CAI_BehaviorHost<CAI_BaseNPC> *this)
{
  int v2; // edi
  CAI_BehaviorBase *v3; // ecx
  double result; // st7
  float base; // [esp+8h] [ebp-4h]

  base = this->GetDefaultJumpGravity(this);
  v2 = 0;
  if ( this->m_Behaviors.m_Size <= 0 )
    return this->GetDefaultJumpGravity(this);
  while ( 1 )
  {
    v3 = this->m_Behaviors.m_Memory.m_pMemory[v2];
    result = ((double (__thiscall *)(CAI_BehaviorBase *))v3->GetJumpGravity)(a1: v3);
    if ( result != base )
      break;
    if ( ++v2 >= this->m_Behaviors.m_Size )
      return this->GetDefaultJumpGravity(this);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10154710
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::IsJumpLegal(class Vector const __near &,class Vector const __near &,class Vector const __near &,float,float,float)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::IsJumpLegal(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        const Vector *startPos,
        const Vector *apex,
        const Vector *endPos,
        float maxUp,
        float maxDown,
        float maxDist)
{
  int v8; // edi
  bool IsJumpLegal; // bl
  CAI_BehaviorBase *v10; // ecx
  bool result; // al

  v8 = 0;
  IsJumpLegal = CAI_BaseNPC::IsJumpLegal(this, startPos, apex, endPos, maxUp, maxDown, maxDist);
  if ( this->m_Behaviors.m_Size <= 0 )
    return IsJumpLegal;
  while ( 1 )
  {
    v10 = this->m_Behaviors.m_Memory.m_pMemory[v8];
    result = ((int (__thiscall *)(CAI_BehaviorBase *, const Vector *, const Vector *, const Vector *, _DWORD, _DWORD, _DWORD))v10->IsJumpLegal)(
               a1: v10,
               a2: startPos,
               a3: apex,
               a4: endPos,
               a5: LODWORD(maxUp),
               a6: LODWORD(maxDown),
               a7: LODWORD(maxDist));
    if ( result != IsJumpLegal )
      break;
    if ( ++v8 >= this->m_Behaviors.m_Size )
      return IsJumpLegal;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101547C0
// Name: public: virtual bool CAI_BehaviorHost<class CAI_BaseNPC>::MovementCost(int,class Vector const __near &,class Vector const __near &,float __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_BehaviorHost<CAI_BaseNPC>::MovementCost(
        CAI_BehaviorHost<CAI_BaseNPC> *this,
        int *moveType,
        const Vector *vecStart,
        const Vector *vecEnd,
        float *pCost)
{
  int v6; // edi
  bool DefaultScreenPosition; // bl
  CAI_BehaviorBase *v8; // ecx
  bool result; // al

  v6 = 0;
  DefaultScreenPosition = vgui::Frame::GetDefaultScreenPosition(
                            (vgui::Frame *)this,
                            x: moveType,
                            y: (int *)vecStart,
                            wide: (int *)vecEnd,
                            tall: (int *)pCost);
  if ( this->m_Behaviors.m_Size <= 0 )
    return DefaultScreenPosition;
  while ( 1 )
  {
    v8 = this->m_Behaviors.m_Memory.m_pMemory[v6];
    result = v8->MovementCost(this: v8, a2: (int)moveType, a3: vecStart, a4: vecEnd, a5: pCost);
    if ( result != DefaultScreenPosition )
      break;
    if ( ++v6 >= this->m_Behaviors.m_Size )
      return DefaultScreenPosition;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10154830
// Name: public: virtual void CGenericActor::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CGenericActor::Spawn(CGenericActor *this)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  Vector *p_m_vHullMin; // eax
  const char *v7; // eax
  const char *pszValue; // eax
  Vector *p_m_vHullMax; // [esp-4h] [ebp-Ch]
  _BYTE v10[4]; // [esp+4h] [ebp-4h] BYREF

  this->Precache(this);
  v2 = *(const char **)((int (__thiscall *)(CGenericActor *, _BYTE *))this->GetModelName)(a1: this, a2: v10);
  if ( v2 == nullptr )
    v2 = locale;
  this->SetModel(this, a2: v2);
  v3 = *(const char **)((int (__thiscall *)(CGenericActor *, _BYTE *))this->GetModelName)(a1: this, a2: v10);
  if ( v3 == nullptr )
    v3 = locale;
  if ( v3 == "models/player.mdl" || _V_stricmp(s1: v3, s2: "models/player.mdl") == 0 )
    goto LABEL_16;
  v4 = *(const char **)((int (__thiscall *)(CGenericActor *, _BYTE *))this->GetModelName)(a1: this, a2: v10);
  if ( v4 == nullptr )
    v4 = locale;
  if ( v4 == "models/holo.mdl" || _V_stricmp(s1: v4, s2: "models/holo.mdl") == 0 )
    goto LABEL_16;
  v5 = *(const char **)((int (__thiscall *)(CGenericActor *, _BYTE *))this->GetModelName)(a1: this, a2: v10);
  if ( v5 == nullptr )
    v5 = locale;
  if ( v5 == "models/blackout.mdl" || _V_stricmp(s1: v5, s2: "models/blackout.mdl") == 0 )
  {
LABEL_16:
    p_m_vHullMax = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMax;
    p_m_vHullMin = &g_pGameRules->GetViewVectors(this: g_pGameRules)->m_vHullMin;
  }
  else
  {
    p_m_vHullMax = NAI_Hull::Maxs(id: 0);
    p_m_vHullMin = NAI_Hull::Mins(id: 0);
  }
  UTIL_SetSize(pEnt: this, vecMin: p_m_vHullMin, vecMax: p_m_vHullMax);
  v7 = *(const char **)((int (__thiscall *)(CGenericActor *, _BYTE *))this->GetModelName)(a1: this, a2: v10);
  if ( v7 == nullptr )
    v7 = locale;
  if ( v7 == "models/blackout.mdl" || _V_stricmp(s1: v7, s2: "models/blackout.mdl") == 0 )
  {
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_NONE);
  }
  else
  {
    CCollisionProperty::SetSolid(this: &this->m_Collision, val: SOLID_BBOX);
    CCollisionProperty::SetSolidFlags(this: &this->m_Collision, flags: this->m_Collision.m_usSolidFlags.m_Value | 0x10);
  }
  CBaseEntity::SetMoveType(this, val: MOVETYPE_STEP, moveCollide: MOVECOLLIDE_DEFAULT);
  CBaseCombatCharacter::SetBloodColor(this, nBloodColor: 0);
  if ( this->m_iHealth.m_Value != 8 )
  {
    this->NetworkStateChanged_m_iHealth(this, a2: &this->m_iHealth);
    this->m_iHealth.m_Value = 8;
  }
  this->m_flFieldOfView = 0.5;
  this->m_NPCState = NPC_STATE_NONE;
  CAI_BaseNPC::CapabilitiesAdd(this, capability: 2049);
  if ( CBaseAnimating::LookupAttachment(this, szName: "eyes") > 0
    && CBaseAnimating::LookupAttachment(this, szName: "forward") > 0 )
  {
    CAI_BaseNPC::CapabilitiesAdd(this, capability: 8392704);
  }
  if ( this->m_strHullName.pszValue != nullptr )
  {
    pszValue = this->m_strHullName.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    this->m_eHull = NAI_Hull::LookupId(szName: pszValue);
  }
  else
  {
    this->m_eHull = HULL_HUMAN;
  }
  CAI_BaseNPC::SetHullSizeNormal(this, force: false);
  this->NPCInit(this);
}

//------------------------------------------------------------------------------
// Address: 0x10154A80
// Name: public: virtual void CAI_ExpresserHost<class CAI_BaseHumanoid>::NoteSpeaking(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserHost<CAI_BaseHumanoid>::NoteSpeaking(
        CAI_ExpresserHost<CAI_BaseHumanoid> *this,
        float duration,
        float delay)
{
  CAI_Expresser *v3; // eax

  v3 = this->GetExpresser(this);
  CAI_Expresser::NoteSpeaking(this: v3, duration, delay);
}

//------------------------------------------------------------------------------
// Address: 0x10154AB0
// Name: public: virtual bool CAI_ExpresserHost<class CAI_BaseHumanoid>::Speak(class CAI_Concept,char const __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ExpresserHost<CAI_BaseHumanoid>::Speak(
        CAI_ExpresserHost<CAI_BaseHumanoid> *this,
        CAI_Concept concept,
        const char *modifiers,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  CAI_Expresser *v6; // eax
  const char *v8; // [esp-10h] [ebp-10h]
  char *v9; // [esp-Ch] [ebp-Ch]
  unsigned int v10; // [esp-8h] [ebp-8h]
  IRecipientFilter *v11; // [esp-4h] [ebp-4h]

  v11 = filter;
  v10 = bufsize;
  v9 = pszOutResponseChosen;
  v8 = modifiers;
  v6 = this->GetExpresser(this);
  return CAI_Expresser::Speak(this: v6, &concept, modifiers: v8, pszOutResponseChosen: v9, bufsize: v10, filter: v11);
}

//------------------------------------------------------------------------------
// Address: 0x10154AE0
// Name: protected: virtual int CAI_ExpresserHost<class CAI_BaseHumanoid>::PlaySentence(char const __near *,float,float,enum soundlevel_t,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_ExpresserHost<CAI_BaseHumanoid>::PlaySentence(
        CAI_ExpresserHost<CAI_BaseHumanoid> *this,
        const char *pszSentence,
        float delay,
        float volume,
        soundlevel_t soundlevel,
        CBaseEntity *pListener)
{
  CAI_Expresser *v6; // eax

  v6 = this->GetExpresser(this);
  return ((int (__thiscall *)(CAI_Expresser *, const char *, _DWORD, _DWORD, soundlevel_t, CBaseEntity *))v6->SpeakRawSentence)(
           a1: v6,
           a2: pszSentence,
           a3: LODWORD(delay),
           a4: LODWORD(volume),
           a5: soundlevel,
           a6: pListener);
}

//------------------------------------------------------------------------------
// Address: 0x10154B20
// Name: protected: virtual class ResponseRules::IResponseSystem __near * CAI_ExpresserHost<class CAI_BaseHumanoid>::GetResponseSystem(void)
// Source: json
//------------------------------------------------------------------------------
ResponseRules::IResponseSystem *__thiscall CAI_ExpresserHost<CAI_BaseHumanoid>::GetResponseSystem(
        CAI_ExpresserHost<CBasePlayer> *this)
{
  return g_pResponseSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10154B30
// Name: public: virtual bool CAI_ExpresserHost<class CAI_BaseHumanoid>::Speak(class CAI_Concept,class ResponseRules::CriteriaSet __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ExpresserHost<CAI_BaseHumanoid>::Speak(
        CAI_ExpresserHost<CAI_BaseHumanoid> *this,
        CAI_Concept concept,
        ResponseRules::CriteriaSet *pCriteria,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  CAI_Expresser *v7; // edi
  const CBaseHandle *v8; // eax
  ResponseRules::CriteriaSet *v9; // esi

  v7 = this->GetExpresser(this);
  v8 = this->GetRefEHandle(this);
  v9 = pCriteria;
  concept.m_hSpeaker = (CHandle<CBaseEntity>)v8->m_Index;
  CAI_Expresser::GatherCriteria(this: v7, outputSet: pCriteria, &concept, modifiers: nullptr);
  return CAI_Expresser::Speak(this: v7, &concept, criteria: v9, pszOutResponseChosen, bufsize, filter);
}

//------------------------------------------------------------------------------
// Address: 0x10154B80
// Name: protected: virtual void CAI_ExpresserHost<class CAI_BaseHumanoid>::DispatchResponse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserHost<CAI_BaseHumanoid>::DispatchResponse(
        CAI_ExpresserHost<CAI_BaseHumanoid> *this,
        const char *conceptName)
{
  int v3; // [esp-18h] [ebp-20h] BYREF
  int v4; // [esp-10h] [ebp-18h]
  int v5; // [esp-Ch] [ebp-14h]
  int v6; // [esp-8h] [ebp-10h]
  int v7; // [esp-4h] [ebp-Ch]

  v7 = 0;
  v6 = 0;
  v5 = 0;
  v4 = 0;
  ResponseRules::CRR_Concept::CRR_Concept(this: (ResponseRules::CRR_Concept *)&v3, fromString: conceptName);
  ((void (__thiscall *)(CAI_ExpresserHost<CAI_BaseHumanoid> *, int, int, int, int, int, int))this->Speak)(
    a1: this,
    a2: v3,
    a3: -1,
    a4: v4,
    a5: v5,
    a6: v6,
    a7: v7);
}

//------------------------------------------------------------------------------
// Address: 0x10154BC0
// Name: public: CAI_BlendedMotor::CAI_BlendedMotor(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_BlendedMotor *__thiscall CAI_BlendedMotor::CAI_BlendedMotor(CAI_BlendedMotor *this, CAI_BaseNPC *pOuter)
{
  CAI_Motor::CAI_Motor(this, pOuter);
  this->CAI_Motor::CAI_Component::__vftable = (CAI_BlendedMotor_vtbl *)&CAI_BlendedMotor::`vftable'{for `CAI_Component'};
  this->CAI_Motor::CAI_ProxyMovementSink::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_ProxyMovementSink_vtbl *)&CAI_BlendedMotor::`vftable'{for `CAI_ProxyMovementSink'};
  this->m_scriptMove.m_Memory.m_pMemory = nullptr;
  this->m_scriptMove.m_Memory.m_nAllocationCount = 0;
  this->m_scriptMove.m_Memory.m_nGrowSize = 0;
  this->m_scriptMove.m_Size = 0;
  this->m_scriptMove.m_pElements = nullptr;
  this->m_scriptTurn.m_Memory.m_pMemory = nullptr;
  this->m_scriptTurn.m_Memory.m_nAllocationCount = 0;
  this->m_scriptTurn.m_Memory.m_nGrowSize = 0;
  this->m_scriptTurn.m_Size = 0;
  this->m_scriptTurn.m_pElements = nullptr;
  this->m_bDeceleratingToGoal = false;
  this->m_iPrimaryLayer = -1;
  this->m_nPrimarySequence = -1;
  this->m_iSecondaryLayer = -1;
  this->m_nSecondarySequence = -1;
  this->m_flSecondaryWeight = 0.0;
  this->m_nSavedGoalActivity = ACT_INVALID;
  this->m_nSavedTranslatedGoalActivity = ACT_INVALID;
  this->m_nGoalSequence = -1;
  this->m_nPrevMovementSequence = -1;
  this->m_nInteriorSequence = -1;
  this->m_flStartCycle = 0.0;
  this->m_flPredictiveSpeedAdjust = 1.0;
  this->m_flReactiveSpeedAdjust = 1.0;
  this->m_vecPrevOrigin1.x = 0.0;
  this->m_vecPrevOrigin1.y = 0.0;
  this->m_vecPrevOrigin1.z = 0.0;
  this->m_vecPrevOrigin2.x = 0.0;
  this->m_vecPrevOrigin2.y = 0.0;
  this->m_vecPrevOrigin2.z = 0.0;
  this->m_prevYaw = 0.0;
  this->m_doTurn = 0.0;
  this->m_doLeft = 0.0;
  this->m_doRight = 0.0;
  this->m_flNextTurnAct = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10154CD0
// Name: public: CAI_BaseActor::CAI_BaseActor(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseActor *__thiscall CAI_BaseActor::CAI_BaseActor(CAI_BaseActor *this)
{
  CAI_BaseNPC::CAI_BaseNPC(this);
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CAI_ExpresserSink::`vftable';
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_BaseActor_vtbl *)&CAI_BaseActor::`vftable'{for `CBaseCombatCharacter'};
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CAI_BaseActor::`vftable'{for `CAI_DefMovementSink'};
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&CAI_BaseActor::`vftable'{for `IAI_BehaviorBridge'};
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CAI_BaseActor::`vftable';
  this->m_fLatchedPositions = 0;
  this->m_latchedEyeOrigin = vec3_origin;
  this->m_latchedEyeDirection = vec3_origin;
  this->m_latchedHeadDirection = vec3_origin;
  this->m_flBlinktime = 0.0;
  this->m_hLookTarget.m_Index = -1;
  this->m_lookQueue.m_Memory.m_pMemory = nullptr;
  this->m_lookQueue.m_Memory.m_nAllocationCount = 0;
  this->m_lookQueue.m_Memory.m_nGrowSize = 0;
  this->m_lookQueue.m_Size = 0;
  this->m_lookQueue.m_pElements = nullptr;
  this->m_syntheticLookQueue.m_Memory.m_pMemory = nullptr;
  this->m_syntheticLookQueue.m_Memory.m_nAllocationCount = 0;
  this->m_syntheticLookQueue.m_Memory.m_nGrowSize = 0;
  this->m_syntheticLookQueue.m_Size = 0;
  this->m_syntheticLookQueue.m_pElements = nullptr;
  this->m_randomLookQueue.m_Memory.m_pMemory = nullptr;
  this->m_randomLookQueue.m_Memory.m_nAllocationCount = 0;
  this->m_randomLookQueue.m_Memory.m_nGrowSize = 0;
  this->m_randomLookQueue.m_Size = 0;
  this->m_randomLookQueue.m_pElements = nullptr;
  this->m_iszExpressionScene.pszValue = nullptr;
  this->m_hExpressionSceneEnt.m_Index = -1;
  this->m_iszExpressionOverride.pszValue = nullptr;
  this->m_iszIdleExpression.pszValue = nullptr;
  this->m_iszAlertExpression.pszValue = nullptr;
  this->m_iszCombatExpression.pszValue = nullptr;
  this->m_iszDeathExpression.pszValue = nullptr;
  this->m_bRemarkablePolling = false;
  memset(dst: (unsigned __int8 *)this->m_flextarget, value: 0, count: sizeof(this->m_flextarget));
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10154E20
// Name: public: virtual void CAI_BaseActor::ExpireCurrentRandomLookTarget(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::ExpireCurrentRandomLookTarget(CAI_BaseActor *this)
{
  this->m_flNextRandomLookTime = gpGlobals->curtime - 0.1;
}

//------------------------------------------------------------------------------
// Address: 0x10154E50
// Name: public: virtual CAI_BaseActor::~CAI_BaseActor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_BaseActor::~CAI_BaseActor(CAI_BaseActor *this)
{
  CAI_Expresser *m_pExpresser; // edi

  m_pExpresser = this->m_pExpresser;
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_BaseActor_vtbl *)&CAI_BaseActor::`vftable'{for `CBaseCombatCharacter'};
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CAI_DefMovementSink::IAI_MovementSink::__vftable = (CAI_DefMovementSink_vtbl *)&CAI_BaseActor::`vftable'{for `CAI_DefMovementSink'};
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::IAI_BehaviorBridge::__vftable = (IAI_BehaviorBridge_vtbl *)&CAI_BaseActor::`vftable'{for `IAI_BehaviorBridge'};
  this->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_ExpresserSink::__vftable = (CAI_ExpresserSink_vtbl *)&CAI_BaseActor::`vftable';
  if ( m_pExpresser != nullptr )
  {
    CAI_Expresser::~CAI_Expresser(this: m_pExpresser);
    free(pMem: m_pExpresser);
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_randomLookQueue);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_syntheticLookQueue);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_lookQueue);
  CAI_BaseNPC::~CAI_BaseNPC(this);
}

//------------------------------------------------------------------------------
// Address: 0x10154EF0
// Name: public: virtual class CAI_Motor __near * CAI_BlendingHost<class CAI_BehaviorHost<class CAI_BaseNPC>>::CreateMotor(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BlendedMotor *__thiscall CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC>>::CreateMotor(
        CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> > *this)
{
  unsigned __int8 *v2; // esi

  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 244);
  memset(dst: v2, value: 0, count: 0xF4u);
  if ( v2 != nullptr )
    return CAI_BlendedMotor::CAI_BlendedMotor(this: (CAI_BlendedMotor *)v2, pOuter: this);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101551A0
// Name: public: virtual float CGenericActor::MaxYawSpeed(void)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CGenericActor::MaxYawSpeed(CGenericActor *this)
{
  return 90.0;
}

//------------------------------------------------------------------------------
// Address: 0x10404E60
// Name: CGenericActor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CGenericActor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CGenericActor>(__formal: nullptr);
  CGenericActor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10404E70
// Name: CFlextalkActor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFlextalkActor_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFlextalkActor>(__formal: nullptr);
  CFlextalkActor_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1012AC80
// Name: class CFlexExpresser __near * _CreateEntityTemplate<class CFlexExpresser>(class CFlexExpresser __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CFlexExpresser *__cdecl _CreateEntityTemplate<CFlexExpresser>(CFlexExpresser *newEnt, const char *className)
{
  CBaseFlex *v2; // eax
  _DWORD *v3; // esi

  v2 = (CBaseFlex *)CBaseEntity::operator new(stAllocateBlock: 0x7BCu);
  v3 = &v2->__vftable;
  if ( v2 != nullptr )
  {
    CBaseFlex::CBaseFlex(this: v2);
    v3[490] = 0;
    v3[491] = 0;
    v3[493] = &CAI_ExpresserSink::`vftable';
    *v3 = &CFlexExpresser::`vftable'{for `CFlexExpresserShim'};
    v3[493] = &CFlexExpresser::`vftable'{for `CAI_ExpresserSink'};
    v3[492] = 0;
    v3[494] = 0;
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CFlexExpresser *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154F30
// Name: class CGenericActor __near * _CreateEntityTemplate<class CGenericActor>(class CGenericActor __near *,char const __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CGenericActor *__cdecl _CreateEntityTemplate<CGenericActor>(CGenericActor *newEnt, const char *className)
{
  CAI_BaseActor *v2; // eax
  _DWORD *v3; // esi

  v2 = (CAI_BaseActor *)CBaseEntity::operator new(stAllocateBlock: 0x10A0u);
  v3 = &v2->CAI_ExpresserHost<CAI_BaseHumanoid>::CAI_BaseHumanoid::CAI_BlendingHost<CAI_BehaviorHost<CAI_BaseNPC> >::CAI_BehaviorHost<CAI_BaseNPC>::CAI_BehaviorHostBase<CAI_BaseNPC>::CAI_BaseNPC::CBaseCombatCharacter::CBaseFlex::CBaseAnimatingOverlay::CBaseAnimating::CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable;
  if ( v2 != nullptr )
  {
    CAI_BaseActor::CAI_BaseActor(this: v2);
    *v3 = &CGenericActor::`vftable'{for `CBaseCombatCharacter'};
    v3[571] = &CGenericActor::`vftable'{for `CAI_DefMovementSink'};
    v3[572] = &CGenericActor::`vftable'{for `IAI_BehaviorBridge'};
    v3[930] = &CGenericActor::`vftable';
    (*(void (__thiscall **)(_DWORD *, const char *))(*v3 + 112))(a1: v3, a2: className);
    return (CGenericActor *)v3;
  }
  else
  {
    (*(void (__thiscall **)(_DWORD, const char *))(MEMORY[0] + 112))(a1: 0, a2: className);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10154FF0
// Name: struct datamap_t __near * DataMapInit<class CGenericActor>(class CGenericActor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CGenericActor>()
{
  if ( (_S2_130 & 1) == 0 )
  {
    _S2_130 |= 1u;
    nameHolder_227.m_pszBase = "CGenericActor";
    nameHolder_227.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_227.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_227.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_227.m_Names.m_Size = 0;
    nameHolder_227.m_Names.m_pElements = nullptr;
    nameHolder_227.m_nLenBase = 13;
    atexit(func: DataMapInit_CGenericActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CGenericActor::m_DataMap.baseMap = &CAI_BaseActor::m_DataMap;
  CGenericActor::m_DataMap.dataNumFields = 1;
  CGenericActor::m_DataMap.dataDesc = &dataDesc_215[1];
  return &CGenericActor::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10155060
// Name: struct datamap_t __near * DataMapInit<class CFlextalkActor>(class CFlextalkActor __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFlextalkActor>()
{
  if ( (_S3_72 & 1) == 0 )
  {
    _S3_72 |= 1u;
    nameHolder_228.m_pszBase = "CFlextalkActor";
    nameHolder_228.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_228.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_228.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_228.m_Names.m_Size = 0;
    nameHolder_228.m_Names.m_pElements = nullptr;
    nameHolder_228.m_nLenBase = 14;
    atexit(func: DataMapInit_CFlextalkActor__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFlextalkActor::m_DataMap.baseMap = &CGenericActor::m_DataMap;
  CFlextalkActor::m_DataMap.dataNumFields = 11;
  CFlextalkActor::m_DataMap.dataDesc = &dataDesc_216[1];
  return &CFlextalkActor::m_DataMap;
}
