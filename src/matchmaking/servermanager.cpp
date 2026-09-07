// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: matchmaking/servermanager.cpp
// Functions: 12
// ============================================================

#include "matchmaking\servermanager.h"

//------------------------------------------------------------------------------
// Address: 0x10002960
// Name: public: virtual unsigned __int64 CServer::GetOnlineId(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CServer::GetOnlineId(CServer *this)
{
  return this->m_xuid;
}

//------------------------------------------------------------------------------
// Address: 0x10002970
// Name: public: virtual bool CServer::IsJoinable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CServer::IsJoinable(CServer *this)
{
  return this->m_pGameDetails != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100029C0
// Name: public: virtual void CServer::Join(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServer::Join(CServer *this)
{
  const char *String; // eax
  IVEngineClient *m_pIVEngineClient; // esi
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+0h] [ebp-100h] BYREF

  String = KeyValues::GetString(this: this->m_pGameDetails, keyName: "Server/connectstring", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "connect %s\n", String);
    m_pIVEngineClient->ClientCmd(this: m_pIVEngineClient, a2: v3->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002A10
// Name: public: virtual int CServerManager::GetNumServers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerManager::GetNumServers(CServerManager *this)
{
  return this->m_Servers.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x10002A20
// Name: public: virtual class IMatchServer __near * CServerManager::GetServerByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServerManager::GetServerByIndex(CServerManager *this, int iServerIdx)
{
  if ( iServerIdx < 0 || iServerIdx >= this->m_Servers.m_Size )
    return nullptr;
  else
    return this->m_Servers.m_Memory.m_pMemory[iServerIdx];
}

//------------------------------------------------------------------------------
// Address: 0x10002A40
// Name: protected: class CServer __near * CServerManager::GetServerRecordByOnlineId(class CUtlVector<class CServer __near *,class CUtlMemory<class CServer __near *,int>> __near &,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServerManager::GetServerRecordByOnlineId(
        CServerManager *this,
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *arr,
        unsigned __int64 xuidServerOnline)
{
  int v3; // edi
  CServer *v4; // esi
  __int64 v5; // rax

  v3 = 0;
  if ( arr->m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = arr->m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      LODWORD(v5) = v4->GetOnlineId(this: arr->m_Memory.m_pMemory[v3]);
      if ( v5 == xuidServerOnline )
        break;
    }
    if ( ++v3 >= arr->m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x10002A90
// Name: public: virtual class IMatchServer __near * CServerManager::GetServerByOnlineId(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServerManager::GetServerByOnlineId(CServerManager *this, unsigned __int64 xuidServerOnline)
{
  return CServerManager::GetServerRecordByOnlineId(this, arr: &this->m_Servers, xuidServerOnline);
}

//------------------------------------------------------------------------------
// Address: 0x10002AB0
// Name: protected: void CServerManager::RemoveOldServers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::RemoveOldServers(CServerManager *this)
{
  int i; // edi
  CServer *v3; // eax

  for ( i = 0; i < this->m_Servers.m_Size; ++i )
  {
    v3 = this->m_Servers.m_Memory.m_pMemory[i];
    if ( v3 == nullptr || v3->m_bNeedsUpdate )
    {
      if ( this->m_Servers.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &this->m_Servers.m_Memory.m_pMemory[i],
          src: &this->m_Servers.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_Servers.m_Size - i - 1));
      --this->m_Servers.m_Size;
      --i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002C40
// Name: protected: void CServerManager::OnAllDataFetched(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::OnAllDataFetched(CServerManager *this)
{
  double v2; // st7
  bool v3; // zf
  KeyValues *v4; // eax
  KeyValues *v5; // esi
  IMatchEventsSubscription *v6; // eax
  int m_nValue; // [esp+4h] [ebp-4h]

  _DevMsg(a1: 2, a2: "Server manager refresh completed.\n");
  this->m_eState = 0;
  m_nValue = mm_server_search_update_interval.m_pParent->m_Value.m_nValue;
  v2 = _Plat_FloatTime();
  v3 = !this->m_bUpdateEnabled;
  this->m_flNextUpdateTime = v2 + (double)m_nValue;
  if ( v3 )
  {
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_Servers);
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
  }
  else
  {
    CServerManager::RemoveOldServers(this);
  }
  v4 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v4 != nullptr )
    v5 = KeyValues::KeyValues(
           this: v4,
           setName: "OnMatchServerMgrUpdate",
           firstKey: "update",
           firstValue: "searchfinished");
  else
    v5 = nullptr;
  v6 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v6->BroadcastEvent(this: v6, a2: v5);
}

//------------------------------------------------------------------------------
// Address: 0x10002D30
// Name: public: virtual void CServerManager::EnableServersUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::EnableServersUpdate(CServerManager *this, bool bEnable)
{
  this->m_bUpdateEnabled = bEnable;
  this->m_flNextUpdateTime = 0.0;
  if ( !bEnable )
  {
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_Servers);
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
    CServerManager::OnAllDataFetched(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002D70
// Name: public: virtual void CServerManager::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CServerManager::OnEvent(
        CServerManager *this@<ecx>,
        int a2@<ebp>,
        KeyValues *pEvent,
        CUtlSymbolTable::StringPool_t *src)
{
  const char *Name; // edi
  unsigned int i; // edi
  KeyValues *Key; // ebp
  KeyValues *v8; // eax
  KeyValues *v9; // ebp
  double Float; // st7
  int v11; // eax
  IMatchNetworkMsgController *v12; // eax
  KeyValues *v13; // eax
  KeyValues *v14; // esi
  KeyValues *v15; // eax
  const char *v16; // eax
  unsigned __int64 Uint64; // rax
  CUtlVector<CServer *,CUtlMemory<CServer *,int> > *p_m_pElements; // edi
  KeyValues *ServerRecordByOnlineId; // eax
  KeyValues *v20; // esi
  const char *v21; // eax
  const char *v22; // esi
  unsigned __int64 v23; // rax
  unsigned int v24; // edi
  unsigned int v25; // ebp
  unsigned int v26; // ebx
  KeyValues *Copy; // edi
  KeyValues *v28; // eax
  KeyValues *v29; // esi
  const char *v30; // eax
  int v31; // esi
  _DWORD *v32; // eax
  CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *v33; // ecx
  int Int; // eax
  KeyValues *v35; // eax
  KeyValues *v36; // esi
  IMatchEventsSubscription *v37; // eax
  KeyValues *v38; // eax
  KeyValues *v39; // esi
  const char *String; // eax
  const char *v41; // eax
  int defaultValue; // [esp+0h] [ebp-60h]
  int value; // [esp+14h] [ebp-4Ch]
  KeyValues *pGameDetailsServer; // [esp+1Ch] [ebp-44h] BYREF
  netadr_s netAddress; // [esp+20h] [ebp-40h] BYREF
  INetSupport::ServerInfo_t v48; // [esp+2Ch] [ebp-34h] BYREF

  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnNetLanConnectionlessPacket") != 0 )
  {
    if ( _V_stricmp(s1: "Client::ResendGameDetailsRequest", s2: Name) == 0 )
    {
      v38 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v39 = v38 != nullptr ? KeyValues::KeyValues(this: v38, setName: "ConnectServerDetailsRequest") : nullptr;
      String = KeyValues::GetString(this: pEvent, keyName: "to", defaultValue: str);
      KeyValues::SetString(this: v39, keyName: "server", value: String);
      v41 = KeyValues::GetString(this: pEvent, keyName: "to", defaultValue: str);
      CConnectionlessLanMgr::SendPacket(this: g_pConnectionlessLanMgr, pMsg: v39, szAddress: v41, eSock: NS_SOCK_CLIENT);
      if ( v39 != nullptr )
        KeyValues::deleteThis(this: v39);
    }
  }
  else
  {
    *(_DWORD *)netAddress.ip = "LanSearchServerPing";
    *(_DWORD *)&netAddress.port = "ConnectServerDetailsRequest";
    v48.m_netAdr.type = (netadrtype_t)"InetSearchServerDetails";
    for ( i = 0; i < 3; ++i )
    {
      Key = KeyValues::FindKey(this: pEvent, keyName: *(const char **)&netAddress.ip[4 * i], bCreate: false);
      if ( Key != nullptr )
      {
        v12 = g_pMatchFramework->GetMatchNetworkMsgController(this: g_pMatchFramework);
        v13 = v12->GetActiveServerGameDetails(this: v12, a2: pEvent);
        v14 = v13;
        if ( v13 != nullptr )
        {
          if ( KeyValues::FindKey(this: v13, keyName: "Server", bCreate: false) != nullptr )
          {
            v15 = KeyValues::FindKey(this: v14, keyName: *(const char **)&netAddress.ip[4 * i], bCreate: true);
            KeyValues::MergeFrom(this: v15, kvMerge: Key, eOp: MERGE_KV_UPDATE);
            v16 = KeyValues::GetString(this: pEvent, keyName: "from", defaultValue: str);
            CConnectionlessLanMgr::SendPacket(
              this: g_pConnectionlessLanMgr,
              pMsg: v14,
              szAddress: v16,
              eSock: NS_SOCK_SERVER);
          }
          KeyValues::deleteThis(this: v14);
        }
        return;
      }
    }
    v8 = KeyValues::FindKey(this: pEvent, keyName: "GameDetailsServer", bCreate: false);
    v9 = v8;
    netAddress.type = (netadrtype_t)v8;
    if ( v8 == nullptr )
      return;
    value = 0;
    Float = KeyValues::GetFloat(this: v8, keyName: "LanSearchServerPing/timestamp", defaultValue: 0.0);
    *(float *)&pGameDetailsServer = Float;
    if ( Float != 0.0 )
    {
      v11 = (int)((_Plat_FloatTime() - *(float *)&pGameDetailsServer) * 1000.0);
      value = v11;
      if ( v11 >= 0 )
      {
        if ( v11 >= 1000 )
          value = 999;
      }
      else
      {
        value = 0;
      }
LABEL_18:
      v21 = KeyValues::GetString(this: v9, keyName: "Server/adronline", defaultValue: nullptr);
      v22 = v21;
      if ( v21 != nullptr && *v21 != 0 )
      {
        netadr_s::SetIP(this: (netadr_s *)netAddress.ip, unIP: 0);
        netadr_s::SetPort(this: (netadr_s *)netAddress.ip, newport: 0);
        netadr_s::SetType(this: (netadr_s *)netAddress.ip, newtype: NA_IP);
        netadr_s::SetType(this: (netadr_s *)netAddress.ip, newtype: NA_IP);
        netadr_s::SetPort(this: (netadr_s *)netAddress.ip, newport: 0x6987u);
        netadr_s::SetFromString(this: (netadr_s *)netAddress.ip, pch: v22, bUseDNS: false);
        INetSupport::ServerInfo_t::ServerInfo_t(this: (INetSupport::ServerInfo_t *)v48.m_netAdr.ip);
        g_pMatchExtensions->m_exts.m_pINetSupport->GetServerInfo(
          this: g_pMatchExtensions->m_exts.m_pINetSupport,
          a2: (INetSupport::ServerInfo_t *)v48.m_netAdr.ip);
        if ( !v48.m_bInMainMenuBkgnd
          || !netadr_s::CompareAdr(
                this: (netadr_s *)v48.m_netAdr.ip,
                a: (const netadr_s *)netAddress.ip,
                onlyBase: false)
          && !netadr_s::CompareAdr(
                this: (netadr_s *)v48.m_netAdrOnline.ip,
                a: (const netadr_s *)netAddress.ip,
                onlyBase: false) )
        {
          v23 = (unsigned __int64)netadr_s::GetPort(this: (netadr_s *)netAddress.ip) << 32;
          v24 = HIDWORD(v23);
          v25 = v23 | netadr_s::GetIP(this: (netadr_s *)netAddress.ip);
          v26 = v24;
          Copy = KeyValues::MakeCopy(this: (KeyValues *)netAddress.type);
          KeyValues::SetName(this: Copy, setName: "Settings");
          v28 = KeyValues::FindKey(this: Copy, keyName: "LanSearch", bCreate: false);
          v29 = v28;
          if ( v28 != nullptr )
          {
            KeyValues::RemoveSubKey(this: Copy, subKey: v28);
            KeyValues::deleteThis(this: v29);
          }
          KeyValues::SetInt(this: Copy, keyName: "Server/ping", value);
          v30 = KeyValues::GetString(this: pEvent, keyName: "from", defaultValue: nullptr);
          if ( v30 != nullptr )
            KeyValues::SetString(this: Copy, keyName: "Server/connectstring", value: v30);
          v31 = (*(int (__thiscall **)(char *, unsigned int, unsigned int, int))(*((_DWORD *)this - 1) + 12))(
                  a1: (char *)this - 4,
                  a2: v25,
                  a3: v26,
                  a4: a2);
          if ( v31 == 0 )
          {
            v32 = operator new(nSize: 0x18u);
            if ( v32 != nullptr )
            {
              v32[2] = 0;
              v32[3] = 0;
              v32[4] = 0;
              *v32 = &CServer::`vftable';
              *((_BYTE *)v32 + 4) = 0;
              v31 = (int)v32;
            }
            v33 = (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)pGameDetailsServer;
            *(_DWORD *)(v31 + 8) = v25;
            v33 = (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)((char *)v33 + 12);
            *(_DWORD *)(v31 + 12) = v26;
            defaultValue = v33->m_Size;
            src = (CUtlSymbolTable::StringPool_t *)v31;
            CUtlVector<IMatchEventsSink *,CUtlMemory<IMatchEventsSink *,int>>::InsertBefore(
              this: v33,
              elem: defaultValue,
              &src);
          }
          if ( *(_DWORD *)(v31 + 16) != 0 )
          {
            Int = KeyValues::GetInt(this: *(KeyValues **)(v31 + 16), keyName: "Server/ping", defaultValue: 0);
            if ( Int < (int)this )
              KeyValues::SetInt(this: Copy, keyName: "Server/ping", value: ((int)this + 8 * Int + Int) / 10);
            KeyValues::deleteThis(this: *(KeyValues **)(v31 + 16));
          }
          *(_DWORD *)(v31 + 16) = Copy;
          *(_BYTE *)(v31 + 4) = 0;
          v35 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v35 != nullptr )
            v36 = KeyValues::KeyValues(
                    this: v35,
                    setName: "OnMatchServerMgrUpdate",
                    firstKey: "update",
                    firstValue: "server");
          else
            v36 = nullptr;
          KeyValues::SetUint64(this: v36, keyName: "xuid", value: __PAIR64__(v26, v25));
          v37 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
          v37->BroadcastEvent(this: v37, a2: v36);
        }
      }
      return;
    }
    Uint64 = KeyValues::GetUint64(this: v9, keyName: "InetSearchServerDetails/pingxuid", defaultValue: 0);
    if ( Uint64 != 0 )
    {
      p_m_pElements = (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&this->m_Servers.m_pElements;
      ServerRecordByOnlineId = (KeyValues *)CServerManager::GetServerRecordByOnlineId(
                                              this: (CServerManager *)((char *)this - 4),
                                              arr: (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&this->m_Servers.m_pElements,
                                              xuidServerOnline: Uint64);
      v20 = ServerRecordByOnlineId;
      if ( ServerRecordByOnlineId == nullptr )
        return;
      pGameDetailsServer = ServerRecordByOnlineId;
      CUtlVector<CServer *,CUtlMemory<CServer *,int>>::FindAndFastRemove(
        this: p_m_pElements,
        src: (CServer **)&pGameDetailsServer);
      (*(void (__thiscall **)(KeyValues *, int))(v20->m_iKeyName + 16))(a1: v20, a2: 1);
      goto LABEL_18;
    }
    if ( KeyValues::GetString(this: v9, keyName: "ConnectServerDetailsRequest/server", defaultValue: str) != nullptr )
      g_pMatchExtensions->m_exts.m_pINetSupport->OnMatchEvent(
        this: g_pMatchExtensions->m_exts.m_pINetSupport,
        a2: pEvent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100080B0
// Name: public: virtual class KeyValues __near * CServer::GetGameDetails(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServer::GetGameDetails(ConCommandBase *this)
{
  return this->m_pszHelpString;
}

// ============================================================
// Overlay from matchmaking (Missing functions)
// ============================================================
namespace matchmaking {

//------------------------------------------------------------------------------
// Address: 0x1001CB80
// Name: public: char const __near * servernetadr_t::GetConnectionAddressString(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall servernetadr_t::GetConnectionAddressString(servernetadr_t *this)
{
  char *result; // eax

  V_snprintf(
    pDest: &`servernetadr_t::ToString'::`2'::s[64 * `servernetadr_t::ToString'::`2'::nBuf],
    maxLen: 64,
    pFormat: "%u.%u.%u.%u:%i",
    HIBYTE(this->m_unIP),
    (unsigned __int8)BYTE2(this->m_unIP),
    BYTE1(this->m_unIP),
    (unsigned __int8)this->m_unIP,
    this->m_usConnectionPort);
  result = &`servernetadr_t::ToString'::`2'::s[64 * `servernetadr_t::ToString'::`2'::nBuf];
  `servernetadr_t::ToString'::`2'::nBuf = ((_BYTE)`servernetadr_t::ToString'::`2'::nBuf + 1) & 3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001CBE0
// Name: public: gameserveritem_t::gameserveritem_t(void)
// Source: json
//------------------------------------------------------------------------------
gameserveritem_t *__thiscall gameserveritem_t::gameserveritem_t(gameserveritem_t *this)
{
  *((_DWORD *)&this->m_steamID.m_steamid.m_comp + 1) &= 0xFF0FFFFF;
  HIBYTE(this->m_steamID.m_steamid.m_unAll64Bits) = 0;
  *((_DWORD *)&this->m_steamID.m_steamid.m_comp + 1) &= 0xFFF00000;
  *(_DWORD *)&this->m_steamID.m_steamid.m_comp = 0;
  this->m_szServerName[0] = 0;
  this->m_szGameDescription[0] = 0;
  this->m_szMap[0] = 0;
  *(_WORD *)&this->m_bPassword = 0;
  *(_WORD *)&this->m_bDoNotRefresh = 0;
  this->m_bHadSuccessfulResponse = false;
  this->m_nServerVersion = 0;
  this->m_ulTimeLastPlayed = 0;
  this->m_nBotPlayers = 0;
  this->m_nMaxPlayers = 0;
  this->m_nPlayers = 0;
  this->m_nAppID = 0;
  this->m_nPing = 0;
  this->m_szGameTags[0] = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001CC50
// Name: public: class gameserveritem_t __near & gameserveritem_t::operator=(class gameserveritem_t const __near &)
// Source: json
//------------------------------------------------------------------------------
gameserveritem_t *__thiscall gameserveritem_t::operator=(gameserveritem_t *this, const gameserveritem_t *__that)
{
  gameserveritem_t *result; // eax
  char *m_szGameDir; // edi
  int v4; // esi
  int i; // edx
  char *m_szMap; // edi
  int j; // edx
  char *m_szGameDescription; // edi
  int k; // edx
  char *m_szServerName; // edi
  int m; // edx
  char *m_szGameTags; // edi
  int n; // edx

  result = this;
  this->m_NetAdr = __that->m_NetAdr;
  this->m_nPing = __that->m_nPing;
  this->m_bHadSuccessfulResponse = __that->m_bHadSuccessfulResponse;
  this->m_bDoNotRefresh = __that->m_bDoNotRefresh;
  m_szGameDir = this->m_szGameDir;
  v4 = (char *)__that - (char *)this;
  for ( i = 32; i != 0; --i )
  {
    *m_szGameDir = m_szGameDir[v4];
    ++m_szGameDir;
  }
  m_szMap = this->m_szMap;
  for ( j = 32; j != 0; --j )
  {
    *m_szMap = m_szMap[v4];
    ++m_szMap;
  }
  m_szGameDescription = this->m_szGameDescription;
  for ( k = 64; k != 0; --k )
  {
    *m_szGameDescription = m_szGameDescription[v4];
    ++m_szGameDescription;
  }
  this->m_nAppID = __that->m_nAppID;
  this->m_nPlayers = __that->m_nPlayers;
  this->m_nMaxPlayers = __that->m_nMaxPlayers;
  this->m_nBotPlayers = __that->m_nBotPlayers;
  this->m_bPassword = __that->m_bPassword;
  this->m_bSecure = __that->m_bSecure;
  this->m_ulTimeLastPlayed = __that->m_ulTimeLastPlayed;
  this->m_nServerVersion = __that->m_nServerVersion;
  m_szServerName = this->m_szServerName;
  for ( m = 64; m != 0; --m )
  {
    *m_szServerName = m_szServerName[v4];
    ++m_szServerName;
  }
  m_szGameTags = this->m_szGameTags;
  for ( n = 128; n != 0; --n )
  {
    *m_szGameTags = m_szGameTags[v4];
    ++m_szGameTags;
  }
  this->m_steamID.m_steamid.m_unAll64Bits = __that->m_steamID.m_steamid.m_unAll64Bits;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1001CD70
// Name: public: virtual void CServerManager::RefreshComplete(void __near *,enum EMatchMakingServerResponse)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::RefreshComplete(CServerManager *this, void *hReq, EMatchMakingServerResponse response)
{
  if ( this->m_ServersPinging.m_pElements == (CServer **)3 )
    this->m_ServersPinging.m_pElements = (CServer **)4;
  steamapicontext->m_pSteamMatchmakingServers->ReleaseRequest(
    this: steamapicontext->m_pSteamMatchmakingServers,
    a2: this->IMatchEventsSink::__vftable);
  this->IMatchEventsSink::__vftable = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1001CDA0
// Name: public: CServer::CServer(void)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServer::CServer(CServer *this)
{
  this->__vftable = (CServer_vtbl *)&CServer::`vftable';
  this->m_flLastRefresh = _Plat_FloatTime();
  this->m_xuid = 0;
  this->m_pGameDetails = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001CDD0
// Name: public: CServerPinging::CServerPinging(void)
// Source: json
//------------------------------------------------------------------------------
CServerPinging *__thiscall CServerPinging::CServerPinging(CServerPinging *this)
{
  this->__vftable = (CServerPinging_vtbl *)&CServer::`vftable';
  this->m_flLastRefresh = _Plat_FloatTime();
  this->m_xuid = 0;
  this->m_pGameDetails = nullptr;
  this->__vftable = (CServerPinging_vtbl *)&CServerPinging::`vftable';
  gameserveritem_t::gameserveritem_t(this: &this->m_gsi);
  this->m_flTimeout = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1001CE50
// Name: public: virtual void CServer::Join(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServer::Join(CServer *this)
{
  const char *String; // eax
  IVEngineClient *m_pIVEngineClient; // esi
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+0h] [ebp-10Ch] BYREF

  String = KeyValues::GetString(this: this->m_pGameDetails, keyName: "server/connectstring", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "connect %s\n", String);
    m_pIVEngineClient->ClientCmd(this: m_pIVEngineClient, a2: v3->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001CEB0
// Name: public: virtual class IMatchServer __near * CServerManager::GetServerByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServerManager::GetServerByIndex(CServerManager *this, int iServerIdx)
{
  if ( iServerIdx < 0 || iServerIdx >= this->m_Servers.m_Size )
    return nullptr;
  else
    return this->m_Servers.m_Memory.m_pMemory[iServerIdx];
}

//------------------------------------------------------------------------------
// Address: 0x1001CED0
// Name: protected: void CServerManager::UpdateLanSearch(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __thiscall CServerManager::UpdateLanSearch(CServerManager *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  char *v4; // eax
  char *m_pszString; // eax
  int i; // esi
  int v7; // eax
  CFmtStrN<256> *v8; // eax
  CFmtStrN<256> v9; // [esp+Ch] [ebp-128h] BYREF
  CSplitString arrPorts; // [esp+118h] [ebp-1Ch] BYREF
  float m_fValue; // [esp+130h] [ebp-4h]

  if ( this->m_lanSearchData.m_flStartTime == 0.0 || this->m_lanSearchData.m_flLastBroadcastTime == 0.0 )
  {
    this->m_lanSearchData.m_flStartTime = _Plat_FloatTime();
LABEL_8:
    this->m_lanSearchData.m_flLastBroadcastTime = _Plat_FloatTime();
    v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v2 != nullptr )
      v3 = KeyValues::KeyValues(this: v2, setName: "LanSearchServerPing");
    else
      v3 = nullptr;
    *(float *)&arrPorts.m_pElements = _Plat_FloatTime();
    KeyValues::SetFloat(this: v3, keyName: "timestamp", value: *(float *)&arrPorts.m_pElements);
    if ( (mm_server_search_lan_ports.m_nFlags & 0x1000) != 0
      || (v4 = mm_server_search_lan_ports.m_pParent->m_Value.m_pszString) != nullptr && *v4 != 0 )
    {
      if ( (mm_server_search_lan_ports.m_nFlags & 0x1000) != 0 )
      {
        m_pszString = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        m_pszString = mm_server_search_lan_ports.m_pParent->m_Value.m_pszString;
        if ( m_pszString == nullptr )
          m_pszString = (char *)defaultValue;
      }
      CSplitString::CSplitString(this: &arrPorts, pString: m_pszString, pSeparator: ",");
      for ( i = 0; i < arrPorts.m_Size; ++i )
      {
        v7 = V_atoi(str: arrPorts.m_Memory.m_pMemory[i]);
        if ( v7 > 0 )
        {
          v8 = CFmtStrN<256>::CFmtStrN<256>(this: &v9, pszFormat: "*:%d", v7);
          CConnectionlessLanMgr::SendPacket(
            this: g_pConnectionlessLanMgr,
            pMsg: v3,
            szAddress: v8->m_szBuf,
            eSock: NS_SOCK_CLIENT);
        }
      }
      CSplitString::~CSplitString(this: &arrPorts);
    }
    if ( v3 != nullptr )
      KeyValues::deleteThis(this: v3);
    return;
  }
  m_fValue = mm_server_search_lan_ping_duration.m_pParent->m_Value.m_fValue;
  if ( _Plat_FloatTime() > m_fValue + this->m_lanSearchData.m_flStartTime )
  {
    this->m_eState = STATE_GROUP_SEARCH;
    return;
  }
  m_fValue = mm_server_search_lan_ping_interval.m_pParent->m_Value.m_fValue;
  if ( m_fValue + this->m_lanSearchData.m_flLastBroadcastTime <= _Plat_FloatTime() )
    goto LABEL_8;
}

//------------------------------------------------------------------------------
// Address: 0x1001D040
// Name: protected: bool CServerManager::FetchGroupServers(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerManager::FetchGroupServers(CServerManager *this)
{
  int m_idxSearchGroupId; // eax
  unsigned int v3; // ebx
  const char *v4; // ecx
  char *m_szBuf; // edi
  char *ModDirectory; // edi
  IMatchTitle *v7; // eax
  ISteamMatchmakingServers *m_pSteamMatchmakingServers; // edi
  int v9; // eax
  CFmtStrN<256> v11; // [esp+Ch] [ebp-594h] BYREF
  MatchMakingKeyValuePair_t filters[2]; // [esp+118h] [ebp-488h] BYREF
  char gamedataFitler[128]; // [esp+518h] [ebp-88h] BYREF
  ISteamMatchmakingServers_vtbl *v14; // [esp+598h] [ebp-8h]
  MatchMakingKeyValuePair_t *pFilter; // [esp+59Ch] [ebp-4h] BYREF

  m_idxSearchGroupId = this->m_groupSearchData.m_idxSearchGroupId;
  gamedataFitler[0] = 0;
  v3 = 115;
  if ( m_idxSearchGroupId < this->m_groupSearchData.m_UserGroupAccountIDs.m_Size )
  {
    do
    {
      v4 = ",grp:%ui";
      if ( gamedataFitler[0] == 0 )
        v4 = "grp:%ui";
      m_szBuf = CFmtStrN<256>::CFmtStrN<256>(
                  this: &v11,
                  pszFormat: v4,
                  this->m_groupSearchData.m_UserGroupAccountIDs.m_Memory.m_pMemory[this->m_groupSearchData.m_idxSearchGroupId])->m_szBuf;
      if ( v3 < strlen(m_szBuf) )
        break;
      V_strncat(pDest: gamedataFitler, pSrc: m_szBuf, destBufferSize: 0x80u, max_chars_to_copy: -1);
      ++this->m_groupSearchData.m_idxSearchGroupId;
      v3 -= strlen(m_szBuf);
    }
    while ( this->m_groupSearchData.m_idxSearchGroupId < this->m_groupSearchData.m_UserGroupAccountIDs.m_Size );
  }
  ModDirectory = COM_GetModDirectory();
  V_strncpy(pDest: filters[0].m_szKey, pSrc: "gamedir", maxLen: 256);
  V_strncpy(pDest: filters[0].m_szValue, pSrc: ModDirectory, maxLen: 256);
  V_strncpy(pDest: filters[1].m_szKey, pSrc: "gamedataor", maxLen: 256);
  V_strncpy(pDest: filters[1].m_szValue, pSrc: gamedataFitler, maxLen: 256);
  this->m_eState = STATE_FETCHING_SERVERS;
  this->m_lanSearchData.m_flLastBroadcastTime = _Plat_FloatTime();
  pFilter = filters;
  _DevMsg(a1: 2, a2: "Requesting group server list for groups %s...\n", gamedataFitler);
  if ( this->m_hRequest != nullptr )
    steamapicontext->m_pSteamMatchmakingServers->ReleaseRequest(
      this: steamapicontext->m_pSteamMatchmakingServers,
      a2: this->m_hRequest);
  v7 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
  m_pSteamMatchmakingServers = steamapicontext->m_pSteamMatchmakingServers;
  v14 = m_pSteamMatchmakingServers->__vftable;
  v9 = ((int (__thiscall *)(IMatchTitle *, MatchMakingKeyValuePair_t **, int, ISteamMatchmakingServerListResponse *))v7->GetTitleID)(
         a1: v7,
         a2: &pFilter,
         a3: 2,
         a4: &this->ISteamMatchmakingServerListResponse);
  this->m_hRequest = (void *)((int (__thiscall *)(ISteamMatchmakingServers *, int))v14->RequestInternetServerList)(
                               a1: m_pSteamMatchmakingServers,
                               a2: v9);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1001D1D0
// Name: public: virtual class IMatchServer __near * CServerManager::GetServerByOnlineId(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServerManager::GetServerByOnlineId(CServerManager *this, unsigned __int64 xuidServerOnline)
{
  return CSearchManager::GetResultById(this, arr: &this->m_Servers, xuidServerOnline);
}

//------------------------------------------------------------------------------
// Address: 0x1001D1F0
// Name: protected: void CServerManager::RemoveOldServers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::RemoveOldServers(CServerManager *this)
{
  int i; // edi
  CServer *v3; // eax
  float now; // [esp+8h] [ebp-4h]

  now = _Plat_FloatTime();
  for ( i = 0; i < this->m_Servers.m_Size; ++i )
  {
    v3 = this->m_Servers.m_Memory.m_pMemory[i];
    if ( v3 == nullptr
      || mm_server_search_server_lifetime.m_pParent->m_Value.m_fValue <= (float)(now - v3->m_flLastRefresh) )
    {
      if ( this->m_Servers.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &this->m_Servers.m_Memory.m_pMemory[i],
          src: &this->m_Servers.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_Servers.m_Size - i - 1));
      --this->m_Servers.m_Size;
      --i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D260
// Name: protected: void CServerManager::RequestPingingDetails(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::RequestPingingDetails(CServerManager *this)
{
  CServerManager *v1; // esi
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  int v4; // ebx
  int m_nValue; // eax
  CServer *v6; // esi
  int m_Size; // ecx
  const char *v8; // [esp-4h] [ebp-1Ch]
  float value; // [esp+0h] [ebp-18h]
  float m_fValue; // [esp+10h] [ebp-8h]

  v1 = this;
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(this: v2, setName: "InetSearchServerDetails");
  else
    v3 = nullptr;
  v4 = 0;
  if ( v1->m_ServersPinging.m_Size > 0 )
  {
    do
    {
      if ( mm_server_search_inet_ping_window.m_pParent != nullptr )
        m_nValue = mm_server_search_inet_ping_window.m_pParent->m_Value.m_nValue;
      else
        m_nValue = 0;
      if ( v4 >= m_nValue )
        break;
      v6 = v1->m_ServersPinging.m_Memory.m_pMemory[v4];
      if ( *(float *)&v6[12].m_netAdr.m_usConnectionPort == 0.0
        || _Plat_FloatTime() <= *(float *)&v6[12].m_netAdr.m_usConnectionPort )
      {
        value = _Plat_FloatTime();
        KeyValues::SetFloat(this: v3, keyName: "timestamp", value);
        KeyValues::SetUint64(this: v3, keyName: "pingxuid", value: v6->m_xuid);
        V_snprintf(
          pDest: &`servernetadr_t::ToString'::`2'::s[64 * `servernetadr_t::ToString'::`2'::nBuf],
          maxLen: 64,
          pFormat: "%u.%u.%u.%u:%i",
          HIBYTE(v6->m_netAdr.m_unIP),
          (unsigned __int8)BYTE2(v6->m_netAdr.m_unIP),
          BYTE1(v6->m_netAdr.m_unIP),
          (unsigned __int8)v6->m_netAdr.m_unIP,
          v6->m_netAdr.m_usConnectionPort);
        v8 = &`servernetadr_t::ToString'::`2'::s[64 * `servernetadr_t::ToString'::`2'::nBuf];
        `servernetadr_t::ToString'::`2'::nBuf = ((_BYTE)`servernetadr_t::ToString'::`2'::nBuf + 1) & 3;
        CConnectionlessLanMgr::SendPacket(this: g_pConnectionlessLanMgr, pMsg: v3, szAddress: v8, eSock: NS_SOCK_CLIENT);
        if ( *(float *)&v6[12].m_netAdr.m_usConnectionPort == 0.0 )
        {
          m_fValue = mm_server_search_inet_ping_timeout.m_pParent->m_Value.m_fValue;
          *(float *)&v6[12].m_netAdr.m_usConnectionPort = _Plat_FloatTime() + m_fValue;
        }
      }
      else
      {
        m_Size = this->m_ServersPinging.m_Size;
        if ( m_Size > 0 )
        {
          if ( v4 != m_Size - 1 )
            this->m_ServersPinging.m_Memory.m_pMemory[v4] = this->m_ServersPinging.m_Memory.m_pMemory[m_Size - 1];
          --this->m_ServersPinging.m_Size;
        }
        --v4;
        ((void (__thiscall *)(CServer *, int))v6->dtr_CServer)(a1: v6, a2: 1);
      }
      ++v4;
      v1 = this;
    }
    while ( v4 < this->m_ServersPinging.m_Size );
  }
  v1->m_lanSearchData.m_flLastBroadcastTime = _Plat_FloatTime();
  _DevMsg(a1: 2, a2: "Server manager waiting for game details from %d servers...\n", v1->m_ServersPinging.m_Size);
  if ( v3 != nullptr )
    KeyValues::deleteThis(this: v3);
}

//------------------------------------------------------------------------------
// Address: 0x1001D550
// Name: public: virtual CServerManager::~CServerManager(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::~CServerManager(CServerManager *this)
{
  this->IServerManager::__vftable = (CServerManager_vtbl *)&CServerManager::`vftable'{for `IServerManager'};
  this->ISteamMatchmakingServerListResponse::__vftable = (ISteamMatchmakingServerListResponse_vtbl *)&CServerManager::`vftable'{for `ISteamMatchmakingServerListResponse'};
  this->IMatchEventsSink::__vftable = (IMatchEventsSink_vtbl *)&CServerManager::`vftable'{for `IMatchEventsSink'};
  CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_Servers);
  CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
  if ( this->m_hRequest != nullptr )
    steamapicontext->m_pSteamMatchmakingServers->ReleaseRequest(
      this: steamapicontext->m_pSteamMatchmakingServers,
      a2: this->m_hRequest);
  this->m_hRequest = nullptr;
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_groupSearchData.m_UserGroupAccountIDs);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_ServersPinging);
  CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>::~CUtlVector<CMatchTitleGameSettingsMgr::SearchPass *,CUtlMemory<CMatchTitleGameSettingsMgr::SearchPass *,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&this->m_Servers);
}

//------------------------------------------------------------------------------
// Address: 0x1001D5C0
// Name: protected: void CServerManager::MarkOldServersAndBeginSearch(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::MarkOldServersAndBeginSearch(CServerManager *this)
{
  KeyValues *v2; // eax
  KeyValues *v3; // edi
  IMatchEventsSubscription *v4; // eax

  _DevMsg(a1: 2, a2: "Server manager refreshing...\n");
  v2 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
  if ( v2 != nullptr )
    v3 = KeyValues::KeyValues(
           this: v2,
           setName: "OnMatchServerMgrUpdate",
           firstKey: "update",
           firstValue: "searchstarted");
  else
    v3 = nullptr;
  v4 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
  v4->BroadcastEvent(this: v4, a2: v3);
  CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
  this->m_groupSearchData.m_idxSearchGroupId = 0;
  this->m_groupSearchData.m_UserGroupAccountIDs.m_Size = 0;
  this->m_lanSearchData.m_flStartTime = 0.0;
  this->m_lanSearchData.m_flLastBroadcastTime = 0.0;
  this->m_eState = STATE_LAN_SEARCH;
  if ( net_allow_multicast.m_pParent == nullptr || net_allow_multicast.m_pParent->m_Value.m_nValue == 0 )
    this->m_eState = STATE_GROUP_SEARCH;
}

//------------------------------------------------------------------------------
// Address: 0x1001D670
// Name: protected: void CServerManager::OnAllDataFetched(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::OnAllDataFetched(CServerManager *this)
{
  bool v2; // zf
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMatchEventsSubscription *v5; // eax

  _DevMsg(a1: 2, a2: "Server manager refresh completed.\n");
  v2 = !this->m_bUpdateEnabled;
  this->m_eState = 0;
  if ( v2 )
  {
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_Servers);
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
  }
  else
  {
    CServerManager::RemoveOldServers(this);
  }
  if ( g_pMatchFramework != nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(
             this: v3,
             setName: "OnMatchServerMgrUpdate",
             firstKey: "update",
             firstValue: "searchfinished");
    else
      v4 = nullptr;
    v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v5->BroadcastEvent(this: v5, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D730
// Name: public: virtual void CServerManager::EnableServersUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::EnableServersUpdate(CServerManager *this, bool bEnable)
{
  bool v2; // bl
  IMatchTitle *v4; // eax

  v2 = bEnable;
  if ( bEnable )
  {
    v4 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    if ( (v4->GetTitleSettingsFlags(this: v4) & 8) != 0 )
      v2 = false;
  }
  this->m_bUpdateEnabled = v2;
  this->m_flNextUpdateTime = 0.0;
  if ( !v2 )
  {
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_Servers);
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
    if ( this->m_eState == STATE_FETCHING_SERVERS && this->m_hRequest != nullptr )
    {
      steamapicontext->m_pSteamMatchmakingServers->ReleaseRequest(
        this: steamapicontext->m_pSteamMatchmakingServers,
        a2: this->m_hRequest);
      this->m_hRequest = nullptr;
    }
    CServerManager::OnAllDataFetched(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001D7B0
// Name: public: virtual void CServerManager::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CServerManager::OnEvent(CServerManager *this@<ecx>, int a2@<ebx>, KeyValues *pEvent)
{
  const char *Name; // esi
  unsigned int i; // ebx
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  double Float; // st7
  int v8; // eax
  IMatchNetworkMsgController *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  KeyValues *Key; // eax
  const char *v13; // eax
  unsigned __int64 Uint64; // rax
  CUtlVector<CServer *,CUtlMemory<CServer *,int> > *p_m_Size; // ebx
  CServer *ResultById; // edi
  double v17; // st7
  int v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  unsigned int IP; // eax
  float v22; // edi
  unsigned int v23; // esi
  CServer *Copy; // ebx
  KeyValues *v25; // eax
  const char *v26; // eax
  CServer *v27; // edi
  CServer *v28; // eax
  int v29; // eax
  unsigned __int16 Port; // si
  unsigned __int16 v31; // bx
  unsigned int v32; // eax
  CServerManager *v33; // esi
  int m_nAllocationCount; // ebx
  float m_flNextServerUpdateTime; // eax
  int m_flNextUpdateTime_low; // ecx
  int v37; // eax
  float m_flNextUpdateTime; // ecx
  CServer **v39; // ebx
  KeyValues *m_pGameDetails; // ecx
  int Int; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // edi
  IMatchEventsSubscription *v44; // eax
  KeyValues *v45; // eax
  KeyValues *v46; // esi
  const char *String; // eax
  const char *v48; // eax
  KeyValues *v49; // [esp-4h] [ebp-6Ch]
  INetSupport::ServerInfo_t v51; // [esp+10h] [ebp-58h] BYREF
  netadr_s netAddress; // [esp+40h] [ebp-28h] BYREF
  unsigned __int64 xuidOnline; // [esp+4Ch] [ebp-1Ch]
  KeyValues *kvLanSearch; // [esp+54h] [ebp-14h]
  float flTimeSent; // [esp+5Ch] [ebp-Ch] BYREF
  CServerManager *v56; // [esp+60h] [ebp-8h]
  int nPing; // [esp+64h] [ebp-4h]

  v56 = this;
  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnNetLanConnectionlessPacket") != 0 )
  {
    if ( _V_stricmp(s1: "Client::ResendGameDetailsRequest", s2: Name) == 0 )
    {
      v45 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v46 = v45 != nullptr ? KeyValues::KeyValues(this: v45, setName: "ConnectServerDetailsRequest") : nullptr;
      String = KeyValues::GetString(this: pEvent, keyName: "to", defaultValue: defaultValue);
      KeyValues::SetString(this: v46, keyName: "server", value: String);
      v48 = KeyValues::GetString(this: pEvent, keyName: "to", defaultValue: defaultValue);
      CConnectionlessLanMgr::SendPacket(this: g_pConnectionlessLanMgr, pMsg: v46, szAddress: v48, eSock: NS_SOCK_CLIENT);
      if ( v46 != nullptr )
        KeyValues::deleteThis(this: v46);
    }
  }
  else
  {
    netAddress.type = (netadrtype_t)"LanSearchServerPing";
    *(_DWORD *)netAddress.ip = "ConnectServerDetailsRequest";
    *(_DWORD *)&netAddress.port = "InetSearchServerDetails";
    for ( i = 0; i < 3; ++i )
    {
      LODWORD(flTimeSent) = KeyValues::FindKey(
                              this: pEvent,
                              keyName: *((const char **)&netAddress.type + i),
                              bCreate: false);
      if ( LODWORD(flTimeSent) != 0 )
      {
        v9 = g_pMatchFramework->GetMatchNetworkMsgController(this: g_pMatchFramework);
        v10 = v9->GetActiveServerGameDetails(this: v9, a2: pEvent);
        v11 = v10;
        if ( v10 != nullptr )
        {
          if ( KeyValues::FindKey(this: v10, keyName: "server", bCreate: false) != nullptr )
          {
            v49 = (KeyValues *)LODWORD(flTimeSent);
            Key = KeyValues::FindKey(this: v11, keyName: *((const char **)&netAddress.type + i), bCreate: true);
            KeyValues::MergeFrom(this: Key, kvMerge: v49, eOp: MERGE_KV_UPDATE);
            v13 = KeyValues::GetString(this: pEvent, keyName: "from", defaultValue: defaultValue);
            CConnectionlessLanMgr::SendPacket(
              this: g_pConnectionlessLanMgr,
              pMsg: v11,
              szAddress: v13,
              eSock: NS_SOCK_SERVER);
          }
          KeyValues::deleteThis(this: v11);
        }
        return;
      }
    }
    v5 = KeyValues::FindKey(this: pEvent, keyName: "GameDetailsServer", bCreate: false);
    v6 = v5;
    kvLanSearch = v5;
    if ( v5 == nullptr )
      return;
    Float = KeyValues::GetFloat(this: v5, keyName: "LanSearchServerPing/timestamp", defaultValue: 0.0);
    flTimeSent = Float;
    if ( Float != 0.0 )
    {
      v8 = (int)((_Plat_FloatTime() - flTimeSent) * 1000.0);
      nPing = v8;
      if ( v8 >= 0 )
      {
        if ( v8 >= 1000 )
          nPing = 999;
      }
      else
      {
        nPing = 0;
      }
LABEL_24:
      v19 = KeyValues::GetString(this: v6, keyName: "server/adronline", defaultValue: nullptr);
      v20 = v19;
      if ( v19 != nullptr && *v19 != 0 )
      {
        netadr_s::SetIP(this: &netAddress, unIP: 0);
        netadr_s::SetPort(this: &netAddress, newport: 0);
        netadr_s::SetType(this: &netAddress, newtype: NA_IP);
        netadr_s::SetType(this: &netAddress, newtype: NA_IP);
        netadr_s::SetPort(this: &netAddress, newport: 0x6987u);
        netadr_s::SetFromString(this: &netAddress, pch: v20, bUseDNS: false);
        INetSupport::ServerInfo_t::ServerInfo_t(this: &v51);
        g_pMatchExtensions->m_exts.m_pINetSupport->GetServerInfo(
          this: g_pMatchExtensions->m_exts.m_pINetSupport,
          a2: &v51);
        if ( !v51.m_bActive
          || !netadr_s::CompareAdr(this: &v51.m_netAdr, a: &netAddress, onlyBase: false)
          && !netadr_s::CompareAdr(this: &v51.m_netAdrOnline, a: &netAddress, onlyBase: false) )
        {
          LODWORD(flTimeSent) = netadr_s::GetPort(this: &netAddress);
          IP = netadr_s::GetIP(this: &netAddress);
          v22 = flTimeSent;
          v23 = IP;
          xuidOnline = __PAIR64__(LODWORD(flTimeSent), IP);
          Copy = (CServer *)KeyValues::MakeCopy(this: kvLanSearch);
          LODWORD(flTimeSent) = Copy;
          KeyValues::SetName(this: (KeyValues *)Copy, setName: "settings");
          v25 = KeyValues::FindKey(this: (KeyValues *)Copy, keyName: "LanSearch", bCreate: false);
          kvLanSearch = v25;
          if ( v25 != nullptr )
          {
            KeyValues::RemoveSubKey(this: (KeyValues *)Copy, subKey: v25);
            KeyValues::deleteThis(this: kvLanSearch);
          }
          KeyValues::SetInt(this: (KeyValues *)Copy, keyName: "server/ping", value: nPing);
          v26 = KeyValues::GetString(this: pEvent, keyName: "from", defaultValue: nullptr);
          if ( v26 != nullptr )
            KeyValues::SetString(this: (KeyValues *)Copy, keyName: "server/connectstring", value: v26);
          v27 = (CServer *)(*(int (__thiscall **)(int *, unsigned int, float, int))(v56[-1].m_groupSearchData.m_UserGroupAccountIDs.m_Size
                                                                                  + 12))(
                             a1: &v56[-1].m_groupSearchData.m_UserGroupAccountIDs.m_Size,
                             a2: v23,
                             a3: COERCE_FLOAT(LODWORD(v22)),
                             a4: a2);
          if ( v27 == nullptr )
          {
            v28 = (CServer *)operator new(nSize: 0x20u);
            if ( v28 != nullptr )
              v27 = CServer::CServer(this: v28);
            else
              v27 = nullptr;
            v29 = HIDWORD(xuidOnline);
            LODWORD(v27->m_xuid) = v23;
            HIDWORD(v27->m_xuid) = v29;
            Port = netadr_s::GetPort(this: &netAddress);
            v31 = netadr_s::GetPort(this: &netAddress);
            v32 = netadr_s::addr_htonl(this: &netAddress);
            v27->m_netAdr.m_usConnectionPort = Port;
            v33 = v56;
            v27->m_netAdr.m_usQueryPort = v31;
            v27->m_netAdr.m_unIP = v32;
            m_nAllocationCount = v33->m_Servers.m_Memory.m_nAllocationCount;
            m_flNextServerUpdateTime = v33->m_flNextServerUpdateTime;
            if ( m_nAllocationCount + 1 > SLODWORD(m_flNextServerUpdateTime) )
              CUtlMemory<GCSDK::CLock *,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v33->m_flNextUpdateTime,
                num: m_nAllocationCount - LODWORD(m_flNextServerUpdateTime) + 1);
            ++v33->m_Servers.m_Memory.m_nAllocationCount;
            m_flNextUpdateTime_low = LODWORD(v33->m_flNextUpdateTime);
            v37 = v33->m_Servers.m_Memory.m_nAllocationCount - m_nAllocationCount - 1;
            v33->m_Servers.m_Memory.m_nGrowSize = m_flNextUpdateTime_low;
            if ( v37 > 0 )
              _V_memmove(
                dest: (void *)(m_flNextUpdateTime_low + 4 * m_nAllocationCount + 4),
                src: (const void *)(m_flNextUpdateTime_low + 4 * m_nAllocationCount),
                count: 4 * v37);
            m_flNextUpdateTime = v33->m_flNextUpdateTime;
            v23 = xuidOnline;
            v39 = (CServer **)(LODWORD(m_flNextUpdateTime) + 4 * m_nAllocationCount);
            if ( v39 != nullptr )
              *v39 = v27;
            Copy = (CServer *)LODWORD(flTimeSent);
          }
          m_pGameDetails = v27->m_pGameDetails;
          if ( m_pGameDetails != nullptr )
          {
            Int = KeyValues::GetInt(this: m_pGameDetails, keyName: "server/ping", defaultValue: 0);
            if ( Int < nPing )
              KeyValues::SetInt(this: (KeyValues *)Copy, keyName: "server/ping", value: (Int + nPing + 8 * Int) / 10);
            KeyValues::deleteThis(this: v27->m_pGameDetails);
          }
          v27->m_pGameDetails = (KeyValues *)Copy;
          v27->m_flLastRefresh = _Plat_FloatTime();
          v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v42 != nullptr )
            v43 = KeyValues::KeyValues(
                    this: v42,
                    setName: "OnMatchServerMgrUpdate",
                    firstKey: "update",
                    firstValue: "server");
          else
            v43 = nullptr;
          KeyValues::SetUint64(this: v43, keyName: "xuid", value: __PAIR64__(HIDWORD(xuidOnline), v23));
          v44 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
          v44->BroadcastEvent(this: v44, a2: v43);
        }
      }
      return;
    }
    Uint64 = KeyValues::GetUint64(this: v6, keyName: "InetSearchServerDetails/pingxuid", defaultValue: 0);
    if ( Uint64 != 0 )
    {
      p_m_Size = (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&v56->m_Servers.m_Size;
      ResultById = CSearchManager::GetResultById(
                     this: (CServerManager *)((char *)v56 - 8),
                     arr: (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&v56->m_Servers.m_Size,
                     xuidServerOnline: Uint64);
      if ( ResultById == nullptr )
        return;
      v17 = KeyValues::GetFloat(this: v6, keyName: "InetSearchServerDetails/timestamp", defaultValue: 0.0);
      flTimeSent = v17;
      if ( v17 == 0.0 )
      {
        nPing = ResultById[1].m_xuid;
      }
      else
      {
        v18 = (int)((_Plat_FloatTime() - flTimeSent) * 1000.0);
        nPing = v18;
        if ( v18 >= 0 )
        {
          if ( v18 >= 1000 )
            nPing = 999;
        }
        else
        {
          nPing = 0;
        }
      }
      LODWORD(flTimeSent) = ResultById;
      CUtlVector<int,CUtlMemory<int,int>>::FindAndFastRemove(this: p_m_Size, src: (CServer **)&flTimeSent);
      ((void (__thiscall *)(CServer *, int))ResultById->dtr_CServer)(a1: ResultById, a2: 1);
      goto LABEL_24;
    }
    if ( KeyValues::GetString(this: v6, keyName: "ConnectServerDetailsRequest/server", defaultValue: defaultValue) != nullptr )
      g_pMatchExtensions->m_exts.m_pINetSupport->OnMatchEvent(
        this: g_pMatchExtensions->m_exts.m_pINetSupport,
        a2: pEvent);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DD30
// Name: public: virtual void CServerManager::ServerResponded(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::ServerResponded(CServerManager *this, void *hReq, CServerPinging *iServer)
{
  ISteamMatchmakingServers *m_pSteamMatchmakingServers; // ecx
  gameserveritem_t *(__thiscall *GetServerDetails)(ISteamMatchmakingServers *, void *, int); // edx
  gameserveritem_t *v6; // edi
  char *ConnectionAddressString; // eax
  unsigned __int16 Port; // ax
  unsigned int IP; // eax
  int v10; // ebx
  CUtlVector<CServer *,CUtlMemory<CServer *,int> > *p_m_pElements; // esi
  CServer *ResultById; // eax
  CServerPinging *v13; // eax
  CServerPinging *v14; // eax
  int v15; // edx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CServer **m_pMemory; // ecx
  int v19; // eax
  CServerPinging **v20; // edi
  netadr_s netAddress; // [esp+8h] [ebp-18h] BYREF
  unsigned __int64 xuidOnline; // [esp+14h] [ebp-Ch]
  CServerManager *v23; // [esp+1Ch] [ebp-4h]
  CServerPinging *pServer; // [esp+2Ch] [ebp+Ch]
  CServerPinging *pServera; // [esp+2Ch] [ebp+Ch]

  m_pSteamMatchmakingServers = steamapicontext->m_pSteamMatchmakingServers;
  GetServerDetails = m_pSteamMatchmakingServers->GetServerDetails;
  v23 = this;
  v6 = GetServerDetails(this: m_pSteamMatchmakingServers, a2: hReq, a3: (int)iServer);
  if ( v6 != nullptr )
  {
    this->m_lanSearchData.m_flStartTime = _Plat_FloatTime();
    netadr_s::SetIP(this: &netAddress, unIP: 0);
    netadr_s::SetPort(this: &netAddress, newport: 0);
    netadr_s::SetType(this: &netAddress, newtype: NA_IP);
    netadr_s::SetType(this: &netAddress, newtype: NA_IP);
    netadr_s::SetPort(this: &netAddress, newport: 0x6987u);
    ConnectionAddressString = servernetadr_t::GetConnectionAddressString(this: &v6->m_NetAdr);
    netadr_s::SetFromString(this: &netAddress, pch: ConnectionAddressString, bUseDNS: false);
    Port = netadr_s::GetPort(this: &netAddress);
    LODWORD(xuidOnline) = 0;
    HIDWORD(xuidOnline) = Port;
    IP = netadr_s::GetIP(this: &netAddress);
    v10 = xuidOnline | IP;
    p_m_pElements = (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&this->m_Servers.m_pElements;
    ResultById = CSearchManager::GetResultById(
                   this: (CServerManager *)((char *)v23 - 4),
                   arr: p_m_pElements,
                   xuidServerOnline: xuidOnline | IP);
    pServer = (CServerPinging *)ResultById;
    if ( ResultById != nullptr )
    {
      gameserveritem_t::operator=(this: (gameserveritem_t *)&ResultById[1], __that: v6);
      pServer->m_netAdr.m_usConnectionPort = v6->m_NetAdr.m_usConnectionPort;
      pServer->m_netAdr.m_usQueryPort = v6->m_NetAdr.m_usQueryPort;
      pServer->m_netAdr.m_unIP = v6->m_NetAdr.m_unIP;
    }
    else
    {
      v13 = (CServerPinging *)operator new(nSize: 0x198u);
      if ( v13 != nullptr )
      {
        v14 = CServerPinging::CServerPinging(this: v13);
        pServera = v14;
      }
      else
      {
        pServera = nullptr;
        v14 = nullptr;
      }
      v15 = HIDWORD(xuidOnline);
      LODWORD(v14->m_xuid) = v10;
      HIDWORD(v14->m_xuid) = v15;
      gameserveritem_t::operator=(this: &v14->m_gsi, __that: v6);
      pServera->m_netAdr.m_usConnectionPort = v6->m_NetAdr.m_usConnectionPort;
      pServera->m_netAdr.m_usQueryPort = v6->m_NetAdr.m_usQueryPort;
      pServera->m_netAdr.m_unIP = v6->m_NetAdr.m_unIP;
      m_Size = p_m_pElements->m_Size;
      m_nAllocationCount = p_m_pElements->m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<GCSDK::CLock *,int>::Grow(
          this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)p_m_pElements,
          num: m_Size - m_nAllocationCount + 1);
      ++p_m_pElements->m_Size;
      m_pMemory = p_m_pElements->m_Memory.m_pMemory;
      v19 = p_m_pElements->m_Size - m_Size - 1;
      p_m_pElements->m_pElements = p_m_pElements->m_Memory.m_pMemory;
      if ( v19 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v19);
      v20 = (CServerPinging **)&p_m_pElements->m_Memory.m_pMemory[m_Size];
      if ( v20 != nullptr )
        *v20 = pServera;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DED0
// Name: protected: void CServerManager::UpdateRequestingDetails(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::UpdateRequestingDetails(CServerManager *this)
{
  double v2; // [esp+4h] [ebp-8h]

  if ( this->m_ServersPinging.m_Size != 0 )
  {
    v2 = (float)(this->m_lanSearchData.m_flLastBroadcastTime
               + mm_server_search_inet_ping_interval.m_pParent->m_Value.m_fValue);
    if ( _Plat_FloatTime() > v2 )
      CServerManager::RequestPingingDetails(this);
  }
  else
  {
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
    CServerManager::OnAllDataFetched(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001DF30
// Name: protected: bool CServerManager::StartFetchingGroupServersData(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CServerManager::StartFetchingGroupServersData(CServerManager *this)
{
  bool v1; // zf
  ISteamFriends *m_pSteamFriends; // edi
  int v4; // eax
  int v5; // ebx
  int i; // esi
  unsigned int *v8; // eax
  CSteamID v9; // [esp+8h] [ebp-Ch] BYREF
  CServerManager *v10; // [esp+10h] [ebp-4h]

  v1 = steamapicontext->m_pSteamUser == nullptr;
  m_pSteamFriends = steamapicontext->m_pSteamFriends;
  v10 = this;
  if ( v1 || m_pSteamFriends == nullptr )
    return 0;
  v4 = m_pSteamFriends->GetClanCount(this: m_pSteamFriends);
  v5 = v4;
  if ( v4 == 0 )
    return 0;
  this->m_groupSearchData.m_UserGroupAccountIDs.m_Size = 0;
  CUtlVector<KeyValues *,CUtlMemory<KeyValues *,int>>::InsertMultipleBefore(
    this: &this->m_groupSearchData.m_UserGroupAccountIDs,
    elem: 0,
    num: v4);
  for ( i = 0; i < v5; ++i )
  {
    v8 = (unsigned int *)m_pSteamFriends->GetClanByIndex(this: m_pSteamFriends, result: &v9, a3: i);
    v10->m_groupSearchData.m_UserGroupAccountIDs.m_Memory.m_pMemory[i] = *v8;
  }
  return CServerManager::FetchGroupServers(this: v10);
}

//------------------------------------------------------------------------------
// Address: 0x1001DFC0
// Name: protected: void CServerManager::OnGroupFetched(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::OnGroupFetched(CServerManager *this)
{
  int m_idxSearchGroupId; // eax
  double v3; // st7
  bool v4; // zf
  int m_nValue; // [esp+4h] [ebp-4h]

  if ( !this->m_bUpdateEnabled
    || (m_idxSearchGroupId = this->m_groupSearchData.m_idxSearchGroupId) < 0
    || m_idxSearchGroupId >= this->m_groupSearchData.m_UserGroupAccountIDs.m_Size
    || CServerManager::FetchGroupServers(this) == 0 )
  {
    if ( mm_server_search_update_interval.m_pParent != nullptr )
      m_nValue = mm_server_search_update_interval.m_pParent->m_Value.m_nValue;
    else
      m_nValue = 0;
    v3 = _Plat_FloatTime();
    v4 = this->m_ServersPinging.m_Size == 0;
    this->m_flNextUpdateTime = v3 + (double)m_nValue;
    if ( v4 )
    {
      CServerManager::OnAllDataFetched(this);
    }
    else
    {
      this->m_eState = STATE_REQUESTING_DETAILS;
      this->m_lanSearchData.m_flStartTime = _Plat_FloatTime();
      CServerManager::RequestPingingDetails(this);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1001E040
// Name: public: void CServerManager::Update(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::Update(CServerManager *this)
{
  CServerManager *v1; // ebx
  float v2; // xmm1_4
  float m_fValue; // xmm2_4
  int v4; // eax
  CServer *v5; // ecx
  float v6; // xmm1_4
  float v7; // xmm0_4
  CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *p_m_ServersPinging; // esi
  unsigned __int64 v9; // rax
  CServerPinging *v10; // eax
  CServerPinging *v11; // edi
  CServer *v12; // ecx
  CServer *v13; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CUtlSymbolTable::StringPool_t **m_pMemory; // ecx
  int v17; // eax
  CServerPinging **v18; // ebx
  float v19; // xmm0_4
  float v21; // [esp+4h] [ebp-10h]
  float now; // [esp+8h] [ebp-Ch]
  float nextUpdatePeriod; // [esp+Ch] [ebp-8h]
  int i; // [esp+10h] [ebp-4h]

  v1 = this;
  now = _Plat_FloatTime();
  switch ( v1->m_eState )
  {
    case 0:
      if ( v1->m_bUpdateEnabled && !IsLocalClientConnectedToServer() )
      {
        v2 = now;
        if ( now <= v1->m_flNextUpdateTime )
        {
          if ( now > v1->m_flNextServerUpdateTime )
          {
            m_fValue = mm_server_search_inet_ping_refresh.m_pParent->m_Value.m_fValue;
            v4 = 0;
            nextUpdatePeriod = m_fValue;
            for ( i = 0; v4 < v1->m_Servers.m_Size; i = v4 )
            {
              v5 = v1->m_Servers.m_Memory.m_pMemory[v4];
              v6 = v2 - v5->m_flLastRefresh;
              v7 = mm_server_search_inet_ping_refresh.m_pParent->m_Value.m_fValue;
              if ( v6 <= v7 )
              {
                v19 = v7 - v6;
                if ( v19 <= m_fValue )
                {
                  m_fValue = v19;
                  nextUpdatePeriod = v19;
                }
              }
              else
              {
                p_m_ServersPinging = (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v1->m_ServersPinging;
                v9 = v5->GetOnlineId(this: v5);
                if ( CSearchManager::GetResultById(this: v1, arr: &v1->m_ServersPinging, xuidServerOnline: v9) == nullptr )
                {
                  v10 = (CServerPinging *)operator new(nSize: 0x198u);
                  if ( v10 != nullptr )
                    v11 = CServerPinging::CServerPinging(this: v10);
                  else
                    v11 = nullptr;
                  v12 = v1->m_Servers.m_Memory.m_pMemory[i];
                  v11->m_xuid = v12->GetOnlineId(this: v12);
                  v13 = v1->m_Servers.m_Memory.m_pMemory[i];
                  v11->m_netAdr.m_usConnectionPort = v13->m_netAdr.m_usConnectionPort;
                  v11->m_netAdr.m_usQueryPort = v13->m_netAdr.m_usQueryPort;
                  v11->m_netAdr.m_unIP = v13->m_netAdr.m_unIP;
                  m_Size = v1->m_ServersPinging.m_Size;
                  m_nAllocationCount = p_m_ServersPinging->m_nAllocationCount;
                  if ( m_Size + 1 > m_nAllocationCount )
                    CUtlMemory<GCSDK::CLock *,int>::Grow(this: p_m_ServersPinging, num: m_Size - m_nAllocationCount + 1);
                  ++p_m_ServersPinging[1].m_pMemory;
                  m_pMemory = p_m_ServersPinging->m_pMemory;
                  v17 = (int)p_m_ServersPinging[1].m_pMemory - m_Size - 1;
                  p_m_ServersPinging[1].m_nAllocationCount = (int)p_m_ServersPinging->m_pMemory;
                  if ( v17 > 0 )
                    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v17);
                  v18 = (CServerPinging **)&p_m_ServersPinging->m_pMemory[m_Size];
                  if ( v18 != nullptr )
                    *v18 = v11;
                  v1 = this;
                }
                m_fValue = nextUpdatePeriod;
              }
              v2 = now;
              v4 = i + 1;
            }
            v1->m_flNextServerUpdateTime = m_fValue + v2;
            v1->m_eState = STATE_REQUESTING_DETAILS;
          }
        }
        else
        {
          CServerManager::MarkOldServersAndBeginSearch(this: v1);
        }
      }
      break;
    case 1:
      CServerManager::UpdateLanSearch(this: v1);
      break;
    case 2:
      if ( CServerManager::StartFetchingGroupServersData(this: v1) == 0 )
        goto $LN5_0;
      break;
    case 3:
      v21 = mm_server_search_inet_ping_timeout.m_pParent->m_Value.m_fValue;
      if ( _Plat_FloatTime() > v1->m_lanSearchData.m_flLastBroadcastTime + v21 )
      {
        steamapicontext->m_pSteamMatchmakingServers->ReleaseRequest(
          this: steamapicontext->m_pSteamMatchmakingServers,
          a2: v1->m_hRequest);
        v1->m_hRequest = nullptr;
        v1->m_eState = STATE_GROUP_FETCHED;
      }
      break;
    case 4:
$LN5_0:
      CServerManager::OnGroupFetched(this: v1);
      break;
    case 5:
      CServerManager::UpdateRequestingDetails(this: v1);
      break;
    default:
      return;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100292E0
// Name: public: virtual bool CServer::IsJoinable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CServer::IsJoinable(CServer *this)
{
  return this->m_pGameDetails != nullptr;
}

} // namespace matchmaking

// ============================================================
// Overlay from matchmaking_ds (Missing functions)
// ============================================================
namespace matchmaking_ds {

//------------------------------------------------------------------------------
// Address: 0x10006430
// Name: public: virtual unsigned __int64 CServer::GetOnlineId(void)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CServer::GetOnlineId(CServer *this)
{
  return this->m_xuid;
}

//------------------------------------------------------------------------------
// Address: 0x10006440
// Name: public: virtual class KeyValues __near * CServer::GetGameDetails(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CServer::GetGameDetails(ConCommandBase *this)
{
  return this->m_pszHelpString;
}

//------------------------------------------------------------------------------
// Address: 0x10006450
// Name: public: virtual bool CServer::IsJoinable(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CServer::IsJoinable(CServer *this)
{
  return this->m_pGameDetails != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006460
// Name: public: CServer::CServer(void)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServer::CServer(CServer *this)
{
  this->__vftable = (CServer_vtbl *)&CServer::`vftable';
  this->m_flLastRefresh = _Plat_FloatTime();
  this->m_xuid = 0;
  this->m_pGameDetails = nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100064D0
// Name: public: virtual int CServerManager::GetNumServers(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CServerManager::GetNumServers(CServerManager *this)
{
  return this->m_Servers.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x100064E0
// Name: public: virtual void CServer::Join(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServer::Join(CServer *this)
{
  const char *String; // eax
  IVEngineClient *m_pIVEngineClient; // esi
  CFmtStrN<256> *v3; // eax
  CFmtStrN<256> v4; // [esp+0h] [ebp-10Ch] BYREF

  String = KeyValues::GetString(this: this->m_pGameDetails, keyName: "server/connectstring", defaultValue: nullptr);
  if ( String != nullptr && *String != 0 )
  {
    m_pIVEngineClient = g_pMatchExtensions->m_exts.m_pIVEngineClient;
    v3 = CFmtStrN<256>::CFmtStrN<256>(this: &v4, pszFormat: "connect %s\n", String);
    m_pIVEngineClient->ClientCmd(this: m_pIVEngineClient, a2: v3->m_szBuf);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006540
// Name: public: virtual class IMatchServer __near * CServerManager::GetServerByIndex(int)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServerManager::GetServerByIndex(CServerManager *this, int iServerIdx)
{
  if ( iServerIdx < 0 || iServerIdx >= this->m_Servers.m_Size )
    return nullptr;
  else
    return this->m_Servers.m_Memory.m_pMemory[iServerIdx];
}

//------------------------------------------------------------------------------
// Address: 0x10006560
// Name: protected: class CServer __near * CServerManager::GetServerRecordByOnlineId(class CUtlVector<class CServer __near *,class CUtlMemory<class CServer __near *,int>> __near &,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServerManager::GetServerRecordByOnlineId(
        CServerManager *this,
        CUtlVector<CServer *,CUtlMemory<CServer *,int> > *arr,
        unsigned __int64 xuidServerOnline)
{
  int v3; // edi
  CServer *v4; // esi
  __int64 v5; // rax

  v3 = 0;
  if ( arr->m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = arr->m_Memory.m_pMemory[v3];
    if ( v4 != nullptr )
    {
      LODWORD(v5) = v4->GetOnlineId(this: arr->m_Memory.m_pMemory[v3]);
      if ( v5 == xuidServerOnline )
        break;
    }
    if ( ++v3 >= arr->m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100065B0
// Name: public: virtual class IMatchServer __near * CServerManager::GetServerByOnlineId(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
CServer *__thiscall CServerManager::GetServerByOnlineId(CServerManager *this, unsigned __int64 xuidServerOnline)
{
  return CServerManager::GetServerRecordByOnlineId(this, arr: &this->m_Servers, xuidServerOnline);
}

//------------------------------------------------------------------------------
// Address: 0x100065D0
// Name: protected: void CServerManager::RemoveOldServers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::RemoveOldServers(CServerManager *this)
{
  int i; // edi
  CServer *v3; // eax
  float now; // [esp+8h] [ebp-4h]

  now = _Plat_FloatTime();
  for ( i = 0; i < this->m_Servers.m_Size; ++i )
  {
    v3 = this->m_Servers.m_Memory.m_pMemory[i];
    if ( v3 == nullptr
      || mm_server_search_server_lifetime.m_pParent->m_Value.m_fValue <= (float)(now - v3->m_flLastRefresh) )
    {
      if ( this->m_Servers.m_Size - i - 1 > 0 )
        _V_memmove(
          dest: &this->m_Servers.m_Memory.m_pMemory[i],
          src: &this->m_Servers.m_Memory.m_pMemory[i + 1],
          count: 4 * (this->m_Servers.m_Size - i - 1));
      --this->m_Servers.m_Size;
      --i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006700
// Name: protected: void CServerManager::OnAllDataFetched(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::OnAllDataFetched(CServerManager *this)
{
  bool v2; // zf
  KeyValues *v3; // eax
  KeyValues *v4; // esi
  IMatchEventsSubscription *v5; // eax

  _DevMsg(a1: 2, a2: "Server manager refresh completed.\n");
  v2 = !this->m_bUpdateEnabled;
  this->m_eState = 0;
  if ( v2 )
  {
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_Servers);
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
  }
  else
  {
    CServerManager::RemoveOldServers(this);
  }
  if ( g_pMatchFramework != nullptr )
  {
    v3 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
    if ( v3 != nullptr )
      v4 = KeyValues::KeyValues(
             this: v3,
             setName: "OnMatchServerMgrUpdate",
             firstKey: "update",
             firstValue: "searchfinished");
    else
      v4 = nullptr;
    v5 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
    v5->BroadcastEvent(this: v5, a2: v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100067F0
// Name: public: virtual void CServerManager::EnableServersUpdate(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CServerManager::EnableServersUpdate(CServerManager *this, bool bEnable)
{
  bool v2; // bl
  IMatchTitle *v4; // eax

  v2 = bEnable;
  if ( bEnable )
  {
    v4 = g_pMatchFramework->GetMatchTitle(this: g_pMatchFramework);
    if ( (v4->GetTitleSettingsFlags(this: v4) & 8) != 0 )
      v2 = false;
  }
  this->m_bUpdateEnabled = v2;
  this->m_flNextUpdateTime = 0.0;
  if ( !v2 )
  {
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_Servers);
    CUtlVector<CServer *,CUtlMemory<CServer *,int>>::PurgeAndDeleteElements(this: &this->m_ServersPinging);
    CServerManager::OnAllDataFetched(this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006850
// Name: public: virtual void CServerManager::OnEvent(class KeyValues __near *)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CServerManager::OnEvent(CServerManager *this@<ecx>, int a2@<edi>, KeyValues *pEvent)
{
  const char *Name; // esi
  unsigned int i; // edi
  KeyValues *v5; // eax
  KeyValues *v6; // esi
  double Float; // st7
  int v8; // eax
  IMatchNetworkMsgController *v9; // eax
  KeyValues *v10; // eax
  KeyValues *v11; // esi
  KeyValues *Key; // eax
  const char *v13; // eax
  unsigned __int64 Uint64; // rax
  CUtlVector<CServer *,CUtlMemory<CServer *,int> > *p_m_pElements; // edi
  CServer *ServerRecordByOnlineId; // ebx
  double v17; // st7
  int v18; // eax
  const char *v19; // eax
  const char *v20; // edi
  unsigned int IP; // eax
  float v22; // ebx
  unsigned int v23; // esi
  CServer *Copy; // edi
  KeyValues *v25; // eax
  const char *v26; // eax
  CServer *v27; // ebx
  CServer *v28; // eax
  int v29; // eax
  CServerManager *v30; // esi
  int m_nGrowSize; // edi
  CServer **m_pMemory; // eax
  int m_flNextServerUpdateTime_low; // ecx
  int v34; // eax
  float m_flNextServerUpdateTime; // ecx
  CServer **v36; // edi
  KeyValues *m_pGameDetails; // ecx
  int Int; // eax
  KeyValues *v39; // eax
  KeyValues *v40; // edi
  IMatchEventsSubscription *v41; // eax
  KeyValues *v42; // eax
  KeyValues *v43; // esi
  const char *String; // eax
  const char *v45; // eax
  KeyValues *v46; // [esp-4h] [ebp-6Ch]
  INetSupport::ServerInfo_t v48; // [esp+10h] [ebp-58h] BYREF
  netadr_s netAddress; // [esp+40h] [ebp-28h] BYREF
  unsigned __int64 xuidOnline; // [esp+4Ch] [ebp-1Ch]
  KeyValues *kvLanSearch; // [esp+54h] [ebp-14h]
  float flTimeSent; // [esp+5Ch] [ebp-Ch] BYREF
  CServerManager *v53; // [esp+60h] [ebp-8h]
  int nPing; // [esp+64h] [ebp-4h]

  v53 = this;
  Name = KeyValues::GetName(this: pEvent);
  if ( _V_stricmp(s1: Name, s2: "OnNetLanConnectionlessPacket") != 0 )
  {
    if ( _V_stricmp(s1: "Client::ResendGameDetailsRequest", s2: Name) == 0 )
    {
      v42 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
      v43 = v42 != nullptr ? KeyValues::KeyValues(this: v42, setName: "ConnectServerDetailsRequest") : nullptr;
      String = KeyValues::GetString(this: pEvent, keyName: "to", defaultValue: str);
      KeyValues::SetString(this: v43, keyName: "server", value: String);
      v45 = KeyValues::GetString(this: pEvent, keyName: "to", defaultValue: str);
      CConnectionlessLanMgr::SendPacket(this: g_pConnectionlessLanMgr, pMsg: v43, szAddress: v45, eSock: NS_SOCK_CLIENT);
      if ( v43 != nullptr )
        KeyValues::deleteThis(this: v43);
    }
  }
  else
  {
    netAddress.type = (netadrtype_t)"LanSearchServerPing";
    *(_DWORD *)netAddress.ip = "ConnectServerDetailsRequest";
    *(_DWORD *)&netAddress.port = "InetSearchServerDetails";
    for ( i = 0; i < 3; ++i )
    {
      LODWORD(flTimeSent) = KeyValues::FindKey(
                              this: pEvent,
                              keyName: *((const char **)&netAddress.type + i),
                              bCreate: false);
      if ( LODWORD(flTimeSent) != 0 )
      {
        v9 = g_pMatchFramework->GetMatchNetworkMsgController(this: g_pMatchFramework);
        v10 = v9->GetActiveServerGameDetails(this: v9, a2: pEvent);
        v11 = v10;
        if ( v10 != nullptr )
        {
          if ( KeyValues::FindKey(this: v10, keyName: "server", bCreate: false) != nullptr )
          {
            v46 = (KeyValues *)LODWORD(flTimeSent);
            Key = KeyValues::FindKey(this: v11, keyName: *((const char **)&netAddress.type + i), bCreate: true);
            KeyValues::MergeFrom(this: Key, kvMerge: v46, eOp: MERGE_KV_UPDATE);
            v13 = KeyValues::GetString(this: pEvent, keyName: "from", defaultValue: str);
            CConnectionlessLanMgr::SendPacket(
              this: g_pConnectionlessLanMgr,
              pMsg: v11,
              szAddress: v13,
              eSock: NS_SOCK_SERVER);
          }
          KeyValues::deleteThis(this: v11);
        }
        return;
      }
    }
    v5 = KeyValues::FindKey(this: pEvent, keyName: "GameDetailsServer", bCreate: false);
    v6 = v5;
    kvLanSearch = v5;
    if ( v5 == nullptr )
      return;
    nPing = 0;
    Float = KeyValues::GetFloat(this: v5, keyName: "LanSearchServerPing/timestamp", defaultValue: 0.0);
    flTimeSent = Float;
    if ( Float != 0.0 )
    {
      v8 = (int)((_Plat_FloatTime() - flTimeSent) * 1000.0);
      nPing = v8;
      if ( v8 >= 0 )
      {
        if ( v8 >= 1000 )
          nPing = 999;
      }
      else
      {
        nPing = 0;
      }
LABEL_23:
      v19 = KeyValues::GetString(this: v6, keyName: "server/adronline", defaultValue: nullptr);
      v20 = v19;
      if ( v19 != nullptr && *v19 != 0 )
      {
        netadr_s::SetIP(this: &netAddress, unIP: 0);
        netadr_s::SetPort(this: &netAddress, newport: 0);
        netadr_s::SetType(this: &netAddress, newtype: NA_IP);
        netadr_s::SetType(this: &netAddress, newtype: NA_IP);
        netadr_s::SetPort(this: &netAddress, newport: 0x6987u);
        netadr_s::SetFromString(this: &netAddress, pch: v20, bUseDNS: false);
        INetSupport::ServerInfo_t::ServerInfo_t(this: &v48);
        g_pMatchExtensions->m_exts.m_pINetSupport->GetServerInfo(
          this: g_pMatchExtensions->m_exts.m_pINetSupport,
          a2: &v48);
        if ( !v48.m_bActive
          || !netadr_s::CompareAdr(this: &v48.m_netAdr, a: &netAddress, onlyBase: false)
          && !netadr_s::CompareAdr(this: &v48.m_netAdrOnline, a: &netAddress, onlyBase: false) )
        {
          LODWORD(flTimeSent) = netadr_s::GetPort(this: &netAddress);
          IP = netadr_s::GetIP(this: &netAddress);
          v22 = flTimeSent;
          v23 = IP;
          xuidOnline = __PAIR64__(LODWORD(flTimeSent), IP);
          Copy = (CServer *)KeyValues::MakeCopy(this: kvLanSearch);
          LODWORD(flTimeSent) = Copy;
          KeyValues::SetName(this: (KeyValues *)Copy, setName: "settings");
          v25 = KeyValues::FindKey(this: (KeyValues *)Copy, keyName: "LanSearch", bCreate: false);
          kvLanSearch = v25;
          if ( v25 != nullptr )
          {
            KeyValues::RemoveSubKey(this: (KeyValues *)Copy, subKey: v25);
            KeyValues::deleteThis(this: kvLanSearch);
          }
          KeyValues::SetInt(this: (KeyValues *)Copy, keyName: "server/ping", value: nPing);
          v26 = KeyValues::GetString(this: pEvent, keyName: "from", defaultValue: nullptr);
          if ( v26 != nullptr )
            KeyValues::SetString(this: (KeyValues *)Copy, keyName: "server/connectstring", value: v26);
          v27 = (CServer *)(*((int (__thiscall **)(unsigned int **, unsigned int, float, int))v53[-1].m_groupSearchData.m_UserGroupAccountIDs.m_pElements
                            + 3))(
                             a1: &v53[-1].m_groupSearchData.m_UserGroupAccountIDs.m_pElements,
                             a2: v23,
                             a3: COERCE_FLOAT(LODWORD(v22)),
                             a4: a2);
          if ( v27 == nullptr )
          {
            v28 = (CServer *)operator new(nSize: 0x18u);
            if ( v28 != nullptr )
              v27 = CServer::CServer(this: v28);
            else
              v27 = nullptr;
            v29 = HIDWORD(xuidOnline);
            LODWORD(v27->m_xuid) = v23;
            v30 = v53;
            HIDWORD(v27->m_xuid) = v29;
            m_nGrowSize = v30->m_Servers.m_Memory.m_nGrowSize;
            m_pMemory = v30->m_Servers.m_Memory.m_pMemory;
            if ( m_nGrowSize + 1 > (int)m_pMemory )
              CUtlMemory<int,int>::Grow(
                this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&v30->m_flNextServerUpdateTime,
                num: m_nGrowSize - (_DWORD)m_pMemory + 1);
            ++v30->m_Servers.m_Memory.m_nGrowSize;
            m_flNextServerUpdateTime_low = LODWORD(v30->m_flNextServerUpdateTime);
            v34 = v30->m_Servers.m_Memory.m_nGrowSize - m_nGrowSize - 1;
            v30->m_Servers.m_Size = m_flNextServerUpdateTime_low;
            if ( v34 > 0 )
              _V_memmove(
                dest: (void *)(m_flNextServerUpdateTime_low + 4 * m_nGrowSize + 4),
                src: (const void *)(m_flNextServerUpdateTime_low + 4 * m_nGrowSize),
                count: 4 * v34);
            m_flNextServerUpdateTime = v30->m_flNextServerUpdateTime;
            v23 = xuidOnline;
            v36 = (CServer **)(LODWORD(m_flNextServerUpdateTime) + 4 * m_nGrowSize);
            if ( v36 != nullptr )
              *v36 = v27;
            Copy = (CServer *)LODWORD(flTimeSent);
          }
          m_pGameDetails = v27->m_pGameDetails;
          if ( m_pGameDetails != nullptr )
          {
            Int = KeyValues::GetInt(this: m_pGameDetails, keyName: "server/ping", defaultValue: 0);
            if ( Int < nPing )
              KeyValues::SetInt(this: (KeyValues *)Copy, keyName: "server/ping", value: (Int + nPing + 8 * Int) / 10);
            KeyValues::deleteThis(this: v27->m_pGameDetails);
          }
          v27->m_pGameDetails = (KeyValues *)Copy;
          v27->m_flLastRefresh = _Plat_FloatTime();
          v39 = (KeyValues *)KeyValues::operator new(iAllocSize: 0x24u);
          if ( v39 != nullptr )
            v40 = KeyValues::KeyValues(
                    this: v39,
                    setName: "OnMatchServerMgrUpdate",
                    firstKey: "update",
                    firstValue: "server");
          else
            v40 = nullptr;
          KeyValues::SetUint64(this: v40, keyName: "xuid", value: __PAIR64__(HIDWORD(xuidOnline), v23));
          v41 = g_pMatchFramework->GetEventsSubscription(this: g_pMatchFramework);
          ((void (__thiscall *)(IMatchEventsSubscription *))v41->BroadcastEvent)(a1: v41);
        }
      }
      return;
    }
    Uint64 = KeyValues::GetUint64(this: v6, keyName: "InetSearchServerDetails/pingxuid", defaultValue: 0);
    if ( Uint64 != 0 )
    {
      p_m_pElements = (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&v53->m_Servers.m_pElements;
      ServerRecordByOnlineId = CServerManager::GetServerRecordByOnlineId(
                                 this: (CServerManager *)((char *)v53 - 4),
                                 arr: (CUtlVector<CServer *,CUtlMemory<CServer *,int> > *)&v53->m_Servers.m_pElements,
                                 xuidServerOnline: Uint64);
      if ( ServerRecordByOnlineId == nullptr )
        return;
      v17 = KeyValues::GetFloat(this: v6, keyName: "InetSearchServerDetails/timestamp", defaultValue: 0.0);
      flTimeSent = v17;
      if ( v17 != 0.0 )
      {
        v18 = (int)((_Plat_FloatTime() - flTimeSent) * 1000.0);
        nPing = v18;
        if ( v18 >= 0 )
        {
          if ( v18 >= 1000 )
            nPing = 999;
        }
        else
        {
          nPing = 0;
        }
      }
      LODWORD(flTimeSent) = ServerRecordByOnlineId;
      CUtlVector<CServer *,CUtlMemory<CServer *,int>>::FindAndFastRemove(
        this: p_m_pElements,
        src: (CServer **)&flTimeSent);
      ((void (__thiscall *)(CServer *, int))ServerRecordByOnlineId->dtr_CServer)(a1: ServerRecordByOnlineId, a2: 1);
      goto LABEL_23;
    }
    if ( KeyValues::GetString(this: v6, keyName: "ConnectServerDetailsRequest/server", defaultValue: str) != nullptr )
      g_pMatchExtensions->m_exts.m_pINetSupport->OnMatchEvent(
        this: g_pMatchExtensions->m_exts.m_pINetSupport,
        a2: pEvent);
  }
}

} // namespace matchmaking_ds
