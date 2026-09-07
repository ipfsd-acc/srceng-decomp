// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_expresserfollowup.cpp
// Functions: 19
// ============================================================

#include "game\server\ai_expresserfollowup.h"

//------------------------------------------------------------------------------
// Address: 0x100501B0
// Name: GetSpeechDurationForResponse
// Source: json
//------------------------------------------------------------------------------
int __userpurge GetSpeechDurationForResponse@<xmm0>(const ResponseRules::CRR_Response *response@<ecx>)
{
  char sceneName[256]; // [esp+0h] [ebp-110h] BYREF
  SceneCachedData_t scenedata; // [esp+100h] [ebp-10h] BYREF

  ResponseRules::CRR_Response::GetResponse(
    this: (ResponseRules::CRR_Response *)response,
    buf: sceneName,
    buflen: 0x100u);
  if ( scenefilecache->GetSceneCachedData(this: scenefilecache, a2: sceneName, a3: &scenedata) )
    return LODWORD(scenedata.m_fLastSpeakSecs);
  else
    return -1082130432;
}

//------------------------------------------------------------------------------
// Address: 0x10050200
// Name: public: virtual void CAI_ExpresserWithFollowup::OnSpeechFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserWithFollowup::OnSpeechFinished(CAI_ExpresserWithFollowup *this)
{
  ResponseRules::AI_ResponseFollowup *m_pPostponedFollowup; // eax

  m_pPostponedFollowup = this->m_pPostponedFollowup;
  if ( m_pPostponedFollowup != nullptr
    && m_pPostponedFollowup->followup_concept != nullptr
    && m_pPostponedFollowup->followup_contexts != nullptr )
  {
    this->SpeakDispatchFollowup(this, a2: this->m_pPostponedFollowup);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050220
// Name: public: char const __near * CCommand::operator[](int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CCommand::operator[](CCommand *this, int nIndex)
{
  if ( nIndex < 0 || nIndex >= this->m_nArgc )
    return locale;
  else
    return this->m_ppArgv[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x10050250
// Name: ResolveFollowupTargetToEntity
// Source: json
//------------------------------------------------------------------------------
CResponseQueue::CFollowupTargetSpec_t *__usercall ResolveFollowupTargetToEntity@<eax>(
        const char *szTarget@<edi>,
        _DWORD *a2@<esi>,
        CAI_Concept *concept,
        ResponseRules::CriteriaSet *criteria)
{
  unsigned int m_Index; // eax
  int CriterionIndex; // eax
  const char *Value; // eax
  CBaseEntity *EntityByName; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax
  CBaseEntity *v11; // eax
  unsigned int v12; // edx
  CHandle<CBaseEntity> v13; // [esp+4h] [ebp-4h] BYREF

  if ( _V_stricmp(s1: szTarget, s2: "self") == 0 )
  {
    m_Index = concept->m_hSpeaker.m_Index;
    *a2 = 2;
    a2[1] = m_Index;
    return (CResponseQueue::CFollowupTargetSpec_t *)a2;
  }
  if ( _V_stricmp(s1: szTarget, s2: "subject") == 0 )
  {
    CriterionIndex = ResponseRules::CriteriaSet::FindCriterionIndex(this: criteria, name: "Subject");
LABEL_5:
    Value = ResponseRules::CriteriaSet::GetValue(this: criteria, index: CriterionIndex);
    if ( Value != nullptr
      && (EntityByName = CGlobalEntityList::FindEntityByName(
                           this: &gEntList,
                           pStartEntity: nullptr,
                           szName: Value,
                           pSearchingEntity: nullptr,
                           pActivator: nullptr,
                           pCaller: nullptr,
                           pFilter: nullptr)) != nullptr )
    {
      v9 = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
      *a2 = 2;
      a2[1] = v9;
      return (CResponseQueue::CFollowupTargetSpec_t *)a2;
    }
    else
    {
      *a2 = 2;
      a2[1] = -1;
      return (CResponseQueue::CFollowupTargetSpec_t *)a2;
    }
  }
  if ( _V_stricmp(s1: szTarget, s2: "from") == 0 )
  {
    CriterionIndex = ResponseRules::CriteriaSet::FindCriterionIndex(this: criteria, name: "From");
    goto LABEL_5;
  }
  if ( _V_stricmp(s1: szTarget, s2: "any") != 0 )
  {
    if ( _V_stricmp(s1: szTarget, s2: "all") != 0 )
    {
      v11 = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: nullptr,
              szName: szTarget,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr);
      if ( v11 != nullptr )
      {
        CHandle<CBaseEntity>::CHandle<CBaseEntity>(this: &v13, pObj: v11);
        v12 = v13.m_Index;
        *a2 = 2;
        a2[1] = v12;
      }
      else
      {
        _Warning(a1: "Couldn't resolve response target %s\n", szTarget);
        *a2 = 3;
        a2[1] = -1;
      }
      return (CResponseQueue::CFollowupTargetSpec_t *)a2;
    }
    else
    {
      *a2 = 1;
      a2[1] = -1;
      return (CResponseQueue::CFollowupTargetSpec_t *)a2;
    }
  }
  else
  {
    v10 = concept->m_hSpeaker.m_Index;
    *a2 = 0;
    a2[1] = v10;
    return (CResponseQueue::CFollowupTargetSpec_t *)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100503B0
// Name: ResolveFollowupTargetToEntity_0
// Source: json
//------------------------------------------------------------------------------
CAI_Concept *__usercall ResolveFollowupTargetToEntity_0@<eax>(
        ResponseRules::CriteriaSet *criteria@<ecx>,
        ResponseRules::AI_ResponseFollowup *followup@<eax>,
        CAI_Concept *concept,
        CAI_Concept *response)
{
  const char *followup_target; // edi

  followup_target = followup->followup_target;
  if ( followup_target != nullptr )
  {
    ResolveFollowupTargetToEntity(szTarget: followup_target, a2: concept, concept: response, criteria);
  }
  else
  {
    *(_DWORD *)&concept->m_iConcept.m_Id = 3;
    concept->m_hSpeaker.m_Index = -1;
  }
  return concept;
}

//------------------------------------------------------------------------------
// Address: 0x10050450
// Name: public: class CBaseFlex __near * CAI_Expresser::GetOuter(void)
// Source: json
//------------------------------------------------------------------------------
CBaseFlex *__thiscall CAI_Expresser::GetOuter(CAI_Expresser *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseFlex *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100505A0
// Name: public: virtual bool CAI_ExpresserWithFollowup::Speak(class CAI_Concept __near &,char const __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ExpresserWithFollowup::Speak(
        CAI_ExpresserWithFollowup *this,
        CAI_Concept *concept,
        const char *modifiers,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  IHandleEntity *v12; // ecx
  unsigned int v13; // eax
  CBaseEntity *v14; // ecx
  const char *v15; // eax
  unsigned int v16; // eax
  CBaseEntity *v17; // ecx
  const char *DebugName; // eax
  const char *StringConcept; // eax
  unsigned int v20; // ecx
  IHandleEntity *v21; // ebx
  IHandleEntity *v22; // edx
  const char *v23; // edi
  CBaseEntity *v24; // ecx
  bool v25; // bl
  ResponseRules::CRR_Response v26; // [esp+18h] [ebp-CCh] BYREF
  ResponseRules::CriteriaSet criteria; // [esp+C0h] [ebp-24h] BYREF

  if ( IAI_BehaviorBridge::BehaviorBridge_IsCurTaskContinuousMove((vgui::ToggleButton *)this) )
    return false;
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    v10 = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
  }
  else
  {
    v10 = -1;
  }
  concept->m_hSpeaker.m_Index = v10;
  ResponseRules::CriteriaSet::CriteriaSet(this: &criteria);
  CAI_Expresser::GatherCriteria(this, outputSet: &criteria, concept, modifiers);
  v11 = this->m_pOuter.m_Index;
  if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
    v12 = nullptr;
  else
    v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *, ResponseRules::CriteriaSet *))v12->__vftable[40].GetRefEHandle)(
    a1: v12,
    a2: &criteria);
  ResponseRules::CRR_Response::CRR_Response(this: &v26);
  if ( CAI_Expresser::FindResponse(this, outResponse: &v26, concept, &criteria) )
  {
    if ( chet_debug_idle.m_pParent != nullptr && chet_debug_idle.m_pParent->m_Value.m_nValue != 0 )
    {
      v16 = this->m_pOuter.m_Index;
      if ( v16 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16) )
        v17 = nullptr;
      else
        v17 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity;
      DebugName = CBaseEntity::GetDebugName(this: v17);
      _Msg(a1: "TLK_IDLE: %s SUCCESSFUL FindResponse\n", DebugName);
    }
    StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: concept);
    v20 = this->m_pOuter.m_Index;
    if ( v20 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
      v21 = nullptr;
    else
      v21 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
    if ( v20 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
      v22 = nullptr;
    else
      v22 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
    v23 = (const char *)v22[51].__vftable;
    if ( v23 == nullptr )
      v23 = locale;
    if ( v20 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
      v24 = nullptr;
    else
      v24 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
    CAI_Expresser::SpeechMsg(
      this,
      pFlex: v24,
      pszFormat: "%s (%x) spoke %s (%f)",
      v23,
      v21,
      StringConcept,
      gpGlobals->curtime);
    v25 = this->SpeakDispatchResponse(this, a2: concept, a3: &v26, a4: &criteria, a5: filter);
    if ( pszOutResponseChosen != nullptr )
      ResponseRules::CRR_Response::GetResponse(this: &v26, buf: pszOutResponseChosen, buflen: bufsize);
    ResponseRules::CRR_Response::~CRR_Response(this: &v26);
    CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &criteria.m_Lookup);
    return v25;
  }
  else
  {
    if ( chet_debug_idle.m_pParent != nullptr && chet_debug_idle.m_pParent->m_Value.m_nValue != 0 )
    {
      v13 = this->m_pOuter.m_Index;
      if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
        v14 = nullptr;
      else
        v14 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
      v15 = CBaseEntity::GetDebugName(this: v14);
      _Msg(a1: "TLK_IDLE: %s did not FindResponse\n", v15);
    }
    ResponseRules::CRR_Response::~CRR_Response(this: &v26);
    CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &criteria.m_Lookup);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050830
// Name: protected: static void CAI_ExpresserWithFollowup::DispatchFollowupThroughQueue(class CAI_Concept const __near &,char const __near *,struct CResponseQueue::CFollowupTargetSpec_t const __near &,float,class CBaseEntity restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CAI_ExpresserWithFollowup::DispatchFollowupThroughQueue(
        const CAI_Concept *concept,
        const char *criteriaStr,
        const CResponseQueue::CFollowupTargetSpec_t *target,
        float delay,
        CBaseEntity *pOuter)
{
  const char *pszValue; // eax
  ResponseRules::CriteriaSet criteria; // [esp+10h] [ebp-24h] BYREF

  ResponseRules::CriteriaSet::CriteriaSet(this: &criteria);
  pszValue = pOuter->m_iName.m_Value.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  ResponseRules::CriteriaSet::AppendCriteria(this: &criteria, pCriteriaName: "From", value: pszValue, weight: 1.0);
  ResponseRules::CriteriaSet::Merge(this: &criteria, modifiers: criteriaStr);
  CResponseQueue::Add(
    this: g_ResponseQueueManager.m_pQueue,
    concept,
    contexts: &criteria,
    time: gpGlobals->curtime + delay,
    targetspec: target,
    pIssuer: pOuter);
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &criteria.m_Lookup);
}

//------------------------------------------------------------------------------
// Address: 0x100508C0
// Name: public: virtual void CAI_ExpresserWithFollowup::SpeakDispatchFollowup(struct ResponseRules::AI_ResponseFollowup __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ExpresserWithFollowup::SpeakDispatchFollowup(
        CAI_ExpresserWithFollowup *this,
        ResponseRules::AI_ResponseFollowup *followup)
{
  DeferredResponseTarget_t m_iTargetType; // eax
  CResponseQueue::CFollowupTargetSpec_t *p_m_followupTarget; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  CAI_Concept v7; // [esp+14h] [ebp-8h] BYREF

  m_iTargetType = this->m_followupTarget.m_iTargetType;
  p_m_followupTarget = &this->m_followupTarget;
  if ( (unsigned int)m_iTargetType <= kDRT_SPECIFIC
    && (m_iTargetType != kDRT_SPECIFIC || this->m_followupTarget.m_hHandle.m_Index != -1) )
  {
    ResponseRules::CRR_Concept::CRR_Concept(this: &v7, fromString: followup->followup_concept);
    m_Index = this->m_pOuter.m_Index;
    v7.m_hSpeaker.m_Index = -1;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    CAI_ExpresserWithFollowup::DispatchFollowupThroughQueue(
      concept: &v7,
      criteriaStr: followup->followup_contexts,
      target: p_m_followupTarget,
      delay: followup->followup_delay,
      pOuter: m_pEntity);
    this->m_pPostponedFollowup = nullptr;
    p_m_followupTarget->m_iTargetType = kDRT_MAX;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050960
// Name: void CC_RR_ForceConcept_f(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_RR_ForceConcept_f(const CCommand *args)
{
  const char *v1; // eax
  const char *v2; // eax
  bool v3; // cc
  const char *v4; // esi
  CResponseQueue::CFollowupTargetSpec_t *v5; // eax
  ResponseRules::CriteriaSet criteria; // [esp+14h] [ebp-34h] BYREF
  int v7; // [esp+38h] [ebp-10h] BYREF
  CAI_Concept concept; // [esp+40h] [ebp-8h] BYREF

  if ( args->m_nArgc >= 3 )
  {
    ResponseRules::CriteriaSet::CriteriaSet(this: &criteria);
    if ( args->m_nArgc >= 3 )
    {
      v1 = locale;
      if ( args->m_nArgc > 3 )
        v1 = args->m_ppArgv[3];
      ResponseRules::CriteriaSet::Merge(this: &criteria, modifiers: v1);
    }
    v2 = locale;
    if ( args->m_nArgc > 2 )
      v2 = args->m_ppArgv[2];
    ResponseRules::CRR_Concept::CRR_Concept(this: &concept, fromString: v2);
    v3 = args->m_nArgc <= 1;
    concept.m_hSpeaker.m_Index = -1;
    if ( v3 )
      v4 = locale;
    else
      v4 = args->m_ppArgv[1];
    v5 = ResolveFollowupTargetToEntity(szTarget: v4, a2: &v7, &concept, &criteria);
    CResponseQueue::Add(
      this: g_ResponseQueueManager.m_pQueue,
      &concept,
      contexts: &criteria,
      time: 0.0,
      targetspec: v5,
      pIssuer: nullptr);
    CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &criteria.m_Lookup);
  }
  else
  {
    _Msg(a1: "USAGE: rr_forceconcept <target> <concept> \"criteria1:value1,criteria2:value2,...\"\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x10050A20
// Name: public: virtual bool CAI_ExpresserWithFollowup::SpeakDispatchResponse(class CAI_Concept __near &,class ResponseRules::CRR_Response __near *,class ResponseRules::CriteriaSet __near *,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ExpresserWithFollowup::SpeakDispatchResponse(
        CAI_ExpresserWithFollowup *this,
        CAI_Concept *concept,
        ResponseRules::CRR_Response *response,
        ResponseRules::CriteriaSet *criteria,
        IRecipientFilter *filter)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v8; // eax
  bool result; // al
  unsigned int v11; // eax
  const CBaseEntity *v12; // ecx
  ResponseRules::AI_ResponseFollowup *m_pFollowup; // edi
  const char *followup_entityiotarget; // eax
  CBaseFlex *Outer; // eax
  const char *followup_concept; // eax
  unsigned __int8 m_Type; // dl
  CBaseFlex *v19; // eax
  float v20; // xmm0_4
  CAI_Concept *v21; // eax
  CAI_Concept *v22; // eax
  variant_t v23; // [esp-14h] [ebp-68h]
  CBaseFlex *delay; // [esp+8h] [ebp-4Ch]
  CBaseEntity *v25; // [esp+Ch] [ebp-48h]
  CBaseFlex *v26; // [esp+Ch] [ebp-48h]
  ResponseRules::CriteriaSet tmpCriteria; // [esp+1Ch] [ebp-38h] BYREF
  CAI_Concept v28; // [esp+40h] [ebp-14h] BYREF
  CAI_Concept v29; // [esp+48h] [ebp-Ch] BYREF
  bool bInterrupted; // [esp+53h] [ebp-1h]
  float responsea; // [esp+60h] [ebp+Ch]
  float responseb; // [esp+60h] [ebp+Ch]
  CBaseEntity *fTimeToLastSpeech; // [esp+64h] [ebp+10h]
  float fTimeToLastSpeecha; // [esp+64h] [ebp+10h]
  bool bSuc_3; // [esp+6Bh] [ebp+17h]

  if ( concept->m_hSpeaker.m_Index == -1 )
  {
    m_Index = this->m_pOuter.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
    {
      v8 = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
    }
    else
    {
      v8 = -1;
    }
    concept->m_hSpeaker.m_Index = v8;
  }
  bInterrupted = this->IsSpeaking(this);
  result = CAI_Expresser::SpeakDispatchResponse(this, concept, result: response, criteria, filter);
  bSuc_3 = result;
  if ( result )
  {
    if ( bInterrupted )
    {
      v11 = this->m_pOuter.m_Index;
      if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
        v12 = nullptr;
      else
        v12 = (const CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
      CResponseQueue::RemoveSpeechQueuedFor(this: g_ResponseQueueManager.m_pQueue, pSpeaker: v12);
    }
    m_pFollowup = response->m_Params.m_pFollowup;
    if ( m_pFollowup != nullptr )
    {
      followup_entityiotarget = m_pFollowup->followup_entityiotarget;
      if ( followup_entityiotarget != nullptr && m_pFollowup->followup_entityioinput != nullptr && criteria != nullptr )
      {
        fTimeToLastSpeech = CGlobalEntityList::FindEntityByName(
                              this: &gEntList,
                              pStartEntity: nullptr,
                              szName: followup_entityiotarget,
                              pSearchingEntity: nullptr,
                              pActivator: nullptr,
                              pCaller: nullptr,
                              pFilter: nullptr);
        if ( fTimeToLastSpeech != nullptr )
        {
          delay = CAI_Expresser::GetOuter(this);
          Outer = CAI_Expresser::GetOuter(this);
          v23.iVal = 0;
          *(_QWORD *)&v23.eVal.m_Index = 0xFFFFFFFFLL;
          CEventQueue::AddEvent(
            this: &g_EventQueue,
            target: fTimeToLastSpeech,
            targetInput: m_pFollowup->followup_entityioinput,
            Value: v23,
            fireDelay: m_pFollowup->followup_entityiodelay,
            pActivator: Outer,
            pCaller: delay,
            outputID: 0);
        }
      }
      followup_concept = m_pFollowup->followup_concept;
      if ( m_pFollowup->followup_concept != nullptr && m_pFollowup->followup_contexts != nullptr )
      {
        m_Type = response->m_Type;
        if ( response->m_Type == 3 && (responsea = m_pFollowup->followup_delay) >= 0.0 )
        {
          fTimeToLastSpeecha = COERCE_FLOAT(GetSpeechDurationForResponse(response));
          if ( fTimeToLastSpeecha > 0.0 )
          {
            ResponseRules::CRR_Concept::CRR_Concept(this: &v29, fromString: m_pFollowup->followup_concept);
            v29.m_hSpeaker.m_Index = -1;
            v19 = CAI_Expresser::GetOuter(this);
            v20 = responsea + fTimeToLastSpeecha;
LABEL_32:
            v25 = v19;
            v21 = ResolveFollowupTargetToEntity_0(criteria, followup: m_pFollowup, concept: &v28, response: concept);
            CAI_ExpresserWithFollowup::DispatchFollowupThroughQueue(
              concept: &v29,
              criteriaStr: m_pFollowup->followup_contexts,
              target: (const CResponseQueue::CFollowupTargetSpec_t *)v21,
              delay: v20,
              pOuter: v25);
            return bSuc_3;
          }
          this->m_pPostponedFollowup = m_pFollowup;
          if ( criteria != nullptr )
          {
LABEL_28:
            this->m_followupTarget = (CResponseQueue::CFollowupTargetSpec_t)*ResolveFollowupTargetToEntity_0(
                                                                               criteria,
                                                                               followup: m_pFollowup,
                                                                               concept: &v28,
                                                                               response: concept);
            return bSuc_3;
          }
        }
        else
        {
          responseb = m_pFollowup->followup_delay;
          if ( responseb < 0.0 )
          {
            ResponseRules::CRR_Concept::CRR_Concept(this: &v29, fromString: followup_concept);
            v29.m_hSpeaker.m_Index = -1;
            v19 = CAI_Expresser::GetOuter(this);
            LODWORD(v20) = LODWORD(responseb) ^ _mask__NegFloat_;
            goto LABEL_32;
          }
          if ( m_Type == 5 )
          {
            ResponseRules::CRR_Concept::CRR_Concept(this: &v29, fromString: followup_concept);
            v29.m_hSpeaker.m_Index = -1;
            v26 = CAI_Expresser::GetOuter(this);
            v22 = ResolveFollowupTargetToEntity_0(criteria, followup: m_pFollowup, concept: &v28, response: concept);
            CAI_ExpresserWithFollowup::DispatchFollowupThroughQueue(
              concept: &v29,
              criteriaStr: m_pFollowup->followup_contexts,
              target: (const CResponseQueue::CFollowupTargetSpec_t *)v22,
              delay: responseb,
              pOuter: v26);
            return bSuc_3;
          }
          this->m_pPostponedFollowup = m_pFollowup;
          if ( criteria != nullptr )
            goto LABEL_28;
        }
        ResponseRules::CriteriaSet::CriteriaSet(this: &tmpCriteria);
        this->m_followupTarget = (CResponseQueue::CFollowupTargetSpec_t)*ResolveFollowupTargetToEntity_0(
                                                                           criteria: &tmpCriteria,
                                                                           followup: this->m_pPostponedFollowup,
                                                                           concept: &v28,
                                                                           response: concept);
        CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &tmpCriteria.m_Lookup);
      }
    }
    return bSuc_3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10417DD0
// Name: _dynamic_initializer_for__ResponseRules::CriteriaSet::sm_CriteriaSymbols__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__ResponseRules::CriteriaSet::sm_CriteriaSymbols__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols,
    growSize: 1024,
    initSize: 1024,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__ResponseRules::CriteriaSet::sm_CriteriaSymbols__);
}

//------------------------------------------------------------------------------
// Address: 0x10422BE0
// Name: _dynamic_atexit_destructor_for__ResponseRules::CriteriaSet::sm_CriteriaSymbols__
// Source: semantic_dyn_outer_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__ResponseRules::CriteriaSet::sm_CriteriaSymbols__()
{
  CUtlSymbolTable::~CUtlSymbolTable(this: &ResponseRules::CriteriaSet::sm_CriteriaSymbols);
}

//------------------------------------------------------------------------------
// Address: 0x10417E00
// Name: _dynamic_initializer_for__rr_debug_responseconcept_exclude__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__rr_debug_responseconcept_exclude__()
{
  ConCommand::ConCommand(
    this: &rr_debug_responseconcept_exclude,
    pName: "rr_debugresponseconcept_exclude",
    callback: CC_RR_Debug_ResponseConcept_Exclude,
    pHelpString: "Set a list of concepts to exclude from rr_debugresponseconcept. Separate multiple concepts with spaces. Call with no"
    " arguments to see current list. Call 'rr_debug_responseconcept_exclude !' to reset.",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__rr_debug_responseconcept_exclude__);
}

//------------------------------------------------------------------------------
// Address: 0x10422BF0
// Name: _dynamic_atexit_destructor_for__rr_debug_responseconcept_exclude__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_debug_responseconcept_exclude__()
{
  ConCommand::~ConCommand(this: &rr_debug_responseconcept_exclude);
}

//------------------------------------------------------------------------------
// Address: 0x10422C00
// Name: _dynamic_atexit_destructor_for__rr_debugresponses__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_debugresponses__()
{
  ConVar::~ConVar(this: &rr_debugresponses);
}

//------------------------------------------------------------------------------
// Address: 0x10422C10
// Name: _dynamic_atexit_destructor_for__rr_debugrule__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_debugrule__()
{
  ConVar::~ConVar(this: &rr_debugrule);
}

//------------------------------------------------------------------------------
// Address: 0x10422C20
// Name: _dynamic_atexit_destructor_for__rr_dumpresponses__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_dumpresponses__()
{
  ConVar::~ConVar(this: &rr_dumpresponses);
}

//------------------------------------------------------------------------------
// Address: 0x10422C30
// Name: _dynamic_atexit_destructor_for__rr_debugresponseconcept__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__rr_debugresponseconcept__()
{
  ConVar::~ConVar(this: &rr_debugresponseconcept);
}
