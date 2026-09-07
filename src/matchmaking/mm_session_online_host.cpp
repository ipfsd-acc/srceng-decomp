// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_session_online_host.cpp
// Functions: 23
// ============================================================

#include "matchmaking\mm_session_online_host.h"

//------------------------------------------------------------------------------
// Address: 0x1001EC30
// Name: public: virtual class KeyValues __near * CMatchSessionOnlineHost::GetSessionSystemData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchSessionOnlineHost::GetSessionSystemData(CMatchSessionOnlineHost *this)
{
  CSysSessionHost *m_pSysSession; // ecx
  unsigned __int64 ReservationCookie; // rax
  unsigned __int64 v4; // rax
  KeyValues *m_pSysData; // ecx

  m_pSysSession = this->m_pSysSession;
  if ( m_pSysSession != nullptr )
    ReservationCookie = CSysSessionBase::GetReservationCookie(this: m_pSysSession);
  else
    ReservationCookie = 0;
  KeyValues::SetUint64(this: this->m_pSysData, keyName: "xuidReserve", value: ReservationCookie);
  if ( this->m_pSysSession != nullptr )
    LODWORD(v4) = ((int (__thiscall *)(CSysSessionHost *, _DWORD, _DWORD))this->m_pSysSession->GetHostXuid)(
                    a1: this->m_pSysSession,
                    a2: 0,
                    a3: 0);
  else
    v4 = 0;
  KeyValues::SetUint64(this: this->m_pSysData, keyName: "xuidHost", value: v4);
  m_pSysData = this->m_pSysData;
  if ( this->m_eState == 2 )
  {
    KeyValues::SetString(this: m_pSysData, keyName: "state", value: "lobby");
    return this->m_pSysData;
  }
  else
  {
    if ( this->m_eState == (STATE_LOADING|0x1) )
      KeyValues::SetString(this: m_pSysData, keyName: "state", value: "game");
    else
      KeyValues::SetString(this: m_pSysData, keyName: "state", value: defaultValue);
    return this->m_pSysData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ED00
// Name: public: virtual void CMatchSessionOnlineHost::UpdateSessionSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::UpdateSessionSettings(CMatchSessionOnlineHost *this, KeyValues *pSettings)
{
  IMatchTitleGameSettingsMgr *v3; // eax
  CSysSessionHost *m_pSysSession; // ecx

  if ( this->m_eState >= 2 )
  {
    v3 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
    v3->ExtendGameSettingsUpdateKeys(this: v3, a2: this->m_pSettings, a3: pSettings);
    KeyValues::MergeFrom(this: this->m_pSettings, kvMerge: pSettings, eOp: MERGE_KV_ALL);
    m_pSysSession = this->m_pSysSession;
    if ( m_pSysSession != nullptr )
      CSysSessionHost::OnUpdateSessionSettings(this: m_pSysSession, kv: pSettings);
    MatchSession_BroadcastSessionSettingsUpdate(pUpdateDeletePackage: pSettings);
  }
  else
  {
    _Warning(a1: "CMatchSessionOnlineHost::UpdateSessionSettings is unavailable in state %d!\n", this->m_eState);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001ED70
// Name: protected: void CMatchSessionOnlineHost::OnRunCommand_Match(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnRunCommand_Match(CMatchSessionOnlineHost *this)
{
  KeyValues *v2; // edi
  CMatchSessionOnlineTeamSearch *m_pTeamSearcher; // ecx
  CMatchSessionOnlineTeamSearch *v4; // eax

  this->m_eState = STATE_MATCHING;
  v2 = KeyValues::FromString(
         szName: "update",
         szStringVal: (KeyValues *)" update {  system {  lock matching  }  } ",
         ppEndOfParse: nullptr);
  this->UpdateSessionSettings(this, a2: v2);
  if ( v2 != nullptr )
    KeyValues::deleteThis(this: v2);
  this->OnGamePrepareLobbyForGame(this);
  m_pTeamSearcher = this->m_pTeamSearcher;
  if ( m_pTeamSearcher != nullptr )
  {
    m_pTeamSearcher->Destroy(this: m_pTeamSearcher);
    this->m_pTeamSearcher = nullptr;
  }
  v4 = (CMatchSessionOnlineTeamSearch *)operator new(nSize: 0x60u);
  if ( v4 != nullptr )
    this->m_pTeamSearcher = CMatchSessionOnlineTeamSearch::CMatchSessionOnlineTeamSearch(
                              this: v4,
                              pSettings: this->m_pSettings,
                              pHost: this);
  else
    this->m_pTeamSearcher = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001EDF0
// Name: protected: void CMatchSessionOnlineHost::OnRunCommand_Cancel_Match(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnRunCommand_Cancel_Match(CMatchSessionOnlineHost *this)
{
  CMatchSessionOnlineTeamSearch *m_pTeamSearcher; // ecx
  KeyValues *v3; // edi

  m_pTeamSearcher = this->m_pTeamSearcher;
  if ( m_pTeamSearcher != nullptr )
  {
    m_pTeamSearcher->Destroy(this: m_pTeamSearcher);
    this->m_pTeamSearcher = nullptr;
  }
  this->m_eState = 2;
  v3 = KeyValues::FromString(
         szName: "update",
         szStringVal: (KeyValues *)" update {  system {  lock #empty#  }  } ",
         ppEndOfParse: nullptr);
  this->UpdateSessionSettings(this, a2: v3);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001EE40
// Name: protected: void CMatchSessionOnlineHost::OnRunCommand_Cancel_DsSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnRunCommand_Cancel_DsSearch(CMatchSessionOnlineHost *this)
{
  CDsSearcher *m_pDsSearcher; // ecx
  KeyValues *v3; // edi

  m_pDsSearcher = this->m_pDsSearcher;
  if ( m_pDsSearcher != nullptr )
  {
    m_pDsSearcher->Destroy(this: m_pDsSearcher);
    this->m_pDsSearcher = nullptr;
  }
  this->m_eState = 2;
  v3 = KeyValues::FromString(
         szName: "update",
         szStringVal: (KeyValues *)" update {  system {  lock #empty#  }  } ",
         ppEndOfParse: nullptr);
  this->UpdateSessionSettings(this, a2: v3);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001EE90
// Name: protected: void CMatchSessionOnlineHost::MigrateGameSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::MigrateGameSettings(CMatchSessionOnlineHost *this)
{
  KeyValues *v2; // edi
  char *String; // edi
  KeyValues *v4; // ebx
  int v5; // eax
  IMatchTitleGameSettingsMgr *v6; // eax
  IMatchTitleGameSettingsMgr_vtbl *v7; // edi
  KeyValues *Key; // eax
  IMatchTitleGameSettingsMgr *v9; // [esp+4h] [ebp-8h]
  char *bEndGameTransition; // [esp+8h] [ebp-4h]

  if ( g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) == this )
  {
    if ( this->m_eState == 2 )
    {
      String = KeyValues::GetString(this: this->m_pSettings, keyName: "server/server", defaultValue: nullptr);
      bEndGameTransition = KeyValues::GetString(
                             this: this->m_pSettings,
                             keyName: "system/lock",
                             defaultValue: defaultValue);
      v4 = KeyValues::FromString(
             szName: "updatedelete",
             szStringVal: (KeyValues *)" update {  system {  lock #empty#  }  }  delete {  server delete  } ",
             ppEndOfParse: nullptr);
      if ( String != nullptr
        || (v5 = _V_stricmp(s1: bEndGameTransition, s2: "endgame"), LOBYTE(bEndGameTransition) = 0, v5 == 0) )
      {
        LOBYTE(bEndGameTransition) = 1;
      }
      v6 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
      v7 = v6->__vftable;
      v9 = v6;
      Key = KeyValues::FindKey(this: v4, keyName: "update", bCreate: false);
      v7->ExtendGameSettingsForLobbyTransition(this: v9, a2: this->m_pSettings, a3: Key, a4: (bool)bEndGameTransition);
      this->UpdateSessionSettings(this, a2: v4);
      if ( v4 != nullptr )
        KeyValues::deleteThis(this: v4);
    }
    else if ( this->m_eState == 8 )
    {
      v2 = KeyValues::FromString(
             szName: "updatedelete",
             szStringVal: (KeyValues *)" update {  system {  lock endgame  }  }  delete {  server delete  } ",
             ppEndOfParse: nullptr);
      this->UpdateSessionSettings(this, a2: v2);
      if ( v2 != nullptr )
        KeyValues::deleteThis(this: v2);
    }
  }
  else
  {
    DevWarning(a1: "CMatchSessionOnlineHost::MigrateGameSettings cannot run because our session is not the active session!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001EFB0
// Name: protected: void CMatchSessionOnlineHost::OnRunCommand_Start(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnRunCommand_Start(CMatchSessionOnlineHost *this)
{
  KeyValues *v2; // edi
  CDsSearcher *v3; // edi
  unsigned __int64 ReservationCookie; // rax

  this->m_eState = STATE_STARTING;
  v2 = KeyValues::FromString(
         szName: "update",
         szStringVal: (KeyValues *)" update {  system {  lock starting  }  } ",
         ppEndOfParse: nullptr);
  this->UpdateSessionSettings(this, a2: v2);
  if ( v2 != nullptr )
    KeyValues::deleteThis(this: v2);
  this->OnGamePrepareLobbyForGame(this);
  v3 = (CDsSearcher *)operator new(nSize: 0x348u);
  if ( v3 != nullptr )
  {
    ReservationCookie = CSysSessionBase::GetReservationCookie(this: this->m_pSysSession);
    this->m_pDsSearcher = CDsSearcher::CDsSearcher(
                            this: v3,
                            pSettings: this->m_pSettings,
                            uiReserveCookie: ReservationCookie);
  }
  else
  {
    this->m_pDsSearcher = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F030
// Name: protected: void CMatchSessionOnlineHost::OnRunCommand_StartListenServerStarted(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnRunCommand_StartListenServerStarted(CMatchSessionOnlineHost *this)
{
  KeyValues *Key; // edi
  const char *v3; // eax
  const char *v4; // eax
  IPlayerLocal *v5; // eax
  unsigned __int64 v6; // rax
  unsigned __int64 ReservationCookie; // rax
  INetSupport *m_pINetSupport; // ecx
  unsigned int v9; // ebx
  CMatchSessionOnlineTeamSearch *m_pTeamSearcher; // ecx
  CSysSessionHost *v11; // eax
  KeyValues *v12; // edi
  CMatchSessionOnlineTeamSearch *v13; // esi
  INetSupport::ServerInfo_t v14; // [esp+Ch] [ebp-3Ch] BYREF
  unsigned __int64 uiReservationCookie; // [esp+3Ch] [ebp-Ch]
  KeyValues *kvUpdate; // [esp+44h] [ebp-4h]

  this->m_eState = STATE_LOADING|0x1;
  kvUpdate = KeyValues::FromString(
               szName: "update",
               szStringVal: (KeyValues *)" update {  system {  lock #empty#  }  server {  server listen  }  } ",
               ppEndOfParse: nullptr);
  Key = KeyValues::FindKey(this: kvUpdate, keyName: "update/server", bCreate: false);
  netadr_s::SetIP(this: &v14.m_netAdr, unIP: 0);
  netadr_s::SetPort(this: &v14.m_netAdr, newport: 0);
  netadr_s::SetType(this: &v14.m_netAdr, newtype: NA_IP);
  netadr_s::SetIP(this: &v14.m_netAdrOnline, unIP: 0);
  netadr_s::SetPort(this: &v14.m_netAdrOnline, newport: 0);
  netadr_s::SetType(this: &v14.m_netAdrOnline, newtype: NA_IP);
  memset(dst: (unsigned __int8 *)&v14, value: 0, count: sizeof(v14));
  g_pMatchExtensions->m_exts.m_pINetSupport->GetServerInfo(this: g_pMatchExtensions->m_exts.m_pINetSupport, a2: &v14);
  v3 = netadr_s::ToString(this: &v14.m_netAdr, baseOnly: false);
  KeyValues::SetString(this: Key, keyName: "adrlocal", value: v3);
  v4 = netadr_s::ToString(this: &v14.m_netAdr, baseOnly: false);
  KeyValues::SetString(this: Key, keyName: "adronline", value: v4);
  v5 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
  v6 = v5->GetXUID(this: v5);
  KeyValues::SetUint64(this: Key, keyName: "xuid", value: v6);
  ReservationCookie = CSysSessionBase::GetReservationCookie(this: this->m_pSysSession);
  m_pINetSupport = g_pMatchExtensions->m_exts.m_pINetSupport;
  HIDWORD(uiReservationCookie) = HIDWORD(ReservationCookie);
  v9 = ReservationCookie;
  ((void (__thiscall *)(INetSupport *, _DWORD, _DWORD))m_pINetSupport->UpdateServerReservation)(
    a1: m_pINetSupport,
    a2: ReservationCookie,
    a3: HIDWORD(ReservationCookie));
  KeyValues::SetUint64(this: Key, keyName: "reservationid", value: __PAIR64__(HIDWORD(uiReservationCookie), v9));
  if ( this->m_pTeamSearcher != nullptr )
    KeyValues::SetInt(this: Key, keyName: "team", value: 1);
  m_pTeamSearcher = this->m_pTeamSearcher;
  if ( m_pTeamSearcher != nullptr )
  {
    v11 = CMatchSessionOnlineTeamSearch::LinkSysSession(this: m_pTeamSearcher);
    __RTDynamicCast(
      inptr: v11,
      VfDelta: 0,
      SrcType: &CSysSessionBase `RTTI Type Descriptor',
      TargetType: &CSysSessionHost `RTTI Type Descriptor',
      isReference: 0);
  }
  v12 = kvUpdate;
  this->UpdateSessionSettings(this, a2: kvUpdate);
  CSysSessionBase::SetSessionActiveGameplayState(
    this: this->m_pSysSession,
    bActive: true,
    szSecureServerAddress: nullptr);
  v13 = this->m_pTeamSearcher;
  if ( v13 != nullptr )
    v13->Update(this: v13);
  if ( v12 != nullptr )
    KeyValues::deleteThis(this: v12);
}

//------------------------------------------------------------------------------
// Address: 0x1001F1C0
// Name: protected: void CMatchSessionOnlineHost::ConnectGameServer(struct CDsSearcher::DsResult_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::ConnectGameServer(
        CMatchSessionOnlineHost *this,
        CDsSearcher::DsResult_t *pDsResult)
{
  unsigned int v3; // esi
  CMatchSessionOnlineTeamSearch *m_pTeamSearcher; // ecx
  CSysSessionHost *m_pSysSession; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *m_pSettings; // [esp-4h] [ebp-424h]
  MatchSessionServerInfo_t msInfo; // [esp+8h] [ebp-418h] BYREF

  m_pSettings = this->m_pSettings;
  this->m_eState = STATE_LOADING|0x1;
  MatchSession_PrepareClientForConnect(pSettings: m_pSettings);
  memset(&msInfo, 0, sizeof(msInfo));
  if ( pDsResult != nullptr )
    msInfo.m_dsResult = *pDsResult;
  v3 = 10;
  if ( pDsResult == nullptr )
    v3 = 11;
  m_pTeamSearcher = this->m_pTeamSearcher;
  if ( m_pTeamSearcher != nullptr )
    v3 |= 4u;
  m_pSysSession = this->m_pSysSession;
  if ( m_pTeamSearcher != nullptr )
    m_pSysSession = CMatchSessionOnlineTeamSearch::LinkSysSession(this: m_pTeamSearcher);
  if ( MatchSession_ResolveServerInfo(
         pSettings: this->m_pSettings,
         pSysSession: m_pSysSession,
         info: &msInfo,
         uiResolveFlags: v3) )
  {
    ((void (__thiscall *)(INetSupport *, _DWORD, _DWORD, _DWORD, _DWORD))g_pMatchExtensions->m_exts.m_pINetSupport->UpdateClientReservation)(
      a1: g_pMatchExtensions->m_exts.m_pINetSupport,
      a2: msInfo.m_uiReservationCookie,
      a3: HIDWORD(msInfo.m_uiReservationCookie),
      a4: msInfo.m_xuidJingle,
      a5: HIDWORD(msInfo.m_xuidJingle));
    CSysSessionBase::SetSessionActiveGameplayState(
      this: this->m_pSysSession,
      bActive: true,
      szSecureServerAddress: msInfo.m_szSecureServerAddress);
    g_pMatchExtensions->m_exts.m_pIVEngineClient->StartLoadingScreenForCommand(
      this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
      a2: msInfo.m_szConnectCmd);
  }
  else if ( this->m_pTeamSearcher != nullptr )
  {
    this->m_eState = STATE_MATCHINGRESTART;
  }
  else
  {
    this->m_pSysSession->Destroy(this: this->m_pSysSession);
    this->m_pSysSession = nullptr;
    v6 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v6 != nullptr )
    {
      v7 = KeyValues::KeyValues(
             this: v6,
             setName: "OnMatchSessionUpdate",
             firstKey: "state",
             firstValue: "error",
             secondKey: "error",
             secondValue: "connect");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v7);
    }
    else
    {
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F330
// Name: protected: void CMatchSessionOnlineHost::OnEndGameToLobby(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnEndGameToLobby(CMatchSessionOnlineHost *this)
{
  KeyValues *v2; // edi
  CMatchSessionOnlineTeamSearch *m_pTeamSearcher; // ecx

  this->m_eState = 8;
  v2 = KeyValues::FromString(
         szName: "updatedelete",
         szStringVal: (KeyValues *)" update {  system {  lock endgame  }  }  delete {  server delete  } ",
         ppEndOfParse: nullptr);
  this->UpdateSessionSettings(this, a2: v2);
  if ( v2 != nullptr )
    KeyValues::deleteThis(this: v2);
  g_pMatchExtensions->m_exts.m_pIVEngineClient->ExecuteClientCmd(
    this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
    a2: "disconnect");
  ((void (__thiscall *)(INetSupport *, _DWORD, _DWORD))g_pMatchExtensions->m_exts.m_pINetSupport->UpdateServerReservation)(
    a1: g_pMatchExtensions->m_exts.m_pINetSupport,
    a2: 0,
    a3: 0);
  m_pTeamSearcher = this->m_pTeamSearcher;
  if ( m_pTeamSearcher != nullptr )
  {
    m_pTeamSearcher->Destroy(this: m_pTeamSearcher);
    this->m_pTeamSearcher = nullptr;
  }
  CSysSessionBase::SetSessionActiveGameplayState(
    this: this->m_pSysSession,
    bActive: false,
    szSecureServerAddress: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1001F3C0
// Name: public: CMatchSessionOnlineHost::CMatchSessionOnlineHost(class CSysSessionClient __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSessionOnlineHost *__thiscall CMatchSessionOnlineHost::CMatchSessionOnlineHost(
        CMatchSessionOnlineHost *this,
        CSysSessionClient *pSysSession,
        KeyValues *pExtendedSettings)
{
  KeyValues *Key; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char *String; // edi
  CSysSessionHost *v8; // eax
  CSysSessionHost *v9; // eax
  KeyValues *v10; // ecx
  KeyValues *m_pSettings; // [esp-4h] [ebp-18h]
  IKeyValuesDumpContext pDump; // [esp+Ch] [ebp-8h] BYREF
  int v14; // [esp+10h] [ebp-4h]

  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOnlineHost_vtbl *)&CMatchSessionOnlineHost::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOnlineHost::`vftable'{for `IMatchEventsSink'};
  Key = KeyValues::FindKey(this: pExtendedSettings, keyName: "settings", bCreate: false);
  this->m_pSettings = Key;
  this->m_autodelete_pSettings.m_pKeyValues = Key;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "SysSessionData", firstKey: "type", firstValue: "host");
  else
    v6 = nullptr;
  this->m_pSysData = v6;
  this->m_autodelete_pSysData.m_pKeyValues = v6;
  m_pSettings = this->m_pSettings;
  this->m_eState = 2;
  this->m_pSysSession = nullptr;
  this->m_pDsSearcher = nullptr;
  this->m_pTeamSearcher = nullptr;
  KeyValues::RemoveSubKey(this: pExtendedSettings, subKey: m_pSettings);
  CMatchFramework::SetCurrentMatchSession(this: g_pMMF, pNewMatchSession: this);
  String = KeyValues::GetString(this: pExtendedSettings, keyName: "state", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "game") != 0 )
  {
    if ( _V_stricmp(s1: String, s2: "ending") == 0 )
      this->m_eState = 8;
  }
  else
  {
    this->m_eState = STATE_LOADING|0x1;
  }
  v8 = (CSysSessionHost *)operator new(nSize: 0xD0u);
  if ( v8 != nullptr )
    v9 = CSysSessionHost::CSysSessionHost(this: v8, pClient: pSysSession, pSettings: this->m_pSettings);
  else
    v9 = nullptr;
  this->m_pSysSession = v9;
  pSysSession->Destroy(this: pSysSession);
  CMatchSessionOnlineHost::MigrateGameSettings(this);
  DevMsg(a1: "Migrated into CMatchSessionOnlineHost:\n");
  v10 = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v14 = 1;
  KeyValues::Dump(this: v10, &pDump, nIndentLevel: 1);
  if ( pExtendedSettings != nullptr )
    KeyValues::deleteThis(this: pExtendedSettings);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001F510
// Name: protected: void CMatchSessionOnlineHost::StartListenServerMap(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::StartListenServerMap(CMatchSessionOnlineHost *this)
{
  KeyValues *v2; // edi
  IMatchTitle *v3; // eax
  KeyValues *m_pSettings; // ecx
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  KeyValues *v7; // eax
  KeyValues *v8; // eax
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v10; // [esp+Ch] [ebp-4h]

  v2 = KeyValues::FromString(
         szName: "update",
         szStringVal: (KeyValues *)" update {  system {  lock loading  }  }  delete {  server delete  } ",
         ppEndOfParse: nullptr);
  this->UpdateSessionSettings(this, a2: v2);
  if ( v2 != nullptr )
    KeyValues::deleteThis(this: v2);
  MatchSession_PrepareClientForConnect(pSettings: this->m_pSettings);
  if ( mm_disable_listen_server.m_pParent != nullptr && mm_disable_listen_server.m_pParent->m_Value.m_nValue != 0 )
  {
    _Msg(a1: "Failed to start server map because mm_disable_listen_server was enabled.\n");
    v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v7 != nullptr )
    {
      v8 = KeyValues::KeyValues(
             this: v7,
             setName: "OnMatchSessionUpdate",
             firstKey: "state",
             firstValue: "error",
             secondKey: "error",
             secondValue: "listen server disabled");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v8);
    }
    else
    {
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
    }
  }
  else
  {
    v3 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    if ( !v3->StartServerMap(this: v3, a2: this->m_pSettings) )
    {
      _Warning(a1: "Failed to start server map!\n");
      m_pSettings = this->m_pSettings;
      pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
      v10 = 1;
      KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
      v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v5 != nullptr )
        v6 = KeyValues::KeyValues(
               this: v5,
               setName: "OnMatchSessionUpdate",
               firstKey: "state",
               firstValue: "error",
               secondKey: "error",
               secondValue: "nomap");
      else
        v6 = nullptr;
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v6);
    }
    _Msg(a1: "Succeeded in starting server map!\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001F670
// Name: public: virtual void CMatchSessionOnlineHost::DebugPrint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::DebugPrint(CMatchSessionOnlineHost *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v5; // [esp+Ch] [ebp-4h]

  DevMsg(a1: "CMatchSessionOnlineHost [ state=%d ]\n", this->m_eState);
  DevMsg(a1: "System data:\n");
  v2 = (KeyValues *)this->GetSessionSystemData(this);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v5 = 1;
  KeyValues::Dump(this: v2, &pDump, nIndentLevel: 1);
  DevMsg(a1: "Settings data:\n");
  v3 = this->GetSessionSettings(this);
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v5 = 1;
  KeyValues::Dump(this: v3, &pDump, nIndentLevel: 1);
  if ( this->m_pDsSearcher != nullptr )
    DevMsg(a1: "Dedicated search in progress\n");
  else
    DevMsg(a1: "Dedicated search not active\n");
  if ( this->m_pSysSession != nullptr )
    this->m_pSysSession->DebugPrint(this: this->m_pSysSession);
  else
    DevMsg(a1: "SysSession is NULL\n");
  if ( this->m_pTeamSearcher != nullptr )
    this->m_pTeamSearcher->DebugPrint(this: this->m_pTeamSearcher);
  else
    DevMsg(a1: "TeamSearch is NULL\n");
}

//------------------------------------------------------------------------------
// Address: 0x1001F740
// Name: protected: void CMatchSessionOnlineHost::InitializeGameSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::InitializeGameSettings(CMatchSessionOnlineHost *this)
{
  CMatchSessionOnlineHost *v1; // ebx
  KeyValues *m_pSettings; // ecx
  KeyValues *v3; // ecx
  KeyValues *FirstSubKey; // edi
  KeyValues *v5; // ebx
  KeyValues *NextKey; // eax
  KeyValues *v7; // ecx
  int v8; // esi
  KeyValues *Key; // eax
  KeyValues *v10; // esi
  KeyValues *v11; // esi
  const char *v12; // edi
  char *String; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // edi
  char *v16; // eax
  KeyValues *v17; // eax
  KeyValues *v18; // esi
  KeyValues *v19; // esi
  IPlayerLocal *v20; // eax
  unsigned __int64 v21; // rax
  unsigned __int64 MachineFlags; // rax
  IMatchSystem *v23; // eax
  int v24; // eax
  KeyValues *v25; // eax
  unsigned __int64 Uint64; // rax
  const char *TuInstalledString; // eax
  CFmtStrN<256> *v28; // eax
  KeyValues *v29; // esi
  IPlayerLocal *v30; // edi
  unsigned __int64 v31; // rax
  const char *v32; // eax
  IMatchTitleGameSettingsMgr *v33; // eax
  KeyValues *v34; // ecx
  CFmtStrN<256> v35; // [esp+Ch] [ebp-12Ch] BYREF
  const char *arrKeys[5]; // [esp+118h] [ebp-20h]
  IKeyValuesDumpContext pDump; // [esp+12Ch] [ebp-Ch] BYREF
  const char *szRootSubkeyName; // [esp+130h] [ebp-8h]
  CMatchSessionOnlineHost *v39; // [esp+134h] [ebp-4h]

  v1 = this;
  m_pSettings = this->m_pSettings;
  v39 = v1;
  KeyValues::SetName(this: m_pSettings, setName: "settings");
  v3 = v1->m_pSettings;
  arrKeys[0] = "system";
  arrKeys[1] = "game";
  arrKeys[2] = "options";
  arrKeys[3] = "members";
  arrKeys[4] = "server";
  FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
  if ( FirstSubKey != nullptr )
  {
    do
    {
      v5 = FirstSubKey;
      NextKey = KeyValues::GetNextKey(this: FirstSubKey);
      v7 = FirstSubKey;
      FirstSubKey = NextKey;
      szRootSubkeyName = KeyValues::GetName(this: v7);
      v8 = 0;
      while ( _V_stricmp(s1: arrKeys[v8], s2: szRootSubkeyName) != 0 )
      {
        if ( (unsigned int)++v8 >= 5 )
        {
          KeyValues::RemoveSubKey(this: v39->m_pSettings, subKey: v5);
          KeyValues::deleteThis(this: v5);
          break;
        }
      }
    }
    while ( FirstSubKey != nullptr );
    v1 = v39;
  }
  Key = KeyValues::FindKey(this: v1->m_pSettings, keyName: "system", bCreate: true);
  v10 = Key;
  if ( Key != nullptr )
  {
    if ( KeyValues::FindKey(this: Key, keyName: "network", bCreate: false) == nullptr )
      KeyValues::SetString(this: v10, keyName: "network", value: "LIVE");
    if ( KeyValues::FindKey(this: v10, keyName: "access", bCreate: false) == nullptr )
      KeyValues::SetString(this: v10, keyName: "access", value: "public");
  }
  v11 = KeyValues::FindKey(this: v1->m_pSettings, keyName: "options", bCreate: true);
  if ( v11 != nullptr )
  {
    v12 = "dedicated";
    String = KeyValues::GetString(this: v1->m_pSettings, keyName: "system/network", defaultValue: defaultValue);
    if ( _V_stricmp(s1: "LIVE", s2: String) != 0 )
      v12 = "listen";
    if ( KeyValues::FindKey(this: v11, keyName: "server", bCreate: false) == nullptr )
      KeyValues::SetString(this: v11, keyName: "server", value: v12);
    v14 = KeyValues::FindKey(this: v11, keyName: "action", bCreate: false);
    v15 = v14;
    if ( v14 != nullptr )
    {
      v16 = KeyValues::GetString(this: v14, keyName: nullptr, defaultValue: defaultValue);
      if ( v16 == nullptr || *v16 == 0 || _V_stricmp(s1: "create", s2: v16) == 0 )
      {
        KeyValues::RemoveSubKey(this: v11, subKey: v15);
        KeyValues::deleteThis(this: v15);
      }
    }
  }
  v17 = KeyValues::FindKey(this: v1->m_pSettings, keyName: "members", bCreate: true);
  v18 = v17;
  if ( v17 != nullptr )
  {
    KeyValues::SetInt(this: v17, keyName: "numMachines", value: 1);
    KeyValues::SetInt(this: v18, keyName: "numPlayers", value: 1);
    KeyValues::SetInt(this: v18, keyName: "numSlots", value: 1);
    v19 = KeyValues::FindKey(this: v18, keyName: "machine0", bCreate: true);
    if ( v19 != nullptr )
    {
      v20 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
      v21 = v20->GetXUID(this: v20);
      KeyValues::SetUint64(this: v19, keyName: "id", value: v21);
      MachineFlags = MatchSession_GetMachineFlags();
      KeyValues::SetUint64(this: v19, keyName: "flags", value: MachineFlags);
      KeyValues::SetInt(this: v19, keyName: "numPlayers", value: 1);
      v23 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
      v24 = (int)v23->GetDlcManager(this: v23);
      v25 = (KeyValues *)(*(int (__thiscall **)(int))(*(_DWORD *)v24 + 8))(a1: v24);
      Uint64 = KeyValues::GetUint64(this: v25, keyName: "@info/installed", defaultValue: 0);
      KeyValues::SetUint64(this: v19, keyName: "dlcmask", value: Uint64);
      TuInstalledString = MatchSession_GetTuInstalledString();
      KeyValues::SetString(this: v19, keyName: "tuver", value: TuInstalledString);
      KeyValues::SetInt(this: v19, keyName: "ping", value: 0);
      v28 = CFmtStrN<256>::CFmtStrN<256>(this: &v35, pszFormat: "player%d", 0);
      v29 = KeyValues::FindKey(this: v19, keyName: v28->m_szBuf, bCreate: true);
      if ( v29 != nullptr )
      {
        v30 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
        v31 = v30->GetXUID(this: v30);
        KeyValues::SetUint64(this: v29, keyName: "xuid", value: v31);
        v32 = v30->GetName(this: v30);
        KeyValues::SetString(this: v29, keyName: "name", value: v32);
      }
    }
  }
  v33 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v33->InitializeGameSettings(this: v33, a2: v1->m_pSettings, a3: "host");
  DevMsg(a1: "CMatchSessionOnlineHost::InitializeGameSettings adjusted settings:\n");
  v34 = v1->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  szRootSubkeyName = (const char *)1;
  KeyValues::Dump(this: v34, &pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1001FAA0
// Name: public: CMatchSessionOnlineHost::CMatchSessionOnlineHost(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSessionOnlineHost *__thiscall CMatchSessionOnlineHost::CMatchSessionOnlineHost(
        CMatchSessionOnlineHost *this,
        KeyValues *pSettings)
{
  KeyValues *Copy; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v9; // [esp+Ch] [ebp-4h]

  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOnlineHost_vtbl *)&CMatchSessionOnlineHost::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOnlineHost::`vftable'{for `IMatchEventsSink'};
  Copy = KeyValues::MakeCopy(this: pSettings);
  this->m_pSettings = Copy;
  this->m_autodelete_pSettings.m_pKeyValues = Copy;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SysSessionData", firstKey: "type", firstValue: "host");
  else
    v5 = nullptr;
  this->m_pSysData = v5;
  this->m_autodelete_pSysData.m_pKeyValues = v5;
  this->m_eState = 0;
  this->m_pSysSession = nullptr;
  this->m_pDsSearcher = nullptr;
  this->m_pTeamSearcher = nullptr;
  DevMsg(a1: "Created CMatchSessionOnlineHost:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v9 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  CMatchSessionOnlineHost::InitializeGameSettings(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001FB50
// Name: protected: void CMatchSessionOnlineHost::OnRunCommand_StartDsSearchFinished(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnRunCommand_StartDsSearchFinished(CMatchSessionOnlineHost *this)
{
  bool v2; // zf
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  KeyValues *v5; // esi
  KeyValues *Key; // eax
  CDsSearcher::DsResult_t dsResult; // [esp+Ch] [ebp-304h] BYREF

  dsResult = *this->m_pDsSearcher->GetResult(this: this->m_pDsSearcher);
  if ( dsResult.m_bAborted )
  {
    CMatchSessionOnlineHost::OnRunCommand_Cancel_DsSearch(this);
    return;
  }
  this->m_pDsSearcher->Destroy(this: this->m_pDsSearcher);
  v2 = !dsResult.m_bDedicated;
  this->m_pDsSearcher = nullptr;
  if ( v2 )
  {
    if ( KeyValues::GetString(this: this->m_pSettings, keyName: "server/server", defaultValue: nullptr) != nullptr )
    {
      v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v3 != nullptr )
        v4 = KeyValues::KeyValues(this: v3, setName: "mmF->SysSessionUpdate");
      else
        v4 = nullptr;
      KeyValues::SetPtr(this: v4, keyName: "syssession", value: this->m_pSysSession);
      KeyValues::SetString(this: v4, keyName: "error", value: "n/a");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v4);
      return;
    }
    if ( !dsResult.m_bDedicated )
    {
      this->m_eState = STATE_LOADING;
      CMatchSessionOnlineHost::StartListenServerMap(this);
      return;
    }
  }
  v5 = KeyValues::FromString(
         szName: "update",
         szStringVal: (KeyValues *)" update {  system {  lock #empty#  }  server {  server dedicated  }  } ",
         ppEndOfParse: nullptr);
  Key = KeyValues::FindKey(this: v5, keyName: "update/server", bCreate: false);
  CDsSearcher::DsResult_t::CopyToServerKey(this: &dsResult, pKvServer: Key);
  this->UpdateSessionSettings(this, a2: v5);
  CMatchSessionOnlineHost::ConnectGameServer(this, pDsResult: &dsResult);
  if ( v5 != nullptr )
    KeyValues::deleteThis(this: v5);
}

//------------------------------------------------------------------------------
// Address: 0x1001FC90
// Name: public: virtual void CMatchSessionOnlineHost::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::Update(CMatchSessionOnlineHost *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  CSysSessionHost *v4; // eax
  CDsSearcher *m_pDsSearcher; // ecx
  CMatchSessionOnlineTeamSearch *m_pTeamSearcher; // ecx
  CSysSessionHost *m_pSysSession; // ecx

  switch ( this->m_eState )
  {
    case 0:
      this->m_eState = 1;
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
        v3 = KeyValues::KeyValues(
               this: v2,
               setName: "OnMatchSessionUpdate",
               firstKey: "state",
               firstValue: "progress",
               secondKey: "progress",
               secondValue: "creating");
      else
        v3 = nullptr;
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
      v4 = (CSysSessionHost *)operator new(nSize: 0xD0u);
      if ( v4 != nullptr )
        this->m_pSysSession = CSysSessionHost::CSysSessionHost(this: v4, pSettings: this->m_pSettings);
      else
        this->m_pSysSession = nullptr;
      goto LABEL_16;
    case 2:
      if ( KeyValues::GetInt(this: this->m_pSettings, keyName: "options/bypasslobby", defaultValue: 0) != 0 )
        CMatchSessionOnlineHost::OnRunCommand_Start(this);
      goto LABEL_16;
    case 3:
      m_pTeamSearcher = this->m_pTeamSearcher;
      if ( m_pTeamSearcher != nullptr )
        m_pTeamSearcher->Update(this: m_pTeamSearcher);
      goto LABEL_16;
    case 4:
      CMatchSessionOnlineHost::OnRunCommand_Match(this);
      goto LABEL_16;
    case 5:
      m_pDsSearcher = this->m_pDsSearcher;
      if ( m_pDsSearcher == nullptr )
        goto LABEL_16;
      m_pDsSearcher->Update(this: m_pDsSearcher);
      if ( !this->m_pDsSearcher->IsFinished(this: this->m_pDsSearcher) )
        goto LABEL_16;
      CMatchSessionOnlineHost::OnRunCommand_StartDsSearchFinished(this);
      break;
    default:
LABEL_16:
      m_pSysSession = this->m_pSysSession;
      if ( m_pSysSession != nullptr )
        m_pSysSession->Update(this: m_pSysSession);
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001FDA0
// Name: public: virtual void CMatchSessionOnlineHost::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::Destroy(CMatchSessionOnlineHost *this)
{
  char *String; // eax
  IGameEvent *v3; // eax
  IGameEvent *v4; // edi
  CMatchSessionOnlineTeamSearch *m_pTeamSearcher; // ecx
  CDsSearcher *m_pDsSearcher; // ecx
  CSysSessionHost *m_pSysSession; // ecx
  KeyValues *m_pSettings; // ecx
  KeyValues *m_pKeyValues; // ecx
  KeyValues *v10; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v12; // [esp+8h] [ebp-4h]

  ((void (__thiscall *)(INetSupport *, _DWORD, _DWORD, _DWORD, _DWORD))g_pMatchExtensions->m_exts.m_pINetSupport->UpdateClientReservation)(
    a1: g_pMatchExtensions->m_exts.m_pINetSupport,
    a2: 0,
    a3: 0,
    a4: 0,
    a5: 0);
  if ( this->m_eState > 2 )
  {
    String = KeyValues::GetString(this: this->m_pSettings, keyName: "server/server", defaultValue: "listen");
    if ( _V_stricmp(s1: String, s2: "listen") == 0 )
    {
      v3 = g_pMatchExtensions->m_exts.m_pIGameEventManager2->CreateEvent(
             this: g_pMatchExtensions->m_exts.m_pIGameEventManager2,
             a2: "server_pre_shutdown",
             a3: 0,
             a4: 0);
      v4 = v3;
      if ( v3 != nullptr )
      {
        v3->SetString(this: v3, a2: "reason", a3: "quit");
        g_pMatchExtensions->m_exts.m_pIGameEventManager2->FireEvent(
          this: g_pMatchExtensions->m_exts.m_pIGameEventManager2,
          a2: v4,
          a3: false);
      }
    }
    g_pMatchExtensions->m_exts.m_pIVEngineClient->ExecuteClientCmd(
      this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
      a2: "disconnect");
  }
  m_pTeamSearcher = this->m_pTeamSearcher;
  if ( m_pTeamSearcher != nullptr )
  {
    m_pTeamSearcher->Destroy(this: m_pTeamSearcher);
    this->m_pTeamSearcher = nullptr;
  }
  m_pDsSearcher = this->m_pDsSearcher;
  if ( m_pDsSearcher != nullptr )
  {
    m_pDsSearcher->Destroy(this: m_pDsSearcher);
    this->m_pDsSearcher = nullptr;
  }
  m_pSysSession = this->m_pSysSession;
  if ( m_pSysSession != nullptr )
  {
    m_pSysSession->Destroy(this: m_pSysSession);
    this->m_pSysSession = nullptr;
  }
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOnlineHost_vtbl *)&CMatchSessionOnlineHost::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOnlineHost::`vftable'{for `IMatchEventsSink'};
  DevMsg(a1: "Destroying CMatchSessionOnlineHost:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v12 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  m_pKeyValues = this->m_autodelete_pSysData.m_pKeyValues;
  if ( m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: m_pKeyValues);
  v10 = this->m_autodelete_pSettings.m_pKeyValues;
  if ( v10 != nullptr )
    KeyValues::deleteThis(this: v10);
  free(pMem: this);
  ((void (__thiscall *)(INetSupport *, _DWORD, _DWORD))g_pMatchExtensions->m_exts.m_pINetSupport->UpdateServerReservation)(
    a1: g_pMatchExtensions->m_exts.m_pINetSupport,
    a2: 0,
    a3: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1001FF00
// Name: protected: void CMatchSessionOnlineHost::OnRunCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnRunCommand(CMatchSessionOnlineHost *this, KeyValues *pCommand)
{
  const char *Name; // ebx
  CSysSessionHost *v4; // ecx
  CSysSessionHost *v5; // ecx
  KeyValues *m_pSettings; // ecx
  int Int; // eax
  KeyValues **m_pMemory; // ebx
  IMatchTitleGameSettingsMgr *v9; // eax
  KeyValues *(__thiscall *GetSessionSystemData)(struct CMatchSessionOnlineHost *); // edx
  IMatchTitleGameSettingsMgr *v11; // edi
  int v12; // eax
  int i; // edi
  CSysSessionHost *m_pSysSession; // ecx
  KeyValues *Copy; // esi
  const char *v16; // eax
  CFmtStrN<256> *v17; // eax
  KeyValues *v18; // [esp-8h] [ebp-138h]
  CFmtStrN<256> v19; // [esp+Ch] [ebp-124h] BYREF
  IMatchTitleGameSettingsMgr_vtbl *v20; // [esp+118h] [ebp-18h]
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > arrPlayersUpdated; // [esp+11Ch] [ebp-14h] BYREF

  Name = KeyValues::GetName(this: pCommand);
  if ( _V_stricmp(s1: "Start", s2: Name) == 0 && this->m_eState == 2 )
  {
    CMatchSessionOnlineHost::OnRunCommand_Start(this);
    return;
  }
  if ( _V_stricmp(s1: "Match", s2: Name) == 0 && this->m_eState == 2 )
  {
    CMatchSessionOnlineHost::OnRunCommand_Match(this);
    return;
  }
  if ( _V_stricmp(s1: "Cancel", s2: Name) == 0 )
  {
    if ( this->m_eState == STATE_MATCHING )
    {
      CMatchSessionOnlineHost::OnRunCommand_Cancel_Match(this);
      return;
    }
    if ( this->m_eState == STATE_STARTING )
    {
      CMatchSessionOnlineHost::OnRunCommand_Cancel_DsSearch(this);
      return;
    }
  }
  if ( _V_stricmp(s1: "Kick", s2: Name) != 0 || (v4 = this->m_pSysSession) == nullptr )
  {
    if ( _V_stricmp(s1: "Migrate", s2: Name) != 0 || (v5 = this->m_pSysSession) == nullptr )
    {
      m_pSettings = this->m_pSettings;
      memset(&arrPlayersUpdated, 0, sizeof(arrPlayersUpdated));
      Int = KeyValues::GetInt(this: m_pSettings, keyName: "members/numPlayers", defaultValue: 0);
      CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::InsertMultipleBefore(
        this: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&arrPlayersUpdated,
        elem: 0,
        num: Int);
      m_pMemory = arrPlayersUpdated.m_Memory.m_pMemory;
      memset(
        dst: (unsigned __int8 *)arrPlayersUpdated.m_Memory.m_pMemory,
        value: 0,
        count: 4 * arrPlayersUpdated.m_Size);
      v9 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
      GetSessionSystemData = this->GetSessionSystemData;
      v11 = v9;
      v18 = this->m_pSettings;
      v20 = v9->__vftable;
      v12 = ((int (__thiscall *)(CMatchSessionOnlineHost *, KeyValues *, KeyValues **))GetSessionSystemData)(
              a1: this,
              a2: v18,
              a3: m_pMemory);
      ((void (__thiscall *)(IMatchTitleGameSettingsMgr *, KeyValues *, int))v20->ExecuteCommand)(
        a1: v11,
        a2: pCommand,
        a3: v12);
      for ( i = 0; i < arrPlayersUpdated.m_Size; ++i )
      {
        if ( arrPlayersUpdated.m_Memory.m_pMemory[i] == nullptr )
          break;
        m_pSysSession = this->m_pSysSession;
        if ( m_pSysSession != nullptr )
          CSysSessionHost::OnPlayerUpdated(this: m_pSysSession, pPlayer: arrPlayersUpdated.m_Memory.m_pMemory[i]);
      }
      Copy = KeyValues::MakeCopy(this: pCommand);
      v16 = KeyValues::GetName(this: pCommand);
      v17 = CFmtStrN<256>::CFmtStrN<256>(this: &v19, pszFormat: "Command::%s", v16);
      KeyValues::SetName(this: Copy, setName: v17->m_szBuf);
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: Copy);
      if ( arrPlayersUpdated.m_Memory.m_nGrowSize >= 0 && arrPlayersUpdated.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: arrPlayersUpdated.m_Memory.m_pMemory);
    }
    else
    {
      CSysSessionHost::Migrate(this: v5, pCommand);
    }
  }
  else
  {
    CSysSessionHost::KickPlayer(this: v4, pCommand);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020100
// Name: protected: virtual void CMatchSessionOnlineHost::OnGamePrepareLobbyForGame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnGamePrepareLobbyForGame(CMatchSessionOnlineHost *this)
{
  int v1; // esi
  KeyValues *m_pSettings; // ecx
  int Int; // eax
  KeyValues **m_pMemory; // edi
  IMatchTitleGameSettingsMgr *v6; // eax
  CSysSessionHost *m_pSysSession; // ecx
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > arrPlayersUpdated; // [esp+Ch] [ebp-14h] BYREF

  v1 = 0;
  m_pSettings = this->m_pSettings;
  memset(&arrPlayersUpdated, 0, sizeof(arrPlayersUpdated));
  Int = KeyValues::GetInt(this: m_pSettings, keyName: "members/numPlayers", defaultValue: 0);
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::InsertMultipleBefore(
    this: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&arrPlayersUpdated,
    elem: 0,
    num: Int);
  m_pMemory = arrPlayersUpdated.m_Memory.m_pMemory;
  memset(dst: (unsigned __int8 *)arrPlayersUpdated.m_Memory.m_pMemory, value: 0, count: 4 * arrPlayersUpdated.m_Size);
  v6 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v6->PrepareLobbyForGame(this: v6, a2: this->m_pSettings, a3: m_pMemory);
  if ( arrPlayersUpdated.m_Size > 0 )
  {
    do
    {
      if ( m_pMemory[v1] == nullptr )
        break;
      m_pSysSession = this->m_pSysSession;
      if ( m_pSysSession != nullptr )
        CSysSessionHost::OnPlayerUpdated(this: m_pSysSession, pPlayer: m_pMemory[v1]);
      ++v1;
    }
    while ( v1 < arrPlayersUpdated.m_Size );
  }
  if ( arrPlayersUpdated.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100201B0
// Name: protected: virtual void CMatchSessionOnlineHost::OnGamePlayerMachinesConnected(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnGamePlayerMachinesConnected(CMatchSessionOnlineHost *this, int numMachines)
{
  KeyValues *m_pSettings; // ecx
  int Int; // eax
  KeyValues **m_pMemory; // esi
  IMatchTitleGameSettingsMgr *v6; // eax
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int> > arrPlayersUpdated; // [esp+4h] [ebp-14h] BYREF

  if ( this->m_eState == (STATE_LOADING|0x1) )
  {
    m_pSettings = this->m_pSettings;
    memset(&arrPlayersUpdated, 0, sizeof(arrPlayersUpdated));
    Int = KeyValues::GetInt(this: m_pSettings, keyName: "members/numPlayers", defaultValue: 0);
    CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::InsertMultipleBefore(
      this: (CUtlVector<unsigned int,CUtlMemory<unsigned int,int> > *)&arrPlayersUpdated,
      elem: 0,
      num: Int);
    m_pMemory = arrPlayersUpdated.m_Memory.m_pMemory;
    memset(dst: (unsigned __int8 *)arrPlayersUpdated.m_Memory.m_pMemory, value: 0, count: 4 * arrPlayersUpdated.m_Size);
    v6 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
    v6->PrepareLobbyForGame(this: v6, a2: this->m_pSettings, a3: m_pMemory);
    CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&arrPlayersUpdated);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020230
// Name: public: virtual void CMatchSessionOnlineHost::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::OnEvent(CMatchSessionOnlineHost *this, KeyValues *pEvent)
{
  const char *Name; // ebx
  CSysSessionHost *m_pSysSession; // eax
  CDsSearcher *m_pDsSearcher; // eax
  int v7; // ebx
  int v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // edi
  IMatchTitleGameSettingsMgr *v11; // eax
  IMatchTitleGameSettingsMgr_vtbl *v12; // ebx
  KeyValues *v13; // eax
  KeyValues *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // eax
  char *v17; // ebx
  IMatchTitleGameSettingsMgr *v18; // eax
  KeyValues *v19; // eax
  KeyValues *v20; // ebx
  CMatchEventsSubscription_vtbl *v21; // ebx
  KeyValues *Copy; // eax
  int v23; // ebx
  int Int; // eax
  KeyValues *v25; // eax
  const char *v26; // eax
  CMatchSessionOnlineHost::State_t v27; // esi
  char *v28; // eax
  char *v29; // ebx
  KeyValues *v30; // edi
  CFmtStrN<256> *v31; // eax
  char *String; // ebx
  KeyValues *m_pKeyValues; // edi
  KeyValues *v34; // eax
  KeyValues *v35; // eax
  char *v36; // eax
  KeyValues *v37; // eax
  KeyValues *v38; // edi
  const char *v39; // eax
  CSysSessionHost *m_eState; // ebx
  CMatchSessionOnlineClient *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // eax
  KeyValues *v44; // eax
  KeyValues *v45; // eax
  KeyValues *FirstTrueSubKey; // eax
  KeyValues *Key; // eax
  KeyValues *v48; // ebx
  KeyValues *v49; // eax
  void (__thiscall *v50)(CMatchSessionOnlineHost *, KeyValues *); // eax
  CMatchSessionOnlineHost *v51; // esi
  CDsSearcher::DsResult_t *Ptr; // eax
  CFmtStrN<256> v53; // [esp+Ch] [ebp-110h] BYREF
  const char *szDisconnectHdlr; // [esp+118h] [ebp-4h]
  KeyValues *pServerInfob; // [esp+124h] [ebp+8h]
  KeyValues *pServerInfo; // [esp+124h] [ebp+8h]
  KeyValues *pServerInfoa; // [esp+124h] [ebp+8h]
  char pServerInfo_3; // [esp+127h] [ebp+Bh]

  Name = KeyValues::GetName(this: pEvent);
  m_pSysSession = this->m_pSysSession;
  if ( m_pSysSession != nullptr )
    (**((void (__thiscall ***)(int, KeyValues *))&m_pSysSession->__vftable + 1))(
      a1: (int)(&m_pSysSession->__vftable + 1),
      a2: pEvent);
  m_pDsSearcher = this->m_pDsSearcher;
  if ( m_pDsSearcher != nullptr )
    m_pDsSearcher->OnEvent(this: &m_pDsSearcher->IMatchEventsSink, a2: pEvent);
  if ( _V_stricmp(s1: "OnEngineClientSignonStateChange", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "OnEngineDisconnectReason", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "OnEngineEndGame", s2: Name) != 0 )
      {
        if ( _V_stricmp(s1: "OnEngineListenServerStarted", s2: Name) != 0 )
        {
          if ( _V_stricmp(s1: "OnPlayerMachinesConnected", s2: Name) == 0 )
          {
            v23 = *((_DWORD *)this - 1);
            Int = KeyValues::GetInt(this: pEvent, keyName: "numMachines", defaultValue: 0);
            (*(void (__thiscall **)(char *, int))(v23 + 36))(a1: (char *)this - 4, a2: Int);
            return;
          }
          if ( _V_stricmp(s1: "OnNetLanConnectionlessPacket", s2: Name) != 0 )
          {
            if ( _V_stricmp(s1: "OnSysMuteListChanged", s2: Name) != 0 )
            {
              if ( _V_stricmp(s1: "OnMatchSessionUpdate", s2: Name) != 0 )
              {
                if ( _V_stricmp(s1: "TeamSearchResult::ListenHost", s2: Name) == 0 )
                {
                  this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)6;
                  CMatchSessionOnlineHost::StartListenServerMap(this: (CMatchSessionOnlineHost *)((char *)this - 4));
                  return;
                }
                if ( _V_stricmp(s1: "TeamSearchResult::Dedicated", s2: Name) != 0
                  && _V_stricmp(s1: "TeamSearchResult::ListenClient", s2: Name) != 0 )
                {
                  if ( _V_stricmp(s1: "mmF->SysSessionUpdate", s2: Name) != 0 )
                  {
                    if ( _V_stricmp(s1: "mmF->SysSessionCommand", s2: Name) == 0
                      && this->m_eState != 0
                      && KeyValues::GetPtr(this: pEvent, keyName: "syssession", defaultValue: nullptr) == (void *)this->m_eState )
                    {
                      FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pEvent);
                      if ( FirstTrueSubKey != nullptr )
                        CMatchSessionOnlineHost::OnRunCommand(
                          this: (CMatchSessionOnlineHost *)((char *)this - 4),
                          pCommand: FirstTrueSubKey);
                    }
                  }
                  else if ( this->m_eState != 0
                         && KeyValues::GetPtr(this: pEvent, keyName: "syssession", defaultValue: nullptr) == (void *)this->m_eState )
                  {
                    String = KeyValues::GetString(this: pEvent, keyName: "error", defaultValue: nullptr);
                    if ( String != nullptr )
                    {
                      m_pKeyValues = this->m_autodelete_pSysData.m_pKeyValues;
                      (*(void (__thiscall **)(CMatchSessionOnlineHost::State_t))(*(_DWORD *)this->m_eState + 8))(a1: this->m_eState);
                      this->m_eState = 0;
                      this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)1;
                      v34 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                      if ( v34 != nullptr )
                        v35 = KeyValues::KeyValues(
                                this: v34,
                                setName: "OnMatchSessionUpdate",
                                firstKey: "state",
                                firstValue: "error",
                                secondKey: "error",
                                secondValue: String);
                      else
                        v35 = nullptr;
                      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v35);
                      if ( _V_stricmp(s1: String, s2: "migrate") == 0
                        && (m_pKeyValues == (KeyValues *)7 || m_pKeyValues == (KeyValues *)8) )
                      {
                        g_pMatchExtensions->m_exts.m_pIVEngineClient->ExecuteClientCmd(
                          this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
                          a2: "disconnect");
                      }
                    }
                    else
                    {
                      if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)1 )
                      {
                        v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                        if ( v42 != nullptr )
                          v43 = KeyValues::KeyValues(
                                  this: v42,
                                  setName: "OnMatchSessionUpdate",
                                  firstKey: "state",
                                  firstValue: "created");
                        else
                          v43 = nullptr;
                        g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v43);
                        if ( KeyValues::GetString(
                               this: (KeyValues *)this->IMatchSessionInternal::IMatchEventsSink::__vftable,
                               keyName: "server/server",
                               defaultValue: nullptr) != nullptr )
                        {
                          CMatchSessionOnlineHost::OnRunCommand_Start(this: (CMatchSessionOnlineHost *)((char *)this - 4));
                          return;
                        }
                        this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)2;
LABEL_90:
                        v44 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                        if ( v44 != nullptr )
                        {
                          v45 = KeyValues::KeyValues(
                                  this: v44,
                                  setName: "OnMatchSessionUpdate",
                                  firstKey: "state",
                                  firstValue: "ready");
                          g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v45);
                          return;
                        }
                        goto LABEL_92;
                      }
                      v36 = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: nullptr);
                      if ( v36 != nullptr && _V_stricmp(s1: "client", s2: v36) == 0 )
                      {
                        v37 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                        if ( v37 != nullptr )
                          v38 = KeyValues::KeyValues(this: v37, setName: "ExtendedSettings");
                        else
                          v38 = nullptr;
                        v39 = "lobby";
                        if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)7 )
                        {
                          v39 = "game";
                        }
                        else if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)8 )
                        {
                          v39 = "ending";
                        }
                        KeyValues::SetString(this: v38, keyName: "state", value: v39);
                        KeyValues::AddSubKey(
                          this: v38,
                          pSubkey: (KeyValues *)this->IMatchSessionInternal::IMatchEventsSink::__vftable);
                        this->IMatchSessionInternal::IMatchEventsSink::__vftable = nullptr;
                        this->m_pSettings = nullptr;
                        m_eState = (CSysSessionHost *)this->m_eState;
                        this->m_eState = 0;
                        this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)9;
                        CMatchFramework::SetCurrentMatchSession(this: g_pMMF, pNewMatchSession: nullptr);
                        (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 20))(a1: (char *)this - 4);
                        v41 = (CMatchSessionOnlineClient *)operator new(nSize: 0x20u);
                        if ( v41 != nullptr )
                          CMatchSessionOnlineClient::CMatchSessionOnlineClient(
                            this: v41,
                            pSysSession: m_eState,
                            pExtendedSettings: v38);
                      }
                    }
                  }
                }
                else
                {
                  Key = KeyValues::FindKey(this: pEvent, keyName: "server", bCreate: false);
                  pServerInfoa = Key;
                  if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)3
                    && Key != nullptr
                    && this->m_pDsSearcher != nullptr )
                  {
                    v48 = KeyValues::FromString(
                            szName: "update",
                            szStringVal: (KeyValues *)" update {  system {  lock #empty#  }  server {  server dedicated  }  } ",
                            ppEndOfParse: nullptr);
                    v49 = KeyValues::FindKey(this: v48, keyName: "update/server", bCreate: false);
                    KeyValues::MergeFrom(this: v49, kvMerge: pServerInfoa, eOp: MERGE_KV_UPDATE);
                    v50 = *(void (__thiscall **)(CMatchSessionOnlineHost *, KeyValues *))(*((_DWORD *)this - 1) + 8);
                    v51 = (CMatchSessionOnlineHost *)((char *)this - 4);
                    v50(a1: v51, a2: v48);
                    Ptr = (CDsSearcher::DsResult_t *)KeyValues::GetPtr(
                                                       this: pEvent,
                                                       keyName: "dsresult",
                                                       defaultValue: nullptr);
                    if ( Ptr != nullptr )
                      CMatchSessionOnlineHost::ConnectGameServer(this: v51, pDsResult: Ptr);
                    else
                      CMatchSessionOnlineHost::ConnectGameServer(this: v51, pDsResult: nullptr);
                    if ( v48 != nullptr )
                      KeyValues::deleteThis(this: v48);
                  }
                }
              }
              else
              {
                v28 = KeyValues::GetString(this: pEvent, keyName: "state", defaultValue: defaultValue);
                if ( _V_stricmp(s1: "progress", s2: v28) == 0
                  && this->m_pDsSearcher != nullptr
                  && this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)3 )
                {
                  v29 = KeyValues::GetString(this: pEvent, keyName: "progress", defaultValue: defaultValue);
                  pServerInfo = (KeyValues *)KeyValues::GetInt(this: pEvent, keyName: "numResults", defaultValue: 0);
                  if ( _V_stricmp(s1: "restart", s2: v29) != 0 )
                  {
                    v30 = KeyValues::FromString(
                            szName: "update",
                            szStringVal: (KeyValues *)" update {  system {  lock =  }  } ",
                            ppEndOfParse: nullptr);
                    if ( (int)pServerInfo <= 0 )
                      v31 = CFmtStrN<256>::CFmtStrN<256>(this: &v53, pszFormat: "matching%s", v29);
                    else
                      v31 = CFmtStrN<256>::CFmtStrN<256>(this: &v53, pszFormat: "matching%s%d", v29, pServerInfo);
                    KeyValues::SetString(this: v30, keyName: "update/system/lock", value: v31->m_szBuf);
                    (*(void (__thiscall **)(char *, KeyValues *))(*((_DWORD *)this - 1) + 8))(
                      a1: (char *)this - 4,
                      a2: v30);
                    if ( v30 != nullptr )
                      KeyValues::deleteThis(this: v30);
                  }
                  else
                  {
                    this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)4;
                  }
                }
              }
            }
            else
            {
              v27 = this->m_eState;
              if ( v27 != 0 )
                (*(void (__thiscall **)(CMatchSessionOnlineHost::State_t))(*(_DWORD *)v27 + 56))(a1: v27);
            }
          }
          else
          {
            v25 = KeyValues::GetFirstTrueSubKey(this: pEvent);
            v26 = KeyValues::GetName(this: v25);
            if ( this->m_eState != 0
              && (int)this->m_autodelete_pSysData.m_pKeyValues > 1
              && _V_stricmp(s1: v26, s2: "LanSearch") == 0 )
            {
              CSysSessionBase::ReplyLanSearch(this: (CSysSessionBase *)this->m_eState, msg: pEvent);
            }
          }
        }
        else if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)6 )
        {
          CMatchSessionOnlineHost::OnRunCommand_StartListenServerStarted(this: (CMatchSessionOnlineHost *)((char *)this - 4));
        }
        return;
      }
    }
    else
    {
      v16 = this->m_autodelete_pSysData.m_pKeyValues;
      if ( v16 != (KeyValues *)6 && v16 != (KeyValues *)7 )
        return;
      v17 = KeyValues::GetString(this: pEvent, keyName: "reason", defaultValue: defaultValue);
      DevMsg(a1: "OnEngineDisconnectReason %s\n", v17);
      if ( StringAfterPrefix(str: v17, prefix: "Connection to server timed out") != nullptr
        || (pServerInfo_3 = 0, StringAfterPrefix(str: v17, prefix: "Server shutting down") != nullptr) )
      {
        pServerInfo_3 = 1;
      }
      v18 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
      v19 = v18->PrepareClientLobbyForGameDisconnect(
              this: v18,
              a2: (KeyValues *)this->IMatchSessionInternal::IMatchEventsSink::__vftable,
              a3: pEvent);
      v20 = v19;
      if ( v19 != nullptr )
      {
        szDisconnectHdlr = KeyValues::GetString(this: v19, keyName: "disconnecthdlr", defaultValue: defaultValue);
        if ( _V_stricmp(s1: szDisconnectHdlr, s2: "destroy") != 0 )
        {
          if ( _V_stricmp(s1: szDisconnectHdlr, s2: "lobby") == 0 )
            pServerInfo_3 = 1;
        }
        else
        {
          pServerInfo_3 = 0;
        }
        KeyValues::deleteThis(this: v20);
      }
      if ( pServerInfo_3 == 0 )
      {
        v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v14 != nullptr )
          goto LABEL_14;
        goto LABEL_92;
      }
      KeyValues::SetString(this: pEvent, keyName: "disconnecthdlr", value: "lobby");
      v21 = g_pMatchEventsSubscription->__vftable;
      Copy = KeyValues::MakeCopy(this: pEvent);
      v21->RegisterEventData(this: g_pMatchEventsSubscription, a2: Copy);
    }
    CMatchSessionOnlineHost::OnEndGameToLobby(this: (CMatchSessionOnlineHost *)((char *)this - 4));
    return;
  }
  v7 = KeyValues::GetInt(this: pEvent, keyName: "old", defaultValue: 0);
  v8 = KeyValues::GetInt(this: pEvent, keyName: "new", defaultValue: 0);
  if ( v7 >= 2 && v8 < 2 )
  {
    v9 = this->m_autodelete_pSysData.m_pKeyValues;
    if ( v9 != (KeyValues *)6 && v9 != (KeyValues *)7 )
    {
      if ( v9 != (KeyValues *)8 )
        return;
      this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)2;
      v10 = KeyValues::FromString(
              szName: "update",
              szStringVal: (KeyValues *)" update {  system {  lock #empty#  }  } ",
              ppEndOfParse: nullptr);
      v11 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
      v12 = v11->__vftable;
      pServerInfob = (KeyValues *)v11;
      v13 = KeyValues::FindKey(this: v10, keyName: "update", bCreate: false);
      v12->ExtendGameSettingsForLobbyTransition(
        this: (IMatchTitleGameSettingsMgr *)pServerInfob,
        a2: (KeyValues *)this->IMatchSessionInternal::IMatchEventsSink::__vftable,
        a3: v13,
        a4: true);
      (*(void (__thiscall **)(char *, KeyValues *))(*((_DWORD *)this - 1) + 8))(a1: (char *)this - 4, a2: v10);
      if ( v10 != nullptr )
        KeyValues::deleteThis(this: v10);
      goto LABEL_90;
    }
    DevMsg(a1: "OnEngineClientSignonStateChange\n");
    v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v14 != nullptr )
    {
LABEL_14:
      v15 = KeyValues::KeyValues(this: v14, setName: "mmF->CloseSession");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v15);
      return;
    }
LABEL_92:
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10020AA0
// Name: public: virtual void CMatchSessionOnlineHost::Command(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineHost::Command(CMatchSessionOnlineHost *this, KeyValues *pCommand)
{
  char *String; // esi
  const char *szCommand; // [esp+14h] [ebp+8h]

  szCommand = KeyValues::GetName(this: pCommand);
  String = KeyValues::GetString(this: pCommand, keyName: "run", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "all") != 0
    && _V_stricmp(s1: String, s2: "clients") != 0
    && _V_stricmp(s1: String, s2: "xuid") != 0 )
  {
    if ( *String == 0 || _V_stricmp(s1: String, s2: "local") == 0 || _V_stricmp(s1: String, s2: "host") == 0 )
    {
      CMatchSessionOnlineHost::OnRunCommand(this, pCommand);
      return;
    }
  }
  else if ( this->m_pSysSession != nullptr )
  {
    this->m_pSysSession->Command(this: this->m_pSysSession, a2: pCommand);
    return;
  }
  _Warning(a1: "CMatchSessionOnlineClient::Command( %s ) unhandled!\n", szCommand);
}
