// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/baseclient.cpp
// Functions: 83
// ============================================================

#include "engine\baseclient.h"

//------------------------------------------------------------------------------
// Address: 0x1005E890
// Name: public: virtual int CLC_VoiceData::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLC_VoiceData::GetType(SVC_ClassInfo *this)
{
  return 10;
}

//------------------------------------------------------------------------------
// Address: 0x101161B0
// Name: public: virtual void CBaseClient::SetRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetRate(CBaseClient *this, int nRate, bool bForce)
{
  if ( this->m_nFilesDownloaded != 0 )
    (*(void (__stdcall **)(float))(*(_DWORD *)this->m_nFilesDownloaded + 112))(a1: (float)nRate);
}

//------------------------------------------------------------------------------
// Address: 0x101161E0
// Name: public: virtual int CBaseClient::GetRate(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetRate(CBaseClient *this)
{
  if ( this->m_nFilesDownloaded != 0 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)this->m_nFilesDownloaded + 20))(a1: this->m_nFilesDownloaded);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10116200
// Name: public: virtual char const __near * CBaseClient::GetUserSetting(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseClient::GetUserSetting(CBaseClient *this, const char *cvar)
{
  KeyValues *v3; // ecx
  const char *String; // ebx

  v3 = *(KeyValues **)&this->m_FriendsName[28];
  if ( v3 == nullptr || cvar == nullptr || *cvar == 0 )
    return defaultValue;
  String = KeyValues::GetString(this: v3, keyName: cvar, defaultValue: defaultValue);
  if ( *String == 0 )
  {
    if ( LOBYTE(this->m_nDebugID) != 0 )
      return this->m_SplitScreenUsers[1]->GetUserSetting(this: &this->m_SplitScreenUsers[1]->IClient, a2: cvar);
    if ( KeyValues::GetDataType(this: *(KeyValues **)&this->m_FriendsName[28], keyName: cvar) == TYPE_NONE )
      DevMsg(a1: "GetUserSetting: cvar '%s' unknown.\n", cvar);
  }
  return String;
}

//------------------------------------------------------------------------------
// Address: 0x10116280
// Name: public: virtual void CBaseClient::SetUserCVar(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetUserCVar(CBaseClient *this, const char *cvar, const char *value)
{
  if ( cvar != nullptr && value != nullptr )
    KeyValues::SetString(this: this->m_ConVars, keyName: cvar, value);
}

//------------------------------------------------------------------------------
// Address: 0x101162B0
// Name: public: virtual int CBaseClient::GetUpdateRate(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetUpdateRate(CBaseClient *this)
{
  float v1; // xmm0_4

  v1 = *((float *)&this->m_fNextMessageTime + 1);
  if ( v1 <= 0.0 )
    return 0;
  else
    return (int)(float)(1.0 / v1);
}

//------------------------------------------------------------------------------
// Address: 0x101162E0
// Name: public: void CBaseClient::SetSignonState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetSignonState(CBaseClient *this, int nState)
{
  bool v3; // al
  IClient_vtbl *v4; // edx

  v3 = this->IsConnected(this: &this->IClient);
  v4 = this->IClient::INetChannelHandler::__vftable;
  this->m_nSignonState = nState;
  if ( v3 != v4->IsConnected(this: &this->IClient)
    && (!this->IsFakeClient(this: &this->IClient) || this->IsSplitScreenUser(this: &this->IClient)) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116350
// Name: public: virtual void CBaseClient::ActivatePlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::ActivatePlayer(CBaseClient *this)
{
  bool v2; // bl
  bool (__thiscall *IsConnected)(IClient *); // eax
  CMapReslistGenerator *v4; // eax

  _COM_TimestampedLog(a1: "CBaseClient::ActivatePlayer");
  this->m_Server->UserInfoChanged(this: this->m_Server, a2: this->m_nClientSlot);
  v2 = this->IsConnected(this: &this->IClient);
  IsConnected = this->IsConnected;
  this->m_nSignonState = 6;
  if ( v2 != IsConnected(this: &this->IClient)
    && (!this->IsFakeClient(this: &this->IClient) || this->IsSplitScreenUser(this: &this->IClient)) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  v4 = MapReslistGenerator();
  CMapReslistGenerator::OnPlayerSpawn(this: v4);
  NotifyDedicatedServerUI(message: "UpdatePlayers");
}

//------------------------------------------------------------------------------
// Address: 0x101163F0
// Name: public: virtual bool CBaseClient::ProcessTick(class NET_Tick __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ProcessTick(CBaseClient *this, NET_Tick *msg)
{
  (*(void (__thiscall **)(unsigned int, float, float))(*(_DWORD *)this->m_nCustomFiles[3].reqID + 272))(
    a1: this->m_nCustomFiles[3].reqID,
    a2: msg->m_flHostFrameTime,
    a3: msg->m_flHostFrameTimeStdDeviation);
  return (*(bool (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 16))(a1: (char *)this - 8, a2: msg->m_nTick);
}

//------------------------------------------------------------------------------
// Address: 0x10116430
// Name: public: virtual bool CBaseClient::ProcessStringCmd(class NET_StringCmd __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessStringCmd(CBaseClient *this, NET_StringCmd *msg)
{
  (*(void (__thiscall **)(char *, const char *))(*((_DWORD *)this - 1) + 112))(
    a1: (char *)this - 4,
    a2: msg->m_szCommand);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10116450
// Name: public: virtual bool CBaseClient::ProcessClientInfo(class CLC_ClientInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessClientInfo(CBaseClient *this, CLC_ClientInfo *msg)
{
  this->m_Server = (CBaseServer *)msg->m_nSendTableCRC;
  this->m_bConVarsChanged = msg->m_bIsHLTV;
  this->m_nCustomFiles[3].crc = 0;
  V_strncpy(pDest: (char *)&this->m_SteamID.m_steamid.m_unAll64Bits + 7, pSrc: msg->m_FriendsName, maxLen: 32);
  *(_DWORD *)&this->m_bIsHLTV = msg->m_nCustomFiles[0];
  this->m_nSendtableCRC = 0;
  this->m_nCustomFiles[0].crc = msg->m_nCustomFiles[1];
  this->m_nCustomFiles[0].reqID = 0;
  this->m_nCustomFiles[1].crc = msg->m_nCustomFiles[2];
  this->m_nCustomFiles[1].reqID = 0;
  this->m_nCustomFiles[2].crc = msg->m_nCustomFiles[3];
  this->m_nCustomFiles[2].reqID = 0;
  if ( msg->m_nServerCount != (*(int (__thiscall **)(KeyValues *))(*(_DWORD *)this->m_ConVars + 60))(a1: this->m_ConVars) )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 48))(a1: (char *)this - 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101164F0
// Name: public: virtual bool CBaseClient::ProcessLoadingProgress(class CLC_LoadingProgress __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessLoadingProgress(CBaseClient *this, CLC_LoadingProgress *msg)
{
  this->m_nSignonTick = msg->m_nProgress;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10116510
// Name: public: bool CBaseClient::IsTracing(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClient::IsTracing(CBaseClient *this)
{
  return this->m_Trace.m_nMinWarningBytes != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10116520
// Name: public: void CBaseClient::SetTraceThreshold(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetTraceThreshold(CBaseClient *this, int nThreshold)
{
  this->m_Trace.m_nMinWarningBytes = nThreshold;
}

//------------------------------------------------------------------------------
// Address: 0x10116530
// Name: public: virtual bool CBaseClient::ExecuteStringCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ExecuteStringCommand(CBaseClient *this, const char *pCommand)
{
  if ( pCommand != nullptr && *pCommand != 0 && _V_stricmp(s1: pCommand, s2: "demorestart") == 0 )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 12))(a1: (char *)this - 4);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x10116570
// Name: public: virtual bool CBaseClient::ShouldSendMessages(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ShouldSendMessages(CBaseClient *this)
{
  IClient *v2; // edi
  bool v4; // bl

  v2 = &this->IClient;
  if ( !this->IsConnected(this: &this->IClient) )
    return false;
  if ( this->m_NetChannel != nullptr && this->m_NetChannel->IsOverflowed(this: this->m_NetChannel) )
  {
    this->m_NetChannel->Reset(this: this->m_NetChannel);
    v2->Disconnect(this: v2, a2: "%s overflowed reliable buffer\n", this->m_Name);
    return false;
  }
  v4 = net_time >= this->m_fNextMessageTime;
  if ( this->m_NetChannel == nullptr || !this->m_NetChannel->IsLoopback(this: this->m_NetChannel) )
  {
    if ( v4 )
      goto LABEL_14;
    if ( v2->IsActive(this: v2)
      || !this->m_bReceivedPacket
      || this->m_NetChannel == nullptr
      || !this->m_NetChannel->HasPendingReliableData(this: this->m_NetChannel) )
    {
      return v4;
    }
  }
  v4 = true;
LABEL_14:
  if ( this->m_NetChannel != nullptr && !this->m_NetChannel->CanPacket(this: this->m_NetChannel) )
  {
    this->m_NetChannel->SetChoked(this: this->m_NetChannel);
    return false;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10116670
// Name: public: virtual void CBaseClient::UpdateUserSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::UpdateUserSettings(CBaseClient *this)
{
  CBaseClient_vtbl *v2; // edi
  const char *String; // eax
  IClient_vtbl *v4; // ebx
  int Int; // eax
  IClient_vtbl *v6; // ebx
  int v7; // eax
  IClient_vtbl *v8; // ebx
  int v9; // eax

  v2 = this->IGameEventListener2::__vftable;
  String = KeyValues::GetString(this: this->m_ConVars, keyName: "name", defaultValue: "unnamed");
  v2->SetName(this, a2: String);
  v4 = this->IClient::INetChannelHandler::__vftable;
  Int = KeyValues::GetInt(this: this->m_ConVars, keyName: "rate", defaultValue: 5000);
  v4->SetRate(this: &this->IClient, a2: Int, a3: false);
  v6 = this->IClient::INetChannelHandler::__vftable;
  v7 = KeyValues::GetInt(this: this->m_ConVars, keyName: "cl_updaterate", defaultValue: 20);
  v6->SetUpdateRate(this: &this->IClient, a2: v7, a3: false);
  v8 = this->IClient::INetChannelHandler::__vftable;
  v9 = KeyValues::GetInt(this: this->m_ConVars, keyName: "net_maxroutable", defaultValue: 1200);
  v8->SetMaxRoutablePayloadSize(this: &this->IClient, a2: v9);
  this->m_Server->UserInfoChanged(this: this->m_Server, a2: this->m_nClientSlot);
  this->m_bConVarsChanged = false;
}

//------------------------------------------------------------------------------
// Address: 0x10116720
// Name: char const __near * GetUserIDString(struct USERID_s const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetUserIDString(const USERID_s *id)
{
  TSteamGlobalUserID nullID; // [esp+4h] [ebp-10h] BYREF

  idstr[0] = 0;
  if ( id->idtype == 1 )
  {
    _V_memset(dest: &nullID, fill: 0, count: 16);
    if ( Steam3Server()->m_eServerMode != eServerModeNoAuthentication
      || _V_memcmp(m1: &id->uid, m2: &nullID, count: 16) != 0 )
    {
      if ( _V_memcmp(m1: &id->uid, m2: &nullID, count: 16) != 0 )
      {
        V_snprintf(
          pDest: idstr,
          maxLen: 63,
          pFormat: "STEAM_%u:%u:%u",
          id->uid.steamid.m_SteamInstanceID,
          id->uid.steamid.m_SteamLocalUserID.Split.High32bits,
          id->uid.steamid.m_SteamLocalUserID.Split.Low32bits);
        byte_10631537 = 0;
      }
      else
      {
        strcpy(idstr, "STEAM_ID_PENDING");
      }
      return idstr;
    }
    else
    {
      strcpy(idstr, "STEAM_ID_LAN");
      return idstr;
    }
  }
  else if ( id->idtype == 3 )
  {
    strcpy(idstr, "HLTV");
    return idstr;
  }
  else
  {
    if ( id->idtype == 4 )
      strcpy(idstr, "REPLAY");
    else
      strcpy(idstr, "UNKNOWN");
    return idstr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101168B0
// Name: public: virtual char const __near * CBaseClient::GetNetworkIDString(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseClient::GetNetworkIDString(CBaseClient *this)
{
  const char *result; // eax
  KeyValues *v3; // ecx
  const USERID_s *v4; // eax
  _BYTE v5[24]; // [esp+4h] [ebp-18h] BYREF

  if ( this->IGameEventListener2::__vftable[1].SendServerInfo(this) )
    return "BOT";
  v3 = *(KeyValues **)&this->m_FriendsName[28];
  if ( v3 == nullptr
    || (result = KeyValues::GetString(this: v3, keyName: "networkid_force", defaultValue: defaultValue)) == nullptr
    || *result == 0 )
  {
    v4 = (const USERID_s *)((int (__thiscall *)(CBaseClient *, _BYTE *))this->SetName)(a1: this, a2: v5);
    return GetUserIDString(id: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10116910
// Name: public: virtual bool CBaseClient::IgnoreTempEntity(class CEventInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IgnoreTempEntity(CBaseClient *this, CEventInfo *event)
{
  int v2; // eax

  v2 = this->GetPlayerSlot(this: &this->IClient);
  return !CEngineRecipientFilter::IncludesPlayer(this: &event->filter, playerindex: v2 + 1);
}

//------------------------------------------------------------------------------
// Address: 0x10116940
// Name: public: void CBaseClient::SetSteamID(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetSteamID(CBaseClient *this, const CSteamID *steamID)
{
  this->m_SteamID = (CSteamID)steamID->m_steamid.m_comp;
}

//------------------------------------------------------------------------------
// Address: 0x10116960
// Name: public: virtual void CBaseClient::SetMaxRoutablePayloadSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetMaxRoutablePayloadSize(CBaseClient *this, int nMaxRoutablePayloadSize)
{
  if ( this->m_nFilesDownloaded != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)this->m_nFilesDownloaded + 276))(
      a1: this->m_nFilesDownloaded,
      a2: nMaxRoutablePayloadSize);
}

//------------------------------------------------------------------------------
// Address: 0x10116990
// Name: public: virtual int CBaseClient::GetMaxAckTickCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetMaxAckTickCount(CBaseClient *this)
{
  int result; // eax
  int m_nSignonState; // edx
  int m_nDeltaTick; // ecx

  result = this->m_nStringTableAckTick;
  m_nSignonState = this->m_nSignonState;
  m_nDeltaTick = this->m_nDeltaTick;
  if ( m_nSignonState > result )
    result = m_nSignonState;
  if ( m_nDeltaTick > result )
    return m_nDeltaTick;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101169B0
// Name: private: void CBaseClient::SendFullConnectEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SendFullConnectEvent(CBaseClient *this)
{
  IGameEvent *v2; // esi

  v2 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_connect_full", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v2->SetInt(this: v2, a2: "userid", a3: this->m_UserID);
    v2->SetInt(this: v2, a2: "index", a3: this->m_nClientSlot);
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v2, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116A10
// Name: public: virtual bool CBaseClient::ProcessSplitScreenUser(class NET_SplitScreenUser __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ProcessSplitScreenUser(CBaseClient *this, NET_SplitScreenUser *msg)
{
  int m_nSlot; // eax
  char v5; // al
  int v6; // eax

  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 1) + 156))(a1: (char *)this - 4) != 0 )
    return this->m_SplitScreenUsers[0]->ProcessSplitScreenUser(
             this: &this->m_SplitScreenUsers[0]->IClientMessageHandler,
             a2: msg);
  m_nSlot = msg->m_nSlot;
  if ( m_nSlot == -1 )
  {
    v5 = (*(int (__stdcall **)(unsigned int))(*(_DWORD *)this->m_nCustomFiles[3].reqID + 284))(a1: this->m_nCustomFiles[3].reqID);
  }
  else
  {
    v6 = *((_DWORD *)&this->m_bSplitScreenUser + m_nSlot);
    if ( v6 == 0 )
    {
LABEL_8:
      _Msg(a1: "Unable to set SetActiveChannel to user in slot %d\n", msg->m_nSlot);
      return false;
    }
    v5 = (*(int (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)this->m_nCustomFiles[3].reqID + 284))(
           a1: this->m_nCustomFiles[3].reqID,
           a2: *(_DWORD *)(v6 + 220));
  }
  if ( v5 == 0 )
    goto LABEL_8;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10116AA0
// Name: public: bool CBaseClient::IsSplitScreenPartner(class CBaseClient const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsSplitScreenPartner(CBaseClient *this, const CBaseClient *pOther)
{
  return pOther != nullptr
      && (pOther->IsSplitScreenUser(this: &pOther->IClient) && pOther->m_pAttachedTo == this
       || this->IsSplitScreenUser(this: &this->IClient) && this->m_pAttachedTo == pOther);
}

//------------------------------------------------------------------------------
// Address: 0x10116AF0
// Name: public: virtual int CBaseClient::GetNumPlayers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetNumPlayers(CBaseClient *this)
{
  int result; // eax

  if ( ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0 )
  {
    if ( this->m_SplitScreenUsers[1] != nullptr )
      return this->m_SplitScreenUsers[1]->GetNumPlayers(this: &this->m_SplitScreenUsers[1]->IClient);
    else
      return 0;
  }
  else
  {
    result = this->m_nSplitScreenPlayerSlot != 0;
    if ( this->m_SplitScreenUsers[0] != nullptr )
      ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10116B40
// Name: public: virtual bool CBaseClient::IsHumanPlayer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsHumanPlayer(CBaseClient *this)
{
  return ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this) != 0
      && !this->IGameEventListener2::__vftable[1].SendSignonData(this)
      && (!this->IGameEventListener2::__vftable[1].SendServerInfo(this)
       || ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10116BF0
// Name: public: virtual void CBaseClient::SetUpdateRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetUpdateRate(CBaseClient *this, int udpaterate, bool bForce)
{
  int v3; // eax

  v3 = udpaterate;
  if ( udpaterate >= 1 )
  {
    if ( udpaterate > 100 )
      v3 = 100;
  }
  else
  {
    v3 = 1;
  }
  *((float *)&this->m_fNextMessageTime + 1) = 1.0 / (float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10116C30
// Name: protected: virtual bool CBaseClient::ProcessSignonStateMsg(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ProcessSignonStateMsg(CBaseClient *this, int state, int spawncount)
{
  bool result; // al
  const char *v5; // eax
  IMDLCache *v6; // edi
  CBaseClient **m_SplitScreenUsers; // esi
  int i; // ebx
  CBaseClient **v9; // esi
  int j; // ebx
  int v11; // [esp-8h] [ebp-10h]

  if ( this->IsSplitScreenUser(this: &this->IClient) )
    return true;
  v5 = (const char *)((int (__thiscall *)(IClient *, int))this->GetClientName)(
                       a1: &this->IClient,
                       a2: this->m_nSignonState);
  _COM_TimestampedLog(a1: "CBaseClient::ProcessSignonStateMsg: %s  :  %d", v5, v11);
  v6 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  switch ( this->m_nSignonState )
  {
    case 2:
      this->m_bSendServerInfo = true;
      v6->EndCoarseLock(this: v6);
      return true;
    case 3:
      if ( this->SendSignonData(this) )
        goto LABEL_17;
      v6->EndCoarseLock(this: v6);
      return false;
    case 4:
      this->SpawnPlayer(this);
      v6->EndCoarseLock(this: v6);
      return true;
    case 5:
      m_SplitScreenUsers = this->m_SplitScreenUsers;
      for ( i = 2; i != 0; --i )
      {
        if ( *m_SplitScreenUsers != nullptr )
          (*m_SplitScreenUsers)->ActivatePlayer(this: *m_SplitScreenUsers);
        ++m_SplitScreenUsers;
      }
      goto LABEL_17;
    case 6:
      v9 = this->m_SplitScreenUsers;
      for ( j = 2; j != 0; --j )
      {
        if ( *v9 != nullptr )
          CBaseClient::SendFullConnectEvent(this: *v9);
        ++v9;
      }
      goto LABEL_17;
    default:
LABEL_17:
      v6->EndCoarseLock(this: v6);
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10116D70
// Name: public: virtual void CBaseClient::SetName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetName(CBaseClient *this, const char *name)
{
  const char *v2; // esi
  char *m_Name; // edi
  CBaseClient *v5; // ecx
  char v6; // al
  int i; // edi
  CBaseClient *v8; // esi
  const char *v9; // eax
  char *v10; // eax
  char newname[32]; // [esp+Ch] [ebp-20h] BYREF
  int dupc; // [esp+34h] [ebp+8h]

  v2 = name;
  m_Name = this->m_Name;
  if ( V_strncmp(s1: name, s2: this->m_Name, count: 32) != 0 )
  {
    v5 = (CBaseClient *)m_Name;
    for ( dupc = 1; *v2 != 0; ++v2 )
    {
      if ( v5 >= (CBaseClient *)&this->m_Name[31] )
        break;
      v6 = *v2;
      if ( *v2 != 37 && v6 != 126 && (v6 != 35 || v5 != (CBaseClient *)this->m_Name) )
      {
        LOBYTE(v5->IGameEventListener2::__vftable) = v6;
        v5 = (CBaseClient *)((char *)v5 + 1);
      }
    }
    LOBYTE(v5->IGameEventListener2::__vftable) = 0;
    if ( _V_strlen(str: this->m_Name) <= 0 )
      V_snprintf(pDest: this->m_Name, maxLen: 32, pFormat: "unnamed");
    while ( 1 )
    {
      for ( i = 0; i < this->m_Server->GetClientCount(this: this->m_Server); ++i )
      {
        v8 = (CBaseClient *)this->m_Server->GetClient(this: this->m_Server, a2: i);
        if ( ((unsigned __int8 (__thiscall *)(CBaseClient *))v8->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: v8) != 0
          && v8 != (CBaseClient *)&this->IClient )
        {
          v9 = (const char *)((int (__thiscall *)(CBaseClient *))v8->SetUserCVar)(a1: v8);
          if ( _V_stricmp(s1: v9, s2: this->m_Name) == 0 )
            break;
        }
      }
      if ( i >= this->m_Server->GetClientCount(this: this->m_Server) )
        break;
      v10 = this->m_Name;
      if ( this->m_Name[0] == 40 )
      {
        if ( this->m_Name[2] == 41 )
        {
          v10 = &this->m_Name[3];
        }
        else if ( this->m_Name[3] == 41 )
        {
          v10 = &this->m_Name[4];
        }
      }
      V_snprintf(pDest: newname, maxLen: 32, pFormat: "(%d)%-.*s", dupc++, 28, v10);
      V_strncpy(pDest: this->m_Name, pSrc: newname, maxLen: 32);
    }
    KeyValues::SetString(this: this->m_ConVars, keyName: "name", value: this->m_Name);
    this->m_Server->UserInfoChanged(this: this->m_Server, a2: this->m_nClientSlot);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116EF0
// Name: protected: virtual void CBaseClient::PerformDisconnection(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::PerformDisconnection(CBaseClient *this, const char *pReason)
{
  CSteam3Server *v3; // eax
  IClient *v4; // edi
  bool v5; // bl
  bool (__thiscall *IsConnected)(IClient *); // eax
  int m_nClientSlot; // ebx
  const char *v8; // eax
  CBaseClient *m_pAttachedTo; // eax
  INetChannel *v10; // eax
  INetChannel *m_NetChannel; // ecx
  const char *v12; // [esp-4h] [ebp-10h]

  SV_NotifyRPTOfDisconnect(nClientSlot: this->m_nClientSlot);
  v3 = Steam3Server();
  CSteam3Server::NotifyClientDisconnect(this: v3, client: this);
  v4 = &this->IClient;
  v5 = this->IsConnected(this: &this->IClient);
  IsConnected = this->IsConnected;
  this->m_nSignonState = 0;
  if ( v5 != IsConnected(this: &this->IClient)
    && (!v4->IsFakeClient(this: &this->IClient) || v4->IsSplitScreenUser(this: &this->IClient)) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  if ( this->m_nClientSlot >= 0 )
  {
    m_nClientSlot = this->m_nClientSlot;
    if ( m_nClientSlot < this->m_Server->GetClientCount(this: this->m_Server)
      && this->m_Server->GetClient(this: this->m_Server, a2: m_nClientSlot) == v4 )
    {
      this->m_Server->UserInfoChanged(this: this->m_Server, a2: this->m_nClientSlot);
      if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue > 1
        || !v4->IsFakeClient(this: &this->IClient)
        || v4->IsSplitScreenUser(this: &this->IClient) )
      {
        v8 = (const char *)((int (__thiscall *)(IClient *, const char *))v4->GetClientName)(
                             a1: &this->IClient,
                             a2: pReason);
        ConMsg(a1: "Dropped %s from server (%s)\n", v8, v12);
      }
      g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: this);
      m_pAttachedTo = this->m_pAttachedTo;
      if ( m_pAttachedTo != nullptr && m_pAttachedTo->GetNetChannel(this: &m_pAttachedTo->IClient) != nullptr )
      {
        v10 = this->m_pAttachedTo->GetNetChannel(this: &this->m_pAttachedTo->IClient);
        v10->DetachSplitPlayer(this: v10, a2: this->m_nSplitScreenPlayerSlot);
        this->m_pAttachedTo = nullptr;
      }
      m_NetChannel = this->m_NetChannel;
      if ( m_NetChannel != nullptr )
      {
        m_NetChannel->Shutdown(this: m_NetChannel, a2: pReason);
        this->m_NetChannel = nullptr;
      }
      v4->Clear(this: &this->IClient);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117070
// Name: public: virtual bool CBaseClient::ProcessSignonState(class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ProcessSignonState(CBaseClient *this, NET_SignonState *msg)
{
  int m_nSignonState; // eax
  int v5; // eax

  m_nSignonState = msg->m_nSignonState;
  if ( m_nSignonState == 7 )
    return true;
  if ( m_nSignonState > 2
    && msg->m_nSpawnCount != (*(int (__thiscall **)(KeyValues *))(*(_DWORD *)this->m_ConVars + 60))(a1: this->m_ConVars)
    || (v5 = msg->m_nSignonState) != this->m_nFilesDownloaded )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 48))(a1: (char *)this - 4);
    return true;
  }
  return (*(bool (__thiscall **)(char *, int, int))(*((_DWORD *)this - 2) + 80))(
           a1: (char *)this - 8,
           a2: v5,
           a3: msg->m_nSpawnCount);
}

//------------------------------------------------------------------------------
// Address: 0x101170D0
// Name: public: virtual void CBaseClient::UpdateSendState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::UpdateSendState(CBaseClient *this)
{
  CBaseServer *m_Server; // ecx
  long double v3; // st7
  double v4; // st7
  long double v5; // st5
  INetChannel *m_NetChannel; // ecx
  float maxDelta; // [esp+4h] [ebp-4h]

  m_Server = this->m_Server;
  this->m_bReceivedPacket = false;
  if ( !m_Server->IsMultiplayer(this: m_Server) && host_limitlocal.m_pParent->m_Value.m_fValue == 0.0 )
  {
    v3 = net_time;
    this->m_bReceivedPacket = true;
    this->m_fNextMessageTime = v3;
    return;
  }
  if ( this->IsActive(this: &this->IClient) )
  {
    maxDelta = this->m_fSnapshotInterval;
    v4 = ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server);
    if ( maxDelta <= v4 )
      v4 = maxDelta;
    else
      this->m_Server->GetTickInterval(this: this->m_Server);
    v5 = net_time - this->m_fNextMessageTime;
    if ( v5 < 0.0 )
    {
      v5 = 0.0;
LABEL_10:
      this->m_fNextMessageTime = net_time + this->m_fSnapshotInterval - v5;
      return;
    }
    if ( v5 <= v4 )
      goto LABEL_10;
    this->m_fNextMessageTime = net_time + this->m_fSnapshotInterval - v4;
  }
  else
  {
    m_NetChannel = this->m_NetChannel;
    if ( m_NetChannel != nullptr
      && m_NetChannel->HasPendingReliableData(this: m_NetChannel)
      && ((double (__thiscall *)(INetChannel *))this->m_NetChannel->GetTimeSinceLastReceived)(a1: this->m_NetChannel) < 1.0 )
    {
      this->m_fNextMessageTime = net_time;
    }
    else
    {
      this->m_fNextMessageTime = net_time + 1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117210
// Name: public: unsigned __int64 CBaseClient::GetClientXuid(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetClientXuid(CBaseClient *this)
{
  KeyValues *m_ConVars; // ecx
  const char *String; // eax
  const char *v4; // esi
  unsigned int v5; // edi
  __int64 v6; // rax

  m_ConVars = this->m_ConVars;
  if ( m_ConVars != nullptr
    && (String = KeyValues::GetString(this: m_ConVars, keyName: "networkid_force", defaultValue: nullptr),
        v4 = String,
        String != nullptr)
    && *String != 0
    && strlen(String) > 0xA )
  {
    v5 = strtoul(nptr: v4 + 9, endptr: nullptr, ibase: 16);
    strtoul(nptr: v4, endptr: nullptr, ibase: 16);
    LODWORD(v6) = v5;
  }
  else if ( this->IsFakeClient(this: &this->IClient) )
  {
    LODWORD(v6) = 0;
  }
  else
  {
    return this->m_SteamID.m_steamid.m_unAll64Bits;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x101172A0
// Name: public: virtual struct USERID_s const CBaseClient::GetNetworkID(void)const
// Source: json
//------------------------------------------------------------------------------
const USERID_s *__thiscall CBaseClient::GetNetworkID(CBaseClient *this, const USERID_s *result)
{
  result->uid.steamid.m_SteamInstanceID = 0;
  result->uid.steamid.m_SteamLocalUserID.Split.High32bits = *(_DWORD *)&this->m_GUID[29] & 1;
  result->uid.steamid.m_SteamLocalUserID.Split.Low32bits = *(_DWORD *)&this->m_GUID[29] >> 1;
  result->idtype = 1;
  result->uid.steamid.m_SteamInstanceID = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10117370
// Name: public: virtual char const __near * CLC_VoiceData::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_VoiceData::GetName(CLC_VoiceData *this)
{
  return "clc_VoiceData";
}

//------------------------------------------------------------------------------
// Address: 0x10117380
// Name: public: virtual unsigned int CLC_VoiceData::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLC_VoiceData::GetSize(CSosOperatorConvar *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x101173A0
// Name: public: virtual bool CBaseClient::FillUserInfo(struct player_info_s __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::FillUserInfo(CBaseClient *this, player_info_s *userInfo)
{
  bool result; // al
  const char *v4; // eax
  const char *v5; // eax
  bool v6; // al

  _V_memset(dest: userInfo, fill: 0, count: 144);
  result = this->IsConnected(this: &this->IClient);
  if ( result )
  {
    v4 = this->GetClientName(this: &this->IClient);
    V_strncpy(pDest: userInfo->name, pSrc: v4, maxLen: 32);
    v5 = this->GetNetworkIDString(this: &this->IClient);
    _V_memcpy(dest: userInfo->guid, src: v5, count: 33);
    userInfo->friendsID = this->m_SteamID.m_steamid.m_unAll64Bits;
    userInfo->xuid = CBaseClient::GetClientXuid(this);
    V_strncpy(pDest: userInfo->friendsName, pSrc: this->m_FriendsName, maxLen: 32);
    userInfo->userID = this->GetUserID(this: &this->IClient);
    v6 = this->IsFakeClient(this: &this->IClient) && !this->IsSplitScreenUser(this: &this->IClient);
    userInfo->fakeplayer = v6;
    userInfo->ishltv = this->IsHLTV(this: &this->IClient);
    userInfo->customFiles[0] = this->m_nCustomFiles[0].crc;
    userInfo->customFiles[1] = this->m_nCustomFiles[1].crc;
    userInfo->customFiles[2] = this->m_nCustomFiles[2].crc;
    userInfo->customFiles[3] = this->m_nCustomFiles[3].crc;
    userInfo->filesDownloaded = this->m_nFilesDownloaded;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101174C0
// Name: public: virtual void CBaseClient::ClientPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseClient::ClientPrintf(CBaseClient *this, const char *fmt, ...)
{
  int m_nFilesDownloaded; // ecx
  char string[1024]; // [esp+0h] [ebp-C14h] BYREF
  SVC_Print print; // [esp+400h] [ebp-814h] BYREF
  va_list params; // [esp+C24h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  print.m_szText = string;
  m_nFilesDownloaded = this->m_nFilesDownloaded;
  print.m_NetChannel = nullptr;
  print.m_bReliable = false;
  print.__vftable = (SVC_Print_vtbl *)&SVC_Print::`vftable';
  (*(void (__thiscall **)(int, SVC_Print *, _DWORD, _DWORD))(*(_DWORD *)m_nFilesDownloaded + 164))(
    a1: m_nFilesDownloaded,
    a2: &print,
    a3: 0,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10117530
// Name: public: virtual void CBaseClient::FreeBaselines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::FreeBaselines(CBaseClient *this)
{
  CFrameSnapshot *m_pBaseline; // ecx

  m_pBaseline = this->m_pBaseline;
  if ( m_pBaseline != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_pBaseline);
    this->m_pBaseline = nullptr;
  }
  this->m_nBaselineUpdateTick = -1;
  this->m_nBaselineUsed = 0;
  if ( this != (CBaseClient *)-256 )
    memset(dst: (unsigned __int8 *)&this->m_BaselinesSent, value: 0, count: sizeof(this->m_BaselinesSent));
}

//------------------------------------------------------------------------------
// Address: 0x10117580
// Name: public: virtual void CBaseClient::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::Clear(CBaseClient *this)
{
  int m_nFilesDownloaded; // ecx
  KeyValues *v3; // ecx
  void (__thiscall *WriteGameSounds)(CBaseClient *, bf_write *, int); // edx
  CFrameSnapshot *m_nSignonTick; // ecx
  char v6; // [esp+Fh] [ebp-1h]

  m_nFilesDownloaded = this->m_nFilesDownloaded;
  if ( m_nFilesDownloaded != 0 )
  {
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)m_nFilesDownloaded + 148))(
      a1: m_nFilesDownloaded,
      a2: "Disconnect by server.\n");
    this->m_nFilesDownloaded = 0;
  }
  v3 = *(KeyValues **)&this->m_FriendsName[28];
  if ( v3 != nullptr )
  {
    KeyValues::deleteThis(this: v3);
    *(_DWORD *)&this->m_FriendsName[28] = 0;
  }
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 72))(a1: (char *)this - 4);
  v6 = ((int (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this);
  WriteGameSounds = this->IGameEventListener2::__vftable[1].WriteGameSounds;
  this->m_NetChannel = nullptr;
  if ( v6 != ((unsigned __int8 (__thiscall *)(CBaseClient *))WriteGameSounds)(a1: this)
    && (!this->IGameEventListener2::__vftable[1].SendServerInfo(this)
     || ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  this->m_nSignonState = -1;
  this->m_nStringTableAckTick = 0;
  this->m_nDeltaTick = 0;
  m_nSignonTick = (CFrameSnapshot *)this->m_nSignonTick;
  if ( m_nSignonTick != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_nSignonTick);
    this->m_nSignonTick = 0;
  }
  *(double *)(&this->m_bFullyAuthenticated + 1) = 0.0;
  this->m_nBaselineUsed = -1;
  LOBYTE(this->m_nForceWaitForTick) = 0;
  LOWORD(this->m_nDebugID) = 0;
  LOBYTE(this->m_pAttachedTo) = 0;
  *(_DWORD *)&this->m_bSplitScreenUser = 0;
  this->m_SplitScreenUsers[1] = nullptr;
  LOBYTE(this->m_Server) = 0;
  HIDWORD(this->m_fNextMessageTime) = 0;
  *(_WORD *)((char *)&this->m_nForceWaitForTick + 1) = 0;
  this->m_nEntityIndex = 0;
  LOBYTE(this->m_UserID) = 0;
  LOBYTE(this->m_nFriendsID) = 0;
  *(_DWORD *)&this->m_bIsHLTV = 0;
  this->m_pBaseline = (CFrameSnapshot *)-1;
  this->m_BaselinesSent.m_Ints[63] = 0;
  this->m_nCustomFiles[3].reqID = 0;
  LOWORD(this->m_ConVars) = 0;
  this->m_pLastSnapshot.m_pObj = nullptr;
  HIBYTE(this->m_nForceWaitForTick) = 0;
  LODWORD(this->m_fSnapshotInterval) = 1;
  _V_memset(dest: &this->m_nSendtableCRC, fill: 0, count: 32);
}

//------------------------------------------------------------------------------
// Address: 0x101176E0
// Name: public: virtual void CBaseClient::Disconnect(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseClient::Disconnect(int a1@<esi>, CBaseClient *this, const char *fmt, ...)
{
  int v3; // ebx
  const char *v4; // eax
  bool (__thiscall *FillUserInfo)(CBaseClient *, player_info_s *); // edx
  int *v6; // esi
  int v7; // ebx
  int v8; // ecx
  int v9; // eax
  char *v10; // eax
  CSteam3Server *v11; // eax
  char string[1024]; // [esp+4h] [ebp-814h] BYREF
  NET_StringCmd stringCmd; // [esp+404h] [ebp-414h] BYREF
  va_list params; // [esp+828h] [ebp+10h] BYREF

  va_start(params, fmt);
  if ( this->m_NetChannel != nullptr && *(int *)&this->m_bSplitPlayerDisconnecting >= 0 )
  {
    v3 = *(_DWORD *)&this->m_bSplitPlayerDisconnecting;
    if ( v3 < (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_bConVarsChanged + 28))(a1: *(_DWORD *)&this->m_bConVarsChanged)
      && (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->m_bConVarsChanged + 24))(
           a1: *(_DWORD *)&this->m_bConVarsChanged,
           a2: v3) == (this != (CBaseClient *)4 ? (unsigned int)this : 0) )
    {
      if ( ((unsigned __int8 (__thiscall *)(CBaseClient *, int))this->IGameEventListener2::__vftable[1].SetUserCVar)(
             a1: this,
             a2: a1) == 0
        || BYTE1(this->m_nDebugID) != 0 )
      {
        if ( ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) == 0
          && host_state.max_splitscreen_players > 1 )
        {
          v6 = &this->m_nSplitScreenPlayerSlot + host_state.max_splitscreen_players;
          v7 = host_state.max_splitscreen_players - 1;
          do
          {
            v8 = *--v6;
            if ( v8 != 0 )
            {
              (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 84))(a1: v8, a2: "leaving splitscreen");
              *v6 = 0;
            }
            --v7;
          }
          while ( v7 != 0 );
        }
        v9 = V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
        if ( v9 > 0 )
        {
          v10 = &string[v9 - 1];
          do
          {
            if ( *v10 != 10 )
              break;
            *v10-- = 0;
          }
          while ( (int)&v10[1 - (_DWORD)string] > 0 );
        }
        (*(void (__thiscall **)(char *, char *))(*((_DWORD *)this - 1) + 84))(a1: (char *)this - 4, a2: string);
        NotifyDedicatedServerUI(message: "UpdatePlayers");
        v11 = Steam3Server();
        CSteam3Server::SendUpdatedServerDetails(this: v11);
      }
      else
      {
        v4 = va(format: "ss_disconnect %d\n", *(_DWORD *)&this->m_bSplitScreenUser);
        FillUserInfo = this->IGameEventListener2::__vftable[1].FillUserInfo;
        stringCmd.m_szCommand = v4;
        stringCmd.m_bReliable = true;
        stringCmd.m_NetChannel = nullptr;
        stringCmd.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
        ((void (__thiscall *)(CBaseClient *, NET_StringCmd *, int))FillUserInfo)(a1: this, a2: &stringCmd, a3: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117860
// Name: public: void CBaseClient::ApplyConVars(class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::ApplyConVars(
        CBaseClient *this,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *list)
{
  int v2; // esi
  int v3; // ebx
  CBaseClient *v4; // [esp+8h] [ebp-4h]

  v2 = 0;
  v4 = this;
  if ( list->m_Size <= 0 )
  {
    this->m_bConVarsChanged = true;
  }
  else
  {
    v3 = 0;
    while ( 1 )
    {
      KeyValues::SetString(
        this: this->m_ConVars,
        keyName: list->m_Memory.m_pMemory[v3].name,
        value: list->m_Memory.m_pMemory[v3].value);
      ++v2;
      ++v3;
      if ( v2 >= list->m_Size )
        break;
      this = v4;
    }
    v4->m_bConVarsChanged = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101178D0
// Name: public: virtual bool CBaseClient::ProcessSetConVar(class NET_SetConVar __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessSetConVar(CBaseClient *this, NET_SetConVar *msg)
{
  CBaseClient::ApplyConVars(this: (CBaseClient *)((char *)this - 8), list: &msg->m_ConVars);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101178F0
// Name: public: virtual bool CBaseClient::ProcessBaselineAck(class CLC_BaselineAck __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessBaselineAck(CBaseClient *this, CFrameSnapshot *msg)
{
  int v4; // eax
  int NextSetBit; // edi
  int v6; // esi
  int m_pPackedData; // eax
  CFrameSnapshotEntry *m_pEntities; // edx
  CFrameSnapshotEntry *v9; // eax
  CFrameSnapshotEntry *v10; // ecx
  BOOL v11; // ecx
  int hNewEntity; // [esp+4h] [ebp-4h]
  CFrameSnapshot *pSnapshot; // [esp+10h] [ebp+8h]

  if ( msg->m_pValidEntities != (unsigned __int16 *)this->m_nLoadingProgress )
    return 1;
  if ( msg->m_nValidEntities != this->m_BaselinesSent.m_Ints[62] )
  {
    DevMsg(a1: "CBaseClient::ProcessBaselineAck: wrong baseline nr received (%i)\n", msg->m_pValidEntities);
    return 1;
  }
  v4 = (*(int (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 40))(
         a1: (char *)this - 8,
         a2: this->m_nLoadingProgress);
  if ( v4 == 0 )
    return 1;
  pSnapshot = *(CFrameSnapshot **)(v4 + 280);
  if ( pSnapshot != nullptr )
  {
    NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(this: (CFixedBitVecBase<2048> *)&this->m_pBaseline, startBit: 0);
    if ( NextSetBit < 0 )
    {
LABEL_13:
      this->m_pLastSnapshot.m_pObj->m_nTickCount = this->m_nLoadingProgress;
      v11 = this->m_BaselinesSent.m_Ints[62] != 1;
      this->m_nLoadingProgress = -1;
      this->m_BaselinesSent.m_Ints[62] = v11;
      return 1;
    }
    else
    {
      while ( 1 )
      {
        v6 = NextSetBit;
        m_pPackedData = pSnapshot->m_pEntities[NextSetBit].m_pPackedData;
        hNewEntity = m_pPackedData;
        if ( m_pPackedData == 0 )
          break;
        m_pEntities = this->m_pLastSnapshot.m_pObj->m_pEntities;
        if ( m_pEntities[v6].m_pPackedData != 0 )
        {
          CFrameSnapshotManager::RemoveEntityReference(
            this: framesnapshotmanager,
            handle: m_pEntities[v6].m_pPackedData);
          m_pPackedData = hNewEntity;
        }
        CFrameSnapshotManager::AddEntityReference(this: framesnapshotmanager, handle: m_pPackedData);
        v9 = pSnapshot->m_pEntities;
        v10 = this->m_pLastSnapshot.m_pObj->m_pEntities;
        v10[NextSetBit].m_pClass = v9[NextSetBit].m_pClass;
        v10[v6].m_nSerialNumber = v9[v6].m_nSerialNumber;
        v10[v6].m_pPackedData = v9[v6].m_pPackedData;
        NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                       this: (CFixedBitVecBase<2048> *)&this->m_pBaseline,
                       startBit: NextSetBit + 1);
        if ( NextSetBit < 0 )
          goto LABEL_13;
      }
      DevMsg(a1: "CBaseClient::ProcessBaselineAck: invalid packet handle (%i)\n", NextSetBit);
      return 0;
    }
  }
  else
  {
    DevMsg(a1: "CBaseClient::ProcessBaselineAck: invalid frame snapshot (%i)\n", this->m_nLoadingProgress);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117A60
// Name: public: virtual bool CBaseClient::ProcessListenEvents(class CLC_ListenEvents __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessListenEvents(CBaseClient *this, CLC_ListenEvents *msg)
{
  char *v2; // edi
  unsigned int v3; // esi
  CGameEventDescriptor *EventDescriptor; // eax

  v2 = (char *)this - 8;
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: (CBaseClient *)((char *)this - 8));
  v3 = 0;
  while ( ((1 << (v3 & 0x1F)) & msg->m_EventArray.m_Ints[v3 >> 5]) == 0 )
  {
LABEL_5:
    if ( (int)++v3 >= 512 )
      return 1;
  }
  EventDescriptor = CGameEventManager::GetEventDescriptor(this: g_GameEventManager, eventid: v3);
  if ( EventDescriptor != nullptr )
  {
    CGameEventManager::AddListener(
      this: g_GameEventManager,
      listener: v2,
      descriptor: EventDescriptor,
      nListenerType: 2);
    goto LABEL_5;
  }
  DevMsg(a1: "ProcessListenEvents: game event %i not found.\n", v3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10117AE0
// Name: private: void CBaseClient::OnRequestFullUpdate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::OnRequestFullUpdate(CBaseClient *this, const char *pchReason)
{
  CFrameSnapshot *m_pObj; // ecx
  CFrameSnapshot *EmptySnapshot; // eax
  IClient_vtbl *v5; // edx
  const char *v6; // eax
  const char *v7; // [esp-4h] [ebp-8h]

  m_pObj = this->m_pLastSnapshot.m_pObj;
  if ( m_pObj != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_pObj);
    this->m_pLastSnapshot.m_pObj = nullptr;
  }
  this->FreeBaselines(this);
  EmptySnapshot = CFrameSnapshotManager::CreateEmptySnapshot(
                    this: framesnapshotmanager,
                    tickcount: 0,
                    maxEntities: 2048);
  v5 = this->IClient::INetChannelHandler::__vftable;
  this->m_pBaseline = EmptySnapshot;
  v6 = (const char *)((int (__thiscall *)(IClient *, const char *))v5->GetClientName)(a1: &this->IClient, a2: pchReason);
  DevMsg(a1: "Sending full update to Client %s (%s)\n", v6, v7);
}

//------------------------------------------------------------------------------
// Address: 0x10117B50
// Name: public: virtual bool CBaseClient::UpdateAcknowledgedFramecount(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::UpdateAcknowledgedFramecount(CBaseClient *this, int tick)
{
  IClient *v3; // ebx
  int m_nForceWaitForTick; // eax
  int v6; // edi
  int m_nDeltaTick; // eax
  int m_nBaselineUpdateTick; // eax

  v3 = &this->IClient;
  if ( this->IsFakeClient(this: &this->IClient) )
  {
    this->m_nDeltaTick = tick;
    this->m_nStringTableAckTick = tick;
    return 1;
  }
  m_nForceWaitForTick = this->m_nForceWaitForTick;
  if ( m_nForceWaitForTick > 0 )
  {
    v6 = tick;
    if ( tick <= m_nForceWaitForTick )
    {
      if ( tick == -1 )
      {
        if ( !this->m_NetChannel->HasPendingReliableData(this: this->m_NetChannel) )
        {
          _ConDMsg(a1: "Client forced immediate full update.\n");
          this->m_nDeltaTick = -1;
          this->m_nForceWaitForTick = -1;
          CBaseClient::OnRequestFullUpdate(this, pchReason: "forced immediate full update");
          return 1;
        }
        goto LABEL_13;
      }
      if ( tick >= m_nForceWaitForTick )
      {
        this->m_nForceWaitForTick = -1;
LABEL_13:
        this->m_nDeltaTick = v6;
        if ( v6 > -1 )
          this->m_nStringTableAckTick = v6;
        m_nBaselineUpdateTick = this->m_nBaselineUpdateTick;
        if ( m_nBaselineUpdateTick > -1 && v6 > m_nBaselineUpdateTick )
          this->m_nBaselineUpdateTick = -1;
      }
    }
    return 1;
  }
  m_nDeltaTick = this->m_nDeltaTick;
  if ( m_nDeltaTick == -1 )
    return 1;
  v6 = tick;
  if ( tick == -1 )
  {
    CBaseClient::OnRequestFullUpdate(this, pchReason: "client ack'd -1");
    goto LABEL_13;
  }
  if ( m_nDeltaTick <= tick )
    goto LABEL_13;
  v3->Disconnect(this: v3, a2: "Client delta ticks out of order.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10117C60
// Name: public: static int SessionClient_t::Less(struct SessionClient_t const __near *,struct SessionClient_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SessionClient_t::Less(const SessionClient_t *a, const SessionClient_t *b)
{
  __int64 v2; // rax
  int numPlayers; // eax
  int m_Size; // ecx
  IClient *v6; // esi
  int v7; // edi

  HIDWORD(v2) = a->xSession;
  LODWORD(v2) = HIDWORD(a->xSession);
  if ( LODWORD(a->xSession) != LODWORD(b->xSession) || (_DWORD)v2 != HIDWORD(b->xSession) )
  {
    if ( v2 == 0 )
      return 1;
    if ( b->xSession == 0 )
      return -1;
  }
  numPlayers = a->numPlayers;
  m_Size = b->numPlayers;
  if ( numPlayers != m_Size )
    return 2 * (numPlayers <= m_Size) - 1;
  numPlayers = a->arrClients.m_Size;
  m_Size = b->arrClients.m_Size;
  if ( numPlayers != m_Size )
    return 2 * (numPlayers <= m_Size) - 1;
  if ( a->xSession != b->xSession )
  {
    if ( a->xSession == CBaseServer::GetReservationCookie(this: &sv) )
      return -1;
    if ( b->xSession == CBaseServer::GetReservationCookie(this: &sv) )
      return 1;
  }
  v6 = *b->arrClients.m_Memory.m_pMemory;
  v7 = (*(int (__thiscall **)(IClient *))(**(_DWORD **)a->arrClients.m_Memory.m_pMemory + 60))(a1: *a->arrClients.m_Memory.m_pMemory);
  return 2 * (v7 >= v6->GetUserID(this: v6)) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117D20
// Name: public: void CBaseClient::DisconnectSplitScreenUser(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::DisconnectSplitScreenUser(CBaseClient *this, CBaseClient *pSplitClient)
{
  int m_nSplitScreenPlayerSlot; // edi
  INetChannel *m_NetChannel; // ecx
  SVC_SplitScreen msg; // [esp+8h] [ebp-1Ch] BYREF

  CBaseServer::QueueSplitScreenDisconnect(this: &sv, pSplitHost: this, pSplitUser: pSplitClient);
  m_nSplitScreenPlayerSlot = pSplitClient->m_nSplitScreenPlayerSlot;
  m_NetChannel = this->m_NetChannel;
  msg.m_nPlayerIndex = pSplitClient->m_nEntityIndex;
  msg.m_bReliable = true;
  msg.m_NetChannel = nullptr;
  msg.__vftable = (SVC_SplitScreen_vtbl *)&SVC_SplitScreen::`vftable';
  msg.m_nSlot = m_nSplitScreenPlayerSlot;
  msg.m_Type = MSG_REMOVEUSER;
  m_NetChannel->DetachSplitPlayer(this: m_NetChannel, a2: m_nSplitScreenPlayerSlot);
  this->SendNetMsg(this: &this->IClient, a2: &msg, a3: true, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10117E40
// Name: public: virtual class IClient __near * CBaseServer::GetClient(int)
// Source: json
//------------------------------------------------------------------------------
IClient *__thiscall CBaseServer::GetClient(CBaseServer *this, int index)
{
  CBaseClient *v2; // eax

  v2 = this->m_Clients.m_Memory.m_pMemory[index];
  if ( v2 != nullptr )
    return &v2->IClient;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10117E60
// Name: public: virtual void CBaseClient::Connect(char const __near *,int,class INetChannel __near *,bool,enum CrossPlayPlatform_t,class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::Connect(
        CBaseClient *this,
        const char *szName,
        int nUserID,
        INetChannel *pNetChannel,
        bool bFakePlayer,
        float clientPlatform,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *pVecCvars)
{
  IEngineVGuiInternal *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  CBaseClient *v11; // edi
  CBaseClient *v12; // ecx
  const char *v13; // eax
  CSteam3Server *v14; // eax
  int v15; // ecx
  char v16; // bl
  void (__thiscall *WriteGameSounds)(CBaseClient *, bf_write *, int); // eax

  _COM_TimestampedLog(a1: "CBaseClient::Connect");
  if ( !bFakePlayer )
  {
    v8 = EngineVGui();
    v8->UpdateProgressBar(this: v8, a2: PROGRESS_SIGNONCONNECT, a3: false);
  }
  ((void (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].UpdateAcknowledgedFramecount)(a1: this);
  this->m_nEntityIndex = nUserID;
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "userinfo");
  else
    v10 = nullptr;
  *(_DWORD *)&this->m_FriendsName[28] = v10;
  v11 = (CBaseClient *)((char *)this - 4);
  v12 = (CBaseClient *)((char *)this - 4);
  if ( pVecCvars != nullptr )
  {
    CBaseClient::ApplyConVars(this: v12, list: pVecCvars);
    v13 = (const char *)((int (__thiscall *)(CBaseClient *, const char *))this->ProcessSignonStateMsg)(
                          a1: this,
                          a2: "name");
    if ( v13 == nullptr || *v13 == 0 )
      v13 = szName;
    v11->SetName(this: (CBaseClient *)((char *)this - 4), a2: v13);
  }
  else
  {
    v11->SetName(this: v12, a2: szName);
  }
  LOBYTE(this->m_nForceWaitForTick) = bFakePlayer;
  if ( bFakePlayer )
  {
    v14 = Steam3Server();
    CSteam3Server::NotifyLocalClientConnect(this: v14, client: (CBaseClient *)((char *)this - 4));
  }
  this->m_nFilesDownloaded = (int)pNetChannel;
  if ( pNetChannel != nullptr )
  {
    v15 = *(_DWORD *)&this->m_bConVarsChanged;
    if ( v15 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v15 + 100))(a1: v15) != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)this->m_nFilesDownloaded + 248))(
        a1: this->m_nFilesDownloaded,
        a2: 1);
  }
  this->m_fSnapshotInterval = clientPlatform;
  v16 = ((int (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this);
  WriteGameSounds = this->IGameEventListener2::__vftable[1].WriteGameSounds;
  v11->m_nSignonState = 2;
  if ( v16 != ((unsigned __int8 (__thiscall *)(CBaseClient *))WriteGameSounds)(a1: this)
    && (!this->IGameEventListener2::__vftable[1].SendServerInfo(this)
     || ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117FC0
// Name: public: virtual void CBaseClient::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::FireGameEvent(CBaseClient *this, IGameEvent *event)
{
  unsigned __int8 v4; // al
  const char *v5; // eax
  const char *v6; // eax
  char buffer_data[1024]; // [esp+Ch] [ebp-450h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-50h] BYREF
  INetChannel_vtbl *eventa; // [esp+464h] [ebp+8h]

  eventMsg.m_bReliable = true;
  eventMsg.m_NetChannel = nullptr;
  eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
  eventMsg.m_DataIn.m_bOverflow = false;
  eventMsg.m_DataIn.m_pDebugName = nullptr;
  eventMsg.m_DataIn.m_nDataBits = -1;
  eventMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &eventMsg.m_DataOut);
  bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
  if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventMsg.m_DataOut) )
  {
    if ( this->m_NetChannel != nullptr )
    {
      eventa = this->m_NetChannel->__vftable;
      v4 = ((int (__thiscall *)(IGameEvent *, _DWORD))event->IsReliable)(a1: event, a2: 0);
      ((void (__thiscall *)(INetChannel *, SVC_GameEvent *, _DWORD))eventa->SendNetMsg)(
        a1: this->m_NetChannel,
        a2: &eventMsg,
        a3: v4);
      v5 = event->GetName(this: event);
      if ( _V_stricmp(s1: v5, s2: "server_pre_shutdown") == 0 )
        this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
    }
  }
  else
  {
    v6 = event->GetName(this: event);
    DevMsg(a1: "GameEventManager: failed to serialize event '%s'.\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101180C0
// Name: public: virtual bool CBaseClient::ProcessSplitPlayerConnect(class CLC_SplitPlayerConnect __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessSplitPlayerConnect(CBaseClient *this, CLC_SplitPlayerConnect *msg)
{
  int v3; // edi
  int *p_m_nSplitScreenPlayerSlot; // eax
  CBaseClient *SplitClient; // esi
  unsigned int reqID; // ecx
  INetChannel *m_NetChannel; // edx
  void **v9; // [esp+8h] [ebp-1Ch] BYREF
  char v10; // [esp+Ch] [ebp-18h]
  int v11; // [esp+10h] [ebp-14h]
  int v12; // [esp+18h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-8h]
  int m_nEntityIndex; // [esp+20h] [ebp-4h]

  v3 = 1;
  if ( host_state.max_splitscreen_players <= 1 )
    goto LABEL_7;
  p_m_nSplitScreenPlayerSlot = &this->m_nSplitScreenPlayerSlot;
  while ( *p_m_nSplitScreenPlayerSlot != 0 )
  {
    ++v3;
    ++p_m_nSplitScreenPlayerSlot;
    if ( v3 >= host_state.max_splitscreen_players )
      goto LABEL_7;
  }
  if ( v3 == -1 )
  {
LABEL_7:
    _Warning(a1: "no more split screen slots!\n");
    (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
      a1: (char *)this - 4,
      a2: "No more split screen slots!");
    return 1;
  }
  else
  {
    SplitClient = CBaseServer::CreateSplitClient(
                    this: &sv,
                    vecUserInfo: &msg->m_UserInfo,
                    pAttachedTo: (CBaseClient *)((char *)this - 8));
    if ( SplitClient != nullptr )
    {
      SplitClient->m_nSplitScreenPlayerSlot = v3;
      *((_DWORD *)&this->m_bSplitScreenUser + v3) = SplitClient;
      reqID = this->m_nCustomFiles[3].reqID;
      m_nEntityIndex = SplitClient->m_nEntityIndex;
      m_NetChannel = SplitClient->m_NetChannel;
      v11 = 0;
      v12 = 0;
      v10 = 1;
      v9 = &SVC_SplitScreen::`vftable';
      v13 = v3;
      (*(void (__thiscall **)(unsigned int, int, INetChannel *))(*(_DWORD *)reqID + 288))(
        a1: reqID,
        a2: v3,
        a3: m_NetChannel);
      (*(void (__thiscall **)(char *, void ***, int, _DWORD))(*((_DWORD *)this - 1) + 116))(
        a1: (char *)this - 4,
        a2: &v9,
        a3: 1,
        a4: 0);
      if ( SplitClient->m_pAttachedTo->IsActive(this: &SplitClient->m_pAttachedTo->IClient) )
        SplitClient->ActivatePlayer(this: SplitClient);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101181B0
// Name: public: void CBaseClient::SplitScreenDisconnect(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SplitScreenDisconnect(CBaseClient *this, const CCommand *args)
{
  int v3; // eax
  CBaseClient *v4; // eax

  v3 = 1;
  if ( args->m_nArgc > 1 )
  {
    v3 = V_atoi(str: args->m_ppArgv[1]);
    if ( v3 <= 0 )
      v3 = 1;
  }
  v4 = this->m_SplitScreenUsers[v3];
  if ( v4 != nullptr )
    CBaseClient::DisconnectSplitScreenUser(this, pSplitClient: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10118340
// Name: public: virtual CBaseClient::~CBaseClient(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::~CBaseClient(CBaseClient *this)
{
  CFrameSnapshot *m_pObj; // ecx

  this->IGameEventListener2::__vftable = (CBaseClient_vtbl *)&CBaseClient::`vftable'{for `IGameEventListener2'};
  this->IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CBaseClient::`vftable'{for `IClient'};
  this->IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CBaseClient::`vftable'{for `IClientMessageHandler'};
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: this);
  this->m_nDebugID = 13;
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Trace.m_Records);
  m_pObj = this->m_pLastSnapshot.m_pObj;
  if ( m_pObj != nullptr )
    CFrameSnapshot::ReleaseReference(this: m_pObj);
  this->IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&INetMessageHandler::`vftable';
  this->IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&INetChannelHandler::`vftable';
  this->IGameEventListener2::__vftable = (CBaseClient_vtbl *)&IGameEventListener2::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x101183C0
// Name: public: virtual char const __near * CBaseClient::GetClientName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseClient::GetClientName(CBaseClient *this)
{
  return (const char *)&this->m_UserID;
}

//------------------------------------------------------------------------------
// Address: 0x101183D0
// Name: public: virtual class INetChannel __near * CBaseClient::GetNetChannel(void)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CBaseClient::GetNetChannel(CBaseClient *this)
{
  return (INetChannel *)this->m_nFilesDownloaded;
}

//------------------------------------------------------------------------------
// Address: 0x101183E0
// Name: public: virtual class IServer __near * CBaseClient::GetServer(void)
// Source: json
//------------------------------------------------------------------------------
IServer *__thiscall CBaseClient::GetServer(CBaseClient *this)
{
  return *(IServer **)&this->m_bConVarsChanged;
}

//------------------------------------------------------------------------------
// Address: 0x101183F0
// Name: public: virtual bool CBaseClient::IsConnected(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClient::IsConnected(CBaseClient *this)
{
  return (int)this->m_NetChannel >= 2;
}

//------------------------------------------------------------------------------
// Address: 0x10118400
// Name: public: virtual bool CBaseClient::IsSpawned(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClient::IsSpawned(CBaseClient *this)
{
  return (int)this->m_NetChannel >= 3;
}

//------------------------------------------------------------------------------
// Address: 0x10118410
// Name: public: virtual bool CBaseClient::IsActive(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClient::IsActive(CBaseClient *this)
{
  return this->m_NetChannel == (INetChannel *)6;
}

//------------------------------------------------------------------------------
// Address: 0x10118430
// Name: public: virtual bool CBaseClient::IsHLTV(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsHLTV(CBaseClient *this)
{
  return (bool)this->m_Server;
}

//------------------------------------------------------------------------------
// Address: 0x10118440
// Name: public: virtual bool CBaseClient::IsLowViolenceClient(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsLowViolenceClient(CBaseClient *this)
{
  return BYTE2(this->m_nForceWaitForTick);
}

//------------------------------------------------------------------------------
// Address: 0x10118450
// Name: public: virtual bool CBaseClient::IsSplitScreenUser(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsSplitScreenUser(CBaseClient *this)
{
  return this->m_nDebugID;
}

//------------------------------------------------------------------------------
// Address: 0x10118460
// Name: public: virtual class IClient __near * CBaseClient::GetSplitScreenOwner(void)
// Source: json
//------------------------------------------------------------------------------
IClient *__thiscall CBaseClient::GetSplitScreenOwner(CBaseClient *this)
{
  CBaseClient *v1; // eax

  v1 = this->m_SplitScreenUsers[1];
  if ( v1 != nullptr )
    return &v1->IClient;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10118470
// Name: public: CBaseClient::CBaseClient(void)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseClient::CBaseClient(CBaseClient *this)
{
  this->IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&IClient::`vftable';
  this->IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&IClientMessageHandler::`vftable';
  this->IGameEventListener2::__vftable = (CBaseClient_vtbl *)&CBaseClient::`vftable'{for `IGameEventListener2'};
  this->IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CBaseClient::`vftable'{for `IClient'};
  this->IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CBaseClient::`vftable'{for `IClientMessageHandler'};
  *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_SteamID.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1) &= 0xFFF00000;
  *(_DWORD *)&this->m_SteamID.m_steamid.m_comp = 0;
  this->m_pLastSnapshot.m_pObj = nullptr;
  if ( this != (CBaseClient *)-256 )
    memset(dst: (unsigned __int8 *)&this->m_BaselinesSent, value: 0, count: sizeof(this->m_BaselinesSent));
  this->m_Trace.m_nMinWarningBytes = 0;
  this->m_Trace.m_nStartBit = 0;
  this->m_Trace.m_nCurBit = 0;
  this->m_Trace.m_Records.m_Memory.m_pMemory = nullptr;
  this->m_Trace.m_Records.m_Memory.m_nAllocationCount = 0;
  this->m_Trace.m_Records.m_Memory.m_nGrowSize = 0;
  this->m_Trace.m_Records.m_Size = 0;
  this->m_Trace.m_Records.m_pElements = nullptr;
  this->m_NetChannel = nullptr;
  this->m_ConVars = nullptr;
  this->m_Server = nullptr;
  this->m_pBaseline = nullptr;
  this->m_bIsHLTV = false;
  *(_WORD *)&this->m_bConVarsChanged = 0;
  this->m_bFullyAuthenticated = false;
  this->m_nSignonState = 0;
  *(_WORD *)&this->m_bSplitScreenUser = 0;
  this->m_bSplitPlayerDisconnecting = false;
  this->m_nSplitScreenPlayerSlot = 0;
  this->m_pAttachedTo = nullptr;
  _V_memset(dest: this->m_SplitScreenUsers, fill: 0, count: 8);
  this->m_SplitScreenUsers[0] = this;
  this->m_ClientPlatform = CROSSPLAYPLATFORM_PC;
  this->m_nDebugID = 42;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101185A0
// Name: public: virtual void CBaseClient::ConnectionStart(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::ConnectionStart(CBaseClient *this, INetChannel *chan)
{
  INetMessage *v3; // eax
  IClient *v4; // ebx
  IClient *v5; // ecx
  INetMessage *v6; // eax
  IClient *v7; // ecx
  INetMessage *v8; // eax
  IClient *v9; // ecx
  INetMessage *v10; // eax
  IClient *v11; // ecx
  NET_SplitScreenUser *v12; // eax
  NET_SplitScreenUser *v13; // eax
  IClient *v14; // ecx
  INetMessage *v15; // eax
  IClient *v16; // ecx
  char *v17; // eax
  INetMessage *v18; // edi
  IClient *v19; // eax
  char *v20; // eax
  INetMessage *v21; // edi
  INetMessage *v22; // eax
  IClient *v23; // ecx
  INetMessage *v24; // eax
  IClient *v25; // ecx
  _BYTE *v26; // edi
  INetMessage *v27; // eax
  IClient *v28; // ecx
  INetMessage *v29; // eax
  IClient *v30; // ecx
  INetMessage *v31; // eax
  IClient *v32; // ecx
  INetMessage *v33; // eax
  IClient *v34; // ecx
  INetMessage *v35; // eax
  IClient *v36; // ecx
  CLC_CmdKeyValues *v37; // eax
  CLC_CmdKeyValues *v38; // eax

  v3 = (INetMessage *)calloc(count: 1u, size: 0x1Cu);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3[2].__vftable = nullptr;
    v3->__vftable = (INetMessage_vtbl *)&NET_Tick::`vftable';
    LOBYTE(v3[1].__vftable) = 0;
    v3[5].__vftable = nullptr;
    v3[6].__vftable = nullptr;
  }
  else
  {
    v3 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v5 = nullptr;
  else
    v5 = &this->IClient;
  v3[3].__vftable = (INetMessage_vtbl *)v5;
  chan->RegisterMessage(this: chan, a2: v3);
  v6 = (INetMessage *)calloc(count: 1u, size: 0x414u);
  if ( v6 != nullptr )
  {
    LOBYTE(v6[1].__vftable) = 1;
    v6[2].__vftable = nullptr;
    v6->__vftable = (INetMessage_vtbl *)&NET_StringCmd::`vftable';
    v6[4].__vftable = nullptr;
  }
  else
  {
    v6 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v7 = nullptr;
  else
    v7 = &this->IClient;
  v6[3].__vftable = (INetMessage_vtbl *)v7;
  chan->RegisterMessage(this: chan, a2: v6);
  v8 = (INetMessage *)calloc(count: 1u, size: 0x24u);
  if ( v8 != nullptr )
  {
    LOBYTE(v8[1].__vftable) = 1;
    v8[2].__vftable = nullptr;
    v8->__vftable = (INetMessage_vtbl *)&NET_SetConVar::`vftable';
    v8[4].__vftable = nullptr;
    v8[5].__vftable = nullptr;
    v8[6].__vftable = nullptr;
    v8[7].__vftable = nullptr;
    v8[8].__vftable = nullptr;
  }
  else
  {
    v8 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v9 = nullptr;
  else
    v9 = &this->IClient;
  v8[3].__vftable = (INetMessage_vtbl *)v9;
  chan->RegisterMessage(this: chan, a2: v8);
  v10 = (INetMessage *)calloc(count: 1u, size: 0x44u);
  if ( v10 != nullptr )
  {
    LOBYTE(v10[1].__vftable) = 1;
    v10[2].__vftable = nullptr;
    v10->__vftable = (INetMessage_vtbl *)&NET_SignonState::`vftable';
    v10[7].__vftable = nullptr;
    v10[8].__vftable = nullptr;
    v10[9].__vftable = nullptr;
    v10[10].__vftable = nullptr;
    v10[11].__vftable = nullptr;
    v10[12].__vftable = nullptr;
    v10[13].__vftable = nullptr;
    v10[14].__vftable = nullptr;
    v10[15].__vftable = nullptr;
    v10[16].__vftable = nullptr;
  }
  else
  {
    v10 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v11 = nullptr;
  else
    v11 = &this->IClient;
  v10[3].__vftable = (INetMessage_vtbl *)v11;
  chan->RegisterMessage(this: chan, a2: v10);
  v12 = (NET_SplitScreenUser *)calloc(count: 1u, size: 0x14u);
  if ( v12 != nullptr )
    v13 = NET_SplitScreenUser::NET_SplitScreenUser(this: v12);
  else
    v13 = nullptr;
  if ( this == (CBaseClient *)4 )
    v14 = nullptr;
  else
    v14 = &this->IClient;
  v13->m_pMessageHandler = (INetMessageHandler *)v14;
  chan->RegisterMessage(this: chan, a2: v13);
  v15 = (INetMessage *)calloc(count: 1u, size: 0x50u);
  if ( v15 != nullptr )
  {
    LOBYTE(v15[1].__vftable) = 1;
    v15[2].__vftable = nullptr;
    v15->__vftable = (INetMessage_vtbl *)&CLC_ClientInfo::`vftable';
  }
  else
  {
    v15 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v16 = nullptr;
  else
    v16 = &this->IClient;
  v15[3].__vftable = (INetMessage_vtbl *)v16;
  chan->RegisterMessage(this: chan, a2: v15);
  v17 = (char *)calloc(count: 1u, size: 0x58u);
  v18 = (INetMessage *)v17;
  if ( v17 != nullptr )
  {
    v17[4] = 1;
    *((_DWORD *)v17 + 2) = 0;
    *(_DWORD *)v17 = &CLC_Move::`vftable';
    v17[32] = 0;
    *((_DWORD *)v17 + 7) = 0;
    *((_DWORD *)v17 + 9) = -1;
    *((_DWORD *)v17 + 10) = 0;
    bf_write::bf_write(this: (bf_write *)(v17 + 64));
    LOBYTE(v18[1].__vftable) = 0;
  }
  else
  {
    v18 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v19 = nullptr;
  else
    v19 = &this->IClient;
  v18[3].__vftable = (INetMessage_vtbl *)v19;
  chan->RegisterMessage(this: chan, a2: v18);
  v20 = (char *)calloc(count: 1u, size: 0x58u);
  v21 = (INetMessage *)v20;
  if ( v20 != nullptr )
  {
    v20[4] = 1;
    *((_DWORD *)v20 + 2) = 0;
    *(_DWORD *)v20 = &CLC_VoiceData::`vftable';
    v20[24] = 0;
    *((_DWORD *)v20 + 5) = 0;
    *((_DWORD *)v20 + 7) = -1;
    *((_DWORD *)v20 + 8) = 0;
    bf_write::bf_write(this: (bf_write *)(v20 + 56));
    LOBYTE(v21[1].__vftable) = 0;
    v21[20].__vftable = nullptr;
    v21[21].__vftable = nullptr;
    v22 = v21;
  }
  else
  {
    v22 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v23 = nullptr;
  else
    v23 = &this->IClient;
  v22[3].__vftable = (INetMessage_vtbl *)v23;
  chan->RegisterMessage(this: chan, a2: v22);
  v24 = (INetMessage *)calloc(count: 1u, size: 0x18u);
  if ( v24 != nullptr )
  {
    LOBYTE(v24[1].__vftable) = 1;
    v24[2].__vftable = nullptr;
    v24->__vftable = (INetMessage_vtbl *)&CLC_BaselineAck::`vftable';
  }
  else
  {
    v24 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v25 = nullptr;
  else
    v25 = &this->IClient;
  v24[3].__vftable = (INetMessage_vtbl *)v25;
  chan->RegisterMessage(this: chan, a2: v24);
  v26 = calloc(count: 1u, size: 0x50u);
  if ( v26 != nullptr )
  {
    v26[4] = 1;
    *((_DWORD *)v26 + 2) = 0;
    *(_DWORD *)v26 = &CLC_ListenEvents::`vftable';
    if ( v26 != (_BYTE *)-16 )
      memset(dst: v26 + 16, value: 0, count: 0x40u);
    v27 = (INetMessage *)v26;
  }
  else
  {
    v27 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v28 = nullptr;
  else
    v28 = &this->IClient;
  v27[3].__vftable = (INetMessage_vtbl *)v28;
  chan->RegisterMessage(this: chan, a2: v27);
  v29 = (INetMessage *)calloc(count: 1u, size: 0x220u);
  if ( v29 != nullptr )
  {
    LOBYTE(v29[1].__vftable) = 1;
    v29[2].__vftable = nullptr;
    v29->__vftable = (INetMessage_vtbl *)&CLC_RespondCvarValue::`vftable';
  }
  else
  {
    v29 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v30 = nullptr;
  else
    v30 = &this->IClient;
  v29[3].__vftable = (INetMessage_vtbl *)v30;
  chan->RegisterMessage(this: chan, a2: v29);
  v31 = (INetMessage *)calloc(count: 1u, size: 0x21Cu);
  if ( v31 != nullptr )
  {
    LOBYTE(v31[1].__vftable) = 1;
    v31[2].__vftable = nullptr;
    v31->__vftable = (INetMessage_vtbl *)&CLC_FileCRCCheck::`vftable';
  }
  else
  {
    v31 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v32 = nullptr;
  else
    v32 = &this->IClient;
  v31[3].__vftable = (INetMessage_vtbl *)v32;
  chan->RegisterMessage(this: chan, a2: v31);
  v33 = (INetMessage *)calloc(count: 1u, size: 0x24u);
  if ( v33 != nullptr )
  {
    LOBYTE(v33[1].__vftable) = 1;
    v33[2].__vftable = nullptr;
    v33->__vftable = (INetMessage_vtbl *)&CLC_SplitPlayerConnect::`vftable';
    v33[4].__vftable = nullptr;
    v33[5].__vftable = nullptr;
    v33[6].__vftable = nullptr;
    v33[7].__vftable = nullptr;
    v33[8].__vftable = nullptr;
  }
  else
  {
    v33 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v34 = nullptr;
  else
    v34 = &this->IClient;
  v33[3].__vftable = (INetMessage_vtbl *)v34;
  chan->RegisterMessage(this: chan, a2: v33);
  v35 = (INetMessage *)calloc(count: 1u, size: 0x14u);
  if ( v35 != nullptr )
  {
    LOBYTE(v35[1].__vftable) = 1;
    v35[2].__vftable = nullptr;
    v35->__vftable = (INetMessage_vtbl *)&CLC_LoadingProgress::`vftable';
  }
  else
  {
    v35 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v36 = nullptr;
  else
    v36 = &this->IClient;
  v35[3].__vftable = (INetMessage_vtbl *)v36;
  chan->RegisterMessage(this: chan, a2: v35);
  v37 = (CLC_CmdKeyValues *)calloc(count: 1u, size: 0x14u);
  if ( v37 != nullptr )
    v38 = CLC_CmdKeyValues::CLC_CmdKeyValues(this: v37, pKeyValues: nullptr);
  else
    v38 = nullptr;
  if ( this != (CBaseClient *)4 )
    v4 = &this->IClient;
  v38->m_pMessageHandler = (IClientMessageHandler *)v4;
  chan->RegisterMessage(this: chan, a2: v38);
}

//------------------------------------------------------------------------------
// Address: 0x101189F0
// Name: public: void CBaseClient::TraceNetworkData(class bf_write __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseClient::TraceNetworkData(CBaseClient *this, bf_write *msg, const char *fmt, ...)
{
  char buf[64]; // [esp+4h] [ebp-84h] BYREF
  Spike_t t; // [esp+44h] [ebp-44h] BYREF
  va_list params; // [esp+9Ch] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
  {
    V_vsnprintf(pDest: buf, maxLen: 64, pFormat: fmt, params);
    t.m_nBits = 0;
    t.m_szDesc[0] = 0;
    V_strncpy(pDest: t.m_szDesc, pSrc: buf, maxLen: 64);
    t.m_nBits = msg->m_iCurBit - this->m_Trace.m_nCurBit;
    CUtlVector<Spike_t,CUtlMemory<Spike_t,int>>::InsertBefore(
      this: &this->m_Trace.m_Records,
      elem: this->m_Trace.m_Records.m_Size,
      src: &t);
    this->m_Trace.m_nCurBit = msg->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118A70
// Name: public: void CBaseClient::TraceNetworkMsg(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseClient::TraceNetworkMsg(CBaseClient *this, int nBits, const char *fmt, ...)
{
  char buf[64]; // [esp+4h] [ebp-84h] BYREF
  Spike_t t; // [esp+44h] [ebp-44h] BYREF
  va_list params; // [esp+9Ch] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
  {
    V_vsnprintf(pDest: buf, maxLen: 64, pFormat: fmt, params);
    t.m_nBits = 0;
    t.m_szDesc[0] = 0;
    V_strncpy(pDest: t.m_szDesc, pSrc: buf, maxLen: 64);
    t.m_nBits = nBits;
    CUtlVector<Spike_t,CUtlMemory<Spike_t,int>>::InsertBefore(
      this: &this->m_Trace.m_Records,
      elem: this->m_Trace.m_Records.m_Size,
      src: &t);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118AE0
// Name: public: void CBaseClient::FillSignOnFullServerInfo(class NET_SignonState __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::FillSignOnFullServerInfo(CBaseClient *this, NET_SignonState *state)
{
  int v2; // esi
  CBaseClient *v3; // eax
  IClient *v4; // ecx
  const char *v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<char,CUtlMemory<char,int> > *p_m_PlayersNetworkIds; // esi
  char *m_pMemory; // ecx
  int v10; // eax
  char *v11; // eax
  char *v12; // edi
  const char *NewLevel; // eax
  const char *v14; // esi
  int v15; // eax
  int v16; // edi
  int v17; // eax
  char *v18; // ecx
  int v19; // eax
  char *v20; // esi

  if ( sv.m_bIsDedicatedForXbox )
  {
    v2 = 0;
    for ( state->m_numServerPlayers = sv.m_Clients.m_Size; v2 < sv.m_Clients.m_Size; ++v2 )
    {
      v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
        v4 = &v3->IClient;
      else
        v4 = nullptr;
      v5 = v4->GetNetworkIDString(this: v4);
      CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        this: &state->m_PlayersNetworkIds,
        elem: state->m_PlayersNetworkIds.m_Size,
        num: strlen(v5) + 1,
        pToInsert: v5);
    }
    m_Size = state->m_PlayersNetworkIds.m_Size;
    m_nAllocationCount = state->m_PlayersNetworkIds.m_Memory.m_nAllocationCount;
    p_m_PlayersNetworkIds = &state->m_PlayersNetworkIds;
    if ( m_Size + 2 > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &p_m_PlayersNetworkIds->m_Memory, num: m_Size - m_nAllocationCount + 2);
    state->m_PlayersNetworkIds.m_Size += 2;
    m_pMemory = p_m_PlayersNetworkIds->m_Memory.m_pMemory;
    v10 = state->m_PlayersNetworkIds.m_Size - m_Size - 2;
    state->m_PlayersNetworkIds.m_pElements = state->m_PlayersNetworkIds.m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 2], src: &m_pMemory[m_Size], count: v10);
    v11 = &p_m_PlayersNetworkIds->m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = 0;
    v12 = &p_m_PlayersNetworkIds->m_Memory.m_pMemory[m_Size + 1];
    if ( v12 != nullptr )
      *v12 = 0;
  }
  NewLevel = HostState_GetNewLevel();
  v14 = NewLevel;
  if ( NewLevel != nullptr )
  {
    v15 = _V_strlen(str: NewLevel);
    CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
      this: &state->m_Mapname,
      elem: state->m_Mapname.m_Size,
      num: v15,
      pToInsert: v14);
  }
  v16 = state->m_Mapname.m_Size;
  v17 = state->m_Mapname.m_Memory.m_nAllocationCount;
  if ( v16 + 1 > v17 )
    CUtlMemory<bool,int>::Grow(this: &state->m_Mapname.m_Memory, num: v16 - v17 + 1);
  ++state->m_Mapname.m_Size;
  v18 = state->m_Mapname.m_Memory.m_pMemory;
  v19 = state->m_Mapname.m_Size - v16 - 1;
  state->m_Mapname.m_pElements = v18;
  if ( v19 > 0 )
    _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: v19);
  v20 = &state->m_Mapname.m_Memory.m_pMemory[v16];
  if ( v20 != nullptr )
    *v20 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10118C20
// Name: public: virtual bool CBaseClient::SendNetMsg(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CBaseClient::SendNetMsg@<al>(
        CBaseClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        INetMessage *msg,
        int bForceReliable,
        int bVoice)
{
  int v9; // eax
  int v10; // eax
  int v11; // edi
  const char *v12; // eax
  int v14; // [esp-4h] [ebp-Ch]
  int nStartBit; // [esp+4h] [ebp-4h]
  char bret_3; // [esp+13h] [ebp+Bh]

  if ( this->m_nFilesDownloaded == 0 )
    return 1;
  v9 = ((int (__thiscall *)(INetMessage *, int))msg->IsReliable)(a1: msg, a2);
  if ( (_BYTE)v9 != 0 || (_BYTE)bForceReliable != 0 )
    v9 = 1;
  nStartBit = (*(int (__thiscall **)(int, int))(*(_DWORD *)this->m_nFilesDownloaded + 264))(
                a1: this->m_nFilesDownloaded,
                a2: v9);
  bret_3 = (*(int (__thiscall **)(int, INetMessage *, int, int))(*(_DWORD *)this->m_nFilesDownloaded + 164))(
             a1: this->m_nFilesDownloaded,
             a2: msg,
             a3: bForceReliable,
             a4: bVoice);
  if ( this->m_MegaSnapshotScratchBuffer[19999] != 0 )
  {
    v10 = ((int (__thiscall *)(INetMessage *, int))msg->IsReliable)(a1: msg, a2: v14);
    if ( (_BYTE)v10 != 0 || (_BYTE)bForceReliable != 0 )
      v10 = 1;
    v11 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)this->m_nFilesDownloaded + 264))(
            a1: this->m_nFilesDownloaded,
            a2: v10,
            a3)
        - nStartBit;
    v12 = msg->ToString(this: msg);
    CBaseClient::TraceNetworkMsg(this: (CBaseClient *)((char *)this - 4), nBits: v11, fmt: "NetMessage %s", v12);
  }
  return bret_3;
}

//------------------------------------------------------------------------------
// Address: 0x10118CF0
// Name: public: virtual void CBaseClient::Reconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::Reconnect(CBaseClient *this)
{
  char v2; // al
  CBaseClient_vtbl *v3; // edx
  void (__thiscall *WriteGameSounds)(CBaseClient *, bf_write *, int); // eax
  INetChannel *m_NetChannel; // eax
  NET_SignonState signon; // [esp+Ch] [ebp-48h] BYREF
  char v7; // [esp+53h] [ebp-1h]

  ConMsg(a1: "Forcing client reconnect (%i)\n", this->m_NetChannel);
  (*(void (__thiscall **)(int))(*(_DWORD *)this->m_nFilesDownloaded + 144))(a1: this->m_nFilesDownloaded);
  v2 = ((int (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this);
  v3 = this->IGameEventListener2::__vftable;
  v7 = v2;
  WriteGameSounds = v3[1].WriteGameSounds;
  this->m_NetChannel = (INetChannel *)2;
  if ( v7 != ((unsigned __int8 (__thiscall *)(CBaseClient *))WriteGameSounds)(a1: this)
    && (!this->IGameEventListener2::__vftable[1].SendServerInfo(this)
     || ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  m_NetChannel = this->m_NetChannel;
  signon.m_bReliable = true;
  signon.m_NetChannel = nullptr;
  signon.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  signon.m_nSignonState = (int)m_NetChannel;
  signon.m_nSpawnCount = -1;
  memset(&signon.m_numServerPlayers, 0, 44);
  CBaseClient::FillSignOnFullServerInfo(this: (CBaseClient *)((char *)this - 4), state: &signon);
  (*(void (__thiscall **)(int, NET_SignonState *, _DWORD, _DWORD))(*(_DWORD *)this->m_nFilesDownloaded + 164))(
    a1: this->m_nFilesDownloaded,
    a2: &signon,
    a3: 0,
    a4: 0);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signon.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signon.m_PlayersNetworkIds);
}

//------------------------------------------------------------------------------
// Address: 0x10118DF0
// Name: public: virtual void CBaseClient::Inactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::Inactivate(CBaseClient *this)
{
  void (__thiscall *v2)(char *); // edx
  char *v3; // ebx
  CFrameSnapshot *m_nSignonTick; // ecx
  char *v5; // ebx
  char v6; // al
  int v7; // edx
  int m_nFilesDownloaded; // ecx
  INetChannel *m_NetChannel; // ebx
  int v10; // eax
  NET_SignonState signon; // [esp+Ch] [ebp-4Ch] BYREF
  CBaseClient *v12; // [esp+50h] [ebp-8h]
  char v13; // [esp+57h] [ebp-1h]

  v2 = *(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 72);
  v3 = (char *)this - 4;
  v12 = (CBaseClient *)((char *)this - 4);
  v2(a1: (char *)this - 4);
  this->m_nSignonState = -1;
  this->m_nStringTableAckTick = 0;
  this->m_nDeltaTick = 0;
  m_nSignonTick = (CFrameSnapshot *)this->m_nSignonTick;
  if ( m_nSignonTick != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_nSignonTick);
    this->m_nSignonTick = 0;
  }
  v5 = v3 + 4;
  this->m_nBaselineUsed = -1;
  v6 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 124))(a1: v5);
  v7 = *(_DWORD *)v5;
  v13 = v6;
  v12->m_nSignonState = 7;
  if ( v13 != (*(unsigned __int8 (__thiscall **)(char *))(v7 + 124))(a1: v5)
    && ((*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)v5 + 136))(a1: v5) == 0
     || (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)v5 + 156))(a1: v5) != 0) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  m_nFilesDownloaded = this->m_nFilesDownloaded;
  if ( m_nFilesDownloaded != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)m_nFilesDownloaded + 144))(a1: m_nFilesDownloaded);
    if ( NET_IsMultiplayer()
      && ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) == 0 )
    {
      m_NetChannel = this->m_NetChannel;
      v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_bConVarsChanged + 60))(a1: *(_DWORD *)&this->m_bConVarsChanged);
      signon.m_bReliable = true;
      signon.m_NetChannel = nullptr;
      signon.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
      signon.m_nSignonState = (int)m_NetChannel;
      signon.m_nSpawnCount = v10;
      memset(&signon.m_numServerPlayers, 0, 44);
      CBaseClient::FillSignOnFullServerInfo(this: v12, state: &signon);
      ((void (__thiscall *)(CBaseClient *, NET_SignonState *, _DWORD, _DWORD))this->IGameEventListener2::__vftable[1].FillUserInfo)(
        a1: this,
        a2: &signon,
        a3: 0,
        a4: 0);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)this->m_nFilesDownloaded + 192))(
        a1: this->m_nFilesDownloaded,
        a2: 0);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signon.m_Mapname);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signon.m_PlayersNetworkIds);
    }
  }
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10118F70
// Name: public: virtual void CBaseClient::SpawnPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SpawnPlayer(CBaseClient *this)
{
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // edx
  bool (__thiscall *IsConnected)(IClient *); // edx
  char v4; // al
  CBaseServer *m_Server; // ecx
  CBaseServer_vtbl *v6; // edx
  int v7; // eax
  NET_SignonState signonState; // [esp+Ch] [ebp-68h] BYREF
  NET_Tick tick; // [esp+50h] [ebp-24h] BYREF
  int m_nSignonState; // [esp+6Ch] [ebp-8h]
  char v11; // [esp+73h] [ebp-1h]

  _COM_TimestampedLog(a1: "CBaseClient::SpawnPlayer");
  if ( !this->IsFakeClient(this: &this->IClient) )
  {
    this->FreeBaselines(this);
    this->m_pBaseline = CFrameSnapshotManager::CreateEmptySnapshot(
                          this: framesnapshotmanager,
                          tickcount: 0,
                          maxEntities: 2048);
  }
  tick.m_nTick = this->m_Server->GetTick(this: this->m_Server);
  SendNetMsg = this->SendNetMsg;
  tick.m_flHostFrameTime = host_frametime_unbounded;
  tick.m_NetChannel = nullptr;
  tick.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  tick.m_bReliable = false;
  tick.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
  SendNetMsg(this: &this->IClient, a2: &tick, a3: true, a4: false);
  v11 = this->IsConnected(this: &this->IClient);
  IsConnected = this->IsConnected;
  this->m_nSignonState = 5;
  v4 = IsConnected(this: &this->IClient);
  if ( v11 != v4 && (!this->IsFakeClient(this: &this->IClient) || this->IsSplitScreenUser(this: &this->IClient)) )
    CGameServer::UpdateHibernationState(this: &sv);
  m_Server = this->m_Server;
  v6 = m_Server->__vftable;
  m_nSignonState = this->m_nSignonState;
  v7 = v6->GetSpawnCount(this: m_Server);
  signonState.m_nSignonState = m_nSignonState;
  signonState.m_bReliable = true;
  signonState.m_NetChannel = nullptr;
  signonState.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  signonState.m_nSpawnCount = v7;
  memset(&signonState.m_numServerPlayers, 0, 44);
  CBaseClient::FillSignOnFullServerInfo(this, state: &signonState);
  this->SendNetMsg(this: &this->IClient, a2: &signonState, a3: false, a4: false);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signonState.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signonState.m_PlayersNetworkIds);
}

//------------------------------------------------------------------------------
// Address: 0x101190E0
// Name: public: virtual bool CBaseClient::SendSignonData(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::SendSignonData(CBaseClient *this)
{
  IEngineVGuiInternal *v2; // eax
  CBaseServer *m_Server; // eax
  int m_nSignonState; // edi
  int v6; // eax
  bool v7; // bl
  NET_SignonState signonState; // [esp+8h] [ebp-44h] BYREF

  _COM_TimestampedLog(a1: " CBaseClient::SendSignonData");
  v2 = EngineVGui();
  v2->UpdateProgressBar(this: v2, a2: PROGRESS_SENDSIGNONDATA, a3: false);
  m_Server = this->m_Server;
  if ( m_Server->m_Signon.m_bOverflow )
  {
    Host_Error(error: "Signon buffer overflowed %i bytes!!!\n", (m_Server->m_Signon.m_iCurBit + 7) >> 3);
    return false;
  }
  else
  {
    this->m_NetChannel->SendData(this: this->m_NetChannel, a2: &m_Server->m_Signon, a3: true);
    S_PreventSound(bSetting: false);
    CBaseClient::SetSignonState(this, nState: 4);
    m_nSignonState = this->m_nSignonState;
    v6 = this->m_Server->GetSpawnCount(this: this->m_Server);
    signonState.m_bReliable = true;
    signonState.m_NetChannel = nullptr;
    signonState.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
    signonState.m_nSignonState = m_nSignonState;
    signonState.m_nSpawnCount = v6;
    memset(&signonState.m_numServerPlayers, 0, 44);
    CBaseClient::FillSignOnFullServerInfo(this, state: &signonState);
    v7 = this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &signonState, a3: false, a4: false);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signonState.m_Mapname);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signonState.m_PlayersNetworkIds);
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101191F0
// Name: public: virtual bool CBaseClient::SendServerInfo(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::SendServerInfo(CBaseClient *this)
{
  IClient *v2; // edi
  const char *v3; // eax
  void *v4; // eax
  int (*GetSpawnCount)(void); // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  CBaseServer *v9; // ecx
  KeyValues *v10; // eax
  IMatchEventsSubscription *v11; // eax
  int m_nTickCount; // edx
  const char *v13; // eax
  bool (__thiscall *IsConnected)(IClient *); // eax
  bool v15; // al
  IClient_vtbl *v16; // edx
  bool (__thiscall *v17)(IClient *); // eax
  char v18; // al
  int v19; // eax
  const char *v21; // [esp-18h] [ebp-1540h]
  int v22; // [esp-14h] [ebp-153Ch]
  int v23; // [esp-10h] [ebp-1538h]
  int v24; // [esp-Ch] [ebp-1534h]
  int v25; // [esp-8h] [ebp-1530h]
  int m_nSignonState; // [esp-4h] [ebp-152Ch]
  int v27; // [esp-4h] [ebp-152Ch]
  int v28; // [esp-4h] [ebp-152Ch]
  char pDest[2048]; // [esp+Ch] [ebp-151Ch] BYREF
  SVC_Print v30; // [esp+80Ch] [ebp-D1Ch] BYREF
  SVC_ServerInfo v31; // [esp+1020h] [ebp-508h] BYREF
  NET_Tick v32; // [esp+1478h] [ebp-B0h] BYREF
  NET_SetConVar v33; // [esp+1494h] [ebp-94h] BYREF
  NET_SignonState state; // [esp+14B8h] [ebp-70h] BYREF
  bf_write buffer; // [esp+14FCh] [ebp-2Ch] BYREF
  int nBots; // [esp+1514h] [ebp-14h] BYREF
  int nMaxHumanSlots; // [esp+1518h] [ebp-10h] BYREF
  int nHumans; // [esp+151Ch] [ebp-Ch] BYREF
  CBaseServer *m_Server; // [esp+1520h] [ebp-8h]
  char v40; // [esp+1527h] [ebp-1h]

  v2 = &this->IClient;
  m_nSignonState = this->m_nSignonState;
  v3 = this->GetClientName(this: &this->IClient);
  _COM_TimestampedLog(a1: " CBaseClient::SendServerInfo: %s  :  %d", v3, m_nSignonState);
  v4 = (void *)_MemAllocScratch(a1: 96000);
  bf_write::bf_write(this: &buffer, pDebugName: "SV_SendServerinfo->msg", pData: v4, nBytes: 96000, nBits: -1);
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0
    || this->m_Server->IsMultiplayer(this: this->m_Server) )
  {
    CBaseServer::GetMasterServerPlayerCounts(this: &sv, &nHumans, &nMaxHumanSlots, &nBots);
    GetSpawnCount = (int (*)(void))this->m_Server->GetSpawnCount;
    m_Server = this->m_Server;
    v27 = GetSpawnCount();
    v6 = build_number();
    v7 = ((int (__thiscall *)(CBaseServer *, int, int, int, int, int))m_Server->GetMapName)(
           a1: m_Server,
           a2: nHumans,
           a3: nBots,
           a4: nMaxHumanSlots,
           a5: v6,
           a6: v27);
    v8 = (const char *)((int (__thiscall *)(IServerGameDLL *, int))serverGameDLL->GetGameDescription)(
                         a1: serverGameDLL,
                         a2: v7);
    V_snprintf(
      pDest,
      maxLen: 2048,
      pFormat: "\n%s\nMap: %s\nPlayers: %i (%i bots) / %i humans\nBuild: %d\nServer Number: %i\n\n",
      v8,
      v21,
      v22,
      v23,
      v24,
      v25,
      v28);
    v30.m_NetChannel = nullptr;
    v30.__vftable = (SVC_Print_vtbl *)&SVC_Print::`vftable';
    v30.m_bReliable = false;
    v30.m_szText = pDest;
    SVC_Print::WriteToBuffer(this: &v30, &buffer);
  }
  v31.m_nPlayerSlot = this->m_nClientSlot;
  v9 = this->m_Server;
  v31.m_bReliable = true;
  v31.m_NetChannel = nullptr;
  v31.__vftable = (SVC_ServerInfo_vtbl *)&SVC_ServerInfo::`vftable';
  v9->FillServerInfo(this: v9, a2: &v31);
  SVC_ServerInfo::WriteToBuffer(this: &v31, &buffer);
  if ( g_pMatchFramework != nullptr && CBaseServer::GetReservationCookie(this: &sv) == 0 )
  {
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      m_Server = (CBaseServer *)KeyValues::KeyValues(this: v10, setName: "OnEngineListenServerStarted");
    else
      m_Server = nullptr;
    v11 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v11->BroadcastEvent(this: v11, a2: (KeyValues *)m_Server);
  }
  m_nTickCount = this->m_Server->m_nTickCount;
  this->m_nSignonTick = m_nTickCount;
  v32.m_NetChannel = nullptr;
  v32.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  v32.m_bReliable = false;
  v32.m_nTick = m_nTickCount;
  v32.m_flHostFrameTime = 0.0;
  v32.m_flHostFrameTimeStdDeviation = 0.0;
  NET_Tick::WriteToBuffer(this: &v32, &buffer);
  if ( !this->m_NetChannel->IsLoopback(this: this->m_NetChannel) )
  {
    v33.m_bReliable = true;
    v33.m_NetChannel = nullptr;
    v33.__vftable = (NET_SetConVar_vtbl *)&NET_SetConVar::`vftable';
    memset(&v33.m_ConVars, 0, sizeof(v33.m_ConVars));
    Host_BuildConVarUpdateMessage(rCvarList: &v33.m_ConVars, flags: 0x2000, nonDefault: true);
    NET_SetConVar::WriteToBuffer(this: &v33, &buffer);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v33.m_ConVars);
  }
  v13 = this->m_Server->GetMapName(this: this->m_Server);
  CNetworkStringTableContainer::WriteBaselines(this: this->m_Server->m_StringTables, pchMapName: v13, buf: &buffer);
  IsConnected = v2->IsConnected;
  this->m_bSendServerInfo = false;
  v15 = IsConnected(this: v2);
  v16 = v2->__vftable;
  v40 = v15;
  v17 = v16->IsConnected;
  this->m_nSignonState = 3;
  v18 = v17(this: v2);
  if ( v40 != v18 && (!v2->IsFakeClient(this: v2) || v2->IsSplitScreenUser(this: v2)) )
    CGameServer::UpdateHibernationState(this: &sv);
  nHumans = this->m_nSignonState;
  v19 = this->m_Server->GetSpawnCount(this: this->m_Server);
  state.m_nSignonState = nHumans;
  state.m_bReliable = true;
  state.m_NetChannel = nullptr;
  state.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  state.m_nSpawnCount = v19;
  memset(&state.m_numServerPlayers, 0, 44);
  CBaseClient::FillSignOnFullServerInfo(this, &state);
  NET_SignonState::WriteToBuffer(this: &state, &buffer);
  if ( this->m_NetChannel->SendData(this: this->m_NetChannel, a2: &buffer, a3: true) )
  {
    _COM_TimestampedLog(a1: " CBaseClient::SendServerInfo(finished)");
    _MemFreeScratch();
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_Mapname);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_PlayersNetworkIds);
    return 1;
  }
  else
  {
    _MemFreeScratch();
    v2->Disconnect(this: v2, a2: "Server info data overflow");
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_Mapname);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_PlayersNetworkIds);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101195B0
// Name: private: void CBaseClient::EndTrace(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
void __thiscall CBaseClient::EndTrace(CBaseClient *this, bf_write *msg)
{
  int m_nMinWarningBytes; // eax
  int v4; // ebx
  CNetChan *m_NetChannel; // edi
  int m_iCurBit; // ebx
  int v7; // edi
  INetChannel *v8; // eax
  int v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // edi
  int v13; // ebx
  Spike_t *m_pMemory; // eax
  bool v15; // sf
  int v16; // [esp+10h] [ebp-58h]
  const char *v17; // [esp+14h] [ebp-54h]
  int v18; // [esp+18h] [ebp-50h]
  double v19; // [esp+1Ch] [ebp-4Ch]
  CUtlBuffer v20; // [esp+2Ch] [ebp-3Ch] BYREF
  __int64 logData_4; // [esp+60h] [ebp-8h] OVERLAPPED

  m_nMinWarningBytes = this->m_Trace.m_nMinWarningBytes;
  if ( m_nMinWarningBytes != 0 )
  {
    v4 = this->m_Trace.m_nCurBit - this->m_Trace.m_nStartBit;
    HIDWORD(logData_4) = v4;
    if ( v4 >= 8 * m_nMinWarningBytes )
    {
      m_NetChannel = (CNetChan *)this->m_NetChannel;
      if ( m_NetChannel != nullptr )
      {
        m_iCurBit = CNetChan::GetBuffer(this: m_NetChannel, eBufType: BUF_RELIABLE)->m_iCurBit;
        LODWORD(logData_4) = CNetChan::GetBuffer(this: m_NetChannel, eBufType: BUF_UNRELIABLE)->m_iCurBit;
        v7 = CNetChan::GetBuffer(this: m_NetChannel, eBufType: BUF_VOICE)->m_iCurBit;
        CBaseClient::TraceNetworkMsg(this, nBits: m_iCurBit, fmt: "[Reliable payload]");
        CBaseClient::TraceNetworkMsg(this, nBits: logData_4, fmt: "[Unreliable payload]");
        CBaseClient::TraceNetworkMsg(this, nBits: v7, fmt: "[Voice payload]");
        v4 = HIDWORD(logData_4);
      }
      CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&v20.m_Memory.m_nAllocationCount, growSize: 0, initSize: 0, nFlags: 1);
      v8 = this->GetNetChannel(this: &this->IClient);
      v9 = ((int (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))v8->GetAddress)(
             a1: v8,
             a2: v4,
             a3: COERCE_UNSIGNED_INT64((double)SHIDWORD(logData_4) * 0.125),
             a4: HIDWORD(COERCE_UNSIGNED_INT64((double)SHIDWORD(logData_4) * 0.125)));
      v10 = ((int (__thiscall *)(IClient *, int))this->GetPlayerSlot)(a1: &this->IClient, a2: v9);
      v11 = (const char *)((int (__thiscall *)(IClient *, int))this->GetClientName)(a1: &this->IClient, a2: v10);
      CUtlBuffer::Printf(
        this: (CUtlBuffer *)&v20.m_Memory.m_nAllocationCount,
        pFmt: "%f/%d Player [%s][%d][adr:%s] was sent a datagram %d bits (%8.3f bytes)\n",
        realtime,
        host_tickcount,
        v11,
        v16,
        v17,
        v18,
        v19);
      v12 = 0;
      if ( this->m_Trace.m_Records.m_Size > 0 )
      {
        v13 = 0;
        do
        {
          m_pMemory = this->m_Trace.m_Records.m_Memory.m_pMemory;
          LODWORD(logData_4) = m_pMemory[v13].m_nBits;
          CUtlBuffer::Printf(
            this: (CUtlBuffer *)&v20.m_Memory.m_nAllocationCount,
            pFmt: "%64.64s : %8d bits (%8.3f bytes)\n",
            m_pMemory[v13].m_szDesc,
            (_DWORD)logData_4,
            (double)(int)logData_4 * 0.125);
          if ( *(int *)&v20.m_Error > 10240 && v12 != this->m_Trace.m_Records.m_Size - 1 )
          {
            COM_LogString(pchFile: "netspike.txt", pchString: (const char *)v20.m_Memory.m_nAllocationCount);
            memset(&v20.m_Put, 0, 9);
            v20.m_GetOverflowFunc = nullptr;
            v20.m_nOffset = -1;
            CUtlBuffer::AddNullTermination(this: (CUtlBuffer *)&v20.m_Memory.m_nAllocationCount, nPut: 0);
          }
          ++v12;
          ++v13;
        }
        while ( v12 < this->m_Trace.m_Records.m_Size );
      }
      COM_LogString(pchFile: "netspike.txt", pchString: (const char *)v20.m_Memory.m_nAllocationCount);
      v15 = v20.m_Get < 0;
      this->m_Trace.m_Records.m_Size = 0;
      if ( !v15 && v20.m_Memory.m_nAllocationCount != 0 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v20.m_Memory.m_nAllocationCount);
    }
    else
    {
      this->m_Trace.m_Records.m_Size = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101197A0
// Name: public: virtual void CBaseClient::SendSnapshot(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseClient::SendSnapshot(CBaseClient *this@<ecx>, int a2@<ebx>, CClientFrame *pFrame)
{
  int v4; // edi
  unsigned int *m_SnapshotScratchBuffer; // ecx
  int m_nValue; // eax
  int v7; // ebx
  const char *v8; // eax
  int tick_count; // ecx
  int m_iCurBit; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  CFrameSnapshot *m_pSnapshot; // edi
  CFrameSnapshot *m_pObj; // ecx
  int v17; // eax
  INetChannel *m_NetChannel; // ecx
  bool v19; // al
  int v20; // [esp-4h] [ebp-BCh]
  char reason[128]; // [esp+4h] [ebp-B4h] BYREF
  NET_Tick tickmsg; // [esp+84h] [ebp-34h] BYREF
  bf_write msg; // [esp+A0h] [ebp-18h] BYREF

  if ( this->m_pLastSnapshot.m_pObj == pFrame->m_pSnapshot )
  {
    this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
    return;
  }
  v4 = 0;
  if ( this->m_nForceWaitForTick > 0 )
  {
    this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
    return;
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SendSnapshot",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  if ( net_megasnapshot.m_pParent == nullptr
    || (m_SnapshotScratchBuffer = this->m_MegaSnapshotScratchBuffer, net_megasnapshot.m_pParent->m_Value.m_nValue == 0) )
  {
    m_SnapshotScratchBuffer = this->m_SnapshotScratchBuffer;
  }
  if ( net_megasnapshot.m_pParent != nullptr )
    m_nValue = net_megasnapshot.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bf_write::bf_write(
    this: &msg,
    pDebugName: "CBaseClient::SendSnapshot",
    pData: m_SnapshotScratchBuffer,
    nBytes: m_nValue != 0 ? 80000 : 40000,
    nBits: -1);
  v7 = ((int (__thiscall *)(CBaseClient *, int, int))this->GetDeltaFrame)(a1: this, a2: this->m_nDeltaTick, a3: a2);
  if ( v7 == 0 )
  {
    v8 = (const char *)((int (__thiscall *)(IClient *, int))this->GetClientName)(
                         a1: &this->IClient,
                         a2: this->m_nDeltaTick);
    V_snprintf(pDest: reason, maxLen: 128, pFormat: "%s can't find frame from tick %d", v8, v20);
    CBaseClient::OnRequestFullUpdate(this, pchReason: reason);
  }
  tick_count = pFrame->tick_count;
  tickmsg.m_flHostFrameTime = host_frametime_unbounded;
  tickmsg.m_NetChannel = nullptr;
  tickmsg.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  tickmsg.m_bReliable = false;
  tickmsg.m_nTick = tick_count;
  tickmsg.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
  {
    m_iCurBit = msg.m_iCurBit;
    this->m_Trace.m_nStartBit = msg.m_iCurBit;
    this->m_Trace.m_nCurBit = m_iCurBit;
  }
  NET_Tick::WriteToBuffer(this: &tickmsg, buffer: &msg);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
    CBaseClient::TraceNetworkData(this, &msg, fmt: "NET_Tick");
  if ( g_pLocalNetworkBackdoor == nullptr )
  {
    v11 = this->GetMaxAckTickCount(this: &this->IClient);
    CNetworkStringTableContainer::WriteUpdateMessage(
      this: this->m_Server->m_StringTables,
      client: this,
      tick_ack: v11,
      buf: &msg);
  }
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
    v4 = msg.m_iCurBit;
  ((void (__stdcall *)(CBaseClient *, CClientFrame *, int, bf_write *))this->m_Server->WriteDeltaEntities)(
    a1: this,
    a2: pFrame,
    a3: v7,
    a4: &msg);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
    CBaseClient::TraceNetworkMsg(this, nBits: msg.m_iCurBit - v4, fmt: "Total Delta");
  if ( this->m_Server->IsMultiplayer(this: this->m_Server) )
  {
    if ( sv_multiplayer_maxtempentities.m_pParent != nullptr )
      v12 = sv_multiplayer_maxtempentities.m_pParent->m_Value.m_nValue;
    else
      v12 = 0;
  }
  else
  {
    v12 = 255;
  }
  this->m_Server->WriteTempEntities(
    this: this->m_Server,
    a2: this,
    a3: pFrame->m_pSnapshot,
    a4: this->m_pLastSnapshot.m_pObj,
    a5: &msg,
    a6: v12);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
    CBaseClient::TraceNetworkData(this, &msg, fmt: "Temp Entities");
  if ( this->m_Server->IsMultiplayer(this: this->m_Server) )
  {
    if ( sv_multiplayer_maxsounds.m_pParent != nullptr )
      v13 = sv_multiplayer_maxsounds.m_pParent->m_Value.m_nValue;
    else
      v13 = 0;
  }
  else
  {
    v13 = 255;
  }
  this->WriteGameSounds(this, a2: &msg, a3: v13);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
  {
    v14 = "yes";
    if ( v7 == 0 )
      v14 = "no";
    CBaseClient::TraceNetworkMsg(this, nBits: 0, fmt: "Finished [delta %s]", v14);
    CBaseClient::EndTrace(this, &msg);
  }
  if ( !msg.m_bOverflow )
    goto LABEL_43;
  if ( v7 != 0 )
  {
    ConMsg(a1: "WARNING: msg overflowed for %s\n", this->m_Name);
    bf_write::Reset(this: &msg);
LABEL_43:
    m_pSnapshot = pFrame->m_pSnapshot;
    if ( m_pSnapshot != this->m_pLastSnapshot.m_pObj )
    {
      if ( m_pSnapshot != nullptr )
        CFrameSnapshot::AddReference(this: m_pSnapshot);
      m_pObj = this->m_pLastSnapshot.m_pObj;
      if ( m_pObj != nullptr )
        CFrameSnapshot::ReleaseReference(this: m_pObj);
      this->m_pLastSnapshot.m_pObj = m_pSnapshot;
    }
    if ( !this->m_bFakePlayer || this->m_NetChannel != nullptr )
    {
      m_NetChannel = this->m_NetChannel;
      if ( v7 != 0 )
      {
        v19 = m_NetChannel->SendDatagram(this: m_NetChannel, a2: &msg) > 0;
      }
      else if ( m_NetChannel->SendData(this: m_NetChannel, a2: &msg, a3: true)
             && this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false) )
      {
        v19 = true;
        this->m_nForceWaitForTick = pFrame->tick_count;
      }
      else
      {
        v19 = false;
        this->m_nForceWaitForTick = pFrame->tick_count;
      }
      if ( !v19 )
        this->Disconnect(this: &this->IClient, a2: "ERROR! Couldn't send snapshot.");
    }
    else
    {
      v17 = pFrame->tick_count;
      this->m_nDeltaTick = v17;
      this->m_nStringTableAckTick = v17;
    }
    goto LABEL_60;
  }
  this->Disconnect(this: &this->IClient, a2: "ERROR! Reliable snaphsot overflow.");
LABEL_60:
  tickmsg.__vftable = (NET_Tick_vtbl *)&INetMessage::`vftable';
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10119B80
// Name: public: CCopyableUtlVector<class IClient __near *>::CCopyableUtlVector<class IClient __near *>(class CCopyableUtlVector<class IClient __near *> const __near &)
// Source: json
//------------------------------------------------------------------------------
CCopyableUtlVector<IClient *> *__thiscall CCopyableUtlVector<IClient *>::CCopyableUtlVector<IClient *>(
        CCopyableUtlVector<IClient *> *this,
        const CCopyableUtlVector<IClient *> *vec)
{
  int m_Size; // edi
  int i; // eax
  IClient **veca; // [esp+14h] [ebp+8h]

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  this->__vftable = (CCopyableUtlVector<IClient *>_vtbl *)&CCopyableUtlVector<IClient *>::`vftable';
  m_Size = vec->m_Size;
  veca = vec->m_Memory.m_pMemory;
  this->m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->CUtlVector<IClient *,CUtlMemory<IClient *,int> >,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    this->m_Memory.m_pMemory[i] = veca[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10119FD0
// Name: void HostValidateSessionImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostValidateSessionImpl()
{
  int v0; // esi
  SessionClient_t *m_pMemory; // edi
  CBaseClient *v2; // ebx
  IClient *v3; // ebx
  const char *v4; // esi
  int v5; // eax
  int v6; // edx
  int m_nAllocationCount; // eax
  SessionClient_t *v8; // esi
  int m_Size; // edi
  IClient **v10; // ecx
  int v11; // eax
  IClient **v12; // edi
  int v13; // eax
  SessionClient_t *v14; // eax
  bool v15; // zf
  int v16; // eax
  int *p_m_Size; // edi
  int v18; // ebx
  int i; // esi
  SessionClient_t sc; // [esp+0h] [ebp-4Ch] BYREF
  CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int> > arrSessions; // [esp+28h] [ebp-24h] BYREF
  unsigned __int64 uid; // [esp+3Ch] [ebp-10h] BYREF
  SessionClient_t *v23; // [esp+44h] [ebp-8h]
  int j; // [esp+48h] [ebp-4h]

  if ( sv.m_bIsDedicatedForXbox )
  {
    _Msg(a1: "[SESSION] Validating Session Information...\n");
    v0 = 0;
    m_pMemory = nullptr;
    memset(&arrSessions, 0, sizeof(arrSessions));
    j = 0;
    if ( sv.m_Clients.m_Size <= 0 )
      goto LABEL_21;
    do
    {
      v2 = sv.m_Clients.m_Memory.m_pMemory[v0];
      if ( v2 != nullptr )
      {
        v3 = &v2->IClient;
        if ( v3 != nullptr
          && v3->IsConnected(this: v3)
          && !v3->IsFakeClient(this: v3)
          && !v3->IsSplitScreenUser(this: v3) )
        {
          v4 = v3->GetUserSetting(this: v3, a2: "cl_session");
          uid = 0;
          if ( sscanf(string: v4, format: "$%llx", &uid) != 1 )
            _Warning(a1: "couldn't parse cl_session %s\n", v4);
          sc.xSession = uid;
          memset(
            &sc.arrClients.CUtlVector<IClient *,CUtlMemory<IClient *,int> >,
            0,
            sizeof(sc.arrClients.CUtlVector<IClient *,CUtlMemory<IClient *,int> >));
          sc.arrClients.__vftable = (CCopyableUtlVector<IClient *>_vtbl *)&CCopyableUtlVector<IClient *>::`vftable';
          sc.numPlayers = 0;
          v5 = CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::Find(this: &arrSessions, src: &sc);
          if ( v5 == -1 )
          {
            v5 = CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::InsertBefore(
                   this: &arrSessions,
                   elem: arrSessions.m_Size,
                   src: &sc);
            m_pMemory = arrSessions.m_Memory.m_pMemory;
          }
          v6 = v5;
          m_nAllocationCount = m_pMemory[v5].arrClients.m_Memory.m_nAllocationCount;
          v8 = &m_pMemory[v6];
          m_Size = v8->arrClients.m_Size;
          v23 = v8;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&v8->arrClients.CUtlVector<IClient *,CUtlMemory<IClient *,int> >,
              num: m_Size - m_nAllocationCount + 1);
          ++v8->arrClients.m_Size;
          v10 = v8->arrClients.m_Memory.m_pMemory;
          v11 = v8->arrClients.m_Size - m_Size - 1;
          v8->arrClients.m_pElements = v10;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 4 * v11);
          v12 = &v8->arrClients.m_Memory.m_pMemory[m_Size];
          if ( v12 != nullptr )
            *v12 = v3;
          v13 = v3->GetNumPlayers(this: v3);
          v23->numPlayers += v13;
          sc.arrClients.__vftable = (CCopyableUtlVector<IClient *>_vtbl *)&CCopyableUtlVector<IClient *>::`vftable';
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&sc.arrClients.CUtlVector<IClient *,CUtlMemory<IClient *,int> >);
          m_pMemory = arrSessions.m_Memory.m_pMemory;
          v0 = j;
        }
      }
      j = ++v0;
    }
    while ( v0 < sv.m_Clients.m_Size );
    if ( arrSessions.m_Size == 0 )
    {
LABEL_21:
      _Msg(a1: "[SESSION] No clients.\n");
      CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::RemoveAll(this: &arrSessions);
      if ( arrSessions.m_Memory.m_nGrowSize < 0 )
        return;
      v14 = arrSessions.m_Memory.m_pMemory;
      v15 = arrSessions.m_Memory.m_pMemory == nullptr;
      goto LABEL_32;
    }
    CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::Sort(
      this: &arrSessions,
      pfnCompare: (int (__cdecl *)(const void *, const void *))SessionClient_t::Less);
    v16 = 0;
    if ( m_pMemory->xSession != 0 )
    {
      _Msg(
        a1: "[SESSION] Updating reservation cookie: %llx, keeping %d players.\n",
        m_pMemory->xSession,
        m_pMemory->numPlayers);
      CBaseServer::SetReservationCookie(
        this: &sv,
        uiCookie: m_pMemory->xSession,
        pchReasonFormat: "HostValidateSession");
      v16 = 1;
    }
    if ( v16 < arrSessions.m_Size )
    {
      p_m_Size = &m_pMemory[v16].arrClients.m_Size;
      v18 = arrSessions.m_Size - v16;
      do
      {
        for ( i = 0; i < *p_m_Size; ++i )
          (*(void (__cdecl **)(_DWORD, const char *))(**(_DWORD **)(*(p_m_Size - 3) + 4 * i) + 52))(
            a1: *(_DWORD *)(*(p_m_Size - 3) + 4 * i),
            a2: "Session migrated");
        p_m_Size += 10;
        --v18;
      }
      while ( v18 != 0 );
    }
    CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::RemoveAll(this: &arrSessions);
    if ( arrSessions.m_Memory.m_nGrowSize >= 0 )
    {
      v14 = arrSessions.m_Memory.m_pMemory;
      v15 = arrSessions.m_Memory.m_pMemory == nullptr;
LABEL_32:
      if ( !v15 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E4FD0
// Name: public: virtual enum CrossPlayPlatform_t CBaseClient::GetClientPlatform(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall CBaseClient::GetClientPlatform(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1005E370
// Name: public: virtual unsigned int CLC_VoiceData::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLC_VoiceData::GetSize(CSosOperatorConvar *this)
{
  return 88;
}

//------------------------------------------------------------------------------
// Address: 0x100620A0
// Name: public: virtual int CLC_VoiceData::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLC_VoiceData::GetType(SVC_ClassInfo *this)
{
  return 10;
}

//------------------------------------------------------------------------------
// Address: 0x10116380
// Name: public: virtual int CBaseClient::GetRate(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetRate(CBaseClient *this)
{
  if ( this->m_nFilesDownloaded != 0 )
    return (*(int (__thiscall **)(int))(*(_DWORD *)this->m_nFilesDownloaded + 20))(a1: this->m_nFilesDownloaded);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101163A0
// Name: public: virtual char const __near * CBaseClient::GetUserSetting(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseClient::GetUserSetting(CBaseClient *this, const char *cvar)
{
  KeyValues *v3; // ecx
  const char *String; // ebx

  v3 = *(KeyValues **)&this->m_FriendsName[28];
  if ( v3 == nullptr || cvar == nullptr || *cvar == 0 )
    return defaultValue;
  String = KeyValues::GetString(this: v3, keyName: cvar, defaultValue: defaultValue);
  if ( *String == 0 )
  {
    if ( LOBYTE(this->m_nDebugID) != 0 )
      return this->m_SplitScreenUsers[1]->GetUserSetting(this: &this->m_SplitScreenUsers[1]->IClient, a2: cvar);
    if ( KeyValues::GetDataType(this: *(KeyValues **)&this->m_FriendsName[28], keyName: cvar) == TYPE_NONE )
      DevMsg(a1: "GetUserSetting: cvar '%s' unknown.\n", cvar);
  }
  return String;
}

//------------------------------------------------------------------------------
// Address: 0x10116420
// Name: public: virtual void CBaseClient::SetUserCVar(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetUserCVar(CBaseClient *this, const char *cvar, const char *value)
{
  if ( cvar != nullptr && value != nullptr )
    KeyValues::SetString(this: this->m_ConVars, keyName: cvar, value);
}

//------------------------------------------------------------------------------
// Address: 0x10116480
// Name: public: void CBaseClient::SetSignonState(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetSignonState(CBaseClient *this, int nState)
{
  bool v3; // al
  IClient_vtbl *v4; // edx

  v3 = this->IsConnected(this: &this->IClient);
  v4 = this->IClient::INetChannelHandler::__vftable;
  this->m_nSignonState = nState;
  if ( v3 != v4->IsConnected(this: &this->IClient)
    && (!this->IsFakeClient(this: &this->IClient) || this->IsSplitScreenUser(this: &this->IClient)) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116680
// Name: public: virtual void CBaseClient::ActivatePlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::ActivatePlayer(CBaseClient *this)
{
  bool v2; // bl
  bool (__thiscall *IsConnected)(IClient *); // eax
  CMapReslistGenerator *v4; // eax

  _COM_TimestampedLog(a1: "CBaseClient::ActivatePlayer");
  this->m_Server->UserInfoChanged(this: this->m_Server, a2: this->m_nClientSlot);
  v2 = this->IsConnected(this: &this->IClient);
  IsConnected = this->IsConnected;
  this->m_nSignonState = 6;
  if ( v2 != IsConnected(this: &this->IClient)
    && (!this->IsFakeClient(this: &this->IClient) || this->IsSplitScreenUser(this: &this->IClient)) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  v4 = MapReslistGenerator();
  CMapReslistGenerator::OnPlayerSpawn(this: v4);
  NotifyDedicatedServerUI(message: "UpdatePlayers");
}

//------------------------------------------------------------------------------
// Address: 0x10116760
// Name: public: virtual bool CBaseClient::ProcessStringCmd(class NET_StringCmd __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessStringCmd(CBaseClient *this, NET_StringCmd *msg)
{
  (*(void (__thiscall **)(char *, const char *))(*((_DWORD *)this - 1) + 112))(
    a1: (char *)this - 4,
    a2: msg->m_szCommand);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10116780
// Name: public: virtual bool CBaseClient::ProcessClientInfo(class CLC_ClientInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessClientInfo(CBaseClient *this, CLC_ClientInfo *msg)
{
  this->m_Server = (CBaseServer *)msg->m_nSendTableCRC;
  this->m_bConVarsChanged = msg->m_bIsHLTV;
  this->m_nCustomFiles[3].crc = 0;
  V_strncpy(pDest: (char *)&this->m_SteamID.m_steamid.m_unAll64Bits + 7, pSrc: msg->m_FriendsName, maxLen: 32);
  *(_DWORD *)&this->m_bIsHLTV = msg->m_nCustomFiles[0];
  this->m_nSendtableCRC = 0;
  this->m_nCustomFiles[0].crc = msg->m_nCustomFiles[1];
  this->m_nCustomFiles[0].reqID = 0;
  this->m_nCustomFiles[1].crc = msg->m_nCustomFiles[2];
  this->m_nCustomFiles[1].reqID = 0;
  this->m_nCustomFiles[2].crc = msg->m_nCustomFiles[3];
  this->m_nCustomFiles[2].reqID = 0;
  if ( msg->m_nServerCount != (*(int (__thiscall **)(KeyValues *))(*(_DWORD *)this->m_ConVars + 60))(a1: this->m_ConVars) )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 48))(a1: (char *)this - 4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10116820
// Name: public: virtual bool CBaseClient::ProcessLoadingProgress(class CLC_LoadingProgress __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessLoadingProgress(CBaseClient *this, CLC_LoadingProgress *msg)
{
  this->m_nSignonTick = msg->m_nProgress;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10116840
// Name: public: bool CBaseClient::IsTracing(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClient::IsTracing(CBaseClient *this)
{
  return this->m_Trace.m_nMinWarningBytes != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10116850
// Name: public: void CBaseClient::SetTraceThreshold(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetTraceThreshold(CBaseClient *this, int nThreshold)
{
  this->m_Trace.m_nMinWarningBytes = nThreshold;
}

//------------------------------------------------------------------------------
// Address: 0x10116860
// Name: public: virtual bool CBaseClient::ExecuteStringCommand(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ExecuteStringCommand(CBaseClient *this, const char *pCommand)
{
  if ( pCommand != nullptr && *pCommand != 0 && _V_stricmp(s1: pCommand, s2: "demorestart") == 0 )
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 12))(a1: (char *)this - 4);
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101168A0
// Name: public: virtual bool CBaseClient::ShouldSendMessages(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ShouldSendMessages(CBaseClient *this)
{
  IClient *v2; // edi
  bool v4; // bl

  v2 = &this->IClient;
  if ( !this->IsConnected(this: &this->IClient) )
    return false;
  if ( this->m_NetChannel != nullptr && this->m_NetChannel->IsOverflowed(this: this->m_NetChannel) )
  {
    this->m_NetChannel->Reset(this: this->m_NetChannel);
    v2->Disconnect(this: v2, a2: "%s overflowed reliable buffer\n", this->m_Name);
    return false;
  }
  v4 = net_time >= this->m_fNextMessageTime;
  if ( this->m_NetChannel == nullptr || !this->m_NetChannel->IsLoopback(this: this->m_NetChannel) )
  {
    if ( v4 )
      goto LABEL_14;
    if ( v2->IsActive(this: v2)
      || !this->m_bReceivedPacket
      || this->m_NetChannel == nullptr
      || !this->m_NetChannel->HasPendingReliableData(this: this->m_NetChannel) )
    {
      return v4;
    }
  }
  v4 = true;
LABEL_14:
  if ( this->m_NetChannel != nullptr && !this->m_NetChannel->CanPacket(this: this->m_NetChannel) )
  {
    this->m_NetChannel->SetChoked(this: this->m_NetChannel);
    return false;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101169A0
// Name: public: virtual void CBaseClient::UpdateUserSettings(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::UpdateUserSettings(CBaseClient *this)
{
  CBaseClient_vtbl *v2; // edi
  const char *String; // eax
  IClient_vtbl *v4; // ebx
  int Int; // eax
  IClient_vtbl *v6; // ebx
  int v7; // eax
  IClient_vtbl *v8; // ebx
  int v9; // eax

  v2 = this->IGameEventListener2::__vftable;
  String = KeyValues::GetString(this: this->m_ConVars, keyName: "name", defaultValue: "unnamed");
  v2->SetName(this, a2: String);
  v4 = this->IClient::INetChannelHandler::__vftable;
  Int = KeyValues::GetInt(this: this->m_ConVars, keyName: "rate", defaultValue: 5000);
  v4->SetRate(this: &this->IClient, a2: Int, a3: false);
  v6 = this->IClient::INetChannelHandler::__vftable;
  v7 = KeyValues::GetInt(this: this->m_ConVars, keyName: "cl_updaterate", defaultValue: 20);
  v6->SetUpdateRate(this: &this->IClient, a2: v7, a3: false);
  v8 = this->IClient::INetChannelHandler::__vftable;
  v9 = KeyValues::GetInt(this: this->m_ConVars, keyName: "net_maxroutable", defaultValue: 1200);
  v8->SetMaxRoutablePayloadSize(this: &this->IClient, a2: v9);
  this->m_Server->UserInfoChanged(this: this->m_Server, a2: this->m_nClientSlot);
  this->m_bConVarsChanged = false;
}

//------------------------------------------------------------------------------
// Address: 0x10116A50
// Name: char const __near * GetUserIDString(struct USERID_s const __near &)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl GetUserIDString(const USERID_s *id)
{
  TSteamGlobalUserID nullID; // [esp+4h] [ebp-10h] BYREF

  idstr[0] = 0;
  if ( id->idtype == 1 )
  {
    _V_memset(dest: &nullID, fill: 0, count: 16);
    if ( Steam3Server()->m_eServerMode != eServerModeNoAuthentication
      || _V_memcmp(m1: &id->uid, m2: &nullID, count: 16) != 0 )
    {
      if ( _V_memcmp(m1: &id->uid, m2: &nullID, count: 16) != 0 )
      {
        V_snprintf(
          pDest: idstr,
          maxLen: 63,
          pFormat: "STEAM_%u:%u:%u",
          id->uid.steamid.m_SteamInstanceID,
          id->uid.steamid.m_SteamLocalUserID.Split.High32bits,
          id->uid.steamid.m_SteamLocalUserID.Split.Low32bits);
        byte_10631537 = 0;
      }
      else
      {
        strcpy(idstr, "STEAM_ID_PENDING");
      }
      return idstr;
    }
    else
    {
      strcpy(idstr, "STEAM_ID_LAN");
      return idstr;
    }
  }
  else if ( id->idtype == 3 )
  {
    strcpy(idstr, "HLTV");
    return idstr;
  }
  else
  {
    if ( id->idtype == 4 )
      strcpy(idstr, "REPLAY");
    else
      strcpy(idstr, "UNKNOWN");
    return idstr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116BE0
// Name: public: virtual char const __near * CBaseClient::GetNetworkIDString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseClient::GetNetworkIDString(CBaseClient *this)
{
  char *result; // eax
  KeyValues *v3; // ecx
  const USERID_s *v4; // eax
  _BYTE v5[24]; // [esp+4h] [ebp-18h] BYREF

  if ( this->IGameEventListener2::__vftable[1].SendServerInfo(this) )
    return "BOT";
  v3 = *(KeyValues **)&this->m_FriendsName[28];
  if ( v3 == nullptr
    || (result = (char *)KeyValues::GetString(this: v3, keyName: "networkid_force", defaultValue: defaultValue)) == nullptr
    || *result == 0 )
  {
    v4 = (const USERID_s *)((int (__thiscall *)(CBaseClient *, _BYTE *))this->SetName)(a1: this, a2: v5);
    return GetUserIDString(id: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10116C40
// Name: public: virtual bool CBaseClient::IgnoreTempEntity(class CEventInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IgnoreTempEntity(CBaseClient *this, CEventInfo *event)
{
  int v2; // eax

  v2 = this->GetPlayerSlot(this: &this->IClient);
  return CEngineRecipientFilter::IncludesPlayer(this: &event->filter, playerindex: v2 + 1) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10116C70
// Name: public: void CBaseClient::SetSteamID(class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetSteamID(CBaseClient *this, const CSteamID *steamID)
{
  this->m_SteamID = (CSteamID)steamID->m_steamid.m_comp;
}

//------------------------------------------------------------------------------
// Address: 0x10116C90
// Name: public: virtual void CBaseClient::SetMaxRoutablePayloadSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetMaxRoutablePayloadSize(CBaseClient *this, int nMaxRoutablePayloadSize)
{
  if ( this->m_nFilesDownloaded != 0 )
    (*(void (__thiscall **)(int, int))(*(_DWORD *)this->m_nFilesDownloaded + 276))(
      a1: this->m_nFilesDownloaded,
      a2: nMaxRoutablePayloadSize);
}

//------------------------------------------------------------------------------
// Address: 0x10116CC0
// Name: public: virtual int CBaseClient::GetMaxAckTickCount(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetMaxAckTickCount(CBaseClient *this)
{
  int result; // eax
  int m_nSignonState; // edx
  int m_nDeltaTick; // ecx

  result = this->m_nStringTableAckTick;
  m_nSignonState = this->m_nSignonState;
  m_nDeltaTick = this->m_nDeltaTick;
  if ( m_nSignonState > result )
    result = m_nSignonState;
  if ( m_nDeltaTick > result )
    return m_nDeltaTick;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10116CE0
// Name: private: void CBaseClient::SendFullConnectEvent(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SendFullConnectEvent(CBaseClient *this)
{
  IGameEvent *v2; // esi

  v2 = g_GameEventManager->CreateEventA(this: g_GameEventManager, a2: "player_connect_full", a3: 0, a4: 0);
  if ( v2 != nullptr )
  {
    v2->SetInt(this: v2, a2: "userid", a3: this->m_UserID);
    v2->SetInt(this: v2, a2: "index", a3: this->m_nClientSlot);
    g_GameEventManager->FireEvent(this: g_GameEventManager, a2: v2, a3: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10116D40
// Name: public: virtual bool CBaseClient::ProcessSplitScreenUser(class NET_SplitScreenUser __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ProcessSplitScreenUser(CBaseClient *this, NET_SplitScreenUser *msg)
{
  int m_nSlot; // eax
  char v5; // al
  int v6; // eax

  if ( (*(unsigned __int8 (__thiscall **)(char *))(*((_DWORD *)this - 1) + 156))(a1: (char *)this - 4) != 0 )
    return this->m_SplitScreenUsers[0]->ProcessSplitScreenUser(
             this: &this->m_SplitScreenUsers[0]->IClientMessageHandler,
             a2: msg);
  m_nSlot = msg->m_nSlot;
  if ( m_nSlot == -1 )
  {
    v5 = (*(int (__stdcall **)(unsigned int))(*(_DWORD *)this->m_nCustomFiles[3].reqID + 284))(a1: this->m_nCustomFiles[3].reqID);
  }
  else
  {
    v6 = *((_DWORD *)&this->m_bSplitScreenUser + m_nSlot);
    if ( v6 == 0 )
    {
LABEL_8:
      _Msg(a1: "Unable to set SetActiveChannel to user in slot %d\n", msg->m_nSlot);
      return false;
    }
    v5 = (*(int (__thiscall **)(unsigned int, _DWORD))(*(_DWORD *)this->m_nCustomFiles[3].reqID + 284))(
           a1: this->m_nCustomFiles[3].reqID,
           a2: *(_DWORD *)(v6 + 220));
  }
  if ( v5 == 0 )
    goto LABEL_8;
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x10116DD0
// Name: public: bool CBaseClient::IsSplitScreenPartner(class CBaseClient const __near *)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsSplitScreenPartner(CBaseClient *this, const CBaseClient *pOther)
{
  return pOther != nullptr
      && (pOther->IsSplitScreenUser(this: &pOther->IClient) && pOther->m_pAttachedTo == this
       || this->IsSplitScreenUser(this: &this->IClient) && this->m_pAttachedTo == pOther);
}

//------------------------------------------------------------------------------
// Address: 0x10116E20
// Name: public: virtual int CBaseClient::GetNumPlayers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetNumPlayers(CBaseClient *this)
{
  int result; // eax

  if ( ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0 )
  {
    if ( this->m_SplitScreenUsers[1] != nullptr )
      return this->m_SplitScreenUsers[1]->GetNumPlayers(this: &this->m_SplitScreenUsers[1]->IClient);
    else
      return 0;
  }
  else
  {
    result = this->m_nSplitScreenPlayerSlot != 0;
    if ( this->m_SplitScreenUsers[0] != nullptr )
      ++result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10116E70
// Name: public: virtual bool CBaseClient::IsHumanPlayer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsHumanPlayer(CBaseClient *this)
{
  return ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this) != 0
      && !this->IGameEventListener2::__vftable[1].SendSignonData(this)
      && (!this->IGameEventListener2::__vftable[1].SendServerInfo(this)
       || ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x10116F50
// Name: public: virtual void CBaseClient::SetUpdateRate(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SetUpdateRate(CBaseClient *this, int udpaterate, bool bForce)
{
  int v3; // eax

  v3 = udpaterate;
  if ( udpaterate >= 1 )
  {
    if ( udpaterate > 100 )
      v3 = 100;
  }
  else
  {
    v3 = 1;
  }
  *((float *)&this->m_fNextMessageTime + 1) = 1.0 / (float)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10116F90
// Name: protected: virtual bool CBaseClient::ProcessSignonStateMsg(int,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ProcessSignonStateMsg(CBaseClient *this, int state, int spawncount)
{
  bool result; // al
  const char *v5; // eax
  IMDLCache *v6; // edi
  CBaseClient **m_SplitScreenUsers; // esi
  int i; // ebx
  CBaseClient **v9; // esi
  int j; // ebx
  int v11; // [esp-8h] [ebp-10h]

  if ( this->IsSplitScreenUser(this: &this->IClient) )
    return true;
  v5 = (const char *)((int (__thiscall *)(IClient *, int))this->GetClientName)(
                       a1: &this->IClient,
                       a2: this->m_nSignonState);
  _COM_TimestampedLog(a1: "CBaseClient::ProcessSignonStateMsg: %s  :  %d", v5, v11);
  v6 = g_pMDLCache;
  g_pMDLCache->BeginCoarseLock(this: g_pMDLCache);
  switch ( this->m_nSignonState )
  {
    case 2:
      this->m_bSendServerInfo = true;
      v6->EndCoarseLock(this: v6);
      return true;
    case 3:
      if ( this->SendSignonData(this) )
        goto LABEL_17;
      v6->EndCoarseLock(this: v6);
      return false;
    case 4:
      this->SpawnPlayer(this);
      v6->EndCoarseLock(this: v6);
      return true;
    case 5:
      m_SplitScreenUsers = this->m_SplitScreenUsers;
      for ( i = 2; i != 0; --i )
      {
        if ( *m_SplitScreenUsers != nullptr )
          (*m_SplitScreenUsers)->ActivatePlayer(this: *m_SplitScreenUsers);
        ++m_SplitScreenUsers;
      }
      goto LABEL_17;
    case 6:
      v9 = this->m_SplitScreenUsers;
      for ( j = 2; j != 0; --j )
      {
        if ( *v9 != nullptr )
          CBaseClient::SendFullConnectEvent(this: *v9);
        ++v9;
      }
      goto LABEL_17;
    default:
LABEL_17:
      v6->EndCoarseLock(this: v6);
      result = true;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10117250
// Name: public: virtual bool CBaseClient::ProcessSignonState(class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::ProcessSignonState(CBaseClient *this, NET_SignonState *msg)
{
  int m_nSignonState; // eax
  int v5; // eax

  m_nSignonState = msg->m_nSignonState;
  if ( m_nSignonState == 7 )
    return true;
  if ( m_nSignonState > 2
    && msg->m_nSpawnCount != (*(int (__thiscall **)(KeyValues *))(*(_DWORD *)this->m_ConVars + 60))(a1: this->m_ConVars)
    || (v5 = msg->m_nSignonState) != this->m_nFilesDownloaded )
  {
    (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 48))(a1: (char *)this - 4);
    return true;
  }
  return (*(bool (__thiscall **)(char *, int, int))(*((_DWORD *)this - 2) + 80))(
           a1: (char *)this - 8,
           a2: v5,
           a3: msg->m_nSpawnCount);
}

//------------------------------------------------------------------------------
// Address: 0x101172B0
// Name: public: virtual void CBaseClient::UpdateSendState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::UpdateSendState(CBaseClient *this)
{
  CBaseServer *m_Server; // ecx
  long double v3; // st7
  double v4; // st7
  long double v5; // st5
  INetChannel *m_NetChannel; // ecx
  float maxDelta; // [esp+4h] [ebp-4h]

  m_Server = this->m_Server;
  this->m_bReceivedPacket = false;
  if ( !m_Server->IsMultiplayer(this: m_Server) && host_limitlocal.m_pParent->m_Value.m_fValue == 0.0 )
  {
    v3 = net_time;
    this->m_bReceivedPacket = true;
    this->m_fNextMessageTime = v3;
    return;
  }
  if ( this->IsActive(this: &this->IClient) )
  {
    maxDelta = this->m_fSnapshotInterval;
    v4 = ((double (__thiscall *)(CBaseServer *))this->m_Server->GetTickInterval)(a1: this->m_Server);
    if ( maxDelta <= v4 )
      v4 = maxDelta;
    else
      this->m_Server->GetTickInterval(this: this->m_Server);
    v5 = net_time - this->m_fNextMessageTime;
    if ( v5 < 0.0 )
    {
      v5 = 0.0;
LABEL_10:
      this->m_fNextMessageTime = net_time + this->m_fSnapshotInterval - v5;
      return;
    }
    if ( v5 <= v4 )
      goto LABEL_10;
    this->m_fNextMessageTime = net_time + this->m_fSnapshotInterval - v4;
  }
  else
  {
    m_NetChannel = this->m_NetChannel;
    if ( m_NetChannel != nullptr
      && m_NetChannel->HasPendingReliableData(this: m_NetChannel)
      && ((double (__thiscall *)(INetChannel *))this->m_NetChannel->GetTimeSinceLastReceived)(a1: this->m_NetChannel) < 1.0 )
    {
      this->m_fNextMessageTime = net_time;
    }
    else
    {
      this->m_fNextMessageTime = net_time + 1.0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101173F0
// Name: public: unsigned __int64 CBaseClient::GetClientXuid(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClient::GetClientXuid(CBaseClient *this)
{
  KeyValues *m_ConVars; // ecx
  const char *String; // eax
  const char *v4; // esi
  unsigned int v5; // edi
  __int64 v6; // rax

  m_ConVars = this->m_ConVars;
  if ( m_ConVars != nullptr
    && (String = KeyValues::GetString(this: m_ConVars, keyName: "networkid_force", defaultValue: nullptr),
        v4 = String,
        String != nullptr)
    && *String != 0
    && strlen(String) > 0xA )
  {
    v5 = strtoul(nptr: v4 + 9, endptr: nullptr, ibase: 0x10u);
    strtoul(nptr: v4, endptr: nullptr, ibase: 0x10u);
    LODWORD(v6) = v5;
  }
  else if ( this->IsFakeClient(this: &this->IClient) )
  {
    LODWORD(v6) = 0;
  }
  else
  {
    return this->m_SteamID.m_steamid.m_unAll64Bits;
  }
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10117480
// Name: public: virtual struct USERID_s const CBaseClient::GetNetworkID(void)const
// Source: json
//------------------------------------------------------------------------------
const USERID_s *__thiscall CBaseClient::GetNetworkID(CBaseClient *this, const USERID_s *result)
{
  result->uid.steamid.m_SteamInstanceID = 0;
  result->uid.steamid.m_SteamLocalUserID.Split.High32bits = *(_DWORD *)&this->m_GUID[29] & 1;
  result->uid.steamid.m_SteamLocalUserID.Split.Low32bits = *(_DWORD *)&this->m_GUID[29] >> 1;
  result->idtype = 1;
  result->uid.steamid.m_SteamInstanceID = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101174B0
// Name: public: virtual char const __near * CLC_VoiceData::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_VoiceData::GetName(CLC_VoiceData *this)
{
  return "clc_VoiceData";
}

//------------------------------------------------------------------------------
// Address: 0x101174D0
// Name: public: virtual bool CBaseClient::FillUserInfo(struct player_info_s __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::FillUserInfo(CBaseClient *this, player_info_s *userInfo)
{
  bool result; // al
  const char *v4; // eax
  const char *v5; // eax
  int v6; // edx
  bool v7; // al

  _V_memset(dest: userInfo, fill: 0, count: 144);
  result = this->IsConnected(this: &this->IClient);
  if ( result )
  {
    v4 = this->GetClientName(this: &this->IClient);
    V_strncpy(pDest: userInfo->name, pSrc: v4, maxLen: 32);
    v5 = this->GetNetworkIDString(this: &this->IClient);
    _V_memcpy(dest: userInfo->guid, src: v5, count: 33);
    userInfo->friendsID = this->m_SteamID.m_steamid.m_unAll64Bits;
    LODWORD(userInfo->xuid) = CBaseClient::GetClientXuid(this);
    HIDWORD(userInfo->xuid) = v6;
    V_strncpy(pDest: userInfo->friendsName, pSrc: this->m_FriendsName, maxLen: 32);
    userInfo->userID = this->GetUserID(this: &this->IClient);
    v7 = this->IsFakeClient(this: &this->IClient) && !this->IsSplitScreenUser(this: &this->IClient);
    userInfo->fakeplayer = v7;
    userInfo->ishltv = this->IsHLTV(this: &this->IClient);
    userInfo->customFiles[0] = this->m_nCustomFiles[0].crc;
    userInfo->customFiles[1] = this->m_nCustomFiles[1].crc;
    userInfo->customFiles[2] = this->m_nCustomFiles[2].crc;
    userInfo->customFiles[3] = this->m_nCustomFiles[3].crc;
    userInfo->filesDownloaded = this->m_nFilesDownloaded;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101175F0
// Name: public: virtual void CBaseClient::ClientPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseClient::ClientPrintf(CBaseClient *this, const char *fmt, ...)
{
  int m_nFilesDownloaded; // ecx
  char string[1024]; // [esp+0h] [ebp-C14h] BYREF
  SVC_Print print; // [esp+400h] [ebp-814h] BYREF
  va_list params; // [esp+C24h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  print.m_szText = string;
  m_nFilesDownloaded = this->m_nFilesDownloaded;
  print.m_NetChannel = nullptr;
  print.m_bReliable = false;
  print.__vftable = (SVC_Print_vtbl *)&SVC_Print::`vftable';
  (*(void (__thiscall **)(int, SVC_Print *, _DWORD, _DWORD))(*(_DWORD *)m_nFilesDownloaded + 164))(
    a1: m_nFilesDownloaded,
    a2: &print,
    a3: 0,
    a4: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10117660
// Name: public: virtual void CBaseClient::FreeBaselines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::FreeBaselines(CBaseClient *this)
{
  CFrameSnapshot *m_pBaseline; // ecx

  m_pBaseline = this->m_pBaseline;
  if ( m_pBaseline != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_pBaseline);
    this->m_pBaseline = nullptr;
  }
  this->m_nBaselineUpdateTick = -1;
  this->m_nBaselineUsed = 0;
  if ( this != (CBaseClient *)-256 )
    memset(dst: (unsigned __int8 *)&this->m_BaselinesSent, value: 0, count: sizeof(this->m_BaselinesSent));
}

//------------------------------------------------------------------------------
// Address: 0x101176B0
// Name: public: virtual void CBaseClient::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::Clear(CBaseClient *this)
{
  int m_nFilesDownloaded; // ecx
  KeyValues *v3; // ecx
  void (__thiscall *WriteGameSounds)(CBaseClient *, bf_write *, int); // edx
  CFrameSnapshot *m_nSignonTick; // ecx
  char v6; // [esp+Fh] [ebp-1h]

  m_nFilesDownloaded = this->m_nFilesDownloaded;
  if ( m_nFilesDownloaded != 0 )
  {
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)m_nFilesDownloaded + 148))(
      a1: m_nFilesDownloaded,
      a2: "Disconnect by server.\n");
    this->m_nFilesDownloaded = 0;
  }
  v3 = *(KeyValues **)&this->m_FriendsName[28];
  if ( v3 != nullptr )
  {
    KeyValues::deleteThis(this: v3);
    *(_DWORD *)&this->m_FriendsName[28] = 0;
  }
  (*(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 72))(a1: (char *)this - 4);
  v6 = ((int (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this);
  WriteGameSounds = this->IGameEventListener2::__vftable[1].WriteGameSounds;
  this->m_NetChannel = nullptr;
  if ( v6 != ((unsigned __int8 (__thiscall *)(CBaseClient *))WriteGameSounds)(a1: this)
    && (!this->IGameEventListener2::__vftable[1].SendServerInfo(this)
     || ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  this->m_nSignonState = -1;
  this->m_nStringTableAckTick = 0;
  this->m_nDeltaTick = 0;
  m_nSignonTick = (CFrameSnapshot *)this->m_nSignonTick;
  if ( m_nSignonTick != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_nSignonTick);
    this->m_nSignonTick = 0;
  }
  *(double *)(&this->m_bFullyAuthenticated + 1) = 0.0;
  this->m_nBaselineUsed = -1;
  LOBYTE(this->m_nForceWaitForTick) = 0;
  LOWORD(this->m_nDebugID) = 0;
  LOBYTE(this->m_pAttachedTo) = 0;
  *(_DWORD *)&this->m_bSplitScreenUser = 0;
  this->m_SplitScreenUsers[1] = nullptr;
  LOBYTE(this->m_Server) = 0;
  HIDWORD(this->m_fNextMessageTime) = 0;
  *(_WORD *)((char *)&this->m_nForceWaitForTick + 1) = 0;
  this->m_nEntityIndex = 0;
  LOBYTE(this->m_UserID) = 0;
  LOBYTE(this->m_nFriendsID) = 0;
  *(_DWORD *)&this->m_bIsHLTV = 0;
  this->m_pBaseline = (CFrameSnapshot *)-1;
  this->m_BaselinesSent.m_Ints[63] = 0;
  this->m_nCustomFiles[3].reqID = 0;
  LOWORD(this->m_ConVars) = 0;
  this->m_pLastSnapshot.m_pObj = nullptr;
  HIBYTE(this->m_nForceWaitForTick) = 0;
  LODWORD(this->m_fSnapshotInterval) = 1;
  _V_memset(dest: &this->m_nSendtableCRC, fill: 0, count: 32);
}

//------------------------------------------------------------------------------
// Address: 0x10117810
// Name: public: virtual void CBaseClient::Disconnect(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseClient::Disconnect(int a1@<esi>, CBaseClient *this, const char *fmt, ...)
{
  int v3; // ebx
  const char *v4; // eax
  bool (__thiscall *FillUserInfo)(CBaseClient *, player_info_s *); // edx
  int *v6; // esi
  int v7; // ebx
  int v8; // ecx
  int v9; // eax
  char *v10; // eax
  CSteam3Server *v11; // eax
  char string[1024]; // [esp+4h] [ebp-814h] BYREF
  NET_StringCmd stringCmd; // [esp+404h] [ebp-414h] BYREF
  va_list params; // [esp+828h] [ebp+10h] BYREF

  va_start(params, fmt);
  if ( this->m_NetChannel != nullptr && *(int *)&this->m_bSplitPlayerDisconnecting >= 0 )
  {
    v3 = *(_DWORD *)&this->m_bSplitPlayerDisconnecting;
    if ( v3 < (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_bConVarsChanged + 28))(a1: *(_DWORD *)&this->m_bConVarsChanged)
      && (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->m_bConVarsChanged + 24))(
           a1: *(_DWORD *)&this->m_bConVarsChanged,
           a2: v3) == (this != (CBaseClient *)4 ? (unsigned int)this : 0) )
    {
      if ( ((unsigned __int8 (__thiscall *)(CBaseClient *, int))this->IGameEventListener2::__vftable[1].SetUserCVar)(
             a1: this,
             a2: a1) == 0
        || BYTE1(this->m_nDebugID) != 0 )
      {
        if ( ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) == 0
          && host_state.max_splitscreen_players > 1 )
        {
          v6 = &this->m_nSplitScreenPlayerSlot + host_state.max_splitscreen_players;
          v7 = host_state.max_splitscreen_players - 1;
          do
          {
            v8 = *--v6;
            if ( v8 != 0 )
            {
              (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v8 + 84))(a1: v8, a2: "leaving splitscreen");
              *v6 = 0;
            }
            --v7;
          }
          while ( v7 != 0 );
        }
        v9 = V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
        if ( v9 > 0 )
        {
          v10 = &string[v9 - 1];
          do
          {
            if ( *v10 != 10 )
              break;
            *v10-- = 0;
          }
          while ( (int)&v10[1 - (_DWORD)string] > 0 );
        }
        (*(void (__thiscall **)(char *, char *))(*((_DWORD *)this - 1) + 84))(a1: (char *)this - 4, a2: string);
        NotifyDedicatedServerUI(message: "UpdatePlayers");
        v11 = Steam3Server();
        CSteam3Server::SendUpdatedServerDetails(this: v11);
      }
      else
      {
        v4 = va(format: "ss_disconnect %d\n", *(_DWORD *)&this->m_bSplitScreenUser);
        FillUserInfo = this->IGameEventListener2::__vftable[1].FillUserInfo;
        stringCmd.m_szCommand = v4;
        stringCmd.m_bReliable = true;
        stringCmd.m_NetChannel = nullptr;
        stringCmd.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
        ((void (__thiscall *)(CBaseClient *, NET_StringCmd *, int))FillUserInfo)(a1: this, a2: &stringCmd, a3: 1);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117990
// Name: public: void CBaseClient::ApplyConVars(class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::ApplyConVars(
        CBaseClient *this,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *list)
{
  int v2; // esi
  int v3; // ebx
  CBaseClient *v4; // [esp+8h] [ebp-4h]

  v2 = 0;
  v4 = this;
  if ( list->m_Size <= 0 )
  {
    this->m_bConVarsChanged = true;
  }
  else
  {
    v3 = 0;
    while ( 1 )
    {
      KeyValues::SetString(
        this: this->m_ConVars,
        keyName: list->m_Memory.m_pMemory[v3].name,
        value: list->m_Memory.m_pMemory[v3].value);
      ++v2;
      ++v3;
      if ( v2 >= list->m_Size )
        break;
      this = v4;
    }
    v4->m_bConVarsChanged = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117A00
// Name: public: virtual bool CBaseClient::ProcessSetConVar(class NET_SetConVar __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessSetConVar(CBaseClient *this, NET_SetConVar *msg)
{
  CBaseClient::ApplyConVars(this: (CBaseClient *)((char *)this - 8), list: &msg->m_ConVars);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117A20
// Name: public: virtual bool CBaseClient::ProcessBaselineAck(class CLC_BaselineAck __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessBaselineAck(CBaseClient *this, CFrameSnapshot *msg)
{
  int v4; // eax
  int NextSetBit; // edi
  int v6; // esi
  int m_pPackedData; // eax
  CFrameSnapshotEntry *m_pEntities; // edx
  CFrameSnapshotEntry *v9; // eax
  CFrameSnapshotEntry *v10; // ecx
  BOOL v11; // ecx
  int hNewEntity; // [esp+4h] [ebp-4h]
  CFrameSnapshot *pSnapshot; // [esp+10h] [ebp+8h]

  if ( msg->m_pValidEntities != (unsigned __int16 *)this->m_nLoadingProgress )
    return 1;
  if ( msg->m_nValidEntities != this->m_BaselinesSent.m_Ints[62] )
  {
    DevMsg(a1: "CBaseClient::ProcessBaselineAck: wrong baseline nr received (%i)\n", msg->m_pValidEntities);
    return 1;
  }
  v4 = (*(int (__thiscall **)(char *, int))(*((_DWORD *)this - 2) + 40))(
         a1: (char *)this - 8,
         a2: this->m_nLoadingProgress);
  if ( v4 == 0 )
    return 1;
  pSnapshot = *(CFrameSnapshot **)(v4 + 280);
  if ( pSnapshot != nullptr )
  {
    NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(this: (CFixedBitVecBase<2048> *)&this->m_pBaseline, startBit: 0);
    if ( NextSetBit < 0 )
    {
LABEL_13:
      this->m_pLastSnapshot.m_pObj->m_nTickCount = this->m_nLoadingProgress;
      v11 = this->m_BaselinesSent.m_Ints[62] != 1;
      this->m_nLoadingProgress = -1;
      this->m_BaselinesSent.m_Ints[62] = v11;
      return 1;
    }
    else
    {
      while ( 1 )
      {
        v6 = NextSetBit;
        m_pPackedData = pSnapshot->m_pEntities[NextSetBit].m_pPackedData;
        hNewEntity = m_pPackedData;
        if ( m_pPackedData == 0 )
          break;
        m_pEntities = this->m_pLastSnapshot.m_pObj->m_pEntities;
        if ( m_pEntities[v6].m_pPackedData != 0 )
        {
          CFrameSnapshotManager::RemoveEntityReference(
            this: framesnapshotmanager,
            handle: m_pEntities[v6].m_pPackedData);
          m_pPackedData = hNewEntity;
        }
        CFrameSnapshotManager::AddEntityReference(this: framesnapshotmanager, handle: m_pPackedData);
        v9 = pSnapshot->m_pEntities;
        v10 = this->m_pLastSnapshot.m_pObj->m_pEntities;
        v10[NextSetBit].m_pClass = v9[NextSetBit].m_pClass;
        v10[v6].m_nSerialNumber = v9[v6].m_nSerialNumber;
        v10[v6].m_pPackedData = v9[v6].m_pPackedData;
        NextSetBit = CFixedBitVecBase<2048>::FindNextSetBit(
                       this: (CFixedBitVecBase<2048> *)&this->m_pBaseline,
                       startBit: NextSetBit + 1);
        if ( NextSetBit < 0 )
          goto LABEL_13;
      }
      DevMsg(a1: "CBaseClient::ProcessBaselineAck: invalid packet handle (%i)\n", NextSetBit);
      return 0;
    }
  }
  else
  {
    DevMsg(a1: "CBaseClient::ProcessBaselineAck: invalid frame snapshot (%i)\n", this->m_nLoadingProgress);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10117B90
// Name: public: virtual bool CBaseClient::ProcessListenEvents(class CLC_ListenEvents __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessListenEvents(CBaseClient *this, CLC_ListenEvents *msg)
{
  char *v2; // edi
  unsigned int v3; // esi
  CGameEventDescriptor *EventDescriptor; // eax

  v2 = (char *)this - 8;
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: (CBaseClient *)((char *)this - 8));
  v3 = 0;
  while ( ((1 << (v3 & 0x1F)) & msg->m_EventArray.m_Ints[v3 >> 5]) == 0 )
  {
LABEL_5:
    if ( (int)++v3 >= 512 )
      return 1;
  }
  EventDescriptor = CGameEventManager::GetEventDescriptor(this: g_GameEventManager, eventid: v3);
  if ( EventDescriptor != nullptr )
  {
    CGameEventManager::AddListener(
      this: g_GameEventManager,
      listener: v2,
      descriptor: EventDescriptor,
      nListenerType: 2);
    goto LABEL_5;
  }
  DevMsg(a1: "ProcessListenEvents: game event %i not found.\n", v3);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10117C10
// Name: private: void CBaseClient::OnRequestFullUpdate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::OnRequestFullUpdate(CBaseClient *this, const char *pchReason)
{
  CFrameSnapshot *m_pObj; // ecx
  CFrameSnapshot *EmptySnapshot; // eax
  IClient_vtbl *v5; // edx
  const char *v6; // eax
  const char *v7; // [esp-4h] [ebp-8h]

  m_pObj = this->m_pLastSnapshot.m_pObj;
  if ( m_pObj != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_pObj);
    this->m_pLastSnapshot.m_pObj = nullptr;
  }
  this->FreeBaselines(this);
  EmptySnapshot = CFrameSnapshotManager::CreateEmptySnapshot(
                    this: framesnapshotmanager,
                    tickcount: 0,
                    maxEntities: 2048);
  v5 = this->IClient::INetChannelHandler::__vftable;
  this->m_pBaseline = EmptySnapshot;
  v6 = (const char *)((int (__thiscall *)(IClient *, const char *))v5->GetClientName)(a1: &this->IClient, a2: pchReason);
  DevMsg(a1: "Sending full update to Client %s (%s)\n", v6, v7);
}

//------------------------------------------------------------------------------
// Address: 0x10117C80
// Name: public: virtual bool CBaseClient::UpdateAcknowledgedFramecount(int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::UpdateAcknowledgedFramecount(CBaseClient *this, int tick)
{
  IClient *v3; // ebx
  int m_nForceWaitForTick; // eax
  int v6; // edi
  int m_nDeltaTick; // eax
  int m_nBaselineUpdateTick; // eax

  v3 = &this->IClient;
  if ( this->IsFakeClient(this: &this->IClient) )
  {
    this->m_nDeltaTick = tick;
    this->m_nStringTableAckTick = tick;
    return 1;
  }
  m_nForceWaitForTick = this->m_nForceWaitForTick;
  if ( m_nForceWaitForTick > 0 )
  {
    v6 = tick;
    if ( tick <= m_nForceWaitForTick )
    {
      if ( tick == -1 )
      {
        if ( !this->m_NetChannel->HasPendingReliableData(this: this->m_NetChannel) )
        {
          _ConDMsg(a1: "Client forced immediate full update.\n");
          this->m_nDeltaTick = -1;
          this->m_nForceWaitForTick = -1;
          CBaseClient::OnRequestFullUpdate(this, pchReason: "forced immediate full update");
          return 1;
        }
        goto LABEL_13;
      }
      if ( tick >= m_nForceWaitForTick )
      {
        this->m_nForceWaitForTick = -1;
LABEL_13:
        this->m_nDeltaTick = v6;
        if ( v6 > -1 )
          this->m_nStringTableAckTick = v6;
        m_nBaselineUpdateTick = this->m_nBaselineUpdateTick;
        if ( m_nBaselineUpdateTick > -1 && v6 > m_nBaselineUpdateTick )
          this->m_nBaselineUpdateTick = -1;
      }
    }
    return 1;
  }
  m_nDeltaTick = this->m_nDeltaTick;
  if ( m_nDeltaTick == -1 )
    return 1;
  v6 = tick;
  if ( tick == -1 )
  {
    CBaseClient::OnRequestFullUpdate(this, pchReason: "client ack'd -1");
    goto LABEL_13;
  }
  if ( m_nDeltaTick <= tick )
    goto LABEL_13;
  v3->Disconnect(this: v3, a2: "Client delta ticks out of order.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10117D90
// Name: public: static int SessionClient_t::Less(struct SessionClient_t const __near *,struct SessionClient_t const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl SessionClient_t::Less(const SessionClient_t *a, const SessionClient_t *b)
{
  __int64 v2; // rax
  int numPlayers; // eax
  int m_Size; // ecx
  IClient *v6; // esi
  int v7; // edi

  HIDWORD(v2) = a->xSession;
  LODWORD(v2) = HIDWORD(a->xSession);
  if ( LODWORD(a->xSession) != LODWORD(b->xSession) || (_DWORD)v2 != HIDWORD(b->xSession) )
  {
    if ( v2 == 0 )
      return 1;
    if ( b->xSession == 0 )
      return -1;
  }
  numPlayers = a->numPlayers;
  m_Size = b->numPlayers;
  if ( numPlayers != m_Size )
    return 2 * (numPlayers <= m_Size) - 1;
  numPlayers = a->arrClients.m_Size;
  m_Size = b->arrClients.m_Size;
  if ( numPlayers != m_Size )
    return 2 * (numPlayers <= m_Size) - 1;
  if ( a->xSession != b->xSession )
  {
    if ( a->xSession == CBaseServer::GetReservationCookie(this: &sv) )
      return -1;
    if ( b->xSession == CBaseServer::GetReservationCookie(this: &sv) )
      return 1;
  }
  v6 = *b->arrClients.m_Memory.m_pMemory;
  v7 = (*(int (__thiscall **)(IClient *))(**(_DWORD **)a->arrClients.m_Memory.m_pMemory + 60))(a1: *a->arrClients.m_Memory.m_pMemory);
  return 2 * (v7 >= v6->GetUserID(this: v6)) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10117E50
// Name: public: void CBaseClient::DisconnectSplitScreenUser(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::DisconnectSplitScreenUser(CBaseClient *this, CBaseClient *pSplitClient)
{
  int m_nSplitScreenPlayerSlot; // edi
  INetChannel *m_NetChannel; // ecx
  SVC_SplitScreen msg; // [esp+8h] [ebp-1Ch] BYREF

  CBaseServer::QueueSplitScreenDisconnect(this: &sv, pSplitHost: this, pSplitUser: pSplitClient);
  m_nSplitScreenPlayerSlot = pSplitClient->m_nSplitScreenPlayerSlot;
  m_NetChannel = this->m_NetChannel;
  msg.m_nPlayerIndex = pSplitClient->m_nEntityIndex;
  msg.m_bReliable = true;
  msg.m_NetChannel = nullptr;
  msg.__vftable = (SVC_SplitScreen_vtbl *)&SVC_SplitScreen::`vftable';
  msg.m_nSlot = m_nSplitScreenPlayerSlot;
  msg.m_Type = MSG_REMOVEUSER;
  m_NetChannel->DetachSplitPlayer(this: m_NetChannel, a2: m_nSplitScreenPlayerSlot);
  this->SendNetMsg(this: &this->IClient, a2: &msg, a3: true, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10117F00
// Name: public: virtual class IClient __near * CBaseServer::GetClient(int)
// Source: json
//------------------------------------------------------------------------------
IClient *__thiscall CBaseServer::GetClient(CBaseServer *this, int index)
{
  CBaseClient *v2; // eax

  v2 = this->m_Clients.m_Memory.m_pMemory[index];
  if ( v2 != nullptr )
    return &v2->IClient;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10117F20
// Name: public: virtual void CBaseClient::Connect(char const __near *,int,class INetChannel __near *,bool,enum CrossPlayPlatform_t,class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::Connect(
        CBaseClient *this,
        const char *szName,
        int nUserID,
        INetChannel *pNetChannel,
        bool bFakePlayer,
        float clientPlatform,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *pVecCvars)
{
  IEngineVGuiInternal *v8; // eax
  KeyValues *v9; // eax
  KeyValues *v10; // eax
  CBaseClient *v11; // edi
  CBaseClient *v12; // ecx
  const char *v13; // eax
  CSteam3Server *v14; // eax
  int v15; // ecx
  char v16; // bl
  void (__thiscall *WriteGameSounds)(CBaseClient *, bf_write *, int); // eax

  _COM_TimestampedLog(a1: "CBaseClient::Connect");
  if ( !bFakePlayer )
  {
    v8 = EngineVGui();
    v8->UpdateProgressBar(this: v8, a2: PROGRESS_SIGNONCONNECT, a3: false);
  }
  ((void (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].UpdateAcknowledgedFramecount)(a1: this);
  this->m_nEntityIndex = nUserID;
  v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v9 != nullptr )
    v10 = KeyValues::KeyValues(this: v9, setName: "userinfo");
  else
    v10 = nullptr;
  *(_DWORD *)&this->m_FriendsName[28] = v10;
  v11 = (CBaseClient *)((char *)this - 4);
  v12 = (CBaseClient *)((char *)this - 4);
  if ( pVecCvars != nullptr )
  {
    CBaseClient::ApplyConVars(this: v12, list: pVecCvars);
    v13 = (const char *)((int (__thiscall *)(CBaseClient *, const char *))this->ProcessSignonStateMsg)(
                          a1: this,
                          a2: "name");
    if ( v13 == nullptr || *v13 == 0 )
      v13 = szName;
    v11->SetName(this: (CBaseClient *)((char *)this - 4), a2: v13);
  }
  else
  {
    v11->SetName(this: v12, a2: szName);
  }
  LOBYTE(this->m_nForceWaitForTick) = bFakePlayer;
  if ( bFakePlayer )
  {
    v14 = Steam3Server();
    CSteam3Server::NotifyLocalClientConnect(this: v14, client: (CBaseClient *)((char *)this - 4));
  }
  this->m_nFilesDownloaded = (int)pNetChannel;
  if ( pNetChannel != nullptr )
  {
    v15 = *(_DWORD *)&this->m_bConVarsChanged;
    if ( v15 != 0 && (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v15 + 100))(a1: v15) != 0 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)this->m_nFilesDownloaded + 248))(
        a1: this->m_nFilesDownloaded,
        a2: 1);
  }
  this->m_fSnapshotInterval = clientPlatform;
  v16 = ((int (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this);
  WriteGameSounds = this->IGameEventListener2::__vftable[1].WriteGameSounds;
  v11->m_nSignonState = 2;
  if ( v16 != ((unsigned __int8 (__thiscall *)(CBaseClient *))WriteGameSounds)(a1: this)
    && (!this->IGameEventListener2::__vftable[1].SendServerInfo(this)
     || ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118080
// Name: public: virtual void CBaseClient::FireGameEvent(class IGameEvent __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::FireGameEvent(CBaseClient *this, IGameEvent *event)
{
  unsigned __int8 v4; // al
  const char *v5; // eax
  const char *v6; // eax
  char buffer_data[1024]; // [esp+Ch] [ebp-450h] BYREF
  SVC_GameEvent eventMsg; // [esp+40Ch] [ebp-50h] BYREF
  INetChannel_vtbl *eventa; // [esp+464h] [ebp+8h]

  eventMsg.m_bReliable = true;
  eventMsg.m_NetChannel = nullptr;
  eventMsg.__vftable = (SVC_GameEvent_vtbl *)&SVC_GameEvent::`vftable';
  eventMsg.m_DataIn.m_bOverflow = false;
  eventMsg.m_DataIn.m_pDebugName = nullptr;
  eventMsg.m_DataIn.m_nDataBits = -1;
  eventMsg.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &eventMsg.m_DataOut);
  bf_write::StartWriting(this: &eventMsg.m_DataOut, pData: buffer_data, nBytes: 1024, iStartBit: 0, nBits: -1);
  if ( g_GameEventManager->SerializeEvent(this: g_GameEventManager, a2: event, a3: &eventMsg.m_DataOut) )
  {
    if ( this->m_NetChannel != nullptr )
    {
      eventa = this->m_NetChannel->__vftable;
      v4 = ((int (__thiscall *)(IGameEvent *, _DWORD))event->IsReliable)(a1: event, a2: 0);
      ((void (__thiscall *)(INetChannel *, SVC_GameEvent *, _DWORD))eventa->SendNetMsg)(
        a1: this->m_NetChannel,
        a2: &eventMsg,
        a3: v4);
      v5 = event->GetName(this: event);
      if ( _V_stricmp(s1: v5, s2: "server_pre_shutdown") == 0 )
        this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
    }
  }
  else
  {
    v6 = event->GetName(this: event);
    DevMsg(a1: "GameEventManager: failed to serialize event '%s'.\n", v6);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118180
// Name: public: virtual bool CBaseClient::ProcessSplitPlayerConnect(class CLC_SplitPlayerConnect __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::ProcessSplitPlayerConnect(CBaseClient *this, CLC_SplitPlayerConnect *msg)
{
  int v3; // edi
  int *p_m_nSplitScreenPlayerSlot; // eax
  CBaseClient *SplitClient; // esi
  unsigned int reqID; // ecx
  INetChannel *m_NetChannel; // edx
  void **v9; // [esp+8h] [ebp-1Ch] BYREF
  char v10; // [esp+Ch] [ebp-18h]
  int v11; // [esp+10h] [ebp-14h]
  int v12; // [esp+18h] [ebp-Ch]
  int v13; // [esp+1Ch] [ebp-8h]
  int m_nEntityIndex; // [esp+20h] [ebp-4h]

  v3 = 1;
  if ( host_state.max_splitscreen_players <= 1 )
    goto LABEL_7;
  p_m_nSplitScreenPlayerSlot = &this->m_nSplitScreenPlayerSlot;
  while ( *p_m_nSplitScreenPlayerSlot != 0 )
  {
    ++v3;
    ++p_m_nSplitScreenPlayerSlot;
    if ( v3 >= host_state.max_splitscreen_players )
      goto LABEL_7;
  }
  if ( v3 == -1 )
  {
LABEL_7:
    _Warning(a1: "no more split screen slots!\n");
    (*(void (__cdecl **)(char *, const char *))(*((_DWORD *)this - 1) + 52))(
      a1: (char *)this - 4,
      a2: "No more split screen slots!");
    return 1;
  }
  else
  {
    SplitClient = CBaseServer::CreateSplitClient(
                    this: &sv,
                    vecUserInfo: &msg->m_UserInfo,
                    pAttachedTo: (CBaseClient *)((char *)this - 8));
    if ( SplitClient != nullptr )
    {
      SplitClient->m_nSplitScreenPlayerSlot = v3;
      *((_DWORD *)&this->m_bSplitScreenUser + v3) = SplitClient;
      reqID = this->m_nCustomFiles[3].reqID;
      m_nEntityIndex = SplitClient->m_nEntityIndex;
      m_NetChannel = SplitClient->m_NetChannel;
      v11 = 0;
      v12 = 0;
      v10 = 1;
      v9 = &SVC_SplitScreen::`vftable';
      v13 = v3;
      (*(void (__thiscall **)(unsigned int, int, INetChannel *))(*(_DWORD *)reqID + 288))(
        a1: reqID,
        a2: v3,
        a3: m_NetChannel);
      (*(void (__thiscall **)(char *, void ***, int, _DWORD))(*((_DWORD *)this - 1) + 116))(
        a1: (char *)this - 4,
        a2: &v9,
        a3: 1,
        a4: 0);
      if ( SplitClient->m_pAttachedTo->IsActive(this: &SplitClient->m_pAttachedTo->IClient) )
        SplitClient->ActivatePlayer(this: SplitClient);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118270
// Name: public: void CBaseClient::SplitScreenDisconnect(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SplitScreenDisconnect(CBaseClient *this, const CCommand *args)
{
  int v3; // eax
  CBaseClient *v4; // eax

  v3 = 1;
  if ( args->m_nArgc > 1 )
  {
    v3 = V_atoi(str: args->m_ppArgv[1]);
    if ( v3 <= 0 )
      v3 = 1;
  }
  v4 = this->m_SplitScreenUsers[v3];
  if ( v4 != nullptr )
    CBaseClient::DisconnectSplitScreenUser(this, pSplitClient: v4);
}

//------------------------------------------------------------------------------
// Address: 0x10118480
// Name: public: virtual char const __near * CBaseClient::GetClientName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseClient::GetClientName(CBaseClient *this)
{
  return (const char *)&this->m_UserID;
}

//------------------------------------------------------------------------------
// Address: 0x10118490
// Name: public: virtual class INetChannel __near * CBaseClient::GetNetChannel(void)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CBaseClient::GetNetChannel(CBaseClient *this)
{
  return (INetChannel *)this->m_nFilesDownloaded;
}

//------------------------------------------------------------------------------
// Address: 0x101184A0
// Name: public: virtual class IServer __near * CBaseClient::GetServer(void)
// Source: json
//------------------------------------------------------------------------------
IServer *__thiscall CBaseClient::GetServer(CBaseClient *this)
{
  return *(IServer **)&this->m_bConVarsChanged;
}

//------------------------------------------------------------------------------
// Address: 0x101184B0
// Name: public: virtual bool CBaseClient::IsConnected(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClient::IsConnected(CBaseClient *this)
{
  return (int)this->m_NetChannel >= 2;
}

//------------------------------------------------------------------------------
// Address: 0x101184C0
// Name: public: virtual bool CBaseClient::IsSpawned(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClient::IsSpawned(CBaseClient *this)
{
  return (int)this->m_NetChannel >= 3;
}

//------------------------------------------------------------------------------
// Address: 0x101184D0
// Name: public: virtual bool CBaseClient::IsActive(void)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClient::IsActive(CBaseClient *this)
{
  return this->m_NetChannel == (INetChannel *)6;
}

//------------------------------------------------------------------------------
// Address: 0x101184F0
// Name: public: virtual bool CBaseClient::IsHLTV(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsHLTV(CBaseClient *this)
{
  return (bool)this->m_Server;
}

//------------------------------------------------------------------------------
// Address: 0x10118500
// Name: public: virtual bool CBaseClient::IsLowViolenceClient(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsLowViolenceClient(CBaseClient *this)
{
  return BYTE2(this->m_nForceWaitForTick);
}

//------------------------------------------------------------------------------
// Address: 0x10118510
// Name: public: virtual bool CBaseClient::IsSplitScreenUser(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::IsSplitScreenUser(CBaseClient *this)
{
  return this->m_nDebugID;
}

//------------------------------------------------------------------------------
// Address: 0x10118520
// Name: public: virtual class IClient __near * CBaseClient::GetSplitScreenOwner(void)
// Source: json
//------------------------------------------------------------------------------
IClient *__thiscall CBaseClient::GetSplitScreenOwner(CBaseClient *this)
{
  CBaseClient *v1; // eax

  v1 = this->m_SplitScreenUsers[1];
  if ( v1 != nullptr )
    return &v1->IClient;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10118530
// Name: public: CBaseClient::CBaseClient(void)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseClient::CBaseClient(CBaseClient *this)
{
  this->IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&IClient::`vftable';
  this->IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&IClientMessageHandler::`vftable';
  this->IGameEventListener2::__vftable = (CBaseClient_vtbl *)&CBaseClient::`vftable'{for `IGameEventListener2'};
  this->IClient::INetChannelHandler::__vftable = (IClient_vtbl *)&CBaseClient::`vftable'{for `IClient'};
  this->IClientMessageHandler::INetMessageHandler::__vftable = (IClientMessageHandler_vtbl *)&CBaseClient::`vftable'{for `IClientMessageHandler'};
  *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_SteamID.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamID.m_steamid.m_comp + 1) &= 0xFFF00000;
  *(_DWORD *)&this->m_SteamID.m_steamid.m_comp = 0;
  this->m_pLastSnapshot.m_pObj = nullptr;
  if ( this != (CBaseClient *)-256 )
    memset(dst: (unsigned __int8 *)&this->m_BaselinesSent, value: 0, count: sizeof(this->m_BaselinesSent));
  this->m_Trace.m_nMinWarningBytes = 0;
  this->m_Trace.m_nStartBit = 0;
  this->m_Trace.m_nCurBit = 0;
  this->m_Trace.m_Records.m_Memory.m_pMemory = nullptr;
  this->m_Trace.m_Records.m_Memory.m_nAllocationCount = 0;
  this->m_Trace.m_Records.m_Memory.m_nGrowSize = 0;
  this->m_Trace.m_Records.m_Size = 0;
  this->m_Trace.m_Records.m_pElements = nullptr;
  this->m_NetChannel = nullptr;
  this->m_ConVars = nullptr;
  this->m_Server = nullptr;
  this->m_pBaseline = nullptr;
  this->m_bIsHLTV = false;
  *(_WORD *)&this->m_bConVarsChanged = 0;
  this->m_bFullyAuthenticated = false;
  this->m_nSignonState = 0;
  *(_WORD *)&this->m_bSplitScreenUser = 0;
  this->m_bSplitPlayerDisconnecting = false;
  this->m_nSplitScreenPlayerSlot = 0;
  this->m_pAttachedTo = nullptr;
  _V_memset(dest: this->m_SplitScreenUsers, fill: 0, count: 8);
  this->m_SplitScreenUsers[0] = this;
  this->m_ClientPlatform = CROSSPLAYPLATFORM_PC;
  this->m_nDebugID = 42;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10118660
// Name: public: virtual void CBaseClient::ConnectionStart(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::ConnectionStart(CBaseClient *this, INetChannel *chan)
{
  INetMessage *v3; // eax
  IClient *v4; // ebx
  IClient *v5; // ecx
  INetMessage *v6; // eax
  IClient *v7; // ecx
  INetMessage *v8; // eax
  IClient *v9; // ecx
  INetMessage *v10; // eax
  IClient *v11; // ecx
  NET_SplitScreenUser *v12; // eax
  NET_SplitScreenUser *v13; // eax
  IClient *v14; // ecx
  INetMessage *v15; // eax
  IClient *v16; // ecx
  char *v17; // eax
  INetMessage *v18; // edi
  IClient *v19; // eax
  char *v20; // eax
  INetMessage *v21; // edi
  INetMessage *v22; // eax
  IClient *v23; // ecx
  INetMessage *v24; // eax
  IClient *v25; // ecx
  _BYTE *v26; // edi
  INetMessage *v27; // eax
  IClient *v28; // ecx
  INetMessage *v29; // eax
  IClient *v30; // ecx
  INetMessage *v31; // eax
  IClient *v32; // ecx
  INetMessage *v33; // eax
  IClient *v34; // ecx
  INetMessage *v35; // eax
  IClient *v36; // ecx
  CLC_CmdKeyValues *v37; // eax
  CLC_CmdKeyValues *v38; // eax

  v3 = (INetMessage *)calloc(count: 1u, size: 0x1Cu);
  v4 = nullptr;
  if ( v3 != nullptr )
  {
    v3[2].__vftable = nullptr;
    v3->__vftable = (INetMessage_vtbl *)&NET_Tick::`vftable';
    LOBYTE(v3[1].__vftable) = 0;
    v3[5].__vftable = nullptr;
    v3[6].__vftable = nullptr;
  }
  else
  {
    v3 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v5 = nullptr;
  else
    v5 = &this->IClient;
  v3[3].__vftable = (INetMessage_vtbl *)v5;
  chan->RegisterMessage(this: chan, a2: v3);
  v6 = (INetMessage *)calloc(count: 1u, size: 0x414u);
  if ( v6 != nullptr )
  {
    LOBYTE(v6[1].__vftable) = 1;
    v6[2].__vftable = nullptr;
    v6->__vftable = (INetMessage_vtbl *)&NET_StringCmd::`vftable';
    v6[4].__vftable = nullptr;
  }
  else
  {
    v6 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v7 = nullptr;
  else
    v7 = &this->IClient;
  v6[3].__vftable = (INetMessage_vtbl *)v7;
  chan->RegisterMessage(this: chan, a2: v6);
  v8 = (INetMessage *)calloc(count: 1u, size: 0x24u);
  if ( v8 != nullptr )
  {
    LOBYTE(v8[1].__vftable) = 1;
    v8[2].__vftable = nullptr;
    v8->__vftable = (INetMessage_vtbl *)&NET_SetConVar::`vftable';
    v8[4].__vftable = nullptr;
    v8[5].__vftable = nullptr;
    v8[6].__vftable = nullptr;
    v8[7].__vftable = nullptr;
    v8[8].__vftable = nullptr;
  }
  else
  {
    v8 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v9 = nullptr;
  else
    v9 = &this->IClient;
  v8[3].__vftable = (INetMessage_vtbl *)v9;
  chan->RegisterMessage(this: chan, a2: v8);
  v10 = (INetMessage *)calloc(count: 1u, size: 0x44u);
  if ( v10 != nullptr )
  {
    LOBYTE(v10[1].__vftable) = 1;
    v10[2].__vftable = nullptr;
    v10->__vftable = (INetMessage_vtbl *)&NET_SignonState::`vftable';
    v10[7].__vftable = nullptr;
    v10[8].__vftable = nullptr;
    v10[9].__vftable = nullptr;
    v10[10].__vftable = nullptr;
    v10[11].__vftable = nullptr;
    v10[12].__vftable = nullptr;
    v10[13].__vftable = nullptr;
    v10[14].__vftable = nullptr;
    v10[15].__vftable = nullptr;
    v10[16].__vftable = nullptr;
  }
  else
  {
    v10 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v11 = nullptr;
  else
    v11 = &this->IClient;
  v10[3].__vftable = (INetMessage_vtbl *)v11;
  chan->RegisterMessage(this: chan, a2: v10);
  v12 = (NET_SplitScreenUser *)calloc(count: 1u, size: 0x14u);
  if ( v12 != nullptr )
    v13 = NET_SplitScreenUser::NET_SplitScreenUser(this: v12);
  else
    v13 = nullptr;
  if ( this == (CBaseClient *)4 )
    v14 = nullptr;
  else
    v14 = &this->IClient;
  v13->m_pMessageHandler = (INetMessageHandler *)v14;
  chan->RegisterMessage(this: chan, a2: v13);
  v15 = (INetMessage *)calloc(count: 1u, size: 0x50u);
  if ( v15 != nullptr )
  {
    LOBYTE(v15[1].__vftable) = 1;
    v15[2].__vftable = nullptr;
    v15->__vftable = (INetMessage_vtbl *)&CLC_ClientInfo::`vftable';
  }
  else
  {
    v15 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v16 = nullptr;
  else
    v16 = &this->IClient;
  v15[3].__vftable = (INetMessage_vtbl *)v16;
  chan->RegisterMessage(this: chan, a2: v15);
  v17 = (char *)calloc(count: 1u, size: 0x58u);
  v18 = (INetMessage *)v17;
  if ( v17 != nullptr )
  {
    v17[4] = 1;
    *((_DWORD *)v17 + 2) = 0;
    *(_DWORD *)v17 = &CLC_Move::`vftable';
    v17[32] = 0;
    *((_DWORD *)v17 + 7) = 0;
    *((_DWORD *)v17 + 9) = -1;
    *((_DWORD *)v17 + 10) = 0;
    bf_write::bf_write(this: (bf_write *)(v17 + 64));
    LOBYTE(v18[1].__vftable) = 0;
  }
  else
  {
    v18 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v19 = nullptr;
  else
    v19 = &this->IClient;
  v18[3].__vftable = (INetMessage_vtbl *)v19;
  chan->RegisterMessage(this: chan, a2: v18);
  v20 = (char *)calloc(count: 1u, size: 0x58u);
  v21 = (INetMessage *)v20;
  if ( v20 != nullptr )
  {
    v20[4] = 1;
    *((_DWORD *)v20 + 2) = 0;
    *(_DWORD *)v20 = &CLC_VoiceData::`vftable';
    v20[24] = 0;
    *((_DWORD *)v20 + 5) = 0;
    *((_DWORD *)v20 + 7) = -1;
    *((_DWORD *)v20 + 8) = 0;
    bf_write::bf_write(this: (bf_write *)(v20 + 56));
    LOBYTE(v21[1].__vftable) = 0;
    v21[20].__vftable = nullptr;
    v21[21].__vftable = nullptr;
    v22 = v21;
  }
  else
  {
    v22 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v23 = nullptr;
  else
    v23 = &this->IClient;
  v22[3].__vftable = (INetMessage_vtbl *)v23;
  chan->RegisterMessage(this: chan, a2: v22);
  v24 = (INetMessage *)calloc(count: 1u, size: 0x18u);
  if ( v24 != nullptr )
  {
    LOBYTE(v24[1].__vftable) = 1;
    v24[2].__vftable = nullptr;
    v24->__vftable = (INetMessage_vtbl *)&CLC_BaselineAck::`vftable';
  }
  else
  {
    v24 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v25 = nullptr;
  else
    v25 = &this->IClient;
  v24[3].__vftable = (INetMessage_vtbl *)v25;
  chan->RegisterMessage(this: chan, a2: v24);
  v26 = calloc(count: 1u, size: 0x50u);
  if ( v26 != nullptr )
  {
    v26[4] = 1;
    *((_DWORD *)v26 + 2) = 0;
    *(_DWORD *)v26 = &CLC_ListenEvents::`vftable';
    if ( v26 != (_BYTE *)-16 )
      memset(dst: v26 + 16, value: 0, count: 0x40u);
    v27 = (INetMessage *)v26;
  }
  else
  {
    v27 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v28 = nullptr;
  else
    v28 = &this->IClient;
  v27[3].__vftable = (INetMessage_vtbl *)v28;
  chan->RegisterMessage(this: chan, a2: v27);
  v29 = (INetMessage *)calloc(count: 1u, size: 0x220u);
  if ( v29 != nullptr )
  {
    LOBYTE(v29[1].__vftable) = 1;
    v29[2].__vftable = nullptr;
    v29->__vftable = (INetMessage_vtbl *)&CLC_RespondCvarValue::`vftable';
  }
  else
  {
    v29 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v30 = nullptr;
  else
    v30 = &this->IClient;
  v29[3].__vftable = (INetMessage_vtbl *)v30;
  chan->RegisterMessage(this: chan, a2: v29);
  v31 = (INetMessage *)calloc(count: 1u, size: 0x21Cu);
  if ( v31 != nullptr )
  {
    LOBYTE(v31[1].__vftable) = 1;
    v31[2].__vftable = nullptr;
    v31->__vftable = (INetMessage_vtbl *)&CLC_FileCRCCheck::`vftable';
  }
  else
  {
    v31 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v32 = nullptr;
  else
    v32 = &this->IClient;
  v31[3].__vftable = (INetMessage_vtbl *)v32;
  chan->RegisterMessage(this: chan, a2: v31);
  v33 = (INetMessage *)calloc(count: 1u, size: 0x24u);
  if ( v33 != nullptr )
  {
    LOBYTE(v33[1].__vftable) = 1;
    v33[2].__vftable = nullptr;
    v33->__vftable = (INetMessage_vtbl *)&CLC_SplitPlayerConnect::`vftable';
    v33[4].__vftable = nullptr;
    v33[5].__vftable = nullptr;
    v33[6].__vftable = nullptr;
    v33[7].__vftable = nullptr;
    v33[8].__vftable = nullptr;
  }
  else
  {
    v33 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v34 = nullptr;
  else
    v34 = &this->IClient;
  v33[3].__vftable = (INetMessage_vtbl *)v34;
  chan->RegisterMessage(this: chan, a2: v33);
  v35 = (INetMessage *)calloc(count: 1u, size: 0x14u);
  if ( v35 != nullptr )
  {
    LOBYTE(v35[1].__vftable) = 1;
    v35[2].__vftable = nullptr;
    v35->__vftable = (INetMessage_vtbl *)&CLC_LoadingProgress::`vftable';
  }
  else
  {
    v35 = nullptr;
  }
  if ( this == (CBaseClient *)4 )
    v36 = nullptr;
  else
    v36 = &this->IClient;
  v35[3].__vftable = (INetMessage_vtbl *)v36;
  chan->RegisterMessage(this: chan, a2: v35);
  v37 = (CLC_CmdKeyValues *)calloc(count: 1u, size: 0x14u);
  if ( v37 != nullptr )
    v38 = CLC_CmdKeyValues::CLC_CmdKeyValues(this: v37, pKeyValues: nullptr);
  else
    v38 = nullptr;
  if ( this != (CBaseClient *)4 )
    v4 = &this->IClient;
  v38->m_pMessageHandler = (IClientMessageHandler *)v4;
  chan->RegisterMessage(this: chan, a2: v38);
}

//------------------------------------------------------------------------------
// Address: 0x10118AB0
// Name: public: void CBaseClient::TraceNetworkData(class bf_write __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseClient::TraceNetworkData(CBaseClient *this, bf_write *msg, const char *fmt, ...)
{
  char buf[64]; // [esp+4h] [ebp-84h] BYREF
  Spike_t t; // [esp+44h] [ebp-44h] BYREF
  va_list params; // [esp+9Ch] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
  {
    V_vsnprintf(pDest: buf, maxLen: 64, pFormat: fmt, params);
    t.m_nBits = 0;
    t.m_szDesc[0] = 0;
    V_strncpy(pDest: t.m_szDesc, pSrc: buf, maxLen: 64);
    t.m_nBits = msg->m_iCurBit - this->m_Trace.m_nCurBit;
    CUtlVector<Spike_t,CUtlMemory<Spike_t,int>>::InsertBefore(
      this: &this->m_Trace.m_Records,
      elem: this->m_Trace.m_Records.m_Size,
      src: &t);
    this->m_Trace.m_nCurBit = msg->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118B30
// Name: public: void CBaseClient::TraceNetworkMsg(int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseClient::TraceNetworkMsg(CBaseClient *this, int nBits, const char *fmt, ...)
{
  char buf[64]; // [esp+4h] [ebp-84h] BYREF
  Spike_t t; // [esp+44h] [ebp-44h] BYREF
  va_list params; // [esp+9Ch] [ebp+14h] BYREF

  va_start(params, fmt);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
  {
    V_vsnprintf(pDest: buf, maxLen: 64, pFormat: fmt, params);
    t.m_nBits = 0;
    t.m_szDesc[0] = 0;
    V_strncpy(pDest: t.m_szDesc, pSrc: buf, maxLen: 64);
    t.m_nBits = nBits;
    CUtlVector<Spike_t,CUtlMemory<Spike_t,int>>::InsertBefore(
      this: &this->m_Trace.m_Records,
      elem: this->m_Trace.m_Records.m_Size,
      src: &t);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10118BA0
// Name: public: void CBaseClient::FillSignOnFullServerInfo(class NET_SignonState __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::FillSignOnFullServerInfo(CBaseClient *this, NET_SignonState *state)
{
  int v2; // esi
  CBaseClient *v3; // eax
  IClient *v4; // ecx
  const char *v5; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CUtlVector<char,CUtlMemory<char,int> > *p_m_PlayersNetworkIds; // esi
  char *m_pMemory; // ecx
  int v10; // eax
  char *v11; // eax
  char *v12; // edi
  const char *NewLevel; // eax
  const char *v14; // esi
  int v15; // eax
  int v16; // edi
  int v17; // eax
  char *v18; // ecx
  int v19; // eax
  char *v20; // esi

  if ( sv.m_bIsDedicatedForXbox )
  {
    v2 = 0;
    for ( state->m_numServerPlayers = sv.m_Clients.m_Size; v2 < sv.m_Clients.m_Size; ++v2 )
    {
      v3 = sv.m_Clients.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
        v4 = &v3->IClient;
      else
        v4 = nullptr;
      v5 = v4->GetNetworkIDString(this: v4);
      CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
        this: &state->m_PlayersNetworkIds,
        elem: state->m_PlayersNetworkIds.m_Size,
        num: strlen(v5) + 1,
        pToInsert: v5);
    }
    m_Size = state->m_PlayersNetworkIds.m_Size;
    m_nAllocationCount = state->m_PlayersNetworkIds.m_Memory.m_nAllocationCount;
    p_m_PlayersNetworkIds = &state->m_PlayersNetworkIds;
    if ( m_Size + 2 > m_nAllocationCount )
      CUtlMemory<bool,int>::Grow(this: &p_m_PlayersNetworkIds->m_Memory, num: m_Size - m_nAllocationCount + 2);
    state->m_PlayersNetworkIds.m_Size += 2;
    m_pMemory = p_m_PlayersNetworkIds->m_Memory.m_pMemory;
    v10 = state->m_PlayersNetworkIds.m_Size - m_Size - 2;
    state->m_PlayersNetworkIds.m_pElements = state->m_PlayersNetworkIds.m_Memory.m_pMemory;
    if ( v10 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 2], src: &m_pMemory[m_Size], count: v10);
    v11 = &p_m_PlayersNetworkIds->m_Memory.m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = 0;
    v12 = &p_m_PlayersNetworkIds->m_Memory.m_pMemory[m_Size + 1];
    if ( v12 != nullptr )
      *v12 = 0;
  }
  NewLevel = HostState_GetNewLevel();
  v14 = NewLevel;
  if ( NewLevel != nullptr )
  {
    v15 = _V_strlen(str: NewLevel);
    CUtlVector<char,CUtlMemory<char,int>>::InsertMultipleBefore(
      this: &state->m_Mapname,
      elem: state->m_Mapname.m_Size,
      num: v15,
      pToInsert: v14);
  }
  v16 = state->m_Mapname.m_Size;
  v17 = state->m_Mapname.m_Memory.m_nAllocationCount;
  if ( v16 + 1 > v17 )
    CUtlMemory<bool,int>::Grow(this: &state->m_Mapname.m_Memory, num: v16 - v17 + 1);
  ++state->m_Mapname.m_Size;
  v18 = state->m_Mapname.m_Memory.m_pMemory;
  v19 = state->m_Mapname.m_Size - v16 - 1;
  state->m_Mapname.m_pElements = v18;
  if ( v19 > 0 )
    _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: v19);
  v20 = &state->m_Mapname.m_Memory.m_pMemory[v16];
  if ( v20 != nullptr )
    *v20 = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10118CE0
// Name: public: virtual bool CBaseClient::SendNetMsg(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CBaseClient::SendNetMsg@<al>(
        CBaseClient *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        INetMessage *msg,
        int bForceReliable,
        int bVoice)
{
  int v9; // eax
  int v10; // eax
  int v11; // edi
  const char *v12; // eax
  int v14; // [esp-4h] [ebp-Ch]
  int nStartBit; // [esp+4h] [ebp-4h]
  char bret_3; // [esp+13h] [ebp+Bh]

  if ( this->m_nFilesDownloaded == 0 )
    return 1;
  v9 = ((int (__thiscall *)(INetMessage *, int))msg->IsReliable)(a1: msg, a2);
  if ( (_BYTE)v9 != 0 || (_BYTE)bForceReliable != 0 )
    v9 = 1;
  nStartBit = (*(int (__thiscall **)(int, int))(*(_DWORD *)this->m_nFilesDownloaded + 264))(
                a1: this->m_nFilesDownloaded,
                a2: v9);
  bret_3 = (*(int (__thiscall **)(int, INetMessage *, int, int))(*(_DWORD *)this->m_nFilesDownloaded + 164))(
             a1: this->m_nFilesDownloaded,
             a2: msg,
             a3: bForceReliable,
             a4: bVoice);
  if ( this->m_MegaSnapshotScratchBuffer[19999] != 0 )
  {
    v10 = ((int (__thiscall *)(INetMessage *, int))msg->IsReliable)(a1: msg, a2: v14);
    if ( (_BYTE)v10 != 0 || (_BYTE)bForceReliable != 0 )
      v10 = 1;
    v11 = (*(int (__thiscall **)(int, int, int))(*(_DWORD *)this->m_nFilesDownloaded + 264))(
            a1: this->m_nFilesDownloaded,
            a2: v10,
            a3)
        - nStartBit;
    v12 = msg->ToString(this: msg);
    CBaseClient::TraceNetworkMsg(this: (CBaseClient *)((char *)this - 4), nBits: v11, fmt: "NetMessage %s", v12);
  }
  return bret_3;
}

//------------------------------------------------------------------------------
// Address: 0x10118DB0
// Name: public: virtual void CBaseClient::Reconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::Reconnect(CBaseClient *this)
{
  char v2; // al
  CBaseClient_vtbl *v3; // edx
  void (__thiscall *WriteGameSounds)(CBaseClient *, bf_write *, int); // eax
  INetChannel *m_NetChannel; // eax
  NET_SignonState signon; // [esp+Ch] [ebp-48h] BYREF
  char v7; // [esp+53h] [ebp-1h]

  ConMsg(a1: "Forcing client reconnect (%i)\n", this->m_NetChannel);
  (*(void (__thiscall **)(int))(*(_DWORD *)this->m_nFilesDownloaded + 144))(a1: this->m_nFilesDownloaded);
  v2 = ((int (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].WriteGameSounds)(a1: this);
  v3 = this->IGameEventListener2::__vftable;
  v7 = v2;
  WriteGameSounds = v3[1].WriteGameSounds;
  this->m_NetChannel = (INetChannel *)2;
  if ( v7 != ((unsigned __int8 (__thiscall *)(CBaseClient *))WriteGameSounds)(a1: this)
    && (!this->IGameEventListener2::__vftable[1].SendServerInfo(this)
     || ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) != 0) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  m_NetChannel = this->m_NetChannel;
  signon.m_bReliable = true;
  signon.m_NetChannel = nullptr;
  signon.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  signon.m_nSignonState = (int)m_NetChannel;
  signon.m_nSpawnCount = -1;
  memset(&signon.m_numServerPlayers, 0, 44);
  CBaseClient::FillSignOnFullServerInfo(this: (CBaseClient *)((char *)this - 4), state: &signon);
  (*(void (__thiscall **)(int, NET_SignonState *, _DWORD, _DWORD))(*(_DWORD *)this->m_nFilesDownloaded + 164))(
    a1: this->m_nFilesDownloaded,
    a2: &signon,
    a3: 0,
    a4: 0);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signon.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signon.m_PlayersNetworkIds);
}

//------------------------------------------------------------------------------
// Address: 0x10118EB0
// Name: public: virtual void CBaseClient::Inactivate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::Inactivate(CBaseClient *this)
{
  void (__thiscall *v2)(char *); // edx
  char *v3; // ebx
  CFrameSnapshot *m_nSignonTick; // ecx
  char *v5; // ebx
  char v6; // al
  int v7; // edx
  int m_nFilesDownloaded; // ecx
  INetChannel *m_NetChannel; // ebx
  int v10; // eax
  NET_SignonState signon; // [esp+Ch] [ebp-4Ch] BYREF
  CBaseClient *v12; // [esp+50h] [ebp-8h]
  char v13; // [esp+57h] [ebp-1h]

  v2 = *(void (__thiscall **)(char *))(*((_DWORD *)this - 1) + 72);
  v3 = (char *)this - 4;
  v12 = (CBaseClient *)((char *)this - 4);
  v2(a1: (char *)this - 4);
  this->m_nSignonState = -1;
  this->m_nStringTableAckTick = 0;
  this->m_nDeltaTick = 0;
  m_nSignonTick = (CFrameSnapshot *)this->m_nSignonTick;
  if ( m_nSignonTick != nullptr )
  {
    CFrameSnapshot::ReleaseReference(this: m_nSignonTick);
    this->m_nSignonTick = 0;
  }
  v5 = v3 + 4;
  this->m_nBaselineUsed = -1;
  v6 = (*(int (__thiscall **)(char *))(*(_DWORD *)v5 + 124))(a1: v5);
  v7 = *(_DWORD *)v5;
  v13 = v6;
  v12->m_nSignonState = 7;
  if ( v13 != (*(unsigned __int8 (__thiscall **)(char *))(v7 + 124))(a1: v5)
    && ((*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)v5 + 136))(a1: v5) == 0
     || (*(unsigned __int8 (__thiscall **)(char *))(*(_DWORD *)v5 + 156))(a1: v5) != 0) )
  {
    CGameServer::UpdateHibernationState(this: &sv);
  }
  m_nFilesDownloaded = this->m_nFilesDownloaded;
  if ( m_nFilesDownloaded != 0 )
  {
    (*(void (__thiscall **)(int))(*(_DWORD *)m_nFilesDownloaded + 144))(a1: m_nFilesDownloaded);
    if ( NET_IsMultiplayer()
      && ((unsigned __int8 (__thiscall *)(CBaseClient *))this->IGameEventListener2::__vftable[1].SetUserCVar)(a1: this) == 0 )
    {
      m_NetChannel = this->m_NetChannel;
      v10 = (*(int (__thiscall **)(_DWORD))(**(_DWORD **)&this->m_bConVarsChanged + 60))(a1: *(_DWORD *)&this->m_bConVarsChanged);
      signon.m_bReliable = true;
      signon.m_NetChannel = nullptr;
      signon.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
      signon.m_nSignonState = (int)m_NetChannel;
      signon.m_nSpawnCount = v10;
      memset(&signon.m_numServerPlayers, 0, 44);
      CBaseClient::FillSignOnFullServerInfo(this: v12, state: &signon);
      ((void (__thiscall *)(CBaseClient *, NET_SignonState *, _DWORD, _DWORD))this->IGameEventListener2::__vftable[1].FillUserInfo)(
        a1: this,
        a2: &signon,
        a3: 0,
        a4: 0);
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)this->m_nFilesDownloaded + 192))(
        a1: this->m_nFilesDownloaded,
        a2: 0);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signon.m_Mapname);
      CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signon.m_PlayersNetworkIds);
    }
  }
  g_GameEventManager->RemoveListener(this: g_GameEventManager, a2: v12);
}

//------------------------------------------------------------------------------
// Address: 0x10119030
// Name: public: virtual void CBaseClient::SpawnPlayer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::SpawnPlayer(CBaseClient *this)
{
  bool (__thiscall *SendNetMsg)(IClient *, INetMessage *, bool, bool); // edx
  bool (__thiscall *IsConnected)(IClient *); // edx
  char v4; // al
  CBaseServer *m_Server; // ecx
  CBaseServer_vtbl *v6; // edx
  int v7; // eax
  NET_SignonState signonState; // [esp+Ch] [ebp-68h] BYREF
  NET_Tick tick; // [esp+50h] [ebp-24h] BYREF
  int m_nSignonState; // [esp+6Ch] [ebp-8h]
  char v11; // [esp+73h] [ebp-1h]

  _COM_TimestampedLog(a1: "CBaseClient::SpawnPlayer");
  if ( !this->IsFakeClient(this: &this->IClient) )
  {
    this->FreeBaselines(this);
    this->m_pBaseline = CFrameSnapshotManager::CreateEmptySnapshot(
                          this: framesnapshotmanager,
                          tickcount: 0,
                          maxEntities: 2048);
  }
  tick.m_nTick = this->m_Server->GetTick(this: this->m_Server);
  SendNetMsg = this->SendNetMsg;
  tick.m_flHostFrameTime = host_frametime_unbounded;
  tick.m_NetChannel = nullptr;
  tick.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  tick.m_bReliable = false;
  tick.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
  SendNetMsg(this: &this->IClient, a2: &tick, a3: true, a4: false);
  v11 = this->IsConnected(this: &this->IClient);
  IsConnected = this->IsConnected;
  this->m_nSignonState = 5;
  v4 = IsConnected(this: &this->IClient);
  if ( v11 != v4 && (!this->IsFakeClient(this: &this->IClient) || this->IsSplitScreenUser(this: &this->IClient)) )
    CGameServer::UpdateHibernationState(this: &sv);
  m_Server = this->m_Server;
  v6 = m_Server->__vftable;
  m_nSignonState = this->m_nSignonState;
  v7 = v6->GetSpawnCount(this: m_Server);
  signonState.m_nSignonState = m_nSignonState;
  signonState.m_bReliable = true;
  signonState.m_NetChannel = nullptr;
  signonState.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  signonState.m_nSpawnCount = v7;
  memset(&signonState.m_numServerPlayers, 0, 44);
  CBaseClient::FillSignOnFullServerInfo(this, state: &signonState);
  this->SendNetMsg(this: &this->IClient, a2: &signonState, a3: false, a4: false);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signonState.m_Mapname);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signonState.m_PlayersNetworkIds);
}

//------------------------------------------------------------------------------
// Address: 0x101191A0
// Name: public: virtual bool CBaseClient::SendSignonData(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClient::SendSignonData(CBaseClient *this)
{
  IEngineVGuiInternal *v2; // eax
  CBaseServer *m_Server; // eax
  int m_nSignonState; // edi
  int v6; // eax
  bool v7; // bl
  NET_SignonState signonState; // [esp+8h] [ebp-44h] BYREF

  _COM_TimestampedLog(a1: " CBaseClient::SendSignonData");
  v2 = EngineVGui();
  v2->UpdateProgressBar(this: v2, a2: PROGRESS_SENDSIGNONDATA, a3: false);
  m_Server = this->m_Server;
  if ( m_Server->m_Signon.m_bOverflow )
  {
    Host_Error(error: "Signon buffer overflowed %i bytes!!!\n", (m_Server->m_Signon.m_iCurBit + 7) >> 3);
    return false;
  }
  else
  {
    this->m_NetChannel->SendData(this: this->m_NetChannel, a2: &m_Server->m_Signon, a3: true);
    S_PreventSound(bSetting: false);
    CBaseClient::SetSignonState(this, nState: 4);
    m_nSignonState = this->m_nSignonState;
    v6 = this->m_Server->GetSpawnCount(this: this->m_Server);
    signonState.m_bReliable = true;
    signonState.m_NetChannel = nullptr;
    signonState.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
    signonState.m_nSignonState = m_nSignonState;
    signonState.m_nSpawnCount = v6;
    memset(&signonState.m_numServerPlayers, 0, 44);
    CBaseClient::FillSignOnFullServerInfo(this, state: &signonState);
    v7 = this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &signonState, a3: false, a4: false);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signonState.m_Mapname);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&signonState.m_PlayersNetworkIds);
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101192B0
// Name: public: virtual bool CBaseClient::SendServerInfo(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClient::SendServerInfo(CBaseClient *this)
{
  IClient *v2; // edi
  const char *v3; // eax
  void *v4; // eax
  int (*GetSpawnCount)(void); // eax
  int v6; // eax
  int v7; // eax
  const char *v8; // eax
  CBaseServer *v9; // ecx
  KeyValues *v10; // eax
  IMatchEventsSubscription *v11; // eax
  int m_nTickCount; // edx
  const char *v13; // eax
  bool (__thiscall *IsConnected)(IClient *); // eax
  bool v15; // al
  IClient_vtbl *v16; // edx
  bool (__thiscall *v17)(IClient *); // eax
  char v18; // al
  int v19; // eax
  const char *v21; // [esp-18h] [ebp-1540h]
  int v22; // [esp-14h] [ebp-153Ch]
  int v23; // [esp-10h] [ebp-1538h]
  int v24; // [esp-Ch] [ebp-1534h]
  int v25; // [esp-8h] [ebp-1530h]
  int v26; // [esp-4h] [ebp-152Ch]
  int v27; // [esp-4h] [ebp-152Ch]
  int v28; // [esp-4h] [ebp-152Ch]
  char pDest[2048]; // [esp+Ch] [ebp-151Ch] BYREF
  SVC_Print v30; // [esp+80Ch] [ebp-D1Ch] BYREF
  SVC_ServerInfo v31; // [esp+1020h] [ebp-508h] BYREF
  NET_Tick v32; // [esp+1478h] [ebp-B0h] BYREF
  NET_SetConVar v33; // [esp+1494h] [ebp-94h] BYREF
  NET_SignonState state; // [esp+14B8h] [ebp-70h] BYREF
  bf_write buffer; // [esp+14FCh] [ebp-2Ch] BYREF
  int nBots; // [esp+1514h] [ebp-14h] BYREF
  int nMaxHumanSlots; // [esp+1518h] [ebp-10h] BYREF
  int nHumans; // [esp+151Ch] [ebp-Ch] BYREF
  CBaseServer *m_Server; // [esp+1520h] [ebp-8h]
  char v40; // [esp+1527h] [ebp-1h]

  v2 = &this->IClient;
  v3 = (const char *)((int (__thiscall *)(IClient *, int))this->GetClientName)(
                       a1: &this->IClient,
                       a2: this->m_nSignonState);
  _COM_TimestampedLog(a1: " CBaseClient::SendServerInfo: %s  :  %d", v3, v26);
  v4 = (void *)_MemAllocScratch(a1: 96000);
  bf_write::bf_write(this: &buffer, pDebugName: "SV_SendServerinfo->msg", pData: v4, nBytes: 96000, nBits: -1);
  if ( developer.m_pParent != nullptr && developer.m_pParent->m_Value.m_nValue != 0
    || this->m_Server->IsMultiplayer(this: this->m_Server) )
  {
    CBaseServer::GetMasterServerPlayerCounts(this: &sv, &nHumans, &nMaxHumanSlots, &nBots);
    GetSpawnCount = (int (*)(void))this->m_Server->GetSpawnCount;
    m_Server = this->m_Server;
    v27 = GetSpawnCount();
    v6 = build_number();
    v7 = ((int (__thiscall *)(CBaseServer *, int, int, int, int, int))m_Server->GetMapName)(
           a1: m_Server,
           a2: nHumans,
           a3: nBots,
           a4: nMaxHumanSlots,
           a5: v6,
           a6: v27);
    v8 = (const char *)((int (__thiscall *)(IServerGameDLL *, int))serverGameDLL->GetGameDescription)(
                         a1: serverGameDLL,
                         a2: v7);
    V_snprintf(
      pDest,
      maxLen: 2048,
      pFormat: "\n%s\nMap: %s\nPlayers: %i (%i bots) / %i humans\nBuild: %d\nServer Number: %i\n\n",
      v8,
      v21,
      v22,
      v23,
      v24,
      v25,
      v28);
    v30.m_NetChannel = nullptr;
    v30.__vftable = (SVC_Print_vtbl *)&SVC_Print::`vftable';
    v30.m_bReliable = false;
    v30.m_szText = pDest;
    SVC_Print::WriteToBuffer(this: &v30, &buffer);
  }
  v31.m_nPlayerSlot = this->m_nClientSlot;
  v9 = this->m_Server;
  v31.m_bReliable = true;
  v31.m_NetChannel = nullptr;
  v31.__vftable = (SVC_ServerInfo_vtbl *)&SVC_ServerInfo::`vftable';
  v9->FillServerInfo(this: v9, a2: &v31);
  SVC_ServerInfo::WriteToBuffer(this: &v31, &buffer);
  if ( g_pMatchFramework != nullptr && CBaseServer::GetReservationCookie(this: &sv) == 0 )
  {
    v10 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v10 != nullptr )
      m_Server = (CBaseServer *)KeyValues::KeyValues(this: v10, setName: "OnEngineListenServerStarted");
    else
      m_Server = nullptr;
    v11 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v11->BroadcastEvent(this: v11, a2: (KeyValues *)m_Server);
  }
  m_nTickCount = this->m_Server->m_nTickCount;
  this->m_nSignonTick = m_nTickCount;
  v32.m_NetChannel = nullptr;
  v32.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  v32.m_bReliable = false;
  v32.m_nTick = m_nTickCount;
  v32.m_flHostFrameTime = 0.0;
  v32.m_flHostFrameTimeStdDeviation = 0.0;
  NET_Tick::WriteToBuffer(this: &v32, &buffer);
  if ( !this->m_NetChannel->IsLoopback(this: this->m_NetChannel) )
  {
    v33.m_bReliable = true;
    v33.m_NetChannel = nullptr;
    v33.__vftable = (NET_SetConVar_vtbl *)&NET_SetConVar::`vftable';
    memset(&v33.m_ConVars, 0, sizeof(v33.m_ConVars));
    Host_BuildConVarUpdateMessage(rCvarList: &v33.m_ConVars, flags: 0x2000, nonDefault: true);
    NET_SetConVar::WriteToBuffer(this: &v33, &buffer);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&v33.m_ConVars);
  }
  v13 = this->m_Server->GetMapName(this: this->m_Server);
  CNetworkStringTableContainer::WriteBaselines(
    this: this->m_Server->m_StringTables,
    pchMapName: (signed int)v13,
    buf: &buffer);
  IsConnected = v2->IsConnected;
  this->m_bSendServerInfo = false;
  v15 = IsConnected(this: v2);
  v16 = v2->__vftable;
  v40 = v15;
  v17 = v16->IsConnected;
  this->m_nSignonState = 3;
  v18 = v17(this: v2);
  if ( v40 != v18 && (!v2->IsFakeClient(this: v2) || v2->IsSplitScreenUser(this: v2)) )
    CGameServer::UpdateHibernationState(this: &sv);
  nHumans = this->m_nSignonState;
  v19 = this->m_Server->GetSpawnCount(this: this->m_Server);
  state.m_nSignonState = nHumans;
  state.m_bReliable = true;
  state.m_NetChannel = nullptr;
  state.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
  state.m_nSpawnCount = v19;
  memset(&state.m_numServerPlayers, 0, 44);
  CBaseClient::FillSignOnFullServerInfo(this, &state);
  NET_SignonState::WriteToBuffer(this: &state, &buffer);
  if ( this->m_NetChannel->SendData(this: this->m_NetChannel, a2: &buffer, a3: true) )
  {
    _COM_TimestampedLog(a1: " CBaseClient::SendServerInfo(finished)");
    _MemFreeScratch();
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_Mapname);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_PlayersNetworkIds);
    return 1;
  }
  else
  {
    _MemFreeScratch();
    v2->Disconnect(this: v2, a2: "Server info data overflow");
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_Mapname);
    CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&state.m_PlayersNetworkIds);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119670
// Name: private: void CBaseClient::EndTrace(class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClient::EndTrace(CBaseClient *this, bf_write *msg)
{
  int m_nMinWarningBytes; // eax
  int v4; // ebx
  CNetChan *m_NetChannel; // edi
  int m_iCurBit; // ebx
  int v7; // edi
  INetChannel *v8; // eax
  int v9; // eax
  int v10; // eax
  const char *v11; // eax
  int v12; // edi
  int v13; // ebx
  Spike_t *m_pMemory; // eax
  bool v15; // sf
  int v16; // [esp+10h] [ebp-58h]
  const char *v17; // [esp+14h] [ebp-54h]
  int v18; // [esp+18h] [ebp-50h]
  double v19; // [esp+1Ch] [ebp-4Ch]
  CUtlBuffer logData; // [esp+30h] [ebp-38h] BYREF
  int bufUnreliable; // [esp+60h] [ebp-8h]
  int bits; // [esp+64h] [ebp-4h]

  m_nMinWarningBytes = this->m_Trace.m_nMinWarningBytes;
  if ( m_nMinWarningBytes != 0 )
  {
    v4 = this->m_Trace.m_nCurBit - this->m_Trace.m_nStartBit;
    bits = v4;
    if ( v4 >= 8 * m_nMinWarningBytes )
    {
      m_NetChannel = (CNetChan *)this->m_NetChannel;
      if ( m_NetChannel != nullptr )
      {
        m_iCurBit = CNetChan::GetBuffer(this: m_NetChannel, eBufType: BUF_RELIABLE)->m_iCurBit;
        bufUnreliable = CNetChan::GetBuffer(this: m_NetChannel, eBufType: BUF_UNRELIABLE)->m_iCurBit;
        v7 = CNetChan::GetBuffer(this: m_NetChannel, eBufType: BUF_VOICE)->m_iCurBit;
        CBaseClient::TraceNetworkMsg(this, nBits: m_iCurBit, fmt: "[Reliable payload]");
        CBaseClient::TraceNetworkMsg(this, nBits: bufUnreliable, fmt: "[Unreliable payload]");
        CBaseClient::TraceNetworkMsg(this, nBits: v7, fmt: "[Voice payload]");
        v4 = bits;
      }
      CUtlBuffer::CUtlBuffer(this: &logData, growSize: 0, initSize: 0, nFlags: 1);
      v8 = this->GetNetChannel(this: &this->IClient);
      v9 = ((int (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))v8->GetAddress)(
             a1: v8,
             a2: v4,
             a3: COERCE_UNSIGNED_INT64((double)bits * 0.125),
             a4: HIDWORD(COERCE_UNSIGNED_INT64((double)bits * 0.125)));
      v10 = ((int (__thiscall *)(IClient *, int))this->GetPlayerSlot)(a1: &this->IClient, a2: v9);
      v11 = (const char *)((int (__thiscall *)(IClient *, int))this->GetClientName)(a1: &this->IClient, a2: v10);
      CUtlBuffer::Printf(
        this: &logData,
        pFmt: "%f/%d Player [%s][%d][adr:%s] was sent a datagram %d bits (%8.3f bytes)\n",
        realtime,
        host_tickcount,
        v11,
        v16,
        v17,
        v18,
        v19);
      v12 = 0;
      if ( this->m_Trace.m_Records.m_Size > 0 )
      {
        v13 = 0;
        do
        {
          m_pMemory = this->m_Trace.m_Records.m_Memory.m_pMemory;
          bufUnreliable = m_pMemory[v13].m_nBits;
          CUtlBuffer::Printf(
            this: &logData,
            pFmt: "%64.64s : %8d bits (%8.3f bytes)\n",
            m_pMemory[v13].m_szDesc,
            bufUnreliable,
            (double)bufUnreliable * 0.125);
          if ( logData.m_Put > 10240 && v12 != this->m_Trace.m_Records.m_Size - 1 )
          {
            COM_LogString(pchFile: "netspike.txt", pchString: (const char *)logData.m_Memory.m_pMemory);
            memset(&logData.m_Get, 0, 9);
            logData.m_nOffset = 0;
            logData.m_nMaxPut = -1;
            CUtlBuffer::AddNullTermination(this: &logData, nPut: 0);
          }
          ++v12;
          ++v13;
        }
        while ( v12 < this->m_Trace.m_Records.m_Size );
      }
      COM_LogString(pchFile: "netspike.txt", pchString: (const char *)logData.m_Memory.m_pMemory);
      v15 = logData.m_Memory.m_nGrowSize < 0;
      this->m_Trace.m_Records.m_Size = 0;
      if ( !v15 && logData.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: logData.m_Memory.m_pMemory);
    }
    else
    {
      this->m_Trace.m_Records.m_Size = 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10119860
// Name: public: virtual void CBaseClient::SendSnapshot(class CClientFrame __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseClient::SendSnapshot(CBaseClient *this@<ecx>, int a2@<ebx>, CClientFrame *pFrame)
{
  int v4; // edi
  unsigned int *m_SnapshotScratchBuffer; // ecx
  int m_nValue; // eax
  int v7; // ebx
  const char *v8; // eax
  int tick_count; // ecx
  int m_iCurBit; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  const char *v14; // eax
  CFrameSnapshot *m_pSnapshot; // edi
  CFrameSnapshot *m_pObj; // ecx
  int v17; // eax
  INetChannel *m_NetChannel; // ecx
  bool v19; // al
  int v20; // [esp-4h] [ebp-BCh]
  char reason[128]; // [esp+4h] [ebp-B4h] BYREF
  NET_Tick tickmsg; // [esp+84h] [ebp-34h] BYREF
  bf_write msg; // [esp+A0h] [ebp-18h] BYREF

  if ( this->m_pLastSnapshot.m_pObj == pFrame->m_pSnapshot )
  {
    this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
    return;
  }
  v4 = 0;
  if ( this->m_nForceWaitForTick > 0 )
  {
    this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
    return;
  }
  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SendSnapshot",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  if ( net_megasnapshot.m_pParent == nullptr
    || (m_SnapshotScratchBuffer = this->m_MegaSnapshotScratchBuffer, net_megasnapshot.m_pParent->m_Value.m_nValue == 0) )
  {
    m_SnapshotScratchBuffer = this->m_SnapshotScratchBuffer;
  }
  if ( net_megasnapshot.m_pParent != nullptr )
    m_nValue = net_megasnapshot.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  bf_write::bf_write(
    this: &msg,
    pDebugName: "CBaseClient::SendSnapshot",
    pData: m_SnapshotScratchBuffer,
    nBytes: m_nValue != 0 ? 80000 : 40000,
    nBits: -1);
  v7 = ((int (__thiscall *)(CBaseClient *, int, int))this->GetDeltaFrame)(a1: this, a2: this->m_nDeltaTick, a3: a2);
  if ( v7 == 0 )
  {
    v8 = (const char *)((int (__thiscall *)(IClient *, int))this->GetClientName)(
                         a1: &this->IClient,
                         a2: this->m_nDeltaTick);
    V_snprintf(pDest: reason, maxLen: 128, pFormat: "%s can't find frame from tick %d", v8, v20);
    CBaseClient::OnRequestFullUpdate(this, pchReason: reason);
  }
  tick_count = pFrame->tick_count;
  tickmsg.m_flHostFrameTime = host_frametime_unbounded;
  tickmsg.m_NetChannel = nullptr;
  tickmsg.__vftable = (NET_Tick_vtbl *)&NET_Tick::`vftable';
  tickmsg.m_bReliable = false;
  tickmsg.m_nTick = tick_count;
  tickmsg.m_flHostFrameTimeStdDeviation = host_frametime_stddeviation;
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
  {
    m_iCurBit = msg.m_iCurBit;
    this->m_Trace.m_nStartBit = msg.m_iCurBit;
    this->m_Trace.m_nCurBit = m_iCurBit;
  }
  NET_Tick::WriteToBuffer(this: &tickmsg, buffer: &msg);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
    CBaseClient::TraceNetworkData(this, &msg, fmt: "NET_Tick");
  if ( g_pLocalNetworkBackdoor == nullptr )
  {
    v11 = this->GetMaxAckTickCount(this: &this->IClient);
    CNetworkStringTableContainer::WriteUpdateMessage(
      this: this->m_Server->m_StringTables,
      client: this,
      tick_ack: v11,
      buf: &msg);
  }
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
    v4 = msg.m_iCurBit;
  ((void (__stdcall *)(CBaseClient *, CClientFrame *, int, bf_write *))this->m_Server->WriteDeltaEntities)(
    a1: this,
    a2: pFrame,
    a3: v7,
    a4: &msg);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
    CBaseClient::TraceNetworkMsg(this, nBits: msg.m_iCurBit - v4, fmt: "Total Delta");
  if ( this->m_Server->IsMultiplayer(this: this->m_Server) )
  {
    if ( sv_multiplayer_maxtempentities.m_pParent != nullptr )
      v12 = sv_multiplayer_maxtempentities.m_pParent->m_Value.m_nValue;
    else
      v12 = 0;
  }
  else
  {
    v12 = 255;
  }
  this->m_Server->WriteTempEntities(
    this: this->m_Server,
    a2: this,
    a3: pFrame->m_pSnapshot,
    a4: this->m_pLastSnapshot.m_pObj,
    a5: &msg,
    a6: v12);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
    CBaseClient::TraceNetworkData(this, &msg, fmt: "Temp Entities");
  if ( this->m_Server->IsMultiplayer(this: this->m_Server) )
  {
    if ( sv_multiplayer_maxsounds.m_pParent != nullptr )
      v13 = sv_multiplayer_maxsounds.m_pParent->m_Value.m_nValue;
    else
      v13 = 0;
  }
  else
  {
    v13 = 255;
  }
  this->WriteGameSounds(this, a2: &msg, a3: v13);
  if ( this->m_Trace.m_nMinWarningBytes != 0 )
  {
    v14 = "yes";
    if ( v7 == 0 )
      v14 = "no";
    CBaseClient::TraceNetworkMsg(this, nBits: 0, fmt: "Finished [delta %s]", v14);
    CBaseClient::EndTrace(this, &msg);
  }
  if ( !msg.m_bOverflow )
    goto LABEL_43;
  if ( v7 != 0 )
  {
    ConMsg(a1: "WARNING: msg overflowed for %s\n", this->m_Name);
    bf_write::Reset(this: &msg);
LABEL_43:
    m_pSnapshot = pFrame->m_pSnapshot;
    if ( m_pSnapshot != this->m_pLastSnapshot.m_pObj )
    {
      if ( m_pSnapshot != nullptr )
        CFrameSnapshot::AddReference(this: m_pSnapshot);
      m_pObj = this->m_pLastSnapshot.m_pObj;
      if ( m_pObj != nullptr )
        CFrameSnapshot::ReleaseReference(this: m_pObj);
      this->m_pLastSnapshot.m_pObj = m_pSnapshot;
    }
    if ( !this->m_bFakePlayer || this->m_NetChannel != nullptr )
    {
      m_NetChannel = this->m_NetChannel;
      if ( v7 != 0 )
      {
        v19 = m_NetChannel->SendDatagram(this: m_NetChannel, a2: &msg) > 0;
      }
      else if ( m_NetChannel->SendData(this: m_NetChannel, a2: &msg, a3: true)
             && this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false) )
      {
        v19 = true;
        this->m_nForceWaitForTick = pFrame->tick_count;
      }
      else
      {
        v19 = false;
        this->m_nForceWaitForTick = pFrame->tick_count;
      }
      if ( !v19 )
        this->Disconnect(this: &this->IClient, a2: "ERROR! Couldn't send snapshot.");
    }
    else
    {
      v17 = pFrame->tick_count;
      this->m_nDeltaTick = v17;
      this->m_nStringTableAckTick = v17;
    }
    goto LABEL_60;
  }
  this->Disconnect(this: &this->IClient, a2: "ERROR! Reliable snaphsot overflow.");
LABEL_60:
  tickmsg.__vftable = (NET_Tick_vtbl *)&INetMessage::`vftable';
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10119C40
// Name: public: CCopyableUtlVector<class IClient __near *>::CCopyableUtlVector<class IClient __near *>(class CCopyableUtlVector<class IClient __near *> const __near &)
// Source: json
//------------------------------------------------------------------------------
CCopyableUtlVector<IClient *> *__thiscall CCopyableUtlVector<IClient *>::CCopyableUtlVector<IClient *>(
        CCopyableUtlVector<IClient *> *this,
        const CCopyableUtlVector<IClient *> *vec)
{
  int m_Size; // edi
  int i; // eax
  IClient **veca; // [esp+14h] [ebp+8h]

  this->m_Memory.m_pMemory = nullptr;
  this->m_Memory.m_nAllocationCount = 0;
  this->m_Memory.m_nGrowSize = 0;
  this->m_Size = 0;
  this->m_pElements = nullptr;
  this->__vftable = (CCopyableUtlVector<IClient *>_vtbl *)&CCopyableUtlVector<IClient *>::`vftable';
  m_Size = vec->m_Size;
  veca = vec->m_Memory.m_pMemory;
  this->m_Size = 0;
  CUtlVector<CUtlSymbolTableLargeBaseTreeEntry_t *,CUtlMemory<CUtlSymbolTableLargeBaseTreeEntry_t *,int>>::InsertMultipleBefore(
    this: (CUtlVector<S3RGBA,CUtlMemory<S3RGBA,int> > *)&this->CUtlVector<IClient *,CUtlMemory<IClient *,int> >,
    elem: 0,
    num: m_Size);
  for ( i = 0; i < m_Size; ++i )
    this->m_Memory.m_pMemory[i] = veca[i];
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1011A090
// Name: void HostValidateSessionImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl HostValidateSessionImpl()
{
  int v0; // esi
  SessionClient_t *m_pMemory; // edi
  CBaseClient *v2; // ebx
  IClient *v3; // ebx
  char *v4; // esi
  int v5; // eax
  int v6; // edx
  int m_nAllocationCount; // eax
  SessionClient_t *v8; // esi
  int m_Size; // edi
  IClient **v10; // ecx
  int v11; // eax
  IClient **v12; // edi
  int v13; // eax
  SessionClient_t *v14; // eax
  bool v15; // zf
  int v16; // eax
  int *p_m_Size; // edi
  int v18; // ebx
  int i; // esi
  SessionClient_t sc; // [esp+0h] [ebp-4Ch] BYREF
  CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int> > arrSessions; // [esp+28h] [ebp-24h] BYREF
  unsigned __int64 uid; // [esp+3Ch] [ebp-10h] BYREF
  SessionClient_t *v23; // [esp+44h] [ebp-8h]
  int j; // [esp+48h] [ebp-4h]

  if ( sv.m_bIsDedicatedForXbox )
  {
    _Msg(a1: "[SESSION] Validating Session Information...\n");
    v0 = 0;
    m_pMemory = nullptr;
    memset(&arrSessions, 0, sizeof(arrSessions));
    j = 0;
    if ( sv.m_Clients.m_Size <= 0 )
      goto LABEL_21;
    do
    {
      v2 = sv.m_Clients.m_Memory.m_pMemory[v0];
      if ( v2 != nullptr )
      {
        v3 = &v2->IClient;
        if ( v3 != nullptr
          && v3->IsConnected(this: v3)
          && !v3->IsFakeClient(this: v3)
          && !v3->IsSplitScreenUser(this: v3) )
        {
          v4 = (char *)v3->GetUserSetting(this: v3, a2: "cl_session");
          uid = 0;
          if ( sscanf(string: v4, format: "$%llx", &uid) != 1 )
            _Warning(a1: "couldn't parse cl_session %s\n", v4);
          sc.xSession = uid;
          memset(
            &sc.arrClients.CUtlVector<IClient *,CUtlMemory<IClient *,int> >,
            0,
            sizeof(sc.arrClients.CUtlVector<IClient *,CUtlMemory<IClient *,int> >));
          sc.arrClients.__vftable = (CCopyableUtlVector<IClient *>_vtbl *)&CCopyableUtlVector<IClient *>::`vftable';
          sc.numPlayers = 0;
          v5 = CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::Find(this: &arrSessions, src: &sc);
          if ( v5 == -1 )
          {
            v5 = CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::InsertBefore(
                   this: &arrSessions,
                   elem: arrSessions.m_Size,
                   src: &sc);
            m_pMemory = arrSessions.m_Memory.m_pMemory;
          }
          v6 = v5;
          m_nAllocationCount = m_pMemory[v5].arrClients.m_Memory.m_nAllocationCount;
          v8 = &m_pMemory[v6];
          m_Size = v8->arrClients.m_Size;
          v23 = v8;
          if ( m_Size + 1 > m_nAllocationCount )
            CUtlMemory<INetMessage *,int>::Grow(
              this: (CUtlMemory<S3RGBA,int> *)&v8->arrClients.CUtlVector<IClient *,CUtlMemory<IClient *,int> >,
              num: m_Size - m_nAllocationCount + 1);
          ++v8->arrClients.m_Size;
          v10 = v8->arrClients.m_Memory.m_pMemory;
          v11 = v8->arrClients.m_Size - m_Size - 1;
          v8->arrClients.m_pElements = v10;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[m_Size + 1], src: &v10[m_Size], count: 4 * v11);
          v12 = &v8->arrClients.m_Memory.m_pMemory[m_Size];
          if ( v12 != nullptr )
            *v12 = v3;
          v13 = v3->GetNumPlayers(this: v3);
          v23->numPlayers += v13;
          sc.arrClients.__vftable = (CCopyableUtlVector<IClient *>_vtbl *)&CCopyableUtlVector<IClient *>::`vftable';
          CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&sc.arrClients.CUtlVector<IClient *,CUtlMemory<IClient *,int> >);
          m_pMemory = arrSessions.m_Memory.m_pMemory;
          v0 = j;
        }
      }
      j = ++v0;
    }
    while ( v0 < sv.m_Clients.m_Size );
    if ( arrSessions.m_Size == 0 )
    {
LABEL_21:
      _Msg(a1: "[SESSION] No clients.\n");
      CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::RemoveAll(this: &arrSessions);
      if ( arrSessions.m_Memory.m_nGrowSize < 0 )
        return;
      v14 = arrSessions.m_Memory.m_pMemory;
      v15 = arrSessions.m_Memory.m_pMemory == nullptr;
      goto LABEL_32;
    }
    CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::Sort(
      this: &arrSessions,
      pfnCompare: (int (__cdecl *)(const void *, const void *))SessionClient_t::Less);
    v16 = 0;
    if ( m_pMemory->xSession != 0 )
    {
      _Msg(
        a1: "[SESSION] Updating reservation cookie: %llx, keeping %d players.\n",
        m_pMemory->xSession,
        m_pMemory->numPlayers);
      CBaseServer::SetReservationCookie(
        this: &sv,
        uiCookie: m_pMemory->xSession,
        pchReasonFormat: "HostValidateSession");
      v16 = 1;
    }
    if ( v16 < arrSessions.m_Size )
    {
      p_m_Size = &m_pMemory[v16].arrClients.m_Size;
      v18 = arrSessions.m_Size - v16;
      do
      {
        for ( i = 0; i < *p_m_Size; ++i )
          (*(void (__cdecl **)(_DWORD, const char *))(**(_DWORD **)(*(p_m_Size - 3) + 4 * i) + 52))(
            a1: *(_DWORD *)(*(p_m_Size - 3) + 4 * i),
            a2: "Session migrated");
        p_m_Size += 10;
        --v18;
      }
      while ( v18 != 0 );
    }
    CUtlVector<SessionClient_t,CUtlMemory<SessionClient_t,int>>::RemoveAll(this: &arrSessions);
    if ( arrSessions.m_Memory.m_nGrowSize >= 0 )
    {
      v14 = arrSessions.m_Memory.m_pMemory;
      v15 = arrSessions.m_Memory.m_pMemory == nullptr;
LABEL_32:
      if ( !v15 )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v14);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x102E50A0
// Name: public: virtual enum CrossPlayPlatform_t CBaseClient::GetClientPlatform(void)const
// Source: json
//------------------------------------------------------------------------------
vgui::IToolWindowFactory *__thiscall CBaseClient::GetClientPlatform(vgui::ToolWindow *this)
{
  return this->m_pFactory;
}

} // namespace engine_xlsp
