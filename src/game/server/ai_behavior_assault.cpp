// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_behavior_assault.cpp
// Functions: 36
// ============================================================

#include "game\server\ai_behavior_assault.h"

//------------------------------------------------------------------------------
// Address: 0x100420B0
// Name: private: static int CAI_NamespaceInfos::Compare(struct AI_NamespaceAddInfo_t const __near *,struct AI_NamespaceAddInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CAI_NamespaceInfos::Compare(const AI_NamespaceAddInfo_t *pLeft, const AI_NamespaceAddInfo_t *pRight)
{
  return pLeft->localId - pRight->localId;
}

//------------------------------------------------------------------------------
// Address: 0x100420D0
// Name: public: virtual struct datamap_t __near * CRallyPoint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CRallyPoint::GetDataDescMap(CRallyPoint *this)
{
  return &CRallyPoint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100420E0
// Name: public: virtual struct datamap_t __near * CAssaultPoint::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAssaultPoint::GetDataDescMap(CAssaultPoint *this)
{
  return &CAssaultPoint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100420F0
// Name: private: virtual struct datamap_t __near * CAI_AssaultGoal::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CAI_AssaultGoal::GetDataDescMap(CAI_AssaultGoal *this)
{
  return &CAI_AssaultGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10042180
// Name: protected: class Vector CAI_Component::WorldSpaceCenter(void)const
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Component::WorldSpaceCenter(CAI_Component *this, Vector *result)
{
  const Vector *v2; // eax
  __int64 v3; // xmm0_8
  float z; // eax

  v2 = this->m_pOuter->WorldSpaceCenter(this: this->m_pOuter);
  v3 = *(_QWORD *)&v2->x;
  z = v2->z;
  *(_QWORD *)&result->x = v3;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100421B0
// Name: public: void CAssaultPoint::InputSetClearOnContact(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssaultPoint::InputSetClearOnContact(CAssaultPoint *this, inputdata_t *inputdata)
{
  this->m_bClearOnContact = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
}

//------------------------------------------------------------------------------
// Address: 0x100421E0
// Name: public: void CAssaultPoint::InputSetAllowDiversion(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssaultPoint::InputSetAllowDiversion(CAssaultPoint *this, inputdata_t *inputdata)
{
  this->m_bAllowDiversion = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
}

//------------------------------------------------------------------------------
// Address: 0x10042210
// Name: public: void CAssaultPoint::InputSetForceClear(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAssaultPoint::InputSetForceClear(CAssaultPoint *this, inputdata_t *inputdata)
{
  this->m_bInputForcedClear = inputdata->value.fieldType == FIELD_BOOLEAN && inputdata->value.bVal;
}

//------------------------------------------------------------------------------
// Address: 0x10042240
// Name: public: virtual int CRallyPoint::DrawDebugTextOverlays(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CRallyPoint::DrawDebugTextOverlays(CRallyPoint *this)
{
  int result; // eax
  int v3; // edi
  int m_sExclusivity; // eax
  unsigned int m_Index; // eax
  int v6; // edi

  result = CBaseEntity::DrawDebugTextOverlays(this);
  v3 = result;
  if ( (this->m_debugOverlays & 1) != 0 )
  {
    m_sExclusivity = this->m_sExclusivity;
    if ( m_sExclusivity == -1 )
    {
      CBaseEntity::EntityText(
        this,
        text_offset: v3,
        text: "Exclusive: Not Evaluated",
        duration: 0.0,
        r: 255,
        g: 255,
        b: 255,
        a: 255);
    }
    else if ( this->m_sExclusivity != 0 )
    {
      if ( m_sExclusivity == 1 )
        CBaseEntity::EntityText(
          this,
          text_offset: v3,
          text: "Exclusive: YES",
          duration: 0.0,
          r: 255,
          g: 255,
          b: 255,
          a: 255);
      else
        CBaseEntity::EntityText(
          this,
          text_offset: v3,
          text: "Exclusive: !?INVALID?!",
          duration: 0.0,
          r: 255,
          g: 255,
          b: 255,
          a: 255);
    }
    else
    {
      CBaseEntity::EntityText(
        this,
        text_offset: v3,
        text: "Exclusive: NO",
        duration: 0.0,
        r: 255,
        g: 255,
        b: 255,
        a: 255);
    }
    m_Index = this->m_hLockedBy.m_Index;
    v6 = v3 + 1;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      CBaseEntity::EntityText(this, text_offset: v6, text: "LOCKED.", duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      return v6 + 1;
    }
    else
    {
      CBaseEntity::EntityText(this, text_offset: v6, text: "Available", duration: 0.0, r: 255, g: 255, b: 255, a: 255);
      return v6 + 1;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042340
// Name: public: virtual class Vector CBaseEntity::GetAutoAimCenter(void)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CBaseEntity::GetAutoAimCenter(CBaseEntity *this, Vector *result)
{
  const Vector *v2; // eax
  __int64 v3; // xmm0_8
  float z; // eax

  v2 = this->WorldSpaceCenter(this);
  v3 = *(_QWORD *)&v2->x;
  z = v2->z;
  *(_QWORD *)&result->x = v3;
  result->z = z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042370
// Name: public: bool CRallyPoint::Lock(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRallyPoint::Lock(CRallyPoint *this, CBaseEntity *pLocker)
{
  unsigned int m_Index; // eax

  m_Index = this->m_hLockedBy.m_Index;
  if ( m_Index != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
  {
    return 0;
  }
  if ( pLocker != nullptr )
    this->m_hLockedBy.m_Index = pLocker->GetRefEHandle(this: pLocker)->m_Index;
  else
    this->m_hLockedBy.m_Index = -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100423E0
// Name: public: bool CRallyPoint::Unlock(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CRallyPoint::Unlock(CRallyPoint *this, CBaseEntity *pUnlocker)
{
  unsigned int m_Index; // edx
  int v3; // eax
  CEntInfo *v4; // esi
  unsigned int v5; // edx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  CBaseEntity *v9; // eax

  m_Index = this->m_hLockedBy.m_Index;
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
      v9 = v7 ? (CBaseEntity *)v8->m_pEntity : nullptr;
      if ( v9 != pUnlocker )
        return 0;
    }
  }
  this->m_hLockedBy.m_Index = -1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10042490
// Name: public: void CAI_AssaultBehavior::ClearSchedule(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AssaultBehavior::ClearSchedule(CAI_AssaultBehavior *this, const char *szReason)
{
  CAI_BaseNPC *m_pOuter; // ecx

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iClassname.pszValue != "npc_monk"
     && CBaseEntity::ClassMatchesComplex(this: m_pOuter, pszClassOrWildcard: "npc_monk") == 0
     || this->m_pOuter->m_NPCState != NPC_STATE_SCRIPT)
    && !this->m_pOuter->IsInAVehicle(this: this->m_pOuter) )
  {
    CAI_BaseNPC::ClearSchedule(this: this->m_pOuter, szReason);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100424E0
// Name: public: void CAI_Behavior<class CAI_BaseNPC,100000>::SetCondition(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Behavior<CAI_BaseNPC,100000>::SetCondition(CAI_Behavior<CAI_BaseNPC,100000> *this, int condition)
{
  int v2; // esi
  CAI_ClassScheduleIdSpace *v4; // eax

  v2 = condition;
  if ( (unsigned int)(condition - 100000) <= 0x270F )
  {
    v4 = this->GetClassScheduleIdSpace(this);
    v2 = CAI_LocalIdSpace::LocalToGlobal(this: &v4->m_ConditionIds, localID: condition);
  }
  CAI_BaseNPC::SetCondition(this: this->m_pOuter, iCondition: v2);
}

//------------------------------------------------------------------------------
// Address: 0x10042640
// Name: public: class CAI_BaseNPC __near * CAI_GoalEntity::GetActor(int)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_GoalEntity::GetActor(CAI_GoalEntity *this, int iActor)
{
  unsigned int m_flags; // eax
  unsigned int m_Index; // eax

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
  if ( this->m_actors.m_Size <= iActor )
    return nullptr;
  m_Index = this->m_actors.m_Memory.m_pMemory[iActor].m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x100426F0
// Name: public: void CAI_AssaultBehavior::UnlockRallyPoint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AssaultBehavior::UnlockRallyPoint(CAI_AssaultBehavior *this)
{
  unsigned int m_Index; // eax
  unsigned int v3; // eax
  CAI_BaseNPC *m_pOuter; // edi
  CAI_AssaultBehavior *pBehavior; // [esp+4h] [ebp-4h] BYREF

  if ( CAI_BaseNPC::GetBehavior<CAI_AssaultBehavior>(this: this->m_pOuter, ppBehavior: &pBehavior) )
  {
    m_Index = pBehavior->m_hRallyPoint.m_Index;
    if ( m_Index != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
    {
      v3 = pBehavior->m_hRallyPoint.m_Index;
      m_pOuter = this->m_pOuter;
      if ( v3 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber != HIWORD(v3) )
        CRallyPoint::Unlock(this: nullptr, pUnlocker: m_pOuter);
      else
        CRallyPoint::Unlock(
          this: (CRallyPoint *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_pEntity,
          pUnlocker: m_pOuter);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042780
// Name: private: virtual void CAI_AssaultGoal::DisableGoal(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AssaultGoal::DisableGoal(CAI_AssaultGoal *this, CAI_BaseNPC *pAI)
{
  CAI_BaseNPC *v2; // esi
  CAI_BaseNPC *v3; // ecx
  CBaseEntity *m_pfnMoveDone; // ecx

  if ( CAI_BaseNPC::GetBehavior<CAI_AssaultBehavior>(this: pAI, ppBehavior: (CAI_AssaultBehavior **)&pAI) )
  {
    v2 = pAI;
    v3 = pAI;
    *(_DWORD *)&pAI->m_Network.m_PVSInfo.m_pClustersInline[2] = 0;
    LOWORD(v3->m_Network.m_hParent.m_Index) = 0;
    CAI_AssaultBehavior::UnlockRallyPoint(this: (CAI_AssaultBehavior *)v3);
    m_pfnMoveDone = (CBaseEntity *)v2->m_pfnMoveDone;
    if ( (m_pfnMoveDone->m_iClassname.pszValue != "npc_monk"
       && CBaseEntity::ClassMatchesComplex(this: m_pfnMoveDone, pszClassOrWildcard: "npc_monk") == 0
       || *((_DWORD *)v2->m_pfnMoveDone + 630) != 4)
      && (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)v2->m_pfnMoveDone + 1260))(a1: v2->m_pfnMoveDone) == 0 )
    {
      CAI_BaseNPC::ClearSchedule(this: (CAI_BaseNPC *)v2->m_pfnMoveDone, szReason: "Assault goal disabled");
    }
    v2->m_Network.m_TimerEvent.m_pCallback = (IEventRegisterCallback *)-1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042800
// Name: private: void CAI_AssaultGoal::InputBeginAssault(struct inputdata_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AssaultGoal::InputBeginAssault(CAI_AssaultGoal *this, inputdata_t *inputdata)
{
  int i; // edi
  unsigned int m_flags; // eax
  unsigned int v5; // eax
  unsigned int m_Index; // eax
  CAI_BaseNPC *m_pEntity; // ecx
  CAI_AssaultBehavior *v8; // ecx
  CAI_BaseNPC *m_pOuter; // eax
  CAI_AssaultBehavior *pBehavior; // [esp+8h] [ebp-4h] BYREF

  for ( i = 0; ; ++i )
  {
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
    if ( i >= this->m_actors.m_Size )
      break;
    v5 = this->m_flags;
    if ( (v5 & 1) != 0 && (v5 & 2) != 0 )
    {
      CAI_GoalEntity::PruneActors(this);
    }
    else
    {
      this->ResolveNames(this);
      this->m_flags |= 2u;
    }
    if ( this->m_actors.m_Size > i )
    {
      m_Index = this->m_actors.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index != -1 && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index) )
      {
        m_pEntity = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
        if ( m_pEntity != nullptr
          && CAI_BaseNPC::GetBehavior<CAI_AssaultBehavior>(this: m_pEntity, ppBehavior: &pBehavior) )
        {
          v8 = pBehavior;
          m_pOuter = pBehavior->m_pOuter;
          if ( m_pOuter != nullptr )
          {
            m_pOuter->m_flNextDecisionTime = 0.0;
            m_pOuter->m_Efficiency = AIE_NORMAL;
          }
          v8->m_ReceivedAssaultCue = CUE_ENTITY_INPUT;
          CAI_BaseNPC::SetCondition(this: v8->m_pOuter, iCondition: 25);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100429A0
// Name: public: CAI_GoalEntity::CAI_GoalEntity(void)
// Source: json
//------------------------------------------------------------------------------
CAI_GoalEntity *__thiscall CAI_GoalEntity::CAI_GoalEntity(CAI_GoalEntity *this)
{
  CBaseEntity::CBaseEntity(this, bServerOnly: false);
  this->IEntityListener::__vftable = (IEntityListener_vtbl *)&IEntityListener::`vftable';
  this->m_iszActor.pszValue = nullptr;
  this->m_iszGoal.pszValue = nullptr;
  this->m_fStartActive = false;
  this->m_SearchType = ST_ENTNAME;
  this->m_iszConceptModifiers.pszValue = nullptr;
  this->CBaseEntity::IServerEntity::IServerUnknown::IHandleEntity::__vftable = (CAI_GoalEntity_vtbl *)&CAI_GoalEntity::`vftable'{for `CBaseEntity'};
  this->IEntityListener::__vftable = (IEntityListener_vtbl *)&CAI_GoalEntity::`vftable'{for `IEntityListener'};
  this->m_actors.m_Memory.m_pMemory = nullptr;
  this->m_actors.m_Memory.m_nAllocationCount = 0;
  this->m_actors.m_Memory.m_nGrowSize = 0;
  this->m_actors.m_Size = 0;
  this->m_actors.m_pElements = nullptr;
  this->m_hGoalEntity.m_Index = -1;
  this->m_flags = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10042A40
// Name: public: class CAssaultPoint __near * CAI_AssaultBehavior::FindAssaultPoint(struct string_t)
// Source: json
//------------------------------------------------------------------------------
CAssaultPoint *__thiscall CAI_AssaultBehavior::FindAssaultPoint(
        CAI_AssaultBehavior *this,
        string_t iszAssaultPointName)
{
  const char *v2; // eax
  int m_Size; // edi
  CBaseEntity *EntityByName; // ebx
  const char *v5; // eax
  int v6; // edx
  const char *v7; // ecx
  const char *v8; // eax
  const char *DebugName; // eax
  int v10; // esi
  CAssaultPoint **v11; // eax
  const char *v12; // eax
  CAssaultPoint *v14; // esi
  const IHandleEntity *m_pfnMoveDone; // edi
  CAssaultPoint *v16; // ebx
  const Vector *v17; // esi
  int v18; // esi
  int v19; // edi
  CAssaultPoint **v20; // edi
  int v21; // eax
  CAssaultPoint **m_pMemory; // ecx
  int v23; // esi
  float m_flTimeLastUsed; // xmm1_4
  int v25; // ecx
  int j; // eax
  CAssaultPoint *v27; // edi
  CAssaultPoint *v28; // ebx
  IEventRegisterCallback *m_pCallback; // ecx
  CBaseEntityList *v30; // edi
  int v31; // eax
  CEntInfo *v32; // edx
  unsigned int v33; // ecx
  int v34; // eax
  bool v35; // zf
  CEntInfo *v36; // eax
  IHandleEntity *v37; // eax
  void (__thiscall *v38)(CBaseEntity *); // esi
  int v39; // ecx
  IEventRegisterCallback *v40; // eax
  float v41; // edx
  IHandleEntity *m_pEntity; // ecx
  int v43; // esi
  CAssaultPoint **v44; // eax
  CAssaultPoint *v45; // edi
  int v46; // xmm0_4
  CAssaultPoint *v47; // edi
  int v48; // xmm0_4
  const char *v49; // [esp-4h] [ebp-A4h]
  CGameTrace tr; // [esp+Ch] [ebp-94h] BYREF
  Vector vStart; // [esp+60h] [ebp-40h]
  char pszValue[4]; // [esp+6Ch] [ebp-34h] BYREF
  CUtlVector<CAssaultPoint *,CUtlMemory<CAssaultPoint *,int> > pAssaultPoints; // [esp+70h] [ebp-30h] BYREF
  CAssaultPoint *pBest; // [esp+84h] [ebp-1Ch]
  CUtlVector<CAssaultPoint *,CUtlMemory<CAssaultPoint *,int> > pClearAssaultPoints; // [esp+88h] [ebp-18h] BYREF
  int i; // [esp+9Ch] [ebp-4h] BYREF
  IHandleEntity savedregs; // [esp+A0h] [ebp+0h] BYREF

  v2 = iszAssaultPointName.pszValue;
  m_Size = 0;
  pBest = (CAssaultPoint *)this;
  memset(&pAssaultPoints, 0, sizeof(pAssaultPoints));
  memset(&pClearAssaultPoints, 0, sizeof(pClearAssaultPoints));
  if ( iszAssaultPointName.pszValue == nullptr )
    v2 = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: v2,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  if ( EntityByName != nullptr )
  {
    do
    {
      v5 = g_AssaultPointString.m_iszString.pszValue;
      v6 = CGameString::gm_iSerialNumber;
      if ( g_AssaultPointString.m_iszString.pszValue == nullptr
        || g_AssaultPointString.m_iSerial != CGameString::gm_iSerialNumber )
      {
        if ( g_AssaultPointString.m_pszString != nullptr )
        {
          v5 = *(const char **)AllocPooledString(pszValue).pszValue;
          v6 = CGameString::gm_iSerialNumber;
          g_AssaultPointString.m_iszString.pszValue = v5;
          g_AssaultPointString.m_iSerial = CGameString::gm_iSerialNumber;
        }
        else
        {
          v5 = nullptr;
        }
      }
      if ( v5 == EntityByName->m_iClassname.pszValue )
      {
        v10 = m_Size;
        if ( m_Size + 1 > pAssaultPoints.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&pAssaultPoints,
            num: m_Size - pAssaultPoints.m_Memory.m_nAllocationCount + 1);
          m_Size = pAssaultPoints.m_Size;
        }
        pAssaultPoints.m_Size = ++m_Size;
        pAssaultPoints.m_pElements = pAssaultPoints.m_Memory.m_pMemory;
        if ( m_Size - v10 - 1 > 0 )
          _V_memmove(
            dest: &pAssaultPoints.m_Memory.m_pMemory[v10 + 1],
            src: &pAssaultPoints.m_Memory.m_pMemory[v10],
            count: 4 * (m_Size - v10 - 1));
        v11 = &pAssaultPoints.m_Memory.m_pMemory[v10];
        if ( v11 != nullptr )
          *v11 = (CAssaultPoint *)EntityByName;
      }
      else
      {
        v7 = g_RallyPointString.m_iszString.pszValue;
        if ( g_RallyPointString.m_iszString.pszValue == nullptr || g_RallyPointString.m_iSerial != v6 )
        {
          if ( g_RallyPointString.m_pszString != nullptr )
          {
            v7 = *(const char **)AllocPooledString(pszValue: (const char *)&i).pszValue;
            g_RallyPointString.m_iszString.pszValue = v7;
            g_RallyPointString.m_iSerial = CGameString::gm_iSerialNumber;
          }
          else
          {
            v7 = nullptr;
          }
        }
        v8 = EntityByName->m_iClassname.pszValue;
        if ( v8 != v7 )
        {
          if ( v8 == nullptr )
            v8 = locale;
          v49 = v8;
          DebugName = CBaseEntity::GetDebugName(this: EntityByName);
          DevMsg(
            a1: "**ERROR: Entity %s being used as an assault_assaultpoint, but is actually a %s!\n",
            DebugName,
            v49);
        }
      }
      v12 = iszAssaultPointName.pszValue;
      if ( iszAssaultPointName.pszValue == nullptr )
        v12 = locale;
      EntityByName = CGlobalEntityList::FindEntityByName(
                       this: &gEntList,
                       pStartEntity: EntityByName,
                       szName: v12,
                       pSearchingEntity: nullptr,
                       pActivator: nullptr,
                       pCaller: nullptr,
                       pFilter: nullptr);
    }
    while ( EntityByName != nullptr );
    if ( m_Size >= 1 )
    {
      if ( m_Size == 1 )
      {
        v14 = *pAssaultPoints.m_Memory.m_pMemory;
LABEL_95:
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pClearAssaultPoints);
        CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pAssaultPoints);
        return v14;
      }
      *(float *)&i = 0.0;
      do
      {
        m_pfnMoveDone = (const IHandleEntity *)pBest->m_pfnMoveDone;
        v16 = pAssaultPoints.m_Memory.m_pMemory[i];
        *(_DWORD *)pszValue = m_pfnMoveDone[57].GetRefEHandle(this: (IHandleEntity *)&m_pfnMoveDone[57]);
        v17 = (const Vector *)((int (__thiscall *)(const IHandleEntity *))m_pfnMoveDone[57].SetRefEHandle)(a1: &m_pfnMoveDone[57]);
        if ( (v16->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v16, a2: (int)&savedregs);
        if ( (v16->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v16, a2: (int)&savedregs);
        UTIL_TraceHull(
          a1: &savedregs,
          a2: (int)v17,
          vecAbsStart: &v16->m_vecAbsOrigin,
          vecAbsEnd: &v16->m_vecAbsOrigin,
          hullMin: v17,
          hullMax: *(const Vector **)pszValue,
          mask: 0x200400Bu,
          ignore: m_pfnMoveDone,
          collisionGroup: 0,
          ptr: &tr);
        v18 = pClearAssaultPoints.m_Size;
        if ( tr.fraction == 1.0 )
        {
          v19 = pClearAssaultPoints.m_Size;
          if ( pClearAssaultPoints.m_Size + 1 > pClearAssaultPoints.m_Memory.m_nAllocationCount )
          {
            CUtlMemory<CNavLadder *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)&pClearAssaultPoints,
              num: pClearAssaultPoints.m_Size - pClearAssaultPoints.m_Memory.m_nAllocationCount + 1);
            v18 = pClearAssaultPoints.m_Size;
          }
          ++v18;
          pClearAssaultPoints.m_pElements = pClearAssaultPoints.m_Memory.m_pMemory;
          pClearAssaultPoints.m_Size = v18;
          if ( v18 - v19 - 1 > 0 )
            _V_memmove(
              dest: &pClearAssaultPoints.m_Memory.m_pMemory[v19 + 1],
              src: &pClearAssaultPoints.m_Memory.m_pMemory[v19],
              count: 4 * (v18 - v19 - 1));
          v20 = &pClearAssaultPoints.m_Memory.m_pMemory[v19];
          if ( v20 != nullptr )
            *v20 = v16;
        }
        ++i;
      }
      while ( i < pAssaultPoints.m_Size );
      if ( v18 == 1 )
      {
        v14 = *pClearAssaultPoints.m_Memory.m_pMemory;
        goto LABEL_95;
      }
      if ( v18 < 1 )
      {
        v21 = random->RandomInt(this: random, a2: 0, a3: pAssaultPoints.m_Size - 1);
        m_pMemory = pAssaultPoints.m_Memory.m_pMemory;
LABEL_94:
        v14 = m_pMemory[v21];
        goto LABEL_95;
      }
      v23 = pClearAssaultPoints.m_Size;
      m_flTimeLastUsed = -1.0;
      v25 = -1;
      for ( j = 0; j < pClearAssaultPoints.m_Size; ++j )
      {
        v27 = pClearAssaultPoints.m_Memory.m_pMemory[j];
        if ( v27->m_flTimeLastUsed > m_flTimeLastUsed )
        {
          m_flTimeLastUsed = v27->m_flTimeLastUsed;
          v25 = j;
        }
      }
      if ( pClearAssaultPoints.m_Size - v25 - 1 > 0 )
        _V_memmove(
          dest: &pClearAssaultPoints.m_Memory.m_pMemory[v25],
          src: &pClearAssaultPoints.m_Memory.m_pMemory[v25 + 1],
          count: 4 * (pClearAssaultPoints.m_Size - v25 - 1));
      v28 = pBest;
      m_pCallback = pBest->m_Network.m_TimerEvent.m_pCallback;
      pClearAssaultPoints.m_Size = v23 - 1;
      if ( m_pCallback != (IEventRegisterCallback *)-1 )
      {
        v30 = g_pEntityList;
        v31 = (unsigned __int16)m_pCallback;
        v32 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_pCallback];
        v33 = (unsigned int)m_pCallback >> 16;
        if ( v32->m_SerialNumber == v33 && v32->m_pEntity != nullptr )
        {
          v34 = v31;
          v35 = g_pEntityList->m_EntPtrArray[v34].m_SerialNumber == v33;
          v36 = &g_pEntityList->m_EntPtrArray[v34];
          v37 = v35 ? v36->m_pEntity : nullptr;
          if ( v37[229].__vftable != nullptr )
          {
            v38 = pBest->m_pfnMoveDone;
            v39 = *((_DWORD *)v38 + 49) >> 11;
            pBest = nullptr;
            if ( (v39 & 1) != 0 )
            {
              CBaseEntity::CalcAbsolutePosition(this: (CBaseEntity *)v38, a2: (int)&savedregs);
              v30 = g_pEntityList;
            }
            v40 = v28->m_Network.m_TimerEvent.m_pCallback;
            v41 = *((float *)v38 + 117);
            *(_QWORD *)&vStart.x = *(_QWORD *)((char *)v38 + 460);
            vStart.z = v41;
            if ( v40 == (IEventRegisterCallback *)-1
              || v30->m_EntPtrArray[(unsigned __int16)v40].m_SerialNumber != (unsigned int)v40 >> 16 )
            {
              m_pEntity = nullptr;
            }
            else
            {
              m_pEntity = v30->m_EntPtrArray[(unsigned __int16)v40].m_pEntity;
            }
            v43 = 0;
            if ( m_pEntity[229].__vftable == (IHandleEntity_vtbl *)1 )
            {
              *(float *)&i = 3.4028235e38;
              if ( pClearAssaultPoints.m_Size > 0 )
              {
                v44 = pClearAssaultPoints.m_Memory.m_pMemory;
                do
                {
                  v45 = v44[v43];
                  if ( (v45->m_iEFlags & 0x800) != 0 )
                  {
                    CBaseEntity::CalcAbsolutePosition(this: v44[v43], a2: (int)&savedregs);
                    v44 = pClearAssaultPoints.m_Memory.m_pMemory;
                  }
                  *(float *)&v46 = (float)((float)((float)(v45->m_vecAbsOrigin.y - vStart.y)
                                                 * (float)(v45->m_vecAbsOrigin.y - vStart.y))
                                         + (float)((float)(v45->m_vecAbsOrigin.x - vStart.x)
                                                 * (float)(v45->m_vecAbsOrigin.x - vStart.x)))
                                 + (float)((float)(v45->m_vecAbsOrigin.z - vStart.z)
                                         * (float)(v45->m_vecAbsOrigin.z - vStart.z));
                  if ( *(float *)&i > *(float *)&v46 )
                  {
                    pBest = v44[v43];
                    i = v46;
                  }
                  ++v43;
                }
                while ( v43 < pClearAssaultPoints.m_Size );
                goto LABEL_86;
              }
            }
            else
            {
              *(float *)&i = 0.0;
              if ( pClearAssaultPoints.m_Size > 0 )
              {
                v44 = pClearAssaultPoints.m_Memory.m_pMemory;
                do
                {
                  v47 = v44[v43];
                  if ( (v47->m_iEFlags & 0x800) != 0 )
                  {
                    CBaseEntity::CalcAbsolutePosition(this: v44[v43], a2: (int)&savedregs);
                    v44 = pClearAssaultPoints.m_Memory.m_pMemory;
                  }
                  *(float *)&v48 = (float)((float)((float)(v47->m_vecAbsOrigin.y - vStart.y)
                                                 * (float)(v47->m_vecAbsOrigin.y - vStart.y))
                                         + (float)((float)(v47->m_vecAbsOrigin.x - vStart.x)
                                                 * (float)(v47->m_vecAbsOrigin.x - vStart.x)))
                                 + (float)((float)(v47->m_vecAbsOrigin.z - vStart.z)
                                         * (float)(v47->m_vecAbsOrigin.z - vStart.z));
                  if ( *(float *)&v48 > *(float *)&i )
                  {
                    pBest = v44[v43];
                    i = v48;
                  }
                  ++v43;
                }
                while ( v43 < pClearAssaultPoints.m_Size );
                goto LABEL_86;
              }
            }
            v44 = pClearAssaultPoints.m_Memory.m_pMemory;
LABEL_86:
            if ( pClearAssaultPoints.m_Memory.m_nGrowSize >= 0 && v44 != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pClearAssaultPoints.m_Memory.m_pMemory);
            if ( pAssaultPoints.m_Memory.m_nGrowSize >= 0 && pAssaultPoints.m_Memory.m_pMemory != nullptr )
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: pAssaultPoints.m_Memory.m_pMemory);
            return pBest;
          }
        }
      }
      v21 = random->RandomInt(this: random, a2: 0, a3: pClearAssaultPoints.m_Size - 1);
      m_pMemory = pClearAssaultPoints.m_Memory.m_pMemory;
      goto LABEL_94;
    }
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pClearAssaultPoints);
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&pAssaultPoints);
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10042FE0
// Name: public: void CAI_AssaultBehavior::InitializeBehavior(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AssaultBehavior::InitializeBehavior(CAI_AssaultBehavior *this)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // ecx
  CAssaultPoint *AssaultPoint; // eax
  CAssaultPoint *v5; // edi
  CAI_BaseNPC *m_pOuter; // ecx
  unsigned int v7; // eax
  IHandleEntity *v8; // ecx
  const char *v9; // eax
  CAI_BaseNPC *v10; // ecx

  *(_WORD *)&this->m_bHitRallyPoint = 0;
  this->m_hAssaultPoint.m_Index = -1;
  this->m_bDiverting = false;
  this->m_flLastSawAnEnemyAt = 0.0;
  this->m_ReceivedAssaultCue = CUE_NO_ASSAULT;
  m_Index = this->m_hRallyPoint.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  AssaultPoint = CAI_AssaultBehavior::FindAssaultPoint(this, iszAssaultPointName: (string_t)m_pEntity[213].__vftable);
  v5 = AssaultPoint;
  if ( AssaultPoint != nullptr )
  {
    this->m_hAssaultPoint.m_Index = AssaultPoint->GetRefEHandle(this: AssaultPoint)->m_Index;
    v5->m_flTimeLastUsed = gpGlobals->curtime;
    m_pOuter = this->m_pOuter;
    if ( (m_pOuter->m_iClassname.pszValue != "npc_monk"
       && CBaseEntity::ClassMatchesComplex(this: m_pOuter, pszClassOrWildcard: "npc_monk") == 0
       || this->m_pOuter->m_NPCState != NPC_STATE_SCRIPT)
      && !this->m_pOuter->IsInAVehicle(this: this->m_pOuter) )
    {
      CAI_BaseNPC::ClearSchedule(this: this->m_pOuter, szReason: "Initializing assault behavior");
    }
  }
  else
  {
    v7 = this->m_hRallyPoint.m_Index;
    if ( v7 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      v8 = nullptr;
    else
      v8 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
    v9 = (const char *)v8[213].__vftable;
    if ( v9 == nullptr )
      v9 = locale;
    DevMsg(a1: "**ERROR: Can't find any assault points named: %s\n", v9);
    v10 = this->m_pOuter;
    this->m_AssaultCue = CUE_NO_ASSAULT;
    if ( (v10->m_iClassname.pszValue != "npc_monk"
       && CBaseEntity::ClassMatchesComplex(this: v10, pszClassOrWildcard: "npc_monk") == 0
       || this->m_pOuter->m_NPCState != NPC_STATE_SCRIPT)
      && !this->m_pOuter->IsInAVehicle(this: this->m_pOuter) )
    {
      CAI_BaseNPC::ClearSchedule(this: this->m_pOuter, szReason: "Can't find assault point");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100433C0
// Name: public: void CAI_AssaultBehavior::SetParameters(struct string_t,enum AssaultCue_t,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AssaultBehavior::SetParameters(
        CAI_AssaultBehavior *this,
        string_t rallypointname,
        AssaultCue_t assaultcue,
        int rallySelectMethod)
{
  CAI_AssaultBehavior *v4; // edi
  const char *pszValue; // eax
  CBaseEntity *EntityByName; // eax
  CRallyPoint *v7; // esi
  int m_nAllocationCount; // edx
  int v9; // ebx
  int m_Size; // ebx
  unsigned int v11; // eax
  int v12; // edi
  CRallyPoint **v13; // edi
  const char *v14; // eax
  CBaseEntity *v15; // eax
  int v16; // eax
  unsigned int m_Index; // eax
  int m_iPriority; // eax
  CAI_BaseNPC *m_pOuter; // edi
  vgui::CTreeViewListControl::CColumnInfo *z_low; // ecx
  unsigned int v21; // edx
  unsigned int v22; // eax
  float v23; // xmm1_4
  float v24; // xmm0_4
  const char *v25; // eax
  CBaseEntity *v26; // eax
  CRallyPoint *v27; // esi
  const char *v28; // eax
  unsigned int v29; // eax
  const char *v30; // eax
  CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > v31; // [esp+Ch] [ebp-20h] BYREF
  float flNewDist; // [esp+20h] [ebp-Ch]
  CAI_AssaultBehavior *v33; // [esp+24h] [ebp-8h]
  CRallyPoint *pBest; // [esp+28h] [ebp-4h]
  int savedregs; // [esp+2Ch] [ebp+0h] BYREF

  v4 = this;
  v33 = this;
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CAI_AssaultBehavior::SetParameters",
    a3: 0,
    a4: "NPCs",
    a5: false,
    a6: 4);
  CAI_AssaultBehavior::UnlockRallyPoint(this: v4);
  pszValue = rallypointname.pszValue;
  if ( rallypointname.pszValue == nullptr )
    pszValue = locale;
  EntityByName = CGlobalEntityList::FindEntityByName(
                   this: &gEntList,
                   pStartEntity: nullptr,
                   szName: pszValue,
                   pSearchingEntity: nullptr,
                   pActivator: nullptr,
                   pCaller: nullptr,
                   pFilter: nullptr);
  v7 = (CRallyPoint *)__RTDynamicCast(
                        inptr: EntityByName,
                        VfDelta: 0,
                        SrcType: &CBaseEntity `RTTI Type Descriptor',
                        TargetType: &CRallyPoint `RTTI Type Descriptor',
                        isReference: 0);
  m_nAllocationCount = 0;
  v9 = -1;
  pBest = nullptr;
  if ( rallySelectMethod == 0 )
  {
LABEL_26:
    if ( v7 == nullptr )
      goto LABEL_48;
    while ( 1 )
    {
      m_Index = v7->m_hLockedBy.m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        goto LABEL_44;
      }
      m_iPriority = v7->m_iPriority;
      if ( m_iPriority > v9 )
        break;
      if ( m_iPriority == v9 )
      {
        m_pOuter = v4->m_pOuter;
        if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2: (int)&savedregs);
        z_low = (vgui::CTreeViewListControl::CColumnInfo *)LODWORD(m_pOuter->m_vecAbsOrigin.z);
        v21 = (unsigned int)v7->m_iEFlags >> 11;
        *(_QWORD *)&v31.m_Memory.m_nGrowSize = *(_QWORD *)&m_pOuter->m_vecAbsOrigin.x;
        v31.m_pElements = z_low;
        if ( (v21 & 1) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v7, a2: (int)&savedregs);
        v22 = (unsigned int)pBest->m_iEFlags >> 11;
        v23 = (float)((float)((float)(v7->m_vecAbsOrigin.y - *(float *)&v31.m_Size)
                            * (float)(v7->m_vecAbsOrigin.y - *(float *)&v31.m_Size))
                    + (float)((float)(v7->m_vecAbsOrigin.x - *(float *)&v31.m_Memory.m_nGrowSize)
                            * (float)(v7->m_vecAbsOrigin.x - *(float *)&v31.m_Memory.m_nGrowSize)))
            + (float)((float)(v7->m_vecAbsOrigin.z - *(float *)&v31.m_pElements)
                    * (float)(v7->m_vecAbsOrigin.z - *(float *)&v31.m_pElements));
        flNewDist = v23;
        if ( (v22 & 1) != 0 )
        {
          CBaseEntity::CalcAbsolutePosition(this: pBest, a2: (int)&savedregs);
          v23 = flNewDist;
        }
        v24 = (float)((float)((float)(pBest->m_vecAbsOrigin.y - *(float *)&v31.m_Size)
                            * (float)(pBest->m_vecAbsOrigin.y - *(float *)&v31.m_Size))
                    + (float)((float)(pBest->m_vecAbsOrigin.x - *(float *)&v31.m_Memory.m_nGrowSize)
                            * (float)(pBest->m_vecAbsOrigin.x - *(float *)&v31.m_Memory.m_nGrowSize)))
            + (float)((float)(pBest->m_vecAbsOrigin.z - *(float *)&v31.m_pElements)
                    * (float)(pBest->m_vecAbsOrigin.z - *(float *)&v31.m_pElements));
        if ( rallySelectMethod == 0 )
        {
          if ( v24 <= v23 )
            goto LABEL_44;
          goto LABEL_43;
        }
        if ( v23 > v24 )
          goto LABEL_43;
      }
LABEL_44:
      v25 = rallypointname.pszValue;
      if ( rallypointname.pszValue == nullptr )
        v25 = locale;
      v26 = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: v7,
              szName: v25,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr);
      v4 = v33;
      v7 = (CRallyPoint *)__RTDynamicCast(
                            inptr: v26,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CRallyPoint `RTTI Type Descriptor',
                            isReference: 0);
      if ( v7 == nullptr )
        goto LABEL_47;
    }
    v9 = v7->m_iPriority;
LABEL_43:
    pBest = v7;
    goto LABEL_44;
  }
  if ( rallySelectMethod != 1 )
  {
    if ( rallySelectMethod != 2 )
    {
      DevMsg(a1: "ERROR: INVALID RALLY POINT SELECTION METHOD. Assault will not function.\n");
LABEL_48:
      v28 = v4->m_pOuter->m_iName.m_Value.pszValue;
      if ( v28 == nullptr )
        v28 = locale;
      DevMsg(a1: "%s Didn't find a best rally point!\n", v28);
      goto LABEL_60;
    }
    goto LABEL_26;
  }
  m_Size = 0;
  memset(&v31, 0, sizeof(v31));
  if ( v7 != nullptr )
  {
    while ( 1 )
    {
      v11 = v7->m_hLockedBy.m_Index;
      if ( v11 == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity == nullptr )
      {
        v12 = m_Size;
        if ( m_Size + 1 > m_nAllocationCount )
        {
          CUtlMemory<CNavLadder *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v31,
            num: m_Size - m_nAllocationCount + 1);
          m_Size = v31.m_Size;
        }
        v31.m_Size = ++m_Size;
        v31.m_pElements = v31.m_Memory.m_pMemory;
        if ( m_Size - v12 - 1 > 0 )
          _V_memmove(
            dest: &v31.m_Memory.m_pMemory->m_Width + v12,
            src: (char *)v31.m_Memory.m_pMemory + 4 * v12,
            count: 4 * (m_Size - v12 - 1));
        v13 = (CRallyPoint **)((char *)v31.m_Memory.m_pMemory + 4 * v12);
        if ( v13 != nullptr )
          *v13 = v7;
      }
      v14 = rallypointname.pszValue;
      if ( rallypointname.pszValue == nullptr )
        v14 = locale;
      v15 = CGlobalEntityList::FindEntityByName(
              this: &gEntList,
              pStartEntity: v7,
              szName: v14,
              pSearchingEntity: nullptr,
              pActivator: nullptr,
              pCaller: nullptr,
              pFilter: nullptr);
      v7 = (CRallyPoint *)__RTDynamicCast(
                            inptr: v15,
                            VfDelta: 0,
                            SrcType: &CBaseEntity `RTTI Type Descriptor',
                            TargetType: &CRallyPoint `RTTI Type Descriptor',
                            isReference: 0);
      if ( v7 == nullptr )
        break;
      m_nAllocationCount = v31.m_Memory.m_nAllocationCount;
    }
    if ( m_Size > 0 )
    {
      v16 = random->RandomInt(this: random, a2: 0, a3: m_Size - 1);
      pBest = *((CRallyPoint **)&v31.m_Memory.m_pMemory->m_Title.m_Id + v16);
    }
    v4 = v33;
  }
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: &v31);
LABEL_47:
  v27 = pBest;
  if ( pBest == nullptr )
    goto LABEL_48;
  if ( pBest->m_bShouldLock )
    CRallyPoint::Lock(this: pBest, pLocker: v4->m_pOuter);
  v29 = v27->GetRefEHandle(this: v27)->m_Index;
  v4->m_hRallyPoint.m_Index = v29;
  if ( v29 != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_SerialNumber == HIWORD(v29)
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v29].m_pEntity != nullptr )
  {
    v4->m_AssaultCue = assaultcue;
    CAI_AssaultBehavior::InitializeBehavior(this: v4);
  }
  else
  {
    v30 = rallypointname.pszValue;
    if ( rallypointname.pszValue == nullptr )
      v30 = locale;
    DevMsg(a1: "**ERROR: Can't find a rally point named '%s'\n", v30);
    v4->m_AssaultCue = CUE_NO_ASSAULT;
    CAI_AssaultBehavior::ClearSchedule(this: v4, szReason: "Can't find rally point");
  }
LABEL_60:
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10043840
// Name: private: virtual void CAI_AssaultGoal::EnableGoal(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_AssaultGoal::EnableGoal(CAI_AssaultGoal *this, CAI_AssaultBehavior *pAI)
{
  CAI_AssaultBehavior *v3; // edi

  if ( CAI_BaseNPC::GetBehavior<CAI_AssaultBehavior>(this: (CAI_BaseNPC *)pAI, ppBehavior: &pAI) )
  {
    v3 = pAI;
    if ( this != nullptr )
      v3->m_hGoal.m_Index = this->GetRefEHandle(this)->m_Index;
    else
      pAI->m_hGoal.m_Index = -1;
    CAI_AssaultBehavior::SetParameters(
      this: v3,
      rallypointname: this->m_RallyPoint,
      assaultcue: (AssaultCue_t)this->m_AssaultCue,
      rallySelectMethod: this->m_RallySelectMethod);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100EE230
// Name: protected: class Vector const __near & CAI_Component::GetAbsOrigin(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__usercall CAI_Component::GetAbsOrigin@<eax>(CAI_Component *this@<ecx>, int a2@<ebp>)
{
  CAI_BaseNPC *m_pOuter; // esi

  m_pOuter = this->m_pOuter;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2);
  return &m_pOuter->m_vecAbsOrigin;
}

//------------------------------------------------------------------------------
// Address: 0x103FB500
// Name: CRallyPoint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CRallyPoint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CRallyPoint>(__formal: nullptr);
  CRallyPoint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB510
// Name: CAssaultPoint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAssaultPoint_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAssaultPoint>(__formal: nullptr);
  CAssaultPoint_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB520
// Name: _dynamic_initializer_for__assault_rallypoint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__assault_rallypoint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CRallyPoint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &assault_rallypoint,
           a3: "assault_rallypoint");
}

//------------------------------------------------------------------------------
// Address: 0x103FB540
// Name: _dynamic_initializer_for__assault_assaultpoint__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__assault_assaultpoint__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAssaultPoint> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &assault_assaultpoint,
           a3: "assault_assaultpoint");
}

//------------------------------------------------------------------------------
// Address: 0x103FB560
// Name: CAI_AssaultBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_AssaultBehavior_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_AssaultBehavior>(__formal: nullptr);
  CAI_AssaultBehavior_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FB570
// Name: CAI_AssaultGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_AssaultGoal_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_AssaultGoal>(__formal: nullptr);
  CAI_AssaultGoal_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043140
// Name: struct datamap_t __near * DataMapInit<class CRallyPoint>(class CRallyPoint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CRallyPoint>()
{
  if ( (_S2_6 & 1) == 0 )
  {
    _S2_6 |= 1u;
    nameHolder_16.m_pszBase = "CRallyPoint";
    nameHolder_16.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_16.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_16.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_16.m_Names.m_Size = 0;
    nameHolder_16.m_Names.m_pElements = nullptr;
    nameHolder_16.m_nLenBase = 11;
    atexit(func: DataMapInit_CRallyPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CRallyPoint::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S2_6 & 2) == 0 )
  {
    _S2_6 |= 2u;
    dataDesc_16[11].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_16[11].inputFunc = 0;
    *(_QWORD *)&dataDesc_16[11].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_16[11].override_count = 0;
    *(_QWORD *)dataDesc_16[11].flatOffset = 0;
    *(_DWORD *)&dataDesc_16[11].flatGroup = 0;
  }
  CRallyPoint::m_DataMap.dataNumFields = 11;
  CRallyPoint::m_DataMap.dataDesc = &dataDesc_16[1];
  return &CRallyPoint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10043210
// Name: struct datamap_t __near * DataMapInit<class CAssaultPoint>(class CAssaultPoint __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAssaultPoint>()
{
  if ( (_S3_3 & 1) == 0 )
  {
    _S3_3 |= 1u;
    nameHolder_17.m_pszBase = "CAssaultPoint";
    nameHolder_17.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_17.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_17.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_17.m_Names.m_Size = 0;
    nameHolder_17.m_Names.m_pElements = nullptr;
    nameHolder_17.m_nLenBase = 13;
    atexit(func: DataMapInit_CAssaultPoint__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAssaultPoint::m_DataMap.baseMap = &CBaseEntity::m_DataMap;
  if ( (_S3_3 & 2) == 0 )
  {
    _S3_3 |= 2u;
    *(_QWORD *)&dataDesc_17[17].inputFunc = 0;
    *(_QWORD *)&dataDesc_17[17].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_17[17].override_count = 0;
    *(_QWORD *)dataDesc_17[17].flatOffset = 0;
    dataDesc_17[17].pSaveRestoreOps = eventFuncs;
    *(_DWORD *)&dataDesc_17[17].flatGroup = 0;
    dataDesc_17[18].fieldType = FIELD_CUSTOM;
    dataDesc_17[18].fieldName = "m_OnAssaultClear";
    dataDesc_17[18].fieldOffset = 860;
    *(_DWORD *)&dataDesc_17[18].fieldSize = 1441793;
    dataDesc_17[18].externalName = "OnAssaultClear";
    dataDesc_17[18].pSaveRestoreOps = eventFuncs;
    *(_QWORD *)&dataDesc_17[18].inputFunc = 0;
    *(_QWORD *)&dataDesc_17[18].fieldSizeInBytes = 0;
    *(_QWORD *)&dataDesc_17[18].override_count = 0;
    *(_QWORD *)dataDesc_17[18].flatOffset = 0;
    *(_DWORD *)&dataDesc_17[18].flatGroup = 0;
  }
  CAssaultPoint::m_DataMap.dataNumFields = 18;
  CAssaultPoint::m_DataMap.dataDesc = &dataDesc_17[1];
  return &CAssaultPoint::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10043340
// Name: struct datamap_t __near * DataMapInit<class CAI_AssaultBehavior>(class CAI_AssaultBehavior __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_AssaultBehavior>()
{
  if ( (_S4_1 & 1) == 0 )
  {
    _S4_1 |= 1u;
    nameHolder_18.m_pszBase = "CAI_AssaultBehavior";
    nameHolder_18.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_18.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_18.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_18.m_Names.m_Size = 0;
    nameHolder_18.m_Names.m_pElements = nullptr;
    nameHolder_18.m_nLenBase = 19;
    atexit(func: DataMapInit_CAI_AssaultBehavior__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_AssaultBehavior::m_DataMap.baseMap = &CAI_BehaviorBase::m_DataMap;
  CAI_AssaultBehavior::m_DataMap.dataNumFields = 11;
  CAI_AssaultBehavior::m_DataMap.dataDesc = &dataDesc_18[1];
  return &CAI_AssaultBehavior::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x100437C0
// Name: struct datamap_t __near * DataMapInit<class CAI_AssaultGoal>(class CAI_AssaultGoal __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_AssaultGoal>()
{
  if ( (_S5_1 & 1) == 0 )
  {
    _S5_1 |= 1u;
    nameHolder_19.m_pszBase = "CAI_AssaultGoal";
    nameHolder_19.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_19.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_19.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_19.m_Names.m_Size = 0;
    nameHolder_19.m_Names.m_pElements = nullptr;
    nameHolder_19.m_nLenBase = 15;
    atexit(func: DataMapInit_CAI_AssaultGoal__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_AssaultGoal::m_DataMap.baseMap = &CAI_GoalEntity::m_DataMap;
  CAI_AssaultGoal::m_DataMap.dataNumFields = 5;
  CAI_AssaultGoal::m_DataMap.dataDesc = &dataDesc_19[1];
  return &CAI_AssaultGoal::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FB580
// Name: _dynamic_initializer_for__ai_goal_assault__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_goal_assault__()
{
  IEntityFactoryDictionary *v0; // eax

  v0 = EntityFactoryDictionary();
  return ((int (__thiscall *)(IEntityFactoryDictionary *, CEntityFactory<CAI_AssaultGoal> *, const char *))v0->InstallFactory)(
           a1: v0,
           a2: &ai_goal_assault,
           a3: "ai_goal_assault");
}

//------------------------------------------------------------------------------
// Address: 0x103FB5A0
// Name: _dynamic_initializer_for__CAI_AssaultBehavior::gm_ClassScheduleIdSpace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CAI_LocalIdSpace *dynamic_initializer_for__CAI_AssaultBehavior::gm_ClassScheduleIdSpace__()
{
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_AssaultBehavior::gm_ClassScheduleIdSpace.m_ScheduleIds, fIsRoot: false);
  CAI_LocalIdSpace::CAI_LocalIdSpace(this: &CAI_AssaultBehavior::gm_ClassScheduleIdSpace.m_TaskIds, fIsRoot: false);
  return CAI_LocalIdSpace::CAI_LocalIdSpace(
           this: &CAI_AssaultBehavior::gm_ClassScheduleIdSpace.m_ConditionIds,
           fIsRoot: false);
}
