// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/ai_squad.cpp
// Functions: 32
// ============================================================

#include "game\server\ai_squad.h"

//------------------------------------------------------------------------------
// Address: 0x1008B600
// Name: public: int CAI_SquadManager::NumSquads(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_SquadManager::NumSquads(CAI_SquadManager *this)
{
  CAI_Squad *m_pSquads; // ecx
  int result; // eax

  m_pSquads = this->m_pSquads;
  for ( result = 0; m_pSquads != nullptr; ++result )
    m_pSquads = m_pSquads->m_pNextSquad;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008B610
// Name: public: bool CAI_Squad::SquadIsMember(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Squad::SquadIsMember(CAI_Squad *this, CBaseEntity *pMember)
{
  CAI_BaseNPC *v3; // eax

  v3 = pMember->MyNPCPointer(this: pMember);
  return v3 != nullptr && v3->m_pSquad == this;
}

//------------------------------------------------------------------------------
// Address: 0x1008B640
// Name: public: bool CAI_Squad::FOkToMakeSound(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Squad::FOkToMakeSound(CAI_Squad *this, int soundPriority)
{
  return this->m_flSquadSoundWaitTime < gpGlobals->curtime || soundPriority > this->m_nSquadSoundPriority;
}

//------------------------------------------------------------------------------
// Address: 0x1008B670
// Name: public: void CAI_Squad::JustMadeSound(int,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Squad::JustMadeSound(CAI_Squad *this, int soundPriority, float time)
{
  this->m_flSquadSoundWaitTime = time;
  this->m_nSquadSoundPriority = soundPriority;
}

//------------------------------------------------------------------------------
// Address: 0x1008B690
// Name: public: class CAI_Squad __near * CAI_SquadManager::FindSquad(struct string_t)
// Source: json
//------------------------------------------------------------------------------
CAI_Squad *__thiscall CAI_SquadManager::FindSquad(CAI_SquadManager *this, string_t squadName)
{
  CAI_Squad *m_pSquads; // esi
  const char *pszValue; // ecx
  const char *v4; // eax

  m_pSquads = this->m_pSquads;
  if ( this->m_pSquads == nullptr )
    return nullptr;
  while ( 1 )
  {
    pszValue = m_pSquads->m_Name.pszValue;
    if ( pszValue == nullptr )
      pszValue = locale;
    v4 = squadName.pszValue;
    if ( squadName.pszValue == nullptr )
      v4 = locale;
    if ( v4 == pszValue || _V_stricmp(s1: v4, s2: pszValue) == 0 )
      break;
    m_pSquads = m_pSquads->m_pNextSquad;
    if ( m_pSquads == nullptr )
      return nullptr;
  }
  return m_pSquads;
}

//------------------------------------------------------------------------------
// Address: 0x1008B6E0
// Name: public: static bool CAI_Squad::IsSilentMember(class CAI_BaseNPC const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CAI_Squad::IsSilentMember(CAI_BaseNPC *pNPC)
{
  return pNPC == nullptr
      || pNPC->m_MoveType.m_Value == 0 && pNPC->m_Collision.GetSolid(this: &pNPC->m_Collision) == SOLID_NONE
      || pNPC->IsSilentSquadMember(this: pNPC);
}

//------------------------------------------------------------------------------
// Address: 0x1008B720
// Name: public: virtual void CVarBitVecSaveRestoreOps<class CBitVec<32>>::Save(struct SaveRestoreFieldInfo_t const __near &,class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecSaveRestoreOps<CBitVec<32>>::Save(
        CVarBitVecSaveRestoreOps<CBitVec<32> > *this,
        int fieldInfo,
        ISave *pSave)
{
  ISave *v3; // esi
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  const int *v5; // edi

  v3 = pSave;
  WriteInt_2 = pSave->WriteInt_2;
  v5 = *(const int **)fieldInfo;
  fieldInfo = 32;
  WriteInt_2(this: pSave, a2: &fieldInfo, a3: 1);
  v3->WriteInt_2(this: v3, a2: v5, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1008B760
// Name: public: virtual void CVarBitVecSaveRestoreOps<class CBitVec<32>>::Restore(struct SaveRestoreFieldInfo_t const __near &,class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecSaveRestoreOps<CBitVec<32>>::Restore(
        CVarBitVecSaveRestoreOps<CBitVec<32> > *this,
        int fieldInfo,
        IRestore *pRestore)
{
  int *v3; // ebx
  IRestore *v4; // edi
  int v5; // eax
  int v6; // eax
  int v7; // esi
  int i; // esi

  v3 = *(int **)fieldInfo;
  v4 = pRestore;
  v5 = pRestore->ReadInt(this: pRestore);
  if ( v3 != nullptr )
    *v3 = 0;
  v6 = v5 + 31;
  v7 = v6 / 32;
  fieldInfo = 1;
  if ( v6 / 32 <= 1 )
    fieldInfo = v6 / 32;
  v4->ReadInt_2(this: v4, a2: v3, a3: v7, a4: 0);
  for ( i = v7 - fieldInfo; i > 0; --i )
    v4->ReadInt_2(this: v4, a2: &fieldInfo, a3: 1, a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1008B7D0
// Name: public: virtual void CVarBitVecSaveRestoreOps<class CBitVec<32>>::MakeEmpty(struct SaveRestoreFieldInfo_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CVarBitVecSaveRestoreOps<CBitVec<32>>::MakeEmpty(
        CVarBitVecSaveRestoreOps<CBitVec<32> > *this,
        const SaveRestoreFieldInfo_t *fieldInfo)
{
  if ( fieldInfo->pField != nullptr )
    *(_DWORD *)fieldInfo->pField = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1008B900
// Name: public: class CAI_BaseNPC __near * CAI_Squad::GetLeader(void)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_Squad::GetLeader(CAI_Squad *this)
{
  IHandleEntity *m_pEntity; // ebx
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // edi
  unsigned int v3; // eax
  CEntInfo *v4; // ecx
  IHandleEntity *v5; // esi
  unsigned int v6; // eax
  CAI_Squad *v8; // [esp+4h] [ebp-Ch]
  int i; // [esp+8h] [ebp-8h]
  int nSilentMembers; // [esp+Ch] [ebp-4h]

  m_pEntity = nullptr;
  v8 = this;
  nSilentMembers = 0;
  i = 0;
  if ( this->m_SquadMembers.m_Size > 0 )
  {
    p_m_SquadMembers = &this->m_SquadMembers;
    do
    {
      v3 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
      if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory != -1
        && (v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v3],
            g_pEntityList->m_EntPtrArray[(unsigned __int16)v3].m_SerialNumber == HIWORD(v3))
        && (v5 = v4->m_pEntity, v4->m_pEntity != nullptr)
        && (BYTE2(v5[53].__vftable) != 0 || v5[57].__vftable[3].GetRefEHandle(this: v5 + 57) != nullptr)
        && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v5->__vftable[180].SetRefEHandle)(a1: v5) == 0 )
      {
        if ( m_pEntity == nullptr )
        {
          v6 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
          if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
          }
        }
      }
      else
      {
        ++nSilentMembers;
      }
      this = v8;
      p_m_SquadMembers = (CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *)((char *)p_m_SquadMembers + 4);
      ++i;
    }
    while ( i < v8->m_SquadMembers.m_Size );
  }
  return this->m_SquadMembers.m_Size - nSilentMembers <= 1 ? nullptr : (CAI_BaseNPC *)m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1008B9F0
// Name: public: class CAI_BaseNPC __near * CAI_Squad::GetFirstMember(struct AISquadIter_t__ __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_Squad::GetFirstMember(CAI_Squad *this, AISquadIter_t__ **pIter, bool bIgnoreSilentMembers)
{
  int v3; // edi
  unsigned int v5; // eax
  CEntInfo *v6; // ecx
  IHandleEntity *m_pEntity; // esi
  unsigned int v8; // eax
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *bIgnoreSilentMembersa; // [esp+14h] [ebp+Ch]

  v3 = 0;
  if ( bIgnoreSilentMembers && this->m_SquadMembers.m_Size > 0 )
  {
    bIgnoreSilentMembersa = &this->m_SquadMembers;
    do
    {
      v5 = *(_DWORD *)bIgnoreSilentMembersa->m_Memory.m_Memory;
      if ( *(_DWORD *)bIgnoreSilentMembersa->m_Memory.m_Memory != -1 )
      {
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v5];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5) )
        {
          m_pEntity = v6->m_pEntity;
          if ( v6->m_pEntity != nullptr
            && (BYTE2(m_pEntity[53].__vftable) != 0
             || m_pEntity[57].__vftable[3].GetRefEHandle(this: m_pEntity + 57) != nullptr)
            && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[180].SetRefEHandle)(a1: m_pEntity) == 0 )
          {
            break;
          }
        }
      }
      bIgnoreSilentMembersa = (CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *)((char *)bIgnoreSilentMembersa + 4);
      ++v3;
    }
    while ( v3 < this->m_SquadMembers.m_Size );
  }
  if ( pIter != nullptr )
    *pIter = (AISquadIter_t__ *)v3;
  if ( v3 >= this->m_SquadMembers.m_Size )
    return nullptr;
  v8 = *(_DWORD *)&this->m_SquadMembers.m_Memory.m_Memory[4 * v3];
  if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    return nullptr;
  else
    return (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1008BAC0
// Name: public: class CAI_BaseNPC __near * CAI_Squad::GetNextMember(struct AISquadIter_t__ __near * __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CAI_BaseNPC *__thiscall CAI_Squad::GetNextMember(CAI_Squad *this, AISquadIter_t__ **pIter, bool bIgnoreSilentMembers)
{
  int v3; // eax
  unsigned int v5; // eax
  CEntInfo *v6; // ecx
  IHandleEntity *m_pEntity; // edi
  unsigned int v8; // eax

  *pIter = (AISquadIter_t__ *)((char *)*pIter + 1);
  v3 = (int)*pIter;
  if ( bIgnoreSilentMembers && v3 < this->m_SquadMembers.m_Size )
  {
    do
    {
      v5 = *(_DWORD *)&this->m_SquadMembers.m_Memory.m_Memory[4 * v3];
      if ( v5 != -1 )
      {
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v5];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5) )
        {
          m_pEntity = v6->m_pEntity;
          if ( v6->m_pEntity != nullptr
            && (BYTE2(m_pEntity[53].__vftable) != 0
             || m_pEntity[57].__vftable[3].GetRefEHandle(this: m_pEntity + 57) != nullptr)
            && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[180].SetRefEHandle)(a1: m_pEntity) == 0 )
          {
            break;
          }
        }
      }
      *pIter = (AISquadIter_t__ *)((char *)*pIter + 1);
      v3 = (int)*pIter;
    }
    while ( (int)*pIter < this->m_SquadMembers.m_Size );
  }
  if ( (int)*pIter >= this->m_SquadMembers.m_Size )
    return nullptr;
  v8 = *(_DWORD *)&this->m_SquadMembers.m_Memory.m_Memory[4 * (_DWORD)*pIter];
  if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
    return nullptr;
  else
    return (CAI_BaseNPC *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1008BB90
// Name: public: class Vector CAI_Squad::ComputeSquadCentroid(bool,class CBaseCombatCharacter __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__thiscall CAI_Squad::ComputeSquadCentroid(
        CAI_Squad *this,
        Vector *result,
        bool bIncludeSilentMembers,
        CBaseCombatCharacter *pExcludeMember)
{
  int v4; // ebx
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // edi
  unsigned int v6; // eax
  CBaseCombatCharacter *m_pEntity; // ecx
  CEntInfo *v8; // ecx
  IHandleEntity *v9; // esi
  unsigned int v10; // eax
  CBaseEntity *v11; // esi
  float v13; // xmm0_4
  float vecSumOfOrigins; // [esp+0h] [ebp-14h]
  float vecSumOfOrigins_4; // [esp+4h] [ebp-10h]
  float vecSumOfOrigins_8; // [esp+8h] [ebp-Ch]
  int count; // [esp+10h] [ebp-4h]
  int savedregs; // [esp+14h] [ebp+0h] BYREF

  v4 = 0;
  count = 0;
  vecSumOfOrigins = 0.0;
  vecSumOfOrigins_4 = 0.0;
  vecSumOfOrigins_8 = 0.0;
  if ( this->m_SquadMembers.m_Size > 0 )
  {
    p_m_SquadMembers = &this->m_SquadMembers;
    do
    {
      v6 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
      if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CBaseCombatCharacter *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
      }
      if ( m_pEntity != pExcludeMember )
      {
        if ( bIncludeSilentMembers
          || v6 != -1
          && (v8 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v6],
              g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber == HIWORD(v6))
          && (v9 = v8->m_pEntity, v8->m_pEntity != nullptr)
          && (BYTE2(v9[53].__vftable) != 0 || v9[57].__vftable[3].GetRefEHandle(this: v9 + 57) != nullptr)
          && ((unsigned __int8 (__thiscall *)(IHandleEntity *))v9->__vftable[180].SetRefEHandle)(a1: v9) == 0 )
        {
          v10 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
          ++count;
          if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber != HIWORD(v10) )
          {
            v11 = nullptr;
          }
          else
          {
            v11 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
          }
          if ( (v11->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v11, a2: (int)&savedregs);
          vecSumOfOrigins = v11->m_vecAbsOrigin.x + vecSumOfOrigins;
          vecSumOfOrigins_4 = v11->m_vecAbsOrigin.y + vecSumOfOrigins_4;
          vecSumOfOrigins_8 = v11->m_vecAbsOrigin.z + vecSumOfOrigins_8;
        }
      }
      ++v4;
      p_m_SquadMembers = (CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *)((char *)p_m_SquadMembers + 4);
    }
    while ( v4 < this->m_SquadMembers.m_Size );
  }
  v13 = 1.0 / (float)count;
  result->x = v13 * vecSumOfOrigins;
  result->y = v13 * vecSumOfOrigins_4;
  result->z = v13 * vecSumOfOrigins_8;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008BD30
// Name: public: int CAI_Squad::NumMembers(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAI_Squad::NumMembers(CAI_Squad *this, bool bIgnoreSilentMembers)
{
  int v2; // edi
  CAI_Squad *v3; // edx
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // ebx
  unsigned int v5; // eax
  CEntInfo *v6; // ecx
  IHandleEntity *m_pEntity; // esi
  int nSilentMembers; // [esp+8h] [ebp-4h]

  v2 = 0;
  v3 = this;
  nSilentMembers = 0;
  if ( bIgnoreSilentMembers && this->m_SquadMembers.m_Size > 0 )
  {
    p_m_SquadMembers = &this->m_SquadMembers;
    do
    {
      v5 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
      if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory != -1 )
      {
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v5];
        if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber == HIWORD(v5) )
        {
          m_pEntity = v6->m_pEntity;
          if ( v6->m_pEntity != nullptr )
          {
            if ( (BYTE2(m_pEntity[53].__vftable) != 0
               || m_pEntity[57].__vftable[3].GetRefEHandle(this: m_pEntity + 57) != nullptr)
              && ((unsigned __int8 (__thiscall *)(IHandleEntity *))m_pEntity->__vftable[180].SetRefEHandle)(a1: m_pEntity) == 0 )
            {
              v3 = this;
              goto LABEL_13;
            }
            v3 = this;
          }
        }
      }
      ++nSilentMembers;
LABEL_13:
      ++v2;
      p_m_SquadMembers = (CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *)((char *)p_m_SquadMembers + 4);
    }
    while ( v2 < v3->m_SquadMembers.m_Size );
  }
  return v3->m_SquadMembers.m_Size - nSilentMembers;
}

//------------------------------------------------------------------------------
// Address: 0x1008BDD0
// Name: public: void CAI_Squad::SquadNewEnemy(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Squad::SquadNewEnemy(CAI_Squad *this, CBaseEntity *pEnemy)
{
  CBaseEntity *v2; // edi
  int v3; // ebx
  unsigned int v4; // eax
  CEntInfo *v5; // ecx
  CAI_BaseNPC *m_pEntity; // esi
  CGlobalVars *v7; // edi
  double v8; // st7
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // [esp+8h] [ebp-4h]

  v2 = pEnemy;
  if ( pEnemy != nullptr )
  {
    v3 = 0;
    if ( this->m_SquadMembers.m_Size > 0 )
    {
      p_m_SquadMembers = &this->m_SquadMembers;
      do
      {
        v4 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
        if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory != -1 )
        {
          v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)v4];
          if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber == HIWORD(v4) )
          {
            m_pEntity = (CAI_BaseNPC *)v5->m_pEntity;
            if ( v5->m_pEntity != nullptr )
            {
              if ( m_pEntity->GetEnemy_2(this: v5->m_pEntity) == nullptr
                || m_pEntity->GetEnemy_2(this: m_pEntity) != v2
                && !CAI_BaseNPC::HasCondition(this: m_pEntity, iCondition: 10)
                && (v7 = gpGlobals,
                    v8 = v7->curtime - CAI_BaseNPC::GetEnemyLastTimeSeen(this: m_pEntity),
                    v2 = pEnemy,
                    v8 > 3.0) )
              {
                if ( hl2_episodic.m_pParent == nullptr
                  || hl2_episodic.m_pParent->m_Value.m_nValue == 0
                  || m_pEntity->IsValidEnemy(this: m_pEntity, a2: v2) )
                {
                  CAI_BaseNPC::SetEnemy(this: m_pEntity, pEnemy: v2, bSetCondNewEnemy: true);
                }
              }
            }
          }
        }
        p_m_SquadMembers = (CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *)((char *)p_m_SquadMembers + 4);
        ++v3;
      }
      while ( v3 < this->m_SquadMembers.m_Size );
    }
  }
  else
  {
    DevMsg(a1: "ERROR: SquadNewEnemy() - pEnemy is NULL!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008BEE0
// Name: public: void CAI_Squad::UpdateEnemyMemory(class CAI_BaseNPC __near *,class CBaseEntity __near *,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Squad::UpdateEnemyMemory(
        CAI_Squad *this,
        CAI_BaseNPC *pUpdater,
        CBaseEntity *pEnemy,
        const Vector *position)
{
  int v4; // esi
  CBaseEntityList *v5; // edx
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // edi
  unsigned int v7; // eax
  CAI_BaseNPC *m_pEntity; // ecx
  IHandleEntity *v9; // ecx

  v4 = 0;
  if ( this->m_SquadMembers.m_Size > 0 )
  {
    v5 = g_pEntityList;
    p_m_SquadMembers = &this->m_SquadMembers;
    do
    {
      v7 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
      if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory == -1
        || v5->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CAI_BaseNPC *)v5->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
      }
      if ( m_pEntity != pUpdater )
      {
        if ( v7 == -1 || v5->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber != HIWORD(v7) )
          v9 = nullptr;
        else
          v9 = v5->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
        ((void (__thiscall *)(IHandleEntity *, CBaseEntity *, const Vector *, CAI_BaseNPC *))v9->__vftable[177].dtr_IHandleEntity)(
          a1: v9,
          a2: pEnemy,
          a3: position,
          a4: pUpdater);
        v5 = g_pEntityList;
      }
      ++v4;
      p_m_SquadMembers = (CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *)((char *)p_m_SquadMembers + 4);
    }
    while ( v4 < this->m_SquadMembers.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C090
// Name: private: CAI_Squad::~CAI_Squad(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Squad::~CAI_Squad(CAI_Squad *this)
{
  CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_EnemyInfos);
  this->m_SquadMembers.m_Size = 0;
  this->m_SquadMembers.m_pElements = (CHandle<CAI_BaseNPC> *)&this->m_SquadMembers;
}

//------------------------------------------------------------------------------
// Address: 0x1008C0B0
// Name: public: void CAI_Squad::RemoveFromSquad(class CAI_BaseNPC __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Squad::RemoveFromSquad(CAI_Squad *this, CAI_BaseNPC *pNPC, bool bDeath)
{
  CAI_BaseNPC *v3; // ebx
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // esi
  int v5; // eax
  int i; // edi
  unsigned int v7; // eax
  IHandleEntity *m_pEntity; // ecx

  v3 = pNPC;
  if ( pNPC != nullptr )
  {
    p_m_SquadMembers = &this->m_SquadMembers;
    pNPC = (CAI_BaseNPC *)pNPC->GetRefEHandle(this: pNPC)->m_Index;
    v5 = CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0>>::Find(
           this: p_m_SquadMembers,
           src: (CHandle<CBaseEntity> *)&pNPC);
    if ( v5 == -1 )
    {
      DevMsg(a1: "ERROR: Attempting to remove non-existing squad membmer!\n");
    }
    else
    {
      if ( p_m_SquadMembers->m_Size - v5 - 1 > 0 )
        _V_memmove(
          dest: (char *)p_m_SquadMembers + 4 * v5,
          src: &p_m_SquadMembers->m_Memory.m_Memory[4 * v5 + 4],
          count: 4 * (p_m_SquadMembers->m_Size - v5 - 1));
      --p_m_SquadMembers->m_Size;
      if ( bDeath )
      {
        for ( i = 0;
              i < this->m_SquadMembers.m_Size;
              p_m_SquadMembers = (CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *)((char *)p_m_SquadMembers + 4) )
        {
          v7 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
          if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory != -1
            && g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_SerialNumber == HIWORD(v7) )
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v7].m_pEntity;
            if ( m_pEntity != nullptr )
              ((void (__thiscall *)(IHandleEntity *, CAI_BaseNPC *))m_pEntity->__vftable[198].dtr_IHandleEntity)(
                a1: m_pEntity,
                a2: v3);
          }
          ++i;
        }
      }
      v3->SetSquad(this: v3, a2: nullptr);
      v3->m_SquadName.pszValue = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C1A0
// Name: public: bool CAI_Squad::IsLeader(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAI_Squad::IsLeader(CAI_Squad *this, CAI_BaseNPC *pNPC)
{
  return pNPC != nullptr
      && (pNPC->m_MoveType.m_Value != 0 || pNPC->m_Collision.GetSolid(this: &pNPC->m_Collision) != SOLID_NONE)
      && !pNPC->IsSilentSquadMember(this: pNPC)
      && CAI_Squad::GetLeader(this) == pNPC;
}

//------------------------------------------------------------------------------
// Address: 0x1008C250
// Name: public: void CAI_SquadManager::DeleteAllSquads(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_SquadManager::DeleteAllSquads(CAI_SquadManager *this)
{
  CAI_Squad *m_pSquads; // esi
  CAI_Squad *m_pNextSquad; // ebx
  AISquadEnemyInfo_t *m_pMemory; // eax
  CAI_SquadManager *v4; // [esp+8h] [ebp-4h]

  m_pSquads = this->m_pSquads;
  v4 = this;
  if ( this->m_pSquads != nullptr )
  {
    do
    {
      m_pNextSquad = m_pSquads->m_pNextSquad;
      m_pSquads->m_EnemyInfos.m_Size = 0;
      if ( m_pSquads->m_EnemyInfos.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pSquads->m_EnemyInfos.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pSquads->m_EnemyInfos.m_Memory.m_pMemory);
          m_pSquads->m_EnemyInfos.m_Memory.m_pMemory = nullptr;
        }
        m_pSquads->m_EnemyInfos.m_Memory.m_nAllocationCount = 0;
      }
      m_pMemory = m_pSquads->m_EnemyInfos.m_Memory.m_pMemory;
      m_pSquads->m_EnemyInfos.m_pElements = m_pMemory;
      if ( m_pSquads->m_EnemyInfos.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          m_pSquads->m_EnemyInfos.m_Memory.m_pMemory = nullptr;
        }
        m_pSquads->m_EnemyInfos.m_Memory.m_nAllocationCount = 0;
      }
      m_pSquads->m_SquadMembers.m_Size = 0;
      m_pSquads->m_SquadMembers.m_pElements = (CHandle<CAI_BaseNPC> *)&m_pSquads->m_SquadMembers;
      free(pMem: m_pSquads);
      m_pSquads = m_pNextSquad;
    }
    while ( m_pNextSquad != nullptr );
    this = v4;
  }
  this->m_pSquads = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1008C510
// Name: private: CAI_Squad::CAI_Squad(struct string_t)
// Source: json
//------------------------------------------------------------------------------
CAI_Squad *__thiscall CAI_Squad::CAI_Squad(CAI_Squad *this, string_t newName)
{
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // edi
  const char *v4; // ecx
  char pszValue[4]; // [esp+Ch] [ebp-4h] BYREF

  this->m_SquadMembers.m_Size = 0;
  p_m_SquadMembers = &this->m_SquadMembers;
  this->m_SquadMembers.m_pElements = (CHandle<CAI_BaseNPC> *)&this->m_SquadMembers;
  this->m_hSquadInflictor.m_Index = -1;
  this->m_EnemyInfos.m_Memory.m_pMemory = nullptr;
  this->m_EnemyInfos.m_Memory.m_nAllocationCount = 0;
  this->m_EnemyInfos.m_Memory.m_nGrowSize = 0;
  this->m_EnemyInfos.m_Size = 0;
  this->m_EnemyInfos.m_pElements = nullptr;
  v4 = *(const char **)AllocPooledString(pszValue).pszValue;
  this->m_pNextSquad = nullptr;
  this->m_Name.pszValue = v4;
  p_m_SquadMembers->m_Size = 0;
  this->m_flSquadSoundWaitTime = 0.0;
  this->m_hSquadInflictor.m_Index = -1;
  this->m_pLastFoundEnemyInfo = nullptr;
  this->m_flEnemyInfoCleanupTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008C590
// Name: private: CAI_Squad::CAI_Squad(void)
// Source: json
//------------------------------------------------------------------------------
CAI_Squad *__thiscall CAI_Squad::CAI_Squad(CAI_Squad *this)
{
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // edi
  const char *v3; // ecx
  char pszValue[4]; // [esp+Ch] [ebp-4h] BYREF

  this->m_SquadMembers.m_Size = 0;
  p_m_SquadMembers = &this->m_SquadMembers;
  this->m_SquadMembers.m_pElements = (CHandle<CAI_BaseNPC> *)&this->m_SquadMembers;
  this->m_hSquadInflictor.m_Index = -1;
  this->m_EnemyInfos.m_Memory.m_pMemory = nullptr;
  this->m_EnemyInfos.m_Memory.m_nAllocationCount = 0;
  this->m_EnemyInfos.m_Memory.m_nGrowSize = 0;
  this->m_EnemyInfos.m_Size = 0;
  this->m_EnemyInfos.m_pElements = nullptr;
  v3 = *(const char **)AllocPooledString(pszValue).pszValue;
  this->m_pNextSquad = nullptr;
  this->m_Name.pszValue = v3;
  p_m_SquadMembers->m_Size = 0;
  this->m_flSquadSoundWaitTime = 0.0;
  this->m_hSquadInflictor.m_Index = -1;
  this->m_pLastFoundEnemyInfo = nullptr;
  this->m_flEnemyInfoCleanupTime = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008C600
// Name: public: void CAI_Squad::AddToSquad(class CAI_BaseNPC __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Squad::AddToSquad(CAI_Squad *this, CAI_BaseNPC *pNPC)
{
  CAI_BaseNPC *v2; // esi
  CAI_Squad *m_pSquad; // ecx
  const char *pszValue; // eax
  CBaseEntity *v6; // edi
  AI_EnemyInfo_t *i; // eax
  unsigned int m_Index; // ecx
  IHandleEntity *m_pEntity; // ecx
  CAI_Enemies *pEnemies; // [esp+8h] [ebp-4h]

  v2 = pNPC;
  if ( pNPC != nullptr && pNPC->IsAlive(this: pNPC) )
  {
    m_pSquad = v2->m_pSquad;
    if ( m_pSquad != this )
    {
      if ( m_pSquad != nullptr )
        CAI_Squad::RemoveFromSquad(this: m_pSquad, pNPC: v2, bDeath: false);
      if ( this->m_SquadMembers.m_Size == 16 )
      {
        pszValue = this->m_Name.pszValue;
        if ( pszValue == nullptr )
          pszValue = locale;
        DevMsg(a1: "Error!! Squad %s is too big!!! Replacing last member\n", pszValue);
        CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0>>::Remove(
          this: &this->m_SquadMembers,
          elem: this->m_SquadMembers.m_Size - 1);
      }
      pNPC = (CAI_BaseNPC *)v2->GetRefEHandle(this: v2)->m_Index;
      CUtlVector<CHandle<CAI_BaseNPC>,CUtlMemoryFixed<CHandle<CAI_BaseNPC>,16,0>>::AddToTail(
        this: &this->m_SquadMembers,
        src: (const CHandle<CAI_BaseNPC> *)&pNPC);
      v2->SetSquad(this: v2, a2: this);
      v2->m_SquadName.pszValue = this->m_Name.pszValue;
      if ( this->m_SquadMembers.m_Size > 1 )
      {
        v6 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)&this->m_SquadMembers);
        pEnemies = (CAI_Enemies *)((int (__thiscall *)(CBaseEntity *))v6->__vftable[2].GetAttackDamageScale)(a1: v6);
        for ( i = CAI_Enemies::GetFirst(this: pEnemies, pIter: (AIEnemiesIter_t__ **)&pNPC);
              i != nullptr;
              i = CAI_Enemies::GetNext(this: pEnemies, pIter: (AIEnemiesIter_t__ **)&pNPC) )
        {
          m_Index = i->hEnemy.m_Index;
          if ( i->hEnemy.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
          }
          v2->UpdateEnemyMemory(this: v2, a2: (CBaseEntity *)m_pEntity, a3: &i->vLastKnownLocation, a4: v6);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1008C730
// Name: public: class CAI_Squad __near * CAI_SquadManager::CreateSquad(struct string_t)
// Source: json
//------------------------------------------------------------------------------
CAI_Squad *__thiscall CAI_SquadManager::CreateSquad(CAI_SquadManager *this, string_t squadName)
{
  CAI_Squad *v3; // eax
  CAI_Squad *result; // eax

  v3 = (CAI_Squad *)operator new(nSize: 0x88u);
  if ( v3 != nullptr )
    result = CAI_Squad::CAI_Squad(this: v3, newName: squadName);
  else
    result = nullptr;
  if ( squadName.pszValue != nullptr )
  {
    result->m_pNextSquad = this->m_pSquads;
    this->m_pSquads = result;
  }
  else
  {
    result->m_pNextSquad = nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008C780
// Name: private: struct AISquadEnemyInfo_t __near * CAI_Squad::FindEnemyInfo(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
AISquadEnemyInfo_t *__thiscall CAI_Squad::FindEnemyInfo(CAI_Squad *this, CBaseEntity *pEnemy)
{
  int v3; // esi
  CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *p_m_SquadMembers; // edi
  unsigned int v5; // eax
  IHandleEntity *m_pEntity; // ecx
  int i; // esi
  AISquadEnemyInfo_t *m_pMemory; // ecx
  unsigned int m_Index; // eax
  AISquadEnemyInfo_t *v10; // edx
  unsigned int v11; // eax
  CBaseEntity *v12; // ecx
  int m_Size; // ecx
  AISquadEnemyInfo_t *v14; // eax
  AISquadEnemyInfo_t *result; // eax
  unsigned int v16; // ecx
  CBaseEntity *v17; // ecx
  int v18; // esi
  AISquadEnemyInfo_t *v19; // edx
  unsigned int v20; // eax
  CBaseEntity *v21; // ecx
  int v22; // edi
  int m_nAllocationCount; // eax
  AISquadEnemyInfo_t *v24; // ecx
  int v25; // eax
  AISquadEnemyInfo_t *v26; // eax
  int v27; // ecx
  bool v28; // zf
  AISquadEnemyInfo_t *v29; // eax
  CBitVec<32> *p_slots; // eax
  AISquadEnemyInfo_t *v31; // edi
  CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl*)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short> > activeEnemies; // [esp+0h] [ebp-20h] BYREF
  CBaseEntity *pMemberEnemy; // [esp+1Ch] [ebp-4h] BYREF

  if ( gpGlobals->curtime > this->m_flEnemyInfoCleanupTime )
  {
    v3 = 0;
    if ( this->m_EnemyInfos.m_Size != 0 )
    {
      this->m_pLastFoundEnemyInfo = nullptr;
      memset(&activeEnemies.m_Elements, 0, sizeof(activeEnemies.m_Elements));
      *(_DWORD *)&activeEnemies.m_Root = 0xFFFF;
      *(_DWORD *)&activeEnemies.m_FirstFree = -1;
      activeEnemies.m_pElements = nullptr;
      activeEnemies.m_LessFunc = (bool (__cdecl *)(CBaseEntity *const *, CBaseEntity *const *))CDefOps<CChoreoActor *>::LessFunc;
      if ( this->m_SquadMembers.m_Size > 0 )
      {
        p_m_SquadMembers = &this->m_SquadMembers;
        do
        {
          v5 = *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory;
          if ( *(_DWORD *)p_m_SquadMembers->m_Memory.m_Memory == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_SerialNumber != HIWORD(v5) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = g_pEntityList->m_EntPtrArray[(unsigned __int16)v5].m_pEntity;
          }
          pMemberEnemy = (CBaseEntity *)m_pEntity->__vftable[32].GetRefEHandle(this: m_pEntity);
          if ( pMemberEnemy != nullptr
            && CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::Find(
                 this: &activeEnemies,
                 search: &pMemberEnemy) == 0xFFFF )
          {
            CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::Insert(
              this: &activeEnemies,
              insert: &pMemberEnemy);
          }
          ++v3;
          p_m_SquadMembers = (CUtlVectorFixed<CHandle<CAI_BaseNPC>,16> *)((char *)p_m_SquadMembers + 4);
        }
        while ( v3 < this->m_SquadMembers.m_Size );
      }
      for ( i = this->m_EnemyInfos.m_Size - 1; i >= 0; --i )
      {
        m_pMemory = this->m_EnemyInfos.m_Memory.m_pMemory;
        m_Index = m_pMemory[i].hEnemy.m_Index;
        v10 = &m_pMemory[i];
        if ( m_Index != -1
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber == HIWORD(m_Index)
          && g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != nullptr )
        {
          v11 = v10->hEnemy.m_Index;
          if ( v10->hEnemy.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
          {
            v12 = nullptr;
          }
          else
          {
            v12 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
          }
          pMemberEnemy = v12;
          if ( CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::Find(
                 this: &activeEnemies,
                 search: &pMemberEnemy) != 0xFFFF )
            continue;
        }
        m_Size = this->m_EnemyInfos.m_Size;
        if ( m_Size > 0 )
        {
          if ( i != m_Size - 1 )
          {
            v14 = this->m_EnemyInfos.m_Memory.m_pMemory;
            v14[i].hEnemy.m_Index = v14[m_Size - 1].hEnemy.m_Index;
            v14[i].slots.m_Ints[0] = v14[m_Size - 1].slots.m_Ints[0];
          }
          --this->m_EnemyInfos.m_Size;
        }
      }
      CUtlRBTree<CBaseEntity *,unsigned short,bool (__cdecl *)(CBaseEntity * const &,CBaseEntity * const &),CUtlMemory<UtlRBTreeNode_t<CBaseEntity *,unsigned short>,unsigned short>>::RemoveAll(this: &activeEnemies);
      if ( activeEnemies.m_Elements.m_nGrowSize >= 0 && activeEnemies.m_Elements.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: activeEnemies.m_Elements.m_pMemory);
    }
    this->m_flEnemyInfoCleanupTime = gpGlobals->curtime + 30.0;
  }
  result = this->m_pLastFoundEnemyInfo;
  if ( result == nullptr
    || ((v16 = result->hEnemy.m_Index, result->hEnemy.m_Index == -1)
     || g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_SerialNumber != HIWORD(v16)
      ? (v17 = nullptr)
      : (v17 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v16].m_pEntity),
        v17 != pEnemy) )
  {
    v18 = 0;
    if ( this->m_EnemyInfos.m_Size <= 0 )
    {
LABEL_45:
      this->m_pLastFoundEnemyInfo = nullptr;
      v22 = this->m_EnemyInfos.m_Size;
      m_nAllocationCount = this->m_EnemyInfos.m_Memory.m_nAllocationCount;
      if ( v22 + 1 > m_nAllocationCount )
        CUtlMemory<CEntityDataInstantiator<StepSimulationData>::HashEntry,int>::Grow(
          this: (CUtlMemory<CUtlHandleTable<vgui::BuildGroup,20>::EntryType_t,int> *)&this->m_EnemyInfos,
          num: v22 - m_nAllocationCount + 1);
      ++this->m_EnemyInfos.m_Size;
      v24 = this->m_EnemyInfos.m_Memory.m_pMemory;
      v25 = this->m_EnemyInfos.m_Size - v22 - 1;
      this->m_EnemyInfos.m_pElements = v24;
      if ( v25 > 0 )
        _V_memmove(dest: &v24[v22 + 1], src: &v24[v22], count: 8 * v25);
      v26 = this->m_EnemyInfos.m_Memory.m_pMemory;
      v27 = v22;
      v28 = &v26[v22] == nullptr;
      v29 = &v26[v22];
      pMemberEnemy = (CBaseEntity *)(8 * v22);
      if ( !v28 )
      {
        v28 = &v29->slots == nullptr;
        p_slots = &v29->slots;
        p_slots[-1].m_Ints[0] = -1;
        if ( !v28 )
          p_slots->m_Ints[0] = 0;
      }
      v31 = &this->m_EnemyInfos.m_Memory.m_pMemory[v27];
      if ( pEnemy != nullptr )
      {
        v31->hEnemy.m_Index = pEnemy->GetRefEHandle(this: pEnemy)->m_Index;
        result = (AISquadEnemyInfo_t *)((char *)pMemberEnemy + (unsigned int)this->m_EnemyInfos.m_Memory.m_pMemory);
      }
      else
      {
        v31->hEnemy.m_Index = -1;
        result = &this->m_EnemyInfos.m_Memory.m_pMemory[v27];
      }
      this->m_pLastFoundEnemyInfo = result;
    }
    else
    {
      v19 = this->m_EnemyInfos.m_Memory.m_pMemory;
      while ( 1 )
      {
        v20 = v19->hEnemy.m_Index;
        if ( v19->hEnemy.m_Index == -1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_SerialNumber != HIWORD(v20) )
        {
          v21 = nullptr;
        }
        else
        {
          v21 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v20].m_pEntity;
        }
        if ( v21 == pEnemy )
          break;
        ++v18;
        ++v19;
        if ( v18 >= this->m_EnemyInfos.m_Size )
          goto LABEL_45;
      }
      result = &this->m_EnemyInfos.m_Memory.m_pMemory[v18];
      this->m_pLastFoundEnemyInfo = result;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1008CB50
// Name: public: bool CAI_Squad::OccupyStrategySlotRange(class CBaseEntity __near *,int,int,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAI_Squad::OccupyStrategySlotRange(
        CAI_Squad *this,
        CBaseEntity *pEnemy,
        int slotIDStart,
        int slotIDEnd,
        int *pSlot)
{
  int v5; // esi
  AISquadEnemyInfo_t *EnemyInfo; // eax
  AISquadEnemyInfo_t *v9; // eax
  int slotIDEnda; // [esp+18h] [ebp+10h]
  int slotIDEndb; // [esp+18h] [ebp+10h]

  v5 = slotIDStart;
  if ( *pSlot >= slotIDStart && *pSlot <= slotIDEnd )
    return 1;
  if ( slotIDStart > slotIDEnd )
    return 0;
  while ( ((1 << (v5 & 0x1F)) & CAI_Squad::FindEnemyInfo(this, pEnemy)->slots.m_Ints[0]) != 0 )
  {
    if ( ++v5 > slotIDEnd )
      return 0;
  }
  if ( *pSlot != -1 )
  {
    slotIDEnda = *pSlot;
    if ( ((1 << (slotIDEnda & 0x1F)) & CAI_Squad::FindEnemyInfo(this, pEnemy)->slots.m_Ints[0]) == 0 )
      DevMsg(a1: "ERROR! Vacating an empty slot!\n");
    slotIDEndb = *pSlot;
    EnemyInfo = CAI_Squad::FindEnemyInfo(this, pEnemy);
    EnemyInfo->slots.m_Ints[0] &= ~(1 << (slotIDEndb & 0x1F));
  }
  v9 = CAI_Squad::FindEnemyInfo(this, pEnemy);
  v9->slots.m_Ints[0] |= 1 << (v5 & 0x1F);
  *pSlot = v5;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1008CC30
// Name: public: void CAI_Squad::VacateStrategySlot(class CBaseEntity __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAI_Squad::VacateStrategySlot(CAI_Squad *this, CBaseEntity *pEnemy, int slot)
{
  int v4; // esi
  AISquadEnemyInfo_t *EnemyInfo; // eax

  if ( slot != -1 )
  {
    v4 = 1 << (slot & 0x1F);
    if ( (v4 & CAI_Squad::FindEnemyInfo(this, pEnemy)->slots.m_Ints[0]) == 0 )
      DevMsg(a1: "ERROR! Vacating an empty slot!\n");
    EnemyInfo = CAI_Squad::FindEnemyInfo(this, pEnemy);
    EnemyInfo->slots.m_Ints[0] &= ~v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x103FEE40
// Name: AISquadEnemyInfo_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *AISquadEnemyInfo_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<AISquadEnemyInfo_t>();
  AISquadEnemyInfo_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEE50
// Name: CAI_Squad_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CAI_Squad_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CAI_Squad>();
  CAI_Squad_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FEE60
// Name: _dynamic_initializer_for__CAI_BaseNPC::gm_SquadSlotNamespace__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__CAI_BaseNPC::gm_SquadSlotNamespace__()
{
  CAI_GlobalNamespace::CAI_GlobalNamespace(this: &CAI_BaseNPC::gm_SquadSlotNamespace);
  return atexit(func: dynamic_atexit_destructor_for__CAI_BaseNPC::gm_SquadSlotNamespace__);
}

//------------------------------------------------------------------------------
// Address: 0x103FEE80
// Name: _dynamic_initializer_for__ai_find_lateral_cover__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_find_lateral_cover__()
{
  ConVar::ConVar(this: &ai_find_lateral_cover, pName: "ai_find_lateral_cover", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_find_lateral_cover__);
}

//------------------------------------------------------------------------------
// Address: 0x103FEEB0
// Name: _dynamic_initializer_for__ai_find_lateral_los__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_find_lateral_los__()
{
  ConVar::ConVar(this: &ai_find_lateral_los, pName: "ai_find_lateral_los", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_find_lateral_los__);
}
