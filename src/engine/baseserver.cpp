// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/baseserver.cpp
// Functions: 103
// ============================================================

#include "engine\baseserver.h"

//------------------------------------------------------------------------------
// Address: 0x10134940
// Name: public: bool CSteam3Server::BSecure(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteam3Server::BSecure(CSteam3Server *this)
{
  ISteamGameServer *m_pSteamGameServer; // ecx

  m_pSteamGameServer = this->m_pSteamGameServer;
  return m_pSteamGameServer != nullptr && m_pSteamGameServer->BSecure(this: m_pSteamGameServer);
}

//------------------------------------------------------------------------------
// Address: 0x10134960
// Name: int SortServerTags(char __near * const __near *,char __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SortServerTags(const char **p1, const char **p2)
{
  return _V_strcmp(s1: *p1, s2: *p2) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x10134990
// Name: SvGameDataChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl SvGameDataChangeCallback()
{
  if ( sv.m_State >= ss_active )
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: "heartbeat\n", nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101349B0
// Name: protected: bool CBaseServer::CanAcceptChallengesFrom(struct netadr_s __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::CanAcceptChallengesFrom(CBaseServer *this, netadr_s *adrFrom)
{
  return this->m_flTimeReservationGraceStarted < 0.0
      || net_time - this->m_flTimeReservationGraceStarted > sv_reservation_grace.m_pParent->m_Value.m_fValue
      || netadr_s::CompareAdr(this: adrFrom, a: &this->m_adrReservationGraceStarted, onlyBase: false);
}

//------------------------------------------------------------------------------
// Address: 0x10134A10
// Name: public: virtual char const __near * CBaseServer::GetPassword(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseServer::GetPassword(CBaseServer *this)
{
  char *v1; // esi
  char *m_pszString; // eax

  if ( (sv_password.m_nFlags & 0x1000) != 0 )
  {
    v1 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = sv_password.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      return nullptr;
    v1 = sv_password.m_pParent->m_Value.m_pszString;
    if ( *m_pszString == 0 )
      return nullptr;
  }
  if ( _V_stricmp(s1: v1, s2: "none") != 0 )
    return v1;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10134A60
// Name: public: virtual void CBaseServer::SetPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SetPassword(CBaseServer *this, const char *password)
{
  if ( password != nullptr )
    V_strncpy(pDest: this->m_Password, pSrc: password, maxLen: 32);
  else
    this->m_Password[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10134A90
// Name: public: bool CBaseServer::IsSinglePlayerGame(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::IsSinglePlayerGame(CBaseServer *this)
{
  return !sv.m_bIsDedicated && this->m_nMaxclients <= 1;
}

//------------------------------------------------------------------------------
// Address: 0x10134AB0
// Name: public: virtual void CBaseServer::FillServerInfo(class SVC_ServerInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::FillServerInfo(CBaseServer *this, SVC_ServerInfo *serverinfo)
{
  V_FileBase(in: com_gamedir, out: gamedir_3, maxlen: 260);
  serverinfo->m_nProtocol = GetHostVersion();
  serverinfo->m_nServerCount = this->GetSpawnCount(this);
  serverinfo->m_nMapCRC = this->worldmapCRC;
  serverinfo->m_nClientCRC = this->clientDllCRC;
  serverinfo->m_nStringTableCRC = this->stringTableCRC;
  serverinfo->m_nMaxClients = this->GetMaxClients(this);
  serverinfo->m_nMaxClasses = this->serverclasses;
  serverinfo->m_bIsDedicated = this->IsDedicated(this);
  serverinfo->m_cOS = 87;
  serverinfo->m_cOS = tolower(c: 87);
  serverinfo->m_fTickInterval = this->GetTickInterval(this);
  serverinfo->m_szGameDir = gamedir_3;
  serverinfo->m_szMapName = this->GetMapName(this);
  serverinfo->m_szSkyName = this->m_szSkyname;
  serverinfo->m_szHostName = this->GetName(this);
  serverinfo->m_bIsHLTV = this->IsHLTV(this);
}

//------------------------------------------------------------------------------
// Address: 0x10134B80
// Name: protected: virtual void CBaseServer::ReplyServerChallenge(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ReplyServerChallenge(CBaseServer *this, netadr_s *adr)
{
  int v3; // ebx
  bf_write msg; // [esp+Ch] [ebp-28h] BYREF
  char buffer[16]; // [esp+24h] [ebp-10h] BYREF

  bf_write::bf_write(this: &msg, pData: buffer, nBytes: 16, nBits: -1);
  v3 = this->GetChallengeNr(this, a2: adr);
  bf_write::WriteLong(this: &msg, val: -1);
  bf_write::WriteByte(this: &msg, val: 0x41u);
  bf_write::WriteLong(this: &msg, val: v3);
  NET_SendPacket(
    chan: nullptr,
    sock: this->m_Socket,
    to: adr,
    data: msg.m_pData,
    length: (msg.m_iCurBit + 7) >> 3,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10134C00
// Name: public: void CBaseServer::ClearReservationStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ClearReservationStatus(CBaseServer *this)
{
  this->m_ReservationStatus.m_bActive = false;
}

//------------------------------------------------------------------------------
// Address: 0x10134C10
// Name: public: virtual char const __near * CBaseServer::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseServer::GetName(CBaseServer *this)
{
  char *result; // eax

  if ( (host_name.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = host_name.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10134C40
// Name: bool UseCDKeyAuth(void)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl UseCDKeyAuth()
{
  return !serverGameDLL->ShouldPreferSteamAuth(this: serverGameDLL) && Host_IsSinglePlayerGame()
      || !sv.m_bIsDedicated && Steam3Client()->m_pSteamUser == nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10134C80
// Name: protected: virtual int CBaseServer::GetChallengeType(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetChallengeType(CBaseServer *this, netadr_s *adr)
{
  if ( (serverGameDLL->ShouldPreferSteamAuth(this: serverGameDLL) || !Host_IsSinglePlayerGame())
    && (sv.m_bIsDedicated || Steam3Client()->m_pSteamUser != nullptr) )
  {
    return 3;
  }
  else
  {
    return 2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134CC0
// Name: protected: virtual bool CBaseServer::CheckProtocol(struct netadr_s __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::CheckProtocol(CBaseServer *this, netadr_s *adr, int nProtocol)
{
  int HostVersion; // eax
  CBaseServer_vtbl *v5; // ebx
  int v6; // eax
  int v8; // eax

  if ( nProtocol == GetHostVersion() )
    return 1;
  HostVersion = GetHostVersion();
  v5 = this->__vftable;
  if ( nProtocol <= HostVersion )
  {
    v8 = GetHostVersion();
    v5->RejectConnection(
      this,
      a2: adr,
      a3: "This server is using a newer protocol ( %i ) than your client ( %i ).\n",
      v8,
      nProtocol);
  }
  else
  {
    v6 = GetHostVersion();
    v5->RejectConnection(
      this,
      a2: adr,
      a3: "This server is using an older protocol ( %i ) than your client ( %i ).\n",
      v6,
      nProtocol);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10134D30
// Name: protected: virtual bool CBaseServer::CheckChallengeType(class CBaseClient __near *,int,struct netadr_s __near &,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::CheckChallengeType(
        CBaseServer *this,
        CBaseClient *client,
        unsigned int nNewUserID,
        netadr_s *adr,
        int nAuthProtocol,
        const char *pchLogonCookie,
        unsigned int cbCookie)
{
  netadrtype_t type; // eax
  int v10; // edx
  unsigned int v11; // eax
  CSteam3Server *v12; // eax
  CSteam3Server *v13; // eax
  netadr_s checkAdr; // [esp+8h] [ebp-14h] BYREF
  CSteamID steamID; // [esp+14h] [ebp-8h] BYREF

  if ( (unsigned int)(nAuthProtocol - 1) > 2 )
  {
    this->RejectConnection(this, a2: adr, a3: "Invalid connection.\n");
    return 0;
  }
  else
  {
    if ( nAuthProtocol == 2 && (_V_strlen(str: pchLogonCookie) <= 0 || _V_strlen(str: pchLogonCookie) != 32) )
    {
      this->RejectConnection(this, a2: adr, a3: "Invalid authentication certificate length.\n");
      return 0;
    }
    if ( !this->m_bIsDedicatedForXbox )
    {
      if ( nAuthProtocol == 3 )
      {
        steamID.m_steamid.m_comp = 0;
        CBaseClient::SetSteamID(this: client, &steamID);
        if ( cbCookie - 1 > 0x7FE )
        {
          this->RejectConnection(this, a2: adr, a3: "STEAM certificate length error! %i/%i\n", cbCookie, 2048);
          return 0;
        }
        type = adr->type;
        v10 = *(_DWORD *)&adr->port;
        *(_DWORD *)checkAdr.ip = *(_DWORD *)adr->ip;
        checkAdr.type = type;
        *(_DWORD *)&checkAdr.port = v10;
        if ( CCircularBuffer::GetReadAvailable(this: adr) == NA_LOOPBACK || netadr_s::IsLocalhost(this: adr) )
        {
          v11 = netadr_s::addr_htonl(this: &net_local_adr);
          netadr_s::SetIP(this: &checkAdr, unIP: v11);
        }
        v12 = Steam3Server();
        if ( !CSteam3Server::NotifyClientConnect(
                this: v12,
                client,
                unUserID: nNewUserID,
                adr: &checkAdr,
                pvCookie: pchLogonCookie,
                ucbCookie: cbCookie)
          && Steam3Server()->m_eServerMode != eServerModeNoAuthentication )
        {
          this->RejectConnection(this, a2: adr, a3: "STEAM validation rejected\n");
          return 0;
        }
      }
      else
      {
        v13 = Steam3Server();
        if ( !CSteam3Server::NotifyLocalClientConnect(this: v13, client) )
        {
          this->RejectConnection(this, a2: adr, a3: "GSCreateLocalUser failed\n");
          return 0;
        }
      }
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134EF0
// Name: public: virtual bool CBaseServer::CheckIPRestrictions(struct netadr_s const __near &,int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::CheckIPRestrictions(CBaseServer *this, netadr_s *adr, int nAuthProtocol)
{
  return netadr_s::IsLoopback(this: adr)
      || Steam3Server()->m_eServerMode != eServerModeNoAuthentication
      || netadr_s::CompareClassBAdr(this: adr, a: &net_local_adr)
      || netadr_s::IsReservedAdr(this: adr);
}

//------------------------------------------------------------------------------
// Address: 0x10134F40
// Name: public: void CBaseServer::SetMasterServerRulesDirty(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SetMasterServerRulesDirty(CBaseServer *this)
{
  this->m_bMasterServerRulesDirty = true;
}

//------------------------------------------------------------------------------
// Address: 0x10134F50
// Name: public: virtual float CBaseServer::GetTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseServer::GetTime(CBaseServer *this)
{
  return (double)this->m_nTickCount * this->m_flTickInterval;
}

//------------------------------------------------------------------------------
// Address: 0x10134F60
// Name: public: float CBaseServer::GetFinalTickTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseServer::GetFinalTickTime(CBaseServer *this)
{
  return (double)(host_frameticks + this->m_nTickCount - host_currentframetick) * this->m_flTickInterval;
}

//------------------------------------------------------------------------------
// Address: 0x10134F90
// Name: public: virtual void CBaseServer::DisconnectClient(class IClient __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::DisconnectClient(CBaseServer *this, IClient *client, const char *reason)
{
  client->Disconnect(this: client, a2: reason);
}

//------------------------------------------------------------------------------
// Address: 0x10134FB0
// Name: public: virtual void CBaseServer::RejectConnection(struct netadr_s const __near &,char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseServer::RejectConnection(CBaseServer *this, netadr_s *adr, char *fmt, ...)
{
  const char *v3; // eax
  char text[1024]; // [esp+4h] [ebp-400h] BYREF
  va_list params; // [esp+418h] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: text, maxLen: 1024, pFormat: fmt, params);
  NET_OutOfBandPrintf(sock: this->m_Socket, adr, format: "%c%s", 57, text);
  v3 = netadr_s::ToString(this: adr, baseOnly: false);
  _Warning(a1: "RejectConnection: %s - %s\n", v3, text);
}

//------------------------------------------------------------------------------
// Address: 0x10135020
// Name: public: virtual void CBaseServer::SetTimescale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SetTimescale(CBaseServer *this, float flTimescale)
{
  this->m_flTimescale = flTimescale;
}

//------------------------------------------------------------------------------
// Address: 0x10135040
// Name: public: class INetworkStringTable __near * CBaseServer::GetInstanceBaselineTable(void)
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CBaseServer::GetInstanceBaselineTable(CBaseServer *this)
{
  if ( this->m_pInstanceBaselineTable == nullptr )
    this->m_pInstanceBaselineTable = this->m_StringTables->FindTable(this: this->m_StringTables, a2: "instancebaseline");
  return this->m_pInstanceBaselineTable;
}

//------------------------------------------------------------------------------
// Address: 0x10135070
// Name: public: class INetworkStringTable __near * CBaseServer::GetLightStyleTable(void)
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CBaseServer::GetLightStyleTable(CBaseServer *this)
{
  if ( this->m_pLightStyleTable == nullptr )
    this->m_pLightStyleTable = this->m_StringTables->FindTable(this: this->m_StringTables, a2: "lightstyles");
  return this->m_pLightStyleTable;
}

//------------------------------------------------------------------------------
// Address: 0x101350A0
// Name: public: class INetworkStringTable __near * CBaseServer::GetUserInfoTable(void)
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CBaseServer::GetUserInfoTable(CBaseServer *this)
{
  CNetworkStringTableContainer *m_StringTables; // ecx

  if ( this->m_pUserInfoTable == nullptr )
  {
    m_StringTables = this->m_StringTables;
    if ( m_StringTables == nullptr )
      return nullptr;
    this->m_pUserInfoTable = m_StringTables->FindTable(this: m_StringTables, a2: "userinfo");
  }
  return this->m_pUserInfoTable;
}

//------------------------------------------------------------------------------
// Address: 0x101350E0
// Name: protected: void CBaseServer::CheckMasterServerRequestRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::CheckMasterServerRequestRestart(CBaseServer *this)
{
  CSteam3Server *v1; // eax

  if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
  {
    v1 = Steam3Server();
    if ( v1->m_pSteamMasterServerUpdater->WasRestartRequested(this: v1->m_pSteamMasterServerUpdater) )
    {
      _Msg(a1: "%cMasterRequestRestart\n", 3);
      if ( g_pFileSystem->IsSteam(this: g_pFileSystem) )
      {
        _Msg(a1: "Your server needs to be restarted in order to receive the latest update.\n");
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SERVER_LOG, a2: 0) != 0 )
          _LoggingSystem_Log(
            a1: LOG_SERVER_LOG,
            a2: 0,
            a3: "Your server needs to be restarted in order to receive the latest update.\n");
      }
      else
      {
        _Msg(a1: "Your server is out of date.  Please update and restart.\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135170
// Name: protected: void CBaseServer::ForwardPacketsFromMasterServerUpdater(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ForwardPacketsFromMasterServerUpdater(CBaseServer *this)
{
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // edi
  int i; // esi
  unsigned __int16 v3; // bx
  unsigned __int8 data[16384]; // [esp+4h] [ebp-4018h] BYREF
  netadr_s to; // [esp+4004h] [ebp-18h] BYREF
  CBaseServer *v6; // [esp+4010h] [ebp-Ch]
  unsigned int unIP; // [esp+4014h] [ebp-8h] BYREF
  unsigned __int16 v8; // [esp+4018h] [ebp-4h] BYREF

  v6 = this;
  m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
  if ( m_pSteamMasterServerUpdater != nullptr )
  {
    for ( i = m_pSteamMasterServerUpdater->GetNextOutgoingPacket(
                this: m_pSteamMasterServerUpdater,
                a2: data,
                a3: 0x4000,
                a4: &unIP,
                a5: &v8);
          i > 0;
          i = m_pSteamMasterServerUpdater->GetNextOutgoingPacket(
                this: m_pSteamMasterServerUpdater,
                a2: data,
                a3: 0x4000,
                a4: &unIP,
                a5: &v8) )
    {
      v3 = v8;
      netadr_s::SetIP(this: &to, unIP);
      netadr_s::SetPort(this: &to, newport: v3);
      netadr_s::SetType(this: &to, newtype: NA_IP);
      NET_SendPacket(
        chan: nullptr,
        sock: v6->m_Socket,
        &to,
        data,
        length: i,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135230
// Name: CEventInfo_LessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CEventInfo_LessFunc(CEventInfo *const *lhs, CEventInfo *const *rhs)
{
  return **(_WORD **)lhs < **(_WORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x10135250
// Name: public: class CBaseClient __near * CBaseServer::GetBaseUserForSplitClient(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseServer::GetBaseUserForSplitClient(CBaseServer *this, CBaseClient *pSplitUser)
{
  CBaseClient *result; // eax

  result = pSplitUser->m_pAttachedTo;
  if ( result == nullptr )
    return pSplitUser;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10135270
// Name: public: void CBaseServer::UpdateReservedState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::UpdateReservedState(CBaseServer *this)
{
  if ( this->m_flReservationExpiryTime != 0.0 && this->m_nReservationCookie == 0
    || net_time > this->m_flReservationExpiryTime )
  {
    this->m_flReservationExpiryTime = 0.0;
    CGameServer::UpdateHibernationState(this: &sv);
  }
  if ( this->m_flTimeLastClientLeft != -1.0 )
    CGameServer::UpdateHibernationState(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x101352F0
// Name: public: unsigned __int64 CBaseServer::GetReservationCookie(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CBaseServer::GetReservationCookie(CBaseServer *this)
{
  return this->m_nReservationCookie;
}

//------------------------------------------------------------------------------
// Address: 0x10135300
// Name: public: char const __near * CBaseServer::GetGameType(enum CBaseServer::EGameTypeResultType)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseServer::GetGameType(CBaseServer *this, CBaseServer::EGameTypeResultType eResultType)
{
  if ( eResultType != EGAMETYPE_RESULTS_INCLUDE_PRIVATE )
    return CUtlString::operator char const *(this: &this->m_GameTypePublic);
  else
    return CUtlString::operator char const *(this: &this->m_GameTypePrivate);
}

//------------------------------------------------------------------------------
// Address: 0x10135330
// Name: public: bool CBaseServer::ShouldHideServer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::ShouldHideServer(CBaseServer *this)
{
  return serverGameDLL != nullptr && serverGameDLL->ShouldHideServer(this: serverGameDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10135350
// Name: public: bool CBaseServer::ShouldHideFromMasterServer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::ShouldHideFromMasterServer(CBaseServer *this)
{
  return !this->IsDedicated(this) || serverGameDLL != nullptr && serverGameDLL->ShouldHideServer(this: serverGameDLL);
}

//------------------------------------------------------------------------------
// Address: 0x10135380
// Name: public: virtual int CBaseServer::GetMaxClients(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetMaxClients(CBaseServer *this)
{
  return this->m_nMaxclients;
}

//------------------------------------------------------------------------------
// Address: 0x10135390
// Name: public: int CBaseServer::GetMaxHumanPlayers(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetMaxHumanPlayers(CBaseServer *this)
{
  int result; // eax

  if ( serverGameClients == nullptr )
    return this->GetMaxClients(this);
  result = serverGameClients->GetMaxHumanPlayers(this: serverGameClients);
  if ( result == -1 )
    return this->GetMaxClients(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101353C0
// Name: sv_showtags
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_showtags()
{
  const char *v0; // eax
  const char *v1; // eax

  _Msg(a1: "Tags:\n");
  v0 = CUtlString::operator char const *(this: &sv.m_GameTypePublic);
  _Msg(a1: "Public :  %s\n", v0);
  v1 = CUtlString::operator char const *(this: &sv.m_GameTypePrivate);
  _Msg(a1: "Private:  %s\n", v1);
}

//------------------------------------------------------------------------------
// Address: 0x10135400
// Name: SvPasswordChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl SvPasswordChangeCallback()
{
  if ( sv.IsActive(this: &sv) )
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: "heartbeat\n", nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10135430
// Name: protected: bool CBaseServer::ValidChallenge(struct netadr_s __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::ValidChallenge(CBaseServer *this, netadr_s *adr, int challengeNr)
{
  if ( !this->IsActive(this) || !this->IsMultiplayer(this) )
    return 0;
  if ( sv_enableoldqueries.m_pParent != nullptr && sv_enableoldqueries.m_pParent->m_Value.m_nValue != 0
    || this->CheckChallengeNr(this, a2: adr, a3: challengeNr) )
  {
    return 1;
  }
  this->ReplyServerChallenge(this, a2: adr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101354A0
// Name: protected: bool CBaseServer::ValidInfoChallenge(struct netadr_s __near &,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::ValidInfoChallenge(CBaseServer *this, netadr_s *adr, const char *nugget)
{
  return this->IsActive(this)
      && this->IsMultiplayer(this)
      && (sv_enableoldqueries.m_pParent != nullptr && sv_enableoldqueries.m_pParent->m_Value.m_nValue != 0
       || _V_stricmp(s1: nugget, s2: "Source Engine Query") == 0);
}

//------------------------------------------------------------------------------
// Address: 0x101354F0
// Name: public: virtual int CBaseServer::GetNumPlayers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumPlayers(CBaseServer *this)
{
  int v1; // edi
  CNetworkStringTableContainer *m_StringTables; // ecx
  int v5; // ebx
  _BYTE *v6; // eax
  int count; // [esp+8h] [ebp-4h]

  v1 = 0;
  count = 0;
  if ( this->m_pUserInfoTable == nullptr )
  {
    m_StringTables = this->m_StringTables;
    if ( m_StringTables == nullptr )
      return 0;
    this->m_pUserInfoTable = m_StringTables->FindTable(this: m_StringTables, a2: "userinfo");
  }
  if ( this->m_pUserInfoTable == nullptr )
    return 0;
  v5 = this->m_pUserInfoTable->GetNumStrings(this: this->m_pUserInfoTable);
  if ( v5 > 0 )
  {
    do
    {
      v6 = this->m_pUserInfoTable->GetStringUserData(this: this->m_pUserInfoTable, a2: v1, a3: 0);
      if ( v6 != nullptr && v6[116] == 0 )
        ++count;
      ++v1;
    }
    while ( v1 < v5 );
  }
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x10135580
// Name: public: void CBaseServer::SendReservationStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SendReservationStatus(CBaseServer *this)
{
  int HostVersion; // eax
  int m_iCurBit; // ecx
  bf_write msg; // [esp+4h] [ebp-28h] BYREF
  char buffer[16]; // [esp+1Ch] [ebp-10h] BYREF

  if ( this->m_ReservationStatus.m_bActive )
  {
    bf_write::bf_write(this: &msg, pData: buffer, nBytes: 16, nBits: -1);
    bf_write::WriteLong(this: &msg, val: -1);
    bf_write::WriteByte(this: &msg, val: 0x70u);
    HostVersion = GetHostVersion();
    bf_write::WriteLong(this: &msg, val: HostVersion);
    m_iCurBit = msg.m_iCurBit;
    if ( msg.m_iCurBit + 1 <= msg.m_nDataBits )
    {
      if ( !msg.m_bOverflow )
      {
        if ( this->m_ReservationStatus.m_bSuccess )
          msg.m_pData[msg.m_iCurBit >> 3] |= 1 << (msg.m_iCurBit & 7);
        else
          msg.m_pData[msg.m_iCurBit >> 3] &= ~(1 << (msg.m_iCurBit & 7));
        m_iCurBit = ++msg.m_iCurBit;
      }
    }
    else
    {
      msg.m_bOverflow = true;
    }
    NET_SendPacket(
      chan: nullptr,
      sock: this->m_Socket,
      to: &this->m_ReservationStatus.m_Remote,
      data: msg.m_pData,
      length: (m_iCurBit + 7) >> 3,
      pVoicePayload: nullptr,
      bUseCompression: false,
      unMillisecondsDelay: 0);
    this->m_ReservationStatus.m_bActive = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135650
// Name: protected: virtual void CBaseServer::CalculateCPUUsage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::CalculateCPUUsage(CBaseServer *this)
{
  HANDLE CurrentProcess; // eax
  unsigned int dwLowDateTime; // eax
  __int64 v4; // kr00_8
  double v5; // st7
  CStatTime *v6; // ecx
  CStatTime *dwHighDateTime; // ecx
  _FILETIME exitTime; // [esp+4h] [ebp-30h] BYREF
  __int64 v9; // [esp+Ch] [ebp-28h]
  _FILETIME userTime; // [esp+14h] [ebp-20h] BYREF
  _FILETIME kernelTime; // [esp+1Ch] [ebp-18h] BYREF
  _FILETIME creationTime; // [esp+24h] [ebp-10h] BYREF
  _FILETIME nowTime; // [esp+2Ch] [ebp-8h] BYREF

  if ( sv_stats.m_pParent != nullptr && sv_stats.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_fStartTime == 0.0 )
      this->m_fStartTime = _Plat_FloatTime((CStatTime *)this);
    if ( _Plat_FloatTime((CStatTime *)this) > this->m_fLastCPUCheckTime + 1.0 )
    {
      CurrentProcess = GetCurrentProcess();
      GetProcessTimes(
        hProcess: CurrentProcess,
        lpCreationTime: &creationTime,
        lpExitTime: &exitTime,
        lpKernelTime: &kernelTime,
        lpUserTime: &userTime);
      GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: &nowTime);
      dwLowDateTime = lastNow;
      if ( lastNow == 0 )
      {
        dwLowDateTime = creationTime.dwLowDateTime;
        lastNow = (__int64)creationTime;
      }
      v4 = *(_QWORD *)&userTime + *(_QWORD *)&kernelTime;
      v9 = *(_QWORD *)&userTime + *(_QWORD *)&kernelTime - lastTotalTime;
      v5 = (double)v9;
      v6 = (CStatTime *)(nowTime.dwLowDateTime - dwLowDateTime);
      v9 = *(_QWORD *)&nowTime - __PAIR64__(HIDWORD(lastNow), dwLowDateTime);
      this->m_fCPUPercent = v5 / (double)(__int64)(*(_QWORD *)&nowTime - __PAIR64__(HIDWORD(lastNow), dwLowDateTime));
      if ( _Plat_FloatTime(this: v6) > lastAvg + 5.0 )
      {
        dwHighDateTime = (CStatTime *)nowTime.dwHighDateTime;
        lastNow = (__int64)nowTime;
        lastTotalTime = v4;
        lastAvg = this->m_fLastCPUCheckTime;
      }
      this->m_fLastCPUCheckTime = _Plat_FloatTime(this: dwHighDateTime);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101357A0
// Name: protected: virtual bool CBaseServer::CheckPassword(struct netadr_s __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::CheckPassword(CBaseServer *this, netadr_s *adr, const char *password, const char *name)
{
  const char *v5; // edi
  int v6; // esi

  if ( this->m_nReservationCookie != 0 )
    return true;
  v5 = this->GetPassword(this);
  if ( v5 == nullptr )
    return true;
  if ( netadr_s::IsLocalhost(this: adr) || netadr_s::IsLoopback(this: adr) )
    return true;
  v6 = _V_strlen(str: v5);
  return v6 == _V_strlen(str: password) && V_strncmp(s1: password, s2: v5, count: v6) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10135830
// Name: public: virtual void CBaseServer::SetPaused(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SetPaused(CBaseServer *this, bool paused)
{
  void (__thiscall *BroadcastMessage_2)(struct CBaseServer *, INetMessage *, bool, bool); // edx
  SVC_SetPause setpause; // [esp+4h] [ebp-14h] BYREF

  if ( (this->m_State == ss_paused || this->IsPausable(this)) && this->IsActive(this) )
  {
    BroadcastMessage_2 = this->BroadcastMessage_2;
    setpause.m_bPaused = paused;
    setpause.m_bReliable = true;
    this->m_State = paused + 2;
    setpause.m_NetChannel = nullptr;
    setpause.__vftable = (SVC_SetPause_vtbl *)&SVC_SetPause::`vftable';
    BroadcastMessage_2(this, a2: &setpause, a3: false, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101358A0
// Name: public: bool CBaseServer::GetClassBaseline(class ServerClass __near *,void const __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::GetClassBaseline(
        CBaseServer *this,
        ServerClass *pClass,
        const void **pData,
        int *pDatalen)
{
  DWORD CurrentThreadId; // eax
  const void *v6; // eax
  bool result; // al

  if ( sv_instancebaselines.m_pParent != nullptr && sv_instancebaselines.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( pClass->m_InstanceBaselineIndex == 0xFFFF )
      _Error(a1: "SV_GetInstanceBaseline: missing instance baseline for class '%s'", pClass->m_pNetworkName);
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != g_svInstanceBaselineMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&g_svInstanceBaselineMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &g_svInstanceBaselineMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++g_svInstanceBaselineMutex.m_depth;
    }
    if ( this->m_pInstanceBaselineTable == nullptr )
      this->m_pInstanceBaselineTable = this->m_StringTables->FindTable(
                                         this: this->m_StringTables,
                                         a2: "instancebaseline");
    v6 = this->m_pInstanceBaselineTable->GetStringUserData(
           this: this->m_pInstanceBaselineTable,
           a2: pClass->m_InstanceBaselineIndex,
           a3: pDatalen);
    *pData = v6;
    result = v6 != nullptr;
    if ( --g_svInstanceBaselineMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&g_svInstanceBaselineMutex, 0);
  }
  else
  {
    *pData = dummy;
    *pDatalen = 1;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10135990
// Name: public: virtual void CBaseServer::BroadcastPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseServer::BroadcastPrintf(CBaseServer *this, const char *fmt, ...)
{
  void (__thiscall *BroadcastMessage_2)(struct CBaseServer *, INetMessage *, bool, bool); // edx
  char string[1024]; // [esp+0h] [ebp-C14h] BYREF
  SVC_Print print; // [esp+400h] [ebp-814h] BYREF
  va_list params; // [esp+C24h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  print.m_szText = string;
  BroadcastMessage_2 = this->BroadcastMessage_2;
  print.m_NetChannel = nullptr;
  print.m_bReliable = false;
  print.__vftable = (SVC_Print_vtbl *)&SVC_Print::`vftable';
  BroadcastMessage_2(this, a2: &print, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10135A00
// Name: public: virtual void CBaseServer::SetMaxClients(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SetMaxClients(CBaseServer *this, int number)
{
  int v2; // eax

  v2 = number;
  if ( number >= 1 )
  {
    if ( number > 64 )
      v2 = 64;
    this->m_nMaxclients = v2;
  }
  else
  {
    this->m_nMaxclients = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135A30
// Name: public: bool CBaseServer::IsExclusiveToLobbyConnections(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::IsExclusiveToLobbyConnections(CBaseServer *this)
{
  return this->IsDedicated(this)
      && sv_allow_lobby_connect_only.m_pParent != nullptr
      && sv_allow_lobby_connect_only.m_pParent->m_Value.m_nValue != 0
      && (sv_lan.m_pParent == nullptr || sv_lan.m_pParent->m_Value.m_nValue == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10135B00
// Name: private: int CBaseServer::GetNextUserID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNextUserID(CBaseServer *this)
{
  int m_Size; // ecx
  int v3; // esi
  int v4; // ebx
  CBaseClient *v5; // ecx
  int i; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Clients.m_Size;
  i = 0;
  if ( m_Size + 1 <= 0 )
    return this->m_nUserid + 1;
  while ( 1 )
  {
    v3 = 0;
    v4 = (this->m_nUserid + i + 1) % 0x7FFF;
    if ( m_Size > 0 )
    {
      do
      {
        v5 = this->m_Clients.m_Memory.m_pMemory[v3];
        if ( v5->GetUserID(this: &v5->IClient) == v4 )
          break;
        ++v3;
      }
      while ( v3 < this->m_Clients.m_Size );
    }
    m_Size = this->m_Clients.m_Size;
    if ( v3 == m_Size )
      break;
    if ( ++i >= m_Size + 1 )
      return this->m_nUserid + 1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10135B90
// Name: public: virtual int CBaseServer::GetNumFakeClients(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumFakeClients(CBaseServer *this)
{
  int v2; // ebx
  int i; // esi
  CBaseClient *v4; // ecx
  CBaseClient *v5; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->IsConnected(this: &v4->IClient) )
    {
      v5 = this->m_Clients.m_Memory.m_pMemory[i];
      if ( v5->IsFakeClient(this: &v5->IClient) )
        ++v2;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10135BF0
// Name: public: virtual int CBaseServer::GetNumClients(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumClients(CBaseServer *this)
{
  int v2; // ebx
  int i; // esi
  CBaseClient *v4; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->IsConnected(this: &v4->IClient) )
      ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10135C30
// Name: public: virtual int CBaseServer::GetNumProxies(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumProxies(CBaseServer *this)
{
  int v2; // ebx
  int i; // esi
  CBaseClient *v4; // ecx
  CBaseClient *v5; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->IsConnected(this: &v4->IClient) )
    {
      v5 = this->m_Clients.m_Memory.m_pMemory[i];
      if ( v5->IsHLTV(this: &v5->IClient) )
        ++v2;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10135C90
// Name: public: virtual bool CBaseServer::GetPlayerInfo(int,struct player_info_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::GetPlayerInfo(CBaseServer *this, int nClientIndex, unsigned int pinfo)
{
  player_info_s *v3; // edi
  void *m_StringTables; // ecx
  INetworkStringTable *UserInfoTable; // eax
  const void *v8; // eax

  v3 = (player_info_s *)pinfo;
  if ( pinfo == 0 )
    return 0;
  if ( nClientIndex >= 0 )
  {
    if ( this->m_pUserInfoTable != nullptr )
      goto LABEL_7;
    m_StringTables = this->m_StringTables;
    if ( m_StringTables != nullptr )
    {
      this->m_pUserInfoTable = (INetworkStringTable *)(*(int (__thiscall **)(void *, const char *))(*(_DWORD *)m_StringTables
                                                                                                  + 12))(
                                                        a1: m_StringTables,
                                                        a2: "userinfo");
LABEL_7:
      m_StringTables = this->m_pUserInfoTable;
    }
    if ( nClientIndex < (*(int (__thiscall **)(void *))(*(_DWORD *)m_StringTables + 12))(a1: m_StringTables) )
    {
      UserInfoTable = CBaseServer::GetUserInfoTable(this);
      v8 = UserInfoTable->GetStringUserData(this: UserInfoTable, a2: nClientIndex, a3: nullptr);
      if ( v8 != nullptr )
      {
        _V_memcpy(dest: v3, src: v8, count: 144);
        pinfo |= 3u;
        CByteswap::SwapFieldsToTargetEndian(
          this: (CByteswap *)&pinfo,
          pOutputBuffer: (char *)v3,
          pBaseData: (char *)v3,
          pDataMap: &player_info_s::m_DataMap);
        return 1;
      }
    }
  }
  _V_memset(dest: v3, fill: 0, count: 144);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10135D40
// Name: public: virtual void CBaseServer::UserInfoChanged(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseServer::UserInfoChanged(CBaseServer *this@<ecx>, int a2@<edi>, CByteswap nClientIndex)
{
  bool v4; // al
  CByteswap v5; // edi
  CBaseClient *v6; // ecx
  player_info_s pi; // [esp+4h] [ebp-94h] BYREF
  BOOL oldlock; // [esp+94h] [ebp-4h]

  if ( this->m_pUserInfoTable != nullptr )
  {
    v4 = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
    v5 = nClientIndex;
    LOBYTE(oldlock) = v4;
    v6 = this->m_Clients.m_Memory.m_pMemory[*(_DWORD *)&nClientIndex];
    if ( ((unsigned __int8 (__thiscall *)(CBaseClient *, player_info_s *, int))v6->FillUserInfo)(
           a1: v6,
           a2: &pi,
           a3: a2) != 0 )
    {
      nClientIndex = (CByteswap)(*(_DWORD *)&nClientIndex | 3);
      CByteswap::SwapFieldsToTargetEndian(
        this: &nClientIndex,
        pOutputBuffer: &pi,
        pBaseData: &pi,
        pDataMap: &player_info_s::m_DataMap);
      ((void (__stdcall *)(_DWORD, _DWORD))this->m_pUserInfoTable->SetStringUserData)(a1: v5, a2: 144);
    }
    else
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->m_pUserInfoTable->SetStringUserData)(a1: v5, a2: 0);
    }
    CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: oldlock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135DF0
// Name: protected: virtual void CBaseServer::ReplyChallenge(struct netadr_s __near &,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ReplyChallenge(CBaseServer *this, netadr_s *adr, bf_read *inmsg)
{
  netadr_s *v4; // ebx
  int v5; // edi
  CSteam3Server *v6; // eax
  const CSteamID *GSSteamID; // eax
  unsigned int m_unAll64Bits; // edi
  unsigned int m_unAll64Bits_high; // ebx
  ISteamGameServer *m_pSteamGameServer; // ecx
  int v11; // eax
  unsigned int v12; // edi
  char *v13; // eax
  const char *v14; // eax
  const char *v15; // edi
  int HostVersion; // eax
  char buffer[512]; // [esp+0h] [ebp-328h] BYREF
  char context[256]; // [esp+200h] [ebp-128h] BYREF
  float m_flTimeReservationGraceStarted; // [esp+300h] [ebp-28h]
  char chValidateChallenge[12]; // [esp+304h] [ebp-24h] BYREF
  bf_write msg; // [esp+310h] [ebp-18h] BYREF
  char bWillRequirePassword_3; // [esp+333h] [ebp+Bh]
  char bWillRequirePassword_3a; // [esp+333h] [ebp+Bh]
  int challengeNr; // [esp+334h] [ebp+Ch]

  m_flTimeReservationGraceStarted = this->m_flTimeReservationGraceStarted;
  if ( m_flTimeReservationGraceStarted < 0.0
    || net_time - m_flTimeReservationGraceStarted > sv_reservation_grace.m_pParent->m_Value.m_fValue )
  {
    v4 = adr;
  }
  else
  {
    v4 = adr;
    if ( !netadr_s::CompareAdr(this: adr, a: &this->m_adrReservationGraceStarted, onlyBase: false) )
      return;
  }
  bf_write::bf_write(this: &msg, pData: buffer, nBytes: 512, nBits: -1);
  memset(context, 0, sizeof(context));
  CBitRead::ReadString(this: inmsg, pStr: context, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  challengeNr = this->GetChallengeNr(this, a2: v4);
  v5 = this->GetChallengeType(this, a2: v4);
  bf_write::WriteLong(this: &msg, val: -1);
  bf_write::WriteByte(this: &msg, val: 0x41u);
  bf_write::WriteLong(this: &msg, val: challengeNr);
  bf_write::WriteLong(this: &msg, val: v5);
  if ( v5 == 3 )
  {
    v6 = Steam3Server();
    GSSteamID = CSteam3Server::GetGSSteamID(this: v6);
    m_unAll64Bits = GSSteamID->m_steamid.m_unAll64Bits;
    m_unAll64Bits_high = HIDWORD(GSSteamID->m_steamid.m_unAll64Bits);
    bf_write::WriteShort(this: &msg, val: 0);
    bf_write::WriteLongLong(this: &msg, val: __SPAIR64__(m_unAll64Bits_high, m_unAll64Bits));
    m_pSteamGameServer = Steam3Server()->m_pSteamGameServer;
    if ( m_pSteamGameServer != nullptr && m_pSteamGameServer->BSecure(this: m_pSteamGameServer) )
    {
      bf_write::WriteByte(this: &msg, val: 1u);
      v4 = adr;
    }
    else
    {
      bf_write::WriteByte(this: &msg, val: 0);
      v4 = adr;
    }
  }
  else
  {
    bf_write::WriteShort(this: &msg, val: 1);
    bf_write::WriteLongLong(this: &msg, val: 0);
    bf_write::WriteByte(this: &msg, val: 0);
  }
  v11 = _V_strlen(str: "connect");
  if ( V_strnicmp(s1: context, s2: "connect", n: v11) != 0 )
  {
    bf_write::WriteString(this: &msg, pStr: context);
  }
  else
  {
    if ( netadr_s::IsLoopback(this: v4) || (bWillRequirePassword_3 = 0, netadr_s::IsLocalhost(this: v4)) )
      bWillRequirePassword_3 = 1;
    if ( this->GetPassword(this) == nullptr
      || bWillRequirePassword_3 != 0
      || (bWillRequirePassword_3a = 1, CBaseServer::IsExclusiveToLobbyConnections(this)) )
    {
      bWillRequirePassword_3a = 0;
    }
    v12 = 0;
    v13 = &context[_V_strlen(str: "connect")];
    if ( *v13 == 48 && v13[1] == 120 )
    {
      memset(chValidateChallenge, 0, 9);
      V_strncpy(pDest: chValidateChallenge, pSrc: v13 + 2, maxLen: 9);
      v12 = strtoul(nptr: chValidateChallenge, endptr: nullptr, ibase: 16);
    }
    if ( !this->IsDedicated(this)
      || sv_allow_lobby_connect_only.m_pParent == nullptr
      || sv_allow_lobby_connect_only.m_pParent->m_Value.m_nValue == 0
      || sv_lan.m_pParent != nullptr && sv_lan.m_pParent->m_Value.m_nValue != 0
      || this->m_nReservationCookie != 0 )
    {
      bf_write::WriteString(this: &msg, pStr: context);
    }
    else if ( v12 == challengeNr )
    {
      bf_write::WriteString(this: &msg, pStr: "connect-granted");
      this->m_flTimeReservationGraceStarted = net_time;
      this->m_adrReservationGraceStarted.type = v4->type;
      *(_DWORD *)this->m_adrReservationGraceStarted.ip = *(_DWORD *)v4->ip;
      *(_DWORD *)&this->m_adrReservationGraceStarted.port = *(_DWORD *)&v4->port;
      v14 = netadr_s::ToString(this: v4, baseOnly: false);
      DevMsg(a1: "Server requires lobby reservation and is unreserved: granting reservation grace period to %s\n", v14);
    }
    else
    {
      bf_write::WriteString(this: &msg, pStr: "connect-retry");
    }
    v15 = defaultValue;
    if ( this->IsDedicated(this)
      && sv_allow_lobby_connect_only.m_pParent != nullptr
      && sv_allow_lobby_connect_only.m_pParent->m_Value.m_nValue != 0
      && (sv_lan.m_pParent == nullptr || sv_lan.m_pParent->m_Value.m_nValue == 0) )
    {
      v15 = "public";
      if ( sv_steamgroup_exclusive.m_pParent != nullptr && sv_steamgroup_exclusive.m_pParent->m_Value.m_nValue != 0 )
        v15 = "friends";
    }
    HostVersion = GetHostVersion();
    bf_write::WriteLong(this: &msg, val: HostVersion);
    bf_write::WriteString(this: &msg, pStr: v15);
    bf_write::WriteByte(this: &msg, val: bWillRequirePassword_3a != 0);
    bf_write::WriteLongLong(this: &msg, val: sv.m_nReservationCookie);
  }
  NET_SendPacket(
    chan: nullptr,
    sock: this->m_Socket,
    to: v4,
    data: msg.m_pData,
    length: (msg.m_iCurBit + 7) >> 3,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10136190
// Name: public: virtual void CBaseServer::GetNetStats(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::GetNetStats(CBaseServer *this, float *avgIn, float *avgOut)
{
  CBaseClient *v4; // esi
  bool (__thiscall *IsFakeClient)(IClient *); // eax
  IClient *v6; // esi
  int v7; // esi
  double v8; // st7
  double (__thiscall *v9)(int, _DWORD); // eax
  CBaseServer *v10; // [esp+0h] [ebp-4h]
  float *avgIna; // [esp+10h] [ebp+Ch]

  *avgOut = 0.0;
  *avgIn = 0.0;
  v10 = this;
  for ( avgIna = nullptr; (int)avgIna < v10->m_Clients.m_Size; avgIna = (float *)((char *)avgIna + 1) )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[(_DWORD)avgIna];
    IsFakeClient = v4->IsFakeClient;
    v6 = &v4->IClient;
    if ( !IsFakeClient(this: v6) && v6->IsConnected(this: v6) )
    {
      v7 = (int)v6->GetNetChannel(this: v6);
      v8 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v7 + 52))(a1: v7, a2: 1);
      v9 = *(double (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 52);
      *avgIn = v8 + *avgIn;
      *avgOut = v9(a1: v7, a2: 0) + *avgOut;
    }
    this = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136240
// Name: public: void CBaseServer::InactivateClients(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::InactivateClients(CBaseServer *this)
{
  int v1; // ebx
  CBaseClient *v2; // edi
  CSteam3Server *v3; // eax
  CBaseServer *i; // [esp+4h] [ebp-4h]

  v1 = 0;
  for ( i = this; v1 < i->m_Clients.m_Size; ++v1 )
  {
    v2 = this->m_Clients.m_Memory.m_pMemory[v1];
    if ( !v2->IsFakeClient(this: &v2->IClient)
      || v2->IsSplitScreenUser(this: &v2->IClient)
      || v2->IsHLTV(this: &v2->IClient) )
    {
      if ( v2->IsConnected(this: &v2->IClient) )
        v2->Inactivate(this: &v2->IClient);
    }
    else
    {
      v3 = Steam3Server();
      CSteam3Server::NotifyClientDisconnect(this: v3, client: v2);
      v2->Clear(this: &v2->IClient);
    }
    this = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101362E0
// Name: public: void CBaseServer::CheckTimeouts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::CheckTimeouts(CBaseServer *this)
{
  int v1; // ebx
  CBaseClient *v2; // eax
  IClient *v3; // esi
  int v4; // eax
  int v5; // edi
  IClient_vtbl *v6; // edi
  IClient_vtbl *v7; // edi
  IClient_vtbl *v8; // edi
  int v9; // [esp-Ch] [ebp-14h]
  int v10; // [esp-Ch] [ebp-14h]
  int v11; // [esp-Ch] [ebp-14h]
  CBaseServer *i; // [esp+4h] [ebp-4h]

  v1 = 0;
  for ( i = this; v1 < i->m_Clients.m_Size; ++v1 )
  {
    v2 = this->m_Clients.m_Memory.m_pMemory[v1];
    if ( v2 != nullptr )
      v3 = &v2->IClient;
    else
      v3 = nullptr;
    if ( !v3->IsFakeClient(this: v3) && v3->IsConnected(this: v3) )
    {
      v4 = (int)v3->GetNetChannel(this: v3);
      v5 = v4;
      if ( v4 != 0 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 236))(a1: v4) != 0 )
        {
          v6 = v3->__vftable;
          v9 = (int)v3->GetClientName(this: v3);
          v6->Disconnect(this: v3, a2: "%s timed out", v9);
        }
        else if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 296))(a1: v5) != 0 )
        {
          v7 = v3->__vftable;
          v10 = (int)v3->GetClientName(this: v3);
          v7->Disconnect(this: v3, a2: "%s disconnected", v10);
        }
        else if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 232))(a1: v5) != 0 )
        {
          v8 = v3->__vftable;
          v11 = (int)v3->GetClientName(this: v3);
          v8->Disconnect(this: v3, a2: "%s overflowed reliable channel", v11);
        }
      }
    }
    this = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101363D0
// Name: public: char const __near * CBaseServer::CompressPackedEntity(class ServerClass __near *,char const __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseServer::CompressPackedEntity(
        CBaseServer *this,
        ServerClass *pServerClass,
        const char *data,
        int *bits)
{
  SendTable *m_pTable; // ecx
  int v7; // [esp-Ch] [ebp-34h]
  bf_write writeBuf; // [esp+8h] [ebp-20h] BYREF
  const void *pBaselineData; // [esp+20h] [ebp-8h] BYREF
  int nBaselineBits; // [esp+24h] [ebp-4h] BYREF

  bf_write::bf_write(
    this: &writeBuf,
    pDebugName: "CompressPackedEntity",
    pData: s_packedData,
    nBytes: 0x4000,
    nBits: -1);
  pBaselineData = nullptr;
  nBaselineBits = 0;
  CBaseServer::GetClassBaseline(this, pClass: pServerClass, pData: &pBaselineData, pDatalen: &nBaselineBits);
  v7 = *bits;
  m_pTable = pServerClass->m_pTable;
  nBaselineBits *= 8;
  SendTable_WriteAllDeltaProps(
    pTable: m_pTable,
    pFromData: pBaselineData,
    nFromDataBits: nBaselineBits,
    pToData: data,
    nToDataBits: v7,
    nObjectID: -1,
    pBufOut: &writeBuf);
  *bits = writeBuf.m_iCurBit;
  return s_packedData;
}

//------------------------------------------------------------------------------
// Address: 0x10136450
// Name: public: char const __near * CBaseServer::UncompressPackedEntity(class PackedEntity __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseServer::UncompressPackedEntity(CBaseServer *this, PackedEntity *pPackedEntity, int *bits)
{
  PackedEntity *v3; // esi
  UnpackedDataCache_t *CachedUncompressedEntity; // edi
  int v5; // eax
  int m_iCurBit; // eax
  int *v8; // edx
  void *m_pData; // [esp-10h] [ebp-80h]
  ServerClass *m_pServerClass; // [esp-Ch] [ebp-7Ch]
  int v11; // [esp-Ch] [ebp-7Ch]
  bf_read oldBuf; // [esp+Ch] [ebp-64h] BYREF
  bf_read newBuf; // [esp+30h] [ebp-40h] BYREF
  bf_write outBuf; // [esp+54h] [ebp-1Ch] BYREF
  const void *pBaseline; // [esp+6Ch] [ebp-4h] BYREF

  v3 = pPackedEntity;
  pBaseline = this;
  CachedUncompressedEntity = CFrameSnapshotManager::GetCachedUncompressedEntity(
                               this: framesnapshotmanager,
                               packedEntity: pPackedEntity);
  v5 = CachedUncompressedEntity->bits;
  if ( v5 <= 0 )
  {
    m_pServerClass = v3->m_pServerClass;
    pPackedEntity = nullptr;
    CBaseServer::GetClassBaseline(
      this: (CBaseServer *)pBaseline,
      pClass: m_pServerClass,
      pData: &pBaseline,
      pDatalen: (int *)&pPackedEntity);
    oldBuf.m_bOverflow = false;
    oldBuf.m_nDataBits = -1;
    oldBuf.m_nDataBytes = 0;
    oldBuf.m_pDebugName = "UncompressPackedEntity1";
    CBitRead::StartReading(this: &oldBuf, pData: pBaseline, nBytes: (int)pPackedEntity, iStartBit: 0, nBits: -1);
    v11 = ((v3->m_nBits & 0x7FFFFFFF) + 7) >> 3;
    m_pData = v3->m_pData;
    newBuf.m_bOverflow = false;
    newBuf.m_nDataBits = -1;
    newBuf.m_nDataBytes = 0;
    newBuf.m_pDebugName = "UncompressPackedEntity2";
    CBitRead::StartReading(this: &newBuf, pData: m_pData, nBytes: v11, iStartBit: 0, nBits: -1);
    bf_write::bf_write(
      this: &outBuf,
      pDebugName: "UncompressPackedEntity3",
      pData: CachedUncompressedEntity->data,
      nBytes: 0x4000,
      nBits: -1);
    RecvTable_MergeDeltas(
      pTable: v3->m_pClientClass->m_pRecvTable,
      pOldState: &oldBuf,
      pNewState: &newBuf,
      pOut: &outBuf,
      objectID: -1,
      bDebugWatchInfo: false,
      pChangedProps: nullptr);
    m_iCurBit = outBuf.m_iCurBit;
    v8 = bits;
    CachedUncompressedEntity->bits = outBuf.m_iCurBit;
    *v8 = m_iCurBit;
  }
  else
  {
    *bits = v5;
  }
  return CachedUncompressedEntity->data;
}

//------------------------------------------------------------------------------
// Address: 0x10136550
// Name: public: virtual void CBaseServer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::Clear(CBaseServer *this)
{
  CNetworkStringTableContainer *m_StringTables; // ecx
  bool (__thiscall *IsMultiplayer)(struct CBaseServer *); // eax
  CUtlMemory<unsigned char,int> *p_m_SignonBuffer; // edi
  unsigned __int8 *m_pMemory; // eax
  unsigned __int8 *v6; // eax

  m_StringTables = this->m_StringTables;
  if ( m_StringTables != nullptr )
  {
    m_StringTables->RemoveAllTables(this: m_StringTables);
    this->m_StringTables = nullptr;
  }
  this->m_pInstanceBaselineTable = nullptr;
  this->m_pLightStyleTable = nullptr;
  this->m_pUserInfoTable = nullptr;
  this->m_pServerStartupTable = nullptr;
  this->m_State = ss_dead;
  this->m_nTickCount = 0;
  _V_memset(dest: this->m_szMapname, fill: 0, count: 64);
  _V_memset(dest: this->m_szSkyname, fill: 0, count: 64);
  IsMultiplayer = this->IsMultiplayer;
  this->clientDllCRC = 0;
  this->worldmapCRC = 0;
  this->stringTableCRC = 0;
  if ( IsMultiplayer(this) || this->IsDedicated(this) )
  {
    p_m_SignonBuffer = &this->m_SignonBuffer;
    if ( this->m_SignonBuffer.m_nAllocationCount < 96000 && this->m_SignonBuffer.m_nGrowSize >= 0 )
    {
      m_pMemory = p_m_SignonBuffer->m_pMemory;
      this->m_SignonBuffer.m_nAllocationCount = 96000;
      if ( m_pMemory != nullptr )
        v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 96000);
      else
        v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96000);
      p_m_SignonBuffer->m_pMemory = v6;
    }
  }
  else
  {
    p_m_SignonBuffer = &this->m_SignonBuffer;
    CUtlMemory<unsigned char,int>::EnsureCapacity(this: &this->m_SignonBuffer, num: 0x4000);
  }
  bf_write::StartWriting(
    this: &this->m_Signon,
    pData: p_m_SignonBuffer->m_pMemory,
    nBytes: this->m_SignonBuffer.m_nAllocationCount,
    iStartBit: 0,
    nBits: -1);
  CNetworkStringTable::SetTick(this: &this->m_Signon, pDebugName: "m_Signon");
  this->serverclasses = 0;
  this->serverclassbits = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10136660
// Name: public: virtual void CBaseServer::SendClientMessages(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SendClientMessages(CBaseServer *this, bool bSendSnapshots)
{
  int i; // edi
  CBaseClient *v4; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SendClientMessages",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->ShouldSendMessages(this: v4) )
    {
      if ( v4->m_NetChannel != nullptr )
      {
        v4->m_NetChannel->Transmit(this: v4->m_NetChannel, a2: false);
        v4->UpdateSendState(this: v4);
      }
      else
      {
        _Msg(a1: "Client has no netchannel.\n");
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10136700
// Name: public: virtual void CBaseServer::BroadcastMessage(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::BroadcastMessage(CBaseServer *this, INetMessage *msg, bool onlyActive, BOOL reliable)
{
  int i; // edi
  CBaseClient *v6; // esi
  bool (__thiscall *IsSpawned)(IClient *); // eax
  IClient *v8; // esi
  const char *v9; // eax

  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v6 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( !onlyActive || v6->IsActive(this: &v6->IClient) )
    {
      IsSpawned = v6->IsSpawned;
      v8 = &v6->IClient;
      if ( IsSpawned(this: v8)
        && !v8->SendNetMsg(this: v8, a2: msg, a3: reliable, a4: false)
        && (msg->IsReliable(this: msg) || reliable) )
      {
        v9 = v8->GetClientName(this: v8);
        DevMsg(a1: "BroadcastMessage: Reliable broadcast message overflow for client %s", v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101367B0
// Name: public: virtual void CBaseServer::BroadcastMessage(class INetMessage __near &,class IRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::BroadcastMessage(CBaseServer *this, INetMessage *msg, IRecipientFilter *filter)
{
  IRecipientFilter *v3; // ebx
  INetMessage_vtbl *v6; // edi
  bool v7; // al
  int v8; // edi
  CBaseClient *v9; // edi
  bool (__thiscall *IsSpawned)(IClient *); // eax
  IClient *v11; // edi
  const char *v12; // eax
  bool v13; // al
  const char *v14; // ebx
  bool v15; // zf
  const char *v16; // eax
  int v17; // eax
  int v18; // eax
  const char *v19; // [esp-14h] [ebp-24h]
  const char *v20; // [esp-10h] [ebp-20h]
  int v21; // [esp-Ch] [ebp-1Ch]
  int v22; // [esp-8h] [ebp-18h]
  int num; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  v3 = filter;
  if ( filter->IsInitMessage(this: filter) )
  {
    if ( this->IsActive(this) )
      _ConDMsg(a1: "SV_BroadcastMessage: Init message being created after signon buffer has been transmitted\n");
    if ( !msg->WriteToBuffer(this: msg, a2: &this->m_Signon) )
      Sys_Error(error: "SV_BroadcastMessage: Init message would overflow signon buffer!\n");
  }
  else
  {
    v6 = msg->__vftable;
    v7 = filter->IsReliable(this: filter);
    v6->SetReliable(this: msg, a2: v7);
    num = filter->GetRecipientCount(this: filter);
    for ( i = 0; i < num; ++i )
    {
      v8 = v3->GetRecipientIndex(this: v3, a2: i);
      if ( v8 < 1 || v8 > this->m_Clients.m_Size )
      {
        v13 = v3->IsInitMessage(this: v3);
        v14 = "yes";
        if ( !v13 )
          v14 = "no";
        v15 = !filter->IsReliable(this: filter);
        v16 = "yes";
        if ( v15 )
          v16 = "no";
        v17 = ((int (__thiscall *)(INetMessage *, const char *, const char *, int, int))msg->GetType)(
                a1: msg,
                a2: v16,
                a3: v14,
                a4: v8,
                a5: num);
        _Msg(
          a1: "SV_BroadcastMessage:  Recipient Filter for message type %i (reliable: %s, init: %s) with bogus client index (%"
          "i) in list of %i clients\n",
          v17,
          v19,
          v20,
          v21,
          v22);
        if ( msg->IsReliable(this: msg) )
        {
          v18 = msg->GetType(this: msg);
          Host_Error(error: "Reliable message (type %i) discarded.", v18);
        }
        v3 = filter;
      }
      else
      {
        v9 = this->m_Clients.m_Memory.m_pMemory[v8 - 1];
        IsSpawned = v9->IsSpawned;
        v11 = &v9->IClient;
        if ( IsSpawned(this: v11)
          && !v11->SendNetMsg(this: v11, a2: msg, a3: false, a4: false)
          && msg->IsReliable(this: msg) )
        {
          v12 = v11->GetClientName(this: v11);
          DevMsg(a1: "BroadcastMessage: Reliable filter message overflow for client %s", v12);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136960
// Name: public: void CBaseServer::RemoveTag(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::RemoveTag(CBaseServer *this, const char *pszTag, bool bSubTag)
{
  char *v3; // eax
  char *m_pszString; // eax
  int v5; // esi
  char v6; // bl
  int v7; // eax
  char tmptags[128]; // [esp+0h] [ebp-98h] BYREF
  CSplitString TagList; // [esp+80h] [ebp-18h] BYREF

  if ( (sv_tags.m_nFlags & 0x1000) != 0 || (v3 = sv_tags.m_pParent->m_Value.m_pszString) != nullptr && *v3 != 0 )
  {
    tmptags[0] = 0;
    if ( (sv_tags.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = sv_tags.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    CSplitString::CSplitString(this: &TagList, pString: m_pszString, pSeparator: ",");
    v5 = 0;
    v6 = 0;
    if ( TagList.m_Size > 0 )
    {
      do
      {
        if ( bSubTag )
          v7 = V_strnicmp(s1: TagList.m_Memory.m_pMemory[v5], s2: pszTag, n: strlen(pszTag));
        else
          v7 = _V_stricmp(s1: TagList.m_Memory.m_pMemory[v5], s2: pszTag);
        if ( v7 != 0 )
        {
          V_strncat(pDest: tmptags, pSrc: TagList.m_Memory.m_pMemory[v5], destBufferSize: 0x80u, max_chars_to_copy: -1);
          V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
        }
        else
        {
          v6 = 1;
        }
        ++v5;
      }
      while ( v5 < TagList.m_Size );
      if ( v6 != 0 )
        CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&sv_tags.IConVar, value: tmptags);
    }
    CSplitString::~CSplitString(this: &TagList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136A80
// Name: public: bool CBaseServer::IsPlayingSoloAgainstBots(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::IsPlayingSoloAgainstBots(CBaseServer *this)
{
  int NumFakeClients; // esi
  int v2; // eax

  if ( sv.m_State < ss_active
    || sv.m_nMaxclients <= 1
    || (NumFakeClients = CBaseServer::GetNumFakeClients(this: &sv),
        (v2 = CBaseServer::GetNumClients(this: &sv) - NumFakeClients) != 1) )
  {
    LOBYTE(v2) = 0;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10136AC0
// Name: public: int CBaseServer::GetNumHumanPlayers(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumHumanPlayers(CBaseServer *this)
{
  int v2; // ebx
  int i; // esi
  CBaseClient *v4; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->IsHumanPlayer(this: &v4->IClient) )
      ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10136B00
// Name: public: void CBaseServer::GetMasterServerPlayerCounts(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::GetMasterServerPlayerCounts(
        CBaseServer *this,
        int *nHumans,
        int *nMaxHumanSlots,
        int *nBots)
{
  int v5; // eax
  int m_nValue; // eax

  *nHumans = CBaseServer::GetNumHumanPlayers(this);
  if ( serverGameClients == nullptr || (v5 = serverGameClients->GetMaxHumanPlayers(this: serverGameClients)) == -1 )
    v5 = this->GetMaxClients(this);
  *nMaxHumanSlots = v5;
  *nBots = CBaseServer::GetNumFakeClients(this: &sv);
  if ( sv_visiblemaxplayers.m_pParent != nullptr )
  {
    m_nValue = sv_visiblemaxplayers.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
      *nMaxHumanSlots = m_nValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137040
// Name: protected: virtual bool CBaseServer::CheckChallengeNr(struct netadr_s __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::CheckChallengeNr(CBaseServer *this, netadr_s *adr, int nChallengeValue)
{
  int v5; // esi
  int v6; // edi
  bool v7; // zf
  challenge_t *m_pMemory; // eax
  const char *v9; // eax
  challenge_t *v10; // eax
  const char *v11; // eax

  if ( netadr_s::IsLoopback(this: adr) || this->m_bIsDedicatedForXbox )
    return 1;
  v5 = 0;
  if ( this->m_ServerQueryChallenges.m_Size <= 0 )
  {
LABEL_10:
    if ( nChallengeValue != -1 )
    {
      v9 = netadr_s::ToString(this: adr, baseOnly: false);
      _ConDMsg(a1: "No challenge from %s.\n", v9);
    }
    return 0;
  }
  v6 = 0;
  while ( 1 )
  {
    v7 = !netadr_s::CompareAdr(this: adr, a: &this->m_ServerQueryChallenges.m_Memory.m_pMemory[v6].adr, onlyBase: true);
    m_pMemory = this->m_ServerQueryChallenges.m_Memory.m_pMemory;
    if ( !v7 )
      break;
    if ( net_time > m_pMemory[v6].time + 3600.0 )
    {
      CUtlVector<challenge_t,CUtlMemory<challenge_t,int>>::FastRemove(this: &this->m_ServerQueryChallenges, elem: v5--);
      --v6;
    }
    ++v5;
    ++v6;
    if ( v5 >= this->m_ServerQueryChallenges.m_Size )
      goto LABEL_10;
  }
  v7 = nChallengeValue == m_pMemory[v5].challenge;
  v10 = &m_pMemory[v5];
  if ( !v7 )
    return 0;
  if ( net_time <= v10->time + 3600.0 )
    return 1;
  CUtlVector<challenge_t,CUtlMemory<challenge_t,int>>::FastRemove(this: &this->m_ServerQueryChallenges, elem: v5);
  v11 = netadr_s::ToString(this: adr, baseOnly: false);
  ConMsg(a1: "Old challenge from %s.\n", v11);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10137150
// Name: protected: void CBaseServer::UpdateMasterServerBasicData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::UpdateMasterServerBasicData(CBaseServer *this)
{
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // edi
  int v3; // eax
  char *m_pszString; // ebx
  ISteamMasterServerUpdater_vtbl *v5; // edi
  const char *v6; // eax
  const char *ProductString; // eax
  int HostVersion; // eax
  BOOL v9; // [esp-4h] [ebp-18h]
  int v10; // [esp-4h] [ebp-18h]
  ISteamMasterServerUpdater *pUpdater; // [esp+Ch] [ebp-8h]
  int nMaxHumans; // [esp+10h] [ebp-4h]

  m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
  pUpdater = m_pSteamMasterServerUpdater;
  CBaseServer::GetNumHumanPlayers(this);
  if ( serverGameClients == nullptr || (v3 = serverGameClients->GetMaxHumanPlayers(this: serverGameClients)) == -1 )
    v3 = this->GetMaxClients(this);
  nMaxHumans = v3;
  CBaseServer::GetNumFakeClients(this: &sv);
  if ( sv_visiblemaxplayers.m_pParent != nullptr && sv_visiblemaxplayers.m_pParent->m_Value.m_nValue > 0 )
    nMaxHumans = sv_visiblemaxplayers.m_pParent->m_Value.m_nValue;
  if ( (sv_region.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = sv_region.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v5 = m_pSteamMasterServerUpdater->__vftable;
  v6 = serverGameDLL->GetGameDescription(this: serverGameDLL);
  v9 = ((int (__thiscall *)(CBaseServer *, const char *))this->GetPassword)(a1: this, a2: v6) != 0;
  ProductString = Sys_GetProductString();
  v10 = ((unsigned __int8 (__thiscall *)(CBaseServer *, char *, const char *, int, BOOL))this->IsDedicated)(
          a1: this,
          a2: m_pszString,
          a3: ProductString,
          a4: nMaxHumans,
          a5: v9);
  HostVersion = GetHostVersion();
  ((void (__thiscall *)(ISteamMasterServerUpdater *, int, int))v5->SetBasicServerData)(
    a1: pUpdater,
    a2: HostVersion,
    a3: v10);
}

//------------------------------------------------------------------------------
// Address: 0x10137220
// Name: public: void CBaseServer::AddTag(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::AddTag(CBaseServer *this, const char *pszTag, const char *pszSubTagValue)
{
  char *m_pszString; // eax
  int i; // edi
  char *v5; // eax
  char tmptags[128]; // [esp+0h] [ebp-9Ch] BYREF
  CSplitString TagList; // [esp+80h] [ebp-1Ch] BYREF
  CBaseServer *v8; // [esp+98h] [ebp-4h]

  v8 = this;
  if ( (sv_tags.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = sv_tags.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  CSplitString::CSplitString(this: &TagList, pString: m_pszString, pSeparator: ",");
  for ( i = 0; i < TagList.m_Size; ++i )
  {
    if ( pszSubTagValue != nullptr )
    {
      if ( V_strnicmp(s1: TagList.m_Memory.m_pMemory[i], s2: pszTag, n: strlen(pszTag)) == 0 )
      {
        if ( _V_stricmp(s1: &TagList.m_Memory.m_pMemory[i][strlen(pszTag)], s2: pszSubTagValue) == 0 )
          goto LABEL_19;
        CBaseServer::RemoveTag(this: v8, pszTag, bSubTag: true);
      }
    }
    else if ( _V_stricmp(s1: TagList.m_Memory.m_pMemory[i], s2: pszTag) == 0 )
    {
      goto LABEL_19;
    }
  }
  tmptags[0] = 0;
  V_strncpy(pDest: tmptags, pSrc: pszTag, maxLen: 128);
  if ( pszSubTagValue != nullptr )
    V_strncat(pDest: tmptags, pSrc: pszSubTagValue, destBufferSize: 0x80u, max_chars_to_copy: -1);
  V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
  if ( (sv_tags.m_nFlags & 0x1000) != 0 )
  {
    v5 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v5 = sv_tags.m_pParent->m_Value.m_pszString;
    if ( v5 == nullptr )
      v5 = (char *)defaultValue;
  }
  V_strncat(pDest: tmptags, pSrc: v5, destBufferSize: 0x80u, max_chars_to_copy: -1);
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&sv_tags.IConVar, value: tmptags);
LABEL_19:
  CSplitString::~CSplitString(this: &TagList);
}

//------------------------------------------------------------------------------
// Address: 0x10137E20
// Name: public: CReferencedSnapshotList::~CReferencedSnapshotList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferencedSnapshotList::~CReferencedSnapshotList(CReferencedSnapshotList *this)
{
  int i; // edi
  bool v3; // sf
  CFrameSnapshot **m_pMemory; // eax

  for ( i = 0; i < this->m_vecSnapshots.m_Size; ++i )
    CFrameSnapshot::ReleaseReference(this: this->m_vecSnapshots.m_Memory.m_pMemory[i]);
  v3 = this->m_vecSnapshots.m_Memory.m_nGrowSize < 0;
  this->m_vecSnapshots.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_vecSnapshots.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecSnapshots.m_Memory.m_pMemory);
      this->m_vecSnapshots.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecSnapshots.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_vecSnapshots.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_vecSnapshots.m_Memory.m_pMemory;
  this->m_vecSnapshots.m_pElements = this->m_vecSnapshots.m_Memory.m_pMemory;
  if ( !v3 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_vecSnapshots.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecSnapshots.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137EA0
// Name: ServerTagsCleanUp
// Source: json
//------------------------------------------------------------------------------
void ServerTagsCleanUp()
{
  int i; // esi
  char *v1; // eax
  char v2; // cl
  int v3; // esi
  char **m_pMemory; // eax
  char tmptags[128]; // [esp+4h] [ebp-9Ch] BYREF
  ConVarRef sv_tags; // [esp+84h] [ebp-1Ch] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > TagList; // [esp+8Ch] [ebp-14h] BYREF

  if ( s_nNoReentry == 0 )
  {
    s_nNoReentry = 1;
    memset(&TagList, 0, sizeof(TagList));
    ConVarRef::ConVarRef(this: &sv_tags, pName: "sv_tags");
    if ( ConVarRef::IsValid(this: &sv_tags) )
    {
      tmptags[0] = 0;
      V_SplitString(pString: sv_tags.m_pConVarState->m_Value.m_pszString, pSeparator: ",", outStrings: &TagList);
      for ( i = 0; i < TagList.m_Size; ++i )
      {
        if ( i > 0 )
          V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
        v1 = TagList.m_Memory.m_pMemory[i];
        v2 = *v1;
        if ( *v1 != 0 )
        {
          while ( v2 == 32 )
          {
            v2 = *++v1;
            if ( v2 == 0 )
              goto LABEL_12;
          }
          if ( *v1 != 0 )
            V_strncat(pDest: tmptags, pSrc: v1, destBufferSize: 0x80u, max_chars_to_copy: -1);
        }
LABEL_12:
        ;
      }
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &TagList);
      V_SplitString(pString: tmptags, pSeparator: ",", outStrings: &TagList);
      CUtlVector<char *,CUtlMemory<char *,int>>::Sort(
        this: (CUtlVector<int,CUtlMemory<int,int> > *)&TagList,
        pfnCompare: (int (__cdecl *)(const void *, const void *))SortServerTags);
      v3 = 0;
      for ( tmptags[0] = 0; v3 < TagList.m_Size; ++v3 )
      {
        if ( v3 > 0 )
          V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
        V_strncat(pDest: tmptags, pSrc: TagList.m_Memory.m_pMemory[v3], destBufferSize: 0x80u, max_chars_to_copy: -1);
      }
      if ( _V_strcmp(s1: tmptags, s2: sv_tags.m_pConVarState->m_Value.m_pszString) != 0 )
        sv_tags.m_pConVar->SetValue_4(this: sv_tags.m_pConVar, a2: tmptags);
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &TagList);
    }
    m_pMemory = TagList.m_Memory.m_pMemory;
    TagList.m_Size = 0;
    if ( TagList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( TagList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TagList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        TagList.m_Memory.m_pMemory = nullptr;
      }
      TagList.m_Memory.m_nAllocationCount = 0;
    }
    TagList.m_pElements = m_pMemory;
    if ( TagList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    --s_nNoReentry;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138080
// Name: public: void CBaseServer::RecalculateTags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::RecalculateTags(CBaseServer *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *FirstSubKey; // edi
  ICvar_vtbl *v5; // esi
  const char *String; // eax
  ConVar *v7; // eax
  ConVar *v8; // esi
  const char *Default; // eax
  const char *m_pszString; // ecx
  const char *v11; // eax
  const char *v12; // eax
  char *v13; // esi
  char *v14; // eax
  char chGroupNameBuf[64]; // [esp+4h] [ebp-58h] BYREF
  int nHumans; // [esp+44h] [ebp-18h] BYREF
  int nBots; // [esp+48h] [ebp-14h] BYREF
  int minmaxplayers; // [esp+4Ch] [ebp-10h] BYREF
  int defaultmaxplayers; // [esp+50h] [ebp-Ch] BYREF
  int maxmaxplayers; // [esp+54h] [ebp-8h] BYREF
  KeyValues *pKV; // [esp+58h] [ebp-4h] BYREF

  if ( !this->IsHLTV(this) && !this->IsReplay(this) && !bRecalculatingTags )
  {
    bRecalculatingTags = true;
    if ( serverGameTags != nullptr )
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
      {
        v3 = KeyValues::KeyValues(this: v2, setName: "GameTags");
        pKV = v3;
      }
      else
      {
        pKV = nullptr;
        v3 = nullptr;
      }
      serverGameTags->GetTaggedConVarList(this: serverGameTags, a2: v3);
      FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          v5 = g_pCVar->__vftable;
          String = KeyValues::GetString(this: FirstSubKey, keyName: "convar", defaultValue: defaultValue);
          v7 = v5->FindVar_2(this: g_pCVar, a2: String);
          v8 = v7;
          if ( v7 != nullptr )
          {
            Default = ConVar::GetDefault(this: v7);
            if ( (v8->m_nFlags & 0x1000) != 0 )
            {
              m_pszString = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszString = v8->m_pParent->m_Value.m_pszString;
              if ( m_pszString == nullptr )
                m_pszString = defaultValue;
            }
            if ( _V_strcmp(s1: Default, s2: m_pszString) != 0 )
            {
              v11 = KeyValues::GetString(this: FirstSubKey, keyName: "tag", defaultValue: defaultValue);
              CBaseServer::AddTag(this, pszTag: v11, pszSubTagValue: nullptr);
            }
            else
            {
              v12 = KeyValues::GetString(this: FirstSubKey, keyName: "tag", defaultValue: defaultValue);
              CBaseServer::RemoveTag(this, pszTag: v12, bSubTag: false);
            }
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v3 = pKV;
      }
      KeyValues::deleteThis(this: v3);
    }
    minmaxplayers = 1;
    maxmaxplayers = 64;
    defaultmaxplayers = 1;
    serverGameClients->GetPlayerLimits(
      this: serverGameClients,
      a2: &minmaxplayers,
      a3: &maxmaxplayers,
      a4: &defaultmaxplayers);
    CBaseServer::GetMasterServerPlayerCounts(this, &nHumans, nMaxHumanSlots: (int *)&pKV, &nBots);
    if ( (int)pKV <= maxmaxplayers )
      CBaseServer::RemoveTag(this, pszTag: "increased_maxplayers", bSubTag: false);
    else
      CBaseServer::AddTag(this, pszTag: "increased_maxplayers", pszSubTagValue: nullptr);
    if ( g_bLowViolence )
      CBaseServer::AddTag(this, pszTag: "low_violence", pszSubTagValue: nullptr);
    else
      CBaseServer::RemoveTag(this, pszTag: "low_violence", bSubTag: false);
    if ( (sv_steamgroup.m_nFlags & 0x1000) != 0 )
    {
      v13 = "FCVAR_NEVER_AS_STRING";
LABEL_30:
      memset(chGroupNameBuf, 0, sizeof(chGroupNameBuf));
      V_snprintf(pDest: chGroupNameBuf, maxLen: 62, pFormat: "%si", v13);
      CBaseServer::AddTag(this, pszTag: "*grp:", pszSubTagValue: chGroupNameBuf);
      bRecalculatingTags = false;
      return;
    }
    v14 = sv_steamgroup.m_pParent->m_Value.m_pszString;
    if ( v14 != nullptr )
    {
      v13 = sv_steamgroup.m_pParent->m_Value.m_pszString;
      if ( *v14 != 0 )
        goto LABEL_30;
    }
    CBaseServer::RemoveTag(this, pszTag: "*grp:", bSubTag: true);
    bRecalculatingTags = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101382C0
// Name: public: void CBaseServer::ProcessSplitScreenDisconnects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ProcessSplitScreenDisconnects(CBaseServer *this)
{
  CBaseServer *v1; // edi
  int v2; // edx
  int max_splitscreen_players; // eax
  CBaseServer::SplitDisconnect_t *v4; // esi
  int v5; // ebx
  CBaseClient **m_SplitScreenUsers; // edi
  CBaseServer::SplitDisconnect_t *m_pMemory; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  i = 0;
  if ( this->m_QueuedForDisconnect.m_Size > 0 )
  {
    max_splitscreen_players = host_state.max_splitscreen_players;
    do
    {
      v4 = &v1->m_QueuedForDisconnect.m_Memory.m_pMemory[v2];
      v5 = 0;
      if ( max_splitscreen_players > 0 )
      {
        m_SplitScreenUsers = v4->m_pUser->m_SplitScreenUsers;
        do
        {
          if ( *m_SplitScreenUsers == v4->m_pSplit )
          {
            *m_SplitScreenUsers = nullptr;
            v4->m_pSplit->m_bSplitAllowFastDisconnect = true;
            v4->m_pSplit->Disconnect(this: &v4->m_pSplit->IClient, a2: "leaving splitscreen");
            v4->m_pSplit->m_bSplitScreenUser = false;
            max_splitscreen_players = host_state.max_splitscreen_players;
          }
          ++v5;
          ++m_SplitScreenUsers;
        }
        while ( v5 < max_splitscreen_players );
        v1 = this;
        v2 = i;
      }
      i = ++v2;
    }
    while ( v2 < v1->m_QueuedForDisconnect.m_Size );
  }
  v1->m_QueuedForDisconnect.m_Size = 0;
  if ( v1->m_QueuedForDisconnect.m_Memory.m_nGrowSize < 0 )
  {
    v1->m_QueuedForDisconnect.m_pElements = v1->m_QueuedForDisconnect.m_Memory.m_pMemory;
  }
  else
  {
    if ( v1->m_QueuedForDisconnect.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_QueuedForDisconnect.m_Memory.m_pMemory);
      v1->m_QueuedForDisconnect.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = v1->m_QueuedForDisconnect.m_Memory.m_pMemory;
    v1->m_QueuedForDisconnect.m_Memory.m_nAllocationCount = 0;
    v1->m_QueuedForDisconnect.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101383B0
// Name: SetMasterServerKeyValue
// Source: json
//------------------------------------------------------------------------------
void __usercall SetMasterServerKeyValue(ISteamMasterServerUpdater *pUpdater@<esi>, IConVar *pConVar@<eax>)
{
  const char *v2; // eax
  CSteam3Server *v3; // eax
  ConVarRef var; // [esp+4h] [ebp-Ch] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 32) && strlen(var.m_pConVarState->m_Value.m_pszString) != 0 )
    _V_stricmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: "none");
  v2 = var.m_pConVar->GetName(this: var.m_pConVar);
  ((void (__thiscall *)(ISteamMasterServerUpdater *, const char *))pUpdater->SetKeyValue)(a1: pUpdater, a2: v2);
  v3 = Steam3Server();
  if ( v3->m_pSteamGameServer != nullptr && v3->m_eServerMode >= eServerModeNoAuthentication )
    CBaseServer::RecalculateTags(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10138460
// Name: ServerNotifyVarChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServerNotifyVarChangeCallback(IConVar *pConVar)
{
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // esi

  if ( pConVar->IsFlagSet(this: pConVar, a2: 256) )
  {
    m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
    if ( m_pSteamMasterServerUpdater != nullptr )
      SetMasterServerKeyValue(pUpdater: m_pSteamMasterServerUpdater, pConVar);
    else
      sv.m_bMasterServerRulesDirty = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101384A0
// Name: public: CBaseServer::CBaseServer(void)
// Source: json
//------------------------------------------------------------------------------
CBaseServer *__thiscall CBaseServer::CBaseServer(CBaseServer *this)
{
  challenge_t *v2; // eax

  this->__vftable = (CBaseServer_vtbl *)&CBaseServer::`vftable';
  bf_write::bf_write(this: &this->m_Signon);
  this->m_SignonBuffer.m_pMemory = nullptr;
  this->m_SignonBuffer.m_nAllocationCount = 0;
  this->m_SignonBuffer.m_nGrowSize = 0;
  this->m_Clients.m_Memory.m_pMemory = nullptr;
  this->m_Clients.m_Memory.m_nAllocationCount = 0;
  this->m_Clients.m_Memory.m_nGrowSize = 0;
  this->m_Clients.m_Size = 0;
  this->m_Clients.m_pElements = nullptr;
  this->m_ServerQueryChallenges.m_Memory.m_pMemory = nullptr;
  this->m_ServerQueryChallenges.m_Memory.m_nAllocationCount = 1024;
  this->m_ServerQueryChallenges.m_Memory.m_nGrowSize = 0;
  v2 = (challenge_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20480);
  this->m_ServerQueryChallenges.m_Memory.m_pMemory = v2;
  this->m_ServerQueryChallenges.m_Size = 0;
  this->m_ServerQueryChallenges.m_pElements = v2;
  this->m_QueuedForDisconnect.m_Memory.m_pMemory = nullptr;
  this->m_QueuedForDisconnect.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedForDisconnect.m_Memory.m_nGrowSize = 0;
  this->m_QueuedForDisconnect.m_Size = 0;
  this->m_QueuedForDisconnect.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_GameTypePublic);
  CUtlString::CUtlString(this: &this->m_GameTypePrivate);
  netadr_s::SetIP(this: &this->m_adrReservationGraceStarted, unIP: 0);
  netadr_s::SetPort(this: &this->m_adrReservationGraceStarted, newport: 0);
  netadr_s::SetType(this: &this->m_adrReservationGraceStarted, newtype: NA_IP);
  *(_WORD *)&this->m_ReservationStatus.m_bActive = 0;
  netadr_s::SetIP(this: &this->m_ReservationStatus.m_Remote, unIP: 0);
  netadr_s::SetPort(this: &this->m_ReservationStatus.m_Remote, newport: 0);
  netadr_s::SetType(this: &this->m_ReservationStatus.m_Remote, newtype: NA_IP);
  this->m_flTickInterval = 0.029999999;
  this->m_StringTables = nullptr;
  this->m_pInstanceBaselineTable = nullptr;
  this->m_pLightStyleTable = nullptr;
  this->m_pUserInfoTable = nullptr;
  this->m_pServerStartupTable = nullptr;
  this->m_pDownloadableFileTable = nullptr;
  this->m_Socket = 1;
  this->m_nTickCount = 0;
  this->m_szMapname[0] = 0;
  this->m_szSkyname[0] = 0;
  this->m_Password[0] = 0;
  this->worldmapCRC = 0;
  this->clientDllCRC = 0;
  this->stringTableCRC = 0;
  this->serverclassbits = 0;
  this->serverclasses = 0;
  this->m_nSpawnCount = 0;
  this->m_nMaxclients = 0;
  this->m_flTimescale = 1.0;
  this->m_nUserid = 0;
  *(_WORD *)&this->m_bIsDedicated = 0;
  this->m_fCPUPercent = 0.0;
  this->m_flLastMasterServerUpdateTime = 0.0;
  this->m_fStartTime = 0.0;
  this->m_fLastCPUCheckTime = 0.0;
  this->m_nReservationCookie = 0;
  this->m_numGameSlots = 0;
  *(_WORD *)&this->m_bRestartOnLevelChange = 256;
  this->m_flReservationExpiryTime = -1.0;
  this->m_flTimeLastClientLeft = -1.0;
  this->m_flTimeReservationGraceStarted = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101386B0
// Name: public: virtual CBaseServer::~CBaseServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::~CBaseServer(CBaseServer *this)
{
  this->__vftable = (CBaseServer_vtbl *)&CBaseServer::`vftable';
  this->m_GameTypePrivate.m_Storage.m_nActualLength = 0;
  if ( this->m_GameTypePrivate.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_GameTypePrivate.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_GameTypePrivate.m_Storage.m_Memory.m_pMemory);
      this->m_GameTypePrivate.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_GameTypePrivate.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_GameTypePublic.m_Storage.m_nActualLength = 0;
  if ( this->m_GameTypePublic.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_GameTypePublic.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_GameTypePublic.m_Storage.m_Memory.m_pMemory);
      this->m_GameTypePublic.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_GameTypePublic.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_QueuedForDisconnect);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ServerQueryChallenges);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Clients);
  if ( this->m_SignonBuffer.m_nGrowSize >= 0 )
  {
    if ( this->m_SignonBuffer.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SignonBuffer.m_pMemory);
      this->m_SignonBuffer.m_pMemory = nullptr;
    }
    this->m_SignonBuffer.m_nAllocationCount = 0;
  }
  this->__vftable = (CBaseServer_vtbl *)&IConnectionlessPacketHandler::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10138780
// Name: protected: virtual int CBaseServer::GetChallengeNr(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CBaseServer::GetChallengeNr(CBaseServer *this, netadr_s *adr)
{
  int v2; // edx
  int v4; // edi
  int v5; // ebx
  int m_Size; // eax
  challenge_t *m_pMemory; // ecx
  challenge_t *v8; // eax
  challenge_t *v9; // ecx
  int v10; // eax
  challenge_t *v11; // ebx
  int v12; // edi
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  int oldest; // [esp+0h] [ebp-8h]
  int oldesta; // [esp+0h] [ebp-8h]
  float oldestTime; // [esp+4h] [ebp-4h]

  v2 = 0;
  v4 = 0;
  oldest = 0;
  oldestTime = 3.4028235e38;
  if ( this->m_ServerQueryChallenges.m_Size <= 0 )
  {
LABEL_8:
    if ( this->m_ServerQueryChallenges.m_Size > 0x4000 )
    {
      m_Size = this->m_ServerQueryChallenges.m_Size;
      if ( m_Size > 0 )
      {
        if ( v2 != m_Size - 1 )
        {
          m_pMemory = this->m_ServerQueryChallenges.m_Memory.m_pMemory;
          v8 = &m_pMemory[m_Size - 1];
          v9 = &m_pMemory[v2];
          v9->adr.type = v8->adr.type;
          *(_DWORD *)v9->adr.ip = *(_DWORD *)v8->adr.ip;
          *(_DWORD *)&v9->adr.port = *(_DWORD *)&v8->adr.port;
          v9->challenge = v8->challenge;
          v9->time = v8->time;
        }
        --this->m_ServerQueryChallenges.m_Size;
      }
    }
    v10 = CUtlVector<challenge_t,CUtlMemory<challenge_t,int>>::InsertBefore(
            this: &this->m_ServerQueryChallenges,
            elem: this->m_ServerQueryChallenges.m_Size);
    v11 = this->m_ServerQueryChallenges.m_Memory.m_pMemory;
    v12 = v10;
    oldesta = _RandomInt(this: v13, a2: 0, a3: 4095) << 16;
    v11[v12].challenge = oldesta | _RandomInt(this: v14, a2: 0, a3: 0xFFFF);
    this->m_ServerQueryChallenges.m_Memory.m_pMemory[v12].adr = *adr;
    this->m_ServerQueryChallenges.m_Memory.m_pMemory[v12].time = net_time;
    return this->m_ServerQueryChallenges.m_Memory.m_pMemory[v12].challenge;
  }
  else
  {
    v5 = 0;
    while ( !netadr_s::CompareAdr(
               this: adr,
               a: &this->m_ServerQueryChallenges.m_Memory.m_pMemory[v5].adr,
               onlyBase: true) )
    {
      if ( oldestTime > this->m_ServerQueryChallenges.m_Memory.m_pMemory[v5].time )
      {
        oldestTime = this->m_ServerQueryChallenges.m_Memory.m_pMemory[v5].time;
        oldest = v4;
      }
      ++v4;
      ++v5;
      if ( v4 >= this->m_ServerQueryChallenges.m_Size )
      {
        v2 = oldest;
        goto LABEL_8;
      }
    }
    this->m_ServerQueryChallenges.m_Memory.m_pMemory[v4].time = net_time;
    return this->m_ServerQueryChallenges.m_Memory.m_pMemory[v4].challenge;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138900
// Name: public: void CBaseServer::ReconnectClients(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ReconnectClients(CBaseServer *this)
{
  CBaseClient *v1; // edi
  int m_nSignonState; // eax
  char *m_pMemory; // eax
  char *v4; // eax
  NET_SignonState signon; // [esp+4h] [ebp-4Ch] BYREF
  CBaseServer *v6; // [esp+48h] [ebp-8h]
  int i; // [esp+4Ch] [ebp-4h]

  v6 = this;
  for ( i = 0; i < v6->m_Clients.m_Size; ++i )
  {
    v1 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v1->IsConnected(this: &v1->IClient) )
    {
      CBaseClient::SetSignonState(this: v1, nState: 2);
      m_nSignonState = v1->m_nSignonState;
      signon.m_bReliable = true;
      signon.m_NetChannel = nullptr;
      signon.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
      signon.m_nSignonState = m_nSignonState;
      signon.m_nSpawnCount = -1;
      memset(&signon.m_numServerPlayers, 0, 44);
      CBaseClient::FillSignOnFullServerInfo(this: v1, state: &signon);
      v1->SendNetMsg(this: &v1->IClient, a2: &signon, a3: false, a4: false);
      m_pMemory = signon.m_Mapname.m_Memory.m_pMemory;
      signon.m_Mapname.m_Size = 0;
      if ( signon.m_Mapname.m_Memory.m_nGrowSize >= 0 )
      {
        if ( signon.m_Mapname.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: signon.m_Mapname.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          signon.m_Mapname.m_Memory.m_pMemory = nullptr;
        }
        signon.m_Mapname.m_Memory.m_nAllocationCount = 0;
      }
      signon.m_Mapname.m_pElements = m_pMemory;
      if ( signon.m_Mapname.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          signon.m_Mapname.m_Memory.m_pMemory = nullptr;
        }
        signon.m_Mapname.m_Memory.m_nAllocationCount = 0;
      }
      v4 = signon.m_PlayersNetworkIds.m_Memory.m_pMemory;
      signon.m_PlayersNetworkIds.m_Size = 0;
      if ( signon.m_PlayersNetworkIds.m_Memory.m_nGrowSize >= 0 )
      {
        if ( signon.m_PlayersNetworkIds.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: signon.m_PlayersNetworkIds.m_Memory.m_pMemory);
          v4 = nullptr;
          signon.m_PlayersNetworkIds.m_Memory.m_pMemory = nullptr;
        }
        signon.m_PlayersNetworkIds.m_Memory.m_nAllocationCount = 0;
      }
      signon.m_PlayersNetworkIds.m_pElements = v4;
      if ( signon.m_PlayersNetworkIds.m_Memory.m_nGrowSize >= 0 && v4 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    this = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138A50
// Name: public: virtual void CBaseServer::Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::Init(CBaseServer *this, bool bIsDedicated)
{
  int v3; // eax
  bool v4; // al
  void (__thiscall *Clear)(CBaseServer *); // eax

  this->m_nMaxclients = 0;
  this->m_nSpawnCount = 0;
  this->m_nUserid = 1;
  this->m_bIsDedicated = bIsDedicated;
  v4 = false;
  if ( bIsDedicated )
  {
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-xlsp") != 0 )
      v4 = true;
  }
  this->m_bIsDedicatedForXbox = v4;
  this->m_Socket = 1;
  CNetworkStringTable::SetTick(this: &this->m_Signon, pDebugName: "m_Signon");
  g_pCVar->InstallGlobalChangeCallback(this: g_pCVar, a2: ServerNotifyVarChangeCallback);
  Clear = this->Clear;
  this->m_bMasterServerRulesDirty = true;
  Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10138AF0
// Name: protected: void CBaseServer::UpdateMasterServerRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::UpdateMasterServerRules(CBaseServer *this)
{
  CBaseServer *v1; // edi
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // esi
  ICvar::ICVarIteratorInternal *v3; // ebx
  ConCommandBase *v4; // edi
  IConVar *v5; // eax

  v1 = this;
  if ( this->m_bMasterServerRulesDirty )
  {
    m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
    if ( m_pSteamMasterServerUpdater != nullptr )
    {
      m_pSteamMasterServerUpdater->ClearAllKeyValues(this: m_pSteamMasterServerUpdater);
      v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
      v3->SetFirst(this: v3);
      if ( v3->IsValid(this: v3) )
      {
        do
        {
          v4 = v3->Get(this: v3);
          if ( v4->IsFlagSet(this: v4, a2: 256) )
          {
            v5 = (IConVar *)__RTDynamicCast(
                              inptr: v4,
                              VfDelta: 0,
                              SrcType: &ConCommandBase `RTTI Type Descriptor',
                              TargetType: &ConVar `RTTI Type Descriptor',
                              isReference: 0);
            if ( v5 != nullptr )
              SetMasterServerKeyValue(pUpdater: m_pSteamMasterServerUpdater, pConVar: v5 + 6);
          }
          v3->Next(this: v3);
        }
        while ( v3->IsValid(this: v3) );
        v1 = this;
      }
      if ( Steam3Server()->m_pSteamGameServer != nullptr )
        CBaseServer::RecalculateTags(this: v1);
      v1->m_bMasterServerRulesDirty = false;
      free(pMem: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138BE0
// Name: protected: class CBaseClient __near * CBaseServer::GetFreeClientInternal(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseServer::GetFreeClientInternal(CBaseServer *this, netadr_s *adr)
{
  CBaseClient *v3; // ebx
  const netadr_s *v4; // eax
  const char *v5; // eax
  int v6; // esi
  CBaseClient *v7; // eax
  void (__thiscall *Clear)(IClient *); // eax
  CBaseClient *v10; // eax
  CUtlMemory<S3RGBA,int> *p_m_Clients; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v15; // eax
  CBaseClient **v16; // eax
  int slot; // [esp+Ch] [ebp-8h]
  CBaseClient *freeclient; // [esp+10h] [ebp-4h]
  netadr_s *adra; // [esp+1Ch] [ebp+8h]

  freeclient = nullptr;
  slot = 0;
  if ( this->m_Clients.m_Size > 0 )
  {
    do
    {
      v3 = this->m_Clients.m_Memory.m_pMemory[slot];
      if ( !v3->IsFakeClient(this: &v3->IClient) )
      {
        if ( v3->IsConnected(this: &v3->IClient) )
        {
          v4 = v3->m_NetChannel->GetRemoteAddress(this: v3->m_NetChannel);
          if ( netadr_s::CompareAdr(this: adr, a: v4, onlyBase: false) )
          {
            v5 = netadr_s::ToString(this: adr, baseOnly: false);
            ConMsg(a1: "%s:reconnect\n", v5);
            if ( host_state.max_splitscreen_players > 1 )
            {
              v6 = (int)&v3->m_SplitScreenUsers[host_state.max_splitscreen_players];
              adra = (netadr_s *)(host_state.max_splitscreen_players - 1);
              do
              {
                v7 = *(CBaseClient **)(v6 - 4);
                v6 -= 4;
                if ( v7 != nullptr )
                {
                  this->RemoveClientFromGame(this, a2: v7);
                  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)v6 + 220) + 148))(
                    a1: *(_DWORD *)(*(_DWORD *)v6 + 220),
                    a2: 0);
                  *(_DWORD *)(*(_DWORD *)v6 + 220) = 0;
                  (*(void (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)v6 + 4) + 104))(a1: *(_DWORD *)v6 + 4);
                  *(_DWORD *)v6 = 0;
                }
                adra = (netadr_s *)((char *)adra - 1);
              }
              while ( adra != nullptr );
            }
            this->RemoveClientFromGame(this, a2: v3);
            v3->m_NetChannel->Shutdown(this: v3->m_NetChannel, a2: nullptr);
            Clear = v3->Clear;
            v3->m_NetChannel = nullptr;
            Clear(this: &v3->IClient);
            return v3;
          }
        }
        else if ( freeclient == nullptr )
        {
          freeclient = v3;
        }
      }
      ++slot;
    }
    while ( slot < this->m_Clients.m_Size );
    if ( freeclient != nullptr )
      return freeclient;
  }
  if ( this->m_Clients.m_Size >= this->m_nMaxclients )
    return nullptr;
  v10 = this->CreateNewClient(this, a2: this->m_Clients.m_Size);
  p_m_Clients = (CUtlMemory<S3RGBA,int> *)&this->m_Clients;
  m_Size = this->m_Clients.m_Size;
  freeclient = v10;
  m_nAllocationCount = p_m_Clients->m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(this: p_m_Clients, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Clients[1].m_pMemory;
  m_pMemory = p_m_Clients->m_pMemory;
  v15 = (int)p_m_Clients[1].m_pMemory - m_Size - 1;
  p_m_Clients[1].m_nAllocationCount = (int)p_m_Clients->m_pMemory;
  if ( v15 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
  v16 = (CBaseClient **)&p_m_Clients->m_pMemory[m_Size];
  if ( v16 != nullptr )
    *v16 = freeclient;
  return freeclient;
}

//------------------------------------------------------------------------------
// Address: 0x10138DD0
// Name: public: virtual void CBaseServer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::Shutdown(CBaseServer *this)
{
  int j; // edi
  CBaseClient *v3; // ecx
  int v4; // eax
  int k; // ebx
  CBaseClient *v6; // edi
  bool (__thiscall *IsConnected)(IClient *); // eax
  IClient *v8; // edi
  bool v9; // al
  IClient_vtbl *v10; // edx
  int m_Size; // eax
  int v12; // edi
  CBaseClient **m_pMemory; // ecx
  int v14; // eax
  CBaseClient **v15; // eax
  int v16; // ebx
  int m; // edi
  CBaseClient *v18; // ecx
  CSteam3Server *v19; // eax
  CUtlVector<CBaseClient *,CUtlMemory<CBaseClient *,int> > vecDelete; // [esp+4h] [ebp-18h] BYREF
  CBaseClient *i; // [esp+18h] [ebp-4h]

  g_pCVar->RemoveGlobalChangeCallback(this: g_pCVar, a2: ServerNotifyVarChangeCallback);
  if ( this->IsActive(this) )
  {
    this->m_State = ss_dead;
    memset(&vecDelete, 0, sizeof(vecDelete));
    for ( i = (CBaseClient *)3; i != nullptr; i = (CBaseClient *)((char *)i - 1) )
    {
      for ( j = 0; j < this->m_Clients.m_Size; ++j )
      {
        v3 = this->m_Clients.m_Memory.m_pMemory[j];
        v4 = (int)v3->GetNetChannel(this: &v3->IClient);
        if ( v4 != 0 )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 192))(a1: v4, a2: 0);
      }
      Sys_Sleep(msec: 10);
    }
    for ( k = this->m_Clients.m_Size - 1; k >= 0; --k )
    {
      v6 = this->m_Clients.m_Memory.m_pMemory[k];
      IsConnected = v6->IsConnected;
      i = v6;
      v8 = &v6->IClient;
      v9 = IsConnected(this: v8);
      v10 = v8->__vftable;
      if ( v9 )
      {
        if ( v10->IsSplitScreenUser(this: v8) )
          i->m_bSplitScreenUser = false;
        v8->Disconnect(this: v8, a2: "Server shutting down");
      }
      else
      {
        v10->Clear(this: v8);
      }
      m_Size = vecDelete.m_Size;
      v12 = vecDelete.m_Size;
      if ( vecDelete.m_Size + 1 > vecDelete.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&vecDelete,
          num: vecDelete.m_Size - vecDelete.m_Memory.m_nAllocationCount + 1);
        m_Size = vecDelete.m_Size;
      }
      m_pMemory = vecDelete.m_Memory.m_pMemory;
      vecDelete.m_Size = m_Size + 1;
      v14 = m_Size - v12;
      vecDelete.m_pElements = vecDelete.m_Memory.m_pMemory;
      if ( v14 > 0 )
      {
        _V_memmove(
          dest: &vecDelete.m_Memory.m_pMemory[v12 + 1],
          src: &vecDelete.m_Memory.m_pMemory[v12],
          count: 4 * v14);
        m_pMemory = vecDelete.m_Memory.m_pMemory;
      }
      v15 = &m_pMemory[v12];
      if ( v15 != nullptr )
        *v15 = i;
      if ( this->m_Clients.m_Size - k - 1 > 0 )
        _V_memmove(
          dest: &this->m_Clients.m_Memory.m_pMemory[k],
          src: &this->m_Clients.m_Memory.m_pMemory[k + 1],
          count: 4 * (this->m_Clients.m_Size - k - 1));
      --this->m_Clients.m_Size;
    }
    Sys_Sleep(msec: 100);
    v16 = vecDelete.m_Size;
    for ( m = 0; m < v16; ++m )
    {
      v18 = vecDelete.m_Memory.m_pMemory[m];
      if ( v18 != nullptr )
        ((void (__thiscall *)(CBaseClient *, int))v18->dtr_IGameEventListener2)(a1: v18, a2: 1);
    }
    this->Clear(this);
    if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
    {
      v19 = Steam3Server();
      v19->m_pSteamMasterServerUpdater->NotifyShutdown(this: v19->m_pSteamMasterServerUpdater);
    }
    g_pMaster->ShutdownConnection(this: g_pMaster, a2: this);
    if ( vecDelete.m_Memory.m_nGrowSize >= 0 && vecDelete.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecDelete.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138FE0
// Name: public: void CBaseServer::QueueSplitScreenDisconnect(class CBaseClient __near *,class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::QueueSplitScreenDisconnect(
        CBaseServer *this,
        CBaseClient *pSplitHost,
        CBaseClient *pSplitUser)
{
  CBaseServer::SplitDisconnect_t disc; // [esp+0h] [ebp-8h] BYREF

  disc.m_pUser = pSplitHost;
  disc.m_pSplit = pSplitUser;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->m_QueuedForDisconnect,
    elem: this->m_QueuedForDisconnect.m_Size,
    src: (const vgui::PropertySheet::Page_t *)&disc);
}

//------------------------------------------------------------------------------
// Address: 0x10139010
// Name: BuildTokenList
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildTokenList(
        CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *list@<esi>,
        char *pchString,
        unsigned __int8 chDelim)
{
  int v3; // ebx
  void *v4; // esp
  char *v5; // edi
  char *v6; // eax
  char *v7; // ebx
  char v8; // dl
  bool v9; // zf
  CUtlString *v10; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlString *v13; // ecx
  int v14; // eax
  CUtlString *v15; // edi
  char *v16; // eax
  CUtlString *v17; // eax
  unsigned __int8 v18[8]; // [esp+0h] [ebp-20h] BYREF
  CUtlString v19; // [esp+8h] [ebp-18h] BYREF
  CUtlString *string; // [esp+18h] [ebp-8h]
  char v21; // [esp+1Fh] [ebp-1h]

  v3 = _V_strlen(str: pchString);
  v4 = alloca(v3 + 1);
  v5 = (char *)v18;
  V_strncpy(pDest: (char *)v18, pSrc: pchString, maxLen: v3 + 1);
  strchr(string: v18, chr: chDelim);
  v7 = v6;
  if ( v6 != nullptr )
  {
    while ( v5 != nullptr )
    {
      v8 = *v7;
      *v7 = 0;
      v9 = *v5 == 0;
      v21 = v8;
      if ( !v9 )
      {
        v10 = CUtlString::CUtlString(this: &v19, pString: v5);
        m_pMemory = (int)list[1].m_pMemory;
        string = v10;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CPortalRect,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v13 = (CUtlString *)list->m_pMemory;
        v14 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v14 > 0 )
          _V_memmove(dest: &v13[m_pMemory + 1], src: &v13[m_pMemory], count: 16 * v14);
        v15 = (CUtlString *)&list->m_pMemory[m_pMemory];
        if ( v15 != nullptr )
          CUtlString::CUtlString(this: v15, string);
        v19.m_Storage.m_nActualLength = 0;
        if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v19.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
            v19.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v19.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
      v5 = v7 + 1;
      *v7 = v21;
      strchr(string: (unsigned __int8 *)v7 + 1, chr: chDelim);
      v7 = v16;
      if ( v16 == nullptr )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    if ( v5 != nullptr && *v5 != 0 )
    {
      v17 = CUtlString::CUtlString(this: &v19, pString: v5);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)list,
        elem: (int)list[1].m_pMemory,
        src: v17);
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139260
// Name: protected: void CBaseServer::UpdateMasterServer(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseServer::UpdateMasterServer(CBaseServer *this@<ecx>, int a2@<ebx>)
{
  long double v3; // st7
  char v4; // bl
  int v5; // eax
  CSteam3Server *v6; // eax
  int bActive; // [esp+4h] [ebp-4h]

  if ( this->ShouldUpdateMasterServer(this) )
  {
    if ( IsUsingMasterLegacyMode() )
    {
      g_pMaster->CheckHeartbeat(this: g_pMaster, a2: this);
    }
    else if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
    {
      CBaseServer::ForwardPacketsFromMasterServerUpdater(this);
      v3 = _Plat_FloatTime();
      if ( v3 - this->m_flLastMasterServerUpdateTime >= 2.0 )
      {
        this->m_flLastMasterServerUpdateTime = v3;
        CBaseServer::CheckMasterServerRequestRestart(this);
        if ( NET_IsDedicated() && sv_region.m_pParent != nullptr && sv_region.m_pParent->m_Value.m_nValue == -1 )
          CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_region.IConVar, value: 255);
        bActive = a2;
        v4 = 1;
        if ( (_S1_13 & 1) == 0 )
        {
          _S1_13 |= 1u;
          v5 = _CommandLine();
          bUpdateMasterServers = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 40))(
                                   a1: v5,
                                   a2: "-nomaster",
                                   a3: bActive) == 0;
        }
        if ( bUpdateMasterServers )
        {
          if ( !this->IsActive(this)
            || !this->IsMultiplayer(this)
            || !g_bEnableMasterServerUpdater
            || CBaseServer::IsSinglePlayerGame(this) )
          {
            v4 = 0;
          }
          LOBYTE(bActive) = v4;
          if ( CBaseServer::ShouldHideFromMasterServer(this) )
          {
            v4 = 0;
            LOBYTE(bActive) = 0;
          }
          v6 = Steam3Server();
          v6->m_pSteamMasterServerUpdater->SetActive(this: v6->m_pSteamMasterServerUpdater, a2: bActive);
          if ( v4 != 0 )
          {
            CBaseServer::UpdateMasterServerRules(this);
            this->UpdateMasterServerPlayers(this);
            CBaseServer::UpdateMasterServerBasicData(this);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101393C0
// Name: public: void CBaseServer::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseServer::RunFrame(CBaseServer *this@<ecx>, int a2@<ebx>)
{
  int i; // edi
  CBaseClient *v4; // ecx
  int j; // edi
  CBaseClient *v6; // ecx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseServer::RunFrame",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  NET_ProcessSocket(sock: this->m_Socket, handler: this);
  CBaseServer::CheckTimeouts(this);
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->m_bConVarsChanged )
      v4->UpdateUserSettings(this: v4);
  }
  for ( j = 0; j < this->m_Clients.m_Size; ++j )
  {
    v6 = this->m_Clients.m_Memory.m_pMemory[j];
    if ( v6->m_bSendServerInfo )
      v6->SendServerInfo(this: v6);
  }
  this->CalculateCPUUsage(this);
  CBaseServer::UpdateMasterServer(this, a2);
  if ( this->m_bMasterServerRulesDirty )
  {
    this->m_bMasterServerRulesDirty = false;
    CBaseServer::RecalculateTags(this);
  }
  CBaseServer::ProcessSplitScreenDisconnects(this);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101394A0
// Name: public: virtual class CBaseClient __near * CBaseServer::CreateFakeClient(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseServer::CreateFakeClient(CBaseServer *this, const char *name)
{
  CBaseClient *result; // eax
  CBaseClient *v4; // esi
  INetChannel *v5; // ebx
  const char *v6; // eax
  int NextUserID; // eax
  netadr_s adr; // [esp+8h] [ebp-18h] BYREF
  netadr_s v9; // [esp+14h] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  result = CBaseServer::GetFreeClientInternal(this, &adr);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = nullptr;
    if ( sv_stressbots.m_pParent != nullptr && sv_stressbots.m_pParent->m_Value.m_nValue != 0 )
    {
      netadr_s::SetIP(this: &v9, unIP: 0);
      netadr_s::SetPort(this: &v9, newport: 0);
      netadr_s::SetType(this: &v9, newtype: NA_IP);
      v6 = netadr_s::ToString(this: &v9, baseOnly: false);
      v5 = NET_CreateNetChannel(
             socket: this->m_Socket,
             adr: &v9,
             name: v6,
             handler: &v4->IClient,
             bForceNewChannel: true);
    }
    NextUserID = CBaseServer::GetNextUserID(this);
    this->m_nUserid = NextUserID;
    v4->Connect(this: &v4->IClient, a2: name, a3: NextUserID, a4: v5, a5: true, a6: CROSSPLAYPLATFORM_PC, a7: nullptr);
    v4->SetUserCVar(this: v4, a2: "rate", a3: "30000");
    v4->SetUserCVar(this: v4, a2: "cl_updaterate", a3: "20");
    v4->SetUserCVar(this: v4, a2: "cl_interp_ratio", a3: "1.0");
    v4->SetUserCVar(this: v4, a2: "cl_interp", a3: "0.1");
    v4->SetUserCVar(this: v4, a2: "cl_interpolate", a3: "0");
    v4->SetUserCVar(this: v4, a2: "cl_predict", a3: "1");
    v4->SetUserCVar(this: v4, a2: "cl_predictweapons", a3: "1");
    v4->SetUserCVar(this: v4, a2: "cl_lagcompensation", a3: "1");
    v4->SetUserCVar(this: v4, a2: "closecaption", a3: "0");
    v4->SetUserCVar(this: v4, a2: "english", a3: "1");
    v4->SetUserCVar(this: v4, a2: "cl_team", a3: "blue");
    v4->SetUserCVar(this: v4, a2: "hud_classautokill", a3: "1");
    v4->SetUserCVar(this: v4, a2: "tf_medigun_autoheal", a3: "0");
    v4->SetUserCVar(this: v4, a2: "cl_autorezoom", a3: "1");
    v4->SetUserCVar(this: v4, a2: "fov_desired", a3: "75");
    v4->ActivatePlayer(this: v4);
    v4->m_nSignonTick = this->m_nTickCount;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10139690
// Name: public: class CBaseClient __near * CBaseServer::CreateSplitClient(class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near &,class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseServer::CreateSplitClient(
        CBaseServer *this,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *vecUserInfo,
        CBaseClient *pAttachedTo)
{
  CBaseClient *FreeClientInternal; // eax
  CBaseClient *v5; // esi
  IClient *v7; // edi
  const char *v8; // eax
  int NextUserID; // eax
  IClient_vtbl *v10; // edx
  bool (__thiscall *CheckConnect)(IClient *); // eax
  bool v12; // al
  INetChannelHandler *v13; // [esp-Ch] [ebp-24h]
  netadr_s adr; // [esp+8h] [ebp-10h] BYREF
  INetChannel *netchan; // [esp+14h] [ebp-4h]

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  FreeClientInternal = CBaseServer::GetFreeClientInternal(this, &adr);
  v5 = FreeClientInternal;
  if ( FreeClientInternal == nullptr )
    return nullptr;
  v7 = &FreeClientInternal->IClient;
  v13 = &FreeClientInternal->IClient;
  v8 = netadr_s::ToString(this: &adr, baseOnly: false);
  netchan = NET_CreateNetChannel(socket: this->m_Socket, &adr, name: v8, handler: v13, bForceNewChannel: true);
  NextUserID = CBaseServer::GetNextUserID(this);
  this->m_nUserid = NextUserID;
  v7->Connect(
    this: &v5->IClient,
    a2: "split",
    a3: NextUserID,
    a4: netchan,
    a5: true,
    a6: pAttachedTo->m_ClientPlatform,
    a7: vecUserInfo);
  v10 = v7->__vftable;
  v5->m_pAttachedTo = pAttachedTo;
  CheckConnect = v10->CheckConnect;
  v5->m_bSplitScreenUser = true;
  v5->m_nSignonTick = this->m_nTickCount;
  v5->m_bSplitAllowFastDisconnect = true;
  v12 = CheckConnect(this: &v5->IClient);
  v5->m_bSplitAllowFastDisconnect = false;
  if ( v12 )
    return v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10139770
// Name: protected: virtual class IClient __near * CBaseServer::ConnectClient(struct netadr_s __near &,int,int,int,char const __near *,char const __near *,char const __near *,int,class CUtlVector<class CLC_SplitPlayerConnect,class CUtlMemory<class CLC_SplitPlayerConnect,int>> __near &,bool,enum CrossPlayPlatform_t)
// Source: json
//------------------------------------------------------------------------------
IClient *__userpurge CBaseServer::ConnectClient@<eax>(
        CBaseServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        netadr_s *adr,
        const char *protocol,
        int challenge,
        int authProtocol,
        const char *name,
        INetChannel *password,
        const char *hashedCDkey,
        int cdKeyLen,
        CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *splitScreenClients,
        bool isClientLowViolence,
        CrossPlayPlatform_t clientPlatform)
{
  const char *v15; // eax
  const char *v18; // eax
  CBaseServer_vtbl *v19; // edi
  const char *v20; // eax
  CBaseServer *v21; // ecx
  const char *v22; // eax
  int m_Size; // edi
  int v24; // edi
  CBaseClient *FreeClientInternal; // edi
  int NextUserID; // eax
  bool (__thiscall *CheckChallengeType)(CBaseServer *, CBaseClient *, int, netadr_s *, int, const char *, int); // edx
  const CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *p_m_UserInfo; // eax
  const char *v29; // eax
  INetChannel *NetChannel; // eax
  int v31; // ecx
  long double v32; // st7
  CFrameSnapshot *m_pObj; // ecx
  IClientMessageHandler *v34; // ebx
  int v35; // edi
  int v36; // eax
  IClient *v37; // edi
  const char *v38; // eax
  const char *v39; // eax
  unsigned __int64 v40; // [esp-18h] [ebp-2Ch]
  const char *v41; // [esp-10h] [ebp-24h]
  unsigned __int64 m_nReservationCookie; // [esp-10h] [ebp-24h]
  const char *v43; // [esp-Ch] [ebp-20h]
  unsigned __int64 uid; // [esp+4h] [ebp-10h] BYREF
  int nNextUserID; // [esp+Ch] [ebp-8h]
  const CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *list; // [esp+10h] [ebp-4h]
  IClient *bIsLocalConnection; // [esp+1Ch] [ebp+8h]
  char bIsLocalConnection_3; // [esp+1Fh] [ebp+Bh]
  char bIsLocalConnection_3a; // [esp+1Fh] [ebp+Bh]
  const char *value; // [esp+20h] [ebp+Ch]
  INetChannel *netchan; // [esp+30h] [ebp+1Ch]
  INetChannel *netchana; // [esp+30h] [ebp+1Ch]
  int i; // [esp+38h] [ebp+24h]
  int playerIndex; // [esp+40h] [ebp+2Ch]

  _COM_TimestampedLog(a1: "CBaseServer::ConnectClient");
  if ( !this->IsActive(this) )
  {
    v15 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Server not active, ignoring %s\n", v15);
    return nullptr;
  }
  if ( name != nullptr && password != nullptr && hashedCDkey != nullptr )
  {
    if ( !this->CheckProtocol(this, a2: adr, a3: (int)protocol) )
    {
      v18 = netadr_s::ToString(this: adr, baseOnly: false);
      DevMsg(a1: "Protocol error from %s\n", v18);
      return nullptr;
    }
    if ( !this->CheckChallengeNr(this, a2: adr, a3: challenge) )
    {
      this->RejectConnection(this, a2: adr, a3: "Bad challenge.\n");
      return nullptr;
    }
    if ( netadr_s::IsLocalhost(this: adr) || (bIsLocalConnection_3 = 0, netadr_s::IsLoopback(this: adr)) )
      bIsLocalConnection_3 = 1;
    if ( CBaseServer::IsExclusiveToLobbyConnections(this) && !CBaseServer::IsReserved(this) && bIsLocalConnection_3 == 0 )
    {
      v19 = this->__vftable;
      v20 = netadr_s::ToString(this: adr, baseOnly: false);
      v19->RejectConnection(
        this,
        a2: adr,
        a3: "Server only accepting connections from game lobby %s %d.\n",
        v20,
        challenge);
      return nullptr;
    }
    if ( this->IsDedicated(this) || bIsLocalConnection_3 != 0 )
      goto LABEL_30;
    if ( sv.m_bIsLevelMainMenuBackground )
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Background_Map");
      return nullptr;
    }
    if ( CBaseServer::IsSinglePlayerGame(this) )
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Single_Player");
      return nullptr;
    }
    if ( !CBaseServer::ShouldHideServer(this: v21) )
    {
LABEL_30:
      if ( this->IsHLTV(this) || this->IsReplay(this) )
        goto LABEL_69;
      if ( !this->CheckIPRestrictions(this, a2: adr, a3: authProtocol) )
      {
        this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_LAN_Game");
        return nullptr;
      }
      if ( this->CheckPassword(this, a2: adr, a3: (const char *)password, a4: name) )
      {
LABEL_69:
        if ( this->m_numGameSlots != 0 )
        {
          m_Size = splitScreenClients->m_Size;
          v24 = m_Size - this->GetNumFakeClients(this);
          if ( v24 + this->GetNumClients(this) > this->m_numGameSlots )
          {
            this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Server_Full");
            return nullptr;
          }
        }
        _COM_TimestampedLog(a1: "CBaseServer::ConnectClient:  GetFreeClient");
        FreeClientInternal = CBaseServer::GetFreeClientInternal(this, adr);
        if ( FreeClientInternal != nullptr )
        {
          NextUserID = CBaseServer::GetNextUserID(this);
          CheckChallengeType = this->CheckChallengeType;
          nNextUserID = NextUserID;
          if ( !CheckChallengeType(
                  this,
                  a2: FreeClientInternal,
                  a3: NextUserID,
                  a4: adr,
                  a5: authProtocol,
                  a6: hashedCDkey,
                  a7: cdKeyLen)
            || !this->FinishCertificateCheck(this, a2: adr, a3: authProtocol, a4: hashedCDkey) )
          {
            return nullptr;
          }
          bIsLocalConnection_3a = 0;
          if ( this->m_nReservationCookie == 0 )
            goto LABEL_53;
          if ( splitScreenClients->m_Size == 0 )
            goto LABEL_52;
          p_m_UserInfo = &splitScreenClients->m_Memory.m_pMemory->m_UserInfo;
          list = p_m_UserInfo;
          i = 0;
          if ( p_m_UserInfo->m_Size <= 0 )
            goto LABEL_52;
          netchan = nullptr;
          while ( 1 )
          {
            v41 = &p_m_UserInfo->m_Memory.m_pMemory->name[(unsigned int)netchan];
            value = v41 + 260;
            if ( _V_stricmp(s1: v41, s2: "cl_session") == 0 )
            {
              if ( sscanf(string: value, format: "$%llx", &uid) == 1 )
              {
                if ( uid == this->m_nReservationCookie )
                {
                  bIsLocalConnection_3a = 1;
                }
                else
                {
                  m_nReservationCookie = this->m_nReservationCookie;
                  v40 = uid;
                  v29 = netadr_s::ToString(this: adr, baseOnly: false);
                  _Warning(
                    a1: "mismatching cookie from %s, client %llx, server %llx!\n",
                    v29,
                    v40,
                    m_nReservationCookie);
                }
              }
              else
              {
                _Warning(a1: "failed to parse session id %s\n", value);
              }
            }
            netchan += 130;
            if ( ++i >= list->m_Size )
              break;
            p_m_UserInfo = list;
          }
          if ( bIsLocalConnection_3a != 0 )
          {
LABEL_53:
            _COM_TimestampedLog(a1: "CBaseServer::ConnectClient:  NET_CreateNetChannel");
            bIsLocalConnection = &FreeClientInternal->IClient;
            NetChannel = NET_CreateNetChannel(
                           socket: this->m_Socket,
                           adr,
                           name,
                           handler: &FreeClientInternal->IClient,
                           bForceNewChannel: false);
            netchana = NetChannel;
            if ( NetChannel == nullptr )
            {
              this->RejectConnection(this, a2: adr, a3: "Failed to create net channel.\n");
              return nullptr;
            }
            ((void (__thiscall *)(INetChannel *, int, int, int))NetChannel->SetChallengeNr)(
              a1: NetChannel,
              a2: challenge,
              a3: a2,
              a4: a3);
            _COM_TimestampedLog(a1: "CBaseServer::ConnectClient:  client->Connect");
            ((void (__thiscall *)(IClient *, const char *, int, INetChannel *, _DWORD))bIsLocalConnection->Connect)(
              a1: bIsLocalConnection,
              a2: name,
              a3: nNextUserID,
              a4: netchana,
              a5: 0);
            v31 = nNextUserID;
            FreeClientInternal->m_bLowViolence = isClientLowViolence;
            this->m_nUserid = v31;
            FreeClientInternal->m_fSnapshotInterval = 0.050000001;
            v32 = net_time + 0.05000000074505806;
            FreeClientInternal->m_nDeltaTick = -1;
            FreeClientInternal->m_nSignonTick = 0;
            FreeClientInternal->m_fNextMessageTime = v32;
            FreeClientInternal->m_nStringTableAckTick = 0;
            m_pObj = FreeClientInternal->m_pLastSnapshot.m_pObj;
            if ( m_pObj != nullptr )
            {
              CFrameSnapshot::ReleaseReference(this: m_pObj);
              FreeClientInternal->m_pLastSnapshot.m_pObj = nullptr;
            }
            NET_OutOfBandPrintf(sock: this->m_Socket, adr, format: "%c00000000000000", 66);
            if ( authProtocol == 2 )
            {
              V_strncpy(pDest: FreeClientInternal->m_GUID, pSrc: hashedCDkey, maxLen: 32);
              FreeClientInternal->m_GUID[32] = 0;
            }
            playerIndex = 1;
            if ( splitScreenClients->m_Size > 1 )
            {
              v34 = &FreeClientInternal->IClientMessageHandler;
              v35 = 1;
              do
              {
                ConMsg(a1: "Processing Split Screen connection packet.\n");
                v34->ProcessSplitPlayerConnect(this: v34, a2: &splitScreenClients->m_Memory.m_pMemory[v35++]);
                ++playerIndex;
              }
              while ( playerIndex < splitScreenClients->m_Size );
            }
            if ( netchana->IsLoopback(this: netchana) )
            {
              v37 = bIsLocalConnection;
            }
            else
            {
              v36 = (int)netchana->GetAddress(this: netchana);
              v37 = bIsLocalConnection;
              v38 = (const char *)((int (__thiscall *)(IClient *, int))bIsLocalConnection->GetClientName)(
                                    a1: bIsLocalConnection,
                                    a2: v36);
              ConMsg(a1: "Client \"%s\" connected (%s).\n", v38, v43);
            }
            this->m_flReservationExpiryTime = 0.0;
            this->m_flTimeLastClientLeft = -1.0;
            return v37;
          }
          else
          {
LABEL_52:
            this->RejectConnection(this, a2: adr, a3: "Invalid user info.\n");
            return nullptr;
          }
        }
        else
        {
          this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Server_Full");
          return nullptr;
        }
      }
      else
      {
        v22 = netadr_s::ToString(this: adr, baseOnly: false);
        ConMsg(a1: "%s:  password failed.\n", v22);
        this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Bad_Password");
        return nullptr;
      }
    }
    else
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Hidden_Game");
      return nullptr;
    }
  }
  else
  {
    v39 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Bad auth data from %s\n", v39);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139D60
// Name: public: virtual bool CBaseServer::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::ProcessConnectionlessPacket(CBaseServer *this, netpacket_s *packet)
{
  char v2; // dl
  char v3; // bl
  char m_nInBufWord; // si
  int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // ebx
  bool result; // al
  const char *v9; // eax
  unsigned int v10; // esi
  int v11; // eax
  unsigned int v12; // edi
  int v13; // edi
  unsigned int v14; // edx
  unsigned int v15; // ebx
  __int64 v16; // rax
  int m_nBitsAvail; // edx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ebx
  unsigned int v20; // esi
  unsigned int v21; // ebx
  int v22; // edi
  unsigned int v23; // edi
  unsigned int v24; // ebx
  int v25; // esi
  int v26; // esi
  unsigned int v27; // ebx
  unsigned int v28; // edi
  unsigned int v29; // eax
  unsigned int v30; // esi
  const unsigned int *v31; // edi
  const unsigned int *v32; // eax
  int m_nInBufWord_low; // esi
  int v34; // edx
  unsigned int v35; // ebx
  int v36; // edi
  int v37; // ecx
  int v38; // ecx
  int v39; // eax
  unsigned int v40; // edi
  int v41; // edx
  int v42; // edi
  int v43; // eax
  const char *v44; // eax
  unsigned int v45; // esi
  unsigned int v46; // edx
  bool IsLoopback; // al
  CBaseServer *v48; // ebx
  bool IsExclusiveToLobbyConnections; // al
  int m_nGrowSize; // esi
  int m_Size; // edi
  const char *v52; // eax
  unsigned int v53; // eax
  unsigned int m_nReservationCookie_high; // ecx
  const char *v55; // eax
  CLC_SplitPlayerConnect *m_pElements; // esi
  __int16 v57; // di
  __int16 v58; // di
  int v59; // eax
  unsigned int v60; // esi
  unsigned int v61; // edx
  KeyValues *v62; // eax
  KeyValues *v63; // esi
  IMatchEventsSubscription *v64; // eax
  CGameServer *v65; // ebx
  CSteam3Server *v66; // eax
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // edi
  char *v68; // eax
  CBaseServer *m_pData; // edx
  ISteamMasterServerUpdater_vtbl *v70; // esi
  unsigned __int32 v71; // ebx
  unsigned __int16 Port; // ax
  __int64 v73; // [esp-8h] [ebp-A78h]
  unsigned __int64 v74; // [esp-8h] [ebp-A78h]
  unsigned __int64 m_nReservationCookie; // [esp+0h] [ebp-A70h]
  long double v76; // [esp+0h] [ebp-A70h]
  char pOut[12]; // [esp+14h] [ebp-A5Ch] BYREF
  char cdkey[2048]; // [esp+20h] [ebp-A50h] BYREF
  char name[256]; // [esp+820h] [ebp-250h] BYREF
  char password[256]; // [esp+920h] [ebp-150h] BYREF
  CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > splitScreenPlayers; // [esp+A20h] [ebp-50h]
  unsigned __int64 nReservationCookie; // [esp+A34h] [ebp-3Ch]
  unsigned int v83; // [esp+A3Ch] [ebp-34h]
  CBaseServer *v84; // [esp+A40h] [ebp-30h]
  unsigned int m_nDataBytes; // [esp+A44h] [ebp-2Ch]
  int v86; // [esp+A48h] [ebp-28h]
  CBitRead message; // [esp+A4Ch] [ebp-24h] BYREF

  LODWORD(nReservationCookie) = this;
  message = (CBitRead)packet->message;
  if ( message.m_nBitsAvail < 8 )
  {
    m_nInBufWord = message.m_nInBufWord;
    v5 = 8 - message.m_nBitsAvail;
    if ( message.m_pDataIn == message.m_pBufferEnd )
    {
      message.m_nBitsAvail = 1;
      message.m_bOverflow = true;
      message.m_nInBufWord = 0;
      ++message.m_pDataIn;
      v3 = 0;
    }
    else if ( message.m_pDataIn <= message.m_pBufferEnd )
    {
      v6 = *message.m_pDataIn;
      message.m_nInBufWord = *message.m_pDataIn++;
      if ( message.m_bOverflow )
      {
        v3 = 0;
      }
      else
      {
        v7 = (v6 & CBitBuffer::s_nMaskTable[v5]) << SLOBYTE(message.m_nBitsAvail);
        message.m_nBitsAvail = 32 - v5;
        v3 = m_nInBufWord | v7;
        message.m_nInBufWord = v6 >> v5;
      }
    }
    else
    {
      message.m_bOverflow = true;
      message.m_nInBufWord = 0;
      v3 = 0;
    }
  }
  else
  {
    v2 = message.m_nInBufWord;
    message.m_nBitsAvail -= 8;
    if ( message.m_nBitsAvail != 0 )
    {
      message.m_nInBufWord >>= 8;
      v3 = v2;
    }
    else
    {
      message.m_nBitsAvail = 32;
      if ( message.m_pDataIn == message.m_pBufferEnd )
      {
        message.m_nBitsAvail = 1;
        message.m_nInBufWord = 0;
        ++message.m_pDataIn;
        v3 = v2;
      }
      else
      {
        if ( message.m_pDataIn <= message.m_pBufferEnd )
        {
          message.m_nInBufWord = *message.m_pDataIn++;
        }
        else
        {
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
        }
        v3 = v2;
      }
    }
  }
  result = CheckConnectionLessRateLimits(adr: &packet->from);
  if ( !result )
    return result;
  if ( ((*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)nReservationCookie + 84))(a1: nReservationCookie) == 0
     || !Host_ShouldRun())
    && ((*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)nReservationCookie + 92))(a1: nReservationCookie) != 0
     || v3 != 0) )
  {
    return true;
  }
  switch ( v3 )
  {
    case 0:
      v62 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v62 != nullptr )
        v63 = KeyValues::KeyValues(this: v62, setName: "OnNetLanConnectionlessPacket");
      else
        v63 = nullptr;
      KeyValues::SetPtr(this: v63, keyName: "rawpkt", value: packet);
      v64 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v64->BroadcastEvent(this: v64, a2: v63);
      return true;
    case 56:
      v10 = message.m_nInBufWord;
      if ( message.m_nBitsAvail < 32 )
      {
        v11 = 32 - message.m_nBitsAvail;
        if ( message.m_pDataIn == message.m_pBufferEnd )
        {
          message.m_nBitsAvail = 1;
          message.m_nInBufWord = 0;
          ++message.m_pDataIn;
          message.m_bOverflow = true;
          v10 = 0;
        }
        else if ( message.m_pDataIn <= message.m_pBufferEnd )
        {
          v12 = *message.m_pDataIn;
          message.m_nInBufWord = *message.m_pDataIn++;
          if ( message.m_bOverflow )
          {
            v10 = 0;
          }
          else
          {
            v10 |= (v12 & CBitBuffer::s_nMaskTable[v11]) << SLOBYTE(message.m_nBitsAvail);
            message.m_nInBufWord = v12 >> v11;
          }
        }
        else
        {
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
          v10 = 0;
        }
      }
      else
      {
        message.m_nBitsAvail -= 32;
        if ( message.m_nBitsAvail != 0 )
        {
          message.m_nInBufWord = 0;
        }
        else
        {
          message.m_nBitsAvail = 32;
          if ( message.m_pDataIn == message.m_pBufferEnd )
          {
            message.m_nBitsAvail = 1;
            message.m_nInBufWord = 0;
            ++message.m_pDataIn;
          }
          else if ( message.m_pDataIn <= message.m_pBufferEnd )
          {
            message.m_nInBufWord = *message.m_pDataIn++;
          }
          else
          {
            message.m_bOverflow = true;
            message.m_nInBufWord = 0;
          }
        }
      }
      v13 = CBitRead::ReadLongLong(this: &message);
      v15 = v14;
      LODWORD(v16) = CBitRead::ReadLongLong(this: &message);
      _Msg(a1: "C2S_VALIDATE_SESSION from %llx, session %llx, protocol %d.\n", __PAIR64__(v15, v13), v16, v10);
      if ( GetHostVersion() != v10 )
        return true;
      HostValidateSessionImpl();
      return true;
    case 87:
      (*(void (__thiscall **)(_DWORD, netpacket_s *))(*(_DWORD *)nReservationCookie + 244))(
        a1: nReservationCookie,
        a2: packet);
      return true;
    case 105:
      NET_OutOfBandPrintf(sock: packet->source, adr: &packet->from, format: "%c00000000000000", 106);
      return true;
    case 106:
      v9 = netadr_s::ToString(this: &packet->from, baseOnly: false);
      ConMsg(a1: "A2A_ACK from %s\n", v9);
      return true;
    case 107:
      m_nBitsAvail = message.m_nBitsAvail;
      m_pDataIn = message.m_pDataIn;
      if ( message.m_nBitsAvail < 32 )
      {
        v21 = message.m_nInBufWord;
        v22 = 32 - message.m_nBitsAvail;
        if ( message.m_pDataIn == message.m_pBufferEnd )
        {
          v20 = 0;
          m_nBitsAvail = 1;
          m_pDataIn = message.m_pDataIn + 1;
          message.m_nBitsAvail = 1;
          message.m_nInBufWord = 0;
          ++message.m_pDataIn;
          message.m_bOverflow = true;
          v83 = 0;
          m_pBufferEnd = message.m_pBufferEnd;
          goto LABEL_61;
        }
        if ( message.m_pDataIn > message.m_pBufferEnd )
        {
          m_pBufferEnd = message.m_pBufferEnd;
          v20 = 0;
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
          v83 = 0;
          goto LABEL_61;
        }
        v20 = *message.m_pDataIn;
        m_pDataIn = message.m_pDataIn + 1;
        message.m_nInBufWord = *message.m_pDataIn++;
        if ( message.m_bOverflow )
        {
          m_pBufferEnd = message.m_pBufferEnd;
          v83 = 0;
          goto LABEL_61;
        }
        m_nDataBytes = v20 & CBitBuffer::s_nMaskTable[v22];
        v83 = (m_nDataBytes << SLOBYTE(message.m_nBitsAvail)) | v21;
        m_pBufferEnd = message.m_pBufferEnd;
        v20 >>= v22;
      }
      else
      {
        m_pBufferEnd = message.m_pBufferEnd;
        m_nBitsAvail = message.m_nBitsAvail - 32;
        message.m_nBitsAvail = m_nBitsAvail;
        if ( m_nBitsAvail != 0 )
        {
          v20 = 0;
          v83 = message.m_nInBufWord;
        }
        else
        {
          m_nBitsAvail = 32;
          message.m_nBitsAvail = 32;
          if ( message.m_pDataIn == message.m_pBufferEnd )
          {
            v20 = 0;
            m_nBitsAvail = 1;
            m_pDataIn = message.m_pDataIn + 1;
            message.m_nBitsAvail = 1;
            ++message.m_pDataIn;
            v83 = message.m_nInBufWord;
          }
          else
          {
            if ( message.m_pDataIn <= message.m_pBufferEnd )
            {
              v20 = *message.m_pDataIn;
              m_pDataIn = ++message.m_pDataIn;
            }
            else
            {
              message.m_bOverflow = true;
              v20 = 0;
            }
            v83 = message.m_nInBufWord;
          }
        }
      }
      message.m_nInBufWord = v20;
LABEL_61:
      if ( m_nBitsAvail < 32 )
      {
        v24 = v20;
        v25 = 32 - m_nBitsAvail;
        if ( m_pDataIn == message.m_pBufferEnd )
        {
          v23 = 0;
          m_nBitsAvail = 1;
          ++m_pDataIn;
          message.m_nBitsAvail = 1;
          message.m_nInBufWord = 0;
          message.m_pDataIn = m_pDataIn;
          message.m_bOverflow = true;
          splitScreenPlayers.m_pElements = nullptr;
          m_pBufferEnd = message.m_pBufferEnd;
          goto LABEL_78;
        }
        if ( m_pDataIn > message.m_pBufferEnd )
        {
          m_pBufferEnd = message.m_pBufferEnd;
          v23 = 0;
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
          splitScreenPlayers.m_pElements = nullptr;
          goto LABEL_78;
        }
        v23 = *m_pDataIn++;
        message.m_nInBufWord = v23;
        message.m_pDataIn = m_pDataIn;
        if ( message.m_bOverflow )
        {
          m_pBufferEnd = message.m_pBufferEnd;
          splitScreenPlayers.m_pElements = nullptr;
          goto LABEL_78;
        }
        m_nDataBytes = v23 & CBitBuffer::s_nMaskTable[v25];
        splitScreenPlayers.m_pElements = (CLC_SplitPlayerConnect *)((m_nDataBytes << m_nBitsAvail) | v24);
        m_pBufferEnd = message.m_pBufferEnd;
        message.m_nBitsAvail = m_nBitsAvail;
        v23 >>= v25;
      }
      else
      {
        m_nBitsAvail -= 32;
        message.m_nBitsAvail = m_nBitsAvail;
        if ( m_nBitsAvail != 0 )
        {
          v23 = 0;
          splitScreenPlayers.m_pElements = (CLC_SplitPlayerConnect *)v20;
        }
        else
        {
          m_nBitsAvail = 32;
          message.m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            v23 = 0;
            m_nBitsAvail = 1;
            ++m_pDataIn;
            message.m_nBitsAvail = 1;
            message.m_pDataIn = m_pDataIn;
            splitScreenPlayers.m_pElements = (CLC_SplitPlayerConnect *)v20;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              v23 = *m_pDataIn++;
              message.m_pDataIn = m_pDataIn;
            }
            else
            {
              message.m_bOverflow = true;
              v23 = 0;
            }
            splitScreenPlayers.m_pElements = (CLC_SplitPlayerConnect *)v20;
          }
        }
      }
      message.m_nInBufWord = v23;
LABEL_78:
      if ( m_nBitsAvail < 32 )
      {
        v26 = 32 - m_nBitsAvail;
        v27 = v23;
        if ( m_pDataIn == message.m_pBufferEnd )
        {
          message.m_nBitsAvail = 1;
          message.m_nInBufWord = 0;
          message.m_pDataIn = m_pDataIn + 1;
          message.m_bOverflow = true;
          HIDWORD(nReservationCookie) = 0;
        }
        else if ( m_pDataIn <= message.m_pBufferEnd )
        {
          v28 = *m_pDataIn;
          message.m_nInBufWord = *m_pDataIn;
          message.m_pDataIn = m_pDataIn + 1;
          if ( message.m_bOverflow )
          {
            HIDWORD(nReservationCookie) = 0;
          }
          else
          {
            v29 = (v28 & CBitBuffer::s_nMaskTable[v26]) << m_nBitsAvail;
            message.m_nBitsAvail = m_nBitsAvail;
            HIDWORD(nReservationCookie) = v29 | v27;
            message.m_nInBufWord = v28 >> v26;
          }
        }
        else
        {
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
          HIDWORD(nReservationCookie) = 0;
        }
      }
      else
      {
        message.m_nBitsAvail = m_nBitsAvail - 32;
        if ( m_nBitsAvail == 32 )
        {
          message.m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            message.m_nBitsAvail = 1;
            message.m_nInBufWord = 0;
            message.m_pDataIn = m_pDataIn + 1;
            HIDWORD(nReservationCookie) = v23;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              message.m_nInBufWord = *m_pDataIn;
              message.m_pDataIn = m_pDataIn + 1;
            }
            else
            {
              message.m_bOverflow = true;
              message.m_nInBufWord = 0;
            }
            HIDWORD(nReservationCookie) = v23;
          }
        }
        else
        {
          message.m_nInBufWord = 0;
          HIDWORD(nReservationCookie) = v23;
        }
      }
      CBitRead::ReadString(this: &message, pStr: &cdkey[2036], maxLen: 256, bLine: false, pOutNumChars: nullptr);
      CBitRead::ReadString(this: &message, pStr: &name[244], maxLen: 256, bLine: false, pOutNumChars: nullptr);
      v30 = message.m_nInBufWord;
      v31 = message.m_pBufferEnd;
      v32 = message.m_pDataIn;
      if ( message.m_nBitsAvail < 8 )
      {
        v34 = 8 - message.m_nBitsAvail;
        if ( message.m_pDataIn == message.m_pBufferEnd )
        {
          v32 = message.m_pDataIn + 1;
          message.m_nBitsAvail = 1;
          message.m_nInBufWord = 0;
          ++message.m_pDataIn;
          message.m_bOverflow = true;
          m_nInBufWord_low = 0;
        }
        else if ( message.m_pDataIn <= message.m_pBufferEnd )
        {
          v32 = message.m_pDataIn + 1;
          message.m_nInBufWord = *message.m_pDataIn++;
          if ( message.m_bOverflow )
          {
            m_nInBufWord_low = 0;
          }
          else
          {
            v35 = (message.m_nInBufWord & CBitBuffer::s_nMaskTable[v34]) << SLOBYTE(message.m_nBitsAvail);
            message.m_nBitsAvail = 32 - v34;
            message.m_nInBufWord >>= v34;
            m_nInBufWord_low = v35 | v30;
          }
        }
        else
        {
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
          m_nInBufWord_low = 0;
        }
      }
      else
      {
        m_nInBufWord_low = LOBYTE(message.m_nInBufWord);
        message.m_nBitsAvail -= 8;
        if ( message.m_nBitsAvail != 0 )
        {
          message.m_nInBufWord >>= 8;
        }
        else
        {
          message.m_nBitsAvail = 32;
          if ( message.m_pDataIn == message.m_pBufferEnd )
          {
            v32 = message.m_pDataIn + 1;
            message.m_nBitsAvail = 1;
            message.m_nInBufWord = 0;
            ++message.m_pDataIn;
          }
          else if ( message.m_pDataIn <= message.m_pBufferEnd )
          {
            v32 = message.m_pDataIn + 1;
            message.m_nInBufWord = *message.m_pDataIn++;
          }
          else
          {
            message.m_bOverflow = true;
            message.m_nInBufWord = 0;
          }
        }
      }
      memset(&password[244], 0, 12);
      splitScreenPlayers.m_Memory.m_pMemory = nullptr;
      splitScreenPlayers.m_Memory.m_nAllocationCount = 0;
      if ( m_nInBufWord_low > 0 )
      {
        CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::InsertMultipleBefore(
          this: (CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *)&password[244],
          elem: 0,
          num: m_nInBufWord_low);
        v36 = 0;
        do
        {
          if ( message.m_nBitsAvail < 6 )
          {
            v37 = 6 - message.m_nBitsAvail;
            if ( message.m_pDataIn == message.m_pBufferEnd )
            {
              message.m_nBitsAvail = 1;
              message.m_nInBufWord = 0;
              ++message.m_pDataIn;
              message.m_bOverflow = true;
            }
            else if ( message.m_pDataIn <= message.m_pBufferEnd )
            {
              message.m_nInBufWord = *message.m_pDataIn++;
              if ( !message.m_bOverflow )
              {
                message.m_nInBufWord >>= v37;
                message.m_nBitsAvail = 32 - v37;
              }
            }
            else
            {
              message.m_bOverflow = true;
              message.m_nInBufWord = 0;
            }
          }
          else
          {
            message.m_nBitsAvail -= 6;
            if ( message.m_nBitsAvail != 0 )
            {
              message.m_nInBufWord >>= 6;
            }
            else
            {
              message.m_nBitsAvail = 32;
              if ( message.m_pDataIn == message.m_pBufferEnd )
              {
                message.m_nBitsAvail = 1;
                message.m_nInBufWord = 0;
                ++message.m_pDataIn;
              }
              else if ( message.m_pDataIn <= message.m_pBufferEnd )
              {
                message.m_nInBufWord = *message.m_pDataIn++;
              }
              else
              {
                message.m_bOverflow = true;
                message.m_nInBufWord = 0;
              }
            }
          }
          (*(void (__thiscall **)(int, CBitRead *))(*(_DWORD *)(*(_DWORD *)&password[244] + v36) + 16))(
            a1: v36 + *(_DWORD *)&password[244],
            a2: &message);
          v36 += 36;
          --m_nInBufWord_low;
        }
        while ( m_nInBufWord_low != 0 );
        v32 = message.m_pDataIn;
        v31 = message.m_pBufferEnd;
      }
      v38 = message.m_nInBufWord & 1;
      if ( --message.m_nBitsAvail != 0 )
      {
        message.m_nInBufWord >>= 1;
      }
      else
      {
        message.m_nBitsAvail = 32;
        if ( v32 == v31 )
        {
          message.m_nBitsAvail = 1;
          message.m_nInBufWord = 0;
          message.m_pDataIn = v32 + 1;
        }
        else if ( v32 <= v31 )
        {
          message.m_nInBufWord = *v32;
          message.m_pDataIn = v32 + 1;
        }
        else
        {
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
        }
      }
      LOBYTE(m_nDataBytes) = v38 != 0;
      v39 = CBitRead::ReadLongLong(this: &message);
      v40 = message.m_nInBufWord;
      splitScreenPlayers.m_Memory.m_nGrowSize = v39;
      splitScreenPlayers.m_Size = v41;
      if ( message.m_nBitsAvail < 8 )
      {
        v43 = 8 - message.m_nBitsAvail;
        if ( message.m_pDataIn == message.m_pBufferEnd )
        {
          message.m_nBitsAvail = 1;
          message.m_nInBufWord = 0;
          ++message.m_pDataIn;
          message.m_bOverflow = true;
        }
        else if ( message.m_pDataIn <= message.m_pBufferEnd )
        {
          v45 = *message.m_pDataIn;
          message.m_nInBufWord = *message.m_pDataIn++;
          if ( !message.m_bOverflow )
          {
            v46 = (v45 & CBitBuffer::s_nMaskTable[v43]) << SLOBYTE(message.m_nBitsAvail);
            message.m_nBitsAvail = 32 - v43;
            v42 = v46 | v40;
            message.m_nInBufWord = v45 >> v43;
            goto LABEL_149;
          }
        }
        else
        {
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
        }
LABEL_144:
        v44 = netadr_s::ToString(this: &packet->from, baseOnly: false);
        DevMsg(a1: "Rejecting connection request from %s, client's cross-play platform is unrecognized.\n", v44);
        (*(void (__cdecl **)(_DWORD, netpacket_s *, const char *))(*(_DWORD *)nReservationCookie + 196))(
          a1: nReservationCookie,
          a2: packet,
          a3: "Invalid cross-play platform id\n");
        CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: (CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *)&password[244]);
        return true;
      }
      v42 = LOBYTE(message.m_nInBufWord);
      message.m_nBitsAvail -= 8;
      if ( message.m_nBitsAvail != 0 )
      {
        message.m_nInBufWord >>= 8;
      }
      else
      {
        message.m_nBitsAvail = 32;
        if ( message.m_pDataIn == message.m_pBufferEnd )
        {
          message.m_nBitsAvail = 1;
          message.m_nInBufWord = 0;
          ++message.m_pDataIn;
        }
        else if ( message.m_pDataIn <= message.m_pBufferEnd )
        {
          message.m_nInBufWord = *message.m_pDataIn++;
        }
        else
        {
          message.m_bOverflow = true;
          message.m_nInBufWord = 0;
        }
      }
LABEL_149:
      v84 = (CBaseServer *)v42;
      if ( v42 == 0 || v42 > 3 )
        goto LABEL_144;
      if ( netadr_s::IsLocalhost(this: &packet->from)
        || (IsLoopback = netadr_s::IsLoopback(this: &packet->from), HIBYTE(v86) = 0, IsLoopback) )
      {
        HIBYTE(v86) = 1;
      }
      v48 = (CBaseServer *)nReservationCookie;
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)nReservationCookie + 92))(a1: nReservationCookie) != 0
        || HIBYTE(v86) == 0 )
      {
        IsExclusiveToLobbyConnections = CBaseServer::IsExclusiveToLobbyConnections(this: v48);
        m_nGrowSize = splitScreenPlayers.m_Memory.m_nGrowSize;
        m_Size = splitScreenPlayers.m_Size;
        if ( IsExclusiveToLobbyConnections
          && (LODWORD(v48->m_nReservationCookie) != splitScreenPlayers.m_Memory.m_nGrowSize
           || HIDWORD(v48->m_nReservationCookie) != splitScreenPlayers.m_Size) )
        {
          m_nReservationCookie = v48->m_nReservationCookie;
          v73 = *(_QWORD *)&splitScreenPlayers.m_Memory.m_nGrowSize;
          v52 = netadr_s::ToString(this: &packet->from, baseOnly: false);
          DevMsg(
            a1: "Rejecting connection request from %s, client's reservation cookie %llx does not match servers's cookie %llx.\n",
            v52,
            v73,
            m_nReservationCookie);
          v48->RejectConnection(this: v48, a2: &packet->from, a3: "#Valve_Reject_Connect_From_Lobby");
          CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: (CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *)&password[244]);
          return true;
        }
        if ( CBaseServer::IsReserved(this: v48) )
        {
          v53 = v48->m_nReservationCookie;
          m_nReservationCookie_high = HIDWORD(v48->m_nReservationCookie);
          if ( v53 != m_nGrowSize || m_nReservationCookie_high != m_Size )
          {
            v76 = v48->m_flReservationExpiryTime - net_time;
            v74 = __PAIR64__(m_nReservationCookie_high, v53);
            v55 = netadr_s::ToString(this: &packet->from, baseOnly: false);
            DevMsg(
              a1: "Rejecting connection request from %s (reservation cookie 0x%llx), server is reserved with reservation cook"
              "ie 0x%llx for %.1f more seconds\n",
              v55,
              __PAIR64__(m_Size, m_nGrowSize),
              v74,
              (double)v76);
            v48->RejectConnection(this: v48, a2: &packet->from, a3: "#Valve_Reject_Reserved_For_Lobby");
            CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: (CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *)&password[244]);
            return true;
          }
        }
      }
      m_pElements = splitScreenPlayers.m_pElements;
      if ( splitScreenPlayers.m_pElements == (CLC_SplitPlayerConnect *)3 )
      {
        v57 = message.m_nInBufWord;
        if ( message.m_nBitsAvail < 16 )
        {
          v59 = 16 - message.m_nBitsAvail;
          if ( message.m_pDataIn == message.m_pBufferEnd )
          {
            message.m_nBitsAvail = 1;
            message.m_nInBufWord = 0;
            ++message.m_pDataIn;
            message.m_bOverflow = true;
            v58 = 0;
          }
          else if ( message.m_pDataIn <= message.m_pBufferEnd )
          {
            v60 = *message.m_pDataIn;
            message.m_nInBufWord = *message.m_pDataIn++;
            if ( message.m_bOverflow )
            {
              v58 = 0;
            }
            else
            {
              v61 = (v60 & CBitBuffer::s_nMaskTable[v59]) << SLOBYTE(message.m_nBitsAvail);
              message.m_nBitsAvail = 32 - v59;
              v58 = v61 | v57;
              message.m_nInBufWord = v60 >> v59;
            }
          }
          else
          {
            message.m_bOverflow = true;
            message.m_nInBufWord = 0;
            v58 = 0;
          }
        }
        else
        {
          v58 = message.m_nInBufWord;
          message.m_nBitsAvail -= 16;
          if ( message.m_nBitsAvail != 0 )
          {
            message.m_nInBufWord >>= 16;
          }
          else
          {
            message.m_nBitsAvail = 32;
            if ( message.m_pDataIn == message.m_pBufferEnd )
            {
              message.m_nBitsAvail = 1;
              message.m_nInBufWord = 0;
              ++message.m_pDataIn;
            }
            else if ( message.m_pDataIn <= message.m_pBufferEnd )
            {
              message.m_nInBufWord = *message.m_pDataIn++;
            }
            else
            {
              message.m_bOverflow = true;
              message.m_nInBufWord = 0;
            }
          }
        }
        if ( (unsigned int)v58 > 0x800 )
        {
          v48->RejectConnection(this: v48, a2: &packet->from, a3: "Invalid Steam key length\n");
          CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: (CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *)&password[244]);
          return true;
        }
        CBitRead::ReadBytes(this: &message, pOut, nBytes: v58);
        v48->ConnectClient(
          this: v48,
          a2: &packet->from,
          a3: v83,
          a4: HIDWORD(nReservationCookie),
          a5: 3,
          a6: &cdkey[2036],
          a7: &name[244],
          a8: pOut,
          a9: v58,
          a10: (CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *)&password[244],
          a11: m_nDataBytes,
          a12: (CrossPlayPlatform_t)v84);
      }
      else
      {
        CBitRead::ReadString(this: &message, pStr: pOut, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
        v48->ConnectClient(
          this: v48,
          a2: &packet->from,
          a3: v83,
          a4: HIDWORD(nReservationCookie),
          a5: (int)m_pElements,
          a6: &cdkey[2036],
          a7: &name[244],
          a8: pOut,
          a9: strlen(pOut),
          a10: (CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *)&password[244],
          a11: m_nDataBytes,
          a12: (CrossPlayPlatform_t)v84);
      }
      CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: (CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *)&password[244]);
      return true;
    case 108:
    case 116:
      return true;
    case 110:
      (*(void (__thiscall **)(_DWORD, netpacket_s *, CBitRead *))(*(_DWORD *)nReservationCookie + 248))(
        a1: nReservationCookie,
        a2: packet,
        a3: &message);
      return true;
    case 113:
      (*(void (__thiscall **)(_DWORD, netpacket_s *, CBitRead *))(*(_DWORD *)nReservationCookie + 240))(
        a1: nReservationCookie,
        a2: packet,
        a3: &message);
      return true;
    default:
      if ( IsUsingMasterLegacyMode() )
      {
        v65 = nullptr;
        if ( (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)nReservationCookie + 108))(a1: nReservationCookie) == 0
          && (*(unsigned __int8 (__thiscall **)(_DWORD))(*(_DWORD *)nReservationCookie + 112))(a1: nReservationCookie) == 0 )
        {
          v65 = (CGameServer *)nReservationCookie;
        }
        g_pMaster->HandleUnknown(this: g_pMaster, a2: packet, a3: (CBaseServer *)nReservationCookie, a4: v65);
        return true;
      }
      if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
      {
        v66 = Steam3Server();
        if ( CSteam3Server::IsMasterServerUpdaterSharingGameSocket(this: v66) )
        {
          m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
          v68 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)packet);
          m_nDataBytes = (unsigned int)v68;
          m_pData = (CBaseServer *)packet->message.m_pData;
          v70 = m_pSteamMasterServerUpdater->__vftable;
          m_nDataBytes = packet->message.m_nDataBytes;
          v71 = _byteswap_ulong((unsigned int)v68);
          v84 = m_pData;
          Port = netadr_s::GetPort(this: &packet->from);
          v70->HandleIncomingPacket(this: m_pSteamMasterServerUpdater, a2: v84, a3: m_nDataBytes, a4: v71, a5: Port);
          CBaseServer::ForwardPacketsFromMasterServerUpdater(this: (CBaseServer *)nReservationCookie);
        }
      }
      return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013AB30
// Name: public: virtual void CBaseServer::WriteTempEntities(class CBaseClient __near *,class CFrameSnapshot __near *,class CFrameSnapshot __near *,class bf_write __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::WriteTempEntities(
        CBaseServer *this,
        CBaseClient *client,
        unsigned int pCurrentSnapshot,
        CFrameSnapshot *pLastSnapshot,
        bf_write *buf,
        int ev_max)
{
  int v6; // ebx
  int m_nValue; // eax
  int v8; // esi
  int v9; // eax
  unsigned __int16 m_NumElements; // cx
  CBaseClient *v11; // edi
  CFrameSnapshot *v12; // esi
  bool v13; // cc
  CBaseClient_vtbl *v14; // edx
  unsigned __int16 v15; // ax
  unsigned __int16 v16; // dx
  unsigned int v17; // ecx
  UtlRBTreeNode_t<CEventInfo *,unsigned short> *m_pMemory; // eax
  unsigned int v19; // esi
  int v20; // edx
  CEventInfo **p_m_Data; // esi
  int v22; // edi
  unsigned __int16 v23; // ax
  CEventInfo *m_Data; // ebx
  float fire_delay; // xmm0_4
  int m_iCurBit; // ecx
  int v27; // eax
  int v28; // esi
  int v29; // esi
  CFrameSnapshot *v30; // eax
  unsigned int classID; // ecx
  int v32; // edi
  int v33; // edx
  CFrameSnapshot *v34; // eax
  bool v35; // zf
  unsigned __int8 *v36; // eax
  _BYTE pData[96000]; // [esp+Ch] [ebp-17798h] BYREF
  CReferencedSnapshotList list; // [esp+1770Ch] [ebp-98h] BYREF
  SVC_TempEntities v39; // [esp+17720h] [ebp-84h] BYREF
  CEventInfo *insert; // [esp+17774h] [ebp-30h] BYREF
  int v41; // [esp+17778h] [ebp-2Ch]
  CBaseServer *v42; // [esp+1777Ch] [ebp-28h]
  CFrameSnapshot *v43; // [esp+17780h] [ebp-24h]
  CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl*)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short> > v44; // [esp+17784h] [ebp-20h] BYREF
  bool v45; // [esp+177A3h] [ebp-1h]
  CBaseClient *i; // [esp+177ACh] [ebp+8h]

  v6 = 0;
  v42 = this;
  v39.m_NetChannel = nullptr;
  v39.__vftable = (SVC_TempEntities_vtbl *)&SVC_TempEntities::`vftable';
  v39.m_DataIn.m_bOverflow = false;
  v39.m_DataIn.m_pDebugName = nullptr;
  v39.m_DataIn.m_nDataBits = -1;
  v39.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &v39.m_DataOut);
  v39.m_bReliable = false;
  bf_write::StartWriting(this: &v39.m_DataOut, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
  if ( sv_debugtempentities.m_pParent != nullptr )
    m_nValue = sv_debugtempentities.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v45 = m_nValue != 0;
  memset(&list, 0, sizeof(list));
  CFrameSnapshotManager::BuildSnapshotList(
    this: framesnapshotmanager,
    (CFrameSnapshot *)pCurrentSnapshot,
    pLastSnapshot,
    &list);
  v8 = ev_max;
  if ( ev_max >= 255 )
  {
    ev_max = 255;
    v8 = 255;
  }
  v44.m_LessFunc = CEventInfo_LessFunc;
  v44.m_Elements.m_pMemory = nullptr;
  v44.m_Elements.m_nAllocationCount = v8;
  v44.m_Elements.m_nGrowSize = 0;
  if ( v8 != 0 )
    v44.m_Elements.m_pMemory = (UtlRBTreeNode_t<CEventInfo *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: 12 * v8);
  v9 = 0;
  m_NumElements = 0;
  *(_DWORD *)&v44.m_Root = 0xFFFF;
  *(_DWORD *)&v44.m_FirstFree = -1;
  v44.m_pElements = v44.m_Elements.m_pMemory;
  v41 = 0;
  if ( list.m_vecSnapshots.m_Size <= 0 )
    goto LABEL_67;
  v11 = client;
  while ( m_NumElements < v8 )
  {
    v12 = list.m_vecSnapshots.m_Memory.m_pMemory[v9];
    v13 = v12->m_nTempEntities <= 0;
    v43 = v12;
    if ( v13 )
      goto LABEL_25;
    while ( 1 )
    {
      v14 = v11->IGameEventListener2::__vftable;
      insert = v12->m_pTempEntities[v6];
      if ( !v14->IgnoreTempEntity(this: v11, a2: insert) )
        break;
LABEL_23:
      if ( ++v6 >= v12->m_nTempEntities )
        goto LABEL_24;
    }
    HIBYTE(pLastSnapshot) = 0;
    pCurrentSnapshot = 0xFFFF;
    CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &v44,
      &insert,
      parent: (unsigned __int16 *)&pCurrentSnapshot,
      leftchild: (bool *)&pLastSnapshot + 3);
    v15 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&v44);
    v16 = pCurrentSnapshot;
    v17 = v15;
    m_pMemory = v44.m_Elements.m_pMemory;
    v19 = v17;
    v44.m_Elements.m_pMemory[v19].m_Right = -1;
    m_pMemory[v19].m_Left = -1;
    m_pMemory[v19].m_Tag = 0;
    m_pMemory[v19].m_Parent = v16;
    if ( v16 == 0xFFFF )
    {
      v44.m_Root = v17;
    }
    else
    {
      v20 = v16;
      if ( HIBYTE(pLastSnapshot) != 0 )
        m_pMemory[v20].m_Left = v17;
      else
        m_pMemory[v20].m_Right = v17;
    }
    CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &v44,
      elem: v17);
    ++v44.m_NumElements;
    p_m_Data = &v44.m_Elements.m_pMemory[v19].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = insert;
    v11 = client;
    if ( v44.m_NumElements < ev_max )
    {
      v12 = v43;
      goto LABEL_23;
    }
LABEL_24:
    v9 = v41;
    m_NumElements = v44.m_NumElements;
LABEL_25:
    ++v9;
    v6 = 0;
    v41 = v9;
    if ( v9 < list.m_vecSnapshots.m_Size )
    {
      v8 = ev_max;
      continue;
    }
    break;
  }
  if ( m_NumElements != 0 )
  {
    v22 = 0;
    ev_max = 0;
    v23 = CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::FirstInorder(this: &v44);
    LOWORD(i) = v23;
    if ( v23 != 0xFFFF )
    {
      while ( 1 )
      {
        m_Data = v44.m_Elements.m_pMemory[v23].m_Data;
        fire_delay = m_Data->fire_delay;
        m_iCurBit = v39.m_DataOut.m_iCurBit;
        v43 = (CFrameSnapshot *)m_Data;
        v27 = v39.m_DataOut.m_iCurBit + 1;
        if ( fire_delay == 0.0 )
        {
          if ( v27 <= v39.m_DataOut.m_nDataBits )
          {
            if ( !v39.m_DataOut.m_bOverflow )
            {
              v39.m_DataOut.m_pData[v39.m_DataOut.m_iCurBit >> 3] &= ~(1 << (v39.m_DataOut.m_iCurBit & 7));
              m_iCurBit = ++v39.m_DataOut.m_iCurBit;
            }
          }
          else
          {
            v39.m_DataOut.m_bOverflow = true;
          }
        }
        else
        {
          if ( v27 <= v39.m_DataOut.m_nDataBits )
          {
            if ( !v39.m_DataOut.m_bOverflow )
              v39.m_DataOut.m_pData[v39.m_DataOut.m_iCurBit++ >> 3] |= 1 << (v39.m_DataOut.m_iCurBit & 7);
          }
          else
          {
            v39.m_DataOut.m_bOverflow = true;
          }
          bf_write::WriteSBitLong(this: &v39.m_DataOut, data: (int)(float)(m_Data->fire_delay * 100.0), numbits: 8);
          m_iCurBit = v39.m_DataOut.m_iCurBit;
        }
        if ( v22 != 0 && *(_WORD *)v22 == m_Data->classID )
        {
          if ( m_iCurBit + 1 <= v39.m_DataOut.m_nDataBits )
          {
            if ( !v39.m_DataOut.m_bOverflow )
            {
              v39.m_DataOut.m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
              m_iCurBit = ++v39.m_DataOut.m_iCurBit;
            }
          }
          else
          {
            v39.m_DataOut.m_bOverflow = true;
          }
          v28 = v45 ? m_iCurBit : 0;
          SendTable_WriteAllDeltaProps(
            pTable: m_Data->pSendTable,
            pFromData: *(const void **)(v22 + 20),
            nFromDataBits: *(_DWORD *)(v22 + 16),
            pToData: m_Data->pData,
            nToDataBits: m_Data->bits,
            nObjectID: -1,
            pBufOut: &v39.m_DataOut);
          if ( v45 )
            DevMsg(a1: "TE %s delta bits: %i\n", m_Data->pSendTable->m_pNetTableName, v39.m_DataOut.m_iCurBit - v28);
        }
        else
        {
          if ( m_iCurBit + 1 <= v39.m_DataOut.m_nDataBits )
          {
            if ( !v39.m_DataOut.m_bOverflow )
            {
              v39.m_DataOut.m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
              m_iCurBit = ++v39.m_DataOut.m_iCurBit;
            }
          }
          else
          {
            v39.m_DataOut.m_bOverflow = true;
          }
          v29 = v45 ? m_iCurBit : 0;
          v30 = (CFrameSnapshot *)v42->GetClassBits(this: v42);
          classID = m_Data->classID;
          pLastSnapshot = v30;
          pCurrentSnapshot = classID;
          if ( (int)v30 + v39.m_DataOut.m_iCurBit <= v39.m_DataOut.m_nDataBits )
          {
            v32 = v39.m_DataOut.m_iCurBit & 0x1F;
            v33 = v39.m_DataOut.m_iCurBit >> 5;
            *(_DWORD *)&v39.m_DataOut.m_pData[4 * (v39.m_DataOut.m_iCurBit >> 5)] = (classID << (v39.m_DataOut.m_iCurBit
                                                                                               & 0x1F))
                                                                                  | *(_DWORD *)&v39.m_DataOut.m_pData[4 * (v39.m_DataOut.m_iCurBit >> 5)]
                                                                                  & g_BitWriteMasks[0][(_DWORD)v30 + 32 * v32 + v32];
            v34 = pLastSnapshot;
            if ( 32 - v32 < (int)pLastSnapshot )
              *(_DWORD *)&v39.m_DataOut.m_pData[4 * v33 + 4] = (pCurrentSnapshot >> (32 - v32))
                                                             | *(_DWORD *)&v39.m_DataOut.m_pData[4 * v33 + 4]
                                                             & g_BitWriteMasks[0][(_DWORD)pLastSnapshot - (32 - v32)];
            v39.m_DataOut.m_iCurBit += (int)v34;
            m_Data = (CEventInfo *)v43;
          }
          else
          {
            v39.m_DataOut.m_iCurBit = v39.m_DataOut.m_nDataBits;
            v39.m_DataOut.m_bOverflow = true;
          }
          v35 = !v42->IsMultiplayer(this: v42);
          v36 = m_Data->pData;
          if ( v35 )
            bf_write::WriteBits(this: &v39.m_DataOut, pInData: v36, nBits: m_Data->bits);
          else
            SendTable_WriteAllDeltaProps(
              pTable: m_Data->pSendTable,
              pFromData: nullptr,
              nFromDataBits: 0,
              pToData: v36,
              nToDataBits: m_Data->bits,
              nObjectID: -1,
              pBufOut: &v39.m_DataOut);
          if ( v45 )
            DevMsg(a1: "TE %s full bits: %i\n", m_Data->pSendTable->m_pNetTableName, v39.m_DataOut.m_iCurBit - v29);
          v22 = ev_max;
        }
        if ( v42->IsMultiplayer(this: v42) )
        {
          ev_max = (int)m_Data;
          v22 = (int)m_Data;
        }
        i = (CBaseClient *)CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::NextInorder(
                             this: &v44,
                             (unsigned __int16)i);
        if ( i == (CBaseClient *)0xFFFF )
          break;
        v23 = (unsigned __int16)i;
      }
    }
    v39.m_nNumEntries = v44.m_NumElements;
    SVC_TempEntities::WriteToBuffer(this: &v39, buffer: buf);
  }
LABEL_67:
  CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::RemoveAll(this: &v44);
  if ( v44.m_Elements.m_nGrowSize >= 0 && v44.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v44.m_Elements.m_pMemory);
  CReferencedSnapshotList::~CReferencedSnapshotList(this: &list);
}

//------------------------------------------------------------------------------
// Address: 0x1013B070
// Name: private: void CBaseServer::AddTagString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::AddTagString(CBaseServer *this, const char *pchString)
{
  const char *v2; // esi
  CUtlString *i; // edi
  CUtlString *m_pMemory; // esi
  const char *v6; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > list; // [esp+Ch] [ebp-14h] BYREF
  bool bHadAsterisk_3; // [esp+2Bh] [ebp+Bh]

  v2 = pchString;
  i = nullptr;
  if ( pchString != nullptr )
  {
    if ( _V_strstr(s1: pchString, search: ",") != nullptr )
    {
      memset(&list, 0, sizeof(list));
      BuildTokenList(pchString, chDelim: 44, &list);
      if ( list.m_Size > 0 )
      {
        m_pMemory = list.m_Memory.m_pMemory;
        for ( i = (CUtlString *)list.m_Size; i != nullptr; i = (CUtlString *)((char *)i - 1) )
        {
          v6 = CUtlString::operator char const *(this: m_pMemory);
          CBaseServer::AddTagString(this, pchString: v6);
          ++m_pMemory;
        }
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&list);
      if ( list.m_Memory.m_nGrowSize >= (int)i && list.m_Memory.m_pMemory != i )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
    }
    else
    {
      bHadAsterisk_3 = *pchString == 42;
      if ( *v2 == 42 )
        ++v2;
      CUtlString::operator+=(this: &this->m_GameTypePrivate, rhs: v2);
      CUtlString::operator+=(this: &this->m_GameTypePrivate, rhs: ",");
      if ( !bHadAsterisk_3 )
      {
        CUtlString::operator+=(this: &this->m_GameTypePublic, rhs: v2);
        CUtlString::operator+=(this: &this->m_GameTypePublic, rhs: ",");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B160
// Name: public: void CBaseServer::UpdateGameType(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::UpdateGameType(CBaseServer *this)
{
  int NumHumanPlayers; // eax
  bool v3; // bl
  int v4; // edi
  char *m_pszString; // edi
  int HostVersion; // eax
  const char *v7; // eax
  ISteamGameServer *m_pSteamGameServer; // esi
  const char *v9; // eax
  char szMatchMakingTags[1024]; // [esp+8h] [ebp-414h] BYREF
  CUtlString tags; // [esp+408h] [ebp-14h] BYREF
  CUtlString *p_m_GameTypePrivate; // [esp+418h] [ebp-4h]

  CUtlString::operator=(this: &this->m_GameTypePublic, src: defaultValue);
  p_m_GameTypePrivate = &this->m_GameTypePrivate;
  CUtlString::operator=(this: &this->m_GameTypePrivate, src: defaultValue);
  CUtlString::CUtlString(this: &tags);
  if ( serverGameDLL != nullptr )
  {
    memset(szMatchMakingTags, 0, sizeof(szMatchMakingTags));
    serverGameDLL->GetMatchmakingTags(this: serverGameDLL, a2: szMatchMakingTags, a3: 1024u);
    if ( szMatchMakingTags[0] != 0 )
      CBaseServer::AddTagString(this, pchString: szMatchMakingTags);
  }
  NumHumanPlayers = CBaseServer::GetNumHumanPlayers(this);
  v3 = NumHumanPlayers > 0;
  if ( NumHumanPlayers <= 0 )
    CBaseServer::AddTagString(this, pchString: "empty");
  if ( (_S2_9 & 1) == 0 )
  {
    _S2_9 |= 1u;
    ConVarRef::ConVarRef(this: &var, pName: "sv_tags");
  }
  if ( ConVarRef::IsValid(this: &var) && *var.m_pConVarState->m_Value.m_pszString != 0 )
    CBaseServer::AddTagString(this, pchString: var.m_pConVarState->m_Value.m_pszString);
  if ( this->IsDedicated(this) && !this->m_bIsDedicatedForXbox && !v3 && this->m_nReservationCookie == 0 )
  {
    v4 = this->GetNumFakeClients(this);
    if ( this->GetNumClients(this) == v4
      && (sv_steamgroup_exclusive.m_pParent == nullptr || sv_steamgroup_exclusive.m_pParent->m_Value.m_nValue == 0) )
    {
      if ( (sv_search_key.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = sv_search_key.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      HostVersion = GetHostVersion();
      v7 = va(format: "*sv_search_key_%s%d", m_pszString, HostVersion);
      CBaseServer::AddTagString(this, pchString: v7);
    }
  }
  if ( Steam3Server()->m_pSteamGameServer != nullptr )
  {
    m_pSteamGameServer = Steam3Server()->m_pSteamGameServer;
    v9 = CUtlString::operator char const *(this: p_m_GameTypePrivate);
    m_pSteamGameServer->SetGameTags(this: m_pSteamGameServer, a2: v9);
  }
  tags.m_Storage.m_nActualLength = 0;
  if ( tags.m_Storage.m_Memory.m_nGrowSize >= 0 && tags.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tags.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1013B340
// Name: SvTagsChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl SvTagsChangeCallback()
{
  CBaseServer::UpdateGameType(this: &sv);
  if ( sv.m_State >= ss_active )
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: "heartbeat\n", nTickDelay: 0);
  ServerTagsCleanUp();
}

//------------------------------------------------------------------------------
// Address: 0x1013B370
// Name: public: void CBaseServer::SetReservationCookie(unsigned __int64,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseServer::SetReservationCookie(CBaseServer *this, unsigned __int64 uiCookie, const char *pchReasonFormat, ...)
{
  unsigned int v3; // ebx
  CBaseServer *v4; // esi
  unsigned int v5; // edi
  char reason[256]; // [esp+Ch] [ebp-100h] BYREF
  va_list params; // [esp+124h] [ebp+18h] BYREF

  va_start(params, pchReasonFormat);
  v3 = HIDWORD(uiCookie);
  v4 = this;
  v5 = uiCookie;
  if ( uiCookie != this->m_nReservationCookie )
  {
    memset(reason, 0, sizeof(reason));
    V_vsnprintf(pDest: reason, maxLen: 256, pFormat: pchReasonFormat, params);
    this = (CBaseServer *)-65281;
    ConColorMsg(
      a1: (const struct Color *)&this,
      a2: "-> Reservation cookie %llx:  reason %s\n",
      __PAIR64__(v3, v5),
      reason);
  }
  LODWORD(v4->m_nReservationCookie) = v5;
  HIDWORD(v4->m_nReservationCookie) = v3;
  CBaseServer::UpdateGameType(this: v4);
  if ( v4->m_nReservationCookie != 0 )
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_hosting_lobby.IConVar, value: 1);
  else
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_hosting_lobby.IConVar, value: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013B440
// Name: protected: virtual void CBaseServer::ReplyReservationRequest(struct netadr_s __near &,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ReplyReservationRequest(CBaseServer *this, netadr_s *adr, bf_read *msgIn)
{
  int m_nBitsAvail; // ecx
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // ebx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // ebx
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  const char *v16; // eax
  int v17; // eax
  int (__thiscall *GetNumClients)(struct CBaseServer *); // edx
  const char *v19; // eax
  int rounds; // edi
  const char *v21; // eax
  const char *v22; // eax
  int v23; // ecx
  unsigned int v24; // eax
  int v25; // ecx
  int v26; // ebx
  const unsigned int *v27; // ecx
  const unsigned int *v28; // edx
  const unsigned int *v29; // edx
  unsigned int v30; // ebx
  int v31; // eax
  const unsigned int *v32; // ecx
  const char *v33; // eax
  unsigned int v34; // edx
  unsigned int v35; // edi
  unsigned __int8 *v36; // edi
  unsigned int v37; // ebx
  int v38; // ecx
  unsigned int v39; // eax
  int v40; // ecx
  int v41; // edi
  const unsigned int *v42; // ecx
  const unsigned int *v43; // edx
  const unsigned int *v44; // edx
  unsigned int v45; // edi
  int v46; // eax
  const unsigned int *v47; // ecx
  unsigned int v48; // edx
  unsigned int v49; // ebx
  const char *v50; // eax
  IceSubkey *LongLong; // eax
  int v52; // ecx
  int v53; // edx
  unsigned int v54; // eax
  int v55; // ecx
  int v56; // edi
  const unsigned int *v57; // ecx
  const unsigned int *v58; // edx
  const unsigned int *v59; // edx
  unsigned int v60; // ebx
  int v61; // eax
  const unsigned int *v62; // ecx
  unsigned int v63; // edx
  unsigned int v64; // edi
  double m_fValue; // st7
  const char *v66; // eax
  unsigned __int64 v67; // rax
  CBaseServer *v68; // ebx
  KeyValues *v69; // eax
  KeyValues *v70; // ebx
  int Int; // eax
  CBaseServer *v72; // eax
  unsigned __int64 v73; // [esp-8h] [ebp-6C4h]
  int v74; // [esp+4h] [ebp-6B8h]
  const char *v75; // [esp+4h] [ebp-6B8h]
  unsigned int v76; // [esp+4h] [ebp-6B8h]
  unsigned int pOut[3]; // [esp+14h] [ebp-6A8h] BYREF
  unsigned __int8 decrypted[1024]; // [esp+20h] [ebp-69Ch] BYREF
  unsigned __int8 tmp[600]; // [esp+420h] [ebp-29Ch] BYREF
  CUtlBuffer buf; // [esp+678h] [ebp-44h] BYREF
  IceKey cipher; // [esp+6A8h] [ebp-14h] BYREF
  unsigned __int8 key[4]; // [esp+6B4h] [ebp-8h]
  CBaseServer *flExpiryTime; // [esp+6B8h] [ebp-4h]
  char v84; // [esp+6CBh] [ebp+Fh]

  flExpiryTime = this;
  m_nBitsAvail = msgIn->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = msgIn->m_pBufferEnd;
    m_nInBufWord = msgIn->m_nInBufWord;
    v12 = 32 - m_nBitsAvail;
    m_pDataIn = msgIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msgIn->m_nBitsAvail = 1;
      msgIn->m_nInBufWord = 0;
      msgIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msgIn->m_bOverflow = true;
        msgIn->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msgIn->m_nInBufWord = *m_pDataIn;
    }
    msgIn->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msgIn->m_bOverflow )
    {
      v7 = 0;
    }
    else
    {
      v14 = msgIn->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << msgIn->m_nBitsAvail;
      msgIn->m_nBitsAvail = 32 - v12;
      v7 = v15 | m_nInBufWord;
      msgIn->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v5 = msgIn->m_nInBufWord;
  v6 = m_nBitsAvail - 32;
  msgIn->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    msgIn->m_nInBufWord = 0;
    v7 = v5;
  }
  else
  {
    v8 = msgIn->m_pDataIn;
    v9 = msgIn->m_pBufferEnd;
    msgIn->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msgIn->m_nBitsAvail = 1;
      msgIn->m_nInBufWord = 0;
      msgIn->m_pDataIn = v8 + 1;
      v7 = v5;
    }
    else
    {
      if ( v8 <= v9 )
      {
        msgIn->m_nInBufWord = *v8;
        msgIn->m_pDataIn = v8 + 1;
      }
      else
      {
        msgIn->m_bOverflow = true;
        msgIn->m_nInBufWord = 0;
      }
      v7 = v5;
    }
  }
LABEL_19:
  if ( v7 != GetHostVersion() )
    return;
  v84 = 0;
  if ( flExpiryTime->m_nReservationCookie != 0 )
  {
    v74 = (int)(flExpiryTime->m_flReservationExpiryTime - net_time);
    v16 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Reservation request from %s rejected: server already reserved (for %d more seconds)\n", v16, v74);
    goto LABEL_99;
  }
  v17 = flExpiryTime->GetNumFakeClients(this: flExpiryTime);
  GetNumClients = flExpiryTime->GetNumClients;
  *(_DWORD *)key = v17;
  if ( GetNumClients(this: flExpiryTime) - v17 > 0 )
  {
    v19 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Reservation request from %s rejected: server not empty\n", v19);
    goto LABEL_99;
  }
  if ( flExpiryTime->m_bIsDedicatedForXbox )
  {
LABEL_73:
    LongLong = (IceSubkey *)CBitRead::ReadLongLong(this: msgIn);
    v52 = msgIn->m_nBitsAvail;
    cipher._keysched = LongLong;
    *(_DWORD *)key = v53;
    if ( v52 >= 32 )
    {
      v54 = msgIn->m_nInBufWord;
      v55 = v52 - 32;
      msgIn->m_nBitsAvail = v55;
      if ( v55 != 0 )
      {
        msgIn->m_nInBufWord = 0;
        v56 = v54;
      }
      else
      {
        v57 = msgIn->m_pDataIn;
        v58 = msgIn->m_pBufferEnd;
        msgIn->m_nBitsAvail = 32;
        if ( v57 == v58 )
        {
          msgIn->m_nInBufWord = 0;
          msgIn->m_nBitsAvail = 1;
          msgIn->m_pDataIn = v57 + 1;
          v56 = v54;
        }
        else
        {
          if ( v57 <= v58 )
          {
            msgIn->m_nInBufWord = *v57;
            msgIn->m_pDataIn = v57 + 1;
          }
          else
          {
            msgIn->m_nInBufWord = 0;
            msgIn->m_bOverflow = true;
          }
          v56 = v54;
        }
      }
LABEL_91:
      m_fValue = sv_reservation_timeout.m_pParent->m_Value.m_fValue;
      *(float *)&cipher._rounds = sv_reservation_timeout.m_pParent->m_Value.m_fValue;
      v73 = __PAIR64__(*(unsigned int *)key, (unsigned int)cipher._keysched->val);
      v66 = netadr_s::ToString(this: adr, baseOnly: false);
      DevMsg(
        a1: "Reservation request from %s accepted: server reserved with reservation cookie 0x%llx for %.1f seconds\n",
        v66,
        v73,
        m_fValue);
      DevMsg(a1: "            settings size = %d\n", v56);
      v67 = __PAIR64__(*(unsigned int *)key, (unsigned int)cipher._keysched->val);
      v68 = flExpiryTime;
      flExpiryTime->m_flReservationExpiryTime = *(float *)&cipher._rounds + net_time;
      v84 = 1;
      CBaseServer::SetReservationCookie(this: v68, uiCookie: v67, pchReasonFormat: "ReplyReservationRequest");
      v68->m_numGameSlots = 0;
      if ( v56 > 0 )
      {
        v69 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v69 != nullptr )
          v70 = KeyValues::KeyValues(this: v69, setName: defaultValue);
        else
          v70 = nullptr;
        if ( (unsigned int)v56 <= 0x258 )
        {
          CUtlBuffer::CUtlBuffer(this: (CUtlBuffer *)&tmp[588], growSize: 0, initSize: 0, nFlags: 0);
          CBitRead::ReadBytes(this: msgIn, pOut: (char *)&decrypted[1012], nBytes: v56);
          CUtlBuffer::Put(this: (CUtlBuffer *)&tmp[588], pMem: &decrypted[1012], size: v56);
          KeyValues::ReadAsBinary(this: v70, buffer: (CUtlBuffer *)&tmp[588]);
          serverGameDLL->ApplyGameSettings(this: serverGameDLL, a2: v70);
          Int = KeyValues::GetInt(this: v70, keyName: "members/numSlots", defaultValue: 0);
          flExpiryTime->m_numGameSlots = Int;
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: (CUtlBuffer *)&tmp[588]);
        }
        if ( v70 != nullptr )
          KeyValues::deleteThis(this: v70);
      }
      goto LABEL_99;
    }
    v59 = msgIn->m_pBufferEnd;
    v60 = msgIn->m_nInBufWord;
    v61 = 32 - v52;
    v62 = msgIn->m_pDataIn;
    if ( v62 == v59 )
    {
      msgIn->m_nBitsAvail = 1;
      msgIn->m_nInBufWord = 0;
      msgIn->m_bOverflow = true;
    }
    else
    {
      if ( v62 > v59 )
      {
        msgIn->m_bOverflow = true;
        msgIn->m_nInBufWord = 0;
        goto LABEL_88;
      }
      msgIn->m_nInBufWord = *v62;
    }
    msgIn->m_pDataIn = v62 + 1;
LABEL_88:
    if ( msgIn->m_bOverflow )
    {
      v56 = 0;
    }
    else
    {
      v63 = msgIn->m_nInBufWord;
      v64 = (v63 & CBitBuffer::s_nMaskTable[v61]) << msgIn->m_nBitsAvail;
      msgIn->m_nBitsAvail = 32 - v61;
      v56 = v60 | v64;
      msgIn->m_nInBufWord = v63 >> v61;
    }
    goto LABEL_91;
  }
  rounds = flExpiryTime->GetChallengeNr(this: flExpiryTime, a2: adr);
  cipher._rounds = rounds;
  if ( !CBaseServer::CanAcceptChallengesFrom(this: flExpiryTime, adrFrom: adr) )
  {
    v75 = netadr_s::ToString(this: &flExpiryTime->m_adrReservationGraceStarted, baseOnly: false);
    v21 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Reservation request from address %s, but challenges exclusive for %s\n", v21, v75);
    goto LABEL_99;
  }
  if ( rounds == 0 )
  {
    v22 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Reservation request from unknown address %s\n", v22);
    goto LABEL_99;
  }
  v23 = msgIn->m_nBitsAvail;
  if ( v23 >= 32 )
  {
    v24 = msgIn->m_nInBufWord;
    v25 = v23 - 32;
    msgIn->m_nBitsAvail = v25;
    if ( v25 != 0 )
    {
      msgIn->m_nInBufWord = 0;
      v26 = v24;
    }
    else
    {
      v27 = msgIn->m_pDataIn;
      v28 = msgIn->m_pBufferEnd;
      msgIn->m_nBitsAvail = 32;
      if ( v27 == v28 )
      {
        msgIn->m_nInBufWord = 0;
        msgIn->m_nBitsAvail = 1;
        msgIn->m_pDataIn = v27 + 1;
        v26 = v24;
      }
      else
      {
        if ( v27 <= v28 )
        {
          msgIn->m_nInBufWord = *v27;
          msgIn->m_pDataIn = v27 + 1;
        }
        else
        {
          msgIn->m_nInBufWord = 0;
          msgIn->m_bOverflow = true;
        }
        v26 = v24;
      }
    }
    goto LABEL_48;
  }
  v29 = msgIn->m_pBufferEnd;
  v30 = msgIn->m_nInBufWord;
  v31 = 32 - v23;
  v32 = msgIn->m_pDataIn;
  if ( v32 == v29 )
  {
    msgIn->m_nBitsAvail = 1;
    msgIn->m_nInBufWord = 0;
    msgIn->m_bOverflow = true;
LABEL_43:
    msgIn->m_pDataIn = v32 + 1;
    goto LABEL_44;
  }
  if ( v32 <= v29 )
  {
    msgIn->m_nInBufWord = *v32;
    goto LABEL_43;
  }
  msgIn->m_bOverflow = true;
  msgIn->m_nInBufWord = 0;
LABEL_44:
  if ( msgIn->m_bOverflow )
  {
    v26 = 0;
    goto LABEL_46;
  }
  v34 = msgIn->m_nInBufWord;
  v35 = (v34 & CBitBuffer::s_nMaskTable[v31]) << msgIn->m_nBitsAvail;
  msgIn->m_nBitsAvail = 32 - v31;
  v26 = v35 | v30;
  rounds = cipher._rounds;
  msgIn->m_nInBufWord = v34 >> v31;
LABEL_48:
  *(_DWORD *)key = v26;
  if ( v26 > 0 && (unsigned int)v26 <= 0x400 && (v26 & 0x80000007) == 0 )
  {
    IceKey::IceKey(this: (IceKey *)&buf.m_GetOverflowFunc, n: 1);
    cipher._size = rounds ^ 0x5EF8CE12;
    cipher._rounds = rounds ^ 0xAA98E42C;
    IceKey::set(this: (IceKey *)&buf.m_GetOverflowFunc, key: (const unsigned __int8 *)&cipher);
    CBitRead::ReadBytes(this: msgIn, (char *)pOut, nBytes: v26);
    v36 = (unsigned __int8 *)pOut;
    v37 = ((unsigned int)(*(_DWORD *)key - 1) >> 3) + 1;
    do
    {
      IceKey::decrypt(this: (IceKey *)&buf.m_GetOverflowFunc, ctext: v36, ptext: v36);
      v36 += 8;
      --v37;
    }
    while ( v37 != 0 );
    CBitRead::StartReading(this: msgIn, pData: pOut, nBytes: *(unsigned int *)key, iStartBit: 0, nBits: -1);
    v38 = msgIn->m_nBitsAvail;
    if ( v38 >= 32 )
    {
      v39 = msgIn->m_nInBufWord;
      v40 = v38 - 32;
      msgIn->m_nBitsAvail = v40;
      if ( v40 != 0 )
      {
        msgIn->m_nInBufWord = 0;
        v41 = v39;
      }
      else
      {
        v42 = msgIn->m_pDataIn;
        v43 = msgIn->m_pBufferEnd;
        msgIn->m_nBitsAvail = 32;
        if ( v42 == v43 )
        {
          msgIn->m_nBitsAvail = 1;
          msgIn->m_nInBufWord = 0;
          msgIn->m_pDataIn = v42 + 1;
          v41 = v39;
        }
        else
        {
          if ( v42 <= v43 )
          {
            msgIn->m_nInBufWord = *v42;
            msgIn->m_pDataIn = v42 + 1;
          }
          else
          {
            msgIn->m_bOverflow = true;
            msgIn->m_nInBufWord = 0;
          }
          v41 = v39;
        }
      }
      goto LABEL_70;
    }
    v44 = msgIn->m_pBufferEnd;
    v45 = msgIn->m_nInBufWord;
    v46 = 32 - v38;
    v47 = msgIn->m_pDataIn;
    if ( v47 == v44 )
    {
      msgIn->m_nBitsAvail = 1;
      msgIn->m_nInBufWord = 0;
      msgIn->m_bOverflow = true;
    }
    else
    {
      if ( v47 > v44 )
      {
        msgIn->m_bOverflow = true;
        msgIn->m_nInBufWord = 0;
LABEL_68:
        if ( !msgIn->m_bOverflow )
        {
          v48 = msgIn->m_nInBufWord;
          v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << msgIn->m_nBitsAvail;
          msgIn->m_nBitsAvail = 32 - v46;
          v41 = v49 | v45;
          msgIn->m_nInBufWord = v48 >> v46;
LABEL_70:
          if ( v41 == -17973521 )
          {
LABEL_72:
            IceKey::~IceKey(this: (IceKey *)&buf.m_GetOverflowFunc);
            goto LABEL_73;
          }
        }
        v76 = *(_DWORD *)key;
        v50 = netadr_s::ToString(this: adr, baseOnly: false);
        _Msg(a1: "ReplyReservationRequest:  Reservation request with bogus payload data from %s [%d bytes]\n", v50, v76);
        goto LABEL_72;
      }
      msgIn->m_nInBufWord = *v47;
    }
    msgIn->m_pDataIn = v47 + 1;
    goto LABEL_68;
  }
LABEL_46:
  v33 = netadr_s::ToString(this: adr, baseOnly: false);
  DevMsg(a1: "ReplyReservationRequest:  Reservation request with bogus payload size from %s [%d bytes]\n", v33, v26);
LABEL_99:
  v72 = flExpiryTime;
  flExpiryTime->m_ReservationStatus.m_bActive = true;
  v72->m_ReservationStatus.m_bSuccess = v84;
  v72->m_ReservationStatus.m_Remote = *adr;
  if ( v84 == 0 )
    CBaseServer::SendReservationStatus(this: v72);
}

//------------------------------------------------------------------------------
// Address: 0x101F68C0
// Name: public: virtual void CBaseServer::RemoveClientFromGame(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::RemoveClientFromGame(vgui::Panel *this, const char *panelName)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101F6B70
// Name: protected: virtual bool CBaseServer::ShouldUpdateMasterServer(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::ShouldUpdateMasterServer(vgui::Splitter *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101FF660
// Name: protected: virtual class CBaseClient __near * CBaseServer::CreateNewClient(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CBaseServer::CreateNewClient(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100357A0
// Name: protected: virtual class CBaseClient __near * CBaseServer::CreateNewClient(int)
// Source: json
//------------------------------------------------------------------------------
vgui::Panel *__thiscall CBaseServer::CreateNewClient(vgui::Panel *this, wchar_t key)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10134980
// Name: public: bool CSteam3Server::BSecure(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CSteam3Server::BSecure(CSteam3Server *this)
{
  ISteamGameServer *m_pSteamGameServer; // ecx

  m_pSteamGameServer = this->m_pSteamGameServer;
  return m_pSteamGameServer != nullptr && m_pSteamGameServer->BSecure(this: m_pSteamGameServer);
}

//------------------------------------------------------------------------------
// Address: 0x101349A0
// Name: int SortServerTags(char __near * const __near *,char __near * const __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __cdecl SortServerTags(const char **p1, const char **p2)
{
  return _V_strcmp(s1: *p1, s2: *p2) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x101349D0
// Name: SvGameDataChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl SvGameDataChangeCallback()
{
  if ( sv.m_State >= ss_active )
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: "heartbeat\n", nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101349F0
// Name: protected: bool CBaseServer::CanAcceptChallengesFrom(struct netadr_s __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::CanAcceptChallengesFrom(CBaseServer *this, netadr_s *adrFrom)
{
  return this->m_flTimeReservationGraceStarted < 0.0
      || net_time - this->m_flTimeReservationGraceStarted > sv_reservation_grace.m_pParent->m_Value.m_fValue
      || netadr_s::CompareAdr(this: adrFrom, a: &this->m_adrReservationGraceStarted, onlyBase: false);
}

//------------------------------------------------------------------------------
// Address: 0x10134A50
// Name: public: virtual char const __near * CBaseServer::GetPassword(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseServer::GetPassword(CBaseServer *this)
{
  char *v1; // esi
  char *m_pszString; // eax

  if ( (sv_password.m_nFlags & 0x1000) != 0 )
  {
    v1 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = sv_password.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      return nullptr;
    v1 = sv_password.m_pParent->m_Value.m_pszString;
    if ( *m_pszString == 0 )
      return nullptr;
  }
  if ( _V_stricmp(s1: v1, s2: "none") != 0 )
    return v1;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10134AA0
// Name: public: virtual void CBaseServer::SetPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SetPassword(CBaseServer *this, const char *password)
{
  if ( password != nullptr )
    V_strncpy(pDest: this->m_Password, pSrc: password, maxLen: 32);
  else
    this->m_Password[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10134AD0
// Name: public: bool CBaseServer::IsSinglePlayerGame(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::IsSinglePlayerGame(CBaseServer *this)
{
  return !sv.m_bIsDedicated && this->m_nMaxclients <= 1;
}

//------------------------------------------------------------------------------
// Address: 0x10134AF0
// Name: public: virtual void CBaseServer::FillServerInfo(class SVC_ServerInfo __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::FillServerInfo(CBaseServer *this, SVC_ServerInfo *serverinfo)
{
  V_FileBase(in: com_gamedir, out: gamedir_3, maxlen: 260);
  serverinfo->m_nProtocol = GetHostVersion();
  serverinfo->m_nServerCount = this->GetSpawnCount(this);
  serverinfo->m_nMapCRC = this->worldmapCRC;
  serverinfo->m_nClientCRC = this->clientDllCRC;
  serverinfo->m_nStringTableCRC = this->stringTableCRC;
  serverinfo->m_nMaxClients = this->GetMaxClients(this);
  serverinfo->m_nMaxClasses = this->serverclasses;
  serverinfo->m_bIsDedicated = this->IsDedicated(this);
  serverinfo->m_cOS = 87;
  serverinfo->m_cOS = tolower(c: 87);
  serverinfo->m_fTickInterval = this->GetTickInterval(this);
  serverinfo->m_szGameDir = gamedir_3;
  serverinfo->m_szMapName = this->GetMapName(this);
  serverinfo->m_szSkyName = this->m_szSkyname;
  serverinfo->m_szHostName = this->GetName(this);
  serverinfo->m_bIsHLTV = this->IsHLTV(this);
}

//------------------------------------------------------------------------------
// Address: 0x10134BC0
// Name: protected: virtual void CBaseServer::ReplyServerChallenge(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ReplyServerChallenge(CBaseServer *this, netadr_s *adr)
{
  int v3; // ebx
  bf_write msg; // [esp+Ch] [ebp-28h] BYREF
  char buffer[16]; // [esp+24h] [ebp-10h] BYREF

  bf_write::bf_write(this: &msg, pData: buffer, nBytes: 16, nBits: -1);
  v3 = this->GetChallengeNr(this, a2: adr);
  bf_write::WriteLong(this: &msg, val: -1);
  bf_write::WriteByte(this: &msg, val: 0x41u);
  bf_write::WriteLong(this: &msg, val: v3);
  NET_SendPacket(
    chan: nullptr,
    sock: this->m_Socket,
    to: adr,
    data: msg.m_pData,
    length: (msg.m_iCurBit + 7) >> 3,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10134C50
// Name: public: virtual char const __near * CBaseServer::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseServer::GetName(CBaseServer *this)
{
  char *result; // eax

  if ( (host_name.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = host_name.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10134D10
// Name: protected: virtual bool CBaseServer::CheckProtocol(struct netadr_s __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::CheckProtocol(CBaseServer *this, netadr_s *adr, int nProtocol)
{
  int HostVersion; // eax
  CBaseServer_vtbl *v5; // ebx
  int v6; // eax
  int v8; // eax

  if ( nProtocol == GetHostVersion() )
    return 1;
  HostVersion = GetHostVersion();
  v5 = this->__vftable;
  if ( nProtocol <= HostVersion )
  {
    v8 = GetHostVersion();
    v5->RejectConnection(
      this,
      a2: adr,
      a3: "This server is using a newer protocol ( %i ) than your client ( %i ).\n",
      v8,
      nProtocol);
  }
  else
  {
    v6 = GetHostVersion();
    v5->RejectConnection(
      this,
      a2: adr,
      a3: "This server is using an older protocol ( %i ) than your client ( %i ).\n",
      v6,
      nProtocol);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10134D80
// Name: protected: virtual bool CBaseServer::CheckChallengeType(class CBaseClient __near *,int,struct netadr_s __near &,int,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::CheckChallengeType(
        CBaseServer *this,
        CBaseClient *client,
        unsigned int nNewUserID,
        netadr_s *adr,
        int nAuthProtocol,
        const char *pchLogonCookie,
        unsigned int cbCookie)
{
  netadrtype_t type; // eax
  int v10; // edx
  unsigned int v11; // eax
  CSteam3Server *v12; // eax
  CSteam3Server *v13; // eax
  netadr_s checkAdr; // [esp+8h] [ebp-14h] BYREF
  CSteamID steamID; // [esp+14h] [ebp-8h] BYREF

  if ( (unsigned int)(nAuthProtocol - 1) > 2 )
  {
    this->RejectConnection(this, a2: adr, a3: "Invalid connection.\n");
    return 0;
  }
  else
  {
    if ( nAuthProtocol == 2 && (_V_strlen(str: pchLogonCookie) <= 0 || _V_strlen(str: pchLogonCookie) != 32) )
    {
      this->RejectConnection(this, a2: adr, a3: "Invalid authentication certificate length.\n");
      return 0;
    }
    if ( !this->m_bIsDedicatedForXbox )
    {
      if ( nAuthProtocol == 3 )
      {
        steamID.m_steamid.m_comp = 0;
        CBaseClient::SetSteamID(this: client, &steamID);
        if ( cbCookie - 1 > 0x7FE )
        {
          this->RejectConnection(this, a2: adr, a3: "STEAM certificate length error! %i/%i\n", cbCookie, 2048);
          return 0;
        }
        type = adr->type;
        v10 = *(_DWORD *)&adr->port;
        *(_DWORD *)checkAdr.ip = *(_DWORD *)adr->ip;
        checkAdr.type = type;
        *(_DWORD *)&checkAdr.port = v10;
        if ( CCircularBuffer::GetReadAvailable(this: adr) == NA_LOOPBACK || netadr_s::IsLocalhost(this: adr) )
        {
          v11 = netadr_s::addr_htonl(this: &net_local_adr);
          netadr_s::SetIP(this: &checkAdr, unIP: v11);
        }
        v12 = Steam3Server();
        if ( !CSteam3Server::NotifyClientConnect(
                this: v12,
                client,
                unUserID: nNewUserID,
                adr: &checkAdr,
                pvCookie: pchLogonCookie,
                ucbCookie: cbCookie)
          && Steam3Server()->m_eServerMode != eServerModeNoAuthentication )
        {
          this->RejectConnection(this, a2: adr, a3: "STEAM validation rejected\n");
          return 0;
        }
      }
      else
      {
        v13 = Steam3Server();
        if ( !CSteam3Server::NotifyLocalClientConnect(this: v13, client) )
        {
          this->RejectConnection(this, a2: adr, a3: "GSCreateLocalUser failed\n");
          return 0;
        }
      }
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10134FA0
// Name: public: virtual float CBaseServer::GetTime(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CBaseServer::GetTime(CBaseServer *this)
{
  return (double)this->m_nTickCount * this->m_flTickInterval;
}

//------------------------------------------------------------------------------
// Address: 0x10134FE0
// Name: public: virtual void CBaseServer::DisconnectClient(class IClient __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::DisconnectClient(CBaseServer *this, IClient *client, const char *reason)
{
  client->Disconnect(this: client, a2: reason);
}

//------------------------------------------------------------------------------
// Address: 0x10135000
// Name: public: virtual void CBaseServer::RejectConnection(struct netadr_s const __near &,char __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseServer::RejectConnection(CBaseServer *this, netadr_s *adr, char *fmt, ...)
{
  const char *v3; // eax
  char text[1024]; // [esp+4h] [ebp-400h] BYREF
  va_list params; // [esp+418h] [ebp+14h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: text, maxLen: 1024, pFormat: fmt, params);
  NET_OutOfBandPrintf(sock: this->m_Socket, adr, format: "%c%s", 57, text);
  v3 = netadr_s::ToString(this: adr, baseOnly: false);
  _Warning(a1: "RejectConnection: %s - %s\n", v3, text);
}

//------------------------------------------------------------------------------
// Address: 0x10135090
// Name: public: class INetworkStringTable __near * CBaseServer::GetInstanceBaselineTable(void)
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CBaseServer::GetInstanceBaselineTable(CBaseServer *this)
{
  if ( this->m_pInstanceBaselineTable == nullptr )
    this->m_pInstanceBaselineTable = this->m_StringTables->FindTable(this: this->m_StringTables, a2: "instancebaseline");
  return this->m_pInstanceBaselineTable;
}

//------------------------------------------------------------------------------
// Address: 0x101350C0
// Name: public: class INetworkStringTable __near * CBaseServer::GetLightStyleTable(void)
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CBaseServer::GetLightStyleTable(CBaseServer *this)
{
  if ( this->m_pLightStyleTable == nullptr )
    this->m_pLightStyleTable = this->m_StringTables->FindTable(this: this->m_StringTables, a2: "lightstyles");
  return this->m_pLightStyleTable;
}

//------------------------------------------------------------------------------
// Address: 0x101350F0
// Name: public: class INetworkStringTable __near * CBaseServer::GetUserInfoTable(void)
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CBaseServer::GetUserInfoTable(CBaseServer *this)
{
  CNetworkStringTableContainer *m_StringTables; // ecx

  if ( this->m_pUserInfoTable == nullptr )
  {
    m_StringTables = this->m_StringTables;
    if ( m_StringTables == nullptr )
      return nullptr;
    this->m_pUserInfoTable = m_StringTables->FindTable(this: m_StringTables, a2: "userinfo");
  }
  return this->m_pUserInfoTable;
}

//------------------------------------------------------------------------------
// Address: 0x10135130
// Name: protected: void CBaseServer::CheckMasterServerRequestRestart(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::CheckMasterServerRequestRestart(CBaseServer *this)
{
  CSteam3Server *v1; // eax

  if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
  {
    v1 = Steam3Server();
    if ( v1->m_pSteamMasterServerUpdater->WasRestartRequested(this: v1->m_pSteamMasterServerUpdater) )
    {
      _Msg(a1: "%cMasterRequestRestart\n", 3);
      if ( g_pFileSystem->IsSteam(this: g_pFileSystem) )
      {
        _Msg(a1: "Your server needs to be restarted in order to receive the latest update.\n");
        if ( (unsigned __int8)_LoggingSystem_IsChannelEnabled(a1: LOG_SERVER_LOG, a2: 0) != 0 )
          _LoggingSystem_Log(
            a1: LOG_SERVER_LOG,
            a2: 0,
            a3: "Your server needs to be restarted in order to receive the latest update.\n");
      }
      else
      {
        _Msg(a1: "Your server is out of date.  Please update and restart.\n");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101351C0
// Name: protected: void CBaseServer::ForwardPacketsFromMasterServerUpdater(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ForwardPacketsFromMasterServerUpdater(CBaseServer *this)
{
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // edi
  int i; // esi
  unsigned __int16 v3; // bx
  unsigned __int8 data[16384]; // [esp+4h] [ebp-4018h] BYREF
  netadr_s to; // [esp+4004h] [ebp-18h] BYREF
  CBaseServer *v6; // [esp+4010h] [ebp-Ch]
  unsigned int unIP; // [esp+4014h] [ebp-8h] BYREF
  unsigned __int16 v8; // [esp+4018h] [ebp-4h] BYREF

  v6 = this;
  m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
  if ( m_pSteamMasterServerUpdater != nullptr )
  {
    for ( i = m_pSteamMasterServerUpdater->GetNextOutgoingPacket(
                this: m_pSteamMasterServerUpdater,
                a2: data,
                a3: 0x4000,
                a4: &unIP,
                a5: &v8);
          i > 0;
          i = m_pSteamMasterServerUpdater->GetNextOutgoingPacket(
                this: m_pSteamMasterServerUpdater,
                a2: data,
                a3: 0x4000,
                a4: &unIP,
                a5: &v8) )
    {
      v3 = v8;
      netadr_s::SetIP(this: &to, unIP);
      netadr_s::SetPort(this: &to, newport: v3);
      netadr_s::SetType(this: &to, newtype: NA_IP);
      NET_SendPacket(
        chan: nullptr,
        sock: v6->m_Socket,
        &to,
        data,
        length: i,
        pVoicePayload: nullptr,
        bUseCompression: false,
        unMillisecondsDelay: 0);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135280
// Name: CEventInfo_LessFunc
// Source: json
//------------------------------------------------------------------------------
bool __cdecl CEventInfo_LessFunc(CEventInfo *const *lhs, CEventInfo *const *rhs)
{
  return **(_WORD **)lhs < **(_WORD **)rhs;
}

//------------------------------------------------------------------------------
// Address: 0x101352A0
// Name: public: class CBaseClient __near * CBaseServer::GetBaseUserForSplitClient(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseServer::GetBaseUserForSplitClient(CBaseServer *this, CBaseClient *pSplitUser)
{
  CBaseClient *result; // eax

  result = pSplitUser->m_pAttachedTo;
  if ( result == nullptr )
    return pSplitUser;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101352C0
// Name: public: void CBaseServer::UpdateReservedState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::UpdateReservedState(CBaseServer *this)
{
  if ( this->m_flReservationExpiryTime != 0.0 && this->m_nReservationCookie == 0
    || net_time > this->m_flReservationExpiryTime )
  {
    this->m_flReservationExpiryTime = 0.0;
    CGameServer::UpdateHibernationState(this: &sv);
  }
  if ( this->m_flTimeLastClientLeft != -1.0 )
    CGameServer::UpdateHibernationState(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10135340
// Name: public: unsigned __int64 CBaseServer::GetReservationCookie(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CBaseServer::GetReservationCookie(CBaseServer *this)
{
  return this->m_nReservationCookie;
}

//------------------------------------------------------------------------------
// Address: 0x101353A0
// Name: public: bool CBaseServer::ShouldHideFromMasterServer(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::ShouldHideFromMasterServer(CBaseServer *this)
{
  return !this->IsDedicated(this) || serverGameDLL != nullptr && serverGameDLL->ShouldHideServer(this: serverGameDLL);
}

//------------------------------------------------------------------------------
// Address: 0x101353D0
// Name: public: virtual int CBaseServer::GetMaxClients(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetMaxClients(CBaseServer *this)
{
  return this->m_nMaxclients;
}

//------------------------------------------------------------------------------
// Address: 0x101353E0
// Name: public: int CBaseServer::GetMaxHumanPlayers(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetMaxHumanPlayers(CBaseServer *this)
{
  int result; // eax

  if ( serverGameClients == nullptr )
    return this->GetMaxClients(this);
  result = serverGameClients->GetMaxHumanPlayers(this: serverGameClients);
  if ( result == -1 )
    return this->GetMaxClients(this);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10135410
// Name: sv_showtags
// Source: json
//------------------------------------------------------------------------------
void __cdecl sv_showtags()
{
  const char *v0; // eax
  const char *v1; // eax

  _Msg(a1: "Tags:\n");
  v0 = CUtlString::operator char const *(this: &sv.m_GameTypePublic);
  _Msg(a1: "Public :  %s\n", v0);
  v1 = CUtlString::operator char const *(this: &sv.m_GameTypePrivate);
  _Msg(a1: "Private:  %s\n", v1);
}

//------------------------------------------------------------------------------
// Address: 0x10135450
// Name: SvPasswordChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl SvPasswordChangeCallback()
{
  if ( sv.IsActive(this: &sv) )
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: "heartbeat\n", nTickDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10135480
// Name: protected: bool CBaseServer::ValidChallenge(struct netadr_s __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::ValidChallenge(CBaseServer *this, netadr_s *adr, int challengeNr)
{
  if ( !this->IsActive(this) || !this->IsMultiplayer(this) )
    return 0;
  if ( sv_enableoldqueries.m_pParent != nullptr && sv_enableoldqueries.m_pParent->m_Value.m_nValue != 0
    || this->CheckChallengeNr(this, a2: adr, a3: challengeNr) )
  {
    return 1;
  }
  this->ReplyServerChallenge(this, a2: adr);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10135540
// Name: public: virtual int CBaseServer::GetNumPlayers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumPlayers(CBaseServer *this)
{
  int v1; // edi
  CNetworkStringTableContainer *m_StringTables; // ecx
  int v5; // ebx
  _BYTE *v6; // eax
  int count; // [esp+8h] [ebp-4h]

  v1 = 0;
  count = 0;
  if ( this->m_pUserInfoTable == nullptr )
  {
    m_StringTables = this->m_StringTables;
    if ( m_StringTables == nullptr )
      return 0;
    this->m_pUserInfoTable = m_StringTables->FindTable(this: m_StringTables, a2: "userinfo");
  }
  if ( this->m_pUserInfoTable == nullptr )
    return 0;
  v5 = this->m_pUserInfoTable->GetNumStrings(this: this->m_pUserInfoTable);
  if ( v5 > 0 )
  {
    do
    {
      v6 = this->m_pUserInfoTable->GetStringUserData(this: this->m_pUserInfoTable, a2: v1, a3: 0);
      if ( v6 != nullptr && v6[116] == 0 )
        ++count;
      ++v1;
    }
    while ( v1 < v5 );
  }
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x101355D0
// Name: public: void CBaseServer::SendReservationStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SendReservationStatus(CBaseServer *this)
{
  int HostVersion; // eax
  int m_iCurBit; // ecx
  bf_write msg; // [esp+4h] [ebp-28h] BYREF
  char buffer[16]; // [esp+1Ch] [ebp-10h] BYREF

  if ( this->m_ReservationStatus.m_bActive )
  {
    bf_write::bf_write(this: &msg, pData: buffer, nBytes: 16, nBits: -1);
    bf_write::WriteLong(this: &msg, val: -1);
    bf_write::WriteByte(this: &msg, val: 0x70u);
    HostVersion = GetHostVersion();
    bf_write::WriteLong(this: &msg, val: HostVersion);
    m_iCurBit = msg.m_iCurBit;
    if ( msg.m_iCurBit + 1 <= msg.m_nDataBits )
    {
      if ( !msg.m_bOverflow )
      {
        if ( this->m_ReservationStatus.m_bSuccess )
          msg.m_pData[msg.m_iCurBit >> 3] |= 1 << (msg.m_iCurBit & 7);
        else
          msg.m_pData[msg.m_iCurBit >> 3] &= ~(1 << (msg.m_iCurBit & 7));
        m_iCurBit = ++msg.m_iCurBit;
      }
    }
    else
    {
      msg.m_bOverflow = true;
    }
    NET_SendPacket(
      chan: nullptr,
      sock: this->m_Socket,
      to: &this->m_ReservationStatus.m_Remote,
      data: msg.m_pData,
      length: (m_iCurBit + 7) >> 3,
      pVoicePayload: nullptr,
      bUseCompression: false,
      unMillisecondsDelay: 0);
    this->m_ReservationStatus.m_bActive = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101356A0
// Name: protected: virtual void CBaseServer::CalculateCPUUsage(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::CalculateCPUUsage(CBaseServer *this)
{
  HANDLE CurrentProcess; // eax
  unsigned int dwLowDateTime; // eax
  __int64 v4; // kr00_8
  double v5; // st7
  _FILETIME exitTime; // [esp+4h] [ebp-30h] BYREF
  __int64 v7; // [esp+Ch] [ebp-28h]
  _FILETIME userTime; // [esp+14h] [ebp-20h] BYREF
  _FILETIME kernelTime; // [esp+1Ch] [ebp-18h] BYREF
  _FILETIME creationTime; // [esp+24h] [ebp-10h] BYREF
  _FILETIME nowTime; // [esp+2Ch] [ebp-8h] BYREF

  if ( sv_stats.m_pParent != nullptr && sv_stats.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( this->m_fStartTime == 0.0 )
      this->m_fStartTime = _Plat_FloatTime();
    if ( _Plat_FloatTime() > this->m_fLastCPUCheckTime + 1.0 )
    {
      CurrentProcess = GetCurrentProcess();
      GetProcessTimes(
        hProcess: CurrentProcess,
        lpCreationTime: &creationTime,
        lpExitTime: &exitTime,
        lpKernelTime: &kernelTime,
        lpUserTime: &userTime);
      GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: &nowTime);
      dwLowDateTime = lastNow;
      if ( lastNow == 0 )
      {
        dwLowDateTime = creationTime.dwLowDateTime;
        lastNow = (__int64)creationTime;
      }
      v4 = *(_QWORD *)&userTime + *(_QWORD *)&kernelTime;
      v7 = *(_QWORD *)&userTime + *(_QWORD *)&kernelTime - lastTotalTime;
      v5 = (double)v7;
      v7 = *(_QWORD *)&nowTime - __PAIR64__(HIDWORD(lastNow), dwLowDateTime);
      this->m_fCPUPercent = v5 / (double)(__int64)(*(_QWORD *)&nowTime - __PAIR64__(HIDWORD(lastNow), dwLowDateTime));
      if ( _Plat_FloatTime() > lastAvg + 5.0 )
      {
        lastNow = (__int64)nowTime;
        lastTotalTime = v4;
        lastAvg = this->m_fLastCPUCheckTime;
      }
      this->m_fLastCPUCheckTime = _Plat_FloatTime();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101357F0
// Name: protected: virtual bool CBaseServer::CheckPassword(struct netadr_s __near &,char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::CheckPassword(CBaseServer *this, netadr_s *adr, const char *password, const char *name)
{
  const char *v5; // edi
  int v6; // esi

  if ( this->m_nReservationCookie != 0 )
    return true;
  v5 = this->GetPassword(this);
  if ( v5 == nullptr )
    return true;
  if ( netadr_s::IsLocalhost(this: adr) || netadr_s::IsLoopback(this: adr) )
    return true;
  v6 = _V_strlen(str: v5);
  return v6 == _V_strlen(str: password) && V_strncmp(s1: password, s2: v5, count: v6) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10135880
// Name: public: virtual void CBaseServer::SetPaused(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SetPaused(CBaseServer *this, bool paused)
{
  void (__thiscall *BroadcastMessage_2)(struct CBaseServer *, INetMessage *, bool, bool); // edx
  SVC_SetPause setpause; // [esp+4h] [ebp-14h] BYREF

  if ( (this->m_State == ss_paused || this->IsPausable(this)) && this->IsActive(this) )
  {
    BroadcastMessage_2 = this->BroadcastMessage_2;
    setpause.m_bPaused = paused;
    setpause.m_bReliable = true;
    this->m_State = paused + 2;
    setpause.m_NetChannel = nullptr;
    setpause.__vftable = (SVC_SetPause_vtbl *)&SVC_SetPause::`vftable';
    BroadcastMessage_2(this, a2: &setpause, a3: false, a4: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101358F0
// Name: public: bool CBaseServer::GetClassBaseline(class ServerClass __near *,void const __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::GetClassBaseline(
        CBaseServer *this,
        ServerClass *pClass,
        const void **pData,
        int *pDatalen)
{
  DWORD CurrentThreadId; // eax
  const void *v6; // eax
  bool result; // al

  if ( sv_instancebaselines.m_pParent != nullptr && sv_instancebaselines.m_pParent->m_Value.m_nValue != 0 )
  {
    if ( pClass->m_InstanceBaselineIndex == 0xFFFF )
      _Error(a1: "SV_GetInstanceBaseline: missing instance baseline for class '%s'", pClass->m_pNetworkName);
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != g_svInstanceBaselineMutex.m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)&g_svInstanceBaselineMutex, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: &g_svInstanceBaselineMutex, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++g_svInstanceBaselineMutex.m_depth;
    }
    if ( this->m_pInstanceBaselineTable == nullptr )
      this->m_pInstanceBaselineTable = this->m_StringTables->FindTable(
                                         this: this->m_StringTables,
                                         a2: "instancebaseline");
    v6 = this->m_pInstanceBaselineTable->GetStringUserData(
           this: this->m_pInstanceBaselineTable,
           a2: pClass->m_InstanceBaselineIndex,
           a3: pDatalen);
    *pData = v6;
    result = v6 != nullptr;
    if ( --g_svInstanceBaselineMutex.m_depth == 0 )
      _InterlockedExchange((volatile __int32 *)&g_svInstanceBaselineMutex, 0);
  }
  else
  {
    *pData = dummy;
    *pDatalen = 1;
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101359E0
// Name: public: virtual void CBaseServer::BroadcastPrintf(char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseServer::BroadcastPrintf(CBaseServer *this, const char *fmt, ...)
{
  void (__thiscall *BroadcastMessage_2)(struct CBaseServer *, INetMessage *, bool, bool); // edx
  char string[1024]; // [esp+0h] [ebp-C14h] BYREF
  SVC_Print print; // [esp+400h] [ebp-814h] BYREF
  va_list params; // [esp+C24h] [ebp+10h] BYREF

  va_start(params, fmt);
  V_vsnprintf(pDest: string, maxLen: 1024, pFormat: fmt, params);
  print.m_szText = string;
  BroadcastMessage_2 = this->BroadcastMessage_2;
  print.m_NetChannel = nullptr;
  print.m_bReliable = false;
  print.__vftable = (SVC_Print_vtbl *)&SVC_Print::`vftable';
  BroadcastMessage_2(this, a2: &print, a3: false, a4: false);
}

//------------------------------------------------------------------------------
// Address: 0x10135A50
// Name: public: virtual void CBaseServer::SetMaxClients(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SetMaxClients(CBaseServer *this, int number)
{
  int v2; // eax

  v2 = number;
  if ( number >= 1 )
  {
    if ( number > 64 )
      v2 = 64;
    this->m_nMaxclients = v2;
  }
  else
  {
    this->m_nMaxclients = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135A80
// Name: public: bool CBaseServer::IsExclusiveToLobbyConnections(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::IsExclusiveToLobbyConnections(CBaseServer *this)
{
  return this->IsDedicated(this)
      && sv_allow_lobby_connect_only.m_pParent != nullptr
      && sv_allow_lobby_connect_only.m_pParent->m_Value.m_nValue != 0
      && (sv_lan.m_pParent == nullptr || sv_lan.m_pParent->m_Value.m_nValue == 0);
}

//------------------------------------------------------------------------------
// Address: 0x10135C00
// Name: private: int CBaseServer::GetNextUserID(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNextUserID(CBaseServer *this)
{
  int m_Size; // ecx
  int v3; // esi
  int v4; // ebx
  CBaseClient *v5; // ecx
  int i; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Clients.m_Size;
  i = 0;
  if ( m_Size + 1 <= 0 )
    return this->m_nUserid + 1;
  while ( 1 )
  {
    v3 = 0;
    v4 = (this->m_nUserid + i + 1) % 0x7FFF;
    if ( m_Size > 0 )
    {
      do
      {
        v5 = this->m_Clients.m_Memory.m_pMemory[v3];
        if ( v5->GetUserID(this: &v5->IClient) == v4 )
          break;
        ++v3;
      }
      while ( v3 < this->m_Clients.m_Size );
    }
    m_Size = this->m_Clients.m_Size;
    if ( v3 == m_Size )
      break;
    if ( ++i >= m_Size + 1 )
      return this->m_nUserid + 1;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10135CF0
// Name: public: virtual int CBaseServer::GetNumClients(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumClients(CBaseServer *this)
{
  int v2; // ebx
  int i; // esi
  CBaseClient *v4; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->IsConnected(this: &v4->IClient) )
      ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10135D30
// Name: public: virtual int CBaseServer::GetNumProxies(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumProxies(CBaseServer *this)
{
  int v2; // ebx
  int i; // esi
  CBaseClient *v4; // ecx
  CBaseClient *v5; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->IsConnected(this: &v4->IClient) )
    {
      v5 = this->m_Clients.m_Memory.m_pMemory[i];
      if ( v5->IsHLTV(this: &v5->IClient) )
        ++v2;
    }
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10135D90
// Name: public: virtual bool CBaseServer::GetPlayerInfo(int,struct player_info_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::GetPlayerInfo(CBaseServer *this, int nClientIndex, unsigned int pinfo)
{
  player_info_s *v3; // edi
  void *m_StringTables; // ecx
  INetworkStringTable *UserInfoTable; // eax
  const void *v8; // eax

  v3 = (player_info_s *)pinfo;
  if ( pinfo == 0 )
    return 0;
  if ( nClientIndex >= 0 )
  {
    if ( this->m_pUserInfoTable != nullptr )
      goto LABEL_7;
    m_StringTables = this->m_StringTables;
    if ( m_StringTables != nullptr )
    {
      this->m_pUserInfoTable = (INetworkStringTable *)(*(int (__thiscall **)(void *, const char *))(*(_DWORD *)m_StringTables
                                                                                                  + 12))(
                                                        a1: m_StringTables,
                                                        a2: "userinfo");
LABEL_7:
      m_StringTables = this->m_pUserInfoTable;
    }
    if ( nClientIndex < (*(int (__thiscall **)(void *))(*(_DWORD *)m_StringTables + 12))(a1: m_StringTables) )
    {
      UserInfoTable = CBaseServer::GetUserInfoTable(this);
      v8 = UserInfoTable->GetStringUserData(this: UserInfoTable, a2: nClientIndex, a3: nullptr);
      if ( v8 != nullptr )
      {
        _V_memcpy(dest: v3, src: v8, count: 144);
        pinfo |= 3u;
        CByteswap::SwapFieldsToTargetEndian(
          this: (CByteswap *)&pinfo,
          pOutputBuffer: v3,
          pBaseData: v3,
          pDataMap: &player_info_s::m_DataMap);
        return 1;
      }
    }
  }
  _V_memset(dest: v3, fill: 0, count: 144);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10135E40
// Name: public: virtual void CBaseServer::UserInfoChanged(int)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseServer::UserInfoChanged(CBaseServer *this@<ecx>, int a2@<edi>, CByteswap nClientIndex)
{
  bool v4; // al
  CByteswap v5; // edi
  CBaseClient *v6; // ecx
  player_info_s pi; // [esp+4h] [ebp-94h] BYREF
  BOOL oldlock; // [esp+94h] [ebp-4h]

  if ( this->m_pUserInfoTable != nullptr )
  {
    v4 = CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: false);
    v5 = nClientIndex;
    LOBYTE(oldlock) = v4;
    v6 = this->m_Clients.m_Memory.m_pMemory[*(_DWORD *)&nClientIndex];
    if ( ((unsigned __int8 (__thiscall *)(CBaseClient *, player_info_s *, int))v6->FillUserInfo)(
           a1: v6,
           a2: &pi,
           a3: a2) != 0 )
    {
      nClientIndex = (CByteswap)(*(_DWORD *)&nClientIndex | 3);
      CByteswap::SwapFieldsToTargetEndian(
        this: &nClientIndex,
        pOutputBuffer: &pi,
        pBaseData: &pi,
        pDataMap: &player_info_s::m_DataMap);
      ((void (__stdcall *)(_DWORD, _DWORD))this->m_pUserInfoTable->SetStringUserData)(a1: v5, a2: 144);
    }
    else
    {
      ((void (__stdcall *)(_DWORD, _DWORD))this->m_pUserInfoTable->SetStringUserData)(a1: v5, a2: 0);
    }
    CNetworkStringTableContainer::Lock(this: networkStringTableContainerServer, bLock: oldlock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10135EF0
// Name: protected: virtual void CBaseServer::ReplyChallenge(struct netadr_s __near &,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ReplyChallenge(CBaseServer *this, netadr_s *adr, bf_read *inmsg)
{
  netadr_s *v4; // ebx
  int v5; // edi
  CSteam3Server *v6; // eax
  const CSteamID *GSSteamID; // eax
  unsigned int m_unAll64Bits; // edi
  unsigned int m_unAll64Bits_high; // ebx
  ISteamGameServer *m_pSteamGameServer; // ecx
  int v11; // eax
  unsigned int v12; // edi
  char *v13; // eax
  const char *v14; // eax
  const char *v15; // edi
  int HostVersion; // eax
  char buffer[512]; // [esp+0h] [ebp-328h] BYREF
  char context[256]; // [esp+200h] [ebp-128h] BYREF
  float m_flTimeReservationGraceStarted; // [esp+300h] [ebp-28h]
  char chValidateChallenge[12]; // [esp+304h] [ebp-24h] BYREF
  bf_write msg; // [esp+310h] [ebp-18h] BYREF
  char bWillRequirePassword_3; // [esp+333h] [ebp+Bh]
  char bWillRequirePassword_3a; // [esp+333h] [ebp+Bh]
  int challengeNr; // [esp+334h] [ebp+Ch]

  m_flTimeReservationGraceStarted = this->m_flTimeReservationGraceStarted;
  if ( m_flTimeReservationGraceStarted < 0.0
    || net_time - m_flTimeReservationGraceStarted > sv_reservation_grace.m_pParent->m_Value.m_fValue )
  {
    v4 = adr;
  }
  else
  {
    v4 = adr;
    if ( !netadr_s::CompareAdr(this: adr, a: &this->m_adrReservationGraceStarted, onlyBase: false) )
      return;
  }
  bf_write::bf_write(this: &msg, pData: buffer, nBytes: 512, nBits: -1);
  memset(context, 0, sizeof(context));
  CBitRead::ReadString(this: inmsg, pStr: context, maxLen: 256, bLine: false, pOutNumChars: nullptr);
  challengeNr = this->GetChallengeNr(this, a2: v4);
  v5 = this->GetChallengeType(this, a2: v4);
  bf_write::WriteLong(this: &msg, val: -1);
  bf_write::WriteByte(this: &msg, val: 0x41u);
  bf_write::WriteLong(this: &msg, val: challengeNr);
  bf_write::WriteLong(this: &msg, val: v5);
  if ( v5 == 3 )
  {
    v6 = Steam3Server();
    GSSteamID = CSteam3Server::GetGSSteamID(this: v6);
    m_unAll64Bits = GSSteamID->m_steamid.m_unAll64Bits;
    m_unAll64Bits_high = HIDWORD(GSSteamID->m_steamid.m_unAll64Bits);
    bf_write::WriteShort(this: &msg, val: 0);
    bf_write::WriteLongLong(this: &msg, val: __SPAIR64__(m_unAll64Bits_high, m_unAll64Bits));
    m_pSteamGameServer = Steam3Server()->m_pSteamGameServer;
    if ( m_pSteamGameServer != nullptr && m_pSteamGameServer->BSecure(this: m_pSteamGameServer) )
    {
      bf_write::WriteByte(this: &msg, val: 1u);
      v4 = adr;
    }
    else
    {
      bf_write::WriteByte(this: &msg, val: 0);
      v4 = adr;
    }
  }
  else
  {
    bf_write::WriteShort(this: &msg, val: 1);
    bf_write::WriteLongLong(this: &msg, val: 0);
    bf_write::WriteByte(this: &msg, val: 0);
  }
  v11 = _V_strlen(str: "connect");
  if ( V_strnicmp(s1: context, s2: "connect", n: v11) != 0 )
  {
    bf_write::WriteString(this: &msg, pStr: context);
  }
  else
  {
    if ( netadr_s::IsLoopback(this: v4) || (bWillRequirePassword_3 = 0, netadr_s::IsLocalhost(this: v4)) )
      bWillRequirePassword_3 = 1;
    if ( this->GetPassword(this) == nullptr
      || bWillRequirePassword_3 != 0
      || (bWillRequirePassword_3a = 1, CBaseServer::IsExclusiveToLobbyConnections(this)) )
    {
      bWillRequirePassword_3a = 0;
    }
    v12 = 0;
    v13 = &context[_V_strlen(str: "connect")];
    if ( *v13 == 48 && v13[1] == 120 )
    {
      memset(chValidateChallenge, 0, 9);
      V_strncpy(pDest: chValidateChallenge, pSrc: v13 + 2, maxLen: 9);
      v12 = strtoul(nptr: chValidateChallenge, endptr: nullptr, ibase: 16);
    }
    if ( !this->IsDedicated(this)
      || sv_allow_lobby_connect_only.m_pParent == nullptr
      || sv_allow_lobby_connect_only.m_pParent->m_Value.m_nValue == 0
      || sv_lan.m_pParent != nullptr && sv_lan.m_pParent->m_Value.m_nValue != 0
      || this->m_nReservationCookie != 0 )
    {
      bf_write::WriteString(this: &msg, pStr: context);
    }
    else if ( v12 == challengeNr )
    {
      bf_write::WriteString(this: &msg, pStr: "connect-granted");
      this->m_flTimeReservationGraceStarted = net_time;
      this->m_adrReservationGraceStarted.type = v4->type;
      *(_DWORD *)this->m_adrReservationGraceStarted.ip = *(_DWORD *)v4->ip;
      *(_DWORD *)&this->m_adrReservationGraceStarted.port = *(_DWORD *)&v4->port;
      v14 = netadr_s::ToString(this: v4, baseOnly: false);
      DevMsg(a1: "Server requires lobby reservation and is unreserved: granting reservation grace period to %s\n", v14);
    }
    else
    {
      bf_write::WriteString(this: &msg, pStr: "connect-retry");
    }
    v15 = defaultValue;
    if ( this->IsDedicated(this)
      && sv_allow_lobby_connect_only.m_pParent != nullptr
      && sv_allow_lobby_connect_only.m_pParent->m_Value.m_nValue != 0
      && (sv_lan.m_pParent == nullptr || sv_lan.m_pParent->m_Value.m_nValue == 0) )
    {
      v15 = "public";
      if ( sv_steamgroup_exclusive.m_pParent != nullptr && sv_steamgroup_exclusive.m_pParent->m_Value.m_nValue != 0 )
        v15 = "friends";
    }
    HostVersion = GetHostVersion();
    bf_write::WriteLong(this: &msg, val: HostVersion);
    bf_write::WriteString(this: &msg, pStr: v15);
    bf_write::WriteByte(this: &msg, val: bWillRequirePassword_3a != 0);
    bf_write::WriteLongLong(this: &msg, val: sv.m_nReservationCookie);
  }
  NET_SendPacket(
    chan: nullptr,
    sock: this->m_Socket,
    to: v4,
    data: msg.m_pData,
    length: (msg.m_iCurBit + 7) >> 3,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10136290
// Name: public: virtual void CBaseServer::GetNetStats(float __near &,float __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::GetNetStats(CBaseServer *this, float *avgIn, float *avgOut)
{
  CBaseClient *v4; // esi
  bool (__thiscall *IsFakeClient)(IClient *); // eax
  IClient *v6; // esi
  int v7; // esi
  double v8; // st7
  double (__thiscall *v9)(int, _DWORD); // eax
  CBaseServer *v10; // [esp+0h] [ebp-4h]
  int i; // [esp+10h] [ebp+Ch]

  *avgOut = 0.0;
  *avgIn = 0.0;
  v10 = this;
  for ( i = 0; i < v10->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    IsFakeClient = v4->IsFakeClient;
    v6 = &v4->IClient;
    if ( !IsFakeClient(this: v6) && v6->IsConnected(this: v6) )
    {
      v7 = (int)v6->GetNetChannel(this: v6);
      v8 = ((double (__thiscall *)(int, int))*(_DWORD *)(*(_DWORD *)v7 + 52))(a1: v7, a2: 1);
      v9 = *(double (__thiscall **)(int, _DWORD))(*(_DWORD *)v7 + 52);
      *avgIn = v8 + *avgIn;
      *avgOut = v9(a1: v7, a2: 0) + *avgOut;
    }
    this = v10;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136340
// Name: public: void CBaseServer::InactivateClients(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::InactivateClients(CBaseServer *this)
{
  int v1; // ebx
  CBaseClient *v2; // edi
  CSteam3Server *v3; // eax
  CBaseServer *i; // [esp+4h] [ebp-4h]

  v1 = 0;
  for ( i = this; v1 < i->m_Clients.m_Size; ++v1 )
  {
    v2 = this->m_Clients.m_Memory.m_pMemory[v1];
    if ( !v2->IsFakeClient(this: &v2->IClient)
      || v2->IsSplitScreenUser(this: &v2->IClient)
      || v2->IsHLTV(this: &v2->IClient) )
    {
      if ( v2->IsConnected(this: &v2->IClient) )
        v2->Inactivate(this: &v2->IClient);
    }
    else
    {
      v3 = Steam3Server();
      CSteam3Server::NotifyClientDisconnect(this: v3, client: v2);
      v2->Clear(this: &v2->IClient);
    }
    this = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101363E0
// Name: public: void CBaseServer::CheckTimeouts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::CheckTimeouts(CBaseServer *this)
{
  int v1; // ebx
  CBaseClient *v2; // eax
  IClient *v3; // esi
  int v4; // eax
  int v5; // edi
  IClient_vtbl *v6; // edi
  IClient_vtbl *v7; // edi
  IClient_vtbl *v8; // edi
  int v9; // [esp-Ch] [ebp-14h]
  int v10; // [esp-Ch] [ebp-14h]
  int v11; // [esp-Ch] [ebp-14h]
  CBaseServer *i; // [esp+4h] [ebp-4h]

  v1 = 0;
  for ( i = this; v1 < i->m_Clients.m_Size; ++v1 )
  {
    v2 = this->m_Clients.m_Memory.m_pMemory[v1];
    if ( v2 != nullptr )
      v3 = &v2->IClient;
    else
      v3 = nullptr;
    if ( !v3->IsFakeClient(this: v3) && v3->IsConnected(this: v3) )
    {
      v4 = (int)v3->GetNetChannel(this: v3);
      v5 = v4;
      if ( v4 != 0 )
      {
        if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v4 + 236))(a1: v4) != 0 )
        {
          v6 = v3->__vftable;
          v9 = (int)v3->GetClientName(this: v3);
          v6->Disconnect(this: v3, a2: "%s timed out", v9);
        }
        else if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 296))(a1: v5) != 0 )
        {
          v7 = v3->__vftable;
          v10 = (int)v3->GetClientName(this: v3);
          v7->Disconnect(this: v3, a2: "%s disconnected", v10);
        }
        else if ( (*(unsigned __int8 (__thiscall **)(int))(*(_DWORD *)v5 + 232))(a1: v5) != 0 )
        {
          v8 = v3->__vftable;
          v11 = (int)v3->GetClientName(this: v3);
          v8->Disconnect(this: v3, a2: "%s overflowed reliable channel", v11);
        }
      }
    }
    this = i;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101364D0
// Name: public: char const __near * CBaseServer::CompressPackedEntity(class ServerClass __near *,char const __near *,int __near &)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseServer::CompressPackedEntity(
        CBaseServer *this,
        ServerClass *pServerClass,
        const char *data,
        int *bits)
{
  SendTable *m_pTable; // ecx
  int v7; // [esp-Ch] [ebp-34h]
  bf_write writeBuf; // [esp+8h] [ebp-20h] BYREF
  const void *pBaselineData; // [esp+20h] [ebp-8h] BYREF
  int nBaselineBits; // [esp+24h] [ebp-4h] BYREF

  bf_write::bf_write(
    this: &writeBuf,
    pDebugName: "CompressPackedEntity",
    pData: s_packedData,
    nBytes: 0x4000,
    nBits: -1);
  pBaselineData = nullptr;
  nBaselineBits = 0;
  CBaseServer::GetClassBaseline(this, pClass: pServerClass, pData: &pBaselineData, pDatalen: &nBaselineBits);
  v7 = *bits;
  m_pTable = pServerClass->m_pTable;
  nBaselineBits *= 8;
  SendTable_WriteAllDeltaProps(
    pTable: m_pTable,
    pFromData: pBaselineData,
    nFromDataBits: nBaselineBits,
    pToData: data,
    nToDataBits: v7,
    nObjectID: -1,
    pBufOut: &writeBuf);
  *bits = writeBuf.m_iCurBit;
  return s_packedData;
}

//------------------------------------------------------------------------------
// Address: 0x10136650
// Name: public: virtual void CBaseServer::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::Clear(CBaseServer *this)
{
  CNetworkStringTableContainer *m_StringTables; // ecx
  bool (__thiscall *IsMultiplayer)(struct CBaseServer *); // eax
  CUtlMemory<unsigned char,int> *p_m_SignonBuffer; // edi
  unsigned __int8 *m_pMemory; // eax
  unsigned __int8 *v6; // eax

  m_StringTables = this->m_StringTables;
  if ( m_StringTables != nullptr )
  {
    m_StringTables->RemoveAllTables(this: m_StringTables);
    this->m_StringTables = nullptr;
  }
  this->m_pInstanceBaselineTable = nullptr;
  this->m_pLightStyleTable = nullptr;
  this->m_pUserInfoTable = nullptr;
  this->m_pServerStartupTable = nullptr;
  this->m_State = ss_dead;
  this->m_nTickCount = 0;
  _V_memset(dest: this->m_szMapname, fill: 0, count: 64);
  _V_memset(dest: this->m_szSkyname, fill: 0, count: 64);
  IsMultiplayer = this->IsMultiplayer;
  this->clientDllCRC = 0;
  this->worldmapCRC = 0;
  this->stringTableCRC = 0;
  if ( IsMultiplayer(this) || this->IsDedicated(this) )
  {
    p_m_SignonBuffer = &this->m_SignonBuffer;
    if ( this->m_SignonBuffer.m_nAllocationCount < 96000 && this->m_SignonBuffer.m_nGrowSize >= 0 )
    {
      m_pMemory = p_m_SignonBuffer->m_pMemory;
      this->m_SignonBuffer.m_nAllocationCount = 96000;
      if ( m_pMemory != nullptr )
        v6 = (unsigned __int8 *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 96000);
      else
        v6 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 96000);
      p_m_SignonBuffer->m_pMemory = v6;
    }
  }
  else
  {
    p_m_SignonBuffer = &this->m_SignonBuffer;
    CUtlMemory<unsigned char,int>::EnsureCapacity(this: &this->m_SignonBuffer, num: 0x4000);
  }
  bf_write::StartWriting(
    this: &this->m_Signon,
    pData: p_m_SignonBuffer->m_pMemory,
    nBytes: this->m_SignonBuffer.m_nAllocationCount,
    iStartBit: 0,
    nBits: -1);
  CNetworkStringTable::SetTick(this: &this->m_Signon, pDebugName: "m_Signon");
  this->serverclasses = 0;
  this->serverclassbits = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10136760
// Name: public: virtual void CBaseServer::SendClientMessages(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::SendClientMessages(CBaseServer *this, bool bSendSnapshots)
{
  int i; // edi
  CBaseClient *v4; // esi

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "SendClientMessages",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->ShouldSendMessages(this: v4) )
    {
      if ( v4->m_NetChannel != nullptr )
      {
        v4->m_NetChannel->Transmit(this: v4->m_NetChannel, a2: false);
        v4->UpdateSendState(this: v4);
      }
      else
      {
        _Msg(a1: "Client has no netchannel.\n");
      }
    }
  }
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x10136800
// Name: public: virtual void CBaseServer::BroadcastMessage(class INetMessage __near &,bool,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::BroadcastMessage(CBaseServer *this, INetMessage *msg, bool onlyActive, BOOL reliable)
{
  int i; // edi
  CBaseClient *v6; // esi
  bool (__thiscall *IsSpawned)(IClient *); // eax
  IClient *v8; // esi
  const char *v9; // eax

  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v6 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( !onlyActive || v6->IsActive(this: &v6->IClient) )
    {
      IsSpawned = v6->IsSpawned;
      v8 = &v6->IClient;
      if ( IsSpawned(this: v8)
        && !v8->SendNetMsg(this: v8, a2: msg, a3: reliable, a4: false)
        && (msg->IsReliable(this: msg) || reliable) )
      {
        v9 = v8->GetClientName(this: v8);
        DevMsg(a1: "BroadcastMessage: Reliable broadcast message overflow for client %s", v9);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101368B0
// Name: public: virtual void CBaseServer::BroadcastMessage(class INetMessage __near &,class IRecipientFilter __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::BroadcastMessage(CBaseServer *this, INetMessage *msg, IRecipientFilter *filter)
{
  IRecipientFilter *v3; // ebx
  INetMessage_vtbl *v6; // edi
  bool v7; // al
  int v8; // edi
  CBaseClient *v9; // edi
  bool (__thiscall *IsSpawned)(IClient *); // eax
  IClient *v11; // edi
  const char *v12; // eax
  bool v13; // al
  const char *v14; // ebx
  bool v15; // zf
  const char *v16; // eax
  int v17; // eax
  int v18; // eax
  const char *v19; // [esp-14h] [ebp-24h]
  const char *v20; // [esp-10h] [ebp-20h]
  int v21; // [esp-Ch] [ebp-1Ch]
  int v22; // [esp-8h] [ebp-18h]
  int num; // [esp+Ch] [ebp-4h]
  int i; // [esp+18h] [ebp+8h]

  v3 = filter;
  if ( filter->IsInitMessage(this: filter) )
  {
    if ( this->IsActive(this) )
      _ConDMsg(a1: "SV_BroadcastMessage: Init message being created after signon buffer has been transmitted\n");
    if ( !msg->WriteToBuffer(this: msg, a2: &this->m_Signon) )
      Sys_Error(error: "SV_BroadcastMessage: Init message would overflow signon buffer!\n");
  }
  else
  {
    v6 = msg->__vftable;
    v7 = filter->IsReliable(this: filter);
    v6->SetReliable(this: msg, a2: v7);
    num = filter->GetRecipientCount(this: filter);
    for ( i = 0; i < num; ++i )
    {
      v8 = v3->GetRecipientIndex(this: v3, a2: i);
      if ( v8 < 1 || v8 > this->m_Clients.m_Size )
      {
        v13 = v3->IsInitMessage(this: v3);
        v14 = "yes";
        if ( !v13 )
          v14 = "no";
        v15 = !filter->IsReliable(this: filter);
        v16 = "yes";
        if ( v15 )
          v16 = "no";
        v17 = ((int (__thiscall *)(INetMessage *, const char *, const char *, int, int))msg->GetType)(
                a1: msg,
                a2: v16,
                a3: v14,
                a4: v8,
                a5: num);
        _Msg(
          a1: "SV_BroadcastMessage:  Recipient Filter for message type %i (reliable: %s, init: %s) with bogus client index (%"
          "i) in list of %i clients\n",
          v17,
          v19,
          v20,
          v21,
          v22);
        if ( msg->IsReliable(this: msg) )
        {
          v18 = msg->GetType(this: msg);
          Host_Error(error: "Reliable message (type %i) discarded.", v18);
        }
        v3 = filter;
      }
      else
      {
        v9 = this->m_Clients.m_Memory.m_pMemory[v8 - 1];
        IsSpawned = v9->IsSpawned;
        v11 = &v9->IClient;
        if ( IsSpawned(this: v11)
          && !v11->SendNetMsg(this: v11, a2: msg, a3: false, a4: false)
          && msg->IsReliable(this: msg) )
        {
          v12 = v11->GetClientName(this: v11);
          DevMsg(a1: "BroadcastMessage: Reliable filter message overflow for client %s", v12);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136A60
// Name: public: void CBaseServer::RemoveTag(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::RemoveTag(CBaseServer *this, const char *pszTag, bool bSubTag)
{
  char *v3; // eax
  char *m_pszString; // eax
  int v5; // esi
  char v6; // bl
  int v7; // eax
  char tmptags[128]; // [esp+0h] [ebp-98h] BYREF
  CSplitString TagList; // [esp+80h] [ebp-18h] BYREF

  if ( (sv_tags.m_nFlags & 0x1000) != 0 || (v3 = sv_tags.m_pParent->m_Value.m_pszString) != nullptr && *v3 != 0 )
  {
    tmptags[0] = 0;
    if ( (sv_tags.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = sv_tags.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)defaultValue;
    }
    CSplitString::CSplitString(this: &TagList, pString: m_pszString, pSeparator: ",");
    v5 = 0;
    v6 = 0;
    if ( TagList.m_Size > 0 )
    {
      do
      {
        if ( bSubTag )
          v7 = V_strnicmp(s1: TagList.m_Memory.m_pMemory[v5], s2: pszTag, n: strlen(pszTag));
        else
          v7 = _V_stricmp(s1: TagList.m_Memory.m_pMemory[v5], s2: pszTag);
        if ( v7 != 0 )
        {
          V_strncat(pDest: tmptags, pSrc: TagList.m_Memory.m_pMemory[v5], destBufferSize: 0x80u, max_chars_to_copy: -1);
          V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
        }
        else
        {
          v6 = 1;
        }
        ++v5;
      }
      while ( v5 < TagList.m_Size );
      if ( v6 != 0 )
        CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&sv_tags.IConVar, value: tmptags);
    }
    CSplitString::~CSplitString(this: &TagList);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10136B80
// Name: public: bool CBaseServer::IsPlayingSoloAgainstBots(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::IsPlayingSoloAgainstBots(CBaseServer *this)
{
  int NumFakeClients; // esi
  int v2; // eax

  if ( sv.m_State < ss_active
    || sv.m_nMaxclients <= 1
    || (NumFakeClients = CBaseServer::GetNumFakeClients(this: &sv),
        (v2 = CBaseServer::GetNumClients(this: &sv) - NumFakeClients) != 1) )
  {
    LOBYTE(v2) = 0;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10136BC0
// Name: public: int CBaseServer::GetNumHumanPlayers(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseServer::GetNumHumanPlayers(CBaseServer *this)
{
  int v2; // ebx
  int i; // esi
  CBaseClient *v4; // ecx

  v2 = 0;
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->IsHumanPlayer(this: &v4->IClient) )
      ++v2;
  }
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x10136C00
// Name: public: void CBaseServer::GetMasterServerPlayerCounts(int __near &,int __near &,int __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::GetMasterServerPlayerCounts(
        CBaseServer *this,
        int *nHumans,
        int *nMaxHumanSlots,
        int *nBots)
{
  int v5; // eax
  int m_nValue; // eax

  *nHumans = CBaseServer::GetNumHumanPlayers(this);
  if ( serverGameClients == nullptr || (v5 = serverGameClients->GetMaxHumanPlayers(this: serverGameClients)) == -1 )
    v5 = this->GetMaxClients(this);
  *nMaxHumanSlots = v5;
  *nBots = CBaseServer::GetNumFakeClients(this: &sv);
  if ( sv_visiblemaxplayers.m_pParent != nullptr )
  {
    m_nValue = sv_visiblemaxplayers.m_pParent->m_Value.m_nValue;
    if ( m_nValue > 0 )
      *nMaxHumanSlots = m_nValue;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101371C0
// Name: protected: virtual bool CBaseServer::CheckChallengeNr(struct netadr_s __near &,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::CheckChallengeNr(CBaseServer *this, netadr_s *adr, int nChallengeValue)
{
  int v5; // esi
  int v6; // edi
  bool v7; // zf
  challenge_t *m_pMemory; // eax
  const char *v9; // eax
  challenge_t *v10; // eax
  const char *v11; // eax

  if ( netadr_s::IsLoopback(this: adr) || this->m_bIsDedicatedForXbox )
    return 1;
  v5 = 0;
  if ( this->m_ServerQueryChallenges.m_Size <= 0 )
  {
LABEL_10:
    if ( nChallengeValue != -1 )
    {
      v9 = netadr_s::ToString(this: adr, baseOnly: false);
      _ConDMsg(a1: "No challenge from %s.\n", v9);
    }
    return 0;
  }
  v6 = 0;
  while ( 1 )
  {
    v7 = !netadr_s::CompareAdr(this: adr, a: &this->m_ServerQueryChallenges.m_Memory.m_pMemory[v6].adr, onlyBase: true);
    m_pMemory = this->m_ServerQueryChallenges.m_Memory.m_pMemory;
    if ( !v7 )
      break;
    if ( net_time > m_pMemory[v6].time + 3600.0 )
    {
      CUtlVector<challenge_t,CUtlMemory<challenge_t,int>>::FastRemove(this: &this->m_ServerQueryChallenges, elem: v5--);
      --v6;
    }
    ++v5;
    ++v6;
    if ( v5 >= this->m_ServerQueryChallenges.m_Size )
      goto LABEL_10;
  }
  v7 = nChallengeValue == m_pMemory[v5].challenge;
  v10 = &m_pMemory[v5];
  if ( !v7 )
    return 0;
  if ( net_time <= v10->time + 3600.0 )
    return 1;
  CUtlVector<challenge_t,CUtlMemory<challenge_t,int>>::FastRemove(this: &this->m_ServerQueryChallenges, elem: v5);
  v11 = netadr_s::ToString(this: adr, baseOnly: false);
  ConMsg(a1: "Old challenge from %s.\n", v11);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101372D0
// Name: protected: void CBaseServer::UpdateMasterServerBasicData(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::UpdateMasterServerBasicData(CBaseServer *this)
{
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // edi
  int v3; // eax
  char *m_pszString; // ebx
  ISteamMasterServerUpdater_vtbl *v5; // edi
  const char *v6; // eax
  const char *ProductString; // eax
  int HostVersion; // eax
  BOOL v9; // [esp-4h] [ebp-18h]
  int v10; // [esp-4h] [ebp-18h]
  ISteamMasterServerUpdater *pUpdater; // [esp+Ch] [ebp-8h]
  int nMaxHumans; // [esp+10h] [ebp-4h]

  m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
  pUpdater = m_pSteamMasterServerUpdater;
  CBaseServer::GetNumHumanPlayers(this);
  if ( serverGameClients == nullptr || (v3 = serverGameClients->GetMaxHumanPlayers(this: serverGameClients)) == -1 )
    v3 = this->GetMaxClients(this);
  nMaxHumans = v3;
  CBaseServer::GetNumFakeClients(this: &sv);
  if ( sv_visiblemaxplayers.m_pParent != nullptr && sv_visiblemaxplayers.m_pParent->m_Value.m_nValue > 0 )
    nMaxHumans = sv_visiblemaxplayers.m_pParent->m_Value.m_nValue;
  if ( (sv_region.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = sv_region.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  v5 = m_pSteamMasterServerUpdater->__vftable;
  v6 = serverGameDLL->GetGameDescription(this: serverGameDLL);
  v9 = ((int (__thiscall *)(CBaseServer *, const char *))this->GetPassword)(a1: this, a2: v6) != 0;
  ProductString = Sys_GetProductString();
  v10 = ((unsigned __int8 (__thiscall *)(CBaseServer *, char *, const char *, int, BOOL))this->IsDedicated)(
          a1: this,
          a2: m_pszString,
          a3: ProductString,
          a4: nMaxHumans,
          a5: v9);
  HostVersion = GetHostVersion();
  ((void (__thiscall *)(ISteamMasterServerUpdater *, int, int))v5->SetBasicServerData)(
    a1: pUpdater,
    a2: HostVersion,
    a3: v10);
}

//------------------------------------------------------------------------------
// Address: 0x101373A0
// Name: public: void CBaseServer::AddTag(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::AddTag(CBaseServer *this, const char *pszTag, const char *pszSubTagValue)
{
  char *m_pszString; // eax
  int i; // edi
  char *v5; // eax
  char tmptags[128]; // [esp+0h] [ebp-9Ch] BYREF
  CSplitString TagList; // [esp+80h] [ebp-1Ch] BYREF
  CBaseServer *v8; // [esp+98h] [ebp-4h]

  v8 = this;
  if ( (sv_tags.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = sv_tags.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  CSplitString::CSplitString(this: &TagList, pString: m_pszString, pSeparator: ",");
  for ( i = 0; i < TagList.m_Size; ++i )
  {
    if ( pszSubTagValue != nullptr )
    {
      if ( V_strnicmp(s1: TagList.m_Memory.m_pMemory[i], s2: pszTag, n: strlen(pszTag)) == 0 )
      {
        if ( _V_stricmp(s1: &TagList.m_Memory.m_pMemory[i][strlen(pszTag)], s2: pszSubTagValue) == 0 )
          goto LABEL_19;
        CBaseServer::RemoveTag(this: v8, pszTag, bSubTag: true);
      }
    }
    else if ( _V_stricmp(s1: TagList.m_Memory.m_pMemory[i], s2: pszTag) == 0 )
    {
      goto LABEL_19;
    }
  }
  tmptags[0] = 0;
  V_strncpy(pDest: tmptags, pSrc: pszTag, maxLen: 128);
  if ( pszSubTagValue != nullptr )
    V_strncat(pDest: tmptags, pSrc: pszSubTagValue, destBufferSize: 0x80u, max_chars_to_copy: -1);
  V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
  if ( (sv_tags.m_nFlags & 0x1000) != 0 )
  {
    v5 = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    v5 = sv_tags.m_pParent->m_Value.m_pszString;
    if ( v5 == nullptr )
      v5 = (char *)defaultValue;
  }
  V_strncat(pDest: tmptags, pSrc: v5, destBufferSize: 0x80u, max_chars_to_copy: -1);
  CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&sv_tags.IConVar, value: tmptags);
LABEL_19:
  CSplitString::~CSplitString(this: &TagList);
}

//------------------------------------------------------------------------------
// Address: 0x10137F30
// Name: public: CReferencedSnapshotList::~CReferencedSnapshotList(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CReferencedSnapshotList::~CReferencedSnapshotList(CReferencedSnapshotList *this)
{
  int i; // edi
  bool v3; // sf
  CFrameSnapshot **m_pMemory; // eax

  for ( i = 0; i < this->m_vecSnapshots.m_Size; ++i )
    CFrameSnapshot::ReleaseReference(this: this->m_vecSnapshots.m_Memory.m_pMemory[i]);
  v3 = this->m_vecSnapshots.m_Memory.m_nGrowSize < 0;
  this->m_vecSnapshots.m_Size = 0;
  if ( !v3 )
  {
    if ( this->m_vecSnapshots.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_vecSnapshots.m_Memory.m_pMemory);
      this->m_vecSnapshots.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecSnapshots.m_Memory.m_nAllocationCount = 0;
  }
  v3 = this->m_vecSnapshots.m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_vecSnapshots.m_Memory.m_pMemory;
  this->m_vecSnapshots.m_pElements = this->m_vecSnapshots.m_Memory.m_pMemory;
  if ( !v3 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_vecSnapshots.m_Memory.m_pMemory = nullptr;
    }
    this->m_vecSnapshots.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10137FB0
// Name: ServerTagsCleanUp
// Source: json
//------------------------------------------------------------------------------
void ServerTagsCleanUp()
{
  int i; // esi
  char *v1; // eax
  char v2; // cl
  int v3; // esi
  char **m_pMemory; // eax
  char tmptags[128]; // [esp+4h] [ebp-9Ch] BYREF
  ConVarRef sv_tags; // [esp+84h] [ebp-1Ch] BYREF
  CUtlVector<char *,CUtlMemory<char *,int> > TagList; // [esp+8Ch] [ebp-14h] BYREF

  if ( s_nNoReentry == 0 )
  {
    s_nNoReentry = 1;
    memset(&TagList, 0, sizeof(TagList));
    ConVarRef::ConVarRef(this: &sv_tags, pName: "sv_tags");
    if ( ConVarRef::IsValid(this: &sv_tags) )
    {
      tmptags[0] = 0;
      V_SplitString(pString: sv_tags.m_pConVarState->m_Value.m_pszString, pSeparator: ",", outStrings: &TagList);
      for ( i = 0; i < TagList.m_Size; ++i )
      {
        if ( i > 0 )
          V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
        v1 = TagList.m_Memory.m_pMemory[i];
        v2 = *v1;
        if ( *v1 != 0 )
        {
          while ( v2 == 32 )
          {
            v2 = *++v1;
            if ( v2 == 0 )
              goto LABEL_12;
          }
          if ( *v1 != 0 )
            V_strncat(pDest: tmptags, pSrc: v1, destBufferSize: 0x80u, max_chars_to_copy: -1);
        }
LABEL_12:
        ;
      }
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &TagList);
      V_SplitString(pString: tmptags, pSeparator: ",", outStrings: &TagList);
      CUtlVector<char *,CUtlMemory<char *,int>>::Sort(
        this: (CUtlVector<int,CUtlMemory<int,int> > *)&TagList,
        pfnCompare: (int (__cdecl *)(const void *, const void *))SortServerTags);
      v3 = 0;
      for ( tmptags[0] = 0; v3 < TagList.m_Size; ++v3 )
      {
        if ( v3 > 0 )
          V_strncat(pDest: tmptags, pSrc: ",", destBufferSize: 0x80u, max_chars_to_copy: -1);
        V_strncat(pDest: tmptags, pSrc: TagList.m_Memory.m_pMemory[v3], destBufferSize: 0x80u, max_chars_to_copy: -1);
      }
      if ( _V_strcmp(s1: tmptags, s2: sv_tags.m_pConVarState->m_Value.m_pszString) != 0 )
        sv_tags.m_pConVar->SetValue_4(this: sv_tags.m_pConVar, a2: tmptags);
      CUtlVector<char *,CUtlMemory<char *,int>>::PurgeAndDeleteElements(this: &TagList);
    }
    m_pMemory = TagList.m_Memory.m_pMemory;
    TagList.m_Size = 0;
    if ( TagList.m_Memory.m_nGrowSize >= 0 )
    {
      if ( TagList.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: TagList.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        TagList.m_Memory.m_pMemory = nullptr;
      }
      TagList.m_Memory.m_nAllocationCount = 0;
    }
    TagList.m_pElements = m_pMemory;
    if ( TagList.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
    --s_nNoReentry;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138190
// Name: public: void CBaseServer::RecalculateTags(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::RecalculateTags(CBaseServer *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // esi
  KeyValues *FirstSubKey; // edi
  ICvar_vtbl *v5; // esi
  const char *String; // eax
  ConVar *v7; // eax
  ConVar *v8; // esi
  const char *Default; // eax
  const char *m_pszString; // ecx
  const char *v11; // eax
  const char *v12; // eax
  char *v13; // esi
  char *v14; // eax
  char chGroupNameBuf[64]; // [esp+4h] [ebp-58h] BYREF
  int nHumans; // [esp+44h] [ebp-18h] BYREF
  int nBots; // [esp+48h] [ebp-14h] BYREF
  int minmaxplayers; // [esp+4Ch] [ebp-10h] BYREF
  int defaultmaxplayers; // [esp+50h] [ebp-Ch] BYREF
  int maxmaxplayers; // [esp+54h] [ebp-8h] BYREF
  KeyValues *pKV; // [esp+58h] [ebp-4h] BYREF

  if ( !this->IsHLTV(this) && !this->IsReplay(this) && !bRecalculatingTags )
  {
    bRecalculatingTags = true;
    if ( serverGameTags != nullptr )
    {
      v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v2 != nullptr )
      {
        v3 = KeyValues::KeyValues(this: v2, setName: "GameTags");
        pKV = v3;
      }
      else
      {
        pKV = nullptr;
        v3 = nullptr;
      }
      serverGameTags->GetTaggedConVarList(this: serverGameTags, a2: v3);
      FirstSubKey = KeyValues::GetFirstSubKey(this: v3);
      if ( FirstSubKey != nullptr )
      {
        do
        {
          v5 = g_pCVar->__vftable;
          String = KeyValues::GetString(this: FirstSubKey, keyName: "convar", defaultValue: defaultValue);
          v7 = v5->FindVar_2(this: g_pCVar, a2: String);
          v8 = v7;
          if ( v7 != nullptr )
          {
            Default = ConVar::GetDefault(this: v7);
            if ( (v8->m_nFlags & 0x1000) != 0 )
            {
              m_pszString = "FCVAR_NEVER_AS_STRING";
            }
            else
            {
              m_pszString = v8->m_pParent->m_Value.m_pszString;
              if ( m_pszString == nullptr )
                m_pszString = defaultValue;
            }
            if ( _V_strcmp(s1: Default, s2: m_pszString) != 0 )
            {
              v11 = KeyValues::GetString(this: FirstSubKey, keyName: "tag", defaultValue: defaultValue);
              CBaseServer::AddTag(this, pszTag: v11, pszSubTagValue: nullptr);
            }
            else
            {
              v12 = KeyValues::GetString(this: FirstSubKey, keyName: "tag", defaultValue: defaultValue);
              CBaseServer::RemoveTag(this, pszTag: v12, bSubTag: false);
            }
          }
          FirstSubKey = KeyValues::GetNextKey(this: FirstSubKey);
        }
        while ( FirstSubKey != nullptr );
        v3 = pKV;
      }
      KeyValues::deleteThis(this: v3);
    }
    minmaxplayers = 1;
    maxmaxplayers = 64;
    defaultmaxplayers = 1;
    serverGameClients->GetPlayerLimits(
      this: serverGameClients,
      a2: &minmaxplayers,
      a3: &maxmaxplayers,
      a4: &defaultmaxplayers);
    CBaseServer::GetMasterServerPlayerCounts(this, &nHumans, nMaxHumanSlots: (int *)&pKV, &nBots);
    if ( (int)pKV <= maxmaxplayers )
      CBaseServer::RemoveTag(this, pszTag: "increased_maxplayers", bSubTag: false);
    else
      CBaseServer::AddTag(this, pszTag: "increased_maxplayers", pszSubTagValue: nullptr);
    if ( g_bLowViolence )
      CBaseServer::AddTag(this, pszTag: "low_violence", pszSubTagValue: nullptr);
    else
      CBaseServer::RemoveTag(this, pszTag: "low_violence", bSubTag: false);
    if ( (sv_steamgroup.m_nFlags & 0x1000) != 0 )
    {
      v13 = "FCVAR_NEVER_AS_STRING";
LABEL_30:
      memset(chGroupNameBuf, 0, sizeof(chGroupNameBuf));
      V_snprintf(pDest: chGroupNameBuf, maxLen: 62, pFormat: "%si", v13);
      CBaseServer::AddTag(this, pszTag: "*grp:", pszSubTagValue: chGroupNameBuf);
      bRecalculatingTags = false;
      return;
    }
    v14 = sv_steamgroup.m_pParent->m_Value.m_pszString;
    if ( v14 != nullptr )
    {
      v13 = sv_steamgroup.m_pParent->m_Value.m_pszString;
      if ( *v14 != 0 )
        goto LABEL_30;
    }
    CBaseServer::RemoveTag(this, pszTag: "*grp:", bSubTag: true);
    bRecalculatingTags = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101383D0
// Name: public: void CBaseServer::ProcessSplitScreenDisconnects(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ProcessSplitScreenDisconnects(CBaseServer *this)
{
  CBaseServer *v1; // edi
  int v2; // edx
  int max_splitscreen_players; // eax
  CBaseServer::SplitDisconnect_t *v4; // esi
  int v5; // ebx
  CBaseClient **m_SplitScreenUsers; // edi
  CBaseServer::SplitDisconnect_t *m_pMemory; // ecx
  int i; // [esp+Ch] [ebp-4h]

  v1 = this;
  v2 = 0;
  i = 0;
  if ( this->m_QueuedForDisconnect.m_Size > 0 )
  {
    max_splitscreen_players = host_state.max_splitscreen_players;
    do
    {
      v4 = &v1->m_QueuedForDisconnect.m_Memory.m_pMemory[v2];
      v5 = 0;
      if ( max_splitscreen_players > 0 )
      {
        m_SplitScreenUsers = v4->m_pUser->m_SplitScreenUsers;
        do
        {
          if ( *m_SplitScreenUsers == v4->m_pSplit )
          {
            *m_SplitScreenUsers = nullptr;
            v4->m_pSplit->m_bSplitAllowFastDisconnect = true;
            v4->m_pSplit->Disconnect(this: &v4->m_pSplit->IClient, a2: "leaving splitscreen");
            v4->m_pSplit->m_bSplitScreenUser = false;
            max_splitscreen_players = host_state.max_splitscreen_players;
          }
          ++v5;
          ++m_SplitScreenUsers;
        }
        while ( v5 < max_splitscreen_players );
        v1 = this;
        v2 = i;
      }
      i = ++v2;
    }
    while ( v2 < v1->m_QueuedForDisconnect.m_Size );
  }
  v1->m_QueuedForDisconnect.m_Size = 0;
  if ( v1->m_QueuedForDisconnect.m_Memory.m_nGrowSize < 0 )
  {
    v1->m_QueuedForDisconnect.m_pElements = v1->m_QueuedForDisconnect.m_Memory.m_pMemory;
  }
  else
  {
    if ( v1->m_QueuedForDisconnect.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v1->m_QueuedForDisconnect.m_Memory.m_pMemory);
      v1->m_QueuedForDisconnect.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = v1->m_QueuedForDisconnect.m_Memory.m_pMemory;
    v1->m_QueuedForDisconnect.m_Memory.m_nAllocationCount = 0;
    v1->m_QueuedForDisconnect.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101384C0
// Name: SetMasterServerKeyValue
// Source: json
//------------------------------------------------------------------------------
void __usercall SetMasterServerKeyValue(ISteamMasterServerUpdater *pUpdater@<esi>, IConVar *pConVar@<eax>)
{
  const char *v2; // eax
  CSteam3Server *v3; // eax
  ConVarRef var; // [esp+4h] [ebp-Ch] BYREF

  ConVarRef::ConVarRef(this: &var, pConVar);
  if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 32) && strlen(var.m_pConVarState->m_Value.m_pszString) != 0 )
    _V_stricmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: "none");
  v2 = var.m_pConVar->GetName(this: var.m_pConVar);
  ((void (__thiscall *)(ISteamMasterServerUpdater *, const char *))pUpdater->SetKeyValue)(a1: pUpdater, a2: v2);
  v3 = Steam3Server();
  if ( v3->m_pSteamGameServer != nullptr && v3->m_eServerMode >= eServerModeNoAuthentication )
    CBaseServer::RecalculateTags(this: &sv);
}

//------------------------------------------------------------------------------
// Address: 0x10138570
// Name: ServerNotifyVarChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl ServerNotifyVarChangeCallback(IConVar *pConVar)
{
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // esi

  if ( pConVar->IsFlagSet(this: pConVar, a2: 256) )
  {
    m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
    if ( m_pSteamMasterServerUpdater != nullptr )
      SetMasterServerKeyValue(pUpdater: m_pSteamMasterServerUpdater, pConVar);
    else
      sv.m_bMasterServerRulesDirty = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101385B0
// Name: public: CBaseServer::CBaseServer(void)
// Source: json
//------------------------------------------------------------------------------
CBaseServer *__thiscall CBaseServer::CBaseServer(CBaseServer *this)
{
  challenge_t *v2; // eax

  this->__vftable = (CBaseServer_vtbl *)&CBaseServer::`vftable';
  bf_write::bf_write(this: &this->m_Signon);
  this->m_SignonBuffer.m_pMemory = nullptr;
  this->m_SignonBuffer.m_nAllocationCount = 0;
  this->m_SignonBuffer.m_nGrowSize = 0;
  this->m_Clients.m_Memory.m_pMemory = nullptr;
  this->m_Clients.m_Memory.m_nAllocationCount = 0;
  this->m_Clients.m_Memory.m_nGrowSize = 0;
  this->m_Clients.m_Size = 0;
  this->m_Clients.m_pElements = nullptr;
  this->m_ServerQueryChallenges.m_Memory.m_pMemory = nullptr;
  this->m_ServerQueryChallenges.m_Memory.m_nAllocationCount = 1024;
  this->m_ServerQueryChallenges.m_Memory.m_nGrowSize = 0;
  v2 = (challenge_t *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 20480);
  this->m_ServerQueryChallenges.m_Memory.m_pMemory = v2;
  this->m_ServerQueryChallenges.m_Size = 0;
  this->m_ServerQueryChallenges.m_pElements = v2;
  this->m_QueuedForDisconnect.m_Memory.m_pMemory = nullptr;
  this->m_QueuedForDisconnect.m_Memory.m_nAllocationCount = 0;
  this->m_QueuedForDisconnect.m_Memory.m_nGrowSize = 0;
  this->m_QueuedForDisconnect.m_Size = 0;
  this->m_QueuedForDisconnect.m_pElements = nullptr;
  CUtlString::CUtlString(this: &this->m_GameTypePublic);
  CUtlString::CUtlString(this: &this->m_GameTypePrivate);
  netadr_s::SetIP(this: &this->m_adrReservationGraceStarted, unIP: 0);
  netadr_s::SetPort(this: &this->m_adrReservationGraceStarted, newport: 0);
  netadr_s::SetType(this: &this->m_adrReservationGraceStarted, newtype: NA_IP);
  *(_WORD *)&this->m_ReservationStatus.m_bActive = 0;
  netadr_s::SetIP(this: &this->m_ReservationStatus.m_Remote, unIP: 0);
  netadr_s::SetPort(this: &this->m_ReservationStatus.m_Remote, newport: 0);
  netadr_s::SetType(this: &this->m_ReservationStatus.m_Remote, newtype: NA_IP);
  this->m_flTickInterval = 0.029999999;
  this->m_StringTables = nullptr;
  this->m_pInstanceBaselineTable = nullptr;
  this->m_pLightStyleTable = nullptr;
  this->m_pUserInfoTable = nullptr;
  this->m_pServerStartupTable = nullptr;
  this->m_pDownloadableFileTable = nullptr;
  this->m_Socket = 1;
  this->m_nTickCount = 0;
  this->m_szMapname[0] = 0;
  this->m_szSkyname[0] = 0;
  this->m_Password[0] = 0;
  this->worldmapCRC = 0;
  this->clientDllCRC = 0;
  this->stringTableCRC = 0;
  this->serverclassbits = 0;
  this->serverclasses = 0;
  this->m_nSpawnCount = 0;
  this->m_nMaxclients = 0;
  this->m_flTimescale = 1.0;
  this->m_nUserid = 0;
  *(_WORD *)&this->m_bIsDedicated = 0;
  this->m_fCPUPercent = 0.0;
  this->m_flLastMasterServerUpdateTime = 0.0;
  this->m_fStartTime = 0.0;
  this->m_fLastCPUCheckTime = 0.0;
  this->m_nReservationCookie = 0;
  this->m_numGameSlots = 0;
  *(_WORD *)&this->m_bRestartOnLevelChange = 256;
  this->m_flReservationExpiryTime = -1.0;
  this->m_flTimeLastClientLeft = -1.0;
  this->m_flTimeReservationGraceStarted = -1.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101387C0
// Name: public: virtual CBaseServer::~CBaseServer(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::~CBaseServer(CBaseServer *this)
{
  this->__vftable = (CBaseServer_vtbl *)&CBaseServer::`vftable';
  this->m_GameTypePrivate.m_Storage.m_nActualLength = 0;
  if ( this->m_GameTypePrivate.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_GameTypePrivate.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_GameTypePrivate.m_Storage.m_Memory.m_pMemory);
      this->m_GameTypePrivate.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_GameTypePrivate.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_GameTypePublic.m_Storage.m_nActualLength = 0;
  if ( this->m_GameTypePublic.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_GameTypePublic.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_GameTypePublic.m_Storage.m_Memory.m_pMemory);
      this->m_GameTypePublic.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_GameTypePublic.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_QueuedForDisconnect);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_ServerQueryChallenges);
  CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>::~CUtlVector<LightmapUpdateInfo_t,CUtlMemory<LightmapUpdateInfo_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&this->m_Clients);
  if ( this->m_SignonBuffer.m_nGrowSize >= 0 )
  {
    if ( this->m_SignonBuffer.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_SignonBuffer.m_pMemory);
      this->m_SignonBuffer.m_pMemory = nullptr;
    }
    this->m_SignonBuffer.m_nAllocationCount = 0;
  }
  this->__vftable = (CBaseServer_vtbl *)&IConnectionlessPacketHandler::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10138890
// Name: protected: virtual int CBaseServer::GetChallengeNr(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __thiscall CBaseServer::GetChallengeNr(CBaseServer *this, netadr_s *adr)
{
  int v2; // edx
  int v4; // edi
  int v5; // ebx
  int m_Size; // eax
  challenge_t *m_pMemory; // ecx
  challenge_t *v8; // eax
  challenge_t *v9; // ecx
  int v10; // eax
  challenge_t *v11; // ebx
  int v12; // edi
  IUniformRandomStream *v13; // ecx
  IUniformRandomStream *v14; // ecx
  int oldest; // [esp+0h] [ebp-8h]
  int oldesta; // [esp+0h] [ebp-8h]
  float oldestTime; // [esp+4h] [ebp-4h]

  v2 = 0;
  v4 = 0;
  oldest = 0;
  oldestTime = 3.4028235e38;
  if ( this->m_ServerQueryChallenges.m_Size <= 0 )
  {
LABEL_8:
    if ( this->m_ServerQueryChallenges.m_Size > 0x4000 )
    {
      m_Size = this->m_ServerQueryChallenges.m_Size;
      if ( m_Size > 0 )
      {
        if ( v2 != m_Size - 1 )
        {
          m_pMemory = this->m_ServerQueryChallenges.m_Memory.m_pMemory;
          v8 = &m_pMemory[m_Size - 1];
          v9 = &m_pMemory[v2];
          v9->adr.type = v8->adr.type;
          *(_DWORD *)v9->adr.ip = *(_DWORD *)v8->adr.ip;
          *(_DWORD *)&v9->adr.port = *(_DWORD *)&v8->adr.port;
          v9->challenge = v8->challenge;
          v9->time = v8->time;
        }
        --this->m_ServerQueryChallenges.m_Size;
      }
    }
    v10 = CUtlVector<challenge_t,CUtlMemory<challenge_t,int>>::InsertBefore(
            this: &this->m_ServerQueryChallenges,
            elem: this->m_ServerQueryChallenges.m_Size);
    v11 = this->m_ServerQueryChallenges.m_Memory.m_pMemory;
    v12 = v10;
    oldesta = _RandomInt(this: v13, a2: 0, a3: 4095) << 16;
    v11[v12].challenge = oldesta | _RandomInt(this: v14, a2: 0, a3: 0xFFFF);
    this->m_ServerQueryChallenges.m_Memory.m_pMemory[v12].adr = *adr;
    this->m_ServerQueryChallenges.m_Memory.m_pMemory[v12].time = net_time;
    return this->m_ServerQueryChallenges.m_Memory.m_pMemory[v12].challenge;
  }
  else
  {
    v5 = 0;
    while ( !netadr_s::CompareAdr(
               this: adr,
               a: &this->m_ServerQueryChallenges.m_Memory.m_pMemory[v5].adr,
               onlyBase: true) )
    {
      if ( oldestTime > this->m_ServerQueryChallenges.m_Memory.m_pMemory[v5].time )
      {
        oldestTime = this->m_ServerQueryChallenges.m_Memory.m_pMemory[v5].time;
        oldest = v4;
      }
      ++v4;
      ++v5;
      if ( v4 >= this->m_ServerQueryChallenges.m_Size )
      {
        v2 = oldest;
        goto LABEL_8;
      }
    }
    this->m_ServerQueryChallenges.m_Memory.m_pMemory[v4].time = net_time;
    return this->m_ServerQueryChallenges.m_Memory.m_pMemory[v4].challenge;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138A10
// Name: public: void CBaseServer::ReconnectClients(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ReconnectClients(CBaseServer *this)
{
  CBaseClient *v1; // edi
  int m_nSignonState; // eax
  char *m_pMemory; // eax
  char *v4; // eax
  NET_SignonState signon; // [esp+4h] [ebp-4Ch] BYREF
  CBaseServer *v6; // [esp+48h] [ebp-8h]
  int i; // [esp+4Ch] [ebp-4h]

  v6 = this;
  for ( i = 0; i < v6->m_Clients.m_Size; ++i )
  {
    v1 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v1->IsConnected(this: &v1->IClient) )
    {
      CBaseClient::SetSignonState(this: v1, nState: 2);
      m_nSignonState = v1->m_nSignonState;
      signon.m_bReliable = true;
      signon.m_NetChannel = nullptr;
      signon.__vftable = (NET_SignonState_vtbl *)&NET_SignonState::`vftable';
      signon.m_nSignonState = m_nSignonState;
      signon.m_nSpawnCount = -1;
      memset(&signon.m_numServerPlayers, 0, 44);
      CBaseClient::FillSignOnFullServerInfo(this: v1, state: &signon);
      v1->SendNetMsg(this: &v1->IClient, a2: &signon, a3: false, a4: false);
      m_pMemory = signon.m_Mapname.m_Memory.m_pMemory;
      signon.m_Mapname.m_Size = 0;
      if ( signon.m_Mapname.m_Memory.m_nGrowSize >= 0 )
      {
        if ( signon.m_Mapname.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: signon.m_Mapname.m_Memory.m_pMemory);
          m_pMemory = nullptr;
          signon.m_Mapname.m_Memory.m_pMemory = nullptr;
        }
        signon.m_Mapname.m_Memory.m_nAllocationCount = 0;
      }
      signon.m_Mapname.m_pElements = m_pMemory;
      if ( signon.m_Mapname.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          signon.m_Mapname.m_Memory.m_pMemory = nullptr;
        }
        signon.m_Mapname.m_Memory.m_nAllocationCount = 0;
      }
      v4 = signon.m_PlayersNetworkIds.m_Memory.m_pMemory;
      signon.m_PlayersNetworkIds.m_Size = 0;
      if ( signon.m_PlayersNetworkIds.m_Memory.m_nGrowSize >= 0 )
      {
        if ( signon.m_PlayersNetworkIds.m_Memory.m_pMemory != nullptr )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: signon.m_PlayersNetworkIds.m_Memory.m_pMemory);
          v4 = nullptr;
          signon.m_PlayersNetworkIds.m_Memory.m_pMemory = nullptr;
        }
        signon.m_PlayersNetworkIds.m_Memory.m_nAllocationCount = 0;
      }
      signon.m_PlayersNetworkIds.m_pElements = v4;
      if ( signon.m_PlayersNetworkIds.m_Memory.m_nGrowSize >= 0 && v4 != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v4);
    }
    this = v6;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138B60
// Name: public: virtual void CBaseServer::Init(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::Init(CBaseServer *this, bool bIsDedicated)
{
  int v3; // eax
  bool v4; // al
  void (__thiscall *Clear)(CBaseServer *); // eax

  this->m_nMaxclients = 0;
  this->m_nSpawnCount = 0;
  this->m_nUserid = 1;
  this->m_bIsDedicated = bIsDedicated;
  v4 = false;
  if ( bIsDedicated )
  {
    v3 = _CommandLine();
    if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-xlsp") != 0 )
      v4 = true;
  }
  this->m_bIsDedicatedForXbox = v4;
  this->m_Socket = 1;
  CNetworkStringTable::SetTick(this: &this->m_Signon, pDebugName: "m_Signon");
  g_pCVar->InstallGlobalChangeCallback(
    this: g_pCVar,
    a2: (void (__cdecl *)(IConVar *, const char *, float))ServerNotifyVarChangeCallback);
  Clear = this->Clear;
  this->m_bMasterServerRulesDirty = true;
  Clear(this);
}

//------------------------------------------------------------------------------
// Address: 0x10138C00
// Name: protected: void CBaseServer::UpdateMasterServerRules(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::UpdateMasterServerRules(CBaseServer *this)
{
  CBaseServer *v1; // edi
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // esi
  ICvar::ICVarIteratorInternal *v3; // ebx
  ConCommandBase *v4; // edi
  IConVar *v5; // eax

  v1 = this;
  if ( this->m_bMasterServerRulesDirty )
  {
    m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
    if ( m_pSteamMasterServerUpdater != nullptr )
    {
      m_pSteamMasterServerUpdater->ClearAllKeyValues(this: m_pSteamMasterServerUpdater);
      v3 = g_pCVar->FactoryInternalIterator(this: g_pCVar);
      v3->SetFirst(this: v3);
      if ( v3->IsValid(this: v3) )
      {
        do
        {
          v4 = v3->Get(this: v3);
          if ( v4->IsFlagSet(this: v4, a2: 256) )
          {
            v5 = (IConVar *)__RTDynamicCast(
                              inptr: v4,
                              VfDelta: 0,
                              SrcType: &ConCommandBase `RTTI Type Descriptor',
                              TargetType: &ConVar `RTTI Type Descriptor',
                              isReference: 0);
            if ( v5 != nullptr )
              SetMasterServerKeyValue(pUpdater: m_pSteamMasterServerUpdater, pConVar: v5 + 6);
          }
          v3->Next(this: v3);
        }
        while ( v3->IsValid(this: v3) );
        v1 = this;
      }
      if ( Steam3Server()->m_pSteamGameServer != nullptr )
        CBaseServer::RecalculateTags(this: v1);
      v1->m_bMasterServerRulesDirty = false;
      free(pMem: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10138CF0
// Name: protected: class CBaseClient __near * CBaseServer::GetFreeClientInternal(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseServer::GetFreeClientInternal(CBaseServer *this, netadr_s *adr)
{
  CBaseClient *v3; // ebx
  const netadr_s *v4; // eax
  const char *v5; // eax
  int v6; // esi
  CBaseClient *v7; // eax
  void (__thiscall *Clear)(IClient *); // eax
  CBaseClient *v10; // eax
  CUtlMemory<S3RGBA,int> *p_m_Clients; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  S3RGBA *m_pMemory; // ecx
  int v15; // eax
  CBaseClient **v16; // eax
  int slot; // [esp+Ch] [ebp-8h]
  CBaseClient *freeclient; // [esp+10h] [ebp-4h]
  netadr_s *adra; // [esp+1Ch] [ebp+8h]

  freeclient = nullptr;
  slot = 0;
  if ( this->m_Clients.m_Size > 0 )
  {
    do
    {
      v3 = this->m_Clients.m_Memory.m_pMemory[slot];
      if ( !v3->IsFakeClient(this: &v3->IClient) )
      {
        if ( v3->IsConnected(this: &v3->IClient) )
        {
          v4 = v3->m_NetChannel->GetRemoteAddress(this: v3->m_NetChannel);
          if ( netadr_s::CompareAdr(this: adr, a: v4, onlyBase: false) )
          {
            v5 = netadr_s::ToString(this: adr, baseOnly: false);
            ConMsg(a1: "%s:reconnect\n", v5);
            if ( host_state.max_splitscreen_players > 1 )
            {
              v6 = (int)&v3->m_SplitScreenUsers[host_state.max_splitscreen_players];
              adra = (netadr_s *)(host_state.max_splitscreen_players - 1);
              do
              {
                v7 = *(CBaseClient **)(v6 - 4);
                v6 -= 4;
                if ( v7 != nullptr )
                {
                  this->RemoveClientFromGame(this, a2: v7);
                  (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)v6 + 220) + 148))(
                    a1: *(_DWORD *)(*(_DWORD *)v6 + 220),
                    a2: 0);
                  *(_DWORD *)(*(_DWORD *)v6 + 220) = 0;
                  (*(void (__thiscall **)(int))(*(_DWORD *)(*(_DWORD *)v6 + 4) + 104))(a1: *(_DWORD *)v6 + 4);
                  *(_DWORD *)v6 = 0;
                }
                adra = (netadr_s *)((char *)adra - 1);
              }
              while ( adra != nullptr );
            }
            this->RemoveClientFromGame(this, a2: v3);
            v3->m_NetChannel->Shutdown(this: v3->m_NetChannel, a2: nullptr);
            Clear = v3->Clear;
            v3->m_NetChannel = nullptr;
            Clear(this: &v3->IClient);
            return v3;
          }
        }
        else if ( freeclient == nullptr )
        {
          freeclient = v3;
        }
      }
      ++slot;
    }
    while ( slot < this->m_Clients.m_Size );
    if ( freeclient != nullptr )
      return freeclient;
  }
  if ( this->m_Clients.m_Size >= this->m_nMaxclients )
    return nullptr;
  v10 = this->CreateNewClient(this, a2: this->m_Clients.m_Size);
  p_m_Clients = (CUtlMemory<S3RGBA,int> *)&this->m_Clients;
  m_Size = this->m_Clients.m_Size;
  freeclient = v10;
  m_nAllocationCount = p_m_Clients->m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<INetMessage *,int>::Grow(this: p_m_Clients, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Clients[1].m_pMemory;
  m_pMemory = p_m_Clients->m_pMemory;
  v15 = (int)p_m_Clients[1].m_pMemory - m_Size - 1;
  p_m_Clients[1].m_nAllocationCount = (int)p_m_Clients->m_pMemory;
  if ( v15 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v15);
  v16 = (CBaseClient **)&p_m_Clients->m_pMemory[m_Size];
  if ( v16 != nullptr )
    *v16 = freeclient;
  return freeclient;
}

//------------------------------------------------------------------------------
// Address: 0x10138EE0
// Name: public: virtual void CBaseServer::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::Shutdown(CBaseServer *this)
{
  int j; // edi
  CBaseClient *v3; // ecx
  int v4; // eax
  int k; // ebx
  CBaseClient *v6; // edi
  bool (__thiscall *IsConnected)(IClient *); // eax
  IClient *v8; // edi
  bool v9; // al
  IClient_vtbl *v10; // edx
  int m_Size; // eax
  int v12; // edi
  CBaseClient **m_pMemory; // ecx
  int v14; // eax
  CBaseClient **v15; // eax
  int v16; // ebx
  int m; // edi
  CBaseClient *v18; // ecx
  CSteam3Server *v19; // eax
  CUtlVector<CBaseClient *,CUtlMemory<CBaseClient *,int> > vecDelete; // [esp+4h] [ebp-18h] BYREF
  CBaseClient *i; // [esp+18h] [ebp-4h]

  g_pCVar->RemoveGlobalChangeCallback(
    this: g_pCVar,
    a2: (void (__cdecl *)(IConVar *, const char *, float))ServerNotifyVarChangeCallback);
  if ( this->IsActive(this) )
  {
    this->m_State = ss_dead;
    memset(&vecDelete, 0, sizeof(vecDelete));
    for ( i = (CBaseClient *)3; i != nullptr; i = (CBaseClient *)((char *)i - 1) )
    {
      for ( j = 0; j < this->m_Clients.m_Size; ++j )
      {
        v3 = this->m_Clients.m_Memory.m_pMemory[j];
        v4 = (int)v3->GetNetChannel(this: &v3->IClient);
        if ( v4 != 0 )
          (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v4 + 192))(a1: v4, a2: 0);
      }
      Sys_Sleep(msec: 10);
    }
    for ( k = this->m_Clients.m_Size - 1; k >= 0; --k )
    {
      v6 = this->m_Clients.m_Memory.m_pMemory[k];
      IsConnected = v6->IsConnected;
      i = v6;
      v8 = &v6->IClient;
      v9 = IsConnected(this: v8);
      v10 = v8->__vftable;
      if ( v9 )
      {
        if ( v10->IsSplitScreenUser(this: v8) )
          i->m_bSplitScreenUser = false;
        v8->Disconnect(this: v8, a2: "Server shutting down");
      }
      else
      {
        v10->Clear(this: v8);
      }
      m_Size = vecDelete.m_Size;
      v12 = vecDelete.m_Size;
      if ( vecDelete.m_Size + 1 > vecDelete.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<INetMessage *,int>::Grow(
          this: (CUtlMemory<S3RGBA,int> *)&vecDelete,
          num: vecDelete.m_Size - vecDelete.m_Memory.m_nAllocationCount + 1);
        m_Size = vecDelete.m_Size;
      }
      m_pMemory = vecDelete.m_Memory.m_pMemory;
      vecDelete.m_Size = m_Size + 1;
      v14 = m_Size - v12;
      vecDelete.m_pElements = vecDelete.m_Memory.m_pMemory;
      if ( v14 > 0 )
      {
        _V_memmove(
          dest: &vecDelete.m_Memory.m_pMemory[v12 + 1],
          src: &vecDelete.m_Memory.m_pMemory[v12],
          count: 4 * v14);
        m_pMemory = vecDelete.m_Memory.m_pMemory;
      }
      v15 = &m_pMemory[v12];
      if ( v15 != nullptr )
        *v15 = i;
      if ( this->m_Clients.m_Size - k - 1 > 0 )
        _V_memmove(
          dest: &this->m_Clients.m_Memory.m_pMemory[k],
          src: &this->m_Clients.m_Memory.m_pMemory[k + 1],
          count: 4 * (this->m_Clients.m_Size - k - 1));
      --this->m_Clients.m_Size;
    }
    Sys_Sleep(msec: 100);
    v16 = vecDelete.m_Size;
    for ( m = 0; m < v16; ++m )
    {
      v18 = vecDelete.m_Memory.m_pMemory[m];
      if ( v18 != nullptr )
        ((void (__thiscall *)(CBaseClient *, int))v18->dtr_IGameEventListener2)(a1: v18, a2: 1);
    }
    this->Clear(this);
    if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
    {
      v19 = Steam3Server();
      v19->m_pSteamMasterServerUpdater->NotifyShutdown(this: v19->m_pSteamMasterServerUpdater);
    }
    g_pMaster->ShutdownConnection(this: g_pMaster, a2: this);
    if ( vecDelete.m_Memory.m_nGrowSize >= 0 && vecDelete.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: vecDelete.m_Memory.m_pMemory);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101390F0
// Name: public: void CBaseServer::QueueSplitScreenDisconnect(class CBaseClient __near *,class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::QueueSplitScreenDisconnect(
        CBaseServer *this,
        CBaseClient *pSplitHost,
        CBaseClient *pSplitUser)
{
  CBaseServer::SplitDisconnect_t disc; // [esp+0h] [ebp-8h] BYREF

  disc.m_pUser = pSplitHost;
  disc.m_pSplit = pSplitUser;
  CUtlVector<RegisteredDemoCustomDataCallbackPair_t,CUtlMemory<RegisteredDemoCustomDataCallbackPair_t,int>>::InsertBefore(
    this: (CUtlVector<vgui::PropertySheet::Page_t,CUtlMemory<vgui::PropertySheet::Page_t,int> > *)&this->m_QueuedForDisconnect,
    elem: this->m_QueuedForDisconnect.m_Size,
    src: (const vgui::PropertySheet::Page_t *)&disc);
}

//------------------------------------------------------------------------------
// Address: 0x10139120
// Name: BuildTokenList
// Source: json
//------------------------------------------------------------------------------
void __usercall BuildTokenList(
        CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *list@<esi>,
        char *pchString,
        unsigned __int8 chDelim)
{
  int v3; // ebx
  void *v4; // esp
  const char *v5; // edi
  _BYTE *v6; // eax
  _BYTE *v7; // ebx
  char v8; // dl
  bool v9; // zf
  CUtlString *v10; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  CUtlString *v13; // ecx
  int v14; // eax
  CUtlString *v15; // edi
  _BYTE *v16; // eax
  const CUtlString *v17; // eax
  unsigned __int8 v18[8]; // [esp+0h] [ebp-20h] BYREF
  CUtlString v19; // [esp+8h] [ebp-18h] BYREF
  CUtlString *string; // [esp+18h] [ebp-8h]
  char v21; // [esp+1Fh] [ebp-1h]

  v3 = _V_strlen(str: pchString);
  v4 = alloca(v3 + 1);
  v5 = (const char *)v18;
  V_strncpy(pDest: (char *)v18, pSrc: pchString, maxLen: v3 + 1);
  strchr(string: v18, chr: chDelim);
  v7 = v6;
  if ( v6 != nullptr )
  {
    while ( v5 != nullptr )
    {
      v8 = *v7;
      *v7 = 0;
      v9 = *v5 == 0;
      v21 = v8;
      if ( !v9 )
      {
        v10 = CUtlString::CUtlString(this: &v19, pString: v5);
        m_pMemory = (int)list[1].m_pMemory;
        string = v10;
        m_nAllocationCount = list->m_nAllocationCount;
        if ( m_pMemory + 1 > m_nAllocationCount )
          CUtlMemory<CPortalRect,int>::Grow(this: list, num: m_pMemory - m_nAllocationCount + 1);
        ++list[1].m_pMemory;
        v13 = (CUtlString *)list->m_pMemory;
        v14 = (int)list[1].m_pMemory - m_pMemory - 1;
        list[1].m_nAllocationCount = (int)list->m_pMemory;
        if ( v14 > 0 )
          _V_memmove(dest: &v13[m_pMemory + 1], src: &v13[m_pMemory], count: 16 * v14);
        v15 = (CUtlString *)&list->m_pMemory[m_pMemory];
        if ( v15 != nullptr )
          CUtlString::CUtlString(this: v15, string);
        v19.m_Storage.m_nActualLength = 0;
        if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v19.m_Storage.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
            v19.m_Storage.m_Memory.m_pMemory = nullptr;
          }
          v19.m_Storage.m_Memory.m_nAllocationCount = 0;
        }
      }
      v5 = v7 + 1;
      *v7 = v21;
      strchr(string: v7 + 1, chr: chDelim);
      v7 = v16;
      if ( v16 == nullptr )
        goto LABEL_15;
    }
  }
  else
  {
LABEL_15:
    if ( v5 != nullptr && *v5 != 0 )
    {
      v17 = CUtlString::CUtlString(this: &v19, pString: v5);
      CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(
        this: (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)list,
        elem: (int)list[1].m_pMemory,
        src: v17);
      v19.m_Storage.m_nActualLength = 0;
      if ( v19.m_Storage.m_Memory.m_nGrowSize >= 0 && v19.m_Storage.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v19.m_Storage.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139370
// Name: protected: void CBaseServer::UpdateMasterServer(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseServer::UpdateMasterServer(CBaseServer *this@<ecx>, int a2@<ebx>)
{
  long double v3; // st7
  char v4; // bl
  int v5; // eax
  CSteam3Server *v6; // eax
  int bActive; // [esp+4h] [ebp-4h]

  if ( this->ShouldUpdateMasterServer(this) )
  {
    if ( IsUsingMasterLegacyMode() )
    {
      g_pMaster->CheckHeartbeat(this: g_pMaster, a2: this);
    }
    else if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
    {
      CBaseServer::ForwardPacketsFromMasterServerUpdater(this);
      v3 = _Plat_FloatTime();
      if ( v3 - this->m_flLastMasterServerUpdateTime >= 2.0 )
      {
        this->m_flLastMasterServerUpdateTime = v3;
        CBaseServer::CheckMasterServerRequestRestart(this);
        if ( NET_IsDedicated() && sv_region.m_pParent != nullptr && sv_region.m_pParent->m_Value.m_nValue == -1 )
          CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_region.IConVar, value: 255);
        bActive = a2;
        v4 = 1;
        if ( (_S1_13 & 1) == 0 )
        {
          _S1_13 |= 1u;
          v5 = _CommandLine();
          bUpdateMasterServers = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v5 + 40))(
                                   a1: v5,
                                   a2: "-nomaster",
                                   a3: bActive) == 0;
        }
        if ( bUpdateMasterServers )
        {
          if ( !this->IsActive(this)
            || !this->IsMultiplayer(this)
            || !g_bEnableMasterServerUpdater
            || CBaseServer::IsSinglePlayerGame(this) )
          {
            v4 = 0;
          }
          LOBYTE(bActive) = v4;
          if ( CBaseServer::ShouldHideFromMasterServer(this) )
          {
            v4 = 0;
            LOBYTE(bActive) = 0;
          }
          v6 = Steam3Server();
          v6->m_pSteamMasterServerUpdater->SetActive(this: v6->m_pSteamMasterServerUpdater, a2: bActive);
          if ( v4 != 0 )
          {
            CBaseServer::UpdateMasterServerRules(this);
            this->UpdateMasterServerPlayers(this);
            CBaseServer::UpdateMasterServerBasicData(this);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101394D0
// Name: public: void CBaseServer::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseServer::RunFrame(CBaseServer *this@<ecx>, int a2@<ebx>)
{
  int i; // edi
  CBaseClient *v4; // ecx
  int j; // edi
  CBaseClient *v6; // ecx

  CVProfile::EnterScope(
    this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled,
    a2: "CBaseServer::RunFrame",
    a3: 0,
    a4: "Networking",
    a5: false,
    a6: 4);
  NET_ProcessSocket(sock: this->m_Socket, handler: this);
  CBaseServer::CheckTimeouts(this);
  for ( i = 0; i < this->m_Clients.m_Size; ++i )
  {
    v4 = this->m_Clients.m_Memory.m_pMemory[i];
    if ( v4->m_bConVarsChanged )
      v4->UpdateUserSettings(this: v4);
  }
  for ( j = 0; j < this->m_Clients.m_Size; ++j )
  {
    v6 = this->m_Clients.m_Memory.m_pMemory[j];
    if ( v6->m_bSendServerInfo )
      v6->SendServerInfo(this: v6);
  }
  this->CalculateCPUUsage(this);
  CBaseServer::UpdateMasterServer(this, a2);
  if ( this->m_bMasterServerRulesDirty )
  {
    this->m_bMasterServerRulesDirty = false;
    CBaseServer::RecalculateTags(this);
  }
  CBaseServer::ProcessSplitScreenDisconnects(this);
  CVProfile::ExitScope(this: *(CVProfile **)&_g_VProfCurrentProfile.m_bVTuneGroupEnabled);
}

//------------------------------------------------------------------------------
// Address: 0x101395B0
// Name: public: virtual class CBaseClient __near * CBaseServer::CreateFakeClient(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseServer::CreateFakeClient(CBaseServer *this, const char *name)
{
  CBaseClient *result; // eax
  CBaseClient *v4; // esi
  CNetChan *v5; // ebx
  const char *v6; // eax
  int NextUserID; // eax
  netadr_s adr; // [esp+8h] [ebp-18h] BYREF
  netadr_s v9; // [esp+14h] [ebp-Ch] BYREF

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  result = CBaseServer::GetFreeClientInternal(this, &adr);
  v4 = result;
  if ( result != nullptr )
  {
    v5 = nullptr;
    if ( sv_stressbots.m_pParent != nullptr && sv_stressbots.m_pParent->m_Value.m_nValue != 0 )
    {
      netadr_s::SetIP(this: &v9, unIP: 0);
      netadr_s::SetPort(this: &v9, newport: 0);
      netadr_s::SetType(this: &v9, newtype: NA_IP);
      v6 = netadr_s::ToString(this: &v9, baseOnly: false);
      v5 = NET_CreateNetChannel(
             socket: this->m_Socket,
             adr: &v9,
             name: v6,
             handler: &v4->IClient,
             bForceNewChannel: true);
    }
    NextUserID = CBaseServer::GetNextUserID(this);
    this->m_nUserid = NextUserID;
    v4->Connect(this: &v4->IClient, a2: name, a3: NextUserID, a4: v5, a5: true, a6: CROSSPLAYPLATFORM_PC, a7: nullptr);
    v4->SetUserCVar(this: v4, a2: "rate", a3: "30000");
    v4->SetUserCVar(this: v4, a2: "cl_updaterate", a3: "20");
    v4->SetUserCVar(this: v4, a2: "cl_interp_ratio", a3: "1.0");
    v4->SetUserCVar(this: v4, a2: "cl_interp", a3: "0.1");
    v4->SetUserCVar(this: v4, a2: "cl_interpolate", a3: "0");
    v4->SetUserCVar(this: v4, a2: "cl_predict", a3: "1");
    v4->SetUserCVar(this: v4, a2: "cl_predictweapons", a3: "1");
    v4->SetUserCVar(this: v4, a2: "cl_lagcompensation", a3: "1");
    v4->SetUserCVar(this: v4, a2: "closecaption", a3: "0");
    v4->SetUserCVar(this: v4, a2: "english", a3: "1");
    v4->SetUserCVar(this: v4, a2: "cl_team", a3: "blue");
    v4->SetUserCVar(this: v4, a2: "hud_classautokill", a3: "1");
    v4->SetUserCVar(this: v4, a2: "tf_medigun_autoheal", a3: "0");
    v4->SetUserCVar(this: v4, a2: "cl_autorezoom", a3: "1");
    v4->SetUserCVar(this: v4, a2: "fov_desired", a3: "75");
    v4->ActivatePlayer(this: v4);
    v4->m_nSignonTick = this->m_nTickCount;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101397A0
// Name: public: class CBaseClient __near * CBaseServer::CreateSplitClient(class CUtlVector<struct NetMessageCvar_t,class CUtlMemory<struct NetMessageCvar_t,int>> __near &,class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
CBaseClient *__thiscall CBaseServer::CreateSplitClient(
        CBaseServer *this,
        CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *vecUserInfo,
        CBaseClient *pAttachedTo)
{
  CBaseClient *FreeClientInternal; // eax
  CBaseClient *v5; // esi
  IClient *v7; // edi
  const char *v8; // eax
  int NextUserID; // eax
  IClient_vtbl *v10; // edx
  bool (__thiscall *CheckConnect)(IClient *); // eax
  bool v12; // al
  INetChannelHandler *v13; // [esp-Ch] [ebp-24h]
  netadr_s adr; // [esp+8h] [ebp-10h] BYREF
  INetChannel *netchan; // [esp+14h] [ebp-4h]

  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  FreeClientInternal = CBaseServer::GetFreeClientInternal(this, &adr);
  v5 = FreeClientInternal;
  if ( FreeClientInternal == nullptr )
    return nullptr;
  v7 = &FreeClientInternal->IClient;
  v13 = &FreeClientInternal->IClient;
  v8 = netadr_s::ToString(this: &adr, baseOnly: false);
  netchan = NET_CreateNetChannel(socket: this->m_Socket, &adr, name: v8, handler: v13, bForceNewChannel: true);
  NextUserID = CBaseServer::GetNextUserID(this);
  this->m_nUserid = NextUserID;
  v7->Connect(
    this: &v5->IClient,
    a2: "split",
    a3: NextUserID,
    a4: netchan,
    a5: true,
    a6: pAttachedTo->m_ClientPlatform,
    a7: vecUserInfo);
  v10 = v7->__vftable;
  v5->m_pAttachedTo = pAttachedTo;
  CheckConnect = v10->CheckConnect;
  v5->m_bSplitScreenUser = true;
  v5->m_nSignonTick = this->m_nTickCount;
  v5->m_bSplitAllowFastDisconnect = true;
  v12 = CheckConnect(this: &v5->IClient);
  v5->m_bSplitAllowFastDisconnect = false;
  if ( v12 )
    return v5;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10139880
// Name: protected: virtual class IClient __near * CBaseServer::ConnectClient(struct netadr_s __near &,int,int,int,char const __near *,char const __near *,char const __near *,int,class CUtlVector<class CLC_SplitPlayerConnect,class CUtlMemory<class CLC_SplitPlayerConnect,int>> __near &,bool,enum CrossPlayPlatform_t)
// Source: json
//------------------------------------------------------------------------------
IClient *__userpurge CBaseServer::ConnectClient@<eax>(
        CBaseServer *this@<ecx>,
        int a2@<ebx>,
        int a3@<edi>,
        netadr_s *adr,
        const char *protocol,
        int challenge,
        int authProtocol,
        const char *name,
        INetChannel *password,
        const char *hashedCDkey,
        int cdKeyLen,
        CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > *splitScreenClients,
        bool isClientLowViolence,
        CrossPlayPlatform_t clientPlatform)
{
  const char *v15; // eax
  const char *v18; // eax
  CBaseServer_vtbl *v19; // edi
  const char *v20; // eax
  CBaseServer *v21; // ecx
  const char *v22; // eax
  int m_Size; // edi
  int v24; // edi
  CBaseClient *FreeClientInternal; // edi
  int NextUserID; // eax
  bool (__thiscall *CheckChallengeType)(CBaseServer *, CBaseClient *, int, netadr_s *, int, const char *, int); // edx
  const CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *p_m_UserInfo; // eax
  const char *v29; // eax
  CNetChan *NetChannel; // eax
  int v31; // ecx
  long double v32; // st7
  CFrameSnapshot *m_pObj; // ecx
  IClientMessageHandler *v34; // ebx
  int v35; // edi
  int v36; // eax
  IClient *v37; // edi
  const char *v38; // eax
  const char *v39; // eax
  unsigned __int64 v40; // [esp-18h] [ebp-2Ch]
  const char *v41; // [esp-10h] [ebp-24h]
  unsigned __int64 m_nReservationCookie; // [esp-10h] [ebp-24h]
  const char *v43; // [esp-Ch] [ebp-20h]
  unsigned __int64 uid; // [esp+4h] [ebp-10h] BYREF
  int nNextUserID; // [esp+Ch] [ebp-8h]
  const CUtlVector<NetMessageCvar_t,CUtlMemory<NetMessageCvar_t,int> > *list; // [esp+10h] [ebp-4h]
  IClient *bIsLocalConnection; // [esp+1Ch] [ebp+8h]
  char bIsLocalConnection_3; // [esp+1Fh] [ebp+Bh]
  char bIsLocalConnection_3a; // [esp+1Fh] [ebp+Bh]
  const char *value; // [esp+20h] [ebp+Ch]
  INetChannel *netchan; // [esp+30h] [ebp+1Ch]
  INetChannel *netchana; // [esp+30h] [ebp+1Ch]
  int i; // [esp+38h] [ebp+24h]
  int playerIndex; // [esp+40h] [ebp+2Ch]

  _COM_TimestampedLog(a1: "CBaseServer::ConnectClient");
  if ( !this->IsActive(this) )
  {
    v15 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Server not active, ignoring %s\n", v15);
    return nullptr;
  }
  if ( name != nullptr && password != nullptr && hashedCDkey != nullptr )
  {
    if ( !this->CheckProtocol(this, a2: adr, a3: (int)protocol) )
    {
      v18 = netadr_s::ToString(this: adr, baseOnly: false);
      DevMsg(a1: "Protocol error from %s\n", v18);
      return nullptr;
    }
    if ( !this->CheckChallengeNr(this, a2: adr, a3: challenge) )
    {
      this->RejectConnection(this, a2: adr, a3: "Bad challenge.\n");
      return nullptr;
    }
    if ( netadr_s::IsLocalhost(this: adr) || (bIsLocalConnection_3 = 0, netadr_s::IsLoopback(this: adr)) )
      bIsLocalConnection_3 = 1;
    if ( CBaseServer::IsExclusiveToLobbyConnections(this) && !CBaseServer::IsReserved(this) && bIsLocalConnection_3 == 0 )
    {
      v19 = this->__vftable;
      v20 = netadr_s::ToString(this: adr, baseOnly: false);
      v19->RejectConnection(
        this,
        a2: adr,
        a3: "Server only accepting connections from game lobby %s %d.\n",
        v20,
        challenge);
      return nullptr;
    }
    if ( this->IsDedicated(this) || bIsLocalConnection_3 != 0 )
      goto LABEL_30;
    if ( sv.m_bIsLevelMainMenuBackground )
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Background_Map");
      return nullptr;
    }
    if ( CBaseServer::IsSinglePlayerGame(this) )
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Single_Player");
      return nullptr;
    }
    if ( !CBaseServer::ShouldHideServer(this: v21) )
    {
LABEL_30:
      if ( this->IsHLTV(this) || this->IsReplay(this) )
        goto LABEL_69;
      if ( !this->CheckIPRestrictions(this, a2: adr, a3: authProtocol) )
      {
        this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_LAN_Game");
        return nullptr;
      }
      if ( this->CheckPassword(this, a2: adr, a3: (const char *)password, a4: name) )
      {
LABEL_69:
        if ( this->m_numGameSlots != 0 )
        {
          m_Size = splitScreenClients->m_Size;
          v24 = m_Size - this->GetNumFakeClients(this);
          if ( v24 + this->GetNumClients(this) > this->m_numGameSlots )
          {
            this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Server_Full");
            return nullptr;
          }
        }
        _COM_TimestampedLog(a1: "CBaseServer::ConnectClient:  GetFreeClient");
        FreeClientInternal = CBaseServer::GetFreeClientInternal(this, adr);
        if ( FreeClientInternal != nullptr )
        {
          NextUserID = CBaseServer::GetNextUserID(this);
          CheckChallengeType = this->CheckChallengeType;
          nNextUserID = NextUserID;
          if ( !CheckChallengeType(
                  this,
                  a2: FreeClientInternal,
                  a3: NextUserID,
                  a4: adr,
                  a5: authProtocol,
                  a6: hashedCDkey,
                  a7: cdKeyLen)
            || !this->FinishCertificateCheck(this, a2: adr, a3: authProtocol, a4: hashedCDkey) )
          {
            return nullptr;
          }
          bIsLocalConnection_3a = 0;
          if ( this->m_nReservationCookie == 0 )
            goto LABEL_53;
          if ( splitScreenClients->m_Size == 0 )
            goto LABEL_52;
          p_m_UserInfo = &splitScreenClients->m_Memory.m_pMemory->m_UserInfo;
          list = p_m_UserInfo;
          i = 0;
          if ( p_m_UserInfo->m_Size <= 0 )
            goto LABEL_52;
          netchan = nullptr;
          while ( 1 )
          {
            v41 = &p_m_UserInfo->m_Memory.m_pMemory->name[(unsigned int)netchan];
            value = v41 + 260;
            if ( _V_stricmp(s1: v41, s2: "cl_session") == 0 )
            {
              if ( sscanf(string: value, format: "$%llx", &uid) == 1 )
              {
                if ( uid == this->m_nReservationCookie )
                {
                  bIsLocalConnection_3a = 1;
                }
                else
                {
                  m_nReservationCookie = this->m_nReservationCookie;
                  v40 = uid;
                  v29 = netadr_s::ToString(this: adr, baseOnly: false);
                  _Warning(
                    a1: "mismatching cookie from %s, client %llx, server %llx!\n",
                    v29,
                    v40,
                    m_nReservationCookie);
                }
              }
              else
              {
                _Warning(a1: "failed to parse session id %s\n", value);
              }
            }
            netchan += 130;
            if ( ++i >= list->m_Size )
              break;
            p_m_UserInfo = list;
          }
          if ( bIsLocalConnection_3a != 0 )
          {
LABEL_53:
            _COM_TimestampedLog(a1: "CBaseServer::ConnectClient:  NET_CreateNetChannel");
            bIsLocalConnection = &FreeClientInternal->IClient;
            NetChannel = NET_CreateNetChannel(
                           socket: this->m_Socket,
                           adr,
                           name,
                           handler: &FreeClientInternal->IClient,
                           bForceNewChannel: false);
            netchana = NetChannel;
            if ( NetChannel == nullptr )
            {
              this->RejectConnection(this, a2: adr, a3: "Failed to create net channel.\n");
              return nullptr;
            }
            ((void (__thiscall *)(CNetChan *, int, int, int))NetChannel->SetChallengeNr)(
              a1: NetChannel,
              a2: challenge,
              a3: a2,
              a4: a3);
            _COM_TimestampedLog(a1: "CBaseServer::ConnectClient:  client->Connect");
            ((void (__thiscall *)(IClient *, const char *, int, INetChannel *, _DWORD))bIsLocalConnection->Connect)(
              a1: bIsLocalConnection,
              a2: name,
              a3: nNextUserID,
              a4: netchana,
              a5: 0);
            v31 = nNextUserID;
            FreeClientInternal->m_bLowViolence = isClientLowViolence;
            this->m_nUserid = v31;
            FreeClientInternal->m_fSnapshotInterval = 0.050000001;
            v32 = net_time + 0.05000000074505806;
            FreeClientInternal->m_nDeltaTick = -1;
            FreeClientInternal->m_nSignonTick = 0;
            FreeClientInternal->m_fNextMessageTime = v32;
            FreeClientInternal->m_nStringTableAckTick = 0;
            m_pObj = FreeClientInternal->m_pLastSnapshot.m_pObj;
            if ( m_pObj != nullptr )
            {
              CFrameSnapshot::ReleaseReference(this: m_pObj);
              FreeClientInternal->m_pLastSnapshot.m_pObj = nullptr;
            }
            NET_OutOfBandPrintf(sock: this->m_Socket, adr, format: "%c00000000000000", 66);
            if ( authProtocol == 2 )
            {
              V_strncpy(pDest: FreeClientInternal->m_GUID, pSrc: hashedCDkey, maxLen: 32);
              FreeClientInternal->m_GUID[32] = 0;
            }
            playerIndex = 1;
            if ( splitScreenClients->m_Size > 1 )
            {
              v34 = &FreeClientInternal->IClientMessageHandler;
              v35 = 1;
              do
              {
                ConMsg(a1: "Processing Split Screen connection packet.\n");
                v34->ProcessSplitPlayerConnect(this: v34, a2: &splitScreenClients->m_Memory.m_pMemory[v35++]);
                ++playerIndex;
              }
              while ( playerIndex < splitScreenClients->m_Size );
            }
            if ( netchana->IsLoopback(this: netchana) )
            {
              v37 = bIsLocalConnection;
            }
            else
            {
              v36 = (int)netchana->GetAddress(this: netchana);
              v37 = bIsLocalConnection;
              v38 = (const char *)((int (__thiscall *)(IClient *, int))bIsLocalConnection->GetClientName)(
                                    a1: bIsLocalConnection,
                                    a2: v36);
              ConMsg(a1: "Client \"%s\" connected (%s).\n", v38, v43);
            }
            this->m_flReservationExpiryTime = 0.0;
            this->m_flTimeLastClientLeft = -1.0;
            return v37;
          }
          else
          {
LABEL_52:
            this->RejectConnection(this, a2: adr, a3: "Invalid user info.\n");
            return nullptr;
          }
        }
        else
        {
          this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Server_Full");
          return nullptr;
        }
      }
      else
      {
        v22 = netadr_s::ToString(this: adr, baseOnly: false);
        ConMsg(a1: "%s:  password failed.\n", v22);
        this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Bad_Password");
        return nullptr;
      }
    }
    else
    {
      this->RejectConnection(this, a2: adr, a3: "#Valve_Reject_Hidden_Game");
      return nullptr;
    }
  }
  else
  {
    v39 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Bad auth data from %s\n", v39);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10139E80
// Name: public: virtual bool CBaseServer::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseServer::ProcessConnectionlessPacket(CBaseServer *this, netpacket_s *packet)
{
  char v2; // dl
  char v3; // bl
  char m_nInBufWord; // si
  int v5; // eax
  unsigned int v6; // edi
  unsigned int v7; // ebx
  bool result; // al
  const char *v9; // eax
  unsigned int v10; // esi
  int v11; // eax
  unsigned int v12; // edi
  __int64 v13; // kr00_8
  __int64 v14; // rax
  int m_nBitsAvail; // edx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ebx
  unsigned int v18; // esi
  unsigned int v19; // ebx
  int v20; // edi
  unsigned int v21; // edi
  unsigned int v22; // ebx
  int v23; // esi
  int v24; // esi
  unsigned int v25; // ebx
  unsigned int v26; // edi
  unsigned int v27; // eax
  unsigned int v28; // esi
  const unsigned int *v29; // edi
  const unsigned int *v30; // eax
  int m_nInBufWord_low; // esi
  int v32; // edx
  unsigned int v33; // ebx
  int v34; // edi
  int v35; // ecx
  int v36; // ecx
  unsigned __int64 v37; // rax
  unsigned int v38; // edi
  int v39; // edi
  int v40; // eax
  const char *v41; // eax
  unsigned int v42; // esi
  unsigned int v43; // edx
  bool IsLoopback; // al
  CBaseServer *v45; // ebx
  bool IsExclusiveToLobbyConnections; // al
  unsigned __int64 v47; // kr08_8
  const char *v48; // eax
  unsigned int v49; // eax
  unsigned int m_nReservationCookie_high; // ecx
  const char *v51; // eax
  int v52; // esi
  __int16 v53; // di
  __int16 v54; // di
  int v55; // eax
  unsigned int v56; // esi
  unsigned int v57; // edx
  KeyValues *v58; // eax
  KeyValues *v59; // esi
  IMatchEventsSubscription *v60; // eax
  CGameServer *v61; // ebx
  CSteam3Server *v62; // eax
  ISteamMasterServerUpdater *m_pSteamMasterServerUpdater; // edi
  const char *v64; // eax
  const unsigned int *m_pData; // edx
  ISteamMasterServerUpdater_vtbl *v66; // esi
  unsigned __int32 v67; // ebx
  unsigned __int16 Port; // ax
  unsigned __int64 v69; // [esp-4h] [ebp-A78h]
  unsigned __int64 v70; // [esp-4h] [ebp-A78h]
  unsigned __int64 m_nReservationCookie; // [esp+4h] [ebp-A70h]
  long double v72; // [esp+4h] [ebp-A70h]
  char cdkey[2048]; // [esp+18h] [ebp-A5Ch] BYREF
  char name[256]; // [esp+818h] [ebp-25Ch] BYREF
  char password[256]; // [esp+918h] [ebp-15Ch] BYREF
  CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int> > splitScreenPlayers; // [esp+A18h] [ebp-5Ch] BYREF
  unsigned __int64 nReservationCookie; // [esp+A2Ch] [ebp-48h]
  int v78; // [esp+A34h] [ebp-40h]
  CBaseServer *v79; // [esp+A38h] [ebp-3Ch]
  int v80; // [esp+A3Ch] [ebp-38h]
  unsigned int v81; // [esp+A40h] [ebp-34h]
  const unsigned int *v82; // [esp+A44h] [ebp-30h]
  unsigned int isClientLowViolence; // [esp+A48h] [ebp-2Ch]
  bool bIsLocalConnection; // [esp+A4Fh] [ebp-25h]
  bf_read msg; // [esp+A50h] [ebp-24h] BYREF

  v79 = this;
  msg = packet->message;
  if ( msg.m_nBitsAvail < 8 )
  {
    m_nInBufWord = msg.m_nInBufWord;
    v5 = 8 - msg.m_nBitsAvail;
    if ( msg.m_pDataIn == msg.m_pBufferEnd )
    {
      msg.m_nBitsAvail = 1;
      msg.m_bOverflow = true;
      msg.m_nInBufWord = 0;
      ++msg.m_pDataIn;
      v3 = 0;
    }
    else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
    {
      v6 = *msg.m_pDataIn;
      msg.m_nInBufWord = *msg.m_pDataIn++;
      if ( msg.m_bOverflow )
      {
        v3 = 0;
      }
      else
      {
        v7 = (v6 & CBitBuffer::s_nMaskTable[v5]) << SLOBYTE(msg.m_nBitsAvail);
        msg.m_nBitsAvail = 32 - v5;
        v3 = m_nInBufWord | v7;
        msg.m_nInBufWord = v6 >> v5;
      }
    }
    else
    {
      msg.m_bOverflow = true;
      msg.m_nInBufWord = 0;
      v3 = 0;
    }
  }
  else
  {
    v2 = msg.m_nInBufWord;
    msg.m_nBitsAvail -= 8;
    if ( msg.m_nBitsAvail != 0 )
    {
      msg.m_nInBufWord >>= 8;
      v3 = v2;
    }
    else
    {
      msg.m_nBitsAvail = 32;
      if ( msg.m_pDataIn == msg.m_pBufferEnd )
      {
        msg.m_nBitsAvail = 1;
        msg.m_nInBufWord = 0;
        ++msg.m_pDataIn;
        v3 = v2;
      }
      else
      {
        if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          msg.m_nInBufWord = *msg.m_pDataIn++;
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
        }
        v3 = v2;
      }
    }
  }
  result = CheckConnectionLessRateLimits(adr: &packet->from);
  if ( !result )
    return result;
  if ( (!v79->IsActive(this: v79) || Host_ShouldRun() == 0) && (v79->IsDedicated(this: v79) || v3 != 0) )
    return true;
  switch ( v3 )
  {
    case 0:
      v58 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v58 != nullptr )
        v59 = KeyValues::KeyValues(this: v58, setName: "OnNetLanConnectionlessPacket");
      else
        v59 = nullptr;
      KeyValues::SetPtr(this: v59, keyName: "rawpkt", value: packet);
      v60 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v60->BroadcastEvent(this: v60, a2: v59);
      return true;
    case 56:
      v10 = msg.m_nInBufWord;
      if ( msg.m_nBitsAvail < 32 )
      {
        v11 = 32 - msg.m_nBitsAvail;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          msg.m_bOverflow = true;
          v10 = 0;
        }
        else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          v12 = *msg.m_pDataIn;
          msg.m_nInBufWord = *msg.m_pDataIn++;
          if ( msg.m_bOverflow )
          {
            v10 = 0;
          }
          else
          {
            v10 |= (v12 & CBitBuffer::s_nMaskTable[v11]) << SLOBYTE(msg.m_nBitsAvail);
            msg.m_nInBufWord = v12 >> v11;
          }
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
          v10 = 0;
        }
      }
      else
      {
        msg.m_nBitsAvail -= 32;
        if ( msg.m_nBitsAvail != 0 )
        {
          msg.m_nInBufWord = 0;
        }
        else
        {
          msg.m_nBitsAvail = 32;
          if ( msg.m_pDataIn == msg.m_pBufferEnd )
          {
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            ++msg.m_pDataIn;
          }
          else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
          {
            msg.m_nInBufWord = *msg.m_pDataIn++;
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
          }
        }
      }
      v13 = CBitRead::ReadLongLong(this: &msg);
      v14 = CBitRead::ReadLongLong(this: &msg);
      _Msg(a1: "C2S_VALIDATE_SESSION from %llx, session %llx, protocol %d.\n", v13, v14, v10);
      if ( GetHostVersion() != v10 )
        return true;
      HostValidateSessionImpl();
      return true;
    case 87:
      v79->ReplyServerChallenge(this: v79, a2: (netadr_s *)packet);
      return true;
    case 105:
      NET_OutOfBandPrintf(sock: packet->source, adr: &packet->from, format: "%c00000000000000", 106);
      return true;
    case 106:
      v9 = netadr_s::ToString(this: &packet->from, baseOnly: false);
      ConMsg(a1: "A2A_ACK from %s\n", v9);
      return true;
    case 107:
      m_nBitsAvail = msg.m_nBitsAvail;
      m_pDataIn = msg.m_pDataIn;
      if ( msg.m_nBitsAvail < 32 )
      {
        v19 = msg.m_nInBufWord;
        v20 = 32 - msg.m_nBitsAvail;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          v18 = 0;
          m_nBitsAvail = 1;
          m_pDataIn = msg.m_pDataIn + 1;
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          msg.m_bOverflow = true;
          v81 = 0;
          m_pBufferEnd = msg.m_pBufferEnd;
          goto LABEL_61;
        }
        if ( msg.m_pDataIn > msg.m_pBufferEnd )
        {
          m_pBufferEnd = msg.m_pBufferEnd;
          v18 = 0;
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
          v81 = 0;
          goto LABEL_61;
        }
        v18 = *msg.m_pDataIn;
        m_pDataIn = msg.m_pDataIn + 1;
        msg.m_nInBufWord = *msg.m_pDataIn++;
        if ( msg.m_bOverflow )
        {
          m_pBufferEnd = msg.m_pBufferEnd;
          v81 = 0;
          goto LABEL_61;
        }
        isClientLowViolence = v18 & CBitBuffer::s_nMaskTable[v20];
        v81 = (isClientLowViolence << SLOBYTE(msg.m_nBitsAvail)) | v19;
        m_pBufferEnd = msg.m_pBufferEnd;
        v18 >>= v20;
      }
      else
      {
        m_pBufferEnd = msg.m_pBufferEnd;
        m_nBitsAvail = msg.m_nBitsAvail - 32;
        msg.m_nBitsAvail = m_nBitsAvail;
        if ( m_nBitsAvail != 0 )
        {
          v18 = 0;
          v81 = msg.m_nInBufWord;
        }
        else
        {
          m_nBitsAvail = 32;
          msg.m_nBitsAvail = 32;
          if ( msg.m_pDataIn == msg.m_pBufferEnd )
          {
            v18 = 0;
            m_nBitsAvail = 1;
            m_pDataIn = msg.m_pDataIn + 1;
            msg.m_nBitsAvail = 1;
            ++msg.m_pDataIn;
            v81 = msg.m_nInBufWord;
          }
          else
          {
            if ( msg.m_pDataIn <= msg.m_pBufferEnd )
            {
              v18 = *msg.m_pDataIn;
              m_pDataIn = ++msg.m_pDataIn;
            }
            else
            {
              msg.m_bOverflow = true;
              v18 = 0;
            }
            v81 = msg.m_nInBufWord;
          }
        }
      }
      msg.m_nInBufWord = v18;
LABEL_61:
      if ( m_nBitsAvail < 32 )
      {
        v22 = v18;
        v23 = 32 - m_nBitsAvail;
        if ( m_pDataIn == msg.m_pBufferEnd )
        {
          v21 = 0;
          m_nBitsAvail = 1;
          ++m_pDataIn;
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          msg.m_pDataIn = m_pDataIn;
          msg.m_bOverflow = true;
          v78 = 0;
          m_pBufferEnd = msg.m_pBufferEnd;
          goto LABEL_78;
        }
        if ( m_pDataIn > msg.m_pBufferEnd )
        {
          m_pBufferEnd = msg.m_pBufferEnd;
          v21 = 0;
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
          v78 = 0;
          goto LABEL_78;
        }
        v21 = *m_pDataIn++;
        msg.m_nInBufWord = v21;
        msg.m_pDataIn = m_pDataIn;
        if ( msg.m_bOverflow )
        {
          m_pBufferEnd = msg.m_pBufferEnd;
          v78 = 0;
          goto LABEL_78;
        }
        isClientLowViolence = v21 & CBitBuffer::s_nMaskTable[v23];
        v78 = (isClientLowViolence << m_nBitsAvail) | v22;
        m_pBufferEnd = msg.m_pBufferEnd;
        msg.m_nBitsAvail = m_nBitsAvail;
        v21 >>= v23;
      }
      else
      {
        m_nBitsAvail -= 32;
        msg.m_nBitsAvail = m_nBitsAvail;
        if ( m_nBitsAvail != 0 )
        {
          v21 = 0;
          v78 = v18;
        }
        else
        {
          m_nBitsAvail = 32;
          msg.m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            v21 = 0;
            m_nBitsAvail = 1;
            ++m_pDataIn;
            msg.m_nBitsAvail = 1;
            msg.m_pDataIn = m_pDataIn;
            v78 = v18;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              v21 = *m_pDataIn++;
              msg.m_pDataIn = m_pDataIn;
            }
            else
            {
              msg.m_bOverflow = true;
              v21 = 0;
            }
            v78 = v18;
          }
        }
      }
      msg.m_nInBufWord = v21;
LABEL_78:
      if ( m_nBitsAvail < 32 )
      {
        v24 = 32 - m_nBitsAvail;
        v25 = v21;
        if ( m_pDataIn == msg.m_pBufferEnd )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          msg.m_pDataIn = m_pDataIn + 1;
          msg.m_bOverflow = true;
          v80 = 0;
        }
        else if ( m_pDataIn <= msg.m_pBufferEnd )
        {
          v26 = *m_pDataIn;
          msg.m_nInBufWord = *m_pDataIn;
          msg.m_pDataIn = m_pDataIn + 1;
          if ( msg.m_bOverflow )
          {
            v80 = 0;
          }
          else
          {
            v27 = (v26 & CBitBuffer::s_nMaskTable[v24]) << m_nBitsAvail;
            msg.m_nBitsAvail = m_nBitsAvail;
            v80 = v27 | v25;
            msg.m_nInBufWord = v26 >> v24;
          }
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
          v80 = 0;
        }
      }
      else
      {
        msg.m_nBitsAvail = m_nBitsAvail - 32;
        if ( m_nBitsAvail == 32 )
        {
          msg.m_nBitsAvail = 32;
          if ( m_pDataIn == m_pBufferEnd )
          {
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            msg.m_pDataIn = m_pDataIn + 1;
            v80 = v21;
          }
          else
          {
            if ( m_pDataIn <= m_pBufferEnd )
            {
              msg.m_nInBufWord = *m_pDataIn;
              msg.m_pDataIn = m_pDataIn + 1;
            }
            else
            {
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
            v80 = v21;
          }
        }
        else
        {
          msg.m_nInBufWord = 0;
          v80 = v21;
        }
      }
      CBitRead::ReadString(this: &msg, pStr: name, maxLen: 256, bLine: false, pOutNumChars: nullptr);
      CBitRead::ReadString(this: &msg, pStr: password, maxLen: 256, bLine: false, pOutNumChars: nullptr);
      v28 = msg.m_nInBufWord;
      v29 = msg.m_pBufferEnd;
      v30 = msg.m_pDataIn;
      if ( msg.m_nBitsAvail < 8 )
      {
        v32 = 8 - msg.m_nBitsAvail;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          v30 = msg.m_pDataIn + 1;
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          msg.m_bOverflow = true;
          m_nInBufWord_low = 0;
        }
        else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          v30 = msg.m_pDataIn + 1;
          msg.m_nInBufWord = *msg.m_pDataIn++;
          if ( msg.m_bOverflow )
          {
            m_nInBufWord_low = 0;
          }
          else
          {
            v33 = (msg.m_nInBufWord & CBitBuffer::s_nMaskTable[v32]) << SLOBYTE(msg.m_nBitsAvail);
            msg.m_nBitsAvail = 32 - v32;
            msg.m_nInBufWord >>= v32;
            m_nInBufWord_low = v33 | v28;
          }
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
          m_nInBufWord_low = 0;
        }
      }
      else
      {
        m_nInBufWord_low = LOBYTE(msg.m_nInBufWord);
        msg.m_nBitsAvail -= 8;
        if ( msg.m_nBitsAvail != 0 )
        {
          msg.m_nInBufWord >>= 8;
        }
        else
        {
          msg.m_nBitsAvail = 32;
          if ( msg.m_pDataIn == msg.m_pBufferEnd )
          {
            v30 = msg.m_pDataIn + 1;
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            ++msg.m_pDataIn;
          }
          else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
          {
            v30 = msg.m_pDataIn + 1;
            msg.m_nInBufWord = *msg.m_pDataIn++;
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
          }
        }
      }
      memset(&splitScreenPlayers, 0, sizeof(splitScreenPlayers));
      if ( m_nInBufWord_low > 0 )
      {
        CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::InsertMultipleBefore(
          this: &splitScreenPlayers,
          elem: 0,
          num: m_nInBufWord_low);
        v34 = 0;
        do
        {
          if ( msg.m_nBitsAvail < 6 )
          {
            v35 = 6 - msg.m_nBitsAvail;
            if ( msg.m_pDataIn == msg.m_pBufferEnd )
            {
              msg.m_nBitsAvail = 1;
              msg.m_nInBufWord = 0;
              ++msg.m_pDataIn;
              msg.m_bOverflow = true;
            }
            else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
            {
              msg.m_nInBufWord = *msg.m_pDataIn++;
              if ( !msg.m_bOverflow )
              {
                msg.m_nInBufWord >>= v35;
                msg.m_nBitsAvail = 32 - v35;
              }
            }
            else
            {
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
          }
          else
          {
            msg.m_nBitsAvail -= 6;
            if ( msg.m_nBitsAvail != 0 )
            {
              msg.m_nInBufWord >>= 6;
            }
            else
            {
              msg.m_nBitsAvail = 32;
              if ( msg.m_pDataIn == msg.m_pBufferEnd )
              {
                msg.m_nBitsAvail = 1;
                msg.m_nInBufWord = 0;
                ++msg.m_pDataIn;
              }
              else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
              {
                msg.m_nInBufWord = *msg.m_pDataIn++;
              }
              else
              {
                msg.m_bOverflow = true;
                msg.m_nInBufWord = 0;
              }
            }
          }
          splitScreenPlayers.m_Memory.m_pMemory[v34].ReadFromBuffer(
            this: &splitScreenPlayers.m_Memory.m_pMemory[v34],
            a2: &msg);
          ++v34;
          --m_nInBufWord_low;
        }
        while ( m_nInBufWord_low != 0 );
        v30 = msg.m_pDataIn;
        v29 = msg.m_pBufferEnd;
      }
      v36 = msg.m_nInBufWord & 1;
      if ( --msg.m_nBitsAvail != 0 )
      {
        msg.m_nInBufWord >>= 1;
      }
      else
      {
        msg.m_nBitsAvail = 32;
        if ( v30 == v29 )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          msg.m_pDataIn = v30 + 1;
        }
        else if ( v30 <= v29 )
        {
          msg.m_nInBufWord = *v30;
          msg.m_pDataIn = v30 + 1;
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
        }
      }
      LOBYTE(isClientLowViolence) = v36 != 0;
      v37 = CBitRead::ReadLongLong(this: &msg);
      v38 = msg.m_nInBufWord;
      nReservationCookie = v37;
      if ( msg.m_nBitsAvail < 8 )
      {
        v40 = 8 - msg.m_nBitsAvail;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
          msg.m_bOverflow = true;
        }
        else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          v42 = *msg.m_pDataIn;
          msg.m_nInBufWord = *msg.m_pDataIn++;
          if ( !msg.m_bOverflow )
          {
            v43 = (v42 & CBitBuffer::s_nMaskTable[v40]) << SLOBYTE(msg.m_nBitsAvail);
            msg.m_nBitsAvail = 32 - v40;
            v39 = v43 | v38;
            msg.m_nInBufWord = v42 >> v40;
            goto LABEL_149;
          }
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
        }
LABEL_144:
        v41 = netadr_s::ToString(this: &packet->from, baseOnly: false);
        DevMsg(a1: "Rejecting connection request from %s, client's cross-play platform is unrecognized.\n", v41);
        v79->RejectConnection(this: v79, a2: (const netadr_s *)packet, a3: "Invalid cross-play platform id\n");
        CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: &splitScreenPlayers);
        return true;
      }
      v39 = LOBYTE(msg.m_nInBufWord);
      msg.m_nBitsAvail -= 8;
      if ( msg.m_nBitsAvail != 0 )
      {
        msg.m_nInBufWord >>= 8;
      }
      else
      {
        msg.m_nBitsAvail = 32;
        if ( msg.m_pDataIn == msg.m_pBufferEnd )
        {
          msg.m_nBitsAvail = 1;
          msg.m_nInBufWord = 0;
          ++msg.m_pDataIn;
        }
        else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
        {
          msg.m_nInBufWord = *msg.m_pDataIn++;
        }
        else
        {
          msg.m_bOverflow = true;
          msg.m_nInBufWord = 0;
        }
      }
LABEL_149:
      v82 = (const unsigned int *)v39;
      if ( v39 == 0 || v39 > 3 )
        goto LABEL_144;
      if ( netadr_s::IsLocalhost(this: &packet->from)
        || (IsLoopback = netadr_s::IsLoopback(this: &packet->from), bIsLocalConnection = false, IsLoopback) )
      {
        bIsLocalConnection = true;
      }
      v45 = v79;
      if ( v79->IsDedicated(this: v79) || !bIsLocalConnection )
      {
        IsExclusiveToLobbyConnections = CBaseServer::IsExclusiveToLobbyConnections(this: v45);
        v47 = nReservationCookie;
        if ( IsExclusiveToLobbyConnections && v45->m_nReservationCookie != nReservationCookie )
        {
          m_nReservationCookie = v45->m_nReservationCookie;
          v69 = nReservationCookie;
          v48 = netadr_s::ToString(this: &packet->from, baseOnly: false);
          DevMsg(
            a1: "Rejecting connection request from %s, client's reservation cookie %llx does not match servers's cookie %llx.\n",
            v48,
            v69,
            m_nReservationCookie);
          v45->RejectConnection(this: v45, a2: &packet->from, a3: "#Valve_Reject_Connect_From_Lobby");
          CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: &splitScreenPlayers);
          return true;
        }
        if ( CBaseServer::IsReserved(this: v45) )
        {
          v49 = v45->m_nReservationCookie;
          m_nReservationCookie_high = HIDWORD(v45->m_nReservationCookie);
          if ( __PAIR64__(m_nReservationCookie_high, v49) != v47 )
          {
            v72 = v45->m_flReservationExpiryTime - net_time;
            v70 = __PAIR64__(m_nReservationCookie_high, v49);
            v51 = netadr_s::ToString(this: &packet->from, baseOnly: false);
            DevMsg(
              a1: "Rejecting connection request from %s (reservation cookie 0x%llx), server is reserved with reservation cook"
              "ie 0x%llx for %.1f more seconds\n",
              v51,
              v47,
              v70,
              (double)v72);
            v45->RejectConnection(this: v45, a2: &packet->from, a3: "#Valve_Reject_Reserved_For_Lobby");
            CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: &splitScreenPlayers);
            return true;
          }
        }
      }
      v52 = v78;
      if ( v78 == 3 )
      {
        v53 = msg.m_nInBufWord;
        if ( msg.m_nBitsAvail < 16 )
        {
          v55 = 16 - msg.m_nBitsAvail;
          if ( msg.m_pDataIn == msg.m_pBufferEnd )
          {
            msg.m_nBitsAvail = 1;
            msg.m_nInBufWord = 0;
            ++msg.m_pDataIn;
            msg.m_bOverflow = true;
            v54 = 0;
          }
          else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
          {
            v56 = *msg.m_pDataIn;
            msg.m_nInBufWord = *msg.m_pDataIn++;
            if ( msg.m_bOverflow )
            {
              v54 = 0;
            }
            else
            {
              v57 = (v56 & CBitBuffer::s_nMaskTable[v55]) << SLOBYTE(msg.m_nBitsAvail);
              msg.m_nBitsAvail = 32 - v55;
              v54 = v57 | v53;
              msg.m_nInBufWord = v56 >> v55;
            }
          }
          else
          {
            msg.m_bOverflow = true;
            msg.m_nInBufWord = 0;
            v54 = 0;
          }
        }
        else
        {
          v54 = msg.m_nInBufWord;
          msg.m_nBitsAvail -= 16;
          if ( msg.m_nBitsAvail != 0 )
          {
            msg.m_nInBufWord >>= 16;
          }
          else
          {
            msg.m_nBitsAvail = 32;
            if ( msg.m_pDataIn == msg.m_pBufferEnd )
            {
              msg.m_nBitsAvail = 1;
              msg.m_nInBufWord = 0;
              ++msg.m_pDataIn;
            }
            else if ( msg.m_pDataIn <= msg.m_pBufferEnd )
            {
              msg.m_nInBufWord = *msg.m_pDataIn++;
            }
            else
            {
              msg.m_bOverflow = true;
              msg.m_nInBufWord = 0;
            }
          }
        }
        if ( (unsigned int)v54 > 0x800 )
        {
          v45->RejectConnection(this: v45, a2: &packet->from, a3: "Invalid Steam key length\n");
          CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: &splitScreenPlayers);
          return true;
        }
        CBitRead::ReadBytes(this: &msg, pOut: cdkey, nBytes: v54);
        v45->ConnectClient(
          this: v45,
          a2: &packet->from,
          a3: v81,
          a4: v80,
          a5: 3,
          a6: name,
          a7: password,
          a8: cdkey,
          a9: v54,
          a10: &splitScreenPlayers,
          a11: isClientLowViolence,
          a12: (CrossPlayPlatform_t)v82);
      }
      else
      {
        CBitRead::ReadString(this: &msg, pStr: cdkey, maxLen: 2048, bLine: false, pOutNumChars: nullptr);
        v45->ConnectClient(
          this: v45,
          a2: &packet->from,
          a3: v81,
          a4: v80,
          a5: v52,
          a6: name,
          a7: password,
          a8: cdkey,
          a9: strlen(cdkey),
          a10: &splitScreenPlayers,
          a11: isClientLowViolence,
          a12: (CrossPlayPlatform_t)v82);
      }
      CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>::~CUtlVector<CLC_SplitPlayerConnect,CUtlMemory<CLC_SplitPlayerConnect,int>>(this: &splitScreenPlayers);
      return true;
    case 108:
    case 116:
      return true;
    case 110:
      v79->ReplyReservationRequest(this: v79, a2: (netadr_s *)packet, a3: &msg);
      return true;
    case 113:
      v79->ReplyChallenge(this: v79, a2: (netadr_s *)packet, a3: &msg);
      return true;
    default:
      if ( IsUsingMasterLegacyMode() )
      {
        v61 = nullptr;
        if ( !v79->IsHLTV(this: v79) && !v79->IsReplay(this: v79) )
          v61 = (CGameServer *)v79;
        g_pMaster->HandleUnknown(this: g_pMaster, a2: packet, a3: v79, a4: v61);
        return true;
      }
      if ( Steam3Server()->m_pSteamMasterServerUpdater != nullptr )
      {
        v62 = Steam3Server();
        if ( CSteam3Server::IsMasterServerUpdaterSharingGameSocket(this: v62) )
        {
          m_pSteamMasterServerUpdater = Steam3Server()->m_pSteamMasterServerUpdater;
          v64 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)packet);
          isClientLowViolence = (unsigned int)v64;
          m_pData = packet->message.m_pData;
          v66 = m_pSteamMasterServerUpdater->__vftable;
          isClientLowViolence = packet->message.m_nDataBytes;
          v67 = _byteswap_ulong((unsigned int)v64);
          v82 = m_pData;
          Port = netadr_s::GetPort(this: &packet->from);
          v66->HandleIncomingPacket(
            this: m_pSteamMasterServerUpdater,
            a2: v82,
            a3: isClientLowViolence,
            a4: v67,
            a5: Port);
          CBaseServer::ForwardPacketsFromMasterServerUpdater(this: v79);
        }
      }
      return true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013AC50
// Name: public: virtual void CBaseServer::WriteTempEntities(class CBaseClient __near *,class CFrameSnapshot __near *,class CFrameSnapshot __near *,class bf_write __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::WriteTempEntities(
        CBaseServer *this,
        CBaseClient *client,
        unsigned int pCurrentSnapshot,
        CFrameSnapshot *pLastSnapshot,
        bf_write *buf,
        int ev_max)
{
  int v6; // ebx
  int m_nValue; // eax
  int v8; // esi
  int v9; // eax
  unsigned __int16 m_NumElements; // cx
  CBaseClient *v11; // edi
  CFrameSnapshot *v12; // esi
  bool v13; // cc
  CBaseClient_vtbl *v14; // edx
  unsigned __int16 v15; // ax
  unsigned __int16 v16; // dx
  unsigned int v17; // ecx
  UtlRBTreeNode_t<CEventInfo *,unsigned short> *m_pMemory; // eax
  unsigned int v19; // esi
  int v20; // edx
  CEventInfo **p_m_Data; // esi
  int v22; // edi
  unsigned __int16 v23; // ax
  CEventInfo *m_Data; // ebx
  float fire_delay; // xmm0_4
  int m_iCurBit; // ecx
  int v27; // eax
  int v28; // esi
  int v29; // esi
  CFrameSnapshot *v30; // eax
  unsigned int classID; // ecx
  int v32; // edi
  int v33; // edx
  CFrameSnapshot *v34; // eax
  bool v35; // zf
  unsigned __int8 *v36; // eax
  _BYTE pData[96000]; // [esp+Ch] [ebp-17798h] BYREF
  CReferencedSnapshotList list; // [esp+1770Ch] [ebp-98h] BYREF
  SVC_TempEntities v39; // [esp+17720h] [ebp-84h] BYREF
  CEventInfo *insert; // [esp+17774h] [ebp-30h] BYREF
  int v41; // [esp+17778h] [ebp-2Ch]
  CBaseServer *v42; // [esp+1777Ch] [ebp-28h]
  CFrameSnapshot *v43; // [esp+17780h] [ebp-24h]
  CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl*)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short> > v44; // [esp+17784h] [ebp-20h] BYREF
  bool v45; // [esp+177A3h] [ebp-1h]
  CBaseClient *i; // [esp+177ACh] [ebp+8h]

  v6 = 0;
  v42 = this;
  v39.m_NetChannel = nullptr;
  v39.__vftable = (SVC_TempEntities_vtbl *)&SVC_TempEntities::`vftable';
  v39.m_DataIn.m_bOverflow = false;
  v39.m_DataIn.m_pDebugName = nullptr;
  v39.m_DataIn.m_nDataBits = -1;
  v39.m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &v39.m_DataOut);
  v39.m_bReliable = false;
  bf_write::StartWriting(this: &v39.m_DataOut, pData, nBytes: 96000, iStartBit: 0, nBits: -1);
  if ( sv_debugtempentities.m_pParent != nullptr )
    m_nValue = sv_debugtempentities.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  v45 = m_nValue != 0;
  memset(&list, 0, sizeof(list));
  CFrameSnapshotManager::BuildSnapshotList(
    this: framesnapshotmanager,
    (CFrameSnapshot *)pCurrentSnapshot,
    pLastSnapshot,
    &list);
  v8 = ev_max;
  if ( ev_max >= 255 )
  {
    ev_max = 255;
    v8 = 255;
  }
  v44.m_LessFunc = CEventInfo_LessFunc;
  v44.m_Elements.m_pMemory = nullptr;
  v44.m_Elements.m_nAllocationCount = v8;
  v44.m_Elements.m_nGrowSize = 0;
  if ( v8 != 0 )
    v44.m_Elements.m_pMemory = (UtlRBTreeNode_t<CEventInfo *,unsigned short> *)_g_pMemAlloc->Alloc_2(
                                                                                 this: _g_pMemAlloc,
                                                                                 a2: 12 * v8);
  v9 = 0;
  m_NumElements = 0;
  *(_DWORD *)&v44.m_Root = 0xFFFF;
  *(_DWORD *)&v44.m_FirstFree = -1;
  v44.m_pElements = v44.m_Elements.m_pMemory;
  v41 = 0;
  if ( list.m_vecSnapshots.m_Size <= 0 )
    goto LABEL_67;
  v11 = client;
  while ( m_NumElements < v8 )
  {
    v12 = list.m_vecSnapshots.m_Memory.m_pMemory[v9];
    v13 = v12->m_nTempEntities <= 0;
    v43 = v12;
    if ( v13 )
      goto LABEL_25;
    while ( 1 )
    {
      v14 = v11->IGameEventListener2::__vftable;
      insert = v12->m_pTempEntities[v6];
      if ( !v14->IgnoreTempEntity(this: v11, a2: insert) )
        break;
LABEL_23:
      if ( ++v6 >= v12->m_nTempEntities )
        goto LABEL_24;
    }
    HIBYTE(pLastSnapshot) = 0;
    pCurrentSnapshot = 0xFFFF;
    CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::FindInsertionPosition(
      this: &v44,
      &insert,
      parent: (unsigned __int16 *)&pCurrentSnapshot,
      leftchild: (bool *)&pLastSnapshot + 3);
    v15 = CUtlRBTree<ConCommandBase const *,unsigned short,bool (__cdecl *)(ConCommandBase const * const &,ConCommandBase const * const &),CUtlMemory<UtlRBTreeNode_t<ConCommandBase const *,unsigned short>,unsigned short>>::NewNode(this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)&v44);
    v16 = pCurrentSnapshot;
    v17 = v15;
    m_pMemory = v44.m_Elements.m_pMemory;
    v19 = v17;
    v44.m_Elements.m_pMemory[v19].m_Right = -1;
    m_pMemory[v19].m_Left = -1;
    m_pMemory[v19].m_Tag = 0;
    m_pMemory[v19].m_Parent = v16;
    if ( v16 == 0xFFFF )
    {
      v44.m_Root = v17;
    }
    else
    {
      v20 = v16;
      if ( HIBYTE(pLastSnapshot) != 0 )
        m_pMemory[v20].m_Left = v17;
      else
        m_pMemory[v20].m_Right = v17;
    }
    CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::InsertRebalance(
      this: &v44,
      elem: v17);
    ++v44.m_NumElements;
    p_m_Data = &v44.m_Elements.m_pMemory[v19].m_Data;
    if ( p_m_Data != nullptr )
      *p_m_Data = insert;
    v11 = client;
    if ( v44.m_NumElements < ev_max )
    {
      v12 = v43;
      goto LABEL_23;
    }
LABEL_24:
    v9 = v41;
    m_NumElements = v44.m_NumElements;
LABEL_25:
    ++v9;
    v6 = 0;
    v41 = v9;
    if ( v9 < list.m_vecSnapshots.m_Size )
    {
      v8 = ev_max;
      continue;
    }
    break;
  }
  if ( m_NumElements != 0 )
  {
    v22 = 0;
    ev_max = 0;
    v23 = CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::FirstInorder(this: &v44);
    LOWORD(i) = v23;
    if ( v23 != 0xFFFF )
    {
      while ( 1 )
      {
        m_Data = v44.m_Elements.m_pMemory[v23].m_Data;
        fire_delay = m_Data->fire_delay;
        m_iCurBit = v39.m_DataOut.m_iCurBit;
        v43 = (CFrameSnapshot *)m_Data;
        v27 = v39.m_DataOut.m_iCurBit + 1;
        if ( fire_delay == 0.0 )
        {
          if ( v27 <= v39.m_DataOut.m_nDataBits )
          {
            if ( !v39.m_DataOut.m_bOverflow )
            {
              v39.m_DataOut.m_pData[v39.m_DataOut.m_iCurBit >> 3] &= ~(1 << (v39.m_DataOut.m_iCurBit & 7));
              m_iCurBit = ++v39.m_DataOut.m_iCurBit;
            }
          }
          else
          {
            v39.m_DataOut.m_bOverflow = true;
          }
        }
        else
        {
          if ( v27 <= v39.m_DataOut.m_nDataBits )
          {
            if ( !v39.m_DataOut.m_bOverflow )
              v39.m_DataOut.m_pData[v39.m_DataOut.m_iCurBit++ >> 3] |= 1 << (v39.m_DataOut.m_iCurBit & 7);
          }
          else
          {
            v39.m_DataOut.m_bOverflow = true;
          }
          bf_write::WriteSBitLong(this: &v39.m_DataOut, data: (int)(float)(m_Data->fire_delay * 100.0), numbits: 8);
          m_iCurBit = v39.m_DataOut.m_iCurBit;
        }
        if ( v22 != 0 && *(_WORD *)v22 == m_Data->classID )
        {
          if ( m_iCurBit + 1 <= v39.m_DataOut.m_nDataBits )
          {
            if ( !v39.m_DataOut.m_bOverflow )
            {
              v39.m_DataOut.m_pData[m_iCurBit >> 3] &= ~(1 << (m_iCurBit & 7));
              m_iCurBit = ++v39.m_DataOut.m_iCurBit;
            }
          }
          else
          {
            v39.m_DataOut.m_bOverflow = true;
          }
          v28 = v45 ? m_iCurBit : 0;
          SendTable_WriteAllDeltaProps(
            pTable: m_Data->pSendTable,
            pFromData: *(const void **)(v22 + 20),
            nFromDataBits: *(_DWORD *)(v22 + 16),
            pToData: m_Data->pData,
            nToDataBits: m_Data->bits,
            nObjectID: -1,
            pBufOut: &v39.m_DataOut);
          if ( v45 )
            DevMsg(a1: "TE %s delta bits: %i\n", m_Data->pSendTable->m_pNetTableName, v39.m_DataOut.m_iCurBit - v28);
        }
        else
        {
          if ( m_iCurBit + 1 <= v39.m_DataOut.m_nDataBits )
          {
            if ( !v39.m_DataOut.m_bOverflow )
            {
              v39.m_DataOut.m_pData[m_iCurBit >> 3] |= 1 << (m_iCurBit & 7);
              m_iCurBit = ++v39.m_DataOut.m_iCurBit;
            }
          }
          else
          {
            v39.m_DataOut.m_bOverflow = true;
          }
          v29 = v45 ? m_iCurBit : 0;
          v30 = (CFrameSnapshot *)v42->GetClassBits(this: v42);
          classID = m_Data->classID;
          pLastSnapshot = v30;
          pCurrentSnapshot = classID;
          if ( (int)v30 + v39.m_DataOut.m_iCurBit <= v39.m_DataOut.m_nDataBits )
          {
            v32 = v39.m_DataOut.m_iCurBit & 0x1F;
            v33 = v39.m_DataOut.m_iCurBit >> 5;
            *(_DWORD *)&v39.m_DataOut.m_pData[4 * (v39.m_DataOut.m_iCurBit >> 5)] = (classID << (v39.m_DataOut.m_iCurBit
                                                                                               & 0x1F))
                                                                                  | *(_DWORD *)&v39.m_DataOut.m_pData[4 * (v39.m_DataOut.m_iCurBit >> 5)]
                                                                                  & g_BitWriteMasks[0][(_DWORD)v30 + 32 * v32 + v32];
            v34 = pLastSnapshot;
            if ( 32 - v32 < (int)pLastSnapshot )
              *(_DWORD *)&v39.m_DataOut.m_pData[4 * v33 + 4] = (pCurrentSnapshot >> (32 - v32))
                                                             | *(_DWORD *)&v39.m_DataOut.m_pData[4 * v33 + 4]
                                                             & g_BitWriteMasks[0][(_DWORD)pLastSnapshot - (32 - v32)];
            v39.m_DataOut.m_iCurBit += (int)v34;
            m_Data = (CEventInfo *)v43;
          }
          else
          {
            v39.m_DataOut.m_iCurBit = v39.m_DataOut.m_nDataBits;
            v39.m_DataOut.m_bOverflow = true;
          }
          v35 = !v42->IsMultiplayer(this: v42);
          v36 = m_Data->pData;
          if ( v35 )
            bf_write::WriteBits(this: &v39.m_DataOut, pInData: v36, nBits: m_Data->bits);
          else
            SendTable_WriteAllDeltaProps(
              pTable: m_Data->pSendTable,
              pFromData: nullptr,
              nFromDataBits: 0,
              pToData: v36,
              nToDataBits: m_Data->bits,
              nObjectID: -1,
              pBufOut: &v39.m_DataOut);
          if ( v45 )
            DevMsg(a1: "TE %s full bits: %i\n", m_Data->pSendTable->m_pNetTableName, v39.m_DataOut.m_iCurBit - v29);
          v22 = ev_max;
        }
        if ( v42->IsMultiplayer(this: v42) )
        {
          ev_max = (int)m_Data;
          v22 = (int)m_Data;
        }
        i = (CBaseClient *)(unsigned __int16)CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::NextInorder(
                                               this: &v44,
                                               (unsigned __int16)i);
        if ( i == (CBaseClient *)0xFFFF )
          break;
        v23 = (unsigned __int16)i;
      }
    }
    v39.m_nNumEntries = v44.m_NumElements;
    SVC_TempEntities::WriteToBuffer(this: &v39, buffer: buf);
  }
LABEL_67:
  CUtlRBTree<CEventInfo *,unsigned short,bool (__cdecl *)(CEventInfo * const &,CEventInfo * const &),CUtlMemory<UtlRBTreeNode_t<CEventInfo *,unsigned short>,unsigned short>>::RemoveAll(this: &v44);
  if ( v44.m_Elements.m_nGrowSize >= 0 && v44.m_Elements.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v44.m_Elements.m_pMemory);
  CReferencedSnapshotList::~CReferencedSnapshotList(this: &list);
}

//------------------------------------------------------------------------------
// Address: 0x1013B190
// Name: private: void CBaseServer::AddTagString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::AddTagString(CBaseServer *this, char *pchString)
{
  const char *v2; // esi
  CUtlString *i; // edi
  CUtlString *m_pMemory; // esi
  const char *v6; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > list; // [esp+Ch] [ebp-14h] BYREF
  bool bHadAsterisk_3; // [esp+2Bh] [ebp+Bh]

  v2 = pchString;
  i = nullptr;
  if ( pchString != nullptr )
  {
    if ( _V_strstr(s1: pchString, search: ",") != nullptr )
    {
      memset(&list, 0, sizeof(list));
      BuildTokenList(
        (CUtlMemory<UtlLinkedListElem_t<vgui::PanelListPanel::dataitem_s,int>,int> *)&list,
        pchString,
        chDelim: 0x2Cu);
      if ( list.m_Size > 0 )
      {
        m_pMemory = list.m_Memory.m_pMemory;
        for ( i = (CUtlString *)list.m_Size; i != nullptr; i = (CUtlString *)((char *)i - 1) )
        {
          v6 = CUtlString::operator char const *(this: m_pMemory);
          CBaseServer::AddTagString(this, pchString: v6);
          ++m_pMemory;
        }
      }
      CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: (CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int> > *)&list);
      if ( list.m_Memory.m_nGrowSize >= (int)i && list.m_Memory.m_pMemory != i )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
    }
    else
    {
      bHadAsterisk_3 = *pchString == 42;
      if ( *v2 == 42 )
        ++v2;
      CUtlString::operator+=(this: &this->m_GameTypePrivate, rhs: v2);
      CUtlString::operator+=(this: &this->m_GameTypePrivate, rhs: ",");
      if ( !bHadAsterisk_3 )
      {
        CUtlString::operator+=(this: &this->m_GameTypePublic, rhs: v2);
        CUtlString::operator+=(this: &this->m_GameTypePublic, rhs: ",");
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1013B280
// Name: public: void CBaseServer::UpdateGameType(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::UpdateGameType(CBaseServer *this)
{
  int NumHumanPlayers; // eax
  bool v3; // bl
  int v4; // edi
  char *m_pszString; // edi
  int HostVersion; // eax
  char *v7; // eax
  ISteamGameServer *m_pSteamGameServer; // esi
  const char *v9; // eax
  char szMatchMakingTags[1024]; // [esp+8h] [ebp-414h] BYREF
  CUtlString tags; // [esp+408h] [ebp-14h] BYREF
  CUtlString *p_m_GameTypePrivate; // [esp+418h] [ebp-4h]

  CUtlString::operator=(this: &this->m_GameTypePublic, src: defaultValue);
  p_m_GameTypePrivate = &this->m_GameTypePrivate;
  CUtlString::operator=(this: &this->m_GameTypePrivate, src: defaultValue);
  CUtlString::CUtlString(this: &tags);
  if ( serverGameDLL != nullptr )
  {
    memset(szMatchMakingTags, 0, sizeof(szMatchMakingTags));
    serverGameDLL->GetMatchmakingTags(this: serverGameDLL, a2: szMatchMakingTags, a3: 1024u);
    if ( szMatchMakingTags[0] != 0 )
      CBaseServer::AddTagString(this, pchString: szMatchMakingTags);
  }
  NumHumanPlayers = CBaseServer::GetNumHumanPlayers(this);
  v3 = NumHumanPlayers > 0;
  if ( NumHumanPlayers <= 0 )
    CBaseServer::AddTagString(this, pchString: "empty");
  if ( (_S2_9 & 1) == 0 )
  {
    _S2_9 |= 1u;
    ConVarRef::ConVarRef(this: &var, pName: "sv_tags");
  }
  if ( ConVarRef::IsValid(this: &var) && *var.m_pConVarState->m_Value.m_pszString != 0 )
    CBaseServer::AddTagString(this, pchString: var.m_pConVarState->m_Value.m_pszString);
  if ( this->IsDedicated(this) && !this->m_bIsDedicatedForXbox && !v3 && this->m_nReservationCookie == 0 )
  {
    v4 = this->GetNumFakeClients(this);
    if ( this->GetNumClients(this) == v4
      && (sv_steamgroup_exclusive.m_pParent == nullptr || sv_steamgroup_exclusive.m_pParent->m_Value.m_nValue == 0) )
    {
      if ( (sv_search_key.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = sv_search_key.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      HostVersion = GetHostVersion();
      v7 = va(format: "*sv_search_key_%s%d", m_pszString, HostVersion);
      CBaseServer::AddTagString(this, pchString: v7);
    }
  }
  if ( Steam3Server()->m_pSteamGameServer != nullptr )
  {
    m_pSteamGameServer = Steam3Server()->m_pSteamGameServer;
    v9 = CUtlString::operator char const *(this: p_m_GameTypePrivate);
    m_pSteamGameServer->SetGameTags(this: m_pSteamGameServer, a2: v9);
  }
  tags.m_Storage.m_nActualLength = 0;
  if ( tags.m_Storage.m_Memory.m_nGrowSize >= 0 && tags.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: tags.m_Storage.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1013B460
// Name: SvTagsChangeCallback
// Source: json
//------------------------------------------------------------------------------
void __cdecl SvTagsChangeCallback()
{
  CBaseServer::UpdateGameType(this: &sv);
  if ( sv.m_State >= ss_active )
    Cbuf_AddText(eTarget: CBUF_SERVER, pText: "heartbeat\n", nTickDelay: 0);
  ServerTagsCleanUp();
}

//------------------------------------------------------------------------------
// Address: 0x1013B490
// Name: public: void CBaseServer::SetReservationCookie(unsigned __int64,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CBaseServer::SetReservationCookie(CBaseServer *this, unsigned __int64 uiCookie, const char *pchReasonFormat, ...)
{
  unsigned int v3; // ebx
  CBaseServer *v4; // esi
  unsigned int v5; // edi
  char reason[256]; // [esp+Ch] [ebp-100h] BYREF
  va_list params; // [esp+124h] [ebp+18h] BYREF

  va_start(params, pchReasonFormat);
  v3 = HIDWORD(uiCookie);
  v4 = this;
  v5 = uiCookie;
  if ( uiCookie != this->m_nReservationCookie )
  {
    memset(reason, 0, sizeof(reason));
    V_vsnprintf(pDest: reason, maxLen: 256, pFormat: pchReasonFormat, params);
    this = (CBaseServer *)-65281;
    ConColorMsg(
      a1: (const struct Color *)&this,
      a2: "-> Reservation cookie %llx:  reason %s\n",
      __PAIR64__(v3, v5),
      reason);
  }
  LODWORD(v4->m_nReservationCookie) = v5;
  HIDWORD(v4->m_nReservationCookie) = v3;
  CBaseServer::UpdateGameType(this: v4);
  if ( v4->m_nReservationCookie != 0 )
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_hosting_lobby.IConVar, value: 1);
  else
    CLoaderMemAlloc::CrtIsValidPointer(this: (ConVar *)&sv_hosting_lobby.IConVar, value: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1013B560
// Name: protected: virtual void CBaseServer::ReplyReservationRequest(struct netadr_s __near &,class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::ReplyReservationRequest(CBaseServer *this, netadr_s *adr, bf_read *msgIn)
{
  int m_nBitsAvail; // ecx
  unsigned int v5; // eax
  int v6; // ecx
  int v7; // ebx
  const unsigned int *v8; // ecx
  const unsigned int *v9; // edx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // ebx
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  const char *v16; // eax
  int v17; // eax
  int (__thiscall *GetNumClients)(struct CBaseServer *); // edx
  const char *v19; // eax
  float v20; // edi
  const char *v21; // eax
  const char *v22; // eax
  int v23; // ecx
  unsigned int v24; // eax
  int v25; // ecx
  int v26; // ebx
  const unsigned int *v27; // ecx
  const unsigned int *v28; // edx
  const unsigned int *v29; // edx
  unsigned int v30; // ebx
  int v31; // eax
  const unsigned int *v32; // ecx
  const char *v33; // eax
  unsigned int v34; // edx
  unsigned int v35; // edi
  unsigned __int8 *v36; // edi
  unsigned int v37; // ebx
  int v38; // ecx
  unsigned int v39; // eax
  int v40; // ecx
  int v41; // edi
  const unsigned int *v42; // ecx
  const unsigned int *v43; // edx
  const unsigned int *v44; // edx
  unsigned int v45; // edi
  int v46; // eax
  const unsigned int *v47; // ecx
  unsigned int v48; // edx
  unsigned int v49; // ebx
  const char *v50; // eax
  unsigned __int64 LongLong; // rax
  int v52; // ecx
  unsigned int v53; // eax
  int v54; // ecx
  int v55; // edi
  const unsigned int *v56; // ecx
  const unsigned int *v57; // edx
  const unsigned int *v58; // edx
  unsigned int v59; // ebx
  int v60; // eax
  const unsigned int *v61; // ecx
  unsigned int v62; // edx
  unsigned int v63; // edi
  double m_fValue; // st7
  const char *v65; // eax
  unsigned __int64 v66; // rax
  CBaseServer *v67; // ebx
  KeyValues *v68; // eax
  KeyValues *v69; // ebx
  int Int; // eax
  CBaseServer *v71; // eax
  unsigned __int64 v72; // [esp-4h] [ebp-6C4h]
  int v73; // [esp+8h] [ebp-6B8h]
  const char *v74; // [esp+8h] [ebp-6B8h]
  int v75; // [esp+8h] [ebp-6B8h]
  unsigned __int8 decrypted[1024]; // [esp+18h] [ebp-6A8h] BYREF
  unsigned __int8 tmp[600]; // [esp+418h] [ebp-2A8h] BYREF
  CUtlBuffer buf; // [esp+670h] [ebp-50h] BYREF
  IceKey cipher; // [esp+6A0h] [ebp-20h] BYREF
  unsigned __int8 key[4]; // [esp+6ACh] [ebp-14h] BYREF
  float flExpiryTime; // [esp+6B0h] [ebp-10h]
  unsigned __int64 nReservationCookie; // [esp+6B4h] [ebp-Ch]
  CBaseServer *v83; // [esp+6BCh] [ebp-4h]
  char bAccepted_3; // [esp+6CFh] [ebp+Fh]

  v83 = this;
  m_nBitsAvail = msgIn->m_nBitsAvail;
  if ( m_nBitsAvail < 32 )
  {
    m_pBufferEnd = msgIn->m_pBufferEnd;
    m_nInBufWord = msgIn->m_nInBufWord;
    v12 = 32 - m_nBitsAvail;
    m_pDataIn = msgIn->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msgIn->m_nBitsAvail = 1;
      msgIn->m_nInBufWord = 0;
      msgIn->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msgIn->m_bOverflow = true;
        msgIn->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msgIn->m_nInBufWord = *m_pDataIn;
    }
    msgIn->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msgIn->m_bOverflow )
    {
      v7 = 0;
    }
    else
    {
      v14 = msgIn->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << msgIn->m_nBitsAvail;
      msgIn->m_nBitsAvail = 32 - v12;
      v7 = v15 | m_nInBufWord;
      msgIn->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v5 = msgIn->m_nInBufWord;
  v6 = m_nBitsAvail - 32;
  msgIn->m_nBitsAvail = v6;
  if ( v6 != 0 )
  {
    msgIn->m_nInBufWord = 0;
    v7 = v5;
  }
  else
  {
    v8 = msgIn->m_pDataIn;
    v9 = msgIn->m_pBufferEnd;
    msgIn->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msgIn->m_nBitsAvail = 1;
      msgIn->m_nInBufWord = 0;
      msgIn->m_pDataIn = v8 + 1;
      v7 = v5;
    }
    else
    {
      if ( v8 <= v9 )
      {
        msgIn->m_nInBufWord = *v8;
        msgIn->m_pDataIn = v8 + 1;
      }
      else
      {
        msgIn->m_bOverflow = true;
        msgIn->m_nInBufWord = 0;
      }
      v7 = v5;
    }
  }
LABEL_19:
  if ( v7 != GetHostVersion() )
    return;
  bAccepted_3 = 0;
  if ( v83->m_nReservationCookie != 0 )
  {
    v73 = (int)(v83->m_flReservationExpiryTime - net_time);
    v16 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Reservation request from %s rejected: server already reserved (for %d more seconds)\n", v16, v73);
    goto LABEL_99;
  }
  v17 = v83->GetNumFakeClients(this: v83);
  GetNumClients = v83->GetNumClients;
  HIDWORD(nReservationCookie) = v17;
  if ( GetNumClients(this: v83) - v17 > 0 )
  {
    v19 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Reservation request from %s rejected: server not empty\n", v19);
    goto LABEL_99;
  }
  if ( v83->m_bIsDedicatedForXbox )
  {
LABEL_73:
    LongLong = CBitRead::ReadLongLong(this: msgIn);
    v52 = msgIn->m_nBitsAvail;
    nReservationCookie = LongLong;
    if ( v52 >= 32 )
    {
      v53 = msgIn->m_nInBufWord;
      v54 = v52 - 32;
      msgIn->m_nBitsAvail = v54;
      if ( v54 != 0 )
      {
        msgIn->m_nInBufWord = 0;
        v55 = v53;
      }
      else
      {
        v56 = msgIn->m_pDataIn;
        v57 = msgIn->m_pBufferEnd;
        msgIn->m_nBitsAvail = 32;
        if ( v56 == v57 )
        {
          msgIn->m_nInBufWord = 0;
          msgIn->m_nBitsAvail = 1;
          msgIn->m_pDataIn = v56 + 1;
          v55 = v53;
        }
        else
        {
          if ( v56 <= v57 )
          {
            msgIn->m_nInBufWord = *v56;
            msgIn->m_pDataIn = v56 + 1;
          }
          else
          {
            msgIn->m_nInBufWord = 0;
            msgIn->m_bOverflow = true;
          }
          v55 = v53;
        }
      }
LABEL_91:
      m_fValue = sv_reservation_timeout.m_pParent->m_Value.m_fValue;
      flExpiryTime = sv_reservation_timeout.m_pParent->m_Value.m_fValue;
      v72 = nReservationCookie;
      v65 = netadr_s::ToString(this: adr, baseOnly: false);
      DevMsg(
        a1: "Reservation request from %s accepted: server reserved with reservation cookie 0x%llx for %.1f seconds\n",
        v65,
        v72,
        m_fValue);
      DevMsg(a1: "            settings size = %d\n", v55);
      v66 = nReservationCookie;
      v67 = v83;
      v83->m_flReservationExpiryTime = flExpiryTime + net_time;
      bAccepted_3 = 1;
      CBaseServer::SetReservationCookie(this: v67, uiCookie: v66, pchReasonFormat: "ReplyReservationRequest");
      v67->m_numGameSlots = 0;
      if ( v55 > 0 )
      {
        v68 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v68 != nullptr )
          v69 = KeyValues::KeyValues(this: v68, setName: defaultValue);
        else
          v69 = nullptr;
        if ( (unsigned int)v55 <= 0x258 )
        {
          CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
          CBitRead::ReadBytes(this: msgIn, pOut: tmp, nBytes: v55);
          CUtlBuffer::Put(this: &buf, pMem: tmp, size: v55);
          KeyValues::ReadAsBinary(this: v69, buffer: &buf);
          serverGameDLL->ApplyGameSettings(this: serverGameDLL, a2: v69);
          Int = KeyValues::GetInt(this: v69, keyName: "members/numSlots", defaultValue: 0);
          v83->m_numGameSlots = Int;
          CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>::~CUtlMemory<UtlRBTreeNode_t<CUtlMap<char const *,int,unsigned short>::Node_t,unsigned short>,unsigned short>(this: &buf);
        }
        if ( v69 != nullptr )
          KeyValues::deleteThis(this: v69);
      }
      goto LABEL_99;
    }
    v58 = msgIn->m_pBufferEnd;
    v59 = msgIn->m_nInBufWord;
    v60 = 32 - v52;
    v61 = msgIn->m_pDataIn;
    if ( v61 == v58 )
    {
      msgIn->m_nBitsAvail = 1;
      msgIn->m_nInBufWord = 0;
      msgIn->m_bOverflow = true;
    }
    else
    {
      if ( v61 > v58 )
      {
        msgIn->m_bOverflow = true;
        msgIn->m_nInBufWord = 0;
        goto LABEL_88;
      }
      msgIn->m_nInBufWord = *v61;
    }
    msgIn->m_pDataIn = v61 + 1;
LABEL_88:
    if ( msgIn->m_bOverflow )
    {
      v55 = 0;
    }
    else
    {
      v62 = msgIn->m_nInBufWord;
      v63 = (v62 & CBitBuffer::s_nMaskTable[v60]) << msgIn->m_nBitsAvail;
      msgIn->m_nBitsAvail = 32 - v60;
      v55 = v59 | v63;
      msgIn->m_nInBufWord = v62 >> v60;
    }
    goto LABEL_91;
  }
  v20 = COERCE_FLOAT(v83->GetChallengeNr(this: v83, a2: adr));
  flExpiryTime = v20;
  if ( !CBaseServer::CanAcceptChallengesFrom(this: v83, adrFrom: adr) )
  {
    v74 = netadr_s::ToString(this: &v83->m_adrReservationGraceStarted, baseOnly: false);
    v21 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Reservation request from address %s, but challenges exclusive for %s\n", v21, v74);
    goto LABEL_99;
  }
  if ( v20 == 0.0 )
  {
    v22 = netadr_s::ToString(this: adr, baseOnly: false);
    DevMsg(a1: "Reservation request from unknown address %s\n", v22);
    goto LABEL_99;
  }
  v23 = msgIn->m_nBitsAvail;
  if ( v23 >= 32 )
  {
    v24 = msgIn->m_nInBufWord;
    v25 = v23 - 32;
    msgIn->m_nBitsAvail = v25;
    if ( v25 != 0 )
    {
      msgIn->m_nInBufWord = 0;
      v26 = v24;
    }
    else
    {
      v27 = msgIn->m_pDataIn;
      v28 = msgIn->m_pBufferEnd;
      msgIn->m_nBitsAvail = 32;
      if ( v27 == v28 )
      {
        msgIn->m_nInBufWord = 0;
        msgIn->m_nBitsAvail = 1;
        msgIn->m_pDataIn = v27 + 1;
        v26 = v24;
      }
      else
      {
        if ( v27 <= v28 )
        {
          msgIn->m_nInBufWord = *v27;
          msgIn->m_pDataIn = v27 + 1;
        }
        else
        {
          msgIn->m_nInBufWord = 0;
          msgIn->m_bOverflow = true;
        }
        v26 = v24;
      }
    }
    goto LABEL_48;
  }
  v29 = msgIn->m_pBufferEnd;
  v30 = msgIn->m_nInBufWord;
  v31 = 32 - v23;
  v32 = msgIn->m_pDataIn;
  if ( v32 == v29 )
  {
    msgIn->m_nBitsAvail = 1;
    msgIn->m_nInBufWord = 0;
    msgIn->m_bOverflow = true;
LABEL_43:
    msgIn->m_pDataIn = v32 + 1;
    goto LABEL_44;
  }
  if ( v32 <= v29 )
  {
    msgIn->m_nInBufWord = *v32;
    goto LABEL_43;
  }
  msgIn->m_bOverflow = true;
  msgIn->m_nInBufWord = 0;
LABEL_44:
  if ( msgIn->m_bOverflow )
  {
    v26 = 0;
    goto LABEL_46;
  }
  v34 = msgIn->m_nInBufWord;
  v35 = (v34 & CBitBuffer::s_nMaskTable[v31]) << msgIn->m_nBitsAvail;
  msgIn->m_nBitsAvail = 32 - v31;
  v26 = v35 | v30;
  v20 = flExpiryTime;
  msgIn->m_nInBufWord = v34 >> v31;
LABEL_48:
  HIDWORD(nReservationCookie) = v26;
  if ( v26 > 0 && (unsigned int)v26 <= 0x400 && (v26 & 0x80000007) == 0 )
  {
    IceKey::IceKey(this: &cipher, n: 1);
    *(_DWORD *)key = LODWORD(v20) ^ 0x5EF8CE12;
    LODWORD(flExpiryTime) = LODWORD(v20) ^ 0xAA98E42C;
    IceKey::set(this: &cipher, key);
    CBitRead::ReadBytes(this: msgIn, pOut: decrypted, nBytes: v26);
    v36 = decrypted;
    v37 = ((unsigned int)(HIDWORD(nReservationCookie) - 1) >> 3) + 1;
    do
    {
      IceKey::decrypt(this: &cipher, ctext: v36, ptext: v36);
      v36 += 8;
      --v37;
    }
    while ( v37 != 0 );
    CBitRead::StartReading(this: msgIn, pData: decrypted, nBytes: SHIDWORD(nReservationCookie), iStartBit: 0, nBits: -1);
    v38 = msgIn->m_nBitsAvail;
    if ( v38 >= 32 )
    {
      v39 = msgIn->m_nInBufWord;
      v40 = v38 - 32;
      msgIn->m_nBitsAvail = v40;
      if ( v40 != 0 )
      {
        msgIn->m_nInBufWord = 0;
        v41 = v39;
      }
      else
      {
        v42 = msgIn->m_pDataIn;
        v43 = msgIn->m_pBufferEnd;
        msgIn->m_nBitsAvail = 32;
        if ( v42 == v43 )
        {
          msgIn->m_nBitsAvail = 1;
          msgIn->m_nInBufWord = 0;
          msgIn->m_pDataIn = v42 + 1;
          v41 = v39;
        }
        else
        {
          if ( v42 <= v43 )
          {
            msgIn->m_nInBufWord = *v42;
            msgIn->m_pDataIn = v42 + 1;
          }
          else
          {
            msgIn->m_bOverflow = true;
            msgIn->m_nInBufWord = 0;
          }
          v41 = v39;
        }
      }
      goto LABEL_70;
    }
    v44 = msgIn->m_pBufferEnd;
    v45 = msgIn->m_nInBufWord;
    v46 = 32 - v38;
    v47 = msgIn->m_pDataIn;
    if ( v47 == v44 )
    {
      msgIn->m_nBitsAvail = 1;
      msgIn->m_nInBufWord = 0;
      msgIn->m_bOverflow = true;
    }
    else
    {
      if ( v47 > v44 )
      {
        msgIn->m_bOverflow = true;
        msgIn->m_nInBufWord = 0;
LABEL_68:
        if ( !msgIn->m_bOverflow )
        {
          v48 = msgIn->m_nInBufWord;
          v49 = (v48 & CBitBuffer::s_nMaskTable[v46]) << msgIn->m_nBitsAvail;
          msgIn->m_nBitsAvail = 32 - v46;
          v41 = v49 | v45;
          msgIn->m_nInBufWord = v48 >> v46;
LABEL_70:
          if ( v41 == -17973521 )
          {
LABEL_72:
            IceKey::~IceKey(this: &cipher);
            goto LABEL_73;
          }
        }
        v75 = HIDWORD(nReservationCookie);
        v50 = netadr_s::ToString(this: adr, baseOnly: false);
        _Msg(a1: "ReplyReservationRequest:  Reservation request with bogus payload data from %s [%d bytes]\n", v50, v75);
        goto LABEL_72;
      }
      msgIn->m_nInBufWord = *v47;
    }
    msgIn->m_pDataIn = v47 + 1;
    goto LABEL_68;
  }
LABEL_46:
  v33 = netadr_s::ToString(this: adr, baseOnly: false);
  DevMsg(a1: "ReplyReservationRequest:  Reservation request with bogus payload size from %s [%d bytes]\n", v33, v26);
LABEL_99:
  v71 = v83;
  v83->m_ReservationStatus.m_bActive = true;
  v71->m_ReservationStatus.m_bSuccess = bAccepted_3;
  v71->m_ReservationStatus.m_Remote = *adr;
  if ( bAccepted_3 == 0 )
    CBaseServer::SendReservationStatus(this: v71);
}

//------------------------------------------------------------------------------
// Address: 0x101CED20
// Name: public: virtual void CBaseServer::RemoveClientFromGame(class CBaseClient __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseServer::RemoveClientFromGame(vgui::Panel *this, const char *panelName)
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x101FF4D0
// Name: protected: virtual bool CBaseServer::ShouldUpdateMasterServer(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseServer::ShouldUpdateMasterServer(vgui::Splitter *this)
{
  return 1;
}

} // namespace engine_xlsp
