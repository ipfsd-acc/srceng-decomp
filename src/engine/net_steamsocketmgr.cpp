// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/net_steamsocketmgr.cpp
// Functions: 28
// ============================================================

#include "engine\net_steamsocketmgr.h"

//------------------------------------------------------------------------------
// Address: 0x1009D990
// Name: private: virtual int CCallback<class CSteam3Client,struct SocketStatusCallback_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCallback<CSteam3Client,SocketStatusCallback_t,0>::GetCallbackSizeBytes(SVC_Prefetch *this)
{
  return 20;
}

//------------------------------------------------------------------------------
// Address: 0x1012F760
// Name: private: virtual void CCallback<class CSteamSocketMgr,struct P2PSessionRequest_t,0>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSteamSocketMgr,P2PSessionRequest_t,0>::Run(
        CCallback<CSteam3Client,SocketStatusCallback_t,0> *this,
        SocketStatusCallback_t *pvParam,
        bool __formal,
        unsigned __int64 a4)
{
  this->m_Func(this: this->m_pObj, a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x1012F780
// Name: private: virtual int CCallback<class CSteam3Server,struct GSClientDeny_t,1>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CSteam3Server,GSClientDeny_t,1>::GetCallbackSizeBytes(
        CCallback<CSteam3Server,GSClientDeny_t,1> *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x101AEF40
// Name: public: char const __near * tokenset_t<enum ESocketIndex_t>::GetNameByToken(enum ESocketIndex_t)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall tokenset_t<enum ESocketIndex_t>::GetNameByToken(
        tokenset_t<enum ESocketIndex_t> *this,
        ESocketIndex_t token)
{
  if ( this->name == nullptr )
    return `tokenset_t<enum ESocketIndex_t>::GetNameByToken'::`2'::unknown;
  while ( this->token != token )
  {
    ++this;
    if ( this->name == nullptr )
      return `tokenset_t<enum ESocketIndex_t>::GetNameByToken'::`2'::unknown;
  }
  return this->name;
}

//------------------------------------------------------------------------------
// Address: 0x101AEF70
// Name: public: virtual void CSteamSocketMgr::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::Init(CSteamSocketMgr *this)
{
  ISteamNetworking *m_pSteamNetworking; // eax

  this->m_bInitialized = true;
  if ( Steam3Client()->m_pSteamNetworking != nullptr )
  {
    m_pSteamNetworking = Steam3Client()->m_pSteamNetworking;
    if ( net_steamcnx_allowrelay.m_pParent != nullptr )
      m_pSteamNetworking->AllowP2PPacketRelay(
        this: m_pSteamNetworking,
        a2: net_steamcnx_allowrelay.m_pParent->m_Value.m_nValue != 0);
    else
      m_pSteamNetworking->AllowP2PPacketRelay(this: m_pSteamNetworking, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AEFC0
// Name: public: virtual enum ISteamSocketMgr::ESteamCnxType CSteamSocketMgr::GetCnxType(void)
// Source: json
//------------------------------------------------------------------------------
ISteamSocketMgr::ESteamCnxType __thiscall CSteamSocketMgr::GetCnxType(CSteamSocketMgr *this)
{
  ISteamSocketMgr::ESteamCnxType result; // eax

  if ( net_steamcnx_enabled.m_pParent == nullptr )
    return ESCT_NEVER;
  result = net_steamcnx_enabled.m_pParent->m_Value.m_nValue;
  if ( result < ESCT_NEVER )
    return ESCT_NEVER;
  if ( result > ESCT_ALWAYS )
    return ESCT_ALWAYS;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AEFF0
// Name: private: virtual void CCallback<class CSteam3Server,struct SteamServerConnectFailure_t,1>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSteam3Server,SteamServerConnectFailure_t,1>::Run(
        CCallback<CSteam3Client,SocketStatusCallback_t,0> *this,
        SocketStatusCallback_t *pvParam)
{
  this->m_Func(this: this->m_pObj, a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x101AF1B0
// Name: class KeyValues __near * SessionMembersFindPlayer(class KeyValues __near *,unsigned __int64,class KeyValues __near * __near *)
// Source: json
//------------------------------------------------------------------------------
KeyValues *__cdecl SessionMembersFindPlayer(
        KeyValues *pSessionSettings,
        unsigned __int64 xuidPlayer,
        KeyValues **ppMachine)
{
  KeyValues *result; // eax
  KeyValues *v4; // edi
  int v5; // esi
  CFmtStrN<256> *v6; // eax
  KeyValues *Key; // eax
  KeyValues *v8; // ebx
  int v9; // edi
  CFmtStrN<256> *v10; // eax
  KeyValues *v11; // eax
  KeyValues *v12; // esi
  CFmtStrN<256> v13; // [esp+0h] [ebp-224h] BYREF
  CFmtStrN<256> v14; // [esp+10Ch] [ebp-118h] BYREF
  int numPlayers; // [esp+218h] [ebp-Ch]
  KeyValues *pMembers; // [esp+21Ch] [ebp-8h]
  int numMachines; // [esp+220h] [ebp-4h]
  int k; // [esp+22Ch] [ebp+8h]

  if ( ppMachine != nullptr )
    *ppMachine = nullptr;
  if ( pSessionSettings == nullptr )
    return nullptr;
  result = KeyValues::FindKey(this: pSessionSettings, keyName: "Members", bCreate: false);
  v4 = result;
  pMembers = result;
  if ( result != nullptr )
  {
    v5 = 0;
    numMachines = KeyValues::GetInt(this: result, keyName: "numMachines", defaultValue: 0);
    k = 0;
    if ( numMachines > 0 )
    {
      while ( 1 )
      {
        v6 = CFmtStrN<256>::CFmtStrN<256>(this: &v14, pszFormat: "machine%d", v5);
        Key = KeyValues::FindKey(this: v4, keyName: v6->m_szBuf, bCreate: false);
        v8 = Key;
        if ( Key != nullptr )
        {
          v9 = 0;
          numPlayers = KeyValues::GetInt(this: Key, keyName: "numPlayers", defaultValue: 0);
          if ( numPlayers > 0 )
            break;
        }
LABEL_15:
        k = ++v5;
        if ( v5 >= numMachines )
          return nullptr;
        v4 = pMembers;
      }
      while ( 1 )
      {
        v10 = CFmtStrN<256>::CFmtStrN<256>(this: &v13, pszFormat: "player%d", v9);
        v11 = KeyValues::FindKey(this: v8, keyName: v10->m_szBuf, bCreate: false);
        v12 = v11;
        if ( v11 != nullptr && KeyValues::GetUint64(this: v11, keyName: "xuid", defaultValue: 0) == xuidPlayer )
          break;
        if ( ++v9 >= numPlayers )
        {
          v5 = k;
          goto LABEL_15;
        }
      }
      if ( ppMachine != nullptr )
        *ppMachine = v8;
      return v12;
    }
    else
    {
      return nullptr;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF2E0
// Name: private: class CSteamSocket __near * CSteamSocketMgr::FindSocketForUser(enum ESocketIndex_t,class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
CSteamSocket *__thiscall CSteamSocketMgr::FindSocketForUser(
        CSteamSocketMgr *this,
        ESocketIndex_t eSocketType,
        const CSteamID *steamID)
{
  int m_Size; // esi
  int v4; // edx
  CSteamSocket **i; // ecx
  CSteamSocket *result; // eax

  m_Size = this->m_vecRemoteSockets.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = this->m_vecRemoteSockets.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    if ( (*i)->m_steamID.m_steamid.m_comp == steamID->m_steamid.m_comp
      && *((_DWORD *)&result->m_steamID.m_steamid.m_comp + 1) == *((_DWORD *)&steamID->m_steamid.m_comp + 1)
      && result->m_eSocketType == eSocketType )
    {
      break;
    }
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF330
// Name: public: void CSteamSocketMgr::OnP2PSessionRequest(struct P2PSessionRequest_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::OnP2PSessionRequest(CSteamSocketMgr *this, int pParam)
{
  IMatchSession *v2; // eax
  P2PSessionRequest_t *v3; // esi
  KeyValues *v4; // eax
  CSteam3Client *v5; // eax
  unsigned __int64 v6; // [esp-10h] [ebp-10h]
  CSteamID::SteamID_t v7; // [esp-Ch] [ebp-Ch]

  if ( g_pMatchFramework != nullptr && g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) != nullptr )
  {
    v2 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
    v3 = (P2PSessionRequest_t *)pParam;
    v6 = *(_QWORD *)pParam;
    v4 = v2->GetSessionSettings(this: v2);
    if ( SessionMembersFindPlayer(pSessionSettings: v4, xuidPlayer: v6, ppMachine: nullptr) != nullptr )
    {
      v5 = Steam3Client();
      ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD))v5->m_pSteamNetworking->AcceptP2PSessionWithUser)(
        a1: v5->m_pSteamNetworking,
        a2: *(_DWORD *)&v3->m_steamIDRemote.m_steamid.m_comp,
        a3: *((_DWORD *)&v3->m_steamIDRemote.m_steamid.m_comp + 1));
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
      {
        v7.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)v3->m_steamIDRemote.m_steamid;
        pParam = -10158081;
        ConColorMsg(a1: (const struct Color *)&pParam, a2: "Accepted P2P connection with %llx\n", v7.m_unAll64Bits);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF3D0
// Name: public: void CSteamSocketMgr::PrintStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::PrintStatus(CSteamSocketMgr *this)
{
  CSteamSocketMgr *v1; // ebx
  int v2; // edi
  CSteamSocket *v3; // esi
  CSteam3Client *v4; // eax
  const char *v5; // edx
  const tokenset_t<enum EP2PSessionError> *v6; // eax
  char *name; // ecx
  const tokenset_t<enum ESocketIndex_t> *v8; // eax
  const char *v9; // eax
  unsigned int m_unAll64Bits; // edi
  unsigned int m_unAll64Bits_high; // ebx
  const char *v12; // eax
  const char *v13; // [esp-1Ch] [ebp-54h]
  const char *v14; // [esp-18h] [ebp-50h]
  const char *v15; // [esp-14h] [ebp-4Ch]
  int m_nBytesQueuedForSend; // [esp-10h] [ebp-48h]
  CSteamID::SteamID_t v17; // [esp-Ch] [ebp-44h]
  int m_nPacketsQueuedForSend; // [esp-Ch] [ebp-44h]
  int m_Size; // [esp-8h] [ebp-40h]
  const char *v20; // [esp-8h] [ebp-40h]
  P2PSessionState_t p2pSessionState; // [esp+8h] [ebp-30h] BYREF
  CSteamSocketMgr *v22; // [esp+1Ch] [ebp-1Ch]
  const char *v23; // [esp+20h] [ebp-18h]
  const char *v24; // [esp+24h] [ebp-14h]
  const char *v25; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int v27; // [esp+30h] [ebp-8h] BYREF
  int v28; // [esp+34h] [ebp-4h] BYREF

  v1 = this;
  v22 = this;
  v28 = -10158081;
  ConColorMsg(a1: (const struct Color *)&v28, a2: "SteamSocketMgr Status\n");
  if ( v1->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    m_Size = v1->m_vecRemoteSockets.m_Size;
    v28 = -10158081;
    ConColorMsg(a1: (const struct Color *)&v28, a2: " %d connections\n", m_Size);
    v2 = 0;
    for ( i = 0; v2 < v1->m_vecRemoteSockets.m_Size; i = v2 )
    {
      v3 = v1->m_vecRemoteSockets.m_Memory.m_pMemory[v2];
      v4 = Steam3Client();
      if ( ((unsigned __int8 (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, P2PSessionState_t *))v4->m_pSteamNetworking->GetP2PSessionState)(
             a1: v4->m_pSteamNetworking,
             a2: *(_DWORD *)&v3->m_steamID.m_steamid.m_comp,
             a3: *((_DWORD *)&v3->m_steamID.m_steamid.m_comp + 1),
             a4: &p2pSessionState) != 0 )
      {
        v25 = "yes";
        if ( p2pSessionState.m_bUsingRelay == 0 )
          v25 = "no";
        v24 = "yes";
        if ( p2pSessionState.m_bConnecting == 0 )
          v24 = "no";
        v5 = "yes";
        if ( p2pSessionState.m_bConnectionActive == 0 )
          v5 = "no";
        v6 = s_EP2PSessionErrorIndexMap;
        if ( "None" != nullptr )
        {
          while ( v6->token != p2pSessionState.m_eP2PSessionError )
          {
            ++v6;
            if ( v6->name == nullptr )
              goto LABEL_16;
          }
          name = (char *)v6->name;
        }
        else
        {
LABEL_16:
          name = `tokenset_t<enum EP2PSessionError>::GetNameByToken'::`2'::unknown[0];
        }
        v8 = s_SocketIndexMap;
        if ( "NS_CLIENT" != nullptr )
        {
          while ( v8->token != v3->m_eSocketType )
          {
            ++v8;
            if ( v8->name == nullptr )
              goto LABEL_20;
          }
          v9 = v8->name;
        }
        else
        {
LABEL_20:
          v9 = `tokenset_t<enum ESocketIndex_t>::GetNameByToken'::`2'::unknown;
        }
        m_unAll64Bits = v3->m_steamID.m_steamid.m_unAll64Bits;
        m_unAll64Bits_high = HIDWORD(v3->m_steamID.m_steamid.m_unAll64Bits);
        v20 = name;
        m_nPacketsQueuedForSend = p2pSessionState.m_nPacketsQueuedForSend;
        v23 = v9;
        m_nBytesQueuedForSend = p2pSessionState.m_nBytesQueuedForSend;
        v15 = v25;
        v14 = v24;
        v13 = v5;
        v27 = -10158081;
        v12 = netadr_s::ToString(this: &v3->m_addr, baseOnly: false);
        ConColorMsg(
          a1: (const struct Color *)&v27,
          a2: " %d %llx, type(%s), psuedoAddr(%s), connected(%s), connecting(%s), relay(%s), bytesQueued(%d), packetsQueued(%"
          "d), lasterror(%s)\n",
          i,
          __PAIR64__(m_unAll64Bits_high, m_unAll64Bits),
          v23,
          v12,
          v13,
          v14,
          v15,
          m_nBytesQueuedForSend,
          m_nPacketsQueuedForSend,
          v20);
        v1 = v22;
        v2 = i;
      }
      else
      {
        v17.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)v3->m_steamID.m_steamid;
        v28 = -10158081;
        ConColorMsg(
          a1: (const struct Color *)&v28,
          a2: " %d %llx, failed to get session state\n",
          v2,
          v17.m_unAll64Bits);
      }
      ++v2;
    }
  }
  else
  {
    v28 = -10158081;
    ConColorMsg(a1: (const struct Color *)&v28, a2: " Invalid (no Steam3Client API?)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF590
// Name: net_steamcnx_status
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_steamcnx_status()
{
  CSteamSocketMgr::PrintStatus(this: &g_SteamSocketMgr);
}

//------------------------------------------------------------------------------
// Address: 0x101B2E00
// Name: private: class CSteamSocket __near * CSteamSocketMgr::FindSocketForAddress(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
CSteamSocket *__thiscall CSteamSocketMgr::FindSocketForAddress(CSteamSocketMgr *this, const netadr_s *adr)
{
  int v3; // edx
  int v4; // eax
  unsigned __int16 v5; // ax
  CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t v7; // [esp+4h] [ebp-10h] BYREF

  netadr_s::SetIP(this: &v7.key, unIP: 0);
  netadr_s::SetPort(this: &v7.key, newport: 0);
  netadr_s::SetType(this: &v7.key, newtype: NA_IP);
  v3 = *(_DWORD *)adr->ip;
  v4 = *(_DWORD *)&adr->port;
  v7.key.type = adr->type;
  *(_DWORD *)v7.key.ip = v3;
  *(_DWORD *)&v7.key.port = v4;
  v5 = CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapAdrToSteamSocket.m_Tree,
         search: &v7);
  if ( v5 == 0xFFFF )
    return nullptr;
  else
    return this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x101B2E70
// Name: private: bool CSteamSocketMgr::GetTypeForSocket(int,enum ESocketIndex_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamSocketMgr::GetTypeForSocket(CSteamSocketMgr *this, int s, ESocketIndex_t *peType)
{
  unsigned __int16 v4; // ax
  CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = s;
  v4 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapSocketToESocketType.m_Tree,
         &search);
  if ( v4 == 0xFFFF )
    return 0;
  *peType = this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B2EC0
// Name: public: virtual unsigned __int64 CSteamSocketMgr::GetSteamIDForRemote(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
CSteamID::SteamID_t __thiscall CSteamSocketMgr::GetSteamIDForRemote(CSteamSocketMgr *this, const netadr_s *remote)
{
  CSteamSocket *SocketForAddress; // eax

  SocketForAddress = CSteamSocketMgr::FindSocketForAddress(this, adr: remote);
  if ( SocketForAddress != nullptr )
    return SocketForAddress->m_steamID.m_steamid;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B2F60
// Name: public: virtual int CSteamSocketMgr::sendto(int,char const __near *,int,int,struct sockaddr const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamSocketMgr::sendto(
        CSteamSocketMgr *this,
        int s,
        const char *buf,
        int len,
        int flags,
        ESocketIndex_t to,
        int tolen)
{
  const sockaddr *v7; // ebx
  CSteamSocket *SocketForAddress; // esi
  CSteam3Client *v10; // eax
  CSteam3Client *v11; // eax
  char v12; // bl
  const char *v13; // edx
  const char *v14; // ecx
  const char *NameByToken; // eax
  int v17; // esi
  const char *v18; // eax
  const char *v19; // [esp-8h] [ebp-34h]
  const char *v20; // [esp-4h] [ebp-30h]
  P2PSessionState_t p2pSessionState; // [esp+Ch] [ebp-20h] BYREF
  netadr_s adr; // [esp+20h] [ebp-Ch] BYREF

  v7 = (const sockaddr *)to;
  if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    netadr_s::SetIP(this: &adr, unIP: 0);
    netadr_s::SetPort(this: &adr, newport: 0);
    netadr_s::SetType(this: &adr, newtype: NA_IP);
    netadr_s::SetFromSockadr(this: &adr, s: v7);
    SocketForAddress = CSteamSocketMgr::FindSocketForAddress(this, &adr);
    if ( SocketForAddress != nullptr )
    {
      v10 = Steam3Client();
      ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, const char *, int, _DWORD, bool))v10->m_pSteamNetworking->SendP2PPacket)(
        a1: v10->m_pSteamNetworking,
        a2: *(_DWORD *)&SocketForAddress->m_steamID.m_steamid.m_comp,
        a3: *((_DWORD *)&SocketForAddress->m_steamID.m_steamid.m_comp + 1),
        a4: buf,
        a5: len,
        a6: 0,
        a7: SocketForAddress->m_eSocketType == NS_CLIENT);
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue >= 3 )
      {
        _V_memset(dest: &p2pSessionState, fill: 0, count: 20);
        v11 = Steam3Client();
        v12 = ((int (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, P2PSessionState_t *))v11->m_pSteamNetworking->GetP2PSessionState)(
                a1: v11->m_pSteamNetworking,
                a2: *(_DWORD *)&SocketForAddress->m_steamID.m_steamid.m_comp,
                a3: *((_DWORD *)&SocketForAddress->m_steamID.m_steamid.m_comp + 1),
                a4: &p2pSessionState);
        to = NS_INVALID;
        CSteamSocketMgr::GetTypeForSocket(this, s, peType: &to);
        v13 = "connected";
        if ( p2pSessionState.m_bConnectionActive == 0 )
          v13 = "not connected";
        v14 = "true";
        if ( v12 == 0 )
          v14 = "false";
        v20 = v13;
        v19 = v14;
        buf = (const char *)-10158081;
        NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                        this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                        token: to);
        ConColorMsg(
          a1: (const struct Color *)&buf,
          a2: "  Send to %llx %u bytes on %s (status %s - %s)\n",
          SocketForAddress->m_steamID.m_steamid.m_unAll64Bits,
          len,
          NameByToken,
          v19,
          v20);
      }
      return len;
    }
    if ( netadr_s::GetPort(this: &adr) == 1 )
    {
      v17 = len;
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue >= 1 )
      {
        len = -10158081;
        v18 = netadr_s::ToString(this: &adr, baseOnly: false);
        ConColorMsg(
          a1: (const struct Color *)&len,
          a2: "  Attempted to send %u bytes on unknown steam socket address %s\n",
          v17,
          v18);
      }
      return v17;
    }
  }
  return sendto(s, buf, len, flags, to: v7, tolen);
}

//------------------------------------------------------------------------------
// Address: 0x101B32A0
// Name: public: virtual void CSteamSocketMgr::OpenSocket(int,int,int,int,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::OpenSocket(
        CSteamSocketMgr *this,
        int s,
        unsigned int nModule,
        int nSetPort,
        int nDefaultPort,
        const char *pName,
        int nProtocol,
        bool bTryAny)
{
  __int32 elem; // esi
  bool v9; // zf
  ESocketIndex_t v10; // edi
  int v11; // ebx
  unsigned __int16 v12; // ax
  const tokenset_t<enum ESocketIndex_t> *v13; // eax
  const char *name; // eax
  CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  elem = (__int32)this;
  v9 = !this->m_bInitialized;
  search.elem = (ESocketIndex_t)this;
  if ( !v9 && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    v10 = nModule;
    if ( nModule <= 1 )
    {
      v11 = 0;
      if ( *(_WORD *)(elem + 100) != 0 )
      {
        while ( (unsigned __int16)v11 >= *(int *)(search.elem + 100)
             || (unsigned __int16)v11 > *(_WORD *)(search.elem + 114)
             || CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                  this: (CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(search.elem + 92),
                  i: v11) == (_WORD)v11
             || *(_DWORD *)(*(_DWORD *)(search.elem + 96) + 16 * (unsigned __int16)v11 + 12) != nModule )
        {
          if ( ++v11 >= *(unsigned __int16 *)(search.elem + 100) )
          {
            v10 = nModule;
            elem = search.elem;
            goto LABEL_11;
          }
        }
      }
      else
      {
LABEL_11:
        search.key = s;
        v12 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: (CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(elem + 92),
                &search);
        if ( v12 == 0xFFFF )
        {
          search.key = s;
          search.elem = v10;
          CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
            this: (CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(elem + 92),
            insert: &search);
        }
        else
        {
          *(_DWORD *)(*(_DWORD *)(elem + 96) + 16 * v12 + 12) = v10;
        }
        if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
        {
          v13 = s_SocketIndexMap;
          if ( "NS_CLIENT" != nullptr )
          {
            while ( v13->token != v10 )
            {
              ++v13;
              if ( v13->name == nullptr )
                goto LABEL_19;
            }
            name = v13->name;
          }
          else
          {
LABEL_19:
            name = `tokenset_t<enum ESocketIndex_t>::GetNameByToken'::`2'::unknown;
          }
          nModule = -10158081;
          ConColorMsg(a1: (const struct Color *)&nModule, a2: "Opened Steam Socket %s ( socket %d )\n", name, s);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B33D0
// Name: private: class CSteamSocket __near * CSteamSocketMgr::CreateConnection(enum ESocketIndex_t,class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
CSteamSocket *__thiscall CSteamSocketMgr::CreateConnection(
        CSteamSocketMgr *this,
        ESocketIndex_t eSocketType,
        int steamID)
{
  CSteamSocket *result; // eax
  int v5; // edi
  unsigned int m_nNextRemoteAddress; // eax
  const char *v7; // eax
  netadr_s *v8; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CSteamSocket **m_pMemory; // ecx
  int v12; // eax
  CSteamSocket **v13; // ebx
  const char *NameByToken; // eax
  __int64 v15; // [esp-10h] [ebp-24h]
  __int64 v16; // [esp-10h] [ebp-24h]
  netadr_s adrRemote; // [esp+4h] [ebp-10h] BYREF
  CSteamSocket *pSocket; // [esp+10h] [ebp-4h] BYREF

  if ( !this->m_bInitialized || Steam3Client()->m_pSteamNetworking == nullptr )
    return nullptr;
  v5 = steamID;
  result = CSteamSocketMgr::FindSocketForUser(this, eSocketType, (const CSteamID *)steamID);
  if ( result == nullptr )
  {
    m_nNextRemoteAddress = this->m_nNextRemoteAddress;
    this->m_nNextRemoteAddress = m_nNextRemoteAddress + 1;
    netadr_s::SetIP(this: &adrRemote, unIP: m_nNextRemoteAddress);
    netadr_s::SetPort(this: &adrRemote, newport: 1u);
    netadr_s::SetType(this: &adrRemote, newtype: NA_IP);
    v15 = *(_QWORD *)v5;
    steamID = -10158081;
    v7 = netadr_s::ToString(this: &adrRemote, baseOnly: false);
    ConColorMsg(a1: (const struct Color *)&steamID, a2: "Generated %s for %llx\n", v7, v15);
    v8 = (netadr_s *)MemAlloc_Alloc(nSize: 0x18u);
    if ( v8 != nullptr )
    {
      v8->type = *(_DWORD *)v5;
      *(_DWORD *)v8->ip = *(_DWORD *)(v5 + 4);
      *(_DWORD *)&v8->port = eSocketType;
      v8[1] = adrRemote;
      pSocket = (CSteamSocket *)v8;
    }
    else
    {
      pSocket = nullptr;
    }
    CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Insert(
      this: &this->m_mapAdrToSteamSocket,
      key: &adrRemote,
      insert: &pSocket);
    m_Size = this->m_vecRemoteSockets.m_Size;
    m_nAllocationCount = this->m_vecRemoteSockets.m_Memory.m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<INetMessage *,int>::Grow(
        this: (CUtlMemory<S3RGBA,int> *)&this->m_vecRemoteSockets,
        num: m_Size - m_nAllocationCount + 1);
    ++this->m_vecRemoteSockets.m_Size;
    m_pMemory = this->m_vecRemoteSockets.m_Memory.m_pMemory;
    v12 = this->m_vecRemoteSockets.m_Size - m_Size - 1;
    this->m_vecRemoteSockets.m_pElements = m_pMemory;
    if ( v12 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
    v13 = &this->m_vecRemoteSockets.m_Memory.m_pMemory[m_Size];
    if ( v13 != nullptr )
      *v13 = pSocket;
    if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v16 = *(_QWORD *)v5;
      steamID = -10158081;
      NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                      this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                      token: eSocketType);
      ConColorMsg(a1: (const struct Color *)&steamID, a2: "Created %s connection to %llx\n", NameByToken, v16);
    }
    return pSocket;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B3540
// Name: private: void CSteamSocketMgr::DestroyConnection(class CSteamSocket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::DestroyConnection(CSteamSocketMgr *this, int pSocket)
{
  CSteamSocket *v3; // esi
  CSteam3Client *v4; // eax
  CSteam3Client *v5; // eax
  const char *NameByToken; // eax
  ESocketIndex_t m_eSocketType; // [esp-10h] [ebp-14h]
  CSteamID::SteamID_t v8; // [esp-Ch] [ebp-10h]

  if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    v3 = (CSteamSocket *)pSocket;
    if ( pSocket != 0 )
    {
      CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Remove(
        this: &this->m_mapAdrToSteamSocket,
        key: (const netadr_s *)(pSocket + 12));
      CUtlVector<CSteamSocket *,CUtlMemory<CSteamSocket *,int>>::FindAndFastRemove(
        this: &this->m_vecRemoteSockets,
        src: (CSteamSocket *const *)&pSocket);
      v4 = Steam3Client();
      ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, bool))v4->m_pSteamNetworking->CloseP2PChannelWithUser)(
        a1: v4->m_pSteamNetworking,
        a2: *(_DWORD *)&v3->m_steamID.m_steamid.m_comp,
        a3: *((_DWORD *)&v3->m_steamID.m_steamid.m_comp + 1),
        a4: v3->m_eSocketType != NS_CLIENT);
      v5 = Steam3Client();
      ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, bool))v5->m_pSteamNetworking->CloseP2PChannelWithUser)(
        a1: v5->m_pSteamNetworking,
        a2: *(_DWORD *)&v3->m_steamID.m_steamid.m_comp,
        a3: *((_DWORD *)&v3->m_steamID.m_steamid.m_comp + 1),
        a4: v3->m_eSocketType == NS_CLIENT);
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
      {
        v8.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)v3->m_steamID.m_steamid;
        m_eSocketType = v3->m_eSocketType;
        pSocket = -10158081;
        NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                        this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                        token: m_eSocketType);
        ConColorMsg(
          a1: (const struct Color *)&pSocket,
          a2: "Destroyed %s connection to %llx\n",
          NameByToken,
          v8.m_unAll64Bits);
      }
      free(pMem: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3610
// Name: public: void CSteamSocketMgr::OnP2PSessionConnectFail(struct P2PSessionConnectFail_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::OnP2PSessionConnectFail(CSteamSocketMgr *this, int pParam)
{
  P2PSessionConnectFail_t *v2; // edi
  const tokenset_t<enum EP2PSessionError> *v4; // eax
  const char *name; // eax
  int i; // esi
  CSteamSocket *v7; // eax
  CSteamID::SteamID_t v8; // [esp-Ch] [ebp-18h]

  v2 = (P2PSessionConnectFail_t *)pParam;
  if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = s_EP2PSessionErrorIndexMap;
    if ( "None" != nullptr )
    {
      while ( v4->token != *(unsigned __int8 *)(pParam + 8) )
      {
        ++v4;
        if ( v4->name == nullptr )
          goto LABEL_6;
      }
      name = v4->name;
    }
    else
    {
LABEL_6:
      name = `tokenset_t<enum EP2PSessionError>::GetNameByToken'::`2'::unknown[0];
    }
    v8.m_comp = *(CSteamID::SteamID_t::SteamIDComponent_t *)pParam;
    pParam = -10158081;
    ConColorMsg(
      a1: (const struct Color *)&pParam,
      a2: "Received connection fail for user %llx %s\n",
      v8.m_unAll64Bits,
      name);
  }
  for ( i = this->m_vecRemoteSockets.m_Size - 1; i >= 0; --i )
  {
    v7 = this->m_vecRemoteSockets.m_Memory.m_pMemory[i];
    if ( v7->m_steamID.m_steamid.m_comp == v2->m_steamIDRemote.m_steamid.m_comp
      && *((_DWORD *)&v7->m_steamID.m_steamid.m_comp + 1) == *((_DWORD *)&v2->m_steamIDRemote.m_steamid.m_comp + 1) )
    {
      CSteamSocketMgr::DestroyConnection(this, pSocket: (int)this->m_vecRemoteSockets.m_Memory.m_pMemory[i]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B36B0
// Name: public: virtual int CSteamSocketMgr::recvfrom(int,char __near *,int,int,struct sockaddr __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamSocketMgr::recvfrom(
        CSteamSocketMgr *this,
        int s,
        char *buf,
        int len,
        unsigned int flags,
        sockaddr *from,
        int *fromlen)
{
  int v7; // ebx
  int result; // eax
  unsigned __int16 v10; // ax
  ESocketIndex_t elem; // edi
  CSteam3Client *v12; // eax
  CSteamSocket *SocketForUser; // eax
  const char *NameByToken; // eax
  sockaddr *v15; // [esp-4h] [ebp-20h]
  CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CSteamID steamIDRemote; // [esp+14h] [ebp-8h] BYREF

  v7 = len;
  result = recvfrom(s, buf, len, flags, from, fromlen);
  if ( result <= 0 )
  {
    if ( this->m_bInitialized
      && Steam3Client()->m_pSteamNetworking != nullptr
      && (search.key = s,
          (v10 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &this->m_mapSocketToESocketType.m_Tree,
                   &search)) != 0xFFFF)
      && (elem = this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem,
          flags = 0,
          steamIDRemote.m_steamid.m_comp = 0,
          v12 = Steam3Client(),
          v12->m_pSteamNetworking->ReadP2PPacket(
            this: v12->m_pSteamNetworking,
            a2: buf,
            a3: v7,
            a4: &flags,
            a5: &steamIDRemote,
            a6: elem != NS_CLIENT))
      && flags != 0 )
    {
      SocketForUser = CSteamSocketMgr::FindSocketForUser(this, eSocketType: elem, steamID: &steamIDRemote);
      if ( SocketForUser == nullptr )
        SocketForUser = CSteamSocketMgr::CreateConnection(this, eSocketType: elem, steamID: &steamIDRemote);
      v15 = from;
      *fromlen = 16;
      netadr_s::ToSockadr(this: &SocketForUser->m_addr, s: v15);
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue >= 3 )
      {
        buf = (char *)-10158081;
        NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                        this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                        token: elem);
        ConColorMsg(
          a1: (const struct Color *)&buf,
          a2: "  Received from %llx %u bytes on %s\n",
          steamIDRemote.m_steamid.m_comp,
          flags,
          NameByToken);
      }
      return flags;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B37F0
// Name: void NET_TerminateSteamConnection(int,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_TerminateSteamConnection(ESocketIndex_t sock, unsigned __int64 uSteamID)
{
  unsigned __int64 v2; // kr00_8
  CSteamSocket *SocketForUser; // eax
  unsigned __int64 v4; // [esp-8h] [ebp-10h]

  v2 = uSteamID;
  if ( uSteamID != 0 )
  {
    if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v4 = uSteamID;
      HIDWORD(uSteamID) = -10158081;
      ConColorMsg(a1: (const struct Color *)&uSteamID + 1, a2: "Terminate %llx\n", v4);
    }
    uSteamID = v2;
    if ( g_SteamSocketMgr.m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
    {
      SocketForUser = CSteamSocketMgr::FindSocketForUser(
                        this: &g_SteamSocketMgr,
                        eSocketType: sock,
                        steamID: (const CSteamID *)&uSteamID);
      CSteamSocketMgr::DestroyConnection(this: &g_SteamSocketMgr, pSocket: (int)SocketForUser);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3870
// Name: public: CSteamSocketMgr::CSteamSocketMgr(void)
// Source: json
//------------------------------------------------------------------------------
CSteamSocketMgr *__thiscall CSteamSocketMgr::CSteamSocketMgr(CSteamSocketMgr *this)
{
  UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx

  this->__vftable = (CSteamSocketMgr_vtbl *)&CSteamSocketMgr::`vftable';
  this->m_callbackP2PSessionRequest.m_nCallbackFlags = 0;
  this->m_callbackP2PSessionRequest.m_iCallback = 0;
  this->m_callbackP2PSessionRequest.__vftable = (CCallback<CSteamSocketMgr,P2PSessionRequest_t,0>_vtbl *)&CCallback<CSteamSocketMgr,P2PSessionRequest_t,0>::`vftable';
  this->m_callbackP2PSessionRequest.m_pObj = this;
  this->m_callbackP2PSessionRequest.m_Func = (void (__thiscall *)(CSteamSocketMgr *, P2PSessionRequest_t *))CSteamSocketMgr::OnP2PSessionRequest;
  if ( CSteamSocketMgr::OnP2PSessionRequest != nullptr )
  {
    this->m_callbackP2PSessionRequest.m_pObj = this;
    this->m_callbackP2PSessionRequest.m_Func = (void (__thiscall *)(CSteamSocketMgr *, P2PSessionRequest_t *))CSteamSocketMgr::OnP2PSessionRequest;
    _SteamAPI_RegisterCallback(a1: &this->m_callbackP2PSessionRequest, a2: 1202);
  }
  this->m_callbackP2PSessionConnectFail.m_nCallbackFlags = 0;
  this->m_callbackP2PSessionConnectFail.m_iCallback = 0;
  this->m_callbackP2PSessionConnectFail.__vftable = (CCallback<CSteamSocketMgr,P2PSessionConnectFail_t,0>_vtbl *)&CCallback<CSteamSocketMgr,P2PSessionConnectFail_t,0>::`vftable';
  this->m_callbackP2PSessionConnectFail.m_pObj = this;
  this->m_callbackP2PSessionConnectFail.m_Func = (void (__thiscall *)(CSteamSocketMgr *, P2PSessionConnectFail_t *))CSteamSocketMgr::OnP2PSessionConnectFail;
  if ( CSteamSocketMgr::OnP2PSessionConnectFail != nullptr )
  {
    this->m_callbackP2PSessionConnectFail.m_pObj = this;
    this->m_callbackP2PSessionConnectFail.m_Func = (void (__thiscall *)(CSteamSocketMgr *, P2PSessionConnectFail_t *))CSteamSocketMgr::OnP2PSessionConnectFail;
    _SteamAPI_RegisterCallback(a1: &this->m_callbackP2PSessionConnectFail, a2: 1203);
  }
  this->m_vecRemoteSockets.m_Memory.m_pMemory = nullptr;
  this->m_vecRemoteSockets.m_Memory.m_nAllocationCount = 0;
  this->m_vecRemoteSockets.m_Memory.m_nGrowSize = 0;
  this->m_vecRemoteSockets.m_Size = 0;
  this->m_vecRemoteSockets.m_pElements = nullptr;
  this->m_mapAdrToSteamSocket.m_Tree.m_LessFunc.m_LessFunc = CDefOps<netadr_s>::LessFunc;
  this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapAdrToSteamSocket.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapAdrToSteamSocket.m_Tree.m_FirstFree = -1;
  this->m_mapAdrToSteamSocket.m_Tree.m_pElements = m_pMemory;
  this->m_mapSocketToESocketType.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CIPRateLimit::LessIP;
  this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapSocketToESocketType.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapSocketToESocketType.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_mapSocketToESocketType.m_Tree.m_pElements = this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapSocketToESocketType.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapSocketToESocketType.m_Tree.m_FirstFree = -1;
  this->m_bInitialized = false;
  this->m_nNextRemoteAddress = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B3950
// Name: public: virtual void CSteamSocketMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::Shutdown(CSteamSocketMgr *this)
{
  int i; // edi

  if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    for ( i = this->m_vecRemoteSockets.m_Size - 1; i >= 0; --i )
      CSteamSocketMgr::DestroyConnection(this, pSocket: this->m_vecRemoteSockets.m_Memory.m_pMemory[i]);
    this->m_vecRemoteSockets.m_Size = 0;
    CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapAdrToSteamSocket.m_Tree);
    CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapSocketToESocketType.m_Tree);
    this->m_bInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B39A0
// Name: public: virtual void CSteamSocketMgr::CloseSocket(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::CloseSocket(CSteamSocketMgr *this, ESocketIndex_t nModule)
{
  const char *NameByToken; // eax
  int i; // esi
  CSteamSocket **m_pMemory; // ecx
  unsigned __int16 Inorder; // si
  int v7; // eax
  int v8; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr && (unsigned int)nModule <= NS_SERVER )
  {
    if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v8 = -10158081;
      NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                      this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                      token: nModule);
      ConColorMsg(a1: (const struct Color *)&v8, a2: "Closed Steam Socket %s\n", NameByToken);
    }
    for ( i = this->m_vecRemoteSockets.m_Size - 1; i >= 0; --i )
    {
      m_pMemory = this->m_vecRemoteSockets.m_Memory.m_pMemory;
      if ( m_pMemory[i]->m_eSocketType == nModule )
        CSteamSocketMgr::DestroyConnection(this, pSocket: m_pMemory[i]);
    }
    Inorder = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapSocketToESocketType.m_Tree);
    if ( Inorder != 0xFFFF )
    {
      while ( this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem != nModule )
      {
        Inorder = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: &this->m_mapSocketToESocketType.m_Tree,
                    i: Inorder);
        if ( Inorder == 0xFFFF )
          return;
      }
      if ( Inorder != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_mapSocketToESocketType.m_Tree,
          elem: Inorder);
        v7 = Inorder;
        this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[v7].m_Left = Inorder;
        this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[v7].m_Right = this->m_mapSocketToESocketType.m_Tree.m_FirstFree;
        --this->m_mapSocketToESocketType.m_Tree.m_NumElements;
        this->m_mapSocketToESocketType.m_Tree.m_FirstFree = Inorder;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3AB0
// Name: public: class CSteamSocket __near * CSteamSocketMgr::InitiateConnection(enum ESocketIndex_t,class CSteamID const __near &,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSteamSocket *__thiscall CSteamSocketMgr::InitiateConnection(
        CSteamSocketMgr *this,
        ESocketIndex_t eSocketTypeFrom,
        const CSteamID *steamID,
        const unsigned __int8 *data,
        unsigned int len)
{
  CSteamSocket *Connection; // esi
  CSteam3Client *v7; // eax
  CSteamSocket *SocketForUser; // eax

  Connection = CSteamSocketMgr::CreateConnection(this, eSocketType: eSocketTypeFrom, (int)steamID);
  if ( Connection == nullptr )
    return nullptr;
  v7 = Steam3Client();
  if ( ((unsigned int (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, const unsigned __int8 *, unsigned int, int, bool))v7->m_pSteamNetworking->SendP2PPacket)(
         a1: v7->m_pSteamNetworking,
         a2: *(_DWORD *)&Connection->m_steamID.m_steamid.m_comp,
         a3: *((_DWORD *)&Connection->m_steamID.m_steamid.m_comp + 1),
         a4: data,
         a5: len,
         a6: 2,
         a7: Connection->m_eSocketType == NS_CLIENT) == 0 )
  {
    if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
    {
      SocketForUser = CSteamSocketMgr::FindSocketForUser(this, eSocketType: eSocketTypeFrom, steamID);
      CSteamSocketMgr::DestroyConnection(this, pSocket: (int)SocketForUser);
    }
    return nullptr;
  }
  return Connection;
}

//------------------------------------------------------------------------------
// Address: 0x101B3B30
// Name: struct netadr_s NET_InitiateSteamConnection(int,unsigned __int64,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
netadr_s *NET_InitiateSteamConnection(
        netadr_s *result,
        ESocketIndex_t sock,
        unsigned __int64 uSteamID,
        const char *format,
        ...)
{
  CSteamID::SteamID_t v4; // kr00_8
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  CSteamSocket *v9; // eax
  netadr_s *v10; // esi
  int v11; // ecx
  int v12; // edx
  char string[1200]; // [esp+8h] [ebp-4F4h] BYREF
  CUtlBuffer sendBuf; // [esp+4B8h] [ebp-44h] BYREF
  CSteamID steamID; // [esp+4E8h] [ebp-14h] BYREF
  netadr_s adr; // [esp+4F0h] [ebp-Ch] BYREF
  va_list params; // [esp+518h] [ebp+1Ch] BYREF

  va_start(params, format);
  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  v4.m_unAll64Bits = uSteamID;
  if ( uSteamID != 0 )
  {
    V_vsnprintf(pDest: string, maxLen: 1200, pFormat: format, params);
    v8 = _V_strlen(str: string);
    CUtlBuffer::CUtlBuffer(this: &sendBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( (sendBuf.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &sendBuf, pFmt: "%u", -1);
    else
      CUtlBuffer::PutTypeBin<int>(this: &sendBuf, src: -1);
    CUtlBuffer::Put(this: &sendBuf, pMem: (unsigned __int8 *)string, size: v8);
    steamID.m_steamid.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)v4.m_unAll64Bits;
    if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      HIDWORD(uSteamID) = -10158081;
      ConColorMsg(a1: (const struct Color *)&uSteamID + 1, a2: "Initiate %llx\n", v4.m_unAll64Bits);
    }
    v9 = CSteamSocketMgr::InitiateConnection(
           this: &g_SteamSocketMgr,
           eSocketTypeFrom: sock,
           &steamID,
           data: sendBuf.m_Memory.m_pMemory,
           len: sendBuf.m_Put);
    if ( v9 != nullptr )
    {
      v10 = result;
      adr = v9->m_addr;
      v11 = *(_DWORD *)v9->m_addr.ip;
      result->type = v9->m_addr.type;
      v12 = *(_DWORD *)&v9->m_addr.port;
      *(_DWORD *)result->ip = v11;
      *(_DWORD *)&result->port = v12;
    }
    else
    {
      _Warning(a1: "NET_InitiateSteamConnection failed to create a socket\n");
      v10 = result;
      *result = adr;
    }
    if ( sendBuf.m_Memory.m_nGrowSize >= 0 && sendBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sendBuf.m_Memory.m_pMemory);
    return v10;
  }
  else
  {
    _Warning(a1: "NET_InitiateSteamConnection called with uSteamID == 0\n");
    v6 = *(_DWORD *)adr.ip;
    result->type = adr.type;
    v7 = *(_DWORD *)&adr.port;
    *(_DWORD *)result->ip = v6;
    *(_DWORD *)&result->port = v7;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3CC0
// Name: __CreateCNetSupportImplINetSupport_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNetSupportImpl *__cdecl _CreateCNetSupportImplINetSupport_interface()
{
  return &g_NetSupport;
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x10090F20
// Name: private: virtual int CCallback<class CSteam3Client,struct SocketStatusCallback_t,0>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CCallback<CSteam3Client,SocketStatusCallback_t,0>::GetCallbackSizeBytes(SVC_Prefetch *this)
{
  return 20;
}

//------------------------------------------------------------------------------
// Address: 0x1012F810
// Name: private: virtual void CCallback<class CSteamSocketMgr,struct P2PSessionRequest_t,0>::Run(void __near *,bool,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSteamSocketMgr,P2PSessionRequest_t,0>::Run(
        CCallback<CSteam3Client,SocketStatusCallback_t,0> *this,
        SocketStatusCallback_t *pvParam,
        bool __formal,
        unsigned __int64 a4)
{
  this->m_Func(this: this->m_pObj, a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x1012F840
// Name: private: virtual void CCallback<class CSteam3Server,struct SteamServerConnectFailure_t,1>::Run(void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCallback<CSteam3Server,SteamServerConnectFailure_t,1>::Run(
        CCallback<CSteam3Client,SocketStatusCallback_t,0> *this,
        SocketStatusCallback_t *pvParam)
{
  this->m_Func(this: this->m_pObj, a2: pvParam);
}

//------------------------------------------------------------------------------
// Address: 0x1012F850
// Name: private: virtual int CCallback<class CSteam3Server,struct GSClientDeny_t,1>::GetCallbackSizeBytes(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CCallback<CSteam3Server,GSClientDeny_t,1>::GetCallbackSizeBytes(
        CCallback<CSteam3Server,GSClientDeny_t,1> *this)
{
  return 140;
}

//------------------------------------------------------------------------------
// Address: 0x101AF340
// Name: public: char const __near * tokenset_t<enum ESocketIndex_t>::GetNameByToken(enum ESocketIndex_t)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall tokenset_t<enum ESocketIndex_t>::GetNameByToken(
        tokenset_t<enum ESocketIndex_t> *this,
        ESocketIndex_t token)
{
  if ( this->name == nullptr )
    return `tokenset_t<enum ESocketIndex_t>::GetNameByToken'::`2'::unknown;
  while ( this->token != token )
  {
    ++this;
    if ( this->name == nullptr )
      return `tokenset_t<enum ESocketIndex_t>::GetNameByToken'::`2'::unknown;
  }
  return this->name;
}

//------------------------------------------------------------------------------
// Address: 0x101AF370
// Name: public: virtual void CSteamSocketMgr::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::Init(CSteamSocketMgr *this)
{
  ISteamNetworking *m_pSteamNetworking; // eax

  this->m_bInitialized = true;
  if ( Steam3Client()->m_pSteamNetworking != nullptr )
  {
    m_pSteamNetworking = Steam3Client()->m_pSteamNetworking;
    if ( net_steamcnx_allowrelay.m_pParent != nullptr )
      m_pSteamNetworking->AllowP2PPacketRelay(
        this: m_pSteamNetworking,
        a2: net_steamcnx_allowrelay.m_pParent->m_Value.m_nValue != 0);
    else
      m_pSteamNetworking->AllowP2PPacketRelay(this: m_pSteamNetworking, a2: false);
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF3C0
// Name: public: virtual enum ISteamSocketMgr::ESteamCnxType CSteamSocketMgr::GetCnxType(void)
// Source: json
//------------------------------------------------------------------------------
ISteamSocketMgr::ESteamCnxType __thiscall CSteamSocketMgr::GetCnxType(CSteamSocketMgr *this)
{
  ISteamSocketMgr::ESteamCnxType result; // eax

  if ( net_steamcnx_enabled.m_pParent == nullptr )
    return ESCT_NEVER;
  result = net_steamcnx_enabled.m_pParent->m_Value.m_nValue;
  if ( result < ESCT_NEVER )
    return ESCT_NEVER;
  if ( result > ESCT_ALWAYS )
    return ESCT_ALWAYS;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF6C0
// Name: private: class CSteamSocket __near * CSteamSocketMgr::FindSocketForUser(enum ESocketIndex_t,class CSteamID const __near &)
// Source: json
//------------------------------------------------------------------------------
CSteamSocket *__thiscall CSteamSocketMgr::FindSocketForUser(
        CSteamSocketMgr *this,
        ESocketIndex_t eSocketType,
        const CSteamID *steamID)
{
  int m_Size; // esi
  int v4; // edx
  CSteamSocket **i; // ecx
  CSteamSocket *result; // eax

  m_Size = this->m_vecRemoteSockets.m_Size;
  v4 = 0;
  if ( m_Size <= 0 )
    return nullptr;
  for ( i = this->m_vecRemoteSockets.m_Memory.m_pMemory; ; ++i )
  {
    result = *i;
    if ( (*i)->m_steamID.m_steamid.m_comp == steamID->m_steamid.m_comp
      && *((_DWORD *)&result->m_steamID.m_steamid.m_comp + 1) == *((_DWORD *)&steamID->m_steamid.m_comp + 1)
      && result->m_eSocketType == eSocketType )
    {
      break;
    }
    if ( ++v4 >= m_Size )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101AF710
// Name: public: void CSteamSocketMgr::OnP2PSessionRequest(struct P2PSessionRequest_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::OnP2PSessionRequest(CSteamSocketMgr *this, int pParam)
{
  IMatchSession *v2; // eax
  P2PSessionRequest_t *v3; // esi
  KeyValues *v4; // eax
  CSteam3Client *v5; // eax
  unsigned __int64 v6; // [esp-10h] [ebp-10h]
  CSteamID::SteamID_t v7; // [esp-Ch] [ebp-Ch]

  if ( g_pMatchFramework != nullptr && g_pMatchFramework->GetMatchSession(this: g_pMatchFramework) != nullptr )
  {
    v2 = g_pMatchFramework->GetMatchSession(this: g_pMatchFramework);
    v3 = (P2PSessionRequest_t *)pParam;
    v6 = *(_QWORD *)pParam;
    v4 = v2->GetSessionSettings(this: v2);
    if ( SessionMembersFindPlayer(pSessionSettings: v4, xuidPlayer: v6, ppMachine: nullptr) != nullptr )
    {
      v5 = Steam3Client();
      ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD))v5->m_pSteamNetworking->AcceptP2PSessionWithUser)(
        a1: v5->m_pSteamNetworking,
        a2: *(_DWORD *)&v3->m_steamIDRemote.m_steamid.m_comp,
        a3: *((_DWORD *)&v3->m_steamIDRemote.m_steamid.m_comp + 1));
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
      {
        v7.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)v3->m_steamIDRemote.m_steamid;
        pParam = -10158081;
        ConColorMsg(a1: (const struct Color *)&pParam, a2: "Accepted P2P connection with %llx\n", v7.m_unAll64Bits);
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF7B0
// Name: public: void CSteamSocketMgr::PrintStatus(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::PrintStatus(CSteamSocketMgr *this)
{
  CSteamSocketMgr *v1; // ebx
  int v2; // edi
  CSteamSocket *v3; // esi
  CSteam3Client *v4; // eax
  const char *v5; // edx
  const tokenset_t<enum EP2PSessionError> *v6; // eax
  char *name; // ecx
  const tokenset_t<enum ESocketIndex_t> *v8; // eax
  const char *v9; // eax
  unsigned int m_unAll64Bits; // edi
  unsigned int m_unAll64Bits_high; // ebx
  const char *v12; // eax
  const char *v13; // [esp-1Ch] [ebp-54h]
  const char *v14; // [esp-18h] [ebp-50h]
  const char *v15; // [esp-14h] [ebp-4Ch]
  int m_nBytesQueuedForSend; // [esp-10h] [ebp-48h]
  CSteamID::SteamID_t v17; // [esp-Ch] [ebp-44h]
  int m_nPacketsQueuedForSend; // [esp-Ch] [ebp-44h]
  int m_Size; // [esp-8h] [ebp-40h]
  const char *v20; // [esp-8h] [ebp-40h]
  P2PSessionState_t p2pSessionState; // [esp+8h] [ebp-30h] BYREF
  CSteamSocketMgr *v22; // [esp+1Ch] [ebp-1Ch]
  const char *v23; // [esp+20h] [ebp-18h]
  const char *v24; // [esp+24h] [ebp-14h]
  const char *v25; // [esp+28h] [ebp-10h]
  int i; // [esp+2Ch] [ebp-Ch]
  int v27; // [esp+30h] [ebp-8h] BYREF
  int v28; // [esp+34h] [ebp-4h] BYREF

  v1 = this;
  v22 = this;
  v28 = -10158081;
  ConColorMsg(a1: (const struct Color *)&v28, a2: "SteamSocketMgr Status\n");
  if ( v1->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    m_Size = v1->m_vecRemoteSockets.m_Size;
    v28 = -10158081;
    ConColorMsg(a1: (const struct Color *)&v28, a2: " %d connections\n", m_Size);
    v2 = 0;
    for ( i = 0; v2 < v1->m_vecRemoteSockets.m_Size; i = v2 )
    {
      v3 = v1->m_vecRemoteSockets.m_Memory.m_pMemory[v2];
      v4 = Steam3Client();
      if ( ((unsigned __int8 (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, P2PSessionState_t *))v4->m_pSteamNetworking->GetP2PSessionState)(
             a1: v4->m_pSteamNetworking,
             a2: *(_DWORD *)&v3->m_steamID.m_steamid.m_comp,
             a3: *((_DWORD *)&v3->m_steamID.m_steamid.m_comp + 1),
             a4: &p2pSessionState) != 0 )
      {
        v25 = "yes";
        if ( p2pSessionState.m_bUsingRelay == 0 )
          v25 = "no";
        v24 = "yes";
        if ( p2pSessionState.m_bConnecting == 0 )
          v24 = "no";
        v5 = "yes";
        if ( p2pSessionState.m_bConnectionActive == 0 )
          v5 = "no";
        v6 = s_EP2PSessionErrorIndexMap;
        if ( "None" != nullptr )
        {
          while ( v6->token != p2pSessionState.m_eP2PSessionError )
          {
            ++v6;
            if ( v6->name == nullptr )
              goto LABEL_16;
          }
          name = (char *)v6->name;
        }
        else
        {
LABEL_16:
          name = `tokenset_t<enum EP2PSessionError>::GetNameByToken'::`2'::unknown[0];
        }
        v8 = s_SocketIndexMap;
        if ( "NS_CLIENT" != nullptr )
        {
          while ( v8->token != v3->m_eSocketType )
          {
            ++v8;
            if ( v8->name == nullptr )
              goto LABEL_20;
          }
          v9 = v8->name;
        }
        else
        {
LABEL_20:
          v9 = `tokenset_t<enum ESocketIndex_t>::GetNameByToken'::`2'::unknown;
        }
        m_unAll64Bits = v3->m_steamID.m_steamid.m_unAll64Bits;
        m_unAll64Bits_high = HIDWORD(v3->m_steamID.m_steamid.m_unAll64Bits);
        v20 = name;
        m_nPacketsQueuedForSend = p2pSessionState.m_nPacketsQueuedForSend;
        v23 = v9;
        m_nBytesQueuedForSend = p2pSessionState.m_nBytesQueuedForSend;
        v15 = v25;
        v14 = v24;
        v13 = v5;
        v27 = -10158081;
        v12 = netadr_s::ToString(this: &v3->m_addr, baseOnly: false);
        ConColorMsg(
          a1: (const struct Color *)&v27,
          a2: " %d %llx, type(%s), psuedoAddr(%s), connected(%s), connecting(%s), relay(%s), bytesQueued(%d), packetsQueued(%"
          "d), lasterror(%s)\n",
          i,
          __PAIR64__(m_unAll64Bits_high, m_unAll64Bits),
          v23,
          v12,
          v13,
          v14,
          v15,
          m_nBytesQueuedForSend,
          m_nPacketsQueuedForSend,
          v20);
        v1 = v22;
        v2 = i;
      }
      else
      {
        v17.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)v3->m_steamID.m_steamid;
        v28 = -10158081;
        ConColorMsg(
          a1: (const struct Color *)&v28,
          a2: " %d %llx, failed to get session state\n",
          v2,
          v17.m_unAll64Bits);
      }
      ++v2;
    }
  }
  else
  {
    v28 = -10158081;
    ConColorMsg(a1: (const struct Color *)&v28, a2: " Invalid (no Steam3Client API?)\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x101AF970
// Name: net_steamcnx_status
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_steamcnx_status()
{
  CSteamSocketMgr::PrintStatus(this: &g_SteamSocketMgr);
}

//------------------------------------------------------------------------------
// Address: 0x101B30E0
// Name: private: class CSteamSocket __near * CSteamSocketMgr::FindSocketForAddress(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
CSteamSocket *__thiscall CSteamSocketMgr::FindSocketForAddress(CSteamSocketMgr *this, const netadr_s *adr)
{
  int v3; // edx
  int v4; // eax
  unsigned __int16 v5; // ax
  CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t v7; // [esp+4h] [ebp-10h] BYREF

  netadr_s::SetIP(this: &v7.key, unIP: 0);
  netadr_s::SetPort(this: &v7.key, newport: 0);
  netadr_s::SetType(this: &v7.key, newtype: NA_IP);
  v3 = *(_DWORD *)adr->ip;
  v4 = *(_DWORD *)&adr->port;
  v7.key.type = adr->type;
  *(_DWORD *)v7.key.ip = v3;
  *(_DWORD *)&v7.key.port = v4;
  v5 = CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapAdrToSteamSocket.m_Tree,
         search: &v7);
  if ( v5 == 0xFFFF )
    return nullptr;
  else
    return this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_pMemory[v5].m_Data.elem;
}

//------------------------------------------------------------------------------
// Address: 0x101B3150
// Name: private: bool CSteamSocketMgr::GetTypeForSocket(int,enum ESocketIndex_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CSteamSocketMgr::GetTypeForSocket(CSteamSocketMgr *this, int s, ESocketIndex_t *peType)
{
  unsigned __int16 v4; // ax
  CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  search.key = s;
  v4 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
         this: &this->m_mapSocketToESocketType.m_Tree,
         &search);
  if ( v4 == 0xFFFF )
    return 0;
  *peType = this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[v4].m_Data.elem;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101B31A0
// Name: public: virtual unsigned __int64 CSteamSocketMgr::GetSteamIDForRemote(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
CSteamID::SteamID_t __thiscall CSteamSocketMgr::GetSteamIDForRemote(CSteamSocketMgr *this, const netadr_s *remote)
{
  CSteamSocket *SocketForAddress; // eax

  SocketForAddress = CSteamSocketMgr::FindSocketForAddress(this, adr: remote);
  if ( SocketForAddress != nullptr )
    return SocketForAddress->m_steamID.m_steamid;
  else
    return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101B3240
// Name: public: virtual int CSteamSocketMgr::sendto(int,char const __near *,int,int,struct sockaddr const __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamSocketMgr::sendto(
        CSteamSocketMgr *this,
        int s,
        const char *buf,
        int len,
        int flags,
        ESocketIndex_t to,
        int tolen)
{
  const sockaddr *v7; // ebx
  CSteamSocket *SocketForAddress; // esi
  CSteam3Client *v10; // eax
  CSteam3Client *v11; // eax
  char v12; // bl
  const char *v13; // edx
  const char *v14; // ecx
  const char *NameByToken; // eax
  int v17; // esi
  const char *v18; // eax
  const char *v19; // [esp-8h] [ebp-34h]
  const char *v20; // [esp-4h] [ebp-30h]
  P2PSessionState_t p2pSessionState; // [esp+Ch] [ebp-20h] BYREF
  netadr_s adr; // [esp+20h] [ebp-Ch] BYREF

  v7 = (const sockaddr *)to;
  if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    netadr_s::SetIP(this: &adr, unIP: 0);
    netadr_s::SetPort(this: &adr, newport: 0);
    netadr_s::SetType(this: &adr, newtype: NA_IP);
    netadr_s::SetFromSockadr(this: &adr, s: v7);
    SocketForAddress = CSteamSocketMgr::FindSocketForAddress(this, &adr);
    if ( SocketForAddress != nullptr )
    {
      v10 = Steam3Client();
      ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, const char *, int, _DWORD, bool))v10->m_pSteamNetworking->SendP2PPacket)(
        a1: v10->m_pSteamNetworking,
        a2: *(_DWORD *)&SocketForAddress->m_steamID.m_steamid.m_comp,
        a3: *((_DWORD *)&SocketForAddress->m_steamID.m_steamid.m_comp + 1),
        a4: buf,
        a5: len,
        a6: 0,
        a7: SocketForAddress->m_eSocketType == NS_CLIENT);
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue >= 3 )
      {
        _V_memset(dest: &p2pSessionState, fill: 0, count: 20);
        v11 = Steam3Client();
        v12 = ((int (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, P2PSessionState_t *))v11->m_pSteamNetworking->GetP2PSessionState)(
                a1: v11->m_pSteamNetworking,
                a2: *(_DWORD *)&SocketForAddress->m_steamID.m_steamid.m_comp,
                a3: *((_DWORD *)&SocketForAddress->m_steamID.m_steamid.m_comp + 1),
                a4: &p2pSessionState);
        to = NS_INVALID;
        CSteamSocketMgr::GetTypeForSocket(this, s, peType: &to);
        v13 = "connected";
        if ( p2pSessionState.m_bConnectionActive == 0 )
          v13 = "not connected";
        v14 = "true";
        if ( v12 == 0 )
          v14 = "false";
        v20 = v13;
        v19 = v14;
        buf = (const char *)-10158081;
        NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                        this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                        token: to);
        ConColorMsg(
          a1: (const struct Color *)&buf,
          a2: "  Send to %llx %u bytes on %s (status %s - %s)\n",
          SocketForAddress->m_steamID.m_steamid.m_unAll64Bits,
          len,
          NameByToken,
          v19,
          v20);
      }
      return len;
    }
    if ( netadr_s::GetPort(this: &adr) == 1 )
    {
      v17 = len;
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue >= 1 )
      {
        len = -10158081;
        v18 = netadr_s::ToString(this: &adr, baseOnly: false);
        ConColorMsg(
          a1: (const struct Color *)&len,
          a2: "  Attempted to send %u bytes on unknown steam socket address %s\n",
          v17,
          v18);
      }
      return v17;
    }
  }
  return sendto(s, buf, len, flags, to: v7, tolen);
}

//------------------------------------------------------------------------------
// Address: 0x101B3580
// Name: public: virtual void CSteamSocketMgr::OpenSocket(int,int,int,int,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::OpenSocket(
        CSteamSocketMgr *this,
        int s,
        unsigned int nModule,
        int nSetPort,
        int nDefaultPort,
        const char *pName,
        int nProtocol,
        bool bTryAny)
{
  __int32 elem; // esi
  bool v9; // zf
  ESocketIndex_t v10; // edi
  int v11; // ebx
  unsigned __int16 v12; // ax
  const tokenset_t<enum ESocketIndex_t> *v13; // eax
  const char *name; // eax
  CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t search; // [esp+4h] [ebp-8h] BYREF

  elem = (__int32)this;
  v9 = !this->m_bInitialized;
  search.elem = (ESocketIndex_t)this;
  if ( !v9 && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    v10 = nModule;
    if ( nModule <= 1 )
    {
      v11 = 0;
      if ( *(_WORD *)(elem + 100) != 0 )
      {
        while ( (unsigned __int16)v11 >= *(int *)(search.elem + 100)
             || (unsigned __int16)v11 > *(_WORD *)(search.elem + 114)
             || CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::LeftChild(
                  this: (CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(search.elem + 92),
                  i: v11) == (_WORD)v11
             || *(_DWORD *)(*(_DWORD *)(search.elem + 96) + 16 * (unsigned __int16)v11 + 12) != nModule )
        {
          if ( ++v11 >= *(unsigned __int16 *)(search.elem + 100) )
          {
            v10 = nModule;
            elem = search.elem;
            goto LABEL_11;
          }
        }
      }
      else
      {
LABEL_11:
        search.key = s;
        v12 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                this: (CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(elem + 92),
                &search);
        if ( v12 == 0xFFFF )
        {
          search.key = s;
          search.elem = v10;
          CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Insert(
            this: (CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short> > *)(elem + 92),
            insert: &search);
        }
        else
        {
          *(_DWORD *)(*(_DWORD *)(elem + 96) + 16 * v12 + 12) = v10;
        }
        if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
        {
          v13 = s_SocketIndexMap;
          if ( "NS_CLIENT" != nullptr )
          {
            while ( v13->token != v10 )
            {
              ++v13;
              if ( v13->name == nullptr )
                goto LABEL_19;
            }
            name = v13->name;
          }
          else
          {
LABEL_19:
            name = `tokenset_t<enum ESocketIndex_t>::GetNameByToken'::`2'::unknown;
          }
          nModule = -10158081;
          ConColorMsg(a1: (const struct Color *)&nModule, a2: "Opened Steam Socket %s ( socket %d )\n", name, s);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3820
// Name: private: void CSteamSocketMgr::DestroyConnection(class CSteamSocket __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::DestroyConnection(CSteamSocketMgr *this, int pSocket)
{
  CSteamSocket *v3; // esi
  CSteam3Client *v4; // eax
  CSteam3Client *v5; // eax
  const char *NameByToken; // eax
  ESocketIndex_t m_eSocketType; // [esp-10h] [ebp-14h]
  CSteamID::SteamID_t v8; // [esp-Ch] [ebp-10h]

  if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    v3 = (CSteamSocket *)pSocket;
    if ( pSocket != 0 )
    {
      CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Remove(
        this: &this->m_mapAdrToSteamSocket,
        key: (const netadr_s *)(pSocket + 12));
      CUtlVector<CSteamSocket *,CUtlMemory<CSteamSocket *,int>>::FindAndFastRemove(
        this: &this->m_vecRemoteSockets,
        src: (CSteamSocket **)&pSocket);
      v4 = Steam3Client();
      ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, bool))v4->m_pSteamNetworking->CloseP2PChannelWithUser)(
        a1: v4->m_pSteamNetworking,
        a2: *(_DWORD *)&v3->m_steamID.m_steamid.m_comp,
        a3: *((_DWORD *)&v3->m_steamID.m_steamid.m_comp + 1),
        a4: v3->m_eSocketType != NS_CLIENT);
      v5 = Steam3Client();
      ((void (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, bool))v5->m_pSteamNetworking->CloseP2PChannelWithUser)(
        a1: v5->m_pSteamNetworking,
        a2: *(_DWORD *)&v3->m_steamID.m_steamid.m_comp,
        a3: *((_DWORD *)&v3->m_steamID.m_steamid.m_comp + 1),
        a4: v3->m_eSocketType == NS_CLIENT);
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
      {
        v8.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)v3->m_steamID.m_steamid;
        m_eSocketType = v3->m_eSocketType;
        pSocket = -10158081;
        NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                        this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                        token: m_eSocketType);
        ConColorMsg(
          a1: (const struct Color *)&pSocket,
          a2: "Destroyed %s connection to %llx\n",
          NameByToken,
          v8.m_unAll64Bits);
      }
      free(pMem: v3);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B38F0
// Name: public: void CSteamSocketMgr::OnP2PSessionConnectFail(struct P2PSessionConnectFail_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::OnP2PSessionConnectFail(CSteamSocketMgr *this, int pParam)
{
  P2PSessionConnectFail_t *v2; // edi
  const tokenset_t<enum EP2PSessionError> *v4; // eax
  const char *name; // eax
  int i; // esi
  CSteamSocket *v7; // eax
  CSteamID::SteamID_t v8; // [esp-Ch] [ebp-18h]

  v2 = (P2PSessionConnectFail_t *)pParam;
  if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
  {
    v4 = s_EP2PSessionErrorIndexMap;
    if ( "None" != nullptr )
    {
      while ( v4->token != *(unsigned __int8 *)(pParam + 8) )
      {
        ++v4;
        if ( v4->name == nullptr )
          goto LABEL_6;
      }
      name = v4->name;
    }
    else
    {
LABEL_6:
      name = `tokenset_t<enum EP2PSessionError>::GetNameByToken'::`2'::unknown[0];
    }
    v8.m_comp = *(CSteamID::SteamID_t::SteamIDComponent_t *)pParam;
    pParam = -10158081;
    ConColorMsg(
      a1: (const struct Color *)&pParam,
      a2: "Received connection fail for user %llx %s\n",
      v8.m_unAll64Bits,
      name);
  }
  for ( i = this->m_vecRemoteSockets.m_Size - 1; i >= 0; --i )
  {
    v7 = this->m_vecRemoteSockets.m_Memory.m_pMemory[i];
    if ( v7->m_steamID.m_steamid.m_comp == v2->m_steamIDRemote.m_steamid.m_comp
      && *((_DWORD *)&v7->m_steamID.m_steamid.m_comp + 1) == *((_DWORD *)&v2->m_steamIDRemote.m_steamid.m_comp + 1) )
    {
      CSteamSocketMgr::DestroyConnection(this, pSocket: (int)this->m_vecRemoteSockets.m_Memory.m_pMemory[i]);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3990
// Name: public: virtual int CSteamSocketMgr::recvfrom(int,char __near *,int,int,struct sockaddr __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CSteamSocketMgr::recvfrom(
        CSteamSocketMgr *this,
        int s,
        char *buf,
        int len,
        unsigned int flags,
        sockaddr *from,
        int *fromlen)
{
  int v7; // ebx
  int result; // eax
  unsigned __int16 v10; // ax
  ESocketIndex_t elem; // edi
  CSteam3Client *v12; // eax
  CSteamSocket *SocketForUser; // eax
  const char *NameByToken; // eax
  sockaddr *v15; // [esp-4h] [ebp-20h]
  CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t search; // [esp+Ch] [ebp-10h] BYREF
  CSteamID steamIDRemote; // [esp+14h] [ebp-8h] BYREF

  v7 = len;
  result = recvfrom(s, buf, len, flags, from, fromlen);
  if ( result <= 0 )
  {
    if ( this->m_bInitialized
      && Steam3Client()->m_pSteamNetworking != nullptr
      && (search.key = s,
          (v10 = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Find(
                   this: &this->m_mapSocketToESocketType.m_Tree,
                   &search)) != 0xFFFF)
      && (elem = this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[v10].m_Data.elem,
          flags = 0,
          steamIDRemote.m_steamid.m_comp = 0,
          v12 = Steam3Client(),
          v12->m_pSteamNetworking->ReadP2PPacket(
            this: v12->m_pSteamNetworking,
            a2: buf,
            a3: v7,
            a4: &flags,
            a5: &steamIDRemote,
            a6: elem != NS_CLIENT))
      && flags != 0 )
    {
      SocketForUser = CSteamSocketMgr::FindSocketForUser(this, eSocketType: elem, steamID: &steamIDRemote);
      if ( SocketForUser == nullptr )
        SocketForUser = CSteamSocketMgr::CreateConnection(this, eSocketType: elem, steamID: &steamIDRemote);
      v15 = from;
      *fromlen = 16;
      netadr_s::ToSockadr(this: &SocketForUser->m_addr, s: v15);
      if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue >= 3 )
      {
        buf = (char *)-10158081;
        NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                        this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                        token: elem);
        ConColorMsg(
          a1: (const struct Color *)&buf,
          a2: "  Received from %llx %u bytes on %s\n",
          steamIDRemote.m_steamid.m_comp,
          flags,
          NameByToken);
      }
      return flags;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101B3AD0
// Name: void NET_TerminateSteamConnection(int,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __cdecl NET_TerminateSteamConnection(ESocketIndex_t sock, unsigned __int64 uSteamID)
{
  unsigned __int64 v2; // kr00_8
  CSteamSocket *SocketForUser; // eax
  unsigned __int64 v4; // [esp-8h] [ebp-10h]

  v2 = uSteamID;
  if ( uSteamID != 0 )
  {
    if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v4 = uSteamID;
      HIDWORD(uSteamID) = -10158081;
      ConColorMsg(a1: (const struct Color *)&uSteamID + 1, a2: "Terminate %llx\n", v4);
    }
    uSteamID = v2;
    if ( g_SteamSocketMgr.m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
    {
      SocketForUser = CSteamSocketMgr::FindSocketForUser(
                        this: &g_SteamSocketMgr,
                        eSocketType: sock,
                        steamID: (const CSteamID *)&uSteamID);
      CSteamSocketMgr::DestroyConnection(this: &g_SteamSocketMgr, pSocket: (int)SocketForUser);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3B50
// Name: public: CSteamSocketMgr::CSteamSocketMgr(void)
// Source: json
//------------------------------------------------------------------------------
CSteamSocketMgr *__thiscall CSteamSocketMgr::CSteamSocketMgr(CSteamSocketMgr *this)
{
  UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short> *m_pMemory; // ecx

  this->__vftable = (CSteamSocketMgr_vtbl *)&CSteamSocketMgr::`vftable';
  this->m_callbackP2PSessionRequest.m_nCallbackFlags = 0;
  this->m_callbackP2PSessionRequest.m_iCallback = 0;
  this->m_callbackP2PSessionRequest.__vftable = (CCallback<CSteamSocketMgr,P2PSessionRequest_t,0>_vtbl *)&CCallback<CSteamSocketMgr,P2PSessionRequest_t,0>::`vftable';
  this->m_callbackP2PSessionRequest.m_pObj = this;
  this->m_callbackP2PSessionRequest.m_Func = (void (__thiscall *)(CSteamSocketMgr *, P2PSessionRequest_t *))CSteamSocketMgr::OnP2PSessionRequest;
  if ( CSteamSocketMgr::OnP2PSessionRequest != nullptr )
  {
    this->m_callbackP2PSessionRequest.m_pObj = this;
    this->m_callbackP2PSessionRequest.m_Func = (void (__thiscall *)(CSteamSocketMgr *, P2PSessionRequest_t *))CSteamSocketMgr::OnP2PSessionRequest;
    _SteamAPI_RegisterCallback(a1: &this->m_callbackP2PSessionRequest, a2: 1202);
  }
  this->m_callbackP2PSessionConnectFail.m_nCallbackFlags = 0;
  this->m_callbackP2PSessionConnectFail.m_iCallback = 0;
  this->m_callbackP2PSessionConnectFail.__vftable = (CCallback<CSteamSocketMgr,P2PSessionConnectFail_t,0>_vtbl *)&CCallback<CSteamSocketMgr,P2PSessionConnectFail_t,0>::`vftable';
  this->m_callbackP2PSessionConnectFail.m_pObj = this;
  this->m_callbackP2PSessionConnectFail.m_Func = (void (__thiscall *)(CSteamSocketMgr *, P2PSessionConnectFail_t *))CSteamSocketMgr::OnP2PSessionConnectFail;
  if ( CSteamSocketMgr::OnP2PSessionConnectFail != nullptr )
  {
    this->m_callbackP2PSessionConnectFail.m_pObj = this;
    this->m_callbackP2PSessionConnectFail.m_Func = (void (__thiscall *)(CSteamSocketMgr *, P2PSessionConnectFail_t *))CSteamSocketMgr::OnP2PSessionConnectFail;
    _SteamAPI_RegisterCallback(a1: &this->m_callbackP2PSessionConnectFail, a2: 1203);
  }
  this->m_vecRemoteSockets.m_Memory.m_pMemory = nullptr;
  this->m_vecRemoteSockets.m_Memory.m_nAllocationCount = 0;
  this->m_vecRemoteSockets.m_Memory.m_nGrowSize = 0;
  this->m_vecRemoteSockets.m_Size = 0;
  this->m_vecRemoteSockets.m_pElements = nullptr;
  this->m_mapAdrToSteamSocket.m_Tree.m_LessFunc.m_LessFunc = CDefOps<netadr_s>::LessFunc;
  this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_nGrowSize = 0;
  m_pMemory = this->m_mapAdrToSteamSocket.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapAdrToSteamSocket.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapAdrToSteamSocket.m_Tree.m_FirstFree = -1;
  this->m_mapAdrToSteamSocket.m_Tree.m_pElements = m_pMemory;
  this->m_mapSocketToESocketType.m_Tree.m_LessFunc.m_LessFunc = (bool (__cdecl *)(const int *, const int *))CIPRateLimit::LessIP;
  this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory = nullptr;
  this->m_mapSocketToESocketType.m_Tree.m_Elements.m_nAllocationCount = 0;
  this->m_mapSocketToESocketType.m_Tree.m_Elements.m_nGrowSize = 0;
  this->m_mapSocketToESocketType.m_Tree.m_pElements = this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory;
  *(_DWORD *)&this->m_mapSocketToESocketType.m_Tree.m_Root = 0xFFFF;
  *(_DWORD *)&this->m_mapSocketToESocketType.m_Tree.m_FirstFree = -1;
  this->m_bInitialized = false;
  this->m_nNextRemoteAddress = 1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101B3C30
// Name: public: virtual void CSteamSocketMgr::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::Shutdown(CSteamSocketMgr *this)
{
  int i; // edi

  if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
  {
    for ( i = this->m_vecRemoteSockets.m_Size - 1; i >= 0; --i )
      CSteamSocketMgr::DestroyConnection(this, pSocket: (int)this->m_vecRemoteSockets.m_Memory.m_pMemory[i]);
    this->m_vecRemoteSockets.m_Size = 0;
    CUtlRBTree<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short,CUtlMap<netadr_s,CSteamSocket *,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<netadr_s,CSteamSocket *,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapAdrToSteamSocket.m_Tree);
    CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_mapSocketToESocketType.m_Tree);
    this->m_bInitialized = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3C80
// Name: public: virtual void CSteamSocketMgr::CloseSocket(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CSteamSocketMgr::CloseSocket(CSteamSocketMgr *this, ESocketIndex_t nModule)
{
  const char *NameByToken; // eax
  int i; // esi
  CSteamSocket **m_pMemory; // ecx
  unsigned __int16 Inorder; // si
  int v7; // eax
  int v8; // [esp+4h] [ebp-4h] BYREF

  if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr && (unsigned int)nModule <= NS_SERVER )
  {
    if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      v8 = -10158081;
      NameByToken = tokenset_t<enum ESocketIndex_t>::GetNameByToken(
                      this: (tokenset_t<enum ESocketIndex_t> *)s_SocketIndexMap,
                      token: nModule);
      ConColorMsg(a1: (const struct Color *)&v8, a2: "Closed Steam Socket %s\n", NameByToken);
    }
    for ( i = this->m_vecRemoteSockets.m_Size - 1; i >= 0; --i )
    {
      m_pMemory = this->m_vecRemoteSockets.m_Memory.m_pMemory;
      if ( m_pMemory[i]->m_eSocketType == nModule )
        CSteamSocketMgr::DestroyConnection(this, pSocket: (int)m_pMemory[i]);
    }
    Inorder = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::FirstInorder(this: &this->m_mapSocketToESocketType.m_Tree);
    if ( Inorder != 0xFFFF )
    {
      while ( this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[Inorder].m_Data.elem != nModule )
      {
        Inorder = CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::NextInorder(
                    this: &this->m_mapSocketToESocketType.m_Tree,
                    i: Inorder);
        if ( Inorder == 0xFFFF )
          return;
      }
      if ( Inorder != 0xFFFF )
      {
        CUtlRBTree<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short,CUtlMap<int,enum ESocketIndex_t,unsigned short>::CKeyLess,CUtlMemory<UtlRBTreeNode_t<CUtlMap<int,enum ESocketIndex_t,unsigned short>::Node_t,unsigned short>,unsigned short>>::Unlink(
          this: &this->m_mapSocketToESocketType.m_Tree,
          elem: Inorder);
        v7 = Inorder;
        this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[v7].m_Left = Inorder;
        this->m_mapSocketToESocketType.m_Tree.m_Elements.m_pMemory[v7].m_Right = this->m_mapSocketToESocketType.m_Tree.m_FirstFree;
        --this->m_mapSocketToESocketType.m_Tree.m_NumElements;
        this->m_mapSocketToESocketType.m_Tree.m_FirstFree = Inorder;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x101B3D90
// Name: public: class CSteamSocket __near * CSteamSocketMgr::InitiateConnection(enum ESocketIndex_t,class CSteamID const __near &,unsigned char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
CSteamSocket *__thiscall CSteamSocketMgr::InitiateConnection(
        CSteamSocketMgr *this,
        ESocketIndex_t eSocketTypeFrom,
        const CSteamID *steamID,
        const unsigned __int8 *data,
        unsigned int len)
{
  CSteamSocket *Connection; // esi
  CSteam3Client *v7; // eax
  CSteamSocket *SocketForUser; // eax

  Connection = CSteamSocketMgr::CreateConnection(this, eSocketType: eSocketTypeFrom, steamID);
  if ( Connection == nullptr )
    return nullptr;
  v7 = Steam3Client();
  if ( ((unsigned int (__thiscall *)(ISteamNetworking *, _DWORD, _DWORD, const unsigned __int8 *, unsigned int, int, bool))v7->m_pSteamNetworking->SendP2PPacket)(
         a1: v7->m_pSteamNetworking,
         a2: *(_DWORD *)&Connection->m_steamID.m_steamid.m_comp,
         a3: *((_DWORD *)&Connection->m_steamID.m_steamid.m_comp + 1),
         a4: data,
         a5: len,
         a6: 2,
         a7: Connection->m_eSocketType == NS_CLIENT) == 0 )
  {
    if ( this->m_bInitialized && Steam3Client()->m_pSteamNetworking != nullptr )
    {
      SocketForUser = CSteamSocketMgr::FindSocketForUser(this, eSocketType: eSocketTypeFrom, steamID);
      CSteamSocketMgr::DestroyConnection(this, pSocket: (int)SocketForUser);
    }
    return nullptr;
  }
  return Connection;
}

//------------------------------------------------------------------------------
// Address: 0x101B3E10
// Name: struct netadr_s NET_InitiateSteamConnection(int,unsigned __int64,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
netadr_s *NET_InitiateSteamConnection(
        netadr_s *result,
        ESocketIndex_t sock,
        unsigned __int64 uSteamID,
        const char *format,
        ...)
{
  CSteamID::SteamID_t v4; // kr00_8
  int v6; // edx
  int v7; // ecx
  int v8; // ebx
  CSteamSocket *v9; // eax
  netadr_s *v10; // esi
  int v11; // ecx
  int v12; // edx
  char string[1200]; // [esp+8h] [ebp-4F4h] BYREF
  CUtlBuffer sendBuf; // [esp+4B8h] [ebp-44h] BYREF
  CSteamID steamID; // [esp+4E8h] [ebp-14h] BYREF
  netadr_s adr; // [esp+4F0h] [ebp-Ch] BYREF
  va_list params; // [esp+518h] [ebp+1Ch] BYREF

  va_start(params, format);
  netadr_s::SetIP(this: &adr, unIP: 0);
  netadr_s::SetPort(this: &adr, newport: 0);
  netadr_s::SetType(this: &adr, newtype: NA_IP);
  v4.m_unAll64Bits = uSteamID;
  if ( uSteamID != 0 )
  {
    V_vsnprintf(pDest: string, maxLen: 1200, pFormat: format, params);
    v8 = _V_strlen(str: string);
    CUtlBuffer::CUtlBuffer(this: &sendBuf, growSize: 0, initSize: 0, nFlags: 0);
    if ( (sendBuf.m_Flags & 1) != 0 )
      CUtlBuffer::Printf(this: &sendBuf, pFmt: "%u", -1);
    else
      CUtlBuffer::PutTypeBin<int>(this: &sendBuf, src: -1);
    CUtlBuffer::Put(this: &sendBuf, pMem: string, size: v8);
    steamID.m_steamid.m_comp = (CSteamID::SteamID_t::SteamIDComponent_t)v4.m_unAll64Bits;
    if ( net_steamcnx_debug.m_pParent != nullptr && net_steamcnx_debug.m_pParent->m_Value.m_nValue != 0 )
    {
      HIDWORD(uSteamID) = -10158081;
      ConColorMsg(a1: (const struct Color *)&uSteamID + 1, a2: "Initiate %llx\n", v4.m_unAll64Bits);
    }
    v9 = CSteamSocketMgr::InitiateConnection(
           this: &g_SteamSocketMgr,
           eSocketTypeFrom: sock,
           &steamID,
           data: sendBuf.m_Memory.m_pMemory,
           len: sendBuf.m_Put);
    if ( v9 != nullptr )
    {
      v10 = result;
      adr = v9->m_addr;
      v11 = *(_DWORD *)v9->m_addr.ip;
      result->type = v9->m_addr.type;
      v12 = *(_DWORD *)&v9->m_addr.port;
      *(_DWORD *)result->ip = v11;
      *(_DWORD *)&result->port = v12;
    }
    else
    {
      _Warning(a1: "NET_InitiateSteamConnection failed to create a socket\n");
      v10 = result;
      *result = adr;
    }
    if ( sendBuf.m_Memory.m_nGrowSize >= 0 && sendBuf.m_Memory.m_pMemory != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: sendBuf.m_Memory.m_pMemory);
    return v10;
  }
  else
  {
    _Warning(a1: "NET_InitiateSteamConnection called with uSteamID == 0\n");
    v6 = *(_DWORD *)adr.ip;
    result->type = adr.type;
    v7 = *(_DWORD *)&adr.port;
    *(_DWORD *)result->ip = v6;
    *(_DWORD *)&result->port = v7;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10212040
// Name: recvfrom(x,x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall recvfrom(SOCKET s, char *buf, int len, int flags, struct sockaddr *from, int *fromlen)
{
  return __imp__recvfrom@24(s, buf, len, flags, from, fromlen);
}

//------------------------------------------------------------------------------
// Address: 0x10212046
// Name: sendto(x,x,x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall sendto(SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen)
{
  return __imp__sendto@24(s, buf, len, flags, to, tolen);
}

//------------------------------------------------------------------------------
// Address: 0x101B3FA0
// Name: __CreateCNetSupportImplINetSupport_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNetSupportImpl *__cdecl _CreateCNetSupportImplINetSupport_interface()
{
  return &g_NetSupport;
}

//------------------------------------------------------------------------------
// Address: 0x1021204C
// Name: ntohs(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
u_short __stdcall ntohs(u_short netshort)
{
  return __imp__ntohs@4(netshort);
}

//------------------------------------------------------------------------------
// Address: 0x10212052
// Name: gethostbyname(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
struct hostent *__stdcall gethostbyname(const char *name)
{
  return __imp__gethostbyname@4(name);
}

//------------------------------------------------------------------------------
// Address: 0x10212058
// Name: setsockopt(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall setsockopt(SOCKET s, int level, int optname, const char *optval, int optlen)
{
  return __imp__setsockopt@20(s, level, optname, optval, optlen);
}

//------------------------------------------------------------------------------
// Address: 0x1021205E
// Name: listen(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall listen(SOCKET s, int backlog)
{
  return __imp__listen@8(s, backlog);
}

//------------------------------------------------------------------------------
// Address: 0x10212064
// Name: WSACleanup()
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall WSACleanup()
{
  return __imp__WSACleanup@0();
}

//------------------------------------------------------------------------------
// Address: 0x1021206A
// Name: accept(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
SOCKET __stdcall accept(SOCKET s, struct sockaddr *addr, int *addrlen)
{
  return __imp__accept@12(s, addr, addrlen);
}

//------------------------------------------------------------------------------
// Address: 0x10212070
// Name: WSAStartup(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall WSAStartup(WORD wVersionRequested, LPWSADATA lpWSAData)
{
  return __imp__WSAStartup@8(wVersionRequested, lpWSAData);
}

//------------------------------------------------------------------------------
// Address: 0x10212076
// Name: GetAdaptersInfo(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
ULONG __stdcall GetAdaptersInfo(PIP_ADAPTER_INFO AdapterInfo, PULONG SizePointer)
{
  return __imp__GetAdaptersInfo@8(AdapterInfo, SizePointer);
}

} // namespace engine_xlsp
