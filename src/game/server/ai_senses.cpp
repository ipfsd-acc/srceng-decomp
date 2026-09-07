// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_senses.cpp
// Functions: 28
// ============================================================

#include "game\server\ai_senses.h"

//------------------------------------------------------------------------------
// Address: 0x10085750
// Name: public: float CAI_Senses::GetTimeLastUpdate(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
double __thiscall CAI_Senses::GetTimeLastUpdate(CAI_Senses *this, CBaseEntity *pEntity)
{
  if ( pEntity == nullptr )
    return 0.0;
  if ( pEntity->IsPlayer(this: pEntity) )
    return this->m_TimeLastLookHighPriority;
  if ( pEntity->IsNPC(this: pEntity) )
    return this->m_TimeLastLookNPCs;
  return this->m_TimeLastLookMisc;
}

//------------------------------------------------------------------------------
// Address: 0x100857B0
// Name: public: class CSound __near * CAI_Senses::GetFirstHeardSound(struct AISoundIter_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CSound *__thiscall CAI_Senses::GetFirstHeardSound(CAI_Senses *this, AISoundIter_t__ **pIter)
{
  AISoundIter_t__ *m_iAudibleList; // eax

  m_iAudibleList = (AISoundIter_t__ *)this->m_iAudibleList;
  if ( m_iAudibleList == (AISoundIter_t__ *)-1 )
  {
    *pIter = (AISoundIter_t__ *)-1;
    return nullptr;
  }
  else
  {
    *pIter = m_iAudibleList;
    return CSoundEnt::SoundPointerForIndex(iIndex: (int)m_iAudibleList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100857E0
// Name: public: class CSound __near * CAI_Senses::GetNextHeardSound(struct AISoundIter_t__ __near * __near *)
// Source: json
//------------------------------------------------------------------------------
CSound *__thiscall CAI_Senses::GetNextHeardSound(CAI_Senses *this, AISoundIter_t__ **pIter)
{
  AISoundIter_t__ *m_iNextAudible; // eax

  if ( *pIter == (AISoundIter_t__ *)-1 )
  {
    *pIter = (AISoundIter_t__ *)-1;
    return nullptr;
  }
  m_iNextAudible = (AISoundIter_t__ *)CSoundEnt::SoundPointerForIndex(iIndex: (int)*pIter)->m_iNextAudible;
  *pIter = m_iNextAudible;
  if ( m_iNextAudible == (AISoundIter_t__ *)-1 )
    return nullptr;
  return CSoundEnt::SoundPointerForIndex(iIndex: (int)m_iNextAudible);
}

//------------------------------------------------------------------------------
// Address: 0x10085820
// Name: public: void CAI_SensedObjectsManager::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SensedObjectsManager::Init(CAI_SensedObjectsManager *this)
{
  CBaseEntity *i; // esi

  for ( i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: nullptr);
        i != nullptr;
        i = CGlobalEntityList::NextEnt(this: &gEntList, pCurrentEnt: i) )
  {
    this->OnEntitySpawned(this, a2: i);
  }
  CGlobalEntityList::AddListenerEntity(this: &gEntList, pListener: this);
}

//------------------------------------------------------------------------------
// Address: 0x10085860
// Name: public: bool CAI_Senses::CanHearSound(class CSound __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Senses::CanHearSound(CAI_Senses *this, CSound *pSound)
{
  unsigned int m_Index; // eax
  IHandleEntity *m_pEntity; // eax
  CAI_BaseNPC *m_pOuter; // ecx
  Vector *v7; // esi
  const Vector *SoundOrigin; // eax
  bool result; // al
  _BYTE v10[12]; // [esp+8h] [ebp-Ch] BYREF
  int flHearDistanceSq; // [esp+1Ch] [ebp+8h]
  float flHearDistanceSqa; // [esp+1Ch] [ebp+8h]

  m_Index = pSound->m_hOwner.m_Index;
  if ( pSound->m_hOwner.m_Index == -1
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
  {
    m_pEntity = nullptr;
  }
  else
  {
    m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  }
  m_pOuter = this->m_pOuter;
  result = m_pEntity != m_pOuter
        && (m_pOuter->m_NPCState != NPC_STATE_SCRIPT || (pSound->m_iType & 8) == 0)
        && !m_pOuter->m_bInAScript
        && (flHearDistanceSq = pSound->m_iVolume,
            flHearDistanceSqa = ((double (__thiscall *)(CAI_BaseNPC *))m_pOuter->HearingSensitivity)(a1: m_pOuter)
                              * (double)flHearDistanceSq,
            v7 = this->m_pOuter->EarPosition(this: this->m_pOuter, result: v10),
            SoundOrigin = CSound::GetSoundOrigin(this: pSound),
            (float)(flHearDistanceSqa * flHearDistanceSqa) >= (float)((float)((float)((float)(SoundOrigin->y - v7->y)
                                                                                    * (float)(SoundOrigin->y - v7->y))
                                                                            + (float)((float)(SoundOrigin->x - v7->x)
                                                                                    * (float)(SoundOrigin->x - v7->x)))
                                                                    + (float)((float)(SoundOrigin->z - v7->z)
                                                                            * (float)(SoundOrigin->z - v7->z))))
        && this->m_pOuter->QueryHearSound(this: this->m_pOuter, a2: pSound);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10085960
// Name: public: bool CAI_Senses::CanSeeEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CAI_Senses::CanSeeEntity(CAI_Senses *this, CBaseEntity *pSightEnt)
{
  return this->m_pOuter->FInViewCone(this: this->m_pOuter, a2: pSightEnt)
      && this->m_pOuter->FVisible_2(this: this->m_pOuter, a2: pSightEnt, a3: 16449, a4: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100859B0
// Name: protected: bool CAI_Senses::SeeEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Senses::SeeEntity(CAI_Senses *this, CBaseEntity *pSightEnt)
{
  this->m_pOuter->OnSeeEntity(this: this->m_pOuter, a2: pSightEnt);
  pSightEnt->m_pLink = this->m_pOuter->m_pLink;
  this->m_pOuter->m_pLink = pSightEnt;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100859F0
// Name: public: class CSound __near * CAI_Senses::GetClosestSound(bool,int,bool)
// Source: json
//------------------------------------------------------------------------------
CSound *__userpurge CAI_Senses::GetClosestSound@<eax>(
        CAI_Senses *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        int a4@<esi>,
        bool fScent,
        int validTypes,
        bool bUsePriority)
{
  int m_iAudibleList; // eax
  CSound *v9; // esi
  int m_iNextAudible; // ebx
  int v11; // eax
  const Vector *SoundOrigin; // eax
  float v13; // xmm0_4
  CAI_BaseNPC *m_pOuter; // ecx
  int (__thiscall *GetSoundPriority)(CAI_BaseNPC *, CSound *); // eax
  CSound *v16; // eax
  Vector earPosition; // [esp+0h] [ebp-18h] BYREF
  int iBestPriority; // [esp+Ch] [ebp-Ch]
  float flBestDist; // [esp+10h] [ebp-8h]
  CSound *pResult; // [esp+14h] [ebp-4h]

  m_iAudibleList = this->m_iAudibleList;
  v9 = nullptr;
  flBestDist = 268435460.0;
  iBestPriority = -2;
  pResult = nullptr;
  if ( m_iAudibleList == -1 )
  {
    m_iNextAudible = -1;
  }
  else
  {
    m_iNextAudible = m_iAudibleList;
    v9 = CSoundEnt::SoundPointerForIndex(iIndex: m_iAudibleList);
  }
  ((void (__thiscall *)(CAI_BaseNPC *, Vector *, int, int, int))this->m_pOuter->EarPosition)(
    a1: this->m_pOuter,
    a2: &earPosition,
    a3,
    a4,
    a5: a2);
  if ( v9 != nullptr )
  {
    while ( 1 )
    {
      if ( fScent )
      {
        if ( CSound::FIsScent(this: v9) )
        {
LABEL_9:
          if ( (validTypes & v9->m_iType) != 0
            && !this->m_pOuter->ShouldIgnoreSound(this: this->m_pOuter, a2: v9)
            && (!bUsePriority || (v11 = this->m_pOuter->GetSoundPriority(this: this->m_pOuter, a2: v9)) >= iBestPriority) )
          {
            SoundOrigin = CSound::GetSoundOrigin(this: v9);
            v13 = (float)((float)((float)(SoundOrigin->x - earPosition.x) * (float)(SoundOrigin->x - earPosition.x))
                        + (float)((float)(SoundOrigin->y - earPosition.y) * (float)(SoundOrigin->y - earPosition.y)))
                + (float)((float)(SoundOrigin->z - earPosition.z) * (float)(SoundOrigin->z - earPosition.z));
            if ( flBestDist > v13 )
            {
              m_pOuter = this->m_pOuter;
              GetSoundPriority = m_pOuter->GetSoundPriority;
              pResult = v9;
              flBestDist = v13;
              iBestPriority = GetSoundPriority(this: m_pOuter, a2: v9);
            }
          }
        }
      }
      else if ( CSound::FIsSound(this: v9) )
      {
        goto LABEL_9;
      }
      if ( m_iNextAudible != -1 )
      {
        v16 = CSoundEnt::SoundPointerForIndex(iIndex: m_iNextAudible);
        m_iNextAudible = v16->m_iNextAudible;
        if ( m_iNextAudible != -1 )
        {
          v9 = CSoundEnt::SoundPointerForIndex(iIndex: v16->m_iNextAudible);
          if ( v9 != nullptr )
            continue;
        }
      }
      return pResult;
    }
  }
  return pResult;
}

//------------------------------------------------------------------------------
// Address: 0x10085B30
// Name: public: void CAI_Senses::Listen(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Senses::Listen(CAI_Senses *this)
{
  CAI_BaseNPC *m_pOuter; // ecx
  int i; // ebx
  CSound *v4; // eax
  CSound *v5; // esi
  int iSoundMask; // [esp+4h] [ebp-4h]

  m_pOuter = this->m_pOuter;
  this->m_iAudibleList = -1;
  iSoundMask = m_pOuter->GetSoundInterests(this: m_pOuter);
  if ( iSoundMask != 0 && (this->m_pOuter->m_spawnflags.m_Value & 1) == 0 )
  {
    for ( i = CSoundEnt::ActiveList(); i != -1; i = v5->m_iNext )
    {
      v4 = CSoundEnt::SoundPointerForIndex(iIndex: i);
      v5 = v4;
      if ( v4 != nullptr && (iSoundMask & v4->m_iType) != 0 && CAI_Senses::CanHearSound(this, pSound: v4) )
      {
        v5->m_iNextAudible = this->m_iAudibleList;
        this->m_iAudibleList = i;
      }
    }
  }
  this->m_pOuter->OnListened(this: this->m_pOuter);
}

//------------------------------------------------------------------------------
// Address: 0x10085BC0
// Name: public: bool CAI_Senses::ShouldSeeEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Senses::ShouldSeeEntity(CAI_Senses *this, CAI_BaseNPC *pSightEnt)
{
  CAI_BaseNPC *m_pOuter; // ecx

  m_pOuter = this->m_pOuter;
  return pSightEnt != m_pOuter
      && (!m_pOuter->OnlySeeAliveEntities(this: m_pOuter) || pSightEnt->IsAlive(this: pSightEnt))
      && (!pSightEnt->IsPlayer(this: pSightEnt) || (pSightEnt->m_fFlags.m_Value & 0x10000) == 0)
      && (pSightEnt->m_spawnflags.m_Value & 1) == 0
      && pSightEnt->CanBeSeenBy(this: pSightEnt, a2: this->m_pOuter)
      && this->m_pOuter->QuerySeeEntity(this: this->m_pOuter, a2: pSightEnt, a3: true);
}

//------------------------------------------------------------------------------
// Address: 0x10085C50
// Name: public: class CBaseEntity __near * CAI_Senses::GetFirstSeenEntity(struct AISightIter_t__ __near * __near *,enum seentype_t)const
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_Senses::GetFirstSeenEntity(CAI_Senses *this, AISightIter_t__ **pIter, seentype_t iSeenType)
{
  seentype_t v3; // eax
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > **v4; // edx
  unsigned int m_Index; // eax

  v3 = iSeenType != SEEN_ALL ? iSeenType : SEEN_HIGH_PRIORITY;
  *((_BYTE *)pIter + 3) = iSeenType;
  if ( (unsigned int)v3 >= (SEEN_MISC|SEEN_NPCS) )
  {
LABEL_5:
    *pIter = (AISightIter_t__ *)-1;
    return nullptr;
  }
  v4 = &this->m_SeenArrays[v3];
  while ( (*v4)->m_Size == 0 )
  {
    ++v3;
    ++v4;
    if ( (unsigned int)v3 >= (SEEN_MISC|SEEN_NPCS) )
      goto LABEL_5;
  }
  *(_BYTE *)pIter = v3;
  *(_WORD *)((char *)pIter + 1) = 1;
  m_Index = this->m_SeenArrays[v3]->m_Memory.m_pMemory->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10085CD0
// Name: public: class CBaseEntity __near * CAI_Senses::GetNextSeenEntity(struct AISightIter_t__ __near * __near *)const
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CAI_Senses::GetNextSeenEntity(CAI_Senses *this, AISightIter_t__ **pIter)
{
  AISightIter_t__ **v2; // edx
  unsigned int v3; // edi
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > **v4; // ecx
  int v5; // esi
  int m_Size; // ebx
  CHandle<CBaseEntity> *v7; // edi
  unsigned int m_Index; // eax
  bool v9; // zf
  unsigned int v11; // eax
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > **v13; // [esp+10h] [ebp-8h]
  int i; // [esp+14h] [ebp-4h]

  v2 = pIter;
  if ( *pIter == (AISightIter_t__ *)-1 )
    return nullptr;
  v3 = *(char *)pIter;
  i = v3;
  if ( v3 >= 3 )
  {
LABEL_14:
    *v2 = (AISightIter_t__ *)-1;
    return nullptr;
  }
  v4 = &this->m_SeenArrays[v3];
  v13 = v4;
  while ( 1 )
  {
    v5 = *(__int16 *)((char *)v2 + 1);
    m_Size = (*v4)->m_Size;
    if ( v5 < m_Size )
      break;
LABEL_12:
    v9 = *((_BYTE *)v2 + 3) == 0xFF;
    *(_WORD *)((char *)v2 + 1) = 0;
    if ( v9 )
    {
      ++v3;
      v4 = v13 + 1;
      i = v3;
      ++v13;
      if ( v3 < 3 )
        continue;
    }
    goto LABEL_14;
  }
  v7 = &(*v4)->m_Memory.m_pMemory[v5];
  while ( 1 )
  {
    m_Index = v7->m_Index;
    if ( v7->m_Index != -1 )
      break;
LABEL_10:
    ++v5;
    ++v7;
    if ( v5 >= m_Size )
    {
      v3 = i;
      goto LABEL_12;
    }
  }
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
    || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
  {
    v2 = pIter;
    goto LABEL_10;
  }
  *(_BYTE *)pIter = i;
  *(_WORD *)((char *)pIter + 1) = v5 + 1;
  v11 = this->m_SeenArrays[i]->m_Memory.m_pMemory[v5].m_Index;
  if ( v11 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
    return nullptr;
  return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10085DD0
// Name: public: bool CAI_Senses::DidSeeEntity(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Senses::DidSeeEntity(CAI_Senses *this, CBaseEntity *pSightEnt)
{
  int v3; // eax
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > **i; // ecx
  unsigned int m_Index; // eax
  CBaseEntity *m_pEntity; // eax
  AISightIter_t__ *iter; // [esp+8h] [ebp-4h] BYREF

  iter = (AISightIter_t__ *)-1;
  v3 = 0;
  for ( i = this->m_SeenArrays; (*i)->m_Size == 0; ++i )
  {
    if ( (unsigned int)++v3 >= 3 )
      return 0;
  }
  LOBYTE(iter) = v3;
  m_Index = this->m_SeenArrays[v3]->m_Memory.m_pMemory->m_Index;
  *(_WORD *)((char *)&iter + 1) = 1;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity == nullptr )
    return 0;
  while ( pSightEnt != m_pEntity )
  {
    m_pEntity = CAI_Senses::GetNextSeenEntity(this, pIter: &iter);
    if ( m_pEntity == nullptr )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10085E70
// Name: public: void CAI_SensedObjectsManager::Term(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SensedObjectsManager::Term(CAI_SensedObjectsManager *this)
{
  CGlobalEntityList::RemoveListenerEntity(this: &gEntList, pListener: this);
  this->m_SensedObjects.m_Size = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10085E90
// Name: private: virtual void CAI_SensedObjectsManager::OnEntityDeleted(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SensedObjectsManager::OnEntityDeleted(CAI_SensedObjectsManager *this, CBaseEntity *pEntity)
{
  CBaseEntity *v2; // esi
  int v4; // eax

  v2 = pEntity;
  if ( (pEntity->m_fFlags.m_Value & 0x4000000) != 0 && !pEntity->IsPlayer(this: pEntity) && !v2->IsNPC(this: v2) )
  {
    pEntity = (CBaseEntity *)v2->GetRefEHandle(this: v2)->m_Index;
    v4 = CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
           this: &this->m_SensedObjects,
           src: (CHandle<CBaseEntity> *)&pEntity);
    if ( v4 != -1 )
      CUtlVector<CNavArea *,CUtlMemory<CNavArea *,int>>::FastRemove(this: &this->m_SensedObjects, elem: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10085F00
// Name: protected: virtual bool CAI_Senses::WaitingUntilSeen(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Senses::WaitingUntilSeen(CAI_Senses *this, CBaseEntity *pSightEnt)
{
  CBaseEntity *v3; // ecx
  CAI_BaseNPC *m_pOuter; // esi
  unsigned int v5; // edi
  CBaseEdict *v7; // ecx
  Vector zero; // [esp+10h] [ebp-Ch] BYREF

  if ( (this->m_pOuter->m_spawnflags.m_Value & 1) == 0 )
    return 0;
  if ( !pSightEnt->IsPlayer(this: pSightEnt) )
    return 1;
  v3 = pSightEnt->IsPlayer(this: pSightEnt) ? pSightEnt : nullptr;
  memset((void *)&zero, 0, sizeof(zero));
  if ( v3 == nullptr
    || ((unsigned __int8 (__thiscall *)(CBaseEntity *, CAI_BaseNPC *))v3->__vftable[1].RequiredEdictIndex)(
         a1: v3,
         a2: this->m_pOuter) == 0
    || !FBoxVisible(pLooker: pSightEnt, pTarget: this->m_pOuter, vecTargetOrigin: &zero, flSize: 0.0) )
  {
    return 1;
  }
  m_pOuter = this->m_pOuter;
  v5 = m_pOuter->m_spawnflags.m_Value & 0xFFFFFFFE;
  if ( m_pOuter->m_spawnflags.m_Value != v5 )
  {
    if ( m_pOuter->m_Network.m_TimerEvent.m_bRegistered )
    {
      *((_BYTE *)&m_pOuter->m_Network + 76) |= 1u;
      m_pOuter->m_spawnflags.m_Value = v5;
      return 0;
    }
    v7 = &m_pOuter->m_Network.m_pPev->CBaseEdict;
    if ( v7 != nullptr )
      CBaseEdict::StateChanged(this: v7, offset: 0x2F8u);
    m_pOuter->m_spawnflags.m_Value = v5;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10086000
// Name: private: virtual void CAI_SensedObjectsManager::OnEntitySpawned(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SensedObjectsManager::OnEntitySpawned(CAI_SensedObjectsManager *this, CBaseEntity *pEntity)
{
  unsigned int m_Index; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_SensedObjects; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v8; // eax
  unsigned int *v9; // eax

  if ( (pEntity->m_fFlags.m_Value & 0x4000000) != 0
    && !pEntity->IsPlayer(this: pEntity)
    && !pEntity->IsNPC(this: pEntity) )
  {
    m_Index = pEntity->GetRefEHandle(this: pEntity)->m_Index;
    m_nAllocationCount = this->m_SensedObjects.m_Memory.m_nAllocationCount;
    p_m_SensedObjects = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SensedObjects;
    m_Size = this->m_SensedObjects.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(this: p_m_SensedObjects, num: m_Size - m_nAllocationCount + 1);
    ++p_m_SensedObjects[1].m_pMemory;
    m_pMemory = p_m_SensedObjects->m_pMemory;
    v8 = (int)p_m_SensedObjects[1].m_pMemory - m_Size - 1;
    p_m_SensedObjects[1].m_nAllocationCount = (int)p_m_SensedObjects->m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = (unsigned int *)&p_m_SensedObjects->m_pMemory[m_Size];
    if ( v9 != nullptr )
      *v9 = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100860A0
// Name: public: virtual void CAI_SensedObjectsManager::AddEntity(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SensedObjectsManager::AddEntity(CAI_SensedObjectsManager *this, unsigned int pEntity)
{
  CBaseEntity *v2; // edi
  int m_Index; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHandle<CBaseEntity> *m_pMemory; // ecx
  int v8; // eax
  CHandle<CBaseEntity> *v9; // eax

  v2 = (CBaseEntity *)pEntity;
  m_Index = -1;
  if ( pEntity != 0 )
    pEntity = *(_DWORD *)(*(int (__thiscall **)(unsigned int))(*(_DWORD *)pEntity + 8))(a1: pEntity);
  else
    pEntity = -1;
  if ( CUtlVector<CHandle<CSceneEntity>,CUtlMemory<CHandle<CSceneEntity>,int>>::Find(
         this: &this->m_SensedObjects,
         src: (CHandle<CBaseEntity> *)&pEntity) == -1 )
  {
    CBaseEntity::AddFlag(this: v2, flags: 0x4000000);
    if ( v2 != nullptr )
      m_Index = v2->GetRefEHandle(this: v2)->m_Index;
    m_Size = this->m_SensedObjects.m_Size;
    m_nAllocationCount = this->m_SensedObjects.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CNavLadder *,int>::Grow(
        this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_SensedObjects,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_SensedObjects.m_Size;
    m_pMemory = this->m_SensedObjects.m_Memory.m_pMemory;
    v8 = this->m_SensedObjects.m_Size - m_Size - 1;
    this->m_SensedObjects.m_pElements = m_pMemory;
    if ( v8 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
    v9 = &this->m_SensedObjects.m_Memory.m_pMemory[m_Size];
    if ( v9 != nullptr )
      v9->m_Index = m_Index;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086480
// Name: protected: void CAI_Senses::EndGather(int,class CUtlVector<class CHandle<class CBaseEntity>,class CUtlMemory<class CHandle<class CBaseEntity>,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Senses::EndGather(
        CAI_Senses *this,
        int nSeen,
        CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *pResult)
{
  CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int> > *v3; // ebx
  CBaseEntity *m_pLink; // esi
  int v6; // edi
  CHandle<CBaseEntity> *v7; // ebx

  v3 = pResult;
  pResult->m_Size = 0;
  CUtlVector<CHandle<CFish>,CUtlMemory<CHandle<CFish>,int>>::InsertMultipleBefore(
    this: (CUtlVector<vgui::PHandle,CUtlMemory<vgui::PHandle,int> > *)pResult,
    elem: 0,
    num: nSeen);
  if ( nSeen != 0 )
  {
    m_pLink = this->m_pOuter->m_pLink;
    v6 = 0;
    if ( nSeen > 0 )
    {
      while ( 1 )
      {
        v7 = &v3->m_Memory.m_pMemory[v6];
        if ( m_pLink != nullptr )
          v7->m_Index = m_pLink->GetRefEHandle(this: m_pLink)->m_Index;
        else
          v7->m_Index = -1;
        m_pLink = m_pLink->m_pLink;
        if ( ++v6 >= nSeen )
          break;
        v3 = pResult;
      }
    }
    this->m_pOuter->m_pLink = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086510
// Name: protected: virtual int CAI_Senses::LookForHighPriorityEntities(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Senses::LookForHighPriorityEntities(CAI_Senses *this, int iDistance)
{
  CAI_BaseNPC *m_pOuter; // edx
  CAI_BaseNPC *v4; // edi
  int v5; // ebx
  CBasePlayer *v6; // eax
  CAI_BaseNPC *v7; // edi
  int i; // edi
  unsigned int m_Index; // eax
  int m_Size; // ecx
  const Vector *origin; // [esp+10h] [ebp-8h]
  int nSeen; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  nSeen = 0;
  if ( (float)(gpGlobals->curtime - this->m_TimeLastLookHighPriority) <= 0.15000001 )
  {
    for ( i = this->m_SeenHighPriority.m_Size - 1; i >= 0; --i )
    {
      m_Index = this->m_SeenHighPriority.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        m_Size = this->m_SeenHighPriority.m_Size;
        if ( m_Size > 0 )
        {
          if ( i != m_Size - 1 )
            this->m_SeenHighPriority.m_Memory.m_pMemory[i].m_Index = this->m_SeenHighPriority.m_Memory.m_pMemory[m_Size - 1].m_Index;
          --this->m_SeenHighPriority.m_Size;
        }
      }
    }
    return this->m_SeenHighPriority.m_Size;
  }
  else
  {
    m_pOuter = this->m_pOuter;
    this->m_TimeLastLookHighPriority = gpGlobals->curtime;
    m_pOuter->m_pLink = nullptr;
    v4 = this->m_pOuter;
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    v5 = 1;
    for ( origin = &v4->m_vecAbsOrigin; v5 <= gpGlobals->maxClients; ++v5 )
    {
      v6 = UTIL_PlayerByIndex(playerIndex: v5);
      v7 = (CAI_BaseNPC *)v6;
      if ( v6 != nullptr )
      {
        if ( (v6->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v6, a2: (int)&savedregs);
        if ( ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->IsWithinSenseDistance)(
               a1: this,
               a2: &v7->m_vecAbsOrigin,
               a3: origin,
               a4: (float)iDistance)
          && !this->WaitingUntilSeen(this, a2: v7)
          && CAI_Senses::ShouldSeeEntity(this, pSightEnt: v7)
          && CAI_Senses::CanSeeEntity(this, pSightEnt: v7)
          && CAI_Senses::SeeEntity(this, pSightEnt: v7) != 0 )
        {
          ++nSeen;
        }
      }
    }
    CAI_Senses::EndGather(this, nSeen, pResult: &this->m_SeenHighPriority);
    return nSeen;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086690
// Name: protected: int CAI_Senses::LookForNPCs(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Senses::LookForNPCs(CAI_Senses *this, int iDistance)
{
  CAI_BaseNPC *m_pOuter; // edi
  CAI_BaseNPC *v4; // eax
  int m_Efficiency; // ecx
  float v6; // xmm1_4
  int v7; // ebx
  CAI_BaseNPC **v8; // edi
  CAI_BaseNPC *v9; // eax
  CBaseEntity *v10; // edi
  CAI_BaseNPC *v11; // edi
  int v13; // eax
  CHandle<CBaseEntity> *m_pMemory; // edx
  int v15; // ebx
  unsigned int m_Index; // eax
  int m_Size; // ecx
  bool v18; // zf
  unsigned int v19; // eax
  IHandleEntity *m_pEntity; // ecx
  unsigned int v21; // eax
  CBaseEntity *v22; // edi
  unsigned int v23; // eax
  CAI_BaseNPC *v24; // edi
  const Vector *origin; // [esp+10h] [ebp-10h]
  CAI_BaseNPC **ppAIs; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  int ia; // [esp+18h] [ebp-8h]
  bool bRemoveStaleFromCache; // [esp+1Fh] [ebp-1h]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  m_pOuter = this->m_pOuter;
  bRemoveStaleFromCache = false;
  if ( (m_pOuter->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: m_pOuter, a2: (int)&savedregs);
  v4 = this->m_pOuter;
  m_Efficiency = v4->m_Efficiency;
  origin = &m_pOuter->m_vecAbsOrigin;
  if ( m_Efficiency >= 2 )
    v6 = 0.34999999;
  else
    v6 = 0.25;
  if ( (float)(gpGlobals->curtime - this->m_TimeLastLookNPCs) <= v6 )
  {
LABEL_24:
    v13 = this->m_SeenNPCs.m_Size - 1;
    ia = v13;
    if ( v13 < 0 )
      return this->m_SeenNPCs.m_Size;
    while ( 1 )
    {
      m_pMemory = this->m_SeenNPCs.m_Memory.m_pMemory;
      v15 = v13;
      m_Index = m_pMemory[v13].m_Index;
      if ( m_Index != -1
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
        && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
      {
        break;
      }
      m_Size = this->m_SeenNPCs.m_Size;
      if ( m_Size > 0 )
      {
        v18 = ia == m_Size - 1;
LABEL_53:
        if ( !v18 )
          this->m_SeenNPCs.m_Memory.m_pMemory[v15].m_Index = this->m_SeenNPCs.m_Memory.m_pMemory[m_Size - 1].m_Index;
        --this->m_SeenNPCs.m_Size;
      }
LABEL_56:
      v13 = --ia;
      if ( ia < 0 )
        return this->m_SeenNPCs.m_Size;
    }
    if ( !bRemoveStaleFromCache )
      goto LABEL_56;
    v19 = m_pMemory[v15].m_Index;
    if ( v19 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_SerialNumber != HIWORD(v19) )
      m_pEntity = nullptr;
    else
      m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v19].m_pEntity;
    if ( ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[140].SetRefEHandle)(a1: m_pEntity) != 0 )
      goto LABEL_50;
    v21 = this->m_SeenNPCs.m_Memory.m_pMemory[v15].m_Index;
    if ( v21 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_SerialNumber != HIWORD(v21) )
      v22 = nullptr;
    else
      v22 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v21].m_pEntity;
    if ( (v22->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v22, a2: (int)&savedregs);
    if ( ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->IsWithinSenseDistance)(
           a1: this,
           a2: origin,
           a3: &v22->m_vecAbsOrigin,
           a4: (float)iDistance) )
    {
LABEL_50:
      v23 = this->m_SeenNPCs.m_Memory.m_pMemory[v15].m_Index;
      if ( v23 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_SerialNumber != HIWORD(v23) )
        v24 = nullptr;
      else
        v24 = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v23].m_pEntity;
      if ( !this->WaitingUntilSeen(this, a2: v24)
        && CAI_Senses::ShouldSeeEntity(this, pSightEnt: v24)
        && CAI_Senses::CanSeeEntity(this, pSightEnt: v24)
        && CAI_Senses::SeeEntity(this, pSightEnt: v24) != 0 )
      {
        goto LABEL_56;
      }
    }
    m_Size = this->m_SeenNPCs.m_Size;
    if ( m_Size <= 0 )
      goto LABEL_56;
    v18 = ia == m_Size - 1;
    goto LABEL_53;
  }
  this->m_TimeLastLookNPCs = gpGlobals->curtime;
  if ( m_Efficiency >= 3 )
  {
    bRemoveStaleFromCache = true;
    goto LABEL_24;
  }
  v7 = 0;
  i = 0;
  v4->m_pLink = nullptr;
  v8 = CAI_Manager::AccessAIs(this: &g_AI_Manager);
  ppAIs = v8;
  if ( vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager) > 0 )
  {
    while ( 1 )
    {
      v9 = v8[v7];
      if ( v9 != this->m_pOuter )
      {
        if ( ((unsigned __int8 (*)(void))v9->ShouldNotDistanceCull)() != 0 )
          goto LABEL_16;
        v10 = v8[v7];
        if ( (v10->m_iEFlags & 0x800) != 0 )
          CBaseEntity::CalcAbsolutePosition(this: v10, a2: (int)&savedregs);
        if ( ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->IsWithinSenseDistance)(
               a1: this,
               a2: origin,
               a3: &v10->m_vecAbsOrigin,
               a4: (float)iDistance) )
        {
LABEL_16:
          v11 = ppAIs[v7];
          if ( !this->WaitingUntilSeen(this, a2: v11)
            && CAI_Senses::ShouldSeeEntity(this, pSightEnt: v11)
            && CAI_Senses::CanSeeEntity(this, pSightEnt: v11)
            && CAI_Senses::SeeEntity(this, pSightEnt: v11) != 0 )
          {
            ++i;
          }
        }
      }
      if ( ++v7 >= vgui::Image::GetWide(this: (vgui::Image *)&g_AI_Manager) )
        break;
      v8 = ppAIs;
    }
  }
  CAI_Senses::EndGather(this, nSeen: i, pResult: &this->m_SeenNPCs);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x100869A0
// Name: protected: int CAI_Senses::LookForObjects(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Senses::LookForObjects(CAI_Senses *this, int iDistance)
{
  float curtime; // xmm0_4
  int v4; // ebx
  CAI_BaseNPC *m_pOuter; // ecx
  CAI_BaseNPC *v6; // edi
  unsigned int v7; // eax
  int v8; // ebx
  CAI_BaseNPC *m_pEntity; // edi
  unsigned int v10; // eax
  int i; // edi
  unsigned int m_Index; // eax
  int m_Size; // ecx
  const Vector *origin; // [esp+10h] [ebp-8h]
  int nSeen; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  curtime = gpGlobals->curtime;
  v4 = 0;
  nSeen = 0;
  if ( (float)(curtime - this->m_TimeLastLookMisc) <= 0.44999999 )
  {
    for ( i = this->m_SeenMisc.m_Size - 1; i >= 0; --i )
    {
      m_Index = this->m_SeenMisc.m_Memory.m_pMemory[i].m_Index;
      if ( m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr )
      {
        m_Size = this->m_SeenMisc.m_Size;
        if ( m_Size > 0 )
        {
          if ( i != m_Size - 1 )
            this->m_SeenMisc.m_Memory.m_pMemory[i].m_Index = this->m_SeenMisc.m_Memory.m_pMemory[m_Size - 1].m_Index;
          --this->m_SeenMisc.m_Size;
        }
      }
    }
    return this->m_SeenMisc.m_Size;
  }
  else
  {
    m_pOuter = this->m_pOuter;
    this->m_TimeLastLookMisc = curtime;
    m_pOuter->m_pLink = nullptr;
    v6 = this->m_pOuter;
    if ( (v6->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: this->m_pOuter, a2: (int)&savedregs);
    origin = &v6->m_vecAbsOrigin;
    if ( g_AI_SensedObjectsManager.m_SensedObjects.m_Size != 0 )
    {
      v7 = g_AI_SensedObjectsManager.m_SensedObjects.m_Memory.m_pMemory->m_Index;
      v8 = 1;
      if ( g_AI_SensedObjectsManager.m_SensedObjects.m_Memory.m_pMemory->m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      }
      while ( m_pEntity != nullptr )
      {
        if ( (m_pEntity->m_fFlags.m_Value & 0x4000000) != 0 )
        {
          if ( (m_pEntity->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: m_pEntity, a2: (int)&savedregs);
          if ( ((int (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD))this->IsWithinSenseDistance)(
                 a1: this,
                 a2: origin,
                 a3: &m_pEntity->m_vecAbsOrigin,
                 a4: (float)iDistance)
            && !this->WaitingUntilSeen(this, a2: m_pEntity)
            && CAI_Senses::ShouldSeeEntity(this, pSightEnt: m_pEntity)
            && this->m_pOuter->FInViewCone(this: this->m_pOuter, a2: m_pEntity)
            && this->m_pOuter->FVisible_2(this: this->m_pOuter, a2: m_pEntity, a3: 16449, a4: nullptr) )
          {
            this->m_pOuter->OnSeeEntity(this: this->m_pOuter, a2: m_pEntity);
            ++nSeen;
            m_pEntity->m_pLink = this->m_pOuter->m_pLink;
            this->m_pOuter->m_pLink = m_pEntity;
          }
        }
        if ( v8 == 0 || v8 >= g_AI_SensedObjectsManager.m_SensedObjects.m_Size )
          break;
        v10 = g_AI_SensedObjectsManager.m_SensedObjects.m_Memory.m_pMemory[v8++].m_Index;
        if ( v10 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
      }
      v4 = nSeen;
    }
    CAI_Senses::EndGather(this, nSeen: v4, pResult: &this->m_SeenMisc);
    return v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10086BD0
// Name: public: void CAI_Senses::Look(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Senses::Look(CAI_Senses *this, int iDistance)
{
  if ( this->m_TimeLastLook != gpGlobals->curtime || this->m_LastLookDist != (float)iDistance )
  {
    this->LookForHighPriorityEntities(this, a2: iDistance);
    CAI_Senses::LookForNPCs(this, iDistance);
    CAI_Senses::LookForObjects(this, iDistance);
    this->m_LastLookDist = (float)iDistance;
    this->m_TimeLastLook = gpGlobals->curtime;
  }
  this->m_pOuter->OnLooked(this: this->m_pOuter, a2: iDistance);
}

//------------------------------------------------------------------------------
// Address: 0x10086C50
// Name: public: virtual void CAI_Senses::PerformSensing(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Senses::PerformSensing(CAI_Senses *this)
{
  if ( (this->m_iSensingFlags & 1) == 0 )
    CAI_Senses::Look(this, iDistance: (int)this->m_LookDist);
  if ( (this->m_iSensingFlags & 2) == 0 )
    CAI_Senses::Listen(this);
}

//------------------------------------------------------------------------------
// Address: 0x103FECE0
// Name: CAI_Senses_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Senses_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Senses>(__formal: nullptr);
  CAI_Senses_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10086150
// Name: struct datamap_t __near * DataMapInit<class CAI_Senses>(class CAI_Senses __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_Senses>()
{
  int v0; // eax

  if ( (_S2_32 & 1) == 0 )
  {
    _S2_32 |= 1u;
    nameHolder_65.m_pszBase = "CAI_Senses";
    nameHolder_65.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_65.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_65.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_65.m_Names.m_Size = 0;
    nameHolder_65.m_Names.m_pElements = nullptr;
    nameHolder_65.m_nLenBase = 10;
    atexit(func: DataMapInit_CAI_Senses__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_Senses::m_DataMap.baseMap = nullptr;
  if ( (_S2_32 & 2) == 0 )
  {
    _S2_32 |= 2u;
    v0 = `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard';
    if ( (`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
        & 1) == 0 )
    {
      v0 = `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard'
         | 1;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    dataDesc_62[6].fieldSize = 1;
    dataDesc_62[5].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_62[5].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_62[5].td = 0;
    *(_QWORD *)&dataDesc_62[5].override_field = 0;
    *(_QWORD *)&dataDesc_62[5].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_62[5].flatOffset[1] = 0;
    dataDesc_62[6].fieldType = FIELD_CUSTOM;
    dataDesc_62[6].fieldName = "m_SeenNPCs";
    dataDesc_62[6].fieldOffset = 44;
    dataDesc_62[6].flags = 2;
    dataDesc_62[6].externalName = nullptr;
    if ( (v0 & 1) == 0 )
    {
      v0 |= 1u;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' = v0;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    dataDesc_62[7].fieldType = FIELD_CUSTOM;
    dataDesc_62[7].fieldSize = 1;
    dataDesc_62[6].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_62[6].inputFunc = nullptr;
    *(_QWORD *)&dataDesc_62[6].td = 0;
    *(_QWORD *)&dataDesc_62[6].override_field = 0;
    *(_QWORD *)&dataDesc_62[6].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_62[6].flatOffset[1] = 0;
    dataDesc_62[7].fieldName = "m_SeenMisc";
    dataDesc_62[7].fieldOffset = 64;
    dataDesc_62[7].flags = 2;
    dataDesc_62[7].externalName = nullptr;
    if ( (v0 & 1) == 0 )
    {
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::`local static guard' = v0 | 1;
      `CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops = (int)&CUtlVectorDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>,13>::`vftable';
    }
    *(_QWORD *)&dataDesc_62[7].td = 0;
    *(_QWORD *)&dataDesc_62[7].override_field = 0;
    *(_QWORD *)&dataDesc_62[7].fieldTolerance = 0;
    *(_QWORD *)&dataDesc_62[7].flatOffset[1] = 0;
    dataDesc_62[7].pSaveRestoreOps = (ISaveRestoreOps *)&`CUtlVectorDataopsInstantiator<13>::GetDataOps<CUtlVector<CHandle<CBaseEntity>,CUtlMemory<CHandle<CBaseEntity>,int>>>'::`2'::ops;
    dataDesc_62[9].fieldSize = 1;
    dataDesc_62[8].fieldTolerance = 0.0;
    *(_QWORD *)dataDesc_62[8].flatOffset = 0;
    dataDesc_62[9].fieldTolerance = 0.0;
    dataDesc_62[10].fieldTolerance = 0.0;
    dataDesc_62[7].inputFunc = nullptr;
    dataDesc_62[8].fieldType = FIELD_TIME;
    dataDesc_62[8].fieldName = "m_TimeLastLookHighPriority";
    dataDesc_62[8].fieldOffset = 96;
    *(_DWORD *)&dataDesc_62[8].fieldSize = 131073;
    dataDesc_62[8].externalName = nullptr;
    dataDesc_62[8].pSaveRestoreOps = nullptr;
    dataDesc_62[8].inputFunc = nullptr;
    dataDesc_62[8].td = nullptr;
    dataDesc_62[8].fieldSizeInBytes = 4;
    dataDesc_62[8].override_field = nullptr;
    dataDesc_62[8].override_count = 0;
    *(_DWORD *)&dataDesc_62[8].flatGroup = 0;
    dataDesc_62[9].fieldType = FIELD_TIME;
    dataDesc_62[9].fieldName = "m_TimeLastLookNPCs";
    dataDesc_62[9].fieldOffset = 100;
    dataDesc_62[9].flags = 2;
    dataDesc_62[9].externalName = nullptr;
    dataDesc_62[9].pSaveRestoreOps = nullptr;
    dataDesc_62[9].inputFunc = nullptr;
    dataDesc_62[9].td = nullptr;
    dataDesc_62[9].fieldSizeInBytes = 4;
    dataDesc_62[9].override_field = nullptr;
    dataDesc_62[9].override_count = 0;
    *(_QWORD *)dataDesc_62[9].flatOffset = 0;
    *(_DWORD *)&dataDesc_62[9].flatGroup = 0;
    dataDesc_62[10].fieldType = FIELD_TIME;
    dataDesc_62[10].fieldName = "m_TimeLastLookMisc";
    dataDesc_62[10].fieldOffset = 104;
    *(_DWORD *)&dataDesc_62[10].fieldSize = 131073;
    dataDesc_62[10].externalName = nullptr;
    dataDesc_62[10].pSaveRestoreOps = nullptr;
    dataDesc_62[10].inputFunc = nullptr;
    dataDesc_62[10].td = nullptr;
    dataDesc_62[10].fieldSizeInBytes = 4;
    dataDesc_62[10].override_field = nullptr;
    dataDesc_62[10].override_count = 0;
    *(_QWORD *)dataDesc_62[10].flatOffset = 0;
    *(_DWORD *)&dataDesc_62[10].flatGroup = 0;
  }
  CAI_Senses::m_DataMap.dataNumFields = 10;
  CAI_Senses::m_DataMap.dataDesc = &dataDesc_62[1];
  return &CAI_Senses::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10086C80
// Name: struct datamap_t __near * DataMapInit<class CAI_SentenceBase>(class CAI_SentenceBase __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CAI_SentenceBase>()
{
  if ( (_S2_33 & 1) == 0 )
  {
    _S2_33 |= 1u;
    nameHolder_66.m_pszBase = "CAI_SentenceBase";
    nameHolder_66.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_66.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_66.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_66.m_Names.m_Size = 0;
    nameHolder_66.m_Names.m_pElements = nullptr;
    nameHolder_66.m_nLenBase = 16;
    atexit(func: DataMapInit_CAI_SentenceBase__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CAI_SentenceBase::m_DataMap.baseMap = nullptr;
  CAI_SentenceBase::m_DataMap.dataNumFields = 4;
  CAI_SentenceBase::m_DataMap.dataDesc = &dataDesc_63[1];
  return &CAI_SentenceBase::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FECF0
// Name: _dynamic_initializer_for__npc_sentences__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__npc_sentences__()
{
  ConVar::ConVar(this: &npc_sentences, pName: "npc_sentences", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__npc_sentences__);
}
