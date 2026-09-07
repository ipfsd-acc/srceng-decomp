// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: networksystem/networksystem.cpp
// Functions: 130
// ============================================================

#include "networksystem\networksystem.h"

//------------------------------------------------------------------------------
// Address: 0x10008AD0
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Push(struct TSLNodeBase_t __near *)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Push(CTSListBase *this, TSLNodeBase_t *pNode)
{
  TSLNodeBase_t *Next; // edi
  TSLNodeBase_t *v5; // [esp-8h] [ebp-18h]
  int value64_high; // [esp-4h] [ebp-14h]
  int v7; // [esp-4h] [ebp-14h]

  Next = this->m_Head.value.Next;
  value64_high = HIDWORD(this->m_Head.value64);
  pNode->Next = this->m_Head.value.Next;
  if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                          a1: this,
                          a2: pNode,
                          a3: value64_high + 65537,
                          a4: Next,
                          a5: value64_high) == 0 )
  {
    do
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      v7 = HIDWORD(this->m_Head.value64);
      v5 = this->m_Head.value.Next;
      pNode->Next = this->m_Head.value.Next;
    }
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(a1: this, a2: pNode, a3: v7 + 65537, a4: v5, a5: v7) == 0 );
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10008B30
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Pop(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Pop(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax

  Next = this->m_Head.value.Next;
  value64_high = HIDWORD(this->m_Head.value64);
  if ( this->m_Head.value.Next == nullptr )
    return nullptr;
  while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                             a1: this,
                             a2: Next->Next,
                             a3: value64_high - 1,
                             a4: Next,
                             a5: value64_high) == 0 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    value64_high = HIDWORD(this->m_Head.value64);
    if ( this->m_Head.value.Next == nullptr )
      return nullptr;
  }
  return Next;
}

//------------------------------------------------------------------------------
// Address: 0x10008B70
// Name: public: struct TSLNodeBase_t __near * CTSListBase::Detach(void)
// Source: json
//------------------------------------------------------------------------------
TSLNodeBase_t *__thiscall CTSListBase::Detach(CTSListBase *this)
{
  TSLNodeBase_t *Next; // esi

  while ( 1 )
  {
    _mm_pause();
    Next = this->m_Head.value.Next;
    if ( this->m_Head.value.Next == nullptr )
      break;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: 0,
                            a3: HIDWORD(this->m_Head.value64) & 0xFFFF0000,
                            a4: Next,
                            a5: HIDWORD(this->m_Head.value64)) != 0 )
      return Next;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10008BB0
// Name: public: netpacket_t::netpacket_t(void)
// Source: json
//------------------------------------------------------------------------------
netpacket_t *__thiscall netpacket_t::netpacket_t(netpacket_t *this)
{
  netadr_s::SetIP(this: &this->from, unIP: 0);
  netadr_s::SetPort(this: &this->from, newport: 0);
  netadr_s::SetType(this: &this->from, newtype: NA_IP);
  this->message.m_bOverflow = false;
  this->message.m_pDebugName = nullptr;
  this->message.m_nDataBytes = 0;
  this->message.m_nDataBits = -1;
  this->source = 0;
  this->data = nullptr;
  this->size = 0;
  this->wiresize = 0;
  this->stream = false;
  this->received = 0.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10008C10
// Name: public: virtual bool CNetworkSystem::Connect(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::Connect(CNetworkSystem *this, void *(__cdecl *factory)(const char *, int *))
{
  g_pFileSystem = (IFileSystem *)factory(a1: "VFileSystem017", a2: nullptr);
  if ( g_pFileSystem == nullptr )
    return 0;
  ConnectTier1Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConnectTier2Libraries(pFactoryList: &factory, nFactoryCount: 1);
  ConVar_Register(nCVarFlag: 0, pAccessor: nullptr);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10008C60
// Name: public: virtual void CNetworkSystem::Disconnect(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::Disconnect(CNetworkSystem *this)
{
  DisconnectTier2Libraries();
  ConVar_Unregister();
  DisconnectTier1Libraries();
}

//------------------------------------------------------------------------------
// Address: 0x10008C70
// Name: public: virtual struct netadr_s const __near & CNetworkSystem::GetLocalAdr(void)const
// Source: json
//------------------------------------------------------------------------------
const netadr_s *__thiscall CNetworkSystem::GetLocalAdr(CNetworkSystem *this)
{
  return &this->m_adrLocal;
}

//------------------------------------------------------------------------------
// Address: 0x10008C80
// Name: public: virtual double CNetworkSystem::GetNetTime(void)const
// Source: json
//------------------------------------------------------------------------------
long double __thiscall CNetworkSystem::GetNetTime(CNetworkSystem *this)
{
  return this->m_flNetworkTime;
}

//------------------------------------------------------------------------------
// Address: 0x10008C90
// Name: private: bool CNetworkSystem::StringToSockaddr(char const __near *,struct sockaddr __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::StringToSockaddr(CNetworkSystem *this, const char *s, sockaddr *sadr)
{
  char v4; // al
  char *v5; // esi
  u_short v6; // ax
  struct hostent *v8; // eax
  char copy[132]; // [esp+8h] [ebp-84h] BYREF

  _V_memset(dest: (void *)sadr, fill: 0, count: 16);
  sadr->sa_family = 2;
  *(_WORD *)sadr->sa_data = 0;
  V_strncpy(pDest: &copy[4], pSrc: s, maxLen: 128);
  v4 = copy[4];
  v5 = &copy[4];
  if ( copy[4] != 0 )
  {
    do
    {
      if ( *v5 == 58 )
      {
        *v5 = 0;
        v6 = atoi(nptr: v5 + 1);
        *(_WORD *)sadr->sa_data = htons(hostshort: v6);
      }
      ++v5;
    }
    while ( *v5 != 0 );
    v4 = copy[4];
  }
  if ( (unsigned __int8)(v4 - 48) <= 9u && _V_strstr(s1: &copy[4], search: ".") != nullptr )
  {
    *(_DWORD *)&sadr->sa_data[2] = inet_addr(cp: &copy[4]);
    return 1;
  }
  else
  {
    if ( (*((_BYTE *)this + 304) & 4) != 0 )
      return 0;
    v8 = gethostbyname(name: &copy[4]);
    if ( v8 == nullptr )
    {
      return 0;
    }
    else
    {
      *(_DWORD *)&sadr->sa_data[2] = **(_DWORD **)v8->h_addr_list;
      return 1;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008D90
// Name: private: int CNetworkSystem::GetLastError(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkSystem::GetLastError(CNetworkSystem *this)
{
  int result; // eax

  result = WSAGetLastError();
  this->m_nLastNetworkErrorCode = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10008DB0
// Name: private: int CNetworkSystem::OpenSocket(char const __near *,int __near &,int)
// Source: json
//------------------------------------------------------------------------------
SOCKET __thiscall CNetworkSystem::OpenSocket(
        CNetworkSystem *this,
        const char *net_interface,
        int *port,
        unsigned int protocol)
{
  unsigned int v4; // edi
  SOCKET v6; // eax
  SOCKET v7; // esi
  int Error; // eax
  const char *v9; // eax
  int v11; // eax
  const char *v12; // eax
  int v13; // eax
  const char *v14; // eax
  int v15; // eax
  const char *v16; // eax
  int v17; // eax
  const char *v18; // eax
  const char *v19; // eax
  const char *v20; // eax
  int v21; // eax
  const char *v22; // eax
  int v23; // eax
  int v24; // eax
  const char *v25; // eax
  const char *v26; // edi
  const char *v27; // ebx
  bool v28; // cf
  int *v29; // edi
  int v30; // eax
  int v31; // eax
  const char *v32; // eax
  sockaddr_in address; // [esp+8h] [ebp-14h] BYREF

  v4 = protocol;
  if ( protocol == 6 )
    v6 = socket(af: 2, type: 1, protocol: 6);
  else
    v6 = socket(af: 2, type: 2, protocol);
  v7 = v6;
  if ( v6 == -1 )
  {
    Error = WSAGetLastError();
    this->m_nLastNetworkErrorCode = Error;
    if ( Error != 10047 )
    {
      v9 = SocketErrorString(code: Error);
      _Msg(a1: "WARNING: NET_OpenSockett: socket failed: %s", v9);
    }
    return 0;
  }
  else
  {
    protocol = 1;
    if ( ioctlsocket(s: v6, cmd: -2147195266, argp: &protocol) == -1 )
    {
      v11 = WSAGetLastError();
      this->m_nLastNetworkErrorCode = v11;
      v12 = SocketErrorString(code: v11);
      _Msg(a1: "WARNING: NET_OpenSocket: ioctl FIONBIO: %s\n", v12);
    }
    protocol = 1;
    if ( v4 == 6 )
    {
      if ( setsockopt(s: v7, level: 0xFFFF, optname: 8, optval: (const char *)&protocol, optlen: 4) == -1 )
      {
        v13 = WSAGetLastError();
        this->m_nLastNetworkErrorCode = v13;
        v14 = SocketErrorString(code: v13);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_KEEPALIVE: %s\n", v14);
        return 0;
      }
      net_interface = nullptr;
      if ( setsockopt(s: v7, level: 0xFFFF, optname: 128, optval: (const char *)&net_interface, optlen: 4) == -1 )
      {
        v15 = WSAGetLastError();
        this->m_nLastNetworkErrorCode = v15;
        v16 = SocketErrorString(code: v15);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_LINGER: %s\n", v16);
        return 0;
      }
      protocol = 1;
      if ( setsockopt(s: v7, level: 6, optname: 1, optval: (const char *)&protocol, optlen: 4) == -1 )
      {
        v17 = WSAGetLastError();
        this->m_nLastNetworkErrorCode = v17;
        v18 = SocketErrorString(code: v17);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt TCP_NODELAY: %s\n", v18);
        return 0;
      }
      protocol = 96016;
      if ( setsockopt(s: v7, level: 0xFFFF, optname: 4097, optval: (const char *)&protocol, optlen: 4) == -1 )
      {
        CNetworkSystem::GetLastError(this);
        v19 = SocketErrorString(code: this->m_nLastNetworkErrorCode);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_SNDBUF: %s\n", v19);
        return 0;
      }
      protocol = 96016;
      if ( setsockopt(s: v7, level: 0xFFFF, optname: 4098, optval: (const char *)&protocol, optlen: 4) == -1 )
      {
        CNetworkSystem::GetLastError(this);
        v20 = SocketErrorString(code: this->m_nLastNetworkErrorCode);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_RCVBUF: %s\n", v20);
        return 0;
      }
    }
    else
    {
      if ( setsockopt(s: v7, level: 0xFFFF, optname: 32, optval: (const char *)&protocol, optlen: 4) == -1 )
      {
        v21 = WSAGetLastError();
        this->m_nLastNetworkErrorCode = v21;
        v22 = SocketErrorString(code: v21);
        _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_BROADCAST: %s\n", v22);
        return 0;
      }
      v23 = _CommandLine();
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v23 + 40))(a1: v23, a2: "-reuse") != 0 )
      {
        protocol = 1;
        if ( setsockopt(s: v7, level: 0xFFFF, optname: 4, optval: (const char *)&protocol, optlen: 4) == -1 )
        {
          v24 = WSAGetLastError();
          this->m_nLastNetworkErrorCode = v24;
          v25 = SocketErrorString(code: v24);
          _Msg(a1: "WARNING: NET_OpenSocket: setsockopt SO_REUSEADDR: %s\n", v25);
          return 0;
        }
      }
      v26 = net_interface;
      v27 = nullptr;
      if ( net_interface != nullptr && *net_interface != 0 && _V_strcmp(s1: net_interface, s2: "localhost") != 0 )
        CNetworkSystem::StringToSockaddr(this, s: v26, sadr: (sockaddr *)&address.sin_addr);
      else
        *(_DWORD *)address.sin_zero = 0;
      v28 = *((char *)this + 304) < 0;
      *(_WORD *)&address.sin_addr.S_un.S_un_b.s_b1 = 2;
      net_interface = (const char *)(v28 ? 150 : 10);
      if ( (v28 ? 0x8C : 0) != 0xFFFFFFF6 )
      {
        v29 = port;
        while ( 1 )
        {
          *(_WORD *)&address.sin_addr.S_un.S_un_w.s_b3 = *v29 == -1 ? 0 : htons(hostshort: (_WORD)v27 + *(_WORD *)v29);
          if ( bind(s: v7, name: (const struct sockaddr *)&address.sin_addr, namelen: 16) != -1 )
            break;
          v30 = WSAGetLastError();
          this->m_nLastNetworkErrorCode = v30;
          if ( *v29 == -1 || v30 != 10048 )
          {
            v32 = SocketErrorString(code: v30);
            _Msg(a1: "WARNING: NET_OpenSocket: bind: %s\n", v32);
            this->CloseSocket(this, a2: v7, a3: -1);
            return 0;
          }
          if ( (int)++v27 >= (int)net_interface )
            goto LABEL_40;
        }
        v31 = *v29;
        if ( *v29 != -1 && v27 != nullptr )
        {
          *v29 = (int)&v27[v31];
          _ConDMsg(a1: "Socket bound to non-default port %i because original port was already in use.\n", &v27[v31]);
        }
      }
LABEL_40:
      if ( v27 == net_interface )
      {
        _Msg(a1: "WARNING: UDP_OpenSocket: unable to bind socket\n");
        this->CloseSocket(this, a2: v7, a3: -1);
        return 0;
      }
    }
    return v7;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100091B0
// Name: public: virtual float CNetworkSystem::GetFakeLag(void)const
// Source: json
//------------------------------------------------------------------------------
double __thiscall CNetworkSystem::GetFakeLag(CNetworkSystem *this)
{
  return this->m_flFakeLagMilliseconds;
}

//------------------------------------------------------------------------------
// Address: 0x100091C0
// Name: public: virtual void CNetworkSystem::SetMessageTypeBits(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SetMessageTypeBits(CNetworkSystem *this, int msgTypeEncodeBits)
{
  this->m_nMsgTypeBits = msgTypeEncodeBits;
}

//------------------------------------------------------------------------------
// Address: 0x100091D0
// Name: public: virtual int CNetworkSystem::GetMsgTypeBits(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkSystem::GetMsgTypeBits(CNetworkSystem *this)
{
  return this->m_nMsgTypeBits;
}

//------------------------------------------------------------------------------
// Address: 0x100091E0
// Name: public: virtual void CNetworkSystem::LogBadPacket(struct netpacket_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::LogBadPacket(CNetworkSystem *this, netpacket_t *packet)
{
  int v2; // ebp
  char v3; // bl
  void *v4; // esi
  const char *v5; // eax
  char filename[264]; // [esp+Ch] [ebp-108h] BYREF

  v2 = 0;
  v3 = 0;
  while ( v3 == 0 )
  {
    V_snprintf(pDest: &filename[4], maxLen: 260, pFormat: "badpacket%03i.dat", v2);
    v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: &filename[4], a3: "rb", a4: 0);
    if ( v4 != nullptr
      || (v4 = g_pFileSystem->Open(this: &g_pFileSystem->IBaseFileSystem, a2: &filename[4], a3: "wb", a4: 0),
          g_pFileSystem->Write(this: &g_pFileSystem->IBaseFileSystem, a2: packet->data, a3: packet->size, a4: v4),
          v3 = 1,
          v4 != nullptr) )
    {
      g_pFileSystem->Close(this: &g_pFileSystem->IBaseFileSystem, a2: v4);
    }
    if ( ++v2 >= 1000 )
    {
      _Msg(a1: "Couldn't write error buffer, delete error###.dat files to make space\n");
      return;
    }
  }
  v5 = netadr_s::ToString(this: &packet->from, baseOnly: false);
  _Msg(a1: "Error buffer for %s written to %s\n", v5, &filename[4]);
}

//------------------------------------------------------------------------------
// Address: 0x100092F0
// Name: public: virtual void CNetworkSystem::SetDefaultBroadcastPort(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SetDefaultBroadcastPort(CNetworkSystem *this, int nPort)
{
  this->m_nDefaultBroadcastPort = nPort;
}

//------------------------------------------------------------------------------
// Address: 0x10009300
// Name: private: void CNetworkSystem::GetLocalAddress(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::GetLocalAddress(CNetworkSystem *this)
{
  netadr_s *p_m_adrLocal; // ebx
  char *m_pszString; // eax
  char *v4; // eax
  char buff[515]; // [esp+4h] [ebp-204h] BYREF
  char v6; // [esp+207h] [ebp-1h]

  p_m_adrLocal = &this->m_adrLocal;
  netadr_s::Clear(this: &this->m_adrLocal);
  if ( (*((_BYTE *)this + 304) & 2) != 0 )
  {
    _Msg(a1: "TCP/UDP Disabled.\n");
  }
  else
  {
    if ( (ipname.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = ipname.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)str;
    }
    if ( _V_strcmp(s1: m_pszString, s2: "localhost") != 0 )
    {
      if ( (ipname.m_nFlags & 0x1000) != 0 )
      {
        v4 = "FCVAR_NEVER_AS_STRING";
      }
      else
      {
        v4 = ipname.m_pParent->m_Value.m_pszString;
        if ( v4 == nullptr )
          v4 = (char *)str;
      }
      V_strncpy(pDest: &buff[4], pSrc: v4, maxLen: 512);
    }
    else
    {
      gethostname(name: &buff[4], namelen: 512);
      v6 = 0;
    }
    netadr_s::SetFromString(this: p_m_adrLocal, pch: &buff[4], bUseDNS: true);
    ConVar::SetValue(
      this: (ConVar *)&hostip.IConVar,
      value: this->m_adrLocal.ip[3]
    + ((this->m_adrLocal.ip[2] + ((this->m_adrLocal.ip[1] + (this->m_adrLocal.ip[0] << 8)) << 8)) << 8));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009400
// Name: public: virtual bool CNetworkSystem::IsMultiplayer(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkSystem::IsMultiplayer(CNetworkSystem *this)
{
  return *((_BYTE *)this + 304) & 1;
}

//------------------------------------------------------------------------------
// Address: 0x10009410
// Name: public: virtual bool CNetworkSystem::IsDedicated(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkSystem::IsDedicated(CNetworkSystem *this)
{
  return (*((_BYTE *)this + 304) & 0x10) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009420
// Name: public: virtual bool CNetworkSystem::IsDedicatedForXbox(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CNetworkSystem::IsDedicatedForXbox(CNetworkSystem *this)
{
  char v1; // al

  v1 = *((_BYTE *)this + 304);
  return (v1 & 0x10) != 0 && (v1 & 0x20) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009440
// Name: public: virtual void CNetworkSystem::SetTime(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SetTime(CNetworkSystem *this, long double realtime)
{
  double v2; // xmm0_8
  __int64 v3; // xmm1_8

  v2 = realtime - s_last_realtime;
  s_last_realtime = realtime;
  v3 = 0x3FF0000000000000LL;
  if ( v2 > 1.0 || (v3 = 0, v2 < 0.0) )
    v2 = *(double *)&v3;
  this->m_flNetworkTime = this->m_flTimeScale * v2 + this->m_flNetworkTime;
}

//------------------------------------------------------------------------------
// Address: 0x10009490
// Name: public: virtual void CNetworkSystem::SetTimeScale(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SetTimeScale(CNetworkSystem *this, float timescale)
{
  this->m_flTimeScale = timescale;
}

//------------------------------------------------------------------------------
// Address: 0x100094A0
// Name: public: virtual void CNetworkSystem::RunFrame(double)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::RunFrame(CNetworkSystem *this, long double realtime)
{
  ((void (__thiscall *)(CNetworkSystem *, _DWORD, _DWORD))this->SetTime)(
    a1: this,
    a2: LODWORD(realtime),
    a3: HIDWORD(realtime));
}

//------------------------------------------------------------------------------
// Address: 0x100094C0
// Name: public: virtual void CNetworkSystem::InitPostFork(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::InitPostFork(CNetworkSystem *this)
{
  int v1; // eax

  v1 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v1 + 40))(a1: v1, a2: "-NoQueuedPacketThread") != 0 )
    _Warning(a1: "Found -NoQueuedPacketThread, so no queued packet thread will be created.\n");
  else
    g_pQueuedPackedSender->Setup(this: g_pQueuedPackedSender);
}

//------------------------------------------------------------------------------
// Address: 0x10009500
// Name: public: virtual void CNetworkSystem::SetSubProcess(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SetSubProcess(CNetworkSystem *this, bool bChildProcess)
{
  *((_BYTE *)this + 304) = (bChildProcess << 7) | *((_BYTE *)this + 304) & 0x7F;
}

//------------------------------------------------------------------------------
// Address: 0x10009520
// Name: public: virtual void CNetworkSystem::SetDedicated(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SetDedicated(CNetworkSystem *this, bool bDedicated)
{
  CNetworkSystem *v2; // esi
  int v3; // eax
  int v4; // ecx
  int v5; // eax

  v2 = this;
  *((_BYTE *)this + 304) ^= (*((_BYTE *)this + 304) ^ (16 * bDedicated)) & 0x10;
  LOBYTE(this) = *((_BYTE *)this + 304);
  if ( bDedicated )
  {
    if ( ((unsigned __int8)this & 2) != 0 )
    {
      _Msg(a1: "Warning! Dedicated not possible with -noip parameter.\n");
    }
    else
    {
      v3 = _CommandLine(a1: this);
      LOBYTE(v4) = (*((_BYTE *)v2 + 304)
                  ^ (32 * ((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v3 + 40))(a1: v3, a2: "-xlsp") != 0)))
                 & 0x20;
      *((_BYTE *)v2 + 304) ^= v4;
      v5 = _CommandLine(a1: v4);
      *((_BYTE *)v2 + 304) ^= (*((_BYTE *)v2 + 304)
                             ^ (((*(int (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 40))(
                                   a1: v5,
                                   a2: "-xlsp_insecure") != 0) << 6))
                            & 0x40;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100095C0
// Name: public: void CNetworkSystem::PrintChannelStatus(class INetChannel __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::PrintChannelStatus(CNetworkSystem *this, INetChannel *chan)
{
  const char *v3; // eax
  const char *v4; // eax
  double v5; // st7
  bool v6; // zf
  const char *v7; // eax
  unsigned __int64 v8; // st7
  double v9; // st7
  unsigned __int64 v10; // st7
  double v11; // st7
  unsigned __int64 v12; // st7
  double v13; // st7
  double v14; // st7
  double v15; // st7
  int v16; // eax
  double v17; // xmm0_8
  double v18; // [esp+30h] [ebp-10h]
  double v19; // [esp+30h] [ebp-10h]
  double v20; // [esp+30h] [ebp-10h]
  double v21; // [esp+30h] [ebp-10h]
  double v22; // [esp+30h] [ebp-10h]
  int v23; // [esp+38h] [ebp-8h]
  int v24; // [esp+38h] [ebp-8h]
  int v25; // [esp+38h] [ebp-8h]
  int v26; // [esp+38h] [ebp-8h]

  v3 = (const char *)chan->GetName(this: chan);
  _Msg(a1: "NetChannel '%s':\n", v3);
  v4 = chan->GetAddress(this: chan);
  _Msg(a1: "- remote IP: %s\n", v4);
  v5 = ((double (__thiscall *)(INetChannel *))chan->GetTimeConnected)(a1: chan);
  _Msg(a1: "- online: %.3f seconds\n", v5);
  v6 = !chan->HasPendingReliableData(this: chan);
  v7 = "pending data";
  if ( v6 )
    v7 = "available";
  _Msg(a1: "- reliable: %s\n", v7);
  *(double *)&v8 = ((double (__thiscall *)(INetChannel *, int))chan->GetAvgLoss)(a1: chan, a2: 1);
  v9 = ((double (__thiscall *)(INetChannel *, _DWORD, _DWORD, _DWORD))chan->GetAvgLatency)(
         a1: chan,
         a2: 0,
         a3: v8,
         a4: HIDWORD(v8));
  _Msg(a1: "- latency: %.1f, loss %.2f\n", v9, v18);
  *(double *)&v10 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgPackets)(a1: chan, a2: 0, a3: v23);
  v11 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgPackets)(
          a1: chan,
          a2: 1,
          a3: v10,
          a4: HIDWORD(v10));
  _Msg(a1: "- packets: in %.1f/s, out %.1f/s\n", v11, v19);
  *(double *)&v12 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgChoke)(a1: chan, a2: 0, a3: v24);
  v13 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgChoke)(
          a1: chan,
          a2: 1,
          a3: v12,
          a4: HIDWORD(v12));
  _Msg(a1: "- choke: in %.2f, out %.2f\n", v13, v20);
  v14 = ((double (__thiscall *)(INetChannel *, _DWORD, int))chan->GetAvgData)(a1: chan, a2: 0, a3: v25);
  v15 = ((double (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetAvgData)(
          a1: chan,
          a2: 1,
          a3: COERCE_UNSIGNED_INT64(v14 * 0.0009765625),
          a4: HIDWORD(COERCE_UNSIGNED_INT64(v14 * 0.0009765625)));
  _Msg(a1: "- flow: in %.1f, out %.1f kB/s\n", v15 * 0.0009765625, v21);
  v16 = ((int (__thiscall *)(INetChannel *, _DWORD, int))chan->GetTotalData)(a1: chan, a2: 0, a3: v26);
  v17 = (float)((float)((int (__thiscall *)(INetChannel *, int, _DWORD, _DWORD))chan->GetTotalData)(
                         a1: chan,
                         a2: 1,
                         a3: COERCE_UNSIGNED_INT64((float)((float)v16 * 0.00000095367432)),
                         a4: HIDWORD(COERCE_UNSIGNED_INT64((float)((float)v16 * 0.00000095367432))))
              * 0.00000095367432);
  _Msg(a1: "- total: in %.1f, out %.1f MB\n\n", v17, v22);
}

//------------------------------------------------------------------------------
// Address: 0x10009750
// Name: public: virtual bool CNetworkSystem::BufferToBufferCompress(char __near *,unsigned int __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::BufferToBufferCompress(
        CNetworkSystem *this,
        char *dest,
        unsigned int *destLen,
        char *source,
        unsigned int sourceLen)
{
  int v5; // edi
  unsigned __int8 *v6; // esi
  CLZSS s; // [esp+Ch] [ebp-10h] BYREF
  int v9; // [esp+18h] [ebp-4h]

  v5 = sourceLen;
  _V_memcpy(dest, src: source, count: sourceLen);
  v9 = 4096;
  sourceLen = 0;
  v6 = CLZSS::Compress(
         this: (CLZSS *)&s.m_pHashTarget,
         pInput: (unsigned __int8 *)source,
         inputLength: v5,
         pOutputSize: &sourceLen);
  if ( v6 != nullptr )
  {
    if ( sourceLen != 0 && sourceLen <= *destLen )
    {
      _V_memcpy(dest, src: v6, count: sourceLen);
      *destLen = sourceLen;
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
      return 1;
    }
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6);
  }
  _V_memcpy(dest, src: source, count: v5);
  *destLen = v5;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10009810
// Name: public: virtual bool CNetworkSystem::BufferToBufferDecompress(char __near *,unsigned int __near *,char __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::BufferToBufferDecompress(
        CNetworkSystem *this,
        char *dest,
        unsigned int *destLen,
        char *source,
        unsigned int sourceLen)
{
  unsigned int ActualSize; // eax
  CLZSS s; // [esp+8h] [ebp-10h] BYREF
  int v8; // [esp+14h] [ebp-4h]

  v8 = 4096;
  if ( CLZSS::IsCompressed(this: (CLZSS *)&s.m_pHashTarget, pInput: (unsigned __int8 *)source) )
  {
    ActualSize = CLZSS::GetActualSize(this: (CLZSS *)&s.m_pHashTarget, pInput: (unsigned __int8 *)source);
    if ( ActualSize > *destLen )
    {
      _Warning(
        a1: "CNetworkSystem::BufferToBufferDecompress with improperly sized dest buffer (%u in, %u needed)\n",
        *destLen,
        ActualSize);
      return 0;
    }
    *destLen = CLZSS::SafeUncompress(
                 this: (CLZSS *)&s.m_pHashTarget,
                 pInput: (unsigned __int8 *)source,
                 pOutput: (unsigned __int8 *)dest,
                 unBufSize: *destLen);
    return 1;
  }
  else
  {
    if ( sourceLen > *destLen )
    {
      _Warning(
        a1: "CNetworkSystem::BufferToBufferDecompress with improperly sized dest buffer (%u in, %u needed)\n",
        *destLen,
        sourceLen);
      return 0;
    }
    _V_memcpy(dest, src: source, count: sourceLen);
    *destLen = sourceLen;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100098B0
// Name: public: virtual struct netadr_s const __near & CNetworkSystem::GetPublicAdr(void)const
// Source: json
//------------------------------------------------------------------------------
const netadr_s *__thiscall CNetworkSystem::GetPublicAdr(CNetworkSystem *this)
{
  return &this->m_adrPublic;
}

//------------------------------------------------------------------------------
// Address: 0x100098C0
// Name: public: bool CNetworkSystem::ShouldChecksumPackets(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkSystem::ShouldChecksumPackets(CNetworkSystem *this)
{
  return this->IsMultiplayer(this);
}

//------------------------------------------------------------------------------
// Address: 0x100098D0
// Name: public: unsigned short CNetworkSystem::BufferToShortChecksum(void const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __thiscall CNetworkSystem::BufferToShortChecksum(
        CNetworkSystem *this,
        const void *pvData,
        unsigned int nLength)
{
  unsigned int pulCRC; // [esp+0h] [ebp-4h] BYREF

  pulCRC = (unsigned int)this;
  CRC32_Init(&pulCRC);
  CRC32_ProcessBuffer(&pulCRC, pBuffer: pvData, nBuffer: nLength);
  CRC32_Final(&pulCRC);
  return pulCRC ^ HIWORD(pulCRC);
}

//------------------------------------------------------------------------------
// Address: 0x10009910
// Name: public: virtual struct netadr_s CNetworkSystem::InitiateSteamConnection(int,unsigned __int64,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
netadr_s *CNetworkSystem::InitiateSteamConnection(
        CNetworkSystem *this,
        netadr_s *result,
        int sock,
        unsigned __int64 uSteamID,
        const char *format,
        ...)
{
  va_list va; // [esp+20h] [ebp+1Ch] BYREF

  va_start(va, format);
  g_pSteamSocketMgrInternal->InitiateSteamConnection(
    this: g_pSteamSocketMgrInternal,
    result,
    a3: sock,
    a4: uSteamID,
    a5: (const char *)HIDWORD(uSteamID),
    format,
    va);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10009950
// Name: public: virtual void CNetworkSystem::TerminateSteamConnection(int,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::TerminateSteamConnection(CNetworkSystem *this, int sock, unsigned __int64 uSteamID)
{
  ((void (__thiscall *)(ISteamSocketMgrInternal *, int, _DWORD, _DWORD))g_pSteamSocketMgrInternal->TerminateSteamConnection)(
    a1: g_pSteamSocketMgrInternal,
    a2: sock,
    a3: uSteamID,
    a4: HIDWORD(uSteamID));
}

//------------------------------------------------------------------------------
// Address: 0x10009970
// Name: public: virtual unsigned __int64 CNetworkSystem::GetSteamIDForRemote(struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall CNetworkSystem::GetSteamIDForRemote(CNetworkSystem *this, const netadr_s *remote)
{
  return g_pSteamSocketMgrInternal->GetSteamIDForRemote(this: g_pSteamSocketMgrInternal, a2: remote);
}

//------------------------------------------------------------------------------
// Address: 0x10009980
// Name: public: virtual enum ESteamCnxType CNetworkSystem::GetCnxType(void)
// Source: json
//------------------------------------------------------------------------------
ESteamCnxType __thiscall CNetworkSystem::GetCnxType(CNetworkSystem *this)
{
  return g_pSteamSocketMgrInternal->GetCnxType(this: g_pSteamSocketMgrInternal);
}

//------------------------------------------------------------------------------
// Address: 0x10009990
// Name: public: virtual void CNetworkSystem::SetTimeout(float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SetTimeout(CNetworkSystem *this, float flSeconds)
{
  ((void (__stdcall *)(_DWORD))g_pSteamSocketMgrInternal->SetTimeout)(a1: LODWORD(flSeconds));
}

//------------------------------------------------------------------------------
// Address: 0x100099B0
// Name: net_start
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_start()
{
  g_pNetworkSystem->SetMultiplayer(this: g_pNetworkSystem, a2: true);
}

//------------------------------------------------------------------------------
// Address: 0x100099C0
// Name: int NET_SendToImpl(unsigned int,char const __near *,int,struct sockaddr const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
unsigned int __cdecl NET_SendToImpl(
        unsigned int s,
        const char *buf,
        char *len,
        const sockaddr *to,
        int tolen,
        int iGameDataLength)
{
  char v6; // al
  int nSend; // [esp+4h] [ebp-18h] BYREF
  _WSABUF buffers[2]; // [esp+8h] [ebp-14h] BYREF
  const char *v10; // [esp+18h] [ebp-4h]

  buffers[0].len = 0;
  v6 = *((_BYTE *)g_pNetworkSystemInternal + 304);
  if ( (v6 & 0x20) == 0 || (v6 & 0x40) != 0 )
    return g_pSteamSocketMgrInternal->sendto(
             this: g_pSteamSocketMgrInternal,
             a2: s,
             a3: buf,
             a4: (int)len,
             a5: 0,
             a6: to,
             a7: tolen);
  if ( iGameDataLength == -1 )
    nSend = (unsigned __int16)len;
  else
    nSend = (unsigned __int16)iGameDataLength;
  if ( voice_xsend_debug.m_pParent->m_Value.m_nValue != 0 && iGameDataLength >= 0 && (char *)iGameDataLength != len )
    DevMsg(a1: "XVoice: VDP packet to %d with unencrypted %d bytes out of %d bytes\n", s, &len[-iGameDataLength], len);
  buffers[1].len = (unsigned int)&nSend;
  v10 = buf;
  buffers[0].buf = (char *)2;
  buffers[1].buf = len;
  WSASendTo(
    s,
    lpBuffers: (LPWSABUF)&buffers[0].buf,
    dwBufferCount: 2u,
    lpNumberOfBytesSent: &buffers[0].len,
    dwFlags: 0,
    lpTo: to,
    iTolen: tolen,
    lpOverlapped: nullptr,
    lpCompletionRoutine: nullptr);
  return buffers[0].len;
}

//------------------------------------------------------------------------------
// Address: 0x10009AB0
// Name: NET_SendTo
// Source: json
//------------------------------------------------------------------------------
char *__usercall NET_SendTo@<eax>(
        char *len@<eax>,
        const sockaddr *to@<ecx>,
        unsigned int verbose,
        const char *s,
        const char *buf,
        int tolen)
{
  if ( *(_DWORD *)&to->sa_data[2] != 0 || *(_WORD *)to->sa_data != 0 )
    return (char *)NET_SendToImpl(s: verbose, buf: s, len, to, tolen: (int)buf, iGameDataLength: tolen);
  return len;
}

//------------------------------------------------------------------------------
// Address: 0x10009AE0
// Name: public: void CNetworkSystem::OnNetPublicAdrChanged(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::OnNetPublicAdrChanged(CNetworkSystem *this)
{
  char *v2; // eax
  char *m_pszString; // eax
  int m_nDefaultServerPortSocket; // eax
  unsigned __int16 v5; // ax

  if ( (net_public_adr.m_nFlags & 0x1000) != 0
    || (v2 = net_public_adr.m_pParent->m_Value.m_pszString) != nullptr && *v2 != 0 )
  {
    if ( (net_public_adr.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = net_public_adr.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)str;
    }
    netadr_s::SetFromString(this: &this->m_adrPublic, pch: m_pszString, bUseDNS: false);
    if ( netadr_s::GetPort(this: &this->m_adrPublic) == 0 )
    {
      m_nDefaultServerPortSocket = this->m_nDefaultServerPortSocket;
      if ( m_nDefaultServerPortSocket >= 0 && m_nDefaultServerPortSocket < this->m_NetSockets.m_Size )
      {
        v5 = this->GetUDPPort(this, a2: this->m_nDefaultServerPortSocket);
        netadr_s::SetPort(this: &this->m_adrPublic, newport: v5);
      }
    }
  }
  else
  {
    netadr_s::Clear(this: &this->m_adrPublic);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009B70
// Name: public: CTSQueue<struct loopback_t __near *,0>::CTSQueue<struct loopback_t __near *,0>(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<loopback_t *,0> *__thiscall CTSQueue<loopback_t *,0>::CTSQueue<loopback_t *,0>(CTSQueue<loopback_t *,0> *this)
{
  CTSListBase *p_m_FreeNodes; // ebx
  CInterlockedIntT<int> *p_m_Count; // edi
  CTSQueue<loopback_t *,0>::Node_t *v4; // eax

  p_m_FreeNodes = &this->m_FreeNodes;
  p_m_Count = &this->m_Count;
  this->m_Count.m_value = 0;
  if ( (((_BYTE)this + 24) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  p_m_FreeNodes->m_Head.value.Next = nullptr;
  HIDWORD(p_m_FreeNodes->m_Head.value64) = 0;
  if ( ((unsigned __int8)this & 7) != 0 )
  {
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
    _Error(a1: "CTSQueue: Misaligned queue\n");
    __debugbreak();
  }
  _InterlockedExchange(&p_m_Count->m_value, 0);
  this->m_Tail.value.sequence = 0;
  this->m_Head.value.sequence = 0;
  v4 = (CTSQueue<loopback_t *,0>::Node_t *)operator new(nSize: 8u);
  this->m_Tail.value.pNode = v4;
  this->m_Head.value.pNode = v4;
  v4->pNext = (CTSQueue<loopback_t *,0>::Node_t *)this;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10009C00
// Name: public: CTSPool<struct net_scratchbuffer_t>::~CTSPool<struct net_scratchbuffer_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSPool<net_scratchbuffer_t>::~CTSPool<net_scratchbuffer_t>(CTSPool<net_scratchbuffer_t> *this)
{
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax

  while ( 1 )
  {
    Next = this->m_Head.value.Next;
    value64_high = HIDWORD(this->m_Head.value64);
    if ( this->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: this,
                               a2: Next->Next,
                               a3: value64_high - 1,
                               a4: Next,
                               a5: value64_high) == 0 )
    {
      _mm_pause();
      Next = this->m_Head.value.Next;
      value64_high = HIDWORD(this->m_Head.value64);
      if ( this->m_Head.value.Next == nullptr )
        goto LABEL_4;
    }
    free(pMem: Next);
  }
LABEL_4:
  CTSListBase::Detach(this);
}

//------------------------------------------------------------------------------
// Address: 0x10009C60
// Name: public: void CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(
        CUtlMemory<unsigned char,int> *this,
        int nGrowSize)
{
  unsigned int m_nAllocationCount; // edi
  unsigned __int8 *v4; // ebx

  if ( this->m_nGrowSize < 0 )
  {
    m_nAllocationCount = this->m_nAllocationCount;
    this->m_nGrowSize = nGrowSize;
    if ( m_nAllocationCount != 0 )
    {
      v4 = (unsigned __int8 *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
      memcpy(dst: v4, src: this->m_pMemory, count: m_nAllocationCount);
      this->m_pMemory = v4;
    }
    else
    {
      this->m_pMemory = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10009FB0
// Name: public: void netsocket_t::ConnectLoopback(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netsocket_t::ConnectLoopback(netsocket_t *this, int nOther)
{
  CTSQueue<loopback_t *,0> *v3; // eax

  v3 = (CTSQueue<loopback_t *,0> *)operator new(nSize: 0x20u);
  if ( v3 != nullptr )
    this->m_pLoopBack = CTSQueue<loopback_t *,0>::CTSQueue<loopback_t *,0>(this: v3);
  else
    this->m_pLoopBack = nullptr;
  this->m_hLoopBackPairSocketIndex = nOther;
}

//------------------------------------------------------------------------------
// Address: 0x1000A000
// Name: OnNetPublicAdrChanged
// Source: json
//------------------------------------------------------------------------------
void __cdecl OnNetPublicAdrChanged()
{
  CNetworkSystem::OnNetPublicAdrChanged(this: g_pNetworkSystemInternal);
}

//------------------------------------------------------------------------------
// Address: 0x1000A010
// Name: public: virtual void __near * CBaseAppSystem<class INetworkSystem>::QueryInterface(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void *__thiscall CBaseAppSystem<INetworkSystem>::QueryInterface(
        CBaseAppSystem<INetworkSystem> *this,
        const char *pInterfaceName)
{
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000A030
// Name: public: virtual void CBaseAppSystem<class INetworkSystem>::Reconnect(void __near * (*)(char const __near *,int __near *),char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBaseAppSystem<INetworkSystem>::Reconnect(
        CBaseAppSystem<INetworkSystem> *this,
        void *(__cdecl *factory)(const char *, int *),
        const char *pInterfaceName)
{
  ReconnectInterface(factory, pInterfaceName);
}

//------------------------------------------------------------------------------
// Address: 0x1000A050
// Name: private: void CNetworkSystem::PlatformSpecificNetworkStartup(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::PlatformSpecificNetworkStartup(CNetworkSystem *this)
{
  int v1; // esi
  bool v3; // cc
  INetworkPrepareStartupParams *v4; // ecx
  int v5; // [esp+8h] [ebp-4h] BYREF

  v1 = 0;
  v3 = this->m_NetworkPrepareStartupParamsCallbacks.m_Size <= 0;
  v5 = 0;
  if ( !v3 )
  {
    do
    {
      v4 = this->m_NetworkPrepareStartupParamsCallbacks.m_Memory.m_pMemory[v1];
      v4->PrepareNetStartupParams(this: v4, a2: &v5);
      ++v1;
    }
    while ( v1 < this->m_NetworkPrepareStartupParamsCallbacks.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A090
// Name: private: class CNetChan __near * CNetworkSystem::FindNetChannel(int,struct netadr_s __near &)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__thiscall CNetworkSystem::FindNetChannel(CNetworkSystem *this, int socket, netadr_s *adr)
{
  CUtlVectorMT<CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int> >,CThreadFastMutex> *p_m_NetChannels; // esi
  CThreadFastMutex *v5; // ebx
  DWORD CurrentThreadId; // ecx
  int m_Size; // ebp
  int v8; // edi
  bool v9; // zf
  CNetChan *v11; // esi
  const netadr_s *v12; // eax
  CUtlVectorMT<CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int> >,CThreadFastMutex> *v13; // [esp+10h] [ebp-4h]

  p_m_NetChannels = &this->m_NetChannels;
  v13 = &this->m_NetChannels;
  if ( this == (CNetworkSystem *)-84 )
    v5 = nullptr;
  else
    v5 = &this->m_NetChannels.CThreadFastMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != v5->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)v5, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: v5, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++v5->m_depth;
  }
  m_Size = this->m_NetChannels.m_Size;
  v8 = 0;
  if ( m_Size > 0 )
  {
    while ( 1 )
    {
      v11 = p_m_NetChannels->m_Memory.m_pMemory[v8];
      if ( socket == v11->GetSocket(this: v11) )
      {
        v12 = v11->GetRemoteAddress(this: v11);
        if ( netadr_s::CompareAdr(this: adr, a: v12, onlyBase: false) )
          break;
      }
      if ( ++v8 >= m_Size )
        goto LABEL_9;
      p_m_NetChannels = v13;
    }
    v9 = v5->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)v5, 0);
    return v11;
  }
  else
  {
LABEL_9:
    v9 = v5->m_depth-- == 1;
    if ( v9 )
      _InterlockedExchange((volatile __int32 *)v5, 0);
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A160
// Name: public: virtual void CNetworkSystem::CloseSocket(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::CloseSocket(CNetworkSystem *this, SOCKET hSocket, int sock)
{
  int Error; // eax
  const char *v5; // eax
  netsocket_t *m_pMemory; // ecx
  bool v7; // zf
  int *p_hTCP; // ecx

  if ( hSocket != 0 )
  {
    if ( closesocket(s: hSocket) == -1 )
    {
      Error = WSAGetLastError();
      this->m_nLastNetworkErrorCode = Error;
      v5 = SocketErrorString(code: Error);
      _Msg(a1: "WARNING! NET_CloseSocket: %s\n", v5);
    }
    if ( sock >= 0 )
    {
      m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
      v7 = m_pMemory[sock].hTCP == hSocket;
      p_hTCP = &m_pMemory[sock].hTCP;
      if ( v7 )
      {
        *p_hTCP = 0;
        this->m_NetSockets.m_Memory.m_pMemory[sock].bListening = false;
      }
    }
    g_pSteamSocketMgrInternal->CloseSocket(this: g_pSteamSocketMgrInternal, a2: sock);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A1E0
// Name: public: virtual int CNetworkSystem::ConnectSocket(int,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkSystem::ConnectSocket(CNetworkSystem *this, int sock, netadr_s *addr)
{
  int v3; // ebp
  int v4; // ebx
  netsocket_t *m_pMemory; // edi
  int hTCP; // eax
  netsocket_t *v8; // edi
  char *m_pszString; // eax
  SOCKET v10; // eax
  int Error; // eax
  const char *v13; // eax
  sockaddr saddr; // [esp+Ch] [ebp-14h] BYREF

  v3 = sock;
  v4 = sock;
  m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
  hTCP = m_pMemory[sock].hTCP;
  v8 = &m_pMemory[sock];
  if ( hTCP != 0 )
    this->CloseSocket(this, a2: hTCP, a3: sock);
  if ( (*((_BYTE *)this + 304) & 8) != 0 )
    return 0;
  netadr_s::ToSockadr(this: addr, s: (sockaddr *)&saddr.sa_data[2]);
  sock = -1;
  if ( (ipname.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = ipname.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)str;
  }
  v10 = CNetworkSystem::OpenSocket(this, net_interface: m_pszString, port: &sock, protocol: 1u);
  v8->hTCP = v10;
  if ( v10 == 0 )
  {
    _Msg(
      a1: "Warning! NET_ConnectSocket failed opening socket %i, port %i.\n",
      v3,
      this->m_NetSockets.m_Memory.m_pMemory[v4].nPort);
    return 0;
  }
  if ( connect(s: v10, name: (const struct sockaddr *)&saddr.sa_data[2], namelen: 16) != -1 )
    return this->m_NetSockets.m_Memory.m_pMemory[v4].hTCP;
  Error = WSAGetLastError();
  this->m_nLastNetworkErrorCode = Error;
  if ( Error == 10035 )
    return this->m_NetSockets.m_Memory.m_pMemory[v4].hTCP;
  v13 = SocketErrorString(code: Error);
  _Msg(a1: "NET_ConnectSocket: %s\n", v13);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000A2F0
// Name: public: virtual char const __near * CNetworkSystem::DescribeSocket(int)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CNetworkSystem::DescribeSocket(CNetworkSystem *this, int sock)
{
  if ( sock < this->m_NetSockets.m_Size )
    return CUtlString::operator char const *(this: &this->m_NetSockets.m_Memory.m_pMemory[sock].m_sSocketName);
  else
    return "???";
}

//------------------------------------------------------------------------------
// Address: 0x1000A320
// Name: public: virtual unsigned short CNetworkSystem::GetUDPPort(int)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CNetworkSystem::GetUDPPort(CNetworkSystem *this, int socket)
{
  if ( socket < 0 || socket >= this->m_NetSockets.m_Size )
    return 0;
  else
    return this->m_NetSockets.m_Memory.m_pMemory[socket].nPort;
}

//------------------------------------------------------------------------------
// Address: 0x1000A350
// Name: public: virtual void CNetworkSystem::EnableLoopbackBetweenSockets(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::EnableLoopbackBetweenSockets(CNetworkSystem *this, int nSocket1, int nSocket2)
{
  int m_Size; // eax
  int v5; // [esp+0h] [ebp-Ch]
  int v6; // [esp+4h] [ebp-8h]

  m_Size = this->m_NetSockets.m_Size;
  if ( nSocket1 >= m_Size || nSocket2 >= m_Size )
  {
    _Warning(a1: "Can't EnableLoopbackBetweenSockets between socket %d and %d, not enough slots\n", v5, v6);
  }
  else
  {
    netsocket_t::ConnectLoopback(this: &this->m_NetSockets.m_Memory.m_pMemory[nSocket1], nOther: nSocket2);
    netsocket_t::ConnectLoopback(this: &this->m_NetSockets.m_Memory.m_pMemory[nSocket2], nOther: nSocket1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A3B0
// Name: public: virtual void CNetworkSystem::ListenSocket(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::ListenSocket(CNetworkSystem *this, int sock, bool bListen)
{
  netsocket_t *v4; // esi
  int hTCP; // eax
  char *m_pszString; // ebp
  int *p_nPort; // ebx
  SOCKET v8; // eax
  u_short v9; // [esp-Ch] [ebp-28h]
  sockaddr_in address; // [esp+8h] [ebp-14h] BYREF

  v4 = &this->m_NetSockets.m_Memory.m_pMemory[sock];
  hTCP = v4->hTCP;
  if ( hTCP != 0 )
    this->CloseSocket(this, a2: hTCP, a3: sock);
  if ( this->IsMultiplayer(this) && (*((_BYTE *)this + 304) & 8) == 0 && bListen )
  {
    if ( (ipname.m_nFlags & 0x1000) != 0 )
    {
      m_pszString = "FCVAR_NEVER_AS_STRING";
    }
    else
    {
      m_pszString = ipname.m_pParent->m_Value.m_pszString;
      if ( m_pszString == nullptr )
        m_pszString = (char *)str;
    }
    p_nPort = &v4->nPort;
    v8 = CNetworkSystem::OpenSocket(this, net_interface: m_pszString, port: &v4->nPort, protocol: 1u);
    v4->hTCP = v8;
    if ( v8 != 0 )
    {
      if ( m_pszString != nullptr && *m_pszString != 0 && _V_strcmp(s1: m_pszString, s2: "localhost") != 0 )
        CNetworkSystem::StringToSockaddr(this, s: m_pszString, sadr: (sockaddr *)&address.sin_addr);
      else
        *(_DWORD *)address.sin_zero = 0;
      v9 = *(_WORD *)p_nPort;
      *(_WORD *)&address.sin_addr.S_un.S_un_b.s_b1 = 2;
      *(_WORD *)&address.sin_addr.S_un.S_un_w.s_b3 = htons(hostshort: v9);
      if ( bind(s: v4->hTCP, name: (const struct sockaddr *)&address.sin_addr, namelen: 16) == -1 )
      {
        CNetworkSystem::GetLastError(this);
        _Msg(a1: "WARNING: CNetworkSystem::ListenSocket bind failed on socket %i, port %i.\n", v4->hTCP, *p_nPort);
      }
      else if ( listen(s: v4->hTCP, backlog: 4) == -1 )
      {
        CNetworkSystem::GetLastError(this);
        _Msg(a1: "WARNING: CNetworkSystem::ListenSocket listen failed on socket %i, port %i.\n", v4->hTCP, *p_nPort);
      }
      else
      {
        v4->bListening = true;
      }
    }
    else
    {
      _Msg(
        a1: "Warning! CNetworkSystem::ListenSocket failed opening socket %i, port %i.\n",
        sock,
        this->m_NetSockets.m_Memory.m_pMemory[sock].nPort);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A540
// Name: public: virtual void CNetworkSystem::SleepUntilMessages(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SleepUntilMessages(CNetworkSystem *this, int sock, int nMilliseconds)
{
  int hUDP; // eax
  timeval tv; // [esp+0h] [ebp-110h] BYREF
  fd_set fdset; // [esp+8h] [ebp-108h] BYREF

  if ( sock < this->m_NetSockets.m_Size && (hUDP = this->m_NetSockets.m_Memory.m_pMemory[sock].hUDP) != 0 )
  {
    fdset.fd_count = 1000 * nMilliseconds;
    tv.tv_usec = 0;
    fdset.fd_array[1] = hUDP;
    fdset.fd_array[0] = 1;
    select(
      nfds: hUDP + 1,
      readfds: (fd_set *)fdset.fd_array,
      writefds: nullptr,
      exceptfds: nullptr,
      timeout: (const struct timeval *)&tv.tv_usec);
  }
  else
  {
    _ThreadSleep(a1: nMilliseconds);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A5D0
// Name: public: void CNetworkSystem::ShowNetChannelInfo(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::ShowNetChannelInfo(CNetworkSystem *this)
{
  int m_Size; // ebp
  CThreadFastMutex *v3; // edi
  DWORD CurrentThreadId; // ecx
  int i; // esi

  m_Size = this->m_NetChannels.m_Size;
  if ( m_Size != 0 )
  {
    if ( this == (CNetworkSystem *)-84 )
      v3 = nullptr;
    else
      v3 = &this->m_NetChannels.CThreadFastMutex;
    CurrentThreadId = GetCurrentThreadId();
    if ( CurrentThreadId != v3->m_ownerID
      && _InterlockedCompareExchange((volatile signed __int32 *)v3, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: v3, a2: CurrentThreadId, a3: 0);
    }
    else
    {
      ++v3->m_depth;
    }
    for ( i = 0; i < m_Size; ++i )
      CNetworkSystem::PrintChannelStatus(this, chan: this->m_NetChannels.m_Memory.m_pMemory[i]);
    if ( v3->m_depth-- == 1 )
      _InterlockedExchange((volatile __int32 *)v3, 0);
  }
  else
  {
    _Msg(a1: "No active net channels.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000A660
// Name: public: void CNetworkSystem::ShowNetStatus(void)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::ShowNetStatus(CNetworkSystem *this)
{
  CThreadFastMutex *v2; // esi
  DWORD CurrentThreadId; // ecx
  int m_Size; // ebp
  netadr_s *v5; // eax
  const char *v6; // eax
  char v7; // al
  const char *v8; // ecx
  bool v9; // zf
  const char *v10; // eax
  int i; // esi
  const char *v12; // eax
  int v13; // ebx
  CNetChan *v14; // esi
  int v15; // [esp+3Ch] [ebp-44h]
  int v16; // [esp+40h] [ebp-40h]
  float avgPacketsIn; // [esp+58h] [ebp-28h]
  float avgPacketsOut; // [esp+5Ch] [ebp-24h]
  float avgDataIn; // [esp+60h] [ebp-20h]
  float avgDataOut; // [esp+64h] [ebp-1Ch]
  CThreadFastMutex *v21; // [esp+68h] [ebp-18h]
  float avgLatencyIn; // [esp+6Ch] [ebp-14h]
  float avgLatencyOut; // [esp+70h] [ebp-10h]
  float avgLossIn; // [esp+74h] [ebp-Ch]
  float avgLossOut; // [esp+78h] [ebp-8h]
  CUtlVectorMT<CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int> >,CThreadFastMutex> *p_m_NetChannels; // [esp+7Ch] [ebp-4h]
  float v27; // [esp+7Ch] [ebp-4h]

  p_m_NetChannels = &this->m_NetChannels;
  if ( this == (CNetworkSystem *)-84 )
  {
    v21 = nullptr;
    v2 = nullptr;
  }
  else
  {
    v2 = &this->m_NetChannels.CThreadFastMutex;
    v21 = &this->m_NetChannels.CThreadFastMutex;
  }
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != v2->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)v2, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: v2, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++v2->m_depth;
  }
  m_Size = this->m_NetChannels.m_Size;
  v5 = (netadr_s *)this->GetLocalAdr(this);
  v6 = netadr_s::ToString(this: v5, baseOnly: true);
  _Msg(a1: "Net status for host %s:\n", v6);
  v7 = *((_BYTE *)this + 304);
  v8 = "dedicated";
  if ( (v7 & 0x10) == 0 )
    v8 = "listen";
  v9 = (v7 & 1) == 0;
  v10 = "Multiplayer";
  if ( v9 )
    v10 = "Singleplayer";
  _Msg(a1: "- Config: %s, %s, %i connections\n", v10, v8, m_Size);
  _Msg(a1: "- Ports: ");
  for ( i = 0; i < this->m_NetSockets.m_Size; ++i )
  {
    ((void (__thiscall *)(INetworkSystem *, int, int))g_pNetworkSystem->GetUDPPort)(
      a1: g_pNetworkSystem,
      a2: i,
      a3: v16);
    v12 = g_pNetworkSystem->DescribeSocket(this: g_pNetworkSystem, a2: i);
    _Msg(a1: "%d %s %u, ", i, v12, v15);
  }
  _Msg(a1: "%d total.\n", this->m_NetSockets.m_Size);
  if ( m_Size <= 0 )
  {
    v9 = v21->m_depth-- == 1;
    if ( !v9 )
      return;
    goto LABEL_20;
  }
  v13 = 0;
  avgLatencyOut = 0.0;
  avgLatencyIn = 0.0;
  avgPacketsOut = 0.0;
  avgPacketsIn = 0.0;
  avgLossOut = 0.0;
  avgLossIn = 0.0;
  avgDataOut = 0.0;
  avgDataIn = 0.0;
  do
  {
    v14 = p_m_NetChannels->m_Memory.m_pMemory[v13];
    avgLatencyOut = ((double (__thiscall *)(CNetChan *, _DWORD))v14->GetAvgLatency)(a1: v14, a2: 0) + avgLatencyOut;
    avgLatencyIn = ((double (__thiscall *)(CNetChan *, int))v14->GetAvgLatency)(a1: v14, a2: 1) + avgLatencyIn;
    avgLossIn = ((double (__thiscall *)(CNetChan *, int))v14->GetAvgLoss)(a1: v14, a2: 1) + avgLossIn;
    avgLossOut = ((double (__thiscall *)(CNetChan *, _DWORD))v14->GetAvgLoss)(a1: v14, a2: 0) + avgLossOut;
    avgPacketsIn = ((double (__thiscall *)(CNetChan *, int))v14->GetAvgPackets)(a1: v14, a2: 1) + avgPacketsIn;
    avgPacketsOut = ((double (__thiscall *)(CNetChan *, _DWORD))v14->GetAvgPackets)(a1: v14, a2: 0) + avgPacketsOut;
    avgDataIn = ((double (__thiscall *)(CNetChan *, int))v14->GetAvgData)(a1: v14, a2: 1) + avgDataIn;
    ++v13;
    avgDataOut = ((double (__thiscall *)(CNetChan *, _DWORD))v14->GetAvgData)(a1: v14, a2: 0) + avgDataOut;
  }
  while ( v13 < m_Size );
  v27 = 1.0 / (float)m_Size;
  _Msg(a1: "- Latency: avg out %.2fs, in %.2fs\n", (float)(v27 * avgLatencyOut), (float)(v27 * avgLatencyIn));
  _Msg(a1: "- Loss:    avg out %.1f, in %.1f\n", (float)(v27 * avgLossOut), (float)(v27 * avgLossIn));
  _Msg(a1: "- Packets: net total out  %.1f/s, in %.1f/s\n", avgPacketsOut, avgPacketsIn);
  _Msg(a1: "           per client out %.1f/s, in %.1f/s\n", (float)(v27 * avgPacketsOut), (float)(v27 * avgPacketsIn));
  _Msg(
    a1: "- Data:    net total out  %.1f, in %.1f kB/s\n",
    (float)(avgDataOut * 0.0009765625),
    (float)(avgDataIn * 0.0009765625));
  _Msg(
    a1: "           per client out %.1f, in %.1f kB/s\n",
    (float)((float)(v27 * avgDataOut) * 0.0009765625),
    (float)((float)(v27 * avgDataIn) * 0.0009765625));
  v9 = v21->m_depth-- == 1;
  if ( v9 )
LABEL_20:
    _InterlockedExchange((volatile __int32 *)v21, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000A9E0
// Name: public: virtual bool CNetworkSystem::IsSafeFileToDownload(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::IsSafeFileToDownload(CNetworkSystem *this, const char *pFilename)
{
  int v3; // esi
  INetworkFileDownloadFilter *v4; // ecx

  v3 = 0;
  if ( this->m_NetworkFileDownloadFilterCallbacks.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = this->m_NetworkFileDownloadFilterCallbacks.m_Memory.m_pMemory[v3];
    if ( v4->IsSafeFileToDownload(this: v4, a2: pFilename) == 0 )
      break;
    if ( ++v3 >= this->m_NetworkFileDownloadFilterCallbacks.m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA30
// Name: public: virtual bool CNetworkSystem::IsValidFileTransferExtension(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::IsValidFileTransferExtension(CNetworkSystem *this, const char *pFilename)
{
  int v3; // esi
  INetworkFileDownloadFilter *v4; // ecx

  v3 = 0;
  if ( this->m_NetworkFileDownloadFilterCallbacks.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = this->m_NetworkFileDownloadFilterCallbacks.m_Memory.m_pMemory[v3];
    if ( !v4->IsValidFileTransferExtension(this: v4, a2: pFilename) )
      break;
    if ( ++v3 >= this->m_NetworkFileDownloadFilterCallbacks.m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000AA80
// Name: public: virtual bool CNetworkSystem::CanRedownloadFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::CanRedownloadFile(CNetworkSystem *this, const char *pFilename)
{
  int v3; // esi
  INetworkFileDownloadFilter *v4; // ecx

  v3 = 0;
  if ( this->m_NetworkFileDownloadFilterCallbacks.m_Size <= 0 )
    return 1;
  while ( 1 )
  {
    v4 = this->m_NetworkFileDownloadFilterCallbacks.m_Memory.m_pMemory[v3];
    if ( !v4->CanRedownloadFile(this: v4, a2: pFilename) )
      break;
    if ( ++v3 >= this->m_NetworkFileDownloadFilterCallbacks.m_Size )
      return 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000AAD0
// Name: public: bool CNetworkSystem::IsSteamCnxEnabledForSocket(int)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CNetworkSystem::IsSteamCnxEnabledForSocket(CNetworkSystem *this, int nSocket)
{
  return nSocket >= 0
      && nSocket < this->m_NetSockets.m_Size
      && this->m_NetSockets.m_Memory.m_pMemory[nSocket].m_bCanUseSteamCnxMgr;
}

//------------------------------------------------------------------------------
// Address: 0x1000AB00
// Name: net_channels
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_channels()
{
  CNetworkSystem::ShowNetChannelInfo(this: g_pNetworkSystemInternal);
}

//------------------------------------------------------------------------------
// Address: 0x1000AB10
// Name: net_status
// Source: json
//------------------------------------------------------------------------------
void __cdecl net_status()
{
  CNetworkSystem::ShowNetStatus(this: g_pNetworkSystemInternal);
}

//------------------------------------------------------------------------------
// Address: 0x1000AB20
// Name: public: void CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(
        CUtlMemoryFixedGrowable<unsigned char,4096,int> *this,
        int num)
{
  if ( this->m_nAllocationCount < num )
  {
    if ( this->m_nGrowSize < 0 )
      CUtlMemory<unsigned char,int>::ConvertToGrowableMemory(this, nGrowSize: this->m_nMallocGrowSize);
    CUtlMemory<unsigned char,int>::EnsureCapacity(this, num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000AB50
// Name: public: struct CTSQueue<struct loopback_t __near *,0>::Node_t __near * CTSQueue<struct loopback_t __near *,0>::Push(struct CTSQueue<struct loopback_t __near *,0>::Node_t __near *)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<loopback_t *,0>::Node_t *__thiscall CTSQueue<loopback_t *,0>::Push(
        CTSQueue<loopback_t *,0> *this,
        CTSQueue<loopback_t *,0>::Node_t *pNode)
{
  int sequence; // ecx
  CTSQueue<loopback_t *,0>::Node_t *i; // edi

  pNode->pNext = (CTSQueue<loopback_t *,0>::Node_t *)this;
  sequence = this->m_Tail.value.sequence;
  for ( i = this->m_Tail.value.pNode;
        (CTSQueue<loopback_t *,0> *)_InterlockedCompareExchange(
                                      (volatile signed __int32 *)i,
                                      (signed __int32)pNode,
                                      (signed __int32)this) != this;
        sequence = this->m_Tail.value.sequence )
  {
    _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: i->pNext, a3: sequence + 1, a4: i, a5: sequence);
    i = this->m_Tail.value.pNode;
  }
  _ThreadInterlockedAssignIf64(a1: &this->m_Tail, a2: pNode, a3: sequence + 1, a4: i, a5: sequence);
  _InterlockedExchangeAdd(&this->m_Count.m_value, 1u);
  return i;
}

//------------------------------------------------------------------------------
// Address: 0x1000ABD0
// Name: public: struct CTSQueue<struct loopback_t __near *,0>::Node_t __near * CTSQueue<struct loopback_t __near *,0>::Pop(void)
// Source: json
//------------------------------------------------------------------------------
CTSQueue<loopback_t *,0>::Node_t *__thiscall CTSQueue<loopback_t *,0>::Pop(CTSQueue<loopback_t *,0> *this)
{
  CTSQueue<loopback_t *,0> *v1; // esi
  CTSQueue<loopback_t *,0> *pNext; // eax
  loopback_t *sequence; // edi
  CTSQueue<loopback_t *,0>::NodeLink_t *p_m_Tail; // [esp+64h] [ebp-1Ch]
  int *p_sequence; // [esp+68h] [ebp-18h]
  CTSQueue<loopback_t *,0>::NodeLink_t *v8; // [esp+70h] [ebp-10h]
  CTSQueue<loopback_t *,0>::Node_t *pNode; // [esp+78h] [ebp-8h]

  v1 = this;
  p_m_Tail = &this->m_Tail;
  p_sequence = &this->m_Head.value.sequence;
  v8 = &this->m_Tail;
  while ( 1 )
  {
    do
    {
      while ( 1 )
      {
        do
        {
          pNode = v1->m_Head.value.pNode;
          pNext = (CTSQueue<loopback_t *,0> *)v1->m_Head.value.pNode->pNext;
        }
        while ( pNext == nullptr );
        if ( pNode != v8->value.pNode )
          break;
        if ( pNext == v1 )
          return nullptr;
        _ThreadInterlockedAssignIf64(
          a1: &v1->m_Tail,
          a2: pNext,
          a3: p_m_Tail->value.sequence + 1,
          a4: pNode,
          a5: p_m_Tail->value.sequence);
      }
    }
    while ( pNext == v1 );
    sequence = (loopback_t *)pNext->m_Head.value.sequence;
    if ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                            a1: this,
                            a2: pNext,
                            a3: *p_sequence + 1,
                            a4: pNode,
                            a5: *p_sequence) != 0 )
      break;
    v1 = this;
  }
  _InterlockedExchangeAdd(&this->m_Count.m_value, 0xFFFFFFFF);
  pNode->elem = sequence;
  return pNode;
}

//------------------------------------------------------------------------------
// Address: 0x1000AD10
// Name: protected: unsigned short CUtlLinkedList<struct netpacket_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct netpacket_t __near *,unsigned short>,unsigned short>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebx
  int m_nAllocationCount; // ecx
  unsigned __int16 result; // ax
  int v7; // edi
  CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlLinkedListElem_t<netpacket_t *,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t v11; // [esp+Eh] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_20:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      m_pMemory[v10].m_Next = -1;
      this->m_Memory.m_pMemory[v10].m_Previous = -1;
    }
    else
    {
      m_pMemory[v10].m_Next = result;
      this->m_Memory.m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  p_m_LastAlloc = &this->m_LastAlloc;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
  {
    result = -1;
  }
  else
  {
    result = p_m_LastAlloc->index + 1;
  }
  v11.index = result;
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( p_m_LastAlloc->index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      v11.index = (v7 > 0) - 1;
      v8 = &v11;
    }
    else
    {
      v8 = CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Next(
             (CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> *)this,
             result: &v11,
             it: (const CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
    }
    result = v8->index;
    if ( result >= v7 )
    {
      if ( _executeCount_0 < 10 )
      {
        ++_executeCount_0;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    p_m_LastAlloc->index = result;
    goto LABEL_20;
  }
  if ( _executeCount >= 10 )
    return -1;
  ++_executeCount;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000AE90
// Name: protected: unsigned short CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        bool multilist)
{
  unsigned __int16 m_FirstFree; // cx
  CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>::Iterator_t *p_m_LastAlloc; // ebx
  int m_nAllocationCount; // ecx
  unsigned __int16 result; // ax
  int v7; // edi
  CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t *v8; // eax
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // edx
  int v10; // ecx
  CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t v11; // [esp+Eh] [ebp-2h] BYREF

  m_FirstFree = this->m_FirstFree;
  if ( m_FirstFree != 0xFFFF )
  {
    result = m_FirstFree;
    this->m_FirstFree = this->m_Memory.m_pMemory[m_FirstFree].m_Next;
LABEL_20:
    m_pMemory = this->m_Memory.m_pMemory;
    v10 = result;
    if ( multilist )
    {
      m_pMemory[v10].m_Next = -1;
      this->m_Memory.m_pMemory[v10].m_Previous = -1;
    }
    else
    {
      m_pMemory[v10].m_Next = result;
      this->m_Memory.m_pMemory[v10].m_Previous = result;
    }
    return result;
  }
  p_m_LastAlloc = &this->m_LastAlloc;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( this->m_LastAlloc.index >= m_nAllocationCount )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    result = (m_nAllocationCount > 0) - 1;
  }
  else if ( (unsigned __int16)(p_m_LastAlloc->index + 1) >= m_nAllocationCount )
  {
    result = -1;
  }
  else
  {
    result = p_m_LastAlloc->index + 1;
  }
  v11.index = result;
  if ( result >= m_nAllocationCount )
  {
    CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>::Grow(this: &this->m_Memory, num: 1);
    this->m_pElements = this->m_Memory.m_pMemory;
    v7 = this->m_Memory.m_nAllocationCount;
    if ( p_m_LastAlloc->index >= v7 )
    {
      v7 = this->m_Memory.m_nAllocationCount;
      v11.index = (v7 > 0) - 1;
      v8 = &v11;
    }
    else
    {
      v8 = CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Next(
             (CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short> *)this,
             result: &v11,
             it: (const CUtlMemory<UtlRBTreeNode_t<CNetChan::SplitPlayer_t,unsigned short>,unsigned short>::Iterator_t *)&this->m_LastAlloc);
    }
    result = v8->index;
    if ( result >= v7 )
    {
      if ( _executeCount_2 < 10 )
      {
        ++_executeCount_2;
        _Warning(a1: "CUtlLinkedList overflow! (exhausted memory allocator)\n");
      }
      return -1;
    }
  }
  if ( result != 0xFFFF )
  {
    ++this->m_NumAlloced;
    p_m_LastAlloc->index = result;
    goto LABEL_20;
  }
  if ( _executeCount_1 >= 10 )
    return -1;
  ++_executeCount_1;
  _Warning(a1: "CUtlLinkedList overflow! (exhausted index range)\n");
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1000B010
// Name: private: void CNetworkSystem::DiscardStaleSplitpackets(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::DiscardStaleSplitpackets(CNetworkSystem *this, int sock)
{
  netsocket_t *m_pMemory; // ecx
  int v4; // esi
  CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int> > *p_m_splitPacket; // edi
  int v6; // ebx

  m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
  v4 = m_pMemory[sock].m_splitPacket.m_Size - 1;
  p_m_splitPacket = &m_pMemory[sock].m_splitPacket;
  if ( v4 >= 0 )
  {
    v6 = v4;
    do
    {
      if ( (float)(p_m_splitPacket->m_Memory.m_pMemory[v6].lastactivetime + 15.0) <= this->m_flNetworkTime )
      {
        if ( p_m_splitPacket->m_Size - v4 - 1 > 0 )
          _V_memmove(
            dest: &p_m_splitPacket->m_Memory.m_pMemory[v6],
            src: &p_m_splitPacket->m_Memory.m_pMemory[v6 + 1],
            count: 96728 * (p_m_splitPacket->m_Size - v4 - 1));
        --p_m_splitPacket->m_Size;
      }
      --v4;
      --v6;
    }
    while ( v4 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B0A0
// Name: public: CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(
        CUtlMemoryFixedGrowable<unsigned char,4096,int> *this)
{
  if ( this->m_nGrowSize >= 0 )
  {
    if ( this->m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_pMemory);
      this->m_pMemory = nullptr;
    }
    this->m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B0D0
// Name: private: void CNetworkSystem::CloseAllSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::CloseAllSockets(CNetworkSystem *this)
{
  int v2; // ebp
  int v3; // ebx
  int v4; // edi
  netsocket_t *v5; // eax
  CThreadFastMutex *v6; // ebx
  DWORD CurrentThreadId; // eax
  int i; // edi

  v2 = 0;
  v3 = 0;
  if ( this->m_NetSockets.m_Size > 0 )
  {
    v4 = 0;
    do
    {
      v5 = &this->m_NetSockets.m_Memory.m_pMemory[v4];
      if ( v5->nPort != 0 )
      {
        this->CloseSocket(this, a2: v5->hUDP, a3: -1);
        this->CloseSocket(this, a2: this->m_NetSockets.m_Memory.m_pMemory[v4].hTCP, a3: -1);
        this->m_NetSockets.m_Memory.m_pMemory[v4].nPort = 0;
        this->m_NetSockets.m_Memory.m_pMemory[v4].bListening = false;
        this->m_NetSockets.m_Memory.m_pMemory[v4].hUDP = 0;
        this->m_NetSockets.m_Memory.m_pMemory[v4].hTCP = 0;
      }
      ++v3;
      ++v4;
    }
    while ( v3 < this->m_NetSockets.m_Size );
  }
  if ( this == (CNetworkSystem *)-120 )
    v6 = nullptr;
  else
    v6 = &this->m_PendingSockets.CThreadFastMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != v6->m_ownerID
    && _InterlockedCompareExchange((volatile signed __int32 *)v6, CurrentThreadId, 0) != 0 )
  {
    _mm_pause();
    CThreadFastMutex::Lock(a1: v6, a2: CurrentThreadId, a3: 0);
  }
  else
  {
    ++v6->m_depth;
  }
  for ( i = 0; i < this->m_PendingSockets.m_Size; ++v2 )
  {
    this->CloseSocket(this, a2: this->m_PendingSockets.m_Memory.m_pMemory[v2].newsock, a3: -1);
    ++i;
  }
  this->m_PendingSockets.m_Size = 0;
  if ( v6->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v6, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000B1E0
// Name: public: virtual void CNetworkSystem::RemoveNetworkConfigChanged(class INetworkConfigChanged __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::RemoveNetworkConfigChanged(CNetworkSystem *this, INetworkConfigChanged *pCallback)
{
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
    this: (CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *)&this->m_NetworkConfigChangedCallbacks,
    src: (CNetChan::DataFragments_t **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000B200
// Name: public: virtual void CNetworkSystem::RemoveNetworkPacketFilterCallback(class INetworkPacketFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::RemoveNetworkPacketFilterCallback(
        CNetworkSystem *this,
        INetworkPacketFilter *pCallback)
{
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
    this: (CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *)&this->m_NetworkPacketFilterCallbacks,
    src: (CNetChan::DataFragments_t **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000B220
// Name: public: virtual void CNetworkSystem::RemoveNetworkFileDownloadFilter(class INetworkFileDownloadFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::RemoveNetworkFileDownloadFilter(
        CNetworkSystem *this,
        INetworkFileDownloadFilter *pCallback)
{
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
    this: (CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *)&this->m_NetworkFileDownloadFilterCallbacks,
    src: (CNetChan::DataFragments_t **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000B240
// Name: public: virtual void CNetworkSystem::RemoveNetworkFileSendCompletedCallback(class INetworkFileSendCompleted __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::RemoveNetworkFileSendCompletedCallback(
        CNetworkSystem *this,
        INetworkFileSendCompleted *pCallback)
{
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
    this: (CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *)&this->m_NetworkFileSendCompletedCallbacks,
    src: (CNetChan::DataFragments_t **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000B260
// Name: public: virtual void CNetworkSystem::RemoveNetworkPrepareStartupParamsCallback(class INetworkPrepareStartupParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::RemoveNetworkPrepareStartupParamsCallback(
        CNetworkSystem *this,
        INetworkPrepareStartupParams *pCallback)
{
  CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
    this: (CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *)&this->m_NetworkPrepareStartupParamsCallbacks,
    src: (CNetChan::DataFragments_t **)&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000B280
// Name: public: void CTSQueue<struct loopback_t __near *,0>::PushItem(struct loopback_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<loopback_t *,0>::PushItem(CTSQueue<loopback_t *,0> *this, loopback_t **init)
{
  CTSQueue<loopback_t *,0>::Node_t *v3; // eax

  v3 = (CTSQueue<loopback_t *,0>::Node_t *)CTSListBase::Pop(this: &this->m_FreeNodes);
  if ( v3 != nullptr || (v3 = (CTSQueue<loopback_t *,0>::Node_t *)operator new(nSize: 8u)) != nullptr )
  {
    v3->elem = *init;
    CTSQueue<loopback_t *,0>::Push(this, pNode: v3);
  }
  else
  {
    CTSQueue<loopback_t *,0>::Push(this, pNode: nullptr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B2C0
// Name: public: void CTSQueue<struct loopback_t __near *,0>::Purge(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CTSQueue<loopback_t *,0>::Purge(CTSQueue<loopback_t *,0> *this)
{
  CTSQueue<loopback_t *,0>::Node_t *i; // eax
  CTSListBase *p_m_FreeNodes; // edi
  TSLNodeBase_t *Next; // esi
  int value64_high; // eax

  for ( i = CTSQueue<loopback_t *,0>::Pop(this); i != nullptr; i = CTSQueue<loopback_t *,0>::Pop(this) )
    free(pMem: i);
  p_m_FreeNodes = &this->m_FreeNodes;
  while ( 1 )
  {
    Next = p_m_FreeNodes->m_Head.value.Next;
    value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
    if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
      break;
    while ( (unsigned __int8)_ThreadInterlockedAssignIf64(
                               a1: &this->m_FreeNodes,
                               a2: Next->Next,
                               a3: value64_high - 1,
                               a4: Next,
                               a5: value64_high) == 0 )
    {
      _mm_pause();
      Next = p_m_FreeNodes->m_Head.value.Next;
      value64_high = HIDWORD(this->m_FreeNodes.m_Head.value64);
      if ( p_m_FreeNodes->m_Head.value.Next == nullptr )
        goto LABEL_7;
    }
    free(pMem: Next);
  }
LABEL_7:
  this->m_Head.value.sequence = 0;
  this->m_Tail.value.sequence = 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000B340
// Name: public: void CUtlLinkedList<struct netpacket_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct netpacket_t __near *,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // dx
  UtlLinkedListElem_t<netpacket_t *,unsigned short> *v2; // esi
  unsigned __int16 m_Next; // ax
  unsigned __int16 m_FirstFree; // dx
  unsigned __int16 v5; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v2 = &this->m_Memory.m_pMemory[m_Head];
        m_Next = v2->m_Next;
        v2->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v2->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v5 = this->m_Head;
    if ( v5 != 0xFFFF )
      this->m_FirstFree = v5;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B4A0
// Name: public: void CUtlLinkedList<struct netpacket_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct netpacket_t __near *,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<netpacket_t *,unsigned short> *m_pMemory; // eax
  unsigned __int16 m_Next; // cx
  unsigned __int16 *p_m_Previous; // ebp
  unsigned __int16 v6; // di

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    m_pMemory = this->m_Memory.m_pMemory;
    if ( this->m_Memory.m_pMemory[elem].m_Previous != elem )
    {
      m_Next = m_pMemory[elem].m_Next;
      p_m_Previous = &m_pMemory[elem].m_Previous;
      v6 = *p_m_Previous;
      if ( *p_m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        m_pMemory[v6].m_Next = m_Next;
      if ( m_Next == 0xFFFF )
      {
        --this->m_ElementCount;
        this->m_Tail = v6;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = v6;
        --this->m_ElementCount;
      }
      *p_m_Previous = elem;
      m_pMemory[elem].m_Next = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B540
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v2; // eax
  unsigned __int16 m_Next; // dx
  unsigned __int16 m_Previous; // di

  if ( elem < this->m_Memory.m_nAllocationCount && elem <= this->m_LastAlloc.index )
  {
    v2 = &this->m_Memory.m_pMemory[elem];
    if ( v2->m_Previous != elem )
    {
      m_Next = v2->m_Next;
      m_Previous = v2->m_Previous;
      if ( m_Previous == 0xFFFF )
        this->m_Head = m_Next;
      else
        this->m_Memory.m_pMemory[m_Previous].m_Next = m_Next;
      if ( m_Next == 0xFFFF )
      {
        --this->m_ElementCount;
        this->m_Tail = m_Previous;
      }
      else
      {
        this->m_Memory.m_pMemory[m_Next].m_Previous = m_Previous;
        --this->m_ElementCount;
      }
      v2->m_Next = elem;
      v2->m_Previous = elem;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B5D0
// Name: public: void netsocket_t::ClearLagPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netsocket_t::ClearLagPackets(netsocket_t *this)
{
  int m_Head; // eax
  UtlLinkedListElem_t<netpacket_t *,unsigned short> *m_pMemory; // ecx
  unsigned int v4; // esi

  m_Head = this->m_LagPackets.m_Head;
  if ( m_Head != 0xFFFF )
  {
    m_pMemory = this->m_LagPackets.m_Memory.m_pMemory;
    do
    {
      v4 = (unsigned __int16)m_Head;
      free(pMem: m_pMemory[v4].m_Element->data);
      free(pMem: this->m_LagPackets.m_Memory.m_pMemory[v4].m_Element);
      m_pMemory = this->m_LagPackets.m_Memory.m_pMemory;
      m_Head = m_pMemory[v4].m_Next;
    }
    while ( m_Head != 0xFFFF );
  }
  CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LagPackets);
}

//------------------------------------------------------------------------------
// Address: 0x1000B630
// Name: private: void CNetworkSystem::SendLoopPacket(int,int,unsigned char const __near *,struct netadr_s const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SendLoopPacket(
        CNetworkSystem *this,
        int sock,
        int length,
        const unsigned __int8 *data,
        const netadr_s *to)
{
  int v5; // ebx
  int m_Size; // edi
  netsocket_t *m_pMemory; // edx
  int m_hLoopBackPairSocketIndex; // ecx
  netsocket_t *v9; // ecx
  netsocket_t *v10; // edi
  _DWORD *v11; // eax
  _DWORD *v12; // esi
  void *v13; // eax
  const unsigned __int8 *v14; // [esp-10h] [ebp-14h]

  v5 = length;
  if ( length <= 96000 )
  {
    m_Size = this->m_NetSockets.m_Size;
    if ( sock < m_Size )
    {
      m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
      m_hLoopBackPairSocketIndex = m_pMemory[sock].m_hLoopBackPairSocketIndex;
      if ( m_hLoopBackPairSocketIndex >= 0
        && m_hLoopBackPairSocketIndex < m_Size
        && m_pMemory[sock].m_pLoopBack != nullptr )
      {
        v9 = &m_pMemory[m_hLoopBackPairSocketIndex];
        v10 = v9;
        if ( v9->m_pLoopBack != nullptr && v9->m_hLoopBackPairSocketIndex == sock )
        {
          v11 = CUtlMemoryPool::Alloc(this: &loopback_t::s_Allocator, amount: 0x808u);
          v12 = v11;
          length = (int)v11;
          if ( v5 > 2048 )
            v13 = operator new(nSize: v5);
          else
            v13 = v11 + 2;
          v14 = data;
          *v12 = v13;
          _V_memcpy(dest: v13, src: v14, count: v5);
          v12[1] = v5;
          CTSQueue<loopback_t *,0>::PushItem(this: v10->m_pLoopBack, init: (loopback_t **)&length);
        }
      }
    }
  }
  else
  {
    _Warning(a1: "NET_SendLoopPacket:  packet too big (%i).\n", length);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B700
// Name: private: void CNetworkSystem::ClearLoopbackBuffers(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::ClearLoopbackBuffers(CNetworkSystem *this)
{
  int v2; // ebp
  CTSQueue<loopback_t *,0> *m_pLoopBack; // esi
  CTSQueue<loopback_t *,0>::Node_t *v4; // eax
  void **p_data; // edi
  int v6; // [esp+4h] [ebp-4h]

  v6 = 0;
  if ( this->m_NetSockets.m_Size > 0 )
  {
    v2 = 0;
    do
    {
      if ( this->m_NetSockets.m_Memory.m_pMemory[v2].m_pLoopBack != nullptr )
      {
        while ( 1 )
        {
          m_pLoopBack = this->m_NetSockets.m_Memory.m_pMemory[v2].m_pLoopBack;
          v4 = CTSQueue<loopback_t *,0>::Pop(this: m_pLoopBack);
          if ( v4 == nullptr )
            break;
          p_data = (void **)&v4->elem->data;
          CTSListBase::Push(this: &m_pLoopBack->m_FreeNodes, pNode: (TSLNodeBase_t *)v4);
          if ( *p_data != nullptr && *p_data != p_data + 2 )
            free(pMem: *p_data);
          CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: p_data);
        }
      }
      ++v2;
      ++v6;
    }
    while ( v6 < this->m_NetSockets.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B7A0
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(unsigned short,unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before,
        unsigned __int16 elem)
{
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // ebx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v5; // eax
  unsigned __int16 m_Tail; // dx
  int v7; // ecx

  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  m_pMemory = this->m_Memory.m_pMemory;
  v5 = &this->m_Memory.m_pMemory[elem];
  v5->m_Next = before;
  if ( before == 0xFFFF )
  {
    m_Tail = this->m_Tail;
    v5->m_Previous = m_Tail;
    this->m_Tail = elem;
  }
  else
  {
    v7 = before;
    m_Tail = m_pMemory[v7].m_Previous;
    v5->m_Previous = m_Tail;
    m_pMemory[v7].m_Previous = elem;
  }
  if ( m_Tail == 0xFFFF )
  {
    ++this->m_ElementCount;
    this->m_Head = elem;
  }
  else
  {
    m_pMemory[m_Tail].m_Next = elem;
    ++this->m_ElementCount;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000B820
// Name: public: netsocket_t::netsocket_t(void)
// Source: json
//------------------------------------------------------------------------------
netsocket_t *__thiscall netsocket_t::netsocket_t(netsocket_t *this)
{
  UtlLinkedListElem_t<netpacket_t *,unsigned short> *m_pMemory; // eax

  CUtlString::CUtlString(this: &this->m_sSocketName);
  netadr_s::SetIP(this: &this->m_NetPacket.from, unIP: 0);
  netadr_s::SetPort(this: &this->m_NetPacket.from, newport: 0);
  netadr_s::SetType(this: &this->m_NetPacket.from, newtype: NA_IP);
  this->m_NetPacket.message.m_bOverflow = false;
  this->m_NetPacket.message.m_pDebugName = nullptr;
  this->m_NetPacket.message.m_nDataBytes = 0;
  this->m_NetPacket.message.m_nDataBits = -1;
  this->m_NetPacket.source = 0;
  this->m_NetPacket.data = nullptr;
  this->m_NetPacket.size = 0;
  this->m_NetPacket.wiresize = 0;
  this->m_NetPacket.stream = false;
  this->m_NetPacket.received = 0.0;
  this->m_LagPackets.m_Memory.m_pMemory = nullptr;
  this->m_LagPackets.m_Memory.m_nAllocationCount = 0;
  this->m_LagPackets.m_Memory.m_nGrowSize = 0;
  this->m_LagPackets.m_LastAlloc.index = -1;
  this->m_LagPackets.m_Head = -1;
  this->m_LagPackets.m_Tail = -1;
  this->m_LagPackets.m_FirstFree = -1;
  m_pMemory = this->m_LagPackets.m_Memory.m_pMemory;
  this->m_LagPackets.m_ElementCount = 0;
  this->m_LagPackets.m_NumAlloced = 0;
  this->m_LagPackets.m_pElements = m_pMemory;
  this->m_splitPacket.m_Memory.m_pMemory = nullptr;
  this->m_splitPacket.m_Memory.m_nAllocationCount = 0;
  this->m_splitPacket.m_Memory.m_nGrowSize = 0;
  this->m_splitPacket.m_Size = 0;
  this->m_splitPacket.m_pElements = nullptr;
  this->nPort = 0;
  this->bListening = false;
  this->hUDP = 0;
  this->hTCP = 0;
  this->m_nLossCount = 0;
  this->m_pLoopBack = nullptr;
  this->m_bFakeLagEnabled = false;
  this->m_bCanUseSteamCnxMgr = false;
  this->m_bTryAny = false;
  this->m_nSplitPacketSequenceNumber = 1;
  this->m_hLoopBackPairSocketIndex = -1;
  this->m_nPortDesired = -1;
  this->m_nPortDefault = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000B920
// Name: public: virtual enum AppSystemTier_t CTier2AppSystem<class INetworkSystem,0>::GetTier(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CTier2AppSystem<INetworkSystem,0>::GetTier(CTier2AppSystem<INetworkSystem,0> *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x1000B930
// Name: public: virtual enum InitReturnVal_t CNetworkSystem::Init(void)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
BOOL __thiscall CNetworkSystem::Init(CNetworkSystem *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  int v5; // ecx
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  const char *v12; // eax
  WSAData wsaData_4; // [esp+10h] [ebp-190h] OVERLAPPED BYREF

  v2 = _CommandLine(a1: this);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-nodns") != 0 )
    *((_BYTE *)this + 304) |= 4u;
  v4 = _CommandLine(a1: v3);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v4 + 40))(a1: v4, a2: "-usetcp") != 0 )
    *((_BYTE *)this + 304) &= ~8u;
  v6 = _CommandLine(a1: v5);
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v6 + 40))(a1: v6, a2: "-noip") != 0 )
  {
    *((_BYTE *)this + 304) |= 2u;
  }
  else
  {
    CNetworkSystem::PlatformSpecificNetworkStartup(this);
    memset(&wsaData_4, 0, sizeof(wsaData_4));
    v8 = WSAStartup(wVersionRequested: 2u, lpWSAData: &wsaData_4);
    if ( v8 != 0 )
    {
      _Warning(a1: "Error! Failed to WSAStartup! err = %d.\n", v8);
      *((_BYTE *)this + 304) |= 2u;
    }
    else
    {
      v10 = _CommandLine(a1: v9);
      if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v10 + 40))(a1: v10, a2: "-winsockstatus") != 0 )
        _Msg(
          a1: "Socket layer initialized:\n"
          "       wsa ver used: %d.%d\n"
          "       wsa ver max:  %d.%d\n"
          "       description:  %s\n"
          "       sys status:   %s\n"
          "\n",
          LOBYTE(wsaData_4.wVersion),
          HIBYTE(wsaData_4.wVersion),
          LOBYTE(wsaData_4.wHighVersion),
          HIBYTE(wsaData_4.wHighVersion),
          wsaData_4.szDescription,
          wsaData_4.szSystemStatus);
    }
  }
  v11 = _CommandLine(a1: v7);
  v12 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v11 + 32))(
                        a1: v11,
                        a2: "-ip",
                        a3: 0);
  if ( v12 != nullptr )
    ConVar::SetValue(this: (ConVar *)&ipname.IConVar, value: v12);
  CNetworkSystem::ClearLoopbackBuffers(this);
  CNetChan::InitParanoidMode();
  return g_pSteamSocketMgrInternal->Init(this: g_pSteamSocketMgrInternal) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000BA70
// Name: public: virtual void CNetworkSystem::Shutdown(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::Shutdown(CNetworkSystem *this)
{
  int v2; // edi
  int v3; // ebx
  int v4; // eax

  g_pSteamSocketMgrInternal->Shutdown(this: g_pSteamSocketMgrInternal);
  v2 = 0;
  if ( this->m_NetSockets.m_Size > 0 )
  {
    v3 = 0;
    do
    {
      netsocket_t::ClearLagPackets(this: &this->m_NetSockets.m_Memory.m_pMemory[v3]);
      ++v2;
      ++v3;
    }
    while ( v2 < this->m_NetSockets.m_Size );
  }
  g_pQueuedPackedSender->Shutdown(this: g_pQueuedPackedSender);
  *((_BYTE *)this + 304) &= 0xEEu;
  CNetworkSystem::CloseAllSockets(this);
  CNetworkSystem::ClearLoopbackBuffers(this);
  if ( (*((_BYTE *)this + 304) & 2) == 0 )
  {
    v4 = WSACleanup();
    if ( v4 != 0 )
      _Msg(a1: "Failed to complete WSACleanup = 0x%x.\n", v4);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000BB00
// Name: public: virtual class INetChannel __near * CNetworkSystem::CreateNetChannel(int,struct netadr_s __near *,char const __near *,class INetChannelHandler __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CNetChan *__thiscall CNetworkSystem::CreateNetChannel(
        CNetworkSystem *this,
        int socket,
        netadr_s *adr,
        const char *name,
        INetChannelHandler *handler,
        CNetChan *bForceNewChannel)
{
  int v7; // ebp
  int v8; // eax
  unsigned __int16 v9; // ax
  CNetChan *NetChannel; // eax
  CNetChan *v11; // esi
  CNetChan *v12; // eax
  CThreadFastMutex *v13; // esi
  DWORD CurrentThreadId; // eax
  INetChannelHandler *v17; // [esp+0h] [ebp-18h]
  netadr_s address; // [esp+8h] [ebp-10h] BYREF
  int v19; // [esp+14h] [ebp-4h]

  netadr_s::SetIP(this: (netadr_s *)address.ip, unIP: 0);
  netadr_s::SetPort(this: (netadr_s *)address.ip, newport: 0);
  netadr_s::SetType(this: (netadr_s *)address.ip, newtype: NA_IP);
  v7 = socket;
  if ( adr != nullptr )
  {
    v8 = *(_DWORD *)&adr->port;
    *(_QWORD *)address.ip = *(_QWORD *)&adr->type;
    v19 = v8;
    if ( netadr_s::GetPort(this: (netadr_s *)address.ip) == 0
      && netadr_s::GetType(this: (netadr_s *)address.ip) == NA_IP )
    {
      v9 = this->GetUDPPort(this, a2: socket);
      netadr_s::SetPort(this: (netadr_s *)address.ip, newport: v9);
    }
  }
  else
  {
    netadr_s::Clear(this: (netadr_s *)address.ip);
    netadr_s::SetType(this: (netadr_s *)address.ip, newtype: NA_NULL);
  }
  if ( (_BYTE)bForceNewChannel == 0 && adr != nullptr )
  {
    NetChannel = CNetworkSystem::FindNetChannel(this, socket, adr: (netadr_s *)address.ip);
    v11 = NetChannel;
    if ( NetChannel != nullptr )
    {
      NetChannel->Clear(this: NetChannel);
      goto LABEL_24;
    }
  }
  v12 = (CNetChan *)operator new(nSize: 0x4140u);
  if ( v12 != nullptr )
    bForceNewChannel = CNetChan::CNetChan(this: v12);
  else
    bForceNewChannel = nullptr;
  if ( this == (CNetworkSystem *)-84 )
    v13 = nullptr;
  else
    v13 = &this->m_NetChannels.CThreadFastMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId != v13->m_ownerID )
  {
    if ( _InterlockedCompareExchange((volatile signed __int32 *)v13, CurrentThreadId, 0) != 0 )
    {
      _mm_pause();
      CThreadFastMutex::Lock(a1: v13, a2: CurrentThreadId, a3: 0);
      v7 = socket;
      goto LABEL_21;
    }
    v7 = socket;
  }
  ++v13->m_depth;
LABEL_21:
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
    this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetChannels,
    elem: this->m_NetChannels.m_Size,
    src: (void (__cdecl **)(IConVar *, const char *, float))&bForceNewChannel);
  if ( v13->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v13, 0);
  v11 = bForceNewChannel;
LABEL_24:
  if ( v7 < this->m_NetSockets.m_Size )
    netsocket_t::ClearLagPackets(this: &this->m_NetSockets.m_Memory.m_pMemory[v7]);
  CNetChan::Setup(this: v11, a2: (int)this, sock: v7, adr: (netadr_s *)address.ip, name, handler, a7: v17);
  return v11;
}

//------------------------------------------------------------------------------
// Address: 0x1000BC90
// Name: private: class CSplitPacketEntry __near * CNetworkSystem::FindOrCreateSplitPacketEntry(int,struct netadr_s __near *)
// Source: json
//------------------------------------------------------------------------------
CSplitPacketEntry *__thiscall CNetworkSystem::FindOrCreateSplitPacketEntry(
        CNetworkSystem *this,
        const int sock,
        netadr_s *from)
{
  netsocket_t *m_pMemory; // ecx
  CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int> > *p_m_splitPacket; // ebx
  int v5; // edi
  int v6; // ebp
  const netadr_s *p_from; // esi
  int v8; // edx
  int v9; // eax
  int m_Size; // [esp+10h] [ebp-179DCh]
  CSplitPacketEntry v12; // [esp+14h] [ebp-179D8h] BYREF

  m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
  p_m_splitPacket = &m_pMemory[sock].m_splitPacket;
  v5 = 0;
  m_Size = m_pMemory[sock].m_splitPacket.m_Size;
  if ( m_Size > 0 )
  {
    v6 = 0;
    while ( 1 )
    {
      p_from = &p_m_splitPacket->m_Memory.m_pMemory[v6].from;
      if ( netadr_s::CompareAdr(this: from, a: p_from, onlyBase: false) )
        break;
      ++v5;
      ++v6;
      if ( v5 >= m_Size )
        goto LABEL_7;
    }
    if ( v5 < m_Size )
      return (CSplitPacketEntry *)p_from;
  }
LABEL_7:
  netadr_s::SetIP(this: &v12.from, unIP: 0);
  netadr_s::SetPort(this: &v12.from, newport: 0);
  netadr_s::SetType(this: &v12.from, newtype: NA_IP);
  memset(&v12, 0, 12);
  memset(v12.splitflags, 0xFFu, sizeof(v12.splitflags));
  memset(&v12.netsplit, 0, 96036);
  v8 = p_m_splitPacket->m_Size;
  v9 = *(_DWORD *)&from->port;
  *(_QWORD *)&v12.from.type = *(_QWORD *)&from->type;
  *(_DWORD *)&v12.from.port = v9;
  CUtlVector<CSplitPacketEntry,CUtlMemory<CSplitPacketEntry,int>>::InsertBefore(
    this: p_m_splitPacket,
    elem: v8,
    src: &v12);
  return &p_m_splitPacket->m_Memory.m_pMemory[p_m_splitPacket->m_Size - 1];
}

//------------------------------------------------------------------------------
// Address: 0x1000BDC0
// Name: private: bool CNetworkSystem::GetLong(int,struct netpacket_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::GetLong(CNetworkSystem *this, int sock, netpacket_t *packet)
{
  unsigned int v4; // eax
  CSplitPacketEntry *SplitPacketEntry; // eax
  unsigned __int8 *v8; // esi
  unsigned __int8 *data; // ecx
  int v10; // edx
  int v11; // ebp
  int v12; // eax
  int v13; // edi
  int v14; // ecx
  const char *v15; // eax
  unsigned int v16; // ecx
  int v17; // eax
  int m_nValue; // eax
  const char *v19; // eax
  const char *v20; // eax
  unsigned int v21; // eax
  const char *v22; // eax
  const char *v23; // eax
  const char *v24; // eax
  int v25; // [esp-18h] [ebp-2Ch]
  int v26; // [esp-14h] [ebp-28h]
  int v27; // [esp-10h] [ebp-24h]
  int v28; // [esp-Ch] [ebp-20h]
  const char *v29; // [esp-Ch] [ebp-20h]
  int sequenceNumber; // [esp+8h] [ebp-Ch]
  int v31; // [esp+Ch] [ebp-8h]
  int size; // [esp+1Ch] [ebp+8h]

  v4 = packet->size;
  if ( v4 < 0xC )
  {
    _Msg(a1: "Invalid split packet length %i\n", v4);
    return 0;
  }
  SplitPacketEntry = CNetworkSystem::FindOrCreateSplitPacketEntry(this, sock, from: &packet->from);
  v8 = (unsigned __int8 *)SplitPacketEntry;
  if ( SplitPacketEntry == nullptr )
    return 0;
  SplitPacketEntry->lastactivetime = this->m_flNetworkTime;
  data = packet->data;
  v10 = *((_DWORD *)data + 1);
  v11 = *((__int16 *)data + 5);
  v12 = (unsigned __int8)*((_WORD *)data + 4);
  v13 = *((__int16 *)data + 4) >> 8;
  v31 = v10;
  sequenceNumber = v12;
  if ( (unsigned int)(v11 - 564) > 0x270 )
  {
    v25 = (unsigned __int8)*((_WORD *)data + 4);
    v24 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with invalid split size (number %i/ count %i) where size %i is out of valid range [%d - %d ]\n",
      v24,
      v13,
      v25,
      v11,
      564,
      1188);
    return 0;
  }
  if ( v13 >= 170 || (unsigned __int8)*((_WORD *)data + 4) > 0xAAu )
  {
    v27 = (unsigned __int8)*((_WORD *)data + 4);
    v23 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with too many split parts (number %i/ count %i) where %i is max count allowed\n",
      v23,
      v13,
      v27,
      170);
    return 0;
  }
  v14 = *((_DWORD *)v8 + 173);
  if ( v14 == -1 || v10 != v14 )
  {
    *((_DWORD *)v8 + 173) = v10;
    *((_DWORD *)v8 + 174) = v12;
    *((_DWORD *)v8 + 176) = v11;
  }
  if ( *((_DWORD *)v8 + 176) != v11 )
  {
    v28 = *((_DWORD *)v8 + 176);
    v26 = v12;
    v15 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Split packet from %s with inconsistent split size (number %i/ count %i) where size %i not equal to i"
      "nitial size of %i\n",
      v15,
      v13,
      v26,
      v11,
      v28);
    return 0;
  }
  v16 = packet->size - 12;
  size = v16;
  if ( *(_DWORD *)&v8[4 * v13 + 12] == v10 )
  {
    v20 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(
      a1: "NET_GetLong:  Ignoring duplicated split packet %i of %i ( %i bytes ) from %s\n",
      v13 + 1,
      sequenceNumber,
      size,
      v20);
    goto LABEL_20;
  }
  v17 = v12 - 1;
  if ( v13 == v17 )
    *((_DWORD *)v8 + 175) = v16 + v11 * v17;
  --*((_DWORD *)v8 + 174);
  *(_DWORD *)&v8[4 * v13 + 12] = v10;
  m_nValue = net_showsplits.m_pParent->m_Value.m_nValue;
  if ( m_nValue != 0 && m_nValue != 3 )
  {
    v29 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    v19 = this->DescribeSocket(this, a2: sock);
    _Msg(
      a1: "<-- [%s] Split packet %4i/%4i seq %5i size %4i mtu %4i from %s\n",
      v19,
      v13 + 1,
      sequenceNumber,
      v31,
      size,
      v11 + 12,
      v29);
LABEL_20:
    v16 = size;
  }
  memcpy(dst: &v8[v13 * v11 + 708], src: packet->data + 12, count: v16);
  if ( *((int *)v8 + 174) > 0 )
    return 0;
  v21 = *((_DWORD *)v8 + 175);
  *((_DWORD *)v8 + 173) = -1;
  if ( v21 <= 0x17710 )
  {
    _V_memcpy(dest: packet->data, src: v8 + 708, count: v21);
    packet->size = *((_DWORD *)v8 + 175);
    packet->wiresize = *((_DWORD *)v8 + 175);
    return 1;
  }
  else
  {
    v22 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _Msg(a1: "Split packet too large! %d bytes from %s\n", *((_DWORD *)v8 + 175), v22);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C070
// Name: private: void CBindAddressHelper::BuildBindAddresses(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBindAddressHelper::BuildBindAddresses(
        CBindAddressHelper *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  _IP_ADAPTER_INFO *v2; // esi
  _IP_ADAPTER_INFO *i; // edi
  const CUtlString *v4; // eax
  _IP_ADAPTER_INFO *infos; // [esp+4h] [ebp-2A0h] BYREF
  _IP_ADAPTER_INFO *v6; // [esp+8h] [ebp-29Ch]
  CUtlString v7; // [esp+Ch] [ebp-298h] BYREF
  _IP_ADAPTER_INFO AdapterInfo; // [esp+1Ch] [ebp-288h] BYREF

  infos = nullptr;
  if ( GetAdaptersInfo(&AdapterInfo, SizePointer: (PULONG)&infos) == 111 )
  {
    v2 = (_IP_ADAPTER_INFO *)operator new(nSize: 648 * (_DWORD)infos);
    v6 = v2;
    if ( v2 == nullptr )
      _Error(a1: "BuildBindAddresses:  Out of memory allocating %d bytes\n", 648 * (_DWORD)infos);
    if ( GetAdaptersInfo(AdapterInfo: v2, SizePointer: (PULONG)&infos) == 0 )
    {
      for ( i = v2; i != nullptr; i = i->Next )
      {
        if ( i->Type != 24 )
        {
          if ( _V_strcmp(s1: i->IpAddressList.IpAddress.String, s2: "0.0.0.0") != 0 )
          {
            _Msg(a1: "NET_GetBindAddresses found %s: '%s'\n", i->IpAddressList.IpAddress.String, i->Description);
            v4 = CUtlString::CUtlString(this: &v7, pString: i->IpAddressList.IpAddress.String);
            CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: list, elem: list->m_Size, src: v4);
            if ( v7.m_Storage.m_Memory.m_nGrowSize >= 0 )
            {
              if ( v7.m_Storage.m_Memory.m_pMemory != nullptr )
              {
                _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v7.m_Storage.m_Memory.m_pMemory);
                v7.m_Storage.m_Memory.m_pMemory = nullptr;
              }
              v7.m_Storage.m_Memory.m_nAllocationCount = 0;
            }
          }
          v2 = v6;
        }
      }
    }
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C1A0
// Name: public: virtual void CNetworkSystem::AddNetworkConfigChangedCallback(class INetworkConfigChanged __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::AddNetworkConfigChangedCallback(CNetworkSystem *this, INetworkConfigChanged *pCallback)
{
  int m_Size; // edx
  CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *p_m_NetworkConfigChangedCallbacks; // ecx
  int v4; // eax
  INetworkConfigChanged **m_pMemory; // esi

  m_Size = this->m_NetworkConfigChangedCallbacks.m_Size;
  p_m_NetworkConfigChangedCallbacks = (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkConfigChangedCallbacks;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (INetworkConfigChanged **)p_m_NetworkConfigChangedCallbacks->m_Memory.m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
LABEL_7:
    CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
      this: p_m_NetworkConfigChangedCallbacks,
      elem: m_Size,
      src: (void (__cdecl **)(IConVar *, const char *, float))&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000C200
// Name: public: virtual void CNetworkSystem::AddNetworkPacketFilterCallback(class INetworkPacketFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::AddNetworkPacketFilterCallback(CNetworkSystem *this, INetworkPacketFilter *pCallback)
{
  int m_Size; // edx
  CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *p_m_NetworkPacketFilterCallbacks; // ecx
  int v4; // eax
  INetworkPacketFilter **m_pMemory; // esi

  m_Size = this->m_NetworkPacketFilterCallbacks.m_Size;
  p_m_NetworkPacketFilterCallbacks = (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkPacketFilterCallbacks;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (INetworkPacketFilter **)p_m_NetworkPacketFilterCallbacks->m_Memory.m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
LABEL_7:
    CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
      this: p_m_NetworkPacketFilterCallbacks,
      elem: m_Size,
      src: (void (__cdecl **)(IConVar *, const char *, float))&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000C260
// Name: public: virtual void CNetworkSystem::AddNetworkFileDownloadFilter(class INetworkFileDownloadFilter __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::AddNetworkFileDownloadFilter(
        CNetworkSystem *this,
        INetworkFileDownloadFilter *pCallback)
{
  int m_Size; // edx
  CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *p_m_NetworkFileDownloadFilterCallbacks; // ecx
  int v4; // eax
  INetworkFileDownloadFilter **m_pMemory; // esi

  m_Size = this->m_NetworkFileDownloadFilterCallbacks.m_Size;
  p_m_NetworkFileDownloadFilterCallbacks = (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkFileDownloadFilterCallbacks;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (INetworkFileDownloadFilter **)p_m_NetworkFileDownloadFilterCallbacks->m_Memory.m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
LABEL_7:
    CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
      this: p_m_NetworkFileDownloadFilterCallbacks,
      elem: m_Size,
      src: (void (__cdecl **)(IConVar *, const char *, float))&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000C2C0
// Name: public: virtual void CNetworkSystem::AddNetworkFileSendCompletedCallback(class INetworkFileSendCompleted __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::AddNetworkFileSendCompletedCallback(
        CNetworkSystem *this,
        INetworkFileSendCompleted *pCallback)
{
  int m_Size; // edx
  CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *p_m_NetworkFileSendCompletedCallbacks; // ecx
  int v4; // eax
  INetworkFileSendCompleted **m_pMemory; // esi

  m_Size = this->m_NetworkFileSendCompletedCallbacks.m_Size;
  p_m_NetworkFileSendCompletedCallbacks = (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkFileSendCompletedCallbacks;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (INetworkFileSendCompleted **)p_m_NetworkFileSendCompletedCallbacks->m_Memory.m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
LABEL_7:
    CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
      this: p_m_NetworkFileSendCompletedCallbacks,
      elem: m_Size,
      src: (void (__cdecl **)(IConVar *, const char *, float))&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000C320
// Name: public: virtual void CNetworkSystem::AddNetworkPrepareStartupParamsCallback(class INetworkPrepareStartupParams __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::AddNetworkPrepareStartupParamsCallback(
        CNetworkSystem *this,
        INetworkPrepareStartupParams *pCallback)
{
  int m_Size; // edx
  CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *p_m_NetworkPrepareStartupParamsCallbacks; // ecx
  int v4; // eax
  INetworkPrepareStartupParams **m_pMemory; // esi

  m_Size = this->m_NetworkPrepareStartupParamsCallbacks.m_Size;
  p_m_NetworkPrepareStartupParamsCallbacks = (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkPrepareStartupParamsCallbacks;
  v4 = 0;
  if ( m_Size <= 0 )
    goto LABEL_7;
  m_pMemory = (INetworkPrepareStartupParams **)p_m_NetworkPrepareStartupParamsCallbacks->m_Memory.m_pMemory;
  while ( *m_pMemory != pCallback )
  {
    ++v4;
    ++m_pMemory;
    if ( v4 >= m_Size )
      goto LABEL_7;
  }
  if ( v4 == -1 )
LABEL_7:
    CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int>>::InsertBefore(
      this: p_m_NetworkPrepareStartupParamsCallbacks,
      elem: m_Size,
      src: (void (__cdecl **)(IConVar *, const char *, float))&pCallback);
}

//------------------------------------------------------------------------------
// Address: 0x1000C380
// Name: public: void CUtlLinkedList<struct netpacket_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct netpacket_t __near *,unsigned short>,unsigned short>>::Remove(unsigned short)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::Remove(
        CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short> > *this,
        unsigned __int16 elem)
{
  CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem);
  this->m_Memory.m_pMemory[elem].m_Next = this->m_FirstFree;
  this->m_FirstFree = elem;
}

//------------------------------------------------------------------------------
// Address: 0x1000C3B0
// Name: public: unsigned short CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::InsertBefore(unsigned short)
// Source: json
//------------------------------------------------------------------------------
unsigned __int16 __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::InsertBefore(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this,
        unsigned __int16 before)
{
  unsigned __int16 v3; // bx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v5; // esi

  v3 = CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::AllocInternal(
         this,
         multilist: false);
  if ( v3 == 0xFFFF )
    return -1;
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::LinkBefore(
    this,
    before,
    elem: v3);
  v5 = &this->m_Memory.m_pMemory[v3];
  if ( v5 != nullptr )
  {
    v5->m_Element.m_pChannel = nullptr;
    v5->m_Element.m_Socket = -1;
    CUtlBuffer::CUtlBuffer(this: &v5->m_Element.m_Buffer, growSize: 0, initSize: 0, nFlags: 0);
    CUtlBuffer::CUtlBuffer(this: &v5->m_Element.m_To, growSize: 0, initSize: 0, nFlags: 0);
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1000C420
// Name: public: netsocket_t::~netsocket_t(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall netsocket_t::~netsocket_t(netsocket_t *this)
{
  CTSQueue<loopback_t *,0> *m_pLoopBack; // edi
  CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short> > *p_m_LagPackets; // edi

  netsocket_t::ClearLagPackets(this);
  this->m_splitPacket.m_Size = 0;
  m_pLoopBack = this->m_pLoopBack;
  if ( m_pLoopBack != nullptr )
  {
    CTSQueue<loopback_t *,0>::Purge(this: this->m_pLoopBack);
    free(pMem: m_pLoopBack->m_Head.value.pNode);
    CTSListBase::Detach(this: &m_pLoopBack->m_FreeNodes);
    free(pMem: m_pLoopBack);
  }
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_splitPacket);
  p_m_LagPackets = &this->m_LagPackets;
  CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::RemoveAll(this: &this->m_LagPackets);
  if ( this->m_LagPackets.m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_LagPackets->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_LagPackets->m_Memory.m_pMemory);
      p_m_LagPackets->m_Memory.m_pMemory = nullptr;
    }
    this->m_LagPackets.m_Memory.m_nAllocationCount = 0;
  }
  if ( this->m_sSocketName.m_Storage.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_sSocketName.m_Storage.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_sSocketName.m_Storage.m_Memory.m_pMemory);
      this->m_sSocketName.m_Storage.m_Memory.m_pMemory = nullptr;
    }
    this->m_sSocketName.m_Storage.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C4C0
// Name: public: void CBindAddressHelper::GetBindAddresses(class CUtlVector<class CUtlString,class CUtlMemory<class CUtlString,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CBindAddressHelper::GetBindAddresses(
        CBindAddressHelper *this,
        CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *list)
{
  int m_Size; // edi
  int m_nAllocationCount; // eax
  const CUtlString *v6; // ebp
  CUtlString *m_pMemory; // ecx
  int v8; // eax
  bool v9; // zf
  CUtlString *v10; // edi
  int v11; // [esp+4h] [ebp-4h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *lista; // [esp+Ch] [ebp+4h]

  if ( !this->m_bInitialized )
  {
    this->m_bInitialized = true;
    CBindAddressHelper::BuildBindAddresses(this, list: &this->m_CachedAddresses);
  }
  v11 = 0;
  if ( this->m_CachedAddresses.m_Size > 0 )
  {
    lista = nullptr;
    do
    {
      m_Size = list->m_Size;
      m_nAllocationCount = list->m_Memory.m_nAllocationCount;
      v6 = (const CUtlString *)((char *)lista + (unsigned int)this->m_CachedAddresses.m_Memory.m_pMemory);
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CUtlString,int>::Grow(this: &list->m_Memory, num: m_Size - m_nAllocationCount + 1);
      ++list->m_Size;
      m_pMemory = list->m_Memory.m_pMemory;
      v8 = list->m_Size - m_Size - 1;
      v9 = list->m_Size - m_Size == 1;
      list->m_pElements = list->m_Memory.m_pMemory;
      if ( v8 >= 0 && !v9 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 16 * v8);
      v10 = &list->m_Memory.m_pMemory[m_Size];
      if ( v10 != nullptr )
        CUtlString::CUtlString(this: v10, string: v6);
      lista = (CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *)((char *)lista + 16);
      ++v11;
    }
    while ( v11 < this->m_CachedAddresses.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C570
// Name: public: unsigned short CUtlLinkedList<struct netpacket_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct netpacket_t __near *,unsigned short>,unsigned short>>::AddToTail(struct netpacket_t __near * const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::AddToTail(
        CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short> > *this,
        netpacket_t **src)
{
  unsigned __int16 v3; // ax
  unsigned __int16 v4; // di
  int v6; // ecx
  UtlLinkedListElem_t<netpacket_t *,unsigned short> *v7; // eax
  unsigned __int16 m_Tail; // bx
  UtlLinkedListElem_t<netpacket_t *,unsigned short> *v9; // esi

  v3 = CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::AllocInternal(
         this,
         multilist: false);
  v4 = v3;
  if ( v3 == 0xFFFF )
    return 0xFFFF;
  CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::Unlink(
    this,
    elem: v3);
  v6 = v4;
  v7 = &this->m_Memory.m_pMemory[v6];
  v7->m_Next = -1;
  m_Tail = this->m_Tail;
  v7->m_Previous = m_Tail;
  this->m_Tail = v4;
  if ( m_Tail == 0xFFFF )
    this->m_Head = v4;
  else
    this->m_Memory.m_pMemory[m_Tail].m_Next = v4;
  ++this->m_ElementCount;
  v9 = &this->m_Memory.m_pMemory[v6];
  if ( v9 != nullptr )
    v9->m_Element = *src;
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x1000C5F0
// Name: public: void CUtlLinkedList<struct SendQueueItem_t,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *this)
{
  unsigned __int16 m_Head; // bx
  int v3; // eax
  unsigned __int16 m_Next; // di
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v5; // esi
  unsigned __int16 m_FirstFree; // ax
  unsigned __int16 v7; // ax

  if ( this->m_LastAlloc.index != 0xFFFF )
  {
    m_Head = this->m_Head;
    if ( m_Head != 0xFFFF )
    {
      do
      {
        v3 = m_Head;
        m_Next = this->m_Memory.m_pMemory[v3].m_Next;
        v5 = &this->m_Memory.m_pMemory[v3];
        if ( v5->m_Element.m_To.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_To.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_To.m_Memory.m_pMemory);
            v5->m_Element.m_To.m_Memory.m_pMemory = nullptr;
          }
          v5->m_Element.m_To.m_Memory.m_nAllocationCount = 0;
        }
        if ( v5->m_Element.m_Buffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v5->m_Element.m_Buffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v5->m_Element.m_Buffer.m_Memory.m_pMemory);
            v5->m_Element.m_Buffer.m_Memory.m_pMemory = nullptr;
          }
          v5->m_Element.m_Buffer.m_Memory.m_nAllocationCount = 0;
        }
        v5->m_Previous = m_Head;
        if ( m_Next == 0xFFFF )
          m_FirstFree = this->m_FirstFree;
        else
          m_FirstFree = m_Next;
        v5->m_Next = m_FirstFree;
        m_Head = m_Next;
      }
      while ( m_Next != 0xFFFF );
    }
    v7 = this->m_Head;
    if ( v7 != 0xFFFF )
      this->m_FirstFree = v7;
    this->m_Head = -1;
    this->m_Tail = -1;
    this->m_ElementCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000C7A0
// Name: private: void CNetworkSystem::AddToLagged(class CUtlLinkedList<struct netpacket_t __near *,unsigned short,0,unsigned short,class CUtlMemory<struct UtlLinkedListElem_t<struct netpacket_t __near *,unsigned short>,unsigned short>> __near &,struct netpacket_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::AddToLagged(
        CNetworkSystem *this,
        CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short> > *list,
        netpacket_t *pPacket)
{
  netpacket_t *v3; // eax
  netpacket_t *v4; // ebp
  unsigned __int8 *v5; // eax
  unsigned int size; // [esp-4h] [ebp-18h]
  netpacket_t *src; // [esp+10h] [ebp-4h] BYREF

  v3 = (netpacket_t *)operator new(nSize: 0x50u);
  if ( v3 != nullptr )
    v4 = netpacket_t::netpacket_t(this: v3);
  else
    v4 = nullptr;
  qmemcpy(v4, pPacket, sizeof(netpacket_t));
  size = pPacket->size;
  src = v4;
  v5 = (unsigned __int8 *)operator new(nSize: size);
  v4->data = v5;
  _V_memcpy(dest: v5, src: pPacket->data, count: pPacket->size);
  CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::AddToTail(
    this: list,
    &src);
}

//------------------------------------------------------------------------------
// Address: 0x1000C810
// Name: private: bool CNetworkSystem::LagPacket(bool,struct netpacket_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::LagPacket(CNetworkSystem *this, bool newdata, netpacket_t *packet)
{
  int source; // ecx
  int m_nValue; // eax
  netsocket_t *m_pMemory; // edx
  int v8; // ecx
  float m_fValue; // xmm0_4
  int p_m_nLossCount; // ecx
  int v11; // ecx
  int v12; // esi
  int v13; // edi
  netsocket_t *v14; // edx
  int v15; // ecx
  CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short> > *p_m_LagPackets; // ebx
  unsigned __int16 m_Head; // ax
  netpacket_t *m_Element; // esi
  float v19; // xmm1_4
  float m_flFakeLagMilliseconds; // xmm0_4
  float v21; // xmm0_4
  double v22; // st7
  unsigned __int16 v23; // [esp+18h] [ebp-4h]
  float target; // [esp+20h] [ebp+4h]
  float targeta; // [esp+20h] [ebp+4h]

  source = packet->source;
  if ( source < 0 || source >= this->m_NetSockets.m_Size )
    return newdata;
  m_nValue = droppackets.m_pParent->m_Value.m_nValue;
  if ( m_nValue > 0 && newdata && this->m_NetSockets.m_Memory.m_pMemory[source].m_bFakeLagEnabled )
  {
    ConVar::SetValue(this: (ConVar *)&droppackets.IConVar, value: m_nValue - 1);
    return 0;
  }
  if ( fakeloss.m_pParent->m_Value.m_fValue != 0.0 && newdata )
  {
    m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
    v8 = source;
    ++m_pMemory[v8].m_nLossCount;
    m_fValue = fakeloss.m_pParent->m_Value.m_fValue;
    p_m_nLossCount = (int)&m_pMemory[v8].m_nLossCount;
    if ( m_fValue <= 0.0 )
    {
      v11 = (int)fabs(m_fValue);
      if ( v11 < 2 )
        v11 = 2;
      if ( this->m_NetSockets.m_Memory.m_pMemory[packet->source].m_nLossCount % v11 == 0 )
        return 0;
    }
    else if ( _RandomInt(a1: p_m_nLossCount, a2: 0, a3: 100) <= (int)m_fValue )
    {
      return 0;
    }
  }
  if ( this->m_flFakeLagMilliseconds > 0.0 )
  {
    v14 = this->m_NetSockets.m_Memory.m_pMemory;
    v15 = packet->source;
    p_m_LagPackets = &v14[v15].m_LagPackets;
    if ( newdata )
      CNetworkSystem::AddToLagged(this, list: &v14[v15].m_LagPackets, pPacket: packet);
    m_Head = p_m_LagPackets->m_Head;
    v23 = m_Head;
    if ( m_Head == 0xFFFF )
      return 0;
    m_Element = p_m_LagPackets->m_Memory.m_pMemory[m_Head].m_Element;
    if ( m_Element == nullptr )
      return 0;
    v19 = fakejitter.m_pParent->m_Value.m_fValue;
    m_flFakeLagMilliseconds = this->m_flFakeLagMilliseconds;
    target = m_flFakeLagMilliseconds;
    if ( v19 > 0.0 )
    {
      v21 = m_flFakeLagMilliseconds * 0.5;
      if ( v21 > v19 )
        v21 = fakejitter.m_pParent->m_Value.m_fValue;
      v22 = _RandomFloat(a1: -0.0 - v21, a2: LODWORD(v21));
      m_Head = v23;
      targeta = v22 + target;
      m_flFakeLagMilliseconds = targeta;
    }
    if ( (float)(m_flFakeLagMilliseconds * 0.001) + m_Element->received <= this->m_flNetworkTime )
    {
      CUtlLinkedList<netpacket_t *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<netpacket_t *,unsigned short>,unsigned short>>::Remove(
        this: p_m_LagPackets,
        elem: m_Head);
      packet->source = m_Element->source;
      packet->from = m_Element->from;
      packet->received = this->m_flNetworkTime;
      packet->size = m_Element->size;
      packet->wiresize = m_Element->wiresize;
      packet->stream = m_Element->stream;
      _V_memcpy(dest: packet->data, src: m_Element->data, count: m_Element->size);
      free(pMem: m_Element->data);
      free(pMem: m_Element);
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    v12 = 0;
    if ( this->m_NetSockets.m_Size > 0 )
    {
      v13 = 0;
      do
      {
        netsocket_t::ClearLagPackets(this: &this->m_NetSockets.m_Memory.m_pMemory[v13]);
        ++v12;
        ++v13;
      }
      while ( v12 < this->m_NetSockets.m_Size );
    }
    return newdata;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CAB0
// Name: private: bool CNetworkSystem::GetLoopPacket(struct netpacket_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::GetLoopPacket(CNetworkSystem *this, netpacket_t *packet)
{
  int source; // eax
  netsocket_t *m_pMemory; // ecx
  int v6; // eax
  CTSListBase *m_pLoopBack; // ebx
  CTSQueue<loopback_t *,0>::Node_t *v8; // eax
  loopback_t *elem; // esi
  int datalen; // edx
  char *data; // eax
  bool v12; // zf

  source = packet->source;
  if ( source < 0 || source >= this->m_NetSockets.m_Size )
    return 0;
  m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
  v6 = source;
  m_pLoopBack = (CTSListBase *)m_pMemory[v6].m_pLoopBack;
  if ( m_pLoopBack == nullptr )
    return 0;
  v8 = CTSQueue<loopback_t *,0>::Pop(this: m_pMemory[v6].m_pLoopBack);
  if ( v8 == nullptr )
    return 0;
  elem = v8->elem;
  CTSListBase::Push(this: m_pLoopBack + 3, pNode: (TSLNodeBase_t *)v8);
  if ( elem->datalen != 0 )
  {
    netadr_s::SetType(this: &packet->from, newtype: NA_LOOPBACK);
    datalen = elem->datalen;
    packet->size = datalen;
    packet->wiresize = elem->datalen;
    _V_memcpy(dest: packet->data, src: elem->data, count: datalen);
    data = elem->data;
    v12 = elem->data == elem->defbuffer;
    elem->datalen = 0;
    if ( !v12 )
    {
      free(pMem: data);
      elem->data = elem->defbuffer;
    }
    CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: elem);
    return CNetworkSystem::LagPacket(this, newdata: true, packet);
  }
  else
  {
    CUtlMemoryPool::Free(this: &loopback_t::s_Allocator, memBlock: elem);
    return CNetworkSystem::LagPacket(this, newdata: false, packet);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000CB90
// Name: private: bool CNetworkSystem::ReceiveDatagram(int,struct netpacket_t __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CNetworkSystem::ReceiveDatagram(CNetworkSystem *this, int sock, netpacket_t *packet)
{
  int source; // eax
  CNetworkSystem *v4; // ebp
  netsocket_t *m_pMemory; // ecx
  unsigned __int8 *data; // esi
  int v7; // eax
  int v8; // esi
  char v9; // al
  unsigned __int8 *v10; // ecx
  unsigned __int16 v11; // ax
  int v12; // ebx
  int v13; // esi
  unsigned __int8 *v14; // ebp
  unsigned int ActualSize; // esi
  unsigned __int8 *v17; // ebx
  unsigned __int8 *v18; // ebx
  unsigned int v19; // esi
  int v20; // eax
  int v21; // ebx
  int v22; // esi
  bool (__thiscall *IsMultiplayer)(INetworkSystem *); // edx
  int m_nBitsAvail; // ecx
  unsigned int m_nInBufWord; // eax
  int v26; // edx
  int v27; // ecx
  int v28; // ebx
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v31; // edx
  unsigned int v32; // ebx
  int v33; // eax
  const unsigned int *v34; // ecx
  unsigned int v35; // edx
  unsigned int v36; // ebp
  int v37; // esi
  int v38; // eax
  unsigned __int16 v39; // ax
  char v40; // bl
  const char *v41; // eax
  int Error; // eax
  const char *v43; // eax
  unsigned int v44; // [esp+4h] [ebp-206Ch]
  int nBits; // [esp+18h] [ebp-2058h]
  CNetworkSystem *v46; // [esp+1Ch] [ebp-2054h]
  bf_write v47; // [esp+20h] [ebp-2050h] BYREF
  int v48; // [esp+38h] [ebp-2038h]
  int v49; // [esp+3Ch] [ebp-2034h] BYREF
  sockaddr s; // [esp+40h] [ebp-2030h] BYREF
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v51; // [esp+50h] [ebp-2020h] BYREF
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v52; // [esp+1060h] [ebp-1010h] BYREF

  source = packet->source;
  v4 = this;
  m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
  data = packet->data;
  v49 = 16;
  v46 = v4;
  v7 = g_pSteamSocketMgrInternal->recvfrom(
         this: g_pSteamSocketMgrInternal,
         a2: m_pMemory[source].hUDP,
         a3: (char *)data,
         a4: 96016,
         a5: 0,
         a6: &s,
         a7: &v49);
  v8 = v7;
  if ( v7 <= 0 )
  {
    if ( v7 == -1 )
    {
      Error = WSAGetLastError();
      v4->m_nLastNetworkErrorCode = Error;
      switch ( Error )
      {
        case 10035:
        case 10054:
        case 10061:
          return 0;
        default:
          v43 = SocketErrorString(code: Error);
          _ConDMsg(a1: "NET_ReceivePacket: %s\n", v43);
          break;
      }
    }
  }
  else
  {
    packet->wiresize = v7;
    v51.m_nAllocationCount = 4096;
    v51.m_nMallocGrowSize = 4096;
    v9 = *((_BYTE *)v4 + 304);
    v51.m_pMemory = v51.m_pFixedMemory;
    v51.m_nGrowSize = -1;
    nBits = 0;
    if ( (v9 & 0x20) != 0 && (v9 & 0x40) == 0 )
    {
      v10 = packet->data;
      v11 = *(_WORD *)v10;
      if ( *(_WORD *)v10 != 0xFFFF )
      {
        v12 = v11;
        v13 = v8 - v11 - 2;
        if ( v13 > 0 )
        {
          v14 = &v10[v11 + 4];
          nBits = *(unsigned __int16 *)&v10[v11 + 2];
          v47.m_nDataBits = 4096;
          if ( CLZSS::IsCompressed(this: (CLZSS *)&v47, pInput: v14) )
          {
            ActualSize = CLZSS::GetActualSize(this: (CLZSS *)&v47, pInput: v14);
            if ( ActualSize != (unsigned int)(nBits + 7) >> 3 )
              goto LABEL_9;
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v51, num: ActualSize);
            if ( CLZSS::SafeUncompress(this: (CLZSS *)&v47, pInput: v14, pOutput: v51.m_pMemory, unBufSize: ActualSize) != ActualSize )
              goto LABEL_9;
          }
          else
          {
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v51, num: v13);
            _V_memcpy(dest: v51.m_pMemory, src: v14, count: v13);
          }
          v4 = v46;
        }
        _V_memmove(dest: packet->data, src: packet->data + 2, count: v12);
        v8 = v12;
      }
    }
    netadr_s::SetFromSockadr(this: &packet->from, &s);
    packet->size = v8;
    if ( v8 < 96016 )
    {
      if ( *(_DWORD *)packet->data != -2 || CNetworkSystem::GetLong(this: v4, sock, packet) != 0 )
      {
        v17 = packet->data;
        if ( *(_DWORD *)v17 != -3 )
          goto LABEL_21;
        v18 = v17 + 4;
        v47.m_nDataBits = 4096;
        v19 = CLZSS::GetActualSize(this: (CLZSS *)&v47, pInput: v18);
        if ( v19 - 1 <= 0x176FF )
        {
          v52.m_pMemory = v52.m_pFixedMemory;
          v52.m_nAllocationCount = 4096;
          v52.m_nGrowSize = -1;
          v52.m_nMallocGrowSize = 4096;
          CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v52, num: v19);
          v20 = CLZSS::SafeUncompress(this: (CLZSS *)&v47, pInput: v18, pOutput: v52.m_pMemory, unBufSize: v19);
          v21 = v20;
          if ( v20 == 0 || v19 != v20 )
          {
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v52);
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v51);
            return 0;
          }
          _V_memcpy(dest: packet->data, src: v52.m_pMemory, count: v20);
          packet->size = v21;
          CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v52);
LABEL_21:
          if ( nBits == 0 )
          {
LABEL_52:
            v40 = CNetworkSystem::LagPacket(this: v4, newdata: true, packet);
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v51);
            return v40;
          }
          v22 = 8 * packet->size - (packet->data[8] >> 5);
          IsMultiplayer = v4->IsMultiplayer;
          v48 = v22;
          if ( !IsMultiplayer(this: v4) )
          {
LABEL_47:
            bf_write::bf_write(this: &v47);
            bf_write::SetDebugName(this: &v47, pDebugName: "X360 Fixup");
            bf_write::StartWriting(this: &v47, pData: packet->data, nBytes: 96016, iStartBit: v22, nBits: -1);
            bf_write::WriteBits(this: &v47, pInData: v51.m_pMemory, nBits);
            if ( v47.m_iCurBit % 8 > 0 )
            {
              v37 = v47.m_iCurBit % 8;
              if ( v37 <= 8 - g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem) )
              {
                v38 = g_pNetworkSystem->GetMsgTypeBits(this: g_pNetworkSystem);
                bf_write::WriteUBitLong(this: &v47, curData: 0, numbits: v38, bCheckRange: true);
              }
            }
            packet->size = (v47.m_iCurBit + 7) >> 3;
            if ( v4->IsMultiplayer(this: v4) )
            {
              bf_write::SeekToBit(this: &v47, bitPos: 72);
              v39 = CNetworkSystem::BufferToShortChecksum(
                      this: v4,
                      pvData: packet->data + 11,
                      nLength: packet->size - 11);
              bf_write::WriteUBitLong(this: &v47, curData: v39, numbits: 16, bCheckRange: true);
            }
            goto LABEL_52;
          }
          CBitRead::Seek(this: &packet->message, nPosition: 72);
          m_nBitsAvail = packet->message.m_nBitsAvail;
          if ( m_nBitsAvail >= 16 )
          {
            m_nInBufWord = packet->message.m_nInBufWord;
            v26 = (unsigned __int16)m_nInBufWord;
            v27 = m_nBitsAvail - 16;
            packet->message.m_nBitsAvail = v27;
            if ( v27 != 0 )
            {
              packet->message.m_nInBufWord = HIWORD(m_nInBufWord);
              v28 = (unsigned __int16)m_nInBufWord;
            }
            else
            {
              m_pDataIn = packet->message.m_pDataIn;
              m_pBufferEnd = packet->message.m_pBufferEnd;
              packet->message.m_nBitsAvail = 32;
              if ( m_pDataIn == m_pBufferEnd )
              {
                packet->message.m_nInBufWord = 0;
                packet->message.m_nBitsAvail = 1;
                packet->message.m_pDataIn = m_pDataIn + 1;
                v28 = v26;
              }
              else
              {
                if ( m_pDataIn <= m_pBufferEnd )
                {
                  packet->message.m_nInBufWord = *m_pDataIn;
                  packet->message.m_pDataIn = m_pDataIn + 1;
                }
                else
                {
                  packet->message.m_nInBufWord = 0;
                  packet->message.m_bOverflow = true;
                }
                v28 = v26;
              }
            }
            goto LABEL_42;
          }
          v31 = packet->message.m_pBufferEnd;
          v32 = packet->message.m_nInBufWord;
          v33 = 16 - m_nBitsAvail;
          v34 = packet->message.m_pDataIn;
          if ( v34 == v31 )
          {
            packet->message.m_nBitsAvail = 1;
            packet->message.m_nInBufWord = 0;
            packet->message.m_bOverflow = true;
          }
          else
          {
            if ( v34 > v31 )
            {
              packet->message.m_bOverflow = true;
              packet->message.m_nInBufWord = 0;
              goto LABEL_39;
            }
            packet->message.m_nInBufWord = *v34;
          }
          packet->message.m_pDataIn = v34 + 1;
LABEL_39:
          if ( packet->message.m_bOverflow )
          {
            v28 = 0;
          }
          else
          {
            v35 = packet->message.m_nInBufWord;
            v36 = (v35 & CBitBuffer::s_nMaskTable[v33]) << packet->message.m_nBitsAvail;
            packet->message.m_nBitsAvail = 32 - v33;
            v28 = v36 | v32;
            v4 = v46;
            packet->message.m_nInBufWord = v35 >> v33;
          }
LABEL_42:
          CBitRead::Seek(this: &packet->message, nPosition: 0);
          v44 = packet->size - 11;
          if ( (unsigned int)(packet->size - 12) > 0x176FF )
          {
            _Msg(a1: "corrupted packet detected (checksumbytes %d)\n", v44);
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v51);
            return 0;
          }
          if ( (unsigned __int16)CNetworkSystem::BufferToShortChecksum(
                                   this: v4,
                                   pvData: packet->data + 11,
                                   nLength: v44) != v28 )
          {
            _Msg(a1: "corrupted packet detected\n");
            CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v51);
            return 0;
          }
          v22 = v48;
          goto LABEL_47;
        }
      }
LABEL_9:
      CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v51);
      return 0;
    }
    v41 = netadr_s::ToString(this: &packet->from, baseOnly: false);
    _ConDMsg(a1: "ReceiveDatagram:  Oversize packet from %s\n", v41);
    if ( v51.m_nGrowSize >= 0 && v51.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v51.m_pMemory);
      return 0;
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1000D170
// Name: private: struct netpacket_t __near * CNetworkSystem::GetPacket(int,unsigned char __near *)
// Source: json
//------------------------------------------------------------------------------
netpacket_t *__thiscall CNetworkSystem::GetPacket(CNetworkSystem *this, int sock, unsigned __int8 *scratch)
{
  double m_flNetworkTime; // xmm2_8
  double v5; // xmm0_8
  double v6; // xmm1_8
  netpacket_t *p_m_NetPacket; // esi
  float v8; // xmm0_4
  float m_flFakeLagMilliseconds; // xmm2_4
  float m_fValue; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm0_4
  float v13; // xmm1_4
  float v14; // xmm2_4

  m_flNetworkTime = this->m_flNetworkTime;
  v5 = m_flNetworkTime - this->m_flLastTime;
  v6 = 0.2000000029802322;
  p_m_NetPacket = &this->m_NetSockets.m_Memory.m_pMemory[sock].m_NetPacket;
  if ( v5 <= 0.2000000029802322 )
  {
    v6 = 0.0;
    if ( v5 >= 0.0 )
      v6 = m_flNetworkTime - this->m_flLastTime;
  }
  v8 = m_flNetworkTime;
  m_flFakeLagMilliseconds = this->m_flFakeLagMilliseconds;
  this->m_flLastTime = v8;
  m_fValue = fakelag.m_pParent->m_Value.m_fValue;
  if ( m_fValue != m_flFakeLagMilliseconds )
  {
    v11 = m_fValue - m_flFakeLagMilliseconds;
    v12 = (float)v6 * 200.0;
    v13 = fabs(v11);
    if ( v12 > v13 )
      v12 = v13;
    if ( v11 >= 0.0 )
      v14 = m_flFakeLagMilliseconds + v12;
    else
      v14 = m_flFakeLagMilliseconds - v12;
    this->m_flFakeLagMilliseconds = v14;
  }
  CNetworkSystem::DiscardStaleSplitpackets(this, sock);
  netadr_s::SetType(this: &p_m_NetPacket->from, newtype: NA_IP);
  netadr_s::Clear(this: &p_m_NetPacket->from);
  p_m_NetPacket->received = this->m_flNetworkTime;
  p_m_NetPacket->data = scratch;
  p_m_NetPacket->source = sock;
  p_m_NetPacket->size = 0;
  p_m_NetPacket->wiresize = 0;
  p_m_NetPacket->message.m_pDebugName = "inpacket.message";
  if ( CNetworkSystem::GetLoopPacket(this, packet: p_m_NetPacket) == 0
    && (!this->IsMultiplayer(this)
     || CNetworkSystem::ReceiveDatagram(this, sock, packet: p_m_NetPacket) == 0
     && CNetworkSystem::LagPacket(this, newdata: false, packet: p_m_NetPacket) == 0) )
  {
    return nullptr;
  }
  CBitRead::StartReading(
    this: &p_m_NetPacket->message,
    pData: p_m_NetPacket->data,
    nBytes: p_m_NetPacket->size,
    iStartBit: 0,
    nBits: -1);
  return p_m_NetPacket;
}

//------------------------------------------------------------------------------
// Address: 0x1000D2C0
// Name: public: virtual void CNetworkSystem::ProcessSocket(int,class IConnectionlessPacketHandler __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::ProcessSocket(CNetworkSystem *this, int sock, IConnectionlessPacketHandler *handler)
{
  TSLNodeBase_t *v4; // eax
  unsigned __int8 *v5; // edi
  netpacket_t *Packet; // esi
  int v7; // edi
  INetworkPacketFilter *v8; // ecx
  int m_nBitsAvail; // eax
  int v10; // eax
  const unsigned int *m_pDataIn; // eax
  const unsigned int *m_pBufferEnd; // ecx
  const unsigned int *v13; // edx
  int v14; // ecx
  const unsigned int *v15; // eax
  const char *v16; // eax
  CNetChan *NetChannel; // eax
  int size; // [esp-Ch] [ebp-24h]
  int v19; // [esp-8h] [ebp-20h]
  int wiresize; // [esp-4h] [ebp-1Ch]
  unsigned __int8 *scratch; // [esp+10h] [ebp-8h]
  CTSPool<net_scratchbuffer_t> *p_m_NetScratchBuffers; // [esp+14h] [ebp-4h]

  p_m_NetScratchBuffers = &this->m_NetScratchBuffers;
  v4 = CTSListBase::Pop(this: &this->m_NetScratchBuffers);
  if ( v4 == nullptr )
    v4 = (TSLNodeBase_t *)operator new(nSize: 0x17718u);
  v5 = (unsigned __int8 *)(&v4->Next + 1);
  scratch = (unsigned __int8 *)(&v4->Next + 1);
  if ( v4 == (TSLNodeBase_t *)-4 )
  {
    scratch = (unsigned __int8 *)operator new(nSize: 0x17710u);
    v5 = scratch;
  }
  Packet = CNetworkSystem::GetPacket(this, sock, scratch: v5);
  if ( Packet != nullptr )
  {
    while ( 1 )
    {
      v7 = 0;
      if ( this->m_NetworkPacketFilterCallbacks.m_Size > 0 )
      {
        do
        {
          v8 = this->m_NetworkPacketFilterCallbacks.m_Memory.m_pMemory[v7];
          if ( v8->ShouldDiscardPacket(this: v8, a2: &Packet->from) != 0 )
            goto LABEL_31;
        }
        while ( ++v7 < this->m_NetworkPacketFilterCallbacks.m_Size );
      }
      if ( *(_DWORD *)Packet->data != -1 )
      {
        NetChannel = CNetworkSystem::FindNetChannel(this, socket: sock, adr: &Packet->from);
        if ( NetChannel != nullptr )
          NetChannel->ProcessPacket(this: NetChannel, a2: Packet, a3: true);
        goto LABEL_31;
      }
      m_nBitsAvail = Packet->message.m_nBitsAvail;
      if ( m_nBitsAvail < 32 )
        break;
      v10 = m_nBitsAvail - 32;
      Packet->message.m_nBitsAvail = v10;
      if ( v10 != 0 )
      {
        Packet->message.m_nInBufWord = 0;
      }
      else
      {
        m_pDataIn = Packet->message.m_pDataIn;
        m_pBufferEnd = Packet->message.m_pBufferEnd;
        Packet->message.m_nBitsAvail = 32;
        if ( m_pDataIn == m_pBufferEnd )
        {
          Packet->message.m_nBitsAvail = 1;
          Packet->message.m_nInBufWord = 0;
          Packet->message.m_pDataIn = m_pDataIn + 1;
        }
        else if ( m_pDataIn <= m_pBufferEnd )
        {
          Packet->message.m_nInBufWord = *m_pDataIn;
          Packet->message.m_pDataIn = m_pDataIn + 1;
        }
        else
        {
          Packet->message.m_bOverflow = true;
          Packet->message.m_nInBufWord = 0;
        }
      }
LABEL_26:
      if ( net_showoob.m_pParent->m_Value.m_nValue != 0 )
      {
        wiresize = Packet->wiresize;
        v19 = Packet->data[4];
        size = Packet->size;
        v16 = netadr_s::ToString(this: &Packet->from, baseOnly: false);
        _Msg(a1: "UDP <- %s: sz=%i OOB (%d) wire=%i\n", v16, size, v19, wiresize);
      }
      handler->ProcessConnectionlessPacket(this: handler, a2: Packet);
LABEL_31:
      Packet = CNetworkSystem::GetPacket(this, sock, scratch);
      if ( Packet == nullptr )
      {
        v5 = scratch;
        goto LABEL_33;
      }
    }
    v13 = Packet->message.m_pBufferEnd;
    v14 = 32 - m_nBitsAvail;
    v15 = Packet->message.m_pDataIn;
    if ( v15 == v13 )
    {
      Packet->message.m_nBitsAvail = 1;
      Packet->message.m_nInBufWord = 0;
      Packet->message.m_bOverflow = true;
    }
    else
    {
      if ( v15 > v13 )
      {
        Packet->message.m_bOverflow = true;
        Packet->message.m_nInBufWord = 0;
        goto LABEL_24;
      }
      Packet->message.m_nInBufWord = *v15;
    }
    Packet->message.m_pDataIn = v15 + 1;
LABEL_24:
    if ( !Packet->message.m_bOverflow )
    {
      Packet->message.m_nInBufWord >>= v14;
      Packet->message.m_nBitsAvail = 32 - v14;
    }
    goto LABEL_26;
  }
LABEL_33:
  CTSListBase::Push(this: p_m_NetScratchBuffers, pNode: (TSLNodeBase_t *)(v5 - 4));
}

//------------------------------------------------------------------------------
// Address: 0x1000D4A0
// Name: private: int CNetworkSystem::QueuePacketForSend(class CNetChan __near *,bool,int,char const __near *,int,struct sockaddr const __near *,int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkSystem::QueuePacketForSend(
        CNetworkSystem *this,
        CNetChan *chan,
        bool verbose,
        int s,
        const char *buf,
        int len,
        const sockaddr *to,
        int tolen,
        unsigned int msecDelay)
{
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v11; // esi

  if ( net_queued_packet_thread.m_pParent->m_Value.m_nValue != 0
    && g_pQueuedPackedSender->IsRunning(this: g_pQueuedPackedSender) )
  {
    g_pQueuedPackedSender->QueuePacket(
      this: g_pQueuedPackedSender,
      a2: chan,
      a3: s,
      a4: buf,
      a5: len,
      a6: to,
      a7: tolen,
      a8: msecDelay);
    return len;
  }
  else
  {
    v11 = &this->m_SendQueue.m_Memory.m_pMemory[CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::InsertBefore(
                                                  this: &this->m_SendQueue,
                                                  before: 0xFFFFu)];
    v11->m_Element.m_pChannel = chan;
    v11->m_Element.m_Socket = s;
    CUtlBuffer::Put(this: &v11->m_Element.m_Buffer, pMem: buf, size: len);
    CUtlBuffer::Put(this: &v11->m_Element.m_To, pMem: to, size: tolen);
    CNetChan::IncrementQueuedPackets(this: v11->m_Element.m_pChannel);
    return len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000D550
// Name: private: int CNetworkSystem::SendLong(class INetChannel __near *,int,int,char const __near *,int,struct sockaddr const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
// local variable allocation has failed, the output may be wrong!
CNetChan *__thiscall CNetworkSystem::SendLong(
        CNetworkSystem *this,
        INetChannel *chan,
        int sock,
        int s,
        const char *buf,
        int len,
        const sockaddr *to,
        int tolen,
        int nMaxRoutableSize)
{
  int v9; // ebx
  CNetChan *v11; // eax
  __int16 v12; // si
  int v13; // eax
  int v14; // ebp
  int v15; // eax
  int v16; // esi
  int m_nValue; // ebp
  int v18; // eax
  float v19; // xmm1_4
  CNetChan *v20; // ebp
  float v21; // xmm0_4
  CNetChan *result; // eax
  char v23; // cl
  int v24; // eax
  const char *v25; // eax
  int v26; // [esp-14h] [ebp-52Ch]
  int v27; // [esp-10h] [ebp-528h]
  const char *v28; // [esp-4h] [ebp-51Ch]
  CNetChan *netchan; // [esp+14h] [ebp-504h] BYREF
  int nBytesLeft; // [esp+18h] [ebp-500h]
  int nFragmentsSent; // [esp+1Ch] [ebp-4FCh]
  int nSequenceNumber; // [esp+20h] [ebp-4F8h]
  int v33; // [esp+24h] [ebp-4F4h]
  int nTotalBytesSent; // [esp+28h] [ebp-4F0h]
  float flMaxSplitpacketDataRateBytesPerSecond; // [esp+2Ch] [ebp-4ECh]
  float v36; // [esp+30h] [ebp-4E8h]
  CNetworkSystem *v37; // [esp+34h] [ebp-4E4h]
  int v38; // [esp+38h] [ebp-4E0h] BYREF
  int v39; // [esp+3Ch] [ebp-4DCh]
  int v40; // [esp+40h] [ebp-4D8h]
  _BYTE msecDelay[9]; // [esp+44h] [ebp-4D4h] OVERLAPPED BYREF
  _WSABUF Buffers; // [esp+58h] [ebp-4C0h] BYREF
  int v43; // [esp+60h] [ebp-4B8h]
  char packet[1200]; // [esp+64h] [ebp-4B4h] BYREF

  v9 = 0;
  v37 = this;
  v11 = (CNetChan *)__RTDynamicCast(
                      inptr: chan,
                      VfDelta: 0,
                      SrcType: &INetChannel `RTTI Type Descriptor',
                      TargetType: &CNetChan `RTTI Type Descriptor',
                      isReference: 0);
  nBytesLeft = (int)v11;
  v12 = nMaxRoutableSize - 12;
  if ( v11 != nullptr )
    v13 = CNetChan::IncrementSplitPacketSequence(this: v11);
  else
    v13 = _InterlockedIncrement(&this->m_NetSockets.m_Memory.m_pMemory[sock].m_nSplitPacketSequenceNumber);
  v14 = v12;
  v33 = v13;
  *(_DWORD *)&packet[8] = v13;
  v15 = (len + v12 - 1) / v12;
  *(_WORD *)&packet[14] = nMaxRoutableSize - 12;
  v16 = len;
  *(_DWORD *)&packet[4] = -2;
  v40 = v14;
  nFragmentsSent = len;
  flMaxSplitpacketDataRateBytesPerSecond = 0.0;
  nSequenceNumber = 0;
  v39 = v15;
  if ( len <= 0 )
    return (CNetChan *)LODWORD(flMaxSplitpacketDataRateBytesPerSecond);
  nTotalBytesSent = (int)buf;
  while ( 1 )
  {
    if ( v14 < v16 )
      v16 = v14;
    *(_WORD *)&packet[12] = v39 + ((_WORD)v9 << 8);
    _V_memcpy(dest: &packet[16], src: (const void *)nTotalBytesSent, count: v16);
    if ( nBytesLeft != 0
      && (nSequenceNumber >= net_splitrate.m_pParent->m_Value.m_nValue
       || net_queued_packet_thread.m_pParent->m_Value.m_nValue == 581304) )
    {
      m_nValue = net_splitpacket_maxrate.m_pParent->m_Value.m_nValue;
      v18 = (*(int (__thiscall **)(int))(*(_DWORD *)nBytesLeft + 20))(a1: nBytesLeft);
      v19 = (float)m_nValue;
      v20 = (CNetChan *)nBytesLeft;
      v21 = v19 <= (float)v18
          ? (float)net_splitpacket_maxrate.m_pParent->m_Value.m_nValue
          : (float)(*(int (__thiscall **)(int))(*(_DWORD *)nBytesLeft + 20))(a1: nBytesLeft);
      netchan = (CNetChan *)(v9 * (nMaxRoutableSize + 28));
      v36 = v21;
      *(_QWORD *)msecDelay = (__int64)((double)(int)netchan / v21 * 1000.0 + 0.5);
      result = (CNetChan *)CNetworkSystem::QueuePacketForSend(
                             this: v37,
                             chan: v20,
                             verbose: false,
                             s,
                             buf: &packet[4],
                             len: v16 + 12,
                             to,
                             tolen,
                             msecDelay: *(unsigned int *)msecDelay);
      v14 = v40;
    }
    else
    {
      result = (CNetChan *)(v16 + 12);
      if ( *(_DWORD *)&to->sa_data[2] != 0 || *(_WORD *)to->sa_data != 0 )
      {
        netchan = nullptr;
        v23 = *((_BYTE *)g_pNetworkSystemInternal + 304);
        if ( (v23 & 0x20) == 0 || (v23 & 0x40) != 0 )
        {
          result = (CNetChan *)g_pSteamSocketMgrInternal->sendto(
                                 this: g_pSteamSocketMgrInternal,
                                 a2: s,
                                 a3: &packet[4],
                                 a4: v16 + 12,
                                 a5: 0,
                                 a6: to,
                                 a7: tolen);
        }
        else
        {
          v43 = v16 + 12;
          v38 = (unsigned __int16)result;
          Buffers.buf = (char *)&v38;
          *(_DWORD *)packet = &packet[4];
          Buffers.len = 2;
          WSASendTo(
            s,
            lpBuffers: &Buffers,
            dwBufferCount: 2u,
            lpNumberOfBytesSent: (LPDWORD)&netchan,
            dwFlags: 0,
            lpTo: to,
            iTolen: tolen,
            lpOverlapped: nullptr,
            lpCompletionRoutine: nullptr);
          result = netchan;
        }
      }
    }
    ++nSequenceNumber;
    if ( (int)result < 0 )
      break;
    if ( (int)result >= v16 )
      LODWORD(flMaxSplitpacketDataRateBytesPerSecond) += v16;
    v24 = net_showsplits.m_pParent->m_Value.m_nValue;
    nFragmentsSent -= v16;
    nTotalBytesSent += v14;
    ++v9;
    if ( v24 != 0 && v24 != 2 )
    {
      netadr_s::SetIP(this: (netadr_s *)&msecDelay[8], unIP: 0);
      netadr_s::SetPort(this: (netadr_s *)&msecDelay[8], newport: 0);
      netadr_s::SetType(this: (netadr_s *)&msecDelay[8], newtype: NA_IP);
      netadr_s::SetFromSockadr(this: (netadr_s *)&msecDelay[8], s: to);
      v28 = netadr_s::ToString(this: (netadr_s *)&msecDelay[8], baseOnly: false);
      v27 = v33;
      v26 = v39;
      v25 = v37->DescribeSocket(this: v37, a2: sock);
      _Msg(
        a1: "--> [%s] Split packet %4i/%4i seq %5i size %4i mtu %4i to %s [ total %4i ]\n",
        v25,
        v9,
        v26,
        v27,
        v16,
        nMaxRoutableSize,
        v28,
        len);
    }
    if ( nFragmentsSent <= 0 )
      return (CNetChan *)LODWORD(flMaxSplitpacketDataRateBytesPerSecond);
    v16 = nFragmentsSent;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000D8A0
// Name: public: virtual int CNetworkSystem::SendPacket(class INetChannel __near *,int,struct netadr_s const __near &,unsigned char const __near *,int,class bf_write __near *,bool,unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CNetworkSystem::SendPacket(
        CNetworkSystem *this,
        CNetChan *chan,
        int sock,
        const netadr_s *toAddr,
        unsigned __int8 *data,
        int length,
        bf_write *pVoicePayload,
        bool bUseCompression,
        unsigned int unMillisecondsDelay)
{
  int v11; // eax
  netsocket_t *v12; // edi
  char *v13; // esi
  const char *v14; // eax
  ConVar *m_pParent; // ecx
  int m_nValue; // eax
  float m_fValue; // xmm0_4
  int v18; // ebx
  unsigned __int8 *m_pMemory; // ebx
  void *v20; // ebx
  int m_iCurBit; // eax
  unsigned __int8 *m_pData; // ecx
  CNetChan *v23; // ebp
  int v24; // esi
  unsigned __int8 *v25; // ebp
  int v26; // edi
  int v27; // edi
  char *v28; // eax
  CNetworkSystem *v29; // ebx
  char *v30; // edi
  int m_nLastNetworkErrorCode; // eax
  const char *v32; // eax
  int v33; // [esp-Ch] [ebp-2070h]
  const char *v34; // [esp-Ch] [ebp-2070h]
  unsigned int m_fValue_low; // [esp+8h] [ebp-205Ch] BYREF
  netadr_s to; // [esp+Ch] [ebp-2058h] BYREF
  CNetworkSystem *v37; // [esp+18h] [ebp-204Ch]
  bool verbose[4]; // [esp+1Ch] [ebp-2048h]
  int tolen; // [esp+20h] [ebp-2044h]
  unsigned int pOutputSize; // [esp+24h] [ebp-2040h] BYREF
  CLZSS v41; // [esp+28h] [ebp-203Ch] BYREF
  sockaddr s; // [esp+34h] [ebp-2030h] BYREF
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v43; // [esp+44h] [ebp-2020h] BYREF
  CUtlMemoryFixedGrowable<unsigned char,4096,int> v44; // [esp+1054h] [ebp-1010h] BYREF

  v37 = this;
  if ( sock < 0 || sock >= this->m_NetSockets.m_Size )
    return (char *)length;
  v11 = *(_DWORD *)&toAddr->port;
  v12 = &this->m_NetSockets.m_Memory.m_pMemory[sock];
  *(_QWORD *)&to.type = *(_QWORD *)&toAddr->type;
  *(_DWORD *)&to.port = v11;
  if ( netadr_s::GetPort(this: &to) == 0 && netadr_s::GetType(this: &to) == NA_BROADCAST )
    netadr_s::SetPort(this: &to, newport: this->m_nDefaultBroadcastPort);
  v13 = (char *)length;
  if ( net_showoob.m_pParent->m_Value.m_nValue != 0
    && *(_DWORD *)data == -1
    && (net_showudp_remoteonly.m_pParent->m_Value.m_nValue == 0
     || !netadr_s::IsLocalhost(this: &to) && !netadr_s::IsLoopback(this: &to)) )
  {
    v33 = data[4];
    v14 = netadr_s::ToString(this: &to, baseOnly: false);
    _Msg(a1: "UDP -> %s: sz=%i OOB (%d)\n", v14, length, v33);
  }
  if ( !this->IsMultiplayer(this)
    || to.type == NA_LOOPBACK
    || netadr_s::IsLocalhost(this: &to)
    && (m_pParent = net_usesocketsforloopback.m_pParent, net_usesocketsforloopback.m_pParent->m_Value.m_nValue == 0) )
  {
    CNetworkSystem::SendLoopPacket(this, sock, length, data, &to);
    return (char *)length;
  }
  if ( to.type == NA_BROADCAST )
  {
    *(_DWORD *)verbose = v12->hUDP;
    if ( *(_DWORD *)verbose == 0 )
      return (char *)length;
  }
  else
  {
    if ( to.type != NA_IP )
    {
      DevMsg(a1: "CNetworkSystem::SendPacket: bad address type (%i)\n", to.type);
      return (char *)length;
    }
    *(_DWORD *)verbose = v12->hUDP;
    if ( *(_DWORD *)verbose == 0 )
      return (char *)length;
  }
  m_nValue = droppackets.m_pParent->m_Value.m_nValue;
  if ( m_nValue < 0 && v12->m_bFakeLagEnabled )
  {
    ConVar::SetValue(this: (ConVar *)&droppackets.IConVar, value: m_nValue + 1);
    return (char *)length;
  }
  m_fValue = fakeloss.m_pParent->m_Value.m_fValue;
  if ( m_fValue > 0.0 )
  {
    m_fValue_low = LODWORD(fakeloss.m_pParent->m_Value.m_fValue);
    if ( _RandomInt(a1: m_pParent, a2: 0, a3: 100) <= (int)m_fValue )
      return (char *)length;
  }
  netadr_s::ToSockadr(this: &to, &s);
  v43.m_pMemory = v43.m_pFixedMemory;
  v43.m_nAllocationCount = 4096;
  v43.m_nGrowSize = -1;
  v43.m_nMallocGrowSize = 4096;
  v44.m_pMemory = v44.m_pFixedMemory;
  v44.m_nAllocationCount = 4096;
  v44.m_nGrowSize = -1;
  v44.m_nMallocGrowSize = 4096;
  tolen = length;
  if ( pVoicePayload == nullptr )
    tolen = -1;
  v18 = 0;
  if ( pVoicePayload != nullptr )
  {
    CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(
      this: &v44,
      num: ((pVoicePayload->m_iCurBit + 7) >> 3) + 2);
    m_pMemory = v44.m_pMemory;
    *(_WORD *)v44.m_pMemory = pVoicePayload->m_iCurBit;
    v20 = m_pMemory + 2;
    pOutputSize = (pVoicePayload->m_iCurBit + 7) >> 3;
    if ( net_compressvoice.m_pParent->m_Value.m_nValue == 0
      || (m_iCurBit = pVoicePayload->m_iCurBit,
          m_pData = pVoicePayload->m_pData,
          v41.m_nWindowSize = 4096,
          CLZSS::CompressNoAlloc(
            this: &v41,
            pInput: m_pData,
            inputLength: (m_iCurBit + 7) >> 3,
            pOutputBuf: (unsigned __int8 *)v20,
            &pOutputSize) == nullptr) )
    {
      _V_memcpy(dest: v20, src: pVoicePayload->m_pData, count: (pVoicePayload->m_iCurBit + 7) >> 3);
    }
    v18 = pOutputSize + 2;
  }
  if ( voice_xsend_debug.m_pParent->m_Value.m_nValue != 0 && v18 != 0 )
  {
    v23 = chan;
    DevMsg(a1: "XVoice: voice data payload for %p: %d bytes\n", chan, v18);
  }
  else
  {
    v23 = chan;
  }
  if ( bUseCompression
    && (v41.m_nWindowSize = 4096,
        m_fValue_low = length,
        CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v43, num: v18 + length + 4),
        *(_DWORD *)v43.m_pMemory = -3,
        CLZSS::CompressNoAlloc(
          this: &v41,
          pInput: data,
          inputLength: length,
          pOutputBuf: v43.m_pMemory + 4,
          pOutputSize: &m_fValue_low) != nullptr) )
  {
    v24 = m_fValue_low + 4;
    data = v43.m_pMemory;
    if ( pVoicePayload != nullptr && pVoicePayload->m_iCurBit > 0 )
      _V_memcpy(dest: &v43.m_pMemory[v24], src: v44.m_pMemory, count: v18);
    tolen = v24;
    v13 = (char *)(v18 + v24);
  }
  else if ( pVoicePayload != nullptr && pVoicePayload->m_iCurBit > 0 )
  {
    CUtlMemoryFixedGrowable<unsigned char,4096,int>::EnsureCapacity(this: &v43, num: v18 + length);
    v25 = v43.m_pMemory;
    _V_memcpy(dest: v43.m_pMemory, src: data, count: length);
    _V_memcpy(dest: &v25[length], src: v44.m_pMemory, count: v18);
    v23 = chan;
    data = v43.m_pMemory;
    v13 = (char *)(v18 + length);
  }
  v26 = 1200;
  if ( v23 != nullptr )
  {
    v27 = sv_maxroutable.m_pParent->m_Value.m_nValue;
    if ( v27 >= 1200 )
      v27 = 1200;
    if ( v23->GetMaxRoutablePayloadSize(this: v23) <= v27 )
    {
      if ( v23->GetMaxRoutablePayloadSize(this: v23) >= 576 )
        v26 = v23->GetMaxRoutablePayloadSize(this: v23);
      else
        v26 = 576;
    }
    else
    {
      v26 = sv_maxroutable.m_pParent->m_Value.m_nValue;
      if ( v26 >= 1200 )
        v26 = 1200;
    }
  }
  if ( unMillisecondsDelay == 0 )
    goto LABEL_59;
  if ( (int)v13 > v26 )
  {
    _Warning(a1: "Can't delay send a packet larger than maxroutable size %d/%d\n", v13, v26);
LABEL_59:
    if ( (int)v13 > v26 || net_queued_packet_thread.m_pParent->m_Value.m_nValue == 581304 && v23 != nullptr )
      v28 = (char *)CNetworkSystem::SendLong(
                      this: v37,
                      chan: v23,
                      sock,
                      s: *(int *)verbose,
                      buf: (const char *)data,
                      len: (int)v13,
                      to: &s,
                      tolen: 16,
                      nMaxRoutableSize: v26);
    else
      v28 = NET_SendTo(
              len: v13,
              to: &s,
              verbose: *(unsigned int *)verbose,
              s: (const char *)data,
              buf: (const char *)0x10,
              tolen);
    v29 = v37;
    goto LABEL_66;
  }
  v29 = v37;
  v28 = (char *)CNetworkSystem::QueuePacketForSend(
                  this: v37,
                  chan: v23,
                  verbose: false,
                  s: *(int *)verbose,
                  buf: (const char *)data,
                  len: (int)v13,
                  to: &s,
                  tolen: 16,
                  msecDelay: unMillisecondsDelay);
LABEL_66:
  v30 = v28;
  if ( v28 == (char *)-1 )
  {
    CNetworkSystem::GetLastError(this: v29);
    m_nLastNetworkErrorCode = v29->m_nLastNetworkErrorCode;
    if ( m_nLastNetworkErrorCode == 10035
      || m_nLastNetworkErrorCode == 10054
      || m_nLastNetworkErrorCode == 10049 && to.type == NA_BROADCAST )
    {
      CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v44);
      CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v43);
      return nullptr;
    }
    v34 = netadr_s::ToString(this: &to, baseOnly: false);
    v32 = SocketErrorString(code: v29->m_nLastNetworkErrorCode);
    _ConDMsg(a1: "CNetworkSystem::SendPacket Warning: %s : %s\n", v32, v34);
    v30 = v13;
  }
  CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v44);
  CUtlMemoryFixedGrowable<unsigned char,4096,int>::~CUtlMemoryFixedGrowable<unsigned char,4096,int>(this: &v43);
  return v30;
}

//------------------------------------------------------------------------------
// Address: 0x1000DE70
// Name: public: virtual void CNetworkSystem::OutOfBandPrintf(int,struct netadr_s const __near &,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CNetworkSystem::OutOfBandPrintf(CNetworkSystem *this, int sock, const netadr_s *adr, const char *format, ...)
{
  int v4; // eax
  unsigned __int8 string[1204]; // [esp+0h] [ebp-4B4h] BYREF
  va_list params; // [esp+4C8h] [ebp+14h] BYREF

  va_start(params, format);
  *(_DWORD *)&string[4] = -1;
  V_vsnprintf(pDest: (char *)&string[8], maxLen: 1196, pFormat: format, params);
  v4 = _V_strlen(str: (const char *)&string[8]);
  CNetworkSystem::SendPacket(
    this,
    chan: nullptr,
    sock,
    toAddr: adr,
    data: &string[4],
    length: v4 + 5,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000DEE0
// Name: public: virtual void CNetworkSystem::OutOfBandDelayedPrintf(int,struct netadr_s const __near &,unsigned int,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CNetworkSystem::OutOfBandDelayedPrintf(
        CNetworkSystem *this,
        int sock,
        const netadr_s *adr,
        unsigned int unMillisecondsDelay,
        const char *format,
        ...)
{
  int v5; // eax
  unsigned __int8 string[1204]; // [esp+0h] [ebp-4B4h] BYREF
  va_list params; // [esp+4CCh] [ebp+18h] BYREF

  va_start(params, format);
  *(_DWORD *)&string[4] = -1;
  V_vsnprintf(pDest: (char *)&string[8], maxLen: 1196, pFormat: format, params);
  v5 = _V_strlen(str: (const char *)&string[8]);
  CNetworkSystem::SendPacket(
    this,
    chan: nullptr,
    sock,
    toAddr: adr,
    data: &string[4],
    length: v5 + 5,
    pVoicePayload: nullptr,
    bUseCompression: false,
    unMillisecondsDelay);
}

//------------------------------------------------------------------------------
// Address: 0x1000DFA0
// Name: private: void CNetworkSystem::ClearQueuedPacketsForChannel(class INetChannel __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::ClearQueuedPacketsForChannel(CNetworkSystem *this, CNetChan *channel)
{
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *p_m_SendQueue; // ebx
  unsigned __int16 m_Head; // bp
  int v4; // edi
  unsigned __int16 m_Next; // cx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v6; // esi
  unsigned __int16 v7; // [esp+8h] [ebp-4h]

  p_m_SendQueue = &this->m_SendQueue;
  m_Head = this->m_SendQueue.m_Head;
  if ( m_Head != 0xFFFF )
  {
    do
    {
      v4 = m_Head;
      m_Next = p_m_SendQueue->m_Memory.m_pMemory[v4].m_Next;
      v7 = m_Next;
      if ( p_m_SendQueue->m_Memory.m_pMemory[v4].m_Element.m_pChannel == channel )
      {
        CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
          this: p_m_SendQueue,
          elem: m_Head);
        v6 = &p_m_SendQueue->m_Memory.m_pMemory[v4];
        if ( v6->m_Element.m_To.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v6->m_Element.m_To.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_Element.m_To.m_Memory.m_pMemory);
            v6->m_Element.m_To.m_Memory.m_pMemory = nullptr;
          }
          v6->m_Element.m_To.m_Memory.m_nAllocationCount = 0;
        }
        if ( v6->m_Element.m_Buffer.m_Memory.m_nGrowSize >= 0 )
        {
          if ( v6->m_Element.m_Buffer.m_Memory.m_pMemory != nullptr )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v6->m_Element.m_Buffer.m_Memory.m_pMemory);
            v6->m_Element.m_Buffer.m_Memory.m_pMemory = nullptr;
          }
          v6->m_Element.m_Buffer.m_Memory.m_nAllocationCount = 0;
        }
        v6->m_Next = p_m_SendQueue->m_FirstFree;
        m_Next = v7;
        p_m_SendQueue->m_FirstFree = m_Head;
      }
      m_Head = m_Next;
    }
    while ( m_Next != 0xFFFF );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E050
// Name: public: virtual void CNetworkSystem::SendQueuedPackets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SendQueuedPackets(CNetworkSystem *this)
{
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *p_m_SendQueue; // ebx
  unsigned __int16 m_Head; // si
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // ecx
  int v4; // eax
  int v5; // esi
  unsigned __int8 *v6; // eax
  int m_Put; // edi
  int v8; // edx
  const char *v9; // ebp
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *v10; // esi
  SOCKET m_Socket; // ecx
  char v12; // bl
  unsigned __int16 v13; // di
  int v14; // esi
  bool v15; // zf
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *nRemaining; // [esp+1Ch] [ebp-20h]
  int m_nValue; // [esp+20h] [ebp-1Ch]
  int v18; // [esp+24h] [ebp-18h] BYREF
  unsigned int NumberOfBytesSent; // [esp+28h] [ebp-14h] BYREF
  _WSABUF Buffers; // [esp+2Ch] [ebp-10h] BYREF
  int v21; // [esp+34h] [ebp-8h]
  const char *v22; // [esp+38h] [ebp-4h]

  p_m_SendQueue = &this->m_SendQueue;
  nRemaining = &this->m_SendQueue;
  m_nValue = net_splitrate.m_pParent->m_Value.m_nValue;
  if ( m_nValue != 0 )
  {
    do
    {
      m_Head = p_m_SendQueue->m_Head;
      if ( m_Head >= p_m_SendQueue->m_Memory.m_nAllocationCount )
        break;
      if ( m_Head > p_m_SendQueue->m_LastAlloc.index )
        break;
      m_pMemory = p_m_SendQueue->m_Memory.m_pMemory;
      v4 = (int)&p_m_SendQueue->m_Memory.m_pMemory[m_Head];
      if ( *(_WORD *)(v4 + 104) == m_Head && *(_WORD *)(v4 + 106) != m_Head )
        break;
      v5 = m_Head;
      v6 = m_pMemory[v5].m_Element.m_To.m_Memory.m_pMemory;
      m_Put = m_pMemory[v5].m_Element.m_To.m_Put;
      v8 = m_pMemory[v5].m_Element.m_Buffer.m_Put;
      v9 = (const char *)m_pMemory[v5].m_Element.m_Buffer.m_Memory.m_pMemory;
      v10 = &m_pMemory[v5];
      m_Socket = v10->m_Element.m_Socket;
      if ( *((_DWORD *)v6 + 1) != 0 || *((_WORD *)v6 + 1) != 0 )
      {
        NumberOfBytesSent = 0;
        v12 = *((_BYTE *)g_pNetworkSystemInternal + 304);
        if ( (v12 & 0x20) == 0 || (v12 & 0x40) != 0 )
        {
          g_pSteamSocketMgrInternal->sendto(
            this: g_pSteamSocketMgrInternal,
            a2: m_Socket,
            a3: v9,
            a4: v8,
            a5: 0,
            a6: (const sockaddr *)v6,
            a7: m_Put);
          p_m_SendQueue = nRemaining;
        }
        else
        {
          v22 = v9;
          v21 = v8;
          v18 = (unsigned __int16)v8;
          Buffers.len = 2;
          Buffers.buf = (char *)&v18;
          WSASendTo(
            s: m_Socket,
            lpBuffers: &Buffers,
            dwBufferCount: 2u,
            lpNumberOfBytesSent: &NumberOfBytesSent,
            dwFlags: 0,
            lpTo: (const struct sockaddr *)v6,
            iTolen: m_Put,
            lpOverlapped: nullptr,
            lpCompletionRoutine: nullptr);
          p_m_SendQueue = nRemaining;
        }
      }
      CNetChan::DecrementQueuedPackets(this: v10->m_Element.m_pChannel);
      v13 = p_m_SendQueue->m_Head;
      CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::Unlink(
        this: p_m_SendQueue,
        elem: v13);
      v14 = (int)&p_m_SendQueue->m_Memory.m_pMemory[v13];
      if ( *(int *)(v14 + 64) >= 0 )
      {
        if ( *(_DWORD *)(v14 + 56) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v14 + 56));
          *(_DWORD *)(v14 + 56) = 0;
        }
        *(_DWORD *)(v14 + 60) = 0;
      }
      if ( *(int *)(v14 + 16) >= 0 )
      {
        if ( *(_DWORD *)(v14 + 8) != 0 )
        {
          _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: *(void **)(v14 + 8));
          *(_DWORD *)(v14 + 8) = 0;
        }
        *(_DWORD *)(v14 + 12) = 0;
      }
      v15 = m_nValue-- == 1;
      *(_WORD *)(v14 + 106) = p_m_SendQueue->m_FirstFree;
      p_m_SendQueue->m_FirstFree = v13;
    }
    while ( !v15 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E1E0
// Name: public: virtual int CNetworkSystem::CreateSocket(int,int,bool,bool,bool,bool,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkSystem::CreateSocket(
        CNetworkSystem *this,
        int nPortDesired,
        int nPortDefault,
        bool bTryAnyPort,
        bool bEnableFakelag,
        bool bEnableSteamCnx,
        bool bUseForDefaultPort,
        const char *pchSocketName)
{
  CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int> > *p_m_NetSockets; // edi
  int v10; // ebp
  int v11; // esi

  p_m_NetSockets = &this->m_NetSockets;
  v10 = CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>::InsertBefore(
          this: &this->m_NetSockets,
          elem: this->m_NetSockets.m_Size);
  v11 = (int)&p_m_NetSockets->m_Memory.m_pMemory[v10];
  *(_DWORD *)v11 = nPortDesired;
  *(_DWORD *)(v11 + 4) = nPortDefault;
  CUtlString::operator=(this: (CUtlString *)(v11 + 28), src: pchSocketName);
  *(_BYTE *)(v11 + 8) = bTryAnyPort;
  *(_BYTE *)(v11 + 196) = bEnableSteamCnx;
  *(_BYTE *)(v11 + 128) = bEnableFakelag;
  if ( bUseForDefaultPort )
    this->m_nDefaultServerPortSocket = v10;
  this->m_nRegularSocketCount = this->m_NetSockets.m_Size;
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x1000E360
// Name: public: virtual void CNetworkSystem::RemoveNetChannel(class INetChannel __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::RemoveNetChannel(CNetworkSystem *this, CNetChan *netchan, bool bDeleteNetChan)
{
  CNetChan *v3; // ebx
  CNetworkSystem *v4; // ebp
  CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *p_m_NetChannels; // edi
  CThreadFastMutex *v6; // esi
  DWORD CurrentThreadId; // ecx
  int m_Size; // ecx
  int v9; // eax
  CNetChan::DataFragments_t **m_pMemory; // edx

  v3 = netchan;
  v4 = this;
  if ( netchan == nullptr )
    return;
  p_m_NetChannels = (CUtlVector<CNetChan::DataFragments_t *,CUtlMemory<CNetChan::DataFragments_t *,int> > *)&this->m_NetChannels;
  if ( this == (CNetworkSystem *)-84 )
    v6 = nullptr;
  else
    v6 = &this->m_NetChannels.CThreadFastMutex;
  CurrentThreadId = GetCurrentThreadId();
  if ( CurrentThreadId == v6->m_ownerID )
    goto LABEL_8;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)v6, CurrentThreadId, 0) == 0 )
  {
    v4 = this;
LABEL_8:
    ++v6->m_depth;
    goto LABEL_10;
  }
  _mm_pause();
  CThreadFastMutex::Lock(a1: v6, a2: CurrentThreadId, a3: 0);
  v4 = this;
LABEL_10:
  m_Size = p_m_NetChannels->m_Size;
  v9 = 0;
  if ( m_Size <= 0 )
    goto LABEL_16;
  m_pMemory = p_m_NetChannels->m_Memory.m_pMemory;
  while ( *m_pMemory != (CNetChan::DataFragments_t *)v3 )
  {
    ++v9;
    ++m_pMemory;
    if ( v9 >= m_Size )
      goto LABEL_16;
  }
  if ( v9 == -1 )
  {
LABEL_16:
    _DevMsg(a1: 1, a2: "NET_CloseNetChannel: unknown channel.\n");
  }
  else
  {
    netchan = v3;
    CUtlVector<CNetChan *,CUtlMemory<CNetChan *,int>>::FindAndRemove(
      this: p_m_NetChannels,
      src: (CNetChan::DataFragments_t **)&netchan);
    CNetworkSystem::ClearQueuedPacketsForChannel(this: v4, channel: v3);
    if ( bDeleteNetChan )
      ((void (__thiscall *)(CNetChan *, int))v3->dtr_INetChannel)(a1: v3, a2: 1);
  }
  if ( v6->m_depth-- == 1 )
    _InterlockedExchange((volatile __int32 *)v6, 0);
}

//------------------------------------------------------------------------------
// Address: 0x1000E430
// Name: private: void CNetworkSystem::OpenSocketInternal(int,int,int,char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::OpenSocketInternal(
        CNetworkSystem *this,
        int nModule,
        int nSetPort,
        int nDefaultPort,
        const char *pName,
        int nProtocol,
        BOOL bTryAny)
{
  int *p_hTCP; // edi
  char *m_pszString; // eax
  const CUtlString *v10; // eax
  int v11; // ebp
  int v13; // esi
  int nPort; // eax
  int v15; // ebp
  const char *v16; // eax
  const char *v17; // esi
  SOCKET v18; // eax
  int v19; // [esp+10h] [ebp-34h] BYREF
  CNetworkSystem *v20; // [esp+14h] [ebp-30h]
  int nSavePort; // [esp+18h] [ebp-2Ch]
  int v22; // [esp+1Ch] [ebp-28h]
  CUtlString v23; // [esp+20h] [ebp-24h] BYREF
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > list; // [esp+30h] [ebp-14h] BYREF
  CUtlString *nProtocola; // [esp+58h] [ebp+14h]

  p_hTCP = nullptr;
  v20 = this;
  memset(&list, 0, sizeof(list));
  if ( (ipname.m_nFlags & 0x1000) != 0 )
  {
    m_pszString = "FCVAR_NEVER_AS_STRING";
  }
  else
  {
    m_pszString = ipname.m_pParent->m_Value.m_pszString;
    if ( m_pszString == nullptr )
      m_pszString = (char *)str;
  }
  v10 = CUtlString::CUtlString(this: &v23, pString: m_pszString);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::InsertBefore(this: &list, elem: 0, src: v10);
  if ( v23.m_Storage.m_Memory.m_nGrowSize >= 0 && v23.m_Storage.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v23.m_Storage.m_Memory.m_pMemory);
  CBindAddressHelper::GetBindAddresses(this: &g_BindAddressHelper, &list);
  v11 = nSetPort;
  if ( nSetPort != 0 )
    v19 = nSetPort;
  else
    v19 = nDefaultPort;
  if ( nProtocol == 6 )
  {
    p_hTCP = &this->m_NetSockets.m_Memory.m_pMemory[nModule].hTCP;
  }
  else if ( nProtocol == 17 )
  {
    p_hTCP = &this->m_NetSockets.m_Memory.m_pMemory[nModule].hUDP;
  }
  else
  {
    _Error(a1: "Unrecognized protocol type %d", nProtocol);
  }
  v13 = 200 * nModule;
  nPort = v20->m_NetSockets.m_Memory.m_pMemory[nModule].nPort;
  nSavePort = 200 * nModule;
  if ( nPort != 0 )
  {
    _Msg(a1: "WARNING: NET_OpenSockets: %s port %i already open.\n", pName, nPort);
  }
  else
  {
    v15 = 0;
    v22 = v19;
    if ( list.m_Size <= 0 )
    {
LABEL_27:
      if ( *p_hTCP == 0 )
        _Error(a1: "Couldn't allocate any %s IP port, tried %d addresses", pName, list.m_Size);
    }
    else
    {
      nProtocola = list.m_Memory.m_pMemory;
      while ( 1 )
      {
        v19 = v22;
        v16 = CUtlString::operator char const *(this: nProtocola);
        v17 = v16;
        if ( v15 > 0 )
          _Msg(a1: "Trying to open socket on %s\n", v16);
        v18 = CNetworkSystem::OpenSocket(this: v20, net_interface: v17, port: &v19, protocol: nProtocol);
        *p_hTCP = v18;
        if ( v18 != 0 )
          break;
        if ( bTryAny )
        {
          v19 = -1;
          *p_hTCP = CNetworkSystem::OpenSocket(this: v20, net_interface: v17, port: &v19, protocol: nProtocol);
        }
        if ( *p_hTCP != 0 )
          break;
        ++nProtocola;
        if ( ++v15 >= list.m_Size )
        {
          v13 = nSavePort;
          goto LABEL_27;
        }
      }
      v13 = nSavePort;
    }
    v11 = nSetPort;
    *(int *)((char *)&v20->m_NetSockets.m_Memory.m_pMemory->nPort + v13) = v19;
  }
  if ( p_hTCP != nullptr )
    g_pSteamSocketMgrInternal->OpenSocket(
      this: g_pSteamSocketMgrInternal,
      a2: *p_hTCP,
      a3: nModule,
      a4: v11,
      a5: nDefaultPort,
      a6: pName,
      a7: nProtocol,
      a8: bTryAny);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &list);
  if ( list.m_Memory.m_nGrowSize >= 0 && list.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: list.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x1000E680
// Name: private: void CNetworkSystem::OpenSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::OpenSockets(CNetworkSystem *this)
{
  int v2; // ebx
  int v3; // ebp
  netsocket_t *m_pMemory; // esi
  BOOL m_bTryAny; // eax
  netsocket_t *v6; // esi
  const char *v7; // eax
  BOOL v8; // [esp-Ch] [ebp-14h]

  v2 = 0;
  if ( this->m_nRegularSocketCount > 0 )
  {
    v3 = 0;
    do
    {
      m_pMemory = this->m_NetSockets.m_Memory.m_pMemory;
      m_bTryAny = m_pMemory[v3].m_bTryAny;
      v6 = &m_pMemory[v3];
      v8 = m_bTryAny;
      v7 = CUtlString::operator char const *(this: &v6->m_sSocketName);
      CNetworkSystem::OpenSocketInternal(
        this,
        nModule: v2++,
        nSetPort: v6->m_nPortDesired,
        nDefaultPort: v6->m_nPortDefault,
        pName: v7,
        nProtocol: 17,
        bTryAny: v8);
      ++v3;
    }
    while ( v2 < this->m_nRegularSocketCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E6D0
// Name: public: virtual int CNetworkSystem::AddExtraSocket(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CNetworkSystem::AddExtraSocket(CNetworkSystem *this, int port, const char *pchSocketName)
{
  CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int> > *p_m_NetSockets; // edi
  int v5; // ebx
  int v6; // esi
  int v8; // [esp-14h] [ebp-24h]
  int v9; // [esp-10h] [ebp-20h]

  p_m_NetSockets = &this->m_NetSockets;
  v5 = CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>::InsertBefore(
         this: &this->m_NetSockets,
         elem: this->m_NetSockets.m_Size);
  v6 = (int)&p_m_NetSockets->m_Memory.m_pMemory[v5];
  *(_DWORD *)v6 = port;
  *(_DWORD *)(v6 + 4) = port;
  CUtlString::operator=(this: (CUtlString *)(v6 + 28), src: pchSocketName);
  v9 = *(_DWORD *)(v6 + 4);
  v8 = *(_DWORD *)v6;
  *(_BYTE *)(v6 + 8) = 1;
  CNetworkSystem::OpenSocketInternal(
    this,
    nModule: v5,
    nSetPort: v8,
    nDefaultPort: v9,
    pName: pchSocketName,
    nProtocol: 17,
    bTryAny: true);
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1000E730
// Name: public: virtual void CNetworkSystem::RemoveAllExtraSockets(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::RemoveAllExtraSockets(CNetworkSystem *this)
{
  int m_nRegularSocketCount; // ebx
  int v3; // edi
  netsocket_t *v4; // eax

  m_nRegularSocketCount = this->m_nRegularSocketCount;
  if ( m_nRegularSocketCount < this->m_NetSockets.m_Size )
  {
    v3 = m_nRegularSocketCount;
    do
    {
      v4 = &this->m_NetSockets.m_Memory.m_pMemory[v3];
      if ( v4->nPort != 0 )
      {
        this->CloseSocket(this, a2: v4->hUDP, a3: -1);
        this->CloseSocket(this, a2: this->m_NetSockets.m_Memory.m_pMemory[v3].hTCP, a3: -1);
      }
      ++m_nRegularSocketCount;
      ++v3;
    }
    while ( m_nRegularSocketCount < this->m_NetSockets.m_Size );
  }
  CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>::RemoveMultiple(
    this: &this->m_NetSockets,
    elem: this->m_nRegularSocketCount,
    num: this->m_NetSockets.m_Size - this->m_nRegularSocketCount);
}

//------------------------------------------------------------------------------
// Address: 0x1000E7C0
// Name: private: void CNetworkSystem::Config(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::Config(CNetworkSystem *this)
{
  char v2; // al
  const char *v3; // ecx
  bool v4; // zf
  const char *v5; // eax
  const char *v6; // eax
  int v7; // ebx
  int v8; // ebp
  netsocket_t *v9; // edi
  const char *v10; // eax
  const char *v11; // [esp-8h] [ebp-10h]
  const char *v12; // [esp-4h] [ebp-Ch]

  CNetworkSystem::CloseAllSockets(this);
  this->m_flNetworkTime = 0.0;
  CNetworkSystem::ClearLoopbackBuffers(this);
  if ( (*((_BYTE *)this + 304) & 1) != 0 )
  {
    CNetworkSystem::GetLocalAddress(this);
    CNetworkSystem::OpenSockets(this);
  }
  v2 = *((_BYTE *)this + 304);
  v3 = "Yes";
  if ( (v2 & 0x10) == 0 )
    v3 = "No";
  v4 = (v2 & 1) == 0;
  v5 = "MP";
  if ( v4 )
    v5 = "SP";
  v12 = v3;
  v11 = v5;
  v6 = netadr_s::ToString(this: &this->m_adrLocal, baseOnly: true);
  _Msg(a1: "Network: IP %s, mode %s, dedicated %s\n", v6, v11, v12);
  v7 = 0;
  if ( this->m_NetSockets.m_Size > 0 )
  {
    v8 = 0;
    do
    {
      v9 = &this->m_NetSockets.m_Memory.m_pMemory[v8];
      v10 = CUtlString::operator char const *(this: &v9->m_sSocketName);
      _Msg(a1: "  Port %s = %d\n", v10, v9->nPort);
      ++v7;
      ++v8;
    }
    while ( v7 < this->m_NetSockets.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E880
// Name: public: virtual void CNetworkSystem::SetMultiplayer(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::SetMultiplayer(CNetworkSystem *this, bool bMultiplayer)
{
  char v3; // al
  int i; // edi
  INetworkConfigChanged *v5; // ecx

  v3 = *((_BYTE *)this + 304);
  if ( (v3 & 2) != 0 && bMultiplayer )
  {
    _Msg(a1: "Warning! Multiplayer mode not available with -noip parameter.\n");
  }
  else if ( (v3 & 0x10) == 0 || bMultiplayer )
  {
    if ( (v3 & 1) != bMultiplayer )
    {
      *((_BYTE *)this + 304) = v3 ^ (bMultiplayer ^ v3) & 1;
      CNetworkSystem::Config(this);
      for ( i = 0; i < this->m_NetworkConfigChangedCallbacks.m_Size; ++i )
      {
        v5 = this->m_NetworkConfigChangedCallbacks.m_Memory.m_pMemory[i];
        v5->OnNetworkConfigChanged(this: v5, a2: *((_BYTE *)this + 304) & 1);
      }
    }
    if ( !bMultiplayer )
      CNetworkSystem::ClearLoopbackBuffers(this);
  }
  else
  {
    _Msg(a1: "Warning! Singleplayer mode not available on dedicated server.\n");
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E990
// Name: public: CNetworkSystem::CNetworkSystem(void)
// Source: json
//------------------------------------------------------------------------------
CNetworkSystem *__thiscall CNetworkSystem::CNetworkSystem(CNetworkSystem *this)
{
  netadr_s *p_m_adrLocal; // ebx
  UtlLinkedListElem_t<SendQueueItem_t,unsigned short> *m_pMemory; // eax

  p_m_adrLocal = &this->m_adrLocal;
  this->__vftable = (CNetworkSystem_vtbl *)&CNetworkSystem::`vftable';
  netadr_s::SetIP(this: &this->m_adrLocal, unIP: 0);
  netadr_s::SetPort(this: p_m_adrLocal, newport: 0);
  netadr_s::SetType(this: p_m_adrLocal, newtype: NA_IP);
  netadr_s::SetIP(this: &this->m_adrPublic, unIP: 0);
  netadr_s::SetPort(this: &this->m_adrPublic, newport: 0);
  netadr_s::SetType(this: &this->m_adrPublic, newtype: NA_IP);
  this->m_flNetworkTime = 0.0;
  this->m_flTimeScale = 1.0;
  this->m_flLastTime = 0.0;
  this->m_flFakeLagMilliseconds = 0.0;
  this->m_SendQueue.m_Memory.m_pMemory = nullptr;
  this->m_SendQueue.m_Memory.m_nAllocationCount = 0;
  this->m_SendQueue.m_Memory.m_nGrowSize = 0;
  this->m_SendQueue.m_LastAlloc.index = -1;
  this->m_SendQueue.m_Head = -1;
  this->m_SendQueue.m_Tail = -1;
  this->m_SendQueue.m_FirstFree = -1;
  m_pMemory = this->m_SendQueue.m_Memory.m_pMemory;
  this->m_SendQueue.m_ElementCount = 0;
  this->m_SendQueue.m_NumAlloced = 0;
  this->m_SendQueue.m_pElements = m_pMemory;
  this->m_NetChannels.m_Memory.m_pMemory = nullptr;
  this->m_NetChannels.m_Memory.m_nAllocationCount = 0;
  this->m_NetChannels.m_Memory.m_nGrowSize = 0;
  this->m_NetChannels.m_Size = 0;
  this->m_NetChannels.m_pElements = nullptr;
  this->m_NetChannels.m_ownerID = 0;
  this->m_NetChannels.m_depth = 0;
  this->m_NetChannels.Mutex_t.m_ownerID = 0;
  this->m_NetChannels.Mutex_t.m_depth = 0;
  this->m_PendingSockets.m_Memory.m_pMemory = nullptr;
  this->m_PendingSockets.m_Memory.m_nAllocationCount = 0;
  this->m_PendingSockets.m_Memory.m_nGrowSize = 0;
  this->m_PendingSockets.m_Size = 0;
  this->m_PendingSockets.m_pElements = nullptr;
  this->m_PendingSockets.m_ownerID = 0;
  this->m_PendingSockets.m_depth = 0;
  this->m_PendingSockets.Mutex_t.m_ownerID = 0;
  this->m_PendingSockets.Mutex_t.m_depth = 0;
  if ( (((_BYTE)this - 96) & 7) != 0 )
  {
    _Error(a1: "CTSListBase: Misaligned list\n");
    __debugbreak();
  }
  this->m_NetScratchBuffers.m_Head.value.Next = nullptr;
  HIDWORD(this->m_NetScratchBuffers.m_Head.value64) = 0;
  this->m_nLastNetworkErrorCode = 0;
  this->m_nRegularSocketCount = 0;
  this->m_nDefaultBroadcastPort = 27015;
  this->m_nDefaultServerPortSocket = -1;
  this->m_NetSockets.m_Memory.m_pMemory = nullptr;
  this->m_NetSockets.m_Memory.m_nAllocationCount = 0;
  this->m_NetSockets.m_Memory.m_nGrowSize = 0;
  this->m_NetSockets.m_Size = 0;
  this->m_NetSockets.m_pElements = nullptr;
  this->m_NetworkConfigChangedCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_NetworkConfigChangedCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_NetworkConfigChangedCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_NetworkConfigChangedCallbacks.m_Size = 0;
  this->m_NetworkConfigChangedCallbacks.m_pElements = nullptr;
  this->m_NetworkPacketFilterCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_NetworkPacketFilterCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_NetworkPacketFilterCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_NetworkPacketFilterCallbacks.m_Size = 0;
  this->m_NetworkPacketFilterCallbacks.m_pElements = nullptr;
  this->m_NetworkFileDownloadFilterCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_NetworkFileDownloadFilterCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_NetworkFileDownloadFilterCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_NetworkFileDownloadFilterCallbacks.m_Size = 0;
  this->m_NetworkFileDownloadFilterCallbacks.m_pElements = nullptr;
  this->m_NetworkFileSendCompletedCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_NetworkFileSendCompletedCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_NetworkFileSendCompletedCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_NetworkFileSendCompletedCallbacks.m_Size = 0;
  this->m_NetworkFileSendCompletedCallbacks.m_pElements = nullptr;
  this->m_NetworkPrepareStartupParamsCallbacks.m_Memory.m_pMemory = nullptr;
  this->m_NetworkPrepareStartupParamsCallbacks.m_Memory.m_nAllocationCount = 0;
  this->m_NetworkPrepareStartupParamsCallbacks.m_Memory.m_nGrowSize = 0;
  this->m_NetworkPrepareStartupParamsCallbacks.m_Size = 0;
  this->m_NetworkPrepareStartupParamsCallbacks.m_pElements = nullptr;
  *((_BYTE *)this + 304) = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000EB70
// Name: public: virtual CNetworkSystem::~CNetworkSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CNetworkSystem::~CNetworkSystem(CNetworkSystem *this)
{
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short> > *p_m_SendQueue; // esi

  this->__vftable = (CNetworkSystem_vtbl *)&CNetworkSystem::`vftable';
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkPrepareStartupParamsCallbacks);
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkFileSendCompletedCallbacks);
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkFileDownloadFilterCallbacks);
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkPacketFilterCallbacks);
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetworkConfigChangedCallbacks);
  CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>::~CUtlVector<netsocket_t,CUtlMemory<netsocket_t,int>>(this: &this->m_NetSockets);
  CTSPool<net_scratchbuffer_t>::~CTSPool<net_scratchbuffer_t>(this: &this->m_NetScratchBuffers);
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_PendingSockets);
  CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>::~CUtlVector<CQueuedPacketSender::CQueuedPacket *,CUtlMemory<CQueuedPacketSender::CQueuedPacket *,int>>(this: (CUtlVector<void (__cdecl*)(IConVar *,char const *,float),CUtlMemory<void (__cdecl*)(IConVar *,char const *,float),int> > *)&this->m_NetChannels);
  p_m_SendQueue = &this->m_SendQueue;
  CUtlLinkedList<SendQueueItem_t,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<SendQueueItem_t,unsigned short>,unsigned short>>::RemoveAll(this: p_m_SendQueue);
  if ( p_m_SendQueue->m_Memory.m_nGrowSize >= 0 )
  {
    if ( p_m_SendQueue->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: p_m_SendQueue->m_Memory.m_pMemory);
      p_m_SendQueue->m_Memory.m_pMemory = nullptr;
    }
    p_m_SendQueue->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10008C00
// Name: __CreateCNetworkSystemINetworkSystem_interface
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CNetworkSystem *__cdecl _CreateCNetworkSystemINetworkSystem_interface()
{
  return &s_NetworkSystem;
}
