// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_scriptconditions.cpp
// Functions: 34
// ============================================================

#include "game\server\ai_scriptconditions.h"

//------------------------------------------------------------------------------
// Address: 0x10082E10
// Name: private: virtual struct datamap_t __near * CAI_ScriptConditions::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_ScriptConditions::GetDataDescMap(CAI_ScriptConditions *this)
{
  return &CAI_ScriptConditions::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10082E20
// Name: private: bool CAI_ScriptConditions::EvalActorSeePlayer(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ScriptConditions::EvalActorSeePlayer(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  CAI_BaseNPC *v4; // eax

  if ( this->m_fActorSeePlayer == TRS_NONE || args->pActor == nullptr )
    return true;
  v4 = args->pActor->MyNPCPointer(this: args->pActor);
  return this->m_fActorSeePlayer == CAI_BaseNPC::HasCondition(this: v4, iCondition: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10082E70
// Name: private: bool CAI_ScriptConditions::EvalActorSeeTarget(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ScriptConditions::EvalActorSeeTarget(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  CAI_BaseNPC *v4; // esi

  if ( this->m_fActorSeeTarget == TRS_NONE )
    return true;
  if ( args->pTarget == nullptr || args->pActor == nullptr )
    return true;
  v4 = args->pActor->MyNPCPointer(this: args->pActor);
  if ( v4->FInViewCone(this: v4, a2: args->pTarget)
    && v4->FVisible_2(this: v4, a2: args->pTarget, a3: 16449, a4: nullptr) )
  {
    return this->m_fActorSeeTarget == TRS_TRUE;
  }
  else
  {
    return this->m_fActorSeeTarget == TRS_FALSE;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10082F00
// Name: private: bool CAI_ScriptConditions::EvalPlayerBlockingActor(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ScriptConditions::EvalPlayerBlockingActor(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  ThreeState_t m_fPlayerBlockingActor; // eax

  m_fPlayerBlockingActor = this->m_fPlayerBlockingActor;
  return m_fPlayerBlockingActor == TRS_NONE || m_fPlayerBlockingActor == TRS_FALSE;
}

//------------------------------------------------------------------------------
// Address: 0x10082F20
// Name: private: virtual void CAI_ScriptConditions::Spawn(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::Spawn(CAI_ScriptConditions *this)
{
  float m_flPlayerActorProximity; // xmm0_4
  float m_flPlayerTargetProximity; // xmm0_4
  float m_flActorTargetProximity; // xmm0_4

  m_flPlayerActorProximity = this->m_flPlayerActorProximity;
  this->m_PlayerActorProxTester.m_fInside = m_flPlayerActorProximity > 0.0;
  this->m_PlayerActorProxTester.m_distSq = m_flPlayerActorProximity * m_flPlayerActorProximity;
  m_flPlayerTargetProximity = this->m_flPlayerTargetProximity;
  this->m_PlayerTargetProxTester.m_fInside = m_flPlayerTargetProximity > 0.0;
  this->m_PlayerTargetProxTester.m_distSq = m_flPlayerTargetProximity * m_flPlayerTargetProximity;
  m_flActorTargetProximity = this->m_flActorTargetProximity;
  this->m_ActorTargetProxTester.m_fInside = m_flActorTargetProximity > 0.0;
  this->m_ActorTargetProxTester.m_distSq = m_flActorTargetProximity * m_flActorTargetProximity;
  this->m_bLeaveAsleep = this->m_fDisabled;
}

//------------------------------------------------------------------------------
// Address: 0x10082FB0
// Name: private: void CAI_ScriptConditions::InputDisable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::InputDisable(CAI_ScriptConditions *this, inputdata_t *inputdata)
{
  this->m_bLeaveAsleep = true;
  CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
  this->m_fDisabled = true;
}

//------------------------------------------------------------------------------
// Address: 0x10082FE0
// Name: public: bool CAI_ProxTester::Check(class CBaseEntity __near *,class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_ProxTester::Check(CAI_ProxTester *this, CBaseEntity *pEntity1, CBaseEntity *pEntity2)
{
  float v4; // xmm1_4
  int savedregs; // [esp+4h] [ebp+0h] BYREF

  if ( this->m_distSq == 0.0 || pEntity1 == nullptr || pEntity2 == nullptr )
    return 1;
  if ( (pEntity2->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity2, a2: (int)&savedregs);
  if ( (pEntity1->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: pEntity1, a2: (int)&savedregs);
  v4 = pEntity1->m_vecAbsOrigin.y - pEntity2->m_vecAbsOrigin.y;
  if ( this->m_distSq <= (float)((float)((float)((float)(pEntity1->m_vecAbsOrigin.x - pEntity2->m_vecAbsOrigin.x)
                                               * (float)(pEntity1->m_vecAbsOrigin.x - pEntity2->m_vecAbsOrigin.x))
                                       + (float)(v4 * v4))
                               + (float)((float)(pEntity1->m_vecAbsOrigin.z - pEntity2->m_vecAbsOrigin.z)
                                       * (float)(pEntity1->m_vecAbsOrigin.z - pEntity2->m_vecAbsOrigin.z))) )
    return !this->m_fInside;
  else
    return this->m_fInside;
}

//------------------------------------------------------------------------------
// Address: 0x100830C0
// Name: private: bool CAI_ScriptConditions::EvalState(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_ScriptConditions::EvalState(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  bool result; // al
  NPC_STATE m_NPCState; // ecx
  int v5; // eax
  int v6; // ecx
  int v7; // edx

  if ( args->pActor == nullptr )
    return true;
  m_NPCState = args->pActor->MyNPCPointer(this: args->pActor)->m_NPCState;
  v5 = stateVals[m_NPCState];
  if ( v5 >= 0 )
  {
    v6 = stateVals[this->m_fMinState];
    v7 = stateVals[this->m_fMaxState];
    if ( v6 <= v7 )
    {
      return v5 >= v6 && v5 <= v7;
    }
    else
    {
      DevMsg(a1: "Script condition warning: Invalid setting for Maximum/Minimum state\n");
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
      this->m_fDisabled = true;
      return false;
    }
  }
  else
  {
    if ( m_NPCState != NPC_STATE_SCRIPT )
      return false;
    result = true;
    if ( this->m_fScriptStatus < TRS_TRUE )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10083180
// Name: private: bool CAI_ScriptConditions::EvalPlayerActorProximity(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ScriptConditions::EvalPlayerActorProximity(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  return args->pActor == nullptr
      || CAI_ProxTester::Check(this: &this->m_PlayerActorProxTester, pEntity1: args->pPlayer, pEntity2: args->pActor) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100831B0
// Name: private: bool CAI_ScriptConditions::EvalPlayerTargetProximity(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ScriptConditions::EvalPlayerTargetProximity(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  return args->pTarget == nullptr
      || CAI_ProxTester::Check(this: &this->m_PlayerTargetProxTester, pEntity1: args->pPlayer, pEntity2: args->pTarget) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100831E0
// Name: private: bool CAI_ScriptConditions::EvalActorTargetProximity(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ScriptConditions::EvalActorTargetProximity(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  return args->pTarget == nullptr
      || args->pActor == nullptr
      || CAI_ProxTester::Check(this: &this->m_ActorTargetProxTester, pEntity1: args->pActor, pEntity2: args->pTarget) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10083220
// Name: private: bool CAI_ScriptConditions::EvalPlayerActorLOS(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_ScriptConditions::EvalPlayerActorLOS(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  ThreeState_t m_fPlayerActorLOS; // ecx
  CBaseEntity *pActor; // esi
  bool v5; // bl
  CBaseCombatCharacter *v6; // eax

  m_fPlayerActorLOS = this->m_fPlayerActorLOS;
  if ( m_fPlayerActorLOS == TRS_NONE )
    return 1;
  pActor = args->pActor;
  if ( args->pActor == nullptr )
    return 1;
  v5 = m_fPlayerActorLOS == TRS_FALSE;
  v6 = args->pPlayer->MyCombatCharacterPointer(this: args->pPlayer);
  if ( v6 == nullptr )
    return 1;
  if ( pActor->FVisible_2(this: pActor, a2: v6, a3: 16449, a4: nullptr) )
  {
    if ( !v5 )
      return 1;
  }
  else if ( v5 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10083290
// Name: private: bool CAI_ScriptConditions::EvalPlayerTargetLOS(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_ScriptConditions::EvalPlayerTargetLOS(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  ThreeState_t m_fPlayerTargetLOS; // ecx
  CBaseEntity *pTarget; // esi
  bool v5; // bl
  CBaseCombatCharacter *v6; // eax

  m_fPlayerTargetLOS = this->m_fPlayerTargetLOS;
  if ( m_fPlayerTargetLOS == TRS_NONE )
    return 1;
  pTarget = args->pTarget;
  if ( pTarget == nullptr )
    return 1;
  v5 = m_fPlayerTargetLOS == TRS_FALSE;
  v6 = args->pPlayer->MyCombatCharacterPointer(this: args->pPlayer);
  if ( v6 == nullptr )
    return 1;
  if ( pTarget->FVisible_2(this: pTarget, a2: v6, a3: 16449, a4: nullptr) )
  {
    if ( !v5 )
      return 1;
  }
  else if ( v5 )
  {
    return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10083300
// Name: private: static bool CAI_ScriptConditions::IsInFOV(class CBaseEntity __near *,class CBaseEntity __near *,float,bool)
// Source: json
//------------------------------------------------------------------------------
bool __usercall CAI_ScriptConditions::IsInFOV@<al>(
        float a1@<ebp>,
        CBaseEntity *pViewer,
        CBaseEntity *pViewed,
        float fov,
        bool bTrueCone)
{
  CBaseCombatCharacter *v5; // esi
  __m128 v6; // xmm0
  double v7; // xmm0_8
  float *v8; // eax
  Vector *(__thiscall *EyePosition)(CBaseEntity *, Vector *); // edx
  float *v10; // esi
  Vector *v11; // eax
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm0_4
  float v15; // xmm1_4
  float *v16; // eax
  Vector *(__thiscall *v17)(CBaseEntity *, Vector *); // edx
  float *v18; // esi
  Vector *v19; // eax
  float v20; // xmm2_4
  float v21; // xmm0_4
  float v22; // xmm1_4
  float v23; // xmm3_4
  float v24; // xmm1_4
  float v25; // xmm0_4
  _BYTE v27[20]; // [esp-2Ch] [ebp-48h] BYREF
  _BYTE v28[12]; // [esp-18h] [ebp-34h] BYREF
  float v29; // [esp-Ch] [ebp-28h]
  float v30; // [esp-8h] [ebp-24h]
  float v31; // [esp-4h] [ebp-20h]
  Vector vLookDir; // [esp+0h] [ebp-1Ch] BYREF
  Vector vActorDir; // [esp+Ch] [ebp-10h]
  float retaddr; // [esp+1Ch] [ebp+0h]

  vActorDir.y = a1;
  vActorDir.z = retaddr;
  if ( pViewer != nullptr )
    v5 = pViewer->MyCombatCharacterPointer(this: pViewer);
  else
    v5 = nullptr;
  v6 = (__m128)LODWORD(fov);
  if ( fov >= 360.0 || v5 == nullptr )
    return v6.m128_f32[0] >= 0.0;
  v6.m128_f32[0] = (float)(fov * 0.5) * 0.017453292;
  __libm_sse2_cos(X: (__m128i)_mm_cvtps_pd(v6));
  *(float *)&v7 = v7;
  vActorDir.x = *(float *)&v7;
  if ( bTrueCone )
  {
    v8 = (float *)v5->EyeDirection3D(this: v5, result: (Vector *)v28);
    v29 = *v8;
    v30 = v8[1];
    EyePosition = pViewer->EyePosition;
    v31 = v8[2];
    v10 = (float *)EyePosition(this: pViewer, result: (Vector *)v28);
    v11 = pViewed->EyePosition(this: pViewed, result: v27);
    v12 = v11->y - v10[1];
    v13 = v11->z - v10[2];
    vLookDir.x = v11->x - *v10;
    vLookDir.y = v12;
    vLookDir.z = v13;
    VectorNormalize(vec: &vLookDir);
    v14 = (float)(vLookDir.y * v30) + (float)(vLookDir.x * v29);
    v15 = v31 * vLookDir.z;
  }
  else
  {
    v16 = (float *)v5->EyeDirection2D(this: v5, result: (Vector *)v27);
    v29 = *v16;
    v17 = pViewer->EyePosition;
    v30 = v16[1];
    v18 = (float *)v17(this: pViewer, result: (Vector *)v27);
    v19 = pViewed->EyePosition(this: pViewed, result: v28);
    v20 = v19->x - *v18;
    v21 = v19->y - v18[1];
    vLookDir.x = v20;
    vLookDir.y = v21;
    vLookDir.z = 0.0;
    v22 = fsqrt((float)(v21 * v21) + (float)(v20 * v20));
    if ( v22 == 0.0 )
    {
      v25 = 0.0;
      v24 = 0.0;
    }
    else
    {
      v23 = 1.0 / v22;
      v24 = (float)(1.0 / v22) * v20;
      v25 = v21 * v23;
    }
    v14 = v25 * v30;
    v15 = v24 * v29;
  }
  if ( vActorDir.x <= (float)(v14 + v15) )
  {
    v6.m128_f32[0] = fov;
    return v6.m128_f32[0] >= 0.0;
  }
  return fov < 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10083540
// Name: private: bool CAI_ScriptConditions::EvalPlayerActorLook(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ScriptConditions::EvalPlayerActorLook(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  return args->pActor == nullptr
      || CAI_ScriptConditions::IsInFOV(
           a1: COERCE_FLOAT(&savedregs),
           pViewer: args->pPlayer,
           pViewed: args->pActor,
           fov: this->m_flPlayerActorFOV,
           bTrueCone: this->m_bPlayerActorFOVTrueCone);
}

//------------------------------------------------------------------------------
// Address: 0x10083590
// Name: private: bool CAI_ScriptConditions::EvalPlayerTargetLook(struct CAI_ScriptConditions::EvalArgs_t const __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_ScriptConditions::EvalPlayerTargetLook(
        CAI_ScriptConditions *this,
        const CAI_ScriptConditions::EvalArgs_t *args)
{
  CBaseEntity *pTarget; // eax
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  pTarget = args->pTarget;
  return pTarget == nullptr
      || CAI_ScriptConditions::IsInFOV(
           a1: COERCE_FLOAT(&savedregs),
           pViewer: args->pPlayer,
           pViewed: pTarget,
           fov: this->m_flPlayerTargetFOV,
           bTrueCone: this->m_bPlayerTargetFOVTrueCone);
}

//------------------------------------------------------------------------------
// Address: 0x100835E0
// Name: private: bool CAI_ScriptConditions::ActorInList(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_ScriptConditions::ActorInList(CAI_ScriptConditions *this, CBaseEntity *pActor)
{
  int m_Size; // edi
  int v3; // edx
  CAI_ScriptConditionsElement *i; // esi
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx

  m_Size = this->m_ElementList.m_Size;
  v3 = 0;
  if ( m_Size <= 0 )
    return 0;
  for ( i = this->m_ElementList.m_Memory.m_pMemory; ; ++i )
  {
    m_Index = i->m_hActor.m_Index;
    if ( i->m_hActor.m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
    }
    if ( m_pEntity == pActor )
      break;
    if ( ++v3 >= m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10083920
// Name: private: virtual void CAI_ScriptConditions::UpdateOnRemove(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::UpdateOnRemove(CAI_ScriptConditions *this)
{
  IEntityListener *v2; // eax
  bool v3; // sf
  CAI_ScriptConditionsElement *m_pMemory; // ecx

  if ( this != nullptr )
    v2 = &this->IEntityListener;
  else
    v2 = nullptr;
  CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: v2);
  CBaseEntity::UpdateOnRemove(this);
  v3 = this->m_ElementList.m_Memory.m_nGrowSize < 0;
  this->m_ElementList.m_Size = 0;
  if ( v3 )
  {
    this->m_ElementList.m_pElements = this->m_ElementList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ElementList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ElementList.m_Memory.m_pMemory);
      this->m_ElementList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
    this->m_ElementList.m_Memory.m_nAllocationCount = 0;
    this->m_ElementList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100839A0
// Name: private: void CAI_ScriptConditions::EvaluationThink(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::EvaluationThink(CAI_ScriptConditions *this)
{
  ConVar *m_pParent; // edi
  CAI_ScriptConditionsElement *m_pMemory; // edx
  bool v4; // zf
  CAI_ScriptConditionsElement *v5; // edx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // ecx
  int v8; // eax
  int v9; // eax
  float m_flMinTimeout; // xmm0_4
  const char *pszValue; // eax
  COutputEvent *p_m_OnConditionsSatisfied; // ecx
  unsigned int v13; // eax
  CBaseEntity *v14; // ecx
  int v15; // ebx
  int *v16; // edi
  float v17; // xmm0_4
  const char *v18; // eax
  const char *v19; // eax
  const char *DebugName; // eax
  const char *fDelay; // [esp+8h] [ebp-2Ch]
  CAI_ScriptConditions::EvalArgs_t args; // [esp+18h] [ebp-1Ch] BYREF
  CAI_ScriptConditionsElement *pConditionElement; // [esp+24h] [ebp-10h]
  int i; // [esp+28h] [ebp-Ch]
  unsigned int v25; // [esp+2Ch] [ebp-8h]
  int iActorsDone; // [esp+30h] [ebp-4h]

  if ( !this->m_fDisabled )
  {
    iActorsDone = 0;
    i = 0;
    if ( this->m_ElementList.m_Size > 0 )
    {
      m_pParent = debugscriptconditions.m_pParent;
      v25 = 0;
      do
      {
        m_pMemory = this->m_ElementList.m_Memory.m_pMemory;
        v4 = &m_pMemory[v25 / 0x14] == nullptr;
        v5 = &m_pMemory[v25 / 0x14];
        pConditionElement = v5;
        if ( v4 )
        {
          ++i;
          v25 += 20;
        }
        else
        {
          m_Index = v5->m_hActor.m_Index;
          if ( v5->m_hActor.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          if ( this->m_Actor.pszValue == nullptr || m_pEntity != nullptr )
          {
            v25 += 20;
            m_flMinTimeout = this->m_flMinTimeout;
            ++i;
            if ( m_flMinTimeout <= 0.0 || (float)(gpGlobals->curtime - v5->m_Timeout.m_next) <= -0.001 )
            {
              args.pActor = m_pEntity;
              args.pPlayer = UTIL_GetLocalPlayer();
              v13 = this->m_hTarget.m_Index;
              if ( v13 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
                v14 = nullptr;
              else
                v14 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
              args.pTarget = v14;
              v15 = 0;
              v16 = &dword_1056C324;
              do
              {
                if ( ((unsigned __int8 (__thiscall *)(char *, CAI_ScriptConditions::EvalArgs_t *))*(v16 - 1))(
                       a1: (char *)this + *v16,
                       a2: &args) == 0 )
                {
                  pConditionElement->m_Timer.m_next = pConditionElement->m_Timer.m_interval + gpGlobals->curtime;
                  m_pParent = debugscriptconditions.m_pParent;
                  if ( debugscriptconditions.m_pParent != nullptr
                    && debugscriptconditions.m_pParent->m_Value.m_nValue != 0 )
                  {
                    fDelay = (&off_1056C328)[4 * v15];
                    DebugName = CBaseEntity::GetDebugName(this);
                    DevMsg(a1: "%s failed on: %s\n", DebugName, fDelay);
                    goto LABEL_43;
                  }
                  goto LABEL_44;
                }
                v16 += 4;
                ++v15;
              }
              while ( (int)v16 < (int)dword_1056C3D4 );
              m_pParent = debugscriptconditions.m_pParent;
              if ( debugscriptconditions.m_pParent != nullptr && debugscriptconditions.m_pParent->m_Value.m_nValue != 0 )
              {
                v17 = pConditionElement->m_Timer.m_next - gpGlobals->curtime;
                if ( v17 < 0.0 )
                  v17 = 0.0;
                v18 = CBaseEntity::GetDebugName(this);
                DevMsg(a1: "%s waiting... %f\n", v18, v17);
                m_pParent = debugscriptconditions.m_pParent;
              }
              if ( (float)(gpGlobals->curtime - pConditionElement->m_Timer.m_next) > -0.001 )
              {
                if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
                {
                  v19 = CBaseEntity::GetDebugName(this);
                  DevMsg(a1: "%s firing output OnConditionsSatisfied\n", v19);
                }
                ++iActorsDone;
                p_m_OnConditionsSatisfied = &this->m_OnConditionsSatisfied;
                goto LABEL_42;
              }
              continue;
            }
            if ( m_pParent != nullptr && m_pParent->m_Value.m_nValue != 0 )
            {
              pszValue = this->m_iName.m_Value.pszValue;
              if ( pszValue == nullptr )
                pszValue = locale;
              DevMsg(a1: "%s firing output OnConditionsTimeout (%f seconds)\n", pszValue, v5->m_Timeout.m_interval);
            }
            ++iActorsDone;
            p_m_OnConditionsSatisfied = &this->m_OnConditionsTimeout;
LABEL_42:
            COutputEvent::FireOutput(this: p_m_OnConditionsSatisfied, pActivator: this, pCaller: this, fDelay: 0.0);
          }
          else
          {
            if ( this->m_ElementList.m_Size == 1 )
            {
              DevMsg(a1: "Warning: Active AI script conditions associated with an non-existant or destroyed NPC\n");
              COutputEvent::FireOutput(this: &this->m_NoValidActors, pActivator: this, pCaller: this, fDelay: 0.0);
            }
            v8 = this->m_ElementList.m_Size - i;
            ++iActorsDone;
            v9 = v8 - 1;
            if ( v9 > 0 )
              _V_memmove(
                dest: &this->m_ElementList.m_Memory.m_pMemory[v25 / 0x14],
                src: &this->m_ElementList.m_Memory.m_pMemory[v25 / 0x14 + 1],
                count: 20 * v9);
            --this->m_ElementList.m_Size;
          }
LABEL_43:
          m_pParent = debugscriptconditions.m_pParent;
        }
LABEL_44:
        ;
      }
      while ( i < this->m_ElementList.m_Size );
    }
    if ( iActorsDone == this->m_ElementList.m_Size )
    {
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
      this->m_fDisabled = true;
      this->m_ElementList.m_Size = 0;
      if ( this->m_ElementList.m_Memory.m_nGrowSize >= 0 )
      {
        if ( this->m_ElementList.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ElementList.m_Memory.m_pMemory);
          this->m_ElementList.m_Memory.m_pMemory = nullptr;
        }
        this->m_ElementList.m_Memory.m_nAllocationCount = 0;
      }
      this->m_ElementList.m_pElements = this->m_ElementList.m_Memory.m_pMemory;
    }
    CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.25, szContext: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10083D30
// Name: public: CAI_ScriptConditions::CAI_ScriptConditions(void)
// Source: json
//------------------------------------------------------------------------------
CAI_ScriptConditions *__thiscall CAI_ScriptConditions::CAI_ScriptConditions(CAI_ScriptConditions *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->IEntityListener::__vftable = (IEntityListener_vtbl *)&IEntityListener::`vftable';
  this->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_ScriptConditions_vtbl *)&CAI_ScriptConditions::`vftable'{for `CBaseEntity'};
  this->IEntityListener::__vftable = (IEntityListener_vtbl *)&CAI_ScriptConditions::`vftable'{for `IEntityListener'};
  this->m_OnConditionsSatisfied.m_Value.iVal = 0;
  this->m_OnConditionsSatisfied.m_Value.eVal.m_Index = -1;
  this->m_OnConditionsSatisfied.m_Value.fieldType = FIELD_VOID;
  this->m_OnConditionsTimeout.m_Value.iVal = 0;
  this->m_OnConditionsTimeout.m_Value.eVal.m_Index = -1;
  this->m_OnConditionsTimeout.m_Value.fieldType = FIELD_VOID;
  this->m_NoValidActors.m_Value.iVal = 0;
  this->m_NoValidActors.m_Value.eVal.m_Index = -1;
  this->m_NoValidActors.m_Value.fieldType = FIELD_VOID;
  this->m_fDisabled = true;
  this->m_hTarget.m_Index = -1;
  this->m_flRequiredTime = 0.0;
  this->m_Timer = (CSimTimer)3212836864LL;
  this->m_Timeout = (CSimTimer)3212836864LL;
  this->m_fMinState = NPC_STATE_IDLE;
  this->m_fMaxState = NPC_STATE_IDLE;
  this->m_flPlayerActorProximity = 0.0;
  this->m_fScriptStatus = TRS_NONE;
  this->m_fActorSeePlayer = TRS_NONE;
  this->m_PlayerActorProxTester.m_fInside = false;
  this->m_PlayerActorProxTester.m_distSq = 0.0;
  this->m_fPlayerActorLOS = TRS_NONE;
  this->m_fActorSeeTarget = TRS_NONE;
  this->m_flPlayerActorFOV = -1.0;
  this->m_flActorTargetProximity = 0.0;
  this->m_ActorTargetProxTester.m_fInside = false;
  this->m_ActorTargetProxTester.m_distSq = 0.0;
  this->m_flPlayerTargetProximity = 0.0;
  this->m_PlayerTargetProxTester.m_fInside = false;
  this->m_PlayerTargetProxTester.m_distSq = 0.0;
  this->m_fPlayerTargetLOS = TRS_NONE;
  this->m_fPlayerBlockingActor = TRS_NONE;
  this->m_fActorInPVS = TRS_NONE;
  this->m_fActorInVehicle = TRS_NONE;
  this->m_fPlayerInVehicle = TRS_NONE;
  this->m_flPlayerTargetFOV = 0.0;
  this->m_flMinTimeout = 0.0;
  this->m_flMaxTimeout = 0.0;
  this->m_ElementList.m_Memory.m_pMemory = nullptr;
  this->m_ElementList.m_Memory.m_nAllocationCount = 0;
  this->m_ElementList.m_Memory.m_nGrowSize = 0;
  this->m_ElementList.m_Size = 0;
  this->m_ElementList.m_pElements = nullptr;
  this->m_hActor.m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10083EB0
// Name: private: int CAI_ScriptConditions::AddNewElement(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_ScriptConditions::AddNewElement(CAI_ScriptConditions *this, CBaseEntity *pActor)
{
  float m_flMaxTimeout; // xmm0_4
  float curtime; // xmm0_4
  CAI_ScriptConditionsElement conditionelement; // [esp+Ch] [ebp-14h] BYREF

  if ( pActor != nullptr )
    conditionelement.m_hActor.m_Index = pActor->GetRefEHandle(this: pActor)->m_Index;
  else
    conditionelement.m_hActor.m_Index = -1;
  m_flMaxTimeout = this->m_flMaxTimeout;
  if ( m_flMaxTimeout <= 0.0 )
  {
    curtime = gpGlobals->curtime;
    conditionelement.m_Timeout.m_interval = this->m_flMinTimeout;
  }
  else
  {
    conditionelement.m_Timeout.m_interval = ((double (__thiscall *)(IUniformRandomStream *, _DWORD, _DWORD))random->RandomFloat)(
                                              a1: random,
                                              a2: LODWORD(this->m_flMinTimeout),
                                              a3: LODWORD(m_flMaxTimeout));
    curtime = gpGlobals->curtime;
  }
  conditionelement.m_Timeout.m_next = curtime + conditionelement.m_Timeout.m_interval;
  conditionelement.m_Timer.m_interval = this->m_flRequiredTime;
  conditionelement.m_Timer.m_next = -1.0;
  if ( conditionelement.m_Timer.m_interval > 0.0 )
    conditionelement.m_Timer.m_next = curtime + conditionelement.m_Timer.m_interval;
  return CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>::InsertBefore(
           this: &this->m_ElementList,
           elem: this->m_ElementList.m_Size,
           src: &conditionelement);
}

//------------------------------------------------------------------------------
// Address: 0x10083FB0
// Name: private: void CAI_ScriptConditions::Enable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::Enable(CAI_ScriptConditions *this)
{
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  const char *v4; // eax
  CBaseEntity *v5; // eax
  CBaseEntity *v6; // edi
  const char *DebugName; // eax
  const char *v8; // eax

  pszValue = this->m_target.pszValue;
  if ( pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
    this->m_hTarget.m_Index = EntityByName->GetRefEHandle(this: EntityByName)->m_Index;
  else
    this->m_hTarget.m_Index = -1;
  v4 = this->m_Actor.pszValue;
  if ( v4 == nullptr )
    v4 = locale;
  v5 = CGlobalEntityList::FindEntityByName(
         this: &gEntList,
         pStartEntity: nullptr,
         szName: v4,
         pSearchingEntity: nullptr,
         pActivator: nullptr,
         pCaller: nullptr,
         pFilter: nullptr);
  v6 = v5;
  if ( this->m_ElementList.m_Size != 0 )
  {
LABEL_15:
    while ( v6 != nullptr )
    {
      if ( CAI_ScriptConditions::ActorInList(this, pActor: v6) == 0 )
        CAI_ScriptConditions::AddNewElement(this, pActor: v6);
      v8 = this->m_Actor.pszValue;
      if ( v8 == nullptr )
        v8 = locale;
      v6 = CGlobalEntityList::FindEntityByName(
             this: &gEntList,
             pStartEntity: v6,
             szName: v8,
             pSearchingEntity: nullptr,
             pActivator: nullptr,
             pCaller: nullptr,
             pFilter: nullptr);
    }
    goto LABEL_21;
  }
  if ( this->m_Actor.pszValue != nullptr )
  {
    if ( v5 == nullptr )
    {
      DebugName = CBaseEntity::GetDebugName(this);
      DevMsg(a1: "Warning: Spawning AI script conditions (%s) associated with an non-existant NPC\n", DebugName);
      COutputEvent::FireOutput(this: &this->m_NoValidActors, pActivator: this, pCaller: this, fDelay: 0.0);
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
      this->m_fDisabled = true;
      return;
    }
LABEL_13:
    if ( v5->MyNPCPointer(this: v5) == nullptr )
    {
      _Warning(a1: "Script condition warning: warning actor is not an NPC\n");
      CBaseEntity::ThinkSet(this, func: nullptr, thinkTime: 0.0, szContext: nullptr);
      this->m_fDisabled = true;
      return;
    }
    goto LABEL_15;
  }
  if ( v5 != nullptr )
    goto LABEL_13;
LABEL_21:
  if ( this->m_Actor.pszValue == nullptr && CAI_ScriptConditions::ActorInList(this, pActor: v6) == 0 )
    CAI_ScriptConditions::AddNewElement(this, pActor: nullptr);
  this->m_fDisabled = false;
  CBaseEntity::ThinkSet(
    this,
    func: (void (__thiscall *)(CBaseEntity *))CAI_ScriptConditions::EvaluationThink,
    thinkTime: 0.0,
    szContext: nullptr);
  CBaseEntity::SetNextThink(this, thinkTime: gpGlobals->curtime + 0.25, szContext: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10084170
// Name: private: void CAI_ScriptConditions::InputEnable(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::InputEnable(CAI_ScriptConditions *this, inputdata_t *inputdata)
{
  this->m_bLeaveAsleep = false;
  CAI_ScriptConditions::Enable(this);
}

//------------------------------------------------------------------------------
// Address: 0x10084180
// Name: private: virtual void CAI_ScriptConditions::OnEntitySpawned(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::OnEntitySpawned(CAI_ScriptConditions *this, CBaseEntity *pEntity)
{
  const char *m_nGrowSize; // eax

  if ( (LOBYTE(this->m_Network.m_TimerEvent.m_flUpdateInterval) == 0
     || BYTE1(this->m_Network.m_TimerEvent.m_flUpdateInterval) == 0)
    && pEntity->MyNPCPointer(this: pEntity) != nullptr )
  {
    m_nGrowSize = (const char *)this->m_aThinkFunctions.m_Memory.m_nGrowSize;
    if ( pEntity->m_iName.m_Value.pszValue == m_nGrowSize )
      goto LABEL_14;
    if ( m_nGrowSize == nullptr )
      m_nGrowSize = locale;
    if ( CBaseEntity::NameMatchesComplex(this: pEntity, pszNameOrWildcard: m_nGrowSize) != 0 )
    {
LABEL_14:
      if ( CAI_ScriptConditions::ActorInList(this: (CAI_ScriptConditions *)((char *)this - 852), pActor: pEntity) == 0 )
      {
        CAI_ScriptConditions::AddNewElement(this: (CAI_ScriptConditions *)((char *)this - 852), pActor: pEntity);
        if ( LOBYTE(this->m_Network.m_TimerEvent.m_flUpdateInterval) == 1
          && BYTE1(this->m_Network.m_TimerEvent.m_flUpdateInterval) == 0 )
        {
          CAI_ScriptConditions::Enable(this: (CAI_ScriptConditions *)((char *)this - 852));
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085550
// Name: private: virtual void CAI_ScriptConditions::OnRestore(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::OnRestore(CAI_ScriptConditions *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *m_pEntity; // eax
  float m_interval; // eax
  float m_next; // ecx
  float v12; // edx
  CAI_ScriptConditionsElement conditionactor; // [esp+4h] [ebp-14h] BYREF

  CBaseEntity::OnRestore(this);
  m_Index = this->m_hActor.m_Index;
  if ( m_Index != -1 )
  {
    v3 = (unsigned __int16)m_Index;
    v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
    v5 = HIWORD(m_Index);
    if ( v4->m_SerialNumber == v5 && v4->m_pEntity != nullptr )
    {
      v6 = v3;
      v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
      v8 = &g_pEntityList->m_EntPtrArray[v6];
      if ( v7 && (m_pEntity = v8->m_pEntity) != nullptr )
        conditionactor.m_hActor.m_Index = m_pEntity->GetRefEHandle(this: m_pEntity)->m_Index;
      else
        conditionactor.m_hActor.m_Index = -1;
      m_interval = this->m_Timeout.m_interval;
      m_next = this->m_Timer.m_next;
      conditionactor.m_Timeout.m_next = this->m_Timeout.m_next;
      v12 = this->m_Timer.m_interval;
      conditionactor.m_Timeout.m_interval = m_interval;
      conditionactor.m_Timer.m_next = m_next;
      conditionactor.m_Timer.m_interval = v12;
      CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>::InsertBefore(
        this: &this->m_ElementList,
        elem: this->m_ElementList.m_Size,
        src: &conditionactor);
      this->m_hActor.m_Index = -1;
    }
  }
  if ( this->m_ElementList.m_Size == 0 && this->m_Actor.pszValue == nullptr && !this->m_fDisabled )
    CAI_ScriptConditions::AddNewElement(this, pActor: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10085630
// Name: private: virtual void CAI_ScriptConditions::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_ScriptConditions::Activate(CAI_ScriptConditions *this)
{
  CBaseEntity::Activate(this);
  if ( !this->m_fDisabled )
    CAI_ScriptConditions::Enable(this);
}

//------------------------------------------------------------------------------
// Address: 0x103FEBE0
// Name: CAI_ScriptConditions_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ScriptConditions_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ScriptConditions>(__formal: nullptr);
  CAI_ScriptConditions_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEBF0
// Name: CAI_ProxTester_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ProxTester_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ProxTester>(__formal: nullptr);
  CAI_ProxTester_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEC00
// Name: CAI_ScriptConditionsElement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_ScriptConditionsElement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_ScriptConditionsElement>(__formal: nullptr);
  CAI_ScriptConditionsElement_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10084280
// Name: struct datamap_t __near * DataMapInit<class CAI_ScriptConditions>(class CAI_ScriptConditions __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ScriptConditions>()
{
  if ( (_S2_31 & 1) == 0 )
  {
    _S2_31 |= 1u;
    nameHolder_62.m_pszBase = "CAI_ScriptConditions";
    nameHolder_62.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_62.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_62.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_62.m_Names.m_Size = 0;
    nameHolder_62.m_Names.m_pElements = nullptr;
    nameHolder_62.m_nLenBase = 20;
    atexit(func: DataMapInit_CAI_ScriptConditions__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ScriptConditions::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_31 & 2) == 0 )
  {
    _S2_31 |= 2u;
    dataDesc_469[1].fieldName = CDatadescGeneratedNameHolder::GenerateName(
                                  this: &nameHolder_62,
                                  pszIdentifier: "EvaluationThink");
    dataDesc_469[1].flags = 32;
    dataDesc_469[1].fieldSize = 1;
    *(_QWORD *)&dataDesc_469[1].td = 0;
    *(_QWORD *)&dataDesc_469[1].override_field = 0;
    *(_QWORD *)&dataDesc_469[1].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_469[1].flatOffset[1] = 0;
    dataDesc_469[2].fieldType = FIELD_CUSTOM;
    dataDesc_469[3].fieldType = FIELD_CUSTOM;
    dataDesc_469[4].fieldType = FIELD_CUSTOM;
    *(_QWORD *)&dataDesc_469[2].inputFunc = 0;
    *(_QWORD *)&dataDesc_469[2].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_469[2].override_count = 0;
    *(_QWORD *)dataDesc_469[2].flatOffset = 0;
    dataDesc_469[2].fieldSize = 1;
    dataDesc_469[2].flags = 22;
    dataDesc_469[3].fieldSize = 1;
    *(_QWORD *)&dataDesc_469[3].inputFunc = 0;
    *(_QWORD *)&dataDesc_469[3].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_469[3].override_count = 0;
    *(_QWORD *)dataDesc_469[3].flatOffset = 0;
    dataDesc_469[4].fieldSize = 1;
    dataDesc_469[2].pSaveRestoreOps = eventFuncs;
    dataDesc_469[3].flags = 22;
    dataDesc_469[3].pSaveRestoreOps = eventFuncs;
    dataDesc_469[4].flags = 22;
    dataDesc_469[4].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_469[4].inputFunc = 0;
    *(_QWORD *)&dataDesc_469[4].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_469[4].override_count = 0;
    *(_QWORD *)dataDesc_469[4].flatOffset = 0;
    dataDesc_469[1].fieldOffset = 0;
    dataDesc_469[1].externalName = nullptr;
    dataDesc_469[1].pSaveRestoreOps = nullptr;
    dataDesc_469[1].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptConditions::EvaluationThink;
    dataDesc_469[2].fieldName = "m_OnConditionsSatisfied";
    dataDesc_469[2].fieldOffset = 856;
    dataDesc_469[2].externalName = "OnConditionsSatisfied";
    *(_DWORD *)&dataDesc_469[2].flatGroup = 0;
    dataDesc_469[3].fieldName = "m_OnConditionsTimeout";
    dataDesc_469[3].fieldOffset = 880;
    dataDesc_469[3].externalName = "OnConditionsTimeout";
    *(_DWORD *)&dataDesc_469[3].flatGroup = 0;
    dataDesc_469[4].fieldName = "m_NoValidActors";
    dataDesc_469[4].fieldOffset = 904;
    dataDesc_469[4].externalName = "NoValidActors";
    *(_DWORD *)&dataDesc_469[4].flatGroup = 0;
    dataDesc_469[5].fieldType = FIELD_VOID;
    dataDesc_469[5].fieldName = "InputEnable";
    dataDesc_469[5].fieldOffset = 0;
    dataDesc_469[5].fieldSize = 1;
    dataDesc_469[5].flags = 8;
    dataDesc_469[5].externalName = "Enable";
    dataDesc_469[5].pSaveRestoreOps = nullptr;
    dataDesc_469[5].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptConditions::InputEnable;
    *(_QWORD *)&dataDesc_469[5].td = 0;
    *(_QWORD *)&dataDesc_469[5].override_field = 0;
    *(_QWORD *)&dataDesc_469[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_469[5].flatOffset[1] = 0;
    dataDesc_469[9].fieldType = FIELD_STRING;
    dataDesc_469[6].fieldSize = 1;
    dataDesc_469[7].fieldSize = 1;
    dataDesc_469[8].fieldSize = 1;
    dataDesc_469[9].fieldSize = 1;
    dataDesc_469[6].flags = 8;
    dataDesc_469[9].flags = 6;
    *(_QWORD *)dataDesc_469[7].flatOffset = 0;
    dataDesc_469[7].flags = 6;
    dataDesc_469[8].flags = 2;
    dataDesc_469[10].fieldSize = 1;
    *(_QWORD *)&dataDesc_469[6].td = 0;
    *(_QWORD *)&dataDesc_469[6].override_field = 0;
    *(_QWORD *)&dataDesc_469[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_469[6].flatOffset[1] = 0;
    *(_QWORD *)dataDesc_469[8].flatOffset = 0;
    dataDesc_469[6].fieldType = FIELD_VOID;
    dataDesc_469[6].fieldName = "InputDisable";
    dataDesc_469[6].fieldOffset = 0;
    dataDesc_469[6].externalName = "Disable";
    dataDesc_469[6].pSaveRestoreOps = nullptr;
    dataDesc_469[6].inputFunc = (void (__thiscall *)(CBaseEntity *, inputdata_t *))CAI_ScriptConditions::InputDisable;
    dataDesc_469[7].fieldType = FIELD_BOOLEAN;
    dataDesc_469[7].fieldName = "m_fDisabled";
    dataDesc_469[7].fieldOffset = 928;
    dataDesc_469[7].externalName = "StartDisabled";
    dataDesc_469[7].pSaveRestoreOps = nullptr;
    dataDesc_469[7].inputFunc = nullptr;
    dataDesc_469[7].td = nullptr;
    dataDesc_469[7].fieldSizeInBytes = 1;
    dataDesc_469[7].override_field = nullptr;
    dataDesc_469[7].override_count = 0;
    dataDesc_469[7].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[7].flatGroup = 0;
    dataDesc_469[8].fieldType = FIELD_EHANDLE;
    dataDesc_469[8].fieldName = "m_hTarget";
    dataDesc_469[8].fieldOffset = 932;
    dataDesc_469[8].externalName = nullptr;
    dataDesc_469[8].pSaveRestoreOps = nullptr;
    dataDesc_469[8].inputFunc = nullptr;
    dataDesc_469[8].td = nullptr;
    dataDesc_469[8].fieldSizeInBytes = 4;
    dataDesc_469[8].override_field = nullptr;
    dataDesc_469[8].override_count = 0;
    dataDesc_469[8].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[8].flatGroup = 0;
    dataDesc_469[9].fieldName = "m_Actor";
    dataDesc_469[9].fieldOffset = 976;
    dataDesc_469[9].externalName = "Actor";
    dataDesc_469[9].pSaveRestoreOps = nullptr;
    dataDesc_469[9].inputFunc = nullptr;
    dataDesc_469[9].td = nullptr;
    dataDesc_469[9].fieldSizeInBytes = 4;
    dataDesc_469[9].override_field = nullptr;
    dataDesc_469[9].override_count = 0;
    dataDesc_469[9].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_469[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_469[9].flatGroup = 0;
    dataDesc_469[10].fieldType = FIELD_FLOAT;
    dataDesc_469[10].fieldName = "m_flRequiredTime";
    dataDesc_469[10].fieldOffset = 936;
    dataDesc_469[10].flags = 6;
    dataDesc_469[10].externalName = "RequiredTime";
    dataDesc_469[10].pSaveRestoreOps = nullptr;
    dataDesc_469[10].inputFunc = nullptr;
    dataDesc_469[10].td = nullptr;
    dataDesc_469[10].fieldSizeInBytes = 4;
    dataDesc_469[10].override_field = nullptr;
    dataDesc_469[12].fieldSize = 1;
    dataDesc_469[12].flags = 2;
    *(_QWORD *)dataDesc_469[10].flatOffset = 0;
    dataDesc_469[11].fieldType = FIELD_EHANDLE;
    dataDesc_469[13].fieldSize = 1;
    *(_QWORD *)dataDesc_469[11].flatOffset = 0;
    dataDesc_469[11].fieldSize = 1;
    dataDesc_469[13].flags = 2;
    *(_QWORD *)dataDesc_469[12].flatOffset = 0;
    dataDesc_469[11].flags = 2;
    dataDesc_469[12].fieldSizeInBytes = 8;
    dataDesc_469[13].fieldSizeInBytes = 8;
    dataDesc_469[14].fieldSize = 1;
    *(_QWORD *)dataDesc_469[13].flatOffset = 0;
    dataDesc_469[10].override_count = 0;
    dataDesc_469[10].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[10].flatGroup = 0;
    dataDesc_469[11].fieldName = "m_hActor";
    dataDesc_469[11].fieldOffset = 940;
    dataDesc_469[11].externalName = nullptr;
    dataDesc_469[11].pSaveRestoreOps = nullptr;
    dataDesc_469[11].inputFunc = nullptr;
    dataDesc_469[11].td = nullptr;
    dataDesc_469[11].fieldSizeInBytes = 4;
    dataDesc_469[11].override_field = nullptr;
    dataDesc_469[11].override_count = 0;
    dataDesc_469[11].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[11].flatGroup = 0;
    dataDesc_469[12].fieldType = FIELD_EMBEDDED;
    dataDesc_469[12].fieldName = "m_Timer";
    dataDesc_469[12].fieldOffset = 944;
    dataDesc_469[12].externalName = nullptr;
    dataDesc_469[12].pSaveRestoreOps = nullptr;
    dataDesc_469[12].inputFunc = nullptr;
    dataDesc_469[12].td = &CSimTimer::m_DataMap;
    dataDesc_469[12].override_field = nullptr;
    dataDesc_469[12].override_count = 0;
    dataDesc_469[12].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[12].flatGroup = 0;
    dataDesc_469[13].fieldType = FIELD_EMBEDDED;
    dataDesc_469[13].fieldName = "m_Timeout";
    dataDesc_469[13].fieldOffset = 952;
    dataDesc_469[13].externalName = nullptr;
    dataDesc_469[13].pSaveRestoreOps = nullptr;
    dataDesc_469[13].inputFunc = nullptr;
    dataDesc_469[13].td = &CSimTimer::m_DataMap;
    dataDesc_469[13].override_field = nullptr;
    dataDesc_469[13].override_count = 0;
    dataDesc_469[13].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[13].flatGroup = 0;
    dataDesc_469[14].fieldType = FIELD_INTEGER;
    dataDesc_469[14].fieldName = "m_fMinState";
    dataDesc_469[14].fieldOffset = 960;
    dataDesc_469[14].flags = 6;
    dataDesc_469[14].externalName = "MinimumState";
    dataDesc_469[14].pSaveRestoreOps = nullptr;
    dataDesc_469[14].inputFunc = nullptr;
    dataDesc_469[14].td = nullptr;
    dataDesc_469[14].fieldSizeInBytes = 4;
    dataDesc_469[14].override_field = nullptr;
    dataDesc_469[14].override_count = 0;
    dataDesc_469[14].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_469[14].flatOffset = 0;
    *(_DWORD *)&dataDesc_469[14].flatGroup = 0;
    dataDesc_469[15].fieldType = FIELD_INTEGER;
    dataDesc_469[15].fieldName = "m_fMaxState";
    dataDesc_469[15].fieldSize = 1;
    dataDesc_469[15].flags = 6;
    dataDesc_469[16].fieldSize = 1;
    dataDesc_469[16].flags = 6;
    dataDesc_469[17].fieldSize = 1;
    dataDesc_469[17].flags = 6;
    dataDesc_469[18].fieldSize = 1;
    *(_QWORD *)dataDesc_469[15].flatOffset = 0;
    dataDesc_469[18].flags = 6;
    *(_QWORD *)dataDesc_469[16].flatOffset = 0;
    dataDesc_469[19].fieldSize = 1;
    *(_QWORD *)dataDesc_469[17].flatOffset = 0;
    dataDesc_469[15].fieldOffset = 964;
    dataDesc_469[15].externalName = "MaximumState";
    dataDesc_469[15].pSaveRestoreOps = nullptr;
    dataDesc_469[15].inputFunc = nullptr;
    dataDesc_469[15].td = nullptr;
    dataDesc_469[15].fieldSizeInBytes = 4;
    dataDesc_469[15].override_field = nullptr;
    dataDesc_469[15].override_count = 0;
    dataDesc_469[15].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[15].flatGroup = 0;
    dataDesc_469[16].fieldType = FIELD_INTEGER;
    dataDesc_469[16].fieldName = "m_fScriptStatus";
    dataDesc_469[16].fieldOffset = 968;
    dataDesc_469[16].externalName = "ScriptStatus";
    dataDesc_469[16].pSaveRestoreOps = nullptr;
    dataDesc_469[16].inputFunc = nullptr;
    dataDesc_469[16].td = nullptr;
    dataDesc_469[16].fieldSizeInBytes = 4;
    dataDesc_469[16].override_field = nullptr;
    dataDesc_469[16].override_count = 0;
    dataDesc_469[16].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[16].flatGroup = 0;
    dataDesc_469[17].fieldType = FIELD_INTEGER;
    dataDesc_469[17].fieldName = "m_fActorSeePlayer";
    dataDesc_469[17].fieldOffset = 972;
    dataDesc_469[17].externalName = "ActorSeePlayer";
    dataDesc_469[17].pSaveRestoreOps = nullptr;
    dataDesc_469[17].inputFunc = nullptr;
    dataDesc_469[17].td = nullptr;
    dataDesc_469[17].fieldSizeInBytes = 4;
    dataDesc_469[17].override_field = nullptr;
    dataDesc_469[17].override_count = 0;
    dataDesc_469[17].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[17].flatGroup = 0;
    dataDesc_469[18].fieldType = FIELD_FLOAT;
    dataDesc_469[18].fieldName = "m_flPlayerActorProximity";
    dataDesc_469[18].fieldOffset = 980;
    dataDesc_469[18].externalName = "PlayerActorProximity";
    dataDesc_469[18].pSaveRestoreOps = nullptr;
    dataDesc_469[18].inputFunc = nullptr;
    dataDesc_469[18].td = nullptr;
    dataDesc_469[18].fieldSizeInBytes = 4;
    dataDesc_469[18].override_field = nullptr;
    dataDesc_469[18].override_count = 0;
    dataDesc_469[18].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_469[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_469[18].flatGroup = 0;
    dataDesc_469[19].fieldType = FIELD_EMBEDDED;
    dataDesc_469[19].fieldName = "m_PlayerActorProxTester";
    dataDesc_469[19].fieldOffset = 984;
    dataDesc_469[19].flags = 2;
    dataDesc_469[19].externalName = nullptr;
    dataDesc_469[19].pSaveRestoreOps = nullptr;
    dataDesc_469[19].inputFunc = nullptr;
    dataDesc_469[19].td = &CAI_ProxTester::m_DataMap;
    dataDesc_469[20].fieldSize = 1;
    dataDesc_469[20].flags = 6;
    dataDesc_469[21].fieldType = FIELD_BOOLEAN;
    dataDesc_469[21].fieldSize = 1;
    dataDesc_469[21].flags = 6;
    *(_QWORD *)dataDesc_469[19].flatOffset = 0;
    dataDesc_469[22].fieldSize = 1;
    *(_QWORD *)dataDesc_469[20].flatOffset = 0;
    dataDesc_469[22].flags = 6;
    *(_QWORD *)dataDesc_469[21].flatOffset = 0;
    dataDesc_469[23].fieldSize = 1;
    *(_QWORD *)dataDesc_469[22].flatOffset = 0;
    dataDesc_469[19].fieldSizeInBytes = 8;
    dataDesc_469[19].override_field = nullptr;
    dataDesc_469[19].override_count = 0;
    dataDesc_469[19].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[19].flatGroup = 0;
    dataDesc_469[20].fieldType = FIELD_FLOAT;
    dataDesc_469[20].fieldName = "m_flPlayerActorFOV";
    dataDesc_469[20].fieldOffset = 992;
    dataDesc_469[20].externalName = "PlayerActorFOV";
    dataDesc_469[20].pSaveRestoreOps = nullptr;
    dataDesc_469[20].inputFunc = nullptr;
    dataDesc_469[20].td = nullptr;
    dataDesc_469[20].fieldSizeInBytes = 4;
    dataDesc_469[20].override_field = nullptr;
    dataDesc_469[20].override_count = 0;
    dataDesc_469[20].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[20].flatGroup = 0;
    dataDesc_469[21].fieldName = "m_bPlayerActorFOVTrueCone";
    dataDesc_469[21].fieldOffset = 996;
    dataDesc_469[21].externalName = "PlayerActorFOVTrueCone";
    dataDesc_469[21].pSaveRestoreOps = nullptr;
    dataDesc_469[21].inputFunc = nullptr;
    dataDesc_469[21].td = nullptr;
    dataDesc_469[21].fieldSizeInBytes = 1;
    dataDesc_469[21].override_field = nullptr;
    dataDesc_469[21].override_count = 0;
    dataDesc_469[21].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[21].flatGroup = 0;
    dataDesc_469[22].fieldType = FIELD_INTEGER;
    dataDesc_469[22].fieldName = "m_fPlayerActorLOS";
    dataDesc_469[22].fieldOffset = 1000;
    dataDesc_469[22].externalName = "PlayerActorLOS";
    dataDesc_469[22].pSaveRestoreOps = nullptr;
    dataDesc_469[22].inputFunc = nullptr;
    dataDesc_469[22].td = nullptr;
    dataDesc_469[22].fieldSizeInBytes = 4;
    dataDesc_469[22].override_field = nullptr;
    dataDesc_469[22].override_count = 0;
    dataDesc_469[22].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[22].flatGroup = 0;
    dataDesc_469[23].fieldType = FIELD_INTEGER;
    dataDesc_469[23].fieldName = "m_fActorSeeTarget";
    dataDesc_469[23].fieldOffset = 1004;
    dataDesc_469[23].flags = 6;
    dataDesc_469[23].externalName = "ActorSeeTarget";
    dataDesc_469[23].pSaveRestoreOps = nullptr;
    dataDesc_469[23].inputFunc = nullptr;
    dataDesc_469[23].td = nullptr;
    dataDesc_469[23].fieldSizeInBytes = 4;
    dataDesc_469[23].override_field = nullptr;
    dataDesc_469[23].override_count = 0;
    dataDesc_469[23].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_469[23].flatOffset = 0;
    *(_DWORD *)&dataDesc_469[23].flatGroup = 0;
    dataDesc_469[24].fieldType = FIELD_FLOAT;
    dataDesc_469[24].fieldName = "m_flActorTargetProximity";
    dataDesc_469[24].fieldSize = 1;
    dataDesc_469[24].flags = 6;
    dataDesc_469[25].fieldType = FIELD_EMBEDDED;
    dataDesc_469[27].fieldType = FIELD_EMBEDDED;
    dataDesc_469[25].fieldSize = 1;
    dataDesc_469[27].fieldSize = 1;
    *(_QWORD *)dataDesc_469[24].flatOffset = 0;
    dataDesc_469[25].flags = 2;
    *(_QWORD *)dataDesc_469[25].flatOffset = 0;
    dataDesc_469[27].flags = 2;
    dataDesc_469[26].fieldSize = 1;
    *(_QWORD *)dataDesc_469[26].flatOffset = 0;
    dataDesc_469[28].fieldSize = 1;
    dataDesc_469[24].fieldOffset = 1008;
    dataDesc_469[24].externalName = "ActorTargetProximity";
    dataDesc_469[24].pSaveRestoreOps = nullptr;
    dataDesc_469[24].inputFunc = nullptr;
    dataDesc_469[24].td = nullptr;
    dataDesc_469[24].fieldSizeInBytes = 4;
    dataDesc_469[24].override_field = nullptr;
    dataDesc_469[24].override_count = 0;
    dataDesc_469[24].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[24].flatGroup = 0;
    dataDesc_469[25].fieldName = "m_ActorTargetProxTester";
    dataDesc_469[25].fieldOffset = 1012;
    dataDesc_469[25].externalName = nullptr;
    dataDesc_469[25].pSaveRestoreOps = nullptr;
    dataDesc_469[25].inputFunc = nullptr;
    dataDesc_469[25].td = &CAI_ProxTester::m_DataMap;
    dataDesc_469[25].fieldSizeInBytes = 8;
    dataDesc_469[25].override_field = nullptr;
    dataDesc_469[25].override_count = 0;
    dataDesc_469[25].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[25].flatGroup = 0;
    dataDesc_469[26].fieldType = FIELD_FLOAT;
    dataDesc_469[26].fieldName = "m_flPlayerTargetProximity";
    dataDesc_469[26].fieldOffset = 1020;
    dataDesc_469[26].flags = 6;
    dataDesc_469[26].externalName = "PlayerTargetProximity";
    dataDesc_469[26].pSaveRestoreOps = nullptr;
    dataDesc_469[26].inputFunc = nullptr;
    dataDesc_469[26].td = nullptr;
    dataDesc_469[26].fieldSizeInBytes = 4;
    dataDesc_469[26].override_field = nullptr;
    dataDesc_469[26].override_count = 0;
    dataDesc_469[26].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[26].flatGroup = 0;
    dataDesc_469[27].fieldName = "m_PlayerTargetProxTester";
    dataDesc_469[27].fieldOffset = 1024;
    dataDesc_469[27].externalName = nullptr;
    dataDesc_469[27].pSaveRestoreOps = nullptr;
    dataDesc_469[27].inputFunc = nullptr;
    dataDesc_469[27].td = &CAI_ProxTester::m_DataMap;
    dataDesc_469[27].fieldSizeInBytes = 8;
    dataDesc_469[27].override_field = nullptr;
    dataDesc_469[27].override_count = 0;
    dataDesc_469[27].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_469[27].flatOffset = 0;
    *(_DWORD *)&dataDesc_469[27].flatGroup = 0;
    dataDesc_469[28].fieldType = FIELD_FLOAT;
    dataDesc_469[28].fieldName = "m_flPlayerTargetFOV";
    dataDesc_469[28].fieldOffset = 1032;
    dataDesc_469[28].flags = 6;
    dataDesc_469[28].externalName = "PlayerTargetFOV";
    dataDesc_469[28].pSaveRestoreOps = nullptr;
    dataDesc_469[28].inputFunc = nullptr;
    dataDesc_469[28].td = nullptr;
    dataDesc_469[29].fieldSize = 1;
    dataDesc_469[29].flags = 6;
    dataDesc_469[30].fieldSize = 1;
    dataDesc_469[30].flags = 6;
    *(_QWORD *)dataDesc_469[28].flatOffset = 0;
    dataDesc_469[31].fieldSize = 1;
    *(_QWORD *)dataDesc_469[29].flatOffset = 0;
    dataDesc_469[31].flags = 6;
    *(_QWORD *)dataDesc_469[30].flatOffset = 0;
    dataDesc_469[32].fieldSize = 1;
    *(_QWORD *)dataDesc_469[31].flatOffset = 0;
    dataDesc_469[28].fieldSizeInBytes = 4;
    dataDesc_469[28].override_field = nullptr;
    dataDesc_469[28].override_count = 0;
    dataDesc_469[28].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[28].flatGroup = 0;
    dataDesc_469[29].fieldType = FIELD_BOOLEAN;
    dataDesc_469[29].fieldName = "m_bPlayerTargetFOVTrueCone";
    dataDesc_469[29].fieldOffset = 1036;
    dataDesc_469[29].externalName = "PlayerTargetFOVTrueCone";
    dataDesc_469[29].pSaveRestoreOps = nullptr;
    dataDesc_469[29].inputFunc = nullptr;
    dataDesc_469[29].td = nullptr;
    dataDesc_469[29].fieldSizeInBytes = 1;
    dataDesc_469[29].override_field = nullptr;
    dataDesc_469[29].override_count = 0;
    dataDesc_469[29].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[29].flatGroup = 0;
    dataDesc_469[30].fieldType = FIELD_INTEGER;
    dataDesc_469[30].fieldName = "m_fPlayerTargetLOS";
    dataDesc_469[30].fieldOffset = 1040;
    dataDesc_469[30].externalName = "PlayerTargetLOS";
    dataDesc_469[30].pSaveRestoreOps = nullptr;
    dataDesc_469[30].inputFunc = nullptr;
    dataDesc_469[30].td = nullptr;
    dataDesc_469[30].fieldSizeInBytes = 4;
    dataDesc_469[30].override_field = nullptr;
    dataDesc_469[30].override_count = 0;
    dataDesc_469[30].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[30].flatGroup = 0;
    dataDesc_469[31].fieldType = FIELD_INTEGER;
    dataDesc_469[31].fieldName = "m_fPlayerBlockingActor";
    dataDesc_469[31].fieldOffset = 1044;
    dataDesc_469[31].externalName = "PlayerBlockingActor";
    dataDesc_469[31].pSaveRestoreOps = nullptr;
    dataDesc_469[31].inputFunc = nullptr;
    dataDesc_469[31].td = nullptr;
    dataDesc_469[31].fieldSizeInBytes = 4;
    dataDesc_469[31].override_field = nullptr;
    dataDesc_469[31].override_count = 0;
    dataDesc_469[31].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[31].flatGroup = 0;
    dataDesc_469[32].fieldType = FIELD_FLOAT;
    dataDesc_469[32].fieldName = "m_flMinTimeout";
    dataDesc_469[32].fieldOffset = 1052;
    dataDesc_469[32].flags = 6;
    dataDesc_469[32].externalName = "MinTimeout";
    dataDesc_469[32].pSaveRestoreOps = nullptr;
    dataDesc_469[32].inputFunc = nullptr;
    dataDesc_469[32].td = nullptr;
    dataDesc_469[32].fieldSizeInBytes = 4;
    dataDesc_469[32].override_field = nullptr;
    dataDesc_469[32].override_count = 0;
    dataDesc_469[32].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_469[32].flatOffset = 0;
    *(_DWORD *)&dataDesc_469[32].flatGroup = 0;
    dataDesc_469[33].fieldType = FIELD_FLOAT;
    dataDesc_469[33].fieldName = "m_flMaxTimeout";
    dataDesc_469[33].fieldSize = 1;
    dataDesc_469[33].flags = 6;
    dataDesc_469[34].fieldSize = 1;
    dataDesc_469[34].fieldType = FIELD_INTEGER;
    dataDesc_469[35].fieldType = FIELD_INTEGER;
    dataDesc_469[36].fieldType = FIELD_INTEGER;
    dataDesc_469[34].flags = 6;
    *(_QWORD *)dataDesc_469[33].flatOffset = 0;
    dataDesc_469[36].fieldSize = 1;
    *(_QWORD *)dataDesc_469[34].flatOffset = 0;
    dataDesc_469[35].fieldSize = 1;
    dataDesc_469[33].fieldSizeInBytes = 4;
    dataDesc_469[34].fieldSizeInBytes = 4;
    dataDesc_469[35].fieldSizeInBytes = 4;
    dataDesc_469[36].flags = 6;
    dataDesc_469[36].fieldSizeInBytes = 4;
    *(_QWORD *)dataDesc_469[35].flatOffset = 0;
    dataDesc_469[35].flags = 6;
    dataDesc_469[33].fieldOffset = 1056;
    dataDesc_469[33].externalName = "MaxTimeout";
    dataDesc_469[33].pSaveRestoreOps = nullptr;
    dataDesc_469[33].inputFunc = nullptr;
    dataDesc_469[33].td = nullptr;
    dataDesc_469[33].override_field = nullptr;
    dataDesc_469[33].override_count = 0;
    dataDesc_469[33].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[33].flatGroup = 0;
    dataDesc_469[34].fieldName = "m_fActorInPVS";
    dataDesc_469[34].fieldOffset = 1048;
    dataDesc_469[34].externalName = "ActorInPVS";
    dataDesc_469[34].pSaveRestoreOps = nullptr;
    dataDesc_469[34].inputFunc = nullptr;
    dataDesc_469[34].td = nullptr;
    dataDesc_469[34].override_field = nullptr;
    dataDesc_469[34].override_count = 0;
    dataDesc_469[34].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[34].flatGroup = 0;
    dataDesc_469[35].fieldName = "m_fActorInVehicle";
    dataDesc_469[35].fieldOffset = 1060;
    dataDesc_469[35].externalName = "ActorInVehicle";
    dataDesc_469[35].pSaveRestoreOps = nullptr;
    dataDesc_469[35].inputFunc = nullptr;
    dataDesc_469[35].td = nullptr;
    dataDesc_469[35].override_field = nullptr;
    dataDesc_469[35].override_count = 0;
    dataDesc_469[35].fieldTolerance = 0.0;
    *(_DWORD *)&dataDesc_469[35].flatGroup = 0;
    dataDesc_469[36].fieldName = "m_fPlayerInVehicle";
    dataDesc_469[36].fieldOffset = 1064;
    dataDesc_469[36].externalName = "PlayerInVehicle";
    dataDesc_469[36].pSaveRestoreOps = nullptr;
    dataDesc_469[36].inputFunc = nullptr;
    dataDesc_469[36].td = nullptr;
    dataDesc_469[36].override_field = nullptr;
    dataDesc_469[36].override_count = 0;
    dataDesc_469[36].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_469[36].flatOffset = 0;
    *(_DWORD *)&dataDesc_469[36].flatGroup = 0;
    dataDesc_469[37].fieldType = FIELD_CUSTOM;
    dataDesc_469[37].fieldName = "m_ElementList";
    dataDesc_469[37].fieldOffset = 1068;
    dataDesc_469[37].fieldSize = 1;
    dataDesc_469[37].flags = 2;
    dataDesc_469[37].externalName = nullptr;
    if ( (`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>,10>::`vftable';
    }
    dataDesc_469[38].fieldType = FIELD_BOOLEAN;
    dataDesc_469[38].fieldTolerance = 0.0;
    dataDesc_469[37].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<10>::GetDataOps<CUtlVector<CAI_ScriptConditionsElement,CUtlMemory<CAI_ScriptConditionsElement,int>>>'::`2'::ops;
    dataDesc_469[37].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_469[37].td = 0;
    *(_QWORD *)&dataDesc_469[37].override_field = 0;
    *(_QWORD *)&dataDesc_469[37].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_469[37].flatOffset[1] = 0;
    dataDesc_469[38].fieldName = "m_bLeaveAsleep";
    dataDesc_469[38].fieldOffset = 929;
    dataDesc_469[38].fieldSize = 1;
    dataDesc_469[38].flags = 2;
    dataDesc_469[38].externalName = nullptr;
    dataDesc_469[38].pSaveRestoreOps = nullptr;
    dataDesc_469[38].inputFunc = nullptr;
    dataDesc_469[38].td = nullptr;
    dataDesc_469[38].fieldSizeInBytes = 1;
    dataDesc_469[38].override_field = nullptr;
    dataDesc_469[38].override_count = 0;
    *(_QWORD *)dataDesc_469[38].flatOffset = 0;
    *(_DWORD *)&dataDesc_469[38].flatGroup = 0;
  }
  CAI_ScriptConditions::m_DataMap.dataNumFields = 38;
  CAI_ScriptConditions::m_DataMap.dataDesc = &dataDesc_469[1];
  return &CAI_ScriptConditions::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10085450
// Name: struct datamap_t __near * DataMapInit<class CAI_ProxTester>(class CAI_ProxTester __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ProxTester>()
{
  if ( (_S3_15 & 1) == 0 )
  {
    _S3_15 |= 1u;
    nameHolder_63.m_pszBase = "CAI_ProxTester";
    nameHolder_63.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_63.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_63.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_63.m_Names.m_Size = 0;
    nameHolder_63.m_Names.m_pElements = nullptr;
    nameHolder_63.m_nLenBase = 14;
    atexit(func: DataMapInit_CAI_ProxTester__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ProxTester::m_DataMap.baseMap = nullptr;
  CAI_ProxTester::m_DataMap.dataNumFields = 2;
  CAI_ProxTester::m_DataMap.dataDesc = &dataDesc_60[1];
  return &CAI_ProxTester::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100854D0
// Name: struct datamap_t __near * DataMapInit<class CAI_ScriptConditionsElement>(class CAI_ScriptConditionsElement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_ScriptConditionsElement>()
{
  if ( (_S4_7 & 1) == 0 )
  {
    _S4_7 |= 1u;
    nameHolder_64.m_pszBase = "CAI_ScriptConditionsElement";
    nameHolder_64.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_64.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_64.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_64.m_Names.m_Size = 0;
    nameHolder_64.m_Names.m_pElements = nullptr;
    nameHolder_64.m_nLenBase = 27;
    atexit(func: DataMapInit_CAI_ScriptConditionsElement__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_ScriptConditionsElement::m_DataMap.baseMap = nullptr;
  CAI_ScriptConditionsElement::m_DataMap.dataNumFields = 3;
  CAI_ScriptConditionsElement::m_DataMap.dataDesc = &dataDesc_61[1];
  return &CAI_ScriptConditionsElement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FEC10
// Name: _dynamic_initializer_for__CAI_ScriptConditions::gm_Evaluators__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char (__thiscall *dynamic_initializer_for__CAI_ScriptConditions::gm_Evaluators__())(CAI_ScriptConditions *this, const CAI_ScriptConditions::EvalArgs_t *args)
{
  LODWORD(CAI_ScriptConditions::gm_Evaluators[0].pfnEvaluator) = CAI_ScriptConditions::EvalActorSeePlayer;
  dword_1056C330 = (int)CAI_ScriptConditions::EvalState;
  dword_1056C340 = (int)CAI_ScriptConditions::EvalPlayerActorProximity;
  dword_1056C350 = (int)CAI_ScriptConditions::EvalPlayerTargetProximity;
  dword_1056C360 = (int)CAI_ScriptConditions::EvalActorTargetProximity;
  dword_1056C370 = (int)CAI_ScriptConditions::EvalPlayerBlockingActor;
  dword_1056C380 = (int)CAI_ScriptConditions::EvalPlayerActorLook;
  dword_1056C390 = (int)CAI_ScriptConditions::EvalPlayerTargetLook;
  dword_1056C3A0 = (int)CAI_ScriptConditions::EvalActorSeeTarget;
  dword_1056C3B0 = (int)CAI_ScriptConditions::EvalPlayerActorLOS;
  dword_1056C324 = 0;
  dword_1056C334 = 0;
  dword_1056C344 = 0;
  dword_1056C354 = 0;
  dword_1056C364 = 0;
  dword_1056C374 = 0;
  dword_1056C384 = 0;
  dword_1056C394 = 0;
  dword_1056C3A4 = 0;
  dword_1056C3B4 = 0;
  dword_1056C3C0 = (int)CAI_ScriptConditions::EvalPlayerTargetLOS;
  dword_1056C3C4 = 0;
  return CAI_ScriptConditions::EvalPlayerTargetLOS;
}

//------------------------------------------------------------------------------
// Address: 0x103FECD0
// Name: _dynamic_initializer_for__g_AI_SensedObjectsManager__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AI_SensedObjectsManager__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_AI_SensedObjectsManager__);
}
