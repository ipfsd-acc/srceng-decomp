// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_framework.cpp
// Functions: 17
// ============================================================

#include "matchmaking\mm_framework.h"

//------------------------------------------------------------------------------
// Address: 0x10001B80
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class IMatchFramework>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IMatchFramework>::GetDependencies(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10002300
// Name: public: CMatchFramework::~CMatchFramework(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::~CMatchFramework(CMatchFramework *this)
{
  this->CTier2AppSystem<IMatchFramework,0>::CTier1AppSystem<IMatchFramework,0>::CTier0AppSystem<IMatchFramework>::CBaseAppSystem<IMatchFramework>::IMatchFramework::IAppSystem::__vftable = (CMatchFramework_vtbl *)&CMatchFramework::`vftable'{for `CTier2AppSystem<IMatchFramework,0>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchFramework::`vftable'{for `IMatchEventsSink'};
}

//------------------------------------------------------------------------------
// Address: 0x10002310
// Name: public: virtual enum InitReturnVal_t CMatchFramework::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CMatchFramework::Init(CMatchFramework *this)
{
  return MM_Title_Init();
}

//------------------------------------------------------------------------------
// Address: 0x10002320
// Name: public: virtual void CMatchFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::Shutdown(CMatchFramework *this)
{
  this->CloseSession(this);
  MM_Title_Shutdown();
  g_pServerManager->EnableServersUpdate(this: g_pServerManager, a2: false);
  g_pDatacenter->EnableUpdate(this: g_pDatacenter, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x10002350
// Name: public: virtual class IMatchExtensions __near * CMatchFramework::GetMatchExtensions(void)
// Source: json
//------------------------------------------------------------------------------
CMatchExtensions *__thiscall CMatchFramework::GetMatchExtensions(CMatchFramework *this)
{
  return g_pMatchExtensions;
}

//------------------------------------------------------------------------------
// Address: 0x10002360
// Name: public: virtual class IMatchEventsSubscription __near * CMatchFramework::GetEventsSubscription(void)
// Source: json
//------------------------------------------------------------------------------
CMatchEventsSubscription *__thiscall CMatchFramework::GetEventsSubscription(CMatchFramework *this)
{
  return g_pMatchEventsSubscription;
}

//------------------------------------------------------------------------------
// Address: 0x10002370
// Name: public: virtual class IMatchTitle __near * CMatchFramework::GetMatchTitle(void)
// Source: json
//------------------------------------------------------------------------------
IMatchTitle *__thiscall CMatchFramework::GetMatchTitle(CMatchFramework *this)
{
  return g_pIMatchTitle;
}

//------------------------------------------------------------------------------
// Address: 0x10002380
// Name: public: virtual class IMatchTitleGameSettingsMgr __near * CMatchFramework::GetMatchTitleGameSettingsMgr(void)
// Source: json
//------------------------------------------------------------------------------
IMatchTitleGameSettingsMgr *__thiscall CMatchFramework::GetMatchTitleGameSettingsMgr(CMatchFramework *this)
{
  return g_pIMatchTitleGameSettingsMgr;
}

//------------------------------------------------------------------------------
// Address: 0x10002390
// Name: public: virtual class IMatchNetworkMsgController __near * CMatchFramework::GetMatchNetworkMsgController(void)
// Source: json
//------------------------------------------------------------------------------
CMatchNetworkMsgControllerBase *__thiscall CMatchFramework::GetMatchNetworkMsgController(CMatchFramework *this)
{
  return g_pMatchNetMsgControllerBase;
}

//------------------------------------------------------------------------------
// Address: 0x100023A0
// Name: public: virtual class IMatchSystem __near * CMatchFramework::GetMatchSystem(void)
// Source: json
//------------------------------------------------------------------------------
CMatchSystem *__thiscall CMatchFramework::GetMatchSystem(CMatchFramework *this)
{
  return g_pMatchSystem;
}

//------------------------------------------------------------------------------
// Address: 0x100023B0
// Name: public: virtual void CMatchFramework::AcceptInvite(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::AcceptInvite(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x100023C0
// Name: public: virtual void CMatchFramework::CloseSession(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::CloseSession(CMatchFramework *this)
{
  IMatchSessionInternal *m_pMatchSession; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  m_pMatchSession = this->m_pMatchSession;
  if ( m_pMatchSession != nullptr )
  {
    this->m_pMatchSession = nullptr;
    m_pMatchSession->Destroy(this: m_pMatchSession);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "OnMatchSessionUpdate", firstKey: "state", firstValue: "closed");
    else
      v3 = nullptr;
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
  }
  if ( (_S1_0 & 1) == 0 )
  {
    _S1_0 |= 1u;
    ConVarRef::ConVarRef(this: &stru_1003F878, pName: "net_usesocketsforloopback", bIgnoreMissing: true);
  }
  if ( ConVarRef::IsValid(this: &stru_1003F878) )
    stru_1003F878.m_pConVar->SetValue_2(this: stru_1003F878.m_pConVar, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10002450
// Name: public: virtual void CMatchFramework::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::OnEvent(CMatchFramework *this, KeyValues *pEvent)
{
  const char *Name; // edi

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "mmF->CloseSession", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "OnInvite", s2: Name) != 0 )
    {
      if ( g_pPlayerManager != nullptr )
        g_pPlayerManager->OnEvent(this: &g_pPlayerManager->IMatchEventsSink, a2: pEvent);
      if ( g_pServerManager != nullptr )
        g_pServerManager->OnEvent(this: &g_pServerManager->IMatchEventsSink, a2: pEvent);
      if ( g_pDatacenter != nullptr )
        g_pDatacenter->OnEvent(this: &g_pDatacenter->IMatchEventsSink, a2: pEvent);
      if ( g_pIMatchTitleEventsSink != nullptr )
        g_pIMatchTitleEventsSink->OnEvent(this: g_pIMatchTitleEventsSink, a2: pEvent);
      if ( this->IMatchEventsSink::__vftable != nullptr )
        (*(void (__thiscall **)(IMatchEventsSink_vtbl *, KeyValues *))this->IMatchEventsSink::__vftable[1].OnEvent)(
          a1: this->IMatchEventsSink::__vftable + 1,
          a2: pEvent);
    }
  }
  else
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 72))(a1: (char *)this - 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002500
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class IMatchFramework,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IMatchFramework,0>::GetTier(CTier2AppSystem<IMatchFramework,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10002510
// Name: public: virtual void CBaseAppSystem<class IMatchFramework>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IMatchFramework>::Reconnect(
        CBaseAppSystem<IMatchFramework> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10002530
// Name: public: virtual void CMatchFramework::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::RunFrame(CMatchFramework *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( mm_events_listeners_validation.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "mm_events_listeners_validation");
    else
      v3 = nullptr;
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
  }
  SteamApiContext_Shutdown(this: (CServerManager *)g_pConnectionlessLanMgr);
  CMatchSystem::Update(this: g_pMatchSystem);
  if ( this->m_pMatchSession != nullptr )
    this->m_pMatchSession->Update(this: this->m_pMatchSession);
}

//------------------------------------------------------------------------------
// Address: 0x100025A0
// Name: public: CMatchFramework::CMatchFramework(void)
// Source: json
//------------------------------------------------------------------------------
CMatchFramework *__thiscall CMatchFramework::CMatchFramework(CMatchFramework *this)
{
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->CTier2AppSystem<IMatchFramework,0>::CTier1AppSystem<IMatchFramework,0>::CTier0AppSystem<IMatchFramework>::CBaseAppSystem<IMatchFramework>::IMatchFramework::IAppSystem::__vftable = (CMatchFramework_vtbl *)&CMatchFramework::`vftable'{for `CTier2AppSystem<IMatchFramework,0>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchFramework::`vftable'{for `IMatchEventsSink'};
  this->m_pMatchSession = nullptr;
  return this;
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x100028B0
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class IMatchFramework>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IMatchFramework>::GetDependencies(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10007060
// Name: private: virtual int CCallback<class CDlcManager,struct DlcInstalled_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CDlcManager,DlcInstalled_t,0>::GetCallbackSizeBytes(
        CCallback<GCSDK::CGCClient,GCMessageAvailable_t,0> *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x1000ACE0
// Name: private: virtual void CCallback<class CSysSessionBase,struct SteamServersConnected_t,0>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSysSessionBase,SteamServersConnected_t,0>::Run(
        CCallback<GCSDK::CGCClient,GCMessageAvailable_t,0> *this,
        GCMessageAvailable_t *pvParam)
{
  this->m_Func(this: this->m_pObj, a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x1000ACF0
// Name: private: virtual int CCallback<class PlayerLocal,struct UserStatsReceived_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<PlayerLocal,UserStatsReceived_t,0>::GetCallbackSizeBytes(
        CCallback<PlayerLocal,UserStatsReceived_t,0> *this)
{
  return 24;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD00
// Name: public: void CCallback<class PlayerFriend,struct LobbyDataUpdate_t,0>::Register(class PlayerFriend __near *,void (PlayerFriend::*)(struct LobbyDataUpdate_t __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<PlayerFriend,LobbyDataUpdate_t,0>::Register(
        CCallback<PlayerFriend,LobbyDataUpdate_t,0> *this,
        PlayerFriend *pObj,
        void (__thiscall *func)(PlayerFriend *this, LobbyDataUpdate_t *))
{
  if ( pObj != nullptr && func != nullptr )
  {
    if ( (this->m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: this);
    this->m_pObj = pObj;
    this->m_Func = func;
    _SteamAPI_RegisterCallback(a1: this, a2: 505);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AD50
// Name: public: void CCallback<class PlayerLocal,struct UserStatsReceived_t,0>::Register(class PlayerLocal __near *,void (PlayerLocal::*)(struct UserStatsReceived_t __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<PlayerLocal,UserStatsReceived_t,0>::Register(
        CCallback<PlayerLocal,UserStatsReceived_t,0> *this,
        PlayerLocal *pObj,
        void (__thiscall *func)(PlayerLocal *this, UserStatsReceived_t *))
{
  if ( pObj != nullptr && func != nullptr )
  {
    if ( (this->m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: this);
    this->m_pObj = pObj;
    this->m_Func = func;
    _SteamAPI_RegisterCallback(a1: this, a2: 1101);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DD00
// Name: public: CMatchFramework::~CMatchFramework(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::~CMatchFramework(CMatchFramework *this)
{
  this->CTier2AppSystem<IMatchFramework,0>::CTier1AppSystem<IMatchFramework,0>::CTier0AppSystem<IMatchFramework>::CBaseAppSystem<IMatchFramework>::IMatchFramework::IAppSystem::__vftable = (CMatchFramework_vtbl *)&CMatchFramework::`vftable'{for `CTier2AppSystem<IMatchFramework,0>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchFramework::`vftable'{for `IMatchEventsSink'};
}

//------------------------------------------------------------------------------
// Address: 0x1000DD10
// Name: public: virtual void CMatchFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::Shutdown(CMatchFramework *this)
{
  CMatchEventsSubscription::Shutdown(this: g_pMatchEventsSubscription);
  MM_Title_Shutdown();
  g_pServerManager->EnableServersUpdate(this: g_pServerManager, a2: false);
  g_pDatacenter->EnableUpdate(this: g_pDatacenter, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x1000DD40
// Name: public: virtual class IMatchExtensions __near * CMatchFramework::GetMatchExtensions(void)
// Source: json
//------------------------------------------------------------------------------
CMatchExtensions *__thiscall CMatchFramework::GetMatchExtensions(CMatchFramework *this)
{
  return g_pMatchExtensions;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD50
// Name: public: virtual class IMatchEventsSubscription __near * CMatchFramework::GetEventsSubscription(void)
// Source: json
//------------------------------------------------------------------------------
CMatchEventsSubscription *__thiscall CMatchFramework::GetEventsSubscription(CMatchFramework *this)
{
  return g_pMatchEventsSubscription;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD60
// Name: public: virtual class IMatchTitle __near * CMatchFramework::GetMatchTitle(void)
// Source: json
//------------------------------------------------------------------------------
IMatchTitle *__thiscall CMatchFramework::GetMatchTitle(CMatchFramework *this)
{
  return g_pIMatchTitle;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD70
// Name: public: virtual class IMatchTitleGameSettingsMgr __near * CMatchFramework::GetMatchTitleGameSettingsMgr(void)
// Source: json
//------------------------------------------------------------------------------
IMatchTitleGameSettingsMgr *__thiscall CMatchFramework::GetMatchTitleGameSettingsMgr(CMatchFramework *this)
{
  return g_pIMatchTitleGameSettingsMgr;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD80
// Name: public: virtual class IMatchNetworkMsgController __near * CMatchFramework::GetMatchNetworkMsgController(void)
// Source: json
//------------------------------------------------------------------------------
CMatchNetworkMsgControllerBase *__thiscall CMatchFramework::GetMatchNetworkMsgController(CMatchFramework *this)
{
  return g_pMatchNetMsgControllerBase;
}

//------------------------------------------------------------------------------
// Address: 0x1000DD90
// Name: public: virtual class IMatchSystem __near * CMatchFramework::GetMatchSystem(void)
// Source: json
//------------------------------------------------------------------------------
CMatchSystem *__thiscall CMatchFramework::GetMatchSystem(CMatchFramework *this)
{
  return g_pMatchSystem;
}

//------------------------------------------------------------------------------
// Address: 0x1000DDA0
// Name: public: virtual void CMatchFramework::ApplySettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::ApplySettings(CMatchFramework *this, KeyValues *keyValues)
{
  g_pMatchExtensions->m_exts.m_pIServerGameDLL->ApplyGameSettings(
    this: g_pMatchExtensions->m_exts.m_pIServerGameDLL,
    a2: keyValues);
}

//------------------------------------------------------------------------------
// Address: 0x1000DDC0
// Name: JoinInviteSession
// Source: json
//------------------------------------------------------------------------------
void JoinInviteSession()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi
  KeyValues *v2; // esi

  s_bInviteSessionDelayedJoin = false;
  if ( s_InviteInfo != 0 )
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->IsDrawingLoadingImage(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)
      || g_pMatchEventsSubscription != nullptr && g_pMatchEventsSubscription->m_bBroadcasting )
    {
      s_bInviteSessionDelayedJoin = true;
    }
    else
    {
      DevMsg(a1: "JoinInviteSession: sessionid = %llx\n", s_InviteInfo);
      s_nInviteConfirmed = -1;
      v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v0 != nullptr
        && (v1 = KeyValues::KeyValues(this: v0, setName: "OnInvite")) != nullptr
        && (KeyValues::SetUint64(this: v1, keyName: "sessionid", value: s_InviteInfo),
            KeyValues::SetString(this: v1, keyName: "action", value: "storage"),
            KeyValues::SetPtr(this: v1, keyName: "confirmed", value: &s_nInviteConfirmed),
            g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v1),
            s_nInviteConfirmed != -1) )
      {
        DevMsg(a1: "JoinInviteSession: waiting for storage device selection...\n");
      }
      else
      {
        DevMsg(a1: "JoinInviteSession: verifying eligibility...\n");
        DevMsg(a1: "JoinInviteSession: connecting...\n");
        v2 = KeyValues::FromString(
               szName: "settings",
               szStringVal: " system {  network LIVE  }  options {  action joinsession  } ",
               ppEndOfParse: nullptr);
        KeyValues::SetUint64(this: v2, keyName: "options/sessionid", value: s_InviteInfo);
        _V_memset(dest: &s_InviteInfo, fill: 0, count: 8);
        g_pMatchFramework->MatchSession(this: g_pMatchFramework, a2: v2);
        if ( v2 != nullptr )
          KeyValues::deleteThis(this: v2);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DF20
// Name: OnInviteAccepted
// Source: json
//------------------------------------------------------------------------------
void OnInviteAccepted()
{
  KeyValues *v0; // eax
  KeyValues *v1; // esi

  DevMsg(a1: "OnInviteAccepted: verifying eligibility...\n");
  DevMsg(a1: "OnInviteAccepted: confirming...\n");
  s_nInviteConfirmed = -1;
  v0 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v0 != nullptr
    && (v1 = KeyValues::KeyValues(this: v0, setName: "OnInvite")) != nullptr
    && (KeyValues::SetUint64(this: v1, keyName: "sessionid", value: s_InviteInfo),
        KeyValues::SetString(this: v1, keyName: "action", value: "accepted"),
        KeyValues::SetPtr(this: v1, keyName: "confirmed", value: &s_nInviteConfirmed),
        g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v1),
        s_nInviteConfirmed != -1) )
  {
    DevMsg(a1: "OnInviteAccepted: waiting for confirmation...\n");
  }
  else
  {
    DevMsg(a1: "OnInviteAccepted: accepting...\n");
    JoinInviteSession();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000DFE0
// Name: public: void CMatchSteamInviteListener::Steam_OnGameLobbyJoinRequested(struct GameLobbyJoinRequested_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSteamInviteListener::Steam_OnGameLobbyJoinRequested(
        CMatchSteamInviteListener *this,
        GameLobbyJoinRequested_t *pJoinInvite)
{
  int m_unAll64Bits_high; // ecx
  __int64 v4; // [esp+10h] [ebp-8h]
  char v5; // [esp+16h] [ebp-2h]

  HIWORD(v4) = v5 & 0xF;
  this->m_msgPending.m_steamIDLobby.m_steamid.m_unAll64Bits = 0;
  this->m_msgPending.m_steamIDFriend.m_steamid.m_unAll64Bits = v4 & 0xFFF0000000000000uLL;
  LODWORD(s_InviteInfo) = pJoinInvite->m_steamIDLobby.m_steamid.m_comp;
  m_unAll64Bits_high = HIDWORD(pJoinInvite->m_steamIDLobby.m_steamid.m_unAll64Bits);
  s_bInviteSessionDelayedJoin = false;
  HIDWORD(s_InviteInfo) = m_unAll64Bits_high;
  if ( (m_unAll64Bits_high | (unsigned int)s_InviteInfo) != 0 )
  {
    if ( g_pMatchExtensions->m_exts.m_pIVEngineClient->IsDrawingLoadingImage(this: g_pMatchExtensions->m_exts.m_pIVEngineClient)
      || g_pMatchEventsSubscription != nullptr && g_pMatchEventsSubscription->m_bBroadcasting )
    {
      this->m_msgPending = *pJoinInvite;
    }
    else
    {
      OnInviteAccepted();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E090
// Name: public: void CMatchSteamInviteListener::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSteamInviteListener::RunFrame(CMatchSteamInviteListener *this)
{
  int m_unAll64Bits_high; // esi
  unsigned int v2; // eax
  GameLobbyJoinRequested_t msgRequest; // [esp+4h] [ebp-10h] BYREF

  m_unAll64Bits_high = HIDWORD(this->m_msgPending.m_steamIDLobby.m_steamid.m_unAll64Bits);
  v2 = ((unsigned int)m_unAll64Bits_high >> 20) & 0xF;
  if ( v2 != 0
    && v2 < 0xB
    && m_unAll64Bits_high >> 24 > 0
    && m_unAll64Bits_high >> 24 < 6
    && (v2 != 1 || this->m_msgPending.m_steamIDLobby.m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 1)
    && (v2 != 7 || this->m_msgPending.m_steamIDLobby.m_steamid.m_comp != 0 && (m_unAll64Bits_high & 0xFFFFF) == 0) )
  {
    msgRequest = this->m_msgPending;
    CMatchSteamInviteListener::Steam_OnGameLobbyJoinRequested(this, pJoinInvite: &msgRequest);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E110
// Name: public: virtual void CMatchFramework::CreateSession(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::CreateSession(CMatchFramework *this, KeyValues *pSettings)
{
  const char *String; // edi
  CMatchSessionOfflineCustom *v4; // eax
  CMatchSessionOfflineCustom *v5; // eax
  CMatchSessionOnlineHost *v6; // eax
  IMatchSessionInternal *v7; // esi

  if ( pSettings != nullptr )
  {
    String = KeyValues::GetString(this: pSettings, keyName: "system/network", defaultValue: "offline");
    PlayerManager::RecomputePlayerXUIDs(this: g_pPlayerManager, szNetwork: String);
    if ( _V_stricmp(s1: "offline", s2: String) != 0 )
    {
      v6 = (CMatchSessionOnlineHost *)operator new(nSize: 0x28u);
      if ( v6 != nullptr )
        v5 = (CMatchSessionOfflineCustom *)CMatchSessionOnlineHost::CMatchSessionOnlineHost(this: v6, pSettings);
      else
        v5 = nullptr;
    }
    else
    {
      v4 = (CMatchSessionOfflineCustom *)operator new(nSize: 0x18u);
      if ( v4 != nullptr )
        v5 = CMatchSessionOfflineCustom::CMatchSessionOfflineCustom(this: v4, pSettings);
      else
        v5 = nullptr;
    }
    v7 = v5;
    if ( v5 != nullptr )
    {
      this->CloseSession(this);
      this->m_pMatchSession = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E1A0
// Name: public: virtual void CMatchFramework::MatchSession(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::MatchSession(CMatchFramework *this, KeyValues *pSettings)
{
  const char *String; // ebx
  const char *v3; // edi
  CMatchSessionOnlineClient *v4; // eax
  CMatchSessionOnlineSearch *v5; // eax
  CMatchSessionOnlineSearch *v6; // eax
  IMatchSessionInternal *v7; // esi

  if ( pSettings != nullptr )
  {
    String = KeyValues::GetString(this: pSettings, keyName: "system/network", defaultValue: "LIVE");
    v3 = KeyValues::GetString(this: pSettings, keyName: "options/action", defaultValue: defaultValue);
    PlayerManager::RecomputePlayerXUIDs(this: g_pPlayerManager, szNetwork: String);
    if ( _V_stricmp(s1: "joinsession", s2: v3) != 0 )
    {
      if ( _V_stricmp(s1: "joininvitesession", s2: v3) == 0 )
        return;
      v6 = (CMatchSessionOnlineSearch *)operator new(nSize: 0x30u);
      if ( v6 != nullptr )
        v5 = CMatchSessionOnlineSearch::CMatchSessionOnlineSearch(this: v6, pSettings);
      else
        v5 = nullptr;
    }
    else
    {
      v4 = (CMatchSessionOnlineClient *)operator new(nSize: 0x20u);
      if ( v4 != nullptr )
        v5 = (CMatchSessionOnlineSearch *)CMatchSessionOnlineClient::CMatchSessionOnlineClient(this: v4, pSettings);
      else
        v5 = nullptr;
    }
    v7 = v5;
    if ( v5 != nullptr )
    {
      this->CloseSession(this);
      this->m_pMatchSession = v7;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E260
// Name: public: virtual void CMatchFramework::CloseSession(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::CloseSession(CMatchFramework *this)
{
  IMatchSessionInternal *m_pMatchSession; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  m_pMatchSession = this->m_pMatchSession;
  if ( m_pMatchSession != nullptr )
  {
    this->m_pMatchSession = nullptr;
    m_pMatchSession->Destroy(this: m_pMatchSession);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "OnMatchSessionUpdate", firstKey: "state", firstValue: "closed");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
    }
    else
    {
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E2C0
// Name: public: virtual bool CMatchFramework::IsOnlineGame(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CMatchFramework::IsOnlineGame(CMatchFramework *this)
{
  IMatchSession *v1; // esi
  KeyValues *v2; // eax
  const char *String; // eax
  bool result; // al

  v1 = this->GetMatchSession(this);
  result = false;
  if ( v1 != nullptr && v1->GetSessionSystemData(this: v1) != 0 )
  {
    v2 = v1->GetSessionSettings(this: v1);
    if ( v2 != nullptr )
    {
      String = KeyValues::GetString(this: v2, keyName: "system/network", defaultValue: nullptr);
      if ( String != nullptr && _V_stricmp(s1: "LIVE", s2: String) == 0 )
        return true;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E320
// Name: public: virtual void CMatchFramework::UpdateTeamProperties(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::UpdateTeamProperties(CMatchFramework *this, KeyValues *pTeamProperties)
{
  IMatchSession *v3; // edi
  IMatchTitleGameSettingsMgr *v4; // eax
  IMatchTitleGameSettingsMgr *v5; // esi
  int v6; // eax

  v3 = this->GetMatchSession(this);
  v4 = this->GetMatchTitleGameSettingsMgr(this);
  v5 = v4;
  if ( v3 != nullptr && v4 != nullptr )
  {
    v6 = (int)v3->GetSessionSettings(this: v3);
    v5->UpdateTeamProperties(this: v5, a2: (KeyValues *)v6, a3: pTeamProperties);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E360
// Name: public: virtual void CMatchFramework::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::OnEvent(CMatchFramework *this, KeyValues *pEvent)
{
  const char *Name; // edi
  const char *String; // eax
  const char *v5; // eax
  GameLobbyJoinRequested_t msg; // [esp+Ch] [ebp-10h] BYREF

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "mmF->CloseSession", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "OnInvite", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "OnSteamOverlayCall::LobbyJoin", s2: Name) != 0 )
      {
        if ( g_pPlayerManager != nullptr )
          g_pPlayerManager->OnEvent(this: &g_pPlayerManager->IMatchEventsSink, a2: pEvent);
        if ( g_pServerManager != nullptr )
          g_pServerManager->OnEvent(this: &g_pServerManager->IMatchEventsSink, a2: pEvent);
        if ( g_pDatacenter != nullptr )
          g_pDatacenter->OnEvent(this: &g_pDatacenter->IMatchEventsSink, a2: pEvent);
        if ( g_pDlcManager != nullptr )
          g_pDlcManager->OnEvent(this: &g_pDlcManager->IMatchEventsSink, a2: pEvent);
        if ( g_pIMatchTitleEventsSink != nullptr )
          g_pIMatchTitleEventsSink->OnEvent(this: g_pIMatchTitleEventsSink, a2: pEvent);
        if ( this->IMatchEventsSink::__vftable != nullptr )
          (*(void (__thiscall **)(IMatchEventsSink_vtbl *, KeyValues *))this->IMatchEventsSink::__vftable[1].OnEvent)(
            a1: this->IMatchEventsSink::__vftable + 1,
            a2: pEvent);
      }
      else
      {
        msg.m_steamIDLobby.m_steamid.m_unAll64Bits = KeyValues::GetUint64(
                                                       this: pEvent,
                                                       keyName: "sessionid",
                                                       defaultValue: 0);
        msg.m_steamIDFriend.m_steamid.m_unAll64Bits = -1;
        CMatchSteamInviteListener::Steam_OnGameLobbyJoinRequested(this: &g_MatchSteamInviteListener, pJoinInvite: &msg);
      }
    }
    else
    {
      String = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: defaultValue);
      if ( _V_stricmp(s1: "join", s2: String) != 0 )
      {
        v5 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: defaultValue);
        if ( _V_stricmp(s1: "deny", s2: v5) == 0 )
        {
          _V_memset(dest: &s_InviteInfo, fill: 0, count: 8);
          s_bInviteSessionDelayedJoin = false;
        }
      }
      else
      {
        s_bInviteSessionDelayedJoin = true;
      }
    }
  }
  else
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 76))(a1: (char *)this - 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E4F0
// Name: public: void CMatchFramework::SetCurrentMatchSession(class IMatchSessionInternal __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::SetCurrentMatchSession(CMatchFramework *this, IMatchSessionInternal *pNewMatchSession)
{
  this->m_pMatchSession = pNewMatchSession;
}

//------------------------------------------------------------------------------
// Address: 0x1000E500
// Name: public: unsigned __int64 CMatchFramework::GetLastInviteFlags(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CMatchFramework::GetLastInviteFlags(CMatchFramework *this)
{
  return g_uiLastInviteFlags;
}

//------------------------------------------------------------------------------
// Address: 0x1000E520
// Name: public: virtual void CBaseAppSystem<class IMatchFramework>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IMatchFramework>::Reconnect(
        CBaseAppSystem<IMatchFramework> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1000E540
// Name: public: virtual void CMatchFramework::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::RunFrame(CMatchFramework *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( mm_events_listeners_validation.m_pParent != nullptr
    && mm_events_listeners_validation.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "mm_events_listeners_validation");
    else
      v3 = nullptr;
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
  }
  if ( s_bInviteSessionDelayedJoin )
    JoinInviteSession();
  CMatchSteamInviteListener::RunFrame(this: &g_MatchSteamInviteListener);
  CSysSessionStubForTeamSearch<CSysSessionHost>::Voice_CaptureAndTransmitLocalVoiceData(this: (CSysSessionStubForTeamSearch<CSysSessionHost> *)g_pConnectionlessLanMgr);
  CMatchSystem::Update(this: g_pMatchSystem);
  if ( this->m_pMatchSession != nullptr )
    this->m_pMatchSession->Update(this: this->m_pMatchSession);
}

//------------------------------------------------------------------------------
// Address: 0x1000E5C0
// Name: private: virtual int CCallback<class PlayerLocal,struct PersonaStateChange_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<PlayerLocal,PersonaStateChange_t,0>::GetCallbackSizeBytes(
        CCallback<PlayerLocal,PersonaStateChange_t,0> *this)
{
  return 16;
}

//------------------------------------------------------------------------------
// Address: 0x1000E5D0
// Name: public: virtual enum InitReturnVal_t CMatchFramework::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CMatchFramework::Init(CMatchFramework *this)
{
  InitReturnVal_t result; // eax

  result = MM_Title_Init();
  if ( result == INIT_OK )
  {
    if ( CMatchSteamInviteListener::Steam_OnGameLobbyJoinRequested != nullptr )
    {
      if ( (g_MatchSteamInviteListener.m_CallbackOnGameLobbyJoinRequested.m_nCallbackFlags & 1) != 0 )
        _SteamAPI_UnregisterCallback(a1: &g_MatchSteamInviteListener);
      g_MatchSteamInviteListener.m_CallbackOnGameLobbyJoinRequested.m_pObj = &g_MatchSteamInviteListener;
      g_MatchSteamInviteListener.m_CallbackOnGameLobbyJoinRequested.m_Func = CMatchSteamInviteListener::Steam_OnGameLobbyJoinRequested;
      _SteamAPI_RegisterCallback(a1: &g_MatchSteamInviteListener, a2: 333);
    }
    return INIT_OK;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E630
// Name: public: CMatchFramework::CMatchFramework(void)
// Source: json
//------------------------------------------------------------------------------
CMatchFramework *__thiscall CMatchFramework::CMatchFramework(CMatchFramework *this)
{
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->CTier2AppSystem<IMatchFramework,0>::CTier1AppSystem<IMatchFramework,0>::CTier0AppSystem<IMatchFramework>::CBaseAppSystem<IMatchFramework>::IMatchFramework::IAppSystem::__vftable = (CMatchFramework_vtbl *)&CMatchFramework::`vftable'{for `CTier2AppSystem<IMatchFramework,0>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchFramework::`vftable'{for `IMatchEventsSink'};
  this->m_pMatchSession = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001C0C0
// Name: private: virtual int CCallback<class CSysSessionBase,struct LobbyChatUpdate_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CSysSessionBase,LobbyChatUpdate_t,0>::GetCallbackSizeBytes(
        CCallback<CSysSessionBase,LobbyChatUpdate_t,0> *this)
{
  return 32;
}

//------------------------------------------------------------------------------
// Address: 0x10025190
// Name: private: virtual void CCallback<class CDlcManager,struct DlcInstalled_t,0>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CDlcManager,DlcInstalled_t,0>::Run(
        CCallback<CDlcManager,DlcInstalled_t,0> *this,
        void *pvParam)
{
  ((void (__thiscall *)(char *, void *))LODWORD(this->m_Func))(
    a1: (char *)this->m_pObj + HIDWORD(this->m_Func),
    a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x100251B0
// Name: private: virtual void CCallback<class CDlcManager,struct DlcInstalled_t,0>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CDlcManager,DlcInstalled_t,0>::Run(
        CCallback<CDlcManager,DlcInstalled_t,0> *this,
        void *pvParam,
        bool __formal,
        unsigned __int64 a4)
{
  ((void (__thiscall *)(char *, void *))LODWORD(this->m_Func))(
    a1: (char *)this->m_pObj + HIDWORD(this->m_Func),
    a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x100251D0
// Name: public: void CCallback<class CDlcManager,struct DlcInstalled_t,0>::Register(class CDlcManager __near *,void (CDlcManager::*)(struct DlcInstalled_t __near *))
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CDlcManager,DlcInstalled_t,0>::Register(
        CCallback<CDlcManager,DlcInstalled_t,0> *this,
        CDlcManager *pObj,
        void (__thiscall *__ptr64 func)(CDlcManager *this, DlcInstalled_t *))
{
  if ( pObj != nullptr && (_DWORD)func != 0 )
  {
    if ( (this->m_nCallbackFlags & 1) != 0 )
      _SteamAPI_UnregisterCallback(a1: this);
    this->m_pObj = pObj;
    this->m_Func = func;
    _SteamAPI_RegisterCallback(a1: this, a2: 1005);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1002AAA0
// Name: private: virtual void CCallback<class CSysSessionClient,struct LobbyEnter_t,0>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSysSessionClient,LobbyEnter_t,0>::Run(
        CCallback<GCSDK::CGCClient,GCMessageAvailable_t,0> *this,
        GCMessageAvailable_t *pvParam,
        bool __formal,
        unsigned __int64 a4)
{
  this->m_Func(this: this->m_pObj, a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x1002AAC0
// Name: private: virtual int CCallback<class CSysSessionBase,struct P2PSessionRequest_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CSysSessionBase,P2PSessionRequest_t,0>::GetCallbackSizeBytes(
        CCallback<CSysSessionBase,P2PSessionRequest_t,0> *this)
{
  return 8;
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x100011C0
// Name: public: virtual void CMatchFramework::AcceptInvite(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::AcceptInvite(CEmptyConVar *this, int nValue)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10002870
// Name: public: virtual struct AppSystemInfo_t const __near * CBaseAppSystem<class IMatchFramework>::GetDependencies(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseAppSystem<IMatchFramework>::GetDependencies(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10005980
// Name: public: CMatchFramework::~CMatchFramework(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::~CMatchFramework(CMatchFramework *this)
{
  this->CTier2AppSystem<IMatchFramework,0>::CTier1AppSystem<IMatchFramework,0>::CTier0AppSystem<IMatchFramework>::CBaseAppSystem<IMatchFramework>::IMatchFramework::IAppSystem::__vftable = (CMatchFramework_vtbl *)&CMatchFramework::`vftable'{for `CTier2AppSystem<IMatchFramework,0>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchFramework::`vftable'{for `IMatchEventsSink'};
}

//------------------------------------------------------------------------------
// Address: 0x10005990
// Name: public: virtual enum InitReturnVal_t CMatchFramework::Init(void)
// Source: json
//------------------------------------------------------------------------------
InitReturnVal_t __thiscall CMatchFramework::Init(CMatchFramework *this)
{
  return MM_Title_Init();
}

//------------------------------------------------------------------------------
// Address: 0x100059A0
// Name: public: virtual void CMatchFramework::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::Shutdown(CMatchFramework *this)
{
  CMatchEventsSubscription::Shutdown(this: g_pMatchEventsSubscription);
  MM_Title_Shutdown();
  g_pServerManager->EnableServersUpdate(this: g_pServerManager, a2: false);
  g_pDatacenter->EnableUpdate(this: g_pDatacenter, a2: false);
}

//------------------------------------------------------------------------------
// Address: 0x100059D0
// Name: public: virtual class IMatchExtensions __near * CMatchFramework::GetMatchExtensions(void)
// Source: json
//------------------------------------------------------------------------------
CMatchExtensions *__thiscall CMatchFramework::GetMatchExtensions(CMatchFramework *this)
{
  return g_pMatchExtensions;
}

//------------------------------------------------------------------------------
// Address: 0x100059E0
// Name: public: virtual class IMatchEventsSubscription __near * CMatchFramework::GetEventsSubscription(void)
// Source: json
//------------------------------------------------------------------------------
CMatchEventsSubscription *__thiscall CMatchFramework::GetEventsSubscription(CMatchFramework *this)
{
  return g_pMatchEventsSubscription;
}

//------------------------------------------------------------------------------
// Address: 0x100059F0
// Name: public: virtual class IMatchTitle __near * CMatchFramework::GetMatchTitle(void)
// Source: json
//------------------------------------------------------------------------------
IMatchTitle *__thiscall CMatchFramework::GetMatchTitle(CMatchFramework *this)
{
  return g_pIMatchTitle;
}

//------------------------------------------------------------------------------
// Address: 0x10005A00
// Name: public: virtual class IMatchTitleGameSettingsMgr __near * CMatchFramework::GetMatchTitleGameSettingsMgr(void)
// Source: json
//------------------------------------------------------------------------------
IMatchTitleGameSettingsMgr *__thiscall CMatchFramework::GetMatchTitleGameSettingsMgr(CMatchFramework *this)
{
  return g_pIMatchTitleGameSettingsMgr;
}

//------------------------------------------------------------------------------
// Address: 0x10005A10
// Name: public: virtual class IMatchNetworkMsgController __near * CMatchFramework::GetMatchNetworkMsgController(void)
// Source: json
//------------------------------------------------------------------------------
CMatchNetworkMsgControllerBase *__thiscall CMatchFramework::GetMatchNetworkMsgController(CMatchFramework *this)
{
  return g_pMatchNetMsgControllerBase;
}

//------------------------------------------------------------------------------
// Address: 0x10005A20
// Name: public: virtual class IMatchSystem __near * CMatchFramework::GetMatchSystem(void)
// Source: json
//------------------------------------------------------------------------------
CMatchSystem *__thiscall CMatchFramework::GetMatchSystem(CMatchFramework *this)
{
  return g_pMatchSystem;
}

//------------------------------------------------------------------------------
// Address: 0x10005BC0
// Name: public: virtual void CMatchFramework::CloseSession(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::CloseSession(CMatchFramework *this)
{
  IMatchSessionInternal *m_pMatchSession; // eax
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  m_pMatchSession = this->m_pMatchSession;
  if ( m_pMatchSession != nullptr )
  {
    this->m_pMatchSession = nullptr;
    m_pMatchSession->Destroy(this: m_pMatchSession);
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(this: v2, setName: "OnMatchSessionUpdate", firstKey: "state", firstValue: "closed");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
    }
    else
    {
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005CC0
// Name: public: virtual void CMatchFramework::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::OnEvent(CMatchFramework *this, KeyValues *pEvent)
{
  const char *Name; // edi
  const char *String; // eax
  const char *v5; // eax

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "mmF->CloseSession", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "OnInvite", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "OnSteamOverlayCall::LobbyJoin", s2: Name) != 0 )
      {
        if ( g_pPlayerManager != nullptr )
          g_pPlayerManager->OnEvent(this: &g_pPlayerManager->IMatchEventsSink, a2: pEvent);
        if ( g_pServerManager != nullptr )
          g_pServerManager->OnEvent(this: &g_pServerManager->IMatchEventsSink, a2: pEvent);
        if ( g_pDatacenter != nullptr )
          g_pDatacenter->OnEvent(this: &g_pDatacenter->IMatchEventsSink, a2: pEvent);
        if ( g_pDlcManager != nullptr )
          g_pDlcManager->OnEvent(this: &g_pDlcManager->IMatchEventsSink, a2: pEvent);
        if ( g_pIMatchTitleEventsSink != nullptr )
          g_pIMatchTitleEventsSink->OnEvent(this: g_pIMatchTitleEventsSink, a2: pEvent);
        if ( this->IMatchEventsSink::__vftable != nullptr )
          (*(void (__thiscall **)(IMatchEventsSink_vtbl *, KeyValues *))this->IMatchEventsSink::__vftable[1].OnEvent)(
            a1: this->IMatchEventsSink::__vftable + 1,
            a2: pEvent);
      }
    }
    else
    {
      String = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: str);
      if ( _V_stricmp(s1: "join", s2: String) != 0 )
      {
        v5 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: str);
        if ( _V_stricmp(s1: "deny", s2: v5) == 0 )
        {
          _V_memset(dest: &s_InviteInfo, fill: 0, count: 8);
          s_bInviteSessionDelayedJoin = false;
        }
      }
      else
      {
        s_bInviteSessionDelayedJoin = true;
      }
    }
  }
  else
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 76))(a1: (char *)this - 4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005E10
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class IMatchFramework,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<IMatchFramework,0>::GetTier(CTier2AppSystem<IMatchFramework,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10005E20
// Name: public: virtual void CBaseAppSystem<class IMatchFramework>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<IMatchFramework>::Reconnect(
        CBaseAppSystem<IMatchFramework> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x10005E40
// Name: public: virtual void CMatchFramework::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchFramework::RunFrame(CMatchFramework *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax

  if ( mm_events_listeners_validation.m_pParent != nullptr
    && mm_events_listeners_validation.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "mm_events_listeners_validation");
    else
      v3 = nullptr;
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
  }
  if ( s_bInviteSessionDelayedJoin )
    JoinInviteSession();
  SteamApiContext_Shutdown(this: (CServerManager *)g_pConnectionlessLanMgr);
  CMatchSystem::Update(this: g_pMatchSystem);
  if ( this->m_pMatchSession != nullptr )
    this->m_pMatchSession->Update(this: this->m_pMatchSession);
}

//------------------------------------------------------------------------------
// Address: 0x10005EC0
// Name: public: CMatchFramework::CMatchFramework(void)
// Source: json
//------------------------------------------------------------------------------
CMatchFramework *__thiscall CMatchFramework::CMatchFramework(CMatchFramework *this)
{
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->CTier2AppSystem<IMatchFramework,0>::CTier1AppSystem<IMatchFramework,0>::CTier0AppSystem<IMatchFramework>::CBaseAppSystem<IMatchFramework>::IMatchFramework::IAppSystem::__vftable = (CMatchFramework_vtbl *)&CMatchFramework::`vftable'{for `CTier2AppSystem<IMatchFramework,0>'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchFramework::`vftable'{for `IMatchEventsSink'};
  this->m_pMatchSession = nullptr;
  return this;
}

} // namespace matchmaking_ds
