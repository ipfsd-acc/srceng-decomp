// Original: matchmaking/playermanager.cpp
// Functions: stubbed / inlined in this build
// ============================================================

#include "matchmaking\playermanager.h"

// Stub: dynamic initializer for 'k_steamIDNil''
void dynamic initializer for 'k_steamIDNil''() {}

// Stub: dynamic initializer for 'k_steamIDOutofDateGS''
void dynamic initializer for 'k_steamIDOutofDateGS''() {}

// Stub: dynamic initializer for 'k_steamIDLanModeGS''
void dynamic initializer for 'k_steamIDLanModeGS''() {}

// Stub: dynamic initializer for 'k_steamIDNotInitYetGS''
void dynamic initializer for 'k_steamIDNotInitYetGS''() {}

// Stub: dynamic initializer for 'k_steamIDNonSteamGS''
void dynamic initializer for 'k_steamIDNonSteamGS''() {}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x10005860
// Name: struct TitleDataFieldsDescription_t const __near * TitleDataFieldsDescriptionFindByString(struct TitleDataFieldsDescription_t const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const TitleDataFieldsDescription_t *__cdecl TitleDataFieldsDescriptionFindByString(
        const TitleDataFieldsDescription_t *fields,
        const char *szString)
{
  const TitleDataFieldsDescription_t *v3; // esi

  if ( szString == nullptr )
    return nullptr;
  v3 = fields;
  if ( fields != nullptr )
  {
    while ( v3->m_szFieldName != nullptr )
    {
      if ( _V_stricmp(s1: v3->m_szFieldName, s2: szString) == 0 )
        return v3;
      if ( ++v3 == nullptr )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100058A0
// Name: bool TitleDataFieldsDescriptionGetBit(struct TitleDataFieldsDescription_t const __near *,class IPlayerLocal __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl TitleDataFieldsDescriptionGetBit(const TitleDataFieldsDescription_t *fdKey, IPlayerLocal *pPlayer)
{
  int m_numBytesOffset; // esi

  m_numBytesOffset = fdKey->m_numBytesOffset;
  return ((unsigned __int8)(1 << (m_numBytesOffset % 8))
        & *((_BYTE *)pPlayer->GetPlayerTitleData(this: pPlayer, a2: fdKey->m_iTitleDataBlock) + m_numBytesOffset / 8)) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100058F0
// Name: void TitleDataFieldsDescriptionSetBit(struct TitleDataFieldsDescription_t const __near *,class IPlayerLocal __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl TitleDataFieldsDescriptionSetBit(
        const TitleDataFieldsDescription_t *fdKey,
        IPlayerLocal *pPlayer,
        int bBitValue)
{
  void (__thiscall *UpdatePlayerTitleData)(IPlayerLocal *, const TitleDataFieldsDescription_t *, const void *, int); // edx

  UpdatePlayerTitleData = pPlayer->UpdatePlayerTitleData;
  HIBYTE(bBitValue) = -((_BYTE)bBitValue != 0);
  UpdatePlayerTitleData(this: pPlayer, a2: fdKey, a3: (char *)&bBitValue + 3, a4: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10005920
// Name: public: virtual class IPlayerLocal __near * PlayerManager::GetLocalPlayer(int)
// Source: json
//------------------------------------------------------------------------------
PlayerLocal *__thiscall PlayerManager::GetLocalPlayer(PlayerManager *this, unsigned int playerIndex)
{
  PlayerLocal *result; // eax

  if ( playerIndex >= 4 )
    return nullptr;
  result = this->mLocalPlayer[playerIndex];
  if ( result == nullptr )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005940
// Name: public: class PlayerLocal __near * PlayerManager::FindPlayerLocal(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
PlayerLocal *__thiscall PlayerManager::FindPlayerLocal(PlayerManager *this, unsigned __int64 xuid)
{
  unsigned int v2; // ebx
  PlayerLocal **mLocalPlayer; // edi
  PlayerLocal *v4; // esi
  __int64 v5; // rax

  v2 = 0;
  mLocalPlayer = this->mLocalPlayer;
  do
  {
    v4 = *mLocalPlayer;
    if ( *mLocalPlayer != nullptr )
    {
      LODWORD(v5) = v4->GetXUID(this: *mLocalPlayer);
      if ( v5 == xuid )
        return v4;
    }
    ++v2;
    ++mLocalPlayer;
  }
  while ( v2 < 4 );
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10005990
// Name: public: void PlayerManager::RecomputePlayerXUIDs(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::RecomputePlayerXUIDs(PlayerManager *this, const char *szNetwork)
{
  PlayerLocal **mLocalPlayer; // esi
  int i; // edi

  mLocalPlayer = this->mLocalPlayer;
  for ( i = 4; i != 0; --i )
  {
    if ( *mLocalPlayer != nullptr )
      PlayerLocal::RecomputeXUID(this: (CEmptyConVar *)*mLocalPlayer, nValue: (int)szNetwork);
    ++mLocalPlayer;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100059C0
// Name: public: void PlayerManager::RequestStoreStats(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::RequestStoreStats(PlayerManager *this)
{
  this->m_bRequestStoreStats = true;
}

//------------------------------------------------------------------------------
// Address: 0x100059D0
// Name: private: void PlayerManager::ExecuteStoreStatsRequest(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::ExecuteStoreStatsRequest(PlayerManager *this)
{
  ISteamUserStats *m_pSteamUserStats; // ecx

  if ( this->m_bRequestStoreStats )
  {
    this->m_bRequestStoreStats = false;
    m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
    if ( m_pSteamUserStats != nullptr )
      m_pSteamUserStats->StoreStats(this: m_pSteamUserStats);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005A00
// Name: public: virtual void PlayerManager::EnableFriendsUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::EnableFriendsUpdate(PlayerManager *this, bool bEnable)
{
  bool v2; // bl
  IMatchTitle *v4; // eax

  v2 = bEnable;
  if ( bEnable )
  {
    v4 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    if ( (v4->GetTitleSettingsFlags(this: v4) & 4) != 0 )
      v2 = false;
  }
  this->m_bUpdateEnabled = v2;
  this->m_flNextUpdateTime = 0.0;
  this->m_lanSearchData.m_flStartTime = 0.0;
  this->m_lanSearchData.m_flLastBroadcastTime = 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x10005A50
// Name: private: void PlayerManager::CreateLanSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::CreateLanSearch(PlayerManager *this)
{
  IMatchTitle *v2; // eax

  v2 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  if ( (v2->GetTitleSettingsFlags(this: v2) & 4) == 0 )
  {
    if ( !this->m_lanSearchData.m_bSearchInProgress )
    {
      ++this->m_searchesPending;
      this->m_lanSearchData.m_bSearchInProgress = true;
    }
    this->m_lanSearchData.m_flStartTime = 0.0;
    this->m_lanSearchData.m_flLastBroadcastTime = 0.0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005AA0
// Name: private: void PlayerManager::CreateFriendEnumeration(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::CreateFriendEnumeration(PlayerManager *this, int iCtrlr)
{
  PlayerManager::SFriendSearchData *v3; // edi
  IMatchTitle *v4; // eax

  v3 = &this->m_searchData[iCtrlr];
  v4 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  if ( (v4->GetTitleSettingsFlags(this: v4) & 4) == 0
    && !v3->mSearchInProgress
    && steamapicontext->m_pSteamFriends != nullptr )
  {
    v3->mSearchInProgress = true;
    ++this->m_searchesPending;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005AF0
// Name: unsigned __int64 TitleDataFieldsDescriptionGetValue<unsigned __int64>(struct TitleDataFieldsDescription_t const __near *,class IPlayerLocal __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __cdecl TitleDataFieldsDescriptionGetValue<unsigned __int64>(
        const TitleDataFieldsDescription_t *fdKey,
        IPlayerLocal *pPlayer)
{
  return *(_QWORD *)((char *)pPlayer->GetPlayerTitleData(this: pPlayer, a2: fdKey->m_iTitleDataBlock)
                   + fdKey->m_numBytesOffset);
}

//------------------------------------------------------------------------------
// Address: 0x10005B20
// Name: public: virtual int PlayerManager::GetNumFriends(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall PlayerManager::GetNumFriends(PlayerManager *this)
{
  return this->mFriendsList.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10005B30
// Name: private: void PlayerManager::UpdateLanSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::UpdateLanSearch(PlayerManager *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  float m_fValue; // [esp+4h] [ebp-4h]
  float v5; // [esp+4h] [ebp-4h]

  if ( !this->m_lanSearchData.m_bSearchInProgress )
    return;
  if ( this->m_lanSearchData.m_flStartTime == 0.0 || this->m_lanSearchData.m_flLastBroadcastTime == 0.0 )
  {
    this->m_lanSearchData.m_flStartTime = _Plat_FloatTime();
LABEL_9:
    this->m_lanSearchData.m_flLastBroadcastTime = _Plat_FloatTime();
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "LanSearch");
    else
      v3 = nullptr;
    CConnectionlessLanMgr::SendPacket(
      this: g_pConnectionlessLanMgr,
      pMsg: v3,
      szAddress: nullptr,
      eSock: NS_SOCK_CLIENT);
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
    return;
  }
  m_fValue = mm_player_search_lan_ping_duration.m_pParent->m_Value.m_fValue;
  if ( _Plat_FloatTime() > m_fValue + this->m_lanSearchData.m_flStartTime )
  {
    --this->m_searchesPending;
    this->m_lanSearchData.m_bSearchInProgress = false;
    return;
  }
  v5 = mm_player_search_lan_ping_interval.m_pParent->m_Value.m_fValue;
  if ( v5 + this->m_lanSearchData.m_flLastBroadcastTime <= _Plat_FloatTime() )
    goto LABEL_9;
}

//------------------------------------------------------------------------------
// Address: 0x10005C20
// Name: SyncKeyValueWithStatField
// Source: json
//------------------------------------------------------------------------------
void __usercall SyncKeyValueWithStatField(
        IPlayerLocal *pPlayerLocal@<esi>,
        const TitleDataFieldsDescription_t *pField@<edi>,
        SyncKeyValueDirection_t eOp@<ecx>,
        KeyValues *kvValue)
{
  int v4; // eax
  bool Bit; // al
  char Int; // al
  void (__thiscall *UpdatePlayerTitleData)(IPlayerLocal *, const TitleDataFieldsDescription_t *, const void *, int); // edx
  unsigned __int8 *v8; // eax
  unsigned __int16 v9; // ax
  void (__thiscall *v10)(IPlayerLocal *, const TitleDataFieldsDescription_t *, const void *, int); // edx
  char *v11; // eax
  char *v12; // eax
  char *v13; // eax
  unsigned __int64 v14; // rax
  unsigned __int64 Uint64; // [esp+8h] [ebp-Ch] BYREF
  _BYTE v16[4]; // [esp+10h] [ebp-4h] BYREF

  switch ( pField->m_eDataType )
  {
    case DT_uint8:
      if ( eOp != KVSTAT_WRITE_STAT )
      {
        v8 = (unsigned __int8 *)pPlayerLocal->GetPlayerTitleData(this: pPlayerLocal, a2: pField->m_iTitleDataBlock);
        KeyValues::SetInt(this: kvValue, keyName: defaultValue, value: v8[pField->m_numBytesOffset]);
      }
      else
      {
        Int = KeyValues::GetInt(this: kvValue, keyName: defaultValue, defaultValue: 0);
        UpdatePlayerTitleData = pPlayerLocal->UpdatePlayerTitleData;
        v16[0] = Int;
        UpdatePlayerTitleData(this: pPlayerLocal, a2: pField, a3: v16, a4: 1);
      }
      break;
    case DT_BITFIELD:
      if ( eOp != KVSTAT_WRITE_STAT )
      {
        Bit = TitleDataFieldsDescriptionGetBit(fdKey: pField, pPlayer: pPlayerLocal);
        KeyValues::SetInt(this: kvValue, keyName: defaultValue, value: Bit);
      }
      else
      {
        v4 = KeyValues::GetInt(this: kvValue, keyName: defaultValue, defaultValue: 0);
        TitleDataFieldsDescriptionSetBit(fdKey: pField, pPlayer: pPlayerLocal, bBitValue: v4 != 0);
      }
      break;
    case DT_uint16:
      if ( eOp != KVSTAT_WRITE_STAT )
      {
        v11 = (char *)pPlayerLocal->GetPlayerTitleData(this: pPlayerLocal, a2: pField->m_iTitleDataBlock);
        KeyValues::SetInt(
          this: kvValue,
          keyName: defaultValue,
          value: *(unsigned __int16 *)&v11[pField->m_numBytesOffset]);
      }
      else
      {
        v9 = KeyValues::GetInt(this: kvValue, keyName: defaultValue, defaultValue: 0);
        v10 = pPlayerLocal->UpdatePlayerTitleData;
        HIDWORD(Uint64) = v9;
        v10(this: pPlayerLocal, a2: pField, a3: (char *)&Uint64 + 4, a4: 2);
      }
      break;
    case DT_uint32:
      if ( eOp != KVSTAT_WRITE_STAT )
      {
        v12 = (char *)pPlayerLocal->GetPlayerTitleData(this: pPlayerLocal, a2: pField->m_iTitleDataBlock);
        KeyValues::SetInt(this: kvValue, keyName: defaultValue, value: *(_DWORD *)&v12[pField->m_numBytesOffset]);
      }
      else
      {
        HIDWORD(Uint64) = KeyValues::GetInt(this: kvValue, keyName: defaultValue, defaultValue: 0);
        pPlayerLocal->UpdatePlayerTitleData(this: pPlayerLocal, a2: pField, a3: (char *)&Uint64 + 4, a4: 4);
      }
      break;
    case DT_float:
      if ( eOp != KVSTAT_WRITE_STAT )
      {
        v13 = (char *)pPlayerLocal->GetPlayerTitleData(this: pPlayerLocal, a2: pField->m_iTitleDataBlock);
        KeyValues::SetInt(this: kvValue, keyName: defaultValue, value: (int)*(float *)&v13[pField->m_numBytesOffset]);
      }
      else
      {
        *((float *)&Uint64 + 1) = KeyValues::GetFloat(this: kvValue, keyName: defaultValue, defaultValue: 0.0);
        pPlayerLocal->UpdatePlayerTitleData(this: pPlayerLocal, a2: pField, a3: (char *)&Uint64 + 4, a4: 4);
      }
      break;
    case DT_uint64:
      if ( eOp != KVSTAT_WRITE_STAT )
      {
        v14 = TitleDataFieldsDescriptionGetValue<unsigned __int64>(fdKey: pField, pPlayer: pPlayerLocal);
        KeyValues::SetUint64(this: kvValue, keyName: defaultValue, value: v14);
      }
      else
      {
        Uint64 = KeyValues::GetUint64(this: kvValue, keyName: defaultValue, defaultValue: 0);
        pPlayerLocal->UpdatePlayerTitleData(this: pPlayerLocal, a2: pField, a3: &Uint64, a4: 8);
      }
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005E80
// Name: public: virtual class IPlayerFriend __near * PlayerManager::GetFriendByIndex(int)
// Source: json
//------------------------------------------------------------------------------
PlayerFriend *__thiscall PlayerManager::GetFriendByIndex(PlayerManager *this, int index)
{
  if ( index < 0 || index >= this->mFriendsList.m_Size )
    return nullptr;
  else
    return this->mFriendsList.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x10005EA0
// Name: public: class PlayerFriend __near * PlayerManager::FindPlayerFriend(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
PlayerFriend *__thiscall PlayerManager::FindPlayerFriend(PlayerManager *this, unsigned __int64 xuid)
{
  int v3; // edi
  PlayerFriend *v4; // esi
  __int64 v5; // rax

  v3 = 0;
  if ( this->mFriendsList.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->mFriendsList.m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      LODWORD(v5) = v4->GetXUID(this: v4);
      if ( v5 == xuid )
        break;
    }
    if ( ++v3 >= this->mFriendsList.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10005EF0
// Name: protected: void PlayerManager::MarkOldFriends(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::MarkOldFriends(PlayerManager *this)
{
  int i; // esi
  PlayerFriend *v3; // edi

  for ( i = 0; i < this->mFriendsList.m_Size; ++i )
  {
    v3 = this->mFriendsList.m_Memory.m_pMemory[i];
    PlayerFriend::SetIsStale(this: v3, bStale: true);
    PlayerFriend::SetFriendMark(this: v3, maskSetting: 0);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005F30
// Name: public: virtual class IPlayerFriend __near * PlayerManager::GetFriendByXUID(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
PlayerFriend *__thiscall PlayerManager::GetFriendByXUID(PlayerManager *this, unsigned __int64 xuid)
{
  return PlayerManager::FindPlayerFriend(this, xuid);
}

//------------------------------------------------------------------------------
// Address: 0x10005F50
// Name: public: virtual class IPlayer __near * PlayerManager::FindPlayer(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
PlayerFriend *__thiscall PlayerManager::FindPlayer(PlayerManager *this, unsigned __int64 xuid)
{
  PlayerFriend *result; // eax

  result = (PlayerFriend *)PlayerManager::FindPlayerLocal(this, xuid);
  if ( result == nullptr )
    return PlayerManager::FindPlayerFriend(this, xuid);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005F80
// Name: protected: void PlayerManager::RemoveOldFriends(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::RemoveOldFriends(PlayerManager *this)
{
  int i; // edi
  PlayerFriend *v3; // ebx
  int m_Size; // ecx

  for ( i = 0; i < this->mFriendsList.m_Size; ++i )
  {
    v3 = this->mFriendsList.m_Memory.m_pMemory[i];
    if ( PlayerFriend::GetIsStale(this: v3) || PlayerFriend::GetFriendMark(this: v3) == 0 )
    {
      m_Size = this->mFriendsList.m_Size;
      if ( m_Size > 0 )
      {
        if ( i != m_Size - 1 )
          this->mFriendsList.m_Memory.m_pMemory[i] = this->mFriendsList.m_Memory.m_pMemory[m_Size - 1];
        --this->mFriendsList.m_Size;
      }
      --i;
      v3->Destroy(this: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005FE0
// Name: public: void PlayerManager::OnGameUsersChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::OnGameUsersChanged(PlayerManager *this)
{
  int i; // edi
  PlayerFriend **m_pMemory; // eax
  PlayerFriend *v4; // ecx
  PlayerFriend **v5; // ebx
  PlayerLocal **mLocalPlayer; // edi
  int j; // ebx
  PlayerLocal *v8; // eax
  PlayerLocal *v9; // eax
  PlayerManager_vtbl *v10; // edx

  DevMsg(a1: "PlayerManager::OnGameUsersChanged\n");
  for ( i = 0; i < this->mFriendsList.m_Size; *v5 = nullptr )
  {
    m_pMemory = this->mFriendsList.m_Memory.m_pMemory;
    v4 = m_pMemory[i];
    v5 = &m_pMemory[i];
    if ( v4 != nullptr )
      v4->Destroy(this: v4);
    ++i;
  }
  this->mFriendsList.m_Size = 0;
  mLocalPlayer = this->mLocalPlayer;
  for ( j = 4; j != 0; --j )
  {
    if ( *mLocalPlayer != nullptr )
      (*mLocalPlayer)->Destroy(this: *mLocalPlayer);
    *mLocalPlayer++ = nullptr;
  }
  if ( steamapicontext->m_pSteamUser != nullptr )
  {
    v8 = (PlayerLocal *)operator new(nSize: 0xD18u);
    if ( v8 != nullptr )
    {
      v9 = PlayerLocal::PlayerLocal(this: v8, iController: 0);
      v10 = this->IPlayerManager::__vftable;
      this->mLocalPlayer[0] = v9;
    }
    else
    {
      v10 = this->IPlayerManager::__vftable;
      this->mLocalPlayer[0] = nullptr;
    }
    v10->EnableFriendsUpdate(this, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006090
// Name: public: PlayerManager::PlayerManager(void)
// Source: json
//------------------------------------------------------------------------------
PlayerManager *__thiscall PlayerManager::PlayerManager(PlayerManager *this)
{
  PlayerManager::SFriendSearchData *m_searchData; // edi

  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IPlayerManager::__vftable = (PlayerManager_vtbl *)&PlayerManager::`vftable'{for `IPlayerManager'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&PlayerManager::`vftable'{for `IMatchEventsSink'};
  this->mFriendsList.m_Memory.m_pMemory = nullptr;
  this->mFriendsList.m_Memory.m_nAllocationCount = 0;
  this->mFriendsList.m_Memory.m_nGrowSize = 0;
  this->mFriendsList.m_Size = 0;
  this->mFriendsList.m_pElements = nullptr;
  m_searchData = this->m_searchData;
  this->m_bUpdateEnabled = true;
  this->m_flNextUpdateTime = 0.0;
  memset(dst: (unsigned __int8 *)this->m_searchData, value: 0, count: sizeof(this->m_searchData));
  *(_QWORD *)&this->m_lanSearchData.m_bSearchInProgress = 0;
  this->m_lanSearchData.m_flLastBroadcastTime = 0.0;
  this->m_searchesPending = 0;
  this->m_bRequestStoreStats = false;
  *(_QWORD *)this->mLocalPlayer = 0;
  *(_QWORD *)&this->mLocalPlayer[2] = 0;
  memset(dst: (unsigned __int8 *)m_searchData, value: 0, count: 0x60u);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006110
// Name: public: virtual PlayerManager::~PlayerManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::~PlayerManager(PlayerManager *this)
{
  this->IPlayerManager::__vftable = (PlayerManager_vtbl *)&PlayerManager::`vftable'{for `IPlayerManager'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&PlayerManager::`vftable'{for `IMatchEventsSink'};
  *(_QWORD *)this->mLocalPlayer = 0;
  *(_QWORD *)&this->mLocalPlayer[2] = 0;
  memset(dst: (unsigned __int8 *)this->m_searchData, value: 0, count: sizeof(this->m_searchData));
  this->m_bUpdateEnabled = false;
  this->m_searchesPending = 0;
  this->mFriendsList.m_Size = 0;
  if ( this->mFriendsList.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->mFriendsList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->mFriendsList.m_Memory.m_pMemory);
      this->mFriendsList.m_Memory.m_pMemory = nullptr;
    }
    this->mFriendsList.m_Memory.m_nAllocationCount = 0;
  }
  this->mFriendsList.m_pElements = this->mFriendsList.m_Memory.m_pMemory;
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->mFriendsList);
}

//------------------------------------------------------------------------------
// Address: 0x10006180
// Name: public: void PlayerManager::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::Update(PlayerManager *this)
{
  PlayerManager *v1; // edi
  bool v2; // zf
  PlayerManager::SFriendSearchData *m_searchData; // ebx
  ISteamFriends *m_pSteamFriends; // ecx
  int v5; // esi
  unsigned int m_unAll64Bits_high; // edi
  ISteamFriends *v7; // ecx
  unsigned int m_unAll64Bits; // ebx
  bool (__thiscall *GetFriendGamePlayed)(ISteamFriends *, CSteamID, FriendGameInfo_t *); // edx
  PlayerFriend *PlayerFriend; // esi
  PlayerFriend *v11; // eax
  PlayerManager *v12; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  PlayerFriend **m_pMemory; // ecx
  int v16; // eax
  PlayerFriend **v17; // ecx
  PlayerFriend **v18; // ebx
  ISteamFriends *v19; // ecx
  unsigned int FriendMark; // eax
  KeyValues *v21; // eax
  KeyValues *v22; // esi
  IMatchEventsSubscription *v23; // eax
  KeyValues *v24; // eax
  KeyValues *v25; // esi
  IMatchEventsSubscription *v26; // eax
  PlayerLocal **mLocalPlayer; // esi
  int i; // ebx
  int j; // esi
  PlayerFriend *v30; // ecx
  ISteamUserStats *m_pSteamUserStats; // ecx
  PlayerFriend::FriendInfo_t fi; // [esp+Ch] [ebp-6Ch] BYREF
  FriendGameInfo_t fgi; // [esp+2Ch] [ebp-4Ch] BYREF
  unsigned __int64 uiAppID; // [esp+44h] [ebp-34h]
  unsigned __int64 uiLobbyIdFriend; // [esp+4Ch] [ebp-2Ch]
  CSteamID steamIDFriend; // [esp+54h] [ebp-24h] BYREF
  unsigned __int64 xuidFriend; // [esp+5Ch] [ebp-1Ch]
  int m_fValue_low; // [esp+64h] [ebp-14h]
  PlayerManager::SFriendSearchData *v39; // [esp+68h] [ebp-10h]
  int index; // [esp+6Ch] [ebp-Ch]
  PlayerManager *v41; // [esp+70h] [ebp-8h]
  int numFriends; // [esp+74h] [ebp-4h]

  v1 = this;
  v2 = this->m_searchesPending == 0;
  v41 = this;
  if ( v2 )
  {
    if ( !this->m_bUpdateEnabled || _Plat_FloatTime() <= this->m_flNextUpdateTime || IsLocalClientConnectedToServer() )
      goto LABEL_40;
    PlayerManager::MarkOldFriends(this: v1);
    PlayerManager::CreateFriendEnumeration(this: v1, iCtrlr: 0);
    PlayerManager::CreateLanSearch(this: v1);
    v24 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v24 != nullptr )
      v25 = KeyValues::KeyValues(
              this: v24,
              setName: "OnMatchPlayerMgrUpdate",
              firstKey: "update",
              firstValue: "searchstarted");
    else
      v25 = nullptr;
    v26 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v26->BroadcastEvent(this: v26, a2: v25);
    goto LABEL_39;
  }
  m_searchData = this->m_searchData;
  v39 = this->m_searchData;
  m_fValue_low = 4;
  do
  {
    if ( m_searchData->mSearchInProgress )
    {
      m_pSteamFriends = steamapicontext->m_pSteamFriends;
      v5 = 0;
      if ( m_pSteamFriends != nullptr )
        numFriends = m_pSteamFriends->GetFriendCount(this: m_pSteamFriends, a2: 4);
      else
        numFriends = 0;
      LODWORD(uiAppID) = steamapicontext->m_pSteamUtils->GetAppID(this: steamapicontext->m_pSteamUtils);
      index = 0;
      if ( numFriends > 0 )
      {
        do
        {
          steamapicontext->m_pSteamFriends->GetFriendByIndex(
            this: steamapicontext->m_pSteamFriends,
            result: &steamIDFriend,
            a3: v5,
            a4: 4);
          HIWORD(fgi.m_steamIDLobby.m_steamid.m_unAll64Bits) = BYTE6(fgi.m_steamIDLobby.m_steamid.m_unAll64Bits) & 0xF;
          m_unAll64Bits_high = HIDWORD(steamIDFriend.m_steamid.m_unAll64Bits);
          fgi.m_steamIDLobby.m_steamid.m_unAll64Bits &= 0xFFF0000000000000uLL;
          fgi.m_gameID.m_ulGameID = 0;
          v7 = steamapicontext->m_pSteamFriends;
          m_unAll64Bits = steamIDFriend.m_steamid.m_unAll64Bits;
          GetFriendGamePlayed = v7->GetFriendGamePlayed;
          xuidFriend = steamIDFriend.m_steamid.m_unAll64Bits;
          if ( ((unsigned __int8 (__thiscall *)(ISteamFriends *, _DWORD, _DWORD, FriendGameInfo_t *))GetFriendGamePlayed)(
                 a1: v7,
                 a2: *(_DWORD *)&steamIDFriend.m_steamid.m_comp,
                 a3: *((_DWORD *)&steamIDFriend.m_steamid.m_comp + 1),
                 a4: &fgi) != 0
            && (fgi.m_gameID.m_ulGameID & 0xFFFFFF) == (_DWORD)uiAppID )
          {
            PlayerFriend = PlayerManager::FindPlayerFriend(
                             this: v41,
                             xuid: __PAIR64__(m_unAll64Bits_high, m_unAll64Bits));
            if ( PlayerFriend == nullptr )
            {
              v11 = (PlayerFriend *)operator new(nSize: 0x120u);
              if ( v11 != nullptr )
                PlayerFriend = PlayerFriend::PlayerFriend(
                                 this: v11,
                                 xuid: __PAIR64__(m_unAll64Bits_high, m_unAll64Bits),
                                 pFriendInfo: nullptr);
              else
                PlayerFriend = nullptr;
              v12 = v41;
              m_Size = v41->mFriendsList.m_Size;
              m_nAllocationCount = v41->mFriendsList.m_Memory.m_nAllocationCount;
              if ( m_Size + 1 > m_nAllocationCount )
                CUtlMemory<GCSDK::CLock *,int>::Grow(
                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v41->mFriendsList,
                  num: m_Size - m_nAllocationCount + 1);
              ++v12->mFriendsList.m_Size;
              m_pMemory = v12->mFriendsList.m_Memory.m_pMemory;
              v16 = v12->mFriendsList.m_Size - m_Size - 1;
              v12->mFriendsList.m_pElements = m_pMemory;
              if ( v16 > 0 )
                _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v16);
              v17 = v12->mFriendsList.m_Memory.m_pMemory;
              m_unAll64Bits_high = HIDWORD(xuidFriend);
              v18 = &v17[m_Size];
              if ( v18 != nullptr )
                *v18 = PlayerFriend;
              m_unAll64Bits = xuidFriend;
            }
            PlayerFriend::SetIsStale(this: PlayerFriend, bStale: false);
            memset(&fi, 0, sizeof(fi));
            v19 = steamapicontext->m_pSteamFriends;
            uiLobbyIdFriend = fgi.m_steamIDLobby.m_steamid.m_unAll64Bits;
            fi.m_szName = (const char *)((int (__thiscall *)(ISteamFriends *, unsigned int, unsigned int))v19->GetFriendPersonaName)(
                                          a1: v19,
                                          a2: m_unAll64Bits,
                                          a3: m_unAll64Bits_high);
            fi.m_xSessionID = (XNKID)uiLobbyIdFriend;
            fi.m_wszRichPresence = &word_10057F4C;
            PlayerFriend::UpdateFriendInfo(this: PlayerFriend, pFriendInfo: &fi);
            FriendMark = PlayerFriend::GetFriendMark(this: PlayerFriend);
            PlayerFriend::SetFriendMark(this: PlayerFriend, maskSetting: FriendMark | 1);
            v5 = index;
          }
          index = ++v5;
        }
        while ( v5 < numFriends );
        m_searchData = v39;
        v1 = v41;
      }
      --v1->m_searchesPending;
      m_searchData->mSearchInProgress = false;
    }
    ++m_searchData;
    v2 = m_fValue_low-- == 1;
    v39 = m_searchData;
  }
  while ( !v2 );
  PlayerManager::UpdateLanSearch(this: v1);
  if ( v1->m_searchesPending == 0 )
  {
    PlayerManager::RemoveOldFriends(this: v1);
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    v22 = v21 != nullptr
        ? KeyValues::KeyValues(
            this: v21,
            setName: "OnMatchPlayerMgrUpdate",
            firstKey: "update",
            firstValue: "searchfinished")
        : nullptr;
    v23 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v23->BroadcastEvent(this: v23, a2: v22);
    if ( v1->m_flNextUpdateTime != 0.0 )
    {
LABEL_39:
      m_fValue_low = SLODWORD(mm_player_search_update_interval.m_pParent->m_Value.m_fValue);
      v1->m_flNextUpdateTime = _Plat_FloatTime() + *(float *)&m_fValue_low;
    }
  }
LABEL_40:
  mLocalPlayer = v1->mLocalPlayer;
  for ( i = 4; i != 0; --i )
  {
    if ( *mLocalPlayer != nullptr )
      (*mLocalPlayer)->Update(this: *mLocalPlayer);
    ++mLocalPlayer;
  }
  for ( j = 0; j < v1->mFriendsList.m_Size; ++j )
  {
    v30 = v1->mFriendsList.m_Memory.m_pMemory[j];
    if ( v30 != nullptr )
      v30->Update(this: v30);
  }
  if ( v1->m_bRequestStoreStats )
  {
    v1->m_bRequestStoreStats = false;
    m_pSteamUserStats = steamapicontext->m_pSteamUserStats;
    if ( m_pSteamUserStats != nullptr )
      m_pSteamUserStats->StoreStats(this: m_pSteamUserStats);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006520
// Name: public: virtual void PlayerManager::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall PlayerManager::OnEvent(PlayerManager *this, KeyValues *pEvent)
{
  const char *Name; // esi
  char *Key; // eax
  KeyValues *v5; // esi
  unsigned int v6; // edi
  unsigned __int64 Uint64; // kr00_8
  unsigned __int64 v8; // kr08_8
  char **k; // ebx
  __int64 v10; // rax
  IMatchNetworkMsgController *v11; // eax
  PlayerFriend *PlayerFriend; // ebx
  PlayerFriend *v13; // eax
  KeyValues *v14; // esi
  bool (__cdecl *m_pExpressionGetSymbolProc)(const char *); // edi
  KeyValues *m_pSub; // eax
  KeyValues *m_pPeer; // ecx
  int v18; // eax
  KeyValues *v19; // eax
  PlayerFriend **v20; // edi
  KeyValues *v21; // eax
  KeyValues *v22; // eax
  KeyValues *v23; // eax
  KeyValues *v24; // eax
  unsigned int v25; // edi
  char **p_m_sValue; // esi
  CFmtStrN<256> *v27; // eax
  const char *v28; // eax
  const char *String; // esi
  PlayerLocal **v30; // esi
  int i; // ebx
  KeyValues *FirstTrueSubKey; // edi
  const char *Int; // ebx
  int (__thiscall *v34)(bool (__cdecl **)(const char *), const char *); // edx
  IPlayerLocal *v35; // esi
  KeyValues *Copy; // edi
  IMatchTitle *v37; // eax
  KeyValues *j; // ebx
  const TitleDataFieldsDescription_t *v39; // edi
  const char *v40; // eax
  const char *v41; // eax
  IMatchTitle *v42; // eax
  KeyValues *FirstValue; // ebx
  const char *v44; // edi
  const TitleDataFieldsDescription_t *v45; // eax
  const char *v46; // eax
  int v47; // esi
  KeyValues *v48; // [esp-8h] [ebp-15Ch]
  KeyValues *v49; // [esp-8h] [ebp-15Ch]
  const char *v50; // [esp-4h] [ebp-158h]
  const char *v51; // [esp-4h] [ebp-158h]
  const char *v52; // [esp-4h] [ebp-158h]
  CFmtStrN<256> v53; // [esp+Ch] [ebp-148h] BYREF
  PlayerFriend::FriendInfo_t fi; // [esp+118h] [ebp-3Ch] BYREF
  MM_GameDetails_QOS_t gd; // [esp+138h] [ebp-1Ch] BYREF
  unsigned __int64 xuid; // [esp+144h] [ebp-10h]
  const char *szStatName; // [esp+14Ch] [ebp-8h]
  KeyValues *kvReply; // [esp+150h] [ebp-4h]
  const TitleDataFieldsDescription_t *pFields; // [esp+15Ch] [ebp+8h]
  KeyValues *pFieldsa; // [esp+15Ch] [ebp+8h]
  const char *pFieldsb; // [esp+15Ch] [ebp+8h]
  const TitleDataFieldsDescription_t *pFieldsc; // [esp+15Ch] [ebp+8h]
  const TitleDataFieldsDescription_t *pFieldsd; // [esp+15Ch] [ebp+8h]

  kvReply = (KeyValues *)this;
  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnNetLanConnectionlessPacket") != 0 )
  {
    if ( _V_stricmp(s1: Name, s2: "OnSysSigninChange") != 0 )
    {
      if ( _V_stricmp(s1: Name, s2: "OnProfilesChanged") == 0 )
      {
        PlayerManager::OnGameUsersChanged(this: (PlayerManager *)((char *)this - 4));
        return;
      }
      if ( _V_stricmp(s1: Name, s2: "OnUnlockArcadeTitle") != 0 )
      {
        if ( _V_stricmp(s1: Name, s2: "OnSysProfileSettingsChanged") == 0 )
        {
          v25 = 0;
          p_m_sValue = &kvReply->m_sValue;
          do
          {
            if ( *p_m_sValue != nullptr )
            {
              v27 = CFmtStrN<256>::CFmtStrN<256>(this: &v53, pszFormat: "user%d", v25);
              if ( KeyValues::GetInt(this: pEvent, keyName: v27->m_szBuf, defaultValue: 0) != 0 )
              {
                v28 = (const char *)(*(int (__thiscall **)(char *))(*(_DWORD *)*p_m_sValue + 8))(a1: *p_m_sValue);
                DevMsg(a1: "Reloading player profile data for ctrlr%d (%s)\n", v25, v28);
                PlayerLocal::LoadPlayerProfileData(this: (PlayerLocal *)*p_m_sValue);
              }
            }
            ++v25;
            ++p_m_sValue;
          }
          while ( v25 < 4 );
          return;
        }
        if ( _V_stricmp(s1: Name, s2: "OnProfilesWriteOpportunity") == 0 )
        {
          String = KeyValues::GetString(this: pEvent, keyName: "reason", defaultValue: defaultValue);
          if ( _V_stricmp(s1: "checkpoint", s2: String) != 0 )
          {
            if ( _V_stricmp(s1: "sessionstart", s2: String) != 0 )
            {
              if ( _V_stricmp(s1: "sessionend", s2: String) != 0 )
              {
                if ( _V_stricmp(s1: "settings", s2: String) != 0 )
                {
                  if ( _V_stricmp(s1: "deactivation", s2: String) == 0 )
                  {
                    v30 = (PlayerLocal **)&this->IMatchEventsSink;
                    for ( i = 4; i != 0; --i )
                    {
                      if ( *v30 != nullptr )
                        PlayerLocal::WriteTitleData(this: *v30);
                      ++v30;
                    }
                    PlayerManager::ExecuteStoreStatsRequest(this: (PlayerManager *)((char *)this - 4));
                  }
                }
                else
                {
                  SignalXWriteOpportunity(eXWO: MMXWO_SETTINGS);
                }
              }
              else
              {
                SignalXWriteOpportunity(eXWO: MMXWO_SESSION_FINISHED);
              }
            }
            else
            {
              SignalXWriteOpportunity(eXWO: MMXWO_SESSION_STARTED);
            }
          }
          else
          {
            SignalXWriteOpportunity(eXWO: MMXWO_CHECKPOINT);
          }
          return;
        }
        if ( _V_stricmp(s1: Name, s2: "Client::CmdKeyValues") != 0 )
          return;
        FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pEvent);
        if ( FirstTrueSubKey == nullptr )
          return;
        Int = (const char *)KeyValues::GetInt(this: pEvent, keyName: "slot", defaultValue: 0);
        v34 = *((int (__thiscall **)(bool (__cdecl **)(const char *), const char *))kvReply[-1].m_pExpressionGetSymbolProc
              + 1);
        szStatName = Int;
        v35 = (IPlayerLocal *)v34(a1: &kvReply[-1].m_pExpressionGetSymbolProc, a2: Int);
        pFieldsb = KeyValues::GetName(this: FirstTrueSubKey);
        if ( _V_stricmp(s1: "write_awards", s2: pFieldsb) == 0 )
        {
          if ( v35 != nullptr )
            v35->UpdateAwardsData(this: v35, a2: FirstTrueSubKey);
          else
            DevWarning(a1: "pPlayerLocal(#%d)->write_awards UNKNOWN SLOT!\n", Int);
          return;
        }
        if ( _V_stricmp(s1: "read_awards", s2: pFieldsb) != 0 )
        {
          if ( _V_stricmp(s1: "write_stats", s2: pFieldsb) == 0 )
          {
            if ( v35 != nullptr )
            {
              v37 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
              pFieldsc = v37->DescribeTitleDataStorage(this: v37);
              for ( j = KeyValues::GetFirstValue(this: FirstTrueSubKey); j != nullptr; j = KeyValues::GetNextValue(this: j) )
              {
                szStatName = KeyValues::GetName(this: j);
                v39 = TitleDataFieldsDescriptionFindByString(fields: pFieldsc, szString: szStatName);
                if ( v39 != nullptr )
                {
                  v40 = (const char *)((int (__thiscall *)(IPlayerLocal *, const char *))v35->GetName)(
                                        a1: v35,
                                        a2: v39->m_szFieldName);
                  DevMsg(a1: "pPlayerLocal(%s)->write_stat(%s)\n", v40, v50);
                  SyncKeyValueWithStatField(pPlayerLocal: v35, pField: v39, eOp: KVSTAT_WRITE_STAT, kvValue: j);
                }
                else if ( szStatName != nullptr )
                {
                  v41 = (const char *)((int (__thiscall *)(IPlayerLocal *, const char *))v35->GetName)(
                                        a1: v35,
                                        a2: szStatName);
                  DevWarning(a1: "pPlayerLocal(%s)->write_stat(%s) UNKNOWN STAT!\n", v41, v51);
                }
              }
            }
            else
            {
              DevWarning(a1: "pPlayerLocal(#%d)->write_stat UNKNOWN SLOT!\n", Int);
            }
            return;
          }
          if ( _V_stricmp(s1: "read_stats", s2: pFieldsb) != 0 )
            return;
          Copy = KeyValues::MakeCopy(this: FirstTrueSubKey);
          kvReply = Copy;
          if ( v35 != nullptr )
          {
            v42 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
            pFieldsd = v42->DescribeTitleDataStorage(this: v42);
            FirstValue = KeyValues::GetFirstValue(this: Copy);
            if ( FirstValue != nullptr )
            {
              do
              {
                v44 = KeyValues::GetName(this: FirstValue);
                v45 = TitleDataFieldsDescriptionFindByString(fields: pFieldsd, szString: v44);
                if ( v45 != nullptr )
                {
                  SyncKeyValueWithStatField(pPlayerLocal: v35, pField: v45, eOp: KVSTAT_READ_STAT, kvValue: FirstValue);
                }
                else if ( v44 != nullptr )
                {
                  v46 = (const char *)((int (__thiscall *)(IPlayerLocal *, const char *))v35->GetName)(a1: v35, a2: v44);
                  DevWarning(a1: "pPlayerLocal(%s)->read_stat(%s) UNKNOWN STAT!\n", v46, v52);
                }
                FirstValue = KeyValues::GetNextValue(this: FirstValue);
              }
              while ( FirstValue != nullptr );
              Copy = kvReply;
            }
            Int = szStatName;
          }
          else
          {
            DevWarning(a1: "pPlayerLocal(#%d)->read_stats UNKNOWN SLOT!\n", Int);
          }
        }
        else
        {
          Copy = KeyValues::MakeCopy(this: FirstTrueSubKey);
          if ( v35 != nullptr )
            v35->GetAwardsData(this: v35, a2: Copy);
          else
            DevWarning(a1: "pPlayerLocal(#%d)->read_awards UNKNOWN SLOT!\n", Int);
        }
        v47 = g_pMatchExtensions->m_exts.m_pIVEngineClient->GetActiveSplitScreenPlayerSlot(this: g_pMatchExtensions->m_exts.m_pIVEngineClient);
        g_pMatchExtensions->m_exts.m_pIVEngineClient->SetActiveSplitScreenPlayerSlot(
          this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
          a2: (int)Int);
        g_pMatchExtensions->m_exts.m_pIVEngineClient->ServerCmdKeyValues(
          this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
          a2: Copy);
        g_pMatchExtensions->m_exts.m_pIVEngineClient->SetActiveSplitScreenPlayerSlot(
          this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
          a2: v47);
      }
    }
  }
  else if ( BYTE4(this->m_searchData[3].mXuid) != 0 && !IsLocalClientConnectedToServer() )
  {
    Key = (char *)KeyValues::FindKey(this: pEvent, keyName: "GameDetailsPlayer", bCreate: false);
    v5 = (KeyValues *)Key;
    szStatName = Key;
    if ( Key != nullptr )
    {
      Uint64 = KeyValues::GetUint64(this: (KeyValues *)Key, keyName: "player/xuidOnline", defaultValue: 0);
      HIDWORD(xuid) = HIDWORD(Uint64);
      v6 = Uint64;
      if ( Uint64 != 0
        || (v8 = KeyValues::GetUint64(this: v5, keyName: "player/xuid", defaultValue: 0),
            HIDWORD(xuid) = HIDWORD(v8),
            v6 = v8,
            v8 != 0) )
      {
        pFields = nullptr;
        for ( k = &kvReply->m_sValue; ; ++k )
        {
          if ( *k != nullptr )
          {
            LODWORD(v10) = (**(int (__thiscall ***)(char *))*k)(a1: *k);
            if ( v10 == __PAIR64__(HIDWORD(xuid), v6) )
              break;
          }
          pFields = (const TitleDataFieldsDescription_t *)((char *)pFields + 1);
          if ( (unsigned int)pFields >= 4 )
          {
            gd.m_pvData = KeyValues::GetPtr(this: v5, keyName: "binary/ptr", defaultValue: nullptr);
            gd.m_numDataBytes = KeyValues::GetInt(this: v5, keyName: "binary/size", defaultValue: 0);
            gd.m_nPing = 0;
            v11 = g_pMatchFramework->GetMatchNetworkMsgController(this: g_pMatchFramework);
            pFieldsa = v11->UnpackGameDetailsFromQOS(this: v11, a2: &gd);
            PlayerFriend = PlayerManager::FindPlayerFriend(
                             this: (PlayerManager *)&kvReply[-1].m_pExpressionGetSymbolProc,
                             xuid: __PAIR64__(HIDWORD(xuid), v6));
            if ( PlayerFriend == nullptr )
            {
              v13 = (PlayerFriend *)operator new(nSize: 0x120u);
              if ( v13 != nullptr )
                PlayerFriend = PlayerFriend::PlayerFriend(
                                 this: v13,
                                 xuid: __PAIR64__(HIDWORD(xuid), v6),
                                 pFriendInfo: nullptr);
              else
                PlayerFriend = nullptr;
              v14 = kvReply;
              m_pExpressionGetSymbolProc = kvReply->m_pExpressionGetSymbolProc;
              m_pSub = kvReply->m_pSub;
              if ( (int)((char *)m_pExpressionGetSymbolProc + 1) > (int)m_pSub )
                CUtlMemory<GCSDK::CLock *,int>::Grow(
                  this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&kvReply->m_pPeer,
                  num: (char *)m_pExpressionGetSymbolProc - (char *)m_pSub + 1);
              ++v14->m_pExpressionGetSymbolProc;
              m_pPeer = v14->m_pPeer;
              v18 = (char *)v14->m_pExpressionGetSymbolProc - (char *)m_pExpressionGetSymbolProc - 1;
              *(_DWORD *)&v14[1] = m_pPeer;
              if ( v18 > 0 )
                _V_memmove(
                  dest: &m_pPeer->m_sValue + (_DWORD)m_pExpressionGetSymbolProc,
                  src: (char *)m_pPeer + 4 * (_DWORD)m_pExpressionGetSymbolProc,
                  count: 4 * v18);
              v19 = v14->m_pPeer;
              v5 = (KeyValues *)szStatName;
              v20 = (PlayerFriend **)((char *)v19 + 4 * (_DWORD)m_pExpressionGetSymbolProc);
              if ( v20 != nullptr )
                *v20 = PlayerFriend;
            }
            PlayerFriend::SetIsStale(this: PlayerFriend, bStale: false);
            PlayerFriend::SetFriendMark(this: PlayerFriend, maskSetting: 0xFFFFFFFF);
            if ( pFieldsa != nullptr )
            {
              v21 = KeyValues::FindKey(this: v5, keyName: "options", bCreate: false);
              if ( v21 != nullptr )
              {
                v48 = v21;
                v22 = KeyValues::FindKey(this: pFieldsa, keyName: "options", bCreate: true);
                KeyValues::MergeFrom(this: v22, kvMerge: v48, eOp: MERGE_KV_UPDATE);
              }
              v23 = KeyValues::FindKey(this: v5, keyName: "player", bCreate: false);
              if ( v23 != nullptr )
              {
                v49 = v23;
                v24 = KeyValues::FindKey(this: pFieldsa, keyName: "player", bCreate: true);
                KeyValues::MergeFrom(this: v24, kvMerge: v49, eOp: MERGE_KV_UPDATE);
              }
            }
            memset(&fi.m_wszRichPresence, 0, 20);
            *((_DWORD *)&fi.m_pGameDetails + 1) = 0;
            fi.m_szName = KeyValues::GetString(this: v5, keyName: "player/name", defaultValue: defaultValue);
            fi.m_pGameDetails = pFieldsa;
            PlayerFriend::UpdateFriendInfo(this: PlayerFriend, pFriendInfo: &fi);
            if ( pFieldsa != nullptr )
              KeyValues::deleteThis(this: pFieldsa);
            return;
          }
        }
      }
    }
  }
}

} // namespace matchmaking
