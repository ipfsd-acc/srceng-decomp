// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/baseclientstate.cpp
// Functions: 180
// ============================================================

#include "engine\baseclientstate.h"

//------------------------------------------------------------------------------
// Address: 0x1005CD10
// Name: void UpdateNameFromSteamID(class IConVar __near *,class CSteamID __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateNameFromSteamID(IConVar *pConVar, CSteamID *pSteamID)
{
  CSteam3Client *v2; // eax
  const char *v3; // eax

  if ( pConVar != nullptr && pSteamID != nullptr && Steam3Client()->m_pSteamFriends != nullptr )
  {
    v2 = Steam3Client();
    v3 = (const char *)((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))v2->m_pSteamFriends->GetFriendPersonaName)(
                         a1: v2->m_pSteamFriends,
                         a2: *(_DWORD *)&pSteamID->m_steamid.m_comp,
                         a3: *((_DWORD *)&pSteamID->m_steamid.m_comp + 1));
    pConVar->SetValue_4(this: pConVar, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CD60
// Name: void SetNameToSteamIDName(class IConVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetNameToSteamIDName(IConVar *pConVar)
{
  CSteam3Client *v1; // eax
  CSteamID steamID; // [esp+0h] [ebp-8h] BYREF

  if ( Steam3Client()->m_pSteamUtils != nullptr
    && Steam3Client()->m_pSteamFriends != nullptr
    && Steam3Client()->m_pSteamUser != nullptr )
  {
    v1 = Steam3Client();
    v1->m_pSteamUser->GetSteamID(this: v1->m_pSteamUser, result: &steamID);
    UpdateNameFromSteamID(pConVar, pSteamID: &steamID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CDB0
// Name: void askconnect_accept_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl askconnect_accept_f()
{
  vgui::CTreeViewListControl *v0; // ecx
  ECommandTarget_t TraceType; // eax
  char szCommand[512]; // [esp+0h] [ebp-300h] BYREF
  char szHostName[256]; // [esp+200h] [ebp-100h] BYREF

  if ( IsAskConnectPanelActive(pHostName: szHostName, maxHostNameBytes: 256) )
  {
    V_snprintf(pDest: szCommand, maxLen: 512, pFormat: "connect %s", szHostName);
    TraceType = CTraceFilter::GetTraceType(this: v0);
    Cbuf_AddText(eTarget: TraceType, pText: szCommand, nTickDelay: 0);
    HideAskConnectPanel();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CE20
// Name: public: C_ServerClassInfo::C_ServerClassInfo(void)
// Source: json
//------------------------------------------------------------------------------
C_ServerClassInfo *__thiscall C_ServerClassInfo::C_ServerClassInfo(C_ServerClassInfo *this)
{
  this->m_ClassName = nullptr;
  this->m_DatatableName = nullptr;
  this->m_InstanceBaselineIndex = 0xFFFF;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005CE40
// Name: public: C_ServerClassInfo::~C_ServerClassInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerClassInfo::~C_ServerClassInfo(C_ServerClassInfo *this)
{
  free(pMem: this->m_ClassName);
  free(pMem: this->m_DatatableName);
}

//------------------------------------------------------------------------------
// Address: 0x1005CE60
// Name: public: virtual void CBaseClientState::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FileReceived(
        CBaseClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  ConMsg(a1: "CBaseClientState::FileReceived: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1005CE80
// Name: public: virtual void CBaseClientState::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FileDenied(
        CBaseClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  ConMsg(a1: "CBaseClientState::FileDenied: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1005CEA0
// Name: public: virtual void CBaseClientState::FileRequested(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FileRequested(
        CBaseClientState *this,
        const char *fileName,
        unsigned int transferID,
        BOOL bIsReplayDemoFile)
{
  const char *v5; // eax

  v5 = this->m_NetChannel->GetAddress(this: this->m_NetChannel);
  ConMsg(a1: "File '%s' requested from %s.\n", fileName, v5);
  this->m_NetChannel->SendFile(this: this->m_NetChannel, a2: fileName, a3: transferID, a4: bIsReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x1005CEE0
// Name: public: virtual void CBaseClientState::FileSent(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FileSent(
        CBaseClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  ConMsg(a1: "File '%s' sent.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1005CF00
// Name: public: virtual void CBaseClientState::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectionClosing(CBaseClientState *this, const char *reason)
{
  const char *v2; // eax

  v2 = reason;
  if ( reason == nullptr )
    v2 = "unknown reason";
  ConMsg(a1: "Disconnect: %s.\n", v2);
  this->Disconnect(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1005CF40
// Name: private: bool CBaseClientState::PrepareSteamConnectResponse(unsigned __int64,bool,struct netadr_s const __near &,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::PrepareSteamConnectResponse(
        CBaseClientState *this,
        unsigned __int64 unGSSteamID,
        bool bGSSecure,
        netadr_s *adr,
        bf_write *msg)
{
  netadrtype_t type; // eax
  int v8; // edx
  unsigned int v9; // eax
  unsigned __int16 UDPPort; // ax
  CSteam3Client *v11; // eax
  int v12; // esi
  const char *v13; // [esp-18h] [ebp-828h]
  unsigned __int16 Port; // [esp-14h] [ebp-824h]
  char steam3Cookie[2048]; // [esp+4h] [ebp-80Ch] BYREF
  netadr_s checkAdr; // [esp+804h] [ebp-Ch] BYREF

  if ( Steam3Client()->m_pSteamUser != nullptr )
  {
    type = adr->type;
    v8 = *(_DWORD *)&adr->port;
    *(_DWORD *)checkAdr.ip = *(_DWORD *)adr->ip;
    checkAdr.type = type;
    *(_DWORD *)&checkAdr.port = v8;
    if ( CCircularBuffer::GetReadAvailable(this: adr) == NA_LOOPBACK || netadr_s::IsLocalhost(this: adr) )
    {
      v9 = netadr_s::addr_ntohl(this: &net_local_adr);
      netadr_s::SetIP(this: &checkAdr, unIP: v9);
      if ( netadr_s::GetPort(this: &checkAdr) == 0 )
      {
        UDPPort = NET_GetUDPPort(socket: 1);
        netadr_s::SetPort(this: &checkAdr, newport: UDPPort);
      }
    }
    if ( sv.m_State >= ss_active
      && (sv.m_bIsLevelMainMenuBackground
       || CBaseServer::IsSinglePlayerGame(this: &sv)
       || CBaseServer::ShouldHideServer(this: &sv)) )
    {
      netadr_s::Clear(this: &checkAdr);
    }
    Port = netadr_s::GetPort(this: &checkAdr);
    v13 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&checkAdr);
    v11 = Steam3Client();
    v12 = CSteam3Client::InitiateConnection(
            this: v11,
            pData: steam3Cookie,
            cbMaxData: 2048,
            unIP: (unsigned int)v13,
            usPort: Port,
            unGSSteamID,
            bSecure: bGSSecure);
    bf_write::WriteShort(this: msg, val: v12);
    if ( v12 > 0 )
      bf_write::WriteBytes(this: msg, pBuf: steam3Cookie, nBytes: v12);
    return 1;
  }
  else
  {
    COM_ExplainDisconnection(bPrint: true, fmt: "The server requires that you be running Steam.\n");
    this->Disconnect(this, a2: true);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D080
// Name: public: class INetworkStringTable __near * CBaseClientState::GetStringTable(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CBaseClientState::GetStringTable(CBaseClientState *this, const char *name)
{
  if ( this->m_StringTableContainer != nullptr )
    return this->m_StringTableContainer->FindTable(this: this->m_StringTableContainer, a2: name);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005D0A0
// Name: public: virtual void CBaseClientState::FullConnect(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FullConnect(CBaseClientState *this, netadr_s *adr)
{
  INetChannel *NetChannel; // eax
  unsigned int m_nChallengeNr; // ecx
  CBaseClientState_vtbl *v5; // eax
  bool (__thiscall *SetSignonState)(CBaseClientState *, int, int, NET_SignonState *); // edx
  CRConClient *v7; // eax
  const netadr_s *v8; // [esp-4h] [ebp-8h]

  _COM_TimestampedLog(a1: "CBaseClientState::FullConnect");
  NetChannel = NET_CreateNetChannel(socket: this->m_Socket, adr, name: "CLIENT", handler: this, bForceNewChannel: false);
  m_nChallengeNr = this->m_nChallengeNr;
  this->m_NetChannel = NetChannel;
  NetChannel->StartStreaming(this: NetChannel, a2: m_nChallengeNr);
  v5 = this->INetChannelHandler::__vftable;
  this->m_flConnectTime = net_time;
  SetSignonState = v5->SetSignonState;
  this->m_nDeltaTick = -1;
  this->m_flNextCmdTime = net_time;
  this->m_nServerReservationCookie = 0;
  SetSignonState(this, a2: 2, a3: -1, a4: nullptr);
  v8 = this->m_NetChannel->GetRemoteAddress(this: this->m_NetChannel);
  v7 = RCONClient();
  CRConClient::SetAddress(this: v7, netAdr: v8);
}

//------------------------------------------------------------------------------
// Address: 0x1005D140
// Name: public: virtual void CBaseClientState::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectionCrashed(CBaseClientState *this, const char *reason)
{
  const char *v2; // eax

  v2 = reason;
  if ( reason == nullptr )
    v2 = "unknown reason";
  ConMsg(a1: "Connection lost: %s.\n", v2);
  this->Disconnect(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1005D180
// Name: public: virtual void CBaseClientState::ResendGameDetailsRequest(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ResendGameDetailsRequest(CBaseClientState *this, netadr_s *adr)
{
  KeyValues *v2; // esi
  const char *v3; // eax
  KeyValues *v4; // esi
  IMatchEventsSubscription *v5; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = netadr_s::ToString(this: adr, baseOnly: false);
    v4 = KeyValues::KeyValues(this: v2, setName: "Client::ResendGameDetailsRequest", firstKey: "to", firstValue: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v5->BroadcastEvent(this: v5, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1005D1E0
// Name: public: virtual bool CBaseClientState::ProcessSignonState(class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessSignonState(CBaseClientState *this, NET_SignonState *msg)
{
  return (*(bool (__thiscall **)(char *, int, int, NET_SignonState *))(*((_DWORD *)this - 2) + 60))(
           a1: (char *)this - 8,
           a2: msg->m_nSignonState,
           a3: msg->m_nSpawnCount,
           a4: msg);
}

//------------------------------------------------------------------------------
// Address: 0x1005D200
// Name: public: virtual bool CBaseClientState::ProcessPrint(class SVC_Print __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessPrint(CBaseClientState *this, SVC_Print *msg)
{
  ConMsg(a1: msg->m_szText);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D220
// Name: public: virtual bool CBaseClientState::ProcessMenu(class SVC_Menu __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessMenu(CBaseClientState *this, SVC_Menu *msg)
{
  PluginHelpers_Menu(msg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D240
// Name: public: virtual bool CBaseClientState::ProcessSendTable(class SVC_SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSendTable(CBaseClientState *this, SVC_SendTable *msg)
{
  if ( RecvTable_RecvClassInfos(pBuf: &msg->m_DataIn, bNeedsDecoder: msg->m_bNeedsDecoder, nDemoProtocol: 0) )
    return 1;
  Host_EndGame(bShowMainMenu: true, message: "ProcessSendTable: RecvTable_RecvClassInfos failed.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005D280
// Name: public: virtual bool CBaseClientState::ProcessSetPause(class SVC_SetPause __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSetPause(CBaseClientState *this, SVC_SetPause *msg)
{
  LOBYTE(this->m_ClockDriftMgr.m_nClientTick) = msg->m_bPaused;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D2A0
// Name: public: virtual bool CBaseClientState::ProcessSetView(class SVC_SetView __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSetView(CBaseClientState *this, SVC_SetView *msg)
{
  this->m_nDeltaTick = msg->m_nEntityIndex;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D2C0
// Name: public: static class ClientClass __near * CBaseClientState::FindClientClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__cdecl CBaseClientState::FindClientClass(const char *pClassName)
{
  ClientClass *AllClasses; // esi

  AllClasses = ClientDLL_GetAllClasses();
  if ( AllClasses == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: AllClasses->m_pNetworkName, s2: pClassName) != 0 )
  {
    AllClasses = AllClasses->m_pNext;
    if ( AllClasses == nullptr )
      return nullptr;
  }
  return AllClasses;
}

//------------------------------------------------------------------------------
// Address: 0x1005D300
// Name: public: class PackedEntity __near * CBaseClientState::GetEntityBaseline(int,int)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall CBaseClientState::GetEntityBaseline(CBaseClientState *this, int iBaseline, int nEntityIndex)
{
  return this->m_pEntityBaselines[iBaseline][nEntityIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1005D320
// Name: public: void CBaseClientState::SetEntityBaseline(int,class ClientClass __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SetEntityBaseline(
        CBaseClientState *this,
        int iBaseline,
        ClientClass *pClientClass,
        int index,
        char *packedData,
        unsigned int length)
{
  PackedEntity **v6; // esi
  PackedEntity *v7; // ecx
  PackedEntity *v8; // eax
  PackedEntity *v9; // eax

  v6 = &this->m_pEntityBaselines[iBaseline][index];
  v7 = *v6;
  if ( *v6 == nullptr )
  {
    v8 = (PackedEntity *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v8 != nullptr )
      v9 = PackedEntity::PackedEntity(this: v8);
    else
      v9 = nullptr;
    *v6 = v9;
    v7 = v9;
  }
  v7->m_pClientClass = pClientClass;
  v7->m_nEntityIndex = index;
  v7->m_pServerClass = nullptr;
  PackedEntity::AllocAndCopyPadded(this: v7, pData: packedData, size: length);
}

//------------------------------------------------------------------------------
// Address: 0x1005D380
// Name: public: class ClientClass __near * CBaseClientState::GetClientClass(int)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall CBaseClientState::GetClientClass(CBaseClientState *this, int index)
{
  return this->m_pServerClasses[index].m_pClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1005D3A0
// Name: public: bool CBaseClientState::GetClassBaseline(int,void const __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::GetClassBaseline(
        CBaseClientState *this,
        int iClass,
        const void **pData,
        int *pDatalen)
{
  C_ServerClassInfo *v5; // edi
  INetworkStringTable *v6; // esi
  int v7; // eax
  const void *v8; // eax
  char str[64]; // [esp+Ch] [ebp-40h] BYREF

  if ( iClass < 0 || iClass >= this->m_nServerClasses )
    _Error(a1: "GetDynamicBaseline: invalid class index '%d'", iClass);
  v5 = &this->m_pServerClasses[iClass];
  if ( this->m_StringTableContainer == nullptr )
  {
    v6 = nullptr;
LABEL_7:
    _Error(a1: "GetDynamicBaseline: NULL baseline table");
    goto LABEL_8;
  }
  v6 = this->m_StringTableContainer->FindTable(this: this->m_StringTableContainer, a2: "instancebaseline");
  if ( v6 == nullptr )
    goto LABEL_7;
LABEL_8:
  if ( v5->m_InstanceBaselineIndex == 0xFFFF )
  {
    V_snprintf(pDest: str, maxLen: 64, pFormat: "%d", iClass);
    v7 = v6->FindStringIndex(this: v6, a2: str);
    v5->m_InstanceBaselineIndex = v7;
    if ( v7 == 0xFFFF )
      _Error(a1: "GetDynamicBaseline: FindStringIndex(%s-%s) failed.", str, v5->m_ClassName);
  }
  v8 = v6->GetStringUserData(this: v6, a2: v5->m_InstanceBaselineIndex, a3: pDatalen);
  *pData = v8;
  return v8 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005D480
// Name: public: virtual bool CBaseClientState::ProcessGameEventList(class SVC_GameEventList __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessGameEventList(CBaseClientState *this, SVC_GameEventList *msg)
{
  return CGameEventManager::ParseEventList(this: g_GameEventManager, msg);
}

//------------------------------------------------------------------------------
// Address: 0x1005D490
// Name: public: virtual bool CBaseClientState::ProcessSplitScreen(class SVC_SplitScreen __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSplitScreen(CBaseClientState *this, SVC_SplitScreen *msg)
{
  SVC_SplitScreen::ESplitScreenMessageType m_Type; // eax

  m_Type = msg->m_Type;
  if ( m_Type != MSG_ADDUSER )
  {
    if ( m_Type == MSG_REMOVEUSER )
    {
      splitscreen->RemoveSplitScreenUser(this: splitscreen, a2: msg->m_nSlot, a3: msg->m_nPlayerIndex);
      g_pScaleformUI->SlotRelease(this: g_pScaleformUI, a2: msg->m_nSlot + 2);
      return 1;
    }
  }
  else
  {
    splitscreen->AddSplitScreenUser(this: splitscreen, a2: msg->m_nSlot, a3: msg->m_nPlayerIndex);
    g_pScaleformUI->InitSlot(this: g_pScaleformUI, a2: msg->m_nSlot + 2, a3: g_szDefaultScaleformClientMovieName);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D510
// Name: public: virtual bool CBaseClientState::ProcessSplitScreenUser(class NET_SplitScreenUser __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSplitScreenUser(CBaseClientState *this, NET_SplitScreenUser *msg)
{
  if ( splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: msg->m_nSlot) )
    splitscreen->SetActiveSplitScreenPlayerSlot(this: splitscreen, a2: msg->m_nSlot);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D550
// Name: public: int CBaseClientState::GetViewEntity(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CBaseClientState::GetViewEntity(CBaseClientState *this)
{
  return this->m_nViewEntity;
}

//------------------------------------------------------------------------------
// Address: 0x1005D5C0
// Name: public: netadr_s::netadr_s(void)
// Source: json
//------------------------------------------------------------------------------
netadr_s *__thiscall netadr_s::netadr_s(netadr_s *this)
{
  netadr_s::SetIP(this, unIP: 0);
  netadr_s::SetPort(this, newport: 0);
  netadr_s::SetType(this, newtype: NA_IP);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005D5E0
// Name: public: CBaseClientState::DirectConnectLobby_t::DirectConnectLobby_t(void)
// Source: json
//------------------------------------------------------------------------------
CBaseClientState::DirectConnectLobby_t *__thiscall CBaseClientState::DirectConnectLobby_t::DirectConnectLobby_t(
        CBaseClientState::DirectConnectLobby_t *this)
{
  this->m_flEndTime = -1.0;
  netadr_s::SetIP(this: &this->m_adrRemote, unIP: 0);
  netadr_s::SetPort(this: &this->m_adrRemote, newport: 0);
  netadr_s::SetType(this: &this->m_adrRemote, newtype: NA_IP);
  this->m_unLobbyID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005D630
// Name: void CL_NameCvarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_NameCvarChanged(IConVar *pConVar)
{
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  if ( __RTDynamicCast(
         inptr: pConVar,
         VfDelta: 0,
         SrcType: &IConVar `RTTI Type Descriptor',
         TargetType: &CSplitScreenAddedConVar `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    if ( LOBYTE(`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements) == 0 )
    {
      LOBYTE(`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements) = 1;
      SetNameToSteamIDName(pConVar);
      LOBYTE(`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements) = 0;
    }
    ConVarRef::ConVarRef(this: &var, pConVar);
    if ( _V_stricmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: var.m_pConVarState->m_pszDefaultValue) != 0
      && _V_stricmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: "player") != 0 )
    {
      Sys_SetRegKeyValue(
        pszSubKey: "Software\\Valve\\Steam",
        pszElement: "LastGameNameUsed",
        pszValue: var.m_pConVarState->m_Value.m_pszString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D6D0
// Name: GetPrivateIPDelayMsecs
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetPrivateIPDelayMsecs()
{
  float v0; // xmm0_4
  int v1; // xmm1_4
  float v3; // [esp+8h] [ebp-4h]

  v0 = cl_resend.m_pParent->m_Value.m_fValue * 0.5;
  v1 = 0;
  if ( v0 < 0.0 || (v1 = 1065353216, v0 > 1.0) )
    v3 = *(float *)&v1;
  else
    v3 = cl_resend.m_pParent->m_Value.m_fValue * 0.5;
  return (__int64)(v3 * 1000.0);
}

//------------------------------------------------------------------------------
// Address: 0x1005D740
// Name: public: virtual bool CBaseClientState::SetSignonState(int,int,class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::SetSignonState(CBaseClientState *this, int state, int count, NET_SignonState *msg)
{
  int m_nServerCount; // eax
  CBaseClientState::DirectConnectLobby_t v7; // [esp+8h] [ebp-18h] BYREF

  if ( (unsigned int)state <= 7
    && (state <= 2 || state > this->m_nSignonState || this->m_NetChannel->IsPlayback(this: this->m_NetChannel)) )
  {
    m_nServerCount = this->m_nServerCount;
    if ( count == m_nServerCount
      || count == -1
      || m_nServerCount == -1
      || this->m_NetChannel->IsPlayback(this: this->m_NetChannel) )
    {
      if ( this->m_nSignonState < 2 && state >= 2 )
        this->m_DirectConnectLobby = *CBaseClientState::DirectConnectLobby_t::DirectConnectLobby_t(this: &v7);
      this->m_nSignonState = state;
      return 1;
    }
    else
    {
      ConMsg(a1: "Received wrong spawn count %i when at %i\n", count, this->m_nServerCount);
      return 0;
    }
  }
  else
  {
    ConMsg(a1: "Received signon %i when at %i\n", state, this->m_nSignonState);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D820
// Name: private: void CBaseClientState::RememberIPAddressForLobby(unsigned __int64,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::RememberIPAddressForLobby(
        CBaseClientState *this,
        unsigned __int64 unLobbyID,
        netadr_s *adrRemote)
{
  const char *v4; // eax
  int v5; // [esp+Ch] [ebp-4h] BYREF

  v5 = -16711936;
  v4 = netadr_s::ToString(this: adrRemote, baseOnly: false);
  ConColorMsg(
    a1: (const struct Color *)&v5,
    a2: "RememberIPAddressForLobby: lobby %llx from address %s\n",
    unLobbyID,
    v4);
  this->m_DirectConnectLobby.m_unLobbyID = unLobbyID;
  this->m_DirectConnectLobby.m_adrRemote = *adrRemote;
  this->m_DirectConnectLobby.m_flEndTime = realtime + 60.0;
}

//------------------------------------------------------------------------------
// Address: 0x1005D890
// Name: public: void CBaseClientState::HandleDeferredConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseClientState::HandleDeferredConnection(CBaseClientState *this@<ecx>, int a2@<edi>)
{
  bool v3; // zf
  int (__thiscall ***v4)(_DWORD); // eax
  KeyValues *v5; // eax
  unsigned __int64 Uint64; // rax
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  IMatchEventsSubscription *v11; // eax
  const char *v12; // eax
  void (__thiscall *ResendGameDetailsRequest)(CBaseClientState *, netadr_s *); // eax

  if ( this->m_DeferredConnection.m_bActive )
  {
    v3 = this->m_DeferredConnection.m_chLobbyType[0] == 0;
    this->m_DeferredConnection.m_bActive = false;
    if ( v3 && this->m_DeferredConnection.m_unLobbyID == 0 || sv.m_State >= ss_active )
    {
      ((void (__thiscall *)(CBaseClientState *, netadr_s *, int, int, _DWORD, _DWORD, bool))this->SendConnectPacket)(
        a1: this,
        a2: &this->m_DeferredConnection.m_adrServerAddress,
        a3: this->m_DeferredConnection.m_nChallenge,
        a4: this->m_DeferredConnection.m_nAuthprotocol,
        a5: this->m_DeferredConnection.m_unGSSteamID,
        a6: HIDWORD(this->m_DeferredConnection.m_unGSSteamID),
        a7: this->m_DeferredConnection.m_bGSSecure);
    }
    else if ( this->m_DeferredConnection.m_unLobbyID != 0 )
    {
      v4 = (int (__thiscall ***)(_DWORD))((int (__thiscall *)(IMatchFramework *, int))g_pMatchFramework->GetMatchSession)(
                                           a1: g_pMatchFramework,
                                           a2);
      if ( v4 != nullptr && (v5 = (KeyValues *)(**v4)(a1: v4)) != nullptr )
        Uint64 = KeyValues::GetUint64(this: v5, keyName: "xuidReserve", defaultValue: 0);
      else
        Uint64 = 0;
      if ( Uint64 == this->m_DeferredConnection.m_unLobbyID )
      {
        this->SendConnectPacket(
          this,
          a2: &this->m_DeferredConnection.m_adrServerAddress,
          a3: this->m_DeferredConnection.m_nChallenge,
          a4: this->m_DeferredConnection.m_nAuthprotocol,
          a5: LODWORD(this->m_DeferredConnection.m_unGSSteamID),
          a6: HIDWORD(this->m_DeferredConnection.m_unGSSteamID));
      }
      else
      {
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v7 != nullptr )
          v8 = KeyValues::KeyValues(this: v7, setName: "settings");
        else
          v8 = nullptr;
        KeyValues::SetString(this: v8, keyName: "system/network", value: "LIVE");
        KeyValues::SetString(this: v8, keyName: "options/action", value: "joinsession");
        KeyValues::SetUint64(this: v8, keyName: "options/sessionid", value: this->m_DeferredConnection.m_unLobbyID);
        this->Disconnect(this, a2: true);
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(
                  this: v9,
                  setName: "OnEngineLevelLoadingSession",
                  firstKey: "reason",
                  firstValue: "MatchSession");
        else
          v10 = nullptr;
        v11 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
        v11->BroadcastEvent(this: v11, a2: v10);
        g_pMatchFramework->MatchSession(this: g_pMatchFramework, a2: v8);
        if ( v8 != nullptr )
          KeyValues::deleteThis(this: v8);
      }
    }
    else
    {
      v12 = netadr_s::ToString(this: &this->m_DeferredConnection.m_adrServerAddress, baseOnly: false);
      _Msg(a1: "Retrying connection to %s, server requires lobby reservation but is unreserved.\n", v12);
      ResendGameDetailsRequest = this->ResendGameDetailsRequest;
      this->m_bWaitingForServerGameDetails = true;
      ResendGameDetailsRequest(this, a2: &this->m_DeferredConnection.m_adrServerAddress);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005DA90
// Name: public: virtual bool CBaseClientState::ProcessTick(class NET_Tick __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClientState::ProcessTick(CBaseClientState *this, NET_Tick *msg)
{
  CNetworkStringTableContainer *v3; // ecx
  int m_nTick; // edi

  (*((void (__thiscall **)(IServerMessageHandler_vtbl *, float, float))this->dtr_INetMessageHandler + 68))(
    a1: this->IServerMessageHandler::INetMessageHandler::__vftable,
    a2: msg->m_flHostFrameTime,
    a3: msg->m_flHostFrameTimeStdDeviation);
  v3 = *(CNetworkStringTableContainer **)&this->m_szEncryptionKey[2044];
  this->m_ClockDriftMgr.m_iCurClockOffset = msg->m_nTick;
  m_nTick = msg->m_nTick;
  LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]) = m_nTick;
  if ( v3 != nullptr )
    CNetworkStringTableContainer::SetTick(this: v3, tick_count: m_nTick);
  return SLODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005DAF0
// Name: protected: bool CBaseClientState::InternalProcessStringCmd(class NET_StringCmd __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::InternalProcessStringCmd(CBaseClientState *this, NET_StringCmd *msg, bool bIsHLTV)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  ECommandTarget_t v10; // eax
  ECommandTarget_t v11; // eax
  vgui::CTreeViewListControl *m_szCommand; // [esp-Ch] [ebp-514h]
  const char *v13; // [esp-Ch] [ebp-514h]
  vgui::CTreeViewListControl *v14; // [esp-8h] [ebp-510h]
  CCommand args; // [esp+0h] [ebp-508h] BYREF

  if ( this->m_bRestrictServerCommands && sv.m_State < ss_active )
  {
    CCommand::CCommand(this: &args);
    CCommand::Tokenize(this: &args, pCommand: msg->m_szCommand, pBreakSet: nullptr);
    if ( args.m_nArgc <= 0 )
      return 1;
    if ( bIsHLTV && _V_stricmp(s1: args.m_ppArgv[0], s2: "Connect") == 0 )
    {
      m_szCommand = (vgui::CTreeViewListControl *)msg->m_szCommand;
      TraceType = CTraceFilter::GetTraceType(this: m_szCommand);
      Cbuf_AddText(eTarget: TraceType, pText: (const char *)m_szCommand, nTickDelay: 0);
      return 1;
    }
    v6 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddExecutionMarker(eTarget: v6, marker: eCmdExecutionMarker_Enable_FCVAR_SERVER_CAN_EXECUTE);
    v13 = msg->m_szCommand;
    v8 = CTraceFilter::GetTraceType(this: v7);
    Cbuf_AddText(eTarget: v8, pText: v13, nTickDelay: 0);
    v10 = CTraceFilter::GetTraceType(this: v9);
    Cbuf_AddExecutionMarker(eTarget: v10, marker: eCmdExecutionMarker_Disable_FCVAR_SERVER_CAN_EXECUTE);
    return 1;
  }
  else
  {
    v14 = (vgui::CTreeViewListControl *)msg->m_szCommand;
    v11 = CTraceFilter::GetTraceType(this: v14);
    Cbuf_AddText(eTarget: v11, pText: (const char *)v14, nTickDelay: 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005DBE0
// Name: public: virtual bool CBaseClientState::ProcessCreateStringTable(class SVC_CreateStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClientState::ProcessCreateStringTable(CBaseClientState *this, SVC_CreateStringTable *msg)
{
  CBaseClientState *v2; // ebx
  IEngineVGuiInternal *v3; // eax
  SVC_CreateStringTable *v4; // edi
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ecx
  CNetworkStringTable *v7; // eax
  void (__thiscall *SetTick)(struct CNetworkStringTable *, int); // edx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edi
  const unsigned int *v16; // edx
  unsigned int v17; // edi
  int v18; // eax
  const unsigned int *v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // ebx
  int v22; // ecx
  unsigned int v23; // edi
  const unsigned int *v24; // eax
  const unsigned int *v25; // ecx
  const unsigned int *v26; // edx
  unsigned int v27; // edi
  int v28; // eax
  const unsigned int *v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // ebx
  char *v32; // ebx
  char *v33; // edi
  const unsigned int *v34; // eax
  int v35; // esi
  signed int v36; // eax
  float v38; // [esp-4h] [ebp-48h]
  unsigned int v39; // [esp-4h] [ebp-48h]
  bf_read data; // [esp+Ch] [ebp-38h] BYREF
  CBaseClientState *v41; // [esp+30h] [ebp-14h]
  char *compressedBuffer; // [esp+34h] [ebp-10h]
  CNetworkStringTable *table; // [esp+38h] [ebp-Ch]
  int startbit; // [esp+3Ch] [ebp-8h]
  unsigned int uncompressedSize; // [esp+40h] [ebp-4h] BYREF

  v2 = this;
  v41 = this;
  v3 = EngineVGui();
  v3->UpdateProgressBar(this: v3, a2: PROGRESS_PROCESSSTRINGTABLE, a3: true);
  v4 = msg;
  _COM_TimestampedLog(a1: " CBaseClient::ProcessCreateStringTable(%s)", msg->m_szTableName);
  CNetMessage::SetReliable(this: *(CNetMessage **)&v2->m_szEncryptionKey[2044], state: true);
  m_pData = msg->m_DataIn.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = msg->m_DataIn.m_nDataBits;
    startbit = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
             - msg->m_DataIn.m_nBitsAvail
             + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( startbit >= m_nDataBits )
      startbit = m_nDataBits;
  }
  else
  {
    startbit = 0;
  }
  v7 = (CNetworkStringTable *)(*(int (__thiscall **)(_DWORD, const char *, int, int, int, int))(**(_DWORD **)&v2->m_szEncryptionKey[2044]
                                                                                              + 4))(
                                a1: *(_DWORD *)&v2->m_szEncryptionKey[2044],
                                a2: msg->m_szTableName,
                                a3: msg->m_nMaxEntries,
                                a4: msg->m_nUserDataSize,
                                a5: msg->m_nUserDataSizeBits,
                                a6: msg->m_nFlags);
  SetTick = v7->SetTick;
  v38 = v2->m_ClockDriftMgr.m_ClockOffsets[15];
  table = v7;
  SetTick(this: v7, a2: LODWORD(v38));
  ((void (__thiscall *)(CNetworkStringTableContainer **, const char *))v2[-1].m_StringTableContainer[2].m_Tables.m_Memory.m_nGrowSize)(
    a1: &v2[-1].m_StringTableContainer,
    a2: msg->m_szTableName);
  if ( msg->m_bDataCompressed )
  {
    m_nBitsAvail = msg->m_DataIn.m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = msg->m_DataIn.m_nInBufWord;
      v11 = m_nBitsAvail - 32;
      v12 = 0;
      msg->m_DataIn.m_nBitsAvail = v11;
      if ( v11 != 0 )
      {
        msg->m_DataIn.m_nInBufWord = 0;
        v13 = m_nInBufWord;
      }
      else
      {
        m_pDataIn = msg->m_DataIn.m_pDataIn;
        m_pBufferEnd = msg->m_DataIn.m_pBufferEnd;
        msg->m_DataIn.m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          msg->m_DataIn.m_nBitsAvail = 1;
          msg->m_DataIn.m_nInBufWord = 0;
          msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          v13 = m_nInBufWord;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            msg->m_DataIn.m_nInBufWord = *m_pDataIn;
            msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
          v13 = m_nInBufWord;
        }
      }
      goto LABEL_25;
    }
    v16 = msg->m_DataIn.m_pBufferEnd;
    v17 = msg->m_DataIn.m_nInBufWord;
    v18 = 32 - m_nBitsAvail;
    v19 = msg->m_DataIn.m_pDataIn;
    if ( v19 == v16 )
    {
      msg->m_DataIn.m_nBitsAvail = 1;
      msg->m_DataIn.m_nInBufWord = 0;
      msg->m_DataIn.m_bOverflow = true;
    }
    else
    {
      if ( v19 > v16 )
      {
        msg->m_DataIn.m_bOverflow = true;
        msg->m_DataIn.m_nInBufWord = 0;
LABEL_21:
        if ( msg->m_DataIn.m_bOverflow )
        {
          v13 = 0;
        }
        else
        {
          v20 = msg->m_DataIn.m_nInBufWord;
          v21 = (v20 & CBitBuffer::s_nMaskTable[v18]) << msg->m_DataIn.m_nBitsAvail;
          msg->m_DataIn.m_nBitsAvail = 32 - v18;
          v13 = v17 | v21;
          msg->m_DataIn.m_nInBufWord = v20 >> v18;
        }
        v12 = 0;
LABEL_25:
        v22 = msg->m_DataIn.m_nBitsAvail;
        uncompressedSize = v13;
        if ( v22 >= 32 )
        {
          v23 = msg->m_DataIn.m_nInBufWord;
          msg->m_DataIn.m_nBitsAvail = v22 - 32;
          if ( v22 == 32 )
          {
            v24 = msg->m_DataIn.m_pDataIn;
            v25 = msg->m_DataIn.m_pBufferEnd;
            msg->m_DataIn.m_nBitsAvail = 32;
            if ( v24 == v25 )
            {
              msg->m_DataIn.m_nBitsAvail = 1;
              msg->m_DataIn.m_pDataIn = v24 + 1;
            }
            else if ( v24 <= v25 )
            {
              v12 = *v24;
              msg->m_DataIn.m_pDataIn = v24 + 1;
            }
            else
            {
              msg->m_DataIn.m_bOverflow = true;
            }
          }
          goto LABEL_41;
        }
        v26 = msg->m_DataIn.m_pBufferEnd;
        v27 = msg->m_DataIn.m_nInBufWord;
        v28 = 32 - v22;
        v29 = msg->m_DataIn.m_pDataIn;
        if ( v29 == v26 )
        {
          msg->m_DataIn.m_nBitsAvail = 1;
          msg->m_DataIn.m_nInBufWord = 0;
          msg->m_DataIn.m_bOverflow = true;
        }
        else
        {
          if ( v29 > v26 )
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
LABEL_38:
            if ( msg->m_DataIn.m_bOverflow )
            {
              v23 = 0;
LABEL_42:
              uncompressedSize = v13;
              v32 = (char *)MemAlloc_Alloc(nSize: 4 * ((v13 + 3) >> 2));
              compressedBuffer = (char *)MemAlloc_Alloc(nSize: 4 * ((v23 + 3) >> 2));
              CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: compressedBuffer, nBits: 8 * v23);
              v39 = v23;
              v33 = compressedBuffer;
              NET_BufferToBufferDecompress(
                dest: v32,
                destLen: &uncompressedSize,
                source: compressedBuffer,
                sourceLen: v39);
              data.m_pDebugName = nullptr;
              data.m_nDataBytes = 0;
              data.m_bOverflow = false;
              data.m_nDataBits = -1;
              CBitRead::StartReading(this: &data, pData: v32, nBytes: uncompressedSize, iStartBit: 0, nBits: -1);
              CNetworkStringTable::ParseUpdate(this: table, buf: &data, entries: msg->m_nNumEntries);
              free(pMem: v32);
              free(pMem: v33);
              v2 = v41;
              v4 = msg;
              goto LABEL_44;
            }
            v30 = msg->m_DataIn.m_nInBufWord;
            v31 = (v30 & CBitBuffer::s_nMaskTable[v28]) << msg->m_DataIn.m_nBitsAvail;
            msg->m_DataIn.m_nBitsAvail = 32 - v28;
            v23 = v31 | v27;
            v13 = uncompressedSize;
            v12 = v30 >> v28;
LABEL_41:
            msg->m_DataIn.m_nInBufWord = v12;
            goto LABEL_42;
          }
          msg->m_DataIn.m_nInBufWord = *v29;
        }
        msg->m_DataIn.m_pDataIn = v29 + 1;
        goto LABEL_38;
      }
      msg->m_DataIn.m_nInBufWord = *v19;
    }
    msg->m_DataIn.m_pDataIn = v19 + 1;
    goto LABEL_21;
  }
  CNetworkStringTable::ParseUpdate(this: table, buf: &msg->m_DataIn, entries: msg->m_nNumEntries);
LABEL_44:
  CNetMessage::SetReliable(this: *(CNetMessage **)&v2->m_szEncryptionKey[2044], state: false);
  v34 = msg->m_DataIn.m_pData;
  if ( v34 != nullptr )
  {
    v35 = msg->m_DataIn.m_nDataBits;
    v36 = 32 * (msg->m_DataIn.m_pDataIn - v34) - msg->m_DataIn.m_nBitsAvail + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( v36 < v35 )
      v35 = v36;
  }
  else
  {
    v35 = 0;
  }
  _COM_TimestampedLog(a1: " CBaseClient::ProcessCreateStringTable(%s)-done", v4->m_szTableName);
  return v35 - startbit == v4->m_nLength;
}

//------------------------------------------------------------------------------
// Address: 0x1005DF60
// Name: public: virtual bool CBaseClientState::ProcessUpdateStringTable(class SVC_UpdateStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessUpdateStringTable(CBaseClientState *this, SVC_UpdateStringTable *msg)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ebx
  CNetworkStringTable *v4; // eax
  const unsigned int *v5; // eax
  int v7; // eax

  m_pData = msg->m_DataIn.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
                - msg->m_DataIn.m_nBitsAvail
                + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( m_nDataBits >= msg->m_DataIn.m_nDataBits )
      m_nDataBits = msg->m_DataIn.m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  if ( *(_DWORD *)&this->m_szEncryptionKey[2044] != 0 )
  {
    v4 = (CNetworkStringTable *)(*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->m_szEncryptionKey[2044] + 16))(
                                  a1: *(_DWORD *)&this->m_szEncryptionKey[2044],
                                  a2: msg->m_nTableID);
    CNetworkStringTable::ParseUpdate(this: v4, buf: &msg->m_DataIn, entries: msg->m_nChangedEntries);
  }
  else
  {
    _Warning(a1: "m_StringTableContainer is NULL in CBaseClientState::ProcessUpdateStringTable\n");
  }
  v5 = msg->m_DataIn.m_pData;
  if ( v5 == nullptr )
    return -m_nDataBits == msg->m_nLength;
  v7 = 32 * (msg->m_DataIn.m_pDataIn - v5) - msg->m_DataIn.m_nBitsAvail + 8 * (msg->m_DataIn.m_nDataBytes & 3);
  if ( v7 >= msg->m_DataIn.m_nDataBits )
    v7 = msg->m_DataIn.m_nDataBits;
  return v7 - m_nDataBits == msg->m_nLength;
}

//------------------------------------------------------------------------------
// Address: 0x1005E030
// Name: public: virtual bool CBaseClientState::ProcessPacketEntities(class SVC_PacketEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessPacketEntities(CBaseClientState *this, SVC_PacketEntities *msg)
{
  int m_ListenServerSteamID; // eax

  m_ListenServerSteamID = this->m_ListenServerSteamID;
  if ( m_ListenServerSteamID < 5 )
  {
    ConMsg(a1: "Received packet entities while connecting!\n");
    return 0;
  }
  if ( m_ListenServerSteamID == 5 )
  {
    if ( msg->m_bIsDelta )
    {
      ConMsg(a1: "Received delta packet entities while spawing!\n");
      return 0;
    }
    (*(void (__thiscall **)(char *, int, _DWORD, _DWORD))(*((_DWORD *)this - 2) + 60))(
      a1: (char *)this - 8,
      a2: 6,
      a3: LODWORD(this->m_flNextCmdTime),
      a4: 0);
  }
  if ( this->m_ClockDriftMgr.m_nServerTick >= 0 || !msg->m_bIsDelta )
    this->m_ClockDriftMgr.m_nServerTick = LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005E0B0
// Name: public: virtual bool CBaseClientState::LinkClasses(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::LinkClasses(CBaseClientState *this)
{
  CBaseClientState *v1; // esi
  int m_nServerClasses; // ecx
  int v3; // eax
  char **p_m_DatatableName; // edx
  C_ServerClassInfo *v6; // esi
  const char *m_ClassName; // ebx
  ClientClass *AllClasses; // edi
  const char *m_pNetTableName; // edi
  const char *m_DatatableName; // ebx
  CBaseClientState *v11; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = this;
  m_nServerClasses = this->m_nServerClasses;
  v3 = 0;
  v11 = v1;
  if ( m_nServerClasses > 0 )
  {
    p_m_DatatableName = &v1->m_pServerClasses->m_DatatableName;
    do
    {
      if ( *p_m_DatatableName == nullptr )
      {
        Host_EndGame(bShowMainMenu: true, message: "CL_ParseClassInfo_EndClasses: class %d not initialized.\n", v3);
        return 0;
      }
      ++v3;
      p_m_DatatableName += 4;
    }
    while ( v3 < m_nServerClasses );
  }
  i = 0;
  if ( m_nServerClasses <= 0 )
    return 1;
  for ( j = 0; ; ++j )
  {
    v6 = &v1->m_pServerClasses[j];
    m_ClassName = v6->m_ClassName;
    AllClasses = ClientDLL_GetAllClasses();
    if ( AllClasses != nullptr )
    {
      while ( _V_stricmp(s1: AllClasses->m_pNetworkName, s2: m_ClassName) != 0 )
      {
        AllClasses = AllClasses->m_pNext;
        if ( AllClasses == nullptr )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      AllClasses = nullptr;
    }
    v6->m_pClientClass = AllClasses;
    if ( AllClasses != nullptr )
      break;
    _Msg(a1: "Client missing DT class %s\n", v6->m_ClassName);
LABEL_17:
    if ( ++i >= v11->m_nServerClasses )
      return 1;
    v1 = v11;
  }
  m_pNetTableName = AllClasses->m_pRecvTable->m_pNetTableName;
  m_DatatableName = v6->m_DatatableName;
  if ( _V_stricmp(s1: m_DatatableName, s2: m_pNetTableName) == 0 )
  {
    v6->m_pClientClass->m_ClassID = i;
    goto LABEL_17;
  }
  Host_EndGame(
    bShowMainMenu: true,
    message: "CL_ParseClassInfo_EndClasses: server and client classes for '%s' use different datatables (server: %s, client: %s)",
    v6->m_ClassName,
    m_DatatableName,
    m_pNetTableName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005E1D0
// Name: public: void CBaseClientState::FreeEntityBaselines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FreeEntityBaselines(CBaseClientState *this)
{
  PackedEntity **v1; // esi
  int j; // ebx
  PackedEntity *v3; // edi
  int i; // [esp+Ch] [ebp-4h]

  v1 = this->m_pEntityBaselines[0];
  for ( i = 2; i != 0; --i )
  {
    for ( j = 2048; j != 0; --j )
    {
      v3 = *v1;
      if ( *v1 != nullptr )
      {
        PackedEntity::~PackedEntity(this: *v1);
        free(pMem: v3);
        *v1 = nullptr;
      }
      ++v1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E220
// Name: public: void CBaseClientState::CopyEntityBaseline(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::CopyEntityBaseline(CBaseClientState *this, int iFrom, int iTo)
{
  PackedEntity **v3; // ebx
  PackedEntity **v4; // ecx
  PackedEntity *v5; // edi
  PackedEntity *v6; // esi
  PackedEntity *v7; // eax
  PackedEntity *v8; // eax
  bool v9; // zf
  int iFroma; // [esp+14h] [ebp+8h]
  int iToa; // [esp+18h] [ebp+Ch]

  v3 = this->m_pEntityBaselines[iTo];
  v4 = this->m_pEntityBaselines[iFrom];
  iToa = (int)v4;
  iFroma = 2048;
  do
  {
    v5 = *v4;
    v6 = *v3;
    if ( *v4 != nullptr )
    {
      if ( v6 == nullptr )
      {
        v7 = (PackedEntity *)MemAlloc_Alloc(nSize: 0x34u);
        if ( v7 != nullptr )
          v8 = PackedEntity::PackedEntity(this: v7);
        else
          v8 = nullptr;
        v6 = v8;
        *v3 = v8;
        v8->m_pClientClass = nullptr;
        v8->m_pServerClass = nullptr;
        _InterlockedExchange(&v8->m_ReferenceCount.m_value, 0);
      }
      v6->m_nEntityIndex = v5->m_nEntityIndex;
      v6->m_pClientClass = v5->m_pClientClass;
      v6->m_pServerClass = v5->m_pServerClass;
      PackedEntity::AllocAndCopyPadded(this: v6, pData: v5->m_pData, size: (v5->m_nBits + 7) >> 3);
    }
    else if ( v6 != nullptr )
    {
      PackedEntity::~PackedEntity(this: *v3);
      free(pMem: v6);
      *v3 = nullptr;
    }
    v4 = (PackedEntity **)(iToa + 4);
    ++v3;
    v9 = iFroma-- == 1;
    iToa += 4;
  }
  while ( !v9 );
}

//------------------------------------------------------------------------------
// Address: 0x1005E2F0
// Name: public: virtual bool CBaseClientState::ProcessCmdKeyValues(class SVC_CmdKeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessCmdKeyValues(CBaseClientState *this, SVC_CmdKeyValues *msg)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  KeyValues *Copy; // eax
  IMatchEventsSubscription *v6; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Client::CmdKeyValues");
  else
    v4 = nullptr;
  Copy = KeyValues::MakeCopy(this: msg->m_pKeyValues);
  KeyValues::AddSubKey(this: v4, pSubkey: Copy);
  KeyValues::SetInt(this: v4, keyName: "slot", value: this->m_nViewEntity);
  v6 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v6->BroadcastEvent(this: v6, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005E3F0
// Name: public: void bf_write::WriteOneBit(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall bf_write::WriteOneBit(bf_write *this, int nValue)
{
  int m_iCurBit; // ecx
  int v4; // esi
  char v5; // bl
  unsigned __int8 *m_pData; // edi

  m_iCurBit = this->m_iCurBit;
  if ( m_iCurBit + 1 > this->m_nDataBits )
    this->m_bOverflow = true;
  if ( !this->m_bOverflow )
  {
    v4 = m_iCurBit >> 3;
    v5 = 1 << (m_iCurBit & 7);
    m_pData = this->m_pData;
    if ( nValue != 0 )
      m_pData[v4] |= v5;
    else
      m_pData[v4] &= ~v5;
    ++this->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E460
// Name: public: virtual char const __near * NET_StringCmd::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_StringCmd::GetName(NET_StringCmd *this)
{
  return "net_StringCmd";
}

//------------------------------------------------------------------------------
// Address: 0x1005E470
// Name: public: virtual unsigned int NET_StringCmd::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NET_StringCmd::GetSize(NET_StringCmd *this)
{
  return 1044;
}

//------------------------------------------------------------------------------
// Address: 0x1005E480
// Name: public: virtual bool NET_StringCmd::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_StringCmd::Process(NET_StringCmd *this)
{
  return this->m_pMessageHandler->ProcessStringCmd(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E4C0
// Name: public: virtual char const __near * NET_Tick::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_Tick::GetName(NET_Tick *this)
{
  return "net_Tick";
}

//------------------------------------------------------------------------------
// Address: 0x1005E4D0
// Name: public: virtual unsigned int SVC_CrosshairAngle::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_CrosshairAngle::GetSize(SVC_Prefetch *this)
{
  return 28;
}

//------------------------------------------------------------------------------
// Address: 0x1005E4E0
// Name: public: virtual bool NET_Tick::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_Tick::Process(NET_Tick *this)
{
  return this->m_pMessageHandler->ProcessTick(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E4F0
// Name: public: virtual char const __near * SVC_Print::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_Print::GetName(SVC_Print *this)
{
  return "svc_Print";
}

//------------------------------------------------------------------------------
// Address: 0x1005E500
// Name: public: virtual unsigned int SVC_Print::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_Print::GetSize(SVC_Print *this)
{
  return 2068;
}

//------------------------------------------------------------------------------
// Address: 0x1005E510
// Name: public: virtual char const __near * SVC_SetPause::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_SetPause::GetName(SVC_SetPause *this)
{
  return "svc_SetPause";
}

//------------------------------------------------------------------------------
// Address: 0x1005E520
// Name: public: virtual char const __near * SVC_VoiceInit::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_VoiceInit::GetName(SVC_VoiceInit *this)
{
  return "svc_VoiceInit";
}

//------------------------------------------------------------------------------
// Address: 0x1005E530
// Name: public: virtual unsigned int SVC_VoiceInit::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_VoiceInit::GetSize(SVC_VoiceInit *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x1005E540
// Name: public: virtual int SVC_VoiceData::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_VoiceData::GetType(SVC_VoiceData *this)
{
  return 15;
}

//------------------------------------------------------------------------------
// Address: 0x1005E550
// Name: public: virtual char const __near * SVC_VoiceData::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_VoiceData::GetName(SVC_VoiceData *this)
{
  return "svc_VoiceData";
}

//------------------------------------------------------------------------------
// Address: 0x1005E560
// Name: public: virtual int SVC_SendTable::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_SendTable::GetType(SVC_SendTable *this)
{
  return 9;
}

//------------------------------------------------------------------------------
// Address: 0x1005E580
// Name: public: virtual char const __near * SVC_SetView::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_SetView::GetName(SVC_SetView *this)
{
  return "svc_SetView";
}

//------------------------------------------------------------------------------
// Address: 0x1005E590
// Name: public: virtual bool SVC_SetView::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SetView::Process(SVC_SetView *this)
{
  return this->m_pMessageHandler->ProcessSetView(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E5A0
// Name: public: virtual int SVC_FixAngle::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_FixAngle::GetType(SVC_FixAngle *this)
{
  return 19;
}

//------------------------------------------------------------------------------
// Address: 0x1005E5B0
// Name: public: virtual char const __near * SVC_FixAngle::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_FixAngle::GetName(SVC_FixAngle *this)
{
  return "svc_FixAngle";
}

//------------------------------------------------------------------------------
// Address: 0x1005E5C0
// Name: public: virtual bool SVC_FixAngle::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_FixAngle::Process(SVC_FixAngle *this)
{
  return this->m_pMessageHandler->ProcessFixAngle(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E5D0
// Name: public: virtual char const __near * SVC_CrosshairAngle::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_CrosshairAngle::GetName(SVC_CrosshairAngle *this)
{
  return "svc_CrosshairAngle";
}

//------------------------------------------------------------------------------
// Address: 0x1005E5E0
// Name: public: virtual bool SVC_CrosshairAngle::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CrosshairAngle::Process(SVC_CrosshairAngle *this)
{
  return this->m_pMessageHandler->ProcessCrosshairAngle(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E5F0
// Name: public: virtual char const __near * SVC_EntityMessage::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_EntityMessage::GetName(SVC_EntityMessage *this)
{
  return "svc_EntityMessage";
}

//------------------------------------------------------------------------------
// Address: 0x1005E600
// Name: public: virtual bool SVC_EntityMessage::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_EntityMessage::Process(SVC_EntityMessage *this)
{
  return this->m_pMessageHandler->ProcessEntityMessage(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E610
// Name: public: virtual int SVC_TempEntities::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_TempEntities::GetType(SVC_TempEntities *this)
{
  return 27;
}

//------------------------------------------------------------------------------
// Address: 0x1005E620
// Name: public: virtual char const __near * SVC_TempEntities::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_TempEntities::GetName(SVC_TempEntities *this)
{
  return "svc_TempEntities";
}

//------------------------------------------------------------------------------
// Address: 0x1005E630
// Name: public: virtual bool SVC_TempEntities::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_TempEntities::Process(SVC_TempEntities *this)
{
  return this->m_pMessageHandler->ProcessTempEntities(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E640
// Name: public: virtual int NET_SetConVar::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall NET_SetConVar::GetType(NET_SetConVar *this)
{
  return 6;
}

//------------------------------------------------------------------------------
// Address: 0x1005E650
// Name: public: virtual int SVC_Menu::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_Menu::GetType(SVC_Menu *this)
{
  return 29;
}

//------------------------------------------------------------------------------
// Address: 0x1005E660
// Name: public: virtual char const __near * SVC_Menu::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_Menu::GetName(SVC_Menu *this)
{
  return "svc_Menu";
}

//------------------------------------------------------------------------------
// Address: 0x1005E670
// Name: public: virtual bool SVC_Menu::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Menu::Process(SVC_Menu *this)
{
  return this->m_pMessageHandler->ProcessMenu(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E6B0
// Name: public: virtual bool CBaseClientState::CAsyncOperation_ReserveServer::IsFinished(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClientState::CAsyncOperation_ReserveServer::IsFinished(
        CBaseClientState::CAsyncOperation_ReserveServer *this)
{
  return this->m_eState > AOS_ABORTING;
}

//------------------------------------------------------------------------------
// Address: 0x1005E6C0
// Name: public: virtual unsigned __int64 CBaseClientState::CAsyncOperation_ReserveServer::GetResult(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CBaseClientState::CAsyncOperation_ReserveServer::GetResult(
        CBaseClientState::CAsyncOperation_ReserveServer *this)
{
  if ( this->m_eState == AOS_SUCCEEDED )
    return (unsigned int)netadr_s::ToString(this: &this->m_adr, baseOnly: false);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005E6E0
// Name: public: virtual void CBaseClientState::CAsyncOperation_ReserveServer::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::CAsyncOperation_ReserveServer::Release(
        CBaseClientState::CAsyncOperation_ReserveServer *this)
{
  CBaseClientState *m_pParent; // eax

  m_pParent = this->m_pParent;
  if ( m_pParent != nullptr && m_pParent->m_pServerReservationOperation == this )
  {
    m_pParent->m_pServerReservationOperation = nullptr;
    this->m_pParent->m_pServerReservationCallback = nullptr;
  }
  free(pMem: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E710
// Name: public: virtual void CBaseClientState::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::Clear(CBaseClientState *this)
{
  bool v2; // zf
  C_ServerClassInfo *m_pServerClasses; // ecx
  int *p_m_InstanceBaselineIndex; // edx
  int v5; // ebx
  void **p_m_DatatableName; // edi
  void *v7; // ecx
  CNetworkStringTableContainer *m_StringTableContainer; // ecx
  INetChannel *m_NetChannel; // ecx
  int *v10; // [esp+Ch] [ebp-4h]

  this->m_nServerCount = -1;
  this->m_nDeltaTick = -1;
  CClockDriftMgr::Clear(this: &this->m_ClockDriftMgr);
  v2 = this->m_szLevelNameShort[0] == 0;
  this->m_nCurrentSequence = 0;
  this->m_nServerClasses = 0;
  this->m_nServerClassBits = 0;
  this->m_nPlayerSlot = 0;
  this->m_nSplitScreenSlot = 0;
  this->m_szLevelName[0] = 0;
  this->m_nMaxClients = 0;
  if ( !v2 )
    V_strncpy(pDest: this->m_szLastLevelNameShort, pSrc: this->m_szLevelNameShort, maxLen: 40);
  m_pServerClasses = this->m_pServerClasses;
  this->m_szLevelNameShort[0] = 0;
  if ( m_pServerClasses != nullptr )
  {
    p_m_InstanceBaselineIndex = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    v5 = m_pServerClasses[-1].m_InstanceBaselineIndex - 1;
    v10 = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    if ( v5 >= 0 )
    {
      p_m_DatatableName = (void **)&m_pServerClasses[m_pServerClasses[-1].m_InstanceBaselineIndex].m_DatatableName;
      do
      {
        v7 = *(p_m_DatatableName - 5);
        p_m_DatatableName -= 4;
        free(pMem: v7);
        free(pMem: *p_m_DatatableName);
        --v5;
      }
      while ( v5 >= 0 );
      p_m_InstanceBaselineIndex = v10;
    }
    free(pMem: p_m_InstanceBaselineIndex);
    this->m_pServerClasses = nullptr;
  }
  m_StringTableContainer = this->m_StringTableContainer;
  if ( m_StringTableContainer != nullptr )
  {
    m_StringTableContainer->RemoveAllTables(this: m_StringTableContainer);
    this->m_StringTableContainer = nullptr;
  }
  CBaseClientState::FreeEntityBaselines(this);
  if ( !this->m_bSplitScreenUser )
    RecvTable_Term(clearall: false);
  m_NetChannel = this->m_NetChannel;
  if ( m_NetChannel != nullptr )
    m_NetChannel->Reset(this: m_NetChannel);
  this->m_nViewEntity = 0;
  this->m_nChallengeNr = 0;
  this->m_flConnectTime = 0.0;
  this->m_bPaused = false;
  this->m_bServerInfoProcessed = false;
}

//------------------------------------------------------------------------------
// Address: 0x1005E830
// Name: public: virtual char const __near * SVC_ServerInfo::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_ServerInfo::GetName(SVC_ServerInfo *this)
{
  return "svc_ServerInfo";
}

//------------------------------------------------------------------------------
// Address: 0x1005E840
// Name: public: virtual unsigned int SVC_ServerInfo::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_ServerInfo::GetSize(SVC_ServerInfo *this)
{
  return 1112;
}

//------------------------------------------------------------------------------
// Address: 0x1005E850
// Name: public: virtual char const __near * SVC_SendTable::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_SendTable::GetName(SVC_SendTable *this)
{
  return "svc_SendTable";
}

//------------------------------------------------------------------------------
// Address: 0x1005E860
// Name: public: virtual unsigned int SVC_SendTable::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_SendTable::GetSize(CSosOperatorSpatializeSpeakers *this)
{
  return 84;
}

//------------------------------------------------------------------------------
// Address: 0x1005E870
// Name: public: virtual char const __near * SVC_UpdateStringTable::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_UpdateStringTable::GetName(SVC_UpdateStringTable *this)
{
  return "svc_UpdateStringTable";
}

//------------------------------------------------------------------------------
// Address: 0x1005E880
// Name: public: virtual bool SVC_UpdateStringTable::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UpdateStringTable::Process(CLC_SplitPlayerConnect *this)
{
  return this->m_pMessageHandler->ProcessSplitPlayerConnect(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E8A0
// Name: public: virtual int CLC_SplitPlayerConnect::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLC_SplitPlayerConnect::GetType(CLC_SplitPlayerConnect *this)
{
  return 17;
}

//------------------------------------------------------------------------------
// Address: 0x1005E8B0
// Name: public: virtual char const __near * SVC_Sounds::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_Sounds::GetName(SVC_Sounds *this)
{
  return "svc_Sounds";
}

//------------------------------------------------------------------------------
// Address: 0x1005E8C0
// Name: public: virtual bool SVC_Sounds::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Sounds::Process(SVC_Sounds *this)
{
  return this->m_pMessageHandler->ProcessSounds(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E8D0
// Name: public: virtual int SVC_BSPDecal::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_BSPDecal::GetType(SVC_BSPDecal *this)
{
  return 21;
}

//------------------------------------------------------------------------------
// Address: 0x1005E8E0
// Name: public: virtual char const __near * SVC_BSPDecal::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_BSPDecal::GetName(SVC_BSPDecal *this)
{
  return "svc_BSPDecal";
}

//------------------------------------------------------------------------------
// Address: 0x1005E8F0
// Name: public: virtual bool SVC_BSPDecal::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_BSPDecal::Process(SVC_BSPDecal *this)
{
  return this->m_pMessageHandler->ProcessBSPDecal(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E900
// Name: public: virtual int SVC_GameEvent::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_GameEvent::GetType(SVC_GameEvent *this)
{
  return 25;
}

//------------------------------------------------------------------------------
// Address: 0x1005E910
// Name: public: virtual char const __near * SVC_GameEvent::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_GameEvent::GetName(SVC_GameEvent *this)
{
  return "svc_GameEvent";
}

//------------------------------------------------------------------------------
// Address: 0x1005E920
// Name: public: virtual bool SVC_GameEvent::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEvent::Process(SVC_GameEvent *this)
{
  return this->m_pMessageHandler->ProcessGameEvent(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E930
// Name: public: virtual int SVC_PacketEntities::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_PacketEntities::GetType(SVC_PacketEntities *this)
{
  return 26;
}

//------------------------------------------------------------------------------
// Address: 0x1005E940
// Name: public: virtual char const __near * SVC_PacketEntities::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_PacketEntities::GetName(SVC_PacketEntities *this)
{
  return "svc_PacketEntities";
}

//------------------------------------------------------------------------------
// Address: 0x1005E950
// Name: public: virtual unsigned int SVC_PacketEntities::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_PacketEntities::GetSize(SVC_UserMessage *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x1005E960
// Name: public: virtual bool SVC_PacketEntities::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PacketEntities::Process(SVC_PacketEntities *this)
{
  return this->m_pMessageHandler->ProcessPacketEntities(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E980
// Name: public: virtual int SVC_GameEventList::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_GameEventList::GetType(SVC_GameEventList *this)
{
  return 30;
}

//------------------------------------------------------------------------------
// Address: 0x1005E990
// Name: public: virtual char const __near * SVC_GameEventList::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_GameEventList::GetName(SVC_GameEventList *this)
{
  return "svc_GameEventList";
}

//------------------------------------------------------------------------------
// Address: 0x1005E9A0
// Name: public: virtual bool SVC_GameEventList::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEventList::Process(SVC_GameEventList *this)
{
  return this->m_pMessageHandler->ProcessGameEventList(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E9B0
// Name: public: virtual int SVC_GetCvarValue::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_GetCvarValue::GetType(SVC_GetCvarValue *this)
{
  return 31;
}

//------------------------------------------------------------------------------
// Address: 0x1005E9C0
// Name: public: virtual char const __near * SVC_GetCvarValue::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_GetCvarValue::GetName(SVC_GetCvarValue *this)
{
  return "svc_GetCvarValue";
}

//------------------------------------------------------------------------------
// Address: 0x1005E9D0
// Name: public: virtual unsigned int SVC_GetCvarValue::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_GetCvarValue::GetSize(SVC_GetCvarValue *this)
{
  return 280;
}

//------------------------------------------------------------------------------
// Address: 0x1005E9E0
// Name: public: virtual bool SVC_GetCvarValue::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GetCvarValue::Process(SVC_GetCvarValue *this)
{
  return this->m_pMessageHandler->ProcessGetCvarValue(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E9F0
// Name: public: virtual int SVC_SplitScreen::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_SplitScreen::GetType(SVC_SplitScreen *this)
{
  return 22;
}

//------------------------------------------------------------------------------
// Address: 0x1005EA00
// Name: public: virtual char const __near * SVC_SplitScreen::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_SplitScreen::GetName(SVC_SplitScreen *this)
{
  return "svc_SplitScreen";
}

//------------------------------------------------------------------------------
// Address: 0x1005EA10
// Name: public: virtual bool SVC_SplitScreen::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SplitScreen::Process(SVC_SplitScreen *this)
{
  return this->m_pMessageHandler->ProcessSplitScreen(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005EA20
// Name: public: SVC_PaintmapData::SVC_PaintmapData(void)
// Source: json
//------------------------------------------------------------------------------
SVC_PaintmapData *__thiscall SVC_PaintmapData::SVC_PaintmapData(SVC_PaintmapData *this)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (SVC_PaintmapData_vtbl *)&SVC_PaintmapData::`vftable';
  this->m_DataIn.m_bOverflow = false;
  this->m_DataIn.m_pDebugName = nullptr;
  this->m_DataIn.m_nDataBits = -1;
  this->m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &this->m_DataOut);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005EA50
// Name: public: virtual int SVC_PaintmapData::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_PaintmapData::GetType(SVC_PaintmapData *this)
{
  return 33;
}

//------------------------------------------------------------------------------
// Address: 0x1005EA60
// Name: public: virtual char const __near * SVC_PaintmapData::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_PaintmapData::GetName(SVC_PaintmapData *this)
{
  return "svc_PaintmapData";
}

//------------------------------------------------------------------------------
// Address: 0x1005EA70
// Name: public: virtual unsigned int CLC_ListenEvents::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLC_ListenEvents::GetSize(CLC_ListenEvents *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x1005EA80
// Name: public: virtual bool SVC_PaintmapData::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PaintmapData::Process(SVC_PaintmapData *this)
{
  return this->m_pMessageHandler->ProcessPaintmapData(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005EA90
// Name: public: virtual int SVC_PaintmapData::GetGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_PaintmapData::GetGroup(SVC_PaintmapData *this)
{
  return 14;
}

//------------------------------------------------------------------------------
// Address: 0x1005EAA0
// Name: public: struct Remote_t __near & CAddressList::Get(int)
// Source: json
//------------------------------------------------------------------------------
Remote_t *__thiscall CAddressList::Get(CAddressList *this, int index)
{
  return &this->m_List.m_Memory.m_pMemory[index];
}

//------------------------------------------------------------------------------
// Address: 0x1005EAB0
// Name: public: void CBaseClientState::ForceFullUpdate(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ForceFullUpdate(CBaseClientState *this, const char *pchReason)
{
  if ( this->m_nDeltaTick != -1 )
  {
    CBaseClientState::FreeEntityBaselines(this);
    this->m_nDeltaTick = -1;
    DevMsg(a1: "Requesting full game update (%s)...\n", pchReason);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005EAF0
// Name: public: virtual void CBaseClientState::Disconnect(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::Disconnect(CBaseClientState *this, bool bShowMainMenu)
{
  INetChannel *m_NetChannel; // ecx
  const char *v4; // eax
  unsigned int v5; // eax
  CSteam3Client *v6; // eax
  INetChannel *v7; // ecx
  const char *v8; // [esp-8h] [ebp-28h]
  unsigned __int16 Port; // [esp-4h] [ebp-24h]
  netadr_s checkAdr; // [esp+8h] [ebp-18h] BYREF
  netadr_s adr; // [esp+14h] [ebp-Ch] BYREF

  this->m_flConnectTime = -3.402823466385289e38;
  this->m_DeferredConnection.m_bActive = false;
  *(_WORD *)&this->m_bWaitingForPassword = 0;
  this->m_bEnteredPassword = false;
  this->m_nRetryNumber = 0;
  if ( this->m_nSignonState != 0 )
  {
    CL_NotifyRPTOfDisconnect();
    this->SetSignonState(this, a2: 0, a3: -1, a4: nullptr);
    netadr_s::SetIP(this: &adr, unIP: 0);
    netadr_s::SetPort(this: &adr, newport: 0);
    netadr_s::SetType(this: &adr, newtype: NA_IP);
    m_NetChannel = this->m_NetChannel;
    if ( m_NetChannel != nullptr )
    {
      adr = *m_NetChannel->GetRemoteAddress(this: m_NetChannel);
    }
    else if ( this->m_Remote.m_List.m_Size > 0 )
    {
      v4 = CUtlString::operator char const *(this: &this->m_Remote.m_List.m_Memory.m_pMemory->m_szRetryAddress);
      NET_StringToAdr(s: v4, a: &adr);
    }
    checkAdr = adr;
    if ( CCircularBuffer::GetReadAvailable(this: &adr) == NA_LOOPBACK || netadr_s::IsLocalhost(this: &adr) )
    {
      v5 = netadr_s::addr_ntohl(this: &net_local_adr);
      netadr_s::SetIP(this: &checkAdr, unIP: v5);
    }
    if ( this->m_ListenServerSteamID != 0 && this->m_Remote.m_List.m_Size > 0 )
    {
      NET_TerminateSteamConnection(sock: this->m_Socket, uSteamID: this->m_ListenServerSteamID);
      LODWORD(this->m_ListenServerSteamID) = 0;
      HIDWORD(this->m_ListenServerSteamID) = 0;
    }
    Port = netadr_s::GetPort(this: &adr);
    v8 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&checkAdr);
    v6 = Steam3Client();
    CSteam3Client::TerminateConnection(this: v6, unIP: (unsigned int)v8, usPort: Port);
    v7 = this->m_NetChannel;
    if ( v7 != nullptr )
    {
      v7->Shutdown(this: v7, a2: "Disconnect by user.");
      this->m_NetChannel = nullptr;
    }
    if ( this->m_bSplitScreenUser
      && splitscreen->IsValidSplitScreenSlot(this: splitscreen, a2: this->m_nSplitScreenSlot) )
    {
      splitscreen->RemoveSplitScreenUser(this: splitscreen, a2: this->m_nSplitScreenSlot, a3: this->m_nPlayerSlot + 1);
    }
    g_pScaleformUI->SlotRelease(this: g_pScaleformUI, a2: this->m_nSplitScreenSlot + 2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005EC90
// Name: Read_S2A_INFO_SRC
// Source: json
//------------------------------------------------------------------------------
void __usercall Read_S2A_INFO_SRC(netadr_s *from@<ecx>, bf_read *msg@<esi>)
{
  char *v2; // eax
  void (*v3)(const char *, ...); // ebx
  int m_nBitsAvail; // ecx
  unsigned int v5; // edx
  int v6; // edi
  unsigned int v7; // edx
  const unsigned int *v8; // eax
  const unsigned int *v9; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // ecx
  unsigned int v18; // eax
  __int16 v19; // dx
  int v20; // ecx
  const unsigned int *v21; // ecx
  unsigned int v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edi
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  __int16 v28; // di
  unsigned int v29; // edx
  int v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // edx
  int v33; // ecx
  const unsigned int *v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // ecx
  const unsigned int *v37; // edx
  unsigned int v38; // edi
  int v39; // eax
  const unsigned int *v40; // ecx
  unsigned int v41; // edx
  unsigned int v42; // ebx
  int v43; // edi
  unsigned int v44; // edx
  int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // edx
  int v48; // ecx
  const unsigned int *v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // ecx
  const unsigned int *v52; // edx
  unsigned int v53; // edi
  int v54; // eax
  const unsigned int *v55; // ecx
  unsigned int v56; // edx
  unsigned int v57; // ebx
  int v58; // edi
  unsigned int v59; // edx
  int v60; // ecx
  unsigned int v61; // edx
  int v62; // eax
  int v63; // ecx
  unsigned int v64; // edx
  const unsigned int *v65; // ecx
  const unsigned int *v66; // edx
  const unsigned int *v67; // edx
  unsigned int v68; // edi
  int v69; // eax
  const unsigned int *v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // ebx
  int v73; // ecx
  const char *v74; // ebx
  unsigned int v75; // eax
  int v76; // edi
  int v77; // ecx
  unsigned int v78; // edx
  const unsigned int *v79; // eax
  const unsigned int *v80; // ecx
  const unsigned int *v81; // edx
  unsigned int v82; // edi
  int v83; // eax
  const unsigned int *v84; // ecx
  unsigned int v85; // edx
  unsigned int v86; // ebx
  int v87; // ecx
  const char *v88; // ebx
  unsigned int v89; // eax
  int v90; // edx
  int v91; // ecx
  int v92; // edi
  const unsigned int *v93; // eax
  const unsigned int *v94; // ecx
  const unsigned int *v95; // edx
  unsigned int v96; // edi
  int v97; // eax
  const unsigned int *v98; // ecx
  unsigned int v99; // edx
  unsigned int v100; // ebx
  int v101; // ecx
  unsigned int v102; // eax
  int v103; // edx
  int v104; // ecx
  int v105; // edi
  const unsigned int *v106; // eax
  const unsigned int *v107; // ecx
  const unsigned int *v108; // edx
  unsigned int v109; // edi
  int v110; // eax
  const unsigned int *v111; // ecx
  unsigned int v112; // edx
  unsigned int v113; // ebx
  const char *v114; // eax
  void (*v115)(const char *, ...); // ebx
  int v116; // ecx
  unsigned int v117; // eax
  int v118; // edx
  int v119; // ecx
  int v120; // edi
  const unsigned int *v121; // eax
  const unsigned int *v122; // ecx
  const unsigned int *v123; // edx
  unsigned int v124; // edi
  int v125; // eax
  const unsigned int *v126; // ecx
  unsigned int v127; // edx
  unsigned int v128; // ebx
  const char *v129; // eax
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  int v132; // ecx
  unsigned int v133; // eax
  int v134; // edx
  int v135; // ecx
  int v136; // ebx
  const unsigned int *v137; // eax
  const unsigned int *v138; // ecx
  const unsigned int *v139; // edx
  unsigned int v140; // edi
  int v141; // eax
  const unsigned int *v142; // ecx
  unsigned int v143; // edx
  unsigned int v144; // ebx
  int v145; // ecx
  unsigned int v146; // eax
  unsigned __int16 v147; // di
  int v148; // ecx
  unsigned int v149; // edx
  const unsigned int *v150; // eax
  const unsigned int *v151; // ecx
  const unsigned int *v152; // edx
  unsigned int v153; // edi
  int v154; // eax
  const unsigned int *v155; // ecx
  unsigned int v156; // edx
  int v157; // ecx
  unsigned int v158; // eax
  __int16 v159; // dx
  int v160; // ecx
  const unsigned int *v161; // ecx
  unsigned int v162; // ecx
  const unsigned int *v163; // edx
  unsigned int v164; // edi
  const unsigned int *v165; // ecx
  unsigned int v166; // edx
  __int16 v167; // di
  unsigned int v168; // edx
  void (*v169)(const char *, ...); // edi
  char str[1024]; // [esp+8h] [ebp-404h] BYREF
  const char *sType; // [esp+408h] [ebp-4h]

  v2 = netadr_s::ToString(this: from, baseOnly: false);
  v3 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "Responder   : %s\n", v2);
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_15:
        if ( msg->m_bOverflow )
        {
          v14 = 0;
          goto LABEL_20;
        }
        v15 = msg->m_nInBufWord;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v12]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v12;
        v6 = v16 | m_nInBufWord;
        v3 = (void (*)(const char *, ...))_Msg;
        v7 = v15 >> v12;
        goto LABEL_18;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v5 = msg->m_nInBufWord;
  v6 = (unsigned __int8)v5;
  msg->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v8 = msg->m_pDataIn;
    v9 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      msg->m_nInBufWord = *v8;
      msg->m_pDataIn = v8 + 1;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v7 = v5 >> 8;
LABEL_18:
  msg->m_nInBufWord = v7;
LABEL_19:
  v14 = v6;
LABEL_20:
  v3(a1: "Protocol    : %d\n", v14);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v3(a1: "Hostname    : %s\n", str);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v3(a1: "Map         : %s\n", str);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v3(a1: "Game        : %s\n", str);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v3(a1: "Description : %s\n", str);
  v17 = msg->m_nBitsAvail;
  if ( v17 < 16 )
  {
    v23 = msg->m_pBufferEnd;
    v24 = msg->m_nInBufWord;
    v18 = 16 - v17;
    v25 = msg->m_pDataIn;
    if ( v25 == v23 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v23 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_35;
      }
      msg->m_nInBufWord = *v25;
    }
    msg->m_pDataIn = v25 + 1;
LABEL_35:
    if ( msg->m_bOverflow )
    {
      LOWORD(v18) = 0;
    }
    else
    {
      v26 = msg->m_nInBufWord;
      v27 = (v26 & CBitBuffer::s_nMaskTable[v18]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v18;
      v28 = v27 | v24;
      v3 = (void (*)(const char *, ...))_Msg;
      v29 = v26 >> v18;
      LOWORD(v18) = v28;
      msg->m_nInBufWord = v29;
    }
    goto LABEL_38;
  }
  v18 = msg->m_nInBufWord;
  v19 = v18;
  v20 = v17 - 16;
  msg->m_nBitsAvail = v20;
  if ( v20 != 0 )
  {
    msg->m_nInBufWord = HIWORD(v18);
  }
  else
  {
    v18 = (unsigned int)msg->m_pDataIn;
    v21 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( (const unsigned int *)v18 == v21 )
    {
      msg->m_pDataIn = (const unsigned int *)(v18 + 4);
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      LOWORD(v18) = v19;
    }
    else
    {
      if ( v18 <= (unsigned int)v21 )
      {
        v22 = *(_DWORD *)v18;
        msg->m_pDataIn = (const unsigned int *)(v18 + 4);
        msg->m_nInBufWord = v22;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      LOWORD(v18) = v19;
    }
  }
LABEL_38:
  v3(a1: "AppID       : %u\n", (__int16)v18);
  v30 = msg->m_nBitsAvail;
  if ( v30 < 8 )
  {
    v37 = msg->m_pBufferEnd;
    v38 = msg->m_nInBufWord;
    v39 = 8 - v30;
    v40 = msg->m_pDataIn;
    if ( v40 == v37 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v40 > v37 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_53;
      }
      msg->m_nInBufWord = *v40;
    }
    msg->m_pDataIn = v40 + 1;
LABEL_53:
    if ( msg->m_bOverflow )
    {
      v31 = 0;
    }
    else
    {
      v41 = msg->m_nInBufWord;
      v42 = (v41 & CBitBuffer::s_nMaskTable[v39]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v39;
      v43 = v42 | v38;
      v3 = (void (*)(const char *, ...))_Msg;
      v44 = v41 >> v39;
      v31 = v43;
      msg->m_nInBufWord = v44;
    }
    goto LABEL_56;
  }
  v31 = msg->m_nInBufWord;
  v32 = (unsigned __int8)v31;
  v33 = v30 - 8;
  msg->m_nBitsAvail = v33;
  if ( v33 != 0 )
  {
    msg->m_nInBufWord = v31 >> 8;
    v31 = (unsigned __int8)v31;
  }
  else
  {
    v34 = msg->m_pDataIn;
    v35 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v34 == v35 )
    {
      msg->m_pDataIn = v34 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v31 = v32;
    }
    else
    {
      if ( v34 <= v35 )
      {
        v36 = *v34;
        msg->m_pDataIn = v34 + 1;
        msg->m_nInBufWord = v36;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v31 = v32;
    }
  }
LABEL_56:
  v3(a1: "Players      : %u\n", v31);
  v45 = msg->m_nBitsAvail;
  if ( v45 < 8 )
  {
    v52 = msg->m_pBufferEnd;
    v53 = msg->m_nInBufWord;
    v54 = 8 - v45;
    v55 = msg->m_pDataIn;
    if ( v55 == v52 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v55 > v52 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_71;
      }
      msg->m_nInBufWord = *v55;
    }
    msg->m_pDataIn = v55 + 1;
LABEL_71:
    if ( msg->m_bOverflow )
    {
      v46 = 0;
    }
    else
    {
      v56 = msg->m_nInBufWord;
      v57 = (v56 & CBitBuffer::s_nMaskTable[v54]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v54;
      v58 = v57 | v53;
      v3 = (void (*)(const char *, ...))_Msg;
      v59 = v56 >> v54;
      v46 = v58;
      msg->m_nInBufWord = v59;
    }
    goto LABEL_74;
  }
  v46 = msg->m_nInBufWord;
  v47 = (unsigned __int8)v46;
  v48 = v45 - 8;
  msg->m_nBitsAvail = v48;
  if ( v48 != 0 )
  {
    msg->m_nInBufWord = v46 >> 8;
    v46 = (unsigned __int8)v46;
  }
  else
  {
    v49 = msg->m_pDataIn;
    v50 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v49 == v50 )
    {
      msg->m_pDataIn = v49 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v46 = v47;
    }
    else
    {
      if ( v49 <= v50 )
      {
        v51 = *v49;
        msg->m_pDataIn = v49 + 1;
        msg->m_nInBufWord = v51;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v46 = v47;
    }
  }
LABEL_74:
  v3(a1: "MaxPlayers   : %u\n", v46);
  v60 = msg->m_nBitsAvail;
  if ( v60 >= 8 )
  {
    v61 = msg->m_nInBufWord;
    v62 = (unsigned __int8)v61;
    v63 = v60 - 8;
    msg->m_nBitsAvail = v63;
    if ( v63 != 0 )
    {
      v64 = v61 >> 8;
    }
    else
    {
      v65 = msg->m_pDataIn;
      v66 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v65 == v66 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v65 + 1;
        goto LABEL_92;
      }
      if ( v65 > v66 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_92;
      }
      v64 = *v65;
      msg->m_pDataIn = v65 + 1;
    }
    goto LABEL_91;
  }
  v67 = msg->m_pBufferEnd;
  v68 = msg->m_nInBufWord;
  v69 = 8 - v60;
  v70 = msg->m_pDataIn;
  if ( v70 == v67 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
LABEL_87:
    msg->m_pDataIn = v70 + 1;
    goto LABEL_88;
  }
  if ( v70 <= v67 )
  {
    msg->m_nInBufWord = *v70;
    goto LABEL_87;
  }
  msg->m_bOverflow = true;
  msg->m_nInBufWord = 0;
LABEL_88:
  if ( msg->m_bOverflow )
  {
    v62 = 0;
    goto LABEL_92;
  }
  v71 = msg->m_nInBufWord;
  v72 = (v71 & CBitBuffer::s_nMaskTable[v69]) << msg->m_nBitsAvail;
  msg->m_nBitsAvail = 32 - v69;
  v64 = v71 >> v69;
  v62 = v72 | v68;
LABEL_91:
  msg->m_nInBufWord = v64;
LABEL_92:
  _Msg(a1: "Bots         : %u\n", v62);
  v73 = msg->m_nBitsAvail;
  v74 = "???";
  sType = "???";
  if ( v73 < 8 )
  {
    v81 = msg->m_pBufferEnd;
    v82 = msg->m_nInBufWord;
    v83 = 8 - v73;
    v84 = msg->m_pDataIn;
    if ( v84 == v81 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v84 > v81 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_106:
        if ( msg->m_bOverflow )
          goto LABEL_115;
        v85 = msg->m_nInBufWord;
        v86 = (v85 & CBitBuffer::s_nMaskTable[v83]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v83;
        v76 = v86 | v82;
        v74 = sType;
        v78 = v85 >> v83;
        goto LABEL_108;
      }
      msg->m_nInBufWord = *v84;
    }
    msg->m_pDataIn = v84 + 1;
    goto LABEL_106;
  }
  v75 = msg->m_nInBufWord;
  v76 = (unsigned __int8)v75;
  v77 = v73 - 8;
  v78 = 0;
  msg->m_nBitsAvail = v77;
  if ( v77 != 0 )
  {
    msg->m_nInBufWord = v75 >> 8;
    goto LABEL_109;
  }
  v79 = msg->m_pDataIn;
  v80 = msg->m_pBufferEnd;
  msg->m_nBitsAvail = 32;
  if ( v79 == v80 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_pDataIn = v79 + 1;
  }
  else if ( v79 <= v80 )
  {
    v78 = *v79;
    msg->m_pDataIn = v79 + 1;
  }
  else
  {
    msg->m_bOverflow = true;
  }
LABEL_108:
  msg->m_nInBufWord = v78;
LABEL_109:
  switch ( v76 )
  {
    case 'd':
      v74 = "dedicated";
      break;
    case 'l':
      v74 = "listen";
      break;
    case 'p':
      v74 = "proxy";
      break;
    default:
      break;
  }
LABEL_115:
  _Msg(a1: "Server Type  : %s\n", v74);
  v87 = msg->m_nBitsAvail;
  v88 = "???";
  sType = "???";
  if ( v87 >= 8 )
  {
    v89 = msg->m_nInBufWord;
    v90 = (unsigned __int8)v89;
    v91 = v87 - 8;
    msg->m_nBitsAvail = v91;
    if ( v91 != 0 )
    {
      msg->m_nInBufWord = v89 >> 8;
      v92 = (unsigned __int8)v89;
    }
    else
    {
      v93 = msg->m_pDataIn;
      v94 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v93 == v94 )
      {
        msg->m_nInBufWord = 0;
        msg->m_nBitsAvail = 1;
        msg->m_pDataIn = v93 + 1;
        v92 = v90;
      }
      else
      {
        if ( v93 <= v94 )
        {
          msg->m_nInBufWord = *v93;
          msg->m_pDataIn = v93 + 1;
        }
        else
        {
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
        }
        v92 = v90;
      }
    }
    goto LABEL_132;
  }
  v95 = msg->m_pBufferEnd;
  v96 = msg->m_nInBufWord;
  v97 = 8 - v87;
  v98 = msg->m_pDataIn;
  if ( v98 == v95 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
LABEL_129:
    msg->m_pDataIn = v98 + 1;
    goto LABEL_130;
  }
  if ( v98 <= v95 )
  {
    msg->m_nInBufWord = *v98;
    goto LABEL_129;
  }
  msg->m_bOverflow = true;
  msg->m_nInBufWord = 0;
LABEL_130:
  if ( !msg->m_bOverflow )
  {
    v99 = msg->m_nInBufWord;
    v100 = (v99 & CBitBuffer::s_nMaskTable[v97]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v97;
    v92 = v100 | v96;
    v88 = sType;
    msg->m_nInBufWord = v99 >> v97;
LABEL_132:
    if ( v92 == 108 )
    {
      v88 = "Linux";
    }
    else if ( v92 == 119 )
    {
      v88 = "Windows";
    }
  }
  _Msg(a1: "OS    Type   : %s\n", v88);
  v101 = msg->m_nBitsAvail;
  if ( v101 >= 8 )
  {
    v102 = msg->m_nInBufWord;
    v103 = (unsigned __int8)v102;
    v104 = v101 - 8;
    msg->m_nBitsAvail = v104;
    if ( v104 != 0 )
    {
      msg->m_nInBufWord = v102 >> 8;
      v105 = (unsigned __int8)v102;
    }
    else
    {
      v106 = msg->m_pDataIn;
      v107 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v106 == v107 )
      {
        msg->m_nInBufWord = 0;
        msg->m_nBitsAvail = 1;
        msg->m_pDataIn = v106 + 1;
        v105 = v103;
      }
      else
      {
        if ( v106 <= v107 )
        {
          msg->m_nInBufWord = *v106;
          msg->m_pDataIn = v106 + 1;
        }
        else
        {
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
        }
        v105 = v103;
      }
    }
LABEL_153:
    v114 = "yes";
    if ( v105 > 0 )
      goto LABEL_155;
    goto LABEL_154;
  }
  v108 = msg->m_pBufferEnd;
  v109 = msg->m_nInBufWord;
  v110 = 8 - v101;
  v111 = msg->m_pDataIn;
  if ( v111 == v108 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v111 > v108 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_151;
    }
    msg->m_nInBufWord = *v111;
  }
  msg->m_pDataIn = v111 + 1;
LABEL_151:
  if ( !msg->m_bOverflow )
  {
    v112 = msg->m_nInBufWord;
    v113 = (v112 & CBitBuffer::s_nMaskTable[v110]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v110;
    v105 = v113 | v109;
    msg->m_nInBufWord = v112 >> v110;
    goto LABEL_153;
  }
LABEL_154:
  v114 = "no";
LABEL_155:
  v115 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "Password     : %s\n", v114);
  v116 = msg->m_nBitsAvail;
  if ( v116 >= 8 )
  {
    v117 = msg->m_nInBufWord;
    v118 = (unsigned __int8)v117;
    v119 = v116 - 8;
    msg->m_nBitsAvail = v119;
    if ( v119 != 0 )
    {
      msg->m_nInBufWord = v117 >> 8;
      v120 = (unsigned __int8)v117;
    }
    else
    {
      v121 = msg->m_pDataIn;
      v122 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v121 == v122 )
      {
        msg->m_nInBufWord = 0;
        msg->m_nBitsAvail = 1;
        msg->m_pDataIn = v121 + 1;
        v120 = v118;
      }
      else
      {
        if ( v121 <= v122 )
        {
          msg->m_nInBufWord = *v121;
          msg->m_pDataIn = v121 + 1;
        }
        else
        {
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
        }
        v120 = v118;
      }
    }
LABEL_172:
    v129 = "yes";
    if ( v120 > 0 )
      goto LABEL_174;
    goto LABEL_173;
  }
  v123 = msg->m_pBufferEnd;
  v124 = msg->m_nInBufWord;
  v125 = 8 - v116;
  v126 = msg->m_pDataIn;
  if ( v126 == v123 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v126 > v123 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_170;
    }
    msg->m_nInBufWord = *v126;
  }
  msg->m_pDataIn = v126 + 1;
LABEL_170:
  if ( !msg->m_bOverflow )
  {
    v127 = msg->m_nInBufWord;
    v128 = (v127 & CBitBuffer::s_nMaskTable[v125]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v125;
    v120 = v128 | v124;
    v115 = (void (*)(const char *, ...))_Msg;
    msg->m_nInBufWord = v127 >> v125;
    goto LABEL_172;
  }
LABEL_173:
  v129 = "no";
LABEL_174:
  v115(a1: "Secure       : %s\n", v129);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v115(a1: "Version      : %s\n", str);
  m_pData = msg->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (msg->m_pDataIn - m_pData) - msg->m_nBitsAvail + 8 * (msg->m_nDataBytes & 3);
    if ( m_nDataBits >= msg->m_nDataBits )
      m_nDataBits = msg->m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  if ( msg->m_nDataBits - m_nDataBits >= 0 && ((msg->m_nDataBits - m_nDataBits) & 0xFFFFFFF8) != 0 )
  {
    v132 = msg->m_nBitsAvail;
    if ( v132 >= 8 )
    {
      v133 = msg->m_nInBufWord;
      v134 = (unsigned __int8)v133;
      v135 = v132 - 8;
      msg->m_nBitsAvail = v135;
      if ( v135 != 0 )
      {
        msg->m_nInBufWord = v133 >> 8;
        v136 = (unsigned __int8)v133;
      }
      else
      {
        v137 = msg->m_pDataIn;
        v138 = msg->m_pBufferEnd;
        msg->m_nBitsAvail = 32;
        if ( v137 == v138 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_nInBufWord = 0;
          msg->m_pDataIn = v137 + 1;
          v136 = v134;
        }
        else
        {
          if ( v137 <= v138 )
          {
            msg->m_nInBufWord = *v137;
            msg->m_pDataIn = v137 + 1;
          }
          else
          {
            msg->m_bOverflow = true;
            msg->m_nInBufWord = 0;
          }
          v136 = v134;
        }
      }
LABEL_197:
      sType = (const char *)v136;
      if ( (v136 & 0x80u) == 0 )
        goto LABEL_217;
      v145 = msg->m_nBitsAvail;
      if ( v145 >= 16 )
      {
        v146 = msg->m_nInBufWord;
        v147 = v146;
        v148 = v145 - 16;
        v149 = 0;
        msg->m_nBitsAvail = v148;
        if ( v148 != 0 )
        {
          msg->m_nInBufWord = HIWORD(v146);
LABEL_216:
          _Msg(a1: "Game Port    : %u\n", v147);
LABEL_217:
          if ( (v136 & 0x40) == 0 )
          {
            v169 = (void (*)(const char *, ...))_Msg;
LABEL_238:
            if ( (v136 & 0x20) != 0 )
            {
              CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
              v169(a1: "Public Tags   : %s\n", str);
            }
            return;
          }
          v157 = msg->m_nBitsAvail;
          if ( v157 >= 16 )
          {
            v158 = msg->m_nInBufWord;
            v159 = v158;
            v160 = v157 - 16;
            msg->m_nBitsAvail = v160;
            if ( v160 != 0 )
            {
              msg->m_nInBufWord = HIWORD(v158);
            }
            else
            {
              v158 = (unsigned int)msg->m_pDataIn;
              v161 = msg->m_pBufferEnd;
              msg->m_nBitsAvail = 32;
              if ( (const unsigned int *)v158 == v161 )
              {
                msg->m_pDataIn = (const unsigned int *)(v158 + 4);
                msg->m_nBitsAvail = 1;
                msg->m_nInBufWord = 0;
                LOWORD(v158) = v159;
              }
              else
              {
                if ( v158 <= (unsigned int)v161 )
                {
                  v162 = *(_DWORD *)v158;
                  msg->m_pDataIn = (const unsigned int *)(v158 + 4);
                  msg->m_nInBufWord = v162;
                }
                else
                {
                  msg->m_bOverflow = true;
                  msg->m_nInBufWord = 0;
                }
                LOWORD(v158) = v159;
              }
            }
            goto LABEL_236;
          }
          v163 = msg->m_pBufferEnd;
          v164 = msg->m_nInBufWord;
          v158 = 16 - v157;
          v165 = msg->m_pDataIn;
          if ( v165 == v163 )
          {
            msg->m_nBitsAvail = 1;
            msg->m_nInBufWord = 0;
            msg->m_bOverflow = true;
          }
          else
          {
            if ( v165 > v163 )
            {
              msg->m_bOverflow = true;
              msg->m_nInBufWord = 0;
              goto LABEL_233;
            }
            msg->m_nInBufWord = *v165;
          }
          msg->m_pDataIn = v165 + 1;
LABEL_233:
          if ( msg->m_bOverflow )
          {
            LOWORD(v158) = 0;
          }
          else
          {
            v166 = msg->m_nInBufWord;
            v136 = (v166 & CBitBuffer::s_nMaskTable[v158]) << msg->m_nBitsAvail;
            msg->m_nBitsAvail = 32 - v158;
            v167 = v136 | v164;
            LOBYTE(v136) = (_BYTE)sType;
            v168 = v166 >> v158;
            LOWORD(v158) = v167;
            msg->m_nInBufWord = v168;
          }
LABEL_236:
          v169 = (void (*)(const char *, ...))_Msg;
          _Msg(a1: "Spectator Port: %u\n", (unsigned __int16)v158);
          CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
          _Msg(a1: "SpectatorName : %s\n", str);
          goto LABEL_238;
        }
        v150 = msg->m_pDataIn;
        v151 = msg->m_pBufferEnd;
        msg->m_nBitsAvail = 32;
        if ( v150 == v151 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_pDataIn = v150 + 1;
        }
        else if ( v150 <= v151 )
        {
          v149 = *v150;
          msg->m_pDataIn = v150 + 1;
        }
        else
        {
          msg->m_bOverflow = true;
        }
        goto LABEL_215;
      }
      v152 = msg->m_pBufferEnd;
      v153 = msg->m_nInBufWord;
      v154 = 16 - v145;
      v155 = msg->m_pDataIn;
      if ( v155 == v152 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_bOverflow = true;
      }
      else
      {
        if ( v155 > v152 )
        {
          msg->m_bOverflow = true;
          msg->m_nInBufWord = 0;
LABEL_212:
          if ( msg->m_bOverflow )
          {
            v147 = 0;
            goto LABEL_216;
          }
          v156 = msg->m_nInBufWord;
          v136 = (v156 & CBitBuffer::s_nMaskTable[v154]) << msg->m_nBitsAvail;
          msg->m_nBitsAvail = 32 - v154;
          v147 = v136 | v153;
          LOBYTE(v136) = (_BYTE)sType;
          v149 = v156 >> v154;
LABEL_215:
          msg->m_nInBufWord = v149;
          goto LABEL_216;
        }
        msg->m_nInBufWord = *v155;
      }
      msg->m_pDataIn = v155 + 1;
      goto LABEL_212;
    }
    v139 = msg->m_pBufferEnd;
    v140 = msg->m_nInBufWord;
    v141 = 8 - v132;
    v142 = msg->m_pDataIn;
    if ( v142 == v139 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v142 > v139 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_194;
      }
      msg->m_nInBufWord = *v142;
    }
    msg->m_pDataIn = v142 + 1;
LABEL_194:
    if ( msg->m_bOverflow )
    {
      v136 = 0;
    }
    else
    {
      v143 = msg->m_nInBufWord;
      v144 = (v143 & CBitBuffer::s_nMaskTable[v141]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v141;
      v136 = v140 | v144;
      msg->m_nInBufWord = v143 >> v141;
    }
    goto LABEL_197;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F9B0
// Name: public: virtual bool CBaseClientState::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessConnectionlessPacket(CBaseClientState *this, netpacket_s *packet)
{
  bf_read *p_message; // ebx
  int m_nBitsAvail; // ecx
  unsigned int v4; // eax
  int v5; // ecx
  unsigned int v6; // edx
  int v7; // esi
  const unsigned int *v8; // eax
  const unsigned int *v9; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // esi
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  netadr_s *v17; // eax
  int v18; // ecx
  unsigned int v19; // edx
  int v20; // ecx
  int v21; // eax
  const unsigned int *v22; // eax
  const unsigned int *v23; // ecx
  unsigned int v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // esi
  int v27; // eax
  const unsigned int *v28; // ecx
  unsigned int v29; // edx
  unsigned int v30; // edi
  unsigned int v31; // edx
  CBaseClientState *v32; // esi
  int v33; // ecx
  unsigned int v34; // edx
  int v35; // ecx
  int v36; // eax
  const unsigned int *v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // ecx
  const unsigned int *v40; // edx
  unsigned int v41; // esi
  int v42; // eax
  const unsigned int *v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edi
  unsigned int v46; // edx
  int v47; // ecx
  unsigned int v48; // eax
  int v49; // ecx
  __int16 v50; // dx
  __int16 v51; // si
  const unsigned int *v52; // eax
  const unsigned int *v53; // ecx
  const unsigned int *v54; // edx
  unsigned int v55; // esi
  int v56; // eax
  const unsigned int *v57; // ecx
  unsigned int v58; // edx
  unsigned int v59; // edi
  int v60; // ecx
  unsigned int v61; // eax
  int v62; // ecx
  unsigned int v63; // edx
  const unsigned int *v64; // eax
  const unsigned int *v65; // ecx
  unsigned int v66; // ecx
  const unsigned int *v67; // edx
  unsigned int v68; // esi
  int v69; // eax
  const unsigned int *v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // edx
  bool v74; // zf
  CBaseClientState *v75; // eax
  int v76; // eax
  int v77; // eax
  const unsigned int *v78; // eax
  const unsigned int *v79; // ecx
  const unsigned int *v80; // edx
  int v81; // ecx
  const unsigned int *v82; // eax
  int v83; // eax
  int v84; // eax
  const unsigned int *v85; // eax
  const unsigned int *v86; // ecx
  const unsigned int *v87; // edx
  int v88; // ecx
  const unsigned int *v89; // eax
  int v90; // eax
  int v91; // eax
  CBaseClientState *v92; // esi
  int v93; // ecx
  unsigned int v94; // edx
  int v95; // ecx
  int v96; // edi
  const unsigned int *v97; // eax
  const unsigned int *v98; // ecx
  int v99; // eax
  const unsigned int *v100; // ecx
  const unsigned int *v101; // edx
  unsigned int v102; // edx
  unsigned int v103; // edi
  int HostVersion; // eax
  int v105; // ecx
  unsigned int v106; // eax
  int v107; // ecx
  unsigned int v108; // edx
  const unsigned int *v109; // eax
  const unsigned int *v110; // ecx
  unsigned int v111; // ecx
  int v112; // eax
  const unsigned int *v113; // ecx
  const unsigned int *v114; // edx
  unsigned int v115; // edx
  unsigned int v116; // edi
  unsigned int v117; // edx
  __int64 LongLong; // rax
  const char *v119; // ecx
  int v120; // ecx
  char *m_pszString; // ecx
  IEngineVGuiInternal *v122; // eax
  char *v123; // edx
  int v124; // eax
  int v125; // eax
  const char *v126; // eax
  int v127; // ecx
  unsigned int v128; // edx
  int v129; // esi
  const unsigned int *v130; // eax
  const unsigned int *v131; // ecx
  const unsigned int *v132; // edx
  unsigned int v133; // esi
  int v134; // eax
  const unsigned int *v135; // ecx
  unsigned int v136; // edx
  unsigned int v137; // edi
  unsigned int v138; // eax
  int v139; // edx
  const unsigned int *v140; // eax
  const unsigned int *v141; // ecx
  KeyValues *v142; // eax
  KeyValues *v143; // esi
  IMatchEventsSubscription *v144; // eax
  const char *v145; // eax
  __int64 v146; // [esp-8h] [ebp-5F0h]
  char string[1200]; // [esp+Ch] [ebp-5DCh] BYREF
  char context[256]; // [esp+4BCh] [ebp-12Ch] BYREF
  bf_read msgOriginal; // [esp+5BCh] [ebp-2Ch]
  netadr_s *adrRemote; // [esp+5E0h] [ebp-8h]
  CBaseClientState *v151; // [esp+5E4h] [ebp-4h]

  p_message = &packet->message;
  v151 = this;
  msgOriginal = packet->message;
  m_nBitsAvail = packet->message.m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = packet->message.m_pBufferEnd;
    m_nInBufWord = packet->message.m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = packet->message.m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
LABEL_15:
        if ( packet->message.m_bOverflow )
        {
          v7 = 0;
          goto LABEL_19;
        }
        v14 = packet->message.m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << packet->message.m_nBitsAvail;
        packet->message.m_nBitsAvail = 32 - v12;
        v7 = v15 | m_nInBufWord;
        v6 = v14 >> v12;
        goto LABEL_18;
      }
      packet->message.m_nInBufWord = *m_pDataIn;
    }
    packet->message.m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = packet->message.m_nInBufWord;
  v5 = m_nBitsAvail - 8;
  v6 = 0;
  v7 = (unsigned __int8)v4;
  packet->message.m_nBitsAvail = v5;
  if ( v5 == 0 )
  {
    v8 = packet->message.m_pDataIn;
    v9 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v8 + 1;
      goto LABEL_19;
    }
    if ( v8 <= v9 )
    {
      packet->message.m_nInBufWord = *v8;
      packet->message.m_pDataIn = v8 + 1;
      goto LABEL_19;
    }
    packet->message.m_bOverflow = true;
LABEL_18:
    packet->message.m_nInBufWord = v6;
    goto LABEL_19;
  }
  packet->message.m_nInBufWord = v4 >> 8;
LABEL_19:
  switch ( v7 )
  {
    case 0:
      *p_message = msgOriginal;
      v142 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v142 != nullptr )
        v143 = KeyValues::KeyValues(this: v142, setName: "OnNetLanConnectionlessPacket");
      else
        v143 = nullptr;
      KeyValues::SetPtr(this: v143, keyName: "rawpkt", value: packet);
      v144 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v144->BroadcastEvent(this: v144, a2: v143);
      return 1;
    case 57:
      if ( HIDWORD(v151->m_ListenServerSteamID) != 1 )
        return 1;
      CBitRead::ReadString(this: p_message, pStr: string, maxLen: 1200, bLine: false, pOutNumChars: nullptr);
      COM_ExplainDisconnection(bPrint: true, fmt: string);
      (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v151[-1].m_bRestrictServerCommands + 64))(
        a1: &v151[-1].m_bRestrictServerCommands,
        a2: 1);
      return 1;
    case 65:
      if ( !netadr_s::IsLocalhost(this: &packet->from)
        && !netadr_s::IsLoopback(this: &packet->from)
        && cl_failremoteconnections.m_pParent != nullptr
        && cl_failremoteconnections.m_pParent->m_Value.m_nValue != 0 )
      {
        return 1;
      }
      v17 = (netadr_s *)v151;
      *(&v151->m_bWaitingForServerGameDetails + 2) = false;
      v17 = (netadr_s *)((char *)v17 + 460);
      *v17 = packet->from;
      v18 = packet->message.m_nBitsAvail;
      adrRemote = v17;
      if ( v18 < 32 )
      {
        v25 = packet->message.m_pBufferEnd;
        v26 = packet->message.m_nInBufWord;
        v27 = 32 - v18;
        v28 = packet->message.m_pDataIn;
        if ( v28 == v25 )
        {
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          packet->message.m_bOverflow = true;
        }
        else
        {
          if ( v28 > v25 )
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
            goto LABEL_41;
          }
          packet->message.m_nInBufWord = *v28;
        }
        packet->message.m_pDataIn = v28 + 1;
LABEL_41:
        if ( packet->message.m_bOverflow )
        {
          v21 = 0;
        }
        else
        {
          v29 = packet->message.m_nInBufWord;
          v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << packet->message.m_nBitsAvail;
          packet->message.m_nBitsAvail = 32 - v27;
          v31 = v29 >> v27;
          v21 = v30 | v26;
          packet->message.m_nInBufWord = v31;
        }
        goto LABEL_44;
      }
      v19 = packet->message.m_nInBufWord;
      v20 = v18 - 32;
      packet->message.m_nBitsAvail = v20;
      if ( v20 != 0 )
      {
        packet->message.m_nInBufWord = 0;
        v21 = v19;
      }
      else
      {
        v22 = packet->message.m_pDataIn;
        v23 = packet->message.m_pBufferEnd;
        packet->message.m_nBitsAvail = 32;
        if ( v22 == v23 )
        {
          packet->message.m_pDataIn = v22 + 1;
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          v21 = v19;
        }
        else
        {
          if ( v22 <= v23 )
          {
            v24 = *v22;
            packet->message.m_pDataIn = v22 + 1;
            packet->message.m_nInBufWord = v24;
          }
          else
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
          }
          v21 = v19;
        }
      }
LABEL_44:
      v32 = v151;
      *(_DWORD *)&v151->m_DeferredConnection.m_chLobbyType[13] = v21;
      v33 = packet->message.m_nBitsAvail;
      if ( v33 >= 32 )
      {
        v34 = packet->message.m_nInBufWord;
        v35 = v33 - 32;
        packet->message.m_nBitsAvail = v35;
        if ( v35 != 0 )
        {
          packet->message.m_nInBufWord = 0;
          v36 = v34;
        }
        else
        {
          v37 = packet->message.m_pDataIn;
          v38 = packet->message.m_pBufferEnd;
          packet->message.m_nBitsAvail = 32;
          if ( v37 == v38 )
          {
            packet->message.m_pDataIn = v37 + 1;
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            v36 = v34;
          }
          else
          {
            if ( v37 <= v38 )
            {
              v39 = *v37;
              packet->message.m_pDataIn = v37 + 1;
              packet->message.m_nInBufWord = v39;
            }
            else
            {
              packet->message.m_bOverflow = true;
              packet->message.m_nInBufWord = 0;
            }
            v36 = v34;
          }
        }
        goto LABEL_63;
      }
      v40 = packet->message.m_pBufferEnd;
      v41 = packet->message.m_nInBufWord;
      v42 = 32 - v33;
      v43 = packet->message.m_pDataIn;
      if ( v43 == v40 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_bOverflow = true;
LABEL_58:
        packet->message.m_pDataIn = v43 + 1;
        goto LABEL_59;
      }
      if ( v43 <= v40 )
      {
        packet->message.m_nInBufWord = *v43;
        goto LABEL_58;
      }
      packet->message.m_bOverflow = true;
      packet->message.m_nInBufWord = 0;
LABEL_59:
      if ( packet->message.m_bOverflow )
      {
        v36 = 0;
      }
      else
      {
        v44 = packet->message.m_nInBufWord;
        v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << packet->message.m_nBitsAvail;
        packet->message.m_nBitsAvail = 32 - v42;
        v46 = v44 >> v42;
        v36 = v45 | v41;
        packet->message.m_nInBufWord = v46;
      }
      v32 = v151;
LABEL_63:
      v32->m_DeferredConnection.m_nChallenge = v36;
      *(&v32->m_DeferredConnection.m_nAuthprotocol + 1) = 0;
      LODWORD(v32->m_DeferredConnection.m_unGSSteamID) = 0;
      *(&v32->m_bWaitingForServerGameDetails + 3) = false;
      if ( v36 == 3 )
      {
        v47 = packet->message.m_nBitsAvail;
        if ( v47 >= 16 )
        {
          v48 = packet->message.m_nInBufWord;
          v49 = v47 - 16;
          v50 = v48;
          packet->message.m_nBitsAvail = v49;
          if ( v49 != 0 )
          {
            packet->message.m_nInBufWord = HIWORD(v48);
            v51 = v48;
          }
          else
          {
            v52 = packet->message.m_pDataIn;
            v53 = packet->message.m_pBufferEnd;
            packet->message.m_nBitsAvail = 32;
            if ( v52 == v53 )
            {
              packet->message.m_nBitsAvail = 1;
              packet->message.m_nInBufWord = 0;
              packet->message.m_pDataIn = v52 + 1;
              v51 = v50;
            }
            else
            {
              if ( v52 <= v53 )
              {
                packet->message.m_nInBufWord = *v52;
                packet->message.m_pDataIn = v52 + 1;
              }
              else
              {
                packet->message.m_bOverflow = true;
                packet->message.m_nInBufWord = 0;
              }
              v51 = v50;
            }
          }
          goto LABEL_81;
        }
        v54 = packet->message.m_pBufferEnd;
        v55 = packet->message.m_nInBufWord;
        v56 = 16 - v47;
        v57 = packet->message.m_pDataIn;
        if ( v57 == v54 )
        {
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          packet->message.m_bOverflow = true;
        }
        else
        {
          if ( v57 > v54 )
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
LABEL_79:
            if ( !packet->message.m_bOverflow )
            {
              v58 = packet->message.m_nInBufWord;
              v59 = (v58 & CBitBuffer::s_nMaskTable[v56]) << packet->message.m_nBitsAvail;
              packet->message.m_nBitsAvail = 32 - v56;
              v51 = v59 | v55;
              packet->message.m_nInBufWord = v58 >> v56;
LABEL_81:
              if ( v51 != 0 )
              {
                _Msg(a1: "Invalid Steam key size.\n");
                (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v151[-1].m_bRestrictServerCommands + 64))(
                  a1: &v151[-1].m_bRestrictServerCommands,
                  a2: 1);
                return 0;
              }
            }
            *(_QWORD *)(&v151->m_DeferredConnection.m_nAuthprotocol + 1) = CBitRead::ReadLongLong(this: p_message);
            v60 = packet->message.m_nBitsAvail;
            if ( v60 >= 8 )
            {
              v61 = packet->message.m_nInBufWord;
              v62 = v60 - 8;
              v63 = (unsigned __int8)v61;
              packet->message.m_nBitsAvail = v62;
              if ( v62 != 0 )
              {
                packet->message.m_nInBufWord = v61 >> 8;
                v61 = (unsigned __int8)v61;
              }
              else
              {
                v64 = packet->message.m_pDataIn;
                v65 = packet->message.m_pBufferEnd;
                packet->message.m_nBitsAvail = 32;
                if ( v64 == v65 )
                {
                  packet->message.m_pDataIn = v64 + 1;
                  packet->message.m_nBitsAvail = 1;
                  packet->message.m_nInBufWord = 0;
                  v61 = v63;
                }
                else
                {
                  if ( v64 <= v65 )
                  {
                    v66 = *v64;
                    packet->message.m_pDataIn = v64 + 1;
                    packet->message.m_nInBufWord = v66;
                  }
                  else
                  {
                    packet->message.m_bOverflow = true;
                    packet->message.m_nInBufWord = 0;
                  }
                  v61 = v63;
                }
              }
              goto LABEL_101;
            }
            v67 = packet->message.m_pBufferEnd;
            v68 = packet->message.m_nInBufWord;
            v69 = 8 - v60;
            v70 = packet->message.m_pDataIn;
            if ( v70 == v67 )
            {
              packet->message.m_nBitsAvail = 1;
              packet->message.m_nInBufWord = 0;
              packet->message.m_bOverflow = true;
            }
            else
            {
              if ( v70 > v67 )
              {
                packet->message.m_bOverflow = true;
                packet->message.m_nInBufWord = 0;
                goto LABEL_98;
              }
              packet->message.m_nInBufWord = *v70;
            }
            packet->message.m_pDataIn = v70 + 1;
LABEL_98:
            if ( packet->message.m_bOverflow )
            {
              v61 = 0;
            }
            else
            {
              v71 = packet->message.m_nInBufWord;
              v72 = (v71 & CBitBuffer::s_nMaskTable[v69]) << packet->message.m_nBitsAvail;
              packet->message.m_nBitsAvail = 32 - v69;
              v73 = v71 >> v69;
              v61 = v72 | v68;
              packet->message.m_nInBufWord = v73;
            }
LABEL_101:
            v74 = v61 == 0;
            v75 = v151;
            *(&v151->m_bWaitingForServerGameDetails + 3) = !v74;
            v32 = v75;
            goto LABEL_134;
          }
          packet->message.m_nInBufWord = *v57;
        }
        packet->message.m_pDataIn = v57 + 1;
        goto LABEL_79;
      }
      v76 = packet->message.m_nBitsAvail;
      if ( v76 >= 16 )
      {
        v77 = v76 - 16;
        packet->message.m_nBitsAvail = v77;
        if ( v77 != 0 )
        {
          packet->message.m_nInBufWord = HIWORD(packet->message.m_nInBufWord);
        }
        else
        {
          v78 = packet->message.m_pDataIn;
          v79 = packet->message.m_pBufferEnd;
          packet->message.m_nBitsAvail = 32;
          if ( v78 == v79 )
          {
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            packet->message.m_pDataIn = v78 + 1;
          }
          else if ( v78 <= v79 )
          {
            packet->message.m_nInBufWord = *v78;
            packet->message.m_pDataIn = v78 + 1;
          }
          else
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
          }
        }
        goto LABEL_118;
      }
      v80 = packet->message.m_pBufferEnd;
      v81 = 16 - v76;
      v82 = packet->message.m_pDataIn;
      if ( v82 == v80 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_bOverflow = true;
      }
      else
      {
        if ( v82 > v80 )
        {
          packet->message.m_bOverflow = true;
          packet->message.m_nInBufWord = 0;
          goto LABEL_116;
        }
        packet->message.m_nInBufWord = *v82;
      }
      packet->message.m_pDataIn = v82 + 1;
LABEL_116:
      if ( !packet->message.m_bOverflow )
      {
        packet->message.m_nInBufWord >>= v81;
        packet->message.m_nBitsAvail = 32 - v81;
      }
LABEL_118:
      CBitRead::ReadLongLong(this: p_message);
      v83 = packet->message.m_nBitsAvail;
      if ( v83 >= 8 )
      {
        v84 = v83 - 8;
        packet->message.m_nBitsAvail = v84;
        if ( v84 != 0 )
        {
          packet->message.m_nInBufWord >>= 8;
        }
        else
        {
          v85 = packet->message.m_pDataIn;
          v86 = packet->message.m_pBufferEnd;
          packet->message.m_nBitsAvail = 32;
          if ( v85 == v86 )
          {
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            packet->message.m_pDataIn = v85 + 1;
          }
          else if ( v85 <= v86 )
          {
            packet->message.m_nInBufWord = *v85;
            packet->message.m_pDataIn = v85 + 1;
          }
          else
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
          }
        }
        goto LABEL_134;
      }
      v87 = packet->message.m_pBufferEnd;
      v88 = 8 - v83;
      v89 = packet->message.m_pDataIn;
      if ( v89 == v87 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_bOverflow = true;
LABEL_131:
        packet->message.m_pDataIn = v89 + 1;
        goto LABEL_132;
      }
      if ( v89 <= v87 )
      {
        packet->message.m_nInBufWord = *v89;
        goto LABEL_131;
      }
      packet->message.m_bOverflow = true;
      packet->message.m_nInBufWord = 0;
LABEL_132:
      if ( packet->message.m_bOverflow )
      {
LABEL_135:
        _Msg(a1: "Invalid challenge packet.\n");
        (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v32[-1].m_bRestrictServerCommands + 64))(
          a1: &v32[-1].m_bRestrictServerCommands,
          a2: 1);
        return 0;
      }
      packet->message.m_nInBufWord >>= v88;
      packet->message.m_nBitsAvail = 32 - v88;
LABEL_134:
      if ( packet->message.m_bOverflow )
        goto LABEL_135;
      memset(context, 0, sizeof(context));
      CBitRead::ReadString(this: p_message, pStr: context, maxLen: 256, bLine: false, pOutNumChars: nullptr);
      v90 = _V_strlen(str: "reserve");
      if ( V_strnicmp(s1: context, s2: "reserve", n: v90) == 0 )
      {
        (*(void (__thiscall **)(bool *, _DWORD))(*(_DWORD *)&v32[-1].m_bRestrictServerCommands + 120))(
          a1: &v32[-1].m_bRestrictServerCommands,
          a2: *(_DWORD *)&v32->m_DeferredConnection.m_chLobbyType[13]);
        return 1;
      }
      v91 = _V_strlen(str: "connect");
      if ( V_strnicmp(s1: context, s2: "connect", n: v91) != 0 )
        return 1;
      v92 = v151;
      if ( HIDWORD(v151->m_ListenServerSteamID) != 1 )
        return 0;
      *(&v151->m_bWaitingForServerGameDetails + 2) = true;
      v93 = packet->message.m_nBitsAvail;
      if ( v93 < 32 )
      {
        v99 = 32 - v93;
        v100 = packet->message.m_pDataIn;
        v151 = (CBaseClientState *)packet->message.m_nInBufWord;
        v101 = packet->message.m_pBufferEnd;
        if ( v100 == v101 )
        {
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          packet->message.m_bOverflow = true;
        }
        else
        {
          if ( v100 > v101 )
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
            goto LABEL_155;
          }
          packet->message.m_nInBufWord = *v100;
        }
        packet->message.m_pDataIn = v100 + 1;
LABEL_155:
        if ( packet->message.m_bOverflow )
        {
          v96 = 0;
        }
        else
        {
          v102 = packet->message.m_nInBufWord;
          v103 = (v102 & CBitBuffer::s_nMaskTable[v99]) << packet->message.m_nBitsAvail;
          packet->message.m_nBitsAvail = 32 - v99;
          v96 = v103 | (unsigned int)v151;
          packet->message.m_nInBufWord = v102 >> v99;
        }
        goto LABEL_158;
      }
      v94 = packet->message.m_nInBufWord;
      v95 = v93 - 32;
      packet->message.m_nBitsAvail = v95;
      if ( v95 != 0 )
      {
        packet->message.m_nInBufWord = 0;
        v96 = v94;
      }
      else
      {
        v97 = packet->message.m_pDataIn;
        v98 = packet->message.m_pBufferEnd;
        packet->message.m_nBitsAvail = 32;
        if ( v97 == v98 )
        {
          packet->message.m_nInBufWord = 0;
          packet->message.m_nBitsAvail = 1;
          packet->message.m_pDataIn = v97 + 1;
          v96 = v94;
        }
        else
        {
          if ( v97 <= v98 )
          {
            packet->message.m_nInBufWord = *v97;
            packet->message.m_pDataIn = v97 + 1;
          }
          else
          {
            packet->message.m_nInBufWord = 0;
            packet->message.m_bOverflow = true;
          }
          v96 = v94;
        }
      }
LABEL_158:
      if ( v96 != GetHostVersion() )
      {
        HostVersion = GetHostVersion();
        _Msg(a1: "Invalid GetHostVersion(), expecting %d, got %d\n", HostVersion, v96);
        (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v92[-1].m_bRestrictServerCommands + 64))(
          a1: &v92[-1].m_bRestrictServerCommands,
          a2: 1);
        return 0;
      }
      CBitRead::ReadString(
        this: p_message,
        pStr: (char *)&v92->m_bWaitingForServerGameDetails + 5,
        maxLen: 15,
        bLine: false,
        pOutNumChars: nullptr);
      v105 = packet->message.m_nBitsAvail;
      if ( v105 < 8 )
      {
        v112 = 8 - v105;
        v113 = packet->message.m_pDataIn;
        v151 = (CBaseClientState *)packet->message.m_nInBufWord;
        v114 = packet->message.m_pBufferEnd;
        if ( v113 == v114 )
        {
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          packet->message.m_bOverflow = true;
        }
        else
        {
          if ( v113 > v114 )
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
            goto LABEL_175;
          }
          packet->message.m_nInBufWord = *v113;
        }
        packet->message.m_pDataIn = v113 + 1;
LABEL_175:
        if ( packet->message.m_bOverflow )
        {
          v106 = 0;
        }
        else
        {
          v115 = packet->message.m_nInBufWord;
          v116 = (v115 & CBitBuffer::s_nMaskTable[v112]) << packet->message.m_nBitsAvail;
          packet->message.m_nBitsAvail = 32 - v112;
          v117 = v115 >> v112;
          v106 = v116 | (unsigned int)v151;
          packet->message.m_nInBufWord = v117;
        }
        goto LABEL_178;
      }
      v106 = packet->message.m_nInBufWord;
      v107 = v105 - 8;
      v108 = (unsigned __int8)v106;
      packet->message.m_nBitsAvail = v107;
      if ( v107 != 0 )
      {
        packet->message.m_nInBufWord = v106 >> 8;
        v106 = (unsigned __int8)v106;
      }
      else
      {
        v109 = packet->message.m_pDataIn;
        v110 = packet->message.m_pBufferEnd;
        packet->message.m_nBitsAvail = 32;
        if ( v109 == v110 )
        {
          packet->message.m_pDataIn = v109 + 1;
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          v106 = v108;
        }
        else
        {
          if ( v109 <= v110 )
          {
            v111 = *v109;
            packet->message.m_pDataIn = v109 + 1;
            packet->message.m_nInBufWord = v111;
          }
          else
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
          }
          v106 = v108;
        }
      }
LABEL_178:
      *(&v92->m_bWaitingForServerGameDetails + 4) = v106 == 1;
      LongLong = CBitRead::ReadLongLong(this: p_message);
      v74 = !*(&v92->m_bWaitingForServerGameDetails + 4);
      *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) = LongLong;
      v119 = "yes";
      if ( v74 )
        v119 = "no";
      LODWORD(LongLong) = &v92->m_bWaitingForServerGameDetails + 5;
      if ( !*(&v92->m_bWaitingForServerGameDetails + 5) )
        LODWORD(LongLong) = "<none>";
      HIDWORD(v146) = HIDWORD(LongLong);
      LODWORD(v146) = HIDWORD(v92->m_DeferredConnection.m_unGSSteamID);
      _Msg(a1: "Server using '%s' lobbies, requiring pw %s, lobby id %llx\n", (const char *)LongLong, v119, v146);
      CBaseClientState::RememberIPAddressForLobby(
        this: (CBaseClientState *)((char *)v92 - 4),
        unLobbyID: *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4),
        adrRemote);
      if ( *(&v92->m_bWaitingForServerGameDetails + 5) )
      {
        if ( sv.m_State < ss_active
          && *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) == 0
          && *(_QWORD *)&v92->m_pServerReservationCallback != 0 )
        {
          _Warning(a1: "Server error - failed to handle reservation request.\n");
          (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v92[-1].m_bRestrictServerCommands + 64))(
            a1: &v92[-1].m_bRestrictServerCommands,
            a2: 1);
          return 0;
        }
LABEL_199:
        v124 = _V_strlen(str: "connect-retry");
        if ( V_strnicmp(s1: context, s2: "connect-retry", n: v124) == 0
          && *(&v92->m_bWaitingForServerGameDetails + 5)
          && sv.m_State < ss_active
          && *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) == 0 )
        {
          _Msg(a1: "Grace request retry for unreserved server...\n");
          (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v92[-1].m_bRestrictServerCommands + 80))(
            a1: &v92[-1].m_bRestrictServerCommands,
            a2: 1);
          return 1;
        }
        v125 = _V_strlen(str: "connect-granted");
        if ( V_strnicmp(s1: context, s2: "connect-granted", n: v125) != 0 )
        {
          if ( !*(&v92->m_bWaitingForServerGameDetails + 5) )
          {
LABEL_213:
            CBaseClientState::HandleDeferredConnection(this: (CBaseClientState *)((char *)v92 - 4));
            return 1;
          }
          if ( sv.m_State < ss_active
            && *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) == 0 )
          {
            _Msg(a1: "Server did not approve grace request, retrying...\n");
            (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v92[-1].m_bRestrictServerCommands + 80))(
              a1: &v92[-1].m_bRestrictServerCommands,
              a2: 1);
            return 1;
          }
        }
        if ( *(&v92->m_bWaitingForServerGameDetails + 5)
          && sv.m_State < ss_active
          && *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) == 0 )
        {
          _Msg(a1: "Server approved grace request...\n");
        }
        goto LABEL_213;
      }
      v120 = LODWORD(v92->m_DeferredConnection.m_unLobbyID) | HIDWORD(v92->m_DeferredConnection.m_unGSSteamID);
      if ( *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) != 0 )
        goto LABEL_199;
      if ( *(&v92->m_bWaitingForServerGameDetails + 4) == (_BYTE)v120 )
        goto LABEL_199;
      if ( LOBYTE(v92->m_netadrReserveServer.m_List.m_pElements) != (_BYTE)v120 )
      {
        if ( (password.m_nFlags & 0x1000) != 0 )
          goto LABEL_199;
        m_pszString = password.m_pParent->m_Value.m_pszString;
        if ( m_pszString != nullptr && *m_pszString != 0 )
          goto LABEL_199;
      }
      BYTE1(v92->m_netadrReserveServer.m_List.m_pElements) = 1;
      SCR_EndLoadingPlaque();
      v122 = EngineVGui();
      if ( (password.m_nFlags & 0x1000) != 0 )
      {
        v122->ShowPasswordUI(this: v122, a2: "FCVAR_NEVER_AS_STRING");
        return 1;
      }
      else
      {
        v123 = password.m_pParent->m_Value.m_pszString;
        if ( v123 == nullptr )
          v123 = (char *)defaultValue;
        v122->ShowPasswordUI(this: v122, a2: v123);
        return 1;
      }
    case 66:
      if ( HIDWORD(v151->m_ListenServerSteamID) != 1 )
        return 1;
      (*(void (__thiscall **)(bool *, netpacket_s *))(*(_DWORD *)&v151[-1].m_bRestrictServerCommands + 48))(
        a1: &v151[-1].m_bRestrictServerCommands,
        a2: packet);
      return 1;
    case 73:
      Read_S2A_INFO_SRC(from: &packet->from, msg: p_message);
      return 1;
    case 105:
      NET_OutOfBandPrintf(
        sock: (int)v151->IServerMessageHandler::INetMessageHandler::__vftable,
        adr: &packet->from,
        format: "%c00000000000000",
        106);
      return 1;
    case 106:
      v126 = netadr_s::ToString(this: &packet->from, baseOnly: false);
      ConMsg(a1: "A2A_ACK from %s\n", v126);
      return 1;
    case 108:
      if ( !CBitRead::ReadString(this: p_message, pStr: string, maxLen: 1200, bLine: false, pOutNumChars: nullptr) )
        return 1;
      ConMsg(a1: "%s\n", string);
      return 1;
    case 112:
      v127 = packet->message.m_nBitsAvail;
      if ( v127 >= 32 )
      {
        v128 = packet->message.m_nInBufWord;
        packet->message.m_nBitsAvail = v127 - 32;
        if ( v127 == 32 )
        {
          v130 = packet->message.m_pDataIn;
          v131 = packet->message.m_pBufferEnd;
          packet->message.m_nBitsAvail = 32;
          if ( v130 == v131 )
          {
            packet->message.m_nInBufWord = 0;
            packet->message.m_nBitsAvail = 1;
            packet->message.m_pDataIn = v130 + 1;
            v129 = v128;
          }
          else
          {
            if ( v130 <= v131 )
            {
              packet->message.m_nInBufWord = *v130;
              packet->message.m_pDataIn = v130 + 1;
            }
            else
            {
              packet->message.m_nInBufWord = 0;
              packet->message.m_bOverflow = true;
            }
            v129 = v128;
          }
        }
        else
        {
          packet->message.m_nInBufWord = 0;
          v129 = v128;
        }
LABEL_238:
        if ( v129 == GetHostVersion() )
        {
          v138 = packet->message.m_nInBufWord;
          v139 = v138 & 1;
          v74 = packet->message.m_nBitsAvail-- == 1;
          if ( v74 )
          {
            v140 = packet->message.m_pDataIn;
            v141 = packet->message.m_pBufferEnd;
            packet->message.m_nBitsAvail = 32;
            if ( v140 == v141 )
            {
              packet->message.m_nBitsAvail = 1;
              packet->message.m_nInBufWord = 0;
              packet->message.m_pDataIn = v140 + 1;
            }
            else if ( v140 <= v141 )
            {
              packet->message.m_nInBufWord = *v140;
              packet->message.m_pDataIn = v140 + 1;
            }
            else
            {
              packet->message.m_bOverflow = true;
              packet->message.m_nInBufWord = 0;
            }
          }
          else
          {
            packet->message.m_nInBufWord = v138 >> 1;
          }
          (*(void (__thiscall **)(bool *, netpacket_s *, bool))(*(_DWORD *)&v151[-1].m_bRestrictServerCommands + 116))(
            a1: &v151[-1].m_bRestrictServerCommands,
            a2: packet,
            a3: v139 != 0);
        }
        return 1;
      }
      v132 = packet->message.m_pBufferEnd;
      v133 = packet->message.m_nInBufWord;
      v134 = 32 - v127;
      v135 = packet->message.m_pDataIn;
      if ( v135 == v132 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_bOverflow = true;
      }
      else
      {
        if ( v135 > v132 )
        {
          packet->message.m_bOverflow = true;
          packet->message.m_nInBufWord = 0;
          goto LABEL_235;
        }
        packet->message.m_nInBufWord = *v135;
      }
      packet->message.m_pDataIn = v135 + 1;
LABEL_235:
      if ( packet->message.m_bOverflow )
      {
        v129 = 0;
      }
      else
      {
        v136 = packet->message.m_nInBufWord;
        v137 = (v136 & CBitBuffer::s_nMaskTable[v134]) << packet->message.m_nBitsAvail;
        packet->message.m_nBitsAvail = 32 - v134;
        v129 = v137 | v133;
        packet->message.m_nInBufWord = v136 >> v134;
      }
      goto LABEL_238;
    case 116:
      return 1;
    default:
      v145 = netadr_s::ToString(this: &packet->from, baseOnly: false);
      _ConDMsg(a1: "Bad connectionless packet ( CL '%c') from %s.\n", v7, v145);
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060950
// Name: public: virtual void CBaseClientState::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseClientState::OnEvent(CBaseClientState *this@<ecx>, int a2@<ebx>, KeyValues *pEvent)
{
  const char *Name; // eax
  KeyValues *Key; // eax
  const char *String; // eax
  int v7; // edi
  int i; // ebx
  const char *v9; // eax
  Remote_t *v10; // edi
  const char *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  IMatchEventsSubscription *v16; // eax
  const char *v17; // [esp-8h] [ebp-14h]
  KeyValues *pGameDetailsServer; // [esp+8h] [ebp-4h]
  const char *szDetailsAdr; // [esp+14h] [ebp+8h]

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnNetLanConnectionlessPacket", s2: Name) == 0 )
  {
    Key = KeyValues::FindKey(this: pEvent, keyName: "GameDetailsServer", bCreate: false);
    pGameDetailsServer = Key;
    if ( Key != nullptr )
    {
      String = KeyValues::GetString(
                 this: Key,
                 keyName: "ConnectServerDetailsRequest/server",
                 defaultValue: defaultValue);
      szDetailsAdr = String;
      if ( this->m_bWaitingForServerGameDetails && String != nullptr && *String != 0 )
      {
        v7 = 0;
        if ( this->m_Remote.m_List.m_Size > 0 )
        {
          for ( i = 0; ; ++i )
          {
            v17 = String;
            v9 = netadr_s::ToString(this: &this->m_Remote.m_List.m_Memory.m_pMemory[i].m_adrRemote, baseOnly: false);
            if ( _V_stricmp(s1: v9, s2: v17) == 0 )
              break;
            if ( ++v7 >= this->m_Remote.m_List.m_Size )
              return;
            String = szDetailsAdr;
          }
          if ( v7 >= 0 )
          {
            v10 = &this->m_Remote.m_List.m_Memory.m_pMemory[v7];
            this->m_bWaitingForServerGameDetails = false;
            v11 = CUtlString::operator char const *(this: &v10->m_szRetryAddress);
            _Msg(a1: "Received game details information from %s...\n", v11);
            ((void (__thiscall *)(CBaseClientState *, int, int))this->Disconnect)(a1: this, a2: 1, a3: a2);
            KeyValues::SetName(this: pGameDetailsServer, setName: "settings");
            v12 = KeyValues::FindKey(this: pGameDetailsServer, keyName: "ConnectServerDetailsRequest", bCreate: false);
            v13 = v12;
            if ( v12 != nullptr )
            {
              KeyValues::RemoveSubKey(this: pGameDetailsServer, subKey: v12);
              KeyValues::deleteThis(this: v13);
            }
            this->Disconnect(this, a2: true);
            v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v14 != nullptr )
              v15 = KeyValues::KeyValues(
                      this: v14,
                      setName: "OnEngineLevelLoadingSession",
                      firstKey: "reason",
                      firstValue: "CreateSession");
            else
              v15 = nullptr;
            v16 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
            v16->BroadcastEvent(this: v16, a2: v15);
            g_pMatchFramework->CreateSession(this: g_pMatchFramework, a2: pGameDetailsServer);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060AD0
// Name: public: void CBaseClientState::SetConnectionPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CBaseClientState::SetConnectionPassword(CBaseClientState *this, const char *pchCurrentPW)
{
  const char *v3; // eax

  if ( pchCurrentPW != nullptr && *pchCurrentPW != 0 )
  {
    SCR_BeginLoadingPlaque(levelName: nullptr);
    *(_WORD *)&this->m_bEnteredPassword = 1;
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&password.IConVar, value: pchCurrentPW);
    CBaseClientState::HandleDeferredConnection(this, a2: (int)pchCurrentPW);
  }
  else
  {
    *(_WORD *)&this->m_bEnteredPassword = 0;
    v3 = netadr_s::ToString(this: &this->m_DeferredConnection.m_adrServerAddress, baseOnly: false);
    _Msg(a1: "Connection to %s failed, server requires a password\n", v3);
    this->Disconnect(this, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060B50
// Name: public: void CBaseClientState::SendStringCmd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SendStringCmd(CBaseClientState *this, char *command)
{
  INetChannel *m_NetChannel; // ecx
  int v4; // eax
  NET_StringCmd stringCmd; // [esp+4h] [ebp-414h] BYREF

  if ( this->m_NetChannel != nullptr )
  {
    m_NetChannel = this->m_NetChannel;
    stringCmd.m_bReliable = true;
    stringCmd.m_NetChannel = nullptr;
    stringCmd.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
    stringCmd.m_szCommand = command;
    m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &stringCmd, a3: false, a4: false);
    strstr(str1: (unsigned __int8 *)command, str2: "disconnect");
    if ( v4 != 0 )
      this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060BD0
// Name: public: virtual bool CBaseClientState::ProcessStringCmd(class NET_StringCmd __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessStringCmd(CBaseClientState *this, NET_StringCmd *msg)
{
  return CBaseClientState::InternalProcessStringCmd(this: (CBaseClientState *)((char *)this - 8), msg, bIsHLTV: false);
}

//------------------------------------------------------------------------------
// Address: 0x10060BF0
// Name: public: virtual bool CBaseClientState::ProcessSetConVar(class NET_SetConVar __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSetConVar(CBaseClientState *this, NET_SetConVar *msg)
{
  NetMessageCvar_t *v3; // esi
  ConVarRef var; // [esp+0h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-4h]
  NET_SetConVar *msga; // [esp+14h] [ebp+8h]

  if ( (*((unsigned __int8 (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 6))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable) == 0 )
  {
    i = 0;
    if ( msg->m_ConVars.m_Size > 0 )
    {
      msga = nullptr;
      do
      {
        v3 = (NetMessageCvar_t *)((char *)msga + (unsigned int)msg->m_ConVars.m_Memory.m_pMemory);
        ConVarRef::ConVarRef(this: &var, pName: v3->name);
        if ( ConVarRef::IsValid(this: &var) )
        {
          if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 0x2000) )
          {
            if ( sv.m_State < ss_active )
            {
              var.m_pConVar->SetValue_4(this: var.m_pConVar, a2: v3->value);
              DevMsg(a1: "SetConVar: %s = \"%s\"\n", v3->name, v3->value);
            }
          }
          else
          {
            ConMsg(
              a1: "SetConVar: Can't set server cvar %s to %s, not marked as FCVAR_REPLICATED on client\n",
              v3->name,
              v3->value);
          }
        }
        else
        {
          ConMsg(a1: "SetConVar: No such cvar ( %s set to %s), skipping\n", v3->name, v3->value);
        }
        msga = (NET_SetConVar *)((char *)msga + 520);
        ++i;
      }
      while ( i < msg->m_ConVars.m_Size );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10060CD0
// Name: public: virtual bool CBaseClientState::ProcessServerInfo(class SVC_ServerInfo __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __userpurge CBaseClientState::ProcessServerInfo@<al>(
        CBaseClientState *this@<ecx>,
        int a2@<esi>,
        SVC_ServerInfo *msg)
{
  IEngineVGuiInternal *v4; // eax
  int HostVersion; // eax
  int v8; // eax
  int v9; // eax
  netadr_s *v10; // eax
  double m_fTickInterval; // st7
  double v12; // st5
  IEngineVGuiInternal *v13; // eax
  vgui::PropertyPage *v14; // ecx
  IGameEvent *v15; // esi
  netadr_s *v16; // eax
  netadr_s *v17; // eax
  unsigned __int16 Port; // ax
  char *v19; // eax
  char *v20; // eax
  KeyValues *v21; // eax
  IMatchEventsSubscription *v22; // eax
  PackedEntity *m_nMaxClasses; // [esp+14h] [ebp-118h]
  const char *v24; // [esp+14h] [ebp-118h]
  char pDest[56]; // [esp+20h] [ebp-10Ch] BYREF
  int bspModelName_204; // [esp+124h] [ebp-8h] OVERLAPPED BYREF
  IGameEvent_vtbl *bspModelName_220; // [esp+134h] [ebp+8h]
  IGameEvent_vtbl *bspModelName_220a; // [esp+134h] [ebp+8h]
  IGameEvent_vtbl *bspModelName_220b; // [esp+134h] [ebp+8h]

  v4 = EngineVGui();
  v4->UpdateProgressBar(this: v4, a2: PROGRESS_PROCESSSERVERINFO, a3: true);
  _COM_TimestampedLog(a1: " CBaseClient::ProcessServerInfo");
  if ( msg->m_nProtocol != GetHostVersion() )
  {
    HostVersion = GetHostVersion();
    ConMsg(a1: "Server returned version %i, expected %i.\n", msg->m_nProtocol, HostVersion);
    return 0;
  }
  LODWORD(this->m_flNextCmdTime) = msg->m_nServerCount;
  *(_DWORD *)&this->m_szLastLevelNameShort[32] = msg->m_nMaxClients;
  m_nMaxClasses = (PackedEntity *)msg->m_nMaxClasses;
  this->m_pEntityBaselines[1][2047] = m_nMaxClasses;
  this->m_pServerClasses = (C_ServerClassInfo *)(Q_log2(val: (unsigned int)m_nMaxClasses) + 1);
  v8 = *(_DWORD *)&this->m_szLastLevelNameShort[32];
  if ( v8 < 1 || v8 > 64 )
  {
    ConMsg(a1: "Bad maxclients (%u) from server.\n", *(_DWORD *)&this->m_szLastLevelNameShort[32]);
    return 0;
  }
  v9 = (int)this->m_pEntityBaselines[1][2047];
  if ( v9 < 1 || v9 > 512 )
  {
    ConMsg(a1: "Bad maxclasses (%u) from server.\n", this->m_pEntityBaselines[1][2047]);
    return 0;
  }
  if ( sv.m_State < ss_active
    && (*((unsigned __int8 (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 6))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable) == 0
    && (*((unsigned __int8 (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 65))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable) == 0 )
  {
    v10 = (netadr_s *)(*((int (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 49))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable);
    if ( !netadr_s::IsLocalhost(this: v10) )
    {
      g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x2000);
      g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x4000);
      DevMsg(a1: "FCVAR_CHEAT cvars reverted to defaults.\n");
    }
  }
  CBaseClientState::FreeEntityBaselines(this: (CBaseClientState *)((char *)this - 8));
  CGameEventManager::HasClientListenersChanged(this: g_GameEventManager, bReset: true);
  splitscreen->AddBaseUser(this: splitscreen, a2: 0, a3: msg->m_nPlayerSlot + 1);
  g_pScaleformUI->InitSlot(this: g_pScaleformUI, a2: 2, a3: g_szDefaultScaleformClientMovieName);
  *(_DWORD *)&this->m_bPaused = msg->m_nPlayerSlot;
  this->m_nDeltaTick = msg->m_nPlayerSlot + 1;
  m_fTickInterval = msg->m_fTickInterval;
  v12 = 0.1;
  if ( m_fTickInterval < 0.001 )
  {
LABEL_29:
    ConMsg(a1: "Interval_per_tick %f out of range [%f to %f]\n", m_fTickInterval, 0.001, v12);
    return 0;
  }
  if ( msg->m_fTickInterval > 0.1 )
  {
    v12 = 0.1;
    m_fTickInterval = msg->m_fTickInterval;
    goto LABEL_29;
  }
  if ( !COM_CheckGameDirectory(gamedir: msg->m_szGameDir) )
    return 0;
  V_snprintf(pDest: (char *)&this->m_nPlayerSlot, maxLen: 40, pFormat: "maps/%s%s.bsp", msg->m_szMapName, defaultValue);
  V_strncpy(pDest: &this->m_szLevelName[32], pSrc: msg->m_szMapName, maxLen: 40);
  v13 = EngineVGui();
  ((void (__thiscall *)(IEngineVGuiInternal *, char *, int))v13->SetProgressLevelName)(
    a1: v13,
    a2: &this->m_szLevelName[32],
    a3: a2);
  audiosourcecache->LevelInit(this: audiosourcecache, a2: &this->m_szLevelName[32]);
  ConVarRef::ConVarRef(this: (ConVarRef *)&bspModelName_204, pName: "sv_skyname");
  if ( ConVarRef::IsValid(this: (ConVarRef *)&bspModelName_204) )
    (*(void (__thiscall **)(int, const char *))(*(_DWORD *)bspModelName_204 + 12))(
      a1: bspModelName_204,
      a2: msg->m_szSkyName);
  this->m_ClockDriftMgr.m_nServerTick = -1;
  v24 = nullptr;
  v15 = (IGameEvent *)((int (__thiscall *)(CGameEventManager *, const char *, _DWORD))g_GameEventManager->CreateEventA)(
                        a1: g_GameEventManager,
                        a2: "server_spawn",
                        a3: 0);
  if ( v15 != nullptr )
  {
    v15->SetString(this: v15, a2: "hostname", a3: msg->m_szHostName);
    bspModelName_220 = v15->__vftable;
    v16 = (netadr_s *)(*((int (__thiscall **)(IServerMessageHandler_vtbl *, int))this->dtr_INetMessageHandler + 49))(
                        a1: this->IServerMessageHandler::INetMessageHandler::__vftable,
                        a2: 1);
    v24 = netadr_s::ToString(this: v16, baseOnly: false);
    ((void (__thiscall *)(IGameEvent *, const char *))bspModelName_220->SetString)(a1: v15, a2: "address");
    bspModelName_220a = v15->__vftable;
    v17 = (netadr_s *)(*((int (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 49))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable);
    Port = netadr_s::GetPort(this: v17);
    bspModelName_220a->SetInt(this: v15, a2: "port", a3: Port);
    v15->SetString(this: v15, a2: "game", a3: msg->m_szGameDir);
    v15->SetString(this: v15, a2: "mapname", a3: msg->m_szMapName);
    v15->SetInt(this: v15, a2: "maxplayers", a3: msg->m_nMaxClients);
    v15->SetInt(this: v15, a2: "password", a3: 0);
    bspModelName_220b = v15->__vftable;
    v19 = va(format: "%c", msg->m_cOS);
    v20 = _V_strupr(start: v19);
    bspModelName_220b->SetString(this: v15, a2: "os", a3: v20);
    v15->SetBool(this: v15, a2: "dedicated", a3: msg->m_bIsDedicated);
    g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v15);
  }
  BYTE2(this->m_iEncryptionKeySize) = 1;
  if ( sv.m_State < ss_active )
  {
    CColorBalanceUIPanel::Init(this: v14);
    SV_FlushMemoryIfMarked();
    HostState_Pre_LoadMapIntoMemory();
    V_FileBase(
      in: com_gamedir,
      out: (char *)&`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc,
      maxlen: 260);
    if ( _V_stricmp(
           s1: (const char *)&`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc,
           s2: "infested") != 0 )
    {
      V_snprintf(pDest, maxLen: 260, pFormat: "maps/%s.bsp", msg->m_szMapName);
      modelloader->GetModelForName(this: modelloader, a2: pDest, a3: FMODELLOADER_CLIENT);
    }
    if ( ((int (__thiscall *)(INetworkStringTableDictionaryMananger *, const char *, unsigned int *, const char *))g_pStringTableDictionary->OnLevelLoadStart)(
           a1: g_pStringTableDictionary,
           a2: msg->m_szMapName,
           a3: &msg->m_nStringTableCRC,
           a4: v24) == 0 )
      _Warning(a1: "***String table CRC mismatch, may need to rebuild bsp if model oddities occur!\n");
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      KeyValues::KeyValues(
        this: v21,
        setName: "OnProfilesWriteOpportunity",
        firstKey: "reason",
        firstValue: "checkpoint");
    v22 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    ((void (__thiscall *)(IMatchEventsSubscription *))v22->BroadcastEvent)(a1: v22);
  }
  _COM_TimestampedLog(a1: "CBaseClient::ProcessServerInfo(done)");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10061190
// Name: public: virtual bool CBaseClientState::ProcessClassInfo(class SVC_ClassInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessClassInfo(CBaseClientState *this, SVC_ClassInfo *msg)
{
  CBaseClientState *v2; // esi
  PackedEntity *v4; // ecx
  void *v5; // edx
  int v6; // ebx
  void **v7; // edi
  void *v8; // ecx
  int m_Size; // edi
  int v10; // ecx
  int *v11; // eax
  int v12; // edi
  PackedEntity *v13; // ebx
  _DWORD *v14; // eax
  PackedEntity *v15; // eax
  SVC_ClassInfo::class_s *v16; // edi
  int v17; // ebx
  int v18; // esi
  char *v19; // eax
  const char *datatablename; // edi
  int v21; // esi
  char *v22; // eax
  int i; // [esp+4h] [ebp-Ch]
  int ia; // [esp+4h] [ebp-Ch]
  int v26; // [esp+Ch] [ebp-4h]

  v2 = this;
  _COM_TimestampedLog(a1: " CBaseClient::ProcessClassInfo");
  if ( msg->m_bCreateOnClient )
  {
    ConMsg(a1: "Can't create class tables.\n");
    return false;
  }
  else
  {
    v4 = v2->m_pEntityBaselines[1][2046];
    if ( v4 != nullptr )
    {
      v5 = (char *)&v4[-1] + 48;
      v6 = *((_DWORD *)&v4[-1] + 12) - 1;
      i = (int)&v4[-1] + 48;
      if ( v6 >= 0 )
      {
        v7 = (void **)(&v4->m_nEntityIndex + 4 * *((_DWORD *)&v4[-1] + 12));
        do
        {
          v8 = *(v7 - 5);
          v7 -= 4;
          free(pMem: v8);
          free(pMem: *v7);
          --v6;
        }
        while ( v6 >= 0 );
        v5 = (void *)i;
      }
      free(pMem: v5);
    }
    m_Size = msg->m_Classes.m_Size;
    v10 = (unsigned __int64)(unsigned int)m_Size >> 28 != 0;
    v2->m_pEntityBaselines[1][2047] = (PackedEntity *)m_Size;
    v11 = (int *)MemAlloc_Alloc(nSize: __CFADD__((16 * m_Size) | -v10, 4) ? -1 : ((16 * m_Size) | -v10) + 4);
    if ( v11 != nullptr )
    {
      *v11 = m_Size;
      v12 = m_Size - 1;
      v13 = (PackedEntity *)(v11 + 1);
      if ( v12 >= 0 )
      {
        v14 = v11 + 3;
        do
        {
          *(v14 - 1) = 0;
          *v14 = 0;
          v14[1] = 0xFFFF;
          v14 += 4;
          --v12;
        }
        while ( v12 >= 0 );
      }
      v15 = v13;
    }
    else
    {
      v15 = nullptr;
    }
    v2->m_pEntityBaselines[1][2046] = v15;
    if ( v15 != nullptr )
    {
      ia = 0;
      if ( (int)v2->m_pEntityBaselines[1][2047] <= 0 )
      {
LABEL_21:
        _COM_TimestampedLog(a1: " CBaseClient::ProcessClassInfo(done)");
        return ((int (__thiscall *)(CNetworkStringTableContainer **))v2[-1].m_StringTableContainer[2].m_Tables.m_Size)(a1: &v2[-1].m_StringTableContainer);
      }
      else
      {
        v26 = 0;
        while ( 1 )
        {
          v16 = &msg->m_Classes.m_Memory.m_pMemory[v26];
          if ( v16->classID >= (int)v2->m_pEntityBaselines[1][2047] )
            break;
          v17 = (int)v2->m_pEntityBaselines[1][2046] + 16 * v16->classID;
          v18 = _V_strlen(str: v16->classname) + 1;
          v19 = (char *)MemAlloc_Alloc(nSize: v18);
          *(_DWORD *)(v17 + 4) = v19;
          V_strncpy(pDest: v19, pSrc: v16->classname, maxLen: v18);
          datatablename = v16->datatablename;
          v21 = _V_strlen(str: datatablename) + 1;
          v22 = (char *)MemAlloc_Alloc(nSize: v21);
          *(_DWORD *)(v17 + 8) = v22;
          V_strncpy(pDest: v22, pSrc: datatablename, maxLen: v21);
          ++v26;
          ++ia;
          v2 = this;
          if ( ia >= (int)this->m_pEntityBaselines[1][2047] )
            goto LABEL_21;
        }
        Host_EndGame(bShowMainMenu: true, message: "ProcessClassInfo: invalid class index (%d).\n", v16->classID);
        return false;
      }
    }
    else
    {
      Host_EndGame(
        bShowMainMenu: true,
        message: "ProcessClassInfo: can't allocate %d C_ServerClassInfos.\n",
        v2->m_pEntityBaselines[1][2047]);
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061380
// Name: public: virtual char const __near * CLC_RespondCvarValue::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_RespondCvarValue::GetName(CLC_RespondCvarValue *this)
{
  return "clc_RespondCvarValue";
}

//------------------------------------------------------------------------------
// Address: 0x10061390
// Name: public: virtual unsigned int CLC_RespondCvarValue::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLC_RespondCvarValue::GetSize(CLC_RespondCvarValue *this)
{
  return 544;
}

//------------------------------------------------------------------------------
// Address: 0x100613A0
// Name: private: void CBaseClientState::SendReserveServerChallenge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SendReserveServerChallenge(CBaseClientState *this)
{
  int v2; // edi
  int v3; // ebx
  unsigned int PrivateIPDelayMsecs; // eax

  v2 = 0;
  if ( this->m_netadrReserveServer.m_List.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      PrivateIPDelayMsecs = GetPrivateIPDelayMsecs();
      NET_OutOfBandDelayedPrintf(
        sock: this->m_Socket,
        adr: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory[v3].m_adrRemote,
        unMillisecondsDelay: v2 * PrivateIPDelayMsecs,
        format: "%creserve0000000",
        113);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_netadrReserveServer.m_List.m_Size );
  }
  this->m_flReservationMsgSendTime = net_time;
}

//------------------------------------------------------------------------------
// Address: 0x10061400
// Name: public: bool CAddressList::IsRemoteInList(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAddressList::IsRemoteInList(CAddressList *this, const char *pchAdrCheck)
{
  int v3; // ebx
  int i; // edi
  const char *v5; // eax

  v3 = 0;
  if ( this->m_List.m_Size <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_List.m_Memory.m_pMemory[i].m_szRetryAddress);
    if ( _V_stricmp(s1: pchAdrCheck, s2: v5) == 0 )
      break;
    if ( ++v3 >= this->m_List.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10061450
// Name: public: bool CAddressList::IsAddressInList(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAddressList::IsAddressInList(CAddressList *this, netadr_s *adr)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( this->m_List.m_Size <= 0 )
    return 0;
  for ( i = 0; !netadr_s::CompareAdr(this: adr, a: &this->m_List.m_Memory.m_pMemory[i].m_adrRemote, onlyBase: false); ++i )
  {
    if ( ++v3 >= this->m_List.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100614A0
// Name: public: void CAddressList::Describe(class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddressList::Describe(CAddressList *this, CUtlString *str)
{
  Remote_t *v3; // esi
  const char *v4; // ebx
  const char *v5; // eax
  const char *v6; // eax
  int i; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  i = 0;
  if ( this->m_List.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v3 = &this->m_List.m_Memory.m_pMemory[v8];
      v4 = CUtlString::operator char const *(this: &v3->m_szAlias);
      v5 = netadr_s::ToString(this: &v3->m_adrRemote, baseOnly: false);
      v6 = va(format: "%s(%s) ", v4, v5);
      CUtlString::operator+=(this: str, rhs: v6);
      ++v8;
      ++i;
    }
    while ( i < this->m_List.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061510
// Name: public: virtual bool CBaseClientState::ProcessGetCvarValue(class SVC_GetCvarValue __near *)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
char __thiscall CBaseClientState::ProcessGetCvarValue(CBaseClientState *this, SVC_GetCvarValue *msg)
{
  const char *m_szCvarName; // eax
  ConVar *v3; // eax
  _DWORD *v4; // esi
  int v5; // esi
  int v6; // esi
  const char *v7; // eax
  char pDest[20]; // [esp+10h] [ebp-32Ch] BYREF
  char tempValue[256]; // [esp+24h] [ebp-318h] BYREF
  _BYTE returnMsg[536]; // [esp+124h] [ebp-218h] OVERLAPPED
  int v12; // [esp+344h] [ebp+8h]

  *(_DWORD *)&tempValue[252] = msg->m_iCookie;
  m_szCvarName = msg->m_szCvarName;
  *(_DWORD *)&returnMsg[532] = this;
  *(_DWORD *)returnMsg = m_szCvarName;
  tempValue[240] = 1;
  *(_DWORD *)&tempValue[244] = 0;
  *(_DWORD *)&tempValue[236] = &CLC_RespondCvarValue::`vftable';
  *(_DWORD *)&returnMsg[4] = defaultValue;
  *(_DWORD *)&returnMsg[8] = 1;
  v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: m_szCvarName);
  v4 = &v3->ConCommandBase::__vftable;
  if ( v3 != nullptr )
  {
    if ( v3->IsFlagSet(this: v3, a2: 0x20000000) )
    {
      *(_DWORD *)&returnMsg[8] = 3;
    }
    else
    {
      *(_DWORD *)&returnMsg[8] = 0;
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int))(*v4 + 8))(a1: v4, a2: 4096) != 0 )
      {
        v5 = v4[7];
        *(_DWORD *)&returnMsg[524] = *(_DWORD *)(v5 + 44);
        *(_DWORD *)&returnMsg[528] = *(_DWORD *)&returnMsg[524];
        if ( v5 != 0 )
          v12 = *(_DWORD *)(v5 + 48);
        else
          v12 = 0;
        if ( fabs(*(float *)&returnMsg[528] - (double)v12) >= 0.001 )
        {
          V_snprintf(pDest, maxLen: 256, pFormat: "%f", *(float *)&returnMsg[524]);
          *(_DWORD *)&returnMsg[4] = pDest;
        }
        else
        {
          if ( v5 != 0 )
            v6 = *(_DWORD *)(v5 + 48);
          else
            v6 = 0;
          V_snprintf(pDest, maxLen: 256, pFormat: "%d", v6);
          *(_DWORD *)&returnMsg[4] = pDest;
        }
      }
      else if ( (v4[5] & 0x1000) != 0 )
      {
        *(_DWORD *)&returnMsg[4] = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v7 = *(const char **)(v4[7] + 36);
        if ( v7 == nullptr )
          v7 = defaultValue;
        *(_DWORD *)&returnMsg[4] = v7;
      }
    }
  }
  else
  {
    *(_DWORD *)&returnMsg[8] = (g_pCVar->FindCommand_2(this: g_pCVar, a2: msg->m_szCvarName) != nullptr) + 1;
  }
  (*(void (__thiscall **)(_DWORD, char *, _DWORD, _DWORD))(**(_DWORD **)(*(_DWORD *)&returnMsg[532] + 8) + 164))(
    a1: *(_DWORD *)(*(_DWORD *)&returnMsg[532] + 8),
    a2: &tempValue[236],
    a3: 0,
    a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100616D0
// Name: public: virtual void CBaseClientState::HandleReservationResponse(struct netadr_s __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::HandleReservationResponse(CBaseClientState *this, netadr_s *adr, bool bSuccess)
{
  KeyValues *m_pKVGameSettings; // ecx
  IMatchAsyncOperationCallback *m_pServerReservationCallback; // ebx
  CBaseClientState::CAsyncOperation_ReserveServer *m_pServerReservationOperation; // eax

  if ( netadr_s::IsLoopback(this: adr) || CAddressList::IsAddressInList(this: &this->m_netadrReserveServer, adr) != 0 )
  {
    m_pKVGameSettings = this->m_pKVGameSettings;
    m_pServerReservationCallback = this->m_pServerReservationCallback;
    this->m_pServerReservationCallback = nullptr;
    if ( m_pKVGameSettings != nullptr )
    {
      KeyValues::deleteThis(this: m_pKVGameSettings);
      this->m_pKVGameSettings = nullptr;
    }
    if ( m_pServerReservationCallback != nullptr )
    {
      m_pServerReservationOperation = this->m_pServerReservationOperation;
      if ( m_pServerReservationOperation != nullptr )
      {
        m_pServerReservationOperation->m_eState = bSuccess + 3;
        this->m_pServerReservationOperation->m_adr = *adr;
      }
      m_pServerReservationCallback->OnOperationFinished(
        this: m_pServerReservationCallback,
        a2: this->m_pServerReservationOperation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061770
// Name: public: virtual int SVC_UserMessage::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_UserMessage::GetType(SVC_UserMessage *this)
{
  return 23;
}

//------------------------------------------------------------------------------
// Address: 0x10061780
// Name: public: virtual char const __near * SVC_UserMessage::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_UserMessage::GetName(SVC_UserMessage *this)
{
  return "svc_UserMessage";
}

//------------------------------------------------------------------------------
// Address: 0x10061790
// Name: public: virtual bool SVC_UserMessage::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UserMessage::Process(SVC_UserMessage *this)
{
  return this->m_pMessageHandler->ProcessUserMessage(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100617A0
// Name: public: virtual int NET_SignonState::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall NET_SignonState::GetType(NET_SignonState *this)
{
  return 7;
}

//------------------------------------------------------------------------------
// Address: 0x100617B0
// Name: public: Remote_t::~Remote_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Remote_t::~Remote_t(Remote_t *this)
{
  this->m_szRetryAddress.m_Storage.m_nActualLength = 0;
  if ( this->m_szRetryAddress.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szRetryAddress.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szRetryAddress.m_Storage.m_Memory.m_pMemory);
      this->m_szRetryAddress.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szRetryAddress.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szAlias.m_Storage.m_nActualLength = 0;
  if ( this->m_szAlias.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szAlias.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szAlias.m_Storage.m_Memory.m_pMemory);
      this->m_szAlias.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szAlias.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061810
// Name: public: virtual char const __near * CLC_SplitPlayerConnect::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_SplitPlayerConnect::GetName(CLC_SplitPlayerConnect *this)
{
  return "clc_SplitPlayerConnect";
}

//------------------------------------------------------------------------------
// Address: 0x10061850
// Name: public: virtual char const __near * CLC_ListenEvents::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_ListenEvents::GetName(CLC_ListenEvents *this)
{
  return "clc_ListenEvents";
}

//------------------------------------------------------------------------------
// Address: 0x10061860
// Name: public: virtual bool SVC_SetPause::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SetPause::Process(CLC_ListenEvents *this)
{
  return this->m_pMessageHandler->ProcessListenEvents(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10061870
// Name: public: virtual void CBaseClientState::CheckForResend(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::CheckForResend(CBaseClientState *this, int bForceResendNow)
{
  int v3; // ebx
  CUtlString *v4; // eax
  netadr_s *v5; // edi
  const char *v6; // eax
  int v7; // eax
  int v8; // ebx
  const char *v9; // eax
  Remote_t *m_pMemory; // ecx
  const char *v11; // eax
  const char *v12; // ebx
  const char *v13; // eax
  int v14; // ebx
  int v15; // edi
  ISteamSocketMgr::ESteamCnxType v16; // eax
  unsigned int m_ListenServerSteamID; // ecx
  unsigned int m_ListenServerSteamID_high; // edx
  int m_nRetryNumber; // ebx
  bool v20; // bl
  int v21; // ebx
  netadr_s *v22; // edi
  const char *v23; // eax
  unsigned int PrivateIPDelayMsecs; // eax
  bool v25; // zf
  CUtlString *p_m_szRetryAddress; // ecx
  const char *v27; // eax
  Remote_t *v28; // ebx
  int v29; // eax
  const char *v30; // eax
  netadr_s *v31; // [esp+10h] [ebp-A8h]
  const char *v32; // [esp+10h] [ebp-A8h]
  int v33; // [esp+10h] [ebp-A8h]
  char pDest[28]; // [esp+20h] [ebp-98h] BYREF
  char payload[128]; // [esp+3Ch] [ebp-7Ch] BYREF

  if ( this->m_nSignonState == 1
    && !this->m_bWaitingForPassword
    && ((_BYTE)bForceResendNow != 0 || cl_resend.m_pParent->m_Value.m_fValue <= net_time - this->m_flConnectTime) )
  {
    v3 = 0;
    if ( this->m_Remote.m_List.m_Size > 0 )
    {
      bForceResendNow = 0;
      do
      {
        v4 = (CUtlString *)((char *)&this->m_Remote.m_List.m_Memory.m_pMemory->m_szAlias + bForceResendNow);
        v5 = (netadr_s *)&v4[2];
        v31 = (netadr_s *)&v4[2];
        v6 = CUtlString::operator char const *(this: v4 + 1);
        if ( !NET_StringToAdr(s: v6, a: v31) )
        {
          v8 = v3;
          v32 = CUtlString::operator char const *(this: &this->m_Remote.m_List.m_Memory.m_pMemory[v8].m_szRetryAddress);
          v9 = CUtlString::operator char const *(this: &this->m_Remote.m_List.m_Memory.m_pMemory[v8].m_szAlias);
          ConMsg(a1: "Bad server address %s(%s)\n", v9, v32);
          this->Disconnect(this, a2: true);
          return;
        }
        if ( netadr_s::GetPort(this: v5) == 0 )
          netadr_s::SetPort(this: v5, newport: 0x6987u);
        bForceResendNow += 44;
        ++v3;
      }
      while ( v3 < this->m_Remote.m_List.m_Size );
      if ( this->m_nRetryNumber >= this->GetConnectionRetryNumber(this) )
      {
        v7 = this->GetConnectionRetryNumber(this);
        COM_ExplainDisconnection(bPrint: true, fmt: "Connection failed after %i retries.\n", v7);
        this->Disconnect(this, a2: true);
        return;
      }
      m_pMemory = this->m_Remote.m_List.m_Memory.m_pMemory;
      this->m_flConnectTime = net_time;
      v11 = CUtlString::operator char const *(this: &m_pMemory->m_szRetryAddress);
      if ( V_strncmp(s1: v11, s2: "localhost", count: 9) != 0 )
      {
        CUtlString::CUtlString(this: (CUtlString *)&payload[100]);
        CAddressList::Describe(this: &this->m_Remote, str: (CUtlString *)&payload[100]);
        v12 = "Connecting to";
        if ( this->m_nRetryNumber != 0 )
          v12 = "Retrying";
        v13 = CUtlString::operator char const *(this: (CUtlString *)&payload[100]);
        ConMsg(a1: "%s %s...\n", v12, v13);
        CUtlString::~CUtlString(this: (CUtlString *)&payload[100]);
      }
      if ( this->m_bWaitingForServerGameDetails )
      {
        v14 = 0;
        if ( this->m_Remote.m_List.m_Size > 0 )
        {
          v15 = 0;
          do
          {
            this->ResendGameDetailsRequest(this, a2: &this->m_Remote.m_List.m_Memory.m_pMemory[v15].m_adrRemote);
            ++v14;
            ++v15;
          }
          while ( v14 < this->m_Remote.m_List.m_Size );
          ++this->m_nRetryNumber;
          return;
        }
        goto LABEL_40;
      }
      V_snprintf(pDest, maxLen: 128, pFormat: "%cconnect0x%08X", 113, this->m_DeferredConnection.m_nChallenge);
      v16 = g_pSteamSocketMgr->GetCnxType(this: g_pSteamSocketMgr);
      m_ListenServerSteamID = this->m_ListenServerSteamID;
      m_ListenServerSteamID_high = HIDWORD(this->m_ListenServerSteamID);
      bForceResendNow = v16;
      v20 = false;
      if ( __PAIR64__(m_ListenServerSteamID, m_ListenServerSteamID_high) != 0 )
      {
        m_nRetryNumber = this->m_nRetryNumber;
        if ( m_nRetryNumber > 0 && (m_nRetryNumber & 1) == 0 )
          v20 = true;
      }
      if ( __PAIR64__(m_ListenServerSteamID, m_ListenServerSteamID_high) != 0 && bForceResendNow == 2 )
        v20 = true;
      if ( __PAIR64__(m_ListenServerSteamID, m_ListenServerSteamID_high) != 0 || v20 )
      {
        v25 = __PAIR64__(m_ListenServerSteamID, m_ListenServerSteamID_high) == 0;
        p_m_szRetryAddress = &this->m_Remote.m_List.m_Memory.m_pMemory->m_szRetryAddress;
        if ( !v25 )
        {
          v27 = CUtlString::operator char const *(this: p_m_szRetryAddress);
          _Msg(a1: "%.3f:  Sending Steam connect to %s %llx\n", (double)net_time, v27, this->m_ListenServerSteamID);
          v28 = this->m_Remote.m_List.m_Memory.m_pMemory;
          v29 = _V_strlen(str: pDest);
          v28->m_adrRemote = *NET_InitiateSteamConnection(
                                result: (netadr_s *)&payload[104],
                                sock: this->m_Socket,
                                uSteamID: this->m_ListenServerSteamID,
                                format: pDest,
                                v29 + 1);
          ++this->m_nRetryNumber;
          return;
        }
        v30 = CUtlString::operator char const *(this: p_m_szRetryAddress);
        _Warning(a1: "%.3f:  Steam connection to unknown SteamId (%s) failed!\n", (double)net_time, v30);
        goto LABEL_40;
      }
      v21 = 0;
      if ( this->m_Remote.m_List.m_Size <= 0 )
      {
LABEL_40:
        ++this->m_nRetryNumber;
        return;
      }
      *(_DWORD *)&payload[120] = 0;
      do
      {
        v22 = (netadr_s *)((char *)&this->m_Remote.m_List.m_Memory.m_pMemory->m_adrRemote + *(_DWORD *)&payload[120]);
        *(_DWORD *)&payload[116] = CUtlString::operator char const *(this: (CUtlString *)((char *)&this->m_Remote.m_List.m_Memory.m_pMemory->m_szAlias
                                                                                        + *(_DWORD *)&payload[120]));
        bForceResendNow = -16711936;
        v23 = netadr_s::ToString(this: v22, baseOnly: false);
        ConColorMsg(
          a1: (const struct Color *)&bForceResendNow,
          a2: "%.3f:  Sending UDP connect to %s IP %s\n",
          (double)net_time,
          *(const char **)&payload[116],
          v23);
        v33 = _V_strlen(str: pDest) + 1;
        PrivateIPDelayMsecs = GetPrivateIPDelayMsecs();
        NET_OutOfBandDelayedPrintf(
          sock: this->m_Socket,
          adr: v22,
          unMillisecondsDelay: v21 * PrivateIPDelayMsecs,
          format: pDest,
          v33);
        *(_DWORD *)&payload[120] += 44;
        ++v21;
      }
      while ( v21 < this->m_Remote.m_List.m_Size );
      ++this->m_nRetryNumber;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061BE0
// Name: private: void CBaseClientState::BuildReserveServerPayload(class bf_write __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::BuildReserveServerPayload(CBaseClientState *this, bf_write *msg, int nChallengeNr)
{
  int m_Put; // edi
  KeyValues *m_pKVGameSettings; // ecx
  unsigned __int8 *m_pData; // esi
  int v7; // eax
  unsigned int v8; // edi
  char buffer[728]; // [esp+8h] [ebp-334h] BYREF
  CUtlBuffer buf; // [esp+2E0h] [ebp-5Ch] BYREF
  IceKey cipher; // [esp+310h] [ebp-2Ch] BYREF
  bf_write payload; // [esp+31Ch] [ebp-20h] BYREF
  unsigned __int8 ucEncryptionKey[8]; // [esp+334h] [ebp-8h] BYREF

  bf_write::bf_write(this: &payload, pData: buffer, nBytes: 728, nBits: -1);
  bf_write::WriteLong(this: &payload, val: -17973521);
  bf_write::WriteLongLong(this: &payload, val: this->m_nServerReservationCookie);
  m_Put = 0;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CUtlBuffer::IsBigEndian(this: &buf) )
    CUtlBuffer::SetBigEndian(this: &buf, bigEndian: false);
  m_pKVGameSettings = this->m_pKVGameSettings;
  if ( m_pKVGameSettings != nullptr
    && (KeyValues::WriteAsBinary(this: m_pKVGameSettings, buffer: &buf), m_Put = buf.m_Put, buf.m_Put > 600) )
  {
    this->HandleReservationResponse(
      this,
      a2: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory->m_adrRemote,
      a3: false);
  }
  else
  {
    bf_write::WriteLong(this: &payload, val: m_Put);
    if ( m_Put > 0 )
      bf_write::WriteBytes(this: &payload, pBuf: buf.m_Memory.m_pMemory, nBytes: m_Put);
    while ( ((payload.m_iCurBit + 7) >> 3) % 8 != 0 )
      bf_write::WriteByte(this: &payload, val: 0);
    IceKey::IceKey(this: &cipher, n: 1);
    *(_DWORD *)ucEncryptionKey = nChallengeNr ^ 0x5EF8CE12;
    *(_DWORD *)&ucEncryptionKey[4] = nChallengeNr ^ 0xAA98E42C;
    IceKey::set(this: &cipher, key: ucEncryptionKey);
    m_pData = payload.m_pData;
    v7 = (payload.m_iCurBit + 7) >> 3;
    if ( v7 != 0 )
    {
      v8 = ((unsigned int)(v7 - 1) >> 3) + 1;
      do
      {
        IceKey::encrypt(this: &cipher, ptext: m_pData, ctext: m_pData);
        m_pData += 8;
        --v8;
      }
      while ( v8 != 0 );
    }
    bf_write::WriteLong(this: msg, val: (payload.m_iCurBit + 7) >> 3);
    IceKey::~IceKey(this: &cipher);
    bf_write::WriteBytes(this: msg, pBuf: payload.m_pData, nBytes: (payload.m_iCurBit + 7) >> 3);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10061D90
// Name: public: virtual char const __near * NET_SetConVar::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_SetConVar::GetName(NET_SetConVar *this)
{
  return "net_SetConVar";
}

//------------------------------------------------------------------------------
// Address: 0x10061DA0
// Name: public: virtual bool NET_SetConVar::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SetConVar::Process(NET_SetConVar *this)
{
  return this->m_pMessageHandler->ProcessSetConVar(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10061E10
// Name: public: virtual void CBaseClientState::SendConnectPacket(struct netadr_s const __near &,int,int,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SendConnectPacket(
        CBaseClientState *this,
        netadr_s *netAdrRemote,
        int challengeNr,
        int authProtocol,
        unsigned __int64 unGSSteamID,
        bool bGSSecure)
{
  const char *v7; // eax
  int HostVersion; // eax
  const char *v9; // eax
  char *m_pszString; // eax
  int i; // edi
  NetMessageCvar_t *m_pMemory; // eax
  int v13; // edi
  char v14; // cl
  const char *v15; // eax
  int m_iCurBit; // edx
  int m_Socket; // edx
  unsigned __int8 *m_pData; // [esp-14h] [ebp-9BCh]
  int v19; // [esp-10h] [ebp-9B8h]
  char msg_buffer[2400]; // [esp+Ch] [ebp-99Ch] BYREF
  CLC_SplitPlayerConnect splitMsg; // [esp+96Ch] [ebp-3Ch] BYREF
  bf_write msg; // [esp+990h] [ebp-18h] BYREF

  _COM_TimestampedLog(a1: "SendConnectPacket");
  if ( !netadr_s::IsLoopback(this: netAdrRemote)
    && CAddressList::IsAddressInList(this: &this->m_Remote, adr: netAdrRemote) == 0 )
  {
    v7 = netadr_s::ToString(this: netAdrRemote, baseOnly: false);
    _Warning(a1: "Sending connect packet to unexpected address %s\n", v7);
  }
  bf_write::bf_write(this: &msg, pData: msg_buffer, nBytes: 2400, nBits: -1);
  bf_write::WriteLong(this: &msg, val: -1);
  bf_write::WriteByte(this: &msg, val: 0x6Bu);
  HostVersion = GetHostVersion();
  bf_write::WriteLong(this: &msg, val: HostVersion);
  bf_write::WriteLong(this: &msg, val: authProtocol);
  bf_write::WriteLong(this: &msg, val: challengeNr);
  v9 = this->GetClientName(this);
  bf_write::WriteString(this: &msg, pStr: v9);
  if ( (password.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = password.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  bf_write::WriteString(this: &msg, pStr: m_pszString);
  bf_write::WriteByte(this: &msg, val: this->m_nNumPlayersToConnect);
  for ( i = 0; i < this->m_nNumPlayersToConnect; ++i )
  {
    splitMsg.m_bReliable = true;
    splitMsg.m_NetChannel = nullptr;
    splitMsg.__vftable = (CLC_SplitPlayerConnect_vtbl *)&CLC_SplitPlayerConnect::`vftable';
    memset(&splitMsg.m_UserInfo, 0, sizeof(splitMsg.m_UserInfo));
    Host_BuildUserInfoUpdateMessage(nSplitScreenSlot: i, rCvarList: &splitMsg.m_UserInfo, nonDefault: false);
    NET_SetConVar::WriteToBuffer(this: (NET_SetConVar *)&splitMsg, buffer: &msg);
    m_pMemory = splitMsg.m_UserInfo.m_Memory.m_pMemory;
    splitMsg.m_UserInfo.m_Size = 0;
    if ( splitMsg.m_UserInfo.m_Memory.m_nGrowSize >= 0 )
    {
      if ( splitMsg.m_UserInfo.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: splitMsg.m_UserInfo.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        splitMsg.m_UserInfo.m_Memory.m_pMemory = nullptr;
      }
      splitMsg.m_UserInfo.m_Memory.m_nAllocationCount = 0;
    }
    splitMsg.m_UserInfo.m_pElements = m_pMemory;
    if ( splitMsg.m_UserInfo.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  if ( msg.m_iCurBit + 1 <= msg.m_nDataBits )
  {
    if ( !msg.m_bOverflow )
    {
      v13 = msg.m_iCurBit >> 3;
      v14 = msg.m_iCurBit & 7;
      if ( g_bLowViolence )
        msg.m_pData[v13] |= 1 << v14;
      else
        msg.m_pData[v13] &= ~(1 << v14);
      ++msg.m_iCurBit;
    }
  }
  else
  {
    msg.m_bOverflow = true;
  }
  bf_write::WriteLongLong(this: &msg, val: this->m_nServerReservationCookie);
  bf_write::WriteByte(this: &msg, val: 1u);
  if ( authProtocol == 2 )
  {
    v15 = this->GetCDKeyHash(this);
    bf_write::WriteString(this: &msg, pStr: v15);
LABEL_30:
    m_iCurBit = msg.m_iCurBit;
    this->m_flConnectTime = net_time;
    v19 = (m_iCurBit + 7) >> 3;
    m_Socket = this->m_Socket;
    m_pData = msg.m_pData;
    this->m_nChallengeNr = challengeNr;
    NET_SendPacket(
      chan: nullptr,
      sock: m_Socket,
      to: netAdrRemote,
      data: m_pData,
      length: v19,
      pVoicePayload: nullptr,
      bUseCompression: false,
      unMillisecondsDelay: 0);
    return;
  }
  if ( authProtocol != 3 )
  {
    Host_Error(error: "Unexepected authentication protocol %i!\n", authProtocol);
    return;
  }
  if ( CBaseClientState::PrepareSteamConnectResponse(this, unGSSteamID, bGSSecure, adr: netAdrRemote, &msg) )
    goto LABEL_30;
}

//------------------------------------------------------------------------------
// Address: 0x10062090
// Name: public: virtual void CBaseClientState::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::RunFrame(CBaseClientState *this)
{
  CLC_ListenEvents msg; // [esp+4h] [ebp-50h] BYREF

  if ( this->m_nSignonState > 3
    && this->m_NetChannel != nullptr
    && CGameEventManager::HasClientListenersChanged(this: g_GameEventManager, bReset: true) )
  {
    msg.m_bReliable = true;
    msg.m_NetChannel = nullptr;
    msg.__vftable = (CLC_ListenEvents_vtbl *)&CLC_ListenEvents::`vftable';
    memset(dst: (unsigned __int8 *)&msg.m_EventArray, value: 0, count: sizeof(msg.m_EventArray));
    CGameEventManager::WriteListenEventList(this: g_GameEventManager, &msg);
    this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &msg, a3: false, a4: false);
  }
  if ( this->m_nSignonState == 1 )
    this->CheckForResend(this, a2: false);
  this->CheckForReservationResend(this);
}

//------------------------------------------------------------------------------
// Address: 0x10062120
// Name: public: virtual void CBaseClientState::CheckForReservationResend(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::CheckForReservationResend(CBaseClientState *this)
{
  int m_nReservationMsgRetryNumber; // eax
  const char *v3; // eax
  CUtlString desc; // [esp+4h] [ebp-10h] BYREF

  if ( !this->m_bWaitingForPassword
    && this->m_pServerReservationCallback != nullptr
    && net_time - this->m_flReservationMsgSendTime >= 3.0 )
  {
    m_nReservationMsgRetryNumber = this->m_nReservationMsgRetryNumber;
    if ( (float)m_nReservationMsgRetryNumber < 2.0 )
    {
      this->m_nReservationMsgRetryNumber = m_nReservationMsgRetryNumber + 1;
      CBaseClientState::SendReserveServerChallenge(this);
    }
    else
    {
      CUtlString::CUtlString(this: &desc);
      CAddressList::Describe(this: &this->m_netadrReserveServer, str: &desc);
      v3 = CUtlString::operator char const *(this: &desc);
      DevMsg(
        a1: "Attempt to reserve server %s failed; timed out after %d attempts\n",
        v3,
        this->m_nReservationMsgRetryNumber + 1);
      this->HandleReservationResponse(
        this,
        a2: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory->m_adrRemote,
        a3: false);
      CUtlString::~CUtlString(this: &desc);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100621E0
// Name: public: virtual void CBaseClientState::HandleReserveServerChallengeResponse(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::HandleReserveServerChallengeResponse(CBaseClientState *this, int nChallengeNr)
{
  int HostVersion; // eax
  int v4; // edi
  int v5; // ebx
  char buffer[728]; // [esp+4h] [ebp-2F0h] BYREF
  bf_write msg; // [esp+2DCh] [ebp-18h] BYREF

  if ( this->m_pServerReservationCallback != nullptr )
  {
    bf_write::bf_write(this: &msg, pData: buffer, nBytes: 728, nBits: -1);
    bf_write::WriteLong(this: &msg, val: -1);
    bf_write::WriteByte(this: &msg, val: 0x6Eu);
    HostVersion = GetHostVersion();
    bf_write::WriteLong(this: &msg, val: HostVersion);
    CBaseClientState::BuildReserveServerPayload(this, &msg, nChallengeNr);
    v4 = 0;
    if ( this->m_netadrReserveServer.m_List.m_Size > 0 )
    {
      v5 = 0;
      do
      {
        NET_SendPacket(
          chan: nullptr,
          sock: this->m_Socket,
          to: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory[v5].m_adrRemote,
          data: msg.m_pData,
          length: (msg.m_iCurBit + 7) >> 3,
          pVoicePayload: nullptr,
          bUseCompression: false,
          unMillisecondsDelay: 0);
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_netadrReserveServer.m_List.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100622A0
// Name: public: virtual char const __near * NET_SignonState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_SignonState::GetName(NET_SignonState *this)
{
  return "net_SignonState";
}

//------------------------------------------------------------------------------
// Address: 0x100622B0
// Name: public: virtual unsigned int NET_SignonState::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NET_SignonState::GetSize(NET_SignonState *this)
{
  return 68;
}

//------------------------------------------------------------------------------
// Address: 0x100622C0
// Name: public: virtual bool NET_SignonState::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SignonState::Process(NET_SignonState *this)
{
  return this->m_pMessageHandler->ProcessSignonState(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100622D0
// Name: public: virtual int CLC_ListenEvents::GetGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLC_ListenEvents::GetGroup(SVC_ClassInfo *this)
{
  return 13;
}

//------------------------------------------------------------------------------
// Address: 0x100622E0
// Name: public: virtual char const __near * SVC_ClassInfo::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_ClassInfo::GetName(SVC_ClassInfo *this)
{
  return "svc_ClassInfo";
}

//------------------------------------------------------------------------------
// Address: 0x100622F0
// Name: public: virtual unsigned int SVC_BSPDecal::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_BSPDecal::GetSize(SVC_ClassInfo *this)
{
  return 44;
}

//------------------------------------------------------------------------------
// Address: 0x10062300
// Name: public: virtual bool SVC_ClassInfo::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_ClassInfo::Process(SVC_ClassInfo *this)
{
  return this->m_pMessageHandler->ProcessClassInfo(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10062310
// Name: public: virtual void CBaseClientState::ConnectionStart(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectionStart(CBaseClientState *this, INetChannel *chan)
{
  INetMessage *v3; // eax
  IServerMessageHandler *v4; // ebx
  IServerMessageHandler *v5; // ecx
  INetMessage *v6; // eax
  IServerMessageHandler *v7; // ecx
  INetMessage *v8; // eax
  IServerMessageHandler *v9; // ecx
  INetMessage *v10; // eax
  IServerMessageHandler *v11; // ecx
  NET_SplitScreenUser *v12; // eax
  NET_SplitScreenUser *v13; // eax
  IServerMessageHandler *v14; // ecx
  INetMessage *v15; // eax
  IServerMessageHandler *v16; // ecx
  INetMessage *v17; // eax
  IServerMessageHandler *v18; // ecx
  char *v19; // eax
  INetMessage *v20; // edi
  INetMessage *v21; // eax
  IServerMessageHandler *v22; // ecx
  INetMessage *v23; // eax
  IServerMessageHandler *v24; // ecx
  INetMessage *v25; // eax
  IServerMessageHandler *v26; // ecx
  SVC_CreateStringTable *v27; // eax
  SVC_CreateStringTable *StringTable; // eax
  IServerMessageHandler *v29; // ecx
  char *v30; // eax
  INetMessage *v31; // edi
  INetMessage *v32; // eax
  IServerMessageHandler *v33; // ecx
  INetMessage *v34; // eax
  IServerMessageHandler *v35; // ecx
  INetMessage *v36; // eax
  IServerMessageHandler *v37; // ecx
  char *v38; // eax
  INetMessage *v39; // edi
  INetMessage *v40; // eax
  IServerMessageHandler *v41; // ecx
  INetMessage *v42; // eax
  IServerMessageHandler *v43; // ecx
  INetMessage *v44; // eax
  IServerMessageHandler *v45; // ecx
  INetMessage *v46; // eax
  IServerMessageHandler *v47; // ecx
  INetMessage *v48; // eax
  IServerMessageHandler *v49; // ecx
  char *v50; // eax
  INetMessage *v51; // edi
  IServerMessageHandler *v52; // eax
  char *v53; // eax
  char *v54; // edi
  IServerMessageHandler *v55; // eax
  char *v56; // eax
  INetMessage *v57; // edi
  IServerMessageHandler *v58; // eax
  char *v59; // eax
  INetMessage *v60; // edi
  IServerMessageHandler *v61; // eax
  char *v62; // eax
  INetMessage *v63; // edi
  INetMessage *v64; // eax
  IServerMessageHandler *v65; // ecx
  INetMessage *v66; // eax
  IServerMessageHandler *v67; // ecx
  INetMessage *v68; // eax
  IServerMessageHandler *v69; // ecx
  char *v70; // eax
  INetMessage *v71; // edi
  INetMessage *v72; // eax
  IServerMessageHandler *v73; // ecx
  INetMessage *v74; // eax
  IServerMessageHandler *v75; // ecx
  INetMessage *v76; // eax
  IServerMessageHandler *v77; // ecx
  SVC_CmdKeyValues *v78; // eax
  SVC_CmdKeyValues *v79; // eax
  IServerMessageHandler *v80; // ecx
  char *v81; // eax
  INetMessage *v82; // edi

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
  if ( this != nullptr )
    v5 = &this->IServerMessageHandler;
  else
    v5 = nullptr;
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
  if ( this != nullptr )
    v7 = &this->IServerMessageHandler;
  else
    v7 = nullptr;
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
  if ( this != nullptr )
    v9 = &this->IServerMessageHandler;
  else
    v9 = nullptr;
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
  if ( this != nullptr )
    v11 = &this->IServerMessageHandler;
  else
    v11 = nullptr;
  v10[3].__vftable = (INetMessage_vtbl *)v11;
  chan->RegisterMessage(this: chan, a2: v10);
  v12 = (NET_SplitScreenUser *)calloc(count: 1u, size: 0x14u);
  if ( v12 != nullptr )
    v13 = NET_SplitScreenUser::NET_SplitScreenUser(this: v12);
  else
    v13 = nullptr;
  if ( this != nullptr )
    v14 = &this->IServerMessageHandler;
  else
    v14 = nullptr;
  v13->m_pMessageHandler = v14;
  chan->RegisterMessage(this: chan, a2: v13);
  v15 = (INetMessage *)calloc(count: 1u, size: 0x814u);
  if ( v15 != nullptr )
  {
    v15[2].__vftable = nullptr;
    v15->__vftable = (INetMessage_vtbl *)&SVC_Print::`vftable';
    LOBYTE(v15[1].__vftable) = 0;
    v15[4].__vftable = nullptr;
  }
  else
  {
    v15 = nullptr;
  }
  if ( this != nullptr )
    v16 = &this->IServerMessageHandler;
  else
    v16 = nullptr;
  v15[3].__vftable = (INetMessage_vtbl *)v16;
  chan->RegisterMessage(this: chan, a2: v15);
  v17 = (INetMessage *)calloc(count: 1u, size: 0x458u);
  if ( v17 != nullptr )
  {
    LOBYTE(v17[1].__vftable) = 1;
    v17[2].__vftable = nullptr;
    v17->__vftable = (INetMessage_vtbl *)&SVC_ServerInfo::`vftable';
  }
  else
  {
    v17 = nullptr;
  }
  if ( this != nullptr )
    v18 = &this->IServerMessageHandler;
  else
    v18 = nullptr;
  v17[3].__vftable = (INetMessage_vtbl *)v18;
  chan->RegisterMessage(this: chan, a2: v17);
  v19 = (char *)calloc(count: 1u, size: 0x54u);
  v20 = (INetMessage *)v19;
  if ( v19 != nullptr )
  {
    v19[4] = 1;
    *((_DWORD *)v19 + 2) = 0;
    *(_DWORD *)v19 = &SVC_SendTable::`vftable';
    v19[28] = 0;
    *((_DWORD *)v19 + 6) = 0;
    *((_DWORD *)v19 + 8) = -1;
    *((_DWORD *)v19 + 9) = 0;
    bf_write::bf_write(this: (bf_write *)(v19 + 60));
    v21 = v20;
  }
  else
  {
    v21 = nullptr;
  }
  if ( this != nullptr )
    v22 = &this->IServerMessageHandler;
  else
    v22 = nullptr;
  v21[3].__vftable = (INetMessage_vtbl *)v22;
  chan->RegisterMessage(this: chan, a2: v21);
  v23 = (INetMessage *)calloc(count: 1u, size: 0x2Cu);
  if ( v23 != nullptr )
  {
    LOBYTE(v23[1].__vftable) = 1;
    v23[2].__vftable = nullptr;
    v23->__vftable = (INetMessage_vtbl *)&SVC_ClassInfo::`vftable';
    v23[5].__vftable = nullptr;
    v23[6].__vftable = nullptr;
    v23[7].__vftable = nullptr;
    v23[8].__vftable = nullptr;
    v23[9].__vftable = nullptr;
  }
  else
  {
    v23 = nullptr;
  }
  if ( this != nullptr )
    v24 = &this->IServerMessageHandler;
  else
    v24 = nullptr;
  v23[3].__vftable = (INetMessage_vtbl *)v24;
  chan->RegisterMessage(this: chan, a2: v23);
  v25 = (INetMessage *)calloc(count: 1u, size: 0x14u);
  if ( v25 != nullptr )
  {
    LOBYTE(v25[1].__vftable) = 1;
    v25[2].__vftable = nullptr;
    v25->__vftable = (INetMessage_vtbl *)&SVC_SetPause::`vftable';
  }
  else
  {
    v25 = nullptr;
  }
  if ( this != nullptr )
    v26 = &this->IServerMessageHandler;
  else
    v26 = nullptr;
  v25[3].__vftable = (INetMessage_vtbl *)v26;
  chan->RegisterMessage(this: chan, a2: v25);
  v27 = (SVC_CreateStringTable *)calloc(count: 1u, size: 0x170u);
  if ( v27 != nullptr )
    StringTable = SVC_CreateStringTable::SVC_CreateStringTable(this: v27);
  else
    StringTable = nullptr;
  if ( this != nullptr )
    v29 = &this->IServerMessageHandler;
  else
    v29 = nullptr;
  StringTable->m_pMessageHandler = v29;
  chan->RegisterMessage(this: chan, a2: StringTable);
  v30 = (char *)calloc(count: 1u, size: 0x58u);
  v31 = (INetMessage *)v30;
  if ( v30 != nullptr )
  {
    v30[4] = 1;
    *((_DWORD *)v30 + 2) = 0;
    *(_DWORD *)v30 = &SVC_UpdateStringTable::`vftable';
    v30[32] = 0;
    *((_DWORD *)v30 + 7) = 0;
    *((_DWORD *)v30 + 9) = -1;
    *((_DWORD *)v30 + 10) = 0;
    bf_write::bf_write(this: (bf_write *)(v30 + 64));
    v32 = v31;
  }
  else
  {
    v32 = nullptr;
  }
  if ( this != nullptr )
    v33 = &this->IServerMessageHandler;
  else
    v33 = nullptr;
  v32[3].__vftable = (INetMessage_vtbl *)v33;
  chan->RegisterMessage(this: chan, a2: v32);
  v34 = (INetMessage *)calloc(count: 1u, size: 0x11Cu);
  if ( v34 != nullptr )
  {
    LOBYTE(v34[1].__vftable) = 1;
    v34[2].__vftable = nullptr;
    v34->__vftable = (INetMessage_vtbl *)&SVC_VoiceInit::`vftable';
  }
  else
  {
    v34 = nullptr;
  }
  if ( this != nullptr )
    v35 = &this->IServerMessageHandler;
  else
    v35 = nullptr;
  v34[3].__vftable = (INetMessage_vtbl *)v35;
  chan->RegisterMessage(this: chan, a2: v34);
  v36 = (INetMessage *)calloc(count: 1u, size: 0x58u);
  if ( v36 != nullptr )
  {
    v36[2].__vftable = nullptr;
    v36->__vftable = (INetMessage_vtbl *)&SVC_VoiceData::`vftable';
    LOBYTE(v36[12].__vftable) = 0;
    v36[11].__vftable = nullptr;
    v36[13].__vftable = (INetMessage_vtbl *)-1;
    v36[14].__vftable = nullptr;
    LOBYTE(v36[1].__vftable) = 0;
  }
  else
  {
    v36 = nullptr;
  }
  if ( this != nullptr )
    v37 = &this->IServerMessageHandler;
  else
    v37 = nullptr;
  v36[3].__vftable = (INetMessage_vtbl *)v37;
  chan->RegisterMessage(this: chan, a2: v36);
  v38 = (char *)calloc(count: 1u, size: 0x58u);
  v39 = (INetMessage *)v38;
  if ( v38 != nullptr )
  {
    v38[4] = 1;
    *((_DWORD *)v38 + 2) = 0;
    *(_DWORD *)v38 = &SVC_Sounds::`vftable';
    v38[32] = 0;
    *((_DWORD *)v38 + 7) = 0;
    *((_DWORD *)v38 + 9) = -1;
    *((_DWORD *)v38 + 10) = 0;
    bf_write::bf_write(this: (bf_write *)(v38 + 64));
    v40 = v39;
  }
  else
  {
    v40 = nullptr;
  }
  if ( this != nullptr )
    v41 = &this->IServerMessageHandler;
  else
    v41 = nullptr;
  v40[3].__vftable = (INetMessage_vtbl *)v41;
  chan->RegisterMessage(this: chan, a2: v40);
  v42 = (INetMessage *)calloc(count: 1u, size: 0x14u);
  if ( v42 != nullptr )
  {
    LOBYTE(v42[1].__vftable) = 1;
    v42[2].__vftable = nullptr;
    v42->__vftable = (INetMessage_vtbl *)&SVC_SetView::`vftable';
  }
  else
  {
    v42 = nullptr;
  }
  if ( this != nullptr )
    v43 = &this->IServerMessageHandler;
  else
    v43 = nullptr;
  v42[3].__vftable = (INetMessage_vtbl *)v43;
  chan->RegisterMessage(this: chan, a2: v42);
  v44 = (INetMessage *)calloc(count: 1u, size: 0x20u);
  if ( v44 != nullptr )
  {
    v44[2].__vftable = nullptr;
    v44->__vftable = (INetMessage_vtbl *)&SVC_FixAngle::`vftable';
    LOBYTE(v44[1].__vftable) = 0;
  }
  else
  {
    v44 = nullptr;
  }
  if ( this != nullptr )
    v45 = &this->IServerMessageHandler;
  else
    v45 = nullptr;
  v44[3].__vftable = (INetMessage_vtbl *)v45;
  chan->RegisterMessage(this: chan, a2: v44);
  v46 = (INetMessage *)calloc(count: 1u, size: 0x1Cu);
  if ( v46 != nullptr )
  {
    LOBYTE(v46[1].__vftable) = 1;
    v46[2].__vftable = nullptr;
    v46->__vftable = (INetMessage_vtbl *)&SVC_CrosshairAngle::`vftable';
  }
  else
  {
    v46 = nullptr;
  }
  if ( this != nullptr )
    v47 = &this->IServerMessageHandler;
  else
    v47 = nullptr;
  v46[3].__vftable = (INetMessage_vtbl *)v47;
  chan->RegisterMessage(this: chan, a2: v46);
  v48 = (INetMessage *)calloc(count: 1u, size: 0x2Cu);
  if ( v48 != nullptr )
  {
    LOBYTE(v48[1].__vftable) = 1;
    v48[2].__vftable = nullptr;
    v48->__vftable = (INetMessage_vtbl *)&SVC_BSPDecal::`vftable';
  }
  else
  {
    v48 = nullptr;
  }
  if ( this != nullptr )
    v49 = &this->IServerMessageHandler;
  else
    v49 = nullptr;
  v48[3].__vftable = (INetMessage_vtbl *)v49;
  chan->RegisterMessage(this: chan, a2: v48);
  v50 = (char *)calloc(count: 1u, size: 0x50u);
  v51 = (INetMessage *)v50;
  if ( v50 != nullptr )
  {
    v50[4] = 1;
    *((_DWORD *)v50 + 2) = 0;
    *(_DWORD *)v50 = &SVC_GameEvent::`vftable';
    v50[24] = 0;
    *((_DWORD *)v50 + 5) = 0;
    *((_DWORD *)v50 + 7) = -1;
    *((_DWORD *)v50 + 8) = 0;
    bf_write::bf_write(this: (bf_write *)(v50 + 56));
  }
  else
  {
    v51 = nullptr;
  }
  if ( this != nullptr )
    v52 = &this->IServerMessageHandler;
  else
    v52 = nullptr;
  v51[3].__vftable = (INetMessage_vtbl *)v52;
  chan->RegisterMessage(this: chan, a2: v51);
  v53 = (char *)calloc(count: 1u, size: 0x64u);
  v54 = v53;
  if ( v53 != nullptr )
  {
    v53[4] = 1;
    *((_DWORD *)v53 + 2) = 0;
    *(_DWORD *)v53 = &SVC_UserMessage::`vftable';
    v53[28] = 0;
    *((_DWORD *)v53 + 6) = 0;
    *((_DWORD *)v53 + 8) = -1;
    *((_DWORD *)v53 + 9) = 0;
    bf_write::bf_write(this: (bf_write *)(v53 + 60));
    CUtlString::CUtlString(this: (CUtlString *)(v54 + 84));
    v54[4] = 0;
  }
  else
  {
    v54 = nullptr;
  }
  if ( this != nullptr )
    v55 = &this->IServerMessageHandler;
  else
    v55 = nullptr;
  *((_DWORD *)v54 + 3) = v55;
  chan->RegisterMessage(this: chan, a2: (INetMessage *)v54);
  v56 = (char *)calloc(count: 1u, size: 0x58u);
  v57 = (INetMessage *)v56;
  if ( v56 != nullptr )
  {
    v56[4] = 1;
    *((_DWORD *)v56 + 2) = 0;
    *(_DWORD *)v56 = &SVC_EntityMessage::`vftable';
    v56[32] = 0;
    *((_DWORD *)v56 + 7) = 0;
    *((_DWORD *)v56 + 9) = -1;
    *((_DWORD *)v56 + 10) = 0;
    bf_write::bf_write(this: (bf_write *)(v56 + 64));
    LOBYTE(v57[1].__vftable) = 0;
  }
  else
  {
    v57 = nullptr;
  }
  if ( this != nullptr )
    v58 = &this->IServerMessageHandler;
  else
    v58 = nullptr;
  v57[3].__vftable = (INetMessage_vtbl *)v58;
  chan->RegisterMessage(this: chan, a2: v57);
  v59 = (char *)calloc(count: 1u, size: 0x64u);
  v60 = (INetMessage *)v59;
  if ( v59 != nullptr )
  {
    v59[4] = 1;
    *((_DWORD *)v59 + 2) = 0;
    *(_DWORD *)v59 = &SVC_PacketEntities::`vftable';
    v59[44] = 0;
    *((_DWORD *)v59 + 10) = 0;
    *((_DWORD *)v59 + 12) = -1;
    *((_DWORD *)v59 + 13) = 0;
    bf_write::bf_write(this: (bf_write *)(v59 + 76));
  }
  else
  {
    v60 = nullptr;
  }
  if ( this != nullptr )
    v61 = &this->IServerMessageHandler;
  else
    v61 = nullptr;
  v60[3].__vftable = (INetMessage_vtbl *)v61;
  chan->RegisterMessage(this: chan, a2: v60);
  v62 = (char *)calloc(count: 1u, size: 0x54u);
  v63 = (INetMessage *)v62;
  if ( v62 != nullptr )
  {
    v62[4] = 1;
    *((_DWORD *)v62 + 2) = 0;
    *(_DWORD *)v62 = &SVC_TempEntities::`vftable';
    v62[28] = 0;
    *((_DWORD *)v62 + 6) = 0;
    *((_DWORD *)v62 + 8) = -1;
    *((_DWORD *)v62 + 9) = 0;
    bf_write::bf_write(this: (bf_write *)(v62 + 60));
    LOBYTE(v63[1].__vftable) = 0;
    v64 = v63;
  }
  else
  {
    v64 = nullptr;
  }
  if ( this != nullptr )
    v65 = &this->IServerMessageHandler;
  else
    v65 = nullptr;
  v64[3].__vftable = (INetMessage_vtbl *)v65;
  chan->RegisterMessage(this: chan, a2: v64);
  v66 = (INetMessage *)calloc(count: 1u, size: 0x14u);
  if ( v66 != nullptr )
  {
    LOBYTE(v66[1].__vftable) = 1;
    v66[2].__vftable = nullptr;
    v66->__vftable = (INetMessage_vtbl *)&SVC_Prefetch::`vftable';
  }
  else
  {
    v66 = nullptr;
  }
  if ( this != nullptr )
    v67 = &this->IServerMessageHandler;
  else
    v67 = nullptr;
  v66[3].__vftable = (INetMessage_vtbl *)v67;
  chan->RegisterMessage(this: chan, a2: v66);
  v68 = (INetMessage *)calloc(count: 1u, size: 0x1Cu);
  if ( v68 != nullptr )
  {
    v68[2].__vftable = nullptr;
    v68->__vftable = (INetMessage_vtbl *)&SVC_Menu::`vftable';
    LOBYTE(v68[1].__vftable) = 1;
    v68[5].__vftable = (INetMessage_vtbl *)1;
    v68[4].__vftable = nullptr;
  }
  else
  {
    v68 = nullptr;
  }
  if ( this != nullptr )
    v69 = &this->IServerMessageHandler;
  else
    v69 = nullptr;
  v68[3].__vftable = (INetMessage_vtbl *)v69;
  chan->RegisterMessage(this: chan, a2: v68);
  v70 = (char *)calloc(count: 1u, size: 0x54u);
  v71 = (INetMessage *)v70;
  if ( v70 != nullptr )
  {
    v70[4] = 1;
    *((_DWORD *)v70 + 2) = 0;
    *(_DWORD *)v70 = &SVC_GameEventList::`vftable';
    v70[28] = 0;
    *((_DWORD *)v70 + 6) = 0;
    *((_DWORD *)v70 + 8) = -1;
    *((_DWORD *)v70 + 9) = 0;
    bf_write::bf_write(this: (bf_write *)(v70 + 60));
    v72 = v71;
  }
  else
  {
    v72 = nullptr;
  }
  if ( this != nullptr )
    v73 = &this->IServerMessageHandler;
  else
    v73 = nullptr;
  v72[3].__vftable = (INetMessage_vtbl *)v73;
  chan->RegisterMessage(this: chan, a2: v72);
  v74 = (INetMessage *)calloc(count: 1u, size: 0x118u);
  if ( v74 != nullptr )
  {
    LOBYTE(v74[1].__vftable) = 1;
    v74[2].__vftable = nullptr;
    v74->__vftable = (INetMessage_vtbl *)&SVC_GetCvarValue::`vftable';
  }
  else
  {
    v74 = nullptr;
  }
  if ( this != nullptr )
    v75 = &this->IServerMessageHandler;
  else
    v75 = nullptr;
  v74[3].__vftable = (INetMessage_vtbl *)v75;
  chan->RegisterMessage(this: chan, a2: v74);
  v76 = (INetMessage *)calloc(count: 1u, size: 0x1Cu);
  if ( v76 != nullptr )
  {
    LOBYTE(v76[1].__vftable) = 1;
    v76[2].__vftable = nullptr;
    v76->__vftable = (INetMessage_vtbl *)&SVC_SplitScreen::`vftable';
  }
  else
  {
    v76 = nullptr;
  }
  if ( this != nullptr )
    v77 = &this->IServerMessageHandler;
  else
    v77 = nullptr;
  v76[3].__vftable = (INetMessage_vtbl *)v77;
  chan->RegisterMessage(this: chan, a2: v76);
  v78 = (SVC_CmdKeyValues *)calloc(count: 1u, size: 0x14u);
  if ( v78 != nullptr )
    v79 = SVC_CmdKeyValues::SVC_CmdKeyValues(this: v78, pKeyValues: nullptr);
  else
    v79 = nullptr;
  if ( this != nullptr )
    v80 = &this->IServerMessageHandler;
  else
    v80 = nullptr;
  v79->m_pMessageHandler = v80;
  chan->RegisterMessage(this: chan, a2: v79);
  v81 = (char *)calloc(count: 1u, size: 0x50u);
  v82 = (INetMessage *)v81;
  if ( v81 != nullptr )
  {
    v81[4] = 1;
    *((_DWORD *)v81 + 2) = 0;
    *(_DWORD *)v81 = &SVC_PaintmapData::`vftable';
    v81[24] = 0;
    *((_DWORD *)v81 + 5) = 0;
    *((_DWORD *)v81 + 7) = -1;
    *((_DWORD *)v81 + 8) = 0;
    bf_write::bf_write(this: (bf_write *)(v81 + 56));
  }
  else
  {
    v82 = nullptr;
  }
  if ( this != nullptr )
    v4 = &this->IServerMessageHandler;
  v82[3].__vftable = (INetMessage_vtbl *)v4;
  chan->RegisterMessage(this: chan, a2: v82);
}

//------------------------------------------------------------------------------
// Address: 0x10062D50
// Name: public: void CAddressList::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CAddressList::RemoveAll(CAddressList *this)
{
  CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::RemoveAll(this: &this->m_List);
}

//------------------------------------------------------------------------------
// Address: 0x10062D60
// Name: public: void CAddressList::AddRemote(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddressList::AddRemote(CAddressList *this, const char *pchAddress, const char *pchAlias)
{
  const char *v4; // eax
  Remote_t remote; // [esp+8h] [ebp-2Ch] BYREF

  if ( CAddressList::IsRemoteInList(this, pchAdrCheck: pchAddress) == 0 )
  {
    CUtlString::CUtlString(this: &remote.m_szAlias);
    CUtlString::CUtlString(this: &remote.m_szRetryAddress);
    netadr_s::SetIP(this: &remote.m_adrRemote, unIP: 0);
    netadr_s::SetPort(this: &remote.m_adrRemote, newport: 0);
    netadr_s::SetType(this: &remote.m_adrRemote, newtype: NA_IP);
    CUtlString::operator=(this: &remote.m_szRetryAddress, src: pchAddress);
    CUtlString::operator=(this: &remote.m_szAlias, src: pchAlias);
    v4 = CUtlString::operator char const *(this: &remote.m_szRetryAddress);
    if ( NET_StringToAdr(s: v4, a: &remote.m_adrRemote) && netadr_s::GetPort(this: &remote.m_adrRemote) == 0 )
      netadr_s::SetPort(this: &remote.m_adrRemote, newport: 0x6987u);
    CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::InsertBefore(
      this: &this->m_List,
      elem: this->m_List.m_Size,
      src: &remote);
    Remote_t::~Remote_t(this: &remote);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062E10
// Name: private: void CBaseClientState::ConnectInternal(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectInternal(
        CBaseClientState *this,
        const char *pchPublicAddress,
        const char *pchPrivateAddress,
        int numPlayers)
{
  ConVar *v5; // eax
  IConVar *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  bool (__thiscall *SetSignonState)(CBaseClientState *, int, int, NET_SignonState *); // eax

  v5 = g_pCVar->FindVar_2(this: g_pCVar, a2: "name");
  if ( v5 != nullptr )
  {
    v6 = &v5->IConVar;
    if ( v6 != nullptr )
      SetNameToSteamIDName(pConVar: v6);
  }
  CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::RemoveAll(this: &this->m_Remote.m_List);
  CAddressList::AddRemote(this: &this->m_Remote, pchAddress: pchPublicAddress, pchAlias: "public");
  CAddressList::AddRemote(this: &this->m_Remote, pchAddress: pchPrivateAddress, pchAlias: "private");
  if ( realtime <= this->m_DirectConnectLobby.m_flEndTime
    && CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&this->m_DirectConnectLobby.m_adrRemote) != nullptr
    && (this->m_DirectConnectLobby.m_unLobbyID == 0
     || LODWORD(this->m_DirectConnectLobby.m_unLobbyID) == LODWORD(this->m_nServerReservationCookie)
     && HIDWORD(this->m_DirectConnectLobby.m_unLobbyID) == HIDWORD(this->m_nServerReservationCookie))
    && CAddressList::IsAddressInList(this: &this->m_Remote, adr: &this->m_DirectConnectLobby.m_adrRemote) == 0 )
  {
    pchPublicAddress = (const char *)-16711936;
    v7 = netadr_s::ToString(this: &this->m_DirectConnectLobby.m_adrRemote, baseOnly: false);
    ConColorMsg(a1: (const struct Color *)&pchPublicAddress, a2: "Adding direct connect IP to connection %s\n", v7);
    v8 = netadr_s::ToString(this: &this->m_DirectConnectLobby.m_adrRemote, baseOnly: false);
    CAddressList::AddRemote(this: &this->m_Remote, pchAddress: v8, pchAlias: "direct");
  }
  SetSignonState = this->SetSignonState;
  this->m_nNumPlayersToConnect = numPlayers;
  SetSignonState(this, a2: 1, a3: -1, a4: nullptr);
  this->m_flConnectTime = -3.402823466385289e38;
  this->m_nRetryNumber = 0;
  this->m_nRetryMax = (int)(float)(cl_resend_timeout.m_pParent->m_Value.m_fValue / cl_resend.m_pParent->m_Value.m_fValue);
}

//------------------------------------------------------------------------------
// Address: 0x10062F40
// Name: public: virtual void CBaseClientState::Connect(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::Connect(
        CBaseClientState *this,
        const char *pchPublicAddress,
        const char *pchPrivateAddress)
{
  CBaseClientState::ConnectInternal(this, pchPublicAddress, pchPrivateAddress, numPlayers: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10062F60
// Name: public: virtual void CBaseClientState::ConnectSplitScreen(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectSplitScreen(
        CBaseClientState *this,
        const char *pchPublicAddress,
        const char *pchPrivateAddress,
        int numPlayers)
{
  CBaseClientState::ConnectInternal(this, pchPublicAddress, pchPrivateAddress, numPlayers);
}

//------------------------------------------------------------------------------
// Address: 0x10062F70
// Name: public: virtual void CBaseClientState::ReserveServer(struct netadr_s const __near &,struct netadr_s const __near &,unsigned __int64,class KeyValues __near *,class IMatchAsyncOperationCallback __near *,class IMatchAsyncOperation __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ReserveServer(
        CBaseClientState *this,
        netadr_s *netAdrPublic,
        netadr_s *netAdrPrivate,
        unsigned __int64 nServerReservationCookie,
        KeyValues *pKVGameSettings,
        IMatchAsyncOperationCallback *pCallback,
        int ppAsyncOperation)
{
  CBaseClientState::CAsyncOperation_ReserveServer *v8; // eax
  CBaseClientState::CAsyncOperation_ReserveServer *v9; // edi
  IMatchAsyncOperation **v10; // eax
  KeyValues *Copy; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax

  NET_SetMultiplayer(multiplayer: true);
  if ( this->m_pServerReservationCallback != nullptr )
    this->HandleReservationResponse(
      this,
      a2: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory->m_adrRemote,
      a3: false);
  if ( ppAsyncOperation != 0 )
  {
    v8 = (CBaseClientState::CAsyncOperation_ReserveServer *)MemAlloc_Alloc(nSize: 0x18u);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v8->__vftable = (CBaseClientState::CAsyncOperation_ReserveServer_vtbl *)&CBaseClientState::CAsyncOperation_ReserveServer::`vftable';
      v8->m_eState = AOS_RUNNING;
      netadr_s::SetIP(this: &v8->m_adr, unIP: 0);
      netadr_s::SetPort(this: &v9->m_adr, newport: 0);
      netadr_s::SetType(this: &v9->m_adr, newtype: NA_IP);
      v9->m_pParent = this;
    }
    else
    {
      v9 = nullptr;
    }
    v10 = (IMatchAsyncOperation **)ppAsyncOperation;
    this->m_pServerReservationOperation = v9;
    *v10 = v9;
  }
  this->m_pServerReservationCallback = pCallback;
  this->m_nServerReservationCookie = nServerReservationCookie;
  Copy = KeyValues::MakeCopy(this: pKVGameSettings);
  this->m_flReservationMsgSendTime = 1.175494350822288e-38;
  this->m_pKVGameSettings = Copy;
  this->m_nReservationMsgRetryNumber = 0;
  this->m_bEnteredPassword = false;
  CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::RemoveAll(this: &this->m_netadrReserveServer.m_List);
  v12 = netadr_s::ToString(this: netAdrPublic, baseOnly: false);
  CAddressList::AddRemote(this: &this->m_netadrReserveServer, pchAddress: v12, pchAlias: "public");
  if ( CCircularBuffer::GetReadAvailable(this: netAdrPrivate) == NA_IP )
  {
    v13 = netadr_s::ToString(this: netAdrPrivate, baseOnly: false);
    CAddressList::AddRemote(this: &this->m_netadrReserveServer, pchAddress: v13, pchAlias: "private");
  }
  if ( realtime <= this->m_DirectConnectLobby.m_flEndTime
    && CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&this->m_DirectConnectLobby.m_adrRemote) != nullptr
    && (this->m_DirectConnectLobby.m_unLobbyID == 0
     || LODWORD(this->m_DirectConnectLobby.m_unLobbyID) == LODWORD(this->m_nServerReservationCookie)
     && HIDWORD(this->m_DirectConnectLobby.m_unLobbyID) == HIDWORD(this->m_nServerReservationCookie))
    && CAddressList::IsAddressInList(this: &this->m_netadrReserveServer, adr: &this->m_DirectConnectLobby.m_adrRemote) == 0 )
  {
    ppAsyncOperation = -16711936;
    v14 = netadr_s::ToString(this: &this->m_DirectConnectLobby.m_adrRemote, baseOnly: false);
    ConColorMsg(a1: (const struct Color *)&ppAsyncOperation, a2: "Adding direct connect IP to reservation %s\n", v14);
    v15 = netadr_s::ToString(this: &this->m_DirectConnectLobby.m_adrRemote, baseOnly: false);
    CAddressList::AddRemote(this: &this->m_netadrReserveServer, pchAddress: v15, pchAlias: "direct");
  }
  CBaseClientState::SendReserveServerChallenge(this);
}

//------------------------------------------------------------------------------
// Address: 0x10063180
// Name: public: virtual CBaseClientState::~CBaseClientState(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::~CBaseClientState(CBaseClientState *this)
{
  KeyValues *m_pKVGameSettings; // ecx

  m_pKVGameSettings = this->m_pKVGameSettings;
  this->INetChannelHandler::__vftable = (CBaseClientState_vtbl *)&CBaseClientState::`vftable'{for `INetChannelHandler'};
  this->IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CBaseClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CBaseClientState::`vftable'{for `IServerMessageHandler'};
  if ( m_pKVGameSettings != nullptr )
  {
    KeyValues::deleteThis(this: m_pKVGameSettings);
    this->m_pKVGameSettings = nullptr;
  }
  CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::~CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>(this: &this->m_netadrReserveServer.m_List);
  CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::~CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>(this: &this->m_Remote.m_List);
  this->IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&INetMessageHandler::`vftable';
  this->IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&IConnectionlessPacketHandler::`vftable';
  this->INetChannelHandler::__vftable = (CBaseClientState_vtbl *)&INetChannelHandler::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x10063200
// Name: public: virtual char const __near * CBaseClientState::GetCDKeyHash(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseClientState::GetCDKeyHash(CBaseClientState *this)
{
  return "123";
}

//------------------------------------------------------------------------------
// Address: 0x10063220
// Name: public: virtual char const __near * CBaseClientState::GetClientName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseClientState::GetClientName(CBaseClientState *this)
{
  char *result; // eax

  if ( (cl_name.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = cl_name.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063250
// Name: public: virtual void CBaseClientState::SetServerReservationCookie(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SetServerReservationCookie(
        CBaseClientState *this,
        unsigned __int64 nReservationCookie)
{
  this->m_nServerReservationCookie = nReservationCookie;
}

//------------------------------------------------------------------------------
// Address: 0x10063270
// Name: public: CBaseClientState::CBaseClientState(void)
// Source: json
//------------------------------------------------------------------------------
CBaseClientState *__thiscall CBaseClientState::CBaseClientState(CBaseClientState *this)
{
  this->IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&IConnectionlessPacketHandler::`vftable';
  this->IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&IServerMessageHandler::`vftable';
  this->INetChannelHandler::__vftable = (CBaseClientState_vtbl *)&CBaseClientState::`vftable'{for `INetChannelHandler'};
  this->IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CBaseClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CBaseClientState::`vftable'{for `IServerMessageHandler'};
  this->m_Remote.m_List.m_Memory.m_pMemory = nullptr;
  this->m_Remote.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_Remote.m_List.m_Memory.m_nGrowSize = 0;
  this->m_Remote.m_List.m_Size = 0;
  this->m_Remote.m_List.m_pElements = nullptr;
  this->m_DirectConnectLobby.m_flEndTime = -1.0;
  netadr_s::SetIP(this: &this->m_DirectConnectLobby.m_adrRemote, unIP: 0);
  netadr_s::SetPort(this: &this->m_DirectConnectLobby.m_adrRemote, newport: 0);
  netadr_s::SetType(this: &this->m_DirectConnectLobby.m_adrRemote, newtype: NA_IP);
  this->m_DirectConnectLobby.m_unLobbyID = 0;
  CClockDriftMgr::CClockDriftMgr(this: &this->m_ClockDriftMgr);
  this->m_netadrReserveServer.m_List.m_Memory.m_pMemory = nullptr;
  this->m_netadrReserveServer.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_netadrReserveServer.m_List.m_Memory.m_nGrowSize = 0;
  this->m_netadrReserveServer.m_List.m_Size = 0;
  this->m_netadrReserveServer.m_List.m_pElements = nullptr;
  netadr_s::SetIP(this: &this->m_DeferredConnection.m_adrServerAddress, unIP: 0);
  netadr_s::SetPort(this: &this->m_DeferredConnection.m_adrServerAddress, newport: 0);
  netadr_s::SetType(this: &this->m_DeferredConnection.m_adrServerAddress, newtype: NA_IP);
  this->m_DeferredConnection.m_nChallenge = 0;
  this->m_DeferredConnection.m_nAuthprotocol = 0;
  this->m_DeferredConnection.m_unGSSteamID = 0;
  this->m_DeferredConnection.m_unLobbyID = 0;
  *(_WORD *)&this->m_DeferredConnection.m_bActive = 0;
  this->m_DeferredConnection.m_bRequiresPassword = false;
  *(_DWORD *)this->m_DeferredConnection.m_chLobbyType = 0;
  *(_DWORD *)&this->m_DeferredConnection.m_chLobbyType[4] = 0;
  *(_DWORD *)&this->m_DeferredConnection.m_chLobbyType[8] = 0;
  *(_DWORD *)&this->m_DeferredConnection.m_chLobbyType[12] = 0;
  this->m_flConnectTime = 0.0;
  this->m_bSplitScreenUser = false;
  this->m_Socket = 0;
  this->m_pServerClasses = nullptr;
  this->m_StringTableContainer = nullptr;
  this->m_NetChannel = nullptr;
  this->m_nSignonState = 0;
  this->m_nChallengeNr = 0;
  this->m_nRetryNumber = 0;
  this->m_nRetryMax = 4;
  this->m_nServerCount = 0;
  this->m_nCurrentSequence = 0;
  this->m_nDeltaTick = 0;
  this->m_bPaused = false;
  this->m_nViewEntity = 0;
  this->m_nPlayerSlot = 0;
  this->m_nSplitScreenSlot = 0;
  this->m_nMaxClients = 0;
  this->m_nNumPlayersToConnect = 1;
  _V_memset(dest: this->m_pEntityBaselines, fill: 0, count: 0x4000);
  this->m_flNextCmdTime = -1.0;
  this->m_nServerClasses = 0;
  this->m_nServerClassBits = 0;
  this->m_ListenServerSteamID = 0;
  _V_memset(dest: this->m_szLevelName, fill: 0, count: 40);
  _V_memset(dest: this->m_szLevelNameShort, fill: 0, count: 40);
  _V_memset(dest: this->m_szLastLevelNameShort, fill: 0, count: 40);
  this->m_iEncryptionKeySize = 0;
  _V_memset(dest: this->m_szEncryptionKey, fill: 0, count: 2048);
  this->m_flReservationMsgSendTime = 0.0;
  this->m_bServerInfoProcessed = false;
  this->m_pServerReservationOperation = nullptr;
  this->m_pServerReservationCallback = nullptr;
  this->m_nReservationMsgRetryNumber = 0;
  *(_WORD *)&this->m_bEnteredPassword = 0;
  this->m_bWaitingForServerGameDetails = false;
  this->m_nServerReservationCookie = 0;
  this->m_pKVGameSettings = nullptr;
  *(_WORD *)&this->m_bRestrictServerCommands = 257;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100853C0
// Name: public: virtual int SVC_EntityMessage::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_EntityMessage::GetType(SVC_EntityMessage *this)
{
  return 24;
}

//------------------------------------------------------------------------------
// Address: 0x1008A330
// Name: public: virtual int SVC_SetPause::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_SetPause::GetType(SVC_SetPause *this)
{
  return 11;
}

//------------------------------------------------------------------------------
// Address: 0x1009D970
// Name: public: virtual bool SVC_Print::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Print::Process(SVC_Print *this)
{
  return this->m_pMessageHandler->ProcessPrint(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1009D9A0
// Name: public: virtual bool SVC_VoiceData::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_VoiceData::Process(SVC_VoiceData *this)
{
  return this->m_pMessageHandler->ProcessVoiceData(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10117390
// Name: public: virtual bool SVC_SendTable::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SendTable::Process(SVC_SendTable *this)
{
  return this->m_pMessageHandler->ProcessSendTable(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1012F790
// Name: public: virtual int NET_StringCmd::GetGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall NET_StringCmd::GetGroup(NET_SetConVar *this)
{
  return 12;
}

//------------------------------------------------------------------------------
// Address: 0x1015A370
// Name: public: virtual int NET_Tick::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall NET_Tick::GetType(SVC_Prefetch *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x101AEFE0
// Name: public: virtual int SVC_EntityMessage::GetGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_EntityMessage::GetGroup(SVC_ServerInfo *this)
{
  return 8;
}

//------------------------------------------------------------------------------
// Address: 0x10273520
// Name: public: bool netadr_s::operator<(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::operator<(netadr_s *this, const netadr_s *netadr)
{
  unsigned int v2; // edx
  unsigned int v3; // eax

  v2 = *(_DWORD *)this->ip;
  v3 = *(_DWORD *)netadr->ip;
  if ( v3 < v2 )
    return true;
  if ( v3 <= v2 )
    return netadr->port < this->port;
  return false;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x1005CAC0
// Name: void UpdateNameFromSteamID(class IConVar __near *,class CSteamID __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateNameFromSteamID(IConVar *pConVar, CSteamID *pSteamID)
{
  CSteam3Client *v2; // eax
  const char *v3; // eax

  if ( pConVar != nullptr && pSteamID != nullptr && Steam3Client()->m_pSteamFriends != nullptr )
  {
    v2 = Steam3Client();
    v3 = (const char *)((int (__thiscall *)(ISteamFriends *, _DWORD, _DWORD))v2->m_pSteamFriends->GetFriendPersonaName)(
                         a1: v2->m_pSteamFriends,
                         a2: *(_DWORD *)&pSteamID->m_steamid.m_comp,
                         a3: *((_DWORD *)&pSteamID->m_steamid.m_comp + 1));
    pConVar->SetValue_4(this: pConVar, a2: v3);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CB10
// Name: void SetNameToSteamIDName(class IConVar __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl SetNameToSteamIDName(IConVar *pConVar)
{
  CSteam3Client *v1; // eax
  CSteamID steamID; // [esp+0h] [ebp-8h] BYREF

  if ( Steam3Client()->m_pSteamUtils != nullptr
    && Steam3Client()->m_pSteamFriends != nullptr
    && Steam3Client()->m_pSteamUser != nullptr )
  {
    v1 = Steam3Client();
    v1->m_pSteamUser->GetSteamID(this: v1->m_pSteamUser, result: &steamID);
    UpdateNameFromSteamID(pConVar, pSteamID: &steamID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CB60
// Name: void askconnect_accept_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl askconnect_accept_f()
{
  vgui::CTreeViewListControl *v0; // ecx
  ECommandTarget_t TraceType; // eax
  char szCommand[512]; // [esp+0h] [ebp-300h] BYREF
  char szHostName[256]; // [esp+200h] [ebp-100h] BYREF

  if ( IsAskConnectPanelActive(pHostName: szHostName, maxHostNameBytes: 256) )
  {
    V_snprintf(pDest: szCommand, maxLen: 512, pFormat: "connect %s", szHostName);
    TraceType = CTraceFilter::GetTraceType(this: v0);
    Cbuf_AddText(eTarget: TraceType, pText: szCommand, nTickDelay: 0);
    HideAskConnectPanel();
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CBD0
// Name: public: C_ServerClassInfo::C_ServerClassInfo(void)
// Source: json
//------------------------------------------------------------------------------
C_ServerClassInfo *__thiscall C_ServerClassInfo::C_ServerClassInfo(C_ServerClassInfo *this)
{
  this->m_ClassName = nullptr;
  this->m_DatatableName = nullptr;
  this->m_InstanceBaselineIndex = 0xFFFF;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005CBF0
// Name: public: C_ServerClassInfo::~C_ServerClassInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall C_ServerClassInfo::~C_ServerClassInfo(C_ServerClassInfo *this)
{
  free(pMem: this->m_ClassName);
  free(pMem: this->m_DatatableName);
}

//------------------------------------------------------------------------------
// Address: 0x1005CC10
// Name: public: virtual void CBaseClientState::FileReceived(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FileReceived(
        CBaseClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  ConMsg(a1: "CBaseClientState::FileReceived: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1005CC30
// Name: public: virtual void CBaseClientState::FileDenied(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FileDenied(
        CBaseClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  ConMsg(a1: "CBaseClientState::FileDenied: %s.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1005CC50
// Name: public: virtual void CBaseClientState::FileRequested(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FileRequested(
        CBaseClientState *this,
        const char *fileName,
        unsigned int transferID,
        BOOL bIsReplayDemoFile)
{
  const char *v5; // eax

  v5 = this->m_NetChannel->GetAddress(this: this->m_NetChannel);
  ConMsg(a1: "File '%s' requested from %s.\n", fileName, v5);
  this->m_NetChannel->SendFile(this: this->m_NetChannel, a2: fileName, a3: transferID, a4: bIsReplayDemoFile);
}

//------------------------------------------------------------------------------
// Address: 0x1005CC90
// Name: public: virtual void CBaseClientState::FileSent(char const __near *,unsigned int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FileSent(
        CBaseClientState *this,
        const char *fileName,
        unsigned int transferID,
        bool bIsReplayDemoFile)
{
  ConMsg(a1: "File '%s' sent.\n", fileName);
}

//------------------------------------------------------------------------------
// Address: 0x1005CCB0
// Name: public: virtual void CBaseClientState::ConnectionClosing(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectionClosing(CBaseClientState *this, const char *reason)
{
  const char *v2; // eax

  v2 = reason;
  if ( reason == nullptr )
    v2 = "unknown reason";
  ConMsg(a1: "Disconnect: %s.\n", v2);
  this->Disconnect(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1005CCF0
// Name: private: bool CBaseClientState::PrepareSteamConnectResponse(unsigned __int64,bool,struct netadr_s const __near &,class bf_write __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::PrepareSteamConnectResponse(
        CBaseClientState *this,
        unsigned __int64 unGSSteamID,
        bool bGSSecure,
        netadr_s *adr,
        bf_write *msg)
{
  netadrtype_t type; // eax
  int v8; // edx
  unsigned int v9; // eax
  unsigned __int16 UDPPort; // ax
  CSteam3Client *v11; // eax
  int v12; // esi
  char *v13; // [esp-18h] [ebp-828h]
  unsigned __int16 Port; // [esp-14h] [ebp-824h]
  char steam3Cookie[2048]; // [esp+4h] [ebp-80Ch] BYREF
  netadr_s checkAdr; // [esp+804h] [ebp-Ch] BYREF

  if ( Steam3Client()->m_pSteamUser != nullptr )
  {
    type = adr->type;
    v8 = *(_DWORD *)&adr->port;
    *(_DWORD *)checkAdr.ip = *(_DWORD *)adr->ip;
    checkAdr.type = type;
    *(_DWORD *)&checkAdr.port = v8;
    if ( CCircularBuffer::GetReadAvailable(this: adr) == NA_LOOPBACK || netadr_s::IsLocalhost(this: adr) )
    {
      v9 = netadr_s::addr_ntohl(this: &net_local_adr);
      netadr_s::SetIP(this: &checkAdr, unIP: v9);
      if ( netadr_s::GetPort(this: &checkAdr) == 0 )
      {
        UDPPort = NET_GetUDPPort(socket: 1);
        netadr_s::SetPort(this: &checkAdr, newport: UDPPort);
      }
    }
    if ( sv.m_State >= ss_active
      && (sv.m_bIsLevelMainMenuBackground
       || CBaseServer::IsSinglePlayerGame(this: &sv)
       || CBaseServer::ShouldHideServer(this: &sv)) )
    {
      netadr_s::Clear(this: &checkAdr);
    }
    Port = netadr_s::GetPort(this: &checkAdr);
    v13 = CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&checkAdr);
    v11 = Steam3Client();
    v12 = CSteam3Client::InitiateConnection(
            this: v11,
            pData: steam3Cookie,
            cbMaxData: 2048,
            unIP: (unsigned int)v13,
            usPort: Port,
            unGSSteamID,
            bSecure: bGSSecure);
    bf_write::WriteShort(this: msg, val: v12);
    if ( v12 > 0 )
      bf_write::WriteBytes(this: msg, pBuf: steam3Cookie, nBytes: v12);
    return 1;
  }
  else
  {
    COM_ExplainDisconnection(bPrint: true, fmt: "The server requires that you be running Steam.\n");
    this->Disconnect(this, a2: true);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005CE30
// Name: public: class INetworkStringTable __near * CBaseClientState::GetStringTable(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
INetworkStringTable *__thiscall CBaseClientState::GetStringTable(CBaseClientState *this, const char *name)
{
  if ( this->m_StringTableContainer != nullptr )
    return this->m_StringTableContainer->FindTable(this: this->m_StringTableContainer, a2: name);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005CE50
// Name: public: virtual void CBaseClientState::FullConnect(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FullConnect(CBaseClientState *this, netadr_s *adr)
{
  CNetChan *NetChannel; // eax
  unsigned int m_nChallengeNr; // ecx
  CBaseClientState_vtbl *v5; // eax
  bool (__thiscall *SetSignonState)(CBaseClientState *, int, int, NET_SignonState *); // edx
  CRConClient *v7; // eax
  const netadr_s *v8; // [esp-4h] [ebp-8h]

  _COM_TimestampedLog(a1: "CBaseClientState::FullConnect");
  NetChannel = NET_CreateNetChannel(socket: this->m_Socket, adr, name: "CLIENT", handler: this, bForceNewChannel: false);
  m_nChallengeNr = this->m_nChallengeNr;
  this->m_NetChannel = NetChannel;
  NetChannel->StartStreaming(this: NetChannel, a2: m_nChallengeNr);
  v5 = this->INetChannelHandler::__vftable;
  this->m_flConnectTime = net_time;
  SetSignonState = v5->SetSignonState;
  this->m_nDeltaTick = -1;
  this->m_flNextCmdTime = net_time;
  this->m_nServerReservationCookie = 0;
  SetSignonState(this, a2: 2, a3: -1, a4: nullptr);
  v8 = this->m_NetChannel->GetRemoteAddress(this: this->m_NetChannel);
  v7 = RCONClient();
  CRConClient::SetAddress(this: v7, netAdr: v8);
}

//------------------------------------------------------------------------------
// Address: 0x1005CEF0
// Name: public: virtual void CBaseClientState::ConnectionCrashed(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectionCrashed(CBaseClientState *this, const char *reason)
{
  const char *v2; // eax

  v2 = reason;
  if ( reason == nullptr )
    v2 = "unknown reason";
  ConMsg(a1: "Connection lost: %s.\n", v2);
  this->Disconnect(this, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x1005CF30
// Name: public: virtual void CBaseClientState::ResendGameDetailsRequest(struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ResendGameDetailsRequest(CBaseClientState *this, netadr_s *adr)
{
  KeyValues *v2; // esi
  const char *v3; // eax
  KeyValues *v4; // esi
  IMatchEventsSubscription *v5; // eax

  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
  {
    v3 = netadr_s::ToString(this: adr, baseOnly: false);
    v4 = KeyValues::KeyValues(this: v2, setName: "Client::ResendGameDetailsRequest", firstKey: "to", firstValue: v3);
  }
  else
  {
    v4 = nullptr;
  }
  v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v5->BroadcastEvent(this: v5, a2: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1005CF90
// Name: public: virtual bool CBaseClientState::ProcessSignonState(class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessSignonState(CBaseClientState *this, NET_SignonState *msg)
{
  return (*(bool (__thiscall **)(char *, int, int, NET_SignonState *))(*((_DWORD *)this - 2) + 60))(
           a1: (char *)this - 8,
           a2: msg->m_nSignonState,
           a3: msg->m_nSpawnCount,
           a4: msg);
}

//------------------------------------------------------------------------------
// Address: 0x1005CFB0
// Name: public: virtual bool CBaseClientState::ProcessPrint(class SVC_Print __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessPrint(CBaseClientState *this, SVC_Print *msg)
{
  ConMsg(a1: msg->m_szText);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005CFD0
// Name: public: virtual bool CBaseClientState::ProcessMenu(class SVC_Menu __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessMenu(CBaseClientState *this, SVC_Menu *msg)
{
  PluginHelpers_Menu(msg);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005CFF0
// Name: public: virtual bool CBaseClientState::ProcessSendTable(class SVC_SendTable __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSendTable(CBaseClientState *this, SVC_SendTable *msg)
{
  if ( RecvTable_RecvClassInfos(pBuf: &msg->m_DataIn, bNeedsDecoder: msg->m_bNeedsDecoder, nDemoProtocol: 0) )
    return 1;
  Host_EndGame(bShowMainMenu: true, message: "ProcessSendTable: RecvTable_RecvClassInfos failed.\n");
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005D030
// Name: public: virtual bool CBaseClientState::ProcessSetPause(class SVC_SetPause __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSetPause(CBaseClientState *this, SVC_SetPause *msg)
{
  LOBYTE(this->m_ClockDriftMgr.m_nClientTick) = msg->m_bPaused;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D050
// Name: public: virtual bool CBaseClientState::ProcessSetView(class SVC_SetView __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSetView(CBaseClientState *this, SVC_SetView *msg)
{
  this->m_nDeltaTick = msg->m_nEntityIndex;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005D070
// Name: public: static class ClientClass __near * CBaseClientState::FindClientClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__cdecl CBaseClientState::FindClientClass(const char *pClassName)
{
  ClientClass *AllClasses; // esi

  AllClasses = ClientDLL_GetAllClasses();
  if ( AllClasses == nullptr )
    return nullptr;
  while ( _V_stricmp(s1: AllClasses->m_pNetworkName, s2: pClassName) != 0 )
  {
    AllClasses = AllClasses->m_pNext;
    if ( AllClasses == nullptr )
      return nullptr;
  }
  return AllClasses;
}

//------------------------------------------------------------------------------
// Address: 0x1005D0B0
// Name: public: class PackedEntity __near * CBaseClientState::GetEntityBaseline(int,int)
// Source: json
//------------------------------------------------------------------------------
PackedEntity *__thiscall CBaseClientState::GetEntityBaseline(CBaseClientState *this, int iBaseline, int nEntityIndex)
{
  return this->m_pEntityBaselines[iBaseline][nEntityIndex];
}

//------------------------------------------------------------------------------
// Address: 0x1005D0D0
// Name: public: void CBaseClientState::SetEntityBaseline(int,class ClientClass __near *,int,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SetEntityBaseline(
        CBaseClientState *this,
        int iBaseline,
        ClientClass *pClientClass,
        int index,
        char *packedData,
        unsigned int length)
{
  PackedEntity **v6; // esi
  PackedEntity *v7; // ecx
  PackedEntity *v8; // eax
  PackedEntity *v9; // eax

  v6 = &this->m_pEntityBaselines[iBaseline][index];
  v7 = *v6;
  if ( *v6 == nullptr )
  {
    v8 = (PackedEntity *)MemAlloc_Alloc(nSize: 0x34u);
    if ( v8 != nullptr )
      v9 = PackedEntity::PackedEntity(this: v8);
    else
      v9 = nullptr;
    *v6 = v9;
    v7 = v9;
  }
  v7->m_pClientClass = pClientClass;
  v7->m_nEntityIndex = index;
  v7->m_pServerClass = nullptr;
  PackedEntity::AllocAndCopyPadded(this: v7, pData: packedData, size: length);
}

//------------------------------------------------------------------------------
// Address: 0x1005D130
// Name: public: class ClientClass __near * CBaseClientState::GetClientClass(int)
// Source: json
//------------------------------------------------------------------------------
ClientClass *__thiscall CBaseClientState::GetClientClass(CBaseClientState *this, int index)
{
  return this->m_pServerClasses[index].m_pClientClass;
}

//------------------------------------------------------------------------------
// Address: 0x1005D150
// Name: public: bool CBaseClientState::GetClassBaseline(int,void const __near * __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::GetClassBaseline(
        CBaseClientState *this,
        int iClass,
        const void **pData,
        int *pDatalen)
{
  C_ServerClassInfo *v5; // edi
  INetworkStringTable *v6; // esi
  int v7; // eax
  const void *v8; // eax
  char str[64]; // [esp+Ch] [ebp-40h] BYREF

  if ( iClass < 0 || iClass >= this->m_nServerClasses )
    _Error(a1: "GetDynamicBaseline: invalid class index '%d'", iClass);
  v5 = &this->m_pServerClasses[iClass];
  if ( this->m_StringTableContainer == nullptr )
  {
    v6 = nullptr;
LABEL_7:
    _Error(a1: "GetDynamicBaseline: NULL baseline table");
    goto LABEL_8;
  }
  v6 = this->m_StringTableContainer->FindTable(this: this->m_StringTableContainer, a2: "instancebaseline");
  if ( v6 == nullptr )
    goto LABEL_7;
LABEL_8:
  if ( v5->m_InstanceBaselineIndex == 0xFFFF )
  {
    V_snprintf(pDest: str, maxLen: 64, pFormat: "%d", iClass);
    v7 = v6->FindStringIndex(this: v6, a2: str);
    v5->m_InstanceBaselineIndex = v7;
    if ( v7 == 0xFFFF )
      _Error(a1: "GetDynamicBaseline: FindStringIndex(%s-%s) failed.", str, v5->m_ClassName);
  }
  v8 = v6->GetStringUserData(this: v6, a2: v5->m_InstanceBaselineIndex, a3: pDatalen);
  *pData = v8;
  return v8 != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1005D230
// Name: public: virtual bool CBaseClientState::ProcessGameEventList(class SVC_GameEventList __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessGameEventList(CBaseClientState *this, SVC_GameEventList *msg)
{
  return CGameEventManager::ParseEventList(this: g_GameEventManager, msg);
}

//------------------------------------------------------------------------------
// Address: 0x1005D340
// Name: public: netadr_s::netadr_s(void)
// Source: json
//------------------------------------------------------------------------------
netadr_s *__thiscall netadr_s::netadr_s(netadr_s *this)
{
  netadr_s::SetIP(this, unIP: 0);
  netadr_s::SetPort(this, newport: 0);
  netadr_s::SetType(this, newtype: NA_IP);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005D360
// Name: public: CBaseClientState::DirectConnectLobby_t::DirectConnectLobby_t(void)
// Source: json
//------------------------------------------------------------------------------
CBaseClientState::DirectConnectLobby_t *__thiscall CBaseClientState::DirectConnectLobby_t::DirectConnectLobby_t(
        CBaseClientState::DirectConnectLobby_t *this)
{
  this->m_flEndTime = -1.0;
  netadr_s::SetIP(this: &this->m_adrRemote, unIP: 0);
  netadr_s::SetPort(this: &this->m_adrRemote, newport: 0);
  netadr_s::SetType(this: &this->m_adrRemote, newtype: NA_IP);
  this->m_unLobbyID = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005D3B0
// Name: void CL_NameCvarChanged(class IConVar __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CL_NameCvarChanged(IConVar *pConVar)
{
  ConVarRef var; // [esp+4h] [ebp-8h] BYREF

  if ( __RTDynamicCast(
         inptr: pConVar,
         VfDelta: 0,
         SrcType: &IConVar `RTTI Type Descriptor',
         TargetType: &CSplitScreenAddedConVar `RTTI Type Descriptor',
         isReference: 0) == nullptr )
  {
    if ( LOBYTE(`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements) == 0 )
    {
      LOBYTE(`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements) = 1;
      SetNameToSteamIDName(pConVar);
      LOBYTE(`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_NumElements) = 0;
    }
    ConVarRef::ConVarRef(this: &var, pConVar);
    if ( _V_stricmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: var.m_pConVarState->m_pszDefaultValue) != 0
      && _V_stricmp(s1: var.m_pConVarState->m_Value.m_pszString, s2: "player") != 0 )
    {
      Sys_SetRegKeyValue(
        pszSubKey: "Software\\Valve\\Steam",
        pszElement: "LastGameNameUsed",
        pszValue: var.m_pConVarState->m_Value.m_pszString);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D450
// Name: GetPrivateIPDelayMsecs
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl GetPrivateIPDelayMsecs()
{
  float v0; // xmm0_4
  int v1; // xmm1_4
  float flSeconds; // [esp+8h] [ebp-4h]

  v0 = cl_resend.m_pParent->m_Value.m_fValue * 0.5;
  v1 = 0;
  if ( v0 < 0.0 || (v1 = 1065353216, v0 > 1.0) )
    flSeconds = *(float *)&v1;
  else
    flSeconds = cl_resend.m_pParent->m_Value.m_fValue * 0.5;
  return (__int64)(flSeconds * 1000.0);
}

//------------------------------------------------------------------------------
// Address: 0x1005D4C0
// Name: public: virtual bool CBaseClientState::SetSignonState(int,int,class NET_SignonState __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::SetSignonState(CBaseClientState *this, int state, int count, NET_SignonState *msg)
{
  int m_nServerCount; // eax
  CBaseClientState::DirectConnectLobby_t v7; // [esp+8h] [ebp-18h] BYREF

  if ( (unsigned int)state <= 7
    && (state <= 2 || state > this->m_nSignonState || this->m_NetChannel->IsPlayback(this: this->m_NetChannel)) )
  {
    m_nServerCount = this->m_nServerCount;
    if ( count == m_nServerCount
      || count == -1
      || m_nServerCount == -1
      || this->m_NetChannel->IsPlayback(this: this->m_NetChannel) )
    {
      if ( this->m_nSignonState < 2 && state >= 2 )
        this->m_DirectConnectLobby = *CBaseClientState::DirectConnectLobby_t::DirectConnectLobby_t(this: &v7);
      this->m_nSignonState = state;
      return 1;
    }
    else
    {
      ConMsg(a1: "Received wrong spawn count %i when at %i\n", count, this->m_nServerCount);
      return 0;
    }
  }
  else
  {
    ConMsg(a1: "Received signon %i when at %i\n", state, this->m_nSignonState);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D5A0
// Name: private: void CBaseClientState::RememberIPAddressForLobby(unsigned __int64,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::RememberIPAddressForLobby(
        CBaseClientState *this,
        unsigned __int64 unLobbyID,
        netadr_s *adrRemote)
{
  const char *v4; // eax
  int v5; // [esp+Ch] [ebp-4h] BYREF

  v5 = -16711936;
  v4 = netadr_s::ToString(this: adrRemote, baseOnly: false);
  ConColorMsg(
    a1: (const struct Color *)&v5,
    a2: "RememberIPAddressForLobby: lobby %llx from address %s\n",
    unLobbyID,
    v4);
  this->m_DirectConnectLobby.m_unLobbyID = unLobbyID;
  this->m_DirectConnectLobby.m_adrRemote = *adrRemote;
  this->m_DirectConnectLobby.m_flEndTime = realtime + 60.0;
}

//------------------------------------------------------------------------------
// Address: 0x1005D610
// Name: public: void CBaseClientState::HandleDeferredConnection(void)
// Source: json
//------------------------------------------------------------------------------
void __usercall CBaseClientState::HandleDeferredConnection(CBaseClientState *this@<ecx>, int a2@<edi>)
{
  bool v3; // zf
  int (__thiscall ***v4)(_DWORD); // eax
  KeyValues *v5; // eax
  unsigned __int64 Uint64; // rax
  KeyValues *v7; // eax
  KeyValues *v8; // edi
  KeyValues *v9; // eax
  KeyValues *v10; // esi
  IMatchEventsSubscription *v11; // eax
  const char *v12; // eax
  void (__thiscall *ResendGameDetailsRequest)(CBaseClientState *, netadr_s *); // eax

  if ( this->m_DeferredConnection.m_bActive )
  {
    v3 = this->m_DeferredConnection.m_chLobbyType[0] == 0;
    this->m_DeferredConnection.m_bActive = false;
    if ( v3 && this->m_DeferredConnection.m_unLobbyID == 0 || sv.m_State >= ss_active )
    {
      ((void (__thiscall *)(CBaseClientState *, netadr_s *, int, int, _DWORD, _DWORD, bool))this->SendConnectPacket)(
        a1: this,
        a2: &this->m_DeferredConnection.m_adrServerAddress,
        a3: this->m_DeferredConnection.m_nChallenge,
        a4: this->m_DeferredConnection.m_nAuthprotocol,
        a5: this->m_DeferredConnection.m_unGSSteamID,
        a6: HIDWORD(this->m_DeferredConnection.m_unGSSteamID),
        a7: this->m_DeferredConnection.m_bGSSecure);
    }
    else if ( this->m_DeferredConnection.m_unLobbyID != 0 )
    {
      v4 = (int (__thiscall ***)(_DWORD))((int (__thiscall *)(IMatchFramework *, int))g_pMatchFramework->GetMatchSession)(
                                           a1: g_pMatchFramework,
                                           a2);
      if ( v4 != nullptr && (v5 = (KeyValues *)(**v4)(a1: v4)) != nullptr )
        Uint64 = KeyValues::GetUint64(this: v5, keyName: "xuidReserve", defaultValue: 0);
      else
        Uint64 = 0;
      if ( Uint64 == this->m_DeferredConnection.m_unLobbyID )
      {
        this->SendConnectPacket(
          this,
          a2: &this->m_DeferredConnection.m_adrServerAddress,
          a3: this->m_DeferredConnection.m_nChallenge,
          a4: this->m_DeferredConnection.m_nAuthprotocol,
          a5: LODWORD(this->m_DeferredConnection.m_unGSSteamID),
          a6: HIDWORD(this->m_DeferredConnection.m_unGSSteamID));
      }
      else
      {
        v7 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v7 != nullptr )
          v8 = KeyValues::KeyValues(this: v7, setName: "settings");
        else
          v8 = nullptr;
        KeyValues::SetString(this: v8, keyName: "system/network", value: "LIVE");
        KeyValues::SetString(this: v8, keyName: "options/action", value: "joinsession");
        KeyValues::SetUint64(this: v8, keyName: "options/sessionid", value: this->m_DeferredConnection.m_unLobbyID);
        this->Disconnect(this, a2: true);
        v9 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
        if ( v9 != nullptr )
          v10 = KeyValues::KeyValues(
                  this: v9,
                  setName: "OnEngineLevelLoadingSession",
                  firstKey: "reason",
                  firstValue: "MatchSession");
        else
          v10 = nullptr;
        v11 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
        v11->BroadcastEvent(this: v11, a2: v10);
        g_pMatchFramework->MatchSession(this: g_pMatchFramework, a2: v8);
        if ( v8 != nullptr )
          KeyValues::deleteThis(this: v8);
      }
    }
    else
    {
      v12 = netadr_s::ToString(this: &this->m_DeferredConnection.m_adrServerAddress, baseOnly: false);
      _Msg(a1: "Retrying connection to %s, server requires lobby reservation but is unreserved.\n", v12);
      ResendGameDetailsRequest = this->ResendGameDetailsRequest;
      this->m_bWaitingForServerGameDetails = true;
      ResendGameDetailsRequest(this, a2: &this->m_DeferredConnection.m_adrServerAddress);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D810
// Name: public: virtual bool CBaseClientState::ProcessTick(class NET_Tick __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClientState::ProcessTick(CBaseClientState *this, NET_Tick *msg)
{
  CNetworkStringTableContainer *v3; // ecx
  int m_nTick; // edi

  (*((void (__thiscall **)(IServerMessageHandler_vtbl *, float, float))this->dtr_INetMessageHandler + 68))(
    a1: this->IServerMessageHandler::INetMessageHandler::__vftable,
    a2: msg->m_flHostFrameTime,
    a3: msg->m_flHostFrameTimeStdDeviation);
  v3 = *(CNetworkStringTableContainer **)&this->m_szEncryptionKey[2044];
  this->m_ClockDriftMgr.m_iCurClockOffset = msg->m_nTick;
  m_nTick = msg->m_nTick;
  LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]) = m_nTick;
  if ( v3 != nullptr )
    CNetworkStringTableContainer::SetTick(this: v3, tick_count: m_nTick);
  return SLODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]) > 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005D870
// Name: protected: bool CBaseClientState::InternalProcessStringCmd(class NET_StringCmd __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::InternalProcessStringCmd(CBaseClientState *this, NET_StringCmd *msg, bool bIsHLTV)
{
  vgui::CTreeViewListControl *v3; // ecx
  ECommandTarget_t TraceType; // eax
  ECommandTarget_t v6; // eax
  vgui::CTreeViewListControl *v7; // ecx
  ECommandTarget_t v8; // eax
  vgui::CTreeViewListControl *v9; // ecx
  ECommandTarget_t v10; // eax
  ECommandTarget_t v11; // eax
  vgui::CTreeViewListControl *m_szCommand; // [esp-Ch] [ebp-514h]
  const char *v13; // [esp-Ch] [ebp-514h]
  vgui::CTreeViewListControl *v14; // [esp-8h] [ebp-510h]
  CCommand args; // [esp+0h] [ebp-508h] BYREF

  if ( this->m_bRestrictServerCommands && sv.m_State < ss_active )
  {
    CCommand::CCommand(this: &args);
    CCommand::Tokenize(this: &args, pCommand: msg->m_szCommand, pBreakSet: nullptr);
    if ( args.m_nArgc <= 0 )
      return 1;
    if ( bIsHLTV && _V_stricmp(s1: args.m_ppArgv[0], s2: "Connect") == 0 )
    {
      m_szCommand = (vgui::CTreeViewListControl *)msg->m_szCommand;
      TraceType = CTraceFilter::GetTraceType(this: m_szCommand);
      Cbuf_AddText(eTarget: TraceType, pText: (const char *)m_szCommand, nTickDelay: 0);
      return 1;
    }
    v6 = CTraceFilter::GetTraceType(this: v3);
    Cbuf_AddExecutionMarker(eTarget: v6, marker: eCmdExecutionMarker_Enable_FCVAR_SERVER_CAN_EXECUTE);
    v13 = msg->m_szCommand;
    v8 = CTraceFilter::GetTraceType(this: v7);
    Cbuf_AddText(eTarget: v8, pText: v13, nTickDelay: 0);
    v10 = CTraceFilter::GetTraceType(this: v9);
    Cbuf_AddExecutionMarker(eTarget: v10, marker: eCmdExecutionMarker_Disable_FCVAR_SERVER_CAN_EXECUTE);
    return 1;
  }
  else
  {
    v14 = (vgui::CTreeViewListControl *)msg->m_szCommand;
    v11 = CTraceFilter::GetTraceType(this: v14);
    Cbuf_AddText(eTarget: v11, pText: (const char *)v14, nTickDelay: 0);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005D960
// Name: public: virtual bool CBaseClientState::ProcessCreateStringTable(class SVC_CreateStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClientState::ProcessCreateStringTable(CBaseClientState *this, SVC_CreateStringTable *msg)
{
  CBaseClientState *v2; // ebx
  IEngineVGuiInternal *v3; // eax
  SVC_CreateStringTable *v4; // edi
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ecx
  CNetworkStringTable *v7; // eax
  void (__thiscall *SetTick)(struct CNetworkStringTable *, int); // edx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v11; // ecx
  unsigned int v12; // edx
  unsigned int v13; // ebx
  const unsigned int *m_pDataIn; // ecx
  const unsigned int *m_pBufferEnd; // edi
  const unsigned int *v16; // edx
  unsigned int v17; // edi
  int v18; // eax
  const unsigned int *v19; // ecx
  unsigned int v20; // edx
  unsigned int v21; // ebx
  int v22; // ecx
  unsigned int v23; // edi
  const unsigned int *v24; // eax
  const unsigned int *v25; // ecx
  const unsigned int *v26; // edx
  unsigned int v27; // edi
  int v28; // eax
  const unsigned int *v29; // ecx
  unsigned int v30; // edx
  unsigned int v31; // ebx
  char *v32; // ebx
  unsigned __int8 *v33; // edi
  const unsigned int *v34; // eax
  int v35; // esi
  signed int v36; // eax
  float v38; // [esp-4h] [ebp-48h]
  unsigned int v39; // [esp-4h] [ebp-48h]
  bf_read data; // [esp+Ch] [ebp-38h] BYREF
  CBaseClientState *v41; // [esp+30h] [ebp-14h]
  char *compressedBuffer; // [esp+34h] [ebp-10h]
  CNetworkStringTable *table; // [esp+38h] [ebp-Ch]
  int startbit; // [esp+3Ch] [ebp-8h]
  unsigned int uncompressedSize; // [esp+40h] [ebp-4h] BYREF

  v2 = this;
  v41 = this;
  v3 = EngineVGui();
  v3->UpdateProgressBar(this: v3, a2: PROGRESS_PROCESSSTRINGTABLE, a3: true);
  v4 = msg;
  _COM_TimestampedLog(a1: " CBaseClient::ProcessCreateStringTable(%s)", msg->m_szTableName);
  CNetMessage::SetReliable(this: *(CNetMessage **)&v2->m_szEncryptionKey[2044], state: true);
  m_pData = msg->m_DataIn.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = msg->m_DataIn.m_nDataBits;
    startbit = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
             - msg->m_DataIn.m_nBitsAvail
             + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( startbit >= m_nDataBits )
      startbit = m_nDataBits;
  }
  else
  {
    startbit = 0;
  }
  v7 = (CNetworkStringTable *)(*(int (__thiscall **)(_DWORD, const char *, int, int, int, int))(**(_DWORD **)&v2->m_szEncryptionKey[2044]
                                                                                              + 4))(
                                a1: *(_DWORD *)&v2->m_szEncryptionKey[2044],
                                a2: msg->m_szTableName,
                                a3: msg->m_nMaxEntries,
                                a4: msg->m_nUserDataSize,
                                a5: msg->m_nUserDataSizeBits,
                                a6: msg->m_nFlags);
  SetTick = v7->SetTick;
  v38 = v2->m_ClockDriftMgr.m_ClockOffsets[15];
  table = v7;
  SetTick(this: v7, a2: LODWORD(v38));
  ((void (__thiscall *)(CNetworkStringTableContainer **, const char *))v2[-1].m_StringTableContainer[2].m_Tables.m_Memory.m_nGrowSize)(
    a1: &v2[-1].m_StringTableContainer,
    a2: msg->m_szTableName);
  if ( msg->m_bDataCompressed )
  {
    m_nBitsAvail = msg->m_DataIn.m_nBitsAvail;
    if ( m_nBitsAvail >= 32 )
    {
      m_nInBufWord = msg->m_DataIn.m_nInBufWord;
      v11 = m_nBitsAvail - 32;
      v12 = 0;
      msg->m_DataIn.m_nBitsAvail = v11;
      if ( v11 != 0 )
      {
        msg->m_DataIn.m_nInBufWord = 0;
        v13 = m_nInBufWord;
      }
      else
      {
        m_pDataIn = msg->m_DataIn.m_pDataIn;
        m_pBufferEnd = msg->m_DataIn.m_pBufferEnd;
        msg->m_DataIn.m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          msg->m_DataIn.m_nBitsAvail = 1;
          msg->m_DataIn.m_nInBufWord = 0;
          msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          v13 = m_nInBufWord;
        }
        else
        {
          if ( m_pDataIn <= m_pBufferEnd )
          {
            msg->m_DataIn.m_nInBufWord = *m_pDataIn;
            msg->m_DataIn.m_pDataIn = m_pDataIn + 1;
          }
          else
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
          }
          v13 = m_nInBufWord;
        }
      }
      goto LABEL_25;
    }
    v16 = msg->m_DataIn.m_pBufferEnd;
    v17 = msg->m_DataIn.m_nInBufWord;
    v18 = 32 - m_nBitsAvail;
    v19 = msg->m_DataIn.m_pDataIn;
    if ( v19 == v16 )
    {
      msg->m_DataIn.m_nBitsAvail = 1;
      msg->m_DataIn.m_nInBufWord = 0;
      msg->m_DataIn.m_bOverflow = true;
    }
    else
    {
      if ( v19 > v16 )
      {
        msg->m_DataIn.m_bOverflow = true;
        msg->m_DataIn.m_nInBufWord = 0;
LABEL_21:
        if ( msg->m_DataIn.m_bOverflow )
        {
          v13 = 0;
        }
        else
        {
          v20 = msg->m_DataIn.m_nInBufWord;
          v21 = (v20 & CBitBuffer::s_nMaskTable[v18]) << msg->m_DataIn.m_nBitsAvail;
          msg->m_DataIn.m_nBitsAvail = 32 - v18;
          v13 = v17 | v21;
          msg->m_DataIn.m_nInBufWord = v20 >> v18;
        }
        v12 = 0;
LABEL_25:
        v22 = msg->m_DataIn.m_nBitsAvail;
        uncompressedSize = v13;
        if ( v22 >= 32 )
        {
          v23 = msg->m_DataIn.m_nInBufWord;
          msg->m_DataIn.m_nBitsAvail = v22 - 32;
          if ( v22 == 32 )
          {
            v24 = msg->m_DataIn.m_pDataIn;
            v25 = msg->m_DataIn.m_pBufferEnd;
            msg->m_DataIn.m_nBitsAvail = 32;
            if ( v24 == v25 )
            {
              msg->m_DataIn.m_nBitsAvail = 1;
              msg->m_DataIn.m_pDataIn = v24 + 1;
            }
            else if ( v24 <= v25 )
            {
              v12 = *v24;
              msg->m_DataIn.m_pDataIn = v24 + 1;
            }
            else
            {
              msg->m_DataIn.m_bOverflow = true;
            }
          }
          goto LABEL_41;
        }
        v26 = msg->m_DataIn.m_pBufferEnd;
        v27 = msg->m_DataIn.m_nInBufWord;
        v28 = 32 - v22;
        v29 = msg->m_DataIn.m_pDataIn;
        if ( v29 == v26 )
        {
          msg->m_DataIn.m_nBitsAvail = 1;
          msg->m_DataIn.m_nInBufWord = 0;
          msg->m_DataIn.m_bOverflow = true;
        }
        else
        {
          if ( v29 > v26 )
          {
            msg->m_DataIn.m_bOverflow = true;
            msg->m_DataIn.m_nInBufWord = 0;
LABEL_38:
            if ( msg->m_DataIn.m_bOverflow )
            {
              v23 = 0;
LABEL_42:
              uncompressedSize = v13;
              v32 = (char *)MemAlloc_Alloc(nSize: 4 * ((v13 + 3) >> 2));
              compressedBuffer = (char *)MemAlloc_Alloc(nSize: 4 * ((v23 + 3) >> 2));
              CBitRead::ReadBits(this: &msg->m_DataIn, pOutData: compressedBuffer, nBits: 8 * v23);
              v39 = v23;
              v33 = (unsigned __int8 *)compressedBuffer;
              NET_BufferToBufferDecompress(
                dest: v32,
                destLen: &uncompressedSize,
                source: compressedBuffer,
                sourceLen: v39);
              data.m_pDebugName = nullptr;
              data.m_nDataBytes = 0;
              data.m_bOverflow = false;
              data.m_nDataBits = -1;
              CBitRead::StartReading(this: &data, pData: v32, nBytes: uncompressedSize, iStartBit: 0, nBits: -1);
              CNetworkStringTable::ParseUpdate(this: table, a2: v33, buf: &data, entries: msg->m_nNumEntries);
              free(pMem: v32);
              free(pMem: v33);
              v2 = v41;
              v4 = msg;
              goto LABEL_44;
            }
            v30 = msg->m_DataIn.m_nInBufWord;
            v31 = (v30 & CBitBuffer::s_nMaskTable[v28]) << msg->m_DataIn.m_nBitsAvail;
            msg->m_DataIn.m_nBitsAvail = 32 - v28;
            v23 = v31 | v27;
            v13 = uncompressedSize;
            v12 = v30 >> v28;
LABEL_41:
            msg->m_DataIn.m_nInBufWord = v12;
            goto LABEL_42;
          }
          msg->m_DataIn.m_nInBufWord = *v29;
        }
        msg->m_DataIn.m_pDataIn = v29 + 1;
        goto LABEL_38;
      }
      msg->m_DataIn.m_nInBufWord = *v19;
    }
    msg->m_DataIn.m_pDataIn = v19 + 1;
    goto LABEL_21;
  }
  CNetworkStringTable::ParseUpdate(
    this: table,
    a2: (unsigned __int8 *)msg,
    buf: &msg->m_DataIn,
    entries: msg->m_nNumEntries);
LABEL_44:
  CNetMessage::SetReliable(this: *(CNetMessage **)&v2->m_szEncryptionKey[2044], state: false);
  v34 = msg->m_DataIn.m_pData;
  if ( v34 != nullptr )
  {
    v35 = msg->m_DataIn.m_nDataBits;
    v36 = 32 * (msg->m_DataIn.m_pDataIn - v34) - msg->m_DataIn.m_nBitsAvail + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( v36 < v35 )
      v35 = v36;
  }
  else
  {
    v35 = 0;
  }
  _COM_TimestampedLog(a1: " CBaseClient::ProcessCreateStringTable(%s)-done", v4->m_szTableName);
  return v35 - startbit == v4->m_nLength;
}

//------------------------------------------------------------------------------
// Address: 0x1005DCE0
// Name: public: virtual bool CBaseClientState::ProcessUpdateStringTable(class SVC_UpdateStringTable __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessUpdateStringTable(CBaseClientState *this, SVC_UpdateStringTable *msg)
{
  const unsigned int *m_pData; // eax
  int m_nDataBits; // ebx
  CNetworkStringTable *v4; // eax
  const unsigned int *v5; // eax
  int v7; // eax

  m_pData = msg->m_DataIn.m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (msg->m_DataIn.m_pDataIn - m_pData)
                - msg->m_DataIn.m_nBitsAvail
                + 8 * (msg->m_DataIn.m_nDataBytes & 3);
    if ( m_nDataBits >= msg->m_DataIn.m_nDataBits )
      m_nDataBits = msg->m_DataIn.m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  if ( *(_DWORD *)&this->m_szEncryptionKey[2044] != 0 )
  {
    v4 = (CNetworkStringTable *)(*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)&this->m_szEncryptionKey[2044] + 16))(
                                  a1: *(_DWORD *)&this->m_szEncryptionKey[2044],
                                  a2: msg->m_nTableID);
    CNetworkStringTable::ParseUpdate(
      this: v4,
      a2: (unsigned __int8 *)msg,
      buf: &msg->m_DataIn,
      entries: msg->m_nChangedEntries);
  }
  else
  {
    _Warning(a1: "m_StringTableContainer is NULL in CBaseClientState::ProcessUpdateStringTable\n");
  }
  v5 = msg->m_DataIn.m_pData;
  if ( v5 == nullptr )
    return -m_nDataBits == msg->m_nLength;
  v7 = 32 * (msg->m_DataIn.m_pDataIn - v5) - msg->m_DataIn.m_nBitsAvail + 8 * (msg->m_DataIn.m_nDataBytes & 3);
  if ( v7 >= msg->m_DataIn.m_nDataBits )
    v7 = msg->m_DataIn.m_nDataBits;
  return v7 - m_nDataBits == msg->m_nLength;
}

//------------------------------------------------------------------------------
// Address: 0x1005DDB0
// Name: public: virtual bool CBaseClientState::ProcessPacketEntities(class SVC_PacketEntities __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessPacketEntities(CBaseClientState *this, SVC_PacketEntities *msg)
{
  int m_ListenServerSteamID; // eax

  m_ListenServerSteamID = this->m_ListenServerSteamID;
  if ( m_ListenServerSteamID < 5 )
  {
    ConMsg(a1: "Received packet entities while connecting!\n");
    return 0;
  }
  if ( m_ListenServerSteamID == 5 )
  {
    if ( msg->m_bIsDelta )
    {
      ConMsg(a1: "Received delta packet entities while spawing!\n");
      return 0;
    }
    (*(void (__thiscall **)(char *, int, _DWORD, _DWORD))(*((_DWORD *)this - 2) + 60))(
      a1: (char *)this - 8,
      a2: 6,
      a3: LODWORD(this->m_flNextCmdTime),
      a4: 0);
  }
  if ( this->m_ClockDriftMgr.m_nServerTick >= 0 || !msg->m_bIsDelta )
    this->m_ClockDriftMgr.m_nServerTick = LODWORD(this->m_ClockDriftMgr.m_ClockOffsets[15]);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005DE30
// Name: public: virtual bool CBaseClientState::LinkClasses(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::LinkClasses(CBaseClientState *this)
{
  CBaseClientState *v1; // esi
  int m_nServerClasses; // ecx
  int v3; // eax
  char **p_m_DatatableName; // edx
  C_ServerClassInfo *v6; // esi
  const char *m_ClassName; // ebx
  ClientClass *AllClasses; // edi
  const char *m_pNetTableName; // edi
  const char *m_DatatableName; // ebx
  CBaseClientState *v11; // [esp+8h] [ebp-Ch]
  int j; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = this;
  m_nServerClasses = this->m_nServerClasses;
  v3 = 0;
  v11 = v1;
  if ( m_nServerClasses > 0 )
  {
    p_m_DatatableName = &v1->m_pServerClasses->m_DatatableName;
    do
    {
      if ( *p_m_DatatableName == nullptr )
      {
        Host_EndGame(bShowMainMenu: true, message: "CL_ParseClassInfo_EndClasses: class %d not initialized.\n", v3);
        return 0;
      }
      ++v3;
      p_m_DatatableName += 4;
    }
    while ( v3 < m_nServerClasses );
  }
  i = 0;
  if ( m_nServerClasses <= 0 )
    return 1;
  for ( j = 0; ; ++j )
  {
    v6 = &v1->m_pServerClasses[j];
    m_ClassName = v6->m_ClassName;
    AllClasses = ClientDLL_GetAllClasses();
    if ( AllClasses != nullptr )
    {
      while ( _V_stricmp(s1: AllClasses->m_pNetworkName, s2: m_ClassName) != 0 )
      {
        AllClasses = AllClasses->m_pNext;
        if ( AllClasses == nullptr )
          goto LABEL_12;
      }
    }
    else
    {
LABEL_12:
      AllClasses = nullptr;
    }
    v6->m_pClientClass = AllClasses;
    if ( AllClasses != nullptr )
      break;
    _Msg(a1: "Client missing DT class %s\n", v6->m_ClassName);
LABEL_17:
    if ( ++i >= v11->m_nServerClasses )
      return 1;
    v1 = v11;
  }
  m_pNetTableName = AllClasses->m_pRecvTable->m_pNetTableName;
  m_DatatableName = v6->m_DatatableName;
  if ( _V_stricmp(s1: m_DatatableName, s2: m_pNetTableName) == 0 )
  {
    v6->m_pClientClass->m_ClassID = i;
    goto LABEL_17;
  }
  Host_EndGame(
    bShowMainMenu: true,
    message: "CL_ParseClassInfo_EndClasses: server and client classes for '%s' use different datatables (server: %s, client: %s)",
    v6->m_ClassName,
    m_DatatableName,
    m_pNetTableName);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005DF50
// Name: public: void CBaseClientState::FreeEntityBaselines(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::FreeEntityBaselines(CBaseClientState *this)
{
  PackedEntity **v1; // esi
  int j; // ebx
  PackedEntity *v3; // edi
  int i; // [esp+Ch] [ebp-4h]

  v1 = this->m_pEntityBaselines[0];
  for ( i = 2; i != 0; --i )
  {
    for ( j = 2048; j != 0; --j )
    {
      v3 = *v1;
      if ( *v1 != nullptr )
      {
        PackedEntity::~PackedEntity(this: *v1);
        free(pMem: v3);
        *v1 = nullptr;
      }
      ++v1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005DFA0
// Name: public: void CBaseClientState::CopyEntityBaseline(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::CopyEntityBaseline(CBaseClientState *this, int iFrom, int iTo)
{
  PackedEntity **v3; // ebx
  PackedEntity **v4; // ecx
  PackedEntity *v5; // edi
  PackedEntity *v6; // esi
  PackedEntity *v7; // eax
  PackedEntity *v8; // eax
  bool v9; // zf
  int iFroma; // [esp+14h] [ebp+8h]
  int iToa; // [esp+18h] [ebp+Ch]

  v3 = this->m_pEntityBaselines[iTo];
  v4 = this->m_pEntityBaselines[iFrom];
  iToa = (int)v4;
  iFroma = 2048;
  do
  {
    v5 = *v4;
    v6 = *v3;
    if ( *v4 != nullptr )
    {
      if ( v6 == nullptr )
      {
        v7 = (PackedEntity *)MemAlloc_Alloc(nSize: 0x34u);
        if ( v7 != nullptr )
          v8 = PackedEntity::PackedEntity(this: v7);
        else
          v8 = nullptr;
        v6 = v8;
        *v3 = v8;
        v8->m_pClientClass = nullptr;
        v8->m_pServerClass = nullptr;
        _InterlockedExchange(&v8->m_ReferenceCount.m_value, 0);
      }
      v6->m_nEntityIndex = v5->m_nEntityIndex;
      v6->m_pClientClass = v5->m_pClientClass;
      v6->m_pServerClass = v5->m_pServerClass;
      PackedEntity::AllocAndCopyPadded(this: v6, pData: v5->m_pData, size: (v5->m_nBits + 7) >> 3);
    }
    else if ( v6 != nullptr )
    {
      PackedEntity::~PackedEntity(this: *v3);
      free(pMem: v6);
      *v3 = nullptr;
    }
    v4 = (PackedEntity **)(iToa + 4);
    ++v3;
    v9 = iFroma-- == 1;
    iToa += 4;
  }
  while ( !v9 );
}

//------------------------------------------------------------------------------
// Address: 0x1005E070
// Name: public: virtual bool CBaseClientState::ProcessCmdKeyValues(class SVC_CmdKeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessCmdKeyValues(CBaseClientState *this, SVC_CmdKeyValues *msg)
{
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  KeyValues *Copy; // eax
  IMatchEventsSubscription *v6; // eax

  v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v3 != nullptr )
    v4 = KeyValues::KeyValues(this: v3, setName: "Client::CmdKeyValues");
  else
    v4 = nullptr;
  Copy = KeyValues::MakeCopy(this: msg->m_pKeyValues);
  KeyValues::AddSubKey(this: v4, pSubkey: Copy);
  KeyValues::SetInt(this: v4, keyName: "slot", value: this->m_nViewEntity);
  v6 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v6->BroadcastEvent(this: v6, a2: v4);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1005E170
// Name: public: void bf_write::WriteOneBit(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall bf_write::WriteOneBit(bf_write *this, int nValue)
{
  int m_iCurBit; // ecx
  int v4; // esi
  char v5; // bl
  unsigned __int8 *m_pData; // edi

  m_iCurBit = this->m_iCurBit;
  if ( m_iCurBit + 1 > this->m_nDataBits )
    this->m_bOverflow = true;
  if ( !this->m_bOverflow )
  {
    v4 = m_iCurBit >> 3;
    v5 = 1 << (m_iCurBit & 7);
    m_pData = this->m_pData;
    if ( nValue != 0 )
      m_pData[v4] |= v5;
    else
      m_pData[v4] &= ~v5;
    ++this->m_iCurBit;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005E1E0
// Name: public: virtual unsigned int NET_StringCmd::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NET_StringCmd::GetSize(NET_StringCmd *this)
{
  return 1044;
}

//------------------------------------------------------------------------------
// Address: 0x1005E1F0
// Name: public: virtual bool NET_StringCmd::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_StringCmd::Process(NET_StringCmd *this)
{
  return this->m_pMessageHandler->ProcessStringCmd(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E200
// Name: public: virtual int NET_StringCmd::GetGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall NET_StringCmd::GetGroup(NET_SetConVar *this)
{
  return 12;
}

//------------------------------------------------------------------------------
// Address: 0x1005E210
// Name: public: virtual char const __near * NET_Tick::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_Tick::GetName(NET_Tick *this)
{
  return "net_Tick";
}

//------------------------------------------------------------------------------
// Address: 0x1005E230
// Name: public: virtual char const __near * SVC_Print::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_Print::GetName(SVC_Print *this)
{
  return "svc_Print";
}

//------------------------------------------------------------------------------
// Address: 0x1005E240
// Name: public: virtual unsigned int SVC_Print::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_Print::GetSize(SVC_Print *this)
{
  return 2068;
}

//------------------------------------------------------------------------------
// Address: 0x1005E250
// Name: public: virtual bool SVC_Print::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_Print::Process(SVC_Print *this)
{
  return this->m_pMessageHandler->ProcessPrint(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E260
// Name: public: virtual char const __near * SVC_SetPause::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_SetPause::GetName(SVC_SetPause *this)
{
  return "svc_SetPause";
}

//------------------------------------------------------------------------------
// Address: 0x1005E270
// Name: public: virtual bool SVC_SetPause::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SetPause::Process(CLC_ListenEvents *this)
{
  return this->m_pMessageHandler->ProcessListenEvents(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E280
// Name: public: virtual char const __near * SVC_VoiceInit::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_VoiceInit::GetName(SVC_VoiceInit *this)
{
  return "svc_VoiceInit";
}

//------------------------------------------------------------------------------
// Address: 0x1005E290
// Name: public: virtual unsigned int SVC_VoiceInit::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_VoiceInit::GetSize(SVC_VoiceInit *this)
{
  return 284;
}

//------------------------------------------------------------------------------
// Address: 0x1005E2A0
// Name: public: virtual int SVC_VoiceData::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_VoiceData::GetType(SVC_VoiceData *this)
{
  return 15;
}

//------------------------------------------------------------------------------
// Address: 0x1005E2B0
// Name: public: virtual char const __near * SVC_VoiceData::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_VoiceData::GetName(SVC_VoiceData *this)
{
  return "svc_VoiceData";
}

//------------------------------------------------------------------------------
// Address: 0x1005E2C0
// Name: public: virtual bool SVC_VoiceData::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_VoiceData::Process(SVC_VoiceData *this)
{
  return this->m_pMessageHandler->ProcessVoiceData(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E2E0
// Name: public: virtual char const __near * SVC_SetView::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_SetView::GetName(SVC_SetView *this)
{
  return "svc_SetView";
}

//------------------------------------------------------------------------------
// Address: 0x1005E300
// Name: public: virtual int SVC_FixAngle::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_FixAngle::GetType(SVC_FixAngle *this)
{
  return 19;
}

//------------------------------------------------------------------------------
// Address: 0x1005E310
// Name: public: virtual char const __near * SVC_FixAngle::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_FixAngle::GetName(SVC_FixAngle *this)
{
  return "svc_FixAngle";
}

//------------------------------------------------------------------------------
// Address: 0x1005E320
// Name: public: virtual bool SVC_FixAngle::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_FixAngle::Process(SVC_FixAngle *this)
{
  return this->m_pMessageHandler->ProcessFixAngle(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E330
// Name: public: virtual char const __near * SVC_CrosshairAngle::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_CrosshairAngle::GetName(SVC_CrosshairAngle *this)
{
  return "svc_CrosshairAngle";
}

//------------------------------------------------------------------------------
// Address: 0x1005E340
// Name: public: virtual bool SVC_CrosshairAngle::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_CrosshairAngle::Process(SVC_CrosshairAngle *this)
{
  return this->m_pMessageHandler->ProcessCrosshairAngle(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E350
// Name: public: virtual int SVC_EntityMessage::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_EntityMessage::GetType(SVC_EntityMessage *this)
{
  return 24;
}

//------------------------------------------------------------------------------
// Address: 0x1005E360
// Name: public: virtual char const __near * SVC_EntityMessage::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_EntityMessage::GetName(SVC_EntityMessage *this)
{
  return "svc_EntityMessage";
}

//------------------------------------------------------------------------------
// Address: 0x1005E380
// Name: public: virtual bool SVC_EntityMessage::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_EntityMessage::Process(SVC_EntityMessage *this)
{
  return this->m_pMessageHandler->ProcessEntityMessage(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E390
// Name: public: virtual int SVC_TempEntities::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_TempEntities::GetType(SVC_TempEntities *this)
{
  return 27;
}

//------------------------------------------------------------------------------
// Address: 0x1005E3A0
// Name: public: virtual char const __near * SVC_TempEntities::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_TempEntities::GetName(SVC_TempEntities *this)
{
  return "svc_TempEntities";
}

//------------------------------------------------------------------------------
// Address: 0x1005E3B0
// Name: public: virtual bool SVC_TempEntities::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_TempEntities::Process(SVC_TempEntities *this)
{
  return this->m_pMessageHandler->ProcessTempEntities(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E3C0
// Name: public: virtual int NET_SetConVar::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall NET_SetConVar::GetType(NET_SetConVar *this)
{
  return 6;
}

//------------------------------------------------------------------------------
// Address: 0x1005E3D0
// Name: public: virtual int SVC_Menu::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_Menu::GetType(SVC_Menu *this)
{
  return 29;
}

//------------------------------------------------------------------------------
// Address: 0x1005E3E0
// Name: public: virtual char const __near * SVC_Menu::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_Menu::GetName(SVC_Menu *this)
{
  return "svc_Menu";
}

//------------------------------------------------------------------------------
// Address: 0x1005E430
// Name: public: virtual bool CBaseClientState::CAsyncOperation_ReserveServer::IsFinished(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CBaseClientState::CAsyncOperation_ReserveServer::IsFinished(
        CBaseClientState::CAsyncOperation_ReserveServer *this)
{
  return this->m_eState > AOS_ABORTING;
}

//------------------------------------------------------------------------------
// Address: 0x1005E440
// Name: public: virtual unsigned __int64 CBaseClientState::CAsyncOperation_ReserveServer::GetResult(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CBaseClientState::CAsyncOperation_ReserveServer::GetResult(
        CBaseClientState::CAsyncOperation_ReserveServer *this)
{
  if ( this->m_eState == AOS_SUCCEEDED )
    return (unsigned int)netadr_s::ToString(this: &this->m_adr, baseOnly: false);
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1005E490
// Name: public: virtual void CBaseClientState::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::Clear(CBaseClientState *this)
{
  bool v2; // zf
  C_ServerClassInfo *m_pServerClasses; // ecx
  int *p_m_InstanceBaselineIndex; // edx
  int v5; // ebx
  void **p_m_DatatableName; // edi
  void *v7; // ecx
  CNetworkStringTableContainer *m_StringTableContainer; // ecx
  INetChannel *m_NetChannel; // ecx
  int *v10; // [esp+Ch] [ebp-4h]

  this->m_nServerCount = -1;
  this->m_nDeltaTick = -1;
  CClockDriftMgr::Clear(this: &this->m_ClockDriftMgr);
  v2 = this->m_szLevelNameShort[0] == 0;
  this->m_nCurrentSequence = 0;
  this->m_nServerClasses = 0;
  this->m_nServerClassBits = 0;
  this->m_nPlayerSlot = 0;
  this->m_nSplitScreenSlot = 0;
  this->m_szLevelName[0] = 0;
  this->m_nMaxClients = 0;
  if ( !v2 )
    V_strncpy(pDest: this->m_szLastLevelNameShort, pSrc: this->m_szLevelNameShort, maxLen: 40);
  m_pServerClasses = this->m_pServerClasses;
  this->m_szLevelNameShort[0] = 0;
  if ( m_pServerClasses != nullptr )
  {
    p_m_InstanceBaselineIndex = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    v5 = m_pServerClasses[-1].m_InstanceBaselineIndex - 1;
    v10 = &m_pServerClasses[-1].m_InstanceBaselineIndex;
    if ( v5 >= 0 )
    {
      p_m_DatatableName = (void **)&m_pServerClasses[m_pServerClasses[-1].m_InstanceBaselineIndex].m_DatatableName;
      do
      {
        v7 = *(p_m_DatatableName - 5);
        p_m_DatatableName -= 4;
        free(pMem: v7);
        free(pMem: *p_m_DatatableName);
        --v5;
      }
      while ( v5 >= 0 );
      p_m_InstanceBaselineIndex = v10;
    }
    free(pMem: p_m_InstanceBaselineIndex);
    this->m_pServerClasses = nullptr;
  }
  m_StringTableContainer = this->m_StringTableContainer;
  if ( m_StringTableContainer != nullptr )
  {
    m_StringTableContainer->RemoveAllTables(this: m_StringTableContainer);
    this->m_StringTableContainer = nullptr;
  }
  CBaseClientState::FreeEntityBaselines(this);
  if ( !this->m_bSplitScreenUser )
    RecvTable_Term(clearall: false);
  m_NetChannel = this->m_NetChannel;
  if ( m_NetChannel != nullptr )
    m_NetChannel->Reset(this: m_NetChannel);
  this->m_nViewEntity = 0;
  this->m_nChallengeNr = 0;
  this->m_flConnectTime = 0.0;
  this->m_bPaused = false;
  this->m_bServerInfoProcessed = false;
}

//------------------------------------------------------------------------------
// Address: 0x1005E680
// Name: public: virtual bool SVC_BSPDecal::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_BSPDecal::Process(SVC_BSPDecal *this)
{
  return this->m_pMessageHandler->ProcessBSPDecal(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E690
// Name: public: virtual int SVC_GameEvent::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_GameEvent::GetType(SVC_GameEvent *this)
{
  return 25;
}

//------------------------------------------------------------------------------
// Address: 0x1005E6A0
// Name: public: virtual char const __near * SVC_GameEvent::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_GameEvent::GetName(SVC_GameEvent *this)
{
  return "svc_GameEvent";
}

//------------------------------------------------------------------------------
// Address: 0x1005E6D0
// Name: public: virtual int SVC_PacketEntities::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_PacketEntities::GetType(SVC_PacketEntities *this)
{
  return 26;
}

//------------------------------------------------------------------------------
// Address: 0x1005E6F0
// Name: public: virtual unsigned int SVC_PacketEntities::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_PacketEntities::GetSize(SVC_UserMessage *this)
{
  return 100;
}

//------------------------------------------------------------------------------
// Address: 0x1005E700
// Name: public: virtual bool SVC_PacketEntities::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PacketEntities::Process(SVC_PacketEntities *this)
{
  return this->m_pMessageHandler->ProcessPacketEntities(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E720
// Name: public: virtual char const __near * SVC_GameEventList::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_GameEventList::GetName(SVC_GameEventList *this)
{
  return "svc_GameEventList";
}

//------------------------------------------------------------------------------
// Address: 0x1005E730
// Name: public: virtual bool SVC_GameEventList::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GameEventList::Process(SVC_GameEventList *this)
{
  return this->m_pMessageHandler->ProcessGameEventList(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E740
// Name: public: virtual int SVC_GetCvarValue::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_GetCvarValue::GetType(SVC_GetCvarValue *this)
{
  return 31;
}

//------------------------------------------------------------------------------
// Address: 0x1005E750
// Name: public: virtual char const __near * SVC_GetCvarValue::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_GetCvarValue::GetName(SVC_GetCvarValue *this)
{
  return "svc_GetCvarValue";
}

//------------------------------------------------------------------------------
// Address: 0x1005E760
// Name: public: virtual unsigned int SVC_GetCvarValue::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall SVC_GetCvarValue::GetSize(SVC_GetCvarValue *this)
{
  return 280;
}

//------------------------------------------------------------------------------
// Address: 0x1005E770
// Name: public: virtual bool SVC_GetCvarValue::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_GetCvarValue::Process(SVC_GetCvarValue *this)
{
  return this->m_pMessageHandler->ProcessGetCvarValue(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E780
// Name: public: virtual int SVC_SplitScreen::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_SplitScreen::GetType(SVC_SplitScreen *this)
{
  return 22;
}

//------------------------------------------------------------------------------
// Address: 0x1005E790
// Name: public: virtual char const __near * SVC_SplitScreen::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_SplitScreen::GetName(SVC_SplitScreen *this)
{
  return "svc_SplitScreen";
}

//------------------------------------------------------------------------------
// Address: 0x1005E7A0
// Name: public: virtual unsigned int SVC_CrosshairAngle::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_CrosshairAngle::GetSize(SVC_Prefetch *this)
{
  return 28;
}

//------------------------------------------------------------------------------
// Address: 0x1005E7B0
// Name: public: virtual bool SVC_SplitScreen::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SplitScreen::Process(SVC_SplitScreen *this)
{
  return this->m_pMessageHandler->ProcessSplitScreen(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005E7C0
// Name: public: SVC_PaintmapData::SVC_PaintmapData(void)
// Source: json
//------------------------------------------------------------------------------
SVC_PaintmapData *__thiscall SVC_PaintmapData::SVC_PaintmapData(SVC_PaintmapData *this)
{
  this->m_bReliable = true;
  this->m_NetChannel = nullptr;
  this->__vftable = (SVC_PaintmapData_vtbl *)&SVC_PaintmapData::`vftable';
  this->m_DataIn.m_bOverflow = false;
  this->m_DataIn.m_pDebugName = nullptr;
  this->m_DataIn.m_nDataBits = -1;
  this->m_DataIn.m_nDataBytes = 0;
  bf_write::bf_write(this: &this->m_DataOut);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1005E7F0
// Name: public: virtual int SVC_PaintmapData::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_PaintmapData::GetType(SVC_PaintmapData *this)
{
  return 33;
}

//------------------------------------------------------------------------------
// Address: 0x1005E800
// Name: public: virtual char const __near * SVC_PaintmapData::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_PaintmapData::GetName(SVC_PaintmapData *this)
{
  return "svc_PaintmapData";
}

//------------------------------------------------------------------------------
// Address: 0x1005E810
// Name: public: virtual bool SVC_PaintmapData::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_PaintmapData::Process(SVC_PaintmapData *this)
{
  return this->m_pMessageHandler->ProcessPaintmapData(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1005EA40
// Name: Read_S2A_INFO_SRC
// Source: json
//------------------------------------------------------------------------------
void __usercall Read_S2A_INFO_SRC(netadr_s *from@<ecx>, bf_read *msg@<esi>)
{
  const char *v2; // eax
  void (*v3)(const char *, ...); // ebx
  int m_nBitsAvail; // ecx
  unsigned int v5; // edx
  int v6; // edi
  unsigned int v7; // edx
  const unsigned int *v8; // eax
  const unsigned int *v9; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // edi
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  int v14; // eax
  unsigned int v15; // edx
  unsigned int v16; // ebx
  int v17; // ecx
  unsigned int v18; // eax
  __int16 v19; // dx
  int v20; // ecx
  const unsigned int *v21; // ecx
  unsigned int v22; // ecx
  const unsigned int *v23; // edx
  unsigned int v24; // edi
  const unsigned int *v25; // ecx
  unsigned int v26; // edx
  unsigned int v27; // ebx
  __int16 v28; // di
  unsigned int v29; // edx
  int v30; // ecx
  unsigned int v31; // eax
  unsigned int v32; // edx
  int v33; // ecx
  const unsigned int *v34; // eax
  const unsigned int *v35; // ecx
  unsigned int v36; // ecx
  const unsigned int *v37; // edx
  unsigned int v38; // edi
  int v39; // eax
  const unsigned int *v40; // ecx
  unsigned int v41; // edx
  unsigned int v42; // ebx
  int v43; // edi
  unsigned int v44; // edx
  int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // edx
  int v48; // ecx
  const unsigned int *v49; // eax
  const unsigned int *v50; // ecx
  unsigned int v51; // ecx
  const unsigned int *v52; // edx
  unsigned int v53; // edi
  int v54; // eax
  const unsigned int *v55; // ecx
  unsigned int v56; // edx
  unsigned int v57; // ebx
  int v58; // edi
  unsigned int v59; // edx
  int v60; // ecx
  unsigned int v61; // edx
  int v62; // eax
  int v63; // ecx
  unsigned int v64; // edx
  const unsigned int *v65; // ecx
  const unsigned int *v66; // edx
  const unsigned int *v67; // edx
  unsigned int v68; // edi
  int v69; // eax
  const unsigned int *v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // ebx
  int v73; // ecx
  const char *v74; // ebx
  unsigned int v75; // eax
  int v76; // edi
  int v77; // ecx
  unsigned int v78; // edx
  const unsigned int *v79; // eax
  const unsigned int *v80; // ecx
  const unsigned int *v81; // edx
  unsigned int v82; // edi
  int v83; // eax
  const unsigned int *v84; // ecx
  unsigned int v85; // edx
  unsigned int v86; // ebx
  int v87; // ecx
  const char *v88; // ebx
  unsigned int v89; // eax
  int v90; // edx
  int v91; // ecx
  int v92; // edi
  const unsigned int *v93; // eax
  const unsigned int *v94; // ecx
  const unsigned int *v95; // edx
  unsigned int v96; // edi
  int v97; // eax
  const unsigned int *v98; // ecx
  unsigned int v99; // edx
  unsigned int v100; // ebx
  int v101; // ecx
  unsigned int v102; // eax
  int v103; // edx
  int v104; // ecx
  int v105; // edi
  const unsigned int *v106; // eax
  const unsigned int *v107; // ecx
  const unsigned int *v108; // edx
  unsigned int v109; // edi
  int v110; // eax
  const unsigned int *v111; // ecx
  unsigned int v112; // edx
  unsigned int v113; // ebx
  const char *v114; // eax
  void (*v115)(const char *, ...); // ebx
  int v116; // ecx
  unsigned int v117; // eax
  int v118; // edx
  int v119; // ecx
  int v120; // edi
  const unsigned int *v121; // eax
  const unsigned int *v122; // ecx
  const unsigned int *v123; // edx
  unsigned int v124; // edi
  int v125; // eax
  const unsigned int *v126; // ecx
  unsigned int v127; // edx
  unsigned int v128; // ebx
  const char *v129; // eax
  const unsigned int *m_pData; // eax
  int m_nDataBits; // eax
  int v132; // ecx
  unsigned int v133; // eax
  int v134; // edx
  int v135; // ecx
  int v136; // ebx
  const unsigned int *v137; // eax
  const unsigned int *v138; // ecx
  const unsigned int *v139; // edx
  unsigned int v140; // edi
  int v141; // eax
  const unsigned int *v142; // ecx
  unsigned int v143; // edx
  unsigned int v144; // ebx
  int v145; // ecx
  unsigned int v146; // eax
  unsigned __int16 v147; // di
  int v148; // ecx
  unsigned int v149; // edx
  const unsigned int *v150; // eax
  const unsigned int *v151; // ecx
  const unsigned int *v152; // edx
  unsigned int v153; // edi
  int v154; // eax
  const unsigned int *v155; // ecx
  unsigned int v156; // edx
  int v157; // ecx
  unsigned int v158; // eax
  __int16 v159; // dx
  int v160; // ecx
  const unsigned int *v161; // ecx
  unsigned int v162; // ecx
  const unsigned int *v163; // edx
  unsigned int v164; // edi
  const unsigned int *v165; // ecx
  unsigned int v166; // edx
  __int16 v167; // di
  unsigned int v168; // edx
  void (*v169)(const char *, ...); // edi
  char str[1024]; // [esp+8h] [ebp-404h] BYREF
  const char *sType; // [esp+408h] [ebp-4h]

  v2 = netadr_s::ToString(this: from, baseOnly: false);
  v3 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "Responder   : %s\n", v2);
  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_15:
        if ( msg->m_bOverflow )
        {
          v14 = 0;
          goto LABEL_20;
        }
        v15 = msg->m_nInBufWord;
        v16 = (v15 & CBitBuffer::s_nMaskTable[v12]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v12;
        v6 = v16 | m_nInBufWord;
        v3 = (void (*)(const char *, ...))_Msg;
        v7 = v15 >> v12;
        goto LABEL_18;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v5 = msg->m_nInBufWord;
  v6 = (unsigned __int8)v5;
  msg->m_nBitsAvail = m_nBitsAvail - 8;
  if ( m_nBitsAvail == 8 )
  {
    v8 = msg->m_pDataIn;
    v9 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v8 + 1;
    }
    else if ( v8 <= v9 )
    {
      msg->m_nInBufWord = *v8;
      msg->m_pDataIn = v8 + 1;
    }
    else
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
    }
    goto LABEL_19;
  }
  v7 = v5 >> 8;
LABEL_18:
  msg->m_nInBufWord = v7;
LABEL_19:
  v14 = v6;
LABEL_20:
  v3(a1: "Protocol    : %d\n", v14);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v3(a1: "Hostname    : %s\n", str);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v3(a1: "Map         : %s\n", str);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v3(a1: "Game        : %s\n", str);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v3(a1: "Description : %s\n", str);
  v17 = msg->m_nBitsAvail;
  if ( v17 < 16 )
  {
    v23 = msg->m_pBufferEnd;
    v24 = msg->m_nInBufWord;
    v18 = 16 - v17;
    v25 = msg->m_pDataIn;
    if ( v25 == v23 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v25 > v23 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_35;
      }
      msg->m_nInBufWord = *v25;
    }
    msg->m_pDataIn = v25 + 1;
LABEL_35:
    if ( msg->m_bOverflow )
    {
      LOWORD(v18) = 0;
    }
    else
    {
      v26 = msg->m_nInBufWord;
      v27 = (v26 & CBitBuffer::s_nMaskTable[v18]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v18;
      v28 = v27 | v24;
      v3 = (void (*)(const char *, ...))_Msg;
      v29 = v26 >> v18;
      LOWORD(v18) = v28;
      msg->m_nInBufWord = v29;
    }
    goto LABEL_38;
  }
  v18 = msg->m_nInBufWord;
  v19 = v18;
  v20 = v17 - 16;
  msg->m_nBitsAvail = v20;
  if ( v20 != 0 )
  {
    msg->m_nInBufWord = HIWORD(v18);
  }
  else
  {
    v18 = (unsigned int)msg->m_pDataIn;
    v21 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( (const unsigned int *)v18 == v21 )
    {
      msg->m_pDataIn = (const unsigned int *)(v18 + 4);
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      LOWORD(v18) = v19;
    }
    else
    {
      if ( v18 <= (unsigned int)v21 )
      {
        v22 = *(_DWORD *)v18;
        msg->m_pDataIn = (const unsigned int *)(v18 + 4);
        msg->m_nInBufWord = v22;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      LOWORD(v18) = v19;
    }
  }
LABEL_38:
  v3(a1: "AppID       : %u\n", (__int16)v18);
  v30 = msg->m_nBitsAvail;
  if ( v30 < 8 )
  {
    v37 = msg->m_pBufferEnd;
    v38 = msg->m_nInBufWord;
    v39 = 8 - v30;
    v40 = msg->m_pDataIn;
    if ( v40 == v37 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v40 > v37 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_53;
      }
      msg->m_nInBufWord = *v40;
    }
    msg->m_pDataIn = v40 + 1;
LABEL_53:
    if ( msg->m_bOverflow )
    {
      v31 = 0;
    }
    else
    {
      v41 = msg->m_nInBufWord;
      v42 = (v41 & CBitBuffer::s_nMaskTable[v39]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v39;
      v43 = v42 | v38;
      v3 = (void (*)(const char *, ...))_Msg;
      v44 = v41 >> v39;
      v31 = v43;
      msg->m_nInBufWord = v44;
    }
    goto LABEL_56;
  }
  v31 = msg->m_nInBufWord;
  v32 = (unsigned __int8)v31;
  v33 = v30 - 8;
  msg->m_nBitsAvail = v33;
  if ( v33 != 0 )
  {
    msg->m_nInBufWord = v31 >> 8;
    v31 = (unsigned __int8)v31;
  }
  else
  {
    v34 = msg->m_pDataIn;
    v35 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v34 == v35 )
    {
      msg->m_pDataIn = v34 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v31 = v32;
    }
    else
    {
      if ( v34 <= v35 )
      {
        v36 = *v34;
        msg->m_pDataIn = v34 + 1;
        msg->m_nInBufWord = v36;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v31 = v32;
    }
  }
LABEL_56:
  v3(a1: "Players      : %u\n", v31);
  v45 = msg->m_nBitsAvail;
  if ( v45 < 8 )
  {
    v52 = msg->m_pBufferEnd;
    v53 = msg->m_nInBufWord;
    v54 = 8 - v45;
    v55 = msg->m_pDataIn;
    if ( v55 == v52 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v55 > v52 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_71;
      }
      msg->m_nInBufWord = *v55;
    }
    msg->m_pDataIn = v55 + 1;
LABEL_71:
    if ( msg->m_bOverflow )
    {
      v46 = 0;
    }
    else
    {
      v56 = msg->m_nInBufWord;
      v57 = (v56 & CBitBuffer::s_nMaskTable[v54]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v54;
      v58 = v57 | v53;
      v3 = (void (*)(const char *, ...))_Msg;
      v59 = v56 >> v54;
      v46 = v58;
      msg->m_nInBufWord = v59;
    }
    goto LABEL_74;
  }
  v46 = msg->m_nInBufWord;
  v47 = (unsigned __int8)v46;
  v48 = v45 - 8;
  msg->m_nBitsAvail = v48;
  if ( v48 != 0 )
  {
    msg->m_nInBufWord = v46 >> 8;
    v46 = (unsigned __int8)v46;
  }
  else
  {
    v49 = msg->m_pDataIn;
    v50 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v49 == v50 )
    {
      msg->m_pDataIn = v49 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v46 = v47;
    }
    else
    {
      if ( v49 <= v50 )
      {
        v51 = *v49;
        msg->m_pDataIn = v49 + 1;
        msg->m_nInBufWord = v51;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v46 = v47;
    }
  }
LABEL_74:
  v3(a1: "MaxPlayers   : %u\n", v46);
  v60 = msg->m_nBitsAvail;
  if ( v60 >= 8 )
  {
    v61 = msg->m_nInBufWord;
    v62 = (unsigned __int8)v61;
    v63 = v60 - 8;
    msg->m_nBitsAvail = v63;
    if ( v63 != 0 )
    {
      v64 = v61 >> 8;
    }
    else
    {
      v65 = msg->m_pDataIn;
      v66 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v65 == v66 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v65 + 1;
        goto LABEL_92;
      }
      if ( v65 > v66 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_92;
      }
      v64 = *v65;
      msg->m_pDataIn = v65 + 1;
    }
    goto LABEL_91;
  }
  v67 = msg->m_pBufferEnd;
  v68 = msg->m_nInBufWord;
  v69 = 8 - v60;
  v70 = msg->m_pDataIn;
  if ( v70 == v67 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
LABEL_87:
    msg->m_pDataIn = v70 + 1;
    goto LABEL_88;
  }
  if ( v70 <= v67 )
  {
    msg->m_nInBufWord = *v70;
    goto LABEL_87;
  }
  msg->m_bOverflow = true;
  msg->m_nInBufWord = 0;
LABEL_88:
  if ( msg->m_bOverflow )
  {
    v62 = 0;
    goto LABEL_92;
  }
  v71 = msg->m_nInBufWord;
  v72 = (v71 & CBitBuffer::s_nMaskTable[v69]) << msg->m_nBitsAvail;
  msg->m_nBitsAvail = 32 - v69;
  v64 = v71 >> v69;
  v62 = v72 | v68;
LABEL_91:
  msg->m_nInBufWord = v64;
LABEL_92:
  _Msg(a1: "Bots         : %u\n", v62);
  v73 = msg->m_nBitsAvail;
  v74 = "???";
  sType = "???";
  if ( v73 < 8 )
  {
    v81 = msg->m_pBufferEnd;
    v82 = msg->m_nInBufWord;
    v83 = 8 - v73;
    v84 = msg->m_pDataIn;
    if ( v84 == v81 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v84 > v81 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
LABEL_106:
        if ( msg->m_bOverflow )
          goto LABEL_115;
        v85 = msg->m_nInBufWord;
        v86 = (v85 & CBitBuffer::s_nMaskTable[v83]) << msg->m_nBitsAvail;
        msg->m_nBitsAvail = 32 - v83;
        v76 = v86 | v82;
        v74 = sType;
        v78 = v85 >> v83;
        goto LABEL_108;
      }
      msg->m_nInBufWord = *v84;
    }
    msg->m_pDataIn = v84 + 1;
    goto LABEL_106;
  }
  v75 = msg->m_nInBufWord;
  v76 = (unsigned __int8)v75;
  v77 = v73 - 8;
  v78 = 0;
  msg->m_nBitsAvail = v77;
  if ( v77 != 0 )
  {
    msg->m_nInBufWord = v75 >> 8;
    goto LABEL_109;
  }
  v79 = msg->m_pDataIn;
  v80 = msg->m_pBufferEnd;
  msg->m_nBitsAvail = 32;
  if ( v79 == v80 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_pDataIn = v79 + 1;
  }
  else if ( v79 <= v80 )
  {
    v78 = *v79;
    msg->m_pDataIn = v79 + 1;
  }
  else
  {
    msg->m_bOverflow = true;
  }
LABEL_108:
  msg->m_nInBufWord = v78;
LABEL_109:
  switch ( v76 )
  {
    case 'd':
      v74 = "dedicated";
      break;
    case 'l':
      v74 = "listen";
      break;
    case 'p':
      v74 = "proxy";
      break;
    default:
      break;
  }
LABEL_115:
  _Msg(a1: "Server Type  : %s\n", v74);
  v87 = msg->m_nBitsAvail;
  v88 = "???";
  sType = "???";
  if ( v87 >= 8 )
  {
    v89 = msg->m_nInBufWord;
    v90 = (unsigned __int8)v89;
    v91 = v87 - 8;
    msg->m_nBitsAvail = v91;
    if ( v91 != 0 )
    {
      msg->m_nInBufWord = v89 >> 8;
      v92 = (unsigned __int8)v89;
    }
    else
    {
      v93 = msg->m_pDataIn;
      v94 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v93 == v94 )
      {
        msg->m_nInBufWord = 0;
        msg->m_nBitsAvail = 1;
        msg->m_pDataIn = v93 + 1;
        v92 = v90;
      }
      else
      {
        if ( v93 <= v94 )
        {
          msg->m_nInBufWord = *v93;
          msg->m_pDataIn = v93 + 1;
        }
        else
        {
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
        }
        v92 = v90;
      }
    }
    goto LABEL_132;
  }
  v95 = msg->m_pBufferEnd;
  v96 = msg->m_nInBufWord;
  v97 = 8 - v87;
  v98 = msg->m_pDataIn;
  if ( v98 == v95 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
LABEL_129:
    msg->m_pDataIn = v98 + 1;
    goto LABEL_130;
  }
  if ( v98 <= v95 )
  {
    msg->m_nInBufWord = *v98;
    goto LABEL_129;
  }
  msg->m_bOverflow = true;
  msg->m_nInBufWord = 0;
LABEL_130:
  if ( !msg->m_bOverflow )
  {
    v99 = msg->m_nInBufWord;
    v100 = (v99 & CBitBuffer::s_nMaskTable[v97]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v97;
    v92 = v100 | v96;
    v88 = sType;
    msg->m_nInBufWord = v99 >> v97;
LABEL_132:
    if ( v92 == 108 )
    {
      v88 = "Linux";
    }
    else if ( v92 == 119 )
    {
      v88 = "Windows";
    }
  }
  _Msg(a1: "OS    Type   : %s\n", v88);
  v101 = msg->m_nBitsAvail;
  if ( v101 >= 8 )
  {
    v102 = msg->m_nInBufWord;
    v103 = (unsigned __int8)v102;
    v104 = v101 - 8;
    msg->m_nBitsAvail = v104;
    if ( v104 != 0 )
    {
      msg->m_nInBufWord = v102 >> 8;
      v105 = (unsigned __int8)v102;
    }
    else
    {
      v106 = msg->m_pDataIn;
      v107 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v106 == v107 )
      {
        msg->m_nInBufWord = 0;
        msg->m_nBitsAvail = 1;
        msg->m_pDataIn = v106 + 1;
        v105 = v103;
      }
      else
      {
        if ( v106 <= v107 )
        {
          msg->m_nInBufWord = *v106;
          msg->m_pDataIn = v106 + 1;
        }
        else
        {
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
        }
        v105 = v103;
      }
    }
LABEL_153:
    v114 = "yes";
    if ( v105 > 0 )
      goto LABEL_155;
    goto LABEL_154;
  }
  v108 = msg->m_pBufferEnd;
  v109 = msg->m_nInBufWord;
  v110 = 8 - v101;
  v111 = msg->m_pDataIn;
  if ( v111 == v108 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v111 > v108 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_151;
    }
    msg->m_nInBufWord = *v111;
  }
  msg->m_pDataIn = v111 + 1;
LABEL_151:
  if ( !msg->m_bOverflow )
  {
    v112 = msg->m_nInBufWord;
    v113 = (v112 & CBitBuffer::s_nMaskTable[v110]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v110;
    v105 = v113 | v109;
    msg->m_nInBufWord = v112 >> v110;
    goto LABEL_153;
  }
LABEL_154:
  v114 = "no";
LABEL_155:
  v115 = (void (*)(const char *, ...))_Msg;
  _Msg(a1: "Password     : %s\n", v114);
  v116 = msg->m_nBitsAvail;
  if ( v116 >= 8 )
  {
    v117 = msg->m_nInBufWord;
    v118 = (unsigned __int8)v117;
    v119 = v116 - 8;
    msg->m_nBitsAvail = v119;
    if ( v119 != 0 )
    {
      msg->m_nInBufWord = v117 >> 8;
      v120 = (unsigned __int8)v117;
    }
    else
    {
      v121 = msg->m_pDataIn;
      v122 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v121 == v122 )
      {
        msg->m_nInBufWord = 0;
        msg->m_nBitsAvail = 1;
        msg->m_pDataIn = v121 + 1;
        v120 = v118;
      }
      else
      {
        if ( v121 <= v122 )
        {
          msg->m_nInBufWord = *v121;
          msg->m_pDataIn = v121 + 1;
        }
        else
        {
          msg->m_nInBufWord = 0;
          msg->m_bOverflow = true;
        }
        v120 = v118;
      }
    }
LABEL_172:
    v129 = "yes";
    if ( v120 > 0 )
      goto LABEL_174;
    goto LABEL_173;
  }
  v123 = msg->m_pBufferEnd;
  v124 = msg->m_nInBufWord;
  v125 = 8 - v116;
  v126 = msg->m_pDataIn;
  if ( v126 == v123 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v126 > v123 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_170;
    }
    msg->m_nInBufWord = *v126;
  }
  msg->m_pDataIn = v126 + 1;
LABEL_170:
  if ( !msg->m_bOverflow )
  {
    v127 = msg->m_nInBufWord;
    v128 = (v127 & CBitBuffer::s_nMaskTable[v125]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v125;
    v120 = v128 | v124;
    v115 = (void (*)(const char *, ...))_Msg;
    msg->m_nInBufWord = v127 >> v125;
    goto LABEL_172;
  }
LABEL_173:
  v129 = "no";
LABEL_174:
  v115(a1: "Secure       : %s\n", v129);
  CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
  v115(a1: "Version      : %s\n", str);
  m_pData = msg->m_pData;
  if ( m_pData != nullptr )
  {
    m_nDataBits = 32 * (msg->m_pDataIn - m_pData) - msg->m_nBitsAvail + 8 * (msg->m_nDataBytes & 3);
    if ( m_nDataBits >= msg->m_nDataBits )
      m_nDataBits = msg->m_nDataBits;
  }
  else
  {
    m_nDataBits = 0;
  }
  if ( msg->m_nDataBits - m_nDataBits >= 0 && ((msg->m_nDataBits - m_nDataBits) & 0xFFFFFFF8) != 0 )
  {
    v132 = msg->m_nBitsAvail;
    if ( v132 >= 8 )
    {
      v133 = msg->m_nInBufWord;
      v134 = (unsigned __int8)v133;
      v135 = v132 - 8;
      msg->m_nBitsAvail = v135;
      if ( v135 != 0 )
      {
        msg->m_nInBufWord = v133 >> 8;
        v136 = (unsigned __int8)v133;
      }
      else
      {
        v137 = msg->m_pDataIn;
        v138 = msg->m_pBufferEnd;
        msg->m_nBitsAvail = 32;
        if ( v137 == v138 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_nInBufWord = 0;
          msg->m_pDataIn = v137 + 1;
          v136 = v134;
        }
        else
        {
          if ( v137 <= v138 )
          {
            msg->m_nInBufWord = *v137;
            msg->m_pDataIn = v137 + 1;
          }
          else
          {
            msg->m_bOverflow = true;
            msg->m_nInBufWord = 0;
          }
          v136 = v134;
        }
      }
LABEL_197:
      sType = (const char *)v136;
      if ( (v136 & 0x80u) == 0 )
        goto LABEL_217;
      v145 = msg->m_nBitsAvail;
      if ( v145 >= 16 )
      {
        v146 = msg->m_nInBufWord;
        v147 = v146;
        v148 = v145 - 16;
        v149 = 0;
        msg->m_nBitsAvail = v148;
        if ( v148 != 0 )
        {
          msg->m_nInBufWord = HIWORD(v146);
LABEL_216:
          _Msg(a1: "Game Port    : %u\n", v147);
LABEL_217:
          if ( (v136 & 0x40) == 0 )
          {
            v169 = (void (*)(const char *, ...))_Msg;
LABEL_238:
            if ( (v136 & 0x20) != 0 )
            {
              CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
              v169(a1: "Public Tags   : %s\n", str);
            }
            return;
          }
          v157 = msg->m_nBitsAvail;
          if ( v157 >= 16 )
          {
            v158 = msg->m_nInBufWord;
            v159 = v158;
            v160 = v157 - 16;
            msg->m_nBitsAvail = v160;
            if ( v160 != 0 )
            {
              msg->m_nInBufWord = HIWORD(v158);
            }
            else
            {
              v158 = (unsigned int)msg->m_pDataIn;
              v161 = msg->m_pBufferEnd;
              msg->m_nBitsAvail = 32;
              if ( (const unsigned int *)v158 == v161 )
              {
                msg->m_pDataIn = (const unsigned int *)(v158 + 4);
                msg->m_nBitsAvail = 1;
                msg->m_nInBufWord = 0;
                LOWORD(v158) = v159;
              }
              else
              {
                if ( v158 <= (unsigned int)v161 )
                {
                  v162 = *(_DWORD *)v158;
                  msg->m_pDataIn = (const unsigned int *)(v158 + 4);
                  msg->m_nInBufWord = v162;
                }
                else
                {
                  msg->m_bOverflow = true;
                  msg->m_nInBufWord = 0;
                }
                LOWORD(v158) = v159;
              }
            }
            goto LABEL_236;
          }
          v163 = msg->m_pBufferEnd;
          v164 = msg->m_nInBufWord;
          v158 = 16 - v157;
          v165 = msg->m_pDataIn;
          if ( v165 == v163 )
          {
            msg->m_nBitsAvail = 1;
            msg->m_nInBufWord = 0;
            msg->m_bOverflow = true;
          }
          else
          {
            if ( v165 > v163 )
            {
              msg->m_bOverflow = true;
              msg->m_nInBufWord = 0;
              goto LABEL_233;
            }
            msg->m_nInBufWord = *v165;
          }
          msg->m_pDataIn = v165 + 1;
LABEL_233:
          if ( msg->m_bOverflow )
          {
            LOWORD(v158) = 0;
          }
          else
          {
            v166 = msg->m_nInBufWord;
            v136 = (v166 & CBitBuffer::s_nMaskTable[v158]) << msg->m_nBitsAvail;
            msg->m_nBitsAvail = 32 - v158;
            v167 = v136 | v164;
            LOBYTE(v136) = (_BYTE)sType;
            v168 = v166 >> v158;
            LOWORD(v158) = v167;
            msg->m_nInBufWord = v168;
          }
LABEL_236:
          v169 = (void (*)(const char *, ...))_Msg;
          _Msg(a1: "Spectator Port: %u\n", (unsigned __int16)v158);
          CBitRead::ReadString(this: msg, pStr: str, maxLen: 1024, bLine: false, pOutNumChars: nullptr);
          _Msg(a1: "SpectatorName : %s\n", str);
          goto LABEL_238;
        }
        v150 = msg->m_pDataIn;
        v151 = msg->m_pBufferEnd;
        msg->m_nBitsAvail = 32;
        if ( v150 == v151 )
        {
          msg->m_nBitsAvail = 1;
          msg->m_pDataIn = v150 + 1;
        }
        else if ( v150 <= v151 )
        {
          v149 = *v150;
          msg->m_pDataIn = v150 + 1;
        }
        else
        {
          msg->m_bOverflow = true;
        }
        goto LABEL_215;
      }
      v152 = msg->m_pBufferEnd;
      v153 = msg->m_nInBufWord;
      v154 = 16 - v145;
      v155 = msg->m_pDataIn;
      if ( v155 == v152 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_bOverflow = true;
      }
      else
      {
        if ( v155 > v152 )
        {
          msg->m_bOverflow = true;
          msg->m_nInBufWord = 0;
LABEL_212:
          if ( msg->m_bOverflow )
          {
            v147 = 0;
            goto LABEL_216;
          }
          v156 = msg->m_nInBufWord;
          v136 = (v156 & CBitBuffer::s_nMaskTable[v154]) << msg->m_nBitsAvail;
          msg->m_nBitsAvail = 32 - v154;
          v147 = v136 | v153;
          LOBYTE(v136) = (_BYTE)sType;
          v149 = v156 >> v154;
LABEL_215:
          msg->m_nInBufWord = v149;
          goto LABEL_216;
        }
        msg->m_nInBufWord = *v155;
      }
      msg->m_pDataIn = v155 + 1;
      goto LABEL_212;
    }
    v139 = msg->m_pBufferEnd;
    v140 = msg->m_nInBufWord;
    v141 = 8 - v132;
    v142 = msg->m_pDataIn;
    if ( v142 == v139 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v142 > v139 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_194;
      }
      msg->m_nInBufWord = *v142;
    }
    msg->m_pDataIn = v142 + 1;
LABEL_194:
    if ( msg->m_bOverflow )
    {
      v136 = 0;
    }
    else
    {
      v143 = msg->m_nInBufWord;
      v144 = (v143 & CBitBuffer::s_nMaskTable[v141]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v141;
      v136 = v140 | v144;
      msg->m_nInBufWord = v143 >> v141;
    }
    goto LABEL_197;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1005F760
// Name: public: virtual bool CBaseClientState::ProcessConnectionlessPacket(struct netpacket_s __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessConnectionlessPacket(CBaseClientState *this, netpacket_s *packet)
{
  bf_read *p_message; // ebx
  int m_nBitsAvail; // ecx
  unsigned int v4; // eax
  int v5; // ecx
  unsigned int v6; // edx
  int v7; // esi
  const unsigned int *v8; // eax
  const unsigned int *v9; // ecx
  const unsigned int *m_pBufferEnd; // edx
  unsigned int m_nInBufWord; // esi
  int v12; // eax
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // edx
  unsigned int v15; // edi
  netadr_s *v17; // eax
  int v18; // ecx
  unsigned int v19; // edx
  int v20; // ecx
  int v21; // eax
  const unsigned int *v22; // eax
  const unsigned int *v23; // ecx
  unsigned int v24; // ecx
  const unsigned int *v25; // edx
  unsigned int v26; // esi
  int v27; // eax
  const unsigned int *v28; // ecx
  unsigned int v29; // edx
  unsigned int v30; // edi
  unsigned int v31; // edx
  CBaseClientState *v32; // esi
  int v33; // ecx
  unsigned int v34; // edx
  int v35; // ecx
  int v36; // eax
  const unsigned int *v37; // eax
  const unsigned int *v38; // ecx
  unsigned int v39; // ecx
  const unsigned int *v40; // edx
  unsigned int v41; // esi
  int v42; // eax
  const unsigned int *v43; // ecx
  unsigned int v44; // edx
  unsigned int v45; // edi
  unsigned int v46; // edx
  int v47; // ecx
  unsigned int v48; // eax
  int v49; // ecx
  __int16 v50; // dx
  __int16 v51; // si
  const unsigned int *v52; // eax
  const unsigned int *v53; // ecx
  const unsigned int *v54; // edx
  unsigned int v55; // esi
  int v56; // eax
  const unsigned int *v57; // ecx
  unsigned int v58; // edx
  unsigned int v59; // edi
  int v60; // ecx
  unsigned int v61; // eax
  int v62; // ecx
  unsigned int v63; // edx
  const unsigned int *v64; // eax
  const unsigned int *v65; // ecx
  unsigned int v66; // ecx
  const unsigned int *v67; // edx
  unsigned int v68; // esi
  int v69; // eax
  const unsigned int *v70; // ecx
  unsigned int v71; // edx
  unsigned int v72; // edi
  unsigned int v73; // edx
  bool v74; // zf
  CBaseClientState *v75; // eax
  int v76; // eax
  int v77; // eax
  const unsigned int *v78; // eax
  const unsigned int *v79; // ecx
  const unsigned int *v80; // edx
  int v81; // ecx
  const unsigned int *v82; // eax
  int v83; // eax
  int v84; // eax
  const unsigned int *v85; // eax
  const unsigned int *v86; // ecx
  const unsigned int *v87; // edx
  int v88; // ecx
  const unsigned int *v89; // eax
  int v90; // eax
  int v91; // eax
  CBaseClientState *v92; // esi
  int v93; // ecx
  unsigned int v94; // edx
  int v95; // ecx
  int v96; // edi
  const unsigned int *v97; // eax
  const unsigned int *v98; // ecx
  int v99; // eax
  const unsigned int *v100; // ecx
  const unsigned int *v101; // edx
  unsigned int v102; // edx
  unsigned int v103; // edi
  int HostVersion; // eax
  int v105; // edi
  int v106; // ecx
  unsigned int v107; // eax
  int v108; // ecx
  unsigned int v109; // edx
  const unsigned int *v110; // eax
  const unsigned int *v111; // ecx
  unsigned int v112; // ecx
  int v113; // eax
  const unsigned int *v114; // ecx
  const unsigned int *v115; // edx
  unsigned int v116; // edx
  unsigned int v117; // edi
  unsigned int v118; // edx
  __int64 LongLong; // rax
  const char *v120; // ecx
  int v121; // ecx
  char *m_pszString; // ecx
  IEngineVGuiInternal *v123; // eax
  char *v124; // edx
  int v125; // eax
  int v126; // eax
  const char *v127; // eax
  int v128; // ecx
  unsigned int v129; // edx
  int v130; // esi
  const unsigned int *v131; // eax
  const unsigned int *v132; // ecx
  const unsigned int *v133; // edx
  unsigned int v134; // esi
  int v135; // eax
  const unsigned int *v136; // ecx
  unsigned int v137; // edx
  unsigned int v138; // edi
  unsigned int v139; // eax
  int v140; // edx
  const unsigned int *v141; // eax
  const unsigned int *v142; // ecx
  KeyValues *v143; // eax
  KeyValues *v144; // esi
  IMatchEventsSubscription *v145; // eax
  const char *v146; // eax
  __int64 v147; // [esp-8h] [ebp-5F0h]
  char string[1200]; // [esp+Ch] [ebp-5DCh] BYREF
  char context[256]; // [esp+4BCh] [ebp-12Ch] BYREF
  bf_read msgOriginal; // [esp+5BCh] [ebp-2Ch]
  netadr_s *adrRemote; // [esp+5E0h] [ebp-8h]
  CBaseClientState *v152; // [esp+5E4h] [ebp-4h]

  p_message = &packet->message;
  v152 = this;
  msgOriginal = packet->message;
  m_nBitsAvail = packet->message.m_nBitsAvail;
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = packet->message.m_pBufferEnd;
    m_nInBufWord = packet->message.m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = packet->message.m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        packet->message.m_bOverflow = true;
        packet->message.m_nInBufWord = 0;
LABEL_15:
        if ( packet->message.m_bOverflow )
        {
          v7 = 0;
          goto LABEL_19;
        }
        v14 = packet->message.m_nInBufWord;
        v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << packet->message.m_nBitsAvail;
        packet->message.m_nBitsAvail = 32 - v12;
        v7 = v15 | m_nInBufWord;
        v6 = v14 >> v12;
        goto LABEL_18;
      }
      packet->message.m_nInBufWord = *m_pDataIn;
    }
    packet->message.m_pDataIn = m_pDataIn + 1;
    goto LABEL_15;
  }
  v4 = packet->message.m_nInBufWord;
  v5 = m_nBitsAvail - 8;
  v6 = 0;
  v7 = (unsigned __int8)v4;
  packet->message.m_nBitsAvail = v5;
  if ( v5 == 0 )
  {
    v8 = packet->message.m_pDataIn;
    v9 = packet->message.m_pBufferEnd;
    packet->message.m_nBitsAvail = 32;
    if ( v8 == v9 )
    {
      packet->message.m_nBitsAvail = 1;
      packet->message.m_nInBufWord = 0;
      packet->message.m_pDataIn = v8 + 1;
      goto LABEL_19;
    }
    if ( v8 <= v9 )
    {
      packet->message.m_nInBufWord = *v8;
      packet->message.m_pDataIn = v8 + 1;
      goto LABEL_19;
    }
    packet->message.m_bOverflow = true;
LABEL_18:
    packet->message.m_nInBufWord = v6;
    goto LABEL_19;
  }
  packet->message.m_nInBufWord = v4 >> 8;
LABEL_19:
  switch ( v7 )
  {
    case 0:
      *p_message = msgOriginal;
      v143 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      if ( v143 != nullptr )
        v144 = KeyValues::KeyValues(this: v143, setName: "OnNetLanConnectionlessPacket");
      else
        v144 = nullptr;
      KeyValues::SetPtr(this: v144, keyName: "rawpkt", value: packet);
      v145 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
      v145->BroadcastEvent(this: v145, a2: v144);
      return 1;
    case 57:
      if ( HIDWORD(v152->m_ListenServerSteamID) != 1 )
        return 1;
      CBitRead::ReadString(this: p_message, pStr: string, maxLen: 1200, bLine: false, pOutNumChars: nullptr);
      COM_ExplainDisconnection(bPrint: true, fmt: string);
      (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v152[-1].m_bRestrictServerCommands + 64))(
        a1: &v152[-1].m_bRestrictServerCommands,
        a2: 1);
      return 1;
    case 65:
      if ( !netadr_s::IsLocalhost(this: &packet->from)
        && !netadr_s::IsLoopback(this: &packet->from)
        && cl_failremoteconnections.m_pParent != nullptr
        && cl_failremoteconnections.m_pParent->m_Value.m_nValue != 0 )
      {
        return 1;
      }
      v17 = (netadr_s *)v152;
      *(&v152->m_bWaitingForServerGameDetails + 2) = false;
      v17 = (netadr_s *)((char *)v17 + 460);
      *v17 = packet->from;
      v18 = packet->message.m_nBitsAvail;
      adrRemote = v17;
      if ( v18 < 32 )
      {
        v25 = packet->message.m_pBufferEnd;
        v26 = packet->message.m_nInBufWord;
        v27 = 32 - v18;
        v28 = packet->message.m_pDataIn;
        if ( v28 == v25 )
        {
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          packet->message.m_bOverflow = true;
        }
        else
        {
          if ( v28 > v25 )
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
            goto LABEL_41;
          }
          packet->message.m_nInBufWord = *v28;
        }
        packet->message.m_pDataIn = v28 + 1;
LABEL_41:
        if ( packet->message.m_bOverflow )
        {
          v21 = 0;
        }
        else
        {
          v29 = packet->message.m_nInBufWord;
          v30 = (v29 & CBitBuffer::s_nMaskTable[v27]) << packet->message.m_nBitsAvail;
          packet->message.m_nBitsAvail = 32 - v27;
          v31 = v29 >> v27;
          v21 = v30 | v26;
          packet->message.m_nInBufWord = v31;
        }
        goto LABEL_44;
      }
      v19 = packet->message.m_nInBufWord;
      v20 = v18 - 32;
      packet->message.m_nBitsAvail = v20;
      if ( v20 != 0 )
      {
        packet->message.m_nInBufWord = 0;
        v21 = v19;
      }
      else
      {
        v22 = packet->message.m_pDataIn;
        v23 = packet->message.m_pBufferEnd;
        packet->message.m_nBitsAvail = 32;
        if ( v22 == v23 )
        {
          packet->message.m_pDataIn = v22 + 1;
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          v21 = v19;
        }
        else
        {
          if ( v22 <= v23 )
          {
            v24 = *v22;
            packet->message.m_pDataIn = v22 + 1;
            packet->message.m_nInBufWord = v24;
          }
          else
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
          }
          v21 = v19;
        }
      }
LABEL_44:
      v32 = v152;
      *(_DWORD *)&v152->m_DeferredConnection.m_chLobbyType[13] = v21;
      v33 = packet->message.m_nBitsAvail;
      if ( v33 >= 32 )
      {
        v34 = packet->message.m_nInBufWord;
        v35 = v33 - 32;
        packet->message.m_nBitsAvail = v35;
        if ( v35 != 0 )
        {
          packet->message.m_nInBufWord = 0;
          v36 = v34;
        }
        else
        {
          v37 = packet->message.m_pDataIn;
          v38 = packet->message.m_pBufferEnd;
          packet->message.m_nBitsAvail = 32;
          if ( v37 == v38 )
          {
            packet->message.m_pDataIn = v37 + 1;
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            v36 = v34;
          }
          else
          {
            if ( v37 <= v38 )
            {
              v39 = *v37;
              packet->message.m_pDataIn = v37 + 1;
              packet->message.m_nInBufWord = v39;
            }
            else
            {
              packet->message.m_bOverflow = true;
              packet->message.m_nInBufWord = 0;
            }
            v36 = v34;
          }
        }
        goto LABEL_63;
      }
      v40 = packet->message.m_pBufferEnd;
      v41 = packet->message.m_nInBufWord;
      v42 = 32 - v33;
      v43 = packet->message.m_pDataIn;
      if ( v43 == v40 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_bOverflow = true;
LABEL_58:
        packet->message.m_pDataIn = v43 + 1;
        goto LABEL_59;
      }
      if ( v43 <= v40 )
      {
        packet->message.m_nInBufWord = *v43;
        goto LABEL_58;
      }
      packet->message.m_bOverflow = true;
      packet->message.m_nInBufWord = 0;
LABEL_59:
      if ( packet->message.m_bOverflow )
      {
        v36 = 0;
      }
      else
      {
        v44 = packet->message.m_nInBufWord;
        v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << packet->message.m_nBitsAvail;
        packet->message.m_nBitsAvail = 32 - v42;
        v46 = v44 >> v42;
        v36 = v45 | v41;
        packet->message.m_nInBufWord = v46;
      }
      v32 = v152;
LABEL_63:
      v32->m_DeferredConnection.m_nChallenge = v36;
      *(&v32->m_DeferredConnection.m_nAuthprotocol + 1) = 0;
      LODWORD(v32->m_DeferredConnection.m_unGSSteamID) = 0;
      *(&v32->m_bWaitingForServerGameDetails + 3) = false;
      if ( v36 == 3 )
      {
        v47 = packet->message.m_nBitsAvail;
        if ( v47 >= 16 )
        {
          v48 = packet->message.m_nInBufWord;
          v49 = v47 - 16;
          v50 = v48;
          packet->message.m_nBitsAvail = v49;
          if ( v49 != 0 )
          {
            packet->message.m_nInBufWord = HIWORD(v48);
            v51 = v48;
          }
          else
          {
            v52 = packet->message.m_pDataIn;
            v53 = packet->message.m_pBufferEnd;
            packet->message.m_nBitsAvail = 32;
            if ( v52 == v53 )
            {
              packet->message.m_nBitsAvail = 1;
              packet->message.m_nInBufWord = 0;
              packet->message.m_pDataIn = v52 + 1;
              v51 = v50;
            }
            else
            {
              if ( v52 <= v53 )
              {
                packet->message.m_nInBufWord = *v52;
                packet->message.m_pDataIn = v52 + 1;
              }
              else
              {
                packet->message.m_bOverflow = true;
                packet->message.m_nInBufWord = 0;
              }
              v51 = v50;
            }
          }
          goto LABEL_81;
        }
        v54 = packet->message.m_pBufferEnd;
        v55 = packet->message.m_nInBufWord;
        v56 = 16 - v47;
        v57 = packet->message.m_pDataIn;
        if ( v57 == v54 )
        {
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          packet->message.m_bOverflow = true;
        }
        else
        {
          if ( v57 > v54 )
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
LABEL_79:
            if ( !packet->message.m_bOverflow )
            {
              v58 = packet->message.m_nInBufWord;
              v59 = (v58 & CBitBuffer::s_nMaskTable[v56]) << packet->message.m_nBitsAvail;
              packet->message.m_nBitsAvail = 32 - v56;
              v51 = v59 | v55;
              packet->message.m_nInBufWord = v58 >> v56;
LABEL_81:
              if ( v51 != 0 )
              {
                _Msg(a1: "Invalid Steam key size.\n");
                (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v152[-1].m_bRestrictServerCommands + 64))(
                  a1: &v152[-1].m_bRestrictServerCommands,
                  a2: 1);
                return 0;
              }
            }
            *(_QWORD *)(&v152->m_DeferredConnection.m_nAuthprotocol + 1) = CBitRead::ReadLongLong(this: p_message);
            v60 = packet->message.m_nBitsAvail;
            if ( v60 >= 8 )
            {
              v61 = packet->message.m_nInBufWord;
              v62 = v60 - 8;
              v63 = (unsigned __int8)v61;
              packet->message.m_nBitsAvail = v62;
              if ( v62 != 0 )
              {
                packet->message.m_nInBufWord = v61 >> 8;
                v61 = (unsigned __int8)v61;
              }
              else
              {
                v64 = packet->message.m_pDataIn;
                v65 = packet->message.m_pBufferEnd;
                packet->message.m_nBitsAvail = 32;
                if ( v64 == v65 )
                {
                  packet->message.m_pDataIn = v64 + 1;
                  packet->message.m_nBitsAvail = 1;
                  packet->message.m_nInBufWord = 0;
                  v61 = v63;
                }
                else
                {
                  if ( v64 <= v65 )
                  {
                    v66 = *v64;
                    packet->message.m_pDataIn = v64 + 1;
                    packet->message.m_nInBufWord = v66;
                  }
                  else
                  {
                    packet->message.m_bOverflow = true;
                    packet->message.m_nInBufWord = 0;
                  }
                  v61 = v63;
                }
              }
              goto LABEL_101;
            }
            v67 = packet->message.m_pBufferEnd;
            v68 = packet->message.m_nInBufWord;
            v69 = 8 - v60;
            v70 = packet->message.m_pDataIn;
            if ( v70 == v67 )
            {
              packet->message.m_nBitsAvail = 1;
              packet->message.m_nInBufWord = 0;
              packet->message.m_bOverflow = true;
            }
            else
            {
              if ( v70 > v67 )
              {
                packet->message.m_bOverflow = true;
                packet->message.m_nInBufWord = 0;
                goto LABEL_98;
              }
              packet->message.m_nInBufWord = *v70;
            }
            packet->message.m_pDataIn = v70 + 1;
LABEL_98:
            if ( packet->message.m_bOverflow )
            {
              v61 = 0;
            }
            else
            {
              v71 = packet->message.m_nInBufWord;
              v72 = (v71 & CBitBuffer::s_nMaskTable[v69]) << packet->message.m_nBitsAvail;
              packet->message.m_nBitsAvail = 32 - v69;
              v73 = v71 >> v69;
              v61 = v72 | v68;
              packet->message.m_nInBufWord = v73;
            }
LABEL_101:
            v74 = v61 == 0;
            v75 = v152;
            *(&v152->m_bWaitingForServerGameDetails + 3) = !v74;
            v32 = v75;
            goto LABEL_134;
          }
          packet->message.m_nInBufWord = *v57;
        }
        packet->message.m_pDataIn = v57 + 1;
        goto LABEL_79;
      }
      v76 = packet->message.m_nBitsAvail;
      if ( v76 >= 16 )
      {
        v77 = v76 - 16;
        packet->message.m_nBitsAvail = v77;
        if ( v77 != 0 )
        {
          packet->message.m_nInBufWord = HIWORD(packet->message.m_nInBufWord);
        }
        else
        {
          v78 = packet->message.m_pDataIn;
          v79 = packet->message.m_pBufferEnd;
          packet->message.m_nBitsAvail = 32;
          if ( v78 == v79 )
          {
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            packet->message.m_pDataIn = v78 + 1;
          }
          else if ( v78 <= v79 )
          {
            packet->message.m_nInBufWord = *v78;
            packet->message.m_pDataIn = v78 + 1;
          }
          else
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
          }
        }
        goto LABEL_118;
      }
      v80 = packet->message.m_pBufferEnd;
      v81 = 16 - v76;
      v82 = packet->message.m_pDataIn;
      if ( v82 == v80 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_bOverflow = true;
      }
      else
      {
        if ( v82 > v80 )
        {
          packet->message.m_bOverflow = true;
          packet->message.m_nInBufWord = 0;
          goto LABEL_116;
        }
        packet->message.m_nInBufWord = *v82;
      }
      packet->message.m_pDataIn = v82 + 1;
LABEL_116:
      if ( !packet->message.m_bOverflow )
      {
        packet->message.m_nInBufWord >>= v81;
        packet->message.m_nBitsAvail = 32 - v81;
      }
LABEL_118:
      CBitRead::ReadLongLong(this: p_message);
      v83 = packet->message.m_nBitsAvail;
      if ( v83 >= 8 )
      {
        v84 = v83 - 8;
        packet->message.m_nBitsAvail = v84;
        if ( v84 != 0 )
        {
          packet->message.m_nInBufWord >>= 8;
        }
        else
        {
          v85 = packet->message.m_pDataIn;
          v86 = packet->message.m_pBufferEnd;
          packet->message.m_nBitsAvail = 32;
          if ( v85 == v86 )
          {
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            packet->message.m_pDataIn = v85 + 1;
          }
          else if ( v85 <= v86 )
          {
            packet->message.m_nInBufWord = *v85;
            packet->message.m_pDataIn = v85 + 1;
          }
          else
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
          }
        }
        goto LABEL_134;
      }
      v87 = packet->message.m_pBufferEnd;
      v88 = 8 - v83;
      v89 = packet->message.m_pDataIn;
      if ( v89 == v87 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_bOverflow = true;
LABEL_131:
        packet->message.m_pDataIn = v89 + 1;
        goto LABEL_132;
      }
      if ( v89 <= v87 )
      {
        packet->message.m_nInBufWord = *v89;
        goto LABEL_131;
      }
      packet->message.m_bOverflow = true;
      packet->message.m_nInBufWord = 0;
LABEL_132:
      if ( packet->message.m_bOverflow )
      {
LABEL_135:
        _Msg(a1: "Invalid challenge packet.\n");
        (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v32[-1].m_bRestrictServerCommands + 64))(
          a1: &v32[-1].m_bRestrictServerCommands,
          a2: 1);
        return 0;
      }
      packet->message.m_nInBufWord >>= v88;
      packet->message.m_nBitsAvail = 32 - v88;
LABEL_134:
      if ( packet->message.m_bOverflow )
        goto LABEL_135;
      memset(context, 0, sizeof(context));
      CBitRead::ReadString(this: p_message, pStr: context, maxLen: 256, bLine: false, pOutNumChars: nullptr);
      v90 = _V_strlen(str: "reserve");
      if ( V_strnicmp(s1: context, s2: "reserve", n: v90) == 0 )
      {
        (*(void (__thiscall **)(bool *, _DWORD))(*(_DWORD *)&v32[-1].m_bRestrictServerCommands + 120))(
          a1: &v32[-1].m_bRestrictServerCommands,
          a2: *(_DWORD *)&v32->m_DeferredConnection.m_chLobbyType[13]);
        return 1;
      }
      v91 = _V_strlen(str: "connect");
      if ( V_strnicmp(s1: context, s2: "connect", n: v91) != 0 )
        return 1;
      v92 = v152;
      if ( HIDWORD(v152->m_ListenServerSteamID) != 1 )
        return 0;
      *(&v152->m_bWaitingForServerGameDetails + 2) = true;
      v93 = packet->message.m_nBitsAvail;
      if ( v93 < 32 )
      {
        v99 = 32 - v93;
        v100 = packet->message.m_pDataIn;
        v152 = (CBaseClientState *)packet->message.m_nInBufWord;
        v101 = packet->message.m_pBufferEnd;
        if ( v100 == v101 )
        {
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          packet->message.m_bOverflow = true;
        }
        else
        {
          if ( v100 > v101 )
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
            goto LABEL_155;
          }
          packet->message.m_nInBufWord = *v100;
        }
        packet->message.m_pDataIn = v100 + 1;
LABEL_155:
        if ( packet->message.m_bOverflow )
        {
          v96 = 0;
        }
        else
        {
          v102 = packet->message.m_nInBufWord;
          v103 = (v102 & CBitBuffer::s_nMaskTable[v99]) << packet->message.m_nBitsAvail;
          packet->message.m_nBitsAvail = 32 - v99;
          v96 = v103 | (unsigned int)v152;
          packet->message.m_nInBufWord = v102 >> v99;
        }
        goto LABEL_158;
      }
      v94 = packet->message.m_nInBufWord;
      v95 = v93 - 32;
      packet->message.m_nBitsAvail = v95;
      if ( v95 != 0 )
      {
        packet->message.m_nInBufWord = 0;
        v96 = v94;
      }
      else
      {
        v97 = packet->message.m_pDataIn;
        v98 = packet->message.m_pBufferEnd;
        packet->message.m_nBitsAvail = 32;
        if ( v97 == v98 )
        {
          packet->message.m_nInBufWord = 0;
          packet->message.m_nBitsAvail = 1;
          packet->message.m_pDataIn = v97 + 1;
          v96 = v94;
        }
        else
        {
          if ( v97 <= v98 )
          {
            packet->message.m_nInBufWord = *v97;
            packet->message.m_pDataIn = v97 + 1;
          }
          else
          {
            packet->message.m_nInBufWord = 0;
            packet->message.m_bOverflow = true;
          }
          v96 = v94;
        }
      }
LABEL_158:
      if ( v96 != GetHostVersion() )
      {
        HostVersion = GetHostVersion();
        _Msg(a1: "Invalid GetHostVersion(), expecting %d, got %d\n", HostVersion, v96);
        (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v92[-1].m_bRestrictServerCommands + 64))(
          a1: &v92[-1].m_bRestrictServerCommands,
          a2: 1);
        return 0;
      }
      v105 = 0;
      CBitRead::ReadString(
        this: p_message,
        pStr: (char *)&v92->m_bWaitingForServerGameDetails + 5,
        maxLen: 15,
        bLine: false,
        pOutNumChars: nullptr);
      v106 = packet->message.m_nBitsAvail;
      if ( v106 < 8 )
      {
        v113 = 8 - v106;
        v114 = packet->message.m_pDataIn;
        v152 = (CBaseClientState *)packet->message.m_nInBufWord;
        v115 = packet->message.m_pBufferEnd;
        if ( v114 == v115 )
        {
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          packet->message.m_bOverflow = true;
        }
        else
        {
          if ( v114 > v115 )
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
            goto LABEL_175;
          }
          packet->message.m_nInBufWord = *v114;
        }
        packet->message.m_pDataIn = v114 + 1;
LABEL_175:
        if ( packet->message.m_bOverflow )
        {
          v107 = 0;
        }
        else
        {
          v116 = packet->message.m_nInBufWord;
          v117 = (v116 & CBitBuffer::s_nMaskTable[v113]) << packet->message.m_nBitsAvail;
          packet->message.m_nBitsAvail = 32 - v113;
          v105 = v117 | (unsigned int)v152;
          v118 = v116 >> v113;
          v107 = v105;
          packet->message.m_nInBufWord = v118;
        }
        goto LABEL_178;
      }
      v107 = packet->message.m_nInBufWord;
      v108 = v106 - 8;
      v109 = (unsigned __int8)v107;
      packet->message.m_nBitsAvail = v108;
      if ( v108 != 0 )
      {
        packet->message.m_nInBufWord = v107 >> 8;
        v107 = (unsigned __int8)v107;
      }
      else
      {
        v110 = packet->message.m_pDataIn;
        v111 = packet->message.m_pBufferEnd;
        packet->message.m_nBitsAvail = 32;
        if ( v110 == v111 )
        {
          packet->message.m_pDataIn = v110 + 1;
          packet->message.m_nBitsAvail = 1;
          packet->message.m_nInBufWord = 0;
          v107 = v109;
        }
        else
        {
          if ( v110 <= v111 )
          {
            v112 = *v110;
            packet->message.m_pDataIn = v110 + 1;
            packet->message.m_nInBufWord = v112;
          }
          else
          {
            packet->message.m_bOverflow = true;
            packet->message.m_nInBufWord = 0;
          }
          v107 = v109;
        }
      }
LABEL_178:
      *(&v92->m_bWaitingForServerGameDetails + 4) = v107 == 1;
      LongLong = CBitRead::ReadLongLong(this: p_message);
      v74 = !*(&v92->m_bWaitingForServerGameDetails + 4);
      *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) = LongLong;
      v120 = "yes";
      if ( v74 )
        v120 = "no";
      LODWORD(LongLong) = &v92->m_bWaitingForServerGameDetails + 5;
      if ( !*(&v92->m_bWaitingForServerGameDetails + 5) )
        LODWORD(LongLong) = "<none>";
      HIDWORD(v147) = HIDWORD(LongLong);
      LODWORD(v147) = HIDWORD(v92->m_DeferredConnection.m_unGSSteamID);
      _Msg(a1: "Server using '%s' lobbies, requiring pw %s, lobby id %llx\n", (const char *)LongLong, v120, v147);
      CBaseClientState::RememberIPAddressForLobby(
        this: (CBaseClientState *)((char *)v92 - 4),
        unLobbyID: *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4),
        adrRemote);
      if ( *(&v92->m_bWaitingForServerGameDetails + 5) )
      {
        if ( sv.m_State < ss_active
          && *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) == 0
          && *(_QWORD *)&v92->m_pServerReservationCallback != 0 )
        {
          _Warning(a1: "Server error - failed to handle reservation request.\n");
          (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v92[-1].m_bRestrictServerCommands + 64))(
            a1: &v92[-1].m_bRestrictServerCommands,
            a2: 1);
          return 0;
        }
LABEL_199:
        v125 = _V_strlen(str: "connect-retry");
        if ( V_strnicmp(s1: context, s2: "connect-retry", n: v125) == 0
          && *(&v92->m_bWaitingForServerGameDetails + 5)
          && sv.m_State < ss_active
          && *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) == 0 )
        {
          _Msg(a1: "Grace request retry for unreserved server...\n");
          (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v92[-1].m_bRestrictServerCommands + 80))(
            a1: &v92[-1].m_bRestrictServerCommands,
            a2: 1);
          return 1;
        }
        v126 = _V_strlen(str: "connect-granted");
        if ( V_strnicmp(s1: context, s2: "connect-granted", n: v126) != 0 )
        {
          if ( !*(&v92->m_bWaitingForServerGameDetails + 5) )
          {
LABEL_213:
            CBaseClientState::HandleDeferredConnection(this: (CBaseClientState *)((char *)v92 - 4), a2: v105);
            return 1;
          }
          if ( sv.m_State < ss_active
            && *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) == 0 )
          {
            _Msg(a1: "Server did not approve grace request, retrying...\n");
            (*(void (__thiscall **)(bool *, int))(*(_DWORD *)&v92[-1].m_bRestrictServerCommands + 80))(
              a1: &v92[-1].m_bRestrictServerCommands,
              a2: 1);
            return 1;
          }
        }
        if ( *(&v92->m_bWaitingForServerGameDetails + 5)
          && sv.m_State < ss_active
          && *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) == 0 )
        {
          _Msg(a1: "Server approved grace request...\n");
        }
        goto LABEL_213;
      }
      v121 = LODWORD(v92->m_DeferredConnection.m_unLobbyID) | HIDWORD(v92->m_DeferredConnection.m_unGSSteamID);
      if ( *(unsigned __int64 *)((char *)&v92->m_DeferredConnection.m_unGSSteamID + 4) != 0 )
        goto LABEL_199;
      if ( *(&v92->m_bWaitingForServerGameDetails + 4) == (_BYTE)v121 )
        goto LABEL_199;
      if ( LOBYTE(v92->m_netadrReserveServer.m_List.m_pElements) != (_BYTE)v121 )
      {
        if ( (password.m_nFlags & 0x1000) != 0 )
          goto LABEL_199;
        m_pszString = password.m_pParent->m_Value.m_pszString;
        if ( m_pszString != nullptr && *m_pszString != 0 )
          goto LABEL_199;
      }
      BYTE1(v92->m_netadrReserveServer.m_List.m_pElements) = 1;
      SCR_EndLoadingPlaque();
      v123 = EngineVGui();
      if ( (password.m_nFlags & 0x1000) != 0 )
      {
        v123->ShowPasswordUI(this: v123, a2: "FCVAR_NEVER_AS_STRING");
        return 1;
      }
      else
      {
        v124 = password.m_pParent->m_Value.m_pszString;
        if ( v124 == nullptr )
          v124 = (char *)defaultValue;
        v123->ShowPasswordUI(this: v123, a2: v124);
        return 1;
      }
    case 66:
      if ( HIDWORD(v152->m_ListenServerSteamID) != 1 )
        return 1;
      (*(void (__thiscall **)(bool *, netpacket_s *))(*(_DWORD *)&v152[-1].m_bRestrictServerCommands + 48))(
        a1: &v152[-1].m_bRestrictServerCommands,
        a2: packet);
      return 1;
    case 73:
      Read_S2A_INFO_SRC(from: &packet->from, msg: p_message);
      return 1;
    case 105:
      NET_OutOfBandPrintf(
        sock: (int)v152->IServerMessageHandler::INetMessageHandler::__vftable,
        adr: &packet->from,
        format: "%c00000000000000",
        106);
      return 1;
    case 106:
      v127 = netadr_s::ToString(this: &packet->from, baseOnly: false);
      ConMsg(a1: "A2A_ACK from %s\n", v127);
      return 1;
    case 108:
      if ( !CBitRead::ReadString(this: p_message, pStr: string, maxLen: 1200, bLine: false, pOutNumChars: nullptr) )
        return 1;
      ConMsg(a1: "%s\n", string);
      return 1;
    case 112:
      v128 = packet->message.m_nBitsAvail;
      if ( v128 >= 32 )
      {
        v129 = packet->message.m_nInBufWord;
        packet->message.m_nBitsAvail = v128 - 32;
        if ( v128 == 32 )
        {
          v131 = packet->message.m_pDataIn;
          v132 = packet->message.m_pBufferEnd;
          packet->message.m_nBitsAvail = 32;
          if ( v131 == v132 )
          {
            packet->message.m_nInBufWord = 0;
            packet->message.m_nBitsAvail = 1;
            packet->message.m_pDataIn = v131 + 1;
            v130 = v129;
          }
          else
          {
            if ( v131 <= v132 )
            {
              packet->message.m_nInBufWord = *v131;
              packet->message.m_pDataIn = v131 + 1;
            }
            else
            {
              packet->message.m_nInBufWord = 0;
              packet->message.m_bOverflow = true;
            }
            v130 = v129;
          }
        }
        else
        {
          packet->message.m_nInBufWord = 0;
          v130 = v129;
        }
LABEL_238:
        if ( v130 == GetHostVersion() )
        {
          v139 = packet->message.m_nInBufWord;
          v140 = v139 & 1;
          v74 = packet->message.m_nBitsAvail-- == 1;
          if ( v74 )
          {
            v141 = packet->message.m_pDataIn;
            v142 = packet->message.m_pBufferEnd;
            packet->message.m_nBitsAvail = 32;
            if ( v141 == v142 )
            {
              packet->message.m_nBitsAvail = 1;
              packet->message.m_nInBufWord = 0;
              packet->message.m_pDataIn = v141 + 1;
            }
            else if ( v141 <= v142 )
            {
              packet->message.m_nInBufWord = *v141;
              packet->message.m_pDataIn = v141 + 1;
            }
            else
            {
              packet->message.m_bOverflow = true;
              packet->message.m_nInBufWord = 0;
            }
          }
          else
          {
            packet->message.m_nInBufWord = v139 >> 1;
          }
          (*(void (__thiscall **)(bool *, netpacket_s *, bool))(*(_DWORD *)&v152[-1].m_bRestrictServerCommands + 116))(
            a1: &v152[-1].m_bRestrictServerCommands,
            a2: packet,
            a3: v140 != 0);
        }
        return 1;
      }
      v133 = packet->message.m_pBufferEnd;
      v134 = packet->message.m_nInBufWord;
      v135 = 32 - v128;
      v136 = packet->message.m_pDataIn;
      if ( v136 == v133 )
      {
        packet->message.m_nBitsAvail = 1;
        packet->message.m_nInBufWord = 0;
        packet->message.m_bOverflow = true;
      }
      else
      {
        if ( v136 > v133 )
        {
          packet->message.m_bOverflow = true;
          packet->message.m_nInBufWord = 0;
          goto LABEL_235;
        }
        packet->message.m_nInBufWord = *v136;
      }
      packet->message.m_pDataIn = v136 + 1;
LABEL_235:
      if ( packet->message.m_bOverflow )
      {
        v130 = 0;
      }
      else
      {
        v137 = packet->message.m_nInBufWord;
        v138 = (v137 & CBitBuffer::s_nMaskTable[v135]) << packet->message.m_nBitsAvail;
        packet->message.m_nBitsAvail = 32 - v135;
        v130 = v138 | v134;
        packet->message.m_nInBufWord = v137 >> v135;
      }
      goto LABEL_238;
    case 116:
      return 1;
    default:
      v146 = netadr_s::ToString(this: &packet->from, baseOnly: false);
      _ConDMsg(a1: "Bad connectionless packet ( CL '%c') from %s.\n", v7, v146);
      return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060700
// Name: public: virtual void CBaseClientState::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CBaseClientState::OnEvent(CBaseClientState *this@<ecx>, int a2@<ebx>, KeyValues *pEvent)
{
  const char *Name; // eax
  KeyValues *Key; // eax
  const char *String; // eax
  int v7; // edi
  int i; // ebx
  const char *v9; // eax
  Remote_t *v10; // edi
  const char *v11; // eax
  KeyValues *v12; // eax
  KeyValues *v13; // edi
  KeyValues *v14; // eax
  KeyValues *v15; // esi
  IMatchEventsSubscription *v16; // eax
  const char *v17; // [esp-8h] [ebp-14h]
  KeyValues *pGameDetailsServer; // [esp+8h] [ebp-4h]
  const char *szDetailsAdr; // [esp+14h] [ebp+8h]

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: "OnNetLanConnectionlessPacket", s2: Name) == 0 )
  {
    Key = KeyValues::FindKey(this: pEvent, keyName: "GameDetailsServer", bCreate: false);
    pGameDetailsServer = Key;
    if ( Key != nullptr )
    {
      String = KeyValues::GetString(
                 this: Key,
                 keyName: "ConnectServerDetailsRequest/server",
                 defaultValue: defaultValue);
      szDetailsAdr = String;
      if ( this->m_bWaitingForServerGameDetails && String != nullptr && *String != 0 )
      {
        v7 = 0;
        if ( this->m_Remote.m_List.m_Size > 0 )
        {
          for ( i = 0; ; ++i )
          {
            v17 = String;
            v9 = netadr_s::ToString(this: &this->m_Remote.m_List.m_Memory.m_pMemory[i].m_adrRemote, baseOnly: false);
            if ( _V_stricmp(s1: v9, s2: v17) == 0 )
              break;
            if ( ++v7 >= this->m_Remote.m_List.m_Size )
              return;
            String = szDetailsAdr;
          }
          if ( v7 >= 0 )
          {
            v10 = &this->m_Remote.m_List.m_Memory.m_pMemory[v7];
            this->m_bWaitingForServerGameDetails = false;
            v11 = CUtlString::operator char const *(this: &v10->m_szRetryAddress);
            _Msg(a1: "Received game details information from %s...\n", v11);
            ((void (__thiscall *)(CBaseClientState *, int, int))this->Disconnect)(a1: this, a2: 1, a3: a2);
            KeyValues::SetName(this: pGameDetailsServer, setName: "settings");
            v12 = KeyValues::FindKey(this: pGameDetailsServer, keyName: "ConnectServerDetailsRequest", bCreate: false);
            v13 = v12;
            if ( v12 != nullptr )
            {
              KeyValues::RemoveSubKey(this: pGameDetailsServer, subKey: v12);
              KeyValues::deleteThis(this: v13);
            }
            this->Disconnect(this, a2: true);
            v14 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
            if ( v14 != nullptr )
              v15 = KeyValues::KeyValues(
                      this: v14,
                      setName: "OnEngineLevelLoadingSession",
                      firstKey: "reason",
                      firstValue: "CreateSession");
            else
              v15 = nullptr;
            v16 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
            v16->BroadcastEvent(this: v16, a2: v15);
            g_pMatchFramework->CreateSession(this: g_pMatchFramework, a2: pGameDetailsServer);
          }
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060880
// Name: public: void CBaseClientState::SetConnectionPassword(char const __near *)
// Source: json
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void __thiscall CBaseClientState::SetConnectionPassword(CBaseClientState *this, const char *pchCurrentPW)
{
  const char *v3; // eax

  if ( pchCurrentPW != nullptr && *pchCurrentPW != 0 )
  {
    SCR_BeginLoadingPlaque(levelName: nullptr);
    *(_WORD *)&this->m_bEnteredPassword = 1;
    CLoaderMemAlloc::CrtSetReportMode(this: (ConVar *)&password.IConVar, value: pchCurrentPW);
    CBaseClientState::HandleDeferredConnection(this, a2: (int)pchCurrentPW);
  }
  else
  {
    *(_WORD *)&this->m_bEnteredPassword = 0;
    v3 = netadr_s::ToString(this: &this->m_DeferredConnection.m_adrServerAddress, baseOnly: false);
    _Msg(a1: "Connection to %s failed, server requires a password\n", v3);
    this->Disconnect(this, a2: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060900
// Name: public: void CBaseClientState::SendStringCmd(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SendStringCmd(CBaseClientState *this, char *command)
{
  INetChannel *m_NetChannel; // ecx
  int v4; // eax
  NET_StringCmd stringCmd; // [esp+4h] [ebp-414h] BYREF

  if ( this->m_NetChannel != nullptr )
  {
    m_NetChannel = this->m_NetChannel;
    stringCmd.m_bReliable = true;
    stringCmd.m_NetChannel = nullptr;
    stringCmd.__vftable = (NET_StringCmd_vtbl *)&NET_StringCmd::`vftable';
    stringCmd.m_szCommand = command;
    m_NetChannel->SendNetMsg(this: m_NetChannel, a2: &stringCmd, a3: false, a4: false);
    strstr(str1: (unsigned __int8 *)command, str2: "disconnect");
    if ( v4 != 0 )
      this->m_NetChannel->Transmit(this: this->m_NetChannel, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10060980
// Name: public: virtual bool CBaseClientState::ProcessStringCmd(class NET_StringCmd __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessStringCmd(CBaseClientState *this, NET_StringCmd *msg)
{
  return CBaseClientState::InternalProcessStringCmd(this: (CBaseClientState *)((char *)this - 8), msg, bIsHLTV: false);
}

//------------------------------------------------------------------------------
// Address: 0x100609A0
// Name: public: virtual bool CBaseClientState::ProcessSetConVar(class NET_SetConVar __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessSetConVar(CBaseClientState *this, NET_SetConVar *msg)
{
  NetMessageCvar_t *v3; // esi
  ConVarRef var; // [esp+0h] [ebp-Ch] BYREF
  int i; // [esp+8h] [ebp-4h]
  NET_SetConVar *msga; // [esp+14h] [ebp+8h]

  if ( (*((unsigned __int8 (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 6))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable) == 0 )
  {
    i = 0;
    if ( msg->m_ConVars.m_Size > 0 )
    {
      msga = nullptr;
      do
      {
        v3 = (NetMessageCvar_t *)((char *)msga + (unsigned int)msg->m_ConVars.m_Memory.m_pMemory);
        ConVarRef::ConVarRef(this: &var, pName: v3->name);
        if ( ConVarRef::IsValid(this: &var) )
        {
          if ( var.m_pConVar->IsFlagSet(this: var.m_pConVar, a2: 0x2000) )
          {
            if ( sv.m_State < ss_active )
            {
              var.m_pConVar->SetValue_4(this: var.m_pConVar, a2: v3->value);
              DevMsg(a1: "SetConVar: %s = \"%s\"\n", v3->name, v3->value);
            }
          }
          else
          {
            ConMsg(
              a1: "SetConVar: Can't set server cvar %s to %s, not marked as FCVAR_REPLICATED on client\n",
              v3->name,
              v3->value);
          }
        }
        else
        {
          ConMsg(a1: "SetConVar: No such cvar ( %s set to %s), skipping\n", v3->name, v3->value);
        }
        msga = (NET_SetConVar *)((char *)msga + 520);
        ++i;
      }
      while ( i < msg->m_ConVars.m_Size );
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10060A70
// Name: public: virtual bool CBaseClientState::ProcessServerInfo(class SVC_ServerInfo __near *)
// Source: json
//------------------------------------------------------------------------------
char __userpurge CBaseClientState::ProcessServerInfo@<al>(
        CBaseClientState *this@<ecx>,
        int a2@<esi>,
        SVC_ServerInfo *msg)
{
  IEngineVGuiInternal *v4; // eax
  int HostVersion; // eax
  int v8; // eax
  int v9; // eax
  netadr_s *v10; // eax
  double m_fTickInterval; // st7
  double v12; // st5
  IEngineVGuiInternal *v13; // eax
  vgui::PropertyPage *v14; // ecx
  IGameEvent *v15; // esi
  netadr_s *v16; // eax
  netadr_s *v17; // eax
  unsigned __int16 Port; // ax
  char *v19; // eax
  char *v20; // eax
  KeyValues *v21; // eax
  IMatchEventsSubscription *v22; // eax
  PackedEntity *m_nMaxClasses; // [esp+34h] [ebp-118h]
  const char *v24; // [esp+34h] [ebp-118h]
  char bspModelName[260]; // [esp+40h] [ebp-10Ch] BYREF
  ConVarRef skyname; // [esp+144h] [ebp-8h] BYREF
  SVC_ServerInfo *msga; // [esp+154h] [ebp+8h]
  SVC_ServerInfo *msgb; // [esp+154h] [ebp+8h]
  SVC_ServerInfo *msgc; // [esp+154h] [ebp+8h]

  v4 = EngineVGui();
  v4->UpdateProgressBar(this: v4, a2: PROGRESS_PROCESSSERVERINFO, a3: true);
  _COM_TimestampedLog(a1: " CBaseClient::ProcessServerInfo");
  if ( msg->m_nProtocol != GetHostVersion() )
  {
    HostVersion = GetHostVersion();
    ConMsg(a1: "Server returned version %i, expected %i.\n", msg->m_nProtocol, HostVersion);
    return 0;
  }
  LODWORD(this->m_flNextCmdTime) = msg->m_nServerCount;
  *(_DWORD *)&this->m_szLastLevelNameShort[32] = msg->m_nMaxClients;
  m_nMaxClasses = (PackedEntity *)msg->m_nMaxClasses;
  this->m_pEntityBaselines[1][2047] = m_nMaxClasses;
  this->m_pServerClasses = (C_ServerClassInfo *)(Q_log2(val: (unsigned int)m_nMaxClasses) + 1);
  v8 = *(_DWORD *)&this->m_szLastLevelNameShort[32];
  if ( v8 < 1 || v8 > 64 )
  {
    ConMsg(a1: "Bad maxclients (%u) from server.\n", *(_DWORD *)&this->m_szLastLevelNameShort[32]);
    return 0;
  }
  v9 = (int)this->m_pEntityBaselines[1][2047];
  if ( v9 < 1 || v9 > 512 )
  {
    ConMsg(a1: "Bad maxclasses (%u) from server.\n", this->m_pEntityBaselines[1][2047]);
    return 0;
  }
  if ( sv.m_State < ss_active
    && (*((unsigned __int8 (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 6))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable) == 0
    && (*((unsigned __int8 (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 65))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable) == 0 )
  {
    v10 = (netadr_s *)(*((int (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 49))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable);
    if ( !netadr_s::IsLocalhost(this: v10) )
    {
      g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x2000);
      g_pCVar->RevertFlaggedConVars(this: g_pCVar, a2: 0x4000);
      DevMsg(a1: "FCVAR_CHEAT cvars reverted to defaults.\n");
    }
  }
  CBaseClientState::FreeEntityBaselines(this: (CBaseClientState *)((char *)this - 8));
  CGameEventManager::HasClientListenersChanged(this: g_GameEventManager, bReset: true);
  splitscreen->AddBaseUser(this: splitscreen, a2: 0, a3: msg->m_nPlayerSlot + 1);
  g_pScaleformUI->InitSlot(this: g_pScaleformUI, a2: 2, a3: g_szDefaultScaleformClientMovieName);
  *(_DWORD *)&this->m_bPaused = msg->m_nPlayerSlot;
  this->m_nDeltaTick = msg->m_nPlayerSlot + 1;
  m_fTickInterval = msg->m_fTickInterval;
  v12 = 0.1;
  if ( m_fTickInterval < 0.001 )
  {
LABEL_29:
    ConMsg(a1: "Interval_per_tick %f out of range [%f to %f]\n", m_fTickInterval, 0.001, v12);
    return 0;
  }
  if ( msg->m_fTickInterval > 0.1 )
  {
    v12 = 0.1;
    m_fTickInterval = msg->m_fTickInterval;
    goto LABEL_29;
  }
  if ( !COM_CheckGameDirectory(gamedir: msg->m_szGameDir) )
    return 0;
  V_snprintf(pDest: (char *)&this->m_nPlayerSlot, maxLen: 40, pFormat: "maps/%s%s.bsp", msg->m_szMapName, defaultValue);
  V_strncpy(pDest: &this->m_szLevelName[32], pSrc: msg->m_szMapName, maxLen: 40);
  v13 = EngineVGui();
  ((void (__thiscall *)(IEngineVGuiInternal *, char *, int))v13->SetProgressLevelName)(
    a1: v13,
    a2: &this->m_szLevelName[32],
    a3: a2);
  audiosourcecache->LevelInit(this: audiosourcecache, a2: &this->m_szLevelName[32]);
  ConVarRef::ConVarRef(this: &skyname, pName: "sv_skyname");
  if ( ConVarRef::IsValid(this: &skyname) )
    skyname.m_pConVar->SetValue_4(this: skyname.m_pConVar, a2: msg->m_szSkyName);
  this->m_ClockDriftMgr.m_nServerTick = -1;
  v24 = nullptr;
  v15 = (IGameEvent *)((int (__thiscall *)(CGameEventManager *, const char *, _DWORD))g_GameEventManager->CreateEventA)(
                        a1: g_GameEventManager,
                        a2: "server_spawn",
                        a3: 0);
  if ( v15 != nullptr )
  {
    v15->SetString(this: v15, a2: "hostname", a3: msg->m_szHostName);
    msga = (SVC_ServerInfo *)v15->__vftable;
    v16 = (netadr_s *)(*((int (__thiscall **)(IServerMessageHandler_vtbl *, int))this->dtr_INetMessageHandler + 49))(
                        a1: this->IServerMessageHandler::INetMessageHandler::__vftable,
                        a2: 1);
    v24 = netadr_s::ToString(this: v16, baseOnly: false);
    ((void (__thiscall *)(IGameEvent *, const char *))msga->m_szGameDir)(a1: v15, a2: "address");
    msgb = (SVC_ServerInfo *)v15->__vftable;
    v17 = (netadr_s *)(*((int (__thiscall **)(IServerMessageHandler_vtbl *))this->dtr_INetMessageHandler + 49))(a1: this->IServerMessageHandler::INetMessageHandler::__vftable);
    Port = netadr_s::GetPort(this: v17);
    ((void (__thiscall *)(IGameEvent *, const char *, _DWORD))msgb->m_nMaxClasses)(a1: v15, a2: "port", a3: Port);
    v15->SetString(this: v15, a2: "game", a3: msg->m_szGameDir);
    v15->SetString(this: v15, a2: "mapname", a3: msg->m_szMapName);
    v15->SetInt(this: v15, a2: "maxplayers", a3: msg->m_nMaxClients);
    v15->SetInt(this: v15, a2: "password", a3: 0);
    msgc = (SVC_ServerInfo *)v15->__vftable;
    v19 = va(format: "%c", msg->m_cOS);
    v20 = _V_strupr(start: v19);
    ((void (__thiscall *)(IGameEvent *, const char *, char *))msgc->m_szGameDir)(a1: v15, a2: "os", a3: v20);
    v15->SetBool(this: v15, a2: "dedicated", a3: msg->m_bIsDedicated);
    g_GameEventManager->FireEventClientSide(this: g_GameEventManager, a2: v15);
  }
  BYTE2(this->m_iEncryptionKeySize) = 1;
  if ( sv.m_State < ss_active )
  {
    CColorBalanceUIPanel::Init(this: v14);
    SV_FlushMemoryIfMarked();
    HostState_Pre_LoadMapIntoMemory();
    V_FileBase(
      in: com_gamedir,
      out: (char *)&`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc,
      maxlen: 260);
    if ( _V_stricmp(
           s1: (const char *)&`CUtlRBTree<ccpair,int,bool (__cdecl *)(ccpair const &,ccpair const &),CUtlMemory<UtlRBTreeNode_t<ccpair,int>,int>>::Links'::`2'::s_Sentinel.m_LastAlloc,
           s2: "infested") != 0 )
    {
      V_snprintf(pDest: bspModelName, maxLen: 260, pFormat: "maps/%s.bsp", msg->m_szMapName);
      modelloader->GetModelForName(this: modelloader, a2: bspModelName, a3: FMODELLOADER_CLIENT);
    }
    if ( ((int (__thiscall *)(INetworkStringTableDictionaryMananger *, const char *, unsigned int *, const char *))g_pStringTableDictionary->OnLevelLoadStart)(
           a1: g_pStringTableDictionary,
           a2: msg->m_szMapName,
           a3: &msg->m_nStringTableCRC,
           a4: v24) == 0 )
      _Warning(a1: "***String table CRC mismatch, may need to rebuild bsp if model oddities occur!\n");
    v21 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v21 != nullptr )
      KeyValues::KeyValues(
        this: v21,
        setName: "OnProfilesWriteOpportunity",
        firstKey: "reason",
        firstValue: "checkpoint");
    v22 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    ((void (__thiscall *)(IMatchEventsSubscription *))v22->BroadcastEvent)(a1: v22);
  }
  _COM_TimestampedLog(a1: "CBaseClient::ProcessServerInfo(done)");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10060F30
// Name: public: virtual bool CBaseClientState::ProcessClassInfo(class SVC_ClassInfo __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CBaseClientState::ProcessClassInfo(CBaseClientState *this, SVC_ClassInfo *msg)
{
  CBaseClientState *v2; // esi
  PackedEntity *v4; // ecx
  void *v5; // edx
  int v6; // ebx
  void **v7; // edi
  void *v8; // ecx
  int m_Size; // edi
  int v10; // ecx
  int *v11; // eax
  int v12; // edi
  PackedEntity *v13; // ebx
  _DWORD *v14; // eax
  PackedEntity *v15; // eax
  SVC_ClassInfo::class_s *v16; // edi
  int v17; // ebx
  int v18; // esi
  char *v19; // eax
  const char *datatablename; // edi
  int v21; // esi
  char *v22; // eax
  int i; // [esp+4h] [ebp-Ch]
  int ia; // [esp+4h] [ebp-Ch]
  int v26; // [esp+Ch] [ebp-4h]

  v2 = this;
  _COM_TimestampedLog(a1: " CBaseClient::ProcessClassInfo");
  if ( msg->m_bCreateOnClient )
  {
    ConMsg(a1: "Can't create class tables.\n");
    return false;
  }
  else
  {
    v4 = v2->m_pEntityBaselines[1][2046];
    if ( v4 != nullptr )
    {
      v5 = (char *)&v4[-1] + 48;
      v6 = *((_DWORD *)&v4[-1] + 12) - 1;
      i = (int)&v4[-1] + 48;
      if ( v6 >= 0 )
      {
        v7 = (void **)(&v4->m_nEntityIndex + 4 * *((_DWORD *)&v4[-1] + 12));
        do
        {
          v8 = *(v7 - 5);
          v7 -= 4;
          free(pMem: v8);
          free(pMem: *v7);
          --v6;
        }
        while ( v6 >= 0 );
        v5 = (void *)i;
      }
      free(pMem: v5);
    }
    m_Size = msg->m_Classes.m_Size;
    v10 = (unsigned __int64)(unsigned int)m_Size >> 28 != 0;
    v2->m_pEntityBaselines[1][2047] = (PackedEntity *)m_Size;
    v11 = (int *)MemAlloc_Alloc(nSize: __CFADD__((16 * m_Size) | -v10, 4) ? -1 : ((16 * m_Size) | -v10) + 4);
    if ( v11 != nullptr )
    {
      *v11 = m_Size;
      v12 = m_Size - 1;
      v13 = (PackedEntity *)(v11 + 1);
      if ( v12 >= 0 )
      {
        v14 = v11 + 3;
        do
        {
          *(v14 - 1) = 0;
          *v14 = 0;
          v14[1] = 0xFFFF;
          v14 += 4;
          --v12;
        }
        while ( v12 >= 0 );
      }
      v15 = v13;
    }
    else
    {
      v15 = nullptr;
    }
    v2->m_pEntityBaselines[1][2046] = v15;
    if ( v15 != nullptr )
    {
      ia = 0;
      if ( (int)v2->m_pEntityBaselines[1][2047] <= 0 )
      {
LABEL_21:
        _COM_TimestampedLog(a1: " CBaseClient::ProcessClassInfo(done)");
        return ((int (__thiscall *)(CNetworkStringTableContainer **))v2[-1].m_StringTableContainer[2].m_Tables.m_Size)(a1: &v2[-1].m_StringTableContainer);
      }
      else
      {
        v26 = 0;
        while ( 1 )
        {
          v16 = &msg->m_Classes.m_Memory.m_pMemory[v26];
          if ( v16->classID >= (int)v2->m_pEntityBaselines[1][2047] )
            break;
          v17 = (int)v2->m_pEntityBaselines[1][2046] + 16 * v16->classID;
          v18 = _V_strlen(str: v16->classname) + 1;
          v19 = (char *)MemAlloc_Alloc(nSize: v18);
          *(_DWORD *)(v17 + 4) = v19;
          V_strncpy(pDest: v19, pSrc: v16->classname, maxLen: v18);
          datatablename = v16->datatablename;
          v21 = _V_strlen(str: datatablename) + 1;
          v22 = (char *)MemAlloc_Alloc(nSize: v21);
          *(_DWORD *)(v17 + 8) = v22;
          V_strncpy(pDest: v22, pSrc: datatablename, maxLen: v21);
          ++v26;
          ++ia;
          v2 = this;
          if ( ia >= (int)this->m_pEntityBaselines[1][2047] )
            goto LABEL_21;
        }
        Host_EndGame(bShowMainMenu: true, message: "ProcessClassInfo: invalid class index (%d).\n", v16->classID);
        return false;
      }
    }
    else
    {
      Host_EndGame(
        bShowMainMenu: true,
        message: "ProcessClassInfo: can't allocate %d C_ServerClassInfos.\n",
        v2->m_pEntityBaselines[1][2047]);
      return false;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061120
// Name: public: virtual char const __near * CLC_RespondCvarValue::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_RespondCvarValue::GetName(CLC_RespondCvarValue *this)
{
  return "clc_RespondCvarValue";
}

//------------------------------------------------------------------------------
// Address: 0x10061130
// Name: public: virtual unsigned int CLC_RespondCvarValue::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLC_RespondCvarValue::GetSize(CLC_RespondCvarValue *this)
{
  return 544;
}

//------------------------------------------------------------------------------
// Address: 0x10061150
// Name: private: void CBaseClientState::SendReserveServerChallenge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SendReserveServerChallenge(CBaseClientState *this)
{
  int v2; // edi
  int v3; // ebx
  unsigned int PrivateIPDelayMsecs; // eax

  v2 = 0;
  if ( this->m_netadrReserveServer.m_List.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      PrivateIPDelayMsecs = GetPrivateIPDelayMsecs();
      NET_OutOfBandDelayedPrintf(
        sock: this->m_Socket,
        adr: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory[v3].m_adrRemote,
        unMillisecondsDelay: v2 * PrivateIPDelayMsecs,
        format: "%creserve0000000",
        113);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_netadrReserveServer.m_List.m_Size );
  }
  this->m_flReservationMsgSendTime = net_time;
}

//------------------------------------------------------------------------------
// Address: 0x100611B0
// Name: public: bool CAddressList::IsRemoteInList(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAddressList::IsRemoteInList(CAddressList *this, const char *pchAdrCheck)
{
  int v3; // ebx
  int i; // edi
  const char *v5; // eax

  v3 = 0;
  if ( this->m_List.m_Size <= 0 )
    return 0;
  for ( i = 0; ; ++i )
  {
    v5 = CUtlString::operator char const *(this: &this->m_List.m_Memory.m_pMemory[i].m_szRetryAddress);
    if ( _V_stricmp(s1: pchAdrCheck, s2: v5) == 0 )
      break;
    if ( ++v3 >= this->m_List.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10061200
// Name: public: bool CAddressList::IsAddressInList(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
char __thiscall CAddressList::IsAddressInList(CAddressList *this, netadr_s *adr)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( this->m_List.m_Size <= 0 )
    return 0;
  for ( i = 0; !netadr_s::CompareAdr(this: adr, a: &this->m_List.m_Memory.m_pMemory[i].m_adrRemote, onlyBase: false); ++i )
  {
    if ( ++v3 >= this->m_List.m_Size )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10061250
// Name: public: void CAddressList::Describe(class CUtlString __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddressList::Describe(CAddressList *this, CUtlString *str)
{
  Remote_t *v3; // esi
  const char *v4; // ebx
  const char *v5; // eax
  const char *v6; // eax
  int i; // [esp+4h] [ebp-8h]
  int v8; // [esp+8h] [ebp-4h]

  i = 0;
  if ( this->m_List.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v3 = &this->m_List.m_Memory.m_pMemory[v8];
      v4 = CUtlString::operator char const *(this: &v3->m_szAlias);
      v5 = netadr_s::ToString(this: &v3->m_adrRemote, baseOnly: false);
      v6 = va(format: "%s(%s) ", v4, v5);
      CUtlString::operator+=(this: str, rhs: v6);
      ++v8;
      ++i;
    }
    while ( i < this->m_List.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100612C0
// Name: public: virtual bool CBaseClientState::ProcessGetCvarValue(class SVC_GetCvarValue __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CBaseClientState::ProcessGetCvarValue(CBaseClientState *this, SVC_GetCvarValue *msg)
{
  const char *m_szCvarName; // eax
  ConVar *v3; // eax
  _DWORD *v4; // esi
  int v5; // esi
  int v6; // esi
  const char *v7; // eax
  char tempValue[256]; // [esp+1Ch] [ebp-32Ch] BYREF
  CLC_RespondCvarValue returnMsg; // [esp+11Ch] [ebp-22Ch] BYREF
  float v11; // [esp+33Ch] [ebp-Ch]
  float v12; // [esp+340h] [ebp-8h]
  CBaseClientState *v13; // [esp+344h] [ebp-4h]
  SVC_GetCvarValue *msga; // [esp+350h] [ebp+8h]

  returnMsg.m_iCookie = msg->m_iCookie;
  m_szCvarName = msg->m_szCvarName;
  v13 = this;
  returnMsg.m_szCvarName = m_szCvarName;
  returnMsg.m_bReliable = true;
  returnMsg.m_NetChannel = nullptr;
  returnMsg.__vftable = (CLC_RespondCvarValue_vtbl *)&CLC_RespondCvarValue::`vftable';
  returnMsg.m_szCvarValue = defaultValue;
  returnMsg.m_eStatusCode = eQueryCvarValueStatus_CvarNotFound;
  v3 = g_pCVar->FindVar_2(this: g_pCVar, a2: m_szCvarName);
  v4 = &v3->ConCommandBase::__vftable;
  if ( v3 != nullptr )
  {
    if ( v3->IsFlagSet(this: v3, a2: 0x20000000) )
    {
      returnMsg.m_eStatusCode = eQueryCvarValueStatus_CvarProtected;
    }
    else
    {
      returnMsg.m_eStatusCode = eQueryCvarValueStatus_ValueIntact;
      if ( (*(unsigned __int8 (__thiscall **)(_DWORD *, int))(*v4 + 8))(a1: v4, a2: 4096) != 0 )
      {
        v5 = v4[7];
        v11 = *(float *)(v5 + 44);
        v12 = v11;
        if ( v5 != 0 )
          msga = *(SVC_GetCvarValue **)(v5 + 48);
        else
          msga = nullptr;
        if ( fabs(v12 - (double)(int)msga) >= 0.001 )
        {
          V_snprintf(pDest: tempValue, maxLen: 256, pFormat: "%f", v11);
          returnMsg.m_szCvarValue = tempValue;
        }
        else
        {
          if ( v5 != 0 )
            v6 = *(_DWORD *)(v5 + 48);
          else
            v6 = 0;
          V_snprintf(pDest: tempValue, maxLen: 256, pFormat: "%d", v6);
          returnMsg.m_szCvarValue = tempValue;
        }
      }
      else if ( (v4[5] & 0x1000) != 0 )
      {
        returnMsg.m_szCvarValue = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v7 = *(const char **)(v4[7] + 36);
        if ( v7 == nullptr )
          v7 = defaultValue;
        returnMsg.m_szCvarValue = v7;
      }
    }
  }
  else
  {
    returnMsg.m_eStatusCode = (g_pCVar->FindCommand_2(this: g_pCVar, a2: msg->m_szCvarName) != nullptr) + 1;
  }
  (*((void (__thiscall **)(IServerMessageHandler_vtbl *, CLC_RespondCvarValue *, _DWORD, _DWORD))v13->dtr_INetMessageHandler
   + 41))(
    a1: v13->IServerMessageHandler::INetMessageHandler::__vftable,
    a2: &returnMsg,
    a3: 0,
    a4: 0);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10061480
// Name: public: virtual void CBaseClientState::HandleReservationResponse(struct netadr_s __near &,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::HandleReservationResponse(CBaseClientState *this, netadr_s *adr, bool bSuccess)
{
  KeyValues *m_pKVGameSettings; // ecx
  IMatchAsyncOperationCallback *m_pServerReservationCallback; // ebx
  CBaseClientState::CAsyncOperation_ReserveServer *m_pServerReservationOperation; // eax

  if ( netadr_s::IsLoopback(this: adr) || CAddressList::IsAddressInList(this: &this->m_netadrReserveServer, adr) != 0 )
  {
    m_pKVGameSettings = this->m_pKVGameSettings;
    m_pServerReservationCallback = this->m_pServerReservationCallback;
    this->m_pServerReservationCallback = nullptr;
    if ( m_pKVGameSettings != nullptr )
    {
      KeyValues::deleteThis(this: m_pKVGameSettings);
      this->m_pKVGameSettings = nullptr;
    }
    if ( m_pServerReservationCallback != nullptr )
    {
      m_pServerReservationOperation = this->m_pServerReservationOperation;
      if ( m_pServerReservationOperation != nullptr )
      {
        m_pServerReservationOperation->m_eState = bSuccess + 3;
        this->m_pServerReservationOperation->m_adr = *adr;
      }
      m_pServerReservationCallback->OnOperationFinished(
        this: m_pServerReservationCallback,
        a2: this->m_pServerReservationOperation);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061520
// Name: public: virtual int SVC_UserMessage::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_UserMessage::GetType(SVC_UserMessage *this)
{
  return 23;
}

//------------------------------------------------------------------------------
// Address: 0x10061530
// Name: public: virtual char const __near * SVC_UserMessage::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_UserMessage::GetName(SVC_UserMessage *this)
{
  return "svc_UserMessage";
}

//------------------------------------------------------------------------------
// Address: 0x10061540
// Name: public: virtual bool SVC_UserMessage::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UserMessage::Process(SVC_UserMessage *this)
{
  return this->m_pMessageHandler->ProcessUserMessage(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10061550
// Name: public: virtual int NET_SignonState::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall NET_SignonState::GetType(NET_SignonState *this)
{
  return 7;
}

//------------------------------------------------------------------------------
// Address: 0x10061560
// Name: public: Remote_t::~Remote_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall Remote_t::~Remote_t(Remote_t *this)
{
  this->m_szRetryAddress.m_Storage.m_nActualLength = 0;
  if ( this->m_szRetryAddress.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szRetryAddress.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szRetryAddress.m_Storage.m_Memory.m_pMemory);
      this->m_szRetryAddress.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szRetryAddress.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
  this->m_szAlias.m_Storage.m_nActualLength = 0;
  if ( this->m_szAlias.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_szAlias.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_szAlias.m_Storage.m_Memory.m_pMemory);
      this->m_szAlias.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_szAlias.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100615C0
// Name: public: virtual int CLC_SplitPlayerConnect::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CLC_SplitPlayerConnect::GetType(CLC_SplitPlayerConnect *this)
{
  return 17;
}

//------------------------------------------------------------------------------
// Address: 0x100615D0
// Name: public: virtual char const __near * CLC_SplitPlayerConnect::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_SplitPlayerConnect::GetName(CLC_SplitPlayerConnect *this)
{
  return "clc_SplitPlayerConnect";
}

//------------------------------------------------------------------------------
// Address: 0x100615E0
// Name: public: virtual bool SVC_UpdateStringTable::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_UpdateStringTable::Process(CLC_SplitPlayerConnect *this)
{
  return this->m_pMessageHandler->ProcessSplitPlayerConnect(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10061620
// Name: public: virtual char const __near * CLC_ListenEvents::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CLC_ListenEvents::GetName(CLC_ListenEvents *this)
{
  return "clc_ListenEvents";
}

//------------------------------------------------------------------------------
// Address: 0x10061630
// Name: public: virtual void CBaseClientState::CheckForResend(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::CheckForResend(
        CBaseClientState *this,
        ISteamSocketMgr::ESteamCnxType bForceResendNow)
{
  int v3; // ebx
  CUtlString *v4; // eax
  netadr_s *v5; // edi
  const char *v6; // eax
  int v7; // eax
  int v8; // ebx
  const char *v9; // eax
  Remote_t *m_pMemory; // ecx
  const char *v11; // eax
  const char *v12; // ebx
  const char *v13; // eax
  int v14; // ebx
  int v15; // edi
  ISteamSocketMgr::ESteamCnxType v16; // eax
  unsigned int m_ListenServerSteamID; // ecx
  unsigned int m_ListenServerSteamID_high; // edx
  int m_nRetryNumber; // ebx
  bool v20; // bl
  int v21; // ebx
  netadr_s *p_m_adrRemote; // edi
  const char *v23; // eax
  unsigned int PrivateIPDelayMsecs; // eax
  bool v25; // zf
  CUtlString *p_m_szRetryAddress; // ecx
  const char *v27; // eax
  Remote_t *v28; // ebx
  int v29; // eax
  const char *v30; // eax
  netadr_s *v31; // [esp+10h] [ebp-A8h]
  const char *v32; // [esp+10h] [ebp-A8h]
  int v33; // [esp+10h] [ebp-A8h]
  char payload[128]; // [esp+20h] [ebp-98h] BYREF
  CUtlString desc; // [esp+A0h] [ebp-18h] BYREF
  const char *v36; // [esp+B0h] [ebp-8h]
  unsigned int v37; // [esp+B4h] [ebp-4h]

  if ( this->m_nSignonState == 1
    && !this->m_bWaitingForPassword
    && ((_BYTE)bForceResendNow != ESCT_NEVER || cl_resend.m_pParent->m_Value.m_fValue <= net_time
                                                                                       - this->m_flConnectTime) )
  {
    v3 = 0;
    if ( this->m_Remote.m_List.m_Size > 0 )
    {
      bForceResendNow = ESCT_NEVER;
      do
      {
        v4 = (CUtlString *)((char *)&this->m_Remote.m_List.m_Memory.m_pMemory->m_szAlias + bForceResendNow);
        v5 = (netadr_s *)&v4[2];
        v31 = (netadr_s *)&v4[2];
        v6 = CUtlString::operator char const *(this: v4 + 1);
        if ( NET_StringToAdr(s: v6, a: v31) == 0 )
        {
          v8 = v3;
          v32 = CUtlString::operator char const *(this: &this->m_Remote.m_List.m_Memory.m_pMemory[v8].m_szRetryAddress);
          v9 = CUtlString::operator char const *(this: &this->m_Remote.m_List.m_Memory.m_pMemory[v8].m_szAlias);
          ConMsg(a1: "Bad server address %s(%s)\n", v9, v32);
          this->Disconnect(this, a2: true);
          return;
        }
        if ( netadr_s::GetPort(this: v5) == 0 )
          netadr_s::SetPort(this: v5, newport: 0x6987u);
        bForceResendNow += 44;
        ++v3;
      }
      while ( v3 < this->m_Remote.m_List.m_Size );
      if ( this->m_nRetryNumber >= this->GetConnectionRetryNumber(this) )
      {
        v7 = this->GetConnectionRetryNumber(this);
        COM_ExplainDisconnection(bPrint: true, fmt: "Connection failed after %i retries.\n", v7);
        this->Disconnect(this, a2: true);
        return;
      }
      m_pMemory = this->m_Remote.m_List.m_Memory.m_pMemory;
      this->m_flConnectTime = net_time;
      v11 = CUtlString::operator char const *(this: &m_pMemory->m_szRetryAddress);
      if ( V_strncmp(s1: v11, s2: "localhost", count: 9) != 0 )
      {
        CUtlString::CUtlString(this: &desc);
        CAddressList::Describe(this: &this->m_Remote, str: &desc);
        v12 = "Connecting to";
        if ( this->m_nRetryNumber != 0 )
          v12 = "Retrying";
        v13 = CUtlString::operator char const *(this: &desc);
        ConMsg(a1: "%s %s...\n", v12, v13);
        CUtlString::~CUtlString(this: &desc);
      }
      if ( this->m_bWaitingForServerGameDetails )
      {
        v14 = 0;
        if ( this->m_Remote.m_List.m_Size > 0 )
        {
          v15 = 0;
          do
          {
            this->ResendGameDetailsRequest(this, a2: &this->m_Remote.m_List.m_Memory.m_pMemory[v15].m_adrRemote);
            ++v14;
            ++v15;
          }
          while ( v14 < this->m_Remote.m_List.m_Size );
          ++this->m_nRetryNumber;
          return;
        }
        goto LABEL_40;
      }
      V_snprintf(pDest: payload, maxLen: 128, pFormat: "%cconnect0x%08X", 113, this->m_DeferredConnection.m_nChallenge);
      v16 = g_pSteamSocketMgr->GetCnxType(this: g_pSteamSocketMgr);
      m_ListenServerSteamID = this->m_ListenServerSteamID;
      m_ListenServerSteamID_high = HIDWORD(this->m_ListenServerSteamID);
      bForceResendNow = v16;
      v20 = false;
      if ( __PAIR64__(m_ListenServerSteamID, m_ListenServerSteamID_high) != 0 )
      {
        m_nRetryNumber = this->m_nRetryNumber;
        if ( m_nRetryNumber > 0 && (m_nRetryNumber & 1) == 0 )
          v20 = true;
      }
      if ( __PAIR64__(m_ListenServerSteamID, m_ListenServerSteamID_high) != 0 && bForceResendNow == ESCT_ALWAYS )
        v20 = true;
      if ( __PAIR64__(m_ListenServerSteamID, m_ListenServerSteamID_high) != 0 || v20 )
      {
        v25 = __PAIR64__(m_ListenServerSteamID, m_ListenServerSteamID_high) == 0;
        p_m_szRetryAddress = &this->m_Remote.m_List.m_Memory.m_pMemory->m_szRetryAddress;
        if ( !v25 )
        {
          v27 = CUtlString::operator char const *(this: p_m_szRetryAddress);
          _Msg(a1: "%.3f:  Sending Steam connect to %s %llx\n", (double)net_time, v27, this->m_ListenServerSteamID);
          v28 = this->m_Remote.m_List.m_Memory.m_pMemory;
          v29 = _V_strlen(str: payload);
          v28->m_adrRemote = *NET_InitiateSteamConnection(
                                result: (netadr_s *)&desc.m_Storage.m_Memory.m_nAllocationCount,
                                sock: this->m_Socket,
                                uSteamID: this->m_ListenServerSteamID,
                                format: payload,
                                v29 + 1);
          ++this->m_nRetryNumber;
          return;
        }
        v30 = CUtlString::operator char const *(this: p_m_szRetryAddress);
        _Warning(a1: "%.3f:  Steam connection to unknown SteamId (%s) failed!\n", (double)net_time, v30);
        goto LABEL_40;
      }
      v21 = 0;
      if ( this->m_Remote.m_List.m_Size <= 0 )
      {
LABEL_40:
        ++this->m_nRetryNumber;
        return;
      }
      v37 = 0;
      do
      {
        p_m_adrRemote = &this->m_Remote.m_List.m_Memory.m_pMemory[v37 / 0x2C].m_adrRemote;
        v36 = CUtlString::operator char const *(this: &this->m_Remote.m_List.m_Memory.m_pMemory[v37 / 0x2C].m_szAlias);
        bForceResendNow = -16711936;
        v23 = netadr_s::ToString(this: p_m_adrRemote, baseOnly: false);
        ConColorMsg(
          a1: (const struct Color *)&bForceResendNow,
          a2: "%.3f:  Sending UDP connect to %s IP %s\n",
          (double)net_time,
          v36,
          v23);
        v33 = _V_strlen(str: payload) + 1;
        PrivateIPDelayMsecs = GetPrivateIPDelayMsecs();
        NET_OutOfBandDelayedPrintf(
          sock: this->m_Socket,
          adr: p_m_adrRemote,
          unMillisecondsDelay: v21 * PrivateIPDelayMsecs,
          format: payload,
          v33);
        v37 += 44;
        ++v21;
      }
      while ( v21 < this->m_Remote.m_List.m_Size );
      ++this->m_nRetryNumber;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100619A0
// Name: private: void CBaseClientState::BuildReserveServerPayload(class bf_write __near &,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::BuildReserveServerPayload(CBaseClientState *this, bf_write *msg, int nChallengeNr)
{
  int m_Put; // edi
  KeyValues *m_pKVGameSettings; // ecx
  unsigned __int8 *m_pData; // esi
  int v7; // eax
  unsigned int v8; // edi
  char buffer[728]; // [esp+8h] [ebp-334h] BYREF
  CUtlBuffer buf; // [esp+2E0h] [ebp-5Ch] BYREF
  IceKey cipher; // [esp+310h] [ebp-2Ch] BYREF
  bf_write payload; // [esp+31Ch] [ebp-20h] BYREF
  unsigned __int8 ucEncryptionKey[8]; // [esp+334h] [ebp-8h] BYREF

  bf_write::bf_write(this: &payload, pData: buffer, nBytes: 728, nBits: -1);
  bf_write::WriteLong(this: &payload, val: -17973521);
  bf_write::WriteLongLong(this: &payload, val: this->m_nServerReservationCookie);
  m_Put = 0;
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 0);
  if ( CUtlBuffer::IsBigEndian(this: &buf) )
    CUtlBuffer::SetBigEndian(this: &buf, bigEndian: false);
  m_pKVGameSettings = this->m_pKVGameSettings;
  if ( m_pKVGameSettings != nullptr
    && (KeyValues::WriteAsBinary(this: m_pKVGameSettings, buffer: &buf), m_Put = buf.m_Put, buf.m_Put > 600) )
  {
    this->HandleReservationResponse(
      this,
      a2: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory->m_adrRemote,
      a3: false);
  }
  else
  {
    bf_write::WriteLong(this: &payload, val: m_Put);
    if ( m_Put > 0 )
      bf_write::WriteBytes(this: &payload, pBuf: buf.m_Memory.m_pMemory, nBytes: m_Put);
    while ( ((payload.m_iCurBit + 7) >> 3) % 8 != 0 )
      bf_write::WriteByte(this: &payload, val: 0);
    IceKey::IceKey(this: &cipher, n: 1);
    *(_DWORD *)ucEncryptionKey = nChallengeNr ^ 0x5EF8CE12;
    *(_DWORD *)&ucEncryptionKey[4] = nChallengeNr ^ 0xAA98E42C;
    IceKey::set(this: &cipher, key: ucEncryptionKey);
    m_pData = payload.m_pData;
    v7 = (payload.m_iCurBit + 7) >> 3;
    if ( v7 != 0 )
    {
      v8 = ((unsigned int)(v7 - 1) >> 3) + 1;
      do
      {
        IceKey::encrypt(this: &cipher, ptext: m_pData, ctext: m_pData);
        m_pData += 8;
        --v8;
      }
      while ( v8 != 0 );
    }
    bf_write::WriteLong(this: msg, val: (payload.m_iCurBit + 7) >> 3);
    IceKey::~IceKey(this: &cipher);
    bf_write::WriteBytes(this: msg, pBuf: payload.m_pData, nBytes: (payload.m_iCurBit + 7) >> 3);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10061B50
// Name: public: virtual char const __near * NET_SetConVar::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_SetConVar::GetName(NET_SetConVar *this)
{
  return "net_SetConVar";
}

//------------------------------------------------------------------------------
// Address: 0x10061B60
// Name: public: virtual bool NET_SetConVar::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SetConVar::Process(NET_SetConVar *this)
{
  return this->m_pMessageHandler->ProcessSetConVar(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x10061BD0
// Name: public: virtual void CBaseClientState::SendConnectPacket(struct netadr_s const __near &,int,int,unsigned __int64,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SendConnectPacket(
        CBaseClientState *this,
        netadr_s *netAdrRemote,
        int challengeNr,
        int authProtocol,
        unsigned __int64 unGSSteamID,
        bool bGSSecure)
{
  const char *v7; // eax
  int HostVersion; // eax
  const char *v9; // eax
  char *m_pszString; // eax
  int i; // edi
  NetMessageCvar_t *m_pMemory; // eax
  int v13; // edi
  char v14; // cl
  const char *v15; // eax
  int m_iCurBit; // edx
  int m_Socket; // edx
  unsigned __int8 *m_pData; // [esp-14h] [ebp-9BCh]
  int v19; // [esp-10h] [ebp-9B8h]
  char msg_buffer[2400]; // [esp+Ch] [ebp-99Ch] BYREF
  CLC_SplitPlayerConnect splitMsg; // [esp+96Ch] [ebp-3Ch] BYREF
  bf_write msg; // [esp+990h] [ebp-18h] BYREF

  _COM_TimestampedLog(a1: "SendConnectPacket");
  if ( !netadr_s::IsLoopback(this: netAdrRemote)
    && CAddressList::IsAddressInList(this: &this->m_Remote, adr: netAdrRemote) == 0 )
  {
    v7 = netadr_s::ToString(this: netAdrRemote, baseOnly: false);
    _Warning(a1: "Sending connect packet to unexpected address %s\n", v7);
  }
  bf_write::bf_write(this: &msg, pData: msg_buffer, nBytes: 2400, nBits: -1);
  bf_write::WriteLong(this: &msg, val: -1);
  bf_write::WriteByte(this: &msg, val: 0x6Bu);
  HostVersion = GetHostVersion();
  bf_write::WriteLong(this: &msg, val: HostVersion);
  bf_write::WriteLong(this: &msg, val: authProtocol);
  bf_write::WriteLong(this: &msg, val: challengeNr);
  v9 = this->GetClientName(this);
  bf_write::WriteString(this: &msg, pStr: v9);
  if ( (password.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = password.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)defaultValue;
  }
  bf_write::WriteString(this: &msg, pStr: m_pszString);
  bf_write::WriteByte(this: &msg, val: this->m_nNumPlayersToConnect);
  for ( i = 0; i < this->m_nNumPlayersToConnect; ++i )
  {
    splitMsg.m_bReliable = true;
    splitMsg.m_NetChannel = nullptr;
    splitMsg.__vftable = (CLC_SplitPlayerConnect_vtbl *)&CLC_SplitPlayerConnect::`vftable';
    memset(&splitMsg.m_UserInfo, 0, sizeof(splitMsg.m_UserInfo));
    Host_BuildUserInfoUpdateMessage(nSplitScreenSlot: i, rCvarList: &splitMsg.m_UserInfo, nonDefault: false);
    NET_SetConVar::WriteToBuffer(this: (NET_SetConVar *)&splitMsg, buffer: &msg);
    m_pMemory = splitMsg.m_UserInfo.m_Memory.m_pMemory;
    splitMsg.m_UserInfo.m_Size = 0;
    if ( splitMsg.m_UserInfo.m_Memory.m_nGrowSize >= 0 )
    {
      if ( splitMsg.m_UserInfo.m_Memory.m_pMemory != nullptr )
      {
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: splitMsg.m_UserInfo.m_Memory.m_pMemory);
        m_pMemory = nullptr;
        splitMsg.m_UserInfo.m_Memory.m_pMemory = nullptr;
      }
      splitMsg.m_UserInfo.m_Memory.m_nAllocationCount = 0;
    }
    splitMsg.m_UserInfo.m_pElements = m_pMemory;
    if ( splitMsg.m_UserInfo.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
  }
  if ( msg.m_iCurBit + 1 <= msg.m_nDataBits )
  {
    if ( !msg.m_bOverflow )
    {
      v13 = msg.m_iCurBit >> 3;
      v14 = msg.m_iCurBit & 7;
      if ( g_bLowViolence )
        msg.m_pData[v13] |= 1 << v14;
      else
        msg.m_pData[v13] &= ~(1 << v14);
      ++msg.m_iCurBit;
    }
  }
  else
  {
    msg.m_bOverflow = true;
  }
  bf_write::WriteLongLong(this: &msg, val: this->m_nServerReservationCookie);
  bf_write::WriteByte(this: &msg, val: 1u);
  if ( authProtocol == 2 )
  {
    v15 = this->GetCDKeyHash(this);
    bf_write::WriteString(this: &msg, pStr: v15);
LABEL_30:
    m_iCurBit = msg.m_iCurBit;
    this->m_flConnectTime = net_time;
    v19 = (m_iCurBit + 7) >> 3;
    m_Socket = this->m_Socket;
    m_pData = msg.m_pData;
    this->m_nChallengeNr = challengeNr;
    NET_SendPacket(
      chan: nullptr,
      sock: m_Socket,
      to: netAdrRemote,
      data: m_pData,
      length: v19,
      pVoicePayload: nullptr,
      bUseCompression: false,
      unMillisecondsDelay: 0);
    return;
  }
  if ( authProtocol != 3 )
  {
    Host_Error(error: "Unexepected authentication protocol %i!\n", authProtocol);
    return;
  }
  if ( CBaseClientState::PrepareSteamConnectResponse(this, unGSSteamID, bGSSecure, adr: netAdrRemote, &msg) != 0 )
    goto LABEL_30;
}

//------------------------------------------------------------------------------
// Address: 0x10061E50
// Name: public: virtual void CBaseClientState::RunFrame(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::RunFrame(CBaseClientState *this)
{
  CLC_ListenEvents msg; // [esp+4h] [ebp-50h] BYREF

  if ( this->m_nSignonState > 3
    && this->m_NetChannel != nullptr
    && CGameEventManager::HasClientListenersChanged(this: g_GameEventManager, bReset: true) )
  {
    msg.m_bReliable = true;
    msg.m_NetChannel = nullptr;
    msg.__vftable = (CLC_ListenEvents_vtbl *)&CLC_ListenEvents::`vftable';
    memset(dst: (unsigned __int8 *)&msg.m_EventArray, value: 0, count: sizeof(msg.m_EventArray));
    CGameEventManager::WriteListenEventList(this: g_GameEventManager, &msg);
    this->m_NetChannel->SendNetMsg(this: this->m_NetChannel, a2: &msg, a3: false, a4: false);
  }
  if ( this->m_nSignonState == 1 )
    this->CheckForResend(this, a2: false);
  this->CheckForReservationResend(this);
}

//------------------------------------------------------------------------------
// Address: 0x10061EE0
// Name: public: virtual void CBaseClientState::CheckForReservationResend(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::CheckForReservationResend(CBaseClientState *this)
{
  int m_nReservationMsgRetryNumber; // eax
  const char *v3; // eax
  CUtlString desc; // [esp+4h] [ebp-10h] BYREF

  if ( !this->m_bWaitingForPassword
    && this->m_pServerReservationCallback != nullptr
    && net_time - this->m_flReservationMsgSendTime >= 3.0 )
  {
    m_nReservationMsgRetryNumber = this->m_nReservationMsgRetryNumber;
    if ( (float)m_nReservationMsgRetryNumber < 2.0 )
    {
      this->m_nReservationMsgRetryNumber = m_nReservationMsgRetryNumber + 1;
      CBaseClientState::SendReserveServerChallenge(this);
    }
    else
    {
      CUtlString::CUtlString(this: &desc);
      CAddressList::Describe(this: &this->m_netadrReserveServer, str: &desc);
      v3 = CUtlString::operator char const *(this: &desc);
      DevMsg(
        a1: "Attempt to reserve server %s failed; timed out after %d attempts\n",
        v3,
        this->m_nReservationMsgRetryNumber + 1);
      this->HandleReservationResponse(
        this,
        a2: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory->m_adrRemote,
        a3: false);
      CUtlString::~CUtlString(this: &desc);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10061FA0
// Name: public: virtual void CBaseClientState::HandleReserveServerChallengeResponse(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::HandleReserveServerChallengeResponse(CBaseClientState *this, int nChallengeNr)
{
  int HostVersion; // eax
  int v4; // edi
  int v5; // ebx
  char buffer[728]; // [esp+4h] [ebp-2F0h] BYREF
  bf_write msg; // [esp+2DCh] [ebp-18h] BYREF

  if ( this->m_pServerReservationCallback != nullptr )
  {
    bf_write::bf_write(this: &msg, pData: buffer, nBytes: 728, nBits: -1);
    bf_write::WriteLong(this: &msg, val: -1);
    bf_write::WriteByte(this: &msg, val: 0x6Eu);
    HostVersion = GetHostVersion();
    bf_write::WriteLong(this: &msg, val: HostVersion);
    CBaseClientState::BuildReserveServerPayload(this, &msg, nChallengeNr);
    v4 = 0;
    if ( this->m_netadrReserveServer.m_List.m_Size > 0 )
    {
      v5 = 0;
      do
      {
        NET_SendPacket(
          chan: nullptr,
          sock: this->m_Socket,
          to: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory[v5].m_adrRemote,
          data: msg.m_pData,
          length: (msg.m_iCurBit + 7) >> 3,
          pVoicePayload: nullptr,
          bUseCompression: false,
          unMillisecondsDelay: 0);
        ++v4;
        ++v5;
      }
      while ( v4 < this->m_netadrReserveServer.m_List.m_Size );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062060
// Name: public: virtual char const __near * NET_SignonState::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall NET_SignonState::GetName(NET_SignonState *this)
{
  return "net_SignonState";
}

//------------------------------------------------------------------------------
// Address: 0x10062070
// Name: public: virtual unsigned int NET_SignonState::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall NET_SignonState::GetSize(NET_SignonState *this)
{
  return 68;
}

//------------------------------------------------------------------------------
// Address: 0x10062080
// Name: public: virtual bool NET_SignonState::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall NET_SignonState::Process(NET_SignonState *this)
{
  return this->m_pMessageHandler->ProcessSignonState(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100620B0
// Name: public: virtual char const __near * SVC_ClassInfo::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall SVC_ClassInfo::GetName(SVC_ClassInfo *this)
{
  return "svc_ClassInfo";
}

//------------------------------------------------------------------------------
// Address: 0x100620C0
// Name: public: virtual bool SVC_ClassInfo::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_ClassInfo::Process(SVC_ClassInfo *this)
{
  return this->m_pMessageHandler->ProcessClassInfo(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x100620D0
// Name: public: virtual void CBaseClientState::ConnectionStart(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectionStart(CBaseClientState *this, INetChannel *chan)
{
  INetMessage *v3; // eax
  IServerMessageHandler *v4; // ebx
  IServerMessageHandler *v5; // ecx
  INetMessage *v6; // eax
  IServerMessageHandler *v7; // ecx
  INetMessage *v8; // eax
  IServerMessageHandler *v9; // ecx
  INetMessage *v10; // eax
  IServerMessageHandler *v11; // ecx
  NET_SplitScreenUser *v12; // eax
  NET_SplitScreenUser *v13; // eax
  IServerMessageHandler *v14; // ecx
  INetMessage *v15; // eax
  IServerMessageHandler *v16; // ecx
  INetMessage *v17; // eax
  IServerMessageHandler *v18; // ecx
  char *v19; // eax
  INetMessage *v20; // edi
  INetMessage *v21; // eax
  IServerMessageHandler *v22; // ecx
  INetMessage *v23; // eax
  IServerMessageHandler *v24; // ecx
  INetMessage *v25; // eax
  IServerMessageHandler *v26; // ecx
  SVC_CreateStringTable *v27; // eax
  SVC_CreateStringTable *StringTable; // eax
  IServerMessageHandler *v29; // ecx
  char *v30; // eax
  INetMessage *v31; // edi
  INetMessage *v32; // eax
  IServerMessageHandler *v33; // ecx
  INetMessage *v34; // eax
  IServerMessageHandler *v35; // ecx
  INetMessage *v36; // eax
  IServerMessageHandler *v37; // ecx
  char *v38; // eax
  INetMessage *v39; // edi
  INetMessage *v40; // eax
  IServerMessageHandler *v41; // ecx
  INetMessage *v42; // eax
  IServerMessageHandler *v43; // ecx
  INetMessage *v44; // eax
  IServerMessageHandler *v45; // ecx
  INetMessage *v46; // eax
  IServerMessageHandler *v47; // ecx
  INetMessage *v48; // eax
  IServerMessageHandler *v49; // ecx
  char *v50; // eax
  INetMessage *v51; // edi
  IServerMessageHandler *v52; // eax
  char *v53; // eax
  char *v54; // edi
  IServerMessageHandler *v55; // eax
  char *v56; // eax
  INetMessage *v57; // edi
  IServerMessageHandler *v58; // eax
  char *v59; // eax
  INetMessage *v60; // edi
  IServerMessageHandler *v61; // eax
  char *v62; // eax
  INetMessage *v63; // edi
  INetMessage *v64; // eax
  IServerMessageHandler *v65; // ecx
  INetMessage *v66; // eax
  IServerMessageHandler *v67; // ecx
  INetMessage *v68; // eax
  IServerMessageHandler *v69; // ecx
  char *v70; // eax
  INetMessage *v71; // edi
  INetMessage *v72; // eax
  IServerMessageHandler *v73; // ecx
  INetMessage *v74; // eax
  IServerMessageHandler *v75; // ecx
  INetMessage *v76; // eax
  IServerMessageHandler *v77; // ecx
  SVC_CmdKeyValues *v78; // eax
  SVC_CmdKeyValues *v79; // eax
  IServerMessageHandler *v80; // ecx
  char *v81; // eax
  INetMessage *v82; // edi

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
  if ( this != nullptr )
    v5 = &this->IServerMessageHandler;
  else
    v5 = nullptr;
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
  if ( this != nullptr )
    v7 = &this->IServerMessageHandler;
  else
    v7 = nullptr;
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
  if ( this != nullptr )
    v9 = &this->IServerMessageHandler;
  else
    v9 = nullptr;
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
  if ( this != nullptr )
    v11 = &this->IServerMessageHandler;
  else
    v11 = nullptr;
  v10[3].__vftable = (INetMessage_vtbl *)v11;
  chan->RegisterMessage(this: chan, a2: v10);
  v12 = (NET_SplitScreenUser *)calloc(count: 1u, size: 0x14u);
  if ( v12 != nullptr )
    v13 = NET_SplitScreenUser::NET_SplitScreenUser(this: v12);
  else
    v13 = nullptr;
  if ( this != nullptr )
    v14 = &this->IServerMessageHandler;
  else
    v14 = nullptr;
  v13->m_pMessageHandler = v14;
  chan->RegisterMessage(this: chan, a2: v13);
  v15 = (INetMessage *)calloc(count: 1u, size: 0x814u);
  if ( v15 != nullptr )
  {
    v15[2].__vftable = nullptr;
    v15->__vftable = (INetMessage_vtbl *)&SVC_Print::`vftable';
    LOBYTE(v15[1].__vftable) = 0;
    v15[4].__vftable = nullptr;
  }
  else
  {
    v15 = nullptr;
  }
  if ( this != nullptr )
    v16 = &this->IServerMessageHandler;
  else
    v16 = nullptr;
  v15[3].__vftable = (INetMessage_vtbl *)v16;
  chan->RegisterMessage(this: chan, a2: v15);
  v17 = (INetMessage *)calloc(count: 1u, size: 0x458u);
  if ( v17 != nullptr )
  {
    LOBYTE(v17[1].__vftable) = 1;
    v17[2].__vftable = nullptr;
    v17->__vftable = (INetMessage_vtbl *)&SVC_ServerInfo::`vftable';
  }
  else
  {
    v17 = nullptr;
  }
  if ( this != nullptr )
    v18 = &this->IServerMessageHandler;
  else
    v18 = nullptr;
  v17[3].__vftable = (INetMessage_vtbl *)v18;
  chan->RegisterMessage(this: chan, a2: v17);
  v19 = (char *)calloc(count: 1u, size: 0x54u);
  v20 = (INetMessage *)v19;
  if ( v19 != nullptr )
  {
    v19[4] = 1;
    *((_DWORD *)v19 + 2) = 0;
    *(_DWORD *)v19 = &SVC_SendTable::`vftable';
    v19[28] = 0;
    *((_DWORD *)v19 + 6) = 0;
    *((_DWORD *)v19 + 8) = -1;
    *((_DWORD *)v19 + 9) = 0;
    bf_write::bf_write(this: (bf_write *)(v19 + 60));
    v21 = v20;
  }
  else
  {
    v21 = nullptr;
  }
  if ( this != nullptr )
    v22 = &this->IServerMessageHandler;
  else
    v22 = nullptr;
  v21[3].__vftable = (INetMessage_vtbl *)v22;
  chan->RegisterMessage(this: chan, a2: v21);
  v23 = (INetMessage *)calloc(count: 1u, size: 0x2Cu);
  if ( v23 != nullptr )
  {
    LOBYTE(v23[1].__vftable) = 1;
    v23[2].__vftable = nullptr;
    v23->__vftable = (INetMessage_vtbl *)&SVC_ClassInfo::`vftable';
    v23[5].__vftable = nullptr;
    v23[6].__vftable = nullptr;
    v23[7].__vftable = nullptr;
    v23[8].__vftable = nullptr;
    v23[9].__vftable = nullptr;
  }
  else
  {
    v23 = nullptr;
  }
  if ( this != nullptr )
    v24 = &this->IServerMessageHandler;
  else
    v24 = nullptr;
  v23[3].__vftable = (INetMessage_vtbl *)v24;
  chan->RegisterMessage(this: chan, a2: v23);
  v25 = (INetMessage *)calloc(count: 1u, size: 0x14u);
  if ( v25 != nullptr )
  {
    LOBYTE(v25[1].__vftable) = 1;
    v25[2].__vftable = nullptr;
    v25->__vftable = (INetMessage_vtbl *)&SVC_SetPause::`vftable';
  }
  else
  {
    v25 = nullptr;
  }
  if ( this != nullptr )
    v26 = &this->IServerMessageHandler;
  else
    v26 = nullptr;
  v25[3].__vftable = (INetMessage_vtbl *)v26;
  chan->RegisterMessage(this: chan, a2: v25);
  v27 = (SVC_CreateStringTable *)calloc(count: 1u, size: 0x170u);
  if ( v27 != nullptr )
    StringTable = SVC_CreateStringTable::SVC_CreateStringTable(this: v27);
  else
    StringTable = nullptr;
  if ( this != nullptr )
    v29 = &this->IServerMessageHandler;
  else
    v29 = nullptr;
  StringTable->m_pMessageHandler = v29;
  chan->RegisterMessage(this: chan, a2: StringTable);
  v30 = (char *)calloc(count: 1u, size: 0x58u);
  v31 = (INetMessage *)v30;
  if ( v30 != nullptr )
  {
    v30[4] = 1;
    *((_DWORD *)v30 + 2) = 0;
    *(_DWORD *)v30 = &SVC_UpdateStringTable::`vftable';
    v30[32] = 0;
    *((_DWORD *)v30 + 7) = 0;
    *((_DWORD *)v30 + 9) = -1;
    *((_DWORD *)v30 + 10) = 0;
    bf_write::bf_write(this: (bf_write *)(v30 + 64));
    v32 = v31;
  }
  else
  {
    v32 = nullptr;
  }
  if ( this != nullptr )
    v33 = &this->IServerMessageHandler;
  else
    v33 = nullptr;
  v32[3].__vftable = (INetMessage_vtbl *)v33;
  chan->RegisterMessage(this: chan, a2: v32);
  v34 = (INetMessage *)calloc(count: 1u, size: 0x11Cu);
  if ( v34 != nullptr )
  {
    LOBYTE(v34[1].__vftable) = 1;
    v34[2].__vftable = nullptr;
    v34->__vftable = (INetMessage_vtbl *)&SVC_VoiceInit::`vftable';
  }
  else
  {
    v34 = nullptr;
  }
  if ( this != nullptr )
    v35 = &this->IServerMessageHandler;
  else
    v35 = nullptr;
  v34[3].__vftable = (INetMessage_vtbl *)v35;
  chan->RegisterMessage(this: chan, a2: v34);
  v36 = (INetMessage *)calloc(count: 1u, size: 0x58u);
  if ( v36 != nullptr )
  {
    v36[2].__vftable = nullptr;
    v36->__vftable = (INetMessage_vtbl *)&SVC_VoiceData::`vftable';
    LOBYTE(v36[12].__vftable) = 0;
    v36[11].__vftable = nullptr;
    v36[13].__vftable = (INetMessage_vtbl *)-1;
    v36[14].__vftable = nullptr;
    LOBYTE(v36[1].__vftable) = 0;
  }
  else
  {
    v36 = nullptr;
  }
  if ( this != nullptr )
    v37 = &this->IServerMessageHandler;
  else
    v37 = nullptr;
  v36[3].__vftable = (INetMessage_vtbl *)v37;
  chan->RegisterMessage(this: chan, a2: v36);
  v38 = (char *)calloc(count: 1u, size: 0x58u);
  v39 = (INetMessage *)v38;
  if ( v38 != nullptr )
  {
    v38[4] = 1;
    *((_DWORD *)v38 + 2) = 0;
    *(_DWORD *)v38 = &SVC_Sounds::`vftable';
    v38[32] = 0;
    *((_DWORD *)v38 + 7) = 0;
    *((_DWORD *)v38 + 9) = -1;
    *((_DWORD *)v38 + 10) = 0;
    bf_write::bf_write(this: (bf_write *)(v38 + 64));
    v40 = v39;
  }
  else
  {
    v40 = nullptr;
  }
  if ( this != nullptr )
    v41 = &this->IServerMessageHandler;
  else
    v41 = nullptr;
  v40[3].__vftable = (INetMessage_vtbl *)v41;
  chan->RegisterMessage(this: chan, a2: v40);
  v42 = (INetMessage *)calloc(count: 1u, size: 0x14u);
  if ( v42 != nullptr )
  {
    LOBYTE(v42[1].__vftable) = 1;
    v42[2].__vftable = nullptr;
    v42->__vftable = (INetMessage_vtbl *)&SVC_SetView::`vftable';
  }
  else
  {
    v42 = nullptr;
  }
  if ( this != nullptr )
    v43 = &this->IServerMessageHandler;
  else
    v43 = nullptr;
  v42[3].__vftable = (INetMessage_vtbl *)v43;
  chan->RegisterMessage(this: chan, a2: v42);
  v44 = (INetMessage *)calloc(count: 1u, size: 0x20u);
  if ( v44 != nullptr )
  {
    v44[2].__vftable = nullptr;
    v44->__vftable = (INetMessage_vtbl *)&SVC_FixAngle::`vftable';
    LOBYTE(v44[1].__vftable) = 0;
  }
  else
  {
    v44 = nullptr;
  }
  if ( this != nullptr )
    v45 = &this->IServerMessageHandler;
  else
    v45 = nullptr;
  v44[3].__vftable = (INetMessage_vtbl *)v45;
  chan->RegisterMessage(this: chan, a2: v44);
  v46 = (INetMessage *)calloc(count: 1u, size: 0x1Cu);
  if ( v46 != nullptr )
  {
    LOBYTE(v46[1].__vftable) = 1;
    v46[2].__vftable = nullptr;
    v46->__vftable = (INetMessage_vtbl *)&SVC_CrosshairAngle::`vftable';
  }
  else
  {
    v46 = nullptr;
  }
  if ( this != nullptr )
    v47 = &this->IServerMessageHandler;
  else
    v47 = nullptr;
  v46[3].__vftable = (INetMessage_vtbl *)v47;
  chan->RegisterMessage(this: chan, a2: v46);
  v48 = (INetMessage *)calloc(count: 1u, size: 0x2Cu);
  if ( v48 != nullptr )
  {
    LOBYTE(v48[1].__vftable) = 1;
    v48[2].__vftable = nullptr;
    v48->__vftable = (INetMessage_vtbl *)&SVC_BSPDecal::`vftable';
  }
  else
  {
    v48 = nullptr;
  }
  if ( this != nullptr )
    v49 = &this->IServerMessageHandler;
  else
    v49 = nullptr;
  v48[3].__vftable = (INetMessage_vtbl *)v49;
  chan->RegisterMessage(this: chan, a2: v48);
  v50 = (char *)calloc(count: 1u, size: 0x50u);
  v51 = (INetMessage *)v50;
  if ( v50 != nullptr )
  {
    v50[4] = 1;
    *((_DWORD *)v50 + 2) = 0;
    *(_DWORD *)v50 = &SVC_GameEvent::`vftable';
    v50[24] = 0;
    *((_DWORD *)v50 + 5) = 0;
    *((_DWORD *)v50 + 7) = -1;
    *((_DWORD *)v50 + 8) = 0;
    bf_write::bf_write(this: (bf_write *)(v50 + 56));
  }
  else
  {
    v51 = nullptr;
  }
  if ( this != nullptr )
    v52 = &this->IServerMessageHandler;
  else
    v52 = nullptr;
  v51[3].__vftable = (INetMessage_vtbl *)v52;
  chan->RegisterMessage(this: chan, a2: v51);
  v53 = (char *)calloc(count: 1u, size: 0x64u);
  v54 = v53;
  if ( v53 != nullptr )
  {
    v53[4] = 1;
    *((_DWORD *)v53 + 2) = 0;
    *(_DWORD *)v53 = &SVC_UserMessage::`vftable';
    v53[28] = 0;
    *((_DWORD *)v53 + 6) = 0;
    *((_DWORD *)v53 + 8) = -1;
    *((_DWORD *)v53 + 9) = 0;
    bf_write::bf_write(this: (bf_write *)(v53 + 60));
    CUtlString::CUtlString(this: (CUtlString *)(v54 + 84));
    v54[4] = 0;
  }
  else
  {
    v54 = nullptr;
  }
  if ( this != nullptr )
    v55 = &this->IServerMessageHandler;
  else
    v55 = nullptr;
  *((_DWORD *)v54 + 3) = v55;
  chan->RegisterMessage(this: chan, a2: (INetMessage *)v54);
  v56 = (char *)calloc(count: 1u, size: 0x58u);
  v57 = (INetMessage *)v56;
  if ( v56 != nullptr )
  {
    v56[4] = 1;
    *((_DWORD *)v56 + 2) = 0;
    *(_DWORD *)v56 = &SVC_EntityMessage::`vftable';
    v56[32] = 0;
    *((_DWORD *)v56 + 7) = 0;
    *((_DWORD *)v56 + 9) = -1;
    *((_DWORD *)v56 + 10) = 0;
    bf_write::bf_write(this: (bf_write *)(v56 + 64));
    LOBYTE(v57[1].__vftable) = 0;
  }
  else
  {
    v57 = nullptr;
  }
  if ( this != nullptr )
    v58 = &this->IServerMessageHandler;
  else
    v58 = nullptr;
  v57[3].__vftable = (INetMessage_vtbl *)v58;
  chan->RegisterMessage(this: chan, a2: v57);
  v59 = (char *)calloc(count: 1u, size: 0x64u);
  v60 = (INetMessage *)v59;
  if ( v59 != nullptr )
  {
    v59[4] = 1;
    *((_DWORD *)v59 + 2) = 0;
    *(_DWORD *)v59 = &SVC_PacketEntities::`vftable';
    v59[44] = 0;
    *((_DWORD *)v59 + 10) = 0;
    *((_DWORD *)v59 + 12) = -1;
    *((_DWORD *)v59 + 13) = 0;
    bf_write::bf_write(this: (bf_write *)(v59 + 76));
  }
  else
  {
    v60 = nullptr;
  }
  if ( this != nullptr )
    v61 = &this->IServerMessageHandler;
  else
    v61 = nullptr;
  v60[3].__vftable = (INetMessage_vtbl *)v61;
  chan->RegisterMessage(this: chan, a2: v60);
  v62 = (char *)calloc(count: 1u, size: 0x54u);
  v63 = (INetMessage *)v62;
  if ( v62 != nullptr )
  {
    v62[4] = 1;
    *((_DWORD *)v62 + 2) = 0;
    *(_DWORD *)v62 = &SVC_TempEntities::`vftable';
    v62[28] = 0;
    *((_DWORD *)v62 + 6) = 0;
    *((_DWORD *)v62 + 8) = -1;
    *((_DWORD *)v62 + 9) = 0;
    bf_write::bf_write(this: (bf_write *)(v62 + 60));
    LOBYTE(v63[1].__vftable) = 0;
    v64 = v63;
  }
  else
  {
    v64 = nullptr;
  }
  if ( this != nullptr )
    v65 = &this->IServerMessageHandler;
  else
    v65 = nullptr;
  v64[3].__vftable = (INetMessage_vtbl *)v65;
  chan->RegisterMessage(this: chan, a2: v64);
  v66 = (INetMessage *)calloc(count: 1u, size: 0x14u);
  if ( v66 != nullptr )
  {
    LOBYTE(v66[1].__vftable) = 1;
    v66[2].__vftable = nullptr;
    v66->__vftable = (INetMessage_vtbl *)&SVC_Prefetch::`vftable';
  }
  else
  {
    v66 = nullptr;
  }
  if ( this != nullptr )
    v67 = &this->IServerMessageHandler;
  else
    v67 = nullptr;
  v66[3].__vftable = (INetMessage_vtbl *)v67;
  chan->RegisterMessage(this: chan, a2: v66);
  v68 = (INetMessage *)calloc(count: 1u, size: 0x1Cu);
  if ( v68 != nullptr )
  {
    v68[2].__vftable = nullptr;
    v68->__vftable = (INetMessage_vtbl *)&SVC_Menu::`vftable';
    LOBYTE(v68[1].__vftable) = 1;
    v68[5].__vftable = (INetMessage_vtbl *)1;
    v68[4].__vftable = nullptr;
  }
  else
  {
    v68 = nullptr;
  }
  if ( this != nullptr )
    v69 = &this->IServerMessageHandler;
  else
    v69 = nullptr;
  v68[3].__vftable = (INetMessage_vtbl *)v69;
  chan->RegisterMessage(this: chan, a2: v68);
  v70 = (char *)calloc(count: 1u, size: 0x54u);
  v71 = (INetMessage *)v70;
  if ( v70 != nullptr )
  {
    v70[4] = 1;
    *((_DWORD *)v70 + 2) = 0;
    *(_DWORD *)v70 = &SVC_GameEventList::`vftable';
    v70[28] = 0;
    *((_DWORD *)v70 + 6) = 0;
    *((_DWORD *)v70 + 8) = -1;
    *((_DWORD *)v70 + 9) = 0;
    bf_write::bf_write(this: (bf_write *)(v70 + 60));
    v72 = v71;
  }
  else
  {
    v72 = nullptr;
  }
  if ( this != nullptr )
    v73 = &this->IServerMessageHandler;
  else
    v73 = nullptr;
  v72[3].__vftable = (INetMessage_vtbl *)v73;
  chan->RegisterMessage(this: chan, a2: v72);
  v74 = (INetMessage *)calloc(count: 1u, size: 0x118u);
  if ( v74 != nullptr )
  {
    LOBYTE(v74[1].__vftable) = 1;
    v74[2].__vftable = nullptr;
    v74->__vftable = (INetMessage_vtbl *)&SVC_GetCvarValue::`vftable';
  }
  else
  {
    v74 = nullptr;
  }
  if ( this != nullptr )
    v75 = &this->IServerMessageHandler;
  else
    v75 = nullptr;
  v74[3].__vftable = (INetMessage_vtbl *)v75;
  chan->RegisterMessage(this: chan, a2: v74);
  v76 = (INetMessage *)calloc(count: 1u, size: 0x1Cu);
  if ( v76 != nullptr )
  {
    LOBYTE(v76[1].__vftable) = 1;
    v76[2].__vftable = nullptr;
    v76->__vftable = (INetMessage_vtbl *)&SVC_SplitScreen::`vftable';
  }
  else
  {
    v76 = nullptr;
  }
  if ( this != nullptr )
    v77 = &this->IServerMessageHandler;
  else
    v77 = nullptr;
  v76[3].__vftable = (INetMessage_vtbl *)v77;
  chan->RegisterMessage(this: chan, a2: v76);
  v78 = (SVC_CmdKeyValues *)calloc(count: 1u, size: 0x14u);
  if ( v78 != nullptr )
    v79 = SVC_CmdKeyValues::SVC_CmdKeyValues(this: v78, pKeyValues: nullptr);
  else
    v79 = nullptr;
  if ( this != nullptr )
    v80 = &this->IServerMessageHandler;
  else
    v80 = nullptr;
  v79->m_pMessageHandler = v80;
  chan->RegisterMessage(this: chan, a2: v79);
  v81 = (char *)calloc(count: 1u, size: 0x50u);
  v82 = (INetMessage *)v81;
  if ( v81 != nullptr )
  {
    v81[4] = 1;
    *((_DWORD *)v81 + 2) = 0;
    *(_DWORD *)v81 = &SVC_PaintmapData::`vftable';
    v81[24] = 0;
    *((_DWORD *)v81 + 5) = 0;
    *((_DWORD *)v81 + 7) = -1;
    *((_DWORD *)v81 + 8) = 0;
    bf_write::bf_write(this: (bf_write *)(v81 + 56));
  }
  else
  {
    v82 = nullptr;
  }
  if ( this != nullptr )
    v4 = &this->IServerMessageHandler;
  v82[3].__vftable = (INetMessage_vtbl *)v4;
  chan->RegisterMessage(this: chan, a2: v82);
}

//------------------------------------------------------------------------------
// Address: 0x10062B10
// Name: public: void CAddressList::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
void __thiscall CAddressList::RemoveAll(CAddressList *this)
{
  CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::RemoveAll(this: &this->m_List);
}

//------------------------------------------------------------------------------
// Address: 0x10062B20
// Name: public: void CAddressList::AddRemote(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CAddressList::AddRemote(CAddressList *this, const char *pchAddress, const char *pchAlias)
{
  const char *v4; // eax
  Remote_t remote; // [esp+8h] [ebp-2Ch] BYREF

  if ( CAddressList::IsRemoteInList(this, pchAdrCheck: pchAddress) == 0 )
  {
    CUtlString::CUtlString(this: &remote.m_szAlias);
    CUtlString::CUtlString(this: &remote.m_szRetryAddress);
    netadr_s::SetIP(this: &remote.m_adrRemote, unIP: 0);
    netadr_s::SetPort(this: &remote.m_adrRemote, newport: 0);
    netadr_s::SetType(this: &remote.m_adrRemote, newtype: NA_IP);
    CUtlString::operator=(this: &remote.m_szRetryAddress, src: pchAddress);
    CUtlString::operator=(this: &remote.m_szAlias, src: pchAlias);
    v4 = CUtlString::operator char const *(this: &remote.m_szRetryAddress);
    if ( NET_StringToAdr(s: v4, a: &remote.m_adrRemote) != 0 && netadr_s::GetPort(this: &remote.m_adrRemote) == 0 )
      netadr_s::SetPort(this: &remote.m_adrRemote, newport: 0x6987u);
    CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::InsertBefore(
      this: &this->m_List,
      elem: this->m_List.m_Size,
      src: &remote);
    Remote_t::~Remote_t(this: &remote);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10062BD0
// Name: private: void CBaseClientState::ConnectInternal(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectInternal(
        CBaseClientState *this,
        const char *pchPublicAddress,
        const char *pchPrivateAddress,
        int numPlayers)
{
  ConVar *v5; // eax
  IConVar *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  bool (__thiscall *SetSignonState)(CBaseClientState *, int, int, NET_SignonState *); // eax

  v5 = g_pCVar->FindVar_2(this: g_pCVar, a2: "name");
  if ( v5 != nullptr )
  {
    v6 = &v5->IConVar;
    if ( v6 != nullptr )
      SetNameToSteamIDName(pConVar: v6);
  }
  CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::RemoveAll(this: &this->m_Remote.m_List);
  CAddressList::AddRemote(this: &this->m_Remote, pchAddress: pchPublicAddress, pchAlias: "public");
  CAddressList::AddRemote(this: &this->m_Remote, pchAddress: pchPrivateAddress, pchAlias: "private");
  if ( realtime <= this->m_DirectConnectLobby.m_flEndTime
    && CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&this->m_DirectConnectLobby.m_adrRemote) != nullptr
    && (this->m_DirectConnectLobby.m_unLobbyID == 0
     || LODWORD(this->m_DirectConnectLobby.m_unLobbyID) == LODWORD(this->m_nServerReservationCookie)
     && HIDWORD(this->m_DirectConnectLobby.m_unLobbyID) == HIDWORD(this->m_nServerReservationCookie))
    && CAddressList::IsAddressInList(this: &this->m_Remote, adr: &this->m_DirectConnectLobby.m_adrRemote) == 0 )
  {
    pchPublicAddress = (const char *)-16711936;
    v7 = netadr_s::ToString(this: &this->m_DirectConnectLobby.m_adrRemote, baseOnly: false);
    ConColorMsg(a1: (const struct Color *)&pchPublicAddress, a2: "Adding direct connect IP to connection %s\n", v7);
    v8 = netadr_s::ToString(this: &this->m_DirectConnectLobby.m_adrRemote, baseOnly: false);
    CAddressList::AddRemote(this: &this->m_Remote, pchAddress: v8, pchAlias: "direct");
  }
  SetSignonState = this->SetSignonState;
  this->m_nNumPlayersToConnect = numPlayers;
  SetSignonState(this, a2: 1, a3: -1, a4: nullptr);
  this->m_flConnectTime = -3.402823466385289e38;
  this->m_nRetryNumber = 0;
  this->m_nRetryMax = (int)(float)(cl_resend_timeout.m_pParent->m_Value.m_fValue / cl_resend.m_pParent->m_Value.m_fValue);
}

//------------------------------------------------------------------------------
// Address: 0x10062D00
// Name: public: virtual void CBaseClientState::Connect(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::Connect(
        CBaseClientState *this,
        const char *pchPublicAddress,
        const char *pchPrivateAddress)
{
  CBaseClientState::ConnectInternal(this, pchPublicAddress, pchPrivateAddress, numPlayers: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10062D20
// Name: public: virtual void CBaseClientState::ConnectSplitScreen(char const __near *,char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ConnectSplitScreen(
        CBaseClientState *this,
        const char *pchPublicAddress,
        const char *pchPrivateAddress,
        int numPlayers)
{
  CBaseClientState::ConnectInternal(this, pchPublicAddress, pchPrivateAddress, numPlayers);
}

//------------------------------------------------------------------------------
// Address: 0x10062D30
// Name: public: virtual void CBaseClientState::ReserveServer(struct netadr_s const __near &,struct netadr_s const __near &,unsigned __int64,class KeyValues __near *,class IMatchAsyncOperationCallback __near *,class IMatchAsyncOperation __near * __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::ReserveServer(
        CBaseClientState *this,
        netadr_s *netAdrPublic,
        netadr_s *netAdrPrivate,
        unsigned __int64 nServerReservationCookie,
        KeyValues *pKVGameSettings,
        IMatchAsyncOperationCallback *pCallback,
        int ppAsyncOperation)
{
  CBaseClientState::CAsyncOperation_ReserveServer *v8; // eax
  CBaseClientState::CAsyncOperation_ReserveServer *v9; // edi
  IMatchAsyncOperation **v10; // eax
  KeyValues *Copy; // eax
  const char *v12; // eax
  const char *v13; // eax
  const char *v14; // eax
  const char *v15; // eax

  NET_SetMultiplayer(multiplayer: true);
  if ( this->m_pServerReservationCallback != nullptr )
    this->HandleReservationResponse(
      this,
      a2: &this->m_netadrReserveServer.m_List.m_Memory.m_pMemory->m_adrRemote,
      a3: false);
  if ( ppAsyncOperation != 0 )
  {
    v8 = (CBaseClientState::CAsyncOperation_ReserveServer *)MemAlloc_Alloc(nSize: 0x18u);
    v9 = v8;
    if ( v8 != nullptr )
    {
      v8->__vftable = (CBaseClientState::CAsyncOperation_ReserveServer_vtbl *)&CBaseClientState::CAsyncOperation_ReserveServer::`vftable';
      v8->m_eState = AOS_RUNNING;
      netadr_s::SetIP(this: &v8->m_adr, unIP: 0);
      netadr_s::SetPort(this: &v9->m_adr, newport: 0);
      netadr_s::SetType(this: &v9->m_adr, newtype: NA_IP);
      v9->m_pParent = this;
    }
    else
    {
      v9 = nullptr;
    }
    v10 = (IMatchAsyncOperation **)ppAsyncOperation;
    this->m_pServerReservationOperation = v9;
    *v10 = v9;
  }
  this->m_pServerReservationCallback = pCallback;
  this->m_nServerReservationCookie = nServerReservationCookie;
  Copy = KeyValues::MakeCopy(this: pKVGameSettings);
  this->m_flReservationMsgSendTime = 1.175494350822288e-38;
  this->m_pKVGameSettings = Copy;
  this->m_nReservationMsgRetryNumber = 0;
  this->m_bEnteredPassword = false;
  CUtlVector<Remote_t,CUtlMemory<Remote_t,int>>::RemoveAll(this: &this->m_netadrReserveServer.m_List);
  v12 = netadr_s::ToString(this: netAdrPublic, baseOnly: false);
  CAddressList::AddRemote(this: &this->m_netadrReserveServer, pchAddress: v12, pchAlias: "public");
  if ( CCircularBuffer::GetReadAvailable(this: netAdrPrivate) == NA_IP )
  {
    v13 = netadr_s::ToString(this: netAdrPrivate, baseOnly: false);
    CAddressList::AddRemote(this: &this->m_netadrReserveServer, pchAddress: v13, pchAlias: "private");
  }
  if ( realtime <= this->m_DirectConnectLobby.m_flEndTime
    && CWaveDataStreamAsync::Source(this: (vgui::Tooltip *)&this->m_DirectConnectLobby.m_adrRemote) != nullptr
    && (this->m_DirectConnectLobby.m_unLobbyID == 0
     || LODWORD(this->m_DirectConnectLobby.m_unLobbyID) == LODWORD(this->m_nServerReservationCookie)
     && HIDWORD(this->m_DirectConnectLobby.m_unLobbyID) == HIDWORD(this->m_nServerReservationCookie))
    && CAddressList::IsAddressInList(this: &this->m_netadrReserveServer, adr: &this->m_DirectConnectLobby.m_adrRemote) == 0 )
  {
    ppAsyncOperation = -16711936;
    v14 = netadr_s::ToString(this: &this->m_DirectConnectLobby.m_adrRemote, baseOnly: false);
    ConColorMsg(a1: (const struct Color *)&ppAsyncOperation, a2: "Adding direct connect IP to reservation %s\n", v14);
    v15 = netadr_s::ToString(this: &this->m_DirectConnectLobby.m_adrRemote, baseOnly: false);
    CAddressList::AddRemote(this: &this->m_netadrReserveServer, pchAddress: v15, pchAlias: "direct");
  }
  CBaseClientState::SendReserveServerChallenge(this);
}

//------------------------------------------------------------------------------
// Address: 0x10062FC0
// Name: public: virtual char const __near * CBaseClientState::GetCDKeyHash(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CBaseClientState::GetCDKeyHash(CBaseClientState *this)
{
  return "123";
}

//------------------------------------------------------------------------------
// Address: 0x10062FD0
// Name: public: virtual char const __near * CBaseClientState::GetClientName(void)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CBaseClientState::GetClientName(CBaseClientState *this)
{
  char *result; // eax

  if ( (cl_name.m_nFlags & 0x1000) != 0 )
    return "FCVAR_NEVER_AS_STRING";
  result = cl_name.m_pParent->m_Value.m_pszString;
  if ( result == nullptr )
    return (char *)defaultValue;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10063000
// Name: public: virtual void CBaseClientState::SetServerReservationCookie(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseClientState::SetServerReservationCookie(
        CBaseClientState *this,
        unsigned __int64 nReservationCookie)
{
  this->m_nServerReservationCookie = nReservationCookie;
}

//------------------------------------------------------------------------------
// Address: 0x10063020
// Name: public: CBaseClientState::CBaseClientState(void)
// Source: json
//------------------------------------------------------------------------------
CBaseClientState *__thiscall CBaseClientState::CBaseClientState(CBaseClientState *this)
{
  this->IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&IConnectionlessPacketHandler::`vftable';
  this->IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&IServerMessageHandler::`vftable';
  this->INetChannelHandler::__vftable = (CBaseClientState_vtbl *)&CBaseClientState::`vftable'{for `INetChannelHandler'};
  this->IConnectionlessPacketHandler::__vftable = (IConnectionlessPacketHandler_vtbl *)&CBaseClientState::`vftable'{for `IConnectionlessPacketHandler'};
  this->IServerMessageHandler::INetMessageHandler::__vftable = (IServerMessageHandler_vtbl *)&CBaseClientState::`vftable'{for `IServerMessageHandler'};
  this->m_Remote.m_List.m_Memory.m_pMemory = nullptr;
  this->m_Remote.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_Remote.m_List.m_Memory.m_nGrowSize = 0;
  this->m_Remote.m_List.m_Size = 0;
  this->m_Remote.m_List.m_pElements = nullptr;
  this->m_DirectConnectLobby.m_flEndTime = -1.0;
  netadr_s::SetIP(this: &this->m_DirectConnectLobby.m_adrRemote, unIP: 0);
  netadr_s::SetPort(this: &this->m_DirectConnectLobby.m_adrRemote, newport: 0);
  netadr_s::SetType(this: &this->m_DirectConnectLobby.m_adrRemote, newtype: NA_IP);
  this->m_DirectConnectLobby.m_unLobbyID = 0;
  CClockDriftMgr::CClockDriftMgr(this: &this->m_ClockDriftMgr);
  this->m_netadrReserveServer.m_List.m_Memory.m_pMemory = nullptr;
  this->m_netadrReserveServer.m_List.m_Memory.m_nAllocationCount = 0;
  this->m_netadrReserveServer.m_List.m_Memory.m_nGrowSize = 0;
  this->m_netadrReserveServer.m_List.m_Size = 0;
  this->m_netadrReserveServer.m_List.m_pElements = nullptr;
  netadr_s::SetIP(this: &this->m_DeferredConnection.m_adrServerAddress, unIP: 0);
  netadr_s::SetPort(this: &this->m_DeferredConnection.m_adrServerAddress, newport: 0);
  netadr_s::SetType(this: &this->m_DeferredConnection.m_adrServerAddress, newtype: NA_IP);
  this->m_DeferredConnection.m_nChallenge = 0;
  this->m_DeferredConnection.m_nAuthprotocol = 0;
  this->m_DeferredConnection.m_unGSSteamID = 0;
  this->m_DeferredConnection.m_unLobbyID = 0;
  *(_WORD *)&this->m_DeferredConnection.m_bActive = 0;
  this->m_DeferredConnection.m_bRequiresPassword = false;
  *(_DWORD *)this->m_DeferredConnection.m_chLobbyType = 0;
  *(_DWORD *)&this->m_DeferredConnection.m_chLobbyType[4] = 0;
  *(_DWORD *)&this->m_DeferredConnection.m_chLobbyType[8] = 0;
  *(_DWORD *)&this->m_DeferredConnection.m_chLobbyType[12] = 0;
  this->m_flConnectTime = 0.0;
  this->m_bSplitScreenUser = false;
  this->m_Socket = 0;
  this->m_pServerClasses = nullptr;
  this->m_StringTableContainer = nullptr;
  this->m_NetChannel = nullptr;
  this->m_nSignonState = 0;
  this->m_nChallengeNr = 0;
  this->m_nRetryNumber = 0;
  this->m_nRetryMax = 4;
  this->m_nServerCount = 0;
  this->m_nCurrentSequence = 0;
  this->m_nDeltaTick = 0;
  this->m_bPaused = false;
  this->m_nViewEntity = 0;
  this->m_nPlayerSlot = 0;
  this->m_nSplitScreenSlot = 0;
  this->m_nMaxClients = 0;
  this->m_nNumPlayersToConnect = 1;
  _V_memset(dest: this->m_pEntityBaselines, fill: 0, count: 0x4000);
  this->m_flNextCmdTime = -1.0;
  this->m_nServerClasses = 0;
  this->m_nServerClassBits = 0;
  this->m_ListenServerSteamID = 0;
  _V_memset(dest: this->m_szLevelName, fill: 0, count: 40);
  _V_memset(dest: this->m_szLevelNameShort, fill: 0, count: 40);
  _V_memset(dest: this->m_szLastLevelNameShort, fill: 0, count: 40);
  this->m_iEncryptionKeySize = 0;
  _V_memset(dest: this->m_szEncryptionKey, fill: 0, count: 2048);
  this->m_flReservationMsgSendTime = 0.0;
  this->m_bServerInfoProcessed = false;
  this->m_pServerReservationOperation = nullptr;
  this->m_pServerReservationCallback = nullptr;
  this->m_nReservationMsgRetryNumber = 0;
  *(_WORD *)&this->m_bEnteredPassword = 0;
  this->m_bWaitingForServerGameDetails = false;
  this->m_nServerReservationCookie = 0;
  this->m_pKVGameSettings = nullptr;
  *(_WORD *)&this->m_bRestrictServerCommands = 257;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1008A040
// Name: public: virtual int SVC_SetPause::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_SetPause::GetType(SVC_SetPause *this)
{
  return 11;
}

//------------------------------------------------------------------------------
// Address: 0x1009D660
// Name: public: virtual unsigned int CLC_ListenEvents::GetSize(void)const
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CLC_ListenEvents::GetSize(CLC_ListenEvents *this)
{
  return 80;
}

//------------------------------------------------------------------------------
// Address: 0x1009DDF0
// Name: public: virtual int SVC_PaintmapData::GetGroup(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall SVC_PaintmapData::GetGroup(SVC_PaintmapData *this)
{
  return 14;
}

//------------------------------------------------------------------------------
// Address: 0x101174C0
// Name: public: virtual bool SVC_SendTable::Process(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall SVC_SendTable::Process(SVC_SendTable *this)
{
  return this->m_pMessageHandler->ProcessSendTable(this: this->m_pMessageHandler, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x1012F830
// Name: public: virtual int NET_Tick::GetType(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall NET_Tick::GetType(SVC_Prefetch *this)
{
  return 4;
}

//------------------------------------------------------------------------------
// Address: 0x102735C0
// Name: public: bool netadr_s::operator<(struct netadr_s const __near &)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall netadr_s::operator<(netadr_s *this, const netadr_s *netadr)
{
  unsigned int v2; // edx
  unsigned int v3; // eax

  v2 = *(_DWORD *)this->ip;
  v3 = *(_DWORD *)netadr->ip;
  if ( v3 < v2 )
    return true;
  if ( v3 <= v2 )
    return netadr->port < this->port;
  return false;
}

} // namespace engine_xlsp
