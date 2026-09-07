// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_gamestate.cpp
// Functions: 38
// ============================================================

#include "game\server\cstrike15\bot\cs_gamestate.h"

//------------------------------------------------------------------------------
// Address: 0x10010F30
// Name: public: void CHandle<class CBaseEntity>::Set(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHandle<CBaseEntity>::Set(CHandle<CBaseEntity> *this, const CBaseEntity *pVal)
{
  if ( pVal != nullptr )
    this->m_Index = pVal->GetRefEHandle(this: pVal)->m_Index;
  else
    this->m_Index = -1;
}

//------------------------------------------------------------------------------
// Address: 0x10012420
// Name: public: CHandle<class CBaseEntity>::CHandle<class CBaseEntity>(void)
// Source: json
//------------------------------------------------------------------------------
CHandle<CBaseEntity> *__thiscall CHandle<CBaseEntity>::CHandle<CBaseEntity>(CHandle<CBaseEntity> *this)
{
  this->m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012430
// Name: public: CHandle<class CBaseAnimating>::operator class CBaseAnimating __near *(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CHandle<CBaseAnimating>::operator CBaseAnimating *(CHandle<CBaseEntity> *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x10012460
// Name: public: bool CHandle<class CBaseEntity>::operator==(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHandle<CBaseEntity>::operator==(CHandle<CBaseEntity> *this, CBaseEntity *val)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return val == nullptr;
  else
    return g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == val;
}

//------------------------------------------------------------------------------
// Address: 0x10012B50
// Name: public: CHandle<class CBaseEntity>::CHandle<class CBaseEntity>(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
CHandle<CBaseEntity> *__thiscall CHandle<CBaseEntity>::CHandle<CBaseEntity>(
        CHandle<CBaseEntity> *this,
        CBaseEntity *pObj)
{
  this->m_Index = -1;
  if ( pObj != nullptr )
    this->m_Index = pObj->GetRefEHandle(this: pObj)->m_Index;
  else
    this->m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10012B90
// Name: public: bool CHandle<class CBaseEntity>::operator!=(class CBaseEntity __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CHandle<CBaseEntity>::operator!=(CHandle<CBaseEntity> *this, CBaseEntity *val)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return val != nullptr;
  else
    return g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity != val;
}

//------------------------------------------------------------------------------
// Address: 0x1001E7B0
// Name: public: bool CHandle<class CAI_BaseNPC>::operator!(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CHandle<CAI_BaseNPC>::operator!(CHandle<CAI_BaseNPC> *this)
{
  unsigned int m_Index; // eax

  m_Index = this->m_Index;
  return this->m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index)
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10043A60
// Name: public: class CHandle<class CBaseEntity> const __near & variant_t::Entity(void)const
// Source: json
//------------------------------------------------------------------------------
const CHandle<CBaseEntity> *__thiscall variant_t::Entity(variant_t *this)
{
  if ( this->fieldType == FIELD_EHANDLE )
    return &this->eVal;
  if ( (`variant_t::Entity'::`4'::`local static guard' & 1) == 0 )
    `variant_t::Entity'::`4'::`local static guard' |= 1u;
  `variant_t::Entity'::`4'::hNull.m_Index = -1;
  return &`variant_t::Entity'::`4'::hNull;
}

//------------------------------------------------------------------------------
// Address: 0x10270EF0
// Name: public: class CBaseHandle const __near & CHandle<class CBaseEntity>::operator=(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
CHandle<CBaseEntity> *__thiscall CHandle<CBaseEntity>::operator=(CHandle<CBaseEntity> *this, const CBaseEntity *val)
{
  if ( val != nullptr )
    this->m_Index = val->GetRefEHandle(this: val)->m_Index;
  else
    this->m_Index = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CA770
// Name: public: void CSGameState::OnHostageRescuedAll(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::OnHostageRescuedAll(CSGameState *this, IGameEvent *event)
{
  this->m_allHostagesRescued = true;
}

//------------------------------------------------------------------------------
// Address: 0x102CA780
// Name: public: void CSGameState::OnRoundEnd(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::OnRoundEnd(CSGameState *this, IGameEvent *event)
{
  this->m_isRoundOver = true;
}

//------------------------------------------------------------------------------
// Address: 0x102CA790
// Name: public: bool CSGameState::IsPlantedBombLocationKnown(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSGameState::IsPlantedBombLocationKnown(CSGameState *this)
{
  return this->m_bombState == 2 && this->m_isPlantedBombPosKnown;
}

//------------------------------------------------------------------------------
// Address: 0x102CA7A0
// Name: public: int CSGameState::GetPlantedBombsite(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSGameState::GetPlantedBombsite(CSGameState *this)
{
  if ( this->m_bombState == 2 )
    return this->m_plantedBombsite;
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x102CA7B0
// Name: public: int CSGameState::GetNextBombsiteToSearch(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSGameState::GetNextBombsiteToSearch(CSGameState *this)
{
  int m_bombsiteSearchIndex; // edx
  int m_bombsiteCount; // edi
  int *v3; // esi
  int result; // eax
  int v5; // eax

  if ( this->m_bombsiteCount <= 0 )
    return 0;
  while ( 1 )
  {
    m_bombsiteSearchIndex = this->m_bombsiteSearchIndex;
    m_bombsiteCount = this->m_bombsiteCount;
    if ( m_bombsiteSearchIndex < m_bombsiteCount )
      break;
LABEL_6:
    v5 = 0;
    if ( m_bombsiteCount > 0 )
    {
      do
        this->m_isBombsiteClear[v5++] = false;
      while ( v5 < this->m_bombsiteCount );
    }
    this->m_bombsiteSearchIndex = 0;
    if ( this->m_bombsiteCount <= 0 )
      return 0;
  }
  v3 = &this->m_bombsiteSearchOrder[m_bombsiteSearchIndex];
  while ( 1 )
  {
    result = *v3;
    if ( !this->m_isBombsiteClear[*v3] )
      break;
    ++m_bombsiteSearchIndex;
    ++v3;
    if ( m_bombsiteSearchIndex >= m_bombsiteCount )
      goto LABEL_6;
  }
  this->m_bombsiteSearchIndex = m_bombsiteSearchIndex;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CA810
// Name: public: void CSGameState::UpdatePlantedBomb(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::UpdatePlantedBomb(CSGameState *this, const Vector *pos)
{
  const CCSBotManager::Zone *ClosestZone; // eax

  ClosestZone = CCSBotManager::GetClosestZone(this: (CCSBotManager *)TheBots, pos);
  if ( ClosestZone != nullptr )
  {
    this->m_plantedBombsite = ClosestZone->m_index;
  }
  else
  {
    CONSOLE_ECHO(pszMsg: "ERROR: Bomb planted outside of a zone!\n");
    this->m_plantedBombsite = -1;
  }
  this->m_plantedBombPos = *pos;
  this->m_isPlantedBombPosKnown = true;
  if ( this->m_bombState != 2 )
    this->m_bombState = 2;
}

//------------------------------------------------------------------------------
// Address: 0x102CA870
// Name: public: void CSGameState::MarkBombsiteAsPlanted(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::MarkBombsiteAsPlanted(CSGameState *this, int zoneIndex)
{
  this->m_plantedBombsite = zoneIndex;
  if ( this->m_bombState != 2 )
    this->m_bombState = 2;
}

//------------------------------------------------------------------------------
// Address: 0x102CA890
// Name: public: void CSGameState::ClearBombsite(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::ClearBombsite(CSGameState *this, int zoneIndex)
{
  if ( zoneIndex >= 0 && zoneIndex < this->m_bombsiteCount )
    this->m_isBombsiteClear[zoneIndex] = true;
}

//------------------------------------------------------------------------------
// Address: 0x102CA8B0
// Name: public: bool CSGameState::IsBombsiteClear(int)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSGameState::IsBombsiteClear(CSGameState *this, int zoneIndex)
{
  return zoneIndex >= 0 && zoneIndex < this->m_bombsiteCount && this->m_isBombsiteClear[zoneIndex];
}

//------------------------------------------------------------------------------
// Address: 0x102CA8D0
// Name: public: void CSGameState::OnBombPlanted(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::OnBombPlanted(CSGameState *this, IGameEvent *event)
{
  int v3; // eax
  CBasePlayer *v4; // esi

  if ( this->m_bombState != 2 )
    this->m_bombState = 2;
  v3 = event->GetInt(this: event, a2: "userid", a3: 0);
  v4 = UTIL_PlayerByUserId(userID: v3);
  if ( CBaseEntity::GetTeamNumber(this: this->m_owner) == 2 && v4 != nullptr )
  {
    if ( (v4->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: v4);
    CSGameState::UpdatePlantedBomb(this, pos: &v4->m_vecAbsOrigin);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CA940
// Name: public: void CSGameState::OnBombDefused(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::OnBombDefused(CSGameState *this, IGameEvent *event)
{
  if ( this->m_bombState != DEFUSED )
    this->m_bombState = DEFUSED;
}

//------------------------------------------------------------------------------
// Address: 0x102CA950
// Name: public: void CSGameState::OnBombExploded(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::OnBombExploded(CSGameState *this, IGameEvent *event)
{
  if ( this->m_bombState != EXPLODED )
    this->m_bombState = EXPLODED;
}

//------------------------------------------------------------------------------
// Address: 0x102CA960
// Name: public: bool CSGameState::IsAtPlantedBombsite(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSGameState::IsAtPlantedBombsite(CSGameState *this)
{
  const CCSBotManager::Zone *ClosestZone; // eax
  bool result; // al
  Vector myOrigin; // [esp+4h] [ebp-Ch] BYREF

  result = this->m_bombState == 2
        && (GetCentroid(result: &myOrigin, player: this->m_owner),
            (ClosestZone = CCSBotManager::GetClosestZone(this: (CCSBotManager *)TheBots, pos: &myOrigin)) != nullptr)
        && this->m_plantedBombsite == ClosestZone->m_index;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102CA9B0
// Name: public: bool CSGameState::IsLooseBombLocationKnown(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSGameState::IsLooseBombLocationKnown(CSGameState *this)
{
  return this->m_bombState == LOOSE && this->m_lastSawLooseBomb.m_timestamp.m_Value > 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x102CA9E0
// Name: public: class Vector const __near * CSGameState::GetBombPosition(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CSGameState::GetBombPosition(CSGameState *this)
{
  CSGameState::BombState m_bombState; // eax
  __int32 v2; // eax

  m_bombState = this->m_bombState;
  if ( m_bombState != MOVING )
  {
    v2 = m_bombState - 1;
    if ( v2 != 0 )
    {
      if ( v2 == 1 && this->m_isPlantedBombPosKnown )
        return &this->m_plantedBombPos;
    }
    else if ( this->m_lastSawLooseBomb.m_timestamp.m_Value > 0.0 )
    {
      return &this->m_looseBombPos;
    }
  }
  else if ( this->m_lastSawBomber.m_timestamp.m_Value > 0.0 )
  {
    return &this->m_bomberPos;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CAA30
// Name: private: void CSGameState::InitializeHostageInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::InitializeHostageInfo(CSGameState *this)
{
  int v1; // ebx
  CHostage *v3; // ecx
  CSGameState::HostageInfo *v4; // edi
  CHostage *v5; // edi
  int m_hostageCount; // eax
  Vector *p_knownPos; // eax

  v1 = 0;
  this->m_hostageCount = 0;
  for ( *(_WORD *)&this->m_allHostagesRescued = 0; v1 < g_Hostages.m_Size; ++this->m_hostageCount )
  {
    v3 = g_Hostages.m_Memory.m_pMemory[v1];
    v4 = &this->m_hostage[this->m_hostageCount];
    if ( v3 != nullptr )
      v4->hostage.m_Index = v3->GetRefEHandle(this: v3)->m_Index;
    else
      v4->hostage.m_Index = -1;
    v5 = g_Hostages.m_Memory.m_pMemory[v1];
    if ( (v5->m_iEFlags & 0x800) != 0 )
      CBaseEntity::CalcAbsolutePosition(this: g_Hostages.m_Memory.m_pMemory[v1]);
    m_hostageCount = this->m_hostageCount;
    this->m_hostage[m_hostageCount].knownPos.x = v5->m_vecAbsOrigin.x;
    p_knownPos = &this->m_hostage[m_hostageCount].knownPos;
    ++v1;
    p_knownPos->y = v5->m_vecAbsOrigin.y;
    p_knownPos->z = v5->m_vecAbsOrigin.z;
    this->m_hostage[this->m_hostageCount].isValid = true;
    this->m_hostage[this->m_hostageCount].isAlive = true;
    this->m_hostage[this->m_hostageCount].isFree = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102CAB10
// Name: public: class Vector const __near * CSGameState::GetRandomFreeHostagePosition(void)const
// Source: json
//------------------------------------------------------------------------------
const Vector *__thiscall CSGameState::GetRandomFreeHostagePosition(CSGameState *this)
{
  CSGameState *v1; // edi
  Vector *v2; // ebx
  CSGameState::HostageInfo *m_hostage; // esi
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *v10; // eax
  unsigned int v11; // eax
  CHostage *m_pEntity; // ecx
  unsigned int v13; // eax
  CBaseEntity *v14; // edi
  Vector *v16; // eax
  int i; // [esp+4h] [ebp-10h]
  Vector *v19; // [esp+Ch] [ebp-8h]
  int freeCount; // [esp+10h] [ebp-4h]

  v1 = this;
  if ( this->m_owner == nullptr )
    return nullptr;
  if ( (_S2_263 & 1) == 0 )
    _S2_263 |= 1u;
  freeCount = 0;
  i = 0;
  if ( this->m_hostageCount <= 0 )
    return nullptr;
  v2 = freePos;
  v19 = freePos;
  m_hostage = this->m_hostage;
  do
  {
    if ( CBaseEntity::GetTeamNumber(this: v1->m_owner) == 3 )
    {
      m_Index = m_hostage->hostage.m_Index;
      if ( m_hostage->hostage.m_Index != -1 )
      {
        v5 = (unsigned __int16)m_Index;
        v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        m_Index >>= 16;
        if ( v6->m_SerialNumber == m_Index && v6->m_pEntity != nullptr )
        {
          v7 = v5;
          v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == m_Index;
          v9 = &g_pEntityList->m_EntPtrArray[v7];
          v10 = v8 ? v9->m_pEntity : nullptr;
          if ( v10->__vftable[22].GetRefEHandle(this: v10) != nullptr )
          {
            v11 = m_hostage->hostage.m_Index;
            if ( m_hostage->hostage.m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
            {
              m_pEntity = nullptr;
            }
            else
            {
              m_pEntity = (CHostage *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
            }
            if ( !CHostage::IsFollowingSomeone(this: m_pEntity) )
            {
              v13 = m_hostage->hostage.m_Index;
              ++freeCount;
              ++v19;
              if ( m_hostage->hostage.m_Index == -1
                || (m_Index = (unsigned int)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v13],
                    g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13)) )
              {
                v14 = nullptr;
              }
              else
              {
                v14 = *(CBaseEntity **)m_Index;
              }
              if ( (v14->m_iEFlags & 0x800) != 0 )
                CBaseEntity::CalcAbsolutePosition(this: v14);
              v2->x = v14->m_vecAbsOrigin.x;
              v2->y = v14->m_vecAbsOrigin.y;
              v2->z = v14->m_vecAbsOrigin.z;
              v2 = v19;
            }
          }
        }
        v1 = this;
      }
    }
    else if ( m_hostage->isValid )
    {
      ++freeCount;
      v16 = v2;
      v2->x = m_hostage->knownPos.x;
      v19 = ++v2;
      v16->y = m_hostage->knownPos.y;
      v16->z = m_hostage->knownPos.z;
    }
    ++m_hostage;
    ++i;
  }
  while ( i < v1->m_hostageCount );
  if ( freeCount != 0 )
    return &freePos[_RandomInt(this: (IUniformRandomStream *)m_Index, a2: 0, a3: freeCount - 1)];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x102CACC0
// Name: public: class CHostage __near * CSGameState::GetNearestVisibleFreeHostage(void)const
// Source: json
//------------------------------------------------------------------------------
CHostage *__thiscall CSGameState::GetNearestVisibleFreeHostage(CSGameState *this)
{
  CSGameState::HostageInfo *m_hostage; // edi
  unsigned int m_Index; // ecx
  int v4; // eax
  CEntInfo *v5; // edx
  unsigned int v6; // ecx
  int v7; // eax
  bool v8; // zf
  CEntInfo *v9; // eax
  IHandleEntity *v10; // eax
  unsigned int v11; // eax
  CHostage *m_pEntity; // ecx
  unsigned int v13; // eax
  CBaseEntity *v14; // esi
  unsigned int v15; // eax
  CHostage *v16; // ecx
  CCSBot *m_owner; // [esp-Ch] [ebp-34h]
  Vector pos; // [esp+0h] [ebp-28h] BYREF
  Vector myOrigin; // [esp+Ch] [ebp-1Ch] BYREF
  float rangeSq; // [esp+18h] [ebp-10h]
  CHostage *close; // [esp+1Ch] [ebp-Ch]
  int i; // [esp+20h] [ebp-8h]
  float closeRangeSq; // [esp+24h] [ebp-4h]

  m_owner = this->m_owner;
  close = nullptr;
  closeRangeSq = 1000000000.0;
  GetCentroid(result: &myOrigin, player: m_owner);
  i = 0;
  if ( this->m_hostageCount <= 0 )
    return nullptr;
  m_hostage = this->m_hostage;
  do
  {
    m_Index = m_hostage->hostage.m_Index;
    if ( m_hostage->hostage.m_Index != -1 )
    {
      v4 = (unsigned __int16)m_Index;
      v5 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v6 = HIWORD(m_Index);
      if ( v5->m_SerialNumber == v6 && v5->m_pEntity != nullptr )
      {
        v7 = v4;
        v8 = g_pEntityList->m_EntPtrArray[v7].m_SerialNumber == v6;
        v9 = &g_pEntityList->m_EntPtrArray[v7];
        v10 = v8 ? v9->m_pEntity : nullptr;
        if ( v10->__vftable[22].GetRefEHandle(this: v10) != nullptr )
        {
          v11 = m_hostage->hostage.m_Index;
          if ( m_hostage->hostage.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_SerialNumber != HIWORD(v11) )
          {
            m_pEntity = nullptr;
          }
          else
          {
            m_pEntity = (CHostage *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v11].m_pEntity;
          }
          if ( !CHostage::IsFollowingSomeone(this: m_pEntity) )
          {
            v13 = m_hostage->hostage.m_Index;
            if ( m_hostage->hostage.m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
            {
              v14 = nullptr;
            }
            else
            {
              v14 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
            }
            if ( (v14->m_iEFlags & 0x800) != 0 )
              CBaseEntity::CalcAbsolutePosition(this: v14);
            pos = v14->m_vecAbsOrigin;
            rangeSq = (float)((float)((float)(pos.x - myOrigin.x) * (float)(pos.x - myOrigin.x))
                            + (float)((float)(pos.y - myOrigin.y) * (float)(pos.y - myOrigin.y)))
                    + (float)((float)(pos.z - myOrigin.z) * (float)(pos.z - myOrigin.z));
            if ( closeRangeSq > rangeSq && CCSBot::IsVisible(this: this->m_owner, &pos, testFOV: false, ignore: nullptr) )
            {
              v15 = m_hostage->hostage.m_Index;
              if ( m_hostage->hostage.m_Index == -1
                || g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_SerialNumber != HIWORD(v15) )
              {
                v16 = nullptr;
              }
              else
              {
                v16 = (CHostage *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v15].m_pEntity;
              }
              close = v16;
              closeRangeSq = rangeSq;
            }
          }
        }
      }
    }
    ++m_hostage;
    ++i;
  }
  while ( i < this->m_hostageCount );
  return close;
}

//------------------------------------------------------------------------------
// Address: 0x102CAEA0
// Name: public: bool CSGameState::AreAllHostagesBeingRescued(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSGameState::AreAllHostagesBeingRescued(CSGameState *this)
{
  CSGameState *v1; // esi
  char v3; // bl
  CSGameState::HostageInfo *m_hostage; // edi
  unsigned int m_Index; // ecx
  int v6; // eax
  CEntInfo *v7; // edx
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // zf
  CEntInfo *v11; // eax
  CHostage *v12; // eax
  unsigned int v13; // eax
  CHostage *m_pEntity; // ecx
  int i; // [esp+4h] [ebp-8h]

  v1 = this;
  if ( this->m_allHostagesRescued )
    return false;
  v3 = 1;
  i = 0;
  if ( this->m_hostageCount <= 0 )
    return false;
  m_hostage = this->m_hostage;
  do
  {
    if ( CBaseEntity::GetTeamNumber(this: v1->m_owner) == 3 )
    {
      m_Index = m_hostage->hostage.m_Index;
      if ( m_hostage->hostage.m_Index != -1 )
      {
        v6 = (unsigned __int16)m_Index;
        v7 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
        v8 = HIWORD(m_Index);
        if ( v7->m_SerialNumber == v8 && v7->m_pEntity != nullptr )
        {
          v9 = v6;
          v10 = g_pEntityList->m_EntPtrArray[v9].m_SerialNumber == v8;
          v11 = &g_pEntityList->m_EntPtrArray[v9];
          v12 = v10 ? (CHostage *)v11->m_pEntity : nullptr;
          if ( CHostage::IsValid(this: v12) )
          {
            v13 = m_hostage->hostage.m_Index;
            if ( m_hostage->hostage.m_Index == -1
              || g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_SerialNumber != HIWORD(v13) )
            {
              m_pEntity = nullptr;
            }
            else
            {
              m_pEntity = (CHostage *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v13].m_pEntity;
            }
            if ( !CHostage::IsFollowingSomeone(this: m_pEntity) )
              return false;
            v3 = 0;
          }
        }
        v1 = this;
      }
    }
    else
    {
      if ( m_hostage->isValid && m_hostage->isAlive )
        return false;
      if ( m_hostage->isAlive )
        v3 = 0;
    }
    ++m_hostage;
    ++i;
  }
  while ( i < v1->m_hostageCount );
  return v3 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CAFB0
// Name: public: bool CSGameState::AreAllHostagesGone(void)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSGameState::AreAllHostagesGone(CSGameState *this)
{
  CSGameState::HostageInfo *m_hostage; // edi
  unsigned int m_Index; // ecx
  int v5; // eax
  CEntInfo *v6; // edx
  unsigned int v7; // ecx
  int v8; // eax
  CEntInfo *v9; // eax
  bool v10; // zf
  int i; // [esp+4h] [ebp-4h]

  if ( this->m_allHostagesRescued )
    return 1;
  i = 0;
  if ( this->m_hostageCount <= 0 )
    return 1;
  m_hostage = this->m_hostage;
  while ( CBaseEntity::GetTeamNumber(this: this->m_owner) != 3 )
  {
    if ( m_hostage->isValid )
    {
      v10 = !m_hostage->isAlive;
      goto LABEL_14;
    }
LABEL_15:
    ++m_hostage;
    if ( ++i >= this->m_hostageCount )
      return 1;
  }
  m_Index = m_hostage->hostage.m_Index;
  if ( m_hostage->hostage.m_Index == -1 )
    goto LABEL_15;
  v5 = (unsigned __int16)m_Index;
  v6 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v7 = HIWORD(m_Index);
  if ( v6->m_SerialNumber != v7 || v6->m_pEntity == nullptr )
    goto LABEL_15;
  v8 = v5;
  v10 = g_pEntityList->m_EntPtrArray[v8].m_SerialNumber == v7;
  v9 = &g_pEntityList->m_EntPtrArray[v8];
  if ( v10 )
    v10 = v9->m_pEntity->__vftable[22].GetRefEHandle(this: v9->m_pEntity) == nullptr;
  else
    v10 = (*(unsigned __int8 (__thiscall **)(_DWORD))(MEMORY[0] + 272))(a1: 0) == 0;
LABEL_14:
  if ( v10 )
    goto LABEL_15;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CB080
// Name: public: CSGameState::CSGameState(class CCSBot __near *)
// Source: json
//------------------------------------------------------------------------------
CSGameState *__userpurge CSGameState::CSGameState@<eax>(
        CSGameState *this@<ecx>,
        int a2@<edi>,
        int a3@<esi>,
        CCSBot *owner)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // eax
  IntervalTimer *p_m_lastSawBomber; // ecx
  IntervalTimer_vtbl *v7; // edx
  IntervalTimer_vtbl *v8; // edx
  CSGameState::HostageInfo *m_hostage; // eax
  int i; // ecx
  CountdownTimer_vtbl *v11; // edx
  CountdownTimer_vtbl *v12; // edx
  float *p_z; // eax
  int j; // ecx

  p_m_timestamp = &this->m_lastSawBomber.m_timestamp;
  p_m_lastSawBomber = &this->m_lastSawBomber;
  this->m_lastSawBomber.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v7 = p_m_lastSawBomber->__vftable;
  p_m_timestamp->m_Value = -1.0;
  ((void (__thiscall *)(IntervalTimer *, CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *, int, int))v7->NetworkStateChanged)(
    a1: p_m_lastSawBomber,
    a2: p_m_timestamp,
    a3: a2,
    a4: a3);
  this->m_lastSawLooseBomb.__vftable = (IntervalTimer_vtbl *)&IntervalTimer::`vftable';
  v8 = this->m_lastSawLooseBomb.__vftable;
  this->m_lastSawLooseBomb.m_timestamp.m_Value = -1.0;
  ((void (__stdcall *)(CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *))v8->NetworkStateChanged)(a1: &this->m_lastSawLooseBomb.m_timestamp);
  m_hostage = this->m_hostage;
  for ( i = 11; i >= 0; --i )
  {
    m_hostage->hostage.m_Index = -1;
    ++m_hostage;
  }
  this->m_validateInterval.__vftable = (CountdownTimer_vtbl *)&CountdownTimer::`vftable';
  v11 = this->m_validateInterval.__vftable;
  this->m_validateInterval.m_duration.m_Value = 0.0;
  ((void (__cdecl *)(CNetworkVarBase<float,CountdownTimer::NetworkVar_m_duration> *))v11->NetworkStateChanged)(a1: &this->m_validateInterval.m_duration);
  v12 = this->m_validateInterval.__vftable;
  this->m_validateInterval.m_timestamp.m_Value = -1.0;
  v12->NetworkStateChanged(this: &this->m_validateInterval, a2: &this->m_validateInterval.m_timestamp);
  this->m_owner = owner;
  this->m_isRoundOver = false;
  this->m_bombState = MOVING;
  if ( this->m_lastSawBomber.m_timestamp.m_Value != -1.0 )
  {
    this->m_lastSawBomber.NetworkStateChanged(this: &this->m_lastSawBomber, a2: &this->m_lastSawBomber.m_timestamp);
    this->m_lastSawBomber.m_timestamp.m_Value = -1.0;
  }
  if ( this->m_lastSawLooseBomb.m_timestamp.m_Value != -1.0 )
  {
    this->m_lastSawLooseBomb.NetworkStateChanged(
      this: &this->m_lastSawLooseBomb,
      a2: &this->m_lastSawLooseBomb.m_timestamp);
    this->m_lastSawLooseBomb.m_timestamp.m_Value = -1.0;
  }
  this->m_isPlantedBombPosKnown = false;
  this->m_plantedBombsite = -1;
  this->m_bombsiteCount = 0;
  this->m_bombsiteSearchIndex = 0;
  p_z = &this->m_hostage[0].knownPos.z;
  for ( j = 12; j != 0; --j )
  {
    *(p_z - 3) = NAN;
    *((_WORD *)p_z + 2) = 0;
    *((_BYTE *)p_z + 6) = 1;
    *(p_z - 2) = 0.0;
    *(p_z - 1) = 0.0;
    *p_z = 0.0;
    p_z += 5;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x102CB1D0
// Name: public: void CSGameState::Reset(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::Reset(CSGameState *this)
{
  CNetworkVarBase<float,IntervalTimer::NetworkVar_m_timestamp> *p_m_timestamp; // edi
  int v3; // ecx
  int v4; // eax
  int *m_bombsiteSearchOrder; // ecx
  int v6; // edi
  IUniformRandomStream **v7; // ebx
  int v8; // eax
  IUniformRandomStream *swap; // [esp+0h] [ebp-4h]

  p_m_timestamp = &this->m_lastSawBomber.m_timestamp;
  this->m_isRoundOver = false;
  this->m_bombState = MOVING;
  if ( this->m_lastSawBomber.m_timestamp.m_Value != -1.0 )
  {
    this->m_lastSawBomber.NetworkStateChanged(this: &this->m_lastSawBomber, a2: p_m_timestamp);
    p_m_timestamp->m_Value = -1.0;
  }
  if ( this->m_lastSawLooseBomb.m_timestamp.m_Value != -1.0 )
  {
    this->m_lastSawLooseBomb.NetworkStateChanged(
      this: &this->m_lastSawLooseBomb,
      a2: &this->m_lastSawLooseBomb.m_timestamp);
    this->m_lastSawLooseBomb.m_timestamp.m_Value = -1.0;
  }
  this->m_isPlantedBombPosKnown = false;
  this->m_plantedBombsite = -1;
  v3 = *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[456];
  v4 = 0;
  this->m_bombsiteCount = v3;
  if ( v3 > 0 )
  {
    m_bombsiteSearchOrder = this->m_bombsiteSearchOrder;
    do
    {
      this->m_isBombsiteClear[v4] = false;
      *m_bombsiteSearchOrder++ = v4++;
    }
    while ( v4 < this->m_bombsiteCount );
  }
  v6 = 0;
  if ( this->m_bombsiteCount > 0 )
  {
    v7 = (IUniformRandomStream **)this->m_bombsiteSearchOrder;
    do
    {
      swap = *v7;
      v8 = _RandomInt(this: *v7, a2: v6, a3: this->m_bombsiteCount - 1);
      *v7 = (IUniformRandomStream *)this->m_bombsiteSearchOrder[v8];
      ++v6;
      this->m_bombsiteSearchOrder[v8] = (int)swap;
      ++v7;
    }
    while ( v6 < this->m_bombsiteCount );
  }
  this->m_bombsiteSearchIndex = 0;
  CSGameState::InitializeHostageInfo(this);
}

//------------------------------------------------------------------------------
// Address: 0x102CB2C0
// Name: public: void CSGameState::OnRoundStart(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CSGameState::OnRoundStart(CSGameState *this, IGameEvent *event)
{
  CSGameState::Reset(this);
}

//------------------------------------------------------------------------------
// Address: 0x102CB2D0
// Name: public: void CSGameState::UpdateLooseBomb(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::UpdateLooseBomb(CSGameState *this, const Vector *pos)
{
  IntervalTimer *p_m_lastSawLooseBomb; // edi
  double v4; // st7
  float *p_m_Value; // edi
  float posa; // [esp+10h] [ebp+8h]

  this->m_looseBombPos = *pos;
  p_m_lastSawLooseBomb = &this->m_lastSawLooseBomb;
  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_lastSawLooseBomb);
  p_m_Value = &p_m_lastSawLooseBomb->m_timestamp.m_Value;
  if ( *p_m_Value != v4 )
  {
    (*(void (__thiscall **)(float *, float *))(*((_DWORD *)p_m_Value - 1) + 4))(a1: p_m_Value - 1, a2: p_m_Value);
    posa = v4;
    *p_m_Value = posa;
  }
  if ( this->m_bombState != LOOSE )
    this->m_bombState = LOOSE;
}

//------------------------------------------------------------------------------
// Address: 0x102CB330
// Name: public: void CSGameState::UpdateBomber(class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSGameState::UpdateBomber(CSGameState *this, const Vector *pos)
{
  IntervalTimer *p_m_lastSawBomber; // edi
  double v4; // st7
  float *p_m_Value; // edi
  float posa; // [esp+10h] [ebp+8h]

  this->m_bomberPos = *pos;
  p_m_lastSawBomber = &this->m_lastSawBomber;
  v4 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_lastSawBomber);
  p_m_Value = &p_m_lastSawBomber->m_timestamp.m_Value;
  if ( *p_m_Value != v4 )
  {
    (*(void (__thiscall **)(float *, float *))(*((_DWORD *)p_m_Value - 1) + 4))(a1: p_m_Value - 1, a2: p_m_Value);
    posa = v4;
    *p_m_Value = posa;
  }
  if ( this->m_bombState != MOVING )
    this->m_bombState = MOVING;
}

//------------------------------------------------------------------------------
// Address: 0x102CB390
// Name: public: class CHostage __near * CSGameState::GetNearestFreeHostage(class Vector __near *)const
// Source: json
//------------------------------------------------------------------------------
CHostage *__thiscall CSGameState::GetNearestFreeHostage(CSGameState *this, Vector *knowPos)
{
  CSGameState *v2; // esi
  CCSBot *m_owner; // ecx
  CHostage *v5; // ecx
  CSGameState::HostageInfo *m_hostage; // edi
  CHandle<CBaseEntity> v7; // eax
  CHostage *m_pEntity; // ebx
  unsigned int m_Index; // ecx
  int v10; // eax
  CEntInfo *v11; // edx
  unsigned int v12; // ecx
  int v13; // eax
  bool v14; // zf
  CEntInfo *v15; // eax
  CHostage *v16; // eax
  unsigned int v17; // eax
  CHostage *v18; // ecx
  CBaseEntity *v19; // esi
  float z; // xmm0_4
  CNavArea *NearestNavArea; // eax
  double v22; // st7
  Vector *v23; // eax
  Vector closePos; // [esp+18h] [ebp-30h] BYREF
  Vector hostagePos; // [esp+24h] [ebp-24h] BYREF
  CSGameState *v26; // [esp+30h] [ebp-18h]
  float travelDistance; // [esp+34h] [ebp-14h]
  CNavArea *startArea; // [esp+38h] [ebp-10h]
  CHostage *close; // [esp+3Ch] [ebp-Ch]
  int i; // [esp+40h] [ebp-8h]
  float closeDistance; // [esp+44h] [ebp-4h]

  v2 = this;
  m_owner = this->m_owner;
  v26 = v2;
  if ( m_owner == nullptr )
    return nullptr;
  startArea = m_owner->GetLastKnownArea(this: m_owner);
  if ( startArea == nullptr )
    return nullptr;
  v5 = nullptr;
  memset((void *)&closePos, 0, sizeof(closePos));
  close = nullptr;
  closeDistance = 1.0e10;
  i = 0;
  if ( v2->m_hostageCount <= 0 )
    goto LABEL_34;
  m_hostage = v2->m_hostage;
  do
  {
    v7.m_Index = m_hostage->hostage.m_Index;
    if ( m_hostage->hostage.m_Index == -1
      || g_pEntityList->m_EntPtrArray[LOWORD(v7.m_Index)].m_SerialNumber != HIWORD(v7.m_Index) )
    {
      m_pEntity = nullptr;
    }
    else
    {
      m_pEntity = (CHostage *)g_pEntityList->m_EntPtrArray[LOWORD(v7.m_Index)].m_pEntity;
    }
    if ( CBaseEntity::GetTeamNumber(this: v2->m_owner) == 3 )
    {
      m_Index = m_hostage->hostage.m_Index;
      if ( m_hostage->hostage.m_Index == -1 )
        goto LABEL_32;
      v10 = (unsigned __int16)m_Index;
      v11 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v12 = HIWORD(m_Index);
      if ( v11->m_SerialNumber != v12 || v11->m_pEntity == nullptr )
        goto LABEL_32;
      v13 = v10;
      v14 = g_pEntityList->m_EntPtrArray[v13].m_SerialNumber == v12;
      v15 = &g_pEntityList->m_EntPtrArray[v13];
      v16 = v14 ? (CHostage *)v15->m_pEntity : nullptr;
      if ( !CHostage::IsValid(this: v16) )
        goto LABEL_32;
      v17 = m_hostage->hostage.m_Index;
      if ( m_hostage->hostage.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_SerialNumber != HIWORD(v17) )
      {
        v18 = nullptr;
      }
      else
      {
        v18 = (CHostage *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v17].m_pEntity;
      }
      if ( CHostage::IsFollowingSomeone(this: v18) )
        goto LABEL_32;
      v19 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: (CHandle<CBaseEntity> *)m_hostage);
      if ( (v19->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v19);
      hostagePos.x = v19->m_vecAbsOrigin.x;
      hostagePos.y = v19->m_vecAbsOrigin.y;
      z = v19->m_vecAbsOrigin.z;
    }
    else
    {
      if ( !m_hostage->isValid )
        goto LABEL_32;
      hostagePos.x = m_hostage->knownPos.x;
      hostagePos.y = m_hostage->knownPos.y;
      z = m_hostage->knownPos.z;
    }
    hostagePos.z = z;
    NearestNavArea = CNavMesh::GetNearestNavArea(
                       this: TheNavMesh,
                       pos: &hostagePos,
                       anyZ: false,
                       maxDist: 10000.0,
                       checkLOS: false,
                       checkGround: true);
    if ( NearestNavArea != nullptr )
    {
      v22 = NavAreaTravelDistance<ShortestPathCost>(
              startArea,
              endArea: NearestNavArea,
              costFunc: (ShortestPathCost *)&knowPos + 3,
              maxPathLength: 0.0);
      travelDistance = v22;
      if ( v22 >= 0.0 && closeDistance > travelDistance )
      {
        closeDistance = travelDistance;
        closePos = hostagePos;
        close = m_pEntity;
      }
    }
LABEL_32:
    v2 = v26;
    ++m_hostage;
    ++i;
  }
  while ( i < v26->m_hostageCount );
  v5 = close;
LABEL_34:
  v23 = knowPos;
  if ( knowPos != nullptr && v5 != nullptr )
  {
    knowPos->x = closePos.x;
    v23->y = closePos.y;
    v23->z = closePos.z;
  }
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x102CB600
// Name: public: unsigned char CSGameState::ValidateHostagePositions(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int8 __thiscall CSGameState::ValidateHostagePositions(CSGameState *this)
{
  CEffectsServer *p_m_validateInterval; // edi
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi
  double v4; // st7
  CSGameState *v5; // edi
  int m_hostageCount; // ecx
  int v7; // esi
  bool *p_isValid; // eax
  int j; // edx
  CSGameState::HostageInfo *m_hostage; // esi
  unsigned int m_Index; // ecx
  int v12; // eax
  CEntInfo *v13; // edx
  unsigned int v14; // ecx
  int v15; // eax
  bool v16; // zf
  CBaseEntity **v17; // eax
  CBaseEntity *v18; // edi
  float z; // xmm0_4
  CCSBot **p_m_owner; // edi
  CCSBot *m_owner; // ecx
  unsigned int v22; // eax
  IHandleEntity *v23; // ecx
  unsigned int v24; // eax
  CHostage *v25; // ecx
  unsigned int v26; // eax
  CBaseEntity *v27; // edi
  float y; // xmm2_4
  float v29; // xmm0_4
  CCSBot *v30; // ecx
  unsigned int v31; // eax
  CHostage *m_pEntity; // ecx
  unsigned int v33; // eax
  CHostage *v34; // ecx
  unsigned int v35; // eax
  CBaseEntity *v36; // edi
  int v37; // ecx
  int v38; // edx
  bool *v39; // eax
  Vector pos; // [esp+8h] [ebp-1Ch] BYREF
  int startValidCount; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  CSGameState *v43; // [esp+1Ch] [ebp-8h]
  unsigned __int8 status; // [esp+23h] [ebp-1h]

  p_m_validateInterval = (CEffectsServer *)&this->m_validateInterval;
  v43 = this;
  p_m_timestamp = &this->m_validateInterval.m_timestamp;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_validateInterval) <= (double)this->m_validateInterval.m_timestamp.m_Value )
    return 0;
  v4 = IntervalTimer::Now(this: p_m_validateInterval) + 0.5;
  *(float *)&startValidCount = v4;
  if ( p_m_timestamp->m_Value != v4 )
  {
    ((void (__thiscall *)(CEffectsServer *, bool *))p_m_validateInterval->dtr_IPredictionSystem)(
      a1: p_m_validateInterval,
      a2: &p_m_validateInterval->m_bSuppressEvent);
    SLODWORD(p_m_timestamp->m_Value) = startValidCount;
  }
  if ( *(float *)&p_m_validateInterval->m_pNextSystem != 0.5 )
  {
    ((void (__thiscall *)(CEffectsServer *, IPredictionSystem **))p_m_validateInterval->dtr_IPredictionSystem)(
      a1: p_m_validateInterval,
      a2: &p_m_validateInterval->m_pNextSystem);
    p_m_validateInterval->m_pNextSystem = (IPredictionSystem *)1056964608;
  }
  v5 = v43;
  m_hostageCount = v43->m_hostageCount;
  *(float *)&v7 = 0.0;
  status = 0;
  *(float *)&startValidCount = 0.0;
  if ( m_hostageCount > 0 )
  {
    p_isValid = &v43->m_hostage[0].isValid;
    for ( j = m_hostageCount; j != 0; --j )
    {
      if ( *p_isValid )
        ++v7;
      p_isValid += 20;
    }
    startValidCount = v7;
  }
  i = 0;
  if ( m_hostageCount > 0 )
  {
    m_hostage = v43->m_hostage;
    while ( 1 )
    {
      m_Index = m_hostage->hostage.m_Index;
      if ( m_hostage->hostage.m_Index == -1 )
        goto LABEL_66;
      v12 = (unsigned __int16)m_Index;
      v13 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
      v14 = HIWORD(m_Index);
      if ( v13->m_SerialNumber != v14 || v13->m_pEntity == nullptr )
        goto LABEL_66;
      v15 = v12;
      v16 = g_pEntityList->m_EntPtrArray[v15].m_SerialNumber == v14;
      v17 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[v15];
      if ( v16 )
        v18 = *v17;
      else
        v18 = nullptr;
      if ( (v18->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v18);
      pos.x = v18->m_vecAbsOrigin.x;
      pos.y = v18->m_vecAbsOrigin.y;
      z = v18->m_vecAbsOrigin.z;
      p_m_owner = &v43->m_owner;
      m_owner = v43->m_owner;
      pos.z = z + 35.5;
      if ( CCSBot::IsVisible(this: m_owner, &pos, testFOV: true, ignore: nullptr) )
        break;
      if ( !m_hostage->isValid )
        goto LABEL_66;
      y = m_hostage->knownPos.y;
      v29 = m_hostage->knownPos.z + 35.5;
      v30 = *p_m_owner;
      pos.x = m_hostage->knownPos.x;
      pos.y = y;
      pos.z = v29;
      if ( !CCSBot::IsVisible(this: v30, &pos, testFOV: true, ignore: nullptr) )
        goto LABEL_66;
      v31 = m_hostage->hostage.m_Index;
      if ( m_hostage->hostage.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v31].m_SerialNumber != HIWORD(v31) )
      {
        m_pEntity = nullptr;
      }
      else
      {
        m_pEntity = (CHostage *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v31].m_pEntity;
      }
      if ( CHostage::IsValid(this: m_pEntity) )
      {
        v33 = m_hostage->hostage.m_Index;
        if ( m_hostage->hostage.m_Index == -1
          || g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_SerialNumber != HIWORD(v33) )
        {
          v34 = nullptr;
        }
        else
        {
          v34 = (CHostage *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v33].m_pEntity;
        }
        if ( !CHostage::IsFollowingSomeone(this: v34) )
        {
          v35 = m_hostage->hostage.m_Index;
          if ( m_hostage->hostage.m_Index == -1
            || g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_SerialNumber != HIWORD(v35) )
          {
            v36 = nullptr;
          }
          else
          {
            v36 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v35].m_pEntity;
          }
          if ( (v36->m_iEFlags & 0x800) != 0 )
            CBaseEntity::CalcAbsolutePosition(this: v36);
          if ( (float)((float)((float)((float)(v36->m_vecAbsOrigin.y - m_hostage->knownPos.y)
                                     * (float)(v36->m_vecAbsOrigin.y - m_hostage->knownPos.y))
                             + (float)((float)(v36->m_vecAbsOrigin.x - m_hostage->knownPos.x)
                                     * (float)(v36->m_vecAbsOrigin.x - m_hostage->knownPos.x)))
                     + (float)((float)(v36->m_vecAbsOrigin.z - m_hostage->knownPos.z)
                             * (float)(v36->m_vecAbsOrigin.z - m_hostage->knownPos.z))) <= 2500.0 )
            goto LABEL_66;
        }
        status |= 2u;
LABEL_65:
        m_hostage->isValid = false;
        goto LABEL_66;
      }
      status |= 1u;
      *(_WORD *)&m_hostage->isValid = 0;
LABEL_66:
      v5 = v43;
      ++m_hostage;
      if ( ++i >= v43->m_hostageCount )
      {
        v7 = startValidCount;
        goto LABEL_68;
      }
    }
    v22 = m_hostage->hostage.m_Index;
    if ( m_hostage->hostage.m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_SerialNumber != HIWORD(v22) )
    {
      v23 = nullptr;
    }
    else
    {
      v23 = g_pEntityList->m_EntPtrArray[(unsigned __int16)v22].m_pEntity;
    }
    if ( v23->__vftable[22].GetRefEHandle(this: v23) == nullptr )
    {
      if ( m_hostage->isAlive )
        status |= 1u;
      *(_WORD *)&m_hostage->isValid = 0;
      goto LABEL_66;
    }
    v24 = m_hostage->hostage.m_Index;
    if ( m_hostage->hostage.m_Index == -1
      || g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_SerialNumber != HIWORD(v24) )
    {
      v25 = nullptr;
    }
    else
    {
      v25 = (CHostage *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v24].m_pEntity;
    }
    if ( !CHostage::IsFollowingSomeone(this: v25) )
    {
      v26 = m_hostage->hostage.m_Index;
      if ( m_hostage->hostage.m_Index == -1
        || g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_SerialNumber != HIWORD(v26) )
      {
        v27 = nullptr;
      }
      else
      {
        v27 = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v26].m_pEntity;
      }
      if ( (v27->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v27);
      m_hostage->knownPos.x = v27->m_vecAbsOrigin.x;
      m_hostage->knownPos.y = v27->m_vecAbsOrigin.y;
      m_hostage->knownPos.z = v27->m_vecAbsOrigin.z;
      m_hostage->isValid = true;
      goto LABEL_66;
    }
    goto LABEL_65;
  }
LABEL_68:
  v37 = v5->m_hostageCount;
  v38 = 0;
  if ( v37 <= 0 )
    goto LABEL_74;
  v39 = &v5->m_hostage[0].isValid;
  do
  {
    if ( *v39 )
      ++v38;
    v39 += 20;
    --v37;
  }
  while ( v37 != 0 );
  if ( v38 == 0 )
  {
LABEL_74:
    if ( v7 > 0 )
      return status & 0xF9 | 4;
  }
  return status;
}

//------------------------------------------------------------------------------
// Address: 0x10270F20
// Name: bool ForEachPlayer<class RevertBotsFunctor>(class RevertBotsFunctor __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char __cdecl ForEachPlayer<RevertBotsFunctor>(RevertBotsFunctor *func)
{
  int v1; // edi
  CBasePlayer *v2; // eax
  CBasePlayer *v3; // esi
  edict_t *m_pPev; // eax

  v1 = 1;
  if ( gpGlobals->maxClients < 1 )
    return 1;
  while ( 1 )
  {
    v2 = UTIL_PlayerByIndex(playerIndex: v1);
    v3 = v2;
    if ( v2 != nullptr )
    {
      m_pPev = v2->m_Network.m_pPev;
      if ( m_pPev != nullptr
        && m_pPev - gpGlobals->pEdicts != 0
        && v3->IsPlayer(this: v3)
        && v3->m_iConnected != PlayerDisconnected
        && !RevertBotsFunctor::operator()(this: func, basePlayer: v3) )
      {
        break;
      }
    }
    if ( ++v1 > gpGlobals->maxClients )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102CB9F0
// Name: __CreateCServerGameTagsIServerGameTags_interface_31
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CServerGameTags *__cdecl _CreateCServerGameTagsIServerGameTags_interface_31()
{
  return &_g_CServerGameTags_singleton_31;
}
