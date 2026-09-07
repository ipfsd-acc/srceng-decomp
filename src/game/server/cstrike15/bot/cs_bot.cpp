// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/server/cstrike15/bot/cs_bot.cpp
// Functions: 54
// ============================================================

#include "game\server\cstrike15\bot\cs_bot.h"

//------------------------------------------------------------------------------
// Address: 0x102A6960
// Name: public: virtual struct datamap_t __near * CCSBot::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CCSBot::GetDataDescMap(CCSBot *this)
{
  return &CCSBot::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x102A6970
// Name: public: bool CCSBot::IsBusy(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsBusy(CCSBot *this)
{
  CCSBot::TaskType m_task; // eax
  bool result; // al

  if ( CCSBot::IsAttacking(this) )
    return true;
  if ( CCSBot::IsBuying(this) )
    return true;
  if ( CCSBot::IsDefusingBomb(this) )
    return true;
  m_task = this->m_task;
  if ( m_task == PLANT_BOMB )
    return true;
  if ( m_task == RESCUE_HOSTAGES )
    return true;
  result = CCSBot::IsSniping(this);
  if ( result )
    return true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A69C0
// Name: public: bool CCSBot::CanSeePlantedBomb(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::CanSeePlantedBomb(CCSBot *this)
{
  const Vector *BombPosition; // eax
  bool result; // al

  result = false;
  if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1
    && this->m_gameState.m_bombState == 2 )
  {
    BombPosition = CSGameState::GetBombPosition(this: &this->m_gameState);
    if ( BombPosition != nullptr && CCSBot::IsVisible(this, pos: BombPosition, testFOV: true, ignore: nullptr) )
      return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A6A10
// Name: public: void CCSBot::GetOffLadder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::GetOffLadder(CCSBot *this)
{
  if ( this->m_pathLadder != nullptr )
  {
    this->Jump(this, a2: true);
    this->m_isStopping = false;
    this->m_pathLength = 0;
    this->m_pathLadder = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A6A50
// Name: public: float CCSBot::GetHidingSpotCheckTimestamp(class HidingSpot __near *)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetHidingSpotCheckTimestamp(CCSBot *this, HidingSpot *spot)
{
  int m_checkedHidingSpotCount; // esi
  int v3; // eax
  CCSBot::HidingSpotCheckInfo *i; // edx

  m_checkedHidingSpotCount = this->m_checkedHidingSpotCount;
  v3 = 0;
  if ( m_checkedHidingSpotCount <= 0 )
    return -999999.88;
  for ( i = this->m_checkedHidingSpot; i->spot->m_id != spot->m_id; ++i )
  {
    if ( ++v3 >= m_checkedHidingSpotCount )
      return -999999.88;
  }
  return this->m_checkedHidingSpot[v3].timestamp;
}

//------------------------------------------------------------------------------
// Address: 0x102A6AA0
// Name: public: void CCSBot::SetHidingSpotCheckTimestamp(class HidingSpot __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetHidingSpotCheckTimestamp(CCSBot *this, HidingSpot *spot)
{
  float curtime; // xmm2_4
  HidingSpot *v3; // edx
  int m_checkedHidingSpotCount; // esi
  int v5; // edi
  int v6; // eax
  float v7; // xmm0_4
  float *p_timestamp; // edx
  int leastRecent; // [esp+0h] [ebp-4h]

  curtime = gpGlobals->curtime;
  v3 = spot;
  m_checkedHidingSpotCount = this->m_checkedHidingSpotCount;
  v5 = 0;
  v6 = 0;
  v7 = curtime + 1.0;
  leastRecent = 0;
  if ( m_checkedHidingSpotCount <= 0 )
  {
LABEL_8:
    if ( m_checkedHidingSpotCount >= 64 )
    {
      this->m_checkedHidingSpot[v5].spot = v3;
      this->m_checkedHidingSpot[v5].timestamp = gpGlobals->curtime;
    }
    else
    {
      this->m_checkedHidingSpot[m_checkedHidingSpotCount].spot = v3;
      this->m_checkedHidingSpot[this->m_checkedHidingSpotCount++].timestamp = gpGlobals->curtime;
    }
  }
  else
  {
    p_timestamp = &this->m_checkedHidingSpot[0].timestamp;
    while ( *(_DWORD *)(*((_DWORD *)p_timestamp - 1) + 16) != spot->m_id )
    {
      if ( v7 > *p_timestamp )
      {
        v7 = *p_timestamp;
        leastRecent = v6;
      }
      ++v6;
      p_timestamp += 2;
      if ( v6 >= m_checkedHidingSpotCount )
      {
        v3 = spot;
        v5 = leastRecent;
        goto LABEL_8;
      }
    }
    this->m_checkedHidingSpot[v6].timestamp = curtime;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A6B70
// Name: public: void CCSBot::IncreaseMorale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::IncreaseMorale(CCSBot *this)
{
  CCSBot::MoraleType m_morale; // eax

  m_morale = this->m_morale;
  if ( m_morale < EXCELLENT )
    this->m_morale = m_morale + 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A6B90
// Name: public: void CCSBot::DecreaseMorale(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::DecreaseMorale(CCSBot *this)
{
  CCSBot::MoraleType m_morale; // eax

  m_morale = this->m_morale;
  if ( m_morale > TERRIBLE )
    this->m_morale = m_morale - 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A6BB0
// Name: public: bool CCSBot::IsSafe(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsSafe(CCSBot *this)
{
  return this->m_safeTime > (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]);
}

//------------------------------------------------------------------------------
// Address: 0x102A6BE0
// Name: public: bool CCSBot::IsWellPastSafe(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsWellPastSafe(CCSBot *this)
{
  return (float)(gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]) > (float)(this->m_safeTime * 2.0);
}

//------------------------------------------------------------------------------
// Address: 0x102A6C20
// Name: public: float CCSBot::GetSafeTimeRemaining(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetSafeTimeRemaining(CCSBot *this)
{
  return this->m_safeTime - (gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696]);
}

//------------------------------------------------------------------------------
// Address: 0x102A6C40
// Name: private: void CCSBot::AdjustSafeTime(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::AdjustSafeTime(CCSBot *this)
{
  float v1; // xmm0_4

  v1 = gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696];
  if ( this->m_safeTime > v1 )
    this->m_safeTime = v1 - 2.0;
}

//------------------------------------------------------------------------------
// Address: 0x102A6C80
// Name: public: bool CCSBot::HasNotSeenEnemyForLongTime(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::HasNotSeenEnemyForLongTime(CCSBot *this)
{
  return (float)(gpGlobals->curtime - this->m_lastSawEnemyTimestamp) > 30.0;
}

//------------------------------------------------------------------------------
// Address: 0x102A6CB0
// Name: public: char const __near * CCSBot::GetTaskName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCSBot::GetTaskName(CCSBot *this)
{
  return name[this->m_task];
}

//------------------------------------------------------------------------------
// Address: 0x102A6CC0
// Name: public: char const __near * CCSBot::GetMoraleName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCSBot::GetMoraleName(CCSBot *this)
{
  return name_0[this->m_morale + 3];
}

//------------------------------------------------------------------------------
// Address: 0x102A6E80
// Name: public: class CNavArea __near * CNavArea::GetAdjacentArea(enum NavDirType,int)const
// Source: json
//------------------------------------------------------------------------------
CNavArea *__thiscall CNavArea::GetAdjacentArea(CNavArea *this, NavDirType dir, int i)
{
  CUtlVectorUltraConservative<NavConnect,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // esi
  int v4; // eax

  m_pData = this->m_connect[dir].m_pData;
  v4 = 0;
  if ( m_pData->m_Size <= 0 )
    return nullptr;
  while ( i != 0 )
  {
    ++v4;
    --i;
    if ( v4 >= m_pData->m_Size )
      return nullptr;
  }
  return m_pData->m_Elements[v4].area;
}

//------------------------------------------------------------------------------
// Address: 0x102A6EB0
// Name: class Vector GetCentroid(class CBaseEntity const __near *)
// Source: json
//------------------------------------------------------------------------------
Vector *__cdecl GetCentroid(Vector *result, CBaseEntity *player)
{
  float z; // ecx
  const Vector *(__thiscall *OBBMins)(struct CBaseEntity::NetworkVar_m_Collision *); // eax
  int v4; // ebx
  int savedregs; // [esp+Ch] [ebp+0h] BYREF

  if ( (player->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: player, a2: (int)&savedregs);
  z = player->m_vecAbsOrigin.z;
  OBBMins = player->m_Collision.OBBMins;
  *(_QWORD *)&result->x = *(_QWORD *)&player->m_vecAbsOrigin.x;
  result->z = z;
  v4 = (int)OBBMins(this: &player->m_Collision);
  result->z = (float)((float)(player->m_Collision.OBBMaxs(this: &player->m_Collision)->z - *(float *)(v4 + 8)) * 0.5)
            + result->z;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A6F30
// Name: public: class CBaseEntity __near * CCSBotManager::GetLooseBomb(void)
// Source: json
//------------------------------------------------------------------------------
CBaseEntity *__thiscall CCSBotManager::GetLooseBomb(CCSBotManager *this)
{
  unsigned int m_Index; // ecx

  m_Index = this->m_looseBomb.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    return nullptr;
  else
    return (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
}

//------------------------------------------------------------------------------
// Address: 0x102A6F60
// Name: public: int CCSBot::GetNearbyEnemyCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSBot::GetNearbyEnemyCount(CCSBot *this)
{
  int m_nearbyEnemyCount; // edi

  m_nearbyEnemyCount = this->m_nearbyEnemyCount;
  if ( CBot<CCSPlayer>::GetEnemiesRemaining(this) >= m_nearbyEnemyCount )
    return m_nearbyEnemyCount;
  else
    return CBot<CCSPlayer>::GetEnemiesRemaining(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A6F90
// Name: public: int CCSBot::GetNearbyFriendCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSBot::GetNearbyFriendCount(CCSBot *this)
{
  int m_nearbyFriendCount; // edi

  m_nearbyFriendCount = this->m_nearbyFriendCount;
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this) >= m_nearbyFriendCount )
    return m_nearbyFriendCount;
  else
    return CBot<CCSPlayer>::GetFriendsRemaining(this);
}

//------------------------------------------------------------------------------
// Address: 0x102A6FC0
// Name: int GetBotFollowCount(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetBotFollowCount(CCSPlayer *leader)
{
  int v1; // edi
  int i; // ebx
  CBasePlayer *v3; // eax
  CBasePlayer *v4; // esi
  _DWORD *v5; // eax
  unsigned int v6; // eax
  CCSPlayer *m_pEntity; // ecx

  v1 = 1;
  for ( i = 0; v1 <= gpGlobals->maxClients; ++v1 )
  {
    v3 = UTIL_PlayerByIndex(playerIndex: v1);
    v4 = v3;
    if ( v3 != nullptr && v3->IsBot(this: v3) && v4->IsAlive(this: v4) )
    {
      v5 = __RTDynamicCast(
             inptr: v4,
             VfDelta: 0,
             SrcType: &CBasePlayer `RTTI Type Descriptor',
             TargetType: &CCSBot `RTTI Type Descriptor',
             isReference: 0);
      if ( v5 != nullptr )
      {
        v6 = v5[1840];
        if ( v6 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_SerialNumber != HIWORD(v6) )
          m_pEntity = nullptr;
        else
          m_pEntity = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v6].m_pEntity;
        if ( m_pEntity == leader )
          ++i;
      }
    }
  }
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x102A7080
// Name: public: virtual void CCSBot::Event_Killed(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CCSBot::Event_Killed(CCSBot *this@<ecx>, int a2@<ebx>, int a3@<edi>, const CTakeDamageInfo *info)
{
  int TeamNumber; // eax
  CCSNavArea *m_lastKnownArea; // [esp+4h] [ebp-14h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  BotChatterInterface::OnDeath(this: &this->m_chatter);
  if ( (this->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this, a2: (int)&savedregs);
  m_lastKnownArea = this->m_lastKnownArea;
  TeamNumber = CBaseEntity::GetTeamNumber(this);
  CNavMesh::IncreaseDangerNearby(
    this: TheNavMesh,
    teamID: TeamNumber,
    amount: 1.0,
    startArea: m_lastKnownArea,
    pos: &this->m_vecAbsOrigin,
    maxRadius: 500.0,
    dangerLimit: -1.0);
  this->m_voiceEndTimestamp = 0.0;
  CCSPlayer::Event_Killed(this, a2, a3, a4: (int)this, info);
}

//------------------------------------------------------------------------------
// Address: 0x102A7110
// Name: public: bool CCSBot::IsDoingScenario(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsDoingScenario(CCSBot *this)
{
  int TeamNumber; // eax
  bool result; // al

  result = true;
  if ( cv_bot_defer_to_human.m_pParent != nullptr && cv_bot_defer_to_human.m_pParent->m_Value.m_nValue != 0 )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this);
    if ( UTIL_HumansOnTeam(teamID: TeamNumber, isAlive: true) != 0 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A7140
// Name: public: bool CCSBot::NoticeLooseBomb(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::NoticeLooseBomb(CCSBot *this)
{
  unsigned int v1; // ecx
  bool result; // al

  result = false;
  if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1 )
  {
    v1 = *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[476];
    if ( v1 != -1
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v1].m_SerialNumber == HIWORD(v1)
      && g_pEntityList->m_EntPtrArray[(unsigned __int16)v1].m_pEntity != nullptr )
    {
      return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A7180
// Name: public: bool CCSBot::CanSeeLooseBomb(void)const
// Source: json
//------------------------------------------------------------------------------
bool __usercall CCSBot::CanSeeLooseBomb@<al>(CCSBot *this@<ecx>, int a2@<ebp>)
{
  unsigned int v4; // ecx
  CBaseEntity **v5; // eax
  CBaseEntity *v6; // esi

  if ( TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory != (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1 )
    return false;
  v4 = *(_DWORD *)&TheBots[1].m_debugMessage[0].m_string[476];
  if ( v4 == -1 )
    return false;
  v5 = (CBaseEntity **)&g_pEntityList->m_EntPtrArray[(unsigned __int16)v4];
  if ( g_pEntityList->m_EntPtrArray[(unsigned __int16)v4].m_SerialNumber != HIWORD(v4) )
    return false;
  v6 = *v5;
  if ( *v5 == nullptr )
    return false;
  if ( (v6->m_iEFlags & 0x800) != 0 )
    CBaseEntity::CalcAbsolutePosition(this: v6, a2);
  return CCSBot::IsVisible(this, pos: &v6->m_vecAbsOrigin, testFOV: true, ignore: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x102A7200
// Name: public: class CCSPlayer __near * CCSBot::GetAttacker(void)const
// Source: json
//------------------------------------------------------------------------------
CCSPlayer *__thiscall CCSBot::GetAttacker(CCSBot *this)
{
  unsigned int m_Index; // ecx
  int v3; // eax
  CEntInfo *v4; // edx
  unsigned int v5; // ecx
  int v6; // eax
  bool v7; // zf
  CEntInfo *v8; // eax
  IHandleEntity *v9; // eax
  unsigned int v10; // eax

  m_Index = this->m_attacker.m_Index;
  if ( m_Index == -1 )
    return nullptr;
  v3 = (unsigned __int16)m_Index;
  v4 = &g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index];
  v5 = HIWORD(m_Index);
  if ( v4->m_SerialNumber != v5 || v4->m_pEntity == nullptr )
    return nullptr;
  v6 = v3;
  v7 = g_pEntityList->m_EntPtrArray[v6].m_SerialNumber == v5;
  v8 = &g_pEntityList->m_EntPtrArray[v6];
  v9 = v7 ? v8->m_pEntity : nullptr;
  if ( v9->__vftable[22].GetRefEHandle(this: v9) != nullptr
    && (v10 = this->m_attacker.m_Index) != -1
    && g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_SerialNumber == HIWORD(v10) )
  {
    return (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v10].m_pEntity;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A7290
// Name: public: bool CCSBot::IsOutnumbered(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsOutnumbered(CCSBot *this)
{
  int m_nearbyFriendCount; // edi
  int FriendsRemaining; // ebx
  int m_nearbyEnemyCount; // edi

  m_nearbyFriendCount = this->m_nearbyFriendCount;
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this) >= m_nearbyFriendCount )
    FriendsRemaining = m_nearbyFriendCount;
  else
    FriendsRemaining = CBot<CCSPlayer>::GetFriendsRemaining(this);
  m_nearbyEnemyCount = this->m_nearbyEnemyCount;
  if ( CBot<CCSPlayer>::GetEnemiesRemaining(this) >= m_nearbyEnemyCount )
    return FriendsRemaining < m_nearbyEnemyCount - 1;
  else
    return FriendsRemaining < CBot<CCSPlayer>::GetEnemiesRemaining(this) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A72E0
// Name: public: int CCSBot::OutnumberedCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCSBot::OutnumberedCount(CCSBot *this)
{
  int m_nearbyFriendCount; // edi
  int FriendsRemaining; // ebx
  int m_nearbyEnemyCount; // edi
  int EnemiesRemaining; // eax
  int v6; // edi
  int v7; // ebx
  int v8; // edi

  m_nearbyFriendCount = this->m_nearbyFriendCount;
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this) >= m_nearbyFriendCount )
    FriendsRemaining = m_nearbyFriendCount;
  else
    FriendsRemaining = CBot<CCSPlayer>::GetFriendsRemaining(this);
  m_nearbyEnemyCount = this->m_nearbyEnemyCount;
  if ( CBot<CCSPlayer>::GetEnemiesRemaining(this) >= m_nearbyEnemyCount )
    EnemiesRemaining = m_nearbyEnemyCount;
  else
    EnemiesRemaining = CBot<CCSPlayer>::GetEnemiesRemaining(this);
  if ( FriendsRemaining >= EnemiesRemaining - 1 )
    return 0;
  v6 = this->m_nearbyEnemyCount;
  if ( CBot<CCSPlayer>::GetEnemiesRemaining(this) >= v6 )
    v7 = v6;
  else
    v7 = CBot<CCSPlayer>::GetEnemiesRemaining(this);
  v8 = this->m_nearbyFriendCount;
  if ( CBot<CCSPlayer>::GetFriendsRemaining(this) >= v8 )
    return v7 - v8 - 1;
  else
    return v7 - CBot<CCSPlayer>::GetFriendsRemaining(this) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A7380
// Name: public: enum CCSBot::DispositionType CCSBot::GetDisposition(void)const
// Source: json
//------------------------------------------------------------------------------
CCSBot::DispositionType __thiscall CCSBot::GetDisposition(CCSBot *this)
{
  double v2; // st7
  CCSBot::DispositionType result; // eax

  v2 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_ignoreEnemiesTimer);
  result = IGNORE_ENEMIES;
  if ( v2 > this->m_ignoreEnemiesTimer.m_timestamp.m_Value )
    return this->m_disposition;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A73B0
// Name: public: bool CCSBot::IsHurrying(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CCSBot::IsHurrying(CCSBot *this)
{
  UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *m_pMemory; // eax

  return IntervalTimer::Now(this: (CEffectsServer *)&this->m_hurryTimer) <= this->m_hurryTimer.m_timestamp.m_Value
      || (m_pMemory = TheBots[1].m_activeGrenadeList.m_Memory.m_pMemory) == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)1
      && TheBots[1].m_debugMessage[0].m_string[460] != 0
      || m_pMemory == (UtlLinkedListElem_t<ActiveGrenade *,unsigned short> *)2
      && CBaseEntity::GetTeamNumber(this) == 2
      && CSGameState::AreAllHostagesBeingRescued(this: &this->m_gameState);
}

//------------------------------------------------------------------------------
// Address: 0x102A7420
// Name: public: bool CollectRetreatSpotsFunctor::operator()(class CNavArea __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CollectRetreatSpotsFunctor::operator()(CollectRetreatSpotsFunctor *this, CNavArea *area)
{
  CUtlVectorUltraConservative<HidingSpot *,CUtlVectorUltraConservativeAllocator>::Data_t *m_pData; // eax
  int v3; // ebx
  float *v5; // edi
  Vector *Centroid; // eax
  const Vector *v7; // edi
  int TeamNumber; // eax
  CBasePlayer *ClosestPlayer; // eax
  Vector v11; // [esp+8h] [ebp-18h] BYREF
  Vector spot; // [esp+14h] [ebp-Ch] BYREF

  m_pData = area->m_hidingSpots.m_pData;
  v3 = 0;
  while ( v3 < m_pData->m_Size )
  {
    v5 = (float *)m_pData->m_Elements[v3];
    if ( this->m_count >= 256 )
      break;
    if ( this->m_range > 0.0 )
    {
      Centroid = GetCentroid(result: &v11, player: this->m_me);
      if ( (float)((float)((float)((float)(v5[2] - Centroid->y) * (float)(v5[2] - Centroid->y))
                         + (float)((float)(v5[1] - Centroid->x) * (float)(v5[1] - Centroid->x)))
                 + (float)((float)(v5[3] - Centroid->z) * (float)(v5[3] - Centroid->z))) > (float)(this->m_range
                                                                                                 * this->m_range) )
        continue;
    }
    v7 = (const Vector *)(v5 + 1);
    if ( !IsSpotOccupied(me: this->m_me, pos: v7) )
    {
      TeamNumber = CBaseEntity::GetTeamNumber(this: this->m_me);
      spot.x = v7->x;
      spot.y = v7->y;
      spot.z = v7->z + 35.5;
      if ( !UTIL_IsVisibleToTeam(&spot, team: (TeamNumber == 2) + 2) )
      {
        ClosestPlayer = UTIL_GetClosestPlayer(pos: v7, distance: nullptr);
        if ( ClosestPlayer == nullptr || CBaseEntity::InSameTeam(this: this->m_me, pEntity: ClosestPlayer) )
          this->m_spot[this->m_count++] = v7;
      }
    }
    m_pData = area->m_hidingSpots.m_pData;
    ++v3;
  }
  return this->m_count != 256;
}

//------------------------------------------------------------------------------
// Address: 0x102A7570
// Name: public: char const __near * CCSBot::GetDispositionName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CCSBot::GetDispositionName(CCSBot *this)
{
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_ignoreEnemiesTimer) > this->m_ignoreEnemiesTimer.m_timestamp.m_Value )
    return name_1[this->m_disposition];
  else
    return off_105CCAF8[0];
}

//------------------------------------------------------------------------------
// Address: 0x102A75B0
// Name: public: virtual void CCSBot::BuildUserCmd(class CUserCmd __near &,class QAngle const __near &,float,float,float,int,unsigned char)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::BuildUserCmd(
        CCSBot *this,
        CUserCmd *cmd,
        const QAngle *viewangles,
        float forwardmove,
        float sidemove,
        float upmove,
        int buttons,
        unsigned __int8 impulse)
{
  int tickcount; // ecx

  _V_memset(dest: (void *)cmd, fill: 0, count: 88);
  if ( CCSPlayer::RunMimicCommand(this, cmd) == 0 )
  {
    if ( this->m_Local.m_bDucked.m_Value || this->m_Local.m_bDucking.m_Value )
      buttons &= ~0x20000u;
    tickcount = gpGlobals->tickcount;
    cmd->forwardmove = forwardmove;
    cmd->impulse = impulse;
    cmd->sidemove = sidemove;
    cmd->command_number = tickcount;
    cmd->upmove = upmove;
    cmd->buttons = buttons;
    cmd->viewangles = *viewangles;
    cmd->random_seed = random->RandomInt(this: random, a2: 0, a3: 0x7FFFFFFF);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A7F80
// Name: bool ForEachHostage<class FarthestHostage>(class FarthestHostage __near &)
// Source: json
//------------------------------------------------------------------------------
char __usercall ForEachHostage<FarthestHostage>@<al>(int a1@<ebp>, FarthestHostage *func)
{
  int v2; // eax
  CHostage *v3; // esi
  CCSBot *m_me; // edi
  float v5; // xmm1_4
  float v6; // xmm0_4
  float v7; // xmm0_4
  int i; // [esp-4h] [ebp-10h]
  _DWORD v10[2]; // [esp+0h] [ebp-Ch] BYREF
  _UNKNOWN *retaddr; // [esp+Ch] [ebp+0h]

  v10[0] = a1;
  v10[1] = retaddr;
  v2 = 0;
  for ( i = 0; v2 < g_Hostages.m_Size; i = v2 )
  {
    v3 = g_Hostages.m_Memory.m_pMemory[v2];
    if ( v3 != nullptr
      && CHostage::IsValid(this: g_Hostages.m_Memory.m_pMemory[v2])
      && CHostage::IsFollowing(this: v3, entity: func->m_me) )
    {
      m_me = (CCSBot *)func->m_me;
      if ( (func->m_me->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: m_me, a2: (int)v10);
      if ( (v3->m_iEFlags & 0x800) != 0 )
        CBaseEntity::CalcAbsolutePosition(this: v3, a2: (int)v10);
      v5 = v3->m_vecAbsOrigin.y - m_me->m_vecAbsOrigin.y;
      v6 = v3->m_vecAbsOrigin.x - m_me->m_vecAbsOrigin.x;
      v7 = fsqrt(
             (float)((float)(v6 * v6) + (float)(v5 * v5))
           + (float)((float)(v3->m_vecAbsOrigin.z - m_me->m_vecAbsOrigin.z)
                   * (float)(v3->m_vecAbsOrigin.z - m_me->m_vecAbsOrigin.z)));
      if ( v7 > func->m_farRange )
        func->m_farRange = v7;
    }
    v2 = i + 1;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A8130
// Name: public: bool CCSBot::IsSurprised(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CCSBot::IsSurprised(CCSBot *this)
{
  return IntervalTimer::Now(this: (CEffectsServer *)&this->m_surpriseTimer) <= this->m_surpriseTimer.m_timestamp.m_Value;
}

//------------------------------------------------------------------------------
// Address: 0x102A8170
// Name: public: virtual void CCSBot::Walk(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Walk(CCSBot *this)
{
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_mustRunTimer) <= this->m_mustRunTimer.m_timestamp.m_Value )
    this->Run(this);
  else
    this->m_isRunning = false;
}

//------------------------------------------------------------------------------
// Address: 0x102A81B0
// Name: public: virtual void CCSBot::Touch(class CBaseEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Touch(CCSBot *this, CBasePlayer *other)
{
  unsigned int v4; // ebx
  CBaseEntity *v5; // eax
  const Vector *v6; // eax
  CBaseEntity *othera; // [esp+34h] [ebp+8h]

  CBasePlayer::Touch(this, pOther: other);
  if ( other->IsPlayer(this: other) )
  {
    if ( CCSBot::IsDefusingBomb(this) )
      return;
    if ( this->m_pathLadder != nullptr )
      return;
    v4 = TheBots->GetPlayerPriority(this: TheBots, a2: other);
    if ( TheBots->GetPlayerPriority(this: TheBots, a2: this) < v4 )
      return;
    if ( CHandle<CBaseEntity>::operator!=(this: &this->m_avoid, val: nullptr) )
    {
      othera = (CBaseEntity *)TheBots->__vftable;
      v5 = CHandle<CBaseAnimating>::operator CBaseAnimating *(this: &this->m_avoid);
      if ( (*(int (__thiscall **)(CBotManager *, CBaseEntity *))&othera->m_Network.m_PVSInfo.m_nAreaNum)(
             a1: TheBots,
             a2: v5) < v4 )
        return;
    }
    CHandle<CBaseEntity>::operator=(this: &this->m_avoid, val: other);
    this->m_avoidTimestamp = gpGlobals->curtime;
  }
  if ( (this->m_isStuck || this->m_isCrouching || CBasePlayer::IsOnLadder(this)) && IsBreakableEntity(pEnt: other) )
  {
    v6 = other->WorldSpaceCenter(this: other);
    CCSBot::SetLookAt(
      this,
      desc: "Breakable",
      pos: v6,
      pri: PRIORITY_HIGH,
      duration: 0.1,
      clearIfClose: false,
      angleTolerance: 5.0,
      attack: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A82E0
// Name: private: void CCSBot::UpdateHostageEscortCount(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::UpdateHostageEscortCount(CCSBot *this)
{
  int v2; // ebx
  CHostage *v3; // edi

  v2 = 0;
  if ( this->m_hostageEscortCount != 0 && (float)(gpGlobals->curtime - this->m_hostageEscortCountTimestamp) >= 1.0 )
  {
    this->m_hostageEscortCountTimestamp = gpGlobals->curtime;
    this->m_hostageEscortCount = 0;
    if ( g_Hostages.m_Size > 0 )
    {
      do
      {
        v3 = g_Hostages.m_Memory.m_pMemory[v2];
        if ( CHostage::IsValid(this: v3) && v3->IsAlive(this: v3) && CHostage::IsFollowing(this: v3, entity: this) )
          ++this->m_hostageEscortCount;
        ++v2;
      }
      while ( v2 < g_Hostages.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A8380
// Name: public: void CCSBot::SetDisposition(enum CCSBot::DispositionType)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetDisposition(CCSBot *this, CCSBot::DispositionType disposition)
{
  CNetworkVarBase<float,CountdownTimer::NetworkVar_m_timestamp> *p_m_timestamp; // esi

  this->m_disposition = disposition;
  if ( disposition != IGNORE_ENEMIES )
  {
    p_m_timestamp = &this->m_ignoreEnemiesTimer.m_timestamp;
    if ( this->m_ignoreEnemiesTimer.m_timestamp.m_Value != -1.0 )
    {
      this->m_ignoreEnemiesTimer.NetworkStateChanged(this: &this->m_ignoreEnemiesTimer, a2: p_m_timestamp);
      p_m_timestamp->m_Value = -1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A83D0
// Name: public: void CCSBot::IgnoreEnemies(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::IgnoreEnemies(CCSBot *this, float duration)
{
  CountdownTimer *p_m_ignoreEnemiesTimer; // edi
  double v3; // st7
  float v4; // [esp+8h] [ebp-4h]

  p_m_ignoreEnemiesTimer = &this->m_ignoreEnemiesTimer;
  v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_ignoreEnemiesTimer) + duration;
  if ( p_m_ignoreEnemiesTimer->m_timestamp.m_Value != v3 )
  {
    p_m_ignoreEnemiesTimer->NetworkStateChanged(this: p_m_ignoreEnemiesTimer, a2: &p_m_ignoreEnemiesTimer->m_timestamp);
    v4 = v3;
    p_m_ignoreEnemiesTimer->m_timestamp.m_Value = v4;
  }
  if ( p_m_ignoreEnemiesTimer->m_duration.m_Value != duration )
  {
    p_m_ignoreEnemiesTimer->NetworkStateChanged(this: p_m_ignoreEnemiesTimer, a2: &p_m_ignoreEnemiesTimer->m_duration);
    p_m_ignoreEnemiesTimer->m_duration.m_Value = duration;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A8440
// Name: public: bool CCSBot::IsRogue(void)const
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
bool __thiscall CCSBot::IsRogue(CCSBot *this)
{
  IUniformRandomStream *v3; // ecx
  IUniformRandomStream *v4; // ecx
  float v5; // [esp+4h] [ebp-10h]
  float m_teamwork; // [esp+10h] [ebp-4h]

  if ( cv_bot_allow_rogues.m_pParent == nullptr || cv_bot_allow_rogues.m_pParent->m_Value.m_nValue == 0 )
    return false;
  if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_rogueTimer) > this->m_rogueTimer.m_timestamp.m_Value )
  {
    v5 = _RandomFloat(this: v3, a2: 10.0, a3: 30.0);
    CountdownTimer::Start(this: &this->m_rogueTimer, duration: v5);
    m_teamwork = this->m_profile->m_teamwork;
    if ( (1.0 - m_teamwork) * 100.0 > _RandomFloat(this: v4, a2: 0.0, a3: 100.0) )
    {
      this->m_isRogue = true;
      return true;
    }
    this->m_isRogue = false;
  }
  return this->m_isRogue;
}

//------------------------------------------------------------------------------
// Address: 0x102A8520
// Name: class Vector const __near * FindNearbyRetreatSpot(class CCSBot __near *,float)
// Source: json
//------------------------------------------------------------------------------
const Vector *__cdecl FindNearbyRetreatSpot(CCSBot *me, float maxRange)
{
  CNavArea *v2; // edi
  const Vector *Centroid; // eax
  IUniformRandomStream *v5; // ecx
  CollectRetreatSpotsFunctor collector; // [esp+14h] [ebp-418h] BYREF
  Vector v7; // [esp+420h] [ebp-Ch] BYREF

  v2 = me->GetLastKnownArea(this: me);
  if ( v2 != nullptr
    && (collector.m_me = me,
        collector.m_count = 0,
        collector.m_range = maxRange,
        Centroid = GetCentroid(result: &v7, player: me),
        SearchSurroundingAreas<CollectRetreatSpotsFunctor>(
          startArea: v2,
          startPos: Centroid,
          func: &collector,
          maxRange,
          options: 0,
          teamID: -1),
        collector.m_count != 0) )
  {
    return collector.m_spot[_RandomInt(this: v5, a2: 0, a3: collector.m_count - 1)];
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A85B0
// Name: public: float CCSBot::GetRangeToFarthestEscortedHostage(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CCSBot::GetRangeToFarthestEscortedHostage(CCSBot *this)
{
  FarthestHostage away; // [esp+0h] [ebp-8h] BYREF
  int savedregs; // [esp+8h] [ebp+0h] BYREF

  away.m_farRange = -1.0;
  away.m_me = this;
  ForEachHostage<FarthestHostage>(a1: (int)&savedregs, func: &away);
  return away.m_farRange;
}

//------------------------------------------------------------------------------
// Address: 0x102A8690
// Name: public: void CCSBot::BecomeAlert(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::BecomeAlert(CCSBot *this)
{
  CountdownTimer *p_m_alertTimer; // edi
  double v2; // st7
  float v3; // [esp+8h] [ebp-4h]

  p_m_alertTimer = &this->m_alertTimer;
  v2 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_alertTimer) + 10.0;
  if ( p_m_alertTimer->m_timestamp.m_Value != v2 )
  {
    p_m_alertTimer->NetworkStateChanged(this: p_m_alertTimer, a2: &p_m_alertTimer->m_timestamp);
    v3 = v2;
    p_m_alertTimer->m_timestamp.m_Value = v3;
  }
  if ( p_m_alertTimer->m_duration.m_Value != 10.0 )
  {
    p_m_alertTimer->NetworkStateChanged(this: p_m_alertTimer, a2: &p_m_alertTimer->m_duration);
    p_m_alertTimer->m_duration.m_Value = 10.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A8860
// Name: public: void CCSBot::Panic(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::Panic(CCSBot *this)
{
  double v2; // st7
  double v3; // st7
  float v4; // [esp+1Ch] [ebp-8h]
  float v5; // [esp+1Ch] [ebp-8h]
  float v6; // [esp+20h] [ebp-4h]

  v6 = _RandomFloat((IUniformRandomStream *)this, a2: 0.2, a3: 0.30000001);
  v2 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_surpriseTimer) + v6;
  if ( this->m_surpriseTimer.m_timestamp.m_Value != v2 )
  {
    this->m_surpriseTimer.NetworkStateChanged(this: &this->m_surpriseTimer, a2: &this->m_surpriseTimer.m_timestamp);
    v4 = v2;
    this->m_surpriseTimer.m_timestamp.m_Value = v4;
  }
  if ( this->m_surpriseTimer.m_duration.m_Value != v6 )
  {
    this->m_surpriseTimer.NetworkStateChanged(this: &this->m_surpriseTimer, a2: &this->m_surpriseTimer.m_duration);
    this->m_surpriseTimer.m_duration.m_Value = v6;
  }
  v3 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_panicTimer) + 3.0;
  if ( this->m_panicTimer.m_timestamp.m_Value != v3 )
  {
    this->m_panicTimer.NetworkStateChanged(this: &this->m_panicTimer, a2: &this->m_panicTimer.m_timestamp);
    v5 = v3;
    this->m_panicTimer.m_timestamp.m_Value = v5;
  }
  if ( this->m_panicTimer.m_duration.m_Value != 3.0 )
  {
    this->m_panicTimer.NetworkStateChanged(this: &this->m_panicTimer, a2: &this->m_panicTimer.m_duration);
    this->m_panicTimer.m_duration.m_Value = 3.0;
  }
  CCSBot::TryToRetreat(this, maxRange: 300.0, duration: 0.0);
  CBot<CCSPlayer>::PrintIfWatched(this, format: "*** PANIC ***\n");
}

//------------------------------------------------------------------------------
// Address: 0x102A89A0
// Name: public: virtual bool CCSBot::Jump(bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::Jump(CCSBot *this, bool mustJump)
{
  CCSNavArea *m_lastKnownArea; // eax
  int m_attributeFlags; // eax
  bool v4; // al
  float v5; // xmm0_4

  m_lastKnownArea = this->m_lastKnownArea;
  v4 = false;
  if ( m_lastKnownArea != nullptr )
  {
    m_attributeFlags = m_lastKnownArea->m_attributeFlags;
    if ( (m_attributeFlags & 1) != 0 && (m_attributeFlags & 2) != 0 )
      v4 = true;
  }
  if ( this->m_pathLadder == nullptr && this->m_Local.m_bDucked.m_Value && !v4 )
    return 0;
  v5 = gpGlobals->curtime - this->m_jumpTimestamp;
  if ( v5 <= 3.0 && (v5 < 0.89999998 || (this->m_fFlags.m_Value & 1) == 0) )
    return 0;
  if ( this->m_isCrouching || !mustJump && v5 < 0.89999998 || v5 < 0.30000001 )
    return 0;
  this->m_buttonFlags |= 2u;
  this->m_jumpTimestamp = gpGlobals->curtime;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x102A8A50
// Name: public: virtual int CCSBot::OnTakeDamage(class CTakeDamageInfo const __near &)
// Source: json
//------------------------------------------------------------------------------
int __userpurge CCSBot::OnTakeDamage@<eax>(CCSBot *this@<ecx>, int TeamNumber@<ebx>, const CTakeDamageInfo *info)
{
  unsigned int m_Index; // eax
  double v5; // st7
  double v6; // st7
  CCSPlayer *v7; // edi
  unsigned int v8; // eax
  float m_safeTime; // xmm1_4
  float v10; // xmm0_4
  float lastAttackedTimestampa; // [esp+Ch] [ebp-8h]
  float lastAttackedTimestampb; // [esp+Ch] [ebp-8h]
  float lastAttackedTimestamp; // [esp+Ch] [ebp-8h]
  CBaseEntity *pEntity; // [esp+10h] [ebp-4h]
  CBaseEntity *pEntitya; // [esp+10h] [ebp-4h]

  m_Index = info->m_hInflictor.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    pEntity = nullptr;
  else
    pEntity = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  v5 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_alertTimer) + 10.0;
  if ( this->m_alertTimer.m_timestamp.m_Value != v5 )
  {
    this->m_alertTimer.NetworkStateChanged(this: &this->m_alertTimer, a2: &this->m_alertTimer.m_timestamp);
    lastAttackedTimestampa = v5;
    this->m_alertTimer.m_timestamp.m_Value = lastAttackedTimestampa;
  }
  if ( this->m_alertTimer.m_duration.m_Value != 10.0 )
  {
    this->m_alertTimer.NetworkStateChanged(this: &this->m_alertTimer, a2: &this->m_alertTimer.m_duration);
    this->m_alertTimer.m_duration.m_Value = 10.0;
  }
  if ( this->m_waitTimer.m_timestamp.m_Value != -1.0 )
  {
    this->m_waitTimer.NetworkStateChanged(this: &this->m_waitTimer, a2: &this->m_waitTimer.m_timestamp);
    this->m_waitTimer.m_timestamp.m_Value = -1.0;
  }
  if ( info->m_bitsDamageType == 8 )
  {
    v6 = IntervalTimer::Now(this: (CEffectsServer *)&this->m_burnedByFlamesTimer);
    if ( this->m_burnedByFlamesTimer.m_timestamp.m_Value != v6 )
    {
      this->m_burnedByFlamesTimer.NetworkStateChanged(
        this: &this->m_burnedByFlamesTimer,
        a2: &this->m_burnedByFlamesTimer.m_timestamp);
      lastAttackedTimestampb = v6;
      this->m_burnedByFlamesTimer.m_timestamp.m_Value = lastAttackedTimestampb;
    }
  }
  v7 = (CCSPlayer *)pEntity;
  if ( pEntity->IsPlayer(this: pEntity)
    && CBaseEntity::InSameTeam(this, pEntity)
    && pEntity->__vftable[2].MyCombatWeaponPointer(this: pEntity) == nullptr )
  {
    BotChatterInterface::FriendlyFire(this: &this->m_chatter);
  }
  if ( pEntity->IsPlayer(this: pEntity) && pEntity->IsPlayer(this: pEntity) && pEntity->IsAlive(this: pEntity) )
  {
    TeamNumber = CBaseEntity::GetTeamNumber(this: pEntity);
    if ( TeamNumber != CBaseEntity::GetTeamNumber(this) )
    {
      v8 = this->m_attacker.m_Index;
      if ( v8 == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_SerialNumber != HIWORD(v8) )
        pEntitya = nullptr;
      else
        pEntitya = (CBaseEntity *)g_pEntityList->m_EntPtrArray[(unsigned __int16)v8].m_pEntity;
      lastAttackedTimestamp = this->m_attackedTimestamp;
      this->m_attacker.m_Index = v7->GetRefEHandle(this: v7)->m_Index;
      m_safeTime = this->m_safeTime;
      this->m_attackedTimestamp = gpGlobals->curtime;
      v10 = gpGlobals->curtime - *(float *)&TheBots[1].m_debugMessage[0].m_string[696];
      if ( m_safeTime > v10 )
        this->m_safeTime = v10 - 2.0;
      if ( IntervalTimer::Now(this: (CEffectsServer *)&this->m_surpriseTimer) > this->m_surpriseTimer.m_timestamp.m_Value
        && (CHandle<CBaseEntity>::operator!=(this: (CHandle<CBaseEntity> *)&this->m_attacker, val: pEntitya)
         || this->m_attackedTimestamp != lastAttackedTimestamp)
        && !CCSBot::IsVisible(this, player: v7, testFOV: true, visParts: nullptr)
        && (!CCSBot::IsAttacking(this) || !this->m_isEnemyVisible) )
      {
        CCSBot::Panic(this);
      }
    }
  }
  return CCSPlayer::OnTakeDamage(this, a2: TeamNumber, a3: (int)v7, inputInfo: info);
}

//------------------------------------------------------------------------------
// Address: 0x102A8D10
// Name: public: void CCSBot::SetBotEnemy(class CCSPlayer __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBot::SetBotEnemy(CCSBot *this, CCSPlayer *enemy)
{
  unsigned int m_Index; // eax
  CCSPlayer *m_pEntity; // ecx
  const char *v5; // eax

  m_Index = this->m_enemy.m_Index;
  if ( m_Index == -1 || g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_SerialNumber != HIWORD(m_Index) )
    m_pEntity = nullptr;
  else
    m_pEntity = (CCSPlayer *)g_pEntityList->m_EntPtrArray[(unsigned __int16)m_Index].m_pEntity;
  if ( m_pEntity != enemy )
  {
    if ( enemy != nullptr )
      this->m_enemy.m_Index = enemy->GetRefEHandle(this: enemy)->m_Index;
    else
      this->m_enemy.m_Index = -1;
    this->m_currentEnemyAcquireTimestamp = gpGlobals->curtime;
    if ( enemy != nullptr )
      v5 = enemy->GetPlayerName(this: enemy);
    else
      v5 = "(NULL)";
    CBot<CCSPlayer>::PrintIfWatched(this, format: "SetBotEnemy: %s\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A8DB0
// Name: public: bool CCSBot::StayOnNavMesh(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::StayOnNavMesh(CCSBot *this)
{
  CCSNavArea *m_lastKnownArea; // edi
  const Vector *Centroid; // eax
  const Vector *v4; // eax
  Vector *v5; // eax
  Vector v7; // [esp+14h] [ebp-30h] BYREF
  Vector v8; // [esp+20h] [ebp-24h] BYREF
  Vector to; // [esp+2Ch] [ebp-18h] BYREF
  Vector pos; // [esp+38h] [ebp-Ch] BYREF

  if ( this->m_currentArea != nullptr )
    return 1;
  m_lastKnownArea = this->m_lastKnownArea;
  if ( m_lastKnownArea != nullptr )
  {
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Getting out of NULL area...\n");
  }
  else
  {
    Centroid = GetCentroid(result: &v8, player: this);
    m_lastKnownArea = (CCSNavArea *)CNavMesh::GetNearestNavArea(
                                      this: TheNavMesh,
                                      pos: Centroid,
                                      anyZ: false,
                                      maxDist: 10000.0,
                                      checkLOS: false,
                                      checkGround: true);
    CBot<CCSPlayer>::PrintIfWatched(this, format: "Started off the nav mesh - moving to closest nav area...\n");
  }
  if ( m_lastKnownArea != nullptr )
  {
    v4 = GetCentroid(result: &v7, player: this);
    CNavArea::GetClosestPointOnArea(this: m_lastKnownArea, pPos: v4, close: &pos);
    v5 = GetCentroid(result: &v7, player: this);
    to.x = pos.x - v5->x;
    to.y = pos.y - v5->y;
    to.z = pos.z - v5->z;
    VectorNormalize(vec: &to);
    pos.x = (float)(to.x * 5.0) + pos.x;
    pos.y = (float)(to.y * 5.0) + pos.y;
    pos.z = (float)(to.z * 5.0) + pos.z;
    CCSBot::MoveTowardsPosition(this, &pos);
  }
  if ( this->m_isStuck )
    CCSBot::Wiggle(this);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x102A8EF0
// Name: public: struct CCSBotManager::Zone const __near * CCSBotManager::GetRandomZone(void)const
// Source: json
//------------------------------------------------------------------------------
const CCSBotManager::Zone *__thiscall CCSBotManager::GetRandomZone(CCSBotManager *this)
{
  int m_zoneCount; // eax
  int m_nAllocationCount; // edx
  const CCSBotManager::Zone **m_pMemory; // ebx
  int m_Size; // esi
  CCSBotManager::Zone *m_zone; // ecx
  int v7; // edi
  const CCSBotManager::Zone **v8; // edi
  const CCSBotManager::Zone *v9; // ebx
  CUtlVector<CCSBotManager::Zone const *,CUtlMemory<CCSBotManager::Zone const *,int> > unblockedZones; // [esp+0h] [ebp-20h] BYREF
  CCSBotManager *v11; // [esp+14h] [ebp-Ch]
  int i; // [esp+18h] [ebp-8h]
  CCSBotManager::Zone *v13; // [esp+1Ch] [ebp-4h]

  m_zoneCount = this->m_zoneCount;
  m_nAllocationCount = 0;
  v11 = this;
  if ( m_zoneCount == 0 )
    return nullptr;
  m_pMemory = nullptr;
  m_Size = 0;
  memset(&unblockedZones, 0, sizeof(unblockedZones));
  i = 0;
  if ( m_zoneCount <= 0 )
    goto LABEL_15;
  m_zone = this->m_zone;
  v13 = m_zone;
  while ( 1 )
  {
    if ( !m_zone->m_isBlocked )
    {
      v7 = m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
      {
        CUtlMemory<CNavLadder *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&unblockedZones,
          num: m_Size - m_nAllocationCount + 1);
        m_Size = unblockedZones.m_Size;
        m_pMemory = unblockedZones.m_Memory.m_pMemory;
      }
      unblockedZones.m_Size = ++m_Size;
      unblockedZones.m_pElements = m_pMemory;
      if ( m_Size - v7 - 1 > 0 )
        _V_memmove(dest: &m_pMemory[v7 + 1], src: &m_pMemory[v7], count: 4 * (m_Size - v7 - 1));
      v8 = &m_pMemory[v7];
      if ( v8 != nullptr )
        *v8 = v13;
    }
    m_zone = v13 + 1;
    ++i;
    ++v13;
    if ( i >= v11->m_zoneCount )
      break;
    m_nAllocationCount = unblockedZones.m_Memory.m_nAllocationCount;
  }
  if ( m_Size != 0 )
  {
    v9 = m_pMemory[_RandomInt(this: (IUniformRandomStream *)m_zone, a2: 0, a3: m_Size - 1)];
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&unblockedZones);
    return v9;
  }
  else
  {
LABEL_15:
    CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>::~CUtlVector<CHandle<CAI_DynamicLink>,CUtlMemory<CHandle<CAI_DynamicLink>,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&unblockedZones);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x102A9060
// Name: public: bool CCSBot::GuardRandomZone(float)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CCSBot::GuardRandomZone(CCSBot *this, float range)
{
  CCSBotManager *v2; // esi
  const CCSBotManager::Zone *RandomZone; // eax
  CNavArea *RandomAreaInZone; // eax

  v2 = (CCSBotManager *)TheBots;
  RandomZone = CCSBotManager::GetRandomZone(this: (CCSBotManager *)TheBots);
  if ( RandomZone == nullptr )
    return 0;
  RandomAreaInZone = CCSBotManager::GetRandomAreaInZone(this: v2, zone: RandomZone);
  if ( RandomAreaInZone == nullptr )
    return 0;
  CCSBot::Hide(this, searchFromArea: RandomAreaInZone, duration: -1.0, hideRange: range, holdPosition: false);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10410740
// Name: CCSBot_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CCSBot_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CCSBot>(__formal: nullptr);
  CCSBot_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x102A8FF0
// Name: struct datamap_t __near * DataMapInit<class CCSBot>(class CCSBot __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CCSBot>()
{
  if ( (_S2_261 & 1) == 0 )
  {
    _S2_261 |= 1u;
    nameHolder_487.m_pszBase = "CCSBot";
    nameHolder_487.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_487.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_487.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_487.m_Names.m_Size = 0;
    nameHolder_487.m_Names.m_pElements = nullptr;
    nameHolder_487.m_nLenBase = 6;
    atexit(func: DataMapInit_CCSBot__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CCSBot::m_DataMap.baseMap = &CCSPlayer::m_DataMap;
  CCSBot::m_DataMap.dataNumFields = 1;
  CCSBot::m_DataMap.dataDesc = dataDesc_505;
  return &CCSBot::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10410750
// Name: _dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___14
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCServerGameTagsIServerGameTags_reg___14()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCServerGameTagsIServerGameTags_reg_14,
           fn: _CreateCServerGameTagsIServerGameTags_interface_14,
           pName: "ServerGameTags001");
}
