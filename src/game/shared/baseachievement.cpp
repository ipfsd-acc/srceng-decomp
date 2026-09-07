// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/baseachievement.cpp
// Functions: 40
// ============================================================

#include "game\shared\baseachievement.h"

//------------------------------------------------------------------------------
// Address: 0x1000CE60
// Name: public: virtual struct datamap_t __near * CBaseAchievement::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseAchievement::GetDataDescMap(CBaseAchievement *this)
{
  return &CBaseAchievement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000CE70
// Name: public: void CBaseAchievement::SetFlags(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::SetFlags(CBaseAchievement *this, int iFlags)
{
  this->m_iFlags = iFlags;
}

//------------------------------------------------------------------------------
// Address: 0x1000CE80
// Name: protected: virtual void CBaseAchievement::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::FireGameEvent(CBaseAchievement *this, IGameEvent *event)
{
  const char *v3; // eax

  if ( this->IsActive(this)
    && (this->m_pMapNameFilter == nullptr
     || _V_strcmp(s1: this->m_pAchievementMgr->m_szMap, s2: this->m_pMapNameFilter) == 0) )
  {
    v3 = event->GetName(this: event);
    if ( _V_strcmp(s1: v3, s2: "teamplay_round_win") != 0
      || (this->m_iFlags & 0x400) == 0
      || event->GetBool(this: event, a2: "full_round", a3: false) )
    {
      this->FireGameEvent_Internal(this, a2: event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CF00
// Name: public: virtual void CBaseAchievement::SetShowOnHUD(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::SetShowOnHUD(CBaseAchievement *this, bool bShow)
{
  if ( LOBYTE(this->m_pAchievementMgr) != bShow )
    *(_BYTE *)(LODWORD(this->m_iComponentBits) + *(&this->m_iProgressShown + 1) + 564) = 1;
  LOBYTE(this->m_pAchievementMgr) = bShow;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF30
// Name: protected: virtual void CBaseAchievement::CalcProgressMsgIncrement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::CalcProgressMsgIncrement(CBaseAchievement *this)
{
  int m_iGoal; // esi
  int v2; // eax

  m_iGoal = this->m_iGoal;
  this->m_iProgressMsgIncrement = m_iGoal / 4;
  if ( m_iGoal % 4 != 0 )
  {
    v2 = m_iGoal / 3;
    if ( m_iGoal % 3 == 0 || (v2 = m_iGoal / 5, m_iGoal % 5 == 0) )
      this->m_iProgressMsgIncrement = v2;
  }
  if ( this->m_iProgressMsgIncrement < 5 )
    this->m_iProgressMsgIncrement = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF90
// Name: protected: void CBaseAchievement::AwardAchievement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::AwardAchievement(CBaseAchievement *this)
{
  if ( !this->IsAchieved(this: &this->IAchievement) )
    CAchievementMgr::AwardAchievement(
      this: this->m_pAchievementMgr,
      iAchievementID: (vgui::TreeNode *)this->m_iAchievementID,
      nUserSlot: this->m_nUserSlot);
}

//------------------------------------------------------------------------------
// Address: 0x1000CFD0
// Name: protected: void CBaseAchievement::ShowProgressNotification(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::ShowProgressNotification(CBaseAchievement *this)
{
  IGameEvent *v2; // esi
  IGameEvent_vtbl *v3; // ebx
  const char *v4; // eax

  if ( this->ShouldShowProgressNotification(this) )
  {
    v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "achievement_event", a3: 0, a4: 0);
    if ( v2 != nullptr )
    {
      v3 = v2->__vftable;
      v4 = this->GetName(this: &this->IAchievement);
      v3->SetString(this: v2, a2: "achievement_name", a3: v4);
      v2->SetInt(this: v2, a2: "cur_val", a3: this->m_iCount);
      v2->SetInt(this: v2, a2: "max_val", a3: this->m_iGoal);
      gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v2);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D050
// Name: public: virtual void CBaseAchievement::PreRestoreSavedGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::PreRestoreSavedGame(CBaseAchievement *this)
{
  if ( (this->m_iFlags & 0x40) != 0 )
    this->m_iCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D060
// Name: public: void CBaseAchievement::SetComponentBits(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::SetComponentBits(CBaseAchievement *this, unsigned __int64 iComponentBits)
{
  unsigned int v2; // edx
  unsigned int v3; // edi
  int v4; // ebx

  v3 = HIDWORD(iComponentBits);
  v2 = iComponentBits;
  v4 = 0;
  this->m_iComponentBits = iComponentBits;
  if ( iComponentBits != 0 )
  {
    do
    {
      if ( (v2 & 1) != 0 )
        ++v4;
      v2 = __PAIR64__(v3, v2) >> 1;
      v3 >>= 1;
    }
    while ( v3 != 0 || v2 != 0 );
    this->m_iCount = v4;
  }
  else
  {
    this->m_iCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D0B0
// Name: public: virtual bool CBaseAchievement::ShouldSaveWithGame(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseAchievement::ShouldSaveWithGame(CBaseAchievement *this)
{
  return ((int)this->IAchievement::__vftable & 0x40) != 0
      && ((int (__thiscall *)(CBaseAchievement *))this->ListenForEvents)(a1: this) > 0
      && ((unsigned __int8 (__thiscall *)(CBaseAchievement *))this->Event_EntityKilled)(a1: this) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D0E0
// Name: public: virtual bool CBaseAchievement::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAchievement::IsActive(CBaseAchievement *this)
{
  return !this->IsAchieved(this: &this->IAchievement)
      && (this->m_pMapNameFilter == nullptr
       || _V_strcmp(s1: this->m_pAchievementMgr->m_szMap, s2: this->m_pMapNameFilter) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D120
// Name: public: virtual void CBaseAchievement::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::GetSettings(CBaseAchievement *this, KeyValues *pNodeOut)
{
  bool v3; // al
  bool v4; // al

  v3 = this->IsAchieved(this: &this->IAchievement);
  KeyValues::SetInt(this: pNodeOut, keyName: "value", value: v3);
  if ( (this->m_iFlags & 0x20) != 0 )
  {
    KeyValues::SetUint64(this: pNodeOut, keyName: "data", value: this->m_iComponentBits);
  }
  else if ( !this->IsAchieved(this: &this->IAchievement) )
  {
    KeyValues::SetInt(this: pNodeOut, keyName: "data", value: this->m_iCount);
  }
  v4 = this->ShouldShowOnHUD(this: &this->IAchievement);
  KeyValues::SetInt(this: pNodeOut, keyName: "hud", value: v4);
  KeyValues::SetInt(this: pNodeOut, keyName: "msg", value: this->m_iProgressShown);
}

//------------------------------------------------------------------------------
// Address: 0x1000D1C0
// Name: public: virtual void CBaseAchievement::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::ApplySettings(CBaseAchievement *this, KeyValues *pNodeIn)
{
  int Int; // eax
  unsigned __int64 Uint64; // rax
  int v6; // eax
  KeyValues *pNodeIna; // [esp+14h] [ebp+8h]

  if ( KeyValues::GetInt(this: pNodeIn, keyName: "value", defaultValue: 0) <= 0 )
  {
    if ( (this->m_iFlags & 0x20) != 0 )
    {
LABEL_6:
      Uint64 = KeyValues::GetUint64(this: pNodeIn, keyName: "data", defaultValue: 0);
      CBaseAchievement::SetComponentBits(this, iComponentBits: Uint64);
      goto LABEL_7;
    }
    Int = KeyValues::GetInt(this: pNodeIn, keyName: "data", defaultValue: 0);
  }
  else
  {
    Int = this->m_iGoal;
    this->m_bAchieved = true;
  }
  this->m_iCount = Int;
  if ( (this->m_iFlags & 0x20) != 0 )
    goto LABEL_6;
LABEL_7:
  pNodeIna = (KeyValues *)this->IAchievement::__vftable;
  v6 = KeyValues::GetInt(this: pNodeIn, keyName: "hud", defaultValue: 0);
  ((void (__thiscall *)(IAchievement *, bool))pNodeIna[1].m_wsValue)(a1: &this->IAchievement, a2: v6 != 0);
  this->m_iProgressShown = KeyValues::GetInt(this: pNodeIn, keyName: "msg", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D260
// Name: public: virtual void CBaseAchievement::ClearAchievementData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::ClearAchievementData(CBaseAchievement *this)
{
  bool v1; // zf

  v1 = (this->m_iFlags & 0x20) == 0;
  this->m_iCount = 0;
  this->m_bAchieved = false;
  if ( !v1 )
  {
    this->m_iComponentBits = 0;
    this->m_iCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D280
// Name: public: virtual char const __near * CBaseAchievement::GetComponentDisplayString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAchievement::GetComponentDisplayString(CBaseAchievement *this, int iComponent)
{
  if ( ((int)this->IAchievement::__vftable & 0x20) != 0 && iComponent >= 0 && iComponent <= (int)this->m_pGameDirFilter )
    return *(const char **)&this->m_pMapNameFilter[4 * iComponent];
  else
    return prType;
}

//------------------------------------------------------------------------------
// Address: 0x1000D2B0
// Name: public: virtual bool CBaseAchievement::CheckAchievementsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseAchievement::CheckAchievementsEnabled(CBaseAchievement *this)
{
  C_GameRules_vtbl *v2; // esi
  int v3; // eax
  char result; // al

  if ( g_pGameRules == nullptr )
    return CAchievementMgr::CheckAchievementsEnabled(this: this->m_pAchievementMgr);
  v2 = g_pGameRules->__vftable;
  v3 = this->GetAchievementID(this: &this->IAchievement);
  result = v2->CheckAchievementsEnabled(this: g_pGameRules, a2: v3);
  if ( result != 0 )
    return CAchievementMgr::CheckAchievementsEnabled(this: this->m_pAchievementMgr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D2F0
// Name: public: CBaseAchievement::CBaseAchievement(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__thiscall CBaseAchievement::CBaseAchievement(CBaseAchievement *this)
{
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->IAchievement::__vftable = (IAchievement_vtbl *)&IAchievement::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CBaseAchievement::`vftable'{for `CGameEventListener'};
  this->IAchievement::__vftable = (IAchievement_vtbl *)&CBaseAchievement::`vftable'{for `IAchievement'};
  this->m_iFlags = 0;
  this->m_iGoal = 0;
  this->m_iProgressMsgIncrement = 0;
  this->m_iProgressMsgMinimum = 0;
  this->m_iAchievementID = 0;
  this->m_iPointValue = 0;
  *(_WORD *)&this->m_bHideUntilAchieved = 0;
  this->m_pVictimClassNameFilter = nullptr;
  this->m_pAttackerClassNameFilter = nullptr;
  this->m_pInflictorClassNameFilter = nullptr;
  this->m_pInflictorEntityNameFilter = nullptr;
  this->m_pMapNameFilter = nullptr;
  this->m_pGameDirFilter = nullptr;
  this->m_pszComponentNames = nullptr;
  this->m_pszComponentDisplayNames = nullptr;
  this->m_pszComponentPrefix = nullptr;
  this->m_iNumComponents = 0;
  this->m_iComponentPrefixLen = 0;
  this->m_iComponentBits = 0;
  this->m_iCount = 0;
  this->m_iProgressShown = 0;
  this->m_bAchieved = false;
  this->m_uUnlockTime = 0;
  this->m_pAchievementMgr = nullptr;
  this->m_nUserSlot = 0;
  this->m_iAssetAwardID = 0;
  this->m_bShowOnHUD = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000D380
// Name: public: virtual bool CBaseAchievement::IsAchieved(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAchievement::IsAchieved(CBaseAchievement *this)
{
  return this->m_iNumComponents;
}

//------------------------------------------------------------------------------
// Address: 0x1000D390
// Name: public: virtual unsigned __int64 CBaseAchievement::GetComponentBits(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CBaseAchievement::GetComponentBits(CBaseAchievement *this)
{
  return *(_QWORD *)&this->m_iCount;
}

//------------------------------------------------------------------------------
// Address: 0x1000D3A0
// Name: public: virtual bool CBaseAchievement::ShouldShowOnHUD(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAchievement::ShouldShowOnHUD(CBaseAchievement *this)
{
  return (bool)this->m_pAchievementMgr;
}

//------------------------------------------------------------------------------
// Address: 0x1000D3B0
// Name: public: virtual void CBaseAchievement::SetUserSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::SetUserSlot(CBaseAchievement *this, int nUserSlot)
{
  this->m_nUserSlot = nUserSlot;
}

//------------------------------------------------------------------------------
// Address: 0x1000D3C0
// Name: public: virtual int CBaseAchievement::GetDisplayOrder(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAchievement::GetDisplayOrder(CBaseAchievement *this)
{
  return HIDWORD(this->m_iComponentBits);
}

//------------------------------------------------------------------------------
// Address: 0x1000D3D0
// Name: protected: void CBaseAchievement::HandleProgressUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::HandleProgressUpdate(CBaseAchievement *this)
{
  int m_iProgressMsgIncrement; // ecx
  int m_iCount; // eax
  int v4; // eax
  int v5; // et2
  int v6; // edi
  int m_nUserSlot; // eax
  CAchievementMgr *m_pAchievementMgr; // ecx

  m_iProgressMsgIncrement = this->m_iProgressMsgIncrement;
  if ( m_iProgressMsgIncrement > 0 )
  {
    m_iCount = this->m_iCount;
    if ( m_iCount >= this->m_iProgressMsgMinimum )
    {
      v5 = m_iCount % m_iProgressMsgIncrement;
      v4 = m_iCount / m_iProgressMsgIncrement;
      v6 = v4;
      if ( v5 == 0 && v4 > this->m_iProgressShown )
      {
        CBaseAchievement::ShowProgressNotification(this);
        m_nUserSlot = this->m_nUserSlot;
        m_pAchievementMgr = this->m_pAchievementMgr;
        this->m_iProgressShown = v6;
        m_pAchievementMgr->m_bDirty[m_nUserSlot] = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D410
// Name: protected: void CBaseAchievement::EvaluateNewAchievement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::EvaluateNewAchievement(CBaseAchievement *this)
{
  int m_iGoal; // eax

  if ( !this->IsAchieved(this: &this->IAchievement) )
  {
    m_iGoal = this->m_iGoal;
    if ( m_iGoal > 0 && this->m_iCount >= m_iGoal )
    {
      this->m_pAchievementMgr->m_bCheckSigninState = false;
      if ( !this->IsAchieved(this: &this->IAchievement) )
        CAchievementMgr::AwardAchievement(
          this: this->m_pAchievementMgr,
          iAchievementID: (vgui::TreeNode *)this->m_iAchievementID,
          nUserSlot: this->m_nUserSlot);
      this->m_pAchievementMgr->m_bCheckSigninState = true;
      this->CheckAssetAwards(this, a2: this->m_nUserSlot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D480
// Name: public: virtual void CBaseAchievement::PostRestoreSavedGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::PostRestoreSavedGame(CBaseAchievement *this)
{
  ISteamUserStats *m_pSteamUserStats; // esi
  ISteamUserStats_vtbl *v3; // ebx
  int v4; // eax
  bool v5; // [esp+Bh] [ebp-1h] BYREF

  m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
  if ( m_pSteamUserStats != nullptr )
  {
    v3 = m_pSteamUserStats->__vftable;
    v4 = ((int (__thiscall *)(IAchievement *, bool *))this->GetName)(a1: &this->IAchievement, a2: &v5);
    ((void (__thiscall *)(ISteamUserStats *, int))v3->GetAchievement)(a1: m_pSteamUserStats, a2: v4);
    this->m_bAchieved = v5;
  }
  CBaseAchievement::EvaluateNewAchievement(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000D4D0
// Name: protected: void CBaseAchievement::IncrementCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::IncrementCount(CBaseAchievement *this, int iOptIncrement)
{
  int v3; // ecx
  const char *v4; // eax
  int m_iGoal; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // [esp-8h] [ebp-10h]
  int v9; // [esp-4h] [ebp-Ch]

  if ( !this->IsAchieved(this: &this->IAchievement) )
  {
    if ( this->CheckAchievementsEnabled(this) )
    {
      if ( iOptIncrement <= 0 )
      {
        ++this->m_iCount;
      }
      else
      {
        this->m_iCount += iOptIncrement;
        m_iGoal = this->m_iGoal;
        if ( this->m_iCount > m_iGoal )
          this->m_iCount = m_iGoal;
      }
      if ( (this->GetFlags(this: &this->IAchievement) & 0x80u) != 0 )
        this->m_pAchievementMgr->m_bDirty[this->m_nUserSlot] = true;
      if ( cc_achievement_debug.m_pParent != nullptr && cc_achievement_debug.m_pParent->m_Value.m_nValue != 0 )
      {
        v6 = (const char *)((int (__thiscall *)(IAchievement *, int, int))this->GetName)(
                             a1: &this->IAchievement,
                             a2: this->m_iCount,
                             a3: this->m_iGoal);
        _Msg(a1: "Achievement count increased for %s: %d/%d\n", v6, v8, v9);
      }
      v7 = this->m_iGoal;
      if ( v7 > 0 )
      {
        if ( this->m_iCount < v7 )
          CBaseAchievement::HandleProgressUpdate(this);
        else
          CBaseAchievement::AwardAchievement(this);
      }
    }
    else
    {
      v3 = g_nAchivementBitchCount++;
      if ( v3 < 10 )
      {
        v4 = this->GetName(this: &this->IAchievement);
        DevMsg(a1: "Achievements disabled, ignoring achievement progress for %s\n", v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D5C0
// Name: public: virtual void CBaseAchievement::OnMapEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::OnMapEvent(CBaseAchievement *this, const char *pEventName)
{
  const char *v3; // eax

  v3 = this->GetName(this: &this->IAchievement);
  if ( _V_stricmp(s1: pEventName, s2: v3) == 0 )
    CBaseAchievement::IncrementCount(this, iOptIncrement: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D5F0
// Name: public: void CBaseAchievement::OnComponentEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::OnComponentEvent(CBaseAchievement *this, const char *pchComponentName)
{
  int v3; // edi
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  IAchievement *pchComponentNamea; // [esp+18h] [ebp+8h]

  v3 = 0;
  if ( this->m_iNumComponents > 0 )
  {
    while ( _V_strcmp(s1: pchComponentName, s2: this->m_pszComponentNames[v3]) != 0 )
    {
      if ( ++v3 >= this->m_iNumComponents )
        return;
    }
    pchComponentNamea = &this->IAchievement;
    if ( ((unsigned __int8 (*)(void))this->IsAchieved)() == 0 )
    {
      if ( ((1LL << v3) & this->m_iComponentBits) != 0 )
      {
        if ( cc_achievement_debug.m_pParent != nullptr && cc_achievement_debug.m_pParent->m_Value.m_nValue != 0 )
        {
          v6 = pchComponentNamea->GetName(this: pchComponentNamea);
          _Msg(a1: "Component %d for achievement %s found, but already had that component\n", v3, v6);
        }
      }
      else if ( this->CheckAchievementsEnabled(this) )
      {
        CBaseAchievement::SetComponentBits(this, iComponentBits: (1LL << v3) | this->m_iComponentBits);
        if ( this->m_iCount == this->m_iGoal )
        {
          if ( !pchComponentNamea->IsAchieved(this: pchComponentNamea) )
            CAchievementMgr::AwardAchievement(
              this: this->m_pAchievementMgr,
              iAchievementID: (vgui::TreeNode *)this->m_iAchievementID,
              nUserSlot: this->m_nUserSlot);
        }
        else
        {
          this->m_pAchievementMgr->m_bDirty[this->m_nUserSlot] = true;
          if ( cc_achievement_debug.m_pParent != nullptr && cc_achievement_debug.m_pParent->m_Value.m_nValue != 0 )
          {
            v5 = pchComponentNamea->GetName(this: pchComponentNamea);
            _Msg(a1: "Component %d for achievement %s found\n", v3, v5);
          }
          CBaseAchievement::ShowProgressNotification(this);
        }
      }
      else
      {
        v4 = pchComponentNamea->GetName(this: pchComponentNamea);
        _Msg(a1: "Achievements disabled, ignoring achievement component for %s\n", v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D770
// Name: public: virtual void CBaseAchievement::Event_EntityKilled(class C_BaseEntity __near *,class C_BaseEntity __near *,class C_BaseEntity __near *,class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::Event_EntityKilled(
        CBaseAchievement *this,
        C_BaseEntity *pVictim,
        C_BaseEntity *pAttacker,
        C_BaseEntity *pInflictor,
        C_BaseEntity *event)
{
  if ( (this->GetFlags(this: &this->IAchievement) & 1) != 0 )
    CBaseAchievement::IncrementCount(this, iOptIncrement: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000D790
// Name: public: CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDatadescGeneratedNameHolder::~CDatadescGeneratedNameHolder(CDatadescGeneratedNameHolder *this)
{
  int i; // edi
  char **m_pMemory; // eax

  for ( i = 0; i < this->m_Names.m_Size; ++i )
    C_BaseEntity::operator delete(pMem: this->m_Names.m_Memory.m_pMemory[i]);
  this->m_Names.m_Size = 0;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Names.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Names.m_Memory.m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Names.m_Memory.m_pMemory;
  this->m_Names.m_pElements = m_pMemory;
  if ( this->m_Names.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Names.m_Memory.m_pMemory = nullptr;
    }
    this->m_Names.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038610
// Name: public: virtual int CBaseAchievement::GetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAchievement::GetCount(CChoreoEvent *this)
{
  return this->m_nLoopsRemaining;
}

//------------------------------------------------------------------------------
// Address: 0x1040FAF0
// Name: CBaseAchievement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseAchievement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseAchievement>();
  CBaseAchievement_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1040FB00
// Name: CFailableAchievement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFailableAchievement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFailableAchievement>();
  CFailableAchievement_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D810
// Name: struct datamap_t __near * DataMapInit<class CBaseAchievement>(class CBaseAchievement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseAchievement>()
{
  if ( (_S5_1 & 1) == 0 )
  {
    _S5_1 |= 1u;
    nameHolder.m_pszBase = "CBaseAchievement";
    nameHolder.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder.m_Names.m_Size = 0;
    nameHolder.m_Names.m_pElements = nullptr;
    nameHolder.m_nLenBase = 16;
    atexit(func: DataMapInit_CBaseAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseAchievement::m_DataMap.baseMap = nullptr;
  CBaseAchievement::m_DataMap.dataNumFields = 1;
  CBaseAchievement::m_DataMap.dataDesc = &dataDesc[1];
  return &CBaseAchievement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1000D890
// Name: struct datamap_t __near * DataMapInit<class CFailableAchievement>(class CFailableAchievement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFailableAchievement>()
{
  if ( (_S6_0 & 1) == 0 )
  {
    _S6_0 |= 1u;
    nameHolder_0.m_pszBase = "CFailableAchievement";
    nameHolder_0.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_0.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_0.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_0.m_Names.m_Size = 0;
    nameHolder_0.m_Names.m_pElements = nullptr;
    nameHolder_0.m_nLenBase = 20;
    atexit(func: DataMapInit_CFailableAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFailableAchievement::m_DataMap.baseMap = &CBaseAchievement::m_DataMap;
  CFailableAchievement::m_DataMap.dataNumFields = 2;
  CFailableAchievement::m_DataMap.dataDesc = &dataDesc_0[1];
  return &CFailableAchievement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x1040FB10
// Name: _dynamic_initializer_for__cl_disable_water_render_targets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_disable_water_render_targets__()
{
  ConVar::ConVar(
    this: &cl_disable_water_render_targets,
    pName: "cl_disable_water_render_targets",
    pDefaultValue: "0",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__cl_disable_water_render_targets__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FB40
// Name: _dynamic_initializer_for__g_BaseClientRenderTargets__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_BaseClientRenderTargets__()
{
  CTextureReference::CTextureReference(this: &g_BaseClientRenderTargets.m_WaterReflectionTexture);
  CTextureReference::CTextureReference(this: &g_BaseClientRenderTargets.m_WaterRefractionTexture);
  CTextureReference::CTextureReference(this: &g_BaseClientRenderTargets.m_CameraTexture);
  return atexit(func: dynamic_atexit_destructor_for__g_BaseClientRenderTargets__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FB70
// Name: _dynamic_initializer_for____g_CreateCBaseClientRenderTargetsIClientRenderTargets_reg__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
InterfaceReg *dynamic_initializer_for____g_CreateCBaseClientRenderTargetsIClientRenderTargets_reg__()
{
  return InterfaceReg::InterfaceReg(
           this: &_g_CreateCBaseClientRenderTargetsIClientRenderTargets_reg,
           fn: (void *(__cdecl *)())_CreateCBaseClientRenderTargetsIClientRenderTargets_interface,
           pName: "ClientRenderTargets001");
}

//------------------------------------------------------------------------------
// Address: 0x1040FB90
// Name: _dynamic_initializer_for__s_CombatCharVisCache__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__s_CombatCharVisCache__()
{
  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this: &s_CombatCharVisCache, name: nullptr);
  s_CombatCharVisCache.__vftable = (CCombatCharVisCache_vtbl *)&CCombatCharVisCache::`vftable';
  s_CombatCharVisCache.m_VisCache.m_Elements.m_pMemory = nullptr;
  s_CombatCharVisCache.m_VisCache.m_Elements.m_nAllocationCount = 0;
  s_CombatCharVisCache.m_VisCache.m_Elements.m_nGrowSize = 0;
  *(_DWORD *)&s_CombatCharVisCache.m_VisCache.m_Root = 0xFFFF;
  *(_DWORD *)&s_CombatCharVisCache.m_VisCache.m_FirstFree = -1;
  s_CombatCharVisCache.m_VisCache.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__s_CombatCharVisCache__);
}

//------------------------------------------------------------------------------
// Address: 0x1040FBF0
// Name: _dynamic_initializer_for__g_WeaponList__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_WeaponList__()
{
  CAutoGameSystem::CAutoGameSystem(this: &g_WeaponList, name: "CWeaponList");
  g_WeaponList.__vftable = (CWeaponList_vtbl *)&CWeaponList::`vftable';
  g_WeaponList.m_list.m_Memory.m_pMemory = nullptr;
  g_WeaponList.m_list.m_Memory.m_nAllocationCount = 0;
  g_WeaponList.m_list.m_Memory.m_nGrowSize = 0;
  g_WeaponList.m_list.m_LastAlloc.index = -1;
  *(_DWORD *)&g_WeaponList.m_list.m_Head = -1;
  *(_DWORD *)&g_WeaponList.m_list.m_FirstFree = 0xFFFF;
  g_WeaponList.m_list.m_NumAlloced = 0;
  g_WeaponList.m_list.m_pElements = nullptr;
  return atexit(func: dynamic_atexit_destructor_for__g_WeaponList__);
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10097410
// Name: public: virtual struct datamap_t __near * CBaseAchievement::GetDataDescMap(void)
// Source: json
//------------------------------------------------------------------------------
datamap_t *__thiscall CBaseAchievement::GetDataDescMap(CBaseAchievement *this)
{
  return &CBaseAchievement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10097420
// Name: protected: virtual void CBaseAchievement::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::FireGameEvent(CBaseAchievement *this, IGameEvent *event)
{
  const char *v3; // eax

  if ( this->IsActive(this)
    && (this->m_pMapNameFilter == nullptr
     || _V_strcmp(s1: this->m_pAchievementMgr->m_szMap, s2: this->m_pMapNameFilter) == 0) )
  {
    v3 = event->GetName(this: event);
    if ( _V_strcmp(s1: v3, s2: "teamplay_round_win") != 0
      || (this->m_iFlags & 0x400) == 0
      || event->GetBool(this: event, a2: "full_round", a3: false) )
    {
      this->FireGameEvent_Internal(this, a2: event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100974A0
// Name: public: virtual void CBaseAchievement::SetShowOnHUD(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::SetShowOnHUD(CBaseAchievement *this, bool bShow)
{
  if ( LOBYTE(this->m_pAchievementMgr) != bShow )
    *(_BYTE *)(LODWORD(this->m_iComponentBits) + *(&this->m_iProgressShown + 1) + 564) = 1;
  LOBYTE(this->m_pAchievementMgr) = bShow;
}

//------------------------------------------------------------------------------
// Address: 0x100974D0
// Name: protected: virtual void CBaseAchievement::CalcProgressMsgIncrement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::CalcProgressMsgIncrement(CBaseAchievement *this)
{
  int m_iGoal; // esi
  int v2; // eax

  m_iGoal = this->m_iGoal;
  this->m_iProgressMsgIncrement = m_iGoal / 4;
  if ( m_iGoal % 4 != 0 )
  {
    v2 = m_iGoal / 3;
    if ( m_iGoal % 3 == 0 || (v2 = m_iGoal / 5, m_iGoal % 5 == 0) )
      this->m_iProgressMsgIncrement = v2;
  }
  if ( this->m_iProgressMsgIncrement < 5 )
    this->m_iProgressMsgIncrement = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10097530
// Name: protected: void CBaseAchievement::AwardAchievement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::AwardAchievement(CBaseAchievement *this)
{
  if ( !this->IsAchieved(this: &this->IAchievement) )
    CAchievementMgr::AwardAchievement(
      this: this->m_pAchievementMgr,
      iAchievementID: this->m_iAchievementID,
      nUserSlot: this->m_nUserSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10097560
// Name: protected: void CBaseAchievement::ShowProgressNotification(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::ShowProgressNotification(CBaseAchievement *this)
{
  IGameEvent *v2; // esi
  IGameEvent_vtbl *v3; // ebx
  const char *v4; // eax

  if ( this->ShouldShowProgressNotification(this) )
  {
    v2 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "achievement_event", a3: 0, a4: 0);
    if ( v2 != nullptr )
    {
      v3 = v2->__vftable;
      v4 = this->GetName(this: &this->IAchievement);
      v3->SetString(this: v2, a2: "achievement_name", a3: v4);
      v2->SetInt(this: v2, a2: "cur_val", a3: this->m_iCount);
      v2->SetInt(this: v2, a2: "max_val", a3: this->m_iGoal);
      gameeventmanager->FireEvent(this: gameeventmanager, a2: v2, a3: false);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100975E0
// Name: public: virtual void CBaseAchievement::PreRestoreSavedGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::PreRestoreSavedGame(CBaseAchievement *this)
{
  if ( (this->m_iFlags & 0x40) != 0 )
    this->m_iCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100975F0
// Name: public: void CBaseAchievement::SetComponentBits(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::SetComponentBits(CBaseAchievement *this, unsigned __int64 iComponentBits)
{
  unsigned int v2; // edx
  unsigned int v3; // edi
  int v4; // ebx

  v3 = HIDWORD(iComponentBits);
  v2 = iComponentBits;
  v4 = 0;
  this->m_iComponentBits = iComponentBits;
  if ( iComponentBits != 0 )
  {
    do
    {
      if ( (v2 & 1) != 0 )
        ++v4;
      v2 = __PAIR64__(v3, v2) >> 1;
      v3 >>= 1;
    }
    while ( v3 != 0 || v2 != 0 );
    this->m_iCount = v4;
  }
  else
  {
    this->m_iCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097640
// Name: public: virtual bool CBaseAchievement::ShouldSaveWithGame(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseAchievement::ShouldSaveWithGame(CBaseAchievement *this)
{
  return ((int)this->IAchievement::__vftable & 0x40) != 0
      && ((int (__thiscall *)(CBaseAchievement *))this->ListenForEvents)(a1: this) > 0
      && ((unsigned __int8 (__thiscall *)(CBaseAchievement *))this->Event_EntityKilled)(a1: this) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10097670
// Name: public: virtual bool CBaseAchievement::IsActive(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAchievement::IsActive(CBaseAchievement *this)
{
  return !this->IsAchieved(this: &this->IAchievement)
      && (this->m_pMapNameFilter == nullptr
       || _V_strcmp(s1: this->m_pAchievementMgr->m_szMap, s2: this->m_pMapNameFilter) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x100976B0
// Name: public: virtual void CBaseAchievement::GetSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::GetSettings(CBaseAchievement *this, KeyValues *pNodeOut)
{
  bool v3; // al
  bool v4; // al

  v3 = this->IsAchieved(this: &this->IAchievement);
  KeyValues::SetInt(this: pNodeOut, keyName: "value", value: v3);
  if ( (this->m_iFlags & 0x20) != 0 )
  {
    KeyValues::SetUint64(this: pNodeOut, keyName: "data", value: this->m_iComponentBits);
  }
  else if ( !this->IsAchieved(this: &this->IAchievement) )
  {
    KeyValues::SetInt(this: pNodeOut, keyName: "data", value: this->m_iCount);
  }
  v4 = this->ShouldShowOnHUD(this: &this->IAchievement);
  KeyValues::SetInt(this: pNodeOut, keyName: "hud", value: v4);
  KeyValues::SetInt(this: pNodeOut, keyName: "msg", value: this->m_iProgressShown);
}

//------------------------------------------------------------------------------
// Address: 0x10097750
// Name: public: virtual void CBaseAchievement::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::ApplySettings(CBaseAchievement *this, KeyValues *pNodeIn)
{
  int Int; // eax
  unsigned __int64 Uint64; // rax
  int v6; // eax
  KeyValues *pNodeIna; // [esp+14h] [ebp+8h]

  if ( KeyValues::GetInt(this: pNodeIn, keyName: "value", defaultValue: 0) <= 0 )
  {
    if ( (this->m_iFlags & 0x20) != 0 )
    {
LABEL_6:
      Uint64 = KeyValues::GetUint64(this: pNodeIn, keyName: "data", defaultValue: 0);
      CBaseAchievement::SetComponentBits(this, iComponentBits: Uint64);
      goto LABEL_7;
    }
    Int = KeyValues::GetInt(this: pNodeIn, keyName: "data", defaultValue: 0);
  }
  else
  {
    Int = this->m_iGoal;
    this->m_bAchieved = true;
  }
  this->m_iCount = Int;
  if ( (this->m_iFlags & 0x20) != 0 )
    goto LABEL_6;
LABEL_7:
  pNodeIna = (KeyValues *)this->IAchievement::__vftable;
  v6 = KeyValues::GetInt(this: pNodeIn, keyName: "hud", defaultValue: 0);
  ((void (__thiscall *)(IAchievement *, bool))pNodeIna[1].m_wsValue)(a1: &this->IAchievement, a2: v6 != 0);
  this->m_iProgressShown = KeyValues::GetInt(this: pNodeIn, keyName: "msg", defaultValue: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100977F0
// Name: public: virtual void CBaseAchievement::ClearAchievementData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::ClearAchievementData(CBaseAchievement *this)
{
  bool v1; // zf

  v1 = (this->m_iFlags & 0x20) == 0;
  this->m_iCount = 0;
  this->m_bAchieved = false;
  if ( !v1 )
  {
    this->m_iComponentBits = 0;
    this->m_iCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097810
// Name: public: virtual char const __near * CBaseAchievement::GetComponentDisplayString(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseAchievement::GetComponentDisplayString(CBaseAchievement *this, int iComponent)
{
  if ( ((int)this->IAchievement::__vftable & 0x20) != 0 && iComponent >= 0 && iComponent <= (int)this->m_pGameDirFilter )
    return *(const char **)&this->m_pMapNameFilter[4 * iComponent];
  else
    return locale;
}

//------------------------------------------------------------------------------
// Address: 0x10097840
// Name: public: virtual bool CBaseAchievement::CheckAchievementsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAchievement::CheckAchievementsEnabled(CBaseAchievement *this)
{
  CGameRules_vtbl *v2; // esi
  int v3; // eax
  bool result; // al

  if ( g_pGameRules == nullptr )
    return CAchievementMgr::CheckAchievementsEnabled(this: this->m_pAchievementMgr);
  v2 = g_pGameRules->__vftable;
  v3 = this->GetAchievementID(this: &this->IAchievement);
  result = v2->CheckAchievementsEnabled(this: g_pGameRules, a2: v3);
  if ( result )
    return CAchievementMgr::CheckAchievementsEnabled(this: this->m_pAchievementMgr);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097880
// Name: protected: void CBaseAchievement::HandleProgressUpdate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::HandleProgressUpdate(CBaseAchievement *this)
{
  int m_iProgressMsgIncrement; // ecx
  int m_iCount; // eax
  int v4; // eax
  int v5; // et2
  int v6; // edi
  int m_nUserSlot; // eax
  CAchievementMgr *m_pAchievementMgr; // ecx

  m_iProgressMsgIncrement = this->m_iProgressMsgIncrement;
  if ( m_iProgressMsgIncrement > 0 )
  {
    m_iCount = this->m_iCount;
    if ( m_iCount >= this->m_iProgressMsgMinimum )
    {
      v5 = m_iCount % m_iProgressMsgIncrement;
      v4 = m_iCount / m_iProgressMsgIncrement;
      v6 = v4;
      if ( v5 == 0 && v4 > this->m_iProgressShown )
      {
        CBaseAchievement::ShowProgressNotification(this);
        m_nUserSlot = this->m_nUserSlot;
        m_pAchievementMgr = this->m_pAchievementMgr;
        this->m_iProgressShown = v6;
        m_pAchievementMgr->m_bDirty[m_nUserSlot] = true;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100978C0
// Name: protected: void CBaseAchievement::EvaluateNewAchievement(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::EvaluateNewAchievement(CBaseAchievement *this)
{
  int m_iGoal; // eax

  if ( !this->IsAchieved(this: &this->IAchievement) )
  {
    m_iGoal = this->m_iGoal;
    if ( m_iGoal > 0 && this->m_iCount >= m_iGoal )
    {
      this->m_pAchievementMgr->m_bCheckSigninState = false;
      if ( !this->IsAchieved(this: &this->IAchievement) )
        CAchievementMgr::AwardAchievement(
          this: this->m_pAchievementMgr,
          iAchievementID: this->m_iAchievementID,
          nUserSlot: this->m_nUserSlot);
      this->m_pAchievementMgr->m_bCheckSigninState = true;
      this->CheckAssetAwards(this, a2: this->m_nUserSlot);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097930
// Name: public: virtual void CBaseAchievement::PostRestoreSavedGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::PostRestoreSavedGame(CBaseAchievement *this)
{
  ISteamUserStats *m_pSteamUserStats; // esi
  ISteamUserStats_vtbl *v3; // ebx
  int v4; // eax
  bool v5; // [esp+Bh] [ebp-1h] BYREF

  m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
  if ( m_pSteamUserStats != nullptr )
  {
    v3 = m_pSteamUserStats->__vftable;
    v4 = ((int (__thiscall *)(IAchievement *, bool *))this->GetName)(a1: &this->IAchievement, a2: &v5);
    ((void (__thiscall *)(ISteamUserStats *, int))v3->GetAchievement)(a1: m_pSteamUserStats, a2: v4);
    this->m_bAchieved = v5;
  }
  CBaseAchievement::EvaluateNewAchievement(this);
}

//------------------------------------------------------------------------------
// Address: 0x10097980
// Name: public: CBaseAchievement::CBaseAchievement(void)
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__thiscall CBaseAchievement::CBaseAchievement(CBaseAchievement *this)
{
  this->m_bRegisteredForEvents = false;
  this->m_nDebugID = 42;
  this->IAchievement::__vftable = (IAchievement_vtbl *)&IAchievement::`vftable';
  this->CGameEventListener::IGameEventListener2::__vftable = (CBaseAchievement_vtbl *)&CBaseAchievement::`vftable'{for `CGameEventListener'};
  this->IAchievement::__vftable = (IAchievement_vtbl *)&CBaseAchievement::`vftable'{for `IAchievement'};
  this->m_iFlags = 0;
  this->m_iGoal = 0;
  this->m_iProgressMsgIncrement = 0;
  this->m_iProgressMsgMinimum = 0;
  this->m_iAchievementID = 0;
  this->m_iPointValue = 0;
  *(_WORD *)&this->m_bHideUntilAchieved = 0;
  this->m_pVictimClassNameFilter = nullptr;
  this->m_pAttackerClassNameFilter = nullptr;
  this->m_pInflictorClassNameFilter = nullptr;
  this->m_pInflictorEntityNameFilter = nullptr;
  this->m_pMapNameFilter = nullptr;
  this->m_pGameDirFilter = nullptr;
  this->m_pszComponentNames = nullptr;
  this->m_pszComponentDisplayNames = nullptr;
  this->m_pszComponentPrefix = nullptr;
  this->m_iNumComponents = 0;
  this->m_iComponentPrefixLen = 0;
  this->m_iComponentBits = 0;
  this->m_iCount = 0;
  this->m_iProgressShown = 0;
  this->m_bAchieved = false;
  this->m_uUnlockTime = 0;
  this->m_pAchievementMgr = nullptr;
  this->m_nUserSlot = 0;
  this->m_iAssetAwardID = 0;
  this->m_bShowOnHUD = false;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10097A20
// Name: public: virtual bool CBaseAchievement::ShouldHideUntilAchieved(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAchievement::ShouldHideUntilAchieved(CBaseAchievement *this)
{
  return this->m_iProgressMsgIncrement;
}

//------------------------------------------------------------------------------
// Address: 0x10097A30
// Name: public: virtual int CBaseAchievement::GetCount(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAchievement::GetCount(CChoreoEvent *this)
{
  return this->m_nLoopsRemaining;
}

//------------------------------------------------------------------------------
// Address: 0x10097A40
// Name: public: virtual bool CBaseAchievement::IsAchieved(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAchievement::IsAchieved(CBaseAchievement *this)
{
  return this->m_iNumComponents;
}

//------------------------------------------------------------------------------
// Address: 0x10097A50
// Name: public: virtual unsigned __int64 CBaseAchievement::GetComponentBits(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CBaseAchievement::GetComponentBits(CBaseAchievement *this)
{
  return *(_QWORD *)&this->m_iCount;
}

//------------------------------------------------------------------------------
// Address: 0x10097A60
// Name: public: virtual bool CBaseAchievement::ShouldShowOnHUD(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseAchievement::ShouldShowOnHUD(CBaseAchievement *this)
{
  return (bool)this->m_pAchievementMgr;
}

//------------------------------------------------------------------------------
// Address: 0x10097A70
// Name: public: virtual void CBaseAchievement::SetUserSlot(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::SetUserSlot(CBaseAchievement *this, int nUserSlot)
{
  this->m_nUserSlot = nUserSlot;
}

//------------------------------------------------------------------------------
// Address: 0x10097A80
// Name: public: virtual int CBaseAchievement::GetDisplayOrder(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAchievement::GetDisplayOrder(CBaseAchievement *this)
{
  return HIDWORD(this->m_iComponentBits);
}

//------------------------------------------------------------------------------
// Address: 0x10097A90
// Name: protected: void CBaseAchievement::IncrementCount(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::IncrementCount(CBaseAchievement *this, int iOptIncrement)
{
  int v3; // ecx
  const char *v4; // eax
  int m_iGoal; // eax
  const char *v6; // eax
  int v7; // eax
  int v8; // [esp-8h] [ebp-10h]
  int v9; // [esp-4h] [ebp-Ch]

  if ( !this->IsAchieved(this: &this->IAchievement) )
  {
    if ( this->CheckAchievementsEnabled(this) )
    {
      if ( iOptIncrement <= 0 )
      {
        ++this->m_iCount;
      }
      else
      {
        this->m_iCount += iOptIncrement;
        m_iGoal = this->m_iGoal;
        if ( this->m_iCount > m_iGoal )
          this->m_iCount = m_iGoal;
      }
      if ( (this->GetFlags(this: &this->IAchievement) & 0x80u) != 0 )
        this->m_pAchievementMgr->m_bDirty[this->m_nUserSlot] = true;
      if ( cc_achievement_debug.m_pParent != nullptr && cc_achievement_debug.m_pParent->m_Value.m_nValue != 0 )
      {
        v6 = (const char *)((int (__thiscall *)(IAchievement *, int, int))this->GetName)(
                             a1: &this->IAchievement,
                             a2: this->m_iCount,
                             a3: this->m_iGoal);
        _Msg(a1: "Achievement count increased for %s: %d/%d\n", v6, v8, v9);
      }
      v7 = this->m_iGoal;
      if ( v7 > 0 )
      {
        if ( this->m_iCount < v7 )
          CBaseAchievement::HandleProgressUpdate(this);
        else
          CBaseAchievement::AwardAchievement(this);
      }
    }
    else
    {
      v3 = g_nAchivementBitchCount++;
      if ( v3 < 10 )
      {
        v4 = this->GetName(this: &this->IAchievement);
        DevMsg(a1: "Achievements disabled, ignoring achievement progress for %s\n", v4);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10097B80
// Name: public: virtual void CBaseAchievement::OnMapEvent(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::OnMapEvent(CBaseAchievement *this, const char *pEventName)
{
  const char *v3; // eax

  v3 = this->GetName(this: &this->IAchievement);
  if ( _V_stricmp(s1: pEventName, s2: v3) == 0 )
    CBaseAchievement::IncrementCount(this, iOptIncrement: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10097C00
// Name: public: virtual void CBaseAchievement::Event_EntityKilled(class CBaseEntity __near *,class CBaseEntity __near *,class CBaseEntity __near *,class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAchievement::Event_EntityKilled(
        CBaseAchievement *this,
        CBaseEntity *pVictim,
        CBaseEntity *pAttacker,
        CBaseEntity *pInflictor,
        CBaseEntity *event)
{
  if ( (this->GetFlags(this: &this->IAchievement) & 1) != 0 )
    CBaseAchievement::IncrementCount(this, iOptIncrement: 0);
}

//------------------------------------------------------------------------------
// Address: 0x103868E0
// Name: public: virtual int CBaseAchievement::GetNumComponents(void)
// Source: json
//------------------------------------------------------------------------------
vgui::KeyBindingContextHandle_t __thiscall CBaseAchievement::GetNumComponents(vgui::Panel *this)
{
  return this->m_hKeyBindingsContext;
}

//------------------------------------------------------------------------------
// Address: 0x103FF140
// Name: CBaseAchievement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CBaseAchievement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CBaseAchievement>(__formal: nullptr);
  CBaseAchievement_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x103FF150
// Name: CFailableAchievement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *CFailableAchievement_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<CFailableAchievement>(__formal: nullptr);
  CFailableAchievement_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10097C20
// Name: struct datamap_t __near * DataMapInit<class CBaseAchievement>(class CBaseAchievement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CBaseAchievement>()
{
  if ( (_S2_44 & 1) == 0 )
  {
    _S2_44 |= 1u;
    nameHolder_81.m_pszBase = "CBaseAchievement";
    nameHolder_81.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_81.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_81.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_81.m_Names.m_Size = 0;
    nameHolder_81.m_Names.m_pElements = nullptr;
    nameHolder_81.m_nLenBase = 16;
    atexit(func: DataMapInit_CBaseAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CBaseAchievement::m_DataMap.baseMap = nullptr;
  CBaseAchievement::m_DataMap.dataNumFields = 1;
  CBaseAchievement::m_DataMap.dataDesc = &dataDesc_78[1];
  return &CBaseAchievement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x10097CA0
// Name: struct datamap_t __near * DataMapInit<class CFailableAchievement>(class CFailableAchievement __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
datamap_t *__cdecl DataMapInit<CFailableAchievement>()
{
  if ( (_S3_20 & 1) == 0 )
  {
    _S3_20 |= 1u;
    nameHolder_82.m_pszBase = "CFailableAchievement";
    nameHolder_82.m_Names.m_Memory.m_pMemory = nullptr;
    nameHolder_82.m_Names.m_Memory.m_nAllocationCount = 0;
    nameHolder_82.m_Names.m_Memory.m_nGrowSize = 0;
    nameHolder_82.m_Names.m_Size = 0;
    nameHolder_82.m_Names.m_pElements = nullptr;
    nameHolder_82.m_nLenBase = 20;
    atexit(func: DataMapInit_CFailableAchievement__::_2_::_dynamic_atexit_destructor_for__nameHolder__);
  }
  CFailableAchievement::m_DataMap.baseMap = &CBaseAchievement::m_DataMap;
  CFailableAchievement::m_DataMap.dataNumFields = 2;
  CFailableAchievement::m_DataMap.dataDesc = &dataDesc_79[1];
  return &CFailableAchievement::m_DataMap;
}

//------------------------------------------------------------------------------
// Address: 0x103FF160
// Name: _dynamic_initializer_for__ai_sequence_debug__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__ai_sequence_debug__()
{
  ConVar::ConVar(this: &ai_sequence_debug, pName: "ai_sequence_debug", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__ai_sequence_debug__);
}

} // namespace server
