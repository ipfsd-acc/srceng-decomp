// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_speech.cpp
// Functions: 40
// ============================================================

#include "game\server\ai_speech.h"

//------------------------------------------------------------------------------
// Address: 0x10086D00
// Name: public: static class RR::CApplyContextOperator __near * RR::CApplyContextOperator::FindOperator(char const __near *)
// Source: json
//------------------------------------------------------------------------------
RR::CIncrementOperator *__cdecl RR::CApplyContextOperator::FindOperator(const char *pContextString)
{
  char v1; // cl
  RR::CIncrementOperator *result; // eax

  if ( pContextString == nullptr )
    return (RR::CIncrementOperator *)&RR::sm_OpCopy;
  v1 = *pContextString;
  if ( *pContextString == 0 )
    return (RR::CIncrementOperator *)&RR::sm_OpCopy;
  if ( v1 == 43 && pContextString[1] == 43 && pContextString[2] != 0 )
    return &RR::sm_OpIncrement;
  if ( v1 == 45 && pContextString[1] == 45 && pContextString[2] != 0 )
    return (RR::CIncrementOperator *)&RR::sm_OpDecrement;
  result = (RR::CIncrementOperator *)&RR::sm_OpToggle;
  if ( v1 != 33 )
    return (RR::CIncrementOperator *)&RR::sm_OpCopy;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10086D50
// Name: public: virtual bool RR::CApplyContextOperator::Apply(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall RR::CApplyContextOperator::Apply(
        RR::CApplyContextOperator *this,
        const char *pOldValue,
        const char *pOperator,
        char *pNewValue,
        int pNewValBufSize)
{
  if ( pOperator != nullptr )
    V_strncpy(pDest: pNewValue, pSrc: pOperator, maxLen: pNewValBufSize);
  else
    *pNewValue = 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10086D80
// Name: public: virtual bool RR::CIncrementOperator::Apply(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall RR::CIncrementOperator::Apply(
        RR::CIncrementOperator *this,
        const char *pOldValue,
        const char *pOperator,
        char *pNewValue,
        int pNewValBufSize)
{
  int v6; // esi
  int v7; // eax

  if ( pOldValue != nullptr )
    v6 = V_atoi(str: pOldValue);
  else
    v6 = 0;
  v7 = V_atoi(str: &pOperator[this->m_nSkipChars]);
  V_snprintf(pDest: pNewValue, maxLen: pNewValBufSize, pFormat: "%d", v6 + v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10086DD0
// Name: public: virtual bool RR::CDecrementOperator::Apply(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall RR::CDecrementOperator::Apply(
        RR::CDecrementOperator *this,
        const char *pOldValue,
        const char *pOperator,
        char *pNewValue,
        int pNewValBufSize)
{
  int v6; // esi
  int v7; // eax

  if ( pOldValue != nullptr )
    v6 = V_atoi(str: pOldValue);
  else
    v6 = 0;
  v7 = V_atoi(str: &pOperator[this->m_nSkipChars]);
  V_snprintf(pDest: pNewValue, maxLen: pNewValBufSize, pFormat: "%d", v6 - v7);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10086E20
// Name: public: virtual bool RR::CToggleOperator::Apply(char const __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall RR::CToggleOperator::Apply(
        RR::CToggleOperator *this,
        const char *pOldValue,
        const char *pOperator,
        char *pNewValue,
        int pNewValBufSize)
{
  int v5; // eax

  if ( pOldValue != nullptr )
    v5 = V_atoi(str: pOldValue);
  else
    v5 = 0;
  V_snprintf(pDest: pNewValue, maxLen: pNewValBufSize, pFormat: "%d", v5 == 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10086E60
// Name: public: bool CAI_Expresser::CanSpeak(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Expresser::CanSpeak(CAI_Expresser *this)
{
  float curtime; // xmm2_4
  float m_flStopTalkTime; // xmm0_4

  curtime = gpGlobals->curtime;
  if ( this->m_flLastTimeAcceptedSpeak == curtime )
    return false;
  m_flStopTalkTime = this->m_flStopTalkTime;
  if ( m_flStopTalkTime <= this->m_flBlockedTalkTime )
    m_flStopTalkTime = this->m_flBlockedTalkTime;
  return curtime >= m_flStopTalkTime;
}

//------------------------------------------------------------------------------
// Address: 0x10086EA0
// Name: public: bool CAI_Expresser::CanSpeakAfterMyself(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Expresser::CanSpeakAfterMyself(CAI_Expresser *this)
{
  float curtime; // xmm2_4
  float m_flStopTalkTimeWithoutDelay; // xmm0_4

  curtime = gpGlobals->curtime;
  if ( this->m_flLastTimeAcceptedSpeak == curtime )
    return false;
  m_flStopTalkTimeWithoutDelay = this->m_flStopTalkTimeWithoutDelay;
  if ( m_flStopTalkTimeWithoutDelay <= this->m_flBlockedTalkTime )
    m_flStopTalkTimeWithoutDelay = this->m_flBlockedTalkTime;
  return curtime >= m_flStopTalkTimeWithoutDelay;
}

//------------------------------------------------------------------------------
// Address: 0x10086EE0
// Name: public: void CMultiplayer_Expresser::AllowMultipleScenes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayer_Expresser::AllowMultipleScenes(CMultiplayer_Expresser *this)
{
  this->m_bAllowMultipleScenes = true;
}

//------------------------------------------------------------------------------
// Address: 0x10086EF0
// Name: public: void CMultiplayer_Expresser::DisallowMultipleScenes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMultiplayer_Expresser::DisallowMultipleScenes(CMultiplayer_Expresser *this)
{
  this->m_bAllowMultipleScenes = false;
}

//------------------------------------------------------------------------------
// Address: 0x10086F40
// Name: public: bool CAI_TimedSemaphore::IsAvailable(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_TimedSemaphore::IsAvailable(CAI_TimedSemaphore *this, CBaseEntity *pTalker)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  BOOL result; // eax

  result = true;
  if ( gpGlobals->curtime <= this->m_ReleaseTime )
  {
    m_Index = this->m_hCurrentTalker.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( m_pEntity != pTalker )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10086FB0
// Name: public: bool CAI_Expresser::SemaphoreIsAvailable(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Expresser::SemaphoreIsAvailable(CAI_Expresser *this, CBaseEntity *pTalker)
{
  CAI_BaseNPC *v3; // esi
  int v4; // eax
  char v5; // al
  CAI_TimedSemaphore *v6; // ecx

  if ( !this->m_pSink->UseSemaphore(this: this->m_pSink) )
    return true;
  v3 = pTalker->MyNPCPointer(this: pTalker);
  if ( v3->MyNPCPointer(this: v3) == nullptr )
    return true;
  v4 = (int)v3->MyNPCPointer(this: v3);
  v5 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 1772))(a1: v4, a2: 0);
  v6 = &g_AIFriendliesTalkSemaphore;
  if ( v5 == 0 )
    v6 = &g_AIFoesTalkSemaphore;
  return CAI_TimedSemaphore::IsAvailable(this: v6, pTalker);
}

//------------------------------------------------------------------------------
// Address: 0x10087030
// Name: void CAI_ExpresserHost_NPC_DoModifyOrAppendCriteria(class CAI_BaseNPC __near *,class ResponseRules::CriteriaSet __near &)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall CAI_ExpresserHost_NPC_DoModifyOrAppendCriteria(
        int a1@<ebp>,
        int a2@<edi>,
        int a3@<esi>,
        CAI_BaseNPC *pSpeaker,
        ResponseRules::CriteriaSet *set)
{
  const char *ActivityName; // eax
  NPC_STATE m_NPCState; // eax
  const char *v7; // eax
  const char *pszValue; // eax
  float m_flLastEnemyTime; // xmm0_4
  Vector *v10; // eax
  float v11; // xmm0_4
  const char *v12; // eax
  CBaseCombatWeapon *ActiveWeapon; // eax
  const char *v14; // eax
  CBasePlayer *LocalPlayer; // edi
  const char *v16; // eax
  bool HasCondition; // al
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20[2]; // [esp+3Ch] [ebp-18h] BYREF
  float v21; // [esp+44h] [ebp-10h]
  _DWORD v22[3]; // [esp+48h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+54h] [ebp+0h]

  v22[0] = a1;
  v22[1] = retaddr;
  ActivityName = CAI_BaseNPC::GetActivityName(actID: pSpeaker->m_Activity);
  if ( ActivityName != nullptr )
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "activity", value: ActivityName, weight: 1.0);
  m_NPCState = pSpeaker->m_NPCState;
  if ( (unsigned int)m_NPCState < NPC_STATE_DEAD )
  {
    v7 = UTIL_VarArgs(format: "[NPCState::%s]", pStateNames_1[m_NPCState]);
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "npcstate", value: v7, weight: 1.0);
  }
  if ( ((int (__thiscall *)(CAI_BaseNPC *, int, int))pSpeaker->GetEnemy_2)(a1: pSpeaker, a2, a3) != 0 )
  {
    pszValue = pSpeaker->GetEnemy_2(this: pSpeaker)->m_iClassname.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "enemy", value: pszValue, weight: 1.0);
    v21 = 1.0;
    LODWORD(v20[1]) = "-1";
  }
  else
  {
    m_flLastEnemyTime = pSpeaker->m_flLastEnemyTime;
    v21 = 1.0;
    if ( m_flLastEnemyTime == 0.0 )
      LODWORD(v20[1]) = "999999.0";
    else
      LODWORD(v20[1]) = UTIL_VarArgs(format: "%f", (float)(gpGlobals->curtime - m_flLastEnemyTime));
  }
  ResponseRules::CriteriaSet::AppendCriteria(
    this: set,
    pCriteriaName: "timesincecombat",
    value: (const char *)LODWORD(v20[1]),
    weight: v21);
  v10 = pSpeaker->GetSmoothedVelocity(this: pSpeaker, result: v20);
  v11 = fsqrt((float)((float)(v10->x * v10->x) + (float)(v10->y * v10->y)) + (float)(v10->z * v10->z));
  v20[1] = 1.0;
  v12 = UTIL_VarArgs(format: "%.3f", v11);
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "speed", value: v12, weight: v20[1]);
  ActiveWeapon = CBaseCombatCharacter::GetActiveWeapon(this: pSpeaker);
  if ( ActiveWeapon != nullptr )
  {
    v14 = ActiveWeapon->m_iClassname.pszValue;
    if ( v14 == nullptr )
      v14 = locale;
    v20[1] = 1.0;
    LODWORD(v20[0]) = v14;
  }
  else
  {
    v20[1] = 1.0;
    LODWORD(v20[0]) = "none";
  }
  ResponseRules::CriteriaSet::AppendCriteria(
    this: set,
    pCriteriaName: "weapon",
    value: (const char *)LODWORD(v20[0]),
    weight: v20[1]);
  if ( gpGlobals->maxClients > 1 )
  {
    LocalPlayer = nullptr;
LABEL_19:
    v20[1] = 1.0;
    v16 = UTIL_VarArgs(format: "%i", 0x4000);
    goto LABEL_20;
  }
  LocalPlayer = UTIL_GetLocalPlayer();
  if ( LocalPlayer == nullptr )
    goto LABEL_19;
  if ( (pSpeaker->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pSpeaker, a2: (int)v22);
  if ( (LocalPlayer->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: LocalPlayer, a2: (int)v22);
  v18 = LocalPlayer->m_vecAbsOrigin.x - pSpeaker->m_vecAbsOrigin.x;
  v19 = fsqrt(
          (float)((float)((float)(LocalPlayer->m_vecAbsOrigin.y - pSpeaker->m_vecAbsOrigin.y)
                        * (float)(LocalPlayer->m_vecAbsOrigin.y - pSpeaker->m_vecAbsOrigin.y))
                + (float)((float)(LocalPlayer->m_vecAbsOrigin.z - pSpeaker->m_vecAbsOrigin.z)
                        * (float)(LocalPlayer->m_vecAbsOrigin.z - pSpeaker->m_vecAbsOrigin.z)))
        + (float)(v18 * v18));
  v20[1] = 1.0;
  v16 = UTIL_VarArgs(format: "%f", v19);
LABEL_20:
  ResponseRules::CriteriaSet::AppendCriteria(this: set, pCriteriaName: "distancetoplayer", value: v16, weight: v20[1]);
  HasCondition = CAI_BaseNPC::HasCondition(this: pSpeaker, iCondition: 32);
  v20[1] = 1.0;
  if ( HasCondition )
    LODWORD(v20[0]) = "1";
  else
    LODWORD(v20[0]) = "0";
  ResponseRules::CriteriaSet::AppendCriteria(
    this: set,
    pCriteriaName: "seeplayer",
    value: (const char *)LODWORD(v20[0]),
    weight: v20[1]);
  if ( LocalPlayer != nullptr
    && LocalPlayer->FInViewCone(this: LocalPlayer, a2: pSpeaker)
    && LocalPlayer->FVisible_2(this: LocalPlayer, a2: pSpeaker, a3: 16449, a4: nullptr) )
  {
    v20[1] = 1.0;
    LODWORD(v20[0]) = "1";
  }
  else
  {
    v20[1] = 1.0;
    LODWORD(v20[0]) = "0";
  }
  ResponseRules::CriteriaSet::AppendCriteria(
    this: set,
    pCriteriaName: "seenbyplayer",
    value: (const char *)LODWORD(v20[0]),
    weight: v20[1]);
}

//------------------------------------------------------------------------------
// Address: 0x10087480
// Name: public: static bool CAI_Expresser::FireEntIOFromResponse(char __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CAI_Expresser::FireEntIOFromResponse(char *response, CBaseEntity *pInitiator)
{
  const char *v2; // ebx
  char *v4; // esi
  CBaseEntity *EntityByName; // eax
  char *v6; // ebx
  int v7; // ecx
  int v8; // ecx
  char *pszInput; // [esp+20h] [ebp-8h]
  char *strtokContext; // [esp+24h] [ebp-4h] BYREF

  v2 = strtok_s(_String: response, _Control: " ", _Context: &strtokContext);
  if ( v2 != nullptr && (pszInput = strtok_s(_String: nullptr, _Control: " ", _Context: &strtokContext)) != nullptr )
  {
    v4 = strtok_s(_String: nullptr, _Control: " ", _Context: &strtokContext);
    EntityByName = CGlobalEntityList::FindEntityByName(
                     this: &gEntList,
                     pStartEntity: nullptr,
                     szName: v2,
                     pSearchingEntity: pInitiator,
                     pActivator: nullptr,
                     pCaller: nullptr,
                     pFilter: nullptr);
    if ( EntityByName != nullptr )
    {
      v6 = nullptr;
      v7 = 0;
      if ( v4 != nullptr )
      {
        v6 = *v4 != 0 ? v4 : nullptr;
        v8 = 2;
      }
      ((void (__thiscall *)(CBaseEntity *, char *, CBaseEntity *, CBaseEntity *, char *))EntityByName->AcceptInput)(
        a1: EntityByName,
        a2: pszInput,
        a3: pInitiator,
        a4: pInitiator,
        a5: v6);
      return 1;
    }
    else
    {
      _Msg(a1: "Response rule targeted %s with entityio, but that doesn't exist.\n", v2);
      return 1;
    }
  }
  else
  {
    _Warning(a1: "Response was entityio but had bad value %s\n", response);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087580
// Name: protected: void CAI_Expresser::SpeechMsg(class CBaseEntity __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CAI_Expresser::SpeechMsg(CAI_Expresser *this, CBaseEntity *pFlex, const char *pszFormat, ...)
{
  CFmtStrN<256> *v3; // eax
  CAI_BaseNPC *v4; // eax
  CFmtStrN<256> *v5; // eax
  CFmtStrN<256> *v6; // eax
  const char *v7; // [esp-8h] [ebp-114h]
  CFmtStrN<256> v8; // [esp+0h] [ebp-10Ch] BYREF

  if ( ai_debug_speech.m_pParent != nullptr && ai_debug_speech.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( pFlex->MyNPCPointer(this: pFlex) != nullptr )
    {
      v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, ppszFormat: &pszFormat);
      v4 = (CAI_BaseNPC *)((int (__thiscall *)(CBaseEntity *, char *))pFlex->MyNPCPointer)(a1: pFlex, a2: v3->m_szBuf);
      DevMsg(pAI: v4, pszFormat: v7);
    }
    else
    {
      v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, ppszFormat: &pszFormat);
      DevMsg(a1: v5->m_szBuf);
    }
    v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v8, ppszFormat: &pszFormat);
    UTIL_LogPrintf(fmt: v6->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087D70
// Name: public: virtual bool CConceptHistoriesDataOps::IsEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CConceptHistoriesDataOps::IsEmpty(
        CConceptHistoriesDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  return *((_DWORD *)fieldInfo->pField + 5) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10087D90
// Name: public: void CAI_Expresser::GatherCriteria(class ResponseRules::CriteriaSet __near *,class CAI_Concept const __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Expresser::GatherCriteria(
        CAI_Expresser *this,
        ResponseRules::CriteriaSet *outputSet,
        const CAI_Concept *concept,
        const char *modifiers)
{
  const char *StringConcept; // eax
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v8; // eax
  IHandleEntity *v9; // ecx
  CBasePlayer *v10; // eax

  StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: &concept->ResponseRules::CRR_Concept);
  ResponseRules::CriteriaSet::AppendCriteria(
    this: outputSet,
    pCriteriaName: "concept",
    value: StringConcept,
    weight: 5.0);
  ResponseRules::CriteriaSet::Merge(this: outputSet, modifiers);
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  m_pEntity->__vftable[40].SetRefEHandle(this: m_pEntity, a2: (const CBaseHandle *)outputSet);
  v8 = this->m_pOuter.m_Index;
  if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    v9 = nullptr;
  else
    v9 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
  if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v9->__vftable[28].dtr_IHandleEntity)(a1: v9) == 0 )
  {
    v10 = UTIL_PlayerByIndex(playerIndex: 1);
    if ( v10 != nullptr )
      v10->ModifyOrAppendPlayerCriteria(this: v10, a2: outputSet);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10087E60
// Name: public: float CAI_Expresser::GetResponseDuration(class ResponseRules::CRR_Response __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Expresser::GetResponseDuration(CAI_Expresser *this, ResponseRules::CRR_Response *result)
{
  ResponseRules::CRR_Response *v2; // esi
  CBaseFlex *Outer; // eax
  const char *v5; // eax
  double SoundDuration; // st7
  char response[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = result;
  ResponseRules::CRR_Response::GetResponse(this: result, buf: response, buflen: 0x100u);
  switch ( v2->m_Type )
  {
    case 1u:
      Outer = CAI_Expresser::GetOuter(this);
      v5 = *(const char **)((int (__thiscall *)(CBaseFlex *, ResponseRules::CRR_Response **))Outer->GetModelName)(
                             a1: Outer,
                             a2: &result);
      if ( v5 == nullptr )
        v5 = locale;
      SoundDuration = CBaseEntity::GetSoundDuration(soundname: response, actormodel: v5);
      break;
    case 2u:
      SoundDuration = 999.0;
      break;
    case 3u:
      SoundDuration = GetSceneDuration(pszScene: response);
      break;
    case 5u:
      SoundDuration = 1.0;
      break;
    default:
      SoundDuration = 0.0;
      break;
  }
  return SoundDuration;
}

//------------------------------------------------------------------------------
// Address: 0x10087F20
// Name: public: void CAI_Expresser::NoteSpeaking(float,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Expresser::NoteSpeaking(CAI_Expresser *this, float duration, float delay)
{
  float v4; // xmm0_4
  float m_flStopTalkTime; // xmm1_4
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  unsigned int v8; // eax
  IHandleEntity *v9; // edi
  int v10; // eax
  CAI_TimedSemaphore *v11; // edi
  unsigned int v12; // eax
  IHandleEntity *v13; // ecx
  float durationa; // [esp+24h] [ebp+8h]

  durationa = duration + delay;
  this->m_pSink->OnStartSpeaking(this: this->m_pSink);
  v4 = durationa;
  if ( durationa > 0.0 )
  {
    this->m_flStopTalkTime = gpGlobals->curtime + durationa;
  }
  else
  {
    this->m_flStopTalkTime = gpGlobals->curtime + 3.0;
    v4 = 0.0;
    durationa = 0.0;
  }
  m_flStopTalkTime = this->m_flStopTalkTime;
  this->m_flStopTalkTimeWithoutDelay = m_flStopTalkTime - delay;
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CAI_Expresser::SpeechMsg(
    this,
    pFlex: m_pEntity,
    pszFormat: "NoteSpeaking( %f, %f ) (stop at %f)\n",
    v4,
    delay,
    m_flStopTalkTime);
  if ( this->m_pSink->UseSemaphore(this: this->m_pSink) )
  {
    v8 = this->m_pOuter.m_Index;
    if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
      v9 = nullptr;
    else
      v9 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
    if ( v9->__vftable[24].GetRefEHandle(this: v9) != nullptr )
    {
      v10 = (int)v9->__vftable[24].GetRefEHandle(this: v9);
      v11 = &g_AIFriendliesTalkSemaphore;
      if ( (*(unsigned __int8 (__thiscall **)(int, _DWORD))(*(_DWORD *)v10 + 1772))(a1: v10, a2: 0) == 0 )
        v11 = &g_AIFoesTalkSemaphore;
      v12 = this->m_pOuter.m_Index;
      if ( v12 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_SerialNumber != HIWORD(v12) )
        v13 = nullptr;
      else
        v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v12].m_pEntity;
      v11->m_ReleaseTime = gpGlobals->curtime + durationa;
      if ( v13 != nullptr )
        v11->m_hCurrentTalker.m_Index = v13->GetRefEHandle(this: v13)->m_Index;
      else
        v11->m_hCurrentTalker.m_Index = -1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100880D0
// Name: public: virtual bool CAI_Expresser::IsSpeaking(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Expresser::IsSpeaking(CAI_Expresser *this)
{
  float curtime; // xmm1_4
  float m_flStopTalkTime; // xmm0_4
  unsigned int m_Index; // ecx
  CBaseEntity *m_pEntity; // eax
  float v6; // xmm0_4

  curtime = gpGlobals->curtime;
  m_flStopTalkTime = this->m_flStopTalkTime;
  if ( m_flStopTalkTime > curtime )
  {
    m_Index = this->m_pOuter.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    CAI_Expresser::SpeechMsg(
      this,
      pFlex: m_pEntity,
      pszFormat: "IsSpeaking() %f\n",
      (float)(m_flStopTalkTime - curtime));
  }
  v6 = gpGlobals->curtime;
  return this->m_flLastTimeAcceptedSpeak == v6 || this->m_flStopTalkTime > v6;
}

//------------------------------------------------------------------------------
// Address: 0x10088160
// Name: private: virtual bool CAI_Expresser::IsValidResponse(enum ResponseRules::ResponseType_t,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Expresser::IsValidResponse(
        CAI_Expresser *this,
        ResponseRules::ResponseType_t type,
        const char *pszValue)
{
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  char szInstanceFilename[256]; // [esp+0h] [ebp-100h] BYREF

  if ( type != RESPONSE_SCENE )
    return true;
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  CBaseEntity::GenderExpandString(this: m_pEntity, in: pszValue, out: szInstanceFilename, maxlen: 256);
  return GetSceneDuration(pszScene: szInstanceFilename) > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x100881F0
// Name: public: virtual bool CMultiplayer_Expresser::IsSpeaking(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMultiplayer_Expresser::IsSpeaking(CMultiplayer_Expresser *this)
{
  return !this->m_bAllowMultipleScenes && CAI_Expresser::IsSpeaking(this);
}

//------------------------------------------------------------------------------
// Address: 0x10088A40
// Name: public: virtual void CConceptHistoriesDataOps::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConceptHistoriesDataOps::Save(
        CConceptHistoriesDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        ISave *pSave)
{
  ISave *v3; // esi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  CUtlDict<ConceptHistory_t,int> *pField; // edi
  int v6; // ebx
  int p_elem; // edi
  void (__thiscall *WriteBool_2)(ISave *, const bool *, int); // edx
  CUtlDict<ConceptHistory_t,int> *v9; // [esp+Ch] [ebp-8h]
  int count; // [esp+10h] [ebp-4h] BYREF

  v3 = pSave;
  WriteInt_2 = pSave->WriteInt_2;
  pField = (CUtlDict<ConceptHistory_t,int> *)fieldInfo->pField;
  count = *((_DWORD *)fieldInfo->pField + 5);
  v9 = pField;
  WriteInt_2(this: pSave, a2: &count, a3: 1);
  v6 = 0;
  pSave = nullptr;
  if ( count > 0 )
  {
    while ( 1 )
    {
      p_elem = (int)&pField->m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.elem;
      v3->StartBlock(this: v3);
      v3->WriteString_4(this: v3, a2: v9->m_Elements.m_Tree.m_Elements.m_pMemory[v6].m_Data.key);
      v3->WriteAll(this: v3, a2: (const void *)p_elem, a3: &ConceptHistory_t::m_DataMap);
      WriteBool_2 = v3->WriteBool_2;
      HIBYTE(fieldInfo) = *(_BYTE *)(p_elem + 5) != 0;
      WriteBool_2(this: v3, a2: (const bool *)&fieldInfo + 3, a3: 1);
      if ( HIBYTE(fieldInfo) != 0 )
        v3->WriteAll(this: v3, a2: (const void *)(p_elem + 4), a3: &ResponseRules::CRR_Response::m_DataMap);
      v3->EndBlock(this: v3);
      ++v6;
      pSave = (ISave *)((char *)pSave + 1);
      if ( (int)pSave >= count )
        break;
      pField = v9;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10088B10
// Name: protected: bool CAI_Expresser::SpeakRawScene(char const __near *,float,class ResponseRules::CRR_Response __near *,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Expresser::SpeakRawScene(
        CAI_Expresser *this,
        const char *pszScene,
        float delay,
        ResponseRules::CRR_Response *response,
        IRecipientFilter *filter)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  double v8; // st7
  unsigned int v9; // eax
  CBaseEntity *v10; // ecx
  float sceneLength; // [esp+3Ch] [ebp+14h]

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v8 = ((double (__stdcall *)(const char *, _DWORD, ResponseRules::CRR_Response *, IRecipientFilter *))m_pEntity->__vftable[78].SetRefEHandle)(
         a1: pszScene,
         a2: LODWORD(delay),
         a3: response,
         a4: filter);
  sceneLength = v8;
  if ( v8 <= 0.0 )
    return 0;
  v9 = this->m_pOuter.m_Index;
  if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
    v10 = nullptr;
  else
    v10 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
  CAI_Expresser::SpeechMsg(this, pFlex: v10, pszFormat: "SpeakRawScene( %s, %f) %f\n", pszScene, delay, sceneLength);
  CAI_Expresser::NoteSpeaking(this, duration: sceneLength, delay);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10088C00
// Name: protected: bool CAI_Expresser::SpeakAutoGeneratedScene(char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Expresser::SpeakAutoGeneratedScene(CAI_Expresser *this, const char *soundname, float delay)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  double v7; // st7
  unsigned int v8; // eax
  CBaseEntity *v9; // ecx
  float speakTime; // [esp+24h] [ebp+8h]

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v7 = ((double (__thiscall *)(IHandleEntity *, const char *))m_pEntity->__vftable[79].dtr_IHandleEntity)(
         a1: m_pEntity,
         a2: soundname);
  speakTime = v7;
  if ( v7 <= 0.0 )
    return 0;
  v8 = this->m_pOuter.m_Index;
  if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    v9 = nullptr;
  else
    v9 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
  CAI_Expresser::SpeechMsg(
    this,
    pFlex: v9,
    pszFormat: "SpeakAutoGeneratedScene( %s, %f) %f\n",
    soundname,
    delay,
    speakTime);
  CAI_Expresser::NoteSpeaking(this, duration: speakTime, delay);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10088CE0
// Name: public: virtual int CAI_Expresser::SpeakRawSentence(char const __near *,float,float,enum soundlevel_t,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CAI_Expresser::SpeakRawSentence@<eax>(
        CAI_Expresser *this@<ecx>,
        int a2@<ebx>,
        const char *pszSentence,
        float delay,
        float volume,
        soundlevel_t soundlevel,
        CBaseEntity *pListener)
{
  int result; // eax
  int v9; // ebx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  int v12; // eax
  unsigned int v13; // ecx
  int v14; // eax
  IHandleEntity *v15; // edx
  signed int v16; // ecx
  int v17; // eax
  unsigned int v18; // ecx
  int v19; // eax
  IHandleEntity *v20; // ecx
  unsigned int v21; // eax
  CBaseEntity *v22; // edi
  double v23; // st7
  float duration_4; // [esp+20h] [ebp-34h]
  CPASAttenuationFilter filter; // [esp+34h] [ebp-20h] BYREF

  if ( pszSentence == nullptr )
    return -1;
  if ( *pszSentence == 33 )
  {
    result = SENTENCEG_Lookup(sample: pszSentence);
    v9 = result;
    if ( result == -1 )
      return result;
    m_Index = this->m_pOuter.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    CPASAttenuationFilter::CPASAttenuationFilter(this: &filter, entity: m_pEntity, soundlevel);
    v12 = ((int (__thiscall *)(IUniformRandomStream *, _DWORD, int, int))random->RandomInt)(
            a1: random,
            a2: 0,
            a3: 3,
            a4: a2);
    v13 = this->m_pOuter.m_Index;
    v14 = this->m_voicePitch + v12;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v15 = nullptr;
    else
      v15 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    v16 = (signed int)v15[6].__vftable;
    if ( v16 != 0 )
      v16 = (signed int)(v16 - (unsigned int)gpGlobals->pEdicts) >> 4;
    CBaseEntity::EmitSentenceByIndex(
      &filter,
      iEntIndex: v16,
      iChannel: 2,
      iSentenceIndex: v9,
      flVolume: volume,
      iSoundlevel: soundlevel,
      iFlags: 0,
      iPitch: v14,
      pOrigin: nullptr,
      pDirection: nullptr,
      bUpdatePositions: 1,
      soundtime: 0.0);
    CRecipientFilter::~CRecipientFilter(this: &filter);
  }
  else
  {
    v17 = ((int (__thiscall *)(IUniformRandomStream *, _DWORD, int, int))random->RandomInt)(
            a1: random,
            a2: 0,
            a3: 3,
            a4: a2);
    v18 = this->m_pOuter.m_Index;
    v19 = this->m_voicePitch + v17;
    if ( v18 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18) )
      v20 = nullptr;
    else
      v20 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
    v9 = SENTENCEG_PlayRndSz(
           entity: (edict_t *)v20[6].__vftable,
           szgroupname: pszSentence,
           volume,
           soundlevel,
           flags: 0,
           pitch: v19);
  }
  v21 = this->m_pOuter.m_Index;
  if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
    v22 = nullptr;
  else
    v22 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
  v23 = ((double (__thiscall *)(IVEngineServer *, int))engine->SentenceLength)(a1: engine, a2: v9);
  CAI_Expresser::SpeechMsg(this, pFlex: v22, pszFormat: "SpeakRawSentence( %s, %f) %f\n", pszSentence, delay, v23);
  duration_4 = ((double (__thiscall *)(IVEngineServer *))engine->SentenceLength)(a1: engine);
  CAI_Expresser::NoteSpeaking(this, duration: duration_4, delay: *(float *)&v9);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10089100
// Name: public: bool CAI_Expresser::FindResponse(class ResponseRules::CRR_Response __near &,class CAI_Concept __near &,class ResponseRules::CriteriaSet __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Expresser::FindResponse(
        CAI_Expresser *this,
        ResponseRules::CRR_Response *outResponse,
        CAI_Concept *concept,
        ResponseRules::CriteriaSet *criteria)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  int v7; // ebx
  unsigned int v9; // eax
  IHandleEntity *v10; // ecx
  ResponseRules::CriteriaSet *p_localCriteriaSet; // esi
  char v12; // bl
  unsigned int v13; // eax
  IHandleEntity *v14; // ecx
  CBaseFlex *v15; // eax
  CBaseFlex *Outer; // eax
  CBaseFlex *v17; // eax
  const char *DebugName; // eax
  CBaseFlex *v19; // eax
  const char *v20; // esi
  const char *v21; // eax
  const char *StringConcept; // eax
  edict_t *v23; // eax
  CBaseEntity *v24; // eax
  char response[256]; // [esp+8h] [ebp-148h] BYREF
  ResponseRules::CriteriaSet localCriteriaSet; // [esp+108h] [ebp-48h] BYREF
  ResponseRules::CriteriaSet worldWritebackCriteria; // [esp+12Ch] [ebp-24h] BYREF

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v7 = ((int (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[18].SetRefEHandle)(a1: m_pEntity);
  if ( v7 == 0 )
    return 0;
  v9 = this->m_pOuter.m_Index;
  if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
    v10 = nullptr;
  else
    v10 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
  if ( v10->__vftable[22].GetRefEHandle(this: v10) == nullptr )
    return 0;
  ResponseRules::CriteriaSet::CriteriaSet(this: &localCriteriaSet);
  p_localCriteriaSet = criteria;
  if ( criteria == nullptr )
  {
    CAI_Expresser::GatherCriteria(this, outputSet: &localCriteriaSet, concept, modifiers: nullptr);
    p_localCriteriaSet = &localCriteriaSet;
  }
  ResponseRules::CriteriaSet::CriteriaSet(this: &worldWritebackCriteria);
  ResponseRules::CriteriaSet::InterceptWorldSetContexts(pFrom: p_localCriteriaSet, pSetOnWorld: &worldWritebackCriteria);
  v12 = (*(int (__thiscall **)(int, ResponseRules::CriteriaSet *, ResponseRules::CRR_Response *, CAI_Expresser *))(*(_DWORD *)v7 + 4))(
          a1: v7,
          a2: p_localCriteriaSet,
          a3: outResponse,
          a4: this);
  if ( rr_debugresponses.m_pParent != nullptr && rr_debugresponses.m_pParent->m_Value.m_nValue == 4 )
  {
    v13 = this->m_pOuter.m_Index;
    if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
      v14 = nullptr;
    else
      v14 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
    if ( v14->__vftable[24].GetRefEHandle(this: v14) != nullptr
      && (CAI_Expresser::GetOuter(this)->m_debugOverlays & 0x1000) != 0
      || (v15 = CAI_Expresser::GetOuter(this), v15->IsPlayer(this: v15)) )
    {
      Outer = CAI_Expresser::GetOuter(this);
      if ( Outer->IsPlayer(this: Outer) )
      {
        v17 = CAI_Expresser::GetOuter(this);
        DebugName = v17->GetPlayerName(this: v17);
      }
      else
      {
        v19 = CAI_Expresser::GetOuter(this);
        DebugName = CBaseEntity::GetDebugName(this: v19);
      }
      v20 = DebugName;
      if ( v12 == 0 )
      {
        StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: concept);
        _Warning(a1: "RESPONSERULES: %s spoke '%s'. Found no matching response.\n", v20, StringConcept);
LABEL_29:
        CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &worldWritebackCriteria.m_Lookup);
        CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &localCriteriaSet.m_Lookup);
        return 0;
      }
      ResponseRules::CRR_Response::GetResponse(this: outResponse, buf: response, buflen: 0x100u);
      v21 = ResponseRules::CRR_Concept::GetStringConcept(this: concept);
      _Warning(a1: "RESPONSERULES: %s spoke '%s'. Found response '%s'.\n", v20, v21, response);
    }
  }
  if ( v12 == 0 )
    goto LABEL_29;
  if ( ResponseRules::CriteriaSet::GetCount(this: &worldWritebackCriteria) > 0 )
  {
    v23 = INDEXENT(iEdictNum: 0);
    v24 = CBaseEntity::Instance(pent: v23);
    CNavMesh::SaveCustomData(this: (vgui::TreeView *)&worldWritebackCriteria, itemIndex: (int)v24);
  }
  if ( outResponse->m_szResponseName[0] == 0 )
    goto LABEL_29;
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &worldWritebackCriteria.m_Lookup);
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &localCriteriaSet.m_Lookup);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10089350
// Name: public: bool CAI_Expresser::Speak(class CAI_Concept __near &,class ResponseRules::CriteriaSet __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Expresser::Speak(
        CAI_Expresser *this,
        CAI_Concept *concept,
        ResponseRules::CriteriaSet *criteria,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  const char *StringConcept; // eax
  unsigned int v11; // ecx
  IHandleEntity *v12; // ebx
  IHandleEntity *v13; // edx
  const char *v14; // edi
  CBaseEntity *v15; // ecx
  bool v16; // bl
  ResponseRules::CRR_Response v17; // [esp+18h] [ebp-ACh] BYREF
  const char *v18; // [esp+C0h] [ebp-4h]

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  ((void (__thiscall *)(IHandleEntity *, ResponseRules::CriteriaSet *))m_pEntity->__vftable[40].GetRefEHandle)(
    a1: m_pEntity,
    a2: criteria);
  ResponseRules::CRR_Response::CRR_Response(this: &v17);
  if ( CAI_Expresser::FindResponse(this, outResponse: &v17, concept, criteria) != 0 )
  {
    StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: concept);
    v11 = this->m_pOuter.m_Index;
    v18 = StringConcept;
    if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
      v12 = nullptr;
    else
      v12 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
      v13 = nullptr;
    else
      v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    v14 = (const char *)v13[51].__vftable;
    if ( v14 == nullptr )
      v14 = locale;
    if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
      v15 = nullptr;
    else
      v15 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
    CAI_Expresser::SpeechMsg(this, pFlex: v15, pszFormat: "%s (%x) spoke %s (%f)", v14, v12, v18, gpGlobals->curtime);
    v16 = this->SpeakDispatchResponse(this, a2: concept, a3: &v17, a4: criteria, a5: filter);
    if ( pszOutResponseChosen != nullptr )
      ResponseRules::CRR_Response::GetResponse(this: &v17, buf: pszOutResponseChosen, buflen: bufsize);
    ResponseRules::CRR_Response::~CRR_Response(this: &v17);
    return v16;
  }
  else
  {
    ResponseRules::CRR_Response::~CRR_Response(this: &v17);
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100894D0
// Name: public: bool CAI_Expresser::CanSpeakConcept(class CAI_Concept)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Expresser::CanSpeakConcept(CAI_Expresser *this, CAI_Concept concept)
{
  const char *StringConcept; // esi
  int v4; // esi
  UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int> *m_pMemory; // edx
  int p_elem; // edi
  double v8; // st7
  CUtlMap<char const *,ConceptHistory_t,int>::Node_t search; // [esp+8h] [ebp-B4h] BYREF
  float respeakDelay; // [esp+B8h] [ebp-4h]

  StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: &concept);
  if ( StringConcept == nullptr )
    return 1;
  search.elem.timeSpoken = -1.0;
  ResponseRules::CRR_Response::CRR_Response(this: &search.elem.m_response);
  search.key = StringConcept;
  v4 = CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::Find(
         this: &this->m_ConceptHistories.m_Elements.m_Tree,
         &search);
  ResponseRules::CRR_Response::~CRR_Response(this: &search.elem.m_response);
  if ( v4 == -1 )
    return 1;
  m_pMemory = this->m_ConceptHistories.m_Elements.m_Tree.m_Elements.m_pMemory;
  p_elem = (int)&m_pMemory[v4].m_Data.elem;
  if ( m_pMemory[v4].m_Data.elem.m_response.m_szResponseName[0] != 0
    && (ResponseRules::CRR_Response::GetSpeakOnce(this: &m_pMemory[v4].m_Data.elem.m_response)
     || (v8 = ResponseRules::CRR_Response::GetRespeakDelay(this: (ResponseRules::CRR_Response *)(p_elem + 4)),
         respeakDelay = v8,
         v8 != 0.0)
     && *(float *)p_elem != -1.0
     && (float)(*(float *)p_elem + respeakDelay) > gpGlobals->curtime) )
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100895A0
// Name: public: float CAI_Expresser::GetTimeSpokeConcept(class CAI_Concept)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Expresser::GetTimeSpokeConcept(CAI_Expresser *this, CAI_Concept concept)
{
  const char *StringConcept; // esi
  int v4; // esi
  CUtlMap<char const *,ConceptHistory_t,int>::Node_t search; // [esp+8h] [ebp-B0h] BYREF

  StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: &concept);
  if ( StringConcept != nullptr
    && (search.elem.timeSpoken = -1.0,
        ResponseRules::CRR_Response::CRR_Response(this: &search.elem.m_response),
        search.key = StringConcept,
        v4 = CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::Find(
               this: &this->m_ConceptHistories.m_Elements.m_Tree,
               &search),
        ResponseRules::CRR_Response::~CRR_Response(this: &search.elem.m_response),
        v4 != -1) )
  {
    return this->m_ConceptHistories.m_Elements.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem.timeSpoken;
  }
  else
  {
    return -1.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100896B0
// Name: public: bool CAI_Expresser::Speak(class CAI_Concept __near &,char const __near *,char __near *,unsigned int,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Expresser::Speak(
        CAI_Expresser *this,
        CAI_Concept *concept,
        const char *modifiers,
        char *pszOutResponseChosen,
        unsigned int bufsize,
        IRecipientFilter *filter)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v9; // eax
  bool v10; // bl
  ResponseRules::CriteriaSet criteria; // [esp+Ch] [ebp-24h] BYREF

  m_Index = this->m_pOuter.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && (m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity) != nullptr )
  {
    v9 = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
  }
  else
  {
    v9 = -1;
  }
  concept->m_hSpeaker.m_Index = v9;
  ResponseRules::CriteriaSet::CriteriaSet(this: &criteria);
  CAI_Expresser::GatherCriteria(this, outputSet: &criteria, concept, modifiers);
  v10 = CAI_Expresser::Speak(this, concept, &criteria, pszOutResponseChosen, bufsize, filter);
  CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>::~CUtlRBTree<ResponseRules::CriteriaSet::CritEntry_t,short,bool (__cdecl *)(ResponseRules::CriteriaSet::CritEntry_t const &,ResponseRules::CriteriaSet::CritEntry_t const &),CUtlMemory<UtlRBTreeNode_t<ResponseRules::CriteriaSet::CritEntry_t,short>,short>>(this: &criteria.m_Lookup);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10089740
// Name: public: bool CAI_Expresser::SpokeConcept(class CAI_Concept)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_Expresser::SpokeConcept(CAI_Expresser *this, CAI_Concept concept)
{
  return CAI_Expresser::GetTimeSpokeConcept(this, concept) != -1.0;
}

//------------------------------------------------------------------------------
// Address: 0x10089780
// Name: public: CAI_Expresser::CAI_Expresser(class CBaseFlex __near *)
// Source: json
//------------------------------------------------------------------------------
CAI_Expresser *__thiscall CAI_Expresser::CAI_Expresser(CAI_Expresser *this, CBaseFlex *pOuter)
{
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CBaseEntity **v9; // eax
  CBaseEntity *v10; // eax

  this->__vftable = (CAI_Expresser_vtbl *)&CAI_Expresser::`vftable';
  this->m_pSink = nullptr;
  this->m_ConceptHistories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_ConceptHistories.m_Elements.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_ConceptHistories.m_Elements.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_ConceptHistories.m_Elements.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_ConceptHistories.m_Elements.m_Tree.m_Root = -1;
  this->m_ConceptHistories.m_Elements.m_Tree.m_NumElements = 0;
  this->m_ConceptHistories.m_Elements.m_Tree.m_FirstFree = -1;
  this->m_ConceptHistories.m_Elements.m_Tree.m_LastAlloc.index = -1;
  this->m_ConceptHistories.m_Elements.m_Tree.m_pElements = this->m_ConceptHistories.m_Elements.m_Tree.m_Elements.m_pMemory;
  if ( this->m_ConceptHistories.m_Elements.m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_ConceptHistories.m_Elements.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const char *const *, const char *const *))CaselessStringLessThan;
  this->m_flStopTalkTime = 0.0;
  this->m_flStopTalkTimeWithoutDelay = 0.0;
  this->m_flBlockedTalkTime = 0.0;
  this->m_voicePitch = 100;
  this->m_flLastTimeAcceptedSpeak = 0.0;
  this->m_pOuter.m_Index = -1;
  if ( pOuter != nullptr )
    this->m_pOuter.m_Index = pOuter->GetRefEHandle(this: pOuter)->m_Index;
  else
    this->m_pOuter.m_Index = -1;
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index != -1 )
  {
    v4 = (unsigned __int16)m_Index;
    v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v6 = HIWORD(m_Index);
    if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
    {
      v7 = v4;
      v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
      v9 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v7];
      if ( v8 )
        v10 = *v9;
      else
        v10 = nullptr;
      CResponseQueue::AddExpresserHost(this: g_ResponseQueueManager.m_pQueue, host: v10);
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10089850
// Name: public: CAI_Expresser::~CAI_Expresser(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Expresser::~CAI_Expresser(CAI_Expresser *this)
{
  CUtlDict<ConceptHistory_t,int> *p_m_ConceptHistories; // edi
  unsigned int m_Index; // eax
  CEntInfo *v4; // ecx
  CBaseEntity *m_pEntity; // esi
  int v6; // eax
  char v7; // al
  CAI_TimedSemaphore *v8; // edx
  unsigned int v9; // eax
  IHandleEntity *v10; // ecx

  p_m_ConceptHistories = &this->m_ConceptHistories;
  this->__vftable = (CAI_Expresser_vtbl *)&CAI_Expresser::`vftable';
  CUtlDict<ConceptHistory_t,int>::RemoveAll(this: &this->m_ConceptHistories);
  m_Index = this->m_pOuter.m_Index;
  if ( m_Index != -1 )
  {
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
    {
      m_pEntity = (CBaseEntity *)v4->m_pEntity;
      if ( v4->m_pEntity != nullptr )
      {
        if ( m_pEntity->MyNPCPointer(this: v4->m_pEntity) != nullptr )
        {
          v6 = (int)m_pEntity->MyNPCPointer(this: m_pEntity);
          v7 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v6 + 1772))(a1: v6, a2: 0);
          v8 = &g_AIFriendliesTalkSemaphore;
          if ( v7 == 0 )
            v8 = &g_AIFoesTalkSemaphore;
          v9 = v8->m_hCurrentTalker.m_Index;
          if ( v9 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_SerialNumber != HIWORD(v9) )
            v10 = nullptr;
          else
            v10 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v9].m_pEntity;
          if ( v10 == m_pEntity )
          {
            v8->m_ReleaseTime = 0.0;
            v8->m_hCurrentTalker.m_Index = -1;
          }
        }
        CResponseQueue::RemoveExpresserHost(this: g_ResponseQueueManager.m_pQueue, host: m_pEntity);
      }
    }
  }
  CUtlDict<ConceptHistory_t,int>::RemoveAll(this: p_m_ConceptHistories);
  CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::~CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>(this: &p_m_ConceptHistories->m_Elements.m_Tree);
}

//------------------------------------------------------------------------------
// Address: 0x10089A00
// Name: public: virtual void CConceptHistoriesDataOps::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CConceptHistoriesDataOps::Restore(
        CConceptHistoriesDataOps *this,
        const SaveRestoreFieldInfo_t *fieldInfo,
        IRestore *pRestore)
{
  IRestore *v3; // esi
  int (__thiscall *ReadInt)(IRestore *); // eax
  int v5; // eax
  int i; // edi
  int (__thiscall *ReadBool)(IRestore *, bool *, int, int); // edx
  char conceptname[512]; // [esp+8h] [ebp-2B0h] BYREF
  ConceptHistory_t history; // [esp+208h] [ebp-B0h] BYREF
  CUtlDict<ConceptHistory_t,int> *pField; // [esp+2B4h] [ebp-4h]

  v3 = pRestore;
  ReadInt = pRestore->ReadInt;
  pField = (CUtlDict<ConceptHistory_t,int> *)fieldInfo->pField;
  v5 = ReadInt(this: pRestore);
  if ( v5 > 0 )
  {
    for ( i = v5; i != 0; --i )
    {
      conceptname[0] = 0;
      history.timeSpoken = -1.0;
      ResponseRules::CRR_Response::CRR_Response(this: &history.m_response);
      v3->StartBlock(this: v3);
      v3->ReadString_2(this: v3, a2: conceptname, a3: 512, a4: 0);
      v3->ReadAll(this: v3, a2: &history, a3: &ConceptHistory_t::m_DataMap);
      ReadBool = v3->ReadBool;
      HIBYTE(fieldInfo) = 0;
      ReadBool(this: v3, a2: (bool *)&fieldInfo + 3, a3: 1, a4: 0);
      if ( HIBYTE(fieldInfo) != 0 )
        v3->ReadAll(this: v3, a2: &history.m_response, a3: &ResponseRules::CRR_Response::m_DataMap);
      else
        ResponseRules::CRR_Response::Invalidate(this: &history.m_response);
      v3->EndBlock(this: v3);
      if ( conceptname[0] != 0 )
        CUtlDict<ConceptHistory_t,int>::Insert(this: pField, pName: conceptname, element: &history);
      ResponseRules::CRR_Response::~CRR_Response(this: &history.m_response);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089B00
// Name: public: void CAI_Expresser::SetSpokeConcept(class CAI_Concept,class ResponseRules::CRR_Response __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Expresser::SetSpokeConcept(
        CAI_Expresser *this,
        CAI_Concept concept,
        ResponseRules::CRR_Response *response,
        bool bCallback)
{
  const char *StringConcept; // edi
  int v6; // edi
  const char *v7; // eax
  int v8; // eax
  const ResponseRules::CRR_Response *v9; // edi
  ConceptHistory_t *p_elem; // eax
  unsigned __int16 m_Id; // [esp-Ch] [ebp-170h]
  CUtlMap<char const *,ConceptHistory_t,int>::Node_t search; // [esp+8h] [ebp-15Ch] BYREF
  ConceptHistory_t h; // [esp+B8h] [ebp-ACh] BYREF

  StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: &concept);
  if ( StringConcept == nullptr
    || (search.elem.timeSpoken = -1.0,
        ResponseRules::CRR_Response::CRR_Response(this: &search.elem.m_response),
        search.key = StringConcept,
        v6 = CUtlRBTree<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int,CUtlMap<char const *,ConceptHistory_t,int>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,ConceptHistory_t,int>::Node_t,int>,int>>::Find(
               this: &this->m_ConceptHistories.m_Elements.m_Tree,
               &search),
        ResponseRules::CRR_Response::~CRR_Response(this: &search.elem.m_response),
        v6 == -1) )
  {
    h.timeSpoken = -1.0;
    ResponseRules::CRR_Response::CRR_Response(this: &h.m_response);
    h.timeSpoken = gpGlobals->curtime;
    v7 = ResponseRules::CRR_Concept::GetStringConcept(this: &concept);
    v6 = CUtlDict<ConceptHistory_t,int>::Insert(this: &this->m_ConceptHistories, pName: v7, element: &h);
    ResponseRules::CRR_Response::~CRR_Response(this: &h.m_response);
  }
  v8 = v6;
  v9 = response;
  p_elem = &this->m_ConceptHistories.m_Elements.m_Tree.m_Elements.m_pMemory[v8].m_Data.elem;
  p_elem->timeSpoken = gpGlobals->curtime;
  if ( v9 != nullptr )
    ResponseRules::CRR_Response::operator=(this: &p_elem->m_response, from: v9);
  if ( bCallback )
  {
    m_Id = concept.m_iConcept.m_Id;
    ((void (__thiscall *)(CAI_ExpresserSink *, unsigned __int16, unsigned int, const ResponseRules::CRR_Response *))this->m_pSink->OnSpokeConcept)(
      a1: this->m_pSink,
      a2: m_Id,
      a3: concept.m_hSpeaker.m_Index,
      a4: v9);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10089C10
// Name: public: CMultiplayer_Expresser::CMultiplayer_Expresser(class CBaseFlex __near *)
// Source: json
//------------------------------------------------------------------------------
CMultiplayer_Expresser *__thiscall CMultiplayer_Expresser::CMultiplayer_Expresser(
        CMultiplayer_Expresser *this,
        CBaseFlex *pOuter)
{
  CAI_Expresser::CAI_Expresser(this, pOuter);
  this->m_pPostponedFollowup = nullptr;
  this->m_followupTarget.m_iTargetType = kDRT_MAX;
  this->m_followupTarget.m_hHandle.m_Index = -1;
  this->m_bAllowMultipleScenes = false;
  this->__vftable = (CMultiplayer_Expresser_vtbl *)&CMultiplayer_Expresser::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10089C50
// Name: public: virtual bool CAI_Expresser::SpeakDispatchResponse(class CAI_Concept __near &,class ResponseRules::CRR_Response __near *,class ResponseRules::CriteriaSet __near *,class IRecipientFilter __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Expresser::SpeakDispatchResponse(
        CAI_Expresser *this,
        CAI_Concept *concept,
        ResponseRules::CRR_Response *result,
        ResponseRules::CriteriaSet *criteria,
        IRecipientFilter *filter)
{
  ResponseRules::CRR_Response *v5; // ebx
  soundlevel_t v7; // eax
  CAI_Expresser_vtbl *v8; // edx
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  const char *v11; // ecx
  const char *v12; // ebx
  IHandleEntity *v13; // ecx
  CBaseFlex *Outer; // eax
  CBasePlayer *v15; // eax
  const char *v16; // edi
  const char *StringConcept; // eax
  unsigned int v18; // ecx
  IHandleEntity *v19; // edx
  signed int v20; // ecx
  unsigned int v21; // eax
  CBaseFlex *v22; // eax
  unsigned int v23; // eax
  CBaseEntity *v24; // ecx
  unsigned int v25; // eax
  CBaseFlex *v26; // ecx
  const char *v27; // edi
  edict_t *m_pPev; // eax
  char v29; // al
  char v30; // al
  CBaseFlex *v31; // eax
  const char *v32; // eax
  CFmtStrN<256> *v33; // eax
  edict_t *pEdicts; // edi
  edict_t *v35; // eax
  CBaseFlex *v36; // eax
  const char *pszValue; // edi
  edict_t *v38; // eax
  CBaseFlex *v39; // eax
  CBaseFlex *v40; // eax
  IServerUnknown *m_pUnk; // ecx
  CBaseEntity *v42; // eax
  unsigned int v43; // eax
  CBaseEntity *v44; // ecx
  CFmtStrN<256> v45; // [esp+1Ch] [ebp-234h] BYREF
  char response[256]; // [esp+128h] [ebp-128h] BYREF
  Vector vPrintPos; // [esp+228h] [ebp-28h] BYREF
  soundlevel_t soundlevel; // [esp+234h] [ebp-1Ch]
  Vector in; // [esp+238h] [ebp-18h] BYREF
  float delay; // [esp+244h] [ebp-Ch]
  const char *entityName; // [esp+248h] [ebp-8h]
  bool spoke; // [esp+24Fh] [ebp-1h]
  float speakTime; // [esp+25Ch] [ebp+Ch]

  v5 = result;
  ResponseRules::CRR_Response::GetResponse(this: result, buf: response, buflen: 0x100u);
  delay = ResponseRules::CRR_Response::GetDelay(this: result);
  spoke = false;
  v7 = ResponseRules::CRR_Response::GetSoundLevel(this: result);
  v8 = this->__vftable;
  soundlevel = v7;
  if ( v8->IsSpeaking(this) && *ResponseRules::CRR_Concept::GetStringConcept(this: concept) != 0 && result->m_Type != 5 )
  {
    m_Index = this->m_pOuter.m_Index;
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    v11 = (const char *)m_pEntity[51].__vftable;
    if ( v11 != nullptr )
    {
      v12 = v11;
      entityName = v11;
    }
    else
    {
      v12 = locale;
      entityName = locale;
    }
    if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
      v13 = nullptr;
    else
      v13 = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))v13->__vftable[28].dtr_IHandleEntity)(a1: v13) != 0 )
    {
      Outer = CAI_Expresser::GetOuter(this);
      v15 = ToBasePlayer(pEntity: Outer);
      v12 = v15->GetPlayerName(this: v15);
      entityName = v12;
    }
    v16 = v12;
    if ( v12 == nullptr )
      v16 = "UNKNOWN";
    StringConcept = ResponseRules::CRR_Concept::GetStringConcept(this: concept);
    v18 = this->m_pOuter.m_Index;
    if ( v18 == -1
      || (v12 = entityName, g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_SerialNumber != HIWORD(v18)) )
    {
      v19 = nullptr;
    }
    else
    {
      v19 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v18].m_pEntity;
    }
    v20 = (signed int)v19[6].__vftable;
    if ( v20 != 0 )
      v20 = (signed int)(v20 - (unsigned int)gpGlobals->pEdicts) >> 4;
    _DevMsg(
      a1: 2,
      a2: "SpeakDispatchResponse:  Entity ( %i/%s ) already speaking, forcing '%s'\n",
      v20,
      v16,
      StringConcept);
    v21 = this->m_pOuter.m_Index;
    if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
      v22 = nullptr;
    else
      v22 = (CBaseFlex *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
    RemoveActorFromScriptedScenes(
      pActor: v22,
      instancedscenesonly: true,
      nonidlescenesonly: false,
      pszThisSceneOnly: nullptr);
    v23 = this->m_pOuter.m_Index;
    if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
      v24 = nullptr;
    else
      v24 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
    CBaseEntity::EmitSound(this: v24, soundname: "AI_BaseNPC.SentenceStop", soundtime: 0.0, duration: nullptr);
    v25 = this->m_pOuter.m_Index;
    if ( v25 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_SerialNumber != HIWORD(v25) )
      v26 = nullptr;
    else
      v26 = (CBaseFlex *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v25].m_pEntity;
    if ( IsRunningScriptedScene(pActor: v26, bIgnoreInstancedScenes: true) != 0 )
    {
      if ( v12 == nullptr )
        v12 = "UNKNOWN";
      v27 = ResponseRules::CRR_Concept::GetStringConcept(this: concept);
      m_pPev = CAI_Expresser::GetOuter(this)->m_Network.m_pPev;
      if ( m_pPev != nullptr )
        m_pPev -= (int)gpGlobals->pEdicts;
      DevMsg(
        a1: "SpeakDispatchResponse:  Entity ( %i/%s ) refusing to speak due to scene entity, tossing '%s'\n",
        m_pPev,
        v12,
        v27);
      return 0;
    }
    v5 = result;
  }
  switch ( v5->m_Type )
  {
    case 1u:
      if ( !ResponseRules::CRR_Response::ShouldntUseScene(this: v5) )
      {
        v30 = CAI_Expresser::SpeakAutoGeneratedScene(this, soundname: response, delay);
        goto LABEL_47;
      }
      speakTime = CAI_Expresser::GetResponseDuration(this, result: v5);
      v36 = CAI_Expresser::GetOuter(this);
      CBaseEntity::EmitSound(this: v36, soundname: response, soundtime: 0.0, duration: nullptr);
      pszValue = CAI_Expresser::GetOuter(this)->m_iName.m_Value.pszValue;
      if ( pszValue == nullptr )
        pszValue = locale;
      v38 = CAI_Expresser::GetOuter(this)->m_Network.m_pPev;
      if ( v38 != nullptr )
        v38 -= (int)gpGlobals->pEdicts;
      _DevMsg(a1: 2, a2: "SpeakDispatchResponse:  Entity ( %i/%s ) playing sound '%s'\n", v38, pszValue, response);
      CAI_Expresser::NoteSpeaking(this, duration: speakTime, delay);
      spoke = true;
      goto LABEL_49;
    case 2u:
      spoke = ((int (__thiscall *)(CAI_Expresser *, char *, _DWORD, int, soundlevel_t, _DWORD))this->SpeakRawSentence)(
                a1: this,
                a2: response,
                a3: LODWORD(delay),
                a4: 1065353216,
                a5: soundlevel,
                a6: 0) != -1;
      goto LABEL_48;
    case 3u:
      v30 = CAI_Expresser::SpeakRawScene(this, pszScene: response, delay, response: v5, filter);
LABEL_47:
      spoke = v30;
LABEL_48:
      if ( spoke )
        goto LABEL_49;
      goto LABEL_83;
    case 5u:
      if ( g_pDeveloper->m_pParent != nullptr && g_pDeveloper->m_pParent->m_Value.m_nValue > 0 )
      {
        in.x = 0.5;
        in.y = 0.5;
        in.z = 1.0;
        v39 = CAI_Expresser::GetOuter(this);
        CCollisionProperty::NormalizedToWorldSpace(this: &v39->m_Collision, &in, pResult: &vPrintPos);
        NDebugOverlay::Text(origin: &vPrintPos, text: response, bViewCheck: true, duration: 1.5);
      }
      spoke = true;
LABEL_49:
      this->m_flLastTimeAcceptedSpeak = gpGlobals->curtime;
      if ( ai_debug_speech.m_pParent != nullptr
        && ai_debug_speech.m_pParent->m_Value.m_nValue != 0
        && g_pDeveloper->m_pParent != nullptr
        && g_pDeveloper->m_pParent->m_Value.m_nValue > 0
        && v5->m_Type != 5 )
      {
        in.x = 0.5;
        in.y = 0.5;
        in.z = 1.0;
        v31 = CAI_Expresser::GetOuter(this);
        CCollisionProperty::NormalizedToWorldSpace(this: &v31->m_Collision, &in, pResult: &vPrintPos);
        v32 = ResponseRules::CRR_Concept::GetStringConcept(this: concept);
        v33 = CFmtStrN<256>::CFmtStrN<256>(this: &v45, pszFormat: "%s: %s", v32, response);
        NDebugOverlay::Text(origin: &vPrintPos, text: v33->m_szBuf, bViewCheck: true, duration: 1.5);
      }
      if ( v5->m_bApplyContextToWorld )
      {
        pEdicts = gpGlobals->pEdicts;
        if ( pEdicts != nullptr )
          v35 = (pEdicts->m_fStateFlags & 2) == 0 ? pEdicts : nullptr;
        else
          v35 = nullptr;
        if ( v35 != nullptr || pEdicts != nullptr && (v35 = gpGlobals->pEdicts, (pEdicts->m_fStateFlags & 2) == 0) )
        {
          m_pUnk = v35->m_pUnk;
          if ( m_pUnk != nullptr )
          {
            v42 = m_pUnk->GetBaseEntity(this: m_pUnk);
            if ( v42 != nullptr )
              CBaseEntity::AddContext(this: v42, contextName: v5->m_szContext);
          }
        }
      }
      else
      {
        v43 = this->m_pOuter.m_Index;
        if ( v43 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v43].m_SerialNumber != HIWORD(v43) )
          v44 = nullptr;
        else
          v44 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v43].m_pEntity;
        CBaseEntity::AddContext(this: v44, contextName: v5->m_szContext);
      }
      CAI_Expresser::SetSpokeConcept(this, concept: *concept, response: v5, bCallback: true);
      goto LABEL_83;
    case 6u:
      v40 = CAI_Expresser::GetOuter(this);
      return CAI_Expresser::FireEntIOFromResponse(response, pInitiator: v40);
    default:
LABEL_83:
      v29 = spoke;
      break;
  }
  return v29;
}

//------------------------------------------------------------------------------
// Address: 0x103FED60
// Name: ConceptHistory_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *ConceptHistory_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<ConceptHistory_t>();
  ConceptHistory_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FED70
// Name: CAI_Expresser_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Expresser_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Expresser>();
  CAI_Expresser_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FED80
// Name: _dynamic_initializer_for__ai_speechfilter__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_speechfilter__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_SpeechFilter> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_speechfilter,
           a3: "ai_speechfilter");
}
