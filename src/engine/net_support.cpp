// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/net_support.cpp
// Functions: 14
// ============================================================

#include "engine\net_support.h"

//------------------------------------------------------------------------------
// Address: 0x1006E390
// Name: public: virtual int CNetSupportImpl::GetEngineBuildNumber(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CNetSupportImpl::GetEngineBuildNumber(CEngineClient *this)
{
  return GetHostVersion();
}

//------------------------------------------------------------------------------
// Address: 0x101B3CD0
// Name: InternalFactory
// Source: json
//------------------------------------------------------------------------------
void *__cdecl InternalFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( s_pfnDelegateFactory == nullptr || (result = s_pfnDelegateFactory(a1: pName, a2: pReturnCode)) == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    result = FactoryThis(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B3D20
// Name: public: virtual bool CNetSupportImpl::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetSupportImpl::Connect(CNetSupportImpl *this, void *(__cdecl *factory)(const char *, int *))
{
  s_pfnDelegateFactory = factory;
  factory = InternalFactory;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  s_pfnDelegateFactory = nullptr;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B3D60
// Name: public: virtual void CNetSupportImpl::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::Disconnect(CNetSupportImpl *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x101B3D70
// Name: public: virtual void __near * CNetSupportImpl::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNetSupportImpl *__thiscall CNetSupportImpl::QueryInterface(CNetSupportImpl *this, const char *pInterfaceName)
{
  return _V_stricmp(s1: pInterfaceName, s2: "INETSUPPORT_002") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101B3DA0
// Name: public: virtual void CNetSupportImpl::GetClientInfo(struct INetSupport::ClientInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::GetClientInfo(CNetSupportImpl *this, INetSupport::ClientInfo_t *pClientInfo)
{
  CClientState *BaseLocalClient; // edi
  int v3; // eax
  int v4; // ebx
  player_info_s pi; // [esp+4h] [ebp-90h] BYREF

  if ( pClientInfo != nullptr )
  {
    pClientInfo->m_nSignonState = 0;
    pClientInfo->m_nSocket = 0;
    pClientInfo->m_pNetChannel = nullptr;
    pClientInfo->m_numHumanPlayers = 0;
    BaseLocalClient = GetBaseLocalClient();
    pClientInfo->m_nSignonState = BaseLocalClient->m_nSignonState;
    pClientInfo->m_nSocket = BaseLocalClient->m_Socket;
    pClientInfo->m_pNetChannel = BaseLocalClient->m_NetChannel;
    pClientInfo->m_numHumanPlayers = 0;
    if ( BaseLocalClient->m_nSignonState >= 2 && BaseLocalClient->m_pUserInfoTable != nullptr )
    {
      v3 = 0;
      if ( BaseLocalClient->m_nMaxClients > 0 )
      {
        do
        {
          v4 = v3 + 1;
          if ( engineClient->GetPlayerInfo(this: engineClient, a2: v3 + 1, a3: &pi) && !pi.fakeplayer && !pi.ishltv )
            ++pClientInfo->m_numHumanPlayers;
          v3 = v4;
        }
        while ( v4 < BaseLocalClient->m_nMaxClients );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3E40
// Name: public: virtual void CNetSupportImpl::UpdateClientReservation(unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::UpdateClientReservation(
        CNetSupportImpl *this,
        unsigned __int64 uiReservation,
        unsigned __int64 uiMachineIdHost)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  ((void (__thiscall *)(CClientState *, _DWORD, _DWORD))BaseLocalClient->SetServerReservationCookie)(
    a1: BaseLocalClient,
    a2: uiReservation,
    a3: HIDWORD(uiReservation));
  GetBaseLocalClient()->m_ListenServerSteamID = uiMachineIdHost;
}

//------------------------------------------------------------------------------
// Address: 0x101B3E70
// Name: public: virtual void CNetSupportImpl::UpdateServerReservation(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::UpdateServerReservation(CNetSupportImpl *this, unsigned __int64 uiReservation)
{
  CBaseServer::SetReservationCookie(this: &sv, uiCookie: uiReservation, pchReasonFormat: "netsupport");
}

//------------------------------------------------------------------------------
// Address: 0x101B3EA0
// Name: public: virtual void CNetSupportImpl::ReserveServer(struct netadr_s const __near &,struct netadr_s const __near &,unsigned __int64,class KeyValues __near *,class IMatchAsyncOperationCallback __near *,class IMatchAsyncOperation __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::ReserveServer(
        CNetSupportImpl *this,
        const netadr_s *netAdrPublic,
        const netadr_s *netAdrPrivate,
        unsigned __int64 nServerReservationCookie,
        KeyValues *pKVGameSettings,
        IMatchAsyncOperationCallback *pCallback,
        IMatchAsyncOperation **ppAsyncOperation)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  ((void (__thiscall *)(CClientState *, const netadr_s *, const netadr_s *, _DWORD, _DWORD, KeyValues *, IMatchAsyncOperationCallback *, IMatchAsyncOperation **))BaseLocalClient->ReserveServer)(
    a1: BaseLocalClient,
    a2: netAdrPublic,
    a3: netAdrPrivate,
    a4: nServerReservationCookie,
    a5: HIDWORD(nServerReservationCookie),
    a6: pKVGameSettings,
    a7: pCallback,
    a8: ppAsyncOperation);
}

//------------------------------------------------------------------------------
// Address: 0x101B3EE0
// Name: public: virtual void CNetSupportImpl::OnMatchEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::OnMatchEvent(CNetSupportImpl *this, KeyValues *pEvent)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  BaseLocalClient->OnEvent(this: BaseLocalClient, a2: pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x101B3F00
// Name: public: virtual class INetChannel __near * CNetSupportImpl::CreateChannel(int,struct netadr_s const __near &,char const __near *,class INetChannelHandler __near *)
// Source: json
//------------------------------------------------------------------------------
INetChannel *__thiscall CNetSupportImpl::CreateChannel(
        CNetSupportImpl *this,
        int sock,
        const netadr_s *to,
        const char *szName,
        INetChannelHandler *pHandler)
{
  int v5; // edx
  int v6; // eax
  unsigned __int16 UDPPort; // ax
  netadr_s inetAddr; // [esp+4h] [ebp-Ch] BYREF

  v5 = *(_DWORD *)to->ip;
  v6 = *(_DWORD *)&to->port;
  inetAddr.type = to->type;
  *(_DWORD *)inetAddr.ip = v5;
  *(_DWORD *)&inetAddr.port = v6;
  if ( netadr_s::GetPort(this: &inetAddr) == 0 && CCircularBuffer::GetReadAvailable(this: &inetAddr) == NA_IP )
  {
    UDPPort = NET_GetUDPPort(socket: sock);
    netadr_s::SetPort(this: &inetAddr, newport: UDPPort);
  }
  return NET_CreateNetChannel(socket: sock, adr: &inetAddr, name: szName, handler: pHandler, bForceNewChannel: false);
}

//------------------------------------------------------------------------------
// Address: 0x101B3F70
// Name: public: virtual void CNetSupportImpl::ProcessSocket(int,class IConnectionlessPacketHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::ProcessSocket(CNetSupportImpl *this, int sock, IConnectionlessPacketHandler *pHandler)
{
  NET_ProcessSocket(sock, handler: pHandler);
}

//------------------------------------------------------------------------------
// Address: 0x101B3F90
// Name: public: virtual int CNetSupportImpl::SendPacket(class INetChannel __near *,int,struct netadr_s const __near &,void const __near *,int,class bf_write __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetSupportImpl::SendPacket(
        CNetSupportImpl *this,
        INetChannel *chan,
        int sock,
        const netadr_s *to,
        const unsigned __int8 *data,
        int length,
        bf_write *pVoicePayload,
        bool bUseCompression)
{
  int v8; // edx
  int v9; // eax
  netadr_s inetAddr; // [esp+0h] [ebp-Ch] BYREF

  v8 = *(_DWORD *)to->ip;
  v9 = *(_DWORD *)&to->port;
  inetAddr.type = to->type;
  *(_DWORD *)inetAddr.ip = v8;
  *(_DWORD *)&inetAddr.port = v9;
  if ( netadr_s::GetPort(this: &inetAddr) == 0 && CCircularBuffer::GetReadAvailable(this: &inetAddr) == NA_BROADCAST )
    netadr_s::SetPort(this: &inetAddr, newport: 0x6987u);
  return NET_SendPacket(chan, sock, to: &inetAddr, data, length, pVoicePayload, bUseCompression, unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B4000
// Name: public: virtual void CNetSupportImpl::GetServerInfo(struct INetSupport::ServerInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::GetServerInfo(CNetSupportImpl *this, INetSupport::ServerInfo_t *pServerInfo)
{
  int v2; // ecx
  int v3; // edx
  unsigned __int16 UDPPort; // ax
  int m_nValue; // eax

  if ( pServerInfo != nullptr )
  {
    memset(dst: (unsigned __int8 *)pServerInfo, value: 0, count: sizeof(INetSupport::ServerInfo_t));
    pServerInfo->m_netAdr = net_local_adr;
    if ( !NET_GetPublicAdr(adr: &pServerInfo->m_netAdrOnline) )
    {
      v2 = *(_DWORD *)pServerInfo->m_netAdr.ip;
      v3 = *(_DWORD *)&pServerInfo->m_netAdr.port;
      pServerInfo->m_netAdrOnline.type = pServerInfo->m_netAdr.type;
      *(_DWORD *)pServerInfo->m_netAdrOnline.ip = v2;
      *(_DWORD *)&pServerInfo->m_netAdrOnline.port = v3;
    }
    UDPPort = NET_GetUDPPort(socket: sv.m_Socket);
    pServerInfo->m_nPort = UDPPort;
    netadr_s::SetPort(this: &pServerInfo->m_netAdr, newport: UDPPort);
    netadr_s::SetPort(this: &pServerInfo->m_netAdrOnline, newport: pServerInfo->m_nPort);
    pServerInfo->m_bActive = sv.m_State > ss_dead;
    pServerInfo->m_bDedicated = sv.m_bIsDedicated;
    pServerInfo->m_bLobbyExclusive = CBaseServer::IsExclusiveToLobbyConnections(this: &sv);
    if ( sv_steamgroup_exclusive.m_pParent != nullptr )
      m_nValue = sv_steamgroup_exclusive.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    pServerInfo->m_bGroupExclusive = m_nValue != 0;
    pServerInfo->m_bInMainMenuBkgnd = sv.m_bIsLevelMainMenuBackground;
    pServerInfo->m_szServerName = CBaseServer::GetName(this: &sv);
    pServerInfo->m_szMapName = sv.m_szMapname;
    pServerInfo->m_numMaxHumanPlayers = CBaseServer::GetMaxHumanPlayers(this: &sv);
    pServerInfo->m_numHumanPlayers = CBaseServer::GetNumHumanPlayers(this: &sv);
  }
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1006E020
// Name: public: virtual int CNetSupportImpl::GetEngineBuildNumber(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __thiscall CNetSupportImpl::GetEngineBuildNumber(CEngineClient *this)
{
  return GetHostVersion();
}

//------------------------------------------------------------------------------
// Address: 0x101B3FB0
// Name: InternalFactory
// Source: json
//------------------------------------------------------------------------------
void *__cdecl InternalFactory(const char *pName, int *pReturnCode)
{
  void *result; // eax
  void *(__cdecl *FactoryThis)(const char *, int *); // eax

  if ( pReturnCode != nullptr )
    *pReturnCode = 0;
  if ( s_pfnDelegateFactory == nullptr || (result = s_pfnDelegateFactory(a1: pName, a2: pReturnCode)) == nullptr )
  {
    FactoryThis = Sys_GetFactoryThis();
    result = FactoryThis(a1: pName, a2: pReturnCode);
    if ( result == nullptr )
    {
      if ( pReturnCode != nullptr )
        *pReturnCode = 1;
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B4040
// Name: public: virtual void CNetSupportImpl::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::Disconnect(CNetSupportImpl *this)
{
  DisconnectTier2Libraries();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x101B4050
// Name: public: virtual void __near * CNetSupportImpl::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CNetSupportImpl *__thiscall CNetSupportImpl::QueryInterface(CNetSupportImpl *this, const char *pInterfaceName)
{
  return _V_stricmp(s1: pInterfaceName, s2: "INETSUPPORT_002") == 0 ? this : nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101B4080
// Name: public: virtual void CNetSupportImpl::GetClientInfo(struct INetSupport::ClientInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::GetClientInfo(CNetSupportImpl *this, INetSupport::ClientInfo_t *pClientInfo)
{
  CClientState *BaseLocalClient; // edi
  int v3; // eax
  int v4; // ebx
  player_info_s pi; // [esp+4h] [ebp-90h] BYREF

  if ( pClientInfo != nullptr )
  {
    pClientInfo->m_nSignonState = 0;
    pClientInfo->m_nSocket = 0;
    pClientInfo->m_pNetChannel = nullptr;
    pClientInfo->m_numHumanPlayers = 0;
    BaseLocalClient = GetBaseLocalClient();
    pClientInfo->m_nSignonState = BaseLocalClient->m_nSignonState;
    pClientInfo->m_nSocket = BaseLocalClient->m_Socket;
    pClientInfo->m_pNetChannel = BaseLocalClient->m_NetChannel;
    pClientInfo->m_numHumanPlayers = 0;
    if ( BaseLocalClient->m_nSignonState >= 2 && BaseLocalClient->m_pUserInfoTable != nullptr )
    {
      v3 = 0;
      if ( BaseLocalClient->m_nMaxClients > 0 )
      {
        do
        {
          v4 = v3 + 1;
          if ( engineClient->GetPlayerInfo(this: engineClient, a2: v3 + 1, a3: &pi) && !pi.fakeplayer && !pi.ishltv )
            ++pClientInfo->m_numHumanPlayers;
          v3 = v4;
        }
        while ( v4 < BaseLocalClient->m_nMaxClients );
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B4120
// Name: public: virtual void CNetSupportImpl::UpdateClientReservation(unsigned __int64,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::UpdateClientReservation(
        CNetSupportImpl *this,
        unsigned __int64 uiReservation,
        unsigned __int64 uiMachineIdHost)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  ((void (__thiscall *)(CClientState *, _DWORD, _DWORD))BaseLocalClient->SetServerReservationCookie)(
    a1: BaseLocalClient,
    a2: uiReservation,
    a3: HIDWORD(uiReservation));
  GetBaseLocalClient()->m_ListenServerSteamID = uiMachineIdHost;
}

//------------------------------------------------------------------------------
// Address: 0x101B4150
// Name: public: virtual void CNetSupportImpl::UpdateServerReservation(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::UpdateServerReservation(CNetSupportImpl *this, unsigned __int64 uiReservation)
{
  CBaseServer::SetReservationCookie(this: &sv, uiCookie: uiReservation, pchReasonFormat: "netsupport");
}

//------------------------------------------------------------------------------
// Address: 0x101B4180
// Name: public: virtual void CNetSupportImpl::ReserveServer(struct netadr_s const __near &,struct netadr_s const __near &,unsigned __int64,class KeyValues __near *,class IMatchAsyncOperationCallback __near *,class IMatchAsyncOperation __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::ReserveServer(
        CNetSupportImpl *this,
        const netadr_s *netAdrPublic,
        const netadr_s *netAdrPrivate,
        unsigned __int64 nServerReservationCookie,
        KeyValues *pKVGameSettings,
        IMatchAsyncOperationCallback *pCallback,
        IMatchAsyncOperation **ppAsyncOperation)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  ((void (__thiscall *)(CClientState *, const netadr_s *, const netadr_s *, _DWORD, _DWORD, KeyValues *, IMatchAsyncOperationCallback *, IMatchAsyncOperation **))BaseLocalClient->ReserveServer)(
    a1: BaseLocalClient,
    a2: netAdrPublic,
    a3: netAdrPrivate,
    a4: nServerReservationCookie,
    a5: HIDWORD(nServerReservationCookie),
    a6: pKVGameSettings,
    a7: pCallback,
    a8: ppAsyncOperation);
}

//------------------------------------------------------------------------------
// Address: 0x101B41C0
// Name: public: virtual void CNetSupportImpl::OnMatchEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::OnMatchEvent(CNetSupportImpl *this, KeyValues *pEvent)
{
  CClientState *BaseLocalClient; // eax

  BaseLocalClient = GetBaseLocalClient();
  BaseLocalClient->OnEvent(this: BaseLocalClient, a2: pEvent);
}

//------------------------------------------------------------------------------
// Address: 0x101B41E0
// Name: public: virtual class INetChannel __near * CNetSupportImpl::CreateChannel(int,struct netadr_s const __near &,char const __near *,class INetChannelHandler __near *)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__thiscall CNetSupportImpl::CreateChannel(
        CNetSupportImpl *this,
        int sock,
        const netadr_s *to,
        const char *szName,
        INetChannelHandler *pHandler)
{
  int v5; // edx
  int v6; // eax
  unsigned __int16 UDPPort; // ax
  netadr_s inetAddr; // [esp+4h] [ebp-Ch] BYREF

  v5 = *(_DWORD *)to->ip;
  v6 = *(_DWORD *)&to->port;
  inetAddr.type = to->type;
  *(_DWORD *)inetAddr.ip = v5;
  *(_DWORD *)&inetAddr.port = v6;
  if ( netadr_s::GetPort(this: &inetAddr) == 0 && CCircularBuffer::GetReadAvailable(this: &inetAddr) == NA_IP )
  {
    UDPPort = NET_GetUDPPort(socket: sock);
    netadr_s::SetPort(this: &inetAddr, newport: UDPPort);
  }
  return NET_CreateNetChannel(socket: sock, adr: &inetAddr, name: szName, handler: pHandler, bForceNewChannel: false);
}

//------------------------------------------------------------------------------
// Address: 0x101B4250
// Name: public: virtual void CNetSupportImpl::ProcessSocket(int,class IConnectionlessPacketHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::ProcessSocket(CNetSupportImpl *this, int sock, IConnectionlessPacketHandler *pHandler)
{
  NET_ProcessSocket(sock, handler: pHandler);
}

//------------------------------------------------------------------------------
// Address: 0x101B4270
// Name: public: virtual int CNetSupportImpl::SendPacket(class INetChannel __near *,int,struct netadr_s const __near &,void const __near *,int,class bf_write __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetSupportImpl::SendPacket(
        CNetSupportImpl *this,
        CNetChan *chan,
        int sock,
        const netadr_s *to,
        unsigned __int8 *data,
        int length,
        bf_write *pVoicePayload,
        bool bUseCompression)
{
  int v8; // edx
  int v9; // eax
  netadr_s inetAddr; // [esp+0h] [ebp-Ch] BYREF

  v8 = *(_DWORD *)to->ip;
  v9 = *(_DWORD *)&to->port;
  inetAddr.type = to->type;
  *(_DWORD *)inetAddr.ip = v8;
  *(_DWORD *)&inetAddr.port = v9;
  if ( netadr_s::GetPort(this: &inetAddr) == 0 && CCircularBuffer::GetReadAvailable(this: &inetAddr) == NA_BROADCAST )
    netadr_s::SetPort(this: &inetAddr, newport: 0x6987u);
  return NET_SendPacket(chan, sock, to: &inetAddr, data, length, pVoicePayload, bUseCompression, unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x101B42E0
// Name: public: virtual void CNetSupportImpl::GetServerInfo(struct INetSupport::ServerInfo_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetSupportImpl::GetServerInfo(CNetSupportImpl *this, INetSupport::ServerInfo_t *pServerInfo)
{
  int v2; // ecx
  int v3; // edx
  unsigned __int16 UDPPort; // ax
  int m_nValue; // eax

  if ( pServerInfo != nullptr )
  {
    memset(dst: (unsigned __int8 *)pServerInfo, value: 0, count: sizeof(INetSupport::ServerInfo_t));
    pServerInfo->m_netAdr = net_local_adr;
    if ( NET_GetPublicAdr(adr: &pServerInfo->m_netAdrOnline) == 0 )
    {
      v2 = *(_DWORD *)pServerInfo->m_netAdr.ip;
      v3 = *(_DWORD *)&pServerInfo->m_netAdr.port;
      pServerInfo->m_netAdrOnline.type = pServerInfo->m_netAdr.type;
      *(_DWORD *)pServerInfo->m_netAdrOnline.ip = v2;
      *(_DWORD *)&pServerInfo->m_netAdrOnline.port = v3;
    }
    UDPPort = NET_GetUDPPort(socket: sv.m_Socket);
    pServerInfo->m_nPort = UDPPort;
    netadr_s::SetPort(this: &pServerInfo->m_netAdr, newport: UDPPort);
    netadr_s::SetPort(this: &pServerInfo->m_netAdrOnline, newport: pServerInfo->m_nPort);
    pServerInfo->m_bActive = sv.m_State > ss_dead;
    pServerInfo->m_bDedicated = sv.m_bIsDedicated;
    pServerInfo->m_bLobbyExclusive = CBaseServer::IsExclusiveToLobbyConnections(this: &sv);
    if ( sv_steamgroup_exclusive.m_pParent != nullptr )
      m_nValue = sv_steamgroup_exclusive.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    pServerInfo->m_bGroupExclusive = m_nValue != 0;
    pServerInfo->m_bInMainMenuBkgnd = sv.m_bIsLevelMainMenuBackground;
    pServerInfo->m_szServerName = CBaseServer::GetName(this: &sv);
    pServerInfo->m_szMapName = sv.m_szMapname;
    pServerInfo->m_numMaxHumanPlayers = CBaseServer::GetMaxHumanPlayers(this: &sv);
    pServerInfo->m_numHumanPlayers = CBaseServer::GetNumHumanPlayers(this: &sv);
  }
}

} // namespace engine_xlsp
