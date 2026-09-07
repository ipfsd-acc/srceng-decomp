// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/cstrike15/achievements_cs.cpp
// Functions: 398
// ============================================================

#include "game\shared\cstrike15\achievements_cs.h"

//------------------------------------------------------------------------------
// Address: 0x101AE800
// Name: public: static class CAchievementMgr __near * CAchievementMgr::GetInstance(void)
// Source: json
//------------------------------------------------------------------------------
CAchievementMgr *__cdecl CAchievementMgr::GetInstance()
{
  return &g_AchievementMgrCS;
}

//------------------------------------------------------------------------------
// Address: 0x101AE810
// Name: public: static class IAchievementMgr __near * CAchievementMgr::GetInstanceInterface(void)
// Source: json
//------------------------------------------------------------------------------
CAchievementMgrDelegateIAchievementMgr *__cdecl CAchievementMgr::GetInstanceInterface()
{
  return &g_IAchievementMgrImpl;
}

//------------------------------------------------------------------------------
// Address: 0x101AE830
// Name: public: virtual void CCSBaseAchievement::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBaseAchievement::GetSettings(CCSBaseAchievement *this, KeyValues *pNodeOut)
{
  CBaseAchievement::GetSettings(this, pNodeOut);
  KeyValues::SetInt(this: pNodeOut, keyName: "unlockTime", value: this->m_uUnlockTime);
}

//------------------------------------------------------------------------------
// Address: 0x101AE860
// Name: public: virtual void CCSBaseAchievement::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCSBaseAchievement::ApplySettings(CCSBaseAchievement *this, KeyValues *pNodeIn)
{
  CBaseAchievement::ApplySettings(this, pNodeIn);
  this->m_uUnlockTime = KeyValues::GetInt(this: pNodeIn, keyName: "unlockTime", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101AE890
// Name: public: virtual class IAchievement __near * CAchievementMgrDelegateIAchievementMgr::GetAchievementByIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
IAchievement *__thiscall CAchievementMgrDelegateIAchievementMgr::GetAchievementByIndex(
        CAchievementMgrDelegateIAchievementMgr *this,
        int index,
        int nPlayerSlot)
{
  return CAchievementMgr::GetAchievementByIndex(this: this->m_pDelegate, index, nUserSlot: nPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101AE8A0
// Name: public: virtual class IAchievement __near * CAchievementMgrDelegateIAchievementMgr::GetAchievementByDisplayOrder(int,int)
// Source: json
//------------------------------------------------------------------------------
IAchievement *__thiscall CAchievementMgrDelegateIAchievementMgr::GetAchievementByDisplayOrder(
        CAchievementMgrDelegateIAchievementMgr *this,
        int orderIndex,
        int nPlayerSlot)
{
  return CAchievementMgr::GetAchievementByDisplayOrder(this: this->m_pDelegate, orderIndex, nUserSlot: nPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101AE8B0
// Name: public: virtual class IAchievement __near * CAchievementMgrDelegateIAchievementMgr::GetAwardByDisplayOrder(int,int)
// Source: json
//------------------------------------------------------------------------------
IAchievement *__thiscall CAchievementMgrDelegateIAchievementMgr::GetAwardByDisplayOrder(
        CAchievementMgrDelegateIAchievementMgr *this,
        int orderIndex,
        int nPlayerSlot)
{
  return CAchievementMgr::GetAwardByDisplayOrder(this: this->m_pDelegate, orderIndex, nUserSlot: nPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101AE8C0
// Name: public: virtual class CBaseAchievement __near * CAchievementMgrDelegateIAchievementMgr::GetAchievementByID(int,int)
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__thiscall CAchievementMgrDelegateIAchievementMgr::GetAchievementByID(
        CAchievementMgrDelegateIAchievementMgr *this,
        int id,
        int nPlayerSlot)
{
  return CAchievementMgr::GetAchievementByID(this: this->m_pDelegate, iAchievementID: id, nUserSlot: nPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101AE8D0
// Name: public: virtual int CAchievementMgrDelegateIAchievementMgr::GetAchievementCount(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAchievementMgrDelegateIAchievementMgr::GetAchievementCount(
        CAchievementMgrDelegateIAchievementMgr *this,
        bool bAssets)
{
  return CAchievementMgr::GetAchievementCount(this: this->m_pDelegate, bAssets);
}

//------------------------------------------------------------------------------
// Address: 0x101AE8E0
// Name: public: virtual void CAchievementMgrDelegateIAchievementMgr::InitializeAchievements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgrDelegateIAchievementMgr::InitializeAchievements(
        CAchievementMgrDelegateIAchievementMgr *this)
{
  CAchievementMgr::InitializeAchievements(this: this->m_pDelegate);
}

//------------------------------------------------------------------------------
// Address: 0x101AE8F0
// Name: public: virtual void CAchievementMgrDelegateIAchievementMgr::AwardAchievement(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgrDelegateIAchievementMgr::AwardAchievement(
        CAchievementMgrDelegateIAchievementMgr *this,
        vgui::TreeNode *nAchievementID,
        int nPlayerSlot)
{
  CAchievementMgr::AwardAchievement(this: this->m_pDelegate, iAchievementID: nAchievementID, nUserSlot: nPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101AE900
// Name: public: virtual void CAchievementMgrDelegateIAchievementMgr::OnMapEvent(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgrDelegateIAchievementMgr::OnMapEvent(
        CAchievementMgrDelegateIAchievementMgr *this,
        const char *pchEventName,
        int nPlayerSlot)
{
  CAchievementMgr::OnMapEvent(this: this->m_pDelegate, pchEventName, nUserSlot: nPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101AE910
// Name: public: virtual void CAchievementMgrDelegateIAchievementMgr::SaveGlobalStateIfDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgrDelegateIAchievementMgr::SaveGlobalStateIfDirty(
        CAchievementMgrDelegateIAchievementMgr *this)
{
  CAchievementMgr::SaveGlobalState(this: this->m_pDelegate);
}

//------------------------------------------------------------------------------
// Address: 0x101AE920
// Name: public: virtual bool CAchievementMgrDelegateIAchievementMgr::HasAchieved(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAchievementMgrDelegateIAchievementMgr::HasAchieved(
        CAchievementMgrDelegateIAchievementMgr *this,
        const char *pchName,
        int nPlayerSlot)
{
  return CAchievementMgr::HasAchieved(this: this->m_pDelegate, pchName, nUserSlot: nPlayerSlot);
}

//------------------------------------------------------------------------------
// Address: 0x101AE940
// Name: public: virtual bool CAchievementMgrDelegateIAchievementMgr::WereCheatsEverOn(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAchievementMgrDelegateIAchievementMgr::WereCheatsEverOn(CAchievementMgrDelegateIAchievementMgr *this)
{
  return this->m_pDelegate->m_bCheatsEverOn;
}

//------------------------------------------------------------------------------
// Address: 0x101AE950
// Name: public: virtual struct UIProfileInfo __near * CAchievementMgrDelegateIAchievementMgr::GetUIProfileInfo(void)
// Source: json
//------------------------------------------------------------------------------
UIProfileInfo *__thiscall CAchievementMgrDelegateIAchievementMgr::GetUIProfileInfo(
        CAchievementMgrDelegateIAchievementMgr *this)
{
  return &this->m_pDelegate->m_UIProfileInfo;
}

//------------------------------------------------------------------------------
// Address: 0x101AE960
// Name: public: virtual void CAchievementMgrDelegateIAchievementMgr::ResetProfileInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgrDelegateIAchievementMgr::ResetProfileInfo(CAchievementMgrDelegateIAchievementMgr *this)
{
  CAchievementMgr::ResetProfileInfo(this: this->m_pDelegate);
}

//------------------------------------------------------------------------------
// Address: 0x101AE970
// Name: public: virtual void CAchievementMgrDelegateIAchievementMgr::SendWriteProfileEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgrDelegateIAchievementMgr::SendWriteProfileEvent(
        CAchievementMgrDelegateIAchievementMgr *this)
{
  CAchievementMgr::SendWriteProfileEvent(this: this->m_pDelegate);
}

//------------------------------------------------------------------------------
// Address: 0x101AE980
// Name: public: virtual void CAchievementMgrDelegateIAchievementMgr::SendResetProfileEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgrDelegateIAchievementMgr::SendResetProfileEvent(
        CAchievementMgrDelegateIAchievementMgr *this)
{
  CAchievementMgr::SendResetProfileEvent(this: this->m_pDelegate);
}

//------------------------------------------------------------------------------
// Address: 0x101AE990
// Name: public: virtual bool CAchievementMgrDelegateIAchievementMgr::GetWriteProfileResult(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAchievementMgrDelegateIAchievementMgr::GetWriteProfileResult(
        CAchievementMgrDelegateIAchievementMgr *this)
{
  return this->m_pDelegate->m_writeProfileResult;
}

//------------------------------------------------------------------------------
// Address: 0x101AEA00
// Name: public: void CAchievement_Meta::Steam_OnUserAchievementStored(struct UserAchievementStored_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievement_Meta::Steam_OnUserAchievementStored(
        CAchievement_Meta *this,
        UserAchievementStored_t *pUserAchievementStored)
{
  int v3; // ebx
  int v4; // edi
  bool v5; // zf
  CBaseAchievement *AchievementByID; // eax
  IAchievement *v7; // ecx

  if ( !this->IsAchieved(this: &this->IAchievement) )
  {
    v3 = 0;
    v4 = 0;
    v5 = this->m_requirements.m_Size == 0;
    if ( this->m_requirements.m_Size > 0 )
    {
      do
      {
        AchievementByID = CAchievementMgr::GetAchievementByID(
                            this: this->m_pAchievementMgr,
                            iAchievementID: this->m_requirements.m_Memory.m_pMemory[v4],
                            nUserSlot: this->m_nUserSlot);
        if ( AchievementByID != nullptr )
          v7 = &AchievementByID->IAchievement;
        else
          v7 = nullptr;
        if ( !v7->IsAchieved(this: v7) )
          break;
        ++v4;
        ++v3;
      }
      while ( v4 < this->m_requirements.m_Size );
      v5 = v3 == this->m_requirements.m_Size;
    }
    if ( v5 )
      CBaseAchievement::AwardAchievement(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AEA70
// Name: private: virtual void CAchievement_StatGoal::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievement_StatGoal::Init(CAchievement_StatGoal *this)
{
  CBaseAchievement::SetFlags(this, iFlags: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101AEA80
// Name: private: virtual void CAchievement_StatGoal::OnPlayerStatsUpdate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievement_StatGoal::OnPlayerStatsUpdate(CAchievement_StatGoal *this, int nUserSlot)
{
  const StatsCollection_t *LifetimeStats; // ebx
  IAchievement_vtbl *v4; // eax
  int v5; // ebx
  int iOldCount; // [esp+14h] [ebp+8h]

  LifetimeStats = CCSClientGameStats::GetLifetimeStats(this: &g_CSClientGameStats, nUserSlot);
  iOldCount = this->GetCount(this: &this->IAchievement);
  v4 = this->CCSBaseAchievement::CBaseAchievement::IAchievement::__vftable;
  this->m_iCount = LifetimeStats->m_iValue[this->m_StatId];
  if ( v4->GetCount(this: &this->IAchievement) != iOldCount )
    this->m_pAchievementMgr->m_bDirty[this->m_nUserSlot] = true;
  v5 = this->GetGoal(this: &this->IAchievement);
  if ( !this->IsAchieved(this: &this->IAchievement) && v5 > 0 )
  {
    if ( achievements_easymode.m_pParent != nullptr && achievements_easymode.m_pParent->m_Value.m_nValue != 0 )
    {
      v5 /= 10;
      if ( v5 == 0 )
        v5 = 1;
    }
    if ( this->GetCount(this: &this->IAchievement) >= v5 )
      CBaseAchievement::AwardAchievement(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AEB40
// Name: Create_CSEnemyKillsMed
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsMed()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3002;
  result->m_pszName = "KILL_ENEMY_MED";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)2;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEBA0
// Name: Create_CSEnemyKillsHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3003;
  result->m_pszName = "KILL_ENEMY_HIGH";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)2;
  result->m_iGoal = 10000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEC00
// Name: Create_CSWinRoundsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinRoundsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5001;
  result->m_pszName = "WIN_ROUNDS_LOW";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)10;
  result->m_iGoal = 10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEC60
// Name: Create_CSWinRoundsMed
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinRoundsMed()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5002;
  result->m_pszName = "WIN_ROUNDS_MED";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)10;
  result->m_iGoal = 200;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AECC0
// Name: Create_CSWinRoundsHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinRoundsHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5003;
  result->m_pszName = "WIN_ROUNDS_HIGH";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)10;
  result->m_iGoal = 5000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AED20
// Name: Create_CSGGWinRoundsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGGWinRoundsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5004;
  result->m_pszName = "WIN_GUN_GAME_ROUNDS_LOW";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)239;
  result->m_iGoal = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AED80
// Name: Create_CSGGWinRoundsMed
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGGWinRoundsMed()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5005;
  result->m_pszName = "WIN_GUN_GAME_MED";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)239;
  result->m_iGoal = 25;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEDE0
// Name: Create_CSGGWinRoundsHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGGWinRoundsHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5006;
  result->m_pszName = "WIN_GUN_GAME_HIGH";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)239;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEE40
// Name: Create_CSGGWinRoundsExtreme
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGGWinRoundsExtreme()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5007;
  result->m_pszName = "WIN_GUN_GAME_EXTREME";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)239;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEEA0
// Name: Create_CSGGWinRoundsUltimate
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGGWinRoundsUltimate()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5008;
  result->m_pszName = "WIN_GUN_GAME_ULTIMATE";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)239;
  result->m_iGoal = 1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEF00
// Name: Create_CSGGRoundsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGGRoundsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5009;
  result->m_pszName = "GUN_GAME_ROUNDS_LOW";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)240;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEF60
// Name: Create_CSGGRoundsMed
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGGRoundsMed()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5010;
  result->m_pszName = "GUN_GAME_ROUNDS_MED";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)240;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEFC0
// Name: Create_CSGGRoundsHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGGRoundsHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5011;
  result->m_pszName = "GUN_GAME_ROUNDS_HIGH";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)240;
  result->m_iGoal = 5000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF020
// Name: Create_CSWinPistolRoundsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinPistolRoundsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5034;
  result->m_pszName = "WIN_PISTOLROUNDS_LOW";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)14;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF080
// Name: Create_CSWinPistolRoundsMed
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinPistolRoundsMed()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5035;
  result->m_pszName = "WIN_PISTOLROUNDS_MED";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)14;
  result->m_iGoal = 25;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF0E0
// Name: Create_CSWinPistolRoundsHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinPistolRoundsHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5036;
  result->m_pszName = "WIN_PISTOLROUNDS_HIGH";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)14;
  result->m_iGoal = 250;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF140
// Name: Create_CSMoneyEarnedLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSMoneyEarnedLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5012;
  result->m_pszName = "EARN_MONEY_LOW";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)17;
  result->m_iGoal = 125000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF1A0
// Name: Create_CSMoneyEarnedMed
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSMoneyEarnedMed()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5013;
  result->m_pszName = "EARN_MONEY_MED";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)17;
  result->m_iGoal = 2500000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF200
// Name: Create_CSMoneyEarnedHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSMoneyEarnedHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5014;
  result->m_pszName = "EARN_MONEY_HIGH";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)17;
  result->m_iGoal = 50000000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF260
// Name: Create_CSGiveDamageLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGiveDamageLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5015;
  result->m_pszName = "GIVE_DAMAGE_LOW";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)4;
  result->m_iGoal = 2500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF2C0
// Name: Create_CSGiveDamageMed
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGiveDamageMed()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5016;
  result->m_pszName = "GIVE_DAMAGE_MED";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)4;
  result->m_iGoal = 50000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF320
// Name: Create_CSGiveDamageHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGiveDamageHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5017;
  result->m_pszName = "GIVE_DAMAGE_HIGH";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)4;
  result->m_iGoal = 1000000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF380
// Name: Create_CSEnemyKillsDeagle
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsDeagle()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4001;
  result->m_pszName = "KILL_ENEMY_DEAGLE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)20;
  result->m_iGoal = 200;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF3E0
// Name: Create_CSEnemyKillsGlock
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsGlock()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4002;
  result->m_pszName = "KILL_ENEMY_GLOCK";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)21;
  result->m_iGoal = 200;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF440
// Name: Create_CSEnemyKillsElite
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsElite()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4003;
  result->m_pszName = "KILL_ENEMY_ELITE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)22;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF4A0
// Name: Create_CSEnemyKillsFiveSeven
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsFiveSeven()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4004;
  result->m_pszName = "KILL_ENEMY_FIVESEVEN";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)23;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF500
// Name: Create_CSEnemyKillsBizon
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsBizon()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4005;
  result->m_pszName = "KILL_ENEMY_BIZON";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)40;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF560
// Name: Create_CSEnemyKillsTec9
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsTec9()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4006;
  result->m_pszName = "KILL_ENEMY_TEC9";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)44;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF5C0
// Name: Create_CSEnemyKillsTaser
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsTaser()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4007;
  result->m_pszName = "KILL_ENEMY_TASER";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)45;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF620
// Name: Create_CSEnemyKillsHKP2000
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsHKP2000()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4008;
  result->m_pszName = "KILL_ENEMY_HKP2000";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)46;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF680
// Name: Create_CSEnemyKillsP250
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsP250()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4009;
  result->m_pszName = "KILL_ENEMY_P250";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)50;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF6E0
// Name: Create_CSEnemyKillsAWP
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsAWP()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4010;
  result->m_pszName = "KILL_ENEMY_AWP";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)24;
  result->m_iGoal = 1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF740
// Name: Create_CSEnemyKillsAK47
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsAK47()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4011;
  result->m_pszName = "KILL_ENEMY_AK47";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)25;
  result->m_iGoal = 1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF7A0
// Name: Create_CSEnemyKillsM4A1
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsM4A1()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4012;
  result->m_pszName = "KILL_ENEMY_M4A1";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)26;
  result->m_iGoal = 1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF800
// Name: Create_CSEnemyKillsAUG
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsAUG()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4013;
  result->m_pszName = "KILL_ENEMY_AUG";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)27;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF860
// Name: Create_CSEnemyKillsGALIL
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsGALIL()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4014;
  result->m_pszName = "KILL_ENEMY_GALIL";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)28;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF8C0
// Name: Create_CSEnemyKillsFAMAS
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsFAMAS()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4015;
  result->m_pszName = "KILL_ENEMY_FAMAS";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)29;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF920
// Name: Create_CSEnemyKillsG3SG1
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsG3SG1()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4016;
  result->m_pszName = "KILL_ENEMY_G3SG1";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)30;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF980
// Name: Create_CSEnemyKillsSCAR20
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsSCAR20()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4017;
  result->m_pszName = "KILL_ENEMY_SCAR20";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)51;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF9E0
// Name: Create_CSEnemyKillsSG556
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsSG556()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4018;
  result->m_pszName = "KILL_ENEMY_SG556";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)52;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFA40
// Name: Create_CSEnemyKillsSSG08
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsSSG08()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4019;
  result->m_pszName = "KILL_ENEMY_SSG08";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)53;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFAA0
// Name: Create_CSEnemyKillsP90
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsP90()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4020;
  result->m_pszName = "KILL_ENEMY_P90";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)31;
  result->m_iGoal = 1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFB00
// Name: Create_CSEnemyKillsMAC10
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsMAC10()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4021;
  result->m_pszName = "KILL_ENEMY_MAC10";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)32;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFB60
// Name: Create_CSEnemyKillsUMP45
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsUMP45()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4022;
  result->m_pszName = "KILL_ENEMY_UMP45";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)33;
  result->m_iGoal = 1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFBC0
// Name: Create_CSEnemyKillsMP7
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsMP7()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4023;
  result->m_pszName = "KILL_ENEMY_MP7";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)47;
  result->m_iGoal = 1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFC20
// Name: Create_CSEnemyKillsMP9
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsMP9()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4024;
  result->m_pszName = "KILL_ENEMY_MP9";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)48;
  result->m_iGoal = 1000;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFC80
// Name: Create_CSEnemyKillsXM1014
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsXM1014()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4025;
  result->m_pszName = "KILL_ENEMY_XM1014";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)34;
  result->m_iGoal = 200;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFCE0
// Name: Create_CSEnemyKillsMag7
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsMag7()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4026;
  result->m_pszName = "KILL_ENEMY_MAG7";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)41;
  result->m_iGoal = 200;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFD40
// Name: Create_CSEnemyKillsSawedoff
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsSawedoff()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4027;
  result->m_pszName = "KILL_ENEMY_SAWEDOFF";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)43;
  result->m_iGoal = 200;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFDA0
// Name: Create_CSEnemyKillsNova
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsNova()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4028;
  result->m_pszName = "KILL_ENEMY_NOVA";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)49;
  result->m_iGoal = 200;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFE00
// Name: Create_CSEnemyKillsM249
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsM249()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4029;
  result->m_pszName = "KILL_ENEMY_M249";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)35;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFE60
// Name: Create_CSEnemyKillsNegev
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsNegev()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4030;
  result->m_pszName = "KILL_ENEMY_NEGEV";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)42;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFEC0
// Name: Create_CSEnemyKillsKnife
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsKnife()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4031;
  result->m_pszName = "KILL_ENEMY_KNIFE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)36;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFF20
// Name: Create_CSEnemyKillsHEGrenade
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsHEGrenade()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4032;
  result->m_pszName = "KILL_ENEMY_HEGRENADE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)37;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFF80
// Name: Create_CSEnemyKillsMolotov
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsMolotov()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4033;
  result->m_pszName = "KILL_ENEMY_MOLOTOV";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)38;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AFFF0
// Name: Create_CSHeadshots
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSHeadshots()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3008;
  result->m_pszName = "HEADSHOTS";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)144;
  result->m_iGoal = 250;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0050
// Name: Create_CSKillsEnemyWeapon
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillsEnemyWeapon()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3023;
  result->m_pszName = "KILLS_ENEMY_WEAPON";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)148;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B00B0
// Name: Create_CSKillEnemyBlinded
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemyBlinded()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3020;
  result->m_pszName = "KILL_ENEMY_BLINDED";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)145;
  result->m_iGoal = 25;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0110
// Name: Create_CSDefuseBombsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDefuseBombsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1013;
  result->m_pszName = "BOMB_DEFUSE_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)6;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0170
// Name: Create_CSPlantBombsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSPlantBombsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1012;
  result->m_pszName = "BOMB_PLANT_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)5;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B01D0
// Name: Create_CSDefuseBombsTRLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDefuseBombsTRLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1015;
  result->m_pszName = "TR_BOMB_DEFUSE_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)8;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0230
// Name: Create_CSPlantBombsTRLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSPlantBombsTRLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1014;
  result->m_pszName = "TR_BOMB_PLANT_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)7;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0290
// Name: Create_CSRescueHostagesLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSRescueHostagesLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 2004;
  result->m_pszName = "RESCUE_HOSTAGES_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)156;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B02F0
// Name: Create_CSRescueHostagesMid
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSRescueHostagesMid()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 2005;
  result->m_pszName = "RESCUE_HOSTAGES_MED";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)156;
  result->m_iGoal = 500;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0350
// Name: Create_CSWinKnifeFightsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinKnifeFightsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3025;
  result->m_pszName = "WIN_KNIFE_FIGHTS_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)149;
  result->m_iGoal = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B03B0
// Name: Create_CSWinKnifeFightsHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinKnifeFightsHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3026;
  result->m_pszName = "WIN_KNIFE_FIGHTS_HIGH";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)149;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0410
// Name: Create_CSKillSnipers
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillSnipers()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3031;
  result->m_pszName = "KILL_SNIPERS";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)164;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0470
// Name: Create_CSWinMapCS_ASSAULT
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapCS_ASSAULT()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6001;
  result->m_pszName = "WIN_MAP_CS_ASSAULT";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)178;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B04D0
// Name: Create_CSWinMapCS_ITALY
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapCS_ITALY()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6004;
  result->m_pszName = "WIN_MAP_CS_ITALY";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)179;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0530
// Name: Create_CSWinMapCS_OFFICE
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapCS_OFFICE()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6006;
  result->m_pszName = "WIN_MAP_CS_OFFICE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)180;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0590
// Name: Create_CSWinMapDE_AZTEC
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapDE_AZTEC()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6007;
  result->m_pszName = "WIN_MAP_DE_AZTEC";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)181;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B05F0
// Name: Create_CSWinMapDE_CBBLE
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapDE_CBBLE()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6008;
  result->m_pszName = "WIN_MAP_DE_CBBLE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)182;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0650
// Name: Create_CSWinMapDE_DUST2
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapDE_DUST2()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6011;
  result->m_pszName = "WIN_MAP_DE_DUST2";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)183;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B06B0
// Name: Create_CSWinMapDE_DUST
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapDE_DUST()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6010;
  result->m_pszName = "WIN_MAP_DE_DUST";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)184;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0710
// Name: Create_CSWinMapDE_INFERNO
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapDE_INFERNO()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6012;
  result->m_pszName = "WIN_MAP_DE_INFERNO";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)185;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0770
// Name: Create_CSWinMapDE_NUKE
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapDE_NUKE()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6013;
  result->m_pszName = "WIN_MAP_DE_NUKE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)186;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B07D0
// Name: Create_CSWinMapDE_PIRANESI
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapDE_PIRANESI()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6014;
  result->m_pszName = "WIN_MAP_DE_PIRANESI";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)187;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0830
// Name: Create_CSWinMapDE_PRODIGY
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMapDE_PRODIGY()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6016;
  result->m_pszName = "WIN_MAP_DE_PRODIGY";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)188;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0890
// Name: Create_CSWinMatchDE_ALLEYWAY
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchDE_ALLEYWAY()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6024;
  result->m_pszName = "WIN_MAP_DE_ALLEYWAY";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)232;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B08F0
// Name: Create_CSWinMatchDE_DEPOT
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchDE_DEPOT()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6025;
  result->m_pszName = "WIN_MAP_DE_DEPOT";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)233;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0950
// Name: Create_CSWinMatchDE_BANK
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchDE_BANK()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6023;
  result->m_pszName = "WIN_MAP_DE_BANK";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)231;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B09B0
// Name: Create_CSWinMatchGG_VIETNAM
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchGG_VIETNAM()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6029;
  result->m_pszName = "WIN_MAP_GG_VIETNAM";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)226;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0A10
// Name: Create_CSWinMatchDE_SHACKS
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchDE_SHACKS()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6022;
  result->m_pszName = "WIN_MAP_DE_SHACKS";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)230;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0A70
// Name: Create_CSWinMatchDE_MILL
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchDE_MILL()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6021;
  result->m_pszName = "WIN_MAP_DE_MILL";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)229;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0AD0
// Name: Create_CSWinMatchDE_HOUSE
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchDE_HOUSE()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6020;
  result->m_pszName = "WIN_MAP_DE_HOUSE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)234;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0B30
// Name: Create_CSWinMatchDE_BOATHOUSE
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchDE_BOATHOUSE()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6019;
  result->m_pszName = "WIN_MAP_DE_BOATHOUSE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)228;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0B90
// Name: Create_CSWinMatchGG_BAGGAGE
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinMatchGG_BAGGAGE()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6030;
  result->m_pszName = "WIN_MAP_GG_BAGGAGE";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)227;
  result->m_iGoal = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0BF0
// Name: Create_CSDonateWeapons
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDonateWeapons()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5041;
  result->m_pszName = "DONATE_WEAPONS";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)165;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0C50
// Name: Create_CSDominationsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDominationsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3011;
  result->m_pszName = "DOMINATIONS_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)168;
  result->m_iGoal = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0CB0
// Name: Create_CSDominationsHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDominationsHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3012;
  result->m_pszName = "DOMINATIONS_HIGH";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)168;
  result->m_iGoal = 10;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0D10
// Name: Create_CSDominationOverkillsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDominationOverkillsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3015;
  result->m_pszName = "DOMINATION_OVERKILLS_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)169;
  result->m_iGoal = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0D70
// Name: Create_CSDominationOverkillsHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDominationOverkillsHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3016;
  result->m_pszName = "DOMINATION_OVERKILLS_HIGH";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)169;
  result->m_iGoal = 100;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0DD0
// Name: Create_CSRevengesLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSRevengesLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3013;
  result->m_pszName = "REVENGES_LOW";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)170;
  result->m_iGoal = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0E30
// Name: Create_CSRevengesHigh
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSRevengesHigh()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3014;
  result->m_pszName = "REVENGES_HIGH";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)170;
  result->m_iGoal = 20;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0E90
// Name: private: virtual void CAchievementCS_ServerAwarded::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_ServerAwarded::Init(CAchievementCS_ServerAwarded *this)
{
  this->m_iGoal = 1;
  CBaseAchievement::SetFlags(this, iFlags: 128);
}

//------------------------------------------------------------------------------
// Address: 0x101B0EB0
// Name: Create_CSDefuseAndNeededKit
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDefuseAndNeededKit()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1003;
  result->m_pszName = "BOMB_DEFUSE_NEEDED_KIT";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0F00
// Name: Create_CSKilledDefuser
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKilledDefuser()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1005;
  result->m_pszName = "KILL_BOMB_DEFUSER";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0F50
// Name: Create_CSWinBombPlant
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinBombPlant()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1001;
  result->m_pszName = "WIN_BOMB_PLANT";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0FA0
// Name: Create_CSWinBombDefuse
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinBombDefuse()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1002;
  result->m_pszName = "WIN_BOMB_DEFUSE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B0FF0
// Name: Create_CSPlantBombWithin25Seconds
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSPlantBombWithin25Seconds()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1006;
  result->m_pszName = "BOMB_PLANT_IN_25_SECONDS";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1040
// Name: Create_CSRescueAllHostagesInARound
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSRescueAllHostagesInARound()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 2001;
  result->m_pszName = "RESCUE_ALL_HOSTAGES";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1090
// Name: Create_CSKillEnemyWithFormerGun
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemyWithFormerGun()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3039;
  result->m_pszName = "KILL_WITH_OWN_GUN";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B10E0
// Name: Create_CSKillingSpree
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillingSpree()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3006;
  result->m_pszName = "KILLING_SPREE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1130
// Name: Create_CSKillTwoWithOneShot
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillTwoWithOneShot()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3040;
  result->m_pszName = "KILL_TWO_WITH_ONE_SHOT";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1180
// Name: Create_CSKillEnemyReloading
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemyReloading()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3005;
  result->m_pszName = "KILL_ENEMY_RELOADING";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B11D0
// Name: Create_CSKillsWithMultipleGuns
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillsWithMultipleGuns()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3007;
  result->m_pszName = "KILLS_WITH_MULTIPLE_GUNS";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1220
// Name: Create_CSPosthumousGrenadeKill
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSPosthumousGrenadeKill()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5018;
  result->m_pszName = "DEAD_GRENADE_KILL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1270
// Name: Create_CSKillEnemyTeam
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemyTeam()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5019;
  result->m_pszName = "KILL_ENEMY_TEAM";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B12C0
// Name: Create_CSLastPlayerAlive
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSLastPlayerAlive()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5020;
  result->m_pszName = "LAST_PLAYER_ALIVE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1310
// Name: Create_CSKillEnemyLastBullet
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemyLastBullet()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5021;
  result->m_pszName = "KILL_ENEMY_LAST_BULLET";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1360
// Name: Create_CSKillingSpreeEnder
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillingSpreeEnder()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5022;
  result->m_pszName = "KILLING_SPREE_ENDER";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B13B0
// Name: Create_CSKillEnemiesWhileBlind
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemiesWhileBlind()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3021;
  result->m_pszName = "KILL_ENEMIES_WHILE_BLIND";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1400
// Name: Create_CSKillEnemiesWhileBlindHard
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemiesWhileBlindHard()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3022;
  result->m_pszName = "KILL_ENEMIES_WHILE_BLIND_HARD";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1450
// Name: Create_CSDamageNoKill
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDamageNoKill()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5023;
  result->m_pszName = "DAMAGE_NO_KILL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B14A0
// Name: Create_CSKillLowDamage
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillLowDamage()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5024;
  result->m_pszName = "KILL_LOW_DAMAGE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B14F0
// Name: Create_CSKilledRescuer
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKilledRescuer()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 2002;
  result->m_pszName = "KILL_HOSTAGE_RESCUER";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1540
// Name: Create_CSSurviveGrenade
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSSurviveGrenade()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3010;
  result->m_pszName = "SURVIVE_GRENADE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1590
// Name: Create_CSKilledDefuserWithGrenade
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKilledDefuserWithGrenade()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3027;
  result->m_pszName = "KILLED_DEFUSER_WITH_GRENADE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B15E0
// Name: Create_CSKillSniperWithSniper
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillSniperWithSniper()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3028;
  result->m_pszName = "KILL_SNIPER_WITH_SNIPER";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1630
// Name: Create_CSKillSniperWithKnife
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillSniperWithKnife()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3029;
  result->m_pszName = "KILL_SNIPER_WITH_KNIFE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1680
// Name: Create_CSHipShot
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSHipShot()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3030;
  result->m_pszName = "HIP_SHOT";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B16D0
// Name: Create_CSKillWhenAtLowHealth
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillWhenAtLowHealth()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3032;
  result->m_pszName = "KILL_WHEN_AT_LOW_HEALTH";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1720
// Name: Create_CSGrenadeMultikill
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGrenadeMultikill()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3035;
  result->m_pszName = "GRENADE_MULTIKILL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1770
// Name: Create_CSBombMultikill
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSBombMultikill()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1008;
  result->m_pszName = "BOMB_MULTIKILL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B17C0
// Name: Create_CSPistolRoundKnifeKill
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSPistolRoundKnifeKill()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3033;
  result->m_pszName = "PISTOL_ROUND_KNIFE_KILL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1810
// Name: Create_CSFastRoundWin
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSFastRoundWin()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5037;
  result->m_pszName = "FAST_ROUND_WIN";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1860
// Name: Create_CSSurviveManyAttacks
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSSurviveManyAttacks()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5025;
  result->m_pszName = "SURVIVE_MANY_ATTACKS";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B18B0
// Name: Create_CSGooseChase
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGooseChase()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1009;
  result->m_pszName = "GOOSE_CHASE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1900
// Name: Create_CSWinBombPlantAfterRecovery
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinBombPlantAfterRecovery()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1010;
  result->m_pszName = "WIN_BOMB_PLANT_AFTER_RECOVERY";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1950
// Name: Create_CSLosslessExtermination
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSLosslessExtermination()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5026;
  result->m_pszName = "LOSSLESS_EXTERMINATION";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B19A0
// Name: Create_CSFlawlessVictory
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSFlawlessVictory()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5027;
  result->m_pszName = "FLAWLESS_VICTORY";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B19F0
// Name: Create_CSWinDualDuel
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinDualDuel()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3034;
  result->m_pszName = "WIN_DUAL_DUEL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1A40
// Name: Create_CSFastHostageRescue
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSFastHostageRescue()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 2003;
  result->m_pszName = "FAST_HOSTAGE_RESCUE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1A90
// Name: Create_CSBreakWindows
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSBreakWindows()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5029;
  result->m_pszName = "BREAK_WINDOWS";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1AE0
// Name: Create_CSBreakProps
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSBreakProps()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5030;
  result->m_pszName = "BREAK_PROPS";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1B30
// Name: Create_CSUnstoppableForce
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSUnstoppableForce()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5031;
  result->m_pszName = "UNSTOPPABLE_FORCE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1B80
// Name: Create_CSImmovableObject
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSImmovableObject()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5032;
  result->m_pszName = "IMMOVABLE_OBJECT";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1BD0
// Name: Create_CSHeadshotsInRound
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSHeadshotsInRound()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5033;
  result->m_pszName = "HEADSHOTS_IN_ROUND";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1C20
// Name: Create_CSKillWhileInAir
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillWhileInAir()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3036;
  result->m_pszName = "KILL_WHILE_IN_AIR";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1C70
// Name: Create_CSKillEnemyInAir
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemyInAir()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3037;
  result->m_pszName = "KILL_ENEMY_IN_AIR";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1CC0
// Name: Create_CSKillerAndEnemyInAir
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillerAndEnemyInAir()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3038;
  result->m_pszName = "KILLER_AND_ENEMY_IN_AIR";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1D10
// Name: Create_CSSilentWin
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSSilentWin()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5039;
  result->m_pszName = "SILENT_WIN";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1D60
// Name: Create_CSBloodlessVictory
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSBloodlessVictory()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5040;
  result->m_pszName = "BLOODLESS_VICTORY";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1DB0
// Name: Create_CSWinRoundsWithoutBuying
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSWinRoundsWithoutBuying()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5042;
  result->m_pszName = "WIN_ROUNDS_WITHOUT_BUYING";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1E00
// Name: Create_CSDefuseDefense
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDefuseDefense()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1011;
  result->m_pszName = "DEFUSE_DEFENSE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1E50
// Name: Create_CSKillBombPickup
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillBombPickup()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1007;
  result->m_pszName = "KILL_BOMB_PICKUP";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1EA0
// Name: Create_CSConcurrentDominations
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSConcurrentDominations()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3019;
  result->m_pszName = "CONCURRENT_DOMINATIONS";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1EF0
// Name: Create_CSDominationOverkillsMatch
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSDominationOverkillsMatch()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3017;
  result->m_pszName = "DOMINATION_OVERKILLS_MATCH";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1F40
// Name: Create_CSExtendedDomination
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSExtendedDomination()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3018;
  result->m_pszName = "EXTENDED_DOMINATION";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1F90
// Name: Create_CSCauseFriendlyFireWithFlashbang
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSCauseFriendlyFireWithFlashbang()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 5044;
  result->m_pszName = "CAUSE_FRIENDLY_FIRE_WITH_FLASHBANG";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B1FF0
// Name: Create_CSGunGameKillKnifer
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGunGameKillKnifer()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3044;
  result->m_pszName = "GUN_GAME_KILL_KNIFER";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2040
// Name: Create_CSGunGameSelectFinalKnifeKill
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGunGameSelectFinalKnifeKill()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3045;
  result->m_pszName = "GUN_GAME_SELECT_KNIFE_KILL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2090
// Name: Create_CSGunGameKnifeSuicide
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGunGameKnifeSuicide()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3046;
  result->m_pszName = "GUN_GAME_SELECT_SUICIDE_WITH_KNIFE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B20E0
// Name: Create_CSGunGameKnifeKillKnifer
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGunGameKnifeKillKnifer()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3047;
  result->m_pszName = "GUN_GAME_KNIFE_KILL_KNIFER";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2130
// Name: Create_CSGunGameSMGKillKnifer
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGunGameSMGKillKnifer()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3048;
  result->m_pszName = "GUN_GAME_SMG_KILL_KNIFER";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2180
// Name: Create_CSGunGameProgressiveRampage
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGunGameProgressiveRampage()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6033;
  result->m_pszName = "GUN_GAME_RAMPAGE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B21D0
// Name: Create_CSGunGameFirstKill
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGunGameFirstKill()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6034;
  result->m_pszName = "GUN_GAME_FIRST_KILL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2220
// Name: Create_CSKillEnemyTerrTeamBeforeBombPlant
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemyTerrTeamBeforeBombPlant()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6035;
  result->m_pszName = "GUN_GAME_FIRST_THING_FIRST";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2270
// Name: Create_CSKillEnemyCTTeamBeforeBombPlant
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSKillEnemyCTTeamBeforeBombPlant()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6036;
  result->m_pszName = "GUN_GAME_TARGET_SECURED";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B22C0
// Name: Create_CSLastPlayerAliveGGSelect
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSLastPlayerAliveGGSelect()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6037;
  result->m_pszName = "IM_STILL_STANDING";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2310
// Name: Create_CSFirstBulletKills
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSFirstBulletKills()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3049;
  result->m_pszName = "ONE_SHOT_ONE_KILL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2360
// Name: Create_CSGunGameConservationist
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSGunGameConservationist()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6038;
  result->m_pszName = "GUN_GAME_CONSERVATIONIST";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B23B0
// Name: Create_CSSpawnCamper
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSSpawnCamper()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3050;
  result->m_pszName = "BASE_SCAMPER";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2400
// Name: Create_CSBornReady
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSBornReady()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3051;
  result->m_pszName = "BORN_READY";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2450
// Name: Create_CSStillAlive
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSStillAlive()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6039;
  result->m_pszName = "STILL_ALIVE";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B24A0
// Name: Create_CSSmorgasboard
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSSmorgasboard()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6040;
  result->m_pszName = "SMORGASBOARD";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B24F0
// Name: private: virtual void CAchievementCS_KillWithAllWeapons::OnPlayerStatsUpdate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_KillWithAllWeapons::OnPlayerStatsUpdate(
        CAchievementCS_KillWithAllWeapons *this,
        int nUserSlot)
{
  const StatsCollection_t *LifetimeStats; // eax
  int v4; // edx
  int v5; // ecx

  if ( !C_CSGameRules::IsPlayingGunGame(this: (C_CSGameRules *)g_pGameRules) )
  {
    LifetimeStats = CCSClientGameStats::GetLifetimeStats(this: &g_CSClientGameStats, nUserSlot);
    v4 = 20;
    v5 = 0;
    while ( LifetimeStats->m_iValue[v4] != 0 )
    {
      ++v5;
      v4 = dword_104A578C[5 * v5];
      if ( v4 == -1 )
      {
        CBaseAchievement::IncrementCount(this, iOptIncrement: 0);
        return;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B2550
// Name: private: virtual void CAchievementCS_KillWithAllWeapons::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_KillWithAllWeapons::Init(CAchievementCS_Medalist *this)
{
  CBaseAchievement::SetFlags(this, iFlags: 128);
  this->m_iGoal = 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B2570
// Name: private: virtual void CAchievementCS_WinEveryGGMap::OnPlayerStatsUpdate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_WinEveryGGMap::OnPlayerStatsUpdate(CAchievementCS_WinEveryGGMap *this, int nUserSlot)
{
  const StatsCollection_t *LifetimeStats; // eax
  int v4; // edx
  CSStatType_t v5; // ecx
  CSStatType_t mapStatsID[9]; // [esp+4h] [ebp-24h]

  mapStatsID[1] = CSSTAT_MAP_MATCHES_WON_BOATHOUSE;
  mapStatsID[2] = CSSTAT_MAP_MATCHES_WON_BANK;
  mapStatsID[3] = CSSTAT_MAP_MATCHES_WON_HOUSE;
  mapStatsID[4] = CSSTAT_MAP_MATCHES_WON_MILL;
  mapStatsID[5] = CSSTAT_MAP_MATCHES_WON_SHACKS;
  mapStatsID[6] = CSSTAT_MAP_MATCHES_WON_VIETNAM;
  mapStatsID[7] = CSSTAT_MAP_MATCHES_WON_TRAIN_REDUX;
  mapStatsID[8] = CSSTAT_MAX;
  LifetimeStats = CCSClientGameStats::GetLifetimeStats(this: &g_CSClientGameStats, nUserSlot);
  v4 = 0;
  v5 = CSSTAT_MAP_MATCHES_WON_BAGGAGE;
  while ( LifetimeStats->m_iValue[v5] != 0 )
  {
    v5 = mapStatsID[++v4];
    if ( v5 == CSSTAT_MAX )
    {
      CBaseAchievement::IncrementCount(this, iOptIncrement: 0);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B2650
// Name: private: virtual void CAchievementCS_PlayEveryGGMap::OnPlayerStatsUpdate(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_PlayEveryGGMap::OnPlayerStatsUpdate(CAchievementCS_PlayEveryGGMap *this, int nUserSlot)
{
  const StatsCollection_t *LifetimeStats; // eax
  int v4; // edx
  CSStatType_t v5; // ecx
  CSStatType_t mapStatsID[9]; // [esp+4h] [ebp-24h]

  mapStatsID[1] = CSSTAT_MAP_ROUNDS_DE_BOATHOUSE;
  mapStatsID[2] = CSSTAT_MAP_ROUNDS_DE_BANK;
  mapStatsID[3] = CSSTAT_MAP_ROUNDS_GG_VIETNAM;
  mapStatsID[4] = CSSTAT_MAP_ROUNDS_DE_HOUSE;
  mapStatsID[5] = CSSTAT_MAP_ROUNDS_TRAIN_REDUX;
  mapStatsID[6] = CSSTAT_MAP_ROUNDS_DE_MILL;
  mapStatsID[7] = CSSTAT_MAP_ROUNDS_DE_SHACKS;
  mapStatsID[8] = CSSTAT_MAX;
  LifetimeStats = CCSClientGameStats::GetLifetimeStats(this: &g_CSClientGameStats, nUserSlot);
  v4 = 0;
  v5 = CSSTAT_MAP_ROUNDS_GG_BAGGAGE;
  while ( LifetimeStats->m_iValue[v5] != 0 )
  {
    v5 = mapStatsID[++v4];
    if ( v5 == CSSTAT_MAX )
    {
      CBaseAchievement::IncrementCount(this, iOptIncrement: 0);
      return;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B26E0
// Name: private: virtual void CAchievementCS_AvengeFriend::ListenForEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_AvengeFriend::ListenForEvents(CAchievementCS_AvengeFriend *this)
{
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "player_avenged_teammate", a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x101B2700
// Name: private: virtual void CAchievementCS_AvengeFriend::FireGameEvent_Internal(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_AvengeFriend::FireGameEvent_Internal(
        CAchievementCS_AvengeFriend *this,
        IGameEvent *event)
{
  const char *v2; // eax
  int LocalPlayerIndex; // eax
  C_CSPlayer *v4; // edi
  int v5; // ebx
  IVEngineClient_vtbl *v6; // ebx
  int v7; // eax
  int v8; // eax
  C_BasePlayer *v9; // eax
  C_CSPlayer *v10; // eax

  v2 = event->GetName(this: event);
  if ( _V_strcmp(s1: v2, s2: "player_avenged_teammate") == 0 )
  {
    LocalPlayerIndex = GetLocalPlayerIndex();
    v4 = (C_CSPlayer *)UTIL_PlayerByIndex(entindex: LocalPlayerIndex);
    if ( v4 != nullptr && v4->IsPlayer(this: v4) )
    {
      v5 = event->GetInt(this: event, a2: "avenger_id", a3: 0);
      if ( C_BasePlayer::GetUserID(this: v4) == v5 )
      {
        v6 = engine->__vftable;
        v7 = event->GetInt(this: event, a2: "avenged_player_id", a3: 0);
        v8 = v6->GetPlayerForUserID(this: engine, a2: v7);
        if ( v8 > 0 )
        {
          v9 = UTIL_PlayerByIndex(entindex: v8);
          v10 = ToBasePlayer(pEntity: v9);
          if ( v10 != nullptr && C_CSPlayer::HasPlayerAsFriend(this: v4, player: v10) )
            CBaseAchievement::AwardAchievement(this);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B27D0
// Name: private: virtual void CAchievementCS_Medalist::ListenForEvents(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_Medalist::ListenForEvents(CAchievementCS_Medalist *this)
{
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: this, a3: "achievement_earned_local", a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x101B27F0
// Name: Create_CSEnemyKillsLow
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSEnemyKillsLow()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x98u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_StatGoal::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3001;
  result->m_pszName = "KILL_ENEMY_LOW";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  result[1].CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)2;
  result->m_iGoal = 25;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2850
// Name: Create_CSBombDefuseCloseCall
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CSBombDefuseCloseCall()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ServerAwarded::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 1004;
  result->m_pszName = "BOMB_DEFUSE_CLOSE_CALL";
  result->m_iPointValue = 5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B28A0
// Name: Create_CAchievementCS_KillWithAllWeapons
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_KillWithAllWeapons()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_KillWithAllWeapons::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_KillWithAllWeapons::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3024;
  result->m_pszName = "KILL_WITH_EVERY_WEAPON";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B28F0
// Name: Create_CAchievementCS_WinEveryGGMap
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_WinEveryGGMap()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_WinEveryGGMap::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_WinEveryGGMap::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6031;
  result->m_pszName = "WIN_EVERY_GUNGAME_MAP";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2940
// Name: Create_CAchievementCS_PlayEveryGGMap
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_PlayEveryGGMap()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_PlayEveryGGMap::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_PlayEveryGGMap::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6032;
  result->m_pszName = "PLAY_EVERY_GUNGAME_MAP";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2990
// Name: Create_CAchievementCS_AvengeFriend
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_AvengeFriend()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_AvengeFriend::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_AvengeFriend::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 3009;
  result->m_pszName = "AVENGE_FRIEND";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B29E0
// Name: Create_CAchievementCS_Medalist
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_Medalist()
{
  CBaseAchievement *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CBaseAchievement *)MemAlloc_Alloc(nSize: 0x90u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CBaseAchievement::CBaseAchievement(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_Medalist::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_Medalist::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 6041;
  result->m_pszName = "MEDALIST";
  result->m_iPointValue = 5;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2A30
// Name: public: CAchievement_Meta::CAchievement_Meta(void)
// Source: json
//------------------------------------------------------------------------------
CAchievement_Meta *__thiscall CAchievement_Meta::CAchievement_Meta(CAchievement_Meta *this)
{
  __int64 v2; // xmm0_8
  __int128 v4; // [esp-10h] [ebp-28h]
  __int64 v5; // [esp+8h] [ebp-10h]
  __int64 v6; // [esp+10h] [ebp-8h]

  CBaseAchievement::CBaseAchievement(this);
  this->CCSBaseAchievement::CBaseAchievement::CGameEventListener::IGameEventListener2::__vftable = (CAchievement_Meta_vtbl *)&CAchievement_Meta::`vftable'{for `CGameEventListener'};
  this->CCSBaseAchievement::CBaseAchievement::IAchievement::__vftable = (IAchievement_vtbl *)&CAchievement_Meta::`vftable'{for `IAchievement'};
  LODWORD(v5) = CAchievement_Meta::Steam_OnUserAchievementStored;
  HIDWORD(v5) = 0;
  v2 = v5;
  v6 = 0;
  *(_QWORD *)&this->m_CallbackUserAchievement.m_Func = v5;
  this->m_CallbackUserAchievement.m_nCallbackFlags = 0;
  this->m_CallbackUserAchievement.m_iCallback = 0;
  this->m_CallbackUserAchievement.__vftable = (CCallback<CAchievement_Meta,UserAchievementStored_t,0>_vtbl *)&CCallback<CAchievement_Meta,UserAchievementStored_t,0>::`vftable';
  this->m_CallbackUserAchievement.m_pObj = this;
  *((_QWORD *)&this->m_CallbackUserAchievement.m_Func + 1) = 0;
  if ( CAchievement_Meta::Steam_OnUserAchievementStored != nullptr )
  {
    *(_QWORD *)&v4 = v2;
    *((_QWORD *)&v4 + 1) = 0;
    CCallback<CAchievement_Meta,UserAchievementStored_t,0>::Register(
      this: &this->m_CallbackUserAchievement,
      pObj: this,
      func: v4);
  }
  this->m_requirements.m_Memory.m_pMemory = nullptr;
  this->m_requirements.m_Memory.m_nAllocationCount = 0;
  this->m_requirements.m_Memory.m_nGrowSize = 0;
  this->m_requirements.m_Size = 0;
  this->m_requirements.m_pElements = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B2AD0
// Name: public: virtual CAchievement_Meta::~CAchievement_Meta(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievement_Meta::~CAchievement_Meta(CAchievement_Meta *this)
{
  bool v2; // zf

  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_requirements);
  v2 = (this->m_CallbackUserAchievement.m_nCallbackFlags & 1) == 0;
  this->m_CallbackUserAchievement.__vftable = (CCallback<CAchievement_Meta,UserAchievementStored_t,0>_vtbl *)&CCallback<CAchievement_Meta,UserAchievementStored_t,0>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackUserAchievement);
  v2 = !this->m_bRegisteredForEvents;
  this->CCSBaseAchievement::CBaseAchievement::CGameEventListener::IGameEventListener2::__vftable = (CAchievement_Meta_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( !v2 )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: this);
    this->m_bRegisteredForEvents = false;
  }
  this->CCSBaseAchievement::CBaseAchievement::CGameEventListener::IGameEventListener2::__vftable = (CAchievement_Meta_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101B2B30
// Name: Create_CAchievementCS_PistolMaster
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_PistolMaster()
{
  CAchievement_Meta *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CAchievement_Meta *)MemAlloc_Alloc(nSize: 0xC8u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CAchievement_Meta::CAchievement_Meta(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_PistolMaster::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_PistolMaster::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4034;
  result->m_pszName = "META_PISTOL";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2B80
// Name: Create_CAchievementCS_RifleMaster
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_RifleMaster()
{
  CAchievement_Meta *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CAchievement_Meta *)MemAlloc_Alloc(nSize: 0xC8u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CAchievement_Meta::CAchievement_Meta(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_RifleMaster::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_RifleMaster::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4035;
  result->m_pszName = "META_RIFLE";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2BD0
// Name: Create_CAchievementCS_SubMachineGunMaster
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_SubMachineGunMaster()
{
  CAchievement_Meta *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CAchievement_Meta *)MemAlloc_Alloc(nSize: 0xC8u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CAchievement_Meta::CAchievement_Meta(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_SubMachineGunMaster::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_SubMachineGunMaster::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4036;
  result->m_pszName = "META_SMG";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2C20
// Name: Create_CAchievementCS_ShotgunMaster
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_ShotgunMaster()
{
  CAchievement_Meta *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CAchievement_Meta *)MemAlloc_Alloc(nSize: 0xC8u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CAchievement_Meta::CAchievement_Meta(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_ShotgunMaster::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_ShotgunMaster::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4037;
  result->m_pszName = "META_SHOTGUN";
  result->m_iPointValue = 10;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2C70
// Name: Create_CAchievementCS_WeaponMaster
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__cdecl Create_CAchievementCS_WeaponMaster()
{
  CAchievement_Meta *v0; // eax
  CBaseAchievement *v1; // esi
  CBaseAchievement *result; // eax

  v0 = (CAchievement_Meta *)MemAlloc_Alloc(nSize: 0xC8u);
  v1 = v0;
  if ( v0 != nullptr )
  {
    CAchievement_Meta::CAchievement_Meta(this: v0);
    v1->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CAchievementCS_WeaponMaster::`vftable'{for `CGameEventListener'};
    v1->IAchievement::__vftable = (IAchievement_vtbl *)&CAchievementCS_WeaponMaster::`vftable'{for `IAchievement'};
    result = v1;
  }
  else
  {
    result = nullptr;
  }
  result->m_iAchievementID = 4038;
  result->m_pszName = "META_WEAPONMASTER";
  result->m_iPointValue = 50;
  result->m_bHideUntilAchieved = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B2CF0
// Name: private: virtual void CAchievementCS_Medalist::FireGameEvent_Internal(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_Medalist::FireGameEvent_Internal(CAchievementCS_Medalist *this, IGameEvent *event)
{
  const char *v2; // eax
  int v3; // esi
  int Inorder; // edi
  CBaseAchievement *elem; // eax
  int totalEarnedAchievements; // [esp+10h] [ebp+8h]

  v2 = event->GetName(this: event);
  if ( _V_strcmp(s1: v2, s2: "achievement_earned_local") == 0 )
  {
    v3 = event->GetInt(this: event, a2: "splitscreenplayer", a3: 0);
    totalEarnedAchievements = 0;
    Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &g_AchievementMgrCS.m_mapAchievement[v3].m_Tree);
    if ( Inorder != 0xFFFF )
    {
      do
      {
        elem = g_AchievementMgrCS.m_mapAchievement[v3].m_Tree.m_Elements.m_pMemory[(unsigned __int16)Inorder].m_Data.elem;
        if ( elem != nullptr && elem->IsAchieved(this: &elem->IAchievement) )
          ++totalEarnedAchievements;
        Inorder = (unsigned __int16)CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                                      this: &g_AchievementMgrCS.m_mapAchievement[v3].m_Tree,
                                      i: Inorder);
      }
      while ( Inorder != 0xFFFF );
      if ( totalEarnedAchievements >= 167 )
        CBaseAchievement::AwardAchievement(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B2DC0
// Name: private: virtual void CAchievementCS_PistolMaster::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_PistolMaster::Init(CAchievementCS_PistolMaster *this)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_requirements; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax
  vgui::TreeNode **v8; // edi
  int v9; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax
  vgui::TreeNode **v13; // edi
  int v14; // eax
  vgui::TreeNode **v15; // ecx
  int v16; // eax
  vgui::TreeNode **v17; // eax
  vgui::TreeNode **v18; // edi
  int v19; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  vgui::TreeNode **v22; // eax
  vgui::TreeNode **v23; // edi
  int v24; // eax
  vgui::TreeNode **v25; // ecx
  int v26; // eax
  vgui::TreeNode **v27; // eax
  vgui::TreeNode **v28; // edi
  int v29; // eax
  vgui::TreeNode **v30; // ecx
  int v31; // eax
  vgui::TreeNode **v32; // eax
  vgui::TreeNode **v33; // edi
  int v34; // eax
  vgui::TreeNode **v35; // ecx
  int v36; // eax
  vgui::TreeNode **v37; // eax
  vgui::TreeNode **v38; // edi
  int v39; // eax
  vgui::TreeNode **v40; // ecx
  int v41; // eax
  vgui::TreeNode **v42; // eax
  vgui::TreeNode **v43; // edi
  int v44; // eax
  vgui::TreeNode **v45; // ecx
  int v46; // eax
  vgui::TreeNode **v47; // eax

  CBaseAchievement::SetFlags(this, iFlags: 128);
  this->m_iGoal = 1;
  m_Size = this->m_requirements.m_Size;
  m_nAllocationCount = this->m_requirements.m_Memory.m_nAllocationCount;
  p_m_requirements = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_requirements;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_requirements[1].m_pMemory;
  m_pMemory = p_m_requirements->m_pMemory;
  v6 = (int)p_m_requirements[1].m_pMemory - m_Size - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_requirements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)4001;
  v8 = p_m_requirements[1].m_pMemory;
  v9 = p_m_requirements->m_nAllocationCount;
  if ( (int)v8 + 1 > v9 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v8 - v9 + 1);
  ++p_m_requirements[1].m_pMemory;
  v10 = p_m_requirements->m_pMemory;
  v11 = (char *)p_m_requirements[1].m_pMemory - (char *)v8 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v10[(_DWORD)v8 + 1], src: (unsigned __int8 *)&v10[(_DWORD)v8], count: 4 * v11);
  v12 = &p_m_requirements->m_pMemory[(_DWORD)v8];
  if ( v12 != nullptr )
    *v12 = (vgui::TreeNode *)4002;
  v13 = p_m_requirements[1].m_pMemory;
  v14 = p_m_requirements->m_nAllocationCount;
  if ( (int)v13 + 1 > v14 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v13 - v14 + 1);
  ++p_m_requirements[1].m_pMemory;
  v15 = p_m_requirements->m_pMemory;
  v16 = (char *)p_m_requirements[1].m_pMemory - (char *)v13 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v16 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v15[(_DWORD)v13 + 1],
      src: (unsigned __int8 *)&v15[(_DWORD)v13],
      count: 4 * v16);
  v17 = &p_m_requirements->m_pMemory[(_DWORD)v13];
  if ( v17 != nullptr )
    *v17 = (vgui::TreeNode *)4003;
  v18 = p_m_requirements[1].m_pMemory;
  v19 = p_m_requirements->m_nAllocationCount;
  if ( (int)v18 + 1 > v19 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v18 - v19 + 1);
  ++p_m_requirements[1].m_pMemory;
  v20 = p_m_requirements->m_pMemory;
  v21 = (char *)p_m_requirements[1].m_pMemory - (char *)v18 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v21 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v20[(_DWORD)v18 + 1],
      src: (unsigned __int8 *)&v20[(_DWORD)v18],
      count: 4 * v21);
  v22 = &p_m_requirements->m_pMemory[(_DWORD)v18];
  if ( v22 != nullptr )
    *v22 = (vgui::TreeNode *)4004;
  v23 = p_m_requirements[1].m_pMemory;
  v24 = p_m_requirements->m_nAllocationCount;
  if ( (int)v23 + 1 > v24 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v23 - v24 + 1);
  ++p_m_requirements[1].m_pMemory;
  v25 = p_m_requirements->m_pMemory;
  v26 = (char *)p_m_requirements[1].m_pMemory - (char *)v23 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v26 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v25[(_DWORD)v23 + 1],
      src: (unsigned __int8 *)&v25[(_DWORD)v23],
      count: 4 * v26);
  v27 = &p_m_requirements->m_pMemory[(_DWORD)v23];
  if ( v27 != nullptr )
    *v27 = (vgui::TreeNode *)4005;
  v28 = p_m_requirements[1].m_pMemory;
  v29 = p_m_requirements->m_nAllocationCount;
  if ( (int)v28 + 1 > v29 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v28 - v29 + 1);
  ++p_m_requirements[1].m_pMemory;
  v30 = p_m_requirements->m_pMemory;
  v31 = (char *)p_m_requirements[1].m_pMemory - (char *)v28 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v31 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v30[(_DWORD)v28 + 1],
      src: (unsigned __int8 *)&v30[(_DWORD)v28],
      count: 4 * v31);
  v32 = &p_m_requirements->m_pMemory[(_DWORD)v28];
  if ( v32 != nullptr )
    *v32 = (vgui::TreeNode *)4006;
  v33 = p_m_requirements[1].m_pMemory;
  v34 = p_m_requirements->m_nAllocationCount;
  if ( (int)v33 + 1 > v34 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v33 - v34 + 1);
  ++p_m_requirements[1].m_pMemory;
  v35 = p_m_requirements->m_pMemory;
  v36 = (char *)p_m_requirements[1].m_pMemory - (char *)v33 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v36 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v35[(_DWORD)v33 + 1],
      src: (unsigned __int8 *)&v35[(_DWORD)v33],
      count: 4 * v36);
  v37 = &p_m_requirements->m_pMemory[(_DWORD)v33];
  if ( v37 != nullptr )
    *v37 = (vgui::TreeNode *)4007;
  v38 = p_m_requirements[1].m_pMemory;
  v39 = p_m_requirements->m_nAllocationCount;
  if ( (int)v38 + 1 > v39 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v38 - v39 + 1);
  ++p_m_requirements[1].m_pMemory;
  v40 = p_m_requirements->m_pMemory;
  v41 = (char *)p_m_requirements[1].m_pMemory - (char *)v38 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v41 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v40[(_DWORD)v38 + 1],
      src: (unsigned __int8 *)&v40[(_DWORD)v38],
      count: 4 * v41);
  v42 = &p_m_requirements->m_pMemory[(_DWORD)v38];
  if ( v42 != nullptr )
    *v42 = (vgui::TreeNode *)4008;
  v43 = p_m_requirements[1].m_pMemory;
  v44 = p_m_requirements->m_nAllocationCount;
  if ( (int)v43 + 1 > v44 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v43 - v44 + 1);
  ++p_m_requirements[1].m_pMemory;
  v45 = p_m_requirements->m_pMemory;
  v46 = (char *)p_m_requirements[1].m_pMemory - (char *)v43 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v46 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v45[(_DWORD)v43 + 1],
      src: (unsigned __int8 *)&v45[(_DWORD)v43],
      count: 4 * v46);
  v47 = &p_m_requirements->m_pMemory[(_DWORD)v43];
  if ( v47 != nullptr )
    *v47 = (vgui::TreeNode *)4009;
}

//------------------------------------------------------------------------------
// Address: 0x101B30E0
// Name: private: virtual void CAchievementCS_RifleMaster::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_RifleMaster::Init(CAchievementCS_RifleMaster *this)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_requirements; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax
  vgui::TreeNode **v8; // edi
  int v9; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax
  vgui::TreeNode **v13; // edi
  int v14; // eax
  vgui::TreeNode **v15; // ecx
  int v16; // eax
  vgui::TreeNode **v17; // eax
  vgui::TreeNode **v18; // edi
  int v19; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  vgui::TreeNode **v22; // eax
  vgui::TreeNode **v23; // edi
  int v24; // eax
  vgui::TreeNode **v25; // ecx
  int v26; // eax
  vgui::TreeNode **v27; // eax
  vgui::TreeNode **v28; // edi
  int v29; // eax
  vgui::TreeNode **v30; // ecx
  int v31; // eax
  vgui::TreeNode **v32; // eax
  vgui::TreeNode **v33; // edi
  int v34; // eax
  vgui::TreeNode **v35; // ecx
  int v36; // eax
  vgui::TreeNode **v37; // eax
  vgui::TreeNode **v38; // edi
  int v39; // eax
  vgui::TreeNode **v40; // ecx
  int v41; // eax
  vgui::TreeNode **v42; // eax
  vgui::TreeNode **v43; // edi
  int v44; // eax
  vgui::TreeNode **v45; // ecx
  int v46; // eax
  vgui::TreeNode **v47; // eax
  vgui::TreeNode **v48; // edi
  int v49; // eax
  vgui::TreeNode **v50; // ecx
  int v51; // eax
  vgui::TreeNode **v52; // eax

  CBaseAchievement::SetFlags(this, iFlags: 128);
  this->m_iGoal = 1;
  m_Size = this->m_requirements.m_Size;
  m_nAllocationCount = this->m_requirements.m_Memory.m_nAllocationCount;
  p_m_requirements = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_requirements;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_requirements[1].m_pMemory;
  m_pMemory = p_m_requirements->m_pMemory;
  v6 = (int)p_m_requirements[1].m_pMemory - m_Size - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_requirements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)4010;
  v8 = p_m_requirements[1].m_pMemory;
  v9 = p_m_requirements->m_nAllocationCount;
  if ( (int)v8 + 1 > v9 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v8 - v9 + 1);
  ++p_m_requirements[1].m_pMemory;
  v10 = p_m_requirements->m_pMemory;
  v11 = (char *)p_m_requirements[1].m_pMemory - (char *)v8 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v10[(_DWORD)v8 + 1], src: (unsigned __int8 *)&v10[(_DWORD)v8], count: 4 * v11);
  v12 = &p_m_requirements->m_pMemory[(_DWORD)v8];
  if ( v12 != nullptr )
    *v12 = (vgui::TreeNode *)4011;
  v13 = p_m_requirements[1].m_pMemory;
  v14 = p_m_requirements->m_nAllocationCount;
  if ( (int)v13 + 1 > v14 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v13 - v14 + 1);
  ++p_m_requirements[1].m_pMemory;
  v15 = p_m_requirements->m_pMemory;
  v16 = (char *)p_m_requirements[1].m_pMemory - (char *)v13 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v16 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v15[(_DWORD)v13 + 1],
      src: (unsigned __int8 *)&v15[(_DWORD)v13],
      count: 4 * v16);
  v17 = &p_m_requirements->m_pMemory[(_DWORD)v13];
  if ( v17 != nullptr )
    *v17 = (vgui::TreeNode *)4012;
  v18 = p_m_requirements[1].m_pMemory;
  v19 = p_m_requirements->m_nAllocationCount;
  if ( (int)v18 + 1 > v19 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v18 - v19 + 1);
  ++p_m_requirements[1].m_pMemory;
  v20 = p_m_requirements->m_pMemory;
  v21 = (char *)p_m_requirements[1].m_pMemory - (char *)v18 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v21 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v20[(_DWORD)v18 + 1],
      src: (unsigned __int8 *)&v20[(_DWORD)v18],
      count: 4 * v21);
  v22 = &p_m_requirements->m_pMemory[(_DWORD)v18];
  if ( v22 != nullptr )
    *v22 = (vgui::TreeNode *)4013;
  v23 = p_m_requirements[1].m_pMemory;
  v24 = p_m_requirements->m_nAllocationCount;
  if ( (int)v23 + 1 > v24 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v23 - v24 + 1);
  ++p_m_requirements[1].m_pMemory;
  v25 = p_m_requirements->m_pMemory;
  v26 = (char *)p_m_requirements[1].m_pMemory - (char *)v23 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v26 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v25[(_DWORD)v23 + 1],
      src: (unsigned __int8 *)&v25[(_DWORD)v23],
      count: 4 * v26);
  v27 = &p_m_requirements->m_pMemory[(_DWORD)v23];
  if ( v27 != nullptr )
    *v27 = (vgui::TreeNode *)4014;
  v28 = p_m_requirements[1].m_pMemory;
  v29 = p_m_requirements->m_nAllocationCount;
  if ( (int)v28 + 1 > v29 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v28 - v29 + 1);
  ++p_m_requirements[1].m_pMemory;
  v30 = p_m_requirements->m_pMemory;
  v31 = (char *)p_m_requirements[1].m_pMemory - (char *)v28 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v31 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v30[(_DWORD)v28 + 1],
      src: (unsigned __int8 *)&v30[(_DWORD)v28],
      count: 4 * v31);
  v32 = &p_m_requirements->m_pMemory[(_DWORD)v28];
  if ( v32 != nullptr )
    *v32 = (vgui::TreeNode *)4015;
  v33 = p_m_requirements[1].m_pMemory;
  v34 = p_m_requirements->m_nAllocationCount;
  if ( (int)v33 + 1 > v34 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v33 - v34 + 1);
  ++p_m_requirements[1].m_pMemory;
  v35 = p_m_requirements->m_pMemory;
  v36 = (char *)p_m_requirements[1].m_pMemory - (char *)v33 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v36 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v35[(_DWORD)v33 + 1],
      src: (unsigned __int8 *)&v35[(_DWORD)v33],
      count: 4 * v36);
  v37 = &p_m_requirements->m_pMemory[(_DWORD)v33];
  if ( v37 != nullptr )
    *v37 = (vgui::TreeNode *)4016;
  v38 = p_m_requirements[1].m_pMemory;
  v39 = p_m_requirements->m_nAllocationCount;
  if ( (int)v38 + 1 > v39 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v38 - v39 + 1);
  ++p_m_requirements[1].m_pMemory;
  v40 = p_m_requirements->m_pMemory;
  v41 = (char *)p_m_requirements[1].m_pMemory - (char *)v38 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v41 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v40[(_DWORD)v38 + 1],
      src: (unsigned __int8 *)&v40[(_DWORD)v38],
      count: 4 * v41);
  v42 = &p_m_requirements->m_pMemory[(_DWORD)v38];
  if ( v42 != nullptr )
    *v42 = (vgui::TreeNode *)4017;
  v43 = p_m_requirements[1].m_pMemory;
  v44 = p_m_requirements->m_nAllocationCount;
  if ( (int)v43 + 1 > v44 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v43 - v44 + 1);
  ++p_m_requirements[1].m_pMemory;
  v45 = p_m_requirements->m_pMemory;
  v46 = (char *)p_m_requirements[1].m_pMemory - (char *)v43 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v46 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v45[(_DWORD)v43 + 1],
      src: (unsigned __int8 *)&v45[(_DWORD)v43],
      count: 4 * v46);
  v47 = &p_m_requirements->m_pMemory[(_DWORD)v43];
  if ( v47 != nullptr )
    *v47 = (vgui::TreeNode *)4018;
  v48 = p_m_requirements[1].m_pMemory;
  v49 = p_m_requirements->m_nAllocationCount;
  if ( (int)v48 + 1 > v49 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v48 - v49 + 1);
  ++p_m_requirements[1].m_pMemory;
  v50 = p_m_requirements->m_pMemory;
  v51 = (char *)p_m_requirements[1].m_pMemory - (char *)v48 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v51 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v50[(_DWORD)v48 + 1],
      src: (unsigned __int8 *)&v50[(_DWORD)v48],
      count: 4 * v51);
  v52 = &p_m_requirements->m_pMemory[(_DWORD)v48];
  if ( v52 != nullptr )
    *v52 = (vgui::TreeNode *)4019;
}

//------------------------------------------------------------------------------
// Address: 0x101B3450
// Name: private: virtual void CAchievementCS_SubMachineGunMaster::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_SubMachineGunMaster::Init(CAchievementCS_SubMachineGunMaster *this)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_requirements; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax
  vgui::TreeNode **v8; // edi
  int v9; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax
  vgui::TreeNode **v13; // edi
  int v14; // eax
  vgui::TreeNode **v15; // ecx
  int v16; // eax
  vgui::TreeNode **v17; // eax
  vgui::TreeNode **v18; // edi
  int v19; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  vgui::TreeNode **v22; // eax
  vgui::TreeNode **v23; // edi
  int v24; // eax
  vgui::TreeNode **v25; // ecx
  int v26; // eax
  vgui::TreeNode **v27; // eax

  CBaseAchievement::SetFlags(this, iFlags: 128);
  this->m_iGoal = 1;
  m_Size = this->m_requirements.m_Size;
  m_nAllocationCount = this->m_requirements.m_Memory.m_nAllocationCount;
  p_m_requirements = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_requirements;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_requirements[1].m_pMemory;
  m_pMemory = p_m_requirements->m_pMemory;
  v6 = (int)p_m_requirements[1].m_pMemory - m_Size - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_requirements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)4020;
  v8 = p_m_requirements[1].m_pMemory;
  v9 = p_m_requirements->m_nAllocationCount;
  if ( (int)v8 + 1 > v9 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v8 - v9 + 1);
  ++p_m_requirements[1].m_pMemory;
  v10 = p_m_requirements->m_pMemory;
  v11 = (char *)p_m_requirements[1].m_pMemory - (char *)v8 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v10[(_DWORD)v8 + 1], src: (unsigned __int8 *)&v10[(_DWORD)v8], count: 4 * v11);
  v12 = &p_m_requirements->m_pMemory[(_DWORD)v8];
  if ( v12 != nullptr )
    *v12 = (vgui::TreeNode *)4021;
  v13 = p_m_requirements[1].m_pMemory;
  v14 = p_m_requirements->m_nAllocationCount;
  if ( (int)v13 + 1 > v14 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v13 - v14 + 1);
  ++p_m_requirements[1].m_pMemory;
  v15 = p_m_requirements->m_pMemory;
  v16 = (char *)p_m_requirements[1].m_pMemory - (char *)v13 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v16 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v15[(_DWORD)v13 + 1],
      src: (unsigned __int8 *)&v15[(_DWORD)v13],
      count: 4 * v16);
  v17 = &p_m_requirements->m_pMemory[(_DWORD)v13];
  if ( v17 != nullptr )
    *v17 = (vgui::TreeNode *)4022;
  v18 = p_m_requirements[1].m_pMemory;
  v19 = p_m_requirements->m_nAllocationCount;
  if ( (int)v18 + 1 > v19 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v18 - v19 + 1);
  ++p_m_requirements[1].m_pMemory;
  v20 = p_m_requirements->m_pMemory;
  v21 = (char *)p_m_requirements[1].m_pMemory - (char *)v18 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v21 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v20[(_DWORD)v18 + 1],
      src: (unsigned __int8 *)&v20[(_DWORD)v18],
      count: 4 * v21);
  v22 = &p_m_requirements->m_pMemory[(_DWORD)v18];
  if ( v22 != nullptr )
    *v22 = (vgui::TreeNode *)4023;
  v23 = p_m_requirements[1].m_pMemory;
  v24 = p_m_requirements->m_nAllocationCount;
  if ( (int)v23 + 1 > v24 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v23 - v24 + 1);
  ++p_m_requirements[1].m_pMemory;
  v25 = p_m_requirements->m_pMemory;
  v26 = (char *)p_m_requirements[1].m_pMemory - (char *)v23 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v26 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v25[(_DWORD)v23 + 1],
      src: (unsigned __int8 *)&v25[(_DWORD)v23],
      count: 4 * v26);
  v27 = &p_m_requirements->m_pMemory[(_DWORD)v23];
  if ( v27 != nullptr )
    *v27 = (vgui::TreeNode *)4024;
}

//------------------------------------------------------------------------------
// Address: 0x101B3620
// Name: private: virtual void CAchievementCS_ShotgunMaster::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_ShotgunMaster::Init(CAchievementCS_ShotgunMaster *this)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_requirements; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax
  vgui::TreeNode **v8; // edi
  int v9; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax
  vgui::TreeNode **v13; // edi
  int v14; // eax
  vgui::TreeNode **v15; // ecx
  int v16; // eax
  vgui::TreeNode **v17; // eax
  vgui::TreeNode **v18; // edi
  int v19; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  vgui::TreeNode **v22; // eax

  CBaseAchievement::SetFlags(this, iFlags: 128);
  this->m_iGoal = 1;
  m_Size = this->m_requirements.m_Size;
  m_nAllocationCount = this->m_requirements.m_Memory.m_nAllocationCount;
  p_m_requirements = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_requirements;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_requirements[1].m_pMemory;
  m_pMemory = p_m_requirements->m_pMemory;
  v6 = (int)p_m_requirements[1].m_pMemory - m_Size - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_requirements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)4025;
  v8 = p_m_requirements[1].m_pMemory;
  v9 = p_m_requirements->m_nAllocationCount;
  if ( (int)v8 + 1 > v9 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v8 - v9 + 1);
  ++p_m_requirements[1].m_pMemory;
  v10 = p_m_requirements->m_pMemory;
  v11 = (char *)p_m_requirements[1].m_pMemory - (char *)v8 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v10[(_DWORD)v8 + 1], src: (unsigned __int8 *)&v10[(_DWORD)v8], count: 4 * v11);
  v12 = &p_m_requirements->m_pMemory[(_DWORD)v8];
  if ( v12 != nullptr )
    *v12 = (vgui::TreeNode *)4026;
  v13 = p_m_requirements[1].m_pMemory;
  v14 = p_m_requirements->m_nAllocationCount;
  if ( (int)v13 + 1 > v14 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v13 - v14 + 1);
  ++p_m_requirements[1].m_pMemory;
  v15 = p_m_requirements->m_pMemory;
  v16 = (char *)p_m_requirements[1].m_pMemory - (char *)v13 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v16 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v15[(_DWORD)v13 + 1],
      src: (unsigned __int8 *)&v15[(_DWORD)v13],
      count: 4 * v16);
  v17 = &p_m_requirements->m_pMemory[(_DWORD)v13];
  if ( v17 != nullptr )
    *v17 = (vgui::TreeNode *)4027;
  v18 = p_m_requirements[1].m_pMemory;
  v19 = p_m_requirements->m_nAllocationCount;
  if ( (int)v18 + 1 > v19 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v18 - v19 + 1);
  ++p_m_requirements[1].m_pMemory;
  v20 = p_m_requirements->m_pMemory;
  v21 = (char *)p_m_requirements[1].m_pMemory - (char *)v18 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v21 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v20[(_DWORD)v18 + 1],
      src: (unsigned __int8 *)&v20[(_DWORD)v18],
      count: 4 * v21);
  v22 = &p_m_requirements->m_pMemory[(_DWORD)v18];
  if ( v22 != nullptr )
    *v22 = (vgui::TreeNode *)4028;
}

//------------------------------------------------------------------------------
// Address: 0x101B37A0
// Name: private: virtual void CAchievementCS_WeaponMaster::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementCS_WeaponMaster::Init(CAchievementCS_WeaponMaster *this)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_requirements; // esi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax
  vgui::TreeNode **v8; // edi
  int v9; // eax
  vgui::TreeNode **v10; // ecx
  int v11; // eax
  vgui::TreeNode **v12; // eax
  vgui::TreeNode **v13; // edi
  int v14; // eax
  vgui::TreeNode **v15; // ecx
  int v16; // eax
  vgui::TreeNode **v17; // eax
  vgui::TreeNode **v18; // edi
  int v19; // eax
  vgui::TreeNode **v20; // ecx
  int v21; // eax
  vgui::TreeNode **v22; // eax
  vgui::TreeNode **v23; // edi
  int v24; // eax
  vgui::TreeNode **v25; // ecx
  int v26; // eax
  vgui::TreeNode **v27; // eax
  vgui::TreeNode **v28; // edi
  int v29; // eax
  vgui::TreeNode **v30; // ecx
  int v31; // eax
  vgui::TreeNode **v32; // eax
  vgui::TreeNode **v33; // edi
  int v34; // eax
  vgui::TreeNode **v35; // ecx
  int v36; // eax
  vgui::TreeNode **v37; // eax
  vgui::TreeNode **v38; // edi
  int v39; // eax
  vgui::TreeNode **v40; // ecx
  int v41; // eax
  vgui::TreeNode **v42; // eax
  vgui::TreeNode **v43; // edi
  int v44; // eax
  vgui::TreeNode **v45; // ecx
  int v46; // eax
  vgui::TreeNode **v47; // eax

  CBaseAchievement::SetFlags(this, iFlags: 128);
  this->m_iGoal = 1;
  m_Size = this->m_requirements.m_Size;
  m_nAllocationCount = this->m_requirements.m_Memory.m_nAllocationCount;
  p_m_requirements = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_requirements;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: m_Size - m_nAllocationCount + 1);
  ++p_m_requirements[1].m_pMemory;
  m_pMemory = p_m_requirements->m_pMemory;
  v6 = (int)p_m_requirements[1].m_pMemory - m_Size - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v6 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v6);
  v7 = &p_m_requirements->m_pMemory[m_Size];
  if ( v7 != nullptr )
    *v7 = (vgui::TreeNode *)4034;
  v8 = p_m_requirements[1].m_pMemory;
  v9 = p_m_requirements->m_nAllocationCount;
  if ( (int)v8 + 1 > v9 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v8 - v9 + 1);
  ++p_m_requirements[1].m_pMemory;
  v10 = p_m_requirements->m_pMemory;
  v11 = (char *)p_m_requirements[1].m_pMemory - (char *)v8 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: (unsigned __int8 *)&v10[(_DWORD)v8 + 1], src: (unsigned __int8 *)&v10[(_DWORD)v8], count: 4 * v11);
  v12 = &p_m_requirements->m_pMemory[(_DWORD)v8];
  if ( v12 != nullptr )
    *v12 = (vgui::TreeNode *)4035;
  v13 = p_m_requirements[1].m_pMemory;
  v14 = p_m_requirements->m_nAllocationCount;
  if ( (int)v13 + 1 > v14 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v13 - v14 + 1);
  ++p_m_requirements[1].m_pMemory;
  v15 = p_m_requirements->m_pMemory;
  v16 = (char *)p_m_requirements[1].m_pMemory - (char *)v13 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v16 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v15[(_DWORD)v13 + 1],
      src: (unsigned __int8 *)&v15[(_DWORD)v13],
      count: 4 * v16);
  v17 = &p_m_requirements->m_pMemory[(_DWORD)v13];
  if ( v17 != nullptr )
    *v17 = (vgui::TreeNode *)4036;
  v18 = p_m_requirements[1].m_pMemory;
  v19 = p_m_requirements->m_nAllocationCount;
  if ( (int)v18 + 1 > v19 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v18 - v19 + 1);
  ++p_m_requirements[1].m_pMemory;
  v20 = p_m_requirements->m_pMemory;
  v21 = (char *)p_m_requirements[1].m_pMemory - (char *)v18 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v21 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v20[(_DWORD)v18 + 1],
      src: (unsigned __int8 *)&v20[(_DWORD)v18],
      count: 4 * v21);
  v22 = &p_m_requirements->m_pMemory[(_DWORD)v18];
  if ( v22 != nullptr )
    *v22 = (vgui::TreeNode *)4037;
  v23 = p_m_requirements[1].m_pMemory;
  v24 = p_m_requirements->m_nAllocationCount;
  if ( (int)v23 + 1 > v24 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v23 - v24 + 1);
  ++p_m_requirements[1].m_pMemory;
  v25 = p_m_requirements->m_pMemory;
  v26 = (char *)p_m_requirements[1].m_pMemory - (char *)v23 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v26 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v25[(_DWORD)v23 + 1],
      src: (unsigned __int8 *)&v25[(_DWORD)v23],
      count: 4 * v26);
  v27 = &p_m_requirements->m_pMemory[(_DWORD)v23];
  if ( v27 != nullptr )
    *v27 = (vgui::TreeNode *)4029;
  v28 = p_m_requirements[1].m_pMemory;
  v29 = p_m_requirements->m_nAllocationCount;
  if ( (int)v28 + 1 > v29 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v28 - v29 + 1);
  ++p_m_requirements[1].m_pMemory;
  v30 = p_m_requirements->m_pMemory;
  v31 = (char *)p_m_requirements[1].m_pMemory - (char *)v28 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v31 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v30[(_DWORD)v28 + 1],
      src: (unsigned __int8 *)&v30[(_DWORD)v28],
      count: 4 * v31);
  v32 = &p_m_requirements->m_pMemory[(_DWORD)v28];
  if ( v32 != nullptr )
    *v32 = (vgui::TreeNode *)4030;
  v33 = p_m_requirements[1].m_pMemory;
  v34 = p_m_requirements->m_nAllocationCount;
  if ( (int)v33 + 1 > v34 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v33 - v34 + 1);
  ++p_m_requirements[1].m_pMemory;
  v35 = p_m_requirements->m_pMemory;
  v36 = (char *)p_m_requirements[1].m_pMemory - (char *)v33 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v36 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v35[(_DWORD)v33 + 1],
      src: (unsigned __int8 *)&v35[(_DWORD)v33],
      count: 4 * v36);
  v37 = &p_m_requirements->m_pMemory[(_DWORD)v33];
  if ( v37 != nullptr )
    *v37 = (vgui::TreeNode *)4031;
  v38 = p_m_requirements[1].m_pMemory;
  v39 = p_m_requirements->m_nAllocationCount;
  if ( (int)v38 + 1 > v39 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v38 - v39 + 1);
  ++p_m_requirements[1].m_pMemory;
  v40 = p_m_requirements->m_pMemory;
  v41 = (char *)p_m_requirements[1].m_pMemory - (char *)v38 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v41 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v40[(_DWORD)v38 + 1],
      src: (unsigned __int8 *)&v40[(_DWORD)v38],
      count: 4 * v41);
  v42 = &p_m_requirements->m_pMemory[(_DWORD)v38];
  if ( v42 != nullptr )
    *v42 = (vgui::TreeNode *)4032;
  v43 = p_m_requirements[1].m_pMemory;
  v44 = p_m_requirements->m_nAllocationCount;
  if ( (int)v43 + 1 > v44 )
    CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_requirements, num: (int)v43 - v44 + 1);
  ++p_m_requirements[1].m_pMemory;
  v45 = p_m_requirements->m_pMemory;
  v46 = (char *)p_m_requirements[1].m_pMemory - (char *)v43 - 1;
  p_m_requirements[1].m_nAllocationCount = (int)p_m_requirements->m_pMemory;
  if ( v46 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&v45[(_DWORD)v43 + 1],
      src: (unsigned __int8 *)&v45[(_DWORD)v43],
      count: 4 * v46);
  v47 = &p_m_requirements->m_pMemory[(_DWORD)v43];
  if ( v47 != nullptr )
    *v47 = (vgui::TreeNode *)4033;
}

//------------------------------------------------------------------------------
// Address: 0x104205F0
// Name: _dynamic_initializer_for__achievements_easymode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__achievements_easymode__()
{
  ConVar::ConVar(
    this: &achievements_easymode,
    pName: "achievement_easymode",
    pDefaultValue: "0",
    flags: 10,
    pHelpString: "Enables all stat-based achievements to be earned at 10% of goals");
  return atexit(func: dynamic_atexit_destructor_for__achievements_easymode__);
}

//------------------------------------------------------------------------------
// Address: 0x104350F0
// Name: _dynamic_atexit_destructor_for__achievements_easymode__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__achievements_easymode__()
{
  ConVar::~ConVar(this: &achievements_easymode);
}

//------------------------------------------------------------------------------
// Address: 0x10420620
// Name: _dynamic_initializer_for__g_AchievementMgrCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_AchievementMgrCS__()
{
  CAchievementMgr::CAchievementMgr(this: &g_AchievementMgrCS);
  return atexit(func: dynamic_atexit_destructor_for__g_AchievementMgrCS__);
}

//------------------------------------------------------------------------------
// Address: 0x10420640
// Name: _dynamic_initializer_for__g_CSEnemyKillsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420660
// Name: _dynamic_initializer_for__g_CSEnemyKillsMed_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsMed_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsMed_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsMed_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420680
// Name: _dynamic_initializer_for__g_CSEnemyKillsHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104206A0
// Name: _dynamic_initializer_for__g_CSWinRoundsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinRoundsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinRoundsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinRoundsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104206C0
// Name: _dynamic_initializer_for__g_CSWinRoundsMed_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinRoundsMed_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinRoundsMed_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinRoundsMed_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104206E0
// Name: _dynamic_initializer_for__g_CSWinRoundsHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinRoundsHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinRoundsHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinRoundsHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420700
// Name: _dynamic_initializer_for__g_CSGGWinRoundsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGGWinRoundsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGGWinRoundsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGGWinRoundsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420720
// Name: _dynamic_initializer_for__g_CSGGWinRoundsMed_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGGWinRoundsMed_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGGWinRoundsMed_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGGWinRoundsMed_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420740
// Name: _dynamic_initializer_for__g_CSGGWinRoundsHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGGWinRoundsHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGGWinRoundsHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGGWinRoundsHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420760
// Name: _dynamic_initializer_for__g_CSGGWinRoundsExtreme_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGGWinRoundsExtreme_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGGWinRoundsExtreme_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGGWinRoundsExtreme_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420780
// Name: _dynamic_initializer_for__g_CSGGWinRoundsUltimate_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGGWinRoundsUltimate_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGGWinRoundsUltimate_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGGWinRoundsUltimate_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104207A0
// Name: _dynamic_initializer_for__g_CSGGRoundsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGGRoundsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGGRoundsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGGRoundsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104207C0
// Name: _dynamic_initializer_for__g_CSGGRoundsMed_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGGRoundsMed_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGGRoundsMed_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGGRoundsMed_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104207E0
// Name: _dynamic_initializer_for__g_CSGGRoundsHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGGRoundsHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGGRoundsHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGGRoundsHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420800
// Name: _dynamic_initializer_for__g_CSWinPistolRoundsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinPistolRoundsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinPistolRoundsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinPistolRoundsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420820
// Name: _dynamic_initializer_for__g_CSWinPistolRoundsMed_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinPistolRoundsMed_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinPistolRoundsMed_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinPistolRoundsMed_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420840
// Name: _dynamic_initializer_for__g_CSWinPistolRoundsHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinPistolRoundsHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinPistolRoundsHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinPistolRoundsHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420860
// Name: _dynamic_initializer_for__g_CSMoneyEarnedLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSMoneyEarnedLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSMoneyEarnedLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSMoneyEarnedLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420880
// Name: _dynamic_initializer_for__g_CSMoneyEarnedMed_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSMoneyEarnedMed_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSMoneyEarnedMed_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSMoneyEarnedMed_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104208A0
// Name: _dynamic_initializer_for__g_CSMoneyEarnedHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSMoneyEarnedHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSMoneyEarnedHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSMoneyEarnedHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104208C0
// Name: _dynamic_initializer_for__g_CSGiveDamageLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGiveDamageLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGiveDamageLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGiveDamageLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104208E0
// Name: _dynamic_initializer_for__g_CSGiveDamageMed_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGiveDamageMed_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGiveDamageMed_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGiveDamageMed_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420900
// Name: _dynamic_initializer_for__g_CSGiveDamageHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGiveDamageHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGiveDamageHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGiveDamageHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420920
// Name: _dynamic_initializer_for__g_CSEnemyKillsDeagle_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsDeagle_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsDeagle_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsDeagle_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420940
// Name: _dynamic_initializer_for__g_CSEnemyKillsGlock_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsGlock_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsGlock_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsGlock_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420960
// Name: _dynamic_initializer_for__g_CSEnemyKillsElite_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsElite_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsElite_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsElite_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420980
// Name: _dynamic_initializer_for__g_CSEnemyKillsFiveSeven_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsFiveSeven_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsFiveSeven_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsFiveSeven_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104209A0
// Name: _dynamic_initializer_for__g_CSEnemyKillsBizon_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsBizon_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsBizon_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsBizon_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104209C0
// Name: _dynamic_initializer_for__g_CSEnemyKillsTec9_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsTec9_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsTec9_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsTec9_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104209E0
// Name: _dynamic_initializer_for__g_CSEnemyKillsTaser_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsTaser_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsTaser_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsTaser_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A00
// Name: _dynamic_initializer_for__g_CSEnemyKillsHKP2000_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsHKP2000_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsHKP2000_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsHKP2000_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A20
// Name: _dynamic_initializer_for__g_CSEnemyKillsP250_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsP250_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsP250_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsP250_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A40
// Name: _dynamic_initializer_for__g_CSEnemyKillsAWP_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsAWP_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsAWP_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsAWP_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A60
// Name: _dynamic_initializer_for__g_CSEnemyKillsAK47_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsAK47_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsAK47_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsAK47_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420A80
// Name: _dynamic_initializer_for__g_CSEnemyKillsM4A1_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsM4A1_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsM4A1_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsM4A1_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420AA0
// Name: _dynamic_initializer_for__g_CSEnemyKillsAUG_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsAUG_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsAUG_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsAUG_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420AC0
// Name: _dynamic_initializer_for__g_CSEnemyKillsGALIL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsGALIL_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsGALIL_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsGALIL_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420AE0
// Name: _dynamic_initializer_for__g_CSEnemyKillsFAMAS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsFAMAS_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsFAMAS_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsFAMAS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420B00
// Name: _dynamic_initializer_for__g_CSEnemyKillsG3SG1_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsG3SG1_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsG3SG1_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsG3SG1_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420B20
// Name: _dynamic_initializer_for__g_CSEnemyKillsSCAR20_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsSCAR20_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsSCAR20_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsSCAR20_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420B40
// Name: _dynamic_initializer_for__g_CSEnemyKillsSG556_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsSG556_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsSG556_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsSG556_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420B60
// Name: _dynamic_initializer_for__g_CSEnemyKillsSSG08_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsSSG08_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsSSG08_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsSSG08_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420B80
// Name: _dynamic_initializer_for__g_CSEnemyKillsP90_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsP90_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsP90_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsP90_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420BA0
// Name: _dynamic_initializer_for__g_CSEnemyKillsMAC10_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsMAC10_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsMAC10_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsMAC10_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420BC0
// Name: _dynamic_initializer_for__g_CSEnemyKillsUMP45_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsUMP45_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsUMP45_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsUMP45_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420BE0
// Name: _dynamic_initializer_for__g_CSEnemyKillsMP7_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsMP7_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsMP7_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsMP7_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C00
// Name: _dynamic_initializer_for__g_CSEnemyKillsMP9_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsMP9_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsMP9_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsMP9_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C20
// Name: _dynamic_initializer_for__g_CSEnemyKillsXM1014_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsXM1014_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsXM1014_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsXM1014_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C40
// Name: _dynamic_initializer_for__g_CSEnemyKillsMag7_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsMag7_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsMag7_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsMag7_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C60
// Name: _dynamic_initializer_for__g_CSEnemyKillsSawedoff_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsSawedoff_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsSawedoff_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsSawedoff_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420C80
// Name: _dynamic_initializer_for__g_CSEnemyKillsNova_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsNova_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsNova_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsNova_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420CA0
// Name: _dynamic_initializer_for__g_CSEnemyKillsM249_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsM249_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsM249_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsM249_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420CC0
// Name: _dynamic_initializer_for__g_CSEnemyKillsNegev_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsNegev_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsNegev_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsNegev_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420CE0
// Name: _dynamic_initializer_for__g_CSEnemyKillsKnife_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsKnife_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsKnife_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsKnife_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D00
// Name: _dynamic_initializer_for__g_CSEnemyKillsHEGrenade_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsHEGrenade_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsHEGrenade_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsHEGrenade_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D20
// Name: _dynamic_initializer_for__g_CSEnemyKillsMolotov_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSEnemyKillsMolotov_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSEnemyKillsMolotov_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSEnemyKillsMolotov_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D40
// Name: _dynamic_initializer_for__g_CSHeadshots_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSHeadshots_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSHeadshots_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSHeadshots_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D60
// Name: _dynamic_initializer_for__g_CSKillsEnemyWeapon_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillsEnemyWeapon_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillsEnemyWeapon_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillsEnemyWeapon_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420D80
// Name: _dynamic_initializer_for__g_CSKillEnemyBlinded_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemyBlinded_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemyBlinded_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemyBlinded_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420DA0
// Name: _dynamic_initializer_for__g_CSDefuseBombsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDefuseBombsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDefuseBombsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDefuseBombsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420DC0
// Name: _dynamic_initializer_for__g_CSPlantBombsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSPlantBombsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSPlantBombsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSPlantBombsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420DE0
// Name: _dynamic_initializer_for__g_CSDefuseBombsTRLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDefuseBombsTRLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDefuseBombsTRLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDefuseBombsTRLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E00
// Name: _dynamic_initializer_for__g_CSPlantBombsTRLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSPlantBombsTRLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSPlantBombsTRLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSPlantBombsTRLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E20
// Name: _dynamic_initializer_for__g_CSRescueHostagesLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSRescueHostagesLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSRescueHostagesLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSRescueHostagesLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E40
// Name: _dynamic_initializer_for__g_CSRescueHostagesMid_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSRescueHostagesMid_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSRescueHostagesMid_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSRescueHostagesMid_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E60
// Name: _dynamic_initializer_for__g_CSWinKnifeFightsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinKnifeFightsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinKnifeFightsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinKnifeFightsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420E80
// Name: _dynamic_initializer_for__g_CSWinKnifeFightsHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinKnifeFightsHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinKnifeFightsHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinKnifeFightsHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420EA0
// Name: _dynamic_initializer_for__g_CSKillSnipers_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillSnipers_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillSnipers_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillSnipers_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420EC0
// Name: _dynamic_initializer_for__g_CSWinMapCS_ASSAULT_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapCS_ASSAULT_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapCS_ASSAULT_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapCS_ASSAULT_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420EE0
// Name: _dynamic_initializer_for__g_CSWinMapCS_ITALY_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapCS_ITALY_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapCS_ITALY_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapCS_ITALY_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420F00
// Name: _dynamic_initializer_for__g_CSWinMapCS_OFFICE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapCS_OFFICE_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapCS_OFFICE_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapCS_OFFICE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420F20
// Name: _dynamic_initializer_for__g_CSWinMapDE_AZTEC_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapDE_AZTEC_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapDE_AZTEC_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapDE_AZTEC_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420F40
// Name: _dynamic_initializer_for__g_CSWinMapDE_CBBLE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapDE_CBBLE_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapDE_CBBLE_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapDE_CBBLE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420F60
// Name: _dynamic_initializer_for__g_CSWinMapDE_DUST2_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapDE_DUST2_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapDE_DUST2_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapDE_DUST2_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420F80
// Name: _dynamic_initializer_for__g_CSWinMapDE_DUST_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapDE_DUST_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapDE_DUST_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapDE_DUST_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420FA0
// Name: _dynamic_initializer_for__g_CSWinMapDE_INFERNO_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapDE_INFERNO_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapDE_INFERNO_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapDE_INFERNO_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420FC0
// Name: _dynamic_initializer_for__g_CSWinMapDE_NUKE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapDE_NUKE_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapDE_NUKE_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapDE_NUKE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10420FE0
// Name: _dynamic_initializer_for__g_CSWinMapDE_PIRANESI_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapDE_PIRANESI_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapDE_PIRANESI_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapDE_PIRANESI_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421000
// Name: _dynamic_initializer_for__g_CSWinMapDE_PRODIGY_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMapDE_PRODIGY_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMapDE_PRODIGY_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMapDE_PRODIGY_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421020
// Name: _dynamic_initializer_for__g_CSWinMatchDE_ALLEYWAY_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchDE_ALLEYWAY_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchDE_ALLEYWAY_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchDE_ALLEYWAY_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421040
// Name: _dynamic_initializer_for__g_CSWinMatchDE_DEPOT_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchDE_DEPOT_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchDE_DEPOT_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchDE_DEPOT_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421060
// Name: _dynamic_initializer_for__g_CSWinMatchDE_BANK_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchDE_BANK_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchDE_BANK_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchDE_BANK_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421080
// Name: _dynamic_initializer_for__g_CSWinMatchGG_VIETNAM_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchGG_VIETNAM_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchGG_VIETNAM_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchGG_VIETNAM_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104210A0
// Name: _dynamic_initializer_for__g_CSWinMatchDE_SHACKS_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchDE_SHACKS_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchDE_SHACKS_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchDE_SHACKS_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104210C0
// Name: _dynamic_initializer_for__g_CSWinMatchDE_MILL_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchDE_MILL_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchDE_MILL_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchDE_MILL_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104210E0
// Name: _dynamic_initializer_for__g_CSWinMatchDE_HOUSE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchDE_HOUSE_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchDE_HOUSE_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchDE_HOUSE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421100
// Name: _dynamic_initializer_for__g_CSWinMatchDE_BOATHOUSE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchDE_BOATHOUSE_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchDE_BOATHOUSE_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchDE_BOATHOUSE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421120
// Name: _dynamic_initializer_for__g_CSWinMatchGG_BAGGAGE_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinMatchGG_BAGGAGE_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinMatchGG_BAGGAGE_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinMatchGG_BAGGAGE_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421140
// Name: _dynamic_initializer_for__g_CSDonateWeapons_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDonateWeapons_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDonateWeapons_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDonateWeapons_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421160
// Name: _dynamic_initializer_for__g_CSDominationsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDominationsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDominationsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDominationsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421180
// Name: _dynamic_initializer_for__g_CSDominationsHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDominationsHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDominationsHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDominationsHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104211A0
// Name: _dynamic_initializer_for__g_CSDominationOverkillsLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDominationOverkillsLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDominationOverkillsLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDominationOverkillsLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104211C0
// Name: _dynamic_initializer_for__g_CSDominationOverkillsHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDominationOverkillsHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDominationOverkillsHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDominationOverkillsHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104211E0
// Name: _dynamic_initializer_for__g_CSRevengesLow_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSRevengesLow_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSRevengesLow_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSRevengesLow_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421200
// Name: _dynamic_initializer_for__g_CSRevengesHigh_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSRevengesHigh_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSRevengesHigh_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSRevengesHigh_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421220
// Name: _dynamic_initializer_for__g_CSBombDefuseCloseCall_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSBombDefuseCloseCall_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSBombDefuseCloseCall_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSBombDefuseCloseCall_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421240
// Name: _dynamic_initializer_for__g_CSDefuseAndNeededKit_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDefuseAndNeededKit_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDefuseAndNeededKit_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDefuseAndNeededKit_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421260
// Name: _dynamic_initializer_for__g_CSKilledDefuser_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKilledDefuser_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKilledDefuser_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKilledDefuser_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421280
// Name: _dynamic_initializer_for__g_CSWinBombPlant_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinBombPlant_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinBombPlant_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinBombPlant_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104212A0
// Name: _dynamic_initializer_for__g_CSWinBombDefuse_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinBombDefuse_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinBombDefuse_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinBombDefuse_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104212C0
// Name: _dynamic_initializer_for__g_CSPlantBombWithin25Seconds_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSPlantBombWithin25Seconds_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSPlantBombWithin25Seconds_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSPlantBombWithin25Seconds_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104212E0
// Name: _dynamic_initializer_for__g_CSRescueAllHostagesInARound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSRescueAllHostagesInARound_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSRescueAllHostagesInARound_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSRescueAllHostagesInARound_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421300
// Name: _dynamic_initializer_for__g_CSKillEnemyWithFormerGun_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemyWithFormerGun_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemyWithFormerGun_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemyWithFormerGun_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421320
// Name: _dynamic_initializer_for__g_CSKillingSpree_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillingSpree_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillingSpree_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillingSpree_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421340
// Name: _dynamic_initializer_for__g_CSKillTwoWithOneShot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillTwoWithOneShot_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillTwoWithOneShot_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillTwoWithOneShot_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421360
// Name: _dynamic_initializer_for__g_CSKillEnemyReloading_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemyReloading_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemyReloading_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemyReloading_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421380
// Name: _dynamic_initializer_for__g_CSKillsWithMultipleGuns_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillsWithMultipleGuns_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillsWithMultipleGuns_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillsWithMultipleGuns_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104213A0
// Name: _dynamic_initializer_for__g_CSPosthumousGrenadeKill_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSPosthumousGrenadeKill_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSPosthumousGrenadeKill_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSPosthumousGrenadeKill_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104213C0
// Name: _dynamic_initializer_for__g_CSKillEnemyTeam_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemyTeam_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemyTeam_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemyTeam_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104213E0
// Name: _dynamic_initializer_for__g_CSLastPlayerAlive_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSLastPlayerAlive_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSLastPlayerAlive_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSLastPlayerAlive_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421400
// Name: _dynamic_initializer_for__g_CSKillEnemyLastBullet_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemyLastBullet_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemyLastBullet_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemyLastBullet_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421420
// Name: _dynamic_initializer_for__g_CSKillingSpreeEnder_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillingSpreeEnder_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillingSpreeEnder_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillingSpreeEnder_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421440
// Name: _dynamic_initializer_for__g_CSKillEnemiesWhileBlind_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemiesWhileBlind_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemiesWhileBlind_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemiesWhileBlind_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421460
// Name: _dynamic_initializer_for__g_CSKillEnemiesWhileBlindHard_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemiesWhileBlindHard_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemiesWhileBlindHard_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemiesWhileBlindHard_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421480
// Name: _dynamic_initializer_for__g_CSDamageNoKill_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDamageNoKill_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDamageNoKill_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDamageNoKill_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104214A0
// Name: _dynamic_initializer_for__g_CSKillLowDamage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillLowDamage_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillLowDamage_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillLowDamage_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104214C0
// Name: _dynamic_initializer_for__g_CSKilledRescuer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKilledRescuer_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKilledRescuer_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKilledRescuer_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104214E0
// Name: _dynamic_initializer_for__g_CSSurviveGrenade_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSSurviveGrenade_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSSurviveGrenade_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSSurviveGrenade_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421500
// Name: _dynamic_initializer_for__g_CSKilledDefuserWithGrenade_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKilledDefuserWithGrenade_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKilledDefuserWithGrenade_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKilledDefuserWithGrenade_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421520
// Name: _dynamic_initializer_for__g_CSKillSniperWithSniper_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillSniperWithSniper_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillSniperWithSniper_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillSniperWithSniper_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421540
// Name: _dynamic_initializer_for__g_CSKillSniperWithKnife_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillSniperWithKnife_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillSniperWithKnife_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillSniperWithKnife_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421560
// Name: _dynamic_initializer_for__g_CSHipShot_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSHipShot_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSHipShot_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSHipShot_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421580
// Name: _dynamic_initializer_for__g_CSKillWhenAtLowHealth_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillWhenAtLowHealth_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillWhenAtLowHealth_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillWhenAtLowHealth_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104215A0
// Name: _dynamic_initializer_for__g_CSGrenadeMultikill_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGrenadeMultikill_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGrenadeMultikill_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGrenadeMultikill_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104215C0
// Name: _dynamic_initializer_for__g_CSBombMultikill_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSBombMultikill_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSBombMultikill_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSBombMultikill_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104215E0
// Name: _dynamic_initializer_for__g_CSPistolRoundKnifeKill_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSPistolRoundKnifeKill_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSPistolRoundKnifeKill_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSPistolRoundKnifeKill_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421600
// Name: _dynamic_initializer_for__g_CSFastRoundWin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSFastRoundWin_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSFastRoundWin_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSFastRoundWin_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421620
// Name: _dynamic_initializer_for__g_CSSurviveManyAttacks_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSSurviveManyAttacks_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSSurviveManyAttacks_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSSurviveManyAttacks_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421640
// Name: _dynamic_initializer_for__g_CSGooseChase_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGooseChase_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGooseChase_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGooseChase_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421660
// Name: _dynamic_initializer_for__g_CSWinBombPlantAfterRecovery_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinBombPlantAfterRecovery_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinBombPlantAfterRecovery_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinBombPlantAfterRecovery_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421680
// Name: _dynamic_initializer_for__g_CSLosslessExtermination_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSLosslessExtermination_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSLosslessExtermination_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSLosslessExtermination_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104216A0
// Name: _dynamic_initializer_for__g_CSFlawlessVictory_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSFlawlessVictory_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSFlawlessVictory_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSFlawlessVictory_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104216C0
// Name: _dynamic_initializer_for__g_CSWinDualDuel_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinDualDuel_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinDualDuel_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinDualDuel_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104216E0
// Name: _dynamic_initializer_for__g_CSFastHostageRescue_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSFastHostageRescue_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSFastHostageRescue_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSFastHostageRescue_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421700
// Name: _dynamic_initializer_for__g_CSBreakWindows_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSBreakWindows_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSBreakWindows_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSBreakWindows_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421720
// Name: _dynamic_initializer_for__g_CSBreakProps_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSBreakProps_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSBreakProps_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSBreakProps_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421740
// Name: _dynamic_initializer_for__g_CSUnstoppableForce_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSUnstoppableForce_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSUnstoppableForce_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSUnstoppableForce_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421760
// Name: _dynamic_initializer_for__g_CSImmovableObject_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSImmovableObject_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSImmovableObject_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSImmovableObject_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421780
// Name: _dynamic_initializer_for__g_CSHeadshotsInRound_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSHeadshotsInRound_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSHeadshotsInRound_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSHeadshotsInRound_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104217A0
// Name: _dynamic_initializer_for__g_CSKillWhileInAir_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillWhileInAir_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillWhileInAir_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillWhileInAir_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104217C0
// Name: _dynamic_initializer_for__g_CSKillEnemyInAir_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemyInAir_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemyInAir_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemyInAir_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104217E0
// Name: _dynamic_initializer_for__g_CSKillerAndEnemyInAir_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillerAndEnemyInAir_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillerAndEnemyInAir_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillerAndEnemyInAir_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421800
// Name: _dynamic_initializer_for__g_CSSilentWin_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSSilentWin_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSSilentWin_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSSilentWin_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421820
// Name: _dynamic_initializer_for__g_CSBloodlessVictory_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSBloodlessVictory_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSBloodlessVictory_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSBloodlessVictory_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421840
// Name: _dynamic_initializer_for__g_CSWinRoundsWithoutBuying_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSWinRoundsWithoutBuying_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSWinRoundsWithoutBuying_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSWinRoundsWithoutBuying_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421860
// Name: _dynamic_initializer_for__g_CSDefuseDefense_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDefuseDefense_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDefuseDefense_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDefuseDefense_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421880
// Name: _dynamic_initializer_for__g_CSKillBombPickup_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillBombPickup_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillBombPickup_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillBombPickup_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104218A0
// Name: _dynamic_initializer_for__g_CSConcurrentDominations_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSConcurrentDominations_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSConcurrentDominations_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSConcurrentDominations_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104218C0
// Name: _dynamic_initializer_for__g_CSDominationOverkillsMatch_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSDominationOverkillsMatch_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSDominationOverkillsMatch_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSDominationOverkillsMatch_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104218E0
// Name: _dynamic_initializer_for__g_CSExtendedDomination_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSExtendedDomination_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSExtendedDomination_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSExtendedDomination_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421900
// Name: _dynamic_initializer_for__g_CSCauseFriendlyFireWithFlashbang_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSCauseFriendlyFireWithFlashbang_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSCauseFriendlyFireWithFlashbang_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSCauseFriendlyFireWithFlashbang_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421920
// Name: _dynamic_initializer_for__g_CSGunGameKillKnifer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGunGameKillKnifer_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGunGameKillKnifer_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGunGameKillKnifer_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421940
// Name: _dynamic_initializer_for__g_CSGunGameSelectFinalKnifeKill_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGunGameSelectFinalKnifeKill_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGunGameSelectFinalKnifeKill_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGunGameSelectFinalKnifeKill_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421960
// Name: _dynamic_initializer_for__g_CSGunGameKnifeSuicide_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGunGameKnifeSuicide_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGunGameKnifeSuicide_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGunGameKnifeSuicide_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421980
// Name: _dynamic_initializer_for__g_CSGunGameKnifeKillKnifer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGunGameKnifeKillKnifer_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGunGameKnifeKillKnifer_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGunGameKnifeKillKnifer_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104219A0
// Name: _dynamic_initializer_for__g_CSGunGameSMGKillKnifer_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGunGameSMGKillKnifer_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGunGameSMGKillKnifer_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGunGameSMGKillKnifer_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104219C0
// Name: _dynamic_initializer_for__g_CSGunGameProgressiveRampage_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGunGameProgressiveRampage_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGunGameProgressiveRampage_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGunGameProgressiveRampage_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x104219E0
// Name: _dynamic_initializer_for__g_CSGunGameFirstKill_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGunGameFirstKill_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGunGameFirstKill_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGunGameFirstKill_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A00
// Name: _dynamic_initializer_for__g_CSKillEnemyTerrTeamBeforeBombPlant_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemyTerrTeamBeforeBombPlant_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemyTerrTeamBeforeBombPlant_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemyTerrTeamBeforeBombPlant_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A20
// Name: _dynamic_initializer_for__g_CSKillEnemyCTTeamBeforeBombPlant_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSKillEnemyCTTeamBeforeBombPlant_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSKillEnemyCTTeamBeforeBombPlant_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSKillEnemyCTTeamBeforeBombPlant_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A40
// Name: _dynamic_initializer_for__g_CSLastPlayerAliveGGSelect_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSLastPlayerAliveGGSelect_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSLastPlayerAliveGGSelect_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSLastPlayerAliveGGSelect_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A60
// Name: _dynamic_initializer_for__g_CSFirstBulletKills_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSFirstBulletKills_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSFirstBulletKills_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSFirstBulletKills_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421A80
// Name: _dynamic_initializer_for__g_CSGunGameConservationist_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSGunGameConservationist_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSGunGameConservationist_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSGunGameConservationist_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421AA0
// Name: _dynamic_initializer_for__g_CSSpawnCamper_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSSpawnCamper_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSSpawnCamper_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSSpawnCamper_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421AC0
// Name: _dynamic_initializer_for__g_CSBornReady_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSBornReady_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSBornReady_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSBornReady_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421AE0
// Name: _dynamic_initializer_for__g_CSStillAlive_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSStillAlive_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSStillAlive_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSStillAlive_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421B00
// Name: _dynamic_initializer_for__g_CSSmorgasboard_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CSSmorgasboard_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CSSmorgasboard_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CSSmorgasboard_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421B20
// Name: _dynamic_initializer_for__g_CAchievementCS_PistolMaster_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_PistolMaster_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_PistolMaster_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_PistolMaster_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421B40
// Name: _dynamic_initializer_for__g_CAchievementCS_RifleMaster_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_RifleMaster_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_RifleMaster_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_RifleMaster_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421B60
// Name: _dynamic_initializer_for__g_CAchievementCS_SubMachineGunMaster_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_SubMachineGunMaster_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_SubMachineGunMaster_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_SubMachineGunMaster_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421B80
// Name: _dynamic_initializer_for__g_CAchievementCS_ShotgunMaster_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_ShotgunMaster_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_ShotgunMaster_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_ShotgunMaster_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421BA0
// Name: _dynamic_initializer_for__g_CAchievementCS_WeaponMaster_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_WeaponMaster_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_WeaponMaster_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_WeaponMaster_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421BC0
// Name: _dynamic_initializer_for__g_CAchievementCS_KillWithAllWeapons_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_KillWithAllWeapons_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_KillWithAllWeapons_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_KillWithAllWeapons_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421BE0
// Name: _dynamic_initializer_for__g_CAchievementCS_WinEveryGGMap_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_WinEveryGGMap_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_WinEveryGGMap_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_WinEveryGGMap_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421C00
// Name: _dynamic_initializer_for__g_CAchievementCS_PlayEveryGGMap_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_PlayEveryGGMap_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_PlayEveryGGMap_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_PlayEveryGGMap_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421C20
// Name: _dynamic_initializer_for__g_CAchievementCS_AvengeFriend_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_AvengeFriend_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_AvengeFriend_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_AvengeFriend_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421C40
// Name: _dynamic_initializer_for__g_CAchievementCS_Medalist_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CBaseAchievementHelper *dynamic_initializer_for__g_CAchievementCS_Medalist_Helper__()
{
  CBaseAchievementHelper *result; // eax

  result = CBaseAchievementHelper::s_pFirst;
  g_CAchievementCS_Medalist_Helper.m_pNext = CBaseAchievementHelper::s_pFirst;
  CBaseAchievementHelper::s_pFirst = &g_CAchievementCS_Medalist_Helper;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10421C60
// Name: _dynamic_initializer_for____g_C_BaseCSGrenadeProjectileClientClass__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
ClientClass *dynamic_initializer_for____g_C_BaseCSGrenadeProjectileClientClass__()
{
  ClientClass *result; // eax

  result = g_pClientClassHead;
  __g_C_BaseCSGrenadeProjectileClientClass.m_pNext = g_pClientClassHead;
  g_pClientClassHead = &__g_C_BaseCSGrenadeProjectileClientClass;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10435100
// Name: _dynamic_atexit_destructor_for__g_AchievementMgrCS__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_AchievementMgrCS__()
{
  CAchievementMgr::~CAchievementMgr(this: &g_AchievementMgrCS);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10268C90
// Name: public: static class CAchievementMgr __near * CAchievementMgr::GetInstance(void)
// Source: json
//------------------------------------------------------------------------------
IAchievementMgr_vtbl *__cdecl CAchievementMgr::GetInstance()
{
  return engine->GetAchievementMgr(this: engine)[1].__vftable;
}

} // namespace server
