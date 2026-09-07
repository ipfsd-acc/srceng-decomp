// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/shared/achievementmgr.cpp
// Functions: 41
// ============================================================

#include "game\shared\achievementmgr.h"

//------------------------------------------------------------------------------
// Address: 0x10001070
// Name: AchievementIDCompare
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl AchievementIDCompare(CBaseAchievement *const *ach1, CBaseAchievement *const *ach2)
{
  int v2; // esi
  int v3; // edi

  v2 = (int)*ach2;
  v3 = (*ach1)->GetAchievementID(this: &(*ach1)->IAchievement);
  return v3 > (**(int (__thiscall ***)(int))(v2 + 12))(a1: v2 + 12);
}

//------------------------------------------------------------------------------
// Address: 0x100010B0
// Name: AchievementOrderCompare
// Source: json
//------------------------------------------------------------------------------
int __cdecl AchievementOrderCompare(CBaseAchievement *const *ach1, CBaseAchievement *const *ach2)
{
  int v2; // esi
  int v3; // edi

  v2 = (int)*ach1;
  v3 = (*ach2)->GetDisplayOrder(this: &(*ach2)->IAchievement);
  return (*(int (__thiscall **)(int))(*(_DWORD *)(v2 + 12) + 52))(a1: v2 + 12) - v3;
}

//------------------------------------------------------------------------------
// Address: 0x100010E0
// Name: public: void CAchievementMgr::ResetProfileInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::ResetProfileInfo(CAchievementMgr *this)
{
  this->m_UIProfileInfo.m_BotDifficulty = 0;
  this->m_UIProfileInfo.m_GameMode = 0;
  this->m_UIProfileInfo.m_IsPublic = true;
  this->m_UIProfileInfo.m_Map = 0;
  this->m_UIProfileInfo.m_LeaderboardFilter = 0;
  this->m_UIProfileInfo.m_LeaderboardMode = 0;
  this->m_UIProfileInfo.m_LeaderboardType = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001100
// Name: public: virtual void CAchievementMgr::InitializeAchievements(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::InitializeAchievements(CAchievementMgr *this)
{
  this->Shutdown(this);
  this->PostInit(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001120
// Name: char const __near * COM_GetModDirectory(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl COM_GetModDirectory()
{
  int v0; // edi
  int *v1; // ebx
  int v2; // esi
  int v3; // eax
  const char *v4; // esi
  int v5; // eax
  int v6; // eax
  int v7; // eax

  if ( _V_strlen(str: modDir) != 0 )
    return modDir;
  v0 = _CommandLine();
  v1 = (int *)_CommandLine();
  v2 = *v1;
  v3 = (*(int (__thiscall **)(int, const char *, const char *))(*(_DWORD *)v0 + 32))(
         a1: v0,
         a2: "-defaultgamedir",
         a3: "hl2");
  v4 = (const char *)(*(int (__thiscall **)(int *, const char *, int))(v2 + 32))(a1: v1, a2: "-game", a3: v3);
  V_strncpy(pDest: modDir, pSrc: v4, maxLen: 260);
  strchr(string: (unsigned __int8 *)modDir, chr: 0x2Fu);
  if ( v5 != 0 || (strchr(string: (unsigned __int8 *)modDir, chr: 0x5Cu), v6 != 0) )
  {
    V_StripLastDir(dirName: modDir, maxlen: 260);
    v7 = _V_strlen(str: modDir);
    V_strncpy(pDest: modDir, pSrc: &v4[v7], maxLen: 260 - v7);
  }
  return modDir;
}

//------------------------------------------------------------------------------
// Address: 0x100011E0
// Name: public: void CAchievementMgr::UploadUserData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::UploadUserData(CAchievementMgr *this, int nUserSlot)
{
  ISteamUserStats *m_pSteamUserStats; // ecx

  if ( nUserSlot == 0 )
  {
    m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
    if ( m_pSteamUserStats != nullptr )
    {
      m_pSteamUserStats->StoreStats(this: m_pSteamUserStats);
      this->m_flTimeLastUpload = _Plat_FloatTime();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001210
// Name: public: void CAchievementMgr::SendResetProfileEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::SendResetProfileEvent(CAchievementMgr *this)
{
  IGameEvent *v1; // eax

  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "reset_user_profile", a3: 0, a4: 0);
  if ( v1 != nullptr )
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10001240
// Name: public: void CAchievementMgr::SendWriteProfileEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::SendWriteProfileEvent(CAchievementMgr *this)
{
  IGameEvent *v1; // eax

  v1 = gameeventmanager->CreateEventA(this: gameeventmanager, a2: "write_user_profile", a3: 0, a4: 0);
  if ( v1 != nullptr )
    gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v1);
}

//------------------------------------------------------------------------------
// Address: 0x10001270
// Name: public: bool CAchievementMgr::IsAchievementAllowedInGame(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAchievementMgr::IsAchievementAllowedInGame(CAchievementMgr *this, int iAchievementID)
{
  char v2; // bl

  v2 = 0;
  if ( iAchievementID > 5037 )
  {
    switch ( iAchievementID )
    {
      case 6019:
      case 6020:
      case 6021:
      case 6022:
      case 6023:
      case 6024:
      case 6025:
      case 6029:
      case 6030:
      case 6031:
      case 6033:
      case 6034:
      case 6035:
      case 6036:
      case 6037:
      case 6038:
      case 6039:
      case 6040:
        goto $LN3;
      default:
        break;
    }
  }
  else
  {
    if ( iAchievementID != 5037 )
    {
      if ( iAchievementID > 3051 )
      {
        if ( iAchievementID < 5004 || iAchievementID > 5011 )
          goto LABEL_9;
      }
      else if ( iAchievementID < 3044 && (iAchievementID < 1014 || iAchievementID > 1015 && iAchievementID != 3030) )
      {
        goto LABEL_9;
      }
    }
$LN3:
    v2 = 1;
  }
LABEL_9:
  if ( C_CSGameRules::IsPlayingGunGame(this: (C_CSGameRules *)g_pGameRules) )
    return v2;
  else
    return v2 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001340
// Name: public: class CStudioHdr __near * C_BaseAnimating::GetModelPtr(void)const
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall C_BaseAnimating::GetModelPtr(C_BaseAnimating *this)
{
  CStudioHdr *result; // eax

  if ( this->m_pStudioHdr == nullptr && this->GetModel(this: &this->IClientRenderable) != nullptr )
    C_BaseAnimating::LockStudioHdr(this);
  result = this->m_pStudioHdr;
  if ( result == nullptr || result->m_pStudioHdr == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100013D0
// Name: public: char const __near * studiohdr_t::pszName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall studiohdr_t::pszName(studiohdr_t *this)
{
  int studiohdr2index; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // ecx

  studiohdr2index = this->studiohdr2index;
  if ( studiohdr2index == 0 )
    return this->name;
  v2 = *(_DWORD *)&this->name[studiohdr2index + 8];
  v3 = (char *)this + studiohdr2index;
  if ( v2 == 0 || &v3[v2] == nullptr )
    return this->name;
  v4 = *((_DWORD *)v3 + 5);
  if ( v4 != 0 )
    return &v3[v4];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001430
// Name: public: void CAchievementMgr::SaveGlobalState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::SaveGlobalState(CAchievementMgr *this)
{
  IMatchSystem *v2; // eax
  int v3; // eax
  int v4; // ebx
  int i; // edi
  CBaseAchievement *v6; // ecx
  int j; // edi
  CBaseAchievement *v8; // ecx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CAchievementMgr::SaveGlobalState",
    a3: 0,
    a4: "Achievements",
    a5: false,
    a6: 4);
  v2 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v3 = v2->GetPlayerManager(this: v2);
  v4 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 4))(a1: v3, a2: 0);
  if ( v4 != 0 )
  {
    for ( i = 0; i < this->m_vecAchievement[0].m_Size; ++i )
    {
      v6 = this->m_vecAchievement[0].m_Memory.m_pMemory[i];
      if ( v6 != nullptr )
        v6->WriteProgress(this: v6, a2: (IPlayerLocal *)v4);
    }
    for ( j = 0; j < this->m_vecAward[0].m_Size; ++j )
    {
      v8 = this->m_vecAward[0].m_Memory.m_pMemory[j];
      if ( v8 != nullptr )
        v8->WriteProgress(this: v8, a2: (IPlayerLocal *)v4);
    }
    this->m_bDirty[0] = false;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001500
// Name: public: void CAchievementMgr::SaveGlobalStateIfDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::SaveGlobalStateIfDirty(CAchievementMgr *this)
{
  if ( this != (CAchievementMgr *)-564 && !this->m_bReadingFromTitleData )
    CAchievementMgr::SaveGlobalState(this);
}

//------------------------------------------------------------------------------
// Address: 0x10001520
// Name: public: bool CAchievementMgr::CheckAchievementsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAchievementMgr::CheckAchievementsEnabled(CAchievementMgr *this)
{
  ISteamUtils *m_pSteamUtils; // ecx

  if ( cc_achievement_disable.m_pParent != nullptr && cc_achievement_disable.m_pParent->m_Value.m_nValue != 0 )
    return 0;
  if ( steamapicontext->m_pSteamUser == nullptr
    || steamapicontext->m_pSteamUserStats == nullptr
    || !steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser) )
  {
    _Msg(a1: "Achievements disabled: Steam not running.\n");
    return 0;
  }
  if ( IsInCommentaryMode() )
  {
    _Msg(a1: "Achievements disabled: in commentary mode.\n");
    return 0;
  }
  else if ( engine->IsPlayingDemo(this: engine) )
  {
    _Msg(a1: "Achievements disabled: demo playing.\n");
    return 0;
  }
  else
  {
    if ( !this->m_bCheatsEverOn )
      return 1;
    if ( developer.m_pParent != nullptr
      && developer.m_pParent->m_Value.m_nValue != 0
      && (m_pSteamUtils = steamapicontext->m_pSteamUtils) != nullptr
      && m_pSteamUtils->GetConnectedUniverse(this: m_pSteamUtils) != k_EUniversePublic )
    {
      return 1;
    }
    else
    {
      _Msg(a1: "Achievements disabled: cheats turned on in this app session.\n");
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100015F0
// Name: private: void CAchievementMgr::OnKillEvent(class C_BaseEntity __near *,class C_BaseEntity __near *,class C_BaseEntity __near *,class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::OnKillEvent(
        CAchievementMgr *this,
        C_BaseEntity *pVictim,
        C_BasePlayer *pAttacker,
        C_BaseEntity *pInflictor,
        IGameEvent *event)
{
  CAchievementMgr *v5; // edi
  C_BasePlayer *LocalPlayer; // esi
  int i; // ebx
  _DWORD *v8; // esi
  bool bVictimIsPlayerEnemy; // [esp+Eh] [ebp-2h]
  bool bAttackerIsPlayer; // [esp+Fh] [ebp-1h]

  v5 = this;
  event->GetInt(this: event, a2: "splitscreenplayer", a3: 0);
  if ( pVictim != nullptr )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    bVictimIsPlayerEnemy = !LocalPlayer->InSameTeam(this: LocalPlayer, a2: pVictim);
    bAttackerIsPlayer = pAttacker == LocalPlayer;
    for ( i = 0; i < v5->m_vecKillEventListeners[0].m_Size; ++i )
    {
      v8 = &v5->m_vecKillEventListeners[0].m_Memory.m_pMemory[i]->CGameEventListener::IGameEventListener2::__vftable;
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *))(*v8 + 40))(a1: v8) != 0 )
      {
        if ( (((*(int (__thiscall **)(_DWORD *))(v8[3] + 8))(a1: v8 + 3) & 0x100) == 0 || bAttackerIsPlayer)
          && (((*(int (__thiscall **)(_DWORD *))(v8[3] + 8))(a1: v8 + 3) & 0x200) == 0 || bVictimIsPlayerEnemy) )
        {
          (*(void (__thiscall **)(_DWORD *, C_BaseEntity *, C_BasePlayer *, C_BaseEntity *, IGameEvent *))(*v8 + 20))(
            a1: v8,
            a2: pVictim,
            a3: pAttacker,
            a4: pInflictor,
            a5: event);
        }
        v5 = this;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100016D0
// Name: public: void CAchievementMgr::OnMapEvent(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::OnMapEvent(CAchievementMgr *this, const char *pchEventName, int nUserSlot)
{
  int v4; // ebx
  CBaseAchievement *v5; // esi
  int v6; // esi
  int *v7; // ebx
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int> > *v8; // edi
  CAchievementMgr *v9; // [esp+0h] [ebp-8h]
  int *p_m_Size; // [esp+4h] [ebp-4h]
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int> > *nUserSlota; // [esp+14h] [ebp+Ch]

  v9 = this;
  if ( pchEventName != nullptr && *pchEventName != 0 )
  {
    v4 = 0;
    p_m_Size = &this->m_vecComponentListeners[nUserSlot].m_Size;
    if ( *p_m_Size <= 0 )
    {
LABEL_8:
      v6 = 0;
      v7 = &this->m_vecMapEventListeners[nUserSlot].m_Size;
      if ( *v7 > 0 )
      {
        v8 = &this->m_vecMapEventListeners[nUserSlot];
        do
        {
          v8->m_Memory.m_pMemory[v6]->OnMapEvent(this: v8->m_Memory.m_pMemory[v6], a2: pchEventName);
          ++v6;
        }
        while ( v6 < *v7 );
      }
    }
    else
    {
      nUserSlota = &this->m_vecComponentListeners[nUserSlot];
      while ( 1 )
      {
        v5 = nUserSlota->m_Memory.m_pMemory[v4];
        if ( V_strncmp(s1: pchEventName, s2: v5->m_pszComponentPrefix, count: v5->m_iComponentPrefixLen) == 0 )
          break;
        if ( ++v4 >= *p_m_Size )
        {
          this = v9;
          goto LABEL_8;
        }
      }
      CBaseAchievement::OnComponentEvent(this: v5, pchComponentName: pchEventName);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001790
// Name: public: class IAchievement __near * CAchievementMgr::GetAchievementByIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
IAchievement *__thiscall CAchievementMgr::GetAchievementByIndex(CAchievementMgr *this, int index, int nUserSlot)
{
  CBaseAchievement *v3; // eax

  v3 = this->m_vecAchievement[nUserSlot].m_Memory.m_pMemory[index];
  if ( v3 != nullptr )
    return &v3->IAchievement;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100017C0
// Name: public: class IAchievement __near * CAchievementMgr::GetAchievementByDisplayOrder(int,int)
// Source: json
//------------------------------------------------------------------------------
IAchievement *__thiscall CAchievementMgr::GetAchievementByDisplayOrder(
        CAchievementMgr *this,
        int orderIndex,
        int nUserSlot)
{
  CBaseAchievement *v3; // eax

  v3 = this->m_vecAchievementInOrder[nUserSlot].m_Memory.m_pMemory[orderIndex];
  if ( v3 != nullptr )
    return &v3->IAchievement;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100017F0
// Name: public: class IAchievement __near * CAchievementMgr::GetAwardByDisplayOrder(int,int)
// Source: json
//------------------------------------------------------------------------------
IAchievement *__thiscall CAchievementMgr::GetAwardByDisplayOrder(CAchievementMgr *this, int orderIndex, int nUserSlot)
{
  CBaseAchievement *v3; // eax

  v3 = this->m_vecAwardInOrder[nUserSlot].m_Memory.m_pMemory[orderIndex];
  if ( v3 != nullptr )
    return &v3->IAchievement;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10001C10
// Name: public: void CAchievementMgr::ReadAchievementsFromTitleData(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::ReadAchievementsFromTitleData(
        CAchievementMgr *this,
        IPlayerLocal *iController,
        int iSlot)
{
  IMatchSystem *v4; // eax
  int v5; // eax
  int v6; // eax
  int *p_m_Size; // edx
  int v9; // edi
  CBaseAchievement *v10; // ecx
  int *v11; // edx
  int v12; // edi
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int> > *v13; // esi
  CBaseAchievement *v14; // ecx
  int *i; // [esp+4h] [ebp-4h]
  IPlayerLocal *pPlayer; // [esp+10h] [ebp+8h]
  int iSlota; // [esp+14h] [ebp+Ch]

  v4 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v5 = v4->GetPlayerManager(this: v4);
  v6 = (*(int (__thiscall **)(int, IPlayerLocal *))(*(_DWORD *)v5 + 4))(a1: v5, a2: iController);
  pPlayer = (IPlayerLocal *)v6;
  if ( v6 != 0 )
  {
    p_m_Size = &this->m_vecAchievement[iSlot].m_Size;
    v9 = 0;
    this->m_bReadingFromTitleData = true;
    for ( i = p_m_Size; v9 < *p_m_Size; ++v9 )
    {
      v10 = this->m_vecAchievement[iSlot].m_Memory.m_pMemory[v9];
      if ( v10 != nullptr )
      {
        v10->ReadProgress(this: v10, a2: (IPlayerLocal *)v6);
        p_m_Size = i;
        v6 = (int)pPlayer;
      }
    }
    v11 = &this->m_vecAward[iSlot].m_Size;
    v12 = 0;
    iSlota = (int)v11;
    if ( *v11 > 0 )
    {
      v13 = &this->m_vecAward[iSlot];
      do
      {
        v14 = v13->m_Memory.m_pMemory[v12];
        if ( v14 != nullptr )
        {
          v14->ReadProgress(this: v14, a2: (IPlayerLocal *)v6);
          v11 = (int *)iSlota;
          v6 = (int)pPlayer;
        }
        ++v12;
      }
      while ( v12 < *v11 );
    }
    this->m_bReadingFromTitleData = false;
    if ( this != (CAchievementMgr *)-564 )
      CAchievementMgr::SaveGlobalState(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001CF0
// Name: public: int CAchievementMgr::GetAchievementCount(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAchievementMgr::GetAchievementCount(CAchievementMgr *this, bool bAssets)
{
  int m_NumElements; // esi
  __int64 v3; // rax
  UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edi
  CBaseAchievement *elem; // ecx

  m_NumElements = this->m_mapAchievement[0].m_Tree.m_NumElements;
  v3 = 0;
  if ( this->m_mapAchievement[0].m_Tree.m_NumElements != 0 )
  {
    m_pMemory = this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory;
    while ( 1 )
    {
      elem = m_pMemory[WORD2(v3)].m_Data.elem;
      if ( bAssets )
        break;
      if ( elem->m_iAssetAwardID <= 0 )
        goto LABEL_7;
LABEL_8:
      ++HIDWORD(v3);
      if ( SHIDWORD(v3) >= m_NumElements )
        return v3;
    }
    if ( elem->m_iAssetAwardID <= 0 )
      goto LABEL_8;
LABEL_7:
    LODWORD(v3) = v3 + 1;
    goto LABEL_8;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001D40
// Name: public: virtual void CAchievementMgr::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::OnEvent(CAchievementMgr *this, KeyValues *pEvent)
{
  const char *Name; // eax
  IPlayerLocal *Int; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnProfileDataLoaded") == 0 )
  {
    Int = (IPlayerLocal *)KeyValues::GetInt(this: pEvent, keyName: "iController", defaultValue: 0);
    CAchievementMgr::ReadAchievementsFromTitleData(
      this: (CAchievementMgr *)((char *)this - 24),
      iController: Int,
      iSlot: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001D90
// Name: public: virtual void CAchievementMgr::Update(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::Update(CAchievementMgr *this, float frametime)
{
  ConVar *v2; // eax
  int i; // edi
  CAchievementMgr::achievementthink_t *v5; // eax
  CBaseAchievement *pAchievement; // ecx

  v2 = (ConVar *)sv_cheats;
  if ( sv_cheats == nullptr )
  {
    v2 = cvar->FindVar_2(this: cvar, a2: "sv_cheats");
    sv_cheats = v2;
  }
  if ( !this->m_bCheatsEverOn && v2 != nullptr && v2->m_pParent != nullptr && v2->m_pParent->m_Value.m_nValue != 0 )
    this->m_bCheatsEverOn = true;
  for ( i = this->m_vecThinkListeners.m_Size - 1; i >= 0; --i )
  {
    v5 = &this->m_vecThinkListeners.m_Memory.m_pMemory[i];
    if ( *(float *)(gpGlobals.m_Index + 12) > v5->m_flThinkTime )
    {
      v5->pAchievement->Think(this: v5->pAchievement);
      pAchievement = this->m_vecThinkListeners.m_Memory.m_pMemory[i].pAchievement;
      if ( pAchievement->IsAchieved(this: &pAchievement->IAchievement)
        || *(float *)(gpGlobals.m_Index + 12) > this->m_vecThinkListeners.m_Memory.m_pMemory[i].m_flThinkTime )
      {
        if ( this->m_vecThinkListeners.m_Size - i - 1 > 0 )
          _V_memmove(
            dest: &this->m_vecThinkListeners.m_Memory.m_pMemory[i],
            src: &this->m_vecThinkListeners.m_Memory.m_pMemory[i + 1],
            count: 8 * (this->m_vecThinkListeners.m_Size - i - 1));
        --this->m_vecThinkListeners.m_Size;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100028E0
// Name: public: virtual void CAchievementMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::Shutdown(CAchievementMgr *this)
{
  int i; // edi
  CBaseAchievement *elem; // ecx
  IMatchEventsSink *v4; // esi
  IMatchEventsSubscription *v5; // eax

  CAchievementMgr::SaveGlobalState(this);
  for ( i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapAchievement[0].m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_mapAchievement[0].m_Tree,
              i) )
  {
    elem = this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
    if ( elem != nullptr )
      ((void (__thiscall *)(CBaseAchievement *, int))elem->dtr_IGameEventListener2)(a1: elem, a2: 1);
  }
  CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapAchievement[0].m_Tree);
  this->m_vecAchievement[0].m_Size = 0;
  this->m_vecAward[0].m_Size = 0;
  this->m_vecAchievementInOrder[0].m_Size = 0;
  this->m_vecAwardInOrder[0].m_Size = 0;
  this->m_vecKillEventListeners[0].m_Size = 0;
  this->m_vecMapEventListeners[0].m_Size = 0;
  this->m_vecComponentListeners[0].m_Size = 0;
  this->m_AchievementsAwarded[0].m_Size = 0;
  this->m_AchievementsAwardedDuringCurrentGame[0].m_Size = 0;
  if ( this != nullptr )
    v4 = &this->IMatchEventsSink;
  else
    v4 = nullptr;
  v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v5->Unsubscribe(this: v5, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x100029A0
// Name: public: virtual void CAchievementMgr::LevelInitPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CAchievementMgr::LevelInitPreEntity(
        CAchievementMgr *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        char *a4@<esi>)
{
  CAchievementMgr *v4; // esi
  CUtlMemory<vgui::TreeNode *,int> *m_vecKillEventListeners; // edi
  CUtlMemory<vgui::TreeNode *,int> *m_vecMapEventListeners; // ebx
  const char *v7; // eax
  unsigned __int16 Inorder; // ax
  CBaseAchievement *elem; // ecx
  const char *m_pMapNameFilter; // eax
  vgui::TreeNode **m_pMemory; // esi
  int m_nAllocationCount; // eax
  vgui::TreeNode **v13; // ecx
  int v14; // eax
  CBaseAchievement **v15; // esi
  vgui::TreeNode **v16; // esi
  int v17; // eax
  vgui::TreeNode **v18; // ecx
  int v19; // eax
  CBaseAchievement **v20; // esi
  int m_Size; // esi
  int v22; // eax
  CBaseAchievement **v23; // ecx
  int v24; // eax
  CBaseAchievement **v25; // esi
  int iAchievement; // [esp+0h] [ebp-Ch]
  CBaseAchievement *pAchievement; // [esp+4h] [ebp-8h]

  v4 = this;
  this->m_bCheatsEverOn = false;
  this->m_vecKillEventListeners[0].m_Size = 0;
  this->m_vecMapEventListeners[0].m_Size = 0;
  this->m_vecComponentListeners[0].m_Size = 0;
  this->m_AchievementsAwarded[0].m_Size = 0;
  m_vecKillEventListeners = (CUtlMemory<vgui::TreeNode *,int> *)this->m_vecKillEventListeners;
  m_vecMapEventListeners = (CUtlMemory<vgui::TreeNode *,int> *)this->m_vecMapEventListeners;
  this->m_flLastClassChangeTime[0] = 0.0;
  this->m_flTeamplayStartTime[0] = 0.0;
  this->m_iMiniroundsCompleted[0] = 0.0;
  v7 = (const char *)((int (__thiscall *)(IVEngineClient *, char *, int, int))engine->GetLevelName)(
                       a1: engine,
                       a2: this->m_szMap,
                       a3: 260,
                       a4: a3);
  V_FileBase(in: v7, out: a4, maxlen: a2);
  if ( v4->m_bUserSlotActive[0] )
  {
    Inorder = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v4->m_mapAchievement[0].m_Tree);
    LOWORD(iAchievement) = Inorder;
    if ( Inorder != 0xFFFF )
    {
      while ( 1 )
      {
        elem = v4->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem;
        m_pMapNameFilter = elem->m_pMapNameFilter;
        pAchievement = elem;
        if ( m_pMapNameFilter != nullptr )
        {
          if ( _V_strcmp(s1: v4->m_szMap, s2: m_pMapNameFilter) != 0 )
            goto LABEL_34;
          elem = pAchievement;
        }
        if ( (elem->GetFlags(this: &elem->IAchievement) & 1) != 0 )
        {
          m_pMemory = m_vecKillEventListeners[1].m_pMemory;
          m_nAllocationCount = m_vecKillEventListeners->m_nAllocationCount;
          if ( (int)m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: m_vecKillEventListeners,
              num: (int)m_pMemory - m_nAllocationCount + 1);
          ++m_vecKillEventListeners[1].m_pMemory;
          v13 = m_vecKillEventListeners->m_pMemory;
          v14 = (char *)m_vecKillEventListeners[1].m_pMemory - (char *)m_pMemory - 1;
          m_vecKillEventListeners[1].m_nAllocationCount = (int)m_vecKillEventListeners->m_pMemory;
          if ( v14 > 0 )
            _V_memmove(dest: &v13[(_DWORD)m_pMemory + 1], src: &v13[(_DWORD)m_pMemory], count: 4 * v14);
          v15 = (CBaseAchievement **)&m_vecKillEventListeners->m_pMemory[(_DWORD)m_pMemory];
          if ( v15 != nullptr )
            *v15 = pAchievement;
          v4 = this;
        }
        if ( (pAchievement->GetFlags(this: &pAchievement->IAchievement) & 2) != 0 )
        {
          v16 = m_vecMapEventListeners[1].m_pMemory;
          v17 = m_vecMapEventListeners->m_nAllocationCount;
          if ( (int)v16 + 1 > v17 )
            CUtlMemory<CChoreoActor *,int>::Grow(this: m_vecMapEventListeners, num: (int)v16 - v17 + 1);
          ++m_vecMapEventListeners[1].m_pMemory;
          v18 = m_vecMapEventListeners->m_pMemory;
          v19 = (char *)m_vecMapEventListeners[1].m_pMemory - (char *)v16 - 1;
          m_vecMapEventListeners[1].m_nAllocationCount = (int)m_vecMapEventListeners->m_pMemory;
          if ( v19 > 0 )
            _V_memmove(dest: &v18[(_DWORD)v16 + 1], src: &v18[(_DWORD)v16], count: 4 * v19);
          v20 = (CBaseAchievement **)&m_vecMapEventListeners->m_pMemory[(_DWORD)v16];
          if ( v20 != nullptr )
            *v20 = pAchievement;
          v4 = this;
        }
        if ( (pAchievement->GetFlags(this: &pAchievement->IAchievement) & 4) != 0 )
        {
          m_Size = v4->m_vecComponentListeners[0].m_Size;
          v22 = this->m_vecComponentListeners[0].m_Memory.m_nAllocationCount;
          if ( m_Size + 1 > v22 )
            CUtlMemory<CChoreoActor *,int>::Grow(
              this: (CUtlMemory<vgui::TreeNode *,int> *)this->m_vecComponentListeners,
              num: m_Size - v22 + 1);
          ++this->m_vecComponentListeners[0].m_Size;
          v23 = this->m_vecComponentListeners[0].m_Memory.m_pMemory;
          v24 = this->m_vecComponentListeners[0].m_Size - m_Size - 1;
          this->m_vecComponentListeners[0].m_pElements = v23;
          if ( v24 > 0 )
            _V_memmove(dest: &v23[m_Size + 1], src: &v23[m_Size], count: 4 * v24);
          v25 = &this->m_vecComponentListeners[0].m_Memory.m_pMemory[m_Size];
          if ( v25 != nullptr )
            *v25 = pAchievement;
          v4 = this;
        }
        if ( pAchievement->IsActive(this: pAchievement) )
          pAchievement->ListenForEvents(this: pAchievement);
LABEL_34:
        iAchievement = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                         this: &v4->m_mapAchievement[0].m_Tree,
                         i: iAchievement);
        if ( iAchievement == 0xFFFF )
          break;
        Inorder = iAchievement;
      }
    }
    v4->m_flLevelInitTime[0] = *(float *)(gpGlobals.m_Index + 12);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002C10
// Name: public: virtual void CAchievementMgr::LevelShutdownPreEntity(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::LevelShutdownPreEntity(CAchievementMgr *this)
{
  int i; // esi
  CBaseAchievement *elem; // edi
  ISteamUserStats *m_pSteamUserStats; // ecx

  for ( i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapAchievement[0].m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_mapAchievement[0].m_Tree,
              i) )
  {
    elem = this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
    if ( elem->m_bRegisteredForEvents )
    {
      if ( gameeventmanager != nullptr )
        gameeventmanager->RemoveListener(this: gameeventmanager, a2: elem);
      elem->m_bRegisteredForEvents = false;
    }
  }
  if ( this != (CAchievementMgr *)-564 && !this->m_bReadingFromTitleData )
    CAchievementMgr::SaveGlobalState(this);
  m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
  if ( m_pSteamUserStats != nullptr )
  {
    m_pSteamUserStats->StoreStats(this: m_pSteamUserStats);
    this->m_flTimeLastUpload = _Plat_FloatTime();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002CB0
// Name: public: class CBaseAchievement __near * CAchievementMgr::GetAchievementByID(int,int)
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__thiscall CAchievementMgr::GetAchievementByID(
        CAchievementMgr *this,
        int iAchievementID,
        int nUserSlot)
{
  char *v3; // esi
  unsigned __int16 v4; // ax
  CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = iAchievementID;
  v3 = (char *)this + 28 * nUserSlot;
  v4 = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v3 + 100),
         &search);
  if ( v4 == 0xFFFF )
    return nullptr;
  else
    return *(CBaseAchievement **)(*((_DWORD *)v3 + 26) + 16 * v4 + 12);
}

//------------------------------------------------------------------------------
// Address: 0x10002D00
// Name: public: class CBaseAchievement __near * CAchievementMgr::GetAchievementByName(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__thiscall CAchievementMgr::GetAchievementByName(
        CAchievementMgr *this,
        const char *pchName,
        int nUserSlot)
{
  char *v3; // edi
  int v4; // ebx
  int *v5; // eax
  int v6; // esi
  const char *v7; // eax

  v3 = (char *)this + 28 * nUserSlot;
  v4 = 0;
  if ( *((_WORD *)v3 + 54) == 0 )
    return nullptr;
  while ( 1 )
  {
    if ( (unsigned __int16)v4 < *((int *)v3 + 27) && (unsigned __int16)v4 <= *((_WORD *)v3 + 61) )
    {
      if ( (`CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
          & 1) == 0 )
      {
        `CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
        `CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
        dword_105F7628 = 0x1FFFF;
      }
      v5 = (_WORD)v4 == 0xFFFF
         ? &`CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel
         : (int *)(*((_DWORD *)v3 + 26) + 16 * (unsigned __int16)v4);
      if ( *(_WORD *)v5 != (_WORD)v4 )
      {
        v6 = *(_DWORD *)(*((_DWORD *)v3 + 26) + 16 * (unsigned __int16)v4 + 12);
        if ( v6 != 0 )
        {
          v7 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)(v6 + 12) + 4))(a1: v6 + 12);
          if ( _V_stricmp(s1: pchName, s2: v7) == 0 )
            break;
        }
      }
    }
    if ( ++v4 >= *((unsigned __int16 *)v3 + 54) )
      return nullptr;
  }
  return (CBaseAchievement *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x10002DE0
// Name: public: bool CAchievementMgr::HasAchieved(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAchievementMgr::HasAchieved(CAchievementMgr *this, const char *pchName, int nUserSlot)
{
  CBaseAchievement *AchievementByName; // eax

  AchievementByName = CAchievementMgr::GetAchievementByName(this, pchName, nUserSlot);
  return AchievementByName != nullptr && AchievementByName->IsAchieved(this: &AchievementByName->IAchievement);
}

//------------------------------------------------------------------------------
// Address: 0x10002E10
// Name: public: void CAchievementMgr::ClearAchievements(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::ClearAchievements(CAchievementMgr *this, int nUserSlot)
{
  char *v2; // esi
  ISteamUserStats_vtbl *Inorder; // edi
  ISteamUserStats *m_pSteamUserStats; // ebx
  int v5; // esi
  int v6; // eax
  bool v7; // zf
  char *v8; // [esp+8h] [ebp-4h]

  v2 = (char *)this + 28 * nUserSlot;
  v8 = v2;
  Inorder = (ISteamUserStats_vtbl *)CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v2 + 100));
  LOWORD(nUserSlot) = (_WORD)Inorder;
  if ( Inorder != (ISteamUserStats_vtbl *)0xFFFF )
  {
    while ( 1 )
    {
      m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
      v5 = *(_DWORD *)(*((_DWORD *)v2 + 26) + 16 * (unsigned __int16)Inorder + 12);
      if ( m_pSteamUserStats != nullptr )
      {
        Inorder = m_pSteamUserStats->__vftable;
        v6 = (*(int (__thiscall **)(int))(*(_DWORD *)(v5 + 12) + 4))(a1: v5 + 12);
        Inorder->ClearAchievement(this: m_pSteamUserStats, a2: (const char *)v6);
        LOWORD(Inorder) = nUserSlot;
      }
      v7 = (*(_BYTE *)(v5 + 24) & 0x20) == 0;
      *(_BYTE *)(v5 + 92) = 0;
      *(_DWORD *)(v5 + 100) = 0;
      if ( !v7 )
        CBaseAchievement::SetComponentBits(this: (CBaseAchievement *)v5, iComponentBits: 0);
      v7 = *(_BYTE *)(v5 + 8) == 0;
      *(_DWORD *)(v5 + 104) = 0;
      if ( !v7 )
      {
        if ( gameeventmanager != nullptr )
          gameeventmanager->RemoveListener(this: gameeventmanager, a2: (IGameEventListener2 *)v5);
        *(_BYTE *)(v5 + 8) = 0;
      }
      if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 40))(a1: v5) != 0 )
        (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 16))(a1: v5);
      nUserSlot = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v8 + 100),
                    i: (unsigned __int16)Inorder);
      if ( nUserSlot == 0xFFFF )
        break;
      LOWORD(Inorder) = nUserSlot;
      v2 = v8;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002F10
// Name: private: virtual void CAchievementMgr::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::FireGameEvent(CAchievementMgr *this, IGameEvent *event)
{
  int v4; // edi
  IVEngineClient_vtbl *v5; // edi
  int v6; // eax
  int v7; // eax
  C_BaseEntity *BaseEntity; // eax
  IGameEvent_vtbl *v9; // edx
  IVEngineClient_vtbl *v10; // edi
  int v11; // eax
  int v12; // eax
  C_BasePlayer *v13; // eax
  C_BasePlayer *LocalPlayer; // eax
  char *v15; // ebx
  int j; // esi
  int v17; // ecx
  int v18; // eax
  int i; // esi
  char cmdLine[80]; // [esp+Ch] [ebp-54h] BYREF
  C_BaseEntity *pVictim; // [esp+5Ch] [ebp-4h]
  const char *name; // [esp+68h] [ebp+8h]
  CClientEntityList *namea; // [esp+68h] [ebp+8h]
  CClientEntityList *nameb; // [esp+68h] [ebp+8h]

  v4 = event->GetInt(this: event, a2: "splitscreenplayer", a3: 0);
  name = event->GetName(this: event);
  if ( _V_strcmp(s1: name, s2: "entity_killed") != 0 && _V_strcmp(s1: name, s2: "game_init") != 0 )
  {
    if ( _V_strcmp(s1: name, s2: "player_death") != 0 )
    {
      if ( _V_strcmp(s1: name, s2: "localplayer_changeclass") != 0 )
      {
        if ( _V_strcmp(s1: name, s2: "localplayer_changeteam") != 0 )
        {
          if ( _V_strcmp(s1: name, s2: "teamplay_round_start") != 0 )
          {
            if ( _V_strcmp(s1: name, s2: "teamplay_round_win") != 0 )
            {
              if ( _V_strcmp(s1: name, s2: "player_stats_updated") != 0 )
              {
                if ( _V_strcmp(s1: name, s2: "read_game_titledata") != 0
                  && _V_strcmp(s1: name, s2: "write_game_titledata") != 0 )
                {
                  if ( _V_strcmp(s1: name, s2: "reset_game_titledata") != 0 )
                  {
                    if ( _V_strcmp(s1: name, s2: "write_profile_data") != 0 )
                    {
                      _V_strcmp(s1: name, s2: "achievement_write_failed");
                    }
                    else
                    {
                      for ( i = 0; i < 4; ++i )
                      {
                        V_snprintf(pDest: cmdLine, maxLen: 80, pFormat: "host_writeconfig_ss %d", i);
                        engine->ClientCmd_Unrestricted(this: engine, a2: cmdLine);
                      }
                    }
                  }
                  else
                  {
                    v18 = event->GetInt(this: event, a2: "controllerId", a3: 0);
                    CAchievementMgr::ClearAchievements(this: (CAchievementMgr *)((char *)this - 12), nUserSlot: v18);
                  }
                }
                else
                {
                  event->GetInt(this: event, a2: "controllerId", a3: 0);
                }
              }
              else
              {
                v15 = (char *)this + 28 * v4;
                for ( j = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v15 + 88));
                      j != 0xFFFF;
                      j = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                            this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v15 + 88),
                            i: j) )
                {
                  v17 = *(_DWORD *)(*((_DWORD *)v15 + 23) + 16 * (unsigned __int16)j + 12);
                  (*(void (__thiscall **)(int, int))(*(_DWORD *)v17 + 28))(a1: v17, a2: v4);
                }
              }
            }
            else if ( !event->GetBool(this: event, a2: "full_round", a3: true) )
            {
              this->m_flLevelInitTime[v4] = this->m_flLevelInitTime[v4] + 1.0;
            }
          }
          else if ( event->GetBool(this: event, a2: "full_reset", a3: false) )
          {
            this->m_flLevelInitTime[v4] = 0.0;
          }
        }
        else
        {
          LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
          if ( LocalPlayer != nullptr )
          {
            if ( LocalPlayer->GetTeamNumber(this: LocalPlayer) <= 1 )
            {
              *((_DWORD *)&this->m_vecThinkListeners.m_pElements + v4) = 0;
            }
            else if ( *((float *)&this->m_vecThinkListeners.m_pElements + v4) == 0.0 )
            {
              *((float *)&this->m_vecThinkListeners.m_pElements + v4) = *(float *)(gpGlobals.m_Index + 12);
            }
          }
        }
      }
      else
      {
        *((float *)&this->m_vecThinkListeners.m_Size + v4) = *(float *)(gpGlobals.m_Index + 12);
      }
    }
    else
    {
      v5 = engine->__vftable;
      namea = (CClientEntityList *)cl_entitylist.m_Index;
      v6 = event->GetInt(this: event, a2: "userid", a3: 0);
      v7 = v5->GetPlayerForUserID(this: engine, a2: v6);
      BaseEntity = CClientEntityList::GetBaseEntity(this: namea, entnum: v7);
      v9 = event->__vftable;
      v10 = engine->__vftable;
      pVictim = BaseEntity;
      nameb = (CClientEntityList *)cl_entitylist.m_Index;
      v11 = v9->GetInt(this: event, a2: "attacker", a3: 0);
      v12 = v10->GetPlayerForUserID(this: engine, a2: v11);
      v13 = (C_BasePlayer *)CClientEntityList::GetBaseEntity(this: nameb, entnum: v12);
      CAchievementMgr::OnKillEvent(
        this: (CAchievementMgr *)((char *)this - 12),
        pVictim,
        pAttacker: v13,
        pInflictor: nullptr,
        event);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003290
// Name: public: void CAchievementMgr::Steam_OnUserStatsStored(struct UserStatsStored_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::Steam_OnUserStatsStored(CAchievementMgr *this, UserStatsStored_t *pUserStatsStored)
{
  vgui::CTreeViewListControl *v3; // ecx
  int v4; // eax
  C_BasePlayer *LocalPlayer; // eax
  int UserID; // esi
  int v7; // eax
  int i; // esi
  CBaseAchievement *elem; // ebx
  char cmd[256]; // [esp+4h] [ebp-100h] BYREF

  if ( pUserStatsStored->m_eResult == k_EResultOK )
  {
    if ( this->m_AchievementsAwarded[0].m_Size > 0 )
    {
      if ( g_pGameRules != nullptr && g_pGameRules->IsMultiplayer(this: g_pGameRules) )
      {
        v4 = C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass(this: v3);
        LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: v4);
        if ( LocalPlayer != nullptr )
        {
          UserID = C_BasePlayer::GetUserID(this: LocalPlayer);
          v7 = *this->m_AchievementsAwarded[0].m_Memory.m_pMemory ^ UTIL_GetAchievementEventMask();
          V_snprintf(pDest: cmd, maxLen: 256, pFormat: "achievement_earned %d %d", v7, UserID ^ v7);
          engine->ClientCmd_Unrestricted(this: engine, a2: cmd);
        }
      }
      if ( this->m_AchievementsAwarded[0].m_Size - 1 > 0 )
        _V_memmove(
          dest: this->m_AchievementsAwarded[0].m_Memory.m_pMemory,
          src: this->m_AchievementsAwarded[0].m_Memory.m_pMemory + 1,
          count: 4 * (this->m_AchievementsAwarded[0].m_Size - 1));
      --this->m_AchievementsAwarded[0].m_Size;
    }
    for ( i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapAchievement[0].m_Tree);
          i != 0xFFFF;
          i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                this: &this->m_mapAchievement[0].m_Tree,
                i) )
    {
      elem = this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
      if ( !elem->IsAchieved(this: &elem->IAchievement) )
        elem->OnSteamUserStatsStored(this: elem);
    }
  }
  else
  {
    DevMsg(a1: "CAchievementMgr: Failed to upload stats to Steam, EResult %d!\n", pUserStatsStored->m_eResult);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100033D0
// Name: void MsgFunc_AchievementEvent(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl MsgFunc_AchievementEvent(CAchievementMgr *msg)
{
  int v2; // ecx
  unsigned int v3; // edx
  __int16 v4; // di
  unsigned int v5; // edx
  const unsigned int *v6; // eax
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int m_nDebugID; // edi
  int v10; // eax
  const unsigned int *v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  int v14; // eax
  int v15; // eax
  const unsigned int *v16; // eax
  const unsigned int *v17; // ecx
  const unsigned int *v18; // edx
  int v19; // ecx
  const unsigned int *v20; // eax
  int v21; // eax
  int v22; // eax
  const unsigned int *v23; // eax
  const unsigned int *v24; // ecx
  const unsigned int *v25; // edx
  int v26; // ecx
  const unsigned int *v27; // eax
  unsigned __int16 v28; // ax
  CBaseAchievement *elem; // esi
  CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t search; // [esp+Ch] [ebp-8h] BYREF
  CAchievementMgr *pAchievementMgr; // [esp+1Ch] [ebp+8h]

  v2 = *(_DWORD *)&msg->m_bRegisteredForEvents;
  if ( v2 < 16 )
  {
    v8 = *((const unsigned int **)&msg->IMatchEventsSink + 1);
    m_nDebugID = msg->m_nDebugID;
    v10 = 16 - v2;
    v11 = (const unsigned int *)msg->IMatchEventsSink::__vftable;
    if ( v11 == v8 )
    {
      *(_DWORD *)&msg->m_bRegisteredForEvents = 1;
      msg->m_nDebugID = 0;
      LOBYTE(msg->m_pNext) = 1;
    }
    else
    {
      if ( v11 > v8 )
      {
        LOBYTE(msg->m_pNext) = 1;
        msg->m_nDebugID = 0;
LABEL_15:
        if ( LOBYTE(msg->m_pNext) != 0 )
        {
          v4 = 0;
          goto LABEL_19;
        }
        v12 = msg->m_nDebugID;
        v13 = (v12 & CBitBuffer::s_nMaskTable[v10]) << *(_DWORD *)&msg->m_bRegisteredForEvents;
        *(_DWORD *)&msg->m_bRegisteredForEvents = 32 - v10;
        v4 = v13 | m_nDebugID;
        v5 = v12 >> v10;
        goto LABEL_18;
      }
      msg->m_nDebugID = *v11;
    }
    msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v11 + 1);
    goto LABEL_15;
  }
  v3 = msg->m_nDebugID;
  v4 = v3;
  *(_DWORD *)&msg->m_bRegisteredForEvents = v2 - 16;
  if ( v2 != 16 )
  {
    v5 = HIWORD(v3);
LABEL_18:
    msg->m_nDebugID = v5;
    goto LABEL_19;
  }
  v6 = (const unsigned int *)msg->IMatchEventsSink::__vftable;
  v7 = *((const unsigned int **)&msg->IMatchEventsSink + 1);
  *(_DWORD *)&msg->m_bRegisteredForEvents = 32;
  if ( v6 == v7 )
  {
    *(_DWORD *)&msg->m_bRegisteredForEvents = 1;
    msg->m_nDebugID = 0;
    msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v6 + 1);
  }
  else if ( v6 <= v7 )
  {
    msg->m_nDebugID = *v6;
    msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v6 + 1);
  }
  else
  {
    LOBYTE(msg->m_pNext) = 1;
    msg->m_nDebugID = 0;
  }
LABEL_19:
  search.elem = (CBaseAchievement *)v4;
  pAchievementMgr = CAchievementMgr::GetInstance();
  if ( pAchievementMgr == nullptr )
    return;
  v14 = *(_DWORD *)&msg->m_bRegisteredForEvents;
  if ( v14 >= 16 )
  {
    v15 = v14 - 16;
    *(_DWORD *)&msg->m_bRegisteredForEvents = v15;
    if ( v15 != 0 )
    {
      msg->m_nDebugID = HIWORD(msg->m_nDebugID);
    }
    else
    {
      v16 = (const unsigned int *)msg->IMatchEventsSink::__vftable;
      v17 = *((const unsigned int **)&msg->IMatchEventsSink + 1);
      *(_DWORD *)&msg->m_bRegisteredForEvents = 32;
      if ( v16 == v17 )
      {
        *(_DWORD *)&msg->m_bRegisteredForEvents = 1;
        msg->m_nDebugID = 0;
        msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v16 + 1);
      }
      else if ( v16 <= v17 )
      {
        msg->m_nDebugID = *v16;
        msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v16 + 1);
      }
      else
      {
        LOBYTE(msg->m_pNext) = 1;
        msg->m_nDebugID = 0;
      }
    }
    goto LABEL_36;
  }
  v18 = *((const unsigned int **)&msg->IMatchEventsSink + 1);
  v19 = 16 - v14;
  v20 = (const unsigned int *)msg->IMatchEventsSink::__vftable;
  if ( v20 == v18 )
  {
    *(_DWORD *)&msg->m_bRegisteredForEvents = 1;
    msg->m_nDebugID = 0;
    LOBYTE(msg->m_pNext) = 1;
  }
  else
  {
    if ( v20 > v18 )
    {
      LOBYTE(msg->m_pNext) = 1;
      msg->m_nDebugID = 0;
      goto LABEL_34;
    }
    msg->m_nDebugID = *v20;
  }
  msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v20 + 1);
LABEL_34:
  if ( LOBYTE(msg->m_pNext) == 0 )
  {
    msg->m_nDebugID = (unsigned int)msg->m_nDebugID >> v19;
    *(_DWORD *)&msg->m_bRegisteredForEvents = 32 - v19;
  }
LABEL_36:
  v21 = *(_DWORD *)&msg->m_bRegisteredForEvents;
  if ( v21 < 16 )
  {
    v25 = *((const unsigned int **)&msg->IMatchEventsSink + 1);
    v26 = 16 - v21;
    v27 = (const unsigned int *)msg->IMatchEventsSink::__vftable;
    if ( v27 == v25 )
    {
      *(_DWORD *)&msg->m_bRegisteredForEvents = 1;
      msg->m_nDebugID = 0;
      LOBYTE(msg->m_pNext) = 1;
    }
    else
    {
      if ( v27 > v25 )
      {
        LOBYTE(msg->m_pNext) = 1;
        msg->m_nDebugID = 0;
        goto LABEL_50;
      }
      msg->m_nDebugID = *v27;
    }
    msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v27 + 1);
LABEL_50:
    if ( LOBYTE(msg->m_pNext) == 0 )
    {
      msg->m_nDebugID = (unsigned int)msg->m_nDebugID >> v26;
      *(_DWORD *)&msg->m_bRegisteredForEvents = 32 - v26;
    }
    goto LABEL_52;
  }
  v22 = v21 - 16;
  *(_DWORD *)&msg->m_bRegisteredForEvents = v22;
  if ( v22 != 0 )
  {
    msg->m_nDebugID = HIWORD(msg->m_nDebugID);
  }
  else
  {
    v23 = (const unsigned int *)msg->IMatchEventsSink::__vftable;
    v24 = *((const unsigned int **)&msg->IMatchEventsSink + 1);
    *(_DWORD *)&msg->m_bRegisteredForEvents = 32;
    if ( v23 == v24 )
    {
      *(_DWORD *)&msg->m_bRegisteredForEvents = 1;
      msg->m_nDebugID = 0;
      msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v23 + 1);
    }
    else if ( v23 <= v24 )
    {
      msg->m_nDebugID = *v23;
      msg->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)(v23 + 1);
    }
    else
    {
      LOBYTE(msg->m_pNext) = 1;
      msg->m_nDebugID = 0;
    }
  }
LABEL_52:
  search.key = (int)search.elem;
  v28 = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
          this: &pAchievementMgr->m_mapAchievement[0].m_Tree,
          &search);
  if ( v28 != 0xFFFF )
  {
    elem = pAchievementMgr->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[v28].m_Data.elem;
    if ( elem != nullptr && !elem->IsAchieved(this: &elem->IAchievement) )
      CBaseAchievement::IncrementCount(this: elem, iOptIncrement: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003650
// Name: private: void CAchievementMgr::ClearAchievementData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::ClearAchievementData(CAchievementMgr *this, int nUserSlot)
{
  char *v2; // esi
  int v3; // edi
  int *v4; // eax
  int v5; // ecx

  v2 = (char *)this + 28 * nUserSlot;
  v3 = 0;
  if ( *((_WORD *)v2 + 54) != 0 )
  {
    do
    {
      if ( (unsigned __int16)v3 < *((int *)v2 + 27) && (unsigned __int16)v3 <= *((_WORD *)v2 + 61) )
      {
        if ( (`CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard'
            & 1) == 0 )
        {
          `CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::`local static guard' |= 1u;
          `CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel = -1;
          dword_105F7628 = 0x1FFFF;
        }
        if ( (_WORD)v3 == 0xFFFF )
          v4 = &`CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Links'::`2'::s_Sentinel;
        else
          v4 = (int *)(*((_DWORD *)v2 + 26) + 16 * (unsigned __int16)v3);
        if ( *(_WORD *)v4 != (_WORD)v3 )
        {
          v5 = *(_DWORD *)(*((_DWORD *)v2 + 26) + 16 * (unsigned __int16)v3 + 12);
          (*(void (__thiscall **)(int))(*(_DWORD *)v5 + 80))(a1: v5);
        }
      }
      ++v3;
    }
    while ( v3 < *((unsigned __int16 *)v2 + 54) );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003700
// Name: public: virtual bool CAchievementMgr::Init(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAchievementMgr::Init(CAchievementMgr *this)
{
  IVEngineClient_vtbl *v1; // esi
  IAchievementMgr *InstanceInterface; // eax
  IMatchEventsSink *v4; // esi
  IMatchEventsSubscription *v5; // eax

  v1 = engine->__vftable;
  InstanceInterface = CAchievementMgr::GetInstanceInterface();
  v1->SetAchievementMgr(this: engine, a2: InstanceInterface);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(this: gameeventmanager, a2: &this->CGameEventListener, a3: "player_death", a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "player_stats_updated",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "achievement_write_failed",
    a4: false);
  CUserMessages::HookMessage(this: usermessages, name: "AchievementEvent", hook: MsgFunc_AchievementEvent);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "read_game_titledata",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "write_game_titledata",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "reset_game_titledata",
    a4: false);
  this->m_bRegisteredForEvents = true;
  gameeventmanager->AddListener(
    this: gameeventmanager,
    a2: &this->CGameEventListener,
    a3: "write_profile_data",
    a4: false);
  if ( this != nullptr )
    v4 = &this->IMatchEventsSink;
  else
    v4 = nullptr;
  v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v5->Subscribe(this: v5, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10003810
// Name: public: void CAchievementMgr::AwardAchievement(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::AwardAchievement(CAchievementMgr *this, vgui::TreeNode *iAchievementID, int nUserSlot)
{
  CAchievementMgr *v3; // edi
  C_BasePlayer *LocalPlayer; // esi
  char *v6; // esi
  unsigned __int16 v7; // ax
  int v8; // esi
  char v9; // al
  int v10; // edx
  const char *v11; // eax
  const char *v12; // eax
  void (__thiscall *v13)(int); // eax
  CBaseAchievement **v14; // eax
  IGameEvent *v15; // esi
  int v16; // eax
  int v17; // esi
  const char *v18; // eax
  int (__thiscall *v19)(int); // edx
  int v20; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *v22; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v25; // eax
  vgui::TreeNode **v26; // edi
  int v27; // eax
  CUtlMemory<vgui::TreeNode *,int> *v28; // esi
  int v29; // edi
  vgui::TreeNode **v30; // ecx
  int v31; // eax
  vgui::TreeNode **v32; // edi
  CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t search; // [esp+8h] [ebp-Ch] BYREF
  CAchievementMgr *v34; // [esp+10h] [ebp-4h]
  int nUserSlota; // [esp+20h] [ebp+Ch]
  CBaseAchievement **nUserSlotb; // [esp+20h] [ebp+Ch]

  v3 = this;
  v34 = this;
  if ( CAchievementMgr::IsAchievementAllowedInGame(this, (int)iAchievementID) != 0 )
  {
    LocalPlayer = C_BasePlayer::GetLocalPlayer(nSlot: -1);
    if ( (LocalPlayer == nullptr || !LocalPlayer->IsPlayer(this: LocalPlayer) || !LocalPlayer[1].m_bReadyToDraw)
      && !C_CSGameRules::IsPlayingFreestyle(this: (C_CSGameRules *)g_pGameRules) )
    {
      search.key = (int)iAchievementID;
      v6 = (char *)v3 + 28 * nUserSlot;
      v7 = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
             this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v6 + 100),
             &search);
      if ( v7 != 0xFFFF )
      {
        v8 = *(_DWORD *)(*((_DWORD *)v6 + 26) + 16 * v7 + 12);
        if ( v8 != 0 )
        {
          v9 = CAchievementMgr::CheckAchievementsEnabled(this: v3);
          v10 = *(_DWORD *)(v8 + 12);
          if ( v9 != 0 )
          {
            nUserSlota = v8 + 12;
            if ( (*(unsigned __int8 (**)(void))(v10 + 20))() != 0 )
            {
              if ( cc_achievement_debug.m_pParent != nullptr && cc_achievement_debug.m_pParent->m_Value.m_nValue > 0 )
              {
                v12 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)nUserSlota + 4))(a1: nUserSlota);
                _Msg(a1: "Achievement award called but already achieved: %s\n", v12);
              }
            }
            else
            {
              v13 = *(void (__thiscall **)(int))(*(_DWORD *)v8 + 56);
              *(_BYTE *)(v8 + 92) = 1;
              v13(a1: v8);
              v14 = (CBaseAchievement **)gameeventmanager->CreateEventA(
                                           this: gameeventmanager,
                                           a2: "achievement_earned_local",
                                           a3: 1,
                                           a4: 0);
              v15 = (IGameEvent *)v14;
              if ( v14 != nullptr )
              {
                search.elem = *v14;
                v16 = (**(int (__thiscall ***)(int))nUserSlota)(a1: nUserSlota);
                (*(void (__thiscall **)(IGameEvent *, const char *, int))&search.elem->m_bHideUntilAchieved)(
                  a1: v15,
                  a2: "achievement",
                  a3: v16);
                v15->SetInt(this: v15, a2: "splitscreenplayer", a3: nUserSlot);
                gameeventmanager->FireEventClientSide(this: gameeventmanager, a2: v15);
              }
              if ( cc_achievement_debug.m_pParent != nullptr && cc_achievement_debug.m_pParent->m_Value.m_nValue > 0 )
              {
                v17 = nUserSlota;
                v18 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)nUserSlota + 4))(a1: nUserSlota);
                _Msg(a1: "Achievement awarded: %s\n", v18);
              }
              else
              {
                v17 = nUserSlota;
              }
              v3->m_bDirty[nUserSlot] = true;
              if ( steamapicontext->m_pSteamUserStats != nullptr )
              {
                CVProfile::EnterScope(
                  this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
                  a2: "AwardAchievement",
                  a3: 0,
                  a4: "Steam",
                  a5: false,
                  a6: 4);
                v19 = *(int (__thiscall **)(int))(*(_DWORD *)v17 + 4);
                nUserSlotb = (CBaseAchievement **)steamapicontext->m_pSteamUserStats;
                search.elem = *nUserSlotb;
                v20 = v19(a1: v17);
                if ( ((unsigned __int8 (__thiscall *)(CBaseAchievement **, int))search.elem->m_iGoal)(
                       a1: nUserSlotb,
                       a2: v20) != 0 )
                {
                  CAchievementMgr::UploadUserData(this: v3, nUserSlot);
                  m_nAllocationCount = v3->m_AchievementsAwarded[nUserSlot].m_Memory.m_nAllocationCount;
                  v22 = (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_AchievementsAwarded[nUserSlot];
                  m_Size = v3->m_AchievementsAwarded[nUserSlot].m_Size;
                  if ( m_Size + 1 > m_nAllocationCount )
                    CUtlMemory<CChoreoActor *,int>::Grow(this: v22, num: m_Size - m_nAllocationCount + 1);
                  ++v22[1].m_pMemory;
                  m_pMemory = v22->m_pMemory;
                  v25 = (int)v22[1].m_pMemory - m_Size - 1;
                  v22[1].m_nAllocationCount = (int)v22->m_pMemory;
                  if ( v25 > 0 )
                    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v25);
                  v26 = &v22->m_pMemory[m_Size];
                  if ( v26 != nullptr )
                    *v26 = iAchievementID;
                  v3 = v34;
                }
                CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
              }
              CAchievementMgr::SaveGlobalStateIfDirty(this: v3);
              v27 = v3->m_AchievementsAwardedDuringCurrentGame[nUserSlot].m_Memory.m_nAllocationCount;
              v28 = (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_AchievementsAwardedDuringCurrentGame[nUserSlot];
              v29 = v3->m_AchievementsAwardedDuringCurrentGame[nUserSlot].m_Size;
              if ( v29 + 1 > v27 )
                CUtlMemory<CChoreoActor *,int>::Grow(this: v28, num: v29 - v27 + 1);
              ++v28[1].m_pMemory;
              v30 = v28->m_pMemory;
              v31 = (int)v28[1].m_pMemory - v29 - 1;
              v28[1].m_nAllocationCount = (int)v28->m_pMemory;
              if ( v31 > 0 )
                _V_memmove(dest: &v30[v29 + 1], src: &v30[v29], count: 4 * v31);
              v32 = &v28->m_pMemory[v29];
              if ( v32 != nullptr )
                *v32 = iAchievementID;
            }
          }
          else
          {
            v11 = (const char *)(*(int (__thiscall **)(int))(v10 + 4))(a1: v8 + 12);
            _Msg(a1: "Achievements disabled, ignoring achievement unlock for %s\n", v11);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003B00
// Name: public: CAchievementMgr::CAchievementMgr(void)
// Source: json
//------------------------------------------------------------------------------
CAchievementMgr *__thiscall CAchievementMgr::CAchievementMgr(CAchievementMgr *this)
{
  UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edx
  __int128 v4; // [esp-10h] [ebp-28h]

  CAutoGameSystemPerFrame::CAutoGameSystemPerFrame(this, name: "CAchievementMgr");
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 42;
  this->m_bRegisteredForEvents = false;
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable = (CAchievementMgr_vtbl *)&CAchievementMgr::`vftable'{for `CAutoGameSystemPerFrame'};
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CAchievementMgr::`vftable'{for `CGameEventListener'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CAchievementMgr::`vftable'{for `IMatchEventsSink'};
  *(_QWORD *)&this->m_CallbackUserStatsStored.m_Func = (unsigned int)CAchievementMgr::Steam_OnUserStatsStored;
  this->m_CallbackUserStatsStored.m_nCallbackFlags = 0;
  this->m_CallbackUserStatsStored.m_iCallback = 0;
  this->m_CallbackUserStatsStored.__vftable = (CCallback<CAchievementMgr,UserStatsStored_t,0>_vtbl *)&CCallback<CAchievementMgr,UserStatsStored_t,0>::`vftable';
  this->m_CallbackUserStatsStored.m_pObj = this;
  *((_QWORD *)&this->m_CallbackUserStatsStored.m_Func + 1) = 0;
  if ( CAchievementMgr::Steam_OnUserStatsStored != nullptr )
  {
    *(_QWORD *)&v4 = (unsigned int)CAchievementMgr::Steam_OnUserStatsStored;
    *((_QWORD *)&v4 + 1) = 0;
    CCallback<CAchievementMgr,UserStatsStored_t,0>::Register(
      this: &this->m_CallbackUserStatsStored,
      pObj: this,
      func: v4);
  }
  this->m_mapAchievement[0].m_Tree.m_LessFunc.m_LessFunc = nullptr;
  this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapAchievement[0].m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapAchievement[0].m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapAchievement[0].m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapAchievement[0].m_Tree.m_FirstFree = -1;
  this->m_mapAchievement[0].m_Tree.m_pElements = m_pMemory;
  this->m_vecAchievement[0].m_Memory.m_pMemory = nullptr;
  this->m_vecAchievement[0].m_Memory.m_nAllocationCount = 0;
  this->m_vecAchievement[0].m_Memory.m_nGrowSize = 0;
  this->m_vecAchievement[0].m_Size = 0;
  this->m_vecAchievement[0].m_pElements = nullptr;
  this->m_vecAward[0].m_Memory.m_pMemory = nullptr;
  this->m_vecAward[0].m_Memory.m_nAllocationCount = 0;
  this->m_vecAward[0].m_Memory.m_nGrowSize = 0;
  this->m_vecAward[0].m_Size = 0;
  this->m_vecAward[0].m_pElements = nullptr;
  this->m_vecKillEventListeners[0].m_Memory.m_pMemory = nullptr;
  this->m_vecKillEventListeners[0].m_Memory.m_nAllocationCount = 0;
  this->m_vecKillEventListeners[0].m_Memory.m_nGrowSize = 0;
  this->m_vecKillEventListeners[0].m_Size = 0;
  this->m_vecKillEventListeners[0].m_pElements = nullptr;
  this->m_vecMapEventListeners[0].m_Memory.m_pMemory = nullptr;
  this->m_vecMapEventListeners[0].m_Memory.m_nAllocationCount = 0;
  this->m_vecMapEventListeners[0].m_Memory.m_nGrowSize = 0;
  this->m_vecMapEventListeners[0].m_Size = 0;
  this->m_vecMapEventListeners[0].m_pElements = nullptr;
  this->m_vecComponentListeners[0].m_Memory.m_pMemory = nullptr;
  this->m_vecComponentListeners[0].m_Memory.m_nAllocationCount = 0;
  this->m_vecComponentListeners[0].m_Memory.m_nGrowSize = 0;
  this->m_vecComponentListeners[0].m_Size = 0;
  this->m_vecComponentListeners[0].m_pElements = nullptr;
  this->m_vecAchievementInOrder[0].m_Memory.m_pMemory = nullptr;
  this->m_vecAchievementInOrder[0].m_Memory.m_nAllocationCount = 0;
  this->m_vecAchievementInOrder[0].m_Memory.m_nGrowSize = 0;
  this->m_vecAchievementInOrder[0].m_Size = 0;
  this->m_vecAchievementInOrder[0].m_pElements = nullptr;
  this->m_vecAwardInOrder[0].m_Memory.m_pMemory = nullptr;
  this->m_vecAwardInOrder[0].m_Memory.m_nAllocationCount = 0;
  this->m_vecAwardInOrder[0].m_Memory.m_nGrowSize = 0;
  this->m_vecAwardInOrder[0].m_Size = 0;
  this->m_vecAwardInOrder[0].m_pElements = nullptr;
  this->m_vecThinkListeners.m_Memory.m_pMemory = nullptr;
  this->m_vecThinkListeners.m_Memory.m_nAllocationCount = 0;
  this->m_vecThinkListeners.m_Memory.m_nGrowSize = 0;
  this->m_vecThinkListeners.m_Size = 0;
  this->m_vecThinkListeners.m_pElements = nullptr;
  this->m_AchievementsAwarded[0].m_Memory.m_pMemory = nullptr;
  this->m_AchievementsAwarded[0].m_Memory.m_nAllocationCount = 0;
  this->m_AchievementsAwarded[0].m_Memory.m_nGrowSize = 0;
  this->m_AchievementsAwarded[0].m_Size = 0;
  this->m_AchievementsAwarded[0].m_pElements = nullptr;
  this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_pMemory = nullptr;
  this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_nAllocationCount = 0;
  this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_nGrowSize = 0;
  this->m_AchievementsAwardedDuringCurrentGame[0].m_Size = 0;
  this->m_AchievementsAwardedDuringCurrentGame[0].m_pElements = nullptr;
  if ( this->m_mapAchievement[0].m_Tree.m_LessFunc.m_LessFunc == nullptr )
    this->m_mapAchievement[0].m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))lessFunc;
  this->m_flLastClassChangeTime[0] = 0.0;
  this->m_flTeamplayStartTime[0] = 0.0;
  this->m_iMiniroundsCompleted[0] = 0.0;
  this->m_bDirty[0] = false;
  this->m_AchievementsAwarded[0].m_Size = 0;
  this->m_AchievementsAwardedDuringCurrentGame[0].m_Size = 0;
  this->m_bUserSlotActive[0] = false;
  this->m_szMap[0] = 0;
  this->m_bCheatsEverOn = false;
  this->m_flTimeLastUpload = 0.0;
  *(_WORD *)&this->m_bCheckSigninState = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003D60
// Name: public: virtual CAchievementMgr::~CAchievementMgr(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::~CAchievementMgr(CAchievementMgr *this)
{
  int *m_pMemory; // eax
  int *v3; // eax
  CBaseAchievement **v4; // eax
  CBaseAchievement **v5; // eax
  CBaseAchievement **v6; // eax
  CBaseAchievement **v7; // eax
  CBaseAchievement **v8; // eax
  CBaseAchievement **v9; // eax
  CBaseAchievement **v10; // eax
  bool v11; // zf

  this->m_AchievementsAwardedDuringCurrentGame[0].m_Size = 0;
  if ( this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_pMemory);
      this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_pMemory;
  this->m_AchievementsAwardedDuringCurrentGame[0].m_pElements = m_pMemory;
  if ( this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_AchievementsAwardedDuringCurrentGame[0].m_Memory.m_nAllocationCount = 0;
  }
  this->m_AchievementsAwarded[0].m_Size = 0;
  if ( this->m_AchievementsAwarded[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_AchievementsAwarded[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_AchievementsAwarded[0].m_Memory.m_pMemory);
      this->m_AchievementsAwarded[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_AchievementsAwarded[0].m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_AchievementsAwarded[0].m_Memory.m_pMemory;
  this->m_AchievementsAwarded[0].m_pElements = v3;
  if ( this->m_AchievementsAwarded[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( v3 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v3);
      this->m_AchievementsAwarded[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_AchievementsAwarded[0].m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>::~CUtlVector<VideoPanel *,CUtlMemory<VideoPanel *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&this->m_vecThinkListeners);
  this->m_vecAwardInOrder[0].m_Size = 0;
  if ( this->m_vecAwardInOrder[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecAwardInOrder[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecAwardInOrder[0].m_Memory.m_pMemory);
      this->m_vecAwardInOrder[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecAwardInOrder[0].m_Memory.m_nAllocationCount = 0;
  }
  v4 = this->m_vecAwardInOrder[0].m_Memory.m_pMemory;
  this->m_vecAwardInOrder[0].m_pElements = v4;
  if ( this->m_vecAwardInOrder[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( v4 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
      this->m_vecAwardInOrder[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecAwardInOrder[0].m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecAchievementInOrder[0].m_Size = 0;
  if ( this->m_vecAchievementInOrder[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecAchievementInOrder[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecAchievementInOrder[0].m_Memory.m_pMemory);
      this->m_vecAchievementInOrder[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecAchievementInOrder[0].m_Memory.m_nAllocationCount = 0;
  }
  v5 = this->m_vecAchievementInOrder[0].m_Memory.m_pMemory;
  this->m_vecAchievementInOrder[0].m_pElements = v5;
  if ( this->m_vecAchievementInOrder[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( v5 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5);
      this->m_vecAchievementInOrder[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecAchievementInOrder[0].m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecComponentListeners[0].m_Size = 0;
  if ( this->m_vecComponentListeners[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecComponentListeners[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecComponentListeners[0].m_Memory.m_pMemory);
      this->m_vecComponentListeners[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecComponentListeners[0].m_Memory.m_nAllocationCount = 0;
  }
  v6 = this->m_vecComponentListeners[0].m_Memory.m_pMemory;
  this->m_vecComponentListeners[0].m_pElements = v6;
  if ( this->m_vecComponentListeners[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( v6 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      this->m_vecComponentListeners[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecComponentListeners[0].m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecMapEventListeners[0].m_Size = 0;
  if ( this->m_vecMapEventListeners[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecMapEventListeners[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecMapEventListeners[0].m_Memory.m_pMemory);
      this->m_vecMapEventListeners[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecMapEventListeners[0].m_Memory.m_nAllocationCount = 0;
  }
  v7 = this->m_vecMapEventListeners[0].m_Memory.m_pMemory;
  this->m_vecMapEventListeners[0].m_pElements = v7;
  if ( this->m_vecMapEventListeners[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( v7 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7);
      this->m_vecMapEventListeners[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecMapEventListeners[0].m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecKillEventListeners[0].m_Size = 0;
  if ( this->m_vecKillEventListeners[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecKillEventListeners[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecKillEventListeners[0].m_Memory.m_pMemory);
      this->m_vecKillEventListeners[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecKillEventListeners[0].m_Memory.m_nAllocationCount = 0;
  }
  v8 = this->m_vecKillEventListeners[0].m_Memory.m_pMemory;
  this->m_vecKillEventListeners[0].m_pElements = v8;
  if ( this->m_vecKillEventListeners[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( v8 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v8);
      this->m_vecKillEventListeners[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecKillEventListeners[0].m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecAward[0].m_Size = 0;
  if ( this->m_vecAward[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecAward[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecAward[0].m_Memory.m_pMemory);
      this->m_vecAward[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecAward[0].m_Memory.m_nAllocationCount = 0;
  }
  v9 = this->m_vecAward[0].m_Memory.m_pMemory;
  this->m_vecAward[0].m_pElements = v9;
  if ( this->m_vecAward[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( v9 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v9);
      this->m_vecAward[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecAward[0].m_Memory.m_nAllocationCount = 0;
  }
  this->m_vecAchievement[0].m_Size = 0;
  if ( this->m_vecAchievement[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_vecAchievement[0].m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecAchievement[0].m_Memory.m_pMemory);
      this->m_vecAchievement[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecAchievement[0].m_Memory.m_nAllocationCount = 0;
  }
  v10 = this->m_vecAchievement[0].m_Memory.m_pMemory;
  this->m_vecAchievement[0].m_pElements = v10;
  if ( this->m_vecAchievement[0].m_Memory.m_nGrowSize >= 0 )
  {
    if ( v10 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v10);
      this->m_vecAchievement[0].m_Memory.m_pMemory = nullptr;
    }
    this->m_vecAchievement[0].m_Memory.m_nAllocationCount = 0;
  }
  CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapAchievement[0].m_Tree);
  this->m_mapAchievement[0].m_Tree.m_FirstFree = -1;
  if ( this->m_mapAchievement[0].m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory);
      this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_mapAchievement[0].m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  this->m_mapAchievement[0].m_Tree.m_LastAlloc.index = -1;
  if ( this->m_mapAchievement[0].m_Tree.m_Elements.m_nGrowSize >= 0 )
  {
    if ( this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory);
      this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory = nullptr;
    }
    this->m_mapAchievement[0].m_Tree.m_Elements.m_nAllocationCount = 0;
  }
  v11 = (this->m_CallbackUserStatsStored.m_nCallbackFlags & 1) == 0;
  this->m_CallbackUserStatsStored.__vftable = (CCallback<CAchievementMgr,UserStatsStored_t,0>_vtbl *)&CCallback<CAchievementMgr,UserStatsStored_t,0>::`vftable';
  if ( !v11 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackUserStatsStored);
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&CGameEventListener::`vftable';
  this->m_nDebugID = 13;
  if ( this->m_bRegisteredForEvents )
  {
    if ( gameeventmanager != nullptr )
      gameeventmanager->RemoveListener(this: gameeventmanager, a2: &this->CGameEventListener);
    this->m_bRegisteredForEvents = false;
  }
  this->CGameEventListener::IGameEventListener2::__vftable = (CGameEventListener_vtbl *)&IGameEventListener2::`vftable';
  IGameSystemPerFrame::~IGameSystemPerFrame(this);
}

//------------------------------------------------------------------------------
// Address: 0x10004200
// Name: public: virtual void CAchievementMgr::PostInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::PostInit(CAchievementMgr *this)
{
  CAchievementMgr *v1; // ebx
  const char *ModDirectory; // eax
  CBaseAchievementHelper *v3; // edi
  CBaseAchievement *v4; // esi
  void (__thiscall *Init)(CBaseAchievement *); // eax
  unsigned __int16 v6; // ax
  unsigned __int16 v7; // dx
  unsigned __int16 v8; // cx
  int v9; // esi
  UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *v10; // eax
  UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *m_pMemory; // eax
  int v12; // edx
  UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *v13; // ecx
  CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t *p_m_Data; // esi
  int m_Size; // edi
  int v16; // eax
  CBaseAchievement **v17; // ecx
  int v18; // eax
  CBaseAchievement **v19; // ecx
  int m_nAllocationCount; // eax
  CBaseAchievement **v21; // ecx
  int v22; // eax
  CAchievementMgr_vtbl **v23; // edi
  CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t insert; // [esp+Ch] [ebp-1Ch] BYREF
  const char *pGameDir; // [esp+14h] [ebp-14h]
  CAchievementMgr *p_elem; // [esp+18h] [ebp-10h]
  unsigned __int16 parent[2]; // [esp+1Ch] [ebp-Ch] BYREF
  int iter; // [esp+20h] [ebp-8h]
  bool leftchild; // [esp+27h] [ebp-1h] BYREF

  v1 = this;
  p_elem = this;
  ModDirectory = COM_GetModDirectory();
  v3 = CBaseAchievementHelper::s_pFirst;
  pGameDir = ModDirectory;
  for ( iter = (int)CBaseAchievementHelper::s_pFirst; v3 != nullptr; iter = (int)v3 )
  {
    v4 = v3->m_pfnCreate();
    Init = v4->Init;
    v4->m_pAchievementMgr = v1;
    Init(this: v4);
    v4->CalcProgressMsgIncrement(this: v4);
    v4->SetUserSlot(this: v4, a2: 0);
    if ( v4->m_pGameDirFilter != nullptr && _V_strcmp(s1: pGameDir, s2: v4->m_pGameDirFilter) != 0
      || v4->m_iAssetAwardID > 0 )
    {
      ((void (__thiscall *)(CBaseAchievement *, int))v4->dtr_IGameEventListener2)(a1: v4, a2: 1);
    }
    else
    {
      insert.key = v4->GetAchievementID(this: &v4->IAchievement);
      insert.elem = v4;
      *(_DWORD *)parent = 0xFFFF;
      leftchild = false;
      CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FindInsertionPosition(
        this: &v1->m_mapAchievement[0].m_Tree,
        &insert,
        parent,
        &leftchild);
      v6 = CUtlRBTree<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short,CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<IPhysicsObject *,CPhysCollide const *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NewNode(this: &v1->m_mapAchievement[0].m_Tree);
      v7 = parent[0];
      v8 = v6;
      v9 = v6;
      v10 = &v1->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[v9];
      v10->m_Right = -1;
      v10->m_Left = -1;
      v10->m_Parent = v7;
      v10->m_Tag = 0;
      if ( v7 == 0xFFFF )
      {
        v1->m_mapAchievement[0].m_Tree.m_Root = v8;
      }
      else
      {
        m_pMemory = v1->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory;
        v12 = v7;
        if ( leftchild )
          m_pMemory[v12].m_Left = v8;
        else
          m_pMemory[v12].m_Right = v8;
      }
      CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::InsertRebalance(
        this: &v1->m_mapAchievement[0].m_Tree,
        elem: v8);
      v13 = v1->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory;
      ++v1->m_mapAchievement[0].m_Tree.m_NumElements;
      v3 = (CBaseAchievementHelper *)iter;
      v1 = p_elem;
      p_m_Data = &v13[v9].m_Data;
      if ( p_m_Data != nullptr )
        *p_m_Data = insert;
    }
    v3 = v3->m_pNext;
  }
  for ( iter = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &v1->m_mapAchievement[0].m_Tree);
        iter != 0xFFFF;
        iter = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                 this: &v1->m_mapAchievement[0].m_Tree,
                 i: iter) )
  {
    p_elem = (CAchievementMgr *)&v1->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[(unsigned __int16)iter].m_Data.elem;
    if ( (int)p_elem->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable[2].Name > 0 )
    {
      m_Size = v1->m_vecAward[0].m_Size;
      m_nAllocationCount = v1->m_vecAward[0].m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)v1->m_vecAward,
          num: m_Size - m_nAllocationCount + 1);
      ++v1->m_vecAward[0].m_Size;
      v21 = v1->m_vecAward[0].m_Memory.m_pMemory;
      v22 = v1->m_vecAward[0].m_Size - m_Size - 1;
      v1->m_vecAward[0].m_pElements = v21;
      if ( v22 > 0 )
        _V_memmove(dest: &v21[m_Size + 1], src: &v21[m_Size], count: 4 * v22);
      v19 = v1->m_vecAward[0].m_Memory.m_pMemory;
    }
    else
    {
      m_Size = v1->m_vecAchievement[0].m_Size;
      v16 = v1->m_vecAchievement[0].m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > v16 )
        CUtlMemory<CChoreoActor *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)v1->m_vecAchievement,
          num: m_Size - v16 + 1);
      ++v1->m_vecAchievement[0].m_Size;
      v17 = v1->m_vecAchievement[0].m_Memory.m_pMemory;
      v18 = v1->m_vecAchievement[0].m_Size - m_Size - 1;
      v1->m_vecAchievement[0].m_pElements = v17;
      if ( v18 > 0 )
        _V_memmove(dest: &v17[m_Size + 1], src: &v17[m_Size], count: 4 * v18);
      v19 = v1->m_vecAchievement[0].m_Memory.m_pMemory;
    }
    v23 = (CAchievementMgr_vtbl **)&v19[m_Size];
    if ( v23 != nullptr )
      *v23 = p_elem->CAutoGameSystemPerFrame::CBaseGameSystemPerFrame::IGameSystemPerFrame::IGameSystem::__vftable;
  }
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::Sort(
    this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)v1->m_vecAchievement,
    pfnCompare: (int (__cdecl *)(vgui::CConsolePanel::CompletionItem *const *, vgui::CConsolePanel::CompletionItem *const *))AchievementIDCompare);
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::AddVectorToTail(
    this: v1->m_vecAchievementInOrder,
    src: v1->m_vecAchievement);
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::Sort(
    this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)v1->m_vecAchievementInOrder,
    pfnCompare: (int (__cdecl *)(vgui::CConsolePanel::CompletionItem *const *, vgui::CConsolePanel::CompletionItem *const *))AchievementOrderCompare);
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::AddVectorToTail(
    this: v1->m_vecAwardInOrder,
    src: v1->m_vecAward);
  CUtlVector<CBaseAchievement *,CUtlMemory<CBaseAchievement *,int>>::Sort(
    this: (CUtlVector<vgui::CConsolePanel::CompletionItem *,CUtlMemory<vgui::CConsolePanel::CompletionItem *,int> > *)v1->m_vecAwardInOrder,
    pfnCompare: (int (__cdecl *)(vgui::CConsolePanel::CompletionItem *const *, vgui::CConsolePanel::CompletionItem *const *))AchievementOrderCompare);
  CAchievementMgr::ClearAchievementData(this: v1, nUserSlot: 0);
  v1->m_bUserSlotActive[0] = true;
}

//------------------------------------------------------------------------------
// Address: 0x1011E190
// Name: void __near * MemAlloc_Alloc(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void *__cdecl MemAlloc_Alloc(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}

//------------------------------------------------------------------------------
// Address: 0x1011E1B0
// Name: __strdup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _strdup(char *string)
{
  unsigned int v1; // kr00_4
  unsigned __int8 *v2; // eax
  unsigned __int8 *v3; // esi

  v1 = strlen(string);
  v2 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v1 + 1);
  v3 = v2;
  if ( v2 != nullptr )
    memcpy(dst: v2, src: (unsigned __int8 *)string, count: v1 + 1);
  return (char *)v3;
}

// ============================================================
// Overlay from server (Missing functions)
// ============================================================
namespace server {

//------------------------------------------------------------------------------
// Address: 0x10001300
// Name: public: bool CAchievementMgr::IsAchievementAllowedInGame(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAchievementMgr::IsAchievementAllowedInGame(CAchievementMgr *this, int iAchievementID)
{
  char v2; // bl

  v2 = 0;
  if ( iAchievementID > 5037 )
  {
    switch ( iAchievementID )
    {
      case 6019:
      case 6020:
      case 6021:
      case 6022:
      case 6023:
      case 6024:
      case 6025:
      case 6029:
      case 6030:
      case 6031:
      case 6033:
      case 6034:
      case 6035:
      case 6036:
      case 6037:
      case 6038:
      case 6039:
      case 6040:
        goto $LN3;
      default:
        break;
    }
  }
  else
  {
    if ( iAchievementID != 5037 )
    {
      if ( iAchievementID > 3051 )
      {
        if ( iAchievementID < 5004 || iAchievementID > 5011 )
          goto LABEL_9;
      }
      else if ( iAchievementID < 3044 && (iAchievementID < 1014 || iAchievementID > 1015 && iAchievementID != 3030) )
      {
        goto LABEL_9;
      }
    }
$LN3:
    v2 = 1;
  }
LABEL_9:
  if ( CCSGameRules::IsPlayingGunGame(this: (CCSGameRules *)g_pGameRules) )
    return v2;
  else
    return v2 == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100013B0
// Name: public: void CAchievementMgr::AwardAchievement(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::AwardAchievement(CAchievementMgr *this, int iAchievementID, int nUserSlot)
{
  CAchievementMgr::IsAchievementAllowedInGame(this, iAchievementID);
}

//------------------------------------------------------------------------------
// Address: 0x100013C0
// Name: bool FStrEq(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl FStrEq(const char *sz1, const char *sz2)
{
  return sz1 == sz2 || _V_stricmp(s1: sz1, s2: sz2) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001410
// Name: public: class CStudioHdr __near * CBaseAnimating::GetModelPtr(void)
// Source: json
//------------------------------------------------------------------------------
CStudioHdr *__thiscall CBaseAnimating::GetModelPtr(CBaseAnimating *this)
{
  CStudioHdr *result; // eax

  if ( this->m_pStudioHdr == nullptr && CBaseEntity::GetModel(this) != nullptr )
    CBaseAnimating::LockStudioHdr(this);
  result = this->m_pStudioHdr;
  if ( result == nullptr || result->m_pStudioHdr == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001440
// Name: public: bool CAchievementMgr::CheckAchievementsEnabled(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CAchievementMgr::CheckAchievementsEnabled(CAchievementMgr *this)
{
  if ( cc_achievement_disable.m_pParent == nullptr || cc_achievement_disable.m_pParent->m_Value.m_nValue == 0 )
    _Msg(a1: "Achievements disabled: Steam not running.\n");
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10001460
// Name: public: char const __near * studiohdr_t::pszName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall studiohdr_t::pszName(studiohdr_t *this)
{
  int studiohdr2index; // eax
  int v2; // edx
  char *v3; // eax
  int v4; // ecx

  studiohdr2index = this->studiohdr2index;
  if ( studiohdr2index == 0 )
    return this->name;
  v2 = *(_DWORD *)&this->name[studiohdr2index + 8];
  v3 = (char *)this + studiohdr2index;
  if ( v2 == 0 || &v3[v2] == nullptr )
    return this->name;
  v4 = *((_DWORD *)v3 + 5);
  if ( v4 != 0 )
    return &v3[v4];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100014C0
// Name: public: void CAchievementMgr::SaveGlobalState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::SaveGlobalState(CAchievementMgr *this)
{
  IMatchSystem *v2; // eax
  int v3; // eax
  int v4; // ebx
  int i; // edi
  CBaseAchievement *v6; // ecx
  int j; // edi
  CBaseAchievement *v8; // ecx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CAchievementMgr::SaveGlobalState",
    a3: 0,
    a4: "Achievements",
    a5: false,
    a6: 4);
  v2 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
  v3 = v2->GetPlayerManager(this: v2);
  v4 = (*(int (__thiscall **)(int, _DWORD))(*(_DWORD *)v3 + 4))(a1: v3, a2: 0);
  if ( v4 != 0 )
  {
    for ( i = 0; i < this->m_vecAchievement[0].m_Size; ++i )
    {
      v6 = this->m_vecAchievement[0].m_Memory.m_pMemory[i];
      if ( v6 != nullptr )
        v6->WriteProgress(this: v6, a2: (IPlayerLocal *)v4);
    }
    for ( j = 0; j < this->m_vecAward[0].m_Size; ++j )
    {
      v8 = this->m_vecAward[0].m_Memory.m_pMemory[j];
      if ( v8 != nullptr )
        v8->WriteProgress(this: v8, a2: (IPlayerLocal *)v4);
    }
    this->m_bDirty[0] = false;
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
  else
  {
    CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001590
// Name: public: void CAchievementMgr::SaveGlobalStateIfDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::SaveGlobalStateIfDirty(CAchievementMgr *this)
{
  if ( this != (CAchievementMgr *)-564 && !this->m_bReadingFromTitleData )
    CAchievementMgr::SaveGlobalState(this);
}

//------------------------------------------------------------------------------
// Address: 0x100015B0
// Name: public: class IAchievement __near * CAchievementMgr::GetAchievementByIndex(int,int)
// Source: json
//------------------------------------------------------------------------------
IAchievement *__thiscall CAchievementMgr::GetAchievementByIndex(CAchievementMgr *this, int index, int nUserSlot)
{
  CBaseAchievement *v3; // eax

  v3 = this->m_vecAchievement[nUserSlot].m_Memory.m_pMemory[index];
  if ( v3 != nullptr )
    return &v3->IAchievement;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100016A0
// Name: public: int CAchievementMgr::GetAchievementCount(bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CAchievementMgr::GetAchievementCount(CAchievementMgr *this, bool bAssets)
{
  int m_NumElements; // esi
  __int64 v3; // rax
  UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short> *m_pMemory; // edi
  CBaseAchievement *elem; // ecx

  m_NumElements = this->m_mapAchievement[0].m_Tree.m_NumElements;
  v3 = 0;
  if ( this->m_mapAchievement[0].m_Tree.m_NumElements != 0 )
  {
    m_pMemory = this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory;
    while ( 1 )
    {
      elem = m_pMemory[WORD2(v3)].m_Data.elem;
      if ( bAssets )
        break;
      if ( elem->m_iAssetAwardID <= 0 )
        goto LABEL_7;
LABEL_8:
      ++HIDWORD(v3);
      if ( SHIDWORD(v3) >= m_NumElements )
        return v3;
    }
    if ( elem->m_iAssetAwardID <= 0 )
      goto LABEL_8;
LABEL_7:
    LODWORD(v3) = v3 + 1;
    goto LABEL_8;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001AB0
// Name: public: class CBaseAchievement __near * CAchievementMgr::GetAchievementByID(int,int)
// Source: json
//------------------------------------------------------------------------------
CBaseAchievement *__thiscall CAchievementMgr::GetAchievementByID(
        CAchievementMgr *this,
        int iAchievementID,
        int nUserSlot)
{
  char *v3; // esi
  unsigned __int16 v4; // ax
  CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = iAchievementID;
  v3 = (char *)this + 28 * nUserSlot;
  v4 = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: (CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(v3 + 100),
         &search);
  if ( v4 == 0xFFFF )
    return nullptr;
  else
    return *(CBaseAchievement **)(*((_DWORD *)v3 + 26) + 16 * v4 + 12);
}

//------------------------------------------------------------------------------
// Address: 0x10001B00
// Name: public: void CAchievementMgr::PreRestoreSavedGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::PreRestoreSavedGame(CAchievementMgr *this)
{
  int i; // esi
  CBaseAchievement *elem; // ecx

  for ( i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapAchievement[0].m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_mapAchievement[0].m_Tree,
              i) )
  {
    elem = this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
    elem->PreRestoreSavedGame(this: elem);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001B50
// Name: public: void CAchievementMgr::PostRestoreSavedGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAchievementMgr::PostRestoreSavedGame(CAchievementMgr *this)
{
  int i; // esi
  CBaseAchievement *elem; // ecx

  for ( i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapAchievement[0].m_Tree);
        i != 0xFFFF;
        i = CUtlRBTree<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short,CUtlMap<int,CBaseAchievement *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,CBaseAchievement *,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
              this: &this->m_mapAchievement[0].m_Tree,
              i) )
  {
    elem = this->m_mapAchievement[0].m_Tree.m_Elements.m_pMemory[(unsigned __int16)i].m_Data.elem;
    elem->PostRestoreSavedGame(this: elem);
  }
}

} // namespace server
