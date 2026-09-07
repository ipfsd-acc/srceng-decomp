// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/sv_steamauth.cpp
// Functions: 27
// ============================================================

#include "engine\sv_steamauth.h"

//------------------------------------------------------------------------------
// Address: 0x1012EF70
// Name: public: bool CSteamGameServerAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamGameServerAPIContext::Init(CSteamGameServerAPIContext *this)
{
  int HSteamUser; // ebx
  int HSteamPipe; // esi
  ISteamGameServer *v5; // eax
  ISteamUtils *v6; // eax
  ISteamMasterServerUpdater *v7; // eax
  ISteamNetworking *v8; // eax
  ISteamGameServerStats *v9; // eax

  if ( _g_pSteamClientGameServer == nullptr )
    return false;
  HSteamUser = _SteamGameServer_GetHSteamUser();
  HSteamPipe = _SteamGameServer_GetHSteamPipe();
  v5 = _g_pSteamClientGameServer->GetISteamGameServer(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamGameServer010");
  this->m_pSteamGameServer = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _g_pSteamClientGameServer->GetISteamUtils(this: _g_pSteamClientGameServer, a2: HSteamPipe, a3: "SteamUtils005");
  this->m_pSteamGameServerUtils = v6;
  if ( v6 == nullptr )
    return false;
  v7 = _g_pSteamClientGameServer->GetISteamMasterServerUpdater(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamMasterServerUpdater001");
  this->m_pSteamMasterServerUpdater = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _g_pSteamClientGameServer->GetISteamNetworking(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamNetworking005");
  this->m_pSteamGameServerNetworking = v8;
  if ( v8 == nullptr )
    return false;
  v9 = _g_pSteamClientGameServer->GetISteamGameServerStats(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamGameServerStats001");
  this->m_pSteamGameServerStats = v9;
  return v9 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1012F030
// Name: class CSteam3Server __near & Steam3Server(void)
// Source: json
//------------------------------------------------------------------------------
CSteam3Server *__cdecl Steam3Server()
{
  return &s_Steam3Server;
}

//------------------------------------------------------------------------------
// Address: 0x1012F040
// Name: public: bool CSteam3Server::CompareUserID(struct USERID_s const __near &,struct USERID_s const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteam3Server::CompareUserID(CSteam3Server *this, const USERID_s *id1, const USERID_s *id2)
{
  if ( id1->idtype != id2->idtype || (unsigned int)(id1->idtype - 1) > 1 )
    return false;
  return id1->uid.steamid.m_SteamInstanceID == id2->uid.steamid.m_SteamInstanceID
      && id1->uid.steamid.m_SteamLocalUserID.Split.Low32bits == id2->uid.steamid.m_SteamLocalUserID.Split.Low32bits
      && id1->uid.steamid.m_SteamLocalUserID.Split.High32bits == id2->uid.steamid.m_SteamLocalUserID.Split.High32bits;
}

//------------------------------------------------------------------------------
// Address: 0x1012F090
// Name: public: void CSteam3Server::UpdateSpectatorPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::UpdateSpectatorPort(CSteam3Server *this, int unSpectatorPort)
{
  ISteamGameServer *m_pSteamGameServer; // ecx

  m_pSteamGameServer = this->m_pSteamGameServer;
  if ( m_pSteamGameServer != nullptr )
    m_pSteamGameServer->UpdateSpectatorPort(this: m_pSteamGameServer, a2: unSpectatorPort);
}

//------------------------------------------------------------------------------
// Address: 0x1012F0B0
// Name: public: void CSteam3Server::OnGSPolicyResponse(struct GSPolicyResponse_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSPolicyResponse(CSteam3Server *this, GSPolicyResponse_t *pPolicyResponse)
{
  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    if ( this->m_pSteamGameServer->BSecure(this: this->m_pSteamGameServer) )
      _Msg(a1: "   VAC secure mode is activated.\n");
    else
      _Msg(a1: "   VAC secure mode disabled.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F0F0
// Name: public: void CSteam3Server::OnLogonFailure(struct SteamServerConnectFailure_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnLogonFailure(CSteam3Server *this, SteamServerConnectFailure_t *pLogonFailure)
{
  EServerMode m_eServerMode; // eax

  if ( this->m_pSteamGameServer != nullptr )
  {
    m_eServerMode = this->m_eServerMode;
    if ( m_eServerMode >= eServerModeNoAuthentication )
    {
      if ( !this->m_bLogOnResult )
      {
        if ( pLogonFailure->m_eResult == k_EResultServiceUnavailable )
        {
          if ( m_eServerMode != eServerModeNoAuthentication )
            _Msg(a1: "Connection to Steam servers successful (SU).\n");
        }
        else if ( m_eServerMode != eServerModeNoAuthentication )
        {
          _Msg(a1: "Could not establish connection to Steam servers.\n");
        }
      }
      this->m_bLogOnResult = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F150
// Name: public: void CSteam3Server::OnLoggedOff(struct SteamServersDisconnected_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnLoggedOff(CSteam3Server *this, SteamServersDisconnected_t *pLoggedOff)
{
  if ( this->m_eServerMode != eServerModeNoAuthentication )
    _Msg(a1: "Connection to Steam servers lost.\n");
}

//------------------------------------------------------------------------------
// Address: 0x1012F170
// Name: private: void CSteam3Server::OnGSClientDenyHelper(class CBaseClient __near *,enum EDenyReason,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSClientDenyHelper(
        CSteam3Server *this,
        CBaseClient *cl,
        EDenyReason eDenyReason,
        const char *pchOptionalText)
{
  EUniverse SteamUniverse; // eax
  bool v6; // bl
  CSteamID steamID; // [esp+Ch] [ebp-8h] BYREF

  SteamUniverse = GetSteamUniverse();
  v6 = SteamUniverse == k_EUniverseBeta;
  if ( SteamUniverse == k_EUniverseBeta )
    _Warning(a1: "Steam deny %s\n", pchOptionalText);
  if ( sv.m_nMaxclients > 1 )
  {
    switch ( eDenyReason )
    {
      case k_EDenyInvalidVersion:
        cl->Disconnect(this: &cl->IClient, a2: "Client version incompatible with server. \nPlease exit and restart");
        break;
      case k_EDenyNotLoggedOn:
      case k_EDenySteamConnectionLost:
      case k_EDenySteamConnectionError:
        if ( this->m_eServerMode != eServerModeNoAuthentication )
          cl->Disconnect(this: &cl->IClient, a2: "No Steam logon\n");
        break;
      case k_EDenyNoLicense:
        cl->Disconnect(
          this: &cl->IClient,
          a2: "This Steam account does not own this game. \nPlease login to the correct Steam account");
        break;
      case k_EDenyCheater:
        if ( this->m_eServerMode != eServerModeNoAuthentication )
          cl->Disconnect(this: &cl->IClient, a2: "VAC banned from secure server\n");
        break;
      case k_EDenyLoggedInElseWhere:
        if ( this->m_eServerMode != eServerModeNoAuthentication )
          cl->Disconnect(this: &cl->IClient, a2: "This Steam account is being used in another location\n");
        break;
      case k_EDenyUnknownText:
        if ( pchOptionalText == nullptr || *pchOptionalText == 0 )
          goto LABEL_25;
        cl->Disconnect(this: &cl->IClient, a2: pchOptionalText);
        break;
      case k_EDenyIncompatibleAnticheat:
        cl->Disconnect(
          this: &cl->IClient,
          a2: "You are running an external tool that is\nincompatible with Secure servers");
        break;
      case k_EDenyMemoryCorruption:
        cl->Disconnect(this: &cl->IClient, a2: "Memory corruption detected");
        break;
      case k_EDenyIncompatibleSoftware:
        cl->Disconnect(this: &cl->IClient, a2: "You are running software that is\nnot compatible with Secure servers");
        break;
      case k_EDenySteamResponseTimedOut:
        if ( v6 )
          _Warning(a1: "Ignoring steam deny message, please report to Alfred!!!\n");
        else
          cl->Disconnect(this: &cl->IClient, a2: "Client timed out");
        break;
      case k_EDenySteamValidationStalled:
        if ( this->m_eServerMode == eServerModeNoAuthentication )
        {
          steamID.m_steamid.m_comp = 0;
          CBaseClient::SetSteamID(this: cl, &steamID);
        }
        else
        {
          _Msg(a1: "Server connection to steam has not responded.\n");
        }
        break;
      default:
LABEL_25:
        cl->Disconnect(this: &cl->IClient, a2: "Client dropped by server");
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F2F0
// Name: public: void CSteam3Server::NotifyClientDisconnect(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::NotifyClientDisconnect(CSteam3Server *this, CBaseClient *client)
{
  USERID_s id; // [esp+8h] [ebp-18h] BYREF

  if ( client != nullptr
    && this->m_pSteamGameServer != nullptr
    && this->m_eServerMode >= eServerModeNoAuthentication
    && client->IsConnected(this: &client->IClient)
    && !client->IsFakeClient(this: &client->IClient) )
  {
    if ( client->IsFakeClient(this: &client->IClient)
      || (client->GetNetworkID(this: &client->IClient, result: &id), id.idtype == 1) )
    {
      ((void (__thiscall *)(ISteamGameServer *, _DWORD, _DWORD))this->m_pSteamGameServer->SendUserDisconnect)(
        a1: this->m_pSteamGameServer,
        a2: *(_DWORD *)&client->m_SteamID.m_steamid.m_comp,
        a3: *((_DWORD *)&client->m_SteamID.m_steamid.m_comp + 1));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F380
// Name: public: void CSteam3Server::SendUpdatedServerDetails(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSteam3Server::SendUpdatedServerDetails(CSteam3Server *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CHLTVServer *v4; // ecx
  bool IsTVRelay; // al
  int v6; // eax
  char *m_szMapname; // ebx
  char *Name; // eax
  ISteamGameServer *m_pSteamGameServer; // edi
  ISteamGameServer_vtbl *v10; // esi
  char *v11; // eax
  CHLTVServer *v12; // ecx
  bool v13; // al
  ISteamGameServer *v14; // edi
  ISteamGameServer_vtbl *v15; // esi
  char *v16; // eax
  char *v17; // [esp-10h] [ebp-24h]
  int v18; // [esp-8h] [ebp-1Ch]
  int v19; // [esp-4h] [ebp-18h]
  int nHumans; // [esp+8h] [ebp-Ch] BYREF
  int nMaxHumans; // [esp+Ch] [ebp-8h] BYREF
  int nBots; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    v19 = a2;
    v18 = a3;
    CBaseServer::GetMasterServerPlayerCounts(this: &sv, &nHumans, nMaxHumanSlots: &nMaxHumans, &nBots);
    v4 = hltv;
    if ( hltv != nullptr && (IsTVRelay = CHLTVServer::IsTVRelay(this: hltv), v4 = hltv, IsTVRelay) )
    {
      v6 = ((int (__thiscall *)(CBaseServer *, int, int))hltv->GetMapName)(a1: &hltv->CBaseServer, a2: a3, a3: a2);
      v4 = hltv;
      m_szMapname = (char *)v6;
    }
    else
    {
      m_szMapname = sv.m_szMapname;
    }
    if ( v4 != nullptr )
      Name = (char *)v4->GetName(this: &v4->CBaseServer);
    else
      Name = CBaseServer::GetName(this: &sv);
    m_pSteamGameServer = this->m_pSteamGameServer;
    v10 = this->m_pSteamGameServer->__vftable;
    v17 = Name;
    v11 = CBaseServer::GetName(this: &sv);
    ((void (__thiscall *)(ISteamGameServer *, int, int, int, char *, char *, char *, int, int))v10->UpdateServerStatus)(
      a1: m_pSteamGameServer,
      a2: nHumans,
      a3: nMaxHumans,
      a4: nBots,
      a5: v11,
      a6: v17,
      a7: m_szMapname,
      a8: v18,
      a9: v19);
    v12 = hltv;
    if ( hltv != nullptr )
    {
      v13 = CHLTVServer::IsTVRelay(this: hltv);
      v12 = hltv;
      if ( v13 )
      {
        hltv->GetMapName(this: &hltv->CBaseServer);
        v12 = hltv;
      }
    }
    if ( v12 != nullptr )
      v12->GetName(this: &v12->CBaseServer);
    else
      CBaseServer::GetName(this: &sv);
    v14 = this->m_pSteamGameServer;
    v15 = this->m_pSteamGameServer->__vftable;
    v16 = CBaseServer::GetName(this: &sv);
    ((void (__thiscall *)(ISteamGameServer *, int, int, int, char *))v15->UpdateServerStatus)(
      a1: v14,
      a2: nHumans,
      a3: nMaxHumans,
      a4: nBots,
      a5: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F4B0
// Name: public: bool CSteam3Server::IsMasterServerUpdaterSharingGameSocket(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteam3Server::IsMasterServerUpdaterSharingGameSocket(CSteam3Server *this)
{
  return this->m_bMasterServerUpdaterSharingGameSocket;
}

//------------------------------------------------------------------------------
// Address: 0x1012F4C0
// Name: public: void CSteam3Server::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::Shutdown(CSteam3Server *this)
{
  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    _SteamGameServer_Shutdown();
    *(_WORD *)&this->m_bLogOnResult = 0;
    *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 1;
    *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) = 0;
    this->m_eServerMode = eServerModeInvalid;
    this->m_pSteamGameServer = nullptr;
    this->m_pSteamGameServerUtils = nullptr;
    this->m_pSteamMasterServerUpdater = nullptr;
    this->m_pSteamGameServerNetworking = nullptr;
    this->m_pSteamGameServerStats = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F510
// Name: public: class CSteamID const __near & CSteam3Server::GetGSSteamID(void)const
// Source: json
//------------------------------------------------------------------------------
const CSteamID *__thiscall CSteam3Server::GetGSSteamID(CSteam3Server *this)
{
  if ( this->m_eServerMode != eServerModeNoAuthentication )
    return &this->m_SteamIDGS;
  if ( (_S2_8 & 1) == 0 )
  {
    _S2_8 |= 1u;
    HIBYTE(s_LAN.m_steamid.m_unAll64Bits) = 1;
    s_LAN.m_steamid.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)(s_LAN.m_steamid.m_unAll64Bits
                                                                     & 0xFF00000000000000uLL);
  }
  return &s_LAN;
}

//------------------------------------------------------------------------------
// Address: 0x1012F560
// Name: public: void CSteam3Server::OnLogonSuccess(struct SteamServersConnected_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSteam3Server::OnLogonSuccess(
        CSteam3Server *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        SteamServersConnected_t *pLogonSuccess)
{
  EServerMode m_eServerMode; // eax
  CSteamID *v6; // eax
  _BYTE v7[8]; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_pSteamGameServer != nullptr )
  {
    m_eServerMode = this->m_eServerMode;
    if ( m_eServerMode >= eServerModeNoAuthentication )
    {
      if ( !this->m_bLogOnResult )
      {
        this->m_bLogOnResult = true;
        if ( m_eServerMode != eServerModeNoAuthentication )
          _Msg(a1: "Connection to Steam servers successful.\n");
      }
      if ( this->m_pSteamGameServer != nullptr )
      {
        v6 = this->m_pSteamGameServer->GetSteamID(this: this->m_pSteamGameServer, result: v7);
        *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = v6->m_steamid.m_comp;
        *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) = *((_DWORD *)&v6->m_steamid.m_comp + 1);
        CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
      }
      else
      {
        *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) = 0;
        *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 1;
        CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F5F0
// Name: public: bool CSteam3Server::NotifyClientConnect(class CBaseClient __near *,unsigned int,struct netadr_s __near &,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteam3Server::NotifyClientConnect(
        CSteam3Server *this,
        CBaseClient *client,
        unsigned int unUserID,
        vgui::Tooltip *adr,
        const void *pvCookie,
        unsigned int ucbCookie)
{
  ISteamGameServer *m_pSteamGameServer; // ebx
  ISteamGameServer_vtbl *v8; // esi
  char *v9; // eax
  CSteamID steamID; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_pSteamGameServer == nullptr || this->m_eServerMode < eServerModeNoAuthentication )
    return 1;
  if ( client != nullptr && !client->IsFakeClient(this: &client->IClient) )
  {
    m_pSteamGameServer = this->m_pSteamGameServer;
    steamID.m_steamid.m_comp = 0;
    v8 = m_pSteamGameServer->__vftable;
    v9 = CWaveDataStreamAsync::Source(this: adr);
    if ( v8->SendUserConnectAndAuthenticate(
           this: m_pSteamGameServer,
           a2: (unsigned int)v9,
           a3: pvCookie,
           a4: ucbCookie,
           a5: &steamID) )
    {
      CBaseClient::SetSteamID(this: client, &steamID);
      CSteam3Server::SendUpdatedServerDetails(this, a2: (int)m_pSteamGameServer, a3: (int)this);
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012F680
// Name: public: bool CSteam3Server::NotifyLocalClientConnect(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSteam3Server::NotifyLocalClientConnect@<al>(
        CSteam3Server *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CBaseClient *client)
{
  ISteamGameServer *m_pSteamGameServer; // ecx
  CSteamID v7; // [esp+4h] [ebp-10h] BYREF
  CSteamID steamID; // [esp+Ch] [ebp-8h] BYREF

  m_pSteamGameServer = this->m_pSteamGameServer;
  steamID.m_steamid.m_comp = 0;
  if ( m_pSteamGameServer != nullptr )
    steamID.m_steamid.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)m_pSteamGameServer->CreateUnauthenticatedUserConnection(
                                                                          this: m_pSteamGameServer,
                                                                          result: &v7)->m_steamid.m_unAll64Bits;
  CBaseClient::SetSteamID(this: client, &steamID);
  CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012F6D0
// Name: public: void CSteam3Server::NotifyOfLevelChange(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSteam3Server::NotifyOfLevelChange(CSteam3Server *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  if ( this->m_bHasActivePlayers )
  {
    this->m_bHasActivePlayers = false;
    CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F6F0
// Name: public: void CSteam3Server::NotifyOfServerNameChange(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __usercall CSteam3Server::NotifyOfServerNameChange(CSteam3Server *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
}

//------------------------------------------------------------------------------
// Address: 0x1012F700
// Name: public: void CSteam3Server::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSteam3Server::RunFrame(CSteam3Server *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool v4; // al
  CStatTime *v5; // ecx
  long double v6; // st7

  v4 = CBaseServer::GetNumClients(this: &sv) > 0;
  if ( this->m_bHasActivePlayers != v4 )
  {
    this->m_bHasActivePlayers = v4;
    CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
  }
  v6 = _Plat_FloatTime(this: v5);
  if ( v6 - s_fLastRunCallback > 0.1000000014901161 )
  {
    s_fLastRunCallback = v6;
    _SteamGameServer_RunCallbacks();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F7A0
// Name: public: CSteam3Server::~CSteam3Server(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::~CSteam3Server(CSteam3Server *this)
{
  bool v2; // zf

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    _SteamGameServer_Shutdown();
    *(_WORD *)&this->m_bLogOnResult = 0;
    *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 1;
    *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) = 0;
    this->m_eServerMode = eServerModeInvalid;
    this->m_pSteamGameServer = nullptr;
    this->m_pSteamGameServerUtils = nullptr;
    this->m_pSteamMasterServerUpdater = nullptr;
    this->m_pSteamGameServerNetworking = nullptr;
    this->m_pSteamGameServerStats = nullptr;
  }
  v2 = (this->m_CallbackGSPolicyResponse.m_nCallbackFlags & 1) == 0;
  this->m_CallbackGSPolicyResponse.__vftable = (CCallback<CSteam3Server,GSPolicyResponse_t,1>_vtbl *)&CCallback<CSteam3Server,GSPolicyResponse_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGSPolicyResponse);
  v2 = (this->m_CallbackGSClientKick.m_nCallbackFlags & 1) == 0;
  this->m_CallbackGSClientKick.__vftable = (CCallback<CSteam3Server,GSClientKick_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientKick_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGSClientKick);
  v2 = (this->m_CallbackGSClientDeny.m_nCallbackFlags & 1) == 0;
  this->m_CallbackGSClientDeny.__vftable = (CCallback<CSteam3Server,GSClientDeny_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientDeny_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGSClientDeny);
  v2 = (this->m_CallbackGSClientApprove.m_nCallbackFlags & 1) == 0;
  this->m_CallbackGSClientApprove.__vftable = (CCallback<CSteam3Server,GSClientApprove_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientApprove_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGSClientApprove);
  v2 = (this->m_CallbackLoggedOff.m_nCallbackFlags & 1) == 0;
  this->m_CallbackLoggedOff.__vftable = (CCallback<CSteam3Server,SteamServersDisconnected_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServersDisconnected_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackLoggedOff);
  v2 = (this->m_CallbackLogonFailure.m_nCallbackFlags & 1) == 0;
  this->m_CallbackLogonFailure.__vftable = (CCallback<CSteam3Server,SteamServerConnectFailure_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServerConnectFailure_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackLogonFailure);
  v2 = (this->m_CallbackLogonSuccess.m_nCallbackFlags & 1) == 0;
  this->m_CallbackLogonSuccess.__vftable = (CCallback<CSteam3Server,SteamServersConnected_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServersConnected_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackLogonSuccess);
}

//------------------------------------------------------------------------------
// Address: 0x1012F890
// Name: public: void CSteam3Server::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::Activate(CSteam3Server *this)
{
  int v2; // eax
  int v3; // eax
  EServerMode m_eServerMode; // ecx
  int v5; // eax
  int v6; // edi
  int v7; // eax
  const char *v8; // eax
  char *v9; // eax
  EServerMode v10; // eax
  int v11; // eax
  int UDPPort; // ebx
  int m_usPort; // eax
  int v14; // edi
  const char *VersionString; // eax
  unsigned int v16; // [esp+4h] [ebp-134h]
  char out[20]; // [esp+18h] [ebp-120h] BYREF
  char gamedir[260]; // [esp+2Ch] [ebp-10Ch] BYREF
  ConVarRef ipname; // [esp+130h] [ebp-8h]

  if ( sv_lan.m_pParent != nullptr && sv_lan.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = 1;
  }
  else
  {
    v3 = _CommandLine();
    v2 = 3 - ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-insecure") != 0);
  }
  m_eServerMode = this->m_eServerMode;
  if ( v2 != m_eServerMode )
  {
    if ( this->m_pSteamGameServer != nullptr && m_eServerMode >= eServerModeNoAuthentication )
      CSteam3Server::Shutdown(this);
    this->m_unIP = 0;
    this->m_usPort = 26900;
    v5 = _CommandLine();
    v6 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 40))(a1: v5);
    if ( v6 != 0 )
    {
      v7 = _CommandLine();
      v16 = v6 + 1;
      v8 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 44))(a1: v7);
      ipname.m_pConVar = (IConVar *)(int)EvaluateExpression(pExpr: v8, flValueToReturnIfFailure: 26900.0);
      this->m_usPort = (unsigned __int16)ipname.m_pConVar;
    }
    ConVarRef::ConVarRef(this: (ConVarRef *)&gamedir[240], pName: "ip");
    if ( ConVarRef::IsValid(this: (ConVarRef *)&gamedir[240]) )
    {
      netadr_s::SetIP(this: (netadr_s *)&gamedir[248], unIP: 0);
      netadr_s::SetPort(this: (netadr_s *)&gamedir[248], newport: 0);
      netadr_s::SetType(this: (netadr_s *)&gamedir[248], newtype: NA_IP);
      NET_StringToAdr(s: *(const char **)(*(_DWORD *)&gamedir[244] + 36), a: (netadr_s *)&gamedir[248]);
      if ( !netadr_s::IsLoopback(this: (netadr_s *)&gamedir[248])
        && !netadr_s::IsLocalhost(this: (netadr_s *)&gamedir[248]) )
      {
        v9 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&gamedir[248]);
        this->m_unIP = htonl(hostlong: (u_long)v9);
      }
    }
    if ( sv_lan.m_pParent != nullptr && sv_lan.m_pParent->m_Value.m_nValue != 0 )
    {
      v10 = eServerModeNoAuthentication;
    }
    else
    {
      v11 = _CommandLine();
      v10 = 3 - ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v11 + 40))(a1: v11, a2: "-insecure") != 0);
    }
    this->m_eServerMode = v10;
    V_FileBase(in: com_gamedir, out, maxlen: 260);
    if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) && CHLTVServer::IsTVRelay(this: hltv) )
      ipname.m_pConVarState = nullptr;
    else
      ipname.m_pConVarState = (ConVar *)NET_GetUDPPort(socket: 1);
    UDPPort = 0;
    if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
      UDPPort = NET_GetUDPPort(socket: 2);
    if ( IsUsingMasterLegacyMode()
      || sv_master_share_game_socket.m_pParent != nullptr
      && sv_master_share_game_socket.m_pParent->m_Value.m_nValue != 0 )
    {
      this->m_bMasterServerUpdaterSharingGameSocket = true;
      v14 = 0xFFFF;
      if ( sv.m_State < ss_active )
        this->m_QueryPort = UDPPort;
      else
        this->m_QueryPort = (unsigned __int16)ipname.m_pConVarState;
    }
    else
    {
      m_usPort = this->m_usPort;
      this->m_bMasterServerUpdaterSharingGameSocket = false;
      v14 = m_usPort;
      this->m_QueryPort = m_usPort;
    }
    VersionString = Sys_GetVersionString();
    if ( (unsigned __int8)_SteamGameServer_InitSafe(
                            a1: this->m_unIP,
                            a2: (unsigned __int16)(this->m_usPort + 1),
                            a3: ipname.m_pConVarState,
                            a4: UDPPort,
                            a5: v14,
                            a6: this->m_eServerMode,
                            a7: out,
                            a8: VersionString) != 0 )
    {
      CSteamGameServerAPIContext::Init(this);
      CSteam3Server::SendUpdatedServerDetails(this, a2: UDPPort, a3: v14);
    }
    else
    {
      _Warning(a1: "************************************************\n");
      _Warning(a1: "*  Unable to load Steam support library.       *\n");
      _Warning(a1: "*  This server will operate in LAN mode only.  *\n");
      _Warning(a1: "************************************************\n");
      this->m_eServerMode = eServerModeNoAuthentication;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_lan.IConVar, value: 1, a2: v16, a3: (int)"-steamport");
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FB80
// Name: private: bool CSteam3Server::CheckForDuplicateSteamID(class CBaseClient const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteam3Server::CheckForDuplicateSteamID(CSteam3Server *this, const CBaseClient *client)
{
  bool v2; // zf
  int v4; // edi
  CBaseClient *v5; // eax
  IClient *v6; // esi
  IClient *v7; // eax
  int v8; // eax
  const USERID_s *v9; // eax
  _BYTE v10[24]; // [esp+0h] [ebp-38h] BYREF
  USERID_s id2; // [esp+18h] [ebp-20h] BYREF
  CSteam3Server *v12; // [esp+30h] [ebp-8h]
  int i; // [esp+34h] [ebp-4h]

  v2 = this->m_eServerMode == eServerModeNoAuthentication;
  v12 = this;
  if ( v2 )
    return 0;
  v4 = 0;
  i = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return 0;
  while ( 1 )
  {
    v5 = sv.m_Clients.m_Memory.m_pMemory[v4];
    if ( v5 != nullptr )
      v6 = &v5->IClient;
    else
      v6 = nullptr;
    if ( v6->IsConnected(this: v6)
      && !v6->IsFakeClient(this: v6)
      && v6->GetNetworkID(this: v6, result: &id2)->idtype == 1 )
    {
      v7 = client != nullptr ? &client->IClient : nullptr;
      if ( v7 == v6 )
        goto LABEL_16;
      v8 = ((int (__thiscall *)(IClient *))v6->GetNetworkID)(a1: v6);
      v9 = (const USERID_s *)((int (__thiscall *)(IClient *, _BYTE *, int))client->GetNetworkID)(
                               a1: &client->IClient,
                               a2: v10,
                               a3: v8);
      if ( CSteam3Server::CompareUserID(this: v12, id1: v9, &id2) )
        return 1;
      v4 = i;
    }
LABEL_16:
    i = ++v4;
    if ( v4 >= sv.m_Clients.m_Size )
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FC60
// Name: private: class CBaseClient __near * CSteam3Server::ClientFindFromSteamID(class CSteamID __near &)
// Source: json
//------------------------------------------------------------------------------
IClient *__thiscall CSteam3Server::ClientFindFromSteamID(CSteam3Server *this, CSteamID *steamIDFind)
{
  CBaseClient *v2; // eax
  IClient *v3; // eax
  IClient *v4; // ebx
  USERID_s v6; // [esp+Ch] [ebp-34h] BYREF
  USERID_s id; // [esp+24h] [ebp-1Ch] BYREF
  int i; // [esp+3Ch] [ebp-4h]

  i = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v2 = sv.m_Clients.m_Memory.m_pMemory[i];
    if ( v2 != nullptr && (v3 = &v2->IClient) != nullptr )
      v4 = v3 - 1;
    else
      v4 = nullptr;
    if ( v4[1].IsConnected(this: v4 + 1)
      && !v4[1].IsFakeClient(this: v4 + 1)
      && v4[1].GetNetworkID(this: v4 + 1, result: &v6)->idtype == 1 )
    {
      v4[1].GetNetworkID(this: v4 + 1, result: &id);
      if ( __PAIR64__(
             *((_DWORD *)&steamIDFind->m_steamid.m_comp + 1) & 0xFF000000 | 0x100001,
             id.uid.steamid.m_SteamLocalUserID.Split.High32bits + 2 * id.uid.steamid.m_SteamLocalUserID.Split.Low32bits) == steamIDFind->m_steamid.m_unAll64Bits )
        break;
    }
    if ( ++i >= sv.m_Clients.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1012FD30
// Name: public: void CSteam3Server::OnGSClientApprove(struct GSClientApprove_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSClientApprove(CSteam3Server *this, GSClientApprove_t *pGSClientApprove)
{
  IClient *v3; // eax
  const CBaseClient *v4; // ebx
  IClient *v5; // esi
  const USERID_s *v6; // eax
  int v7; // eax
  netadr_s *v8; // eax
  IClient_vtbl *v9; // edi
  const char *v10; // eax
  char *v11; // eax
  char v12; // al
  IClient *v13; // ecx
  IClient_vtbl *v14; // edi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  const char *v18; // eax
  CServerPlugin_vtbl *v19; // edi
  int v20; // eax
  int v21; // eax
  IServerGameClients_vtbl *v22; // edi
  int v23; // eax
  int v24; // eax
  int v25; // [esp-10h] [ebp-22Ch]
  char *v26; // [esp-Ch] [ebp-228h]
  const char *v27; // [esp-Ch] [ebp-228h]
  char msg[512]; // [esp+4h] [ebp-218h] BYREF
  USERID_s v29; // [esp+204h] [ebp-18h] BYREF

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    v3 = CSteam3Server::ClientFindFromSteamID(this, steamIDFind: &pGSClientApprove->m_SteamID);
    v4 = (const CBaseClient *)v3;
    if ( v3 != nullptr )
    {
      v5 = v3 + 1;
      v6 = v3[1].GetNetworkID(this: v3 + 1, result: &v29);
      if ( Filter_IsUserBanned(userid: v6) )
      {
        v7 = (int)v5->GetNetChannel(this: &v4->IClient);
        v8 = (netadr_s *)(*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 196))(
                           a1: v7,
                           a2: "#Valve_Reject_Banned_From_Server");
        CBaseServer::RejectConnection(this: &sv, adr: v8, fmt: v26);
        v9 = v5->__vftable;
        v10 = v5->GetNetworkIDString(this: &v4->IClient);
        v11 = va(format: "STEAM UserID %s is banned", v10);
        v9->Disconnect(this: &v4->IClient, a2: v11);
        v4->m_bFullyAuthenticated = true;
      }
      else
      {
        v12 = CSteam3Server::CheckForDuplicateSteamID(this, client: v4);
        v13 = &v4->IClient;
        if ( v12 != 0 )
        {
          v14 = v5->__vftable;
          v15 = (int)v5->GetNetworkIDString(this: v13);
          v14->Disconnect(this: &v4->IClient, a2: "STEAM UserID %s is already\nin use on this server", v15);
          v4->m_bFullyAuthenticated = true;
        }
        else
        {
          v16 = (int)v5->GetNetworkIDString(this: v13);
          v17 = ((int (__thiscall *)(IClient *, int))v5->GetUserID)(a1: &v4->IClient, a2: v16);
          v18 = (const char *)((int (__thiscall *)(IClient *, int))v5->GetClientName)(a1: &v4->IClient, a2: v17);
          sprintf(string: msg, format: "\"%s<%i><%s><>\" STEAM USERID validated\n", v18, v25, v27);
          DevMsg(a1: "%s", msg);
          CLog::Printf(this: &g_Log, fmt: "%s", msg);
          v19 = g_pServerPluginHandler->__vftable;
          v20 = (int)v5->GetNetworkIDString(this: &v4->IClient);
          v21 = ((int (__thiscall *)(IClient *, int))v5->GetClientName)(a1: &v4->IClient, a2: v20);
          ((void (__thiscall *)(CServerPlugin *, int))v19->NetworkIDValidated)(a1: g_pServerPluginHandler, a2: v21);
          if ( g_iServerGameClientsVersion >= 4 )
          {
            v22 = serverGameClients->__vftable;
            v23 = (int)v5->GetNetworkIDString(this: &v4->IClient);
            v24 = ((int (__thiscall *)(IClient *, int))v5->GetClientName)(a1: &v4->IClient, a2: v23);
            ((void (__thiscall *)(IServerGameClients *, int))v22->NetworkIDValidated)(a1: serverGameClients, a2: v24);
          }
          v4->m_bFullyAuthenticated = true;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FED0
// Name: public: void CSteam3Server::OnGSClientDeny(struct GSClientDeny_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSClientDeny(CSteam3Server *this, GSClientDeny_t *pGSClientDeny)
{
  IClient *v3; // eax

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    v3 = CSteam3Server::ClientFindFromSteamID(this, steamIDFind: &pGSClientDeny->m_SteamID);
    if ( v3 != nullptr )
      CSteam3Server::OnGSClientDenyHelper(
        this,
        cl: (CBaseClient *)v3,
        eDenyReason: pGSClientDeny->m_eDenyReason,
        pchOptionalText: pGSClientDeny->m_rgchOptionalText);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FF10
// Name: public: void CSteam3Server::OnGSClientKick(struct GSClientKick_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSClientKick(CSteam3Server *this, GSClientKick_t *pGSClientKick)
{
  IClient *v3; // eax

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    v3 = CSteam3Server::ClientFindFromSteamID(this, steamIDFind: &pGSClientKick->m_SteamID);
    if ( v3 != nullptr )
      CSteam3Server::OnGSClientDenyHelper(
        this,
        cl: (CBaseClient *)v3,
        eDenyReason: pGSClientKick->m_eDenyReason,
        pchOptionalText: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FF50
// Name: public: CSteam3Server::CSteam3Server(void)
// Source: json
//------------------------------------------------------------------------------
CSteam3Server *__thiscall CSteam3Server::CSteam3Server(CSteam3Server *this)
{
  this->m_pSteamGameServer = nullptr;
  this->m_pSteamGameServerUtils = nullptr;
  this->m_pSteamMasterServerUpdater = nullptr;
  this->m_pSteamGameServerNetworking = nullptr;
  this->m_pSteamGameServerStats = nullptr;
  this->m_CallbackLogonSuccess.m_nCallbackFlags = 0;
  this->m_CallbackLogonSuccess.m_iCallback = 0;
  this->m_CallbackLogonSuccess.__vftable = (CCallback<CSteam3Server,SteamServersConnected_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServersConnected_t,1>::`vftable';
  this->m_CallbackLogonSuccess.m_pObj = this;
  this->m_CallbackLogonSuccess.m_Func = (void (__thiscall *)(CSteam3Server *, SteamServersConnected_t *))CSteam3Server::OnLogonSuccess;
  if ( CSteam3Server::OnLogonSuccess != nullptr )
  {
    this->m_CallbackLogonSuccess.m_nCallbackFlags = 2;
    this->m_CallbackLogonSuccess.m_pObj = this;
    this->m_CallbackLogonSuccess.m_Func = (void (__thiscall *)(CSteam3Server *, SteamServersConnected_t *))CSteam3Server::OnLogonSuccess;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackLogonSuccess, a2: 101);
  }
  this->m_CallbackLogonFailure.m_nCallbackFlags = 0;
  this->m_CallbackLogonFailure.m_iCallback = 0;
  this->m_CallbackLogonFailure.__vftable = (CCallback<CSteam3Server,SteamServerConnectFailure_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServerConnectFailure_t,1>::`vftable';
  this->m_CallbackLogonFailure.m_pObj = this;
  this->m_CallbackLogonFailure.m_Func = CSteam3Server::OnLogonFailure;
  if ( CSteam3Server::OnLogonFailure != nullptr )
  {
    this->m_CallbackLogonFailure.m_nCallbackFlags = 2;
    this->m_CallbackLogonFailure.m_pObj = this;
    this->m_CallbackLogonFailure.m_Func = CSteam3Server::OnLogonFailure;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackLogonFailure, a2: 102);
  }
  this->m_CallbackLoggedOff.m_nCallbackFlags = 0;
  this->m_CallbackLoggedOff.m_iCallback = 0;
  this->m_CallbackLoggedOff.__vftable = (CCallback<CSteam3Server,SteamServersDisconnected_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServersDisconnected_t,1>::`vftable';
  this->m_CallbackLoggedOff.m_pObj = this;
  this->m_CallbackLoggedOff.m_Func = CSteam3Server::OnLoggedOff;
  if ( CSteam3Server::OnLoggedOff != nullptr )
  {
    this->m_CallbackLoggedOff.m_nCallbackFlags = 2;
    this->m_CallbackLoggedOff.m_pObj = this;
    this->m_CallbackLoggedOff.m_Func = CSteam3Server::OnLoggedOff;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackLoggedOff, a2: 103);
  }
  this->m_CallbackGSClientApprove.m_nCallbackFlags = 0;
  this->m_CallbackGSClientApprove.m_iCallback = 0;
  this->m_CallbackGSClientApprove.__vftable = (CCallback<CSteam3Server,GSClientApprove_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientApprove_t,1>::`vftable';
  this->m_CallbackGSClientApprove.m_pObj = this;
  this->m_CallbackGSClientApprove.m_Func = CSteam3Server::OnGSClientApprove;
  if ( CSteam3Server::OnGSClientApprove != nullptr )
  {
    this->m_CallbackGSClientApprove.m_nCallbackFlags = 2;
    this->m_CallbackGSClientApprove.m_pObj = this;
    this->m_CallbackGSClientApprove.m_Func = CSteam3Server::OnGSClientApprove;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGSClientApprove, a2: 201);
  }
  this->m_CallbackGSClientDeny.m_nCallbackFlags = 0;
  this->m_CallbackGSClientDeny.m_iCallback = 0;
  this->m_CallbackGSClientDeny.__vftable = (CCallback<CSteam3Server,GSClientDeny_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientDeny_t,1>::`vftable';
  this->m_CallbackGSClientDeny.m_pObj = this;
  this->m_CallbackGSClientDeny.m_Func = CSteam3Server::OnGSClientDeny;
  if ( CSteam3Server::OnGSClientDeny != nullptr )
  {
    this->m_CallbackGSClientDeny.m_nCallbackFlags = 2;
    this->m_CallbackGSClientDeny.m_pObj = this;
    this->m_CallbackGSClientDeny.m_Func = CSteam3Server::OnGSClientDeny;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGSClientDeny, a2: 202);
  }
  this->m_CallbackGSClientKick.m_nCallbackFlags = 0;
  this->m_CallbackGSClientKick.m_iCallback = 0;
  this->m_CallbackGSClientKick.__vftable = (CCallback<CSteam3Server,GSClientKick_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientKick_t,1>::`vftable';
  this->m_CallbackGSClientKick.m_pObj = this;
  this->m_CallbackGSClientKick.m_Func = CSteam3Server::OnGSClientKick;
  if ( CSteam3Server::OnGSClientKick != nullptr )
  {
    this->m_CallbackGSClientKick.m_nCallbackFlags = 2;
    this->m_CallbackGSClientKick.m_pObj = this;
    this->m_CallbackGSClientKick.m_Func = CSteam3Server::OnGSClientKick;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGSClientKick, a2: 203);
  }
  this->m_CallbackGSPolicyResponse.m_nCallbackFlags = 0;
  this->m_CallbackGSPolicyResponse.m_iCallback = 0;
  this->m_CallbackGSPolicyResponse.__vftable = (CCallback<CSteam3Server,GSPolicyResponse_t,1>_vtbl *)&CCallback<CSteam3Server,GSPolicyResponse_t,1>::`vftable';
  this->m_CallbackGSPolicyResponse.m_pObj = this;
  this->m_CallbackGSPolicyResponse.m_Func = CSteam3Server::OnGSPolicyResponse;
  if ( CSteam3Server::OnGSPolicyResponse != nullptr )
  {
    this->m_CallbackGSPolicyResponse.m_nCallbackFlags = 2;
    this->m_CallbackGSPolicyResponse.m_pObj = this;
    this->m_CallbackGSPolicyResponse.m_Func = CSteam3Server::OnGSPolicyResponse;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGSPolicyResponse, a2: 115);
  }
  *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_SteamIDGS.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) &= 0xFFF00000;
  *((_DWORD *)&this->m_steamIDLanOnly.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_steamIDLanOnly.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_steamIDLanOnly.m_steamid.m_comp + 1) &= 0xFFF00000;
  *(_WORD *)&this->m_bLogOnResult = 0;
  this->m_eServerMode = eServerModeInvalid;
  *(_WORD *)&this->m_bWantsSecure = 0;
  *(_WORD *)&this->m_bMasterServerUpdaterSharingGameSocket = 0;
  *(_DWORD *)&this->m_steamIDLanOnly.m_steamid.m_comp = 0;
  HIBYTE(this->m_steamIDLanOnly.m_steamid.m_unAll64Bits) = 1;
  *((_DWORD *)&this->m_steamIDLanOnly.m_steamid.m_comp + 1) &= 0xFF000000;
  HIBYTE(this->m_SteamIDGS.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) &= 0xFF000000;
  *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 1;
  this->m_QueryPort = 0;
  return this;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1012F020
// Name: public: bool CSteamGameServerAPIContext::Init(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CSteamGameServerAPIContext::Init(CSteamGameServerAPIContext *this)
{
  int HSteamUser; // ebx
  int HSteamPipe; // esi
  ISteamGameServer *v5; // eax
  ISteamUtils *v6; // eax
  ISteamMasterServerUpdater *v7; // eax
  ISteamNetworking *v8; // eax
  ISteamGameServerStats *v9; // eax

  if ( _g_pSteamClientGameServer == nullptr )
    return false;
  HSteamUser = _SteamGameServer_GetHSteamUser();
  HSteamPipe = _SteamGameServer_GetHSteamPipe();
  v5 = _g_pSteamClientGameServer->GetISteamGameServer(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamGameServer010");
  this->m_pSteamGameServer = v5;
  if ( v5 == nullptr )
    return false;
  v6 = _g_pSteamClientGameServer->GetISteamUtils(this: _g_pSteamClientGameServer, a2: HSteamPipe, a3: "SteamUtils005");
  this->m_pSteamGameServerUtils = v6;
  if ( v6 == nullptr )
    return false;
  v7 = _g_pSteamClientGameServer->GetISteamMasterServerUpdater(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamMasterServerUpdater001");
  this->m_pSteamMasterServerUpdater = v7;
  if ( v7 == nullptr )
    return false;
  v8 = _g_pSteamClientGameServer->GetISteamNetworking(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamNetworking005");
  this->m_pSteamGameServerNetworking = v8;
  if ( v8 == nullptr )
    return false;
  v9 = _g_pSteamClientGameServer->GetISteamGameServerStats(
         this: _g_pSteamClientGameServer,
         a2: HSteamUser,
         a3: HSteamPipe,
         a4: "SteamGameServerStats001");
  this->m_pSteamGameServerStats = v9;
  return v9 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1012F0E0
// Name: class CSteam3Server __near & Steam3Server(void)
// Source: json
//------------------------------------------------------------------------------
CSteam3Server *__cdecl Steam3Server()
{
  return &s_Steam3Server;
}

//------------------------------------------------------------------------------
// Address: 0x1012F140
// Name: public: void CSteam3Server::UpdateSpectatorPort(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::UpdateSpectatorPort(CSteam3Server *this, int unSpectatorPort)
{
  ISteamGameServer *m_pSteamGameServer; // ecx

  m_pSteamGameServer = this->m_pSteamGameServer;
  if ( m_pSteamGameServer != nullptr )
    m_pSteamGameServer->UpdateSpectatorPort(this: m_pSteamGameServer, a2: unSpectatorPort);
}

//------------------------------------------------------------------------------
// Address: 0x1012F160
// Name: public: void CSteam3Server::OnGSPolicyResponse(struct GSPolicyResponse_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSPolicyResponse(CSteam3Server *this, GSPolicyResponse_t *pPolicyResponse)
{
  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    if ( this->m_pSteamGameServer->BSecure(this: this->m_pSteamGameServer) )
      _Msg(a1: "   VAC secure mode is activated.\n");
    else
      _Msg(a1: "   VAC secure mode disabled.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F1A0
// Name: public: void CSteam3Server::OnLogonFailure(struct SteamServerConnectFailure_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnLogonFailure(CSteam3Server *this, SteamServerConnectFailure_t *pLogonFailure)
{
  EServerMode m_eServerMode; // eax

  if ( this->m_pSteamGameServer != nullptr )
  {
    m_eServerMode = this->m_eServerMode;
    if ( m_eServerMode >= eServerModeNoAuthentication )
    {
      if ( !this->m_bLogOnResult )
      {
        if ( pLogonFailure->m_eResult == k_EResultServiceUnavailable )
        {
          if ( m_eServerMode != eServerModeNoAuthentication )
            _Msg(a1: "Connection to Steam servers successful (SU).\n");
        }
        else if ( m_eServerMode != eServerModeNoAuthentication )
        {
          _Msg(a1: "Could not establish connection to Steam servers.\n");
        }
      }
      this->m_bLogOnResult = true;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F200
// Name: public: void CSteam3Server::OnLoggedOff(struct SteamServersDisconnected_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnLoggedOff(CSteam3Server *this, SteamServersDisconnected_t *pLoggedOff)
{
  if ( this->m_eServerMode != eServerModeNoAuthentication )
    _Msg(a1: "Connection to Steam servers lost.\n");
}

//------------------------------------------------------------------------------
// Address: 0x1012F220
// Name: private: void CSteam3Server::OnGSClientDenyHelper(class CBaseClient __near *,enum EDenyReason,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSClientDenyHelper(
        CSteam3Server *this,
        CBaseClient *cl,
        EDenyReason eDenyReason,
        const char *pchOptionalText)
{
  EUniverse SteamUniverse; // eax
  bool v6; // bl
  CSteamID steamID; // [esp+Ch] [ebp-8h] BYREF

  SteamUniverse = GetSteamUniverse();
  v6 = SteamUniverse == k_EUniverseBeta;
  if ( SteamUniverse == k_EUniverseBeta )
    _Warning(a1: "Steam deny %s\n", pchOptionalText);
  if ( sv.m_nMaxclients > 1 )
  {
    switch ( eDenyReason )
    {
      case k_EDenyInvalidVersion:
        cl->Disconnect(this: &cl->IClient, a2: "Client version incompatible with server. \nPlease exit and restart");
        break;
      case k_EDenyNotLoggedOn:
      case k_EDenySteamConnectionLost:
      case k_EDenySteamConnectionError:
        if ( this->m_eServerMode != eServerModeNoAuthentication )
          cl->Disconnect(this: &cl->IClient, a2: "No Steam logon\n");
        break;
      case k_EDenyNoLicense:
        cl->Disconnect(
          this: &cl->IClient,
          a2: "This Steam account does not own this game. \nPlease login to the correct Steam account");
        break;
      case k_EDenyCheater:
        if ( this->m_eServerMode != eServerModeNoAuthentication )
          cl->Disconnect(this: &cl->IClient, a2: "VAC banned from secure server\n");
        break;
      case k_EDenyLoggedInElseWhere:
        if ( this->m_eServerMode != eServerModeNoAuthentication )
          cl->Disconnect(this: &cl->IClient, a2: "This Steam account is being used in another location\n");
        break;
      case k_EDenyUnknownText:
        if ( pchOptionalText == nullptr || *pchOptionalText == 0 )
          goto LABEL_25;
        cl->Disconnect(this: &cl->IClient, a2: pchOptionalText);
        break;
      case k_EDenyIncompatibleAnticheat:
        cl->Disconnect(
          this: &cl->IClient,
          a2: "You are running an external tool that is\nincompatible with Secure servers");
        break;
      case k_EDenyMemoryCorruption:
        cl->Disconnect(this: &cl->IClient, a2: "Memory corruption detected");
        break;
      case k_EDenyIncompatibleSoftware:
        cl->Disconnect(this: &cl->IClient, a2: "You are running software that is\nnot compatible with Secure servers");
        break;
      case k_EDenySteamResponseTimedOut:
        if ( v6 )
          _Warning(a1: "Ignoring steam deny message, please report to Alfred!!!\n");
        else
          cl->Disconnect(this: &cl->IClient, a2: "Client timed out");
        break;
      case k_EDenySteamValidationStalled:
        if ( this->m_eServerMode == eServerModeNoAuthentication )
        {
          steamID.m_steamid.m_comp = 0;
          CBaseClient::SetSteamID(this: cl, &steamID);
        }
        else
        {
          _Msg(a1: "Server connection to steam has not responded.\n");
        }
        break;
      default:
LABEL_25:
        cl->Disconnect(this: &cl->IClient, a2: "Client dropped by server");
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F3A0
// Name: public: void CSteam3Server::NotifyClientDisconnect(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::NotifyClientDisconnect(CSteam3Server *this, CBaseClient *client)
{
  USERID_s id; // [esp+8h] [ebp-18h] BYREF

  if ( client != nullptr
    && this->m_pSteamGameServer != nullptr
    && this->m_eServerMode >= eServerModeNoAuthentication
    && client->IsConnected(this: &client->IClient)
    && !client->IsFakeClient(this: &client->IClient) )
  {
    if ( client->IsFakeClient(this: &client->IClient)
      || (client->GetNetworkID(this: &client->IClient, result: &id), id.idtype == 1) )
    {
      ((void (__thiscall *)(ISteamGameServer *, _DWORD, _DWORD))this->m_pSteamGameServer->SendUserDisconnect)(
        a1: this->m_pSteamGameServer,
        a2: *(_DWORD *)&client->m_SteamID.m_steamid.m_comp,
        a3: *((_DWORD *)&client->m_SteamID.m_steamid.m_comp + 1));
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F430
// Name: public: void CSteam3Server::SendUpdatedServerDetails(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSteam3Server::SendUpdatedServerDetails(CSteam3Server *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  CHLTVServer *v4; // ecx
  bool IsTVRelay; // al
  int v6; // eax
  char *m_szMapname; // ebx
  char *Name; // eax
  ISteamGameServer *m_pSteamGameServer; // edi
  ISteamGameServer_vtbl *v10; // esi
  char *v11; // eax
  CHLTVServer *v12; // ecx
  bool v13; // al
  ISteamGameServer *v14; // edi
  ISteamGameServer_vtbl *v15; // esi
  char *v16; // eax
  char *v17; // [esp-10h] [ebp-24h]
  int v18; // [esp-8h] [ebp-1Ch]
  int v19; // [esp-4h] [ebp-18h]
  int nHumans; // [esp+8h] [ebp-Ch] BYREF
  int nMaxHumans; // [esp+Ch] [ebp-8h] BYREF
  int nBots; // [esp+10h] [ebp-4h] BYREF

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    v19 = a2;
    v18 = a3;
    CBaseServer::GetMasterServerPlayerCounts(this: &sv, &nHumans, nMaxHumanSlots: &nMaxHumans, &nBots);
    v4 = hltv;
    if ( hltv != nullptr && (IsTVRelay = CHLTVServer::IsTVRelay(this: hltv), v4 = hltv, IsTVRelay) )
    {
      v6 = ((int (__thiscall *)(CBaseServer *, int, int))hltv->GetMapName)(a1: &hltv->CBaseServer, a2: a3, a3: a2);
      v4 = hltv;
      m_szMapname = (char *)v6;
    }
    else
    {
      m_szMapname = sv.m_szMapname;
    }
    if ( v4 != nullptr )
      Name = (char *)v4->GetName(this: &v4->CBaseServer);
    else
      Name = CBaseServer::GetName(this: &sv);
    m_pSteamGameServer = this->m_pSteamGameServer;
    v10 = this->m_pSteamGameServer->__vftable;
    v17 = Name;
    v11 = CBaseServer::GetName(this: &sv);
    ((void (__thiscall *)(ISteamGameServer *, int, int, int, char *, char *, char *, int, int))v10->UpdateServerStatus)(
      a1: m_pSteamGameServer,
      a2: nHumans,
      a3: nMaxHumans,
      a4: nBots,
      a5: v11,
      a6: v17,
      a7: m_szMapname,
      a8: v18,
      a9: v19);
    v12 = hltv;
    if ( hltv != nullptr )
    {
      v13 = CHLTVServer::IsTVRelay(this: hltv);
      v12 = hltv;
      if ( v13 )
      {
        hltv->GetMapName(this: &hltv->CBaseServer);
        v12 = hltv;
      }
    }
    if ( v12 != nullptr )
      v12->GetName(this: &v12->CBaseServer);
    else
      CBaseServer::GetName(this: &sv);
    v14 = this->m_pSteamGameServer;
    v15 = this->m_pSteamGameServer->__vftable;
    v16 = CBaseServer::GetName(this: &sv);
    ((void (__thiscall *)(ISteamGameServer *, int, int, int, char *))v15->UpdateServerStatus)(
      a1: v14,
      a2: nHumans,
      a3: nMaxHumans,
      a4: nBots,
      a5: v16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F570
// Name: public: void CSteam3Server::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::Shutdown(CSteam3Server *this)
{
  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    _SteamGameServer_Shutdown();
    *(_WORD *)&this->m_bLogOnResult = 0;
    *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 1;
    *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) = 0;
    this->m_eServerMode = eServerModeInvalid;
    this->m_pSteamGameServer = nullptr;
    this->m_pSteamGameServerUtils = nullptr;
    this->m_pSteamMasterServerUpdater = nullptr;
    this->m_pSteamGameServerNetworking = nullptr;
    this->m_pSteamGameServerStats = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F5C0
// Name: public: class CSteamID const __near & CSteam3Server::GetGSSteamID(void)const
// Source: json
//------------------------------------------------------------------------------
const CSteamID *__thiscall CSteam3Server::GetGSSteamID(CSteam3Server *this)
{
  if ( this->m_eServerMode != eServerModeNoAuthentication )
    return &this->m_SteamIDGS;
  if ( (_S2_8 & 1) == 0 )
  {
    _S2_8 |= 1u;
    HIBYTE(s_LAN.m_steamid.m_unAll64Bits) = 1;
    s_LAN.m_steamid.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)(s_LAN.m_steamid.m_unAll64Bits
                                                                     & 0xFF00000000000000uLL);
  }
  return &s_LAN;
}

//------------------------------------------------------------------------------
// Address: 0x1012F610
// Name: public: void CSteam3Server::OnLogonSuccess(struct SteamServersConnected_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CSteam3Server::OnLogonSuccess(
        CSteam3Server *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        SteamServersConnected_t *pLogonSuccess)
{
  EServerMode m_eServerMode; // eax
  CSteamID *v6; // eax
  _BYTE v7[8]; // [esp+4h] [ebp-8h] BYREF

  if ( this->m_pSteamGameServer != nullptr )
  {
    m_eServerMode = this->m_eServerMode;
    if ( m_eServerMode >= eServerModeNoAuthentication )
    {
      if ( !this->m_bLogOnResult )
      {
        this->m_bLogOnResult = true;
        if ( m_eServerMode != eServerModeNoAuthentication )
          _Msg(a1: "Connection to Steam servers successful.\n");
      }
      if ( this->m_pSteamGameServer != nullptr )
      {
        v6 = this->m_pSteamGameServer->GetSteamID(this: this->m_pSteamGameServer, result: v7);
        *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = v6->m_steamid.m_comp;
        *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) = *((_DWORD *)&v6->m_steamid.m_comp + 1);
        CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
      }
      else
      {
        *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) = 0;
        *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 1;
        CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F6A0
// Name: public: bool CSteam3Server::NotifyClientConnect(class CBaseClient __near *,unsigned int,struct netadr_s __near &,void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteam3Server::NotifyClientConnect(
        CSteam3Server *this,
        CBaseClient *client,
        unsigned int unUserID,
        vgui::Tooltip *adr,
        const void *pvCookie,
        unsigned int ucbCookie)
{
  ISteamGameServer *m_pSteamGameServer; // ebx
  ISteamGameServer_vtbl *v8; // esi
  char *v9; // eax
  CSteamID steamID; // [esp+8h] [ebp-8h] BYREF

  if ( this->m_pSteamGameServer == nullptr || this->m_eServerMode < eServerModeNoAuthentication )
    return 1;
  if ( client != nullptr && !client->IsFakeClient(this: &client->IClient) )
  {
    m_pSteamGameServer = this->m_pSteamGameServer;
    steamID.m_steamid.m_comp = 0;
    v8 = m_pSteamGameServer->__vftable;
    v9 = CWaveDataStreamAsync::Source(this: adr);
    if ( v8->SendUserConnectAndAuthenticate(
           this: m_pSteamGameServer,
           a2: (unsigned int)v9,
           a3: pvCookie,
           a4: ucbCookie,
           a5: &steamID) )
    {
      CBaseClient::SetSteamID(this: client, &steamID);
      CSteam3Server::SendUpdatedServerDetails(this, a2: (int)m_pSteamGameServer, a3: (int)this);
      return 1;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1012F730
// Name: public: bool CSteam3Server::NotifyLocalClientConnect(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CSteam3Server::NotifyLocalClientConnect@<al>(
        CSteam3Server *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        CBaseClient *client)
{
  ISteamGameServer *m_pSteamGameServer; // ecx
  CSteamID v7; // [esp+4h] [ebp-10h] BYREF
  CSteamID steamID; // [esp+Ch] [ebp-8h] BYREF

  m_pSteamGameServer = this->m_pSteamGameServer;
  steamID.m_steamid.m_comp = 0;
  if ( m_pSteamGameServer != nullptr )
    steamID.m_steamid.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)m_pSteamGameServer->CreateUnauthenticatedUserConnection(
                                                                          this: m_pSteamGameServer,
                                                                          result: &v7)->m_steamid.m_unAll64Bits;
  CBaseClient::SetSteamID(this: client, &steamID);
  CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1012F780
// Name: public: void CSteam3Server::NotifyOfLevelChange(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSteam3Server::NotifyOfLevelChange(CSteam3Server *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  if ( this->m_bHasActivePlayers )
  {
    this->m_bHasActivePlayers = false;
    CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F7B0
// Name: public: void CSteam3Server::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CSteam3Server::RunFrame(CSteam3Server *this@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  bool v4; // al
  int v5; // ecx
  double v6; // st7

  v4 = CBaseServer::GetNumClients(this: &sv) > 0;
  if ( this->m_bHasActivePlayers != v4 )
  {
    this->m_bHasActivePlayers = v4;
    CSteam3Server::SendUpdatedServerDetails(this, a2, a3);
  }
  v6 = _Plat_FloatTime(a1: v5);
  if ( v6 - s_fLastRunCallback > 0.1000000014901161 )
  {
    s_fLastRunCallback = v6;
    _SteamGameServer_RunCallbacks();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012F860
// Name: public: CSteam3Server::~CSteam3Server(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::~CSteam3Server(CSteam3Server *this)
{
  bool v2; // zf

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    _SteamGameServer_Shutdown();
    *(_WORD *)&this->m_bLogOnResult = 0;
    *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 1;
    *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) = 0;
    this->m_eServerMode = eServerModeInvalid;
    this->m_pSteamGameServer = nullptr;
    this->m_pSteamGameServerUtils = nullptr;
    this->m_pSteamMasterServerUpdater = nullptr;
    this->m_pSteamGameServerNetworking = nullptr;
    this->m_pSteamGameServerStats = nullptr;
  }
  v2 = (this->m_CallbackGSPolicyResponse.m_nCallbackFlags & 1) == 0;
  this->m_CallbackGSPolicyResponse.__vftable = (CCallback<CSteam3Server,GSPolicyResponse_t,1>_vtbl *)&CCallback<CSteam3Server,GSPolicyResponse_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGSPolicyResponse);
  v2 = (this->m_CallbackGSClientKick.m_nCallbackFlags & 1) == 0;
  this->m_CallbackGSClientKick.__vftable = (CCallback<CSteam3Server,GSClientKick_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientKick_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGSClientKick);
  v2 = (this->m_CallbackGSClientDeny.m_nCallbackFlags & 1) == 0;
  this->m_CallbackGSClientDeny.__vftable = (CCallback<CSteam3Server,GSClientDeny_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientDeny_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGSClientDeny);
  v2 = (this->m_CallbackGSClientApprove.m_nCallbackFlags & 1) == 0;
  this->m_CallbackGSClientApprove.__vftable = (CCallback<CSteam3Server,GSClientApprove_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientApprove_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackGSClientApprove);
  v2 = (this->m_CallbackLoggedOff.m_nCallbackFlags & 1) == 0;
  this->m_CallbackLoggedOff.__vftable = (CCallback<CSteam3Server,SteamServersDisconnected_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServersDisconnected_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackLoggedOff);
  v2 = (this->m_CallbackLogonFailure.m_nCallbackFlags & 1) == 0;
  this->m_CallbackLogonFailure.__vftable = (CCallback<CSteam3Server,SteamServerConnectFailure_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServerConnectFailure_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackLogonFailure);
  v2 = (this->m_CallbackLogonSuccess.m_nCallbackFlags & 1) == 0;
  this->m_CallbackLogonSuccess.__vftable = (CCallback<CSteam3Server,SteamServersConnected_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServersConnected_t,1>::`vftable';
  if ( !v2 )
    _SteamAPI_UnregisterCallback(a1: &this->m_CallbackLogonSuccess);
}

//------------------------------------------------------------------------------
// Address: 0x1012F950
// Name: public: void CSteam3Server::Activate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::Activate(CSteam3Server *this)
{
  int v2; // eax
  int v3; // eax
  EServerMode m_eServerMode; // ecx
  int v5; // eax
  int v6; // eax
  const char *v7; // eax
  char *v8; // eax
  EServerMode v9; // eax
  int v10; // eax
  int UDPPort; // ebx
  int m_usPort; // eax
  int v13; // edi
  void (*v14)(const char *, ...); // edi
  const char *VersionString; // eax
  char gamedir[260]; // [esp+1Ch] [ebp-120h] BYREF
  ConVarRef ipname; // [esp+120h] [ebp-1Ch] BYREF
  netadr_s ipaddr; // [esp+128h] [ebp-14h] BYREF
  int v19; // [esp+134h] [ebp-8h]
  int usGamePort; // [esp+138h] [ebp-4h]

  if ( sv_lan.m_pParent != nullptr && sv_lan.m_pParent->m_Value.m_nValue != 0 )
  {
    v2 = 1;
  }
  else
  {
    v3 = _CommandLine();
    v2 = 3 - ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-insecure") != 0);
  }
  m_eServerMode = this->m_eServerMode;
  if ( v2 != m_eServerMode )
  {
    if ( this->m_pSteamGameServer != nullptr && m_eServerMode >= eServerModeNoAuthentication )
      CSteam3Server::Shutdown(this);
    this->m_unIP = 0;
    this->m_usPort = 26900;
    v5 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(a1: v5, a2: "-steamport") != 0 )
    {
      v6 = _CommandLine();
      v7 = (const char *)(*(int (__thiscall **)(int))(*(_DWORD *)v6 + 44))(a1: v6);
      v19 = (int)EvaluateExpression(pExpr: v7, flValueToReturnIfFailure: 26900.0);
      this->m_usPort = v19;
    }
    ConVarRef::ConVarRef(this: &ipname, pName: "ip");
    if ( ConVarRef::IsValid(this: &ipname) )
    {
      netadr_s::SetIP(this: &ipaddr, unIP: 0);
      netadr_s::SetPort(this: &ipaddr, newport: 0);
      netadr_s::SetType(this: &ipaddr, newtype: NA_IP);
      NET_StringToAdr(s: ipname.m_pConVarState->m_Value.m_pszString, a: &ipaddr);
      if ( !netadr_s::IsLoopback(this: &ipaddr) && !netadr_s::IsLocalhost(this: &ipaddr) )
      {
        v8 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&ipaddr);
        this->m_unIP = htonl(hostlong: (u_long)v8);
      }
    }
    if ( sv_lan.m_pParent != nullptr && sv_lan.m_pParent->m_Value.m_nValue != 0 )
    {
      v9 = eServerModeNoAuthentication;
    }
    else
    {
      v10 = _CommandLine();
      v9 = 3 - ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-insecure") != 0);
    }
    this->m_eServerMode = v9;
    V_FileBase(in: com_gamedir, out: gamedir, maxlen: 260);
    if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) && CHLTVServer::IsTVRelay(this: hltv) )
      usGamePort = 0;
    else
      usGamePort = NET_GetUDPPort(socket: 1);
    UDPPort = 0;
    if ( hltv != nullptr && hltv->IsActive(this: &hltv->CBaseServer) )
      UDPPort = NET_GetUDPPort(socket: 2);
    if ( IsUsingMasterLegacyMode()
      || sv_master_share_game_socket.m_pParent != nullptr
      && sv_master_share_game_socket.m_pParent->m_Value.m_nValue != 0 )
    {
      this->m_bMasterServerUpdaterSharingGameSocket = true;
      v13 = 0xFFFF;
      if ( sv.m_State < ss_active )
        this->m_QueryPort = UDPPort;
      else
        this->m_QueryPort = usGamePort;
    }
    else
    {
      m_usPort = this->m_usPort;
      this->m_bMasterServerUpdaterSharingGameSocket = false;
      v13 = m_usPort;
      this->m_QueryPort = m_usPort;
    }
    if ( NET_IsDedicatedForXbox() )
    {
      v14 = (void (*)(const char *, ...))_Warning;
      _Warning(a1: "************************************************\n");
      _Warning(a1: "*  Dedicated Server for Xbox. Not using STEAM. *\n");
LABEL_38:
      v14(a1: "*  This server will operate in LAN mode only.  *\n");
      v14(a1: "************************************************\n");
      this->m_eServerMode = eServerModeNoAuthentication;
      CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_lan.IConVar, value: 1);
      return;
    }
    VersionString = Sys_GetVersionString();
    if ( (unsigned __int8)_SteamGameServer_InitSafe(
                            a1: this->m_unIP,
                            a2: (unsigned __int16)(this->m_usPort + 1),
                            a3: usGamePort,
                            a4: UDPPort,
                            a5: v13,
                            a6: this->m_eServerMode,
                            a7: gamedir,
                            a8: VersionString) == 0 )
    {
      v14 = (void (*)(const char *, ...))_Warning;
      _Warning(a1: "************************************************\n");
      _Warning(a1: "*  Unable to load Steam support library.       *\n");
      goto LABEL_38;
    }
    CSteamGameServerAPIContext::Init(this);
    CSteam3Server::SendUpdatedServerDetails(this, a2: UDPPort, a3: v13);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FD40
// Name: private: class CBaseClient __near * CSteam3Server::ClientFindFromSteamID(class CSteamID __near &)
// Source: json
//------------------------------------------------------------------------------
IClient *__thiscall CSteam3Server::ClientFindFromSteamID(CSteam3Server *this, CSteamID *steamIDFind)
{
  CBaseClient *v2; // eax
  IClient *v3; // eax
  IClient *v4; // ebx
  USERID_s v6; // [esp+Ch] [ebp-34h] BYREF
  USERID_s id; // [esp+24h] [ebp-1Ch] BYREF
  int i; // [esp+3Ch] [ebp-4h]

  i = 0;
  if ( sv.m_Clients.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v2 = sv.m_Clients.m_Memory.m_pMemory[i];
    if ( v2 != nullptr && (v3 = &v2->IClient) != nullptr )
      v4 = v3 - 1;
    else
      v4 = nullptr;
    if ( v4[1].IsConnected(this: v4 + 1)
      && !v4[1].IsFakeClient(this: v4 + 1)
      && v4[1].GetNetworkID(this: v4 + 1, result: &v6)->idtype == 1 )
    {
      v4[1].GetNetworkID(this: v4 + 1, result: &id);
      if ( __PAIR64__(
             *((_DWORD *)&steamIDFind->m_steamid.m_comp + 1) & 0xFF000000 | 0x100001,
             id.uid.steamid.m_SteamLocalUserID.Split.High32bits + 2 * id.uid.steamid.m_SteamLocalUserID.Split.Low32bits) == steamIDFind->m_steamid.m_unAll64Bits )
        break;
    }
    if ( ++i >= sv.m_Clients.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1012FE10
// Name: public: void CSteam3Server::OnGSClientApprove(struct GSClientApprove_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSClientApprove(CSteam3Server *this, GSClientApprove_t *pGSClientApprove)
{
  IClient *v3; // eax
  const CBaseClient *v4; // ebx
  IClient *v5; // esi
  const USERID_s *v6; // eax
  int v7; // eax
  netadr_s *v8; // eax
  IClient_vtbl *v9; // edi
  const char *v10; // eax
  char *v11; // eax
  bool v12; // al
  IClient *v13; // ecx
  IClient_vtbl *v14; // edi
  int v15; // eax
  int v16; // eax
  int v17; // eax
  const char *v18; // eax
  CServerPlugin_vtbl *v19; // edi
  int v20; // eax
  int v21; // eax
  IServerGameClients_vtbl *v22; // edi
  int v23; // eax
  int v24; // eax
  int v25; // [esp-10h] [ebp-22Ch]
  char *v26; // [esp-Ch] [ebp-228h]
  const char *v27; // [esp-Ch] [ebp-228h]
  char msg[512]; // [esp+4h] [ebp-218h] BYREF
  USERID_s v29; // [esp+204h] [ebp-18h] BYREF

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    v3 = CSteam3Server::ClientFindFromSteamID(this, steamIDFind: &pGSClientApprove->m_SteamID);
    v4 = (const CBaseClient *)v3;
    if ( v3 != nullptr )
    {
      v5 = v3 + 1;
      v6 = v3[1].GetNetworkID(this: v3 + 1, result: &v29);
      if ( Filter_IsUserBanned(userid: v6) )
      {
        v7 = (int)v5->GetNetChannel(this: &v4->IClient);
        v8 = (netadr_s *)(*(int (__thiscall **)(int, const char *))(*(_DWORD *)v7 + 196))(
                           a1: v7,
                           a2: "#Valve_Reject_Banned_From_Server");
        CBaseServer::RejectConnection(this: &sv, adr: v8, fmt: v26);
        v9 = v5->__vftable;
        v10 = v5->GetNetworkIDString(this: &v4->IClient);
        v11 = va(format: "STEAM UserID %s is banned", v10);
        v9->Disconnect(this: &v4->IClient, a2: v11);
        v4->m_bFullyAuthenticated = true;
      }
      else
      {
        v12 = CSteam3Server::CheckForDuplicateSteamID(this, client: v4);
        v13 = &v4->IClient;
        if ( v12 )
        {
          v14 = v5->__vftable;
          v15 = (int)v5->GetNetworkIDString(this: v13);
          v14->Disconnect(this: &v4->IClient, a2: "STEAM UserID %s is already\nin use on this server", v15);
          v4->m_bFullyAuthenticated = true;
        }
        else
        {
          v16 = (int)v5->GetNetworkIDString(this: v13);
          v17 = ((int (__thiscall *)(IClient *, int))v5->GetUserID)(a1: &v4->IClient, a2: v16);
          v18 = (const char *)((int (__thiscall *)(IClient *, int))v5->GetClientName)(a1: &v4->IClient, a2: v17);
          sprintf(string: msg, format: "\"%s<%i><%s><>\" STEAM USERID validated\n", v18, v25, v27);
          DevMsg(a1: "%s", msg);
          CLog::Printf(this: &g_Log, fmt: "%s", msg);
          v19 = g_pServerPluginHandler->__vftable;
          v20 = (int)v5->GetNetworkIDString(this: &v4->IClient);
          v21 = ((int (__thiscall *)(IClient *, int))v5->GetClientName)(a1: &v4->IClient, a2: v20);
          ((void (__thiscall *)(CServerPlugin *, int))v19->NetworkIDValidated)(a1: g_pServerPluginHandler, a2: v21);
          if ( g_iServerGameClientsVersion >= 4 )
          {
            v22 = serverGameClients->__vftable;
            v23 = (int)v5->GetNetworkIDString(this: &v4->IClient);
            v24 = ((int (__thiscall *)(IClient *, int))v5->GetClientName)(a1: &v4->IClient, a2: v23);
            ((void (__thiscall *)(IServerGameClients *, int))v22->NetworkIDValidated)(a1: serverGameClients, a2: v24);
          }
          v4->m_bFullyAuthenticated = true;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FFB0
// Name: public: void CSteam3Server::OnGSClientDeny(struct GSClientDeny_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSClientDeny(CSteam3Server *this, GSClientDeny_t *pGSClientDeny)
{
  IClient *v3; // eax

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    v3 = CSteam3Server::ClientFindFromSteamID(this, steamIDFind: &pGSClientDeny->m_SteamID);
    if ( v3 != nullptr )
      CSteam3Server::OnGSClientDenyHelper(
        this,
        cl: (CBaseClient *)v3,
        eDenyReason: pGSClientDeny->m_eDenyReason,
        pchOptionalText: pGSClientDeny->m_rgchOptionalText);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1012FFF0
// Name: public: void CSteam3Server::OnGSClientKick(struct GSClientKick_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteam3Server::OnGSClientKick(CSteam3Server *this, GSClientKick_t *pGSClientKick)
{
  IClient *v3; // eax

  if ( this->m_pSteamGameServer != nullptr && this->m_eServerMode >= eServerModeNoAuthentication )
  {
    v3 = CSteam3Server::ClientFindFromSteamID(this, steamIDFind: &pGSClientKick->m_SteamID);
    if ( v3 != nullptr )
      CSteam3Server::OnGSClientDenyHelper(
        this,
        cl: (CBaseClient *)v3,
        eDenyReason: pGSClientKick->m_eDenyReason,
        pchOptionalText: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10130030
// Name: public: CSteam3Server::CSteam3Server(void)
// Source: json
//------------------------------------------------------------------------------
CSteam3Server *__thiscall CSteam3Server::CSteam3Server(CSteam3Server *this)
{
  this->m_pSteamGameServer = nullptr;
  this->m_pSteamGameServerUtils = nullptr;
  this->m_pSteamMasterServerUpdater = nullptr;
  this->m_pSteamGameServerNetworking = nullptr;
  this->m_pSteamGameServerStats = nullptr;
  this->m_CallbackLogonSuccess.m_nCallbackFlags = 0;
  this->m_CallbackLogonSuccess.m_iCallback = 0;
  this->m_CallbackLogonSuccess.__vftable = (CCallback<CSteam3Server,SteamServersConnected_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServersConnected_t,1>::`vftable';
  this->m_CallbackLogonSuccess.m_pObj = this;
  this->m_CallbackLogonSuccess.m_Func = (void (__thiscall *)(CSteam3Server *, SteamServersConnected_t *))CSteam3Server::OnLogonSuccess;
  if ( CSteam3Server::OnLogonSuccess != nullptr )
  {
    this->m_CallbackLogonSuccess.m_nCallbackFlags = 2;
    this->m_CallbackLogonSuccess.m_pObj = this;
    this->m_CallbackLogonSuccess.m_Func = (void (__thiscall *)(CSteam3Server *, SteamServersConnected_t *))CSteam3Server::OnLogonSuccess;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackLogonSuccess, a2: 101);
  }
  this->m_CallbackLogonFailure.m_nCallbackFlags = 0;
  this->m_CallbackLogonFailure.m_iCallback = 0;
  this->m_CallbackLogonFailure.__vftable = (CCallback<CSteam3Server,SteamServerConnectFailure_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServerConnectFailure_t,1>::`vftable';
  this->m_CallbackLogonFailure.m_pObj = this;
  this->m_CallbackLogonFailure.m_Func = CSteam3Server::OnLogonFailure;
  if ( CSteam3Server::OnLogonFailure != nullptr )
  {
    this->m_CallbackLogonFailure.m_nCallbackFlags = 2;
    this->m_CallbackLogonFailure.m_pObj = this;
    this->m_CallbackLogonFailure.m_Func = CSteam3Server::OnLogonFailure;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackLogonFailure, a2: 102);
  }
  this->m_CallbackLoggedOff.m_nCallbackFlags = 0;
  this->m_CallbackLoggedOff.m_iCallback = 0;
  this->m_CallbackLoggedOff.__vftable = (CCallback<CSteam3Server,SteamServersDisconnected_t,1>_vtbl *)&CCallback<CSteam3Server,SteamServersDisconnected_t,1>::`vftable';
  this->m_CallbackLoggedOff.m_pObj = this;
  this->m_CallbackLoggedOff.m_Func = CSteam3Server::OnLoggedOff;
  if ( CSteam3Server::OnLoggedOff != nullptr )
  {
    this->m_CallbackLoggedOff.m_nCallbackFlags = 2;
    this->m_CallbackLoggedOff.m_pObj = this;
    this->m_CallbackLoggedOff.m_Func = CSteam3Server::OnLoggedOff;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackLoggedOff, a2: 103);
  }
  this->m_CallbackGSClientApprove.m_nCallbackFlags = 0;
  this->m_CallbackGSClientApprove.m_iCallback = 0;
  this->m_CallbackGSClientApprove.__vftable = (CCallback<CSteam3Server,GSClientApprove_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientApprove_t,1>::`vftable';
  this->m_CallbackGSClientApprove.m_pObj = this;
  this->m_CallbackGSClientApprove.m_Func = CSteam3Server::OnGSClientApprove;
  if ( CSteam3Server::OnGSClientApprove != nullptr )
  {
    this->m_CallbackGSClientApprove.m_nCallbackFlags = 2;
    this->m_CallbackGSClientApprove.m_pObj = this;
    this->m_CallbackGSClientApprove.m_Func = CSteam3Server::OnGSClientApprove;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGSClientApprove, a2: 201);
  }
  this->m_CallbackGSClientDeny.m_nCallbackFlags = 0;
  this->m_CallbackGSClientDeny.m_iCallback = 0;
  this->m_CallbackGSClientDeny.__vftable = (CCallback<CSteam3Server,GSClientDeny_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientDeny_t,1>::`vftable';
  this->m_CallbackGSClientDeny.m_pObj = this;
  this->m_CallbackGSClientDeny.m_Func = CSteam3Server::OnGSClientDeny;
  if ( CSteam3Server::OnGSClientDeny != nullptr )
  {
    this->m_CallbackGSClientDeny.m_nCallbackFlags = 2;
    this->m_CallbackGSClientDeny.m_pObj = this;
    this->m_CallbackGSClientDeny.m_Func = CSteam3Server::OnGSClientDeny;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGSClientDeny, a2: 202);
  }
  this->m_CallbackGSClientKick.m_nCallbackFlags = 0;
  this->m_CallbackGSClientKick.m_iCallback = 0;
  this->m_CallbackGSClientKick.__vftable = (CCallback<CSteam3Server,GSClientKick_t,1>_vtbl *)&CCallback<CSteam3Server,GSClientKick_t,1>::`vftable';
  this->m_CallbackGSClientKick.m_pObj = this;
  this->m_CallbackGSClientKick.m_Func = CSteam3Server::OnGSClientKick;
  if ( CSteam3Server::OnGSClientKick != nullptr )
  {
    this->m_CallbackGSClientKick.m_nCallbackFlags = 2;
    this->m_CallbackGSClientKick.m_pObj = this;
    this->m_CallbackGSClientKick.m_Func = CSteam3Server::OnGSClientKick;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGSClientKick, a2: 203);
  }
  this->m_CallbackGSPolicyResponse.m_nCallbackFlags = 0;
  this->m_CallbackGSPolicyResponse.m_iCallback = 0;
  this->m_CallbackGSPolicyResponse.__vftable = (CCallback<CSteam3Server,GSPolicyResponse_t,1>_vtbl *)&CCallback<CSteam3Server,GSPolicyResponse_t,1>::`vftable';
  this->m_CallbackGSPolicyResponse.m_pObj = this;
  this->m_CallbackGSPolicyResponse.m_Func = CSteam3Server::OnGSPolicyResponse;
  if ( CSteam3Server::OnGSPolicyResponse != nullptr )
  {
    this->m_CallbackGSPolicyResponse.m_nCallbackFlags = 2;
    this->m_CallbackGSPolicyResponse.m_pObj = this;
    this->m_CallbackGSPolicyResponse.m_Func = CSteam3Server::OnGSPolicyResponse;
    _SteamAPI_RegisterCallback(a1: &this->m_CallbackGSPolicyResponse, a2: 115);
  }
  *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 0;
  *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_SteamIDGS.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) &= 0xFFF00000;
  *((_DWORD *)&this->m_steamIDLanOnly.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_steamIDLanOnly.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_steamIDLanOnly.m_steamid.m_comp + 1) &= 0xFFF00000;
  *(_WORD *)&this->m_bLogOnResult = 0;
  this->m_eServerMode = eServerModeInvalid;
  *(_WORD *)&this->m_bWantsSecure = 0;
  *(_WORD *)&this->m_bMasterServerUpdaterSharingGameSocket = 0;
  *(_DWORD *)&this->m_steamIDLanOnly.m_steamid.m_comp = 0;
  HIBYTE(this->m_steamIDLanOnly.m_steamid.m_unAll64Bits) = 1;
  *((_DWORD *)&this->m_steamIDLanOnly.m_steamid.m_comp + 1) &= 0xFF000000;
  HIBYTE(this->m_SteamIDGS.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp + 1) &= 0xFF000000;
  *(_DWORD *)&this->m_SteamIDGS.m_steamid.m_comp = 1;
  this->m_QueryPort = 0;
  return this;
}

} // namespace engine_xlsp
