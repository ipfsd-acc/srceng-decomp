// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/player.cpp
// Functions: 54
// ============================================================

#include "matchmaking\player.h"

//------------------------------------------------------------------------------
// Address: 0x10005410
// Name: public: void CUtlMemory<unsigned __int64,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned __int64,int>::Grow(
        CUtlMemory<CThreadSafeMemoryPool::BlockSet_t,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CThreadSafeMemoryPool::BlockSet_t *m_pMemory; // edx
  unsigned int v7; // [esp-4h] [ebp-Ch]

  m_nGrowSize = this->m_nGrowSize;
  if ( m_nGrowSize >= 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    v5 = m_nAllocationCount + num;
    if ( m_nGrowSize != 0 )
    {
      m_nAllocationCount = m_nGrowSize * ((v5 - 1) / m_nGrowSize + 1);
    }
    else
    {
      if ( m_nAllocationCount == 0 )
        m_nAllocationCount = 4;
      if ( m_nAllocationCount >= v5 )
        goto LABEL_13;
      do
        m_nAllocationCount *= 2;
      while ( m_nAllocationCount < v5 );
    }
    if ( m_nAllocationCount < v5 )
    {
      if ( m_nAllocationCount != 0 || v5 > -1 )
      {
        do
          m_nAllocationCount = (v5 + m_nAllocationCount) / 2;
        while ( m_nAllocationCount < v5 );
      }
      else
      {
        m_nAllocationCount = -1;
      }
    }
LABEL_13:
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = m_nAllocationCount;
    v7 = 8 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CThreadSafeMemoryPool::BlockSet_t *)_g_pMemAlloc->Realloc_2(
                                                               this: _g_pMemAlloc,
                                                               a2: m_pMemory,
                                                               a3: v7);
    else
      this->m_pMemory = (CThreadSafeMemoryPool::BlockSet_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A000
// Name: public: bool CSteamID::IsValid(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamID::IsValid(CSteamID *this)
{
  int m_unAll64Bits_high; // esi
  unsigned int v2; // eax

  m_unAll64Bits_high = HIDWORD(this->m_steamid.m_unAll64Bits);
  v2 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  return v2 != 0
      && v2 < 0xB
      && m_unAll64Bits_high >> 24 > 0
      && m_unAll64Bits_high >> 24 < 6
      && (v2 != 1 || this->m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 1)
      && (v2 != 7 || this->m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000A060
// Name: public: virtual wchar_t const __near * PlayerFriend::GetRichPresence(void)
// Source: json
//------------------------------------------------------------------------------
wchar_t *__thiscall PlayerFriend::GetRichPresence(PlayerFriend *this)
{
  return this->m_wszRichPresence;
}

//------------------------------------------------------------------------------
// Address: 0x1000A070
// Name: public: virtual class KeyValues __near * PlayerFriend::GetGameDetails(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall PlayerFriend::GetGameDetails(PlayerFriend *this)
{
  return this->m_pDetails;
}

//------------------------------------------------------------------------------
// Address: 0x1000A080
// Name: public: virtual bool PlayerFriend::IsJoinable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall PlayerFriend::IsJoinable(PlayerFriend *this)
{
  return *(_DWORD *)this->m_xSessionID.ab != 0 || *(_DWORD *)&this->m_xSessionID.ab[4] != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A0A0
// Name: public: virtual void PlayerFriend::Join(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::Join(PlayerFriend *this)
{
  KeyValues *v2; // esi
  const char *String; // eax

  v2 = KeyValues::FromString(
         szName: "settings",
         szStringVal: " system {  network LIVE  }  options {  action joinsession  } ",
         ppEndOfParse: nullptr);
  if ( this->m_eSearchState == SEARCH_NONE )
  {
    String = KeyValues::GetString(this: this->m_pDetails, keyName: "system/network", defaultValue: "LIVE");
    KeyValues::SetString(this: v2, keyName: "system/network", value: String);
  }
  KeyValues::SetUint64(this: v2, keyName: "options/sessionid", value: *(_QWORD *)&this->m_xSessionID);
  g_pMatchFramework->MatchSession(this: g_pMatchFramework, a2: v2);
  if ( v2 != nullptr )
    KeyValues::deleteThis(this: v2);
}

//------------------------------------------------------------------------------
// Address: 0x1000A120
// Name: public: void PlayerFriend::SetFriendMark(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::SetFriendMark(PlayerFriend *this, unsigned int maskSetting)
{
  this->m_uFriendMark = maskSetting;
}

//------------------------------------------------------------------------------
// Address: 0x1000A130
// Name: public: unsigned int PlayerFriend::GetFriendMark(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall PlayerFriend::GetFriendMark(PlayerFriend *this)
{
  return this->m_uFriendMark;
}

//------------------------------------------------------------------------------
// Address: 0x1000A140
// Name: public: void PlayerFriend::SetIsStale(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::SetIsStale(PlayerFriend *this, bool bStale)
{
  this->m_bIsStale = bStale;
}

//------------------------------------------------------------------------------
// Address: 0x1000A150
// Name: public: bool PlayerFriend::GetIsStale(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall PlayerFriend::GetIsStale(PlayerFriend *this)
{
  return this->m_bIsStale;
}

//------------------------------------------------------------------------------
// Address: 0x1000A160
// Name: SetSteamStatWithPotentialOverride
// Source: json
//------------------------------------------------------------------------------
bool __cdecl SetSteamStatWithPotentialOverride(const char *szField, int iValue)
{
  ISteamUserStats *m_pSteamUserStats; // ecx

  m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
  return m_pSteamUserStats != nullptr && m_pSteamUserStats->SetStat_2(this: m_pSteamUserStats, a2: szField, a3: iValue);
}

//------------------------------------------------------------------------------
// Address: 0x1000A190
// Name: SetSteamStatWithPotentialOverride_0
// Source: json
//------------------------------------------------------------------------------
char __usercall SetSteamStatWithPotentialOverride_0@<al>(int a1@<xmm0>, const char *szField)
{
  ISteamUserStats *m_pSteamUserStats; // ecx

  m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
  if ( m_pSteamUserStats != nullptr )
    return ((int (__stdcall *)(const char *, int))m_pSteamUserStats->SetStat)(a1: szField, a2: a1);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A1C0
// Name: protected: void PlayerLocal::UpdatePlayersSteamLogon(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::UpdatePlayersSteamLogon(PlayerLocal *this)
{
  CSteamID *v2; // eax
  _BYTE v3[8]; // [esp+4h] [ebp-10h] BYREF
  CSteamID cSteamId; // [esp+Ch] [ebp-8h] BYREF

  if ( steamapicontext->m_pSteamUser != nullptr )
  {
    this->m_eOnlineState = steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser)
                         ? STATE_ONLINE
                         : STATE_OFFLINE;
    steamapicontext->m_pSteamUser->GetSteamID(this: steamapicontext->m_pSteamUser, result: &cSteamId);
    if ( this->m_xuid == 0 && CSteamID::IsValid(this: &cSteamId) )
    {
      v2 = steamapicontext->m_pSteamUser->GetSteamID(this: steamapicontext->m_pSteamUser, result: v3);
      LODWORD(this->m_xuid) = v2->m_steamid.m_comp;
      HIDWORD(this->m_xuid) = *((_DWORD *)&v2->m_steamid.m_comp + 1);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A240
// Name: protected: void PlayerLocal::Steam_OnServersConnected(struct SteamServersConnected_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::Steam_OnServersConnected(PlayerLocal *this, SteamServersConnected_t *pParam)
{
  DevMsg(a1: "Steam_OnServersConnected\n");
  PlayerLocal::UpdatePlayersSteamLogon(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A260
// Name: protected: void PlayerLocal::Steam_OnServersDisconnected(struct SteamServersDisconnected_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::Steam_OnServersDisconnected(PlayerLocal *this, SteamServersDisconnected_t *pParam)
{
  DevWarning(a1: "Steam_OnServersDisconnected\n");
  PlayerLocal::UpdatePlayersSteamLogon(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000A290
// Name: public: void PlayerLocal::WriteTitleData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::WriteTitleData(PlayerLocal *this)
{
  bool v2; // zf
  bool *m_bSaveTitleData; // ecx
  int v4; // eax
  unsigned int m_iController; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax

  v2 = !this->m_bSaveTitleData[0];
  m_bSaveTitleData = this->m_bSaveTitleData;
  v4 = !v2;
  if ( this->m_bSaveTitleData[1] )
    ++v4;
  if ( this->m_bSaveTitleData[2] )
    ++v4;
  if ( v4 != 0 )
  {
    _V_memset(dest: m_bSaveTitleData, fill: 0, count: 3);
    PlayerManager::RequestStoreStats(this: g_pPlayerManager);
    m_iController = this->m_iController;
    if ( m_iController < 4 )
      s_arrXWO[m_iController] = MMXWO_NONE;
    DevMsg(a1: "User stats written.\n");
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(
             this: v6,
             setName: "OnProfileDataSaved",
             firstKey: "iController",
             firstValue: this->m_iController);
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v7);
    }
    else
    {
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A340
// Name: public: void PlayerLocal::LoadPlayerProfileData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::LoadPlayerProfileData(PlayerLocal *this)
{
  DevMsg(a1: "Player %d : LoadPlayerProfileData finished\n", this->m_iController);
}

//------------------------------------------------------------------------------
// Address: 0x1000A360
// Name: public: virtual struct MatchmakingData __near * PlayerLocal::GetPlayerMatchmakingData(void)
// Source: json
//------------------------------------------------------------------------------
MatchmakingData *__thiscall PlayerLocal::GetPlayerMatchmakingData(PlayerLocal *this)
{
  return &this->m_MatchmakingData;
}

//------------------------------------------------------------------------------
// Address: 0x1000A370
// Name: public: virtual void PlayerLocal::ResetPlayerMatchmakingData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::ResetPlayerMatchmakingData(PlayerLocal *this, unsigned int mmDataScope)
{
  int v3; // eax
  ConVar *m_pConVarState; // eax
  int v5; // [esp-4h] [ebp-14h]
  ConVarRef score_default; // [esp+8h] [ebp-8h] BYREF

  if ( mmDataScope > 1 )
  {
    DevMsg(a1: "Invalid matchmaking data scope passed to ResetPlayerMatchmakingData ( %d )", mmDataScope);
  }
  else
  {
    v3 = ((int (__thiscall *)(PlayerLocal *, unsigned int))this->GetPlayerIndex)(a1: this, a2: mmDataScope);
    DevMsg(a1: "Player::ResetPlayerMatchmakingData( ctrlr%d; mmDataScope%d )\n", v3, v5);
    ConVarRef::ConVarRef(this: &score_default, pName: "score_default");
    m_pConVarState = score_default.m_pConVarState;
    this->m_MatchmakingData.mContribution[0][mmDataScope] = score_default.m_pConVarState->m_Value.m_nValue;
    this->m_MatchmakingData.mMVPs[0][mmDataScope] = 0;
    this->m_MatchmakingData.mKills[0][mmDataScope] = 0;
    this->m_MatchmakingData.mDeaths[0][mmDataScope] = 0;
    this->m_MatchmakingData.mHeadShots[0][mmDataScope] = 0;
    this->m_MatchmakingData.mDamage[0][mmDataScope] = 0;
    this->m_MatchmakingData.mShotsFired[0][mmDataScope] = 0;
    this->m_MatchmakingData.mShotsHit[0][mmDataScope] = 0;
    this->m_MatchmakingData.mDominations[0][mmDataScope] = 0;
    this->m_MatchmakingData.mRoundsPlayed[0][mmDataScope] = 0;
    this->m_MatchmakingData.mContribution[1][mmDataScope] = m_pConVarState->m_Value.m_nValue;
    this->m_MatchmakingData.mMVPs[1][mmDataScope] = 0;
    this->m_MatchmakingData.mKills[1][mmDataScope] = 0;
    this->m_MatchmakingData.mDeaths[1][mmDataScope] = 0;
    this->m_MatchmakingData.mHeadShots[1][mmDataScope] = 0;
    this->m_MatchmakingData.mDamage[1][mmDataScope] = 0;
    this->m_MatchmakingData.mShotsFired[1][mmDataScope] = 0;
    this->m_MatchmakingData.mShotsHit[1][mmDataScope] = 0;
    this->m_MatchmakingData.mDominations[1][mmDataScope] = 0;
    this->m_MatchmakingData.mRoundsPlayed[1][mmDataScope] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A480
// Name: public: virtual void const __near * PlayerLocal::GetPlayerTitleData(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall PlayerLocal::GetPlayerTitleData(PlayerLocal *this, unsigned int iTitleDataIndex)
{
  if ( iTitleDataIndex > 2 )
    return nullptr;
  else
    return this->m_bufTitleData[iTitleDataIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1000A4B0
// Name: public: virtual void PlayerLocal::GetLeaderboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::GetLeaderboardData(PlayerLocal *this, KeyValues *pLeaderboardInfo)
{
  KeyValues *i; // esi
  const char *Name; // eax
  KeyValues *Key; // edi

  for ( i = KeyValues::GetFirstTrueSubKey(this: pLeaderboardInfo); i != nullptr; i = KeyValues::GetNextTrueSubKey(this: i) )
  {
    Name = KeyValues::GetName(this: i);
    Key = KeyValues::FindKey(this: this->m_pLeaderboardData, keyName: Name, bCreate: false);
    if ( (KeyValues::GetInt(this: i, keyName: ":refresh", defaultValue: 0) != 0 || Key == nullptr)
      && g_pLeaderboardRequestQueue != nullptr )
    {
      g_pLeaderboardRequestQueue->Request(this: g_pLeaderboardRequestQueue, a2: i);
    }
    KeyValues::MergeFrom(this: i, kvMerge: Key, eOp: MERGE_KV_BORROW);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A530
// Name: public: virtual void PlayerLocal::UpdateLeaderboardData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::UpdateLeaderboardData(PlayerLocal *this, KeyValues *pLeaderboardInfo)
{
  PlayerLocal *v2; // ebx
  const char *v3; // eax
  KeyValues *FirstTrueSubKey; // eax
  const char *Name; // esi
  IMatchTitle *v6; // eax
  KeyValues *v7; // edi
  KeyValues *Key; // ebx
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  const char *v11; // eax
  KeyValues *pView; // [esp+10h] [ebp+8h]

  v2 = this;
  v3 = (const char *)((int (__fastcall *)(PlayerLocal *))this->GetName)(a1: this);
  DevMsg(a1: "PlayerLocal::UpdateLeaderboardData for %s ...\n", v3);
  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pLeaderboardInfo);
  pView = FirstTrueSubKey;
  if ( FirstTrueSubKey != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstTrueSubKey);
      v6 = g_pMMF->GetMatchTitle(this: g_pMMF);
      v7 = v6->DescribeTitleLeaderboard(this: v6, a2: Name);
      if ( v7 == nullptr )
        DevWarning(a1: "   View %s failed to allocate description!\n", Name);
      Key = KeyValues::FindKey(this: v2->m_pLeaderboardData, keyName: Name, bCreate: false);
      if ( KeyValues::GetInt(this: v7, keyName: ":nocache", defaultValue: 0) == 0 && Key == nullptr )
      {
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(this: v9, setName: Name);
        else
          v10 = nullptr;
        KeyValues::AddSubKey(this: this->m_pLeaderboardData, pSubkey: v10);
      }
      if ( v7 != nullptr )
      {
        Steam_WriteLeaderboardData(pViewDescription: v7, pViewData: pView);
        KeyValues::deleteThis(this: v7);
      }
      v2 = this;
      pView = KeyValues::GetNextTrueSubKey(this: pView);
      if ( pView == nullptr )
        break;
      FirstTrueSubKey = pView;
    }
  }
  v11 = v2->GetName(this: v2);
  DevMsg(a1: "PlayerLocal::UpdateLeaderboardData for %s finished.\n", v11);
}

//------------------------------------------------------------------------------
// Address: 0x1000A650
// Name: public: void PlayerLocal::OnLeaderboardRequestFinished(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::OnLeaderboardRequestFinished(PlayerLocal *this, KeyValues *pLeaderboardData)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi

  KeyValues::MergeFrom(this: this->m_pLeaderboardData, kvMerge: pLeaderboardData, eOp: MERGE_KV_UPDATE);
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "OnProfileLeaderboardData");
  else
    v4 = nullptr;
  KeyValues::SetInt(this: v4, keyName: "iController", value: this->m_iController);
  KeyValues::MergeFrom(this: v4, kvMerge: pLeaderboardData, eOp: MERGE_KV_UPDATE);
  g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1000A6C0
// Name: ms_player_unaward
// Source: json
//------------------------------------------------------------------------------
void __cdecl ms_player_unaward(const CCommand *args)
{
  ISteamUserStats *m_pSteamUserStats; // edi
  ISteamUserStats_vtbl *v2; // esi
  const char *Arg; // eax
  const char *v4; // eax
  const char *v5; // eax

  m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
  v2 = m_pSteamUserStats->__vftable;
  Arg = CCommand::FindArg(this: args, pName: "unaward");
  if ( v2->ClearAchievement(this: m_pSteamUserStats, a2: Arg) )
  {
    steamapicontext->m_pSteamUserStats->StoreStats(this: steamapicontext->m_pSteamUserStats);
    v4 = CCommand::FindArg(this: args, pName: "unaward");
    DevMsg(a1: "%s unawarded!\n", v4);
  }
  else
  {
    v5 = CCommand::FindArg(this: args, pName: "unaward");
    DevWarning(a1: "%s failed\n", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A740
// Name: public: virtual unsigned __int64 Player<class IPlayerFriend>::GetXUID(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall Player<IPlayerFriend>::GetXUID(CServer *this)
{
  return this->m_xuid;
}

//------------------------------------------------------------------------------
// Address: 0x1000A750
// Name: public: virtual char const __near * Player<class IPlayerFriend>::GetName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall Player<IPlayerFriend>::GetName(Player<IPlayerLocal> *this)
{
  return this->m_szName;
}

//------------------------------------------------------------------------------
// Address: 0x1000A7C0
// Name: void SignalXWriteOpportunity(enum MM_XWriteOpportunity)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SignalXWriteOpportunity(MM_XWriteOpportunity eXWO)
{
  int i; // edi
  IPlayerLocal *v2; // eax
  float *v3; // esi

  if ( eXWO != MMXWO_NONE )
  {
    _Msg(a1: "SignalXWriteOpportunity(%d)\n", eXWO);
    if ( eXWO == MMXWO_SESSION_STARTED )
    {
      for ( i = 0; i < 4; ++i )
      {
        v2 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: i);
        v3 = (float *)__RTDynamicCast(
                        inptr: v2,
                        VfDelta: 0,
                        SrcType: &IPlayerLocal `RTTI Type Descriptor',
                        TargetType: &PlayerLocal `RTTI Type Descriptor',
                        isReference: 0);
        if ( v3 != nullptr )
          v3[15] = _Plat_FloatTime();
      }
    }
    else
    {
      if ( s_arrXWO[0] < eXWO )
        s_arrXWO[0] = eXWO;
      if ( s_arrXWO[1] < eXWO )
        s_arrXWO[1] = eXWO;
      if ( s_arrXWO[2] < eXWO )
        s_arrXWO[2] = eXWO;
      if ( s_arrXWO[3] < eXWO )
        s_arrXWO[3] = eXWO;
    }
  }
  else
  {
    _Warning(a1: "SignalXWriteOpportunity called with MMXWO_NONE!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A870
// Name: protected: void PlayerFriend::Steam_OnLobbyDataUpdate(struct LobbyDataUpdate_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::Steam_OnLobbyDataUpdate(PlayerFriend *this, LobbyDataUpdate_t *pParam)
{
  int m_ulSteamIDLobby_high; // ecx
  int v4; // edx
  KeyValues *m_pDetails; // ecx
  IMatchNetworkMsgController *v6; // eax
  KeyValues *v7; // eax
  KeyValues *Key; // eax
  KeyValues *v9; // edi
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  const char *v12; // eax
  const wchar_t *v13; // eax

  m_ulSteamIDLobby_high = HIDWORD(pParam->m_ulSteamIDLobby);
  if ( LODWORD(pParam->m_ulSteamIDLobby) == LODWORD(pParam->m_ulSteamIDMember)
    && m_ulSteamIDLobby_high == HIDWORD(pParam->m_ulSteamIDMember)
    && LODWORD(pParam->m_ulSteamIDLobby) == *(_DWORD *)this->m_xSessionID.ab
    && m_ulSteamIDLobby_high == *(_DWORD *)&this->m_xSessionID.ab[4] )
  {
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyDataUpdate);
    memset(dst: this->m_GameSessionInfo.sessionID.ab, value: 0, count: 0x3Cu);
    v4 = *(_DWORD *)&this->m_xSessionID.ab[4];
    *(_DWORD *)this->m_GameSessionInfo.sessionID.ab = *(_DWORD *)this->m_xSessionID.ab;
    m_pDetails = this->m_pDetails;
    *(_DWORD *)&this->m_GameSessionInfo.sessionID.ab[4] = v4;
    if ( m_pDetails != nullptr )
      KeyValues::deleteThis(this: m_pDetails);
    this->m_pDetails = nullptr;
    v6 = g_pMatchFramework->GetMatchNetworkMsgController(this: g_pMatchFramework);
    v7 = (KeyValues *)((int (__thiscall *)(IMatchNetworkMsgController *, _DWORD, _DWORD))v6->UnpackGameDetailsFromSteamLobby)(
                        a1: v6,
                        a2: pParam->m_ulSteamIDLobby,
                        a3: HIDWORD(pParam->m_ulSteamIDLobby));
    this->m_pDetails = v7;
    if ( v7 != nullptr )
    {
      Key = KeyValues::FindKey(this: v7, keyName: "options", bCreate: true);
      if ( Key != nullptr )
        KeyValues::SetUint64(this: Key, keyName: "sessionid", value: pParam->m_ulSteamIDLobby);
      v9 = KeyValues::FindKey(this: this->m_pDetails, keyName: "player", bCreate: true);
      if ( v9 != nullptr )
      {
        v10 = this->GetXUID(this);
        KeyValues::SetUint64(this: v9, keyName: "xuid", value: v10);
        v11 = this->GetXUID(this);
        KeyValues::SetUint64(this: v9, keyName: "xuidOnline", value: v11);
        v12 = this->GetName(this);
        KeyValues::SetString(this: v9, keyName: "name", value: v12);
        v13 = this->GetRichPresence(this);
        KeyValues::SetWString(this: v9, keyName: "richpresence", value: v13);
      }
    }
    this->m_eSearchState = SEARCH_COMPLETED;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A9D0
// Name: protected: void PlayerLocal::Steam_OnPersonaStateChange(struct PersonaStateChange_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::Steam_OnPersonaStateChange(PlayerLocal *this, PersonaStateChange_t *pParam)
{
  ISteamFriends *m_pSteamFriends; // ecx
  unsigned __int64 m_xuid; // rax
  const char *v5; // eax

  if ( steamapicontext != nullptr && steamapicontext->m_pSteamUtils != nullptr )
  {
    m_pSteamFriends = steamapicontext->m_pSteamFriends;
    if ( m_pSteamFriends != nullptr && steamapicontext->m_pSteamUser != nullptr && pParam != nullptr )
    {
      m_xuid = this->m_xuid;
      if ( m_xuid != 0 && m_xuid == pParam->m_ulSteamID && (pParam->m_nChangeFlags & 1) != 0 )
      {
        v5 = (const char *)((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))m_pSteamFriends->GetFriendPersonaName)(
                             a1: m_pSteamFriends,
                             a2: m_xuid,
                             a3: HIDWORD(m_xuid));
        if ( v5 != nullptr )
          V_strncpy(pDest: this->m_szName, pSrc: v5, maxLen: 32);
        if ( cl_names_debug.m_pParent != nullptr && cl_names_debug.m_pParent->m_Value.m_nValue != 0 )
          V_strncpy(pDest: this->m_szName, pSrc: "WWWWWWWWWWWWWWW", maxLen: 32);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AA60
// Name: public: virtual void PlayerLocal::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::Destroy(PlayerLocal *this)
{
  this->m_xuid = 0;
  this->m_eOnlineState = STATE_OFFLINE;
  this->m_iController = 254;
  _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnUserStatsReceived);
  _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnPersonaStateChange);
  ((void (__thiscall *)(PlayerLocal *, int))this->dtr_Player<IPlayerLocal>)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000AAA0
// Name: ms_player_dump_properties
// Source: json
//------------------------------------------------------------------------------
void __cdecl ms_player_dump_properties()
{
  void (*v0)(const char *, ...); // ebx
  IPlayerLocal *v1; // edi
  const char *v2; // eax
  IMatchTitle *v3; // eax
  int v4; // eax
  int *v5; // esi
  int v6; // ebx
  int v7; // eax
  char v8; // cl
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  double v13; // [esp+8h] [ebp-18h]
  int v14; // [esp+1Ch] [ebp-4h]

  v0 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "[DMM] ms_player_dump_properties...\n");
  _Msg(a1: "        Num game users: %d\n", 1);
  _Msg(a1: "Slot%d ctrlr%d: %s\n", 0, 0, "profile");
  v1 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  if ( v1 != nullptr )
  {
    v2 = v1->GetName(this: v1);
    _Msg(a1: "  Name = %s\n", v2);
    v3 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    v4 = (int)v3->DescribeTitleDataStorage(this: v3);
    if ( v4 != 0 )
    {
      v5 = (int *)(v4 + 12);
      do
      {
        if ( *(v5 - 3) == 0 )
          break;
        switch ( *(v5 - 1) )
        {
          case 8:
            v9 = (int)v1->GetPlayerTitleData(this: v1, a2: *(v5 - 2));
            v0(a1: "  %s = %u\n", (const char *)*(v5 - 3), *(unsigned __int8 *)(v9 + *v5));
            break;
          case 9:
            v6 = *v5;
            v14 = (int)v1->GetPlayerTitleData(this: v1, a2: *(v5 - 2));
            v7 = v6 / 8;
            v8 = v6 % 8;
            v0 = (void (*)(const char *, ...))_Msg;
            _Msg(a1: "  %s = %u\n", (const char *)*(v5 - 3), ((unsigned __int8)(1 << v8) & *(_BYTE *)(v14 + v7)) != 0);
            break;
          case 16:
            v10 = (int)v1->GetPlayerTitleData(this: v1, a2: *(v5 - 2));
            v0(a1: "  %s = %u\n", (const char *)*(v5 - 3), *(unsigned __int16 *)(v10 + *v5));
            break;
          case 32:
            v11 = (int)v1->GetPlayerTitleData(this: v1, a2: *(v5 - 2));
            v0(a1: "  %s = %u\n", (const char *)*(v5 - 3), *(_DWORD *)(v11 + *v5));
            break;
          case 33:
            v13 = *(float *)((char *)v1->GetPlayerTitleData(this: v1, a2: *(v5 - 2)) + *v5);
            v0(a1: "  %s = %.3f\n", *(v5 - 3), v13);
            break;
          case 64:
            v12 = (int)v1->GetPlayerTitleData(this: v1, a2: *(v5 - 2));
            v0(a1: "  %s = 0x%llX\n", *(v5 - 3), *(_QWORD *)(v12 + *v5));
            break;
          default:
            break;
        }
        v5 += 4;
      }
      while ( v5 != (int *)12 );
    }
  }
  v0(a1: "        ms_player_dump_properties finished.\n");
}

//------------------------------------------------------------------------------
// Address: 0x1000ADA0
// Name: ApplySteamStatPotentialOverride_int_
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ApplySteamStatPotentialOverride_int_(
        const char *szField,
        int *pValue,
        bool bResult,
        int (__thiscall *pfn)(KeyValues *this, const char *, int))
{
  char *m_pszString; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // edi
  IBaseFileSystem *v7; // eax
  KeyValues *Key; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  const char *String; // eax
  KeyValues *v13; // eax
  KeyValues *FirstValue; // esi
  const char *Name; // edi
  int v16; // eax
  const char *v17; // eax
  KeyValues *kvOverride; // [esp+4h] [ebp-8h]
  char *szFile; // [esp+8h] [ebp-4h]

  if ( mm_cfgdebug_mode.m_pParent != nullptr && mm_cfgdebug_mode.m_pParent->m_Value.m_nValue > 0 )
    DevMsg(a1: "[PlayerStats] '%s' = %d (0x%08X)\n", szField, *pValue, *pValue);
  if ( (mm_cfgoverride_file.m_nFlags & 0x1000) != 0 )
  {
    szFile = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = mm_cfgoverride_file.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      return bResult;
    szFile = mm_cfgoverride_file.m_pParent->m_Value.m_pszString;
    if ( *m_pszString == 0 )
      return bResult;
  }
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
  {
    v6 = KeyValues::KeyValues(this: v5, setName: "cfgoverride.kv");
    kvOverride = v6;
  }
  else
  {
    kvOverride = nullptr;
    v6 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v7 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v7 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v6,
          filesystem: v7,
          resourceName: szFile,
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    if ( v6 != nullptr )
      KeyValues::deleteThis(this: v6);
    return bResult;
  }
  Key = KeyValues::FindKey(this: v6, keyName: "items", bCreate: false);
  v10 = KeyValues::FindKey(this: Key, keyName: szField, bCreate: false);
  v11 = v10;
  if ( v10 != nullptr )
  {
    *pValue = pfn(this: v10, a2: defaultValue, a3: 0);
    String = KeyValues::GetString(this: v11, keyName: defaultValue, defaultValue: defaultValue);
    DevMsg(a1: "[PlayerStats] '%s' overrides '%s' = '%s'\n", szFile, szField, String);
    if ( mm_cfgoverride_commit.m_pParent != nullptr && mm_cfgoverride_commit.m_pParent->m_Value.m_nValue != 0 )
      SetSteamStatWithPotentialOverride(szField, iValue: *pValue);
    if ( v6 != nullptr )
      KeyValues::deleteThis(this: v6);
    return true;
  }
  v13 = KeyValues::FindKey(this: v6, keyName: "wildcards", bCreate: false);
  FirstValue = KeyValues::GetFirstValue(this: v13);
  if ( FirstValue != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstValue);
      v16 = _V_strlen(str: Name);
      if ( v16 != 0 && Name[v16 - 1] == 42 && (v16 <= 1 || V_strnicmp(s1: Name, s2: szField, n: v16 - 1) == 0) )
        break;
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
      {
        v6 = kvOverride;
        goto LABEL_32;
      }
    }
    *pValue = pfn(this: FirstValue, a2: defaultValue, a3: 0);
    v17 = KeyValues::GetString(this: FirstValue, keyName: defaultValue, defaultValue: defaultValue);
    DevMsg(a1: "[PlayerStats] '%s' overrides '%s' = '%s' [wildcard match '%s']\n", szFile, szField, v17, Name);
    if ( mm_cfgoverride_commit.m_pParent != nullptr && mm_cfgoverride_commit.m_pParent->m_Value.m_nValue != 0 )
      SetSteamStatWithPotentialOverride(szField, iValue: *pValue);
    if ( kvOverride != nullptr )
    {
      KeyValues::deleteThis(this: kvOverride);
      return true;
    }
    return true;
  }
LABEL_32:
  if ( v6 != nullptr )
    KeyValues::deleteThis(this: v6);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x1000AFE0
// Name: ApplySteamStatPotentialOverride_float_
// Source: json
//------------------------------------------------------------------------------
bool __usercall ApplySteamStatPotentialOverride_float_@<al>(
        float a1@<xmm1>,
        const char *szField,
        float *pValue,
        bool bResult,
        float (__thiscall *pfn)(KeyValues *this, const char *, float))
{
  char *m_pszString; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  IBaseFileSystem *v8; // eax
  KeyValues *Key; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  const char *String; // eax
  KeyValues *v14; // eax
  KeyValues *FirstValue; // esi
  const char *Name; // edi
  int v17; // eax
  const char *v18; // eax
  KeyValues *kvOverride; // [esp+10h] [ebp-8h]
  char *szFile; // [esp+14h] [ebp-4h]

  if ( mm_cfgdebug_mode.m_pParent != nullptr && mm_cfgdebug_mode.m_pParent->m_Value.m_nValue > 0 )
    DevMsg(a1: "[PlayerStats] '%s' = %d (0x%08X)\n", szField, (int)a1, *(_DWORD *)pValue);
  if ( (mm_cfgoverride_file.m_nFlags & 0x1000) != 0 )
  {
    szFile = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = mm_cfgoverride_file.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      return bResult;
    szFile = mm_cfgoverride_file.m_pParent->m_Value.m_pszString;
    if ( *m_pszString == 0 )
      return bResult;
  }
  v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v6 != nullptr )
  {
    v7 = KeyValues::KeyValues(this: v6, setName: "cfgoverride.kv");
    kvOverride = v7;
  }
  else
  {
    kvOverride = nullptr;
    v7 = nullptr;
  }
  if ( g_pFullFileSystem != nullptr )
    v8 = &g_pFullFileSystem->IBaseFileSystem;
  else
    v8 = nullptr;
  if ( !KeyValues::LoadFromFile(
          this: v7,
          filesystem: v8,
          resourceName: szFile,
          pathID: nullptr,
          pfnEvaluateSymbolProc: nullptr) )
  {
    if ( v7 != nullptr )
      KeyValues::deleteThis(this: v7);
    return bResult;
  }
  Key = KeyValues::FindKey(this: v7, keyName: "items", bCreate: false);
  v11 = KeyValues::FindKey(this: Key, keyName: szField, bCreate: false);
  v12 = v11;
  if ( v11 != nullptr )
  {
    *pValue = ((double (__thiscall *)(KeyValues *, const char *, _DWORD))pfn)(a1: v11, a2: defaultValue, a3: 0);
    String = KeyValues::GetString(this: v12, keyName: defaultValue, defaultValue: defaultValue);
    DevMsg(a1: "[PlayerStats] '%s' overrides '%s' = '%s'\n", szFile, szField, String);
    if ( mm_cfgoverride_commit.m_pParent != nullptr && mm_cfgoverride_commit.m_pParent->m_Value.m_nValue != 0 )
      SetSteamStatWithPotentialOverride_0(a1: *(_DWORD *)pValue, szField);
    if ( v7 != nullptr )
      KeyValues::deleteThis(this: v7);
    return true;
  }
  v14 = KeyValues::FindKey(this: v7, keyName: "wildcards", bCreate: false);
  FirstValue = KeyValues::GetFirstValue(this: v14);
  if ( FirstValue != nullptr )
  {
    while ( 1 )
    {
      Name = KeyValues::GetName(this: FirstValue);
      v17 = _V_strlen(str: Name);
      if ( v17 != 0 && Name[v17 - 1] == 42 && (v17 <= 1 || V_strnicmp(s1: Name, s2: szField, n: v17 - 1) == 0) )
        break;
      FirstValue = KeyValues::GetNextValue(this: FirstValue);
      if ( FirstValue == nullptr )
      {
        v7 = kvOverride;
        goto LABEL_32;
      }
    }
    *pValue = ((double (__thiscall *)(KeyValues *, const char *, _DWORD))pfn)(a1: FirstValue, a2: defaultValue, a3: 0);
    v18 = KeyValues::GetString(this: FirstValue, keyName: defaultValue, defaultValue: defaultValue);
    DevMsg(a1: "[PlayerStats] '%s' overrides '%s' = '%s' [wildcard match '%s']\n", szFile, szField, v18, Name);
    if ( mm_cfgoverride_commit.m_pParent != nullptr && mm_cfgoverride_commit.m_pParent->m_Value.m_nValue != 0 )
      SetSteamStatWithPotentialOverride_0(a1: *(_DWORD *)pValue, szField);
    if ( kvOverride != nullptr )
    {
      KeyValues::deleteThis(this: kvOverride);
      return true;
    }
    return true;
  }
LABEL_32:
  if ( v7 != nullptr )
    KeyValues::deleteThis(this: v7);
  return bResult;
}

//------------------------------------------------------------------------------
// Address: 0x1000B230
// Name: public: void PlayerFriend::StartSearchForSessionInfoImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::StartSearchForSessionInfoImpl(PlayerFriend *this)
{
  ISteamMatchmaking *m_pSteamMatchmaking; // ecx
  KeyValues *m_pDetails; // ecx

  if ( this->m_eSearchState <= (unsigned int)SEARCH_QUEUED )
  {
    m_pSteamMatchmaking = steamapicontext->m_pSteamMatchmaking;
    if ( m_pSteamMatchmaking != nullptr
      && *(_QWORD *)&this->m_xSessionID != 0
      && ((unsigned __int8 (__thiscall *)(ISteamMatchmaking *, _DWORD, _DWORD))m_pSteamMatchmaking->RequestLobbyData)(
           a1: m_pSteamMatchmaking,
           a2: *(_DWORD *)this->m_xSessionID.ab,
           a3: *(_DWORD *)&this->m_xSessionID.ab[4]) != 0 )
    {
      CCallback<PlayerFriend,LobbyDataUpdate_t,0>::Register(
        this: &this->m_CallbackOnLobbyDataUpdate,
        pObj: this,
        func: PlayerFriend::Steam_OnLobbyDataUpdate);
      ++s_numSearchesOutstanding;
      this->m_eSearchState = SEARCH_WAIT_LOBBY_DATA;
    }
    else
    {
      this->m_xSessionID = 0;
      memset(dst: this->m_GameSessionInfo.sessionID.ab, value: 0, count: 0x3Cu);
      m_pDetails = this->m_pDetails;
      if ( m_pDetails != nullptr )
        KeyValues::deleteThis(this: m_pDetails);
      this->m_pDetails = nullptr;
      this->m_eSearchState = SEARCH_NONE;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B400
// Name: void PumpSessionSearchQueue(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl PumpSessionSearchQueue()
{
  int i; // ecx
  int m_nValue; // eax
  unsigned int v2; // esi
  unsigned int v3; // edi
  int v4; // ecx
  PlayerFriend *PlayerFriend; // eax

  for ( i = s_arrSessionSearchesQueue.m_Size; s_arrSessionSearchesQueue.m_Size > 0; i = s_arrSessionSearchesQueue.m_Size )
  {
    if ( mm_player_search_count.m_pParent != nullptr )
      m_nValue = mm_player_search_count.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    if ( s_numSearchesOutstanding >= m_nValue )
      break;
    v2 = *(_DWORD *)s_arrSessionSearchesQueue.m_Memory.m_pMemory;
    v3 = *((_DWORD *)s_arrSessionSearchesQueue.m_Memory.m_pMemory + 1);
    v4 = i - 1;
    if ( v4 > 0 )
      _V_memmove(
        dest: s_arrSessionSearchesQueue.m_Memory.m_pMemory,
        src: s_arrSessionSearchesQueue.m_Memory.m_pMemory + 1,
        count: 8 * v4);
    --s_arrSessionSearchesQueue.m_Size;
    PlayerFriend = PlayerManager::FindPlayerFriend(this: g_pPlayerManager, xuid: __PAIR64__(v3, v2));
    if ( PlayerFriend != nullptr )
      PlayerFriend::StartSearchForSessionInfoImpl(this: PlayerFriend);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B480
// Name: public: void PlayerFriend::AbortSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::AbortSearch(PlayerFriend *this)
{
  KeyValues *m_pDetails; // ecx

  _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnLobbyDataUpdate);
  while ( CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::FindAndRemove(
            this: &s_arrSessionSearchesQueue,
            src: &this->m_xuid) != 0 )
    ;
  if ( this->m_eSearchState == SEARCH_WAIT_LOBBY_DATA || this->m_eSearchState == SEARCH_COMPLETED )
  {
    --s_numSearchesOutstanding;
    PumpSessionSearchQueue();
  }
  m_pDetails = this->m_pDetails;
  this->m_eSearchState = SEARCH_NONE;
  if ( m_pDetails != nullptr )
    KeyValues::deleteThis(this: m_pDetails);
  this->m_pDetails = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000B4F0
// Name: public: virtual void PlayerLocal::GetAwardsData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::GetAwardsData(PlayerLocal *this, KeyValues *pAwardsData)
{
  const char *Name; // edi
  int j; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  int i; // edi
  KeyValues *v8; // eax
  KeyValues *v9; // esi
  IMatchTitle *v10; // eax
  int v11; // esi
  IMatchTitle *v12; // eax
  int v13; // esi
  const char *v14; // eax
  int m_Size; // edx
  int v16; // eax
  int v17; // esi
  int *m_pMemory; // ecx
  int v19; // edx
  int v20; // esi
  int *v21; // ecx
  const char *v22; // [esp-Ch] [ebp-10h]
  KeyValues *kvValue; // [esp+Ch] [ebp+8h]

  for ( kvValue = KeyValues::GetFirstValue(this: pAwardsData);
        kvValue != nullptr;
        kvValue = KeyValues::GetNextValue(this: kvValue) )
  {
    Name = KeyValues::GetName(this: kvValue);
    if ( _V_stricmp(s1: "@achievements", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "@awards", s2: Name) != 0 )
      {
        v10 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
        v11 = (int)v10->DescribeTitleAchievements(this: v10);
        if ( v11 != 0 )
        {
          while ( *(_DWORD *)v11 != 0 )
          {
            if ( _V_stricmp(s1: Name, s2: *(const char **)v11) == 0 )
            {
              m_Size = this->m_arrAchievementsEarned.m_Size;
              v16 = 0;
              if ( m_Size <= 0 )
              {
LABEL_32:
                v16 = -1;
              }
              else
              {
                v17 = *(_DWORD *)(v11 + 4);
                m_pMemory = this->m_arrAchievementsEarned.m_Memory.m_pMemory;
                while ( *m_pMemory != v17 )
                {
                  ++v16;
                  ++m_pMemory;
                  if ( v16 >= m_Size )
                    goto LABEL_32;
                }
              }
LABEL_33:
              KeyValues::SetInt(this: kvValue, keyName: defaultValue, value: v16 != -1);
              goto LABEL_26;
            }
            v11 += 12;
            if ( v11 == 0 )
              break;
          }
        }
        if ( Name != nullptr )
        {
          v12 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
          v13 = (int)v12->DescribeTitleAvatarAwards(this: v12);
          if ( v13 != 0 )
          {
            while ( *(_DWORD *)v13 != 0 )
            {
              if ( _V_stricmp(s1: Name, s2: *(const char **)v13) == 0 )
              {
                v19 = this->m_arrAvatarAwardsEarned.m_Size;
                v16 = 0;
                if ( v19 <= 0 )
                {
LABEL_38:
                  v16 = -1;
                }
                else
                {
                  v20 = *(_DWORD *)(v13 + 4);
                  v21 = this->m_arrAvatarAwardsEarned.m_Memory.m_pMemory;
                  while ( *v21 != v20 )
                  {
                    ++v16;
                    ++v21;
                    if ( v16 >= v19 )
                      goto LABEL_38;
                  }
                }
                goto LABEL_33;
              }
              v13 += 12;
              if ( v13 == 0 )
                break;
            }
          }
          v14 = (const char *)((int (__thiscall *)(PlayerLocal *, const char *))this->GetName)(a1: this, a2: Name);
          DevWarning(a1: "pPlayerLocal(%s)->GetAwardsData(%s) UNKNOWN NAME!\n", v14, v22);
        }
      }
      else
      {
        for ( i = 0; i < this->m_arrAvatarAwardsEarned.m_Size; ++i )
        {
          v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v8 != nullptr )
            v9 = KeyValues::KeyValues(this: v8, setName: defaultValue);
          else
            v9 = nullptr;
          KeyValues::SetInt(this: v9, keyName: nullptr, value: this->m_arrAvatarAwardsEarned.m_Memory.m_pMemory[i]);
          KeyValues::AddSubKey(this: kvValue, pSubkey: v9);
        }
      }
    }
    else
    {
      for ( j = 0; j < this->m_arrAchievementsEarned.m_Size; ++j )
      {
        v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v5 != nullptr )
          v6 = KeyValues::KeyValues(this: v5, setName: defaultValue);
        else
          v6 = nullptr;
        KeyValues::SetInt(this: v6, keyName: nullptr, value: this->m_arrAchievementsEarned.m_Memory.m_pMemory[j]);
        KeyValues::AddSubKey(this: kvValue, pSubkey: v6);
      }
    }
LABEL_26:
    ;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B790
// Name: public: virtual void PlayerFriend::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::Destroy(PlayerFriend *this)
{
  PlayerFriend::AbortSearch(this);
  if ( this != nullptr )
    ((void (__thiscall *)(PlayerFriend *, int))this->dtr_Player<IPlayerFriend>)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000B7B0
// Name: public: PlayerLocal::PlayerLocal(int)
// Source: json
//------------------------------------------------------------------------------
PlayerLocal *__thiscall PlayerLocal::PlayerLocal(PlayerLocal *this, unsigned int iController)
{
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  ISteamUser *m_pSteamUser; // ecx
  int v6; // edx
  int m_unAll64Bits_high; // eax
  unsigned int v8; // eax
  ISteamFriends *m_pSteamFriends; // ecx
  const char *v10; // eax
  __int64 v12; // [esp+8h] [ebp-10h] BYREF
  CSteamID steamIDPlayer; // [esp+10h] [ebp-8h] BYREF

  this->m_xuid = 0;
  this->m_iController = 254;
  this->m_eOnlineState = STATE_OFFLINE;
  *(_QWORD *)this->m_szName = 0;
  *(_QWORD *)&this->m_szName[8] = 0;
  *(_QWORD *)&this->m_szName[16] = 0;
  *(_QWORD *)&this->m_szName[24] = 0;
  this->__vftable = (PlayerLocal_vtbl *)&PlayerLocal::`vftable';
  this->m_eLoadedTitleData = eXUserSigninState_NotSignedIn;
  this->m_flLastSave = 0.0;
  this->m_uiPlayerFlags = 0;
  this->m_arrAchievementsEarned.m_Memory.m_pMemory = nullptr;
  this->m_arrAchievementsEarned.m_Memory.m_nAllocationCount = 0;
  this->m_arrAchievementsEarned.m_Memory.m_nGrowSize = 0;
  this->m_arrAchievementsEarned.m_Size = 0;
  this->m_arrAchievementsEarned.m_pElements = nullptr;
  this->m_arrAvatarAwardsEarned.m_Memory.m_pMemory = nullptr;
  this->m_arrAvatarAwardsEarned.m_Memory.m_nAllocationCount = 0;
  this->m_arrAvatarAwardsEarned.m_Memory.m_nGrowSize = 0;
  this->m_arrAvatarAwardsEarned.m_Size = 0;
  this->m_arrAvatarAwardsEarned.m_pElements = nullptr;
  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Leaderboard");
  else
    v4 = nullptr;
  this->m_pLeaderboardData = v4;
  this->m_autodelete_pLeaderboardData.m_pKeyValues = v4;
  this->m_CallbackOnUserStatsReceived.m_nCallbackFlags = 0;
  this->m_CallbackOnUserStatsReceived.m_iCallback = 0;
  this->m_CallbackOnUserStatsReceived.m_pObj = nullptr;
  this->m_CallbackOnUserStatsReceived.m_Func = nullptr;
  this->m_CallbackOnUserStatsReceived.__vftable = (CCallbackManual<PlayerLocal,UserStatsReceived_t,0>_vtbl *)&CCallbackManual<PlayerLocal,UserStatsReceived_t,0>::`vftable';
  this->m_CallbackOnPersonaStateChange.m_nCallbackFlags = 0;
  this->m_CallbackOnPersonaStateChange.m_iCallback = 0;
  this->m_CallbackOnPersonaStateChange.m_pObj = nullptr;
  this->m_CallbackOnPersonaStateChange.m_Func = nullptr;
  this->m_CallbackOnPersonaStateChange.__vftable = (CCallbackManual<PlayerLocal,PersonaStateChange_t,0>_vtbl *)&CCallbackManual<PlayerLocal,PersonaStateChange_t,0>::`vftable';
  this->m_CallbackOnServersConnected.m_nCallbackFlags = 0;
  this->m_CallbackOnServersConnected.m_iCallback = 0;
  this->m_CallbackOnServersConnected.m_pObj = nullptr;
  this->m_CallbackOnServersConnected.m_Func = nullptr;
  this->m_CallbackOnServersConnected.__vftable = (CCallbackManual<PlayerLocal,SteamServersConnected_t,0>_vtbl *)&CCallbackManual<PlayerLocal,SteamServersConnected_t,0>::`vftable';
  this->m_CallbackOnServersDisconnected.m_nCallbackFlags = 0;
  this->m_CallbackOnServersDisconnected.m_iCallback = 0;
  this->m_CallbackOnServersDisconnected.m_pObj = nullptr;
  this->m_CallbackOnServersDisconnected.m_Func = nullptr;
  this->m_CallbackOnServersDisconnected.__vftable = (CCallbackManual<PlayerLocal,SteamServersDisconnected_t,0>_vtbl *)&CCallbackManual<PlayerLocal,SteamServersDisconnected_t,0>::`vftable';
  memset(dst: (unsigned __int8 *)&this->m_ProfileData, value: 0, count: sizeof(this->m_ProfileData));
  memset(dst: (unsigned __int8 *)this->m_bufTitleData, value: 0, count: sizeof(this->m_bufTitleData));
  *(_WORD *)this->m_bSaveTitleData = 0;
  this->m_bSaveTitleData[2] = false;
  this->m_iController = iController;
  if ( iController < 4 )
    s_arrXWO[iController] = MMXWO_NONE;
  m_pSteamUser = steamapicontext->m_pSteamUser;
  v6 = 0;
  steamIDPlayer.m_steamid.m_comp = 0;
  if ( m_pSteamUser != nullptr )
  {
    this->m_eOnlineState = m_pSteamUser->BLoggedOn(this: m_pSteamUser) ? STATE_ONLINE : STATE_OFFLINE;
    steamIDPlayer.m_steamid.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)steamapicontext->m_pSteamUser->GetSteamID(
                                                                                this: steamapicontext->m_pSteamUser,
                                                                                result: &v12)->m_steamid.m_unAll64Bits;
    if ( CSteamID::IsValid(this: &steamIDPlayer) )
    {
      m_unAll64Bits_high = HIDWORD(steamIDPlayer.m_steamid.m_unAll64Bits);
      this->m_xuid = steamIDPlayer.m_steamid.m_unAll64Bits;
      v6 = m_unAll64Bits_high;
    }
    else
    {
      v6 = HIDWORD(steamIDPlayer.m_steamid.m_unAll64Bits);
      v12 = 0;
      LODWORD(this->m_xuid) = 0;
      HIDWORD(this->m_xuid) = 0;
    }
  }
  else
  {
    LODWORD(this->m_xuid) = 0;
    HIDWORD(this->m_xuid) = 0;
  }
  v8 = ((unsigned int)v6 >> 20) & 0xF;
  if ( v8 != 0
    && v8 < 0xB
    && v6 >> 24 > 0
    && v6 >> 24 < 6
    && (v8 != 1 || steamIDPlayer.m_steamid.m_comp != 0 && (v6 & 0xFFFFF) == 1)
    && (v8 != 7 || steamIDPlayer.m_steamid.m_comp != 0 && (v6 & 0xFFFFF) == 0)
    && steamapicontext->m_pSteamUser != nullptr )
  {
    m_pSteamFriends = steamapicontext->m_pSteamFriends;
    if ( m_pSteamFriends != nullptr )
    {
      v10 = (const char *)((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))m_pSteamFriends->GetFriendPersonaName)(
                            a1: m_pSteamFriends,
                            a2: *(_DWORD *)&steamIDPlayer.m_steamid.m_comp,
                            a3: *((_DWORD *)&steamIDPlayer.m_steamid.m_comp + 1));
      if ( v10 != nullptr )
        V_strncpy(pDest: this->m_szName, pSrc: v10, maxLen: 32);
    }
  }
  if ( PlayerLocal::Steam_OnPersonaStateChange != nullptr )
  {
    if ( (this->m_CallbackOnPersonaStateChange.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnPersonaStateChange);
    this->m_CallbackOnPersonaStateChange.m_pObj = this;
    this->m_CallbackOnPersonaStateChange.m_Func = PlayerLocal::Steam_OnPersonaStateChange;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnPersonaStateChange, a2: 304);
  }
  if ( PlayerLocal::Steam_OnServersConnected != nullptr )
  {
    if ( (this->m_CallbackOnServersConnected.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnServersConnected);
    this->m_CallbackOnServersConnected.m_pObj = this;
    this->m_CallbackOnServersConnected.m_Func = PlayerLocal::Steam_OnServersConnected;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnServersConnected, a2: 101);
  }
  if ( PlayerLocal::Steam_OnServersDisconnected != nullptr )
  {
    if ( (this->m_CallbackOnServersDisconnected.m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnServersDisconnected);
    this->m_CallbackOnServersDisconnected.m_pObj = this;
    this->m_CallbackOnServersDisconnected.m_Func = PlayerLocal::Steam_OnServersDisconnected;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackOnServersDisconnected, a2: 103);
  }
  DevMsg(a1: "Player %d : LoadPlayerProfileData finished\n", this->m_iController);
  if ( cl_names_debug.m_pParent != nullptr && cl_names_debug.m_pParent->m_Value.m_nValue != 0 )
    V_strncpy(pDest: this->m_szName, pSrc: "WWWWWWWWWWWWWWW", maxLen: 32);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000BB10
// Name: public: virtual PlayerLocal::~PlayerLocal(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::~PlayerLocal(PlayerLocal *this)
{
  KeyValues *m_pKeyValues; // ecx

  this->__vftable = (PlayerLocal_vtbl *)&PlayerLocal::`vftable';
  this->m_CallbackOnServersDisconnected.__vftable = (CCallbackManual<PlayerLocal,SteamServersDisconnected_t,0>_vtbl *)&CCallback<PlayerLocal,SteamServersDisconnected_t,0>::`vftable';
  if ( (this->m_CallbackOnServersDisconnected.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnServersDisconnected);
  this->m_CallbackOnServersConnected.__vftable = (CCallbackManual<PlayerLocal,SteamServersConnected_t,0>_vtbl *)&CCallback<PlayerLocal,SteamServersConnected_t,0>::`vftable';
  if ( (this->m_CallbackOnServersConnected.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnServersConnected);
  this->m_CallbackOnPersonaStateChange.__vftable = (CCallbackManual<PlayerLocal,PersonaStateChange_t,0>_vtbl *)&CCallback<PlayerLocal,PersonaStateChange_t,0>::`vftable';
  if ( (this->m_CallbackOnPersonaStateChange.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnPersonaStateChange);
  this->m_CallbackOnUserStatsReceived.__vftable = (CCallbackManual<PlayerLocal,UserStatsReceived_t,0>_vtbl *)&CCallback<PlayerLocal,UserStatsReceived_t,0>::`vftable';
  if ( (this->m_CallbackOnUserStatsReceived.m_nCallbackFlags & 1) != 0 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackOnUserStatsReceived);
  m_pKeyValues = this->m_autodelete_pLeaderboardData.m_pKeyValues;
  if ( m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: m_pKeyValues);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrAvatarAwardsEarned);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_arrAchievementsEarned);
  this->__vftable = (PlayerLocal_vtbl *)&Player<IPlayerLocal>::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1000BBB0
// Name: public: void PlayerFriend::StartSearchForSessionInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::StartSearchForSessionInfo(PlayerFriend *this)
{
  __int64 v1; // rdi
  int v2; // eax

  HIDWORD(v1) = this->m_xuid;
  LODWORD(v1) = HIDWORD(this->m_xuid);
  if ( v1 != 0 && this->m_eSearchState == SEARCH_NONE )
  {
    this->m_eSearchState = SEARCH_QUEUED;
    v2 = 0;
    if ( s_arrSessionSearchesQueue.m_Size <= 0 )
      goto LABEL_8;
    while ( s_arrSessionSearchesQueue.m_Memory.m_pMemory[v2] != __PAIR64__(v1, HIDWORD(v1)) )
    {
      if ( ++v2 >= s_arrSessionSearchesQueue.m_Size )
        goto LABEL_8;
    }
    if ( v2 == -1 )
LABEL_8:
      CUtlVector<unsigned __int64,CUtlMemory<unsigned __int64,int>>::InsertBefore(
        this: &s_arrSessionSearchesQueue,
        elem: s_arrSessionSearchesQueue.m_Size,
        src: &this->m_xuid);
    PumpSessionSearchQueue();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BC60
// Name: public: virtual void PlayerLocal::UpdateAwardsData(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge PlayerLocal::UpdateAwardsData(PlayerLocal *this@<ecx>, const char *a2@<esi>, KeyValues *pAwardsData)
{
  const char *Name; // ebx
  IMatchTitle *v5; // eax
  const TitleAchievementsDescription_t *v6; // esi
  IMatchTitle *v7; // eax
  int v8; // eax
  int *m_pMemory; // ecx
  const char *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // ebx
  const char *v13; // eax
  int m_Size; // edx
  int v15; // eax
  int *v16; // ecx
  const char *v17; // eax
  int v18; // [esp-10h] [ebp-14h]
  int v19; // [esp-10h] [ebp-14h]
  const char *v20; // [esp-Ch] [ebp-10h]
  const char *v21; // [esp-Ch] [ebp-10h]
  KeyValues *kvValue; // [esp+Ch] [ebp+8h]

  for ( kvValue = KeyValues::GetFirstValue(this: pAwardsData);
        kvValue != nullptr;
        kvValue = KeyValues::GetNextValue(this: kvValue) )
  {
    Name = KeyValues::GetName(this: kvValue);
    if ( KeyValues::GetInt(this: kvValue, keyName: defaultValue, defaultValue: 0) != 0 )
    {
      v5 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
      v6 = v5->DescribeTitleAchievements(this: v5);
      if ( v6 != nullptr )
      {
        while ( v6->m_szAchievementName != nullptr )
        {
          if ( _V_stricmp(s1: Name, s2: v6->m_szAchievementName) == 0 )
          {
            v8 = 0;
            if ( this->m_arrAchievementsEarned.m_Size <= 0 )
              goto LABEL_21;
            m_pMemory = this->m_arrAchievementsEarned.m_Memory.m_pMemory;
            while ( *m_pMemory != v6->m_idAchievement )
            {
              ++v8;
              ++m_pMemory;
              if ( v8 >= this->m_arrAchievementsEarned.m_Size )
                goto LABEL_21;
            }
            if ( v8 == -1 )
            {
LABEL_21:
              if ( steamapicontext->m_pSteamUserStats->SetAchievement(
                     this: steamapicontext->m_pSteamUserStats,
                     a2: v6->m_szAchievementName) )
              {
                this->m_bSaveTitleData[0] = true;
                CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
                  this: &this->m_arrAchievementsEarned,
                  elem: this->m_arrAchievementsEarned.m_Size,
                  src: &v6->m_idAchievement);
                v10 = (const char *)((int (__thiscall *)(PlayerLocal *, const char *))this->GetName)(
                                      a1: this,
                                      a2: v6->m_szAchievementName);
                DevMsg(a1: "pPlayerLocal(%s)->UpdateAwardsData(%s) set achievement and stored stats.\n", v10, a2);
                v11 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                if ( v11 != nullptr )
                  v12 = KeyValues::KeyValues(this: v11, setName: "OnPlayerAward");
                else
                  v12 = nullptr;
                KeyValues::SetInt(this: v12, keyName: "iController", value: this->m_iController);
                KeyValues::SetString(this: v12, keyName: "award", value: v6->m_szAchievementName);
                a2 = (const char *)v12;
                ((void (__thiscall *)(CMatchEventsSubscription *))g_pMatchEventsSubscription->BroadcastEvent)(a1: g_pMatchEventsSubscription);
              }
              else
              {
                v19 = ((int (__thiscall *)(PlayerLocal *, const char *))this->GetName)(
                        a1: this,
                        a2: v6->m_szAchievementName);
                DevWarning(a1: "pPlayerLocal(%s)->UpdateAwardsData(%s) failed to set in Steam.\n", v19);
              }
            }
            else
            {
LABEL_27:
              v13 = (const char *)((int (__thiscall *)(PlayerLocal *, const char *))this->GetName)(
                                    a1: this,
                                    a2: v6->m_szAchievementName);
              DevMsg(a1: "pPlayerLocal(%s)->UpdateAwardsData(%s) already earned.\n", v13, v20);
            }
            goto LABEL_13;
          }
          if ( ++v6 == nullptr )
            break;
        }
      }
      if ( Name != nullptr )
      {
        v7 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
        v6 = (const TitleAchievementsDescription_t *)v7->DescribeTitleAvatarAwards(this: v7);
        if ( v6 != nullptr )
        {
          while ( v6->m_szAchievementName != nullptr )
          {
            if ( _V_stricmp(s1: Name, s2: v6->m_szAchievementName) == 0 )
            {
              m_Size = this->m_arrAvatarAwardsEarned.m_Size;
              v15 = 0;
              if ( m_Size <= 0 )
                goto LABEL_34;
              v16 = this->m_arrAvatarAwardsEarned.m_Memory.m_pMemory;
              while ( *v16 != v6->m_idAchievement )
              {
                ++v15;
                ++v16;
                if ( v15 >= m_Size )
                  goto LABEL_34;
              }
              if ( v15 == -1 )
              {
LABEL_34:
                v17 = (const char *)((int (__thiscall *)(PlayerLocal *, const char *))this->GetName)(
                                      a1: this,
                                      a2: v6->m_szAchievementName);
                DevMsg(a1: "pPlayerLocal(%s)->UpdateAwardsData(%s) NOT IMPLEMENTED ON THIS PLATFORM.\n", v17, v21);
                goto LABEL_13;
              }
              goto LABEL_27;
            }
            if ( ++v6 == nullptr )
              break;
          }
        }
        v18 = ((int (__thiscall *)(PlayerLocal *, const char *))this->GetName)(a1: this, a2: Name);
        DevWarning(a1: "pPlayerLocal(%s)->write_awards(%s) UNKNOWN NAME!\n", v18);
      }
    }
LABEL_13:
    ;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BEA0
// Name: protected: void PlayerLocal::EvaluateAwardsStateBasedOnStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::EvaluateAwardsStateBasedOnStats(PlayerLocal *this)
{
  IMatchTitle *v1; // eax
  const TitleDataFieldsDescription_t *v2; // eax
  IMatchFramework_vtbl *v3; // edx
  IMatchTitle *(__thiscall *GetMatchTitle)(IMatchFramework *); // eax
  int v5; // eax
  _DWORD *i; // edi
  int m_Size; // edx
  int v8; // eax
  int *m_pMemory; // ecx
  CFmtStrN<256> *v10; // eax
  const TitleDataFieldsDescription_t *v11; // eax
  int v12; // ebx
  bool v13; // zf
  $2CDD8C73E6C10214380560DA937D48A5 *v14; // esi
  int m_numBytesOffset; // ebx
  int v16; // eax
  char v17; // cl
  KeyValues *v18; // eax
  const char *v19; // eax
  IMatchTitle *v20; // eax
  int v21; // eax
  int v22; // ebx
  const char *v23; // edi
  const TitleDataFieldsDescription_t *v24; // esi
  _DWORD *v25; // ebx
  int v26; // edi
  int v27; // edx
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *v28; // esi
  int v29; // eax
  CUtlSymbolTable::StringPool_t **v30; // ecx
  int v31; // edi
  int v32; // eax
  CUtlSymbolTable::StringPool_t **v33; // ecx
  int v34; // eax
  CUtlSymbolTable::StringPool_t **v35; // eax
  const char *v36; // [esp-4h] [ebp-134h]
  CFmtStrN<256> v37; // [esp+Ch] [ebp-124h] BYREF
  int v38; // [esp+118h] [ebp-18h]
  KeyValues::AutoDelete autodelete_kvAwards; // [esp+11Ch] [ebp-14h]
  const TitleDataFieldsDescription_t *pTitleDataStorage; // [esp+120h] [ebp-10h]
  PlayerLocal *v41; // [esp+124h] [ebp-Ch]
  KeyValues *kvAwards; // [esp+128h] [ebp-8h]
  int numComponentsSet; // [esp+12Ch] [ebp-4h]

  v41 = this;
  v1 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  v2 = v1->DescribeTitleDataStorage(this: v1);
  v3 = g_pMatchFramework->__vftable;
  pTitleDataStorage = v2;
  GetMatchTitle = v3->GetMatchTitle;
  kvAwards = nullptr;
  autodelete_kvAwards.m_pKeyValues = nullptr;
  v5 = (int)GetMatchTitle(this: g_pMatchFramework);
  for ( i = (_DWORD *)(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 28))(a1: v5); i != nullptr; i += 3 )
  {
    if ( *i == 0 )
      break;
    if ( (int)i[2] > 1 )
    {
      m_Size = v41->m_arrAchievementsEarned.m_Size;
      v8 = 0;
      if ( m_Size <= 0 )
        goto LABEL_10;
      m_pMemory = v41->m_arrAchievementsEarned.m_Memory.m_pMemory;
      while ( *m_pMemory != i[1] )
      {
        ++v8;
        ++m_pMemory;
        if ( v8 >= m_Size )
          goto LABEL_10;
      }
      if ( v8 == -1 )
      {
LABEL_10:
        v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v37, pszFormat: "%s[1]", (const char *)*i);
        v11 = TitleDataFieldsDescriptionFindByString(fields: pTitleDataStorage, szString: v10->m_szBuf);
        v12 = 0;
        numComponentsSet = 0;
        v13 = i[2] == 0;
        if ( (int)i[2] > 0 )
        {
          v14 = &v11->___u3;
          while ( v14 != ($2CDD8C73E6C10214380560DA937D48A5 *)12
               && v14[-3].m_numBytesOffset != 0
               && v14[-1].m_numBytesOffset == 9 )
          {
            m_numBytesOffset = v14->m_numBytesOffset;
            v38 = (int)v41->GetPlayerTitleData(this: v41, a2: v14[-2].m_numBytesOffset);
            v16 = m_numBytesOffset / 8;
            v17 = m_numBytesOffset % 8;
            v12 = numComponentsSet;
            if ( ((unsigned __int8)(1 << v17) & *(_BYTE *)(v38 + v16)) != 0 )
            {
              v12 = numComponentsSet + 1;
              v14 += 4;
              numComponentsSet = v12;
              if ( v12 < i[2] )
                continue;
            }
            goto LABEL_19;
          }
          DevWarning(
            a1: "EvaluateAwardsStateBasedOnStats for achievement [%s] error: invalid component configuration (comp#%d)!\n",
            (const char *)*i,
            v12 + 1);
LABEL_19:
          v13 = v12 == i[2];
        }
        if ( v13 )
        {
          if ( kvAwards == nullptr )
          {
            v18 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v18 != nullptr )
              kvAwards = KeyValues::KeyValues(this: v18, setName: "write_award");
            else
              kvAwards = nullptr;
            autodelete_kvAwards.m_pKeyValues = kvAwards;
          }
          v19 = (const char *)((int (__thiscall *)(PlayerLocal *, _DWORD))v41->GetName)(a1: v41, a2: *i);
          DevMsg(a1: "PlayerLocal(%s)::EvaluateAwardsStateBasedOnStats is awarding %s\n", v19, v36);
          KeyValues::SetInt(this: kvAwards, keyName: (const char *)*i, value: 1);
        }
      }
    }
  }
  v20 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  v21 = (int)v20->DescribeTitleAvatarAwards(this: v20);
  if ( v21 != 0 )
  {
    v22 = v21 + 4;
    numComponentsSet = v21 + 4;
    do
    {
      if ( *(_DWORD *)(v22 - 4) == 0 )
        break;
      v23 = *(const char **)(v22 + 4);
      v24 = pTitleDataStorage;
      if ( v23 != nullptr && pTitleDataStorage != nullptr )
      {
        while ( v24->m_szFieldName != nullptr )
        {
          if ( _V_stricmp(s1: v24->m_szFieldName, s2: v23) == 0 )
          {
            v25 = &v41->__vftable;
            v26 = v24->m_numBytesOffset;
            if ( ((unsigned __int8)(1 << (v26 % 8))
                & *((_BYTE *)v41->GetPlayerTitleData(this: v41, a2: v24->m_iTitleDataBlock) + v26 / 8)) != 0 )
            {
              v27 = v25[62];
              v28 = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)(v25 + 59);
              v29 = 0;
              if ( v27 > 0 )
              {
                v30 = v28->m_pMemory;
                while ( *v30 != *(CUtlSymbolTable::StringPool_t **)numComponentsSet )
                {
                  ++v29;
                  ++v30;
                  if ( v29 >= v27 )
                    goto LABEL_47;
                }
                if ( v29 != -1 )
                {
                  if ( v29 != v27 - 1 )
                    v28->m_pMemory[v29] = v28->m_pMemory[v27 - 1];
                  --v25[62];
                }
              }
LABEL_47:
              v31 = v25[62];
              v32 = v25[60];
              if ( v31 + 1 > v32 )
                CUtlMemory<GCSDK::CLock *,int>::Grow(this: v28, num: v31 - v32 + 1);
              ++v25[62];
              v33 = v28->m_pMemory;
              v34 = v25[62] - v31 - 1;
              v25[63] = v25[59];
              if ( v34 > 0 )
                _V_memmove(dest: &v33[v31 + 1], src: &v33[v31], count: 4 * v34);
              v35 = &v28->m_pMemory[v31];
              if ( v35 != nullptr )
                *v35 = *(CUtlSymbolTable::StringPool_t **)numComponentsSet;
            }
            v22 = numComponentsSet;
            break;
          }
          if ( ++v24 == nullptr )
            break;
        }
      }
      v22 += 12;
      numComponentsSet = v22;
    }
    while ( v22 != 4 );
  }
  v41->UpdateAwardsData(this: v41, a2: kvAwards);
  if ( autodelete_kvAwards.m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: autodelete_kvAwards.m_pKeyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1000C1C0
// Name: public: virtual void PlayerFriend::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::Update(PlayerFriend *this)
{
  KeyValues *v2; // edi
  KeyValues *v3; // eax
  unsigned __int64 v4; // rax
  IMatchEventsSubscription *v5; // eax

  if ( this->m_xuid != 0 && this->m_eSearchState == SEARCH_COMPLETED )
  {
    --s_numSearchesOutstanding;
    v2 = nullptr;
    this->m_eSearchState = SEARCH_NONE;
    PumpSessionSearchQueue();
    if ( _V_memcmp(m1: &this->m_GameSessionInfo, m2: &this->m_xSessionID, count: 8) != 0 )
      PlayerFriend::StartSearchForSessionInfo(this);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v2 = KeyValues::KeyValues(this: v3, setName: "OnMatchPlayerMgrUpdate", firstKey: "update", firstValue: "friend");
    v4 = this->GetXUID(this);
    KeyValues::SetUint64(this: v2, keyName: "xuid", value: v4);
    v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v5->BroadcastEvent(this: v5, a2: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C270
// Name: public: void PlayerFriend::UpdateFriendInfo(struct PlayerFriend::FriendInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerFriend::UpdateFriendInfo(PlayerFriend *this, const PlayerFriend::FriendInfo_t *pFriendInfo)
{
  const wchar_t *m_wszRichPresence; // eax
  KeyValues *m_pDetails; // ecx
  KeyValues *Copy; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // edi
  unsigned __int64 v8; // rax
  IMatchEventsSubscription *v9; // eax
  IMatchTitle *v10; // eax
  int v11; // edx
  KeyValues *v12; // ecx
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  bool v15; // zf

  if ( pFriendInfo != nullptr )
  {
    if ( pFriendInfo->m_szName != nullptr )
      V_strncpy(pDest: this->m_szName, pSrc: pFriendInfo->m_szName, maxLen: 32);
    m_wszRichPresence = pFriendInfo->m_wszRichPresence;
    if ( m_wszRichPresence != nullptr )
      V_wcsncpy(pDest: this->m_wszRichPresence, pSrc: m_wszRichPresence, maxLenInBytes: 64);
    if ( cl_names_debug.m_pParent != nullptr && cl_names_debug.m_pParent->m_Value.m_nValue != 0 )
      V_strncpy(pDest: this->m_szName, pSrc: "WWWWWWWWWWWWWWW", maxLen: 32);
    if ( pFriendInfo->m_pGameDetails != nullptr )
    {
      PlayerFriend::AbortSearch(this);
      m_pDetails = this->m_pDetails;
      if ( m_pDetails != nullptr )
        KeyValues::deleteThis(this: m_pDetails);
      Copy = KeyValues::MakeCopy(this: pFriendInfo->m_pGameDetails);
      this->m_pDetails = Copy;
      this->m_xSessionID = (XNKID)KeyValues::GetUint64(this: Copy, keyName: "options/sessionid", defaultValue: 0);
      v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v6 != nullptr )
        v7 = KeyValues::KeyValues(this: v6, setName: "OnMatchPlayerMgrUpdate", firstKey: "update", firstValue: "friend");
      else
        v7 = nullptr;
      v8 = this->GetXUID(this);
      KeyValues::SetUint64(this: v7, keyName: "xuid", value: v8);
      v9 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v9->BroadcastEvent(this: v9, a2: v7);
    }
    else if ( pFriendInfo->m_uiTitleID == 0
           || (v10 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework),
               LODWORD(pFriendInfo->m_uiTitleID) == v10->GetTitleID(this: v10))
           && HIDWORD(pFriendInfo->m_uiTitleID) == v11 )
    {
      v15 = this->m_eSearchState == SEARCH_NONE;
      this->m_xSessionID = pFriendInfo->m_xSessionID;
      if ( v15 )
        PlayerFriend::StartSearchForSessionInfo(this);
    }
    else
    {
      v12 = this->m_pDetails;
      if ( v12 != nullptr )
        KeyValues::deleteThis(this: v12);
      v13 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v13 != nullptr )
        v14 = KeyValues::KeyValues(this: v13, setName: "TitleSettings");
      else
        v14 = nullptr;
      this->m_pDetails = v14;
      KeyValues::SetUint64(this: v14, keyName: "titleid", value: pFriendInfo->m_uiTitleID);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C420
// Name: protected: void PlayerLocal::Steam_OnUserStatsReceived(struct UserStatsReceived_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge PlayerLocal::Steam_OnUserStatsReceived(
        PlayerLocal *this@<ecx>,
        float a2@<xmm1>,
        UserStatsReceived_t *pParam)
{
  PlayerLocal *v3; // esi
  UserStatsReceived_t *v4; // edi
  double v5; // xmm0_8
  EResult m_eResult; // eax
  IMatchTitle *(__thiscall *GetMatchTitle)(IMatchFramework *); // edx
  int v8; // eax
  int i; // ebx
  IMatchTitle *v10; // eax
  int v11; // eax
  _DWORD *v12; // esi
  const char *v13; // edi
  unsigned int v14; // ebx
  int *v15; // edi
  int v16; // edi
  KeyValues *v17; // eax
  KeyValues *v18; // eax
  unsigned int m_uiPlayerFlags; // eax
  KeyValues *v20; // eax
  KeyValues *v21; // esi
  IMatchEventsSubscription *v22; // eax
  char chBuffer[256]; // [esp+10h] [ebp-16Ch] BYREF
  char chStatField[64]; // [esp+110h] [ebp-6Ch] BYREF
  bool v25[4]; // [esp+150h] [ebp-2Ch]
  bool v26[4]; // [esp+154h] [ebp-28h]
  bool bResult[4]; // [esp+158h] [ebp-24h]
  bool v28[4]; // [esp+15Ch] [ebp-20h]
  int pValue[2]; // [esp+160h] [ebp-1Ch] BYREF
  unsigned int i32field[3]; // [esp+168h] [ebp-14h] BYREF
  int iCombinedBitValue; // [esp+174h] [ebp-8h] BYREF
  PlayerLocal *v32; // [esp+178h] [ebp-4h]

  v3 = this;
  v4 = pParam;
  v32 = this;
  if ( !s_bSteamStatsRequestFailed || pParam->m_eResult == k_EResultOK )
  {
    if ( s_flSteamStatsRequestTime == 0.0 )
    {
      v5 = 0.0;
    }
    else
    {
      *(double *)pValue = _Plat_FloatTime() - s_flSteamStatsRequestTime;
      v5 = *(double *)pValue;
    }
    DevMsg(a1: "PlayerLocal::Steam_OnUserStatsReceived... (%2.2f sec since request)\n", v5);
  }
  m_eResult = v4->m_eResult;
  s_flSteamStatsRequestTime = 0.0;
  if ( m_eResult == k_EResultOK )
  {
    GetMatchTitle = g_pMatchFramework->GetMatchTitle;
    s_bSteamStatsRequestFailed = false;
    v8 = (int)GetMatchTitle(this: g_pMatchFramework);
    for ( i = (*(int (__thiscall **)(int))(*(_DWORD *)v8 + 28))(a1: v8); i != 0; i += 12 )
    {
      if ( *(_DWORD *)i == 0 )
        break;
      if ( steamapicontext->m_pSteamUserStats->GetAchievement(
             this: steamapicontext->m_pSteamUserStats,
             a2: *(const char **)i,
             a3: (bool *)&pParam + 3)
        && HIBYTE(pParam) != 0 )
      {
        v3 = v32;
        CUtlVector<int,CUtlMemory<int,int>>::FindAndFastRemove(
          this: (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&v32->m_arrAchievementsEarned,
          src: (CServer **)(i + 4));
        CUtlVector<int,CUtlMemory<int,int>>::InsertBefore(
          this: &v3->m_arrAchievementsEarned,
          elem: v3->m_arrAchievementsEarned.m_Size,
          src: (int *)(i + 4));
      }
    }
    v10 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    v11 = (int)v10->DescribeTitleDataStorage(this: v10);
    if ( v11 != 0 )
    {
      v12 = (_DWORD *)(v11 + 8);
      do
      {
        v13 = (const char *)*(v12 - 2);
        if ( v13 == nullptr )
          break;
        switch ( *v12 )
        {
          case 8:
          case 0x10:
          case 0x20:
            memset(i32field, 0, sizeof(i32field));
            bResult[0] = steamapicontext->m_pSteamUserStats->GetStat_2(
                           this: steamapicontext->m_pSteamUserStats,
                           a2: v13,
                           a3: (int *)i32field);
            if ( ApplySteamStatPotentialOverride_int_(
                   szField: v13,
                   pValue: (int *)i32field,
                   bResult: bResult[0],
                   pfn: KeyValues::GetInt) )
            {
              LOWORD(i32field[1]) = i32field[0];
              LOBYTE(i32field[2]) = i32field[0];
              memcpy(
                dst: (unsigned __int8 *)&v32->m_bufTitleData[*(v12 - 1)][v12[1]],
                src: (unsigned __int8 *)&i32field[-(*v12 / 16) + 2],
                count: *v12 / 8);
            }
            break;
          case 9:
            memset(chStatField, 0, sizeof(chStatField));
            v16 = v12[1] / 32;
            V_snprintf(pDest: chStatField, maxLen: 64, pFormat: "bitfield_%02u_%03X", *(v12 - 1) + 1, 4 * v16);
            iCombinedBitValue = 0;
            v26[0] = steamapicontext->m_pSteamUserStats->GetStat_2(
                       this: steamapicontext->m_pSteamUserStats,
                       a2: chStatField,
                       a3: &iCombinedBitValue);
            if ( ApplySteamStatPotentialOverride_int_(
                   szField: chStatField,
                   pValue: &iCombinedBitValue,
                   bResult: v26[0],
                   pfn: KeyValues::GetInt) )
            {
              *(_DWORD *)&v32->m_bufTitleData[*(v12 - 1)][4 * v16] = iCombinedBitValue;
            }
            break;
          case 0x21:
            pParam = nullptr;
            v25[0] = steamapicontext->m_pSteamUserStats->GetStat(
                       this: steamapicontext->m_pSteamUserStats,
                       a2: v13,
                       a3: (float *)&pParam);
            if ( ApplySteamStatPotentialOverride_float_(
                   a1: a2,
                   szField: v13,
                   pValue: (float *)&pParam,
                   bResult: v25[0],
                   pfn: KeyValues::GetFloat) )
            {
              memcpy(
                dst: (unsigned __int8 *)&v32->m_bufTitleData[*(v12 - 1)][v12[1]],
                src: (unsigned __int8 *)&pParam,
                count: *v12 / 8);
            }
            break;
          case 0x40:
            v14 = 0;
            pValue[0] = 0;
            pValue[1] = 0;
            memset(chBuffer, 0, sizeof(chBuffer));
            v15 = pValue;
            do
            {
              V_snprintf(pDest: chBuffer, maxLen: 256, pFormat: "%s.%d", (const char *)*(v12 - 2), v14);
              v28[0] = steamapicontext->m_pSteamUserStats->GetStat_2(
                         this: steamapicontext->m_pSteamUserStats,
                         a2: chBuffer,
                         a3: v15);
              if ( !ApplySteamStatPotentialOverride_int_(
                      szField: chBuffer,
                      pValue: v15,
                      bResult: v28[0],
                      pfn: KeyValues::GetInt) )
                *v15 = 0;
              ++v14;
              ++v15;
            }
            while ( v14 < 2 );
            memcpy(
              dst: (unsigned __int8 *)&v32->m_bufTitleData[*(v12 - 1)][v12[1]],
              src: (unsigned __int8 *)pValue,
              count: *v12 / 8);
            break;
          default:
            break;
        }
        v12 += 4;
      }
      while ( v12 != (_DWORD *)8 );
      v3 = v32;
    }
    PlayerLocal::EvaluateAwardsStateBasedOnStats(this: v3);
    if ( mm_cfgoverride_commit.m_pParent != nullptr && mm_cfgoverride_commit.m_pParent->m_Value.m_nValue != 0 )
      steamapicontext->m_pSteamUserStats->StoreStats(this: steamapicontext->m_pSteamUserStats);
    DevMsg(a1: "User%d stats retrieved.\n", v3->m_iController);
    v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v17 != nullptr )
      v18 = KeyValues::KeyValues(
              this: v17,
              setName: "OnProfileDataLoaded",
              firstKey: "iController",
              firstValue: v3->m_iController);
    else
      v18 = nullptr;
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v18);
    m_uiPlayerFlags = v3->m_uiPlayerFlags;
    if ( (m_uiPlayerFlags & 1) != 0 )
    {
      v3->m_uiPlayerFlags = m_uiPlayerFlags & 0xFFFFFFFE;
      v20 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v20 != nullptr )
        v21 = KeyValues::KeyValues(this: v20, setName: "OnInvite", firstKey: "action", firstValue: "join");
      else
        v21 = nullptr;
      v22 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v22->BroadcastEvent(this: v22, a2: v21);
    }
  }
  else
  {
    if ( !s_bSteamStatsRequestFailed )
    {
      DevWarning(a1: "PlayerLocal::Steam_OnUserStatsReceived (failed with error %d)\n", m_eResult);
      s_bSteamStatsRequestFailed = true;
    }
    v3->m_eLoadedTitleData = eXUserSigninState_NotSignedIn;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C8D0
// Name: public: virtual void PlayerLocal::UpdatePlayerTitleData(struct TitleDataFieldsDescription_t const __near *,void const __near *,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall PlayerLocal::UpdatePlayerTitleData(
        PlayerLocal *this,
        const TitleDataFieldsDescription_t *fdKey,
        unsigned __int8 *pvNewTitleData,
        unsigned int numNewBytes)
{
  PlayerLocal *v5; // edi
  ISteamUtils *m_pSteamUtils; // ecx
  TitleDataFieldsDescription_t::DataType_t m_eDataType; // kr00_4
  const char *v9; // eax
  const char *v10; // eax
  const char *v11; // eax
  unsigned int v12; // eax
  unsigned __int8 *v13; // ecx
  unsigned __int8 *v14; // edx
  void *v15; // esp
  int m_numBytesOffset; // eax
  unsigned __int8 v17; // bl
  TitleDataFieldsDescription_t::DataType_t v18; // ebx
  unsigned int i; // ebx
  int v20; // ebx
  int v21; // eax
  int v22; // [esp-8h] [ebp-174h]
  int v23; // [esp-8h] [ebp-174h]
  const char *v24; // [esp+4h] [ebp-168h]
  const char *v25; // [esp+4h] [ebp-168h]
  const char *v26; // [esp+4h] [ebp-168h]
  int v27; // [esp+8h] [ebp-164h]
  int v28; // [esp+8h] [ebp-164h]
  int v29; // [esp+8h] [ebp-164h]
  unsigned __int8 *v30; // [esp+8h] [ebp-164h]
  unsigned __int8 *v31; // [esp+8h] [ebp-164h]
  int v32; // [esp+Ch] [ebp-160h]
  int v33; // [esp+Ch] [ebp-160h]
  int v34; // [esp+Ch] [ebp-160h]
  unsigned __int8 v35[12]; // [esp+10h] [ebp-15Ch] BYREF
  char chBuffer[256]; // [esp+1Ch] [ebp-150h] BYREF
  char chStatField[64]; // [esp+11Ch] [ebp-50h] BYREF
  _BYTE i32field[12]; // [esp+15Ch] [ebp-10h] OVERLAPPED BYREF
  unsigned __int8 *dst; // [esp+168h] [ebp-4h] BYREF
  unsigned __int8 *bBitValue; // [esp+174h] [ebp+8h]
  bool bBitValue_3; // [esp+177h] [ebp+Bh]
  unsigned __int8 *pvData; // [esp+178h] [ebp+Ch]
  unsigned __int8 *pvDataa; // [esp+178h] [ebp+Ch]

  v5 = this;
  dst = (unsigned __int8 *)this;
  if ( fdKey != nullptr
    && fdKey->m_eDataType != DT_0
    && pvNewTitleData != nullptr
    && (int)numNewBytes > 0
    && fdKey->m_szFieldName != nullptr
    && fdKey->m_iTitleDataBlock <= (unsigned int)DB_TD3 )
  {
    m_pSteamUtils = steamapicontext->m_pSteamUtils;
    if ( m_pSteamUtils != nullptr )
      m_pSteamUtils->GetConnectedUniverse(this: m_pSteamUtils);
    m_eDataType = fdKey->m_eDataType;
    if ( m_eDataType / 8 != numNewBytes )
    {
      DevWarning(
        a1: "PlayerLocal::UpdatePlayerTitleData( %s ) new data size %d != description size %d!\n",
        fdKey->m_szFieldName,
        numNewBytes,
        m_eDataType / 8);
      return;
    }
    switch ( fdKey->m_eDataType )
    {
      case DT_uint8:
      case DT_BITFIELD:
        v9 = (const char *)((int (__thiscall *)(PlayerLocal *, const char *, _DWORD, _DWORD))v5->GetName)(
                             a1: v5,
                             a2: fdKey->m_szFieldName,
                             a3: *pvNewTitleData,
                             a4: *pvNewTitleData);
        DevMsg(a1: "PlayerLocal(%s)::UpdatePlayerTitleData: %s = %d (0x%02X)\n", v9, v24, v27, v32);
        break;
      case DT_uint16:
        v10 = (const char *)((int (__thiscall *)(PlayerLocal *, const char *, _DWORD, _DWORD))v5->GetName)(
                              a1: v5,
                              a2: fdKey->m_szFieldName,
                              a3: *(unsigned __int16 *)pvNewTitleData,
                              a4: *(unsigned __int16 *)pvNewTitleData);
        DevMsg(a1: "PlayerLocal(%s)::UpdatePlayerTitleData: %s = %d (0x%04X)\n", v10, v25, v28, v33);
        break;
      case DT_uint32:
        v11 = (const char *)((int (__thiscall *)(PlayerLocal *, const char *, _DWORD, _DWORD))v5->GetName)(
                              a1: v5,
                              a2: fdKey->m_szFieldName,
                              a3: *(_DWORD *)pvNewTitleData,
                              a4: *(_DWORD *)pvNewTitleData);
        DevMsg(a1: "PlayerLocal(%s)::UpdatePlayerTitleData: %s = %d (0x%08X)\n", v11, v26, v29, v34);
        break;
      case DT_float:
        v23 = ((int (__thiscall *)(PlayerLocal *, const char *, _DWORD, _DWORD, _DWORD, _DWORD))v5->GetName)(
                a1: v5,
                a2: fdKey->m_szFieldName,
                a3: COERCE_UNSIGNED_INT64(*(float *)pvNewTitleData),
                a4: HIDWORD(COERCE_UNSIGNED_INT64(*(float *)pvNewTitleData)),
                a5: COERCE_UNSIGNED_INT64(*(float *)pvNewTitleData),
                a6: HIDWORD(COERCE_UNSIGNED_INT64(*(float *)pvNewTitleData)));
        DevMsg(a1: "PlayerLocal(%s)::UpdatePlayerTitleData: %s = %f (%0.2f)\n", v23);
        break;
      case DT_uint64:
        v22 = ((int (__thiscall *)(PlayerLocal *, const char *, _DWORD, _DWORD, _DWORD, _DWORD))v5->GetName)(
                a1: v5,
                a2: fdKey->m_szFieldName,
                a3: *(_DWORD *)pvNewTitleData,
                a4: *((_DWORD *)pvNewTitleData + 1),
                a5: *(_DWORD *)pvNewTitleData,
                a6: *((_DWORD *)pvNewTitleData + 1));
        DevMsg(a1: "PlayerLocal(%s)::UpdatePlayerTitleData: %s = %llu (0x%llX)\n", v22);
        break;
      default:
        break;
    }
    v12 = numNewBytes;
    pvData = (unsigned __int8 *)v5->m_bufTitleData[fdKey->m_iTitleDataBlock];
    if ( fdKey->m_eDataType == DT_BITFIELD )
    {
      v15 = alloca(numNewBytes);
      m_numBytesOffset = fdKey->m_numBytesOffset;
      bBitValue_3 = *pvNewTitleData != 0;
      v17 = 1 << (fdKey->m_numBytesOffset % 8);
      memcpy(dst: v35, src: &pvData[m_numBytesOffset / 8], count: numNewBytes);
      if ( ((v35[0] & v17) != 0) == bBitValue_3 )
        return;
      if ( bBitValue_3 )
        v35[0] |= v17;
      else
        v35[0] &= ~v17;
      memcpy(dst: &pvData[fdKey->m_numBytesOffset / 8], src: v35, count: numNewBytes);
      v5 = (PlayerLocal *)dst;
    }
    else
    {
      v13 = (unsigned __int8 *)&v5->m_bufTitleData[fdKey->m_iTitleDataBlock][fdKey->m_numBytesOffset];
      bBitValue = pvNewTitleData;
      dst = v13;
      pvDataa = v13;
      v14 = pvNewTitleData;
      if ( numNewBytes < 4 )
      {
LABEL_22:
        if ( v12 == 0 || *v14 == *v13 && (v12 <= 1 || bBitValue[1] == v13[1] && (v12 <= 2 || bBitValue[2] == v13[2])) )
          return;
      }
      else
      {
        while ( *(_DWORD *)v13 == *(_DWORD *)v14 )
        {
          v12 -= 4;
          v13 = pvDataa + 4;
          v14 += 4;
          pvDataa += 4;
          if ( v12 < 4 )
          {
            bBitValue = v14;
            goto LABEL_22;
          }
        }
      }
      memcpy(dst, src: pvNewTitleData, count: numNewBytes);
    }
    v5->m_bSaveTitleData[fdKey->m_iTitleDataBlock] = true;
    v18 = fdKey->m_eDataType;
    switch ( v18 )
    {
      case DT_uint8:
      case DT_uint16:
      case DT_uint32:
        v30 = (unsigned __int8 *)&v5->m_bufTitleData[fdKey->m_iTitleDataBlock][fdKey->m_numBytesOffset];
        *(_QWORD *)&i32field[4] = 0;
        dst = nullptr;
        memcpy((unsigned __int8 *)&dst, src: v30, count: v18 / 8);
        *(_DWORD *)i32field = dst;
        *(_DWORD *)&i32field[8] = (unsigned __int8)dst;
        *(_DWORD *)&i32field[4] = (unsigned __int16)dst;
        SetSteamStatWithPotentialOverride(
          szField: fdKey->m_szFieldName,
          iValue: *(_DWORD *)&i32field[-4 * (v18 / 16) + 8]);
        break;
      case DT_BITFIELD:
        memset(chStatField, 0, sizeof(chStatField));
        v20 = fdKey->m_numBytesOffset / 32;
        V_snprintf(pDest: chStatField, maxLen: 64, pFormat: "bitfield_%02u_%03X", fdKey->m_iTitleDataBlock + 1, 4 * v20);
        SetSteamStatWithPotentialOverride(
          szField: chStatField,
          iValue: *(_DWORD *)&v5->m_bufTitleData[fdKey->m_iTitleDataBlock][4 * v20]);
        break;
      case DT_float:
        v31 = (unsigned __int8 *)&v5->m_bufTitleData[fdKey->m_iTitleDataBlock][fdKey->m_numBytesOffset];
        numNewBytes = 0;
        memcpy(dst: (unsigned __int8 *)&numNewBytes, src: v31, count: v18 / 8);
        SetSteamStatWithPotentialOverride_0(a1: numNewBytes, szField: fdKey->m_szFieldName);
        break;
      case DT_uint64:
        *(_DWORD *)&i32field[8] = 0;
        dst = nullptr;
        memcpy(
          dst: &i32field[8],
          src: (unsigned __int8 *)&v5->m_bufTitleData[fdKey->m_iTitleDataBlock][fdKey->m_numBytesOffset],
          count: v18 / 8);
        memset(chBuffer, 0, sizeof(chBuffer));
        for ( i = 0; i < 2; ++i )
        {
          V_snprintf(pDest: chBuffer, maxLen: 256, pFormat: "%s.%d", fdKey->m_szFieldName, i);
          SetSteamStatWithPotentialOverride(szField: chBuffer, iValue: *(_DWORD *)&i32field[4 * i + 8]);
        }
        break;
      default:
        break;
    }
    v21 = _V_strlen(str: fdKey->m_szFieldName);
    if ( v21 > 0 && fdKey->m_szFieldName[v21 - 1] == 93 )
      PlayerLocal::EvaluateAwardsStateBasedOnStats(this: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CE10
// Name: public: PlayerFriend::PlayerFriend(unsigned __int64,struct PlayerFriend::FriendInfo_t const __near *)
// Source: json
//------------------------------------------------------------------------------
PlayerFriend *__thiscall PlayerFriend::PlayerFriend(
        PlayerFriend *this,
        unsigned __int64 xuid,
        const PlayerFriend::FriendInfo_t *pFriendInfo)
{
  this->m_iController = 254;
  *(_QWORD *)this->m_szName = 0;
  *(_QWORD *)&this->m_szName[8] = 0;
  *(_QWORD *)&this->m_szName[16] = 0;
  *(_QWORD *)&this->m_szName[24] = 0;
  this->__vftable = (PlayerFriend_vtbl *)&PlayerFriend::`vftable';
  this->m_uFriendMark = 0;
  this->m_bIsStale = false;
  this->m_pDetails = nullptr;
  this->m_eSearchState = SEARCH_NONE;
  this->m_CallbackOnLobbyDataUpdate.m_nCallbackFlags = 0;
  this->m_CallbackOnLobbyDataUpdate.m_iCallback = 0;
  this->m_CallbackOnLobbyDataUpdate.m_pObj = nullptr;
  this->m_CallbackOnLobbyDataUpdate.m_Func = nullptr;
  this->m_CallbackOnLobbyDataUpdate.__vftable = (CCallbackManual<PlayerFriend,LobbyDataUpdate_t,0>_vtbl *)&CCallbackManual<PlayerFriend,LobbyDataUpdate_t,0>::`vftable';
  memset(dst: (unsigned __int8 *)this->m_wszRichPresence, value: 0, count: sizeof(this->m_wszRichPresence));
  this->m_xSessionID = 0;
  memset(dst: this->m_GameSessionInfo.sessionID.ab, value: 0, count: 0x3Cu);
  this->m_xuid = xuid;
  this->m_eOnlineState = STATE_ONLINE;
  PlayerFriend::UpdateFriendInfo(this, pFriendInfo);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000CF20
// Name: public: void PlayerLocal::LoadTitleData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::LoadTitleData(PlayerLocal *this)
{
  bool v2; // zf
  XUSER_SIGNIN_STATE v3; // eax
  XUSER_SIGNIN_STATE v4; // eax
  double v5; // st7

  if ( this->m_eLoadedTitleData != eXUserSigninState_SignedInToLive )
  {
    if ( steamapicontext->m_pSteamUser == nullptr
      || (v2 = !steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser),
          v3 = eXUserSigninState_SignedInToLive,
          v2) )
    {
      v3 = eXUserSigninState_SignedInLocally;
    }
    if ( this->m_eLoadedTitleData < v3 && steamapicontext->m_pSteamUserStats != nullptr )
    {
      if ( steamapicontext->m_pSteamUser == nullptr
        || (v2 = !steamapicontext->m_pSteamUser->BLoggedOn(this: steamapicontext->m_pSteamUser),
            v4 = eXUserSigninState_SignedInToLive,
            v2) )
      {
        v4 = eXUserSigninState_SignedInLocally;
      }
      this->m_eLoadedTitleData = v4;
      CCallback<PlayerLocal,UserStatsReceived_t,0>::Register(
        this: &this->m_CallbackOnUserStatsReceived,
        pObj: this,
        func: (void (__thiscall *)(PlayerLocal *, UserStatsReceived_t *))PlayerLocal::Steam_OnUserStatsReceived);
      steamapicontext->m_pSteamUserStats->RequestCurrentStats(this: steamapicontext->m_pSteamUserStats);
      s_flSteamStatsRequestTime = _Plat_FloatTime();
      if ( !s_bSteamStatsRequestFailed )
      {
        v5 = _Plat_FloatTime();
        DevMsg(a1: "Requesting Steam stats... (%2.2f)\n", v5);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CFE0
// Name: public: virtual void PlayerLocal::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::Update(PlayerLocal *this)
{
  double v2; // st7

  PlayerLocal::LoadTitleData(this);
  PlayerLocal::WriteTitleData(this);
  if ( s_flSteamStatsRequestTime != 0.0 && _Plat_FloatTime() - s_flSteamStatsRequestTime > 10.0 )
  {
    v2 = _Plat_FloatTime();
    DevWarning(
      a1: "=========== Failed to retrieve Steam stats (%2.2f sec) =================\n",
      v2 - s_flSteamStatsRequestTime);
    steamapicontext->m_pSteamUserStats->RequestCurrentStats(this: steamapicontext->m_pSteamUserStats);
    s_flSteamStatsRequestTime = _Plat_FloatTime();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D060
// Name: public: CExpressionCalculator::~CExpressionCalculator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpressionCalculator::~CExpressionCalculator(CExpressionCalculator *this)
{
  bool v2; // sf

  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_stack);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_varValues);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::~CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>(this: &this->m_varNames);
  v2 = this->m_expr.m_Storage.m_Memory.m_nGrowSize < 0;
  this->m_expr.m_Storage.m_nActualLength = 0;
  if ( !v2 )
  {
    if ( this->m_expr.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_expr.m_Storage.m_Memory.m_pMemory);
      this->m_expr.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_expr.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D0B0
// Name: public: virtual void PlayerLocal::UpdatePlayerMatchmakingData(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::UpdatePlayerMatchmakingData(PlayerLocal *this, unsigned int mmDataType)
{
  unsigned int v2; // esi
  int v4; // eax
  IMatchTitleGameSettingsMgr *v5; // eax
  const char *v6; // eax
  int value; // [esp+4h] [ebp-5Ch]
  float valuea; // [esp+4h] [ebp-5Ch]
  CExpressionCalculator calc; // [esp+10h] [ebp-50h] BYREF

  v2 = mmDataType;
  if ( mmDataType > 1 )
  {
    DevMsg(a1: "Invalid matchmaking data type passed to UpdatePlayerMatchmakingData ( %d )", mmDataType);
  }
  else
  {
    v4 = ((int (__thiscall *)(PlayerLocal *, unsigned int))this->GetPlayerIndex)(a1: this, a2: mmDataType);
    DevMsg(a1: "Player::UpdatePlayerMatchmakingData( ctrlr%d; mmDataType%d )\n", v4, value);
    v5 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
    v6 = v5->GetFormulaAverage(this: v5, a2: v2);
    CUtlString::CUtlString(this: &calc.m_expr, pString: v6);
    valuea = (float)this->m_MatchmakingData.mContribution[v2][0];
    memset(&calc.m_varNames, 0, 60);
    CExpressionCalculator::SetVariable(this: &calc, var: "avgValue", value: valuea);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mContribution[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mContribution[v2][0] = (int)*(float *)&mmDataType;
    CExpressionCalculator::SetVariable(this: &calc, var: "avgValue", value: (float)this->m_MatchmakingData.mMVPs[v2][0]);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mMVPs[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mMVPs[v2][0] = (int)*(float *)&mmDataType;
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "avgValue",
      value: (float)this->m_MatchmakingData.mKills[v2][0]);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mKills[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mKills[v2][0] = (int)*(float *)&mmDataType;
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "avgValue",
      value: (float)this->m_MatchmakingData.mDeaths[v2][0]);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mDeaths[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mDeaths[v2][0] = (int)*(float *)&mmDataType;
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "avgValue",
      value: (float)this->m_MatchmakingData.mHeadShots[v2][0]);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mHeadShots[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mHeadShots[v2][0] = (int)*(float *)&mmDataType;
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "avgValue",
      value: (float)this->m_MatchmakingData.mDamage[v2][0]);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mDamage[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mDamage[v2][0] = (int)*(float *)&mmDataType;
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "avgValue",
      value: (float)this->m_MatchmakingData.mShotsFired[v2][0]);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mShotsFired[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mShotsFired[v2][0] = (int)*(float *)&mmDataType;
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "avgValue",
      value: (float)this->m_MatchmakingData.mShotsHit[v2][0]);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mShotsHit[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mShotsHit[v2][0] = (int)*(float *)&mmDataType;
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "avgValue",
      value: (float)this->m_MatchmakingData.mDominations[v2][0]);
    CExpressionCalculator::SetVariable(
      this: &calc,
      var: "newValue",
      value: (float)this->m_MatchmakingData.mDominations[v2][1] * 100.0);
    if ( CExpressionCalculator::Evaluate(this: &calc, value: (float *)&mmDataType) )
      this->m_MatchmakingData.mDominations[v2][0] = (int)*(float *)&mmDataType;
    ++this->m_MatchmakingData.mRoundsPlayed[v2][0];
    ++this->m_MatchmakingData.mRoundsPlayed[v2][1];
    CExpressionCalculator::~CExpressionCalculator(this: &calc);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DFD0
// Name: public: void PlayerLocal::RecomputeXUID(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerLocal::RecomputeXUID(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10031BB0
// Name: public: int CUtlStack<float,class CUtlMemory<float,int>>::Push(float const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlStack<float,CUtlMemory<float,int>>::Push(CUtlStack<float,CUtlMemory<float,int> > *this, float *src)
{
  float *m_pMemory; // eax
  int m_Size; // ecx
  float *v5; // eax

  if ( this->m_Size >= this->m_Memory.m_nAllocationCount )
    CUtlMemory<GCSDK::CLock *,int>::Grow((CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)this, num: 1);
  ++this->m_Size;
  m_pMemory = this->m_Memory.m_pMemory;
  m_Size = this->m_Size;
  this->m_pElements = this->m_Memory.m_pMemory;
  v5 = &m_pMemory[m_Size - 1];
  if ( v5 != nullptr )
    *v5 = *src;
  return this->m_Size - 1;
}
