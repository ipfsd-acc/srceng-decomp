// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/mm_session_online_client.cpp
// Functions: 15
// ============================================================

#include "matchmaking\mm_session_online_client.h"

//------------------------------------------------------------------------------
// Address: 0x10023E00
// Name: public: virtual class KeyValues __near * CMatchSessionOnlineClient::GetSessionSystemData(void)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__thiscall CMatchSessionOnlineClient::GetSessionSystemData(CMatchSessionOnlineClient *this)
{
  CSysSessionClient *m_pSysSession; // ecx
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
    LODWORD(v4) = ((int (__thiscall *)(CSysSessionClient *, _DWORD, _DWORD))this->m_pSysSession->GetHostXuid)(
                    a1: this->m_pSysSession,
                    a2: 0,
                    a3: 0);
  else
    v4 = 0;
  KeyValues::SetUint64(this: this->m_pSysData, keyName: "xuidHost", value: v4);
  m_pSysData = this->m_pSysData;
  if ( this->m_eState == STATE_LOBBY )
  {
    KeyValues::SetString(this: m_pSysData, keyName: "state", value: "lobby");
    return this->m_pSysData;
  }
  else
  {
    if ( this->m_eState == STATE_GAME )
      KeyValues::SetString(this: m_pSysData, keyName: "state", value: "game");
    else
      KeyValues::SetString(this: m_pSysData, keyName: "state", value: defaultValue);
    return this->m_pSysData;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10023EC0
// Name: public: virtual void CMatchSessionOnlineClient::UpdateSessionSettings(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::UpdateSessionSettings(CMatchSessionOnlineClient *this, KeyValues *pSettings)
{
  _Warning(a1: "CMatchSessionOnlineClient::UpdateSessionSettings is unavailable in state %d!\n", this->m_eState);
}

//------------------------------------------------------------------------------
// Address: 0x10023EE0
// Name: public: virtual void CMatchSessionOnlineClient::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::Update(CMatchSessionOnlineClient *this)
{
  unsigned __int64 LastInviteFlags; // rax
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  CSysSessionClient *v5; // eax
  CSysSessionClient *v6; // eax
  CSysSessionClient *m_pSysSession; // ecx

  if ( this->m_eState == STATE_INIT )
  {
    this->m_eState = STATE_CREATING;
    LastInviteFlags = CMatchFramework::GetLastInviteFlags(this: g_pMMF);
    KeyValues::SetUint64(this: this->m_pSettings, keyName: "members/joinflags", value: LastInviteFlags);
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(
             this: v3,
             setName: "OnMatchSessionUpdate",
             firstKey: "state",
             firstValue: "progress",
             secondKey: "progress",
             secondValue: "joining");
    else
      v4 = nullptr;
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v4);
    v5 = (CSysSessionClient *)operator new(nSize: 0xC0u);
    if ( v5 != nullptr )
      v6 = CSysSessionClient::CSysSessionClient(this: v5, pSettings: this->m_pSettings);
    else
      v6 = nullptr;
    this->m_pSysSession = v6;
  }
  m_pSysSession = this->m_pSysSession;
  if ( m_pSysSession != nullptr )
    m_pSysSession->Update(this: m_pSysSession);
}

//------------------------------------------------------------------------------
// Address: 0x10023FA0
// Name: public: void CMatchSessionOnlineClient::OnEndGameToLobby(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::OnEndGameToLobby(CMatchSessionOnlineClient *this)
{
  this->m_eState = STATE_ENDING;
  g_pMatchExtensions->m_exts.m_pIVEngineClient->ExecuteClientCmd(
    this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
    a2: "disconnect");
  CSysSessionBase::SetSessionActiveGameplayState(
    this: this->m_pSysSession,
    bActive: false,
    szSecureServerAddress: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10023FD0
// Name: protected: void CMatchSessionOnlineClient::ConnectGameServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::ConnectGameServer(CMatchSessionOnlineClient *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  KeyValues *m_pSettings; // [esp-4h] [ebp-420h]
  MatchSessionServerInfo_t msInfo; // [esp+4h] [ebp-418h] BYREF

  m_pSettings = this->m_pSettings;
  this->m_eState = STATE_GAME;
  MatchSession_PrepareClientForConnect(pSettings: m_pSettings);
  memset(&msInfo, 0, sizeof(msInfo));
  if ( MatchSession_ResolveServerInfo(
         pSettings: this->m_pSettings,
         pSysSession: this->m_pSysSession,
         info: &msInfo,
         uiResolveFlags: 0xBu) )
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
    g_pMatchExtensions->m_exts.m_pIVEngineClient->ClientCmd_Unrestricted(
      this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
      a2: msInfo.m_szConnectCmd);
  }
  else
  {
    this->m_pSysSession->Destroy(this: this->m_pSysSession);
    this->m_pSysSession = nullptr;
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
    {
      v3 = KeyValues::KeyValues(
             this: v2,
             setName: "OnMatchSessionUpdate",
             firstKey: "state",
             firstValue: "error",
             secondKey: "error",
             secondValue: "connect");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
    }
    else
    {
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100240E0
// Name: public: void CMatchSessionOnlineClient::OnClientFullyConnectedToSession(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::OnClientFullyConnectedToSession(CMatchSessionOnlineClient *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "OnMatchSessionUpdate", firstKey: "state", firstValue: "created");
  else
    v3 = nullptr;
  g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v3);
  if ( KeyValues::FindKey(this: this->m_pSettings, keyName: "server", bCreate: false) != nullptr )
  {
    CMatchSessionOnlineClient::ConnectGameServer(this);
  }
  else
  {
    v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v4 != nullptr )
    {
      v5 = KeyValues::KeyValues(this: v4, setName: "OnMatchSessionUpdate", firstKey: "state", firstValue: "ready");
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v5);
    }
    else
    {
      g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: nullptr);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024180
// Name: public: CMatchSessionOnlineClient::CMatchSessionOnlineClient(class CSysSessionClient __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSessionOnlineClient *__thiscall CMatchSessionOnlineClient::CMatchSessionOnlineClient(
        CMatchSessionOnlineClient *this,
        CSysSessionClient *pSysSession,
        KeyValues *pSettings)
{
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h]

  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOnlineClient_vtbl *)&CMatchSessionOnlineClient::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOnlineClient::`vftable'{for `IMatchEventsSink'};
  this->m_pSettings = pSettings;
  this->m_autodelete_pSettings.m_pKeyValues = pSettings;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SysSessionData", firstKey: "type", firstValue: "client");
  else
    v5 = nullptr;
  this->m_pSysData = v5;
  this->m_autodelete_pSysData.m_pKeyValues = v5;
  this->m_eState = STATE_LOBBY;
  this->m_pSysSession = pSysSession;
  DevMsg(a1: "Converted sys session into CMatchSessionOnlineClient:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v9 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10024220
// Name: public: CMatchSessionOnlineClient::CMatchSessionOnlineClient(class CSysSessionHost __near *,class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSessionOnlineClient *__thiscall CMatchSessionOnlineClient::CMatchSessionOnlineClient(
        CMatchSessionOnlineClient *this,
        CSysSessionHost *pSysSession,
        KeyValues *pExtendedSettings)
{
  KeyValues *Key; // eax
  KeyValues *v5; // eax
  KeyValues *v6; // eax
  char *String; // ebx
  CSysSessionClient *v8; // eax
  CSysSessionClient *v9; // eax
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v13; // [esp+Ch] [ebp-4h]

  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOnlineClient_vtbl *)&CMatchSessionOnlineClient::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOnlineClient::`vftable'{for `IMatchEventsSink'};
  Key = KeyValues::FindKey(this: pExtendedSettings, keyName: "settings", bCreate: false);
  this->m_pSettings = Key;
  this->m_autodelete_pSettings.m_pKeyValues = Key;
  v5 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v5 != nullptr )
    v6 = KeyValues::KeyValues(this: v5, setName: "SysSessionData", firstKey: "type", firstValue: "client");
  else
    v6 = nullptr;
  this->m_pSysData = v6;
  this->m_autodelete_pSysData.m_pKeyValues = v6;
  this->m_eState = STATE_LOBBY;
  this->m_pSysSession = nullptr;
  DevMsg(a1: "Migrating into CMatchSessionOnlineClient...\n");
  KeyValues::RemoveSubKey(this: pExtendedSettings, subKey: this->m_pSettings);
  CMatchFramework::SetCurrentMatchSession(this: g_pMMF, pNewMatchSession: this);
  String = KeyValues::GetString(this: pExtendedSettings, keyName: "state", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "game") != 0 )
  {
    if ( _V_stricmp(s1: String, s2: "ending") == 0 )
      this->m_eState = STATE_ENDING;
  }
  else
  {
    this->m_eState = STATE_GAME;
  }
  v8 = (CSysSessionClient *)operator new(nSize: 0xC0u);
  if ( v8 != nullptr )
    v9 = CSysSessionClient::CSysSessionClient(this: v8, pHost: pSysSession, pSettings: this->m_pSettings);
  else
    v9 = nullptr;
  this->m_pSysSession = v9;
  pSysSession->Destroy(this: pSysSession);
  DevMsg(a1: "Migrated into CMatchSessionOnlineClient:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v13 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  if ( pExtendedSettings != nullptr )
    KeyValues::deleteThis(this: pExtendedSettings);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10024370
// Name: protected: void CMatchSessionOnlineClient::OnRunCommand(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::OnRunCommand(CMatchSessionOnlineClient *this, KeyValues *pCommand)
{
  const char *Name; // eax
  CSysSessionClient *m_pSysSession; // ecx
  IMatchTitleGameSettingsMgr *v6; // eax
  IMatchTitleGameSettingsMgr_vtbl *v7; // esi
  int v8; // eax
  KeyValues *Copy; // esi
  const char *v10; // eax
  CFmtStrN<256> *v11; // eax
  CFmtStrN<256> v12; // [esp+8h] [ebp-10Ch] BYREF
  KeyValues *pCommanda; // [esp+11Ch] [ebp+8h]

  Name = KeyValues::GetName(this: pCommand);
  if ( _V_stricmp(s1: "Migrate", s2: Name) != 0 || (m_pSysSession = this->m_pSysSession) == nullptr )
  {
    v6 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
    v7 = v6->__vftable;
    pCommanda = (KeyValues *)v6;
    v8 = ((int (__thiscall *)(CMatchSessionOnlineClient *, KeyValues *, _DWORD))this->GetSessionSystemData)(
           a1: this,
           a2: this->m_pSettings,
           a3: 0);
    ((void (__thiscall *)(KeyValues *, KeyValues *, int))v7->ExecuteCommand)(a1: pCommanda, a2: pCommand, a3: v8);
    Copy = KeyValues::MakeCopy(this: pCommand);
    v10 = KeyValues::GetName(this: pCommand);
    v11 = CFmtStrN<256>::CFmtStrN<256>(this: &v12, pszFormat: "Command::%s", v10);
    KeyValues::SetName(this: Copy, setName: v11->m_szBuf);
    g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: Copy);
  }
  else
  {
    CSysSessionClient::Migrate(this: m_pSysSession, pCommand);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024420
// Name: public: virtual void CMatchSessionOnlineClient::DebugPrint(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::DebugPrint(CMatchSessionOnlineClient *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // eax
  IKeyValuesDumpContext pDump; // [esp+8h] [ebp-8h] BYREF
  int v5; // [esp+Ch] [ebp-4h]

  DevMsg(a1: "CMatchSessionOnlineClient [ state=%d ]\n", this->m_eState);
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
  if ( this->m_pSysSession != nullptr )
    this->m_pSysSession->DebugPrint(this: this->m_pSysSession);
  else
    DevMsg(a1: "SysSession is NULL\n");
}

//------------------------------------------------------------------------------
// Address: 0x100244C0
// Name: public: virtual void CMatchSessionOnlineClient::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::OnEvent(CMatchSessionOnlineClient *this, KeyValues *pEvent)
{
  const char *Name; // ebx
  int Int; // ebx
  int v6; // eax
  KeyValues *m_pKeyValues; // eax
  KeyValues *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // eax
  char *v13; // ebx
  IMatchTitleGameSettingsMgr *v14; // eax
  KeyValues *v15; // eax
  KeyValues *v16; // ebx
  KeyValues *v17; // eax
  CMatchEventsSubscription_vtbl *v18; // ebx
  KeyValues *v19; // eax
  char *v20; // eax
  KeyValues *v21; // eax
  const char *v22; // eax
  CMatchSessionOnlineClient::State_t v23; // ecx
  KeyValues *Copy; // esi
  char *String; // eax
  KeyValues *v26; // eax
  KeyValues *v27; // edi
  const char *v28; // eax
  CSysSessionClient *m_eState; // ebx
  CMatchSessionOnlineHost *v30; // eax
  KeyValues *FirstTrueSubKey; // eax
  char *szDisconnectHdlr; // [esp+Ch] [ebp-4h]
  char bLobbySalvagable_3; // [esp+1Bh] [ebp+Bh]

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnEngineClientSignonStateChange", s2: Name) != 0 )
  {
    if ( _V_stricmp(s1: "OnEngineDisconnectReason", s2: Name) != 0 )
    {
      if ( _V_stricmp(s1: "OnEngineEndGame", s2: Name) != 0 )
      {
        if ( _V_stricmp(s1: "OnMatchSessionUpdate", s2: Name) != 0 )
        {
          if ( _V_stricmp(s1: "OnNetLanConnectionlessPacket", s2: Name) != 0 )
          {
            if ( _V_stricmp(s1: "OnSysMuteListChanged", s2: Name) != 0 )
            {
              if ( _V_stricmp(s1: "mmF->SysSessionUpdate", s2: Name) != 0 )
              {
                if ( _V_stricmp(s1: "mmF->SysSessionCommand", s2: Name) == 0
                  && this->m_eState != STATE_INIT
                  && KeyValues::GetPtr(this: pEvent, keyName: "syssession", defaultValue: nullptr) == (void *)this->m_eState )
                {
                  FirstTrueSubKey = KeyValues::GetFirstTrueSubKey(this: pEvent);
                  if ( FirstTrueSubKey != nullptr )
                    CMatchSessionOnlineClient::OnRunCommand(
                      this: (CMatchSessionOnlineClient *)((char *)this - 4),
                      pCommand: FirstTrueSubKey);
                }
              }
              else if ( this->m_eState != STATE_INIT
                     && KeyValues::GetPtr(this: pEvent, keyName: "syssession", defaultValue: nullptr) == (void *)this->m_eState )
              {
                if ( KeyValues::GetString(this: pEvent, keyName: "error", defaultValue: nullptr) != nullptr )
                {
                  (*(void (__thiscall **)(CMatchSessionOnlineClient::State_t))(*(_DWORD *)this->m_eState + 8))(a1: this->m_eState);
                  this->m_eState = STATE_INIT;
                  this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)1;
                  Copy = KeyValues::MakeCopy(this: pEvent);
                  KeyValues::SetName(this: Copy, setName: "OnMatchSessionUpdate");
                  KeyValues::SetString(this: Copy, keyName: "state", value: "error");
                  g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: Copy);
                }
                else if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)1 )
                {
                  this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)2;
                  CMatchSessionOnlineClient::OnClientFullyConnectedToSession(this: (CMatchSessionOnlineClient *)((char *)this - 4));
                }
                else
                {
                  String = KeyValues::GetString(this: pEvent, keyName: "action", defaultValue: nullptr);
                  if ( String == nullptr || _V_stricmp(s1: "host", s2: String) != 0 )
                  {
                    DevWarning(a1: "Unhandled mmF->SysSessionUpdate!\n");
                  }
                  else
                  {
                    v26 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
                    if ( v26 != nullptr )
                      v27 = KeyValues::KeyValues(this: v26, setName: "ExtendedSettings");
                    else
                      v27 = nullptr;
                    v28 = "lobby";
                    if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)3 )
                    {
                      v28 = "game";
                    }
                    else if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)4 )
                    {
                      v28 = "ending";
                    }
                    KeyValues::SetString(this: v27, keyName: "state", value: v28);
                    KeyValues::AddSubKey(
                      this: v27,
                      pSubkey: (KeyValues *)this->IMatchSessionInternal::IMatchEventsSink::__vftable);
                    this->IMatchSessionInternal::IMatchEventsSink::__vftable = nullptr;
                    this->m_pSettings = nullptr;
                    m_eState = (CSysSessionClient *)this->m_eState;
                    this->m_eState = STATE_INIT;
                    this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)5;
                    CMatchFramework::SetCurrentMatchSession(this: g_pMMF, pNewMatchSession: nullptr);
                    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 20))(a1: (char *)this - 4);
                    v30 = (CMatchSessionOnlineHost *)operator new(nSize: 0x28u);
                    if ( v30 != nullptr )
                      CMatchSessionOnlineHost::CMatchSessionOnlineHost(
                        this: v30,
                        pSysSession: m_eState,
                        pExtendedSettings: v27);
                  }
                }
              }
            }
            else
            {
              v23 = this->m_eState;
              if ( v23 != STATE_INIT )
                (*(void (__thiscall **)(CMatchSessionOnlineClient::State_t))(*(_DWORD *)v23 + 56))(a1: v23);
            }
          }
          else
          {
            v21 = KeyValues::GetFirstTrueSubKey(this: pEvent);
            v22 = KeyValues::GetName(this: v21);
            if ( this->m_eState != STATE_INIT
              && (int)this->m_autodelete_pSysData.m_pKeyValues > 1
              && _V_stricmp(s1: v22, s2: "LanSearch") == 0 )
            {
              CSysSessionBase::ReplyLanSearch(this: (CSysSessionBase *)this->m_eState, msg: pEvent);
            }
          }
          return;
        }
        v20 = KeyValues::GetString(this: pEvent, keyName: "state", defaultValue: defaultValue);
        if ( _V_stricmp(s1: "updated", s2: v20) != 0 )
          return;
        if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)2 )
        {
          if ( KeyValues::FindKey(this: pEvent, keyName: "update/server", bCreate: false) != nullptr )
            CMatchSessionOnlineClient::ConnectGameServer(this: (CMatchSessionOnlineClient *)((char *)this - 4));
          return;
        }
        if ( this->m_autodelete_pSysData.m_pKeyValues != (KeyValues *)3
          || KeyValues::FindKey(this: pEvent, keyName: "delete/server", bCreate: false) == nullptr )
        {
          return;
        }
      }
      else if ( this->m_autodelete_pSysData.m_pKeyValues != (KeyValues *)3 )
      {
        return;
      }
      CMatchSessionOnlineClient::OnEndGameToLobby(this: (CMatchSessionOnlineClient *)((char *)this - 4));
      return;
    }
    if ( this->m_autodelete_pSysData.m_pKeyValues == (KeyValues *)3 )
    {
      v13 = KeyValues::GetString(this: pEvent, keyName: "reason", defaultValue: defaultValue);
      DevMsg(a1: "OnEngineDisconnectReason %s\n", v13);
      if ( StringAfterPrefix(str: v13, prefix: "Connection to server timed out") != nullptr
        || (bLobbySalvagable_3 = 0, StringAfterPrefix(str: v13, prefix: "Server shutting down") != nullptr) )
      {
        bLobbySalvagable_3 = 1;
      }
      v14 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
      v15 = v14->PrepareClientLobbyForGameDisconnect(
              this: v14,
              a2: (KeyValues *)this->IMatchSessionInternal::IMatchEventsSink::__vftable,
              a3: pEvent);
      v16 = v15;
      if ( v15 != nullptr )
      {
        szDisconnectHdlr = KeyValues::GetString(this: v15, keyName: "disconnecthdlr", defaultValue: defaultValue);
        if ( _V_stricmp(s1: szDisconnectHdlr, s2: "destroy") != 0 )
        {
          if ( _V_stricmp(s1: szDisconnectHdlr, s2: "lobby") == 0 )
            bLobbySalvagable_3 = 1;
        }
        else
        {
          bLobbySalvagable_3 = 0;
        }
        KeyValues::deleteThis(this: v16);
      }
      if ( bLobbySalvagable_3 == 0 )
      {
        v17 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v17 != nullptr )
        {
          v12 = KeyValues::KeyValues(this: v17, setName: "mmF->CloseSession");
          goto LABEL_11;
        }
LABEL_10:
        v12 = nullptr;
LABEL_11:
        g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v12);
        return;
      }
      KeyValues::SetString(this: pEvent, keyName: "disconnecthdlr", value: "lobby");
      v18 = g_pMatchEventsSubscription->__vftable;
      v19 = KeyValues::MakeCopy(this: pEvent);
      v18->RegisterEventData(this: g_pMatchEventsSubscription, a2: v19);
      CMatchSessionOnlineClient::OnEndGameToLobby(this: (CMatchSessionOnlineClient *)((char *)this - 4));
    }
  }
  else
  {
    Int = KeyValues::GetInt(this: pEvent, keyName: "old", defaultValue: 0);
    v6 = KeyValues::GetInt(this: pEvent, keyName: "new", defaultValue: 0);
    if ( Int >= 2 && v6 < 2 )
    {
      m_pKeyValues = this->m_autodelete_pSysData.m_pKeyValues;
      if ( m_pKeyValues == (KeyValues *)3 )
      {
        DevMsg(a1: "OnEngineClientSignonStateChange\n");
        v8 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v8 != nullptr )
        {
          v9 = KeyValues::KeyValues(this: v8, setName: "mmF->CloseSession");
          g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v9);
          return;
        }
      }
      else
      {
        if ( m_pKeyValues != (KeyValues *)4 )
          return;
        this->m_autodelete_pSysData.m_pKeyValues = (KeyValues *)2;
        v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v10 != nullptr )
        {
          v11 = KeyValues::KeyValues(this: v10, setName: "OnMatchSessionUpdate", firstKey: "state", firstValue: "ready");
          g_pMatchEventsSubscription->BroadcastEvent(this: g_pMatchEventsSubscription, a2: v11);
          return;
        }
      }
      goto LABEL_10;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10024A40
// Name: protected: void CMatchSessionOnlineClient::InitializeGameSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::InitializeGameSettings(CMatchSessionOnlineClient *this)
{
  KeyValues *Key; // eax
  KeyValues *v3; // esi
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  KeyValues *v6; // esi
  IPlayerLocal *v7; // eax
  unsigned __int64 v8; // rax
  unsigned __int64 MachineFlags; // rax
  IMatchSystem *v10; // eax
  int v11; // eax
  KeyValues *v12; // eax
  unsigned __int64 Uint64; // rax
  const char *TuInstalledString; // eax
  CFmtStrN<256> *v15; // eax
  KeyValues *v16; // esi
  IPlayerLocal *v17; // edi
  unsigned __int64 v18; // rax
  const char *v19; // eax
  IMatchTitleGameSettingsMgr *v20; // eax
  KeyValues *m_pSettings; // ecx
  CFmtStrN<256> v22; // [esp+8h] [ebp-114h] BYREF
  IKeyValuesDumpContext pDump; // [esp+114h] [ebp-8h] BYREF
  int v24; // [esp+118h] [ebp-4h]

  Key = KeyValues::FindKey(this: this->m_pSettings, keyName: "system", bCreate: true);
  v3 = Key;
  if ( Key != nullptr )
  {
    if ( KeyValues::FindKey(this: Key, keyName: "network", bCreate: false) == nullptr )
      KeyValues::SetString(this: v3, keyName: "network", value: "LIVE");
    if ( KeyValues::FindKey(this: v3, keyName: "access", bCreate: false) == nullptr )
      KeyValues::SetString(this: v3, keyName: "access", value: "public");
  }
  v4 = KeyValues::FindKey(this: this->m_pSettings, keyName: "members", bCreate: true);
  v5 = v4;
  if ( v4 != nullptr )
  {
    KeyValues::SetInt(this: v4, keyName: "numMachines", value: 1);
    KeyValues::SetInt(this: v5, keyName: "numPlayers", value: 1);
    KeyValues::SetInt(this: v5, keyName: "numSlots", value: 1);
    v6 = KeyValues::FindKey(this: v5, keyName: "machine0", bCreate: true);
    if ( v6 != nullptr )
    {
      v7 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
      v8 = v7->GetXUID(this: v7);
      KeyValues::SetUint64(this: v6, keyName: "id", value: v8);
      MachineFlags = MatchSession_GetMachineFlags();
      KeyValues::SetUint64(this: v6, keyName: "flags", value: MachineFlags);
      KeyValues::SetInt(this: v6, keyName: "numPlayers", value: 1);
      v10 = g_pMatchFramework->GetMatchSystem(this: g_pMatchFramework);
      v11 = (int)v10->GetDlcManager(this: v10);
      v12 = (KeyValues *)(*(int (__thiscall **)(int))(*(_DWORD *)v11 + 8))(a1: v11);
      Uint64 = KeyValues::GetUint64(this: v12, keyName: "@info/installed", defaultValue: 0);
      KeyValues::SetUint64(this: v6, keyName: "dlcmask", value: Uint64);
      TuInstalledString = MatchSession_GetTuInstalledString();
      KeyValues::SetString(this: v6, keyName: "tuver", value: TuInstalledString);
      KeyValues::SetInt(this: v6, keyName: "ping", value: 0);
      v15 = CFmtStrN<256>::CFmtStrN<256>(this: &v22, pszFormat: "player%d", 0);
      v16 = KeyValues::FindKey(this: v6, keyName: v15->m_szBuf, bCreate: true);
      if ( v16 != nullptr )
      {
        v17 = g_pPlayerManager->GetLocalPlayer(this: g_pPlayerManager, a2: 0);
        v18 = v17->GetXUID(this: v17);
        KeyValues::SetUint64(this: v16, keyName: "xuid", value: v18);
        v19 = v17->GetName(this: v17);
        KeyValues::SetString(this: v16, keyName: "name", value: v19);
      }
    }
  }
  v20 = g_pMMF->GetMatchTitleGameSettingsMgr(this: g_pMMF);
  v20->InitializeGameSettings(this: v20, a2: this->m_pSettings, a3: "client");
  DevMsg(a1: "CMatchSessionOnlineClient::InitializeGameSettings adjusted settings:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v24 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10024C60
// Name: public: CMatchSessionOnlineClient::CMatchSessionOnlineClient(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
CMatchSessionOnlineClient *__thiscall CMatchSessionOnlineClient::CMatchSessionOnlineClient(
        CMatchSessionOnlineClient *this,
        KeyValues *pSettings)
{
  KeyValues *Copy; // eax
  KeyValues *v4; // eax
  KeyValues *v5; // eax
  KeyValues *m_pSettings; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v9; // [esp+8h] [ebp-4h]

  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&IMatchEventsSink::`vftable';
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOnlineClient_vtbl *)&CMatchSessionOnlineClient::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOnlineClient::`vftable'{for `IMatchEventsSink'};
  Copy = KeyValues::MakeCopy(this: pSettings);
  this->m_pSettings = Copy;
  this->m_autodelete_pSettings.m_pKeyValues = Copy;
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(this: v4, setName: "SysSessionData", firstKey: "type", firstValue: "client");
  else
    v5 = nullptr;
  this->m_pSysData = v5;
  this->m_autodelete_pSysData.m_pKeyValues = v5;
  this->m_eState = STATE_INIT;
  this->m_pSysSession = nullptr;
  DevMsg(a1: "Created CMatchSessionOnlineClient:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v9 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  CMatchSessionOnlineClient::InitializeGameSettings(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10024D10
// Name: public: virtual void CMatchSessionOnlineClient::Command(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::Command(CMatchSessionOnlineClient *this, KeyValues *pCommand)
{
  char *String; // esi
  const char *szCommand; // [esp+14h] [ebp+8h]

  szCommand = KeyValues::GetName(this: pCommand);
  String = KeyValues::GetString(this: pCommand, keyName: "run", defaultValue: defaultValue);
  if ( _V_stricmp(s1: String, s2: "host") != 0
    && _V_stricmp(s1: String, s2: "all") != 0
    && _V_stricmp(s1: String, s2: "xuid") != 0 )
  {
    if ( *String == 0 || _V_stricmp(s1: String, s2: "local") == 0 )
    {
      CMatchSessionOnlineClient::OnRunCommand(this, pCommand);
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

//------------------------------------------------------------------------------
// Address: 0x10024DD0
// Name: public: virtual void CMatchSessionOnlineClient::Destroy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CMatchSessionOnlineClient::Destroy(CMatchSessionOnlineClient *this)
{
  CMatchSessionOnlineClient::State_t m_eState; // eax
  CSysSessionClient *m_pSysSession; // ecx
  KeyValues *m_pSettings; // ecx
  KeyValues *m_pKeyValues; // ecx
  KeyValues *v6; // ecx
  IKeyValuesDumpContext pDump; // [esp+4h] [ebp-8h] BYREF
  int v8; // [esp+8h] [ebp-4h]

  if ( this->m_eState != STATE_MIGRATE )
    ((void (__thiscall *)(INetSupport *, _DWORD, _DWORD, _DWORD, _DWORD))g_pMatchExtensions->m_exts.m_pINetSupport->UpdateClientReservation)(
      a1: g_pMatchExtensions->m_exts.m_pINetSupport,
      a2: 0,
      a3: 0,
      a4: 0,
      a5: 0);
  m_eState = this->m_eState;
  if ( m_eState == STATE_GAME || m_eState == STATE_ENDING )
  {
    this->m_eState = STATE_INIT;
    g_pMatchExtensions->m_exts.m_pIVEngineClient->ExecuteClientCmd(
      this: g_pMatchExtensions->m_exts.m_pIVEngineClient,
      a2: "disconnect");
  }
  m_pSysSession = this->m_pSysSession;
  if ( m_pSysSession != nullptr )
  {
    m_pSysSession->Destroy(this: m_pSysSession);
    this->m_pSysSession = nullptr;
  }
  this->IMatchSessionInternal::IMatchSession::__vftable = (CMatchSessionOnlineClient_vtbl *)&CMatchSessionOnlineClient::`vftable'{for `IMatchSession'};
  this->IMatchSessionInternal::IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CMatchSessionOnlineClient::`vftable'{for `IMatchEventsSink'};
  DevMsg(a1: "Destroying CMatchSessionOnlineClient:\n");
  m_pSettings = this->m_pSettings;
  pDump.__vftable = (IKeyValuesDumpContext_vtbl *)&CKeyValuesDumpContextAsDevMsg::`vftable';
  v8 = 1;
  KeyValues::Dump(this: m_pSettings, &pDump, nIndentLevel: 1);
  m_pKeyValues = this->m_autodelete_pSysData.m_pKeyValues;
  if ( m_pKeyValues != nullptr )
    KeyValues::deleteThis(this: m_pKeyValues);
  v6 = this->m_autodelete_pSettings.m_pKeyValues;
  if ( v6 != nullptr )
    KeyValues::deleteThis(this: v6);
  free(pMem: this);
}
